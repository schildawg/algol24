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
    union {
        bool        boolean;
        int32_t     integer;
        double      number;
        const char *string;
        Obj        *obj;
    };
} Value;

/* Constructors. */
Value alg_nil(void);
Value alg_bool(bool b);
Value alg_int(int32_t i);
Value alg_double(double d);
Value alg_string(const char *s);
Value alg_char_value(int32_t code);

/* Arithmetic.  Integer op Integer stays an Integer -- including '/', which is
 * integer division; a Double on either side promotes.  '+' also concatenates
 * when either side is a String. */
Value alg_add(Value a, Value b);
Value alg_subtract(Value a, Value b);
Value alg_multiply(Value a, Value b);
Value alg_divide(Value a, Value b);
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
Value   alg_closure(const char *name, AlgFunction fn, Value **cells, int32_t cell_count, int32_t arity);
Value   alg_call(Value callee, Value *args, int32_t count);

/* String and numeric builtins.
 *
 * String indices are 0-based, unlike real Pascal's.  Pos returns -1 when the
 * substring is absent, and Copy clamps its end but not its start. */
Value alg_copy(Value text, Value begin, Value length);
Value alg_pos(Value text, Value part);
Value alg_char(Value code);
Value alg_ord(Value v);
Value alg_val(Value v);
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

/* 'X is T' -- whether a value's runtime type is T or inherits from it.  nil is
 * never anything.  The type name is known when the C is written; the value's
 * type is not, which is why this is a call rather than a comparison. */
Value alg_is(Value v, const char *name);

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
void alg_test_begin(int32_t count);
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
void  alg_writeln(Value v);
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
