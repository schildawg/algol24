/* Generated from Algol-24.  Do not edit. */
#include "Interpreter.h"
#include "Console.h"
#include "TestReport.h"
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
Value f_parsednumber(Value **cells, Value *args, int32_t count);
Value f_labelat(Value **cells, Value *args, int32_t count);
Value f_names(Value **cells, Value *args, int32_t count);
Value v_programarguments;
bool d_programarguments;
Value fn_setprogramarguments;
static const char *t_f_setprogramarguments[] = { "Arguments : List" };
Value v_outputsuppressed;
bool d_outputsuppressed;
Value fn_suppressoutput;
static const char *t_f_suppressoutput[] = { "Suppress : Boolean" };
Value fn_rendered;
static const char *t_f_rendered[] = { "TheInterpreter : Any", "Arguments : List" };
Value fn_stringify;
static const char *t_f_stringify[] = { "TheInterpreter : Any", "Value : Any" };
Value k_native;
static Value or_0;
static Value or_1;
static Value or_2;
static Value or_3;
static const char *t_native_init_2_string_integer[] = { "Name : String", "TheArity : Integer" };
static const char *t_native_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };
static Value or_4;
static Value or_5;
Value fn_parsednumber;
static const char *t_f_parsednumber[] = { "Text : String" };
Value k_interpreter;
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
static Value or_51;
static Value or_52;
static Value or_53;
static Value or_54;
static Value or_55;
static Value or_56;
static Value or_57;
static Value or_58;
static Value or_59;
static Value or_60;
static Value or_61;
static Value or_62;
static Value or_63;
static Value or_64;
static Value or_65;
static Value or_66;
static const char *t_interpreter_hoist_1_list[] = { "Statements : List" };
static const char *t_interpreter_hoistedclass_1_string[] = { "Name : String" };
static const char *t_interpreter_interpret_1_list[] = { "Statements : List" };
static const char *t_interpreter_hoisttests_11_list_list_map_boolean_environment_map_string_list_map_set_boolean[] = { "Statements : List", "Tests : List", "ByName : Map", "Define : Boolean", "Scope : Environment", "DeclaredIn : Map", "File : String", "Files : List", "ByFile : Map", "Hoisted : Set", "Collect : Boolean" };
static const char *t_interpreter_runtests_2_list_string[] = { "Statements : List", "FileName : String" };
static const char *t_interpreter_visitliteral_1_literalexpr[] = { "TheExpr : LiteralExpr" };
static const char *t_interpreter_visitlogical_1_logicalexpr[] = { "TheExpr : LogicalExpr" };
static const char *t_interpreter_visitgrouping_1_groupingexpr[] = { "TheExpr : GroupingExpr" };
static const char *t_interpreter_visitunary_1_unaryexpr[] = { "TheExpr : UnaryExpr" };
static const char *t_interpreter_visitcollectionexpr_1_collectionexpr[] = { "TheExpr : CollectionExpr" };
static const char *t_interpreter_visitsubscriptexpr_1_subscriptexpr[] = { "TheExpr : SubscriptExpr" };
static const char *t_interpreter_visitsetsubscriptexpr_1_setsubscriptexpr[] = { "TheExpr : SetSubscriptExpr" };
static const char *t_interpreter_istext_1[] = { "Obj : Any" };
static const char *t_interpreter_insubrange_2_string[] = { "Value : Any", "TheName : String" };
static const char *t_interpreter_satisfiestype_2_string[] = { "Value : Any", "TheName : String" };
static const char *t_interpreter_visitisexpr_1_isexpr[] = { "TheExpr : IsExpr" };
static const char *t_interpreter_visitvariableexpr_1_variableexpr[] = { "TheExpr : VariableExpr" };
static const char *t_interpreter_thisfield_2_token_string[] = { "Name : Token", "Original : String" };
static const char *t_interpreter_setthisfield_3_token_string[] = { "Name : Token", "Value : Any", "Original : String" };
static const char *t_interpreter_lookupvariable_2_token_expr[] = { "Name : Token", "TheExpr : Expr" };
static const char *t_interpreter_shown_1[] = { "Value : Any" };
static const char *t_interpreter_suggestunit_2_token_string[] = { "Name : Token", "Message : String" };
static const char *t_interpreter_integerdivide_2[] = { "Left : Any", "Right : Any" };
static const char *t_interpreter_remainder_2[] = { "Left : Any", "Right : Any" };
static const char *t_interpreter_bitwise_1[] = { "Op : Any" };
static const char *t_interpreter_arithmetic_1[] = { "Op : Any" };
static const char *t_interpreter_orders_1[] = { "Op : Any" };
static const char *t_interpreter_visitbinary_1_binaryexpr[] = { "TheExpr : BinaryExpr" };
static const char *t_interpreter_arranged_3_list_list[] = { "Callee : Any", "Arguments : List", "Names : List" };
static const char *t_interpreter_visitcall_1_callexpr[] = { "TheExpr : CallExpr" };
static const char *t_interpreter_assignqualified_3_string_token[] = { "Unit : String", "Name : Token", "Value : Any" };
static const char *t_interpreter_qualified_2_string_token[] = { "Unit : String", "Name : Token" };
static const char *t_interpreter_responds_2_token[] = { "Obj : Any", "Name : Token" };
static const char *t_interpreter_extensionnamed_1_getexpr[] = { "TheExpr : GetExpr" };
static const char *t_interpreter_visitgetexpr_1_getexpr[] = { "TheExpr : GetExpr" };
static const char *t_interpreter_visitsetexpr_1_setexpr[] = { "TheExpr : SetExpr" };
static const char *t_interpreter_visitsuperexpr_1_superexpr[] = { "TheExpr : SuperExpr" };
static const char *t_interpreter_visitthisexpr_1_thisexpr[] = { "TheExpr : ThisExpr" };
static const char *t_interpreter_classnameof_1[] = { "Obj : Any" };
static const char *t_interpreter_istruthy_1[] = { "Obj : Any" };
static const char *t_interpreter_isequal_2[] = { "A : Any", "B : Any" };
static const char *t_interpreter_widen_2_string[] = { "Value : Any", "Declared : String" };
static const char *t_interpreter_evaluate_1_expr[] = { "TheExpr : Expr" };
static const char *t_interpreter_execute_1_stmt[] = { "TheStmt : Stmt" };
static const char *t_interpreter_resolve_2_expr_integer[] = { "TheExpr : Expr", "Depth : Integer" };
static const char *t_interpreter_executeblock_2_list_environment[] = { "Statements : List", "NewEnv : Environment" };
static const char *t_interpreter_visitblockstmt_1_blockstmt[] = { "TheStmt : BlockStmt" };
static const char *t_interpreter_visitclassstmt_1_classstmt[] = { "TheStmt : ClassStmt" };
static const char *t_interpreter_visitobjectstmt_1_objectstmt[] = { "TheStmt : ObjectStmt" };
static const char *t_interpreter_visitsubrangestmt_1_subrangestmt[] = { "TheStmt : SubrangeStmt" };
static const char *t_interpreter_visitenumstmt_1_enumstmt[] = { "TheStmt : EnumStmt" };
static const char *t_interpreter_visitexpressionstmt_1_expressionstmt[] = { "Stmt : ExpressionStmt" };
static const char *t_interpreter_visitfunctionstmt_1_functionstmt[] = { "TheStmt : FunctionStmt" };
static const char *t_interpreter_visitifstmt_1_ifstmt[] = { "Stmt : IfStmt" };
static const char *t_interpreter_visitwhilestmt_1_whilestmt[] = { "Stmt : WhileStmt" };
static const char *t_interpreter_contains_2[] = { "Collection : Any", "Value : Any" };
static const char *t_interpreter_iscallable_1[] = { "Value : Any" };
static const char *t_interpreter_elementsof_2_token[] = { "Where : Token", "Target : Any" };
static const char *t_interpreter_visitforinstmt_1_forinstmt[] = { "TheStmt : ForInStmt" };
static const char *t_interpreter_visitbreakstmt_1_breakstmt[] = { "TheStmt : BreakStmt" };
static const char *t_interpreter_visitcontinuestmt_1_continuestmt[] = { "TheStmt : ContinueStmt" };
static const char *t_interpreter_visitlabelstmt_1_labelstmt[] = { "TheStmt : LabelStmt" };
static const char *t_interpreter_visitgotostmt_1_gotostmt[] = { "TheStmt : GotoStmt" };
static const char *t_interpreter_visitmodulestmt_1_modulestmt[] = { "TheStmt : ModuleStmt" };
static const char *t_interpreter_visitraisestmt_1_raisestmt[] = { "TheStmt : RaiseStmt" };
static const char *t_interpreter_findhandler_2_map[] = { "Handlers : Map", "Value : Any" };
static const char *t_interpreter_handle_3_trystmt[] = { "TheStmt : TryStmt", "Value : Any", "Original : Any" };
static const char *t_interpreter_visittrystmt_1_trystmt[] = { "TheStmt : TryStmt" };
static const char *t_interpreter_visitreturnstmt_1_returnstmt[] = { "Stmt : ReturnStmt" };
static const char *t_interpreter_visitvarstmt_1_varstmt[] = { "Stmt : VarStmt" };
static const char *t_interpreter_visitvargroupstmt_1_vargroupstmt[] = { "TheStmt : VarGroupStmt" };
static const char *t_interpreter_visitassignexpr_1_assignexpr[] = { "Expr : AssignExpr" };
Value k_broke;
static const char *t_broke_init_1_string[] = { "Label : String" };
Value k_continued;
static const char *t_continued_init_1_string[] = { "Label : String" };
Value k_jumped;
static const char *t_jumped_init_1_string[] = { "Label : String" };
Value fn_labelat;
static const char *t_f_labelat[] = { "Statements : List", "Named : String" };
Value fn_names;
static const char *t_f_names[] = { "Wanted : String", "Loop : String" };
Value k_raised;
static const char *t_raised_init_1[] = { "Value : Any" };
Value k_return;
static const char *t_return_init_1[] = { "Value : Any" };

