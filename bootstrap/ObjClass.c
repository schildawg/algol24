/* Generated from Algol-24.  Do not edit. */
#include "ObjClass.h"
#include "Token.h"
#include "ObjFunction.h"
#include "ObjInstance.h"

Value k_objclass;
static const char *t_objclass_init_4_string_objclass_map_list[] = { "String", "ObjClass", "Map", "List" };
static const char *t_objclass_findmethod_1_string[] = { "String" };
static const char *t_objclass_findoverload_2_string_list[] = { "String", "List" };
static const char *t_objclass_fitting_3_string_list_boolean[] = { "String", "List", "Boolean" };
static const char *t_objclass_seedfields_2_objinstance[] = { "ObjInstance", "Any" };
static const char *t_objclass_call_2[] = { "Any", "Any" };

static Value i_objclass(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Methods", alg_nil());
    alg_set_property(v_this, "Superclass", alg_nil());
    alg_set_property(v_this, "Fields", alg_nil());
    return alg_nil();
}

static Value m_objclass_init_4_string_objclass_map_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = args[0];
    (void)v_name;
    Value v_superclass = args[1];
    (void)v_superclass;
    Value v_methods = args[2];
    (void)v_methods;
    Value v_fields = args[3];
    (void)v_fields;
    (void)(alg_set_property(v_this, "Name", v_name));
    (void)(alg_set_property(v_this, "Methods", v_methods));
    (void)(alg_set_property(v_this, "Superclass", v_superclass));
    (void)(alg_set_property(v_this, "Fields", v_fields));
    return alg_nil();
}

static Value m_objclass_findmethod_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = args[0];
    (void)v_name;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1))) {
        {
            Value v_found = alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1);
            (void)v_found;
            if (alg_truthy(alg_greater(alg_property(v_found, "Length"), alg_int(0)))) {
                return alg_subscript_get(v_found, alg_int(0));
            }
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        {
            return alg_invoke(alg_property(v_this, "Superclass"), "FindMethod", (Value[]){v_name}, 1);
        }
    }
    return alg_nil();
}

static Value m_objclass_findoverload_2_string_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = args[0];
    (void)v_name;
    Value v_arguments = args[1];
    (void)v_arguments;
    if (alg_truthy(alg_not_equal(alg_invoke(v_this, "Fitting", (Value[]){v_name, v_arguments, alg_bool(false)}, 3), alg_nil()))) {
        return alg_invoke(v_this, "Fitting", (Value[]){v_name, v_arguments, alg_bool(false)}, 3);
    }
    return alg_invoke(v_this, "Fitting", (Value[]){v_name, v_arguments, alg_bool(true)}, 3);
    return alg_nil();
}

static Value m_objclass_fitting_3_string_list_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = args[0];
    (void)v_name;
    Value v_arguments = args[1];
    (void)v_arguments;
    Value v_widening = args[2];
    (void)v_widening;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1))) {
        {
            Value v_candidates = alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1);
            (void)v_candidates;
            {
                Value v_i = alg_int(0);
                (void)v_i;
                while (alg_truthy(alg_less(v_i, alg_property(v_candidates, "Length")))) {
                    {
                        if (alg_truthy(alg_invoke(alg_subscript_get(v_candidates, v_i), "Fits", (Value[]){v_arguments, v_widening}, 2))) {
                            return alg_subscript_get(v_candidates, v_i);
                        }
                        (void)((v_i = alg_add(v_i, alg_int(1))));
                    }
                }
            }
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        return alg_invoke(alg_property(v_this, "Superclass"), "Fitting", (Value[]){v_name, v_arguments, v_widening}, 3);
    }
    return alg_nil();
}

static Value m_objclass_seedfields_2_objinstance(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_instance = args[0];
    (void)v_instance;
    Value v_theinterpreter = args[1];
    (void)v_theinterpreter;
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Superclass"), "SeedFields", (Value[]){v_instance, v_theinterpreter}, 2));
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_this, "Fields"), "Length")))) {
            {
                {
                    Value v_field = alg_subscript_get(alg_property(v_this, "Fields"), v_i);
                    (void)v_field;
                    Value v_value = alg_nil();
                    (void)v_value;
                    if (alg_truthy(alg_not_equal(alg_property(v_field, "Initializer"), alg_nil()))) {
                        (void)((v_value = alg_invoke(v_theinterpreter, "Evaluate", (Value[]){alg_property(v_field, "Initializer")}, 1)));
                    }
                    (void)(alg_invoke(alg_property(v_instance, "Fields"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_field, "Name"), "Lexeme")}, 1), v_value}, 2));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_objclass_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    (void)((v_initializer = alg_invoke(v_this, "FindMethod", (Value[]){alg_string("init")}, 1)));
    if (alg_truthy(alg_equal(v_initializer, alg_nil()))) {
        return alg_int(0);
    }
    return alg_invoke(v_initializer, "Arity", NULL, 0);
    return alg_nil();
}

static Value m_objclass_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "Name");
    return alg_nil();
}

static Value m_objclass_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    Value v_instance = alg_nil();
    (void)v_instance;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    (void)((v_instance = alg_new(k_objinstance, (Value[]){v_this}, 1)));
    (void)(alg_invoke(v_this, "SeedFields", (Value[]){v_instance, v_theinterpreter}, 2));
    (void)((v_initializer = alg_invoke(v_this, "FindOverload", (Value[]){alg_string("init"), v_arguments}, 2)));
    if (alg_truthy(alg_equal(v_initializer, alg_nil()))) {
        (void)((v_initializer = alg_invoke(v_this, "FindMethod", (Value[]){alg_string("init")}, 1)));
    }
    if (alg_truthy(alg_not_equal(v_initializer, alg_nil()))) {
        {
            (void)(alg_invoke(alg_invoke(v_initializer, "Bind", (Value[]){v_instance}, 1), "Call", (Value[]){v_theinterpreter, v_arguments}, 2));
        }
    }
    return v_instance;
    return alg_nil();
}

void init_ObjClass(void) {
    k_objclass = alg_class("ObjClass", alg_nil());
    alg_class_field(k_objclass, "Name");
    alg_class_field(k_objclass, "Methods");
    alg_class_field(k_objclass, "Superclass");
    alg_class_field(k_objclass, "Fields");
    alg_class_initializer(k_objclass, i_objclass);
    alg_class_method(k_objclass, "Init", m_objclass_init_4_string_objclass_map_list, 4, t_objclass_init_4_string_objclass_map_list);
    alg_class_method(k_objclass, "FindMethod", m_objclass_findmethod_1_string, 1, t_objclass_findmethod_1_string);
    alg_class_method(k_objclass, "FindOverload", m_objclass_findoverload_2_string_list, 2, t_objclass_findoverload_2_string_list);
    alg_class_method(k_objclass, "Fitting", m_objclass_fitting_3_string_list_boolean, 3, t_objclass_fitting_3_string_list_boolean);
    alg_class_method(k_objclass, "SeedFields", m_objclass_seedfields_2_objinstance, 2, t_objclass_seedfields_2_objinstance);
    alg_class_method(k_objclass, "Arity", m_objclass_arity_0, 0, NULL);
    alg_class_method(k_objclass, "ToString", m_objclass_tostring_0, 0, NULL);
    alg_class_method(k_objclass, "Call", m_objclass_call_2, 2, t_objclass_call_2);
}
