/* Generated from Algol-24.  Do not edit. */
#include "ObjClass.h"
#include "Token.h"
#include "ObjFunction.h"
#include "ObjInstance.h"

Value k_objclass;
static const char *t_objclass_init_4_string_objclass_map_list[] = { "Name : String", "Superclass : ObjClass", "Methods : Map", "Fields : List" };
static const char *t_objclass_methodofarity_2_string_integer[] = { "Name : String", "TheArity : Integer" };
static const char *t_objclass_declaresfield_1_string[] = { "Name : String" };
static const char *t_objclass_findmethod_1_string[] = { "Name : String" };
static const char *t_objclass_findoverload_2_string_list[] = { "Name : String", "Arguments : List" };
static const char *t_objclass_fitting_3_string_list_integer[] = { "Name : String", "Arguments : List", "Pass : Integer" };
static const char *t_objclass_seedfields_2_objinstance[] = { "Instance : ObjInstance", "TheInterpreter : Any" };
static const char *t_objclass_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };

static Value i_objclass(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Methods", alg_nil());
    alg_set_property(v_this, "Superclass", alg_nil());
    alg_set_property(v_this, "Fields", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_objclass_init_4_string_objclass_map_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_superclass = alg_widen(args[1], "ObjClass");
    (void)v_superclass;
    alg_root(&v_superclass, 1);
    Value v_methods = alg_widen(args[2], "Map");
    (void)v_methods;
    alg_root(&v_methods, 1);
    Value v_fields = alg_widen(args[3], "List");
    (void)v_fields;
    alg_root(&v_fields, 1);
    (void)(alg_set_property(v_this, "Name", v_name));
    (void)(alg_set_property(v_this, "Methods", v_methods));
    (void)(alg_set_property(v_this, "Superclass", v_superclass));
    (void)(alg_set_property(v_this, "Fields", v_fields));
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

static Value m_objclass_methodofarity_2_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_thearity = alg_widen(args[1], "Integer");
    (void)v_thearity;
    alg_root(&v_thearity, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1))) {
        {
            int32_t rt_11 = alg_root_top;
            Value v_found = alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1);
            (void)v_found;
            alg_root(&v_found, 1);
            {
                int32_t rt_12 = alg_root_top;
                Value loop_1 = alg_iterable(v_found);
                (void)loop_1;
                alg_root(&loop_1, 1);
                for (int32_t at_1 = 0; at_1 < alg_iterable_count(loop_1); at_1++) {
                    int32_t rt_13 = alg_root_top;
                    Value v_each = alg_iterable_at(loop_1, at_1);
                    (void)v_each;
                    alg_root(&v_each, 1);
                    if (alg_truthy(alg_equal(alg_invoke(v_each, "Arity", NULL, 0), v_thearity))) {
                        Value ret_2 = alg_cast(v_each, "ObjFunction");
                        alg_root_top = rt_base;
                        return ret_2;
                    }
                    alg_root_top = rt_13;
                }
                alg_root_top = rt_12;
            }
            alg_root_top = rt_11;
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        Value ret_3 = alg_invoke(alg_property(v_this, "Superclass"), "MethodOfArity", (Value[]){v_name, v_thearity}, 2);
        alg_root_top = rt_base;
        return ret_3;
    }
    Value ret_4 = alg_nil();
    alg_root_top = rt_base;
    return ret_4;
}

static Value m_objclass_declaresfield_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    {
        int32_t rt_14 = alg_root_top;
        Value loop_5 = alg_iterable(alg_property(v_this, "Fields"));
        (void)loop_5;
        alg_root(&loop_5, 1);
        for (int32_t at_5 = 0; at_5 < alg_iterable_count(loop_5); at_5++) {
            int32_t rt_15 = alg_root_top;
            Value v_field = alg_iterable_at(loop_5, at_5);
            (void)v_field;
            alg_root(&v_field, 1);
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(alg_property(v_field, "Name"), "Lexeme")}, 1), v_name))) {
                Value ret_6 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_6;
            }
            alg_root_top = rt_15;
        }
        alg_root_top = rt_14;
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        Value ret_7 = alg_invoke(alg_property(v_this, "Superclass"), "DeclaresField", (Value[]){v_name}, 1);
        alg_root_top = rt_base;
        return ret_7;
    }
    Value ret_8 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_8;
    Value ret_9 = alg_nil();
    alg_root_top = rt_base;
    return ret_9;
}

