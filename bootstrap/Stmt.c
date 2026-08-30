/* Generated from Algol-24.  Do not edit. */
#include "Stmt.h"
#include "Expr.h"
#include "Token.h"

Value k_stmt;
Value k_blockstmt;
static const char *t_blockstmt_init_1_list[] = { "List" };
static const char *t_blockstmt_accept_1[] = { "Any" };
Value k_expressionstmt;
static const char *t_expressionstmt_init_1_expr[] = { "Expr" };
static const char *t_expressionstmt_accept_1[] = { "Any" };
Value k_varstmt;
static const char *t_varstmt_init_2_token_expr[] = { "Token", "Expr" };
static const char *t_varstmt_accept_1[] = { "Any" };
Value k_vargroupstmt;
static const char *t_vargroupstmt_init_2_list_expr[] = { "List", "Expr" };
static const char *t_vargroupstmt_accept_1[] = { "Any" };
Value k_ifstmt;
static const char *t_ifstmt_init_3_expr_stmt_stmt[] = { "Expr", "Stmt", "Stmt" };
static const char *t_ifstmt_accept_1[] = { "Any" };
Value k_excepthandler;
static const char *t_excepthandler_init_2_string_stmt[] = { "String", "Stmt" };
Value k_objectstmt;
static const char *t_objectstmt_init_4_token_variableexpr_list_list[] = { "Token", "VariableExpr", "List", "List" };
static const char *t_objectstmt_accept_1[] = { "Any" };
Value k_modulestmt;
static const char *t_modulestmt_init_3_token_list_list[] = { "Token", "List", "List" };
static const char *t_modulestmt_accept_1[] = { "Any" };
Value k_breakstmt;
static const char *t_breakstmt_init_1_token[] = { "Token" };
static const char *t_breakstmt_accept_1[] = { "Any" };
Value k_trystmt;
static const char *t_trystmt_init_2_stmt_map[] = { "Stmt", "Map" };
static const char *t_trystmt_accept_1[] = { "Any" };
Value k_raisestmt;
static const char *t_raisestmt_init_2_token_expr[] = { "Token", "Expr" };
static const char *t_raisestmt_accept_1[] = { "Any" };
Value k_forinstmt;
static const char *t_forinstmt_init_3_token_expr_stmt[] = { "Token", "Expr", "Stmt" };
static const char *t_forinstmt_accept_1[] = { "Any" };
Value k_whilestmt;
static const char *t_whilestmt_init_2_expr_stmt[] = { "Expr", "Stmt" };
static const char *t_whilestmt_accept_1[] = { "Any" };
Value k_functionstmt;
static const char *t_functionstmt_init_3_token_list_list[] = { "Token", "List", "List" };
static const char *t_functionstmt_accept_1[] = { "Any" };
Value k_returnstmt;
static const char *t_returnstmt_init_2_token_expr[] = { "Token", "Expr" };
static const char *t_returnstmt_accept_1[] = { "Any" };
Value k_enumstmt;
static const char *t_enumstmt_init_2_token_list[] = { "Token", "List" };
static const char *t_enumstmt_accept_1[] = { "Any" };
Value k_subrangestmt;
static const char *t_subrangestmt_init_3_token_integer_integer[] = { "Token", "Integer", "Integer" };
static const char *t_subrangestmt_accept_1[] = { "Any" };
Value k_classstmt;
static const char *t_classstmt_init_4_token_variableexpr_list_list[] = { "Token", "VariableExpr", "List", "List" };
static const char *t_classstmt_accept_1[] = { "Any" };

static Value i_stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value i_blockstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Statements", alg_nil());
    return alg_nil();
}

static Value m_blockstmt_init_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    (void)(alg_set_property(v_this, "Statements", alg_widen(v_statements, "List")));
    return alg_nil();
}

static Value m_blockstmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitBlockStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_expressionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Expression", alg_nil());
    return alg_nil();
}

static Value m_expressionstmt_init_1_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_expression = alg_widen(args[0], "Expr");
    (void)v_expression;
    (void)(alg_set_property(v_this, "Expression", alg_widen(v_expression, "Expr")));
    return alg_nil();
}

static Value m_expressionstmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitExpressionStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_varstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Initializer", alg_nil());
    alg_set_property(v_this, "TypeName", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "IsConstant", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "Generic", alg_widen(alg_string(""), "String"));
    return alg_nil();
}

