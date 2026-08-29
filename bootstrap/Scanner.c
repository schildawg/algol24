/* Generated from Algol-24.  Do not edit. */
#include "Scanner.h"
#include "SourceCode.h"
#include "Token.h"
#include "TokenType.h"
#include "Unicode.h"

Value f_ToLower(Value **cells, Value *args, int32_t count);
Value f_ToInteger(Value **cells, Value *args, int32_t count);
Value f_ExceedsInteger(Value **cells, Value *args, int32_t count);
Value v_DIGITS;
Value v_UPPERCASE;
Value v_LOWERCASE;
Value fn_ToLower;
Value fn_ToInteger;
static Value or_0;
Value fn_ExceedsInteger;
Value v_Keywords;
Value v_HadError;
Value v_LastError;
Value k_Scanner;
static Value or_1;
static Value or_2;
static Value or_3;
static Value or_4;
static Value or_5;
static Value or_6;
static Value or_7;
static Value or_8;
static Value or_9;
static Value or_10;
static Value or_11;
static Value or_12;
static const char *t_Scanner_Init_1[] = { "Any" };
static const char *t_Scanner_Match_1_Char[] = { "Char" };
static const char *t_Scanner_AddToken_1_TokenType[] = { "TokenType" };
static const char *t_Scanner_AddToken_2_TokenType[] = { "TokenType", "Any" };
static const char *t_Scanner_IsAlpha_1_Char[] = { "Char" };
static const char *t_Scanner_IsMark_1_Char[] = { "Char" };
static const char *t_Scanner_IsAlphaNumeric_1_Char[] = { "Char" };
static const char *t_Scanner_IsDigit_1_Char[] = { "Char" };

