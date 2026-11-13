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
Value v_interpVcollectVevery;
bool d_interpVcollectVevery;
Value v_interpVtick;
bool d_interpVtick;
Value v_typeVvalues;
bool d_typeVvalues;
Value v_interpVsiteVfile;
bool d_interpVsiteVfile;
Value v_interpVsiteVline;
bool d_interpVsiteVline;
Value k_native;
static Value or_0;
static Value or_1;
static Value or_2;
static Value or_3;
static Value or_4;
static Value or_5;
static Value or_6;
static Value or_7;
static const char *t_native_init_2_string_integer[] = { "Name : String", "TheArity : Integer" };
static const char *t_native_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };
static Value or_8;
static Value or_9;
Value fn_parsednumber;
static const char *t_f_parsednumber[] = { "Text : String" };
Value k_interpreter;
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
static Value or_67;
static Value or_68;
static Value or_69;
static Value or_70;
static Value or_71;
static Value or_72;
static Value or_73;
static Value or_74;
static Value or_75;
static Value or_76;
static Value or_77;
static Value or_78;
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
static const char *t_interpreter_receiverfield_1_token[] = { "Name : Token" };
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
    Value v_arguments = alg_param_of(args[0], "List", "SetProgramArguments");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    int32_t rh_781 = alg_hold_top;
    (void)((alg_declared(d_programarguments, "ProgramArguments"), (v_programarguments = v_arguments)));
    alg_hold_top = rh_781;
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

Value f_suppressoutput(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_suppress = alg_param_of(args[0], "Boolean", "SuppressOutput");
    (void)v_suppress;
    alg_root(&v_suppress, 1);
    int32_t rh_782 = alg_hold_top;
    (void)((alg_declared(d_outputsuppressed, "OutputSuppressed"), (v_outputsuppressed = v_suppress)));
    alg_hold_top = rh_782;
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
    Value v_arguments = alg_param_of(args[1], "List", "Rendered");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    int32_t rh_783 = alg_hold_top;
    Value v_line = alg_nil();
    (void)v_line;
    alg_root(&v_line, 1);
    alg_hold_top = rh_783;
    (void)((v_line = alg_literal("")));
    alg_hold_top = rh_783;
    {
        int32_t rt_784 = alg_root_top;
        Value loop_2 = alg_iterable(v_arguments);
        (void)loop_2;
        alg_root(&loop_2, 1);
        for (int32_t at_2 = 0; at_2 < alg_iterable_count(loop_2); at_2++) {
            alg_safe_point();
            int32_t rt_785 = alg_root_top;
            Value v_argument = alg_iterable_at(loop_2, at_2);
            (void)v_argument;
            alg_root(&v_argument, 1);
            (void)((v_line = alg_hold(alg_add(v_line, alg_hold(f_stringify(NULL, (Value[]){v_theinterpreter, v_argument}, 2))))));
            alg_root_top = rt_785;
        }
        alg_root_top = rt_784;
    }
    alg_hold_top = rh_783;
    Value ret_3 = v_line;
    alg_root_top = rt_base;
    return ret_3;
    alg_hold_top = rh_783;
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
    int32_t rh_786 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(v_value, alg_nil())))) {
        Value ret_5 = alg_literal("nil");
        alg_root_top = rt_base;
        return ret_5;
    }
    alg_hold_top = rh_786;
    if (alg_truthy(alg_is_class(v_value, k_objinstance))) {
        {
            int32_t rt_787 = alg_root_top;
            int32_t rh_788 = alg_hold_top;
            Value v_method = alg_hold(alg_invoke(alg_hold(alg_property(v_value, "Klass")), "MethodOfArity", (Value[]){alg_literal("tostring"), alg_int(0)}, 2));
            (void)v_method;
            alg_root(&v_method, 1);
            alg_hold_top = rh_788;
            if (alg_truthy(alg_hold(alg_not_equal(v_method, alg_nil())))) {
                Value ret_6 = alg_hold(f_stringify(NULL, (Value[]){v_theinterpreter, alg_hold(alg_invoke(alg_hold(alg_invoke(v_method, "Bind", (Value[]){v_value}, 1)), "Call", (Value[]){v_theinterpreter, alg_hold(alg_list())}, 2))}, 2));
                alg_root_top = rt_base;
                return ret_6;
            }
            alg_hold_top = rh_788;
            alg_root_top = rt_787;
        }
    }
    alg_hold_top = rh_786;
    if (alg_truthy(alg_is_class(v_value, k_objcollection))) {
        {
            int32_t rt_789 = alg_root_top;
            int32_t rh_790 = alg_hold_top;
            Value v_result = alg_char_value(91);
            (void)v_result;
            alg_root(&v_result, 1);
            alg_hold_top = rh_790;
            Value v_first = alg_bool(true);
            (void)v_first;
            alg_root(&v_first, 1);
            alg_hold_top = rh_790;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_value, "Kind")), alg_literal("Map"))))) {
                {
                    int32_t rt_791 = alg_root_top;
                    Value loop_7 = alg_iterable(alg_hold(alg_invoke(alg_hold(alg_property(v_value, "Pairs")), "Keys", NULL, 0)));
                    (void)loop_7;
                    alg_root(&loop_7, 1);
                    for (int32_t at_7 = 0; at_7 < alg_iterable_count(loop_7); at_7++) {
                        alg_safe_point();
                        int32_t rt_792 = alg_root_top;
                        Value v_key = alg_iterable_at(loop_7, at_7);
                        (void)v_key;
                        alg_root(&v_key, 1);
                        {
                            int32_t rh_793 = alg_hold_top;
                            if (alg_truthy(alg_hold(alg_not(v_first)))) {
                                (void)((v_result = alg_hold(alg_add(v_result, alg_literal(", ")))));
                            }
                            alg_hold_top = rh_793;
                            (void)((v_first = alg_bool(false)));
                            alg_hold_top = rh_793;
                            (void)((v_result = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_result, alg_hold(f_stringify(NULL, (Value[]){v_theinterpreter, v_key}, 2)))), alg_char_value(58))), alg_hold(f_stringify(NULL, (Value[]){v_theinterpreter, alg_hold(alg_invoke(alg_hold(alg_property(v_value, "Pairs")), "Get", (Value[]){v_key}, 1))}, 2))))));
                            alg_hold_top = rh_793;
                        }
                        alg_root_top = rt_792;
                    }
                    alg_root_top = rt_791;
                }
            } else {
                {
                    int32_t rt_794 = alg_root_top;
                    Value loop_8 = alg_iterable(alg_hold(alg_property(v_value, "Items")));
                    (void)loop_8;
                    alg_root(&loop_8, 1);
                    for (int32_t at_8 = 0; at_8 < alg_iterable_count(loop_8); at_8++) {
                        alg_safe_point();
                        int32_t rt_795 = alg_root_top;
                        Value v_element = alg_iterable_at(loop_8, at_8);
                        (void)v_element;
                        alg_root(&v_element, 1);
                        {
                            int32_t rh_796 = alg_hold_top;
                            if (alg_truthy(alg_hold(alg_not(v_first)))) {
                                (void)((v_result = alg_hold(alg_add(v_result, alg_literal(", ")))));
                            }
                            alg_hold_top = rh_796;
                            (void)((v_first = alg_bool(false)));
                            alg_hold_top = rh_796;
                            (void)((v_result = alg_hold(alg_add(v_result, alg_hold(f_stringify(NULL, (Value[]){v_theinterpreter, v_element}, 2))))));
                            alg_hold_top = rh_796;
                        }
                        alg_root_top = rt_795;
                    }
                    alg_root_top = rt_794;
                }
            }
            alg_hold_top = rh_790;
            Value ret_9 = alg_hold(alg_add(v_result, alg_char_value(93)));
            alg_root_top = rt_base;
            return ret_9;
            alg_hold_top = rh_790;
            alg_root_top = rt_789;
        }
    }
    alg_hold_top = rh_786;
    Value ret_10 = alg_hold(alg_str(v_value));
    alg_root_top = rt_base;
    return ret_10;
    alg_hold_top = rh_786;
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
    int32_t rh_797 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_797;
    (void)(alg_hold(alg_set_property(v_this, "TheArity", v_thearity)));
    alg_hold_top = rh_797;
    Value ret_12 = alg_nil();
    alg_root_top = rt_base;
    return ret_12;
}

static Value m_native_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_798 = alg_hold_top;
    Value ret_13 = alg_property(v_this, "TheArity");
    alg_root_top = rt_base;
    return ret_13;
    alg_hold_top = rh_798;
    Value ret_14 = alg_nil();
    alg_root_top = rt_base;
    return ret_14;
}

static Value m_native_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_799 = alg_hold_top;
    Value ret_15 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("<fn "), alg_property(v_this, "Name"))), alg_char_value(62)));
    alg_root_top = rt_base;
    return ret_15;
    alg_hold_top = rh_799;
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
    int32_t rh_800 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("clock"))))) {
        Value ret_17 = alg_hold(alg_clock());
        alg_root_top = rt_base;
        return ret_17;
    } else {
        if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Collect"))))) {
            Value ret_18 = alg_hold(alg_collected());
            alg_root_top = rt_base;
            return ret_18;
        } else {
            if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Fields"))))) {
                {
                    int32_t rt_801 = alg_root_top;
                    int32_t rh_802 = alg_hold_top;
                    Value v_shaped = alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("Map")}, 1));
                    (void)v_shaped;
                    alg_root(&v_shaped, 1);
                    alg_hold_top = rh_802;
                    if (alg_truthy(alg_is_class(alg_hold(alg_subscript_get(v_arguments, alg_int(0))), k_objinstance))) {
                        (void)(alg_hold(alg_invoke(alg_hold(alg_property((alg_hold(alg_cast_class(alg_subscript_get(v_arguments, alg_int(0)), k_objinstance, "ObjInstance"))), "Klass")), "FieldsInto", (Value[]){alg_hold(alg_property(v_shaped, "Pairs"))}, 1)));
                    } else {
                        if (alg_truthy(alg_is_class(alg_hold(alg_subscript_get(v_arguments, alg_int(0))), k_objclass))) {
                            (void)(alg_hold(alg_invoke((alg_hold(alg_cast_class(alg_subscript_get(v_arguments, alg_int(0)), k_objclass, "ObjClass"))), "FieldsInto", (Value[]){alg_hold(alg_property(v_shaped, "Pairs"))}, 1)));
                        }
                    }
                    alg_hold_top = rh_802;
                    Value ret_19 = v_shaped;
                    alg_root_top = rt_base;
                    return ret_19;
                    alg_hold_top = rh_802;
                    alg_root_top = rt_801;
                }
            } else {
                if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("TypeOf"))))) {
                    {
                        int32_t rt_803 = alg_root_top;
                        int32_t rh_804 = alg_hold_top;
                        Value v_asked = alg_hold(alg_subscript_get(v_arguments, alg_int(0)));
                        (void)v_asked;
                        alg_root(&v_asked, 1);
                        alg_hold_top = rh_804;
                        if (alg_truthy(alg_hold(alg_equal(v_asked, alg_nil())))) {
                            Value ret_20 = alg_nil();
                            alg_root_top = rt_base;
                            return ret_20;
                        }
                        alg_hold_top = rh_804;
                        if (alg_truthy(alg_is_class(v_asked, k_objclass))) {
                            Value ret_21 = v_asked;
                            alg_root_top = rt_base;
                            return ret_21;
                        }
                        alg_hold_top = rh_804;
                        if (alg_truthy(alg_is_class(v_asked, k_objinstance))) {
                            Value ret_22 = alg_hold(alg_property((alg_cast_class(v_asked, k_objinstance, "ObjInstance")), "Klass"));
                            alg_root_top = rt_base;
                            return ret_22;
                        }
                        alg_hold_top = rh_804;
                        Value v_named = alg_hold(f_typenameof(NULL, (Value[]){v_asked}, 1));
                        (void)v_named;
                        alg_root(&v_named, 1);
                        alg_hold_top = rh_804;
                        if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke((alg_declared(d_typeVvalues, "TYPE_VALUES"), v_typeVvalues), "Contains", (Value[]){v_named}, 1)))))) {
                            {
                                int32_t rt_805 = alg_root_top;
                                int32_t rh_806 = alg_hold_top;
                                Value v_made = alg_hold(alg_new(k_objclass, (Value[]){v_named, alg_nil(), alg_hold(alg_map()), alg_hold(alg_list())}, 4));
                                (void)v_made;
                                alg_root(&v_made, 1);
                                alg_hold_top = rh_806;
                                (void)(alg_hold(alg_set_property(v_made, "IsType", alg_bool(true))));
                                alg_hold_top = rh_806;
                                (void)(alg_hold(alg_invoke((alg_declared(d_typeVvalues, "TYPE_VALUES"), v_typeVvalues), "Put", (Value[]){v_named, v_made}, 2)));
                                alg_hold_top = rh_806;
                                alg_root_top = rt_805;
                            }
                        }
                        alg_hold_top = rh_804;
                        Value ret_23 = alg_hold(alg_invoke((alg_declared(d_typeVvalues, "TYPE_VALUES"), v_typeVvalues), "Get", (Value[]){v_named}, 1));
                        alg_root_top = rt_base;
                        return ret_23;
                        alg_hold_top = rh_804;
                        alg_root_top = rt_803;
                    }
                } else {
                    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Member"))))) {
                        {
                            int32_t rt_807 = alg_root_top;
                            int32_t rh_808 = alg_hold_top;
                            Value v_on = alg_hold(alg_subscript_get(v_arguments, alg_int(0)));
                            (void)v_on;
                            alg_root(&v_on, 1);
                            alg_hold_top = rh_808;
                            Value v_asking = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(1)))))}, 1));
                            (void)v_asking;
                            alg_root(&v_asking, 1);
                            alg_hold_top = rh_808;
                            if (alg_truthy(alg_is_class(v_on, k_objinstance))) {
                                {
                                    int32_t rt_809 = alg_root_top;
                                    int32_t rh_810 = alg_hold_top;
                                    Value v_it = alg_cast_class(v_on, k_objinstance, "ObjInstance");
                                    (void)v_it;
                                    alg_root(&v_it, 1);
                                    alg_hold_top = rh_810;
                                    if (alg_truthy(alg_hold(alg_equal(v_asking, alg_hold(f_foldcase(NULL, (Value[]){alg_literal("ClassName")}, 1)))))) {
                                        Value ret_24 = alg_hold(alg_property(alg_hold(alg_property(v_it, "Klass")), "Name"));
                                        alg_root_top = rt_base;
                                        return ret_24;
                                    }
                                    alg_hold_top = rh_810;
                                    Value v_computed = alg_hold(alg_invoke(alg_hold(alg_property(v_it, "Klass")), "MethodOfArity", (Value[]){v_asking, alg_int(0)}, 2));
                                    (void)v_computed;
                                    alg_root(&v_computed, 1);
                                    alg_hold_top = rh_810;
                                    if (alg_truthy(alg_hold((or_1 = alg_hold((or_0 = alg_hold(alg_not_equal(v_computed, alg_nil())), !alg_truthy(or_0) ? or_0 : alg_hold(alg_property(alg_hold(alg_property(v_computed, "Declaration")), "IsProperty")))), !alg_truthy(or_1) ? or_1 : alg_hold(alg_not(alg_hold(alg_invoke(alg_hold(alg_property(v_it, "Fields")), "Contains", (Value[]){v_asking}, 1)))))))) {
                                        Value ret_25 = alg_hold(alg_invoke(alg_hold(alg_invoke(v_computed, "Bind", (Value[]){v_it}, 1)), "Call", (Value[]){v_theinterpreter, alg_hold(alg_list())}, 2));
                                        alg_root_top = rt_base;
                                        return ret_25;
                                    }
                                    alg_hold_top = rh_810;
                                    if (alg_truthy(alg_hold(alg_invoke(alg_hold(alg_property(v_it, "Fields")), "Contains", (Value[]){v_asking}, 1)))) {
                                        Value ret_26 = alg_hold(alg_invoke(alg_hold(alg_property(v_it, "Fields")), "Get", (Value[]){v_asking}, 1));
                                        alg_root_top = rt_base;
                                        return ret_26;
                                    }
                                    alg_hold_top = rh_810;
                                    Value v_bound = alg_hold(alg_invoke(alg_hold(alg_property(v_it, "Klass")), "FindMethod", (Value[]){v_asking}, 1));
                                    (void)v_bound;
                                    alg_root(&v_bound, 1);
                                    alg_hold_top = rh_810;
                                    if (alg_truthy(alg_hold(alg_not_equal(v_bound, alg_nil())))) {
                                        Value ret_27 = alg_hold(alg_invoke(v_bound, "Bind", (Value[]){v_it}, 1));
                                        alg_root_top = rt_base;
                                        return ret_27;
                                    }
                                    alg_hold_top = rh_810;
                                    alg_root_top = rt_809;
                                }
                            }
                            alg_hold_top = rh_808;
                            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined property '"), alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(1))))))), alg_literal("'."))));
                            alg_hold_top = rh_808;
                            alg_root_top = rt_807;
                        }
                    } else {
                        if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Invoke"))))) {
                            {
                                int32_t rt_811 = alg_root_top;
                                int32_t rh_812 = alg_hold_top;
                                Value v_onto = alg_hold(alg_subscript_get(v_arguments, alg_int(0)));
                                (void)v_onto;
                                alg_root(&v_onto, 1);
                                alg_hold_top = rh_812;
                                Value v_called = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(1)))))}, 1));
                                (void)v_called;
                                alg_root(&v_called, 1);
                                alg_hold_top = rh_812;
                                if (alg_truthy(alg_hold(alg_not((alg_is_class(alg_hold(alg_subscript_get(v_arguments, alg_int(2))), k_objcollection)))))) {
                                    alg_raise(alg_literal("Invoke expects a List of arguments."));
                                }
                                alg_hold_top = rh_812;
                                Value v_given = alg_hold(alg_property((alg_hold(alg_cast_class(alg_subscript_get(v_arguments, alg_int(2)), k_objcollection, "ObjCollection"))), "Items"));
                                (void)v_given;
                                alg_root(&v_given, 1);
                                alg_hold_top = rh_812;
                                if (alg_truthy(alg_is_class(v_onto, k_objinstance))) {
                                    {
                                        int32_t rt_813 = alg_root_top;
                                        int32_t rh_814 = alg_hold_top;
                                        Value v_that = alg_cast_class(v_onto, k_objinstance, "ObjInstance");
                                        (void)v_that;
                                        alg_root(&v_that, 1);
                                        alg_hold_top = rh_814;
                                        Value v_maybe = alg_hold(alg_invoke(alg_hold(alg_property(v_that, "Klass")), "MethodOfArity", (Value[]){v_called, alg_int(0)}, 2));
                                        (void)v_maybe;
                                        alg_root(&v_maybe, 1);
                                        alg_hold_top = rh_814;
                                        if (alg_truthy(alg_hold((or_2 = alg_hold(alg_not_equal(v_maybe, alg_nil())), !alg_truthy(or_2) ? or_2 : alg_hold(alg_property(alg_hold(alg_property(v_maybe, "Declaration")), "IsProperty")))))) {
                                            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(1))))))), alg_literal("' is a property; read it rather than calling it."))));
                                        }
                                        alg_hold_top = rh_814;
                                        Value v_chosen = alg_hold(alg_invoke(alg_hold(alg_property(v_that, "Klass")), "FindOverload", (Value[]){v_called, v_given}, 2));
                                        (void)v_chosen;
                                        alg_root(&v_chosen, 1);
                                        alg_hold_top = rh_814;
                                        if (alg_truthy(alg_hold(alg_equal(v_chosen, alg_nil())))) {
                                            {
                                                int32_t rh_815 = alg_hold_top;
                                                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_invoke(alg_hold(alg_property(v_that, "Klass")), "FindMethod", (Value[]){v_called}, 1)), alg_nil())))) {
                                                    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined property '"), alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(1))))))), alg_literal("'."))));
                                                }
                                                alg_hold_top = rh_815;
                                                alg_raise(alg_hold(f_nomatch(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_that, "Klass")), "Name")))), alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(1))))), alg_hold(alg_invoke(alg_hold(alg_property(v_that, "Klass")), "CandidatesOf", (Value[]){v_called}, 1)), alg_hold(alg_property(v_given, "Length"))}, 4)));
                                                alg_hold_top = rh_815;
                                            }
                                        }
                                        alg_hold_top = rh_814;
                                        Value ret_28 = alg_hold(alg_invoke(alg_hold(alg_invoke(v_chosen, "Bind", (Value[]){v_that}, 1)), "Call", (Value[]){v_theinterpreter, v_given}, 2));
                                        alg_root_top = rt_base;
                                        return ret_28;
                                        alg_hold_top = rh_814;
                                        alg_root_top = rt_813;
                                    }
                                }
                                alg_hold_top = rh_812;
                                alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined property '"), alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(1))))))), alg_literal("'."))));
                                alg_hold_top = rh_812;
                                alg_root_top = rt_811;
                            }
                        } else {
                            if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("New"))))) {
                                {
                                    int32_t rh_816 = alg_hold_top;
                                    if (alg_truthy(alg_hold(alg_not((alg_is_class(alg_hold(alg_subscript_get(v_arguments, alg_int(1))), k_objcollection)))))) {
                                        alg_raise(alg_literal("New expects a List of arguments."));
                                    }
                                    alg_hold_top = rh_816;
                                    if (alg_truthy(alg_hold(alg_not((alg_is_class(alg_hold(alg_subscript_get(v_arguments, alg_int(0))), k_objclass)))))) {
                                        alg_raise(alg_literal("Can only construct a class."));
                                    }
                                    alg_hold_top = rh_816;
                                    Value ret_29 = alg_hold(alg_invoke((alg_hold(alg_cast_class(alg_subscript_get(v_arguments, alg_int(0)), k_objclass, "ObjClass"))), "Call", (Value[]){v_theinterpreter, alg_hold(alg_property((alg_hold(alg_cast_class(alg_subscript_get(v_arguments, alg_int(1)), k_objcollection, "ObjCollection"))), "Items"))}, 2));
                                    alg_root_top = rt_base;
                                    return ret_29;
                                    alg_hold_top = rh_816;
                                }
                            } else {
                                if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("SetMember"))))) {
                                    {
                                        int32_t rt_817 = alg_root_top;
                                        int32_t rh_818 = alg_hold_top;
                                        Value v_onto = alg_hold(alg_subscript_get(v_arguments, alg_int(0)));
                                        (void)v_onto;
                                        alg_root(&v_onto, 1);
                                        alg_hold_top = rh_818;
                                        if (alg_truthy(alg_hold(alg_not((alg_is_class(v_onto, k_objinstance)))))) {
                                            alg_raise(alg_literal("Only instances have fields."));
                                        }
                                        alg_hold_top = rh_818;
                                        Value v_that = alg_cast_class(v_onto, k_objinstance, "ObjInstance");
                                        (void)v_that;
                                        alg_root(&v_that, 1);
                                        alg_hold_top = rh_818;
                                        Value v_written = alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(1)))));
                                        (void)v_written;
                                        alg_root(&v_written, 1);
                                        alg_hold_top = rh_818;
                                        Value v_folded = alg_hold(f_foldcase(NULL, (Value[]){v_written}, 1));
                                        (void)v_folded;
                                        alg_root(&v_folded, 1);
                                        alg_hold_top = rh_818;
                                        Value v_maybe = alg_hold(alg_invoke(alg_hold(alg_property(v_that, "Klass")), "MethodOfArity", (Value[]){v_folded, alg_int(0)}, 2));
                                        (void)v_maybe;
                                        alg_root(&v_maybe, 1);
                                        alg_hold_top = rh_818;
                                        if (alg_truthy(alg_hold((or_3 = alg_hold(alg_not_equal(v_maybe, alg_nil())), !alg_truthy(or_3) ? or_3 : alg_hold(alg_property(alg_hold(alg_property(v_maybe, "Declaration")), "IsProperty")))))) {
                                            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), v_written)), alg_literal("' is a property of "))), alg_hold(alg_property(alg_hold(alg_property(v_that, "Klass")), "Name")))), alg_literal(" and cannot be assigned."))));
                                        }
                                        alg_hold_top = rh_818;
                                        if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_hold(alg_property(v_that, "Fields")), "Contains", (Value[]){v_folded}, 1)))))) {
                                            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined property '"), v_written)), alg_literal("'."))));
                                        }
                                        alg_hold_top = rh_818;
                                        Value v_value = alg_hold(alg_invoke(v_theinterpreter, "Widen", (Value[]){alg_hold(alg_subscript_get(v_arguments, alg_int(2))), alg_hold(alg_invoke(alg_hold(alg_property(v_that, "Klass")), "DeclaredTypeOf", (Value[]){v_folded}, 1))}, 2));
                                        (void)v_value;
                                        alg_root(&v_value, 1);
                                        alg_hold_top = rh_818;
                                        (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_that, "Fields")), "Put", (Value[]){v_folded, v_value}, 2)));
                                        alg_hold_top = rh_818;
                                        Value ret_30 = v_value;
                                        alg_root_top = rt_base;
                                        return ret_30;
                                        alg_hold_top = rh_818;
                                        alg_root_top = rt_817;
                                    }
                                } else {
                                    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Length"))))) {
                                        {
                                            int32_t rh_819 = alg_hold_top;
                                            if (alg_truthy(alg_is_class(alg_hold(alg_subscript_get(v_arguments, alg_int(0))), k_objcollection))) {
                                                alg_raise(alg_literal("Length expects text; use .Length for a collection."));
                                            }
                                            alg_hold_top = rh_819;
                                            Value ret_31 = alg_hold(alg_text_length(alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))))));
                                            alg_root_top = rt_base;
                                            return ret_31;
                                            alg_hold_top = rh_819;
                                        }
                                    } else {
                                        if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Copy"))))) {
                                            Value ret_32 = alg_hold(alg_copy(alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0))))), alg_hold(alg_subscript_get(v_arguments, alg_int(1))), alg_hold(alg_subscript_get(v_arguments, alg_int(2)))));
                                            alg_root_top = rt_base;
                                            return ret_32;
                                        } else {
                                            if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Pos"))))) {
                                                {
                                                    int32_t rh_820 = alg_hold_top;
                                                    if (alg_truthy(alg_hold((or_4 = alg_hold(alg_less(alg_hold(alg_property(v_arguments, "Length")), alg_int(2))), alg_truthy(or_4) ? or_4 : alg_hold(alg_greater(alg_hold(alg_property(v_arguments, "Length")), alg_int(3))))))) {
                                                        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expected 2 or 3 arguments but got "), alg_hold(alg_str(alg_hold(alg_property(v_arguments, "Length")))))), alg_char_value(46))));
                                                    }
                                                    alg_hold_top = rh_820;
                                                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(2))))) {
                                                        Value ret_33 = alg_hold(alg_pos(alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0))))), alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(1)))))));
                                                        alg_root_top = rt_base;
                                                        return ret_33;
                                                    }
                                                    alg_hold_top = rh_820;
                                                    Value ret_34 = alg_hold(alg_pos_from(alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0))))), alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(1))))), alg_hold(alg_subscript_get(v_arguments, alg_int(2)))));
                                                    alg_root_top = rt_base;
                                                    return ret_34;
                                                    alg_hold_top = rh_820;
                                                }
                                            } else {
                                                if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("ToUpper"))))) {
                                                    Value ret_35 = alg_hold(alg_to_upper(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))));
                                                    alg_root_top = rt_base;
                                                    return ret_35;
                                                } else {
                                                    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("ToLower"))))) {
                                                        Value ret_36 = alg_hold(alg_to_lower(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))));
                                                        alg_root_top = rt_base;
                                                        return ret_36;
                                                    } else {
                                                        if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Str"))))) {
                                                            {
                                                                int32_t rh_821 = alg_hold_top;
                                                                if (alg_truthy(alg_hold((or_5 = alg_hold(alg_less(alg_hold(alg_property(v_arguments, "Length")), alg_int(1))), alg_truthy(or_5) ? or_5 : alg_hold(alg_greater(alg_hold(alg_property(v_arguments, "Length")), alg_int(3))))))) {
                                                                    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expected 1, 2 or 3 arguments but got "), alg_hold(alg_str(alg_hold(alg_property(v_arguments, "Length")))))), alg_char_value(46))));
                                                                }
                                                                alg_hold_top = rh_821;
                                                                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(1))))) {
                                                                    Value ret_37 = alg_hold(f_stringify(NULL, (Value[]){v_theinterpreter, alg_hold(alg_subscript_get(v_arguments, alg_int(0)))}, 2));
                                                                    alg_root_top = rt_base;
                                                                    return ret_37;
                                                                }
                                                                alg_hold_top = rh_821;
                                                                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(2))))) {
                                                                    Value ret_38 = alg_hold(alg_str_fixed(alg_hold(alg_subscript_get(v_arguments, alg_int(0))), alg_hold(alg_subscript_get(v_arguments, alg_int(1)))));
                                                                    alg_root_top = rt_base;
                                                                    return ret_38;
                                                                }
                                                                alg_hold_top = rh_821;
                                                                Value ret_39 = alg_hold(alg_str_padded(alg_hold(alg_subscript_get(v_arguments, alg_int(0))), alg_hold(alg_subscript_get(v_arguments, alg_int(1))), alg_hold(alg_subscript_get(v_arguments, alg_int(2)))));
                                                                alg_root_top = rt_base;
                                                                return ret_39;
                                                                alg_hold_top = rh_821;
                                                            }
                                                        } else {
                                                            if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Array"))))) {
                                                                {
                                                                    int32_t rt_822 = alg_root_top;
                                                                    int32_t rh_823 = alg_hold_top;
                                                                    Value v_thearray = alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("Array")}, 1));
                                                                    (void)v_thearray;
                                                                    alg_root(&v_thearray, 1);
                                                                    alg_hold_top = rh_823;
                                                                    (void)(alg_hold(alg_invoke(v_thearray, "Allocate", (Value[]){alg_hold(alg_subscript_get(v_arguments, alg_int(0)))}, 1)));
                                                                    alg_hold_top = rh_823;
                                                                    Value ret_40 = v_thearray;
                                                                    alg_root_top = rt_base;
                                                                    return ret_40;
                                                                    alg_hold_top = rh_823;
                                                                    alg_root_top = rt_822;
                                                                }
                                                            } else {
                                                                if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("List"))))) {
                                                                    Value ret_41 = alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("List")}, 1));
                                                                    alg_root_top = rt_base;
                                                                    return ret_41;
                                                                } else {
                                                                    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Map"))))) {
                                                                        Value ret_42 = alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("Map")}, 1));
                                                                        alg_root_top = rt_base;
                                                                        return ret_42;
                                                                    } else {
                                                                        if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Stack"))))) {
                                                                            Value ret_43 = alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("Stack")}, 1));
                                                                            alg_root_top = rt_base;
                                                                            return ret_43;
                                                                        } else {
                                                                            if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Set"))))) {
                                                                                {
                                                                                    int32_t rt_824 = alg_root_top;
                                                                                    int32_t rh_825 = alg_hold_top;
                                                                                    if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(v_arguments, "Length")), alg_int(1))))) {
                                                                                        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expected 0 or 1 arguments but got "), alg_hold(alg_str(alg_hold(alg_property(v_arguments, "Length")))))), alg_char_value(46))));
                                                                                    }
                                                                                    alg_hold_top = rh_825;
                                                                                    Value v_theset = alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("Set")}, 1));
                                                                                    (void)v_theset;
                                                                                    alg_root(&v_theset, 1);
                                                                                    alg_hold_top = rh_825;
                                                                                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(1))))) {
                                                                                        {
                                                                                            int32_t rt_826 = alg_root_top;
                                                                                            int32_t rh_827 = alg_hold_top;
                                                                                            Value v_from = alg_hold(alg_subscript_get(v_arguments, alg_int(0)));
                                                                                            (void)v_from;
                                                                                            alg_root(&v_from, 1);
                                                                                            alg_hold_top = rh_827;
                                                                                            if (alg_truthy(alg_hold((or_6 = alg_hold(alg_not((alg_is_class(v_from, k_objcollection)))), alg_truthy(or_6) ? or_6 : alg_hold(alg_not_equal(alg_hold(alg_property(v_from, "Kind")), alg_literal("List"))))))) {
                                                                                                alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Set expects (List) but got ("), alg_hold(f_typenameof(NULL, (Value[]){v_from}, 1)))), alg_literal(")."))));
                                                                                            }
                                                                                            alg_hold_top = rh_827;
                                                                                            {
                                                                                                int32_t rt_828 = alg_root_top;
                                                                                                Value loop_44 = alg_iterable(alg_hold(alg_property(v_from, "Items")));
                                                                                                (void)loop_44;
                                                                                                alg_root(&loop_44, 1);
                                                                                                for (int32_t at_44 = 0; at_44 < alg_iterable_count(loop_44); at_44++) {
                                                                                                    alg_safe_point();
                                                                                                    int32_t rt_829 = alg_root_top;
                                                                                                    Value v_item = alg_iterable_at(loop_44, at_44);
                                                                                                    (void)v_item;
                                                                                                    alg_root(&v_item, 1);
                                                                                                    (void)(alg_hold(alg_invoke(v_theset, "Invoke", (Value[]){alg_literal("add"), alg_hold(alg_list_keep(alg_list(), v_item))}, 2)));
                                                                                                    alg_root_top = rt_829;
                                                                                                }
                                                                                                alg_root_top = rt_828;
                                                                                            }
                                                                                            alg_hold_top = rh_827;
                                                                                            alg_root_top = rt_826;
                                                                                        }
                                                                                    }
                                                                                    alg_hold_top = rh_825;
                                                                                    Value ret_45 = v_theset;
                                                                                    alg_root_top = rt_base;
                                                                                    return ret_45;
                                                                                    alg_hold_top = rh_825;
                                                                                    alg_root_top = rt_824;
                                                                                }
                                                                            } else {
                                                                                if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Write"))))) {
                                                                                    {
                                                                                        int32_t rh_830 = alg_hold_top;
                                                                                        if (alg_truthy(alg_hold(alg_not((alg_declared(d_outputsuppressed, "OutputSuppressed"), v_outputsuppressed))))) {
                                                                                            (void)(alg_write(alg_hold(f_rendered(NULL, (Value[]){v_theinterpreter, v_arguments}, 2))));
                                                                                        }
                                                                                        alg_hold_top = rh_830;
                                                                                        Value ret_46 = alg_nil();
                                                                                        alg_root_top = rt_base;
                                                                                        return ret_46;
                                                                                        alg_hold_top = rh_830;
                                                                                    }
                                                                                } else {
                                                                                    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("WriteLn"))))) {
                                                                                        {
                                                                                            int32_t rh_831 = alg_hold_top;
                                                                                            if (alg_truthy(alg_hold(alg_not((alg_declared(d_outputsuppressed, "OutputSuppressed"), v_outputsuppressed))))) {
                                                                                                (void)(alg_writeln(alg_hold(f_rendered(NULL, (Value[]){v_theinterpreter, v_arguments}, 2))));
                                                                                            }
                                                                                            alg_hold_top = rh_831;
                                                                                            Value ret_47 = alg_nil();
                                                                                            alg_root_top = rt_base;
                                                                                            return ret_47;
                                                                                            alg_hold_top = rh_831;
                                                                                        }
                                                                                    } else {
                                                                                        if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("ErrorLn"))))) {
                                                                                            {
                                                                                                int32_t rh_832 = alg_hold_top;
                                                                                                if (alg_truthy(alg_hold(alg_not((alg_declared(d_outputsuppressed, "OutputSuppressed"), v_outputsuppressed))))) {
                                                                                                    (void)(alg_stderr_line(alg_hold(f_rendered(NULL, (Value[]){v_theinterpreter, v_arguments}, 2))));
                                                                                                }
                                                                                                alg_hold_top = rh_832;
                                                                                                Value ret_48 = alg_nil();
                                                                                                alg_root_top = rt_base;
                                                                                                return ret_48;
                                                                                                alg_hold_top = rh_832;
                                                                                            }
                                                                                        } else {
                                                                                            if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Halt"))))) {
                                                                                                {
                                                                                                    int32_t rh_833 = alg_hold_top;
                                                                                                    (void)(alg_halt(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))));
                                                                                                    alg_hold_top = rh_833;
                                                                                                    Value ret_49 = alg_nil();
                                                                                                    alg_root_top = rt_base;
                                                                                                    return ret_49;
                                                                                                    alg_hold_top = rh_833;
                                                                                                }
                                                                                            } else {
                                                                                                if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Foreign"))))) {
                                                                                                    Value ret_50 = alg_hold(alg_foreign_call(alg_hold(alg_subscript_get(v_arguments, alg_int(0))), alg_hold(alg_subscript_get(v_arguments, alg_int(1))), alg_hold(alg_subscript_get(v_arguments, alg_int(2))), alg_hold(alg_subscript_get(v_arguments, alg_int(3))), alg_hold(alg_subscript_get(v_arguments, alg_int(4)))));
                                                                                                    alg_root_top = rt_base;
                                                                                                    return ret_50;
                                                                                                } else {
                                                                                                    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Succ"))))) {
                                                                                                        Value ret_51 = alg_hold(alg_succ(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))));
                                                                                                        alg_root_top = rt_base;
                                                                                                        return ret_51;
                                                                                                    } else {
                                                                                                        if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Pred"))))) {
                                                                                                            Value ret_52 = alg_hold(alg_pred(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))));
                                                                                                            alg_root_top = rt_base;
                                                                                                            return ret_52;
                                                                                                        } else {
                                                                                                            if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Ord"))))) {
                                                                                                                {
                                                                                                                    int32_t rh_834 = alg_hold_top;
                                                                                                                    if (alg_truthy(alg_is_class(alg_hold(alg_subscript_get(v_arguments, alg_int(0))), k_objenum))) {
                                                                                                                        Value ret_53 = alg_hold(alg_property(alg_hold(alg_subscript_get(v_arguments, alg_int(0))), "Ordinal"));
                                                                                                                        alg_root_top = rt_base;
                                                                                                                        return ret_53;
                                                                                                                    }
                                                                                                                    alg_hold_top = rh_834;
                                                                                                                    Value ret_54 = alg_hold(alg_ord(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))));
                                                                                                                    alg_root_top = rt_base;
                                                                                                                    return ret_54;
                                                                                                                    alg_hold_top = rh_834;
                                                                                                                }
                                                                                                            } else {
                                                                                                                if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Val"))))) {
                                                                                                                    Value ret_55 = alg_hold(f_parsednumber(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))))}, 1));
                                                                                                                    alg_root_top = rt_base;
                                                                                                                    return ret_55;
                                                                                                                } else {
                                                                                                                    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Char"))))) {
                                                                                                                        Value ret_56 = alg_hold(alg_char(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))));
                                                                                                                        alg_root_top = rt_base;
                                                                                                                        return ret_56;
                                                                                                                    } else {
                                                                                                                        if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("TextFile"))))) {
                                                                                                                            Value ret_57 = alg_hold(alg_new(k_objfile, NULL, 0));
                                                                                                                            alg_root_top = rt_base;
                                                                                                                            return ret_57;
                                                                                                                        } else {
                                                                                                                            if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("FileExists"))))) {
                                                                                                                                Value ret_58 = alg_hold(alg_file_exists(alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))))));
                                                                                                                                alg_root_top = rt_base;
                                                                                                                                return ret_58;
                                                                                                                            } else {
                                                                                                                                if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("MkDir"))))) {
                                                                                                                                    Value ret_59 = alg_hold(alg_mkdir(alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))))));
                                                                                                                                    alg_root_top = rt_base;
                                                                                                                                    return ret_59;
                                                                                                                                } else {
                                                                                                                                    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("RmDir"))))) {
                                                                                                                                        Value ret_60 = alg_hold(alg_rmdir(alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))))));
                                                                                                                                        alg_root_top = rt_base;
                                                                                                                                        return ret_60;
                                                                                                                                    } else {
                                                                                                                                        if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("ChDir"))))) {
                                                                                                                                            Value ret_61 = alg_hold(alg_chdir(alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))))));
                                                                                                                                            alg_root_top = rt_base;
                                                                                                                                            return ret_61;
                                                                                                                                        } else {
                                                                                                                                            if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("GetDir"))))) {
                                                                                                                                                Value ret_62 = alg_hold(alg_getdir());
                                                                                                                                                alg_root_top = rt_base;
                                                                                                                                                return ret_62;
                                                                                                                                            } else {
                                                                                                                                                if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Buffer"))))) {
                                                                                                                                                    {
                                                                                                                                                        int32_t rh_835 = alg_hold_top;
                                                                                                                                                        if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(v_arguments, "Length")), alg_int(1))))) {
                                                                                                                                                            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expected 0 or 1 arguments but got "), alg_hold(alg_str(alg_hold(alg_property(v_arguments, "Length")))))), alg_char_value(46))));
                                                                                                                                                        }
                                                                                                                                                        alg_hold_top = rh_835;
                                                                                                                                                        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(0))))) {
                                                                                                                                                            Value ret_63 = alg_hold(alg_new(k_objbuffer, (Value[]){alg_int(0)}, 1));
                                                                                                                                                            alg_root_top = rt_base;
                                                                                                                                                            return ret_63;
                                                                                                                                                        }
                                                                                                                                                        alg_hold_top = rh_835;
                                                                                                                                                        Value ret_64 = alg_hold(alg_new(k_objbuffer, (Value[]){alg_hold(alg_subscript_get(v_arguments, alg_int(0)))}, 1));
                                                                                                                                                        alg_root_top = rt_base;
                                                                                                                                                        return ret_64;
                                                                                                                                                        alg_hold_top = rh_835;
                                                                                                                                                    }
                                                                                                                                                } else {
                                                                                                                                                    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("ParamCount"))))) {
                                                                                                                                                        Value ret_65 = alg_hold(alg_subtract(alg_hold(alg_property((alg_declared(d_programarguments, "ProgramArguments"), v_programarguments), "Length")), alg_int(1)));
                                                                                                                                                        alg_root_top = rt_base;
                                                                                                                                                        return ret_65;
                                                                                                                                                    } else {
                                                                                                                                                        if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("ParamStr"))))) {
                                                                                                                                                            {
                                                                                                                                                                int32_t rt_836 = alg_root_top;
                                                                                                                                                                int32_t rh_837 = alg_hold_top;
                                                                                                                                                                Value v_at = alg_hold(alg_cast_kind(alg_subscript_get(v_arguments, alg_int(0)), ALG_KIND_INTEGER, "Integer"));
                                                                                                                                                                (void)v_at;
                                                                                                                                                                alg_root(&v_at, 1);
                                                                                                                                                                alg_hold_top = rh_837;
                                                                                                                                                                if (alg_truthy(alg_hold((or_7 = alg_hold(alg_less(v_at, alg_int(0))), alg_truthy(or_7) ? or_7 : alg_hold(alg_greater_equal(v_at, alg_hold(alg_property((alg_declared(d_programarguments, "ProgramArguments"), v_programarguments), "Length")))))))) {
                                                                                                                                                                    Value ret_66 = alg_literal("");
                                                                                                                                                                    alg_root_top = rt_base;
                                                                                                                                                                    return ret_66;
                                                                                                                                                                }
                                                                                                                                                                alg_hold_top = rh_837;
                                                                                                                                                                Value ret_67 = alg_hold(alg_subscript_get((alg_declared(d_programarguments, "ProgramArguments"), v_programarguments), v_at));
                                                                                                                                                                alg_root_top = rt_base;
                                                                                                                                                                return ret_67;
                                                                                                                                                                alg_hold_top = rh_837;
                                                                                                                                                                alg_root_top = rt_836;
                                                                                                                                                            }
                                                                                                                                                        } else {
                                                                                                                                                            if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("AssertTrue"))))) {
                                                                                                                                                                {
                                                                                                                                                                    int32_t rh_838 = alg_hold_top;
                                                                                                                                                                    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_theinterpreter, "IsTruthy", (Value[]){alg_hold(alg_subscript_get(v_arguments, alg_int(0)))}, 1)))))) {
                                                                                                                                                                        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Assertion failed.  Expected true but got '"), alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0))))))), alg_literal("'."))));
                                                                                                                                                                    }
                                                                                                                                                                    alg_hold_top = rh_838;
                                                                                                                                                                    Value ret_68 = alg_nil();
                                                                                                                                                                    alg_root_top = rt_base;
                                                                                                                                                                    return ret_68;
                                                                                                                                                                    alg_hold_top = rh_838;
                                                                                                                                                                }
                                                                                                                                                            } else {
                                                                                                                                                                if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("AssertEqual"))))) {
                                                                                                                                                                    {
                                                                                                                                                                        int32_t rh_839 = alg_hold_top;
                                                                                                                                                                        if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_theinterpreter, "IsEqual", (Value[]){alg_hold(alg_subscript_get(v_arguments, alg_int(0))), alg_hold(alg_subscript_get(v_arguments, alg_int(1)))}, 2)))))) {
                                                                                                                                                                            {
                                                                                                                                                                                int32_t rt_840 = alg_root_top;
                                                                                                                                                                                int32_t rh_841 = alg_hold_top;
                                                                                                                                                                                Value v_left = alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0)))));
                                                                                                                                                                                (void)v_left;
                                                                                                                                                                                alg_root(&v_left, 1);
                                                                                                                                                                                alg_hold_top = rh_841;
                                                                                                                                                                                Value v_right = alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(1)))));
                                                                                                                                                                                (void)v_right;
                                                                                                                                                                                alg_root(&v_right, 1);
                                                                                                                                                                                alg_hold_top = rh_841;
                                                                                                                                                                                if (alg_truthy(alg_hold(alg_equal(v_left, v_right)))) {
                                                                                                                                                                                    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Assertion failed.  Expected "), alg_hold(f_typenameof(NULL, (Value[]){alg_hold(alg_subscript_get(v_arguments, alg_int(0)))}, 1)))), alg_literal(" '"))), v_left)), alg_literal("' but got "))), alg_hold(f_typenameof(NULL, (Value[]){alg_hold(alg_subscript_get(v_arguments, alg_int(1)))}, 1)))), alg_literal(" '"))), v_right)), alg_literal("'."))));
                                                                                                                                                                                }
                                                                                                                                                                                alg_hold_top = rh_841;
                                                                                                                                                                                alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Assertion failed.  Expected '"), v_left)), alg_literal("' but got '"))), v_right)), alg_literal("'."))));
                                                                                                                                                                                alg_hold_top = rh_841;
                                                                                                                                                                                alg_root_top = rt_840;
                                                                                                                                                                            }
                                                                                                                                                                        }
                                                                                                                                                                        alg_hold_top = rh_839;
                                                                                                                                                                        Value ret_69 = alg_nil();
                                                                                                                                                                        alg_root_top = rt_base;
                                                                                                                                                                        return ret_69;
                                                                                                                                                                        alg_hold_top = rh_839;
                                                                                                                                                                    }
                                                                                                                                                                } else {
                                                                                                                                                                    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Name"), alg_literal("Fail"))))) {
                                                                                                                                                                        alg_raise(alg_hold(alg_add(alg_literal("Failed.  "), alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0))))))));
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
                            }
                        }
                    }
                }
            }
        }
    }
    alg_hold_top = rh_800;
    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined built-in '"), alg_property(v_this, "Name"))), alg_literal("'."))));
    alg_hold_top = rh_800;
    Value ret_70 = alg_nil();
    alg_root_top = rt_base;
    return ret_70;
}

