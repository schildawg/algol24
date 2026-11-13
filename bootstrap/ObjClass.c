/* Generated from Algol-24.  Do not edit. */
#include "ObjClass.h"
#include "Token.h"
#include "ObjFunction.h"
#include "ObjInstance.h"

Value f_nomatch(Value **cells, Value *args, int32_t count);
static Value or_0;
static Value or_1;
static Value or_2;
static Value or_3;
Value fn_nomatch;
static const char *t_f_nomatch[] = { "OwnerName : String", "Named : String", "Candidates : List", "Given : Integer" };
Value k_classmethod;
static const char *t_classmethod_init_2_objclass_token[] = { "Receiver : ObjClass", "Name : Token" };
static const char *t_classmethod_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };
Value k_objclass;
static Value or_4;
static const char *t_objclass_init_4_string_objclass_map_list[] = { "Name : String", "Superclass : ObjClass", "Methods : Map", "Fields : List" };
static const char *t_objclass_methodofarity_2_string_integer[] = { "Name : String", "TheArity : Integer" };
static const char *t_objclass_declaresfield_1_string[] = { "Name : String" };
static const char *t_objclass_declaredtypeof_1_string[] = { "Name : String" };
static const char *t_objclass_findmethod_1_string[] = { "Name : String" };
static const char *t_objclass_findoverload_2_string_list[] = { "Name : String", "Arguments : List" };
static const char *t_objclass_fitting_3_string_list_integer[] = { "Name : String", "Arguments : List", "Pass : Integer" };
static const char *t_objclass_candidatesof_1_string[] = { "Name : String" };
static const char *t_objclass_gathercandidates_2_string_list[] = { "Name : String", "Into : List" };
static const char *t_objclass_seedfields_2_objinstance[] = { "Instance : ObjInstance", "TheInterpreter : Any" };
static const char *t_objclass_fieldsinto_1_map[] = { "Into : Map" };
static const char *t_objclass_absorbs_1_list[] = { "Arguments : List" };
static const char *t_objclass_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };

Value f_nomatch(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 4);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_ownername = alg_param_of(args[0], "String", "NoMatch");
    (void)v_ownername;
    alg_root(&v_ownername, 1);
    Value v_named = alg_param_of(args[1], "String", "NoMatch");
    (void)v_named;
    alg_root(&v_named, 1);
    Value v_candidates = alg_param_of(args[2], "List", "NoMatch");
    (void)v_candidates;
    alg_root(&v_candidates, 1);
    Value v_given = alg_param_of(args[3], "Integer", "NoMatch");
    (void)v_given;
    alg_root(&v_given, 1);
    int32_t rh_233 = alg_hold_top;
    if (alg_truthy(alg_hold((or_0 = alg_hold(alg_not_equal(v_candidates, alg_nil())), !alg_truthy(or_0) ? or_0 : alg_hold(alg_equal(alg_hold(alg_property(v_candidates, "Length")), alg_int(1))))))) {
        {
            int32_t rt_234 = alg_root_top;
            int32_t rh_235 = alg_hold_top;
            Value v_only = alg_hold(alg_subscript_get(v_candidates, alg_int(0)));
            (void)v_only;
            alg_root(&v_only, 1);
            alg_hold_top = rh_235;
            if (alg_truthy(alg_hold((or_2 = alg_hold((or_1 = alg_hold(alg_not(alg_hold(alg_invoke(v_only, "Variadic", NULL, 0)))), !alg_truthy(or_1) ? or_1 : alg_hold(alg_greater_equal(alg_hold(alg_invoke(v_only, "Arity", NULL, 0)), alg_int(0))))), !alg_truthy(or_2) ? or_2 : alg_hold(alg_not_equal(v_given, alg_hold(alg_invoke(v_only, "Arity", NULL, 0)))))))) {
                Value ret_0 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expected "), alg_hold(alg_str(alg_hold(alg_invoke(v_only, "Arity", NULL, 0)))))), alg_literal(" arguments but got "))), alg_hold(alg_str(v_given)))), alg_char_value(46)));
                alg_root_top = rt_base;
                return ret_0;
            }
            alg_hold_top = rh_235;
            alg_root_top = rt_234;
        }
    }
    alg_hold_top = rh_233;
    if (alg_truthy(alg_hold(alg_equal(v_named, alg_literal(""))))) {
        Value ret_1 = alg_literal("No matching signature for function.");
        alg_root_top = rt_base;
        return ret_1;
    }
    alg_hold_top = rh_233;
    if (alg_truthy(alg_hold((or_3 = alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){v_named}, 1)), alg_literal("init"))), !alg_truthy(or_3) ? or_3 : alg_hold(alg_not_equal(v_ownername, alg_literal(""))))))) {
        Value ret_2 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("No matching signature for "), v_ownername)), alg_char_value(46)));
        alg_root_top = rt_base;
        return ret_2;
    }
    alg_hold_top = rh_233;
    if (alg_truthy(alg_hold(alg_not_equal(v_ownername, alg_literal(""))))) {
        Value ret_3 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("No matching signature for "), v_ownername)), alg_char_value(46))), v_named)), alg_char_value(46)));
        alg_root_top = rt_base;
        return ret_3;
    }
    alg_hold_top = rh_233;
    Value ret_4 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("No matching signature for "), v_named)), alg_char_value(46)));
    alg_root_top = rt_base;
    return ret_4;
    alg_hold_top = rh_233;
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

