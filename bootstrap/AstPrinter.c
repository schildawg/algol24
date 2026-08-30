/* Generated from Algol-24.  Do not edit. */
#include "AstPrinter.h"
#include "Expr.h"
#include "Token.h"
#include "TokenType.h"

Value k_astprinter;
static const char *t_astprinter_doprint_1[] = { "Any" };
static const char *t_astprinter_visitbinary_1[] = { "Any" };
static const char *t_astprinter_visitgrouping_1[] = { "Any" };
static const char *t_astprinter_visitliteral_1[] = { "Any" };
static const char *t_astprinter_visitunary_1[] = { "Any" };
static const char *t_astprinter_parenthesize_2[] = { "Any", "Any" };

static Value i_astprinter(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_astprinter_doprint_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_expr = args[0];
    (void)v_expr;
    return alg_invoke(v_expr, "Accept", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value m_astprinter_visitbinary_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_expr = args[0];
    (void)v_expr;
    Value v_exprs = alg_list();
    (void)v_exprs;
    (void)(alg_invoke(v_exprs, "Add", (Value[]){alg_property(v_expr, "Left")}, 1));
    (void)(alg_invoke(v_exprs, "Add", (Value[]){alg_property(v_expr, "Right")}, 1));
    return alg_invoke(v_this, "Parenthesize", (Value[]){alg_property(alg_property(v_expr, "Op"), "Lexeme"), v_exprs}, 2);
    return alg_nil();
}

static Value m_astprinter_visitgrouping_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_expr = args[0];
    (void)v_expr;
    Value v_exprs = alg_list();
    (void)v_exprs;
    (void)(alg_invoke(v_exprs, "Add", (Value[]){alg_property(v_expr, "Expression")}, 1));
    return alg_invoke(v_this, "Parenthesize", (Value[]){alg_string("group"), v_exprs}, 2);
    return alg_nil();
}

static Value m_astprinter_visitliteral_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_expr = args[0];
    (void)v_expr;
    if (alg_truthy(alg_equal(alg_property(v_expr, "Value"), alg_nil()))) {
        return alg_nil();
    }
    return alg_str(alg_property(v_expr, "Value"));
    return alg_nil();
}

static Value m_astprinter_visitunary_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_expr = args[0];
    (void)v_expr;
    Value v_exprs = alg_list();
    (void)v_exprs;
    (void)(alg_invoke(v_exprs, "Add", (Value[]){alg_property(v_expr, "Right")}, 1));
    return alg_invoke(v_this, "Parenthesize", (Value[]){alg_property(alg_property(v_expr, "Op"), "Lexeme"), v_exprs}, 2);
    return alg_nil();
}

static Value m_astprinter_parenthesize_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = args[0];
    (void)v_name;
    Value v_exprs = args[1];
    (void)v_exprs;
    Value v_builder = alg_add(alg_str(alg_char_value(40)), v_name);
    (void)v_builder;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_exprs, "Length")))) {
            {
                {
                    (void)((v_builder = alg_add(v_builder, alg_char_value(32))));
                    (void)((v_builder = alg_add(v_builder, alg_invoke(alg_subscript_get(v_exprs, v_i), "Accept", (Value[]){v_this}, 1))));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    (void)((v_builder = alg_add(v_builder, alg_char_value(41))));
    return v_builder;
    return alg_nil();
}

void init_AstPrinter(void) {
    k_astprinter = alg_class("AstPrinter", alg_nil());
    alg_class_initializer(k_astprinter, i_astprinter);
    alg_class_method(k_astprinter, "DoPrint", m_astprinter_doprint_1, 1, t_astprinter_doprint_1);
    alg_class_method(k_astprinter, "VisitBinary", m_astprinter_visitbinary_1, 1, t_astprinter_visitbinary_1);
    alg_class_method(k_astprinter, "VisitGrouping", m_astprinter_visitgrouping_1, 1, t_astprinter_visitgrouping_1);
    alg_class_method(k_astprinter, "VisitLiteral", m_astprinter_visitliteral_1, 1, t_astprinter_visitliteral_1);
    alg_class_method(k_astprinter, "VisitUnary", m_astprinter_visitunary_1, 1, t_astprinter_visitunary_1);
    alg_class_method(k_astprinter, "Parenthesize", m_astprinter_parenthesize_2, 2, t_astprinter_parenthesize_2);
    init_Expr();
}