static Value m_varstmt_init_2_token_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_initializer = alg_widen(args[1], "Expr");
    (void)v_initializer;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    (void)(alg_set_property(v_this, "Initializer", alg_widen(v_initializer, "Expr")));
    return alg_nil();
}

static Value m_varstmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitVarStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_vargroupstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Names", alg_nil());
    alg_set_property(v_this, "Initializer", alg_nil());
    alg_set_property(v_this, "TypeName", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "Generic", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "IsConstant", alg_widen(alg_bool(false), "Boolean"));
    return alg_nil();
}

static Value m_vargroupstmt_init_2_list_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_names = alg_widen(args[0], "List");
    (void)v_names;
    Value v_initializer = alg_widen(args[1], "Expr");
    (void)v_initializer;
    (void)(alg_set_property(v_this, "Names", alg_widen(v_names, "List")));
    (void)(alg_set_property(v_this, "Initializer", alg_widen(v_initializer, "Expr")));
    return alg_nil();
}

static Value m_vargroupstmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitVarGroupStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_ifstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Condition", alg_nil());
    alg_set_property(v_this, "ThenBranch", alg_nil());
    alg_set_property(v_this, "ElseBranch", alg_nil());
    return alg_nil();
}

static Value m_ifstmt_init_3_expr_stmt_stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_condition = alg_widen(args[0], "Expr");
    (void)v_condition;
    Value v_thenbranch = alg_widen(args[1], "Stmt");
    (void)v_thenbranch;
    Value v_elsebranch = alg_widen(args[2], "Stmt");
    (void)v_elsebranch;
    (void)(alg_set_property(v_this, "Condition", alg_widen(v_condition, "Expr")));
    (void)(alg_set_property(v_this, "ThenBranch", alg_widen(v_thenbranch, "Stmt")));
    (void)(alg_set_property(v_this, "ElseBranch", alg_widen(v_elsebranch, "Stmt")));
    return alg_nil();
}

static Value m_ifstmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitIfStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_excepthandler(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Body", alg_nil());
    return alg_nil();
}

static Value m_excepthandler_init_2_string_stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_body = alg_widen(args[1], "Stmt");
    (void)v_body;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "String")));
    (void)(alg_set_property(v_this, "Body", alg_widen(v_body, "Stmt")));
    return alg_nil();
}

static Value i_objectstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Superclass", alg_nil());
    alg_set_property(v_this, "Methods", alg_nil());
    alg_set_property(v_this, "Fields", alg_nil());
    alg_set_property(v_this, "PrivateMembers", alg_widen(alg_list(), "List"));
    return alg_nil();
}

static Value m_objectstmt_init_4_token_variableexpr_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_superclass = alg_widen(args[1], "VariableExpr");
    (void)v_superclass;
    Value v_methods = alg_widen(args[2], "List");
    (void)v_methods;
    Value v_fields = alg_widen(args[3], "List");
    (void)v_fields;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    (void)(alg_set_property(v_this, "Superclass", alg_widen(v_superclass, "VariableExpr")));
    (void)(alg_set_property(v_this, "Methods", alg_widen(v_methods, "List")));
    (void)(alg_set_property(v_this, "Fields", alg_widen(v_fields, "List")));
    return alg_nil();
}

static Value m_objectstmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitObjectStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_modulestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Statements", alg_nil());
    alg_set_property(v_this, "PrivateNames", alg_nil());
    alg_set_property(v_this, "FileName", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "UnitName", alg_widen(alg_string(""), "String"));
    return alg_nil();
}

static Value m_modulestmt_init_3_token_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_statements = alg_widen(args[1], "List");
    (void)v_statements;
    Value v_privatenames = alg_widen(args[2], "List");
    (void)v_privatenames;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    (void)(alg_set_property(v_this, "Statements", alg_widen(v_statements, "List")));
    (void)(alg_set_property(v_this, "PrivateNames", alg_widen(v_privatenames, "List")));
    return alg_nil();
}

static Value m_modulestmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitModuleStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_breakstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Keyword", alg_nil());
    return alg_nil();
}

static Value m_breakstmt_init_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_keyword = alg_widen(args[0], "Token");
    (void)v_keyword;
    (void)(alg_set_property(v_this, "Keyword", alg_widen(v_keyword, "Token")));
    return alg_nil();
}

