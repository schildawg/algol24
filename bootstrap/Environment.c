/* Generated from Algol-24.  Do not edit. */
#include "Environment.h"
#include "Token.h"
#include "TokenType.h"

Value k_environment;
static Value or_0;
static const char *t_environment_markambiguous_2_string_string[] = { "Name : String", "Owners : String" };
static const char *t_environment_raiseambiguousimport_2_string_string[] = { "Name : String", "Display : String" };
static const char *t_environment_isexported_1_string[] = { "Name : String" };
static const char *t_environment_ownerof_2_string_string[] = { "Name : String", "Display : String" };
static const char *t_environment_define_2_string[] = { "Name : String", "Value : Any" };
static const char *t_environment_assign_2_token[] = { "Name : Token", "Value : Any" };
static const char *t_environment_get_1_token[] = { "Name : Token" };
static const char *t_environment_getat_2_integer_string[] = { "Distance : Integer", "Name : String" };
static const char *t_environment_assignat_3_integer_token[] = { "Distance : Integer", "Name : Token", "Value : Any" };
static const char *t_environment_ancestor_1_integer[] = { "Distance : Integer" };

static Value i_environment(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Values", alg_nil());
    alg_set_property(v_this, "Enclosing", alg_nil());
    alg_set_property(v_this, "Imports", alg_nil());
    alg_set_property(v_this, "Exports", alg_nil());
    alg_set_property(v_this, "UnitName", alg_nil());
    alg_set_property(v_this, "Ambiguous", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_environment_init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_set_property(v_this, "Values", alg_map()));
    (void)(alg_set_property(v_this, "Enclosing", alg_widen(alg_nil(), "Environment")));
    (void)(alg_set_property(v_this, "Imports", alg_list()));
    (void)(alg_set_property(v_this, "Exports", alg_widen(alg_nil(), "Set")));
    (void)(alg_set_property(v_this, "UnitName", alg_string("")));
    (void)(alg_set_property(v_this, "Ambiguous", alg_widen(alg_nil(), "Map")));
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

static Value m_environment_markambiguous_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_owners = alg_widen(args[1], "String");
    (void)v_owners;
    alg_root(&v_owners, 1);
    if (alg_truthy(alg_equal(alg_property(v_this, "Ambiguous"), alg_nil()))) {
        (void)(alg_set_property(v_this, "Ambiguous", alg_map()));
    }
    (void)(alg_invoke(alg_property(v_this, "Ambiguous"), "Put", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1), v_owners}, 2));
    (void)(alg_invoke(alg_property(v_this, "Values"), "Remove", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1));
    Value ret_1 = alg_nil();
    alg_root_top = rt_base;
    return ret_1;
}

static Value m_environment_raiseambiguousimport_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_display = alg_widen(args[1], "String");
    (void)v_display;
    alg_root(&v_display, 1);
    Value v_owners = alg_nil();
    (void)v_owners;
    alg_root(&v_owners, 1);
    Value v_seen = alg_nil();
    (void)v_seen;
    alg_root(&v_seen, 1);
    (void)((v_owners = alg_string("")));
    (void)((v_seen = alg_set()));
    {
        int32_t rt_0 = alg_root_top;
        Value loop_2 = alg_iterable(alg_property(v_this, "Imports"));
        (void)loop_2;
        alg_root(&loop_2, 1);
        for (int32_t at_2 = 0; at_2 < alg_iterable_count(loop_2); at_2++) {
            int32_t rt_1 = alg_root_top;
            Value v_import = alg_iterable_at(loop_2, at_2);
            (void)v_import;
            alg_root(&v_import, 1);
            {
                int32_t rt_2 = alg_root_top;
                Value v_themodule = alg_cast(v_import, "Environment");
                (void)v_themodule;
                alg_root(&v_themodule, 1);
                if (alg_truthy(alg_invoke(alg_property(v_themodule, "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
                    if (alg_truthy(alg_invoke(v_themodule, "IsExported", (Value[]){v_name}, 1))) {
                        if (alg_truthy(alg_not(alg_invoke(v_seen, "Contains", (Value[]){alg_property(v_themodule, "UnitName")}, 1)))) {
                            {
                                (void)(alg_invoke(v_seen, "Add", (Value[]){alg_property(v_themodule, "UnitName")}, 1));
                                if (alg_truthy(alg_equal(v_owners, alg_string("")))) {
                                    (void)((v_owners = alg_property(v_themodule, "UnitName")));
                                } else {
                                    (void)((v_owners = alg_add(alg_add(v_owners, alg_string(" or ")), alg_property(v_themodule, "UnitName"))));
                                }
                            }
                        }
                    }
                }
                alg_root_top = rt_2;
            }
            alg_root_top = rt_1;
        }
        alg_root_top = rt_0;
    }
    alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_str(v_display)), alg_string("' is ambiguous: ")), v_owners), alg_char_value(46)));
    Value ret_3 = alg_nil();
    alg_root_top = rt_base;
    return ret_3;
}

