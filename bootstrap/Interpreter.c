/* Generated from Algol-24.  Do not edit. */
#include "Interpreter.h"
#include "Console.h"
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

Value f_setprogramarguments(Value **cells, Value *args, int32_t count);
Value f_suppressoutput(Value **cells, Value *args, int32_t count);
Value f_rendered(Value **cells, Value *args, int32_t count);
Value f_stringify(Value **cells, Value *args, int32_t count);
Value k_clocknative;
static const char *t_clocknative_call_2[] = { "Any", "Any" };
Value k_lengthnative;
static const char *t_lengthnative_call_2[] = { "Any", "Any" };
Value k_copynative;
static const char *t_copynative_call_2[] = { "Any", "Any" };
Value k_posnative;
static const char *t_posnative_call_2[] = { "Any", "Any" };
Value k_arraynative;
static const char *t_arraynative_call_2[] = { "Any", "Any" };
Value k_listnative;
static const char *t_listnative_call_2[] = { "Any", "Any" };
Value k_mapnative;
static const char *t_mapnative_call_2[] = { "Any", "Any" };
Value k_setnative;
static Value or_0;
static const char *t_setnative_call_2[] = { "Any", "Any" };
Value k_stacknative;
static const char *t_stacknative_call_2[] = { "Any", "Any" };
Value v_programarguments;
bool d_programarguments;
Value fn_setprogramarguments;
Value v_outputsuppressed;
bool d_outputsuppressed;
Value fn_suppressoutput;
Value fn_rendered;
Value k_writenative;
static const char *t_writenative_call_2[] = { "Any", "Any" };
Value k_writelnnative;
static const char *t_writelnnative_call_2[] = { "Any", "Any" };
Value k_haltnative;
static const char *t_haltnative_call_2[] = { "Any", "Any" };
Value k_ordnative;
static const char *t_ordnative_call_2[] = { "Any", "Any" };
Value k_valnative;
static Value or_1;
static Value or_2;
static const char *t_valnative_call_2[] = { "Any", "Any" };
Value k_charnative;
static const char *t_charnative_call_2[] = { "Any", "Any" };
Value k_maxnative;
static Value or_3;
static Value or_4;
static Value or_5;
static const char *t_maxnative_call_2[] = { "Any", "Any" };
Value k_modnative;
static const char *t_modnative_call_2[] = { "Any", "Any" };
Value k_textfilenative;
static const char *t_textfilenative_call_2[] = { "Any", "Any" };
Value k_buffernative;
static const char *t_buffernative_call_2[] = { "Any", "Any" };
Value k_fileexistsnative;
static const char *t_fileexistsnative_call_2[] = { "Any", "Any" };
Value k_paramcountnative;
static const char *t_paramcountnative_call_2[] = { "Any", "Any" };
Value k_paramstrnative;
static Value or_6;
static const char *t_paramstrnative_call_2[] = { "Any", "Any" };
Value fn_stringify;
Value k_strnative;
static const char *t_strnative_call_2[] = { "Any", "Any" };
Value k_asserttruenative;
static const char *t_asserttruenative_call_2[] = { "Any", "Any" };
Value k_assertequalnative;
static const char *t_assertequalnative_call_2[] = { "Any", "Any" };
Value k_failnative;
static const char *t_failnative_call_2[] = { "Any", "Any" };
Value k_interpreter;
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
static const char *t_interpreter_hoist_1_list[] = { "List" };
static const char *t_interpreter_hoistedclass_1_string[] = { "String" };
static const char *t_interpreter_interpret_1_list[] = { "List" };
static const char *t_interpreter_hoisttests_11_list_list_map_boolean_environment_map_string_list_map_set_boolean[] = { "List", "List", "Map", "Boolean", "Environment", "Map", "String", "List", "Map", "Set", "Boolean" };
static const char *t_interpreter_runtests_2_list_string[] = { "List", "String" };
static const char *t_interpreter_report_2_string_string[] = { "String", "String" };
static const char *t_interpreter_visitliteral_1_literalexpr[] = { "LiteralExpr" };
static const char *t_interpreter_visitlogical_1_logicalexpr[] = { "LogicalExpr" };
static const char *t_interpreter_visitgrouping_1_groupingexpr[] = { "GroupingExpr" };
static const char *t_interpreter_visitunary_1_unaryexpr[] = { "UnaryExpr" };
static const char *t_interpreter_visitcollectionexpr_1_collectionexpr[] = { "CollectionExpr" };
static const char *t_interpreter_visitsubscriptexpr_1_subscriptexpr[] = { "SubscriptExpr" };
static const char *t_interpreter_visitsetsubscriptexpr_1_setsubscriptexpr[] = { "SetSubscriptExpr" };
static const char *t_interpreter_istext_1[] = { "Any" };
static const char *t_interpreter_insubrange_2_string[] = { "Any", "String" };
static const char *t_interpreter_satisfiestype_2_string[] = { "Any", "String" };
static const char *t_interpreter_visitisexpr_1_isexpr[] = { "IsExpr" };
static const char *t_interpreter_visitvariableexpr_1_variableexpr[] = { "VariableExpr" };
static const char *t_interpreter_thisfield_2_token_string[] = { "Token", "String" };
static const char *t_interpreter_setthisfield_3_token_string[] = { "Token", "Any", "String" };
static const char *t_interpreter_lookupvariable_2_token_expr[] = { "Token", "Expr" };
static const char *t_interpreter_suggestunit_2_token_string[] = { "Token", "String" };
static const char *t_interpreter_integerdivide_2[] = { "Any", "Any" };
static const char *t_interpreter_visitbinary_1_binaryexpr[] = { "BinaryExpr" };
static const char *t_interpreter_visitcall_1_callexpr[] = { "CallExpr" };
static const char *t_interpreter_assignqualified_3_string_token[] = { "String", "Token", "Any" };
static const char *t_interpreter_qualified_2_string_token[] = { "String", "Token" };
static const char *t_interpreter_visitgetexpr_1_getexpr[] = { "GetExpr" };
static const char *t_interpreter_visitsetexpr_1_setexpr[] = { "SetExpr" };
static const char *t_interpreter_visitsuperexpr_1_superexpr[] = { "SuperExpr" };
static const char *t_interpreter_visitthisexpr_1_thisexpr[] = { "ThisExpr" };
static const char *t_interpreter_classnameof_1[] = { "Any" };
static const char *t_interpreter_istruthy_1[] = { "Any" };
static const char *t_interpreter_isequal_2[] = { "Any", "Any" };
static const char *t_interpreter_widen_2_string[] = { "Any", "String" };
static const char *t_interpreter_evaluate_1_expr[] = { "Expr" };
static const char *t_interpreter_execute_1_stmt[] = { "Stmt" };
static const char *t_interpreter_resolve_2_expr_integer[] = { "Expr", "Integer" };
static const char *t_interpreter_executeblock_2_list_environment[] = { "List", "Environment" };
static const char *t_interpreter_visitblockstmt_1_blockstmt[] = { "BlockStmt" };
static const char *t_interpreter_visitclassstmt_1_classstmt[] = { "ClassStmt" };
static const char *t_interpreter_visitobjectstmt_1_objectstmt[] = { "ObjectStmt" };
static const char *t_interpreter_visitsubrangestmt_1_subrangestmt[] = { "SubrangeStmt" };
static const char *t_interpreter_visitenumstmt_1_enumstmt[] = { "EnumStmt" };
static const char *t_interpreter_visitexpressionstmt_1_expressionstmt[] = { "ExpressionStmt" };
static const char *t_interpreter_visitfunctionstmt_1_functionstmt[] = { "FunctionStmt" };
static const char *t_interpreter_visitifstmt_1_ifstmt[] = { "IfStmt" };
static const char *t_interpreter_visitwhilestmt_1_whilestmt[] = { "WhileStmt" };
static const char *t_interpreter_contains_2[] = { "Any", "Any" };
static const char *t_interpreter_iscallable_1[] = { "Any" };
static const char *t_interpreter_elementsof_2_token[] = { "Token", "Any" };
static const char *t_interpreter_visitforinstmt_1_forinstmt[] = { "ForInStmt" };
static const char *t_interpreter_visitbreakstmt_1_breakstmt[] = { "BreakStmt" };
static const char *t_interpreter_visitmodulestmt_1_modulestmt[] = { "ModuleStmt" };
static const char *t_interpreter_visitraisestmt_1_raisestmt[] = { "RaiseStmt" };
static const char *t_interpreter_findhandler_2_map[] = { "Map", "Any" };
static const char *t_interpreter_handle_3_trystmt[] = { "TryStmt", "Any", "Any" };
static const char *t_interpreter_visittrystmt_1_trystmt[] = { "TryStmt" };
static const char *t_interpreter_visitreturnstmt_1_returnstmt[] = { "ReturnStmt" };
static const char *t_interpreter_visitvarstmt_1_varstmt[] = { "VarStmt" };
static const char *t_interpreter_visitvargroupstmt_1_vargroupstmt[] = { "VarGroupStmt" };
static const char *t_interpreter_visitassignexpr_1_assignexpr[] = { "AssignExpr" };
Value k_broke;
Value k_raised;
static const char *t_raised_init_1[] = { "Any" };
Value k_return;
static const char *t_return_init_1[] = { "Any" };

static Value i_clocknative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_clocknative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(0);
    return alg_nil();
}

static Value m_clocknative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_clock();
    return alg_nil();
}

static Value i_lengthnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_lengthnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_lengthnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    if (alg_truthy(alg_is(alg_subscript_get(v_arguments, alg_int(0)), "ObjCollection"))) {
        alg_raise(alg_string("Length expects text; use .Length for a collection."));
    }
    return alg_text_length(alg_str(alg_subscript_get(v_arguments, alg_int(0))));
    return alg_nil();
}

static Value i_copynative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_copynative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(3);
    return alg_nil();
}

static Value m_copynative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_copy(alg_str(alg_subscript_get(v_arguments, alg_int(0))), alg_subscript_get(v_arguments, alg_int(1)), alg_subscript_get(v_arguments, alg_int(2)));
    return alg_nil();
}

static Value i_posnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_posnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(2);
    return alg_nil();
}

static Value m_posnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_pos(alg_str(alg_subscript_get(v_arguments, alg_int(0))), alg_str(alg_subscript_get(v_arguments, alg_int(1))));
    return alg_nil();
}

static Value i_arraynative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_arraynative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_arraynative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    Value v_result = alg_nil();
    (void)v_result;
    (void)((v_result = alg_widen(alg_new(k_objcollection, (Value[]){alg_string("Array")}, 1), "ObjCollection")));
    (void)(alg_invoke(v_result, "Allocate", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1));
    return v_result;
    return alg_nil();
}

static Value i_listnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_listnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(0);
    return alg_nil();
}

static Value m_listnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_new(k_objcollection, (Value[]){alg_string("List")}, 1);
    return alg_nil();
}

static Value i_mapnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_mapnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(0);
    return alg_nil();
}

static Value m_mapnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_new(k_objcollection, (Value[]){alg_string("Map")}, 1);
    return alg_nil();
}

static Value i_setnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_setnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_negate(alg_int(1));
    return alg_nil();
}

static Value m_setnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    Value v_result = alg_nil();
    (void)v_result;
    if (alg_truthy(alg_greater(alg_property(v_arguments, "Length"), alg_int(1)))) {
        alg_raise(alg_add(alg_add(alg_string("Expected 0 or 1 arguments but got "), alg_str(alg_property(v_arguments, "Length"))), alg_char_value(46)));
    }
    (void)((v_result = alg_widen(alg_new(k_objcollection, (Value[]){alg_string("Set")}, 1), "ObjCollection")));
    if (alg_truthy(alg_equal(alg_property(v_arguments, "Length"), alg_int(1)))) {
        {
            Value v_from = alg_subscript_get(v_arguments, alg_int(0));
            (void)v_from;
            if (alg_truthy((or_0 = alg_not((alg_is(v_from, "ObjCollection"))), alg_truthy(or_0) ? or_0 : alg_not_equal(alg_property(v_from, "Kind"), alg_string("List"))))) {
                alg_raise(alg_add(alg_add(alg_string("Set expects (List) but got ("), f_typenameof(NULL, (Value[]){v_from}, 1)), alg_string(").")));
            }
            {
                Value v_i = alg_int(0);
                (void)v_i;
                while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_from, "Items"), "Length")))) {
                    {
                        (void)(alg_invoke(v_result, "Invoke", (Value[]){alg_string("add"), alg_list_keep(alg_list(), alg_subscript_get(alg_property(v_from, "Items"), v_i))}, 2));
                        (void)((v_i = alg_add(v_i, alg_int(1))));
                    }
                }
            }
        }
    }
    return v_result;
    return alg_nil();
}

static Value i_stacknative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_stacknative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(0);
    return alg_nil();
}

static Value m_stacknative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_new(k_objcollection, (Value[]){alg_string("Stack")}, 1);
    return alg_nil();
}

Value f_setprogramarguments(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_arguments = alg_param(args[0], "List");
    (void)v_arguments;
    (void)((alg_declared(d_programarguments, "ProgramArguments"), (v_programarguments = alg_widen(v_arguments, "List"))));
    return alg_nil();
}

Value f_suppressoutput(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_suppress = alg_param(args[0], "Boolean");
    (void)v_suppress;
    (void)((alg_declared(d_outputsuppressed, "OutputSuppressed"), (v_outputsuppressed = alg_widen(v_suppress, "Boolean"))));
    return alg_nil();
}

Value f_rendered(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = alg_param(args[1], "List");
    (void)v_arguments;
    Value v_line = alg_nil();
    (void)v_line;
    (void)((v_line = alg_widen(alg_buffer(alg_int(0)), "Buffer")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_arguments, "Length")))) {
            {
                (void)(alg_invoke(v_line, "Append", (Value[]){f_stringify(NULL, (Value[]){v_theinterpreter, alg_subscript_get(v_arguments, v_i)}, 2)}, 1));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_property(v_line, "Text");
    return alg_nil();
}

static Value i_writenative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_writenative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_negate(alg_int(1));
    return alg_nil();
}

static Value m_writenative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    if (alg_truthy(alg_not((alg_declared(d_outputsuppressed, "OutputSuppressed"), v_outputsuppressed)))) {
        (void)(alg_write(f_rendered(NULL, (Value[]){v_theinterpreter, v_arguments}, 2)));
    }
    return alg_nil();
    return alg_nil();
}

static Value i_writelnnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_writelnnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_negate(alg_int(1));
    return alg_nil();
}

static Value m_writelnnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    if (alg_truthy(alg_not((alg_declared(d_outputsuppressed, "OutputSuppressed"), v_outputsuppressed)))) {
        (void)(alg_writeln(f_rendered(NULL, (Value[]){v_theinterpreter, v_arguments}, 2)));
    }
    return alg_nil();
    return alg_nil();
}

static Value i_haltnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_haltnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_haltnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    (void)(alg_halt(alg_subscript_get(v_arguments, alg_int(0))));
    return alg_nil();
    return alg_nil();
}

static Value i_ordnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_ordnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_ordnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    if (alg_truthy(alg_is(alg_subscript_get(v_arguments, alg_int(0)), "ObjEnum"))) {
        return alg_property(alg_subscript_get(v_arguments, alg_int(0)), "Ordinal");
    }
    return alg_ord(alg_subscript_get(v_arguments, alg_int(0)));
    return alg_nil();
}