static Value m_breakstmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitBreakStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_trystmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "TryBlock", alg_nil());
    alg_set_property(v_this, "Handlers", alg_nil());
    return alg_nil();
}

static Value m_trystmt_init_2_stmt_map(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_tryblock = alg_widen(args[0], "Stmt");
    (void)v_tryblock;
    Value v_handlers = alg_widen(args[1], "Map");
    (void)v_handlers;
    (void)(alg_set_property(v_this, "TryBlock", alg_widen(v_tryblock, "Stmt")));
    (void)(alg_set_property(v_this, "Handlers", alg_widen(v_handlers, "Map")));
    return alg_nil();
}

static Value m_trystmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitTryStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_raisestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Keyword", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    return alg_nil();
}

static Value m_raisestmt_init_2_token_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_keyword = alg_widen(args[0], "Token");
    (void)v_keyword;
    Value v_value = alg_widen(args[1], "Expr");
    (void)v_value;
    (void)(alg_set_property(v_this, "Keyword", alg_widen(v_keyword, "Token")));
    (void)(alg_set_property(v_this, "Value", alg_widen(v_value, "Expr")));
    return alg_nil();
}

static Value m_raisestmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitRaiseStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_forinstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Iterable", alg_nil());
    alg_set_property(v_this, "Body", alg_nil());
    return alg_nil();
}

static Value m_forinstmt_init_3_token_expr_stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_iterable = alg_widen(args[1], "Expr");
    (void)v_iterable;
    Value v_body = alg_widen(args[2], "Stmt");
    (void)v_body;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    (void)(alg_set_property(v_this, "Iterable", alg_widen(v_iterable, "Expr")));
    (void)(alg_set_property(v_this, "Body", alg_widen(v_body, "Stmt")));
    return alg_nil();
}

static Value m_forinstmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitForInStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_whilestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Condition", alg_nil());
    alg_set_property(v_this, "Body", alg_nil());
    return alg_nil();
}

static Value m_whilestmt_init_2_expr_stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_condition = alg_widen(args[0], "Expr");
    (void)v_condition;
    Value v_body = alg_widen(args[1], "Stmt");
    (void)v_body;
    (void)(alg_set_property(v_this, "Condition", alg_widen(v_condition, "Expr")));
    (void)(alg_set_property(v_this, "Body", alg_widen(v_body, "Stmt")));
    return alg_nil();
}

static Value m_whilestmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitWhileStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_functionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Params", alg_nil());
    alg_set_property(v_this, "Body", alg_nil());
    alg_set_property(v_this, "ReturnType", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "ParamTypes", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "ParamGenerics", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "ReturnGeneric", alg_widen(alg_string(""), "String"));
    return alg_nil();
}

static Value m_functionstmt_init_3_token_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_params = alg_widen(args[1], "List");
    (void)v_params;
    Value v_body = alg_widen(args[2], "List");
    (void)v_body;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    (void)(alg_set_property(v_this, "Params", alg_widen(v_params, "List")));
    (void)(alg_set_property(v_this, "Body", alg_widen(v_body, "List")));
    return alg_nil();
}

static Value m_functionstmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitFunctionStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_returnstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Keyword", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    return alg_nil();
}

static Value m_returnstmt_init_2_token_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_keyword = alg_widen(args[0], "Token");
    (void)v_keyword;
    Value v_value = alg_widen(args[1], "Expr");
    (void)v_value;
    (void)(alg_set_property(v_this, "Keyword", alg_widen(v_keyword, "Token")));
    (void)(alg_set_property(v_this, "Value", alg_widen(v_value, "Expr")));
    return alg_nil();
}

static Value m_returnstmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitReturnStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_enumstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Members", alg_nil());
    return alg_nil();
}

static Value m_enumstmt_init_2_token_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_members = alg_widen(args[1], "List");
    (void)v_members;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    (void)(alg_set_property(v_this, "Members", alg_widen(v_members, "List")));
    return alg_nil();
}

static Value m_enumstmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitEnumStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_subrangestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Low", alg_nil());
    alg_set_property(v_this, "High", alg_nil());
    return alg_nil();
}

