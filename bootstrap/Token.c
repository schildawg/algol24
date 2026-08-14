/* Generated from Algol-24.  Do not edit. */
#include "Token.h"
#include "TokenType.h"

Value k_Token;
static const char *t_Token_Init_4_TokenType_String_Integer[] = { "TokenType", "String", "Any", "Integer" };

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
    k_Token = alg_class("Token", alg_nil());
    alg_class_field(k_Token, "TypeOfToken");
    alg_class_field(k_Token, "Lexeme");
    alg_class_field(k_Token, "Literal");
    alg_class_field(k_Token, "LineNumber");
    alg_class_field(k_Token, "Offset");
    alg_class_initializer(k_Token, i_Token);
    alg_class_method(k_Token, "Init", m_Token_Init_4_TokenType_String_Integer, 4, t_Token_Init_4_TokenType_String_Integer);
    alg_class_method(k_Token, "ToString", m_Token_ToString_0, 0, NULL);
}
