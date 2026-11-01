/* Generated from Algol-24.  Do not edit. */
#include "ObjInstance.h"
#include "ObjClass.h"
#include "ObjFunction.h"
#include "Token.h"

Value k_objinstance;
static const char *t_objinstance_init_1_objclass[] = { "Klass : ObjClass" };
static const char *t_objinstance_get_1_token[] = { "Name : Token" };
static const char *t_objinstance_set_2_token[] = { "Name : Token", "Value : Any" };
Value k_objsingleton;
static const char *t_objsingleton_init_2_objclass[] = { "Klass : ObjClass", "TheInterpreter : Any" };
static const char *t_objsingleton_get_1_token[] = { "Name : Token" };
static const char *t_objsingleton_set_2_token[] = { "Name : Token", "Value : Any" };

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
    (void)(alg_set_property(v_this, "Klass", v_klass));
    (void)(alg_set_property(v_this, "Fields", alg_map()));
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

static Value m_objinstance_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_method = alg_nil();
    (void)v_method;
    alg_root(&v_method, 1);
    if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), alg_string("classname")))) {
        Value ret_1 = alg_property(alg_property(v_this, "Klass"), "Name");
        alg_root_top = rt_base;
        return ret_1;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Fields"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
        {
            Value ret_2 = alg_invoke(alg_property(v_this, "Fields"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1);
            alg_root_top = rt_base;
            return ret_2;
        }
    }
    (void)((v_method = alg_invoke(alg_property(v_this, "Klass"), "FindMethod", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1)));
    if (alg_truthy(alg_not_equal(v_method, alg_nil()))) {
        Value ret_3 = alg_invoke(v_method, "Bind", (Value[]){v_this}, 1);
        alg_root_top = rt_base;
        return ret_3;
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_property(v_name, "Lexeme")), alg_string("'.")));
    Value ret_4 = alg_nil();
    alg_root_top = rt_base;
    return ret_4;
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
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Fields"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1)))) {
        alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_property(v_name, "Lexeme")), alg_string("'.")));
    }
    (void)(alg_invoke(alg_property(v_this, "Fields"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_value}, 2));
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

static Value m_objinstance_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_6 = alg_add(alg_property(alg_property(v_this, "Klass"), "Name"), alg_string(" instance"));
    alg_root_top = rt_base;
    return ret_6;
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
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
    (void)(alg_set_property(v_this, "Klass", v_klass));
    (void)(alg_set_property(v_this, "Fields", alg_map()));
    (void)(alg_set_property(v_this, "TheInterpreter", v_theinterpreter));
    Value ret_8 = alg_nil();
    alg_root_top = rt_base;
    return ret_8;
}

static Value m_objsingleton_instance_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_equal(alg_property(v_this, "TheInstance"), alg_nil()))) {
        (void)(alg_set_property(v_this, "TheInstance", alg_cast(alg_invoke(alg_property(v_this, "Klass"), "Call", (Value[]){alg_property(v_this, "TheInterpreter"), alg_list()}, 2), "ObjInstance")));
    }
    Value ret_9 = alg_property(v_this, "TheInstance");
    alg_root_top = rt_base;
    return ret_9;
    Value ret_10 = alg_nil();
    alg_root_top = rt_base;
    return ret_10;
}

static Value m_objsingleton_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_11 = alg_invoke(alg_invoke(v_this, "Instance", NULL, 0), "Get", (Value[]){v_name}, 1);
    alg_root_top = rt_base;
    return ret_11;
    Value ret_12 = alg_nil();
    alg_root_top = rt_base;
    return ret_12;
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
    (void)(alg_invoke(alg_invoke(v_this, "Instance", NULL, 0), "Set", (Value[]){v_name, v_value}, 2));
    Value ret_13 = alg_nil();
    alg_root_top = rt_base;
    return ret_13;
}

static Value m_objsingleton_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_14 = alg_property(alg_property(v_this, "Klass"), "Name");
    alg_root_top = rt_base;
    return ret_14;
    Value ret_15 = alg_nil();
    alg_root_top = rt_base;
    return ret_15;
}

static Value *roots_ObjInstance[] = {
    &k_objinstance,
    &k_objsingleton,
};

void init_ObjInstance(void) {
    alg_roots(roots_ObjInstance, 2);
    k_objinstance = alg_class("ObjInstance", alg_nil());
    k_objsingleton = alg_class("ObjSingleton", alg_nil());
    alg_class_field(k_objinstance, "Klass");
    alg_class_field(k_objinstance, "Fields");
    alg_class_initializer(k_objinstance, i_objinstance);
    alg_class_method(k_objinstance, "Init", m_objinstance_init_1_objclass, 1, t_objinstance_init_1_objclass);
    alg_class_method(k_objinstance, "Get", m_objinstance_get_1_token, 1, t_objinstance_get_1_token);
    alg_class_method(k_objinstance, "Set", m_objinstance_set_2_token, 2, t_objinstance_set_2_token);
    alg_class_method(k_objinstance, "ToString", m_objinstance_tostring_0, 0, NULL);
    alg_class_super(k_objsingleton, k_objinstance);
    alg_class_field(k_objsingleton, "TheInterpreter");
    alg_class_field(k_objsingleton, "TheInstance");
    alg_class_initializer(k_objsingleton, i_objsingleton);
    alg_class_method(k_objsingleton, "Init", m_objsingleton_init_2_objclass, 2, t_objsingleton_init_2_objclass);
    alg_class_method(k_objsingleton, "Instance", m_objsingleton_instance_0, 0, NULL);
    alg_class_method(k_objsingleton, "Get", m_objsingleton_get_1_token, 1, t_objsingleton_get_1_token);
    alg_class_method(k_objsingleton, "Set", m_objsingleton_set_2_token, 2, t_objsingleton_set_2_token);
    alg_class_method(k_objsingleton, "ToString", m_objsingleton_tostring_0, 0, NULL);
}
