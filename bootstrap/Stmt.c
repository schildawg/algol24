/* Generated from Algol-24.  Do not edit. */
#include "Stmt.h"
#include "Expr.h"
#include "Token.h"

Value k_Stmt;
Value k_PrintStmt;
static const char *t_PrintStmt_Init_1_Expr[] = { "Expr" };
static const char *t_PrintStmt_Accept_1[] = { "Any" };
Value k_BlockStmt;
static const char *t_BlockStmt_Init_1_List[] = { "List" };
static const char *t_BlockStmt_Accept_1[] = { "Any" };
Value k_ExpressionStmt;
static const char *t_ExpressionStmt_Init_1_Expr[] = { "Expr" };
static const char *t_ExpressionStmt_Accept_1[] = { "Any" };
Value k_VarStmt;
static const char *t_VarStmt_Init_2_Token_Expr[] = { "Token", "Expr" };
static const char *t_VarStmt_Accept_1[] = { "Any" };
Value k_VarGroupStmt;
static const char *t_VarGroupStmt_Init_2_List_Expr[] = { "List", "Expr" };
static const char *t_VarGroupStmt_Accept_1[] = { "Any" };
Value k_IfStmt;
static const char *t_IfStmt_Init_3_Expr_Stmt_Stmt[] = { "Expr", "Stmt", "Stmt" };
static const char *t_IfStmt_Accept_1[] = { "Any" };
Value k_ExceptHandler;
static const char *t_ExceptHandler_Init_2_String_Stmt[] = { "String", "Stmt" };
Value k_ObjectStmt;
static const char *t_ObjectStmt_Init_4_Token_VariableExpr_List_List[] = { "Token", "VariableExpr", "List", "List" };
static const char *t_ObjectStmt_Accept_1[] = { "Any" };
Value k_ModuleStmt;
static const char *t_ModuleStmt_Init_3_Token_List_List[] = { "Token", "List", "List" };
static const char *t_ModuleStmt_Accept_1[] = { "Any" };
Value k_BreakStmt;
static const char *t_BreakStmt_Init_1_Token[] = { "Token" };
static const char *t_BreakStmt_Accept_1[] = { "Any" };
Value k_TryStmt;
static const char *t_TryStmt_Init_2_Stmt_Map[] = { "Stmt", "Map" };
static const char *t_TryStmt_Accept_1[] = { "Any" };
Value k_RaiseStmt;
static const char *t_RaiseStmt_Init_2_Token_Expr[] = { "Token", "Expr" };
static const char *t_RaiseStmt_Accept_1[] = { "Any" };
Value k_ForInStmt;
static const char *t_ForInStmt_Init_3_Token_Expr_Stmt[] = { "Token", "Expr", "Stmt" };
static const char *t_ForInStmt_Accept_1[] = { "Any" };
Value k_WhileStmt;
static const char *t_WhileStmt_Init_2_Expr_Stmt[] = { "Expr", "Stmt" };
static const char *t_WhileStmt_Accept_1[] = { "Any" };
Value k_FunctionStmt;
static const char *t_FunctionStmt_Init_3_Token_List_List[] = { "Token", "List", "List" };
static const char *t_FunctionStmt_Accept_1[] = { "Any" };
Value k_ReturnStmt;
static const char *t_ReturnStmt_Init_2_Token_Expr[] = { "Token", "Expr" };
static const char *t_ReturnStmt_Accept_1[] = { "Any" };
Value k_EnumStmt;
static const char *t_EnumStmt_Init_2_Token_List[] = { "Token", "List" };
static const char *t_EnumStmt_Accept_1[] = { "Any" };
Value k_ClassStmt;
static const char *t_ClassStmt_Init_4_Token_VariableExpr_List_List[] = { "Token", "VariableExpr", "List", "List" };
static const char *t_ClassStmt_Accept_1[] = { "Any" };

static Value i_Stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value i_PrintStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Expression", alg_nil());
    return alg_nil();
}

static Value m_PrintStmt_Init_1_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Expression = args[0];
    (void)v_Expression;
    (void)(alg_set_property(v_this, "Expression", v_Expression));
    return alg_nil();
}