static Value i_classmethod(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_classmethod_init_2_objclass_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_receiver = alg_widen(args[0], "ObjClass");
    (void)v_receiver;
    alg_root(&v_receiver, 1);
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_236 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Receiver", v_receiver)));
    alg_hold_top = rh_236;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_236;
    Value ret_6 = alg_nil();
    alg_root_top = rt_base;
    return ret_6;
}

static Value m_classmethod_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_237 = alg_hold_top;
    Value ret_7 = alg_int(1);
    alg_root_top = rt_base;
    return ret_7;
    alg_hold_top = rh_237;
    Value ret_8 = alg_nil();
    alg_root_top = rt_base;
    return ret_8;
}

static Value m_classmethod_call_2(Value v_this, Value *args, int32_t count) {
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
    int32_t rh_238 = alg_hold_top;
    Value ret_9 = alg_hold(alg_invoke(v_theinterpreter, "SatisfiesType", (Value[]){alg_hold(alg_subscript_get(v_arguments, alg_int(0))), alg_hold(alg_property(alg_property(v_this, "Receiver"), "Name"))}, 2));
    alg_root_top = rt_base;
    return ret_9;
    alg_hold_top = rh_238;
    Value ret_10 = alg_nil();
    alg_root_top = rt_base;
    return ret_10;
}

static Value m_classmethod_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_239 = alg_hold_top;
    Value ret_11 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("<fn "), alg_hold(alg_str(alg_hold(alg_property(alg_property(v_this, "Name"), "Lexeme")))))), alg_char_value(62)));
    alg_root_top = rt_base;
    return ret_11;
    alg_hold_top = rh_239;
    Value ret_12 = alg_nil();
    alg_root_top = rt_base;
    return ret_12;
}

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
    int32_t rh_240 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_240;
    (void)(alg_hold(alg_set_property(v_this, "Methods", v_methods)));
    alg_hold_top = rh_240;
    (void)(alg_hold(alg_set_property(v_this, "Superclass", v_superclass)));
    alg_hold_top = rh_240;
    (void)(alg_hold(alg_set_property(v_this, "Fields", v_fields)));
    alg_hold_top = rh_240;
    Value ret_13 = alg_nil();
    alg_root_top = rt_base;
    return ret_13;
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
    int32_t rh_241 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1)))) {
        {
            int32_t rt_242 = alg_root_top;
            int32_t rh_243 = alg_hold_top;
            Value v_found = alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1));
            (void)v_found;
            alg_root(&v_found, 1);
            alg_hold_top = rh_243;
            {
                int32_t rt_244 = alg_root_top;
                Value loop_14 = alg_iterable(v_found);
                (void)loop_14;
                alg_root(&loop_14, 1);
                for (int32_t at_14 = 0; at_14 < alg_iterable_count(loop_14); at_14++) {
                    alg_safe_point();
                    int32_t rt_245 = alg_root_top;
                    Value v_each = alg_iterable_at(loop_14, at_14);
                    (void)v_each;
                    alg_root(&v_each, 1);
                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_invoke(v_each, "Arity", NULL, 0)), v_thearity)))) {
                        Value ret_15 = alg_cast_class(v_each, k_objfunction, "ObjFunction");
                        alg_root_top = rt_base;
                        return ret_15;
                    }
                    alg_root_top = rt_245;
                }
                alg_root_top = rt_244;
            }
            alg_hold_top = rh_243;
            alg_root_top = rt_242;
        }
    }
    alg_hold_top = rh_241;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        Value ret_16 = alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "MethodOfArity", (Value[]){v_name, v_thearity}, 2));
        alg_root_top = rt_base;
        return ret_16;
    }
    alg_hold_top = rh_241;
    Value ret_17 = alg_nil();
    alg_root_top = rt_base;
    return ret_17;
}

