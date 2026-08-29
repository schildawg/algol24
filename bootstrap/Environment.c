/* Generated from Algol-24.  Do not edit. */
#include "Environment.h"
#include "Token.h"
#include "TokenType.h"

Value k_environment;
static Value or_0;
static const char *t_environment_markambiguous_2_string_string[] = { "String", "String" };
static const char *t_environment_raiseambiguousimport_2_string_string[] = { "String", "String" };
static const char *t_environment_isexported_1_string[] = { "String" };
static const char *t_environment_ownerof_2_string_string[] = { "String", "String" };
static const char *t_environment_define_2_string[] = { "String", "Any" };
static const char *t_environment_assign_2_token[] = { "Token", "Any" };
static const char *t_environment_get_1_token[] = { "Token" };
static const char *t_environment_getat_2_integer_string[] = { "Integer", "String" };
static const char *t_environment_assignat_3_integer_token[] = { "Integer", "Token", "Any" };
static const char *t_environment_ancestor_1_integer[] = { "Integer" };

static Value i_environment(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Values", alg_nil());
    alg_set_property(v_this, "Enclosing", alg_nil());
    alg_set_property(v_this, "Imports", alg_nil());
    alg_set_property(v_this, "Exports", alg_nil());
    alg_set_property(v_this, "UnitName", alg_nil());
    alg_set_property(v_this, "Ambiguous", alg_nil());
    return alg_nil();
}

static Value m_environment_init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_set_property(v_this, "Values", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "Enclosing", alg_widen(alg_nil(), "Environment")));
    (void)(alg_set_property(v_this, "Imports", alg_widen(alg_list(), "List")));
    (void)(alg_set_property(v_this, "Exports", alg_widen(alg_nil(), "Set")));
    (void)(alg_set_property(v_this, "UnitName", alg_widen(alg_string(""), "String")));
    (void)(alg_set_property(v_this, "Ambiguous", alg_widen(alg_nil(), "Map")));
    return alg_nil();
}

static Value m_environment_markambiguous_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_owners = alg_widen(args[1], "String");
    (void)v_owners;
    if (alg_truthy(alg_equal(alg_property(v_this, "Ambiguous"), alg_nil()))) {
        (void)(alg_set_property(v_this, "Ambiguous", alg_widen(alg_map(), "Map")));
    }
    (void)(alg_invoke(alg_property(v_this, "Ambiguous"), "Put", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1), v_owners}, 2));
    (void)(alg_invoke(alg_property(v_this, "Values"), "Remove", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1));
    return alg_nil();
}