static Value i_valnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_valnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_valnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    Value v_text = alg_nil();
    (void)v_text;
    Value v_digits = alg_nil();
    (void)v_digits;
    Value v_result = alg_nil();
    (void)v_result;
    Value v_sign = alg_nil();
    (void)v_sign;
    (void)((v_text = alg_widen(alg_str(alg_subscript_get(v_arguments, alg_int(0))), "String")));
    Value v_asdouble = alg_val(v_text);
    (void)v_asdouble;
    (void)((v_sign = alg_widen(alg_int(1), "Integer")));
    (void)((v_digits = alg_widen(v_text, "String")));
    if (alg_truthy((or_1 = alg_greater(alg_text_length(v_digits), alg_int(0)), !alg_truthy(or_1) ? or_1 : alg_equal(alg_subscript_get(v_digits, alg_int(0)), alg_char_value(45))))) {
        {
            (void)((v_sign = alg_widen(alg_negate(alg_int(1)), "Integer")));
            (void)((v_digits = alg_widen(alg_copy(v_digits, alg_int(1), alg_subtract(alg_text_length(v_digits), alg_int(1))), "String")));
        }
    }
    if (alg_truthy(alg_equal(alg_text_length(v_digits), alg_int(0)))) {
        return v_asdouble;
    }
    (void)((v_result = alg_widen(alg_int(0), "Integer")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_text_length(v_digits)))) {
            {
                {
                    Value v_c = alg_subscript_get(v_digits, v_i);
                    (void)v_c;
                    if (alg_truthy((or_2 = alg_less(v_c, alg_char_value(48)), alg_truthy(or_2) ? or_2 : alg_greater(v_c, alg_char_value(57))))) {
                        return v_asdouble;
                    }
                    (void)((v_result = alg_widen(alg_add(alg_multiply(v_result, alg_int(10)), (alg_subtract(alg_ord(v_c), alg_ord(alg_char_value(48))))), "Integer")));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_multiply(v_sign, v_result);
    return alg_nil();
}

static Value i_charnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_charnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_charnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_char(alg_subscript_get(v_arguments, alg_int(0)));
    return alg_nil();
}

static Value i_maxnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_maxnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(2);
    return alg_nil();
}

static Value m_maxnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    Value v_a = alg_nil();
    (void)v_a;
    Value v_b = alg_nil();
    (void)v_b;
    (void)((v_a = alg_subscript_get(v_arguments, alg_int(0))));
    (void)((v_b = alg_subscript_get(v_arguments, alg_int(1))));
    if (alg_truthy(alg_not(((or_5 = ((or_3 = alg_is(v_a, "Integer"), alg_truthy(or_3) ? or_3 : alg_is(v_a, "Double"))), !alg_truthy(or_5) ? or_5 : ((or_4 = alg_is(v_b, "Integer"), alg_truthy(or_4) ? or_4 : alg_is(v_b, "Double")))))))) {
        alg_raise(alg_string("Max expects numbers."));
    }
    if (alg_truthy(alg_greater(v_a, v_b))) {
        return v_a;
    }
    return v_b;
    return alg_nil();
}

static Value i_modnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_modnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(2);
    return alg_nil();
}

static Value m_modnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_mod(alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1)));
    return alg_nil();
}

static Value i_textfilenative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_textfilenative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(0);
    return alg_nil();
}

static Value m_textfilenative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_new(k_objfile, NULL, 0);
    return alg_nil();
}

static Value i_buffernative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_buffernative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_negate(alg_int(1));
    return alg_nil();
}

static Value m_buffernative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    if (alg_truthy(alg_greater(alg_property(v_arguments, "Length"), alg_int(1)))) {
        alg_raise(alg_add(alg_add(alg_string("Expected 0 or 1 arguments but got "), alg_str(alg_property(v_arguments, "Length"))), alg_char_value(46)));
    }
    if (alg_truthy(alg_equal(alg_property(v_arguments, "Length"), alg_int(0)))) {
        return alg_new(k_objbuffer, (Value[]){alg_int(0)}, 1);
    }
    return alg_new(k_objbuffer, (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
    return alg_nil();
}

static Value i_fileexistsnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_fileexistsnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_fileexistsnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_file_exists(alg_str(alg_subscript_get(v_arguments, alg_int(0))));
    return alg_nil();
}

static Value i_paramcountnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_paramcountnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(0);
    return alg_nil();
}

static Value m_paramcountnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_subtract(alg_property((alg_declared(d_programarguments, "ProgramArguments"), v_programarguments), "Length"), alg_int(1));
    return alg_nil();
}

static Value i_paramstrnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_paramstrnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_paramstrnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    Value v_at = alg_nil();
    (void)v_at;
    (void)((v_at = alg_widen(alg_cast(alg_subscript_get(v_arguments, alg_int(0)), "Integer"), "Integer")));
    if (alg_truthy((or_6 = alg_less(v_at, alg_int(0)), alg_truthy(or_6) ? or_6 : alg_greater_equal(v_at, alg_property((alg_declared(d_programarguments, "ProgramArguments"), v_programarguments), "Length"))))) {
        return alg_string("");
    }
    return alg_subscript_get((alg_declared(d_programarguments, "ProgramArguments"), v_programarguments), v_at);
    return alg_nil();
}

Value f_stringify(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_value = args[1];
    (void)v_value;
    if (alg_truthy(alg_equal(v_value, alg_nil()))) {
        return alg_string("nil");
    }
    if (alg_truthy(alg_is(v_value, "ObjInstance"))) {
        {
            Value v_method = alg_invoke(alg_property(v_value, "Klass"), "FindMethod", (Value[]){alg_string("tostring")}, 1);
            (void)v_method;
            if (alg_truthy(alg_not_equal(v_method, alg_nil()))) {
                return f_stringify(NULL, (Value[]){v_theinterpreter, alg_invoke(alg_invoke(v_method, "Bind", (Value[]){v_value}, 1), "Call", (Value[]){v_theinterpreter, alg_list()}, 2)}, 2);
            }
        }
    }
    if (alg_truthy(alg_is(v_value, "ObjCollection"))) {
        {
            Value v_result = alg_char_value(91);
            (void)v_result;
            Value v_first = alg_bool(true);
            (void)v_first;
            if (alg_truthy(alg_equal(alg_property(v_value, "Kind"), alg_string("Map")))) {
                {
                    Value loop_0 = alg_iterable(alg_invoke(alg_property(v_value, "Pairs"), "Keys", NULL, 0));
                    for (int32_t at_0 = 0; at_0 < alg_iterable_count(loop_0); at_0++) {
                        Value v_key = alg_iterable_at(loop_0, at_0);
                        (void)v_key;
                        {
                            if (alg_truthy(alg_not(v_first))) {
                                (void)((v_result = alg_add(v_result, alg_string(", "))));
                            }
                            (void)((v_first = alg_bool(false)));
                            (void)((v_result = alg_add(alg_add(alg_add(v_result, f_stringify(NULL, (Value[]){v_theinterpreter, v_key}, 2)), alg_char_value(58)), f_stringify(NULL, (Value[]){v_theinterpreter, alg_invoke(alg_property(v_value, "Pairs"), "Get", (Value[]){v_key}, 1)}, 2))));
                        }
                    }
                }
            } else {
                {
                    Value loop_1 = alg_iterable(alg_property(v_value, "Items"));
                    for (int32_t at_1 = 0; at_1 < alg_iterable_count(loop_1); at_1++) {
                        Value v_element = alg_iterable_at(loop_1, at_1);
                        (void)v_element;
                        {
                            if (alg_truthy(alg_not(v_first))) {
                                (void)((v_result = alg_add(v_result, alg_string(", "))));
                            }
                            (void)((v_first = alg_bool(false)));
                            (void)((v_result = alg_add(v_result, f_stringify(NULL, (Value[]){v_theinterpreter, v_element}, 2))));
                        }
                    }
                }
            }
            return alg_add(v_result, alg_char_value(93));
        }
    }
    return alg_str(v_value);
    return alg_nil();
}

static Value i_strnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_strnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_strnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return f_stringify(NULL, (Value[]){v_theinterpreter, alg_subscript_get(v_arguments, alg_int(0))}, 2);
    return alg_nil();
}

static Value i_asserttruenative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_asserttruenative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_asserttruenative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    if (alg_truthy(alg_not(alg_invoke(v_theinterpreter, "IsTruthy", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1)))) {
        alg_raise(alg_add(alg_add(alg_string("Assertion failed.  Expected true but got '"), alg_str(alg_subscript_get(v_arguments, alg_int(0)))), alg_string("'.")));
    }
    return alg_nil();
    return alg_nil();
}

static Value i_assertequalnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_assertequalnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(2);
    return alg_nil();
}

static Value m_assertequalnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    if (alg_truthy(alg_not(alg_invoke(v_theinterpreter, "IsEqual", (Value[]){alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1))}, 2)))) {
        {
            Value v_left = alg_str(alg_subscript_get(v_arguments, alg_int(0)));
            (void)v_left;
            Value v_right = alg_str(alg_subscript_get(v_arguments, alg_int(1)));
            (void)v_right;
            if (alg_truthy(alg_equal(v_left, v_right))) {
                alg_raise(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("Assertion failed.  Expected "), f_typenameof(NULL, (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1)), alg_string(" '")), v_left), alg_string("' but got ")), f_typenameof(NULL, (Value[]){alg_subscript_get(v_arguments, alg_int(1))}, 1)), alg_string(" '")), v_right), alg_string("'.")));
            }
            alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Assertion failed.  Expected '"), v_left), alg_string("' but got '")), v_right), alg_string("'.")));
        }
    }
    return alg_nil();
    return alg_nil();
}

static Value i_failnative(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_failnative_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_int(1);
    return alg_nil();
}

static Value m_failnative_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    alg_raise(alg_add(alg_string("Failed.  "), alg_str(alg_subscript_get(v_arguments, alg_int(0)))));
    return alg_nil();
}

static Value i_interpreter(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Env", alg_nil());
    alg_set_property(v_this, "Builtins", alg_nil());
    alg_set_property(v_this, "Globals", alg_nil());
    alg_set_property(v_this, "Locals", alg_nil());
    alg_set_property(v_this, "Modules", alg_nil());
    alg_set_property(v_this, "HoistedClasses", alg_nil());
    alg_set_property(v_this, "RootFile", alg_nil());
    alg_set_property(v_this, "UnitsByName", alg_nil());
    return alg_nil();
}

static Value m_interpreter_init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_set_property(v_this, "Builtins", alg_widen(alg_new(k_environment, NULL, 0), "Environment")));
    (void)(alg_set_property(v_this, "Globals", alg_widen(alg_new(k_environment, NULL, 0), "Environment")));
    (void)(alg_set_property(alg_property(v_this, "Globals"), "Enclosing", alg_property(v_this, "Builtins")));
    (void)(alg_set_property(v_this, "Locals", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "Modules", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "RootFile", alg_widen(alg_string(""), "String")));
    (void)(alg_set_property(v_this, "HoistedClasses", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "UnitsByName", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "Env", alg_widen(alg_property(v_this, "Globals"), "Environment")));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("clock"), alg_new(k_clocknative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Length"), alg_new(k_lengthnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Copy"), alg_new(k_copynative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Pos"), alg_new(k_posnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Str"), alg_new(k_strnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Array"), alg_new(k_arraynative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("List"), alg_new(k_listnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Map"), alg_new(k_mapnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Set"), alg_new(k_setnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Stack"), alg_new(k_stacknative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Halt"), alg_new(k_haltnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Ord"), alg_new(k_ordnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Val"), alg_new(k_valnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Char"), alg_new(k_charnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Max"), alg_new(k_maxnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Mod"), alg_new(k_modnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Write"), alg_new(k_writenative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("WriteLn"), alg_new(k_writelnnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Buffer"), alg_new(k_buffernative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("TextFile"), alg_new(k_textfilenative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("FileExists"), alg_new(k_fileexistsnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("ParamCount"), alg_new(k_paramcountnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("ParamStr"), alg_new(k_paramstrnative, NULL, 0)}, 2));
    return alg_nil();
}

static Value m_interpreter_hoist_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    Value v_names = alg_set();
    (void)v_names;
    {
        Value v_i = alg_widen(alg_int(0), "Integer");
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_statements, "Length")))) {
            {
                if (alg_truthy(alg_is(alg_subscript_get(v_statements, v_i), "ClassStmt"))) {
                    (void)(alg_invoke(v_names, "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Name"), "Lexeme")}, 1)}, 1));
                }
                (void)((v_i = alg_widen(alg_add(v_i, alg_int(1)), "Integer")));
            }
        }
    }
    {
        Value v_i = alg_widen(alg_int(0), "Integer");
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_statements, "Length")))) {
            {
                if (alg_truthy(alg_is(alg_subscript_get(v_statements, v_i), "ClassStmt"))) {
                    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Name"), "Lexeme"), alg_new(k_objclass, (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Name"), "Lexeme")), alg_nil(), alg_map(), alg_list()}, 4)}, 2));
                }
                (void)((v_i = alg_widen(alg_add(v_i, alg_int(1)), "Integer")));
            }
        }
    }
    {
        Value v_i = alg_widen(alg_int(0), "Integer");
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_statements, "Length")))) {
            {
                if (alg_truthy(alg_is(alg_subscript_get(v_statements, v_i), "ClassStmt"))) {
                    {
                        Value v_parent = alg_property(alg_subscript_get(v_statements, v_i), "Superclass");
                        (void)v_parent;
                        Value v_ready = alg_equal(v_parent, alg_nil());
                        (void)v_ready;
                        if (alg_truthy(alg_not(v_ready))) {
                            (void)((v_ready = alg_invoke(v_names, "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_parent, "Name"), "Lexeme")}, 1)}, 1)));
                        }
                        if (alg_truthy(v_ready)) {
                            {
                                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(v_statements, v_i)}, 1));
                                (void)(alg_invoke(alg_property(v_this, "HoistedClasses"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Name"), "Lexeme")}, 1)}, 1));
                            }
                        }
                    }
                }
                (void)((v_i = alg_widen(alg_add(v_i, alg_int(1)), "Integer")));
            }
        }
    }
    {
        Value v_i = alg_widen(alg_int(0), "Integer");
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_statements, "Length")))) {
            {
                if (alg_truthy(alg_is(alg_subscript_get(v_statements, v_i), "FunctionStmt"))) {
                    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(v_statements, v_i)}, 1));
                }
                (void)((v_i = alg_widen(alg_add(v_i, alg_int(1)), "Integer")));
            }
        }
    }
    return alg_nil();
}

static Value m_interpreter_hoistedclass_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    if (alg_truthy(alg_not(alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1)))) {
        return alg_nil();
    }
    Value v_bound = alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1);
    (void)v_bound;
    if (alg_truthy(alg_not((alg_is(v_bound, "ObjClass"))))) {
        return alg_nil();
    }
    return v_bound;
    return alg_nil();
}

static Value m_interpreter_registerroot_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_equal(alg_property(v_this, "RootFile"), alg_string("")))) {
        return alg_nil();
    }
    (void)(alg_invoke(alg_property(v_this, "Modules"), "Put", (Value[]){alg_property(v_this, "RootFile"), alg_property(v_this, "Globals")}, 2));
    return alg_nil();
}