static Value m_objclass_declaresfield_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_246 = alg_hold_top;
    {
        int32_t rt_247 = alg_root_top;
        Value loop_18 = alg_iterable(alg_property(v_this, "Fields"));
        (void)loop_18;
        alg_root(&loop_18, 1);
        for (int32_t at_18 = 0; at_18 < alg_iterable_count(loop_18); at_18++) {
            alg_safe_point();
            int32_t rt_248 = alg_root_top;
            Value v_field = alg_iterable_at(loop_18, at_18);
            (void)v_field;
            alg_root(&v_field, 1);
            if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme"))}, 1)), v_name)))) {
                Value ret_19 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_19;
            }
            alg_root_top = rt_248;
        }
        alg_root_top = rt_247;
    }
    alg_hold_top = rh_246;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        Value ret_20 = alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "DeclaresField", (Value[]){v_name}, 1));
        alg_root_top = rt_base;
        return ret_20;
    }
    alg_hold_top = rh_246;
    Value ret_21 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_21;
    alg_hold_top = rh_246;
    Value ret_22 = alg_nil();
    alg_root_top = rt_base;
    return ret_22;
}

static Value m_objclass_declaredtypeof_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_249 = alg_hold_top;
    {
        int32_t rt_250 = alg_root_top;
        Value loop_23 = alg_iterable(alg_property(v_this, "Fields"));
        (void)loop_23;
        alg_root(&loop_23, 1);
        for (int32_t at_23 = 0; at_23 < alg_iterable_count(loop_23); at_23++) {
            alg_safe_point();
            int32_t rt_251 = alg_root_top;
            Value v_field = alg_iterable_at(loop_23, at_23);
            (void)v_field;
            alg_root(&v_field, 1);
            if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme"))}, 1)), v_name)))) {
                Value ret_24 = alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_field, "TypeName"))))}, 1));
                alg_root_top = rt_base;
                return ret_24;
            }
            alg_root_top = rt_251;
        }
        alg_root_top = rt_250;
    }
    alg_hold_top = rh_249;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        Value ret_25 = alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "DeclaredTypeOf", (Value[]){v_name}, 1));
        alg_root_top = rt_base;
        return ret_25;
    }
    alg_hold_top = rh_249;
    Value ret_26 = alg_literal("");
    alg_root_top = rt_base;
    return ret_26;
    alg_hold_top = rh_249;
    Value ret_27 = alg_nil();
    alg_root_top = rt_base;
    return ret_27;
}

