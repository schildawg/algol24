/* Generated from Algol-24.  Do not edit. */
#include "ObjClass.h"
#include "Token.h"
#include "ObjFunction.h"
#include "ObjInstance.h"

Value k_ObjClass;
static const char *t_ObjClass_Init_4_String_ObjClass_Map_List[] = { "String", "ObjClass", "Map", "List" };
static const char *t_ObjClass_FindMethod_1_String[] = { "String" };
static const char *t_ObjClass_FindOverload_2_String_List[] = { "String", "List" };
static const char *t_ObjClass_Fitting_3_String_List_Boolean[] = { "String", "List", "Boolean" };
static const char *t_ObjClass_SeedFields_2_ObjInstance[] = { "ObjInstance", "Any" };
static const char *t_ObjClass_Call_2[] = { "Any", "Any" };

static Value i_ObjClass(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Methods", alg_nil());
    alg_set_property(v_this, "Superclass", alg_nil());
    alg_set_property(v_this, "Fields", alg_nil());
    return alg_nil();
}

static Value m_ObjClass_Init_4_String_ObjClass_Map_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Superclass = args[1];
    (void)v_Superclass;
    Value v_Methods = args[2];
    (void)v_Methods;
    Value v_Fields = args[3];
    (void)v_Fields;
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Methods", v_Methods));
    (void)(alg_set_property(v_this, "Superclass", v_Superclass));
    (void)(alg_set_property(v_this, "Fields", v_Fields));
    return alg_nil();
}

static Value m_ObjClass_FindMethod_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_Name}, 1))) {
        {
            Value v_Found = alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_Name}, 1);
            (void)v_Found;
            if (alg_truthy(alg_greater(alg_property(v_Found, "Length"), alg_int(0)))) {
                return alg_subscript_get(v_Found, alg_int(0));
            }
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        {
            return alg_invoke(alg_property(v_this, "Superclass"), "FindMethod", (Value[]){v_Name}, 1);
        }
    }
    return alg_nil();
}

static Value m_ObjClass_FindOverload_2_String_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    if (alg_truthy(alg_not_equal(alg_invoke(v_this, "Fitting", (Value[]){v_Name, v_Arguments, alg_bool(false)}, 3), alg_nil()))) {
        return alg_invoke(v_this, "Fitting", (Value[]){v_Name, v_Arguments, alg_bool(false)}, 3);
    }
    return alg_invoke(v_this, "Fitting", (Value[]){v_Name, v_Arguments, alg_bool(true)}, 3);
    return alg_nil();
}

static Value m_ObjClass_Fitting_3_String_List_Boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    Value v_Widening = args[2];
    (void)v_Widening;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_Name}, 1))) {
        {
            Value v_Candidates = alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_Name}, 1);
            (void)v_Candidates;
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(v_Candidates, "Length")))) {
                    {
                        if (alg_truthy(alg_invoke(alg_subscript_get(v_Candidates, v_I), "Fits", (Value[]){v_Arguments, v_Widening}, 2))) {
                            return alg_subscript_get(v_Candidates, v_I);
                        }
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        return alg_invoke(alg_property(v_this, "Superclass"), "Fitting", (Value[]){v_Name, v_Arguments, v_Widening}, 3);
    }
    return alg_nil();
}

static Value m_ObjClass_SeedFields_2_ObjInstance(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Instance = args[0];
    (void)v_Instance;
    Value v_TheInterpreter = args[1];
    (void)v_TheInterpreter;
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Superclass"), "SeedFields", (Value[]){v_Instance, v_TheInterpreter}, 2));
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_this, "Fields"), "Length")))) {
            {
                {
                    Value v_Field = alg_subscript_get(alg_property(v_this, "Fields"), v_I);
                    (void)v_Field;
                    Value v_Value = alg_nil();
                    (void)v_Value;
                    if (alg_truthy(alg_not_equal(alg_property(v_Field, "Initializer"), alg_nil()))) {
                        (void)((v_Value = alg_invoke(v_TheInterpreter, "Evaluate", (Value[]){alg_property(v_Field, "Initializer")}, 1)));
                    }
                    (void)(alg_invoke(alg_property(v_Instance, "Fields"), "Put", (Value[]){f_FoldCase(NULL, (Value[]){alg_property(alg_property(v_Field, "Name"), "Lexeme")}, 1), v_Value}, 2));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_ObjClass_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Initializer = alg_nil();
    (void)v_Initializer;
    (void)((v_Initializer = alg_invoke(v_this, "FindMethod", (Value[]){alg_string("init")}, 1)));
    if (alg_truthy(alg_equal(v_Initializer, alg_nil()))) {
        return alg_int(0);
    }
    return alg_invoke(v_Initializer, "Arity", NULL, 0);
    return alg_nil();
}

static Value m_ObjClass_ToString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "Name");
    return alg_nil();
}

static Value m_ObjClass_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    Value v_Instance = alg_nil();
    (void)v_Instance;
    Value v_Initializer = alg_nil();
    (void)v_Initializer;
    (void)((v_Instance = alg_new(k_ObjInstance, (Value[]){v_this}, 1)));
    (void)(alg_invoke(v_this, "SeedFields", (Value[]){v_Instance, v_TheInterpreter}, 2));
    (void)((v_Initializer = alg_invoke(v_this, "FindOverload", (Value[]){alg_string("init"), v_Arguments}, 2)));
    if (alg_truthy(alg_equal(v_Initializer, alg_nil()))) {
        (void)((v_Initializer = alg_invoke(v_this, "FindMethod", (Value[]){alg_string("init")}, 1)));
    }
    if (alg_truthy(alg_not_equal(v_Initializer, alg_nil()))) {
        {
            (void)(alg_invoke(alg_invoke(v_Initializer, "Bind", (Value[]){v_Instance}, 1), "Call", (Value[]){v_TheInterpreter, v_Arguments}, 2));
        }
    }
    return v_Instance;
    return alg_nil();
}

void init_ObjClass(void) {
    k_ObjClass = alg_class("ObjClass", alg_nil());
    alg_class_field(k_ObjClass, "Name");
    alg_class_field(k_ObjClass, "Methods");
    alg_class_field(k_ObjClass, "Superclass");
    alg_class_field(k_ObjClass, "Fields");
    alg_class_initializer(k_ObjClass, i_ObjClass);
    alg_class_method(k_ObjClass, "Init", m_ObjClass_Init_4_String_ObjClass_Map_List, 4, t_ObjClass_Init_4_String_ObjClass_Map_List);
    alg_class_method(k_ObjClass, "FindMethod", m_ObjClass_FindMethod_1_String, 1, t_ObjClass_FindMethod_1_String);
    alg_class_method(k_ObjClass, "FindOverload", m_ObjClass_FindOverload_2_String_List, 2, t_ObjClass_FindOverload_2_String_List);
    alg_class_method(k_ObjClass, "Fitting", m_ObjClass_Fitting_3_String_List_Boolean, 3, t_ObjClass_Fitting_3_String_List_Boolean);
    alg_class_method(k_ObjClass, "SeedFields", m_ObjClass_SeedFields_2_ObjInstance, 2, t_ObjClass_SeedFields_2_ObjInstance);
    alg_class_method(k_ObjClass, "Arity", m_ObjClass_Arity_0, 0, NULL);
    alg_class_method(k_ObjClass, "ToString", m_ObjClass_ToString_0, 0, NULL);
    alg_class_method(k_ObjClass, "Call", m_ObjClass_Call_2, 2, t_ObjClass_Call_2);
}
