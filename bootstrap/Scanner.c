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
    Value v_text = alg_param_of(args[0], "String", "ToInteger");
    (void)v_text;
    alg_root(&v_text, 1);
    int32_t rh_125 = alg_hold_top;
    Value v_result = alg_int(0);
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_125;
    {
        int32_t rt_126 = alg_root_top;
        int32_t rh_127 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_127;
        {
            int32_t rh_128 = alg_hold_top;
            for (; (alg_hold_top = rh_128, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_text_length(v_text)))))); (alg_hold_top = rh_128, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                (void)((v_result = alg_hold(alg_add(alg_hold(alg_multiply(v_result, alg_int(10))), alg_hold(alg_pos((alg_declared(d_digits, "DIGITS"), v_digits), alg_hold(alg_copy(v_text, v_i, alg_int(1)))))))));
            }
        }
        alg_hold_top = rh_127;
        alg_root_top = rt_126;
    }
    alg_hold_top = rh_125;
    Value ret_0 = v_result;
    alg_root_top = rt_base;
    return ret_0;
    alg_hold_top = rh_125;
    Value ret_1 = alg_nil();
    alg_root_top = rt_base;
    return ret_1;
}

Value f_toradix(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_text = alg_param_of(args[0], "String", "ToRadix");
    (void)v_text;
    alg_root(&v_text, 1);
    Value v_alphabet = alg_param_of(args[1], "String", "ToRadix");
    (void)v_alphabet;
    alg_root(&v_alphabet, 1);
    int32_t rh_129 = alg_hold_top;
    Value v_result = alg_int(0);
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_129;
    {
        int32_t rt_130 = alg_root_top;
        int32_t rh_131 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_131;
        {
            int32_t rh_132 = alg_hold_top;
            for (; (alg_hold_top = rh_132, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_text_length(v_text)))))); (alg_hold_top = rh_132, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                (void)((v_result = alg_hold(alg_add(alg_hold(alg_multiply(v_result, alg_hold(alg_text_length(v_alphabet)))), alg_hold(alg_pos(v_alphabet, alg_hold(alg_to_lower(alg_hold(alg_copy(v_text, v_i, alg_int(1)))))))))));
            }
        }
        alg_hold_top = rh_131;
        alg_root_top = rt_130;
    }
    alg_hold_top = rh_129;
    Value ret_2 = v_result;
    alg_root_top = rt_base;
    return ret_2;
    alg_hold_top = rh_129;
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
    alg_set_property(v_this, "FileName", alg_widen(alg_literal(""), "String"));
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
    int32_t rh_133 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Source", alg_hold(alg_str(v_source)))));
    alg_hold_top = rh_133;
    (void)(alg_hold(alg_set_property(v_this, "Current", alg_int(0))));
    alg_hold_top = rh_133;
    (void)(alg_hold(alg_set_property(v_this, "Start", alg_int(0))));
    alg_hold_top = rh_133;
    (void)(alg_hold(alg_set_property(v_this, "Line", alg_int(1))));
    alg_hold_top = rh_133;
    (void)(alg_hold(alg_set_property(v_this, "LineStart", alg_int(0))));
    alg_hold_top = rh_133;
    (void)(alg_hold(alg_set_property(v_this, "Tokens", alg_hold(alg_list()))));
    alg_hold_top = rh_133;
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
    int32_t rh_134 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Source", alg_hold(alg_str(v_source)))));
    alg_hold_top = rh_134;
    (void)(alg_hold(alg_set_property(v_this, "Current", alg_int(0))));
    alg_hold_top = rh_134;
    (void)(alg_hold(alg_set_property(v_this, "Start", alg_int(0))));
    alg_hold_top = rh_134;
    (void)(alg_hold(alg_set_property(v_this, "Line", alg_int(1))));
    alg_hold_top = rh_134;
    (void)(alg_hold(alg_set_property(v_this, "LineStart", alg_int(0))));
    alg_hold_top = rh_134;
    (void)(alg_hold(alg_set_property(v_this, "FileName", v_filename)));
    alg_hold_top = rh_134;
    (void)(alg_hold(alg_set_property(v_this, "Tokens", alg_hold(alg_list()))));
    alg_hold_top = rh_134;
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

static Value m_scanner_scantokens_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_135 = alg_hold_top;
    {
        int32_t rh_136 = alg_hold_top;
        while ((alg_hold_top = rh_136, alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0))))))) {
            alg_safe_point();
            {
                int32_t rh_137 = alg_hold_top;
                (void)(alg_set_property(v_this, "Start", alg_property(v_this, "Current")));
                alg_hold_top = rh_137;
                (void)(alg_hold(alg_invoke(v_this, "ScanToken", NULL, 0)));
                alg_hold_top = rh_137;
            }
        }
    }
    alg_hold_top = rh_135;
    (void)(alg_hold(alg_invoke(alg_singleton(k_sourcecode), "Add", (Value[]){alg_property(v_this, "FileName"), alg_property(v_this, "Line"), alg_hold(alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "LineStart"), alg_hold(alg_subtract(alg_hold(alg_text_length(alg_property(v_this, "Source"))), alg_property(v_this, "LineStart")))))}, 3)));
    alg_hold_top = rh_135;
    Value v_theend = alg_hold(alg_new(k_token, (Value[]){e_tokentype_eof, alg_literal(""), alg_nil(), alg_property(v_this, "Line")}, 4));
    (void)v_theend;
    alg_root(&v_theend, 1);
    alg_hold_top = rh_135;
    (void)(alg_hold(alg_set_property(v_theend, "File", alg_property(v_this, "FileName"))));
    alg_hold_top = rh_135;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Tokens"), "Add", (Value[]){v_theend}, 1)));
    alg_hold_top = rh_135;
    Value ret_6 = alg_property(v_this, "Tokens");
    alg_root_top = rt_base;
    return ret_6;
    alg_hold_top = rh_135;
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
}

