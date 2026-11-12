/* Generated from Algol-24.  Do not edit. */
#include "Resolver.h"
#include "Expr.h"
#include "Interpreter.h"
#include "Parser.h"
#include "Scanner.h"
#include "Stmt.h"
#include "Token.h"

Value e_functiontype;
Value e_functiontype_funVnone;
Value e_functiontype_funVfunction;
Value e_functiontype_funVmethod;
Value e_functiontype_funVinitializer;
Value e_classtype;
Value e_classtype_classVnone;
Value e_classtype_classVclass;
Value e_classtype_classVsubclass;
Value k_resolver;
static Value or_0;
static Value or_1;
static Value or_2;
static Value or_3;
static const char *t_resolver_init_1_interpreter[] = { "TheInterpreter : Interpreter" };
static const char *t_resolver_collectextensions_2_list_string[] = { "Statements : List", "Unit : String" };
static const char *t_resolver_ownextensions_3_map_modulestmt_string[] = { "Inner : Map", "Stmt : ModuleStmt", "Unit : String" };
static const char *t_resolver_adoptextensions_1_string[] = { "Unit : String" };
static const char *t_resolver_collectdottable_1_list[] = { "Statements : List" };
static const char *t_resolver_isunitqualifier_1[] = { "Obj : Any" };
static const char *t_resolver_visitblockstmt_1_blockstmt[] = { "Stmt : BlockStmt" };
static const char *t_resolver_visitclassstmt_1_classstmt[] = { "Stmt : ClassStmt" };
static const char *t_resolver_visitobjectstmt_1_objectstmt[] = { "Stmt : ObjectStmt" };
static const char *t_resolver_visitsubrangestmt_1_subrangestmt[] = { "Stmt : SubrangeStmt" };
static const char *t_resolver_visitenumstmt_1_enumstmt[] = { "Stmt : EnumStmt" };
static const char *t_resolver_visitexpressionstmt_1_expressionstmt[] = { "Stmt : ExpressionStmt" };
static const char *t_resolver_visitifstmt_1_ifstmt[] = { "Stmt : IfStmt" };
static const char *t_resolver_visittrystmt_1_trystmt[] = { "Stmt : TryStmt" };
static const char *t_resolver_visitmodulestmt_1_modulestmt[] = { "Stmt : ModuleStmt" };
static const char *t_resolver_visitforinstmt_1_forinstmt[] = { "Stmt : ForInStmt" };
static const char *t_resolver_visitbreakstmt_1_breakstmt[] = { "Stmt : BreakStmt" };
static const char *t_resolver_visitcontinuestmt_1_continuestmt[] = { "Stmt : ContinueStmt" };
static const char *t_resolver_visitlabelstmt_1_labelstmt[] = { "Stmt : LabelStmt" };
static const char *t_resolver_visitraisestmt_1_raisestmt[] = { "Stmt : RaiseStmt" };
static const char *t_resolver_visitreturnstmt_1_returnstmt[] = { "Stmt : ReturnStmt" };
static const char *t_resolver_visitwhilestmt_1_whilestmt[] = { "Stmt : WhileStmt" };
static const char *t_resolver_visitfunctionstmt_1_functionstmt[] = { "Stmt : FunctionStmt" };
static const char *t_resolver_visitvarstmt_1_varstmt[] = { "Stmt : VarStmt" };
static const char *t_resolver_visitvargroupstmt_1_vargroupstmt[] = { "Stmt : VarGroupStmt" };
static const char *t_resolver_visitassignexpr_1_assignexpr[] = { "TheExpr : AssignExpr" };
static const char *t_resolver_visitbinary_1_binaryexpr[] = { "TheExpr : BinaryExpr" };
static const char *t_resolver_visitlogical_1_logicalexpr[] = { "TheExpr : LogicalExpr" };
static const char *t_resolver_visitunary_1_unaryexpr[] = { "TheExpr : UnaryExpr" };
static const char *t_resolver_visitcall_1_callexpr[] = { "TheExpr : CallExpr" };
static const char *t_resolver_visitgetexpr_1_getexpr[] = { "TheExpr : GetExpr" };
static const char *t_resolver_visitsetexpr_1_setexpr[] = { "TheExpr : SetExpr" };
static const char *t_resolver_visitsuperexpr_1_superexpr[] = { "TheExpr : SuperExpr" };
static const char *t_resolver_visitthisexpr_1_thisexpr[] = { "TheExpr : ThisExpr" };
static const char *t_resolver_visitisexpr_1_isexpr[] = { "TheExpr : IsExpr" };
static const char *t_resolver_visitgrouping_1_groupingexpr[] = { "TheExpr : GroupingExpr" };
static const char *t_resolver_visitsubscriptexpr_1_subscriptexpr[] = { "TheExpr : SubscriptExpr" };
static const char *t_resolver_visitsetsubscriptexpr_1_setsubscriptexpr[] = { "TheExpr : SetSubscriptExpr" };
static const char *t_resolver_visitcollectionexpr_1_collectionexpr[] = { "TheExpr : CollectionExpr" };
static const char *t_resolver_visitliteral_1_literalexpr[] = { "TheExpr : LiteralExpr" };
static const char *t_resolver_visitvariableexpr_1_variableexpr[] = { "TheExpr : VariableExpr" };
static const char *t_resolver_checkduplicates_1_list[] = { "Statements : List" };
static const char *t_resolver_signatureof_1[] = { "TheStmt : Any" };
static const char *t_resolver_checkmethodduplicates_1_list[] = { "Methods : List" };
static const char *t_resolver_checkinheritance_1_list[] = { "Statements : List" };
static const char *t_resolver_resolveall_1_list[] = { "Statements : List" };
static const char *t_resolver_pushlabels_1_list[] = { "Statements : List" };
static const char *t_resolver_findlabel_1_string[] = { "Named : String" };
static const char *t_resolver_visitgotostmt_1_gotostmt[] = { "Stmt : GotoStmt" };
static const char *t_resolver_resolve_1[] = { "TheExpr : Any" };
static const char *t_resolver_resolvefunction_2_functionstmt_functiontype[] = { "TheFunction : FunctionStmt", "TypeOfFunction : FunctionType" };
static const char *t_resolver_declare_1_token[] = { "Name : Token" };
static const char *t_resolver_declarebinding_2_token_boolean[] = { "Name : Token", "IsConstant : Boolean" };
static const char *t_resolver_isconstant_1_token[] = { "Name : Token" };
static const char *t_resolver_define_1_token[] = { "Name : Token" };
static const char *t_resolver_resolvelocal_2_expr_token[] = { "TheExpr : Expr", "Name : Token" };

static Value i_resolver(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "TheInterpreter", alg_nil());
    alg_set_property(v_this, "Scopes", alg_nil());
    alg_set_property(v_this, "Constants", alg_nil());
    alg_set_property(v_this, "GlobalConstants", alg_nil());
    alg_set_property(v_this, "CurrentFunction", alg_nil());
    alg_set_property(v_this, "CurrentClass", alg_nil());
    alg_set_property(v_this, "Units", alg_nil());
    alg_set_property(v_this, "Dottable", alg_nil());
    alg_set_property(v_this, "Extensions", alg_nil());
    alg_set_property(v_this, "Exported", alg_nil());
    alg_set_property(v_this, "Collected", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "LabelScopes", alg_widen(alg_hold(alg_list()), "List"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_resolver_init_1_interpreter(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theinterpreter = alg_widen(args[0], "Interpreter");
    (void)v_theinterpreter;
    alg_root(&v_theinterpreter, 1);
    int32_t rh_587 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "TheInterpreter", v_theinterpreter)));
    alg_hold_top = rh_587;
    (void)(alg_hold(alg_set_property(v_this, "Scopes", alg_hold(alg_stack()))));
    alg_hold_top = rh_587;
    (void)(alg_hold(alg_set_property(v_this, "Constants", alg_hold(alg_stack()))));
    alg_hold_top = rh_587;
    (void)(alg_hold(alg_set_property(v_this, "GlobalConstants", alg_hold(alg_map()))));
    alg_hold_top = rh_587;
    (void)(alg_hold(alg_set_property(v_this, "CurrentFunction", e_functiontype_funVnone)));
    alg_hold_top = rh_587;
    (void)(alg_hold(alg_set_property(v_this, "CurrentClass", e_classtype_classVnone)));
    alg_hold_top = rh_587;
    (void)(alg_hold(alg_set_property(v_this, "Units", alg_hold(alg_set()))));
    alg_hold_top = rh_587;
    (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_this, "Units")), "Add", (Value[]){alg_literal("system")}, 1)));
    alg_hold_top = rh_587;
    (void)(alg_hold(alg_set_property(v_this, "Dottable", alg_hold(alg_set()))));
    alg_hold_top = rh_587;
    (void)(alg_hold(alg_set_property(v_this, "Extensions", alg_hold(alg_map()))));
    alg_hold_top = rh_587;
    (void)(alg_hold(alg_set_property(v_this, "Exported", alg_hold(alg_map()))));
    alg_hold_top = rh_587;
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

static Value m_resolver_collectextensions_2_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    Value v_unit = alg_widen(args[1], "String");
    (void)v_unit;
    alg_root(&v_unit, 1);
    int32_t rh_588 = alg_hold_top;
    {
        int32_t rt_589 = alg_root_top;
        Value loop_1 = alg_iterable(v_statements);
        (void)loop_1;
        alg_root(&loop_1, 1);
        for (int32_t at_1 = 0; at_1 < alg_iterable_count(loop_1); at_1++) {
            alg_safe_point();
            int32_t rt_590 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_1, at_1);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rh_591 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_not((alg_is_class(v_thestmt, k_functionstmt)))))) {
                    continue;
                }
                alg_hold_top = rh_591;
                if (alg_truthy(alg_hold(alg_property(v_thestmt, "IsExtension")))) {
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Extensions"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1)), v_unit}, 2)));
                }
                alg_hold_top = rh_591;
            }
            alg_root_top = rt_590;
        }
        alg_root_top = rt_589;
    }
    alg_hold_top = rh_588;
    Value ret_2 = alg_nil();
    alg_root_top = rt_base;
    return ret_2;
}

static Value m_resolver_ownextensions_3_map_modulestmt_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_inner = alg_widen(args[0], "Map");
    (void)v_inner;
    alg_root(&v_inner, 1);
    Value v_stmt = alg_widen(args[1], "ModuleStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    Value v_unit = alg_widen(args[2], "String");
    (void)v_unit;
    alg_root(&v_unit, 1);
    int32_t rh_592 = alg_hold_top;
    Value v_hidden = alg_nil();
    (void)v_hidden;
    alg_root(&v_hidden, 1);
    alg_hold_top = rh_592;
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_592;
    (void)((v_hidden = alg_hold(alg_set())));
    alg_hold_top = rh_592;
    {
        int32_t rt_593 = alg_root_top;
        Value loop_3 = alg_iterable(alg_hold(alg_property(v_stmt, "PrivateNames")));
        (void)loop_3;
        alg_root(&loop_3, 1);
        for (int32_t at_3 = 0; at_3 < alg_iterable_count(loop_3); at_3++) {
            alg_safe_point();
            int32_t rt_594 = alg_root_top;
            Value v_thename = alg_iterable_at(loop_3, at_3);
            (void)v_thename;
            alg_root(&v_thename, 1);
            (void)(alg_hold(alg_invoke(v_hidden, "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_thename}, 1))}, 1)));
            alg_root_top = rt_594;
        }
        alg_root_top = rt_593;
    }
    alg_hold_top = rh_592;
    (void)((v_result = alg_hold(alg_map())));
    alg_hold_top = rh_592;
    {
        int32_t rt_595 = alg_root_top;
        Value loop_4 = alg_iterable(alg_hold(alg_invoke(v_inner, "Keys", NULL, 0)));
        (void)loop_4;
        alg_root(&loop_4, 1);
        for (int32_t at_4 = 0; at_4 < alg_iterable_count(loop_4); at_4++) {
            alg_safe_point();
            int32_t rt_596 = alg_root_top;
            Value v_key = alg_iterable_at(loop_4, at_4);
            (void)v_key;
            alg_root(&v_key, 1);
            {
                int32_t rh_597 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_str(alg_hold(alg_invoke(v_inner, "Get", (Value[]){v_key}, 1)))), alg_literal(""))))) {
                    continue;
                }
                alg_hold_top = rh_597;
                if (alg_truthy(alg_hold(alg_invoke(v_hidden, "Contains", (Value[]){v_key}, 1)))) {
                    continue;
                }
                alg_hold_top = rh_597;
                (void)(alg_hold(alg_invoke(v_result, "Put", (Value[]){v_key, v_unit}, 2)));
                alg_hold_top = rh_597;
            }
            alg_root_top = rt_596;
        }
        alg_root_top = rt_595;
    }
    alg_hold_top = rh_592;
    Value ret_5 = v_result;
    alg_root_top = rt_base;
    return ret_5;
    alg_hold_top = rh_592;
    Value ret_6 = alg_nil();
    alg_root_top = rt_base;
    return ret_6;
}

