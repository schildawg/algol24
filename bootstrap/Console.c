/* Generated from Algol-24.  Do not edit. */
#include "Console.h"
#include "Scanner.h"
#include "SourceCode.h"
#include "Token.h"

Value v_BAR;
Value v_ESC;
Value v_ANSI_RESET;
Value v_ANSI_RED;
Value v_ANSI_GREEN;
Value v_ANSI_YELLOW;
Value v_ANSI_BLUE;
Value v_ANSI_CYAN;
Value v_ANSI_WHITE;
Value v_INFO_TAG;
Value v_ERROR_TAG;
Value k_Console;
static const char *t_Console_Repeat_2_Char_Integer[] = { "Char", "Integer" };
static const char *t_Console_Header_1_String[] = { "String" };
static const char *t_Console_Subheader_1_String[] = { "String" };
static const char *t_Console_Info_1_String[] = { "String" };
static const char *t_Console_Success_1_String[] = { "String" };
static const char *t_Console_Fail_1_String[] = { "String" };
static const char *t_Console_Debug_1_String[] = { "String" };
static const char *t_Console_Error_2_Token_String[] = { "Token", "String" };

static Value i_Console(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Id", alg_string("Console"));
    return alg_nil();
}

static Value m_Console_Repeat_2_Char_Integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_What = args[0];
    (void)v_What;
    Value v_Times = args[1];
    (void)v_Times;
    Value v_Result = alg_string("");
    (void)v_Result;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, v_Times))) {
            {
                (void)((v_Result = alg_add(v_Result, v_What)));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Result;
    return alg_nil();
}

static Value m_Console_Header_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Width = alg_nil();
    (void)v_Width;
    (void)((v_Width = alg_subtract(alg_subtract(alg_length(v_BAR), alg_int(4)), alg_length(v_Name))));
    (void)((v_Width = alg_divide(v_Width, alg_int(2))));
    if (alg_truthy(alg_less(v_Width, alg_int(0)))) {
        (void)((v_Width = alg_int(0)));
    }
    (void)(alg_invoke(v_this, "Info", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(45), v_Width}, 2), alg_string("[ ")), v_ANSI_CYAN), v_Name), v_ANSI_RESET), alg_string(" ]")), alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(45), v_Width}, 2))}, 1));
    return alg_nil();
}

static Value m_Console_Subheader_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    (void)(alg_invoke(v_this, "Info", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("< "), v_ANSI_CYAN), v_Name), v_ANSI_RESET), alg_string(" >"))}, 1));
    return alg_nil();
}

static Value m_Console_Info_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Text = args[0];
    (void)v_Text;
    (void)(alg_writeln(alg_add(v_INFO_TAG, v_Text)));
    return alg_nil();
}

static Value m_Console_Success_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Width = alg_nil();
    (void)v_Width;
    (void)((v_Width = alg_subtract(alg_subtract(alg_length(v_BAR), alg_int(10)), alg_length(v_Name))));
    if (alg_truthy(alg_less(v_Width, alg_int(0)))) {
        (void)((v_Width = alg_int(0)));
    }
    (void)(alg_invoke(v_this, "Info", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(v_Name, alg_char_value(32)), alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(46), v_Width}, 2)), v_ANSI_GREEN), alg_string(" SUCCESS")), v_ANSI_RESET)}, 1));
    return alg_nil();
}

static Value m_Console_Fail_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Width = alg_nil();
    (void)v_Width;
    (void)((v_Width = alg_subtract(alg_subtract(alg_length(v_BAR), alg_int(10)), alg_length(v_Name))));
    if (alg_truthy(alg_less(v_Width, alg_int(0)))) {
        (void)((v_Width = alg_int(0)));
    }
    (void)(alg_invoke(v_this, "Info", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(v_Name, alg_char_value(32)), alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(46), v_Width}, 2)), v_ANSI_RED), alg_string(" FAILED")), v_ANSI_RESET)}, 1));
    return alg_nil();
}