Value f_setprogramarguments(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_arguments = alg_param(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    (void)((alg_declared(d_programarguments, "ProgramArguments"), (v_programarguments = v_arguments)));
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

Value f_suppressoutput(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_suppress = alg_param(args[0], "Boolean");
    (void)v_suppress;
    alg_root(&v_suppress, 1);
    (void)((alg_declared(d_outputsuppressed, "OutputSuppressed"), (v_outputsuppressed = v_suppress)));
    Value ret_1 = alg_nil();
    alg_root_top = rt_base;
    return ret_1;
}

Value f_rendered(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    alg_root(&v_theinterpreter, 1);
    Value v_arguments = alg_param(args[1], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_line = alg_nil();
    (void)v_line;
    alg_root(&v_line, 1);
    (void)((v_line = alg_string("")));
    {
        int32_t rt_136 = alg_root_top;
        Value loop_2 = alg_iterable(v_arguments);
        (void)loop_2;
        alg_root(&loop_2, 1);
        for (int32_t at_2 = 0; at_2 < alg_iterable_count(loop_2); at_2++) {
            int32_t rt_137 = alg_root_top;
            Value v_argument = alg_iterable_at(loop_2, at_2);
            (void)v_argument;
            alg_root(&v_argument, 1);
            (void)((v_line = alg_add(v_line, f_stringify(NULL, (Value[]){v_theinterpreter, v_argument}, 2))));
            alg_root_top = rt_137;
        }
        alg_root_top = rt_136;
    }
    Value ret_3 = v_line;
    alg_root_top = rt_base;
    return ret_3;
    Value ret_4 = alg_nil();
    alg_root_top = rt_base;
    return ret_4;
}

Value f_stringify(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    alg_root(&v_theinterpreter, 1);
    Value v_value = args[1];
    (void)v_value;
    alg_root(&v_value, 1);
    if (alg_truthy(alg_equal(v_value, alg_nil()))) {
        Value ret_5 = alg_string("nil");
        alg_root_top = rt_base;
        return ret_5;
    }
    if (alg_truthy(alg_is(v_value, "ObjInstance"))) {
        {
            int32_t rt_138 = alg_root_top;
            Value v_method = alg_invoke(alg_property(v_value, "Klass"), "MethodOfArity", (Value[]){alg_string("tostring"), alg_int(0)}, 2);
            (void)v_method;
            alg_root(&v_method, 1);
            if (alg_truthy(alg_not_equal(v_method, alg_nil()))) {
                Value ret_6 = f_stringify(NULL, (Value[]){v_theinterpreter, alg_invoke(alg_invoke(v_method, "Bind", (Value[]){v_value}, 1), "Call", (Value[]){v_theinterpreter, alg_list()}, 2)}, 2);
                alg_root_top = rt_base;
                return ret_6;
            }
            alg_root_top = rt_138;
        }
    }
    if (alg_truthy(alg_is(v_value, "ObjCollection"))) {
        {
            int32_t rt_139 = alg_root_top;
            Value v_result = alg_char_value(91);
            (void)v_result;
            alg_root(&v_result, 1);
            Value v_first = alg_bool(true);
            (void)v_first;
            alg_root(&v_first, 1);
            if (alg_truthy(alg_equal(alg_property(v_value, "Kind"), alg_string("Map")))) {
                {
                    int32_t rt_140 = alg_root_top;
                    Value loop_7 = alg_iterable(alg_invoke(alg_property(v_value, "Pairs"), "Keys", NULL, 0));
                    (void)loop_7;
                    alg_root(&loop_7, 1);
                    for (int32_t at_7 = 0; at_7 < alg_iterable_count(loop_7); at_7++) {
                        int32_t rt_141 = alg_root_top;
                        Value v_key = alg_iterable_at(loop_7, at_7);
                        (void)v_key;
                        alg_root(&v_key, 1);
                        {
                            if (alg_truthy(alg_not(v_first))) {
                                (void)((v_result = alg_add(v_result, alg_string(", "))));
                            }
                            (void)((v_first = alg_bool(false)));
                            (void)((v_result = alg_add(alg_add(alg_add(v_result, f_stringify(NULL, (Value[]){v_theinterpreter, v_key}, 2)), alg_char_value(58)), f_stringify(NULL, (Value[]){v_theinterpreter, alg_invoke(alg_property(v_value, "Pairs"), "Get", (Value[]){v_key}, 1)}, 2))));
                        }
                        alg_root_top = rt_141;
                    }
                    alg_root_top = rt_140;
                }
            } else {
                {
                    int32_t rt_142 = alg_root_top;
                    Value loop_8 = alg_iterable(alg_property(v_value, "Items"));
                    (void)loop_8;
                    alg_root(&loop_8, 1);
                    for (int32_t at_8 = 0; at_8 < alg_iterable_count(loop_8); at_8++) {
                        int32_t rt_143 = alg_root_top;
                        Value v_element = alg_iterable_at(loop_8, at_8);
                        (void)v_element;
                        alg_root(&v_element, 1);
                        {
                            if (alg_truthy(alg_not(v_first))) {
                                (void)((v_result = alg_add(v_result, alg_string(", "))));
                            }
                            (void)((v_first = alg_bool(false)));
                            (void)((v_result = alg_add(v_result, f_stringify(NULL, (Value[]){v_theinterpreter, v_element}, 2))));
                        }
                        alg_root_top = rt_143;
                    }
                    alg_root_top = rt_142;
                }
            }
            Value ret_9 = alg_add(v_result, alg_char_value(93));
            alg_root_top = rt_base;
            return ret_9;
            alg_root_top = rt_139;
        }
    }
    Value ret_10 = alg_str(v_value);
    alg_root_top = rt_base;
    return ret_10;
    Value ret_11 = alg_nil();
    alg_root_top = rt_base;
    return ret_11;
}

static Value i_native(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "TheArity", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_native_init_2_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_thearity = alg_widen(args[1], "Integer");
    (void)v_thearity;
    alg_root(&v_thearity, 1);
    (void)(alg_set_property(v_this, "Name", v_name));
    (void)(alg_set_property(v_this, "TheArity", v_thearity));
    Value ret_12 = alg_nil();
    alg_root_top = rt_base;
    return ret_12;
}

static Value m_native_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_13 = alg_property(v_this, "TheArity");
    alg_root_top = rt_base;
    return ret_13;
    Value ret_14 = alg_nil();
    alg_root_top = rt_base;
    return ret_14;
}

static Value m_native_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_15 = alg_add(alg_add(alg_string("<fn "), alg_property(v_this, "Name")), alg_char_value(62));
    alg_root_top = rt_base;
    return ret_15;
    Value ret_16 = alg_nil();
    alg_root_top = rt_base;
    return ret_16;
}

static Value m_native_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    alg_root(&v_theinterpreter, 1);
    Value v_arguments = args[1];
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("clock")))) {
        Value ret_17 = alg_clock();
        alg_root_top = rt_base;
        return ret_17;
    } else {
        if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Collect")))) {
            Value ret_18 = alg_int(0);
            alg_root_top = rt_base;
            return ret_18;
        } else {
            if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Length")))) {
                {
                    if (alg_truthy(alg_is(alg_subscript_get(v_arguments, alg_int(0)), "ObjCollection"))) {
                        alg_raise(alg_string("Length expects text; use .Length for a collection."));
                    }
                    Value ret_19 = alg_text_length(alg_str(alg_subscript_get(v_arguments, alg_int(0))));
                    alg_root_top = rt_base;
                    return ret_19;
                }
            } else {
                if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Copy")))) {
                    Value ret_20 = alg_copy(alg_str(alg_subscript_get(v_arguments, alg_int(0))), alg_subscript_get(v_arguments, alg_int(1)), alg_subscript_get(v_arguments, alg_int(2)));
                    alg_root_top = rt_base;
                    return ret_20;
                } else {
                    if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Pos")))) {
                        {
                            if (alg_truthy((or_0 = alg_less(alg_property(v_arguments, "Length"), alg_int(2)), alg_truthy(or_0) ? or_0 : alg_greater(alg_property(v_arguments, "Length"), alg_int(3))))) {
                                alg_raise(alg_add(alg_add(alg_string("Expected 2 or 3 arguments but got "), alg_str(alg_property(v_arguments, "Length"))), alg_char_value(46)));
                            }
                            if (alg_truthy(alg_equal(alg_property(v_arguments, "Length"), alg_int(2)))) {
                                Value ret_21 = alg_pos(alg_str(alg_subscript_get(v_arguments, alg_int(0))), alg_str(alg_subscript_get(v_arguments, alg_int(1))));
                                alg_root_top = rt_base;
                                return ret_21;
                            }
                            Value ret_22 = alg_pos_from(alg_str(alg_subscript_get(v_arguments, alg_int(0))), alg_str(alg_subscript_get(v_arguments, alg_int(1))), alg_subscript_get(v_arguments, alg_int(2)));
                            alg_root_top = rt_base;
                            return ret_22;
                        }
                    } else {
                        if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("ToUpper")))) {
                            Value ret_23 = alg_to_upper(alg_subscript_get(v_arguments, alg_int(0)));
                            alg_root_top = rt_base;
                            return ret_23;
                        } else {
                            if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("ToLower")))) {
                                Value ret_24 = alg_to_lower(alg_subscript_get(v_arguments, alg_int(0)));
                                alg_root_top = rt_base;
                                return ret_24;
                            } else {
                                if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Str")))) {
                                    {
                                        if (alg_truthy((or_1 = alg_less(alg_property(v_arguments, "Length"), alg_int(1)), alg_truthy(or_1) ? or_1 : alg_greater(alg_property(v_arguments, "Length"), alg_int(3))))) {
                                            alg_raise(alg_add(alg_add(alg_string("Expected 1, 2 or 3 arguments but got "), alg_str(alg_property(v_arguments, "Length"))), alg_char_value(46)));
                                        }
                                        if (alg_truthy(alg_equal(alg_property(v_arguments, "Length"), alg_int(1)))) {
                                            Value ret_25 = f_stringify(NULL, (Value[]){v_theinterpreter, alg_subscript_get(v_arguments, alg_int(0))}, 2);
                                            alg_root_top = rt_base;
                                            return ret_25;
                                        }
                                        if (alg_truthy(alg_equal(alg_property(v_arguments, "Length"), alg_int(2)))) {
                                            Value ret_26 = alg_str_fixed(alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1)));
                                            alg_root_top = rt_base;
                                            return ret_26;
                                        }
                                        Value ret_27 = alg_str_padded(alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1)), alg_subscript_get(v_arguments, alg_int(2)));
                                        alg_root_top = rt_base;
                                        return ret_27;
                                    }
                                } else {
                                    if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Array")))) {
                                        {
                                            int32_t rt_144 = alg_root_top;
                                            Value v_thearray = alg_new(k_objcollection, (Value[]){alg_string("Array")}, 1);
                                            (void)v_thearray;
                                            alg_root(&v_thearray, 1);
                                            (void)(alg_invoke(v_thearray, "Allocate", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1));
                                            Value ret_28 = v_thearray;
                                            alg_root_top = rt_base;
                                            return ret_28;
                                            alg_root_top = rt_144;
                                        }
                                    } else {
                                        if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("List")))) {
                                            Value ret_29 = alg_new(k_objcollection, (Value[]){alg_string("List")}, 1);
                                            alg_root_top = rt_base;
                                            return ret_29;
                                        } else {
                                            if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Map")))) {
                                                Value ret_30 = alg_new(k_objcollection, (Value[]){alg_string("Map")}, 1);
                                                alg_root_top = rt_base;
                                                return ret_30;
                                            } else {
                                                if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Stack")))) {
                                                    Value ret_31 = alg_new(k_objcollection, (Value[]){alg_string("Stack")}, 1);
                                                    alg_root_top = rt_base;
                                                    return ret_31;
                                                } else {
                                                    if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Set")))) {
                                                        {
                                                            int32_t rt_145 = alg_root_top;
                                                            if (alg_truthy(alg_greater(alg_property(v_arguments, "Length"), alg_int(1)))) {
                                                                alg_raise(alg_add(alg_add(alg_string("Expected 0 or 1 arguments but got "), alg_str(alg_property(v_arguments, "Length"))), alg_char_value(46)));
                                                            }
                                                            Value v_theset = alg_new(k_objcollection, (Value[]){alg_string("Set")}, 1);
                                                            (void)v_theset;
                                                            alg_root(&v_theset, 1);
                                                            if (alg_truthy(alg_equal(alg_property(v_arguments, "Length"), alg_int(1)))) {
                                                                {
                                                                    int32_t rt_146 = alg_root_top;
                                                                    Value v_from = alg_subscript_get(v_arguments, alg_int(0));
                                                                    (void)v_from;
                                                                    alg_root(&v_from, 1);
                                                                    if (alg_truthy((or_2 = alg_not((alg_is(v_from, "ObjCollection"))), alg_truthy(or_2) ? or_2 : alg_not_equal(alg_property(v_from, "Kind"), alg_string("List"))))) {
                                                                        alg_raise(alg_add(alg_add(alg_string("Set expects (List) but got ("), f_typenameof(NULL, (Value[]){v_from}, 1)), alg_string(").")));
                                                                    }
                                                                    {
                                                                        int32_t rt_147 = alg_root_top;
                                                                        Value loop_32 = alg_iterable(alg_property(v_from, "Items"));
                                                                        (void)loop_32;
                                                                        alg_root(&loop_32, 1);
                                                                        for (int32_t at_32 = 0; at_32 < alg_iterable_count(loop_32); at_32++) {
                                                                            int32_t rt_148 = alg_root_top;
                                                                            Value v_item = alg_iterable_at(loop_32, at_32);
                                                                            (void)v_item;
                                                                            alg_root(&v_item, 1);
                                                                            (void)(alg_invoke(v_theset, "Invoke", (Value[]){alg_string("add"), alg_list_keep(alg_list(), v_item)}, 2));
                                                                            alg_root_top = rt_148;
                                                                        }
                                                                        alg_root_top = rt_147;
                                                                    }
                                                                    alg_root_top = rt_146;
                                                                }
                                                            }
                                                            Value ret_33 = v_theset;
                                                            alg_root_top = rt_base;
                                                            return ret_33;
                                                            alg_root_top = rt_145;
                                                        }
                                                    } else {
                                                        if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Write")))) {
                                                            {
                                                                if (alg_truthy(alg_not((alg_declared(d_outputsuppressed, "OutputSuppressed"), v_outputsuppressed)))) {
                                                                    (void)(alg_write(f_rendered(NULL, (Value[]){v_theinterpreter, v_arguments}, 2)));
                                                                }
                                                                Value ret_34 = alg_nil();
                                                                alg_root_top = rt_base;
                                                                return ret_34;
                                                            }
                                                        } else {
                                                            if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("WriteLn")))) {
                                                                {
                                                                    if (alg_truthy(alg_not((alg_declared(d_outputsuppressed, "OutputSuppressed"), v_outputsuppressed)))) {
                                                                        (void)(alg_writeln(f_rendered(NULL, (Value[]){v_theinterpreter, v_arguments}, 2)));
                                                                    }
                                                                    Value ret_35 = alg_nil();
                                                                    alg_root_top = rt_base;
                                                                    return ret_35;
                                                                }
                                                            } else {
                                                                if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Halt")))) {
                                                                    {
                                                                        (void)(alg_halt(alg_subscript_get(v_arguments, alg_int(0))));
                                                                        Value ret_36 = alg_nil();
                                                                        alg_root_top = rt_base;
                                                                        return ret_36;
                                                                    }
                                                                } else {
                                                                    if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Foreign")))) {
                                                                        Value ret_37 = alg_foreign_call(alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1)), alg_subscript_get(v_arguments, alg_int(2)), alg_subscript_get(v_arguments, alg_int(3)), alg_subscript_get(v_arguments, alg_int(4)));
                                                                        alg_root_top = rt_base;
                                                                        return ret_37;
                                                                    } else {
                                                                        if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Succ")))) {
                                                                            Value ret_38 = alg_succ(alg_subscript_get(v_arguments, alg_int(0)));
                                                                            alg_root_top = rt_base;
                                                                            return ret_38;
                                                                        } else {
                                                                            if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Pred")))) {
                                                                                Value ret_39 = alg_pred(alg_subscript_get(v_arguments, alg_int(0)));
                                                                                alg_root_top = rt_base;
                                                                                return ret_39;
                                                                            } else {
                                                                                if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Ord")))) {
                                                                                    {
                                                                                        if (alg_truthy(alg_is(alg_subscript_get(v_arguments, alg_int(0)), "ObjEnum"))) {
                                                                                            Value ret_40 = alg_property(alg_subscript_get(v_arguments, alg_int(0)), "Ordinal");
                                                                                            alg_root_top = rt_base;
                                                                                            return ret_40;
                                                                                        }
                                                                                        Value ret_41 = alg_ord(alg_subscript_get(v_arguments, alg_int(0)));
                                                                                        alg_root_top = rt_base;
                                                                                        return ret_41;
                                                                                    }
                                                                                } else {
                                                                                    if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Val")))) {
                                                                                        Value ret_42 = f_parsednumber(NULL, (Value[]){alg_str(alg_subscript_get(v_arguments, alg_int(0)))}, 1);
                                                                                        alg_root_top = rt_base;
                                                                                        return ret_42;
                                                                                    } else {
                                                                                        if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Char")))) {
                                                                                            Value ret_43 = alg_char(alg_subscript_get(v_arguments, alg_int(0)));
                                                                                            alg_root_top = rt_base;
                                                                                            return ret_43;
                                                                                        } else {
                                                                                            if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("TextFile")))) {
                                                                                                Value ret_44 = alg_new(k_objfile, NULL, 0);
                                                                                                alg_root_top = rt_base;
                                                                                                return ret_44;
                                                                                            } else {
                                                                                                if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("FileExists")))) {
                                                                                                    Value ret_45 = alg_file_exists(alg_str(alg_subscript_get(v_arguments, alg_int(0))));
                                                                                                    alg_root_top = rt_base;
                                                                                                    return ret_45;
                                                                                                } else {
                                                                                                    if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("MkDir")))) {
                                                                                                        Value ret_46 = alg_mkdir(alg_str(alg_subscript_get(v_arguments, alg_int(0))));
                                                                                                        alg_root_top = rt_base;
                                                                                                        return ret_46;
                                                                                                    } else {
                                                                                                        if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("RmDir")))) {
                                                                                                            Value ret_47 = alg_rmdir(alg_str(alg_subscript_get(v_arguments, alg_int(0))));
                                                                                                            alg_root_top = rt_base;
                                                                                                            return ret_47;
                                                                                                        } else {
                                                                                                            if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("ChDir")))) {
                                                                                                                Value ret_48 = alg_chdir(alg_str(alg_subscript_get(v_arguments, alg_int(0))));
                                                                                                                alg_root_top = rt_base;
                                                                                                                return ret_48;
                                                                                                            } else {
                                                                                                                if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("GetDir")))) {
                                                                                                                    Value ret_49 = alg_getdir();
                                                                                                                    alg_root_top = rt_base;
                                                                                                                    return ret_49;
                                                                                                                } else {
                                                                                                                    if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Buffer")))) {
                                                                                                                        {
                                                                                                                            if (alg_truthy(alg_greater(alg_property(v_arguments, "Length"), alg_int(1)))) {
                                                                                                                                alg_raise(alg_add(alg_add(alg_string("Expected 0 or 1 arguments but got "), alg_str(alg_property(v_arguments, "Length"))), alg_char_value(46)));
                                                                                                                            }
                                                                                                                            if (alg_truthy(alg_equal(alg_property(v_arguments, "Length"), alg_int(0)))) {
                                                                                                                                Value ret_50 = alg_new(k_objbuffer, (Value[]){alg_int(0)}, 1);
                                                                                                                                alg_root_top = rt_base;
                                                                                                                                return ret_50;
                                                                                                                            }
                                                                                                                            Value ret_51 = alg_new(k_objbuffer, (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
                                                                                                                            alg_root_top = rt_base;
                                                                                                                            return ret_51;
                                                                                                                        }
                                                                                                                    } else {
                                                                                                                        if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("ParamCount")))) {
                                                                                                                            Value ret_52 = alg_subtract(alg_property((alg_declared(d_programarguments, "ProgramArguments"), v_programarguments), "Length"), alg_int(1));
                                                                                                                            alg_root_top = rt_base;
                                                                                                                            return ret_52;
                                                                                                                        } else {
                                                                                                                            if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("ParamStr")))) {
                                                                                                                                {
                                                                                                                                    int32_t rt_149 = alg_root_top;
                                                                                                                                    Value v_at = alg_cast(alg_subscript_get(v_arguments, alg_int(0)), "Integer");
                                                                                                                                    (void)v_at;
                                                                                                                                    alg_root(&v_at, 1);
                                                                                                                                    if (alg_truthy((or_3 = alg_less(v_at, alg_int(0)), alg_truthy(or_3) ? or_3 : alg_greater_equal(v_at, alg_property((alg_declared(d_programarguments, "ProgramArguments"), v_programarguments), "Length"))))) {
                                                                                                                                        Value ret_53 = alg_string("");
                                                                                                                                        alg_root_top = rt_base;
                                                                                                                                        return ret_53;
                                                                                                                                    }
                                                                                                                                    Value ret_54 = alg_subscript_get((alg_declared(d_programarguments, "ProgramArguments"), v_programarguments), v_at);
                                                                                                                                    alg_root_top = rt_base;
                                                                                                                                    return ret_54;
                                                                                                                                    alg_root_top = rt_149;
                                                                                                                                }
                                                                                                                            } else {
                                                                                                                                if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("AssertTrue")))) {
                                                                                                                                    {
                                                                                                                                        if (alg_truthy(alg_not(alg_invoke(v_theinterpreter, "IsTruthy", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1)))) {
                                                                                                                                            alg_raise(alg_add(alg_add(alg_string("Assertion failed.  Expected true but got '"), alg_str(alg_subscript_get(v_arguments, alg_int(0)))), alg_string("'.")));
                                                                                                                                        }
                                                                                                                                        Value ret_55 = alg_nil();
                                                                                                                                        alg_root_top = rt_base;
                                                                                                                                        return ret_55;
                                                                                                                                    }
                                                                                                                                } else {
                                                                                                                                    if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("AssertEqual")))) {
                                                                                                                                        {
                                                                                                                                            if (alg_truthy(alg_not(alg_invoke(v_theinterpreter, "IsEqual", (Value[]){alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1))}, 2)))) {
                                                                                                                                                {
                                                                                                                                                    int32_t rt_150 = alg_root_top;
                                                                                                                                                    Value v_left = alg_str(alg_subscript_get(v_arguments, alg_int(0)));
                                                                                                                                                    (void)v_left;
                                                                                                                                                    alg_root(&v_left, 1);
                                                                                                                                                    Value v_right = alg_str(alg_subscript_get(v_arguments, alg_int(1)));
                                                                                                                                                    (void)v_right;
                                                                                                                                                    alg_root(&v_right, 1);
                                                                                                                                                    if (alg_truthy(alg_equal(v_left, v_right))) {
                                                                                                                                                        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("Assertion failed.  Expected "), f_typenameof(NULL, (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1)), alg_string(" '")), v_left), alg_string("' but got ")), f_typenameof(NULL, (Value[]){alg_subscript_get(v_arguments, alg_int(1))}, 1)), alg_string(" '")), v_right), alg_string("'.")));
                                                                                                                                                    }
                                                                                                                                                    alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Assertion failed.  Expected '"), v_left), alg_string("' but got '")), v_right), alg_string("'.")));
                                                                                                                                                    alg_root_top = rt_150;
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                            Value ret_56 = alg_nil();
                                                                                                                                            alg_root_top = rt_base;
                                                                                                                                            return ret_56;
                                                                                                                                        }
                                                                                                                                    } else {
                                                                                                                                        if (alg_truthy(alg_equal(alg_property(v_this, "Name"), alg_string("Fail")))) {
                                                                                                                                            alg_raise(alg_add(alg_string("Failed.  "), alg_str(alg_subscript_get(v_arguments, alg_int(0)))));
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
    alg_raise(alg_add(alg_add(alg_string("Undefined built-in '"), alg_property(v_this, "Name")), alg_string("'.")));
    Value ret_57 = alg_nil();
    alg_root_top = rt_base;
    return ret_57;
}

Value f_parsednumber(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_text = alg_param(args[0], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    Value v_digits = alg_nil();
    (void)v_digits;
    alg_root(&v_digits, 1);
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    Value v_sign = alg_nil();
    (void)v_sign;
    alg_root(&v_sign, 1);
    Value v_asdouble = alg_val(v_text);
    (void)v_asdouble;
    alg_root(&v_asdouble, 1);
    (void)((v_sign = alg_int(1)));
    (void)((v_digits = v_text));
    if (alg_truthy((or_4 = alg_greater(alg_text_length(v_digits), alg_int(0)), !alg_truthy(or_4) ? or_4 : alg_equal(alg_subscript_get(v_digits, alg_int(0)), alg_char_value(45))))) {
        {
            (void)((v_sign = alg_negate(alg_int(1))));
            (void)((v_digits = alg_copy(v_digits, alg_int(1), alg_subtract(alg_text_length(v_digits), alg_int(1)))));
        }
    }
    if (alg_truthy(alg_equal(alg_text_length(v_digits), alg_int(0)))) {
        Value ret_58 = v_asdouble;
        alg_root_top = rt_base;
        return ret_58;
    }
    (void)((v_result = alg_int(0)));
    {
        int32_t rt_151 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_digits))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_152 = alg_root_top;
                Value v_c = alg_subscript_get(v_digits, v_i);
                (void)v_c;
                alg_root(&v_c, 1);
                if (alg_truthy((or_5 = alg_less(v_c, alg_char_value(48)), alg_truthy(or_5) ? or_5 : alg_greater(v_c, alg_char_value(57))))) {
                    Value ret_59 = v_asdouble;
                    alg_root_top = rt_base;
                    return ret_59;
                }
                (void)((v_result = alg_add(alg_multiply(v_result, alg_int(10)), (alg_subtract(alg_ord(v_c), alg_ord(alg_char_value(48)))))));
                alg_root_top = rt_152;
            }
        }
        alg_root_top = rt_151;
    }
    Value ret_60 = alg_multiply(v_sign, v_result);
    alg_root_top = rt_base;
    return ret_60;
    Value ret_61 = alg_nil();
    alg_root_top = rt_base;
    return ret_61;
}

