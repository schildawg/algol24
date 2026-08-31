/* algol.h -- the Algol-24 C runtime.
 *
 * Emitted code manipulates tagged Values through these calls rather than
 * native C types, because the language is dynamically typed: the checker is
 * gradual and 'Any' means "not known", so a compiled expression generally
 * cannot be given a C type at emit time.  Where a type *is* known, the emitter
 * is free to skip the helper and emit the direct form -- an optimization, not a
 * correctness requirement.
 *
 * Scope: the language as the interpreter implements it -- integers, doubles,
 * strings, chars, booleans and nil, plus classes, enums, closures, collections,
 * buffers, text files and exceptions.  Enough to build this compiler, which is
 * written in Algol-24 and compiles itself through here.
 *
 * Doubles render in Algol-24's specified format -- shortest round-trip -- which
 * the interpreter reproduces exactly.
 */
#ifndef ALGOL_H
#define ALGOL_H

#include <setjmp.h>

/* ⚠️ The signal-mask-free variants, and the difference is a SYSCALL per frame.
 * On BSD-derived systems -- macOS among them -- setjmp/longjmp save and restore
 * the signal mask, which costs a sigprocmask each way.  A program that raises
 * rarely never notices; algc's own interpreter implements 'Exit' as a raise, so
 * it pays one per interpreted call, and 'sigprocmask' came out as the single
 * heaviest frame in its profile -- 1.98 s of system time in an 18.5 s run.
 * Nothing here installs a signal handler or blocks a signal, so there is no
 * mask worth preserving.
 *
 * ⚠️ The test below names the platforms that HAVE that behaviour.  It was
 * written as 'not _WIN32' once, which is a different claim and a wrong one:
 *
 *   - glibc declares the two asymmetrically -- _setjmp always, _longjmp only
 *     under __USE_MISC or __USE_XOPEN.  '-std=c11' sets __STRICT_ANSI__, which
 *     turns both off, so _longjmp is undeclared; since GCC 14 that is an error
 *     rather than a warning.  The seed therefore failed to build on Linux under
 *     this project's own default CFLAGS.
 *   - and it bought glibc nothing to begin with.  Its <setjmp.h> says
 *     '#define setjmp(env) _setjmp(env)' -- "Do not save the signal mask" -- so
 *     the standard name there already IS the mask-free one.
 *
 * Anywhere else, including MSVC, the standard pair is correct and portable. */
#if defined(__APPLE__)  || defined(__FreeBSD__) || defined(__NetBSD__)   \
 || defined(__OpenBSD__) || defined(__DragonFly__)                       \
 || (defined(__GLIBC__) && (defined(__USE_MISC) || defined(__USE_XOPEN)))
#define ALG_SETJMP(buf)       _setjmp(buf)
#define ALG_LONGJMP(buf, val) _longjmp(buf, val)
#else
#define ALG_SETJMP(buf)       setjmp(buf)
#define ALG_LONGJMP(buf, val) longjmp(buf, val)
#endif
#include <stdbool.h>
#include <stddef.h>   /* NULL, used by generated code */
#include <stdint.h>

typedef enum {
    VAL_NIL,
    VAL_BOOL,
    VAL_INT,
    VAL_DOUBLE,
    VAL_STRING,
    /* A one-character literal is a Char, not a String, and the two are never
     * equal -- Copy(s, 0, 1) = 'a' is false while s[0] = 'a' is true.  That is
     * Character versus String on the JVM, and compiled code has to agree. */
    VAL_CHAR,

    /* An opaque handle from a foreign call [FUN-014].  A type of its own rather
     * than an Integer, so it cannot be arithmetic'd, ordered, or printed as a
     * number -- the language hands it back out to C and does nothing else with
     * it. */
    VAL_POINTER,

    VAL_OBJ
} ValueType;

/* Heap things carry a tag so a Value can hold any of them through one pointer.
 * This is clox's Obj arrangement, and it is what class instances and closures
 * will hang off later -- which is why collections use it rather than getting a
 * ValueType each. */