static Value m_scanner_scantoken_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_138 = alg_hold_top;
    Value v_c = alg_nil();
    (void)v_c;
    alg_root(&v_c, 1);
    alg_hold_top = rh_138;
    (void)((v_c = alg_hold(alg_invoke(v_this, "Advance", NULL, 0))));
    alg_hold_top = rh_138;
    if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(40))))) {
        (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVleftVparen}, 1)));
    } else {
        if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(41))))) {
            (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVrightVparen}, 1)));
        } else {
            if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(91))))) {
                (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVleftVbracket}, 1)));
            } else {
                if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(93))))) {
                    (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVrightVbracket}, 1)));
                } else {
                    if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(44))))) {
                        (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVcomma}, 1)));
                    } else {
                        if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(46))))) {
                            if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){alg_char_value(46)}, 1)))) {
                                (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVdotVdot}, 1)));
                            } else {
                                (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVdot}, 1)));
                            }
                        } else {
                            if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(45))))) {
                                (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVminus}, 1)));
                            } else {
                                if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(43))))) {
                                    (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVplus}, 1)));
                                } else {
                                    if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(59))))) {
                                        (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVsemicolon}, 1)));
                                    } else {
                                        if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(42))))) {
                                            (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVstar}, 1)));
                                        } else {
                                            if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(61))))) {
                                                (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVequal}, 1)));
                                            } else {
                                                if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(58))))) {
                                                    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){alg_char_value(61)}, 1)))) {
                                                        (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVassign}, 1)));
                                                    } else {
                                                        (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVcolon}, 1)));
                                                    }
                                                } else {
                                                    if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(38))))) {
                                                        (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVampersand}, 1)));
                                                    } else {
                                                        if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(124))))) {
                                                            (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVpipe}, 1)));
                                                        } else {
                                                            if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(94))))) {
                                                                (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVcaret}, 1)));
                                                            } else {
                                                                if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(126))))) {
                                                                    (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVtilde}, 1)));
                                                                } else {
                                                                    if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(62))))) {
                                                                        if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){alg_char_value(61)}, 1)))) {
                                                                            (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVgreaterVequal}, 1)));
                                                                        } else {
                                                                            if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){alg_char_value(62)}, 1)))) {
                                                                                (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVshiftVright}, 1)));
                                                                            } else {
                                                                                (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVgreater}, 1)));
                                                                            }
                                                                        }
                                                                    } else {
                                                                        if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(60))))) {
                                                                            if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){alg_char_value(62)}, 1)))) {
                                                                                (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVnotVequal}, 1)));
                                                                            } else {
                                                                                if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){alg_char_value(61)}, 1)))) {
                                                                                    (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVlessVequal}, 1)));
                                                                                } else {
                                                                                    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){alg_char_value(60)}, 1)))) {
                                                                                        (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVshiftVleft}, 1)));
                                                                                    } else {
                                                                                        (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVless}, 1)));
                                                                                    }
                                                                                }
                                                                            }
                                                                        } else {
                                                                            if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(47))))) {
                                                                                if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){alg_char_value(47)}, 1)))) {
                                                                                    {
                                                                                        int32_t rh_139 = alg_hold_top;
                                                                                        while ((alg_hold_top = rh_139, alg_truthy(alg_hold((or_0 = alg_hold(alg_not_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(10))), !alg_truthy(or_0) ? or_0 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0))))))))) {
                                                                                            alg_safe_point();
                                                                                            (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
                                                                                        }
                                                                                    }
                                                                                } else {
                                                                                    (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVslash}, 1)));
                                                                                }
                                                                            } else {
                                                                                if (alg_truthy(alg_hold((or_2 = alg_hold((or_1 = alg_hold(alg_equal(v_c, alg_char_value(9))), alg_truthy(or_1) ? or_1 : alg_hold(alg_equal(v_c, alg_char_value(13))))), alg_truthy(or_2) ? or_2 : alg_hold(alg_equal(v_c, alg_char_value(32))))))) {
                                                                                    Value ret_8 = alg_nil();
                                                                                    alg_root_top = rt_base;
                                                                                    return ret_8;
                                                                                } else {
                                                                                    if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(10))))) {
                                                                                        {
                                                                                            int32_t rh_140 = alg_hold_top;
                                                                                            (void)(alg_hold(alg_invoke(alg_singleton(k_sourcecode), "Add", (Value[]){alg_property(v_this, "FileName"), alg_property(v_this, "Line"), alg_hold(alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "LineStart"), alg_hold(alg_subtract(alg_hold(alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "LineStart"))), alg_int(1)))))}, 3)));
                                                                                            alg_hold_top = rh_140;
                                                                                            (void)(alg_set_property(v_this, "Line", alg_hold(alg_add(alg_property(v_this, "Line"), alg_int(1)))));
                                                                                            alg_hold_top = rh_140;
                                                                                            (void)(alg_set_property(v_this, "LineStart", alg_property(v_this, "Current")));
                                                                                            alg_hold_top = rh_140;
                                                                                            Value ret_9 = alg_nil();
                                                                                            alg_root_top = rt_base;
                                                                                            return ret_9;
                                                                                            alg_hold_top = rh_140;
                                                                                        }
                                                                                    } else {
                                                                                        if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(39))))) {
                                                                                            (void)(alg_hold(alg_invoke(v_this, "ScanString", NULL, 0)));
                                                                                        } else {
                                                                                            if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(35))))) {
                                                                                                (void)(alg_hold(alg_invoke(v_this, "ScanChar", NULL, 0)));
                                                                                            } else {
                                                                                                if (alg_truthy(alg_hold(alg_invoke(v_this, "IsAlpha", (Value[]){v_c}, 1)))) {
                                                                                                    (void)(alg_hold(alg_invoke(v_this, "ScanIdentifier", NULL, 0)));
                                                                                                } else {
                                                                                                    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsDigit", (Value[]){v_c}, 1)))) {
                                                                                                        (void)(alg_hold(alg_invoke(v_this, "ScanNumber", NULL, 0)));
                                                                                                    } else {
                                                                                                        {
                                                                                                            int32_t rh_141 = alg_hold_top;
                                                                                                            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
                                                                                                            alg_hold_top = rh_141;
                                                                                                            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("[line "), alg_property(v_this, "Line"))), alg_literal("] Error: Unexpected character: "))), v_c)))));
                                                                                                            alg_hold_top = rh_141;
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
    alg_hold_top = rh_138;
    Value ret_10 = alg_nil();
    alg_root_top = rt_base;
    return ret_10;
}