static Value m_interpreter_interpret_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    {
        AlgFrame frame_2;
        alg_push_frame(&frame_2);
        if (ALG_SETJMP(frame_2.jump) == 0) {
            {
                (void)(alg_invoke(v_this, "RegisterRoot", NULL, 0));
                (void)(alg_invoke(v_this, "Hoist", (Value[]){v_statements}, 1));
                {
                    volatile Value v_i = alg_widen(alg_int(0), "Integer");
                    (void)v_i;
                    while (alg_truthy(alg_less(v_i, alg_property(v_statements, "Length")))) {
                        {
                            {
                                volatile Value v_done = alg_is(alg_subscript_get(v_statements, v_i), "FunctionStmt");
                                (void)v_done;
                                if (alg_truthy(alg_is(alg_subscript_get(v_statements, v_i), "ClassStmt"))) {
                                    (void)((v_done = alg_invoke(alg_property(v_this, "HoistedClasses"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Name"), "Lexeme")}, 1)}, 1)));
                                }
                                if (alg_truthy(alg_not(v_done))) {
                                    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(v_statements, v_i)}, 1));
                                }
                            }
                            (void)((v_i = alg_widen(alg_add(v_i, alg_int(1)), "Integer")));
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

static Value m_interpreter_hoisttests_11_list_list_map_boolean_environment_map_string_list_map_set_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    Value v_tests = alg_widen(args[1], "List");
    (void)v_tests;
    Value v_byname = alg_widen(args[2], "Map");
    (void)v_byname;
    Value v_define = alg_widen(args[3], "Boolean");
    (void)v_define;
    Value v_scope = alg_widen(args[4], "Environment");
    (void)v_scope;
    Value v_declaredin = alg_widen(args[5], "Map");
    (void)v_declaredin;
    Value v_file = alg_widen(args[6], "String");
    (void)v_file;
    Value v_files = alg_widen(args[7], "List");
    (void)v_files;
    Value v_byfile = alg_widen(args[8], "Map");
    (void)v_byfile;
    Value v_hoisted = alg_widen(args[9], "Set");
    (void)v_hoisted;
    Value v_collect = alg_widen(args[10], "Boolean");
    (void)v_collect;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_statements, "Length")))) {
            {
                {
                    Value v_thestmt = alg_subscript_get(v_statements, v_i);
                    (void)v_thestmt;
                    if (alg_truthy(alg_is(v_thestmt, "ModuleStmt"))) {
                        {
                            if (alg_truthy(v_define)) {
                                (void)(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1));
                            }
                            if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Statements"), alg_nil()))) {
                                {
                                    Value v_mine = alg_not(alg_invoke(v_hoisted, "Contains", (Value[]){alg_str(alg_property(v_thestmt, "FileName"))}, 1));
                                    (void)v_mine;
                                    if (alg_truthy(v_mine)) {
                                        (void)(alg_invoke(v_hoisted, "Add", (Value[]){alg_str(alg_property(v_thestmt, "FileName"))}, 1));
                                    }
                                    (void)(alg_invoke(v_this, "HoistTests", (Value[]){alg_property(v_thestmt, "Statements"), v_tests, v_byname, alg_bool(false), alg_cast(alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_property(v_thestmt, "FileName")}, 1), "Environment"), v_declaredin, alg_str(alg_property(v_thestmt, "FileName")), v_files, v_byfile, v_hoisted, v_mine}, 11));
                                }
                            }
                        }
                    } else {
                        if (alg_truthy(alg_is(v_thestmt, "FunctionStmt"))) {
                            {
                                if (alg_truthy(v_define)) {
                                    (void)(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1));
                                }
                                if (alg_truthy((or_7 = alg_not_equal(alg_property(alg_property(v_thestmt, "Name"), "Literal"), alg_nil()), !alg_truthy(or_7) ? or_7 : v_collect))) {
                                    {
                                        (void)(alg_invoke(v_tests, "Add", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1));
                                        (void)(alg_invoke(v_byname, "Put", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_thestmt}, 2));
                                        (void)(alg_invoke(v_declaredin, "Put", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_scope}, 2));
                                        if (alg_truthy(alg_not(alg_invoke(v_files, "Contains", (Value[]){v_file}, 1)))) {
                                            {
                                                (void)(alg_invoke(v_files, "Add", (Value[]){v_file}, 1));
                                                (void)(alg_invoke(v_byfile, "Put", (Value[]){v_file, alg_list()}, 2));
                                            }
                                        }
                                        (void)(alg_invoke((alg_cast(alg_invoke(v_byfile, "Get", (Value[]){v_file}, 1), "List")), "Add", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1));
                                    }
                                }
                            }
                        } else {
                            if (alg_truthy((or_12 = v_define, !alg_truthy(or_12) ? or_12 : ((or_11 = (or_10 = (or_9 = (or_8 = alg_is(v_thestmt, "ClassStmt"), alg_truthy(or_8) ? or_8 : alg_is(v_thestmt, "ObjectStmt")), alg_truthy(or_9) ? or_9 : alg_is(v_thestmt, "EnumStmt")), alg_truthy(or_10) ? or_10 : alg_is(v_thestmt, "VarGroupStmt")), alg_truthy(or_11) ? or_11 : alg_is(v_thestmt, "VarStmt")))))) {
                                (void)(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1));
                            }
                        }
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_interpreter_runtests_2_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    volatile Value v_filename = alg_widen(args[1], "String");
    (void)v_filename;
    volatile Value v_tests = alg_nil();
    (void)v_tests;
    volatile Value v_passed = alg_nil();
    (void)v_passed;
    volatile Value v_failed = alg_nil();
    (void)v_failed;
    (void)(alg_set_property(v_this, "RootFile", alg_widen(alg_str(v_filename), "String")));
    (void)(alg_invoke(v_this, "RegisterRoot", NULL, 0));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("AssertTrue"), alg_new(k_asserttruenative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("AssertEqual"), alg_new(k_assertequalnative, NULL, 0)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Fail"), alg_new(k_failnative, NULL, 0)}, 2));
    (void)(f_suppressoutput(NULL, (Value[]){alg_bool(true)}, 1));
    (void)((v_tests = alg_widen(alg_list(), "List")));
    volatile Value v_byname = alg_map();
    (void)v_byname;
    volatile Value v_declaredin = alg_map();
    (void)v_declaredin;
    volatile Value v_files = alg_list();
    (void)v_files;
    volatile Value v_byfile = alg_map();
    (void)v_byfile;
    volatile Value v_hoisted = alg_set();
    (void)v_hoisted;
    (void)(alg_invoke(v_hoisted, "Add", (Value[]){v_filename}, 1));
    (void)(alg_invoke(v_this, "HoistTests", (Value[]){v_statements, v_tests, v_byname, alg_bool(true), alg_property(v_this, "Globals"), v_declaredin, v_filename, v_files, v_byfile, v_hoisted, alg_bool(true)}, 11));
    (void)(alg_writeln(alg_add(alg_add(alg_add((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag), alg_string("Running ")), alg_str(alg_property(v_tests, "Length"))), alg_string(" tests..."))));
    (void)((v_passed = alg_widen(alg_int(0), "Integer")));
    (void)((v_failed = alg_widen(alg_int(0), "Integer")));
    volatile Value v_ordered = alg_list();
    (void)v_ordered;
    {
        volatile Value v_f = alg_int(0);
        (void)v_f;
        while (alg_truthy(alg_less(v_f, alg_property(v_files, "Length")))) {
            {
                {
                    volatile Value v_group = alg_cast(alg_invoke(v_byfile, "Get", (Value[]){alg_subscript_get(v_files, v_f)}, 1), "List");
                    (void)v_group;
                    (void)(alg_invoke(v_group, "Sort", NULL, 0));
                    (void)(alg_invoke(v_ordered, "Add", (Value[]){alg_subscript_get(v_files, v_f)}, 1));
                    {
                        volatile Value v_j = alg_int(0);
                        (void)v_j;
                        while (alg_truthy(alg_less(v_j, alg_property(v_group, "Length")))) {
                            {
                                (void)(alg_invoke(v_ordered, "Add", (Value[]){alg_subscript_get(v_group, v_j)}, 1));
                                (void)((v_j = alg_add(v_j, alg_int(1))));
                            }
                        }
                    }
                }
                (void)((v_f = alg_add(v_f, alg_int(1))));
            }
        }
    }
    {
        volatile Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_ordered, "Length")))) {
            {
                {
                    if (alg_truthy(alg_not(alg_invoke(v_byname, "Contains", (Value[]){alg_subscript_get(v_ordered, v_i)}, 1)))) {
                        {
                            if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                                (void)(alg_writeln((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag)));
                            }
                            (void)(alg_writeln(alg_add(alg_add(alg_add(alg_add(alg_add((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag), alg_string("< ")), (alg_declared(d_ansiVcyan, "ANSI_CYAN"), v_ansiVcyan)), alg_str(alg_subscript_get(v_ordered, v_i))), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)), alg_string(" >"))));
                        }
                    } else {
                        {
                            volatile Value v_thetest = alg_invoke(v_byname, "Get", (Value[]){alg_subscript_get(v_ordered, v_i)}, 1);
                            (void)v_thetest;
                            volatile Value v_name = alg_str(alg_property(alg_property(v_thetest, "Name"), "Literal"));
                            (void)v_name;
                            {
                                AlgFrame frame_3;
                                alg_push_frame(&frame_3);
                                if (ALG_SETJMP(frame_3.jump) == 0) {
                                    {
                                        volatile Value v_scope = alg_property(v_this, "Globals");
                                        (void)v_scope;
                                        if (alg_truthy(alg_invoke(v_declaredin, "Contains", (Value[]){alg_subscript_get(v_ordered, v_i)}, 1))) {
                                            (void)((v_scope = alg_cast(alg_invoke(v_declaredin, "Get", (Value[]){alg_subscript_get(v_ordered, v_i)}, 1), "Environment")));
                                        }
                                        volatile Value v_body = alg_invoke(v_scope, "Get", (Value[]){alg_property(v_thetest, "Name")}, 1);
                                        (void)v_body;
                                        (void)(alg_invoke(v_body, "Call", (Value[]){v_this, alg_list()}, 2));
                                        (void)((v_passed = alg_widen(alg_add(v_passed, alg_int(1)), "Integer")));
                                        (void)(alg_writeln(alg_invoke(v_this, "Report", (Value[]){v_name, alg_string("PASS")}, 2)));
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
                                                (void)((v_failed = alg_widen(alg_add(v_failed, alg_int(1)), "Integer")));
                                                (void)(alg_writeln(alg_invoke(v_this, "Report", (Value[]){v_name, alg_string("FAIL")}, 2)));
                                                (void)(alg_writeln(alg_add(alg_add(alg_add((alg_declared(d_errorVtag, "ERROR_TAG"), v_errorVtag), v_filename), alg_string(": ")), v_e)));
                                            }
                                        }
                                    }
                                    else if (which_3 == 1) {
                                        {
                                            volatile Value v_e = frame_3.raised;
                                            (void)v_e;
                                            {
                                                (void)((v_failed = alg_widen(alg_add(v_failed, alg_int(1)), "Integer")));
                                                (void)(alg_writeln(alg_invoke(v_this, "Report", (Value[]){v_name, alg_string("FAIL")}, 2)));
                                                (void)(alg_writeln(alg_add(alg_add(alg_add((alg_declared(d_errorVtag, "ERROR_TAG"), v_errorVtag), v_filename), alg_string(": ")), alg_str(alg_property(v_e, "Value")))));
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
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    (void)(alg_writeln((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag)));
    if (alg_truthy(alg_equal(v_failed, alg_int(0)))) {
        (void)(alg_writeln(alg_add(alg_add(alg_add(alg_add(alg_add((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag), (alg_declared(d_ansiVgreen, "ANSI_GREEN"), v_ansiVgreen)), alg_string("All ")), alg_str(v_passed)), alg_string(" tests passed.")), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset))));
    } else {
        (void)(alg_writeln(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag), (alg_declared(d_ansiVred, "ANSI_RED"), v_ansiVred)), alg_str(v_failed)), alg_string(" of ")), alg_str(alg_add(v_passed, v_failed))), alg_string(" tests failed.")), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset))));
    }
    return v_failed;
    return alg_nil();
}

static Value m_interpreter_report_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_status = alg_widen(args[1], "String");
    (void)v_status;
    Value v_dots = alg_nil();
    (void)v_dots;
    (void)((v_dots = alg_widen(alg_subtract(alg_int(55), alg_text_length(v_name)), "Integer")));
    if (alg_truthy(alg_less(v_dots, alg_int(1)))) {
        (void)((v_dots = alg_widen(alg_int(1), "Integer")));
    }
    Value v_leader = alg_string("");
    (void)v_leader;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, v_dots))) {
            {
                (void)((v_leader = alg_add(v_leader, alg_char_value(46))));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    Value v_tint = (alg_declared(d_ansiVgreen, "ANSI_GREEN"), v_ansiVgreen);
    (void)v_tint;
    if (alg_truthy(alg_equal(v_status, alg_string("FAIL")))) {
        (void)((v_tint = (alg_declared(d_ansiVred, "ANSI_RED"), v_ansiVred)));
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag), alg_string("Test: ")), v_name), alg_char_value(32)), v_leader), alg_string(" [ ")), v_tint), v_status), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)), alg_string(" ]"));
    return alg_nil();
}

static Value m_interpreter_visitliteral_1_literalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "LiteralExpr");
    (void)v_theexpr;
    return alg_property(v_theexpr, "Value");
    return alg_nil();
}

static Value m_interpreter_visitlogical_1_logicalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "LogicalExpr");
    (void)v_theexpr;
    Value v_left = alg_nil();
    (void)v_left;
    (void)((v_left = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Left")}, 1)));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVor))) {
        {
            if (alg_truthy(alg_invoke(v_this, "IsTruthy", (Value[]){v_left}, 1))) {
                return v_left;
            }
        }
    } else {
        if (alg_truthy(alg_not(alg_invoke(v_this, "IsTruthy", (Value[]){v_left}, 1)))) {
            return v_left;
        }
    }
    return alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Right")}, 1);
    return alg_nil();
}

static Value m_interpreter_visitgrouping_1_groupingexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "GroupingExpr");
    (void)v_theexpr;
    return alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Expression")}, 1);
    return alg_nil();
}

static Value m_interpreter_visitunary_1_unaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "UnaryExpr");
    (void)v_theexpr;
    Value v_right = alg_nil();
    (void)v_right;
    (void)((v_right = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Right")}, 1)));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVminus))) {
        return alg_negate(v_right);
    } else {
        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVnot))) {
            return alg_not(alg_invoke(v_this, "IsTruthy", (Value[]){v_right}, 1));
        }
    }
    return alg_nil();
}

static Value m_interpreter_visitcollectionexpr_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    Value v_result = alg_nil();
    (void)v_result;
    if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
        {
            (void)((v_result = alg_widen(alg_new(k_objcollection, (Value[]){alg_string("Map")}, 1), "ObjCollection")));
            {
                Value v_i = alg_int(0);
                (void)v_i;
                while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Keys"), "Length")))) {
                    {
                        (void)(alg_invoke(alg_property(v_result, "Pairs"), "Put", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Keys"), v_i)}, 1), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Values"), v_i)}, 1)}, 2));
                        (void)((v_i = alg_add(v_i, alg_int(1))));
                    }
                }
            }
            return v_result;
        }
    }
    (void)((v_result = alg_widen(alg_new(k_objcollection, (Value[]){alg_string("List")}, 1), "ObjCollection")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Values"), "Length")))) {
            {
                (void)(alg_invoke(alg_property(v_result, "Items"), "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Values"), v_i)}, 1)}, 1));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return v_result;
    return alg_nil();
}

