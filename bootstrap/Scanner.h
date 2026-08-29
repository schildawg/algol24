/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_SCANNER_H
#define ALG_SCANNER_H

#include "algol.h"

Value f_tolower(Value **cells, Value *args, int32_t count);
Value f_tointeger(Value **cells, Value *args, int32_t count);
Value f_exceedsinteger(Value **cells, Value *args, int32_t count);
extern Value v_digits;
extern Value v_uppercase;
extern Value v_lowercase;
extern Value fn_tolower;
extern Value fn_tointeger;
extern Value fn_exceedsinteger;
extern Value v_keywords;
extern Value v_haderror;
extern Value v_lasterror;
extern Value k_scanner;
void init_Scanner(void);

#endif