static Value m_objclass_findmethod_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_252 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1)))) {
        {
            int32_t rt_253 = alg_root_top;
            int32_t rh_254 = alg_hold_top;
            Value v_found = alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1));
            (void)v_found;
            alg_root(&v_found, 1);
            alg_hold_top = rh_254;
            if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(v_found, "Length")), alg_int(0))))) {
                Value ret_28 = alg_hold(alg_cast_class(alg_subscript_get(v_found, alg_int(0)), k_objfunction, "ObjFunction"));
                alg_root_top = rt_base;
                return ret_28;
            }
            alg_hold_top = rh_254;
            alg_root_top = rt_253;
        }
    }
    alg_hold_top = rh_252;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        {
            int32_t rh_255 = alg_hold_top;
            Value ret_29 = alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "FindMethod", (Value[]){v_name}, 1));
            alg_root_top = rt_base;
            return ret_29;
            alg_hold_top = rh_255;
        }
    }
    alg_hold_top = rh_252;
    Value ret_30 = alg_nil();
    alg_root_top = rt_base;
    return ret_30;
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
    int32_t rh_256 = alg_hold_top;
    {
        int32_t rt_257 = alg_root_top;
        int32_t rh_258 = alg_hold_top;
        Value v_pass = (alg_declared(d_exact, "EXACT"), v_exact);
        (void)v_pass;
        alg_root(&v_pass, 1);
        alg_hold_top = rh_258;
        {
            int32_t rh_259 = alg_hold_top;
            for (; (alg_hold_top = rh_259, alg_truthy(alg_hold(alg_less_equal(v_pass, (alg_declared(d_absorbing, "ABSORBING"), v_absorbing))))); (alg_hold_top = rh_259, (v_pass = alg_hold(alg_add(v_pass, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_260 = alg_root_top;
                    int32_t rh_261 = alg_hold_top;
                    Value v_found = alg_hold(alg_invoke(v_this, "Fitting", (Value[]){v_name, v_arguments, v_pass}, 3));
                    (void)v_found;
                    alg_root(&v_found, 1);
                    alg_hold_top = rh_261;
                    if (alg_truthy(alg_hold(alg_not_equal(v_found, alg_nil())))) {
                        Value ret_31 = v_found;
                        alg_root_top = rt_base;
                        return ret_31;
                    }
                    alg_hold_top = rh_261;
                    alg_root_top = rt_260;
                }
            }
        }
        alg_hold_top = rh_258;
        alg_root_top = rt_257;
    }
    alg_hold_top = rh_256;
    Value ret_32 = alg_nil();
    alg_root_top = rt_base;
    return ret_32;
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
    int32_t rh_262 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1)))) {
        {
            int32_t rt_263 = alg_root_top;
            int32_t rh_264 = alg_hold_top;
            Value v_candidates = alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1));
            (void)v_candidates;
            alg_root(&v_candidates, 1);
            alg_hold_top = rh_264;
            {
                int32_t rt_265 = alg_root_top;
                Value loop_33 = alg_iterable(v_candidates);
                (void)loop_33;
                alg_root(&loop_33, 1);
                for (int32_t at_33 = 0; at_33 < alg_iterable_count(loop_33); at_33++) {
                    alg_safe_point();
                    int32_t rt_266 = alg_root_top;
                    Value v_candidate = alg_iterable_at(loop_33, at_33);
                    (void)v_candidate;
                    alg_root(&v_candidate, 1);
                    if (alg_truthy(alg_hold(alg_invoke(v_candidate, "Selects", (Value[]){v_arguments, v_pass}, 2)))) {
                        Value ret_34 = alg_cast_class(v_candidate, k_objfunction, "ObjFunction");
                        alg_root_top = rt_base;
                        return ret_34;
                    }
                    alg_root_top = rt_266;
                }
                alg_root_top = rt_265;
            }
            alg_hold_top = rh_264;
            alg_root_top = rt_263;
        }
    }
    alg_hold_top = rh_262;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        Value ret_35 = alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "Fitting", (Value[]){v_name, v_arguments, v_pass}, 3));
        alg_root_top = rt_base;
        return ret_35;
    }
    alg_hold_top = rh_262;
    Value ret_36 = alg_nil();
    alg_root_top = rt_base;
    return ret_36;
}

static Value m_objclass_candidatesof_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_267 = alg_hold_top;
    Value v_found = alg_nil();
    (void)v_found;
    alg_root(&v_found, 1);
    alg_hold_top = rh_267;
    (void)((v_found = alg_hold(alg_list())));
    alg_hold_top = rh_267;
    (void)(alg_hold(alg_invoke(v_this, "GatherCandidates", (Value[]){v_name, v_found}, 2)));
    alg_hold_top = rh_267;
    Value ret_37 = v_found;
    alg_root_top = rt_base;
    return ret_37;
    alg_hold_top = rh_267;
    Value ret_38 = alg_nil();
    alg_root_top = rt_base;
    return ret_38;
}