static Value m_scanner_scanidentifier_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_142 = alg_hold_top;
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    alg_hold_top = rh_142;
    Value v_typeoftoken = alg_nil();
    (void)v_typeoftoken;
    alg_root(&v_typeoftoken, 1);
    alg_hold_top = rh_142;
    {
        int32_t rh_143 = alg_hold_top;
        while ((alg_hold_top = rh_143, alg_truthy(alg_hold(alg_invoke(v_this, "IsAlphaNumeric", (Value[]){alg_hold(alg_invoke(v_this, "Peek", NULL, 0))}, 1))))) {
            alg_safe_point();
            (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
        }
    }
    alg_hold_top = rh_142;
    (void)((v_text = alg_hold(alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "Start"), alg_hold(alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start")))))));
    alg_hold_top = rh_142;
    (void)((v_typeoftoken = e_tokentype_tokenVidentifier));
    alg_hold_top = rh_142;
    Value v_lowered = alg_hold(alg_to_lower(v_text));
    (void)v_lowered;
    alg_root(&v_lowered, 1);
    alg_hold_top = rh_142;
    if (alg_truthy(alg_hold(alg_invoke((alg_declared(d_keywords, "Keywords"), v_keywords), "Contains", (Value[]){v_lowered}, 1)))) {
        {
            int32_t rh_144 = alg_hold_top;
            (void)((v_typeoftoken = alg_hold(alg_cast(alg_invoke((alg_declared(d_keywords, "Keywords"), v_keywords), "Get", (Value[]){v_lowered}, 1), "TokenType"))));
            alg_hold_top = rh_144;
        }
    }
    alg_hold_top = rh_142;
    (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){v_typeoftoken}, 1)));
    alg_hold_top = rh_142;
    Value ret_11 = alg_nil();
    alg_root_top = rt_base;
    return ret_11;
}