typedef enum {
    OBJ_CLASS,
    OBJ_INSTANCE,
    OBJ_ENUM_TYPE,
    OBJ_ENUM,
    OBJ_CLOSURE,

    /* A method with its receiver already attached -- 'B.Hello' without the
     * call.  The interpreter hands back a bound method for exactly this, and
     * nothing here did. */
    OBJ_BOUND,

    /* The same thing for a BUILT-IN member -- 'L.Sort' without the call.  A
     * collection, a Buffer and a TextFile have no MethodEntry to bind, so this
     * carries the receiver, the member's name and its arity instead, and the
     * call goes back through alg_invoke.  The interpreter's CollectionMethod,
     * BufferMethod and FileMethod are the same three fields. */
    OBJ_BUILTIN_BOUND,

    /* Every top-level subprogram of one name, selected between at the call from
     * the values actually passed [FUN-013].  One of these per overloaded name;
     * a name with a single subprogram behind it has no set and is called
     * directly. */
    OBJ_OVERLOADS,

    /* An Integer past the machine width.  Arithmetic promotes into one rather
     * than raising [LEX-018], and demotes out of it the moment a result fits
     * again -- so one value never has two representations. */
    OBJ_BIGINT,
    OBJ_LIST,
    OBJ_SET,
    OBJ_STACK,
    OBJ_ARRAY,
    OBJ_MAP,
    OBJ_FILE,

    /* Growable bytes with an explicit lifetime -- the one thing here whose
     * storage is malloc'd rather than taken from the arena, because Free has
     * to mean something.  See the Buffer section in algol.c. */
    OBJ_BUFFER
} ObjType;

typedef struct {
    ObjType type;
} Obj;

/* C11 anonymous union, so a Value reads as v.integer rather than v.as.integer. */
typedef struct {
    ValueType type;

    /* ⚠️ A String and a Char carry their own BYTE length, and every operation
     * on their value uses it rather than strlen.  A String may therefore hold a
     * zero character, which is what [SRC-001] asks for -- 'a' + Str(Char(0)) +
     * 'b' is three characters long and prints as three.
     *
     * They are still NUL-terminated as well, and deliberately: as_text hands a
     * plain C string to everything that builds a diagnostic, and that stays
     * cheap.  Only the value-semantic operations -- concat, output, equality,
     * hashing, Copy, Pos, Length, subscript -- consult this field.
     *
     * ⚠️ Meaningless for every other type, and left zero there rather than
     * unset, so two Values of one number compare and hash alike whatever route
     * built them. */
    int32_t length;

    union {
        bool        boolean;
        int64_t     integer;
        double      number;
        const char *string;
        void       *pointer;
        Obj        *obj;
    };
} Value;

/* Constructors. */
Value alg_nil(void);
Value alg_bool(bool b);
Value alg_int(int64_t i);

/* An Integer from decimal text.  The emitter uses it for a literal too wide for
 * C to spell -- an Integer is unbounded [LEX-018] and a C literal is not. */
Value alg_integer(const char *digits);
Value alg_double(double d);
Value alg_string(const char *s);

/* A String of exactly n bytes, which may contain a zero character.  alg_string
 * is this with strlen, and is what a C literal wants. */
Value alg_string_n(const char *s, int32_t n);
Value alg_char_value(int32_t code);

/* Arithmetic.  Integer op Integer stays an Integer -- including '/', which is
 * integer division; a Double on either side promotes.  '+' also concatenates
 * when either side is a String. */
Value alg_add(Value a, Value b);
Value alg_subtract(Value a, Value b);
Value alg_multiply(Value a, Value b);
Value alg_divide(Value a, Value b);

/* 'A div B': integer division said deliberately, refusing a Double where '/'
 * would quietly do real division instead. */
Value alg_div_int(Value a, Value b);
Value alg_negate(Value a);

/* Comparison.  Returns a Bool Value. */
Value alg_greater(Value a, Value b);
Value alg_greater_equal(Value a, Value b);
Value alg_less(Value a, Value b);
Value alg_less_equal(Value a, Value b);
Value alg_equal(Value a, Value b);
Value alg_not_equal(Value a, Value b);
Value alg_not(Value a);

