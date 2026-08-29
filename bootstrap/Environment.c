/* Generated from Algol-24.  Do not edit. */
#include "Environment.h"
#include "Token.h"
#include "TokenType.h"

Value k_Environment;
static Value or_0;
static const char *t_Environment_MarkAmbiguous_2_String_String[] = { "String", "String" };
static const char *t_Environment_RaiseAmbiguousImport_2_String_String[] = { "String", "String" };
static const char *t_Environment_IsExported_1_String[] = { "String" };
static const char *t_Environment_OwnerOf_2_String_String[] = { "String", "String" };
static const char *t_Environment_Define_2_String[] = { "String", "Any" };
static const char *t_Environment_Assign_2_Token[] = { "Token", "Any" };
static const char *t_Environment_Get_1_Token[] = { "Token" };
static const char *t_Environment_GetAt_2_Integer_String[] = { "Integer", "String" };
static const char *t_Environment_AssignAt_3_Integer_Token[] = { "Integer", "Token", "Any" };
static const char *t_Environment_Ancestor_1_Integer[] = { "Integer" };

static Value i_Environment(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Values", alg_nil());
    alg_set_property(v_this, "Enclosing", alg_nil());
    alg_set_property(v_this, "Imports", alg_nil());
    alg_set_property(v_this, "Exports", alg_nil());
    alg_set_property(v_this, "UnitName", alg_nil());
    alg_set_property(v_this, "Ambiguous", alg_nil());
    return alg_nil();
}

static Value m_Environment_Init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_set_property(v_this, "Values", alg_map()));
    (void)(alg_set_property(v_this, "Enclosing", alg_nil()));
    (void)(alg_set_property(v_this, "Imports", alg_list()));
    (void)(alg_set_property(v_this, "Exports", alg_nil()));
    (void)(alg_set_property(v_this, "UnitName", alg_string("")));
    (void)(alg_set_property(v_this, "Ambiguous", alg_nil()));
    return alg_nil();
}

static Value m_Environment_MarkAmbiguous_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Owners = args[1];
    (void)v_Owners;
    if (alg_truthy(alg_equal(alg_property(v_this, "Ambiguous"), alg_nil()))) {
        (void)(alg_set_property(v_this, "Ambiguous", alg_map()));
    }
    (void)(alg_invoke(alg_property(v_this, "Ambiguous"), "Put", (Value[]){f_FoldCase(NULL, (Value[]){v_Name}, 1), v_Owners}, 2));
    (void)(alg_invoke(alg_property(v_this, "Values"), "Remove", (Value[]){f_FoldCase(NULL, (Value[]){v_Name}, 1)}, 1));
    return alg_nil();
}

static Value m_Environment_RaiseAmbiguousImport_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Display = args[1];
    (void)v_Display;
    Value v_Owners = alg_nil();
    (void)v_Owners;
    Value v_Seen = alg_nil();
    (void)v_Seen;
    (void)((v_Owners = alg_string("")));
    (void)((v_Seen = alg_set()));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_this, "Imports"), "Length")))) {
            {
                {
                    Value v_TheModule = alg_subscript_get(alg_property(v_this, "Imports"), v_I);
                    (void)v_TheModule;
                    if (alg_truthy(alg_invoke(alg_property(v_TheModule, "Values"), "Contains", (Value[]){f_FoldCase(NULL, (Value[]){v_Name}, 1)}, 1))) {
                        if (alg_truthy(alg_invoke(v_TheModule, "IsExported", (Value[]){v_Name}, 1))) {
                            if (alg_truthy(alg_not(alg_invoke(v_Seen, "Contains", (Value[]){alg_property(v_TheModule, "UnitName")}, 1)))) {
                                {
                                    (void)(alg_invoke(v_Seen, "Add", (Value[]){alg_property(v_TheModule, "UnitName")}, 1));
                                    if (alg_truthy(alg_equal(v_Owners, alg_string("")))) {
                                        (void)((v_Owners = alg_property(v_TheModule, "UnitName")));
                                    } else {
                                        (void)((v_Owners = alg_add(alg_add(v_Owners, alg_string(" or ")), alg_property(v_TheModule, "UnitName"))));
                                    }
                                }
                            }
                        }
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_str(v_Display)), alg_string("' is ambiguous: ")), v_Owners), alg_char_value(46)));
    return alg_nil();
}