static Value i_interpreter(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Env", alg_nil());
    alg_set_property(v_this, "Builtins", alg_nil());
    alg_set_property(v_this, "Globals", alg_nil());
    alg_set_property(v_this, "Locals", alg_nil());
    alg_set_property(v_this, "Modules", alg_nil());
    alg_set_property(v_this, "HoistedClasses", alg_nil());
    alg_set_property(v_this, "RootFile", alg_nil());
    alg_set_property(v_this, "UnitsByName", alg_nil());
    alg_set_property(v_this, "MemberIsCallee", alg_widen(alg_bool(false), "Boolean"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_interpreter_init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_set_property(v_this, "Builtins", alg_new(k_environment, NULL, 0)));
    (void)(alg_set_property(v_this, "Globals", alg_new(k_environment, NULL, 0)));
    (void)(alg_set_property(alg_property(v_this, "Globals"), "Enclosing", alg_property(v_this, "Builtins")));
    (void)(alg_set_property(v_this, "Locals", alg_map()));
    (void)(alg_set_property(v_this, "Modules", alg_map()));
    (void)(alg_set_property(v_this, "RootFile", alg_string("")));
    (void)(alg_set_property(v_this, "HoistedClasses", alg_set()));
    (void)(alg_set_property(v_this, "UnitsByName", alg_map()));
    (void)(alg_set_property(v_this, "Env", alg_property(v_this, "Globals")));
    (void)(f_setinstanceshown(NULL, (Value[]){alg_property(v_this, "Shown")}, 1));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("clock"), alg_new(k_native, (Value[]){alg_string("clock"), alg_int(0)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Collect"), alg_new(k_native, (Value[]){alg_string("Collect"), alg_int(0)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Length"), alg_new(k_native, (Value[]){alg_string("Length"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Copy"), alg_new(k_native, (Value[]){alg_string("Copy"), alg_int(3)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Pos"), alg_new(k_native, (Value[]){alg_string("Pos"), alg_negate(alg_int(1))}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("ToUpper"), alg_new(k_native, (Value[]){alg_string("ToUpper"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("ToLower"), alg_new(k_native, (Value[]){alg_string("ToLower"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Str"), alg_new(k_native, (Value[]){alg_string("Str"), alg_negate(alg_int(1))}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Array"), alg_new(k_native, (Value[]){alg_string("Array"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("List"), alg_new(k_native, (Value[]){alg_string("List"), alg_int(0)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Map"), alg_new(k_native, (Value[]){alg_string("Map"), alg_int(0)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Set"), alg_new(k_native, (Value[]){alg_string("Set"), alg_negate(alg_int(1))}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Stack"), alg_new(k_native, (Value[]){alg_string("Stack"), alg_int(0)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Halt"), alg_new(k_native, (Value[]){alg_string("Halt"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Ord"), alg_new(k_native, (Value[]){alg_string("Ord"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Succ"), alg_new(k_native, (Value[]){alg_string("Succ"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Pred"), alg_new(k_native, (Value[]){alg_string("Pred"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Foreign"), alg_new(k_native, (Value[]){alg_string("Foreign"), alg_int(5)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Val"), alg_new(k_native, (Value[]){alg_string("Val"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Char"), alg_new(k_native, (Value[]){alg_string("Char"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Write"), alg_new(k_native, (Value[]){alg_string("Write"), alg_negate(alg_int(1))}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("WriteLn"), alg_new(k_native, (Value[]){alg_string("WriteLn"), alg_negate(alg_int(1))}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Buffer"), alg_new(k_native, (Value[]){alg_string("Buffer"), alg_negate(alg_int(1))}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("TextFile"), alg_new(k_native, (Value[]){alg_string("TextFile"), alg_int(0)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("FileExists"), alg_new(k_native, (Value[]){alg_string("FileExists"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("MkDir"), alg_new(k_native, (Value[]){alg_string("MkDir"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("RmDir"), alg_new(k_native, (Value[]){alg_string("RmDir"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("ChDir"), alg_new(k_native, (Value[]){alg_string("ChDir"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("GetDir"), alg_new(k_native, (Value[]){alg_string("GetDir"), alg_int(0)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("ParamCount"), alg_new(k_native, (Value[]){alg_string("ParamCount"), alg_int(0)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("ParamStr"), alg_new(k_native, (Value[]){alg_string("ParamStr"), alg_int(1)}, 2)}, 2));
    Value ret_62 = alg_nil();
    alg_root_top = rt_base;
    return ret_62;
}

static Value m_interpreter_hoist_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    Value v_names = alg_set();
    (void)v_names;
    alg_root(&v_names, 1);
    {
        int32_t rt_153 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_statements, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_is(alg_subscript_get(v_statements, v_i), "ClassStmt"))) {
                (void)(alg_invoke(v_names, "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Name"), "Lexeme")}, 1)}, 1));
            }
        }
        alg_root_top = rt_153;
    }
    {
        int32_t rt_154 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_statements, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_is(alg_subscript_get(v_statements, v_i), "ClassStmt"))) {
                (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Name"), "Lexeme"), alg_new(k_objclass, (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Name"), "Lexeme")), alg_nil(), alg_map(), alg_list()}, 4)}, 2));
            }
        }
        alg_root_top = rt_154;
    }
    {
        int32_t rt_155 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_statements, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_is(alg_subscript_get(v_statements, v_i), "ClassStmt"))) {
                {
                    int32_t rt_156 = alg_root_top;
                    Value v_parent = alg_property(alg_subscript_get(v_statements, v_i), "Superclass");
                    (void)v_parent;
                    alg_root(&v_parent, 1);
                    Value v_ready = alg_equal(v_parent, alg_nil());
                    (void)v_ready;
                    alg_root(&v_ready, 1);
                    if (alg_truthy(alg_not(v_ready))) {
                        (void)((v_ready = alg_invoke(v_names, "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_parent, "Name"), "Lexeme")}, 1)}, 1)));
                    }
                    if (alg_truthy(v_ready)) {
                        {
                            (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(v_statements, v_i)}, 1));
                            (void)(alg_invoke(alg_property(v_this, "HoistedClasses"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Name"), "Lexeme")}, 1)}, 1));
                        }
                    }
                    alg_root_top = rt_156;
                }
            }
        }
        alg_root_top = rt_155;
    }
    {
        int32_t rt_157 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_statements, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_is(alg_subscript_get(v_statements, v_i), "FunctionStmt"))) {
                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(v_statements, v_i)}, 1));
            }
        }
        alg_root_top = rt_157;
    }
    Value ret_63 = alg_nil();
    alg_root_top = rt_base;
    return ret_63;
}

static Value m_interpreter_hoistedclass_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_not(alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1)))) {
        Value ret_64 = alg_nil();
        alg_root_top = rt_base;
        return ret_64;
    }
    Value v_bound = alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1);
    (void)v_bound;
    alg_root(&v_bound, 1);
    if (alg_truthy(alg_not((alg_is(v_bound, "ObjClass"))))) {
        Value ret_65 = alg_nil();
        alg_root_top = rt_base;
        return ret_65;
    }
    Value ret_66 = v_bound;
    alg_root_top = rt_base;
    return ret_66;
    Value ret_67 = alg_nil();
    alg_root_top = rt_base;
    return ret_67;
}

static Value m_interpreter_registerroot_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_equal(alg_property(v_this, "RootFile"), alg_string("")))) {
        Value ret_68 = alg_nil();
        alg_root_top = rt_base;
        return ret_68;
    }
    (void)(alg_invoke(alg_property(v_this, "Modules"), "Put", (Value[]){alg_property(v_this, "RootFile"), alg_property(v_this, "Globals")}, 2));
    Value ret_69 = alg_nil();
    alg_root_top = rt_base;
    return ret_69;
}

static Value m_interpreter_interpret_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    {
        AlgFrame frame_70;
        alg_push_frame(&frame_70);
        if (ALG_SETJMP(frame_70.jump) == 0) {
            {
                int32_t rt_158 = alg_root_top;
                (void)(alg_invoke(v_this, "RegisterRoot", NULL, 0));
                (void)(alg_invoke(v_this, "Hoist", (Value[]){v_statements}, 1));
                volatile Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                while (alg_truthy(alg_less(v_i, alg_property(v_statements, "Length")))) {
                    {
                        int32_t rt_159 = alg_root_top;
                        volatile Value v_done = alg_is(alg_subscript_get(v_statements, v_i), "FunctionStmt");
                        (void)v_done;
                        alg_root(&v_done, 1);
                        if (alg_truthy(alg_is(alg_subscript_get(v_statements, v_i), "ClassStmt"))) {
                            (void)((v_done = alg_invoke(alg_property(v_this, "HoistedClasses"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Name"), "Lexeme")}, 1)}, 1)));
                        }
                        {
                            AlgFrame frame_71;
                            alg_push_frame(&frame_71);
                            if (ALG_SETJMP(frame_71.jump) == 0) {
                                {
                                    if (alg_truthy(alg_not(v_done))) {
                                        (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(v_statements, v_i)}, 1));
                                    }
                                    (void)((v_i = alg_add(v_i, alg_int(1))));
                                }
                                alg_pop_frame();
                            }
                            else {
                                static const char *names_71[] = {"Jumped"};
                                int32_t which_71 = alg_handler(frame_71.raised, names_71, 1);
                                if (which_71 == 0) {
                                    {
                                        int32_t rt_160 = alg_root_top;
                                        volatile Value v_g = frame_71.raised;
                                        (void)v_g;
                                        alg_root(&v_g, 1);
                                        {
                                            int32_t rt_161 = alg_root_top;
                                            volatile Value v_at = f_labelat(NULL, (Value[]){v_statements, alg_property(v_g, "Label")}, 2);
                                            (void)v_at;
                                            alg_root(&v_at, 1);
                                            if (alg_truthy(alg_less(v_at, alg_int(0)))) {
                                                alg_raise(v_g);
                                            }
                                            (void)((v_i = v_at));
                                            alg_root_top = rt_161;
                                        }
                                        alg_root_top = rt_160;
                                    }
                                }
                                else {
                                    alg_raise(frame_71.raised);
                                }
                            }
                        }
                        alg_root_top = rt_159;
                    }
                }
                alg_root_top = rt_158;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_70[] = {"Raised"};
            int32_t which_70 = alg_handler(frame_70.raised, names_70, 1);
            if (which_70 == 0) {
                {
                    int32_t rt_162 = alg_root_top;
                    volatile Value v_e = frame_70.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    alg_raise(alg_str(alg_property(v_e, "Value")));
                    alg_root_top = rt_162;
                }
            }
            else {
                alg_raise(frame_70.raised);
            }
        }
    }
    volatile Value ret_72 = alg_nil();
    alg_root_top = rt_base;
    return ret_72;
}

static Value m_interpreter_hoisttests_11_list_list_map_boolean_environment_map_string_list_map_set_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    Value v_tests = alg_widen(args[1], "List");
    (void)v_tests;
    alg_root(&v_tests, 1);
    Value v_byname = alg_widen(args[2], "Map");
    (void)v_byname;
    alg_root(&v_byname, 1);
    Value v_define = alg_widen(args[3], "Boolean");
    (void)v_define;
    alg_root(&v_define, 1);
    Value v_scope = alg_widen(args[4], "Environment");
    (void)v_scope;
    alg_root(&v_scope, 1);
    Value v_declaredin = alg_widen(args[5], "Map");
    (void)v_declaredin;
    alg_root(&v_declaredin, 1);
    Value v_file = alg_widen(args[6], "String");
    (void)v_file;
    alg_root(&v_file, 1);
    Value v_files = alg_widen(args[7], "List");
    (void)v_files;
    alg_root(&v_files, 1);
    Value v_byfile = alg_widen(args[8], "Map");
    (void)v_byfile;
    alg_root(&v_byfile, 1);
    Value v_hoisted = alg_widen(args[9], "Set");
    (void)v_hoisted;
    alg_root(&v_hoisted, 1);
    Value v_collect = alg_widen(args[10], "Boolean");
    (void)v_collect;
    alg_root(&v_collect, 1);
    {
        int32_t rt_163 = alg_root_top;
        Value loop_73 = alg_iterable(v_statements);
        (void)loop_73;
        alg_root(&loop_73, 1);
        for (int32_t at_73 = 0; at_73 < alg_iterable_count(loop_73); at_73++) {
            int32_t rt_164 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_73, at_73);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                if (alg_truthy(alg_is(v_thestmt, "ModuleStmt"))) {
                    {
                        if (alg_truthy(v_define)) {
                            (void)(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1));
                        }
                        if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Statements"), alg_nil()))) {
                            {
                                int32_t rt_165 = alg_root_top;
                                Value v_mine = alg_not(alg_invoke(v_hoisted, "Contains", (Value[]){alg_str(alg_property(v_thestmt, "FileName"))}, 1));
                                (void)v_mine;
                                alg_root(&v_mine, 1);
                                if (alg_truthy(v_mine)) {
                                    (void)(alg_invoke(v_hoisted, "Add", (Value[]){alg_str(alg_property(v_thestmt, "FileName"))}, 1));
                                }
                                (void)(alg_invoke(v_this, "HoistTests", (Value[]){alg_property(v_thestmt, "Statements"), v_tests, v_byname, alg_bool(false), alg_cast(alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_property(v_thestmt, "FileName")}, 1), "Environment"), v_declaredin, alg_str(alg_property(v_thestmt, "FileName")), v_files, v_byfile, v_hoisted, v_mine}, 11));
                                alg_root_top = rt_165;
                            }
                        }
                    }
                } else {
                    if (alg_truthy(alg_is(v_thestmt, "FunctionStmt"))) {
                        {
                            if (alg_truthy(v_define)) {
                                (void)(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1));
                            }
                            if (alg_truthy((or_6 = alg_not_equal(alg_property(alg_property(v_thestmt, "Name"), "Literal"), alg_nil()), !alg_truthy(or_6) ? or_6 : v_collect))) {
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
                        if (alg_truthy((or_11 = v_define, !alg_truthy(or_11) ? or_11 : ((or_10 = (or_9 = (or_8 = (or_7 = alg_is(v_thestmt, "ClassStmt"), alg_truthy(or_7) ? or_7 : alg_is(v_thestmt, "ObjectStmt")), alg_truthy(or_8) ? or_8 : alg_is(v_thestmt, "EnumStmt")), alg_truthy(or_9) ? or_9 : alg_is(v_thestmt, "VarGroupStmt")), alg_truthy(or_10) ? or_10 : alg_is(v_thestmt, "VarStmt")))))) {
                            (void)(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1));
                        }
                    }
                }
            }
            alg_root_top = rt_164;
        }
        alg_root_top = rt_163;
    }
    Value ret_74 = alg_nil();
    alg_root_top = rt_base;
    return ret_74;
}

static Value m_interpreter_runtests_2_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    volatile Value v_filename = alg_widen(args[1], "String");
    (void)v_filename;
    alg_root(&v_filename, 1);
    volatile Value v_tests = alg_nil();
    (void)v_tests;
    alg_root(&v_tests, 1);
    volatile Value v_passed = alg_nil();
    (void)v_passed;
    alg_root(&v_passed, 1);
    volatile Value v_failed = alg_nil();
    (void)v_failed;
    alg_root(&v_failed, 1);
    (void)(alg_set_property(v_this, "RootFile", alg_str(v_filename)));
    (void)(alg_invoke(v_this, "RegisterRoot", NULL, 0));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("AssertTrue"), alg_new(k_native, (Value[]){alg_string("AssertTrue"), alg_int(1)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("AssertEqual"), alg_new(k_native, (Value[]){alg_string("AssertEqual"), alg_int(2)}, 2)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_string("Fail"), alg_new(k_native, (Value[]){alg_string("Fail"), alg_int(1)}, 2)}, 2));
    (void)(f_suppressoutput(NULL, (Value[]){alg_bool(true)}, 1));
    (void)((v_tests = alg_list()));
    volatile Value v_byname = alg_map();
    (void)v_byname;
    alg_root(&v_byname, 1);
    volatile Value v_declaredin = alg_map();
    (void)v_declaredin;
    alg_root(&v_declaredin, 1);
    volatile Value v_files = alg_list();
    (void)v_files;
    alg_root(&v_files, 1);
    volatile Value v_byfile = alg_map();
    (void)v_byfile;
    alg_root(&v_byfile, 1);
    volatile Value v_hoisted = alg_set();
    (void)v_hoisted;
    alg_root(&v_hoisted, 1);
    (void)(alg_invoke(v_hoisted, "Add", (Value[]){v_filename}, 1));
    (void)(alg_invoke(v_this, "HoistTests", (Value[]){v_statements, v_tests, v_byname, alg_bool(true), alg_property(v_this, "Globals"), v_declaredin, v_filename, v_files, v_byfile, v_hoisted, alg_bool(true)}, 11));
    (void)(alg_writeln(f_testopening(NULL, (Value[]){alg_property(v_tests, "Length")}, 1)));
    (void)((v_passed = alg_int(0)));
    (void)((v_failed = alg_int(0)));
    volatile Value v_ordered = alg_list();
    (void)v_ordered;
    alg_root(&v_ordered, 1);
    {
        int32_t rt_166 = alg_root_top;
        volatile Value loop_75 = alg_iterable(v_files);
        (void)loop_75;
        alg_root(&loop_75, 1);
        for (volatile int32_t at_75 = 0; at_75 < alg_iterable_count(loop_75); at_75++) {
            int32_t rt_167 = alg_root_top;
            volatile Value v_file = alg_iterable_at(loop_75, at_75);
            (void)v_file;
            alg_root(&v_file, 1);
            {
                int32_t rt_168 = alg_root_top;
                volatile Value v_group = alg_cast(alg_invoke(v_byfile, "Get", (Value[]){v_file}, 1), "List");
                (void)v_group;
                alg_root(&v_group, 1);
                (void)(alg_invoke(v_group, "Sort", NULL, 0));
                (void)(alg_invoke(v_ordered, "Add", (Value[]){v_file}, 1));
                {
                    int32_t rt_169 = alg_root_top;
                    volatile Value loop_76 = alg_iterable(v_group);
                    (void)loop_76;
                    alg_root(&loop_76, 1);
                    for (volatile int32_t at_76 = 0; at_76 < alg_iterable_count(loop_76); at_76++) {
                        int32_t rt_170 = alg_root_top;
                        volatile Value v_each = alg_iterable_at(loop_76, at_76);
                        (void)v_each;
                        alg_root(&v_each, 1);
                        (void)(alg_invoke(v_ordered, "Add", (Value[]){v_each}, 1));
                        alg_root_top = rt_170;
                    }
                    alg_root_top = rt_169;
                }
                alg_root_top = rt_168;
            }
            alg_root_top = rt_167;
        }
        alg_root_top = rt_166;
    }
    {
        int32_t rt_171 = alg_root_top;
        volatile Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_ordered, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_not(alg_invoke(v_byname, "Contains", (Value[]){alg_subscript_get(v_ordered, v_i)}, 1)))) {
                    {
                        if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                            (void)(alg_writeln((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag)));
                        }
                        (void)(alg_writeln(f_testbanner(NULL, (Value[]){alg_str(alg_subscript_get(v_ordered, v_i))}, 1)));
                    }
                } else {
                    {
                        int32_t rt_172 = alg_root_top;
                        volatile Value v_thetest = alg_invoke(v_byname, "Get", (Value[]){alg_subscript_get(v_ordered, v_i)}, 1);
                        (void)v_thetest;
                        alg_root(&v_thetest, 1);
                        volatile Value v_name = alg_str(alg_property(alg_property(v_thetest, "Name"), "Literal"));
                        (void)v_name;
                        alg_root(&v_name, 1);
                        {
                            AlgFrame frame_77;
                            alg_push_frame(&frame_77);
                            if (ALG_SETJMP(frame_77.jump) == 0) {
                                {
                                    int32_t rt_173 = alg_root_top;
                                    volatile Value v_scope = alg_property(v_this, "Globals");
                                    (void)v_scope;
                                    alg_root(&v_scope, 1);
                                    if (alg_truthy(alg_invoke(v_declaredin, "Contains", (Value[]){alg_subscript_get(v_ordered, v_i)}, 1))) {
                                        (void)((v_scope = alg_cast(alg_invoke(v_declaredin, "Get", (Value[]){alg_subscript_get(v_ordered, v_i)}, 1), "Environment")));
                                    }
                                    volatile Value v_body = alg_invoke(v_scope, "Get", (Value[]){alg_property(v_thetest, "Name")}, 1);
                                    (void)v_body;
                                    alg_root(&v_body, 1);
                                    (void)(alg_invoke(v_body, "Call", (Value[]){v_this, alg_list()}, 2));
                                    (void)((v_passed = alg_add(v_passed, alg_int(1))));
                                    (void)(alg_writeln(f_testline(NULL, (Value[]){v_name, alg_string("PASS")}, 2)));
                                    alg_root_top = rt_173;
                                }
                                alg_pop_frame();
                            }
                            else {
                                static const char *names_77[] = {"String", "Raised"};
                                int32_t which_77 = alg_handler(frame_77.raised, names_77, 2);
                                if (which_77 == 0) {
                                    {
                                        int32_t rt_174 = alg_root_top;
                                        volatile Value v_e = frame_77.raised;
                                        (void)v_e;
                                        alg_root(&v_e, 1);
                                        {
                                            (void)((v_failed = alg_add(v_failed, alg_int(1))));
                                            (void)(alg_writeln(f_testline(NULL, (Value[]){v_name, alg_string("FAIL")}, 2)));
                                            (void)(alg_writeln(f_testfailure(NULL, (Value[]){v_filename, v_e}, 2)));
                                        }
                                        alg_root_top = rt_174;
                                    }
                                }
                                else if (which_77 == 1) {
                                    {
                                        int32_t rt_175 = alg_root_top;
                                        volatile Value v_e = frame_77.raised;
                                        (void)v_e;
                                        alg_root(&v_e, 1);
                                        {
                                            (void)((v_failed = alg_add(v_failed, alg_int(1))));
                                            (void)(alg_writeln(f_testline(NULL, (Value[]){v_name, alg_string("FAIL")}, 2)));
                                            (void)(alg_writeln(f_testfailure(NULL, (Value[]){v_filename, alg_str(alg_property(v_e, "Value"))}, 2)));
                                        }
                                        alg_root_top = rt_175;
                                    }
                                }
                                else {
                                    alg_raise(frame_77.raised);
                                }
                            }
                        }
                        alg_root_top = rt_172;
                    }
                }
            }
        }
        alg_root_top = rt_171;
    }
    (void)(alg_writeln((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag)));
    (void)(alg_writeln(f_testtotals(NULL, (Value[]){v_passed, v_failed}, 2)));
    volatile Value ret_78 = v_failed;
    alg_root_top = rt_base;
    return ret_78;
    volatile Value ret_79 = alg_nil();
    alg_root_top = rt_base;
    return ret_79;
}

static Value m_interpreter_visitliteral_1_literalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "LiteralExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value ret_80 = alg_property(v_theexpr, "Value");
    alg_root_top = rt_base;
    return ret_80;
    Value ret_81 = alg_nil();
    alg_root_top = rt_base;
    return ret_81;
}

static Value m_interpreter_visitlogical_1_logicalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "LogicalExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_left = alg_nil();
    (void)v_left;
    alg_root(&v_left, 1);
    (void)((v_left = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Left")}, 1)));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVor))) {
        {
            if (alg_truthy(alg_invoke(v_this, "IsTruthy", (Value[]){v_left}, 1))) {
                Value ret_82 = v_left;
                alg_root_top = rt_base;
                return ret_82;
            }
        }
    } else {
        if (alg_truthy(alg_not(alg_invoke(v_this, "IsTruthy", (Value[]){v_left}, 1)))) {
            Value ret_83 = v_left;
            alg_root_top = rt_base;
            return ret_83;
        }
    }
    Value ret_84 = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Right")}, 1);
    alg_root_top = rt_base;
    return ret_84;
    Value ret_85 = alg_nil();
    alg_root_top = rt_base;
    return ret_85;
}

static Value m_interpreter_visitgrouping_1_groupingexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GroupingExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value ret_86 = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Expression")}, 1);
    alg_root_top = rt_base;
    return ret_86;
    Value ret_87 = alg_nil();
    alg_root_top = rt_base;
    return ret_87;
}

static Value m_interpreter_visitunary_1_unaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "UnaryExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    (void)((v_right = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Right")}, 1)));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVminus))) {
        {
            if (alg_truthy(alg_is(v_right, "ObjInstance"))) {
                {
                    int32_t rt_176 = alg_root_top;
                    Value v_negate = alg_invoke(alg_property(v_right, "Klass"), "MethodOfArity", (Value[]){alg_char_value(45), alg_int(0)}, 2);
                    (void)v_negate;
                    alg_root(&v_negate, 1);
                    if (alg_truthy(alg_not_equal(v_negate, alg_nil()))) {
                        Value ret_88 = alg_invoke(alg_invoke(v_negate, "Bind", (Value[]){v_right}, 1), "Call", (Value[]){v_this, alg_list()}, 2);
                        alg_root_top = rt_base;
                        return ret_88;
                    }
                    alg_root_top = rt_176;
                }
            }
            Value ret_89 = alg_negate(v_right);
            alg_root_top = rt_base;
            return ret_89;
        }
    } else {
        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVnot))) {
            Value ret_90 = alg_not(alg_invoke(v_this, "IsTruthy", (Value[]){v_right}, 1));
            alg_root_top = rt_base;
            return ret_90;
        } else {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVtilde))) {
                {
                    if (alg_truthy(alg_is(v_right, "ObjInstance"))) {
                        {
                            int32_t rt_177 = alg_root_top;
                            Value v_invert = alg_invoke(alg_property(v_right, "Klass"), "MethodOfArity", (Value[]){alg_char_value(126), alg_int(0)}, 2);
                            (void)v_invert;
                            alg_root(&v_invert, 1);
                            if (alg_truthy(alg_not_equal(v_invert, alg_nil()))) {
                                Value ret_91 = alg_invoke(alg_invoke(v_invert, "Bind", (Value[]){v_right}, 1), "Call", (Value[]){v_this, alg_list()}, 2);
                                alg_root_top = rt_base;
                                return ret_91;
                            }
                            alg_root_top = rt_177;
                        }
                    }
                    Value ret_92 = alg_bit_not(v_right);
                    alg_root_top = rt_base;
                    return ret_92;
                }
            }
        }
    }
    Value ret_93 = alg_nil();
    alg_root_top = rt_base;
    return ret_93;
}