Value f_parsednumber(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_text = alg_param_of(args[0], "String", "ParsedNumber");
    (void)v_text;
    alg_root(&v_text, 1);
    int32_t rh_842 = alg_hold_top;
    Value v_digits = alg_nil();
    (void)v_digits;
    alg_root(&v_digits, 1);
    alg_hold_top = rh_842;
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_842;
    Value v_sign = alg_nil();
    (void)v_sign;
    alg_root(&v_sign, 1);
    alg_hold_top = rh_842;
    Value v_asdouble = alg_hold(alg_val(v_text));
    (void)v_asdouble;
    alg_root(&v_asdouble, 1);
    alg_hold_top = rh_842;
    (void)((v_sign = alg_int(1)));
    alg_hold_top = rh_842;
    (void)((v_digits = v_text));
    alg_hold_top = rh_842;
    if (alg_truthy(alg_hold((or_8 = alg_hold(alg_greater(alg_hold(alg_text_length(v_digits)), alg_int(0))), !alg_truthy(or_8) ? or_8 : alg_hold(alg_equal(alg_hold(alg_subscript_get(v_digits, alg_int(0))), alg_char_value(45))))))) {
        {
            int32_t rh_843 = alg_hold_top;
            (void)((v_sign = alg_hold(alg_negate(alg_int(1)))));
            alg_hold_top = rh_843;
            (void)((v_digits = alg_hold(alg_copy(v_digits, alg_int(1), alg_hold(alg_subtract(alg_hold(alg_text_length(v_digits)), alg_int(1)))))));
            alg_hold_top = rh_843;
        }
    }
    alg_hold_top = rh_842;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_text_length(v_digits)), alg_int(0))))) {
        Value ret_71 = v_asdouble;
        alg_root_top = rt_base;
        return ret_71;
    }
    alg_hold_top = rh_842;
    (void)((v_result = alg_int(0)));
    alg_hold_top = rh_842;
    {
        int32_t rt_844 = alg_root_top;
        int32_t rh_845 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_845;
        {
            int32_t rh_846 = alg_hold_top;
            for (; (alg_hold_top = rh_846, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_text_length(v_digits)))))); (alg_hold_top = rh_846, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_847 = alg_root_top;
                    int32_t rh_848 = alg_hold_top;
                    Value v_c = alg_hold(alg_subscript_get(v_digits, v_i));
                    (void)v_c;
                    alg_root(&v_c, 1);
                    alg_hold_top = rh_848;
                    if (alg_truthy(alg_hold((or_9 = alg_hold(alg_less(v_c, alg_char_value(48))), alg_truthy(or_9) ? or_9 : alg_hold(alg_greater(v_c, alg_char_value(57))))))) {
                        Value ret_72 = v_asdouble;
                        alg_root_top = rt_base;
                        return ret_72;
                    }
                    alg_hold_top = rh_848;
                    (void)((v_result = alg_hold(alg_add(alg_hold(alg_multiply(v_result, alg_int(10))), (alg_hold(alg_subtract(alg_hold(alg_ord(v_c)), alg_hold(alg_ord(alg_char_value(48))))))))));
                    alg_hold_top = rh_848;
                    alg_root_top = rt_847;
                }
            }
        }
        alg_hold_top = rh_845;
        alg_root_top = rt_844;
    }
    alg_hold_top = rh_842;
    Value ret_73 = alg_hold(alg_multiply(v_sign, v_result));
    alg_root_top = rt_base;
    return ret_73;
    alg_hold_top = rh_842;
    Value ret_74 = alg_nil();
    alg_root_top = rt_base;
    return ret_74;
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
    int32_t rh_849 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Builtins", alg_hold(alg_new(k_environment, NULL, 0)))));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_set_property(v_this, "Globals", alg_hold(alg_new(k_environment, NULL, 0)))));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_set_property(alg_hold(alg_property(v_this, "Globals")), "Enclosing", alg_property(v_this, "Builtins"))));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_set_property(v_this, "Locals", alg_hold(alg_map()))));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_set_property(v_this, "Modules", alg_hold(alg_map()))));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_set_property(v_this, "RootFile", alg_literal(""))));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_set_property(v_this, "HoistedClasses", alg_hold(alg_set()))));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_set_property(v_this, "UnitsByName", alg_hold(alg_map()))));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_set_property(v_this, "Env", alg_property(v_this, "Globals"))));
    alg_hold_top = rh_849;
    (void)(alg_hold(f_setinstanceshown(NULL, (Value[]){alg_hold(alg_property(v_this, "Shown"))}, 1)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("clock"), alg_hold(alg_new(k_native, (Value[]){alg_literal("clock"), alg_int(0)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Collect"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Collect"), alg_int(0)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Fields"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Fields"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("TypeOf"), alg_hold(alg_new(k_native, (Value[]){alg_literal("TypeOf"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Member"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Member"), alg_int(2)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Invoke"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Invoke"), alg_int(3)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("New"), alg_hold(alg_new(k_native, (Value[]){alg_literal("New"), alg_int(2)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("SetMember"), alg_hold(alg_new(k_native, (Value[]){alg_literal("SetMember"), alg_int(3)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Length"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Length"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Copy"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Copy"), alg_int(3)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Pos"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Pos"), alg_hold(alg_negate(alg_int(1)))}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("ToUpper"), alg_hold(alg_new(k_native, (Value[]){alg_literal("ToUpper"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("ToLower"), alg_hold(alg_new(k_native, (Value[]){alg_literal("ToLower"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Str"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Str"), alg_hold(alg_negate(alg_int(1)))}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Array"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Array"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("List"), alg_hold(alg_new(k_native, (Value[]){alg_literal("List"), alg_int(0)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Map"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Map"), alg_int(0)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Set"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Set"), alg_hold(alg_negate(alg_int(1)))}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Stack"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Stack"), alg_int(0)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Halt"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Halt"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Ord"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Ord"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Succ"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Succ"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Pred"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Pred"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Foreign"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Foreign"), alg_int(5)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Val"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Val"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Char"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Char"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Write"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Write"), alg_hold(alg_negate(alg_int(1)))}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("WriteLn"), alg_hold(alg_new(k_native, (Value[]){alg_literal("WriteLn"), alg_hold(alg_negate(alg_int(1)))}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("ErrorLn"), alg_hold(alg_new(k_native, (Value[]){alg_literal("ErrorLn"), alg_hold(alg_negate(alg_int(1)))}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Buffer"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Buffer"), alg_hold(alg_negate(alg_int(1)))}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("TextFile"), alg_hold(alg_new(k_native, (Value[]){alg_literal("TextFile"), alg_int(0)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("FileExists"), alg_hold(alg_new(k_native, (Value[]){alg_literal("FileExists"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("MkDir"), alg_hold(alg_new(k_native, (Value[]){alg_literal("MkDir"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("RmDir"), alg_hold(alg_new(k_native, (Value[]){alg_literal("RmDir"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("ChDir"), alg_hold(alg_new(k_native, (Value[]){alg_literal("ChDir"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("GetDir"), alg_hold(alg_new(k_native, (Value[]){alg_literal("GetDir"), alg_int(0)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("ParamCount"), alg_hold(alg_new(k_native, (Value[]){alg_literal("ParamCount"), alg_int(0)}, 2))}, 2)));
    alg_hold_top = rh_849;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("ParamStr"), alg_hold(alg_new(k_native, (Value[]){alg_literal("ParamStr"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_849;
    Value ret_75 = alg_nil();
    alg_root_top = rt_base;
    return ret_75;
}

static Value m_interpreter_hoist_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_850 = alg_hold_top;
    Value v_names = alg_hold(alg_set());
    (void)v_names;
    alg_root(&v_names, 1);
    alg_hold_top = rh_850;
    {
        int32_t rt_851 = alg_root_top;
        int32_t rh_852 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_852;
        {
            int32_t rh_853 = alg_hold_top;
            for (; (alg_hold_top = rh_853, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_statements, "Length")))))); (alg_hold_top = rh_853, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_is_class(alg_hold(alg_subscript_get(v_statements, v_i)), k_classstmt))) {
                    (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_subscript_get(v_statements, v_i)), "Name")), "Lexeme"))}, 1))}, 1)));
                }
            }
        }
        alg_hold_top = rh_852;
        alg_root_top = rt_851;
    }
    alg_hold_top = rh_850;
    {
        int32_t rt_854 = alg_root_top;
        int32_t rh_855 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_855;
        {
            int32_t rh_856 = alg_hold_top;
            for (; (alg_hold_top = rh_856, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_statements, "Length")))))); (alg_hold_top = rh_856, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_is_class(alg_hold(alg_subscript_get(v_statements, v_i)), k_classstmt))) {
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_subscript_get(v_statements, v_i)), "Name")), "Lexeme")), alg_hold(alg_new(k_objclass, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_subscript_get(v_statements, v_i)), "Name")), "Lexeme")))), alg_nil(), alg_hold(alg_map()), alg_hold(alg_list())}, 4))}, 2)));
                }
            }
        }
        alg_hold_top = rh_855;
        alg_root_top = rt_854;
    }
    alg_hold_top = rh_850;
    {
        int32_t rt_857 = alg_root_top;
        int32_t rh_858 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_858;
        {
            int32_t rh_859 = alg_hold_top;
            for (; (alg_hold_top = rh_859, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_statements, "Length")))))); (alg_hold_top = rh_859, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_is_class(alg_hold(alg_subscript_get(v_statements, v_i)), k_classstmt))) {
                    {
                        int32_t rt_860 = alg_root_top;
                        int32_t rh_861 = alg_hold_top;
                        Value v_parent = alg_hold(alg_property(alg_hold(alg_subscript_get(v_statements, v_i)), "Superclass"));
                        (void)v_parent;
                        alg_root(&v_parent, 1);
                        alg_hold_top = rh_861;
                        Value v_ready = alg_hold(alg_equal(v_parent, alg_nil()));
                        (void)v_ready;
                        alg_root(&v_ready, 1);
                        alg_hold_top = rh_861;
                        if (alg_truthy(alg_hold(alg_not(v_ready)))) {
                            (void)((v_ready = alg_hold(alg_invoke(v_names, "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_parent, "Name")), "Lexeme"))}, 1))}, 1))));
                        }
                        alg_hold_top = rh_861;
                        if (alg_truthy(v_ready)) {
                            {
                                int32_t rh_862 = alg_hold_top;
                                (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_subscript_get(v_statements, v_i))}, 1)));
                                alg_hold_top = rh_862;
                                (void)(alg_hold(alg_invoke(alg_property(v_this, "HoistedClasses"), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_subscript_get(v_statements, v_i)), "Name")), "Lexeme"))}, 1))}, 1)));
                                alg_hold_top = rh_862;
                            }
                        }
                        alg_hold_top = rh_861;
                        alg_root_top = rt_860;
                    }
                }
            }
        }
        alg_hold_top = rh_858;
        alg_root_top = rt_857;
    }
    alg_hold_top = rh_850;
    {
        int32_t rt_863 = alg_root_top;
        int32_t rh_864 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_864;
        {
            int32_t rh_865 = alg_hold_top;
            for (; (alg_hold_top = rh_865, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_statements, "Length")))))); (alg_hold_top = rh_865, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_is_class(alg_hold(alg_subscript_get(v_statements, v_i)), k_functionstmt))) {
                    (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_subscript_get(v_statements, v_i))}, 1)));
                }
            }
        }
        alg_hold_top = rh_864;
        alg_root_top = rt_863;
    }
    alg_hold_top = rh_850;
    Value ret_76 = alg_nil();
    alg_root_top = rt_base;
    return ret_76;
}

