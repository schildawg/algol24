#ifndef ALGOL_H
#define ALGOL_H

/* WHICH RELEASE THIS HEADER IS, so the body cannot be a different one.
   Encoded major * 10000 + minor * 100 + patch, so 0.2.4 is 204 and it only
   ever increases.

   algol.c and algol.h are a PAIR -- the body uses what the header declares --
   and --compile emits them together.  Nothing stopped a build taking one of
   each: anything that assembles a program out of both the compiler's output
   and a checkout of the compiler itself can, and a project packaging for
   Android did exactly that.  A v0.2.3 body against a 0.1.6 header gave twenty
   cc errors, the first two being 'call to undeclared function alg_collect' and
   'no member named marked in Obj'.  Not one of the twenty said "two
   versions"; they read as a corrupt runtime, and the first guess was a bad
   checkout.

   The _Static_assert in algol.c turns all twenty into one line naming the real
   fault.  It also catches a stale generated directory left by an earlier
   compiler, which is the other way to arrive here.

   ⚠️ NOTHING DERIVES THIS FROM compiler/Release.a24, because both halves of
   the runtime are hand-written and copied verbatim.  spec/spec.sh holds the
   three to each other instead, so bumping the release bumps this too or the
   gate goes red -- which is the whole point, since a version in two places
   with nothing comparing them is what Release.a24 was created to end. */
#define ALG_RUNTIME_VERSION 206

/* glibc hides POSIX behind a feature test, and -std=c11 asks for it to: the
   flag defines __STRICT_ANSI__, which suppresses the _DEFAULT_SOURCE glibc
   would otherwise assume.  Every build line this project documents says
   -std=c11 -- build.sh's default, the README's line for emitted programs, and
   the Homebrew formula's own test -- so without this, 'realpath' and
   'readlink' are implicitly declared and a fresh clone does not build on a
   current Linux at all.  Measured on gcc 14.4 / glibc 2.41: four errors, two
   of them a char* initialised from an int.

   ⚠️ IT GOES HERE RATHER THAN IN algol.c, and the setjmp guard below is why.
   That guard asks whether POSIX is exposed, so the macro decides which of two
   setjmp variants the program uses -- and generated units call ALG_SETJMP on
   the same jmp_buf the runtime unwinds.  Defining it in algol.c alone would
   give the runtime '_setjmp' while every generated unit kept 'setjmp', which
   is one buffer written and read two ways.  Here, every translation unit
   agrees.

   Harmless where it means nothing: Darwin and the BSDs key on their own
   macros, and the branch below already picks the same variant for them. */
#define _DEFAULT_SOURCE 1

#include <setjmp.h>

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
#include <stddef.h>
#include <stdint.h>

typedef enum {
    VAL_NIL,
    VAL_BOOL,
    VAL_INT,
    VAL_DOUBLE,
    VAL_STRING,

    VAL_CHAR,

    VAL_POINTER,

    VAL_OBJ
} ValueType;

typedef enum {
    OBJ_CLASS,
    OBJ_INSTANCE,
    OBJ_ENUM_TYPE,
    OBJ_ENUM,
    OBJ_CLOSURE,

    OBJ_BOUND,

    OBJ_BUILTIN_BOUND,

    OBJ_EXTENSION,

    OBJ_OVERLOADS,

    OBJ_BIGINT,
    OBJ_LIST,
    OBJ_SET,
    OBJ_STACK,
    OBJ_ARRAY,
    OBJ_MAP,
    OBJ_FILE,

    OBJ_BUFFER,

    /* Not a kind of object: what a RELEASED one is retagged as when poisoning
       is on, so the first use of it faults where the misuse is rather than
       wedging the program three operations later.  See obj_release. */
    OBJ_RELEASED
} ObjType;

