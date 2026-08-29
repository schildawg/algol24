/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_CEMITTER_H
#define ALG_CEMITTER_H

#include "algol.h"

Value f_Indentation(Value **cells, Value *args, int32_t count);
Value f_QuoteC(Value **cells, Value *args, int32_t count);
extern Value v_HOIST_ABOVE;
extern Value fn_Indentation;
extern Value fn_QuoteC;
extern Value k_EmitUnit;
extern Value k_CEmitter;
void init_CEmitter(void);

#endif