static Value m_interpreter_visitsubscriptexpr_1_subscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "SubscriptExpr");
    (void)v_theexpr;
    Value v_target = alg_nil();
    (void)v_target;
    Value v_index = alg_nil();
    (void)v_index;
    (void)((v_target = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)));
    (void)((v_index = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Index")}, 1)));
    if (alg_truthy(alg_is(v_target, "ObjCollection"))) {
        return alg_invoke(v_target, "At", (Value[]){v_index}, 1);
    }
    if (alg_truthy(alg_is(v_target, "ObjBuffer"))) {
        return alg_invoke(v_target, "At", (Value[]){v_index}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "IsText", (Value[]){v_target}, 1))) {
        return alg_subscript_get(alg_str(v_target), v_index);
    }
    alg_raise(alg_string("Subscript target should be an ordinal."));
    return alg_nil();
}

static Value m_interpreter_visitsetsubscriptexpr_1_setsubscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "SetSubscriptExpr");
    (void)v_theexpr;
    Value v_target = alg_nil();
    (void)v_target;
    Value v_index = alg_nil();
    (void)v_index;
    Value v_value = alg_nil();
    (void)v_value;
    (void)((v_target = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)));
    (void)((v_index = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Index")}, 1)));
    (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1)));
    if (alg_truthy(alg_is(v_target, "ObjCollection"))) {
        return alg_invoke(v_target, "PutAt", (Value[]){v_index, v_value}, 2);
    }
    if (alg_truthy(alg_is(v_target, "ObjBuffer"))) {
        return alg_invoke(v_target, "PutAt", (Value[]){v_index, v_value}, 2);
    }
    if (alg_truthy(alg_invoke(v_this, "IsText", (Value[]){v_target}, 1))) {
        alg_raise(alg_string("Strings are immutable."));
    }
    alg_raise(alg_string("Subscript target should be an ordinal."));
    return alg_nil();
}

static Value m_interpreter_istext_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_obj = args[0];
    (void)v_obj;
    return (or_13 = alg_is(v_obj, "String"), alg_truthy(or_13) ? or_13 : alg_is(v_obj, "Char"));
    return alg_nil();
}

static Value m_interpreter_insubrange_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_value = args[0];
    (void)v_value;
    Value v_thename = alg_widen(args[1], "String");
    (void)v_thename;
    Value v_at = alg_nil();
    (void)v_at;
    if (alg_truthy(alg_not((alg_is(v_value, "Integer"))))) {
        return alg_bool(false);
    }
    (void)((v_at = alg_widen(f_subrangeindex(NULL, (Value[]){v_thename}, 1), "Integer")));
    return (or_14 = alg_greater_equal(v_value, alg_subscript_get((alg_declared(d_subrangeVlows, "SUBRANGE_LOWS"), v_subrangeVlows), v_at)), !alg_truthy(or_14) ? or_14 : alg_less_equal(v_value, alg_subscript_get((alg_declared(d_subrangeVhighs, "SUBRANGE_HIGHS"), v_subrangeVhighs), v_at)));
    return alg_nil();
}

static Value m_interpreter_satisfiestype_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_value = args[0];
    (void)v_value;
    Value v_thename = alg_widen(args[1], "String");
    (void)v_thename;
    if (alg_truthy(f_issubrange(NULL, (Value[]){v_thename}, 1))) {
        return alg_invoke(v_this, "InSubrange", (Value[]){v_value, v_thename}, 2);
    }
    Value v_wanted = f_canonicaltype(NULL, (Value[]){v_thename}, 1);
    (void)v_wanted;
    if (alg_truthy(alg_equal(f_tolower(NULL, (Value[]){f_typenameof(NULL, (Value[]){v_value}, 1)}, 1), f_tolower(NULL, (Value[]){v_wanted}, 1)))) {
        return alg_bool(true);
    }
    return f_inheritsfrom(NULL, (Value[]){v_value, v_wanted}, 2);
    return alg_nil();
}

static Value m_interpreter_visitisexpr_1_isexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "IsExpr");
    (void)v_theexpr;
    Value v_value = alg_nil();
    (void)v_value;
    (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)));
    if (alg_truthy(alg_equal(v_value, alg_nil()))) {
        return alg_bool(false);
    }
    return alg_invoke(v_this, "SatisfiesType", (Value[]){v_value, alg_str(alg_property(alg_property(v_theexpr, "TypeName"), "Lexeme"))}, 2);
    return alg_nil();
}

static Value m_interpreter_visitvariableexpr_1_variableexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_theexpr = alg_widen(args[0], "VariableExpr");
    (void)v_theexpr;
    {
        AlgFrame frame_4;
        alg_push_frame(&frame_4);
        if (ALG_SETJMP(frame_4.jump) == 0) {
            {
                volatile Value ret_5 = alg_invoke(v_this, "LookupVariable", (Value[]){alg_property(v_theexpr, "Name"), v_theexpr}, 2);
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
                    return alg_invoke(v_this, "ThisField", (Value[]){alg_property(v_theexpr, "Name"), v_e}, 2);
                }
            }
            else {
                alg_raise(frame_4.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_interpreter_thisfield_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    volatile Value v_original = alg_widen(args[1], "String");
    (void)v_original;
    volatile Value v_obj = alg_nil();
    (void)v_obj;
    {
        AlgFrame frame_6;
        alg_push_frame(&frame_6);
        if (ALG_SETJMP(frame_6.jump) == 0) {
            {
                (void)((v_obj = alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_new(k_token, (Value[]){e_tokentype_tokenVthis, alg_string("this"), alg_nil(), alg_property(v_name, "LineNumber")}, 4)}, 1)));
                volatile Value ret_7 = alg_invoke(v_obj, "Get", (Value[]){v_name}, 1);
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
                    alg_raise(v_original);
                }
            }
            else {
                alg_raise(frame_6.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_interpreter_setthisfield_3_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    volatile Value v_value = args[1];
    (void)v_value;
    volatile Value v_original = alg_widen(args[2], "String");
    (void)v_original;
    volatile Value v_obj = alg_nil();
    (void)v_obj;
    {
        AlgFrame frame_8;
        alg_push_frame(&frame_8);
        if (ALG_SETJMP(frame_8.jump) == 0) {
            {
                (void)((v_obj = alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_new(k_token, (Value[]){e_tokentype_tokenVthis, alg_string("this"), alg_nil(), alg_property(v_name, "LineNumber")}, 4)}, 1)));
                (void)(alg_invoke(v_obj, "Set", (Value[]){v_name, v_value}, 2));
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
                    alg_raise(v_original);
                }
            }
            else {
                alg_raise(frame_8.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_interpreter_lookupvariable_2_token_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    volatile Value v_theexpr = alg_widen(args[1], "Expr");
    (void)v_theexpr;
    volatile Value v_distance = alg_nil();
    (void)v_distance;
    (void)((v_distance = alg_widen(alg_cast(alg_invoke(alg_property(v_this, "Locals"), "Get", (Value[]){v_theexpr}, 1), "Integer"), "Integer")));
    if (alg_truthy(alg_not_equal(v_distance, alg_nil()))) {
        return alg_invoke(alg_property(v_this, "Env"), "GetAt", (Value[]){v_distance, alg_property(v_name, "Lexeme")}, 2);
    }
    {
        AlgFrame frame_9;
        alg_push_frame(&frame_9);
        if (ALG_SETJMP(frame_9.jump) == 0) {
            {
                volatile Value ret_10 = alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){v_name}, 1);
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
                    alg_raise(alg_invoke(v_this, "SuggestUnit", (Value[]){v_name, v_e}, 2));
                }
            }
            else {
                alg_raise(frame_9.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_interpreter_suggestunit_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_message = alg_widen(args[1], "String");
    (void)v_message;
    if (alg_truthy(alg_not_equal(alg_copy(v_message, alg_int(0), alg_int(19)), alg_string("Undefined variable ")))) {
        return alg_str(v_message);
    }
    Value v_units = alg_invoke(alg_property(v_this, "UnitsByName"), "Keys", NULL, 0);
    (void)v_units;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_units, "Length")))) {
            {
                {
                    Value v_moduleenv = alg_cast(alg_invoke(alg_property(v_this, "UnitsByName"), "Get", (Value[]){alg_subscript_get(v_units, v_i)}, 1), "Environment");
                    (void)v_moduleenv;
                    if (alg_truthy((or_15 = alg_not_equal(alg_property(v_moduleenv, "Exports"), alg_nil()), !alg_truthy(or_15) ? or_15 : alg_invoke(alg_property(v_moduleenv, "Exports"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1)))) {
                        return alg_add(alg_add(alg_add(alg_str(v_message), alg_string(" Unit '")), alg_str(alg_property(v_moduleenv, "UnitName"))), alg_string("' exports it; this file has no 'uses' for it."));
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    if (alg_truthy((or_16 = alg_not_equal(alg_property(v_this, "Env"), alg_property(v_this, "Globals")), !alg_truthy(or_16) ? or_16 : alg_invoke(alg_property(alg_property(v_this, "Globals"), "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1)))) {
        return alg_add(alg_str(v_message), alg_string(" The file the program started from declares it, and no file can 'uses' that."));
    }
    return alg_str(v_message);
    return alg_nil();
}

static Value m_interpreter_integerdivide_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_left = args[0];
    (void)v_left;
    Value v_right = args[1];
    (void)v_right;
    if (alg_truthy((or_17 = alg_not((alg_is(v_left, "Integer"))), alg_truthy(or_17) ? or_17 : alg_not((alg_is(v_right, "Integer")))))) {
        alg_raise(alg_string("div expects Integers."));
    }
    if (alg_truthy(alg_equal(v_right, alg_int(0)))) {
        alg_raise(alg_string("Division by zero."));
    }
    return alg_divide(v_left, v_right);
    return alg_nil();
}

static Value m_interpreter_visitbinary_1_binaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "BinaryExpr");
    (void)v_theexpr;
    Value v_left = alg_nil();
    (void)v_left;
    Value v_right = alg_nil();
    (void)v_right;
    (void)((v_left = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Left")}, 1)));
    (void)((v_right = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Right")}, 1)));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVgreater))) {
        return alg_greater(v_left, v_right);
    } else {
        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVgreaterVequal))) {
            return alg_greater_equal(v_left, v_right);
        } else {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVless))) {
                return alg_less(v_left, v_right);
            } else {
                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVlessVequal))) {
                    return alg_less_equal(v_left, v_right);
                } else {
                    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVnotVequal))) {
                        return alg_not(alg_invoke(v_this, "IsEqual", (Value[]){v_left, v_right}, 2));
                    } else {
                        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVequal))) {
                            return alg_invoke(v_this, "IsEqual", (Value[]){v_left, v_right}, 2);
                        } else {
                            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVin))) {
                                return alg_invoke(v_this, "Contains", (Value[]){v_right, v_left}, 2);
                            } else {
                                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVplus))) {
                                    return alg_add(v_left, v_right);
                                } else {
                                    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVminus))) {
                                        return alg_subtract(v_left, v_right);
                                    } else {
                                        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVslash))) {
                                            return alg_divide(v_left, v_right);
                                        } else {
                                            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVdiv))) {
                                                return alg_invoke(v_this, "IntegerDivide", (Value[]){v_left, v_right}, 2);
                                            } else {
                                                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVstar))) {
                                                    return alg_multiply(v_left, v_right);
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
    }
    return alg_nil();
}

static Value m_interpreter_visitcall_1_callexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "CallExpr");
    (void)v_theexpr;
    Value v_callee = alg_nil();
    (void)v_callee;
    Value v_arguments = alg_nil();
    (void)v_arguments;
    (void)((v_callee = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Callee")}, 1)));
    (void)((v_arguments = alg_widen(alg_list(), "List")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Arguments"), "Length")))) {
            {
                {
                    (void)(alg_invoke(v_arguments, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Arguments"), v_i)}, 1)}, 1));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_not(alg_invoke(v_this, "IsCallable", (Value[]){v_callee}, 1)))) {
        {
            alg_raise(alg_string("Can only call functions and classes."));
        }
    }
    if (alg_truthy(alg_is(v_callee, "ObjFunction"))) {
        {
            if (alg_truthy(alg_not_equal(alg_property(v_callee, "Owner"), alg_nil()))) {
                {
                    Value v_better = alg_invoke(alg_property(v_callee, "Owner"), "FindOverload", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_property(v_callee, "Declaration"), "Name"), "Lexeme")}, 1), v_arguments}, 2);
                    (void)v_better;
                    if (alg_truthy(alg_equal(v_better, alg_nil()))) {
                        alg_raise(alg_string("No matching signature for function."));
                    }
                    (void)((v_callee = alg_invoke(v_better, "Bind", (Value[]){alg_property(v_callee, "Bound")}, 1)));
                }
            } else {
                if (alg_truthy((or_18 = alg_not(alg_invoke(v_callee, "Fits", (Value[]){v_arguments, alg_bool(true)}, 2)), !alg_truthy(or_18) ? or_18 : alg_not(alg_invoke(v_callee, "Absorbs", (Value[]){v_arguments}, 1))))) {
                    {
                        if (alg_truthy((or_19 = alg_not(alg_invoke(v_callee, "Variadic", NULL, 0)), !alg_truthy(or_19) ? or_19 : alg_not_equal(alg_property(v_arguments, "Length"), alg_invoke(v_callee, "Arity", NULL, 0))))) {
                            alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Expected "), alg_invoke(v_callee, "Arity", NULL, 0)), alg_string(" arguments but got ")), alg_property(v_arguments, "Length")), alg_char_value(46)));
                        }
                        alg_raise(alg_string("No matching signature for function."));
                    }
                }
            }
        }
    }
    Value v_gathering = alg_bool(false);
    (void)v_gathering;
    if (alg_truthy(alg_is(v_callee, "ObjFunction"))) {
        (void)((v_gathering = alg_invoke(v_callee, "Absorbs", (Value[]){v_arguments}, 1)));
    }
    if (alg_truthy((or_21 = (or_20 = alg_not(v_gathering), !alg_truthy(or_20) ? or_20 : alg_greater_equal(alg_invoke(v_callee, "Arity", NULL, 0), alg_int(0))), !alg_truthy(or_21) ? or_21 : alg_not_equal(alg_property(v_arguments, "Length"), alg_invoke(v_callee, "Arity", NULL, 0))))) {
        {
            alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Expected "), alg_invoke(v_callee, "Arity", NULL, 0)), alg_string(" arguments but got ")), alg_property(v_arguments, "Length")), alg_char_value(46)));
        }
    }
    return alg_invoke(v_callee, "Call", (Value[]){v_this, v_arguments}, 2);
    return alg_nil();
}

static Value m_interpreter_assignqualified_3_string_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_unit = alg_widen(args[0], "String");
    (void)v_unit;
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    Value v_value = args[2];
    (void)v_value;
    Value v_moduleenv = alg_nil();
    (void)v_moduleenv;
    if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){v_unit}, 1), alg_string("system")))) {
        alg_raise(alg_add(alg_add(alg_string("Can't assign to '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' in unit 'System'.")));
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "UnitsByName"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_unit}, 1)}, 1)))) {
        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' in unit '")), v_unit), alg_string("'.")));
    }
    (void)((v_moduleenv = alg_widen(alg_cast(alg_invoke(alg_property(v_this, "UnitsByName"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_unit}, 1)}, 1), "Environment"), "Environment")));
    if (alg_truthy((or_22 = alg_equal(alg_property(v_moduleenv, "Exports"), alg_nil()), alg_truthy(or_22) ? or_22 : alg_not(alg_invoke(alg_property(v_moduleenv, "Exports"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))))) {
        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' in unit '")), v_unit), alg_string("'.")));
    }
    (void)(alg_invoke(alg_property(v_moduleenv, "Values"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_value}, 2));
    return alg_nil();
}

