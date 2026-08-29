/* Generated from Algol-24.  Do not edit. */
#include "Expr.h"
#include "Token.h"

Value k_expr;
Value k_binaryexpr;
static const char *t_binaryexpr_init_3[] = { "Any", "Any", "Any" };
static const char *t_binaryexpr_accept_1[] = { "Any" };
Value k_logicalexpr;
static const char *t_logicalexpr_init_3[] = { "Any", "Any", "Any" };
static const char *t_logicalexpr_accept_1[] = { "Any" };
Value k_groupingexpr;
static const char *t_groupingexpr_init_1_expr[] = { "Expr" };
static const char *t_groupingexpr_accept_1[] = { "Any" };
Value k_collectionexpr;
static const char *t_collectionexpr_init_3_boolean_list_list[] = { "Boolean", "List", "List" };
static const char *t_collectionexpr_accept_1[] = { "Any" };
Value k_subscriptexpr;
static const char *t_subscriptexpr_init_3_expr_expr_token[] = { "Expr", "Expr", "Token" };
static const char *t_subscriptexpr_accept_1[] = { "Any" };
Value k_setsubscriptexpr;
static const char *t_setsubscriptexpr_init_4_expr_expr_expr_token[] = { "Expr", "Expr", "Expr", "Token" };
static const char *t_setsubscriptexpr_accept_1[] = { "Any" };
Value k_literalexpr;
static const char *t_literalexpr_init_1_expr[] = { "Expr" };
static const char *t_literalexpr_accept_1[] = { "Any" };
Value k_variableexpr;
static const char *t_variableexpr_init_1_token[] = { "Token" };
static const char *t_variableexpr_accept_1[] = { "Any" };
Value k_assignexpr;
static const char *t_assignexpr_init_2_token_expr[] = { "Token", "Expr" };
static const char *t_assignexpr_accept_1[] = { "Any" };
Value k_unaryexpr;
static const char *t_unaryexpr_init_2_token_expr[] = { "Token", "Expr" };
static const char *t_unaryexpr_accept_1[] = { "Any" };
Value k_callexpr;
static const char *t_callexpr_init_3_expr_token_list[] = { "Expr", "Token", "List" };
static const char *t_callexpr_accept_1[] = { "Any" };
Value k_getexpr;
static const char *t_getexpr_init_2_expr_token[] = { "Expr", "Token" };
static const char *t_getexpr_accept_1[] = { "Any" };
Value k_setexpr;
static const char *t_setexpr_init_3_expr_token_expr[] = { "Expr", "Token", "Expr" };
static const char *t_setexpr_accept_1[] = { "Any" };
Value k_thisexpr;
static const char *t_thisexpr_init_1_token[] = { "Token" };
static const char *t_thisexpr_accept_1[] = { "Any" };
Value k_superexpr;
static const char *t_superexpr_init_2_token_token[] = { "Token", "Token" };
static const char *t_superexpr_accept_1[] = { "Any" };
Value k_isexpr;
static const char *t_isexpr_init_2_expr_token[] = { "Expr", "Token" };
static const char *t_isexpr_accept_1[] = { "Any" };

static Value i_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Cast", alg_widen(alg_string(""), "String"));
    return alg_nil();
}

static Value i_binaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Left", alg_nil());
    alg_set_property(v_this, "Op", alg_nil());
    alg_set_property(v_this, "Right", alg_nil());
    return alg_nil();
}

static Value m_binaryexpr_init_3(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_left = args[0];
    (void)v_left;
    Value v_op = args[1];
    (void)v_op;
    Value v_right = args[2];
    (void)v_right;
    (void)(alg_set_property(v_this, "Left", alg_widen(v_left, "Expr")));
    (void)(alg_set_property(v_this, "Op", alg_widen(v_op, "Token")));
    (void)(alg_set_property(v_this, "Right", alg_widen(v_right, "Expr")));
    return alg_nil();
}

static Value m_binaryexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitBinary", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_logicalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Left", alg_nil());
    alg_set_property(v_this, "Op", alg_nil());
    alg_set_property(v_this, "Right", alg_nil());
    return alg_nil();
}

