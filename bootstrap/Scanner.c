/* Generated from Algol-24.  Do not edit. */
#include "Scanner.h"
#include "SourceCode.h"
#include "Token.h"
#include "TokenType.h"

Value f_tolower(Value **cells, Value *args, int32_t count);
Value f_tointeger(Value **cells, Value *args, int32_t count);
Value f_exceedsinteger(Value **cells, Value *args, int32_t count);
Value v_digits;
bool d_digits;
Value v_uppercase;
bool d_uppercase;
Value v_lowercase;
bool d_lowercase;
Value fn_tolower;
Value fn_tointeger;
static Value or_0;
Value fn_exceedsinteger;
Value v_keywords;
bool d_keywords;
Value v_haderror;
bool d_haderror;
Value v_lasterror;
bool d_lasterror;
Value k_scanner;
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
static const char *t_scanner_init_1[] = { "Any" };
static const char *t_scanner_match_1_char[] = { "Char" };
static const char *t_scanner_addtoken_1_tokentype[] = { "TokenType" };
static const char *t_scanner_addtoken_2_tokentype[] = { "TokenType", "Any" };
static const char *t_scanner_isalpha_1_char[] = { "Char" };
static const char *t_scanner_ismark_1_char[] = { "Char" };
static const char *t_scanner_isalphanumeric_1_char[] = { "Char" };
static const char *t_scanner_isdigit_1_char[] = { "Char" };