/* Falsey: nil, false, the Integer 0, and an enum member whose ordinal is 0.
 * Everything else is truthy, including 0.0, '' and a Char.  This is not Lox's
 * rule -- it is Interpreter.isTruthy's, which is the one that defines the
 * language. */
bool alg_truthy(Value v);

/* Collections.
 *
 * List, Set, Stack and Array share one representation -- a growable Value array
 * -- and differ only in what their methods allow.  A Map holds pairs.
 *
 * Every collection iterates in insertion order, and re-assigning an existing Map
 * key keeps its original position.  That is specified by the language rather
 * than left to the container, because the interpreter and the compiler have to
 * produce the same output.
 *
 * Methods dispatch on the receiver at run time rather than being resolved when
 * the C is emitted: a name means different things to different collections --
 * 'Contains' is on all of them, 'Get' on three -- and in a dynamically typed
 * language the receiver's kind is not known until the call happens. */
Value alg_list(void);
Value alg_set(void);
Value alg_set_of(Value items);
Value alg_stack(void);
Value alg_array(Value size);
Value alg_map(void);

/* Buffer(n) makes n zero bytes; Buffer() makes none.  The emitter passes
 * alg_int(0) for the second form rather than there being two entry points,
 * because unlike Set the two do not differ in what the argument means. */
Value alg_buffer(Value size);

/* Add-and-return-the-collection, so a literal can be built as one expression:
 * alg_list_keep(alg_list_keep(alg_list(), a), b). */
Value alg_list_keep(Value list, Value item);
Value alg_map_keep(Value map, Value key, Value value);

Value alg_add_item(Value receiver, Value item);
Value alg_put(Value receiver, Value key, Value value);
Value alg_get(Value receiver, Value key);
Value alg_set_at(Value receiver, Value index, Value item);
Value alg_remove(Value receiver, Value key);
Value alg_remove_at(Value receiver, Value index);
Value alg_insert(Value receiver, Value index, Value item);
Value alg_contains(Value receiver, Value item);
Value alg_index_of(Value receiver, Value item);
Value alg_clear(Value receiver);
Value alg_fill(Value receiver, Value item);
Value alg_push(Value receiver, Value item);
Value alg_pop(Value receiver);
Value alg_peek(Value receiver);
Value alg_sort(Value receiver);
Value alg_keys(Value receiver);
Value alg_values(Value receiver);
Value alg_to_list(Value receiver);

/* Properties -- written without parentheses in Algol-24. */
Value alg_length(Value v);
Value alg_is_empty(Value v);

/* Length(X), the FUNCTION, which measures TEXT and refuses a collection
 * [RT-003].  Deliberately not alg_length: the two are spelled alike and are not
 * the same operation.  See the comment on its definition. */
Value alg_text_length(Value v);

Value alg_subscript_get(Value target, Value index);
Value alg_subscript_set(Value target, Value index, Value value);
Value alg_in(Value needle, Value haystack);

/* 'for ... in'.  The collection is snapshotted first, so mutating it inside the
 * loop does not change what the loop walks. */
Value   alg_iterable(Value v);
int32_t alg_iterable_count(Value snapshot);
Value   alg_iterable_at(Value snapshot, int32_t index);

/* Classes and instances.
 *
 * A class is built once at startup by generated code calling alg_class and then
 * registering its fields and methods; an instance carries a pointer to it and a
 * flat array of field slots.  Fields are a closed set -- exactly what the class
 * declares -- so the slots can be a fixed array rather than a hash, and the
 * name-to-slot scan here could later be resolved when the C is emitted wherever
 * the receiver's type is known.
 *
 * Every method has the same C signature regardless of arity, so a class can hold
 * them in one table. */
typedef Value (*AlgMethod)(Value self, Value *args, int32_t count);

Value alg_class(const char *name, Value super);

/* Links a class to its parent, once both shells exist.
 *
 * ⚠️ A class may inherit from one declared BELOW it [DCL-006], so the emitter
 * builds every shell in a unit before linking any of them -- the interpreter's
 * two-phase hoist, written out.  Passing the parent to alg_class instead could
 * only ever see a handle that was still nil, which linked the child to nothing
 * and made the inherited method 'Undefined property'. */
