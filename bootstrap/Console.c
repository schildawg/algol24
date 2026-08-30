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
    alg_set_property(v_this, "Id", alg_string("Console"));
    return alg_nil();
}

static Value m_console_repeat_2_char_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_what = alg_widen(args[0], "Char");
    (void)v_what;
    Value v_times = alg_widen(args[1], "Integer");
    (void)v_times;
    Value v_result = alg_widen(alg_string(""), "String");
    (void)v_result;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, v_times)); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)((v_result = alg_widen(alg_add(v_result, v_what), "String")));
        }
    }
    return v_result;
    return alg_nil();
}

static Value m_console_header_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_width = alg_nil();
    (void)v_width;
    (void)((v_width = alg_widen(alg_subtract(alg_subtract(alg_text_length((alg_declared(d_bar, "BAR"), v_bar)), alg_int(4)), alg_text_length(v_name)), "Integer")));
    (void)((v_width = alg_widen(alg_divide(v_width, alg_int(2)), "Integer")));
    if (alg_truthy(alg_less(v_width, alg_int(0)))) {
        (void)((v_width = alg_widen(alg_int(0), "Integer")));
    }
    (void)(alg_invoke(v_this, "Info", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(45), v_width}, 2), alg_string("[ ")), (alg_declared(d_ansiVcyan, "ANSI_CYAN"), v_ansiVcyan)), v_name), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)), alg_string(" ]")), alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(45), v_width}, 2))}, 1));
    return alg_nil();
}

static Value m_console_subheader_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    (void)(alg_invoke(v_this, "Info", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("< "), (alg_declared(d_ansiVcyan, "ANSI_CYAN"), v_ansiVcyan)), v_name), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)), alg_string(" >"))}, 1));
    return alg_nil();
}

static Value m_console_info_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_text = alg_widen(args[0], "String");
    (void)v_text;
    (void)(alg_writeln(alg_add((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag), v_text)));
    return alg_nil();
}

static Value m_console_warn_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_text = alg_widen(args[0], "String");
    (void)v_text;
    (void)(alg_writeln(alg_add((alg_declared(d_warnVtag, "WARN_TAG"), v_warnVtag), v_text)));
    return alg_nil();
}

static Value m_console_success_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_width = alg_nil();
    (void)v_width;
    (void)((v_width = alg_widen(alg_subtract(alg_subtract(alg_text_length((alg_declared(d_bar, "BAR"), v_bar)), alg_int(10)), alg_text_length(v_name)), "Integer")));
    if (alg_truthy(alg_less(v_width, alg_int(0)))) {
        (void)((v_width = alg_widen(alg_int(0), "Integer")));
    }
    (void)(alg_invoke(v_this, "Info", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(v_name, alg_char_value(32)), alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(46), v_width}, 2)), (alg_declared(d_ansiVgreen, "ANSI_GREEN"), v_ansiVgreen)), alg_string(" SUCCESS")), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset))}, 1));
    return alg_nil();
}

static Value m_console_fail_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_width = alg_nil();
    (void)v_width;
    (void)((v_width = alg_widen(alg_subtract(alg_subtract(alg_text_length((alg_declared(d_bar, "BAR"), v_bar)), alg_int(10)), alg_text_length(v_name)), "Integer")));
    if (alg_truthy(alg_less(v_width, alg_int(0)))) {
        (void)((v_width = alg_widen(alg_int(0), "Integer")));
    }
    (void)(alg_invoke(v_this, "Info", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(v_name, alg_char_value(32)), alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(46), v_width}, 2)), (alg_declared(d_ansiVred, "ANSI_RED"), v_ansiVred)), alg_string(" FAILED")), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset))}, 1));
    return alg_nil();
}

static Value m_console_debug_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_text = alg_widen(args[0], "String");
    (void)v_text;
    (void)(alg_writeln(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add((alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite), alg_char_value(91)), (alg_declared(d_ansiVyellow, "ANSI_YELLOW"), v_ansiVyellow)), alg_string("DEBUG")), (alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite)), alg_string("] ")), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)), v_text)));
    return alg_nil();
}

static Value m_console_error_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_where = alg_widen(args[0], "Token");
    (void)v_where;
    Value v_message = alg_widen(args[1], "String");
    (void)v_message;
    Value v_text = alg_nil();
    (void)v_text;
    Value v_digits = alg_nil();
    (void)v_digits;
    (void)((v_text = alg_widen(alg_cast(alg_invoke(alg_singleton(k_sourcecode), "Get", (Value[]){alg_property(v_where, "LineNumber")}, 1), "String"), "String")));
    (void)((v_digits = alg_widen(alg_text_length(alg_str(alg_property(v_where, "LineNumber"))), "Integer")));
    (void)(alg_writeln(alg_add(alg_add(alg_add((alg_declared(d_errorVtag, "ERROR_TAG"), v_errorVtag), alg_invoke(alg_singleton(k_sourcecode), "Name", NULL, 0)), alg_string(": ")), v_message)));
    (void)(alg_writeln(alg_add(alg_add(alg_add((alg_declared(d_errorVtag, "ERROR_TAG"), v_errorVtag), alg_str(alg_property(v_where, "LineNumber"))), alg_string(" | ")), v_text)));
    (void)(alg_writeln(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add((alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite), alg_char_value(91)), (alg_declared(d_ansiVred, "ANSI_RED"), v_ansiVred)), alg_string("ERROR")), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)), alg_string("] ")), alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(32), v_digits}, 2)), alg_string(" |")), (alg_declared(d_ansiVred, "ANSI_RED"), v_ansiVred)), alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(32), alg_add(alg_property(v_where, "Offset"), alg_int(1))}, 2)), alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(94), alg_text_length(alg_property(v_where, "Lexeme"))}, 2)), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset))));
    return alg_nil();
}

void init_Console(void) {
    k_console = alg_class("Console", alg_nil());
    alg_class_field(k_console, "Id");
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
    init_Scanner();
    v_bar = alg_string("------------------------------------------------------------------------");
    d_bar = true;
    v_esc = alg_char_value(27);
    d_esc = true;
    v_ansiVreset = alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_string("[0m"));
    d_ansiVreset = true;
    v_ansiVred = alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_string("[31m"));
    d_ansiVred = true;
    v_ansiVgreen = alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_string("[32m"));
    d_ansiVgreen = true;
    v_ansiVyellow = alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_string("[33m"));
    d_ansiVyellow = true;
    v_ansiVblue = alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_string("[34m"));
    d_ansiVblue = true;
    v_ansiVcyan = alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_string("[36m"));
    d_ansiVcyan = true;
    v_ansiVwhite = alg_add((alg_declared(d_esc, "ESC"), v_esc), alg_string("[37m"));
    d_ansiVwhite = true;
    v_infoVtag = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add((alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite), alg_char_value(91)), (alg_declared(d_ansiVblue, "ANSI_BLUE"), v_ansiVblue)), alg_string("INFO")), (alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite)), alg_string("] ")), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset));
    d_infoVtag = true;
    v_errorVtag = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add((alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite), alg_char_value(91)), (alg_declared(d_ansiVred, "ANSI_RED"), v_ansiVred)), alg_string("ERROR")), (alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite)), alg_string("] ")), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset));
    d_errorVtag = true;
    v_warnVtag = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add((alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite), alg_char_value(91)), (alg_declared(d_ansiVyellow, "ANSI_YELLOW"), v_ansiVyellow)), alg_string("WARN")), (alg_declared(d_ansiVwhite, "ANSI_WHITE"), v_ansiVwhite)), alg_string("] ")), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset));
    d_warnVtag = true;
}
