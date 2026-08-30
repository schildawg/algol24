/* Generated from Algol-24.  Do not edit. */
#include "Token.h"
#include "TokenType.h"

Value f_foldcase(Value **cells, Value *args, int32_t count);
Value v_foldVupper;
bool d_foldVupper;
Value v_foldVlower;
bool d_foldVlower;
Value fn_foldcase;
Value k_token;
static const char *t_token_init_4_tokentype_string_integer[] = { "TokenType", "String", "Any", "Integer" };

Value f_foldcase(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_name = args[0];
    (void)v_name;
    Value v_text = alg_nil();
    (void)v_text;
    Value v_out = alg_nil();
    (void)v_out;
    (void)((v_text = alg_widen(alg_str(v_name), "String")));
    Value v_needs = alg_bool(false);
    (void)v_needs;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_text_length(v_text)))) {
            {
                if (alg_truthy(alg_greater_equal(alg_pos((alg_declared(d_foldVupper, "FOLD_UPPER"), v_foldVupper), alg_str(alg_subscript_get(v_text, v_i))), alg_int(0)))) {
                    (void)((v_needs = alg_bool(true)));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_not(v_needs))) {
        return v_text;
    }
    (void)((v_out = alg_widen(alg_buffer(alg_int(0)), "Buffer")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_text_length(v_text)))) {
            {
                {
                    Value v_at = alg_pos((alg_declared(d_foldVupper, "FOLD_UPPER"), v_foldVupper), alg_str(alg_subscript_get(v_text, v_i)));
                    (void)v_at;
                    if (alg_truthy(alg_greater_equal(v_at, alg_int(0)))) {
                        (void)(alg_invoke(v_out, "Append", (Value[]){alg_copy((alg_declared(d_foldVlower, "FOLD_LOWER"), v_foldVlower), v_at, alg_int(1))}, 1));
                    } else {
                        (void)(alg_invoke(v_out, "Append", (Value[]){alg_str(alg_subscript_get(v_text, v_i))}, 1));
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_property(v_out, "Text");
    return alg_nil();
}

static Value i_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "TypeOfToken", alg_nil());
    alg_set_property(v_this, "Lexeme", alg_nil());
    alg_set_property(v_this, "Literal", alg_nil());
    alg_set_property(v_this, "LineNumber", alg_nil());
    alg_set_property(v_this, "Offset", alg_widen(alg_int(0), "Integer"));
    return alg_nil();
}

static Value m_token_init_4_tokentype_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_typeoftoken = alg_widen(args[0], "TokenType");
    (void)v_typeoftoken;
    Value v_lexeme = alg_widen(args[1], "String");
    (void)v_lexeme;
    Value v_literal = args[2];
    (void)v_literal;
    Value v_linenumber = alg_widen(args[3], "Integer");
    (void)v_linenumber;
    (void)(alg_set_property(v_this, "TypeOfToken", alg_widen(v_typeoftoken, "TokenType")));
    (void)(alg_set_property(v_this, "Lexeme", alg_widen(v_lexeme, "String")));
    (void)(alg_set_property(v_this, "Literal", v_literal));
    (void)(alg_set_property(v_this, "LineNumber", alg_widen(v_linenumber, "Integer")));
    return alg_nil();
}

static Value m_token_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_add(alg_add(alg_add(alg_add(alg_str(alg_property(v_this, "TypeOfToken")), alg_char_value(32)), alg_property(v_this, "Lexeme")), alg_char_value(32)), alg_property(v_this, "Literal"));
    return alg_nil();
}

void init_Token(void) {
    k_token = alg_class("Token", alg_nil());
    fn_foldcase = alg_closure("FoldCase", f_foldcase, NULL, 0, 1);
    alg_class_field(k_token, "TypeOfToken");
    alg_class_field(k_token, "Lexeme");
    alg_class_field(k_token, "Literal");
    alg_class_field(k_token, "LineNumber");
    alg_class_field(k_token, "Offset");
    alg_class_initializer(k_token, i_token);
    alg_class_method(k_token, "Init", m_token_init_4_tokentype_string_integer, 4, t_token_init_4_tokentype_string_integer);
    alg_class_method(k_token, "ToString", m_token_tostring_0, 0, NULL);
    init_TokenType();
    v_foldVupper = alg_string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    d_foldVupper = true;
    v_foldVlower = alg_string("abcdefghijklmnopqrstuvwxyz");
    d_foldVlower = true;
}