Value f_tolower(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_text = alg_param(args[0], "String");
    (void)v_text;
    Value v_result = alg_widen(alg_string(""), "String");
    (void)v_result;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_text_length(v_text)))) {
            {
                {
                    Value v_c = alg_copy(v_text, v_i, alg_int(1));
                    (void)v_c;
                    Value v_at = alg_pos((alg_declared(d_uppercase, "UPPERCASE"), v_uppercase), v_c);
                    (void)v_at;
                    if (alg_truthy(alg_greater_equal(v_at, alg_int(0)))) {
                        (void)((v_result = alg_widen(alg_add(v_result, alg_copy((alg_declared(d_lowercase, "LOWERCASE"), v_lowercase), v_at, alg_int(1))), "String")));
                    } else {
                        (void)((v_result = alg_widen(alg_add(v_result, v_c), "String")));
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return v_result;
    return alg_nil();
}

Value f_tointeger(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_text = alg_param(args[0], "String");
    (void)v_text;
    Value v_result = alg_widen(alg_int(0), "Integer");
    (void)v_result;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_text_length(v_text)))) {
            {
                (void)((v_result = alg_widen(alg_add(alg_multiply(v_result, alg_int(10)), alg_pos((alg_declared(d_digits, "DIGITS"), v_digits), alg_copy(v_text, v_i, alg_int(1)))), "Integer")));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return v_result;
    return alg_nil();
}

Value f_exceedsinteger(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_text = alg_param(args[0], "String");
    (void)v_text;
    Value v_body = alg_nil();
    (void)v_body;
    (void)((v_body = alg_widen(v_text, "String")));
    while (alg_truthy((or_0 = alg_greater(alg_text_length(v_body), alg_int(1)), !alg_truthy(or_0) ? or_0 : alg_equal(alg_subscript_get(v_body, alg_int(0)), alg_char_value(48))))) {
        (void)((v_body = alg_widen(alg_copy(v_body, alg_int(1), alg_subtract(alg_text_length(v_body), alg_int(1))), "String")));
    }
    if (alg_truthy(alg_less(alg_text_length(v_body), alg_int(10)))) {
        return alg_bool(false);
    }
    if (alg_truthy(alg_greater(alg_text_length(v_body), alg_int(10)))) {
        return alg_bool(true);
    }
    Value v_limit = alg_string("2147483647");
    (void)v_limit;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_int(10)))) {
            {
                {
                    if (alg_truthy(alg_greater(alg_subscript_get(v_body, v_i), alg_subscript_get(v_limit, v_i)))) {
                        return alg_bool(true);
                    }
                    if (alg_truthy(alg_less(alg_subscript_get(v_body, v_i), alg_subscript_get(v_limit, v_i)))) {
                        return alg_bool(false);
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value i_scanner(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Source", alg_nil());
    alg_set_property(v_this, "Tokens", alg_nil());
    alg_set_property(v_this, "Current", alg_nil());
    alg_set_property(v_this, "Start", alg_nil());
    alg_set_property(v_this, "Line", alg_nil());
    alg_set_property(v_this, "LineStart", alg_nil());
    return alg_nil();
}

static Value m_scanner_init_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_source = args[0];
    (void)v_source;
    (void)(alg_set_property(v_this, "Source", alg_widen(alg_str(v_source), "String")));
    (void)(alg_set_property(v_this, "Current", alg_widen(alg_int(0), "Integer")));
    (void)(alg_set_property(v_this, "Start", alg_widen(alg_int(0), "Integer")));
    (void)(alg_set_property(v_this, "Line", alg_widen(alg_int(1), "Integer")));
    (void)(alg_set_property(v_this, "LineStart", alg_widen(alg_int(0), "Integer")));
    (void)(alg_set_property(v_this, "Tokens", alg_widen(alg_list(), "List")));
    return alg_nil();
}

static Value m_scanner_scantokens_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    while (alg_truthy(alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        {
            (void)(alg_set_property(v_this, "Start", alg_widen(alg_property(v_this, "Current"), "Integer")));
            (void)(alg_invoke(v_this, "ScanToken", NULL, 0));
        }
    }
    (void)(alg_invoke(alg_singleton(k_sourcecode), "Add", (Value[]){alg_property(v_this, "Line"), alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "LineStart"), alg_subtract(alg_text_length(alg_property(v_this, "Source")), alg_property(v_this, "LineStart")))}, 2));
    (void)(alg_invoke(alg_property(v_this, "Tokens"), "Add", (Value[]){alg_new(k_token, (Value[]){e_tokentype_eof, alg_string(""), alg_nil(), alg_property(v_this, "Line")}, 4)}, 1));
    return alg_property(v_this, "Tokens");
    return alg_nil();
}

static Value m_scanner_scantoken_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_c = alg_nil();
    (void)v_c;
    (void)((v_c = alg_widen(alg_invoke(v_this, "Advance", NULL, 0), "Char")));
    if (alg_truthy(alg_equal(v_c, alg_char_value(40)))) {
        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVleftVparen}, 1));
    } else {
        if (alg_truthy(alg_equal(v_c, alg_char_value(41)))) {
            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVrightVparen}, 1));
        } else {
            if (alg_truthy(alg_equal(v_c, alg_char_value(91)))) {
                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVleftVbracket}, 1));
            } else {
                if (alg_truthy(alg_equal(v_c, alg_char_value(93)))) {
                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVrightVbracket}, 1));
                } else {
                    if (alg_truthy(alg_equal(v_c, alg_char_value(44)))) {
                        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVcomma}, 1));
                    } else {
                        if (alg_truthy(alg_equal(v_c, alg_char_value(46)))) {
                            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVdot}, 1));
                        } else {
                            if (alg_truthy(alg_equal(v_c, alg_char_value(45)))) {
                                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVminus}, 1));
                            } else {
                                if (alg_truthy(alg_equal(v_c, alg_char_value(43)))) {
                                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVplus}, 1));
                                } else {
                                    if (alg_truthy(alg_equal(v_c, alg_char_value(59)))) {
                                        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVsemicolon}, 1));
                                    } else {
                                        if (alg_truthy(alg_equal(v_c, alg_char_value(42)))) {
                                            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVstar}, 1));
                                        } else {
                                            if (alg_truthy(alg_equal(v_c, alg_char_value(61)))) {
                                                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVequal}, 1));
                                            } else {
                                                if (alg_truthy(alg_equal(v_c, alg_char_value(58)))) {
                                                    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(61)}, 1))) {
                                                        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVassign}, 1));
                                                    } else {
                                                        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVcolon}, 1));
                                                    }
                                                } else {
                                                    if (alg_truthy(alg_equal(v_c, alg_char_value(62)))) {
                                                        if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(61)}, 1))) {
                                                            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVgreaterVequal}, 1));
                                                        } else {
                                                            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVgreater}, 1));
                                                        }
                                                    } else {
                                                        if (alg_truthy(alg_equal(v_c, alg_char_value(60)))) {
                                                            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(62)}, 1))) {
                                                                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVnotVequal}, 1));
                                                            } else {
                                                                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(61)}, 1))) {
                                                                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVlessVequal}, 1));
                                                                } else {
                                                                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVless}, 1));
                                                                }
                                                            }
                                                        } else {
                                                            if (alg_truthy(alg_equal(v_c, alg_char_value(47)))) {
                                                                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(47)}, 1))) {
                                                                    while (alg_truthy((or_1 = alg_not_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(10)), !alg_truthy(or_1) ? or_1 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
                                                                        (void)(alg_invoke(v_this, "Advance", NULL, 0));
                                                                    }
                                                                } else {
                                                                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVslash}, 1));
                                                                }
                                                            } else {
                                                                if (alg_truthy((or_3 = (or_2 = alg_equal(v_c, alg_char_value(9)), alg_truthy(or_2) ? or_2 : alg_equal(v_c, alg_char_value(13))), alg_truthy(or_3) ? or_3 : alg_equal(v_c, alg_char_value(32))))) {
                                                                    return alg_nil();
                                                                } else {
                                                                    if (alg_truthy(alg_equal(v_c, alg_char_value(10)))) {
                                                                        {
                                                                            (void)(alg_invoke(alg_singleton(k_sourcecode), "Add", (Value[]){alg_property(v_this, "Line"), alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "LineStart"), alg_subtract(alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "LineStart")), alg_int(1)))}, 2));
                                                                            (void)(alg_set_property(v_this, "Line", alg_widen(alg_add(alg_property(v_this, "Line"), alg_int(1)), "Integer")));
                                                                            (void)(alg_set_property(v_this, "LineStart", alg_widen(alg_property(v_this, "Current"), "Integer")));
                                                                            return alg_nil();
                                                                        }
                                                                    } else {
                                                                        if (alg_truthy(alg_equal(v_c, alg_char_value(39)))) {
                                                                            (void)(alg_invoke(v_this, "ScanString", NULL, 0));
                                                                        } else {
                                                                            if (alg_truthy(alg_equal(v_c, alg_char_value(35)))) {
                                                                                (void)(alg_invoke(v_this, "ScanChar", NULL, 0));
                                                                            } else {
                                                                                if (alg_truthy(alg_invoke(v_this, "IsAlpha", (Value[]){v_c}, 1))) {
                                                                                    (void)(alg_invoke(v_this, "ScanIdentifier", NULL, 0));
                                                                                } else {
                                                                                    if (alg_truthy(alg_invoke(v_this, "IsDigit", (Value[]){v_c}, 1))) {
                                                                                        (void)(alg_invoke(v_this, "ScanNumber", NULL, 0));
                                                                                    } else {
                                                                                        {
                                                                                            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
                                                                                            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_add(alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: Unexpected character: ")), v_c))));
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

static Value m_scanner_scanidentifier_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_text = alg_nil();
    (void)v_text;
    Value v_typeoftoken = alg_nil();
    (void)v_typeoftoken;
    while (alg_truthy(alg_invoke(v_this, "IsAlphaNumeric", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1))) {
        (void)(alg_invoke(v_this, "Advance", NULL, 0));
    }
    (void)((v_text = alg_widen(alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "Start"), alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start"))), "String")));
    (void)((v_typeoftoken = alg_widen(e_tokentype_tokenVidentifier, "TokenType")));
    Value v_lowered = f_tolower(NULL, (Value[]){v_text}, 1);
    (void)v_lowered;
    if (alg_truthy(alg_invoke((alg_declared(d_keywords, "Keywords"), v_keywords), "Contains", (Value[]){v_lowered}, 1))) {
        {
            (void)((v_typeoftoken = alg_widen(alg_cast(alg_invoke((alg_declared(d_keywords, "Keywords"), v_keywords), "Get", (Value[]){v_lowered}, 1), "TokenType"), "TokenType")));
        }
    }
    (void)(alg_invoke(v_this, "AddToken", (Value[]){v_typeoftoken}, 1));
    return alg_nil();
}

static Value m_scanner_scannumber_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_isinteger = alg_nil();
    (void)v_isinteger;
    (void)((v_isinteger = alg_widen(alg_bool(true), "Boolean")));
    while (alg_truthy(alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1))) {
        (void)(alg_invoke(v_this, "Advance", NULL, 0));
    }
    if (alg_truthy((or_4 = alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(46)), !alg_truthy(or_4) ? or_4 : alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "PeekNext", NULL, 0)}, 1)))) {
        {
            (void)((v_isinteger = alg_widen(alg_bool(false), "Boolean")));
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
        }
    }
    while (alg_truthy(alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1))) {
        (void)(alg_invoke(v_this, "Advance", NULL, 0));
    }
    Value v_text = alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "Start"), alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start")));
    (void)v_text;
    if (alg_truthy(v_isinteger)) {
        {
            if (alg_truthy(f_exceedsinteger(NULL, (Value[]){v_text}, 1))) {
                {
                    (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
                    (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_add(alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: Integer literal out of range: ")), v_text))));
                    return alg_nil();
                }
            }
            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVinteger, f_tointeger(NULL, (Value[]){v_text}, 1)}, 2));
        }
    } else {
        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVnumber, alg_val(v_text)}, 2));
    }
    return alg_nil();
}

