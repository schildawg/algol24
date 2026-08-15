/* Generated from Algol-24.  Do not edit. */
#include "CEmitter.h"
#include "Expr.h"
#include "ObjFunction.h"
#include "Stmt.h"
#include "TokenType.h"

Value f_Indentation(Value **cells, Value *args, int32_t count);
Value f_QuoteC(Value **cells, Value *args, int32_t count);
Value fn_Indentation;
Value fn_QuoteC;
Value k_EmitUnit;
static const char *t_EmitUnit_Init_5_String_List_List_List_String[] = { "String", "List", "List", "List", "String" };
Value k_CEmitter;
static Value or_0;
static Value or_1;
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
static Value or_19;
static Value or_20;
static Value or_21;
static Value or_22;
static Value or_23;
static Value or_24;
static Value or_25;
static Value or_26;
static Value or_27;
static Value or_28;
static Value or_29;
static Value or_30;
static Value or_31;
static Value or_32;
static Value or_33;
static Value or_34;
static Value or_35;
static Value or_36;
static Value or_37;
static Value or_38;
static Value or_39;
static Value or_40;
static Value or_41;
static Value or_42;
static Value or_43;
static Value or_44;
static Value or_45;
static Value or_46;
static Value or_47;
static Value or_48;
static Value or_49;
static Value or_50;
static const char *t_CEmitter_Unsupported_1[] = { "Any" };
static const char *t_CEmitter_Line_1[] = { "Any" };
static const char *t_CEmitter_Mangle_2_String_String[] = { "String", "String" };
static const char *t_CEmitter_SymbolOf_2_String_String[] = { "String", "String" };
static const char *t_CEmitter_ClassHandle_1_String[] = { "String" };
static const char *t_CEmitter_InitName_1_String[] = { "String" };
static const char *t_CEmitter_EnumTypeName_1_String[] = { "String" };
static const char *t_CEmitter_EnumMemberName_2_String_String[] = { "String", "String" };
static const char *t_CEmitter_QuestionsOut_1_String[] = { "String" };
static const char *t_CEmitter_IsLetterOrDigit_1_Char[] = { "Char" };
static const char *t_CEmitter_Sanitize_1_String[] = { "String" };
static const char *t_CEmitter_CollectUnits_5_List_String_List_List_String[] = { "List", "String", "List", "List", "String" };
static const char *t_CEmitter_UnitNameOf_1_String[] = { "String" };
static const char *t_CEmitter_VariableName_1_String[] = { "String" };
static const char *t_CEmitter_FunctionName_1_String[] = { "String" };
static const char *t_CEmitter_HandleName_1_String[] = { "String" };
static const char *t_CEmitter_Prototype_1[] = { "Any" };
static const char *t_CEmitter_Exported_1_String[] = { "String" };
static const char *t_CEmitter_DeclareValue_2_String_String[] = { "String", "String" };
static const char *t_CEmitter_IsTest_1[] = { "Any" };
static const char *t_CEmitter_CollectFunctions_1_List[] = { "List" };
static const char *t_CEmitter_CollectGlobals_1_List[] = { "List" };
static const char *t_CEmitter_CompilingFile_1_String[] = { "String" };
static const char *t_CEmitter_Emit_2_List_String[] = { "List", "String" };
static const char *t_CEmitter_UnitHeader_1[] = { "Any" };
static const char *t_CEmitter_UnitSource_4_List_Boolean_String[] = { "Any", "List", "Boolean", "String" };
static const char *t_CEmitter_Upper_1_String[] = { "String" };
static const char *t_CEmitter_TextLess_2_String_String[] = { "String", "String" };
static const char *t_CEmitter_Execute_1[] = { "Any" };
static const char *t_CEmitter_Evaluate_1[] = { "Any" };
static const char *t_CEmitter_EmitTest_1[] = { "Any" };
static const char *t_CEmitter_RefuseBareBinding_1[] = { "Any" };
static const char *t_CEmitter_DeclaresNested_1_List[] = { "List" };
static const char *t_CEmitter_AddOnce_2_List_String[] = { "List", "String" };
static const char *t_CEmitter_CollectBindings_2_List_List[] = { "List", "List" };
static const char *t_CEmitter_BoundNames_1[] = { "Any" };
static const char *t_CEmitter_BoxesFor_1_List[] = { "List" };
static const char *t_CEmitter_Cell_1_String[] = { "String" };
static const char *t_CEmitter_Read_1_String[] = { "String" };
static const char *t_CEmitter_ClosureOf_2_List[] = { "Any", "List" };
static const char *t_CEmitter_ContainsTry_1_List[] = { "List" };
static const char *t_CEmitter_RequireCell_1_String[] = { "String" };
static const char *t_CEmitter_CloseScope_1_List[] = { "List" };
static const char *t_CEmitter_DeclareCell_2_String_String[] = { "String", "String" };
static const char *t_CEmitter_HoistCells_1_List[] = { "List" };
static const char *t_CEmitter_EmitHandlerBody_2_String[] = { "Any", "String" };
static const char *t_CEmitter_DeclaredTypes_1[] = { "Any" };
static const char *t_CEmitter_MethodSymbol_2_String[] = { "String", "Any" };
static const char *t_CEmitter_NamesVisible_3_String_List_Boolean[] = { "String", "List", "Boolean" };
static const char *t_CEmitter_EmitMethod_2_String[] = { "String", "Any" };
static const char *t_CEmitter_EmitClass_5_String_List_List_Boolean[] = { "String", "Any", "List", "List", "Boolean" };
static const char *t_CEmitter_VisitVarStmt_1_VarStmt[] = { "VarStmt" };
static const char *t_CEmitter_VisitExpressionStmt_1_ExpressionStmt[] = { "ExpressionStmt" };
static const char *t_CEmitter_VisitBlockStmt_1_BlockStmt[] = { "BlockStmt" };
static const char *t_CEmitter_VisitIfStmt_1_IfStmt[] = { "IfStmt" };
static const char *t_CEmitter_VisitWhileStmt_1_WhileStmt[] = { "WhileStmt" };
static const char *t_CEmitter_VisitPrintStmt_1_PrintStmt[] = { "PrintStmt" };
static const char *t_CEmitter_VisitReturnStmt_1_ReturnStmt[] = { "ReturnStmt" };
static const char *t_CEmitter_VisitFunctionStmt_1_FunctionStmt[] = { "FunctionStmt" };
static const char *t_CEmitter_VisitLiteral_1_LiteralExpr[] = { "LiteralExpr" };
static const char *t_CEmitter_VisitVariableExpr_1_VariableExpr[] = { "VariableExpr" };
static const char *t_CEmitter_Unreachable_1_String[] = { "String" };
static const char *t_CEmitter_VisitAssignExpr_1_AssignExpr[] = { "AssignExpr" };
static const char *t_CEmitter_VisitGrouping_1_GroupingExpr[] = { "GroupingExpr" };
static const char *t_CEmitter_VisitIsExpr_1_IsExpr[] = { "IsExpr" };
static const char *t_CEmitter_VisitUnary_1_UnaryExpr[] = { "UnaryExpr" };
static const char *t_CEmitter_VisitBinary_1_BinaryExpr[] = { "BinaryExpr" };
static const char *t_CEmitter_Builtin_2_String_Integer[] = { "String", "Integer" };
static const char *t_CEmitter_ArgumentArray_1_List[] = { "List" };
static const char *t_CEmitter_ConstructorFor_3_String_List_String[] = { "String", "List", "String" };
static const char *t_CEmitter_UnitCall_4_String_String_List_String[] = { "String", "String", "List", "String" };
static const char *t_CEmitter_VisitCall_1_CallExpr[] = { "CallExpr" };
static const char *t_CEmitter_VisitLogical_1_LogicalExpr[] = { "LogicalExpr" };
static const char *t_CEmitter_VisitCollectionExpr_1_CollectionExpr[] = { "CollectionExpr" };
static const char *t_CEmitter_VisitSubscriptExpr_1_SubscriptExpr[] = { "SubscriptExpr" };
static const char *t_CEmitter_VisitSetSubscriptExpr_1_SetSubscriptExpr[] = { "SetSubscriptExpr" };
static const char *t_CEmitter_UnitValue_2_String_String[] = { "String", "String" };
static const char *t_CEmitter_VisitGetExpr_1_GetExpr[] = { "GetExpr" };
static const char *t_CEmitter_VisitSetExpr_1_SetExpr[] = { "SetExpr" };
static const char *t_CEmitter_VisitSuperExpr_1_SuperExpr[] = { "SuperExpr" };
static const char *t_CEmitter_VisitThisExpr_1_ThisExpr[] = { "ThisExpr" };
static const char *t_CEmitter_VisitClassStmt_1_ClassStmt[] = { "ClassStmt" };
static const char *t_CEmitter_VisitObjectStmt_1_ObjectStmt[] = { "ObjectStmt" };
static const char *t_CEmitter_VisitEnumStmt_1_EnumStmt[] = { "EnumStmt" };
static const char *t_CEmitter_VisitTryStmt_1_TryStmt[] = { "TryStmt" };
static const char *t_CEmitter_VisitRaiseStmt_1_RaiseStmt[] = { "RaiseStmt" };
static const char *t_CEmitter_VisitForInStmt_1_ForInStmt[] = { "ForInStmt" };
static const char *t_CEmitter_VisitBreakStmt_1_BreakStmt[] = { "BreakStmt" };
static const char *t_CEmitter_VisitVarGroupStmt_1_VarGroupStmt[] = { "VarGroupStmt" };
static const char *t_CEmitter_VisitModuleStmt_1_ModuleStmt[] = { "ModuleStmt" };

Value f_Indentation(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Depth = args[0];
    (void)v_Depth;
    Value v_Result = alg_string("");
    (void)v_Result;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, v_Depth))) {
            {
                (void)((v_Result = alg_add(v_Result, alg_string("    "))));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Result;
    return alg_nil();
}

Value f_QuoteC(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Text = args[0];
    (void)v_Text;
    Value v_Result = alg_nil();
    (void)v_Result;
    (void)((v_Result = alg_str(alg_char_value(34))));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_length(v_Text)))) {
            {
                {
                    Value v_C = alg_subscript_get(alg_str(v_Text), v_I);
                    (void)v_C;
                    if (alg_truthy(alg_equal(v_C, alg_char_value(34)))) {
                        (void)((v_Result = alg_add(v_Result, alg_string("\\\""))));
                    } else {
                        if (alg_truthy(alg_equal(v_C, alg_char_value(92)))) {
                            (void)((v_Result = alg_add(v_Result, alg_string("\\\\"))));
                        } else {
                            if (alg_truthy(alg_equal(v_C, alg_char_value(10)))) {
                                (void)((v_Result = alg_add(v_Result, alg_string("\\n"))));
                            } else {
                                if (alg_truthy(alg_equal(v_C, alg_char_value(9)))) {
                                    (void)((v_Result = alg_add(v_Result, alg_string("\\t"))));
                                } else {
                                    if (alg_truthy(alg_equal(v_C, alg_char_value(13)))) {
                                        (void)((v_Result = alg_add(v_Result, alg_string("\\r"))));
                                    } else {
                                        (void)((v_Result = alg_add(v_Result, alg_str(v_C))));
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
    return alg_add(v_Result, alg_str(alg_char_value(34)));
    return alg_nil();
}

static Value i_EmitUnit(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Statements", alg_nil());
    alg_set_property(v_this, "Imports", alg_nil());
    alg_set_property(v_this, "PrivateNames", alg_nil());
    alg_set_property(v_this, "FileName", alg_nil());
    return alg_nil();
}

static Value m_EmitUnit_Init_5_String_List_List_List_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Statements = args[1];
    (void)v_Statements;
    Value v_Imports = args[2];
    (void)v_Imports;
    Value v_PrivateNames = args[3];
    (void)v_PrivateNames;
    Value v_FileName = args[4];
    (void)v_FileName;
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Statements", v_Statements));
    (void)(alg_set_property(v_this, "Imports", v_Imports));
    (void)(alg_set_property(v_this, "PrivateNames", v_PrivateNames));
    (void)(alg_set_property(v_this, "FileName", v_FileName));
    return alg_nil();
}

static Value i_CEmitter(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Declarations", alg_buffer(alg_int(0)));
    alg_set_property(v_this, "Functions", alg_buffer(alg_int(0)));
    alg_set_property(v_this, "MainBody", alg_buffer(alg_int(0)));
    alg_set_property(v_this, "Setup", alg_buffer(alg_int(0)));
    alg_set_property(v_this, "Body", alg_buffer(alg_int(0)));
    alg_set_property(v_this, "TestSymbols", alg_nil());
    alg_set_property(v_this, "Header", alg_string(""));
    alg_set_property(v_this, "UnitName", alg_string("Main"));
    alg_set_property(v_this, "PrivateNames", alg_nil());
    alg_set_property(v_this, "RootUnit", alg_bool(false));
    alg_set_property(v_this, "UnitTests", alg_int(0));
    alg_set_property(v_this, "Target", alg_string("main"));
    alg_set_property(v_this, "Depth", alg_int(1));
    alg_set_property(v_this, "AtTopLevel", alg_bool(false));
    alg_set_property(v_this, "Locals", alg_nil());
    alg_set_property(v_this, "Declared", alg_nil());
    alg_set_property(v_this, "Logicals", alg_int(0));
    alg_set_property(v_this, "Loops", alg_int(0));
    alg_set_property(v_this, "TryDepth", alg_int(0));
    alg_set_property(v_this, "LoopTryDepth", alg_int(0));
    alg_set_property(v_this, "Volatiles", alg_bool(false));
    alg_set_property(v_this, "Renames", alg_nil());
    alg_set_property(v_this, "Boxed", alg_nil());
    alg_set_property(v_this, "Cells", alg_nil());
    alg_set_property(v_this, "Captured", alg_nil());
    alg_set_property(v_this, "Globals", alg_nil());
    alg_set_property(v_this, "TopLevel", alg_nil());
    alg_set_property(v_this, "UnitExports", alg_nil());
    alg_set_property(v_this, "UnitAll", alg_nil());
    alg_set_property(v_this, "ShadowNames", alg_nil());
    alg_set_property(v_this, "InsideNested", alg_bool(false));
    alg_set_property(v_this, "EmitTests", alg_bool(false));
    alg_set_property(v_this, "Tests", alg_nil());
    alg_set_property(v_this, "TestFiles", alg_nil());
    alg_set_property(v_this, "CurrentFile", alg_string(""));
    alg_set_property(v_this, "SourceFile", alg_string(""));
    alg_set_property(v_this, "Classes", alg_nil());
    alg_set_property(v_this, "Objects", alg_nil());
    alg_set_property(v_this, "EnumTypes", alg_nil());
    alg_set_property(v_this, "EnumMembers", alg_nil());
    alg_set_property(v_this, "CurrentClass", alg_string(""));
    alg_set_property(v_this, "VisibleFields", alg_nil());
    alg_set_property(v_this, "VisibleMethods", alg_nil());
    return alg_nil();
}

static Value m_CEmitter_Init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_set_property(v_this, "Locals", alg_list()));
    (void)(alg_set_property(v_this, "Declared", alg_set()));
    (void)(alg_set_property(v_this, "Classes", alg_map()));
    (void)(alg_set_property(v_this, "Objects", alg_set()));
    (void)(alg_set_property(v_this, "EnumTypes", alg_set()));
    (void)(alg_set_property(v_this, "EnumMembers", alg_map()));
    (void)(alg_set_property(v_this, "VisibleFields", alg_set()));
    (void)(alg_set_property(v_this, "VisibleMethods", alg_set()));
    (void)(alg_set_property(v_this, "Renames", alg_map()));
    (void)(alg_set_property(v_this, "Boxed", alg_list()));
    (void)(alg_set_property(v_this, "Cells", alg_list()));
    (void)(alg_set_property(v_this, "Captured", alg_map()));
    (void)(alg_set_property(v_this, "Globals", alg_set()));
    (void)(alg_set_property(v_this, "TopLevel", alg_set()));
    (void)(alg_set_property(v_this, "UnitExports", alg_map()));
    (void)(alg_set_property(v_this, "UnitAll", alg_map()));
    (void)(alg_set_property(v_this, "ShadowNames", alg_set()));
    (void)(alg_set_property(v_this, "Tests", alg_list()));
    (void)(alg_set_property(v_this, "TestFiles", alg_list()));
    (void)(alg_set_property(v_this, "TestSymbols", alg_list()));
    (void)(alg_set_property(v_this, "PrivateNames", alg_list()));
    return alg_nil();
}

static Value m_CEmitter_Unsupported_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Construct = args[0];
    (void)v_Construct;
    alg_raise(alg_add(alg_str(v_Construct), alg_string(" is not supported by the C back end yet.")));
    return alg_nil();
}

static Value m_CEmitter_Line_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Text = args[0];
    (void)v_Text;
    if (alg_truthy(alg_equal(alg_property(v_this, "Target"), alg_string("body")))) {
        (void)(alg_invoke(alg_property(v_this, "Body"), "Append", (Value[]){alg_add(alg_add(f_Indentation(NULL, (Value[]){alg_property(v_this, "Depth")}, 1), alg_str(v_Text)), alg_char_value(10))}, 1));
    } else {
        (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_add(f_Indentation(NULL, (Value[]){alg_property(v_this, "Depth")}, 1), alg_str(v_Text)), alg_char_value(10))}, 1));
    }
    return alg_nil();
}

static Value m_CEmitter_Mangle_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Prefix = args[0];
    (void)v_Prefix;
    Value v_Name = args[1];
    (void)v_Name;
    Value v_Renamed = alg_nil();
    (void)v_Renamed;
    (void)((v_Renamed = alg_str(v_Name)));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Renames"), "Contains", (Value[]){v_Renamed}, 1))) {
        (void)((v_Renamed = alg_str(alg_invoke(alg_property(v_this, "Renames"), "Get", (Value[]){v_Renamed}, 1))));
    }
    return alg_invoke(v_this, "SymbolOf", (Value[]){v_Prefix, v_Renamed}, 2);
    return alg_nil();
}

static Value m_CEmitter_SymbolOf_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Prefix = args[0];
    (void)v_Prefix;
    Value v_Name = args[1];
    (void)v_Name;
    return alg_add(v_Prefix, alg_invoke(v_this, "QuestionsOut", (Value[]){v_Name}, 1));
    return alg_nil();
}

static Value m_CEmitter_ClassHandle_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    return alg_invoke(v_this, "SymbolOf", (Value[]){alg_string("k_"), v_Name}, 2);
    return alg_nil();
}

static Value m_CEmitter_InitName_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    return alg_invoke(v_this, "SymbolOf", (Value[]){alg_string("i_"), v_Name}, 2);
    return alg_nil();
}

static Value m_CEmitter_EnumTypeName_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    return alg_invoke(v_this, "SymbolOf", (Value[]){alg_string("e_"), v_Name}, 2);
    return alg_nil();
}

static Value m_CEmitter_EnumMemberName_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TypeName = args[0];
    (void)v_TypeName;
    Value v_Member = args[1];
    (void)v_Member;
    return alg_invoke(v_this, "SymbolOf", (Value[]){alg_string("e_"), alg_add(alg_add(v_TypeName, alg_char_value(95)), v_Member)}, 2);
    return alg_nil();
}

static Value m_CEmitter_QuestionsOut_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Result = alg_string("");
    (void)v_Result;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_length(v_Name)))) {
            {
                {
                    Value v_C = alg_subscript_get(alg_str(v_Name), v_I);
                    (void)v_C;
                    if (alg_truthy(alg_equal(v_C, alg_char_value(63)))) {
                        (void)((v_Result = alg_add(v_Result, alg_string("_q"))));
                    } else {
                        if (alg_truthy((or_0 = alg_equal(v_C, alg_char_value(95)), alg_truthy(or_0) ? or_0 : alg_invoke(v_this, "IsLetterOrDigit", (Value[]){v_C}, 1)))) {
                            (void)((v_Result = alg_add(v_Result, alg_str(v_C))));
                        } else {
                            (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("An identifier containing '"), alg_str(v_C)), alg_string("'"))}, 1));
                        }
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Result;
    return alg_nil();
}

