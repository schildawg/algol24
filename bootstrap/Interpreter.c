/* Generated from Algol-24.  Do not edit. */
#include "Interpreter.h"
#include "Environment.h"
#include "Expr.h"
#include "ObjBuffer.h"
#include "ObjClass.h"
#include "ObjCollection.h"
#include "ObjEnum.h"
#include "ObjFile.h"
#include "ObjFunction.h"
#include "ObjInstance.h"
#include "Parser.h"
#include "Resolver.h"
#include "Scanner.h"
#include "Stmt.h"
#include "Token.h"
#include "TokenType.h"

Value f_SetProgramArguments(Value **cells, Value *args, int32_t count);
Value f_SuppressOutput(Value **cells, Value *args, int32_t count);
Value f_Stringify(Value **cells, Value *args, int32_t count);
Value k_ClockNative;
static const char *t_ClockNative_Call_2[] = { "Any", "Any" };
Value k_LengthNative;
static const char *t_LengthNative_Call_2[] = { "Any", "Any" };
Value k_CopyNative;
static const char *t_CopyNative_Call_2[] = { "Any", "Any" };
Value k_PosNative;
static const char *t_PosNative_Call_2[] = { "Any", "Any" };
Value k_ArrayNative;
static const char *t_ArrayNative_Call_2[] = { "Any", "Any" };
Value k_ListNative;
static const char *t_ListNative_Call_2[] = { "Any", "Any" };
Value k_MapNative;
static const char *t_MapNative_Call_2[] = { "Any", "Any" };
Value k_SetNative;
static Value or_0;
static const char *t_SetNative_Call_2[] = { "Any", "Any" };
Value k_StackNative;
static const char *t_StackNative_Call_2[] = { "Any", "Any" };
Value v_ProgramArguments;
Value fn_SetProgramArguments;
Value v_OutputSuppressed;
Value fn_SuppressOutput;
Value k_WriteNative;
static const char *t_WriteNative_Call_2[] = { "Any", "Any" };
Value k_WriteLnNative;
static const char *t_WriteLnNative_Call_2[] = { "Any", "Any" };
Value k_OrdNative;
static const char *t_OrdNative_Call_2[] = { "Any", "Any" };
Value k_ValNative;
static const char *t_ValNative_Call_2[] = { "Any", "Any" };
Value k_CharNative;
static const char *t_CharNative_Call_2[] = { "Any", "Any" };
Value k_MaxNative;
static const char *t_MaxNative_Call_2[] = { "Any", "Any" };
Value k_ModNative;
static const char *t_ModNative_Call_2[] = { "Any", "Any" };
Value k_TextFileNative;
static const char *t_TextFileNative_Call_2[] = { "Any", "Any" };
Value k_BufferNative;
static const char *t_BufferNative_Call_2[] = { "Any", "Any" };
Value k_FileExistsNative;
static const char *t_FileExistsNative_Call_2[] = { "Any", "Any" };
Value k_ParamCountNative;
static const char *t_ParamCountNative_Call_2[] = { "Any", "Any" };
Value k_ParamStrNative;
static Value or_1;
static const char *t_ParamStrNative_Call_2[] = { "Any", "Any" };
Value fn_Stringify;
Value k_StrNative;
static const char *t_StrNative_Call_2[] = { "Any", "Any" };
Value k_AssertTrueNative;
static const char *t_AssertTrueNative_Call_2[] = { "Any", "Any" };
Value k_AssertEqualNative;
static const char *t_AssertEqualNative_Call_2[] = { "Any", "Any" };
Value k_FailNative;
static const char *t_FailNative_Call_2[] = { "Any", "Any" };
Value k_Interpreter;
static Value or_2;
static Value or_3;
static Value or_4;
static Value or_5;
static Value or_6;
static Value or_7;
static Value or_8;
static Value or_9;
static Value or_10;
static Value or_11;
static Value or_12;
static Value or_13;
static Value or_14;
static Value or_15;
static Value or_16;
static Value or_17;
static Value or_18;
static const char *t_Interpreter_Interpret_1_List[] = { "List" };
static const char *t_Interpreter_HoistTests_9_List_List_Map_Boolean_Environment_Map_String_List_Map[] = { "List", "List", "Map", "Boolean", "Environment", "Map", "String", "List", "Map" };
static const char *t_Interpreter_RunTests_2_List_String[] = { "List", "String" };
static const char *t_Interpreter_Report_2_String_String[] = { "String", "String" };
static const char *t_Interpreter_VisitLiteral_1_LiteralExpr[] = { "LiteralExpr" };
static const char *t_Interpreter_VisitLogical_1_LogicalExpr[] = { "LogicalExpr" };
static const char *t_Interpreter_VisitGrouping_1_GroupingExpr[] = { "GroupingExpr" };
static const char *t_Interpreter_VisitUnary_1_UnaryExpr[] = { "UnaryExpr" };
static const char *t_Interpreter_VisitCollectionExpr_1_CollectionExpr[] = { "CollectionExpr" };
static const char *t_Interpreter_VisitSubscriptExpr_1_SubscriptExpr[] = { "SubscriptExpr" };
static const char *t_Interpreter_VisitSetSubscriptExpr_1_SetSubscriptExpr[] = { "SetSubscriptExpr" };
static const char *t_Interpreter_IsText_1[] = { "Any" };
static const char *t_Interpreter_VisitIsExpr_1_IsExpr[] = { "IsExpr" };
static const char *t_Interpreter_VisitVariableExpr_1_VariableExpr[] = { "VariableExpr" };
static const char *t_Interpreter_ThisField_2_Token_String[] = { "Token", "String" };
static const char *t_Interpreter_SetThisField_3_Token_String[] = { "Token", "Any", "String" };
static const char *t_Interpreter_LookupVariable_2_Token_Expr[] = { "Token", "Expr" };
static const char *t_Interpreter_VisitBinary_1_BinaryExpr[] = { "BinaryExpr" };
static const char *t_Interpreter_VisitCall_1_CallExpr[] = { "CallExpr" };
static const char *t_Interpreter_AssignQualified_3_String_Token[] = { "String", "Token", "Any" };
static const char *t_Interpreter_Qualified_2_String_Token[] = { "String", "Token" };
static const char *t_Interpreter_VisitGetExpr_1_GetExpr[] = { "GetExpr" };
static const char *t_Interpreter_VisitSetExpr_1_SetExpr[] = { "SetExpr" };
static const char *t_Interpreter_VisitSuperExpr_1_SuperExpr[] = { "SuperExpr" };
static const char *t_Interpreter_VisitThisExpr_1_ThisExpr[] = { "ThisExpr" };
static const char *t_Interpreter_ClassNameOf_1[] = { "Any" };
static const char *t_Interpreter_IsTruthy_1[] = { "Any" };
static const char *t_Interpreter_IsEqual_2[] = { "Any", "Any" };
static const char *t_Interpreter_Evaluate_1_Expr[] = { "Expr" };
static const char *t_Interpreter_Execute_1_Stmt[] = { "Stmt" };
static const char *t_Interpreter_Resolve_2_Expr_Integer[] = { "Expr", "Integer" };
static const char *t_Interpreter_ExecuteBlock_2_List_Environment[] = { "List", "Environment" };
static const char *t_Interpreter_VisitBlockStmt_1_BlockStmt[] = { "BlockStmt" };
static const char *t_Interpreter_VisitClassStmt_1_ClassStmt[] = { "ClassStmt" };
static const char *t_Interpreter_VisitObjectStmt_1_ObjectStmt[] = { "ObjectStmt" };
static const char *t_Interpreter_VisitEnumStmt_1_EnumStmt[] = { "EnumStmt" };
static const char *t_Interpreter_VisitExpressionStmt_1_ExpressionStmt[] = { "ExpressionStmt" };
static const char *t_Interpreter_VisitFunctionStmt_1_FunctionStmt[] = { "FunctionStmt" };
static const char *t_Interpreter_VisitIfStmt_1_IfStmt[] = { "IfStmt" };
static const char *t_Interpreter_VisitWhileStmt_1_WhileStmt[] = { "WhileStmt" };
static const char *t_Interpreter_Contains_2[] = { "Any", "Any" };
static const char *t_Interpreter_IsCallable_1[] = { "Any" };
static const char *t_Interpreter_ElementsOf_2_Token[] = { "Token", "Any" };
static const char *t_Interpreter_VisitForInStmt_1_ForInStmt[] = { "ForInStmt" };
static const char *t_Interpreter_VisitBreakStmt_1_BreakStmt[] = { "BreakStmt" };
static const char *t_Interpreter_VisitModuleStmt_1_ModuleStmt[] = { "ModuleStmt" };
static const char *t_Interpreter_VisitRaiseStmt_1_RaiseStmt[] = { "RaiseStmt" };
static const char *t_Interpreter_FindHandler_2_Map[] = { "Map", "Any" };
static const char *t_Interpreter_Handle_3_TryStmt[] = { "TryStmt", "Any", "Any" };
static const char *t_Interpreter_VisitTryStmt_1_TryStmt[] = { "TryStmt" };
static const char *t_Interpreter_VisitPrintStmt_1_PrintStmt[] = { "PrintStmt" };
static const char *t_Interpreter_VisitReturnStmt_1_ReturnStmt[] = { "ReturnStmt" };
static const char *t_Interpreter_VisitVarStmt_1_VarStmt[] = { "VarStmt" };
static const char *t_Interpreter_VisitVarGroupStmt_1_VarGroupStmt[] = { "VarGroupStmt" };
static const char *t_Interpreter_VisitAssignExpr_1_AssignExpr[] = { "AssignExpr" };
Value k_Broke;
Value k_Raised;
static const char *t_Raised_Init_1[] = { "Any" };
Value k_Return;
static const char *t_Return_Init_1[] = { "Any" };

static Value i_ClockNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_ClockNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(0);
    return alg_nil();
}

static Value m_ClockNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_clock();
    return alg_nil();
}

static Value i_LengthNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_LengthNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_LengthNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_length(alg_str(alg_subscript_get(v_Arguments, alg_int(0))));
    return alg_nil();
}

static Value i_CopyNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_CopyNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(3);
    return alg_nil();
}

static Value m_CopyNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_copy(alg_str(alg_subscript_get(v_Arguments, alg_int(0))), alg_subscript_get(v_Arguments, alg_int(1)), alg_subscript_get(v_Arguments, alg_int(2)));
    return alg_nil();
}

static Value i_PosNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_PosNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(2);
    return alg_nil();
}

static Value m_PosNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_pos(alg_str(alg_subscript_get(v_Arguments, alg_int(0))), alg_str(alg_subscript_get(v_Arguments, alg_int(1))));
    return alg_nil();
}

static Value i_ArrayNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_ArrayNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_ArrayNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    Value v_Result = alg_nil();
    (void)v_Result;
    (void)((v_Result = alg_new(k_ObjCollection, (Value[]){alg_string("Array")}, 1)));
    (void)(alg_invoke(v_Result, "Allocate", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1));
    return v_Result;
    return alg_nil();
}

static Value i_ListNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_ListNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(0);
    return alg_nil();
}

static Value m_ListNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_new(k_ObjCollection, (Value[]){alg_string("List")}, 1);
    return alg_nil();
}

static Value i_MapNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_MapNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(0);
    return alg_nil();
}

static Value m_MapNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_new(k_ObjCollection, (Value[]){alg_string("Map")}, 1);
    return alg_nil();
}

static Value i_SetNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_SetNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_negate(alg_int(1));
    return alg_nil();
}

static Value m_SetNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    Value v_Result = alg_nil();
    (void)v_Result;
    if (alg_truthy(alg_greater(alg_property(v_Arguments, "Length"), alg_int(1)))) {
        alg_raise(alg_add(alg_add(alg_string("Expected 0 or 1 arguments but got "), alg_str(alg_property(v_Arguments, "Length"))), alg_char_value(46)));
    }
    (void)((v_Result = alg_new(k_ObjCollection, (Value[]){alg_string("Set")}, 1)));
    if (alg_truthy(alg_equal(alg_property(v_Arguments, "Length"), alg_int(1)))) {
        {
            Value v_From = alg_subscript_get(v_Arguments, alg_int(0));
            (void)v_From;
            if (alg_truthy((or_0 = alg_not((alg_is(v_From, "ObjCollection"))), alg_truthy(or_0) ? or_0 : alg_not_equal(alg_property(v_From, "Kind"), alg_string("List"))))) {
                alg_raise(alg_add(alg_add(alg_string("Set expects (List) but got ("), f_TypeNameOf(NULL, (Value[]){v_From}, 1)), alg_string(").")));
            }
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_From, "Items"), "Length")))) {
                    {
                        (void)(alg_invoke(v_Result, "Invoke", (Value[]){alg_string("Add"), alg_list_keep(alg_list(), alg_subscript_get(alg_property(v_From, "Items"), v_I))}, 2));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
        }
    }
    return v_Result;
    return alg_nil();
}

static Value i_StackNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_StackNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(0);
    return alg_nil();
}

static Value m_StackNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_new(k_ObjCollection, (Value[]){alg_string("Stack")}, 1);
    return alg_nil();
}

Value f_SetProgramArguments(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Arguments = args[0];
    (void)v_Arguments;
    (void)((v_ProgramArguments = v_Arguments));
    return alg_nil();
}

Value f_SuppressOutput(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Suppress = args[0];
    (void)v_Suppress;
    (void)((v_OutputSuppressed = v_Suppress));
    return alg_nil();
}