static Value m_interpreter_qualified_2_string_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_unit = alg_widen(args[0], "String");
    (void)v_unit;
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    Value v_moduleenv = alg_nil();
    (void)v_moduleenv;
    if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){v_unit}, 1), alg_string("system")))) {
        {
            if (alg_truthy(alg_not(alg_invoke(alg_property(alg_property(v_this, "Builtins"), "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1)))) {
                alg_raise(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' in unit 'System'.")));
            }
            return alg_invoke(alg_property(alg_property(v_this, "Builtins"), "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1);
        }
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "UnitsByName"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_unit}, 1)}, 1)))) {
        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' in unit '")), v_unit), alg_string("'.")));
    }
    (void)((v_moduleenv = alg_widen(alg_cast(alg_invoke(alg_property(v_this, "UnitsByName"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_unit}, 1)}, 1), "Environment"), "Environment")));
    if (alg_truthy((or_23 = alg_equal(alg_property(v_moduleenv, "Exports"), alg_nil()), alg_truthy(or_23) ? or_23 : alg_not(alg_invoke(alg_property(v_moduleenv, "Exports"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))))) {
        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' in unit '")), v_unit), alg_string("'.")));
    }
    return alg_invoke(alg_property(v_moduleenv, "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1);
    return alg_nil();
}

static Value m_interpreter_visitgetexpr_1_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "GetExpr");
    (void)v_theexpr;
    Value v_obj = alg_nil();
    (void)v_obj;
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Unit"), alg_string("")))) {
        return alg_invoke(v_this, "Qualified", (Value[]){alg_property(v_theexpr, "Unit"), alg_property(v_theexpr, "Name")}, 2);
    }
    (void)((v_obj = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)));
    if (alg_truthy(alg_is(v_obj, "String"))) {
        {
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1), alg_string("length")))) {
                return alg_text_length(v_obj);
            }
            alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))), alg_string("'.")));
        }
    }
    if (alg_truthy((or_24 = alg_is(v_obj, "Integer"), alg_truthy(or_24) ? or_24 : alg_is(v_obj, "Double")))) {
        {
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1), alg_string("tostring")))) {
                return alg_new(k_numbermethod, (Value[]){v_obj, alg_property(v_theexpr, "Name")}, 2);
            }
            alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))), alg_string("'.")));
        }
    }
    if (alg_truthy(alg_not(((or_29 = (or_28 = (or_27 = (or_26 = (or_25 = alg_is(v_obj, "ObjInstance"), alg_truthy(or_25) ? or_25 : alg_is(v_obj, "ObjEnumType")), alg_truthy(or_26) ? or_26 : alg_is(v_obj, "ObjEnum")), alg_truthy(or_27) ? or_27 : alg_is(v_obj, "ObjCollection")), alg_truthy(or_28) ? or_28 : alg_is(v_obj, "ObjFile")), alg_truthy(or_29) ? or_29 : alg_is(v_obj, "ObjBuffer")))))) {
        {
            alg_raise(alg_string("Only instances have properties."));
        }
    }
    return alg_invoke(v_obj, "Get", (Value[]){alg_property(v_theexpr, "Name")}, 1);
    return alg_nil();
}

static Value m_interpreter_visitsetexpr_1_setexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "SetExpr");
    (void)v_theexpr;
    Value v_obj = alg_nil();
    (void)v_obj;
    Value v_value = alg_nil();
    (void)v_value;
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Unit"), alg_string("")))) {
        {
            (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1)));
            (void)(alg_invoke(v_this, "AssignQualified", (Value[]){alg_str(alg_property(v_theexpr, "Unit")), alg_property(v_theexpr, "Name"), v_value}, 3));
            return v_value;
        }
    }
    (void)((v_obj = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)));
    if (alg_truthy(alg_not((alg_is(v_obj, "ObjInstance"))))) {
        {
            alg_raise(alg_string("Only instances have fields."));
        }
    }
    (void)((v_value = alg_invoke(v_this, "Widen", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1), alg_str(alg_property(v_theexpr, "Declared"))}, 2)));
    (void)(alg_invoke(v_obj, "Set", (Value[]){alg_property(v_theexpr, "Name"), v_value}, 2));
    return v_value;
    return alg_nil();
}

static Value m_interpreter_visitsuperexpr_1_superexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "SuperExpr");
    (void)v_theexpr;
    Value v_distance = alg_nil();
    (void)v_distance;
    Value v_superclass = alg_nil();
    (void)v_superclass;
    Value v_obj = alg_nil();
    (void)v_obj;
    Value v_method = alg_nil();
    (void)v_method;
    (void)((v_distance = alg_widen(alg_cast(alg_invoke(alg_property(v_this, "Locals"), "Get", (Value[]){v_theexpr}, 1), "Integer"), "Integer")));
    (void)((v_superclass = alg_widen(alg_cast(alg_invoke(alg_property(v_this, "Env"), "GetAt", (Value[]){v_distance, alg_string("super")}, 2), "ObjClass"), "ObjClass")));
    (void)((v_obj = alg_widen(alg_cast(alg_invoke(alg_property(v_this, "Env"), "GetAt", (Value[]){alg_subtract(v_distance, alg_int(1)), alg_string("this")}, 2), "ObjInstance"), "ObjInstance")));
    (void)((v_method = alg_widen(alg_invoke(v_superclass, "FindMethod", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_theexpr, "Method"), "Lexeme")}, 1)}, 1), "ObjFunction")));
    return alg_invoke(v_method, "Bind", (Value[]){v_obj}, 1);
    return alg_nil();
}

static Value m_interpreter_visitthisexpr_1_thisexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "ThisExpr");
    (void)v_theexpr;
    return alg_invoke(v_this, "LookupVariable", (Value[]){alg_property(v_theexpr, "Keyword"), v_theexpr}, 2);
    return alg_nil();
}

static Value m_interpreter_classnameof_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_obj = args[0];
    (void)v_obj;
    {
        AlgFrame frame_11;
        alg_push_frame(&frame_11);
        if (ALG_SETJMP(frame_11.jump) == 0) {
            {
                volatile Value ret_12 = alg_property(v_obj, "ClassName");
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

static Value m_interpreter_istruthy_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_obj = args[0];
    (void)v_obj;
    if (alg_truthy((or_30 = alg_equal(v_obj, alg_nil()), alg_truthy(or_30) ? or_30 : alg_equal(v_obj, alg_bool(false))))) {
        return alg_bool(false);
    }
    if (alg_truthy(alg_is(v_obj, "Integer"))) {
        return alg_not_equal(v_obj, alg_int(0));
    }
    if (alg_truthy(alg_is(v_obj, "ObjEnum"))) {
        return alg_not_equal(alg_property(v_obj, "Ordinal"), alg_int(0));
    }
    return alg_bool(true);
    return alg_nil();
}

static Value m_interpreter_isequal_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_a = args[0];
    (void)v_a;
    Value v_b = args[1];
    (void)v_b;
    if (alg_truthy((or_31 = alg_equal(v_a, alg_nil()), !alg_truthy(or_31) ? or_31 : alg_equal(v_b, alg_nil())))) {
        return alg_bool(true);
    }
    if (alg_truthy(alg_equal(v_a, alg_nil()))) {
        return alg_bool(false);
    }
    return alg_equal(v_a, v_b);
    return alg_nil();
}

static Value m_interpreter_widen_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_value = args[0];
    (void)v_value;
    Value v_declared = alg_widen(args[1], "String");
    (void)v_declared;
    if (alg_truthy((or_32 = alg_equal(v_declared, alg_string("")), alg_truthy(or_32) ? or_32 : alg_equal(v_value, alg_nil())))) {
        return v_value;
    }
    if (alg_truthy(f_issubrange(NULL, (Value[]){v_declared}, 1))) {
        {
            if (alg_truthy(alg_not(alg_invoke(v_this, "InSubrange", (Value[]){v_value, v_declared}, 2)))) {
                alg_raise(alg_add(alg_add(alg_add(alg_str(v_value), alg_string(" is not in ")), v_declared), alg_char_value(46)));
            }
            return v_value;
        }
    }
    if (alg_truthy((or_33 = alg_equal(v_declared, alg_string("Double")), !alg_truthy(or_33) ? or_33 : alg_is(v_value, "Integer")))) {
        return alg_multiply(v_value, alg_double(1.0));
    }
    if (alg_truthy((or_34 = alg_equal(v_declared, alg_string("String")), !alg_truthy(or_34) ? or_34 : alg_is(v_value, "Char")))) {
        return alg_str(v_value);
    }
    return v_value;
    return alg_nil();
}

static Value m_interpreter_evaluate_1_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "Expr");
    (void)v_theexpr;
    Value v_value = alg_nil();
    (void)v_value;
    (void)((v_value = alg_invoke(v_theexpr, "Accept", (Value[]){v_this}, 1)));
    if (alg_truthy((or_35 = alg_not_equal(alg_property(v_theexpr, "Cast"), alg_string("")), !alg_truthy(or_35) ? or_35 : alg_not_equal(v_value, alg_nil())))) {
        {
            if (alg_truthy(alg_not(alg_invoke(v_this, "SatisfiesType", (Value[]){v_value, alg_property(v_theexpr, "Cast")}, 2)))) {
                alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Cannot cast "), f_typenameof(NULL, (Value[]){v_value}, 1)), alg_string(" to ")), alg_property(v_theexpr, "Cast")), alg_char_value(46)));
            }
        }
    }
    return v_value;
    return alg_nil();
}

static Value m_interpreter_execute_1_stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "Stmt");
    (void)v_thestmt;
    (void)(alg_invoke(v_thestmt, "Accept", (Value[]){v_this}, 1));
    return alg_nil();
}

static Value m_interpreter_resolve_2_expr_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "Expr");
    (void)v_theexpr;
    Value v_depth = alg_widen(args[1], "Integer");
    (void)v_depth;
    (void)(alg_invoke(alg_property(v_this, "Locals"), "Put", (Value[]){v_theexpr, v_depth}, 2));
    return alg_nil();
}

static Value m_interpreter_executeblock_2_list_environment(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    volatile Value v_newenv = alg_widen(args[1], "Environment");
    (void)v_newenv;
    volatile Value v_previousenv = alg_nil();
    (void)v_previousenv;
    (void)((v_previousenv = alg_widen(alg_cast(alg_property(v_this, "Env"), "Environment"), "Environment")));
    {
        AlgFrame frame_13;
        alg_push_frame(&frame_13);
        if (ALG_SETJMP(frame_13.jump) == 0) {
            {
                (void)(alg_set_property(v_this, "Env", alg_widen(v_newenv, "Environment")));
                {
                    volatile Value v_i = alg_int(0);
                    (void)v_i;
                    while (alg_truthy(alg_less(v_i, alg_property(v_statements, "Length")))) {
                        {
                            {
                                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(v_statements, v_i)}, 1));
                            }
                            (void)((v_i = alg_add(v_i, alg_int(1))));
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
                    (void)(alg_set_property(v_this, "Env", alg_widen(v_previousenv, "Environment")));
                    alg_raise(v_e);
                }
            }
        }
    }
    (void)(alg_set_property(v_this, "Env", alg_widen(v_previousenv, "Environment")));
    return alg_nil();
}

static Value m_interpreter_visitblockstmt_1_blockstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "BlockStmt");
    (void)v_thestmt;
    Value v_newenv = alg_widen(alg_new(k_environment, NULL, 0), "Environment");
    (void)v_newenv;
    (void)(alg_set_property(v_newenv, "Enclosing", alg_widen(alg_property(v_this, "Env"), "Environment")));
    (void)(alg_invoke(v_this, "ExecuteBlock", (Value[]){alg_property(v_thestmt, "Statements"), v_newenv}, 2));
    return alg_nil();
}

