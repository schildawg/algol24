/* Generated from Algol-24.  Do not edit. */
#include "ObjClass.h"
#include "Token.h"
#include "ObjFunction.h"
#include "ObjInstance.h"

Value k_objclass;
static const char *t_objclass_init_4_string_objclass_map_list[] = { "Name : String", "Superclass : ObjClass", "Methods : Map", "Fields : List" };
static const char *t_objclass_methodofarity_2_string_integer[] = { "Name : String", "TheArity : Integer" };
static const char *t_objclass_findmethod_1_string[] = { "Name : String" };
static const char *t_objclass_findoverload_2_string_list[] = { "Name : String", "Arguments : List" };
static const char *t_objclass_fitting_3_string_list_integer[] = { "Name : String", "Arguments : List", "Pass : Integer" };
static const char *t_objclass_seedfields_2_objinstance[] = { "Instance : ObjInstance", "TheInterpreter : Any" };
static const char *t_objclass_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };

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
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_superclass = alg_widen(args[1], "ObjClass");
    (void)v_superclass;
    Value v_methods = alg_widen(args[2], "Map");
    (void)v_methods;
    Value v_fields = alg_widen(args[3], "List");
    (void)v_fields;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "String")));
    (void)(alg_set_property(v_this, "Methods", alg_widen(v_methods, "Map")));
    (void)(alg_set_property(v_this, "Superclass", alg_widen(v_superclass, "ObjClass")));
    (void)(alg_set_property(v_this, "Fields", alg_widen(v_fields, "List")));
    return alg_nil();
}

static Value m_objclass_methodofarity_2_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_thearity = alg_widen(args[1], "Integer");
    (void)v_thearity;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1))) {
        {
            Value v_found = alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1);
            (void)v_found;
            {
                Value loop_0 = alg_iterable(v_found);
                for (int32_t at_0 = 0; at_0 < alg_iterable_count(loop_0); at_0++) {
                    Value v_each = alg_iterable_at(loop_0, at_0);
                    (void)v_each;
                    if (alg_truthy(alg_equal(alg_invoke(v_each, "Arity", NULL, 0), v_thearity))) {
                        return alg_cast(v_each, "ObjFunction");
                    }
                }
            }
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        return alg_invoke(alg_property(v_this, "Superclass"), "MethodOfArity", (Value[]){v_name, v_thearity}, 2);
    }
    return alg_nil();
}

static Value m_objclass_findmethod_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1))) {
        {
            Value v_found = alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1);
            (void)v_found;
            if (alg_truthy(alg_greater(alg_property(v_found, "Length"), alg_int(0)))) {
                return alg_cast(alg_subscript_get(v_found, alg_int(0)), "ObjFunction");
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
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_arguments = alg_widen(args[1], "List");
    (void)v_arguments;
    {
        Value v_pass = (alg_declared(d_exact, "EXACT"), v_exact);
        (void)v_pass;
        for (; alg_truthy(alg_less_equal(v_pass, (alg_declared(d_absorbing, "ABSORBING"), v_absorbing))); (v_pass = alg_add(v_pass, alg_int(1)))) {
            {
                Value v_found = alg_invoke(v_this, "Fitting", (Value[]){v_name, v_arguments, v_pass}, 3);
                (void)v_found;
                if (alg_truthy(alg_not_equal(v_found, alg_nil()))) {
                    return v_found;
                }
            }
        }
    }
    return alg_nil();
}

static Value m_objclass_fitting_3_string_list_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_arguments = alg_widen(args[1], "List");
    (void)v_arguments;
    Value v_pass = alg_widen(args[2], "Integer");
    (void)v_pass;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1))) {
        {
            Value v_candidates = alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1);
            (void)v_candidates;
            {
                Value loop_1 = alg_iterable(v_candidates);
                for (int32_t at_1 = 0; at_1 < alg_iterable_count(loop_1); at_1++) {
                    Value v_candidate = alg_iterable_at(loop_1, at_1);
                    (void)v_candidate;
                    if (alg_truthy(alg_invoke(v_candidate, "Selects", (Value[]){v_arguments, v_pass}, 2))) {
                        return alg_cast(v_candidate, "ObjFunction");
                    }
                }
            }
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        return alg_invoke(alg_property(v_this, "Superclass"), "Fitting", (Value[]){v_name, v_arguments, v_pass}, 3);
    }
    return alg_nil();
}

static Value m_objclass_seedfields_2_objinstance(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_instance = alg_widen(args[0], "ObjInstance");
    (void)v_instance;
    Value v_theinterpreter = args[1];
    (void)v_theinterpreter;
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Superclass"), "SeedFields", (Value[]){v_instance, v_theinterpreter}, 2));
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_this, "Fields"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                Value v_field = alg_subscript_get(alg_property(v_this, "Fields"), v_i);
                (void)v_field;
                Value v_value = alg_nil();
                (void)v_value;
                if (alg_truthy(alg_not_equal(alg_property(v_field, "Initializer"), alg_nil()))) {
                    (void)((v_value = alg_invoke(v_theinterpreter, "Widen", (Value[]){alg_invoke(v_theinterpreter, "Evaluate", (Value[]){alg_property(v_field, "Initializer")}, 1), alg_str(alg_property(v_field, "TypeName"))}, 2)));
                }
                (void)(alg_invoke(alg_property(v_instance, "Fields"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_field, "Name"), "Lexeme")}, 1), v_value}, 2));
            }
        }
    }
    return alg_nil();
}

static Value m_objclass_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    (void)((v_initializer = alg_widen(alg_invoke(v_this, "FindMethod", (Value[]){alg_string("init")}, 1), "ObjFunction")));
    if (alg_truthy(alg_equal(v_initializer, alg_nil()))) {
        return alg_int(0);
    }
    return alg_cast(alg_invoke(v_initializer, "Arity", NULL, 0), "Integer");
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
    (void)((v_instance = alg_widen(alg_cast(alg_new(k_objinstance, (Value[]){v_this}, 1), "ObjInstance"), "ObjInstance")));
    (void)(alg_invoke(v_this, "SeedFields", (Value[]){v_instance, v_theinterpreter}, 2));
    (void)((v_initializer = alg_widen(alg_invoke(v_this, "FindOverload", (Value[]){alg_string("init"), v_arguments}, 2), "ObjFunction")));
    if (alg_truthy(alg_equal(v_initializer, alg_nil()))) {
        (void)((v_initializer = alg_widen(alg_invoke(v_this, "FindMethod", (Value[]){alg_string("init")}, 1), "ObjFunction")));
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
    alg_class_method(k_objclass, "MethodOfArity", m_objclass_methodofarity_2_string_integer, 2, t_objclass_methodofarity_2_string_integer);
    alg_class_method(k_objclass, "FindMethod", m_objclass_findmethod_1_string, 1, t_objclass_findmethod_1_string);
    alg_class_method(k_objclass, "FindOverload", m_objclass_findoverload_2_string_list, 2, t_objclass_findoverload_2_string_list);
    alg_class_method(k_objclass, "Fitting", m_objclass_fitting_3_string_list_integer, 3, t_objclass_fitting_3_string_list_integer);
    alg_class_method(k_objclass, "SeedFields", m_objclass_seedfields_2_objinstance, 2, t_objclass_seedfields_2_objinstance);
    alg_class_method(k_objclass, "Arity", m_objclass_arity_0, 0, NULL);
    alg_class_method(k_objclass, "ToString", m_objclass_tostring_0, 0, NULL);
    alg_class_method(k_objclass, "Call", m_objclass_call_2, 2, t_objclass_call_2);
    init_ObjInstance();
}