static Value m_interpreter_visitcollectionexpr_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
        {
            (void)((v_result = alg_new(k_objcollection, (Value[]){alg_string("Map")}, 1)));
            {
                int32_t rt_178 = alg_root_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Keys"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(alg_property(v_result, "Pairs"), "Put", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Keys"), v_i)}, 1), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Values"), v_i)}, 1)}, 2));
                }
                alg_root_top = rt_178;
            }
            Value ret_94 = v_result;
            alg_root_top = rt_base;
            return ret_94;
        }
    }
    (void)((v_result = alg_new(k_objcollection, (Value[]){alg_string("List")}, 1)));
    {
        int32_t rt_179 = alg_root_top;
        Value loop_95 = alg_iterable(alg_property(v_theexpr, "Values"));
        (void)loop_95;
        alg_root(&loop_95, 1);
        for (int32_t at_95 = 0; at_95 < alg_iterable_count(loop_95); at_95++) {
            int32_t rt_180 = alg_root_top;
            Value v_value = alg_iterable_at(loop_95, at_95);
            (void)v_value;
            alg_root(&v_value, 1);
            (void)(alg_invoke(alg_property(v_result, "Items"), "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){v_value}, 1)}, 1));
            alg_root_top = rt_180;
        }
        alg_root_top = rt_179;
    }
    Value ret_96 = v_result;
    alg_root_top = rt_base;
    return ret_96;
    Value ret_97 = alg_nil();
    alg_root_top = rt_base;
    return ret_97;
}

static Value m_interpreter_visitsubscriptexpr_1_subscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SubscriptExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_target = alg_nil();
    (void)v_target;
    alg_root(&v_target, 1);
    Value v_index = alg_nil();
    (void)v_index;
    alg_root(&v_index, 1);
    (void)((v_target = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)));
    (void)((v_index = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Index")}, 1)));
    if (alg_truthy(alg_is(v_target, "ObjCollection"))) {
        Value ret_98 = alg_invoke(v_target, "At", (Value[]){v_index}, 1);
        alg_root_top = rt_base;
        return ret_98;
    }
    if (alg_truthy(alg_is(v_target, "ObjBuffer"))) {
        Value ret_99 = alg_invoke(v_target, "At", (Value[]){v_index}, 1);
        alg_root_top = rt_base;
        return ret_99;
    }
    if (alg_truthy(alg_is(v_target, "ObjInstance"))) {
        {
            int32_t rt_181 = alg_root_top;
            Value v_reader = alg_invoke(alg_property(v_target, "Klass"), "MethodOfArity", (Value[]){alg_string("get"), alg_int(1)}, 2);
            (void)v_reader;
            alg_root(&v_reader, 1);
            if (alg_truthy(alg_not_equal(v_reader, alg_nil()))) {
                Value ret_100 = alg_invoke(alg_invoke(v_reader, "Bind", (Value[]){v_target}, 1), "Call", (Value[]){v_this, alg_list_keep(alg_list(), v_index)}, 2);
                alg_root_top = rt_base;
                return ret_100;
            }
            alg_root_top = rt_181;
        }
    }
    if (alg_truthy(alg_invoke(v_this, "IsText", (Value[]){v_target}, 1))) {
        Value ret_101 = alg_subscript_get(alg_str(v_target), v_index);
        alg_root_top = rt_base;
        return ret_101;
    }
    alg_raise(alg_string("Subscript target should be an ordinal."));
    Value ret_102 = alg_nil();
    alg_root_top = rt_base;
    return ret_102;
}

static Value m_interpreter_visitsetsubscriptexpr_1_setsubscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SetSubscriptExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_target = alg_nil();
    (void)v_target;
    alg_root(&v_target, 1);
    Value v_index = alg_nil();
    (void)v_index;
    alg_root(&v_index, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    (void)((v_target = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)));
    (void)((v_index = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Index")}, 1)));
    (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1)));
    if (alg_truthy(alg_is(v_target, "ObjCollection"))) {
        Value ret_103 = alg_invoke(v_target, "PutAt", (Value[]){v_index, v_value}, 2);
        alg_root_top = rt_base;
        return ret_103;
    }
    if (alg_truthy(alg_is(v_target, "ObjBuffer"))) {
        Value ret_104 = alg_invoke(v_target, "PutAt", (Value[]){v_index, v_value}, 2);
        alg_root_top = rt_base;
        return ret_104;
    }
    if (alg_truthy(alg_is(v_target, "ObjInstance"))) {
        {
            int32_t rt_182 = alg_root_top;
            Value v_writer = alg_invoke(alg_property(v_target, "Klass"), "MethodOfArity", (Value[]){alg_string("put"), alg_int(2)}, 2);
            (void)v_writer;
            alg_root(&v_writer, 1);
            if (alg_truthy(alg_not_equal(v_writer, alg_nil()))) {
                Value ret_105 = alg_invoke(alg_invoke(v_writer, "Bind", (Value[]){v_target}, 1), "Call", (Value[]){v_this, alg_list_keep(alg_list_keep(alg_list(), v_index), v_value)}, 2);
                alg_root_top = rt_base;
                return ret_105;
            }
            alg_root_top = rt_182;
        }
    }
    if (alg_truthy(alg_invoke(v_this, "IsText", (Value[]){v_target}, 1))) {
        alg_raise(alg_string("Strings are immutable."));
    }
    alg_raise(alg_string("Subscript target should be an ordinal."));
    Value ret_106 = alg_nil();
    alg_root_top = rt_base;
    return ret_106;
}

static Value m_interpreter_istext_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    Value ret_107 = (or_12 = alg_is(v_obj, "String"), alg_truthy(or_12) ? or_12 : alg_is(v_obj, "Char"));
    alg_root_top = rt_base;
    return ret_107;
    Value ret_108 = alg_nil();
    alg_root_top = rt_base;
    return ret_108;
}

static Value m_interpreter_insubrange_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    Value v_thename = alg_widen(args[1], "String");
    (void)v_thename;
    alg_root(&v_thename, 1);
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    if (alg_truthy(alg_not((alg_is(v_value, "Integer"))))) {
        Value ret_109 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_109;
    }
    (void)((v_at = f_subrangeindex(NULL, (Value[]){v_thename}, 1)));
    Value ret_110 = (or_13 = alg_greater_equal(v_value, alg_subscript_get((alg_declared(d_subrangeVlows, "SUBRANGE_LOWS"), v_subrangeVlows), v_at)), !alg_truthy(or_13) ? or_13 : alg_less_equal(v_value, alg_subscript_get((alg_declared(d_subrangeVhighs, "SUBRANGE_HIGHS"), v_subrangeVhighs), v_at)));
    alg_root_top = rt_base;
    return ret_110;
    Value ret_111 = alg_nil();
    alg_root_top = rt_base;
    return ret_111;
}

static Value m_interpreter_satisfiestype_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    Value v_thename = alg_widen(args[1], "String");
    (void)v_thename;
    alg_root(&v_thename, 1);
    if (alg_truthy(f_issubrange(NULL, (Value[]){v_thename}, 1))) {
        Value ret_112 = alg_invoke(v_this, "InSubrange", (Value[]){v_value, v_thename}, 2);
        alg_root_top = rt_base;
        return ret_112;
    }
    Value v_wanted = f_canonicaltype(NULL, (Value[]){v_thename}, 1);
    (void)v_wanted;
    alg_root(&v_wanted, 1);
    if (alg_truthy(alg_equal(alg_to_lower(f_typenameof(NULL, (Value[]){v_value}, 1)), alg_to_lower(v_wanted)))) {
        Value ret_113 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_113;
    }
    Value ret_114 = f_inheritsfrom(NULL, (Value[]){v_value, v_wanted}, 2);
    alg_root_top = rt_base;
    return ret_114;
    Value ret_115 = alg_nil();
    alg_root_top = rt_base;
    return ret_115;
}

static Value m_interpreter_visitisexpr_1_isexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "IsExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)));
    if (alg_truthy(alg_equal(v_value, alg_nil()))) {
        Value ret_116 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_116;
    }
    Value ret_117 = alg_invoke(v_this, "SatisfiesType", (Value[]){v_value, alg_str(alg_property(alg_property(v_theexpr, "TypeName"), "Lexeme"))}, 2);
    alg_root_top = rt_base;
    return ret_117;
    Value ret_118 = alg_nil();
    alg_root_top = rt_base;
    return ret_118;
}

static Value m_interpreter_visitvariableexpr_1_variableexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_theexpr = alg_widen(args[0], "VariableExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    {
        AlgFrame frame_119;
        alg_push_frame(&frame_119);
        if (ALG_SETJMP(frame_119.jump) == 0) {
            {
                volatile Value ret_120 = alg_invoke(v_this, "LookupVariable", (Value[]){alg_property(v_theexpr, "Name"), v_theexpr}, 2);
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_120;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_119[] = {"String"};
            int32_t which_119 = alg_handler(frame_119.raised, names_119, 1);
            if (which_119 == 0) {
                {
                    int32_t rt_183 = alg_root_top;
                    volatile Value v_e = frame_119.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_121 = alg_invoke(v_this, "ThisField", (Value[]){alg_property(v_theexpr, "Name"), v_e}, 2);
                    alg_root_top = rt_base;
                    return ret_121;
                    alg_root_top = rt_183;
                }
            }
            else {
                alg_raise(frame_119.raised);
            }
        }
    }
    volatile Value ret_122 = alg_nil();
    alg_root_top = rt_base;
    return ret_122;
}

static Value m_interpreter_thisfield_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    volatile Value v_original = alg_widen(args[1], "String");
    (void)v_original;
    alg_root(&v_original, 1);
    volatile Value v_obj = alg_nil();
    (void)v_obj;
    alg_root(&v_obj, 1);
    {
        AlgFrame frame_123;
        alg_push_frame(&frame_123);
        if (ALG_SETJMP(frame_123.jump) == 0) {
            {
                (void)((v_obj = alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_new(k_token, (Value[]){e_tokentype_tokenVthis, alg_string("this"), alg_nil(), alg_property(v_name, "LineNumber")}, 4)}, 1)));
                volatile Value ret_124 = alg_invoke(v_obj, "Get", (Value[]){v_name}, 1);
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_124;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_123[] = {"String"};
            int32_t which_123 = alg_handler(frame_123.raised, names_123, 1);
            if (which_123 == 0) {
                {
                    int32_t rt_184 = alg_root_top;
                    volatile Value v_e = frame_123.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    alg_raise(v_original);
                    alg_root_top = rt_184;
                }
            }
            else {
                alg_raise(frame_123.raised);
            }
        }
    }
    volatile Value ret_125 = alg_nil();
    alg_root_top = rt_base;
    return ret_125;
}

static Value m_interpreter_setthisfield_3_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    volatile Value v_value = args[1];
    (void)v_value;
    alg_root(&v_value, 1);
    volatile Value v_original = alg_widen(args[2], "String");
    (void)v_original;
    alg_root(&v_original, 1);
    volatile Value v_obj = alg_nil();
    (void)v_obj;
    alg_root(&v_obj, 1);
    {
        AlgFrame frame_126;
        alg_push_frame(&frame_126);
        if (ALG_SETJMP(frame_126.jump) == 0) {
            {
                (void)((v_obj = alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_new(k_token, (Value[]){e_tokentype_tokenVthis, alg_string("this"), alg_nil(), alg_property(v_name, "LineNumber")}, 4)}, 1)));
                (void)(alg_invoke(v_obj, "Set", (Value[]){v_name, v_value}, 2));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_126[] = {"String"};
            int32_t which_126 = alg_handler(frame_126.raised, names_126, 1);
            if (which_126 == 0) {
                {
                    int32_t rt_185 = alg_root_top;
                    volatile Value v_e = frame_126.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    alg_raise(v_original);
                    alg_root_top = rt_185;
                }
            }
            else {
                alg_raise(frame_126.raised);
            }
        }
    }
    volatile Value ret_127 = alg_nil();
    alg_root_top = rt_base;
    return ret_127;
}

static Value m_interpreter_lookupvariable_2_token_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    volatile Value v_theexpr = alg_widen(args[1], "Expr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    volatile Value v_distance = alg_nil();
    (void)v_distance;
    alg_root(&v_distance, 1);
    (void)((v_distance = alg_cast(alg_invoke(alg_property(v_this, "Locals"), "Get", (Value[]){v_theexpr}, 1), "Integer")));
    if (alg_truthy(alg_not_equal(v_distance, alg_nil()))) {
        volatile Value ret_128 = alg_invoke(alg_property(v_this, "Env"), "GetAt", (Value[]){v_distance, alg_property(v_name, "Lexeme")}, 2);
        alg_root_top = rt_base;
        return ret_128;
    }
    {
        AlgFrame frame_129;
        alg_push_frame(&frame_129);
        if (ALG_SETJMP(frame_129.jump) == 0) {
            {
                volatile Value ret_130 = alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){v_name}, 1);
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_130;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_129[] = {"String"};
            int32_t which_129 = alg_handler(frame_129.raised, names_129, 1);
            if (which_129 == 0) {
                {
                    int32_t rt_186 = alg_root_top;
                    volatile Value v_e = frame_129.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    alg_raise(alg_invoke(v_this, "SuggestUnit", (Value[]){v_name, v_e}, 2));
                    alg_root_top = rt_186;
                }
            }
            else {
                alg_raise(frame_129.raised);
            }
        }
    }
    volatile Value ret_131 = alg_nil();
    alg_root_top = rt_base;
    return ret_131;
}

static Value m_interpreter_shown_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    Value v_method = alg_invoke(alg_property(v_value, "Klass"), "MethodOfArity", (Value[]){alg_string("tostring"), alg_int(0)}, 2);
    (void)v_method;
    alg_root(&v_method, 1);
    if (alg_truthy(alg_not_equal(v_method, alg_nil()))) {
        Value ret_132 = f_stringify(NULL, (Value[]){v_this, alg_invoke(alg_invoke(v_method, "Bind", (Value[]){v_value}, 1), "Call", (Value[]){v_this, alg_list()}, 2)}, 2);
        alg_root_top = rt_base;
        return ret_132;
    }
    Value ret_133 = alg_add(alg_str(alg_property(alg_property(v_value, "Klass"), "Name")), alg_string(" instance"));
    alg_root_top = rt_base;
    return ret_133;
    Value ret_134 = alg_nil();
    alg_root_top = rt_base;
    return ret_134;
}

static Value m_interpreter_suggestunit_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_message = alg_widen(args[1], "String");
    (void)v_message;
    alg_root(&v_message, 1);
    if (alg_truthy(alg_not_equal(alg_copy(v_message, alg_int(0), alg_int(19)), alg_string("Undefined variable ")))) {
        Value ret_135 = alg_str(v_message);
        alg_root_top = rt_base;
        return ret_135;
    }
    Value v_units = alg_invoke(alg_property(v_this, "UnitsByName"), "Keys", NULL, 0);
    (void)v_units;
    alg_root(&v_units, 1);
    {
        int32_t rt_187 = alg_root_top;
        Value loop_136 = alg_iterable(v_units);
        (void)loop_136;
        alg_root(&loop_136, 1);
        for (int32_t at_136 = 0; at_136 < alg_iterable_count(loop_136); at_136++) {
            int32_t rt_188 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_136, at_136);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            {
                int32_t rt_189 = alg_root_top;
                Value v_moduleenv = alg_cast(alg_invoke(alg_property(v_this, "UnitsByName"), "Get", (Value[]){v_theunit}, 1), "Environment");
                (void)v_moduleenv;
                alg_root(&v_moduleenv, 1);
                if (alg_truthy((or_14 = alg_not_equal(alg_property(v_moduleenv, "Exports"), alg_nil()), !alg_truthy(or_14) ? or_14 : alg_invoke(alg_property(v_moduleenv, "Exports"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1)))) {
                    Value ret_137 = alg_add(alg_add(alg_add(alg_str(v_message), alg_string(" Unit '")), alg_str(alg_property(v_moduleenv, "UnitName"))), alg_string("' exports it; this file has no 'uses' for it."));
                    alg_root_top = rt_base;
                    return ret_137;
                }
                alg_root_top = rt_189;
            }
            alg_root_top = rt_188;
        }
        alg_root_top = rt_187;
    }
    if (alg_truthy((or_15 = alg_not_equal(alg_property(v_this, "Env"), alg_property(v_this, "Globals")), !alg_truthy(or_15) ? or_15 : alg_invoke(alg_property(alg_property(v_this, "Globals"), "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1)))) {
        Value ret_138 = alg_add(alg_str(v_message), alg_string(" The file the program started from declares it, and no file can 'uses' that."));
        alg_root_top = rt_base;
        return ret_138;
    }
    Value ret_139 = alg_str(v_message);
    alg_root_top = rt_base;
    return ret_139;
    Value ret_140 = alg_nil();
    alg_root_top = rt_base;
    return ret_140;
}

static Value m_interpreter_integerdivide_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_left = args[0];
    (void)v_left;
    alg_root(&v_left, 1);
    Value v_right = args[1];
    (void)v_right;
    alg_root(&v_right, 1);
    if (alg_truthy((or_16 = alg_not((alg_is(v_left, "Integer"))), alg_truthy(or_16) ? or_16 : alg_not((alg_is(v_right, "Integer")))))) {
        alg_raise(alg_string("div expects Integers."));
    }
    if (alg_truthy(alg_equal(v_right, alg_int(0)))) {
        alg_raise(alg_string("Division by zero."));
    }
    Value ret_141 = alg_div_int(v_left, v_right);
    alg_root_top = rt_base;
    return ret_141;
    Value ret_142 = alg_nil();
    alg_root_top = rt_base;
    return ret_142;
}

static Value m_interpreter_remainder_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_left = args[0];
    (void)v_left;
    alg_root(&v_left, 1);
    Value v_right = args[1];
    (void)v_right;
    alg_root(&v_right, 1);
    if (alg_truthy((or_17 = alg_not((alg_is(v_left, "Integer"))), alg_truthy(or_17) ? or_17 : alg_not((alg_is(v_right, "Integer")))))) {
        alg_raise(alg_string("mod expects Integers."));
    }
    if (alg_truthy(alg_equal(v_right, alg_int(0)))) {
        alg_raise(alg_string("Division by zero."));
    }
    Value ret_143 = alg_mod(v_left, v_right);
    alg_root_top = rt_base;
    return ret_143;
    Value ret_144 = alg_nil();
    alg_root_top = rt_base;
    return ret_144;
}

static Value m_interpreter_bitwise_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_op = args[0];
    (void)v_op;
    alg_root(&v_op, 1);
    Value ret_145 = (or_21 = (or_20 = (or_19 = (or_18 = alg_equal(v_op, e_tokentype_tokenVampersand), alg_truthy(or_18) ? or_18 : alg_equal(v_op, e_tokentype_tokenVpipe)), alg_truthy(or_19) ? or_19 : alg_equal(v_op, e_tokentype_tokenVcaret)), alg_truthy(or_20) ? or_20 : alg_equal(v_op, e_tokentype_tokenVshiftVleft)), alg_truthy(or_21) ? or_21 : alg_equal(v_op, e_tokentype_tokenVshiftVright));
    alg_root_top = rt_base;
    return ret_145;
    Value ret_146 = alg_nil();
    alg_root_top = rt_base;
    return ret_146;
}

static Value m_interpreter_arithmetic_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_op = args[0];
    (void)v_op;
    alg_root(&v_op, 1);
    Value ret_147 = (or_26 = (or_25 = (or_24 = (or_23 = (or_22 = alg_equal(v_op, e_tokentype_tokenVplus), alg_truthy(or_22) ? or_22 : alg_equal(v_op, e_tokentype_tokenVminus)), alg_truthy(or_23) ? or_23 : alg_equal(v_op, e_tokentype_tokenVstar)), alg_truthy(or_24) ? or_24 : alg_equal(v_op, e_tokentype_tokenVslash)), alg_truthy(or_25) ? or_25 : alg_equal(v_op, e_tokentype_tokenVdiv)), alg_truthy(or_26) ? or_26 : alg_equal(v_op, e_tokentype_tokenVmod));
    alg_root_top = rt_base;
    return ret_147;
    Value ret_148 = alg_nil();
    alg_root_top = rt_base;
    return ret_148;
}

static Value m_interpreter_orders_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_op = args[0];
    (void)v_op;
    alg_root(&v_op, 1);
    Value ret_149 = (or_29 = (or_28 = (or_27 = alg_equal(v_op, e_tokentype_tokenVless), alg_truthy(or_27) ? or_27 : alg_equal(v_op, e_tokentype_tokenVlessVequal)), alg_truthy(or_28) ? or_28 : alg_equal(v_op, e_tokentype_tokenVgreater)), alg_truthy(or_29) ? or_29 : alg_equal(v_op, e_tokentype_tokenVgreaterVequal));
    alg_root_top = rt_base;
    return ret_149;
    Value ret_150 = alg_nil();
    alg_root_top = rt_base;
    return ret_150;
}

static Value m_interpreter_visitbinary_1_binaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "BinaryExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_left = alg_nil();
    (void)v_left;
    alg_root(&v_left, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    (void)((v_left = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Left")}, 1)));
    (void)((v_right = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Right")}, 1)));
    if (alg_truthy((or_31 = alg_is(v_left, "ObjInstance"), !alg_truthy(or_31) ? or_31 : ((or_30 = alg_invoke(v_this, "Arithmetic", (Value[]){alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken")}, 1), alg_truthy(or_30) ? or_30 : alg_invoke(v_this, "Bitwise", (Value[]){alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken")}, 1)))))) {
        {
            int32_t rt_190 = alg_root_top;
            Value v_defined = alg_invoke(alg_property(v_left, "Klass"), "MethodOfArity", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Op"), "Lexeme")), alg_int(1)}, 2);
            (void)v_defined;
            alg_root(&v_defined, 1);
            if (alg_truthy(alg_not_equal(v_defined, alg_nil()))) {
                Value ret_151 = alg_invoke(alg_invoke(v_defined, "Bind", (Value[]){v_left}, 1), "Call", (Value[]){v_this, alg_list_keep(alg_list(), v_right)}, 2);
                alg_root_top = rt_base;
                return ret_151;
            }
            alg_root_top = rt_190;
        }
    }
    if (alg_truthy((or_32 = alg_is(v_left, "ObjInstance"), !alg_truthy(or_32) ? or_32 : alg_invoke(v_this, "Orders", (Value[]){alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken")}, 1)))) {
        {
            int32_t rt_191 = alg_root_top;
            Value v_ordering = alg_invoke(alg_property(v_left, "Klass"), "MethodOfArity", (Value[]){alg_string("compare"), alg_int(1)}, 2);
            (void)v_ordering;
            alg_root(&v_ordering, 1);
            if (alg_truthy(alg_not_equal(v_ordering, alg_nil()))) {
                {
                    (void)((v_left = alg_invoke(alg_invoke(v_ordering, "Bind", (Value[]){v_left}, 1), "Call", (Value[]){v_this, alg_list_keep(alg_list(), v_right)}, 2)));
                    (void)((v_right = alg_int(0)));
                    if (alg_truthy(alg_not((alg_is(v_left, "Integer"))))) {
                        alg_raise(alg_string("Compare must answer an Integer."));
                    }
                }
            }
            alg_root_top = rt_191;
        }
    }
    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVgreater))) {
        Value ret_152 = alg_greater(v_left, v_right);
        alg_root_top = rt_base;
        return ret_152;
    } else {
        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVgreaterVequal))) {
            Value ret_153 = alg_greater_equal(v_left, v_right);
            alg_root_top = rt_base;
            return ret_153;
        } else {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVless))) {
                Value ret_154 = alg_less(v_left, v_right);
                alg_root_top = rt_base;
                return ret_154;
            } else {
                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVlessVequal))) {
                    Value ret_155 = alg_less_equal(v_left, v_right);
                    alg_root_top = rt_base;
                    return ret_155;
                } else {
                    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVnotVequal))) {
                        Value ret_156 = alg_not(alg_invoke(v_this, "IsEqual", (Value[]){v_left, v_right}, 2));
                        alg_root_top = rt_base;
                        return ret_156;
                    } else {
                        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVequal))) {
                            Value ret_157 = alg_invoke(v_this, "IsEqual", (Value[]){v_left, v_right}, 2);
                            alg_root_top = rt_base;
                            return ret_157;
                        } else {
                            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVin))) {
                                Value ret_158 = alg_invoke(v_this, "Contains", (Value[]){v_right, v_left}, 2);
                                alg_root_top = rt_base;
                                return ret_158;
                            } else {
                                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVplus))) {
                                    Value ret_159 = alg_add(v_left, v_right);
                                    alg_root_top = rt_base;
                                    return ret_159;
                                } else {
                                    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVminus))) {
                                        Value ret_160 = alg_subtract(v_left, v_right);
                                        alg_root_top = rt_base;
                                        return ret_160;
                                    } else {
                                        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVslash))) {
                                            Value ret_161 = alg_divide(v_left, v_right);
                                            alg_root_top = rt_base;
                                            return ret_161;
                                        } else {
                                            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVdiv))) {
                                                Value ret_162 = alg_invoke(v_this, "IntegerDivide", (Value[]){v_left, v_right}, 2);
                                                alg_root_top = rt_base;
                                                return ret_162;
                                            } else {
                                                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVmod))) {
                                                    Value ret_163 = alg_invoke(v_this, "Remainder", (Value[]){v_left, v_right}, 2);
                                                    alg_root_top = rt_base;
                                                    return ret_163;
                                                } else {
                                                    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVstar))) {
                                                        Value ret_164 = alg_multiply(v_left, v_right);
                                                        alg_root_top = rt_base;
                                                        return ret_164;
                                                    } else {
                                                        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVampersand))) {
                                                            Value ret_165 = alg_bit_and(v_left, v_right);
                                                            alg_root_top = rt_base;
                                                            return ret_165;
                                                        } else {
                                                            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVpipe))) {
                                                                Value ret_166 = alg_bit_or(v_left, v_right);
                                                                alg_root_top = rt_base;
                                                                return ret_166;
                                                            } else {
                                                                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVcaret))) {
                                                                    Value ret_167 = alg_bit_xor(v_left, v_right);
                                                                    alg_root_top = rt_base;
                                                                    return ret_167;
                                                                } else {
                                                                    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVshiftVleft))) {
                                                                        Value ret_168 = alg_shift_left(v_left, v_right);
                                                                        alg_root_top = rt_base;
                                                                        return ret_168;
                                                                    } else {
                                                                        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVshiftVright))) {
                                                                            Value ret_169 = alg_shift_right(v_left, v_right);
                                                                            alg_root_top = rt_base;
                                                                            return ret_169;
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
                        }
                    }
                }
            }
        }
    }
    Value ret_170 = alg_nil();
    alg_root_top = rt_base;
    return ret_170;
}