static Value m_interpreter_hoistedclass_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_866 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Env"), "Values")), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))))) {
        Value ret_77 = alg_nil();
        alg_root_top = rt_base;
        return ret_77;
    }
    alg_hold_top = rh_866;
    Value v_bound = alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Env"), "Values")), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1));
    (void)v_bound;
    alg_root(&v_bound, 1);
    alg_hold_top = rh_866;
    if (alg_truthy(alg_hold(alg_not((alg_is_class(v_bound, k_objclass)))))) {
        Value ret_78 = alg_nil();
        alg_root_top = rt_base;
        return ret_78;
    }
    alg_hold_top = rh_866;
    Value ret_79 = v_bound;
    alg_root_top = rt_base;
    return ret_79;
    alg_hold_top = rh_866;
    Value ret_80 = alg_nil();
    alg_root_top = rt_base;
    return ret_80;
}

static Value m_interpreter_registerroot_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_867 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "RootFile"), alg_literal(""))))) {
        Value ret_81 = alg_nil();
        alg_root_top = rt_base;
        return ret_81;
    }
    alg_hold_top = rh_867;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Modules"), "Put", (Value[]){alg_property(v_this, "RootFile"), alg_property(v_this, "Globals")}, 2)));
    alg_hold_top = rh_867;
    Value ret_82 = alg_nil();
    alg_root_top = rt_base;
    return ret_82;
}

static Value m_interpreter_interpret_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_868 = alg_hold_top;
    {
        AlgFrame frame_83;
        alg_push_frame(&frame_83);
        if (ALG_SETJMP(frame_83.jump) == 0) {
            {
                int32_t rt_869 = alg_root_top;
                int32_t rh_870 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_this, "RegisterRoot", NULL, 0)));
                alg_hold_top = rh_870;
                (void)(alg_hold(alg_invoke(v_this, "Hoist", (Value[]){v_statements}, 1)));
                alg_hold_top = rh_870;
                volatile Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_870;
                {
                    int32_t rh_871 = alg_hold_top;
                    while ((alg_hold_top = rh_871, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_statements, "Length"))))))) {
                        alg_safe_point();
                        {
                            int32_t rt_872 = alg_root_top;
                            int32_t rh_873 = alg_hold_top;
                            volatile Value v_done = alg_is_class(alg_hold(alg_subscript_get(v_statements, v_i)), k_functionstmt);
                            (void)v_done;
                            alg_root(&v_done, 1);
                            alg_hold_top = rh_873;
                            if (alg_truthy(alg_is_class(alg_hold(alg_subscript_get(v_statements, v_i)), k_classstmt))) {
                                (void)((v_done = alg_hold(alg_invoke(alg_property(v_this, "HoistedClasses"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_subscript_get(v_statements, v_i)), "Name")), "Lexeme"))}, 1))}, 1))));
                            }
                            alg_hold_top = rh_873;
                            {
                                AlgFrame frame_84;
                                alg_push_frame(&frame_84);
                                if (ALG_SETJMP(frame_84.jump) == 0) {
                                    {
                                        int32_t rh_874 = alg_hold_top;
                                        if (alg_truthy(alg_hold(alg_not(v_done)))) {
                                            (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_subscript_get(v_statements, v_i))}, 1)));
                                        }
                                        alg_hold_top = rh_874;
                                        (void)((v_i = alg_hold(alg_add(v_i, alg_int(1)))));
                                        alg_hold_top = rh_874;
                                    }
                                    alg_pop_frame();
                                }
                                else {
                                    static const char *names_84[] = {"Jumped"};
                                    int32_t which_84 = alg_handler(frame_84.raised, names_84, 1);
                                    if (which_84 == 0) {
                                        {
                                            int32_t rt_875 = alg_root_top;
                                            volatile Value v_g = frame_84.raised;
                                            (void)v_g;
                                            alg_root(&v_g, 1);
                                            {
                                                int32_t rt_876 = alg_root_top;
                                                int32_t rh_877 = alg_hold_top;
                                                volatile Value v_at = alg_hold(f_labelat(NULL, (Value[]){v_statements, alg_hold(alg_property(v_g, "Label"))}, 2));
                                                (void)v_at;
                                                alg_root(&v_at, 1);
                                                alg_hold_top = rh_877;
                                                if (alg_truthy(alg_hold(alg_less(v_at, alg_int(0))))) {
                                                    alg_raise(v_g);
                                                }
                                                alg_hold_top = rh_877;
                                                (void)((v_i = v_at));
                                                alg_hold_top = rh_877;
                                                alg_root_top = rt_876;
                                            }
                                            alg_root_top = rt_875;
                                        }
                                    }
                                    else {
                                        alg_raise(frame_84.raised);
                                    }
                                }
                            }
                            alg_hold_top = rh_873;
                            alg_root_top = rt_872;
                        }
                    }
                }
                alg_hold_top = rh_870;
                alg_root_top = rt_869;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_83[] = {"Raised"};
            int32_t which_83 = alg_handler(frame_83.raised, names_83, 1);
            if (which_83 == 0) {
                {
                    int32_t rt_878 = alg_root_top;
                    volatile Value v_e = frame_83.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    alg_raise(alg_hold(alg_str(alg_hold(alg_property(v_e, "Value")))));
                    alg_root_top = rt_878;
                }
            }
            else {
                alg_raise(frame_83.raised);
            }
        }
    }
    alg_hold_top = rh_868;
    volatile Value ret_85 = alg_nil();
    alg_root_top = rt_base;
    return ret_85;
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
    int32_t rh_879 = alg_hold_top;
    {
        int32_t rt_880 = alg_root_top;
        Value loop_86 = alg_iterable(v_statements);
        (void)loop_86;
        alg_root(&loop_86, 1);
        for (int32_t at_86 = 0; at_86 < alg_iterable_count(loop_86); at_86++) {
            alg_safe_point();
            int32_t rt_881 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_86, at_86);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rh_882 = alg_hold_top;
                if (alg_truthy(alg_is_class(v_thestmt, k_modulestmt))) {
                    {
                        int32_t rh_883 = alg_hold_top;
                        if (alg_truthy(v_define)) {
                            (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1)));
                        }
                        alg_hold_top = rh_883;
                        if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Statements")), alg_nil())))) {
                            {
                                int32_t rt_884 = alg_root_top;
                                int32_t rh_885 = alg_hold_top;
                                Value v_mine = alg_hold(alg_not(alg_hold(alg_invoke(v_hoisted, "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "FileName"))))}, 1))));
                                (void)v_mine;
                                alg_root(&v_mine, 1);
                                alg_hold_top = rh_885;
                                if (alg_truthy(v_mine)) {
                                    (void)(alg_hold(alg_invoke(v_hoisted, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "FileName"))))}, 1)));
                                }
                                alg_hold_top = rh_885;
                                (void)(alg_hold(alg_invoke(v_this, "HoistTests", (Value[]){alg_hold(alg_property(v_thestmt, "Statements")), v_tests, v_byname, alg_bool(false), alg_hold(alg_cast_class(alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_hold(alg_property(v_thestmt, "FileName"))}, 1), k_environment, "Environment")), v_declaredin, alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "FileName")))), v_files, v_byfile, v_hoisted, v_mine}, 11)));
                                alg_hold_top = rh_885;
                                alg_root_top = rt_884;
                            }
                        }
                        alg_hold_top = rh_883;
                    }
                } else {
                    if (alg_truthy(alg_is_class(v_thestmt, k_functionstmt))) {
                        {
                            int32_t rh_886 = alg_hold_top;
                            if (alg_truthy(v_define)) {
                                (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1)));
                            }
                            alg_hold_top = rh_886;
                            if (alg_truthy(alg_hold((or_10 = alg_hold(alg_not_equal(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Literal")), alg_nil())), !alg_truthy(or_10) ? or_10 : v_collect)))) {
                                {
                                    int32_t rh_887 = alg_hold_top;
                                    (void)(alg_hold(alg_invoke(v_tests, "Add", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1)));
                                    alg_hold_top = rh_887;
                                    (void)(alg_hold(alg_invoke(v_byname, "Put", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), v_thestmt}, 2)));
                                    alg_hold_top = rh_887;
                                    (void)(alg_hold(alg_invoke(v_declaredin, "Put", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), v_scope}, 2)));
                                    alg_hold_top = rh_887;
                                    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_files, "Contains", (Value[]){v_file}, 1)))))) {
                                        {
                                            int32_t rh_888 = alg_hold_top;
                                            (void)(alg_hold(alg_invoke(v_files, "Add", (Value[]){v_file}, 1)));
                                            alg_hold_top = rh_888;
                                            (void)(alg_hold(alg_invoke(v_byfile, "Put", (Value[]){v_file, alg_hold(alg_list())}, 2)));
                                            alg_hold_top = rh_888;
                                        }
                                    }
                                    alg_hold_top = rh_887;
                                    (void)(alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(v_byfile, "Get", (Value[]){v_file}, 1), ALG_KIND_LIST, "List"))), "Add", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1)));
                                    alg_hold_top = rh_887;
                                }
                            }
                            alg_hold_top = rh_886;
                        }
                    } else {
                        if (alg_truthy(alg_hold((or_15 = v_define, !alg_truthy(or_15) ? or_15 : (alg_hold((or_14 = alg_hold((or_13 = alg_hold((or_12 = alg_hold((or_11 = alg_is_class(v_thestmt, k_classstmt), alg_truthy(or_11) ? or_11 : alg_is_class(v_thestmt, k_objectstmt))), alg_truthy(or_12) ? or_12 : alg_is_class(v_thestmt, k_enumstmt))), alg_truthy(or_13) ? or_13 : alg_is_class(v_thestmt, k_vargroupstmt))), alg_truthy(or_14) ? or_14 : alg_is_class(v_thestmt, k_varstmt)))))))) {
                            (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1)));
                        }
                    }
                }
                alg_hold_top = rh_882;
            }
            alg_root_top = rt_881;
        }
        alg_root_top = rt_880;
    }
    alg_hold_top = rh_879;
    Value ret_87 = alg_nil();
    alg_root_top = rt_base;
    return ret_87;
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
    int32_t rh_889 = alg_hold_top;
    volatile Value v_tests = alg_nil();
    (void)v_tests;
    alg_root(&v_tests, 1);
    alg_hold_top = rh_889;
    volatile Value v_passed = alg_nil();
    (void)v_passed;
    alg_root(&v_passed, 1);
    alg_hold_top = rh_889;
    volatile Value v_failed = alg_nil();
    (void)v_failed;
    alg_root(&v_failed, 1);
    alg_hold_top = rh_889;
    (void)(alg_set_property(v_this, "RootFile", alg_hold(alg_str(v_filename))));
    alg_hold_top = rh_889;
    (void)(alg_hold(alg_invoke(v_this, "RegisterRoot", NULL, 0)));
    alg_hold_top = rh_889;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("AssertTrue"), alg_hold(alg_new(k_native, (Value[]){alg_literal("AssertTrue"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_889;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("AssertEqual"), alg_hold(alg_new(k_native, (Value[]){alg_literal("AssertEqual"), alg_int(2)}, 2))}, 2)));
    alg_hold_top = rh_889;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Builtins"), "Define", (Value[]){alg_literal("Fail"), alg_hold(alg_new(k_native, (Value[]){alg_literal("Fail"), alg_int(1)}, 2))}, 2)));
    alg_hold_top = rh_889;
    (void)(alg_hold(f_suppressoutput(NULL, (Value[]){alg_bool(true)}, 1)));
    alg_hold_top = rh_889;
    (void)((v_tests = alg_hold(alg_list())));
    alg_hold_top = rh_889;
    volatile Value v_byname = alg_hold(alg_map());
    (void)v_byname;
    alg_root(&v_byname, 1);
    alg_hold_top = rh_889;
    volatile Value v_declaredin = alg_hold(alg_map());
    (void)v_declaredin;
    alg_root(&v_declaredin, 1);
    alg_hold_top = rh_889;
    volatile Value v_files = alg_hold(alg_list());
    (void)v_files;
    alg_root(&v_files, 1);
    alg_hold_top = rh_889;
    volatile Value v_byfile = alg_hold(alg_map());
    (void)v_byfile;
    alg_root(&v_byfile, 1);
    alg_hold_top = rh_889;
    volatile Value v_hoisted = alg_hold(alg_set());
    (void)v_hoisted;
    alg_root(&v_hoisted, 1);
    alg_hold_top = rh_889;
    (void)(alg_hold(alg_invoke(v_hoisted, "Add", (Value[]){v_filename}, 1)));
    alg_hold_top = rh_889;
    (void)(alg_hold(alg_invoke(v_this, "HoistTests", (Value[]){v_statements, v_tests, v_byname, alg_bool(true), alg_property(v_this, "Globals"), v_declaredin, v_filename, v_files, v_byfile, v_hoisted, alg_bool(true)}, 11)));
    alg_hold_top = rh_889;
    (void)(alg_writeln(alg_hold(f_testopening(NULL, (Value[]){alg_hold(alg_property(v_tests, "Length"))}, 1))));
    alg_hold_top = rh_889;
    (void)((v_passed = alg_int(0)));
    alg_hold_top = rh_889;
    (void)((v_failed = alg_int(0)));
    alg_hold_top = rh_889;
    volatile Value v_ordered = alg_hold(alg_list());
    (void)v_ordered;
    alg_root(&v_ordered, 1);
    alg_hold_top = rh_889;
    {
        int32_t rt_890 = alg_root_top;
        volatile Value loop_88 = alg_iterable(v_files);
        (void)loop_88;
        alg_root(&loop_88, 1);
        for (volatile int32_t at_88 = 0; at_88 < alg_iterable_count(loop_88); at_88++) {
            alg_safe_point();
            int32_t rt_891 = alg_root_top;
            volatile Value v_file = alg_iterable_at(loop_88, at_88);
            (void)v_file;
            alg_root(&v_file, 1);
            {
                int32_t rt_892 = alg_root_top;
                int32_t rh_893 = alg_hold_top;
                volatile Value v_group = alg_hold(alg_cast_kind(alg_invoke(v_byfile, "Get", (Value[]){v_file}, 1), ALG_KIND_LIST, "List"));
                (void)v_group;
                alg_root(&v_group, 1);
                alg_hold_top = rh_893;
                (void)(alg_hold(alg_invoke(v_group, "Sort", NULL, 0)));
                alg_hold_top = rh_893;
                (void)(alg_hold(alg_invoke(v_ordered, "Add", (Value[]){v_file}, 1)));
                alg_hold_top = rh_893;
                {
                    int32_t rt_894 = alg_root_top;
                    volatile Value loop_89 = alg_iterable(v_group);
                    (void)loop_89;
                    alg_root(&loop_89, 1);
                    for (volatile int32_t at_89 = 0; at_89 < alg_iterable_count(loop_89); at_89++) {
                        alg_safe_point();
                        int32_t rt_895 = alg_root_top;
                        volatile Value v_each = alg_iterable_at(loop_89, at_89);
                        (void)v_each;
                        alg_root(&v_each, 1);
                        (void)(alg_hold(alg_invoke(v_ordered, "Add", (Value[]){v_each}, 1)));
                        alg_root_top = rt_895;
                    }
                    alg_root_top = rt_894;
                }
                alg_hold_top = rh_893;
                alg_root_top = rt_892;
            }
            alg_root_top = rt_891;
        }
        alg_root_top = rt_890;
    }
    alg_hold_top = rh_889;
    {
        int32_t rt_896 = alg_root_top;
        int32_t rh_897 = alg_hold_top;
        volatile Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_897;
        {
            int32_t rh_898 = alg_hold_top;
            for (; (alg_hold_top = rh_898, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_ordered, "Length")))))); (alg_hold_top = rh_898, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_899 = alg_hold_top;
                    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_byname, "Contains", (Value[]){alg_hold(alg_subscript_get(v_ordered, v_i))}, 1)))))) {
                        {
                            int32_t rh_900 = alg_hold_top;
                            if (alg_truthy(alg_hold(alg_greater(v_i, alg_int(0))))) {
                                (void)(alg_writeln((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag)));
                            }
                            alg_hold_top = rh_900;
                            (void)(alg_writeln(alg_hold(f_testbanner(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_ordered, v_i))))}, 1))));
                            alg_hold_top = rh_900;
                        }
                    } else {
                        {
                            int32_t rt_901 = alg_root_top;
                            int32_t rh_902 = alg_hold_top;
                            volatile Value v_thetest = alg_hold(alg_invoke(v_byname, "Get", (Value[]){alg_hold(alg_subscript_get(v_ordered, v_i))}, 1));
                            (void)v_thetest;
                            alg_root(&v_thetest, 1);
                            alg_hold_top = rh_902;
                            volatile Value v_name = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thetest, "Name")), "Literal"))));
                            (void)v_name;
                            alg_root(&v_name, 1);
                            alg_hold_top = rh_902;
                            {
                                AlgFrame frame_90;
                                alg_push_frame(&frame_90);
                                if (ALG_SETJMP(frame_90.jump) == 0) {
                                    {
                                        int32_t rt_903 = alg_root_top;
                                        int32_t rh_904 = alg_hold_top;
                                        volatile Value v_scope = alg_property(v_this, "Globals");
                                        (void)v_scope;
                                        alg_root(&v_scope, 1);
                                        alg_hold_top = rh_904;
                                        if (alg_truthy(alg_hold(alg_invoke(v_declaredin, "Contains", (Value[]){alg_hold(alg_subscript_get(v_ordered, v_i))}, 1)))) {
                                            (void)((v_scope = alg_hold(alg_cast_class(alg_invoke(v_declaredin, "Get", (Value[]){alg_hold(alg_subscript_get(v_ordered, v_i))}, 1), k_environment, "Environment"))));
                                        }
                                        alg_hold_top = rh_904;
                                        volatile Value v_body = alg_hold(alg_invoke(v_scope, "Get", (Value[]){alg_hold(alg_property(v_thetest, "Name"))}, 1));
                                        (void)v_body;
                                        alg_root(&v_body, 1);
                                        alg_hold_top = rh_904;
                                        (void)(alg_hold(alg_invoke(v_body, "Call", (Value[]){v_this, alg_hold(alg_list())}, 2)));
                                        alg_hold_top = rh_904;
                                        (void)((v_passed = alg_hold(alg_add(v_passed, alg_int(1)))));
                                        alg_hold_top = rh_904;
                                        (void)(alg_writeln(alg_hold(f_testline(NULL, (Value[]){v_name, alg_literal("PASS")}, 2))));
                                        alg_hold_top = rh_904;
                                        alg_root_top = rt_903;
                                    }
                                    alg_pop_frame();
                                }
                                else {
                                    static const char *names_90[] = {"String", "Raised"};
                                    int32_t which_90 = alg_handler(frame_90.raised, names_90, 2);
                                    if (which_90 == 0) {
                                        {
                                            int32_t rt_905 = alg_root_top;
                                            volatile Value v_e = frame_90.raised;
                                            (void)v_e;
                                            alg_root(&v_e, 1);
                                            {
                                                int32_t rh_906 = alg_hold_top;
                                                (void)((v_failed = alg_hold(alg_add(v_failed, alg_int(1)))));
                                                alg_hold_top = rh_906;
                                                (void)(alg_writeln(alg_hold(f_testline(NULL, (Value[]){v_name, alg_literal("FAIL")}, 2))));
                                                alg_hold_top = rh_906;
                                                (void)(alg_writeln(alg_hold(f_testfailure(NULL, (Value[]){v_filename, v_e}, 2))));
                                                alg_hold_top = rh_906;
                                            }
                                            alg_root_top = rt_905;
                                        }
                                    }
                                    else if (which_90 == 1) {
                                        {
                                            int32_t rt_907 = alg_root_top;
                                            volatile Value v_e = frame_90.raised;
                                            (void)v_e;
                                            alg_root(&v_e, 1);
                                            {
                                                int32_t rh_908 = alg_hold_top;
                                                (void)((v_failed = alg_hold(alg_add(v_failed, alg_int(1)))));
                                                alg_hold_top = rh_908;
                                                (void)(alg_writeln(alg_hold(f_testline(NULL, (Value[]){v_name, alg_literal("FAIL")}, 2))));
                                                alg_hold_top = rh_908;
                                                (void)(alg_writeln(alg_hold(f_testfailure(NULL, (Value[]){v_filename, alg_hold(alg_str(alg_hold(alg_property(v_e, "Value"))))}, 2))));
                                                alg_hold_top = rh_908;
                                            }
                                            alg_root_top = rt_907;
                                        }
                                    }
                                    else {
                                        alg_raise(frame_90.raised);
                                    }
                                }
                            }
                            alg_hold_top = rh_902;
                            alg_root_top = rt_901;
                        }
                    }
                    alg_hold_top = rh_899;
                }
            }
        }
        alg_hold_top = rh_897;
        alg_root_top = rt_896;
    }
    alg_hold_top = rh_889;
    (void)(alg_writeln((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag)));
    alg_hold_top = rh_889;
    (void)(alg_writeln(alg_hold(f_testtotals(NULL, (Value[]){v_passed, v_failed}, 2))));
    alg_hold_top = rh_889;
    volatile Value ret_91 = v_failed;
    alg_root_top = rt_base;
    return ret_91;
    alg_hold_top = rh_889;
    volatile Value ret_92 = alg_nil();
    alg_root_top = rt_base;
    return ret_92;
}

static Value m_interpreter_visitliteral_1_literalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "LiteralExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_909 = alg_hold_top;
    Value ret_93 = alg_hold(alg_property(v_theexpr, "Value"));
    alg_root_top = rt_base;
    return ret_93;
    alg_hold_top = rh_909;
    Value ret_94 = alg_nil();
    alg_root_top = rt_base;
    return ret_94;
}

static Value m_interpreter_visitlogical_1_logicalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "LogicalExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_910 = alg_hold_top;
    Value v_left = alg_nil();
    (void)v_left;
    alg_root(&v_left, 1);
    alg_hold_top = rh_910;
    (void)((v_left = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Left"))}, 1))));
    alg_hold_top = rh_910;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVor)))) {
        {
            int32_t rh_911 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_invoke(v_this, "IsTruthy", (Value[]){v_left}, 1)))) {
                Value ret_95 = v_left;
                alg_root_top = rt_base;
                return ret_95;
            }
            alg_hold_top = rh_911;
        }
    } else {
        if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsTruthy", (Value[]){v_left}, 1)))))) {
            Value ret_96 = v_left;
            alg_root_top = rt_base;
            return ret_96;
        }
    }
    alg_hold_top = rh_910;
    Value ret_97 = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1));
    alg_root_top = rt_base;
    return ret_97;
    alg_hold_top = rh_910;
    Value ret_98 = alg_nil();
    alg_root_top = rt_base;
    return ret_98;
}

static Value m_interpreter_visitgrouping_1_groupingexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GroupingExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_912 = alg_hold_top;
    Value ret_99 = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Expression"))}, 1));
    alg_root_top = rt_base;
    return ret_99;
    alg_hold_top = rh_912;
    Value ret_100 = alg_nil();
    alg_root_top = rt_base;
    return ret_100;
}

static Value m_interpreter_visitunary_1_unaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "UnaryExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_913 = alg_hold_top;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_913;
    (void)((v_right = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1))));
    alg_hold_top = rh_913;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVminus)))) {
        {
            int32_t rh_914 = alg_hold_top;
            if (alg_truthy(alg_is_class(v_right, k_objinstance))) {
                {
                    int32_t rt_915 = alg_root_top;
                    int32_t rh_916 = alg_hold_top;
                    Value v_negate = alg_hold(alg_invoke(alg_hold(alg_property(v_right, "Klass")), "MethodOfArity", (Value[]){alg_char_value(45), alg_int(0)}, 2));
                    (void)v_negate;
                    alg_root(&v_negate, 1);
                    alg_hold_top = rh_916;
                    if (alg_truthy(alg_hold(alg_not_equal(v_negate, alg_nil())))) {
                        Value ret_101 = alg_hold(alg_invoke(alg_hold(alg_invoke(v_negate, "Bind", (Value[]){v_right}, 1)), "Call", (Value[]){v_this, alg_hold(alg_list())}, 2));
                        alg_root_top = rt_base;
                        return ret_101;
                    }
                    alg_hold_top = rh_916;
                    alg_root_top = rt_915;
                }
            }
            alg_hold_top = rh_914;
            Value ret_102 = alg_hold(alg_negate(v_right));
            alg_root_top = rt_base;
            return ret_102;
            alg_hold_top = rh_914;
        }
    } else {
        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVnot)))) {
            Value ret_103 = alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsTruthy", (Value[]){v_right}, 1))));
            alg_root_top = rt_base;
            return ret_103;
        } else {
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVtilde)))) {
                {
                    int32_t rh_917 = alg_hold_top;
                    if (alg_truthy(alg_is_class(v_right, k_objinstance))) {
                        {
                            int32_t rt_918 = alg_root_top;
                            int32_t rh_919 = alg_hold_top;
                            Value v_invert = alg_hold(alg_invoke(alg_hold(alg_property(v_right, "Klass")), "MethodOfArity", (Value[]){alg_char_value(126), alg_int(0)}, 2));
                            (void)v_invert;
                            alg_root(&v_invert, 1);
                            alg_hold_top = rh_919;
                            if (alg_truthy(alg_hold(alg_not_equal(v_invert, alg_nil())))) {
                                Value ret_104 = alg_hold(alg_invoke(alg_hold(alg_invoke(v_invert, "Bind", (Value[]){v_right}, 1)), "Call", (Value[]){v_this, alg_hold(alg_list())}, 2));
                                alg_root_top = rt_base;
                                return ret_104;
                            }
                            alg_hold_top = rh_919;
                            alg_root_top = rt_918;
                        }
                    }
                    alg_hold_top = rh_917;
                    Value ret_105 = alg_hold(alg_bit_not(v_right));
                    alg_root_top = rt_base;
                    return ret_105;
                    alg_hold_top = rh_917;
                }
            }
        }
    }
    alg_hold_top = rh_913;
    Value ret_106 = alg_nil();
    alg_root_top = rt_base;
    return ret_106;
}

static Value m_interpreter_visitcollectionexpr_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_920 = alg_hold_top;
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_920;
    if (alg_truthy(alg_hold(alg_property(v_theexpr, "IsMap")))) {
        {
            int32_t rh_921 = alg_hold_top;
            (void)((v_result = alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("Map")}, 1))));
            alg_hold_top = rh_921;
            {
                int32_t rt_922 = alg_root_top;
                int32_t rh_923 = alg_hold_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_923;
                {
                    int32_t rh_924 = alg_hold_top;
                    for (; (alg_hold_top = rh_924, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Keys")), "Length")))))); (alg_hold_top = rh_924, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                        alg_safe_point();
                        (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_result, "Pairs")), "Put", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_theexpr, "Keys")), v_i))}, 1)), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_theexpr, "Values")), v_i))}, 1))}, 2)));
                    }
                }
                alg_hold_top = rh_923;
                alg_root_top = rt_922;
            }
            alg_hold_top = rh_921;
            Value ret_107 = v_result;
            alg_root_top = rt_base;
            return ret_107;
            alg_hold_top = rh_921;
        }
    }
    alg_hold_top = rh_920;
    (void)((v_result = alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("List")}, 1))));
    alg_hold_top = rh_920;
    {
        int32_t rt_925 = alg_root_top;
        Value loop_108 = alg_iterable(alg_hold(alg_property(v_theexpr, "Values")));
        (void)loop_108;
        alg_root(&loop_108, 1);
        for (int32_t at_108 = 0; at_108 < alg_iterable_count(loop_108); at_108++) {
            alg_safe_point();
            int32_t rt_926 = alg_root_top;
            Value v_value = alg_iterable_at(loop_108, at_108);
            (void)v_value;
            alg_root(&v_value, 1);
            (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_result, "Items")), "Add", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){v_value}, 1))}, 1)));
            alg_root_top = rt_926;
        }
        alg_root_top = rt_925;
    }
    alg_hold_top = rh_920;
    Value ret_109 = v_result;
    alg_root_top = rt_base;
    return ret_109;
    alg_hold_top = rh_920;
    Value ret_110 = alg_nil();
    alg_root_top = rt_base;
    return ret_110;
}