static Value i_WriteNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_WriteNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_WriteNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    if (alg_truthy(alg_not(v_OutputSuppressed))) {
        (void)(alg_write(f_Stringify(NULL, (Value[]){v_TheInterpreter, alg_subscript_get(v_Arguments, alg_int(0))}, 2)));
    }
    return alg_nil();
    return alg_nil();
}

static Value i_WriteLnNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_WriteLnNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_negate(alg_int(1));
    return alg_nil();
}

static Value m_WriteLnNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    if (alg_truthy(alg_greater(alg_property(v_Arguments, "Length"), alg_int(1)))) {
        alg_raise(alg_add(alg_add(alg_string("Expected 0 or 1 arguments but got "), alg_str(alg_property(v_Arguments, "Length"))), alg_char_value(46)));
    }
    if (alg_truthy(alg_not(v_OutputSuppressed))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_Arguments, "Length"), alg_int(0)))) {
                (void)(alg_writeln(alg_string("")));
            } else {
                (void)(alg_writeln(f_Stringify(NULL, (Value[]){v_TheInterpreter, alg_subscript_get(v_Arguments, alg_int(0))}, 2)));
            }
        }
    }
    return alg_nil();
    return alg_nil();
}

static Value i_OrdNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_OrdNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_OrdNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    if (alg_truthy(alg_is(alg_subscript_get(v_Arguments, alg_int(0)), "ObjEnum"))) {
        return alg_property(alg_subscript_get(v_Arguments, alg_int(0)), "Ordinal");
    }
    return alg_ord(alg_subscript_get(v_Arguments, alg_int(0)));
    return alg_nil();
}

static Value i_ValNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_ValNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_ValNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_val(alg_subscript_get(v_Arguments, alg_int(0)));
    return alg_nil();
}

static Value i_CharNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_CharNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_CharNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_char(alg_subscript_get(v_Arguments, alg_int(0)));
    return alg_nil();
}

static Value i_MaxNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_MaxNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(2);
    return alg_nil();
}

static Value m_MaxNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_max(alg_subscript_get(v_Arguments, alg_int(0)), alg_subscript_get(v_Arguments, alg_int(1)));
    return alg_nil();
}

static Value i_ModNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_ModNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(2);
    return alg_nil();
}

static Value m_ModNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_mod(alg_subscript_get(v_Arguments, alg_int(0)), alg_subscript_get(v_Arguments, alg_int(1)));
    return alg_nil();
}

static Value i_TextFileNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_TextFileNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(0);
    return alg_nil();
}

static Value m_TextFileNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_new(k_ObjFile, NULL, 0);
    return alg_nil();
}

static Value i_BufferNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_BufferNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_negate(alg_int(1));
    return alg_nil();
}

static Value m_BufferNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    if (alg_truthy(alg_greater(alg_property(v_Arguments, "Length"), alg_int(1)))) {
        alg_raise(alg_add(alg_add(alg_string("Expected 0 or 1 arguments but got "), alg_str(alg_property(v_Arguments, "Length"))), alg_char_value(46)));
    }
    if (alg_truthy(alg_equal(alg_property(v_Arguments, "Length"), alg_int(0)))) {
        return alg_new(k_ObjBuffer, (Value[]){alg_int(0)}, 1);
    }
    return alg_new(k_ObjBuffer, (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
    return alg_nil();
}

static Value i_FileExistsNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_FileExistsNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_FileExistsNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_file_exists(alg_str(alg_subscript_get(v_Arguments, alg_int(0))));
    return alg_nil();
}

static Value i_ParamCountNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_ParamCountNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(0);
    return alg_nil();
}

static Value m_ParamCountNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_subtract(alg_property(v_ProgramArguments, "Length"), alg_int(1));
    return alg_nil();
}

static Value i_ParamStrNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_ParamStrNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_ParamStrNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    Value v_At = alg_nil();
    (void)v_At;
    (void)((v_At = alg_subscript_get(v_Arguments, alg_int(0))));
    if (alg_truthy((or_1 = alg_less(v_At, alg_int(0)), alg_truthy(or_1) ? or_1 : alg_greater_equal(v_At, alg_property(v_ProgramArguments, "Length"))))) {
        return alg_string("");
    }
    return alg_subscript_get(v_ProgramArguments, v_At);
    return alg_nil();
}

Value f_Stringify(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Value = args[1];
    (void)v_Value;
    if (alg_truthy(alg_equal(v_Value, alg_nil()))) {
        return alg_string("nil");
    }
    if (alg_truthy(alg_is(v_Value, "ObjInstance"))) {
        {
            Value v_Method = alg_invoke(alg_property(v_Value, "Klass"), "FindMethod", (Value[]){alg_string("ToString")}, 1);
            (void)v_Method;
            if (alg_truthy(alg_not_equal(v_Method, alg_nil()))) {
                return f_Stringify(NULL, (Value[]){v_TheInterpreter, alg_invoke(alg_invoke(v_Method, "Bind", (Value[]){v_Value}, 1), "Call", (Value[]){v_TheInterpreter, alg_list()}, 2)}, 2);
            }
        }
    }
    if (alg_truthy(alg_is(v_Value, "ObjCollection"))) {
        {
            Value v_Result = alg_char_value(91);
            (void)v_Result;
            Value v_First = alg_bool(true);
            (void)v_First;
            if (alg_truthy(alg_equal(alg_property(v_Value, "Kind"), alg_string("Map")))) {
                {
                    Value loop_0 = alg_iterable(alg_invoke(alg_property(v_Value, "Pairs"), "Keys", NULL, 0));
                    for (int32_t at_0 = 0; at_0 < alg_iterable_count(loop_0); at_0++) {
                        Value v_Key = alg_iterable_at(loop_0, at_0);
                        (void)v_Key;
                        {
                            if (alg_truthy(alg_not(v_First))) {
                                (void)((v_Result = alg_add(v_Result, alg_string(", "))));
                            }
                            (void)((v_First = alg_bool(false)));
                            (void)((v_Result = alg_add(alg_add(alg_add(v_Result, f_Stringify(NULL, (Value[]){v_TheInterpreter, v_Key}, 2)), alg_char_value(58)), f_Stringify(NULL, (Value[]){v_TheInterpreter, alg_invoke(alg_property(v_Value, "Pairs"), "Get", (Value[]){v_Key}, 1)}, 2))));
                        }
                    }
                }
            } else {
                {
                    Value loop_1 = alg_iterable(alg_property(v_Value, "Items"));
                    for (int32_t at_1 = 0; at_1 < alg_iterable_count(loop_1); at_1++) {
                        Value v_Element = alg_iterable_at(loop_1, at_1);
                        (void)v_Element;
                        {
                            if (alg_truthy(alg_not(v_First))) {
                                (void)((v_Result = alg_add(v_Result, alg_string(", "))));
                            }
                            (void)((v_First = alg_bool(false)));
                            (void)((v_Result = alg_add(v_Result, f_Stringify(NULL, (Value[]){v_TheInterpreter, v_Element}, 2))));
                        }
                    }
                }
            }
            return alg_add(v_Result, alg_char_value(93));
        }
    }
    return alg_str(v_Value);
    return alg_nil();
}

static Value i_StrNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_StrNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_StrNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return f_Stringify(NULL, (Value[]){v_TheInterpreter, alg_subscript_get(v_Arguments, alg_int(0))}, 2);
    return alg_nil();
}

static Value i_AssertTrueNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_AssertTrueNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_AssertTrueNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    if (alg_truthy(alg_not(alg_invoke(v_TheInterpreter, "IsTruthy", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1)))) {
        alg_raise(alg_string("Assertion 'left = right' failed."));
    }
    return alg_nil();
    return alg_nil();
}

static Value i_AssertEqualNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_AssertEqualNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(2);
    return alg_nil();
}

static Value m_AssertEqualNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    if (alg_truthy(alg_not(alg_invoke(v_TheInterpreter, "IsEqual", (Value[]){alg_subscript_get(v_Arguments, alg_int(0)), alg_subscript_get(v_Arguments, alg_int(1))}, 2)))) {
        {
            Value v_Left = alg_str(alg_subscript_get(v_Arguments, alg_int(0)));
            (void)v_Left;
            Value v_Right = alg_str(alg_subscript_get(v_Arguments, alg_int(1)));
            (void)v_Right;
            if (alg_truthy(alg_equal(v_Left, v_Right))) {
                alg_raise(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("Assertion 'left = right' failed.  Expected "), f_TypeNameOf(NULL, (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1)), alg_string(" '")), v_Left), alg_string("' but got ")), f_TypeNameOf(NULL, (Value[]){alg_subscript_get(v_Arguments, alg_int(1))}, 1)), alg_string(" '")), v_Right), alg_string("'.")));
            }
            alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Assertion 'left = right' failed.  Expected '"), v_Left), alg_string("' but got '")), v_Right), alg_string("'.")));
        }
    }
    return alg_nil();
    return alg_nil();
}

static Value i_FailNative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_FailNative_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_FailNative_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    alg_raise(alg_add(alg_string("Failed.  "), alg_str(alg_subscript_get(v_Arguments, alg_int(0)))));
    return alg_nil();
}

static Value i_Interpreter(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Env", alg_nil());
    alg_set_property(v_this, "Builtins", alg_nil());
    alg_set_property(v_this, "Globals", alg_nil());
    alg_set_property(v_this, "Locals", alg_nil());
    alg_set_property(v_this, "Modules", alg_nil());
    alg_set_property(v_this, "UnitsByName", alg_nil());
    return alg_nil();
}

