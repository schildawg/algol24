/* Generated from Algol-24.  Do not edit. */
#include "Expr.h"
#include "Token.h"

Value k_Expr;
Value k_BinaryExpr;
static const char *t_BinaryExpr_Init_3[] = { "Any", "Any", "Any" };
static const char *t_BinaryExpr_Accept_1[] = { "Any" };
Value k_LogicalExpr;
static const char *t_LogicalExpr_Init_3[] = { "Any", "Any", "Any" };
static const char *t_LogicalExpr_Accept_1[] = { "Any" };
Value k_GroupingExpr;
static const char *t_GroupingExpr_Init_1_Expr[] = { "Expr" };
static const char *t_GroupingExpr_Accept_1[] = { "Any" };
Value k_CollectionExpr;
static const char *t_CollectionExpr_Init_3_Boolean_List_List[] = { "Boolean", "List", "List" };
static const char *t_CollectionExpr_Accept_1[] = { "Any" };
Value k_SubscriptExpr;
static const char *t_SubscriptExpr_Init_3_Expr_Expr_Token[] = { "Expr", "Expr", "Token" };
static const char *t_SubscriptExpr_Accept_1[] = { "Any" };
Value k_SetSubscriptExpr;
static const char *t_SetSubscriptExpr_Init_4_Expr_Expr_Expr_Token[] = { "Expr", "Expr", "Expr", "Token" };
static const char *t_SetSubscriptExpr_Accept_1[] = { "Any" };
Value k_LiteralExpr;
static const char *t_LiteralExpr_Init_1_Expr[] = { "Expr" };
static const char *t_LiteralExpr_Accept_1[] = { "Any" };
Value k_VariableExpr;
static const char *t_VariableExpr_Init_1_Token[] = { "Token" };
static const char *t_VariableExpr_Accept_1[] = { "Any" };
Value k_AssignExpr;
static const char *t_AssignExpr_Init_2_Token_Expr[] = { "Token", "Expr" };
static const char *t_AssignExpr_Accept_1[] = { "Any" };
Value k_UnaryExpr;
static const char *t_UnaryExpr_Init_2_Token_Expr[] = { "Token", "Expr" };
static const char *t_UnaryExpr_Accept_1[] = { "Any" };
Value k_CallExpr;
static const char *t_CallExpr_Init_3_Expr_Token_List[] = { "Expr", "Token", "List" };
static const char *t_CallExpr_Accept_1[] = { "Any" };
Value k_GetExpr;
static const char *t_GetExpr_Init_2_Expr_Token[] = { "Expr", "Token" };
static const char *t_GetExpr_Accept_1[] = { "Any" };
Value k_SetExpr;
static const char *t_SetExpr_Init_3_Expr_Token_Expr[] = { "Expr", "Token", "Expr" };
static const char *t_SetExpr_Accept_1[] = { "Any" };
Value k_ThisExpr;
static const char *t_ThisExpr_Init_1_Token[] = { "Token" };
static const char *t_ThisExpr_Accept_1[] = { "Any" };
Value k_SuperExpr;
static const char *t_SuperExpr_Init_2_Token_Token[] = { "Token", "Token" };
static const char *t_SuperExpr_Accept_1[] = { "Any" };
Value k_IsExpr;
static const char *t_IsExpr_Init_2_Expr_Token[] = { "Expr", "Token" };
static const char *t_IsExpr_Accept_1[] = { "Any" };

static Value i_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Cast", alg_string(""));
    return alg_nil();
}

static Value i_BinaryExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Left", alg_nil());
    alg_set_property(v_this, "Op", alg_nil());
    alg_set_property(v_this, "Right", alg_nil());
    return alg_nil();
}

static Value m_BinaryExpr_Init_3(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Left = args[0];
    (void)v_Left;
    Value v_Op = args[1];
    (void)v_Op;
    Value v_Right = args[2];
    (void)v_Right;
    (void)(alg_set_property(v_this, "Left", v_Left));
    (void)(alg_set_property(v_this, "Op", v_Op));
    (void)(alg_set_property(v_this, "Right", v_Right));
    return alg_nil();
}

static Value m_BinaryExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitBinary", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_LogicalExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Left", alg_nil());
    alg_set_property(v_this, "Op", alg_nil());
    alg_set_property(v_this, "Right", alg_nil());
    return alg_nil();
}