static Value m_interpreter_visitsubscriptexpr_1_subscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SubscriptExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_927 = alg_hold_top;
    Value v_target = alg_nil();
    (void)v_target;
    alg_root(&v_target, 1);
    alg_hold_top = rh_927;
    Value v_index = alg_nil();
    (void)v_index;
    alg_root(&v_index, 1);
    alg_hold_top = rh_927;
    (void)((v_target = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1))));
    alg_hold_top = rh_927;
    (void)((v_index = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Index"))}, 1))));
    alg_hold_top = rh_927;
    if (alg_truthy(alg_is_class(v_target, k_objcollection))) {
        Value ret_111 = alg_hold(alg_invoke(v_target, "At", (Value[]){v_index}, 1));
        alg_root_top = rt_base;
        return ret_111;
    }
    alg_hold_top = rh_927;
    if (alg_truthy(alg_is_class(v_target, k_objbuffer))) {
        Value ret_112 = alg_hold(alg_invoke(v_target, "At", (Value[]){v_index}, 1));
        alg_root_top = rt_base;
        return ret_112;
    }
    alg_hold_top = rh_927;
    if (alg_truthy(alg_is_class(v_target, k_objinstance))) {
        {
            int32_t rt_928 = alg_root_top;
            int32_t rh_929 = alg_hold_top;
            Value v_reader = alg_hold(alg_invoke(alg_hold(alg_property(v_target, "Klass")), "MethodOfArity", (Value[]){alg_literal("get"), alg_int(1)}, 2));
            (void)v_reader;
            alg_root(&v_reader, 1);
            alg_hold_top = rh_929;
            if (alg_truthy(alg_hold(alg_not_equal(v_reader, alg_nil())))) {
                Value ret_113 = alg_hold(alg_invoke(alg_hold(alg_invoke(v_reader, "Bind", (Value[]){v_target}, 1)), "Call", (Value[]){v_this, alg_hold(alg_list_keep(alg_list(), v_index))}, 2));
                alg_root_top = rt_base;
                return ret_113;
            }
            alg_hold_top = rh_929;
            alg_root_top = rt_928;
        }
    }
    alg_hold_top = rh_927;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsText", (Value[]){v_target}, 1)))) {
        Value ret_114 = alg_hold(alg_subscript_get(alg_hold(alg_str(v_target)), v_index));
        alg_root_top = rt_base;
        return ret_114;
    }
    alg_hold_top = rh_927;
    alg_raise(alg_literal("Subscript target should be an ordinal."));
    alg_hold_top = rh_927;
    Value ret_115 = alg_nil();
    alg_root_top = rt_base;
    return ret_115;
}

static Value m_interpreter_visitsetsubscriptexpr_1_setsubscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SetSubscriptExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_930 = alg_hold_top;
    Value v_target = alg_nil();
    (void)v_target;
    alg_root(&v_target, 1);
    alg_hold_top = rh_930;
    Value v_index = alg_nil();
    (void)v_index;
    alg_root(&v_index, 1);
    alg_hold_top = rh_930;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_930;
    (void)((v_target = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1))));
    alg_hold_top = rh_930;
    (void)((v_index = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Index"))}, 1))));
    alg_hold_top = rh_930;
    (void)((v_value = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1))));
    alg_hold_top = rh_930;
    if (alg_truthy(alg_is_class(v_target, k_objcollection))) {
        Value ret_116 = alg_hold(alg_invoke(v_target, "PutAt", (Value[]){v_index, v_value}, 2));
        alg_root_top = rt_base;
        return ret_116;
    }
    alg_hold_top = rh_930;
    if (alg_truthy(alg_is_class(v_target, k_objbuffer))) {
        Value ret_117 = alg_hold(alg_invoke(v_target, "PutAt", (Value[]){v_index, v_value}, 2));
        alg_root_top = rt_base;
        return ret_117;
    }
    alg_hold_top = rh_930;
    if (alg_truthy(alg_is_class(v_target, k_objinstance))) {
        {
            int32_t rt_931 = alg_root_top;
            int32_t rh_932 = alg_hold_top;
            Value v_writer = alg_hold(alg_invoke(alg_hold(alg_property(v_target, "Klass")), "MethodOfArity", (Value[]){alg_literal("put"), alg_int(2)}, 2));
            (void)v_writer;
            alg_root(&v_writer, 1);
            alg_hold_top = rh_932;
            if (alg_truthy(alg_hold(alg_not_equal(v_writer, alg_nil())))) {
                Value ret_118 = alg_hold(alg_invoke(alg_hold(alg_invoke(v_writer, "Bind", (Value[]){v_target}, 1)), "Call", (Value[]){v_this, alg_hold(alg_list_keep(alg_list_keep(alg_list(), v_index), v_value))}, 2));
                alg_root_top = rt_base;
                return ret_118;
            }
            alg_hold_top = rh_932;
            alg_root_top = rt_931;
        }
    }
    alg_hold_top = rh_930;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsText", (Value[]){v_target}, 1)))) {
        alg_raise(alg_literal("Strings are immutable."));
    }
    alg_hold_top = rh_930;
    alg_raise(alg_literal("Subscript target should be an ordinal."));
    alg_hold_top = rh_930;
    Value ret_119 = alg_nil();
    alg_root_top = rt_base;
    return ret_119;
}

static Value m_interpreter_istext_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    int32_t rh_933 = alg_hold_top;
    Value ret_120 = alg_hold((or_16 = alg_is_kind(v_obj, ALG_KIND_STRING), alg_truthy(or_16) ? or_16 : alg_is_kind(v_obj, ALG_KIND_CHAR)));
    alg_root_top = rt_base;
    return ret_120;
    alg_hold_top = rh_933;
    Value ret_121 = alg_nil();
    alg_root_top = rt_base;
    return ret_121;
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
    int32_t rh_934 = alg_hold_top;
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    alg_hold_top = rh_934;
    if (alg_truthy(alg_hold(alg_not((alg_is_kind(v_value, ALG_KIND_INTEGER)))))) {
        Value ret_122 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_122;
    }
    alg_hold_top = rh_934;
    (void)((v_at = alg_hold(f_subrangeindex(NULL, (Value[]){v_thename}, 1))));
    alg_hold_top = rh_934;
    Value ret_123 = alg_hold((or_17 = alg_hold(alg_greater_equal(v_value, alg_hold(alg_subscript_get((alg_declared(d_subrangeVlows, "SUBRANGE_LOWS"), v_subrangeVlows), v_at)))), !alg_truthy(or_17) ? or_17 : alg_hold(alg_less_equal(v_value, alg_hold(alg_subscript_get((alg_declared(d_subrangeVhighs, "SUBRANGE_HIGHS"), v_subrangeVhighs), v_at))))));
    alg_root_top = rt_base;
    return ret_123;
    alg_hold_top = rh_934;
    Value ret_124 = alg_nil();
    alg_root_top = rt_base;
    return ret_124;
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
    int32_t rh_935 = alg_hold_top;
    if (alg_truthy(alg_hold(f_issubrange(NULL, (Value[]){v_thename}, 1)))) {
        Value ret_125 = alg_hold(alg_invoke(v_this, "InSubrange", (Value[]){v_value, v_thename}, 2));
        alg_root_top = rt_base;
        return ret_125;
    }
    alg_hold_top = rh_935;
    Value v_wanted = alg_hold(f_canonicaltype(NULL, (Value[]){v_thename}, 1));
    (void)v_wanted;
    alg_root(&v_wanted, 1);
    alg_hold_top = rh_935;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_to_lower(alg_hold(f_typenameof(NULL, (Value[]){v_value}, 1)))), alg_hold(alg_to_lower(v_wanted)))))) {
        Value ret_126 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_126;
    }
    alg_hold_top = rh_935;
    Value ret_127 = alg_hold(f_inheritsfrom(NULL, (Value[]){v_value, v_wanted}, 2));
    alg_root_top = rt_base;
    return ret_127;
    alg_hold_top = rh_935;
    Value ret_128 = alg_nil();
    alg_root_top = rt_base;
    return ret_128;
}

static Value m_interpreter_visitisexpr_1_isexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "IsExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_936 = alg_hold_top;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_936;
    (void)((v_value = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1))));
    alg_hold_top = rh_936;
    if (alg_truthy(alg_hold(alg_equal(v_value, alg_nil())))) {
        Value ret_129 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_129;
    }
    alg_hold_top = rh_936;
    Value ret_130 = alg_hold(alg_invoke(v_this, "SatisfiesType", (Value[]){v_value, alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "TypeName")), "Lexeme"))))}, 2));
    alg_root_top = rt_base;
    return ret_130;
    alg_hold_top = rh_936;
    Value ret_131 = alg_nil();
    alg_root_top = rt_base;
    return ret_131;
}

static Value m_interpreter_visitvariableexpr_1_variableexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_theexpr = alg_widen(args[0], "VariableExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_937 = alg_hold_top;
    volatile Value v_found = alg_nil();
    (void)v_found;
    alg_root(&v_found, 1);
    alg_hold_top = rh_937;
    {
        AlgFrame frame_132;
        alg_push_frame(&frame_132);
        if (ALG_SETJMP(frame_132.jump) == 0) {
            {
                int32_t rh_938 = alg_hold_top;
                (void)((v_found = alg_hold(alg_invoke(v_this, "LookupVariable", (Value[]){alg_hold(alg_property(v_theexpr, "Name")), v_theexpr}, 2))));
                alg_hold_top = rh_938;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_132[] = {"String"};
            int32_t which_132 = alg_handler(frame_132.raised, names_132, 1);
            if (which_132 == 0) {
                {
                    int32_t rt_939 = alg_root_top;
                    volatile Value v_e = frame_132.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_133 = alg_hold(alg_invoke(v_this, "ThisField", (Value[]){alg_hold(alg_property(v_theexpr, "Name")), v_e}, 2));
                    alg_root_top = rt_base;
                    return ret_133;
                    alg_root_top = rt_939;
                }
            }
            else {
                alg_raise(frame_132.raised);
            }
        }
    }
    alg_hold_top = rh_937;
    if (alg_truthy(alg_is_class(v_found, k_native))) {
        {
            AlgFrame frame_134;
            alg_push_frame(&frame_134);
            if (ALG_SETJMP(frame_134.jump) == 0) {
                {
                    int32_t rh_940 = alg_hold_top;
                    volatile Value ret_135 = alg_hold(alg_invoke(v_this, "ReceiverField", (Value[]){alg_hold(alg_property(v_theexpr, "Name"))}, 1));
                    alg_pop_frame();
                    alg_root_top = rt_base;
                    return ret_135;
                    alg_hold_top = rh_940;
                }
                alg_pop_frame();
            }
            else {
                static const char *names_134[] = {"String"};
                int32_t which_134 = alg_handler(frame_134.raised, names_134, 1);
                if (which_134 == 0) {
                    {
                        int32_t rt_941 = alg_root_top;
                        volatile Value v_e = frame_134.raised;
                        (void)v_e;
                        alg_root(&v_e, 1);
                        volatile Value ret_136 = v_found;
                        alg_root_top = rt_base;
                        return ret_136;
                        alg_root_top = rt_941;
                    }
                }
                else {
                    alg_raise(frame_134.raised);
                }
            }
        }
    }
    alg_hold_top = rh_937;
    volatile Value ret_137 = v_found;
    alg_root_top = rt_base;
    return ret_137;
    alg_hold_top = rh_937;
    volatile Value ret_138 = alg_nil();
    alg_root_top = rt_base;
    return ret_138;
}

static Value m_interpreter_receiverfield_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_942 = alg_hold_top;
    Value v_obj = alg_nil();
    (void)v_obj;
    alg_root(&v_obj, 1);
    alg_hold_top = rh_942;
    (void)((v_obj = alg_hold(alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_hold(alg_new(k_token, (Value[]){e_tokentype_tokenVthis, alg_literal("this"), alg_nil(), alg_hold(alg_property(v_name, "LineNumber"))}, 4))}, 1))));
    alg_hold_top = rh_942;
    Value ret_139 = alg_hold(alg_invoke(v_obj, "GetField", (Value[]){v_name}, 1));
    alg_root_top = rt_base;
    return ret_139;
    alg_hold_top = rh_942;
    Value ret_140 = alg_nil();
    alg_root_top = rt_base;
    return ret_140;
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
    int32_t rh_943 = alg_hold_top;
    volatile Value v_obj = alg_nil();
    (void)v_obj;
    alg_root(&v_obj, 1);
    alg_hold_top = rh_943;
    {
        AlgFrame frame_141;
        alg_push_frame(&frame_141);
        if (ALG_SETJMP(frame_141.jump) == 0) {
            {
                int32_t rh_944 = alg_hold_top;
                (void)((v_obj = alg_hold(alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_hold(alg_new(k_token, (Value[]){e_tokentype_tokenVthis, alg_literal("this"), alg_nil(), alg_hold(alg_property(v_name, "LineNumber"))}, 4))}, 1))));
                alg_hold_top = rh_944;
                volatile Value ret_142 = alg_hold(alg_invoke(v_obj, "Get", (Value[]){v_name}, 1));
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_142;
                alg_hold_top = rh_944;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_141[] = {"String"};
            int32_t which_141 = alg_handler(frame_141.raised, names_141, 1);
            if (which_141 == 0) {
                {
                    int32_t rt_945 = alg_root_top;
                    volatile Value v_e = frame_141.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    alg_raise(v_original);
                    alg_root_top = rt_945;
                }
            }
            else {
                alg_raise(frame_141.raised);
            }
        }
    }
    alg_hold_top = rh_943;
    volatile Value ret_143 = alg_nil();
    alg_root_top = rt_base;
    return ret_143;
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
    int32_t rh_946 = alg_hold_top;
    volatile Value v_obj = alg_nil();
    (void)v_obj;
    alg_root(&v_obj, 1);
    alg_hold_top = rh_946;
    {
        AlgFrame frame_144;
        alg_push_frame(&frame_144);
        if (ALG_SETJMP(frame_144.jump) == 0) {
            {
                int32_t rh_947 = alg_hold_top;
                (void)((v_obj = alg_hold(alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_hold(alg_new(k_token, (Value[]){e_tokentype_tokenVthis, alg_literal("this"), alg_nil(), alg_hold(alg_property(v_name, "LineNumber"))}, 4))}, 1))));
                alg_hold_top = rh_947;
                (void)(alg_hold(alg_invoke(v_obj, "Set", (Value[]){v_name, v_value}, 2)));
                alg_hold_top = rh_947;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_144[] = {"String"};
            int32_t which_144 = alg_handler(frame_144.raised, names_144, 1);
            if (which_144 == 0) {
                {
                    int32_t rt_948 = alg_root_top;
                    volatile Value v_e = frame_144.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    alg_raise(v_original);
                    alg_root_top = rt_948;
                }
            }
            else {
                alg_raise(frame_144.raised);
            }
        }
    }
    alg_hold_top = rh_946;
    volatile Value ret_145 = alg_nil();
    alg_root_top = rt_base;
    return ret_145;
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
    int32_t rh_949 = alg_hold_top;
    volatile Value v_distance = alg_nil();
    (void)v_distance;
    alg_root(&v_distance, 1);
    alg_hold_top = rh_949;
    (void)((v_distance = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "Locals"), "Get", (Value[]){v_theexpr}, 1), ALG_KIND_INTEGER, "Integer"))));
    alg_hold_top = rh_949;
    if (alg_truthy(alg_hold(alg_not_equal(v_distance, alg_nil())))) {
        volatile Value ret_146 = alg_hold(alg_invoke(alg_property(v_this, "Env"), "GetAt", (Value[]){v_distance, alg_hold(alg_property(v_name, "Lexeme"))}, 2));
        alg_root_top = rt_base;
        return ret_146;
    }
    alg_hold_top = rh_949;
    {
        AlgFrame frame_147;
        alg_push_frame(&frame_147);
        if (ALG_SETJMP(frame_147.jump) == 0) {
            {
                int32_t rh_950 = alg_hold_top;
                volatile Value ret_148 = alg_hold(alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){v_name}, 1));
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_148;
                alg_hold_top = rh_950;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_147[] = {"String"};
            int32_t which_147 = alg_handler(frame_147.raised, names_147, 1);
            if (which_147 == 0) {
                {
                    int32_t rt_951 = alg_root_top;
                    volatile Value v_e = frame_147.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    alg_raise(alg_hold(alg_invoke(v_this, "SuggestUnit", (Value[]){v_name, v_e}, 2)));
                    alg_root_top = rt_951;
                }
            }
            else {
                alg_raise(frame_147.raised);
            }
        }
    }
    alg_hold_top = rh_949;
    volatile Value ret_149 = alg_nil();
    alg_root_top = rt_base;
    return ret_149;
}

static Value m_interpreter_shown_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    int32_t rh_952 = alg_hold_top;
    Value v_method = alg_hold(alg_invoke(alg_hold(alg_property(v_value, "Klass")), "MethodOfArity", (Value[]){alg_literal("tostring"), alg_int(0)}, 2));
    (void)v_method;
    alg_root(&v_method, 1);
    alg_hold_top = rh_952;
    if (alg_truthy(alg_hold(alg_not_equal(v_method, alg_nil())))) {
        Value ret_150 = alg_hold(f_stringify(NULL, (Value[]){v_this, alg_hold(alg_invoke(alg_hold(alg_invoke(v_method, "Bind", (Value[]){v_value}, 1)), "Call", (Value[]){v_this, alg_hold(alg_list())}, 2))}, 2));
        alg_root_top = rt_base;
        return ret_150;
    }
    alg_hold_top = rh_952;
    Value ret_151 = alg_hold(alg_add(alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_value, "Klass")), "Name")))), alg_literal(" instance")));
    alg_root_top = rt_base;
    return ret_151;
    alg_hold_top = rh_952;
    Value ret_152 = alg_nil();
    alg_root_top = rt_base;
    return ret_152;
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
    int32_t rh_953 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_copy(v_message, alg_int(0), alg_int(19))), alg_literal("Undefined variable "))))) {
        Value ret_153 = alg_hold(alg_str(v_message));
        alg_root_top = rt_base;
        return ret_153;
    }
    alg_hold_top = rh_953;
    Value v_units = alg_hold(alg_invoke(alg_property(v_this, "UnitsByName"), "Keys", NULL, 0));
    (void)v_units;
    alg_root(&v_units, 1);
    alg_hold_top = rh_953;
    {
        int32_t rt_954 = alg_root_top;
        Value loop_154 = alg_iterable(v_units);
        (void)loop_154;
        alg_root(&loop_154, 1);
        for (int32_t at_154 = 0; at_154 < alg_iterable_count(loop_154); at_154++) {
            alg_safe_point();
            int32_t rt_955 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_154, at_154);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            {
                int32_t rt_956 = alg_root_top;
                int32_t rh_957 = alg_hold_top;
                Value v_moduleenv = alg_hold(alg_cast_class(alg_invoke(alg_property(v_this, "UnitsByName"), "Get", (Value[]){v_theunit}, 1), k_environment, "Environment"));
                (void)v_moduleenv;
                alg_root(&v_moduleenv, 1);
                alg_hold_top = rh_957;
                if (alg_truthy(alg_hold((or_18 = alg_hold(alg_not_equal(alg_hold(alg_property(v_moduleenv, "Exports")), alg_nil())), !alg_truthy(or_18) ? or_18 : alg_hold(alg_invoke(alg_hold(alg_property(v_moduleenv, "Exports")), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1)))))) {
                    Value ret_155 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_str(v_message)), alg_literal(" Unit '"))), alg_hold(alg_str(alg_hold(alg_property(v_moduleenv, "UnitName")))))), alg_literal("' exports it; this file has no 'uses' for it.")));
                    alg_root_top = rt_base;
                    return ret_155;
                }
                alg_hold_top = rh_957;
                alg_root_top = rt_956;
            }
            alg_root_top = rt_955;
        }
        alg_root_top = rt_954;
    }
    alg_hold_top = rh_953;
    if (alg_truthy(alg_hold((or_19 = alg_hold(alg_not_equal(alg_property(v_this, "Env"), alg_property(v_this, "Globals"))), !alg_truthy(or_19) ? or_19 : alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Globals"), "Values")), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1)))))) {
        Value ret_156 = alg_hold(alg_add(alg_hold(alg_str(v_message)), alg_literal(" The file the program started from declares it, and no file can 'uses' that.")));
        alg_root_top = rt_base;
        return ret_156;
    }
    alg_hold_top = rh_953;
    Value ret_157 = alg_hold(alg_str(v_message));
    alg_root_top = rt_base;
    return ret_157;
    alg_hold_top = rh_953;
    Value ret_158 = alg_nil();
    alg_root_top = rt_base;
    return ret_158;
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
    int32_t rh_958 = alg_hold_top;
    if (alg_truthy(alg_hold((or_20 = alg_hold(alg_not((alg_is_kind(v_left, ALG_KIND_INTEGER)))), alg_truthy(or_20) ? or_20 : alg_hold(alg_not((alg_is_kind(v_right, ALG_KIND_INTEGER)))))))) {
        alg_raise(alg_literal("div expects Integers."));
    }
    alg_hold_top = rh_958;
    if (alg_truthy(alg_hold(alg_equal(v_right, alg_int(0))))) {
        alg_raise(alg_literal("Division by zero."));
    }
    alg_hold_top = rh_958;
    Value ret_159 = alg_hold(alg_div_int(v_left, v_right));
    alg_root_top = rt_base;
    return ret_159;
    alg_hold_top = rh_958;
    Value ret_160 = alg_nil();
    alg_root_top = rt_base;
    return ret_160;
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
    int32_t rh_959 = alg_hold_top;
    if (alg_truthy(alg_hold((or_21 = alg_hold(alg_not((alg_is_kind(v_left, ALG_KIND_INTEGER)))), alg_truthy(or_21) ? or_21 : alg_hold(alg_not((alg_is_kind(v_right, ALG_KIND_INTEGER)))))))) {
        alg_raise(alg_literal("mod expects Integers."));
    }
    alg_hold_top = rh_959;
    if (alg_truthy(alg_hold(alg_equal(v_right, alg_int(0))))) {
        alg_raise(alg_literal("Division by zero."));
    }
    alg_hold_top = rh_959;
    Value ret_161 = alg_hold(alg_mod(v_left, v_right));
    alg_root_top = rt_base;
    return ret_161;
    alg_hold_top = rh_959;
    Value ret_162 = alg_nil();
    alg_root_top = rt_base;
    return ret_162;
}

static Value m_interpreter_bitwise_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_op = args[0];
    (void)v_op;
    alg_root(&v_op, 1);
    int32_t rh_960 = alg_hold_top;
    Value ret_163 = alg_hold((or_25 = alg_hold((or_24 = alg_hold((or_23 = alg_hold((or_22 = alg_hold(alg_equal(v_op, e_tokentype_tokenVampersand)), alg_truthy(or_22) ? or_22 : alg_hold(alg_equal(v_op, e_tokentype_tokenVpipe)))), alg_truthy(or_23) ? or_23 : alg_hold(alg_equal(v_op, e_tokentype_tokenVcaret)))), alg_truthy(or_24) ? or_24 : alg_hold(alg_equal(v_op, e_tokentype_tokenVshiftVleft)))), alg_truthy(or_25) ? or_25 : alg_hold(alg_equal(v_op, e_tokentype_tokenVshiftVright))));
    alg_root_top = rt_base;
    return ret_163;
    alg_hold_top = rh_960;
    Value ret_164 = alg_nil();
    alg_root_top = rt_base;
    return ret_164;
}

static Value m_interpreter_arithmetic_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_op = args[0];
    (void)v_op;
    alg_root(&v_op, 1);
    int32_t rh_961 = alg_hold_top;
    Value ret_165 = alg_hold((or_30 = alg_hold((or_29 = alg_hold((or_28 = alg_hold((or_27 = alg_hold((or_26 = alg_hold(alg_equal(v_op, e_tokentype_tokenVplus)), alg_truthy(or_26) ? or_26 : alg_hold(alg_equal(v_op, e_tokentype_tokenVminus)))), alg_truthy(or_27) ? or_27 : alg_hold(alg_equal(v_op, e_tokentype_tokenVstar)))), alg_truthy(or_28) ? or_28 : alg_hold(alg_equal(v_op, e_tokentype_tokenVslash)))), alg_truthy(or_29) ? or_29 : alg_hold(alg_equal(v_op, e_tokentype_tokenVdiv)))), alg_truthy(or_30) ? or_30 : alg_hold(alg_equal(v_op, e_tokentype_tokenVmod))));
    alg_root_top = rt_base;
    return ret_165;
    alg_hold_top = rh_961;
    Value ret_166 = alg_nil();
    alg_root_top = rt_base;
    return ret_166;
}

static Value m_interpreter_orders_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_op = args[0];
    (void)v_op;
    alg_root(&v_op, 1);
    int32_t rh_962 = alg_hold_top;
    Value ret_167 = alg_hold((or_33 = alg_hold((or_32 = alg_hold((or_31 = alg_hold(alg_equal(v_op, e_tokentype_tokenVless)), alg_truthy(or_31) ? or_31 : alg_hold(alg_equal(v_op, e_tokentype_tokenVlessVequal)))), alg_truthy(or_32) ? or_32 : alg_hold(alg_equal(v_op, e_tokentype_tokenVgreater)))), alg_truthy(or_33) ? or_33 : alg_hold(alg_equal(v_op, e_tokentype_tokenVgreaterVequal))));
    alg_root_top = rt_base;
    return ret_167;
    alg_hold_top = rh_962;
    Value ret_168 = alg_nil();
    alg_root_top = rt_base;
    return ret_168;
}

