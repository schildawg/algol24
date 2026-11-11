/* Generated from Algol-24.  Do not edit. */
#include "Expr.h"
#include "Token.h"

Value k_expr;
Value k_binaryexpr;
static const char *t_binaryexpr_init_3[] = { "Left : Any", "Op : Any", "Right : Any" };
static const char *t_binaryexpr_accept_1[] = { "Visitor : Any" };
Value k_logicalexpr;
static const char *t_logicalexpr_init_3[] = { "Left : Any", "Op : Any", "Right : Any" };
static const char *t_logicalexpr_accept_1[] = { "Visitor : Any" };
Value k_groupingexpr;
static const char *t_groupingexpr_init_1_expr[] = { "Expression : Expr" };
static const char *t_groupingexpr_accept_1[] = { "Visitor : Any" };
Value k_collectionexpr;
static const char *t_collectionexpr_init_3_boolean_list_list[] = { "IsMap : Boolean", "Keys : List", "Values : List" };
static const char *t_collectionexpr_accept_1[] = { "Visitor : Any" };
Value k_subscriptexpr;
static const char *t_subscriptexpr_init_3_expr_expr_token[] = { "Obj : Expr", "Index : Expr", "Bracket : Token" };
static const char *t_subscriptexpr_accept_1[] = { "Visitor : Any" };
Value k_setsubscriptexpr;
static const char *t_setsubscriptexpr_init_4_expr_expr_expr_token[] = { "Obj : Expr", "Index : Expr", "Value : Expr", "Bracket : Token" };
static const char *t_setsubscriptexpr_accept_1[] = { "Visitor : Any" };
Value k_literalexpr;
static const char *t_literalexpr_init_1[] = { "Value : Any" };
static const char *t_literalexpr_accept_1[] = { "Visitor : Any" };
Value k_variableexpr;
static const char *t_variableexpr_init_1_token[] = { "Name : Token" };
static const char *t_variableexpr_accept_1[] = { "Visitor : Any" };
Value k_assignexpr;
static const char *t_assignexpr_init_2_token_expr[] = { "Name : Token", "Value : Expr" };
static const char *t_assignexpr_accept_1[] = { "Visitor : Any" };
Value k_unaryexpr;
static const char *t_unaryexpr_init_2_token_expr[] = { "Op : Token", "Right : Expr" };
static const char *t_unaryexpr_accept_1[] = { "Visitor : Any" };
Value k_callexpr;
static const char *t_callexpr_init_3_expr_token_list[] = { "Callee : Expr", "Paren : Token", "Arguments : List" };
static const char *t_callexpr_accept_1[] = { "Visitor : Any" };
Value k_getexpr;
static const char *t_getexpr_init_2_expr_token[] = { "Obj : Expr", "Name : Token" };
static const char *t_getexpr_accept_1[] = { "Visitor : Any" };
Value k_setexpr;
static const char *t_setexpr_init_3_expr_token_expr[] = { "Obj : Expr", "Name : Token", "Value : Expr" };
static const char *t_setexpr_accept_1[] = { "Visitor : Any" };
Value k_thisexpr;
static const char *t_thisexpr_init_1_token[] = { "Keyword : Token" };
static const char *t_thisexpr_accept_1[] = { "Visitor : Any" };
Value k_superexpr;
static const char *t_superexpr_init_2_token_token[] = { "Keyword : Token", "Method : Token" };
static const char *t_superexpr_accept_1[] = { "Visitor : Any" };
Value k_isexpr;
static const char *t_isexpr_init_2_expr_token[] = { "Obj : Expr", "TypeName : Token" };
static const char *t_isexpr_accept_1[] = { "Visitor : Any" };

