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
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "TheArity", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_buffermethod_init_3_objbuffer_token_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_receiver = alg_widen(args[0], "ObjBuffer");
    (void)v_receiver;
    alg_root(&v_receiver, 1);
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_thearity = alg_widen(args[2], "Integer");
    (void)v_thearity;
    alg_root(&v_thearity, 1);
    (void)(alg_set_property(v_this, "Receiver", v_receiver));
    (void)(alg_set_property(v_this, "Name", v_name));
    (void)(alg_set_property(v_this, "TheArity", v_thearity));
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

static Value m_buffermethod_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_1 = alg_property(v_this, "TheArity");
    alg_root_top = rt_base;
    return ret_1;
    Value ret_2 = alg_nil();
    alg_root_top = rt_base;
    return ret_2;
}

static Value m_buffermethod_call_2(Value v_this, Value *args, int32_t count) {
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
    Value ret_3 = alg_invoke(alg_property(v_this, "Receiver"), "Invoke", (Value[]){f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(v_this, "Name"), "Lexeme"))}, 1), v_arguments}, 2);
    alg_root_top = rt_base;
    return ret_3;
    Value ret_4 = alg_nil();
    alg_root_top = rt_base;
    return ret_4;
}

static Value m_buffermethod_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_5 = alg_add(alg_add(alg_string("<fn "), alg_str(alg_property(alg_property(v_this, "Name"), "Lexeme"))), alg_char_value(62));
    alg_root_top = rt_base;
    return ret_5;
    Value ret_6 = alg_nil();
    alg_root_top = rt_base;
    return ret_6;
}

static Value i_objbuffer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Handle", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_objbuffer_init_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_size = alg_widen(args[0], "Integer");
    (void)v_size;
    alg_root(&v_size, 1);
    (void)(alg_set_property(v_this, "Handle", alg_buffer(v_size)));
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
}

static Value m_objbuffer_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thename = alg_widen(args[0], "Token");
    (void)v_thename;
    alg_root(&v_thename, 1);
    Value v_member = alg_nil();
    (void)v_member;
    alg_root(&v_member, 1);
    (void)((v_member = f_foldcase(NULL, (Value[]){alg_property(v_thename, "Lexeme")}, 1)));
    if (alg_truthy(alg_equal(v_member, alg_string("text")))) {
        Value ret_8 = alg_property(alg_property(v_this, "Handle"), "Text");
        alg_root_top = rt_base;
        return ret_8;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("length")))) {
        Value ret_9 = alg_property(alg_property(v_this, "Handle"), "Length");
        alg_root_top = rt_base;
        return ret_9;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("isempty")))) {
        Value ret_10 = alg_property(alg_property(v_this, "Handle"), "IsEmpty");
        alg_root_top = rt_base;
        return ret_10;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("address")))) {
        Value ret_11 = alg_property(alg_property(v_this, "Handle"), "Address");
        alg_root_top = rt_base;
        return ret_11;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("append")))) {
        Value ret_12 = alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
        alg_root_top = rt_base;
        return ret_12;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("putint")))) {
        Value ret_13 = alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(2)}, 3);
        alg_root_top = rt_base;
        return ret_13;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("getint")))) {
        Value ret_14 = alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
        alg_root_top = rt_base;
        return ret_14;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("putword")))) {
        Value ret_15 = alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(2)}, 3);
        alg_root_top = rt_base;
        return ret_15;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("getword")))) {
        Value ret_16 = alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
        alg_root_top = rt_base;
        return ret_16;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("putdouble")))) {
        Value ret_17 = alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(2)}, 3);
        alg_root_top = rt_base;
        return ret_17;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("getdouble")))) {
        Value ret_18 = alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
        alg_root_top = rt_base;
        return ret_18;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("resize")))) {
        Value ret_19 = alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
        alg_root_top = rt_base;
        return ret_19;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("free")))) {
        Value ret_20 = alg_new(k_buffermethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
        alg_root_top = rt_base;
        return ret_20;
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_str(alg_property(v_thename, "Lexeme"))), alg_string("'.")));
    Value ret_21 = alg_nil();
    alg_root_top = rt_base;
    return ret_21;
}

static Value m_objbuffer_invoke_2_string_list(Value v_this, Value *args, int32_t count) {
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
    if (alg_truthy(alg_equal(v_name, alg_string("append")))) {
        Value ret_22 = alg_invoke(alg_property(v_this, "Handle"), "Append", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        alg_root_top = rt_base;
        return ret_22;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("putint")))) {
        Value ret_23 = alg_invoke(alg_property(v_this, "Handle"), "PutInt", (Value[]){alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1))}, 2);
        alg_root_top = rt_base;
        return ret_23;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("getint")))) {
        Value ret_24 = alg_invoke(alg_property(v_this, "Handle"), "GetInt", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        alg_root_top = rt_base;
        return ret_24;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("putword")))) {
        Value ret_25 = alg_invoke(alg_property(v_this, "Handle"), "PutWord", (Value[]){alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1))}, 2);
        alg_root_top = rt_base;
        return ret_25;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("getword")))) {
        Value ret_26 = alg_invoke(alg_property(v_this, "Handle"), "GetWord", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        alg_root_top = rt_base;
        return ret_26;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("putdouble")))) {
        Value ret_27 = alg_invoke(alg_property(v_this, "Handle"), "PutDouble", (Value[]){alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1))}, 2);
        alg_root_top = rt_base;
        return ret_27;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("getdouble")))) {
        Value ret_28 = alg_invoke(alg_property(v_this, "Handle"), "GetDouble", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        alg_root_top = rt_base;
        return ret_28;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("resize")))) {
        Value ret_29 = alg_invoke(alg_property(v_this, "Handle"), "Resize", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        alg_root_top = rt_base;
        return ret_29;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("free")))) {
        Value ret_30 = alg_invoke(alg_property(v_this, "Handle"), "Free", NULL, 0);
        alg_root_top = rt_base;
        return ret_30;
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined method '"), v_name), alg_string("'.")));
    Value ret_31 = alg_nil();
    alg_root_top = rt_base;
    return ret_31;
}

static Value m_objbuffer_at_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_index = args[0];
    (void)v_index;
    alg_root(&v_index, 1);
    Value ret_32 = alg_subscript_get(alg_property(v_this, "Handle"), v_index);
    alg_root_top = rt_base;
    return ret_32;
    Value ret_33 = alg_nil();
    alg_root_top = rt_base;
    return ret_33;
}

static Value m_objbuffer_putat_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_index = args[0];
    (void)v_index;
    alg_root(&v_index, 1);
    Value v_value = args[1];
    (void)v_value;
    alg_root(&v_value, 1);
    (void)(alg_subscript_set(alg_property(v_this, "Handle"), v_index, v_value));
    Value ret_34 = v_value;
    alg_root_top = rt_base;
    return ret_34;
    Value ret_35 = alg_nil();
    alg_root_top = rt_base;
    return ret_35;
}

static Value m_objbuffer_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_36 = alg_str(alg_property(v_this, "Handle"));
    alg_root_top = rt_base;
    return ret_36;
    Value ret_37 = alg_nil();
    alg_root_top = rt_base;
    return ret_37;
}

static Value *roots_ObjBuffer[] = {
    &k_buffermethod,
    &k_objbuffer,
};

void init_ObjBuffer(void) {
    alg_roots(roots_ObjBuffer, 2);
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
