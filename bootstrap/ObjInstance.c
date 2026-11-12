/* Generated from Algol-24.  Do not edit. */
#include "ObjInstance.h"
#include "ObjClass.h"
#include "ObjFunction.h"
#include "Token.h"

Value f_setinstanceshown(Value **cells, Value *args, int32_t count);
Value v_instanceVshown;
bool d_instanceVshown;
Value fn_setinstanceshown;
static const char *t_f_setinstanceshown[] = { "Answering : Any" };
Value k_objinstance;
static const char *t_objinstance_init_1_objclass[] = { "Klass : ObjClass" };
static const char *t_objinstance_get_1_token[] = { "Name : Token" };
static const char *t_objinstance_getfield_1_token[] = { "Name : Token" };
static const char *t_objinstance_set_2_token[] = { "Name : Token", "Value : Any" };
Value k_objsingleton;
static const char *t_objsingleton_init_2_objclass[] = { "Klass : ObjClass", "TheInterpreter : Any" };
static const char *t_objsingleton_get_1_token[] = { "Name : Token" };
static const char *t_objsingleton_getfield_1_token[] = { "Name : Token" };
static const char *t_objsingleton_set_2_token[] = { "Name : Token", "Value : Any" };

Value f_setinstanceshown(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_answering = args[0];
    (void)v_answering;
    alg_root(&v_answering, 1);
    int32_t rh_219 = alg_hold_top;
    (void)((alg_declared(d_instanceVshown, "INSTANCE_SHOWN"), (v_instanceVshown = v_answering)));
    alg_hold_top = rh_219;
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

static Value i_objinstance(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Klass", alg_nil());
    alg_set_property(v_this, "Fields", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_objinstance_init_1_objclass(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_klass = alg_widen(args[0], "ObjClass");
    (void)v_klass;
    alg_root(&v_klass, 1);
    int32_t rh_220 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Klass", v_klass)));
    alg_hold_top = rh_220;
    (void)(alg_hold(alg_set_property(v_this, "Fields", alg_hold(alg_map()))));
    alg_hold_top = rh_220;
    Value ret_1 = alg_nil();
    alg_root_top = rt_base;
    return ret_1;
}

static Value m_objinstance_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_221 = alg_hold_top;
    Value v_method = alg_nil();
    (void)v_method;
    alg_root(&v_method, 1);
    alg_hold_top = rh_221;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1)), alg_literal("classname"))))) {
        Value ret_2 = alg_hold(alg_property(alg_property(v_this, "Klass"), "Name"));
        alg_root_top = rt_base;
        return ret_2;
    }
    alg_hold_top = rh_221;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Fields"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1)))) {
        {
            int32_t rh_222 = alg_hold_top;
            Value ret_3 = alg_hold(alg_invoke(alg_property(v_this, "Fields"), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1));
            alg_root_top = rt_base;
            return ret_3;
            alg_hold_top = rh_222;
        }
    }
    alg_hold_top = rh_221;
    (void)((v_method = alg_hold(alg_invoke(alg_property(v_this, "Klass"), "FindMethod", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1))));
    alg_hold_top = rh_221;
    if (alg_truthy(alg_hold(alg_not_equal(v_method, alg_nil())))) {
        Value ret_4 = alg_hold(alg_invoke(v_method, "Bind", (Value[]){v_this}, 1));
        alg_root_top = rt_base;
        return ret_4;
    }
    alg_hold_top = rh_221;
    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined property '"), alg_hold(alg_property(v_name, "Lexeme")))), alg_literal("'."))));
    alg_hold_top = rh_221;
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

static Value m_objinstance_getfield_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_223 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Fields"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1)))))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined property '"), alg_hold(alg_property(v_name, "Lexeme")))), alg_literal("'."))));
    }
    alg_hold_top = rh_223;
    Value ret_6 = alg_hold(alg_invoke(alg_property(v_this, "Fields"), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1));
    alg_root_top = rt_base;
    return ret_6;
    alg_hold_top = rh_223;
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
}

static Value m_objinstance_set_2_token(Value v_this, Value *args, int32_t count) {
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
    int32_t rh_224 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Fields"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1))}, 1)))))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined property '"), alg_hold(alg_property(v_name, "Lexeme")))), alg_literal("'."))));
    }
    alg_hold_top = rh_224;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Fields"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_name, "Lexeme"))}, 1)), v_value}, 2)));
    alg_hold_top = rh_224;
    Value ret_8 = alg_nil();
    alg_root_top = rt_base;
    return ret_8;
}

static Value m_objinstance_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_225 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not_equal((alg_declared(d_instanceVshown, "INSTANCE_SHOWN"), v_instanceVshown), alg_nil())))) {
        Value ret_9 = alg_hold(alg_str(alg_hold(alg_call((alg_declared(d_instanceVshown, "INSTANCE_SHOWN"), v_instanceVshown), (Value[]){v_this}, 1))));
        alg_root_top = rt_base;
        return ret_9;
    }
    alg_hold_top = rh_225;
    Value ret_10 = alg_hold(alg_add(alg_hold(alg_property(alg_property(v_this, "Klass"), "Name")), alg_literal(" instance")));
    alg_root_top = rt_base;
    return ret_10;
    alg_hold_top = rh_225;
    Value ret_11 = alg_nil();
    alg_root_top = rt_base;
    return ret_11;
}

