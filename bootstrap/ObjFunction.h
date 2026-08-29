/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_OBJFUNCTION_H
#define ALG_OBJFUNCTION_H

#include "algol.h"

Value f_TypeNameOf(Value **cells, Value *args, int32_t count);
Value f_NameOfClass(Value **cells, Value *args, int32_t count);
Value f_Widens(Value **cells, Value *args, int32_t count);
Value f_InheritsFrom(Value **cells, Value *args, int32_t count);
extern Value fn_TypeNameOf;
extern Value fn_NameOfClass;
extern Value fn_Widens;
extern Value fn_InheritsFrom;
extern Value k_ObjFunction;
void init_ObjFunction(void);

#endif