static Value m_interpreter_arranged_3_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_callee = args[0];
    (void)v_callee;
    alg_root(&v_callee, 1);
    Value v_arguments = alg_widen(args[1], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_names = alg_widen(args[2], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    if (alg_truthy(alg_not(f_anynamed(NULL, (Value[]){v_names}, 1)))) {
        Value ret_171 = v_arguments;
        alg_root_top = rt_base;
        return ret_171;
    }
    if (alg_truthy(alg_is(v_callee, "ObjFunction"))) {
        {
            int32_t rt_192 = alg_root_top;
            Value v_fitted = alg_invoke(v_callee, "Arrange", (Value[]){v_arguments, v_names}, 2);
            (void)v_fitted;
            alg_root(&v_fitted, 1);
            if (alg_truthy(alg_equal(v_fitted, alg_nil()))) {
                alg_raise(alg_string("No matching signature for function."));
            }
            Value ret_172 = v_fitted;
            alg_root_top = rt_base;
            return ret_172;
            alg_root_top = rt_192;
        }
    }
    if (alg_truthy(alg_is(v_callee, "ObjOverloads"))) {
        {
            {
                int32_t rt_193 = alg_root_top;
                Value loop_173 = alg_iterable(alg_property(v_callee, "Candidates"));
                (void)loop_173;
                alg_root(&loop_173, 1);
                for (int32_t at_173 = 0; at_173 < alg_iterable_count(loop_173); at_173++) {
                    int32_t rt_194 = alg_root_top;
                    Value v_candidate = alg_iterable_at(loop_173, at_173);
                    (void)v_candidate;
                    alg_root(&v_candidate, 1);
                    {
                        int32_t rt_195 = alg_root_top;
                        Value v_fitted = alg_invoke(v_candidate, "Arrange", (Value[]){v_arguments, v_names}, 2);
                        (void)v_fitted;
                        alg_root(&v_fitted, 1);
                        if (alg_truthy(alg_not_equal(v_fitted, alg_nil()))) {
                            Value ret_174 = v_fitted;
                            alg_root_top = rt_base;
                            return ret_174;
                        }
                        alg_root_top = rt_195;
                    }
                    alg_root_top = rt_194;
                }
                alg_root_top = rt_193;
            }
            alg_raise(alg_string("No matching signature for function."));
        }
    }
    if (alg_truthy(alg_is(v_callee, "ObjClass"))) {
        {
            int32_t rt_196 = alg_root_top;
            Value v_init = alg_invoke(v_callee, "FindMethod", (Value[]){alg_string("init")}, 1);
            (void)v_init;
            alg_root(&v_init, 1);
            if (alg_truthy(alg_not_equal(v_init, alg_nil()))) {
                {
                    int32_t rt_197 = alg_root_top;
                    Value v_fitted = alg_invoke(v_init, "Arrange", (Value[]){v_arguments, v_names}, 2);
                    (void)v_fitted;
                    alg_root(&v_fitted, 1);
                    if (alg_truthy(alg_not_equal(v_fitted, alg_nil()))) {
                        Value ret_175 = v_fitted;
                        alg_root_top = rt_base;
                        return ret_175;
                    }
                    alg_root_top = rt_197;
                }
            }
            alg_raise(alg_string("No matching signature for function."));
            alg_root_top = rt_196;
        }
    }
    alg_raise(alg_string("A built-in has no named parameters."));
    Value ret_176 = alg_nil();
    alg_root_top = rt_base;
    return ret_176;
}

static Value m_interpreter_visitcall_1_callexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CallExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_callee = alg_nil();
    (void)v_callee;
    alg_root(&v_callee, 1);
    Value v_arguments = alg_nil();
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    (void)(alg_set_property(v_this, "MemberIsCallee", alg_is(alg_property(v_theexpr, "Callee"), "GetExpr")));
    (void)((v_callee = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Callee")}, 1)));
    (void)(alg_set_property(v_this, "MemberIsCallee", alg_bool(false)));
    (void)((v_arguments = alg_list()));
    {
        int32_t rt_198 = alg_root_top;
        Value loop_177 = alg_iterable(alg_property(v_theexpr, "Arguments"));
        (void)loop_177;
        alg_root(&loop_177, 1);
        for (int32_t at_177 = 0; at_177 < alg_iterable_count(loop_177); at_177++) {
            int32_t rt_199 = alg_root_top;
            Value v_argument = alg_iterable_at(loop_177, at_177);
            (void)v_argument;
            alg_root(&v_argument, 1);
            {
                (void)(alg_invoke(v_arguments, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){v_argument}, 1)}, 1));
            }
            alg_root_top = rt_199;
        }
        alg_root_top = rt_198;
    }
    Value v_names = alg_property(v_theexpr, "ArgumentNames");
    (void)v_names;
    alg_root(&v_names, 1);
    if (alg_truthy(alg_is(v_callee, "ObjExtension"))) {
        {
            int32_t rt_200 = alg_root_top;
            (void)(alg_invoke(v_arguments, "Insert", (Value[]){alg_int(0), alg_property(v_callee, "Receiver")}, 2));
            Value v_padded = alg_list();
            (void)v_padded;
            alg_root(&v_padded, 1);
            (void)(alg_invoke(v_padded, "Add", (Value[]){alg_string("")}, 1));
            {
                int32_t rt_201 = alg_root_top;
                Value loop_178 = alg_iterable(v_names);
                (void)loop_178;
                alg_root(&loop_178, 1);
                for (int32_t at_178 = 0; at_178 < alg_iterable_count(loop_178); at_178++) {
                    int32_t rt_202 = alg_root_top;
                    Value v_each = alg_iterable_at(loop_178, at_178);
                    (void)v_each;
                    alg_root(&v_each, 1);
                    (void)(alg_invoke(v_padded, "Add", (Value[]){v_each}, 1));
                    alg_root_top = rt_202;
                }
                alg_root_top = rt_201;
            }
            (void)((v_names = v_padded));
            (void)((v_callee = alg_property(v_callee, "Target")));
            alg_root_top = rt_200;
        }
    }
    (void)((v_arguments = alg_invoke(v_this, "Arranged", (Value[]){v_callee, v_arguments, v_names}, 3)));
    if (alg_truthy(alg_not(alg_invoke(v_this, "IsCallable", (Value[]){v_callee}, 1)))) {
        {
            alg_raise(alg_string("Can only call functions and classes."));
        }
    }
    if (alg_truthy(alg_is(v_callee, "ObjFunction"))) {
        {
            if (alg_truthy(alg_not_equal(alg_property(v_callee, "Owner"), alg_nil()))) {
                {
                    int32_t rt_203 = alg_root_top;
                    Value v_better = alg_invoke(alg_property(v_callee, "Owner"), "FindOverload", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_property(v_callee, "Declaration"), "Name"), "Lexeme")}, 1), v_arguments}, 2);
                    (void)v_better;
                    alg_root(&v_better, 1);
                    if (alg_truthy(alg_equal(v_better, alg_nil()))) {
                        alg_raise(alg_string("No matching signature for function."));
                    }
                    (void)((v_callee = alg_invoke(v_better, "Bind", (Value[]){alg_property(v_callee, "Bound")}, 1)));
                    alg_root_top = rt_203;
                }
            } else {
                if (alg_truthy((or_33 = alg_not(alg_invoke(v_callee, "Fits", (Value[]){v_arguments, alg_bool(true)}, 2)), !alg_truthy(or_33) ? or_33 : alg_not(alg_invoke(v_callee, "Absorbs", (Value[]){v_arguments}, 1))))) {
                    {
                        if (alg_truthy((or_34 = alg_not(alg_invoke(v_callee, "Variadic", NULL, 0)), !alg_truthy(or_34) ? or_34 : alg_not_equal(alg_property(v_arguments, "Length"), alg_invoke(v_callee, "Arity", NULL, 0))))) {
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
    alg_root(&v_gathering, 1);
    if (alg_truthy((or_35 = alg_is(v_callee, "ObjFunction"), alg_truthy(or_35) ? or_35 : alg_is(v_callee, "ObjClass")))) {
        (void)((v_gathering = alg_invoke(v_callee, "Absorbs", (Value[]){v_arguments}, 1)));
    }
    Value v_absorbing = alg_bool(false);
    (void)v_absorbing;
    alg_root(&v_absorbing, 1);
    if (alg_truthy((or_36 = alg_is(v_callee, "ObjFunction"), alg_truthy(or_36) ? or_36 : alg_is(v_callee, "ObjClass")))) {
        (void)((v_absorbing = alg_invoke(v_callee, "Variadic", NULL, 0)));
    }
    if (alg_truthy((or_39 = (or_38 = (or_37 = alg_not(v_gathering), !alg_truthy(or_37) ? or_37 : alg_not(v_absorbing)), !alg_truthy(or_38) ? or_38 : alg_greater_equal(alg_invoke(v_callee, "Arity", NULL, 0), alg_int(0))), !alg_truthy(or_39) ? or_39 : alg_not_equal(alg_property(v_arguments, "Length"), alg_invoke(v_callee, "Arity", NULL, 0))))) {
        {
            alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Expected "), alg_invoke(v_callee, "Arity", NULL, 0)), alg_string(" arguments but got ")), alg_property(v_arguments, "Length")), alg_char_value(46)));
        }
    }
    Value ret_179 = alg_invoke(v_callee, "Call", (Value[]){v_this, v_arguments}, 2);
    alg_root_top = rt_base;
    return ret_179;
    Value ret_180 = alg_nil();
    alg_root_top = rt_base;
    return ret_180;
}

static Value m_interpreter_assignqualified_3_string_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_unit = alg_widen(args[0], "String");
    (void)v_unit;
    alg_root(&v_unit, 1);
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_value = args[2];
    (void)v_value;
    alg_root(&v_value, 1);
    Value v_moduleenv = alg_nil();
    (void)v_moduleenv;
    alg_root(&v_moduleenv, 1);
    if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){v_unit}, 1), alg_string("system")))) {
        alg_raise(alg_add(alg_add(alg_string("Can't assign to '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' in unit 'System'.")));
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "UnitsByName"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_unit}, 1)}, 1)))) {
        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' in unit '")), v_unit), alg_string("'.")));
    }
    (void)((v_moduleenv = alg_cast(alg_invoke(alg_property(v_this, "UnitsByName"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_unit}, 1)}, 1), "Environment")));
    if (alg_truthy((or_40 = alg_equal(alg_property(v_moduleenv, "Exports"), alg_nil()), alg_truthy(or_40) ? or_40 : alg_not(alg_invoke(alg_property(v_moduleenv, "Exports"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))))) {
        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' in unit '")), v_unit), alg_string("'.")));
    }
    (void)(alg_invoke(alg_property(v_moduleenv, "Values"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_value}, 2));
    Value ret_181 = alg_nil();
    alg_root_top = rt_base;
    return ret_181;
}

static Value m_interpreter_qualified_2_string_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_unit = alg_widen(args[0], "String");
    (void)v_unit;
    alg_root(&v_unit, 1);
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_moduleenv = alg_nil();
    (void)v_moduleenv;
    alg_root(&v_moduleenv, 1);
    if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){v_unit}, 1), alg_string("system")))) {
        {
            if (alg_truthy(alg_not(alg_invoke(alg_property(alg_property(v_this, "Builtins"), "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1)))) {
                alg_raise(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' in unit 'System'.")));
            }
            Value ret_182 = alg_invoke(alg_property(alg_property(v_this, "Builtins"), "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1);
            alg_root_top = rt_base;
            return ret_182;
        }
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "UnitsByName"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_unit}, 1)}, 1)))) {
        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' in unit '")), v_unit), alg_string("'.")));
    }
    (void)((v_moduleenv = alg_cast(alg_invoke(alg_property(v_this, "UnitsByName"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_unit}, 1)}, 1), "Environment")));
    if (alg_truthy((or_41 = alg_equal(alg_property(v_moduleenv, "Exports"), alg_nil()), alg_truthy(or_41) ? or_41 : alg_not(alg_invoke(alg_property(v_moduleenv, "Exports"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))))) {
        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' in unit '")), v_unit), alg_string("'.")));
    }
    Value ret_183 = alg_invoke(alg_property(v_moduleenv, "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1);
    alg_root_top = rt_base;
    return ret_183;
    Value ret_184 = alg_nil();
    alg_root_top = rt_base;
    return ret_184;
}

static Value m_interpreter_responds_2_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    volatile Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    volatile Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    (void)((v_folded = f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)));
    if (alg_truthy(alg_is(v_obj, "String"))) {
        volatile Value ret_185 = alg_equal(v_folded, alg_string("length"));
        alg_root_top = rt_base;
        return ret_185;
    }
    if (alg_truthy((or_42 = alg_is(v_obj, "Integer"), alg_truthy(or_42) ? or_42 : alg_is(v_obj, "Double")))) {
        volatile Value ret_186 = alg_equal(v_folded, alg_string("tostring"));
        alg_root_top = rt_base;
        return ret_186;
    }
    if (alg_truthy(alg_is(v_obj, "ObjInstance"))) {
        volatile Value ret_187 = (or_44 = (or_43 = alg_equal(v_folded, alg_string("classname")), alg_truthy(or_43) ? or_43 : alg_invoke(alg_property(v_obj, "Klass"), "DeclaresField", (Value[]){v_folded}, 1)), alg_truthy(or_44) ? or_44 : alg_not_equal(alg_invoke(alg_property(v_obj, "Klass"), "FindMethod", (Value[]){v_folded}, 1), alg_nil()));
        alg_root_top = rt_base;
        return ret_187;
    }
    if (alg_truthy(alg_not(((or_48 = (or_47 = (or_46 = (or_45 = alg_is(v_obj, "ObjEnumType"), alg_truthy(or_45) ? or_45 : alg_is(v_obj, "ObjEnum")), alg_truthy(or_46) ? or_46 : alg_is(v_obj, "ObjCollection")), alg_truthy(or_47) ? or_47 : alg_is(v_obj, "ObjFile")), alg_truthy(or_48) ? or_48 : alg_is(v_obj, "ObjBuffer")))))) {
        volatile Value ret_188 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_188;
    }
    {
        AlgFrame frame_189;
        alg_push_frame(&frame_189);
        if (ALG_SETJMP(frame_189.jump) == 0) {
            {
                (void)(alg_invoke(v_obj, "Get", (Value[]){v_name}, 1));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_189[] = {"String"};
            int32_t which_189 = alg_handler(frame_189.raised, names_189, 1);
            if (which_189 == 0) {
                {
                    int32_t rt_204 = alg_root_top;
                    volatile Value v_e = frame_189.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_190 = alg_bool(false);
                    alg_root_top = rt_base;
                    return ret_190;
                    alg_root_top = rt_204;
                }
            }
            else {
                alg_raise(frame_189.raised);
            }
        }
    }
    volatile Value ret_191 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_191;
    volatile Value ret_192 = alg_nil();
    alg_root_top = rt_base;
    return ret_192;
}

static Value m_interpreter_extensionnamed_1_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "ExtensionUnit"), alg_string("")))) {
        Value ret_193 = alg_invoke(v_this, "Qualified", (Value[]){alg_str(alg_property(v_theexpr, "ExtensionUnit")), alg_property(v_theexpr, "Name")}, 2);
        alg_root_top = rt_base;
        return ret_193;
    }
    Value ret_194 = alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_property(v_theexpr, "Name")}, 1);
    alg_root_top = rt_base;
    return ret_194;
    Value ret_195 = alg_nil();
    alg_root_top = rt_base;
    return ret_195;
}

static Value m_interpreter_visitgetexpr_1_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_obj = alg_nil();
    (void)v_obj;
    alg_root(&v_obj, 1);
    Value v_ascallee = alg_property(v_this, "MemberIsCallee");
    (void)v_ascallee;
    alg_root(&v_ascallee, 1);
    (void)(alg_set_property(v_this, "MemberIsCallee", alg_bool(false)));
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Unit"), alg_string("")))) {
        Value ret_196 = alg_invoke(v_this, "Qualified", (Value[]){alg_property(v_theexpr, "Unit"), alg_property(v_theexpr, "Name")}, 2);
        alg_root_top = rt_base;
        return ret_196;
    }
    (void)((v_obj = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)));
    if (alg_truthy((or_49 = alg_not_equal(alg_property(v_theexpr, "Extension"), alg_string("")), !alg_truthy(or_49) ? or_49 : alg_not(alg_invoke(v_this, "Responds", (Value[]){v_obj, alg_property(v_theexpr, "Name")}, 2))))) {
        Value ret_197 = alg_new(k_objextension, (Value[]){v_obj, alg_invoke(v_this, "ExtensionNamed", (Value[]){v_theexpr}, 1)}, 2);
        alg_root_top = rt_base;
        return ret_197;
    }
    if (alg_truthy(alg_is(v_obj, "String"))) {
        {
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1), alg_string("length")))) {
                Value ret_198 = alg_text_length(v_obj);
                alg_root_top = rt_base;
                return ret_198;
            }
            alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))), alg_string("'.")));
        }
    }
    if (alg_truthy((or_50 = alg_is(v_obj, "Integer"), alg_truthy(or_50) ? or_50 : alg_is(v_obj, "Double")))) {
        {
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1), alg_string("tostring")))) {
                Value ret_199 = alg_new(k_numbermethod, (Value[]){v_obj, alg_property(v_theexpr, "Name")}, 2);
                alg_root_top = rt_base;
                return ret_199;
            }
            alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))), alg_string("'.")));
        }
    }
    if (alg_truthy(alg_not(((or_55 = (or_54 = (or_53 = (or_52 = (or_51 = alg_is(v_obj, "ObjInstance"), alg_truthy(or_51) ? or_51 : alg_is(v_obj, "ObjEnumType")), alg_truthy(or_52) ? or_52 : alg_is(v_obj, "ObjEnum")), alg_truthy(or_53) ? or_53 : alg_is(v_obj, "ObjCollection")), alg_truthy(or_54) ? or_54 : alg_is(v_obj, "ObjFile")), alg_truthy(or_55) ? or_55 : alg_is(v_obj, "ObjBuffer")))))) {
        {
            alg_raise(alg_string("Only instances have properties."));
        }
    }
    if (alg_truthy(alg_is(v_obj, "ObjInstance"))) {
        {
            int32_t rt_205 = alg_root_top;
            if (alg_truthy(v_ascallee)) {
                {
                    int32_t rt_206 = alg_root_top;
                    Value v_called = alg_invoke(alg_property(v_obj, "Klass"), "FindMethod", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1)}, 1);
                    (void)v_called;
                    alg_root(&v_called, 1);
                    if (alg_truthy(alg_not_equal(v_called, alg_nil()))) {
                        Value ret_200 = alg_invoke(v_called, "Bind", (Value[]){v_obj}, 1);
                        alg_root_top = rt_base;
                        return ret_200;
                    }
                    alg_root_top = rt_206;
                }
            }
            Value v_member = alg_invoke(alg_property(v_obj, "Klass"), "MethodOfArity", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1), alg_int(0)}, 2);
            (void)v_member;
            alg_root(&v_member, 1);
            if (alg_truthy((or_57 = (or_56 = alg_not_equal(v_member, alg_nil()), !alg_truthy(or_56) ? or_56 : alg_property(alg_property(v_member, "Declaration"), "IsProperty")), !alg_truthy(or_57) ? or_57 : alg_not(alg_invoke(alg_property(v_obj, "Fields"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1)}, 1))))) {
                Value ret_201 = alg_invoke(alg_invoke(v_member, "Bind", (Value[]){v_obj}, 1), "Call", (Value[]){v_this, alg_list()}, 2);
                alg_root_top = rt_base;
                return ret_201;
            }
            alg_root_top = rt_205;
        }
    }
    Value ret_202 = alg_invoke(v_obj, "Get", (Value[]){alg_property(v_theexpr, "Name")}, 1);
    alg_root_top = rt_base;
    return ret_202;
    Value ret_203 = alg_nil();
    alg_root_top = rt_base;
    return ret_203;
}