static Value m_PrintStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitPrintStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_BlockStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Statements", alg_nil());
    return alg_nil();
}

static Value m_BlockStmt_Init_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    (void)(alg_set_property(v_this, "Statements", v_Statements));
    return alg_nil();
}

static Value m_BlockStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitBlockStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_ExpressionStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Expression", alg_nil());
    return alg_nil();
}

static Value m_ExpressionStmt_Init_1_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Expression = args[0];
    (void)v_Expression;
    (void)(alg_set_property(v_this, "Expression", v_Expression));
    return alg_nil();
}

static Value m_ExpressionStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitExpressionStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_VarStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Initializer", alg_nil());
    alg_set_property(v_this, "TypeName", alg_string(""));
    alg_set_property(v_this, "IsConstant", alg_bool(false));
    alg_set_property(v_this, "Generic", alg_string(""));
    return alg_nil();
}

static Value m_VarStmt_Init_2_Token_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Initializer = args[1];
    (void)v_Initializer;
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Initializer", v_Initializer));
    return alg_nil();
}

static Value m_VarStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitVarStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_VarGroupStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Names", alg_nil());
    alg_set_property(v_this, "Initializer", alg_nil());
    alg_set_property(v_this, "TypeName", alg_string(""));
    alg_set_property(v_this, "Generic", alg_string(""));
    alg_set_property(v_this, "IsConstant", alg_bool(false));
    return alg_nil();
}

static Value m_VarGroupStmt_Init_2_List_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Names = args[0];
    (void)v_Names;
    Value v_Initializer = args[1];
    (void)v_Initializer;
    (void)(alg_set_property(v_this, "Names", v_Names));
    (void)(alg_set_property(v_this, "Initializer", v_Initializer));
    return alg_nil();
}

static Value m_VarGroupStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitVarGroupStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_IfStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Condition", alg_nil());
    alg_set_property(v_this, "ThenBranch", alg_nil());
    alg_set_property(v_this, "ElseBranch", alg_nil());
    return alg_nil();
}

static Value m_IfStmt_Init_3_Expr_Stmt_Stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Condition = args[0];
    (void)v_Condition;
    Value v_ThenBranch = args[1];
    (void)v_ThenBranch;
    Value v_ElseBranch = args[2];
    (void)v_ElseBranch;
    (void)(alg_set_property(v_this, "Condition", v_Condition));
    (void)(alg_set_property(v_this, "ThenBranch", v_ThenBranch));
    (void)(alg_set_property(v_this, "ElseBranch", v_ElseBranch));
    return alg_nil();
}

static Value m_IfStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitIfStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_ExceptHandler(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Body", alg_nil());
    return alg_nil();
}

static Value m_ExceptHandler_Init_2_String_Stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Body = args[1];
    (void)v_Body;
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Body", v_Body));
    return alg_nil();
}

static Value i_ObjectStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Superclass", alg_nil());
    alg_set_property(v_this, "Methods", alg_nil());
    alg_set_property(v_this, "Fields", alg_nil());
    alg_set_property(v_this, "PrivateMembers", alg_list());
    return alg_nil();
}

static Value m_ObjectStmt_Init_4_Token_VariableExpr_List_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Superclass = args[1];
    (void)v_Superclass;
    Value v_Methods = args[2];
    (void)v_Methods;
    Value v_Fields = args[3];
    (void)v_Fields;
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Superclass", v_Superclass));
    (void)(alg_set_property(v_this, "Methods", v_Methods));
    (void)(alg_set_property(v_this, "Fields", v_Fields));
    return alg_nil();
}

static Value m_ObjectStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitObjectStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_ModuleStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Statements", alg_nil());
    alg_set_property(v_this, "PrivateNames", alg_nil());
    alg_set_property(v_this, "FileName", alg_string(""));
    return alg_nil();
}

