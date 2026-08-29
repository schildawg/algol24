/* Generated from Algol-24.  Do not edit. */
#include "SourceCode.h"

Value k_sourcecode;
static const char *t_sourcecode_begins_1_string[] = { "String" };
static const char *t_sourcecode_add_2_integer_string[] = { "Integer", "String" };
static const char *t_sourcecode_get_1_integer[] = { "Integer" };

static Value i_sourcecode(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Lines", alg_list());
    alg_set_property(v_this, "FileName", alg_string(""));
    alg_set_property(v_this, "Id", alg_string("SourceCode"));
    return alg_nil();
}

static Value m_sourcecode_begins_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = args[0];
    (void)v_name;
    (void)(alg_set_property(v_this, "Lines", alg_list()));
    (void)(alg_set_property(v_this, "FileName", v_name));
    return alg_nil();
}

static Value m_sourcecode_add_2_integer_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_linenumber = args[0];
    (void)v_linenumber;
    Value v_text = args[1];
    (void)v_text;
    if (alg_truthy(alg_less(v_linenumber, alg_int(1)))) {
        return alg_nil();
    }
    while (alg_truthy(alg_less(alg_property(alg_property(v_this, "Lines"), "Length"), alg_subtract(v_linenumber, alg_int(1))))) {
        (void)(alg_invoke(alg_property(v_this, "Lines"), "Add", (Value[]){alg_string("")}, 1));
    }
    if (alg_truthy(alg_equal(alg_property(alg_property(v_this, "Lines"), "Length"), alg_subtract(v_linenumber, alg_int(1))))) {
        (void)(alg_invoke(alg_property(v_this, "Lines"), "Add", (Value[]){v_text}, 1));
    } else {
        (void)(alg_subscript_set(alg_property(v_this, "Lines"), alg_subtract(v_linenumber, alg_int(1)), v_text));
    }
    return alg_nil();
}

static Value m_sourcecode_get_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_linenumber = args[0];
    (void)v_linenumber;
    if (alg_truthy(alg_less(v_linenumber, alg_int(1)))) {
        return alg_string("");
    }
    if (alg_truthy(alg_greater(v_linenumber, alg_property(alg_property(v_this, "Lines"), "Length")))) {
        return alg_string("");
    }
    return alg_str(alg_subscript_get(alg_property(v_this, "Lines"), alg_subtract(v_linenumber, alg_int(1))));
    return alg_nil();
}

static Value m_sourcecode_name_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "FileName");
    return alg_nil();
}

void init_SourceCode(void) {
    k_sourcecode = alg_class("SourceCode", alg_nil());
    alg_class_field(k_sourcecode, "Lines");
    alg_class_field(k_sourcecode, "FileName");
    alg_class_field(k_sourcecode, "Id");
    alg_class_initializer(k_sourcecode, i_sourcecode);
    alg_class_method(k_sourcecode, "Begins", m_sourcecode_begins_1_string, 1, t_sourcecode_begins_1_string);
    alg_class_method(k_sourcecode, "Add", m_sourcecode_add_2_integer_string, 2, t_sourcecode_add_2_integer_string);
    alg_class_method(k_sourcecode, "Get", m_sourcecode_get_1_integer, 1, t_sourcecode_get_1_integer);
    alg_class_method(k_sourcecode, "Name", m_sourcecode_name_0, 0, NULL);
    alg_class_is_object(k_sourcecode);
}