static Value m_interpreter_visitsetexpr_1_setexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_obj = alg_nil();
    (void)v_obj;
    alg_root(&v_obj, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Unit"), alg_string("")))) {
        {
            (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1)));
            (void)(alg_invoke(v_this, "AssignQualified", (Value[]){alg_str(alg_property(v_theexpr, "Unit")), alg_property(v_theexpr, "Name"), v_value}, 3));
            Value ret_204 = v_value;
            alg_root_top = rt_base;
            return ret_204;
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
    Value ret_205 = v_value;
    alg_root_top = rt_base;
    return ret_205;
    Value ret_206 = alg_nil();
    alg_root_top = rt_base;
    return ret_206;
}

static Value m_interpreter_visitsuperexpr_1_superexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SuperExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_distance = alg_nil();
    (void)v_distance;
    alg_root(&v_distance, 1);
    Value v_superclass = alg_nil();
    (void)v_superclass;
    alg_root(&v_superclass, 1);
    Value v_obj = alg_nil();
    (void)v_obj;
    alg_root(&v_obj, 1);
    Value v_method = alg_nil();
    (void)v_method;
    alg_root(&v_method, 1);
    (void)((v_distance = alg_cast(alg_invoke(alg_property(v_this, "Locals"), "Get", (Value[]){v_theexpr}, 1), "Integer")));
    (void)((v_superclass = alg_cast(alg_invoke(alg_property(v_this, "Env"), "GetAt", (Value[]){v_distance, alg_string("super")}, 2), "ObjClass")));
    (void)((v_obj = alg_cast(alg_invoke(alg_property(v_this, "Env"), "GetAt", (Value[]){alg_subtract(v_distance, alg_int(1)), alg_string("this")}, 2), "ObjInstance")));
    (void)((v_method = alg_invoke(v_superclass, "FindMethod", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_theexpr, "Method"), "Lexeme")}, 1)}, 1)));
    Value ret_207 = alg_invoke(v_method, "Bind", (Value[]){v_obj}, 1);
    alg_root_top = rt_base;
    return ret_207;
    Value ret_208 = alg_nil();
    alg_root_top = rt_base;
    return ret_208;
}

static Value m_interpreter_visitthisexpr_1_thisexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "ThisExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value ret_209 = alg_invoke(v_this, "LookupVariable", (Value[]){alg_property(v_theexpr, "Keyword"), v_theexpr}, 2);
    alg_root_top = rt_base;
    return ret_209;
    Value ret_210 = alg_nil();
    alg_root_top = rt_base;
    return ret_210;
}

static Value m_interpreter_classnameof_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    {
        AlgFrame frame_211;
        alg_push_frame(&frame_211);
        if (ALG_SETJMP(frame_211.jump) == 0) {
            {
                volatile Value ret_212 = alg_property(v_obj, "ClassName");
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_212;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_211[] = {"String"};
            int32_t which_211 = alg_handler(frame_211.raised, names_211, 1);
            if (which_211 == 0) {
                {
                    int32_t rt_207 = alg_root_top;
                    volatile Value v_e = frame_211.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_213 = alg_string("");
                    alg_root_top = rt_base;
                    return ret_213;
                    alg_root_top = rt_207;
                }
            }
            else {
                alg_raise(frame_211.raised);
            }
        }
    }
    volatile Value ret_214 = alg_nil();
    alg_root_top = rt_base;
    return ret_214;
}

static Value m_interpreter_istruthy_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    if (alg_truthy((or_58 = alg_equal(v_obj, alg_nil()), alg_truthy(or_58) ? or_58 : alg_equal(v_obj, alg_bool(false))))) {
        Value ret_215 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_215;
    }
    if (alg_truthy(alg_is(v_obj, "Integer"))) {
        Value ret_216 = alg_not_equal(v_obj, alg_int(0));
        alg_root_top = rt_base;
        return ret_216;
    }
    if (alg_truthy(alg_is(v_obj, "ObjEnum"))) {
        Value ret_217 = alg_not_equal(alg_property(v_obj, "Ordinal"), alg_int(0));
        alg_root_top = rt_base;
        return ret_217;
    }
    Value ret_218 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_218;
    Value ret_219 = alg_nil();
    alg_root_top = rt_base;
    return ret_219;
}

static Value m_interpreter_isequal_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_a = args[0];
    (void)v_a;
    alg_root(&v_a, 1);
    Value v_b = args[1];
    (void)v_b;
    alg_root(&v_b, 1);
    if (alg_truthy((or_59 = alg_equal(v_a, alg_nil()), !alg_truthy(or_59) ? or_59 : alg_equal(v_b, alg_nil())))) {
        Value ret_220 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_220;
    }
    if (alg_truthy(alg_equal(v_a, alg_nil()))) {
        Value ret_221 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_221;
    }
    Value ret_222 = alg_equal(v_a, v_b);
    alg_root_top = rt_base;
    return ret_222;
    Value ret_223 = alg_nil();
    alg_root_top = rt_base;
    return ret_223;
}

static Value m_interpreter_widen_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    Value v_declared = alg_widen(args[1], "String");
    (void)v_declared;
    alg_root(&v_declared, 1);
    if (alg_truthy((or_60 = alg_equal(v_declared, alg_string("")), alg_truthy(or_60) ? or_60 : alg_equal(v_value, alg_nil())))) {
        Value ret_224 = v_value;
        alg_root_top = rt_base;
        return ret_224;
    }
    if (alg_truthy(f_issubrange(NULL, (Value[]){v_declared}, 1))) {
        {
            if (alg_truthy(alg_not(alg_invoke(v_this, "InSubrange", (Value[]){v_value, v_declared}, 2)))) {
                alg_raise(alg_add(alg_add(alg_add(alg_str(v_value), alg_string(" is not in ")), v_declared), alg_char_value(46)));
            }
            Value ret_225 = v_value;
            alg_root_top = rt_base;
            return ret_225;
        }
    }
    if (alg_truthy((or_61 = alg_equal(v_declared, alg_string("Double")), !alg_truthy(or_61) ? or_61 : alg_is(v_value, "Integer")))) {
        Value ret_226 = alg_multiply(v_value, alg_double(1.0));
        alg_root_top = rt_base;
        return ret_226;
    }
    if (alg_truthy((or_62 = alg_equal(v_declared, alg_string("String")), !alg_truthy(or_62) ? or_62 : alg_is(v_value, "Char")))) {
        Value ret_227 = alg_str(v_value);
        alg_root_top = rt_base;
        return ret_227;
    }
    Value ret_228 = v_value;
    alg_root_top = rt_base;
    return ret_228;
    Value ret_229 = alg_nil();
    alg_root_top = rt_base;
    return ret_229;
}

static Value m_interpreter_evaluate_1_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "Expr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    (void)((v_value = alg_invoke(v_theexpr, "Accept", (Value[]){v_this}, 1)));
    if (alg_truthy((or_63 = alg_not_equal(alg_property(v_theexpr, "Cast"), alg_string("")), !alg_truthy(or_63) ? or_63 : alg_not_equal(v_value, alg_nil())))) {
        {
            if (alg_truthy(alg_not(alg_invoke(v_this, "SatisfiesType", (Value[]){v_value, alg_property(v_theexpr, "Cast")}, 2)))) {
                alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("Cannot cast "), f_typenameof(NULL, (Value[]){v_value}, 1)), alg_string(" to ")), alg_property(v_theexpr, "Cast")), alg_char_value(46)));
            }
        }
    }
    Value ret_230 = v_value;
    alg_root_top = rt_base;
    return ret_230;
    Value ret_231 = alg_nil();
    alg_root_top = rt_base;
    return ret_231;
}

static Value m_interpreter_execute_1_stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "Stmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    (void)(alg_invoke(v_thestmt, "Accept", (Value[]){v_this}, 1));
    Value ret_232 = alg_nil();
    alg_root_top = rt_base;
    return ret_232;
}

static Value m_interpreter_resolve_2_expr_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "Expr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_depth = alg_widen(args[1], "Integer");
    (void)v_depth;
    alg_root(&v_depth, 1);
    (void)(alg_invoke(alg_property(v_this, "Locals"), "Put", (Value[]){v_theexpr, v_depth}, 2));
    Value ret_233 = alg_nil();
    alg_root_top = rt_base;
    return ret_233;
}

static Value m_interpreter_executeblock_2_list_environment(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    volatile Value v_newenv = alg_widen(args[1], "Environment");
    (void)v_newenv;
    alg_root(&v_newenv, 1);
    volatile Value v_previousenv = alg_nil();
    (void)v_previousenv;
    alg_root(&v_previousenv, 1);
    (void)((v_previousenv = alg_cast(alg_property(v_this, "Env"), "Environment")));
    {
        AlgFrame frame_234;
        alg_push_frame(&frame_234);
        if (ALG_SETJMP(frame_234.jump) == 0) {
            {
                int32_t rt_208 = alg_root_top;
                (void)(alg_set_property(v_this, "Env", v_newenv));
                volatile Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                while (alg_truthy(alg_less(v_i, alg_property(v_statements, "Length")))) {
                    {
                        {
                            AlgFrame frame_235;
                            alg_push_frame(&frame_235);
                            if (ALG_SETJMP(frame_235.jump) == 0) {
                                {
                                    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_subscript_get(v_statements, v_i)}, 1));
                                    (void)((v_i = alg_add(v_i, alg_int(1))));
                                }
                                alg_pop_frame();
                            }
                            else {
                                static const char *names_235[] = {"Jumped"};
                                int32_t which_235 = alg_handler(frame_235.raised, names_235, 1);
                                if (which_235 == 0) {
                                    {
                                        int32_t rt_209 = alg_root_top;
                                        volatile Value v_g = frame_235.raised;
                                        (void)v_g;
                                        alg_root(&v_g, 1);
                                        {
                                            int32_t rt_210 = alg_root_top;
                                            volatile Value v_at = f_labelat(NULL, (Value[]){v_statements, alg_property(v_g, "Label")}, 2);
                                            (void)v_at;
                                            alg_root(&v_at, 1);
                                            if (alg_truthy(alg_less(v_at, alg_int(0)))) {
                                                alg_raise(v_g);
                                            }
                                            (void)((v_i = v_at));
                                            alg_root_top = rt_210;
                                        }
                                        alg_root_top = rt_209;
                                    }
                                }
                                else {
                                    alg_raise(frame_235.raised);
                                }
                            }
                        }
                    }
                }
                alg_root_top = rt_208;
            }
            alg_pop_frame();
        }
        else {
            {
                int32_t rt_211 = alg_root_top;
                volatile Value v_e = frame_234.raised;
                (void)v_e;
                alg_root(&v_e, 1);
                {
                    (void)(alg_set_property(v_this, "Env", v_previousenv));
                    alg_raise(v_e);
                }
                alg_root_top = rt_211;
            }
        }
    }
    (void)(alg_set_property(v_this, "Env", v_previousenv));
    volatile Value ret_236 = alg_nil();
    alg_root_top = rt_base;
    return ret_236;
}

static Value m_interpreter_visitblockstmt_1_blockstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "BlockStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_newenv = alg_new(k_environment, NULL, 0);
    (void)v_newenv;
    alg_root(&v_newenv, 1);
    (void)(alg_set_property(v_newenv, "Enclosing", alg_property(v_this, "Env")));
    (void)(alg_invoke(v_this, "ExecuteBlock", (Value[]){alg_property(v_thestmt, "Statements"), v_newenv}, 2));
    Value ret_237 = alg_nil();
    alg_root_top = rt_base;
    return ret_237;
}

static Value m_interpreter_visitclassstmt_1_classstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ClassStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_klass = alg_nil();
    (void)v_klass;
    alg_root(&v_klass, 1);
    Value v_superclass = alg_nil();
    (void)v_superclass;
    alg_root(&v_superclass, 1);
    Value v_methods = alg_nil();
    (void)v_methods;
    alg_root(&v_methods, 1);
    Value v_thefunction = alg_nil();
    (void)v_thefunction;
    alg_root(&v_thefunction, 1);
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
    alg_root(&v_shell, 1);
    if (alg_truthy(alg_equal(v_shell, alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_nil()}, 2));
    }
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Superclass"), alg_nil()))) {
        {
            int32_t rt_212 = alg_root_top;
            Value v_previous = alg_property(v_this, "Env");
            (void)v_previous;
            alg_root(&v_previous, 1);
            (void)(alg_set_property(v_this, "Env", alg_new(k_environment, NULL, 0)));
            (void)(alg_set_property(alg_property(v_this, "Env"), "Enclosing", v_previous));
            (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_string("super"), v_superclass}, 2));
            alg_root_top = rt_212;
        }
    }
    (void)((v_methods = alg_map()));
    {
        int32_t rt_213 = alg_root_top;
        Value loop_238 = alg_iterable(alg_property(v_thestmt, "Methods"));
        (void)loop_238;
        alg_root(&loop_238, 1);
        for (int32_t at_238 = 0; at_238 < alg_iterable_count(loop_238); at_238++) {
            int32_t rt_214 = alg_root_top;
            Value v_method = alg_iterable_at(loop_238, at_238);
            (void)v_method;
            alg_root(&v_method, 1);
            {
                int32_t rt_215 = alg_root_top;
                (void)((v_thefunction = alg_new(k_objfunction, (Value[]){v_method, alg_property(v_this, "Env"), alg_equal(f_foldcase(NULL, (Value[]){alg_property(alg_property(v_method, "Name"), "Lexeme")}, 1), alg_string("init"))}, 3)));
                Value v_methodkey = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_method, "Name"), "Lexeme")}, 1);
                (void)v_methodkey;
                alg_root(&v_methodkey, 1);
                if (alg_truthy(alg_not(alg_invoke(v_methods, "Contains", (Value[]){v_methodkey}, 1)))) {
                    (void)(alg_invoke(v_methods, "Put", (Value[]){v_methodkey, alg_list()}, 2));
                }
                (void)(alg_invoke(alg_invoke(v_methods, "Get", (Value[]){v_methodkey}, 1), "Add", (Value[]){v_thefunction}, 1));
                alg_root_top = rt_215;
            }
            alg_root_top = rt_214;
        }
        alg_root_top = rt_213;
    }
    if (alg_truthy(alg_not_equal(v_shell, alg_nil()))) {
        {
            (void)((v_klass = alg_cast(v_shell, "ObjClass")));
            (void)(alg_set_property(v_klass, "Superclass", alg_cast(v_superclass, "ObjClass")));
            (void)(alg_set_property(v_klass, "Methods", v_methods));
            (void)(alg_set_property(v_klass, "Fields", alg_property(v_thestmt, "Fields")));
        }
    } else {
        (void)((v_klass = alg_new(k_objclass, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_superclass, v_methods, alg_property(v_thestmt, "Fields")}, 4)));
    }
    {
        int32_t rt_216 = alg_root_top;
        Value loop_239 = alg_iterable(alg_invoke(v_methods, "Keys", NULL, 0));
        (void)loop_239;
        alg_root(&loop_239, 1);
        for (int32_t at_239 = 0; at_239 < alg_iterable_count(loop_239); at_239++) {
            int32_t rt_217 = alg_root_top;
            Value v_name = alg_iterable_at(loop_239, at_239);
            (void)v_name;
            alg_root(&v_name, 1);
            {
                int32_t rt_218 = alg_root_top;
                Value loop_240 = alg_iterable(alg_invoke(v_methods, "Get", (Value[]){v_name}, 1));
                (void)loop_240;
                alg_root(&loop_240, 1);
                for (int32_t at_240 = 0; at_240 < alg_iterable_count(loop_240); at_240++) {
                    int32_t rt_219 = alg_root_top;
                    Value v_each = alg_iterable_at(loop_240, at_240);
                    (void)v_each;
                    alg_root(&v_each, 1);
                    (void)(alg_set_property(v_each, "Owner", v_klass));
                    alg_root_top = rt_219;
                }
                alg_root_top = rt_218;
            }
            alg_root_top = rt_217;
        }
        alg_root_top = rt_216;
    }
    if (alg_truthy(alg_not_equal(v_superclass, alg_nil()))) {
        {
            (void)(alg_set_property(v_this, "Env", alg_property(alg_property(v_this, "Env"), "Enclosing")));
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Assign", (Value[]){alg_property(v_thestmt, "Name"), v_klass}, 2));
    Value ret_241 = alg_nil();
    alg_root_top = rt_base;
    return ret_241;
}

static Value m_interpreter_visitobjectstmt_1_objectstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ObjectStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_klass = alg_nil();
    (void)v_klass;
    alg_root(&v_klass, 1);
    Value v_hasid = alg_bool(false);
    (void)v_hasid;
    alg_root(&v_hasid, 1);
    {
        int32_t rt_220 = alg_root_top;
        Value loop_242 = alg_iterable(alg_property(v_thestmt, "Fields"));
        (void)loop_242;
        alg_root(&loop_242, 1);
        for (int32_t at_242 = 0; at_242 < alg_iterable_count(loop_242); at_242++) {
            int32_t rt_221 = alg_root_top;
            Value v_field = alg_iterable_at(loop_242, at_242);
            (void)v_field;
            alg_root(&v_field, 1);
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(alg_property(v_field, "Name"), "Lexeme")}, 1), alg_string("id")))) {
                (void)((v_hasid = alg_bool(true)));
            }
            alg_root_top = rt_221;
        }
        alg_root_top = rt_220;
    }
    if (alg_truthy(alg_not(v_hasid))) {
        {
            int32_t rt_222 = alg_root_top;
            Value v_idname = alg_new(k_token, (Value[]){e_tokentype_tokenVidentifier, alg_string("Id"), alg_nil(), alg_property(alg_property(v_thestmt, "Name"), "LineNumber")}, 4);
            (void)v_idname;
            alg_root(&v_idname, 1);
            (void)(alg_invoke(alg_property(v_thestmt, "Fields"), "Add", (Value[]){alg_new(k_varstmt, (Value[]){v_idname, alg_new(k_literalexpr, (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)}, 2)}, 1));
            alg_root_top = rt_222;
        }
    }
    (void)(alg_invoke(v_this, "VisitClassStmt", (Value[]){alg_new(k_classstmt, (Value[]){alg_property(v_thestmt, "Name"), alg_property(v_thestmt, "Superclass"), alg_property(v_thestmt, "Methods"), alg_property(v_thestmt, "Fields")}, 4)}, 1));
    (void)((v_klass = alg_cast(alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_property(v_thestmt, "Name")}, 1), "ObjClass")));
    (void)(alg_invoke(alg_property(v_this, "Env"), "Assign", (Value[]){alg_property(v_thestmt, "Name"), alg_new(k_objsingleton, (Value[]){v_klass, v_this}, 2)}, 2));
    Value ret_243 = alg_nil();
    alg_root_top = rt_base;
    return ret_243;
}

static Value m_interpreter_visitsubrangestmt_1_subrangestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "SubrangeStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value ret_244 = alg_nil();
    alg_root_top = rt_base;
    return ret_244;
}

static Value m_interpreter_visitenumstmt_1_enumstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "EnumStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_thetype = alg_nil();
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    (void)((v_thetype = alg_new(k_objenumtype, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)));
    {
        int32_t rt_223 = alg_root_top;
        Value loop_245 = alg_iterable(alg_property(v_thestmt, "Members"));
        (void)loop_245;
        alg_root(&loop_245, 1);
        for (int32_t at_245 = 0; at_245 < alg_iterable_count(loop_245); at_245++) {
            int32_t rt_224 = alg_root_top;
            Value v_themember = alg_iterable_at(loop_245, at_245);
            (void)v_themember;
            alg_root(&v_themember, 1);
            {
                int32_t rt_225 = alg_root_top;
                Value v_membername = alg_str(alg_property(v_themember, "Lexeme"));
                (void)v_membername;
                alg_root(&v_membername, 1);
                Value v_member = alg_invoke(v_thetype, "Add", (Value[]){v_membername}, 1);
                (void)v_member;
                alg_root(&v_member, 1);
                Value v_clash = alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_membername}, 1)}, 1);
                (void)v_clash;
                alg_root(&v_clash, 1);
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
                alg_root_top = rt_225;
            }
            alg_root_top = rt_224;
        }
        alg_root_top = rt_223;
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_thetype}, 2));
    Value ret_246 = alg_nil();
    alg_root_top = rt_base;
    return ret_246;
}

static Value m_interpreter_visitexpressionstmt_1_expressionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "ExpressionStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    (void)(alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_stmt, "Expression")}, 1));
    Value ret_247 = alg_nil();
    alg_root_top = rt_base;
    return ret_247;
}