Value f_ToLower(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Text = args[0];
    (void)v_Text;
    Value v_Result = alg_string("");
    (void)v_Result;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_length(v_Text)))) {
            {
                {
                    Value v_C = alg_copy(v_Text, v_I, alg_int(1));
                    (void)v_C;
                    Value v_At = alg_pos(v_UPPERCASE, v_C);
                    (void)v_At;
                    if (alg_truthy(alg_greater_equal(v_At, alg_int(0)))) {
                        (void)((v_Result = alg_add(v_Result, alg_copy(v_LOWERCASE, v_At, alg_int(1)))));
                    } else {
                        (void)((v_Result = alg_add(v_Result, v_C)));
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Result;
    return alg_nil();
}

Value f_ToInteger(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Text = args[0];
    (void)v_Text;
    Value v_Result = alg_int(0);
    (void)v_Result;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_length(v_Text)))) {
            {
                (void)((v_Result = alg_add(alg_multiply(v_Result, alg_int(10)), alg_pos(v_DIGITS, alg_copy(v_Text, v_I, alg_int(1))))));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Result;
    return alg_nil();
}

Value f_ExceedsInteger(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Text = args[0];
    (void)v_Text;
    Value v_Body = alg_nil();
    (void)v_Body;
    (void)((v_Body = v_Text));
    while (alg_truthy((or_0 = alg_greater(alg_length(v_Body), alg_int(1)), !alg_truthy(or_0) ? or_0 : alg_equal(alg_subscript_get(v_Body, alg_int(0)), alg_char_value(48))))) {
        (void)((v_Body = alg_copy(v_Body, alg_int(1), alg_subtract(alg_length(v_Body), alg_int(1)))));
    }
    if (alg_truthy(alg_less(alg_length(v_Body), alg_int(10)))) {
        return alg_bool(false);
    }
    if (alg_truthy(alg_greater(alg_length(v_Body), alg_int(10)))) {
        return alg_bool(true);
    }
    Value v_Limit = alg_string("2147483647");
    (void)v_Limit;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_int(10)))) {
            {
                {
                    if (alg_truthy(alg_greater(alg_subscript_get(v_Body, v_I), alg_subscript_get(v_Limit, v_I)))) {
                        return alg_bool(true);
                    }
                    if (alg_truthy(alg_less(alg_subscript_get(v_Body, v_I), alg_subscript_get(v_Limit, v_I)))) {
                        return alg_bool(false);
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value i_Scanner(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Source", alg_nil());
    alg_set_property(v_this, "Tokens", alg_nil());
    alg_set_property(v_this, "Current", alg_nil());
    alg_set_property(v_this, "Start", alg_nil());
    alg_set_property(v_this, "Line", alg_nil());
    alg_set_property(v_this, "LineStart", alg_nil());
    return alg_nil();
}

static Value m_Scanner_Init_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Source = args[0];
    (void)v_Source;
    (void)(alg_set_property(v_this, "Source", alg_str(v_Source)));
    (void)(alg_set_property(v_this, "Current", alg_int(0)));
    (void)(alg_set_property(v_this, "Start", alg_int(0)));
    (void)(alg_set_property(v_this, "Line", alg_int(1)));
    (void)(alg_set_property(v_this, "LineStart", alg_int(0)));
    (void)(alg_set_property(v_this, "Tokens", alg_list()));
    return alg_nil();
}

static Value m_Scanner_ScanTokens_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    while (alg_truthy(alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        {
            (void)(alg_set_property(v_this, "Start", alg_property(v_this, "Current")));
            (void)(alg_invoke(v_this, "ScanToken", NULL, 0));
        }
    }
    (void)(alg_invoke(alg_singleton(k_SourceCode), "Add", (Value[]){alg_property(v_this, "Line"), alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "LineStart"), alg_subtract(alg_length(alg_property(v_this, "Source")), alg_property(v_this, "LineStart")))}, 2));
    (void)(alg_invoke(alg_property(v_this, "Tokens"), "Add", (Value[]){alg_new(k_Token, (Value[]){e_TokenType_EOF, alg_string(""), alg_nil(), alg_property(v_this, "Line")}, 4)}, 1));
    return alg_property(v_this, "Tokens");
    return alg_nil();
}

static Value m_Scanner_ScanToken_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_C = alg_nil();
    (void)v_C;
    (void)((v_C = alg_invoke(v_this, "Advance", NULL, 0)));
    if (alg_truthy(alg_equal(v_C, alg_char_value(40)))) {
        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_LEFT_PAREN}, 1));
    } else {
        if (alg_truthy(alg_equal(v_C, alg_char_value(41)))) {
            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_RIGHT_PAREN}, 1));
        } else {
            if (alg_truthy(alg_equal(v_C, alg_char_value(91)))) {
                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_LEFT_BRACKET}, 1));
            } else {
                if (alg_truthy(alg_equal(v_C, alg_char_value(93)))) {
                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_RIGHT_BRACKET}, 1));
                } else {
                    if (alg_truthy(alg_equal(v_C, alg_char_value(44)))) {
                        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_COMMA}, 1));
                    } else {
                        if (alg_truthy(alg_equal(v_C, alg_char_value(46)))) {
                            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_DOT}, 1));
                        } else {
                            if (alg_truthy(alg_equal(v_C, alg_char_value(45)))) {
                                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_MINUS}, 1));
                            } else {
                                if (alg_truthy(alg_equal(v_C, alg_char_value(43)))) {
                                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_PLUS}, 1));
                                } else {
                                    if (alg_truthy(alg_equal(v_C, alg_char_value(59)))) {
                                        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_SEMICOLON}, 1));
                                    } else {
                                        if (alg_truthy(alg_equal(v_C, alg_char_value(42)))) {
                                            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_STAR}, 1));
                                        } else {
                                            if (alg_truthy(alg_equal(v_C, alg_char_value(61)))) {
                                                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_EQUAL}, 1));
                                            } else {
                                                if (alg_truthy(alg_equal(v_C, alg_char_value(58)))) {
                                                    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(61)}, 1))) {
                                                        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_ASSIGN}, 1));
                                                    } else {
                                                        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_COLON}, 1));
                                                    }
                                                } else {
                                                    if (alg_truthy(alg_equal(v_C, alg_char_value(62)))) {
                                                        if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(61)}, 1))) {
                                                            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_GREATER_EQUAL}, 1));
                                                        } else {
                                                            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_GREATER}, 1));
                                                        }
                                                    } else {
                                                        if (alg_truthy(alg_equal(v_C, alg_char_value(60)))) {
                                                            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(62)}, 1))) {
                                                                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_NOT_EQUAL}, 1));
                                                            } else {
                                                                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(61)}, 1))) {
                                                                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_LESS_EQUAL}, 1));
                                                                } else {
                                                                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_LESS}, 1));
                                                                }
                                                            }
                                                        } else {
                                                            if (alg_truthy(alg_equal(v_C, alg_char_value(47)))) {
                                                                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(47)}, 1))) {
                                                                    while (alg_truthy((or_1 = alg_not_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(10)), !alg_truthy(or_1) ? or_1 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
                                                                        (void)(alg_invoke(v_this, "Advance", NULL, 0));
                                                                    }
                                                                } else {
                                                                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_SLASH}, 1));
                                                                }
                                                            } else {
                                                                if (alg_truthy((or_3 = (or_2 = alg_equal(v_C, alg_char_value(9)), alg_truthy(or_2) ? or_2 : alg_equal(v_C, alg_char_value(13))), alg_truthy(or_3) ? or_3 : alg_equal(v_C, alg_char_value(32))))) {
                                                                    return alg_nil();
                                                                } else {
                                                                    if (alg_truthy(alg_equal(v_C, alg_char_value(10)))) {
                                                                        {
                                                                            (void)(alg_invoke(alg_singleton(k_SourceCode), "Add", (Value[]){alg_property(v_this, "Line"), alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "LineStart"), alg_subtract(alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "LineStart")), alg_int(1)))}, 2));
                                                                            (void)(alg_set_property(v_this, "Line", alg_add(alg_property(v_this, "Line"), alg_int(1))));
                                                                            (void)(alg_set_property(v_this, "LineStart", alg_property(v_this, "Current")));
                                                                            return alg_nil();
                                                                        }
                                                                    } else {
                                                                        if (alg_truthy(alg_equal(v_C, alg_char_value(39)))) {
                                                                            (void)(alg_invoke(v_this, "ScanString", NULL, 0));
                                                                        } else {
                                                                            if (alg_truthy(alg_equal(v_C, alg_char_value(35)))) {
                                                                                (void)(alg_invoke(v_this, "ScanChar", NULL, 0));
                                                                            } else {
                                                                                if (alg_truthy(alg_invoke(v_this, "IsAlpha", (Value[]){v_C}, 1))) {
                                                                                    (void)(alg_invoke(v_this, "ScanIdentifier", NULL, 0));
                                                                                } else {
                                                                                    if (alg_truthy(alg_invoke(v_this, "IsDigit", (Value[]){v_C}, 1))) {
                                                                                        (void)(alg_invoke(v_this, "ScanNumber", NULL, 0));
                                                                                    } else {
                                                                                        {
                                                                                            (void)((v_HadError = alg_bool(true)));
                                                                                            (void)((v_LastError = alg_add(alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: Unexpected character: ")), v_C)));
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return alg_nil();
}

static Value m_Scanner_ScanIdentifier_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Text = alg_nil();
    (void)v_Text;
    Value v_TypeOfToken = alg_nil();
    (void)v_TypeOfToken;
    while (alg_truthy(alg_invoke(v_this, "IsAlphaNumeric", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1))) {
        (void)(alg_invoke(v_this, "Advance", NULL, 0));
    }
    (void)((v_Text = alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "Start"), alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start")))));
    (void)((v_TypeOfToken = e_TokenType_TOKEN_IDENTIFIER));
    Value v_Lowered = f_ToLower(NULL, (Value[]){v_Text}, 1);
    (void)v_Lowered;
    if (alg_truthy(alg_invoke(v_Keywords, "Contains", (Value[]){v_Lowered}, 1))) {
        {
            (void)((v_TypeOfToken = alg_invoke(v_Keywords, "Get", (Value[]){v_Lowered}, 1)));
        }
    }
    (void)(alg_invoke(v_this, "AddToken", (Value[]){v_TypeOfToken}, 1));
    return alg_nil();
}

static Value m_Scanner_ScanNumber_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_IsInteger = alg_nil();
    (void)v_IsInteger;
    (void)((v_IsInteger = alg_bool(true)));
    while (alg_truthy(alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1))) {
        (void)(alg_invoke(v_this, "Advance", NULL, 0));
    }
    if (alg_truthy((or_4 = alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(46)), !alg_truthy(or_4) ? or_4 : alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "PeekNext", NULL, 0)}, 1)))) {
        {
            (void)((v_IsInteger = alg_bool(false)));
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
        }
    }
    while (alg_truthy(alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1))) {
        (void)(alg_invoke(v_this, "Advance", NULL, 0));
    }
    Value v_Text = alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "Start"), alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start")));
    (void)v_Text;
    if (alg_truthy(v_IsInteger)) {
        {
            if (alg_truthy(f_ExceedsInteger(NULL, (Value[]){v_Text}, 1))) {
                {
                    (void)((v_HadError = alg_bool(true)));
                    (void)((v_LastError = alg_add(alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: Integer literal out of range: ")), v_Text)));
                    return alg_nil();
                }
            }
            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_INTEGER, f_ToInteger(NULL, (Value[]){v_Text}, 1)}, 2));
        }
    } else {
        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_NUMBER, alg_val(v_Text)}, 2));
    }
    return alg_nil();
}

