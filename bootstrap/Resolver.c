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
static const char *t_resolver_init_1_interpreter[] = { "Interpreter" };
static const char *t_resolver_collectdottable_1_list[] = { "List" };
static const char *t_resolver_isunitqualifier_1[] = { "Any" };
static const char *t_resolver_visitblockstmt_1_blockstmt[] = { "BlockStmt" };
static const char *t_resolver_visitclassstmt_1_classstmt[] = { "ClassStmt" };
static const char *t_resolver_visitobjectstmt_1_objectstmt[] = { "ObjectStmt" };
static const char *t_resolver_visitenumstmt_1_enumstmt[] = { "EnumStmt" };
static const char *t_resolver_visitexpressionstmt_1_expressionstmt[] = { "ExpressionStmt" };
static const char *t_resolver_visitifstmt_1_ifstmt[] = { "IfStmt" };
static const char *t_resolver_visittrystmt_1_trystmt[] = { "TryStmt" };
static const char *t_resolver_visitmodulestmt_1_modulestmt[] = { "ModuleStmt" };
static const char *t_resolver_visitforinstmt_1_forinstmt[] = { "ForInStmt" };
static const char *t_resolver_visitbreakstmt_1_breakstmt[] = { "BreakStmt" };
static const char *t_resolver_visitraisestmt_1_raisestmt[] = { "RaiseStmt" };
static const char *t_resolver_visitreturnstmt_1_returnstmt[] = { "ReturnStmt" };
static const char *t_resolver_visitwhilestmt_1_whilestmt[] = { "WhileStmt" };
static const char *t_resolver_visitfunctionstmt_1_functionstmt[] = { "FunctionStmt" };
static const char *t_resolver_visitvarstmt_1_varstmt[] = { "VarStmt" };
static const char *t_resolver_visitvargroupstmt_1_vargroupstmt[] = { "VarGroupStmt" };
static const char *t_resolver_visitassignexpr_1_assignexpr[] = { "AssignExpr" };
static const char *t_resolver_visitbinary_1_binaryexpr[] = { "BinaryExpr" };
static const char *t_resolver_visitlogical_1_logicalexpr[] = { "LogicalExpr" };
static const char *t_resolver_visitunary_1_unaryexpr[] = { "UnaryExpr" };
static const char *t_resolver_visitcall_1_callexpr[] = { "CallExpr" };
static const char *t_resolver_visitgetexpr_1_getexpr[] = { "GetExpr" };
static const char *t_resolver_visitsetexpr_1_setexpr[] = { "SetExpr" };
static const char *t_resolver_visitsuperexpr_1_superexpr[] = { "SuperExpr" };
static const char *t_resolver_visitthisexpr_1_thisexpr[] = { "ThisExpr" };
static const char *t_resolver_visitisexpr_1_isexpr[] = { "IsExpr" };
static const char *t_resolver_visitgrouping_1_groupingexpr[] = { "GroupingExpr" };
static const char *t_resolver_visitsubscriptexpr_1_subscriptexpr[] = { "SubscriptExpr" };
static const char *t_resolver_visitsetsubscriptexpr_1_setsubscriptexpr[] = { "SetSubscriptExpr" };
static const char *t_resolver_visitcollectionexpr_1_collectionexpr[] = { "CollectionExpr" };
static const char *t_resolver_visitliteral_1_literalexpr[] = { "LiteralExpr" };
static const char *t_resolver_visitvariableexpr_1_variableexpr[] = { "VariableExpr" };
static const char *t_resolver_checkduplicates_1_list[] = { "List" };
static const char *t_resolver_signatureof_1[] = { "Any" };
static const char *t_resolver_checkinheritance_1_list[] = { "List" };
static const char *t_resolver_resolveall_1_list[] = { "List" };
static const char *t_resolver_resolve_1[] = { "Any" };
static const char *t_resolver_resolvefunction_2_functionstmt_functiontype[] = { "FunctionStmt", "FunctionType" };
static const char *t_resolver_declare_1_token[] = { "Token" };
static const char *t_resolver_declarebinding_2_token_boolean[] = { "Token", "Boolean" };
static const char *t_resolver_isconstant_1_token[] = { "Token" };
static const char *t_resolver_define_1_token[] = { "Token" };
static const char *t_resolver_resolvelocal_2_expr_token[] = { "Expr", "Token" };