static Value m_interpreter_visitbinary_1_binaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "BinaryExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_963 = alg_hold_top;
    Value v_left = alg_nil();
    (void)v_left;
    alg_root(&v_left, 1);
    alg_hold_top = rh_963;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_963;
    (void)((v_left = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Left"))}, 1))));
    alg_hold_top = rh_963;
    (void)((v_right = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1))));
    alg_hold_top = rh_963;
    if (alg_truthy(alg_hold((or_35 = alg_is_class(v_left, k_objinstance), !alg_truthy(or_35) ? or_35 : (alg_hold((or_34 = alg_hold(alg_invoke(v_this, "Arithmetic", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken"))}, 1)), alg_truthy(or_34) ? or_34 : alg_hold(alg_invoke(v_this, "Bitwise", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken"))}, 1))))))))) {
        {
            int32_t rt_964 = alg_root_top;
            int32_t rh_965 = alg_hold_top;
            Value v_defined = alg_hold(alg_invoke(alg_hold(alg_property(v_left, "Klass")), "MethodOfArity", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "Lexeme")))), alg_int(1)}, 2));
            (void)v_defined;
            alg_root(&v_defined, 1);
            alg_hold_top = rh_965;
            if (alg_truthy(alg_hold(alg_not_equal(v_defined, alg_nil())))) {
                Value ret_169 = alg_hold(alg_invoke(alg_hold(alg_invoke(v_defined, "Bind", (Value[]){v_left}, 1)), "Call", (Value[]){v_this, alg_hold(alg_list_keep(alg_list(), v_right))}, 2));
                alg_root_top = rt_base;
                return ret_169;
            }
            alg_hold_top = rh_965;
            alg_root_top = rt_964;
        }
    }
    alg_hold_top = rh_963;
    if (alg_truthy(alg_hold((or_36 = alg_is_class(v_left, k_objinstance), !alg_truthy(or_36) ? or_36 : alg_hold(alg_invoke(v_this, "Orders", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken"))}, 1)))))) {
        {
            int32_t rt_966 = alg_root_top;
            int32_t rh_967 = alg_hold_top;
            Value v_ordering = alg_hold(alg_invoke(alg_hold(alg_property(v_left, "Klass")), "MethodOfArity", (Value[]){alg_literal("compare"), alg_int(1)}, 2));
            (void)v_ordering;
            alg_root(&v_ordering, 1);
            alg_hold_top = rh_967;
            if (alg_truthy(alg_hold(alg_not_equal(v_ordering, alg_nil())))) {
                {
                    int32_t rh_968 = alg_hold_top;
                    (void)((v_left = alg_hold(alg_invoke(alg_hold(alg_invoke(v_ordering, "Bind", (Value[]){v_left}, 1)), "Call", (Value[]){v_this, alg_hold(alg_list_keep(alg_list(), v_right))}, 2))));
                    alg_hold_top = rh_968;
                    (void)((v_right = alg_int(0)));
                    alg_hold_top = rh_968;
                    if (alg_truthy(alg_hold(alg_not((alg_is_kind(v_left, ALG_KIND_INTEGER)))))) {
                        alg_raise(alg_literal("Compare must answer an Integer."));
                    }
                    alg_hold_top = rh_968;
                }
            }
            alg_hold_top = rh_967;
            alg_root_top = rt_966;
        }
    }
    alg_hold_top = rh_963;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVgreater)))) {
        Value ret_170 = alg_hold(alg_greater(v_left, v_right));
        alg_root_top = rt_base;
        return ret_170;
    } else {
        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVgreaterVequal)))) {
            Value ret_171 = alg_hold(alg_greater_equal(v_left, v_right));
            alg_root_top = rt_base;
            return ret_171;
        } else {
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVless)))) {
                Value ret_172 = alg_hold(alg_less(v_left, v_right));
                alg_root_top = rt_base;
                return ret_172;
            } else {
                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVlessVequal)))) {
                    Value ret_173 = alg_hold(alg_less_equal(v_left, v_right));
                    alg_root_top = rt_base;
                    return ret_173;
                } else {
                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVnotVequal)))) {
                        Value ret_174 = alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsEqual", (Value[]){v_left, v_right}, 2))));
                        alg_root_top = rt_base;
                        return ret_174;
                    } else {
                        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVequal)))) {
                            Value ret_175 = alg_hold(alg_invoke(v_this, "IsEqual", (Value[]){v_left, v_right}, 2));
                            alg_root_top = rt_base;
                            return ret_175;
                        } else {
                            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVin)))) {
                                Value ret_176 = alg_hold(alg_invoke(v_this, "Contains", (Value[]){v_right, v_left}, 2));
                                alg_root_top = rt_base;
                                return ret_176;
                            } else {
                                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVplus)))) {
                                    Value ret_177 = alg_hold(alg_add(v_left, v_right));
                                    alg_root_top = rt_base;
                                    return ret_177;
                                } else {
                                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVminus)))) {
                                        Value ret_178 = alg_hold(alg_subtract(v_left, v_right));
                                        alg_root_top = rt_base;
                                        return ret_178;
                                    } else {
                                        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVslash)))) {
                                            Value ret_179 = alg_hold(alg_divide(v_left, v_right));
                                            alg_root_top = rt_base;
                                            return ret_179;
                                        } else {
                                            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVdiv)))) {
                                                Value ret_180 = alg_hold(alg_invoke(v_this, "IntegerDivide", (Value[]){v_left, v_right}, 2));
                                                alg_root_top = rt_base;
                                                return ret_180;
                                            } else {
                                                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVmod)))) {
                                                    Value ret_181 = alg_hold(alg_invoke(v_this, "Remainder", (Value[]){v_left, v_right}, 2));
                                                    alg_root_top = rt_base;
                                                    return ret_181;
                                                } else {
                                                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVstar)))) {
                                                        Value ret_182 = alg_hold(alg_multiply(v_left, v_right));
                                                        alg_root_top = rt_base;
                                                        return ret_182;
                                                    } else {
                                                        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVampersand)))) {
                                                            Value ret_183 = alg_hold(alg_bit_and(v_left, v_right));
                                                            alg_root_top = rt_base;
                                                            return ret_183;
                                                        } else {
                                                            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVpipe)))) {
                                                                Value ret_184 = alg_hold(alg_bit_or(v_left, v_right));
                                                                alg_root_top = rt_base;
                                                                return ret_184;
                                                            } else {
                                                                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVcaret)))) {
                                                                    Value ret_185 = alg_hold(alg_bit_xor(v_left, v_right));
                                                                    alg_root_top = rt_base;
                                                                    return ret_185;
                                                                } else {
                                                                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVshiftVleft)))) {
                                                                        Value ret_186 = alg_hold(alg_shift_left(v_left, v_right));
                                                                        alg_root_top = rt_base;
                                                                        return ret_186;
                                                                    } else {
                                                                        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVshiftVright)))) {
                                                                            Value ret_187 = alg_hold(alg_shift_right(v_left, v_right));
                                                                            alg_root_top = rt_base;
                                                                            return ret_187;
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
    alg_hold_top = rh_963;
    Value ret_188 = alg_nil();
    alg_root_top = rt_base;
    return ret_188;
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
    int32_t rh_969 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(f_anynamed(NULL, (Value[]){v_names}, 1)))))) {
        Value ret_189 = v_arguments;
        alg_root_top = rt_base;
        return ret_189;
    }
    alg_hold_top = rh_969;
    if (alg_truthy(alg_is_class(v_callee, k_objfunction))) {
        {
            int32_t rt_970 = alg_root_top;
            int32_t rh_971 = alg_hold_top;
            Value v_fitted = alg_hold(alg_invoke(v_callee, "Arrange", (Value[]){v_arguments, v_names}, 2));
            (void)v_fitted;
            alg_root(&v_fitted, 1);
            alg_hold_top = rh_971;
            if (alg_truthy(alg_hold(alg_equal(v_fitted, alg_nil())))) {
                alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("No matching signature for "), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_callee, "Declaration")), "Name")), "Lexeme")))))), alg_char_value(46))));
            }
            alg_hold_top = rh_971;
            Value ret_190 = v_fitted;
            alg_root_top = rt_base;
            return ret_190;
            alg_hold_top = rh_971;
            alg_root_top = rt_970;
        }
    }
    alg_hold_top = rh_969;
    if (alg_truthy(alg_is_class(v_callee, k_objoverloads))) {
        {
            int32_t rh_972 = alg_hold_top;
            {
                int32_t rt_973 = alg_root_top;
                Value loop_191 = alg_iterable(alg_hold(alg_property(v_callee, "Candidates")));
                (void)loop_191;
                alg_root(&loop_191, 1);
                for (int32_t at_191 = 0; at_191 < alg_iterable_count(loop_191); at_191++) {
                    alg_safe_point();
                    int32_t rt_974 = alg_root_top;
                    Value v_candidate = alg_iterable_at(loop_191, at_191);
                    (void)v_candidate;
                    alg_root(&v_candidate, 1);
                    {
                        int32_t rt_975 = alg_root_top;
                        int32_t rh_976 = alg_hold_top;
                        Value v_fitted = alg_hold(alg_invoke(v_candidate, "Arrange", (Value[]){v_arguments, v_names}, 2));
                        (void)v_fitted;
                        alg_root(&v_fitted, 1);
                        alg_hold_top = rh_976;
                        if (alg_truthy(alg_hold(alg_not_equal(v_fitted, alg_nil())))) {
                            Value ret_192 = v_fitted;
                            alg_root_top = rt_base;
                            return ret_192;
                        }
                        alg_hold_top = rh_976;
                        alg_root_top = rt_975;
                    }
                    alg_root_top = rt_974;
                }
                alg_root_top = rt_973;
            }
            alg_hold_top = rh_972;
            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("No matching signature for "), alg_hold(alg_str(alg_hold(alg_property(v_callee, "Name")))))), alg_char_value(46))));
            alg_hold_top = rh_972;
        }
    }
    alg_hold_top = rh_969;
    if (alg_truthy(alg_is_class(v_callee, k_objclass))) {
        {
            int32_t rt_977 = alg_root_top;
            int32_t rh_978 = alg_hold_top;
            Value v_init = alg_hold(alg_invoke(v_callee, "FindMethod", (Value[]){alg_literal("init")}, 1));
            (void)v_init;
            alg_root(&v_init, 1);
            alg_hold_top = rh_978;
            if (alg_truthy(alg_hold(alg_not_equal(v_init, alg_nil())))) {
                {
                    int32_t rt_979 = alg_root_top;
                    int32_t rh_980 = alg_hold_top;
                    Value v_fitted = alg_hold(alg_invoke(v_init, "Arrange", (Value[]){v_arguments, v_names}, 2));
                    (void)v_fitted;
                    alg_root(&v_fitted, 1);
                    alg_hold_top = rh_980;
                    if (alg_truthy(alg_hold(alg_not_equal(v_fitted, alg_nil())))) {
                        Value ret_193 = v_fitted;
                        alg_root_top = rt_base;
                        return ret_193;
                    }
                    alg_hold_top = rh_980;
                    alg_root_top = rt_979;
                }
            }
            alg_hold_top = rh_978;
            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("No matching signature for "), alg_hold(alg_str(alg_hold(alg_property(v_callee, "Name")))))), alg_char_value(46))));
            alg_hold_top = rh_978;
            alg_root_top = rt_977;
        }
    }
    alg_hold_top = rh_969;
    alg_raise(alg_literal("A built-in has no named parameters."));
    alg_hold_top = rh_969;
    Value ret_194 = alg_nil();
    alg_root_top = rt_base;
    return ret_194;
}

static Value m_interpreter_visitcall_1_callexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CallExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_981 = alg_hold_top;
    Value v_callee = alg_nil();
    (void)v_callee;
    alg_root(&v_callee, 1);
    alg_hold_top = rh_981;
    Value v_arguments = alg_nil();
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    alg_hold_top = rh_981;
    (void)(alg_set_property(v_this, "MemberIsCallee", alg_is_class(alg_hold(alg_property(v_theexpr, "Callee")), k_getexpr)));
    alg_hold_top = rh_981;
    (void)((v_callee = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Callee"))}, 1))));
    alg_hold_top = rh_981;
    (void)(alg_set_property(v_this, "MemberIsCallee", alg_bool(false)));
    alg_hold_top = rh_981;
    (void)((v_arguments = alg_hold(alg_list())));
    alg_hold_top = rh_981;
    {
        int32_t rt_982 = alg_root_top;
        Value loop_195 = alg_iterable(alg_hold(alg_property(v_theexpr, "Arguments")));
        (void)loop_195;
        alg_root(&loop_195, 1);
        for (int32_t at_195 = 0; at_195 < alg_iterable_count(loop_195); at_195++) {
            alg_safe_point();
            int32_t rt_983 = alg_root_top;
            Value v_argument = alg_iterable_at(loop_195, at_195);
            (void)v_argument;
            alg_root(&v_argument, 1);
            {
                int32_t rh_984 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_arguments, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){v_argument}, 1))}, 1)));
                alg_hold_top = rh_984;
            }
            alg_root_top = rt_983;
        }
        alg_root_top = rt_982;
    }
    alg_hold_top = rh_981;
    Value v_names = alg_hold(alg_property(v_theexpr, "ArgumentNames"));
    (void)v_names;
    alg_root(&v_names, 1);
    alg_hold_top = rh_981;
    if (alg_truthy(alg_is_class(v_callee, k_objextension))) {
        {
            int32_t rt_985 = alg_root_top;
            int32_t rh_986 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_arguments, "Insert", (Value[]){alg_int(0), alg_hold(alg_property(v_callee, "Receiver"))}, 2)));
            alg_hold_top = rh_986;
            Value v_padded = alg_hold(alg_list());
            (void)v_padded;
            alg_root(&v_padded, 1);
            alg_hold_top = rh_986;
            (void)(alg_hold(alg_invoke(v_padded, "Add", (Value[]){alg_literal("")}, 1)));
            alg_hold_top = rh_986;
            {
                int32_t rt_987 = alg_root_top;
                Value loop_196 = alg_iterable(v_names);
                (void)loop_196;
                alg_root(&loop_196, 1);
                for (int32_t at_196 = 0; at_196 < alg_iterable_count(loop_196); at_196++) {
                    alg_safe_point();
                    int32_t rt_988 = alg_root_top;
                    Value v_each = alg_iterable_at(loop_196, at_196);
                    (void)v_each;
                    alg_root(&v_each, 1);
                    (void)(alg_hold(alg_invoke(v_padded, "Add", (Value[]){v_each}, 1)));
                    alg_root_top = rt_988;
                }
                alg_root_top = rt_987;
            }
            alg_hold_top = rh_986;
            (void)((v_names = v_padded));
            alg_hold_top = rh_986;
            (void)((v_callee = alg_hold(alg_property(v_callee, "Target"))));
            alg_hold_top = rh_986;
            alg_root_top = rt_985;
        }
    }
    alg_hold_top = rh_981;
    (void)((v_arguments = alg_hold(alg_invoke(v_this, "Arranged", (Value[]){v_callee, v_arguments, v_names}, 3))));
    alg_hold_top = rh_981;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsCallable", (Value[]){v_callee}, 1)))))) {
        {
            int32_t rh_989 = alg_hold_top;
            alg_raise(alg_literal("Can only call functions and classes."));
            alg_hold_top = rh_989;
        }
    }
    alg_hold_top = rh_981;
    if (alg_truthy(alg_is_class(v_callee, k_objfunction))) {
        {
            int32_t rh_990 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_callee, "Owner")), alg_nil())))) {
                {
                    int32_t rt_991 = alg_root_top;
                    int32_t rh_992 = alg_hold_top;
                    Value v_member = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_callee, "Declaration")), "Name")), "Lexeme"))}, 1));
                    (void)v_member;
                    alg_root(&v_member, 1);
                    alg_hold_top = rh_992;
                    Value v_better = alg_hold(alg_invoke(alg_hold(alg_property(v_callee, "Owner")), "FindOverload", (Value[]){v_member, v_arguments}, 2));
                    (void)v_better;
                    alg_root(&v_better, 1);
                    alg_hold_top = rh_992;
                    if (alg_truthy(alg_hold(alg_equal(v_better, alg_nil())))) {
                        alg_raise(alg_hold(f_nomatch(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_callee, "Owner")), "Name")))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_callee, "Declaration")), "Name")), "Lexeme")))), alg_hold(alg_invoke(alg_hold(alg_property(v_callee, "Owner")), "CandidatesOf", (Value[]){v_member}, 1)), alg_hold(alg_property(v_arguments, "Length"))}, 4)));
                    }
                    alg_hold_top = rh_992;
                    (void)((v_callee = alg_hold(alg_invoke(v_better, "Bind", (Value[]){alg_hold(alg_property(v_callee, "Bound"))}, 1))));
                    alg_hold_top = rh_992;
                    alg_root_top = rt_991;
                }
            } else {
                if (alg_truthy(alg_hold((or_37 = alg_hold(alg_not(alg_hold(alg_invoke(v_callee, "Fits", (Value[]){v_arguments, alg_bool(true)}, 2)))), !alg_truthy(or_37) ? or_37 : alg_hold(alg_not(alg_hold(alg_invoke(v_callee, "Absorbs", (Value[]){v_arguments}, 1)))))))) {
                    {
                        int32_t rh_993 = alg_hold_top;
                        if (alg_truthy(alg_hold((or_38 = alg_hold(alg_not(alg_hold(alg_invoke(v_callee, "Variadic", NULL, 0)))), !alg_truthy(or_38) ? or_38 : alg_hold(alg_not_equal(alg_hold(alg_property(v_arguments, "Length")), alg_hold(alg_invoke(v_callee, "Arity", NULL, 0)))))))) {
                            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expected "), alg_hold(alg_invoke(v_callee, "Arity", NULL, 0)))), alg_literal(" arguments but got "))), alg_hold(alg_property(v_arguments, "Length")))), alg_char_value(46))));
                        }
                        alg_hold_top = rh_993;
                        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("No matching signature for "), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_callee, "Declaration")), "Name")), "Lexeme")))))), alg_char_value(46))));
                        alg_hold_top = rh_993;
                    }
                }
            }
            alg_hold_top = rh_990;
        }
    }
    alg_hold_top = rh_981;
    Value v_gathering = alg_bool(false);
    (void)v_gathering;
    alg_root(&v_gathering, 1);
    alg_hold_top = rh_981;
    if (alg_truthy(alg_hold((or_39 = alg_is_class(v_callee, k_objfunction), alg_truthy(or_39) ? or_39 : alg_is_class(v_callee, k_objclass))))) {
        (void)((v_gathering = alg_hold(alg_invoke(v_callee, "Absorbs", (Value[]){v_arguments}, 1))));
    }
    alg_hold_top = rh_981;
    Value v_absorbing = alg_bool(false);
    (void)v_absorbing;
    alg_root(&v_absorbing, 1);
    alg_hold_top = rh_981;
    if (alg_truthy(alg_hold((or_40 = alg_is_class(v_callee, k_objfunction), alg_truthy(or_40) ? or_40 : alg_is_class(v_callee, k_objclass))))) {
        (void)((v_absorbing = alg_hold(alg_invoke(v_callee, "Variadic", NULL, 0))));
    }
    alg_hold_top = rh_981;
    if (alg_truthy(alg_hold((or_44 = alg_hold((or_43 = alg_hold((or_42 = alg_hold((or_41 = alg_hold(alg_not(v_gathering)), !alg_truthy(or_41) ? or_41 : alg_hold(alg_not(v_absorbing)))), !alg_truthy(or_42) ? or_42 : alg_hold(alg_not((alg_is_class(v_callee, k_objclass)))))), !alg_truthy(or_43) ? or_43 : alg_hold(alg_greater_equal(alg_hold(alg_invoke(v_callee, "Arity", NULL, 0)), alg_int(0))))), !alg_truthy(or_44) ? or_44 : alg_hold(alg_not_equal(alg_hold(alg_property(v_arguments, "Length")), alg_hold(alg_invoke(v_callee, "Arity", NULL, 0)))))))) {
        {
            int32_t rh_994 = alg_hold_top;
            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expected "), alg_hold(alg_invoke(v_callee, "Arity", NULL, 0)))), alg_literal(" arguments but got "))), alg_hold(alg_property(v_arguments, "Length")))), alg_char_value(46))));
            alg_hold_top = rh_994;
        }
    }
    alg_hold_top = rh_981;
    Value ret_197 = alg_hold(alg_invoke(v_callee, "Call", (Value[]){v_this, v_arguments}, 2));
    alg_root_top = rt_base;
    return ret_197;
    alg_hold_top = rh_981;
    Value ret_198 = alg_nil();
    alg_root_top = rt_base;
    return ret_198;
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
    int32_t rh_995 = alg_hold_top;
    Value v_moduleenv = alg_nil();
    (void)v_moduleenv;
    alg_root(&v_moduleenv, 1);
    alg_hold_top = rh_995;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){v_unit}, 1)), alg_literal("system"))))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Can't assign to '"), alg_hold(alg_str(alg_hold(alg_property(v_name, "Lexeme")))))), alg_literal("' in unit 'System'."))));
    }
    alg_hold_top = rh_995;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "UnitsByName"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_unit}, 1))}, 1)))))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined name '"), alg_hold(alg_str(alg_hold(alg_property(v_name, "Lexeme")))))), alg_literal("' in unit '"))), v_unit)), alg_literal("'."))));
    }
    alg_hold_top = rh_995;
    (void)((v_moduleenv = alg_hold(alg_cast_class(alg_invoke(alg_property(v_this, "UnitsByName"), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_unit}, 1))}, 1), k_environment, "Environment"))));
    alg_hold_top = rh_995;
    if (alg_truthy(alg_hold((or_45 = alg_hold(alg_equal(alg_hold(alg_property(v_moduleenv, "Exports")), alg_nil())), alg_truthy(or_45) ? or_45 : alg_hold(alg_not(alg_hold(alg_invoke(alg_hold(alg_property(v_moduleenv, "Exports")), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1)))))))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined name '"), alg_hold(alg_str(alg_hold(alg_property(v_name, "Lexeme")))))), alg_literal("' in unit '"))), v_unit)), alg_literal("'."))));
    }
    alg_hold_top = rh_995;
    (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_moduleenv, "Values")), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1)), v_value}, 2)));
    alg_hold_top = rh_995;
    Value ret_199 = alg_nil();
    alg_root_top = rt_base;
    return ret_199;
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
    int32_t rh_996 = alg_hold_top;
    Value v_moduleenv = alg_nil();
    (void)v_moduleenv;
    alg_root(&v_moduleenv, 1);
    alg_hold_top = rh_996;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){v_unit}, 1)), alg_literal("system"))))) {
        {
            int32_t rh_997 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Builtins"), "Values")), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1)))))) {
                alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined name '"), alg_hold(alg_str(alg_hold(alg_property(v_name, "Lexeme")))))), alg_literal("' in unit 'System'."))));
            }
            alg_hold_top = rh_997;
            Value ret_200 = alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Builtins"), "Values")), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1));
            alg_root_top = rt_base;
            return ret_200;
            alg_hold_top = rh_997;
        }
    }
    alg_hold_top = rh_996;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "UnitsByName"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_unit}, 1))}, 1)))))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined name '"), alg_hold(alg_str(alg_hold(alg_property(v_name, "Lexeme")))))), alg_literal("' in unit '"))), v_unit)), alg_literal("'."))));
    }
    alg_hold_top = rh_996;
    (void)((v_moduleenv = alg_hold(alg_cast_class(alg_invoke(alg_property(v_this, "UnitsByName"), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_unit}, 1))}, 1), k_environment, "Environment"))));
    alg_hold_top = rh_996;
    if (alg_truthy(alg_hold((or_46 = alg_hold(alg_equal(alg_hold(alg_property(v_moduleenv, "Exports")), alg_nil())), alg_truthy(or_46) ? or_46 : alg_hold(alg_not(alg_hold(alg_invoke(alg_hold(alg_property(v_moduleenv, "Exports")), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1)))))))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined name '"), alg_hold(alg_str(alg_hold(alg_property(v_name, "Lexeme")))))), alg_literal("' in unit '"))), v_unit)), alg_literal("'."))));
    }
    alg_hold_top = rh_996;
    Value ret_201 = alg_hold(alg_invoke(alg_hold(alg_property(v_moduleenv, "Values")), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1));
    alg_root_top = rt_base;
    return ret_201;
    alg_hold_top = rh_996;
    Value ret_202 = alg_nil();
    alg_root_top = rt_base;
    return ret_202;
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
    int32_t rh_998 = alg_hold_top;
    volatile Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    alg_hold_top = rh_998;
    (void)((v_folded = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))));
    alg_hold_top = rh_998;
    if (alg_truthy(alg_is_kind(v_obj, ALG_KIND_STRING))) {
        volatile Value ret_203 = alg_hold(alg_equal(v_folded, alg_literal("length")));
        alg_root_top = rt_base;
        return ret_203;
    }
    alg_hold_top = rh_998;
    if (alg_truthy(alg_hold((or_47 = alg_is_kind(v_obj, ALG_KIND_INTEGER), alg_truthy(or_47) ? or_47 : alg_is_kind(v_obj, ALG_KIND_DOUBLE))))) {
        volatile Value ret_204 = alg_hold(alg_equal(v_folded, alg_literal("tostring")));
        alg_root_top = rt_base;
        return ret_204;
    }
    alg_hold_top = rh_998;
    if (alg_truthy(alg_is_class(v_obj, k_objinstance))) {
        volatile Value ret_205 = alg_hold((or_49 = alg_hold((or_48 = alg_hold(alg_equal(v_folded, alg_literal("classname"))), alg_truthy(or_48) ? or_48 : alg_hold(alg_invoke(alg_hold(alg_property(v_obj, "Klass")), "DeclaresField", (Value[]){v_folded}, 1)))), alg_truthy(or_49) ? or_49 : alg_hold(alg_not_equal(alg_hold(alg_invoke(alg_hold(alg_property(v_obj, "Klass")), "FindMethod", (Value[]){v_folded}, 1)), alg_nil()))));
        alg_root_top = rt_base;
        return ret_205;
    }
    alg_hold_top = rh_998;
    if (alg_truthy(alg_is_class(v_obj, k_objclass))) {
        volatile Value ret_206 = alg_hold((or_54 = alg_hold((or_53 = alg_hold((or_52 = alg_hold((or_51 = alg_hold((or_50 = alg_hold(alg_equal(v_folded, alg_literal("name"))), alg_truthy(or_50) ? or_50 : alg_hold(alg_equal(v_folded, alg_literal("parent"))))), alg_truthy(or_51) ? or_51 : alg_hold(alg_equal(v_folded, alg_literal("fields"))))), alg_truthy(or_52) ? or_52 : alg_hold(alg_equal(v_folded, alg_literal("methods"))))), alg_truthy(or_53) ? or_53 : alg_hold(alg_equal(v_folded, alg_literal("properties"))))), alg_truthy(or_54) ? or_54 : alg_hold(alg_equal(v_folded, alg_literal("accepts")))));
        alg_root_top = rt_base;
        return ret_206;
    }
    alg_hold_top = rh_998;
    if (alg_truthy(alg_hold(alg_not((alg_hold((or_58 = alg_hold((or_57 = alg_hold((or_56 = alg_hold((or_55 = alg_is_class(v_obj, k_objenumtype), alg_truthy(or_55) ? or_55 : alg_is_class(v_obj, k_objenum))), alg_truthy(or_56) ? or_56 : alg_is_class(v_obj, k_objcollection))), alg_truthy(or_57) ? or_57 : alg_is_class(v_obj, k_objfile))), alg_truthy(or_58) ? or_58 : alg_is_class(v_obj, k_objbuffer)))))))) {
        volatile Value ret_207 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_207;
    }
    alg_hold_top = rh_998;
    {
        AlgFrame frame_208;
        alg_push_frame(&frame_208);
        if (ALG_SETJMP(frame_208.jump) == 0) {
            {
                int32_t rh_999 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_obj, "Get", (Value[]){v_name}, 1)));
                alg_hold_top = rh_999;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_208[] = {"String"};
            int32_t which_208 = alg_handler(frame_208.raised, names_208, 1);
            if (which_208 == 0) {
                {
                    int32_t rt_1000 = alg_root_top;
                    volatile Value v_e = frame_208.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_209 = alg_bool(false);
                    alg_root_top = rt_base;
                    return ret_209;
                    alg_root_top = rt_1000;
                }
            }
            else {
                alg_raise(frame_208.raised);
            }
        }
    }
    alg_hold_top = rh_998;
    volatile Value ret_210 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_210;
    alg_hold_top = rh_998;
    volatile Value ret_211 = alg_nil();
    alg_root_top = rt_base;
    return ret_211;
}

static Value m_interpreter_extensionnamed_1_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1001 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_theexpr, "ExtensionUnit")), alg_literal(""))))) {
        Value ret_212 = alg_hold(alg_invoke(v_this, "Qualified", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "ExtensionUnit")))), alg_hold(alg_property(v_theexpr, "Name"))}, 2));
        alg_root_top = rt_base;
        return ret_212;
    }
    alg_hold_top = rh_1001;
    Value ret_213 = alg_hold(alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_hold(alg_property(v_theexpr, "Name"))}, 1));
    alg_root_top = rt_base;
    return ret_213;
    alg_hold_top = rh_1001;
    Value ret_214 = alg_nil();
    alg_root_top = rt_base;
    return ret_214;
}