static Value m_resolver_adoptextensions_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_unit = alg_widen(args[0], "String");
    (void)v_unit;
    alg_root(&v_unit, 1);
    int32_t rh_598 = alg_hold_top;
    Value v_theirs = alg_nil();
    (void)v_theirs;
    alg_root(&v_theirs, 1);
    alg_hold_top = rh_598;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Exported"), "Contains", (Value[]){v_unit}, 1)))))) {
        Value ret_7 = alg_nil();
        alg_root_top = rt_base;
        return ret_7;
    }
    alg_hold_top = rh_598;
    (void)((v_theirs = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "Exported"), "Get", (Value[]){v_unit}, 1), ALG_KIND_MAP, "Map"))));
    alg_hold_top = rh_598;
    {
        int32_t rt_599 = alg_root_top;
        Value loop_8 = alg_iterable(alg_hold(alg_invoke(v_theirs, "Keys", NULL, 0)));
        (void)loop_8;
        alg_root(&loop_8, 1);
        for (int32_t at_8 = 0; at_8 < alg_iterable_count(loop_8); at_8++) {
            alg_safe_point();
            int32_t rt_600 = alg_root_top;
            Value v_key = alg_iterable_at(loop_8, at_8);
            (void)v_key;
            alg_root(&v_key, 1);
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Extensions"), "Put", (Value[]){v_key, alg_hold(alg_str(alg_hold(alg_invoke(v_theirs, "Get", (Value[]){v_key}, 1))))}, 2)));
            alg_root_top = rt_600;
        }
        alg_root_top = rt_599;
    }
    alg_hold_top = rh_598;
    Value ret_9 = alg_nil();
    alg_root_top = rt_base;
    return ret_9;
}

static Value m_resolver_collectdottable_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_601 = alg_hold_top;
    {
        int32_t rt_602 = alg_root_top;
        Value loop_10 = alg_iterable(v_statements);
        (void)loop_10;
        alg_root(&loop_10, 1);
        for (int32_t at_10 = 0; at_10 < alg_iterable_count(loop_10); at_10++) {
            alg_safe_point();
            int32_t rt_603 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_10, at_10);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rh_604 = alg_hold_top;
                if (alg_truthy(alg_is_class(v_thestmt, k_objectstmt))) {
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))}, 1)));
                }
                alg_hold_top = rh_604;
                if (alg_truthy(alg_is_class(v_thestmt, k_enumstmt))) {
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))}, 1)));
                }
                alg_hold_top = rh_604;
                if (alg_truthy(alg_is_class(v_thestmt, k_varstmt))) {
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))}, 1)));
                }
                alg_hold_top = rh_604;
                if (alg_truthy(alg_is_class(v_thestmt, k_vargroupstmt))) {
                    {
                        int32_t rt_605 = alg_root_top;
                        Value loop_11 = alg_iterable(alg_hold(alg_property(v_thestmt, "Names")));
                        (void)loop_11;
                        alg_root(&loop_11, 1);
                        for (int32_t at_11 = 0; at_11 < alg_iterable_count(loop_11); at_11++) {
                            alg_safe_point();
                            int32_t rt_606 = alg_root_top;
                            Value v_thename = alg_iterable_at(loop_11, at_11);
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            (void)(alg_hold(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_thename, "Lexeme"))}, 1))}, 1)));
                            alg_root_top = rt_606;
                        }
                        alg_root_top = rt_605;
                    }
                }
                alg_hold_top = rh_604;
                if (alg_truthy(alg_hold((or_0 = alg_is_class(v_thestmt, k_modulestmt), !alg_truthy(or_0) ? or_0 : alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Statements")), alg_nil())))))) {
                    (void)(alg_hold(alg_invoke(v_this, "CollectDottable", (Value[]){alg_hold(alg_property(v_thestmt, "Statements"))}, 1)));
                }
                alg_hold_top = rh_604;
            }
            alg_root_top = rt_603;
        }
        alg_root_top = rt_602;
    }
    alg_hold_top = rh_601;
    Value ret_12 = alg_nil();
    alg_root_top = rt_base;
    return ret_12;
}

static Value m_resolver_isunitqualifier_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    int32_t rh_607 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not((alg_is_class(v_obj, k_variableexpr)))))) {
        Value ret_13 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_13;
    }
    alg_hold_top = rh_607;
    Value v_name = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_obj, "Name")), "Lexeme"))));
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_607;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Units"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))))) {
        Value ret_14 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_14;
    }
    alg_hold_top = rh_607;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Dottable"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))) {
        Value ret_15 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_15;
    }
    alg_hold_top = rh_607;
    {
        int32_t rt_608 = alg_root_top;
        int32_t rh_609 = alg_hold_top;
        Value v_i = alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "Scopes"), "Length")), alg_int(1)));
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_609;
        {
            int32_t rh_610 = alg_hold_top;
            for (; (alg_hold_top = rh_610, alg_truthy(alg_hold(alg_greater_equal(v_i, alg_int(0))))); (alg_hold_top = rh_610, (v_i = alg_hold(alg_subtract(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold(alg_invoke(alg_hold(alg_subscript_get(alg_property(v_this, "Scopes"), v_i)), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))) {
                    Value ret_16 = alg_bool(false);
                    alg_root_top = rt_base;
                    return ret_16;
                }
            }
        }
        alg_hold_top = rh_609;
        alg_root_top = rt_608;
    }
    alg_hold_top = rh_607;
    Value ret_17 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_17;
    alg_hold_top = rh_607;
    Value ret_18 = alg_nil();
    alg_root_top = rt_base;
    return ret_18;
}

static Value m_resolver_visitblockstmt_1_blockstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "BlockStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_611 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "BeginScope", NULL, 0)));
    alg_hold_top = rh_611;
    (void)(alg_hold(alg_invoke(v_this, "ResolveAll", (Value[]){alg_hold(alg_property(v_stmt, "Statements"))}, 1)));
    alg_hold_top = rh_611;
    (void)(alg_hold(alg_invoke(v_this, "EndScope", NULL, 0)));
    alg_hold_top = rh_611;
    Value ret_19 = alg_nil();
    alg_root_top = rt_base;
    return ret_19;
}

static Value m_resolver_visitclassstmt_1_classstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "ClassStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_612 = alg_hold_top;
    Value v_enclosingclass = alg_nil();
    (void)v_enclosingclass;
    alg_root(&v_enclosingclass, 1);
    alg_hold_top = rh_612;
    (void)((v_enclosingclass = alg_property(v_this, "CurrentClass")));
    alg_hold_top = rh_612;
    (void)(alg_set_property(v_this, "CurrentClass", e_classtype_classVclass));
    alg_hold_top = rh_612;
    (void)(alg_hold(alg_invoke(v_this, "Declare", (Value[]){alg_hold(alg_property(v_stmt, "Name"))}, 1)));
    alg_hold_top = rh_612;
    (void)(alg_hold(alg_invoke(v_this, "Define", (Value[]){alg_hold(alg_property(v_stmt, "Name"))}, 1)));
    alg_hold_top = rh_612;
    if (alg_truthy(alg_hold((or_1 = alg_hold(alg_not_equal(alg_hold(alg_property(v_stmt, "Superclass")), alg_nil())), !alg_truthy(or_1) ? or_1 : alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_stmt, "Name")), "Lexeme")), alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_stmt, "Superclass")), "Name")), "Lexeme")))))))) {
        {
            int32_t rh_613 = alg_hold_top;
            alg_raise(alg_literal("A class can't inherit from itself."));
            alg_hold_top = rh_613;
        }
    }
    alg_hold_top = rh_612;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_stmt, "Superclass")), alg_nil())))) {
        {
            int32_t rh_614 = alg_hold_top;
            (void)(alg_set_property(v_this, "CurrentClass", e_classtype_classVsubclass));
            alg_hold_top = rh_614;
            (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "Superclass"))}, 1)));
            alg_hold_top = rh_614;
        }
    }
    alg_hold_top = rh_612;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_stmt, "Superclass")), alg_nil())))) {
        {
            int32_t rh_615 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "BeginScope", NULL, 0)));
            alg_hold_top = rh_615;
            (void)(alg_hold(alg_invoke(alg_hold(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0)), "Put", (Value[]){alg_literal("super"), alg_bool(true)}, 2)));
            alg_hold_top = rh_615;
        }
    }
    alg_hold_top = rh_612;
    (void)(alg_hold(alg_invoke(v_this, "BeginScope", NULL, 0)));
    alg_hold_top = rh_612;
    (void)(alg_hold(alg_invoke(alg_hold(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0)), "Put", (Value[]){alg_literal("this"), alg_bool(true)}, 2)));
    alg_hold_top = rh_612;
    {
        int32_t rt_616 = alg_root_top;
        Value loop_20 = alg_iterable(alg_hold(alg_property(v_stmt, "Methods")));
        (void)loop_20;
        alg_root(&loop_20, 1);
        for (int32_t at_20 = 0; at_20 < alg_iterable_count(loop_20); at_20++) {
            alg_safe_point();
            int32_t rt_617 = alg_root_top;
            Value v_method = alg_iterable_at(loop_20, at_20);
            (void)v_method;
            alg_root(&v_method, 1);
            {
                int32_t rt_618 = alg_root_top;
                int32_t rh_619 = alg_hold_top;
                Value v_declaration = e_functiontype_funVfunction;
                (void)v_declaration;
                alg_root(&v_declaration, 1);
                alg_hold_top = rh_619;
                if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_method, "Name")), "Lexeme"))}, 1)), alg_literal("init"))))) {
                    {
                        int32_t rh_620 = alg_hold_top;
                        (void)((v_declaration = e_functiontype_funVinitializer));
                        alg_hold_top = rh_620;
                    }
                }
                alg_hold_top = rh_619;
                (void)(alg_hold(alg_invoke(v_this, "ResolveFunction", (Value[]){v_method, v_declaration}, 2)));
                alg_hold_top = rh_619;
                alg_root_top = rt_618;
            }
            alg_root_top = rt_617;
        }
        alg_root_top = rt_616;
    }
    alg_hold_top = rh_612;
    (void)(alg_hold(alg_invoke(v_this, "EndScope", NULL, 0)));
    alg_hold_top = rh_612;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_stmt, "Superclass")), alg_nil())))) {
        (void)(alg_hold(alg_invoke(v_this, "EndScope", NULL, 0)));
    }
    alg_hold_top = rh_612;
    (void)(alg_set_property(v_this, "CurrentClass", v_enclosingclass));
    alg_hold_top = rh_612;
    Value ret_21 = alg_nil();
    alg_root_top = rt_base;
    return ret_21;
}

static Value m_resolver_visitobjectstmt_1_objectstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "ObjectStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_621 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "VisitClassStmt", (Value[]){alg_hold(alg_new(k_classstmt, (Value[]){alg_hold(alg_property(v_stmt, "Name")), alg_hold(alg_property(v_stmt, "Superclass")), alg_hold(alg_property(v_stmt, "Methods")), alg_hold(alg_property(v_stmt, "Fields"))}, 4))}, 1)));
    alg_hold_top = rh_621;
    Value ret_22 = alg_nil();
    alg_root_top = rt_base;
    return ret_22;
}

