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
    alg_set_property(v_this, "LabelScopes", alg_widen(alg_list(), "List"));
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
    (void)(alg_set_property(v_this, "TheInterpreter", v_theinterpreter));
    (void)(alg_set_property(v_this, "Scopes", alg_stack()));
    (void)(alg_set_property(v_this, "Constants", alg_stack()));
    (void)(alg_set_property(v_this, "GlobalConstants", alg_map()));
    (void)(alg_set_property(v_this, "CurrentFunction", e_functiontype_funVnone));
    (void)(alg_set_property(v_this, "CurrentClass", e_classtype_classVnone));
    (void)(alg_set_property(v_this, "Units", alg_set()));
    (void)(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){alg_string("system")}, 1));
    (void)(alg_set_property(v_this, "Dottable", alg_set()));
    (void)(alg_set_property(v_this, "Extensions", alg_map()));
    (void)(alg_set_property(v_this, "Exported", alg_map()));
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
    {
        int32_t rt_68 = alg_root_top;
        Value loop_1 = alg_iterable(v_statements);
        (void)loop_1;
        alg_root(&loop_1, 1);
        for (int32_t at_1 = 0; at_1 < alg_iterable_count(loop_1); at_1++) {
            int32_t rt_69 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_1, at_1);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                if (alg_truthy(alg_not((alg_is(v_thestmt, "FunctionStmt"))))) {
                    continue;
                }
                if (alg_truthy(alg_property(v_thestmt, "IsExtension"))) {
                    (void)(alg_invoke(alg_property(v_this, "Extensions"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), v_unit}, 2));
                }
            }
            alg_root_top = rt_69;
        }
        alg_root_top = rt_68;
    }
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
    Value v_hidden = alg_nil();
    (void)v_hidden;
    alg_root(&v_hidden, 1);
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    (void)((v_hidden = alg_set()));
    {
        int32_t rt_70 = alg_root_top;
        Value loop_3 = alg_iterable(alg_property(v_stmt, "PrivateNames"));
        (void)loop_3;
        alg_root(&loop_3, 1);
        for (int32_t at_3 = 0; at_3 < alg_iterable_count(loop_3); at_3++) {
            int32_t rt_71 = alg_root_top;
            Value v_thename = alg_iterable_at(loop_3, at_3);
            (void)v_thename;
            alg_root(&v_thename, 1);
            (void)(alg_invoke(v_hidden, "Add", (Value[]){f_foldcase(NULL, (Value[]){v_thename}, 1)}, 1));
            alg_root_top = rt_71;
        }
        alg_root_top = rt_70;
    }
    (void)((v_result = alg_map()));
    {
        int32_t rt_72 = alg_root_top;
        Value loop_4 = alg_iterable(alg_invoke(v_inner, "Keys", NULL, 0));
        (void)loop_4;
        alg_root(&loop_4, 1);
        for (int32_t at_4 = 0; at_4 < alg_iterable_count(loop_4); at_4++) {
            int32_t rt_73 = alg_root_top;
            Value v_key = alg_iterable_at(loop_4, at_4);
            (void)v_key;
            alg_root(&v_key, 1);
            {
                if (alg_truthy(alg_not_equal(alg_str(alg_invoke(v_inner, "Get", (Value[]){v_key}, 1)), alg_string("")))) {
                    continue;
                }
                if (alg_truthy(alg_invoke(v_hidden, "Contains", (Value[]){v_key}, 1))) {
                    continue;
                }
                (void)(alg_invoke(v_result, "Put", (Value[]){v_key, v_unit}, 2));
            }
            alg_root_top = rt_73;
        }
        alg_root_top = rt_72;
    }
    Value ret_5 = v_result;
    alg_root_top = rt_base;
    return ret_5;
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
    Value v_theirs = alg_nil();
    (void)v_theirs;
    alg_root(&v_theirs, 1);
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Exported"), "Contains", (Value[]){v_unit}, 1)))) {
        Value ret_7 = alg_nil();
        alg_root_top = rt_base;
        return ret_7;
    }
    (void)((v_theirs = alg_cast(alg_invoke(alg_property(v_this, "Exported"), "Get", (Value[]){v_unit}, 1), "Map")));
    {
        int32_t rt_74 = alg_root_top;
        Value loop_8 = alg_iterable(alg_invoke(v_theirs, "Keys", NULL, 0));
        (void)loop_8;
        alg_root(&loop_8, 1);
        for (int32_t at_8 = 0; at_8 < alg_iterable_count(loop_8); at_8++) {
            int32_t rt_75 = alg_root_top;
            Value v_key = alg_iterable_at(loop_8, at_8);
            (void)v_key;
            alg_root(&v_key, 1);
            (void)(alg_invoke(alg_property(v_this, "Extensions"), "Put", (Value[]){v_key, alg_str(alg_invoke(v_theirs, "Get", (Value[]){v_key}, 1))}, 2));
            alg_root_top = rt_75;
        }
        alg_root_top = rt_74;
    }
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
    {
        int32_t rt_76 = alg_root_top;
        Value loop_10 = alg_iterable(v_statements);
        (void)loop_10;
        alg_root(&loop_10, 1);
        for (int32_t at_10 = 0; at_10 < alg_iterable_count(loop_10); at_10++) {
            int32_t rt_77 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_10, at_10);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                if (alg_truthy(alg_is(v_thestmt, "ObjectStmt"))) {
                    (void)(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)}, 1));
                }
                if (alg_truthy(alg_is(v_thestmt, "EnumStmt"))) {
                    (void)(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)}, 1));
                }
                if (alg_truthy(alg_is(v_thestmt, "VarStmt"))) {
                    (void)(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)}, 1));
                }
                if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                    {
                        int32_t rt_78 = alg_root_top;
                        Value loop_11 = alg_iterable(alg_property(v_thestmt, "Names"));
                        (void)loop_11;
                        alg_root(&loop_11, 1);
                        for (int32_t at_11 = 0; at_11 < alg_iterable_count(loop_11); at_11++) {
                            int32_t rt_79 = alg_root_top;
                            Value v_thename = alg_iterable_at(loop_11, at_11);
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            (void)(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_thename, "Lexeme")}, 1)}, 1));
                            alg_root_top = rt_79;
                        }
                        alg_root_top = rt_78;
                    }
                }
                if (alg_truthy((or_0 = alg_is(v_thestmt, "ModuleStmt"), !alg_truthy(or_0) ? or_0 : alg_not_equal(alg_property(v_thestmt, "Statements"), alg_nil())))) {
                    (void)(alg_invoke(v_this, "CollectDottable", (Value[]){alg_property(v_thestmt, "Statements")}, 1));
                }
            }
            alg_root_top = rt_77;
        }
        alg_root_top = rt_76;
    }
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
    if (alg_truthy(alg_not((alg_is(v_obj, "VariableExpr"))))) {
        Value ret_13 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_13;
    }
    Value v_name = alg_str(alg_property(alg_property(v_obj, "Name"), "Lexeme"));
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Units"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1)))) {
        Value ret_14 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_14;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Dottable"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
        Value ret_15 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_15;
    }
    {
        int32_t rt_80 = alg_root_top;
        Value v_i = alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1));
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_greater_equal(v_i, alg_int(0))); (v_i = alg_subtract(v_i, alg_int(1)))) {
            if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), v_i), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
                Value ret_16 = alg_bool(false);
                alg_root_top = rt_base;
                return ret_16;
            }
        }
        alg_root_top = rt_80;
    }
    Value ret_17 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_17;
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
    (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
    (void)(alg_invoke(v_this, "ResolveAll", (Value[]){alg_property(v_stmt, "Statements")}, 1));
    (void)(alg_invoke(v_this, "EndScope", NULL, 0));
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
    Value v_enclosingclass = alg_nil();
    (void)v_enclosingclass;
    alg_root(&v_enclosingclass, 1);
    (void)((v_enclosingclass = alg_property(v_this, "CurrentClass")));
    (void)(alg_set_property(v_this, "CurrentClass", e_classtype_classVclass));
    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_stmt, "Name")}, 1));
    if (alg_truthy((or_1 = alg_not_equal(alg_property(v_stmt, "Superclass"), alg_nil()), !alg_truthy(or_1) ? or_1 : alg_equal(alg_property(alg_property(v_stmt, "Name"), "Lexeme"), alg_property(alg_property(alg_property(v_stmt, "Superclass"), "Name"), "Lexeme"))))) {
        {
            alg_raise(alg_string("A class can't inherit from itself."));
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_stmt, "Superclass"), alg_nil()))) {
        {
            (void)(alg_set_property(v_this, "CurrentClass", e_classtype_classVsubclass));
            (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Superclass")}, 1));
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_stmt, "Superclass"), alg_nil()))) {
        {
            (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
            (void)(alg_invoke(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0), "Put", (Value[]){alg_string("super"), alg_bool(true)}, 2));
        }
    }
    (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
    (void)(alg_invoke(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0), "Put", (Value[]){alg_string("this"), alg_bool(true)}, 2));
    {
        int32_t rt_81 = alg_root_top;
        Value loop_20 = alg_iterable(alg_property(v_stmt, "Methods"));
        (void)loop_20;
        alg_root(&loop_20, 1);
        for (int32_t at_20 = 0; at_20 < alg_iterable_count(loop_20); at_20++) {
            int32_t rt_82 = alg_root_top;
            Value v_method = alg_iterable_at(loop_20, at_20);
            (void)v_method;
            alg_root(&v_method, 1);
            {
                int32_t rt_83 = alg_root_top;
                Value v_declaration = e_functiontype_funVfunction;
                (void)v_declaration;
                alg_root(&v_declaration, 1);
                if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(alg_property(v_method, "Name"), "Lexeme")}, 1), alg_string("init")))) {
                    {
                        (void)((v_declaration = e_functiontype_funVinitializer));
                    }
                }
                (void)(alg_invoke(v_this, "ResolveFunction", (Value[]){v_method, v_declaration}, 2));
                alg_root_top = rt_83;
            }
            alg_root_top = rt_82;
        }
        alg_root_top = rt_81;
    }
    (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    if (alg_truthy(alg_not_equal(alg_property(v_stmt, "Superclass"), alg_nil()))) {
        (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    }
    (void)(alg_set_property(v_this, "CurrentClass", v_enclosingclass));
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
    (void)(alg_invoke(v_this, "VisitClassStmt", (Value[]){alg_new(k_classstmt, (Value[]){alg_property(v_stmt, "Name"), alg_property(v_stmt, "Superclass"), alg_property(v_stmt, "Methods"), alg_property(v_stmt, "Fields")}, 4)}, 1));
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
    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(f_definesubrange(NULL, (Value[]){alg_property(alg_property(v_stmt, "Name"), "Lexeme"), alg_property(v_stmt, "Low"), alg_property(v_stmt, "High")}, 3));
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
    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_stmt, "Name")}, 1));
    {
        int32_t rt_84 = alg_root_top;
        Value loop_24 = alg_iterable(alg_property(v_stmt, "Members"));
        (void)loop_24;
        alg_root(&loop_24, 1);
        for (int32_t at_24 = 0; at_24 < alg_iterable_count(loop_24); at_24++) {
            int32_t rt_85 = alg_root_top;
            Value v_member = alg_iterable_at(loop_24, at_24);
            (void)v_member;
            alg_root(&v_member, 1);
            {
                (void)(alg_invoke(v_this, "Declare", (Value[]){v_member}, 1));
                (void)(alg_invoke(v_this, "Define", (Value[]){v_member}, 1));
            }
            alg_root_top = rt_85;
        }
        alg_root_top = rt_84;
    }
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Expression")}, 1));
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Condition")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "ThenBranch")}, 1));
    if (alg_truthy((alg_not_equal(alg_property(v_stmt, "ElseBranch"), alg_nil())))) {
        (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "ElseBranch")}, 1));
    }
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
    Value v_keys = alg_nil();
    (void)v_keys;
    alg_root(&v_keys, 1);
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "TryBlock")}, 1));
    (void)((v_keys = alg_invoke(alg_property(v_stmt, "Handlers"), "Keys", NULL, 0)));
    {
        int32_t rt_86 = alg_root_top;
        Value loop_28 = alg_iterable(v_keys);
        (void)loop_28;
        alg_root(&loop_28, 1);
        for (int32_t at_28 = 0; at_28 < alg_iterable_count(loop_28); at_28++) {
            int32_t rt_87 = alg_root_top;
            Value v_key = alg_iterable_at(loop_28, at_28);
            (void)v_key;
            alg_root(&v_key, 1);
            (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(alg_invoke(alg_property(v_stmt, "Handlers"), "Get", (Value[]){v_key}, 1), "Body")}, 1));
            alg_root_top = rt_87;
        }
        alg_root_top = rt_86;
    }
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
    Value v_enclosing = alg_nil();
    (void)v_enclosing;
    alg_root(&v_enclosing, 1);
    Value v_outer = alg_nil();
    (void)v_outer;
    alg_root(&v_outer, 1);
    Value v_inner = alg_nil();
    (void)v_inner;
    alg_root(&v_inner, 1);
    Value v_unit = alg_nil();
    (void)v_unit;
    alg_root(&v_unit, 1);
    (void)((v_unit = f_foldcase(NULL, (Value[]){alg_property(v_stmt, "UnitName")}, 1)));
    if (alg_truthy(alg_equal(alg_property(v_stmt, "Statements"), alg_nil()))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){v_unit}, 1));
            (void)(alg_invoke(v_this, "AdoptExtensions", (Value[]){v_unit}, 1));
            Value ret_30 = alg_nil();
            alg_root_top = rt_base;
            return ret_30;
        }
    }
    (void)((v_enclosing = alg_property(v_this, "Units")));
    (void)(alg_set_property(v_this, "Units", alg_set()));
    (void)(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){alg_string("system")}, 1));
    (void)((v_outer = alg_property(v_this, "Extensions")));
    (void)(alg_set_property(v_this, "Extensions", alg_map()));
    (void)(alg_invoke(v_this, "CollectExtensions", (Value[]){alg_property(v_stmt, "Statements"), alg_string("")}, 2));
    (void)(alg_invoke(v_this, "ResolveAll", (Value[]){alg_property(v_stmt, "Statements")}, 1));
    (void)((v_inner = alg_property(v_this, "Extensions")));
    (void)(alg_set_property(v_this, "Units", v_enclosing));
    (void)(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){v_unit}, 1));
    (void)(alg_set_property(v_this, "Extensions", v_outer));
    (void)(alg_invoke(alg_property(v_this, "Exported"), "Put", (Value[]){v_unit, alg_invoke(v_this, "OwnExtensions", (Value[]){v_inner, v_stmt, v_unit}, 3)}, 2));
    (void)(alg_invoke(v_this, "AdoptExtensions", (Value[]){v_unit}, 1));
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Iterable")}, 1));
    (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Body")}, 1));
    (void)(alg_invoke(v_this, "EndScope", NULL, 0));
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Inner")}, 1));
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Value")}, 1));
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
    if (alg_truthy(alg_equal(alg_property(v_this, "CurrentFunction"), e_functiontype_funVnone))) {
        {
            alg_raise(alg_string("Can't return from top-level code."));
        }
    }
    if (alg_truthy((alg_not_equal(alg_property(v_stmt, "Value"), alg_nil())))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "CurrentFunction"), e_functiontype_funVinitializer))) {
                {
                    alg_raise(alg_string("Can't return a value from an initializer."));
                }
            }
            (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Value")}, 1));
        }
    }
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Condition")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Body")}, 1));
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
    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "ResolveFunction", (Value[]){v_stmt, e_functiontype_funVfunction}, 2));
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
    (void)(alg_invoke(v_this, "DeclareBinding", (Value[]){alg_property(v_stmt, "Name"), alg_property(v_stmt, "IsConstant")}, 2));
    if (alg_truthy((alg_not_equal(alg_property(v_stmt, "Initializer"), alg_nil())))) {
        {
            (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Initializer")}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_stmt, "Name")}, 1));
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
    {
        int32_t rt_88 = alg_root_top;
        Value loop_41 = alg_iterable(alg_property(v_stmt, "Names"));
        (void)loop_41;
        alg_root(&loop_41, 1);
        for (int32_t at_41 = 0; at_41 < alg_iterable_count(loop_41); at_41++) {
            int32_t rt_89 = alg_root_top;
            Value v_name = alg_iterable_at(loop_41, at_41);
            (void)v_name;
            alg_root(&v_name, 1);
            (void)(alg_invoke(v_this, "DeclareBinding", (Value[]){v_name, alg_property(v_stmt, "IsConstant")}, 2));
            alg_root_top = rt_89;
        }
        alg_root_top = rt_88;
    }
    if (alg_truthy(alg_not_equal(alg_property(v_stmt, "Initializer"), alg_nil()))) {
        (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Initializer")}, 1));
    }
    {
        int32_t rt_90 = alg_root_top;
        Value loop_42 = alg_iterable(alg_property(v_stmt, "Names"));
        (void)loop_42;
        alg_root(&loop_42, 1);
        for (int32_t at_42 = 0; at_42 < alg_iterable_count(loop_42); at_42++) {
            int32_t rt_91 = alg_root_top;
            Value v_thename = alg_iterable_at(loop_42, at_42);
            (void)v_thename;
            alg_root(&v_thename, 1);
            (void)(alg_invoke(v_this, "Define", (Value[]){v_thename}, 1));
            alg_root_top = rt_91;
        }
        alg_root_top = rt_90;
    }
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
    if (alg_truthy(alg_invoke(v_this, "IsConstant", (Value[]){alg_property(v_theexpr, "Name")}, 1))) {
        alg_raise(alg_add(alg_add(alg_string("Can't assign to constant '"), alg_property(alg_property(v_theexpr, "Name"), "Lexeme")), alg_string("'.")));
    }
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Value")}, 1));
    (void)(alg_invoke(v_this, "ResolveLocal", (Value[]){v_theexpr, alg_property(v_theexpr, "Name")}, 2));
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Left")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Right")}, 1));
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Left")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Right")}, 1));
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Right")}, 1));
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Callee")}, 1));
    {
        int32_t rt_92 = alg_root_top;
        Value loop_48 = alg_iterable(alg_property(v_theexpr, "Arguments"));
        (void)loop_48;
        alg_root(&loop_48, 1);
        for (int32_t at_48 = 0; at_48 < alg_iterable_count(loop_48); at_48++) {
            int32_t rt_93 = alg_root_top;
            Value v_argument = alg_iterable_at(loop_48, at_48);
            (void)v_argument;
            alg_root(&v_argument, 1);
            {
                (void)(alg_invoke(v_this, "Resolve", (Value[]){v_argument}, 1));
            }
            alg_root_top = rt_93;
        }
        alg_root_top = rt_92;
    }
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
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    if (alg_truthy(alg_invoke(v_this, "IsUnitQualifier", (Value[]){alg_property(v_theexpr, "Obj")}, 1))) {
        {
            (void)(alg_set_property(v_theexpr, "Unit", alg_str(alg_property(alg_property(alg_property(v_theexpr, "Obj"), "Name"), "Lexeme"))));
            Value ret_50 = alg_nil();
            alg_root_top = rt_base;
            return ret_50;
        }
    }
    (void)((v_folded = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1)));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Extensions"), "Contains", (Value[]){v_folded}, 1))) {
        {
            (void)(alg_set_property(v_theexpr, "Extension", alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))));
            (void)(alg_set_property(v_theexpr, "ExtensionUnit", alg_str(alg_invoke(alg_property(v_this, "Extensions"), "Get", (Value[]){v_folded}, 1))));
        }
    }
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
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
    if (alg_truthy(alg_invoke(v_this, "IsUnitQualifier", (Value[]){alg_property(v_theexpr, "Obj")}, 1))) {
        {
            (void)(alg_set_property(v_theexpr, "Unit", alg_str(alg_property(alg_property(alg_property(v_theexpr, "Obj"), "Name"), "Lexeme"))));
            (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Value")}, 1));
            Value ret_52 = alg_nil();
            alg_root_top = rt_base;
            return ret_52;
        }
    }
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Value")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
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
    if (alg_truthy(alg_equal(alg_property(v_this, "CurrentClass"), e_classtype_classVnone))) {
        alg_raise(alg_string("Can't use 'super' outside a class."));
    } else {
        if (alg_truthy(alg_not_equal(alg_property(v_this, "CurrentClass"), e_classtype_classVsubclass))) {
            alg_raise(alg_string("Can't use 'super' in a class with no superclass."));
        }
    }
    (void)(alg_invoke(v_this, "ResolveLocal", (Value[]){v_theexpr, alg_property(v_theexpr, "Keyword")}, 2));
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
    if (alg_truthy(alg_equal(alg_property(v_this, "CurrentClass"), e_classtype_classVnone))) {
        {
            alg_raise(alg_string("Can't use 'this' outside a class."));
        }
    }
    (void)(alg_invoke(v_this, "ResolveLocal", (Value[]){v_theexpr, alg_property(v_theexpr, "Keyword")}, 2));
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Expression")}, 1));
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Index")}, 1));
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
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Index")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Value")}, 1));
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
    {
        int32_t rt_94 = alg_root_top;
        Value loop_60 = alg_iterable(alg_property(v_theexpr, "Keys"));
        (void)loop_60;
        alg_root(&loop_60, 1);
        for (int32_t at_60 = 0; at_60 < alg_iterable_count(loop_60); at_60++) {
            int32_t rt_95 = alg_root_top;
            Value v_key = alg_iterable_at(loop_60, at_60);
            (void)v_key;
            alg_root(&v_key, 1);
            (void)(alg_invoke(v_this, "Resolve", (Value[]){v_key}, 1));
            alg_root_top = rt_95;
        }
        alg_root_top = rt_94;
    }
    {
        int32_t rt_96 = alg_root_top;
        Value loop_61 = alg_iterable(alg_property(v_theexpr, "Values"));
        (void)loop_61;
        alg_root(&loop_61, 1);
        for (int32_t at_61 = 0; at_61 < alg_iterable_count(loop_61); at_61++) {
            int32_t rt_97 = alg_root_top;
            Value v_value = alg_iterable_at(loop_61, at_61);
            (void)v_value;
            alg_root(&v_value, 1);
            (void)(alg_invoke(v_this, "Resolve", (Value[]){v_value}, 1));
            alg_root_top = rt_97;
        }
        alg_root_top = rt_96;
    }
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
    if (alg_truthy((or_2 = alg_not(alg_property(alg_property(v_this, "Scopes"), "IsEmpty")), !alg_truthy(or_2) ? or_2 : alg_equal(alg_invoke(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1)}, 1), alg_bool(false))))) {
        {
            alg_raise(alg_string("Can't read local variable in its own initializer."));
        }
    }
    (void)(alg_invoke(v_this, "ResolveLocal", (Value[]){v_theexpr, alg_property(v_theexpr, "Name")}, 2));
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
    Value v_seen = alg_nil();
    (void)v_seen;
    alg_root(&v_seen, 1);
    Value v_memberowner = alg_nil();
    (void)v_memberowner;
    alg_root(&v_memberowner, 1);
    Value v_signatures = alg_nil();
    (void)v_signatures;
    alg_root(&v_signatures, 1);
    (void)((v_seen = alg_set()));
    (void)((v_memberowner = alg_map()));
    (void)((v_signatures = alg_map()));
    {
        int32_t rt_98 = alg_root_top;
        Value loop_65 = alg_iterable(v_statements);
        (void)loop_65;
        alg_root(&loop_65, 1);
        for (int32_t at_65 = 0; at_65 < alg_iterable_count(loop_65); at_65++) {
            int32_t rt_99 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_65, at_65);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                if (alg_truthy(alg_is(v_thestmt, "ModuleStmt"))) {
                    {
                        if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Statements"), alg_nil()))) {
                            (void)(alg_invoke(v_this, "CheckDuplicates", (Value[]){alg_property(v_thestmt, "Statements")}, 1));
                        }
                    }
                } else {
                    {
                        int32_t rt_100 = alg_root_top;
                        Value v_thename = alg_string("");
                        (void)v_thename;
                        alg_root(&v_thename, 1);
                        Value v_written = alg_string("");
                        (void)v_written;
                        alg_root(&v_written, 1);
                        if (alg_truthy(alg_is(v_thestmt, "FunctionStmt"))) {
                            {
                                int32_t rt_101 = alg_root_top;
                                Value v_fnname = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1);
                                (void)v_fnname;
                                alg_root(&v_fnname, 1);
                                Value v_signature = alg_invoke(v_this, "SignatureOf", (Value[]){v_thestmt}, 1);
                                (void)v_signature;
                                alg_root(&v_signature, 1);
                                if (alg_truthy((or_3 = alg_invoke(v_seen, "Contains", (Value[]){v_fnname}, 1), alg_truthy(or_3) ? or_3 : alg_invoke(v_memberowner, "Contains", (Value[]){v_fnname}, 1)))) {
                                    alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))), alg_string("' is already defined.")));
                                }
                                if (alg_truthy(alg_not(alg_invoke(v_signatures, "Contains", (Value[]){v_fnname}, 1)))) {
                                    (void)(alg_invoke(v_signatures, "Put", (Value[]){v_fnname, alg_list()}, 2));
                                }
                                Value v_taken = alg_invoke(v_signatures, "Get", (Value[]){v_fnname}, 1);
                                (void)v_taken;
                                alg_root(&v_taken, 1);
                                {
                                    int32_t rt_102 = alg_root_top;
                                    Value loop_66 = alg_iterable(v_taken);
                                    (void)loop_66;
                                    alg_root(&loop_66, 1);
                                    for (int32_t at_66 = 0; at_66 < alg_iterable_count(loop_66); at_66++) {
                                        int32_t rt_103 = alg_root_top;
                                        Value v_item = alg_iterable_at(loop_66, at_66);
                                        (void)v_item;
                                        alg_root(&v_item, 1);
                                        if (alg_truthy(alg_equal(alg_str(v_item), v_signature))) {
                                            alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))), alg_string("' is already defined.")));
                                        }
                                        alg_root_top = rt_103;
                                    }
                                    alg_root_top = rt_102;
                                }
                                (void)(alg_invoke(v_taken, "Add", (Value[]){v_signature}, 1));
                                alg_root_top = rt_101;
                            }
                        }
                        if (alg_truthy(alg_is(v_thestmt, "ClassStmt"))) {
                            (void)((v_thename = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)));
                        }
                        if (alg_truthy(alg_is(v_thestmt, "ObjectStmt"))) {
                            (void)((v_thename = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)));
                        }
                        if (alg_truthy(alg_is(v_thestmt, "VarStmt"))) {
                            (void)((v_thename = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)));
                        }
                        if (alg_truthy(alg_is(v_thestmt, "ClassStmt"))) {
                            (void)(alg_invoke(v_this, "CheckMethodDuplicates", (Value[]){alg_property(v_thestmt, "Methods")}, 1));
                        }
                        if (alg_truthy(alg_is(v_thestmt, "ObjectStmt"))) {
                            (void)(alg_invoke(v_this, "CheckMethodDuplicates", (Value[]){alg_property(v_thestmt, "Methods")}, 1));
                        }
                        if (alg_truthy(alg_not_equal(v_thename, alg_string("")))) {
                            (void)((v_written = alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))));
                        }
                        if (alg_truthy(alg_is(v_thestmt, "EnumStmt"))) {
                            {
                                int32_t rt_104 = alg_root_top;
                                Value v_owner = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1);
                                (void)v_owner;
                                alg_root(&v_owner, 1);
                                {
                                    int32_t rt_105 = alg_root_top;
                                    Value loop_67 = alg_iterable(alg_property(v_thestmt, "Members"));
                                    (void)loop_67;
                                    alg_root(&loop_67, 1);
                                    for (int32_t at_67 = 0; at_67 < alg_iterable_count(loop_67); at_67++) {
                                        int32_t rt_106 = alg_root_top;
                                        Value v_themember = alg_iterable_at(loop_67, at_67);
                                        (void)v_themember;
                                        alg_root(&v_themember, 1);
                                        {
                                            int32_t rt_107 = alg_root_top;
                                            Value v_member = f_foldcase(NULL, (Value[]){alg_property(v_themember, "Lexeme")}, 1);
                                            (void)v_member;
                                            alg_root(&v_member, 1);
                                            Value v_aswritten = alg_str(alg_property(v_themember, "Lexeme"));
                                            (void)v_aswritten;
                                            alg_root(&v_aswritten, 1);
                                            if (alg_truthy(alg_invoke(v_seen, "Contains", (Value[]){v_member}, 1))) {
                                                alg_raise(alg_add(alg_add(alg_char_value(39), v_aswritten), alg_string("' is already defined.")));
                                            }
                                            if (alg_truthy(alg_invoke(v_memberowner, "Contains", (Value[]){v_member}, 1))) {
                                                if (alg_truthy(alg_equal(alg_str(alg_invoke(v_memberowner, "Get", (Value[]){v_member}, 1)), v_owner))) {
                                                    alg_raise(alg_add(alg_add(alg_char_value(39), v_aswritten), alg_string("' is already defined.")));
                                                }
                                            }
                                            (void)(alg_invoke(v_memberowner, "Put", (Value[]){v_member, v_owner}, 2));
                                            alg_root_top = rt_107;
                                        }
                                        alg_root_top = rt_106;
                                    }
                                    alg_root_top = rt_105;
                                }
                                (void)((v_thename = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)));
                                (void)((v_written = alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))));
                                alg_root_top = rt_104;
                            }
                        }
                        if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                            {
                                int32_t rt_108 = alg_root_top;
                                Value loop_68 = alg_iterable(alg_property(v_thestmt, "Names"));
                                (void)loop_68;
                                alg_root(&loop_68, 1);
                                for (int32_t at_68 = 0; at_68 < alg_iterable_count(loop_68); at_68++) {
                                    int32_t rt_109 = alg_root_top;
                                    Value v_eachname = alg_iterable_at(loop_68, at_68);
                                    (void)v_eachname;
                                    alg_root(&v_eachname, 1);
                                    {
                                        int32_t rt_110 = alg_root_top;
                                        Value v_each = f_foldcase(NULL, (Value[]){alg_property(v_eachname, "Lexeme")}, 1);
                                        (void)v_each;
                                        alg_root(&v_each, 1);
                                        if (alg_truthy(alg_invoke(v_seen, "Contains", (Value[]){v_each}, 1))) {
                                            alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(v_eachname, "Lexeme"))), alg_string("' is already defined.")));
                                        }
                                        if (alg_truthy(alg_invoke(v_memberowner, "Contains", (Value[]){v_each}, 1))) {
                                            alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(v_eachname, "Lexeme"))), alg_string("' is already defined.")));
                                        }
                                        if (alg_truthy(alg_invoke(v_signatures, "Contains", (Value[]){v_each}, 1))) {
                                            alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(v_eachname, "Lexeme"))), alg_string("' is already defined.")));
                                        }
                                        (void)(alg_invoke(v_seen, "Add", (Value[]){v_each}, 1));
                                        alg_root_top = rt_110;
                                    }
                                    alg_root_top = rt_109;
                                }
                                alg_root_top = rt_108;
                            }
                        }
                        if (alg_truthy(alg_not_equal(v_thename, alg_string("")))) {
                            {
                                if (alg_truthy(alg_invoke(v_seen, "Contains", (Value[]){v_thename}, 1))) {
                                    alg_raise(alg_add(alg_add(alg_char_value(39), v_written), alg_string("' is already defined.")));
                                }
                                if (alg_truthy(alg_invoke(v_memberowner, "Contains", (Value[]){v_thename}, 1))) {
                                    alg_raise(alg_add(alg_add(alg_char_value(39), v_written), alg_string("' is already defined.")));
                                }
                                if (alg_truthy(alg_invoke(v_signatures, "Contains", (Value[]){v_thename}, 1))) {
                                    alg_raise(alg_add(alg_add(alg_char_value(39), v_written), alg_string("' is already defined.")));
                                }
                                (void)(alg_invoke(v_seen, "Add", (Value[]){v_thename}, 1));
                            }
                        }
                        alg_root_top = rt_100;
                    }
                }
            }
            alg_root_top = rt_99;
        }
        alg_root_top = rt_98;
    }
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
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    (void)((v_text = alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))));
    {
        int32_t rt_111 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_112 = alg_root_top;
                Value v_declared = alg_str(alg_subscript_get(alg_property(v_thestmt, "ParamTypes"), v_i));
                (void)v_declared;
                alg_root(&v_declared, 1);
                if (alg_truthy(alg_equal(v_declared, alg_string("")))) {
                    (void)((v_declared = alg_string("Any")));
                }
                (void)((v_text = alg_add(alg_add(v_text, alg_char_value(47)), f_foldcase(NULL, (Value[]){v_declared}, 1))));
                alg_root_top = rt_112;
            }
        }
        alg_root_top = rt_111;
    }
    Value ret_70 = v_text;
    alg_root_top = rt_base;
    return ret_70;
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
    Value v_signatures = alg_nil();
    (void)v_signatures;
    alg_root(&v_signatures, 1);
    (void)((v_signatures = alg_map()));
    {
        int32_t rt_113 = alg_root_top;
        Value loop_72 = alg_iterable(v_methods);
        (void)loop_72;
        alg_root(&loop_72, 1);
        for (int32_t at_72 = 0; at_72 < alg_iterable_count(loop_72); at_72++) {
            int32_t rt_114 = alg_root_top;
            Value v_method = alg_iterable_at(loop_72, at_72);
            (void)v_method;
            alg_root(&v_method, 1);
            {
                int32_t rt_115 = alg_root_top;
                Value v_fnname = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_method, "Name"), "Lexeme")}, 1);
                (void)v_fnname;
                alg_root(&v_fnname, 1);
                Value v_signature = alg_invoke(v_this, "SignatureOf", (Value[]){v_method}, 1);
                (void)v_signature;
                alg_root(&v_signature, 1);
                if (alg_truthy(alg_not(alg_invoke(v_signatures, "Contains", (Value[]){v_fnname}, 1)))) {
                    (void)(alg_invoke(v_signatures, "Put", (Value[]){v_fnname, alg_list()}, 2));
                }
                Value v_taken = alg_invoke(v_signatures, "Get", (Value[]){v_fnname}, 1);
                (void)v_taken;
                alg_root(&v_taken, 1);
                {
                    int32_t rt_116 = alg_root_top;
                    Value loop_73 = alg_iterable(v_taken);
                    (void)loop_73;
                    alg_root(&loop_73, 1);
                    for (int32_t at_73 = 0; at_73 < alg_iterable_count(loop_73); at_73++) {
                        int32_t rt_117 = alg_root_top;
                        Value v_item = alg_iterable_at(loop_73, at_73);
                        (void)v_item;
                        alg_root(&v_item, 1);
                        if (alg_truthy(alg_equal(alg_str(v_item), v_signature))) {
                            alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_property(v_method, "Name"), "Lexeme"))), alg_string("' is already defined.")));
                        }
                        alg_root_top = rt_117;
                    }
                    alg_root_top = rt_116;
                }
                (void)(alg_invoke(v_taken, "Add", (Value[]){v_signature}, 1));
                alg_root_top = rt_115;
            }
            alg_root_top = rt_114;
        }
        alg_root_top = rt_113;
    }
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
    Value v_parent = alg_nil();
    (void)v_parent;
    alg_root(&v_parent, 1);
    (void)((v_parent = alg_map()));
    {
        int32_t rt_118 = alg_root_top;
        Value loop_75 = alg_iterable(v_statements);
        (void)loop_75;
        alg_root(&loop_75, 1);
        for (int32_t at_75 = 0; at_75 < alg_iterable_count(loop_75); at_75++) {
            int32_t rt_119 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_75, at_75);
            (void)v_statement;
            alg_root(&v_statement, 1);
            if (alg_truthy(alg_is(v_statement, "ClassStmt"))) {
                if (alg_truthy(alg_not_equal(alg_property(v_statement, "Superclass"), alg_nil()))) {
                    (void)(alg_invoke(v_parent, "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_statement, "Name"), "Lexeme")}, 1), f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_property(v_statement, "Superclass"), "Name"), "Lexeme")}, 1)}, 2));
                }
            }
            alg_root_top = rt_119;
        }
        alg_root_top = rt_118;
    }
    {
        int32_t rt_120 = alg_root_top;
        Value loop_76 = alg_iterable(alg_invoke(v_parent, "Keys", NULL, 0));
        (void)loop_76;
        alg_root(&loop_76, 1);
        for (int32_t at_76 = 0; at_76 < alg_iterable_count(loop_76); at_76++) {
            int32_t rt_121 = alg_root_top;
            Value v_name = alg_iterable_at(loop_76, at_76);
            (void)v_name;
            alg_root(&v_name, 1);
            {
                int32_t rt_122 = alg_root_top;
                Value v_seen = alg_set();
                (void)v_seen;
                alg_root(&v_seen, 1);
                Value v_at = alg_str(v_name);
                (void)v_at;
                alg_root(&v_at, 1);
                while (alg_truthy(alg_invoke(v_parent, "Contains", (Value[]){v_at}, 1))) {
                    {
                        if (alg_truthy(alg_invoke(v_seen, "Contains", (Value[]){v_at}, 1))) {
                            alg_raise(alg_string("A class can't inherit from itself."));
                        }
                        (void)(alg_invoke(v_seen, "Add", (Value[]){v_at}, 1));
                        (void)((v_at = alg_str(alg_invoke(v_parent, "Get", (Value[]){v_at}, 1))));
                    }
                }
                alg_root_top = rt_122;
            }
            alg_root_top = rt_121;
        }
        alg_root_top = rt_120;
    }
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
    if (alg_truthy(alg_not(alg_property(v_this, "Collected")))) {
        {
            (void)(alg_set_property(v_this, "Collected", alg_bool(true)));
            (void)(alg_invoke(v_this, "CollectDottable", (Value[]){v_statements}, 1));
            (void)(alg_invoke(v_this, "CollectExtensions", (Value[]){v_statements, alg_string("")}, 2));
            (void)(alg_invoke(v_this, "CheckDuplicates", (Value[]){v_statements}, 1));
            (void)(alg_invoke(v_this, "CheckInheritance", (Value[]){v_statements}, 1));
        }
    }
    (void)(alg_invoke(v_this, "PushLabels", (Value[]){v_statements}, 1));
    {
        int32_t rt_123 = alg_root_top;
        Value loop_78 = alg_iterable(v_statements);
        (void)loop_78;
        alg_root(&loop_78, 1);
        for (int32_t at_78 = 0; at_78 < alg_iterable_count(loop_78); at_78++) {
            int32_t rt_124 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_78, at_78);
            (void)v_statement;
            alg_root(&v_statement, 1);
            {
                (void)(alg_invoke(v_this, "Resolve", (Value[]){v_statement}, 1));
            }
            alg_root_top = rt_124;
        }
        alg_root_top = rt_123;
    }
    (void)(alg_invoke(v_this, "PopLabels", NULL, 0));
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
    Value v_found = alg_nil();
    (void)v_found;
    alg_root(&v_found, 1);
    (void)((v_found = alg_list()));
    {
        int32_t rt_125 = alg_root_top;
        Value loop_80 = alg_iterable(v_statements);
        (void)loop_80;
        alg_root(&loop_80, 1);
        for (int32_t at_80 = 0; at_80 < alg_iterable_count(loop_80); at_80++) {
            int32_t rt_126 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_80, at_80);
            (void)v_statement;
            alg_root(&v_statement, 1);
            if (alg_truthy(alg_is(v_statement, "LabelStmt"))) {
                (void)(alg_invoke(v_found, "Add", (Value[]){v_statement}, 1));
            }
            alg_root_top = rt_126;
        }
        alg_root_top = rt_125;
    }
    (void)(alg_invoke(alg_property(v_this, "LabelScopes"), "Add", (Value[]){v_found}, 1));
    Value ret_81 = alg_nil();
    alg_root_top = rt_base;
    return ret_81;
}