static Value m_CEmitter_IsLetterOrDigit_1_Char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_C = args[0];
    (void)v_C;
    return (or_5 = (or_3 = ((or_1 = alg_greater_equal(v_C, alg_char_value(97)), !alg_truthy(or_1) ? or_1 : alg_less_equal(v_C, alg_char_value(122)))), alg_truthy(or_3) ? or_3 : ((or_2 = alg_greater_equal(v_C, alg_char_value(65)), !alg_truthy(or_2) ? or_2 : alg_less_equal(v_C, alg_char_value(90))))), alg_truthy(or_5) ? or_5 : ((or_4 = alg_greater_equal(v_C, alg_char_value(48)), !alg_truthy(or_4) ? or_4 : alg_less_equal(v_C, alg_char_value(57)))));
    return alg_nil();
}

static Value m_CEmitter_Sanitize_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Text = args[0];
    (void)v_Text;
    Value v_Result = alg_string("");
    (void)v_Result;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_length(v_Text)))) {
            {
                {
                    Value v_C = alg_subscript_get(alg_str(v_Text), v_I);
                    (void)v_C;
                    if (alg_truthy((or_10 = (or_8 = ((or_6 = alg_greater_equal(v_C, alg_char_value(97)), !alg_truthy(or_6) ? or_6 : alg_less_equal(v_C, alg_char_value(122)))), alg_truthy(or_8) ? or_8 : ((or_7 = alg_greater_equal(v_C, alg_char_value(65)), !alg_truthy(or_7) ? or_7 : alg_less_equal(v_C, alg_char_value(90))))), alg_truthy(or_10) ? or_10 : ((or_9 = alg_greater_equal(v_C, alg_char_value(48)), !alg_truthy(or_9) ? or_9 : alg_less_equal(v_C, alg_char_value(57))))))) {
                        (void)((v_Result = alg_add(v_Result, alg_str(v_C))));
                    } else {
                        (void)((v_Result = alg_add(v_Result, alg_char_value(95))));
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Result;
    return alg_nil();
}

static Value m_CEmitter_CollectUnits_5_List_String_List_List_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    Value v_Name = args[1];
    (void)v_Name;
    Value v_Privates = args[2];
    (void)v_Privates;
    Value v_Units = args[3];
    (void)v_Units;
    Value v_FileName = args[4];
    (void)v_FileName;
    Value v_Own = alg_nil();
    (void)v_Own;
    Value v_Imports = alg_nil();
    (void)v_Imports;
    (void)((v_Own = alg_list()));
    (void)((v_Imports = alg_list()));
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
                            Value v_ModuleName = alg_invoke(v_this, "UnitNameOf", (Value[]){alg_str(alg_property(v_TheStmt, "FileName"))}, 1);
                            (void)v_ModuleName;
                            (void)(alg_invoke(v_Imports, "Add", (Value[]){v_ModuleName}, 1));
                            if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Statements"), alg_nil()))) {
                                (void)(alg_invoke(v_this, "CollectUnits", (Value[]){alg_property(v_TheStmt, "Statements"), v_ModuleName, alg_property(v_TheStmt, "PrivateNames"), v_Units, alg_str(alg_property(v_TheStmt, "FileName"))}, 5));
                            }
                        }
                    } else {
                        (void)(alg_invoke(v_Own, "Add", (Value[]){v_TheStmt}, 1));
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_Units, "Add", (Value[]){alg_new(k_EmitUnit, (Value[]){v_Name, v_Own, v_Imports, v_Privates, v_FileName}, 5)}, 1));
    return alg_nil();
}

static Value m_CEmitter_UnitNameOf_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Key = args[0];
    (void)v_Key;
    Value v_Start = alg_nil();
    (void)v_Start;
    Value v_Stem = alg_nil();
    (void)v_Stem;
    (void)((v_Start = alg_int(0)));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_length(v_Key)))) {
            {
                if (alg_truthy(alg_equal(alg_subscript_get(v_Key, v_I), alg_char_value(47)))) {
                    (void)((v_Start = alg_add(v_I, alg_int(1))));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)((v_Stem = alg_copy(v_Key, v_Start, alg_subtract(alg_length(v_Key), v_Start))));
    if (alg_truthy(alg_greater(alg_length(v_Stem), alg_int(4)))) {
        if (alg_truthy(alg_equal(alg_copy(v_Stem, alg_subtract(alg_length(v_Stem), alg_int(4)), alg_int(4)), alg_string(".a24")))) {
            (void)((v_Stem = alg_copy(v_Stem, alg_int(0), alg_subtract(alg_length(v_Stem), alg_int(4)))));
        }
    }
    return alg_invoke(v_this, "Sanitize", (Value[]){v_Stem}, 1);
    return alg_nil();
}

static Value m_CEmitter_VariableName_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    return alg_invoke(v_this, "Mangle", (Value[]){alg_string("v_"), v_Name}, 2);
    return alg_nil();
}

static Value m_CEmitter_FunctionName_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    return alg_invoke(v_this, "Mangle", (Value[]){alg_string("f_"), v_Name}, 2);
    return alg_nil();
}

static Value m_CEmitter_HandleName_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    return alg_invoke(v_this, "Mangle", (Value[]){alg_string("fn_"), v_Name}, 2);
    return alg_nil();
}

static Value m_CEmitter_Prototype_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Lead = alg_nil();
    (void)v_Lead;
    (void)((v_Lead = alg_string("static Value ")));
    if (alg_truthy(alg_invoke(v_this, "Exported", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1))) {
        (void)((v_Lead = alg_string("Value ")));
    }
    return alg_add(alg_add(v_Lead, alg_invoke(v_this, "FunctionName", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1)), alg_string("(Value **cells, Value *args, int32_t count)"));
    return alg_nil();
}

static Value m_CEmitter_Exported_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    if (alg_truthy(alg_property(v_this, "RootUnit"))) {
        return alg_bool(false);
    }
    return alg_not(alg_invoke(alg_property(v_this, "PrivateNames"), "Contains", (Value[]){v_Name}, 1));
    return alg_nil();
}

static Value m_CEmitter_DeclareValue_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Symbol = args[0];
    (void)v_Symbol;
    Value v_Name = args[1];
    (void)v_Name;
    if (alg_truthy(alg_invoke(v_this, "Exported", (Value[]){v_Name}, 1))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), v_Symbol), alg_char_value(59)), alg_char_value(10))}, 1));
            (void)(alg_set_property(v_this, "Header", alg_add(alg_add(alg_add(alg_add(alg_property(v_this, "Header"), alg_string("extern Value ")), v_Symbol), alg_char_value(59)), alg_char_value(10))));
        }
    } else {
        (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_Symbol), alg_char_value(59)), alg_char_value(10))}, 1));
    }
    return alg_nil();
}

static Value m_CEmitter_IsTest_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    return alg_not_equal(alg_property(alg_property(v_TheStmt, "Name"), "Literal"), alg_nil());
    return alg_nil();
}

static Value m_CEmitter_CollectFunctions_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Statements, "Length")))) {
            {
                {
                    Value v_TheStmt = alg_subscript_get(v_Statements, v_I);
                    (void)v_TheStmt;
                    if (alg_truthy(alg_is(v_TheStmt, "FunctionStmt"))) {
                        {
                            if (alg_truthy(alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_TheStmt}, 1)))) {
                                (void)(alg_invoke(alg_property(v_this, "Declared"), "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                            }
                            (void)(alg_invoke(v_this, "CollectFunctions", (Value[]){alg_property(v_TheStmt, "Body")}, 1));
                        }
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "ClassStmt"))) {
                        (void)(alg_invoke(alg_property(v_this, "Classes"), "Put", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")), v_TheStmt}, 2));
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "ObjectStmt"))) {
                        (void)(alg_invoke(alg_property(v_this, "Objects"), "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "EnumStmt"))) {
                        {
                            (void)(alg_invoke(alg_property(v_this, "EnumTypes"), "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                            {
                                Value v_J = alg_int(0);
                                (void)v_J;
                                while (alg_truthy(alg_less(v_J, alg_property(alg_property(v_TheStmt, "Members"), "Length")))) {
                                    {
                                        (void)(alg_invoke(alg_property(v_this, "EnumMembers"), "Put", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Members"), v_J), "Lexeme")), alg_invoke(v_this, "EnumMemberName", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")), alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Members"), v_J), "Lexeme"))}, 2)}, 2));
                                        (void)((v_J = alg_add(v_J, alg_int(1))));
                                    }
                                }
                            }
                        }
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "BlockStmt"))) {
                        (void)(alg_invoke(v_this, "CollectFunctions", (Value[]){alg_property(v_TheStmt, "Statements")}, 1));
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_CEmitter_CollectGlobals_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Statements, "Length")))) {
            {
                {
                    Value v_TheStmt = alg_subscript_get(v_Statements, v_I);
                    (void)v_TheStmt;
                    if (alg_truthy(alg_is(v_TheStmt, "VarStmt"))) {
                        (void)(alg_invoke(alg_property(v_this, "Globals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "VarGroupStmt"))) {
                        {
                            Value v_J = alg_int(0);
                            (void)v_J;
                            while (alg_truthy(alg_less(v_J, alg_property(alg_property(v_TheStmt, "Names"), "Length")))) {
                                {
                                    (void)(alg_invoke(alg_property(v_this, "Globals"), "Add", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_J), "Lexeme"))}, 1));
                                    (void)((v_J = alg_add(v_J, alg_int(1))));
                                }
                            }
                        }
                    }
                    if (alg_truthy((or_11 = alg_is(v_TheStmt, "FunctionStmt"), !alg_truthy(or_11) ? or_11 : alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_TheStmt}, 1))))) {
                        (void)(alg_invoke(alg_property(v_this, "TopLevel"), "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_CEmitter_CompilingFile_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    (void)(alg_set_property(v_this, "SourceFile", v_Name));
    return alg_nil();
}

static Value m_CEmitter_WithTests_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_set_property(v_this, "EmitTests", alg_bool(true)));
    return alg_nil();
}

static Value m_CEmitter_Emit_2_List_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    Value v_Stem = args[1];
    (void)v_Stem;
    Value v_MainStatements = alg_nil();
    (void)v_MainStatements;
    Value v_Units = alg_nil();
    (void)v_Units;
    Value v_Files = alg_nil();
    (void)v_Files;
    Value v_MainBodyText = alg_nil();
    (void)v_MainBodyText;
    (void)((v_MainStatements = alg_list()));
    (void)((v_Units = alg_list()));
    (void)((v_Files = alg_map()));
    (void)((v_MainBodyText = alg_string("")));
    (void)(alg_invoke(v_this, "CollectUnits", (Value[]){v_Statements, v_Stem, alg_list(), v_Units, alg_property(v_this, "SourceFile")}, 5));
    Value v_Seen = alg_set();
    (void)v_Seen;
    {
        Value v_U = alg_int(0);
        (void)v_U;
        while (alg_truthy(alg_less(v_U, alg_property(v_Units, "Length")))) {
            {
                {
                    if (alg_truthy(alg_invoke(v_Seen, "Contains", (Value[]){alg_str(alg_property(alg_subscript_get(v_Units, v_U), "Name"))}, 1))) {
                        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("Two modules named '"), alg_str(alg_property(alg_subscript_get(v_Units, v_U), "Name"))), alg_string("'"))}, 1));
                    }
                    (void)(alg_invoke(v_Seen, "Add", (Value[]){alg_str(alg_property(alg_subscript_get(v_Units, v_U), "Name"))}, 1));
                }
                (void)((v_U = alg_add(v_U, alg_int(1))));
            }
        }
    }
    {
        Value v_U = alg_int(0);
        (void)v_U;
        while (alg_truthy(alg_less(v_U, alg_property(v_Units, "Length")))) {
            {
                (void)(alg_invoke(v_this, "CollectFunctions", (Value[]){alg_property(alg_subscript_get(v_Units, v_U), "Statements")}, 1));
                (void)((v_U = alg_add(v_U, alg_int(1))));
            }
        }
    }
    {
        Value v_U = alg_int(0);
        (void)v_U;
        while (alg_truthy(alg_less(v_U, alg_property(v_Units, "Length")))) {
            {
                (void)(alg_invoke(v_this, "CollectGlobals", (Value[]){alg_property(alg_subscript_get(v_Units, v_U), "Statements")}, 1));
                (void)((v_U = alg_add(v_U, alg_int(1))));
            }
        }
    }
    {
        Value v_U = alg_int(0);
        (void)v_U;
        while (alg_truthy(alg_less(v_U, alg_property(v_Units, "Length")))) {
            {
                {
                    Value v_Exported = alg_set();
                    (void)v_Exported;
                    Value v_Own = alg_property(alg_subscript_get(v_Units, v_U), "Statements");
                    (void)v_Own;
                    {
                        Value v_I = alg_int(0);
                        (void)v_I;
                        while (alg_truthy(alg_less(v_I, alg_property(v_Own, "Length")))) {
                            {
                                {
                                    Value v_TheStmt = alg_subscript_get(v_Own, v_I);
                                    (void)v_TheStmt;
                                    if (alg_truthy((or_12 = alg_is(v_TheStmt, "FunctionStmt"), !alg_truthy(or_12) ? or_12 : alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_TheStmt}, 1))))) {
                                        (void)(alg_invoke(v_Exported, "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                                    }
                                    if (alg_truthy(alg_is(v_TheStmt, "ClassStmt"))) {
                                        (void)(alg_invoke(v_Exported, "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                                    }
                                    if (alg_truthy(alg_is(v_TheStmt, "ObjectStmt"))) {
                                        (void)(alg_invoke(v_Exported, "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                                    }
                                    if (alg_truthy(alg_is(v_TheStmt, "VarStmt"))) {
                                        (void)(alg_invoke(v_Exported, "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                                    }
                                    if (alg_truthy(alg_is(v_TheStmt, "EnumStmt"))) {
                                        {
                                            (void)(alg_invoke(v_Exported, "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                                            {
                                                Value v_J = alg_int(0);
                                                (void)v_J;
                                                while (alg_truthy(alg_less(v_J, alg_property(alg_property(v_TheStmt, "Members"), "Length")))) {
                                                    {
                                                        (void)(alg_invoke(v_Exported, "Add", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Members"), v_J), "Lexeme"))}, 1));
                                                        (void)((v_J = alg_add(v_J, alg_int(1))));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (alg_truthy(alg_is(v_TheStmt, "VarGroupStmt"))) {
                                        {
                                            Value v_J = alg_int(0);
                                            (void)v_J;
                                            while (alg_truthy(alg_less(v_J, alg_property(alg_property(v_TheStmt, "Names"), "Length")))) {
                                                {
                                                    (void)(alg_invoke(v_Exported, "Add", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_J), "Lexeme"))}, 1));
                                                    (void)((v_J = alg_add(v_J, alg_int(1))));
                                                }
                                            }
                                        }
                                    }
                                }
                                (void)((v_I = alg_add(v_I, alg_int(1))));
                            }
                        }
                    }
                    Value v_Everything = alg_set();
                    (void)v_Everything;
                    {
                        Value v_I = alg_int(0);
                        (void)v_I;
                        while (alg_truthy(alg_less(v_I, alg_property(alg_invoke(v_Exported, "ToList", NULL, 0), "Length")))) {
                            {
                                (void)(alg_invoke(v_Everything, "Add", (Value[]){alg_subscript_get(alg_invoke(v_Exported, "ToList", NULL, 0), v_I)}, 1));
                                (void)((v_I = alg_add(v_I, alg_int(1))));
                            }
                        }
                    }
                    (void)(alg_invoke(alg_property(v_this, "UnitAll"), "Put", (Value[]){alg_str(alg_property(alg_subscript_get(v_Units, v_U), "Name")), v_Everything}, 2));
                    Value v_Hidden = alg_property(alg_subscript_get(v_Units, v_U), "PrivateNames");
                    (void)v_Hidden;
                    {
                        Value v_I = alg_int(0);
                        (void)v_I;
                        while (alg_truthy(alg_less(v_I, alg_property(v_Hidden, "Length")))) {
                            {
                                (void)(alg_invoke(v_Exported, "Remove", (Value[]){alg_str(alg_subscript_get(v_Hidden, v_I))}, 1));
                                (void)((v_I = alg_add(v_I, alg_int(1))));
                            }
                        }
                    }
                    (void)(alg_invoke(alg_property(v_this, "UnitExports"), "Put", (Value[]){alg_str(alg_property(alg_subscript_get(v_Units, v_U), "Name")), v_Exported}, 2));
                }
                (void)((v_U = alg_add(v_U, alg_int(1))));
            }
        }
    }
    {
        Value v_U = alg_int(0);
        (void)v_U;
        while (alg_truthy(alg_less(v_U, alg_property(v_Units, "Length")))) {
            {
                {
                    Value v_Unit = alg_subscript_get(v_Units, v_U);
                    (void)v_Unit;
                    (void)(alg_set_property(v_this, "Declarations", alg_buffer(alg_int(0))));
                    (void)(alg_set_property(v_this, "Functions", alg_buffer(alg_int(0))));
                    (void)(alg_set_property(v_this, "Setup", alg_buffer(alg_int(0))));
                    (void)(alg_set_property(v_this, "MainBody", alg_buffer(alg_int(0))));
                    (void)(alg_set_property(v_this, "Header", alg_string("")));
                    (void)(alg_set_property(v_this, "Target", alg_string("main")));
                    (void)(alg_set_property(v_this, "Logicals", alg_int(0)));
                    (void)(alg_set_property(v_this, "Loops", alg_int(0)));
                    (void)(alg_set_property(v_this, "UnitTests", alg_int(0)));
                    Value v_IsMain = alg_equal(v_U, alg_subtract(alg_property(v_Units, "Length"), alg_int(1)));
                    (void)v_IsMain;
                    (void)(alg_set_property(v_this, "UnitName", alg_str(alg_property(v_Unit, "Name"))));
                    (void)(alg_set_property(v_this, "PrivateNames", alg_property(v_Unit, "PrivateNames")));
                    (void)(alg_set_property(v_this, "RootUnit", v_IsMain));
                    (void)(alg_set_property(v_this, "CurrentFile", alg_str(alg_property(v_Unit, "FileName"))));
                    (void)(alg_set_property(v_this, "ShadowNames", alg_set()));
                    if (alg_truthy(alg_invoke(alg_property(v_this, "UnitAll"), "Contains", (Value[]){alg_str(alg_property(v_Unit, "Name"))}, 1))) {
                        {
                            Value v_Own = alg_invoke((alg_invoke(alg_property(v_this, "UnitAll"), "Get", (Value[]){alg_str(alg_property(v_Unit, "Name"))}, 1)), "ToList", NULL, 0);
                            (void)v_Own;
                            {
                                Value v_I = alg_int(0);
                                (void)v_I;
                                while (alg_truthy(alg_less(v_I, alg_property(v_Own, "Length")))) {
                                    {
                                        (void)(alg_invoke(alg_property(v_this, "ShadowNames"), "Add", (Value[]){alg_subscript_get(v_Own, v_I)}, 1));
                                        (void)((v_I = alg_add(v_I, alg_int(1))));
                                    }
                                }
                            }
                        }
                    }
                    {
                        Value v_I = alg_int(0);
                        (void)v_I;
                        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_Unit, "Imports"), "Length")))) {
                            {
                                if (alg_truthy(alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){alg_str(alg_subscript_get(alg_property(v_Unit, "Imports"), v_I))}, 1))) {
                                    {
                                        Value v_Seen = alg_invoke((alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){alg_str(alg_subscript_get(alg_property(v_Unit, "Imports"), v_I))}, 1)), "ToList", NULL, 0);
                                        (void)v_Seen;
                                        {
                                            Value v_J = alg_int(0);
                                            (void)v_J;
                                            while (alg_truthy(alg_less(v_J, alg_property(v_Seen, "Length")))) {
                                                {
                                                    (void)(alg_invoke(alg_property(v_this, "ShadowNames"), "Add", (Value[]){alg_subscript_get(v_Seen, v_J)}, 1));
                                                    (void)((v_J = alg_add(v_J, alg_int(1))));
                                                }
                                            }
                                        }
                                    }
                                }
                                (void)((v_I = alg_add(v_I, alg_int(1))));
                            }
                        }
                    }
                    {
                        Value v_I = alg_int(0);
                        (void)v_I;
                        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_Unit, "Statements"), "Length")))) {
                            {
                                {
                                    Value v_TheStmt = alg_subscript_get(alg_property(v_Unit, "Statements"), v_I);
                                    (void)v_TheStmt;
                                    if (alg_truthy((or_13 = alg_is(v_TheStmt, "FunctionStmt"), !alg_truthy(or_13) ? or_13 : alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_TheStmt}, 1))))) {
                                        {
                                            (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_invoke(v_this, "Prototype", (Value[]){v_TheStmt}, 1), alg_char_value(59)), alg_char_value(10))}, 1));
                                            if (alg_truthy(alg_invoke(v_this, "Exported", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1))) {
                                                (void)(alg_set_property(v_this, "Header", alg_add(alg_add(alg_add(alg_property(v_this, "Header"), alg_invoke(v_this, "Prototype", (Value[]){v_TheStmt}, 1)), alg_char_value(59)), alg_char_value(10))));
                                            }
                                        }
                                    }
                                }
                                (void)((v_I = alg_add(v_I, alg_int(1))));
                            }
                        }
                    }
                    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(true)));
                    {
                        Value v_I = alg_int(0);
                        (void)v_I;
                        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_Unit, "Statements"), "Length")))) {
                            {
                                {
                                    Value v_TheStmt = alg_subscript_get(alg_property(v_Unit, "Statements"), v_I);
                                    (void)v_TheStmt;
                                    if (alg_truthy(alg_is(v_TheStmt, "BlockStmt"))) {
                                        {
                                            {
                                                Value v_J = alg_int(0);
                                                (void)v_J;
                                                while (alg_truthy(alg_less(v_J, alg_property(alg_property(v_TheStmt, "Statements"), "Length")))) {
                                                    {
                                                        (void)(alg_invoke(v_MainStatements, "Add", (Value[]){alg_subscript_get(alg_property(v_TheStmt, "Statements"), v_J)}, 1));
                                                        (void)((v_J = alg_add(v_J, alg_int(1))));
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        (void)(alg_invoke(v_this, "Execute", (Value[]){v_TheStmt}, 1));
                                    }
                                }
                                (void)((v_I = alg_add(v_I, alg_int(1))));
                            }
                        }
                    }
                    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
                    if (alg_truthy(v_IsMain)) {
                        {
                            Value v_InitBody = alg_property(v_this, "MainBody");
                            (void)v_InitBody;
                            (void)(alg_set_property(v_this, "MainBody", alg_buffer(alg_int(0))));
                            if (alg_truthy(alg_property(v_this, "EmitTests"))) {
                                (void)(alg_invoke(v_this, "EmitTestRunner", NULL, 0));
                            } else {
                                {
                                    (void)(alg_set_property(v_this, "Volatiles", alg_invoke(v_this, "ContainsTry", (Value[]){v_MainStatements}, 1)));
                                    (void)(alg_set_property(v_this, "Boxed", alg_invoke(v_this, "BoxesFor", (Value[]){v_MainStatements}, 1)));
                                    (void)(alg_set_property(v_this, "Cells", alg_list()));
                                    (void)(alg_invoke(v_this, "HoistCells", (Value[]){v_MainStatements}, 1));
                                    {
                                        Value v_I = alg_int(0);
                                        (void)v_I;
                                        while (alg_truthy(alg_less(v_I, alg_property(v_MainStatements, "Length")))) {
                                            {
                                                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(v_MainStatements, v_I)}, 1));
                                                (void)((v_I = alg_add(v_I, alg_int(1))));
                                            }
                                        }
                                    }
                                    (void)(alg_set_property(v_this, "Boxed", alg_list()));
                                    (void)(alg_set_property(v_this, "Cells", alg_list()));
                                    (void)(alg_set_property(v_this, "Volatiles", alg_bool(false)));
                                }
                            }
                            (void)((v_MainBodyText = alg_property(alg_property(v_this, "MainBody"), "Text")));
                            (void)(alg_set_property(v_this, "MainBody", v_InitBody));
                        }
                    }
                    (void)(alg_invoke(v_Files, "Put", (Value[]){alg_add(alg_str(alg_property(v_Unit, "Name")), alg_string(".h")), alg_invoke(v_this, "UnitHeader", (Value[]){v_Unit}, 1)}, 2));
                    (void)(alg_invoke(v_Files, "Put", (Value[]){alg_add(alg_str(alg_property(v_Unit, "Name")), alg_string(".c")), alg_invoke(v_this, "UnitSource", (Value[]){v_Unit, v_Units, v_IsMain, v_MainBodyText}, 4)}, 2));
                }
                (void)((v_U = alg_add(v_U, alg_int(1))));
            }
        }
    }
    return v_Files;
    return alg_nil();
}