static Value m_resolver_visitsubrangestmt_1_subrangestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "SubrangeStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_622 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Declare", (Value[]){alg_hold(alg_property(v_stmt, "Name"))}, 1)));
    alg_hold_top = rh_622;
    (void)(alg_hold(alg_invoke(v_this, "Define", (Value[]){alg_hold(alg_property(v_stmt, "Name"))}, 1)));
    alg_hold_top = rh_622;
    (void)(alg_hold(f_definesubrange(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_stmt, "Name")), "Lexeme")), alg_hold(alg_property(v_stmt, "Low")), alg_hold(alg_property(v_stmt, "High"))}, 3)));
    alg_hold_top = rh_622;
    Value ret_23 = alg_nil();
    alg_root_top = rt_base;
    return ret_23;
}

static Value m_resolver_visitenumstmt_1_enumstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "EnumStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_623 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Declare", (Value[]){alg_hold(alg_property(v_stmt, "Name"))}, 1)));
    alg_hold_top = rh_623;
    (void)(alg_hold(alg_invoke(v_this, "Define", (Value[]){alg_hold(alg_property(v_stmt, "Name"))}, 1)));
    alg_hold_top = rh_623;
    {
        int32_t rt_624 = alg_root_top;
        Value loop_24 = alg_iterable(alg_hold(alg_property(v_stmt, "Members")));
        (void)loop_24;
        alg_root(&loop_24, 1);
        for (int32_t at_24 = 0; at_24 < alg_iterable_count(loop_24); at_24++) {
            alg_safe_point();
            int32_t rt_625 = alg_root_top;
            Value v_member = alg_iterable_at(loop_24, at_24);
            (void)v_member;
            alg_root(&v_member, 1);
            {
                int32_t rh_626 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_this, "Declare", (Value[]){v_member}, 1)));
                alg_hold_top = rh_626;
                (void)(alg_hold(alg_invoke(v_this, "Define", (Value[]){v_member}, 1)));
                alg_hold_top = rh_626;
            }
            alg_root_top = rt_625;
        }
        alg_root_top = rt_624;
    }
    alg_hold_top = rh_623;
    Value ret_25 = alg_nil();
    alg_root_top = rt_base;
    return ret_25;
}

static Value m_resolver_visitexpressionstmt_1_expressionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "ExpressionStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_627 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "Expression"))}, 1)));
    alg_hold_top = rh_627;
    Value ret_26 = alg_nil();
    alg_root_top = rt_base;
    return ret_26;
}

static Value m_resolver_visitifstmt_1_ifstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "IfStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_628 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "Condition"))}, 1)));
    alg_hold_top = rh_628;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "ThenBranch"))}, 1)));
    alg_hold_top = rh_628;
    if (alg_truthy((alg_hold(alg_not_equal(alg_hold(alg_property(v_stmt, "ElseBranch")), alg_nil()))))) {
        (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "ElseBranch"))}, 1)));
    }
    alg_hold_top = rh_628;
    Value ret_27 = alg_nil();
    alg_root_top = rt_base;
    return ret_27;
}

static Value m_resolver_visittrystmt_1_trystmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "TryStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_629 = alg_hold_top;
    Value v_keys = alg_nil();
    (void)v_keys;
    alg_root(&v_keys, 1);
    alg_hold_top = rh_629;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "TryBlock"))}, 1)));
    alg_hold_top = rh_629;
    (void)((v_keys = alg_hold(alg_invoke(alg_hold(alg_property(v_stmt, "Handlers")), "Keys", NULL, 0))));
    alg_hold_top = rh_629;
    {
        int32_t rt_630 = alg_root_top;
        Value loop_28 = alg_iterable(v_keys);
        (void)loop_28;
        alg_root(&loop_28, 1);
        for (int32_t at_28 = 0; at_28 < alg_iterable_count(loop_28); at_28++) {
            alg_safe_point();
            int32_t rt_631 = alg_root_top;
            Value v_key = alg_iterable_at(loop_28, at_28);
            (void)v_key;
            alg_root(&v_key, 1);
            (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(alg_hold(alg_invoke(alg_hold(alg_property(v_stmt, "Handlers")), "Get", (Value[]){v_key}, 1)), "Body"))}, 1)));
            alg_root_top = rt_631;
        }
        alg_root_top = rt_630;
    }
    alg_hold_top = rh_629;
    Value ret_29 = alg_nil();
    alg_root_top = rt_base;
    return ret_29;
}

static Value m_resolver_visitmodulestmt_1_modulestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "ModuleStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_632 = alg_hold_top;
    Value v_enclosing = alg_nil();
    (void)v_enclosing;
    alg_root(&v_enclosing, 1);
    alg_hold_top = rh_632;
    Value v_outer = alg_nil();
    (void)v_outer;
    alg_root(&v_outer, 1);
    alg_hold_top = rh_632;
    Value v_inner = alg_nil();
    (void)v_inner;
    alg_root(&v_inner, 1);
    alg_hold_top = rh_632;
    Value v_unit = alg_nil();
    (void)v_unit;
    alg_root(&v_unit, 1);
    alg_hold_top = rh_632;
    (void)((v_unit = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_stmt, "UnitName"))}, 1))));
    alg_hold_top = rh_632;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_stmt, "Statements")), alg_nil())))) {
        {
            int32_t rh_633 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){v_unit}, 1)));
            alg_hold_top = rh_633;
            (void)(alg_hold(alg_invoke(v_this, "AdoptExtensions", (Value[]){v_unit}, 1)));
            alg_hold_top = rh_633;
            Value ret_30 = alg_nil();
            alg_root_top = rt_base;
            return ret_30;
            alg_hold_top = rh_633;
        }
    }
    alg_hold_top = rh_632;
    (void)((v_enclosing = alg_property(v_this, "Units")));
    alg_hold_top = rh_632;
    (void)(alg_set_property(v_this, "Units", alg_hold(alg_set())));
    alg_hold_top = rh_632;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){alg_literal("system")}, 1)));
    alg_hold_top = rh_632;
    (void)((v_outer = alg_property(v_this, "Extensions")));
    alg_hold_top = rh_632;
    (void)(alg_set_property(v_this, "Extensions", alg_hold(alg_map())));
    alg_hold_top = rh_632;
    (void)(alg_hold(alg_invoke(v_this, "CollectExtensions", (Value[]){alg_hold(alg_property(v_stmt, "Statements")), alg_literal("")}, 2)));
    alg_hold_top = rh_632;
    (void)(alg_hold(alg_invoke(v_this, "ResolveAll", (Value[]){alg_hold(alg_property(v_stmt, "Statements"))}, 1)));
    alg_hold_top = rh_632;
    (void)((v_inner = alg_property(v_this, "Extensions")));
    alg_hold_top = rh_632;
    (void)(alg_set_property(v_this, "Units", v_enclosing));
    alg_hold_top = rh_632;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){v_unit}, 1)));
    alg_hold_top = rh_632;
    (void)(alg_set_property(v_this, "Extensions", v_outer));
    alg_hold_top = rh_632;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Exported"), "Put", (Value[]){v_unit, alg_hold(alg_invoke(v_this, "OwnExtensions", (Value[]){v_inner, v_stmt, v_unit}, 3))}, 2)));
    alg_hold_top = rh_632;
    (void)(alg_hold(alg_invoke(v_this, "AdoptExtensions", (Value[]){v_unit}, 1)));
    alg_hold_top = rh_632;
    Value ret_31 = alg_nil();
    alg_root_top = rt_base;
    return ret_31;
}

static Value m_resolver_visitforinstmt_1_forinstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "ForInStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_634 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "Iterable"))}, 1)));
    alg_hold_top = rh_634;
    (void)(alg_hold(alg_invoke(v_this, "BeginScope", NULL, 0)));
    alg_hold_top = rh_634;
    (void)(alg_hold(alg_invoke(v_this, "Declare", (Value[]){alg_hold(alg_property(v_stmt, "Name"))}, 1)));
    alg_hold_top = rh_634;
    (void)(alg_hold(alg_invoke(v_this, "Define", (Value[]){alg_hold(alg_property(v_stmt, "Name"))}, 1)));
    alg_hold_top = rh_634;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "Body"))}, 1)));
    alg_hold_top = rh_634;
    (void)(alg_hold(alg_invoke(v_this, "EndScope", NULL, 0)));
    alg_hold_top = rh_634;
    Value ret_32 = alg_nil();
    alg_root_top = rt_base;
    return ret_32;
}

static Value m_resolver_visitbreakstmt_1_breakstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "BreakStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_635 = alg_hold_top;
    Value ret_33 = alg_nil();
    alg_root_top = rt_base;
    return ret_33;
}

static Value m_resolver_visitcontinuestmt_1_continuestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "ContinueStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_636 = alg_hold_top;
    Value ret_34 = alg_nil();
    alg_root_top = rt_base;
    return ret_34;
}

static Value m_resolver_visitlabelstmt_1_labelstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "LabelStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_637 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "Inner"))}, 1)));
    alg_hold_top = rh_637;
    Value ret_35 = alg_nil();
    alg_root_top = rt_base;
    return ret_35;
}

static Value m_resolver_visitraisestmt_1_raisestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "RaiseStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_638 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "Value"))}, 1)));
    alg_hold_top = rh_638;
    Value ret_36 = alg_nil();
    alg_root_top = rt_base;
    return ret_36;
}

static Value m_resolver_visitreturnstmt_1_returnstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "ReturnStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_639 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "CurrentFunction"), e_functiontype_funVnone)))) {
        {
            int32_t rh_640 = alg_hold_top;
            alg_raise(alg_literal("Can't return from top-level code."));
            alg_hold_top = rh_640;
        }
    }
    alg_hold_top = rh_639;
    if (alg_truthy((alg_hold(alg_not_equal(alg_hold(alg_property(v_stmt, "Value")), alg_nil()))))) {
        {
            int32_t rh_641 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "CurrentFunction"), e_functiontype_funVinitializer)))) {
                {
                    int32_t rh_642 = alg_hold_top;
                    alg_raise(alg_literal("Can't return a value from an initializer."));
                    alg_hold_top = rh_642;
                }
            }
            alg_hold_top = rh_641;
            (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "Value"))}, 1)));
            alg_hold_top = rh_641;
        }
    }
    alg_hold_top = rh_639;
    Value ret_37 = alg_nil();
    alg_root_top = rt_base;
    return ret_37;
}

static Value m_resolver_visitwhilestmt_1_whilestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "WhileStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_643 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "Condition"))}, 1)));
    alg_hold_top = rh_643;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "Body"))}, 1)));
    alg_hold_top = rh_643;
    Value ret_38 = alg_nil();
    alg_root_top = rt_base;
    return ret_38;
}

static Value m_resolver_visitfunctionstmt_1_functionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "FunctionStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_644 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Declare", (Value[]){alg_hold(alg_property(v_stmt, "Name"))}, 1)));
    alg_hold_top = rh_644;
    (void)(alg_hold(alg_invoke(v_this, "Define", (Value[]){alg_hold(alg_property(v_stmt, "Name"))}, 1)));
    alg_hold_top = rh_644;
    (void)(alg_hold(alg_invoke(v_this, "ResolveFunction", (Value[]){v_stmt, e_functiontype_funVfunction}, 2)));
    alg_hold_top = rh_644;
    Value ret_39 = alg_nil();
    alg_root_top = rt_base;
    return ret_39;
}

static Value m_resolver_visitvarstmt_1_varstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "VarStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_645 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "DeclareBinding", (Value[]){alg_hold(alg_property(v_stmt, "Name")), alg_hold(alg_property(v_stmt, "IsConstant"))}, 2)));
    alg_hold_top = rh_645;
    if (alg_truthy((alg_hold(alg_not_equal(alg_hold(alg_property(v_stmt, "Initializer")), alg_nil()))))) {
        {
            int32_t rh_646 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "Initializer"))}, 1)));
            alg_hold_top = rh_646;
        }
    }
    alg_hold_top = rh_645;
    (void)(alg_hold(alg_invoke(v_this, "Define", (Value[]){alg_hold(alg_property(v_stmt, "Name"))}, 1)));
    alg_hold_top = rh_645;
    Value ret_40 = alg_nil();
    alg_root_top = rt_base;
    return ret_40;
}