static Value m_subrangestmt_init_3_token_integer_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_low = alg_widen(args[1], "Integer");
    (void)v_low;
    Value v_high = alg_widen(args[2], "Integer");
    (void)v_high;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    (void)(alg_set_property(v_this, "Low", alg_widen(v_low, "Integer")));
    (void)(alg_set_property(v_this, "High", alg_widen(v_high, "Integer")));
    return alg_nil();
}

static Value m_subrangestmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitSubrangeStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_classstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Superclass", alg_nil());
    alg_set_property(v_this, "Methods", alg_nil());
    alg_set_property(v_this, "Fields", alg_nil());
    alg_set_property(v_this, "PrivateMembers", alg_widen(alg_list(), "List"));
    return alg_nil();
}

static Value m_classstmt_init_4_token_variableexpr_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_superclass = alg_widen(args[1], "VariableExpr");
    (void)v_superclass;
    Value v_methods = alg_widen(args[2], "List");
    (void)v_methods;
    Value v_fields = alg_widen(args[3], "List");
    (void)v_fields;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    (void)(alg_set_property(v_this, "Superclass", alg_widen(v_superclass, "VariableExpr")));
    (void)(alg_set_property(v_this, "Methods", alg_widen(v_methods, "List")));
    (void)(alg_set_property(v_this, "Fields", alg_widen(v_fields, "List")));
    return alg_nil();
}

static Value m_classstmt_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitClassStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

