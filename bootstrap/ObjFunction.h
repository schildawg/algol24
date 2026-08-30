/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_OBJFUNCTION_H
#define ALG_OBJFUNCTION_H

#include "algol.h"

Value f_typenameof(Value **cells, Value *args, int32_t count);
Value f_nameofclass(Value **cells, Value *args, int32_t count);
Value f_samesignature(Value **cells, Value *args, int32_t count);
Value f_widens(Value **cells, Value *args, int32_t count);
Value f_inheritsfrom(Value **cells, Value *args, int32_t count);
extern Value fn_typenameof;
extern Value fn_nameofclass;
extern Value k_objoverloads;
extern Value k_numbermethod;
extern Value fn_samesignature;
extern Value fn_widens;
extern Value fn_inheritsfrom;
extern Value k_objfunction;
void init_ObjFunction(void);

#endif