static Value m_objclass_findmethod_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1))) {
        {
            int32_t rt_16 = alg_root_top;
            Value v_found = alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1);
            (void)v_found;
            alg_root(&v_found, 1);
            if (alg_truthy(alg_greater(alg_property(v_found, "Length"), alg_int(0)))) {
                Value ret_10 = alg_cast(alg_subscript_get(v_found, alg_int(0)), "ObjFunction");
                alg_root_top = rt_base;
                return ret_10;
            }
            alg_root_top = rt_16;
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        {
            Value ret_11 = alg_invoke(alg_property(v_this, "Superclass"), "FindMethod", (Value[]){v_name}, 1);
            alg_root_top = rt_base;
            return ret_11;
        }
    }
    Value ret_12 = alg_nil();
    alg_root_top = rt_base;
    return ret_12;
}

static Value m_objclass_findoverload_2_string_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_arguments = alg_widen(args[1], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    {
        int32_t rt_17 = alg_root_top;
        Value v_pass = (alg_declared(d_exact, "EXACT"), v_exact);
        (void)v_pass;
        alg_root(&v_pass, 1);
        for (; alg_truthy(alg_less_equal(v_pass, (alg_declared(d_absorbing, "ABSORBING"), v_absorbing))); (v_pass = alg_add(v_pass, alg_int(1)))) {
            {
                int32_t rt_18 = alg_root_top;
                Value v_found = alg_invoke(v_this, "Fitting", (Value[]){v_name, v_arguments, v_pass}, 3);
                (void)v_found;
                alg_root(&v_found, 1);
                if (alg_truthy(alg_not_equal(v_found, alg_nil()))) {
                    Value ret_13 = v_found;
                    alg_root_top = rt_base;
                    return ret_13;
                }
                alg_root_top = rt_18;
            }
        }
        alg_root_top = rt_17;
    }
    Value ret_14 = alg_nil();
    alg_root_top = rt_base;
    return ret_14;
}

static Value m_objclass_fitting_3_string_list_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_arguments = alg_widen(args[1], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_pass = alg_widen(args[2], "Integer");
    (void)v_pass;
    alg_root(&v_pass, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1))) {
        {
            int32_t rt_19 = alg_root_top;
            Value v_candidates = alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1);
            (void)v_candidates;
            alg_root(&v_candidates, 1);
            {
                int32_t rt_20 = alg_root_top;
                Value loop_15 = alg_iterable(v_candidates);
                (void)loop_15;
                alg_root(&loop_15, 1);
                for (int32_t at_15 = 0; at_15 < alg_iterable_count(loop_15); at_15++) {
                    int32_t rt_21 = alg_root_top;
                    Value v_candidate = alg_iterable_at(loop_15, at_15);
                    (void)v_candidate;
                    alg_root(&v_candidate, 1);
                    if (alg_truthy(alg_invoke(v_candidate, "Selects", (Value[]){v_arguments, v_pass}, 2))) {
                        Value ret_16 = alg_cast(v_candidate, "ObjFunction");
                        alg_root_top = rt_base;
                        return ret_16;
                    }
                    alg_root_top = rt_21;
                }
                alg_root_top = rt_20;
            }
            alg_root_top = rt_19;
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        Value ret_17 = alg_invoke(alg_property(v_this, "Superclass"), "Fitting", (Value[]){v_name, v_arguments, v_pass}, 3);
        alg_root_top = rt_base;
        return ret_17;
    }
    Value ret_18 = alg_nil();
    alg_root_top = rt_base;
    return ret_18;
}