void init_Stmt(void) {
    k_stmt = alg_class("Stmt", alg_nil());
    k_blockstmt = alg_class("BlockStmt", alg_nil());
    k_expressionstmt = alg_class("ExpressionStmt", alg_nil());
    k_varstmt = alg_class("VarStmt", alg_nil());
    k_vargroupstmt = alg_class("VarGroupStmt", alg_nil());
    k_ifstmt = alg_class("IfStmt", alg_nil());
    k_excepthandler = alg_class("ExceptHandler", alg_nil());
    k_objectstmt = alg_class("ObjectStmt", alg_nil());
    k_modulestmt = alg_class("ModuleStmt", alg_nil());
    k_breakstmt = alg_class("BreakStmt", alg_nil());
    k_trystmt = alg_class("TryStmt", alg_nil());
    k_raisestmt = alg_class("RaiseStmt", alg_nil());
    k_forinstmt = alg_class("ForInStmt", alg_nil());
    k_whilestmt = alg_class("WhileStmt", alg_nil());
    k_functionstmt = alg_class("FunctionStmt", alg_nil());
    k_returnstmt = alg_class("ReturnStmt", alg_nil());
    k_enumstmt = alg_class("EnumStmt", alg_nil());
    k_subrangestmt = alg_class("SubrangeStmt", alg_nil());
    k_classstmt = alg_class("ClassStmt", alg_nil());
    alg_class_initializer(k_stmt, i_stmt);
    alg_class_super(k_blockstmt, k_stmt);
    alg_class_field(k_blockstmt, "Statements");
    alg_class_initializer(k_blockstmt, i_blockstmt);
    alg_class_method(k_blockstmt, "Init", m_blockstmt_init_1_list, 1, t_blockstmt_init_1_list);
    alg_class_method(k_blockstmt, "Accept", m_blockstmt_accept_1, 1, t_blockstmt_accept_1);
    alg_class_super(k_expressionstmt, k_stmt);
    alg_class_field(k_expressionstmt, "Expression");
    alg_class_initializer(k_expressionstmt, i_expressionstmt);
    alg_class_method(k_expressionstmt, "Init", m_expressionstmt_init_1_expr, 1, t_expressionstmt_init_1_expr);
    alg_class_method(k_expressionstmt, "Accept", m_expressionstmt_accept_1, 1, t_expressionstmt_accept_1);
    alg_class_super(k_varstmt, k_stmt);
    alg_class_field(k_varstmt, "Name");
    alg_class_field(k_varstmt, "Initializer");
    alg_class_field(k_varstmt, "TypeName");
    alg_class_field(k_varstmt, "IsConstant");
    alg_class_field(k_varstmt, "Generic");
    alg_class_initializer(k_varstmt, i_varstmt);
    alg_class_method(k_varstmt, "Init", m_varstmt_init_2_token_expr, 2, t_varstmt_init_2_token_expr);
    alg_class_method(k_varstmt, "Accept", m_varstmt_accept_1, 1, t_varstmt_accept_1);
    alg_class_super(k_vargroupstmt, k_stmt);
    alg_class_field(k_vargroupstmt, "Names");
    alg_class_field(k_vargroupstmt, "Initializer");
    alg_class_field(k_vargroupstmt, "TypeName");
    alg_class_field(k_vargroupstmt, "Generic");
    alg_class_field(k_vargroupstmt, "IsConstant");
    alg_class_initializer(k_vargroupstmt, i_vargroupstmt);
    alg_class_method(k_vargroupstmt, "Init", m_vargroupstmt_init_2_list_expr, 2, t_vargroupstmt_init_2_list_expr);
    alg_class_method(k_vargroupstmt, "Accept", m_vargroupstmt_accept_1, 1, t_vargroupstmt_accept_1);
    alg_class_super(k_ifstmt, k_stmt);
    alg_class_field(k_ifstmt, "Condition");
    alg_class_field(k_ifstmt, "ThenBranch");
    alg_class_field(k_ifstmt, "ElseBranch");
    alg_class_initializer(k_ifstmt, i_ifstmt);
    alg_class_method(k_ifstmt, "Init", m_ifstmt_init_3_expr_stmt_stmt, 3, t_ifstmt_init_3_expr_stmt_stmt);
    alg_class_method(k_ifstmt, "Accept", m_ifstmt_accept_1, 1, t_ifstmt_accept_1);
    alg_class_field(k_excepthandler, "Name");
    alg_class_field(k_excepthandler, "Body");
    alg_class_initializer(k_excepthandler, i_excepthandler);
    alg_class_method(k_excepthandler, "Init", m_excepthandler_init_2_string_stmt, 2, t_excepthandler_init_2_string_stmt);
    alg_class_super(k_objectstmt, k_stmt);
    alg_class_field(k_objectstmt, "Name");
    alg_class_field(k_objectstmt, "Superclass");
    alg_class_field(k_objectstmt, "Methods");
    alg_class_field(k_objectstmt, "Fields");
    alg_class_field(k_objectstmt, "PrivateMembers");
    alg_class_initializer(k_objectstmt, i_objectstmt);
    alg_class_method(k_objectstmt, "Init", m_objectstmt_init_4_token_variableexpr_list_list, 4, t_objectstmt_init_4_token_variableexpr_list_list);
    alg_class_method(k_objectstmt, "Accept", m_objectstmt_accept_1, 1, t_objectstmt_accept_1);
    alg_class_super(k_modulestmt, k_stmt);
    alg_class_field(k_modulestmt, "Name");
    alg_class_field(k_modulestmt, "Statements");
    alg_class_field(k_modulestmt, "PrivateNames");
    alg_class_field(k_modulestmt, "FileName");
    alg_class_field(k_modulestmt, "UnitName");
    alg_class_initializer(k_modulestmt, i_modulestmt);
    alg_class_method(k_modulestmt, "Init", m_modulestmt_init_3_token_list_list, 3, t_modulestmt_init_3_token_list_list);
    alg_class_method(k_modulestmt, "Accept", m_modulestmt_accept_1, 1, t_modulestmt_accept_1);
    alg_class_super(k_breakstmt, k_stmt);
    alg_class_field(k_breakstmt, "Keyword");
    alg_class_initializer(k_breakstmt, i_breakstmt);
    alg_class_method(k_breakstmt, "Init", m_breakstmt_init_1_token, 1, t_breakstmt_init_1_token);
    alg_class_method(k_breakstmt, "Accept", m_breakstmt_accept_1, 1, t_breakstmt_accept_1);
    alg_class_super(k_trystmt, k_stmt);
    alg_class_field(k_trystmt, "TryBlock");
    alg_class_field(k_trystmt, "Handlers");
    alg_class_initializer(k_trystmt, i_trystmt);
    alg_class_method(k_trystmt, "Init", m_trystmt_init_2_stmt_map, 2, t_trystmt_init_2_stmt_map);
    alg_class_method(k_trystmt, "Accept", m_trystmt_accept_1, 1, t_trystmt_accept_1);
    alg_class_super(k_raisestmt, k_stmt);
    alg_class_field(k_raisestmt, "Keyword");
    alg_class_field(k_raisestmt, "Value");
    alg_class_initializer(k_raisestmt, i_raisestmt);
    alg_class_method(k_raisestmt, "Init", m_raisestmt_init_2_token_expr, 2, t_raisestmt_init_2_token_expr);
    alg_class_method(k_raisestmt, "Accept", m_raisestmt_accept_1, 1, t_raisestmt_accept_1);
    alg_class_super(k_forinstmt, k_stmt);
    alg_class_field(k_forinstmt, "Name");
    alg_class_field(k_forinstmt, "Iterable");
    alg_class_field(k_forinstmt, "Body");
    alg_class_initializer(k_forinstmt, i_forinstmt);
    alg_class_method(k_forinstmt, "Init", m_forinstmt_init_3_token_expr_stmt, 3, t_forinstmt_init_3_token_expr_stmt);
    alg_class_method(k_forinstmt, "Accept", m_forinstmt_accept_1, 1, t_forinstmt_accept_1);
    alg_class_super(k_whilestmt, k_stmt);
    alg_class_field(k_whilestmt, "Condition");
    alg_class_field(k_whilestmt, "Body");
    alg_class_initializer(k_whilestmt, i_whilestmt);
    alg_class_method(k_whilestmt, "Init", m_whilestmt_init_2_expr_stmt, 2, t_whilestmt_init_2_expr_stmt);
    alg_class_method(k_whilestmt, "Accept", m_whilestmt_accept_1, 1, t_whilestmt_accept_1);
    alg_class_super(k_functionstmt, k_stmt);
    alg_class_field(k_functionstmt, "Name");
    alg_class_field(k_functionstmt, "Params");
    alg_class_field(k_functionstmt, "Body");
    alg_class_field(k_functionstmt, "ReturnType");
    alg_class_field(k_functionstmt, "ParamTypes");
    alg_class_field(k_functionstmt, "ParamGenerics");
    alg_class_field(k_functionstmt, "ReturnGeneric");
    alg_class_initializer(k_functionstmt, i_functionstmt);
    alg_class_method(k_functionstmt, "Init", m_functionstmt_init_3_token_list_list, 3, t_functionstmt_init_3_token_list_list);
    alg_class_method(k_functionstmt, "Accept", m_functionstmt_accept_1, 1, t_functionstmt_accept_1);
    alg_class_super(k_returnstmt, k_stmt);
    alg_class_field(k_returnstmt, "Keyword");
    alg_class_field(k_returnstmt, "Value");
    alg_class_initializer(k_returnstmt, i_returnstmt);
    alg_class_method(k_returnstmt, "Init", m_returnstmt_init_2_token_expr, 2, t_returnstmt_init_2_token_expr);
    alg_class_method(k_returnstmt, "Accept", m_returnstmt_accept_1, 1, t_returnstmt_accept_1);
    alg_class_super(k_enumstmt, k_stmt);
    alg_class_field(k_enumstmt, "Name");
    alg_class_field(k_enumstmt, "Members");
    alg_class_initializer(k_enumstmt, i_enumstmt);
    alg_class_method(k_enumstmt, "Init", m_enumstmt_init_2_token_list, 2, t_enumstmt_init_2_token_list);
    alg_class_method(k_enumstmt, "Accept", m_enumstmt_accept_1, 1, t_enumstmt_accept_1);
    alg_class_super(k_subrangestmt, k_stmt);
    alg_class_field(k_subrangestmt, "Name");
    alg_class_field(k_subrangestmt, "Low");
    alg_class_field(k_subrangestmt, "High");
    alg_class_initializer(k_subrangestmt, i_subrangestmt);
    alg_class_method(k_subrangestmt, "Init", m_subrangestmt_init_3_token_integer_integer, 3, t_subrangestmt_init_3_token_integer_integer);
    alg_class_method(k_subrangestmt, "Accept", m_subrangestmt_accept_1, 1, t_subrangestmt_accept_1);
    alg_class_super(k_classstmt, k_stmt);
    alg_class_field(k_classstmt, "Name");
    alg_class_field(k_classstmt, "Superclass");
    alg_class_field(k_classstmt, "Methods");
    alg_class_field(k_classstmt, "Fields");
    alg_class_field(k_classstmt, "PrivateMembers");
    alg_class_initializer(k_classstmt, i_classstmt);
    alg_class_method(k_classstmt, "Init", m_classstmt_init_4_token_variableexpr_list_list, 4, t_classstmt_init_4_token_variableexpr_list_list);
    alg_class_method(k_classstmt, "Accept", m_classstmt_accept_1, 1, t_classstmt_accept_1);
}