static Value m_resolver_visitvargroupstmt_1_vargroupstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "VarGroupStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_647 = alg_hold_top;
    {
        int32_t rt_648 = alg_root_top;
        Value loop_41 = alg_iterable(alg_hold(alg_property(v_stmt, "Names")));
        (void)loop_41;
        alg_root(&loop_41, 1);
        for (int32_t at_41 = 0; at_41 < alg_iterable_count(loop_41); at_41++) {
            alg_safe_point();
            int32_t rt_649 = alg_root_top;
            Value v_name = alg_iterable_at(loop_41, at_41);
            (void)v_name;
            alg_root(&v_name, 1);
            (void)(alg_hold(alg_invoke(v_this, "DeclareBinding", (Value[]){v_name, alg_hold(alg_property(v_stmt, "IsConstant"))}, 2)));
            alg_root_top = rt_649;
        }
        alg_root_top = rt_648;
    }
    alg_hold_top = rh_647;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_stmt, "Initializer")), alg_nil())))) {
        (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_stmt, "Initializer"))}, 1)));
    }
    alg_hold_top = rh_647;
    {
        int32_t rt_650 = alg_root_top;
        Value loop_42 = alg_iterable(alg_hold(alg_property(v_stmt, "Names")));
        (void)loop_42;
        alg_root(&loop_42, 1);
        for (int32_t at_42 = 0; at_42 < alg_iterable_count(loop_42); at_42++) {
            alg_safe_point();
            int32_t rt_651 = alg_root_top;
            Value v_thename = alg_iterable_at(loop_42, at_42);
            (void)v_thename;
            alg_root(&v_thename, 1);
            (void)(alg_hold(alg_invoke(v_this, "Define", (Value[]){v_thename}, 1)));
            alg_root_top = rt_651;
        }
        alg_root_top = rt_650;
    }
    alg_hold_top = rh_647;
    Value ret_43 = alg_nil();
    alg_root_top = rt_base;
    return ret_43;
}

static Value m_resolver_visitassignexpr_1_assignexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "AssignExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_652 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsConstant", (Value[]){alg_hold(alg_property(v_theexpr, "Name"))}, 1)))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Can't assign to constant '"), alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme")))), alg_literal("'."))));
    }
    alg_hold_top = rh_652;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1)));
    alg_hold_top = rh_652;
    (void)(alg_hold(alg_invoke(v_this, "ResolveLocal", (Value[]){v_theexpr, alg_hold(alg_property(v_theexpr, "Name"))}, 2)));
    alg_hold_top = rh_652;
    Value ret_44 = alg_nil();
    alg_root_top = rt_base;
    return ret_44;
}

static Value m_resolver_visitbinary_1_binaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "BinaryExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_653 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Left"))}, 1)));
    alg_hold_top = rh_653;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1)));
    alg_hold_top = rh_653;
    Value ret_45 = alg_nil();
    alg_root_top = rt_base;
    return ret_45;
}

static Value m_resolver_visitlogical_1_logicalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "LogicalExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_654 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Left"))}, 1)));
    alg_hold_top = rh_654;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1)));
    alg_hold_top = rh_654;
    Value ret_46 = alg_nil();
    alg_root_top = rt_base;
    return ret_46;
}

static Value m_resolver_visitunary_1_unaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "UnaryExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_655 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1)));
    alg_hold_top = rh_655;
    Value ret_47 = alg_nil();
    alg_root_top = rt_base;
    return ret_47;
}

static Value m_resolver_visitcall_1_callexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CallExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_656 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Callee"))}, 1)));
    alg_hold_top = rh_656;
    {
        int32_t rt_657 = alg_root_top;
        Value loop_48 = alg_iterable(alg_hold(alg_property(v_theexpr, "Arguments")));
        (void)loop_48;
        alg_root(&loop_48, 1);
        for (int32_t at_48 = 0; at_48 < alg_iterable_count(loop_48); at_48++) {
            alg_safe_point();
            int32_t rt_658 = alg_root_top;
            Value v_argument = alg_iterable_at(loop_48, at_48);
            (void)v_argument;
            alg_root(&v_argument, 1);
            {
                int32_t rh_659 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){v_argument}, 1)));
                alg_hold_top = rh_659;
            }
            alg_root_top = rt_658;
        }
        alg_root_top = rt_657;
    }
    alg_hold_top = rh_656;
    Value ret_49 = alg_nil();
    alg_root_top = rt_base;
    return ret_49;
}

static Value m_resolver_visitgetexpr_1_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_660 = alg_hold_top;
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    alg_hold_top = rh_660;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsUnitQualifier", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)))) {
        {
            int32_t rh_661 = alg_hold_top;
            (void)(alg_hold(alg_set_property(v_theexpr, "Unit", alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Obj")), "Name")), "Lexeme")))))));
            alg_hold_top = rh_661;
            Value ret_50 = alg_nil();
            alg_root_top = rt_base;
            return ret_50;
            alg_hold_top = rh_661;
        }
    }
    alg_hold_top = rh_660;
    (void)((v_folded = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))}, 1))));
    alg_hold_top = rh_660;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Extensions"), "Contains", (Value[]){v_folded}, 1)))) {
        {
            int32_t rh_662 = alg_hold_top;
            (void)(alg_hold(alg_set_property(v_theexpr, "Extension", alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme")))))));
            alg_hold_top = rh_662;
            (void)(alg_hold(alg_set_property(v_theexpr, "ExtensionUnit", alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "Extensions"), "Get", (Value[]){v_folded}, 1)))))));
            alg_hold_top = rh_662;
        }
    }
    alg_hold_top = rh_660;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)));
    alg_hold_top = rh_660;
    Value ret_51 = alg_nil();
    alg_root_top = rt_base;
    return ret_51;
}

static Value m_resolver_visitsetexpr_1_setexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_663 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsUnitQualifier", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)))) {
        {
            int32_t rh_664 = alg_hold_top;
            (void)(alg_hold(alg_set_property(v_theexpr, "Unit", alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Obj")), "Name")), "Lexeme")))))));
            alg_hold_top = rh_664;
            (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1)));
            alg_hold_top = rh_664;
            Value ret_52 = alg_nil();
            alg_root_top = rt_base;
            return ret_52;
            alg_hold_top = rh_664;
        }
    }
    alg_hold_top = rh_663;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1)));
    alg_hold_top = rh_663;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)));
    alg_hold_top = rh_663;
    Value ret_53 = alg_nil();
    alg_root_top = rt_base;
    return ret_53;
}

static Value m_resolver_visitsuperexpr_1_superexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SuperExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_665 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "CurrentClass"), e_classtype_classVnone)))) {
        alg_raise(alg_literal("Can't use 'super' outside a class."));
    } else {
        if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "CurrentClass"), e_classtype_classVsubclass)))) {
            alg_raise(alg_literal("Can't use 'super' in a class with no superclass."));
        }
    }
    alg_hold_top = rh_665;
    (void)(alg_hold(alg_invoke(v_this, "ResolveLocal", (Value[]){v_theexpr, alg_hold(alg_property(v_theexpr, "Keyword"))}, 2)));
    alg_hold_top = rh_665;
    Value ret_54 = alg_nil();
    alg_root_top = rt_base;
    return ret_54;
}

static Value m_resolver_visitthisexpr_1_thisexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "ThisExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_666 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "CurrentClass"), e_classtype_classVnone)))) {
        {
            int32_t rh_667 = alg_hold_top;
            alg_raise(alg_literal("Can't use 'this' outside a class."));
            alg_hold_top = rh_667;
        }
    }
    alg_hold_top = rh_666;
    (void)(alg_hold(alg_invoke(v_this, "ResolveLocal", (Value[]){v_theexpr, alg_hold(alg_property(v_theexpr, "Keyword"))}, 2)));
    alg_hold_top = rh_666;
    Value ret_55 = alg_nil();
    alg_root_top = rt_base;
    return ret_55;
}

static Value m_resolver_visitisexpr_1_isexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "IsExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_668 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)));
    alg_hold_top = rh_668;
    Value ret_56 = alg_nil();
    alg_root_top = rt_base;
    return ret_56;
}

static Value m_resolver_visitgrouping_1_groupingexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GroupingExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_669 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Expression"))}, 1)));
    alg_hold_top = rh_669;
    Value ret_57 = alg_nil();
    alg_root_top = rt_base;
    return ret_57;
}

static Value m_resolver_visitsubscriptexpr_1_subscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SubscriptExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_670 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)));
    alg_hold_top = rh_670;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Index"))}, 1)));
    alg_hold_top = rh_670;
    Value ret_58 = alg_nil();
    alg_root_top = rt_base;
    return ret_58;
}

static Value m_resolver_visitsetsubscriptexpr_1_setsubscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SetSubscriptExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_671 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)));
    alg_hold_top = rh_671;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Index"))}, 1)));
    alg_hold_top = rh_671;
    (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1)));
    alg_hold_top = rh_671;
    Value ret_59 = alg_nil();
    alg_root_top = rt_base;
    return ret_59;
}

static Value m_resolver_visitcollectionexpr_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_672 = alg_hold_top;
    {
        int32_t rt_673 = alg_root_top;
        Value loop_60 = alg_iterable(alg_hold(alg_property(v_theexpr, "Keys")));
        (void)loop_60;
        alg_root(&loop_60, 1);
        for (int32_t at_60 = 0; at_60 < alg_iterable_count(loop_60); at_60++) {
            alg_safe_point();
            int32_t rt_674 = alg_root_top;
            Value v_key = alg_iterable_at(loop_60, at_60);
            (void)v_key;
            alg_root(&v_key, 1);
            (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){v_key}, 1)));
            alg_root_top = rt_674;
        }
        alg_root_top = rt_673;
    }
    alg_hold_top = rh_672;
    {
        int32_t rt_675 = alg_root_top;
        Value loop_61 = alg_iterable(alg_hold(alg_property(v_theexpr, "Values")));
        (void)loop_61;
        alg_root(&loop_61, 1);
        for (int32_t at_61 = 0; at_61 < alg_iterable_count(loop_61); at_61++) {
            alg_safe_point();
            int32_t rt_676 = alg_root_top;
            Value v_value = alg_iterable_at(loop_61, at_61);
            (void)v_value;
            alg_root(&v_value, 1);
            (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){v_value}, 1)));
            alg_root_top = rt_676;
        }
        alg_root_top = rt_675;
    }
    alg_hold_top = rh_672;
    Value ret_62 = alg_nil();
    alg_root_top = rt_base;
    return ret_62;
}

static Value m_resolver_visitliteral_1_literalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "LiteralExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_677 = alg_hold_top;
    Value ret_63 = alg_nil();
    alg_root_top = rt_base;
    return ret_63;
}

static Value m_resolver_visitvariableexpr_1_variableexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "VariableExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_678 = alg_hold_top;
    if (alg_truthy(alg_hold((or_2 = alg_hold(alg_not(alg_hold(alg_property(alg_property(v_this, "Scopes"), "IsEmpty")))), !alg_truthy(or_2) ? or_2 : alg_hold(alg_equal(alg_hold(alg_invoke(alg_hold(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0)), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))}, 1))}, 1)), alg_bool(false))))))) {
        {
            int32_t rh_679 = alg_hold_top;
            alg_raise(alg_literal("Can't read local variable in its own initializer."));
            alg_hold_top = rh_679;
        }
    }
    alg_hold_top = rh_678;
    (void)(alg_hold(alg_invoke(v_this, "ResolveLocal", (Value[]){v_theexpr, alg_hold(alg_property(v_theexpr, "Name"))}, 2)));
    alg_hold_top = rh_678;
    Value ret_64 = alg_nil();
    alg_root_top = rt_base;
    return ret_64;
}