static Value m_scanner_scannumber_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_145 = alg_hold_top;
    Value v_isinteger = alg_nil();
    (void)v_isinteger;
    alg_root(&v_isinteger, 1);
    alg_hold_top = rh_145;
    Value v_digits = alg_nil();
    (void)v_digits;
    alg_root(&v_digits, 1);
    alg_hold_top = rh_145;
    if (alg_truthy(alg_hold((or_4 = alg_hold(alg_equal(alg_hold(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Start"))), alg_char_value(48))), !alg_truthy(or_4) ? or_4 : (alg_hold((or_3 = alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(120))), alg_truthy(or_3) ? or_3 : alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(88)))))))))) {
        if (alg_truthy(alg_hold(alg_invoke(v_this, "IsHexDigit", (Value[]){alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0))}, 1)))) {
            {
                int32_t rh_146 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
                alg_hold_top = rh_146;
                (void)(alg_hold(alg_invoke(v_this, "ScanRadix", (Value[]){(alg_declared(d_hexdigits, "HEXDIGITS"), v_hexdigits)}, 1)));
                alg_hold_top = rh_146;
                Value ret_12 = alg_nil();
                alg_root_top = rt_base;
                return ret_12;
                alg_hold_top = rh_146;
            }
        }
    }
    alg_hold_top = rh_145;
    if (alg_truthy(alg_hold((or_6 = alg_hold(alg_equal(alg_hold(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Start"))), alg_char_value(48))), !alg_truthy(or_6) ? or_6 : (alg_hold((or_5 = alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(98))), alg_truthy(or_5) ? or_5 : alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(66)))))))))) {
        if (alg_truthy(alg_hold((or_7 = alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0)), alg_char_value(48))), alg_truthy(or_7) ? or_7 : alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0)), alg_char_value(49))))))) {
            {
                int32_t rh_147 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
                alg_hold_top = rh_147;
                (void)(alg_hold(alg_invoke(v_this, "ScanRadix", (Value[]){(alg_declared(d_bindigits, "BINDIGITS"), v_bindigits)}, 1)));
                alg_hold_top = rh_147;
                Value ret_13 = alg_nil();
                alg_root_top = rt_base;
                return ret_13;
                alg_hold_top = rh_147;
            }
        }
    }
    alg_hold_top = rh_145;
    (void)((v_isinteger = alg_bool(true)));
    alg_hold_top = rh_145;
    (void)((v_digits = alg_hold(alg_str(alg_hold(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Start")))))));
    alg_hold_top = rh_145;
    (void)((v_digits = alg_hold(alg_add(v_digits, alg_hold(alg_invoke(v_this, "ScanDigits", NULL, 0))))));
    alg_hold_top = rh_145;
    if (alg_truthy(alg_hold((or_8 = alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(46))), !alg_truthy(or_8) ? or_8 : alg_hold(alg_invoke(v_this, "IsDigit", (Value[]){alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0))}, 1)))))) {
        {
            int32_t rh_148 = alg_hold_top;
            (void)((v_isinteger = alg_bool(false)));
            alg_hold_top = rh_148;
            (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
            alg_hold_top = rh_148;
            (void)((v_digits = alg_hold(alg_add(alg_hold(alg_add(v_digits, alg_char_value(46))), alg_hold(alg_invoke(v_this, "ScanDigits", NULL, 0))))));
            alg_hold_top = rh_148;
        }
    }
    alg_hold_top = rh_145;
    if (alg_truthy(alg_hold((or_9 = alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(101))), alg_truthy(or_9) ? or_9 : alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(69))))))) {
        if (alg_truthy(alg_hold(alg_invoke(v_this, "IsExponent", NULL, 0)))) {
            {
                int32_t rh_149 = alg_hold_top;
                (void)((v_isinteger = alg_bool(false)));
                alg_hold_top = rh_149;
                (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
                alg_hold_top = rh_149;
                (void)((v_digits = alg_hold(alg_add(v_digits, alg_char_value(101)))));
                alg_hold_top = rh_149;
                if (alg_truthy(alg_hold((or_10 = alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(43))), alg_truthy(or_10) ? or_10 : alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(45))))))) {
                    {
                        int32_t rh_150 = alg_hold_top;
                        (void)((v_digits = alg_hold(alg_add(v_digits, alg_hold(alg_str(alg_hold(alg_invoke(v_this, "Peek", NULL, 0))))))));
                        alg_hold_top = rh_150;
                        (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
                        alg_hold_top = rh_150;
                    }
                }
                alg_hold_top = rh_149;
                (void)((v_digits = alg_hold(alg_add(v_digits, alg_hold(alg_invoke(v_this, "ScanDigits", NULL, 0))))));
                alg_hold_top = rh_149;
            }
        }
    }
    alg_hold_top = rh_145;
    if (alg_truthy(v_isinteger)) {
        {
            int32_t rh_151 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVinteger, alg_hold(f_tointeger(NULL, (Value[]){v_digits}, 1))}, 2)));
            alg_hold_top = rh_151;
        }
    } else {
        (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVnumber, alg_hold(alg_val(v_digits))}, 2)));
    }
    alg_hold_top = rh_145;
    Value ret_14 = alg_nil();
    alg_root_top = rt_base;
    return ret_14;
}