static Value m_LogicalExpr_Init_3(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Left = args[0];
    (void)v_Left;
    Value v_Op = args[1];
    (void)v_Op;
    Value v_Right = args[2];
    (void)v_Right;
    (void)(alg_set_property(v_this, "Left", v_Left));
    (void)(alg_set_property(v_this, "Op", v_Op));
    (void)(alg_set_property(v_this, "Right", v_Right));
    return alg_nil();
}

static Value m_LogicalExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitLogical", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_GroupingExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Expression", alg_nil());
    return alg_nil();
}

static Value m_GroupingExpr_Init_1_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Expression = args[0];
    (void)v_Expression;
    (void)(alg_set_property(v_this, "Expression", v_Expression));
    return alg_nil();
}

static Value m_GroupingExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitGrouping", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_CollectionExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "IsMap", alg_nil());
    alg_set_property(v_this, "Keys", alg_nil());
    alg_set_property(v_this, "Values", alg_nil());
    return alg_nil();
}

static Value m_CollectionExpr_Init_3_Boolean_List_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_IsMap = args[0];
    (void)v_IsMap;
    Value v_Keys = args[1];
    (void)v_Keys;
    Value v_Values = args[2];
    (void)v_Values;
    (void)(alg_set_property(v_this, "IsMap", v_IsMap));
    (void)(alg_set_property(v_this, "Keys", v_Keys));
    (void)(alg_set_property(v_this, "Values", v_Values));
    return alg_nil();
}

static Value m_CollectionExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitCollectionExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_SubscriptExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "Index", alg_nil());
    alg_set_property(v_this, "Bracket", alg_nil());
    return alg_nil();
}

static Value m_SubscriptExpr_Init_3_Expr_Expr_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Obj = args[0];
    (void)v_Obj;
    Value v_Index = args[1];
    (void)v_Index;
    Value v_Bracket = args[2];
    (void)v_Bracket;
    (void)(alg_set_property(v_this, "Obj", v_Obj));
    (void)(alg_set_property(v_this, "Index", v_Index));
    (void)(alg_set_property(v_this, "Bracket", v_Bracket));
    return alg_nil();
}

static Value m_SubscriptExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitSubscriptExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_SetSubscriptExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "Index", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    alg_set_property(v_this, "Bracket", alg_nil());
    return alg_nil();
}

static Value m_SetSubscriptExpr_Init_4_Expr_Expr_Expr_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Obj = args[0];
    (void)v_Obj;
    Value v_Index = args[1];
    (void)v_Index;
    Value v_Value = args[2];
    (void)v_Value;
    Value v_Bracket = args[3];
    (void)v_Bracket;
    (void)(alg_set_property(v_this, "Obj", v_Obj));
    (void)(alg_set_property(v_this, "Index", v_Index));
    (void)(alg_set_property(v_this, "Value", v_Value));
    (void)(alg_set_property(v_this, "Bracket", v_Bracket));
    return alg_nil();
}

static Value m_SetSubscriptExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitSetSubscriptExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_LiteralExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Value", alg_nil());
    return alg_nil();
}

static Value m_LiteralExpr_Init_1_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Value = args[0];
    (void)v_Value;
    (void)(alg_set_property(v_this, "Value", v_Value));
    return alg_nil();
}

static Value m_LiteralExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitLiteral", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_VariableExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    return alg_nil();
}

static Value m_VariableExpr_Init_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    (void)(alg_set_property(v_this, "Name", v_Name));
    return alg_nil();
}

static Value m_VariableExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitVariableExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_AssignExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    return alg_nil();
}

static Value m_AssignExpr_Init_2_Token_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Value = args[1];
    (void)v_Value;
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Value", v_Value));
    return alg_nil();
}

static Value m_AssignExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitAssignExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_UnaryExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Op", alg_nil());
    alg_set_property(v_this, "Right", alg_nil());
    return alg_nil();
}

static Value m_UnaryExpr_Init_2_Token_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Op = args[0];
    (void)v_Op;
    Value v_Right = args[1];
    (void)v_Right;
    (void)(alg_set_property(v_this, "Op", v_Op));
    (void)(alg_set_property(v_this, "Right", v_Right));
    return alg_nil();
}