static Value m_resolver_checkduplicates_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_680 = alg_hold_top;
    Value v_seen = alg_nil();
    (void)v_seen;
    alg_root(&v_seen, 1);
    alg_hold_top = rh_680;
    Value v_memberowner = alg_nil();
    (void)v_memberowner;
    alg_root(&v_memberowner, 1);
    alg_hold_top = rh_680;
    Value v_signatures = alg_nil();
    (void)v_signatures;
    alg_root(&v_signatures, 1);
    alg_hold_top = rh_680;
    (void)((v_seen = alg_hold(alg_set())));
    alg_hold_top = rh_680;
    (void)((v_memberowner = alg_hold(alg_map())));
    alg_hold_top = rh_680;
    (void)((v_signatures = alg_hold(alg_map())));
    alg_hold_top = rh_680;
    {
        int32_t rt_681 = alg_root_top;
        Value loop_65 = alg_iterable(v_statements);
        (void)loop_65;
        alg_root(&loop_65, 1);
        for (int32_t at_65 = 0; at_65 < alg_iterable_count(loop_65); at_65++) {
            alg_safe_point();
            int32_t rt_682 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_65, at_65);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rh_683 = alg_hold_top;
                if (alg_truthy(alg_is_class(v_thestmt, k_modulestmt))) {
                    {
                        int32_t rh_684 = alg_hold_top;
                        if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Statements")), alg_nil())))) {
                            (void)(alg_hold(alg_invoke(v_this, "CheckDuplicates", (Value[]){alg_hold(alg_property(v_thestmt, "Statements"))}, 1)));
                        }
                        alg_hold_top = rh_684;
                    }
                } else {
                    {
                        int32_t rt_685 = alg_root_top;
                        int32_t rh_686 = alg_hold_top;
                        Value v_thename = alg_literal("");
                        (void)v_thename;
                        alg_root(&v_thename, 1);
                        alg_hold_top = rh_686;
                        Value v_written = alg_literal("");
                        (void)v_written;
                        alg_root(&v_written, 1);
                        alg_hold_top = rh_686;
                        if (alg_truthy(alg_is_class(v_thestmt, k_functionstmt))) {
                            {
                                int32_t rt_687 = alg_root_top;
                                int32_t rh_688 = alg_hold_top;
                                Value v_fnname = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1));
                                (void)v_fnname;
                                alg_root(&v_fnname, 1);
                                alg_hold_top = rh_688;
                                Value v_signature = alg_hold(alg_invoke(v_this, "SignatureOf", (Value[]){v_thestmt}, 1));
                                (void)v_signature;
                                alg_root(&v_signature, 1);
                                alg_hold_top = rh_688;
                                if (alg_truthy(alg_hold((or_3 = alg_hold(alg_invoke(v_seen, "Contains", (Value[]){v_fnname}, 1)), alg_truthy(or_3) ? or_3 : alg_hold(alg_invoke(v_memberowner, "Contains", (Value[]){v_fnname}, 1)))))) {
                                    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))))), alg_literal("' is already defined."))));
                                }
                                alg_hold_top = rh_688;
                                if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_signatures, "Contains", (Value[]){v_fnname}, 1)))))) {
                                    (void)(alg_hold(alg_invoke(v_signatures, "Put", (Value[]){v_fnname, alg_hold(alg_list())}, 2)));
                                }
                                alg_hold_top = rh_688;
                                Value v_taken = alg_hold(alg_invoke(v_signatures, "Get", (Value[]){v_fnname}, 1));
                                (void)v_taken;
                                alg_root(&v_taken, 1);
                                alg_hold_top = rh_688;
                                {
                                    int32_t rt_689 = alg_root_top;
                                    Value loop_66 = alg_iterable(v_taken);
                                    (void)loop_66;
                                    alg_root(&loop_66, 1);
                                    for (int32_t at_66 = 0; at_66 < alg_iterable_count(loop_66); at_66++) {
                                        alg_safe_point();
                                        int32_t rt_690 = alg_root_top;
                                        Value v_item = alg_iterable_at(loop_66, at_66);
                                        (void)v_item;
                                        alg_root(&v_item, 1);
                                        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_str(v_item)), v_signature)))) {
                                            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))))), alg_literal("' is already defined."))));
                                        }
                                        alg_root_top = rt_690;
                                    }
                                    alg_root_top = rt_689;
                                }
                                alg_hold_top = rh_688;
                                (void)(alg_hold(alg_invoke(v_taken, "Add", (Value[]){v_signature}, 1)));
                                alg_hold_top = rh_688;
                                alg_root_top = rt_687;
                            }
                        }
                        alg_hold_top = rh_686;
                        if (alg_truthy(alg_is_class(v_thestmt, k_classstmt))) {
                            (void)((v_thename = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))));
                        }
                        alg_hold_top = rh_686;
                        if (alg_truthy(alg_is_class(v_thestmt, k_objectstmt))) {
                            (void)((v_thename = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))));
                        }
                        alg_hold_top = rh_686;
                        if (alg_truthy(alg_is_class(v_thestmt, k_varstmt))) {
                            (void)((v_thename = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))));
                        }
                        alg_hold_top = rh_686;
                        if (alg_truthy(alg_is_class(v_thestmt, k_classstmt))) {
                            (void)(alg_hold(alg_invoke(v_this, "CheckMethodDuplicates", (Value[]){alg_hold(alg_property(v_thestmt, "Methods"))}, 1)));
                        }
                        alg_hold_top = rh_686;
                        if (alg_truthy(alg_is_class(v_thestmt, k_objectstmt))) {
                            (void)(alg_hold(alg_invoke(v_this, "CheckMethodDuplicates", (Value[]){alg_hold(alg_property(v_thestmt, "Methods"))}, 1)));
                        }
                        alg_hold_top = rh_686;
                        if (alg_truthy(alg_hold(alg_not_equal(v_thename, alg_literal(""))))) {
                            (void)((v_written = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))));
                        }
                        alg_hold_top = rh_686;
                        if (alg_truthy(alg_is_class(v_thestmt, k_enumstmt))) {
                            {
                                int32_t rt_691 = alg_root_top;
                                int32_t rh_692 = alg_hold_top;
                                Value v_owner = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1));
                                (void)v_owner;
                                alg_root(&v_owner, 1);
                                alg_hold_top = rh_692;
                                {
                                    int32_t rt_693 = alg_root_top;
                                    Value loop_67 = alg_iterable(alg_hold(alg_property(v_thestmt, "Members")));
                                    (void)loop_67;
                                    alg_root(&loop_67, 1);
                                    for (int32_t at_67 = 0; at_67 < alg_iterable_count(loop_67); at_67++) {
                                        alg_safe_point();
                                        int32_t rt_694 = alg_root_top;
                                        Value v_themember = alg_iterable_at(loop_67, at_67);
                                        (void)v_themember;
                                        alg_root(&v_themember, 1);
                                        {
                                            int32_t rt_695 = alg_root_top;
                                            int32_t rh_696 = alg_hold_top;
                                            Value v_member = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_themember, "Lexeme"))}, 1));
                                            (void)v_member;
                                            alg_root(&v_member, 1);
                                            alg_hold_top = rh_696;
                                            Value v_aswritten = alg_hold(alg_str(alg_hold(alg_property(v_themember, "Lexeme"))));
                                            (void)v_aswritten;
                                            alg_root(&v_aswritten, 1);
                                            alg_hold_top = rh_696;
                                            if (alg_truthy(alg_hold(alg_invoke(v_seen, "Contains", (Value[]){v_member}, 1)))) {
                                                alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), v_aswritten)), alg_literal("' is already defined."))));
                                            }
                                            alg_hold_top = rh_696;
                                            if (alg_truthy(alg_hold(alg_invoke(v_memberowner, "Contains", (Value[]){v_member}, 1)))) {
                                                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_str(alg_hold(alg_invoke(v_memberowner, "Get", (Value[]){v_member}, 1)))), v_owner)))) {
                                                    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), v_aswritten)), alg_literal("' is already defined."))));
                                                }
                                            }
                                            alg_hold_top = rh_696;
                                            (void)(alg_hold(alg_invoke(v_memberowner, "Put", (Value[]){v_member, v_owner}, 2)));
                                            alg_hold_top = rh_696;
                                            alg_root_top = rt_695;
                                        }
                                        alg_root_top = rt_694;
                                    }
                                    alg_root_top = rt_693;
                                }
                                alg_hold_top = rh_692;
                                (void)((v_thename = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))));
                                alg_hold_top = rh_692;
                                (void)((v_written = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))));
                                alg_hold_top = rh_692;
                                alg_root_top = rt_691;
                            }
                        }
                        alg_hold_top = rh_686;
                        if (alg_truthy(alg_is_class(v_thestmt, k_vargroupstmt))) {
                            {
                                int32_t rt_697 = alg_root_top;
                                Value loop_68 = alg_iterable(alg_hold(alg_property(v_thestmt, "Names")));
                                (void)loop_68;
                                alg_root(&loop_68, 1);
                                for (int32_t at_68 = 0; at_68 < alg_iterable_count(loop_68); at_68++) {
                                    alg_safe_point();
                                    int32_t rt_698 = alg_root_top;
                                    Value v_eachname = alg_iterable_at(loop_68, at_68);
                                    (void)v_eachname;
                                    alg_root(&v_eachname, 1);
                                    {
                                        int32_t rt_699 = alg_root_top;
                                        int32_t rh_700 = alg_hold_top;
                                        Value v_each = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_eachname, "Lexeme"))}, 1));
                                        (void)v_each;
                                        alg_root(&v_each, 1);
                                        alg_hold_top = rh_700;
                                        if (alg_truthy(alg_hold(alg_invoke(v_seen, "Contains", (Value[]){v_each}, 1)))) {
                                            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), alg_hold(alg_str(alg_hold(alg_property(v_eachname, "Lexeme")))))), alg_literal("' is already defined."))));
                                        }
                                        alg_hold_top = rh_700;
                                        if (alg_truthy(alg_hold(alg_invoke(v_memberowner, "Contains", (Value[]){v_each}, 1)))) {
                                            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), alg_hold(alg_str(alg_hold(alg_property(v_eachname, "Lexeme")))))), alg_literal("' is already defined."))));
                                        }
                                        alg_hold_top = rh_700;
                                        if (alg_truthy(alg_hold(alg_invoke(v_signatures, "Contains", (Value[]){v_each}, 1)))) {
                                            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), alg_hold(alg_str(alg_hold(alg_property(v_eachname, "Lexeme")))))), alg_literal("' is already defined."))));
                                        }
                                        alg_hold_top = rh_700;
                                        (void)(alg_hold(alg_invoke(v_seen, "Add", (Value[]){v_each}, 1)));
                                        alg_hold_top = rh_700;
                                        alg_root_top = rt_699;
                                    }
                                    alg_root_top = rt_698;
                                }
                                alg_root_top = rt_697;
                            }
                        }
                        alg_hold_top = rh_686;
                        if (alg_truthy(alg_hold(alg_not_equal(v_thename, alg_literal(""))))) {
                            {
                                int32_t rh_701 = alg_hold_top;
                                if (alg_truthy(alg_hold(alg_invoke(v_seen, "Contains", (Value[]){v_thename}, 1)))) {
                                    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), v_written)), alg_literal("' is already defined."))));
                                }
                                alg_hold_top = rh_701;
                                if (alg_truthy(alg_hold(alg_invoke(v_memberowner, "Contains", (Value[]){v_thename}, 1)))) {
                                    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), v_written)), alg_literal("' is already defined."))));
                                }
                                alg_hold_top = rh_701;
                                if (alg_truthy(alg_hold(alg_invoke(v_signatures, "Contains", (Value[]){v_thename}, 1)))) {
                                    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), v_written)), alg_literal("' is already defined."))));
                                }
                                alg_hold_top = rh_701;
                                (void)(alg_hold(alg_invoke(v_seen, "Add", (Value[]){v_thename}, 1)));
                                alg_hold_top = rh_701;
                            }
                        }
                        alg_hold_top = rh_686;
                        alg_root_top = rt_685;
                    }
                }
                alg_hold_top = rh_683;
            }
            alg_root_top = rt_682;
        }
        alg_root_top = rt_681;
    }
    alg_hold_top = rh_680;
    Value ret_69 = alg_nil();
    alg_root_top = rt_base;
    return ret_69;
}