static Value m_objclass_gathercandidates_2_string_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_into = alg_widen(args[1], "List");
    (void)v_into;
    alg_root(&v_into, 1);
    int32_t rh_268 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Contains", (Value[]){v_name}, 1)))) {
        {
            int32_t rt_269 = alg_root_top;
            Value loop_39 = alg_iterable(alg_hold(alg_invoke(alg_property(v_this, "Methods"), "Get", (Value[]){v_name}, 1)));
            (void)loop_39;
            alg_root(&loop_39, 1);
            for (int32_t at_39 = 0; at_39 < alg_iterable_count(loop_39); at_39++) {
                alg_safe_point();
                int32_t rt_270 = alg_root_top;
                Value v_candidate = alg_iterable_at(loop_39, at_39);
                (void)v_candidate;
                alg_root(&v_candidate, 1);
                (void)(alg_hold(alg_invoke(v_into, "Add", (Value[]){v_candidate}, 1)));
                alg_root_top = rt_270;
            }
            alg_root_top = rt_269;
        }
    }
    alg_hold_top = rh_268;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "GatherCandidates", (Value[]){v_name, v_into}, 2)));
    }
    alg_hold_top = rh_268;
    Value ret_40 = alg_nil();
    alg_root_top = rt_base;
    return ret_40;
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
    int32_t rh_271 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "SeedFields", (Value[]){v_instance, v_theinterpreter}, 2)));
    }
    alg_hold_top = rh_271;
    {
        int32_t rt_272 = alg_root_top;
        int32_t rh_273 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_273;
        {
            int32_t rh_274 = alg_hold_top;
            for (; (alg_hold_top = rh_274, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_property(v_this, "Fields"), "Length")))))); (alg_hold_top = rh_274, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_275 = alg_root_top;
                    int32_t rh_276 = alg_hold_top;
                    Value v_field = alg_hold(alg_subscript_get(alg_property(v_this, "Fields"), v_i));
                    (void)v_field;
                    alg_root(&v_field, 1);
                    alg_hold_top = rh_276;
                    Value v_value = alg_nil();
                    (void)v_value;
                    alg_root(&v_value, 1);
                    alg_hold_top = rh_276;
                    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_field, "Initializer")), alg_nil())))) {
                        (void)((v_value = alg_hold(alg_invoke(v_theinterpreter, "Widen", (Value[]){alg_hold(alg_invoke(v_theinterpreter, "Evaluate", (Value[]){alg_hold(alg_property(v_field, "Initializer"))}, 1)), alg_hold(alg_str(alg_hold(alg_property(v_field, "TypeName"))))}, 2))));
                    }
                    alg_hold_top = rh_276;
                    (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_instance, "Fields")), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme"))}, 1)), v_value}, 2)));
                    alg_hold_top = rh_276;
                    alg_root_top = rt_275;
                }
            }
        }
        alg_hold_top = rh_273;
        alg_root_top = rt_272;
    }
    alg_hold_top = rh_271;
    Value ret_41 = alg_nil();
    alg_root_top = rt_base;
    return ret_41;
}

static Value m_objclass_fieldsinto_1_map(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_into = alg_widen(args[0], "Map");
    (void)v_into;
    alg_root(&v_into, 1);
    int32_t rh_277 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Superclass"), alg_nil())))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Superclass"), "FieldsInto", (Value[]){v_into}, 1)));
    }
    alg_hold_top = rh_277;
    {
        int32_t rt_278 = alg_root_top;
        int32_t rh_279 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_279;
        {
            int32_t rh_280 = alg_hold_top;
            for (; (alg_hold_top = rh_280, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_property(v_this, "Fields"), "Length")))))); (alg_hold_top = rh_280, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_281 = alg_root_top;
                    int32_t rh_282 = alg_hold_top;
                    Value v_field = alg_hold(alg_subscript_get(alg_property(v_this, "Fields"), v_i));
                    (void)v_field;
                    alg_root(&v_field, 1);
                    alg_hold_top = rh_282;
                    (void)(alg_hold(alg_invoke(v_into, "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme")))), alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_field, "TypeName"))))}, 1))}, 2)));
                    alg_hold_top = rh_282;
                    alg_root_top = rt_281;
                }
            }
        }
        alg_hold_top = rh_279;
        alg_root_top = rt_278;
    }
    alg_hold_top = rh_277;
    Value ret_42 = alg_nil();
    alg_root_top = rt_base;
    return ret_42;
}

static Value m_objclass_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_283 = alg_hold_top;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    alg_hold_top = rh_283;
    (void)((v_initializer = alg_hold(alg_invoke(v_this, "FindMethod", (Value[]){alg_literal("init")}, 1))));
    alg_hold_top = rh_283;
    if (alg_truthy(alg_hold(alg_equal(v_initializer, alg_nil())))) {
        Value ret_43 = alg_int(0);
        alg_root_top = rt_base;
        return ret_43;
    }
    alg_hold_top = rh_283;
    Value ret_44 = alg_hold(alg_cast_kind(alg_invoke(v_initializer, "Arity", NULL, 0), ALG_KIND_INTEGER, "Integer"));
    alg_root_top = rt_base;
    return ret_44;
    alg_hold_top = rh_283;
    Value ret_45 = alg_nil();
    alg_root_top = rt_base;
    return ret_45;
}

