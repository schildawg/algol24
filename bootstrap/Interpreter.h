/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_INTERPRETER_H
#define ALG_INTERPRETER_H

#include "algol.h"

Value f_setprogramarguments(Value **cells, Value *args, int32_t count);
Value f_suppressoutput(Value **cells, Value *args, int32_t count);
Value f_rendered(Value **cells, Value *args, int32_t count);
Value f_stringify(Value **cells, Value *args, int32_t count);
Value f_labelat(Value **cells, Value *args, int32_t count);
Value f_names(Value **cells, Value *args, int32_t count);
extern Value k_clocknative;
extern Value k_lengthnative;
extern Value k_copynative;
extern Value k_posnative;
extern Value k_arraynative;
extern Value k_listnative;
extern Value k_mapnative;
extern Value k_setnative;
extern Value k_stacknative;
extern Value v_programarguments;
extern bool d_programarguments;
extern Value fn_setprogramarguments;
extern Value v_outputsuppressed;
extern bool d_outputsuppressed;
extern Value fn_suppressoutput;
extern Value fn_rendered;
extern Value k_writenative;
extern Value k_writelnnative;
extern Value k_haltnative;
extern Value k_ordnative;
extern Value k_valnative;
extern Value k_charnative;
extern Value k_maxnative;
extern Value k_modnative;
extern Value k_textfilenative;
extern Value k_buffernative;
extern Value k_fileexistsnative;
extern Value k_paramcountnative;
extern Value k_paramstrnative;
extern Value fn_stringify;
extern Value k_strnative;
extern Value k_asserttruenative;
extern Value k_assertequalnative;
extern Value k_failnative;
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
