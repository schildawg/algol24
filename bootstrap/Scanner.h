/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_SCANNER_H
#define ALG_SCANNER_H

#include "algol.h"

Value f_ToLower(Value **cells, Value *args, int32_t count);
Value f_ToInteger(Value **cells, Value *args, int32_t count);
extern Value v_DIGITS;
extern Value v_UPPERCASE;
extern Value v_LOWERCASE;
extern Value fn_ToLower;
extern Value fn_ToInteger;
extern Value v_Keywords;
extern Value v_HadError;
extern Value v_LastError;
extern Value k_Scanner;
void init_Scanner(void);

#endif
