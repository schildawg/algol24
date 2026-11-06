/* Generated from Algol-24.  Do not edit. */
#include "Release.h"

Value v_version;
bool d_version;

static Value *roots_Release[] = {
    &v_version,
};

void init_Release(void) {
    alg_roots(roots_Release, 1);
    v_version = alg_string("0.2.3");
    d_version = true;
}