static Value m_UnaryExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitUnary", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_CallExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Callee", alg_nil());
    alg_set_property(v_this, "Paren", alg_nil());
    alg_set_property(v_this, "Arguments", alg_nil());
    return alg_nil();
}

static Value m_CallExpr_Init_3_Expr_Token_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Callee = args[0];
    (void)v_Callee;
    Value v_Paren = args[1];
    (void)v_Paren;
    Value v_Arguments = args[2];
    (void)v_Arguments;
    (void)(alg_set_property(v_this, "Callee", v_Callee));
    (void)(alg_set_property(v_this, "Paren", v_Paren));
    (void)(alg_set_property(v_this, "Arguments", v_Arguments));
    return alg_nil();
}

static Value m_CallExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitCall", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_GetExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    return alg_nil();
}

static Value m_GetExpr_Init_2_Expr_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Obj = args[0];
    (void)v_Obj;
    Value v_Name = args[1];
    (void)v_Name;
    (void)(alg_set_property(v_this, "Obj", v_Obj));
    (void)(alg_set_property(v_this, "Name", v_Name));
    return alg_nil();
}

static Value m_GetExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitGetExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_SetExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    return alg_nil();
}

static Value m_SetExpr_Init_3_Expr_Token_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Obj = args[0];
    (void)v_Obj;
    Value v_Name = args[1];
    (void)v_Name;
    Value v_Value = args[2];
    (void)v_Value;
    (void)(alg_set_property(v_this, "Obj", v_Obj));
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Value", v_Value));
    return alg_nil();
}

static Value m_SetExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitSetExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_ThisExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Keyword", alg_nil());
    return alg_nil();
}

static Value m_ThisExpr_Init_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Keyword = args[0];
    (void)v_Keyword;
    (void)(alg_set_property(v_this, "Keyword", v_Keyword));
    return alg_nil();
}

static Value m_ThisExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitThisExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_SuperExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Keyword", alg_nil());
    alg_set_property(v_this, "Method", alg_nil());
    return alg_nil();
}

static Value m_SuperExpr_Init_2_Token_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Keyword = args[0];
    (void)v_Keyword;
    Value v_Method = args[1];
    (void)v_Method;
    (void)(alg_set_property(v_this, "Keyword", v_Keyword));
    (void)(alg_set_property(v_this, "Method", v_Method));
    return alg_nil();
}

static Value m_SuperExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitSuperExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_IsExpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "TypeName", alg_nil());
    return alg_nil();
}

static Value m_IsExpr_Init_2_Expr_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Obj = args[0];
    (void)v_Obj;
    Value v_TypeName = args[1];
    (void)v_TypeName;
    (void)(alg_set_property(v_this, "Obj", v_Obj));
    (void)(alg_set_property(v_this, "TypeName", v_TypeName));
    return alg_nil();
}