static Value m_Interpreter_Init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_set_property(v_this, "Builtins", alg_new(k_Environment, NULL, 0)));
    (void)(alg_set_property(v_this, "Globals", alg_new(k_Environment, NULL, 0)));
    (void)(alg_set_property(alg_property(v_this, "Globals"), "Enclosing", alg_property(v_this, "Builtins")));
    (void)(alg_set_property(v_this, "Locals", alg_map()));
    (void)(alg_set_property(v_this, "Modules", alg_map()));
    (void)(alg_set_property(v_this, "UnitsByName", alg_map()));
    (void)(alg_set_property(v_this, "Env", alg_property(v_this, "Globals")));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("clock"), alg_new(k_ClockNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Length"), alg_new(k_LengthNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Copy"), alg_new(k_CopyNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Pos"), alg_new(k_PosNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Str"), alg_new(k_StrNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Array"), alg_new(k_ArrayNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("List"), alg_new(k_ListNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Map"), alg_new(k_MapNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Set"), alg_new(k_SetNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Stack"), alg_new(k_StackNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Ord"), alg_new(k_OrdNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Val"), alg_new(k_ValNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Char"), alg_new(k_CharNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Max"), alg_new(k_MaxNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Mod"), alg_new(k_ModNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Write"), alg_new(k_WriteNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("WriteLn"), alg_new(k_WriteLnNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Buffer"), alg_new(k_BufferNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("TextFile"), alg_new(k_TextFileNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("FileExists"), alg_new(k_FileExistsNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("ParamCount"), alg_new(k_ParamCountNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("ParamStr"), alg_new(k_ParamStrNative, NULL, 0)}, 2));
    return alg_nil();
}

static Value m_Interpreter_Interpret_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_Statements = args[0];
    (void)v_Statements;
    {
        AlgFrame frame_2;
        alg_push_frame(&frame_2);
        if (ALG_SETJMP(frame_2.jump) == 0) {
            {
                {
                    volatile Value v_I = alg_int(0);
                    (void)v_I;
                    while (alg_truthy(alg_less(v_I, alg_property(v_Statements, "Length")))) {
                        {
                            {
                                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(v_Statements, v_I)}, 1));
                            }
                            (void)((v_I = alg_add(v_I, alg_int(1))));
                        }
                    }
                }
            }
            alg_pop_frame();
        }
        else {
            static const char *names_2[] = {"Raised"};
            int32_t which_2 = alg_handler(frame_2.raised, names_2, 1);
            if (which_2 == 0) {
                {
                    volatile Value v_e = frame_2.raised;
                    (void)v_e;
                    alg_raise(alg_str(alg_property(v_e, "Value")));
                }
            }
            else {
                alg_raise(frame_2.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_HoistTests_9_List_List_Map_Boolean_Environment_Map_String_List_Map(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    Value v_Tests = args[1];
    (void)v_Tests;
    Value v_ByName = args[2];
    (void)v_ByName;
    Value v_Define = args[3];
    (void)v_Define;
    Value v_Scope = args[4];
    (void)v_Scope;
    Value v_DeclaredIn = args[5];
    (void)v_DeclaredIn;
    Value v_File = args[6];
    (void)v_File;
    Value v_Files = args[7];
    (void)v_Files;
    Value v_ByFile = args[8];
    (void)v_ByFile;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Statements, "Length")))) {
            {
                {
                    Value v_TheStmt = alg_subscript_get(v_Statements, v_I);
                    (void)v_TheStmt;
                    if (alg_truthy(alg_is(v_TheStmt, "ModuleStmt"))) {
                        {
                            if (alg_truthy(v_Define)) {
                                (void)(alg_invoke(v_this, "Execute", (Value[]){v_TheStmt}, 1));
                            }
                            if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Statements"), alg_nil()))) {
                                (void)(alg_invoke(v_this, "HoistTests", (Value[]){alg_property(v_TheStmt, "Statements"), v_Tests, v_ByName, alg_bool(false), alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_property(v_TheStmt, "FileName")}, 1), v_DeclaredIn, alg_str(alg_property(v_TheStmt, "FileName")), v_Files, v_ByFile}, 9));
                            }
                        }
                    } else {
                        if (alg_truthy(alg_is(v_TheStmt, "FunctionStmt"))) {
                            {
                                if (alg_truthy(v_Define)) {
                                    (void)(alg_invoke(v_this, "Execute", (Value[]){v_TheStmt}, 1));
                                }
                                if (alg_truthy(alg_not_equal(alg_property(alg_property(v_TheStmt, "Name"), "Literal"), alg_nil()))) {
                                    {
                                        (void)(alg_invoke(v_Tests, "Add", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")}, 1));
                                        (void)(alg_invoke(v_ByName, "Put", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), v_TheStmt}, 2));
                                        (void)(alg_invoke(v_DeclaredIn, "Put", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), v_Scope}, 2));
                                        if (alg_truthy(alg_not(alg_invoke(v_Files, "Contains", (Value[]){v_File}, 1)))) {
                                            {
                                                (void)(alg_invoke(v_Files, "Add", (Value[]){v_File}, 1));
                                                (void)(alg_invoke(v_ByFile, "Put", (Value[]){v_File, alg_list()}, 2));
                                            }
                                        }
                                        (void)(alg_invoke((alg_invoke(v_ByFile, "Get", (Value[]){v_File}, 1)), "Add", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")}, 1));
                                    }
                                }
                            }
                        } else {
                            if (alg_truthy((or_6 = v_Define, !alg_truthy(or_6) ? or_6 : ((or_5 = (or_4 = (or_3 = (or_2 = alg_is(v_TheStmt, "ClassStmt"), alg_truthy(or_2) ? or_2 : alg_is(v_TheStmt, "ObjectStmt")), alg_truthy(or_3) ? or_3 : alg_is(v_TheStmt, "EnumStmt")), alg_truthy(or_4) ? or_4 : alg_is(v_TheStmt, "VarGroupStmt")), alg_truthy(or_5) ? or_5 : alg_is(v_TheStmt, "VarStmt")))))) {
                                (void)(alg_invoke(v_this, "Execute", (Value[]){v_TheStmt}, 1));
                            }
                        }
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_RunTests_2_List_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_Statements = args[0];
    (void)v_Statements;
    volatile Value v_FileName = args[1];
    (void)v_FileName;
    volatile Value v_Tests = alg_nil();
    (void)v_Tests;
    volatile Value v_Passed = alg_nil();
    (void)v_Passed;
    volatile Value v_Failed = alg_nil();
    (void)v_Failed;
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("AssertTrue"), alg_new(k_AssertTrueNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("AssertEqual"), alg_new(k_AssertEqualNative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Fail"), alg_new(k_FailNative, NULL, 0)}, 2));
    (void)(f_SuppressOutput(NULL, (Value[]){alg_bool(true)}, 1));
    (void)((v_Tests = alg_list()));
    volatile Value v_ByName = alg_map();
    (void)v_ByName;
    volatile Value v_DeclaredIn = alg_map();
    (void)v_DeclaredIn;
    volatile Value v_Files = alg_list();
    (void)v_Files;
    volatile Value v_ByFile = alg_map();
    (void)v_ByFile;
    (void)(alg_invoke(v_this, "HoistTests", (Value[]){v_Statements, v_Tests, v_ByName, alg_bool(true), alg_property(v_this, "Globals"), v_DeclaredIn, v_FileName, v_Files, v_ByFile}, 9));
    (void)(alg_writeln(alg_add(alg_add(alg_string("[INFO] Running "), alg_str(alg_property(v_Tests, "Length"))), alg_string(" tests..."))));
    (void)((v_Passed = alg_int(0)));
    (void)((v_Failed = alg_int(0)));
    volatile Value v_Ordered = alg_list();
    (void)v_Ordered;
    {
        volatile Value v_F = alg_int(0);
        (void)v_F;
        while (alg_truthy(alg_less(v_F, alg_property(v_Files, "Length")))) {
            {
                {
                    volatile Value v_Group = alg_invoke(v_ByFile, "Get", (Value[]){alg_subscript_get(v_Files, v_F)}, 1);
                    (void)v_Group;
                    (void)(alg_invoke(v_Group, "Sort", NULL, 0));
                    (void)(alg_invoke(v_Ordered, "Add", (Value[]){alg_subscript_get(v_Files, v_F)}, 1));
                    {
                        volatile Value v_J = alg_int(0);
                        (void)v_J;
                        while (alg_truthy(alg_less(v_J, alg_property(v_Group, "Length")))) {
                            {
                                (void)(alg_invoke(v_Ordered, "Add", (Value[]){alg_subscript_get(v_Group, v_J)}, 1));
                                (void)((v_J = alg_add(v_J, alg_int(1))));
                            }
                        }
                    }
                }
                (void)((v_F = alg_add(v_F, alg_int(1))));
            }
        }
    }
    {
        volatile Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Ordered, "Length")))) {
            {
                {
                    if (alg_truthy(alg_not(alg_invoke(v_ByName, "Contains", (Value[]){alg_subscript_get(v_Ordered, v_I)}, 1)))) {
                        {
                            if (alg_truthy(alg_greater(v_I, alg_int(0)))) {
                                (void)(alg_writeln(alg_string("[INFO] ")));
                            }
                            (void)(alg_writeln(alg_add(alg_add(alg_string("[INFO] < "), alg_str(alg_subscript_get(v_Ordered, v_I))), alg_string(" >"))));
                        }
                    } else {
                        {
                            volatile Value v_TheTest = alg_invoke(v_ByName, "Get", (Value[]){alg_subscript_get(v_Ordered, v_I)}, 1);
                            (void)v_TheTest;
                            volatile Value v_Name = alg_str(alg_property(alg_property(v_TheTest, "Name"), "Literal"));
                            (void)v_Name;
                            {
                                AlgFrame frame_3;
                                alg_push_frame(&frame_3);
                                if (ALG_SETJMP(frame_3.jump) == 0) {
                                    {
                                        volatile Value v_Scope = alg_property(v_this, "Globals");
                                        (void)v_Scope;
                                        if (alg_truthy(alg_invoke(v_DeclaredIn, "Contains", (Value[]){alg_subscript_get(v_Ordered, v_I)}, 1))) {
                                            (void)((v_Scope = alg_invoke(v_DeclaredIn, "Get", (Value[]){alg_subscript_get(v_Ordered, v_I)}, 1)));
                                        }
                                        volatile Value v_Body = alg_invoke(v_Scope, "Get", (Value[]){alg_property(v_TheTest, "Name")}, 1);
                                        (void)v_Body;
                                        (void)(alg_invoke(v_Body, "Call", (Value[]){v_this, alg_list()}, 2));
                                        (void)((v_Passed = alg_add(v_Passed, alg_int(1))));
                                        (void)(alg_writeln(alg_invoke(v_this, "Report", (Value[]){v_Name, alg_string("PASS")}, 2)));
                                    }
                                    alg_pop_frame();
                                }
                                else {
                                    static const char *names_3[] = {"String", "Raised"};
                                    int32_t which_3 = alg_handler(frame_3.raised, names_3, 2);
                                    if (which_3 == 0) {
                                        {
                                            volatile Value v_e = frame_3.raised;
                                            (void)v_e;
                                            {
                                                (void)((v_Failed = alg_add(v_Failed, alg_int(1))));
                                                (void)(alg_writeln(alg_invoke(v_this, "Report", (Value[]){v_Name, alg_string("FAIL")}, 2)));
                                                (void)(alg_writeln(alg_add(alg_add(alg_add(alg_string("[ERROR] "), v_FileName), alg_string(": ")), v_e)));
                                            }
                                        }
                                    }
                                    else if (which_3 == 1) {
                                        {
                                            volatile Value v_e = frame_3.raised;
                                            (void)v_e;
                                            {
                                                (void)((v_Failed = alg_add(v_Failed, alg_int(1))));
                                                (void)(alg_writeln(alg_invoke(v_this, "Report", (Value[]){v_Name, alg_string("FAIL")}, 2)));
                                                (void)(alg_writeln(alg_add(alg_add(alg_add(alg_string("[ERROR] "), v_FileName), alg_string(": ")), alg_str(alg_property(v_e, "Value")))));
                                            }
                                        }
                                    }
                                    else {
                                        alg_raise(frame_3.raised);
                                    }
                                }
                            }
                        }
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_writeln(alg_string("[INFO] ")));
    if (alg_truthy(alg_equal(v_Failed, alg_int(0)))) {
        (void)(alg_writeln(alg_add(alg_add(alg_string("[INFO] All "), alg_str(v_Passed)), alg_string(" tests passed."))));
    } else {
        (void)(alg_writeln(alg_add(alg_add(alg_add(alg_add(alg_string("[INFO] "), alg_str(v_Failed)), alg_string(" of ")), alg_str(alg_add(v_Passed, v_Failed))), alg_string(" tests failed."))));
    }
    return v_Failed;
    return alg_nil();
}

static Value m_Interpreter_Report_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Status = args[1];
    (void)v_Status;
    Value v_Dots = alg_nil();
    (void)v_Dots;
    (void)((v_Dots = alg_subtract(alg_int(55), alg_length(v_Name))));
    if (alg_truthy(alg_less(v_Dots, alg_int(1)))) {
        (void)((v_Dots = alg_int(1)));
    }
    Value v_Leader = alg_string("");
    (void)v_Leader;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, v_Dots))) {
            {
                (void)((v_Leader = alg_add(v_Leader, alg_char_value(46))));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("[INFO] Test: "), v_Name), alg_char_value(32)), v_Leader), alg_string(" [ ")), v_Status), alg_string(" ]"));
    return alg_nil();
}

static Value m_Interpreter_VisitLiteral_1_LiteralExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    return alg_property(v_TheExpr, "Value");
    return alg_nil();
}

static Value m_Interpreter_VisitLogical_1_LogicalExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Left = alg_nil();
    (void)v_Left;
    (void)((v_Left = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Left")}, 1)));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_OR))) {
        {
            if (alg_truthy(alg_invoke(v_this, "IsTruthy", (Value[]){v_Left}, 1))) {
                return v_Left;
            }
        }
    } else {
        if (alg_truthy(alg_not(alg_invoke(v_this, "IsTruthy", (Value[]){v_Left}, 1)))) {
            return v_Left;
        }
    }
    return alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Right")}, 1);
    return alg_nil();
}

static Value m_Interpreter_VisitGrouping_1_GroupingExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    return alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Expression")}, 1);
    return alg_nil();
}

static Value m_Interpreter_VisitUnary_1_UnaryExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Right = alg_nil();
    (void)v_Right;
    (void)((v_Right = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Right")}, 1)));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_MINUS))) {
        return alg_negate(v_Right);
    } else {
        if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_NOT))) {
            return alg_not(alg_invoke(v_this, "IsTruthy", (Value[]){v_Right}, 1));
        }
    }
    return alg_nil();
}

static Value m_Interpreter_VisitCollectionExpr_1_CollectionExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Result = alg_nil();
    (void)v_Result;
    if (alg_truthy(alg_property(v_TheExpr, "IsMap"))) {
        {
            (void)((v_Result = alg_new(k_ObjCollection, (Value[]){alg_string("Map")}, 1)));
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Keys"), "Length")))) {
                    {
                        (void)(alg_invoke(alg_property(v_Result, "Pairs"), "Put", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Keys"), v_I)}, 1), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Values"), v_I)}, 1)}, 2));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return v_Result;
        }
    }
    (void)((v_Result = alg_new(k_ObjCollection, (Value[]){alg_string("List")}, 1)));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Values"), "Length")))) {
            {
                (void)(alg_invoke(alg_property(v_Result, "Items"), "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Values"), v_I)}, 1)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Result;
    return alg_nil();
}