static Value m_interpreter_visitclassstmt_1_classstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "ClassStmt");
    (void)v_thestmt;
    Value v_klass = alg_nil();
    (void)v_klass;
    Value v_superclass = alg_nil();
    (void)v_superclass;
    Value v_methods = alg_nil();
    (void)v_methods;
    Value v_thefunction = alg_nil();
    (void)v_thefunction;
    (void)((v_superclass = alg_nil()));
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Superclass"), alg_nil()))) {
        {
            (void)((v_superclass = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Superclass")}, 1)));
            if (alg_truthy(alg_not((alg_is(v_superclass, "ObjClass"))))) {
                {
                    alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_property(alg_property(v_thestmt, "Superclass"), "Name"), "Lexeme"))), alg_string("' is not a class.")));
                }
            }
        }
    }
    Value v_shell = alg_invoke(v_this, "HoistedClass", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1);
    (void)v_shell;
    if (alg_truthy(alg_equal(v_shell, alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_nil()}, 2));
    }
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Superclass"), alg_nil()))) {
        {
            Value v_previous = alg_widen(alg_property(v_this, "Env"), "Environment");
            (void)v_previous;
            (void)(alg_set_property(v_this, "Env", alg_widen(alg_new(k_environment, NULL, 0), "Environment")));
            (void)(alg_set_property(alg_property(v_this, "Env"), "Enclosing", alg_widen(v_previous, "Environment")));
            (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_string("super"), v_superclass}, 2));
        }
    }
    (void)((v_methods = alg_widen(alg_map(), "Map")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Methods"), "Length")))) {
            {
                {
                    Value v_method = alg_subscript_get(alg_property(v_thestmt, "Methods"), v_i);
                    (void)v_method;
                    (void)((v_thefunction = alg_widen(alg_new(k_objfunction, (Value[]){v_method, alg_property(v_this, "Env"), alg_equal(f_foldcase(NULL, (Value[]){alg_property(alg_property(v_method, "Name"), "Lexeme")}, 1), alg_string("init"))}, 3), "ObjFunction")));
                    Value v_methodkey = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_method, "Name"), "Lexeme")}, 1);
                    (void)v_methodkey;
                    if (alg_truthy(alg_not(alg_invoke(v_methods, "Contains", (Value[]){v_methodkey}, 1)))) {
                        (void)(alg_invoke(v_methods, "Put", (Value[]){v_methodkey, alg_list()}, 2));
                    }
                    (void)(alg_invoke(alg_invoke(v_methods, "Get", (Value[]){v_methodkey}, 1), "Add", (Value[]){v_thefunction}, 1));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_not_equal(v_shell, alg_nil()))) {
        {
            (void)((v_klass = alg_widen(alg_cast(v_shell, "ObjClass"), "ObjClass")));
            (void)(alg_set_property(v_klass, "Superclass", alg_widen(alg_cast(v_superclass, "ObjClass"), "ObjClass")));
            (void)(alg_set_property(v_klass, "Methods", alg_widen(v_methods, "Map")));
            (void)(alg_set_property(v_klass, "Fields", alg_widen(alg_property(v_thestmt, "Fields"), "List")));
        }
    } else {
        (void)((v_klass = alg_widen(alg_cast(alg_new(k_objclass, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_superclass, v_methods, alg_property(v_thestmt, "Fields")}, 4), "ObjClass"), "ObjClass")));
    }
    {
        Value loop_14 = alg_iterable(alg_invoke(v_methods, "Keys", NULL, 0));
        for (int32_t at_14 = 0; at_14 < alg_iterable_count(loop_14); at_14++) {
            Value v_name = alg_iterable_at(loop_14, at_14);
            (void)v_name;
            {
                Value v_i = alg_int(0);
                (void)v_i;
                while (alg_truthy(alg_less(v_i, alg_property(alg_invoke(v_methods, "Get", (Value[]){v_name}, 1), "Length")))) {
                    {
                        (void)(alg_set_property(alg_subscript_get(alg_invoke(v_methods, "Get", (Value[]){v_name}, 1), v_i), "Owner", v_klass));
                        (void)((v_i = alg_add(v_i, alg_int(1))));
                    }
                }
            }
        }
    }
    if (alg_truthy(alg_not_equal(v_superclass, alg_nil()))) {
        {
            (void)(alg_set_property(v_this, "Env", alg_widen(alg_cast(alg_property(alg_property(v_this, "Env"), "Enclosing"), "Environment"), "Environment")));
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Assign", (Value[]){alg_property(v_thestmt, "Name"), v_klass}, 2));
    return alg_nil();
}

static Value m_interpreter_visitobjectstmt_1_objectstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "ObjectStmt");
    (void)v_thestmt;
    Value v_klass = alg_nil();
    (void)v_klass;
    Value v_hasid = alg_bool(false);
    (void)v_hasid;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Fields"), "Length")))) {
            {
                if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_subscript_get(alg_property(v_thestmt, "Fields"), v_i), "Name"), "Lexeme")}, 1), alg_string("id")))) {
                    (void)((v_hasid = alg_bool(true)));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_not(v_hasid))) {
        {
            Value v_idname = alg_new(k_token, (Value[]){e_tokentype_tokenVidentifier, alg_string("Id"), alg_nil(), alg_property(alg_property(v_thestmt, "Name"), "LineNumber")}, 4);
            (void)v_idname;
            (void)(alg_invoke(alg_property(v_thestmt, "Fields"), "Add", (Value[]){alg_new(k_varstmt, (Value[]){v_idname, alg_new(k_literalexpr, (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)}, 2)}, 1));
        }
    }
    (void)(alg_invoke(v_this, "VisitClassStmt", (Value[]){alg_new(k_classstmt, (Value[]){alg_property(v_thestmt, "Name"), alg_property(v_thestmt, "Superclass"), alg_property(v_thestmt, "Methods"), alg_property(v_thestmt, "Fields")}, 4)}, 1));
    (void)((v_klass = alg_widen(alg_cast(alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_property(v_thestmt, "Name")}, 1), "ObjClass"), "ObjClass")));
    (void)(alg_invoke(alg_property(v_this, "Env"), "Assign", (Value[]){alg_property(v_thestmt, "Name"), alg_new(k_objsingleton, (Value[]){v_klass, v_this}, 2)}, 2));
    return alg_nil();
}

static Value m_interpreter_visitsubrangestmt_1_subrangestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "SubrangeStmt");
    (void)v_thestmt;
    return alg_nil();
}

static Value m_interpreter_visitenumstmt_1_enumstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "EnumStmt");
    (void)v_thestmt;
    Value v_thetype = alg_nil();
    (void)v_thetype;
    (void)((v_thetype = alg_widen(alg_new(k_objenumtype, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), "ObjEnumType")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Members"), "Length")))) {
            {
                {
                    Value v_membername = alg_str(alg_property(alg_subscript_get(alg_property(v_thestmt, "Members"), v_i), "Lexeme"));
                    (void)v_membername;
                    Value v_member = alg_invoke(v_thetype, "Add", (Value[]){v_membername}, 1);
                    (void)v_member;
                    Value v_clash = alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_membername}, 1)}, 1);
                    (void)v_clash;
                    if (alg_truthy(v_clash)) {
                        (void)((v_clash = alg_is(alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_membername}, 1)}, 1), "ObjEnum")));
                    }
                    if (alg_truthy(v_clash)) {
                        (void)((v_clash = alg_not_equal(alg_property((alg_cast(alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_membername}, 1)}, 1), "ObjEnum")), "TypeName"), alg_property(v_thetype, "Name"))));
                    }
                    if (alg_truthy(v_clash)) {
                        (void)(alg_invoke(alg_property(v_this, "Env"), "MarkAmbiguous", (Value[]){v_membername, alg_add(alg_add(alg_property((alg_cast(alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_membername}, 1)}, 1), "ObjEnum")), "TypeName"), alg_string(" or ")), alg_property(v_thetype, "Name"))}, 2));
                    } else {
                        (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){v_membername, v_member}, 2));
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_thetype}, 2));
    return alg_nil();
}

static Value m_interpreter_visitexpressionstmt_1_expressionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = alg_widen(args[0], "ExpressionStmt");
    (void)v_stmt;
    (void)(alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_stmt, "Expression")}, 1));
    return alg_nil();
}

static Value m_interpreter_visitfunctionstmt_1_functionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "FunctionStmt");
    (void)v_thestmt;
    Value v_thefunction = alg_nil();
    (void)v_thefunction;
    (void)((v_thefunction = alg_widen(alg_new(k_objfunction, (Value[]){v_thestmt, alg_property(v_this, "Env"), alg_bool(false)}, 3), "ObjFunction")));
    Value v_key = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1);
    (void)v_key;
    if (alg_truthy(alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Contains", (Value[]){v_key}, 1))) {
        {
            Value v_existing = alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Get", (Value[]){v_key}, 1);
            (void)v_existing;
            if (alg_truthy((or_36 = alg_not((alg_is(v_existing, "ObjFunction"))), !alg_truthy(or_36) ? or_36 : alg_not((alg_is(v_existing, "ObjOverloads")))))) {
                alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))), alg_string("' is already defined.")));
            }
            Value v_overloads = v_existing;
            (void)v_overloads;
            if (alg_truthy(alg_is(v_existing, "ObjFunction"))) {
                {
                    (void)((v_overloads = alg_new(k_objoverloads, (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)));
                    (void)(alg_invoke(v_overloads, "Add", (Value[]){v_existing}, 1));
                }
            }
            {
                Value v_i = alg_int(0);
                (void)v_i;
                while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_overloads, "Candidates"), "Length")))) {
                    {
                        if (alg_truthy(f_samesignature(NULL, (Value[]){alg_property(alg_subscript_get(alg_property(v_overloads, "Candidates"), v_i), "Declaration"), v_thestmt}, 2))) {
                            alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))), alg_string("' is already defined.")));
                        }
                        (void)((v_i = alg_add(v_i, alg_int(1))));
                    }
                }
            }
            (void)(alg_invoke(v_overloads, "Add", (Value[]){v_thefunction}, 1));
            (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_overloads}, 2));
            return alg_nil();
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_thefunction}, 2));
    return alg_nil();
}

static Value m_interpreter_visitifstmt_1_ifstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = alg_widen(args[0], "IfStmt");
    (void)v_stmt;
    if (alg_truthy(alg_invoke(v_this, "IsTruthy", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_stmt, "Condition")}, 1)}, 1))) {
        (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_stmt, "ThenBranch")}, 1));
    } else {
        if (alg_truthy(alg_not_equal(alg_property(v_stmt, "ElseBranch"), alg_nil()))) {
            (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_stmt, "ElseBranch")}, 1));
        }
    }
    return alg_nil();
}

static Value m_interpreter_visitwhilestmt_1_whilestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_stmt = alg_widen(args[0], "WhileStmt");
    (void)v_stmt;
    {
        AlgFrame frame_15;
        alg_push_frame(&frame_15);
        if (ALG_SETJMP(frame_15.jump) == 0) {
            {
                while (alg_truthy(alg_invoke(v_this, "IsTruthy", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_stmt, "Condition")}, 1)}, 1))) {
                    {
                        (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_stmt, "Body")}, 1));
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

static Value m_interpreter_contains_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_collection = args[0];
    (void)v_collection;
    Value v_value = args[1];
    (void)v_value;
    if (alg_truthy(alg_is(v_collection, "ObjCollection"))) {
        return alg_invoke(v_collection, "Invoke", (Value[]){alg_string("contains"), alg_list_keep(alg_list(), v_value)}, 2);
    }
    if (alg_truthy(alg_is(v_collection, "ObjEnumType"))) {
        return alg_invoke(alg_invoke(alg_property(v_collection, "Members"), "Values", NULL, 0), "Contains", (Value[]){v_value}, 1);
    }
    if (alg_truthy(alg_is(v_collection, "ObjInstance"))) {
        {
            Value v_method = alg_invoke(alg_property(v_collection, "Klass"), "FindMethod", (Value[]){alg_string("contains")}, 1);
            (void)v_method;
            if (alg_truthy(alg_not_equal(v_method, alg_nil()))) {
                return alg_invoke(v_this, "IsTruthy", (Value[]){alg_invoke(alg_invoke(v_method, "Bind", (Value[]){v_collection}, 1), "Call", (Value[]){v_this, alg_list_keep(alg_list(), v_value)}, 2)}, 1);
            }
        }
    }
    if (alg_truthy(alg_invoke(v_this, "IsText", (Value[]){v_collection}, 1))) {
        {
            if (alg_truthy(alg_equal(v_value, alg_nil()))) {
                return alg_bool(false);
            }
            return alg_greater_equal(alg_pos(alg_str(v_collection), alg_str(v_value)), alg_int(0));
        }
    }
    alg_raise(alg_string("Right operand of 'in' must be a collection or a String."));
    return alg_nil();
}

static Value m_interpreter_iscallable_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_value = args[0];
    (void)v_value;
    if (alg_truthy(alg_equal(v_value, alg_nil()))) {
        return alg_bool(false);
    }
    {
        AlgFrame frame_16;
        alg_push_frame(&frame_16);
        if (ALG_SETJMP(frame_16.jump) == 0) {
            {
                volatile Value v_thearity = alg_property(v_value, "Arity");
                (void)v_thearity;
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

static Value m_interpreter_elementsof_2_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_where = alg_widen(args[0], "Token");
    (void)v_where;
    Value v_target = args[1];
    (void)v_target;
    Value v_result = alg_nil();
    (void)v_result;
    (void)((v_result = alg_widen(alg_list(), "List")));
    if (alg_truthy(alg_is(v_target, "ObjCollection"))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_target, "Kind"), alg_string("Map")))) {
                return alg_invoke(alg_property(v_target, "Pairs"), "Keys", NULL, 0);
            }
            {
                Value v_i = alg_int(0);
                (void)v_i;
                while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_target, "Items"), "Length")))) {
                    {
                        (void)(alg_invoke(v_result, "Add", (Value[]){alg_subscript_get(alg_property(v_target, "Items"), v_i)}, 1));
                        (void)((v_i = alg_add(v_i, alg_int(1))));
                    }
                }
            }
            return v_result;
        }
    }
    if (alg_truthy(alg_is(v_target, "ObjEnumType"))) {
        return alg_invoke(alg_property(v_target, "Members"), "Values", NULL, 0);
    }
    if (alg_truthy(alg_is(v_target, "ObjInstance"))) {
        {
            Value v_elements = alg_invoke(alg_property(v_target, "Klass"), "FindMethod", (Value[]){alg_string("elements")}, 1);
            (void)v_elements;
            if (alg_truthy(alg_not_equal(v_elements, alg_nil()))) {
                return alg_invoke(v_this, "ElementsOf", (Value[]){v_where, alg_invoke(alg_invoke(v_elements, "Bind", (Value[]){v_target}, 1), "Call", (Value[]){v_this, alg_list()}, 2)}, 2);
            }
        }
    }
    if (alg_truthy(alg_invoke(v_this, "IsText", (Value[]){v_target}, 1))) {
        {
            Value v_text = alg_str(v_target);
            (void)v_text;
            {
                Value v_i = alg_int(0);
                (void)v_i;
                while (alg_truthy(alg_less(v_i, alg_text_length(v_text)))) {
                    {
                        (void)(alg_invoke(v_result, "Add", (Value[]){alg_subscript_get(v_text, v_i)}, 1));
                        (void)((v_i = alg_add(v_i, alg_int(1))));
                    }
                }
            }
            return v_result;
        }
    }
    alg_raise(alg_string("Can only iterate a collection or a String."));
    return alg_nil();
}

static Value m_interpreter_visitforinstmt_1_forinstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_thestmt = alg_widen(args[0], "ForInStmt");
    (void)v_thestmt;
    volatile Value v_elements = alg_nil();
    (void)v_elements;
    (void)((v_elements = alg_widen(alg_invoke(v_this, "ElementsOf", (Value[]){alg_property(v_thestmt, "Name"), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Iterable")}, 1)}, 2), "List")));
    {
        AlgFrame frame_18;
        alg_push_frame(&frame_18);
        if (ALG_SETJMP(frame_18.jump) == 0) {
            {
                {
                    volatile Value v_i = alg_int(0);
                    (void)v_i;
                    while (alg_truthy(alg_less(v_i, alg_property(v_elements, "Length")))) {
                        {
                            {
                                volatile Value v_scope = alg_new(k_environment, NULL, 0);
                                (void)v_scope;
                                (void)(alg_set_property(v_scope, "Enclosing", alg_widen(alg_property(v_this, "Env"), "Environment")));
                                (void)(alg_invoke(v_scope, "Define", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_subscript_get(v_elements, v_i)}, 2));
                                (void)(alg_invoke(v_this, "ExecuteBlock", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "Body")), v_scope}, 2));
                            }
                            (void)((v_i = alg_add(v_i, alg_int(1))));
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

static Value m_interpreter_visitbreakstmt_1_breakstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "BreakStmt");
    (void)v_thestmt;
    alg_raise(alg_new(k_broke, NULL, 0));
    return alg_nil();
}

static Value m_interpreter_visitmodulestmt_1_modulestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "ModuleStmt");
    (void)v_thestmt;
    Value v_importer = alg_nil();
    (void)v_importer;
    Value v_moduleenv = alg_nil();
    (void)v_moduleenv;
    Value v_exported = alg_nil();
    (void)v_exported;
    (void)((v_importer = alg_widen(alg_property(v_this, "Env"), "Environment")));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Modules"), "Contains", (Value[]){alg_property(v_thestmt, "FileName")}, 1))) {
        {
            Value v_already = alg_cast(alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_property(v_thestmt, "FileName")}, 1), "Environment");
            (void)v_already;
            if (alg_truthy(alg_equal(alg_property(v_already, "UnitName"), alg_string("")))) {
                (void)(alg_set_property(v_already, "UnitName", alg_widen(alg_str(alg_property(v_thestmt, "UnitName")), "String")));
            }
            (void)(alg_invoke(alg_property(v_importer, "Imports"), "Add", (Value[]){alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_property(v_thestmt, "FileName")}, 1)}, 1));
            (void)(alg_invoke(alg_property(v_this, "UnitsByName"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_thestmt, "UnitName")}, 1), alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_property(v_thestmt, "FileName")}, 1)}, 2));
            return alg_nil();
        }
    }
    (void)((v_moduleenv = alg_widen(alg_new(k_environment, NULL, 0), "Environment")));
    (void)(alg_set_property(v_moduleenv, "Enclosing", alg_widen(alg_property(v_this, "Builtins"), "Environment")));
    (void)(alg_set_property(v_moduleenv, "UnitName", alg_widen(alg_str(alg_property(v_thestmt, "UnitName")), "String")));
    (void)(alg_invoke(alg_property(v_this, "Modules"), "Put", (Value[]){alg_property(v_thestmt, "FileName"), v_moduleenv}, 2));
    (void)(alg_invoke(v_this, "ExecuteBlock", (Value[]){alg_property(v_thestmt, "Statements"), v_moduleenv}, 2));
    (void)((v_exported = alg_widen(alg_list(), "List")));
    Value v_hidden = alg_set();
    (void)v_hidden;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "PrivateNames"), "Length")))) {
            {
                (void)(alg_invoke(v_hidden, "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_subscript_get(alg_property(v_thestmt, "PrivateNames"), v_i)}, 1)}, 1));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    Value v_names = alg_invoke(alg_property(v_moduleenv, "Values"), "Keys", NULL, 0);
    (void)v_names;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_names, "Length")))) {
            {
                {
                    Value v_thename = alg_subscript_get(v_names, v_i);
                    (void)v_thename;
                    if (alg_truthy(alg_not(alg_invoke(v_hidden, "Contains", (Value[]){v_thename}, 1)))) {
                        (void)(alg_invoke(v_exported, "Add", (Value[]){v_thename}, 1));
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    (void)(alg_set_property(v_moduleenv, "Exports", alg_widen(alg_set(), "Set")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_exported, "Length")))) {
            {
                (void)(alg_invoke(alg_property(v_moduleenv, "Exports"), "Add", (Value[]){alg_subscript_get(v_exported, v_i)}, 1));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_importer, "Imports"), "Add", (Value[]){v_moduleenv}, 1));
    (void)(alg_invoke(alg_property(v_this, "UnitsByName"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_thestmt, "UnitName")}, 1), v_moduleenv}, 2));
    return alg_nil();
}

