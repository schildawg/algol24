/* Generated from Algol-24.  Do not edit. */
#include "System.h"

Value f_max(Value **cells, Value *args, int32_t count);
static Value or_0;
static Value or_1;
static Value or_2;
Value fn_max;
static const char *t_f_max[] = { "A : Any", "B : Any" };

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

void init_System(void) {
    fn_max = alg_closure("Max", f_max, NULL, 0, 2, t_f_max);
}