static Value m_CEmitter_UnitHeader_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Unit = args[0];
    (void)v_Unit;
    Value v_Guard = alg_nil();
    (void)v_Guard;
    Value v_Text = alg_nil();
    (void)v_Text;
    (void)((v_Guard = alg_add(alg_add(alg_string("ALG_"), alg_invoke(v_this, "Upper", (Value[]){alg_str(alg_property(v_Unit, "Name"))}, 1)), alg_string("_H"))));
    (void)((v_Text = alg_add(alg_string("/* Generated from Algol-24.  Do not edit. */"), alg_char_value(10))));
    (void)((v_Text = alg_add(alg_add(alg_add(v_Text, alg_string("#ifndef ")), v_Guard), alg_char_value(10))));
    (void)((v_Text = alg_add(alg_add(alg_add(alg_add(v_Text, alg_string("#define ")), v_Guard), alg_char_value(10)), alg_char_value(10))));
    (void)((v_Text = alg_add(alg_add(alg_add(v_Text, alg_string("#include \"algol.h\"")), alg_char_value(10)), alg_char_value(10))));
    (void)((v_Text = alg_add(v_Text, alg_property(v_this, "Header"))));
    (void)((v_Text = alg_add(alg_add(alg_add(alg_add(v_Text, alg_string("void init_")), alg_str(alg_property(v_Unit, "Name"))), alg_string("(void);")), alg_char_value(10))));
    (void)((v_Text = alg_add(alg_add(alg_add(v_Text, alg_char_value(10)), alg_string("#endif")), alg_char_value(10))));
    return v_Text;
    return alg_nil();
}

static Value m_CEmitter_UnitSource_4_List_Boolean_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Unit = args[0];
    (void)v_Unit;
    Value v_Units = args[1];
    (void)v_Units;
    Value v_IsMain = args[2];
    (void)v_IsMain;
    Value v_Written = args[3];
    (void)v_Written;
    Value v_Text = alg_nil();
    (void)v_Text;
    (void)((v_Text = alg_add(alg_string("/* Generated from Algol-24.  Do not edit. */"), alg_char_value(10))));
    (void)((v_Text = alg_add(alg_add(alg_add(alg_add(v_Text, alg_string("#include \"")), alg_str(alg_property(v_Unit, "Name"))), alg_string(".h\"")), alg_char_value(10))));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_Unit, "Imports"), "Length")))) {
            {
                (void)((v_Text = alg_add(alg_add(alg_add(alg_add(v_Text, alg_string("#include \"")), alg_str(alg_subscript_get(alg_property(v_Unit, "Imports"), v_I))), alg_string(".h\"")), alg_char_value(10))));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)((v_Text = alg_add(v_Text, alg_char_value(10))));
    if (alg_truthy(alg_greater(alg_property(alg_property(v_this, "Declarations"), "Length"), alg_int(0)))) {
        (void)((v_Text = alg_add(alg_add(v_Text, alg_property(alg_property(v_this, "Declarations"), "Text")), alg_char_value(10))));
    }
    if (alg_truthy(alg_greater(alg_property(alg_property(v_this, "Functions"), "Length"), alg_int(0)))) {
        (void)((v_Text = alg_add(v_Text, alg_property(alg_property(v_this, "Functions"), "Text"))));
    }
    (void)((v_Text = alg_add(alg_add(alg_add(alg_add(v_Text, alg_string("void init_")), alg_str(alg_property(v_Unit, "Name"))), alg_string("(void) {")), alg_char_value(10))));
    (void)((v_Text = alg_add(v_Text, alg_property(alg_property(v_this, "Setup"), "Text"))));
    (void)((v_Text = alg_add(v_Text, alg_property(alg_property(v_this, "MainBody"), "Text"))));
    (void)((v_Text = alg_add(alg_add(v_Text, alg_char_value(125)), alg_char_value(10))));
    if (alg_truthy(v_IsMain)) {
        {
            (void)((v_Text = alg_add(alg_add(alg_add(v_Text, alg_char_value(10)), alg_string("int main(int argc, char **argv) {")), alg_char_value(10))));
            (void)((v_Text = alg_add(alg_add(v_Text, alg_string("    alg_set_arguments(argc, argv);")), alg_char_value(10))));
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(v_Units, "Length")))) {
                    {
                        (void)((v_Text = alg_add(alg_add(alg_add(alg_add(v_Text, alg_string("    init_")), alg_str(alg_property(alg_subscript_get(v_Units, v_I), "Name"))), alg_string("();")), alg_char_value(10))));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            (void)((v_Text = alg_add(v_Text, v_Written)));
            (void)((v_Text = alg_add(alg_add(alg_add(alg_add(v_Text, alg_string("    return 0;")), alg_char_value(10)), alg_char_value(125)), alg_char_value(10))));
        }
    }
    return v_Text;
    return alg_nil();
}

static Value m_CEmitter_Upper_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Text = args[0];
    (void)v_Text;
    Value v_Result = alg_nil();
    (void)v_Result;
    (void)((v_Result = alg_string("")));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_length(v_Text)))) {
            {
                {
                    Value v_C = alg_subscript_get(v_Text, v_I);
                    (void)v_C;
                    if (alg_truthy(alg_greater_equal(v_C, alg_char_value(97)))) {
                        if (alg_truthy(alg_less_equal(v_C, alg_char_value(122)))) {
                            (void)((v_C = alg_char(alg_subtract(alg_ord(v_C), alg_int(32)))));
                        }
                    }
                    (void)((v_Result = alg_add(v_Result, v_C)));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Result;
    return alg_nil();
}

static Value m_CEmitter_TextLess_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_A = args[0];
    (void)v_A;
    Value v_B = args[1];
    (void)v_B;
    Value v_Shorter = alg_nil();
    (void)v_Shorter;
    (void)((v_Shorter = alg_length(v_A)));
    if (alg_truthy(alg_less(alg_length(v_B), v_Shorter))) {
        (void)((v_Shorter = alg_length(v_B)));
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, v_Shorter))) {
            {
                {
                    Value v_Left = alg_subscript_get(alg_str(v_A), v_I);
                    (void)v_Left;
                    Value v_Right = alg_subscript_get(alg_str(v_B), v_I);
                    (void)v_Right;
                    if (alg_truthy(alg_less(v_Left, v_Right))) {
                        return alg_bool(true);
                    }
                    if (alg_truthy(alg_less(v_Right, v_Left))) {
                        return alg_bool(false);
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_less(alg_length(v_A), alg_length(v_B));
    return alg_nil();
}

static Value m_CEmitter_EmitTestRunner_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Files = alg_nil();
    (void)v_Files;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_this, "TestSymbols"), "Length")))) {
            {
                (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), alg_str(alg_subscript_get(alg_property(v_this, "TestSymbols"), v_I))), alg_string("(Value **cells, Value *args, int32_t count);")), alg_char_value(10))}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("    alg_test_begin("), alg_str(alg_property(alg_property(v_this, "Tests"), "Length"))), alg_string(");")), alg_char_value(10))}, 1));
    (void)((v_Files = alg_list()));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_this, "TestFiles"), "Length")))) {
            {
                if (alg_truthy(alg_not(alg_invoke(v_Files, "Contains", (Value[]){alg_subscript_get(alg_property(v_this, "TestFiles"), v_I)}, 1)))) {
                    (void)(alg_invoke(v_Files, "Add", (Value[]){alg_subscript_get(alg_property(v_this, "TestFiles"), v_I)}, 1));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    {
        Value v_F = alg_int(0);
        (void)v_F;
        while (alg_truthy(alg_less(v_F, alg_property(v_Files, "Length")))) {
            {
                {
                    (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("    alg_test_file("), f_QuoteC(NULL, (Value[]){alg_str(alg_subscript_get(v_Files, v_F))}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                    Value v_Ordered = alg_list();
                    (void)v_Ordered;
                    {
                        Value v_I = alg_int(0);
                        (void)v_I;
                        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_this, "Tests"), "Length")))) {
                            {
                                if (alg_truthy(alg_equal(alg_subscript_get(alg_property(v_this, "TestFiles"), v_I), alg_subscript_get(v_Files, v_F)))) {
                                    (void)(alg_invoke(v_Ordered, "Add", (Value[]){v_I}, 1));
                                }
                                (void)((v_I = alg_add(v_I, alg_int(1))));
                            }
                        }
                    }
                    {
                        Value v_A = alg_int(0);
                        (void)v_A;
                        while (alg_truthy(alg_less(v_A, alg_property(v_Ordered, "Length")))) {
                            {
                                {
                                    Value v_B = alg_add(v_A, alg_int(1));
                                    (void)v_B;
                                    while (alg_truthy(alg_less(v_B, alg_property(v_Ordered, "Length")))) {
                                        {
                                            if (alg_truthy(alg_invoke(v_this, "TextLess", (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_this, "Tests"), alg_subscript_get(v_Ordered, v_B)), "Name"), "Lexeme")), alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_this, "Tests"), alg_subscript_get(v_Ordered, v_A)), "Name"), "Lexeme"))}, 2))) {
                                                {
                                                    Value v_Swap = alg_subscript_get(v_Ordered, v_A);
                                                    (void)v_Swap;
                                                    (void)(alg_subscript_set(v_Ordered, v_A, alg_subscript_get(v_Ordered, v_B)));
                                                    (void)(alg_subscript_set(v_Ordered, v_B, v_Swap));
                                                }
                                            }
                                            (void)((v_B = alg_add(v_B, alg_int(1))));
                                        }
                                    }
                                }
                                (void)((v_A = alg_add(v_A, alg_int(1))));
                            }
                        }
                    }
                    {
                        Value v_A = alg_int(0);
                        (void)v_A;
                        while (alg_truthy(alg_less(v_A, alg_property(v_Ordered, "Length")))) {
                            {
                                (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_test_run("), f_QuoteC(NULL, (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_this, "Tests"), alg_subscript_get(v_Ordered, v_A)), "Name"), "Literal"))}, 1)), alg_string(", ")), alg_str(alg_subscript_get(alg_property(v_this, "TestSymbols"), alg_subscript_get(v_Ordered, v_A)))), alg_string(");")), alg_char_value(10))}, 1));
                                (void)((v_A = alg_add(v_A, alg_int(1))));
                            }
                        }
                    }
                    (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_string("    alg_test_end_file();"), alg_char_value(10))}, 1));
                }
                (void)((v_F = alg_add(v_F, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_string("    return alg_test_summary();"), alg_char_value(10))}, 1));
    return alg_nil();
}

static Value m_CEmitter_Execute_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    (void)(alg_invoke(v_TheStmt, "Accept", (Value[]){v_this}, 1));
    return alg_nil();
}

static Value m_CEmitter_Evaluate_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    return alg_invoke(v_TheExpr, "Accept", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value m_CEmitter_EmitTest_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Symbol = alg_nil();
    (void)v_Symbol;
    (void)((v_Symbol = alg_add(alg_add(alg_add(alg_string("t_"), alg_property(v_this, "UnitName")), alg_char_value(95)), alg_str(alg_property(v_this, "UnitTests")))));
    (void)(alg_set_property(v_this, "UnitTests", alg_add(alg_property(v_this, "UnitTests"), alg_int(1))));
    (void)(alg_invoke(alg_property(v_this, "Tests"), "Add", (Value[]){v_TheStmt}, 1));
    (void)(alg_invoke(alg_property(v_this, "TestFiles"), "Add", (Value[]){alg_property(v_this, "CurrentFile")}, 1));
    (void)(alg_invoke(alg_property(v_this, "TestSymbols"), "Add", (Value[]){v_Symbol}, 1));
    Value v_EnclosingTarget = alg_property(v_this, "Target");
    (void)v_EnclosingTarget;
    Value v_EnclosingBody = alg_property(v_this, "Body");
    (void)v_EnclosingBody;
    Value v_EnclosingLocals = alg_property(v_this, "Locals");
    (void)v_EnclosingLocals;
    Value v_EnclosingTop = alg_property(v_this, "AtTopLevel");
    (void)v_EnclosingTop;
    Value v_EnclosingVolatiles = alg_property(v_this, "Volatiles");
    (void)v_EnclosingVolatiles;
    Value v_EnclosingDepth = alg_property(v_this, "Depth");
    (void)v_EnclosingDepth;
    Value v_EnclosingBoxed = alg_property(v_this, "Boxed");
    (void)v_EnclosingBoxed;
    Value v_EnclosingCaptured = alg_property(v_this, "Captured");
    (void)v_EnclosingCaptured;
    Value v_EnclosingCells = alg_property(v_this, "Cells");
    (void)v_EnclosingCells;
    (void)(alg_set_property(v_this, "Target", alg_string("body")));
    (void)(alg_set_property(v_this, "Body", alg_buffer(alg_int(0))));
    (void)(alg_set_property(v_this, "Depth", alg_int(1)));
    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
    (void)(alg_set_property(v_this, "Volatiles", alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_TheStmt, "Body")}, 1)));
    (void)(alg_set_property(v_this, "Boxed", alg_invoke(v_this, "BoxesFor", (Value[]){alg_property(v_TheStmt, "Body")}, 1)));
    (void)(alg_set_property(v_this, "Captured", alg_map()));
    (void)(alg_set_property(v_this, "Cells", alg_list()));
    (void)(alg_set_property(v_this, "Locals", alg_list()));
    Value v_EnclosingTryDepth = alg_property(v_this, "TryDepth");
    (void)v_EnclosingTryDepth;
    Value v_EnclosingLoopTry = alg_property(v_this, "LoopTryDepth");
    (void)v_EnclosingLoopTry;
    (void)(alg_set_property(v_this, "TryDepth", alg_int(0)));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_int(0)));
    (void)(alg_invoke(v_this, "HoistCells", (Value[]){alg_property(v_TheStmt, "Body")}, 1));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Body"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(alg_property(v_TheStmt, "Body"), v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    Value v_Written = alg_property(alg_property(v_this, "Body"), "Text");
    (void)v_Written;
    (void)(alg_set_property(v_this, "Target", v_EnclosingTarget));
    (void)(alg_set_property(v_this, "Body", v_EnclosingBody));
    (void)(alg_set_property(v_this, "Locals", v_EnclosingLocals));
    (void)(alg_set_property(v_this, "AtTopLevel", v_EnclosingTop));
    (void)(alg_set_property(v_this, "Volatiles", v_EnclosingVolatiles));
    (void)(alg_set_property(v_this, "Depth", v_EnclosingDepth));
    (void)(alg_set_property(v_this, "Boxed", v_EnclosingBoxed));
    (void)(alg_set_property(v_this, "Captured", v_EnclosingCaptured));
    (void)(alg_set_property(v_this, "Cells", v_EnclosingCells));
    (void)(alg_set_property(v_this, "TryDepth", v_EnclosingTryDepth));
    (void)(alg_set_property(v_this, "LoopTryDepth", v_EnclosingLoopTry));
    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), v_Symbol), alg_string("(Value **cells, Value *args, int32_t count);")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), v_Symbol), alg_string("(Value **cells, Value *args, int32_t count) {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)cells; (void)args; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_Written}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("    return alg_nil();"), alg_char_value(10)), alg_char_value(125)), alg_char_value(10)), alg_char_value(10))}, 1));
    return alg_nil();
}