static Value m_Scanner_ScanString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Value = alg_nil();
    (void)v_Value;
    Value v_Opened = alg_nil();
    (void)v_Opened;
    (void)((v_Value = alg_string("")));
    (void)((v_Opened = alg_property(v_this, "Line")));
    while (alg_truthy(alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        {
            if (alg_truthy(alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(39)))) {
                {
                    if (alg_truthy(alg_not_equal(alg_invoke(v_this, "PeekNext", NULL, 0), alg_char_value(39)))) {
                        break;
                    }
                    (void)(alg_invoke(v_this, "Advance", NULL, 0));
                }
            }
            if (alg_truthy(alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(10)))) {
                (void)(alg_set_property(v_this, "Line", alg_add(alg_property(v_this, "Line"), alg_int(1))));
            }
            (void)((v_Value = alg_add(v_Value, alg_invoke(v_this, "Advance", NULL, 0))));
        }
    }
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        {
            (void)((v_HadError = alg_bool(true)));
            (void)((v_LastError = alg_add(alg_add(alg_string("[line "), v_Opened), alg_string("] Error: Unterminated string."))));
            return alg_nil();
        }
    }
    (void)(alg_invoke(v_this, "Advance", NULL, 0));
    if (alg_truthy(alg_equal(alg_length(v_Value), alg_int(1)))) {
        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_CHAR, alg_subscript_get(v_Value, alg_int(0))}, 2));
    } else {
        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_STRING, v_Value}, 2));
    }
    return alg_nil();
}