static Value m_logicalexpr_init_3(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_left = args[0];
    (void)v_left;
    Value v_op = args[1];
    (void)v_op;
    Value v_right = args[2];
    (void)v_right;
    (void)(alg_set_property(v_this, "Left", alg_widen(v_left, "Expr")));
    (void)(alg_set_property(v_this, "Op", alg_widen(v_op, "Token")));
    (void)(alg_set_property(v_this, "Right", alg_widen(v_right, "Expr")));
    return alg_nil();
}

static Value m_logicalexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitLogical", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_groupingexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Expression", alg_nil());
    return alg_nil();
}

static Value m_groupingexpr_init_1_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_expression = alg_widen(args[0], "Expr");
    (void)v_expression;
    (void)(alg_set_property(v_this, "Expression", alg_widen(v_expression, "Expr")));
    return alg_nil();
}

static Value m_groupingexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitGrouping", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "IsMap", alg_nil());
    alg_set_property(v_this, "Keys", alg_nil());
    alg_set_property(v_this, "Values", alg_nil());
    return alg_nil();
}

static Value m_collectionexpr_init_3_boolean_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_ismap = alg_widen(args[0], "Boolean");
    (void)v_ismap;
    Value v_keys = alg_widen(args[1], "List");
    (void)v_keys;
    Value v_values = alg_widen(args[2], "List");
    (void)v_values;
    (void)(alg_set_property(v_this, "IsMap", alg_widen(v_ismap, "Boolean")));
    (void)(alg_set_property(v_this, "Keys", alg_widen(v_keys, "List")));
    (void)(alg_set_property(v_this, "Values", alg_widen(v_values, "List")));
    return alg_nil();
}

static Value m_collectionexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitCollectionExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_subscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "Index", alg_nil());
    alg_set_property(v_this, "Bracket", alg_nil());
    return alg_nil();
}

static Value m_subscriptexpr_init_3_expr_expr_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_obj = alg_widen(args[0], "Expr");
    (void)v_obj;
    Value v_index = alg_widen(args[1], "Expr");
    (void)v_index;
    Value v_bracket = alg_widen(args[2], "Token");
    (void)v_bracket;
    (void)(alg_set_property(v_this, "Obj", alg_widen(v_obj, "Expr")));
    (void)(alg_set_property(v_this, "Index", alg_widen(v_index, "Expr")));
    (void)(alg_set_property(v_this, "Bracket", alg_widen(v_bracket, "Token")));
    return alg_nil();
}

static Value m_subscriptexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitSubscriptExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_setsubscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "Index", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    alg_set_property(v_this, "Bracket", alg_nil());
    return alg_nil();
}

static Value m_setsubscriptexpr_init_4_expr_expr_expr_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_obj = alg_widen(args[0], "Expr");
    (void)v_obj;
    Value v_index = alg_widen(args[1], "Expr");
    (void)v_index;
    Value v_value = alg_widen(args[2], "Expr");
    (void)v_value;
    Value v_bracket = alg_widen(args[3], "Token");
    (void)v_bracket;
    (void)(alg_set_property(v_this, "Obj", alg_widen(v_obj, "Expr")));
    (void)(alg_set_property(v_this, "Index", alg_widen(v_index, "Expr")));
    (void)(alg_set_property(v_this, "Value", alg_widen(v_value, "Expr")));
    (void)(alg_set_property(v_this, "Bracket", alg_widen(v_bracket, "Token")));
    return alg_nil();
}

static Value m_setsubscriptexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitSetSubscriptExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_literalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Value", alg_nil());
    return alg_nil();
}

static Value m_literalexpr_init_1_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_value = alg_widen(args[0], "Expr");
    (void)v_value;
    (void)(alg_set_property(v_this, "Value", alg_widen(v_value, "Expr")));
    return alg_nil();
}

static Value m_literalexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitLiteral", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_variableexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    return alg_nil();
}

static Value m_variableexpr_init_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    return alg_nil();
}

static Value m_variableexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitVariableExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_assignexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    alg_set_property(v_this, "Declared", alg_widen(alg_string(""), "String"));
    return alg_nil();
}

static Value m_assignexpr_init_2_token_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_value = alg_widen(args[1], "Expr");
    (void)v_value;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    (void)(alg_set_property(v_this, "Value", alg_widen(v_value, "Expr")));
    return alg_nil();
}

static Value m_assignexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitAssignExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_unaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Op", alg_nil());
    alg_set_property(v_this, "Right", alg_nil());
    return alg_nil();
}