static Value m_objclass_absorbs_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    int32_t rh_284 = alg_hold_top;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    alg_hold_top = rh_284;
    (void)((v_initializer = alg_hold(alg_invoke(v_this, "FindOverload", (Value[]){alg_literal("init"), v_arguments}, 2))));
    alg_hold_top = rh_284;
    if (alg_truthy(alg_hold(alg_equal(v_initializer, alg_nil())))) {
        (void)((v_initializer = alg_hold(alg_invoke(v_this, "FindMethod", (Value[]){alg_literal("init")}, 1))));
    }
    alg_hold_top = rh_284;
    if (alg_truthy(alg_hold(alg_equal(v_initializer, alg_nil())))) {
        Value ret_46 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_46;
    }
    alg_hold_top = rh_284;
    Value ret_47 = alg_hold(alg_cast_kind(alg_invoke(v_initializer, "Absorbs", (Value[]){v_arguments}, 1), ALG_KIND_BOOLEAN, "Boolean"));
    alg_root_top = rt_base;
    return ret_47;
    alg_hold_top = rh_284;
    Value ret_48 = alg_nil();
    alg_root_top = rt_base;
    return ret_48;
}

static Value m_objclass_variadic_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_285 = alg_hold_top;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    alg_hold_top = rh_285;
    (void)((v_initializer = alg_hold(alg_invoke(v_this, "FindMethod", (Value[]){alg_literal("init")}, 1))));
    alg_hold_top = rh_285;
    if (alg_truthy(alg_hold(alg_equal(v_initializer, alg_nil())))) {
        Value ret_49 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_49;
    }
    alg_hold_top = rh_285;
    Value ret_50 = alg_hold(alg_cast_kind(alg_invoke(v_initializer, "Variadic", NULL, 0), ALG_KIND_BOOLEAN, "Boolean"));
    alg_root_top = rt_base;
    return ret_50;
    alg_hold_top = rh_285;
    Value ret_51 = alg_nil();
    alg_root_top = rt_base;
    return ret_51;
}

static Value m_objclass_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_286 = alg_hold_top;
    Value ret_52 = alg_property(v_this, "Name");
    alg_root_top = rt_base;
    return ret_52;
    alg_hold_top = rh_286;
    Value ret_53 = alg_nil();
    alg_root_top = rt_base;
    return ret_53;
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
    int32_t rh_287 = alg_hold_top;
    Value v_instance = alg_nil();
    (void)v_instance;
    alg_root(&v_instance, 1);
    alg_hold_top = rh_287;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    alg_hold_top = rh_287;
    if (alg_truthy(alg_property(v_this, "IsType"))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_str(alg_property(v_this, "Name"))), alg_literal(" is a type rather than a class, and cannot be constructed."))));
    }
    alg_hold_top = rh_287;
    (void)((v_instance = alg_hold(alg_new(k_objinstance, (Value[]){v_this}, 1))));
    alg_hold_top = rh_287;
    (void)(alg_hold(alg_invoke(v_this, "SeedFields", (Value[]){v_instance, v_theinterpreter}, 2)));
    alg_hold_top = rh_287;
    (void)((v_initializer = alg_hold(alg_invoke(v_this, "FindOverload", (Value[]){alg_literal("init"), v_arguments}, 2))));
    alg_hold_top = rh_287;
    if (alg_truthy(alg_hold(alg_equal(v_initializer, alg_nil())))) {
        {
            int32_t rh_288 = alg_hold_top;
            (void)((v_initializer = alg_hold(alg_invoke(v_this, "FindMethod", (Value[]){alg_literal("init")}, 1))));
            alg_hold_top = rh_288;
            if (alg_truthy(alg_hold(alg_equal(v_initializer, alg_nil())))) {
                {
                    int32_t rh_289 = alg_hold_top;
                    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(0))))) {
                        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expected 0 arguments but got "), alg_hold(alg_str(alg_hold(alg_property(v_arguments, "Length")))))), alg_char_value(46))));
                    }
                    alg_hold_top = rh_289;
                }
            } else {
                {
                    int32_t rh_290 = alg_hold_top;
                    if (alg_truthy(alg_hold((or_4 = alg_hold(alg_invoke(v_initializer, "Variadic", NULL, 0)), alg_truthy(or_4) ? or_4 : alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_hold(alg_invoke(v_initializer, "Arity", NULL, 0)))))))) {
                        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("No matching signature for "), alg_property(v_this, "Name"))), alg_char_value(46))));
                    }
                    alg_hold_top = rh_290;
                    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Absorbs", (Value[]){v_arguments}, 1)))))) {
                        alg_raise(alg_hold(f_nomatch(NULL, (Value[]){alg_literal(""), alg_property(v_this, "Name"), alg_hold(alg_invoke(v_this, "CandidatesOf", (Value[]){alg_literal("init")}, 1)), alg_hold(alg_property(v_arguments, "Length"))}, 4)));
                    }
                    alg_hold_top = rh_290;
                }
            }
            alg_hold_top = rh_288;
        }
    }
    alg_hold_top = rh_287;
    if (alg_truthy(alg_hold(alg_not_equal(v_initializer, alg_nil())))) {
        {
            int32_t rh_291 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_hold(alg_invoke(v_initializer, "Bind", (Value[]){v_instance}, 1)), "Call", (Value[]){v_theinterpreter, v_arguments}, 2)));
            alg_hold_top = rh_291;
        }
    }
    alg_hold_top = rh_287;
    Value ret_54 = v_instance;
    alg_root_top = rt_base;
    return ret_54;
    alg_hold_top = rh_287;
    Value ret_55 = alg_nil();
    alg_root_top = rt_base;
    return ret_55;
}

