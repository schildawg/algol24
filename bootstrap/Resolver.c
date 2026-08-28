/* Generated from Algol-24.  Do not edit. */
#include "Resolver.h"
#include "Expr.h"
#include "Interpreter.h"
#include "Parser.h"
#include "Scanner.h"
#include "Stmt.h"
#include "Token.h"

Value e_FunctionType;
Value e_FunctionType_FUN_NONE;
Value e_FunctionType_FUN_FUNCTION;
Value e_FunctionType_FUN_METHOD;
Value e_FunctionType_FUN_INITIALIZER;
Value e_ClassType;
Value e_ClassType_CLASS_NONE;
Value e_ClassType_CLASS_CLASS;
Value e_ClassType_CLASS_SUBCLASS;
Value k_Resolver;
static Value or_0;
static Value or_1;
static Value or_2;
static const char *t_Resolver_Init_1_Interpreter[] = { "Interpreter" };
static const char *t_Resolver_CollectDottable_1_List[] = { "List" };
static const char *t_Resolver_IsUnitQualifier_1[] = { "Any" };
static const char *t_Resolver_VisitBlockStmt_1_BlockStmt[] = { "BlockStmt" };
static const char *t_Resolver_VisitClassStmt_1_ClassStmt[] = { "ClassStmt" };
static const char *t_Resolver_VisitObjectStmt_1_ObjectStmt[] = { "ObjectStmt" };
static const char *t_Resolver_VisitEnumStmt_1_EnumStmt[] = { "EnumStmt" };
static const char *t_Resolver_VisitExpressionStmt_1_ExpressionStmt[] = { "ExpressionStmt" };
static const char *t_Resolver_VisitIfStmt_1_IfStmt[] = { "IfStmt" };
static const char *t_Resolver_VisitTryStmt_1_TryStmt[] = { "TryStmt" };
static const char *t_Resolver_VisitModuleStmt_1_ModuleStmt[] = { "ModuleStmt" };
static const char *t_Resolver_VisitForInStmt_1_ForInStmt[] = { "ForInStmt" };
static const char *t_Resolver_VisitBreakStmt_1_BreakStmt[] = { "BreakStmt" };
static const char *t_Resolver_VisitRaiseStmt_1_RaiseStmt[] = { "RaiseStmt" };
static const char *t_Resolver_VisitPrintStmt_1_PrintStmt[] = { "PrintStmt" };
static const char *t_Resolver_VisitReturnStmt_1_ReturnStmt[] = { "ReturnStmt" };
static const char *t_Resolver_VisitWhileStmt_1_WhileStmt[] = { "WhileStmt" };
static const char *t_Resolver_VisitFunctionStmt_1_FunctionStmt[] = { "FunctionStmt" };
static const char *t_Resolver_VisitVarStmt_1_VarStmt[] = { "VarStmt" };
static const char *t_Resolver_VisitVarGroupStmt_1_VarGroupStmt[] = { "VarGroupStmt" };
static const char *t_Resolver_VisitAssignExpr_1_AssignExpr[] = { "AssignExpr" };
static const char *t_Resolver_VisitBinary_1_BinaryExpr[] = { "BinaryExpr" };
static const char *t_Resolver_VisitLogical_1_LogicalExpr[] = { "LogicalExpr" };
static const char *t_Resolver_VisitUnary_1_UnaryExpr[] = { "UnaryExpr" };
static const char *t_Resolver_VisitCall_1_CallExpr[] = { "CallExpr" };
static const char *t_Resolver_VisitGetExpr_1_GetExpr[] = { "GetExpr" };
static const char *t_Resolver_VisitSetExpr_1_SetExpr[] = { "SetExpr" };
static const char *t_Resolver_VisitSuperExpr_1_SuperExpr[] = { "SuperExpr" };
static const char *t_Resolver_VisitThisExpr_1_ThisExpr[] = { "ThisExpr" };
static const char *t_Resolver_VisitIsExpr_1_IsExpr[] = { "IsExpr" };
static const char *t_Resolver_VisitGrouping_1_GroupingExpr[] = { "GroupingExpr" };
static const char *t_Resolver_VisitSubscriptExpr_1_SubscriptExpr[] = { "SubscriptExpr" };
static const char *t_Resolver_VisitSetSubscriptExpr_1_SetSubscriptExpr[] = { "SetSubscriptExpr" };
static const char *t_Resolver_VisitCollectionExpr_1_CollectionExpr[] = { "CollectionExpr" };
static const char *t_Resolver_VisitLiteral_1_LiteralExpr[] = { "LiteralExpr" };
static const char *t_Resolver_VisitVariableExpr_1_VariableExpr[] = { "VariableExpr" };
static const char *t_Resolver_CheckDuplicates_1_List[] = { "List" };
static const char *t_Resolver_ResolveAll_1_List[] = { "List" };
static const char *t_Resolver_Resolve_1[] = { "Any" };
static const char *t_Resolver_ResolveFunction_2_FunctionStmt_FunctionType[] = { "FunctionStmt", "FunctionType" };
static const char *t_Resolver_Declare_1_Token[] = { "Token" };
static const char *t_Resolver_DeclareBinding_2_Token_Boolean[] = { "Token", "Boolean" };
static const char *t_Resolver_IsConstant_1_Token[] = { "Token" };
static const char *t_Resolver_Define_1_Token[] = { "Token" };
static const char *t_Resolver_ResolveLocal_2_Expr_Token[] = { "Expr", "Token" };

