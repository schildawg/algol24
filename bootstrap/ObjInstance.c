/* Generated from Algol-24.  Do not edit. */
#include "ObjInstance.h"
#include "ObjClass.h"
#include "ObjFunction.h"
#include "Token.h"

Value k_ObjInstance;
static const char *t_ObjInstance_Init_1_ObjClass[] = { "ObjClass" };
static const char *t_ObjInstance_Get_1_Token[] = { "Token" };
static const char *t_ObjInstance_Set_2_Token[] = { "Token", "Any" };
Value k_ObjSingleton;
static const char *t_ObjSingleton_Init_2_ObjClass[] = { "ObjClass", "Any" };
static const char *t_ObjSingleton_Get_1_Token[] = { "Token" };
static const char *t_ObjSingleton_Set_2_Token[] = { "Token", "Any" };

static Value i_ObjInstance(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Klass", alg_nil());
    alg_set_property(v_this, "Fields", alg_nil());
    return alg_nil();
}

static Value m_ObjInstance_Init_1_ObjClass(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Klass = args[0];
    (void)v_Klass;
    (void)(alg_set_property(v_this, "Klass", v_Klass));
    (void)(alg_set_property(v_this, "Fields", alg_map()));
    return alg_nil();
}

static Value m_ObjInstance_Get_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Method = alg_nil();
    (void)v_Method;
    if (alg_truthy(alg_equal(alg_str(alg_property(v_Name, "Lexeme")), alg_string("ClassName")))) {
        return alg_property(alg_property(v_this, "Klass"), "Name");
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Fields"), "Contains", (Value[]){alg_property(v_Name, "Lexeme")}, 1))) {
        {
            return alg_invoke(alg_property(v_this, "Fields"), "Get", (Value[]){alg_property(v_Name, "Lexeme")}, 1);
        }
    }
    (void)((v_Method = alg_invoke(alg_property(v_this, "Klass"), "FindMethod", (Value[]){alg_property(v_Name, "Lexeme")}, 1)));
    if (alg_truthy(alg_not_equal(v_Method, alg_nil()))) {
        return alg_invoke(v_Method, "Bind", (Value[]){v_this}, 1);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_property(v_Name, "Lexeme")), alg_string("'.")));
    return alg_nil();
}

static Value m_ObjInstance_Set_2_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Value = args[1];
    (void)v_Value;
    (void)(alg_invoke(alg_property(v_this, "Fields"), "Put", (Value[]){alg_property(v_Name, "Lexeme"), v_Value}, 2));
    return alg_nil();
}

static Value m_ObjInstance_ToString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_add(alg_property(alg_property(v_this, "Klass"), "Name"), alg_string(" instance"));
    return alg_nil();
}

static Value i_ObjSingleton(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "TheInterpreter", alg_nil());
    alg_set_property(v_this, "TheInstance", alg_nil());
    return alg_nil();
}

static Value m_ObjSingleton_Init_2_ObjClass(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Klass = args[0];
    (void)v_Klass;
    Value v_TheInterpreter = args[1];
    (void)v_TheInterpreter;
    (void)(alg_set_property(v_this, "Klass", v_Klass));
    (void)(alg_set_property(v_this, "Fields", alg_map()));
    (void)(alg_set_property(v_this, "TheInterpreter", v_TheInterpreter));
    return alg_nil();
}

static Value m_ObjSingleton_Instance_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_equal(alg_property(v_this, "TheInstance"), alg_nil()))) {
        (void)(alg_set_property(v_this, "TheInstance", alg_invoke(alg_property(v_this, "Klass"), "Call", (Value[]){alg_property(v_this, "TheInterpreter"), alg_list()}, 2)));
    }
    return alg_property(v_this, "TheInstance");
    return alg_nil();
}

static Value m_ObjSingleton_Get_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    return alg_invoke(alg_invoke(v_this, "Instance", NULL, 0), "Get", (Value[]){v_Name}, 1);
    return alg_nil();
}

static Value m_ObjSingleton_Set_2_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Value = args[1];
    (void)v_Value;
    (void)(alg_invoke(alg_invoke(v_this, "Instance", NULL, 0), "Set", (Value[]){v_Name, v_Value}, 2));
    return alg_nil();
}

static Value m_ObjSingleton_ToString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(alg_property(v_this, "Klass"), "Name");
    return alg_nil();
}

void init_ObjInstance(void) {
    k_ObjInstance = alg_class("ObjInstance", alg_nil());
    alg_class_field(k_ObjInstance, "Klass");
    alg_class_field(k_ObjInstance, "Fields");
    alg_class_initializer(k_ObjInstance, i_ObjInstance);
    alg_class_method(k_ObjInstance, "Init", m_ObjInstance_Init_1_ObjClass, 1, t_ObjInstance_Init_1_ObjClass);
    alg_class_method(k_ObjInstance, "Get", m_ObjInstance_Get_1_Token, 1, t_ObjInstance_Get_1_Token);
    alg_class_method(k_ObjInstance, "Set", m_ObjInstance_Set_2_Token, 2, t_ObjInstance_Set_2_Token);
    alg_class_method(k_ObjInstance, "ToString", m_ObjInstance_ToString_0, 0, NULL);
    k_ObjSingleton = alg_class("ObjSingleton", k_ObjInstance);
    alg_class_field(k_ObjSingleton, "TheInterpreter");
    alg_class_field(k_ObjSingleton, "TheInstance");
    alg_class_initializer(k_ObjSingleton, i_ObjSingleton);
    alg_class_method(k_ObjSingleton, "Init", m_ObjSingleton_Init_2_ObjClass, 2, t_ObjSingleton_Init_2_ObjClass);
    alg_class_method(k_ObjSingleton, "Instance", m_ObjSingleton_Instance_0, 0, NULL);
    alg_class_method(k_ObjSingleton, "Get", m_ObjSingleton_Get_1_Token, 1, t_ObjSingleton_Get_1_Token);
    alg_class_method(k_ObjSingleton, "Set", m_ObjSingleton_Set_2_Token, 2, t_ObjSingleton_Set_2_Token);
    alg_class_method(k_ObjSingleton, "ToString", m_ObjSingleton_ToString_0, 0, NULL);
}