static Value *roots_ObjClass[] = {
    &fn_nomatch,
    &k_classmethod,
    &k_objclass,
};

void init_ObjClass(void) {
    alg_roots(roots_ObjClass, 3);
    k_classmethod = alg_class("ClassMethod", alg_nil());
    k_objclass = alg_class("ObjClass", alg_nil());
    fn_nomatch = alg_closure("NoMatch", f_nomatch, NULL, 0, 4, t_f_nomatch);
    alg_class_field(k_classmethod, "Receiver", "ObjClass");
    alg_class_field(k_classmethod, "Name", "Token");
    alg_class_initializer(k_classmethod, i_classmethod);
    alg_class_method(k_classmethod, "Init", m_classmethod_init_2_objclass_token, 2, t_classmethod_init_2_objclass_token);
    alg_class_method(k_classmethod, "Arity", m_classmethod_arity_0, 0, NULL);
    alg_class_method(k_classmethod, "Call", m_classmethod_call_2, 2, t_classmethod_call_2);
    alg_class_method(k_classmethod, "ToString", m_classmethod_tostring_0, 0, NULL);
    alg_class_field(k_objclass, "Name", "String");
    alg_class_field(k_objclass, "Methods", "Map");
    alg_class_field(k_objclass, "Superclass", "ObjClass");
    alg_class_field(k_objclass, "IsType", "Boolean");
    alg_class_field(k_objclass, "Fields", "List");
    alg_class_initializer(k_objclass, i_objclass);
    alg_class_method(k_objclass, "Init", m_objclass_init_4_string_objclass_map_list, 4, t_objclass_init_4_string_objclass_map_list);
    alg_class_method(k_objclass, "MethodOfArity", m_objclass_methodofarity_2_string_integer, 2, t_objclass_methodofarity_2_string_integer);
    alg_class_method(k_objclass, "DeclaresField", m_objclass_declaresfield_1_string, 1, t_objclass_declaresfield_1_string);
    alg_class_method(k_objclass, "DeclaredTypeOf", m_objclass_declaredtypeof_1_string, 1, t_objclass_declaredtypeof_1_string);
    alg_class_method(k_objclass, "FindMethod", m_objclass_findmethod_1_string, 1, t_objclass_findmethod_1_string);
    alg_class_method(k_objclass, "FindOverload", m_objclass_findoverload_2_string_list, 2, t_objclass_findoverload_2_string_list);
    alg_class_method(k_objclass, "Fitting", m_objclass_fitting_3_string_list_integer, 3, t_objclass_fitting_3_string_list_integer);
    alg_class_method(k_objclass, "CandidatesOf", m_objclass_candidatesof_1_string, 1, t_objclass_candidatesof_1_string);
    alg_class_method(k_objclass, "GatherCandidates", m_objclass_gathercandidates_2_string_list, 2, t_objclass_gathercandidates_2_string_list);
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
    alg_hold_top = rh_232;
    alg_hold_top = rh_232;
}