static Value m_Scanner_ScanChar_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_not(alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1)))) {
        {
            (void)((v_HadError = alg_bool(true)));
            (void)((v_LastError = alg_add(alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: Invalid character: ")), alg_invoke(v_this, "Peek", NULL, 0))));
            return alg_nil();
        }
    }
    while (alg_truthy(alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1))) {
        (void)(alg_invoke(v_this, "Advance", NULL, 0));
    }
    Value v_Code = f_ToInteger(NULL, (Value[]){alg_copy(alg_property(v_this, "Source"), alg_add(alg_property(v_this, "Start"), alg_int(1)), alg_subtract(alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start")), alg_int(1)))}, 1);
    (void)v_Code;
    if (alg_truthy(alg_equal(v_Code, alg_int(0)))) {
        {
            (void)((v_HadError = alg_bool(true)));
            (void)((v_LastError = alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: '#0' is not a Char."))));
            return alg_nil();
        }
    }
    if (alg_truthy((or_6 = alg_greater(v_Code, alg_int(1114111)), alg_truthy(or_6) ? or_6 : ((or_5 = alg_greater_equal(v_Code, alg_int(55296)), !alg_truthy(or_5) ? or_5 : alg_less_equal(v_Code, alg_int(57343))))))) {
        {
            (void)((v_HadError = alg_bool(true)));
            (void)((v_LastError = alg_add(alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: Char is limited to 0..10FFFF, excluding D800..DFFF: #")), v_Code)));
            return alg_nil();
        }
    }
    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_TokenType_TOKEN_CHAR, alg_char(v_Code)}, 2));
    return alg_nil();
}

static Value m_Scanner_Match_1_Char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Expected = args[0];
    (void)v_Expected;
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        return alg_bool(false);
    }
    if (alg_truthy(alg_not_equal(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Current")), v_Expected))) {
        return alg_bool(false);
    }
    (void)(alg_set_property(v_this, "Current", alg_add(alg_property(v_this, "Current"), alg_int(1))));
    return alg_bool(true);
    return alg_nil();
}

static Value m_Scanner_Peek_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        return alg_char(alg_int(0));
    }
    return alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Current"));
    return alg_nil();
}

static Value m_Scanner_PeekNext_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_greater_equal(alg_add(alg_property(v_this, "Current"), alg_int(1)), alg_length(alg_property(v_this, "Source"))))) {
        return alg_char(alg_int(0));
    }
    return alg_subscript_get(alg_property(v_this, "Source"), alg_add(alg_property(v_this, "Current"), alg_int(1)));
    return alg_nil();
}

static Value m_Scanner_AddToken_1_TokenType(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TypeOfToken = args[0];
    (void)v_TypeOfToken;
    (void)(alg_invoke(v_this, "AddToken", (Value[]){v_TypeOfToken, alg_nil()}, 2));
    return alg_nil();
}

static Value m_Scanner_AddToken_2_TokenType(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TypeOfToken = args[0];
    (void)v_TypeOfToken;
    Value v_Literal = args[1];
    (void)v_Literal;
    Value v_Text = alg_nil();
    (void)v_Text;
    Value v_TheToken = alg_nil();
    (void)v_TheToken;
    (void)((v_Text = alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "Start"), alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start")))));
    (void)((v_TheToken = alg_new(k_Token, (Value[]){v_TypeOfToken, v_Text, v_Literal, alg_property(v_this, "Line")}, 4)));
    (void)(alg_set_property(v_TheToken, "Offset", alg_subtract(alg_property(v_this, "Start"), alg_property(v_this, "LineStart"))));
    (void)(alg_invoke(alg_property(v_this, "Tokens"), "Add", (Value[]){v_TheToken}, 1));
    return alg_nil();
}

static Value m_Scanner_IsAtEnd_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_greater_equal(alg_property(v_this, "Current"), alg_length(alg_property(v_this, "Source")));
    return alg_nil();
}

static Value m_Scanner_Advance_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_ReturnValue = alg_nil();
    (void)v_ReturnValue;
    (void)((v_ReturnValue = alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Current"))));
    (void)(alg_set_property(v_this, "Current", alg_add(alg_property(v_this, "Current"), alg_int(1))));
    return v_ReturnValue;
    return alg_nil();
}

static Value m_Scanner_IsAlpha_1_Char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_C = args[0];
    (void)v_C;
    if (alg_truthy((or_7 = alg_greater_equal(v_C, alg_char_value(97)), !alg_truthy(or_7) ? or_7 : alg_less_equal(v_C, alg_char_value(122))))) {
        return alg_bool(true);
    }
    if (alg_truthy((or_8 = alg_greater_equal(v_C, alg_char_value(65)), !alg_truthy(or_8) ? or_8 : alg_less_equal(v_C, alg_char_value(90))))) {
        return alg_bool(true);
    }
    if (alg_truthy(alg_equal(v_C, alg_char_value(95)))) {
        return alg_bool(true);
    }
    if (alg_truthy(alg_less(alg_ord(v_C), alg_int(128)))) {
        return alg_bool(false);
    }
    return f_IsLetterCode(NULL, (Value[]){alg_ord(v_C)}, 1);
    return alg_nil();
}

static Value m_Scanner_IsMark_1_Char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_C = args[0];
    (void)v_C;
    return (or_9 = (alg_equal(v_C, alg_char_value(63))), alg_truthy(or_9) ? or_9 : (alg_equal(v_C, alg_char_value(33))));
    return alg_nil();
}

static Value m_Scanner_IsAlphaNumeric_1_Char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_C = args[0];
    (void)v_C;
    return (or_11 = (or_10 = alg_invoke(v_this, "IsAlpha", (Value[]){v_C}, 1), alg_truthy(or_10) ? or_10 : alg_invoke(v_this, "IsDigit", (Value[]){v_C}, 1)), alg_truthy(or_11) ? or_11 : alg_invoke(v_this, "IsMark", (Value[]){v_C}, 1));
    return alg_nil();
}

