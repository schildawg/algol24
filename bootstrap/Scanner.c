/* Generated from Algol-24.  Do not edit. */
#include "Scanner.h"
#include "SourceCode.h"
#include "Token.h"
#include "TokenType.h"

Value f_tointeger(Value **cells, Value *args, int32_t count);
Value f_toradix(Value **cells, Value *args, int32_t count);
Value v_digits;
bool d_digits;
Value v_hexdigits;
bool d_hexdigits;
Value v_bindigits;
bool d_bindigits;
Value fn_tointeger;
static const char *t_f_tointeger[] = { "Text : String" };
Value fn_toradix;
static const char *t_f_toradix[] = { "Text : String", "Alphabet : String" };
Value v_keywords;
bool d_keywords;
Value v_haderror;
bool d_haderror;
Value v_lasterror;
bool d_lasterror;
Value k_scanner;
static Value or_0;
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
static Value or_13;
static Value or_14;
static Value or_15;
static Value or_16;
static Value or_17;
static Value or_18;
static Value or_19;
static Value or_20;
static Value or_21;
static const char *t_scanner_init_1[] = { "Source : Any" };
static const char *t_scanner_init_2_string[] = { "Source : Any", "FileName : String" };
static const char *t_scanner_scanradix_1_string[] = { "Alphabet : String" };
static const char *t_scanner_inalphabet_2_string_char[] = { "Alphabet : String", "C : Char" };
static const char *t_scanner_ishexdigit_1_char[] = { "C : Char" };
static const char *t_scanner_match_1_char[] = { "Expected : Char" };
static const char *t_scanner_addtoken_1_tokentype[] = { "TypeOfToken : TokenType" };
static const char *t_scanner_addtoken_2_tokentype[] = { "TypeOfToken : TokenType", "Literal : Any" };
static const char *t_scanner_isalpha_1_char[] = { "C : Char" };
static const char *t_scanner_ismark_1_char[] = { "C : Char" };
static const char *t_scanner_isalphanumeric_1_char[] = { "C : Char" };
static const char *t_scanner_isdigit_1_char[] = { "C : Char" };

Value f_tointeger(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_text = alg_param(args[0], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    Value v_result = alg_int(0);
    (void)v_result;
    alg_root(&v_result, 1);
    {
        int32_t rt_7 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_text))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)((v_result = alg_add(alg_multiply(v_result, alg_int(10)), alg_pos((alg_declared(d_digits, "DIGITS"), v_digits), alg_copy(v_text, v_i, alg_int(1))))));
        }
        alg_root_top = rt_7;
    }
    Value ret_0 = v_result;
    alg_root_top = rt_base;
    return ret_0;
    Value ret_1 = alg_nil();
    alg_root_top = rt_base;
    return ret_1;
}

Value f_toradix(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_text = alg_param(args[0], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    Value v_alphabet = alg_param(args[1], "String");
    (void)v_alphabet;
    alg_root(&v_alphabet, 1);
    Value v_result = alg_int(0);
    (void)v_result;
    alg_root(&v_result, 1);
    {
        int32_t rt_8 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_text))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)((v_result = alg_add(alg_multiply(v_result, alg_text_length(v_alphabet)), alg_pos(v_alphabet, alg_to_lower(alg_copy(v_text, v_i, alg_int(1)))))));
        }
        alg_root_top = rt_8;
    }
    Value ret_2 = v_result;
    alg_root_top = rt_base;
    return ret_2;
    Value ret_3 = alg_nil();
    alg_root_top = rt_base;
    return ret_3;
}

