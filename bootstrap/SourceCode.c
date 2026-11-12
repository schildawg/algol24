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
    alg_set_property(v_this, "Files", alg_widen(alg_hold(alg_map()), "Map"));
    alg_set_property(v_this, "FileName", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "Id", alg_literal("SourceCode"));
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
    int32_t rh_117 = alg_hold_top;
    (void)(alg_set_property(v_this, "Files", alg_hold(alg_map())));
    alg_hold_top = rh_117;
    (void)(alg_set_property(v_this, "FileName", v_name));
    alg_hold_top = rh_117;
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
    int32_t rh_118 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_118;
    Value v_lines = alg_nil();
    (void)v_lines;
    alg_root(&v_lines, 1);
    alg_hold_top = rh_118;
    if (alg_truthy(alg_hold(alg_less(v_linenumber, alg_int(1))))) {
        Value ret_1 = alg_nil();
        alg_root_top = rt_base;
        return ret_1;
    }
    alg_hold_top = rh_118;
    (void)((v_name = alg_hold(alg_invoke(v_this, "Keyed", (Value[]){v_file}, 1))));
    alg_hold_top = rh_118;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Files"), "Contains", (Value[]){v_name}, 1)))))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Files"), "Put", (Value[]){v_name, alg_hold(alg_list())}, 2)));
    }
    alg_hold_top = rh_118;
    (void)((v_lines = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "Files"), "Get", (Value[]){v_name}, 1), ALG_KIND_LIST, "List"))));
    alg_hold_top = rh_118;
    {
        int32_t rh_119 = alg_hold_top;
        while ((alg_hold_top = rh_119, alg_truthy(alg_hold(alg_less(alg_hold(alg_property(v_lines, "Length")), alg_hold(alg_subtract(v_linenumber, alg_int(1)))))))) {
            alg_safe_point();
            (void)(alg_hold(alg_invoke(v_lines, "Add", (Value[]){alg_literal("")}, 1)));
        }
    }
    alg_hold_top = rh_118;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_lines, "Length")), alg_hold(alg_subtract(v_linenumber, alg_int(1))))))) {
        (void)(alg_hold(alg_invoke(v_lines, "Add", (Value[]){v_text}, 1)));
    } else {
        (void)(alg_hold(alg_subscript_set(v_lines, alg_hold(alg_subtract(v_linenumber, alg_int(1))), v_text)));
    }
    alg_hold_top = rh_118;
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
    int32_t rh_120 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_120;
    Value v_lines = alg_nil();
    (void)v_lines;
    alg_root(&v_lines, 1);
    alg_hold_top = rh_120;
    if (alg_truthy(alg_hold(alg_less(v_linenumber, alg_int(1))))) {
        Value ret_3 = alg_literal("");
        alg_root_top = rt_base;
        return ret_3;
    }
    alg_hold_top = rh_120;
    (void)((v_name = alg_hold(alg_invoke(v_this, "Keyed", (Value[]){v_file}, 1))));
    alg_hold_top = rh_120;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Files"), "Contains", (Value[]){v_name}, 1)))))) {
        Value ret_4 = alg_literal("");
        alg_root_top = rt_base;
        return ret_4;
    }
    alg_hold_top = rh_120;
    (void)((v_lines = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "Files"), "Get", (Value[]){v_name}, 1), ALG_KIND_LIST, "List"))));
    alg_hold_top = rh_120;
    if (alg_truthy(alg_hold(alg_greater(v_linenumber, alg_hold(alg_property(v_lines, "Length")))))) {
        Value ret_5 = alg_literal("");
        alg_root_top = rt_base;
        return ret_5;
    }
    alg_hold_top = rh_120;
    Value ret_6 = alg_hold(alg_str(alg_hold(alg_subscript_get(v_lines, alg_hold(alg_subtract(v_linenumber, alg_int(1)))))));
    alg_root_top = rt_base;
    return ret_6;
    alg_hold_top = rh_120;
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
    int32_t rh_121 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(v_file, alg_literal(""))))) {
        Value ret_8 = alg_property(v_this, "FileName");
        alg_root_top = rt_base;
        return ret_8;
    }
    alg_hold_top = rh_121;
    Value ret_9 = alg_hold(alg_str(v_file));
    alg_root_top = rt_base;
    return ret_9;
    alg_hold_top = rh_121;
    Value ret_10 = alg_nil();
    alg_root_top = rt_base;
    return ret_10;
}

static Value m_sourcecode_name_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_122 = alg_hold_top;
    Value ret_11 = alg_property(v_this, "FileName");
    alg_root_top = rt_base;
    return ret_11;
    alg_hold_top = rh_122;
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
    int32_t rh_123 = alg_hold_top;
    Value ret_13 = alg_hold(alg_invoke(v_this, "Keyed", (Value[]){v_file}, 1));
    alg_root_top = rt_base;
    return ret_13;
    alg_hold_top = rh_123;
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
    alg_class_field(k_sourcecode, "Files", "Map");
    alg_class_field(k_sourcecode, "FileName", "String");
    alg_class_field(k_sourcecode, "Id", "String");
    alg_class_initializer(k_sourcecode, i_sourcecode);
    alg_class_method(k_sourcecode, "Begins", m_sourcecode_begins_1_string, 1, t_sourcecode_begins_1_string);
    alg_class_method(k_sourcecode, "Add", m_sourcecode_add_3_string_integer_string, 3, t_sourcecode_add_3_string_integer_string);
    alg_class_method(k_sourcecode, "Get", m_sourcecode_get_2_string_integer, 2, t_sourcecode_get_2_string_integer);
    alg_class_method(k_sourcecode, "Keyed", m_sourcecode_keyed_1_string, 1, t_sourcecode_keyed_1_string);
    alg_class_method(k_sourcecode, "Name", m_sourcecode_name_0, 0, NULL);
    alg_class_method(k_sourcecode, "Named", m_sourcecode_named_1_string, 1, t_sourcecode_named_1_string);
    alg_class_is_object(k_sourcecode);
    int32_t rh_116 = alg_hold_top;
    alg_hold_top = rh_116;
}
