/* Generated from Algol-24.  Do not edit. */
#include "AstPrinter.h"
#include "Expr.h"
#include "Token.h"
#include "TokenType.h"

Value k_AstPrinter;
static const char *t_AstPrinter_DoPrint_1[] = { "Any" };
static const char *t_AstPrinter_VisitBinary_1[] = { "Any" };
static const char *t_AstPrinter_VisitGrouping_1[] = { "Any" };
static const char *t_AstPrinter_VisitLiteral_1[] = { "Any" };
static const char *t_AstPrinter_VisitUnary_1[] = { "Any" };
static const char *t_AstPrinter_Parenthesize_2[] = { "Any", "Any" };

static Value i_AstPrinter(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_nil();
}

static Value m_AstPrinter_DoPrint_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Expr = args[0];
    (void)v_Expr;
    return alg_invoke(v_Expr, "Accept", (Value[]){v_this}, 1);
    return alg_nil();
}

static Value m_AstPrinter_VisitBinary_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Expr = args[0];
    (void)v_Expr;
    Value v_Exprs = alg_list();
    (void)v_Exprs;
    (void)(alg_invoke(v_Exprs, "Add", (Value[]){alg_property(v_Expr, "Left")}, 1));
    (void)(alg_invoke(v_Exprs, "Add", (Value[]){alg_property(v_Expr, "Right")}, 1));
    return alg_invoke(v_this, "Parenthesize", (Value[]){alg_property(alg_property(v_Expr, "Op"), "Lexeme"), v_Exprs}, 2);
    return alg_nil();
}

static Value m_AstPrinter_VisitGrouping_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Expr = args[0];
    (void)v_Expr;
    Value v_Exprs = alg_list();
    (void)v_Exprs;
    (void)(alg_invoke(v_Exprs, "Add", (Value[]){alg_property(v_Expr, "Expression")}, 1));
    return alg_invoke(v_this, "Parenthesize", (Value[]){alg_string("group"), v_Exprs}, 2);
    return alg_nil();
}

static Value m_AstPrinter_VisitLiteral_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Expr = args[0];
    (void)v_Expr;
    if (alg_truthy(alg_equal(alg_property(v_Expr, "Value"), alg_nil()))) {
        return alg_nil();
    }
    return alg_str(alg_property(v_Expr, "Value"));
    return alg_nil();
}

static Value m_AstPrinter_VisitUnary_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Expr = args[0];
    (void)v_Expr;
    Value v_Exprs = alg_list();
    (void)v_Exprs;
    (void)(alg_invoke(v_Exprs, "Add", (Value[]){alg_property(v_Expr, "Right")}, 1));
    return alg_invoke(v_this, "Parenthesize", (Value[]){alg_property(alg_property(v_Expr, "Op"), "Lexeme"), v_Exprs}, 2);
    return alg_nil();
}

static Value m_AstPrinter_Parenthesize_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Exprs = args[1];
    (void)v_Exprs;
    Value v_Builder = alg_add(alg_str(alg_char_value(40)), v_Name);
    (void)v_Builder;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Exprs, "Length")))) {
            {
                {
                    (void)((v_Builder = alg_add(v_Builder, alg_char_value(32))));
                    (void)((v_Builder = alg_add(v_Builder, alg_invoke(alg_subscript_get(v_Exprs, v_I), "Accept", (Value[]){v_this}, 1))));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)((v_Builder = alg_add(v_Builder, alg_char_value(41))));
    return v_Builder;
    return alg_nil();
}

void init_AstPrinter(void) {
    k_AstPrinter = alg_class("AstPrinter", alg_nil());
    alg_class_initializer(k_AstPrinter, i_AstPrinter);
    alg_class_method(k_AstPrinter, "DoPrint", m_AstPrinter_DoPrint_1, 1, t_AstPrinter_DoPrint_1);
    alg_class_method(k_AstPrinter, "VisitBinary", m_AstPrinter_VisitBinary_1, 1, t_AstPrinter_VisitBinary_1);
    alg_class_method(k_AstPrinter, "VisitGrouping", m_AstPrinter_VisitGrouping_1, 1, t_AstPrinter_VisitGrouping_1);
    alg_class_method(k_AstPrinter, "VisitLiteral", m_AstPrinter_VisitLiteral_1, 1, t_AstPrinter_VisitLiteral_1);
    alg_class_method(k_AstPrinter, "VisitUnary", m_AstPrinter_VisitUnary_1, 1, t_AstPrinter_VisitUnary_1);
    alg_class_method(k_AstPrinter, "Parenthesize", m_AstPrinter_Parenthesize_2, 2, t_AstPrinter_Parenthesize_2);
}
