/* Generated from Algol-24.  Do not edit. */
#include "ObjFile.h"
#include "Token.h"

Value k_FileMethod;
static const char *t_FileMethod_Init_3_ObjFile_String_Integer[] = { "ObjFile", "String", "Integer" };
static const char *t_FileMethod_Call_2[] = { "Any", "Any" };
Value k_ObjFile;
static const char *t_ObjFile_Get_1_Token[] = { "Token" };
static const char *t_ObjFile_Invoke_2_String_List[] = { "String", "List" };

static Value i_FileMethod(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "TheArity", alg_nil());
    return alg_nil();
}

static Value m_FileMethod_Init_3_ObjFile_String_Integer(Value v_this, Value *args, int32_t count) {
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

static Value m_FileMethod_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "TheArity");
    return alg_nil();
}

static Value m_FileMethod_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_invoke(alg_property(v_this, "Receiver"), "Invoke", (Value[]){alg_property(v_this, "Name"), v_Arguments}, 2);
    return alg_nil();
}

static Value i_ObjFile(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Handle", alg_nil());
    return alg_nil();
}

static Value m_ObjFile_Init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_set_property(v_this, "Handle", alg_text_file()));
    return alg_nil();
}

static Value m_ObjFile_Get_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheName = args[0];
    (void)v_TheName;
    Value v_Member = alg_nil();
    (void)v_Member;
    (void)((v_Member = alg_property(v_TheName, "Lexeme")));
    if (alg_truthy(alg_equal(v_Member, alg_string("Eof")))) {
        return alg_property(alg_property(v_this, "Handle"), "Eof");
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Assign")))) {
        return alg_new(k_FileMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Reset")))) {
        return alg_new(k_FileMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Rewrite")))) {
        return alg_new(k_FileMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Append")))) {
        return alg_new(k_FileMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("ReadLn")))) {
        return alg_new(k_FileMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Write")))) {
        return alg_new(k_FileMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("WriteLn")))) {
        return alg_new(k_FileMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Flush")))) {
        return alg_new(k_FileMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Close")))) {
        return alg_new(k_FileMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Erase")))) {
        return alg_new(k_FileMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Rename")))) {
        return alg_new(k_FileMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), v_Member), alg_string("'.")));
    return alg_nil();
}

static Value m_ObjFile_Invoke_2_String_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    if (alg_truthy(alg_equal(v_Name, alg_string("Assign")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Assign", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Reset")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Reset", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Rewrite")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Rewrite", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Append")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Append", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("ReadLn")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "ReadLn", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Write")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Write", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("WriteLn")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "WriteLn", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Flush")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Flush", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Close")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Close", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Erase")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Erase", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Rename")))) {
        return alg_invoke(alg_property(v_this, "Handle"), "Rename", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined method '"), v_Name), alg_string("'.")));
    return alg_nil();
}

static Value m_ObjFile_ToString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_str(alg_property(v_this, "Handle"));
    return alg_nil();
}

void init_ObjFile(void) {
    k_FileMethod = alg_class("FileMethod", alg_nil());
    alg_class_field(k_FileMethod, "Receiver");
    alg_class_field(k_FileMethod, "Name");
    alg_class_field(k_FileMethod, "TheArity");
    alg_class_initializer(k_FileMethod, i_FileMethod);
    alg_class_method(k_FileMethod, "Init", m_FileMethod_Init_3_ObjFile_String_Integer, 3, t_FileMethod_Init_3_ObjFile_String_Integer);
    alg_class_method(k_FileMethod, "Arity", m_FileMethod_Arity_0, 0, NULL);
    alg_class_method(k_FileMethod, "Call", m_FileMethod_Call_2, 2, t_FileMethod_Call_2);
    k_ObjFile = alg_class("ObjFile", alg_nil());
    alg_class_field(k_ObjFile, "Handle");
    alg_class_initializer(k_ObjFile, i_ObjFile);
    alg_class_method(k_ObjFile, "Init", m_ObjFile_Init_0, 0, NULL);
    alg_class_method(k_ObjFile, "Get", m_ObjFile_Get_1_Token, 1, t_ObjFile_Get_1_Token);
    alg_class_method(k_ObjFile, "Invoke", m_ObjFile_Invoke_2_String_List, 2, t_ObjFile_Invoke_2_String_List);
    alg_class_method(k_ObjFile, "ToString", m_ObjFile_ToString_0, 0, NULL);
}