static Value m_interpreter_visitgetexpr_1_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1002 = alg_hold_top;
    Value v_obj = alg_nil();
    (void)v_obj;
    alg_root(&v_obj, 1);
    alg_hold_top = rh_1002;
    Value v_ascallee = alg_property(v_this, "MemberIsCallee");
    (void)v_ascallee;
    alg_root(&v_ascallee, 1);
    alg_hold_top = rh_1002;
    (void)(alg_set_property(v_this, "MemberIsCallee", alg_bool(false)));
    alg_hold_top = rh_1002;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_theexpr, "Unit")), alg_literal(""))))) {
        Value ret_215 = alg_hold(alg_invoke(v_this, "Qualified", (Value[]){alg_hold(alg_property(v_theexpr, "Unit")), alg_hold(alg_property(v_theexpr, "Name"))}, 2));
        alg_root_top = rt_base;
        return ret_215;
    }
    alg_hold_top = rh_1002;
    (void)((v_obj = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1))));
    alg_hold_top = rh_1002;
    if (alg_truthy(alg_hold((or_59 = alg_hold(alg_not_equal(alg_hold(alg_property(v_theexpr, "Extension")), alg_literal(""))), !alg_truthy(or_59) ? or_59 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Responds", (Value[]){v_obj, alg_hold(alg_property(v_theexpr, "Name"))}, 2)))))))) {
        Value ret_216 = alg_hold(alg_new(k_objextension, (Value[]){v_obj, alg_hold(alg_invoke(v_this, "ExtensionNamed", (Value[]){v_theexpr}, 1))}, 2));
        alg_root_top = rt_base;
        return ret_216;
    }
    alg_hold_top = rh_1002;
    if (alg_truthy(alg_is_kind(v_obj, ALG_KIND_STRING))) {
        {
            int32_t rh_1003 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))}, 1)), alg_literal("length"))))) {
                Value ret_217 = alg_hold(alg_text_length(v_obj));
                alg_root_top = rt_base;
                return ret_217;
            }
            alg_hold_top = rh_1003;
            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined property '"), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme")))))), alg_literal("'."))));
            alg_hold_top = rh_1003;
        }
    }
    alg_hold_top = rh_1002;
    if (alg_truthy(alg_hold((or_60 = alg_is_kind(v_obj, ALG_KIND_INTEGER), alg_truthy(or_60) ? or_60 : alg_is_kind(v_obj, ALG_KIND_DOUBLE))))) {
        {
            int32_t rh_1004 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))}, 1)), alg_literal("tostring"))))) {
                Value ret_218 = alg_hold(alg_new(k_numbermethod, (Value[]){v_obj, alg_hold(alg_property(v_theexpr, "Name"))}, 2));
                alg_root_top = rt_base;
                return ret_218;
            }
            alg_hold_top = rh_1004;
            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined property '"), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme")))))), alg_literal("'."))));
            alg_hold_top = rh_1004;
        }
    }
    alg_hold_top = rh_1002;
    if (alg_truthy(alg_hold(alg_not((alg_hold((or_66 = alg_hold((or_65 = alg_hold((or_64 = alg_hold((or_63 = alg_hold((or_62 = alg_hold((or_61 = alg_is_class(v_obj, k_objinstance), alg_truthy(or_61) ? or_61 : alg_is_class(v_obj, k_objenumtype))), alg_truthy(or_62) ? or_62 : alg_is_class(v_obj, k_objenum))), alg_truthy(or_63) ? or_63 : alg_is_class(v_obj, k_objcollection))), alg_truthy(or_64) ? or_64 : alg_is_class(v_obj, k_objfile))), alg_truthy(or_65) ? or_65 : alg_is_class(v_obj, k_objbuffer))), alg_truthy(or_66) ? or_66 : alg_is_class(v_obj, k_objclass)))))))) {
        {
            int32_t rh_1005 = alg_hold_top;
            alg_raise(alg_literal("Only instances have properties."));
            alg_hold_top = rh_1005;
        }
    }
    alg_hold_top = rh_1002;
    if (alg_truthy(alg_is_class(v_obj, k_objclass))) {
        {
            int32_t rt_1006 = alg_root_top;
            int32_t rh_1007 = alg_hold_top;
            Value v_asked = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 1));
            (void)v_asked;
            alg_root(&v_asked, 1);
            alg_hold_top = rh_1007;
            if (alg_truthy(alg_hold(alg_equal(v_asked, alg_hold(f_foldcase(NULL, (Value[]){alg_literal("Name")}, 1)))))) {
                Value ret_219 = alg_hold(alg_str(alg_hold(alg_property((alg_cast_class(v_obj, k_objclass, "ObjClass")), "Name"))));
                alg_root_top = rt_base;
                return ret_219;
            }
            alg_hold_top = rh_1007;
            if (alg_truthy(alg_hold(alg_equal(v_asked, alg_hold(f_foldcase(NULL, (Value[]){alg_literal("Parent")}, 1)))))) {
                Value ret_220 = alg_hold(alg_property((alg_cast_class(v_obj, k_objclass, "ObjClass")), "Superclass"));
                alg_root_top = rt_base;
                return ret_220;
            }
            alg_hold_top = rh_1007;
            if (alg_truthy(alg_hold(alg_equal(v_asked, alg_hold(f_foldcase(NULL, (Value[]){alg_literal("Accepts")}, 1)))))) {
                Value ret_221 = alg_hold(alg_new(k_classmethod, (Value[]){alg_cast_class(v_obj, k_objclass, "ObjClass"), alg_hold(alg_property(v_theexpr, "Name"))}, 2));
                alg_root_top = rt_base;
                return ret_221;
            }
            alg_hold_top = rh_1007;
            if (alg_truthy(alg_hold(alg_equal(v_asked, alg_hold(f_foldcase(NULL, (Value[]){alg_literal("Fields")}, 1)))))) {
                {
                    int32_t rt_1008 = alg_root_top;
                    int32_t rh_1009 = alg_hold_top;
                    Value v_shaped = alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("Map")}, 1));
                    (void)v_shaped;
                    alg_root(&v_shaped, 1);
                    alg_hold_top = rh_1009;
                    (void)(alg_hold(alg_invoke((alg_cast_class(v_obj, k_objclass, "ObjClass")), "FieldsInto", (Value[]){alg_hold(alg_property(v_shaped, "Pairs"))}, 1)));
                    alg_hold_top = rh_1009;
                    Value ret_222 = v_shaped;
                    alg_root_top = rt_base;
                    return ret_222;
                    alg_hold_top = rh_1009;
                    alg_root_top = rt_1008;
                }
            }
            alg_hold_top = rh_1007;
            if (alg_truthy(alg_hold((or_67 = alg_hold(alg_equal(v_asked, alg_hold(f_foldcase(NULL, (Value[]){alg_literal("Methods")}, 1)))), alg_truthy(or_67) ? or_67 : alg_hold(alg_equal(v_asked, alg_hold(f_foldcase(NULL, (Value[]){alg_literal("Properties")}, 1)))))))) {
                {
                    int32_t rt_1010 = alg_root_top;
                    int32_t rh_1011 = alg_hold_top;
                    Value v_wantproperties = alg_hold(alg_equal(v_asked, alg_hold(f_foldcase(NULL, (Value[]){alg_literal("Properties")}, 1))));
                    (void)v_wantproperties;
                    alg_root(&v_wantproperties, 1);
                    alg_hold_top = rh_1011;
                    Value v_listed = alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("Map")}, 1));
                    (void)v_listed;
                    alg_root(&v_listed, 1);
                    alg_hold_top = rh_1011;
                    Value v_declared = alg_hold(alg_property((alg_cast_class(v_obj, k_objclass, "ObjClass")), "Methods"));
                    (void)v_declared;
                    alg_root(&v_declared, 1);
                    alg_hold_top = rh_1011;
                    {
                        int32_t rt_1012 = alg_root_top;
                        Value loop_223 = alg_iterable(v_declared);
                        (void)loop_223;
                        alg_root(&loop_223, 1);
                        for (int32_t at_223 = 0; at_223 < alg_iterable_count(loop_223); at_223++) {
                            alg_safe_point();
                            int32_t rt_1013 = alg_root_top;
                            Value v_key = alg_iterable_at(loop_223, at_223);
                            (void)v_key;
                            alg_root(&v_key, 1);
                            {
                                int32_t rt_1014 = alg_root_top;
                                int32_t rh_1015 = alg_hold_top;
                                Value v_found = alg_hold(alg_invoke(v_declared, "Get", (Value[]){v_key}, 1));
                                (void)v_found;
                                alg_root(&v_found, 1);
                                alg_hold_top = rh_1015;
                                {
                                    int32_t rt_1016 = alg_root_top;
                                    int32_t rh_1017 = alg_hold_top;
                                    Value v_i = alg_int(0);
                                    (void)v_i;
                                    alg_root(&v_i, 1);
                                    alg_hold_top = rh_1017;
                                    {
                                        int32_t rh_1018 = alg_hold_top;
                                        for (; (alg_hold_top = rh_1018, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_found, "Length")))))); (alg_hold_top = rh_1018, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                                            alg_safe_point();
                                            {
                                                int32_t rt_1019 = alg_root_top;
                                                int32_t rh_1020 = alg_hold_top;
                                                Value v_each = alg_hold(alg_cast_class(alg_subscript_get(v_found, v_i), k_objfunction, "ObjFunction"));
                                                (void)v_each;
                                                alg_root(&v_each, 1);
                                                alg_hold_top = rh_1020;
                                                if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(alg_hold(alg_property(v_each, "Declaration")), "IsProperty")), v_wantproperties)))) {
                                                    continue;
                                                }
                                                alg_hold_top = rh_1020;
                                                Value v_written = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_each, "Declaration")), "Name")), "Lexeme"))));
                                                (void)v_written;
                                                alg_root(&v_written, 1);
                                                alg_hold_top = rh_1020;
                                                if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_hold(alg_property(v_listed, "Pairs")), "Contains", (Value[]){v_written}, 1)))))) {
                                                    (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_listed, "Pairs")), "Put", (Value[]){v_written, alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("List")}, 1))}, 2)));
                                                }
                                                alg_hold_top = rh_1020;
                                                Value v_shape = alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("List")}, 1));
                                                (void)v_shape;
                                                alg_root(&v_shape, 1);
                                                alg_hold_top = rh_1020;
                                                {
                                                    int32_t rt_1021 = alg_root_top;
                                                    Value loop_224 = alg_iterable(alg_hold(alg_property(alg_hold(alg_property(v_each, "Declaration")), "ParamTypes")));
                                                    (void)loop_224;
                                                    alg_root(&loop_224, 1);
                                                    for (int32_t at_224 = 0; at_224 < alg_iterable_count(loop_224); at_224++) {
                                                        alg_safe_point();
                                                        int32_t rt_1022 = alg_root_top;
                                                        Value v_t = alg_iterable_at(loop_224, at_224);
                                                        (void)v_t;
                                                        alg_root(&v_t, 1);
                                                        (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_shape, "Items")), "Add", (Value[]){alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_str(v_t))}, 1))}, 1)));
                                                        alg_root_top = rt_1022;
                                                    }
                                                    alg_root_top = rt_1021;
                                                }
                                                alg_hold_top = rh_1020;
                                                (void)(alg_hold(alg_invoke(alg_hold(alg_property((alg_hold(alg_cast_class(alg_invoke(alg_hold(alg_property(v_listed, "Pairs")), "Get", (Value[]){v_written}, 1), k_objcollection, "ObjCollection"))), "Items")), "Add", (Value[]){v_shape}, 1)));
                                                alg_hold_top = rh_1020;
                                                alg_root_top = rt_1019;
                                            }
                                        }
                                    }
                                    alg_hold_top = rh_1017;
                                    alg_root_top = rt_1016;
                                }
                                alg_hold_top = rh_1015;
                                alg_root_top = rt_1014;
                            }
                            alg_root_top = rt_1013;
                        }
                        alg_root_top = rt_1012;
                    }
                    alg_hold_top = rh_1011;
                    Value ret_225 = v_listed;
                    alg_root_top = rt_base;
                    return ret_225;
                    alg_hold_top = rh_1011;
                    alg_root_top = rt_1010;
                }
            }
            alg_hold_top = rh_1007;
            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined property '"), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme")))))), alg_literal("'."))));
            alg_hold_top = rh_1007;
            alg_root_top = rt_1006;
        }
    }
    alg_hold_top = rh_1002;
    if (alg_truthy(alg_is_class(v_obj, k_objinstance))) {
        {
            int32_t rt_1023 = alg_root_top;
            int32_t rh_1024 = alg_hold_top;
            if (alg_truthy(v_ascallee)) {
                {
                    int32_t rt_1025 = alg_root_top;
                    int32_t rh_1026 = alg_hold_top;
                    Value v_called = alg_hold(alg_invoke(alg_hold(alg_property(v_obj, "Klass")), "FindMethod", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))}, 1))}, 1));
                    (void)v_called;
                    alg_root(&v_called, 1);
                    alg_hold_top = rh_1026;
                    if (alg_truthy(alg_hold(alg_not_equal(v_called, alg_nil())))) {
                        Value ret_226 = alg_hold(alg_invoke(v_called, "Bind", (Value[]){v_obj}, 1));
                        alg_root_top = rt_base;
                        return ret_226;
                    }
                    alg_hold_top = rh_1026;
                    alg_root_top = rt_1025;
                }
            }
            alg_hold_top = rh_1024;
            Value v_member = alg_hold(alg_invoke(alg_hold(alg_property(v_obj, "Klass")), "MethodOfArity", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))}, 1)), alg_int(0)}, 2));
            (void)v_member;
            alg_root(&v_member, 1);
            alg_hold_top = rh_1024;
            if (alg_truthy(alg_hold((or_69 = alg_hold((or_68 = alg_hold(alg_not_equal(v_member, alg_nil())), !alg_truthy(or_68) ? or_68 : alg_hold(alg_property(alg_hold(alg_property(v_member, "Declaration")), "IsProperty")))), !alg_truthy(or_69) ? or_69 : alg_hold(alg_not(alg_hold(alg_invoke(alg_hold(alg_property(v_obj, "Fields")), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))}, 1))}, 1)))))))) {
                Value ret_227 = alg_hold(alg_invoke(alg_hold(alg_invoke(v_member, "Bind", (Value[]){v_obj}, 1)), "Call", (Value[]){v_this, alg_hold(alg_list())}, 2));
                alg_root_top = rt_base;
                return ret_227;
            }
            alg_hold_top = rh_1024;
            alg_root_top = rt_1023;
        }
    }
    alg_hold_top = rh_1002;
    Value ret_228 = alg_hold(alg_invoke(v_obj, "Get", (Value[]){alg_hold(alg_property(v_theexpr, "Name"))}, 1));
    alg_root_top = rt_base;
    return ret_228;
    alg_hold_top = rh_1002;
    Value ret_229 = alg_nil();
    alg_root_top = rt_base;
    return ret_229;
}

static Value m_interpreter_visitsetexpr_1_setexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1027 = alg_hold_top;
    Value v_obj = alg_nil();
    (void)v_obj;
    alg_root(&v_obj, 1);
    alg_hold_top = rh_1027;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_1027;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_theexpr, "Unit")), alg_literal(""))))) {
        {
            int32_t rh_1028 = alg_hold_top;
            (void)((v_value = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1))));
            alg_hold_top = rh_1028;
            (void)(alg_hold(alg_invoke(v_this, "AssignQualified", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "Unit")))), alg_hold(alg_property(v_theexpr, "Name")), v_value}, 3)));
            alg_hold_top = rh_1028;
            Value ret_230 = v_value;
            alg_root_top = rt_base;
            return ret_230;
            alg_hold_top = rh_1028;
        }
    }
    alg_hold_top = rh_1027;
    (void)((v_obj = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1))));
    alg_hold_top = rh_1027;
    if (alg_truthy(alg_hold(alg_not((alg_is_class(v_obj, k_objinstance)))))) {
        {
            int32_t rh_1029 = alg_hold_top;
            alg_raise(alg_literal("Only instances have fields."));
            alg_hold_top = rh_1029;
        }
    }
    alg_hold_top = rh_1027;
    (void)((v_value = alg_hold(alg_invoke(v_this, "Widen", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1)), alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "Declared"))))}, 2))));
    alg_hold_top = rh_1027;
    (void)(alg_hold(alg_invoke(v_obj, "Set", (Value[]){alg_hold(alg_property(v_theexpr, "Name")), v_value}, 2)));
    alg_hold_top = rh_1027;
    Value ret_231 = v_value;
    alg_root_top = rt_base;
    return ret_231;
    alg_hold_top = rh_1027;
    Value ret_232 = alg_nil();
    alg_root_top = rt_base;
    return ret_232;
}

static Value m_interpreter_visitsuperexpr_1_superexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SuperExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1030 = alg_hold_top;
    Value v_distance = alg_nil();
    (void)v_distance;
    alg_root(&v_distance, 1);
    alg_hold_top = rh_1030;
    Value v_superclass = alg_nil();
    (void)v_superclass;
    alg_root(&v_superclass, 1);
    alg_hold_top = rh_1030;
    Value v_obj = alg_nil();
    (void)v_obj;
    alg_root(&v_obj, 1);
    alg_hold_top = rh_1030;
    Value v_method = alg_nil();
    (void)v_method;
    alg_root(&v_method, 1);
    alg_hold_top = rh_1030;
    (void)((v_distance = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "Locals"), "Get", (Value[]){v_theexpr}, 1), ALG_KIND_INTEGER, "Integer"))));
    alg_hold_top = rh_1030;
    (void)((v_superclass = alg_hold(alg_cast_class(alg_invoke(alg_property(v_this, "Env"), "GetAt", (Value[]){v_distance, alg_literal("super")}, 2), k_objclass, "ObjClass"))));
    alg_hold_top = rh_1030;
    (void)((v_obj = alg_hold(alg_cast_class(alg_invoke(alg_property(v_this, "Env"), "GetAt", (Value[]){alg_hold(alg_subtract(v_distance, alg_int(1))), alg_literal("this")}, 2), k_objinstance, "ObjInstance"))));
    alg_hold_top = rh_1030;
    (void)((v_method = alg_hold(alg_invoke(v_superclass, "FindMethod", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Method")), "Lexeme"))}, 1))}, 1))));
    alg_hold_top = rh_1030;
    if (alg_truthy(alg_hold(alg_equal(v_method, alg_nil())))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined property '"), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Method")), "Lexeme")))))), alg_literal("'."))));
    }
    alg_hold_top = rh_1030;
    Value ret_233 = alg_hold(alg_invoke(v_method, "Bind", (Value[]){v_obj}, 1));
    alg_root_top = rt_base;
    return ret_233;
    alg_hold_top = rh_1030;
    Value ret_234 = alg_nil();
    alg_root_top = rt_base;
    return ret_234;
}

static Value m_interpreter_visitthisexpr_1_thisexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "ThisExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1031 = alg_hold_top;
    Value ret_235 = alg_hold(alg_invoke(v_this, "LookupVariable", (Value[]){alg_hold(alg_property(v_theexpr, "Keyword")), v_theexpr}, 2));
    alg_root_top = rt_base;
    return ret_235;
    alg_hold_top = rh_1031;
    Value ret_236 = alg_nil();
    alg_root_top = rt_base;
    return ret_236;
}

static Value m_interpreter_classnameof_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    int32_t rh_1032 = alg_hold_top;
    {
        AlgFrame frame_237;
        alg_push_frame(&frame_237);
        if (ALG_SETJMP(frame_237.jump) == 0) {
            {
                int32_t rh_1033 = alg_hold_top;
                volatile Value ret_238 = alg_hold(alg_property(v_obj, "ClassName"));
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_238;
                alg_hold_top = rh_1033;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_237[] = {"String"};
            int32_t which_237 = alg_handler(frame_237.raised, names_237, 1);
            if (which_237 == 0) {
                {
                    int32_t rt_1034 = alg_root_top;
                    volatile Value v_e = frame_237.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_239 = alg_literal("");
                    alg_root_top = rt_base;
                    return ret_239;
                    alg_root_top = rt_1034;
                }
            }
            else {
                alg_raise(frame_237.raised);
            }
        }
    }
    alg_hold_top = rh_1032;
    volatile Value ret_240 = alg_nil();
    alg_root_top = rt_base;
    return ret_240;
}

static Value m_interpreter_istruthy_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    int32_t rh_1035 = alg_hold_top;
    if (alg_truthy(alg_hold((or_70 = alg_hold(alg_equal(v_obj, alg_nil())), alg_truthy(or_70) ? or_70 : alg_hold(alg_equal(v_obj, alg_bool(false))))))) {
        Value ret_241 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_241;
    }
    alg_hold_top = rh_1035;
    if (alg_truthy(alg_is_kind(v_obj, ALG_KIND_INTEGER))) {
        Value ret_242 = alg_hold(alg_not_equal(v_obj, alg_int(0)));
        alg_root_top = rt_base;
        return ret_242;
    }
    alg_hold_top = rh_1035;
    if (alg_truthy(alg_is_class(v_obj, k_objenum))) {
        Value ret_243 = alg_hold(alg_not_equal(alg_hold(alg_property(v_obj, "Ordinal")), alg_int(0)));
        alg_root_top = rt_base;
        return ret_243;
    }
    alg_hold_top = rh_1035;
    Value ret_244 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_244;
    alg_hold_top = rh_1035;
    Value ret_245 = alg_nil();
    alg_root_top = rt_base;
    return ret_245;
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
    int32_t rh_1036 = alg_hold_top;
    if (alg_truthy(alg_hold((or_71 = alg_hold(alg_equal(v_a, alg_nil())), !alg_truthy(or_71) ? or_71 : alg_hold(alg_equal(v_b, alg_nil())))))) {
        Value ret_246 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_246;
    }
    alg_hold_top = rh_1036;
    if (alg_truthy(alg_hold(alg_equal(v_a, alg_nil())))) {
        Value ret_247 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_247;
    }
    alg_hold_top = rh_1036;
    Value ret_248 = alg_hold(alg_equal(v_a, v_b));
    alg_root_top = rt_base;
    return ret_248;
    alg_hold_top = rh_1036;
    Value ret_249 = alg_nil();
    alg_root_top = rt_base;
    return ret_249;
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
    int32_t rh_1037 = alg_hold_top;
    if (alg_truthy(alg_hold((or_72 = alg_hold(alg_equal(v_declared, alg_literal(""))), alg_truthy(or_72) ? or_72 : alg_hold(alg_equal(v_value, alg_nil())))))) {
        Value ret_250 = v_value;
        alg_root_top = rt_base;
        return ret_250;
    }
    alg_hold_top = rh_1037;
    if (alg_truthy(alg_hold(f_issubrange(NULL, (Value[]){v_declared}, 1)))) {
        {
            int32_t rh_1038 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "InSubrange", (Value[]){v_value, v_declared}, 2)))))) {
                alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_str(v_value)), alg_literal(" is not in "))), v_declared)), alg_char_value(46))));
            }
            alg_hold_top = rh_1038;
            Value ret_251 = v_value;
            alg_root_top = rt_base;
            return ret_251;
            alg_hold_top = rh_1038;
        }
    }
    alg_hold_top = rh_1037;
    if (alg_truthy(alg_hold((or_73 = alg_hold(alg_equal(v_declared, alg_literal("Double"))), !alg_truthy(or_73) ? or_73 : alg_is_kind(v_value, ALG_KIND_INTEGER))))) {
        Value ret_252 = alg_hold(alg_multiply(v_value, alg_double(1.0)));
        alg_root_top = rt_base;
        return ret_252;
    }
    alg_hold_top = rh_1037;
    if (alg_truthy(alg_hold((or_74 = alg_hold(alg_equal(v_declared, alg_literal("String"))), !alg_truthy(or_74) ? or_74 : alg_is_kind(v_value, ALG_KIND_CHAR))))) {
        Value ret_253 = alg_hold(alg_str(v_value));
        alg_root_top = rt_base;
        return ret_253;
    }
    alg_hold_top = rh_1037;
    Value ret_254 = v_value;
    alg_root_top = rt_base;
    return ret_254;
    alg_hold_top = rh_1037;
    Value ret_255 = alg_nil();
    alg_root_top = rt_base;
    return ret_255;
}

static Value m_interpreter_evaluate_1_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "Expr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1039 = alg_hold_top;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_1039;
    (void)((v_value = alg_hold(alg_invoke(v_theexpr, "Accept", (Value[]){v_this}, 1))));
    alg_hold_top = rh_1039;
    if (alg_truthy(alg_hold((or_75 = alg_hold(alg_not_equal(alg_hold(alg_property(v_theexpr, "Cast")), alg_literal(""))), !alg_truthy(or_75) ? or_75 : alg_hold(alg_not_equal(v_value, alg_nil())))))) {
        {
            int32_t rh_1040 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "SatisfiesType", (Value[]){v_value, alg_hold(alg_property(v_theexpr, "Cast"))}, 2)))))) {
                alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Cannot cast "), alg_hold(f_typenameof(NULL, (Value[]){v_value}, 1)))), alg_literal(" to "))), alg_hold(alg_property(v_theexpr, "Cast")))), alg_char_value(46))));
            }
            alg_hold_top = rh_1040;
        }
    }
    alg_hold_top = rh_1039;
    Value ret_256 = v_value;
    alg_root_top = rt_base;
    return ret_256;
    alg_hold_top = rh_1039;
    Value ret_257 = alg_nil();
    alg_root_top = rt_base;
    return ret_257;
}

static Value m_interpreter_execute_1_stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "Stmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1041 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(v_thestmt, "Line")), alg_int(0))))) {
        {
            int32_t rh_1042 = alg_hold_top;
            (void)((alg_declared(d_interpVsiteVfile, "INTERP_SITE_FILE"), (v_interpVsiteVfile = alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "File")))))));
            alg_hold_top = rh_1042;
            (void)((alg_declared(d_interpVsiteVline, "INTERP_SITE_LINE"), (v_interpVsiteVline = alg_hold(alg_property(v_thestmt, "Line")))));
            alg_hold_top = rh_1042;
        }
    }
    alg_hold_top = rh_1041;
    if (alg_truthy(alg_hold(alg_greater((alg_declared(d_interpVcollectVevery, "INTERP_COLLECT_EVERY"), v_interpVcollectVevery), alg_int(0))))) {
        {
            int32_t rh_1043 = alg_hold_top;
            (void)((alg_declared(d_interpVtick, "INTERP_TICK"), (v_interpVtick = alg_hold(alg_add((alg_declared(d_interpVtick, "INTERP_TICK"), v_interpVtick), alg_int(1))))));
            alg_hold_top = rh_1043;
            if (alg_truthy(alg_hold(alg_greater_equal((alg_declared(d_interpVtick, "INTERP_TICK"), v_interpVtick), (alg_declared(d_interpVcollectVevery, "INTERP_COLLECT_EVERY"), v_interpVcollectVevery))))) {
                {
                    int32_t rh_1044 = alg_hold_top;
                    (void)((alg_declared(d_interpVtick, "INTERP_TICK"), (v_interpVtick = alg_int(0))));
                    alg_hold_top = rh_1044;
                    (void)(alg_hold(alg_collected()));
                    alg_hold_top = rh_1044;
                }
            }
            alg_hold_top = rh_1043;
        }
    }
    alg_hold_top = rh_1041;
    (void)(alg_hold(alg_invoke(v_thestmt, "Accept", (Value[]){v_this}, 1)));
    alg_hold_top = rh_1041;
    Value ret_258 = alg_nil();
    alg_root_top = rt_base;
    return ret_258;
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
    int32_t rh_1045 = alg_hold_top;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Put", (Value[]){v_theexpr, v_depth}, 2)));
    alg_hold_top = rh_1045;
    Value ret_259 = alg_nil();
    alg_root_top = rt_base;
    return ret_259;
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
    int32_t rh_1046 = alg_hold_top;
    volatile Value v_previousenv = alg_nil();
    (void)v_previousenv;
    alg_root(&v_previousenv, 1);
    alg_hold_top = rh_1046;
    (void)((v_previousenv = alg_hold(alg_cast_class(alg_property(v_this, "Env"), k_environment, "Environment"))));
    alg_hold_top = rh_1046;
    {
        AlgFrame frame_260;
        alg_push_frame(&frame_260);
        if (ALG_SETJMP(frame_260.jump) == 0) {
            {
                int32_t rt_1047 = alg_root_top;
                int32_t rh_1048 = alg_hold_top;
                (void)(alg_hold(alg_set_property(v_this, "Env", v_newenv)));
                alg_hold_top = rh_1048;
                volatile Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_1048;
                {
                    int32_t rh_1049 = alg_hold_top;
                    while ((alg_hold_top = rh_1049, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_statements, "Length"))))))) {
                        alg_safe_point();
                        {
                            int32_t rh_1050 = alg_hold_top;
                            {
                                AlgFrame frame_261;
                                alg_push_frame(&frame_261);
                                if (ALG_SETJMP(frame_261.jump) == 0) {
                                    {
                                        int32_t rh_1051 = alg_hold_top;
                                        (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_subscript_get(v_statements, v_i))}, 1)));
                                        alg_hold_top = rh_1051;
                                        (void)((v_i = alg_hold(alg_add(v_i, alg_int(1)))));
                                        alg_hold_top = rh_1051;
                                    }
                                    alg_pop_frame();
                                }
                                else {
                                    static const char *names_261[] = {"Jumped"};
                                    int32_t which_261 = alg_handler(frame_261.raised, names_261, 1);
                                    if (which_261 == 0) {
                                        {
                                            int32_t rt_1052 = alg_root_top;
                                            volatile Value v_g = frame_261.raised;
                                            (void)v_g;
                                            alg_root(&v_g, 1);
                                            {
                                                int32_t rt_1053 = alg_root_top;
                                                int32_t rh_1054 = alg_hold_top;
                                                volatile Value v_at = alg_hold(f_labelat(NULL, (Value[]){v_statements, alg_hold(alg_property(v_g, "Label"))}, 2));
                                                (void)v_at;
                                                alg_root(&v_at, 1);
                                                alg_hold_top = rh_1054;
                                                if (alg_truthy(alg_hold(alg_less(v_at, alg_int(0))))) {
                                                    alg_raise(v_g);
                                                }
                                                alg_hold_top = rh_1054;
                                                (void)((v_i = v_at));
                                                alg_hold_top = rh_1054;
                                                alg_root_top = rt_1053;
                                            }
                                            alg_root_top = rt_1052;
                                        }
                                    }
                                    else {
                                        alg_raise(frame_261.raised);
                                    }
                                }
                            }
                            alg_hold_top = rh_1050;
                        }
                    }
                }
                alg_hold_top = rh_1048;
                alg_root_top = rt_1047;
            }
            alg_pop_frame();
        }
        else {
            {
                int32_t rt_1055 = alg_root_top;
                volatile Value v_e = frame_260.raised;
                (void)v_e;
                alg_root(&v_e, 1);
                {
                    int32_t rh_1056 = alg_hold_top;
                    (void)(alg_hold(alg_set_property(v_this, "Env", v_previousenv)));
                    alg_hold_top = rh_1056;
                    alg_raise(v_e);
                    alg_hold_top = rh_1056;
                }
                alg_root_top = rt_1055;
            }
        }
    }
    alg_hold_top = rh_1046;
    (void)(alg_hold(alg_set_property(v_this, "Env", v_previousenv)));
    alg_hold_top = rh_1046;
    volatile Value ret_262 = alg_nil();
    alg_root_top = rt_base;
    return ret_262;
}

static Value m_interpreter_visitblockstmt_1_blockstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "BlockStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1057 = alg_hold_top;
    Value v_newenv = alg_hold(alg_new(k_environment, NULL, 0));
    (void)v_newenv;
    alg_root(&v_newenv, 1);
    alg_hold_top = rh_1057;
    (void)(alg_hold(alg_set_property(v_newenv, "Enclosing", alg_property(v_this, "Env"))));
    alg_hold_top = rh_1057;
    (void)(alg_hold(alg_invoke(v_this, "ExecuteBlock", (Value[]){alg_hold(alg_property(v_thestmt, "Statements")), v_newenv}, 2)));
    alg_hold_top = rh_1057;
    Value ret_263 = alg_nil();
    alg_root_top = rt_base;
    return ret_263;
}