void  alg_class_super(Value klass, Value super);

/* Checks that the name a class inherits from is bound, naming it if not.  A
 * class whose parent comes from a module is linked where its declaration
 * stands, and there the module may not have run -- see the definition. */
void  alg_class_declared(Value klass, const char *name);

void  alg_class_field(Value klass, const char *name);
/* Registers a method.  'types' names each parameter's declared type, "Any"
 * where none was written, and may be NULL for a method with no parameters.
 *
 * Overloads select on the whole signature rather than on arity, so a class may
 * declare two methods of one name each taking one argument and differing only
 * in what kind.  Selection happens at run time, because in a gradually typed
 * language the emitter frequently does not know an argument's type. */
void  alg_class_method(Value klass, const char *name, AlgMethod fn, int32_t arity,
                       const char **types);
void  alg_class_initializer(Value klass, AlgMethod fn);

/* A property: a member of arity 0 that alg_property CALLS rather than binding,
 * so it is read without parentheses [TYP-012]. */
void  alg_class_property(Value klass, const char *name, AlgMethod fn);

Value alg_new(Value klass, Value *args, int32_t count);

/* An 'object' declaration: a class with exactly one instance, built on first
 * use rather than at registration, so an object may refer to another declared
 * later in the file. */
void  alg_class_is_object(Value klass);
Value alg_singleton(Value klass);

/* Enums.  A member is interned by its type, so 'Red' and 'Color.Red' are the
 * same object and equality is identity. */
Value alg_enum_type(const char *name);
Value alg_enum_member(Value type, const char *name);

/* Records a subrange -- the predefined ones [TYP-015] and a program's own
 * [TYP-016] alike, since the emitter registers both by this one route.  Emitted
 * beside the class shells, because a subrange must be known before any
 * statement can assign through it.
 *
 * ⚠️ The bounds arrive as decimal TEXT, because a bound may be any Integer and
 * C cannot spell one past its own width. */
void  alg_subrange(const char *name, const char *low, const char *high);

/* Property and method access.  Both dispatch on the receiver at run time, so one
 * emitted call covers an instance field, a collection's Length, and a method on
 * either -- the emitter cannot know which it is looking at.
 *
 * Method names match case-sensitively on a class and case-insensitively on a
 * built-in collection.
 *
 * ⚠️ That is NOT what the interpreter does, and this comment claimed it was.
 * The interpreter compares a collection member exactly, so 'L.add(2)' on a List
 * is 'Undefined property ''add''.' interpreted and works compiled -- the C back
 * end accepting a program the language refuses.  The interpreter is the
 * authority, so the fault is here; see Annex C of the specification. */
Value alg_property(Value receiver, const char *name);
Value alg_set_property(Value receiver, const char *name, Value value);
Value alg_invoke(Value receiver, const char *name, Value *args, int32_t count);

/* 'super.M()' -- starts the search above the class that declared the caller. */
/* 'super.M' as a value: the parent's method bound to this receiver. */
Value alg_bound_from(Value klass, Value receiver, const char *name);

Value alg_invoke_from(Value klass, Value receiver, const char *name, Value *args, int32_t count);

/* Functions as values.
 *
 * Every function -- top level or nested -- is emitted with one signature and
 * wrapped in a closure, so it can be called directly, passed as an argument, or
 * kept in a collection.
 *
 * A variable captured by a nested function lives in a heap cell rather than as a
 * C local, because the capture outlives the call that created it and is shared
 * with it: Counter() hands back a Bump that keeps incrementing the same Count,
 * and a second Counter() gets its own.  The emitter boxes exactly the variables
 * some nested function reads. */
typedef Value (*AlgFunction)(Value **cells, Value *args, int32_t count);

Value  *alg_cell(Value initial);
Value   alg_closure(const char *name, AlgFunction fn, Value **cells, int32_t cell_count, int32_t arity,
                    const char **types);
Value   alg_call(Value callee, Value *args, int32_t count);