static Value m_scanner_scandigits_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_152 = alg_hold_top;
    Value v_digits = alg_nil();
    (void)v_digits;
    alg_root(&v_digits, 1);
    alg_hold_top = rh_152;
    (void)((v_digits = alg_literal("")));
    alg_hold_top = rh_152;
    {
        int32_t rh_153 = alg_hold_top;
        while ((alg_hold_top = rh_153, alg_truthy(alg_bool(true)))) {
            alg_safe_point();
            {
                int32_t rh_154 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "IsDigit", (Value[]){alg_hold(alg_invoke(v_this, "Peek", NULL, 0))}, 1)))) {
                    {
                        int32_t rh_155 = alg_hold_top;
                        (void)((v_digits = alg_hold(alg_add(v_digits, alg_hold(alg_str(alg_hold(alg_invoke(v_this, "Peek", NULL, 0))))))));
                        alg_hold_top = rh_155;
                        (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
                        alg_hold_top = rh_155;
                    }
                } else {
                    if (alg_truthy(alg_hold((or_11 = alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(95))), !alg_truthy(or_11) ? or_11 : alg_hold(alg_invoke(v_this, "IsDigit", (Value[]){alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0))}, 1)))))) {
                        (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
                    } else {
                        Value ret_15 = v_digits;
                        alg_root_top = rt_base;
                        return ret_15;
                    }
                }
                alg_hold_top = rh_154;
            }
        }
    }
    alg_hold_top = rh_152;
    Value ret_16 = v_digits;
    alg_root_top = rt_base;
    return ret_16;
    alg_hold_top = rh_152;
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
    int32_t rh_156 = alg_hold_top;
    Value v_digits = alg_nil();
    (void)v_digits;
    alg_root(&v_digits, 1);
    alg_hold_top = rh_156;
    (void)((v_digits = alg_literal("")));
    alg_hold_top = rh_156;
    {
        int32_t rh_157 = alg_hold_top;
        while ((alg_hold_top = rh_157, alg_truthy(alg_bool(true)))) {
            alg_safe_point();
            {
                int32_t rh_158 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "InAlphabet", (Value[]){v_alphabet, alg_hold(alg_invoke(v_this, "Peek", NULL, 0))}, 2)))) {
                    {
                        int32_t rh_159 = alg_hold_top;
                        (void)((v_digits = alg_hold(alg_add(v_digits, alg_hold(alg_str(alg_hold(alg_invoke(v_this, "Peek", NULL, 0))))))));
                        alg_hold_top = rh_159;
                        (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
                        alg_hold_top = rh_159;
                    }
                } else {
                    if (alg_truthy(alg_hold((or_12 = alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(95))), !alg_truthy(or_12) ? or_12 : alg_hold(alg_invoke(v_this, "InAlphabet", (Value[]){v_alphabet, alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0))}, 2)))))) {
                        (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
                    } else {
                        {
                            int32_t rh_160 = alg_hold_top;
                            (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVinteger, alg_hold(f_toradix(NULL, (Value[]){v_digits, v_alphabet}, 2))}, 2)));
                            alg_hold_top = rh_160;
                            Value ret_18 = alg_nil();
                            alg_root_top = rt_base;
                            return ret_18;
                            alg_hold_top = rh_160;
                        }
                    }
                }
                alg_hold_top = rh_158;
            }
        }
    }
    alg_hold_top = rh_156;
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
    int32_t rh_161 = alg_hold_top;
    Value ret_20 = alg_hold(alg_greater_equal(alg_hold(alg_pos(v_alphabet, alg_hold(alg_to_lower(alg_hold(alg_str(v_c)))))), alg_int(0)));
    alg_root_top = rt_base;
    return ret_20;
    alg_hold_top = rh_161;
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
    int32_t rh_162 = alg_hold_top;
    Value ret_22 = alg_hold(alg_invoke(v_this, "InAlphabet", (Value[]){(alg_declared(d_hexdigits, "HEXDIGITS"), v_hexdigits), v_c}, 2));
    alg_root_top = rt_base;
    return ret_22;
    alg_hold_top = rh_162;
    Value ret_23 = alg_nil();
    alg_root_top = rt_base;
    return ret_23;
}

static Value m_scanner_isexponent_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_163 = alg_hold_top;
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    alg_hold_top = rh_163;
    (void)((v_at = alg_hold(alg_add(alg_property(v_this, "Current"), alg_int(1)))));
    alg_hold_top = rh_163;
    if (alg_truthy(alg_hold(alg_less(v_at, alg_hold(alg_text_length(alg_property(v_this, "Source"))))))) {
        if (alg_truthy(alg_hold((or_13 = alg_hold(alg_equal(alg_hold(alg_subscript_get(alg_property(v_this, "Source"), v_at)), alg_char_value(43))), alg_truthy(or_13) ? or_13 : alg_hold(alg_equal(alg_hold(alg_subscript_get(alg_property(v_this, "Source"), v_at)), alg_char_value(45))))))) {
            (void)((v_at = alg_hold(alg_add(v_at, alg_int(1)))));
        }
    }
    alg_hold_top = rh_163;
    if (alg_truthy(alg_hold(alg_greater_equal(v_at, alg_hold(alg_text_length(alg_property(v_this, "Source"))))))) {
        Value ret_24 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_24;
    }
    alg_hold_top = rh_163;
    Value ret_25 = alg_hold(alg_invoke(v_this, "IsDigit", (Value[]){alg_hold(alg_subscript_get(alg_property(v_this, "Source"), v_at))}, 1));
    alg_root_top = rt_base;
    return ret_25;
    alg_hold_top = rh_163;
    Value ret_26 = alg_nil();
    alg_root_top = rt_base;
    return ret_26;
}