static Value m_interpreter_visitclassstmt_1_classstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ClassStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1058 = alg_hold_top;
    Value v_klass = alg_nil();
    (void)v_klass;
    alg_root(&v_klass, 1);
    alg_hold_top = rh_1058;
    Value v_superclass = alg_nil();
    (void)v_superclass;
    alg_root(&v_superclass, 1);
    alg_hold_top = rh_1058;
    Value v_methods = alg_nil();
    (void)v_methods;
    alg_root(&v_methods, 1);
    alg_hold_top = rh_1058;
    Value v_thefunction = alg_nil();
    (void)v_thefunction;
    alg_root(&v_thefunction, 1);
    alg_hold_top = rh_1058;
    (void)((v_superclass = alg_nil()));
    alg_hold_top = rh_1058;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Superclass")), alg_nil())))) {
        {
            int32_t rh_1059 = alg_hold_top;
            (void)((v_superclass = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Superclass"))}, 1))));
            alg_hold_top = rh_1059;
            if (alg_truthy(alg_hold(alg_not((alg_is_class(v_superclass, k_objclass)))))) {
                {
                    int32_t rh_1060 = alg_hold_top;
                    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Superclass")), "Name")), "Lexeme")))))), alg_literal("' is not a class."))));
                    alg_hold_top = rh_1060;
                }
            }
            alg_hold_top = rh_1059;
        }
    }
    alg_hold_top = rh_1058;
    Value v_shell = alg_hold(alg_invoke(v_this, "HoistedClass", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1));
    (void)v_shell;
    alg_root(&v_shell, 1);
    alg_hold_top = rh_1058;
    if (alg_truthy(alg_hold(alg_equal(v_shell, alg_nil())))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_nil()}, 2)));
    }
    alg_hold_top = rh_1058;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Superclass")), alg_nil())))) {
        {
            int32_t rt_1061 = alg_root_top;
            int32_t rh_1062 = alg_hold_top;
            Value v_previous = alg_property(v_this, "Env");
            (void)v_previous;
            alg_root(&v_previous, 1);
            alg_hold_top = rh_1062;
            (void)(alg_set_property(v_this, "Env", alg_hold(alg_new(k_environment, NULL, 0))));
            alg_hold_top = rh_1062;
            (void)(alg_hold(alg_set_property(alg_property(v_this, "Env"), "Enclosing", v_previous)));
            alg_hold_top = rh_1062;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_literal("super"), v_superclass}, 2)));
            alg_hold_top = rh_1062;
            alg_root_top = rt_1061;
        }
    }
    alg_hold_top = rh_1058;
    (void)((v_methods = alg_hold(alg_map())));
    alg_hold_top = rh_1058;
    {
        int32_t rt_1063 = alg_root_top;
        Value loop_264 = alg_iterable(alg_hold(alg_property(v_thestmt, "Methods")));
        (void)loop_264;
        alg_root(&loop_264, 1);
        for (int32_t at_264 = 0; at_264 < alg_iterable_count(loop_264); at_264++) {
            alg_safe_point();
            int32_t rt_1064 = alg_root_top;
            Value v_method = alg_iterable_at(loop_264, at_264);
            (void)v_method;
            alg_root(&v_method, 1);
            {
                int32_t rt_1065 = alg_root_top;
                int32_t rh_1066 = alg_hold_top;
                (void)((v_thefunction = alg_hold(alg_new(k_objfunction, (Value[]){v_method, alg_property(v_this, "Env"), alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_method, "Name")), "Lexeme"))}, 1)), alg_literal("init")))}, 3))));
                alg_hold_top = rh_1066;
                Value v_methodkey = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_method, "Name")), "Lexeme"))}, 1));
                (void)v_methodkey;
                alg_root(&v_methodkey, 1);
                alg_hold_top = rh_1066;
                if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_methods, "Contains", (Value[]){v_methodkey}, 1)))))) {
                    (void)(alg_hold(alg_invoke(v_methods, "Put", (Value[]){v_methodkey, alg_hold(alg_list())}, 2)));
                }
                alg_hold_top = rh_1066;
                (void)(alg_hold(alg_invoke(alg_hold(alg_invoke(v_methods, "Get", (Value[]){v_methodkey}, 1)), "Add", (Value[]){v_thefunction}, 1)));
                alg_hold_top = rh_1066;
                alg_root_top = rt_1065;
            }
            alg_root_top = rt_1064;
        }
        alg_root_top = rt_1063;
    }
    alg_hold_top = rh_1058;
    if (alg_truthy(alg_hold(alg_not_equal(v_shell, alg_nil())))) {
        {
            int32_t rh_1067 = alg_hold_top;
            (void)((v_klass = alg_cast_class(v_shell, k_objclass, "ObjClass")));
            alg_hold_top = rh_1067;
            (void)(alg_hold(alg_set_property(v_klass, "Superclass", alg_cast_class(v_superclass, k_objclass, "ObjClass"))));
            alg_hold_top = rh_1067;
            (void)(alg_hold(alg_set_property(v_klass, "Methods", v_methods)));
            alg_hold_top = rh_1067;
            (void)(alg_hold(alg_set_property(v_klass, "Fields", alg_hold(alg_property(v_thestmt, "Fields")))));
            alg_hold_top = rh_1067;
        }
    } else {
        (void)((v_klass = alg_hold(alg_new(k_objclass, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), v_superclass, v_methods, alg_hold(alg_property(v_thestmt, "Fields"))}, 4))));
    }
    alg_hold_top = rh_1058;
    {
        int32_t rt_1068 = alg_root_top;
        Value loop_265 = alg_iterable(alg_hold(alg_invoke(v_methods, "Keys", NULL, 0)));
        (void)loop_265;
        alg_root(&loop_265, 1);
        for (int32_t at_265 = 0; at_265 < alg_iterable_count(loop_265); at_265++) {
            alg_safe_point();
            int32_t rt_1069 = alg_root_top;
            Value v_name = alg_iterable_at(loop_265, at_265);
            (void)v_name;
            alg_root(&v_name, 1);
            {
                int32_t rt_1070 = alg_root_top;
                Value loop_266 = alg_iterable(alg_hold(alg_invoke(v_methods, "Get", (Value[]){v_name}, 1)));
                (void)loop_266;
                alg_root(&loop_266, 1);
                for (int32_t at_266 = 0; at_266 < alg_iterable_count(loop_266); at_266++) {
                    alg_safe_point();
                    int32_t rt_1071 = alg_root_top;
                    Value v_each = alg_iterable_at(loop_266, at_266);
                    (void)v_each;
                    alg_root(&v_each, 1);
                    (void)(alg_hold(alg_set_property(v_each, "Owner", v_klass)));
                    alg_root_top = rt_1071;
                }
                alg_root_top = rt_1070;
            }
            alg_root_top = rt_1069;
        }
        alg_root_top = rt_1068;
    }
    alg_hold_top = rh_1058;
    if (alg_truthy(alg_hold(alg_not_equal(v_superclass, alg_nil())))) {
        {
            int32_t rh_1072 = alg_hold_top;
            (void)(alg_set_property(v_this, "Env", alg_hold(alg_property(alg_property(v_this, "Env"), "Enclosing"))));
            alg_hold_top = rh_1072;
        }
    }
    alg_hold_top = rh_1058;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Assign", (Value[]){alg_hold(alg_property(v_thestmt, "Name")), v_klass}, 2)));
    alg_hold_top = rh_1058;
    Value ret_267 = alg_nil();
    alg_root_top = rt_base;
    return ret_267;
}

static Value m_interpreter_visitobjectstmt_1_objectstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ObjectStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1073 = alg_hold_top;
    Value v_klass = alg_nil();
    (void)v_klass;
    alg_root(&v_klass, 1);
    alg_hold_top = rh_1073;
    Value v_hasid = alg_bool(false);
    (void)v_hasid;
    alg_root(&v_hasid, 1);
    alg_hold_top = rh_1073;
    {
        int32_t rt_1074 = alg_root_top;
        Value loop_268 = alg_iterable(alg_hold(alg_property(v_thestmt, "Fields")));
        (void)loop_268;
        alg_root(&loop_268, 1);
        for (int32_t at_268 = 0; at_268 < alg_iterable_count(loop_268); at_268++) {
            alg_safe_point();
            int32_t rt_1075 = alg_root_top;
            Value v_field = alg_iterable_at(loop_268, at_268);
            (void)v_field;
            alg_root(&v_field, 1);
            if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme"))}, 1)), alg_literal("id"))))) {
                (void)((v_hasid = alg_bool(true)));
            }
            alg_root_top = rt_1075;
        }
        alg_root_top = rt_1074;
    }
    alg_hold_top = rh_1073;
    if (alg_truthy(alg_hold(alg_not(v_hasid)))) {
        {
            int32_t rt_1076 = alg_root_top;
            int32_t rh_1077 = alg_hold_top;
            Value v_idname = alg_hold(alg_new(k_token, (Value[]){e_tokentype_tokenVidentifier, alg_literal("Id"), alg_nil(), alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "LineNumber"))}, 4));
            (void)v_idname;
            alg_root(&v_idname, 1);
            alg_hold_top = rh_1077;
            (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_thestmt, "Fields")), "Add", (Value[]){alg_hold(alg_new(k_varstmt, (Value[]){v_idname, alg_hold(alg_new(k_literalexpr, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1))}, 2))}, 1)));
            alg_hold_top = rh_1077;
            alg_root_top = rt_1076;
        }
    }
    alg_hold_top = rh_1073;
    (void)(alg_hold(alg_invoke(v_this, "VisitClassStmt", (Value[]){alg_hold(alg_new(k_classstmt, (Value[]){alg_hold(alg_property(v_thestmt, "Name")), alg_hold(alg_property(v_thestmt, "Superclass")), alg_hold(alg_property(v_thestmt, "Methods")), alg_hold(alg_property(v_thestmt, "Fields"))}, 4))}, 1)));
    alg_hold_top = rh_1073;
    (void)((v_klass = alg_hold(alg_cast_class(alg_invoke(alg_property(v_this, "Env"), "Get", (Value[]){alg_hold(alg_property(v_thestmt, "Name"))}, 1), k_objclass, "ObjClass"))));
    alg_hold_top = rh_1073;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Assign", (Value[]){alg_hold(alg_property(v_thestmt, "Name")), alg_hold(alg_new(k_objsingleton, (Value[]){v_klass, v_this}, 2))}, 2)));
    alg_hold_top = rh_1073;
    Value ret_269 = alg_nil();
    alg_root_top = rt_base;
    return ret_269;
}

static Value m_interpreter_visitsubrangestmt_1_subrangestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "SubrangeStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1078 = alg_hold_top;
    Value ret_270 = alg_nil();
    alg_root_top = rt_base;
    return ret_270;
}

static Value m_interpreter_visitenumstmt_1_enumstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "EnumStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1079 = alg_hold_top;
    Value v_thetype = alg_nil();
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    alg_hold_top = rh_1079;
    (void)((v_thetype = alg_hold(alg_new(k_objenumtype, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))));
    alg_hold_top = rh_1079;
    {
        int32_t rt_1080 = alg_root_top;
        Value loop_271 = alg_iterable(alg_hold(alg_property(v_thestmt, "Members")));
        (void)loop_271;
        alg_root(&loop_271, 1);
        for (int32_t at_271 = 0; at_271 < alg_iterable_count(loop_271); at_271++) {
            alg_safe_point();
            int32_t rt_1081 = alg_root_top;
            Value v_themember = alg_iterable_at(loop_271, at_271);
            (void)v_themember;
            alg_root(&v_themember, 1);
            {
                int32_t rt_1082 = alg_root_top;
                int32_t rh_1083 = alg_hold_top;
                Value v_membername = alg_hold(alg_str(alg_hold(alg_property(v_themember, "Lexeme"))));
                (void)v_membername;
                alg_root(&v_membername, 1);
                alg_hold_top = rh_1083;
                Value v_member = alg_hold(alg_invoke(v_thetype, "Add", (Value[]){v_membername}, 1));
                (void)v_member;
                alg_root(&v_member, 1);
                alg_hold_top = rh_1083;
                Value v_clash = alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Env"), "Values")), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_membername}, 1))}, 1));
                (void)v_clash;
                alg_root(&v_clash, 1);
                alg_hold_top = rh_1083;
                if (alg_truthy(v_clash)) {
                    (void)((v_clash = alg_is_class(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Env"), "Values")), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_membername}, 1))}, 1)), k_objenum)));
                }
                alg_hold_top = rh_1083;
                if (alg_truthy(v_clash)) {
                    (void)((v_clash = alg_hold(alg_not_equal(alg_hold(alg_property((alg_hold(alg_cast_class(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Env"), "Values")), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_membername}, 1))}, 1), k_objenum, "ObjEnum"))), "TypeName")), alg_hold(alg_property(v_thetype, "Name"))))));
                }
                alg_hold_top = rh_1083;
                if (alg_truthy(v_clash)) {
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "MarkAmbiguous", (Value[]){v_membername, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_property((alg_hold(alg_cast_class(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Env"), "Values")), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_membername}, 1))}, 1), k_objenum, "ObjEnum"))), "TypeName")), alg_literal(" or "))), alg_hold(alg_property(v_thetype, "Name"))))}, 2)));
                } else {
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){v_membername, v_member}, 2)));
                }
                alg_hold_top = rh_1083;
                alg_root_top = rt_1082;
            }
            alg_root_top = rt_1081;
        }
        alg_root_top = rt_1080;
    }
    alg_hold_top = rh_1079;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), v_thetype}, 2)));
    alg_hold_top = rh_1079;
    Value ret_272 = alg_nil();
    alg_root_top = rt_base;
    return ret_272;
}

static Value m_interpreter_visitexpressionstmt_1_expressionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "ExpressionStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_1084 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_stmt, "Expression"))}, 1)));
    alg_hold_top = rh_1084;
    Value ret_273 = alg_nil();
    alg_root_top = rt_base;
    return ret_273;
}

static Value m_interpreter_visitfunctionstmt_1_functionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "FunctionStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1085 = alg_hold_top;
    Value v_thefunction = alg_nil();
    (void)v_thefunction;
    alg_root(&v_thefunction, 1);
    alg_hold_top = rh_1085;
    (void)((v_thefunction = alg_hold(alg_new(k_objfunction, (Value[]){v_thestmt, alg_property(v_this, "Env"), alg_bool(false)}, 3))));
    alg_hold_top = rh_1085;
    Value v_key = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1));
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_1085;
    if (alg_truthy(alg_hold((or_76 = alg_hold(alg_not(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Env"), "Values")), "Contains", (Value[]){v_key}, 1)))), !alg_truthy(or_76) ? or_76 : alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Builtins"), "Values")), "Contains", (Value[]){v_key}, 1)))))) {
        {
            int32_t rt_1086 = alg_root_top;
            int32_t rh_1087 = alg_hold_top;
            Value v_shadowing = alg_hold(alg_new(k_objoverloads, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1));
            (void)v_shadowing;
            alg_root(&v_shadowing, 1);
            alg_hold_top = rh_1087;
            (void)(alg_hold(alg_invoke(v_shadowing, "Add", (Value[]){v_thefunction}, 1)));
            alg_hold_top = rh_1087;
            (void)(alg_hold(alg_set_property(v_shadowing, "Fallback", alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Builtins"), "Values")), "Get", (Value[]){v_key}, 1)))));
            alg_hold_top = rh_1087;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), v_shadowing}, 2)));
            alg_hold_top = rh_1087;
            Value ret_274 = alg_nil();
            alg_root_top = rt_base;
            return ret_274;
            alg_hold_top = rh_1087;
            alg_root_top = rt_1086;
        }
    }
    alg_hold_top = rh_1085;
    if (alg_truthy(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Env"), "Values")), "Contains", (Value[]){v_key}, 1)))) {
        {
            int32_t rt_1088 = alg_root_top;
            int32_t rh_1089 = alg_hold_top;
            Value v_existing = alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Env"), "Values")), "Get", (Value[]){v_key}, 1));
            (void)v_existing;
            alg_root(&v_existing, 1);
            alg_hold_top = rh_1089;
            if (alg_truthy(alg_hold((or_77 = alg_hold(alg_not((alg_is_class(v_existing, k_objfunction)))), !alg_truthy(or_77) ? or_77 : alg_hold(alg_not((alg_is_class(v_existing, k_objoverloads)))))))) {
                alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))))), alg_literal("' is already defined."))));
            }
            alg_hold_top = rh_1089;
            Value v_overloads = v_existing;
            (void)v_overloads;
            alg_root(&v_overloads, 1);
            alg_hold_top = rh_1089;
            if (alg_truthy(alg_is_class(v_existing, k_objfunction))) {
                {
                    int32_t rh_1090 = alg_hold_top;
                    (void)((v_overloads = alg_hold(alg_new(k_objoverloads, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1))));
                    alg_hold_top = rh_1090;
                    (void)(alg_hold(alg_invoke(v_overloads, "Add", (Value[]){v_existing}, 1)));
                    alg_hold_top = rh_1090;
                }
            }
            alg_hold_top = rh_1089;
            {
                int32_t rt_1091 = alg_root_top;
                Value loop_275 = alg_iterable(alg_hold(alg_property(v_overloads, "Candidates")));
                (void)loop_275;
                alg_root(&loop_275, 1);
                for (int32_t at_275 = 0; at_275 < alg_iterable_count(loop_275); at_275++) {
                    alg_safe_point();
                    int32_t rt_1092 = alg_root_top;
                    Value v_candidate = alg_iterable_at(loop_275, at_275);
                    (void)v_candidate;
                    alg_root(&v_candidate, 1);
                    if (alg_truthy(alg_hold(f_samesignature(NULL, (Value[]){alg_hold(alg_property(v_candidate, "Declaration")), v_thestmt}, 2)))) {
                        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))))), alg_literal("' is already defined."))));
                    }
                    alg_root_top = rt_1092;
                }
                alg_root_top = rt_1091;
            }
            alg_hold_top = rh_1089;
            (void)(alg_hold(alg_invoke(v_overloads, "Add", (Value[]){v_thefunction}, 1)));
            alg_hold_top = rh_1089;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), v_overloads}, 2)));
            alg_hold_top = rh_1089;
            Value ret_276 = alg_nil();
            alg_root_top = rt_base;
            return ret_276;
            alg_hold_top = rh_1089;
            alg_root_top = rt_1088;
        }
    }
    alg_hold_top = rh_1085;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), v_thefunction}, 2)));
    alg_hold_top = rh_1085;
    Value ret_277 = alg_nil();
    alg_root_top = rt_base;
    return ret_277;
}

static Value m_interpreter_visitifstmt_1_ifstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "IfStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_1093 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsTruthy", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_stmt, "Condition"))}, 1))}, 1)))) {
        (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_stmt, "ThenBranch"))}, 1)));
    } else {
        if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_stmt, "ElseBranch")), alg_nil())))) {
            (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_stmt, "ElseBranch"))}, 1)));
        }
    }
    alg_hold_top = rh_1093;
    Value ret_278 = alg_nil();
    alg_root_top = rt_base;
    return ret_278;
}

static Value m_interpreter_visitwhilestmt_1_whilestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_stmt = alg_widen(args[0], "WhileStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_1094 = alg_hold_top;
    {
        AlgFrame frame_279;
        alg_push_frame(&frame_279);
        if (ALG_SETJMP(frame_279.jump) == 0) {
            {
                int32_t rh_1095 = alg_hold_top;
                {
                    int32_t rh_1096 = alg_hold_top;
                    while ((alg_hold_top = rh_1096, alg_truthy(alg_hold(alg_invoke(v_this, "IsTruthy", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_stmt, "Condition"))}, 1))}, 1))))) {
                        alg_safe_point();
                        {
                            int32_t rh_1097 = alg_hold_top;
                            {
                                AlgFrame frame_280;
                                alg_push_frame(&frame_280);
                                if (ALG_SETJMP(frame_280.jump) == 0) {
                                    {
                                        int32_t rh_1098 = alg_hold_top;
                                        (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_stmt, "Body"))}, 1)));
                                        alg_hold_top = rh_1098;
                                    }
                                    alg_pop_frame();
                                }
                                else {
                                    static const char *names_280[] = {"Continued"};
                                    int32_t which_280 = alg_handler(frame_280.raised, names_280, 1);
                                    if (which_280 == 0) {
                                        {
                                            int32_t rt_1099 = alg_root_top;
                                            volatile Value v_c = frame_280.raised;
                                            (void)v_c;
                                            alg_root(&v_c, 1);
                                            if (alg_truthy(alg_hold(alg_not(alg_hold(f_names(NULL, (Value[]){alg_hold(alg_property(v_c, "Label")), alg_hold(alg_property(v_stmt, "Label"))}, 2)))))) {
                                                alg_raise(v_c);
                                            }
                                            alg_root_top = rt_1099;
                                        }
                                    }
                                    else {
                                        alg_raise(frame_280.raised);
                                    }
                                }
                            }
                            alg_hold_top = rh_1097;
                            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_stmt, "Increment")), alg_nil())))) {
                                (void)(alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_stmt, "Increment"))}, 1)));
                            }
                            alg_hold_top = rh_1097;
                        }
                    }
                }
                alg_hold_top = rh_1095;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_279[] = {"Broke"};
            int32_t which_279 = alg_handler(frame_279.raised, names_279, 1);
            if (which_279 == 0) {
                {
                    int32_t rt_1100 = alg_root_top;
                    volatile Value v_e = frame_279.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    if (alg_truthy(alg_hold(alg_not(alg_hold(f_names(NULL, (Value[]){alg_hold(alg_property(v_e, "Label")), alg_hold(alg_property(v_stmt, "Label"))}, 2)))))) {
                        alg_raise(v_e);
                    }
                    alg_root_top = rt_1100;
                }
            }
            else {
                alg_raise(frame_279.raised);
            }
        }
    }
    alg_hold_top = rh_1094;
    volatile Value ret_281 = alg_nil();
    alg_root_top = rt_base;
    return ret_281;
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
    int32_t rh_1101 = alg_hold_top;
    if (alg_truthy(alg_is_class(v_collection, k_objcollection))) {
        Value ret_282 = alg_hold(alg_invoke(v_collection, "Invoke", (Value[]){alg_literal("contains"), alg_hold(alg_list_keep(alg_list(), v_value))}, 2));
        alg_root_top = rt_base;
        return ret_282;
    }
    alg_hold_top = rh_1101;
    if (alg_truthy(alg_is_class(v_collection, k_objenumtype))) {
        Value ret_283 = alg_hold(alg_invoke(alg_hold(alg_invoke(alg_hold(alg_property(v_collection, "Members")), "Values", NULL, 0)), "Contains", (Value[]){v_value}, 1));
        alg_root_top = rt_base;
        return ret_283;
    }
    alg_hold_top = rh_1101;
    if (alg_truthy(alg_is_class(v_collection, k_objinstance))) {
        {
            int32_t rt_1102 = alg_root_top;
            int32_t rh_1103 = alg_hold_top;
            Value v_method = alg_hold(alg_invoke(alg_hold(alg_property(v_collection, "Klass")), "MethodOfArity", (Value[]){alg_literal("contains"), alg_int(1)}, 2));
            (void)v_method;
            alg_root(&v_method, 1);
            alg_hold_top = rh_1103;
            if (alg_truthy(alg_hold(alg_not_equal(v_method, alg_nil())))) {
                Value ret_284 = alg_hold(alg_invoke(v_this, "IsTruthy", (Value[]){alg_hold(alg_invoke(alg_hold(alg_invoke(v_method, "Bind", (Value[]){v_collection}, 1)), "Call", (Value[]){v_this, alg_hold(alg_list_keep(alg_list(), v_value))}, 2))}, 1));
                alg_root_top = rt_base;
                return ret_284;
            }
            alg_hold_top = rh_1103;
            alg_root_top = rt_1102;
        }
    }
    alg_hold_top = rh_1101;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsText", (Value[]){v_collection}, 1)))) {
        {
            int32_t rh_1104 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(v_value, alg_nil())))) {
                Value ret_285 = alg_bool(false);
                alg_root_top = rt_base;
                return ret_285;
            }
            alg_hold_top = rh_1104;
            Value ret_286 = alg_hold(alg_greater_equal(alg_hold(alg_pos(alg_hold(alg_str(v_collection)), alg_hold(alg_str(v_value)))), alg_int(0)));
            alg_root_top = rt_base;
            return ret_286;
            alg_hold_top = rh_1104;
        }
    }
    alg_hold_top = rh_1101;
    alg_raise(alg_literal("Right operand of 'in' must be a collection or a String."));
    alg_hold_top = rh_1101;
    Value ret_287 = alg_nil();
    alg_root_top = rt_base;
    return ret_287;
}

static Value m_interpreter_iscallable_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    int32_t rh_1105 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(v_value, alg_nil())))) {
        volatile Value ret_288 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_288;
    }
    alg_hold_top = rh_1105;
    {
        AlgFrame frame_289;
        alg_push_frame(&frame_289);
        if (ALG_SETJMP(frame_289.jump) == 0) {
            {
                int32_t rt_1106 = alg_root_top;
                int32_t rh_1107 = alg_hold_top;
                volatile Value v_thearity = alg_hold(alg_property(v_value, "Arity"));
                (void)v_thearity;
                alg_root(&v_thearity, 1);
                alg_hold_top = rh_1107;
                volatile Value ret_290 = alg_bool(true);
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_290;
                alg_hold_top = rh_1107;
                alg_root_top = rt_1106;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_289[] = {"String"};
            int32_t which_289 = alg_handler(frame_289.raised, names_289, 1);
            if (which_289 == 0) {
                {
                    int32_t rt_1108 = alg_root_top;
                    volatile Value v_e = frame_289.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_291 = alg_bool(false);
                    alg_root_top = rt_base;
                    return ret_291;
                    alg_root_top = rt_1108;
                }
            }
            else {
                alg_raise(frame_289.raised);
            }
        }
    }
    alg_hold_top = rh_1105;
    volatile Value ret_292 = alg_nil();
    alg_root_top = rt_base;
    return ret_292;
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
    int32_t rh_1109 = alg_hold_top;
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_1109;
    (void)((v_result = alg_hold(alg_list())));
    alg_hold_top = rh_1109;
    if (alg_truthy(alg_is_class(v_target, k_objcollection))) {
        {
            int32_t rh_1110 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_target, "Kind")), alg_literal("Map"))))) {
                Value ret_293 = alg_hold(alg_invoke(alg_hold(alg_property(v_target, "Pairs")), "Keys", NULL, 0));
                alg_root_top = rt_base;
                return ret_293;
            }
            alg_hold_top = rh_1110;
            {
                int32_t rt_1111 = alg_root_top;
                Value loop_294 = alg_iterable(alg_hold(alg_property(v_target, "Items")));
                (void)loop_294;
                alg_root(&loop_294, 1);
                for (int32_t at_294 = 0; at_294 < alg_iterable_count(loop_294); at_294++) {
                    alg_safe_point();
                    int32_t rt_1112 = alg_root_top;
                    Value v_item = alg_iterable_at(loop_294, at_294);
                    (void)v_item;
                    alg_root(&v_item, 1);
                    (void)(alg_hold(alg_invoke(v_result, "Add", (Value[]){v_item}, 1)));
                    alg_root_top = rt_1112;
                }
                alg_root_top = rt_1111;
            }
            alg_hold_top = rh_1110;
            Value ret_295 = v_result;
            alg_root_top = rt_base;
            return ret_295;
            alg_hold_top = rh_1110;
        }
    }
    alg_hold_top = rh_1109;
    if (alg_truthy(alg_is_class(v_target, k_objenumtype))) {
        Value ret_296 = alg_hold(alg_invoke(alg_hold(alg_property(v_target, "Members")), "Values", NULL, 0));
        alg_root_top = rt_base;
        return ret_296;
    }
    alg_hold_top = rh_1109;
    if (alg_truthy(alg_is_class(v_target, k_objinstance))) {
        {
            int32_t rt_1113 = alg_root_top;
            int32_t rh_1114 = alg_hold_top;
            Value v_elements = alg_hold(alg_invoke(alg_hold(alg_property(v_target, "Klass")), "MethodOfArity", (Value[]){alg_literal("elements"), alg_int(0)}, 2));
            (void)v_elements;
            alg_root(&v_elements, 1);
            alg_hold_top = rh_1114;
            if (alg_truthy(alg_hold(alg_not_equal(v_elements, alg_nil())))) {
                Value ret_297 = alg_hold(alg_invoke(v_this, "ElementsOf", (Value[]){v_where, alg_hold(alg_invoke(alg_hold(alg_invoke(v_elements, "Bind", (Value[]){v_target}, 1)), "Call", (Value[]){v_this, alg_hold(alg_list())}, 2))}, 2));
                alg_root_top = rt_base;
                return ret_297;
            }
            alg_hold_top = rh_1114;
            alg_root_top = rt_1113;
        }
    }
    alg_hold_top = rh_1109;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsText", (Value[]){v_target}, 1)))) {
        {
            int32_t rt_1115 = alg_root_top;
            int32_t rh_1116 = alg_hold_top;
            Value v_text = alg_hold(alg_str(v_target));
            (void)v_text;
            alg_root(&v_text, 1);
            alg_hold_top = rh_1116;
            {
                int32_t rt_1117 = alg_root_top;
                int32_t rh_1118 = alg_hold_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_1118;
                {
                    int32_t rh_1119 = alg_hold_top;
                    for (; (alg_hold_top = rh_1119, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_text_length(v_text)))))); (alg_hold_top = rh_1119, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                        alg_safe_point();
                        (void)(alg_hold(alg_invoke(v_result, "Add", (Value[]){alg_hold(alg_subscript_get(v_text, v_i))}, 1)));
                    }
                }
                alg_hold_top = rh_1118;
                alg_root_top = rt_1117;
            }
            alg_hold_top = rh_1116;
            Value ret_298 = v_result;
            alg_root_top = rt_base;
            return ret_298;
            alg_hold_top = rh_1116;
            alg_root_top = rt_1115;
        }
    }
    alg_hold_top = rh_1109;
    alg_raise(alg_literal("Can only iterate a collection or a String."));
    alg_hold_top = rh_1109;
    Value ret_299 = alg_nil();
    alg_root_top = rt_base;
    return ret_299;
}

