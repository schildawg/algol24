/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_CORE_H
#define ALG_CORE_H

#include "algol.h"

Value f_max(Value **cells, Value *args, int32_t count);
Value f_mod(Value **cells, Value *args, int32_t count);
Value f_stepped(Value **cells, Value *args, int32_t count);
Value f_succ(Value **cells, Value *args, int32_t count);
Value f_pred(Value **cells, Value *args, int32_t count);
extern Value fn_max;
extern Value fn_mod;
extern Value fn_stepped;
extern Value fn_succ;
extern Value fn_pred;
void init_Core(void);

#endif
