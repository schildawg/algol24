/* Generated from Algol-24.  Do not edit. */
#include "SourceCode.h"

Value k_sourcecode;
static const char *t_sourcecode_begins_1_string[] = { "Name : String" };
static const char *t_sourcecode_add_3_string_integer_string[] = { "File : String", "LineNumber : Integer", "Text : String" };
static const char *t_sourcecode_get_2_string_integer[] = { "File : String", "LineNumber : Integer" };
static const char *t_sourcecode_keyed_1_string[] = { "File : String" };
static const char *t_sourcecode_named_1_string[] = { "File : String" };

static Value i_sourcecode(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Files", alg_widen(alg_map(), "Map"));
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
    (void)(alg_set_property(v_this, "Files", alg_map()));
    (void)(alg_set_property(v_this, "FileName", v_name));
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

static Value m_sourcecode_add_3_string_integer_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_file = alg_widen(args[0], "String");
    (void)v_file;
    alg_root(&v_file, 1);
    Value v_linenumber = alg_widen(args[1], "Integer");
    (void)v_linenumber;
    alg_root(&v_linenumber, 1);
    Value v_text = alg_widen(args[2], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_lines = alg_nil();
    (void)v_lines;
    alg_root(&v_lines, 1);
    if (alg_truthy(alg_less(v_linenumber, alg_int(1)))) {
        Value ret_1 = alg_nil();
        alg_root_top = rt_base;
        return ret_1;
    }
    (void)((v_name = alg_invoke(v_this, "Keyed", (Value[]){v_file}, 1)));
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Files"), "Contains", (Value[]){v_name}, 1)))) {
        (void)(alg_invoke(alg_property(v_this, "Files"), "Put", (Value[]){v_name, alg_list()}, 2));
    }
    (void)((v_lines = alg_cast(alg_invoke(alg_property(v_this, "Files"), "Get", (Value[]){v_name}, 1), "List")));
    while (alg_truthy(alg_less(alg_property(v_lines, "Length"), alg_subtract(v_linenumber, alg_int(1))))) {
        (void)(alg_invoke(v_lines, "Add", (Value[]){alg_string("")}, 1));
    }
    if (alg_truthy(alg_equal(alg_property(v_lines, "Length"), alg_subtract(v_linenumber, alg_int(1))))) {
        (void)(alg_invoke(v_lines, "Add", (Value[]){v_text}, 1));
    } else {
        (void)(alg_subscript_set(v_lines, alg_subtract(v_linenumber, alg_int(1)), v_text));
    }
    Value ret_2 = alg_nil();
    alg_root_top = rt_base;
    return ret_2;
}

static Value m_sourcecode_get_2_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_file = alg_widen(args[0], "String");
    (void)v_file;
    alg_root(&v_file, 1);
    Value v_linenumber = alg_widen(args[1], "Integer");
    (void)v_linenumber;
    alg_root(&v_linenumber, 1);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_lines = alg_nil();
    (void)v_lines;
    alg_root(&v_lines, 1);
    if (alg_truthy(alg_less(v_linenumber, alg_int(1)))) {
        Value ret_3 = alg_string("");
        alg_root_top = rt_base;
        return ret_3;
    }
    (void)((v_name = alg_invoke(v_this, "Keyed", (Value[]){v_file}, 1)));
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Files"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_4 = alg_string("");
        alg_root_top = rt_base;
        return ret_4;
    }
    (void)((v_lines = alg_cast(alg_invoke(alg_property(v_this, "Files"), "Get", (Value[]){v_name}, 1), "List")));
    if (alg_truthy(alg_greater(v_linenumber, alg_property(v_lines, "Length")))) {
        Value ret_5 = alg_string("");
        alg_root_top = rt_base;
        return ret_5;
    }
    Value ret_6 = alg_str(alg_subscript_get(v_lines, alg_subtract(v_linenumber, alg_int(1))));
    alg_root_top = rt_base;
    return ret_6;
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
}

static Value m_sourcecode_keyed_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_file = alg_widen(args[0], "String");
    (void)v_file;
    alg_root(&v_file, 1);
    if (alg_truthy(alg_equal(v_file, alg_string("")))) {
        Value ret_8 = alg_property(v_this, "FileName");
        alg_root_top = rt_base;
        return ret_8;
    }
    Value ret_9 = alg_str(v_file);
    alg_root_top = rt_base;
    return ret_9;
    Value ret_10 = alg_nil();
    alg_root_top = rt_base;
    return ret_10;
}

static Value m_sourcecode_name_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_11 = alg_property(v_this, "FileName");
    alg_root_top = rt_base;
    return ret_11;
    Value ret_12 = alg_nil();
    alg_root_top = rt_base;
    return ret_12;
}

static Value m_sourcecode_named_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_file = alg_widen(args[0], "String");
    (void)v_file;
    alg_root(&v_file, 1);
    Value ret_13 = alg_invoke(v_this, "Keyed", (Value[]){v_file}, 1);
    alg_root_top = rt_base;
    return ret_13;
    Value ret_14 = alg_nil();
    alg_root_top = rt_base;
    return ret_14;
}

static Value *roots_SourceCode[] = {
    &k_sourcecode,
};

void init_SourceCode(void) {
    alg_roots(roots_SourceCode, 1);
    k_sourcecode = alg_class("SourceCode", alg_nil());
    alg_class_field(k_sourcecode, "Files");
    alg_class_field(k_sourcecode, "FileName");
    alg_class_field(k_sourcecode, "Id");
    alg_class_initializer(k_sourcecode, i_sourcecode);
    alg_class_method(k_sourcecode, "Begins", m_sourcecode_begins_1_string, 1, t_sourcecode_begins_1_string);
    alg_class_method(k_sourcecode, "Add", m_sourcecode_add_3_string_integer_string, 3, t_sourcecode_add_3_string_integer_string);
    alg_class_method(k_sourcecode, "Get", m_sourcecode_get_2_string_integer, 2, t_sourcecode_get_2_string_integer);
    alg_class_method(k_sourcecode, "Keyed", m_sourcecode_keyed_1_string, 1, t_sourcecode_keyed_1_string);
    alg_class_method(k_sourcecode, "Name", m_sourcecode_name_0, 0, NULL);
    alg_class_method(k_sourcecode, "Named", m_sourcecode_named_1_string, 1, t_sourcecode_named_1_string);
    alg_class_is_object(k_sourcecode);
}
