/* Generated from Algol-24.  Do not edit. */
#include "ObjClass.h"
#include "Token.h"
#include "ObjFunction.h"
#include "ObjInstance.h"

Value k_objclass;
static Value or_0;
static const char *t_objclass_init_4_string_objclass_map_list[] = { "Name : String", "Superclass : ObjClass", "Methods : Map", "Fields : List" };
static const char *t_objclass_methodofarity_2_string_integer[] = { "Name : String", "TheArity : Integer" };
static const char *t_objclass_declaresfield_1_string[] = { "Name : String" };
static const char *t_objclass_findmethod_1_string[] = { "Name : String" };
static const char *t_objclass_findoverload_2_string_list[] = { "Name : String", "Arguments : List" };
static const char *t_objclass_fitting_3_string_list_integer[] = { "Name : String", "Arguments : List", "Pass : Integer" };
static const char *t_objclass_seedfields_2_objinstance[] = { "Instance : ObjInstance", "TheInterpreter : Any" };
static const char *t_objclass_fieldsinto_1_map[] = { "Into : Map" };
static const char *t_objclass_absorbs_1_list[] = { "Arguments : List" };
static const char *t_objclass_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };

static Value i_objclass(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Methods", alg_nil());
    alg_set_property(v_this, "Superclass", alg_nil());
    alg_set_property(v_this, "IsType", alg_widen(alg_bool(false), "Boolean"));
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
    int32_t rh_233 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_233;
    (void)(alg_hold(alg_set_property(v_this, "Methods", v_methods)));
    alg_hold_top = rh_233;
    (void)(alg_hold(alg_set_property(v_this, "Superclass", v_superclass)));
    alg_hold_top = rh_233;
    (void)(alg_hold(alg_set_property(v_this, "Fields", v_fields)));
    alg_hold_top = rh_233;
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
    int32_t rh_234 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1)))) {
        {
            int32_t rt_235 = alg_root_top;
            int32_t rh_236 = alg_hold_top;
            Value v_found = alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1));
            (void)v_found;
            alg_root(&v_found, 1);
            alg_hold_top = rh_236;
            {
                int32_t rt_237 = alg_root_top;
                Value loop_1 = alg_iterable(v_found);
                (void)loop_1;
                alg_root(&loop_1, 1);
                for (int32_t at_1 = 0; at_1 < alg_iterable_count(loop_1); at_1++) {
                    alg_safe_point();
                    int32_t rt_238 = alg_root_top;
                    Value v_each = alg_iterable_at(loop_1, at_1);
                    (void)v_each;
                    alg_root(&v_each, 1);
                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_invoke(v_each, "Arity", NULL, 0)), v_thearity)))) {
                        Value ret_2 = alg_cast_class(v_each, k_objfunction, "ObjFunction");
                        alg_root_top = rt_base;
                        return ret_2;
                    }
                    alg_root_top = rt_238;
                }
                alg_root_top = rt_237;
            }
            alg_hold_top = rh_236;
            alg_root_top = rt_235;
        }
    }
    alg_hold_top = rh_234;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        Value ret_3 = alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "MethodOfArity", (Value[]){v_name, v_thearity}, 2));
        alg_root_top = rt_base;
        return ret_3;
    }
    alg_hold_top = rh_234;
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
    int32_t rh_239 = alg_hold_top;
    {
        int32_t rt_240 = alg_root_top;
        Value loop_5 = alg_iterable(alg_property(v_this, "Fields"));
        (void)loop_5;
        alg_root(&loop_5, 1);
        for (int32_t at_5 = 0; at_5 < alg_iterable_count(loop_5); at_5++) {
            alg_safe_point();
            int32_t rt_241 = alg_root_top;
            Value v_field = alg_iterable_at(loop_5, at_5);
            (void)v_field;
            alg_root(&v_field, 1);
            if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme"))}, 1)), v_name)))) {
                Value ret_6 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_6;
            }
            alg_root_top = rt_241;
        }
        alg_root_top = rt_240;
    }
    alg_hold_top = rh_239;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        Value ret_7 = alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "DeclaresField", (Value[]){v_name}, 1));
        alg_root_top = rt_base;
        return ret_7;
    }
    alg_hold_top = rh_239;
    Value ret_8 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_8;
    alg_hold_top = rh_239;
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
    int32_t rh_242 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1)))) {
        {
            int32_t rt_243 = alg_root_top;
            int32_t rh_244 = alg_hold_top;
            Value v_found = alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1));
            (void)v_found;
            alg_root(&v_found, 1);
            alg_hold_top = rh_244;
            if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(v_found, "Length")), alg_int(0))))) {
                Value ret_10 = alg_hold(alg_cast_class(alg_subscript_get(v_found, alg_int(0)), k_objfunction, "ObjFunction"));
                alg_root_top = rt_base;
                return ret_10;
            }
            alg_hold_top = rh_244;
            alg_root_top = rt_243;
        }
    }
    alg_hold_top = rh_242;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        {
            int32_t rh_245 = alg_hold_top;
            Value ret_11 = alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "FindMethod", (Value[]){v_name}, 1));
            alg_root_top = rt_base;
            return ret_11;
            alg_hold_top = rh_245;
        }
    }
    alg_hold_top = rh_242;
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
    int32_t rh_246 = alg_hold_top;
    {
        int32_t rt_247 = alg_root_top;
        int32_t rh_248 = alg_hold_top;
        Value v_pass = (alg_declared(d_exact, "EXACT"), v_exact);
        (void)v_pass;
        alg_root(&v_pass, 1);
        alg_hold_top = rh_248;
        {
            int32_t rh_249 = alg_hold_top;
            for (; (alg_hold_top = rh_249, alg_truthy(alg_hold(alg_less_equal(v_pass, (alg_declared(d_absorbing, "ABSORBING"), v_absorbing))))); (alg_hold_top = rh_249, (v_pass = alg_hold(alg_add(v_pass, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_250 = alg_root_top;
                    int32_t rh_251 = alg_hold_top;
                    Value v_found = alg_hold(alg_invoke(v_this, "Fitting", (Value[]){v_name, v_arguments, v_pass}, 3));
                    (void)v_found;
                    alg_root(&v_found, 1);
                    alg_hold_top = rh_251;
                    if (alg_truthy(alg_hold(alg_not_equal(v_found, alg_nil())))) {
                        Value ret_13 = v_found;
                        alg_root_top = rt_base;
                        return ret_13;
                    }
                    alg_hold_top = rh_251;
                    alg_root_top = rt_250;
                }
            }
        }
        alg_hold_top = rh_248;
        alg_root_top = rt_247;
    }
    alg_hold_top = rh_246;
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
    int32_t rh_252 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1)))) {
        {
            int32_t rt_253 = alg_root_top;
            int32_t rh_254 = alg_hold_top;
            Value v_candidates = alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1));
            (void)v_candidates;
            alg_root(&v_candidates, 1);
            alg_hold_top = rh_254;
            {
                int32_t rt_255 = alg_root_top;
                Value loop_15 = alg_iterable(v_candidates);
                (void)loop_15;
                alg_root(&loop_15, 1);
                for (int32_t at_15 = 0; at_15 < alg_iterable_count(loop_15); at_15++) {
                    alg_safe_point();
                    int32_t rt_256 = alg_root_top;
                    Value v_candidate = alg_iterable_at(loop_15, at_15);
                    (void)v_candidate;
                    alg_root(&v_candidate, 1);
                    if (alg_truthy(alg_hold(alg_invoke(v_candidate, "Selects", (Value[]){v_arguments, v_pass}, 2)))) {
                        Value ret_16 = alg_cast_class(v_candidate, k_objfunction, "ObjFunction");
                        alg_root_top = rt_base;
                        return ret_16;
                    }
                    alg_root_top = rt_256;
                }
                alg_root_top = rt_255;
            }
            alg_hold_top = rh_254;
            alg_root_top = rt_253;
        }
    }
    alg_hold_top = rh_252;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        Value ret_17 = alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "Fitting", (Value[]){v_name, v_arguments, v_pass}, 3));
        alg_root_top = rt_base;
        return ret_17;
    }
    alg_hold_top = rh_252;
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
    int32_t rh_257 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "SeedFields", (Value[]){v_instance, v_theinterpreter}, 2)));
    }
    alg_hold_top = rh_257;
    {
        int32_t rt_258 = alg_root_top;
        int32_t rh_259 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_259;
        {
            int32_t rh_260 = alg_hold_top;
            for (; (alg_hold_top = rh_260, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_property(v_this, "Fields"), "Length")))))); (alg_hold_top = rh_260, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_261 = alg_root_top;
                    int32_t rh_262 = alg_hold_top;
                    Value v_field = alg_hold(alg_subscript_get(alg_property(v_this, "Fields"), v_i));
                    (void)v_field;
                    alg_root(&v_field, 1);
                    alg_hold_top = rh_262;
                    Value v_value = alg_nil();
                    (void)v_value;
                    alg_root(&v_value, 1);
                    alg_hold_top = rh_262;
                    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_field, "Initializer")), alg_nil())))) {
                        (void)((v_value = alg_hold(alg_invoke(v_theinterpreter, "Widen", (Value[]){alg_hold(alg_invoke(v_theinterpreter, "Evaluate", (Value[]){alg_hold(alg_property(v_field, "Initializer"))}, 1)), alg_hold(alg_str(alg_hold(alg_property(v_field, "TypeName"))))}, 2))));
                    }
                    alg_hold_top = rh_262;
                    (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_instance, "Fields")), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme"))}, 1)), v_value}, 2)));
                    alg_hold_top = rh_262;
                    alg_root_top = rt_261;
                }
            }
        }
        alg_hold_top = rh_259;
        alg_root_top = rt_258;
    }
    alg_hold_top = rh_257;
    Value ret_19 = alg_nil();
    alg_root_top = rt_base;
    return ret_19;
}