static Value i_scanner(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Source", alg_nil());
    alg_set_property(v_this, "Tokens", alg_nil());
    alg_set_property(v_this, "Current", alg_nil());
    alg_set_property(v_this, "Start", alg_nil());
    alg_set_property(v_this, "Line", alg_nil());
    alg_set_property(v_this, "LineStart", alg_nil());
    alg_set_property(v_this, "FileName", alg_widen(alg_string(""), "String"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_scanner_init_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_source = args[0];
    (void)v_source;
    alg_root(&v_source, 1);
    (void)(alg_set_property(v_this, "Source", alg_str(v_source)));
    (void)(alg_set_property(v_this, "Current", alg_int(0)));
    (void)(alg_set_property(v_this, "Start", alg_int(0)));
    (void)(alg_set_property(v_this, "Line", alg_int(1)));
    (void)(alg_set_property(v_this, "LineStart", alg_int(0)));
    (void)(alg_set_property(v_this, "Tokens", alg_list()));
    Value ret_4 = alg_nil();
    alg_root_top = rt_base;
    return ret_4;
}

static Value m_scanner_init_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_source = args[0];
    (void)v_source;
    alg_root(&v_source, 1);
    Value v_filename = alg_widen(args[1], "String");
    (void)v_filename;
    alg_root(&v_filename, 1);
    (void)(alg_set_property(v_this, "Source", alg_str(v_source)));
    (void)(alg_set_property(v_this, "Current", alg_int(0)));
    (void)(alg_set_property(v_this, "Start", alg_int(0)));
    (void)(alg_set_property(v_this, "Line", alg_int(1)));
    (void)(alg_set_property(v_this, "LineStart", alg_int(0)));
    (void)(alg_set_property(v_this, "FileName", v_filename));
    (void)(alg_set_property(v_this, "Tokens", alg_list()));
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

static Value m_scanner_scantokens_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    while (alg_truthy(alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        {
            (void)(alg_set_property(v_this, "Start", alg_property(v_this, "Current")));
            (void)(alg_invoke(v_this, "ScanToken", NULL, 0));
        }
    }
    (void)(alg_invoke(alg_singleton(k_sourcecode), "Add", (Value[]){alg_property(v_this, "FileName"), alg_property(v_this, "Line"), alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "LineStart"), alg_subtract(alg_text_length(alg_property(v_this, "Source")), alg_property(v_this, "LineStart")))}, 3));
    Value v_theend = alg_new(k_token, (Value[]){e_tokentype_eof, alg_string(""), alg_nil(), alg_property(v_this, "Line")}, 4);
    (void)v_theend;
    alg_root(&v_theend, 1);
    (void)(alg_set_property(v_theend, "File", alg_property(v_this, "FileName")));
    (void)(alg_invoke(alg_property(v_this, "Tokens"), "Add", (Value[]){v_theend}, 1));
    Value ret_6 = alg_property(v_this, "Tokens");
    alg_root_top = rt_base;
    return ret_6;
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
}

static Value m_scanner_scantoken_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_c = alg_nil();
    (void)v_c;
    alg_root(&v_c, 1);
    (void)((v_c = alg_invoke(v_this, "Advance", NULL, 0)));
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
                            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(46)}, 1))) {
                                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVdotVdot}, 1));
                            } else {
                                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVdot}, 1));
                            }
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
                                                    if (alg_truthy(alg_equal(v_c, alg_char_value(38)))) {
                                                        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVampersand}, 1));
                                                    } else {
                                                        if (alg_truthy(alg_equal(v_c, alg_char_value(124)))) {
                                                            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVpipe}, 1));
                                                        } else {
                                                            if (alg_truthy(alg_equal(v_c, alg_char_value(94)))) {
                                                                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVcaret}, 1));
                                                            } else {
                                                                if (alg_truthy(alg_equal(v_c, alg_char_value(126)))) {
                                                                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVtilde}, 1));
                                                                } else {
                                                                    if (alg_truthy(alg_equal(v_c, alg_char_value(62)))) {
                                                                        if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(61)}, 1))) {
                                                                            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVgreaterVequal}, 1));
                                                                        } else {
                                                                            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(62)}, 1))) {
                                                                                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVshiftVright}, 1));
                                                                            } else {
                                                                                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVgreater}, 1));
                                                                            }
                                                                        }
                                                                    } else {
                                                                        if (alg_truthy(alg_equal(v_c, alg_char_value(60)))) {
                                                                            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(62)}, 1))) {
                                                                                (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVnotVequal}, 1));
                                                                            } else {
                                                                                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(61)}, 1))) {
                                                                                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVlessVequal}, 1));
                                                                                } else {
                                                                                    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(60)}, 1))) {
                                                                                        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVshiftVleft}, 1));
                                                                                    } else {
                                                                                        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVless}, 1));
                                                                                    }
                                                                                }
                                                                            }
                                                                        } else {
                                                                            if (alg_truthy(alg_equal(v_c, alg_char_value(47)))) {
                                                                                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){alg_char_value(47)}, 1))) {
                                                                                    while (alg_truthy((or_0 = alg_not_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(10)), !alg_truthy(or_0) ? or_0 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
                                                                                        (void)(alg_invoke(v_this, "Advance", NULL, 0));
                                                                                    }
                                                                                } else {
                                                                                    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVslash}, 1));
                                                                                }
                                                                            } else {
                                                                                if (alg_truthy((or_2 = (or_1 = alg_equal(v_c, alg_char_value(9)), alg_truthy(or_1) ? or_1 : alg_equal(v_c, alg_char_value(13))), alg_truthy(or_2) ? or_2 : alg_equal(v_c, alg_char_value(32))))) {
                                                                                    Value ret_8 = alg_nil();
                                                                                    alg_root_top = rt_base;
                                                                                    return ret_8;
                                                                                } else {
                                                                                    if (alg_truthy(alg_equal(v_c, alg_char_value(10)))) {
                                                                                        {
                                                                                            (void)(alg_invoke(alg_singleton(k_sourcecode), "Add", (Value[]){alg_property(v_this, "FileName"), alg_property(v_this, "Line"), alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "LineStart"), alg_subtract(alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "LineStart")), alg_int(1)))}, 3));
                                                                                            (void)(alg_set_property(v_this, "Line", alg_add(alg_property(v_this, "Line"), alg_int(1))));
                                                                                            (void)(alg_set_property(v_this, "LineStart", alg_property(v_this, "Current")));
                                                                                            Value ret_9 = alg_nil();
                                                                                            alg_root_top = rt_base;
                                                                                            return ret_9;
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
                }
            }
        }
    }
    Value ret_10 = alg_nil();
    alg_root_top = rt_base;
    return ret_10;
}