static Value m_interpreter_visitfunctionstmt_1_functionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "FunctionStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_thefunction = alg_nil();
    (void)v_thefunction;
    alg_root(&v_thefunction, 1);
    (void)((v_thefunction = alg_new(k_objfunction, (Value[]){v_thestmt, alg_property(v_this, "Env"), alg_bool(false)}, 3)));
    Value v_key = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1);
    (void)v_key;
    alg_root(&v_key, 1);
    if (alg_truthy((or_64 = alg_not(alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Contains", (Value[]){v_key}, 1)), !alg_truthy(or_64) ? or_64 : alg_invoke(alg_property(alg_property(v_this, "Builtins"), "Values"), "Contains", (Value[]){v_key}, 1)))) {
        {
            int32_t rt_226 = alg_root_top;
            Value v_shadowing = alg_new(k_objoverloads, (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1);
            (void)v_shadowing;
            alg_root(&v_shadowing, 1);
            (void)(alg_invoke(v_shadowing, "Add", (Value[]){v_thefunction}, 1));
            (void)(alg_set_property(v_shadowing, "Fallback", alg_invoke(alg_property(alg_property(v_this, "Builtins"), "Values"), "Get", (Value[]){v_key}, 1)));
            (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_shadowing}, 2));
            Value ret_248 = alg_nil();
            alg_root_top = rt_base;
            return ret_248;
            alg_root_top = rt_226;
        }
    }
    if (alg_truthy(alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Contains", (Value[]){v_key}, 1))) {
        {
            int32_t rt_227 = alg_root_top;
            Value v_existing = alg_invoke(alg_property(alg_property(v_this, "Env"), "Values"), "Get", (Value[]){v_key}, 1);
            (void)v_existing;
            alg_root(&v_existing, 1);
            if (alg_truthy((or_65 = alg_not((alg_is(v_existing, "ObjFunction"))), !alg_truthy(or_65) ? or_65 : alg_not((alg_is(v_existing, "ObjOverloads")))))) {
                alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))), alg_string("' is already defined.")));
            }
            Value v_overloads = v_existing;
            (void)v_overloads;
            alg_root(&v_overloads, 1);
            if (alg_truthy(alg_is(v_existing, "ObjFunction"))) {
                {
                    (void)((v_overloads = alg_new(k_objoverloads, (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)));
                    (void)(alg_invoke(v_overloads, "Add", (Value[]){v_existing}, 1));
                }
            }
            {
                int32_t rt_228 = alg_root_top;
                Value loop_249 = alg_iterable(alg_property(v_overloads, "Candidates"));
                (void)loop_249;
                alg_root(&loop_249, 1);
                for (int32_t at_249 = 0; at_249 < alg_iterable_count(loop_249); at_249++) {
                    int32_t rt_229 = alg_root_top;
                    Value v_candidate = alg_iterable_at(loop_249, at_249);
                    (void)v_candidate;
                    alg_root(&v_candidate, 1);
                    if (alg_truthy(f_samesignature(NULL, (Value[]){alg_property(v_candidate, "Declaration"), v_thestmt}, 2))) {
                        alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))), alg_string("' is already defined.")));
                    }
                    alg_root_top = rt_229;
                }
                alg_root_top = rt_228;
            }
            (void)(alg_invoke(v_overloads, "Add", (Value[]){v_thefunction}, 1));
            (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_overloads}, 2));
            Value ret_250 = alg_nil();
            alg_root_top = rt_base;
            return ret_250;
            alg_root_top = rt_227;
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_thefunction}, 2));
    Value ret_251 = alg_nil();
    alg_root_top = rt_base;
    return ret_251;
}

static Value m_interpreter_visitifstmt_1_ifstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "IfStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    if (alg_truthy(alg_invoke(v_this, "IsTruthy", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_stmt, "Condition")}, 1)}, 1))) {
        (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_stmt, "ThenBranch")}, 1));
    } else {
        if (alg_truthy(alg_not_equal(alg_property(v_stmt, "ElseBranch"), alg_nil()))) {
            (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_stmt, "ElseBranch")}, 1));
        }
    }
    Value ret_252 = alg_nil();
    alg_root_top = rt_base;
    return ret_252;
}

static Value m_interpreter_visitwhilestmt_1_whilestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_stmt = alg_widen(args[0], "WhileStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    {
        AlgFrame frame_253;
        alg_push_frame(&frame_253);
        if (ALG_SETJMP(frame_253.jump) == 0) {
            {
                while (alg_truthy(alg_invoke(v_this, "IsTruthy", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_stmt, "Condition")}, 1)}, 1))) {
                    {
                        {
                            AlgFrame frame_254;
                            alg_push_frame(&frame_254);
                            if (ALG_SETJMP(frame_254.jump) == 0) {
                                {
                                    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_stmt, "Body")}, 1));
                                }
                                alg_pop_frame();
                            }
                            else {
                                static const char *names_254[] = {"Continued"};
                                int32_t which_254 = alg_handler(frame_254.raised, names_254, 1);
                                if (which_254 == 0) {
                                    {
                                        int32_t rt_230 = alg_root_top;
                                        volatile Value v_c = frame_254.raised;
                                        (void)v_c;
                                        alg_root(&v_c, 1);
                                        if (alg_truthy(alg_not(f_names(NULL, (Value[]){alg_property(v_c, "Label"), alg_property(v_stmt, "Label")}, 2)))) {
                                            alg_raise(v_c);
                                        }
                                        alg_root_top = rt_230;
                                    }
                                }
                                else {
                                    alg_raise(frame_254.raised);
                                }
                            }
                        }
                        if (alg_truthy(alg_not_equal(alg_property(v_stmt, "Increment"), alg_nil()))) {
                            (void)(alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_stmt, "Increment")}, 1));
                        }
                    }
                }
            }
            alg_pop_frame();
        }
        else {
            static const char *names_253[] = {"Broke"};
            int32_t which_253 = alg_handler(frame_253.raised, names_253, 1);
            if (which_253 == 0) {
                {
                    int32_t rt_231 = alg_root_top;
                    volatile Value v_e = frame_253.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    if (alg_truthy(alg_not(f_names(NULL, (Value[]){alg_property(v_e, "Label"), alg_property(v_stmt, "Label")}, 2)))) {
                        alg_raise(v_e);
                    }
                    alg_root_top = rt_231;
                }
            }
            else {
                alg_raise(frame_253.raised);
            }
        }
    }
    volatile Value ret_255 = alg_nil();
    alg_root_top = rt_base;
    return ret_255;
}

static Value m_interpreter_contains_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_collection = args[0];
    (void)v_collection;
    alg_root(&v_collection, 1);
    Value v_value = args[1];
    (void)v_value;
    alg_root(&v_value, 1);
    if (alg_truthy(alg_is(v_collection, "ObjCollection"))) {
        Value ret_256 = alg_invoke(v_collection, "Invoke", (Value[]){alg_string("contains"), alg_list_keep(alg_list(), v_value)}, 2);
        alg_root_top = rt_base;
        return ret_256;
    }
    if (alg_truthy(alg_is(v_collection, "ObjEnumType"))) {
        Value ret_257 = alg_invoke(alg_invoke(alg_property(v_collection, "Members"), "Values", NULL, 0), "Contains", (Value[]){v_value}, 1);
        alg_root_top = rt_base;
        return ret_257;
    }
    if (alg_truthy(alg_is(v_collection, "ObjInstance"))) {
        {
            int32_t rt_232 = alg_root_top;
            Value v_method = alg_invoke(alg_property(v_collection, "Klass"), "MethodOfArity", (Value[]){alg_string("contains"), alg_int(1)}, 2);
            (void)v_method;
            alg_root(&v_method, 1);
            if (alg_truthy(alg_not_equal(v_method, alg_nil()))) {
                Value ret_258 = alg_invoke(v_this, "IsTruthy", (Value[]){alg_invoke(alg_invoke(v_method, "Bind", (Value[]){v_collection}, 1), "Call", (Value[]){v_this, alg_list_keep(alg_list(), v_value)}, 2)}, 1);
                alg_root_top = rt_base;
                return ret_258;
            }
            alg_root_top = rt_232;
        }
    }
    if (alg_truthy(alg_invoke(v_this, "IsText", (Value[]){v_collection}, 1))) {
        {
            if (alg_truthy(alg_equal(v_value, alg_nil()))) {
                Value ret_259 = alg_bool(false);
                alg_root_top = rt_base;
                return ret_259;
            }
            Value ret_260 = alg_greater_equal(alg_pos(alg_str(v_collection), alg_str(v_value)), alg_int(0));
            alg_root_top = rt_base;
            return ret_260;
        }
    }
    alg_raise(alg_string("Right operand of 'in' must be a collection or a String."));
    Value ret_261 = alg_nil();
    alg_root_top = rt_base;
    return ret_261;
}

static Value m_interpreter_iscallable_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    if (alg_truthy(alg_equal(v_value, alg_nil()))) {
        volatile Value ret_262 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_262;
    }
    {
        AlgFrame frame_263;
        alg_push_frame(&frame_263);
        if (ALG_SETJMP(frame_263.jump) == 0) {
            {
                int32_t rt_233 = alg_root_top;
                volatile Value v_thearity = alg_property(v_value, "Arity");
                (void)v_thearity;
                alg_root(&v_thearity, 1);
                volatile Value ret_264 = alg_bool(true);
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_264;
                alg_root_top = rt_233;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_263[] = {"String"};
            int32_t which_263 = alg_handler(frame_263.raised, names_263, 1);
            if (which_263 == 0) {
                {
                    int32_t rt_234 = alg_root_top;
                    volatile Value v_e = frame_263.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_265 = alg_bool(false);
                    alg_root_top = rt_base;
                    return ret_265;
                    alg_root_top = rt_234;
                }
            }
            else {
                alg_raise(frame_263.raised);
            }
        }
    }
    volatile Value ret_266 = alg_nil();
    alg_root_top = rt_base;
    return ret_266;
}

static Value m_interpreter_elementsof_2_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_where = alg_widen(args[0], "Token");
    (void)v_where;
    alg_root(&v_where, 1);
    Value v_target = args[1];
    (void)v_target;
    alg_root(&v_target, 1);
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    (void)((v_result = alg_list()));
    if (alg_truthy(alg_is(v_target, "ObjCollection"))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_target, "Kind"), alg_string("Map")))) {
                Value ret_267 = alg_invoke(alg_property(v_target, "Pairs"), "Keys", NULL, 0);
                alg_root_top = rt_base;
                return ret_267;
            }
            {
                int32_t rt_235 = alg_root_top;
                Value loop_268 = alg_iterable(alg_property(v_target, "Items"));
                (void)loop_268;
                alg_root(&loop_268, 1);
                for (int32_t at_268 = 0; at_268 < alg_iterable_count(loop_268); at_268++) {
                    int32_t rt_236 = alg_root_top;
                    Value v_item = alg_iterable_at(loop_268, at_268);
                    (void)v_item;
                    alg_root(&v_item, 1);
                    (void)(alg_invoke(v_result, "Add", (Value[]){v_item}, 1));
                    alg_root_top = rt_236;
                }
                alg_root_top = rt_235;
            }
            Value ret_269 = v_result;
            alg_root_top = rt_base;
            return ret_269;
        }
    }
    if (alg_truthy(alg_is(v_target, "ObjEnumType"))) {
        Value ret_270 = alg_invoke(alg_property(v_target, "Members"), "Values", NULL, 0);
        alg_root_top = rt_base;
        return ret_270;
    }
    if (alg_truthy(alg_is(v_target, "ObjInstance"))) {
        {
            int32_t rt_237 = alg_root_top;
            Value v_elements = alg_invoke(alg_property(v_target, "Klass"), "MethodOfArity", (Value[]){alg_string("elements"), alg_int(0)}, 2);
            (void)v_elements;
            alg_root(&v_elements, 1);
            if (alg_truthy(alg_not_equal(v_elements, alg_nil()))) {
                Value ret_271 = alg_invoke(v_this, "ElementsOf", (Value[]){v_where, alg_invoke(alg_invoke(v_elements, "Bind", (Value[]){v_target}, 1), "Call", (Value[]){v_this, alg_list()}, 2)}, 2);
                alg_root_top = rt_base;
                return ret_271;
            }
            alg_root_top = rt_237;
        }
    }
    if (alg_truthy(alg_invoke(v_this, "IsText", (Value[]){v_target}, 1))) {
        {
            int32_t rt_238 = alg_root_top;
            Value v_text = alg_str(v_target);
            (void)v_text;
            alg_root(&v_text, 1);
            {
                int32_t rt_239 = alg_root_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less(v_i, alg_text_length(v_text))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(v_result, "Add", (Value[]){alg_subscript_get(v_text, v_i)}, 1));
                }
                alg_root_top = rt_239;
            }
            Value ret_272 = v_result;
            alg_root_top = rt_base;
            return ret_272;
            alg_root_top = rt_238;
        }
    }
    alg_raise(alg_string("Can only iterate a collection or a String."));
    Value ret_273 = alg_nil();
    alg_root_top = rt_base;
    return ret_273;
}

static Value m_interpreter_visitforinstmt_1_forinstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_thestmt = alg_widen(args[0], "ForInStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    volatile Value v_elements = alg_nil();
    (void)v_elements;
    alg_root(&v_elements, 1);
    (void)((v_elements = alg_invoke(v_this, "ElementsOf", (Value[]){alg_property(v_thestmt, "Name"), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Iterable")}, 1)}, 2)));
    {
        AlgFrame frame_274;
        alg_push_frame(&frame_274);
        if (ALG_SETJMP(frame_274.jump) == 0) {
            {
                {
                    int32_t rt_240 = alg_root_top;
                    volatile Value loop_275 = alg_iterable(v_elements);
                    (void)loop_275;
                    alg_root(&loop_275, 1);
                    for (volatile int32_t at_275 = 0; at_275 < alg_iterable_count(loop_275); at_275++) {
                        int32_t rt_241 = alg_root_top;
                        volatile Value v_element = alg_iterable_at(loop_275, at_275);
                        (void)v_element;
                        alg_root(&v_element, 1);
                        {
                            int32_t rt_242 = alg_root_top;
                            volatile Value v_scope = alg_new(k_environment, NULL, 0);
                            (void)v_scope;
                            alg_root(&v_scope, 1);
                            (void)(alg_set_property(v_scope, "Enclosing", alg_property(v_this, "Env")));
                            (void)(alg_invoke(v_scope, "Define", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_element}, 2));
                            {
                                AlgFrame frame_276;
                                alg_push_frame(&frame_276);
                                if (ALG_SETJMP(frame_276.jump) == 0) {
                                    {
                                        (void)(alg_invoke(v_this, "ExecuteBlock", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "Body")), v_scope}, 2));
                                    }
                                    alg_pop_frame();
                                }
                                else {
                                    static const char *names_276[] = {"Continued"};
                                    int32_t which_276 = alg_handler(frame_276.raised, names_276, 1);
                                    if (which_276 == 0) {
                                        {
                                            int32_t rt_243 = alg_root_top;
                                            volatile Value v_c = frame_276.raised;
                                            (void)v_c;
                                            alg_root(&v_c, 1);
                                            if (alg_truthy(alg_not(f_names(NULL, (Value[]){alg_property(v_c, "Label"), alg_property(v_thestmt, "Label")}, 2)))) {
                                                alg_raise(v_c);
                                            }
                                            alg_root_top = rt_243;
                                        }
                                    }
                                    else {
                                        alg_raise(frame_276.raised);
                                    }
                                }
                            }
                            alg_root_top = rt_242;
                        }
                        alg_root_top = rt_241;
                    }
                    alg_root_top = rt_240;
                }
            }
            alg_pop_frame();
        }
        else {
            static const char *names_274[] = {"Broke"};
            int32_t which_274 = alg_handler(frame_274.raised, names_274, 1);
            if (which_274 == 0) {
                {
                    int32_t rt_244 = alg_root_top;
                    volatile Value v_e = frame_274.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    if (alg_truthy(alg_not(f_names(NULL, (Value[]){alg_property(v_e, "Label"), alg_property(v_thestmt, "Label")}, 2)))) {
                        alg_raise(v_e);
                    }
                    alg_root_top = rt_244;
                }
            }
            else {
                alg_raise(frame_274.raised);
            }
        }
    }
    volatile Value ret_277 = alg_nil();
    alg_root_top = rt_base;
    return ret_277;
}

static Value m_interpreter_visitbreakstmt_1_breakstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "BreakStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    alg_raise(alg_new(k_broke, (Value[]){alg_property(v_thestmt, "Label")}, 1));
    Value ret_278 = alg_nil();
    alg_root_top = rt_base;
    return ret_278;
}

static Value m_interpreter_visitcontinuestmt_1_continuestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ContinueStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    alg_raise(alg_new(k_continued, (Value[]){alg_property(v_thestmt, "Label")}, 1));
    Value ret_279 = alg_nil();
    alg_root_top = rt_base;
    return ret_279;
}

static Value m_interpreter_visitlabelstmt_1_labelstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "LabelStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "Inner")}, 1));
    Value ret_280 = alg_nil();
    alg_root_top = rt_base;
    return ret_280;
}

static Value m_interpreter_visitgotostmt_1_gotostmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "GotoStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    alg_raise(alg_new(k_jumped, (Value[]){alg_property(v_thestmt, "Label")}, 1));
    Value ret_281 = alg_nil();
    alg_root_top = rt_base;
    return ret_281;
}

static Value m_interpreter_visitmodulestmt_1_modulestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ModuleStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_importer = alg_nil();
    (void)v_importer;
    alg_root(&v_importer, 1);
    Value v_moduleenv = alg_nil();
    (void)v_moduleenv;
    alg_root(&v_moduleenv, 1);
    Value v_exported = alg_nil();
    (void)v_exported;
    alg_root(&v_exported, 1);
    (void)((v_importer = alg_property(v_this, "Env")));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Modules"), "Contains", (Value[]){alg_property(v_thestmt, "FileName")}, 1))) {
        {
            int32_t rt_245 = alg_root_top;
            Value v_already = alg_cast(alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_property(v_thestmt, "FileName")}, 1), "Environment");
            (void)v_already;
            alg_root(&v_already, 1);
            if (alg_truthy(alg_equal(alg_property(v_already, "UnitName"), alg_string("")))) {
                (void)(alg_set_property(v_already, "UnitName", alg_str(alg_property(v_thestmt, "UnitName"))));
            }
            (void)(alg_invoke(alg_property(v_importer, "Imports"), "Add", (Value[]){alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_property(v_thestmt, "FileName")}, 1)}, 1));
            (void)(alg_invoke(alg_property(v_this, "UnitsByName"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_thestmt, "UnitName")}, 1), alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_property(v_thestmt, "FileName")}, 1)}, 2));
            Value ret_282 = alg_nil();
            alg_root_top = rt_base;
            return ret_282;
            alg_root_top = rt_245;
        }
    }
    (void)((v_moduleenv = alg_new(k_environment, NULL, 0)));
    (void)(alg_set_property(v_moduleenv, "Enclosing", alg_property(v_this, "Builtins")));
    (void)(alg_set_property(v_moduleenv, "UnitName", alg_str(alg_property(v_thestmt, "UnitName"))));
    (void)(alg_invoke(alg_property(v_this, "Modules"), "Put", (Value[]){alg_property(v_thestmt, "FileName"), v_moduleenv}, 2));
    (void)(alg_invoke(v_this, "ExecuteBlock", (Value[]){alg_property(v_thestmt, "Statements"), v_moduleenv}, 2));
    (void)((v_exported = alg_list()));
    Value v_hidden = alg_set();
    (void)v_hidden;
    alg_root(&v_hidden, 1);
    {
        int32_t rt_246 = alg_root_top;
        Value loop_283 = alg_iterable(alg_property(v_thestmt, "PrivateNames"));
        (void)loop_283;
        alg_root(&loop_283, 1);
        for (int32_t at_283 = 0; at_283 < alg_iterable_count(loop_283); at_283++) {
            int32_t rt_247 = alg_root_top;
            Value v_privatename = alg_iterable_at(loop_283, at_283);
            (void)v_privatename;
            alg_root(&v_privatename, 1);
            (void)(alg_invoke(v_hidden, "Add", (Value[]){f_foldcase(NULL, (Value[]){v_privatename}, 1)}, 1));
            alg_root_top = rt_247;
        }
        alg_root_top = rt_246;
    }
    Value v_names = alg_invoke(alg_property(v_moduleenv, "Values"), "Keys", NULL, 0);
    (void)v_names;
    alg_root(&v_names, 1);
    {
        int32_t rt_248 = alg_root_top;
        Value loop_284 = alg_iterable(v_names);
        (void)loop_284;
        alg_root(&loop_284, 1);
        for (int32_t at_284 = 0; at_284 < alg_iterable_count(loop_284); at_284++) {
            int32_t rt_249 = alg_root_top;
            Value v_thename = alg_iterable_at(loop_284, at_284);
            (void)v_thename;
            alg_root(&v_thename, 1);
            {
                if (alg_truthy(alg_not(alg_invoke(v_hidden, "Contains", (Value[]){v_thename}, 1)))) {
                    (void)(alg_invoke(v_exported, "Add", (Value[]){v_thename}, 1));
                }
            }
            alg_root_top = rt_249;
        }
        alg_root_top = rt_248;
    }
    (void)(alg_set_property(v_moduleenv, "Exports", alg_set()));
    {
        int32_t rt_250 = alg_root_top;
        Value loop_285 = alg_iterable(v_exported);
        (void)loop_285;
        alg_root(&loop_285, 1);
        for (int32_t at_285 = 0; at_285 < alg_iterable_count(loop_285); at_285++) {
            int32_t rt_251 = alg_root_top;
            Value v_each = alg_iterable_at(loop_285, at_285);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_invoke(alg_property(v_moduleenv, "Exports"), "Add", (Value[]){v_each}, 1));
            alg_root_top = rt_251;
        }
        alg_root_top = rt_250;
    }
    (void)(alg_invoke(alg_property(v_importer, "Imports"), "Add", (Value[]){v_moduleenv}, 1));
    (void)(alg_invoke(alg_property(v_this, "UnitsByName"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_thestmt, "UnitName")}, 1), v_moduleenv}, 2));
    Value ret_286 = alg_nil();
    alg_root_top = rt_base;
    return ret_286;
}

