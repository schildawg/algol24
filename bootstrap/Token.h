/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_TOKEN_H
#define ALG_TOKEN_H

#include "algol.h"

Value f_definesubrange(Value **cells, Value *args, int32_t count);
Value f_subrangeindex(Value **cells, Value *args, int32_t count);
Value f_issubrange(Value **cells, Value *args, int32_t count);
Value f_underlyingtype(Value **cells, Value *args, int32_t count);
Value f_canonicaltype(Value **cells, Value *args, int32_t count);
Value f_foldcase(Value **cells, Value *args, int32_t count);
extern Value v_foldVupper;
extern bool d_foldVupper;
extern Value v_foldVlower;
extern bool d_foldVlower;
extern Value v_subrangeVnames;
extern bool d_subrangeVnames;
extern Value v_subrangeVlows;
extern bool d_subrangeVlows;
extern Value v_subrangeVhighs;
extern bool d_subrangeVhighs;
extern Value fn_definesubrange;
extern Value fn_subrangeindex;
extern Value fn_issubrange;
extern Value fn_underlyingtype;
extern Value fn_canonicaltype;
extern Value fn_foldcase;
extern Value k_token;
void init_Token(void);

#endif