static Value m_resolver_signatureof_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_702 = alg_hold_top;
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    alg_hold_top = rh_702;
    (void)((v_text = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length"))))));
    alg_hold_top = rh_702;
    {
        int32_t rt_703 = alg_root_top;
        int32_t rh_704 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_704;
        {
            int32_t rh_705 = alg_hold_top;
            for (; (alg_hold_top = rh_705, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length")))))); (alg_hold_top = rh_705, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_706 = alg_root_top;
                    int32_t rh_707 = alg_hold_top;
                    Value v_declared = alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(v_thestmt, "ParamTypes")), v_i))));
                    (void)v_declared;
                    alg_root(&v_declared, 1);
                    alg_hold_top = rh_707;
                    if (alg_truthy(alg_hold(alg_equal(v_declared, alg_literal(""))))) {
                        (void)((v_declared = alg_literal("Any")));
                    }
                    alg_hold_top = rh_707;
                    (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(v_text, alg_char_value(47))), alg_hold(f_foldcase(NULL, (Value[]){v_declared}, 1))))));
                    alg_hold_top = rh_707;
                    alg_root_top = rt_706;
                }
            }
        }
        alg_hold_top = rh_704;
        alg_root_top = rt_703;
    }
    alg_hold_top = rh_702;
    Value ret_70 = v_text;
    alg_root_top = rt_base;
    return ret_70;
    alg_hold_top = rh_702;
    Value ret_71 = alg_nil();
    alg_root_top = rt_base;
    return ret_71;
}

static Value m_resolver_checkmethodduplicates_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_methods = alg_widen(args[0], "List");
    (void)v_methods;
    alg_root(&v_methods, 1);
    int32_t rh_708 = alg_hold_top;
    Value v_signatures = alg_nil();
    (void)v_signatures;
    alg_root(&v_signatures, 1);
    alg_hold_top = rh_708;
    (void)((v_signatures = alg_hold(alg_map())));
    alg_hold_top = rh_708;
    {
        int32_t rt_709 = alg_root_top;
        Value loop_72 = alg_iterable(v_methods);
        (void)loop_72;
        alg_root(&loop_72, 1);
        for (int32_t at_72 = 0; at_72 < alg_iterable_count(loop_72); at_72++) {
            alg_safe_point();
            int32_t rt_710 = alg_root_top;
            Value v_method = alg_iterable_at(loop_72, at_72);
            (void)v_method;
            alg_root(&v_method, 1);
            {
                int32_t rt_711 = alg_root_top;
                int32_t rh_712 = alg_hold_top;
                Value v_fnname = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_method, "Name")), "Lexeme"))}, 1));
                (void)v_fnname;
                alg_root(&v_fnname, 1);
                alg_hold_top = rh_712;
                Value v_signature = alg_hold(alg_invoke(v_this, "SignatureOf", (Value[]){v_method}, 1));
                (void)v_signature;
                alg_root(&v_signature, 1);
                alg_hold_top = rh_712;
                if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_signatures, "Contains", (Value[]){v_fnname}, 1)))))) {
                    (void)(alg_hold(alg_invoke(v_signatures, "Put", (Value[]){v_fnname, alg_hold(alg_list())}, 2)));
                }
                alg_hold_top = rh_712;
                Value v_taken = alg_hold(alg_invoke(v_signatures, "Get", (Value[]){v_fnname}, 1));
                (void)v_taken;
                alg_root(&v_taken, 1);
                alg_hold_top = rh_712;
                {
                    int32_t rt_713 = alg_root_top;
                    Value loop_73 = alg_iterable(v_taken);
                    (void)loop_73;
                    alg_root(&loop_73, 1);
                    for (int32_t at_73 = 0; at_73 < alg_iterable_count(loop_73); at_73++) {
                        alg_safe_point();
                        int32_t rt_714 = alg_root_top;
                        Value v_item = alg_iterable_at(loop_73, at_73);
                        (void)v_item;
                        alg_root(&v_item, 1);
                        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_str(v_item)), v_signature)))) {
                            alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_method, "Name")), "Lexeme")))))), alg_literal("' is already defined."))));
                        }
                        alg_root_top = rt_714;
                    }
                    alg_root_top = rt_713;
                }
                alg_hold_top = rh_712;
                (void)(alg_hold(alg_invoke(v_taken, "Add", (Value[]){v_signature}, 1)));
                alg_hold_top = rh_712;
                alg_root_top = rt_711;
            }
            alg_root_top = rt_710;
        }
        alg_root_top = rt_709;
    }
    alg_hold_top = rh_708;
    Value ret_74 = alg_nil();
    alg_root_top = rt_base;
    return ret_74;
}

static Value m_resolver_checkinheritance_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_715 = alg_hold_top;
    Value v_parent = alg_nil();
    (void)v_parent;
    alg_root(&v_parent, 1);
    alg_hold_top = rh_715;
    (void)((v_parent = alg_hold(alg_map())));
    alg_hold_top = rh_715;
    {
        int32_t rt_716 = alg_root_top;
        Value loop_75 = alg_iterable(v_statements);
        (void)loop_75;
        alg_root(&loop_75, 1);
        for (int32_t at_75 = 0; at_75 < alg_iterable_count(loop_75); at_75++) {
            alg_safe_point();
            int32_t rt_717 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_75, at_75);
            (void)v_statement;
            alg_root(&v_statement, 1);
            if (alg_truthy(alg_is_class(v_statement, k_classstmt))) {
                if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_statement, "Superclass")), alg_nil())))) {
                    (void)(alg_hold(alg_invoke(v_parent, "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_statement, "Name")), "Lexeme"))}, 1)), alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_statement, "Superclass")), "Name")), "Lexeme"))}, 1))}, 2)));
                }
            }
            alg_root_top = rt_717;
        }
        alg_root_top = rt_716;
    }
    alg_hold_top = rh_715;
    {
        int32_t rt_718 = alg_root_top;
        Value loop_76 = alg_iterable(alg_hold(alg_invoke(v_parent, "Keys", NULL, 0)));
        (void)loop_76;
        alg_root(&loop_76, 1);
        for (int32_t at_76 = 0; at_76 < alg_iterable_count(loop_76); at_76++) {
            alg_safe_point();
            int32_t rt_719 = alg_root_top;
            Value v_name = alg_iterable_at(loop_76, at_76);
            (void)v_name;
            alg_root(&v_name, 1);
            {
                int32_t rt_720 = alg_root_top;
                int32_t rh_721 = alg_hold_top;
                Value v_seen = alg_hold(alg_set());
                (void)v_seen;
                alg_root(&v_seen, 1);
                alg_hold_top = rh_721;
                Value v_at = alg_hold(alg_str(v_name));
                (void)v_at;
                alg_root(&v_at, 1);
                alg_hold_top = rh_721;
                {
                    int32_t rh_722 = alg_hold_top;
                    while ((alg_hold_top = rh_722, alg_truthy(alg_hold(alg_invoke(v_parent, "Contains", (Value[]){v_at}, 1))))) {
                        alg_safe_point();
                        {
                            int32_t rh_723 = alg_hold_top;
                            if (alg_truthy(alg_hold(alg_invoke(v_seen, "Contains", (Value[]){v_at}, 1)))) {
                                alg_raise(alg_literal("A class can't inherit from itself."));
                            }
                            alg_hold_top = rh_723;
                            (void)(alg_hold(alg_invoke(v_seen, "Add", (Value[]){v_at}, 1)));
                            alg_hold_top = rh_723;
                            (void)((v_at = alg_hold(alg_str(alg_hold(alg_invoke(v_parent, "Get", (Value[]){v_at}, 1))))));
                            alg_hold_top = rh_723;
                        }
                    }
                }
                alg_hold_top = rh_721;
                alg_root_top = rt_720;
            }
            alg_root_top = rt_719;
        }
        alg_root_top = rt_718;
    }
    alg_hold_top = rh_715;
    Value ret_77 = alg_nil();
    alg_root_top = rt_base;
    return ret_77;
}

static Value m_resolver_resolveall_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_724 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_property(v_this, "Collected"))))) {
        {
            int32_t rh_725 = alg_hold_top;
            (void)(alg_set_property(v_this, "Collected", alg_bool(true)));
            alg_hold_top = rh_725;
            (void)(alg_hold(alg_invoke(v_this, "CollectDottable", (Value[]){v_statements}, 1)));
            alg_hold_top = rh_725;
            (void)(alg_hold(alg_invoke(v_this, "CollectExtensions", (Value[]){v_statements, alg_literal("")}, 2)));
            alg_hold_top = rh_725;
            (void)(alg_hold(alg_invoke(v_this, "CheckDuplicates", (Value[]){v_statements}, 1)));
            alg_hold_top = rh_725;
            (void)(alg_hold(alg_invoke(v_this, "CheckInheritance", (Value[]){v_statements}, 1)));
            alg_hold_top = rh_725;
        }
    }
    alg_hold_top = rh_724;
    (void)(alg_hold(alg_invoke(v_this, "PushLabels", (Value[]){v_statements}, 1)));
    alg_hold_top = rh_724;
    {
        int32_t rt_726 = alg_root_top;
        Value loop_78 = alg_iterable(v_statements);
        (void)loop_78;
        alg_root(&loop_78, 1);
        for (int32_t at_78 = 0; at_78 < alg_iterable_count(loop_78); at_78++) {
            alg_safe_point();
            int32_t rt_727 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_78, at_78);
            (void)v_statement;
            alg_root(&v_statement, 1);
            {
                int32_t rh_728 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_this, "Resolve", (Value[]){v_statement}, 1)));
                alg_hold_top = rh_728;
            }
            alg_root_top = rt_727;
        }
        alg_root_top = rt_726;
    }
    alg_hold_top = rh_724;
    (void)(alg_hold(alg_invoke(v_this, "PopLabels", NULL, 0)));
    alg_hold_top = rh_724;
    Value ret_79 = alg_nil();
    alg_root_top = rt_base;
    return ret_79;
}

static Value m_resolver_pushlabels_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_729 = alg_hold_top;
    Value v_found = alg_nil();
    (void)v_found;
    alg_root(&v_found, 1);
    alg_hold_top = rh_729;
    (void)((v_found = alg_hold(alg_list())));
    alg_hold_top = rh_729;
    {
        int32_t rt_730 = alg_root_top;
        Value loop_80 = alg_iterable(v_statements);
        (void)loop_80;
        alg_root(&loop_80, 1);
        for (int32_t at_80 = 0; at_80 < alg_iterable_count(loop_80); at_80++) {
            alg_safe_point();
            int32_t rt_731 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_80, at_80);
            (void)v_statement;
            alg_root(&v_statement, 1);
            if (alg_truthy(alg_is_class(v_statement, k_labelstmt))) {
                (void)(alg_hold(alg_invoke(v_found, "Add", (Value[]){v_statement}, 1)));
            }
            alg_root_top = rt_731;
        }
        alg_root_top = rt_730;
    }
    alg_hold_top = rh_729;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LabelScopes"), "Add", (Value[]){v_found}, 1)));
    alg_hold_top = rh_729;
    Value ret_81 = alg_nil();
    alg_root_top = rt_base;
    return ret_81;
}

static Value m_resolver_poplabels_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_732 = alg_hold_top;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LabelScopes"), "RemoveAt", (Value[]){alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "LabelScopes"), "Length")), alg_int(1)))}, 1)));
    alg_hold_top = rh_732;
    Value ret_82 = alg_nil();
    alg_root_top = rt_base;
    return ret_82;
}