static Value m_ModuleStmt_Init_3_Token_List_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Statements = args[1];
    (void)v_Statements;
    Value v_PrivateNames = args[2];
    (void)v_PrivateNames;
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Statements", v_Statements));
    (void)(alg_set_property(v_this, "PrivateNames", v_PrivateNames));
    return alg_nil();
}

static Value m_ModuleStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitModuleStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_BreakStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Keyword", alg_nil());
    return alg_nil();
}

static Value m_BreakStmt_Init_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Keyword = args[0];
    (void)v_Keyword;
    (void)(alg_set_property(v_this, "Keyword", v_Keyword));
    return alg_nil();
}

static Value m_BreakStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitBreakStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_TryStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "TryBlock", alg_nil());
    alg_set_property(v_this, "Handlers", alg_nil());
    return alg_nil();
}

static Value m_TryStmt_Init_2_Stmt_Map(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TryBlock = args[0];
    (void)v_TryBlock;
    Value v_Handlers = args[1];
    (void)v_Handlers;
    (void)(alg_set_property(v_this, "TryBlock", v_TryBlock));
    (void)(alg_set_property(v_this, "Handlers", v_Handlers));
    return alg_nil();
}

static Value m_TryStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitTryStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_RaiseStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Keyword", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    return alg_nil();
}

static Value m_RaiseStmt_Init_2_Token_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Keyword = args[0];
    (void)v_Keyword;
    Value v_Value = args[1];
    (void)v_Value;
    (void)(alg_set_property(v_this, "Keyword", v_Keyword));
    (void)(alg_set_property(v_this, "Value", v_Value));
    return alg_nil();
}

static Value m_RaiseStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitRaiseStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_ForInStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Iterable", alg_nil());
    alg_set_property(v_this, "Body", alg_nil());
    return alg_nil();
}

static Value m_ForInStmt_Init_3_Token_Expr_Stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Iterable = args[1];
    (void)v_Iterable;
    Value v_Body = args[2];
    (void)v_Body;
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Iterable", v_Iterable));
    (void)(alg_set_property(v_this, "Body", v_Body));
    return alg_nil();
}

static Value m_ForInStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitForInStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_WhileStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Condition", alg_nil());
    alg_set_property(v_this, "Body", alg_nil());
    return alg_nil();
}

static Value m_WhileStmt_Init_2_Expr_Stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Condition = args[0];
    (void)v_Condition;
    Value v_Body = args[1];
    (void)v_Body;
    (void)(alg_set_property(v_this, "Condition", v_Condition));
    (void)(alg_set_property(v_this, "Body", v_Body));
    return alg_nil();
}

static Value m_WhileStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitWhileStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_FunctionStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Params", alg_nil());
    alg_set_property(v_this, "Body", alg_nil());
    alg_set_property(v_this, "ReturnType", alg_string(""));
    alg_set_property(v_this, "ParamTypes", alg_list());
    return alg_nil();
}

static Value m_FunctionStmt_Init_3_Token_List_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Params = args[1];
    (void)v_Params;
    Value v_Body = args[2];
    (void)v_Body;
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Params", v_Params));
    (void)(alg_set_property(v_this, "Body", v_Body));
    return alg_nil();
}

static Value m_FunctionStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitFunctionStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_ReturnStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Keyword", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    return alg_nil();
}

static Value m_ReturnStmt_Init_2_Token_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Keyword = args[0];
    (void)v_Keyword;
    Value v_Value = args[1];
    (void)v_Value;
    (void)(alg_set_property(v_this, "Keyword", v_Keyword));
    (void)(alg_set_property(v_this, "Value", v_Value));
    return alg_nil();
}

static Value m_ReturnStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitReturnStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_EnumStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Members", alg_nil());
    return alg_nil();
}

static Value m_EnumStmt_Init_2_Token_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Members = args[1];
    (void)v_Members;
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Members", v_Members));
    return alg_nil();
}

static Value m_EnumStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitEnumStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_ClassStmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Superclass", alg_nil());
    alg_set_property(v_this, "Methods", alg_nil());
    alg_set_property(v_this, "Fields", alg_nil());
    alg_set_property(v_this, "PrivateMembers", alg_list());
    return alg_nil();
}