static Value i_Resolver(Value v_this, Value *args, int32_t count) {
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

static Value m_Resolver_Init_1_Interpreter(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    (void)(alg_set_property(v_this, "TheInterpreter", v_TheInterpreter));
    (void)(alg_set_property(v_this, "Scopes", alg_stack()));
    (void)(alg_set_property(v_this, "Constants", alg_stack()));
    (void)(alg_set_property(v_this, "GlobalConstants", alg_map()));
    (void)(alg_set_property(v_this, "CurrentFunction", e_FunctionType_FUN_NONE));
    (void)(alg_set_property(v_this, "CurrentClass", e_ClassType_CLASS_NONE));
    (void)(alg_set_property(v_this, "Units", alg_set()));
    (void)(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){alg_string("System")}, 1));
    (void)(alg_set_property(v_this, "Dottable", alg_set()));
    return alg_nil();
}

static Value m_Resolver_CollectDottable_1_List(Value v_this, Value *args, int32_t count) {
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
                    if (alg_truthy(alg_is(v_TheStmt, "ObjectStmt"))) {
                        (void)(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "EnumStmt"))) {
                        (void)(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "VarStmt"))) {
                        (void)(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))}, 1));
                    }
                    if (alg_truthy(alg_is(v_TheStmt, "VarGroupStmt"))) {
                        {
                            Value v_J = alg_int(0);
                            (void)v_J;
                            while (alg_truthy(alg_less(v_J, alg_property(alg_property(v_TheStmt, "Names"), "Length")))) {
                                {
                                    (void)(alg_invoke(alg_property(v_this, "Dottable"), "Add", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_J), "Lexeme"))}, 1));
                                    (void)((v_J = alg_add(v_J, alg_int(1))));
                                }
                            }
                        }
                    }
                    if (alg_truthy((or_0 = alg_is(v_TheStmt, "ModuleStmt"), !alg_truthy(or_0) ? or_0 : alg_not_equal(alg_property(v_TheStmt, "Statements"), alg_nil())))) {
                        (void)(alg_invoke(v_this, "CollectDottable", (Value[]){alg_property(v_TheStmt, "Statements")}, 1));
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_Resolver_IsUnitQualifier_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Obj = args[0];
    (void)v_Obj;
    if (alg_truthy(alg_not((alg_is(v_Obj, "VariableExpr"))))) {
        return alg_bool(false);
    }
    Value v_Name = alg_str(alg_property(alg_property(v_Obj, "Name"), "Lexeme"));
    (void)v_Name;
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Units"), "Contains", (Value[]){v_Name}, 1)))) {
        return alg_bool(false);
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Dottable"), "Contains", (Value[]){v_Name}, 1))) {
        return alg_bool(false);
    }
    {
        Value v_I = alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1));
        (void)v_I;
        while (alg_truthy(alg_greater_equal(v_I, alg_int(0)))) {
            {
                if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), v_I), "Contains", (Value[]){v_Name}, 1))) {
                    return alg_bool(false);
                }
                (void)((v_I = alg_subtract(v_I, alg_int(1))));
            }
        }
    }
    return alg_bool(true);
    return alg_nil();
}

static Value m_Resolver_VisitBlockStmt_1_BlockStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
    (void)(alg_invoke(v_this, "ResolveAll", (Value[]){alg_property(v_Stmt, "Statements")}, 1));
    (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    return alg_nil();
}

