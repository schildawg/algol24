/* Generated from Algol-24.  Do not edit. */
#include "ObjInstance.h"
#include "ObjClass.h"
#include "ObjFunction.h"
#include "Token.h"

Value k_objinstance;
static const char *t_objinstance_init_1_objclass[] = { "ObjClass" };
static const char *t_objinstance_get_1_token[] = { "Token" };
static const char *t_objinstance_set_2_token[] = { "Token", "Any" };
Value k_objsingleton;
static const char *t_objsingleton_init_2_objclass[] = { "ObjClass", "Any" };
static const char *t_objsingleton_get_1_token[] = { "Token" };
static const char *t_objsingleton_set_2_token[] = { "Token", "Any" };

static Value i_objinstance(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Klass", alg_nil());
    alg_set_property(v_this, "Fields", alg_nil());
    return alg_nil();
}

static Value m_objinstance_init_1_objclass(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_klass = alg_widen(args[0], "ObjClass");
    (void)v_klass;
    (void)(alg_set_property(v_this, "Klass", alg_widen(v_klass, "ObjClass")));
    (void)(alg_set_property(v_this, "Fields", alg_widen(alg_map(), "Map")));
    return alg_nil();
}

static Value m_objinstance_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_method = alg_nil();
    (void)v_method;
    if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), alg_string("classname")))) {
        return alg_property(alg_property(v_this, "Klass"), "Name");
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Fields"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1))) {
        {
            return alg_invoke(alg_property(v_this, "Fields"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1);
        }
    }
    (void)((v_method = alg_widen(alg_invoke(alg_property(v_this, "Klass"), "FindMethod", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1)}, 1), "ObjFunction")));
    if (alg_truthy(alg_not_equal(v_method, alg_nil()))) {
        return alg_invoke(v_method, "Bind", (Value[]){v_this}, 1);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_property(v_name, "Lexeme")), alg_string("'.")));
    return alg_nil();
}

static Value m_objinstance_set_2_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_value = args[1];
    (void)v_value;
    (void)(alg_invoke(alg_property(v_this, "Fields"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_name, "Lexeme")}, 1), v_value}, 2));
    return alg_nil();
}

static Value m_objinstance_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_add(alg_property(alg_property(v_this, "Klass"), "Name"), alg_string(" instance"));
    return alg_nil();
}

static Value i_objsingleton(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "TheInterpreter", alg_nil());
    alg_set_property(v_this, "TheInstance", alg_widen(alg_nil(), "ObjInstance"));
    return alg_nil();
}

static Value m_objsingleton_init_2_objclass(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_klass = alg_widen(args[0], "ObjClass");
    (void)v_klass;
    Value v_theinterpreter = args[1];
    (void)v_theinterpreter;
    (void)(alg_set_property(v_this, "Klass", v_klass));
    (void)(alg_set_property(v_this, "Fields", alg_map()));
    (void)(alg_set_property(v_this, "TheInterpreter", v_theinterpreter));
    return alg_nil();
}

static Value m_objsingleton_instance_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_equal(alg_property(v_this, "TheInstance"), alg_nil()))) {
        (void)(alg_set_property(v_this, "TheInstance", alg_widen(alg_cast(alg_invoke(alg_property(v_this, "Klass"), "Call", (Value[]){alg_property(v_this, "TheInterpreter"), alg_list()}, 2), "ObjInstance"), "ObjInstance")));
    }
    return alg_property(v_this, "TheInstance");
    return alg_nil();
}

static Value m_objsingleton_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    return alg_invoke(alg_invoke(v_this, "Instance", NULL, 0), "Get", (Value[]){v_name}, 1);
    return alg_nil();
}

static Value m_objsingleton_set_2_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_value = args[1];
    (void)v_value;
    (void)(alg_invoke(alg_invoke(v_this, "Instance", NULL, 0), "Set", (Value[]){v_name, v_value}, 2));
    return alg_nil();
}

static Value m_objsingleton_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(alg_property(v_this, "Klass"), "Name");
    return alg_nil();
}

void init_ObjInstance(void) {
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