static Value m_scanner_scanidentifier_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    Value v_typeoftoken = alg_nil();
    (void)v_typeoftoken;
    alg_root(&v_typeoftoken, 1);
    while (alg_truthy(alg_invoke(v_this, "IsAlphaNumeric", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1))) {
        (void)(alg_invoke(v_this, "Advance", NULL, 0));
    }
    (void)((v_text = alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "Start"), alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start")))));
    (void)((v_typeoftoken = e_tokentype_tokenVidentifier));
    Value v_lowered = alg_to_lower(v_text);
    (void)v_lowered;
    alg_root(&v_lowered, 1);
    if (alg_truthy(alg_invoke((alg_declared(d_keywords, "Keywords"), v_keywords), "Contains", (Value[]){v_lowered}, 1))) {
        {
            (void)((v_typeoftoken = alg_cast(alg_invoke((alg_declared(d_keywords, "Keywords"), v_keywords), "Get", (Value[]){v_lowered}, 1), "TokenType")));
        }
    }
    (void)(alg_invoke(v_this, "AddToken", (Value[]){v_typeoftoken}, 1));
    Value ret_11 = alg_nil();
    alg_root_top = rt_base;
    return ret_11;
}

static Value m_scanner_scannumber_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_isinteger = alg_nil();
    (void)v_isinteger;
    alg_root(&v_isinteger, 1);
    Value v_digits = alg_nil();
    (void)v_digits;
    alg_root(&v_digits, 1);
    if (alg_truthy((or_4 = alg_equal(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Start")), alg_char_value(48)), !alg_truthy(or_4) ? or_4 : ((or_3 = alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(120)), alg_truthy(or_3) ? or_3 : alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(88))))))) {
        if (alg_truthy(alg_invoke(v_this, "IsHexDigit", (Value[]){alg_invoke(v_this, "PeekNext", NULL, 0)}, 1))) {
            {
                (void)(alg_invoke(v_this, "Advance", NULL, 0));
                (void)(alg_invoke(v_this, "ScanRadix", (Value[]){(alg_declared(d_hexdigits, "HEXDIGITS"), v_hexdigits)}, 1));
                Value ret_12 = alg_nil();
                alg_root_top = rt_base;
                return ret_12;
            }
        }
    }
    if (alg_truthy((or_6 = alg_equal(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Start")), alg_char_value(48)), !alg_truthy(or_6) ? or_6 : ((or_5 = alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(98)), alg_truthy(or_5) ? or_5 : alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(66))))))) {
        if (alg_truthy((or_7 = alg_equal(alg_invoke(v_this, "PeekNext", NULL, 0), alg_char_value(48)), alg_truthy(or_7) ? or_7 : alg_equal(alg_invoke(v_this, "PeekNext", NULL, 0), alg_char_value(49))))) {
            {
                (void)(alg_invoke(v_this, "Advance", NULL, 0));
                (void)(alg_invoke(v_this, "ScanRadix", (Value[]){(alg_declared(d_bindigits, "BINDIGITS"), v_bindigits)}, 1));
                Value ret_13 = alg_nil();
                alg_root_top = rt_base;
                return ret_13;
            }
        }
    }
    (void)((v_isinteger = alg_bool(true)));
    (void)((v_digits = alg_str(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Start")))));
    (void)((v_digits = alg_add(v_digits, alg_invoke(v_this, "ScanDigits", NULL, 0))));
    if (alg_truthy((or_8 = alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(46)), !alg_truthy(or_8) ? or_8 : alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "PeekNext", NULL, 0)}, 1)))) {
        {
            (void)((v_isinteger = alg_bool(false)));
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)((v_digits = alg_add(alg_add(v_digits, alg_char_value(46)), alg_invoke(v_this, "ScanDigits", NULL, 0))));
        }
    }
    if (alg_truthy((or_9 = alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(101)), alg_truthy(or_9) ? or_9 : alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(69))))) {
        if (alg_truthy(alg_invoke(v_this, "IsExponent", NULL, 0))) {
            {
                (void)((v_isinteger = alg_bool(false)));
                (void)(alg_invoke(v_this, "Advance", NULL, 0));
                (void)((v_digits = alg_add(v_digits, alg_char_value(101))));
                if (alg_truthy((or_10 = alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(43)), alg_truthy(or_10) ? or_10 : alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(45))))) {
                    {
                        (void)((v_digits = alg_add(v_digits, alg_str(alg_invoke(v_this, "Peek", NULL, 0)))));
                        (void)(alg_invoke(v_this, "Advance", NULL, 0));
                    }
                }
                (void)((v_digits = alg_add(v_digits, alg_invoke(v_this, "ScanDigits", NULL, 0))));
            }
        }
    }
    if (alg_truthy(v_isinteger)) {
        {
            (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVinteger, f_tointeger(NULL, (Value[]){v_digits}, 1)}, 2));
        }
    } else {
        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVnumber, alg_val(v_digits)}, 2));
    }
    Value ret_14 = alg_nil();
    alg_root_top = rt_base;
    return ret_14;
}