static Value m_Resolver_VisitClassStmt_1_ClassStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    Value v_EnclosingClass = alg_nil();
    (void)v_EnclosingClass;
    (void)((v_EnclosingClass = alg_property(v_this, "CurrentClass")));
    (void)(alg_set_property(v_this, "CurrentClass", e_ClassType_CLASS_CLASS));
    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_property(v_Stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_Stmt, "Name")}, 1));
    if (alg_truthy((or_1 = alg_not_equal(alg_property(v_Stmt, "Superclass"), alg_nil()), !alg_truthy(or_1) ? or_1 : alg_equal(alg_property(alg_property(v_Stmt, "Name"), "Lexeme"), alg_property(alg_property(alg_property(v_Stmt, "Superclass"), "Name"), "Lexeme"))))) {
        {
            alg_raise(alg_string("A class can't inherit from itself."));
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_Stmt, "Superclass"), alg_nil()))) {
        {
            (void)(alg_set_property(v_this, "CurrentClass", e_ClassType_CLASS_SUBCLASS));
            (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "Superclass")}, 1));
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_Stmt, "Superclass"), alg_nil()))) {
        {
            (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
            (void)(alg_invoke(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0), "Put", (Value[]){alg_string("super"), alg_bool(true)}, 2));
        }
    }
    (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
    (void)(alg_invoke(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0), "Put", (Value[]){alg_string("this"), alg_bool(true)}, 2));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_Stmt, "Methods"), "Length")))) {
            {
                {
                    Value v_Declaration = e_FunctionType_FUN_FUNCTION;
                    (void)v_Declaration;
                    if (alg_truthy(alg_equal(alg_property(alg_property(alg_subscript_get(alg_property(v_Stmt, "Methods"), v_I), "Name"), "Lexeme"), alg_string("Init")))) {
                        {
                            (void)((v_Declaration = e_FunctionType_FUN_INITIALIZER));
                        }
                    }
                    (void)(alg_invoke(v_this, "ResolveFunction", (Value[]){alg_subscript_get(alg_property(v_Stmt, "Methods"), v_I), v_Declaration}, 2));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    if (alg_truthy(alg_not_equal(alg_property(v_Stmt, "Superclass"), alg_nil()))) {
        (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    }
    (void)(alg_set_property(v_this, "CurrentClass", v_EnclosingClass));
    return alg_nil();
}

static Value m_Resolver_VisitObjectStmt_1_ObjectStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    (void)(alg_invoke(v_this, "VisitClassStmt", (Value[]){alg_new(k_ClassStmt, (Value[]){alg_property(v_Stmt, "Name"), alg_property(v_Stmt, "Superclass"), alg_property(v_Stmt, "Methods"), alg_property(v_Stmt, "Fields")}, 4)}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitEnumStmt_1_EnumStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_property(v_Stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_Stmt, "Name")}, 1));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_Stmt, "Members"), "Length")))) {
            {
                {
                    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_subscript_get(alg_property(v_Stmt, "Members"), v_I)}, 1));
                    (void)(alg_invoke(v_this, "Define", (Value[]){alg_subscript_get(alg_property(v_Stmt, "Members"), v_I)}, 1));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_Resolver_VisitExpressionStmt_1_ExpressionStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "Expression")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitIfStmt_1_IfStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "Condition")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "ThenBranch")}, 1));
    if (alg_truthy((alg_not_equal(alg_property(v_Stmt, "ElseBranch"), alg_nil())))) {
        (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "ElseBranch")}, 1));
    }
    return alg_nil();
}

static Value m_Resolver_VisitTryStmt_1_TryStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    Value v_Keys = alg_nil();
    (void)v_Keys;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "TryBlock")}, 1));
    (void)((v_Keys = alg_invoke(alg_property(v_Stmt, "Handlers"), "Keys", NULL, 0)));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Keys, "Length")))) {
            {
                (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(alg_invoke(alg_property(v_Stmt, "Handlers"), "Get", (Value[]){alg_subscript_get(v_Keys, v_I)}, 1), "Body")}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_Resolver_VisitModuleStmt_1_ModuleStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    Value v_Enclosing = alg_nil();
    (void)v_Enclosing;
    if (alg_truthy(alg_equal(alg_property(v_Stmt, "Statements"), alg_nil()))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){alg_str(alg_property(v_Stmt, "UnitName"))}, 1));
            return alg_nil();
        }
    }
    (void)((v_Enclosing = alg_property(v_this, "Units")));
    (void)(alg_set_property(v_this, "Units", alg_set()));
    (void)(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){alg_string("System")}, 1));
    (void)(alg_invoke(v_this, "ResolveAll", (Value[]){alg_property(v_Stmt, "Statements")}, 1));
    (void)(alg_set_property(v_this, "Units", v_Enclosing));
    (void)(alg_invoke(alg_property(v_this, "Units"), "Add", (Value[]){alg_str(alg_property(v_Stmt, "UnitName"))}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitForInStmt_1_ForInStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "Iterable")}, 1));
    (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_property(v_Stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_Stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "Body")}, 1));
    (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    return alg_nil();
}

static Value m_Resolver_VisitBreakStmt_1_BreakStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    return alg_nil();
}

static Value m_Resolver_VisitRaiseStmt_1_RaiseStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "Value")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitPrintStmt_1_PrintStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "Expression")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitReturnStmt_1_ReturnStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    if (alg_truthy(alg_equal(alg_property(v_this, "CurrentFunction"), e_FunctionType_FUN_NONE))) {
        {
            alg_raise(alg_string("Can't return from top-level code."));
        }
    }
    if (alg_truthy((alg_not_equal(alg_property(v_Stmt, "Value"), alg_nil())))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "CurrentFunction"), e_FunctionType_FUN_INITIALIZER))) {
                {
                    alg_raise(alg_string("Can't return a value from an initializer."));
                }
            }
            (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "Value")}, 1));
        }
    }
    return alg_nil();
}

static Value m_Resolver_VisitWhileStmt_1_WhileStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "Condition")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "Body")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitFunctionStmt_1_FunctionStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    (void)(alg_invoke(v_this, "Declare", (Value[]){alg_property(v_Stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_Stmt, "Name")}, 1));
    (void)(alg_invoke(v_this, "ResolveFunction", (Value[]){v_Stmt, e_FunctionType_FUN_FUNCTION}, 2));
    return alg_nil();
}

