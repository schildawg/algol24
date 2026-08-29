/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_TYPECHECKER_H
#define ALG_TYPECHECKER_H

#include "algol.h"

Value f_rejects(Value **cells, Value *args, int32_t count);
extern Value k_typelookup;
extern Value k_typechecker;
extern Value fn_rejects;
extern Value v_hider;
void init_TypeChecker(void);

#endif
