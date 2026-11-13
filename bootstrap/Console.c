/* Generated from Algol-24.  Do not edit. */
#include "Console.h"
#include "Scanner.h"
#include "SourceCode.h"
#include "Token.h"

Value v_bar;
bool d_bar;
Value v_esc;
bool d_esc;
Value v_ansiVreset;
bool d_ansiVreset;
Value v_ansiVred;
bool d_ansiVred;
Value v_ansiVgreen;
bool d_ansiVgreen;
Value v_ansiVyellow;
bool d_ansiVyellow;
Value v_ansiVblue;
bool d_ansiVblue;
Value v_ansiVcyan;
bool d_ansiVcyan;
Value v_ansiVwhite;
bool d_ansiVwhite;
Value v_infoVtag;
bool d_infoVtag;
Value v_errorVtag;
bool d_errorVtag;
Value v_warnVtag;
bool d_warnVtag;
Value k_console;
static const char *t_console_repeat_2_char_integer[] = { "What : Char", "Times : Integer" };
static const char *t_console_header_1_string[] = { "Name : String" };
static const char *t_console_subheader_1_string[] = { "Name : String" };
static const char *t_console_info_1_string[] = { "Text : String" };
static const char *t_console_warn_1_string[] = { "Text : String" };
static const char *t_console_success_1_string[] = { "Name : String" };
static const char *t_console_fail_1_string[] = { "Name : String" };
static const char *t_console_debug_1_string[] = { "Text : String" };
static const char *t_console_error_2_token_string[] = { "Where : Token", "Message : String" };

static Value i_console(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Id", alg_literal("Console"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_console_repeat_2_char_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_what = alg_widen(args[0], "Char");
    (void)v_what;
    alg_root(&v_what, 1);
    Value v_times = alg_widen(args[1], "Integer");
    (void)v_times;
    alg_root(&v_times, 1);
    int32_t rh_186 = alg_hold_top;
    Value v_result = alg_literal("");
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_186;
    {
        int32_t rt_187 = alg_root_top;
        int32_t rh_188 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_188;
        {
            int32_t rh_189 = alg_hold_top;
            for (; (alg_hold_top = rh_189, alg_truthy(alg_hold(alg_less(v_i, v_times)))); (alg_hold_top = rh_189, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                (void)((v_result = alg_hold(alg_add(v_result, v_what))));
            }
        }
        alg_hold_top = rh_188;
        alg_root_top = rt_187;
    }
    alg_hold_top = rh_186;
    Value ret_0 = v_result;
    alg_root_top = rt_base;
    return ret_0;
    alg_hold_top = rh_186;
    Value ret_1 = alg_nil();
    alg_root_top = rt_base;
    return ret_1;
}

static Value m_console_header_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_190 = alg_hold_top;
    Value v_width = alg_nil();
    (void)v_width;
    alg_root(&v_width, 1);
    alg_hold_top = rh_190;
    (void)((v_width = alg_hold(alg_subtract(alg_hold(alg_subtract(alg_hold(alg_text_length((alg_declared(d_bar, "BAR"), v_bar))), alg_int(4))), alg_hold(alg_text_length(v_name))))));
    alg_hold_top = rh_190;
    (void)((v_width = alg_hold(alg_div_int(v_width, alg_int(2)))));
    alg_hold_top = rh_190;
    if (alg_truthy(alg_hold(alg_less(v_width, alg_int(0))))) {
        (void)((v_width = alg_int(0)));
    }
    alg_hold_top = rh_190;
    (void)(alg_hold(alg_invoke(v_this, "Info", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(45), v_width}, 2)), alg_literal("[ "))), (alg_declared(d_ansiVcyan, "ANSI_CYAN"), v_ansiVcyan))), v_name)), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset))), alg_literal(" ]"))), alg_hold(alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(45), v_width}, 2))))}, 1)));
    alg_hold_top = rh_190;
    Value ret_2 = alg_nil();
    alg_root_top = rt_base;
    return ret_2;
}

static Value m_console_subheader_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_191 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Info", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("< "), (alg_declared(d_ansiVcyan, "ANSI_CYAN"), v_ansiVcyan))), v_name)), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset))), alg_literal(" >")))}, 1)));
    alg_hold_top = rh_191;
    Value ret_3 = alg_nil();
    alg_root_top = rt_base;
    return ret_3;
}

static Value m_console_info_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_text = alg_widen(args[0], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    int32_t rh_192 = alg_hold_top;
    (void)(alg_writeln(alg_hold(alg_add((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag), v_text))));
    alg_hold_top = rh_192;
    Value ret_4 = alg_nil();
    alg_root_top = rt_base;
    return ret_4;
}