static Value m_scanner_scanstring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_164 = alg_hold_top;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_164;
    Value v_opened = alg_nil();
    (void)v_opened;
    alg_root(&v_opened, 1);
    alg_hold_top = rh_164;
    (void)((v_value = alg_literal("")));
    alg_hold_top = rh_164;
    (void)((v_opened = alg_property(v_this, "Line")));
    alg_hold_top = rh_164;
    {
        int32_t rh_165 = alg_hold_top;
        while ((alg_hold_top = rh_165, alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0))))))) {
            alg_safe_point();
            {
                int32_t rh_166 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(39))))) {
                    {
                        int32_t rh_167 = alg_hold_top;
                        if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0)), alg_char_value(39))))) {
                            break;
                        }
                        alg_hold_top = rh_167;
                        (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
                        alg_hold_top = rh_167;
                    }
                }
                alg_hold_top = rh_166;
                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_char_value(10))))) {
                    (void)(alg_set_property(v_this, "Line", alg_hold(alg_add(alg_property(v_this, "Line"), alg_int(1)))));
                }
                alg_hold_top = rh_166;
                (void)((v_value = alg_hold(alg_add(v_value, alg_hold(alg_invoke(v_this, "Advance", NULL, 0))))));
                alg_hold_top = rh_166;
            }
        }
    }
    alg_hold_top = rh_164;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        {
            int32_t rh_168 = alg_hold_top;
            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
            alg_hold_top = rh_168;
            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_hold(alg_add(alg_hold(alg_add(alg_literal("[line "), v_opened)), alg_literal("] Error: Unterminated string."))))));
            alg_hold_top = rh_168;
            Value ret_27 = alg_nil();
            alg_root_top = rt_base;
            return ret_27;
            alg_hold_top = rh_168;
        }
    }
    alg_hold_top = rh_164;
    (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
    alg_hold_top = rh_164;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_text_length(v_value)), alg_int(1))))) {
        (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVchar, alg_hold(alg_subscript_get(v_value, alg_int(0)))}, 2)));
    } else {
        (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVstring, v_value}, 2)));
    }
    alg_hold_top = rh_164;
    Value ret_28 = alg_nil();
    alg_root_top = rt_base;
    return ret_28;
}

static Value m_scanner_scanchar_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_169 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsDigit", (Value[]){alg_hold(alg_invoke(v_this, "Peek", NULL, 0))}, 1)))))) {
        {
            int32_t rh_170 = alg_hold_top;
            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
            alg_hold_top = rh_170;
            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("[line "), alg_property(v_this, "Line"))), alg_literal("] Error: Invalid character: "))), alg_hold(alg_invoke(v_this, "Peek", NULL, 0)))))));
            alg_hold_top = rh_170;
            Value ret_29 = alg_nil();
            alg_root_top = rt_base;
            return ret_29;
            alg_hold_top = rh_170;
        }
    }
    alg_hold_top = rh_169;
    {
        int32_t rh_171 = alg_hold_top;
        while ((alg_hold_top = rh_171, alg_truthy(alg_hold(alg_invoke(v_this, "IsDigit", (Value[]){alg_hold(alg_invoke(v_this, "Peek", NULL, 0))}, 1))))) {
            alg_safe_point();
            (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
        }
    }
    alg_hold_top = rh_169;
    Value v_code = alg_hold(f_tointeger(NULL, (Value[]){alg_hold(alg_copy(alg_property(v_this, "Source"), alg_hold(alg_add(alg_property(v_this, "Start"), alg_int(1))), alg_hold(alg_subtract(alg_hold(alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start"))), alg_int(1)))))}, 1));
    (void)v_code;
    alg_root(&v_code, 1);
    alg_hold_top = rh_169;
    if (alg_truthy(alg_hold(alg_equal(v_code, alg_int(0))))) {
        {
            int32_t rh_172 = alg_hold_top;
            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
            alg_hold_top = rh_172;
            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_hold(alg_add(alg_hold(alg_add(alg_literal("[line "), alg_property(v_this, "Line"))), alg_literal("] Error: '#0' is not a Char."))))));
            alg_hold_top = rh_172;
            Value ret_30 = alg_nil();
            alg_root_top = rt_base;
            return ret_30;
            alg_hold_top = rh_172;
        }
    }
    alg_hold_top = rh_169;
    if (alg_truthy(alg_hold((or_15 = alg_hold(alg_greater(v_code, alg_int(1114111))), alg_truthy(or_15) ? or_15 : (alg_hold((or_14 = alg_hold(alg_greater_equal(v_code, alg_int(55296))), !alg_truthy(or_14) ? or_14 : alg_hold(alg_less_equal(v_code, alg_int(57343)))))))))) {
        {
            int32_t rh_173 = alg_hold_top;
            (void)((alg_declared(d_haderror, "HadError"), (v_haderror = alg_bool(true))));
            alg_hold_top = rh_173;
            (void)((alg_declared(d_lasterror, "LastError"), (v_lasterror = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("[line "), alg_property(v_this, "Line"))), alg_literal("] Error: Char is limited to 0..10FFFF, excluding D800..DFFF: #"))), v_code)))));
            alg_hold_top = rh_173;
            Value ret_31 = alg_nil();
            alg_root_top = rt_base;
            return ret_31;
            alg_hold_top = rh_173;
        }
    }
    alg_hold_top = rh_169;
    (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){e_tokentype_tokenVchar, alg_hold(alg_char(v_code))}, 2)));
    alg_hold_top = rh_169;
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
    int32_t rh_174 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        Value ret_33 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_33;
    }
    alg_hold_top = rh_174;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Current"))), v_expected)))) {
        Value ret_34 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_34;
    }
    alg_hold_top = rh_174;
    (void)(alg_set_property(v_this, "Current", alg_hold(alg_add(alg_property(v_this, "Current"), alg_int(1)))));
    alg_hold_top = rh_174;
    Value ret_35 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_35;
    alg_hold_top = rh_174;
    Value ret_36 = alg_nil();
    alg_root_top = rt_base;
    return ret_36;
}