static Value m_environment_isexported_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_equal(alg_property(v_this, "Exports"), alg_nil()))) {
        Value ret_4 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_4;
    }
    Value ret_5 = alg_invoke(alg_property(v_this, "Exports"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1);
    alg_root_top = rt_base;
    return ret_5;
    Value ret_6 = alg_nil();
    alg_root_top = rt_base;
    return ret_6;
}

static Value m_environment_ownerof_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_display = alg_widen(args[1], "String");
    (void)v_display;
    alg_root(&v_display, 1);
    Value v_found = alg_nil();
    (void)v_found;
    alg_root(&v_found, 1);
    (void)((v_found = alg_widen(alg_nil(), "Environment")));
    {
        int32_t rt_3 = alg_root_top;
        Value loop_7 = alg_iterable(alg_property(v_this, "Imports"));
        (void)loop_7;
        alg_root(&loop_7, 1);
        for (int32_t at_7 = 0; at_7 < alg_iterable_count(loop_7); at_7++) {
            int32_t rt_4 = alg_root_top;
            Value v_import = alg_iterable_at(loop_7, at_7);
            (void)v_import;
            alg_root(&v_import, 1);
            {
                int32_t rt_5 = alg_root_top;
                Value v_themodule = alg_cast(v_import, "Environment");
                (void)v_themodule;
                alg_root(&v_themodule, 1);
                if (alg_truthy(alg_invoke(alg_property(v_themodule, "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
                    if (alg_truthy(alg_invoke(v_themodule, "IsExported", (Value[]){v_name}, 1))) {
                        {
                            if (alg_truthy((or_0 = alg_not_equal(v_found, alg_nil()), !alg_truthy(or_0) ? or_0 : alg_not_equal(v_themodule, v_found)))) {
                                (void)(alg_invoke(v_this, "RaiseAmbiguousImport", (Value[]){v_name, v_display}, 2));
                            }
                            (void)((v_found = v_themodule));
                        }
                    }
                }
                alg_root_top = rt_5;
            }
            alg_root_top = rt_4;
        }
        alg_root_top = rt_3;
    }
    Value ret_8 = v_found;
    alg_root_top = rt_base;
    return ret_8;
    Value ret_9 = alg_nil();
    alg_root_top = rt_base;
    return ret_9;
}

static Value m_environment_define_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_value = args[1];
    (void)v_value;
    alg_root(&v_value, 1);
    (void)(alg_invoke(alg_property(v_this, "Values"), "Put", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1), v_value}, 2));
    Value ret_10 = alg_nil();
    alg_root_top = rt_base;
    return ret_10;
}

static Value m_environment_assign_2_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_value = args[1];
    (void)v_value;
    alg_root(&v_value, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Values"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_value}, 2));
            Value ret_11 = alg_nil();
            alg_root_top = rt_base;
            return ret_11;
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Ambiguous"), alg_nil()))) {
        if (alg_truthy(alg_invoke(alg_property(v_this, "Ambiguous"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
            alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' is ambiguous: ")), alg_str(alg_invoke(alg_property(v_this, "Ambiguous"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))), alg_char_value(46)));
        }
    }
    Value v_owner = alg_invoke(v_this, "OwnerOf", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), alg_str(alg_property(v_name, "Lexeme"))}, 2);
    (void)v_owner;
    alg_root(&v_owner, 1);
    if (alg_truthy(alg_not_equal(v_owner, alg_nil()))) {
        {
            (void)(alg_invoke(alg_property((alg_cast(v_owner, "Environment")), "Values"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_value}, 2));
            Value ret_12 = alg_nil();
            alg_root_top = rt_base;
            return ret_12;
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Enclosing"), alg_nil()))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Enclosing"), "Assign", (Value[]){v_name, v_value}, 2));
            Value ret_13 = alg_nil();
            alg_root_top = rt_base;
            return ret_13;
        }
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined variable '"), alg_property(v_name, "Lexeme")), alg_string("'.")));
    Value ret_14 = alg_nil();
    alg_root_top = rt_base;
    return ret_14;
}