static Value m_interpreter_visitforinstmt_1_forinstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_thestmt = alg_widen(args[0], "ForInStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1120 = alg_hold_top;
    volatile Value v_elements = alg_nil();
    (void)v_elements;
    alg_root(&v_elements, 1);
    alg_hold_top = rh_1120;
    (void)((v_elements = alg_hold(alg_invoke(v_this, "ElementsOf", (Value[]){alg_hold(alg_property(v_thestmt, "Name")), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Iterable"))}, 1))}, 2))));
    alg_hold_top = rh_1120;
    {
        AlgFrame frame_300;
        alg_push_frame(&frame_300);
        if (ALG_SETJMP(frame_300.jump) == 0) {
            {
                int32_t rh_1121 = alg_hold_top;
                {
                    int32_t rt_1122 = alg_root_top;
                    volatile Value loop_301 = alg_iterable(v_elements);
                    (void)loop_301;
                    alg_root(&loop_301, 1);
                    for (volatile int32_t at_301 = 0; at_301 < alg_iterable_count(loop_301); at_301++) {
                        alg_safe_point();
                        int32_t rt_1123 = alg_root_top;
                        volatile Value v_element = alg_iterable_at(loop_301, at_301);
                        (void)v_element;
                        alg_root(&v_element, 1);
                        {
                            int32_t rt_1124 = alg_root_top;
                            int32_t rh_1125 = alg_hold_top;
                            volatile Value v_scope = alg_hold(alg_new(k_environment, NULL, 0));
                            (void)v_scope;
                            alg_root(&v_scope, 1);
                            alg_hold_top = rh_1125;
                            (void)(alg_hold(alg_set_property(v_scope, "Enclosing", alg_property(v_this, "Env"))));
                            alg_hold_top = rh_1125;
                            (void)(alg_hold(alg_invoke(v_scope, "Define", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), v_element}, 2)));
                            alg_hold_top = rh_1125;
                            {
                                AlgFrame frame_302;
                                alg_push_frame(&frame_302);
                                if (ALG_SETJMP(frame_302.jump) == 0) {
                                    {
                                        int32_t rh_1126 = alg_hold_top;
                                        (void)(alg_hold(alg_invoke(v_this, "ExecuteBlock", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "Body")))), v_scope}, 2)));
                                        alg_hold_top = rh_1126;
                                    }
                                    alg_pop_frame();
                                }
                                else {
                                    static const char *names_302[] = {"Continued"};
                                    int32_t which_302 = alg_handler(frame_302.raised, names_302, 1);
                                    if (which_302 == 0) {
                                        {
                                            int32_t rt_1127 = alg_root_top;
                                            volatile Value v_c = frame_302.raised;
                                            (void)v_c;
                                            alg_root(&v_c, 1);
                                            if (alg_truthy(alg_hold(alg_not(alg_hold(f_names(NULL, (Value[]){alg_hold(alg_property(v_c, "Label")), alg_hold(alg_property(v_thestmt, "Label"))}, 2)))))) {
                                                alg_raise(v_c);
                                            }
                                            alg_root_top = rt_1127;
                                        }
                                    }
                                    else {
                                        alg_raise(frame_302.raised);
                                    }
                                }
                            }
                            alg_hold_top = rh_1125;
                            alg_root_top = rt_1124;
                        }
                        alg_root_top = rt_1123;
                    }
                    alg_root_top = rt_1122;
                }
                alg_hold_top = rh_1121;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_300[] = {"Broke"};
            int32_t which_300 = alg_handler(frame_300.raised, names_300, 1);
            if (which_300 == 0) {
                {
                    int32_t rt_1128 = alg_root_top;
                    volatile Value v_e = frame_300.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    if (alg_truthy(alg_hold(alg_not(alg_hold(f_names(NULL, (Value[]){alg_hold(alg_property(v_e, "Label")), alg_hold(alg_property(v_thestmt, "Label"))}, 2)))))) {
                        alg_raise(v_e);
                    }
                    alg_root_top = rt_1128;
                }
            }
            else {
                alg_raise(frame_300.raised);
            }
        }
    }
    alg_hold_top = rh_1120;
    volatile Value ret_303 = alg_nil();
    alg_root_top = rt_base;
    return ret_303;
}

static Value m_interpreter_visitbreakstmt_1_breakstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "BreakStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1129 = alg_hold_top;
    alg_raise(alg_hold(alg_new(k_broke, (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1)));
    alg_hold_top = rh_1129;
    Value ret_304 = alg_nil();
    alg_root_top = rt_base;
    return ret_304;
}

static Value m_interpreter_visitcontinuestmt_1_continuestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ContinueStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1130 = alg_hold_top;
    alg_raise(alg_hold(alg_new(k_continued, (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1)));
    alg_hold_top = rh_1130;
    Value ret_305 = alg_nil();
    alg_root_top = rt_base;
    return ret_305;
}

static Value m_interpreter_visitlabelstmt_1_labelstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "LabelStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1131 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_thestmt, "Inner"))}, 1)));
    alg_hold_top = rh_1131;
    Value ret_306 = alg_nil();
    alg_root_top = rt_base;
    return ret_306;
}

static Value m_interpreter_visitgotostmt_1_gotostmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "GotoStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1132 = alg_hold_top;
    alg_raise(alg_hold(alg_new(k_jumped, (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1)));
    alg_hold_top = rh_1132;
    Value ret_307 = alg_nil();
    alg_root_top = rt_base;
    return ret_307;
}

static Value m_interpreter_visitmodulestmt_1_modulestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ModuleStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1133 = alg_hold_top;
    Value v_importer = alg_nil();
    (void)v_importer;
    alg_root(&v_importer, 1);
    alg_hold_top = rh_1133;
    Value v_moduleenv = alg_nil();
    (void)v_moduleenv;
    alg_root(&v_moduleenv, 1);
    alg_hold_top = rh_1133;
    Value v_exported = alg_nil();
    (void)v_exported;
    alg_root(&v_exported, 1);
    alg_hold_top = rh_1133;
    (void)((v_importer = alg_property(v_this, "Env")));
    alg_hold_top = rh_1133;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Modules"), "Contains", (Value[]){alg_hold(alg_property(v_thestmt, "FileName"))}, 1)))) {
        {
            int32_t rt_1134 = alg_root_top;
            int32_t rh_1135 = alg_hold_top;
            Value v_already = alg_hold(alg_cast_class(alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_hold(alg_property(v_thestmt, "FileName"))}, 1), k_environment, "Environment"));
            (void)v_already;
            alg_root(&v_already, 1);
            alg_hold_top = rh_1135;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_already, "UnitName")), alg_literal(""))))) {
                (void)(alg_hold(alg_set_property(v_already, "UnitName", alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "UnitName")))))));
            }
            alg_hold_top = rh_1135;
            (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_importer, "Imports")), "Add", (Value[]){alg_hold(alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_hold(alg_property(v_thestmt, "FileName"))}, 1))}, 1)));
            alg_hold_top = rh_1135;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "UnitsByName"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_thestmt, "UnitName"))}, 1)), alg_hold(alg_invoke(alg_property(v_this, "Modules"), "Get", (Value[]){alg_hold(alg_property(v_thestmt, "FileName"))}, 1))}, 2)));
            alg_hold_top = rh_1135;
            Value ret_308 = alg_nil();
            alg_root_top = rt_base;
            return ret_308;
            alg_hold_top = rh_1135;
            alg_root_top = rt_1134;
        }
    }
    alg_hold_top = rh_1133;
    (void)((v_moduleenv = alg_hold(alg_new(k_environment, NULL, 0))));
    alg_hold_top = rh_1133;
    (void)(alg_hold(alg_set_property(v_moduleenv, "Enclosing", alg_property(v_this, "Builtins"))));
    alg_hold_top = rh_1133;
    (void)(alg_hold(alg_set_property(v_moduleenv, "UnitName", alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "UnitName")))))));
    alg_hold_top = rh_1133;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Modules"), "Put", (Value[]){alg_hold(alg_property(v_thestmt, "FileName")), v_moduleenv}, 2)));
    alg_hold_top = rh_1133;
    (void)(alg_hold(alg_invoke(v_this, "ExecuteBlock", (Value[]){alg_hold(alg_property(v_thestmt, "Statements")), v_moduleenv}, 2)));
    alg_hold_top = rh_1133;
    (void)((v_exported = alg_hold(alg_list())));
    alg_hold_top = rh_1133;
    Value v_hidden = alg_hold(alg_set());
    (void)v_hidden;
    alg_root(&v_hidden, 1);
    alg_hold_top = rh_1133;
    {
        int32_t rt_1136 = alg_root_top;
        Value loop_309 = alg_iterable(alg_hold(alg_property(v_thestmt, "PrivateNames")));
        (void)loop_309;
        alg_root(&loop_309, 1);
        for (int32_t at_309 = 0; at_309 < alg_iterable_count(loop_309); at_309++) {
            alg_safe_point();
            int32_t rt_1137 = alg_root_top;
            Value v_privatename = alg_iterable_at(loop_309, at_309);
            (void)v_privatename;
            alg_root(&v_privatename, 1);
            (void)(alg_hold(alg_invoke(v_hidden, "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_privatename}, 1))}, 1)));
            alg_root_top = rt_1137;
        }
        alg_root_top = rt_1136;
    }
    alg_hold_top = rh_1133;
    Value v_names = alg_hold(alg_invoke(alg_hold(alg_property(v_moduleenv, "Values")), "Keys", NULL, 0));
    (void)v_names;
    alg_root(&v_names, 1);
    alg_hold_top = rh_1133;
    {
        int32_t rt_1138 = alg_root_top;
        Value loop_310 = alg_iterable(v_names);
        (void)loop_310;
        alg_root(&loop_310, 1);
        for (int32_t at_310 = 0; at_310 < alg_iterable_count(loop_310); at_310++) {
            alg_safe_point();
            int32_t rt_1139 = alg_root_top;
            Value v_thename = alg_iterable_at(loop_310, at_310);
            (void)v_thename;
            alg_root(&v_thename, 1);
            {
                int32_t rh_1140 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_hidden, "Contains", (Value[]){v_thename}, 1)))))) {
                    (void)(alg_hold(alg_invoke(v_exported, "Add", (Value[]){v_thename}, 1)));
                }
                alg_hold_top = rh_1140;
            }
            alg_root_top = rt_1139;
        }
        alg_root_top = rt_1138;
    }
    alg_hold_top = rh_1133;
    (void)(alg_hold(alg_set_property(v_moduleenv, "Exports", alg_hold(alg_set()))));
    alg_hold_top = rh_1133;
    {
        int32_t rt_1141 = alg_root_top;
        Value loop_311 = alg_iterable(v_exported);
        (void)loop_311;
        alg_root(&loop_311, 1);
        for (int32_t at_311 = 0; at_311 < alg_iterable_count(loop_311); at_311++) {
            alg_safe_point();
            int32_t rt_1142 = alg_root_top;
            Value v_each = alg_iterable_at(loop_311, at_311);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_moduleenv, "Exports")), "Add", (Value[]){v_each}, 1)));
            alg_root_top = rt_1142;
        }
        alg_root_top = rt_1141;
    }
    alg_hold_top = rh_1133;
    (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_importer, "Imports")), "Add", (Value[]){v_moduleenv}, 1)));
    alg_hold_top = rh_1133;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "UnitsByName"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_thestmt, "UnitName"))}, 1)), v_moduleenv}, 2)));
    alg_hold_top = rh_1133;
    Value ret_312 = alg_nil();
    alg_root_top = rt_base;
    return ret_312;
}

static Value m_interpreter_visitraisestmt_1_raisestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "RaiseStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1143 = alg_hold_top;
    alg_raise(alg_hold(alg_new(k_raised, (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Value"))}, 1))}, 1)));
    alg_hold_top = rh_1143;
    Value ret_313 = alg_nil();
    alg_root_top = rt_base;
    return ret_313;
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
    int32_t rh_1144 = alg_hold_top;
    Value v_klass = alg_nil();
    (void)v_klass;
    alg_root(&v_klass, 1);
    alg_hold_top = rh_1144;
    if (alg_truthy(alg_is_class(v_value, k_objinstance))) {
        {
            int32_t rh_1145 = alg_hold_top;
            (void)((v_klass = alg_hold(alg_cast_class(alg_property(v_value, "Klass"), k_objclass, "ObjClass"))));
            alg_hold_top = rh_1145;
            {
                int32_t rh_1146 = alg_hold_top;
                while ((alg_hold_top = rh_1146, alg_truthy(alg_hold(alg_not_equal(v_klass, alg_nil()))))) {
                    alg_safe_point();
                    {
                        int32_t rt_1147 = alg_root_top;
                        int32_t rh_1148 = alg_hold_top;
                        Value v_thename = alg_hold(alg_str(alg_hold(alg_property(v_klass, "Name"))));
                        (void)v_thename;
                        alg_root(&v_thename, 1);
                        alg_hold_top = rh_1148;
                        if (alg_truthy(alg_hold(alg_invoke(v_handlers, "Contains", (Value[]){v_thename}, 1)))) {
                            Value ret_314 = alg_hold(alg_cast_class(alg_invoke(v_handlers, "Get", (Value[]){v_thename}, 1), k_excepthandler, "ExceptHandler"));
                            alg_root_top = rt_base;
                            return ret_314;
                        }
                        alg_hold_top = rh_1148;
                        (void)((v_klass = alg_hold(alg_property(v_klass, "Superclass"))));
                        alg_hold_top = rh_1148;
                        alg_root_top = rt_1147;
                    }
                }
            }
            alg_hold_top = rh_1145;
            Value ret_315 = alg_nil();
            alg_root_top = rt_base;
            return ret_315;
            alg_hold_top = rh_1145;
        }
    }
    alg_hold_top = rh_1144;
    Value v_typename = alg_hold(f_typenameof(NULL, (Value[]){v_value}, 1));
    (void)v_typename;
    alg_root(&v_typename, 1);
    alg_hold_top = rh_1144;
    if (alg_truthy(alg_hold(alg_invoke(v_handlers, "Contains", (Value[]){v_typename}, 1)))) {
        Value ret_316 = alg_hold(alg_cast_class(alg_invoke(v_handlers, "Get", (Value[]){v_typename}, 1), k_excepthandler, "ExceptHandler"));
        alg_root_top = rt_base;
        return ret_316;
    }
    alg_hold_top = rh_1144;
    Value ret_317 = alg_nil();
    alg_root_top = rt_base;
    return ret_317;
    alg_hold_top = rh_1144;
    Value ret_318 = alg_nil();
    alg_root_top = rt_base;
    return ret_318;
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
    int32_t rh_1149 = alg_hold_top;
    Value v_handler = alg_nil();
    (void)v_handler;
    alg_root(&v_handler, 1);
    alg_hold_top = rh_1149;
    (void)((v_handler = alg_hold(alg_invoke(v_this, "FindHandler", (Value[]){alg_hold(alg_property(v_thestmt, "Handlers")), v_value}, 2))));
    alg_hold_top = rh_1149;
    if (alg_truthy(alg_hold((or_78 = alg_hold(alg_equal(v_handler, alg_nil())), !alg_truthy(or_78) ? or_78 : alg_hold(alg_invoke(alg_hold(alg_property(v_thestmt, "Handlers")), "Contains", (Value[]){alg_literal("default")}, 1)))))) {
        (void)((v_handler = alg_hold(alg_cast_class(alg_invoke(alg_hold(alg_property(v_thestmt, "Handlers")), "Get", (Value[]){alg_literal("default")}, 1), k_excepthandler, "ExceptHandler"))));
    }
    alg_hold_top = rh_1149;
    if (alg_truthy(alg_hold(alg_equal(v_handler, alg_nil())))) {
        alg_raise(v_original);
    }
    alg_hold_top = rh_1149;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_hold(alg_property(v_handler, "Name")), v_value}, 2)));
    alg_hold_top = rh_1149;
    (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_handler, "Body"))}, 1)));
    alg_hold_top = rh_1149;
    Value ret_319 = alg_nil();
    alg_root_top = rt_base;
    return ret_319;
}

static Value m_interpreter_visittrystmt_1_trystmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_thestmt = alg_widen(args[0], "TryStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1150 = alg_hold_top;
    {
        AlgFrame frame_320;
        alg_push_frame(&frame_320);
        if (ALG_SETJMP(frame_320.jump) == 0) {
            {
                int32_t rh_1151 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_thestmt, "TryBlock"))}, 1)));
                alg_hold_top = rh_1151;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_320[] = {"Return", "Raised", "String"};
            int32_t which_320 = alg_handler(frame_320.raised, names_320, 3);
            if (which_320 == 0) {
                {
                    int32_t rt_1152 = alg_root_top;
                    volatile Value v_e = frame_320.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    alg_raise(v_e);
                    alg_root_top = rt_1152;
                }
            }
            else if (which_320 == 1) {
                {
                    int32_t rt_1153 = alg_root_top;
                    volatile Value v_e = frame_320.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    (void)(alg_hold(alg_invoke(v_this, "Handle", (Value[]){v_thestmt, alg_hold(alg_property(v_e, "Value")), v_e}, 3)));
                    alg_root_top = rt_1153;
                }
            }
            else if (which_320 == 2) {
                {
                    int32_t rt_1154 = alg_root_top;
                    volatile Value v_e = frame_320.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    (void)(alg_hold(alg_invoke(v_this, "Handle", (Value[]){v_thestmt, v_e, v_e}, 3)));
                    alg_root_top = rt_1154;
                }
            }
            else {
                alg_raise(frame_320.raised);
            }
        }
    }
    alg_hold_top = rh_1150;
    volatile Value ret_321 = alg_nil();
    alg_root_top = rt_base;
    return ret_321;
}

static Value m_interpreter_visitreturnstmt_1_returnstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "ReturnStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_1155 = alg_hold_top;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_1155;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_stmt, "Value")), alg_nil())))) {
        (void)((v_value = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_stmt, "Value"))}, 1))));
    }
    alg_hold_top = rh_1155;
    alg_raise(alg_hold(alg_new(k_return, (Value[]){v_value}, 1)));
    alg_hold_top = rh_1155;
    Value ret_322 = alg_nil();
    alg_root_top = rt_base;
    return ret_322;
}

static Value m_interpreter_visitvarstmt_1_varstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "VarStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_1156 = alg_hold_top;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_1156;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_stmt, "Initializer")), alg_nil())))) {
        {
            int32_t rh_1157 = alg_hold_top;
            (void)((v_value = alg_hold(alg_invoke(v_this, "Widen", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_stmt, "Initializer"))}, 1)), alg_hold(alg_str(alg_hold(alg_property(v_stmt, "TypeName"))))}, 2))));
            alg_hold_top = rh_1157;
        }
    }
    alg_hold_top = rh_1156;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_stmt, "Name")), "Lexeme")), v_value}, 2)));
    alg_hold_top = rh_1156;
    Value ret_323 = alg_nil();
    alg_root_top = rt_base;
    return ret_323;
}

static Value m_interpreter_visitvargroupstmt_1_vargroupstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "VarGroupStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1158 = alg_hold_top;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_1158;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Initializer")), alg_nil())))) {
        (void)((v_value = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Initializer"))}, 1))));
    }
    alg_hold_top = rh_1158;
    {
        int32_t rt_1159 = alg_root_top;
        Value loop_324 = alg_iterable(alg_hold(alg_property(v_thestmt, "Names")));
        (void)loop_324;
        alg_root(&loop_324, 1);
        for (int32_t at_324 = 0; at_324 < alg_iterable_count(loop_324); at_324++) {
            alg_safe_point();
            int32_t rt_1160 = alg_root_top;
            Value v_thename = alg_iterable_at(loop_324, at_324);
            (void)v_thename;
            alg_root(&v_thename, 1);
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Define", (Value[]){alg_hold(alg_property(v_thename, "Lexeme")), v_value}, 2)));
            alg_root_top = rt_1160;
        }
        alg_root_top = rt_1159;
    }
    alg_hold_top = rh_1158;
    Value ret_325 = alg_nil();
    alg_root_top = rt_base;
    return ret_325;
}

static Value m_interpreter_visitassignexpr_1_assignexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_expr = alg_widen(args[0], "AssignExpr");
    (void)v_expr;
    alg_root(&v_expr, 1);
    int32_t rh_1161 = alg_hold_top;
    volatile Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_1161;
    volatile Value v_distance = alg_nil();
    (void)v_distance;
    alg_root(&v_distance, 1);
    alg_hold_top = rh_1161;
    (void)((v_value = alg_hold(alg_invoke(v_this, "Widen", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_expr, "Value"))}, 1)), alg_hold(alg_str(alg_hold(alg_property(v_expr, "Declared"))))}, 2))));
    alg_hold_top = rh_1161;
    (void)((v_distance = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "Locals"), "Get", (Value[]){v_expr}, 1), ALG_KIND_INTEGER, "Integer"))));
    alg_hold_top = rh_1161;
    if (alg_truthy(alg_hold(alg_not_equal(v_distance, alg_nil())))) {
        {
            int32_t rh_1162 = alg_hold_top;
            {
                AlgFrame frame_326;
                alg_push_frame(&frame_326);
                if (ALG_SETJMP(frame_326.jump) == 0) {
                    {
                        int32_t rh_1163 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "AssignAt", (Value[]){v_distance, alg_hold(alg_property(v_expr, "Name")), v_value}, 3)));
                        alg_hold_top = rh_1163;
                    }
                    alg_pop_frame();
                }
                else {
                    static const char *names_326[] = {"String"};
                    int32_t which_326 = alg_handler(frame_326.raised, names_326, 1);
                    if (which_326 == 0) {
                        {
                            int32_t rt_1164 = alg_root_top;
                            volatile Value v_e = frame_326.raised;
                            (void)v_e;
                            alg_root(&v_e, 1);
                            (void)(alg_hold(alg_invoke(v_this, "SetThisField", (Value[]){alg_hold(alg_property(v_expr, "Name")), v_value, v_e}, 3)));
                            alg_root_top = rt_1164;
                        }
                    }
                    else {
                        alg_raise(frame_326.raised);
                    }
                }
            }
            alg_hold_top = rh_1162;
        }
    } else {
        {
            int32_t rh_1165 = alg_hold_top;
            {
                AlgFrame frame_327;
                alg_push_frame(&frame_327);
                if (ALG_SETJMP(frame_327.jump) == 0) {
                    {
                        int32_t rh_1166 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Env"), "Assign", (Value[]){alg_hold(alg_property(v_expr, "Name")), v_value}, 2)));
                        alg_hold_top = rh_1166;
                    }
                    alg_pop_frame();
                }
                else {
                    static const char *names_327[] = {"String"};
                    int32_t which_327 = alg_handler(frame_327.raised, names_327, 1);
                    if (which_327 == 0) {
                        {
                            int32_t rt_1167 = alg_root_top;
                            volatile Value v_e = frame_327.raised;
                            (void)v_e;
                            alg_root(&v_e, 1);
                            (void)(alg_hold(alg_invoke(v_this, "SetThisField", (Value[]){alg_hold(alg_property(v_expr, "Name")), v_value, v_e}, 3)));
                            alg_root_top = rt_1167;
                        }
                    }
                    else {
                        alg_raise(frame_327.raised);
                    }
                }
            }
            alg_hold_top = rh_1165;
        }
    }
    alg_hold_top = rh_1161;
    volatile Value ret_328 = v_value;
    alg_root_top = rt_base;
    return ret_328;
    alg_hold_top = rh_1161;
    volatile Value ret_329 = alg_nil();
    alg_root_top = rt_base;
    return ret_329;
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
    int32_t rh_1168 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Label", v_label)));
    alg_hold_top = rh_1168;
    Value ret_330 = alg_nil();
    alg_root_top = rt_base;
    return ret_330;
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
    int32_t rh_1169 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Label", v_label)));
    alg_hold_top = rh_1169;
    Value ret_331 = alg_nil();
    alg_root_top = rt_base;
    return ret_331;
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
    int32_t rh_1170 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Label", v_label)));
    alg_hold_top = rh_1170;
    Value ret_332 = alg_nil();
    alg_root_top = rt_base;
    return ret_332;
}

Value f_labelat(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_statements = alg_param_of(args[0], "List", "LabelAt");
    (void)v_statements;
    alg_root(&v_statements, 1);
    Value v_named = alg_param_of(args[1], "String", "LabelAt");
    (void)v_named;
    alg_root(&v_named, 1);
    int32_t rh_1171 = alg_hold_top;
    {
        int32_t rt_1172 = alg_root_top;
        int32_t rh_1173 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1173;
        {
            int32_t rh_1174 = alg_hold_top;
            for (; (alg_hold_top = rh_1174, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_statements, "Length")))))); (alg_hold_top = rh_1174, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_is_class(alg_hold(alg_subscript_get(v_statements, v_i)), k_labelstmt))) {
                    if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_subscript_get(v_statements, v_i)), "Name")), "Lexeme"))))}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_named}, 1)))))) {
                        Value ret_333 = v_i;
                        alg_root_top = rt_base;
                        return ret_333;
                    }
                }
            }
        }
        alg_hold_top = rh_1173;
        alg_root_top = rt_1172;
    }
    alg_hold_top = rh_1171;
    Value ret_334 = alg_hold(alg_negate(alg_int(1)));
    alg_root_top = rt_base;
    return ret_334;
    alg_hold_top = rh_1171;
    Value ret_335 = alg_nil();
    alg_root_top = rt_base;
    return ret_335;
}

Value f_names(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_wanted = alg_param_of(args[0], "String", "Names");
    (void)v_wanted;
    alg_root(&v_wanted, 1);
    Value v_loop = alg_param_of(args[1], "String", "Names");
    (void)v_loop;
    alg_root(&v_loop, 1);
    int32_t rh_1175 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(v_wanted, alg_literal(""))))) {
        Value ret_336 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_336;
    }
    alg_hold_top = rh_1175;
    Value ret_337 = alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){v_wanted}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_loop}, 1))));
    alg_root_top = rt_base;
    return ret_337;
    alg_hold_top = rh_1175;
    Value ret_338 = alg_nil();
    alg_root_top = rt_base;
    return ret_338;
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
    int32_t rh_1176 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Value", v_value)));
    alg_hold_top = rh_1176;
    Value ret_339 = alg_nil();
    alg_root_top = rt_base;
    return ret_339;
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
    int32_t rh_1177 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Value", v_value)));
    alg_hold_top = rh_1177;
    Value ret_340 = alg_nil();
    alg_root_top = rt_base;
    return ret_340;
}

static Value *roots_Interpreter[] = {
    &v_programarguments,
    &fn_setprogramarguments,
    &v_outputsuppressed,
    &fn_suppressoutput,
    &fn_rendered,
    &fn_stringify,
    &v_interpVcollectVevery,
    &v_interpVtick,
    &v_typeVvalues,
    &v_interpVsiteVfile,
    &v_interpVsiteVline,
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
    alg_roots(roots_Interpreter, 21);
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
    alg_class_field(k_native, "Name", "String");
    alg_class_field(k_native, "TheArity", "Integer");
    alg_class_initializer(k_native, i_native);
    alg_class_method(k_native, "Init", m_native_init_2_string_integer, 2, t_native_init_2_string_integer);
    alg_class_method(k_native, "Arity", m_native_arity_0, 0, NULL);
    alg_class_method(k_native, "ToString", m_native_tostring_0, 0, NULL);
    alg_class_method(k_native, "Call", m_native_call_2, 2, t_native_call_2);
    fn_parsednumber = alg_closure("ParsedNumber", f_parsednumber, NULL, 0, 1, t_f_parsednumber);
    alg_class_field(k_interpreter, "Env", "Environment");
    alg_class_field(k_interpreter, "Builtins", "Environment");
    alg_class_field(k_interpreter, "Globals", "Environment");
    alg_class_field(k_interpreter, "Locals", "Map");
    alg_class_field(k_interpreter, "Modules", "Map");
    alg_class_field(k_interpreter, "HoistedClasses", "Set");
    alg_class_field(k_interpreter, "RootFile", "String");
    alg_class_field(k_interpreter, "UnitsByName", "Map");
    alg_class_field(k_interpreter, "MemberIsCallee", "Boolean");
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
    alg_class_method(k_interpreter, "ReceiverField", m_interpreter_receiverfield_1_token, 1, t_interpreter_receiverfield_1_token);
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
    alg_class_field(k_broke, "Label", "String");
    alg_class_initializer(k_broke, i_broke);
    alg_class_method(k_broke, "Init", m_broke_init_1_string, 1, t_broke_init_1_string);
    alg_class_field(k_continued, "Label", "String");
    alg_class_initializer(k_continued, i_continued);
    alg_class_method(k_continued, "Init", m_continued_init_1_string, 1, t_continued_init_1_string);
    alg_class_field(k_jumped, "Label", "String");
    alg_class_initializer(k_jumped, i_jumped);
    alg_class_method(k_jumped, "Init", m_jumped_init_1_string, 1, t_jumped_init_1_string);
    fn_labelat = alg_closure("LabelAt", f_labelat, NULL, 0, 2, t_f_labelat);
    fn_names = alg_closure("Names", f_names, NULL, 0, 2, t_f_names);
    alg_class_field(k_raised, "Value", "Any");
    alg_class_initializer(k_raised, i_raised);
    alg_class_method(k_raised, "Init", m_raised_init_1, 1, t_raised_init_1);
    alg_class_field(k_return, "Value", "Any");
    alg_class_initializer(k_return, i_return);
    alg_class_method(k_return, "Init", m_return_init_1, 1, t_return_init_1);
    int32_t rh_780 = alg_hold_top;
    init_Console();
    alg_hold_top = rh_780;
    init_TestReport();
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    init_ObjBuffer();
    alg_hold_top = rh_780;
    init_ObjClass();
    alg_hold_top = rh_780;
    init_ObjCollection();
    alg_hold_top = rh_780;
    init_ObjEnum();
    alg_hold_top = rh_780;
    init_ObjFile();
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    init_Parser();
    alg_hold_top = rh_780;
    init_Resolver();
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    v_programarguments = alg_hold(alg_list());
    d_programarguments = true;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    v_outputsuppressed = alg_bool(false);
    d_outputsuppressed = true;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    v_interpVcollectVevery = alg_int(200000);
    d_interpVcollectVevery = true;
    alg_hold_top = rh_780;
    v_interpVtick = alg_int(0);
    d_interpVtick = true;
    alg_hold_top = rh_780;
    v_typeVvalues = alg_hold(alg_map());
    d_typeVvalues = true;
    alg_hold_top = rh_780;
    v_interpVsiteVfile = alg_literal("");
    d_interpVsiteVfile = true;
    alg_hold_top = rh_780;
    v_interpVsiteVline = alg_int(0);
    d_interpVsiteVline = true;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
    alg_hold_top = rh_780;
}