static Value m_unaryexpr_init_2_token_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_op = alg_widen(args[0], "Token");
    (void)v_op;
    Value v_right = alg_widen(args[1], "Expr");
    (void)v_right;
    (void)(alg_set_property(v_this, "Op", alg_widen(v_op, "Token")));
    (void)(alg_set_property(v_this, "Right", alg_widen(v_right, "Expr")));
    return alg_nil();
}

static Value m_unaryexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitUnary", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_callexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Callee", alg_nil());
    alg_set_property(v_this, "Paren", alg_nil());
    alg_set_property(v_this, "Arguments", alg_nil());
    return alg_nil();
}

static Value m_callexpr_init_3_expr_token_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_callee = alg_widen(args[0], "Expr");
    (void)v_callee;
    Value v_paren = alg_widen(args[1], "Token");
    (void)v_paren;
    Value v_arguments = alg_widen(args[2], "List");
    (void)v_arguments;
    (void)(alg_set_property(v_this, "Callee", alg_widen(v_callee, "Expr")));
    (void)(alg_set_property(v_this, "Paren", alg_widen(v_paren, "Token")));
    (void)(alg_set_property(v_this, "Arguments", alg_widen(v_arguments, "List")));
    return alg_nil();
}

static Value m_callexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitCall", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Unit", alg_widen(alg_string(""), "String"));
    return alg_nil();
}

static Value m_getexpr_init_2_expr_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_obj = alg_widen(args[0], "Expr");
    (void)v_obj;
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    (void)(alg_set_property(v_this, "Obj", alg_widen(v_obj, "Expr")));
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    return alg_nil();
}

static Value m_getexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitGetExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_setexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    alg_set_property(v_this, "Unit", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "Declared", alg_widen(alg_string(""), "String"));
    return alg_nil();
}

static Value m_setexpr_init_3_expr_token_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_obj = alg_widen(args[0], "Expr");
    (void)v_obj;
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    Value v_value = alg_widen(args[2], "Expr");
    (void)v_value;
    (void)(alg_set_property(v_this, "Obj", alg_widen(v_obj, "Expr")));
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    (void)(alg_set_property(v_this, "Value", alg_widen(v_value, "Expr")));
    return alg_nil();
}

static Value m_setexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitSetExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_thisexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Keyword", alg_nil());
    return alg_nil();
}

static Value m_thisexpr_init_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_keyword = alg_widen(args[0], "Token");
    (void)v_keyword;
    (void)(alg_set_property(v_this, "Keyword", alg_widen(v_keyword, "Token")));
    return alg_nil();
}

static Value m_thisexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitThisExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_superexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Keyword", alg_nil());
    alg_set_property(v_this, "Method", alg_nil());
    return alg_nil();
}

static Value m_superexpr_init_2_token_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_keyword = alg_widen(args[0], "Token");
    (void)v_keyword;
    Value v_method = alg_widen(args[1], "Token");
    (void)v_method;
    (void)(alg_set_property(v_this, "Keyword", alg_widen(v_keyword, "Token")));
    (void)(alg_set_property(v_this, "Method", alg_widen(v_method, "Token")));
    return alg_nil();
}

static Value m_superexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitSuperExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value i_isexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "TypeName", alg_nil());
    return alg_nil();
}

static Value m_isexpr_init_2_expr_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_obj = alg_widen(args[0], "Expr");
    (void)v_obj;
    Value v_typename = alg_widen(args[1], "Token");
    (void)v_typename;
    (void)(alg_set_property(v_this, "Obj", alg_widen(v_obj, "Expr")));
    (void)(alg_set_property(v_this, "TypeName", alg_widen(v_typename, "Token")));
    return alg_nil();
}

static Value m_isexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_visitor = args[0];
    (void)v_visitor;
    return alg_invoke(v_visitor, "VisitIsExpr", (Value[]){v_this}, 1);
    return alg_nil();
}