static Value m_scanner_scandigits_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_digits = alg_nil();
    (void)v_digits;
    alg_root(&v_digits, 1);
    (void)((v_digits = alg_string("")));
    while (alg_truthy(alg_bool(true))) {
        {
            if (alg_truthy(alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1))) {
                {
                    (void)((v_digits = alg_add(v_digits, alg_str(alg_invoke(v_this, "Peek", NULL, 0)))));
                    (void)(alg_invoke(v_this, "Advance", NULL, 0));
                }
            } else {
                if (alg_truthy((or_11 = alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(95)), !alg_truthy(or_11) ? or_11 : alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "PeekNext", NULL, 0)}, 1)))) {
                    (void)(alg_invoke(v_this, "Advance", NULL, 0));
                } else {
                    Value ret_15 = v_digits;
                    alg_root_top = rt_base;
                    return ret_15;
                }
            }
        }
    }
    Value ret_16 = v_digits;
    alg_root_top = rt_base;
    return ret_16;
    Value ret_17 = alg_nil();
    alg_root_top = rt_base;
    return ret_17;
}

static Value m_scanner_scanradix_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_alphabet = alg_widen(args[0], "String");
    (void)v_alphabet;
    alg_root(&v_alphabet, 1);
    Value v_digits = alg_nil();
    (void)v_digits;
    alg_root(&v_digits, 1);
    (void)((v_digits = alg_string("")));
    while (alg_truthy(alg_bool(true))) {
        {
            if (alg_truthy(alg_invoke(v_this, "InAlphabet", (Value[]){v_alphabet, alg_invoke(v_this, "Peek", NULL, 0)}, 2))) {
                {
                    (void)((v_digits = alg_add(v_digits, alg_str(alg_invoke(v_this, "Peek", NULL, 0)))));
                    (void)(alg_invoke(v_this, "Advance", NULL, 0));
                }
            } else {
                if (alg_truthy((or_12 = alg_equal(alg_invoke(v_this, "Peek", NULL, 0), alg_char_value(95)), !alg_truthy(or_12) ? or_12 : alg_invoke(v_this, "InAlphabet", (Value[]){v_alphabet, alg_invoke(v_this, "PeekNext", NULL, 0)}, 2)))) {
                    (void)(alg_invoke(v_this, "Advance", NULL, 0));
                } else {
                    {
                        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVinteger, f_toradix(NULL, (Value[]){v_digits, v_alphabet}, 2)}, 2));
                        Value ret_18 = alg_nil();
                        alg_root_top = rt_base;
                        return ret_18;
                    }
                }
            }
        }
    }
    Value ret_19 = alg_nil();
    alg_root_top = rt_base;
    return ret_19;
}

