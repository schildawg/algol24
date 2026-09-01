/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_INTERPRETER_H
#define ALG_INTERPRETER_H

#include "algol.h"

Value f_setprogramarguments(Value **cells, Value *args, int32_t count);
Value f_suppressoutput(Value **cells, Value *args, int32_t count);
Value f_rendered(Value **cells, Value *args, int32_t count);
Value f_stringify(Value **cells, Value *args, int32_t count);
Value f_parsednumber(Value **cells, Value *args, int32_t count);
Value f_labelat(Value **cells, Value *args, int32_t count);
Value f_names(Value **cells, Value *args, int32_t count);
extern Value v_programarguments;
extern bool d_programarguments;
extern Value fn_setprogramarguments;
extern Value v_outputsuppressed;
extern bool d_outputsuppressed;
extern Value fn_suppressoutput;
extern Value fn_rendered;
extern Value fn_stringify;
extern Value k_native;
extern Value fn_parsednumber;
extern Value k_interpreter;
extern Value k_broke;
extern Value k_continued;
extern Value k_jumped;
extern Value fn_labelat;
extern Value fn_names;
extern Value k_raised;
extern Value k_return;
void init_Interpreter(void);

#endif