static Value m_Scanner_IsDigit_1_Char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_C = args[0];
    (void)v_C;
    return (or_12 = alg_greater_equal(v_C, alg_char_value(48)), !alg_truthy(or_12) ? or_12 : alg_less_equal(v_C, alg_char_value(57)));
    return alg_nil();
}

void init_Scanner(void) {
    fn_ToLower = alg_closure("ToLower", f_ToLower, NULL, 0, 1);
    fn_ToInteger = alg_closure("ToInteger", f_ToInteger, NULL, 0, 1);
    fn_ExceedsInteger = alg_closure("ExceedsInteger", f_ExceedsInteger, NULL, 0, 1);
    k_Scanner = alg_class("Scanner", alg_nil());
    alg_class_field(k_Scanner, "Source");
    alg_class_field(k_Scanner, "Tokens");
    alg_class_field(k_Scanner, "Current");
    alg_class_field(k_Scanner, "Start");
    alg_class_field(k_Scanner, "Line");
    alg_class_field(k_Scanner, "LineStart");
    alg_class_initializer(k_Scanner, i_Scanner);
    alg_class_method(k_Scanner, "Init", m_Scanner_Init_1, 1, t_Scanner_Init_1);
    alg_class_method(k_Scanner, "ScanTokens", m_Scanner_ScanTokens_0, 0, NULL);
    alg_class_method(k_Scanner, "ScanToken", m_Scanner_ScanToken_0, 0, NULL);
    alg_class_method(k_Scanner, "ScanIdentifier", m_Scanner_ScanIdentifier_0, 0, NULL);
    alg_class_method(k_Scanner, "ScanNumber", m_Scanner_ScanNumber_0, 0, NULL);
    alg_class_method(k_Scanner, "ScanString", m_Scanner_ScanString_0, 0, NULL);
    alg_class_method(k_Scanner, "ScanChar", m_Scanner_ScanChar_0, 0, NULL);
    alg_class_method(k_Scanner, "Match", m_Scanner_Match_1_Char, 1, t_Scanner_Match_1_Char);
    alg_class_method(k_Scanner, "Peek", m_Scanner_Peek_0, 0, NULL);
    alg_class_method(k_Scanner, "PeekNext", m_Scanner_PeekNext_0, 0, NULL);
    alg_class_method(k_Scanner, "AddToken", m_Scanner_AddToken_1_TokenType, 1, t_Scanner_AddToken_1_TokenType);
    alg_class_method(k_Scanner, "AddToken", m_Scanner_AddToken_2_TokenType, 2, t_Scanner_AddToken_2_TokenType);
    alg_class_method(k_Scanner, "IsAtEnd", m_Scanner_IsAtEnd_0, 0, NULL);
    alg_class_method(k_Scanner, "Advance", m_Scanner_Advance_0, 0, NULL);
    alg_class_method(k_Scanner, "IsAlpha", m_Scanner_IsAlpha_1_Char, 1, t_Scanner_IsAlpha_1_Char);
    alg_class_method(k_Scanner, "IsMark", m_Scanner_IsMark_1_Char, 1, t_Scanner_IsMark_1_Char);
    alg_class_method(k_Scanner, "IsAlphaNumeric", m_Scanner_IsAlphaNumeric_1_Char, 1, t_Scanner_IsAlphaNumeric_1_Char);
    alg_class_method(k_Scanner, "IsDigit", m_Scanner_IsDigit_1_Char, 1, t_Scanner_IsDigit_1_Char);
    v_DIGITS = alg_string("0123456789");
    v_UPPERCASE = alg_string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    v_LOWERCASE = alg_string("abcdefghijklmnopqrstuvwxyz");
    v_Keywords = alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map(), alg_string("and"), e_TokenType_TOKEN_AND), alg_string("as"), e_TokenType_TOKEN_AS), alg_string("begin"), e_TokenType_TOKEN_BEGIN), alg_string("break"), e_TokenType_TOKEN_BREAK), alg_string("case"), e_TokenType_TOKEN_CASE), alg_string("class"), e_TokenType_TOKEN_CLASS), alg_string("const"), e_TokenType_TOKEN_CONST), alg_string("constructor"), e_TokenType_TOKEN_CONSTRUCTOR), alg_string("do"), e_TokenType_TOKEN_DO), alg_string("else"), e_TokenType_TOKEN_ELSE), alg_string("end"), e_TokenType_TOKEN_END), alg_string("except"), e_TokenType_TOKEN_EXCEPT), alg_string("exit"), e_TokenType_TOKEN_EXIT), alg_string("false"), e_TokenType_TOKEN_FALSE), alg_string("for"), e_TokenType_TOKEN_FOR), alg_string("function"), e_TokenType_TOKEN_FUNCTION), alg_string("if"), e_TokenType_TOKEN_IF), alg_string("in"), e_TokenType_TOKEN_IN), alg_string("is"), e_TokenType_TOKEN_IS), alg_string("nil"), e_TokenType_TOKEN_NIL), alg_string("not"), e_TokenType_TOKEN_NOT), alg_string("object"), e_TokenType_TOKEN_OBJECT), alg_string("of"), e_TokenType_TOKEN_OF), alg_string("or"), e_TokenType_TOKEN_OR), alg_string("private"), e_TokenType_TOKEN_PRIVATE), alg_string("procedure"), e_TokenType_TOKEN_PROCEDURE), alg_string("public"), e_TokenType_TOKEN_PUBLIC), alg_string("raise"), e_TokenType_TOKEN_RAISE), alg_string("super"), e_TokenType_TOKEN_SUPER), alg_string("uses"), e_TokenType_TOKEN_USES), alg_string("then"), e_TokenType_TOKEN_THEN), alg_string("try"), e_TokenType_TOKEN_TRY), alg_string("this"), e_TokenType_TOKEN_THIS), alg_string("true"), e_TokenType_TOKEN_TRUE), alg_string("type"), e_TokenType_TOKEN_TYPE), alg_string("var"), e_TokenType_TOKEN_VAR), alg_string("while"), e_TokenType_TOKEN_WHILE);
    v_HadError = alg_bool(false);
    v_LastError = alg_nil();
}