static Value m_scanner_peek_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_175 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        Value ret_37 = alg_hold(alg_char(alg_int(0)));
        alg_root_top = rt_base;
        return ret_37;
    }
    alg_hold_top = rh_175;
    Value ret_38 = alg_hold(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Current")));
    alg_root_top = rt_base;
    return ret_38;
    alg_hold_top = rh_175;
    Value ret_39 = alg_nil();
    alg_root_top = rt_base;
    return ret_39;
}

static Value m_scanner_peeknext_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_176 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_greater_equal(alg_hold(alg_add(alg_property(v_this, "Current"), alg_int(1))), alg_hold(alg_text_length(alg_property(v_this, "Source"))))))) {
        Value ret_40 = alg_hold(alg_char(alg_int(0)));
        alg_root_top = rt_base;
        return ret_40;
    }
    alg_hold_top = rh_176;
    Value ret_41 = alg_hold(alg_subscript_get(alg_property(v_this, "Source"), alg_hold(alg_add(alg_property(v_this, "Current"), alg_int(1)))));
    alg_root_top = rt_base;
    return ret_41;
    alg_hold_top = rh_176;
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
    int32_t rh_177 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "AddToken", (Value[]){v_typeoftoken, alg_nil()}, 2)));
    alg_hold_top = rh_177;
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
    int32_t rh_178 = alg_hold_top;
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    alg_hold_top = rh_178;
    Value v_thetoken = alg_nil();
    (void)v_thetoken;
    alg_root(&v_thetoken, 1);
    alg_hold_top = rh_178;
    (void)((v_text = alg_hold(alg_copy(alg_property(v_this, "Source"), alg_property(v_this, "Start"), alg_hold(alg_subtract(alg_property(v_this, "Current"), alg_property(v_this, "Start")))))));
    alg_hold_top = rh_178;
    (void)((v_thetoken = alg_hold(alg_new(k_token, (Value[]){v_typeoftoken, v_text, v_literal, alg_property(v_this, "Line")}, 4))));
    alg_hold_top = rh_178;
    (void)(alg_hold(alg_set_property(v_thetoken, "Offset", alg_hold(alg_subtract(alg_property(v_this, "Start"), alg_property(v_this, "LineStart"))))));
    alg_hold_top = rh_178;
    (void)(alg_hold(alg_set_property(v_thetoken, "File", alg_property(v_this, "FileName"))));
    alg_hold_top = rh_178;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Tokens"), "Add", (Value[]){v_thetoken}, 1)));
    alg_hold_top = rh_178;
    Value ret_44 = alg_nil();
    alg_root_top = rt_base;
    return ret_44;
}

static Value m_scanner_isatend_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_179 = alg_hold_top;
    Value ret_45 = alg_hold(alg_greater_equal(alg_property(v_this, "Current"), alg_hold(alg_text_length(alg_property(v_this, "Source")))));
    alg_root_top = rt_base;
    return ret_45;
    alg_hold_top = rh_179;
    Value ret_46 = alg_nil();
    alg_root_top = rt_base;
    return ret_46;
}