static Value m_CEmitter_RefuseBareBinding_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Body = args[0];
    (void)v_Body;
    if (alg_truthy((or_14 = alg_is(v_Body, "VarStmt"), alg_truthy(or_14) ? or_14 : alg_is(v_Body, "VarGroupStmt")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("A 'var' as an unbraced branch or loop body")}, 1));
    }
    return alg_nil();
}

static Value m_CEmitter_DeclaresNested_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Statements, "Length")))) {
            {
                {
                    Value v_TheStmt = alg_subscript_get(v_Statements, v_I);
                    (void)v_TheStmt;
                    if (alg_truthy(alg_is(v_TheStmt, "FunctionStmt"))) {
                        return alg_bool(true);
                    }
                    if (alg_truthy((or_15 = alg_is(v_TheStmt, "BlockStmt"), !alg_truthy(or_15) ? or_15 : alg_invoke(v_this, "DeclaresNested", (Value[]){alg_property(v_TheStmt, "Statements")}, 1)))) {
                        return alg_bool(true);
                    }
                    if (alg_truthy((or_16 = alg_is(v_TheStmt, "WhileStmt"), !alg_truthy(or_16) ? or_16 : alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "Body"))}, 1)))) {
                        return alg_bool(true);
                    }
                    if (alg_truthy((or_17 = alg_is(v_TheStmt, "ForInStmt"), !alg_truthy(or_17) ? or_17 : alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "Body"))}, 1)))) {
                        return alg_bool(true);
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "IfStmt"))) {
                        {
                            if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "ThenBranch"))}, 1))) {
                                return alg_bool(true);
                            }
                            if (alg_truthy((or_18 = alg_not_equal(alg_property(v_TheStmt, "ElseBranch"), alg_nil()), !alg_truthy(or_18) ? or_18 : alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "ElseBranch"))}, 1)))) {
                                return alg_bool(true);
                            }
                        }
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "TryStmt"))) {
                        {
                            if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "TryBlock"))}, 1))) {
                                return alg_bool(true);
                            }
                            Value v_Handlers = alg_invoke(alg_property(v_TheStmt, "Handlers"), "Values", NULL, 0);
                            (void)v_Handlers;
                            {
                                Value v_J = alg_int(0);
                                (void)v_J;
                                while (alg_truthy(alg_less(v_J, alg_property(v_Handlers, "Length")))) {
                                    {
                                        if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(alg_subscript_get(v_Handlers, v_J), "Body"))}, 1))) {
                                            return alg_bool(true);
                                        }
                                        (void)((v_J = alg_add(v_J, alg_int(1))));
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
    return alg_bool(false);
    return alg_nil();
}

static Value m_CEmitter_AddOnce_2_List_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Names = args[0];
    (void)v_Names;
    Value v_Name = args[1];
    (void)v_Name;
    if (alg_truthy(alg_not(alg_invoke(v_Names, "Contains", (Value[]){v_Name}, 1)))) {
        (void)(alg_invoke(v_Names, "Add", (Value[]){v_Name}, 1));
    }
    return alg_nil();
}

static Value m_CEmitter_CollectBindings_2_List_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    Value v_Names = args[1];
    (void)v_Names;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Statements, "Length")))) {
            {
                {
                    Value v_TheStmt = alg_subscript_get(v_Statements, v_I);
                    (void)v_TheStmt;
                    if (alg_truthy(alg_is(v_TheStmt, "VarStmt"))) {
                        (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_Names, alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 2));
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "VarGroupStmt"))) {
                        {
                            Value v_J = alg_int(0);
                            (void)v_J;
                            while (alg_truthy(alg_less(v_J, alg_property(alg_property(v_TheStmt, "Names"), "Length")))) {
                                {
                                    (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_Names, alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_J), "Lexeme"))}, 2));
                                    (void)((v_J = alg_add(v_J, alg_int(1))));
                                }
                            }
                        }
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "ForInStmt"))) {
                        {
                            (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_Names, alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 2));
                            (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "Body")), v_Names}, 2));
                        }
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "BlockStmt"))) {
                        (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_property(v_TheStmt, "Statements"), v_Names}, 2));
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "WhileStmt"))) {
                        (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "Body")), v_Names}, 2));
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "IfStmt"))) {
                        {
                            (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "ThenBranch")), v_Names}, 2));
                            if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "ElseBranch"), alg_nil()))) {
                                (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "ElseBranch")), v_Names}, 2));
                            }
                        }
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "TryStmt"))) {
                        {
                            (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "TryBlock")), v_Names}, 2));
                            Value v_Handlers = alg_invoke(alg_property(v_TheStmt, "Handlers"), "Values", NULL, 0);
                            (void)v_Handlers;
                            {
                                Value v_J = alg_int(0);
                                (void)v_J;
                                while (alg_truthy(alg_less(v_J, alg_property(v_Handlers, "Length")))) {
                                    {
                                        {
                                            (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_Names, alg_str(alg_property(alg_subscript_get(v_Handlers, v_J), "Name"))}, 2));
                                            (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(alg_subscript_get(v_Handlers, v_J), "Body")), v_Names}, 2));
                                        }
                                        (void)((v_J = alg_add(v_J, alg_int(1))));
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
    return alg_nil();
}

static Value m_CEmitter_BoundNames_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Names = alg_nil();
    (void)v_Names;
    (void)((v_Names = alg_list()));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Params"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_Names, alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Params"), v_I), "Lexeme"))}, 2));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_property(v_TheStmt, "Body"), v_Names}, 2));
    return v_Names;
    return alg_nil();
}

static Value m_CEmitter_BoxesFor_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Body = args[0];
    (void)v_Body;
    Value v_Names = alg_nil();
    (void)v_Names;
    (void)((v_Names = alg_list()));
    if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){v_Body}, 1))) {
        (void)(alg_invoke(v_this, "CollectBindings", (Value[]){v_Body, v_Names}, 2));
    }
    return v_Names;
    return alg_nil();
}

static Value m_CEmitter_Cell_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    return alg_invoke(v_this, "Mangle", (Value[]){alg_string("c_"), v_Name}, 2);
    return alg_nil();
}

static Value m_CEmitter_Read_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_add(alg_add(alg_string("(*cells["), alg_str(alg_invoke(alg_property(v_this, "Captured"), "Get", (Value[]){v_Name}, 1))), alg_string("])"));
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_add(alg_add(alg_string("(*"), alg_invoke(v_this, "Cell", (Value[]){v_Name}, 1)), alg_char_value(41));
    }
    return alg_invoke(v_this, "VariableName", (Value[]){v_Name}, 1);
    return alg_nil();
}

static Value m_CEmitter_ClosureOf_2_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Cells = args[1];
    (void)v_Cells;
    Value v_Array = alg_nil();
    (void)v_Array;
    (void)((v_Array = alg_string("NULL, 0")));
    if (alg_truthy(alg_greater(alg_property(v_Cells, "Length"), alg_int(0)))) {
        {
            Value v_Joined = alg_string("");
            (void)v_Joined;
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(v_Cells, "Length")))) {
                    {
                        {
                            if (alg_truthy(alg_greater(v_I, alg_int(0)))) {
                                (void)((v_Joined = alg_add(v_Joined, alg_string(", "))));
                            }
                            (void)((v_Joined = alg_add(v_Joined, alg_invoke(v_this, "Cell", (Value[]){alg_str(alg_subscript_get(v_Cells, v_I))}, 1))));
                        }
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            (void)((v_Array = alg_add(alg_add(alg_add(alg_string("(Value*[]){"), v_Joined), alg_string("}, ")), alg_str(alg_property(v_Cells, "Length")))));
        }
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_closure("), f_QuoteC(NULL, (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "FunctionName", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1)), alg_string(", ")), v_Array), alg_string(", ")), alg_str(alg_property(alg_property(v_TheStmt, "Params"), "Length"))), alg_char_value(41));
    return alg_nil();
}

static Value m_CEmitter_ContainsTry_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Statements, "Length")))) {
            {
                {
                    Value v_TheStmt = alg_subscript_get(v_Statements, v_I);
                    (void)v_TheStmt;
                    if (alg_truthy(alg_is(v_TheStmt, "TryStmt"))) {
                        return alg_bool(true);
                    }
                    if (alg_truthy((or_19 = alg_is(v_TheStmt, "BlockStmt"), !alg_truthy(or_19) ? or_19 : alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_TheStmt, "Statements")}, 1)))) {
                        return alg_bool(true);
                    }
                    if (alg_truthy((or_20 = alg_is(v_TheStmt, "WhileStmt"), !alg_truthy(or_20) ? or_20 : alg_invoke(v_this, "ContainsTry", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "Body"))}, 1)))) {
                        return alg_bool(true);
                    }
                    if (alg_truthy((or_21 = alg_is(v_TheStmt, "ForInStmt"), !alg_truthy(or_21) ? or_21 : alg_invoke(v_this, "ContainsTry", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "Body"))}, 1)))) {
                        return alg_bool(true);
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "IfStmt"))) {
                        {
                            if (alg_truthy(alg_invoke(v_this, "ContainsTry", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "ThenBranch"))}, 1))) {
                                return alg_bool(true);
                            }
                            if (alg_truthy((or_22 = alg_not_equal(alg_property(v_TheStmt, "ElseBranch"), alg_nil()), !alg_truthy(or_22) ? or_22 : alg_invoke(v_this, "ContainsTry", (Value[]){alg_list_keep(alg_list(), alg_property(v_TheStmt, "ElseBranch"))}, 1)))) {
                                return alg_bool(true);
                            }
                        }
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value m_CEmitter_Local_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_property(v_this, "Volatiles"))) {
        return alg_string("volatile Value ");
    }
    return alg_string("Value ");
    return alg_nil();
}

static Value m_CEmitter_RequireCell_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Cells"), "Contains", (Value[]){v_Name}, 1)))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("A capture of '"), v_Name), alg_string("'"))}, 1));
    }
    return alg_nil();
}

static Value m_CEmitter_OpenScope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_list_keep(alg_list_keep(alg_list(), alg_property(alg_property(v_this, "Cells"), "Length")), alg_property(alg_property(v_this, "Locals"), "Length"));
    return alg_nil();
}

static Value m_CEmitter_CloseScope_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Mark = args[0];
    (void)v_Mark;
    while (alg_truthy(alg_greater(alg_property(alg_property(v_this, "Cells"), "Length"), alg_subscript_get(v_Mark, alg_int(0))))) {
        (void)(alg_invoke(alg_property(v_this, "Cells"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "Cells"), "Length"), alg_int(1))}, 1));
    }
    while (alg_truthy(alg_greater(alg_property(alg_property(v_this, "Locals"), "Length"), alg_subscript_get(v_Mark, alg_int(1))))) {
        (void)(alg_invoke(alg_property(v_this, "Locals"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "Locals"), "Length"), alg_int(1))}, 1));
    }
    return alg_nil();
}

static Value m_CEmitter_DeclareCell_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Initial = args[1];
    (void)v_Initial;
    Value v_Qualifier = alg_nil();
    (void)v_Qualifier;
    (void)((v_Qualifier = alg_string("")));
    if (alg_truthy(alg_property(v_this, "Volatiles"))) {
        (void)((v_Qualifier = alg_string("volatile ")));
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("Value *"), v_Qualifier), alg_invoke(v_this, "Cell", (Value[]){v_Name}, 1)), alg_string(" = alg_cell(")), v_Initial), alg_string(");"))}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "Cell", (Value[]){v_Name}, 1)), alg_char_value(59))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Cells"), "Add", (Value[]){v_Name}, 1));
    return alg_nil();
}

static Value m_CEmitter_HoistCells_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Statements, "Length")))) {
            {
                {
                    Value v_TheStmt = alg_subscript_get(v_Statements, v_I);
                    (void)v_TheStmt;
                    if (alg_truthy((or_23 = alg_is(v_TheStmt, "VarStmt"), !alg_truthy(or_23) ? or_23 : alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1)))) {
                        {
                            (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                            (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")), alg_string("alg_nil()")}, 2));
                        }
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "VarGroupStmt"))) {
                        {
                            Value v_J = alg_int(0);
                            (void)v_J;
                            while (alg_truthy(alg_less(v_J, alg_property(alg_property(v_TheStmt, "Names"), "Length")))) {
                                {
                                    if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_J), "Lexeme"))}, 1))) {
                                        {
                                            (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_J), "Lexeme"))}, 1));
                                            (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_J), "Lexeme")), alg_string("alg_nil()")}, 2));
                                        }
                                    }
                                    (void)((v_J = alg_add(v_J, alg_int(1))));
                                }
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

static Value m_CEmitter_EmitHandlerBody_2_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Handler = args[0];
    (void)v_Handler;
    Value v_Frame = args[1];
    (void)v_Frame;
    Value v_Mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_Mark;
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(v_Handler, "Name"))}, 1));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(v_Handler, "Name"))}, 1))) {
        (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_str(alg_property(v_Handler, "Name")), alg_add(v_Frame, alg_string(".raised"))}, 2));
    } else {
        {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(v_Handler, "Name"))}, 1)), alg_string(" = ")), v_Frame), alg_string(".raised;"))}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(v_Handler, "Name"))}, 1)), alg_char_value(59))}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_Handler, "Body")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_Mark}, 1));
    return alg_nil();
}

static Value m_CEmitter_DeclaredTypes_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheMethod = args[0];
    (void)v_TheMethod;
    Value v_Types = alg_nil();
    (void)v_Types;
    (void)((v_Types = alg_list()));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheMethod, "Params"), "Length")))) {
            {
                {
                    Value v_Declared = alg_str(alg_subscript_get(alg_property(v_TheMethod, "ParamTypes"), v_I));
                    (void)v_Declared;
                    if (alg_truthy(alg_equal(v_Declared, alg_string("")))) {
                        (void)((v_Declared = alg_string("Any")));
                    }
                    (void)(alg_invoke(v_Types, "Add", (Value[]){v_Declared}, 1));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Types;
    return alg_nil();
}

static Value m_CEmitter_MethodSymbol_2_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Owner = args[0];
    (void)v_Owner;
    Value v_TheMethod = args[1];
    (void)v_TheMethod;
    Value v_Symbol = alg_nil();
    (void)v_Symbol;
    (void)((v_Symbol = alg_add(alg_add(alg_invoke(v_this, "SymbolOf", (Value[]){alg_string("m_"), alg_add(alg_add(v_Owner, alg_char_value(95)), alg_str(alg_property(alg_property(v_TheMethod, "Name"), "Lexeme")))}, 2), alg_char_value(95)), alg_str(alg_property(alg_property(v_TheMethod, "Params"), "Length")))));
    Value v_Types = alg_invoke(v_this, "DeclaredTypes", (Value[]){v_TheMethod}, 1);
    (void)v_Types;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Types, "Length")))) {
            {
                if (alg_truthy(alg_not_equal(alg_subscript_get(v_Types, v_I), alg_string("Any")))) {
                    (void)((v_Symbol = alg_add(alg_add(v_Symbol, alg_char_value(95)), alg_invoke(v_this, "QuestionsOut", (Value[]){alg_str(alg_subscript_get(v_Types, v_I))}, 1))));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Symbol;
    return alg_nil();
}

static Value m_CEmitter_NamesVisible_3_String_List_Boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_SuperName = args[0];
    (void)v_SuperName;
    Value v_Own = args[1];
    (void)v_Own;
    Value v_Fields = args[2];
    (void)v_Fields;
    Value v_Names = alg_nil();
    (void)v_Names;
    Value v_At = alg_nil();
    (void)v_At;
    (void)((v_Names = alg_set()));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Own, "Length")))) {
            {
                (void)(alg_invoke(v_Names, "Add", (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(v_Own, v_I), "Name"), "Lexeme"))}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)((v_At = v_SuperName));
    while (alg_truthy(alg_not_equal(v_At, alg_string("")))) {
        {
            if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_At}, 1)))) {
                return v_Names;
            }
            Value v_Ancestor = alg_invoke(alg_property(v_this, "Classes"), "Get", (Value[]){v_At}, 1);
            (void)v_Ancestor;
            Value v_Inherited = alg_property(v_Ancestor, "Methods");
            (void)v_Inherited;
            if (alg_truthy(v_Fields)) {
                (void)((v_Inherited = alg_property(v_Ancestor, "Fields")));
            }
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(v_Inherited, "Length")))) {
                    {
                        (void)(alg_invoke(v_Names, "Add", (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(v_Inherited, v_I), "Name"), "Lexeme"))}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            (void)((v_At = alg_string("")));
            if (alg_truthy(alg_not_equal(alg_property(v_Ancestor, "Superclass"), alg_nil()))) {
                (void)((v_At = alg_str(alg_property(alg_property(alg_property(v_Ancestor, "Superclass"), "Name"), "Lexeme"))));
            }
        }
    }
    return v_Names;
    return alg_nil();
}

static Value m_CEmitter_EmitMethod_2_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Owner = args[0];
    (void)v_Owner;
    Value v_TheMethod = args[1];
    (void)v_TheMethod;
    Value v_EnclosingLocals = alg_nil();
    (void)v_EnclosingLocals;
    Value v_EnclosingTop = alg_nil();
    (void)v_EnclosingTop;
    Value v_EnclosingDepth = alg_nil();
    (void)v_EnclosingDepth;
    Value v_Opening = alg_nil();
    (void)v_Opening;
    (void)((v_EnclosingLocals = alg_property(v_this, "Locals")));
    (void)((v_EnclosingTop = alg_property(v_this, "AtTopLevel")));
    (void)((v_EnclosingDepth = alg_property(v_this, "Depth")));
    (void)(alg_set_property(v_this, "Locals", alg_list()));
    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
    Value v_EnclosingTarget = alg_property(v_this, "Target");
    (void)v_EnclosingTarget;
    Value v_EnclosingBody = alg_property(v_this, "Body");
    (void)v_EnclosingBody;
    (void)(alg_set_property(v_this, "Target", alg_string("body")));
    (void)(alg_set_property(v_this, "Body", alg_buffer(alg_int(0))));
    (void)(alg_set_property(v_this, "Depth", alg_int(1)));
    Value v_EnclosingVolatiles = alg_property(v_this, "Volatiles");
    (void)v_EnclosingVolatiles;
    (void)(alg_set_property(v_this, "Volatiles", alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_TheMethod, "Body")}, 1)));
    Value v_EnclosingBoxed = alg_property(v_this, "Boxed");
    (void)v_EnclosingBoxed;
    Value v_EnclosingCaptured = alg_property(v_this, "Captured");
    (void)v_EnclosingCaptured;
    Value v_EnclosingCells = alg_property(v_this, "Cells");
    (void)v_EnclosingCells;
    (void)(alg_set_property(v_this, "Boxed", alg_list()));
    (void)(alg_set_property(v_this, "Captured", alg_map()));
    (void)(alg_set_property(v_this, "Cells", alg_list()));
    Value v_EnclosingTryDepth = alg_property(v_this, "TryDepth");
    (void)v_EnclosingTryDepth;
    Value v_EnclosingLoopTry = alg_property(v_this, "LoopTryDepth");
    (void)v_EnclosingLoopTry;
    (void)(alg_set_property(v_this, "TryDepth", alg_int(0)));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_int(0)));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheMethod, "Params"), "Length")))) {
            {
                {
                    Value v_Name = alg_str(alg_property(alg_subscript_get(alg_property(v_TheMethod, "Params"), v_I), "Lexeme"));
                    (void)v_Name;
                    (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_Name}, 1));
                    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){v_Name}, 1)), alg_string(" = args[")), alg_str(v_I)), alg_string("];"))}, 1));
                    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "VariableName", (Value[]){v_Name}, 1)), alg_char_value(59))}, 1));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheMethod, "Body"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(alg_property(v_TheMethod, "Body"), v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("return alg_nil();")}, 1));
    Value v_Written = alg_property(alg_property(v_this, "Body"), "Text");
    (void)v_Written;
    (void)(alg_set_property(v_this, "Target", v_EnclosingTarget));
    (void)(alg_set_property(v_this, "Body", v_EnclosingBody));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), alg_invoke(v_this, "MethodSymbol", (Value[]){v_Owner, v_TheMethod}, 2)), alg_string("(Value v_this, Value *args, int32_t count) {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)v_this; (void)args; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_Written}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_char_value(125), alg_char_value(10)), alg_char_value(10))}, 1));
    (void)(alg_set_property(v_this, "Depth", v_EnclosingDepth));
    (void)(alg_set_property(v_this, "AtTopLevel", v_EnclosingTop));
    (void)(alg_set_property(v_this, "Locals", v_EnclosingLocals));
    (void)(alg_set_property(v_this, "Volatiles", v_EnclosingVolatiles));
    (void)(alg_set_property(v_this, "Boxed", v_EnclosingBoxed));
    (void)(alg_set_property(v_this, "Captured", v_EnclosingCaptured));
    (void)(alg_set_property(v_this, "Cells", v_EnclosingCells));
    (void)(alg_set_property(v_this, "TryDepth", v_EnclosingTryDepth));
    (void)(alg_set_property(v_this, "LoopTryDepth", v_EnclosingLoopTry));
    return alg_nil();
}