static Value m_scanner_scanstring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_value = alg_nil();
    (void)v_value;
    Value v_opened = alg_nil();
    (void)v_opened;
    (void)((v_value = alg_widen(alg_string(""), "String")));
    (void)((v_opened = alg_widen(alg_property(v_this, "Line"), "Integer")));
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
                (void)(alg_set_property(v_this, "Line", alg_widen(alg_add(alg_property(v_this, "Line"), alg_int(1)), "Integer")));
            }
            (void)((v_value = alg_widen(alg_add(v_value, alg_invoke(v_this, "Advance", NULL, 0)), "String")));
        }
    }
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        {
            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_add(alg_add(alg_string("[line "), v_opened), alg_string("] Error: Unterminated string.")))));
            return alg_nil();
        }
    }
    (void)(alg_invoke(v_this, "Advance", NULL, 0));
    if (alg_truthy(alg_equal(alg_text_length(v_value), alg_int(1)))) {
        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVchar, alg_subscript_get(v_value, alg_int(0))}, 2));
    } else {
        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVstring, v_value}, 2));
    }
    return alg_nil();
}

static Value m_scanner_scanchar_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_not(alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1)))) {
        {
            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_add(alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: Invalid character: ")), alg_invoke(v_this, "Peek", NULL, 0)))));
            return alg_nil();
        }
    }
    while (alg_truthy(alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1))) {
        (void)(alg_invoke(v_this, "Advance", NULL, 0));
    }
    Value v_code = f_tointeger(NULL, (Value[]){alg_copy(alg_property(v_this, "Source"), alg_add(alg_property(v_this, "Start"), alg_int(1)), alg_subtract(alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start")), alg_int(1)))}, 1);
    (void)v_code;
    if (alg_truthy(alg_equal(v_code, alg_int(0)))) {
        {
            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: '#0' is not a Char.")))));
            return alg_nil();
        }
    }
    if (alg_truthy((or_6 = alg_greater(v_code, alg_int(1114111)), alg_truthy(or_6) ? or_6 : ((or_5 = alg_greater_equal(v_code, alg_int(55296)), !alg_truthy(or_5) ? or_5 : alg_less_equal(v_code, alg_int(57343))))))) {
        {
            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_add(alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: Char is limited to 0..10FFFF, excluding D800..DFFF: #")), v_code))));
            return alg_nil();
        }
    }
    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVchar, alg_char(v_code)}, 2));
    return alg_nil();
}

static Value m_scanner_match_1_char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_expected = alg_widen(args[0], "Char");
    (void)v_expected;
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        return alg_bool(false);
    }
    if (alg_truthy(alg_not_equal(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Current")), v_expected))) {
        return alg_bool(false);
    }
    (void)(alg_set_property(v_this, "Current", alg_widen(alg_add(alg_property(v_this, "Current"), alg_int(1)), "Integer")));
    return alg_bool(true);
    return alg_nil();
}

static Value m_scanner_peek_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        return alg_char(alg_int(0));
    }
    return alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Current"));
    return alg_nil();
}

