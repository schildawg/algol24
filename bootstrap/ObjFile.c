/* Generated from Algol-24.  Do not edit. */
#include "ObjFile.h"
#include "Token.h"

Value k_filemethod;
static const char *t_filemethod_init_3_objfile_token_integer[] = { "Receiver : ObjFile", "Name : Token", "TheArity : Integer" };
static const char *t_filemethod_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };
Value k_objfile;
static const char *t_objfile_get_1_token[] = { "TheName : Token" };
static const char *t_objfile_invoke_2_string_list[] = { "Name : String", "Arguments : List" };

static Value i_filemethod(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "TheArity", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_filemethod_init_3_objfile_token_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_receiver = alg_widen(args[0], "ObjFile");
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

static Value m_filemethod_arity_0(Value v_this, Value *args, int32_t count) {
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

static Value m_filemethod_call_2(Value v_this, Value *args, int32_t count) {
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

static Value m_filemethod_tostring_0(Value v_this, Value *args, int32_t count) {
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

static Value i_objfile(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Handle", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_objfile_init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_set_property(v_this, "Handle", alg_text_file()));
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
}

static Value m_objfile_get_1_token(Value v_this, Value *args, int32_t count) {
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
    if (alg_truthy(alg_equal(v_member, alg_string("eof")))) {
        Value ret_8 = alg_property(alg_property(v_this, "Handle"), "Eof");
        alg_root_top = rt_base;
        return ret_8;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("assign")))) {
        Value ret_9 = alg_new(k_filemethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
        alg_root_top = rt_base;
        return ret_9;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("reset")))) {
        Value ret_10 = alg_new(k_filemethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
        alg_root_top = rt_base;
        return ret_10;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("rewrite")))) {
        Value ret_11 = alg_new(k_filemethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
        alg_root_top = rt_base;
        return ret_11;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("append")))) {
        Value ret_12 = alg_new(k_filemethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
        alg_root_top = rt_base;
        return ret_12;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("readln")))) {
        Value ret_13 = alg_new(k_filemethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
        alg_root_top = rt_base;
        return ret_13;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("write")))) {
        Value ret_14 = alg_new(k_filemethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
        alg_root_top = rt_base;
        return ret_14;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("writeln")))) {
        Value ret_15 = alg_new(k_filemethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
        alg_root_top = rt_base;
        return ret_15;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("flush")))) {
        Value ret_16 = alg_new(k_filemethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
        alg_root_top = rt_base;
        return ret_16;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("close")))) {
        Value ret_17 = alg_new(k_filemethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
        alg_root_top = rt_base;
        return ret_17;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("erase")))) {
        Value ret_18 = alg_new(k_filemethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
        alg_root_top = rt_base;
        return ret_18;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("rename")))) {
        Value ret_19 = alg_new(k_filemethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
        alg_root_top = rt_base;
        return ret_19;
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_str(alg_property(v_thename, "Lexeme"))), alg_string("'.")));
    Value ret_20 = alg_nil();
    alg_root_top = rt_base;
    return ret_20;
}

static Value m_objfile_invoke_2_string_list(Value v_this, Value *args, int32_t count) {
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
    if (alg_truthy(alg_equal(v_name, alg_string("assign")))) {
        Value ret_21 = alg_invoke(alg_property(v_this, "Handle"), "Assign", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        alg_root_top = rt_base;
        return ret_21;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("reset")))) {
        Value ret_22 = alg_invoke(alg_property(v_this, "Handle"), "Reset", NULL, 0);
        alg_root_top = rt_base;
        return ret_22;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("rewrite")))) {
        Value ret_23 = alg_invoke(alg_property(v_this, "Handle"), "Rewrite", NULL, 0);
        alg_root_top = rt_base;
        return ret_23;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("append")))) {
        Value ret_24 = alg_invoke(alg_property(v_this, "Handle"), "Append", NULL, 0);
        alg_root_top = rt_base;
        return ret_24;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("readln")))) {
        Value ret_25 = alg_invoke(alg_property(v_this, "Handle"), "ReadLn", NULL, 0);
        alg_root_top = rt_base;
        return ret_25;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("write")))) {
        Value ret_26 = alg_invoke(alg_property(v_this, "Handle"), "Write", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        alg_root_top = rt_base;
        return ret_26;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("writeln")))) {
        Value ret_27 = alg_invoke(alg_property(v_this, "Handle"), "WriteLn", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        alg_root_top = rt_base;
        return ret_27;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("flush")))) {
        Value ret_28 = alg_invoke(alg_property(v_this, "Handle"), "Flush", NULL, 0);
        alg_root_top = rt_base;
        return ret_28;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("close")))) {
        Value ret_29 = alg_invoke(alg_property(v_this, "Handle"), "Close", NULL, 0);
        alg_root_top = rt_base;
        return ret_29;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("erase")))) {
        Value ret_30 = alg_invoke(alg_property(v_this, "Handle"), "Erase", NULL, 0);
        alg_root_top = rt_base;
        return ret_30;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("rename")))) {
        Value ret_31 = alg_invoke(alg_property(v_this, "Handle"), "Rename", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        alg_root_top = rt_base;
        return ret_31;
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined method '"), v_name), alg_string("'.")));
    Value ret_32 = alg_nil();
    alg_root_top = rt_base;
    return ret_32;
}

static Value m_objfile_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_33 = alg_str(alg_property(v_this, "Handle"));
    alg_root_top = rt_base;
    return ret_33;
    Value ret_34 = alg_nil();
    alg_root_top = rt_base;
    return ret_34;
}

static Value *roots_ObjFile[] = {
    &k_filemethod,
    &k_objfile,
};

void init_ObjFile(void) {
    alg_roots(roots_ObjFile, 2);
    k_filemethod = alg_class("FileMethod", alg_nil());
    k_objfile = alg_class("ObjFile", alg_nil());
    alg_class_field(k_filemethod, "Receiver");
    alg_class_field(k_filemethod, "Name");
    alg_class_field(k_filemethod, "TheArity");
    alg_class_initializer(k_filemethod, i_filemethod);
    alg_class_method(k_filemethod, "Init", m_filemethod_init_3_objfile_token_integer, 3, t_filemethod_init_3_objfile_token_integer);
    alg_class_method(k_filemethod, "Arity", m_filemethod_arity_0, 0, NULL);
    alg_class_method(k_filemethod, "Call", m_filemethod_call_2, 2, t_filemethod_call_2);
    alg_class_method(k_filemethod, "ToString", m_filemethod_tostring_0, 0, NULL);
    alg_class_field(k_objfile, "Handle");
    alg_class_initializer(k_objfile, i_objfile);
    alg_class_method(k_objfile, "Init", m_objfile_init_0, 0, NULL);
    alg_class_method(k_objfile, "Get", m_objfile_get_1_token, 1, t_objfile_get_1_token);
    alg_class_method(k_objfile, "Invoke", m_objfile_invoke_2_string_list, 2, t_objfile_invoke_2_string_list);
    alg_class_method(k_objfile, "ToString", m_objfile_tostring_0, 0, NULL);
}