static Value m_CEmitter_EmitClass_5_String_List_List_Boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Superclass = args[1];
    (void)v_Superclass;
    Value v_Fields = args[2];
    (void)v_Fields;
    Value v_Methods = args[3];
    (void)v_Methods;
    Value v_IsObject = args[4];
    (void)v_IsObject;
    Value v_Handle = alg_nil();
    (void)v_Handle;
    Value v_SuperName = alg_nil();
    (void)v_SuperName;
    Value v_Applied = alg_nil();
    (void)v_Applied;
    Value v_Initializer = alg_nil();
    (void)v_Initializer;
    Value v_EnclosingClass = alg_nil();
    (void)v_EnclosingClass;
    Value v_EnclosingFields = alg_nil();
    (void)v_EnclosingFields;
    Value v_EnclosingMethods = alg_nil();
    (void)v_EnclosingMethods;
    (void)((v_Handle = alg_invoke(v_this, "ClassHandle", (Value[]){v_Name}, 1)));
    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){v_Handle, v_Name}, 2));
    (void)((v_EnclosingClass = alg_property(v_this, "CurrentClass")));
    (void)((v_EnclosingFields = alg_property(v_this, "VisibleFields")));
    (void)((v_EnclosingMethods = alg_property(v_this, "VisibleMethods")));
    (void)((v_SuperName = alg_string("")));
    if (alg_truthy(alg_not_equal(v_Superclass, alg_nil()))) {
        (void)((v_SuperName = alg_str(alg_property(alg_property(v_Superclass, "Name"), "Lexeme"))));
    }
    (void)(alg_set_property(v_this, "CurrentClass", v_Name));
    (void)(alg_set_property(v_this, "VisibleFields", alg_invoke(v_this, "NamesVisible", (Value[]){v_SuperName, v_Fields, alg_bool(true)}, 3)));
    (void)(alg_set_property(v_this, "VisibleMethods", alg_invoke(v_this, "NamesVisible", (Value[]){v_SuperName, v_Methods, alg_bool(false)}, 3)));
    Value v_DeclaresId = alg_bool(false);
    (void)v_DeclaresId;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Fields, "Length")))) {
            {
                if (alg_truthy(alg_equal(alg_str(alg_property(alg_property(alg_subscript_get(v_Fields, v_I), "Name"), "Lexeme")), alg_string("Id")))) {
                    (void)((v_DeclaresId = alg_bool(true)));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    Value v_AddId = (or_24 = v_IsObject, !alg_truthy(or_24) ? or_24 : alg_not(v_DeclaresId));
    (void)v_AddId;
    if (alg_truthy(v_AddId)) {
        (void)(alg_invoke(alg_property(v_this, "VisibleFields"), "Add", (Value[]){alg_string("Id")}, 1));
    }
    (void)((v_Applied = alg_string("")));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Fields, "Length")))) {
            {
                {
                    Value v_Value = alg_string("alg_nil()");
                    (void)v_Value;
                    if (alg_truthy(alg_not_equal(alg_property(alg_subscript_get(v_Fields, v_I), "Initializer"), alg_nil()))) {
                        (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(alg_subscript_get(v_Fields, v_I), "Initializer")}, 1)));
                    }
                    (void)((v_Applied = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(v_Applied, alg_string("    alg_set_property(v_this, ")), f_QuoteC(NULL, (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(v_Fields, v_I), "Name"), "Lexeme"))}, 1)), alg_string(", ")), v_Value), alg_string(");")), alg_char_value(10))));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    if (alg_truthy(v_AddId)) {
        (void)((v_Applied = alg_add(alg_add(alg_add(alg_add(v_Applied, alg_string("    alg_set_property(v_this, \"Id\", alg_string(")), f_QuoteC(NULL, (Value[]){v_Name}, 1)), alg_string("));")), alg_char_value(10))));
    }
    (void)((v_Initializer = alg_invoke(v_this, "InitName", (Value[]){v_Name}, 1)));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_Initializer), alg_string("(Value v_this, Value *args, int32_t count) {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)v_this; (void)args; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_Applied}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("    return alg_nil();"), alg_char_value(10)), alg_char_value(125)), alg_char_value(10)), alg_char_value(10))}, 1));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Methods, "Length")))) {
            {
                (void)(alg_invoke(v_this, "EmitMethod", (Value[]){v_Name, alg_subscript_get(v_Methods, v_I)}, 2));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_set_property(v_this, "CurrentClass", v_EnclosingClass));
    (void)(alg_set_property(v_this, "VisibleFields", v_EnclosingFields));
    (void)(alg_set_property(v_this, "VisibleMethods", v_EnclosingMethods));
    Value v_SuperHandle = alg_string("alg_nil()");
    (void)v_SuperHandle;
    if (alg_truthy(alg_not_equal(v_SuperName, alg_string("")))) {
        (void)((v_SuperHandle = alg_invoke(v_this, "ClassHandle", (Value[]){v_SuperName}, 1)));
    }
    (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), v_Handle), alg_string(" = alg_class(")), f_QuoteC(NULL, (Value[]){v_Name}, 1)), alg_string(", ")), v_SuperHandle), alg_string(");")), alg_char_value(10))}, 1));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Fields, "Length")))) {
            {
                (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_class_field("), v_Handle), alg_string(", ")), f_QuoteC(NULL, (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(v_Fields, v_I), "Name"), "Lexeme"))}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    if (alg_truthy(v_AddId)) {
        (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("    alg_class_field("), v_Handle), alg_string(", \"Id\");")), alg_char_value(10))}, 1));
    }
    (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_class_initializer("), v_Handle), alg_string(", ")), v_Initializer), alg_string(");")), alg_char_value(10))}, 1));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Methods, "Length")))) {
            {
                {
                    Value v_TheMethod = alg_subscript_get(v_Methods, v_I);
                    (void)v_TheMethod;
                    Value v_Types = alg_invoke(v_this, "DeclaredTypes", (Value[]){v_TheMethod}, 1);
                    (void)v_Types;
                    Value v_Table = alg_string("NULL");
                    (void)v_Table;
                    Value v_AnyDeclared = alg_bool(false);
                    (void)v_AnyDeclared;
                    {
                        Value v_J = alg_int(0);
                        (void)v_J;
                        while (alg_truthy(alg_less(v_J, alg_property(v_Types, "Length")))) {
                            {
                                if (alg_truthy(alg_not_equal(alg_subscript_get(v_Types, v_J), alg_string("Any")))) {
                                    (void)((v_AnyDeclared = alg_bool(true)));
                                }
                                (void)((v_J = alg_add(v_J, alg_int(1))));
                            }
                        }
                    }
                    if (alg_truthy(alg_greater(alg_property(v_Types, "Length"), alg_int(0)))) {
                        {
                            (void)((v_Table = alg_add(alg_string("t_"), alg_copy(alg_invoke(v_this, "MethodSymbol", (Value[]){v_Name, v_TheMethod}, 2), alg_int(2), alg_subtract(alg_length(alg_invoke(v_this, "MethodSymbol", (Value[]){v_Name, v_TheMethod}, 2)), alg_int(2))))));
                            Value v_Quoted = alg_string("");
                            (void)v_Quoted;
                            {
                                Value v_J = alg_int(0);
                                (void)v_J;
                                while (alg_truthy(alg_less(v_J, alg_property(v_Types, "Length")))) {
                                    {
                                        {
                                            if (alg_truthy(alg_greater(v_J, alg_int(0)))) {
                                                (void)((v_Quoted = alg_add(v_Quoted, alg_string(", "))));
                                            }
                                            (void)((v_Quoted = alg_add(v_Quoted, f_QuoteC(NULL, (Value[]){alg_str(alg_subscript_get(v_Types, v_J))}, 1))));
                                        }
                                        (void)((v_J = alg_add(v_J, alg_int(1))));
                                    }
                                }
                            }
                            (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("static const char *"), v_Table), alg_string("[] = { ")), v_Quoted), alg_string(" };")), alg_char_value(10))}, 1));
                        }
                    }
                    (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_class_method("), v_Handle), alg_string(", ")), f_QuoteC(NULL, (Value[]){alg_str(alg_property(alg_property(v_TheMethod, "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "MethodSymbol", (Value[]){v_Name, v_TheMethod}, 2)), alg_string(", ")), alg_str(alg_property(alg_property(v_TheMethod, "Params"), "Length"))), alg_string(", ")), v_Table), alg_string(");")), alg_char_value(10))}, 1));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    if (alg_truthy(v_IsObject)) {
        (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("    alg_class_is_object("), v_Handle), alg_string(");")), alg_char_value(10))}, 1));
    }
    return alg_nil();
}

static Value m_CEmitter_VisitVarStmt_1_VarStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Value = alg_nil();
    (void)v_Value;
    (void)((v_Value = alg_string("alg_nil()")));
    if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Initializer"), alg_nil()))) {
        (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Initializer")}, 1)));
    }
    if (alg_truthy(alg_property(v_this, "AtTopLevel"))) {
        {
            (void)(alg_invoke(v_this, "DeclareValue", (Value[]){alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1), alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 2));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1), alg_string(" = ")), v_Value), alg_char_value(59))}, 1));
        }
    } else {
        if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1))) {
            {
                (void)(alg_invoke(v_this, "RequireCell", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_char_value(42), alg_invoke(v_this, "Cell", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1)), alg_string(" = ")), v_Value), alg_char_value(59))}, 1));
            }
        } else {
            {
                (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1)), alg_string(" = ")), v_Value), alg_char_value(59))}, 1));
                (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1)), alg_char_value(59))}, 1));
            }
        }
    }
    return alg_nil();
}

static Value m_CEmitter_VisitExpressionStmt_1_ExpressionStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Expression")}, 1)), alg_string(");"))}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitBlockStmt_1_BlockStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_Mark;
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "HoistCells", (Value[]){alg_property(v_TheStmt, "Statements")}, 1));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Statements"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(alg_property(v_TheStmt, "Statements"), v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_Mark}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitIfStmt_1_IfStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    (void)(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_property(v_TheStmt, "ThenBranch")}, 1));
    if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "ElseBranch"), alg_nil()))) {
        (void)(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_property(v_TheStmt, "ElseBranch")}, 1));
    }
    Value v_Mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_Mark;
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("if (alg_truthy("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Condition")}, 1)), alg_string(")) {"))}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_TheStmt, "ThenBranch")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_Mark}, 1));
    if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "ElseBranch"), alg_nil()))) {
        {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("} else {")}, 1));
            (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
            (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_TheStmt, "ElseBranch")}, 1));
            (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
            (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_Mark}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitWhileStmt_1_WhileStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    (void)(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_property(v_TheStmt, "Body")}, 1));
    Value v_Mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_Mark;
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("while (alg_truthy("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Condition")}, 1)), alg_string(")) {"))}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    Value v_EnclosingLoopDepth = alg_property(v_this, "LoopTryDepth");
    (void)v_EnclosingLoopDepth;
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_property(v_this, "TryDepth")));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_TheStmt, "Body")}, 1));
    (void)(alg_set_property(v_this, "LoopTryDepth", v_EnclosingLoopDepth));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_Mark}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitPrintStmt_1_PrintStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_writeln("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Expression")}, 1)), alg_string(");"))}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitReturnStmt_1_ReturnStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Value = alg_nil();
    (void)v_Value;
    (void)((v_Value = alg_string("alg_nil()")));
    if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Value"), alg_nil()))) {
        (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Value")}, 1)));
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "TryDepth"), alg_int(0)))) {
        {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("return "), v_Value), alg_char_value(59))}, 1));
            return alg_nil();
        }
    }
    Value v_Slot = alg_add(alg_string("ret_"), alg_str(alg_property(v_this, "Loops")));
    (void)v_Slot;
    (void)(alg_set_property(v_this, "Loops", alg_add(alg_property(v_this, "Loops"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), v_Slot), alg_string(" = ")), v_Value), alg_char_value(59))}, 1));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_this, "TryDepth")))) {
            {
                (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("alg_pop_frame();")}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("return "), v_Slot), alg_char_value(59))}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitFunctionStmt_1_FunctionStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_EnclosingLocals = alg_nil();
    (void)v_EnclosingLocals;
    Value v_EnclosingTop = alg_nil();
    (void)v_EnclosingTop;
    Value v_EnclosingDepth = alg_nil();
    (void)v_EnclosingDepth;
    if (alg_truthy(alg_invoke(v_this, "IsTest", (Value[]){v_TheStmt}, 1))) {
        {
            if (alg_truthy(alg_property(v_this, "EmitTests"))) {
                (void)(alg_invoke(v_this, "EmitTest", (Value[]){v_TheStmt}, 1));
            }
            return alg_nil();
        }
    }
    Value v_Nested = alg_not(alg_property(v_this, "AtTopLevel"));
    (void)v_Nested;
    if (alg_truthy((or_25 = v_Nested, !alg_truthy(or_25) ? or_25 : alg_property(v_this, "InsideNested")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("A function nested more than one level deep")}, 1));
    }
    if (alg_truthy((or_26 = v_Nested, !alg_truthy(or_26) ? or_26 : alg_not_equal(alg_property(v_this, "CurrentClass"), alg_string(""))))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("A function declared inside a method")}, 1));
    }
    (void)((v_EnclosingLocals = alg_property(v_this, "Locals")));
    (void)((v_EnclosingTop = alg_property(v_this, "AtTopLevel")));
    (void)((v_EnclosingDepth = alg_property(v_this, "Depth")));
    Value v_EnclosingBoxed = alg_property(v_this, "Boxed");
    (void)v_EnclosingBoxed;
    Value v_EnclosingCaptured = alg_property(v_this, "Captured");
    (void)v_EnclosingCaptured;
    Value v_EnclosingCells = alg_property(v_this, "Cells");
    (void)v_EnclosingCells;
    Value v_EnclosingNested = alg_property(v_this, "InsideNested");
    (void)v_EnclosingNested;
    (void)(alg_set_property(v_this, "Locals", alg_list()));
    if (alg_truthy(v_Nested)) {
        {
            Value v_Index = alg_map();
            (void)v_Index;
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(v_EnclosingCells, "Length")))) {
                    {
                        (void)(alg_invoke(v_Index, "Put", (Value[]){alg_str(alg_subscript_get(v_EnclosingCells, v_I)), v_I}, 2));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            (void)(alg_set_property(v_this, "Captured", v_Index));
            (void)(alg_set_property(v_this, "InsideNested", alg_bool(true)));
        }
    } else {
        (void)(alg_set_property(v_this, "Captured", alg_map()));
    }
    (void)(alg_set_property(v_this, "Cells", alg_list()));
    Value v_EnclosingVolatiles = alg_property(v_this, "Volatiles");
    (void)v_EnclosingVolatiles;
    (void)(alg_set_property(v_this, "Volatiles", alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_TheStmt, "Body")}, 1)));
    Value v_EnclosingTryDepth = alg_property(v_this, "TryDepth");
    (void)v_EnclosingTryDepth;
    Value v_EnclosingLoopTry = alg_property(v_this, "LoopTryDepth");
    (void)v_EnclosingLoopTry;
    (void)(alg_set_property(v_this, "TryDepth", alg_int(0)));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_int(0)));
    (void)(alg_set_property(v_this, "Boxed", alg_list()));
    if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_property(v_TheStmt, "Body")}, 1))) {
        (void)(alg_set_property(v_this, "Boxed", alg_invoke(v_this, "BoundNames", (Value[]){v_TheStmt}, 1)));
    }
    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
    Value v_EnclosingTarget = alg_property(v_this, "Target");
    (void)v_EnclosingTarget;
    Value v_EnclosingBody = alg_property(v_this, "Body");
    (void)v_EnclosingBody;
    (void)(alg_set_property(v_this, "Target", alg_string("body")));
    (void)(alg_set_property(v_this, "Body", alg_buffer(alg_int(0))));
    (void)(alg_set_property(v_this, "Depth", alg_int(1)));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Params"), "Length")))) {
            {
                {
                    Value v_ParamName = alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Params"), v_I), "Lexeme"));
                    (void)v_ParamName;
                    (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_ParamName}, 1));
                    if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_ParamName}, 1))) {
                        {
                            Value v_Qualifier = alg_string("Value *");
                            (void)v_Qualifier;
                            if (alg_truthy(alg_property(v_this, "Volatiles"))) {
                                (void)((v_Qualifier = alg_string("Value *volatile ")));
                            }
                            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(v_Qualifier, alg_invoke(v_this, "Cell", (Value[]){v_ParamName}, 1)), alg_string(" = alg_cell(args[")), alg_str(v_I)), alg_string("]);"))}, 1));
                            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "Cell", (Value[]){v_ParamName}, 1)), alg_char_value(59))}, 1));
                            (void)(alg_invoke(alg_property(v_this, "Cells"), "Add", (Value[]){v_ParamName}, 1));
                        }
                    } else {
                        {
                            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){v_ParamName}, 1)), alg_string(" = args[")), alg_str(v_I)), alg_string("];"))}, 1));
                            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "VariableName", (Value[]){v_ParamName}, 1)), alg_char_value(59))}, 1));
                        }
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "HoistCells", (Value[]){alg_property(v_TheStmt, "Body")}, 1));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Body"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(alg_property(v_TheStmt, "Body"), v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("return alg_nil();")}, 1));
    Value v_Written = alg_property(alg_property(v_this, "Body"), "Text");
    (void)v_Written;
    (void)(alg_set_property(v_this, "Target", v_EnclosingTarget));
    (void)(alg_set_property(v_this, "Body", v_EnclosingBody));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_invoke(v_this, "Prototype", (Value[]){v_TheStmt}, 1), alg_string(" {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)cells; (void)args; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_Written}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_char_value(125), alg_char_value(10)), alg_char_value(10))}, 1));
    Value v_CapturedCells = v_EnclosingCells;
    (void)v_CapturedCells;
    (void)(alg_set_property(v_this, "Depth", v_EnclosingDepth));
    (void)(alg_set_property(v_this, "AtTopLevel", v_EnclosingTop));
    (void)(alg_set_property(v_this, "Locals", v_EnclosingLocals));
    (void)(alg_set_property(v_this, "Volatiles", v_EnclosingVolatiles));
    (void)(alg_set_property(v_this, "Boxed", v_EnclosingBoxed));
    (void)(alg_set_property(v_this, "Captured", v_EnclosingCaptured));
    (void)(alg_set_property(v_this, "Cells", v_EnclosingCells));
    (void)(alg_set_property(v_this, "TryDepth", v_EnclosingTryDepth));
    (void)(alg_set_property(v_this, "LoopTryDepth", v_EnclosingLoopTry));
    (void)(alg_set_property(v_this, "InsideNested", v_EnclosingNested));
    Value v_Name = alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"));
    (void)v_Name;
    if (alg_truthy(v_Nested)) {
        {
            (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_Name}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){v_Name}, 1)), alg_string(" = ")), alg_invoke(v_this, "ClosureOf", (Value[]){v_TheStmt, v_CapturedCells}, 2)), alg_char_value(59))}, 1));
        }
    } else {
        {
            (void)(alg_invoke(v_this, "DeclareValue", (Value[]){alg_invoke(v_this, "HandleName", (Value[]){v_Name}, 1), v_Name}, 2));
            (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), alg_invoke(v_this, "HandleName", (Value[]){v_Name}, 1)), alg_string(" = ")), alg_invoke(v_this, "ClosureOf", (Value[]){v_TheStmt, alg_list()}, 2)), alg_char_value(59)), alg_char_value(10))}, 1));
        }
    }
    return alg_nil();
}