static Value m_environment_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
        {
            Value ret_15 = alg_invoke(alg_property(v_this, "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1);
            alg_root_top = rt_base;
            return ret_15;
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Ambiguous"), alg_nil()))) {
        if (alg_truthy(alg_invoke(alg_property(v_this, "Ambiguous"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
            alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' is ambiguous: ")), alg_str(alg_invoke(alg_property(v_this, "Ambiguous"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))), alg_char_value(46)));
        }
    }
    Value v_owner = alg_invoke(v_this, "OwnerOf", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), alg_str(alg_property(v_name, "Lexeme"))}, 2);
    (void)v_owner;
    alg_root(&v_owner, 1);
    if (alg_truthy(alg_not_equal(v_owner, alg_nil()))) {
        Value ret_16 = alg_invoke(alg_property((alg_cast(v_owner, "Environment")), "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1);
        alg_root_top = rt_base;
        return ret_16;
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Enclosing"), alg_nil()))) {
        Value ret_17 = alg_invoke(alg_property(v_this, "Enclosing"), "Get", (Value[]){v_name}, 1);
        alg_root_top = rt_base;
        return ret_17;
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined variable '"), alg_property(v_name, "Lexeme")), alg_string("'.")));
    Value ret_18 = alg_nil();
    alg_root_top = rt_base;
    return ret_18;
}

static Value m_environment_getat_2_integer_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_distance = alg_widen(args[0], "Integer");
    (void)v_distance;
    alg_root(&v_distance, 1);
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_19 = alg_invoke(alg_property(alg_invoke(v_this, "Ancestor", (Value[]){v_distance}, 1), "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1);
    alg_root_top = rt_base;
    return ret_19;
    Value ret_20 = alg_nil();
    alg_root_top = rt_base;
    return ret_20;
}

static Value m_environment_assignat_3_integer_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_distance = alg_widen(args[0], "Integer");
    (void)v_distance;
    alg_root(&v_distance, 1);
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_value = args[2];
    (void)v_value;
    alg_root(&v_value, 1);
    (void)(alg_invoke(alg_property(alg_invoke(v_this, "Ancestor", (Value[]){v_distance}, 1), "Values"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_value}, 2));
    Value ret_21 = alg_nil();
    alg_root_top = rt_base;
    return ret_21;
}

static Value m_environment_ancestor_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_distance = alg_widen(args[0], "Integer");
    (void)v_distance;
    alg_root(&v_distance, 1);
    Value v_env = alg_nil();
    (void)v_env;
    alg_root(&v_env, 1);
    (void)((v_env = alg_cast(v_this, "Environment")));
    {
        int32_t rt_6 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, v_distance)); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                (void)((v_env = alg_property(v_env, "Enclosing")));
            }
        }
        alg_root_top = rt_6;
    }
    Value ret_22 = v_env;
    alg_root_top = rt_base;
    return ret_22;
    Value ret_23 = alg_nil();
    alg_root_top = rt_base;
    return ret_23;
}

static Value *roots_Environment[] = {
    &k_environment,
};

void init_Environment(void) {
    alg_roots(roots_Environment, 1);
    k_environment = alg_class("Environment", alg_nil());
    alg_class_field(k_environment, "Values");
    alg_class_field(k_environment, "Enclosing");
    alg_class_field(k_environment, "Imports");
    alg_class_field(k_environment, "Exports");
    alg_class_field(k_environment, "UnitName");
    alg_class_field(k_environment, "Ambiguous");
    alg_class_initializer(k_environment, i_environment);
    alg_class_method(k_environment, "Init", m_environment_init_0, 0, NULL);
    alg_class_method(k_environment, "MarkAmbiguous", m_environment_markambiguous_2_string_string, 2, t_environment_markambiguous_2_string_string);
    alg_class_method(k_environment, "RaiseAmbiguousImport", m_environment_raiseambiguousimport_2_string_string, 2, t_environment_raiseambiguousimport_2_string_string);
    alg_class_method(k_environment, "IsExported", m_environment_isexported_1_string, 1, t_environment_isexported_1_string);
    alg_class_method(k_environment, "OwnerOf", m_environment_ownerof_2_string_string, 2, t_environment_ownerof_2_string_string);
    alg_class_method(k_environment, "Define", m_environment_define_2_string, 2, t_environment_define_2_string);
    alg_class_method(k_environment, "Assign", m_environment_assign_2_token, 2, t_environment_assign_2_token);
    alg_class_method(k_environment, "Get", m_environment_get_1_token, 1, t_environment_get_1_token);
    alg_class_method(k_environment, "GetAt", m_environment_getat_2_integer_string, 2, t_environment_getat_2_integer_string);
    alg_class_method(k_environment, "AssignAt", m_environment_assignat_3_integer_token, 3, t_environment_assignat_3_integer_token);
    alg_class_method(k_environment, "Ancestor", m_environment_ancestor_1_integer, 1, t_environment_ancestor_1_integer);
}