static Value m_Environment_IsExported_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    if (alg_truthy(alg_equal(alg_property(v_this, "Exports"), alg_nil()))) {
        return alg_bool(true);
    }
    return alg_invoke(alg_property(v_this, "Exports"), "Contains", (Value[]){f_FoldCase(NULL, (Value[]){v_Name}, 1)}, 1);
    return alg_nil();
}

static Value m_Environment_OwnerOf_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Display = args[1];
    (void)v_Display;
    Value v_Found = alg_nil();
    (void)v_Found;
    (void)((v_Found = alg_nil()));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_this, "Imports"), "Length")))) {
            {
                {
                    Value v_TheModule = alg_subscript_get(alg_property(v_this, "Imports"), v_I);
                    (void)v_TheModule;
                    if (alg_truthy(alg_invoke(alg_property(v_TheModule, "Values"), "Contains", (Value[]){f_FoldCase(NULL, (Value[]){v_Name}, 1)}, 1))) {
                        if (alg_truthy(alg_invoke(v_TheModule, "IsExported", (Value[]){v_Name}, 1))) {
                            {
                                if (alg_truthy((or_0 = alg_not_equal(v_Found, alg_nil()), !alg_truthy(or_0) ? or_0 : alg_not_equal(v_TheModule, v_Found)))) {
                                    (void)(alg_invoke(v_this, "RaiseAmbiguousImport", (Value[]){v_Name, v_Display}, 2));
                                }
                                (void)((v_Found = v_TheModule));
                            }
                        }
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Found;
    return alg_nil();
}

static Value m_Environment_Define_2_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Value = args[1];
    (void)v_Value;
    (void)(alg_invoke(alg_property(v_this, "Values"), "Put", (Value[]){f_FoldCase(NULL, (Value[]){v_Name}, 1), v_Value}, 2));
    return alg_nil();
}

static Value m_Environment_Assign_2_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Value = args[1];
    (void)v_Value;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Values"), "Contains", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1)}, 1))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Values"), "Put", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1), v_Value}, 2));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Ambiguous"), alg_nil()))) {
        if (alg_truthy(alg_invoke(alg_property(v_this, "Ambiguous"), "Contains", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1)}, 1))) {
            alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(v_Name, "Lexeme"))), alg_string("' is ambiguous: ")), alg_str(alg_invoke(alg_property(v_this, "Ambiguous"), "Get", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1)}, 1))), alg_char_value(46)));
        }
    }
    Value v_Owner = alg_invoke(v_this, "OwnerOf", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1), alg_str(alg_property(v_Name, "Lexeme"))}, 2);
    (void)v_Owner;
    if (alg_truthy(alg_not_equal(v_Owner, alg_nil()))) {
        {
            (void)(alg_invoke(alg_property((v_Owner), "Values"), "Put", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1), v_Value}, 2));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Enclosing"), alg_nil()))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Enclosing"), "Assign", (Value[]){v_Name, v_Value}, 2));
            return alg_nil();
        }
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined variable '"), alg_property(v_Name, "Lexeme")), alg_string("'.")));
    return alg_nil();
}