static Value m_IsExpr_Accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Visitor = args[0];
    (void)v_Visitor;
    return alg_invoke(v_Visitor, "VisitIsExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

void init_Expr(void) {
    k_Expr = alg_class("Expr", alg_nil());
    alg_class_field(k_Expr, "Cast");
    alg_class_initializer(k_Expr, i_Expr);
    k_BinaryExpr = alg_class("BinaryExpr", k_Expr);
    alg_class_field(k_BinaryExpr, "Left");
    alg_class_field(k_BinaryExpr, "Op");
    alg_class_field(k_BinaryExpr, "Right");
    alg_class_initializer(k_BinaryExpr, i_BinaryExpr);
    alg_class_method(k_BinaryExpr, "Init", m_BinaryExpr_Init_3, 3, t_BinaryExpr_Init_3);
    alg_class_method(k_BinaryExpr, "Accept", m_BinaryExpr_Accept_1, 1, t_BinaryExpr_Accept_1);
    k_LogicalExpr = alg_class("LogicalExpr", k_Expr);
    alg_class_field(k_LogicalExpr, "Left");
    alg_class_field(k_LogicalExpr, "Op");
    alg_class_field(k_LogicalExpr, "Right");
    alg_class_initializer(k_LogicalExpr, i_LogicalExpr);
    alg_class_method(k_LogicalExpr, "Init", m_LogicalExpr_Init_3, 3, t_LogicalExpr_Init_3);
    alg_class_method(k_LogicalExpr, "Accept", m_LogicalExpr_Accept_1, 1, t_LogicalExpr_Accept_1);
    k_GroupingExpr = alg_class("GroupingExpr", k_Expr);
    alg_class_field(k_GroupingExpr, "Expression");
    alg_class_initializer(k_GroupingExpr, i_GroupingExpr);
    alg_class_method(k_GroupingExpr, "Init", m_GroupingExpr_Init_1_Expr, 1, t_GroupingExpr_Init_1_Expr);
    alg_class_method(k_GroupingExpr, "Accept", m_GroupingExpr_Accept_1, 1, t_GroupingExpr_Accept_1);
    k_CollectionExpr = alg_class("CollectionExpr", k_Expr);
    alg_class_field(k_CollectionExpr, "IsMap");
    alg_class_field(k_CollectionExpr, "Keys");
    alg_class_field(k_CollectionExpr, "Values");
    alg_class_initializer(k_CollectionExpr, i_CollectionExpr);
    alg_class_method(k_CollectionExpr, "Init", m_CollectionExpr_Init_3_Boolean_List_List, 3, t_CollectionExpr_Init_3_Boolean_List_List);
    alg_class_method(k_CollectionExpr, "Accept", m_CollectionExpr_Accept_1, 1, t_CollectionExpr_Accept_1);
    k_SubscriptExpr = alg_class("SubscriptExpr", k_Expr);
    alg_class_field(k_SubscriptExpr, "Obj");
    alg_class_field(k_SubscriptExpr, "Index");
    alg_class_field(k_SubscriptExpr, "Bracket");
    alg_class_initializer(k_SubscriptExpr, i_SubscriptExpr);
    alg_class_method(k_SubscriptExpr, "Init", m_SubscriptExpr_Init_3_Expr_Expr_Token, 3, t_SubscriptExpr_Init_3_Expr_Expr_Token);
    alg_class_method(k_SubscriptExpr, "Accept", m_SubscriptExpr_Accept_1, 1, t_SubscriptExpr_Accept_1);
    k_SetSubscriptExpr = alg_class("SetSubscriptExpr", k_Expr);
    alg_class_field(k_SetSubscriptExpr, "Obj");
    alg_class_field(k_SetSubscriptExpr, "Index");
    alg_class_field(k_SetSubscriptExpr, "Value");
    alg_class_field(k_SetSubscriptExpr, "Bracket");
    alg_class_initializer(k_SetSubscriptExpr, i_SetSubscriptExpr);
    alg_class_method(k_SetSubscriptExpr, "Init", m_SetSubscriptExpr_Init_4_Expr_Expr_Expr_Token, 4, t_SetSubscriptExpr_Init_4_Expr_Expr_Expr_Token);
    alg_class_method(k_SetSubscriptExpr, "Accept", m_SetSubscriptExpr_Accept_1, 1, t_SetSubscriptExpr_Accept_1);
    k_LiteralExpr = alg_class("LiteralExpr", k_Expr);
    alg_class_field(k_LiteralExpr, "Value");
    alg_class_initializer(k_LiteralExpr, i_LiteralExpr);
    alg_class_method(k_LiteralExpr, "Init", m_LiteralExpr_Init_1_Expr, 1, t_LiteralExpr_Init_1_Expr);
    alg_class_method(k_LiteralExpr, "Accept", m_LiteralExpr_Accept_1, 1, t_LiteralExpr_Accept_1);
    k_VariableExpr = alg_class("VariableExpr", k_Expr);
    alg_class_field(k_VariableExpr, "Name");
    alg_class_initializer(k_VariableExpr, i_VariableExpr);
    alg_class_method(k_VariableExpr, "Init", m_VariableExpr_Init_1_Token, 1, t_VariableExpr_Init_1_Token);
    alg_class_method(k_VariableExpr, "Accept", m_VariableExpr_Accept_1, 1, t_VariableExpr_Accept_1);
    k_AssignExpr = alg_class("AssignExpr", k_Expr);
    alg_class_field(k_AssignExpr, "Name");
    alg_class_field(k_AssignExpr, "Value");
    alg_class_initializer(k_AssignExpr, i_AssignExpr);
    alg_class_method(k_AssignExpr, "Init", m_AssignExpr_Init_2_Token_Expr, 2, t_AssignExpr_Init_2_Token_Expr);
    alg_class_method(k_AssignExpr, "Accept", m_AssignExpr_Accept_1, 1, t_AssignExpr_Accept_1);
    k_UnaryExpr = alg_class("UnaryExpr", k_Expr);
    alg_class_field(k_UnaryExpr, "Op");
    alg_class_field(k_UnaryExpr, "Right");
    alg_class_initializer(k_UnaryExpr, i_UnaryExpr);
    alg_class_method(k_UnaryExpr, "Init", m_UnaryExpr_Init_2_Token_Expr, 2, t_UnaryExpr_Init_2_Token_Expr);
    alg_class_method(k_UnaryExpr, "Accept", m_UnaryExpr_Accept_1, 1, t_UnaryExpr_Accept_1);
    k_CallExpr = alg_class("CallExpr", k_Expr);
    alg_class_field(k_CallExpr, "Callee");
    alg_class_field(k_CallExpr, "Paren");
    alg_class_field(k_CallExpr, "Arguments");
    alg_class_initializer(k_CallExpr, i_CallExpr);
    alg_class_method(k_CallExpr, "Init", m_CallExpr_Init_3_Expr_Token_List, 3, t_CallExpr_Init_3_Expr_Token_List);
    alg_class_method(k_CallExpr, "Accept", m_CallExpr_Accept_1, 1, t_CallExpr_Accept_1);
    k_GetExpr = alg_class("GetExpr", k_Expr);
    alg_class_field(k_GetExpr, "Obj");
    alg_class_field(k_GetExpr, "Name");
    alg_class_initializer(k_GetExpr, i_GetExpr);
    alg_class_method(k_GetExpr, "Init", m_GetExpr_Init_2_Expr_Token, 2, t_GetExpr_Init_2_Expr_Token);
    alg_class_method(k_GetExpr, "Accept", m_GetExpr_Accept_1, 1, t_GetExpr_Accept_1);
    k_SetExpr = alg_class("SetExpr", k_Expr);
    alg_class_field(k_SetExpr, "Obj");
    alg_class_field(k_SetExpr, "Name");
    alg_class_field(k_SetExpr, "Value");
    alg_class_initializer(k_SetExpr, i_SetExpr);
    alg_class_method(k_SetExpr, "Init", m_SetExpr_Init_3_Expr_Token_Expr, 3, t_SetExpr_Init_3_Expr_Token_Expr);
    alg_class_method(k_SetExpr, "Accept", m_SetExpr_Accept_1, 1, t_SetExpr_Accept_1);
    k_ThisExpr = alg_class("ThisExpr", k_Expr);
    alg_class_field(k_ThisExpr, "Keyword");
    alg_class_initializer(k_ThisExpr, i_ThisExpr);
    alg_class_method(k_ThisExpr, "Init", m_ThisExpr_Init_1_Token, 1, t_ThisExpr_Init_1_Token);
    alg_class_method(k_ThisExpr, "Accept", m_ThisExpr_Accept_1, 1, t_ThisExpr_Accept_1);
    k_SuperExpr = alg_class("SuperExpr", k_Expr);
    alg_class_field(k_SuperExpr, "Keyword");
    alg_class_field(k_SuperExpr, "Method");
    alg_class_initializer(k_SuperExpr, i_SuperExpr);
    alg_class_method(k_SuperExpr, "Init", m_SuperExpr_Init_2_Token_Token, 2, t_SuperExpr_Init_2_Token_Token);
    alg_class_method(k_SuperExpr, "Accept", m_SuperExpr_Accept_1, 1, t_SuperExpr_Accept_1);
    k_IsExpr = alg_class("IsExpr", k_Expr);
    alg_class_field(k_IsExpr, "Obj");
    alg_class_field(k_IsExpr, "TypeName");
    alg_class_initializer(k_IsExpr, i_IsExpr);
    alg_class_method(k_IsExpr, "Init", m_IsExpr_Init_2_Expr_Token, 2, t_IsExpr_Init_2_Expr_Token);
    alg_class_method(k_IsExpr, "Accept", m_IsExpr_Accept_1, 1, t_IsExpr_Accept_1);
}