/* Every top-level subprogram of one name, in one value the call site hands its
 * arguments to [FUN-013].  Built once at startup: alg_overloads makes the set
 * and alg_overload adds a candidate, in declaration order, so that when two
 * both fit the first declared wins.  'types' names each parameter's declared
 * type, "Any" where none was written, and may be NULL for no parameters --
 * exactly as alg_class_method's does.
 *
 * ⚠️ Emitted only for a name that HAS more than one subprogram.  A single one
 * is still called by its own symbol, which keeps every other program's C
 * unchanged and the selection cost where the language asks for it. */
/* A call in which an argument named the parameter it fills [EXP-013].  The
 * arguments are put in declaration order and the call proceeds positionally, so
 * nothing downstream learns that a name can appear at a call.
 *
 * 'names' runs parallel to 'args', holding "" where an argument was written
 * positionally.  Emitted only where a name was actually written, so an ordinary
 * call still reaches alg_call, alg_invoke and alg_new and costs nothing. */
Value   alg_call_named(Value callee, Value *args, int32_t count, const char **names);
Value   alg_invoke_named(Value receiver, const char *name, Value *args, int32_t count,
                         const char **names);
Value   alg_new_named(Value klass, Value *args, int32_t count, const char **names);

/* An opaque foreign handle [FUN-014]. */
Value alg_pointer(void *address);

/* Calls a C function by symbol, with the declared parameter list describing how
 * to marshal the arguments.  'library' is "" for a symbol already in the running
 * program, which covers libc and anything linked. */
Value alg_foreign(const char *symbol, const char *library, const char **types,
                  int32_t count, const char *returns, Value *args);

/* The interpreter's route to one, taking Algol-24 values. */
Value alg_foreign_call(Value symbol, Value library, Value types, Value returns, Value args);

Value   alg_overloads(const char *name);
void    alg_overload(Value set, AlgFunction fn, int32_t arity, const char **types);

/* String and numeric builtins.
 *
 * String indices are 0-based, unlike real Pascal's.  Pos returns -1 when the
 * substring is absent, and Copy clamps its end but not its start. */
Value alg_copy(Value text, Value begin, Value length);
Value alg_pos(Value text, Value part);
Value alg_char(Value code);
Value alg_ord(Value v);
Value alg_val(Value v);

/* Succ and Pred step an ordinal -- a Char or an Integer [RT-020]. */
Value alg_succ(Value v);
Value alg_pred(Value v);
Value alg_max(Value a, Value b);

/* Seconds since the epoch, at millisecond resolution -- the same units and the
 * same granularity as the interpreter's System.currentTimeMillis() / 1000. */
Value alg_clock(void);
Value alg_mod(Value a, Value b);

/* Text files, and the command line.
 *
 * Turbo Pascal's API with the handle as the receiver: Assign, Reset, Rewrite,
 * Append, ReadLn, Write, WriteLn, Flush, Close, Erase and Rename are reached
 * through alg_invoke, and Eof through alg_property, exactly as a collection's
 * methods and its Length are.  So the emitter needs to know only the
 * constructor -- everything else is dispatch it already emits.
 *
 * Failures raise rather than setting an IOResult, which is what the
 * interpreter does, and the messages are part of the observable surface: a
 * failure inside a 'try' is catchable as a String and must read identically in
 * both implementations.
 *
 * A line ends at '\n', which is not returned; a '\r' immediately before one
 * comes off with it, and any other '\r' is ordinary text.  That is the rule the
 * scanner follows too.  WriteLn always writes '\n' rather than the host's
 * separator, so the same program writes the same bytes everywhere. */
Value alg_text_file(void);
Value alg_file_exists(Value name);

/* Checks a call's argument count against the declared one [EXP-011], raising
 * 'Expected N arguments but got M.' where they differ.
 *
 * ⚠️ Emitted in the CALLEE of a top-level subprogram, because that is the one
 * call shape nothing else guards: it is reached by its own C symbol, so no
 * dispatcher sits between the call and the body.  A nested function goes
 * through alg_call and a method through alg_invoke, both of which check. */