static Value m_Resolver_VisitVarStmt_1_VarStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    (void)(alg_invoke(v_this, "DeclareBinding", (Value[]){alg_property(v_Stmt, "Name"), alg_property(v_Stmt, "IsConstant")}, 2));
    if (alg_truthy((alg_not_equal(alg_property(v_Stmt, "Initializer"), alg_nil())))) {
        {
            (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "Initializer")}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Define", (Value[]){alg_property(v_Stmt, "Name")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitVarGroupStmt_1_VarGroupStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Stmt = args[0];
    (void)v_Stmt;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_Stmt, "Names"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "DeclareBinding", (Value[]){alg_subscript_get(alg_property(v_Stmt, "Names"), v_I), alg_property(v_Stmt, "IsConstant")}, 2));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_Stmt, "Initializer"), alg_nil()))) {
        (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_Stmt, "Initializer")}, 1));
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_Stmt, "Names"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "Define", (Value[]){alg_subscript_get(alg_property(v_Stmt, "Names"), v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_Resolver_VisitAssignExpr_1_AssignExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    if (alg_truthy(alg_invoke(v_this, "IsConstant", (Value[]){alg_property(v_TheExpr, "Name")}, 1))) {
        alg_raise(alg_add(alg_add(alg_string("Can't assign to constant '"), alg_property(alg_property(v_TheExpr, "Name"), "Lexeme")), alg_string("'.")));
    }
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Value")}, 1));
    (void)(alg_invoke(v_this, "ResolveLocal", (Value[]){v_TheExpr, alg_property(v_TheExpr, "Name")}, 2));
    return alg_nil();
}

static Value m_Resolver_VisitBinary_1_BinaryExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Left")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Right")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitLogical_1_LogicalExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Left")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Right")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitUnary_1_UnaryExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Right")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitCall_1_CallExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Callee")}, 1));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Arguments"), "Length")))) {
            {
                {
                    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Arguments"), v_I)}, 1));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_Resolver_VisitGetExpr_1_GetExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    if (alg_truthy(alg_invoke(v_this, "IsUnitQualifier", (Value[]){alg_property(v_TheExpr, "Obj")}, 1))) {
        {
            (void)(alg_set_property(v_TheExpr, "Unit", alg_str(alg_property(alg_property(alg_property(v_TheExpr, "Obj"), "Name"), "Lexeme"))));
            return alg_nil();
        }
    }
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Obj")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitSetExpr_1_SetExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    if (alg_truthy(alg_invoke(v_this, "IsUnitQualifier", (Value[]){alg_property(v_TheExpr, "Obj")}, 1))) {
        {
            (void)(alg_set_property(v_TheExpr, "Unit", alg_str(alg_property(alg_property(alg_property(v_TheExpr, "Obj"), "Name"), "Lexeme"))));
            (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Value")}, 1));
            return alg_nil();
        }
    }
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Value")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Obj")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitSuperExpr_1_SuperExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    if (alg_truthy(alg_equal(alg_property(v_this, "CurrentClass"), e_ClassType_CLASS_NONE))) {
        alg_raise(alg_string("Can't use 'super' outside a class."));
    } else {
        if (alg_truthy(alg_not_equal(alg_property(v_this, "CurrentClass"), e_ClassType_CLASS_SUBCLASS))) {
            alg_raise(alg_string("Can't use 'super' in a class with no superclass."));
        }
    }
    (void)(alg_invoke(v_this, "ResolveLocal", (Value[]){v_TheExpr, alg_property(v_TheExpr, "Keyword")}, 2));
    return alg_nil();
}

static Value m_Resolver_VisitThisExpr_1_ThisExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    if (alg_truthy(alg_equal(alg_property(v_this, "CurrentClass"), e_ClassType_CLASS_NONE))) {
        {
            alg_raise(alg_string("Can't use 'this' outside a class."));
        }
    }
    (void)(alg_invoke(v_this, "ResolveLocal", (Value[]){v_TheExpr, alg_property(v_TheExpr, "Keyword")}, 2));
    return alg_nil();
}

static Value m_Resolver_VisitIsExpr_1_IsExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Obj")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitGrouping_1_GroupingExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Expression")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitSubscriptExpr_1_SubscriptExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Obj")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Index")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitSetSubscriptExpr_1_SetSubscriptExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Obj")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Index")}, 1));
    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_property(v_TheExpr, "Value")}, 1));
    return alg_nil();
}

static Value m_Resolver_VisitCollectionExpr_1_CollectionExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Keys"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Keys"), v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Values"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Values"), v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_Resolver_VisitLiteral_1_LiteralExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    return alg_nil();
}

static Value m_Resolver_VisitVariableExpr_1_VariableExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    if (alg_truthy((or_2 = alg_not(alg_property(alg_property(v_this, "Scopes"), "IsEmpty")), !alg_truthy(or_2) ? or_2 : alg_equal(alg_invoke(alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0), "Get", (Value[]){alg_property(alg_property(v_TheExpr, "Name"), "Lexeme")}, 1), alg_bool(false))))) {
        {
            alg_raise(alg_string("Can't read local variable in its own initializer."));
        }
    }
    (void)(alg_invoke(v_this, "ResolveLocal", (Value[]){v_TheExpr, alg_property(v_TheExpr, "Name")}, 2));
    return alg_nil();
}