static Value m_Environment_Get_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Values"), "Contains", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1)}, 1))) {
        {
            return alg_invoke(alg_property(v_this, "Values"), "Get", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1)}, 1);
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Ambiguous"), alg_nil()))) {
        if (alg_truthy(alg_invoke(alg_property(v_this, "Ambiguous"), "Contains", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1)}, 1))) {
            alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(v_Name, "Lexeme"))), alg_string("' is ambiguous: ")), alg_str(alg_invoke(alg_property(v_this, "Ambiguous"), "Get", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1)}, 1))), alg_char_value(46)));
        }
    }
    Value v_Owner = alg_invoke(v_this, "OwnerOf", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1), alg_str(alg_property(v_Name, "Lexeme"))}, 2);
    (void)v_Owner;
    if (alg_truthy(alg_not_equal(v_Owner, alg_nil()))) {
        return alg_invoke(alg_property((v_Owner), "Values"), "Get", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1)}, 1);
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Enclosing"), alg_nil()))) {
        return alg_invoke(alg_property(v_this, "Enclosing"), "Get", (Value[]){v_Name}, 1);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined variable '"), alg_property(v_Name, "Lexeme")), alg_string("'.")));
    return alg_nil();
}

static Value m_Environment_GetAt_2_Integer_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Distance = args[0];
    (void)v_Distance;
    Value v_Name = args[1];
    (void)v_Name;
    return alg_invoke(alg_property(alg_invoke(v_this, "Ancestor", (Value[]){v_Distance}, 1), "Values"), "Get", (Value[]){f_FoldCase(NULL, (Value[]){v_Name}, 1)}, 1);
    return alg_nil();
}

static Value m_Environment_AssignAt_3_Integer_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Distance = args[0];
    (void)v_Distance;
    Value v_Name = args[1];
    (void)v_Name;
    Value v_Value = args[2];
    (void)v_Value;
    (void)(alg_invoke(alg_property(alg_invoke(v_this, "Ancestor", (Value[]){v_Distance}, 1), "Values"), "Put", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(v_Name, "Lexeme")}, 1), v_Value}, 2));
    return alg_nil();
}

static Value m_Environment_Ancestor_1_Integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Distance = args[0];
    (void)v_Distance;
    Value v_Env = alg_nil();
    (void)v_Env;
    (void)((v_Env = v_this));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, v_Distance))) {
            {
                {
                    (void)((v_Env = alg_property(v_Env, "Enclosing")));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Env;
    return alg_nil();
}

void init_Environment(void) {
    k_Environment = alg_class("Environment", alg_nil());
    alg_class_field(k_Environment, "Values");
    alg_class_field(k_Environment, "Enclosing");
    alg_class_field(k_Environment, "Imports");
    alg_class_field(k_Environment, "Exports");
    alg_class_field(k_Environment, "UnitName");
    alg_class_field(k_Environment, "Ambiguous");
    alg_class_initializer(k_Environment, i_Environment);
    alg_class_method(k_Environment, "Init", m_Environment_Init_0, 0, NULL);
    alg_class_method(k_Environment, "MarkAmbiguous", m_Environment_MarkAmbiguous_2_String_String, 2, t_Environment_MarkAmbiguous_2_String_String);
    alg_class_method(k_Environment, "RaiseAmbiguousImport", m_Environment_RaiseAmbiguousImport_2_String_String, 2, t_Environment_RaiseAmbiguousImport_2_String_String);
    alg_class_method(k_Environment, "IsExported", m_Environment_IsExported_1_String, 1, t_Environment_IsExported_1_String);
    alg_class_method(k_Environment, "OwnerOf", m_Environment_OwnerOf_2_String_String, 2, t_Environment_OwnerOf_2_String_String);
    alg_class_method(k_Environment, "Define", m_Environment_Define_2_String, 2, t_Environment_Define_2_String);
    alg_class_method(k_Environment, "Assign", m_Environment_Assign_2_Token, 2, t_Environment_Assign_2_Token);
    alg_class_method(k_Environment, "Get", m_Environment_Get_1_Token, 1, t_Environment_Get_1_Token);
    alg_class_method(k_Environment, "GetAt", m_Environment_GetAt_2_Integer_String, 2, t_Environment_GetAt_2_Integer_String);
    alg_class_method(k_Environment, "AssignAt", m_Environment_AssignAt_3_Integer_Token, 3, t_Environment_AssignAt_3_Integer_Token);
    alg_class_method(k_Environment, "Ancestor", m_Environment_Ancestor_1_Integer, 1, t_Environment_Ancestor_1_Integer);
}