static Value m_scanner_inalphabet_2_string_char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_alphabet = alg_widen(args[0], "String");
    (void)v_alphabet;
    alg_root(&v_alphabet, 1);
    Value v_c = alg_widen(args[1], "Char");
    (void)v_c;
    alg_root(&v_c, 1);
    Value ret_20 = alg_greater_equal(alg_pos(v_alphabet, alg_to_lower(alg_str(v_c))), alg_int(0));
    alg_root_top = rt_base;
    return ret_20;
    Value ret_21 = alg_nil();
    alg_root_top = rt_base;
    return ret_21;
}

static Value m_scanner_ishexdigit_1_char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_c = alg_widen(args[0], "Char");
    (void)v_c;
    alg_root(&v_c, 1);
    Value ret_22 = alg_invoke(v_this, "InAlphabet", (Value[]){(alg_declared(d_hexdigits, "HEXDIGITS"), v_hexdigits), v_c}, 2);
    alg_root_top = rt_base;
    return ret_22;
    Value ret_23 = alg_nil();
    alg_root_top = rt_base;
    return ret_23;
}

static Value m_scanner_isexponent_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    (void)((v_at = alg_add(alg_property(v_this, "Current"), alg_int(1))));
    if (alg_truthy(alg_less(v_at, alg_text_length(alg_property(v_this, "Source"))))) {
        if (alg_truthy((or_13 = alg_equal(alg_subscript_get(alg_property(v_this, "Source"), v_at), alg_char_value(43)), alg_truthy(or_13) ? or_13 : alg_equal(alg_subscript_get(alg_property(v_this, "Source"), v_at), alg_char_value(45))))) {
            (void)((v_at = alg_add(v_at, alg_int(1))));
        }
    }
    if (alg_truthy(alg_greater_equal(v_at, alg_text_length(alg_property(v_this, "Source"))))) {
        Value ret_24 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_24;
    }
    Value ret_25 = alg_invoke(v_this, "IsDigit", (Value[]){alg_subscript_get(alg_property(v_this, "Source"), v_at)}, 1);
    alg_root_top = rt_base;
    return ret_25;
    Value ret_26 = alg_nil();
    alg_root_top = rt_base;
    return ret_26;
}

static Value m_scanner_scanstring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    Value v_opened = alg_nil();
    (void)v_opened;
    alg_root(&v_opened, 1);
    (void)((v_value = alg_string("")));
    (void)((v_opened = alg_property(v_this, "Line")));
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
            (void)((v_value = alg_add(v_value, alg_invoke(v_this, "Advance", NULL, 0))));
        }
    }
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        {
            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_add(alg_add(alg_string("[line "), v_opened), alg_string("] Error: Unterminated string.")))));
            Value ret_27 = alg_nil();
            alg_root_top = rt_base;
            return ret_27;
        }
    }
    (void)(alg_invoke(v_this, "Advance", NULL, 0));
    if (alg_truthy(alg_equal(alg_text_length(v_value), alg_int(1)))) {
        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVchar, alg_subscript_get(v_value, alg_int(0))}, 2));
    } else {
        (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVstring, v_value}, 2));
    }
    Value ret_28 = alg_nil();
    alg_root_top = rt_base;
    return ret_28;
}