static Value m_console_warn_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_text = alg_widen(args[0], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    int32_t rh_193 = alg_hold_top;
    (void)(alg_stderr_line(alg_hold(alg_add((alg_declared(d_warnVtag, "WARN_TAG"), v_warnVtag), v_text))));
    alg_hold_top = rh_193;
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

static Value m_console_success_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_194 = alg_hold_top;
    Value v_width = alg_nil();
    (void)v_width;
    alg_root(&v_width, 1);
    alg_hold_top = rh_194;
    (void)((v_width = alg_hold(alg_subtract(alg_hold(alg_subtract(alg_hold(alg_text_length((alg_declared(d_bar, "BAR"), v_bar))), alg_int(10))), alg_hold(alg_text_length(v_name))))));
    alg_hold_top = rh_194;
    if (alg_truthy(alg_hold(alg_less(v_width, alg_int(0))))) {
        (void)((v_width = alg_int(0)));
    }
    alg_hold_top = rh_194;
    (void)(alg_hold(alg_invoke(v_this, "Info", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_name, alg_char_value(32))), alg_hold(alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(46), v_width}, 2)))), (alg_declared(d_ansiVgreen, "ANSI_GREEN"), v_ansiVgreen))), alg_literal(" SUCCESS"))), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)))}, 1)));
    alg_hold_top = rh_194;
    Value ret_6 = alg_nil();
    alg_root_top = rt_base;
    return ret_6;
}

static Value m_console_fail_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_195 = alg_hold_top;
    Value v_width = alg_nil();
    (void)v_width;
    alg_root(&v_width, 1);
    alg_hold_top = rh_195;
    (void)((v_width = alg_hold(alg_subtract(alg_hold(alg_subtract(alg_hold(alg_text_length((alg_declared(d_bar, "BAR"), v_bar))), alg_int(10))), alg_hold(alg_text_length(v_name))))));
    alg_hold_top = rh_195;
    if (alg_truthy(alg_hold(alg_less(v_width, alg_int(0))))) {
        (void)((v_width = alg_int(0)));
    }
    alg_hold_top = rh_195;
    (void)(alg_hold(alg_invoke(v_this, "Info", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_name, alg_char_value(32))), alg_hold(alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(46), v_width}, 2)))), (alg_declared(d_ansiVred, "ANSI_RED"), v_ansiVred))), alg_literal(" FAILED"))), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)))}, 1)));
    alg_hold_top = rh_195;
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
}

static Value m_console_debug_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_text = alg_widen(args[0], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    int32_t rh_196 = alg_hold_top;
    (void)(alg_writeln(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite), alg_char_value(91))), (alg_declared(d_ansiVyellow, "ANSI_YELLOW"), v_ansiVyellow))), alg_literal("DEBUG"))), (alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite))), alg_literal("] "))), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset))), v_text))));
    alg_hold_top = rh_196;
    Value ret_8 = alg_nil();
    alg_root_top = rt_base;
    return ret_8;
}

static Value m_console_error_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_where = alg_widen(args[0], "Token");
    (void)v_where;
    alg_root(&v_where, 1);
    Value v_message = alg_widen(args[1], "String");
    (void)v_message;
    alg_root(&v_message, 1);
    int32_t rh_197 = alg_hold_top;
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    alg_hold_top = rh_197;
    Value v_digits = alg_nil();
    (void)v_digits;
    alg_root(&v_digits, 1);
    alg_hold_top = rh_197;
    (void)((v_text = alg_hold(alg_invoke(alg_singleton(k_sourcecode), "Get", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_where, "File")))), alg_hold(alg_property(v_where, "LineNumber"))}, 2))));
    alg_hold_top = rh_197;
    (void)((v_digits = alg_hold(alg_text_length(alg_hold(alg_str(alg_hold(alg_property(v_where, "LineNumber"))))))));
    alg_hold_top = rh_197;
    (void)(alg_writeln(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_errorVtag, "ERROR_TAG"), v_errorVtag), alg_hold(alg_invoke(alg_singleton(k_sourcecode), "Named", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_where, "File"))))}, 1)))), alg_literal(": "))), v_message))));
    alg_hold_top = rh_197;
    (void)(alg_writeln(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_errorVtag, "ERROR_TAG"), v_errorVtag), alg_hold(alg_str(alg_hold(alg_property(v_where, "LineNumber")))))), alg_literal(" | "))), v_text))));
    alg_hold_top = rh_197;
    (void)(alg_writeln(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite), alg_char_value(91))), (alg_declared(d_ansiVred, "ANSI_RED"), v_ansiVred))), alg_literal("ERROR"))), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset))), alg_literal("] "))), alg_hold(alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(32), v_digits}, 2)))), alg_literal(" |"))), (alg_declared(d_ansiVred, "ANSI_RED"), v_ansiVred))), alg_hold(alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(32), alg_hold(alg_add(alg_hold(alg_property(v_where, "Offset")), alg_int(1)))}, 2)))), alg_hold(alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(94), alg_hold(alg_text_length(alg_hold(alg_property(v_where, "Lexeme"))))}, 2)))), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)))));
    alg_hold_top = rh_197;
    Value ret_9 = alg_nil();
    alg_root_top = rt_base;
    return ret_9;
}