static Value i_resolver(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "TheInterpreter", alg_nil());
    alg_set_property(v_this, "Scopes", alg_nil());
    alg_set_property(v_this, "Constants", alg_nil());
    alg_set_property(v_this, "GlobalConstants", alg_nil());
    alg_set_property(v_this, "CurrentFunction", alg_nil());
    alg_set_property(v_this, "CurrentClass", alg_nil());
    alg_set_property(v_this, "Units", alg_nil());
    alg_set_property(v_this, "Dottable", alg_nil());
    alg_set_property(v_this, "Collected", alg_bool(false));
    return alg_nil();
}

static Value m_resolver_init_1_interpreter(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    (void)(alg_set_property(v_this, "TheInterpreter", v_theinterpreter));
    (void)(alg_set_property(v_this, "Scopes", alg_stack()));
    (void)(alg_set_property(v_this, "Constants", alg_stack()));
    (void)(alg_set_property(v_this, "GlobalConstants", alg_map()));
    (void)(alg_set_property(v_this, "CurrentFunction", e_functiontype_funVnone));
    (void)(alg_set_property(v_this, "CurrentClass", e_classtype_classVnone));
    (void)(alg_set_property(v_this, "Units", alg_set()));
    (void)(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){alg_string("system")}, 1));
    (void)(alg_set_property(v_this, "Dottable", alg_set()));
    return alg_nil();
}

static Value m_resolver_collectdottable_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = args[0];
    (void)v_statements;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_statements, "Length")))) {
            {
                {
                    Value v_thestmt = alg_subscript_get(v_statements, v_i);
                    (void)v_thestmt;
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
                            Value v_j = alg_int(0);
                            (void)v_j;
                            while (alg_truthy(alg_less(v_j, alg_property(alg_property(v_thestmt, "Names"), "Length")))) {
                                {
                                    (void)(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_subscript_get(alg_property(v_thestmt, "Names"), v_j), "Lexeme")}, 1)}, 1));
                                    (void)((v_j = alg_add(v_j, alg_int(1))));
                                }
                            }
                        }
                    }
                    if (alg_truthy((or_0 = alg_is(v_thestmt, "ModuleStmt"), !alg_truthy(or_0) ? or_0 : alg_not_equal(alg_property(v_thestmt, "Statements"), alg_nil())))) {
                        (void)(alg_invoke(v_this, "CollectDottable", (Value[]){alg_property(v_thestmt, "Statements")}, 1));
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_resolver_isunitqualifier_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_obj = args[0];
    (void)v_obj;
    if (alg_truthy(alg_not((alg_is(v_obj, "VariableExpr"))))) {
        return alg_bool(false);
    }
    Value v_name = alg_str(alg_property(alg_property(v_obj, "Name"), "Lexeme"));
    (void)v_name;
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Units"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1)))) {
        return alg_bool(false);
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Dottable"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
        return alg_bool(false);
    }
    {
        Value v_i = alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1));
        (void)v_i;
        while (alg_truthy(alg_greater_equal(v_i, alg_int(0)))) {
            {
                if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), v_i), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
                    return alg_bool(false);
                }
                (void)((v_i = alg_subtract(v_i, alg_int(1))));
            }
        }
    }
    return alg_bool(true);
    return alg_nil();
}

static Value m_resolver_visitblockstmt_1_blockstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
    (void)(alg_invoke(v_this, "ResolveAll", (Value[]){alg_property(v_stmt, "Statements")}, 1));
    (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    return alg_nil();
}

static Value m_resolver_visitclassstmt_1_classstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    Value v_enclosingclass = alg_nil();
    (void)v_enclosingclass;
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
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_stmt, "Methods"), "Length")))) {
            {
                {
                    Value v_declaration = e_functiontype_funVfunction;
                    (void)v_declaration;
                    if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_subscript_get(alg_property(v_stmt, "Methods"), v_i), "Name"), "Lexeme")}, 1), alg_string("init")))) {
                        {
                            (void)((v_declaration = e_functiontype_funVinitializer));
                        }
                    }
                    (void)(alg_invoke(v_this, "ResolveFunction", (Value[]){alg_subscript_get(alg_property(v_stmt, "Methods"), v_i), v_declaration}, 2));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    if (alg_truthy(alg_not_equal(alg_property(v_stmt, "Superclass"), alg_nil()))) {
        (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    }
    (void)(alg_set_property(v_this, "CurrentClass", v_enclosingclass));
    return alg_nil();
}