static Value m_scanner_scanchar_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_not(alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1)))) {
        {
            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_add(alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: Invalid character: ")), alg_invoke(v_this, "Peek", NULL, 0)))));
            Value ret_29 = alg_nil();
            alg_root_top = rt_base;
            return ret_29;
        }
    }
    while (alg_truthy(alg_invoke(v_this, "IsDigit", (Value[]){alg_invoke(v_this, "Peek", NULL, 0)}, 1))) {
        (void)(alg_invoke(v_this, "Advance", NULL, 0));
    }
    Value v_code = f_tointeger(NULL, (Value[]){alg_copy(alg_property(v_this, "Source"), alg_add(alg_property(v_this, "Start"), alg_int(1)), alg_subtract(alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start")), alg_int(1)))}, 1);
    (void)v_code;
    alg_root(&v_code, 1);
    if (alg_truthy(alg_equal(v_code, alg_int(0)))) {
        {
            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: '#0' is not a Char.")))));
            Value ret_30 = alg_nil();
            alg_root_top = rt_base;
            return ret_30;
        }
    }
    if (alg_truthy((or_15 = alg_greater(v_code, alg_int(1114111)), alg_truthy(or_15) ? or_15 : ((or_14 = alg_greater_equal(v_code, alg_int(55296)), !alg_truthy(or_14) ? or_14 : alg_less_equal(v_code, alg_int(57343))))))) {
        {
            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_add(alg_add(alg_add(alg_string("[line "), alg_property(v_this, "Line")), alg_string("] Error: Char is limited to 0..10FFFF, excluding D800..DFFF: #")), v_code))));
            Value ret_31 = alg_nil();
            alg_root_top = rt_base;
            return ret_31;
        }
    }
    (void)(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVchar, alg_char(v_code)}, 2));
    Value ret_32 = alg_nil();
    alg_root_top = rt_base;
    return ret_32;
}

static Value m_scanner_match_1_char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_expected = alg_widen(args[0], "Char");
    (void)v_expected;
    alg_root(&v_expected, 1);
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        Value ret_33 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_33;
    }
    if (alg_truthy(alg_not_equal(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Current")), v_expected))) {
        Value ret_34 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_34;
    }
    (void)(alg_set_property(v_this, "Current", alg_add(alg_property(v_this, "Current"), alg_int(1))));
    Value ret_35 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_35;
    Value ret_36 = alg_nil();
    alg_root_top = rt_base;
    return ret_36;
}

static Value m_scanner_peek_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        Value ret_37 = alg_char(alg_int(0));
        alg_root_top = rt_base;
        return ret_37;
    }
    Value ret_38 = alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Current"));
    alg_root_top = rt_base;
    return ret_38;
    Value ret_39 = alg_nil();
    alg_root_top = rt_base;
    return ret_39;
}

static Value m_scanner_peeknext_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_greater_equal(alg_add(alg_property(v_this, "Current"), alg_int(1)), alg_text_length(alg_property(v_this, "Source"))))) {
        Value ret_40 = alg_char(alg_int(0));
        alg_root_top = rt_base;
        return ret_40;
    }
    Value ret_41 = alg_subscript_get(alg_property(v_this, "Source"), alg_add(alg_property(v_this, "Current"), alg_int(1)));
    alg_root_top = rt_base;
    return ret_41;
    Value ret_42 = alg_nil();
    alg_root_top = rt_base;
    return ret_42;
}

static Value m_scanner_addtoken_1_tokentype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_typeoftoken = alg_widen(args[0], "TokenType");
    (void)v_typeoftoken;
    alg_root(&v_typeoftoken, 1);
    (void)(alg_invoke(v_this, "AddToken", (Value[]){v_typeoftoken, alg_nil()}, 2));
    Value ret_43 = alg_nil();
    alg_root_top = rt_base;
    return ret_43;
}

static Value m_scanner_addtoken_2_tokentype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_typeoftoken = alg_widen(args[0], "TokenType");
    (void)v_typeoftoken;
    alg_root(&v_typeoftoken, 1);
    Value v_literal = args[1];
    (void)v_literal;
    alg_root(&v_literal, 1);
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    Value v_thetoken = alg_nil();
    (void)v_thetoken;
    alg_root(&v_thetoken, 1);
    (void)((v_text = alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "Start"), alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start")))));
    (void)((v_thetoken = alg_new(k_token, (Value[]){v_typeoftoken, v_text, v_literal, alg_property(v_this, "Line")}, 4)));
    (void)(alg_set_property(v_thetoken, "Offset", alg_subtract(alg_property(v_this, "Start"), alg_property(v_this, "LineStart"))));
    (void)(alg_set_property(v_thetoken, "File", alg_property(v_this, "FileName")));
    (void)(alg_invoke(alg_property(v_this, "Tokens"), "Add", (Value[]){v_thetoken}, 1));
    Value ret_44 = alg_nil();
    alg_root_top = rt_base;
    return ret_44;
}