static Value *roots_Console[] = {
    &v_bar,
    &v_esc,
    &v_ansiVreset,
    &v_ansiVred,
    &v_ansiVgreen,
    &v_ansiVyellow,
    &v_ansiVblue,
    &v_ansiVcyan,
    &v_ansiVwhite,
    &v_infoVtag,
    &v_errorVtag,
    &v_warnVtag,
    &k_console,
};

void init_Console(void) {
    alg_roots(roots_Console, 13);
    k_console = alg_class("Console", alg_nil());
    alg_class_field(k_console, "Id", "String");
    alg_class_initializer(k_console, i_console);
    alg_class_method(k_console, "Repeat", m_console_repeat_2_char_integer, 2, t_console_repeat_2_char_integer);
    alg_class_method(k_console, "Header", m_console_header_1_string, 1, t_console_header_1_string);
    alg_class_method(k_console, "Subheader", m_console_subheader_1_string, 1, t_console_subheader_1_string);
    alg_class_method(k_console, "Info", m_console_info_1_string, 1, t_console_info_1_string);
    alg_class_method(k_console, "Warn", m_console_warn_1_string, 1, t_console_warn_1_string);
    alg_class_method(k_console, "Success", m_console_success_1_string, 1, t_console_success_1_string);
    alg_class_method(k_console, "Fail", m_console_fail_1_string, 1, t_console_fail_1_string);
    alg_class_method(k_console, "Debug", m_console_debug_1_string, 1, t_console_debug_1_string);
    alg_class_method(k_console, "Error", m_console_error_2_token_string, 2, t_console_error_2_token_string);
    alg_class_is_object(k_console);
    int32_t rh_185 = alg_hold_top;
    init_Scanner();
    alg_hold_top = rh_185;
    alg_hold_top = rh_185;
    alg_hold_top = rh_185;
    v_bar = alg_literal("------------------------------------------------------------------------");
    d_bar = true;
    alg_hold_top = rh_185;
    v_esc = alg_char_value(27);
    d_esc = true;
    alg_hold_top = rh_185;
    v_ansiVreset = alg_hold(alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_literal("[0m")));
    d_ansiVreset = true;
    alg_hold_top = rh_185;
    v_ansiVred = alg_hold(alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_literal("[31m")));
    d_ansiVred = true;
    alg_hold_top = rh_185;
    v_ansiVgreen = alg_hold(alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_literal("[32m")));
    d_ansiVgreen = true;
    alg_hold_top = rh_185;
    v_ansiVyellow = alg_hold(alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_literal("[33m")));
    d_ansiVyellow = true;
    alg_hold_top = rh_185;
    v_ansiVblue = alg_hold(alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_literal("[34m")));
    d_ansiVblue = true;
    alg_hold_top = rh_185;
    v_ansiVcyan = alg_hold(alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_literal("[36m")));
    d_ansiVcyan = true;
    alg_hold_top = rh_185;
    v_ansiVwhite = alg_hold(alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_literal("[37m")));
    d_ansiVwhite = true;
    alg_hold_top = rh_185;
    v_infoVtag = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite), alg_char_value(91))), (alg_declared(d_ansiVblue, "ANSI_BLUE"), v_ansiVblue))), alg_literal("INFO"))), (alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite))), alg_literal("] "))), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)));
    d_infoVtag = true;
    alg_hold_top = rh_185;
    v_errorVtag = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite), alg_char_value(91))), (alg_declared(d_ansiVred, "ANSI_RED"), v_ansiVred))), alg_literal("ERROR"))), (alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite))), alg_literal("] "))), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)));
    d_errorVtag = true;
    alg_hold_top = rh_185;
    v_warnVtag = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite), alg_char_value(91))), (alg_declared(d_ansiVyellow, "ANSI_YELLOW"), v_ansiVyellow))), alg_literal("WARN"))), (alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite))), alg_literal("] "))), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)));
    d_warnVtag = true;
    alg_hold_top = rh_185;
    alg_hold_top = rh_185;
}
