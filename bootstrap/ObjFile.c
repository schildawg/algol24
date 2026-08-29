/* Generated from Algol-24.  Do not edit. */
#include "ObjFile.h"
#include "Token.h"

Value k_filemethod;
static const char *t_filemethod_init_3_objfile_string_integer[] = { "ObjFile", "String", "Integer" };
static const char *t_filemethod_call_2[] = { "Any", "Any" };
Value k_objfile;
static const char *t_objfile_get_1_token[] = { "Token" };
static const char *t_objfile_invoke_2_string_list[] = { "String", "List" };

static Value i_filemethod(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "TheArity", alg_nil());
    return alg_nil();
}

static Value m_filemethod_init_3_objfile_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_receiver = alg_widen(args[0], "ObjFile");
    (void)v_receiver;
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    Value v_thearity = alg_widen(args[2], "Integer");
    (void)v_thearity;
    (void)(alg_set_property(v_this, "Receiver", alg_widen(v_receiver, "ObjFile")));
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "String")));
    (void)(alg_set_property(v_this, "TheArity", alg_widen(v_thearity, "Integer")));
    return alg_nil();
}

static Value m_filemethod_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "TheArity");
    return alg_nil();
}

static Value m_filemethod_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_invoke(alg_property(v_this, "Receiver"), "Invoke", (Value[]){alg_property(v_this, "Name"), v_arguments}, 2);
    return alg_nil();
}

static Value i_objfile(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Handle", alg_nil());
    return alg_nil();
}

static Value m_objfile_init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_set_property(v_this, "Handle", alg_text_file()));
    return alg_nil();
}

static Value m_objfile_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thename = alg_widen(args[0], "Token");
    (void)v_thename;
    Value v_member = alg_nil();
    (void)v_member;
    (void)((v_member = alg_widen(f_foldcase(NULL, (Value[]){alg_property(v_thename, "Lexeme")}, 1), "String")));
    if (alg_truthy(alg_equal(v_member, alg_string("eof")))) {
        return alg_property(alg_property(v_this, "Handle"), "Eof");
    }
    if (alg_truthy(alg_equal(v_member, alg_string("assign")))) {
        return alg_new(k_filemethod, (Value[]){v_this, v_member, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("reset")))) {
        return alg_new(k_filemethod, (Value[]){v_this, v_member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("rewrite")))) {
        return alg_new(k_filemethod, (Value[]){v_this, v_member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("append")))) {
        return alg_new(k_filemethod, (Value[]){v_this, v_member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("readln")))) {
        return alg_new(k_filemethod, (Value[]){v_this, v_member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("write")))) {
        return alg_new(k_filemethod, (Value[]){v_this, v_member, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("writeln")))) {
        return alg_new(k_filemethod, (Value[]){v_this, v_member, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("flush")))) {
        return alg_new(k_filemethod, (Value[]){v_this, v_member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("close")))) {
        return alg_new(k_filemethod, (Value[]){v_this, v_member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("erase")))) {
        return alg_new(k_filemethod, (Value[]){v_this, v_member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("rename")))) {
        return alg_new(k_filemethod, (Value[]){v_this, v_member, alg_int(1)}, 3);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_str(alg_property(v_thename, "Lexeme"))), alg_string("'.")));
    return alg_nil();
}

static Value m_objfile_invoke_2_string_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_arguments = alg_widen(args[1], "List");
    (void)v_arguments;
    if (alg_truthy(alg_equal(v_name, alg_string("assign")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Assign", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("reset")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Reset", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("rewrite")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Rewrite", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("append")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Append", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("readln")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "ReadLn", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("write")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Write", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("writeln")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "WriteLn", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("flush")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Flush", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("close")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Close", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("erase")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Erase", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("rename")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Rename", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined method '"), v_name), alg_string("'.")));
    return alg_nil();
}

static Value m_objfile_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_str(alg_property(v_this, "Handle"));
    return alg_nil();
}

void init_ObjFile(void) {
    k_filemethod = alg_class("FileMethod", alg_nil());
    alg_class_field(k_filemethod, "Receiver");
    alg_class_field(k_filemethod, "Name");
    alg_class_field(k_filemethod, "TheArity");
    alg_class_initializer(k_filemethod, i_filemethod);
    alg_class_method(k_filemethod, "Init", m_filemethod_init_3_objfile_string_integer, 3, t_filemethod_init_3_objfile_string_integer);
    alg_class_method(k_filemethod, "Arity", m_filemethod_arity_0, 0, NULL);
    alg_class_method(k_filemethod, "Call", m_filemethod_call_2, 2, t_filemethod_call_2);
    k_objfile = alg_class("ObjFile", alg_nil());
    alg_class_field(k_objfile, "Handle");
    alg_class_initializer(k_objfile, i_objfile);
    alg_class_method(k_objfile, "Init", m_objfile_init_0, 0, NULL);
    alg_class_method(k_objfile, "Get", m_objfile_get_1_token, 1, t_objfile_get_1_token);
    alg_class_method(k_objfile, "Invoke", m_objfile_invoke_2_string_list, 2, t_objfile_invoke_2_string_list);
    alg_class_method(k_objfile, "ToString", m_objfile_tostring_0, 0, NULL);
}