static Value m_objclass_fieldsinto_1_map(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_into = alg_widen(args[0], "Map");
    (void)v_into;
    alg_root(&v_into, 1);
    int32_t rh_263 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "FieldsInto", (Value[]){v_into}, 1)));
    }
    alg_hold_top = rh_263;
    {
        int32_t rt_264 = alg_root_top;
        int32_t rh_265 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_265;
        {
            int32_t rh_266 = alg_hold_top;
            for (; (alg_hold_top = rh_266, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_property(v_this, "Fields"), "Length")))))); (alg_hold_top = rh_266, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_267 = alg_root_top;
                    int32_t rh_268 = alg_hold_top;
                    Value v_field = alg_hold(alg_subscript_get(alg_property(v_this, "Fields"), v_i));
                    (void)v_field;
                    alg_root(&v_field, 1);
                    alg_hold_top = rh_268;
                    (void)(alg_hold(alg_invoke(v_into, "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme")))), alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_field, "TypeName"))))}, 1))}, 2)));
                    alg_hold_top = rh_268;
                    alg_root_top = rt_267;
                }
            }
        }
        alg_hold_top = rh_265;
        alg_root_top = rt_264;
    }
    alg_hold_top = rh_263;
    Value ret_20 = alg_nil();
    alg_root_top = rt_base;
    return ret_20;
}

