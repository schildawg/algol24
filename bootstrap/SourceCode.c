/* Generated from Algol-24.  Do not edit. */
#include "SourceCode.h"

Value k_SourceCode;
static const char *t_SourceCode_Begins_1_String[] = { "String" };
static const char *t_SourceCode_Add_2_Integer_String[] = { "Integer", "String" };
static const char *t_SourceCode_Get_1_Integer[] = { "Integer" };

static Value i_SourceCode(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Lines", alg_map());
    alg_set_property(v_this, "FileName", alg_string(""));
    alg_set_property(v_this, "Id", alg_string("SourceCode"));
    return alg_nil();
}

static Value m_SourceCode_Begins_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    (void)(alg_set_property(v_this, "Lines", alg_map()));
    (void)(alg_set_property(v_this, "FileName", v_Name));
    return alg_nil();
}

static Value m_SourceCode_Add_2_Integer_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_LineNumber = args[0];
    (void)v_LineNumber;
    Value v_Text = args[1];
    (void)v_Text;
    (void)(alg_invoke(alg_property(v_this, "Lines"), "Put", (Value[]){v_LineNumber, v_Text}, 2));
    return alg_nil();
}

static Value m_SourceCode_Get_1_Integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_LineNumber = args[0];
    (void)v_LineNumber;
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Lines"), "Contains", (Value[]){v_LineNumber}, 1)))) {
        return alg_string("");
    }
    return alg_str(alg_invoke(alg_property(v_this, "Lines"), "Get", (Value[]){v_LineNumber}, 1));
    return alg_nil();
}

static Value m_SourceCode_Name_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "FileName");
    return alg_nil();
}

void init_SourceCode(void) {
    k_SourceCode = alg_class("SourceCode", alg_nil());
    alg_class_field(k_SourceCode, "Lines");
    alg_class_field(k_SourceCode, "FileName");
    alg_class_field(k_SourceCode, "Id");
    alg_class_initializer(k_SourceCode, i_SourceCode);
    alg_class_method(k_SourceCode, "Begins", m_SourceCode_Begins_1_String, 1, t_SourceCode_Begins_1_String);
    alg_class_method(k_SourceCode, "Add", m_SourceCode_Add_2_Integer_String, 2, t_SourceCode_Add_2_Integer_String);
    alg_class_method(k_SourceCode, "Get", m_SourceCode_Get_1_Integer, 1, t_SourceCode_Get_1_Integer);
    alg_class_method(k_SourceCode, "Name", m_SourceCode_Name_0, 0, NULL);
    alg_class_is_object(k_SourceCode);
}