static Value m_scanner_isatend_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_45 = alg_greater_equal(alg_property(v_this, "Current"), alg_text_length(alg_property(v_this, "Source")));
    alg_root_top = rt_base;
    return ret_45;
    Value ret_46 = alg_nil();
    alg_root_top = rt_base;
    return ret_46;
}

static Value m_scanner_advance_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_returnvalue = alg_nil();
    (void)v_returnvalue;
    alg_root(&v_returnvalue, 1);
    (void)((v_returnvalue = alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Current"))));
    (void)(alg_set_property(v_this, "Current", alg_add(alg_property(v_this, "Current"), alg_int(1))));
    Value ret_47 = v_returnvalue;
    alg_root_top = rt_base;
    return ret_47;
    Value ret_48 = alg_nil();
    alg_root_top = rt_base;
    return ret_48;
}

static Value m_scanner_isalpha_1_char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_c = alg_widen(args[0], "Char");
    (void)v_c;
    alg_root(&v_c, 1);
    if (alg_truthy((or_16 = alg_greater_equal(v_c, alg_char_value(97)), !alg_truthy(or_16) ? or_16 : alg_less_equal(v_c, alg_char_value(122))))) {
        Value ret_49 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_49;
    }
    if (alg_truthy((or_17 = alg_greater_equal(v_c, alg_char_value(65)), !alg_truthy(or_17) ? or_17 : alg_less_equal(v_c, alg_char_value(90))))) {
        Value ret_50 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_50;
    }
    if (alg_truthy(alg_equal(v_c, alg_char_value(95)))) {
        Value ret_51 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_51;
    }
    Value ret_52 = alg_greater(alg_ord(v_c), alg_int(127));
    alg_root_top = rt_base;
    return ret_52;
    Value ret_53 = alg_nil();
    alg_root_top = rt_base;
    return ret_53;
}

static Value m_scanner_ismark_1_char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_c = alg_widen(args[0], "Char");
    (void)v_c;
    alg_root(&v_c, 1);
    Value ret_54 = (or_18 = (alg_equal(v_c, alg_char_value(63))), alg_truthy(or_18) ? or_18 : (alg_equal(v_c, alg_char_value(33))));
    alg_root_top = rt_base;
    return ret_54;
    Value ret_55 = alg_nil();
    alg_root_top = rt_base;
    return ret_55;
}

static Value m_scanner_isalphanumeric_1_char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_c = alg_widen(args[0], "Char");
    (void)v_c;
    alg_root(&v_c, 1);
    Value ret_56 = (or_20 = (or_19 = alg_invoke(v_this, "IsAlpha", (Value[]){v_c}, 1), alg_truthy(or_19) ? or_19 : alg_invoke(v_this, "IsDigit", (Value[]){v_c}, 1)), alg_truthy(or_20) ? or_20 : alg_invoke(v_this, "IsMark", (Value[]){v_c}, 1));
    alg_root_top = rt_base;
    return ret_56;
    Value ret_57 = alg_nil();
    alg_root_top = rt_base;
    return ret_57;
}

static Value m_scanner_isdigit_1_char(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_c = alg_widen(args[0], "Char");
    (void)v_c;
    alg_root(&v_c, 1);
    Value ret_58 = (or_21 = alg_greater_equal(v_c, alg_char_value(48)), !alg_truthy(or_21) ? or_21 : alg_less_equal(v_c, alg_char_value(57)));
    alg_root_top = rt_base;
    return ret_58;
    Value ret_59 = alg_nil();
    alg_root_top = rt_base;
    return ret_59;
}

static Value *roots_Scanner[] = {
    &v_digits,
    &v_hexdigits,
    &v_bindigits,
    &fn_tointeger,
    &fn_toradix,
    &v_keywords,
    &v_haderror,
    &v_lasterror,
    &k_scanner,
};