static Value m_resolver_visitobjectstmt_1_objectstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    (void)(alg_invoke(v_this, "VisitClassStmt", (Value[]){alg_new(k_classstmt, (Value[]){alg_property(v_stmt, "Name"), alg_property(v_stmt, "Superclass"), alg_property(v_stmt, "Methods"), alg_property(v_stmt, "Fields")}, 4)}, 1));
    return alg_nil();
}

static Value m_resolver_visitenumstmt_1_enumstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_stmt, "Name")}, 1));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_stmt, "Members"), "Length")))) {
            {
                {
                    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_subscript_get(alg_property(v_stmt, "Members"), v_i)}, 1));
                    (void)(alg_invoke(v_this, "Define", (Value[]){alg_subscript_get(alg_property(v_stmt, "Members"), v_i)}, 1));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_resolver_visitexpressionstmt_1_expressionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Expression")}, 1));
    return alg_nil();
}

static Value m_resolver_visitifstmt_1_ifstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Condition")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "ThenBranch")}, 1));
    if (alg_truthy((alg_not_equal(alg_property(v_stmt, "ElseBranch"), alg_nil())))) {
        (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "ElseBranch")}, 1));
    }
    return alg_nil();
}

static Value m_resolver_visittrystmt_1_trystmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    Value v_keys = alg_nil();
    (void)v_keys;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "TryBlock")}, 1));
    (void)((v_keys = alg_invoke(alg_property(v_stmt, "Handlers"), "Keys", NULL, 0)));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_keys, "Length")))) {
            {
                (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(alg_invoke(alg_property(v_stmt, "Handlers"), "Get", (Value[]){alg_subscript_get(v_keys, v_i)}, 1), "Body")}, 1));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_resolver_visitmodulestmt_1_modulestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    Value v_enclosing = alg_nil();
    (void)v_enclosing;
    if (alg_truthy(alg_equal(alg_property(v_stmt, "Statements"), alg_nil()))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_stmt, "UnitName")}, 1)}, 1));
            return alg_nil();
        }
    }
    (void)((v_enclosing = alg_property(v_this, "Units")));
    (void)(alg_set_property(v_this, "Units", alg_set()));
    (void)(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){alg_string("system")}, 1));
    (void)(alg_invoke(v_this, "ResolveAll", (Value[]){alg_property(v_stmt, "Statements")}, 1));
    (void)(alg_set_property(v_this, "Units", v_enclosing));
    (void)(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_stmt, "UnitName")}, 1)}, 1));
    return alg_nil();
}

static Value m_resolver_visitforinstmt_1_forinstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Iterable")}, 1));
    (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Body")}, 1));
    (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    return alg_nil();
}

static Value m_resolver_visitbreakstmt_1_breakstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    return alg_nil();
}

static Value m_resolver_visitraisestmt_1_raisestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Value")}, 1));
    return alg_nil();
}

static Value m_resolver_visitreturnstmt_1_returnstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
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
    return alg_nil();
}

static Value m_resolver_visitwhilestmt_1_whilestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Condition")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Body")}, 1));
    return alg_nil();
}

static Value m_resolver_visitfunctionstmt_1_functionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "ResolveFunction", (Value[]){v_stmt, e_functiontype_funVfunction}, 2));
    return alg_nil();
}

static Value m_resolver_visitvarstmt_1_varstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    (void)(alg_invoke(v_this, "DeclareBinding", (Value[]){alg_property(v_stmt, "Name"), alg_property(v_stmt, "IsConstant")}, 2));
    if (alg_truthy((alg_not_equal(alg_property(v_stmt, "Initializer"), alg_nil())))) {
        {
            (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Initializer")}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_stmt, "Name")}, 1));
    return alg_nil();
}

static Value m_resolver_visitvargroupstmt_1_vargroupstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_stmt = args[0];
    (void)v_stmt;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_stmt, "Names"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "DeclareBinding", (Value[]){alg_subscript_get(alg_property(v_stmt, "Names"), v_i), alg_property(v_stmt, "IsConstant")}, 2));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_stmt, "Initializer"), alg_nil()))) {
        (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_stmt, "Initializer")}, 1));
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_stmt, "Names"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "Define", (Value[]){alg_subscript_get(alg_property(v_stmt, "Names"), v_i)}, 1));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_resolver_visitassignexpr_1_assignexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    if (alg_truthy(alg_invoke(v_this, "IsConstant", (Value[]){alg_property(v_theexpr, "Name")}, 1))) {
        alg_raise(alg_add(alg_add(alg_string("Can't assign to constant '"), alg_property(alg_property(v_theexpr, "Name"), "Lexeme")), alg_string("'.")));
    }
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Value")}, 1));
    (void)(alg_invoke(v_this, "ResolveLocal", (Value[]){v_theexpr, alg_property(v_theexpr, "Name")}, 2));
    return alg_nil();
}

