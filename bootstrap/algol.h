#ifndef ALGOL_H
#define ALGOL_H

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

    OBJ_OVERLOADS,

    OBJ_BIGINT,
    OBJ_LIST,
    OBJ_SET,
    OBJ_STACK,
    OBJ_ARRAY,
    OBJ_MAP,
    OBJ_FILE,

    OBJ_BUFFER
} ObjType;

typedef struct {
    ObjType type;
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

typedef Value (*AlgFunction)(Value **cells, Value *args, int32_t count);

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

Value   alg_overloads(const char *name);
void    alg_overload(Value set, AlgFunction fn, int32_t arity, const char **types);

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

Value alg_is(Value v, const char *name);

Value alg_cast(Value v, const char *name);

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

typedef struct AlgFrame {
    jmp_buf          jump;
    struct AlgFrame *previous;
    Value            raised;
} AlgFrame;

void alg_push_frame(AlgFrame *frame);
void alg_pop_frame(void);
_Noreturn void alg_raise(Value value);

int32_t alg_handler(Value raised, const char **names, int32_t count);

_Noreturn void alg_error(const char *message);

#endif
