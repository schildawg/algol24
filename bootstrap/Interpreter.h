/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_INTERPRETER_H
#define ALG_INTERPRETER_H

#include "algol.h"

Value f_SetProgramArguments(Value **cells, Value *args, int32_t count);
Value f_SuppressOutput(Value **cells, Value *args, int32_t count);
Value f_Stringify(Value **cells, Value *args, int32_t count);
extern Value k_ClockNative;
extern Value k_LengthNative;
extern Value k_CopyNative;
extern Value k_PosNative;
extern Value k_ArrayNative;
extern Value k_ListNative;
extern Value k_MapNative;
extern Value k_SetNative;
extern Value k_StackNative;
extern Value v_ProgramArguments;
extern Value fn_SetProgramArguments;
extern Value v_OutputSuppressed;
extern Value fn_SuppressOutput;
extern Value k_WriteNative;
extern Value k_WriteLnNative;
extern Value k_OrdNative;
extern Value k_ValNative;
extern Value k_CharNative;
extern Value k_MaxNative;
extern Value k_ModNative;
extern Value k_TextFileNative;
extern Value k_FileExistsNative;
extern Value k_ParamCountNative;
extern Value k_ParamStrNative;
extern Value fn_Stringify;
extern Value k_StrNative;
extern Value k_AssertTrueNative;
extern Value k_AssertEqualNative;
extern Value k_FailNative;
extern Value k_Interpreter;
extern Value k_Broke;
extern Value k_Raised;
extern Value k_Return;
void init_Interpreter(void);

#endif