static Value m_Resolver_CheckDuplicates_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    Value v_Seen = alg_nil();
    (void)v_Seen;
    Value v_MemberOwner = alg_nil();
    (void)v_MemberOwner;
    (void)((v_Seen = alg_set()));
    (void)((v_MemberOwner = alg_map()));
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
                            if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Statements"), alg_nil()))) {
                                (void)(alg_invoke(v_this, "CheckDuplicates", (Value[]){alg_property(v_TheStmt, "Statements")}, 1));
                            }
                        }
                    } else {
                        {
                            Value v_TheName = alg_string("");
                            (void)v_TheName;
                            if (alg_truthy(alg_is(v_TheStmt, "FunctionStmt"))) {
                                (void)((v_TheName = alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))));
                            }
                            if (alg_truthy(alg_is(v_TheStmt, "ClassStmt"))) {
                                (void)((v_TheName = alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))));
                            }
                            if (alg_truthy(alg_is(v_TheStmt, "ObjectStmt"))) {
                                (void)((v_TheName = alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))));
                            }
                            if (alg_truthy(alg_is(v_TheStmt, "VarStmt"))) {
                                (void)((v_TheName = alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))));
                            }
                            if (alg_truthy(alg_is(v_TheStmt, "EnumStmt"))) {
                                {
                                    Value v_Owner = alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"));
                                    (void)v_Owner;
                                    {
                                        Value v_J = alg_int(0);
                                        (void)v_J;
                                        while (alg_truthy(alg_less(v_J, alg_property(alg_property(v_TheStmt, "Members"), "Length")))) {
                                            {
                                                {
                                                    Value v_Member = alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Members"), v_J), "Lexeme"));
                                                    (void)v_Member;
                                                    if (alg_truthy(alg_invoke(v_Seen, "Contains", (Value[]){v_Member}, 1))) {
                                                        alg_raise(alg_add(alg_add(alg_string("'"), v_Member), alg_string("' is already defined.")));
                                                    }
                                                    if (alg_truthy(alg_invoke(v_MemberOwner, "Contains", (Value[]){v_Member}, 1))) {
                                                        if (alg_truthy(alg_equal(alg_str(alg_invoke(v_MemberOwner, "Get", (Value[]){v_Member}, 1)), v_Owner))) {
                                                            alg_raise(alg_add(alg_add(alg_string("'"), v_Member), alg_string("' is already defined.")));
                                                        }
                                                    }
                                                    (void)(alg_invoke(v_MemberOwner, "Put", (Value[]){v_Member, v_Owner}, 2));
                                                }
                                                (void)((v_J = alg_add(v_J, alg_int(1))));
                                            }
                                        }
                                    }
                                    (void)((v_TheName = alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"))));
                                }
                            }
                            if (alg_truthy(alg_is(v_TheStmt, "VarGroupStmt"))) {
                                {
                                    Value v_J = alg_int(0);
                                    (void)v_J;
                                    while (alg_truthy(alg_less(v_J, alg_property(alg_property(v_TheStmt, "Names"), "Length")))) {
                                        {
                                            {
                                                Value v_Each = alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_J), "Lexeme"));
                                                (void)v_Each;
                                                if (alg_truthy(alg_invoke(v_Seen, "Contains", (Value[]){v_Each}, 1))) {
                                                    alg_raise(alg_add(alg_add(alg_string("'"), v_Each), alg_string("' is already defined.")));
                                                }
                                                if (alg_truthy(alg_invoke(v_MemberOwner, "Contains", (Value[]){v_Each}, 1))) {
                                                    alg_raise(alg_add(alg_add(alg_string("'"), v_Each), alg_string("' is already defined.")));
                                                }
                                                (void)(alg_invoke(v_Seen, "Add", (Value[]){v_Each}, 1));
                                            }
                                            (void)((v_J = alg_add(v_J, alg_int(1))));
                                        }
                                    }
                                }
                            }
                            if (alg_truthy(alg_not_equal(v_TheName, alg_string("")))) {
                                {
                                    if (alg_truthy(alg_invoke(v_Seen, "Contains", (Value[]){v_TheName}, 1))) {
                                        alg_raise(alg_add(alg_add(alg_string("'"), v_TheName), alg_string("' is already defined.")));
                                    }
                                    if (alg_truthy(alg_invoke(v_MemberOwner, "Contains", (Value[]){v_TheName}, 1))) {
                                        alg_raise(alg_add(alg_add(alg_string("'"), v_TheName), alg_string("' is already defined.")));
                                    }
                                    (void)(alg_invoke(v_Seen, "Add", (Value[]){v_TheName}, 1));
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

static Value m_Resolver_ResolveAll_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    if (alg_truthy(alg_not(alg_property(v_this, "Collected")))) {
        {
            (void)(alg_set_property(v_this, "Collected", alg_bool(true)));
            (void)(alg_invoke(v_this, "CollectDottable", (Value[]){v_Statements}, 1));
            (void)(alg_invoke(v_this, "CheckDuplicates", (Value[]){v_Statements}, 1));
        }
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Statements, "Length")))) {
            {
                {
                    (void)(alg_invoke(v_this, "Resolve", (Value[]){alg_subscript_get(v_Statements, v_I)}, 1));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_Resolver_Resolve_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    (void)(alg_invoke(v_TheExpr, "Accept", (Value[]){v_this}, 1));
    return alg_nil();
}

static Value m_Resolver_ResolveFunction_2_FunctionStmt_FunctionType(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheFunction = args[0];
    (void)v_TheFunction;
    Value v_TypeOfFunction = args[1];
    (void)v_TypeOfFunction;
    Value v_EnclosingFunction = alg_nil();
    (void)v_EnclosingFunction;
    (void)((v_EnclosingFunction = alg_property(v_this, "CurrentFunction")));
    (void)(alg_set_property(v_this, "CurrentFunction", v_TypeOfFunction));
    (void)(alg_invoke(v_this, "BeginScope", NULL, 0));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheFunction, "Params"), "Length")))) {
            {
                {
                    Value v_Param = alg_subscript_get(alg_property(v_TheFunction, "Params"), v_I);
                    (void)v_Param;
                    (void)(alg_invoke(v_this, "Declare", (Value[]){v_Param}, 1));
                    (void)(alg_invoke(v_this, "Define", (Value[]){v_Param}, 1));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "ResolveAll", (Value[]){alg_property(v_TheFunction, "Body")}, 1));
    (void)(alg_invoke(v_this, "EndScope", NULL, 0));
    (void)(alg_set_property(v_this, "CurrentFunction", v_EnclosingFunction));
    return alg_nil();
}