static Value m_resolver_visitbinary_1_binaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Left")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Right")}, 1));
    return alg_nil();
}

static Value m_resolver_visitlogical_1_logicalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Left")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Right")}, 1));
    return alg_nil();
}

static Value m_resolver_visitunary_1_unaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Right")}, 1));
    return alg_nil();
}

static Value m_resolver_visitcall_1_callexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Callee")}, 1));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Arguments"), "Length")))) {
            {
                {
                    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Arguments"), v_i)}, 1));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_resolver_visitgetexpr_1_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    if (alg_truthy(alg_invoke(v_this, "IsUnitQualifier", (Value[]){alg_property(v_theexpr, "Obj")}, 1))) {
        {
            (void)(alg_set_property(v_theexpr, "Unit", alg_str(alg_property(alg_property(alg_property(v_theexpr, "Obj"), "Name"), "Lexeme"))));
            return alg_nil();
        }
    }
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
    return alg_nil();
}

static Value m_resolver_visitsetexpr_1_setexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    if (alg_truthy(alg_invoke(v_this, "IsUnitQualifier", (Value[]){alg_property(v_theexpr, "Obj")}, 1))) {
        {
            (void)(alg_set_property(v_theexpr, "Unit", alg_str(alg_property(alg_property(alg_property(v_theexpr, "Obj"), "Name"), "Lexeme"))));
            (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Value")}, 1));
            return alg_nil();
        }
    }
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Value")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
    return alg_nil();
}

static Value m_resolver_visitsuperexpr_1_superexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    if (alg_truthy(alg_equal(alg_property(v_this, "CurrentClass"), e_classtype_classVnone))) {
        alg_raise(alg_string("Can't use 'super' outside a class."));
    } else {
        if (alg_truthy(alg_not_equal(alg_property(v_this, "CurrentClass"), e_classtype_classVsubclass))) {
            alg_raise(alg_string("Can't use 'super' in a class with no superclass."));
        }
    }
    (void)(alg_invoke(v_this, "ResolveLocal", (Value[]){v_theexpr, alg_property(v_theexpr, "Keyword")}, 2));
    return alg_nil();
}

static Value m_resolver_visitthisexpr_1_thisexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    if (alg_truthy(alg_equal(alg_property(v_this, "CurrentClass"), e_classtype_classVnone))) {
        {
            alg_raise(alg_string("Can't use 'this' outside a class."));
        }
    }
    (void)(alg_invoke(v_this, "ResolveLocal", (Value[]){v_theexpr, alg_property(v_theexpr, "Keyword")}, 2));
    return alg_nil();
}

static Value m_resolver_visitisexpr_1_isexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
    return alg_nil();
}

static Value m_resolver_visitgrouping_1_groupingexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Expression")}, 1));
    return alg_nil();
}

static Value m_resolver_visitsubscriptexpr_1_subscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Index")}, 1));
    return alg_nil();
}

static Value m_resolver_visitsetsubscriptexpr_1_setsubscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Index")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_theexpr, "Value")}, 1));
    return alg_nil();
}

static Value m_resolver_visitcollectionexpr_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Keys"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Keys"), v_i)}, 1));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Values"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Values"), v_i)}, 1));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_resolver_visitliteral_1_literalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    return alg_nil();
}

static Value m_resolver_visitvariableexpr_1_variableexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    if (alg_truthy((or_2 = alg_not(alg_property(alg_property(v_this, "Scopes"), "IsEmpty")), !alg_truthy(or_2) ? or_2 : alg_equal(alg_invoke(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1)}, 1), alg_bool(false))))) {
        {
            alg_raise(alg_string("Can't read local variable in its own initializer."));
        }
    }
    (void)(alg_invoke(v_this, "ResolveLocal", (Value[]){v_theexpr, alg_property(v_theexpr, "Name")}, 2));
    return alg_nil();
}