static Value m_objclass_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_269 = alg_hold_top;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    alg_hold_top = rh_269;
    (void)((v_initializer = alg_hold(alg_invoke(v_this, "FindMethod", (Value[]){alg_literal("init")}, 1))));
    alg_hold_top = rh_269;
    if (alg_truthy(alg_hold(alg_equal(v_initializer, alg_nil())))) {
        Value ret_21 = alg_int(0);
        alg_root_top = rt_base;
        return ret_21;
    }
    alg_hold_top = rh_269;
    Value ret_22 = alg_hold(alg_cast_kind(alg_invoke(v_initializer, "Arity", NULL, 0), ALG_KIND_INTEGER, "Integer"));
    alg_root_top = rt_base;
    return ret_22;
    alg_hold_top = rh_269;
    Value ret_23 = alg_nil();
    alg_root_top = rt_base;
    return ret_23;
}

static Value m_objclass_absorbs_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    int32_t rh_270 = alg_hold_top;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    alg_hold_top = rh_270;
    (void)((v_initializer = alg_hold(alg_invoke(v_this, "FindOverload", (Value[]){alg_literal("init"), v_arguments}, 2))));
    alg_hold_top = rh_270;
    if (alg_truthy(alg_hold(alg_equal(v_initializer, alg_nil())))) {
        (void)((v_initializer = alg_hold(alg_invoke(v_this, "FindMethod", (Value[]){alg_literal("init")}, 1))));
    }
    alg_hold_top = rh_270;
    if (alg_truthy(alg_hold(alg_equal(v_initializer, alg_nil())))) {
        Value ret_24 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_24;
    }
    alg_hold_top = rh_270;
    Value ret_25 = alg_hold(alg_cast_kind(alg_invoke(v_initializer, "Absorbs", (Value[]){v_arguments}, 1), ALG_KIND_BOOLEAN, "Boolean"));
    alg_root_top = rt_base;
    return ret_25;
    alg_hold_top = rh_270;
    Value ret_26 = alg_nil();
    alg_root_top = rt_base;
    return ret_26;
}