static Value m_resolver_poplabels_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_invoke(alg_property(v_this, "LabelScopes"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LabelScopes"), "Length"), alg_int(1))}, 1));
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
    {
        int32_t rt_127 = alg_root_top;
        Value v_s = alg_subtract(alg_property(alg_property(v_this, "LabelScopes"), "Length"), alg_int(1));
        (void)v_s;
        alg_root(&v_s, 1);
        for (; alg_truthy(alg_greater_equal(v_s, alg_int(0))); (v_s = alg_subtract(v_s, alg_int(1)))) {
            {
                int32_t rt_128 = alg_root_top;
                Value v_scope = alg_subscript_get(alg_property(v_this, "LabelScopes"), v_s);
                (void)v_scope;
                alg_root(&v_scope, 1);
                {
                    int32_t rt_129 = alg_root_top;
                    Value loop_83 = alg_iterable(v_scope);
                    (void)loop_83;
                    alg_root(&loop_83, 1);
                    for (int32_t at_83 = 0; at_83 < alg_iterable_count(loop_83); at_83++) {
                        int32_t rt_130 = alg_root_top;
                        Value v_each = alg_iterable_at(loop_83, at_83);
                        (void)v_each;
                        alg_root(&v_each, 1);
                        if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(v_each, "Name"), "Lexeme"))}, 1), f_foldcase(NULL, (Value[]){v_named}, 1)))) {
                            Value ret_84 = v_each;
                            alg_root_top = rt_base;
                            return ret_84;
                        }
                        alg_root_top = rt_130;
                    }
                    alg_root_top = rt_129;
                }
                alg_root_top = rt_128;
            }
        }
        alg_root_top = rt_127;
    }
    Value ret_85 = alg_nil();
    alg_root_top = rt_base;
    return ret_85;
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
    Value v_target = alg_nil();
    (void)v_target;
    alg_root(&v_target, 1);
    (void)((v_target = alg_invoke(v_this, "FindLabel", (Value[]){alg_property(v_stmt, "Label")}, 1)));
    if (alg_truthy(alg_equal(v_target, alg_nil()))) {
        alg_raise(alg_add(alg_add(alg_string("No label '"), alg_property(v_stmt, "Label")), alg_string("' is in scope.")));
    }
    (void)(alg_set_property(v_target, "Targeted", alg_bool(true)));
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
    (void)(alg_invoke(v_theexpr, "Accept", (Value[]){v_this}, 1));
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
    Value v_enclosingfunction = alg_nil();
    (void)v_enclosingfunction;
    alg_root(&v_enclosingfunction, 1);
    (void)((v_enclosingfunction = alg_property(v_this, "CurrentFunction")));
    (void)(alg_set_property(v_this, "CurrentFunction", v_typeoffunction));
    (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
    {
        int32_t rt_131 = alg_root_top;
        Value loop_89 = alg_iterable(alg_property(v_thefunction, "Params"));
        (void)loop_89;
        alg_root(&loop_89, 1);
        for (int32_t at_89 = 0; at_89 < alg_iterable_count(loop_89); at_89++) {
            int32_t rt_132 = alg_root_top;
            Value v_param = alg_iterable_at(loop_89, at_89);
            (void)v_param;
            alg_root(&v_param, 1);
            {
                (void)(alg_invoke(v_this, "Declare", (Value[]){v_param}, 1));
                (void)(alg_invoke(v_this, "Define", (Value[]){v_param}, 1));
            }
            alg_root_top = rt_132;
        }
        alg_root_top = rt_131;
    }
    Value v_enclosinglabels = alg_property(v_this, "LabelScopes");
    (void)v_enclosinglabels;
    alg_root(&v_enclosinglabels, 1);
    (void)(alg_set_property(v_this, "LabelScopes", alg_list()));
    (void)(alg_invoke(v_this, "ResolveAll", (Value[]){alg_property(v_thefunction, "Body")}, 1));
    (void)(alg_set_property(v_this, "LabelScopes", v_enclosinglabels));
    (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    (void)(alg_set_property(v_this, "CurrentFunction", v_enclosingfunction));
    Value ret_90 = alg_nil();
    alg_root_top = rt_base;
    return ret_90;
}

static Value m_resolver_beginscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_invoke(alg_property(v_this, "Scopes"), "Push", (Value[]){alg_map()}, 1));
    (void)(alg_invoke(alg_property(v_this, "Constants"), "Push", (Value[]){alg_map()}, 1));
    Value ret_91 = alg_nil();
    alg_root_top = rt_base;
    return ret_91;
}