static Value m_Interpreter_VisitSubscriptExpr_1_SubscriptExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Target = alg_nil();
    (void)v_Target;
    Value v_Index = alg_nil();
    (void)v_Index;
    (void)((v_Target = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Obj")}, 1)));
    (void)((v_Index = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Index")}, 1)));
    if (alg_truthy(alg_is(v_Target, "ObjCollection"))) {
        return alg_invoke(v_Target, "At", (Value[]){v_Index}, 1);
    }
    if (alg_truthy(alg_is(v_Target, "ObjBuffer"))) {
        return alg_invoke(v_Target, "At", (Value[]){v_Index}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "IsText", (Value[]){v_Target}, 1))) {
        return alg_subscript_get(alg_str(v_Target), v_Index);
    }
    alg_raise(alg_string("Subscript target should be an ordinal."));
    return alg_nil();
}

static Value m_Interpreter_VisitSetSubscriptExpr_1_SetSubscriptExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Target = alg_nil();
    (void)v_Target;
    Value v_Index = alg_nil();
    (void)v_Index;
    Value v_Value = alg_nil();
    (void)v_Value;
    (void)((v_Target = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Obj")}, 1)));
    (void)((v_Index = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Index")}, 1)));
    (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Value")}, 1)));
    if (alg_truthy(alg_is(v_Target, "ObjCollection"))) {
        return alg_invoke(v_Target, "PutAt", (Value[]){v_Index, v_Value}, 2);
    }
    if (alg_truthy(alg_is(v_Target, "ObjBuffer"))) {
        return alg_invoke(v_Target, "PutAt", (Value[]){v_Index, v_Value}, 2);
    }
    if (alg_truthy(alg_invoke(v_this, "IsText", (Value[]){v_Target}, 1))) {
        alg_raise(alg_string("Strings are immutable."));
    }
    alg_raise(alg_string("Subscript target should be an ordinal."));
    return alg_nil();
}

static Value m_Interpreter_IsText_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Obj = args[0];
    (void)v_Obj;
    return (or_7 = alg_is(v_Obj, "String"), alg_truthy(or_7) ? or_7 : alg_is(v_Obj, "Char"));
    return alg_nil();
}

static Value m_Interpreter_VisitIsExpr_1_IsExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Value = alg_nil();
    (void)v_Value;
    Value v_TheName = alg_nil();
    (void)v_TheName;
    (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Obj")}, 1)));
    if (alg_truthy(alg_equal(v_Value, alg_nil()))) {
        return alg_bool(false);
    }
    (void)((v_TheName = f_ToLower(NULL, (Value[]){alg_str(alg_property(alg_property(v_TheExpr, "TypeName"), "Lexeme"))}, 1)));
    if (alg_truthy(alg_equal(f_ToLower(NULL, (Value[]){f_TypeNameOf(NULL, (Value[]){v_Value}, 1)}, 1), v_TheName))) {
        return alg_bool(true);
    }
    return f_InheritsFrom(NULL, (Value[]){v_Value, alg_str(alg_property(alg_property(v_TheExpr, "TypeName"), "Lexeme"))}, 2);
    return alg_nil();
}

static Value m_Interpreter_VisitVariableExpr_1_VariableExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_TheExpr = args[0];
    (void)v_TheExpr;
    {
        AlgFrame frame_4;
        alg_push_frame(&frame_4);
        if (ALG_SETJMP(frame_4.jump) == 0) {
            {
                volatile Value ret_5 = alg_invoke(v_this, "LookupVariable", (Value[]){alg_property(v_TheExpr, "Name"), v_TheExpr}, 2);
                alg_pop_frame();
                return ret_5;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_4[] = {"String"};
            int32_t which_4 = alg_handler(frame_4.raised, names_4, 1);
            if (which_4 == 0) {
                {
                    volatile Value v_e = frame_4.raised;
                    (void)v_e;
                    return alg_invoke(v_this, "ThisField", (Value[]){alg_property(v_TheExpr, "Name"), v_e}, 2);
                }
            }
            else {
                alg_raise(frame_4.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_ThisField_2_Token_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_Name = args[0];
    (void)v_Name;
    volatile Value v_Original = args[1];
    (void)v_Original;
    volatile Value v_Obj = alg_nil();
    (void)v_Obj;
    {
        AlgFrame frame_6;
        alg_push_frame(&frame_6);
        if (ALG_SETJMP(frame_6.jump) == 0) {
            {
                (void)((v_Obj = alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_new(k_Token, (Value[]){e_TokenType_TOKEN_THIS, alg_string("this"), alg_nil(), alg_property(v_Name, "LineNumber")}, 4)}, 1)));
                volatile Value ret_7 = alg_invoke(v_Obj, "Get", (Value[]){v_Name}, 1);
                alg_pop_frame();
                return ret_7;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_6[] = {"String"};
            int32_t which_6 = alg_handler(frame_6.raised, names_6, 1);
            if (which_6 == 0) {
                {
                    volatile Value v_e = frame_6.raised;
                    (void)v_e;
                    alg_raise(v_Original);
                }
            }
            else {
                alg_raise(frame_6.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_SetThisField_3_Token_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_Name = args[0];
    (void)v_Name;
    volatile Value v_Value = args[1];
    (void)v_Value;
    volatile Value v_Original = args[2];
    (void)v_Original;
    volatile Value v_Obj = alg_nil();
    (void)v_Obj;
    {
        AlgFrame frame_8;
        alg_push_frame(&frame_8);
        if (ALG_SETJMP(frame_8.jump) == 0) {
            {
                (void)((v_Obj = alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_new(k_Token, (Value[]){e_TokenType_TOKEN_THIS, alg_string("this"), alg_nil(), alg_property(v_Name, "LineNumber")}, 4)}, 1)));
                (void)(alg_invoke(v_Obj, "Set", (Value[]){v_Name, v_Value}, 2));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_8[] = {"String"};
            int32_t which_8 = alg_handler(frame_8.raised, names_8, 1);
            if (which_8 == 0) {
                {
                    volatile Value v_e = frame_8.raised;
                    (void)v_e;
                    alg_raise(v_Original);
                }
            }
            else {
                alg_raise(frame_8.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_LookupVariable_2_Token_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_Name = args[0];
    (void)v_Name;
    volatile Value v_TheExpr = args[1];
    (void)v_TheExpr;
    volatile Value v_Distance = alg_nil();
    (void)v_Distance;
    (void)((v_Distance = alg_invoke(alg_property(v_this, "Locals"), "Get", (Value[]){v_TheExpr}, 1)));
    if (alg_truthy(alg_not_equal(v_Distance, alg_nil()))) {
        return alg_invoke(alg_property(v_this, "Env"), "GetAt", (Value[]){v_Distance, alg_property(v_Name, "Lexeme")}, 2);
    }
    {
        AlgFrame frame_9;
        alg_push_frame(&frame_9);
        if (ALG_SETJMP(frame_9.jump) == 0) {
            {
                volatile Value ret_10 = alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){v_Name}, 1);
                alg_pop_frame();
                return ret_10;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_9[] = {"String"};
            int32_t which_9 = alg_handler(frame_9.raised, names_9, 1);
            if (which_9 == 0) {
                {
                    volatile Value v_e = frame_9.raised;
                    (void)v_e;
                    return alg_invoke(alg_property(v_this, "Globals"), "Get", (Value[]){v_Name}, 1);
                }
            }
            else {
                alg_raise(frame_9.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_VisitBinary_1_BinaryExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Left = alg_nil();
    (void)v_Left;
    Value v_Right = alg_nil();
    (void)v_Right;
    (void)((v_Left = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Left")}, 1)));
    (void)((v_Right = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Right")}, 1)));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_GREATER))) {
        return alg_greater(v_Left, v_Right);
    } else {
        if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_GREATER_EQUAL))) {
            return alg_greater_equal(v_Left, v_Right);
        } else {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_LESS))) {
                return alg_less(v_Left, v_Right);
            } else {
                if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_LESS_EQUAL))) {
                    return alg_less_equal(v_Left, v_Right);
                } else {
                    if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_NOT_EQUAL))) {
                        return alg_not(alg_invoke(v_this, "IsEqual", (Value[]){v_Left, v_Right}, 2));
                    } else {
                        if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_EQUAL))) {
                            return alg_invoke(v_this, "IsEqual", (Value[]){v_Left, v_Right}, 2);
                        } else {
                            if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_IN))) {
                                return alg_invoke(v_this, "Contains", (Value[]){v_Right, v_Left}, 2);
                            } else {
                                if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_PLUS))) {
                                    return alg_add(v_Left, v_Right);
                                } else {
                                    if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_MINUS))) {
                                        return alg_subtract(v_Left, v_Right);
                                    } else {
                                        if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_SLASH))) {
                                            return alg_divide(v_Left, v_Right);
                                        } else {
                                            if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_STAR))) {
                                                return alg_multiply(v_Left, v_Right);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_VisitCall_1_CallExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Callee = alg_nil();
    (void)v_Callee;
    Value v_Arguments = alg_nil();
    (void)v_Arguments;
    (void)((v_Callee = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Callee")}, 1)));
    (void)((v_Arguments = alg_list()));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Arguments"), "Length")))) {
            {
                {
                    (void)(alg_invoke(v_Arguments, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Arguments"), v_I)}, 1)}, 1));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_not(alg_invoke(v_this, "IsCallable", (Value[]){v_Callee}, 1)))) {
        {
            alg_raise(alg_string("Can only call functions and classes."));
        }
    }
    if (alg_truthy(alg_is(v_Callee, "ObjFunction"))) {
        {
            if (alg_truthy(alg_not_equal(alg_property(v_Callee, "Owner"), alg_nil()))) {
                {
                    Value v_Better = alg_invoke(alg_property(v_Callee, "Owner"), "FindOverload", (Value[]){alg_property(alg_property(alg_property(v_Callee, "Declaration"), "Name"), "Lexeme"), v_Arguments}, 2);
                    (void)v_Better;
                    if (alg_truthy(alg_equal(v_Better, alg_nil()))) {
                        alg_raise(alg_string("No matching signature for function."));
                    }
                    (void)((v_Callee = alg_invoke(v_Better, "Bind", (Value[]){alg_property(v_Callee, "Bound")}, 1)));
                }
            }
        }
    }
    if (alg_truthy((or_8 = alg_greater_equal(alg_invoke(v_Callee, "Arity", NULL, 0), alg_int(0)), !alg_truthy(or_8) ? or_8 : alg_not_equal(alg_property(v_Arguments, "Length"), alg_invoke(v_Callee, "Arity", NULL, 0))))) {
        {
            alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Expected "), alg_invoke(v_Callee, "Arity", NULL, 0)), alg_string(" arguments but got ")), alg_property(v_Arguments, "Length")), alg_char_value(46)));
        }
    }
    return alg_invoke(v_Callee, "Call", (Value[]){v_this, v_Arguments}, 2);
    return alg_nil();
}

static Value m_Interpreter_AssignQualified_3_String_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Unit = args[0];
    (void)v_Unit;
    Value v_Name = args[1];
    (void)v_Name;
    Value v_Value = args[2];
    (void)v_Value;
    Value v_ModuleEnv = alg_nil();
    (void)v_ModuleEnv;
    if (alg_truthy(alg_equal(v_Unit, alg_string("System")))) {
        alg_raise(alg_add(alg_add(alg_string("Can't assign to '"), alg_str(alg_property(v_Name, "Lexeme"))), alg_string("' in unit 'System'.")));
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "UnitsByName"), "Contains", (Value[]){v_Unit}, 1)))) {
        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_Name, "Lexeme"))), alg_string("' in unit '")), v_Unit), alg_string("'.")));
    }
    (void)((v_ModuleEnv = alg_invoke(alg_property(v_this, "UnitsByName"), "Get", (Value[]){v_Unit}, 1)));
    if (alg_truthy((or_9 = alg_equal(alg_property(v_ModuleEnv, "Exports"), alg_nil()), alg_truthy(or_9) ? or_9 : alg_not(alg_invoke(alg_property(v_ModuleEnv, "Exports"), "Contains", (Value[]){alg_str(alg_property(v_Name, "Lexeme"))}, 1))))) {
        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_Name, "Lexeme"))), alg_string("' in unit '")), v_Unit), alg_string("'.")));
    }
    (void)(alg_invoke(alg_property(v_ModuleEnv, "Values"), "Put", (Value[]){alg_str(alg_property(v_Name, "Lexeme")), v_Value}, 2));
    return alg_nil();
}

static Value m_Interpreter_Qualified_2_String_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Unit = args[0];
    (void)v_Unit;
    Value v_Name = args[1];
    (void)v_Name;
    Value v_ModuleEnv = alg_nil();
    (void)v_ModuleEnv;
    if (alg_truthy(alg_equal(v_Unit, alg_string("System")))) {
        {
            if (alg_truthy(alg_not(alg_invoke(alg_property(alg_property(v_this, "Builtins"), "Values"), "Contains", (Value[]){alg_str(alg_property(v_Name, "Lexeme"))}, 1)))) {
                alg_raise(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_Name, "Lexeme"))), alg_string("' in unit 'System'.")));
            }
            return alg_invoke(alg_property(alg_property(v_this, "Builtins"), "Values"), "Get", (Value[]){alg_str(alg_property(v_Name, "Lexeme"))}, 1);
        }
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "UnitsByName"), "Contains", (Value[]){v_Unit}, 1)))) {
        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_Name, "Lexeme"))), alg_string("' in unit '")), v_Unit), alg_string("'.")));
    }
    (void)((v_ModuleEnv = alg_invoke(alg_property(v_this, "UnitsByName"), "Get", (Value[]){v_Unit}, 1)));
    if (alg_truthy((or_10 = alg_equal(alg_property(v_ModuleEnv, "Exports"), alg_nil()), alg_truthy(or_10) ? or_10 : alg_not(alg_invoke(alg_property(v_ModuleEnv, "Exports"), "Contains", (Value[]){alg_str(alg_property(v_Name, "Lexeme"))}, 1))))) {
        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_Name, "Lexeme"))), alg_string("' in unit '")), v_Unit), alg_string("'.")));
    }
    return alg_invoke(alg_property(v_ModuleEnv, "Values"), "Get", (Value[]){alg_str(alg_property(v_Name, "Lexeme"))}, 1);
    return alg_nil();
}