static Value m_scanner_peeknext_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_greater_equal(alg_add(alg_property(v_this, "Current"), alg_int(1)), alg_text_length(alg_property(v_this, "Source"))))) {
        return alg_char(alg_int(0));
    }
    return alg_subscript_get(alg_property(v_this, "Source"), alg_add(alg_property(v_this, "Current"), alg_int(1)));
    return alg_nil();
}

static Value m_scanner_addtoken_1_tokentype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_typeoftoken = alg_widen(args[0], "TokenType");
    (void)v_typeoftoken;
    (void)(alg_invoke(v_this, "AddToken", (Value[]){v_typeoftoken, alg_nil()}, 2));
    return alg_nil();
}

static Value m_scanner_addtoken_2_tokentype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_typeoftoken = alg_widen(args[0], "TokenType");
    (void)v_typeoftoken;
    Value v_literal = args[1];
    (void)v_literal;
    Value v_text = alg_nil();
    (void)v_text;
    Value v_thetoken = alg_nil();
    (void)v_thetoken;
    (void)((v_text = alg_widen(alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "Start"), alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start"))), "String")));
    (void)((v_thetoken = alg_widen(alg_new(k_token, (Value[]){v_typeoftoken, v_text, v_literal, alg_property(v_this, "Line")}, 4), "Token")));
    (void)(alg_set_property(v_thetoken, "Offset", alg_widen(alg_subtract(alg_property(v_this, "Start"), alg_property(v_this, "LineStart")), "Integer")));
    (void)(alg_invoke(alg_property(v_this, "Tokens"), "Add", (Value[]){v_thetoken}, 1));
    return alg_nil();
}

static Value m_scanner_isatend_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_greater_equal(alg_property(v_this, "Current"), alg_text_length(alg_property(v_this, "Source")));
    return alg_nil();
}