static Value m_resolver_findlabel_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_named = alg_widen(args[0], "String");
    (void)v_named;
    alg_root(&v_named, 1);
    int32_t rh_733 = alg_hold_top;
    {
        int32_t rt_734 = alg_root_top;
        int32_t rh_735 = alg_hold_top;
        Value v_s = alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "LabelScopes"), "Length")), alg_int(1)));
        (void)v_s;
        alg_root(&v_s, 1);
        alg_hold_top = rh_735;
        {
            int32_t rh_736 = alg_hold_top;
            for (; (alg_hold_top = rh_736, alg_truthy(alg_hold(alg_greater_equal(v_s, alg_int(0))))); (alg_hold_top = rh_736, (v_s = alg_hold(alg_subtract(v_s, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_737 = alg_root_top;
                    int32_t rh_738 = alg_hold_top;
                    Value v_scope = alg_hold(alg_subscript_get(alg_property(v_this, "LabelScopes"), v_s));
                    (void)v_scope;
                    alg_root(&v_scope, 1);
                    alg_hold_top = rh_738;
                    {
                        int32_t rt_739 = alg_root_top;
                        Value loop_83 = alg_iterable(v_scope);
                        (void)loop_83;
                        alg_root(&loop_83, 1);
                        for (int32_t at_83 = 0; at_83 < alg_iterable_count(loop_83); at_83++) {
                            alg_safe_point();
                            int32_t rt_740 = alg_root_top;
                            Value v_each = alg_iterable_at(loop_83, at_83);
                            (void)v_each;
                            alg_root(&v_each, 1);
                            if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_each, "Name")), "Lexeme"))))}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_named}, 1)))))) {
                                Value ret_84 = v_each;
                                alg_root_top = rt_base;
                                return ret_84;
                            }
                            alg_root_top = rt_740;
                        }
                        alg_root_top = rt_739;
                    }
                    alg_hold_top = rh_738;
                    alg_root_top = rt_737;
                }
            }
        }
        alg_hold_top = rh_735;
        alg_root_top = rt_734;
    }
    alg_hold_top = rh_733;
    Value ret_85 = alg_nil();
    alg_root_top = rt_base;
    return ret_85;
    alg_hold_top = rh_733;
    Value ret_86 = alg_nil();
    alg_root_top = rt_base;
    return ret_86;
}

static Value m_resolver_visitgotostmt_1_gotostmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_stmt = alg_widen(args[0], "GotoStmt");
    (void)v_stmt;
    alg_root(&v_stmt, 1);
    int32_t rh_741 = alg_hold_top;
    Value v_target = alg_nil();
    (void)v_target;
    alg_root(&v_target, 1);
    alg_hold_top = rh_741;
    (void)((v_target = alg_hold(alg_invoke(v_this, "FindLabel", (Value[]){alg_hold(alg_property(v_stmt, "Label"))}, 1))));
    alg_hold_top = rh_741;
    if (alg_truthy(alg_hold(alg_equal(v_target, alg_nil())))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("No label '"), alg_hold(alg_property(v_stmt, "Label")))), alg_literal("' is in scope."))));
    }
    alg_hold_top = rh_741;
    (void)(alg_hold(alg_set_property(v_target, "Targeted", alg_bool(true))));
    alg_hold_top = rh_741;
    Value ret_87 = alg_nil();
    alg_root_top = rt_base;
    return ret_87;
}

static Value m_resolver_resolve_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = args[0];
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_742 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_theexpr, "Accept", (Value[]){v_this}, 1)));
    alg_hold_top = rh_742;
    Value ret_88 = alg_nil();
    alg_root_top = rt_base;
    return ret_88;
}

static Value m_resolver_resolvefunction_2_functionstmt_functiontype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thefunction = alg_widen(args[0], "FunctionStmt");
    (void)v_thefunction;
    alg_root(&v_thefunction, 1);
    Value v_typeoffunction = alg_widen(args[1], "FunctionType");
    (void)v_typeoffunction;
    alg_root(&v_typeoffunction, 1);
    int32_t rh_743 = alg_hold_top;
    Value v_enclosingfunction = alg_nil();
    (void)v_enclosingfunction;
    alg_root(&v_enclosingfunction, 1);
    alg_hold_top = rh_743;
    (void)((v_enclosingfunction = alg_property(v_this, "CurrentFunction")));
    alg_hold_top = rh_743;
    (void)(alg_set_property(v_this, "CurrentFunction", v_typeoffunction));
    alg_hold_top = rh_743;
    (void)(alg_hold(alg_invoke(v_this, "BeginScope", NULL, 0)));
    alg_hold_top = rh_743;
    {
        int32_t rt_744 = alg_root_top;
        Value loop_89 = alg_iterable(alg_hold(alg_property(v_thefunction, "Params")));
        (void)loop_89;
        alg_root(&loop_89, 1);
        for (int32_t at_89 = 0; at_89 < alg_iterable_count(loop_89); at_89++) {
            alg_safe_point();
            int32_t rt_745 = alg_root_top;
            Value v_param = alg_iterable_at(loop_89, at_89);
            (void)v_param;
            alg_root(&v_param, 1);
            {
                int32_t rh_746 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_this, "Declare", (Value[]){v_param}, 1)));
                alg_hold_top = rh_746;
                (void)(alg_hold(alg_invoke(v_this, "Define", (Value[]){v_param}, 1)));
                alg_hold_top = rh_746;
            }
            alg_root_top = rt_745;
        }
        alg_root_top = rt_744;
    }
    alg_hold_top = rh_743;
    Value v_enclosinglabels = alg_property(v_this, "LabelScopes");
    (void)v_enclosinglabels;
    alg_root(&v_enclosinglabels, 1);
    alg_hold_top = rh_743;
    (void)(alg_set_property(v_this, "LabelScopes", alg_hold(alg_list())));
    alg_hold_top = rh_743;
    (void)(alg_hold(alg_invoke(v_this, "ResolveAll", (Value[]){alg_hold(alg_property(v_thefunction, "Body"))}, 1)));
    alg_hold_top = rh_743;
    (void)(alg_set_property(v_this, "LabelScopes", v_enclosinglabels));
    alg_hold_top = rh_743;
    (void)(alg_hold(alg_invoke(v_this, "EndScope", NULL, 0)));
    alg_hold_top = rh_743;
    (void)(alg_set_property(v_this, "CurrentFunction", v_enclosingfunction));
    alg_hold_top = rh_743;
    Value ret_90 = alg_nil();
    alg_root_top = rt_base;
    return ret_90;
}

static Value m_resolver_beginscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_747 = alg_hold_top;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Scopes"), "Push", (Value[]){alg_hold(alg_map())}, 1)));
    alg_hold_top = rh_747;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Constants"), "Push", (Value[]){alg_hold(alg_map())}, 1)));
    alg_hold_top = rh_747;
    Value ret_91 = alg_nil();
    alg_root_top = rt_base;
    return ret_91;
}

static Value m_resolver_endscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_748 = alg_hold_top;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Scopes"), "Pop", NULL, 0)));
    alg_hold_top = rh_748;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Constants"), "Pop", NULL, 0)));
    alg_hold_top = rh_748;
    Value ret_92 = alg_nil();
    alg_root_top = rt_base;
    return ret_92;
}

static Value m_resolver_declare_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_749 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "DeclareBinding", (Value[]){v_name, alg_bool(false)}, 2)));
    alg_hold_top = rh_749;
    Value ret_93 = alg_nil();
    alg_root_top = rt_base;
    return ret_93;
}

static Value m_resolver_declarebinding_2_token_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_isconstant = alg_widen(args[1], "Boolean");
    (void)v_isconstant;
    alg_root(&v_isconstant, 1);
    int32_t rh_750 = alg_hold_top;
    Value v_scope = alg_nil();
    (void)v_scope;
    alg_root(&v_scope, 1);
    alg_hold_top = rh_750;
    if (alg_truthy(alg_hold(alg_property(alg_property(v_this, "Scopes"), "IsEmpty")))) {
        {
            int32_t rh_751 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "GlobalConstants"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1)), v_isconstant}, 2)));
            alg_hold_top = rh_751;
            Value ret_94 = alg_nil();
            alg_root_top = rt_base;
            return ret_94;
            alg_hold_top = rh_751;
        }
    }
    alg_hold_top = rh_750;
    (void)((v_scope = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0), ALG_KIND_MAP, "Map"))));
    alg_hold_top = rh_750;
    if (alg_truthy(alg_hold(alg_invoke(v_scope, "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1)))) {
        {
            int32_t rh_752 = alg_hold_top;
            alg_raise(alg_literal("Already a variable with this name in this scope."));
            alg_hold_top = rh_752;
        }
    }
    alg_hold_top = rh_750;
    (void)(alg_hold(alg_invoke(v_scope, "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1)), alg_bool(false)}, 2)));
    alg_hold_top = rh_750;
    (void)(alg_hold(alg_invoke(alg_hold(alg_invoke(alg_property(v_this, "Constants"), "Peek", NULL, 0)), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1)), v_isconstant}, 2)));
    alg_hold_top = rh_750;
    Value ret_95 = alg_nil();
    alg_root_top = rt_base;
    return ret_95;
}

static Value m_resolver_isconstant_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_753 = alg_hold_top;
    Value v_lexeme = alg_nil();
    (void)v_lexeme;
    alg_root(&v_lexeme, 1);
    alg_hold_top = rh_753;
    (void)((v_lexeme = alg_hold(alg_str(alg_hold(alg_property(v_name, "Lexeme"))))));
    alg_hold_top = rh_753;
    {
        int32_t rt_754 = alg_root_top;
        int32_t rh_755 = alg_hold_top;
        Value v_i = alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "Constants"), "Length")), alg_int(1)));
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_755;
        {
            int32_t rh_756 = alg_hold_top;
            for (; (alg_hold_top = rh_756, alg_truthy(alg_hold(alg_greater_equal(v_i, alg_int(0))))); (alg_hold_top = rh_756, (v_i = alg_hold(alg_subtract(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold(alg_invoke(alg_hold(alg_subscript_get(alg_property(v_this, "Constants"), v_i)), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_lexeme}, 1))}, 1)))) {
                    Value ret_96 = alg_hold(alg_invoke(alg_hold(alg_subscript_get(alg_property(v_this, "Constants"), v_i)), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_lexeme}, 1))}, 1));
                    alg_root_top = rt_base;
                    return ret_96;
                }
            }
        }
        alg_hold_top = rh_755;
        alg_root_top = rt_754;
    }
    alg_hold_top = rh_753;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "GlobalConstants"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_lexeme}, 1))}, 1)))) {
        Value ret_97 = alg_hold(alg_invoke(alg_property(v_this, "GlobalConstants"), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_lexeme}, 1))}, 1));
        alg_root_top = rt_base;
        return ret_97;
    }
    alg_hold_top = rh_753;
    Value ret_98 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_98;
    alg_hold_top = rh_753;
    Value ret_99 = alg_nil();
    alg_root_top = rt_base;
    return ret_99;
}

static Value m_resolver_define_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_757 = alg_hold_top;
    Value v_scope = alg_nil();
    (void)v_scope;
    alg_root(&v_scope, 1);
    alg_hold_top = rh_757;
    if (alg_truthy(alg_hold(alg_property(alg_property(v_this, "Scopes"), "IsEmpty")))) {
        Value ret_100 = alg_nil();
        alg_root_top = rt_base;
        return ret_100;
    }
    alg_hold_top = rh_757;
    (void)((v_scope = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0), ALG_KIND_MAP, "Map"))));
    alg_hold_top = rh_757;
    (void)(alg_hold(alg_invoke(v_scope, "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1)), alg_bool(true)}, 2)));
    alg_hold_top = rh_757;
    Value ret_101 = alg_nil();
    alg_root_top = rt_base;
    return ret_101;
}

static Value m_resolver_resolvelocal_2_expr_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "Expr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_758 = alg_hold_top;
    {
        int32_t rt_759 = alg_root_top;
        int32_t rh_760 = alg_hold_top;
        Value v_i = alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "Scopes"), "Length")), alg_int(1)));
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_760;
        {
            int32_t rh_761 = alg_hold_top;
            for (; (alg_hold_top = rh_761, alg_truthy(alg_hold(alg_greater_equal(v_i, alg_int(0))))); (alg_hold_top = rh_761, (v_i = alg_hold(alg_subtract(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_762 = alg_hold_top;
                    if (alg_truthy(alg_hold(alg_invoke(alg_hold(alg_subscript_get(alg_property(v_this, "Scopes"), v_i)), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1)))) {
                        {
                            int32_t rh_763 = alg_hold_top;
                            (void)(alg_hold(alg_invoke(alg_property(v_this, "TheInterpreter"), "Resolve", (Value[]){v_theexpr, alg_hold(alg_subtract(alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "Scopes"), "Length")), alg_int(1))), v_i))}, 2)));
                            alg_hold_top = rh_763;
                            Value ret_102 = alg_nil();
                            alg_root_top = rt_base;
                            return ret_102;
                            alg_hold_top = rh_763;
                        }
                    }
                    alg_hold_top = rh_762;
                }
            }
        }
        alg_hold_top = rh_760;
        alg_root_top = rt_759;
    }
    alg_hold_top = rh_758;
    Value ret_103 = alg_nil();
    alg_root_top = rt_base;
    return ret_103;
}