static Value i_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Cast", alg_widen(alg_literal(""), "String"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value i_binaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Left", alg_nil());
    alg_set_property(v_this, "Op", alg_nil());
    alg_set_property(v_this, "Right", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_binaryexpr_init_3(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_left = args[0];
    (void)v_left;
    alg_root(&v_left, 1);
    Value v_op = args[1];
    (void)v_op;
    alg_root(&v_op, 1);
    Value v_right = args[2];
    (void)v_right;
    alg_root(&v_right, 1);
    int32_t rh_12 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Left", v_left)));
    alg_hold_top = rh_12;
    (void)(alg_hold(alg_set_property(v_this, "Op", v_op)));
    alg_hold_top = rh_12;
    (void)(alg_hold(alg_set_property(v_this, "Right", v_right)));
    alg_hold_top = rh_12;
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

static Value m_binaryexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_13 = alg_hold_top;
    Value ret_1 = alg_hold(alg_invoke(v_visitor, "VisitBinary", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_1;
    alg_hold_top = rh_13;
    Value ret_2 = alg_nil();
    alg_root_top = rt_base;
    return ret_2;
}

static Value i_logicalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Left", alg_nil());
    alg_set_property(v_this, "Op", alg_nil());
    alg_set_property(v_this, "Right", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_logicalexpr_init_3(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_left = args[0];
    (void)v_left;
    alg_root(&v_left, 1);
    Value v_op = args[1];
    (void)v_op;
    alg_root(&v_op, 1);
    Value v_right = args[2];
    (void)v_right;
    alg_root(&v_right, 1);
    int32_t rh_14 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Left", v_left)));
    alg_hold_top = rh_14;
    (void)(alg_hold(alg_set_property(v_this, "Op", v_op)));
    alg_hold_top = rh_14;
    (void)(alg_hold(alg_set_property(v_this, "Right", v_right)));
    alg_hold_top = rh_14;
    Value ret_3 = alg_nil();
    alg_root_top = rt_base;
    return ret_3;
}

static Value m_logicalexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_15 = alg_hold_top;
    Value ret_4 = alg_hold(alg_invoke(v_visitor, "VisitLogical", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_4;
    alg_hold_top = rh_15;
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

static Value i_groupingexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Expression", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_groupingexpr_init_1_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_expression = alg_widen(args[0], "Expr");
    (void)v_expression;
    alg_root(&v_expression, 1);
    int32_t rh_16 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Expression", v_expression)));
    alg_hold_top = rh_16;
    Value ret_6 = alg_nil();
    alg_root_top = rt_base;
    return ret_6;
}

static Value m_groupingexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_17 = alg_hold_top;
    Value ret_7 = alg_hold(alg_invoke(v_visitor, "VisitGrouping", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_7;
    alg_hold_top = rh_17;
    Value ret_8 = alg_nil();
    alg_root_top = rt_base;
    return ret_8;
}

static Value i_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "IsMap", alg_nil());
    alg_set_property(v_this, "Keys", alg_nil());
    alg_set_property(v_this, "Values", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_collectionexpr_init_3_boolean_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_ismap = alg_widen(args[0], "Boolean");
    (void)v_ismap;
    alg_root(&v_ismap, 1);
    Value v_keys = alg_widen(args[1], "List");
    (void)v_keys;
    alg_root(&v_keys, 1);
    Value v_values = alg_widen(args[2], "List");
    (void)v_values;
    alg_root(&v_values, 1);
    int32_t rh_18 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "IsMap", v_ismap)));
    alg_hold_top = rh_18;
    (void)(alg_hold(alg_set_property(v_this, "Keys", v_keys)));
    alg_hold_top = rh_18;
    (void)(alg_hold(alg_set_property(v_this, "Values", v_values)));
    alg_hold_top = rh_18;
    Value ret_9 = alg_nil();
    alg_root_top = rt_base;
    return ret_9;
}

static Value m_collectionexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_19 = alg_hold_top;
    Value ret_10 = alg_hold(alg_invoke(v_visitor, "VisitCollectionExpr", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_10;
    alg_hold_top = rh_19;
    Value ret_11 = alg_nil();
    alg_root_top = rt_base;
    return ret_11;
}

static Value i_subscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "Index", alg_nil());
    alg_set_property(v_this, "Bracket", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_subscriptexpr_init_3_expr_expr_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = alg_widen(args[0], "Expr");
    (void)v_obj;
    alg_root(&v_obj, 1);
    Value v_index = alg_widen(args[1], "Expr");
    (void)v_index;
    alg_root(&v_index, 1);
    Value v_bracket = alg_widen(args[2], "Token");
    (void)v_bracket;
    alg_root(&v_bracket, 1);
    int32_t rh_20 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Obj", v_obj)));
    alg_hold_top = rh_20;
    (void)(alg_hold(alg_set_property(v_this, "Index", v_index)));
    alg_hold_top = rh_20;
    (void)(alg_hold(alg_set_property(v_this, "Bracket", v_bracket)));
    alg_hold_top = rh_20;
    Value ret_12 = alg_nil();
    alg_root_top = rt_base;
    return ret_12;
}

static Value m_subscriptexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_21 = alg_hold_top;
    Value ret_13 = alg_hold(alg_invoke(v_visitor, "VisitSubscriptExpr", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_13;
    alg_hold_top = rh_21;
    Value ret_14 = alg_nil();
    alg_root_top = rt_base;
    return ret_14;
}

static Value i_setsubscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "Index", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    alg_set_property(v_this, "Bracket", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_setsubscriptexpr_init_4_expr_expr_expr_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = alg_widen(args[0], "Expr");
    (void)v_obj;
    alg_root(&v_obj, 1);
    Value v_index = alg_widen(args[1], "Expr");
    (void)v_index;
    alg_root(&v_index, 1);
    Value v_value = alg_widen(args[2], "Expr");
    (void)v_value;
    alg_root(&v_value, 1);
    Value v_bracket = alg_widen(args[3], "Token");
    (void)v_bracket;
    alg_root(&v_bracket, 1);
    int32_t rh_22 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Obj", v_obj)));
    alg_hold_top = rh_22;
    (void)(alg_hold(alg_set_property(v_this, "Index", v_index)));
    alg_hold_top = rh_22;
    (void)(alg_hold(alg_set_property(v_this, "Value", v_value)));
    alg_hold_top = rh_22;
    (void)(alg_hold(alg_set_property(v_this, "Bracket", v_bracket)));
    alg_hold_top = rh_22;
    Value ret_15 = alg_nil();
    alg_root_top = rt_base;
    return ret_15;
}

static Value m_setsubscriptexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_23 = alg_hold_top;
    Value ret_16 = alg_hold(alg_invoke(v_visitor, "VisitSetSubscriptExpr", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_16;
    alg_hold_top = rh_23;
    Value ret_17 = alg_nil();
    alg_root_top = rt_base;
    return ret_17;
}

static Value i_literalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Value", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_literalexpr_init_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    int32_t rh_24 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Value", v_value)));
    alg_hold_top = rh_24;
    Value ret_18 = alg_nil();
    alg_root_top = rt_base;
    return ret_18;
}

