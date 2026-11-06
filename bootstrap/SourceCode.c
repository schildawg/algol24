/* Generated from Algol-24.  Do not edit. */
#include "SourceCode.h"

Value k_sourcecode;
static const char *t_sourcecode_begins_1_string[] = { "Name : String" };
static const char *t_sourcecode_add_2_integer_string[] = { "LineNumber : Integer", "Text : String" };
static const char *t_sourcecode_get_1_integer[] = { "LineNumber : Integer" };

static Value i_sourcecode(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Lines", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "FileName", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "Id", alg_string("SourceCode"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_sourcecode_begins_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    (void)(alg_set_property(v_this, "Lines", alg_list()));
    (void)(alg_set_property(v_this, "FileName", v_name));
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

static Value m_sourcecode_add_2_integer_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_linenumber = alg_widen(args[0], "Integer");
    (void)v_linenumber;
    alg_root(&v_linenumber, 1);
    Value v_text = alg_widen(args[1], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    if (alg_truthy(alg_less(v_linenumber, alg_int(1)))) {
        Value ret_1 = alg_nil();
        alg_root_top = rt_base;
        return ret_1;
    }
    while (alg_truthy(alg_less(alg_property(alg_property(v_this, "Lines"), "Length"), alg_subtract(v_linenumber, alg_int(1))))) {
        (void)(alg_invoke(alg_property(v_this, "Lines"), "Add", (Value[]){alg_string("")}, 1));
    }
    if (alg_truthy(alg_equal(alg_property(alg_property(v_this, "Lines"), "Length"), alg_subtract(v_linenumber, alg_int(1))))) {
        (void)(alg_invoke(alg_property(v_this, "Lines"), "Add", (Value[]){v_text}, 1));
    } else {
        (void)(alg_subscript_set(alg_property(v_this, "Lines"), alg_subtract(v_linenumber, alg_int(1)), v_text));
    }
    Value ret_2 = alg_nil();
    alg_root_top = rt_base;
    return ret_2;
}

static Value m_sourcecode_get_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_linenumber = alg_widen(args[0], "Integer");
    (void)v_linenumber;
    alg_root(&v_linenumber, 1);
    if (alg_truthy(alg_less(v_linenumber, alg_int(1)))) {
        Value ret_3 = alg_string("");
        alg_root_top = rt_base;
        return ret_3;
    }
    if (alg_truthy(alg_greater(v_linenumber, alg_property(alg_property(v_this, "Lines"), "Length")))) {
        Value ret_4 = alg_string("");
        alg_root_top = rt_base;
        return ret_4;
    }
    Value ret_5 = alg_str(alg_subscript_get(alg_property(v_this, "Lines"), alg_subtract(v_linenumber, alg_int(1))));
    alg_root_top = rt_base;
    return ret_5;
    Value ret_6 = alg_nil();
    alg_root_top = rt_base;
    return ret_6;
}

static Value m_sourcecode_name_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_7 = alg_property(v_this, "FileName");
    alg_root_top = rt_base;
    return ret_7;
    Value ret_8 = alg_nil();
    alg_root_top = rt_base;
    return ret_8;
}

static Value *roots_SourceCode[] = {
    &k_sourcecode,
};

void init_SourceCode(void) {
    alg_roots(roots_SourceCode, 1);
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