static Value m_objclass_variadic_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_271 = alg_hold_top;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    alg_hold_top = rh_271;
    (void)((v_initializer = alg_hold(alg_invoke(v_this, "FindMethod", (Value[]){alg_literal("init")}, 1))));
    alg_hold_top = rh_271;
    if (alg_truthy(alg_hold(alg_equal(v_initializer, alg_nil())))) {
        Value ret_27 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_27;
    }
    alg_hold_top = rh_271;
    Value ret_28 = alg_hold(alg_cast_kind(alg_invoke(v_initializer, "Variadic", NULL, 0), ALG_KIND_BOOLEAN, "Boolean"));
    alg_root_top = rt_base;
    return ret_28;
    alg_hold_top = rh_271;
    Value ret_29 = alg_nil();
    alg_root_top = rt_base;
    return ret_29;
}

static Value m_objclass_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_272 = alg_hold_top;
    Value ret_30 = alg_property(v_this, "Name");
    alg_root_top = rt_base;
    return ret_30;
    alg_hold_top = rh_272;
    Value ret_31 = alg_nil();
    alg_root_top = rt_base;
    return ret_31;
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
    int32_t rh_273 = alg_hold_top;
    Value v_instance = alg_nil();
    (void)v_instance;
    alg_root(&v_instance, 1);
    alg_hold_top = rh_273;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    alg_hold_top = rh_273;
    if (alg_truthy(alg_property(v_this, "IsType"))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_str(alg_property(v_this, "Name"))), alg_literal(" is a type rather than a class, and cannot be constructed."))));
    }
    alg_hold_top = rh_273;
    (void)((v_instance = alg_hold(alg_new(k_objinstance, (Value[]){v_this}, 1))));
    alg_hold_top = rh_273;
    (void)(alg_hold(alg_invoke(v_this, "SeedFields", (Value[]){v_instance, v_theinterpreter}, 2)));
    alg_hold_top = rh_273;
    (void)((v_initializer = alg_hold(alg_invoke(v_this, "FindOverload", (Value[]){alg_literal("init"), v_arguments}, 2))));
    alg_hold_top = rh_273;
    if (alg_truthy(alg_hold(alg_equal(v_initializer, alg_nil())))) {
        {
            int32_t rh_274 = alg_hold_top;
            (void)((v_initializer = alg_hold(alg_invoke(v_this, "FindMethod", (Value[]){alg_literal("init")}, 1))));
            alg_hold_top = rh_274;
            if (alg_truthy(alg_hold(alg_not_equal(v_initializer, alg_nil())))) {
                if (alg_truthy(alg_hold((or_0 = alg_hold(alg_invoke(v_initializer, "Variadic", NULL, 0)), alg_truthy(or_0) ? or_0 : alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_hold(alg_invoke(v_initializer, "Arity", NULL, 0)))))))) {
                    alg_raise(alg_literal("No matching signature for function."));
                }
            }
            alg_hold_top = rh_274;
        }
    }
    alg_hold_top = rh_273;
    if (alg_truthy(alg_hold(alg_not_equal(v_initializer, alg_nil())))) {
        {
            int32_t rh_275 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_hold(alg_invoke(v_initializer, "Bind", (Value[]){v_instance}, 1)), "Call", (Value[]){v_theinterpreter, v_arguments}, 2)));
            alg_hold_top = rh_275;
        }
    }
    alg_hold_top = rh_273;
    Value ret_32 = v_instance;
    alg_root_top = rt_base;
    return ret_32;
    alg_hold_top = rh_273;
    Value ret_33 = alg_nil();
    alg_root_top = rt_base;
    return ret_33;
}