static Value m_objclass_seedfields_2_objinstance(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_instance = alg_widen(args[0], "ObjInstance");
    (void)v_instance;
    alg_root(&v_instance, 1);
    Value v_theinterpreter = args[1];
    (void)v_theinterpreter;
    alg_root(&v_theinterpreter, 1);
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Superclass"), "SeedFields", (Value[]){v_instance, v_theinterpreter}, 2));
    }
    {
        int32_t rt_22 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_this, "Fields"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_23 = alg_root_top;
                Value v_field = alg_subscript_get(alg_property(v_this, "Fields"), v_i);
                (void)v_field;
                alg_root(&v_field, 1);
                Value v_value = alg_nil();
                (void)v_value;
                alg_root(&v_value, 1);
                if (alg_truthy(alg_not_equal(alg_property(v_field, "Initializer"), alg_nil()))) {
                    (void)((v_value = alg_invoke(v_theinterpreter, "Widen", (Value[]){alg_invoke(v_theinterpreter, "Evaluate", (Value[]){alg_property(v_field, "Initializer")}, 1), alg_str(alg_property(v_field, "TypeName"))}, 2)));
                }
                (void)(alg_invoke(alg_property(v_instance, "Fields"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_field, "Name"), "Lexeme")}, 1), v_value}, 2));
                alg_root_top = rt_23;
            }
        }
        alg_root_top = rt_22;
    }
    Value ret_19 = alg_nil();
    alg_root_top = rt_base;
    return ret_19;
}

static Value m_objclass_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    (void)((v_initializer = alg_invoke(v_this, "FindMethod", (Value[]){alg_string("init")}, 1)));
    if (alg_truthy(alg_equal(v_initializer, alg_nil()))) {
        Value ret_20 = alg_int(0);
        alg_root_top = rt_base;
        return ret_20;
    }
    Value ret_21 = alg_cast(alg_invoke(v_initializer, "Arity", NULL, 0), "Integer");
    alg_root_top = rt_base;
    return ret_21;
    Value ret_22 = alg_nil();
    alg_root_top = rt_base;
    return ret_22;
}

static Value m_objclass_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_23 = alg_property(v_this, "Name");
    alg_root_top = rt_base;
    return ret_23;
    Value ret_24 = alg_nil();
    alg_root_top = rt_base;
    return ret_24;
}

static Value m_objclass_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    alg_root(&v_theinterpreter, 1);
    Value v_arguments = args[1];
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_instance = alg_nil();
    (void)v_instance;
    alg_root(&v_instance, 1);
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
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
    Value ret_25 = v_instance;
    alg_root_top = rt_base;
    return ret_25;
    Value ret_26 = alg_nil();
    alg_root_top = rt_base;
    return ret_26;
}

static Value *roots_ObjClass[] = {
    &k_objclass,
};

void init_ObjClass(void) {
    alg_roots(roots_ObjClass, 1);
    k_objclass = alg_class("ObjClass", alg_nil());
    alg_class_field(k_objclass, "Name");
    alg_class_field(k_objclass, "Methods");
    alg_class_field(k_objclass, "Superclass");
    alg_class_field(k_objclass, "Fields");
    alg_class_initializer(k_objclass, i_objclass);
    alg_class_method(k_objclass, "Init", m_objclass_init_4_string_objclass_map_list, 4, t_objclass_init_4_string_objclass_map_list);
    alg_class_method(k_objclass, "MethodOfArity", m_objclass_methodofarity_2_string_integer, 2, t_objclass_methodofarity_2_string_integer);
    alg_class_method(k_objclass, "DeclaresField", m_objclass_declaresfield_1_string, 1, t_objclass_declaresfield_1_string);
    alg_class_method(k_objclass, "FindMethod", m_objclass_findmethod_1_string, 1, t_objclass_findmethod_1_string);
    alg_class_method(k_objclass, "FindOverload", m_objclass_findoverload_2_string_list, 2, t_objclass_findoverload_2_string_list);
    alg_class_method(k_objclass, "Fitting", m_objclass_fitting_3_string_list_integer, 3, t_objclass_fitting_3_string_list_integer);
    alg_class_method(k_objclass, "SeedFields", m_objclass_seedfields_2_objinstance, 2, t_objclass_seedfields_2_objinstance);
    alg_class_method(k_objclass, "Arity", m_objclass_arity_0, 0, NULL);
    alg_class_method(k_objclass, "ToString", m_objclass_tostring_0, 0, NULL);
    alg_class_method(k_objclass, "Call", m_objclass_call_2, 2, t_objclass_call_2);
    init_ObjInstance();
}