static Value m_resolver_checkduplicates_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = args[0];
    (void)v_statements;
    Value v_seen = alg_nil();
    (void)v_seen;
    Value v_memberowner = alg_nil();
    (void)v_memberowner;
    Value v_signatures = alg_nil();
    (void)v_signatures;
    (void)((v_seen = alg_set()));
    (void)((v_memberowner = alg_map()));
    (void)((v_signatures = alg_map()));
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
                            if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Statements"), alg_nil()))) {
                                (void)(alg_invoke(v_this, "CheckDuplicates", (Value[]){alg_property(v_thestmt, "Statements")}, 1));
                            }
                        }
                    } else {
                        {
                            Value v_thename = alg_string("");
                            (void)v_thename;
                            Value v_written = alg_string("");
                            (void)v_written;
                            if (alg_truthy(alg_is(v_thestmt, "FunctionStmt"))) {
                                {
                                    Value v_fnname = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1);
                                    (void)v_fnname;
                                    Value v_signature = alg_invoke(v_this, "SignatureOf", (Value[]){v_thestmt}, 1);
                                    (void)v_signature;
                                    if (alg_truthy((or_3 = alg_invoke(v_seen, "Contains", (Value[]){v_fnname}, 1), alg_truthy(or_3) ? or_3 : alg_invoke(v_memberowner, "Contains", (Value[]){v_fnname}, 1)))) {
                                        alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))), alg_string("' is already defined.")));
                                    }
                                    if (alg_truthy(alg_not(alg_invoke(v_signatures, "Contains", (Value[]){v_fnname}, 1)))) {
                                        (void)(alg_invoke(v_signatures, "Put", (Value[]){v_fnname, alg_list()}, 2));
                                    }
                                    Value v_taken = alg_invoke(v_signatures, "Get", (Value[]){v_fnname}, 1);
                                    (void)v_taken;
                                    {
                                        Value v_j = alg_int(0);
                                        (void)v_j;
                                        while (alg_truthy(alg_less(v_j, alg_property(v_taken, "Length")))) {
                                            {
                                                if (alg_truthy(alg_equal(alg_str(alg_subscript_get(v_taken, v_j)), v_signature))) {
                                                    alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))), alg_string("' is already defined.")));
                                                }
                                                (void)((v_j = alg_add(v_j, alg_int(1))));
                                            }
                                        }
                                    }
                                    (void)(alg_invoke(v_taken, "Add", (Value[]){v_signature}, 1));
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
                            if (alg_truthy(alg_not_equal(v_thename, alg_string("")))) {
                                (void)((v_written = alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))));
                            }
                            if (alg_truthy(alg_is(v_thestmt, "EnumStmt"))) {
                                {
                                    Value v_owner = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1);
                                    (void)v_owner;
                                    {
                                        Value v_j = alg_int(0);
                                        (void)v_j;
                                        while (alg_truthy(alg_less(v_j, alg_property(alg_property(v_thestmt, "Members"), "Length")))) {
                                            {
                                                {
                                                    Value v_member = f_foldcase(NULL, (Value[]){alg_property(alg_subscript_get(alg_property(v_thestmt, "Members"), v_j), "Lexeme")}, 1);
                                                    (void)v_member;
                                                    Value v_aswritten = alg_str(alg_property(alg_subscript_get(alg_property(v_thestmt, "Members"), v_j), "Lexeme"));
                                                    (void)v_aswritten;
                                                    if (alg_truthy(alg_invoke(v_seen, "Contains", (Value[]){v_member}, 1))) {
                                                        alg_raise(alg_add(alg_add(alg_char_value(39), v_aswritten), alg_string("' is already defined.")));
                                                    }
                                                    if (alg_truthy(alg_invoke(v_memberowner, "Contains", (Value[]){v_member}, 1))) {
                                                        if (alg_truthy(alg_equal(alg_str(alg_invoke(v_memberowner, "Get", (Value[]){v_member}, 1)), v_owner))) {
                                                            alg_raise(alg_add(alg_add(alg_char_value(39), v_aswritten), alg_string("' is already defined.")));
                                                        }
                                                    }
                                                    (void)(alg_invoke(v_memberowner, "Put", (Value[]){v_member, v_owner}, 2));
                                                }
                                                (void)((v_j = alg_add(v_j, alg_int(1))));
                                            }
                                        }
                                    }
                                    (void)((v_thename = f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)));
                                    (void)((v_written = alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))));
                                }
                            }
                            if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                                {
                                    Value v_j = alg_int(0);
                                    (void)v_j;
                                    while (alg_truthy(alg_less(v_j, alg_property(alg_property(v_thestmt, "Names"), "Length")))) {
                                        {
                                            {
                                                Value v_each = f_foldcase(NULL, (Value[]){alg_property(alg_subscript_get(alg_property(v_thestmt, "Names"), v_j), "Lexeme")}, 1);
                                                (void)v_each;
                                                if (alg_truthy(alg_invoke(v_seen, "Contains", (Value[]){v_each}, 1))) {
                                                    alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_subscript_get(alg_property(v_thestmt, "Names"), v_j), "Lexeme"))), alg_string("' is already defined.")));
                                                }
                                                if (alg_truthy(alg_invoke(v_memberowner, "Contains", (Value[]){v_each}, 1))) {
                                                    alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_subscript_get(alg_property(v_thestmt, "Names"), v_j), "Lexeme"))), alg_string("' is already defined.")));
                                                }
                                                if (alg_truthy(alg_invoke(v_signatures, "Contains", (Value[]){v_each}, 1))) {
                                                    alg_raise(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_subscript_get(alg_property(v_thestmt, "Names"), v_j), "Lexeme"))), alg_string("' is already defined.")));
                                                }
                                                (void)(alg_invoke(v_seen, "Add", (Value[]){v_each}, 1));
                                            }
                                            (void)((v_j = alg_add(v_j, alg_int(1))));
                                        }
                                    }
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
                        }
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_resolver_signatureof_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = args[0];
    (void)v_thestmt;
    Value v_text = alg_nil();
    (void)v_text;
    (void)((v_text = alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Params"), "Length")))) {
            {
                {
                    Value v_declared = alg_str(alg_subscript_get(alg_property(v_thestmt, "ParamTypes"), v_i));
                    (void)v_declared;
                    if (alg_truthy(alg_equal(v_declared, alg_string("")))) {
                        (void)((v_declared = alg_string("Any")));
                    }
                    (void)((v_text = alg_add(alg_add(v_text, alg_char_value(47)), f_foldcase(NULL, (Value[]){v_declared}, 1))));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return v_text;
    return alg_nil();
}

static Value m_resolver_checkinheritance_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = args[0];
    (void)v_statements;
    Value v_parent = alg_nil();
    (void)v_parent;
    (void)((v_parent = alg_map()));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_statements, "Length")))) {
            {
                if (alg_truthy(alg_is(alg_subscript_get(v_statements, v_i), "ClassStmt"))) {
                    if (alg_truthy(alg_not_equal(alg_property(alg_subscript_get(v_statements, v_i), "Superclass"), alg_nil()))) {
                        (void)(alg_invoke(v_parent, "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Name"), "Lexeme")}, 1), f_foldcase(NULL, (Value[]){alg_property(alg_property(alg_property(alg_subscript_get(v_statements, v_i), "Superclass"), "Name"), "Lexeme")}, 1)}, 2));
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    {
        Value loop_0 = alg_iterable(alg_invoke(v_parent, "Keys", NULL, 0));
        for (int32_t at_0 = 0; at_0 < alg_iterable_count(loop_0); at_0++) {
            Value v_name = alg_iterable_at(loop_0, at_0);
            (void)v_name;
            {
                Value v_seen = alg_set();
                (void)v_seen;
                Value v_at = alg_str(v_name);
                (void)v_at;
                while (alg_truthy(alg_invoke(v_parent, "Contains", (Value[]){v_at}, 1))) {
                    {
                        if (alg_truthy(alg_invoke(v_seen, "Contains", (Value[]){v_at}, 1))) {
                            alg_raise(alg_string("A class can't inherit from itself."));
                        }
                        (void)(alg_invoke(v_seen, "Add", (Value[]){v_at}, 1));
                        (void)((v_at = alg_str(alg_invoke(v_parent, "Get", (Value[]){v_at}, 1))));
                    }
                }
            }
        }
    }
    return alg_nil();
}