static Value m_CEmitter_VisitLiteral_1_LiteralExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Value = alg_nil();
    (void)v_Value;
    (void)((v_Value = alg_property(v_TheExpr, "Value")));
    if (alg_truthy(alg_equal(v_Value, alg_nil()))) {
        return alg_string("alg_nil()");
    }
    if (alg_truthy(alg_equal(v_Value, alg_bool(true)))) {
        return alg_string("alg_bool(true)");
    }
    if (alg_truthy(alg_equal(v_Value, alg_bool(false)))) {
        return alg_string("alg_bool(false)");
    }
    if (alg_truthy(alg_is(v_Value, "Integer"))) {
        return alg_add(alg_add(alg_string("alg_int("), alg_str(v_Value)), alg_char_value(41));
    }
    if (alg_truthy(alg_is(v_Value, "Double"))) {
        return alg_add(alg_add(alg_string("alg_double("), alg_str(v_Value)), alg_char_value(41));
    }
    if (alg_truthy(alg_is(v_Value, "String"))) {
        return alg_add(alg_add(alg_string("alg_string("), f_QuoteC(NULL, (Value[]){alg_str(v_Value)}, 1)), alg_char_value(41));
    }
    if (alg_truthy(alg_is(v_Value, "Char"))) {
        return alg_add(alg_add(alg_string("alg_char_value("), alg_str(alg_ord(v_Value))), alg_char_value(41));
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_string("A literal of type "), f_TypeNameOf(NULL, (Value[]){v_Value}, 1))}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitVariableExpr_1_VariableExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Name = alg_nil();
    (void)v_Name;
    (void)((v_Name = alg_str(alg_property(alg_property(v_TheExpr, "Name"), "Lexeme"))));
    if (alg_truthy((or_27 = alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_Name}, 1), alg_truthy(or_27) ? or_27 : alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_Name}, 1)))) {
        return alg_invoke(v_this, "Read", (Value[]){v_Name}, 1);
    }
    if (alg_truthy((or_29 = (or_28 = alg_not_equal(alg_property(v_this, "CurrentClass"), alg_string("")), !alg_truthy(or_28) ? or_28 : alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_Name}, 1))), !alg_truthy(or_29) ? or_29 : alg_invoke(alg_property(v_this, "VisibleFields"), "Contains", (Value[]){v_Name}, 1)))) {
        return alg_add(alg_add(alg_string("alg_property(v_this, "), f_QuoteC(NULL, (Value[]){v_Name}, 1)), alg_char_value(41));
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_Name}, 1)))) {
        {
            if (alg_truthy(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_Name}, 1))) {
                return alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_Name}, 1));
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "EnumTypes"), "Contains", (Value[]){v_Name}, 1))) {
                return alg_invoke(v_this, "EnumTypeName", (Value[]){v_Name}, 1);
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){v_Name}, 1))) {
                return alg_add(alg_add(alg_string("alg_singleton("), alg_invoke(v_this, "ClassHandle", (Value[]){v_Name}, 1)), alg_char_value(41));
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_Name}, 1))) {
                return alg_invoke(v_this, "HandleName", (Value[]){v_Name}, 1);
            }
        }
    }
    (void)(alg_invoke(v_this, "Unreachable", (Value[]){v_Name}, 1));
    return alg_invoke(v_this, "VariableName", (Value[]){v_Name}, 1);
    return alg_nil();
}

static Value m_CEmitter_Unreachable_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    if (alg_truthy(alg_not(alg_property(v_this, "InsideNested")))) {
        return alg_nil();
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_nil();
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_nil();
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("Reading '"), v_Name), alg_string("' from a nested function"))}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitAssignExpr_1_AssignExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Name = alg_nil();
    (void)v_Name;
    (void)((v_Name = alg_str(alg_property(alg_property(v_TheExpr, "Name"), "Lexeme"))));
    if (alg_truthy((or_30 = alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_Name}, 1), alg_truthy(or_30) ? or_30 : alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_Name}, 1)))) {
        return alg_add(alg_add(alg_add(alg_add(alg_char_value(40), alg_invoke(v_this, "Read", (Value[]){v_Name}, 1)), alg_string(" = ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Value")}, 1)), alg_char_value(41));
    }
    if (alg_truthy((or_32 = (or_31 = alg_not_equal(alg_property(v_this, "CurrentClass"), alg_string("")), !alg_truthy(or_31) ? or_31 : alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_Name}, 1))), !alg_truthy(or_32) ? or_32 : alg_invoke(alg_property(v_this, "VisibleFields"), "Contains", (Value[]){v_Name}, 1)))) {
        return alg_add(alg_add(alg_add(alg_add(alg_string("alg_set_property(v_this, "), f_QuoteC(NULL, (Value[]){v_Name}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Value")}, 1)), alg_char_value(41));
    }
    (void)(alg_invoke(v_this, "Unreachable", (Value[]){v_Name}, 1));
    return alg_add(alg_add(alg_add(alg_add(alg_char_value(40), alg_invoke(v_this, "VariableName", (Value[]){v_Name}, 1)), alg_string(" = ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Value")}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_CEmitter_VisitGrouping_1_GroupingExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    return alg_add(alg_add(alg_char_value(40), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Expression")}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_CEmitter_VisitIsExpr_1_IsExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    return alg_add(alg_add(alg_add(alg_add(alg_string("alg_is("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Obj")}, 1)), alg_string(", ")), f_QuoteC(NULL, (Value[]){alg_str(alg_property(alg_property(v_TheExpr, "TypeName"), "Lexeme"))}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_CEmitter_VisitUnary_1_UnaryExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Operand = alg_nil();
    (void)v_Operand;
    (void)((v_Operand = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Right")}, 1)));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_MINUS))) {
        return alg_add(alg_add(alg_string("alg_negate("), v_Operand), alg_char_value(41));
    } else {
        if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_NOT))) {
            return alg_add(alg_add(alg_string("alg_not("), v_Operand), alg_char_value(41));
        }
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("Unary '"), alg_str(alg_property(alg_property(v_TheExpr, "Op"), "Lexeme"))), alg_string("'"))}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitBinary_1_BinaryExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Left = alg_nil();
    (void)v_Left;
    Value v_Right = alg_nil();
    (void)v_Right;
    Value v_Call = alg_nil();
    (void)v_Call;
    (void)((v_Left = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Left")}, 1)));
    (void)((v_Right = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Right")}, 1)));
    (void)((v_Call = alg_string("")));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_PLUS))) {
        (void)((v_Call = alg_string("alg_add")));
    } else {
        if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_MINUS))) {
            (void)((v_Call = alg_string("alg_subtract")));
        } else {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_STAR))) {
                (void)((v_Call = alg_string("alg_multiply")));
            } else {
                if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_SLASH))) {
                    (void)((v_Call = alg_string("alg_divide")));
                } else {
                    if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_GREATER))) {
                        (void)((v_Call = alg_string("alg_greater")));
                    } else {
                        if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_GREATER_EQUAL))) {
                            (void)((v_Call = alg_string("alg_greater_equal")));
                        } else {
                            if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_LESS))) {
                                (void)((v_Call = alg_string("alg_less")));
                            } else {
                                if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_LESS_EQUAL))) {
                                    (void)((v_Call = alg_string("alg_less_equal")));
                                } else {
                                    if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_EQUAL))) {
                                        (void)((v_Call = alg_string("alg_equal")));
                                    } else {
                                        if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_NOT_EQUAL))) {
                                            (void)((v_Call = alg_string("alg_not_equal")));
                                        } else {
                                            if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_IN))) {
                                                (void)((v_Call = alg_string("alg_in")));
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
    if (alg_truthy(alg_equal(v_Call, alg_string("")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("Binary '"), alg_str(alg_property(alg_property(v_TheExpr, "Op"), "Lexeme"))), alg_string("'"))}, 1));
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(v_Call, alg_char_value(40)), v_Left), alg_string(", ")), v_Right), alg_char_value(41));
    return alg_nil();
}

static Value m_CEmitter_Builtin_2_String_Integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Count = args[1];
    (void)v_Count;
    Value v_Key = alg_nil();
    (void)v_Key;
    (void)((v_Key = alg_add(alg_add(v_Name, alg_char_value(47)), alg_str(v_Count))));
    if (alg_truthy(alg_equal(v_Key, alg_string("WriteLn/1")))) {
        return alg_string("alg_writeln");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("Write/1")))) {
        return alg_string("alg_write");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("Str/1")))) {
        return alg_string("alg_str");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("Length/1")))) {
        return alg_string("alg_length");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("Copy/3")))) {
        return alg_string("alg_copy");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("Pos/2")))) {
        return alg_string("alg_pos");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("Char/1")))) {
        return alg_string("alg_char");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("Ord/1")))) {
        return alg_string("alg_ord");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("Val/1")))) {
        return alg_string("alg_val");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("Max/2")))) {
        return alg_string("alg_max");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("Mod/2")))) {
        return alg_string("alg_mod");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("clock/0")))) {
        return alg_string("alg_clock");
    }
    if (alg_truthy(alg_property(v_this, "EmitTests"))) {
        {
            if (alg_truthy(alg_equal(v_Key, alg_string("AssertTrue/1")))) {
                return alg_string("alg_assert_true");
            }
            if (alg_truthy(alg_equal(v_Key, alg_string("AssertEqual/2")))) {
                return alg_string("alg_assert_equal");
            }
            if (alg_truthy(alg_equal(v_Key, alg_string("Fail/1")))) {
                return alg_string("alg_assert_fail");
            }
        }
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("FileExists/1")))) {
        return alg_string("alg_file_exists");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("ParamCount/0")))) {
        return alg_string("alg_param_count");
    }
    if (alg_truthy(alg_equal(v_Key, alg_string("ParamStr/1")))) {
        return alg_string("alg_param_str");
    }
    return alg_string("");
    return alg_nil();
}

static Value m_CEmitter_ArgumentArray_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Arguments = args[0];
    (void)v_Arguments;
    Value v_Joined = alg_string("");
    (void)v_Joined;
    if (alg_truthy(alg_equal(alg_property(v_Arguments, "Length"), alg_int(0)))) {
        return alg_string("NULL, 0");
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Arguments, "Length")))) {
            {
                {
                    if (alg_truthy(alg_greater(v_I, alg_int(0)))) {
                        (void)((v_Joined = alg_add(v_Joined, alg_string(", "))));
                    }
                    (void)((v_Joined = alg_add(v_Joined, alg_str(alg_subscript_get(v_Arguments, v_I)))));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_add(alg_add(alg_add(alg_string("(Value[]){"), v_Joined), alg_string("}, ")), alg_str(alg_property(v_Arguments, "Length")));
    return alg_nil();
}

static Value m_CEmitter_ConstructorFor_3_String_List_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    Value v_Joined = args[2];
    (void)v_Joined;
    if (alg_truthy((or_33 = alg_equal(v_Name, alg_string("List")), !alg_truthy(or_33) ? or_33 : alg_equal(alg_property(v_Arguments, "Length"), alg_int(0))))) {
        return alg_string("alg_list()");
    }
    if (alg_truthy((or_34 = alg_equal(v_Name, alg_string("Map")), !alg_truthy(or_34) ? or_34 : alg_equal(alg_property(v_Arguments, "Length"), alg_int(0))))) {
        return alg_string("alg_map()");
    }
    if (alg_truthy((or_35 = alg_equal(v_Name, alg_string("Stack")), !alg_truthy(or_35) ? or_35 : alg_equal(alg_property(v_Arguments, "Length"), alg_int(0))))) {
        return alg_string("alg_stack()");
    }
    if (alg_truthy((or_36 = alg_equal(v_Name, alg_string("Set")), !alg_truthy(or_36) ? or_36 : alg_equal(alg_property(v_Arguments, "Length"), alg_int(0))))) {
        return alg_string("alg_set()");
    }
    if (alg_truthy((or_37 = alg_equal(v_Name, alg_string("Set")), !alg_truthy(or_37) ? or_37 : alg_equal(alg_property(v_Arguments, "Length"), alg_int(1))))) {
        return alg_add(alg_add(alg_string("alg_set_of("), v_Joined), alg_char_value(41));
    }
    if (alg_truthy((or_38 = alg_equal(v_Name, alg_string("Array")), !alg_truthy(or_38) ? or_38 : alg_equal(alg_property(v_Arguments, "Length"), alg_int(1))))) {
        return alg_add(alg_add(alg_string("alg_array("), v_Joined), alg_char_value(41));
    }
    if (alg_truthy((or_39 = alg_equal(v_Name, alg_string("TextFile")), !alg_truthy(or_39) ? or_39 : alg_equal(alg_property(v_Arguments, "Length"), alg_int(0))))) {
        return alg_string("alg_text_file()");
    }
    if (alg_truthy((or_40 = alg_equal(v_Name, alg_string("Buffer")), !alg_truthy(or_40) ? or_40 : alg_equal(alg_property(v_Arguments, "Length"), alg_int(0))))) {
        return alg_string("alg_buffer(alg_int(0))");
    }
    if (alg_truthy((or_41 = alg_equal(v_Name, alg_string("Buffer")), !alg_truthy(or_41) ? or_41 : alg_equal(alg_property(v_Arguments, "Length"), alg_int(1))))) {
        return alg_add(alg_add(alg_string("alg_buffer("), v_Joined), alg_char_value(41));
    }
    return alg_string("");
    return alg_nil();
}

static Value m_CEmitter_UnitCall_4_String_String_List_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Unit = args[0];
    (void)v_Unit;
    Value v_Name = args[1];
    (void)v_Name;
    Value v_Arguments = args[2];
    (void)v_Arguments;
    Value v_Joined = args[3];
    (void)v_Joined;
    if (alg_truthy((or_42 = alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){v_Unit}, 1), !alg_truthy(or_42) ? or_42 : alg_not(alg_invoke((alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_Unit}, 1)), "Contains", (Value[]){v_Name}, 1))))) {
        return alg_add(alg_add(alg_string("(alg_error("), f_QuoteC(NULL, (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), v_Name), alg_string("' in unit '")), v_Unit), alg_string("'."))}, 1)), alg_string("), alg_nil())"));
    }
    if (alg_truthy(alg_equal(v_Unit, alg_string("System")))) {
        {
            Value v_TheBuiltin = alg_invoke(v_this, "Builtin", (Value[]){v_Name, alg_property(v_Arguments, "Length")}, 2);
            (void)v_TheBuiltin;
            if (alg_truthy(alg_not_equal(v_TheBuiltin, alg_string("")))) {
                return alg_add(alg_add(alg_add(v_TheBuiltin, alg_char_value(40)), v_Joined), alg_char_value(41));
            }
            Value v_TheConstructor = alg_invoke(v_this, "ConstructorFor", (Value[]){v_Name, v_Arguments, v_Joined}, 3);
            (void)v_TheConstructor;
            if (alg_truthy(alg_not_equal(v_TheConstructor, alg_string("")))) {
                return v_TheConstructor;
            }
            (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("A call to '"), v_Unit), alg_char_value(46)), v_Name), alg_string("'"))}, 1));
        }
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_add(alg_add(alg_add(alg_add(alg_string("alg_new("), alg_invoke(v_this, "ClassHandle", (Value[]){v_Name}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_Arguments}, 1)), alg_char_value(41));
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_add(alg_add(alg_add(alg_invoke(v_this, "FunctionName", (Value[]){v_Name}, 1), alg_string("(NULL, ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_Arguments}, 1)), alg_char_value(41));
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_add(alg_add(alg_add(alg_add(alg_string("alg_call("), alg_invoke(v_this, "Read", (Value[]){v_Name}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_Arguments}, 1)), alg_char_value(41));
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("A call to '"), v_Unit), alg_char_value(46)), v_Name), alg_string("'"))}, 1));
    return alg_string("");
    return alg_nil();
}