static Value m_scanner_advance_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_returnvalue = alg_nil();
    (void)v_returnvalue;
    (void)((v_returnvalue = alg_widen(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Current")), "Char")));
    (void)(alg_set_property(v_this, "Current", alg_widen(alg_add(alg_property(v_this, "Current"), alg_int(1)), "Integer")));
    return v_returnvalue;
    return alg_nil();
}

static Value m_scanner_isalpha_1_char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_c = alg_widen(args[0], "Char");
    (void)v_c;
    if (alg_truthy((or_7 = alg_greater_equal(v_c, alg_char_value(97)), !alg_truthy(or_7) ? or_7 : alg_less_equal(v_c, alg_char_value(122))))) {
        return alg_bool(true);
    }
    if (alg_truthy((or_8 = alg_greater_equal(v_c, alg_char_value(65)), !alg_truthy(or_8) ? or_8 : alg_less_equal(v_c, alg_char_value(90))))) {
        return alg_bool(true);
    }
    if (alg_truthy(alg_equal(v_c, alg_char_value(95)))) {
        return alg_bool(true);
    }
    return alg_greater(alg_ord(v_c), alg_int(127));
    return alg_nil();
}

static Value m_scanner_ismark_1_char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_c = alg_widen(args[0], "Char");
    (void)v_c;
    return (or_9 = (alg_equal(v_c, alg_char_value(63))), alg_truthy(or_9) ? or_9 : (alg_equal(v_c, alg_char_value(33))));
    return alg_nil();
}

static Value m_scanner_isalphanumeric_1_char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_c = alg_widen(args[0], "Char");
    (void)v_c;
    return (or_11 = (or_10 = alg_invoke(v_this, "IsAlpha", (Value[]){v_c}, 1), alg_truthy(or_10) ? or_10 : alg_invoke(v_this, "IsDigit", (Value[]){v_c}, 1)), alg_truthy(or_11) ? or_11 : alg_invoke(v_this, "IsMark", (Value[]){v_c}, 1));
    return alg_nil();
}

static Value m_scanner_isdigit_1_char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_c = alg_widen(args[0], "Char");
    (void)v_c;
    return (or_12 = alg_greater_equal(v_c, alg_char_value(48)), !alg_truthy(or_12) ? or_12 : alg_less_equal(v_c, alg_char_value(57)));
    return alg_nil();
}