static Value m_ClassStmt_Init_4_Token_VariableExpr_List_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Superclass = args[1];
    (void)v_Superclass;
    Value v_Methods = args[2];
    (void)v_Methods;
    Value v_Fields = args[3];
    (void)v_Fields;
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Superclass", v_Superclass));
    (void)(alg_set_property(v_this, "Methods", v_Methods));
    (void)(alg_set_property(v_this, "Fields", v_Fields));
    return alg_nil();
}

static Value m_ClassStmt_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitClassStmt", (Value[]){v_this}, 1);
    return alg_nil();
}

void init_Stmt(void) {
    k_Stmt = alg_class("Stmt", alg_nil());
    alg_class_initializer(k_Stmt, i_Stmt);
    k_PrintStmt = alg_class("PrintStmt", k_Stmt);
    alg_class_field(k_PrintStmt, "Expression");
    alg_class_initializer(k_PrintStmt, i_PrintStmt);
    alg_class_method(k_PrintStmt, "Init", m_PrintStmt_Init_1_Expr, 1, t_PrintStmt_Init_1_Expr);
    alg_class_method(k_PrintStmt, "Accept", m_PrintStmt_Accept_1, 1, t_PrintStmt_Accept_1);
    k_BlockStmt = alg_class("BlockStmt", k_Stmt);
    alg_class_field(k_BlockStmt, "Statements");
    alg_class_initializer(k_BlockStmt, i_BlockStmt);
    alg_class_method(k_BlockStmt, "Init", m_BlockStmt_Init_1_List, 1, t_BlockStmt_Init_1_List);
    alg_class_method(k_BlockStmt, "Accept", m_BlockStmt_Accept_1, 1, t_BlockStmt_Accept_1);
    k_ExpressionStmt = alg_class("ExpressionStmt", k_Stmt);
    alg_class_field(k_ExpressionStmt, "Expression");
    alg_class_initializer(k_ExpressionStmt, i_ExpressionStmt);
    alg_class_method(k_ExpressionStmt, "Init", m_ExpressionStmt_Init_1_Expr, 1, t_ExpressionStmt_Init_1_Expr);
    alg_class_method(k_ExpressionStmt, "Accept", m_ExpressionStmt_Accept_1, 1, t_ExpressionStmt_Accept_1);
    k_VarStmt = alg_class("VarStmt", k_Stmt);
    alg_class_field(k_VarStmt, "Name");
    alg_class_field(k_VarStmt, "Initializer");
    alg_class_field(k_VarStmt, "TypeName");
    alg_class_field(k_VarStmt, "IsConstant");
    alg_class_field(k_VarStmt, "Generic");
    alg_class_initializer(k_VarStmt, i_VarStmt);
    alg_class_method(k_VarStmt, "Init", m_VarStmt_Init_2_Token_Expr, 2, t_VarStmt_Init_2_Token_Expr);
    alg_class_method(k_VarStmt, "Accept", m_VarStmt_Accept_1, 1, t_VarStmt_Accept_1);
    k_VarGroupStmt = alg_class("VarGroupStmt", k_Stmt);
    alg_class_field(k_VarGroupStmt, "Names");
    alg_class_field(k_VarGroupStmt, "Initializer");
    alg_class_field(k_VarGroupStmt, "TypeName");
    alg_class_field(k_VarGroupStmt, "Generic");
    alg_class_field(k_VarGroupStmt, "IsConstant");
    alg_class_initializer(k_VarGroupStmt, i_VarGroupStmt);
    alg_class_method(k_VarGroupStmt, "Init", m_VarGroupStmt_Init_2_List_Expr, 2, t_VarGroupStmt_Init_2_List_Expr);
    alg_class_method(k_VarGroupStmt, "Accept", m_VarGroupStmt_Accept_1, 1, t_VarGroupStmt_Accept_1);
    k_IfStmt = alg_class("IfStmt", k_Stmt);
    alg_class_field(k_IfStmt, "Condition");
    alg_class_field(k_IfStmt, "ThenBranch");
    alg_class_field(k_IfStmt, "ElseBranch");
    alg_class_initializer(k_IfStmt, i_IfStmt);
    alg_class_method(k_IfStmt, "Init", m_IfStmt_Init_3_Expr_Stmt_Stmt, 3, t_IfStmt_Init_3_Expr_Stmt_Stmt);
    alg_class_method(k_IfStmt, "Accept", m_IfStmt_Accept_1, 1, t_IfStmt_Accept_1);
    k_ExceptHandler = alg_class("ExceptHandler", alg_nil());
    alg_class_field(k_ExceptHandler, "Name");
    alg_class_field(k_ExceptHandler, "Body");
    alg_class_initializer(k_ExceptHandler, i_ExceptHandler);
    alg_class_method(k_ExceptHandler, "Init", m_ExceptHandler_Init_2_String_Stmt, 2, t_ExceptHandler_Init_2_String_Stmt);
    k_ObjectStmt = alg_class("ObjectStmt", k_Stmt);
    alg_class_field(k_ObjectStmt, "Name");
    alg_class_field(k_ObjectStmt, "Superclass");
    alg_class_field(k_ObjectStmt, "Methods");
    alg_class_field(k_ObjectStmt, "Fields");
    alg_class_field(k_ObjectStmt, "PrivateMembers");
    alg_class_initializer(k_ObjectStmt, i_ObjectStmt);
    alg_class_method(k_ObjectStmt, "Init", m_ObjectStmt_Init_4_Token_VariableExpr_List_List, 4, t_ObjectStmt_Init_4_Token_VariableExpr_List_List);
    alg_class_method(k_ObjectStmt, "Accept", m_ObjectStmt_Accept_1, 1, t_ObjectStmt_Accept_1);
    k_ModuleStmt = alg_class("ModuleStmt", k_Stmt);
    alg_class_field(k_ModuleStmt, "Name");
    alg_class_field(k_ModuleStmt, "Statements");
    alg_class_field(k_ModuleStmt, "PrivateNames");
    alg_class_field(k_ModuleStmt, "FileName");
    alg_class_initializer(k_ModuleStmt, i_ModuleStmt);
    alg_class_method(k_ModuleStmt, "Init", m_ModuleStmt_Init_3_Token_List_List, 3, t_ModuleStmt_Init_3_Token_List_List);
    alg_class_method(k_ModuleStmt, "Accept", m_ModuleStmt_Accept_1, 1, t_ModuleStmt_Accept_1);
    k_BreakStmt = alg_class("BreakStmt", k_Stmt);
    alg_class_field(k_BreakStmt, "Keyword");
    alg_class_initializer(k_BreakStmt, i_BreakStmt);
    alg_class_method(k_BreakStmt, "Init", m_BreakStmt_Init_1_Token, 1, t_BreakStmt_Init_1_Token);
    alg_class_method(k_BreakStmt, "Accept", m_BreakStmt_Accept_1, 1, t_BreakStmt_Accept_1);
    k_TryStmt = alg_class("TryStmt", k_Stmt);
    alg_class_field(k_TryStmt, "TryBlock");
    alg_class_field(k_TryStmt, "Handlers");
    alg_class_initializer(k_TryStmt, i_TryStmt);
    alg_class_method(k_TryStmt, "Init", m_TryStmt_Init_2_Stmt_Map, 2, t_TryStmt_Init_2_Stmt_Map);
    alg_class_method(k_TryStmt, "Accept", m_TryStmt_Accept_1, 1, t_TryStmt_Accept_1);
    k_RaiseStmt = alg_class("RaiseStmt", k_Stmt);
    alg_class_field(k_RaiseStmt, "Keyword");
    alg_class_field(k_RaiseStmt, "Value");
    alg_class_initializer(k_RaiseStmt, i_RaiseStmt);
    alg_class_method(k_RaiseStmt, "Init", m_RaiseStmt_Init_2_Token_Expr, 2, t_RaiseStmt_Init_2_Token_Expr);
    alg_class_method(k_RaiseStmt, "Accept", m_RaiseStmt_Accept_1, 1, t_RaiseStmt_Accept_1);
    k_ForInStmt = alg_class("ForInStmt", k_Stmt);
    alg_class_field(k_ForInStmt, "Name");
    alg_class_field(k_ForInStmt, "Iterable");
    alg_class_field(k_ForInStmt, "Body");
    alg_class_initializer(k_ForInStmt, i_ForInStmt);
    alg_class_method(k_ForInStmt, "Init", m_ForInStmt_Init_3_Token_Expr_Stmt, 3, t_ForInStmt_Init_3_Token_Expr_Stmt);
    alg_class_method(k_ForInStmt, "Accept", m_ForInStmt_Accept_1, 1, t_ForInStmt_Accept_1);
    k_WhileStmt = alg_class("WhileStmt", k_Stmt);
    alg_class_field(k_WhileStmt, "Condition");
    alg_class_field(k_WhileStmt, "Body");
    alg_class_initializer(k_WhileStmt, i_WhileStmt);
    alg_class_method(k_WhileStmt, "Init", m_WhileStmt_Init_2_Expr_Stmt, 2, t_WhileStmt_Init_2_Expr_Stmt);
    alg_class_method(k_WhileStmt, "Accept", m_WhileStmt_Accept_1, 1, t_WhileStmt_Accept_1);
    k_FunctionStmt = alg_class("FunctionStmt", k_Stmt);
    alg_class_field(k_FunctionStmt, "Name");
    alg_class_field(k_FunctionStmt, "Params");
    alg_class_field(k_FunctionStmt, "Body");
    alg_class_field(k_FunctionStmt, "ReturnType");
    alg_class_field(k_FunctionStmt, "ParamTypes");
    alg_class_initializer(k_FunctionStmt, i_FunctionStmt);
    alg_class_method(k_FunctionStmt, "Init", m_FunctionStmt_Init_3_Token_List_List, 3, t_FunctionStmt_Init_3_Token_List_List);
    alg_class_method(k_FunctionStmt, "Accept", m_FunctionStmt_Accept_1, 1, t_FunctionStmt_Accept_1);
    k_ReturnStmt = alg_class("ReturnStmt", k_Stmt);
    alg_class_field(k_ReturnStmt, "Keyword");
    alg_class_field(k_ReturnStmt, "Value");
    alg_class_initializer(k_ReturnStmt, i_ReturnStmt);
    alg_class_method(k_ReturnStmt, "Init", m_ReturnStmt_Init_2_Token_Expr, 2, t_ReturnStmt_Init_2_Token_Expr);
    alg_class_method(k_ReturnStmt, "Accept", m_ReturnStmt_Accept_1, 1, t_ReturnStmt_Accept_1);
    k_EnumStmt = alg_class("EnumStmt", k_Stmt);
    alg_class_field(k_EnumStmt, "Name");
    alg_class_field(k_EnumStmt, "Members");
    alg_class_initializer(k_EnumStmt, i_EnumStmt);
    alg_class_method(k_EnumStmt, "Init", m_EnumStmt_Init_2_Token_List, 2, t_EnumStmt_Init_2_Token_List);
    alg_class_method(k_EnumStmt, "Accept", m_EnumStmt_Accept_1, 1, t_EnumStmt_Accept_1);
    k_ClassStmt = alg_class("ClassStmt", k_Stmt);
    alg_class_field(k_ClassStmt, "Name");
    alg_class_field(k_ClassStmt, "Superclass");
    alg_class_field(k_ClassStmt, "Methods");
    alg_class_field(k_ClassStmt, "Fields");
    alg_class_field(k_ClassStmt, "PrivateMembers");
    alg_class_initializer(k_ClassStmt, i_ClassStmt);
    alg_class_method(k_ClassStmt, "Init", m_ClassStmt_Init_4_Token_VariableExpr_List_List, 4, t_ClassStmt_Init_4_Token_VariableExpr_List_List);
    alg_class_method(k_ClassStmt, "Accept", m_ClassStmt_Accept_1, 1, t_ClassStmt_Accept_1);
}
