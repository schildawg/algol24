/* Generated from Algol-24.  Do not edit. */
#include "Token.h"
#include "TokenType.h"

Value f_FoldCase(Value **cells, Value *args, int32_t count);
Value v_FOLD_UPPER;
Value v_FOLD_LOWER;
Value fn_FoldCase;
Value k_Token;
static const char *t_Token_Init_4_TokenType_String_Integer[] = { "TokenType", "String", "Any", "Integer" };

Value f_FoldCase(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Text = alg_nil();
    (void)v_Text;
    Value v_Out = alg_nil();
    (void)v_Out;
    (void)((v_Text = alg_str(v_Name)));
    Value v_Needs = alg_bool(false);
    (void)v_Needs;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_length(v_Text)))) {
            {
                if (alg_truthy(alg_greater_equal(alg_pos(v_FOLD_UPPER, alg_str(alg_subscript_get(v_Text, v_I))), alg_int(0)))) {
                    (void)((v_Needs = alg_bool(true)));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_not(v_Needs))) {
        return v_Text;
    }
    (void)((v_Out = alg_buffer(alg_int(0))));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_length(v_Text)))) {
            {
                {
                    Value v_At = alg_pos(v_FOLD_UPPER, alg_str(alg_subscript_get(v_Text, v_I)));
                    (void)v_At;
                    if (alg_truthy(alg_greater_equal(v_At, alg_int(0)))) {
                        (void)(alg_invoke(v_Out, "Append", (Value[]){alg_copy(v_FOLD_LOWER, v_At, alg_int(1))}, 1));
                    } else {
                        (void)(alg_invoke(v_Out, "Append", (Value[]){alg_str(alg_subscript_get(v_Text, v_I))}, 1));
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_property(v_Out, "Text");
    return alg_nil();
}

static Value i_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "TypeOfToken", alg_nil());
    alg_set_property(v_this, "Lexeme", alg_nil());
    alg_set_property(v_this, "Literal", alg_nil());
    alg_set_property(v_this, "LineNumber", alg_nil());
    alg_set_property(v_this, "Offset", alg_int(0));
    return alg_nil();
}

static Value m_Token_Init_4_TokenType_String_Integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TypeOfToken = args[0];
    (void)v_TypeOfToken;
    Value v_Lexeme = args[1];
    (void)v_Lexeme;
    Value v_Literal = args[2];
    (void)v_Literal;
    Value v_LineNumber = args[3];
    (void)v_LineNumber;
    (void)(alg_set_property(v_this, "TypeOfToken", v_TypeOfToken));
    (void)(alg_set_property(v_this, "Lexeme", v_Lexeme));
    (void)(alg_set_property(v_this, "Literal", v_Literal));
    (void)(alg_set_property(v_this, "LineNumber", v_LineNumber));
    return alg_nil();
}

static Value m_Token_ToString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_add(alg_add(alg_add(alg_add(alg_str(alg_property(v_this, "TypeOfToken")), alg_char_value(32)), alg_property(v_this, "Lexeme")), alg_char_value(32)), alg_property(v_this, "Literal"));
    return alg_nil();
}

void init_Token(void) {
    fn_FoldCase = alg_closure("FoldCase", f_FoldCase, NULL, 0, 1);
    k_Token = alg_class("Token", alg_nil());
    alg_class_field(k_Token, "TypeOfToken");
    alg_class_field(k_Token, "Lexeme");
    alg_class_field(k_Token, "Literal");
    alg_class_field(k_Token, "LineNumber");
    alg_class_field(k_Token, "Offset");
    alg_class_initializer(k_Token, i_Token);
    alg_class_method(k_Token, "Init", m_Token_Init_4_TokenType_String_Integer, 4, t_Token_Init_4_TokenType_String_Integer);
    alg_class_method(k_Token, "ToString", m_Token_ToString_0, 0, NULL);
    v_FOLD_UPPER = alg_string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    v_FOLD_LOWER = alg_string("abcdefghijklmnopqrstuvwxyz");
}