/* Every heap object begins with one of these.

   Both bools cost nothing: ObjType is an enum and every object that follows it
   holds a pointer, so there were already four bytes of padding here for them
   to sit in.  `marked` is the collector's bit -- see `obj_registry` in
   algol.c, which is how a sweep finds the objects to clear it on.

   `dead` says the object is on a free list.  A released object KEEPS its place
   in the registry, because it keeps its place in the arena and may be handed
   out again; without this bit the next collection would find it unmarked and
   release it a second time, putting one block on the free list twice and
   handing it to two owners. */
typedef struct {
    ObjType type;
    bool    marked;
    bool    dead;
} Obj;

typedef struct {
    ValueType type;

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

Value alg_nil(void);
Value alg_bool(bool b);
Value alg_int(int64_t i);

Value alg_integer(const char *digits);
Value alg_double(double d);
Value alg_string(const char *s);

/* A STRING LITERAL from generated code, interned by its address so one copy in
   the text heap serves every call.  Only ever called with a C static. */
Value alg_literal(const char *s);

Value alg_string_n(const char *s, int32_t n);
Value alg_char_value(int32_t code);

Value alg_add(Value a, Value b);
Value alg_subtract(Value a, Value b);
Value alg_multiply(Value a, Value b);
Value alg_divide(Value a, Value b);

Value alg_div_int(Value a, Value b);
Value alg_negate(Value a);

Value alg_greater(Value a, Value b);
Value alg_greater_equal(Value a, Value b);
Value alg_less(Value a, Value b);
Value alg_less_equal(Value a, Value b);
Value alg_equal(Value a, Value b);
Value alg_not_equal(Value a, Value b);
Value alg_not(Value a);

bool alg_truthy(Value v);

Value alg_list(void);
Value alg_set(void);
Value alg_set_of(Value items);
Value alg_stack(void);
Value alg_array(Value size);
Value alg_map(void);

Value alg_buffer(Value size);

/* A Buffer's bytes, for C that wants to read them without a call per byte.
 *
 * The same pointer `Buffer.Address` answers, which the language has always
 * given C [RT-022] -- this is the in-process form, so a caller already holding
 * the Value need not go through a Pointer to get at it.
 *
 * ⚠️ BORROWED, not owned, and only as valid as the Buffer.  A Buffer that
 * grows may move its bytes, and `Free` releases them, so a caller re-reads
 * this rather than keeping it: the machine's dispatch loop re-reads it every
 * instruction precisely because entering a frame swaps the chunk.
 *
 * Answers NULL for anything that is not a Buffer, rather than raising, because
 * the one caller is a loop that would rather check than carry a handler. */
const unsigned char *alg_buffer_bytes(Value v);

/* An Array's backing store, for C that wants to index it without a call per
 * element.
 *
 * The companion to alg_buffer_bytes, and there for the same reason: a
 * subscript goes through alg_subscript_get, which tries Map, Buffer, Set,
 * sequence and text in turn before it can index, and the machine's value stack
 * is an Array touched several times per instruction.
 *
 * BORROWED, and only as valid as the Array's capacity.  A List that grows
 * moves its items, so a caller re-reads this rather than keeping it; the
 * machine's stack is allocated once at a fixed size and never grows, which is
 * what makes it safe to touch this way at all.
 *
 * Answers NULL for anything that is not a sequence, so a caller checks rather
 * than carrying a handler. */
Value *alg_array_slots(Value v);

/* Whether a value is a number held INLINE -- an Integer inside a machine word
   or a Double.  Deliberately not true of a bignum, which is an object: this
   exists for fast paths that want the common case and are content to hand
   everything else to the general one. */
static inline bool alg_plain_number(Value v) {
    return v.type == VAL_INT || v.type == VAL_DOUBLE;
}

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

Value alg_length(Value v);
Value alg_is_empty(Value v);

Value alg_text_length(Value v);

Value alg_subscript_get(Value target, Value index);
Value alg_subscript_set(Value target, Value index, Value value);
Value alg_in(Value needle, Value haystack);

Value   alg_iterable(Value v);
int32_t alg_iterable_count(Value snapshot);
Value   alg_iterable_at(Value snapshot, int32_t index);

typedef Value (*AlgMethod)(Value self, Value *args, int32_t count);

Value alg_class(const char *name, Value super);

void  alg_class_super(Value klass, Value super);

void  alg_class_declared(Value klass, const char *name);

void  alg_class_field(Value klass, const char *name);

void  alg_class_method(Value klass, const char *name, AlgMethod fn, int32_t arity,
                       const char **types);
void  alg_class_initializer(Value klass, AlgMethod fn);

void  alg_class_property(Value klass, const char *name, AlgMethod fn);

Value alg_new(Value klass, Value *args, int32_t count);

void  alg_class_is_object(Value klass);
Value alg_singleton(Value klass);

Value alg_enum_type(const char *name);
Value alg_enum_member(Value type, const char *name);

void  alg_subrange(const char *name, const char *low, const char *high);

Value alg_property(Value receiver, const char *name);
Value alg_set_property(Value receiver, const char *name, Value value);
Value alg_invoke(Value receiver, const char *name, Value *args, int32_t count);

Value alg_bound_from(Value klass, Value receiver, const char *name);

Value alg_invoke_from(Value klass, Value receiver, const char *name, Value *args, int32_t count);

/* Extension functions [FUN-015].  A call written 'x.f (...)' where 'f' is not a
   member of x may mean 'f (x, ...)', and which it means is decided HERE rather
   than at emit time, because the checker is gradual and a receiver's type is
   often unknown until it holds a value [EXP-022].

   The emitter passes the extension as the value its name evaluates to -- a
   closure, or the overload set where the name is overloaded -- so selection
   among several of one name is the selection alg_call already does, with the
   receiver as the first argument.

   alg_responds asks by NAME and not by signature, which is what the rule
   requires: a receiver carrying an 'f' of another arity still takes the member,
   and the call then fails on its arity rather than quietly reaching past it. */
bool  alg_responds(Value receiver, const char *name);
Value alg_extension(Value receiver, Value target);

Value alg_invoke_or(Value receiver, const char *name, Value *args, int32_t count,
                    Value extension);
Value alg_invoke_or_named(Value receiver, const char *name, Value *args, int32_t count,
                          const char **names, Value extension);

/* 'x.f' with no call after it, which answers the extension bound to x -- the
   same thing reading a method off an instance answers [FUN-011]. */
Value alg_property_or(Value receiver, const char *name, Value extension);

typedef Value (*AlgFunction)(Value **cells, Value *args, int32_t count);

/* A BUILT-IN HELD AS A VALUE [FUN-011].  A built-in's name without parentheses
   is a value like any subprogram's, and reading one answers a callable that
   reaches the very same alg_* function a direct call reaches -- not a second
   implementation that would have to agree with the first forever.

   INTERNED BY NAME, and that is not an optimisation: these compare by identity
   [VAL-011], so 'Length = Length' is true only if both reads answer one object.
   The emitter calls this at every read and the first call for a name wins; the
   fn, arity and types are the emitter's own table either way, so a later caller
   passing the same name necessarily passes the same rest.

   Interning in the RUNTIME rather than in a generated unit is what makes the
   identity hold across units: a static per unit would make a Length read in one
   unit a different object from one read in another, where the interpreter keeps
   a single native per name in the environment every file encloses. */
Value alg_builtin(const char *name, AlgFunction fn, int32_t arity, const char **types);

/* An arity of -1 in alg_closure means ANY count, the callee checking for
   itself -- the interpreter's own convention for a variadic built-in.  Only a
   held built-in uses it. */
#define ALG_ANY_ARITY (-1)

/* The arity complaint for a built-in that takes SEVERAL counts, where 'expected'
   is the counts written out -- 'Expected 1, 2 or 3 arguments but got 4.'

   alg_arity cannot word it: it knows one expected count and these have a set of
   them, and an overload set cannot either -- call_overload answers 'No matching
   signature for function.', which is right for a subprogram and wrong here,
   since what is wrong is the COUNT and nothing about the types. */
void  alg_arity_counts(int32_t got, const char *expected);

Value  *alg_cell(Value initial);
Value   alg_closure(const char *name, AlgFunction fn, Value **cells, int32_t cell_count, int32_t arity,
                    const char **types);
Value   alg_call(Value callee, Value *args, int32_t count);

Value   alg_call_named(Value callee, Value *args, int32_t count, const char **names);
Value   alg_invoke_named(Value receiver, const char *name, Value *args, int32_t count,
                         const char **names);
Value   alg_new_named(Value klass, Value *args, int32_t count, const char **names);

Value alg_pointer(void *address);

Value alg_foreign(const char *symbol, const char *library, const char **types,
                  int32_t count, const char *returns, Value *args);

Value alg_foreign_call(Value symbol, Value library, Value types, Value returns, Value args);

/* The collector.  `alg_roots` registers one unit's module-level variables by
   address, which the emitter calls from `init_<Unit>()`; `alg_collect` marks
   from every registered root and releases what nothing points at, answering
   how many objects it released.

   A caller chooses WHEN, because a value living only in a C local is invisible
   here: the VM collects at the top of its dispatch loop, where every live
   guest value is on its stack or in a global. */
void    alg_roots(Value **slots, int32_t count);
int32_t alg_collect(void);
Value   alg_collected(void);

Value   alg_overloads(const char *name);
void    alg_overload(Value set, AlgFunction fn, int32_t arity, const char **types);

/* Str with a precision [RT-028]: exactly that many decimal places, never
   exponent form, correctly rounded from the binary value.  alg_str_padded
   right-aligns the result in a field it never truncates. */
Value alg_str_fixed(Value v, Value decimals);
Value alg_str_padded(Value v, Value width, Value decimals);

/* The bitwise operators [EXP-023], [EXP-024], over Integers of any size: two's
   complement extended infinitely to the left, so every operation is total and
   no width is named anywhere.  Each checks for a class's own operator first,
   as alg_div_int does. */
Value alg_bit_and(Value a, Value b);
Value alg_bit_or(Value a, Value b);
Value alg_bit_xor(Value a, Value b);
Value alg_bit_not(Value a);
Value alg_shift_left(Value a, Value b);
Value alg_shift_right(Value a, Value b);

Value alg_copy(Value text, Value begin, Value length);
Value alg_pos(Value text, Value part);

/* Pos from a starting index. The answer is still an index into the whole
   text, so it can be fed back in as the next search's start. */
Value alg_pos_from(Value text, Value part, Value start);

/* ASCII-only, and type-preserving: a Char folds to a Char, a String to a
   String.  Both refuse anything that is not text. */
Value alg_to_upper(Value text);
Value alg_to_lower(Value text);
Value alg_char(Value code);
Value alg_ord(Value v);
Value alg_val(Value v);

Value alg_succ(Value v);
Value alg_pred(Value v);
Value alg_max(Value a, Value b);

Value alg_clock(void);
Value alg_mod(Value a, Value b);

Value alg_text_file(void);
Value alg_file_exists(Value name);

/* Directories.  MkDir makes one, RmDir removes an empty one, ChDir moves the
   process, and GetDir answers where it is -- taking nothing, because the drive
   Turbo Pascal selects does not exist here. */
Value alg_mkdir(Value name);
Value alg_rmdir(Value name);
Value alg_chdir(Value name);
Value alg_getdir(void);

void alg_arity(int32_t got, int32_t expected);

void alg_declared(bool defined, const char *name);

/* ── The compiled safe point ──────────────────────────────────────────────
 * A compiled program used to collect only where it called `Collect` itself,
 * so a loop that allocated grew without bound -- while still paying for the
 * shadow stack that exists to make collection precise.  The runtime holds the
 * collector; the EMITTER holds the only knowledge of where collecting is
 * safe.  So the trigger is emitted: CEmitter puts one of these at the top of
 * every loop body, which is the compiled equivalent of the machine's
 * top-of-dispatch-loop and the tree walker's statement boundary.
 *
 * ⚠️ A LOOP BODY'S TOP IS SAFE WHERE AN ARBITRARY ALLOCATION IS NOT.  An
 * intermediate inside one expression is in no local and registered nowhere --
 * `alg_add(v_t, alg_text_length(alg_str(v_i)))` holds a string the shadow
 * stack cannot see -- which is why the runtime must not collect from
 * `obj_alloc`.  At the top of a body every live value is a registered local
 * or a module-level root.
 *
 * Inline, and a counter rather than a call, for the reason `alg_root_top` is
 * touched directly: this runs once per iteration of every loop a program has.
 *
 * `alg_tick_every` is the POLICY and 0 turns it off.  The default is a
 * measurement rather than a fact, and ALG_COLLECT_EVERY overrides it. */
extern int32_t alg_tick;
extern int32_t alg_tick_every;

void alg_tick_over(void);

static inline void alg_safe_point(void) {
    if (alg_tick_every > 0 && ++alg_tick >= alg_tick_every) alg_tick_over();
}

Value alg_is(Value v, const char *name);

Value alg_cast(Value v, const char *name);

/* `is` and `as` against a type the EMITTER resolved, which is every built-in
   type name [TYP-002].
 *
 * The pair above take the type as a string the emitter wrote, so each test
 * pays a linear scan of the subrange table and a case-insensitive comparison
 * for something fixed when the C was written -- and they were the two heaviest
 * functions in a profile of a real program.  A written type name folds and
 * cannot change at run time, so the emitter resolves it to one of these codes
 * and the test becomes an integer compare.
 *
 * Only the BUILT-IN names resolve.  A class, a singleton, an enumeration and a
 * subrange all keep the string form, because a program may declare one whose
 * name is a built-in's -- `class List` is legal, and `X is List` must then
 * answer for the instance as well as for a List.  CEmitter.ResolvedKind is
 * where that decision lives, and it refuses any name the program declares.
 *
 * Inline rather than called, because an out-of-line call was most of what the
 * string version cost: interning the names behind alg_is measured 1.05x on the
 * Inn where resolving them here measures more.  That is why Obj's layout is
 * public -- the same reason alg_root_top is. */
typedef enum {
    ALG_KIND_NONE = 0,

    ALG_KIND_BOOLEAN,
    ALG_KIND_INTEGER,
    ALG_KIND_DOUBLE,
    ALG_KIND_STRING,
    ALG_KIND_CHAR,
    ALG_KIND_POINTER,

    ALG_KIND_LIST,
    ALG_KIND_SET,
    ALG_KIND_STACK,
    ALG_KIND_ARRAY,
    ALG_KIND_MAP,
    ALG_KIND_TEXTFILE,
    ALG_KIND_BUFFER
} AlgKind;

/* The code a value answers to, or ALG_KIND_NONE for nil and for every object
   no built-in type name describes -- an instance, a class, an enumeration
   member, a closure.  An Integer is two representations [LEX-018], so a
   bignum answers ALG_KIND_INTEGER as a machine word does. */
static inline int alg_kind_of(Value v) {
    switch (v.type) {
        case VAL_NIL:     return ALG_KIND_NONE;
        case VAL_BOOL:    return ALG_KIND_BOOLEAN;
        case VAL_INT:     return ALG_KIND_INTEGER;
        case VAL_DOUBLE:  return ALG_KIND_DOUBLE;
        case VAL_STRING:  return ALG_KIND_STRING;
        case VAL_CHAR:    return ALG_KIND_CHAR;
        case VAL_POINTER: return ALG_KIND_POINTER;
        case VAL_OBJ:     break;
    }

    switch (v.obj->type) {
        case OBJ_BIGINT: return ALG_KIND_INTEGER;
        case OBJ_LIST:   return ALG_KIND_LIST;
        case OBJ_SET:    return ALG_KIND_SET;
        case OBJ_STACK:  return ALG_KIND_STACK;
        case OBJ_ARRAY:  return ALG_KIND_ARRAY;
        case OBJ_MAP:    return ALG_KIND_MAP;
        case OBJ_FILE:   return ALG_KIND_TEXTFILE;
        case OBJ_BUFFER: return ALG_KIND_BUFFER;

        default:         return ALG_KIND_NONE;
    }
}

/* Reports a cast that did not hold, which is the only part of `as` that is not
   a comparison.  Out of line so the path that succeeds carries none of it. */
Value alg_cast_failed(Value v, const char *name);

/* nil has no type, so it IS no kind and every test of it is false [VAL-010] --
   which falls out of nil answering ALG_KIND_NONE and no resolved code being
   ALG_KIND_NONE. */
static inline Value alg_is_kind(Value v, int kind) {
    return alg_bool(alg_kind_of(v) == kind);
}

/* A cast passes nil, where a test of it is false [VAR-005], and checks rather
   than converts: `7 as Double` raises as it always has. */
static inline Value alg_cast_kind(Value v, int kind, const char *name) {
    if (v.type == VAL_NIL) return v;

    if (alg_kind_of(v) == kind) return v;

    return alg_cast_failed(v, name);
}

/* `is` and `as` against a CLASS the emitter resolved to its handle, which walks
 * the instance's chain comparing ObjClass pointers instead of names.
 *
 * Out of line where the built-in pair above are inline, because ObjClass is
 * private to algol.c and exposing it would be a far wider contract than Obj's
 * three fields.  The win here is the strings rather than the call: the name
 * version compares one per class per level, and a member read walks that chain
 * several times.
 *
 * Sound only because alg_class allocates ONE ObjClass per class and the
 * handles are roots, so a class's identity is stable for the run.  The emitter
 * resolves a name only where the program declares exactly one class of it --
 * two classes of one name are two objects, where the other two processors
 * match a class by name and answer true for either, so comparing handles there
 * would diverge.  CEmitter.ResolvedClass is where that is decided. */
Value alg_is_class(Value v, Value klass);
Value alg_cast_class(Value v, Value klass, const char *name);

void  alg_set_arguments(int argc, char **argv);
Value alg_param_count(void);
Value alg_param_str(Value index);

void alg_test_begin(int32_t count, const char *file);
void alg_test_file(const char *file);
void alg_test_end_file(void);
void alg_test_run(const char *name, AlgFunction body);
int  alg_test_summary(void);

void alg_assert_true(Value value);
void alg_assert_equal(Value expected, Value actual);

void alg_assert_fail(Value message);

void  alg_write(Value v);

void  alg_halt(Value status);

Value alg_param(Value argument, const char *declared);

Value alg_widen(Value argument, const char *declared);
void  alg_writeln(Value v);

void  alg_writeln_blank(void);
Value alg_str(Value v);

/* Writes a line to the ERROR stream [RT-030].
 *
 * Named for the stream and not for the word 'error', deliberately: alg_error
 * RAISES and never returns, and two functions a few letters apart meaning
 * opposite things is a misreading waiting to happen.  This one prints and
 * returns.
 *
 * Flushes STDOUT first, so a program's own output cannot appear after a
 * diagnostic that followed it: stderr is unbuffered and stdout is
 * block-buffered the moment it is redirected, which is exactly the ordering
 * this built-in exists to let a program get right. */
void alg_stderr_line(Value v);

/* ── The shadow stack ─────────────────────────────────────────────────────
   Where a subprogram's locals are registered, so that a collection can see
   them.

   `alg_roots` covers every module-level variable, because the emitter can take
   a static's address once and be done.  A LOCAL has no such address: it is an
   ordinary C local, live only while its frame is, so the emitter registers a
   range on the way in and truncates the stack on the way out.  One entry
   serves a single local (`count` of 1), a subprogram's whole argument array,
   and a captured cell alike.

   The depth is read and written DIRECTLY by generated code -- `int32_t r =
   alg_root_top;` to save, `alg_root_top = r;` to restore -- because a block
   boundary is far more common than a declaration and a call per brace is a
   cost the generated code should not carry.  The push is inline for the same
   reason: a local declared inside a loop is registered once an iteration. */
/* The slots are VOLATILE because a local inside a `try` is: the emitter marks
   one so that a value written before the `setjmp` survives the `longjmp`, and
   registering it through a plain `Value *` would quietly cast that away.  The
   qualifier costs the collector nothing it can measure -- it reads each slot
   once per collection -- and a plain local converts to it without a cast. */
typedef struct {
    volatile Value *slots;
    int32_t         count;
} AlgRoots;

extern AlgRoots *alg_root_stack;
extern int32_t   alg_root_top;
extern int32_t   alg_root_room;

void alg_root_grow(void);

static inline void alg_root(volatile Value *slots, int32_t count) {
    if (alg_root_top == alg_root_room) {
        alg_root_grow();

        /* Out of memory here is not fatal to the program, only to collection,
           and `alg_root_grow` has already declined on its way out. */
        if (alg_root_top == alg_root_room) return;
    }

    alg_root_stack[alg_root_top].slots = slots;
    alg_root_stack[alg_root_top].count = count;

    alg_root_top++;
}

/* ── A TEMPORARY is a root too ────────────────────────────────────────────
   An intermediate inside one expression -- the left operand of a `+` whose
   right operand is a call -- is in no local and no argument array, so the
   shadow stack could not see it.  That was survivable while a collection
   happened only where a program asked for one: an expression is never
   interrupted by its own statement boundary.  It stopped being survivable
   the moment collection became automatic, because a safe point inside a
   CALLEE fires while the caller is still part way through an expression.

   So the emitter wraps each intermediate in `alg_hold`, which pushes the
   VALUE rather than a pointer to it: there is no C local whose address could
   be taken.

   ⚠️ A STACK OF ITS OWN, and sharing the shadow stack was both slower and
   harder to emit.  An entry there is a pointer and a count, so a held value
   needed a third field and three stores where this needs one -- and the two
   have different LIFETIMES: a declaration's root lives to the end of its
   block, a temporary to the end of its statement.  Separate tops mean a
   statement boundary restores one without the other, so a declaration in the
   middle of a block needs no special case at all.

   A Value that cannot reference the heap is not pushed, which is what keeps
   arithmetic free. */
extern Value  *alg_holds;
extern int32_t alg_hold_top;
extern int32_t alg_hold_room;

void alg_hold_grow(void);

static inline Value alg_hold(Value v) {
    if (v.type != VAL_OBJ && v.type != VAL_STRING && v.type != VAL_CHAR) return v;

    if (alg_hold_top == alg_hold_room) {
        alg_hold_grow();

        /* Out of memory here is not fatal to the program, only to collection,
           and `alg_hold_grow` has already declined on its way out. */
        if (alg_hold_top == alg_hold_room) return v;
    }

    alg_holds[alg_hold_top++] = v;
    return v;
}

typedef struct AlgFrame {
    jmp_buf          jump;
    struct AlgFrame *previous;
    Value            raised;

    /* The shadow stack's depth when the `try` was entered, so that a raise
       several calls down truncates every frame it unwound past.  The normal
       path needs nothing: each block restores its own depth as it closes.
       `holds` is the same question for held temporaries, which a raise
       skips past in exactly the same way. */
    int32_t          roots;
    int32_t          holds;
} AlgFrame;

void alg_push_frame(AlgFrame *frame);
void alg_pop_frame(void);
_Noreturn void alg_raise(Value value);

int32_t alg_handler(Value raised, const char **names, int32_t count);

_Noreturn void alg_error(const char *message);

#endif
