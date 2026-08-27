/* Generated from Algol-24.  Do not edit. */
#include "ObjBuffer.h"
#include "Token.h"

Value k_BufferMethod;
static const char *t_BufferMethod_Init_3_ObjBuffer_String_Integer[] = { "ObjBuffer", "String", "Integer" };
static const char *t_BufferMethod_Call_2[] = { "Any", "Any" };
Value k_ObjBuffer;
static const char *t_ObjBuffer_Init_1_Integer[] = { "Integer" };
static const char *t_ObjBuffer_Get_1_Token[] = { "Token" };
static const char *t_ObjBuffer_Invoke_2_String_List[] = { "String", "List" };
static const char *t_ObjBuffer_At_1[] = { "Any" };
static const char *t_ObjBuffer_PutAt_2[] = { "Any", "Any" };

static Value i_BufferMethod(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "TheArity", alg_nil());
    return alg_nil();
}

static Value m_BufferMethod_Init_3_ObjBuffer_String_Integer(Value v_this, Value *args, int32_t count) {
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

static Value m_BufferMethod_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "TheArity");
    return alg_nil();
}

static Value m_BufferMethod_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_invoke(alg_property(v_this, "Receiver"), "Invoke", (Value[]){alg_property(v_this, "Name"), v_Arguments}, 2);
    return alg_nil();
}

static Value i_ObjBuffer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Handle", alg_nil());
    return alg_nil();
}

static Value m_ObjBuffer_Init_1_Integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Size = args[0];
    (void)v_Size;
    (void)(alg_set_property(v_this, "Handle", alg_buffer(v_Size)));
    return alg_nil();
}

static Value m_ObjBuffer_Get_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheName = args[0];
    (void)v_TheName;
    Value v_Member = alg_nil();
    (void)v_Member;
    (void)((v_Member = alg_property(v_TheName, "Lexeme")));
    if (alg_truthy(alg_equal(v_Member, alg_string("Text")))) {
        return alg_property(alg_property(v_this, "Handle"), "Text");
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Length")))) {
        return alg_property(alg_property(v_this, "Handle"), "Length");
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("IsEmpty")))) {
        return alg_property(alg_property(v_this, "Handle"), "IsEmpty");
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Append")))) {
        return alg_new(k_BufferMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("PutInt")))) {
        return alg_new(k_BufferMethod, (Value[]){v_this, v_Member, alg_int(2)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("GetInt")))) {
        return alg_new(k_BufferMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Resize")))) {
        return alg_new(k_BufferMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Free")))) {
        return alg_new(k_BufferMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), v_Member), alg_string("'.")));
    return alg_nil();
}

static Value m_ObjBuffer_Invoke_2_String_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    if (alg_truthy(alg_equal(v_Name, alg_string("Append")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Append", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("PutInt")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "PutInt", (Value[]){alg_subscript_get(v_Arguments, alg_int(0)), alg_subscript_get(v_Arguments, alg_int(1))}, 2);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("GetInt")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "GetInt", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Resize")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Resize", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Free")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Free", NULL, 0);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined method '"), v_Name), alg_string("'.")));
    return alg_nil();
}

static Value m_ObjBuffer_At_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Index = args[0];
    (void)v_Index;
    return alg_subscript_get(alg_property(v_this, "Handle"), v_Index);
    return alg_nil();
}

static Value m_ObjBuffer_PutAt_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Index = args[0];
    (void)v_Index;
    Value v_Value = args[1];
    (void)v_Value;
    (void)(alg_subscript_set(alg_property(v_this, "Handle"), v_Index, v_Value));
    return v_Value;
    return alg_nil();
}

static Value m_ObjBuffer_ToString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_str(alg_property(v_this, "Handle"));
    return alg_nil();
}

void init_ObjBuffer(void) {
    k_BufferMethod = alg_class("BufferMethod", alg_nil());
    alg_class_field(k_BufferMethod, "Receiver");
    alg_class_field(k_BufferMethod, "Name");
    alg_class_field(k_BufferMethod, "TheArity");
    alg_class_initializer(k_BufferMethod, i_BufferMethod);
    alg_class_method(k_BufferMethod, "Init", m_BufferMethod_Init_3_ObjBuffer_String_Integer, 3, t_BufferMethod_Init_3_ObjBuffer_String_Integer);
    alg_class_method(k_BufferMethod, "Arity", m_BufferMethod_Arity_0, 0, NULL);
    alg_class_method(k_BufferMethod, "Call", m_BufferMethod_Call_2, 2, t_BufferMethod_Call_2);
    k_ObjBuffer = alg_class("ObjBuffer", alg_nil());
    alg_class_field(k_ObjBuffer, "Handle");
    alg_class_initializer(k_ObjBuffer, i_ObjBuffer);
    alg_class_method(k_ObjBuffer, "Init", m_ObjBuffer_Init_1_Integer, 1, t_ObjBuffer_Init_1_Integer);
    alg_class_method(k_ObjBuffer, "Get", m_ObjBuffer_Get_1_Token, 1, t_ObjBuffer_Get_1_Token);
    alg_class_method(k_ObjBuffer, "Invoke", m_ObjBuffer_Invoke_2_String_List, 2, t_ObjBuffer_Invoke_2_String_List);
    alg_class_method(k_ObjBuffer, "At", m_ObjBuffer_At_1, 1, t_ObjBuffer_At_1);
    alg_class_method(k_ObjBuffer, "PutAt", m_ObjBuffer_PutAt_2, 2, t_ObjBuffer_PutAt_2);
    alg_class_method(k_ObjBuffer, "ToString", m_ObjBuffer_ToString_0, 0, NULL);
}