static Value m_Interpreter_VisitGetExpr_1_GetExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Obj = alg_nil();
    (void)v_Obj;
    if (alg_truthy(alg_not_equal(alg_property(v_TheExpr, "Unit"), alg_string("")))) {
        return alg_invoke(v_this, "Qualified", (Value[]){alg_property(v_TheExpr, "Unit"), alg_property(v_TheExpr, "Name")}, 2);
    }
    (void)((v_Obj = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Obj")}, 1)));
    if (alg_truthy(alg_not(((or_14 = (or_13 = (or_12 = (or_11 = alg_is(v_Obj, "ObjInstance"), alg_truthy(or_11) ? or_11 : alg_is(v_Obj, "ObjEnumType")), alg_truthy(or_12) ? or_12 : alg_is(v_Obj, "ObjCollection")), alg_truthy(or_13) ? or_13 : alg_is(v_Obj, "ObjFile")), alg_truthy(or_14) ? or_14 : alg_is(v_Obj, "ObjBuffer")))))) {
        {
            alg_raise(alg_string("Only instances have properties."));
        }
    }
    return alg_invoke(v_Obj, "Get", (Value[]){alg_property(v_TheExpr, "Name")}, 1);
    return alg_nil();
}

static Value m_Interpreter_VisitSetExpr_1_SetExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Obj = alg_nil();
    (void)v_Obj;
    Value v_Value = alg_nil();
    (void)v_Value;
    if (alg_truthy(alg_not_equal(alg_property(v_TheExpr, "Unit"), alg_string("")))) {
        {
            (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Value")}, 1)));
            (void)(alg_invoke(v_this, "AssignQualified", (Value[]){alg_str(alg_property(v_TheExpr, "Unit")), alg_property(v_TheExpr, "Name"), v_Value}, 3));
            return v_Value;
        }
    }
    (void)((v_Obj = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Obj")}, 1)));
    if (alg_truthy(alg_not((alg_is(v_Obj, "ObjInstance"))))) {
        {
            alg_raise(alg_string("Only instances have fields."));
        }
    }
    (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Value")}, 1)));
    (void)(alg_invoke(v_Obj, "Set", (Value[]){alg_property(v_TheExpr, "Name"), v_Value}, 2));
    return v_Value;
    return alg_nil();
}

static Value m_Interpreter_VisitSuperExpr_1_SuperExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Distance = alg_nil();
    (void)v_Distance;
    Value v_Superclass = alg_nil();
    (void)v_Superclass;
    Value v_Obj = alg_nil();
    (void)v_Obj;
    Value v_Method = alg_nil();
    (void)v_Method;
    (void)((v_Distance = alg_invoke(alg_property(v_this, "Locals"), "Get", (Value[]){v_TheExpr}, 1)));
    (void)((v_Superclass = alg_invoke(alg_property(v_this, "Env"), "GetAt", (Value[]){v_Distance, alg_string("super")}, 2)));
    (void)((v_Obj = alg_invoke(alg_property(v_this, "Env"), "GetAt", (Value[]){alg_subtract(v_Distance, alg_int(1)), alg_string("this")}, 2)));
    (void)((v_Method = alg_invoke(v_Superclass, "FindMethod", (Value[]){alg_property(alg_property(v_TheExpr, "Method"), "Lexeme")}, 1)));
    return alg_invoke(v_Method, "Bind", (Value[]){v_Obj}, 1);
    return alg_nil();
}

static Value m_Interpreter_VisitThisExpr_1_ThisExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    return alg_invoke(v_this, "LookupVariable", (Value[]){alg_property(v_TheExpr, "Keyword"), v_TheExpr}, 2);
    return alg_nil();
}

static Value m_Interpreter_ClassNameOf_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_Obj = args[0];
    (void)v_Obj;
    {
        AlgFrame frame_11;
        alg_push_frame(&frame_11);
        if (ALG_SETJMP(frame_11.jump) == 0) {
            {
                volatile Value ret_12 = alg_property(v_Obj, "ClassName");
                alg_pop_frame();
                return ret_12;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_11[] = {"String"};
            int32_t which_11 = alg_handler(frame_11.raised, names_11, 1);
            if (which_11 == 0) {
                {
                    volatile Value v_e = frame_11.raised;
                    (void)v_e;
                    return alg_string("");
                }
            }
            else {
                alg_raise(frame_11.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_IsTruthy_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Obj = args[0];
    (void)v_Obj;
    if (alg_truthy((or_15 = alg_equal(v_Obj, alg_nil()), alg_truthy(or_15) ? or_15 : alg_equal(v_Obj, alg_bool(false))))) {
        return alg_bool(false);
    }
    if (alg_truthy(alg_is(v_Obj, "Integer"))) {
        return alg_not_equal(v_Obj, alg_int(0));
    }
    if (alg_truthy(alg_is(v_Obj, "ObjEnum"))) {
        return alg_not_equal(alg_property(v_Obj, "Ordinal"), alg_int(0));
    }
    return alg_bool(true);
    return alg_nil();
}

static Value m_Interpreter_IsEqual_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_A = args[0];
    (void)v_A;
    Value v_B = args[1];
    (void)v_B;
    if (alg_truthy((or_16 = alg_equal(v_A, alg_nil()), !alg_truthy(or_16) ? or_16 : alg_equal(v_B, alg_nil())))) {
        return alg_bool(true);
    }
    if (alg_truthy(alg_equal(v_A, alg_nil()))) {
        return alg_bool(false);
    }
    return alg_equal(v_A, v_B);
    return alg_nil();
}

static Value m_Interpreter_Evaluate_1_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    return alg_invoke(v_TheExpr, "Accept", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value m_Interpreter_Execute_1_Stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    (void)(alg_invoke(v_TheStmt, "Accept", (Value[]){v_this}, 1));
    return alg_nil();
}

static Value m_Interpreter_Resolve_2_Expr_Integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Depth = args[1];
    (void)v_Depth;
    (void)(alg_invoke(alg_property(v_this, "Locals"), "Put", (Value[]){v_TheExpr, v_Depth}, 2));
    return alg_nil();
}

static Value m_Interpreter_ExecuteBlock_2_List_Environment(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_Statements = args[0];
    (void)v_Statements;
    volatile Value v_NewEnv = args[1];
    (void)v_NewEnv;
    volatile Value v_PreviousEnv = alg_nil();
    (void)v_PreviousEnv;
    (void)((v_PreviousEnv = alg_property(v_this, "Env")));
    {
        AlgFrame frame_13;
        alg_push_frame(&frame_13);
        if (ALG_SETJMP(frame_13.jump) == 0) {
            {
                (void)(alg_set_property(v_this, "Env", v_NewEnv));
                {
                    volatile Value v_I = alg_int(0);
                    (void)v_I;
                    while (alg_truthy(alg_less(v_I, alg_property(v_Statements, "Length")))) {
                        {
                            {
                                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(v_Statements, v_I)}, 1));
                            }
                            (void)((v_I = alg_add(v_I, alg_int(1))));
                        }
                    }
                }
            }
            alg_pop_frame();
        }
        else {
            {
                volatile Value v_e = frame_13.raised;
                (void)v_e;
                {
                    (void)(alg_set_property(v_this, "Env", v_PreviousEnv));
                    alg_raise(v_e);
                }
            }
        }
    }
    (void)(alg_set_property(v_this, "Env", v_PreviousEnv));
    return alg_nil();
}

static Value m_Interpreter_VisitBlockStmt_1_BlockStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_NewEnv = alg_new(k_Environment, NULL, 0);
    (void)v_NewEnv;
    (void)(alg_set_property(v_NewEnv, "Enclosing", alg_property(v_this, "Env")));
    (void)(alg_invoke(v_this, "ExecuteBlock", (Value[]){alg_property(v_TheStmt, "Statements"), v_NewEnv}, 2));
    return alg_nil();
}

static Value m_Interpreter_VisitClassStmt_1_ClassStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Klass = alg_nil();
    (void)v_Klass;
    Value v_Superclass = alg_nil();
    (void)v_Superclass;
    Value v_Methods = alg_nil();
    (void)v_Methods;
    Value v_TheFunction = alg_nil();
    (void)v_TheFunction;
    (void)((v_Superclass = alg_nil()));
    if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Superclass"), alg_nil()))) {
        {
            (void)((v_Superclass = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Superclass")}, 1)));
            if (alg_truthy(alg_not_equal(alg_property(v_Superclass, "ClassName"), alg_string("ObjClass")))) {
                {
                    alg_raise(alg_string("Superclass must be a class."));
                }
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_nil()}, 2));
    if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Superclass"), alg_nil()))) {
        {
            Value v_Previous = alg_property(v_this, "Env");
            (void)v_Previous;
            (void)(alg_set_property(v_this, "Env", alg_new(k_Environment, NULL, 0)));
            (void)(alg_set_property(alg_property(v_this, "Env"), "Enclosing", v_Previous));
            (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_string("super"), v_Superclass}, 2));
        }
    }
    (void)((v_Methods = alg_map()));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Methods"), "Length")))) {
            {
                {
                    Value v_Method = alg_subscript_get(alg_property(v_TheStmt, "Methods"), v_I);
                    (void)v_Method;
                    (void)((v_TheFunction = alg_new(k_ObjFunction, (Value[]){v_Method, alg_property(v_this, "Env"), alg_equal(alg_property(alg_property(v_Method, "Name"), "Lexeme"), alg_string("Init"))}, 3)));
                    if (alg_truthy(alg_not(alg_invoke(v_Methods, "Contains", (Value[]){alg_property(alg_property(v_Method, "Name"), "Lexeme")}, 1)))) {
                        (void)(alg_invoke(v_Methods, "Put", (Value[]){alg_property(alg_property(v_Method, "Name"), "Lexeme"), alg_list()}, 2));
                    }
                    (void)(alg_invoke(alg_invoke(v_Methods, "Get", (Value[]){alg_property(alg_property(v_Method, "Name"), "Lexeme")}, 1), "Add", (Value[]){v_TheFunction}, 1));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)((v_Klass = alg_new(k_ObjClass, (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), v_Superclass, v_Methods, alg_property(v_TheStmt, "Fields")}, 4)));
    {
        Value loop_14 = alg_iterable(alg_invoke(v_Methods, "Keys", NULL, 0));
        for (int32_t at_14 = 0; at_14 < alg_iterable_count(loop_14); at_14++) {
            Value v_Name = alg_iterable_at(loop_14, at_14);
            (void)v_Name;
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_invoke(v_Methods, "Get", (Value[]){v_Name}, 1), "Length")))) {
                    {
                        (void)(alg_set_property(alg_subscript_get(alg_invoke(v_Methods, "Get", (Value[]){v_Name}, 1), v_I), "Owner", v_Klass));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
        }
    }
    if (alg_truthy(alg_not_equal(v_Superclass, alg_nil()))) {
        {
            (void)(alg_set_property(v_this, "Env", alg_property(alg_property(v_this, "Env"), "Enclosing")));
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Assign", (Value[]){alg_property(v_TheStmt, "Name"), v_Klass}, 2));
    return alg_nil();
}

static Value m_Interpreter_VisitObjectStmt_1_ObjectStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Klass = alg_nil();
    (void)v_Klass;
    Value v_HasId = alg_bool(false);
    (void)v_HasId;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Fields"), "Length")))) {
            {
                if (alg_truthy(alg_equal(alg_property(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Fields"), v_I), "Name"), "Lexeme"), alg_string("Id")))) {
                    (void)((v_HasId = alg_bool(true)));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_not(v_HasId))) {
        {
            Value v_IdName = alg_new(k_Token, (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Id"), alg_nil(), alg_property(alg_property(v_TheStmt, "Name"), "LineNumber")}, 4);
            (void)v_IdName;
            (void)(alg_invoke(alg_property(v_TheStmt, "Fields"), "Add", (Value[]){alg_new(k_VarStmt, (Value[]){v_IdName, alg_new(k_LiteralExpr, (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1)}, 2)}, 1));
        }
    }
    (void)(alg_invoke(v_this, "VisitClassStmt", (Value[]){alg_new(k_ClassStmt, (Value[]){alg_property(v_TheStmt, "Name"), alg_property(v_TheStmt, "Superclass"), alg_property(v_TheStmt, "Methods"), alg_property(v_TheStmt, "Fields")}, 4)}, 1));
    (void)((v_Klass = alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_property(v_TheStmt, "Name")}, 1)));
    (void)(alg_invoke(alg_property(v_this, "Env"), "Assign", (Value[]){alg_property(v_TheStmt, "Name"), alg_new(k_ObjSingleton, (Value[]){v_Klass, v_this}, 2)}, 2));
    return alg_nil();
}

static Value m_Interpreter_VisitEnumStmt_1_EnumStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_TheType = alg_nil();
    (void)v_TheType;
    (void)((v_TheType = alg_new(k_ObjEnumType, (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")}, 1)));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Members"), "Length")))) {
            {
                {
                    Value v_MemberName = alg_property(alg_subscript_get(alg_property(v_TheStmt, "Members"), v_I), "Lexeme");
                    (void)v_MemberName;
                    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){v_MemberName, alg_invoke(v_TheType, "Add", (Value[]){v_MemberName}, 1)}, 2));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), v_TheType}, 2));
    return alg_nil();
}

static Value m_Interpreter_VisitExpressionStmt_1_ExpressionStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    (void)(alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_Stmt, "Expression")}, 1));
    return alg_nil();
}

static Value m_Interpreter_VisitFunctionStmt_1_FunctionStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_TheFunction = alg_nil();
    (void)v_TheFunction;
    (void)((v_TheFunction = alg_new(k_ObjFunction, (Value[]){v_TheStmt, alg_property(v_this, "Env"), alg_bool(false)}, 3)));
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), v_TheFunction}, 2));
    return alg_nil();
}