static Value *roots_Resolver[] = {
    &e_functiontype,
    &e_functiontype_funVnone,
    &e_functiontype_funVfunction,
    &e_functiontype_funVmethod,
    &e_functiontype_funVinitializer,
    &e_classtype,
    &e_classtype_classVnone,
    &e_classtype_classVclass,
    &e_classtype_classVsubclass,
    &k_resolver,
};

void init_Resolver(void) {
    alg_roots(roots_Resolver, 10);
    k_resolver = alg_class("Resolver", alg_nil());
    e_functiontype = alg_enum_type("FunctionType");
    e_functiontype_funVnone = alg_enum_member(e_functiontype, "FUN_NONE");
    e_functiontype_funVfunction = alg_enum_member(e_functiontype, "FUN_FUNCTION");
    e_functiontype_funVmethod = alg_enum_member(e_functiontype, "FUN_METHOD");
    e_functiontype_funVinitializer = alg_enum_member(e_functiontype, "FUN_INITIALIZER");
    e_classtype = alg_enum_type("ClassType");
    e_classtype_classVnone = alg_enum_member(e_classtype, "CLASS_NONE");
    e_classtype_classVclass = alg_enum_member(e_classtype, "CLASS_CLASS");
    e_classtype_classVsubclass = alg_enum_member(e_classtype, "CLASS_SUBCLASS");
    alg_class_field(k_resolver, "TheInterpreter", "Interpreter");
    alg_class_field(k_resolver, "Scopes", "Stack");
    alg_class_field(k_resolver, "Constants", "Stack");
    alg_class_field(k_resolver, "GlobalConstants", "Map");
    alg_class_field(k_resolver, "CurrentFunction", "FunctionType");
    alg_class_field(k_resolver, "CurrentClass", "ClassType");
    alg_class_field(k_resolver, "Units", "Set");
    alg_class_field(k_resolver, "Dottable", "Set");
    alg_class_field(k_resolver, "Extensions", "Map");
    alg_class_field(k_resolver, "Exported", "Map");
    alg_class_field(k_resolver, "Collected", "Boolean");
    alg_class_field(k_resolver, "LabelScopes", "List");
    alg_class_initializer(k_resolver, i_resolver);
    alg_class_method(k_resolver, "Init", m_resolver_init_1_interpreter, 1, t_resolver_init_1_interpreter);
    alg_class_method(k_resolver, "CollectExtensions", m_resolver_collectextensions_2_list_string, 2, t_resolver_collectextensions_2_list_string);
    alg_class_method(k_resolver, "OwnExtensions", m_resolver_ownextensions_3_map_modulestmt_string, 3, t_resolver_ownextensions_3_map_modulestmt_string);
    alg_class_method(k_resolver, "AdoptExtensions", m_resolver_adoptextensions_1_string, 1, t_resolver_adoptextensions_1_string);
    alg_class_method(k_resolver, "CollectDottable", m_resolver_collectdottable_1_list, 1, t_resolver_collectdottable_1_list);
    alg_class_method(k_resolver, "IsUnitQualifier", m_resolver_isunitqualifier_1, 1, t_resolver_isunitqualifier_1);
    alg_class_method(k_resolver, "VisitBlockStmt", m_resolver_visitblockstmt_1_blockstmt, 1, t_resolver_visitblockstmt_1_blockstmt);
    alg_class_method(k_resolver, "VisitClassStmt", m_resolver_visitclassstmt_1_classstmt, 1, t_resolver_visitclassstmt_1_classstmt);
    alg_class_method(k_resolver, "VisitObjectStmt", m_resolver_visitobjectstmt_1_objectstmt, 1, t_resolver_visitobjectstmt_1_objectstmt);
    alg_class_method(k_resolver, "VisitSubrangeStmt", m_resolver_visitsubrangestmt_1_subrangestmt, 1, t_resolver_visitsubrangestmt_1_subrangestmt);
    alg_class_method(k_resolver, "VisitEnumStmt", m_resolver_visitenumstmt_1_enumstmt, 1, t_resolver_visitenumstmt_1_enumstmt);
    alg_class_method(k_resolver, "VisitExpressionStmt", m_resolver_visitexpressionstmt_1_expressionstmt, 1, t_resolver_visitexpressionstmt_1_expressionstmt);
    alg_class_method(k_resolver, "VisitIfStmt", m_resolver_visitifstmt_1_ifstmt, 1, t_resolver_visitifstmt_1_ifstmt);
    alg_class_method(k_resolver, "VisitTryStmt", m_resolver_visittrystmt_1_trystmt, 1, t_resolver_visittrystmt_1_trystmt);
    alg_class_method(k_resolver, "VisitModuleStmt", m_resolver_visitmodulestmt_1_modulestmt, 1, t_resolver_visitmodulestmt_1_modulestmt);
    alg_class_method(k_resolver, "VisitForInStmt", m_resolver_visitforinstmt_1_forinstmt, 1, t_resolver_visitforinstmt_1_forinstmt);
    alg_class_method(k_resolver, "VisitBreakStmt", m_resolver_visitbreakstmt_1_breakstmt, 1, t_resolver_visitbreakstmt_1_breakstmt);
    alg_class_method(k_resolver, "VisitContinueStmt", m_resolver_visitcontinuestmt_1_continuestmt, 1, t_resolver_visitcontinuestmt_1_continuestmt);
    alg_class_method(k_resolver, "VisitLabelStmt", m_resolver_visitlabelstmt_1_labelstmt, 1, t_resolver_visitlabelstmt_1_labelstmt);
    alg_class_method(k_resolver, "VisitRaiseStmt", m_resolver_visitraisestmt_1_raisestmt, 1, t_resolver_visitraisestmt_1_raisestmt);
    alg_class_method(k_resolver, "VisitReturnStmt", m_resolver_visitreturnstmt_1_returnstmt, 1, t_resolver_visitreturnstmt_1_returnstmt);
    alg_class_method(k_resolver, "VisitWhileStmt", m_resolver_visitwhilestmt_1_whilestmt, 1, t_resolver_visitwhilestmt_1_whilestmt);
    alg_class_method(k_resolver, "VisitFunctionStmt", m_resolver_visitfunctionstmt_1_functionstmt, 1, t_resolver_visitfunctionstmt_1_functionstmt);
    alg_class_method(k_resolver, "VisitVarStmt", m_resolver_visitvarstmt_1_varstmt, 1, t_resolver_visitvarstmt_1_varstmt);
    alg_class_method(k_resolver, "VisitVarGroupStmt", m_resolver_visitvargroupstmt_1_vargroupstmt, 1, t_resolver_visitvargroupstmt_1_vargroupstmt);
    alg_class_method(k_resolver, "VisitAssignExpr", m_resolver_visitassignexpr_1_assignexpr, 1, t_resolver_visitassignexpr_1_assignexpr);
    alg_class_method(k_resolver, "VisitBinary", m_resolver_visitbinary_1_binaryexpr, 1, t_resolver_visitbinary_1_binaryexpr);
    alg_class_method(k_resolver, "VisitLogical", m_resolver_visitlogical_1_logicalexpr, 1, t_resolver_visitlogical_1_logicalexpr);
    alg_class_method(k_resolver, "VisitUnary", m_resolver_visitunary_1_unaryexpr, 1, t_resolver_visitunary_1_unaryexpr);
    alg_class_method(k_resolver, "VisitCall", m_resolver_visitcall_1_callexpr, 1, t_resolver_visitcall_1_callexpr);
    alg_class_method(k_resolver, "VisitGetExpr", m_resolver_visitgetexpr_1_getexpr, 1, t_resolver_visitgetexpr_1_getexpr);
    alg_class_method(k_resolver, "VisitSetExpr", m_resolver_visitsetexpr_1_setexpr, 1, t_resolver_visitsetexpr_1_setexpr);
    alg_class_method(k_resolver, "VisitSuperExpr", m_resolver_visitsuperexpr_1_superexpr, 1, t_resolver_visitsuperexpr_1_superexpr);
    alg_class_method(k_resolver, "VisitThisExpr", m_resolver_visitthisexpr_1_thisexpr, 1, t_resolver_visitthisexpr_1_thisexpr);
    alg_class_method(k_resolver, "VisitIsExpr", m_resolver_visitisexpr_1_isexpr, 1, t_resolver_visitisexpr_1_isexpr);
    alg_class_method(k_resolver, "VisitGrouping", m_resolver_visitgrouping_1_groupingexpr, 1, t_resolver_visitgrouping_1_groupingexpr);
    alg_class_method(k_resolver, "VisitSubscriptExpr", m_resolver_visitsubscriptexpr_1_subscriptexpr, 1, t_resolver_visitsubscriptexpr_1_subscriptexpr);
    alg_class_method(k_resolver, "VisitSetSubscriptExpr", m_resolver_visitsetsubscriptexpr_1_setsubscriptexpr, 1, t_resolver_visitsetsubscriptexpr_1_setsubscriptexpr);
    alg_class_method(k_resolver, "VisitCollectionExpr", m_resolver_visitcollectionexpr_1_collectionexpr, 1, t_resolver_visitcollectionexpr_1_collectionexpr);
    alg_class_method(k_resolver, "VisitLiteral", m_resolver_visitliteral_1_literalexpr, 1, t_resolver_visitliteral_1_literalexpr);
    alg_class_method(k_resolver, "VisitVariableExpr", m_resolver_visitvariableexpr_1_variableexpr, 1, t_resolver_visitvariableexpr_1_variableexpr);
    alg_class_method(k_resolver, "CheckDuplicates", m_resolver_checkduplicates_1_list, 1, t_resolver_checkduplicates_1_list);
    alg_class_method(k_resolver, "SignatureOf", m_resolver_signatureof_1, 1, t_resolver_signatureof_1);
    alg_class_method(k_resolver, "CheckMethodDuplicates", m_resolver_checkmethodduplicates_1_list, 1, t_resolver_checkmethodduplicates_1_list);
    alg_class_method(k_resolver, "CheckInheritance", m_resolver_checkinheritance_1_list, 1, t_resolver_checkinheritance_1_list);
    alg_class_method(k_resolver, "ResolveAll", m_resolver_resolveall_1_list, 1, t_resolver_resolveall_1_list);
    alg_class_method(k_resolver, "PushLabels", m_resolver_pushlabels_1_list, 1, t_resolver_pushlabels_1_list);
    alg_class_method(k_resolver, "PopLabels", m_resolver_poplabels_0, 0, NULL);
    alg_class_method(k_resolver, "FindLabel", m_resolver_findlabel_1_string, 1, t_resolver_findlabel_1_string);
    alg_class_method(k_resolver, "VisitGotoStmt", m_resolver_visitgotostmt_1_gotostmt, 1, t_resolver_visitgotostmt_1_gotostmt);
    alg_class_method(k_resolver, "Resolve", m_resolver_resolve_1, 1, t_resolver_resolve_1);
    alg_class_method(k_resolver, "ResolveFunction", m_resolver_resolvefunction_2_functionstmt_functiontype, 2, t_resolver_resolvefunction_2_functionstmt_functiontype);
    alg_class_method(k_resolver, "BeginScope", m_resolver_beginscope_0, 0, NULL);
    alg_class_method(k_resolver, "EndScope", m_resolver_endscope_0, 0, NULL);
    alg_class_method(k_resolver, "Declare", m_resolver_declare_1_token, 1, t_resolver_declare_1_token);
    alg_class_method(k_resolver, "DeclareBinding", m_resolver_declarebinding_2_token_boolean, 2, t_resolver_declarebinding_2_token_boolean);
    alg_class_method(k_resolver, "IsConstant", m_resolver_isconstant_1_token, 1, t_resolver_isconstant_1_token);
    alg_class_method(k_resolver, "Define", m_resolver_define_1_token, 1, t_resolver_define_1_token);
    alg_class_method(k_resolver, "ResolveLocal", m_resolver_resolvelocal_2_expr_token, 2, t_resolver_resolvelocal_2_expr_token);
    int32_t rh_586 = alg_hold_top;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
    alg_hold_top = rh_586;
}