static Value m_Resolver_BeginScope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_invoke(alg_property(v_this, "Scopes"), "Push", (Value[]){alg_map()}, 1));
    (void)(alg_invoke(alg_property(v_this, "Constants"), "Push", (Value[]){alg_map()}, 1));
    return alg_nil();
}

static Value m_Resolver_EndScope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_invoke(alg_property(v_this, "Scopes"), "Pop", NULL, 0));
    (void)(alg_invoke(alg_property(v_this, "Constants"), "Pop", NULL, 0));
    return alg_nil();
}

static Value m_Resolver_Declare_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    (void)(alg_invoke(v_this, "DeclareBinding", (Value[]){v_Name, alg_bool(false)}, 2));
    return alg_nil();
}

static Value m_Resolver_DeclareBinding_2_Token_Boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_IsConstant = args[1];
    (void)v_IsConstant;
    Value v_Scope = alg_nil();
    (void)v_Scope;
    if (alg_truthy(alg_property(alg_property(v_this, "Scopes"), "IsEmpty"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "GlobalConstants"), "Put", (Value[]){alg_str(alg_property(v_Name, "Lexeme")), v_IsConstant}, 2));
            return alg_nil();
        }
    }
    (void)((v_Scope = alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0)));
    if (alg_truthy(alg_invoke(v_Scope, "Contains", (Value[]){alg_property(v_Name, "Lexeme")}, 1))) {
        {
            alg_raise(alg_string("Already a variable with this name in this scope."));
        }
    }
    (void)(alg_invoke(v_Scope, "Put", (Value[]){alg_property(v_Name, "Lexeme"), alg_bool(false)}, 2));
    (void)(alg_invoke(alg_invoke(alg_property(v_this, "Constants"), "Peek", NULL, 0), "Put", (Value[]){alg_str(alg_property(v_Name, "Lexeme")), v_IsConstant}, 2));
    return alg_nil();
}

static Value m_Resolver_IsConstant_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Lexeme = alg_nil();
    (void)v_Lexeme;
    (void)((v_Lexeme = alg_str(alg_property(v_Name, "Lexeme"))));
    {
        Value v_I = alg_subtract(alg_property(alg_property(v_this, "Constants"), "Length"), alg_int(1));
        (void)v_I;
        while (alg_truthy(alg_greater_equal(v_I, alg_int(0)))) {
            {
                if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Constants"), v_I), "Contains", (Value[]){v_Lexeme}, 1))) {
                    return alg_invoke(alg_subscript_get(alg_property(v_this, "Constants"), v_I), "Get", (Value[]){v_Lexeme}, 1);
                }
                (void)((v_I = alg_subtract(v_I, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "GlobalConstants"), "Contains", (Value[]){v_Lexeme}, 1))) {
        return alg_invoke(alg_property(v_this, "GlobalConstants"), "Get", (Value[]){v_Lexeme}, 1);
    }
    return alg_bool(false);
    return alg_nil();
}

static Value m_Resolver_Define_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Scope = alg_nil();
    (void)v_Scope;
    if (alg_truthy(alg_property(alg_property(v_this, "Scopes"), "IsEmpty"))) {
        return alg_nil();
    }
    (void)((v_Scope = alg_invoke(alg_property(v_this, "Scopes"), "Peek", NULL, 0)));
    (void)(alg_invoke(v_Scope, "Put", (Value[]){alg_property(v_Name, "Lexeme"), alg_bool(true)}, 2));
    return alg_nil();
}