void init_Scanner(void) {
    alg_roots(roots_Scanner, 9);
    k_scanner = alg_class("Scanner", alg_nil());
    fn_tointeger = alg_closure("ToInteger", f_tointeger, NULL, 0, 1, t_f_tointeger);
    fn_toradix = alg_closure("ToRadix", f_toradix, NULL, 0, 2, t_f_toradix);
    alg_class_field(k_scanner, "Source");
    alg_class_field(k_scanner, "Tokens");
    alg_class_field(k_scanner, "Current");
    alg_class_field(k_scanner, "Start");
    alg_class_field(k_scanner, "Line");
    alg_class_field(k_scanner, "LineStart");
    alg_class_field(k_scanner, "FileName");
    alg_class_initializer(k_scanner, i_scanner);
    alg_class_method(k_scanner, "Init", m_scanner_init_1, 1, t_scanner_init_1);
    alg_class_method(k_scanner, "Init", m_scanner_init_2_string, 2, t_scanner_init_2_string);
    alg_class_method(k_scanner, "ScanTokens", m_scanner_scantokens_0, 0, NULL);
    alg_class_method(k_scanner, "ScanToken", m_scanner_scantoken_0, 0, NULL);
    alg_class_method(k_scanner, "ScanIdentifier", m_scanner_scanidentifier_0, 0, NULL);
    alg_class_method(k_scanner, "ScanNumber", m_scanner_scannumber_0, 0, NULL);
    alg_class_method(k_scanner, "ScanDigits", m_scanner_scandigits_0, 0, NULL);
    alg_class_method(k_scanner, "ScanRadix", m_scanner_scanradix_1_string, 1, t_scanner_scanradix_1_string);
    alg_class_method(k_scanner, "InAlphabet", m_scanner_inalphabet_2_string_char, 2, t_scanner_inalphabet_2_string_char);
    alg_class_method(k_scanner, "IsHexDigit", m_scanner_ishexdigit_1_char, 1, t_scanner_ishexdigit_1_char);
    alg_class_method(k_scanner, "IsExponent", m_scanner_isexponent_0, 0, NULL);
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
    v_hexdigits = alg_string("0123456789abcdef");
    d_hexdigits = true;
    v_bindigits = alg_string("01");
    d_bindigits = true;
    v_keywords = alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map(), alg_string("and"), e_tokentype_tokenVand), alg_string("as"), e_tokentype_tokenVas), alg_string("begin"), e_tokentype_tokenVbegin), alg_string("break"), e_tokentype_tokenVbreak), alg_string("continue"), e_tokentype_tokenVcontinue), alg_string("goto"), e_tokentype_tokenVgoto), alg_string("case"), e_tokentype_tokenVcase), alg_string("class"), e_tokentype_tokenVclass), alg_string("const"), e_tokentype_tokenVconst), alg_string("constructor"), e_tokentype_tokenVconstructor), alg_string("div"), e_tokentype_tokenVdiv), alg_string("do"), e_tokentype_tokenVdo), alg_string("else"), e_tokentype_tokenVelse), alg_string("end"), e_tokentype_tokenVend), alg_string("except"), e_tokentype_tokenVexcept), alg_string("exit"), e_tokentype_tokenVexit), alg_string("false"), e_tokentype_tokenVfalse), alg_string("for"), e_tokentype_tokenVfor), alg_string("function"), e_tokentype_tokenVfunction), alg_string("if"), e_tokentype_tokenVif), alg_string("in"), e_tokentype_tokenVin), alg_string("is"), e_tokentype_tokenVis), alg_string("mod"), e_tokentype_tokenVmod), alg_string("nil"), e_tokentype_tokenVnil), alg_string("not"), e_tokentype_tokenVnot), alg_string("object"), e_tokentype_tokenVobject), alg_string("of"), e_tokentype_tokenVof), alg_string("or"), e_tokentype_tokenVor), alg_string("private"), e_tokentype_tokenVprivate), alg_string("procedure"), e_tokentype_tokenVprocedure), alg_string("property"), e_tokentype_tokenVproperty), alg_string("operator"), e_tokentype_tokenVoperator), alg_string("external"), e_tokentype_tokenVexternal), alg_string("public"), e_tokentype_tokenVpublic), alg_string("raise"), e_tokentype_tokenVraise), alg_string("super"), e_tokentype_tokenVsuper), alg_string("uses"), e_tokentype_tokenVuses), alg_string("then"), e_tokentype_tokenVthen), alg_string("try"), e_tokentype_tokenVtry), alg_string("this"), e_tokentype_tokenVthis), alg_string("true"), e_tokentype_tokenVtrue), alg_string("type"), e_tokentype_tokenVtype), alg_string("var"), e_tokentype_tokenVvar), alg_string("while"), e_tokentype_tokenVwhile);
    d_keywords = true;
    v_haderror = alg_bool(false);
    d_haderror = true;
    v_lasterror = alg_nil();
    d_lasterror = true;
}