static Value m_environment_raiseambiguousimport_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_display = alg_widen(args[1], "String");
    (void)v_display;
    Value v_owners = alg_nil();
    (void)v_owners;
    Value v_seen = alg_nil();
    (void)v_seen;
    (void)((v_owners = alg_widen(alg_string(""), "String")));
    (void)((v_seen = alg_widen(alg_set(), "Set")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_this, "Imports"), "Length")))) {
            {
                {
                    Value v_themodule = alg_subscript_get(alg_property(v_this, "Imports"), v_i);
                    (void)v_themodule;
                    if (alg_truthy(alg_invoke(alg_property(v_themodule, "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
                        if (alg_truthy(alg_invoke(v_themodule, "IsExported", (Value[]){v_name}, 1))) {
                            if (alg_truthy(alg_not(alg_invoke(v_seen, "Contains", (Value[]){alg_property(v_themodule, "UnitName")}, 1)))) {
                                {
                                    (void)(alg_invoke(v_seen, "Add", (Value[]){alg_property(v_themodule, "UnitName")}, 1));
                                    if (alg_truthy(alg_equal(v_owners, alg_string("")))) {
                                        (void)((v_owners = alg_widen(alg_property(v_themodule, "UnitName"), "String")));
                                    } else {
                                        (void)((v_owners = alg_widen(alg_add(alg_add(v_owners, alg_string(" or ")), alg_property(v_themodule, "UnitName")), "String")));
                                    }
                                }
                            }
                        }
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_str(v_display)), alg_string("' is ambiguous: ")), v_owners), alg_char_value(46)));
    return alg_nil();
}

static Value m_environment_isexported_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    if (alg_truthy(alg_equal(alg_property(v_this, "Exports"), alg_nil()))) {
        return alg_bool(true);
    }
    return alg_invoke(alg_property(v_this, "Exports"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1);
    return alg_nil();
}

static Value m_environment_ownerof_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_display = alg_widen(args[1], "String");
    (void)v_display;
    Value v_found = alg_nil();
    (void)v_found;
    (void)((v_found = alg_widen(alg_nil(), "Environment")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_this, "Imports"), "Length")))) {
            {
                {
                    Value v_themodule = alg_subscript_get(alg_property(v_this, "Imports"), v_i);
                    (void)v_themodule;
                    if (alg_truthy(alg_invoke(alg_property(v_themodule, "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
                        if (alg_truthy(alg_invoke(v_themodule, "IsExported", (Value[]){v_name}, 1))) {
                            {
                                if (alg_truthy((or_0 = alg_not_equal(v_found, alg_nil()), !alg_truthy(or_0) ? or_0 : alg_not_equal(v_themodule, v_found)))) {
                                    (void)(alg_invoke(v_this, "RaiseAmbiguousImport", (Value[]){v_name, v_display}, 2));
                                }
                                (void)((v_found = alg_widen(v_themodule, "Environment")));
                            }
                        }
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return v_found;
    return alg_nil();
}

static Value m_environment_define_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_value = args[1];
    (void)v_value;
    (void)(alg_invoke(alg_property(v_this, "Values"), "Put", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1), v_value}, 2));
    return alg_nil();
}

static Value m_environment_assign_2_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_value = args[1];
    (void)v_value;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Values"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_value}, 2));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Ambiguous"), alg_nil()))) {
        if (alg_truthy(alg_invoke(alg_property(v_this, "Ambiguous"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
            alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' is ambiguous: ")), alg_str(alg_invoke(alg_property(v_this, "Ambiguous"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))), alg_char_value(46)));
        }
    }
    Value v_owner = alg_invoke(v_this, "OwnerOf", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), alg_str(alg_property(v_name, "Lexeme"))}, 2);
    (void)v_owner;
    if (alg_truthy(alg_not_equal(v_owner, alg_nil()))) {
        {
            (void)(alg_invoke(alg_property((v_owner), "Values"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_value}, 2));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Enclosing"), alg_nil()))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Enclosing"), "Assign", (Value[]){v_name, v_value}, 2));
            return alg_nil();
        }
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined variable '"), alg_property(v_name, "Lexeme")), alg_string("'.")));
    return alg_nil();
}

static Value m_environment_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Values"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
        {
            return alg_invoke(alg_property(v_this, "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1);
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Ambiguous"), alg_nil()))) {
        if (alg_truthy(alg_invoke(alg_property(v_this, "Ambiguous"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
            alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' is ambiguous: ")), alg_str(alg_invoke(alg_property(v_this, "Ambiguous"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))), alg_char_value(46)));
        }
    }
    Value v_owner = alg_invoke(v_this, "OwnerOf", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), alg_str(alg_property(v_name, "Lexeme"))}, 2);
    (void)v_owner;
    if (alg_truthy(alg_not_equal(v_owner, alg_nil()))) {
        return alg_invoke(alg_property((v_owner), "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1);
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Enclosing"), alg_nil()))) {
        return alg_invoke(alg_property(v_this, "Enclosing"), "Get", (Value[]){v_name}, 1);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined variable '"), alg_property(v_name, "Lexeme")), alg_string("'.")));
    return alg_nil();
}

static Value m_environment_getat_2_integer_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_distance = alg_widen(args[0], "Integer");
    (void)v_distance;
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    return alg_invoke(alg_property(alg_invoke(v_this, "Ancestor", (Value[]){v_distance}, 1), "Values"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1);
    return alg_nil();
}

static Value m_environment_assignat_3_integer_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_distance = alg_widen(args[0], "Integer");
    (void)v_distance;
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    Value v_value = args[2];
    (void)v_value;
    (void)(alg_invoke(alg_property(alg_invoke(v_this, "Ancestor", (Value[]){v_distance}, 1), "Values"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_value}, 2));
    return alg_nil();
}

static Value m_environment_ancestor_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_distance = alg_widen(args[0], "Integer");
    (void)v_distance;
    Value v_env = alg_nil();
    (void)v_env;
    (void)((v_env = alg_widen(v_this, "Environment")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, v_distance))) {
            {
                {
                    (void)((v_env = alg_widen(alg_property(v_env, "Enclosing"), "Environment")));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return v_env;
    return alg_nil();
}

void init_Environment(void) {
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