static Value m_literalexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_25 = alg_hold_top;
    Value ret_19 = alg_hold(alg_invoke(v_visitor, "VisitLiteral", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_19;
    alg_hold_top = rh_25;
    Value ret_20 = alg_nil();
    alg_root_top = rt_base;
    return ret_20;
}

static Value i_variableexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Name", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_variableexpr_init_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_26 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_26;
    Value ret_21 = alg_nil();
    alg_root_top = rt_base;
    return ret_21;
}

static Value m_variableexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_27 = alg_hold_top;
    Value ret_22 = alg_hold(alg_invoke(v_visitor, "VisitVariableExpr", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_22;
    alg_hold_top = rh_27;
    Value ret_23 = alg_nil();
    alg_root_top = rt_base;
    return ret_23;
}

static Value i_assignexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    alg_set_property(v_this, "Declared", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "Actual", alg_widen(alg_literal(""), "String"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_assignexpr_init_2_token_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_value = alg_widen(args[1], "Expr");
    (void)v_value;
    alg_root(&v_value, 1);
    int32_t rh_28 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_28;
    (void)(alg_hold(alg_set_property(v_this, "Value", v_value)));
    alg_hold_top = rh_28;
    Value ret_24 = alg_nil();
    alg_root_top = rt_base;
    return ret_24;
}

static Value m_assignexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_29 = alg_hold_top;
    Value ret_25 = alg_hold(alg_invoke(v_visitor, "VisitAssignExpr", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_25;
    alg_hold_top = rh_29;
    Value ret_26 = alg_nil();
    alg_root_top = rt_base;
    return ret_26;
}

static Value i_unaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Op", alg_nil());
    alg_set_property(v_this, "Right", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_unaryexpr_init_2_token_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_op = alg_widen(args[0], "Token");
    (void)v_op;
    alg_root(&v_op, 1);
    Value v_right = alg_widen(args[1], "Expr");
    (void)v_right;
    alg_root(&v_right, 1);
    int32_t rh_30 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Op", v_op)));
    alg_hold_top = rh_30;
    (void)(alg_hold(alg_set_property(v_this, "Right", v_right)));
    alg_hold_top = rh_30;
    Value ret_27 = alg_nil();
    alg_root_top = rt_base;
    return ret_27;
}

static Value m_unaryexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_31 = alg_hold_top;
    Value ret_28 = alg_hold(alg_invoke(v_visitor, "VisitUnary", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_28;
    alg_hold_top = rh_31;
    Value ret_29 = alg_nil();
    alg_root_top = rt_base;
    return ret_29;
}

static Value i_callexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Callee", alg_nil());
    alg_set_property(v_this, "Paren", alg_nil());
    alg_set_property(v_this, "Arguments", alg_nil());
    alg_set_property(v_this, "ArgumentNames", alg_widen(alg_hold(alg_list()), "List"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_callexpr_init_3_expr_token_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_callee = alg_widen(args[0], "Expr");
    (void)v_callee;
    alg_root(&v_callee, 1);
    Value v_paren = alg_widen(args[1], "Token");
    (void)v_paren;
    alg_root(&v_paren, 1);
    Value v_arguments = alg_widen(args[2], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    int32_t rh_32 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Callee", v_callee)));
    alg_hold_top = rh_32;
    (void)(alg_hold(alg_set_property(v_this, "Paren", v_paren)));
    alg_hold_top = rh_32;
    (void)(alg_hold(alg_set_property(v_this, "Arguments", v_arguments)));
    alg_hold_top = rh_32;
    Value ret_30 = alg_nil();
    alg_root_top = rt_base;
    return ret_30;
}

static Value m_callexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_33 = alg_hold_top;
    Value ret_31 = alg_hold(alg_invoke(v_visitor, "VisitCall", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_31;
    alg_hold_top = rh_33;
    Value ret_32 = alg_nil();
    alg_root_top = rt_base;
    return ret_32;
}

static Value i_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Unit", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "Extension", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "ExtensionUnit", alg_widen(alg_literal(""), "String"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_getexpr_init_2_expr_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = alg_widen(args[0], "Expr");
    (void)v_obj;
    alg_root(&v_obj, 1);
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_34 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Obj", v_obj)));
    alg_hold_top = rh_34;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_34;
    Value ret_33 = alg_nil();
    alg_root_top = rt_base;
    return ret_33;
}

static Value m_getexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_35 = alg_hold_top;
    Value ret_34 = alg_hold(alg_invoke(v_visitor, "VisitGetExpr", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_34;
    alg_hold_top = rh_35;
    Value ret_35 = alg_nil();
    alg_root_top = rt_base;
    return ret_35;
}

static Value i_setexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Value", alg_nil());
    alg_set_property(v_this, "Unit", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "Declared", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "Actual", alg_widen(alg_literal(""), "String"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_setexpr_init_3_expr_token_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = alg_widen(args[0], "Expr");
    (void)v_obj;
    alg_root(&v_obj, 1);
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_value = alg_widen(args[2], "Expr");
    (void)v_value;
    alg_root(&v_value, 1);
    int32_t rh_36 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Obj", v_obj)));
    alg_hold_top = rh_36;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_36;
    (void)(alg_hold(alg_set_property(v_this, "Value", v_value)));
    alg_hold_top = rh_36;
    Value ret_36 = alg_nil();
    alg_root_top = rt_base;
    return ret_36;
}

static Value m_setexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_37 = alg_hold_top;
    Value ret_37 = alg_hold(alg_invoke(v_visitor, "VisitSetExpr", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_37;
    alg_hold_top = rh_37;
    Value ret_38 = alg_nil();
    alg_root_top = rt_base;
    return ret_38;
}

static Value i_thisexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Keyword", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_thisexpr_init_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_keyword = alg_widen(args[0], "Token");
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    int32_t rh_38 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Keyword", v_keyword)));
    alg_hold_top = rh_38;
    Value ret_39 = alg_nil();
    alg_root_top = rt_base;
    return ret_39;
}

static Value m_thisexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_39 = alg_hold_top;
    Value ret_40 = alg_hold(alg_invoke(v_visitor, "VisitThisExpr", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_40;
    alg_hold_top = rh_39;
    Value ret_41 = alg_nil();
    alg_root_top = rt_base;
    return ret_41;
}

static Value i_superexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Keyword", alg_nil());
    alg_set_property(v_this, "Method", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_superexpr_init_2_token_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_keyword = alg_widen(args[0], "Token");
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    Value v_method = alg_widen(args[1], "Token");
    (void)v_method;
    alg_root(&v_method, 1);
    int32_t rh_40 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Keyword", v_keyword)));
    alg_hold_top = rh_40;
    (void)(alg_hold(alg_set_property(v_this, "Method", v_method)));
    alg_hold_top = rh_40;
    Value ret_42 = alg_nil();
    alg_root_top = rt_base;
    return ret_42;
}

static Value m_superexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_41 = alg_hold_top;
    Value ret_43 = alg_hold(alg_invoke(v_visitor, "VisitSuperExpr", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_43;
    alg_hold_top = rh_41;
    Value ret_44 = alg_nil();
    alg_root_top = rt_base;
    return ret_44;
}

static Value i_isexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Obj", alg_nil());
    alg_set_property(v_this, "TypeName", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_isexpr_init_2_expr_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = alg_widen(args[0], "Expr");
    (void)v_obj;
    alg_root(&v_obj, 1);
    Value v_typename = alg_widen(args[1], "Token");
    (void)v_typename;
    alg_root(&v_typename, 1);
    int32_t rh_42 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Obj", v_obj)));
    alg_hold_top = rh_42;
    (void)(alg_hold(alg_set_property(v_this, "TypeName", v_typename)));
    alg_hold_top = rh_42;
    Value ret_45 = alg_nil();
    alg_root_top = rt_base;
    return ret_45;
}

static Value m_isexpr_accept_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_visitor = args[0];
    (void)v_visitor;
    alg_root(&v_visitor, 1);
    int32_t rh_43 = alg_hold_top;
    Value ret_46 = alg_hold(alg_invoke(v_visitor, "VisitIsExpr", (Value[]){v_this}, 1));
    alg_root_top = rt_base;
    return ret_46;
    alg_hold_top = rh_43;
    Value ret_47 = alg_nil();
    alg_root_top = rt_base;
    return ret_47;
}

static Value *roots_Expr[] = {
    &k_expr,
    &k_binaryexpr,
    &k_logicalexpr,
    &k_groupingexpr,
    &k_collectionexpr,
    &k_subscriptexpr,
    &k_setsubscriptexpr,
    &k_literalexpr,
    &k_variableexpr,
    &k_assignexpr,
    &k_unaryexpr,
    &k_callexpr,
    &k_getexpr,
    &k_setexpr,
    &k_thisexpr,
    &k_superexpr,
    &k_isexpr,
};

void init_Expr(void) {
    alg_roots(roots_Expr, 17);
    k_expr = alg_class("Expr", alg_nil());
    k_binaryexpr = alg_class("BinaryExpr", alg_nil());
    k_logicalexpr = alg_class("LogicalExpr", alg_nil());
    k_groupingexpr = alg_class("GroupingExpr", alg_nil());
    k_collectionexpr = alg_class("CollectionExpr", alg_nil());
    k_subscriptexpr = alg_class("SubscriptExpr", alg_nil());
    k_setsubscriptexpr = alg_class("SetSubscriptExpr", alg_nil());
    k_literalexpr = alg_class("LiteralExpr", alg_nil());
    k_variableexpr = alg_class("VariableExpr", alg_nil());
    k_assignexpr = alg_class("AssignExpr", alg_nil());
    k_unaryexpr = alg_class("UnaryExpr", alg_nil());
    k_callexpr = alg_class("CallExpr", alg_nil());
    k_getexpr = alg_class("GetExpr", alg_nil());
    k_setexpr = alg_class("SetExpr", alg_nil());
    k_thisexpr = alg_class("ThisExpr", alg_nil());
    k_superexpr = alg_class("SuperExpr", alg_nil());
    k_isexpr = alg_class("IsExpr", alg_nil());
    alg_class_field(k_expr, "Cast");
    alg_class_initializer(k_expr, i_expr);
    alg_class_super(k_binaryexpr, k_expr);
    alg_class_field(k_binaryexpr, "Left");
    alg_class_field(k_binaryexpr, "Op");
    alg_class_field(k_binaryexpr, "Right");
    alg_class_initializer(k_binaryexpr, i_binaryexpr);
    alg_class_method(k_binaryexpr, "Init", m_binaryexpr_init_3, 3, t_binaryexpr_init_3);
    alg_class_method(k_binaryexpr, "Accept", m_binaryexpr_accept_1, 1, t_binaryexpr_accept_1);
    alg_class_super(k_logicalexpr, k_expr);
    alg_class_field(k_logicalexpr, "Left");
    alg_class_field(k_logicalexpr, "Op");
    alg_class_field(k_logicalexpr, "Right");
    alg_class_initializer(k_logicalexpr, i_logicalexpr);
    alg_class_method(k_logicalexpr, "Init", m_logicalexpr_init_3, 3, t_logicalexpr_init_3);
    alg_class_method(k_logicalexpr, "Accept", m_logicalexpr_accept_1, 1, t_logicalexpr_accept_1);
    alg_class_super(k_groupingexpr, k_expr);
    alg_class_field(k_groupingexpr, "Expression");
    alg_class_initializer(k_groupingexpr, i_groupingexpr);
    alg_class_method(k_groupingexpr, "Init", m_groupingexpr_init_1_expr, 1, t_groupingexpr_init_1_expr);
    alg_class_method(k_groupingexpr, "Accept", m_groupingexpr_accept_1, 1, t_groupingexpr_accept_1);
    alg_class_super(k_collectionexpr, k_expr);
    alg_class_field(k_collectionexpr, "IsMap");
    alg_class_field(k_collectionexpr, "Keys");
    alg_class_field(k_collectionexpr, "Values");
    alg_class_initializer(k_collectionexpr, i_collectionexpr);
    alg_class_method(k_collectionexpr, "Init", m_collectionexpr_init_3_boolean_list_list, 3, t_collectionexpr_init_3_boolean_list_list);
    alg_class_method(k_collectionexpr, "Accept", m_collectionexpr_accept_1, 1, t_collectionexpr_accept_1);
    alg_class_super(k_subscriptexpr, k_expr);
    alg_class_field(k_subscriptexpr, "Obj");
    alg_class_field(k_subscriptexpr, "Index");
    alg_class_field(k_subscriptexpr, "Bracket");
    alg_class_initializer(k_subscriptexpr, i_subscriptexpr);
    alg_class_method(k_subscriptexpr, "Init", m_subscriptexpr_init_3_expr_expr_token, 3, t_subscriptexpr_init_3_expr_expr_token);
    alg_class_method(k_subscriptexpr, "Accept", m_subscriptexpr_accept_1, 1, t_subscriptexpr_accept_1);
    alg_class_super(k_setsubscriptexpr, k_expr);
    alg_class_field(k_setsubscriptexpr, "Obj");
    alg_class_field(k_setsubscriptexpr, "Index");
    alg_class_field(k_setsubscriptexpr, "Value");
    alg_class_field(k_setsubscriptexpr, "Bracket");
    alg_class_initializer(k_setsubscriptexpr, i_setsubscriptexpr);
    alg_class_method(k_setsubscriptexpr, "Init", m_setsubscriptexpr_init_4_expr_expr_expr_token, 4, t_setsubscriptexpr_init_4_expr_expr_expr_token);
    alg_class_method(k_setsubscriptexpr, "Accept", m_setsubscriptexpr_accept_1, 1, t_setsubscriptexpr_accept_1);
    alg_class_super(k_literalexpr, k_expr);
    alg_class_field(k_literalexpr, "Value");
    alg_class_initializer(k_literalexpr, i_literalexpr);
    alg_class_method(k_literalexpr, "Init", m_literalexpr_init_1, 1, t_literalexpr_init_1);
    alg_class_method(k_literalexpr, "Accept", m_literalexpr_accept_1, 1, t_literalexpr_accept_1);
    alg_class_super(k_variableexpr, k_expr);
    alg_class_field(k_variableexpr, "Name");
    alg_class_initializer(k_variableexpr, i_variableexpr);
    alg_class_method(k_variableexpr, "Init", m_variableexpr_init_1_token, 1, t_variableexpr_init_1_token);
    alg_class_method(k_variableexpr, "Accept", m_variableexpr_accept_1, 1, t_variableexpr_accept_1);
    alg_class_super(k_assignexpr, k_expr);
    alg_class_field(k_assignexpr, "Name");
    alg_class_field(k_assignexpr, "Value");
    alg_class_field(k_assignexpr, "Declared");
    alg_class_field(k_assignexpr, "Actual");
    alg_class_initializer(k_assignexpr, i_assignexpr);
    alg_class_method(k_assignexpr, "Init", m_assignexpr_init_2_token_expr, 2, t_assignexpr_init_2_token_expr);
    alg_class_method(k_assignexpr, "Accept", m_assignexpr_accept_1, 1, t_assignexpr_accept_1);
    alg_class_super(k_unaryexpr, k_expr);
    alg_class_field(k_unaryexpr, "Op");
    alg_class_field(k_unaryexpr, "Right");
    alg_class_initializer(k_unaryexpr, i_unaryexpr);
    alg_class_method(k_unaryexpr, "Init", m_unaryexpr_init_2_token_expr, 2, t_unaryexpr_init_2_token_expr);
    alg_class_method(k_unaryexpr, "Accept", m_unaryexpr_accept_1, 1, t_unaryexpr_accept_1);
    alg_class_super(k_callexpr, k_expr);
    alg_class_field(k_callexpr, "Callee");
    alg_class_field(k_callexpr, "Paren");
    alg_class_field(k_callexpr, "Arguments");
    alg_class_field(k_callexpr, "ArgumentNames");
    alg_class_initializer(k_callexpr, i_callexpr);
    alg_class_method(k_callexpr, "Init", m_callexpr_init_3_expr_token_list, 3, t_callexpr_init_3_expr_token_list);
    alg_class_method(k_callexpr, "Accept", m_callexpr_accept_1, 1, t_callexpr_accept_1);
    alg_class_super(k_getexpr, k_expr);
    alg_class_field(k_getexpr, "Obj");
    alg_class_field(k_getexpr, "Name");
    alg_class_field(k_getexpr, "Unit");
    alg_class_field(k_getexpr, "Extension");
    alg_class_field(k_getexpr, "ExtensionUnit");
    alg_class_initializer(k_getexpr, i_getexpr);
    alg_class_method(k_getexpr, "Init", m_getexpr_init_2_expr_token, 2, t_getexpr_init_2_expr_token);
    alg_class_method(k_getexpr, "Accept", m_getexpr_accept_1, 1, t_getexpr_accept_1);
    alg_class_super(k_setexpr, k_expr);
    alg_class_field(k_setexpr, "Obj");
    alg_class_field(k_setexpr, "Name");
    alg_class_field(k_setexpr, "Value");
    alg_class_field(k_setexpr, "Unit");
    alg_class_field(k_setexpr, "Declared");
    alg_class_field(k_setexpr, "Actual");
    alg_class_initializer(k_setexpr, i_setexpr);
    alg_class_method(k_setexpr, "Init", m_setexpr_init_3_expr_token_expr, 3, t_setexpr_init_3_expr_token_expr);
    alg_class_method(k_setexpr, "Accept", m_setexpr_accept_1, 1, t_setexpr_accept_1);
    alg_class_super(k_thisexpr, k_expr);
    alg_class_field(k_thisexpr, "Keyword");
    alg_class_initializer(k_thisexpr, i_thisexpr);
    alg_class_method(k_thisexpr, "Init", m_thisexpr_init_1_token, 1, t_thisexpr_init_1_token);
    alg_class_method(k_thisexpr, "Accept", m_thisexpr_accept_1, 1, t_thisexpr_accept_1);
    alg_class_super(k_superexpr, k_expr);
    alg_class_field(k_superexpr, "Keyword");
    alg_class_field(k_superexpr, "Method");
    alg_class_initializer(k_superexpr, i_superexpr);
    alg_class_method(k_superexpr, "Init", m_superexpr_init_2_token_token, 2, t_superexpr_init_2_token_token);
    alg_class_method(k_superexpr, "Accept", m_superexpr_accept_1, 1, t_superexpr_accept_1);
    alg_class_super(k_isexpr, k_expr);
    alg_class_field(k_isexpr, "Obj");
    alg_class_field(k_isexpr, "TypeName");
    alg_class_initializer(k_isexpr, i_isexpr);
    alg_class_method(k_isexpr, "Init", m_isexpr_init_2_expr_token, 2, t_isexpr_init_2_expr_token);
    alg_class_method(k_isexpr, "Accept", m_isexpr_accept_1, 1, t_isexpr_accept_1);
    int32_t rh_11 = alg_hold_top;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
    alg_hold_top = rh_11;
}