static Value m_Interpreter_VisitIfStmt_1_IfStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    if (alg_truthy(alg_invoke(v_this, "IsTruthy", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_Stmt, "Condition")}, 1)}, 1))) {
        (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_Stmt, "ThenBranch")}, 1));
    } else {
        if (alg_truthy(alg_not_equal(alg_property(v_Stmt, "ElseBranch"), alg_nil()))) {
            (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_Stmt, "ElseBranch")}, 1));
        }
    }
    return alg_nil();
}

static Value m_Interpreter_VisitWhileStmt_1_WhileStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_Stmt = args[0];
    (void)v_Stmt;
    {
        AlgFrame frame_15;
        alg_push_frame(&frame_15);
        if (ALG_SETJMP(frame_15.jump) == 0) {
            {
                while (alg_truthy(alg_invoke(v_this, "IsTruthy", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_Stmt, "Condition")}, 1)}, 1))) {
                    {
                        (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_Stmt, "Body")}, 1));
                    }
                }
            }
            alg_pop_frame();
        }
        else {
            static const char *names_15[] = {"Broke"};
            int32_t which_15 = alg_handler(frame_15.raised, names_15, 1);
            if (which_15 == 0) {
                {
                    volatile Value v_e = frame_15.raised;
                    (void)v_e;
                    return alg_nil();
                }
            }
            else {
                alg_raise(frame_15.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_Contains_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Collection = args[0];
    (void)v_Collection;
    Value v_Value = args[1];
    (void)v_Value;
    if (alg_truthy(alg_is(v_Collection, "ObjCollection"))) {
        return alg_invoke(v_Collection, "Invoke", (Value[]){alg_string("Contains"), alg_list_keep(alg_list(), v_Value)}, 2);
    }
    if (alg_truthy(alg_is(v_Collection, "ObjEnumType"))) {
        return alg_invoke(alg_invoke(alg_property(v_Collection, "Members"), "Values", NULL, 0), "Contains", (Value[]){v_Value}, 1);
    }
    if (alg_truthy(alg_is(v_Collection, "ObjInstance"))) {
        {
            Value v_Method = alg_invoke(alg_property(v_Collection, "Klass"), "FindMethod", (Value[]){alg_string("Contains")}, 1);
            (void)v_Method;
            if (alg_truthy(alg_not_equal(v_Method, alg_nil()))) {
                return alg_invoke(v_this, "IsTruthy", (Value[]){alg_invoke(alg_invoke(v_Method, "Bind", (Value[]){v_Collection}, 1), "Call", (Value[]){v_this, alg_list_keep(alg_list(), v_Value)}, 2)}, 1);
            }
        }
    }
    if (alg_truthy(alg_invoke(v_this, "IsText", (Value[]){v_Collection}, 1))) {
        {
            if (alg_truthy(alg_equal(v_Value, alg_nil()))) {
                return alg_bool(false);
            }
            return alg_greater_equal(alg_pos(alg_str(v_Collection), alg_str(v_Value)), alg_int(0));
        }
    }
    alg_raise(alg_string("Right operand of 'in' must be a collection or a String."));
    return alg_nil();
}

static Value m_Interpreter_IsCallable_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_Value = args[0];
    (void)v_Value;
    if (alg_truthy(alg_equal(v_Value, alg_nil()))) {
        return alg_bool(false);
    }
    {
        AlgFrame frame_16;
        alg_push_frame(&frame_16);
        if (ALG_SETJMP(frame_16.jump) == 0) {
            {
                volatile Value v_TheArity = alg_property(v_Value, "Arity");
                (void)v_TheArity;
                volatile Value ret_17 = alg_bool(true);
                alg_pop_frame();
                return ret_17;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_16[] = {"String"};
            int32_t which_16 = alg_handler(frame_16.raised, names_16, 1);
            if (which_16 == 0) {
                {
                    volatile Value v_e = frame_16.raised;
                    (void)v_e;
                    return alg_bool(false);
                }
            }
            else {
                alg_raise(frame_16.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_ElementsOf_2_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Where = args[0];
    (void)v_Where;
    Value v_Target = args[1];
    (void)v_Target;
    Value v_Result = alg_nil();
    (void)v_Result;
    (void)((v_Result = alg_list()));
    if (alg_truthy(alg_is(v_Target, "ObjCollection"))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_Target, "Kind"), alg_string("Map")))) {
                return alg_invoke(alg_property(v_Target, "Pairs"), "Keys", NULL, 0);
            }
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_Target, "Items"), "Length")))) {
                    {
                        (void)(alg_invoke(v_Result, "Add", (Value[]){alg_subscript_get(alg_property(v_Target, "Items"), v_I)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return v_Result;
        }
    }
    if (alg_truthy(alg_is(v_Target, "ObjEnumType"))) {
        return alg_invoke(alg_property(v_Target, "Members"), "Values", NULL, 0);
    }
    if (alg_truthy(alg_is(v_Target, "ObjInstance"))) {
        {
            Value v_Elements = alg_invoke(alg_property(v_Target, "Klass"), "FindMethod", (Value[]){alg_string("Elements")}, 1);
            (void)v_Elements;
            if (alg_truthy(alg_not_equal(v_Elements, alg_nil()))) {
                return alg_invoke(v_this, "ElementsOf", (Value[]){v_Where, alg_invoke(alg_invoke(v_Elements, "Bind", (Value[]){v_Target}, 1), "Call", (Value[]){v_this, alg_list()}, 2)}, 2);
            }
        }
    }
    if (alg_truthy(alg_invoke(v_this, "IsText", (Value[]){v_Target}, 1))) {
        {
            Value v_Text = alg_str(v_Target);
            (void)v_Text;
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_length(v_Text)))) {
                    {
                        (void)(alg_invoke(v_Result, "Add", (Value[]){alg_subscript_get(v_Text, v_I)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return v_Result;
        }
    }
    alg_raise(alg_string("Can only iterate a collection or a String."));
    return alg_nil();
}

static Value m_Interpreter_VisitForInStmt_1_ForInStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_TheStmt = args[0];
    (void)v_TheStmt;
    volatile Value v_Elements = alg_nil();
    (void)v_Elements;
    (void)((v_Elements = alg_invoke(v_this, "ElementsOf", (Value[]){alg_property(v_TheStmt, "Name"), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Iterable")}, 1)}, 2)));
    {
        AlgFrame frame_18;
        alg_push_frame(&frame_18);
        if (ALG_SETJMP(frame_18.jump) == 0) {
            {
                {
                    volatile Value v_I = alg_int(0);
                    (void)v_I;
                    while (alg_truthy(alg_less(v_I, alg_property(v_Elements, "Length")))) {
                        {
                            {
                                volatile Value v_Scope = alg_new(k_Environment, NULL, 0);
                                (void)v_Scope;
                                (void)(alg_set_property(v_Scope, "Enclosing", alg_property(v_this, "Env")));
                                (void)(alg_invoke(v_Scope, "Define", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_subscript_get(v_Elements, v_I)}, 2));
                                (void)(alg_invoke(v_this, "ExecuteBlock", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "Body")), v_Scope}, 2));
                            }
                            (void)((v_I = alg_add(v_I, alg_int(1))));
                        }
                    }
                }
            }
            alg_pop_frame();
        }
        else {
            static const char *names_18[] = {"Broke"};
            int32_t which_18 = alg_handler(frame_18.raised, names_18, 1);
            if (which_18 == 0) {
                {
                    volatile Value v_e = frame_18.raised;
                    (void)v_e;
                    return alg_nil();
                }
            }
            else {
                alg_raise(frame_18.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_VisitBreakStmt_1_BreakStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    alg_raise(alg_new(k_Broke, NULL, 0));
    return alg_nil();
}

static Value m_Interpreter_VisitModuleStmt_1_ModuleStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Importer = alg_nil();
    (void)v_Importer;
    Value v_ModuleEnv = alg_nil();
    (void)v_ModuleEnv;
    Value v_Exported = alg_nil();
    (void)v_Exported;
    (void)((v_Importer = alg_property(v_this, "Env")));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Modules"), "Contains", (Value[]){alg_property(v_TheStmt, "FileName")}, 1))) {
        {
            (void)(alg_invoke(alg_property(v_Importer, "Imports"), "Add", (Value[]){alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_property(v_TheStmt, "FileName")}, 1)}, 1));
            (void)(alg_invoke(alg_property(v_this, "UnitsByName"), "Put", (Value[]){alg_str(alg_property(v_TheStmt, "UnitName")), alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_property(v_TheStmt, "FileName")}, 1)}, 2));
            return alg_nil();
        }
    }
    (void)((v_ModuleEnv = alg_new(k_Environment, NULL, 0)));
    (void)(alg_set_property(v_ModuleEnv, "Enclosing", alg_property(v_this, "Builtins")));
    (void)(alg_invoke(alg_property(v_this, "Modules"), "Put", (Value[]){alg_property(v_TheStmt, "FileName"), v_ModuleEnv}, 2));
    (void)(alg_invoke(v_this, "ExecuteBlock", (Value[]){alg_property(v_TheStmt, "Statements"), v_ModuleEnv}, 2));
    (void)((v_Exported = alg_list()));
    Value v_Names = alg_invoke(alg_property(v_ModuleEnv, "Values"), "Keys", NULL, 0);
    (void)v_Names;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Names, "Length")))) {
            {
                {
                    Value v_TheName = alg_subscript_get(v_Names, v_I);
                    (void)v_TheName;
                    if (alg_truthy(alg_not(alg_invoke(alg_property(v_TheStmt, "PrivateNames"), "Contains", (Value[]){v_TheName}, 1)))) {
                        {
                            (void)(alg_invoke(v_Exported, "Add", (Value[]){v_TheName}, 1));
                            if (alg_truthy(alg_not_equal(alg_invoke(v_Importer, "OwnerOf", (Value[]){v_TheName}, 1), alg_nil()))) {
                                {
                                    Value v_Existing = alg_invoke(alg_property((alg_invoke(v_Importer, "OwnerOf", (Value[]){v_TheName}, 1)), "Values"), "Get", (Value[]){v_TheName}, 1);
                                    (void)v_Existing;
                                    Value v_Incoming = alg_invoke(alg_property(v_ModuleEnv, "Values"), "Get", (Value[]){v_TheName}, 1);
                                    (void)v_Incoming;
                                    if (alg_truthy(alg_not(((or_17 = alg_is(v_Existing, "ObjFunction"), !alg_truthy(or_17) ? or_17 : alg_is(v_Incoming, "ObjFunction")))))) {
                                        alg_raise(alg_add(alg_add(alg_string("'"), v_TheName), alg_string("' is already defined; mark it private in one of the modules.")));
                                    }
                                }
                            }
                        }
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_set_property(v_ModuleEnv, "Exports", alg_set()));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Exported, "Length")))) {
            {
                (void)(alg_invoke(alg_property(v_ModuleEnv, "Exports"), "Add", (Value[]){alg_subscript_get(v_Exported, v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_Importer, "Imports"), "Add", (Value[]){v_ModuleEnv}, 1));
    (void)(alg_invoke(alg_property(v_this, "UnitsByName"), "Put", (Value[]){alg_str(alg_property(v_TheStmt, "UnitName")), v_ModuleEnv}, 2));
    return alg_nil();
}

static Value m_Interpreter_VisitRaiseStmt_1_RaiseStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    alg_raise(alg_new(k_Raised, (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Value")}, 1)}, 1));
    return alg_nil();
}

static Value m_Interpreter_FindHandler_2_Map(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Handlers = args[0];
    (void)v_Handlers;
    Value v_Value = args[1];
    (void)v_Value;
    Value v_Klass = alg_nil();
    (void)v_Klass;
    if (alg_truthy(alg_is(v_Value, "ObjInstance"))) {
        {
            (void)((v_Klass = alg_property(v_Value, "Klass")));
            while (alg_truthy(alg_not_equal(v_Klass, alg_nil()))) {
                {
                    Value v_TheName = alg_str(alg_property(v_Klass, "Name"));
                    (void)v_TheName;
                    if (alg_truthy(alg_invoke(v_Handlers, "Contains", (Value[]){v_TheName}, 1))) {
                        return alg_invoke(v_Handlers, "Get", (Value[]){v_TheName}, 1);
                    }
                    (void)((v_Klass = alg_property(v_Klass, "Superclass")));
                }
            }
            return alg_nil();
        }
    }
    Value v_TypeName = f_TypeNameOf(NULL, (Value[]){v_Value}, 1);
    (void)v_TypeName;
    if (alg_truthy(alg_invoke(v_Handlers, "Contains", (Value[]){v_TypeName}, 1))) {
        return alg_invoke(v_Handlers, "Get", (Value[]){v_TypeName}, 1);
    }
    return alg_nil();
    return alg_nil();
}

static Value m_Interpreter_Handle_3_TryStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Value = args[1];
    (void)v_Value;
    Value v_Original = args[2];
    (void)v_Original;
    Value v_Handler = alg_nil();
    (void)v_Handler;
    (void)((v_Handler = alg_invoke(v_this, "FindHandler", (Value[]){alg_property(v_TheStmt, "Handlers"), v_Value}, 2)));
    if (alg_truthy((or_18 = alg_equal(v_Handler, alg_nil()), !alg_truthy(or_18) ? or_18 : alg_invoke(alg_property(v_TheStmt, "Handlers"), "Contains", (Value[]){alg_string("default")}, 1)))) {
        (void)((v_Handler = alg_invoke(alg_property(v_TheStmt, "Handlers"), "Get", (Value[]){alg_string("default")}, 1)));
    }
    if (alg_truthy(alg_equal(v_Handler, alg_nil()))) {
        alg_raise(v_Original);
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(v_Handler, "Name"), v_Value}, 2));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_Handler, "Body")}, 1));
    return alg_nil();
}

