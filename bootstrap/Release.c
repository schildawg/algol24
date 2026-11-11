/* Generated from Algol-24.  Do not edit. */
#include "Release.h"

Value v_version;
bool d_version;

static Value *roots_Release[] = {
    &v_version,
};

void init_Release(void) {
    alg_roots(roots_Release, 1);
    int32_t rh_1212 = alg_hold_top;
    v_version = alg_literal("0.2.5");
    d_version = true;
    alg_hold_top = rh_1212;
}