void init_Scanner(void) {
    k_scanner = alg_class("Scanner", alg_nil());
    fn_tolower = alg_closure("ToLower", f_tolower, NULL, 0, 1);
    fn_tointeger = alg_closure("ToInteger", f_tointeger, NULL, 0, 1);
    fn_exceedsinteger = alg_closure("ExceedsInteger", f_exceedsinteger, NULL, 0, 1);
    alg_class_field(k_scanner, "Source");
    alg_class_field(k_scanner, "Tokens");
    alg_class_field(k_scanner, "Current");
    alg_class_field(k_scanner, "Start");
    alg_class_field(k_scanner, "Line");
    alg_class_field(k_scanner, "LineStart");
    alg_class_initializer(k_scanner, i_scanner);
    alg_class_method(k_scanner, "Init", m_scanner_init_1, 1, t_scanner_init_1);
    alg_class_method(k_scanner, "ScanTokens", m_scanner_scantokens_0, 0, NULL);
    alg_class_method(k_scanner, "ScanToken", m_scanner_scantoken_0, 0, NULL);
    alg_class_method(k_scanner, "ScanIdentifier", m_scanner_scanidentifier_0, 0, NULL);
    alg_class_method(k_scanner, "ScanNumber", m_scanner_scannumber_0, 0, NULL);
    alg_class_method(k_scanner, "ScanString", m_scanner_scanstring_0, 0, NULL);
    alg_class_method(k_scanner, "ScanChar", m_scanner_scanchar_0, 0, NULL);
    alg_class_method(k_scanner, "Match", m_scanner_match_1_char, 1, t_scanner_match_1_char);
    alg_class_method(k_scanner, "Peek", m_scanner_peek_0, 0, NULL);
    alg_class_method(k_scanner, "PeekNext", m_scanner_peeknext_0, 0, NULL);
    alg_class_method(k_scanner, "AddToken", m_scanner_addtoken_1_tokentype, 1, t_scanner_addtoken_1_tokentype);
    alg_class_method(k_scanner, "AddToken", m_scanner_addtoken_2_tokentype, 2, t_scanner_addtoken_2_tokentype);
    alg_class_method(k_scanner, "IsAtEnd", m_scanner_isatend_0, 0, NULL);
    alg_class_method(k_scanner, "Advance", m_scanner_advance_0, 0, NULL);
    alg_class_method(k_scanner, "IsAlpha", m_scanner_isalpha_1_char, 1, t_scanner_isalpha_1_char);
    alg_class_method(k_scanner, "IsMark", m_scanner_ismark_1_char, 1, t_scanner_ismark_1_char);
    alg_class_method(k_scanner, "IsAlphaNumeric", m_scanner_isalphanumeric_1_char, 1, t_scanner_isalphanumeric_1_char);
    alg_class_method(k_scanner, "IsDigit", m_scanner_isdigit_1_char, 1, t_scanner_isdigit_1_char);
    init_SourceCode();
    v_digits = alg_string("0123456789");
    d_digits = true;
    v_uppercase = alg_string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    d_uppercase = true;
    v_lowercase = alg_string("abcdefghijklmnopqrstuvwxyz");
    d_lowercase = true;
    v_keywords = alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map(), alg_string("and"), e_tokentype_tokenVand), alg_string("as"), e_tokentype_tokenVas), alg_string("begin"), e_tokentype_tokenVbegin), alg_string("break"), e_tokentype_tokenVbreak), alg_string("case"), e_tokentype_tokenVcase), alg_string("class"), e_tokentype_tokenVclass), alg_string("const"), e_tokentype_tokenVconst), alg_string("constructor"), e_tokentype_tokenVconstructor), alg_string("do"), e_tokentype_tokenVdo), alg_string("else"), e_tokentype_tokenVelse), alg_string("end"), e_tokentype_tokenVend), alg_string("except"), e_tokentype_tokenVexcept), alg_string("exit"), e_tokentype_tokenVexit), alg_string("false"), e_tokentype_tokenVfalse), alg_string("for"), e_tokentype_tokenVfor), alg_string("function"), e_tokentype_tokenVfunction), alg_string("if"), e_tokentype_tokenVif), alg_string("in"), e_tokentype_tokenVin), alg_string("is"), e_tokentype_tokenVis), alg_string("nil"), e_tokentype_tokenVnil), alg_string("not"), e_tokentype_tokenVnot), alg_string("object"), e_tokentype_tokenVobject), alg_string("of"), e_tokentype_tokenVof), alg_string("or"), e_tokentype_tokenVor), alg_string("private"), e_tokentype_tokenVprivate), alg_string("procedure"), e_tokentype_tokenVprocedure), alg_string("public"), e_tokentype_tokenVpublic), alg_string("raise"), e_tokentype_tokenVraise), alg_string("super"), e_tokentype_tokenVsuper), alg_string("uses"), e_tokentype_tokenVuses), alg_string("then"), e_tokentype_tokenVthen), alg_string("try"), e_tokentype_tokenVtry), alg_string("this"), e_tokentype_tokenVthis), alg_string("true"), e_tokentype_tokenVtrue), alg_string("type"), e_tokentype_tokenVtype), alg_string("var"), e_tokentype_tokenVvar), alg_string("while"), e_tokentype_tokenVwhile);
    d_keywords = true;
    v_haderror = alg_bool(false);
    d_haderror = true;
    v_lasterror = alg_nil();
    d_lasterror = true;
}