static Value m_Resolver_ResolveLocal_2_Expr_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Name = args[1];
    (void)v_Name;
    {
        Value v_I = alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1));
        (void)v_I;
        while (alg_truthy(alg_greater_equal(v_I, alg_int(0)))) {
            {
                {
                    if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), v_I), "Contains", (Value[]){alg_property(v_Name, "Lexeme")}, 1))) {
                        {
                            (void)(alg_invoke(alg_property(v_this, "TheInterpreter"), "Resolve", (Value[]){v_TheExpr, alg_subtract(alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1)), v_I)}, 2));
                            return alg_nil();
                        }
                    }
                }
                (void)((v_I = alg_subtract(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

void init_Resolver(void) {
    e_FunctionType = alg_enum_type("FunctionType");
    e_FunctionType_FUN_NONE = alg_enum_member(e_FunctionType, "FUN_NONE");
    e_FunctionType_FUN_FUNCTION = alg_enum_member(e_FunctionType, "FUN_FUNCTION");
    e_FunctionType_FUN_METHOD = alg_enum_member(e_FunctionType, "FUN_METHOD");
    e_FunctionType_FUN_INITIALIZER = alg_enum_member(e_FunctionType, "FUN_INITIALIZER");
    e_ClassType = alg_enum_type("ClassType");
    e_ClassType_CLASS_NONE = alg_enum_member(e_ClassType, "CLASS_NONE");
    e_ClassType_CLASS_CLASS = alg_enum_member(e_ClassType, "CLASS_CLASS");
    e_ClassType_CLASS_SUBCLASS = alg_enum_member(e_ClassType, "CLASS_SUBCLASS");
    k_Resolver = alg_class("Resolver", alg_nil());
    alg_class_field(k_Resolver, "TheInterpreter");
    alg_class_field(k_Resolver, "Scopes");
    alg_class_field(k_Resolver, "Constants");
    alg_class_field(k_Resolver, "GlobalConstants");
    alg_class_field(k_Resolver, "CurrentFunction");
    alg_class_field(k_Resolver, "CurrentClass");
    alg_class_field(k_Resolver, "Units");
    alg_class_field(k_Resolver, "Dottable");
    alg_class_field(k_Resolver, "Collected");
    alg_class_initializer(k_Resolver, i_Resolver);
    alg_class_method(k_Resolver, "Init", m_Resolver_Init_1_Interpreter, 1, t_Resolver_Init_1_Interpreter);
    alg_class_method(k_Resolver, "CollectDottable", m_Resolver_CollectDottable_1_List, 1, t_Resolver_CollectDottable_1_List);
    alg_class_method(k_Resolver, "IsUnitQualifier", m_Resolver_IsUnitQualifier_1, 1, t_Resolver_IsUnitQualifier_1);
    alg_class_method(k_Resolver, "VisitBlockStmt", m_Resolver_VisitBlockStmt_1_BlockStmt, 1, t_Resolver_VisitBlockStmt_1_BlockStmt);
    alg_class_method(k_Resolver, "VisitClassStmt", m_Resolver_VisitClassStmt_1_ClassStmt, 1, t_Resolver_VisitClassStmt_1_ClassStmt);
    alg_class_method(k_Resolver, "VisitObjectStmt", m_Resolver_VisitObjectStmt_1_ObjectStmt, 1, t_Resolver_VisitObjectStmt_1_ObjectStmt);
    alg_class_method(k_Resolver, "VisitEnumStmt", m_Resolver_VisitEnumStmt_1_EnumStmt, 1, t_Resolver_VisitEnumStmt_1_EnumStmt);
    alg_class_method(k_Resolver, "VisitExpressionStmt", m_Resolver_VisitExpressionStmt_1_ExpressionStmt, 1, t_Resolver_VisitExpressionStmt_1_ExpressionStmt);
    alg_class_method(k_Resolver, "VisitIfStmt", m_Resolver_VisitIfStmt_1_IfStmt, 1, t_Resolver_VisitIfStmt_1_IfStmt);
    alg_class_method(k_Resolver, "VisitTryStmt", m_Resolver_VisitTryStmt_1_TryStmt, 1, t_Resolver_VisitTryStmt_1_TryStmt);
    alg_class_method(k_Resolver, "VisitModuleStmt", m_Resolver_VisitModuleStmt_1_ModuleStmt, 1, t_Resolver_VisitModuleStmt_1_ModuleStmt);
    alg_class_method(k_Resolver, "VisitForInStmt", m_Resolver_VisitForInStmt_1_ForInStmt, 1, t_Resolver_VisitForInStmt_1_ForInStmt);
    alg_class_method(k_Resolver, "VisitBreakStmt", m_Resolver_VisitBreakStmt_1_BreakStmt, 1, t_Resolver_VisitBreakStmt_1_BreakStmt);
    alg_class_method(k_Resolver, "VisitRaiseStmt", m_Resolver_VisitRaiseStmt_1_RaiseStmt, 1, t_Resolver_VisitRaiseStmt_1_RaiseStmt);
    alg_class_method(k_Resolver, "VisitPrintStmt", m_Resolver_VisitPrintStmt_1_PrintStmt, 1, t_Resolver_VisitPrintStmt_1_PrintStmt);
    alg_class_method(k_Resolver, "VisitReturnStmt", m_Resolver_VisitReturnStmt_1_ReturnStmt, 1, t_Resolver_VisitReturnStmt_1_ReturnStmt);
    alg_class_method(k_Resolver, "VisitWhileStmt", m_Resolver_VisitWhileStmt_1_WhileStmt, 1, t_Resolver_VisitWhileStmt_1_WhileStmt);
    alg_class_method(k_Resolver, "VisitFunctionStmt", m_Resolver_VisitFunctionStmt_1_FunctionStmt, 1, t_Resolver_VisitFunctionStmt_1_FunctionStmt);
    alg_class_method(k_Resolver, "VisitVarStmt", m_Resolver_VisitVarStmt_1_VarStmt, 1, t_Resolver_VisitVarStmt_1_VarStmt);
    alg_class_method(k_Resolver, "VisitVarGroupStmt", m_Resolver_VisitVarGroupStmt_1_VarGroupStmt, 1, t_Resolver_VisitVarGroupStmt_1_VarGroupStmt);
    alg_class_method(k_Resolver, "VisitAssignExpr", m_Resolver_VisitAssignExpr_1_AssignExpr, 1, t_Resolver_VisitAssignExpr_1_AssignExpr);
    alg_class_method(k_Resolver, "VisitBinary", m_Resolver_VisitBinary_1_BinaryExpr, 1, t_Resolver_VisitBinary_1_BinaryExpr);
    alg_class_method(k_Resolver, "VisitLogical", m_Resolver_VisitLogical_1_LogicalExpr, 1, t_Resolver_VisitLogical_1_LogicalExpr);
    alg_class_method(k_Resolver, "VisitUnary", m_Resolver_VisitUnary_1_UnaryExpr, 1, t_Resolver_VisitUnary_1_UnaryExpr);
    alg_class_method(k_Resolver, "VisitCall", m_Resolver_VisitCall_1_CallExpr, 1, t_Resolver_VisitCall_1_CallExpr);
    alg_class_method(k_Resolver, "VisitGetExpr", m_Resolver_VisitGetExpr_1_GetExpr, 1, t_Resolver_VisitGetExpr_1_GetExpr);
    alg_class_method(k_Resolver, "VisitSetExpr", m_Resolver_VisitSetExpr_1_SetExpr, 1, t_Resolver_VisitSetExpr_1_SetExpr);
    alg_class_method(k_Resolver, "VisitSuperExpr", m_Resolver_VisitSuperExpr_1_SuperExpr, 1, t_Resolver_VisitSuperExpr_1_SuperExpr);
    alg_class_method(k_Resolver, "VisitThisExpr", m_Resolver_VisitThisExpr_1_ThisExpr, 1, t_Resolver_VisitThisExpr_1_ThisExpr);
    alg_class_method(k_Resolver, "VisitIsExpr", m_Resolver_VisitIsExpr_1_IsExpr, 1, t_Resolver_VisitIsExpr_1_IsExpr);
    alg_class_method(k_Resolver, "VisitGrouping", m_Resolver_VisitGrouping_1_GroupingExpr, 1, t_Resolver_VisitGrouping_1_GroupingExpr);
    alg_class_method(k_Resolver, "VisitSubscriptExpr", m_Resolver_VisitSubscriptExpr_1_SubscriptExpr, 1, t_Resolver_VisitSubscriptExpr_1_SubscriptExpr);
    alg_class_method(k_Resolver, "VisitSetSubscriptExpr", m_Resolver_VisitSetSubscriptExpr_1_SetSubscriptExpr, 1, t_Resolver_VisitSetSubscriptExpr_1_SetSubscriptExpr);
    alg_class_method(k_Resolver, "VisitCollectionExpr", m_Resolver_VisitCollectionExpr_1_CollectionExpr, 1, t_Resolver_VisitCollectionExpr_1_CollectionExpr);
    alg_class_method(k_Resolver, "VisitLiteral", m_Resolver_VisitLiteral_1_LiteralExpr, 1, t_Resolver_VisitLiteral_1_LiteralExpr);
    alg_class_method(k_Resolver, "VisitVariableExpr", m_Resolver_VisitVariableExpr_1_VariableExpr, 1, t_Resolver_VisitVariableExpr_1_VariableExpr);
    alg_class_method(k_Resolver, "CheckDuplicates", m_Resolver_CheckDuplicates_1_List, 1, t_Resolver_CheckDuplicates_1_List);
    alg_class_method(k_Resolver, "ResolveAll", m_Resolver_ResolveAll_1_List, 1, t_Resolver_ResolveAll_1_List);
    alg_class_method(k_Resolver, "Resolve", m_Resolver_Resolve_1, 1, t_Resolver_Resolve_1);
    alg_class_method(k_Resolver, "ResolveFunction", m_Resolver_ResolveFunction_2_FunctionStmt_FunctionType, 2, t_Resolver_ResolveFunction_2_FunctionStmt_FunctionType);
    alg_class_method(k_Resolver, "BeginScope", m_Resolver_BeginScope_0, 0, NULL);
    alg_class_method(k_Resolver, "EndScope", m_Resolver_EndScope_0, 0, NULL);
    alg_class_method(k_Resolver, "Declare", m_Resolver_Declare_1_Token, 1, t_Resolver_Declare_1_Token);
    alg_class_method(k_Resolver, "DeclareBinding", m_Resolver_DeclareBinding_2_Token_Boolean, 2, t_Resolver_DeclareBinding_2_Token_Boolean);
    alg_class_method(k_Resolver, "IsConstant", m_Resolver_IsConstant_1_Token, 1, t_Resolver_IsConstant_1_Token);
    alg_class_method(k_Resolver, "Define", m_Resolver_Define_1_Token, 1, t_Resolver_Define_1_Token);
    alg_class_method(k_Resolver, "ResolveLocal", m_Resolver_ResolveLocal_2_Expr_Token, 2, t_Resolver_ResolveLocal_2_Expr_Token);
}