static Value m_resolver_resolveall_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = args[0];
    (void)v_statements;
    if (alg_truthy(alg_not(alg_property(v_this, "Collected")))) {
        {
            (void)(alg_set_property(v_this, "Collected", alg_bool(true)));
            (void)(alg_invoke(v_this, "CollectDottable", (Value[]){v_statements}, 1));
            (void)(alg_invoke(v_this, "CheckDuplicates", (Value[]){v_statements}, 1));
            (void)(alg_invoke(v_this, "CheckInheritance", (Value[]){v_statements}, 1));
        }
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_statements, "Length")))) {
            {
                {
                    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_subscript_get(v_statements, v_i)}, 1));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_resolver_resolve_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    (void)(alg_invoke(v_theexpr, "Accept", (Value[]){v_this}, 1));
    return alg_nil();
}

static Value m_resolver_resolvefunction_2_functionstmt_functiontype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thefunction = args[0];
    (void)v_thefunction;
    Value v_typeoffunction = args[1];
    (void)v_typeoffunction;
    Value v_enclosingfunction = alg_nil();
    (void)v_enclosingfunction;
    (void)((v_enclosingfunction = alg_property(v_this, "CurrentFunction")));
    (void)(alg_set_property(v_this, "CurrentFunction", v_typeoffunction));
    (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_thefunction, "Params"), "Length")))) {
            {
                {
                    Value v_param = alg_subscript_get(alg_property(v_thefunction, "Params"), v_i);
                    (void)v_param;
                    (void)(alg_invoke(v_this, "Declare", (Value[]){v_param}, 1));
                    (void)(alg_invoke(v_this, "Define", (Value[]){v_param}, 1));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "ResolveAll", (Value[]){alg_property(v_thefunction, "Body")}, 1));
    (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    (void)(alg_set_property(v_this, "CurrentFunction", v_enclosingfunction));
    return alg_nil();
}

static Value m_resolver_beginscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_invoke(alg_property(v_this, "Scopes"), "Push", (Value[]){alg_map()}, 1));
    (void)(alg_invoke(alg_property(v_this, "Constants"), "Push", (Value[]){alg_map()}, 1));
    return alg_nil();
}

