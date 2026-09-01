/* Generated from Algol-24.  Do not edit. */
#include "Core.h"

Value f_max(Value **cells, Value *args, int32_t count);
Value f_mod(Value **cells, Value *args, int32_t count);
Value f_stepped(Value **cells, Value *args, int32_t count);
Value f_succ(Value **cells, Value *args, int32_t count);
Value f_pred(Value **cells, Value *args, int32_t count);
static Value or_0;
static Value or_1;
static Value or_2;
Value fn_max;
static const char *t_f_max[] = { "A : Any", "B : Any" };
static Value or_3;
Value fn_mod;
static const char *t_f_mod[] = { "A : Any", "B : Any" };
static Value or_4;
Value fn_stepped;
static const char *t_f_stepped[] = { "X : Any", "By : Integer", "What : String" };
Value fn_succ;
static const char *t_f_succ[] = { "X : Any" };
Value fn_pred;
static const char *t_f_pred[] = { "X : Any" };

Value f_max(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    Value v_a = args[0];
    (void)v_a;
    Value v_b = args[1];
    (void)v_b;
    if (alg_truthy(alg_not(((or_2 = ((or_0 = alg_is(v_a, "Integer"), alg_truthy(or_0) ? or_0 : alg_is(v_a, "Double"))), !alg_truthy(or_2) ? or_2 : ((or_1 = alg_is(v_b, "Integer"), alg_truthy(or_1) ? or_1 : alg_is(v_b, "Double")))))))) {
        alg_raise(alg_string("Max expects numbers."));
    }
    if (alg_truthy(alg_greater(v_a, v_b))) {
        return v_a;
    }
    return v_b;
    return alg_nil();
}

Value f_mod(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    Value v_a = args[0];
    (void)v_a;
    Value v_b = args[1];
    (void)v_b;
    if (alg_truthy(alg_not(((or_3 = alg_is(v_a, "Integer"), !alg_truthy(or_3) ? or_3 : alg_is(v_b, "Integer")))))) {
        alg_raise(alg_string("Mod expects Integers."));
    }
    if (alg_truthy(alg_equal(v_b, alg_int(0)))) {
        alg_raise(alg_string("Mod failed: Division by zero."));
    }
    return alg_subtract(v_a, alg_multiply((alg_div_int(v_a, v_b)), v_b));
    return alg_nil();
}

Value f_stepped(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 3);
    Value v_x = args[0];
    (void)v_x;
    Value v_by = alg_param(args[1], "Integer");
    (void)v_by;
    Value v_what = alg_param(args[2], "String");
    (void)v_what;
    if (alg_truthy(alg_is(v_x, "Integer"))) {
        return alg_add(v_x, v_by);
    }
    if (alg_truthy(alg_not((alg_is(v_x, "Char"))))) {
        alg_raise(alg_add(alg_add(alg_add(v_what, alg_string(" failed: '")), alg_str(v_x)), alg_string("' has no ordinal.")));
    }
    Value v_code = alg_add(alg_ord(v_x), v_by);
    (void)v_code;
    if (alg_truthy((or_4 = alg_less(v_code, alg_int(0)), alg_truthy(or_4) ? or_4 : alg_greater(v_code, alg_int(1114111))))) {
        alg_raise(alg_add(alg_add(alg_add(v_what, alg_string(" failed: '")), alg_str(v_x)), alg_string("' has no ordinal beyond it.")));
    }
    return alg_char(v_code);
    return alg_nil();
}

Value f_succ(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_x = args[0];
    (void)v_x;
    return f_stepped(NULL, (Value[]){v_x, alg_int(1), alg_string("Succ")}, 3);
    return alg_nil();
}

Value f_pred(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_x = args[0];
    (void)v_x;
    return f_stepped(NULL, (Value[]){v_x, alg_negate(alg_int(1)), alg_string("Pred")}, 3);
    return alg_nil();
}

void init_Core(void) {
    fn_max = alg_closure("Max", f_max, NULL, 0, 2, t_f_max);
    fn_mod = alg_closure("Mod", f_mod, NULL, 0, 2, t_f_mod);
    fn_stepped = alg_closure("Stepped", f_stepped, NULL, 0, 3, t_f_stepped);
    fn_succ = alg_closure("Succ", f_succ, NULL, 0, 1, t_f_succ);
    fn_pred = alg_closure("Pred", f_pred, NULL, 0, 1, t_f_pred);
}