void alg_arity(int32_t got, int32_t expected);

/* Checks that a file-scope variable's declaration has run before it is read or
 * assigned [DCL-016], raising 'Undefined variable 'X'.' where it has not.  Each
 * such variable carries a 'd_' bool beside its 'v_' storage; see the emitter's
 * Guarded, and the note on the definition for why a bool rather than a
 * sentinel Value. */
void alg_declared(bool defined, const char *name);

/* 'X is T' -- whether a value's runtime type is T or inherits from it.  nil is
 * never anything.  The type name is known when the C is written; the value's
 * type is not, which is why this is a call rather than a comparison. */
Value alg_is(Value v, const char *name);

/* 'X as T' -- the same test, made a requirement: the value back when it holds,
 * an error naming both types when it does not.  nil passes every cast [VAR-005],
 * which is the one place this and alg_is disagree. */
Value alg_cast(Value v, const char *name);

/* argv, behind Turbo Pascal's names.  Index 0 is the program; ParamCount does
 * not count it.  Emitted main passes these through on the way in. */
void  alg_set_arguments(int argc, char **argv);
Value alg_param_count(void);
Value alg_param_str(Value index);

/* The test runner.
 *
 * Reproduces the interpreter's --test report line for line, because that report
 * is what the conformance suites are compared on.  Assertion *failures* also
 * print an [ERROR] line with a source caret in the interpreter; compiled code
 * has no line information, so those are not reproduced and the comparison drops
 * them -- what is checked is which tests pass and the exit code.
 */
/* ⚠️ Takes the file the run was started from, because a failure names it -- and
 * names THAT file, not the one the failing test lives in, which is what the
 * interpreter does. */
void alg_test_begin(int32_t count, const char *file);
void alg_test_file(const char *file);
void alg_test_end_file(void);
void alg_test_run(const char *name, AlgFunction body);
int  alg_test_summary(void);

void alg_assert_true(Value value);
void alg_assert_equal(Value expected, Value actual);

/* Fails outright, for a branch that should not have been reached -- the 'do the
 * thing, then Fail, and catch below' shape that tests a raise. */
void alg_assert_fail(Value message);

/* Builtins. */
void  alg_write(Value v);

/* Ends the program with this status.  ⚠️ The one way a program can choose its
 * own exit code: without it a driver has to 'raise' to exit non-zero, which
 * prints an 'Uncaught:' line the report never asked for. */
void  alg_halt(Value status);

/* Binds an argument to a declared parameter type: raises where it does not fit,
 * widens where it does.  Emitted around every typed parameter's unpack. */
Value alg_param(Value argument, const char *declared);

/* Widens a value into a written type and refuses nothing -- a declaration, an
 * assignment, a field, a method's parameter.  The check lives elsewhere. */
Value alg_widen(Value argument, const char *declared);
void  alg_writeln(Value v);

/* 'WriteLn ()', the newline on its own -- WriteLn takes nothing or one value. */
void  alg_writeln_blank(void);
Value alg_str(Value v);

/* Exceptions.
 *
 * 'raise' carries any value, and a handler matches on the runtime type name --
 * a class name for an instance, otherwise String, Integer, Double, Char or
 * Boolean.  A handler for a base class catches a derived value, and the most
 * derived handler wins however the handlers are ordered.
 *
 * Unwinding is setjmp/longjmp over a stack of frames. */
typedef struct AlgFrame {
    jmp_buf          jump;
    struct AlgFrame *previous;
    Value            raised;
} AlgFrame;

void alg_push_frame(AlgFrame *frame);
void alg_pop_frame(void);
_Noreturn void alg_raise(Value value);

/* Index of the handler that should run, or -1.  Given all the handlers' type
 * names at once so nearness in the hierarchy decides, rather than the order they
 * happen to be written in. */
int32_t alg_handler(Value raised, const char **names, int32_t count);

/* Reports a runtime error and exits 70, matching the interpreter.  Inside a
 * 'try' it raises the message as a String instead, which is how the interpreter
 * makes its own errors catchable. */
_Noreturn void alg_error(const char *message);

#endif
