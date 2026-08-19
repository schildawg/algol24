/* Generated from Algol-24.  Do not edit. */
#include "ObjWindow.h"
#include "Token.h"

Value k_WindowMethod;
static const char *t_WindowMethod_Init_3_String_Integer[] = { "Any", "String", "Integer" };
static const char *t_WindowMethod_Call_2[] = { "Any", "Any" };
Value k_ObjImage;
static const char *t_ObjImage_Init_1[] = { "Any" };
static const char *t_ObjImage_Get_1_Token[] = { "Token" };
Value k_ObjWindow;
static const char *t_ObjWindow_Init_3_String_Integer_Integer[] = { "String", "Integer", "Integer" };
static const char *t_ObjWindow_Get_1_Token[] = { "Token" };
static const char *t_ObjWindow_Invoke_2_String_List[] = { "String", "List" };

static Value i_WindowMethod(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "TheArity", alg_nil());
    return alg_nil();
}

static Value m_WindowMethod_Init_3_String_Integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Receiver = args[0];
    (void)v_Receiver;
    Value v_Name = args[1];
    (void)v_Name;
    Value v_TheArity = args[2];
    (void)v_TheArity;
    (void)(alg_set_property(v_this, "Receiver", v_Receiver));
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "TheArity", v_TheArity));
    return alg_nil();
}

static Value m_WindowMethod_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "TheArity");
    return alg_nil();
}

static Value m_WindowMethod_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_invoke(alg_property(v_this, "Receiver"), "Invoke", (Value[]){alg_property(v_this, "Name"), v_Arguments}, 2);
    return alg_nil();
}

static Value i_ObjImage(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Handle", alg_nil());
    return alg_nil();
}

static Value m_ObjImage_Init_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Handle = args[0];
    (void)v_Handle;
    (void)(alg_set_property(v_this, "Handle", v_Handle));
    return alg_nil();
}

static Value m_ObjImage_Get_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheName = args[0];
    (void)v_TheName;
    Value v_Member = alg_nil();
    (void)v_Member;
    (void)((v_Member = alg_property(v_TheName, "Lexeme")));
    if (alg_truthy(alg_equal(v_Member, alg_string("Width")))) {
        return alg_property(alg_property(v_this, "Handle"), "Width");
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Height")))) {
        return alg_property(alg_property(v_this, "Handle"), "Height");
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), v_Member), alg_string("'.")));
    return alg_nil();
}

static Value m_ObjImage_ToString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_str(alg_property(v_this, "Handle"));
    return alg_nil();
}

static Value i_ObjWindow(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Handle", alg_nil());
    return alg_nil();
}

static Value m_ObjWindow_Init_3_String_Integer_Integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Title = args[0];
    (void)v_Title;
    Value v_Width = args[1];
    (void)v_Width;
    Value v_Height = args[2];
    (void)v_Height;
    (void)(alg_set_property(v_this, "Handle", alg_window(v_Title, v_Width, v_Height)));
    return alg_nil();
}

static Value m_ObjWindow_Get_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheName = args[0];
    (void)v_TheName;
    Value v_Member = alg_nil();
    (void)v_Member;
    (void)((v_Member = alg_property(v_TheName, "Lexeme")));
    if (alg_truthy(alg_equal(v_Member, alg_string("Width")))) {
        return alg_property(alg_property(v_this, "Handle"), "Width");
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Height")))) {
        return alg_property(alg_property(v_this, "Handle"), "Height");
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Open?")))) {
        return alg_property(alg_property(v_this, "Handle"), "Open?");
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Load")))) {
        return alg_new(k_WindowMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Clear")))) {
        return alg_new(k_WindowMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Draw")))) {
        return alg_new(k_WindowMethod, (Value[]){v_this, v_Member, alg_int(3)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Present")))) {
        return alg_new(k_WindowMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Poll")))) {
        return alg_new(k_WindowMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Delay")))) {
        return alg_new(k_WindowMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Pixel")))) {
        return alg_new(k_WindowMethod, (Value[]){v_this, v_Member, alg_int(2)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Close")))) {
        return alg_new(k_WindowMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), v_Member), alg_string("'.")));
    return alg_nil();
}

static Value m_ObjWindow_Invoke_2_String_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    if (alg_truthy(alg_equal(v_Name, alg_string("Load")))) {
        return alg_new(k_ObjImage, (Value[]){alg_invoke(alg_property(v_this, "Handle"), "Load", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1)}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Clear")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Clear", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Present")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Present", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Poll")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Poll", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Delay")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Delay", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Pixel")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Pixel", (Value[]){alg_subscript_get(v_Arguments, alg_int(0)), alg_subscript_get(v_Arguments, alg_int(1))}, 2);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Close")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Close", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Draw")))) {
        {
            Value v_Picture = alg_subscript_get(v_Arguments, alg_int(0));
            (void)v_Picture;
            if (alg_truthy(alg_not((alg_is(v_Picture, "ObjImage"))))) {
                alg_raise(alg_string("Draw expects an Image."));
            }
            return alg_invoke(alg_property(v_this, "Handle"), "Draw", (Value[]){alg_property(v_Picture, "Handle"), alg_subscript_get(v_Arguments, alg_int(1)), alg_subscript_get(v_Arguments, alg_int(2))}, 3);
        }
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined method '"), v_Name), alg_string("'.")));
    return alg_nil();
}

static Value m_ObjWindow_ToString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_str(alg_property(v_this, "Handle"));
    return alg_nil();
}

void init_ObjWindow(void) {
    k_WindowMethod = alg_class("WindowMethod", alg_nil());
    alg_class_field(k_WindowMethod, "Receiver");
    alg_class_field(k_WindowMethod, "Name");
    alg_class_field(k_WindowMethod, "TheArity");
    alg_class_initializer(k_WindowMethod, i_WindowMethod);
    alg_class_method(k_WindowMethod, "Init", m_WindowMethod_Init_3_String_Integer, 3, t_WindowMethod_Init_3_String_Integer);
    alg_class_method(k_WindowMethod, "Arity", m_WindowMethod_Arity_0, 0, NULL);
    alg_class_method(k_WindowMethod, "Call", m_WindowMethod_Call_2, 2, t_WindowMethod_Call_2);
    k_ObjImage = alg_class("ObjImage", alg_nil());
    alg_class_field(k_ObjImage, "Handle");
    alg_class_initializer(k_ObjImage, i_ObjImage);
    alg_class_method(k_ObjImage, "Init", m_ObjImage_Init_1, 1, t_ObjImage_Init_1);
    alg_class_method(k_ObjImage, "Get", m_ObjImage_Get_1_Token, 1, t_ObjImage_Get_1_Token);
    alg_class_method(k_ObjImage, "ToString", m_ObjImage_ToString_0, 0, NULL);
    k_ObjWindow = alg_class("ObjWindow", alg_nil());
    alg_class_field(k_ObjWindow, "Handle");
    alg_class_initializer(k_ObjWindow, i_ObjWindow);
    alg_class_method(k_ObjWindow, "Init", m_ObjWindow_Init_3_String_Integer_Integer, 3, t_ObjWindow_Init_3_String_Integer_Integer);
    alg_class_method(k_ObjWindow, "Get", m_ObjWindow_Get_1_Token, 1, t_ObjWindow_Get_1_Token);
    alg_class_method(k_ObjWindow, "Invoke", m_ObjWindow_Invoke_2_String_List, 2, t_ObjWindow_Invoke_2_String_List);
    alg_class_method(k_ObjWindow, "ToString", m_ObjWindow_ToString_0, 0, NULL);
}