static Value i_objsingleton(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "TheInterpreter", alg_nil());
    alg_set_property(v_this, "TheInstance", alg_widen(alg_nil(), "ObjInstance"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_objsingleton_init_2_objclass(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_klass = alg_widen(args[0], "ObjClass");
    (void)v_klass;
    alg_root(&v_klass, 1);
    Value v_theinterpreter = args[1];
    (void)v_theinterpreter;
    alg_root(&v_theinterpreter, 1);
    int32_t rh_226 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Klass", v_klass)));
    alg_hold_top = rh_226;
    (void)(alg_hold(alg_set_property(v_this, "Fields", alg_hold(alg_map()))));
    alg_hold_top = rh_226;
    (void)(alg_hold(alg_set_property(v_this, "TheInterpreter", v_theinterpreter)));
    alg_hold_top = rh_226;
    Value ret_12 = alg_nil();
    alg_root_top = rt_base;
    return ret_12;
}

static Value m_objsingleton_instance_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_227 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "TheInstance"), alg_nil())))) {
        (void)(alg_set_property(v_this, "TheInstance", alg_hold(alg_cast_class(alg_invoke(alg_property(v_this, "Klass"), "Call", (Value[]){alg_property(v_this, "TheInterpreter"), alg_hold(alg_list())}, 2), k_objinstance, "ObjInstance"))));
    }
    alg_hold_top = rh_227;
    Value ret_13 = alg_property(v_this, "TheInstance");
    alg_root_top = rt_base;
    return ret_13;
    alg_hold_top = rh_227;
    Value ret_14 = alg_nil();
    alg_root_top = rt_base;
    return ret_14;
}

static Value m_objsingleton_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_228 = alg_hold_top;
    Value ret_15 = alg_hold(alg_invoke(alg_hold(alg_invoke(v_this, "Instance", NULL, 0)), "Get", (Value[]){v_name}, 1));
    alg_root_top = rt_base;
    return ret_15;
    alg_hold_top = rh_228;
    Value ret_16 = alg_nil();
    alg_root_top = rt_base;
    return ret_16;
}

static Value m_objsingleton_getfield_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_229 = alg_hold_top;
    Value ret_17 = alg_hold(alg_invoke(alg_hold(alg_invoke(v_this, "Instance", NULL, 0)), "GetField", (Value[]){v_name}, 1));
    alg_root_top = rt_base;
    return ret_17;
    alg_hold_top = rh_229;
    Value ret_18 = alg_nil();
    alg_root_top = rt_base;
    return ret_18;
}

static Value m_objsingleton_set_2_token(Value v_this, Value *args, int32_t count) {
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
    int32_t rh_230 = alg_hold_top;
    (void)(alg_hold(alg_invoke(alg_hold(alg_invoke(v_this, "Instance", NULL, 0)), "Set", (Value[]){v_name, v_value}, 2)));
    alg_hold_top = rh_230;
    Value ret_19 = alg_nil();
    alg_root_top = rt_base;
    return ret_19;
}

static Value m_objsingleton_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_231 = alg_hold_top;
    Value ret_20 = alg_hold(alg_property(alg_property(v_this, "Klass"), "Name"));
    alg_root_top = rt_base;
    return ret_20;
    alg_hold_top = rh_231;
    Value ret_21 = alg_nil();
    alg_root_top = rt_base;
    return ret_21;
}

static Value *roots_ObjInstance[] = {
    &v_instanceVshown,
    &fn_setinstanceshown,
    &k_objinstance,
    &k_objsingleton,
};

void init_ObjInstance(void) {
    alg_roots(roots_ObjInstance, 4);
    k_objinstance = alg_class("ObjInstance", alg_nil());
    k_objsingleton = alg_class("ObjSingleton", alg_nil());
    fn_setinstanceshown = alg_closure("SetInstanceShown", f_setinstanceshown, NULL, 0, 1, t_f_setinstanceshown);
    alg_class_field(k_objinstance, "Klass", "ObjClass");
    alg_class_field(k_objinstance, "Fields", "Map");
    alg_class_initializer(k_objinstance, i_objinstance);
    alg_class_method(k_objinstance, "Init", m_objinstance_init_1_objclass, 1, t_objinstance_init_1_objclass);
    alg_class_method(k_objinstance, "Get", m_objinstance_get_1_token, 1, t_objinstance_get_1_token);
    alg_class_method(k_objinstance, "GetField", m_objinstance_getfield_1_token, 1, t_objinstance_getfield_1_token);
    alg_class_method(k_objinstance, "Set", m_objinstance_set_2_token, 2, t_objinstance_set_2_token);
    alg_class_method(k_objinstance, "ToString", m_objinstance_tostring_0, 0, NULL);
    alg_class_super(k_objsingleton, k_objinstance);
    alg_class_field(k_objsingleton, "TheInterpreter", "Any");
    alg_class_field(k_objsingleton, "TheInstance", "ObjInstance");
    alg_class_initializer(k_objsingleton, i_objsingleton);
    alg_class_method(k_objsingleton, "Init", m_objsingleton_init_2_objclass, 2, t_objsingleton_init_2_objclass);
    alg_class_method(k_objsingleton, "Instance", m_objsingleton_instance_0, 0, NULL);
    alg_class_method(k_objsingleton, "Get", m_objsingleton_get_1_token, 1, t_objsingleton_get_1_token);
    alg_class_method(k_objsingleton, "GetField", m_objsingleton_getfield_1_token, 1, t_objsingleton_getfield_1_token);
    alg_class_method(k_objsingleton, "Set", m_objsingleton_set_2_token, 2, t_objsingleton_set_2_token);
    alg_class_method(k_objsingleton, "ToString", m_objsingleton_tostring_0, 0, NULL);
    int32_t rh_218 = alg_hold_top;
    alg_hold_top = rh_218;
    alg_hold_top = rh_218;
    alg_hold_top = rh_218;
    v_instanceVshown = alg_nil();
    d_instanceVshown = true;
    alg_hold_top = rh_218;
    alg_hold_top = rh_218;
    alg_hold_top = rh_218;
    alg_hold_top = rh_218;
}