static Value m_resolver_endscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_invoke(alg_property(v_this, "Scopes"), "Pop", NULL, 0));
    (void)(alg_invoke(alg_property(v_this, "Constants"), "Pop", NULL, 0));
    return alg_nil();
}

static Value m_resolver_declare_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = args[0];
    (void)v_name;
    (void)(alg_invoke(v_this, "DeclareBinding", (Value[]){v_name, alg_bool(false)}, 2));
    return alg_nil();
}

static Value m_resolver_declarebinding_2_token_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = args[0];
    (void)v_name;
    Value v_isconstant = args[1];
    (void)v_isconstant;
    Value v_scope = alg_nil();
    (void)v_scope;
    if (alg_truthy(alg_property(alg_property(v_this, "Scopes"), "IsEmpty"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "GlobalConstants"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_isconstant}, 2));
            return alg_nil();
        }
    }
    (void)((v_scope = alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0)));
    if (alg_truthy(alg_invoke(v_scope, "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
        {
            alg_raise(alg_string("Already a variable with this name in this scope."));
        }
    }
    (void)(alg_invoke(v_scope, "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), alg_bool(false)}, 2));
    (void)(alg_invoke(alg_invoke(alg_property(v_this, "Constants"), "Peek", NULL, 0), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_isconstant}, 2));
    return alg_nil();
}

static Value m_resolver_isconstant_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = args[0];
    (void)v_name;
    Value v_lexeme = alg_nil();
    (void)v_lexeme;
    (void)((v_lexeme = alg_str(alg_property(v_name, "Lexeme"))));
    {
        Value v_i = alg_subtract(alg_property(alg_property(v_this, "Constants"), "Length"), alg_int(1));
        (void)v_i;
        while (alg_truthy(alg_greater_equal(v_i, alg_int(0)))) {
            {
                if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Constants"), v_i), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_lexeme}, 1)}, 1))) {
                    return alg_invoke(alg_subscript_get(alg_property(v_this, "Constants"), v_i), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_lexeme}, 1)}, 1);
                }
                (void)((v_i = alg_subtract(v_i, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "GlobalConstants"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_lexeme}, 1)}, 1))) {
        return alg_invoke(alg_property(v_this, "GlobalConstants"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_lexeme}, 1)}, 1);
    }
    return alg_bool(false);
    return alg_nil();
}