static Value m_Interpreter_VisitTryStmt_1_TryStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_TheStmt = args[0];
    (void)v_TheStmt;
    {
        AlgFrame frame_19;
        alg_push_frame(&frame_19);
        if (ALG_SETJMP(frame_19.jump) == 0) {
            {
                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_TheStmt, "TryBlock")}, 1));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_19[] = {"Return", "Raised", "String"};
            int32_t which_19 = alg_handler(frame_19.raised, names_19, 3);
            if (which_19 == 0) {
                {
                    volatile Value v_e = frame_19.raised;
                    (void)v_e;
                    alg_raise(v_e);
                }
            }
            else if (which_19 == 1) {
                {
                    volatile Value v_e = frame_19.raised;
                    (void)v_e;
                    (void)(alg_invoke(v_this, "Handle", (Value[]){v_TheStmt, alg_property(v_e, "Value"), v_e}, 3));
                }
            }
            else if (which_19 == 2) {
                {
                    volatile Value v_e = frame_19.raised;
                    (void)v_e;
                    (void)(alg_invoke(v_this, "Handle", (Value[]){v_TheStmt, v_e, v_e}, 3));
                }
            }
            else {
                alg_raise(frame_19.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_VisitPrintStmt_1_PrintStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    Value v_Value = alg_nil();
    (void)v_Value;
    (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_Stmt, "Expression")}, 1)));
    (void)(alg_writeln(f_Stringify(NULL, (Value[]){v_this, v_Value}, 2)));
    return alg_nil();
}

static Value m_Interpreter_VisitReturnStmt_1_ReturnStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    Value v_Value = alg_nil();
    (void)v_Value;
    if (alg_truthy(alg_not_equal(alg_property(v_Stmt, "Value"), alg_nil()))) {
        (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_Stmt, "Value")}, 1)));
    }
    alg_raise(alg_new(k_Return, (Value[]){v_Value}, 1));
    return alg_nil();
}

static Value m_Interpreter_VisitVarStmt_1_VarStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    Value v_Value = alg_nil();
    (void)v_Value;
    if (alg_truthy(alg_not_equal(alg_property(v_Stmt, "Initializer"), alg_nil()))) {
        {
            (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_Stmt, "Initializer")}, 1)));
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_Stmt, "Name"), "Lexeme"), v_Value}, 2));
    return alg_nil();
}

static Value m_Interpreter_VisitVarGroupStmt_1_VarGroupStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Value = alg_nil();
    (void)v_Value;
    if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Initializer"), alg_nil()))) {
        (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Initializer")}, 1)));
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Names"), "Length")))) {
            {
                (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_I), "Lexeme"), v_Value}, 2));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_Interpreter_VisitAssignExpr_1_AssignExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_Expr = args[0];
    (void)v_Expr;
    volatile Value v_Value = alg_nil();
    (void)v_Value;
    volatile Value v_Distance = alg_nil();
    (void)v_Distance;
    (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_Expr, "Value")}, 1)));
    (void)((v_Distance = alg_invoke(alg_property(v_this, "Locals"), "Get", (Value[]){v_Expr}, 1)));
    if (alg_truthy(alg_not_equal(v_Distance, alg_nil()))) {
        {
            {
                AlgFrame frame_20;
                alg_push_frame(&frame_20);
                if (ALG_SETJMP(frame_20.jump) == 0) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Env"), "AssignAt", (Value[]){v_Distance, alg_property(v_Expr, "Name"), v_Value}, 3));
                    }
                    alg_pop_frame();
                }
                else {
                    static const char *names_20[] = {"String"};
                    int32_t which_20 = alg_handler(frame_20.raised, names_20, 1);
                    if (which_20 == 0) {
                        {
                            volatile Value v_e = frame_20.raised;
                            (void)v_e;
                            (void)(alg_invoke(v_this, "SetThisField", (Value[]){alg_property(v_Expr, "Name"), v_Value, v_e}, 3));
                        }
                    }
                    else {
                        alg_raise(frame_20.raised);
                    }
                }
            }
        }
    } else {
        {
            {
                AlgFrame frame_21;
                alg_push_frame(&frame_21);
                if (ALG_SETJMP(frame_21.jump) == 0) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Env"), "Assign", (Value[]){alg_property(v_Expr, "Name"), v_Value}, 2));
                    }
                    alg_pop_frame();
                }
                else {
                    static const char *names_21[] = {"String"};
                    int32_t which_21 = alg_handler(frame_21.raised, names_21, 1);
                    if (which_21 == 0) {
                        {
                            volatile Value v_e = frame_21.raised;
                            (void)v_e;
                            (void)(alg_invoke(v_this, "SetThisField", (Value[]){alg_property(v_Expr, "Name"), v_Value, v_e}, 3));
                        }
                    }
                    else {
                        alg_raise(frame_21.raised);
                    }
                }
            }
        }
    }
    return v_Value;
    return alg_nil();
}

static Value i_Broke(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value i_Raised(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Value", alg_nil());
    return alg_nil();
}

static Value m_Raised_Init_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Value = args[0];
    (void)v_Value;
    (void)(alg_set_property(v_this, "Value", v_Value));
    return alg_nil();
}

static Value i_Return(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Value", alg_nil());
    return alg_nil();
}

static Value m_Return_Init_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Value = args[0];
    (void)v_Value;
    (void)(alg_set_property(v_this, "Value", v_Value));
    return alg_nil();
}