static Value m_interpreter_visitraisestmt_1_raisestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "RaiseStmt");
    (void)v_thestmt;
    alg_raise(alg_new(k_raised, (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Value")}, 1)}, 1));
    return alg_nil();
}

static Value m_interpreter_findhandler_2_map(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_handlers = alg_widen(args[0], "Map");
    (void)v_handlers;
    Value v_value = args[1];
    (void)v_value;
    Value v_klass = alg_nil();
    (void)v_klass;
    if (alg_truthy(alg_is(v_value, "ObjInstance"))) {
        {
            (void)((v_klass = alg_widen(alg_cast(alg_property(v_value, "Klass"), "ObjClass"), "ObjClass")));
            while (alg_truthy(alg_not_equal(v_klass, alg_nil()))) {
                {
                    Value v_thename = alg_str(alg_property(v_klass, "Name"));
                    (void)v_thename;
                    if (alg_truthy(alg_invoke(v_handlers, "Contains", (Value[]){v_thename}, 1))) {
                        return alg_cast(alg_invoke(v_handlers, "Get", (Value[]){v_thename}, 1), "ExceptHandler");
                    }
                    (void)((v_klass = alg_widen(alg_property(v_klass, "Superclass"), "ObjClass")));
                }
            }
            return alg_nil();
        }
    }
    Value v_typename = f_typenameof(NULL, (Value[]){v_value}, 1);
    (void)v_typename;
    if (alg_truthy(alg_invoke(v_handlers, "Contains", (Value[]){v_typename}, 1))) {
        return alg_cast(alg_invoke(v_handlers, "Get", (Value[]){v_typename}, 1), "ExceptHandler");
    }
    return alg_nil();
    return alg_nil();
}

static Value m_interpreter_handle_3_trystmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "TryStmt");
    (void)v_thestmt;
    Value v_value = args[1];
    (void)v_value;
    Value v_original = args[2];
    (void)v_original;
    Value v_handler = alg_nil();
    (void)v_handler;
    (void)((v_handler = alg_widen(alg_invoke(v_this, "FindHandler", (Value[]){alg_property(v_thestmt, "Handlers"), v_value}, 2), "ExceptHandler")));
    if (alg_truthy((or_37 = alg_equal(v_handler, alg_nil()), !alg_truthy(or_37) ? or_37 : alg_invoke(alg_property(v_thestmt, "Handlers"), "Contains", (Value[]){alg_string("default")}, 1)))) {
        (void)((v_handler = alg_widen(alg_cast(alg_invoke(alg_property(v_thestmt, "Handlers"), "Get", (Value[]){alg_string("default")}, 1), "ExceptHandler"), "ExceptHandler")));
    }
    if (alg_truthy(alg_equal(v_handler, alg_nil()))) {
        alg_raise(v_original);
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(v_handler, "Name"), v_value}, 2));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_handler, "Body")}, 1));
    return alg_nil();
}

static Value m_interpreter_visittrystmt_1_trystmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_thestmt = alg_widen(args[0], "TryStmt");
    (void)v_thestmt;
    {
        AlgFrame frame_19;
        alg_push_frame(&frame_19);
        if (ALG_SETJMP(frame_19.jump) == 0) {
            {
                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "TryBlock")}, 1));
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
                    (void)(alg_invoke(v_this, "Handle", (Value[]){v_thestmt, alg_property(v_e, "Value"), v_e}, 3));
                }
            }
            else if (which_19 == 2) {
                {
                    volatile Value v_e = frame_19.raised;
                    (void)v_e;
                    (void)(alg_invoke(v_this, "Handle", (Value[]){v_thestmt, v_e, v_e}, 3));
                }
            }
            else {
                alg_raise(frame_19.raised);
            }
        }
    }
    return alg_nil();
}

static Value m_interpreter_visitreturnstmt_1_returnstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = alg_widen(args[0], "ReturnStmt");
    (void)v_stmt;
    Value v_value = alg_nil();
    (void)v_value;
    if (alg_truthy(alg_not_equal(alg_property(v_stmt, "Value"), alg_nil()))) {
        (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_stmt, "Value")}, 1)));
    }
    alg_raise(alg_new(k_return, (Value[]){v_value}, 1));
    return alg_nil();
}

static Value m_interpreter_visitvarstmt_1_varstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = alg_widen(args[0], "VarStmt");
    (void)v_stmt;
    Value v_value = alg_nil();
    (void)v_value;
    if (alg_truthy(alg_not_equal(alg_property(v_stmt, "Initializer"), alg_nil()))) {
        {
            (void)((v_value = alg_invoke(v_this, "Widen", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_stmt, "Initializer")}, 1), alg_str(alg_property(v_stmt, "TypeName"))}, 2)));
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_stmt, "Name"), "Lexeme"), v_value}, 2));
    return alg_nil();
}

static Value m_interpreter_visitvargroupstmt_1_vargroupstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "VarGroupStmt");
    (void)v_thestmt;
    Value v_value = alg_nil();
    (void)v_value;
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Initializer"), alg_nil()))) {
        (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Initializer")}, 1)));
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Names"), "Length")))) {
            {
                (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_subscript_get(alg_property(v_thestmt, "Names"), v_i), "Lexeme"), v_value}, 2));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_interpreter_visitassignexpr_1_assignexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_expr = alg_widen(args[0], "AssignExpr");
    (void)v_expr;
    volatile Value v_value = alg_nil();
    (void)v_value;
    volatile Value v_distance = alg_nil();
    (void)v_distance;
    (void)((v_value = alg_invoke(v_this, "Widen", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_expr, "Value")}, 1), alg_str(alg_property(v_expr, "Declared"))}, 2)));
    (void)((v_distance = alg_widen(alg_cast(alg_invoke(alg_property(v_this, "Locals"), "Get", (Value[]){v_expr}, 1), "Integer"), "Integer")));
    if (alg_truthy(alg_not_equal(v_distance, alg_nil()))) {
        {
            {
                AlgFrame frame_20;
                alg_push_frame(&frame_20);
                if (ALG_SETJMP(frame_20.jump) == 0) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Env"), "AssignAt", (Value[]){v_distance, alg_property(v_expr, "Name"), v_value}, 3));
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
                            (void)(alg_invoke(v_this, "SetThisField", (Value[]){alg_property(v_expr, "Name"), v_value, v_e}, 3));
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
                        (void)(alg_invoke(alg_property(v_this, "Env"), "Assign", (Value[]){alg_property(v_expr, "Name"), v_value}, 2));
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
                            (void)(alg_invoke(v_this, "SetThisField", (Value[]){alg_property(v_expr, "Name"), v_value, v_e}, 3));
                        }
                    }
                    else {
                        alg_raise(frame_21.raised);
                    }
                }
            }
        }
    }
    return v_value;
    return alg_nil();
}

static Value i_broke(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value i_raised(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Value", alg_nil());
    return alg_nil();
}

static Value m_raised_init_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_value = args[0];
    (void)v_value;
    (void)(alg_set_property(v_this, "Value", v_value));
    return alg_nil();
}

static Value i_return(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Value", alg_nil());
    return alg_nil();
}

static Value m_return_init_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_value = args[0];
    (void)v_value;
    (void)(alg_set_property(v_this, "Value", v_value));
    return alg_nil();
}