static Value m_interpreter_visitraisestmt_1_raisestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "RaiseStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    alg_raise(alg_new(k_raised, (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Value")}, 1)}, 1));
    Value ret_287 = alg_nil();
    alg_root_top = rt_base;
    return ret_287;
}

static Value m_interpreter_findhandler_2_map(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_handlers = alg_widen(args[0], "Map");
    (void)v_handlers;
    alg_root(&v_handlers, 1);
    Value v_value = args[1];
    (void)v_value;
    alg_root(&v_value, 1);
    Value v_klass = alg_nil();
    (void)v_klass;
    alg_root(&v_klass, 1);
    if (alg_truthy(alg_is(v_value, "ObjInstance"))) {
        {
            (void)((v_klass = alg_cast(alg_property(v_value, "Klass"), "ObjClass")));
            while (alg_truthy(alg_not_equal(v_klass, alg_nil()))) {
                {
                    int32_t rt_252 = alg_root_top;
                    Value v_thename = alg_str(alg_property(v_klass, "Name"));
                    (void)v_thename;
                    alg_root(&v_thename, 1);
                    if (alg_truthy(alg_invoke(v_handlers, "Contains", (Value[]){v_thename}, 1))) {
                        Value ret_288 = alg_cast(alg_invoke(v_handlers, "Get", (Value[]){v_thename}, 1), "ExceptHandler");
                        alg_root_top = rt_base;
                        return ret_288;
                    }
                    (void)((v_klass = alg_property(v_klass, "Superclass")));
                    alg_root_top = rt_252;
                }
            }
            Value ret_289 = alg_nil();
            alg_root_top = rt_base;
            return ret_289;
        }
    }
    Value v_typename = f_typenameof(NULL, (Value[]){v_value}, 1);
    (void)v_typename;
    alg_root(&v_typename, 1);
    if (alg_truthy(alg_invoke(v_handlers, "Contains", (Value[]){v_typename}, 1))) {
        Value ret_290 = alg_cast(alg_invoke(v_handlers, "Get", (Value[]){v_typename}, 1), "ExceptHandler");
        alg_root_top = rt_base;
        return ret_290;
    }
    Value ret_291 = alg_nil();
    alg_root_top = rt_base;
    return ret_291;
    Value ret_292 = alg_nil();
    alg_root_top = rt_base;
    return ret_292;
}

static Value m_interpreter_handle_3_trystmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "TryStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_value = args[1];
    (void)v_value;
    alg_root(&v_value, 1);
    Value v_original = args[2];
    (void)v_original;
    alg_root(&v_original, 1);
    Value v_handler = alg_nil();
    (void)v_handler;
    alg_root(&v_handler, 1);
    (void)((v_handler = alg_invoke(v_this, "FindHandler", (Value[]){alg_property(v_thestmt, "Handlers"), v_value}, 2)));
    if (alg_truthy((or_66 = alg_equal(v_handler, alg_nil()), !alg_truthy(or_66) ? or_66 : alg_invoke(alg_property(v_thestmt, "Handlers"), "Contains", (Value[]){alg_string("default")}, 1)))) {
        (void)((v_handler = alg_cast(alg_invoke(alg_property(v_thestmt, "Handlers"), "Get", (Value[]){alg_string("default")}, 1), "ExceptHandler")));
    }
    if (alg_truthy(alg_equal(v_handler, alg_nil()))) {
        alg_raise(v_original);
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(v_handler, "Name"), v_value}, 2));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_handler, "Body")}, 1));
    Value ret_293 = alg_nil();
    alg_root_top = rt_base;
    return ret_293;
}

static Value m_interpreter_visittrystmt_1_trystmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_thestmt = alg_widen(args[0], "TryStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    {
        AlgFrame frame_294;
        alg_push_frame(&frame_294);
        if (ALG_SETJMP(frame_294.jump) == 0) {
            {
                (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "TryBlock")}, 1));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_294[] = {"Return", "Raised", "String"};
            int32_t which_294 = alg_handler(frame_294.raised, names_294, 3);
            if (which_294 == 0) {
                {
                    int32_t rt_253 = alg_root_top;
                    volatile Value v_e = frame_294.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    alg_raise(v_e);
                    alg_root_top = rt_253;
                }
            }
            else if (which_294 == 1) {
                {
                    int32_t rt_254 = alg_root_top;
                    volatile Value v_e = frame_294.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    (void)(alg_invoke(v_this, "Handle", (Value[]){v_thestmt, alg_property(v_e, "Value"), v_e}, 3));
                    alg_root_top = rt_254;
                }
            }
            else if (which_294 == 2) {
                {
                    int32_t rt_255 = alg_root_top;
                    volatile Value v_e = frame_294.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    (void)(alg_invoke(v_this, "Handle", (Value[]){v_thestmt, v_e, v_e}, 3));
                    alg_root_top = rt_255;
                }
            }
            else {
                alg_raise(frame_294.raised);
            }
        }
    }
    volatile Value ret_295 = alg_nil();
    alg_root_top = rt_base;
    return ret_295;
}

static Value m_interpreter_visitreturnstmt_1_returnstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "ReturnStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    if (alg_truthy(alg_not_equal(alg_property(v_stmt, "Value"), alg_nil()))) {
        (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_stmt, "Value")}, 1)));
    }
    alg_raise(alg_new(k_return, (Value[]){v_value}, 1));
    Value ret_296 = alg_nil();
    alg_root_top = rt_base;
    return ret_296;
}

static Value m_interpreter_visitvarstmt_1_varstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "VarStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    if (alg_truthy(alg_not_equal(alg_property(v_stmt, "Initializer"), alg_nil()))) {
        {
            (void)((v_value = alg_invoke(v_this, "Widen", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_stmt, "Initializer")}, 1), alg_str(alg_property(v_stmt, "TypeName"))}, 2)));
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(alg_property(v_stmt, "Name"), "Lexeme"), v_value}, 2));
    Value ret_297 = alg_nil();
    alg_root_top = rt_base;
    return ret_297;
}

static Value m_interpreter_visitvargroupstmt_1_vargroupstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "VarGroupStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Initializer"), alg_nil()))) {
        (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Initializer")}, 1)));
    }
    {
        int32_t rt_256 = alg_root_top;
        Value loop_298 = alg_iterable(alg_property(v_thestmt, "Names"));
        (void)loop_298;
        alg_root(&loop_298, 1);
        for (int32_t at_298 = 0; at_298 < alg_iterable_count(loop_298); at_298++) {
            int32_t rt_257 = alg_root_top;
            Value v_thename = alg_iterable_at(loop_298, at_298);
            (void)v_thename;
            alg_root(&v_thename, 1);
            (void)(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_property(v_thename, "Lexeme"), v_value}, 2));
            alg_root_top = rt_257;
        }
        alg_root_top = rt_256;
    }
    Value ret_299 = alg_nil();
    alg_root_top = rt_base;
    return ret_299;
}

static Value m_interpreter_visitassignexpr_1_assignexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_expr = alg_widen(args[0], "AssignExpr");
    (void)v_expr;
    alg_root(&v_expr, 1);
    volatile Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    volatile Value v_distance = alg_nil();
    (void)v_distance;
    alg_root(&v_distance, 1);
    (void)((v_value = alg_invoke(v_this, "Widen", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_expr, "Value")}, 1), alg_str(alg_property(v_expr, "Declared"))}, 2)));
    (void)((v_distance = alg_cast(alg_invoke(alg_property(v_this, "Locals"), "Get", (Value[]){v_expr}, 1), "Integer")));
    if (alg_truthy(alg_not_equal(v_distance, alg_nil()))) {
        {
            {
                AlgFrame frame_300;
                alg_push_frame(&frame_300);
                if (ALG_SETJMP(frame_300.jump) == 0) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Env"), "AssignAt", (Value[]){v_distance, alg_property(v_expr, "Name"), v_value}, 3));
                    }
                    alg_pop_frame();
                }
                else {
                    static const char *names_300[] = {"String"};
                    int32_t which_300 = alg_handler(frame_300.raised, names_300, 1);
                    if (which_300 == 0) {
                        {
                            int32_t rt_258 = alg_root_top;
                            volatile Value v_e = frame_300.raised;
                            (void)v_e;
                            alg_root(&v_e, 1);
                            (void)(alg_invoke(v_this, "SetThisField", (Value[]){alg_property(v_expr, "Name"), v_value, v_e}, 3));
                            alg_root_top = rt_258;
                        }
                    }
                    else {
                        alg_raise(frame_300.raised);
                    }
                }
            }
        }
    } else {
        {
            {
                AlgFrame frame_301;
                alg_push_frame(&frame_301);
                if (ALG_SETJMP(frame_301.jump) == 0) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Env"), "Assign", (Value[]){alg_property(v_expr, "Name"), v_value}, 2));
                    }
                    alg_pop_frame();
                }
                else {
                    static const char *names_301[] = {"String"};
                    int32_t which_301 = alg_handler(frame_301.raised, names_301, 1);
                    if (which_301 == 0) {
                        {
                            int32_t rt_259 = alg_root_top;
                            volatile Value v_e = frame_301.raised;
                            (void)v_e;
                            alg_root(&v_e, 1);
                            (void)(alg_invoke(v_this, "SetThisField", (Value[]){alg_property(v_expr, "Name"), v_value, v_e}, 3));
                            alg_root_top = rt_259;
                        }
                    }
                    else {
                        alg_raise(frame_301.raised);
                    }
                }
            }
        }
    }
    volatile Value ret_302 = v_value;
    alg_root_top = rt_base;
    return ret_302;
    volatile Value ret_303 = alg_nil();
    alg_root_top = rt_base;
    return ret_303;
}

static Value i_broke(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Label", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_broke_init_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_label = alg_widen(args[0], "String");
    (void)v_label;
    alg_root(&v_label, 1);
    (void)(alg_set_property(v_this, "Label", v_label));
    Value ret_304 = alg_nil();
    alg_root_top = rt_base;
    return ret_304;
}

static Value i_continued(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Label", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_continued_init_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_label = alg_widen(args[0], "String");
    (void)v_label;
    alg_root(&v_label, 1);
    (void)(alg_set_property(v_this, "Label", v_label));
    Value ret_305 = alg_nil();
    alg_root_top = rt_base;
    return ret_305;
}

static Value i_jumped(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Label", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_jumped_init_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_label = alg_widen(args[0], "String");
    (void)v_label;
    alg_root(&v_label, 1);
    (void)(alg_set_property(v_this, "Label", v_label));
    Value ret_306 = alg_nil();
    alg_root_top = rt_base;
    return ret_306;
}

Value f_labelat(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_statements = alg_param(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    Value v_named = alg_param(args[1], "String");
    (void)v_named;
    alg_root(&v_named, 1);
    {
        int32_t rt_260 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_statements, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_is(alg_subscript_get(v_statements, v_i), "LabelStmt"))) {
                if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Name"), "Lexeme"))}, 1), f_foldcase(NULL, (Value[]){v_named}, 1)))) {
                    Value ret_307 = v_i;
                    alg_root_top = rt_base;
                    return ret_307;
                }
            }
        }
        alg_root_top = rt_260;
    }
    Value ret_308 = alg_negate(alg_int(1));
    alg_root_top = rt_base;
    return ret_308;
    Value ret_309 = alg_nil();
    alg_root_top = rt_base;
    return ret_309;
}

Value f_names(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_wanted = alg_param(args[0], "String");
    (void)v_wanted;
    alg_root(&v_wanted, 1);
    Value v_loop = alg_param(args[1], "String");
    (void)v_loop;
    alg_root(&v_loop, 1);
    if (alg_truthy(alg_equal(v_wanted, alg_string("")))) {
        Value ret_310 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_310;
    }
    Value ret_311 = alg_equal(f_foldcase(NULL, (Value[]){v_wanted}, 1), f_foldcase(NULL, (Value[]){v_loop}, 1));
    alg_root_top = rt_base;
    return ret_311;
    Value ret_312 = alg_nil();
    alg_root_top = rt_base;
    return ret_312;
}

static Value i_raised(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Value", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_raised_init_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    (void)(alg_set_property(v_this, "Value", v_value));
    Value ret_313 = alg_nil();
    alg_root_top = rt_base;
    return ret_313;
}

static Value i_return(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Value", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_return_init_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    (void)(alg_set_property(v_this, "Value", v_value));
    Value ret_314 = alg_nil();
    alg_root_top = rt_base;
    return ret_314;
}

static Value *roots_Interpreter[] = {
    &v_programarguments,
    &fn_setprogramarguments,
    &v_outputsuppressed,
    &fn_suppressoutput,
    &fn_rendered,
    &fn_stringify,
    &k_native,
    &fn_parsednumber,
    &k_interpreter,
    &k_broke,
    &k_continued,
    &k_jumped,
    &fn_labelat,
    &fn_names,
    &k_raised,
    &k_return,
};

void init_Interpreter(void) {
    alg_roots(roots_Interpreter, 16);
    k_native = alg_class("Native", alg_nil());
    k_interpreter = alg_class("Interpreter", alg_nil());
    k_broke = alg_class("Broke", alg_nil());
    k_continued = alg_class("Continued", alg_nil());
    k_jumped = alg_class("Jumped", alg_nil());
    k_raised = alg_class("Raised", alg_nil());
    k_return = alg_class("Return", alg_nil());
    fn_setprogramarguments = alg_closure("SetProgramArguments", f_setprogramarguments, NULL, 0, 1, t_f_setprogramarguments);
    fn_suppressoutput = alg_closure("SuppressOutput", f_suppressoutput, NULL, 0, 1, t_f_suppressoutput);
    fn_rendered = alg_closure("Rendered", f_rendered, NULL, 0, 2, t_f_rendered);
    fn_stringify = alg_closure("Stringify", f_stringify, NULL, 0, 2, t_f_stringify);
    alg_class_field(k_native, "Name");
    alg_class_field(k_native, "TheArity");
    alg_class_initializer(k_native, i_native);
    alg_class_method(k_native, "Init", m_native_init_2_string_integer, 2, t_native_init_2_string_integer);
    alg_class_method(k_native, "Arity", m_native_arity_0, 0, NULL);
    alg_class_method(k_native, "ToString", m_native_tostring_0, 0, NULL);
    alg_class_method(k_native, "Call", m_native_call_2, 2, t_native_call_2);
    fn_parsednumber = alg_closure("ParsedNumber", f_parsednumber, NULL, 0, 1, t_f_parsednumber);
    alg_class_field(k_interpreter, "Env");
    alg_class_field(k_interpreter, "Builtins");
    alg_class_field(k_interpreter, "Globals");
    alg_class_field(k_interpreter, "Locals");
    alg_class_field(k_interpreter, "Modules");
    alg_class_field(k_interpreter, "HoistedClasses");
    alg_class_field(k_interpreter, "RootFile");
    alg_class_field(k_interpreter, "UnitsByName");
    alg_class_field(k_interpreter, "MemberIsCallee");
    alg_class_initializer(k_interpreter, i_interpreter);
    alg_class_method(k_interpreter, "Init", m_interpreter_init_0, 0, NULL);
    alg_class_method(k_interpreter, "Hoist", m_interpreter_hoist_1_list, 1, t_interpreter_hoist_1_list);
    alg_class_method(k_interpreter, "HoistedClass", m_interpreter_hoistedclass_1_string, 1, t_interpreter_hoistedclass_1_string);
    alg_class_method(k_interpreter, "RegisterRoot", m_interpreter_registerroot_0, 0, NULL);
    alg_class_method(k_interpreter, "Interpret", m_interpreter_interpret_1_list, 1, t_interpreter_interpret_1_list);
    alg_class_method(k_interpreter, "HoistTests", m_interpreter_hoisttests_11_list_list_map_boolean_environment_map_string_list_map_set_boolean, 11, t_interpreter_hoisttests_11_list_list_map_boolean_environment_map_string_list_map_set_boolean);
    alg_class_method(k_interpreter, "RunTests", m_interpreter_runtests_2_list_string, 2, t_interpreter_runtests_2_list_string);
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
    alg_class_method(k_interpreter, "Shown", m_interpreter_shown_1, 1, t_interpreter_shown_1);
    alg_class_method(k_interpreter, "SuggestUnit", m_interpreter_suggestunit_2_token_string, 2, t_interpreter_suggestunit_2_token_string);
    alg_class_method(k_interpreter, "IntegerDivide", m_interpreter_integerdivide_2, 2, t_interpreter_integerdivide_2);
    alg_class_method(k_interpreter, "Remainder", m_interpreter_remainder_2, 2, t_interpreter_remainder_2);
    alg_class_method(k_interpreter, "Bitwise", m_interpreter_bitwise_1, 1, t_interpreter_bitwise_1);
    alg_class_method(k_interpreter, "Arithmetic", m_interpreter_arithmetic_1, 1, t_interpreter_arithmetic_1);
    alg_class_method(k_interpreter, "Orders", m_interpreter_orders_1, 1, t_interpreter_orders_1);
    alg_class_method(k_interpreter, "VisitBinary", m_interpreter_visitbinary_1_binaryexpr, 1, t_interpreter_visitbinary_1_binaryexpr);
    alg_class_method(k_interpreter, "Arranged", m_interpreter_arranged_3_list_list, 3, t_interpreter_arranged_3_list_list);
    alg_class_method(k_interpreter, "VisitCall", m_interpreter_visitcall_1_callexpr, 1, t_interpreter_visitcall_1_callexpr);
    alg_class_method(k_interpreter, "AssignQualified", m_interpreter_assignqualified_3_string_token, 3, t_interpreter_assignqualified_3_string_token);
    alg_class_method(k_interpreter, "Qualified", m_interpreter_qualified_2_string_token, 2, t_interpreter_qualified_2_string_token);
    alg_class_method(k_interpreter, "Responds", m_interpreter_responds_2_token, 2, t_interpreter_responds_2_token);
    alg_class_method(k_interpreter, "ExtensionNamed", m_interpreter_extensionnamed_1_getexpr, 1, t_interpreter_extensionnamed_1_getexpr);
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
    alg_class_method(k_interpreter, "VisitContinueStmt", m_interpreter_visitcontinuestmt_1_continuestmt, 1, t_interpreter_visitcontinuestmt_1_continuestmt);
    alg_class_method(k_interpreter, "VisitLabelStmt", m_interpreter_visitlabelstmt_1_labelstmt, 1, t_interpreter_visitlabelstmt_1_labelstmt);
    alg_class_method(k_interpreter, "VisitGotoStmt", m_interpreter_visitgotostmt_1_gotostmt, 1, t_interpreter_visitgotostmt_1_gotostmt);
    alg_class_method(k_interpreter, "VisitModuleStmt", m_interpreter_visitmodulestmt_1_modulestmt, 1, t_interpreter_visitmodulestmt_1_modulestmt);
    alg_class_method(k_interpreter, "VisitRaiseStmt", m_interpreter_visitraisestmt_1_raisestmt, 1, t_interpreter_visitraisestmt_1_raisestmt);
    alg_class_method(k_interpreter, "FindHandler", m_interpreter_findhandler_2_map, 2, t_interpreter_findhandler_2_map);
    alg_class_method(k_interpreter, "Handle", m_interpreter_handle_3_trystmt, 3, t_interpreter_handle_3_trystmt);
    alg_class_method(k_interpreter, "VisitTryStmt", m_interpreter_visittrystmt_1_trystmt, 1, t_interpreter_visittrystmt_1_trystmt);
    alg_class_method(k_interpreter, "VisitReturnStmt", m_interpreter_visitreturnstmt_1_returnstmt, 1, t_interpreter_visitreturnstmt_1_returnstmt);
    alg_class_method(k_interpreter, "VisitVarStmt", m_interpreter_visitvarstmt_1_varstmt, 1, t_interpreter_visitvarstmt_1_varstmt);
    alg_class_method(k_interpreter, "VisitVarGroupStmt", m_interpreter_visitvargroupstmt_1_vargroupstmt, 1, t_interpreter_visitvargroupstmt_1_vargroupstmt);
    alg_class_method(k_interpreter, "VisitAssignExpr", m_interpreter_visitassignexpr_1_assignexpr, 1, t_interpreter_visitassignexpr_1_assignexpr);
    alg_class_field(k_broke, "Label");
    alg_class_initializer(k_broke, i_broke);
    alg_class_method(k_broke, "Init", m_broke_init_1_string, 1, t_broke_init_1_string);
    alg_class_field(k_continued, "Label");
    alg_class_initializer(k_continued, i_continued);
    alg_class_method(k_continued, "Init", m_continued_init_1_string, 1, t_continued_init_1_string);
    alg_class_field(k_jumped, "Label");
    alg_class_initializer(k_jumped, i_jumped);
    alg_class_method(k_jumped, "Init", m_jumped_init_1_string, 1, t_jumped_init_1_string);
    fn_labelat = alg_closure("LabelAt", f_labelat, NULL, 0, 2, t_f_labelat);
    fn_names = alg_closure("Names", f_names, NULL, 0, 2, t_f_names);
    alg_class_field(k_raised, "Value");
    alg_class_initializer(k_raised, i_raised);
    alg_class_method(k_raised, "Init", m_raised_init_1, 1, t_raised_init_1);
    alg_class_field(k_return, "Value");
    alg_class_initializer(k_return, i_return);
    alg_class_method(k_return, "Init", m_return_init_1, 1, t_return_init_1);
    init_Console();
    init_TestReport();
    init_ObjBuffer();
    init_ObjClass();
    init_ObjCollection();
    init_ObjEnum();
    init_ObjFile();
    init_Parser();
    init_Resolver();
    v_programarguments = alg_list();
    d_programarguments = true;
    v_outputsuppressed = alg_bool(false);
    d_outputsuppressed = true;
}