static Value m_Console_Debug_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Text = args[0];
    (void)v_Text;
    (void)(alg_writeln(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(v_ANSI_WHITE, alg_char_value(91)), v_ANSI_YELLOW), alg_string("DEBUG")), v_ANSI_WHITE), alg_string("] ")), v_ANSI_RESET), v_Text)));
    return alg_nil();
}

static Value m_Console_Error_2_Token_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Where = args[0];
    (void)v_Where;
    Value v_Message = args[1];
    (void)v_Message;
    Value v_Text = alg_nil();
    (void)v_Text;
    Value v_Digits = alg_nil();
    (void)v_Digits;
    (void)((v_Text = alg_invoke(alg_singleton(k_SourceCode), "Get", (Value[]){alg_property(v_Where, "LineNumber")}, 1)));
    (void)((v_Digits = alg_length(alg_str(alg_property(v_Where, "LineNumber")))));
    (void)(alg_writeln(alg_add(alg_add(alg_add(v_ERROR_TAG, alg_invoke(alg_singleton(k_SourceCode), "Name", NULL, 0)), alg_string(": ")), v_Message)));
    (void)(alg_writeln(alg_add(alg_add(alg_add(v_ERROR_TAG, alg_str(alg_property(v_Where, "LineNumber"))), alg_string(" | ")), v_Text)));
    (void)(alg_writeln(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(v_ANSI_WHITE, alg_char_value(91)), v_ANSI_RED), alg_string("ERROR")), v_ANSI_RESET), alg_string("] ")), alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(32), v_Digits}, 2)), alg_string(" |")), v_ANSI_RED), alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(32), alg_add(alg_property(v_Where, "Offset"), alg_int(1))}, 2)), alg_invoke(v_this, "Repeat", (Value[]){alg_char_value(94), alg_length(alg_property(v_Where, "Lexeme"))}, 2)), v_ANSI_RESET)));
    return alg_nil();
}

void init_Console(void) {
    k_Console = alg_class("Console", alg_nil());
    alg_class_field(k_Console, "Id");
    alg_class_initializer(k_Console, i_Console);
    alg_class_method(k_Console, "Repeat", m_Console_Repeat_2_Char_Integer, 2, t_Console_Repeat_2_Char_Integer);
    alg_class_method(k_Console, "Header", m_Console_Header_1_String, 1, t_Console_Header_1_String);
    alg_class_method(k_Console, "Subheader", m_Console_Subheader_1_String, 1, t_Console_Subheader_1_String);
    alg_class_method(k_Console, "Info", m_Console_Info_1_String, 1, t_Console_Info_1_String);
    alg_class_method(k_Console, "Success", m_Console_Success_1_String, 1, t_Console_Success_1_String);
    alg_class_method(k_Console, "Fail", m_Console_Fail_1_String, 1, t_Console_Fail_1_String);
    alg_class_method(k_Console, "Debug", m_Console_Debug_1_String, 1, t_Console_Debug_1_String);
    alg_class_method(k_Console, "Error", m_Console_Error_2_Token_String, 2, t_Console_Error_2_Token_String);
    alg_class_is_object(k_Console);
    v_BAR = alg_string("------------------------------------------------------------------------");
    v_ESC = alg_char_value(27);
    v_ANSI_RESET = alg_add(v_ESC, alg_string("[0m"));
    v_ANSI_RED = alg_add(v_ESC, alg_string("[31m"));
    v_ANSI_GREEN = alg_add(v_ESC, alg_string("[32m"));
    v_ANSI_YELLOW = alg_add(v_ESC, alg_string("[33m"));
    v_ANSI_BLUE = alg_add(v_ESC, alg_string("[34m"));
    v_ANSI_CYAN = alg_add(v_ESC, alg_string("[36m"));
    v_ANSI_WHITE = alg_add(v_ESC, alg_string("[37m"));
    v_INFO_TAG = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(v_ANSI_WHITE, alg_char_value(91)), v_ANSI_BLUE), alg_string("INFO")), v_ANSI_WHITE), alg_string("] ")), v_ANSI_RESET);
    v_ERROR_TAG = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(v_ANSI_WHITE, alg_char_value(91)), v_ANSI_RED), alg_string("ERROR")), v_ANSI_WHITE), alg_string("] ")), v_ANSI_RESET);
}