void init_Interpreter(void) {
    k_clocknative = alg_class("ClockNative", alg_nil());
    k_lengthnative = alg_class("LengthNative", alg_nil());
    k_copynative = alg_class("CopyNative", alg_nil());
    k_posnative = alg_class("PosNative", alg_nil());
    k_arraynative = alg_class("ArrayNative", alg_nil());
    k_listnative = alg_class("ListNative", alg_nil());
    k_mapnative = alg_class("MapNative", alg_nil());
    k_setnative = alg_class("SetNative", alg_nil());
    k_stacknative = alg_class("StackNative", alg_nil());
    k_writenative = alg_class("WriteNative", alg_nil());
    k_writelnnative = alg_class("WriteLnNative", alg_nil());
    k_haltnative = alg_class("HaltNative", alg_nil());
    k_ordnative = alg_class("OrdNative", alg_nil());
    k_valnative = alg_class("ValNative", alg_nil());
    k_charnative = alg_class("CharNative", alg_nil());
    k_maxnative = alg_class("MaxNative", alg_nil());
    k_modnative = alg_class("ModNative", alg_nil());
    k_textfilenative = alg_class("TextFileNative", alg_nil());
    k_buffernative = alg_class("BufferNative", alg_nil());
    k_fileexistsnative = alg_class("FileExistsNative", alg_nil());
    k_paramcountnative = alg_class("ParamCountNative", alg_nil());
    k_paramstrnative = alg_class("ParamStrNative", alg_nil());
    k_strnative = alg_class("StrNative", alg_nil());
    k_asserttruenative = alg_class("AssertTrueNative", alg_nil());
    k_assertequalnative = alg_class("AssertEqualNative", alg_nil());
    k_failnative = alg_class("FailNative", alg_nil());
    k_interpreter = alg_class("Interpreter", alg_nil());
    k_broke = alg_class("Broke", alg_nil());
    k_raised = alg_class("Raised", alg_nil());
    k_return = alg_class("Return", alg_nil());
    alg_class_initializer(k_clocknative, i_clocknative);
    alg_class_method(k_clocknative, "Arity", m_clocknative_arity_0, 0, NULL);
    alg_class_method(k_clocknative, "Call", m_clocknative_call_2, 2, t_clocknative_call_2);
    alg_class_initializer(k_lengthnative, i_lengthnative);
    alg_class_method(k_lengthnative, "Arity", m_lengthnative_arity_0, 0, NULL);
    alg_class_method(k_lengthnative, "Call", m_lengthnative_call_2, 2, t_lengthnative_call_2);
    alg_class_initializer(k_copynative, i_copynative);
    alg_class_method(k_copynative, "Arity", m_copynative_arity_0, 0, NULL);
    alg_class_method(k_copynative, "Call", m_copynative_call_2, 2, t_copynative_call_2);
    alg_class_initializer(k_posnative, i_posnative);
    alg_class_method(k_posnative, "Arity", m_posnative_arity_0, 0, NULL);
    alg_class_method(k_posnative, "Call", m_posnative_call_2, 2, t_posnative_call_2);
    alg_class_initializer(k_arraynative, i_arraynative);
    alg_class_method(k_arraynative, "Arity", m_arraynative_arity_0, 0, NULL);
    alg_class_method(k_arraynative, "Call", m_arraynative_call_2, 2, t_arraynative_call_2);
    alg_class_initializer(k_listnative, i_listnative);
    alg_class_method(k_listnative, "Arity", m_listnative_arity_0, 0, NULL);
    alg_class_method(k_listnative, "Call", m_listnative_call_2, 2, t_listnative_call_2);
    alg_class_initializer(k_mapnative, i_mapnative);
    alg_class_method(k_mapnative, "Arity", m_mapnative_arity_0, 0, NULL);
    alg_class_method(k_mapnative, "Call", m_mapnative_call_2, 2, t_mapnative_call_2);
    alg_class_initializer(k_setnative, i_setnative);
    alg_class_method(k_setnative, "Arity", m_setnative_arity_0, 0, NULL);
    alg_class_method(k_setnative, "Call", m_setnative_call_2, 2, t_setnative_call_2);
    alg_class_initializer(k_stacknative, i_stacknative);
    alg_class_method(k_stacknative, "Arity", m_stacknative_arity_0, 0, NULL);
    alg_class_method(k_stacknative, "Call", m_stacknative_call_2, 2, t_stacknative_call_2);
    fn_setprogramarguments = alg_closure("SetProgramArguments", f_setprogramarguments, NULL, 0, 1);
    fn_suppressoutput = alg_closure("SuppressOutput", f_suppressoutput, NULL, 0, 1);
    fn_rendered = alg_closure("Rendered", f_rendered, NULL, 0, 2);
    alg_class_initializer(k_writenative, i_writenative);
    alg_class_method(k_writenative, "Arity", m_writenative_arity_0, 0, NULL);
    alg_class_method(k_writenative, "Call", m_writenative_call_2, 2, t_writenative_call_2);
    alg_class_initializer(k_writelnnative, i_writelnnative);
    alg_class_method(k_writelnnative, "Arity", m_writelnnative_arity_0, 0, NULL);
    alg_class_method(k_writelnnative, "Call", m_writelnnative_call_2, 2, t_writelnnative_call_2);
    alg_class_initializer(k_haltnative, i_haltnative);
    alg_class_method(k_haltnative, "Arity", m_haltnative_arity_0, 0, NULL);
    alg_class_method(k_haltnative, "Call", m_haltnative_call_2, 2, t_haltnative_call_2);
    alg_class_initializer(k_ordnative, i_ordnative);
    alg_class_method(k_ordnative, "Arity", m_ordnative_arity_0, 0, NULL);
    alg_class_method(k_ordnative, "Call", m_ordnative_call_2, 2, t_ordnative_call_2);
    alg_class_initializer(k_valnative, i_valnative);
    alg_class_method(k_valnative, "Arity", m_valnative_arity_0, 0, NULL);
    alg_class_method(k_valnative, "Call", m_valnative_call_2, 2, t_valnative_call_2);
    alg_class_initializer(k_charnative, i_charnative);
    alg_class_method(k_charnative, "Arity", m_charnative_arity_0, 0, NULL);
    alg_class_method(k_charnative, "Call", m_charnative_call_2, 2, t_charnative_call_2);
    alg_class_initializer(k_maxnative, i_maxnative);
    alg_class_method(k_maxnative, "Arity", m_maxnative_arity_0, 0, NULL);
    alg_class_method(k_maxnative, "Call", m_maxnative_call_2, 2, t_maxnative_call_2);
    alg_class_initializer(k_modnative, i_modnative);
    alg_class_method(k_modnative, "Arity", m_modnative_arity_0, 0, NULL);
    alg_class_method(k_modnative, "Call", m_modnative_call_2, 2, t_modnative_call_2);
    alg_class_initializer(k_textfilenative, i_textfilenative);
    alg_class_method(k_textfilenative, "Arity", m_textfilenative_arity_0, 0, NULL);
    alg_class_method(k_textfilenative, "Call", m_textfilenative_call_2, 2, t_textfilenative_call_2);
    alg_class_initializer(k_buffernative, i_buffernative);
    alg_class_method(k_buffernative, "Arity", m_buffernative_arity_0, 0, NULL);
    alg_class_method(k_buffernative, "Call", m_buffernative_call_2, 2, t_buffernative_call_2);
    alg_class_initializer(k_fileexistsnative, i_fileexistsnative);
    alg_class_method(k_fileexistsnative, "Arity", m_fileexistsnative_arity_0, 0, NULL);
    alg_class_method(k_fileexistsnative, "Call", m_fileexistsnative_call_2, 2, t_fileexistsnative_call_2);
    alg_class_initializer(k_paramcountnative, i_paramcountnative);
    alg_class_method(k_paramcountnative, "Arity", m_paramcountnative_arity_0, 0, NULL);
    alg_class_method(k_paramcountnative, "Call", m_paramcountnative_call_2, 2, t_paramcountnative_call_2);
    alg_class_initializer(k_paramstrnative, i_paramstrnative);
    alg_class_method(k_paramstrnative, "Arity", m_paramstrnative_arity_0, 0, NULL);
    alg_class_method(k_paramstrnative, "Call", m_paramstrnative_call_2, 2, t_paramstrnative_call_2);
    fn_stringify = alg_closure("Stringify", f_stringify, NULL, 0, 2);
    alg_class_initializer(k_strnative, i_strnative);
    alg_class_method(k_strnative, "Arity", m_strnative_arity_0, 0, NULL);
    alg_class_method(k_strnative, "Call", m_strnative_call_2, 2, t_strnative_call_2);
    alg_class_initializer(k_asserttruenative, i_asserttruenative);
    alg_class_method(k_asserttruenative, "Arity", m_asserttruenative_arity_0, 0, NULL);
    alg_class_method(k_asserttruenative, "Call", m_asserttruenative_call_2, 2, t_asserttruenative_call_2);
    alg_class_initializer(k_assertequalnative, i_assertequalnative);
    alg_class_method(k_assertequalnative, "Arity", m_assertequalnative_arity_0, 0, NULL);
    alg_class_method(k_assertequalnative, "Call", m_assertequalnative_call_2, 2, t_assertequalnative_call_2);
    alg_class_initializer(k_failnative, i_failnative);
    alg_class_method(k_failnative, "Arity", m_failnative_arity_0, 0, NULL);
    alg_class_method(k_failnative, "Call", m_failnative_call_2, 2, t_failnative_call_2);
    alg_class_field(k_interpreter, "Env");
    alg_class_field(k_interpreter, "Builtins");
    alg_class_field(k_interpreter, "Globals");
    alg_class_field(k_interpreter, "Locals");
    alg_class_field(k_interpreter, "Modules");
    alg_class_field(k_interpreter, "HoistedClasses");
    alg_class_field(k_interpreter, "RootFile");
    alg_class_field(k_interpreter, "UnitsByName");
    alg_class_initializer(k_interpreter, i_interpreter);
    alg_class_method(k_interpreter, "Init", m_interpreter_init_0, 0, NULL);
    alg_class_method(k_interpreter, "Hoist", m_interpreter_hoist_1_list, 1, t_interpreter_hoist_1_list);
    alg_class_method(k_interpreter, "HoistedClass", m_interpreter_hoistedclass_1_string, 1, t_interpreter_hoistedclass_1_string);
    alg_class_method(k_interpreter, "RegisterRoot", m_interpreter_registerroot_0, 0, NULL);
    alg_class_method(k_interpreter, "Interpret", m_interpreter_interpret_1_list, 1, t_interpreter_interpret_1_list);
    alg_class_method(k_interpreter, "HoistTests", m_interpreter_hoisttests_11_list_list_map_boolean_environment_map_string_list_map_set_boolean, 11, t_interpreter_hoisttests_11_list_list_map_boolean_environment_map_string_list_map_set_boolean);
    alg_class_method(k_interpreter, "RunTests", m_interpreter_runtests_2_list_string, 2, t_interpreter_runtests_2_list_string);
    alg_class_method(k_interpreter, "Report", m_interpreter_report_2_string_string, 2, t_interpreter_report_2_string_string);
    alg_class_method(k_interpreter, "VisitLiteral", m_interpreter_visitliteral_1_literalexpr, 1, t_interpreter_visitliteral_1_literalexpr);
    alg_class_method(k_interpreter, "VisitLogical", m_interpreter_visitlogical_1_logicalexpr, 1, t_interpreter_visitlogical_1_logicalexpr);
    alg_class_method(k_interpreter, "VisitGrouping", m_interpreter_visitgrouping_1_groupingexpr, 1, t_interpreter_visitgrouping_1_groupingexpr);
    alg_class_method(k_interpreter, "VisitUnary", m_interpreter_visitunary_1_unaryexpr, 1, t_interpreter_visitunary_1_unaryexpr);
    alg_class_method(k_interpreter, "VisitCollectionExpr", m_interpreter_visitcollectionexpr_1_collectionexpr, 1, t_interpreter_visitcollectionexpr_1_collectionexpr);
    alg_class_method(k_interpreter, "VisitSubscriptExpr", m_interpreter_visitsubscriptexpr_1_subscriptexpr, 1, t_interpreter_visitsubscriptexpr_1_subscriptexpr);
    alg_class_method(k_interpreter, "VisitSetSubscriptExpr", m_interpreter_visitsetsubscriptexpr_1_setsubscriptexpr, 1, t_interpreter_visitsetsubscriptexpr_1_setsubscriptexpr);
    alg_class_method(k_interpreter, "IsText", m_interpreter_istext_1, 1, t_interpreter_istext_1);
    alg_class_method(k_interpreter, "InSubrange", m_interpreter_insubrange_2_string, 2, t_interpreter_insubrange_2_string);
    alg_class_method(k_interpreter, "SatisfiesType", m_interpreter_satisfiestype_2_string, 2, t_interpreter_satisfiestype_2_string);
    alg_class_method(k_interpreter, "VisitIsExpr", m_interpreter_visitisexpr_1_isexpr, 1, t_interpreter_visitisexpr_1_isexpr);
    alg_class_method(k_interpreter, "VisitVariableExpr", m_interpreter_visitvariableexpr_1_variableexpr, 1, t_interpreter_visitvariableexpr_1_variableexpr);
    alg_class_method(k_interpreter, "ThisField", m_interpreter_thisfield_2_token_string, 2, t_interpreter_thisfield_2_token_string);
    alg_class_method(k_interpreter, "SetThisField", m_interpreter_setthisfield_3_token_string, 3, t_interpreter_setthisfield_3_token_string);
    alg_class_method(k_interpreter, "LookupVariable", m_interpreter_lookupvariable_2_token_expr, 2, t_interpreter_lookupvariable_2_token_expr);
    alg_class_method(k_interpreter, "SuggestUnit", m_interpreter_suggestunit_2_token_string, 2, t_interpreter_suggestunit_2_token_string);
    alg_class_method(k_interpreter, "IntegerDivide", m_interpreter_integerdivide_2, 2, t_interpreter_integerdivide_2);
    alg_class_method(k_interpreter, "VisitBinary", m_interpreter_visitbinary_1_binaryexpr, 1, t_interpreter_visitbinary_1_binaryexpr);
    alg_class_method(k_interpreter, "VisitCall", m_interpreter_visitcall_1_callexpr, 1, t_interpreter_visitcall_1_callexpr);
    alg_class_method(k_interpreter, "AssignQualified", m_interpreter_assignqualified_3_string_token, 3, t_interpreter_assignqualified_3_string_token);
    alg_class_method(k_interpreter, "Qualified", m_interpreter_qualified_2_string_token, 2, t_interpreter_qualified_2_string_token);
    alg_class_method(k_interpreter, "VisitGetExpr", m_interpreter_visitgetexpr_1_getexpr, 1, t_interpreter_visitgetexpr_1_getexpr);
    alg_class_method(k_interpreter, "VisitSetExpr", m_interpreter_visitsetexpr_1_setexpr, 1, t_interpreter_visitsetexpr_1_setexpr);
    alg_class_method(k_interpreter, "VisitSuperExpr", m_interpreter_visitsuperexpr_1_superexpr, 1, t_interpreter_visitsuperexpr_1_superexpr);
    alg_class_method(k_interpreter, "VisitThisExpr", m_interpreter_visitthisexpr_1_thisexpr, 1, t_interpreter_visitthisexpr_1_thisexpr);
    alg_class_method(k_interpreter, "ClassNameOf", m_interpreter_classnameof_1, 1, t_interpreter_classnameof_1);
    alg_class_method(k_interpreter, "IsTruthy", m_interpreter_istruthy_1, 1, t_interpreter_istruthy_1);
    alg_class_method(k_interpreter, "IsEqual", m_interpreter_isequal_2, 2, t_interpreter_isequal_2);
    alg_class_method(k_interpreter, "Widen", m_interpreter_widen_2_string, 2, t_interpreter_widen_2_string);
    alg_class_method(k_interpreter, "Evaluate", m_interpreter_evaluate_1_expr, 1, t_interpreter_evaluate_1_expr);
    alg_class_method(k_interpreter, "Execute", m_interpreter_execute_1_stmt, 1, t_interpreter_execute_1_stmt);
    alg_class_method(k_interpreter, "Resolve", m_interpreter_resolve_2_expr_integer, 2, t_interpreter_resolve_2_expr_integer);
    alg_class_method(k_interpreter, "ExecuteBlock", m_interpreter_executeblock_2_list_environment, 2, t_interpreter_executeblock_2_list_environment);
    alg_class_method(k_interpreter, "VisitBlockStmt", m_interpreter_visitblockstmt_1_blockstmt, 1, t_interpreter_visitblockstmt_1_blockstmt);
    alg_class_method(k_interpreter, "VisitClassStmt", m_interpreter_visitclassstmt_1_classstmt, 1, t_interpreter_visitclassstmt_1_classstmt);
    alg_class_method(k_interpreter, "VisitObjectStmt", m_interpreter_visitobjectstmt_1_objectstmt, 1, t_interpreter_visitobjectstmt_1_objectstmt);
    alg_class_method(k_interpreter, "VisitSubrangeStmt", m_interpreter_visitsubrangestmt_1_subrangestmt, 1, t_interpreter_visitsubrangestmt_1_subrangestmt);
    alg_class_method(k_interpreter, "VisitEnumStmt", m_interpreter_visitenumstmt_1_enumstmt, 1, t_interpreter_visitenumstmt_1_enumstmt);
    alg_class_method(k_interpreter, "VisitExpressionStmt", m_interpreter_visitexpressionstmt_1_expressionstmt, 1, t_interpreter_visitexpressionstmt_1_expressionstmt);
    alg_class_method(k_interpreter, "VisitFunctionStmt", m_interpreter_visitfunctionstmt_1_functionstmt, 1, t_interpreter_visitfunctionstmt_1_functionstmt);
    alg_class_method(k_interpreter, "VisitIfStmt", m_interpreter_visitifstmt_1_ifstmt, 1, t_interpreter_visitifstmt_1_ifstmt);
    alg_class_method(k_interpreter, "VisitWhileStmt", m_interpreter_visitwhilestmt_1_whilestmt, 1, t_interpreter_visitwhilestmt_1_whilestmt);
    alg_class_method(k_interpreter, "Contains", m_interpreter_contains_2, 2, t_interpreter_contains_2);
    alg_class_method(k_interpreter, "IsCallable", m_interpreter_iscallable_1, 1, t_interpreter_iscallable_1);
    alg_class_method(k_interpreter, "ElementsOf", m_interpreter_elementsof_2_token, 2, t_interpreter_elementsof_2_token);
    alg_class_method(k_interpreter, "VisitForInStmt", m_interpreter_visitforinstmt_1_forinstmt, 1, t_interpreter_visitforinstmt_1_forinstmt);
    alg_class_method(k_interpreter, "VisitBreakStmt", m_interpreter_visitbreakstmt_1_breakstmt, 1, t_interpreter_visitbreakstmt_1_breakstmt);
    alg_class_method(k_interpreter, "VisitModuleStmt", m_interpreter_visitmodulestmt_1_modulestmt, 1, t_interpreter_visitmodulestmt_1_modulestmt);
    alg_class_method(k_interpreter, "VisitRaiseStmt", m_interpreter_visitraisestmt_1_raisestmt, 1, t_interpreter_visitraisestmt_1_raisestmt);
    alg_class_method(k_interpreter, "FindHandler", m_interpreter_findhandler_2_map, 2, t_interpreter_findhandler_2_map);
    alg_class_method(k_interpreter, "Handle", m_interpreter_handle_3_trystmt, 3, t_interpreter_handle_3_trystmt);
    alg_class_method(k_interpreter, "VisitTryStmt", m_interpreter_visittrystmt_1_trystmt, 1, t_interpreter_visittrystmt_1_trystmt);
    alg_class_method(k_interpreter, "VisitReturnStmt", m_interpreter_visitreturnstmt_1_returnstmt, 1, t_interpreter_visitreturnstmt_1_returnstmt);
    alg_class_method(k_interpreter, "VisitVarStmt", m_interpreter_visitvarstmt_1_varstmt, 1, t_interpreter_visitvarstmt_1_varstmt);
    alg_class_method(k_interpreter, "VisitVarGroupStmt", m_interpreter_visitvargroupstmt_1_vargroupstmt, 1, t_interpreter_visitvargroupstmt_1_vargroupstmt);
    alg_class_method(k_interpreter, "VisitAssignExpr", m_interpreter_visitassignexpr_1_assignexpr, 1, t_interpreter_visitassignexpr_1_assignexpr);
    alg_class_initializer(k_broke, i_broke);
    alg_class_field(k_raised, "Value");
    alg_class_initializer(k_raised, i_raised);
    alg_class_method(k_raised, "Init", m_raised_init_1, 1, t_raised_init_1);
    alg_class_field(k_return, "Value");
    alg_class_initializer(k_return, i_return);
    alg_class_method(k_return, "Init", m_return_init_1, 1, t_return_init_1);
    init_Console();
    init_ObjBuffer();
    init_ObjClass();
    init_ObjCollection();
    init_ObjEnum();
    init_ObjFile();
    init_Parser();
    init_Resolver();
    v_programarguments = alg_widen(alg_list(), "List");
    d_programarguments = true;
    v_outputsuppressed = alg_widen(alg_bool(false), "Boolean");
    d_outputsuppressed = true;
}