static Value *roots_ObjClass[] = {
    &k_objclass,
};

void init_ObjClass(void) {
    alg_roots(roots_ObjClass, 1);
    k_objclass = alg_class("ObjClass", alg_nil());
    alg_class_field(k_objclass, "Name", "String");
    alg_class_field(k_objclass, "Methods", "Map");
    alg_class_field(k_objclass, "Superclass", "ObjClass");
    alg_class_field(k_objclass, "IsType", "Boolean");
    alg_class_field(k_objclass, "Fields", "List");
    alg_class_initializer(k_objclass, i_objclass);
    alg_class_method(k_objclass, "Init", m_objclass_init_4_string_objclass_map_list, 4, t_objclass_init_4_string_objclass_map_list);
    alg_class_method(k_objclass, "MethodOfArity", m_objclass_methodofarity_2_string_integer, 2, t_objclass_methodofarity_2_string_integer);
    alg_class_method(k_objclass, "DeclaresField", m_objclass_declaresfield_1_string, 1, t_objclass_declaresfield_1_string);
    alg_class_method(k_objclass, "FindMethod", m_objclass_findmethod_1_string, 1, t_objclass_findmethod_1_string);
    alg_class_method(k_objclass, "FindOverload", m_objclass_findoverload_2_string_list, 2, t_objclass_findoverload_2_string_list);
    alg_class_method(k_objclass, "Fitting", m_objclass_fitting_3_string_list_integer, 3, t_objclass_fitting_3_string_list_integer);
    alg_class_method(k_objclass, "SeedFields", m_objclass_seedfields_2_objinstance, 2, t_objclass_seedfields_2_objinstance);
    alg_class_method(k_objclass, "FieldsInto", m_objclass_fieldsinto_1_map, 1, t_objclass_fieldsinto_1_map);
    alg_class_method(k_objclass, "Arity", m_objclass_arity_0, 0, NULL);
    alg_class_method(k_objclass, "Absorbs", m_objclass_absorbs_1_list, 1, t_objclass_absorbs_1_list);
    alg_class_method(k_objclass, "Variadic", m_objclass_variadic_0, 0, NULL);
    alg_class_method(k_objclass, "ToString", m_objclass_tostring_0, 0, NULL);
    alg_class_method(k_objclass, "Call", m_objclass_call_2, 2, t_objclass_call_2);
    int32_t rh_232 = alg_hold_top;
    alg_hold_top = rh_232;
    alg_hold_top = rh_232;
    init_ObjInstance();
    alg_hold_top = rh_232;
    alg_hold_top = rh_232;
}