static Value m_scanner_advance_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_180 = alg_hold_top;
    Value v_returnvalue = alg_nil();
    (void)v_returnvalue;
    alg_root(&v_returnvalue, 1);
    alg_hold_top = rh_180;
    (void)((v_returnvalue = alg_hold(alg_subscript_get(alg_property(v_this, "Source"), alg_property(v_this, "Current")))));
    alg_hold_top = rh_180;
    (void)(alg_set_property(v_this, "Current", alg_hold(alg_add(alg_property(v_this, "Current"), alg_int(1)))));
    alg_hold_top = rh_180;
    Value ret_47 = v_returnvalue;
    alg_root_top = rt_base;
    return ret_47;
    alg_hold_top = rh_180;
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
    int32_t rh_181 = alg_hold_top;
    if (alg_truthy(alg_hold((or_16 = alg_hold(alg_greater_equal(v_c, alg_char_value(97))), !alg_truthy(or_16) ? or_16 : alg_hold(alg_less_equal(v_c, alg_char_value(122))))))) {
        Value ret_49 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_49;
    }
    alg_hold_top = rh_181;
    if (alg_truthy(alg_hold((or_17 = alg_hold(alg_greater_equal(v_c, alg_char_value(65))), !alg_truthy(or_17) ? or_17 : alg_hold(alg_less_equal(v_c, alg_char_value(90))))))) {
        Value ret_50 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_50;
    }
    alg_hold_top = rh_181;
    if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(95))))) {
        Value ret_51 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_51;
    }
    alg_hold_top = rh_181;
    Value ret_52 = alg_hold(alg_greater(alg_hold(alg_ord(v_c)), alg_int(127)));
    alg_root_top = rt_base;
    return ret_52;
    alg_hold_top = rh_181;
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
    int32_t rh_182 = alg_hold_top;
    Value ret_54 = alg_hold((or_18 = (alg_hold(alg_equal(v_c, alg_char_value(63)))), alg_truthy(or_18) ? or_18 : (alg_hold(alg_equal(v_c, alg_char_value(33))))));
    alg_root_top = rt_base;
    return ret_54;
    alg_hold_top = rh_182;
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
    int32_t rh_183 = alg_hold_top;
    Value ret_56 = alg_hold((or_20 = alg_hold((or_19 = alg_hold(alg_invoke(v_this, "IsAlpha", (Value[]){v_c}, 1)), alg_truthy(or_19) ? or_19 : alg_hold(alg_invoke(v_this, "IsDigit", (Value[]){v_c}, 1)))), alg_truthy(or_20) ? or_20 : alg_hold(alg_invoke(v_this, "IsMark", (Value[]){v_c}, 1))));
    alg_root_top = rt_base;
    return ret_56;
    alg_hold_top = rh_183;
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
    int32_t rh_184 = alg_hold_top;
    Value ret_58 = alg_hold((or_21 = alg_hold(alg_greater_equal(v_c, alg_char_value(48))), !alg_truthy(or_21) ? or_21 : alg_hold(alg_less_equal(v_c, alg_char_value(57)))));
    alg_root_top = rt_base;
    return ret_58;
    alg_hold_top = rh_184;
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
    alg_class_field(k_scanner, "Source", "String");
    alg_class_field(k_scanner, "Tokens", "List");
    alg_class_field(k_scanner, "Current", "Integer");
    alg_class_field(k_scanner, "Start", "Integer");
    alg_class_field(k_scanner, "Line", "Integer");
    alg_class_field(k_scanner, "LineStart", "Integer");
    alg_class_field(k_scanner, "FileName", "String");
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
    int32_t rh_124 = alg_hold_top;
    init_SourceCode();
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    v_digits = alg_literal("0123456789");
    d_digits = true;
    alg_hold_top = rh_124;
    v_hexdigits = alg_literal("0123456789abcdef");
    d_hexdigits = true;
    alg_hold_top = rh_124;
    v_bindigits = alg_literal("01");
    d_bindigits = true;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    v_keywords = alg_hold(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map(), alg_literal("and"), e_tokentype_tokenVand), alg_literal("as"), e_tokentype_tokenVas), alg_literal("begin"), e_tokentype_tokenVbegin), alg_literal("break"), e_tokentype_tokenVbreak), alg_literal("continue"), e_tokentype_tokenVcontinue), alg_literal("goto"), e_tokentype_tokenVgoto), alg_literal("case"), e_tokentype_tokenVcase), alg_literal("class"), e_tokentype_tokenVclass), alg_literal("const"), e_tokentype_tokenVconst), alg_literal("constructor"), e_tokentype_tokenVconstructor), alg_literal("div"), e_tokentype_tokenVdiv), alg_literal("do"), e_tokentype_tokenVdo), alg_literal("else"), e_tokentype_tokenVelse), alg_literal("end"), e_tokentype_tokenVend), alg_literal("except"), e_tokentype_tokenVexcept), alg_literal("exit"), e_tokentype_tokenVexit), alg_literal("false"), e_tokentype_tokenVfalse), alg_literal("for"), e_tokentype_tokenVfor), alg_literal("function"), e_tokentype_tokenVfunction), alg_literal("if"), e_tokentype_tokenVif), alg_literal("in"), e_tokentype_tokenVin), alg_literal("is"), e_tokentype_tokenVis), alg_literal("mod"), e_tokentype_tokenVmod), alg_literal("nil"), e_tokentype_tokenVnil), alg_literal("not"), e_tokentype_tokenVnot), alg_literal("object"), e_tokentype_tokenVobject), alg_literal("of"), e_tokentype_tokenVof), alg_literal("or"), e_tokentype_tokenVor), alg_literal("private"), e_tokentype_tokenVprivate), alg_literal("procedure"), e_tokentype_tokenVprocedure), alg_literal("property"), e_tokentype_tokenVproperty), alg_literal("operator"), e_tokentype_tokenVoperator), alg_literal("external"), e_tokentype_tokenVexternal), alg_literal("public"), e_tokentype_tokenVpublic), alg_literal("raise"), e_tokentype_tokenVraise), alg_literal("super"), e_tokentype_tokenVsuper), alg_literal("uses"), e_tokentype_tokenVuses), alg_literal("then"), e_tokentype_tokenVthen), alg_literal("try"), e_tokentype_tokenVtry), alg_literal("this"), e_tokentype_tokenVthis), alg_literal("true"), e_tokentype_tokenVtrue), alg_literal("type"), e_tokentype_tokenVtype), alg_literal("var"), e_tokentype_tokenVvar), alg_literal("while"), e_tokentype_tokenVwhile));
    d_keywords = true;
    alg_hold_top = rh_124;
    v_haderror = alg_bool(false);
    d_haderror = true;
    alg_hold_top = rh_124;
    v_lasterror = alg_nil();
    d_lasterror = true;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
    alg_hold_top = rh_124;
}