static Value m_CEmitter_VisitCall_1_CallExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Arguments = alg_nil();
    (void)v_Arguments;
    Value v_Joined = alg_nil();
    (void)v_Joined;
    if (alg_truthy(alg_is(alg_property(v_TheExpr, "Callee"), "SuperExpr"))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "CurrentClass"), alg_string("")))) {
                (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("'super' outside a class")}, 1));
            }
            Value v_Emitted = alg_list();
            (void)v_Emitted;
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Arguments"), "Length")))) {
                    {
                        (void)(alg_invoke(v_Emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Arguments"), v_I)}, 1)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_invoke_from("), alg_invoke(v_this, "ClassHandle", (Value[]){alg_property(v_this, "CurrentClass")}, 1)), alg_string(", v_this, ")), f_QuoteC(NULL, (Value[]){alg_str(alg_property(alg_property(alg_property(v_TheExpr, "Callee"), "Method"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_Emitted}, 1)), alg_char_value(41));
        }
    }
    if (alg_truthy((or_43 = alg_is(alg_property(v_TheExpr, "Callee"), "GetExpr"), !alg_truthy(or_43) ? or_43 : alg_not_equal(alg_property(alg_property(v_TheExpr, "Callee"), "Unit"), alg_string(""))))) {
        {
            Value v_Emitted = alg_list();
            (void)v_Emitted;
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Arguments"), "Length")))) {
                    {
                        (void)(alg_invoke(v_Emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Arguments"), v_I)}, 1)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            Value v_Text = alg_string("");
            (void)v_Text;
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(v_Emitted, "Length")))) {
                    {
                        {
                            if (alg_truthy(alg_greater(v_I, alg_int(0)))) {
                                (void)((v_Text = alg_add(v_Text, alg_string(", "))));
                            }
                            (void)((v_Text = alg_add(v_Text, alg_str(alg_subscript_get(v_Emitted, v_I)))));
                        }
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return alg_invoke(v_this, "UnitCall", (Value[]){alg_str(alg_property(alg_property(v_TheExpr, "Callee"), "Unit")), alg_str(alg_property(alg_property(alg_property(v_TheExpr, "Callee"), "Name"), "Lexeme")), v_Emitted, v_Text}, 4);
        }
    }
    if (alg_truthy(alg_is(alg_property(v_TheExpr, "Callee"), "GetExpr"))) {
        {
            Value v_Receiver = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(alg_property(v_TheExpr, "Callee"), "Obj")}, 1);
            (void)v_Receiver;
            Value v_Emitted = alg_list();
            (void)v_Emitted;
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Arguments"), "Length")))) {
                    {
                        (void)(alg_invoke(v_Emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Arguments"), v_I)}, 1)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_invoke("), v_Receiver), alg_string(", ")), f_QuoteC(NULL, (Value[]){alg_str(alg_property(alg_property(alg_property(v_TheExpr, "Callee"), "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_Emitted}, 1)), alg_char_value(41));
        }
    }
    if (alg_truthy(alg_not((alg_is(alg_property(v_TheExpr, "Callee"), "VariableExpr"))))) {
        {
            Value v_Emitted = alg_list();
            (void)v_Emitted;
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Arguments"), "Length")))) {
                    {
                        (void)(alg_invoke(v_Emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Arguments"), v_I)}, 1)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return alg_add(alg_add(alg_add(alg_add(alg_string("alg_call("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Callee")}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_Emitted}, 1)), alg_char_value(41));
        }
    }
    (void)((v_Arguments = alg_list()));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Arguments"), "Length")))) {
            {
                (void)(alg_invoke(v_Arguments, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Arguments"), v_I)}, 1)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)((v_Joined = alg_string("")));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Arguments, "Length")))) {
            {
                {
                    if (alg_truthy(alg_greater(v_I, alg_int(0)))) {
                        (void)((v_Joined = alg_add(v_Joined, alg_string(", "))));
                    }
                    (void)((v_Joined = alg_add(v_Joined, alg_str(alg_subscript_get(v_Arguments, v_I)))));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    Value v_Name = alg_str(alg_property(alg_property(alg_property(v_TheExpr, "Callee"), "Name"), "Lexeme"));
    (void)v_Name;
    if (alg_truthy((or_45 = (or_44 = alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_Name}, 1), alg_truthy(or_44) ? or_44 : alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_Name}, 1)), alg_truthy(or_45) ? or_45 : alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_Name}, 1)))) {
        return alg_add(alg_add(alg_add(alg_add(alg_string("alg_call("), alg_invoke(v_this, "Read", (Value[]){v_Name}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_Arguments}, 1)), alg_char_value(41));
    }
    Value v_Shadowed = alg_invoke(alg_property(v_this, "ShadowNames"), "Contains", (Value[]){v_Name}, 1);
    (void)v_Shadowed;
    if (alg_truthy(alg_not(v_Shadowed))) {
        {
            Value v_TheBuiltin = alg_invoke(v_this, "Builtin", (Value[]){v_Name, alg_property(v_Arguments, "Length")}, 2);
            (void)v_TheBuiltin;
            if (alg_truthy(alg_not_equal(v_TheBuiltin, alg_string("")))) {
                return alg_add(alg_add(alg_add(v_TheBuiltin, alg_char_value(40)), v_Joined), alg_char_value(41));
            }
        }
    }
    if (alg_truthy(alg_not(v_Shadowed))) {
        {
            Value v_TheConstructor = alg_invoke(v_this, "ConstructorFor", (Value[]){v_Name, v_Arguments, v_Joined}, 3);
            (void)v_TheConstructor;
            if (alg_truthy(alg_not_equal(v_TheConstructor, alg_string("")))) {
                return v_TheConstructor;
            }
        }
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_add(alg_add(alg_add(alg_add(alg_string("alg_new("), alg_invoke(v_this, "ClassHandle", (Value[]){v_Name}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_Arguments}, 1)), alg_char_value(41));
    }
    if (alg_truthy((or_47 = (or_46 = alg_not_equal(alg_property(v_this, "CurrentClass"), alg_string("")), !alg_truthy(or_46) ? or_46 : alg_not(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_Name}, 1))), !alg_truthy(or_47) ? or_47 : alg_invoke(alg_property(v_this, "VisibleMethods"), "Contains", (Value[]){v_Name}, 1)))) {
        return alg_add(alg_add(alg_add(alg_add(alg_string("alg_invoke(v_this, "), f_QuoteC(NULL, (Value[]){v_Name}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_Arguments}, 1)), alg_char_value(41));
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_add(alg_add(alg_add(alg_invoke(v_this, "FunctionName", (Value[]){v_Name}, 1), alg_string("(NULL, ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_Arguments}, 1)), alg_char_value(41));
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_add(alg_add(alg_add(alg_add(alg_string("alg_call("), alg_invoke(v_this, "Read", (Value[]){v_Name}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_Arguments}, 1)), alg_char_value(41));
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("A call to '"), v_Name), alg_string("'"))}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitLogical_1_LogicalExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Slot = alg_nil();
    (void)v_Slot;
    Value v_Test = alg_nil();
    (void)v_Test;
    Value v_Left = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Left")}, 1);
    (void)v_Left;
    Value v_Right = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Right")}, 1);
    (void)v_Right;
    (void)((v_Slot = alg_add(alg_string("or_"), alg_str(alg_property(v_this, "Logicals")))));
    (void)(alg_set_property(v_this, "Logicals", alg_add(alg_property(v_this, "Logicals"), alg_int(1))));
    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_Slot), alg_char_value(59)), alg_char_value(10))}, 1));
    (void)((v_Test = alg_string("!alg_truthy(")));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_OR))) {
        (void)((v_Test = alg_string("alg_truthy(")));
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_char_value(40), v_Slot), alg_string(" = ")), v_Left), alg_string(", ")), v_Test), v_Slot), alg_string(") ? ")), v_Slot), alg_string(" : ")), v_Right), alg_char_value(41));
    return alg_nil();
}

static Value m_CEmitter_VisitCollectionExpr_1_CollectionExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Built = alg_nil();
    (void)v_Built;
    if (alg_truthy(alg_property(v_TheExpr, "IsMap"))) {
        {
            (void)((v_Built = alg_string("alg_map()")));
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Keys"), "Length")))) {
                    {
                        (void)((v_Built = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_map_keep("), v_Built), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Keys"), v_I)}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Values"), v_I)}, 1)), alg_char_value(41))));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return v_Built;
        }
    }
    (void)((v_Built = alg_string("alg_list()")));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Values"), "Length")))) {
            {
                (void)((v_Built = alg_add(alg_add(alg_add(alg_add(alg_string("alg_list_keep("), v_Built), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Values"), v_I)}, 1)), alg_char_value(41))));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Built;
    return alg_nil();
}

static Value m_CEmitter_VisitSubscriptExpr_1_SubscriptExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    return alg_add(alg_add(alg_add(alg_add(alg_string("alg_subscript_get("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Obj")}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Index")}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_CEmitter_VisitSetSubscriptExpr_1_SetSubscriptExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_subscript_set("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Obj")}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Index")}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Value")}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_CEmitter_UnitValue_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Unit = args[0];
    (void)v_Unit;
    Value v_Name = args[1];
    (void)v_Name;
    if (alg_truthy((or_48 = alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){v_Unit}, 1), !alg_truthy(or_48) ? or_48 : alg_not(alg_invoke((alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_Unit}, 1)), "Contains", (Value[]){v_Name}, 1))))) {
        return alg_add(alg_add(alg_string("(alg_error("), f_QuoteC(NULL, (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), v_Name), alg_string("' in unit '")), v_Unit), alg_string("'."))}, 1)), alg_string("), alg_nil())"));
    }
    if (alg_truthy(alg_equal(v_Unit, alg_string("System")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("'"), v_Unit), alg_char_value(46)), v_Name), alg_string("' as a value"))}, 1));
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_Name}, 1));
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "EnumTypes"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_invoke(v_this, "EnumTypeName", (Value[]){v_Name}, 1);
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_add(alg_add(alg_string("alg_singleton("), alg_invoke(v_this, "ClassHandle", (Value[]){v_Name}, 1)), alg_char_value(41));
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_invoke(v_this, "ClassHandle", (Value[]){v_Name}, 1);
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_invoke(v_this, "HandleName", (Value[]){v_Name}, 1);
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_invoke(v_this, "VariableName", (Value[]){v_Name}, 1);
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("'"), v_Unit), alg_char_value(46)), v_Name), alg_string("' as a value"))}, 1));
    return alg_string("");
    return alg_nil();
}

static Value m_CEmitter_VisitGetExpr_1_GetExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    if (alg_truthy(alg_not_equal(alg_property(v_TheExpr, "Unit"), alg_string("")))) {
        return alg_invoke(v_this, "UnitValue", (Value[]){alg_str(alg_property(v_TheExpr, "Unit")), alg_str(alg_property(alg_property(v_TheExpr, "Name"), "Lexeme"))}, 2);
    }
    return alg_add(alg_add(alg_add(alg_add(alg_string("alg_property("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Obj")}, 1)), alg_string(", ")), f_QuoteC(NULL, (Value[]){alg_str(alg_property(alg_property(v_TheExpr, "Name"), "Lexeme"))}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_CEmitter_VisitSetExpr_1_SetExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    if (alg_truthy(alg_not_equal(alg_property(v_TheExpr, "Unit"), alg_string("")))) {
        {
            Value v_Written = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Value")}, 1);
            (void)v_Written;
            Value v_Unit = alg_str(alg_property(v_TheExpr, "Unit"));
            (void)v_Unit;
            Value v_Name = alg_str(alg_property(alg_property(v_TheExpr, "Name"), "Lexeme"));
            (void)v_Name;
            if (alg_truthy((or_49 = alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){v_Unit}, 1), !alg_truthy(or_49) ? or_49 : alg_not(alg_invoke((alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_Unit}, 1)), "Contains", (Value[]){v_Name}, 1))))) {
                return alg_add(alg_add(alg_string("(alg_error("), f_QuoteC(NULL, (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), v_Name), alg_string("' in unit '")), v_Unit), alg_string("'."))}, 1)), alg_string("), alg_nil())"));
            }
            if (alg_truthy((or_50 = alg_not_equal(v_Unit, alg_string("System")), !alg_truthy(or_50) ? or_50 : alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_Name}, 1)))) {
                return alg_add(alg_add(alg_add(alg_add(alg_char_value(40), alg_invoke(v_this, "VariableName", (Value[]){v_Name}, 1)), alg_string(" = ")), v_Written), alg_char_value(41));
            }
            (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("An assignment to '"), v_Unit), alg_char_value(46)), v_Name), alg_string("'"))}, 1));
        }
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_set_property("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Obj")}, 1)), alg_string(", ")), f_QuoteC(NULL, (Value[]){alg_str(alg_property(alg_property(v_TheExpr, "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheExpr, "Value")}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_CEmitter_VisitSuperExpr_1_SuperExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("'super' as a value")}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitThisExpr_1_ThisExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    return alg_string("v_this");
    return alg_nil();
}

static Value m_CEmitter_VisitClassStmt_1_ClassStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    (void)(alg_invoke(v_this, "EmitClass", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")), alg_property(v_TheStmt, "Superclass"), alg_property(v_TheStmt, "Fields"), alg_property(v_TheStmt, "Methods"), alg_bool(false)}, 5));
    return alg_nil();
}

static Value m_CEmitter_VisitObjectStmt_1_ObjectStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    (void)(alg_invoke(v_this, "EmitClass", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")), alg_property(v_TheStmt, "Superclass"), alg_property(v_TheStmt, "Fields"), alg_property(v_TheStmt, "Methods"), alg_bool(true)}, 5));
    return alg_nil();
}

static Value m_CEmitter_VisitEnumStmt_1_EnumStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_TheType = alg_nil();
    (void)v_TheType;
    (void)((v_TheType = alg_invoke(v_this, "EnumTypeName", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1)));
    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){v_TheType, alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 2));
    (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), v_TheType), alg_string(" = alg_enum_type(")), f_QuoteC(NULL, (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1)), alg_string(");")), alg_char_value(10))}, 1));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Members"), "Length")))) {
            {
                {
                    Value v_Symbol = alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Members"), v_I), "Lexeme"))}, 1));
                    (void)v_Symbol;
                    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){v_Symbol, alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Members"), v_I), "Lexeme"))}, 2));
                    (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), v_Symbol), alg_string(" = alg_enum_member(")), v_TheType), alg_string(", ")), f_QuoteC(NULL, (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Members"), v_I), "Lexeme"))}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_CEmitter_VisitTryStmt_1_TryStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Id = alg_nil();
    (void)v_Id;
    Value v_Frame = alg_nil();
    (void)v_Frame;
    Value v_Handlers = alg_nil();
    (void)v_Handlers;
    Value v_CatchAll = alg_nil();
    (void)v_CatchAll;
    Value v_Keys = alg_nil();
    (void)v_Keys;
    (void)((v_Id = alg_property(v_this, "Loops")));
    (void)(alg_set_property(v_this, "Loops", alg_add(alg_property(v_this, "Loops"), alg_int(1))));
    (void)((v_Frame = alg_add(alg_string("frame_"), alg_str(v_Id))));
    (void)((v_Handlers = alg_list()));
    (void)((v_CatchAll = alg_nil()));
    (void)((v_Keys = alg_invoke(alg_property(v_TheStmt, "Handlers"), "Keys", NULL, 0)));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Keys, "Length")))) {
            {
                {
                    if (alg_truthy(alg_equal(alg_subscript_get(v_Keys, v_I), alg_string("default")))) {
                        (void)((v_CatchAll = alg_invoke(alg_property(v_TheStmt, "Handlers"), "Get", (Value[]){alg_subscript_get(v_Keys, v_I)}, 1)));
                    } else {
                        (void)(alg_invoke(v_Handlers, "Add", (Value[]){alg_subscript_get(v_Keys, v_I)}, 1));
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("AlgFrame "), v_Frame), alg_char_value(59))}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_push_frame(&"), v_Frame), alg_string(");"))}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("if (ALG_SETJMP("), v_Frame), alg_string(".jump) == 0) {"))}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_set_property(v_this, "TryDepth", alg_add(alg_property(v_this, "TryDepth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_TheStmt, "TryBlock")}, 1));
    (void)(alg_set_property(v_this, "TryDepth", alg_subtract(alg_property(v_this, "TryDepth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("alg_pop_frame();")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("else {")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    if (alg_truthy(alg_equal(alg_property(v_Handlers, "Length"), alg_int(0)))) {
        (void)(alg_invoke(v_this, "EmitHandlerBody", (Value[]){v_CatchAll, v_Frame}, 2));
    } else {
        {
            Value v_Names = alg_string("");
            (void)v_Names;
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(v_Handlers, "Length")))) {
                    {
                        {
                            if (alg_truthy(alg_greater(v_I, alg_int(0)))) {
                                (void)((v_Names = alg_add(v_Names, alg_string(", "))));
                            }
                            (void)((v_Names = alg_add(v_Names, f_QuoteC(NULL, (Value[]){alg_str(alg_subscript_get(v_Handlers, v_I))}, 1))));
                        }
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            Value v_Table = alg_add(alg_string("names_"), alg_str(v_Id));
            (void)v_Table;
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("static const char *"), v_Table), alg_string("[] = {")), v_Names), alg_string("};"))}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("int32_t which_"), alg_str(v_Id)), alg_string(" = alg_handler(")), v_Frame), alg_string(".raised, ")), v_Table), alg_string(", ")), alg_str(alg_property(v_Handlers, "Length"))), alg_string(");"))}, 1));
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(v_Handlers, "Length")))) {
                    {
                        {
                            Value v_Lead = alg_string("else if");
                            (void)v_Lead;
                            if (alg_truthy(alg_equal(v_I, alg_int(0)))) {
                                (void)((v_Lead = alg_string("if")));
                            }
                            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(v_Lead, alg_string(" (which_")), alg_str(v_Id)), alg_string(" == ")), alg_str(v_I)), alg_string(") {"))}, 1));
                            (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
                            (void)(alg_invoke(v_this, "EmitHandlerBody", (Value[]){alg_invoke(alg_property(v_TheStmt, "Handlers"), "Get", (Value[]){alg_subscript_get(v_Handlers, v_I)}, 1), v_Frame}, 2));
                            (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
                            (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
                        }
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("else {")}, 1));
            (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
            if (alg_truthy(alg_not_equal(v_CatchAll, alg_nil()))) {
                (void)(alg_invoke(v_this, "EmitHandlerBody", (Value[]){v_CatchAll, v_Frame}, 2));
            } else {
                (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_raise("), v_Frame), alg_string(".raised);"))}, 1));
            }
            (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
        }
    }
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitRaiseStmt_1_RaiseStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    if (alg_truthy(alg_equal(alg_property(v_TheStmt, "Value"), alg_nil()))) {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("alg_raise(alg_nil());")}, 1));
    } else {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_raise("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Value")}, 1)), alg_string(");"))}, 1));
    }
    return alg_nil();
}

static Value m_CEmitter_VisitForInStmt_1_ForInStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Id = alg_nil();
    (void)v_Id;
    Value v_Snapshot = alg_nil();
    (void)v_Snapshot;
    Value v_Index = alg_nil();
    (void)v_Index;
    Value v_Counter = alg_nil();
    (void)v_Counter;
    (void)(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_property(v_TheStmt, "Body")}, 1));
    (void)((v_Id = alg_property(v_this, "Loops")));
    (void)(alg_set_property(v_this, "Loops", alg_add(alg_property(v_this, "Loops"), alg_int(1))));
    (void)((v_Snapshot = alg_add(alg_string("loop_"), alg_str(v_Id))));
    (void)((v_Index = alg_add(alg_string("at_"), alg_str(v_Id))));
    Value v_Mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_Mark;
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), v_Snapshot), alg_string(" = alg_iterable(")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Iterable")}, 1)), alg_string(");"))}, 1));
    (void)((v_Counter = alg_string("int32_t ")));
    if (alg_truthy(alg_property(v_this, "Volatiles"))) {
        (void)((v_Counter = alg_string("volatile int32_t ")));
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("for ("), v_Counter), v_Index), alg_string(" = 0; ")), v_Index), alg_string(" < alg_iterable_count(")), v_Snapshot), alg_string("); ")), v_Index), alg_string("++) {"))}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
    Value v_Element = alg_add(alg_add(alg_add(alg_add(alg_string("alg_iterable_at("), v_Snapshot), alg_string(", ")), v_Index), alg_char_value(41));
    (void)v_Element;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1))) {
        (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")), v_Element}, 2));
    } else {
        {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1)), alg_string(" = ")), v_Element), alg_char_value(59))}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1)), alg_char_value(59))}, 1));
        }
    }
    Value v_EnclosingLoopDepth = alg_property(v_this, "LoopTryDepth");
    (void)v_EnclosingLoopDepth;
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_property(v_this, "TryDepth")));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_TheStmt, "Body")}, 1));
    (void)(alg_set_property(v_this, "LoopTryDepth", v_EnclosingLoopDepth));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_Mark}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitBreakStmt_1_BreakStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    {
        Value v_I = alg_property(v_this, "LoopTryDepth");
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_this, "TryDepth")))) {
            {
                (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("alg_pop_frame();")}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("break;")}, 1));
    return alg_nil();
}

static Value m_CEmitter_VisitVarGroupStmt_1_VarGroupStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Value = alg_nil();
    (void)v_Value;
    Value v_Shared = alg_nil();
    (void)v_Shared;
    (void)((v_Value = alg_string("alg_nil()")));
    if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Initializer"), alg_nil()))) {
        (void)((v_Value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_TheStmt, "Initializer")}, 1)));
    }
    (void)((v_Shared = alg_add(alg_string("shared_"), alg_str(alg_property(v_this, "Loops")))));
    (void)(alg_set_property(v_this, "Loops", alg_add(alg_property(v_this, "Loops"), alg_int(1))));
    if (alg_truthy(alg_property(v_this, "AtTopLevel"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_Shared), alg_char_value(59)), alg_char_value(10))}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(v_Shared, alg_string(" = ")), v_Value), alg_char_value(59))}, 1));
        }
    } else {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), v_Shared), alg_string(" = ")), v_Value), alg_char_value(59))}, 1));
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Names"), "Length")))) {
            {
                {
                    Value v_Name = alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_I), "Lexeme"));
                    (void)v_Name;
                    if (alg_truthy(alg_property(v_this, "AtTopLevel"))) {
                        {
                            (void)(alg_invoke(v_this, "DeclareValue", (Value[]){alg_invoke(v_this, "VariableName", (Value[]){v_Name}, 1), v_Name}, 2));
                            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_invoke(v_this, "VariableName", (Value[]){v_Name}, 1), alg_string(" = ")), v_Shared), alg_char_value(59))}, 1));
                        }
                    } else {
                        if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_Name}, 1))) {
                            {
                                (void)(alg_invoke(v_this, "RequireCell", (Value[]){v_Name}, 1));
                                (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_Name}, 1));
                                (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_char_value(42), alg_invoke(v_this, "Cell", (Value[]){v_Name}, 1)), alg_string(" = ")), v_Shared), alg_char_value(59))}, 1));
                            }
                        } else {
                            {
                                (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_Name}, 1));
                                (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){v_Name}, 1)), alg_string(" = ")), v_Shared), alg_char_value(59))}, 1));
                                (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "VariableName", (Value[]){v_Name}, 1)), alg_char_value(59))}, 1));
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

static Value m_CEmitter_VisitModuleStmt_1_ModuleStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("A nested 'uses'")}, 1));
    return alg_nil();
}

