/* Generated from Algol-24.  Do not edit. */
#include "ObjBuffer.h"
#include "Token.h"

Value k_buffermethod;
static const char *t_buffermethod_init_3_objbuffer_token_integer[] = { "Receiver : ObjBuffer", "Name : Token", "TheArity : Integer" };
static const char *t_buffermethod_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };
Value k_objbuffer;
static const char *t_objbuffer_init_1_integer[] = { "Size : Integer" };
static const char *t_objbuffer_get_1_token[] = { "TheName : Token" };
static const char *t_objbuffer_invoke_2_string_list[] = { "Name : String", "Arguments : List" };
static const char *t_objbuffer_at_1[] = { "Index : Any" };
static const char *t_objbuffer_putat_2[] = { "Index : Any", "Value : Any" };

static Value i_buffermethod(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "TheArity", alg_nil());
    return alg_nil();
}

static Value m_buffermethod_init_3_objbuffer_token_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_receiver = alg_widen(args[0], "ObjBuffer");
    (void)v_receiver;
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    Value v_thearity = alg_widen(args[2], "Integer");
    (void)v_thearity;
    (void)(alg_set_property(v_this, "Receiver", alg_widen(v_receiver, "ObjBuffer")));
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    (void)(alg_set_property(v_this, "TheArity", alg_widen(v_thearity, "Integer")));
    return alg_nil();
}

static Value m_buffermethod_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "TheArity");
    return alg_nil();
}

static Value m_buffermethod_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_invoke(alg_property(v_this, "Receiver"), "Invoke", (Value[]){f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(v_this, "Name"), "Lexeme"))}, 1), v_arguments}, 2);
    return alg_nil();
}

static Value m_buffermethod_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_add(alg_add(alg_string("<fn "), alg_str(alg_property(alg_property(v_this, "Name"), "Lexeme"))), alg_char_value(62));
    return alg_nil();
}

static Value i_objbuffer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Handle", alg_nil());
    return alg_nil();
}

static Value m_objbuffer_init_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_size = alg_widen(args[0], "Integer");
    (void)v_size;
    (void)(alg_set_property(v_this, "Handle", alg_buffer(v_size)));
    return alg_nil();
}

static Value m_objbuffer_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thename = alg_widen(args[0], "Token");
    (void)v_thename;
    Value v_member = alg_nil();
    (void)v_member;
    (void)((v_member = alg_widen(f_foldcase(NULL, (Value[]){alg_property(v_thename, "Lexeme")}, 1), "String")));
    if (alg_truthy(alg_equal(v_member, alg_string("text")))) {
        return alg_property(alg_property(v_this, "Handle"), "Text");
    }
    if (alg_truthy(alg_equal(v_member, alg_string("length")))) {
        return alg_property(alg_property(v_this, "Handle"), "Length");
    }
    if (alg_truthy(alg_equal(v_member, alg_string("isempty")))) {
        return alg_property(alg_property(v_this, "Handle"), "IsEmpty");
    }
    if (alg_truthy(alg_equal(v_member, alg_string("address")))) {
        return alg_property(alg_property(v_this, "Handle"), "Address");
    }
    if (alg_truthy(alg_equal(v_member, alg_string("append")))) {
        return alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("putint")))) {
        return alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(2)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("getint")))) {
        return alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("resize")))) {
        return alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("free")))) {
        return alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_str(alg_property(v_thename, "Lexeme"))), alg_string("'.")));
    return alg_nil();
}

static Value m_objbuffer_invoke_2_string_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_arguments = alg_widen(args[1], "List");
    (void)v_arguments;
    if (alg_truthy(alg_equal(v_name, alg_string("append")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Append", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("putint")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "PutInt", (Value[]){alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1))}, 2);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("getint")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "GetInt", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("resize")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Resize", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("free")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Free", NULL, 0);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined method '"), v_name), alg_string("'.")));
    return alg_nil();
}

static Value m_objbuffer_at_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_index = args[0];
    (void)v_index;
    return alg_subscript_get(alg_property(v_this, "Handle"), v_index);
    return alg_nil();
}

static Value m_objbuffer_putat_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_index = args[0];
    (void)v_index;
    Value v_value = args[1];
    (void)v_value;
    (void)(alg_subscript_set(alg_property(v_this, "Handle"), v_index, v_value));
    return v_value;
    return alg_nil();
}

static Value m_objbuffer_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_str(alg_property(v_this, "Handle"));
    return alg_nil();
}

void init_ObjBuffer(void) {
    k_buffermethod = alg_class("BufferMethod", alg_nil());
    k_objbuffer = alg_class("ObjBuffer", alg_nil());
    alg_class_field(k_buffermethod, "Receiver");
    alg_class_field(k_buffermethod, "Name");
    alg_class_field(k_buffermethod, "TheArity");
    alg_class_initializer(k_buffermethod, i_buffermethod);
    alg_class_method(k_buffermethod, "Init", m_buffermethod_init_3_objbuffer_token_integer, 3, t_buffermethod_init_3_objbuffer_token_integer);
    alg_class_method(k_buffermethod, "Arity", m_buffermethod_arity_0, 0, NULL);
    alg_class_method(k_buffermethod, "Call", m_buffermethod_call_2, 2, t_buffermethod_call_2);
    alg_class_method(k_buffermethod, "ToString", m_buffermethod_tostring_0, 0, NULL);
    alg_class_field(k_objbuffer, "Handle");
    alg_class_initializer(k_objbuffer, i_objbuffer);
    alg_class_method(k_objbuffer, "Init", m_objbuffer_init_1_integer, 1, t_objbuffer_init_1_integer);
    alg_class_method(k_objbuffer, "Get", m_objbuffer_get_1_token, 1, t_objbuffer_get_1_token);
    alg_class_method(k_objbuffer, "Invoke", m_objbuffer_invoke_2_string_list, 2, t_objbuffer_invoke_2_string_list);
    alg_class_method(k_objbuffer, "At", m_objbuffer_at_1, 1, t_objbuffer_at_1);
    alg_class_method(k_objbuffer, "PutAt", m_objbuffer_putat_2, 2, t_objbuffer_putat_2);
    alg_class_method(k_objbuffer, "ToString", m_objbuffer_tostring_0, 0, NULL);
}