static Value m_resolver_define_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = args[0];
    (void)v_name;
    Value v_scope = alg_nil();
    (void)v_scope;
    if (alg_truthy(alg_property(alg_property(v_this, "Scopes"), "IsEmpty"))) {
        return alg_nil();
    }
    (void)((v_scope = alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0)));
    (void)(alg_invoke(v_scope, "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), alg_bool(true)}, 2));
    return alg_nil();
}

static Value m_resolver_resolvelocal_2_expr_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    Value v_name = args[1];
    (void)v_name;
    {
        Value v_i = alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1));
        (void)v_i;
        while (alg_truthy(alg_greater_equal(v_i, alg_int(0)))) {
            {
                {
                    if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), v_i), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
                        {
                            (void)(alg_invoke(alg_property(v_this, "TheInterpreter"), "Resolve", (Value[]){v_theexpr, alg_subtract(alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1)), v_i)}, 2));
                            return alg_nil();
                        }
                    }
                }
                (void)((v_i = alg_subtract(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

void init_Resolver(void) {
    e_functiontype = alg_enum_type("FunctionType");
    e_functiontype_funVnone = alg_enum_member(e_functiontype, "FUN_NONE");
    e_functiontype_funVfunction = alg_enum_member(e_functiontype, "FUN_FUNCTION");
    e_functiontype_funVmethod = alg_enum_member(e_functiontype, "FUN_METHOD");
    e_functiontype_funVinitializer = alg_enum_member(e_functiontype, "FUN_INITIALIZER");
    e_classtype = alg_enum_type("ClassType");
    e_classtype_classVnone = alg_enum_member(e_classtype, "CLASS_NONE");
    e_classtype_classVclass = alg_enum_member(e_classtype, "CLASS_CLASS");
    e_classtype_classVsubclass = alg_enum_member(e_classtype, "CLASS_SUBCLASS");
    k_resolver = alg_class("Resolver", alg_nil());
    alg_class_field(k_resolver, "TheInterpreter");
    alg_class_field(k_resolver, "Scopes");
    alg_class_field(k_resolver, "Constants");
    alg_class_field(k_resolver, "GlobalConstants");
    alg_class_field(k_resolver, "CurrentFunction");
    alg_class_field(k_resolver, "CurrentClass");
    alg_class_field(k_resolver, "Units");
    alg_class_field(k_resolver, "Dottable");
    alg_class_field(k_resolver, "Collected");
    alg_class_initializer(k_resolver, i_resolver);
    alg_class_method(k_resolver, "Init", m_resolver_init_1_interpreter, 1, t_resolver_init_1_interpreter);
    alg_class_method(k_resolver, "CollectDottable", m_resolver_collectdottable_1_list, 1, t_resolver_collectdottable_1_list);
    alg_class_method(k_resolver, "IsUnitQualifier", m_resolver_isunitqualifier_1, 1, t_resolver_isunitqualifier_1);
    alg_class_method(k_resolver, "VisitBlockStmt", m_resolver_visitblockstmt_1_blockstmt, 1, t_resolver_visitblockstmt_1_blockstmt);
    alg_class_method(k_resolver, "VisitClassStmt", m_resolver_visitclassstmt_1_classstmt, 1, t_resolver_visitclassstmt_1_classstmt);
    alg_class_method(k_resolver, "VisitObjectStmt", m_resolver_visitobjectstmt_1_objectstmt, 1, t_resolver_visitobjectstmt_1_objectstmt);
    alg_class_method(k_resolver, "VisitEnumStmt", m_resolver_visitenumstmt_1_enumstmt, 1, t_resolver_visitenumstmt_1_enumstmt);
    alg_class_method(k_resolver, "VisitExpressionStmt", m_resolver_visitexpressionstmt_1_expressionstmt, 1, t_resolver_visitexpressionstmt_1_expressionstmt);
    alg_class_method(k_resolver, "VisitIfStmt", m_resolver_visitifstmt_1_ifstmt, 1, t_resolver_visitifstmt_1_ifstmt);
    alg_class_method(k_resolver, "VisitTryStmt", m_resolver_visittrystmt_1_trystmt, 1, t_resolver_visittrystmt_1_trystmt);
    alg_class_method(k_resolver, "VisitModuleStmt", m_resolver_visitmodulestmt_1_modulestmt, 1, t_resolver_visitmodulestmt_1_modulestmt);
    alg_class_method(k_resolver, "VisitForInStmt", m_resolver_visitforinstmt_1_forinstmt, 1, t_resolver_visitforinstmt_1_forinstmt);
    alg_class_method(k_resolver, "VisitBreakStmt", m_resolver_visitbreakstmt_1_breakstmt, 1, t_resolver_visitbreakstmt_1_breakstmt);
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
    alg_class_method(k_resolver, "CheckInheritance", m_resolver_checkinheritance_1_list, 1, t_resolver_checkinheritance_1_list);
    alg_class_method(k_resolver, "ResolveAll", m_resolver_resolveall_1_list, 1, t_resolver_resolveall_1_list);
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