void init_Interpreter(void) {
    k_ClockNative = alg_class("ClockNative", alg_nil());
    alg_class_initializer(k_ClockNative, i_ClockNative);
    alg_class_method(k_ClockNative, "Arity", m_ClockNative_Arity_0, 0, NULL);
    alg_class_method(k_ClockNative, "Call", m_ClockNative_Call_2, 2, t_ClockNative_Call_2);
    k_LengthNative = alg_class("LengthNative", alg_nil());
    alg_class_initializer(k_LengthNative, i_LengthNative);
    alg_class_method(k_LengthNative, "Arity", m_LengthNative_Arity_0, 0, NULL);
    alg_class_method(k_LengthNative, "Call", m_LengthNative_Call_2, 2, t_LengthNative_Call_2);
    k_CopyNative = alg_class("CopyNative", alg_nil());
    alg_class_initializer(k_CopyNative, i_CopyNative);
    alg_class_method(k_CopyNative, "Arity", m_CopyNative_Arity_0, 0, NULL);
    alg_class_method(k_CopyNative, "Call", m_CopyNative_Call_2, 2, t_CopyNative_Call_2);
    k_PosNative = alg_class("PosNative", alg_nil());
    alg_class_initializer(k_PosNative, i_PosNative);
    alg_class_method(k_PosNative, "Arity", m_PosNative_Arity_0, 0, NULL);
    alg_class_method(k_PosNative, "Call", m_PosNative_Call_2, 2, t_PosNative_Call_2);
    k_ArrayNative = alg_class("ArrayNative", alg_nil());
    alg_class_initializer(k_ArrayNative, i_ArrayNative);
    alg_class_method(k_ArrayNative, "Arity", m_ArrayNative_Arity_0, 0, NULL);
    alg_class_method(k_ArrayNative, "Call", m_ArrayNative_Call_2, 2, t_ArrayNative_Call_2);
    k_ListNative = alg_class("ListNative", alg_nil());
    alg_class_initializer(k_ListNative, i_ListNative);
    alg_class_method(k_ListNative, "Arity", m_ListNative_Arity_0, 0, NULL);
    alg_class_method(k_ListNative, "Call", m_ListNative_Call_2, 2, t_ListNative_Call_2);
    k_MapNative = alg_class("MapNative", alg_nil());
    alg_class_initializer(k_MapNative, i_MapNative);
    alg_class_method(k_MapNative, "Arity", m_MapNative_Arity_0, 0, NULL);
    alg_class_method(k_MapNative, "Call", m_MapNative_Call_2, 2, t_MapNative_Call_2);
    k_SetNative = alg_class("SetNative", alg_nil());
    alg_class_initializer(k_SetNative, i_SetNative);
    alg_class_method(k_SetNative, "Arity", m_SetNative_Arity_0, 0, NULL);
    alg_class_method(k_SetNative, "Call", m_SetNative_Call_2, 2, t_SetNative_Call_2);
    k_StackNative = alg_class("StackNative", alg_nil());
    alg_class_initializer(k_StackNative, i_StackNative);
    alg_class_method(k_StackNative, "Arity", m_StackNative_Arity_0, 0, NULL);
    alg_class_method(k_StackNative, "Call", m_StackNative_Call_2, 2, t_StackNative_Call_2);
    fn_SetProgramArguments = alg_closure("SetProgramArguments", f_SetProgramArguments, NULL, 0, 1);
    fn_SuppressOutput = alg_closure("SuppressOutput", f_SuppressOutput, NULL, 0, 1);
    k_WriteNative = alg_class("WriteNative", alg_nil());
    alg_class_initializer(k_WriteNative, i_WriteNative);
    alg_class_method(k_WriteNative, "Arity", m_WriteNative_Arity_0, 0, NULL);
    alg_class_method(k_WriteNative, "Call", m_WriteNative_Call_2, 2, t_WriteNative_Call_2);
    k_WriteLnNative = alg_class("WriteLnNative", alg_nil());
    alg_class_initializer(k_WriteLnNative, i_WriteLnNative);
    alg_class_method(k_WriteLnNative, "Arity", m_WriteLnNative_Arity_0, 0, NULL);
    alg_class_method(k_WriteLnNative, "Call", m_WriteLnNative_Call_2, 2, t_WriteLnNative_Call_2);
    k_OrdNative = alg_class("OrdNative", alg_nil());
    alg_class_initializer(k_OrdNative, i_OrdNative);
    alg_class_method(k_OrdNative, "Arity", m_OrdNative_Arity_0, 0, NULL);
    alg_class_method(k_OrdNative, "Call", m_OrdNative_Call_2, 2, t_OrdNative_Call_2);
    k_ValNative = alg_class("ValNative", alg_nil());
    alg_class_initializer(k_ValNative, i_ValNative);
    alg_class_method(k_ValNative, "Arity", m_ValNative_Arity_0, 0, NULL);
    alg_class_method(k_ValNative, "Call", m_ValNative_Call_2, 2, t_ValNative_Call_2);
    k_CharNative = alg_class("CharNative", alg_nil());
    alg_class_initializer(k_CharNative, i_CharNative);
    alg_class_method(k_CharNative, "Arity", m_CharNative_Arity_0, 0, NULL);
    alg_class_method(k_CharNative, "Call", m_CharNative_Call_2, 2, t_CharNative_Call_2);
    k_MaxNative = alg_class("MaxNative", alg_nil());
    alg_class_initializer(k_MaxNative, i_MaxNative);
    alg_class_method(k_MaxNative, "Arity", m_MaxNative_Arity_0, 0, NULL);
    alg_class_method(k_MaxNative, "Call", m_MaxNative_Call_2, 2, t_MaxNative_Call_2);
    k_ModNative = alg_class("ModNative", alg_nil());
    alg_class_initializer(k_ModNative, i_ModNative);
    alg_class_method(k_ModNative, "Arity", m_ModNative_Arity_0, 0, NULL);
    alg_class_method(k_ModNative, "Call", m_ModNative_Call_2, 2, t_ModNative_Call_2);
    k_TextFileNative = alg_class("TextFileNative", alg_nil());
    alg_class_initializer(k_TextFileNative, i_TextFileNative);
    alg_class_method(k_TextFileNative, "Arity", m_TextFileNative_Arity_0, 0, NULL);
    alg_class_method(k_TextFileNative, "Call", m_TextFileNative_Call_2, 2, t_TextFileNative_Call_2);
    k_BufferNative = alg_class("BufferNative", alg_nil());
    alg_class_initializer(k_BufferNative, i_BufferNative);
    alg_class_method(k_BufferNative, "Arity", m_BufferNative_Arity_0, 0, NULL);
    alg_class_method(k_BufferNative, "Call", m_BufferNative_Call_2, 2, t_BufferNative_Call_2);
    k_FileExistsNative = alg_class("FileExistsNative", alg_nil());
    alg_class_initializer(k_FileExistsNative, i_FileExistsNative);
    alg_class_method(k_FileExistsNative, "Arity", m_FileExistsNative_Arity_0, 0, NULL);
    alg_class_method(k_FileExistsNative, "Call", m_FileExistsNative_Call_2, 2, t_FileExistsNative_Call_2);
    k_ParamCountNative = alg_class("ParamCountNative", alg_nil());
    alg_class_initializer(k_ParamCountNative, i_ParamCountNative);
    alg_class_method(k_ParamCountNative, "Arity", m_ParamCountNative_Arity_0, 0, NULL);
    alg_class_method(k_ParamCountNative, "Call", m_ParamCountNative_Call_2, 2, t_ParamCountNative_Call_2);
    k_ParamStrNative = alg_class("ParamStrNative", alg_nil());
    alg_class_initializer(k_ParamStrNative, i_ParamStrNative);
    alg_class_method(k_ParamStrNative, "Arity", m_ParamStrNative_Arity_0, 0, NULL);
    alg_class_method(k_ParamStrNative, "Call", m_ParamStrNative_Call_2, 2, t_ParamStrNative_Call_2);
    fn_Stringify = alg_closure("Stringify", f_Stringify, NULL, 0, 2);
    k_StrNative = alg_class("StrNative", alg_nil());
    alg_class_initializer(k_StrNative, i_StrNative);
    alg_class_method(k_StrNative, "Arity", m_StrNative_Arity_0, 0, NULL);
    alg_class_method(k_StrNative, "Call", m_StrNative_Call_2, 2, t_StrNative_Call_2);
    k_AssertTrueNative = alg_class("AssertTrueNative", alg_nil());
    alg_class_initializer(k_AssertTrueNative, i_AssertTrueNative);
    alg_class_method(k_AssertTrueNative, "Arity", m_AssertTrueNative_Arity_0, 0, NULL);
    alg_class_method(k_AssertTrueNative, "Call", m_AssertTrueNative_Call_2, 2, t_AssertTrueNative_Call_2);
    k_AssertEqualNative = alg_class("AssertEqualNative", alg_nil());
    alg_class_initializer(k_AssertEqualNative, i_AssertEqualNative);
    alg_class_method(k_AssertEqualNative, "Arity", m_AssertEqualNative_Arity_0, 0, NULL);
    alg_class_method(k_AssertEqualNative, "Call", m_AssertEqualNative_Call_2, 2, t_AssertEqualNative_Call_2);
    k_FailNative = alg_class("FailNative", alg_nil());
    alg_class_initializer(k_FailNative, i_FailNative);
    alg_class_method(k_FailNative, "Arity", m_FailNative_Arity_0, 0, NULL);
    alg_class_method(k_FailNative, "Call", m_FailNative_Call_2, 2, t_FailNative_Call_2);
    k_Interpreter = alg_class("Interpreter", alg_nil());
    alg_class_field(k_Interpreter, "Env");
    alg_class_field(k_Interpreter, "Builtins");
    alg_class_field(k_Interpreter, "Globals");
    alg_class_field(k_Interpreter, "Locals");
    alg_class_field(k_Interpreter, "Modules");
    alg_class_field(k_Interpreter, "UnitsByName");
    alg_class_initializer(k_Interpreter, i_Interpreter);
    alg_class_method(k_Interpreter, "Init", m_Interpreter_Init_0, 0, NULL);
    alg_class_method(k_Interpreter, "Interpret", m_Interpreter_Interpret_1_List, 1, t_Interpreter_Interpret_1_List);
    alg_class_method(k_Interpreter, "HoistTests", m_Interpreter_HoistTests_9_List_List_Map_Boolean_Environment_Map_String_List_Map, 9, t_Interpreter_HoistTests_9_List_List_Map_Boolean_Environment_Map_String_List_Map);
    alg_class_method(k_Interpreter, "RunTests", m_Interpreter_RunTests_2_List_String, 2, t_Interpreter_RunTests_2_List_String);
    alg_class_method(k_Interpreter, "Report", m_Interpreter_Report_2_String_String, 2, t_Interpreter_Report_2_String_String);
    alg_class_method(k_Interpreter, "VisitLiteral", m_Interpreter_VisitLiteral_1_LiteralExpr, 1, t_Interpreter_VisitLiteral_1_LiteralExpr);
    alg_class_method(k_Interpreter, "VisitLogical", m_Interpreter_VisitLogical_1_LogicalExpr, 1, t_Interpreter_VisitLogical_1_LogicalExpr);
    alg_class_method(k_Interpreter, "VisitGrouping", m_Interpreter_VisitGrouping_1_GroupingExpr, 1, t_Interpreter_VisitGrouping_1_GroupingExpr);
    alg_class_method(k_Interpreter, "VisitUnary", m_Interpreter_VisitUnary_1_UnaryExpr, 1, t_Interpreter_VisitUnary_1_UnaryExpr);
    alg_class_method(k_Interpreter, "VisitCollectionExpr", m_Interpreter_VisitCollectionExpr_1_CollectionExpr, 1, t_Interpreter_VisitCollectionExpr_1_CollectionExpr);
    alg_class_method(k_Interpreter, "VisitSubscriptExpr", m_Interpreter_VisitSubscriptExpr_1_SubscriptExpr, 1, t_Interpreter_VisitSubscriptExpr_1_SubscriptExpr);
    alg_class_method(k_Interpreter, "VisitSetSubscriptExpr", m_Interpreter_VisitSetSubscriptExpr_1_SetSubscriptExpr, 1, t_Interpreter_VisitSetSubscriptExpr_1_SetSubscriptExpr);
    alg_class_method(k_Interpreter, "IsText", m_Interpreter_IsText_1, 1, t_Interpreter_IsText_1);
    alg_class_method(k_Interpreter, "VisitIsExpr", m_Interpreter_VisitIsExpr_1_IsExpr, 1, t_Interpreter_VisitIsExpr_1_IsExpr);
    alg_class_method(k_Interpreter, "VisitVariableExpr", m_Interpreter_VisitVariableExpr_1_VariableExpr, 1, t_Interpreter_VisitVariableExpr_1_VariableExpr);
    alg_class_method(k_Interpreter, "ThisField", m_Interpreter_ThisField_2_Token_String, 2, t_Interpreter_ThisField_2_Token_String);
    alg_class_method(k_Interpreter, "SetThisField", m_Interpreter_SetThisField_3_Token_String, 3, t_Interpreter_SetThisField_3_Token_String);
    alg_class_method(k_Interpreter, "LookupVariable", m_Interpreter_LookupVariable_2_Token_Expr, 2, t_Interpreter_LookupVariable_2_Token_Expr);
    alg_class_method(k_Interpreter, "VisitBinary", m_Interpreter_VisitBinary_1_BinaryExpr, 1, t_Interpreter_VisitBinary_1_BinaryExpr);
    alg_class_method(k_Interpreter, "VisitCall", m_Interpreter_VisitCall_1_CallExpr, 1, t_Interpreter_VisitCall_1_CallExpr);
    alg_class_method(k_Interpreter, "AssignQualified", m_Interpreter_AssignQualified_3_String_Token, 3, t_Interpreter_AssignQualified_3_String_Token);
    alg_class_method(k_Interpreter, "Qualified", m_Interpreter_Qualified_2_String_Token, 2, t_Interpreter_Qualified_2_String_Token);
    alg_class_method(k_Interpreter, "VisitGetExpr", m_Interpreter_VisitGetExpr_1_GetExpr, 1, t_Interpreter_VisitGetExpr_1_GetExpr);
    alg_class_method(k_Interpreter, "VisitSetExpr", m_Interpreter_VisitSetExpr_1_SetExpr, 1, t_Interpreter_VisitSetExpr_1_SetExpr);
    alg_class_method(k_Interpreter, "VisitSuperExpr", m_Interpreter_VisitSuperExpr_1_SuperExpr, 1, t_Interpreter_VisitSuperExpr_1_SuperExpr);
    alg_class_method(k_Interpreter, "VisitThisExpr", m_Interpreter_VisitThisExpr_1_ThisExpr, 1, t_Interpreter_VisitThisExpr_1_ThisExpr);
    alg_class_method(k_Interpreter, "ClassNameOf", m_Interpreter_ClassNameOf_1, 1, t_Interpreter_ClassNameOf_1);
    alg_class_method(k_Interpreter, "IsTruthy", m_Interpreter_IsTruthy_1, 1, t_Interpreter_IsTruthy_1);
    alg_class_method(k_Interpreter, "IsEqual", m_Interpreter_IsEqual_2, 2, t_Interpreter_IsEqual_2);
    alg_class_method(k_Interpreter, "Evaluate", m_Interpreter_Evaluate_1_Expr, 1, t_Interpreter_Evaluate_1_Expr);
    alg_class_method(k_Interpreter, "Execute", m_Interpreter_Execute_1_Stmt, 1, t_Interpreter_Execute_1_Stmt);
    alg_class_method(k_Interpreter, "Resolve", m_Interpreter_Resolve_2_Expr_Integer, 2, t_Interpreter_Resolve_2_Expr_Integer);
    alg_class_method(k_Interpreter, "ExecuteBlock", m_Interpreter_ExecuteBlock_2_List_Environment, 2, t_Interpreter_ExecuteBlock_2_List_Environment);
    alg_class_method(k_Interpreter, "VisitBlockStmt", m_Interpreter_VisitBlockStmt_1_BlockStmt, 1, t_Interpreter_VisitBlockStmt_1_BlockStmt);
    alg_class_method(k_Interpreter, "VisitClassStmt", m_Interpreter_VisitClassStmt_1_ClassStmt, 1, t_Interpreter_VisitClassStmt_1_ClassStmt);
    alg_class_method(k_Interpreter, "VisitObjectStmt", m_Interpreter_VisitObjectStmt_1_ObjectStmt, 1, t_Interpreter_VisitObjectStmt_1_ObjectStmt);
    alg_class_method(k_Interpreter, "VisitEnumStmt", m_Interpreter_VisitEnumStmt_1_EnumStmt, 1, t_Interpreter_VisitEnumStmt_1_EnumStmt);
    alg_class_method(k_Interpreter, "VisitExpressionStmt", m_Interpreter_VisitExpressionStmt_1_ExpressionStmt, 1, t_Interpreter_VisitExpressionStmt_1_ExpressionStmt);
    alg_class_method(k_Interpreter, "VisitFunctionStmt", m_Interpreter_VisitFunctionStmt_1_FunctionStmt, 1, t_Interpreter_VisitFunctionStmt_1_FunctionStmt);
    alg_class_method(k_Interpreter, "VisitIfStmt", m_Interpreter_VisitIfStmt_1_IfStmt, 1, t_Interpreter_VisitIfStmt_1_IfStmt);
    alg_class_method(k_Interpreter, "VisitWhileStmt", m_Interpreter_VisitWhileStmt_1_WhileStmt, 1, t_Interpreter_VisitWhileStmt_1_WhileStmt);
    alg_class_method(k_Interpreter, "Contains", m_Interpreter_Contains_2, 2, t_Interpreter_Contains_2);
    alg_class_method(k_Interpreter, "IsCallable", m_Interpreter_IsCallable_1, 1, t_Interpreter_IsCallable_1);
    alg_class_method(k_Interpreter, "ElementsOf", m_Interpreter_ElementsOf_2_Token, 2, t_Interpreter_ElementsOf_2_Token);
    alg_class_method(k_Interpreter, "VisitForInStmt", m_Interpreter_VisitForInStmt_1_ForInStmt, 1, t_Interpreter_VisitForInStmt_1_ForInStmt);
    alg_class_method(k_Interpreter, "VisitBreakStmt", m_Interpreter_VisitBreakStmt_1_BreakStmt, 1, t_Interpreter_VisitBreakStmt_1_BreakStmt);
    alg_class_method(k_Interpreter, "VisitModuleStmt", m_Interpreter_VisitModuleStmt_1_ModuleStmt, 1, t_Interpreter_VisitModuleStmt_1_ModuleStmt);
    alg_class_method(k_Interpreter, "VisitRaiseStmt", m_Interpreter_VisitRaiseStmt_1_RaiseStmt, 1, t_Interpreter_VisitRaiseStmt_1_RaiseStmt);
    alg_class_method(k_Interpreter, "FindHandler", m_Interpreter_FindHandler_2_Map, 2, t_Interpreter_FindHandler_2_Map);
    alg_class_method(k_Interpreter, "Handle", m_Interpreter_Handle_3_TryStmt, 3, t_Interpreter_Handle_3_TryStmt);
    alg_class_method(k_Interpreter, "VisitTryStmt", m_Interpreter_VisitTryStmt_1_TryStmt, 1, t_Interpreter_VisitTryStmt_1_TryStmt);
    alg_class_method(k_Interpreter, "VisitPrintStmt", m_Interpreter_VisitPrintStmt_1_PrintStmt, 1, t_Interpreter_VisitPrintStmt_1_PrintStmt);
    alg_class_method(k_Interpreter, "VisitReturnStmt", m_Interpreter_VisitReturnStmt_1_ReturnStmt, 1, t_Interpreter_VisitReturnStmt_1_ReturnStmt);
    alg_class_method(k_Interpreter, "VisitVarStmt", m_Interpreter_VisitVarStmt_1_VarStmt, 1, t_Interpreter_VisitVarStmt_1_VarStmt);
    alg_class_method(k_Interpreter, "VisitVarGroupStmt", m_Interpreter_VisitVarGroupStmt_1_VarGroupStmt, 1, t_Interpreter_VisitVarGroupStmt_1_VarGroupStmt);
    alg_class_method(k_Interpreter, "VisitAssignExpr", m_Interpreter_VisitAssignExpr_1_AssignExpr, 1, t_Interpreter_VisitAssignExpr_1_AssignExpr);
    k_Broke = alg_class("Broke", alg_nil());
    alg_class_initializer(k_Broke, i_Broke);
    k_Raised = alg_class("Raised", alg_nil());
    alg_class_field(k_Raised, "Value");
    alg_class_initializer(k_Raised, i_Raised);
    alg_class_method(k_Raised, "Init", m_Raised_Init_1, 1, t_Raised_Init_1);
    k_Return = alg_class("Return", alg_nil());
    alg_class_field(k_Return, "Value");
    alg_class_initializer(k_Return, i_Return);
    alg_class_method(k_Return, "Init", m_Return_Init_1, 1, t_Return_Init_1);
    v_ProgramArguments = alg_list();
    v_OutputSuppressed = alg_bool(false);
}