static Value m_resolver_endscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_invoke(alg_property(v_this, "Scopes"), "Pop", NULL, 0));
    (void)(alg_invoke(alg_property(v_this, "Constants"), "Pop", NULL, 0));
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
    (void)(alg_invoke(v_this, "DeclareBinding", (Value[]){v_name, alg_bool(false)}, 2));
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
    Value v_scope = alg_nil();
    (void)v_scope;
    alg_root(&v_scope, 1);
    if (alg_truthy(alg_property(alg_property(v_this, "Scopes"), "IsEmpty"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "GlobalConstants"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_isconstant}, 2));
            Value ret_94 = alg_nil();
            alg_root_top = rt_base;
            return ret_94;
        }
    }
    (void)((v_scope = alg_cast(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0), "Map")));
    if (alg_truthy(alg_invoke(v_scope, "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
        {
            alg_raise(alg_string("Already a variable with this name in this scope."));
        }
    }
    (void)(alg_invoke(v_scope, "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), alg_bool(false)}, 2));
    (void)(alg_invoke(alg_invoke(alg_property(v_this, "Constants"), "Peek", NULL, 0), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_isconstant}, 2));
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
    Value v_lexeme = alg_nil();
    (void)v_lexeme;
    alg_root(&v_lexeme, 1);
    (void)((v_lexeme = alg_str(alg_property(v_name, "Lexeme"))));
    {
        int32_t rt_133 = alg_root_top;
        Value v_i = alg_subtract(alg_property(alg_property(v_this, "Constants"), "Length"), alg_int(1));
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_greater_equal(v_i, alg_int(0))); (v_i = alg_subtract(v_i, alg_int(1)))) {
            if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Constants"), v_i), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_lexeme}, 1)}, 1))) {
                Value ret_96 = alg_invoke(alg_subscript_get(alg_property(v_this, "Constants"), v_i), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_lexeme}, 1)}, 1);
                alg_root_top = rt_base;
                return ret_96;
            }
        }
        alg_root_top = rt_133;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "GlobalConstants"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_lexeme}, 1)}, 1))) {
        Value ret_97 = alg_invoke(alg_property(v_this, "GlobalConstants"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_lexeme}, 1)}, 1);
        alg_root_top = rt_base;
        return ret_97;
    }
    Value ret_98 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_98;
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
    Value v_scope = alg_nil();
    (void)v_scope;
    alg_root(&v_scope, 1);
    if (alg_truthy(alg_property(alg_property(v_this, "Scopes"), "IsEmpty"))) {
        Value ret_100 = alg_nil();
        alg_root_top = rt_base;
        return ret_100;
    }
    (void)((v_scope = alg_cast(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0), "Map")));
    (void)(alg_invoke(v_scope, "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), alg_bool(true)}, 2));
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
    {
        int32_t rt_134 = alg_root_top;
        Value v_i = alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1));
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_greater_equal(v_i, alg_int(0))); (v_i = alg_subtract(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), v_i), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "TheInterpreter"), "Resolve", (Value[]){v_theexpr, alg_subtract(alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1)), v_i)}, 2));
                        Value ret_102 = alg_nil();
                        alg_root_top = rt_base;
                        return ret_102;
                    }
                }
            }
        }
        alg_root_top = rt_134;
    }
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
    alg_class_field(k_resolver, "TheInterpreter");
    alg_class_field(k_resolver, "Scopes");
    alg_class_field(k_resolver, "Constants");
    alg_class_field(k_resolver, "GlobalConstants");
    alg_class_field(k_resolver, "CurrentFunction");
    alg_class_field(k_resolver, "CurrentClass");
    alg_class_field(k_resolver, "Units");
    alg_class_field(k_resolver, "Dottable");
    alg_class_field(k_resolver, "Extensions");
    alg_class_field(k_resolver, "Exported");
    alg_class_field(k_resolver, "Collected");
    alg_class_field(k_resolver, "LabelScopes");
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
}