void init_Expr(void) {
    k_expr = alg_class("Expr", alg_nil());
    alg_class_field(k_expr, "Cast");
    alg_class_initializer(k_expr, i_expr);
    k_binaryexpr = alg_class("BinaryExpr", k_expr);
    alg_class_field(k_binaryexpr, "Left");
    alg_class_field(k_binaryexpr, "Op");
    alg_class_field(k_binaryexpr, "Right");
    alg_class_initializer(k_binaryexpr, i_binaryexpr);
    alg_class_method(k_binaryexpr, "Init", m_binaryexpr_init_3, 3, t_binaryexpr_init_3);
    alg_class_method(k_binaryexpr, "Accept", m_binaryexpr_accept_1, 1, t_binaryexpr_accept_1);
    k_logicalexpr = alg_class("LogicalExpr", k_expr);
    alg_class_field(k_logicalexpr, "Left");
    alg_class_field(k_logicalexpr, "Op");
    alg_class_field(k_logicalexpr, "Right");
    alg_class_initializer(k_logicalexpr, i_logicalexpr);
    alg_class_method(k_logicalexpr, "Init", m_logicalexpr_init_3, 3, t_logicalexpr_init_3);
    alg_class_method(k_logicalexpr, "Accept", m_logicalexpr_accept_1, 1, t_logicalexpr_accept_1);
    k_groupingexpr = alg_class("GroupingExpr", k_expr);
    alg_class_field(k_groupingexpr, "Expression");
    alg_class_initializer(k_groupingexpr, i_groupingexpr);
    alg_class_method(k_groupingexpr, "Init", m_groupingexpr_init_1_expr, 1, t_groupingexpr_init_1_expr);
    alg_class_method(k_groupingexpr, "Accept", m_groupingexpr_accept_1, 1, t_groupingexpr_accept_1);
    k_collectionexpr = alg_class("CollectionExpr", k_expr);
    alg_class_field(k_collectionexpr, "IsMap");
    alg_class_field(k_collectionexpr, "Keys");
    alg_class_field(k_collectionexpr, "Values");
    alg_class_initializer(k_collectionexpr, i_collectionexpr);
    alg_class_method(k_collectionexpr, "Init", m_collectionexpr_init_3_boolean_list_list, 3, t_collectionexpr_init_3_boolean_list_list);
    alg_class_method(k_collectionexpr, "Accept", m_collectionexpr_accept_1, 1, t_collectionexpr_accept_1);
    k_subscriptexpr = alg_class("SubscriptExpr", k_expr);
    alg_class_field(k_subscriptexpr, "Obj");
    alg_class_field(k_subscriptexpr, "Index");
    alg_class_field(k_subscriptexpr, "Bracket");
    alg_class_initializer(k_subscriptexpr, i_subscriptexpr);
    alg_class_method(k_subscriptexpr, "Init", m_subscriptexpr_init_3_expr_expr_token, 3, t_subscriptexpr_init_3_expr_expr_token);
    alg_class_method(k_subscriptexpr, "Accept", m_subscriptexpr_accept_1, 1, t_subscriptexpr_accept_1);
    k_setsubscriptexpr = alg_class("SetSubscriptExpr", k_expr);
    alg_class_field(k_setsubscriptexpr, "Obj");
    alg_class_field(k_setsubscriptexpr, "Index");
    alg_class_field(k_setsubscriptexpr, "Value");
    alg_class_field(k_setsubscriptexpr, "Bracket");
    alg_class_initializer(k_setsubscriptexpr, i_setsubscriptexpr);
    alg_class_method(k_setsubscriptexpr, "Init", m_setsubscriptexpr_init_4_expr_expr_expr_token, 4, t_setsubscriptexpr_init_4_expr_expr_expr_token);
    alg_class_method(k_setsubscriptexpr, "Accept", m_setsubscriptexpr_accept_1, 1, t_setsubscriptexpr_accept_1);
    k_literalexpr = alg_class("LiteralExpr", k_expr);
    alg_class_field(k_literalexpr, "Value");
    alg_class_initializer(k_literalexpr, i_literalexpr);
    alg_class_method(k_literalexpr, "Init", m_literalexpr_init_1_expr, 1, t_literalexpr_init_1_expr);
    alg_class_method(k_literalexpr, "Accept", m_literalexpr_accept_1, 1, t_literalexpr_accept_1);
    k_variableexpr = alg_class("VariableExpr", k_expr);
    alg_class_field(k_variableexpr, "Name");
    alg_class_initializer(k_variableexpr, i_variableexpr);
    alg_class_method(k_variableexpr, "Init", m_variableexpr_init_1_token, 1, t_variableexpr_init_1_token);
    alg_class_method(k_variableexpr, "Accept", m_variableexpr_accept_1, 1, t_variableexpr_accept_1);
    k_assignexpr = alg_class("AssignExpr", k_expr);
    alg_class_field(k_assignexpr, "Name");
    alg_class_field(k_assignexpr, "Value");
    alg_class_field(k_assignexpr, "Declared");
    alg_class_initializer(k_assignexpr, i_assignexpr);
    alg_class_method(k_assignexpr, "Init", m_assignexpr_init_2_token_expr, 2, t_assignexpr_init_2_token_expr);
    alg_class_method(k_assignexpr, "Accept", m_assignexpr_accept_1, 1, t_assignexpr_accept_1);
    k_unaryexpr = alg_class("UnaryExpr", k_expr);
    alg_class_field(k_unaryexpr, "Op");
    alg_class_field(k_unaryexpr, "Right");
    alg_class_initializer(k_unaryexpr, i_unaryexpr);
    alg_class_method(k_unaryexpr, "Init", m_unaryexpr_init_2_token_expr, 2, t_unaryexpr_init_2_token_expr);
    alg_class_method(k_unaryexpr, "Accept", m_unaryexpr_accept_1, 1, t_unaryexpr_accept_1);
    k_callexpr = alg_class("CallExpr", k_expr);
    alg_class_field(k_callexpr, "Callee");
    alg_class_field(k_callexpr, "Paren");
    alg_class_field(k_callexpr, "Arguments");
    alg_class_initializer(k_callexpr, i_callexpr);
    alg_class_method(k_callexpr, "Init", m_callexpr_init_3_expr_token_list, 3, t_callexpr_init_3_expr_token_list);
    alg_class_method(k_callexpr, "Accept", m_callexpr_accept_1, 1, t_callexpr_accept_1);
    k_getexpr = alg_class("GetExpr", k_expr);
    alg_class_field(k_getexpr, "Obj");
    alg_class_field(k_getexpr, "Name");
    alg_class_field(k_getexpr, "Unit");
    alg_class_initializer(k_getexpr, i_getexpr);
    alg_class_method(k_getexpr, "Init", m_getexpr_init_2_expr_token, 2, t_getexpr_init_2_expr_token);
    alg_class_method(k_getexpr, "Accept", m_getexpr_accept_1, 1, t_getexpr_accept_1);
    k_setexpr = alg_class("SetExpr", k_expr);
    alg_class_field(k_setexpr, "Obj");
    alg_class_field(k_setexpr, "Name");
    alg_class_field(k_setexpr, "Value");
    alg_class_field(k_setexpr, "Unit");
    alg_class_field(k_setexpr, "Declared");
    alg_class_initializer(k_setexpr, i_setexpr);
    alg_class_method(k_setexpr, "Init", m_setexpr_init_3_expr_token_expr, 3, t_setexpr_init_3_expr_token_expr);
    alg_class_method(k_setexpr, "Accept", m_setexpr_accept_1, 1, t_setexpr_accept_1);
    k_thisexpr = alg_class("ThisExpr", k_expr);
    alg_class_field(k_thisexpr, "Keyword");
    alg_class_initializer(k_thisexpr, i_thisexpr);
    alg_class_method(k_thisexpr, "Init", m_thisexpr_init_1_token, 1, t_thisexpr_init_1_token);
    alg_class_method(k_thisexpr, "Accept", m_thisexpr_accept_1, 1, t_thisexpr_accept_1);
    k_superexpr = alg_class("SuperExpr", k_expr);
    alg_class_field(k_superexpr, "Keyword");
    alg_class_field(k_superexpr, "Method");
    alg_class_initializer(k_superexpr, i_superexpr);
    alg_class_method(k_superexpr, "Init", m_superexpr_init_2_token_token, 2, t_superexpr_init_2_token_token);
    alg_class_method(k_superexpr, "Accept", m_superexpr_accept_1, 1, t_superexpr_accept_1);
    k_isexpr = alg_class("IsExpr", k_expr);
    alg_class_field(k_isexpr, "Obj");
    alg_class_field(k_isexpr, "TypeName");
    alg_class_initializer(k_isexpr, i_isexpr);
    alg_class_method(k_isexpr, "Init", m_isexpr_init_2_expr_token, 2, t_isexpr_init_2_expr_token);
    alg_class_method(k_isexpr, "Accept", m_isexpr_accept_1, 1, t_isexpr_accept_1);
}