void init_CEmitter(void) {
    fn_Indentation = alg_closure("Indentation", f_Indentation, NULL, 0, 1);
    fn_QuoteC = alg_closure("QuoteC", f_QuoteC, NULL, 0, 1);
    k_EmitUnit = alg_class("EmitUnit", alg_nil());
    alg_class_field(k_EmitUnit, "Name");
    alg_class_field(k_EmitUnit, "Statements");
    alg_class_field(k_EmitUnit, "Imports");
    alg_class_field(k_EmitUnit, "PrivateNames");
    alg_class_field(k_EmitUnit, "FileName");
    alg_class_initializer(k_EmitUnit, i_EmitUnit);
    alg_class_method(k_EmitUnit, "Init", m_EmitUnit_Init_5_String_List_List_List_String, 5, t_EmitUnit_Init_5_String_List_List_List_String);
    k_CEmitter = alg_class("CEmitter", alg_nil());
    alg_class_field(k_CEmitter, "Declarations");
    alg_class_field(k_CEmitter, "Functions");
    alg_class_field(k_CEmitter, "MainBody");
    alg_class_field(k_CEmitter, "Setup");
    alg_class_field(k_CEmitter, "Body");
    alg_class_field(k_CEmitter, "TestSymbols");
    alg_class_field(k_CEmitter, "Header");
    alg_class_field(k_CEmitter, "UnitName");
    alg_class_field(k_CEmitter, "PrivateNames");
    alg_class_field(k_CEmitter, "RootUnit");
    alg_class_field(k_CEmitter, "UnitTests");
    alg_class_field(k_CEmitter, "Target");
    alg_class_field(k_CEmitter, "Depth");
    alg_class_field(k_CEmitter, "AtTopLevel");
    alg_class_field(k_CEmitter, "Locals");
    alg_class_field(k_CEmitter, "Declared");
    alg_class_field(k_CEmitter, "Logicals");
    alg_class_field(k_CEmitter, "Loops");
    alg_class_field(k_CEmitter, "TryDepth");
    alg_class_field(k_CEmitter, "LoopTryDepth");
    alg_class_field(k_CEmitter, "Volatiles");
    alg_class_field(k_CEmitter, "Renames");
    alg_class_field(k_CEmitter, "Boxed");
    alg_class_field(k_CEmitter, "Cells");
    alg_class_field(k_CEmitter, "Captured");
    alg_class_field(k_CEmitter, "Globals");
    alg_class_field(k_CEmitter, "TopLevel");
    alg_class_field(k_CEmitter, "UnitExports");
    alg_class_field(k_CEmitter, "UnitAll");
    alg_class_field(k_CEmitter, "ShadowNames");
    alg_class_field(k_CEmitter, "InsideNested");
    alg_class_field(k_CEmitter, "EmitTests");
    alg_class_field(k_CEmitter, "Tests");
    alg_class_field(k_CEmitter, "TestFiles");
    alg_class_field(k_CEmitter, "CurrentFile");
    alg_class_field(k_CEmitter, "SourceFile");
    alg_class_field(k_CEmitter, "Classes");
    alg_class_field(k_CEmitter, "Objects");
    alg_class_field(k_CEmitter, "EnumTypes");
    alg_class_field(k_CEmitter, "EnumMembers");
    alg_class_field(k_CEmitter, "CurrentClass");
    alg_class_field(k_CEmitter, "VisibleFields");
    alg_class_field(k_CEmitter, "VisibleMethods");
    alg_class_initializer(k_CEmitter, i_CEmitter);
    alg_class_method(k_CEmitter, "Init", m_CEmitter_Init_0, 0, NULL);
    alg_class_method(k_CEmitter, "Unsupported", m_CEmitter_Unsupported_1, 1, t_CEmitter_Unsupported_1);
    alg_class_method(k_CEmitter, "Line", m_CEmitter_Line_1, 1, t_CEmitter_Line_1);
    alg_class_method(k_CEmitter, "Mangle", m_CEmitter_Mangle_2_String_String, 2, t_CEmitter_Mangle_2_String_String);
    alg_class_method(k_CEmitter, "SymbolOf", m_CEmitter_SymbolOf_2_String_String, 2, t_CEmitter_SymbolOf_2_String_String);
    alg_class_method(k_CEmitter, "ClassHandle", m_CEmitter_ClassHandle_1_String, 1, t_CEmitter_ClassHandle_1_String);
    alg_class_method(k_CEmitter, "InitName", m_CEmitter_InitName_1_String, 1, t_CEmitter_InitName_1_String);
    alg_class_method(k_CEmitter, "EnumTypeName", m_CEmitter_EnumTypeName_1_String, 1, t_CEmitter_EnumTypeName_1_String);
    alg_class_method(k_CEmitter, "EnumMemberName", m_CEmitter_EnumMemberName_2_String_String, 2, t_CEmitter_EnumMemberName_2_String_String);
    alg_class_method(k_CEmitter, "QuestionsOut", m_CEmitter_QuestionsOut_1_String, 1, t_CEmitter_QuestionsOut_1_String);
    alg_class_method(k_CEmitter, "IsLetterOrDigit", m_CEmitter_IsLetterOrDigit_1_Char, 1, t_CEmitter_IsLetterOrDigit_1_Char);
    alg_class_method(k_CEmitter, "Sanitize", m_CEmitter_Sanitize_1_String, 1, t_CEmitter_Sanitize_1_String);
    alg_class_method(k_CEmitter, "CollectUnits", m_CEmitter_CollectUnits_5_List_String_List_List_String, 5, t_CEmitter_CollectUnits_5_List_String_List_List_String);
    alg_class_method(k_CEmitter, "UnitNameOf", m_CEmitter_UnitNameOf_1_String, 1, t_CEmitter_UnitNameOf_1_String);
    alg_class_method(k_CEmitter, "VariableName", m_CEmitter_VariableName_1_String, 1, t_CEmitter_VariableName_1_String);
    alg_class_method(k_CEmitter, "FunctionName", m_CEmitter_FunctionName_1_String, 1, t_CEmitter_FunctionName_1_String);
    alg_class_method(k_CEmitter, "HandleName", m_CEmitter_HandleName_1_String, 1, t_CEmitter_HandleName_1_String);
    alg_class_method(k_CEmitter, "Prototype", m_CEmitter_Prototype_1, 1, t_CEmitter_Prototype_1);
    alg_class_method(k_CEmitter, "Exported", m_CEmitter_Exported_1_String, 1, t_CEmitter_Exported_1_String);
    alg_class_method(k_CEmitter, "DeclareValue", m_CEmitter_DeclareValue_2_String_String, 2, t_CEmitter_DeclareValue_2_String_String);
    alg_class_method(k_CEmitter, "IsTest", m_CEmitter_IsTest_1, 1, t_CEmitter_IsTest_1);
    alg_class_method(k_CEmitter, "CollectFunctions", m_CEmitter_CollectFunctions_1_List, 1, t_CEmitter_CollectFunctions_1_List);
    alg_class_method(k_CEmitter, "CollectGlobals", m_CEmitter_CollectGlobals_1_List, 1, t_CEmitter_CollectGlobals_1_List);
    alg_class_method(k_CEmitter, "CompilingFile", m_CEmitter_CompilingFile_1_String, 1, t_CEmitter_CompilingFile_1_String);
    alg_class_method(k_CEmitter, "WithTests", m_CEmitter_WithTests_0, 0, NULL);
    alg_class_method(k_CEmitter, "Emit", m_CEmitter_Emit_2_List_String, 2, t_CEmitter_Emit_2_List_String);
    alg_class_method(k_CEmitter, "UnitHeader", m_CEmitter_UnitHeader_1, 1, t_CEmitter_UnitHeader_1);
    alg_class_method(k_CEmitter, "UnitSource", m_CEmitter_UnitSource_4_List_Boolean_String, 4, t_CEmitter_UnitSource_4_List_Boolean_String);
    alg_class_method(k_CEmitter, "Upper", m_CEmitter_Upper_1_String, 1, t_CEmitter_Upper_1_String);
    alg_class_method(k_CEmitter, "TextLess", m_CEmitter_TextLess_2_String_String, 2, t_CEmitter_TextLess_2_String_String);
    alg_class_method(k_CEmitter, "EmitTestRunner", m_CEmitter_EmitTestRunner_0, 0, NULL);
    alg_class_method(k_CEmitter, "Execute", m_CEmitter_Execute_1, 1, t_CEmitter_Execute_1);
    alg_class_method(k_CEmitter, "Evaluate", m_CEmitter_Evaluate_1, 1, t_CEmitter_Evaluate_1);
    alg_class_method(k_CEmitter, "EmitTest", m_CEmitter_EmitTest_1, 1, t_CEmitter_EmitTest_1);
    alg_class_method(k_CEmitter, "RefuseBareBinding", m_CEmitter_RefuseBareBinding_1, 1, t_CEmitter_RefuseBareBinding_1);
    alg_class_method(k_CEmitter, "DeclaresNested", m_CEmitter_DeclaresNested_1_List, 1, t_CEmitter_DeclaresNested_1_List);
    alg_class_method(k_CEmitter, "AddOnce", m_CEmitter_AddOnce_2_List_String, 2, t_CEmitter_AddOnce_2_List_String);
    alg_class_method(k_CEmitter, "CollectBindings", m_CEmitter_CollectBindings_2_List_List, 2, t_CEmitter_CollectBindings_2_List_List);
    alg_class_method(k_CEmitter, "BoundNames", m_CEmitter_BoundNames_1, 1, t_CEmitter_BoundNames_1);
    alg_class_method(k_CEmitter, "BoxesFor", m_CEmitter_BoxesFor_1_List, 1, t_CEmitter_BoxesFor_1_List);
    alg_class_method(k_CEmitter, "Cell", m_CEmitter_Cell_1_String, 1, t_CEmitter_Cell_1_String);
    alg_class_method(k_CEmitter, "Read", m_CEmitter_Read_1_String, 1, t_CEmitter_Read_1_String);
    alg_class_method(k_CEmitter, "ClosureOf", m_CEmitter_ClosureOf_2_List, 2, t_CEmitter_ClosureOf_2_List);
    alg_class_method(k_CEmitter, "ContainsTry", m_CEmitter_ContainsTry_1_List, 1, t_CEmitter_ContainsTry_1_List);
    alg_class_method(k_CEmitter, "Local", m_CEmitter_Local_0, 0, NULL);
    alg_class_method(k_CEmitter, "RequireCell", m_CEmitter_RequireCell_1_String, 1, t_CEmitter_RequireCell_1_String);
    alg_class_method(k_CEmitter, "OpenScope", m_CEmitter_OpenScope_0, 0, NULL);
    alg_class_method(k_CEmitter, "CloseScope", m_CEmitter_CloseScope_1_List, 1, t_CEmitter_CloseScope_1_List);
    alg_class_method(k_CEmitter, "DeclareCell", m_CEmitter_DeclareCell_2_String_String, 2, t_CEmitter_DeclareCell_2_String_String);
    alg_class_method(k_CEmitter, "HoistCells", m_CEmitter_HoistCells_1_List, 1, t_CEmitter_HoistCells_1_List);
    alg_class_method(k_CEmitter, "EmitHandlerBody", m_CEmitter_EmitHandlerBody_2_String, 2, t_CEmitter_EmitHandlerBody_2_String);
    alg_class_method(k_CEmitter, "DeclaredTypes", m_CEmitter_DeclaredTypes_1, 1, t_CEmitter_DeclaredTypes_1);
    alg_class_method(k_CEmitter, "MethodSymbol", m_CEmitter_MethodSymbol_2_String, 2, t_CEmitter_MethodSymbol_2_String);
    alg_class_method(k_CEmitter, "NamesVisible", m_CEmitter_NamesVisible_3_String_List_Boolean, 3, t_CEmitter_NamesVisible_3_String_List_Boolean);
    alg_class_method(k_CEmitter, "EmitMethod", m_CEmitter_EmitMethod_2_String, 2, t_CEmitter_EmitMethod_2_String);
    alg_class_method(k_CEmitter, "EmitClass", m_CEmitter_EmitClass_5_String_List_List_Boolean, 5, t_CEmitter_EmitClass_5_String_List_List_Boolean);
    alg_class_method(k_CEmitter, "VisitVarStmt", m_CEmitter_VisitVarStmt_1_VarStmt, 1, t_CEmitter_VisitVarStmt_1_VarStmt);
    alg_class_method(k_CEmitter, "VisitExpressionStmt", m_CEmitter_VisitExpressionStmt_1_ExpressionStmt, 1, t_CEmitter_VisitExpressionStmt_1_ExpressionStmt);
    alg_class_method(k_CEmitter, "VisitBlockStmt", m_CEmitter_VisitBlockStmt_1_BlockStmt, 1, t_CEmitter_VisitBlockStmt_1_BlockStmt);
    alg_class_method(k_CEmitter, "VisitIfStmt", m_CEmitter_VisitIfStmt_1_IfStmt, 1, t_CEmitter_VisitIfStmt_1_IfStmt);
    alg_class_method(k_CEmitter, "VisitWhileStmt", m_CEmitter_VisitWhileStmt_1_WhileStmt, 1, t_CEmitter_VisitWhileStmt_1_WhileStmt);
    alg_class_method(k_CEmitter, "VisitPrintStmt", m_CEmitter_VisitPrintStmt_1_PrintStmt, 1, t_CEmitter_VisitPrintStmt_1_PrintStmt);
    alg_class_method(k_CEmitter, "VisitReturnStmt", m_CEmitter_VisitReturnStmt_1_ReturnStmt, 1, t_CEmitter_VisitReturnStmt_1_ReturnStmt);
    alg_class_method(k_CEmitter, "VisitFunctionStmt", m_CEmitter_VisitFunctionStmt_1_FunctionStmt, 1, t_CEmitter_VisitFunctionStmt_1_FunctionStmt);
    alg_class_method(k_CEmitter, "VisitLiteral", m_CEmitter_VisitLiteral_1_LiteralExpr, 1, t_CEmitter_VisitLiteral_1_LiteralExpr);
    alg_class_method(k_CEmitter, "VisitVariableExpr", m_CEmitter_VisitVariableExpr_1_VariableExpr, 1, t_CEmitter_VisitVariableExpr_1_VariableExpr);
    alg_class_method(k_CEmitter, "Unreachable", m_CEmitter_Unreachable_1_String, 1, t_CEmitter_Unreachable_1_String);
    alg_class_method(k_CEmitter, "VisitAssignExpr", m_CEmitter_VisitAssignExpr_1_AssignExpr, 1, t_CEmitter_VisitAssignExpr_1_AssignExpr);
    alg_class_method(k_CEmitter, "VisitGrouping", m_CEmitter_VisitGrouping_1_GroupingExpr, 1, t_CEmitter_VisitGrouping_1_GroupingExpr);
    alg_class_method(k_CEmitter, "VisitIsExpr", m_CEmitter_VisitIsExpr_1_IsExpr, 1, t_CEmitter_VisitIsExpr_1_IsExpr);
    alg_class_method(k_CEmitter, "VisitUnary", m_CEmitter_VisitUnary_1_UnaryExpr, 1, t_CEmitter_VisitUnary_1_UnaryExpr);
    alg_class_method(k_CEmitter, "VisitBinary", m_CEmitter_VisitBinary_1_BinaryExpr, 1, t_CEmitter_VisitBinary_1_BinaryExpr);
    alg_class_method(k_CEmitter, "Builtin", m_CEmitter_Builtin_2_String_Integer, 2, t_CEmitter_Builtin_2_String_Integer);
    alg_class_method(k_CEmitter, "ArgumentArray", m_CEmitter_ArgumentArray_1_List, 1, t_CEmitter_ArgumentArray_1_List);
    alg_class_method(k_CEmitter, "ConstructorFor", m_CEmitter_ConstructorFor_3_String_List_String, 3, t_CEmitter_ConstructorFor_3_String_List_String);
    alg_class_method(k_CEmitter, "UnitCall", m_CEmitter_UnitCall_4_String_String_List_String, 4, t_CEmitter_UnitCall_4_String_String_List_String);
    alg_class_method(k_CEmitter, "VisitCall", m_CEmitter_VisitCall_1_CallExpr, 1, t_CEmitter_VisitCall_1_CallExpr);
    alg_class_method(k_CEmitter, "VisitLogical", m_CEmitter_VisitLogical_1_LogicalExpr, 1, t_CEmitter_VisitLogical_1_LogicalExpr);
    alg_class_method(k_CEmitter, "VisitCollectionExpr", m_CEmitter_VisitCollectionExpr_1_CollectionExpr, 1, t_CEmitter_VisitCollectionExpr_1_CollectionExpr);
    alg_class_method(k_CEmitter, "VisitSubscriptExpr", m_CEmitter_VisitSubscriptExpr_1_SubscriptExpr, 1, t_CEmitter_VisitSubscriptExpr_1_SubscriptExpr);
    alg_class_method(k_CEmitter, "VisitSetSubscriptExpr", m_CEmitter_VisitSetSubscriptExpr_1_SetSubscriptExpr, 1, t_CEmitter_VisitSetSubscriptExpr_1_SetSubscriptExpr);
    alg_class_method(k_CEmitter, "UnitValue", m_CEmitter_UnitValue_2_String_String, 2, t_CEmitter_UnitValue_2_String_String);
    alg_class_method(k_CEmitter, "VisitGetExpr", m_CEmitter_VisitGetExpr_1_GetExpr, 1, t_CEmitter_VisitGetExpr_1_GetExpr);
    alg_class_method(k_CEmitter, "VisitSetExpr", m_CEmitter_VisitSetExpr_1_SetExpr, 1, t_CEmitter_VisitSetExpr_1_SetExpr);
    alg_class_method(k_CEmitter, "VisitSuperExpr", m_CEmitter_VisitSuperExpr_1_SuperExpr, 1, t_CEmitter_VisitSuperExpr_1_SuperExpr);
    alg_class_method(k_CEmitter, "VisitThisExpr", m_CEmitter_VisitThisExpr_1_ThisExpr, 1, t_CEmitter_VisitThisExpr_1_ThisExpr);
    alg_class_method(k_CEmitter, "VisitClassStmt", m_CEmitter_VisitClassStmt_1_ClassStmt, 1, t_CEmitter_VisitClassStmt_1_ClassStmt);
    alg_class_method(k_CEmitter, "VisitObjectStmt", m_CEmitter_VisitObjectStmt_1_ObjectStmt, 1, t_CEmitter_VisitObjectStmt_1_ObjectStmt);
    alg_class_method(k_CEmitter, "VisitEnumStmt", m_CEmitter_VisitEnumStmt_1_EnumStmt, 1, t_CEmitter_VisitEnumStmt_1_EnumStmt);
    alg_class_method(k_CEmitter, "VisitTryStmt", m_CEmitter_VisitTryStmt_1_TryStmt, 1, t_CEmitter_VisitTryStmt_1_TryStmt);
    alg_class_method(k_CEmitter, "VisitRaiseStmt", m_CEmitter_VisitRaiseStmt_1_RaiseStmt, 1, t_CEmitter_VisitRaiseStmt_1_RaiseStmt);
    alg_class_method(k_CEmitter, "VisitForInStmt", m_CEmitter_VisitForInStmt_1_ForInStmt, 1, t_CEmitter_VisitForInStmt_1_ForInStmt);
    alg_class_method(k_CEmitter, "VisitBreakStmt", m_CEmitter_VisitBreakStmt_1_BreakStmt, 1, t_CEmitter_VisitBreakStmt_1_BreakStmt);
    alg_class_method(k_CEmitter, "VisitVarGroupStmt", m_CEmitter_VisitVarGroupStmt_1_VarGroupStmt, 1, t_CEmitter_VisitVarGroupStmt_1_VarGroupStmt);
    alg_class_method(k_CEmitter, "VisitModuleStmt", m_CEmitter_VisitModuleStmt_1_ModuleStmt, 1, t_CEmitter_VisitModuleStmt_1_ModuleStmt);
}
