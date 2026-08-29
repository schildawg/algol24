/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_CEMITTER_H
#define ALG_CEMITTER_H

#include "algol.h"

Value f_indentation(Value **cells, Value *args, int32_t count);
Value f_quotec(Value **cells, Value *args, int32_t count);
extern Value v_hoistVabove;
extern Value fn_indentation;
extern Value fn_quotec;
extern Value k_emitunit;
extern Value k_cemitter;
void init_CEmitter(void);

#endif
