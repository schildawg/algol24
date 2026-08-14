/* Generated from Algol-24.  Do not edit. */
#include "ObjFunction.h"
#include "Environment.h"
#include "Interpreter.h"
#include "ObjBuffer.h"
#include "ObjClass.h"
#include "ObjFile.h"
#include "ObjInstance.h"
#include "Stmt.h"

Value f_TypeNameOf(Value **cells, Value *args, int32_t count);
Value f_NameOfClass(Value **cells, Value *args, int32_t count);
Value f_InheritsFrom(Value **cells, Value *args, int32_t count);
Value fn_TypeNameOf;
Value fn_NameOfClass;
Value fn_InheritsFrom;
Value k_ObjFunction;
static Value or_0;
static Value or_1;
static Value or_2;
static const char *t_ObjFunction_Init_3_FunctionStmt_Environment_Boolean[] = { "FunctionStmt", "Environment", "Boolean" };
static const char *t_ObjFunction_Bind_1_ObjInstance[] = { "ObjInstance" };
static const char *t_ObjFunction_Fits_1_List[] = { "List" };
static const char *t_ObjFunction_Call_2[] = { "Any", "Any" };

Value f_TypeNameOf(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Value = args[0];
    (void)v_Value;
    if (alg_truthy(alg_equal(v_Value, alg_nil()))) {
        return alg_string("nil");
    }
    if (alg_truthy(alg_is(v_Value, "Boolean"))) {
        return alg_string("Boolean");
    }
    if (alg_truthy(alg_is(v_Value, "Integer"))) {
        return alg_string("Integer");
    }
    if (alg_truthy(alg_is(v_Value, "Double"))) {
        return alg_string("Double");
    }
    if (alg_truthy(alg_is(v_Value, "String"))) {
        return alg_string("String");
    }
    if (alg_truthy(alg_is(v_Value, "Char"))) {
        return alg_string("Char");
    }
    if (alg_truthy(alg_is(v_Value, "ObjInstance"))) {
        return alg_str(alg_property(alg_property(v_Value, "Klass"), "Name"));
    }
    if (alg_truthy(alg_is(v_Value, "ObjCollection"))) {
        return alg_property(v_Value, "Kind");
    }
    if (alg_truthy(alg_is(v_Value, "ObjEnum"))) {
        return alg_property(v_Value, "TypeName");
    }
    if (alg_truthy(alg_is(v_Value, "ObjFile"))) {
        return alg_string("TextFile");
    }
    if (alg_truthy(alg_is(v_Value, "ObjBuffer"))) {
        return alg_string("Buffer");
    }
    return f_NameOfClass(NULL, (Value[]){v_Value}, 1);
    return alg_nil();
}

Value f_NameOfClass(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    volatile Value v_Obj = args[0];
    (void)v_Obj;
    {
        AlgFrame frame_0;
        alg_push_frame(&frame_0);
        if (setjmp(frame_0.jump) == 0) {
            {
                volatile Value ret_1 = alg_property(v_Obj, "ClassName");
                alg_pop_frame();
                return ret_1;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_0[] = {"String"};
            int32_t which_0 = alg_handler(frame_0.raised, names_0, 1);
            if (which_0 == 0) {
                {
                    volatile Value v_e = frame_0.raised;
                    (void)v_e;
                    return alg_string("");
                }
            }
            else {
                alg_raise(frame_0.raised);
            }
        }
    }
    return alg_nil();
}

Value f_InheritsFrom(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Value = args[0];
    (void)v_Value;
    Value v_TheName = args[1];
    (void)v_TheName;
    Value v_Klass = alg_nil();
    (void)v_Klass;
    if (alg_truthy(alg_not((alg_is(v_Value, "ObjInstance"))))) {
        return alg_bool(false);
    }
    (void)((v_Klass = alg_property(v_Value, "Klass")));
    while (alg_truthy(alg_not_equal(v_Klass, alg_nil()))) {
        {
            if (alg_truthy(alg_equal(alg_str(alg_property(v_Klass, "Name")), v_TheName))) {
                return alg_bool(true);
            }
            (void)((v_Klass = alg_property(v_Klass, "Superclass")));
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value i_ObjFunction(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Declaration", alg_nil());
    alg_set_property(v_this, "Closure", alg_nil());
    alg_set_property(v_this, "IsInitializer", alg_nil());
    alg_set_property(v_this, "Owner", alg_nil());
    alg_set_property(v_this, "Bound", alg_nil());
    return alg_nil();
}

static Value m_ObjFunction_Init_3_FunctionStmt_Environment_Boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Declaration = args[0];
    (void)v_Declaration;
    Value v_Closure = args[1];
    (void)v_Closure;
    Value v_IsInitializer = args[2];
    (void)v_IsInitializer;
    (void)(alg_set_property(v_this, "Closure", v_Closure));
    (void)(alg_set_property(v_this, "Declaration", v_Declaration));
    (void)(alg_set_property(v_this, "IsInitializer", v_IsInitializer));
    return alg_nil();
}

static Value m_ObjFunction_Bind_1_ObjInstance(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Instance = args[0];
    (void)v_Instance;
    Value v_Env = alg_nil();
    (void)v_Env;
    (void)((v_Env = alg_new(k_Environment, NULL, 0)));
    (void)(alg_set_property(v_Env, "Enclosing", alg_property(v_this, "Closure")));
    (void)(alg_invoke(v_Env, "Define", (Value[]){alg_string("this"), v_Instance}, 2));
    Value v_Result = alg_new(k_ObjFunction, (Value[]){alg_property(v_this, "Declaration"), v_Env, alg_property(v_this, "IsInitializer")}, 3);
    (void)v_Result;
    (void)(alg_set_property(v_Result, "Owner", alg_property(v_this, "Owner")));
    (void)(alg_set_property(v_Result, "Bound", v_Instance));
    return v_Result;
    return alg_nil();
}

static Value m_ObjFunction_Fits_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Arguments = args[0];
    (void)v_Arguments;
    if (alg_truthy(alg_not_equal(alg_invoke(v_this, "Arity", NULL, 0), alg_property(v_Arguments, "Length")))) {
        return alg_bool(false);
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Arguments, "Length")))) {
            {
                {
                    Value v_Declared = alg_str(alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "ParamTypes"), v_I));
                    (void)v_Declared;
                    if (alg_truthy((or_0 = alg_not_equal(v_Declared, alg_string("")), !alg_truthy(or_0) ? or_0 : alg_not_equal(v_Declared, alg_string("Any"))))) {
                        {
                            Value v_Actual = f_TypeNameOf(NULL, (Value[]){alg_subscript_get(v_Arguments, v_I)}, 1);
                            (void)v_Actual;
                            if (alg_truthy((or_2 = (or_1 = alg_not_equal(v_Actual, alg_string("nil")), !alg_truthy(or_1) ? or_1 : alg_not_equal(v_Actual, alg_string("Any"))), !alg_truthy(or_2) ? or_2 : alg_not_equal(v_Actual, v_Declared)))) {
                                if (alg_truthy(alg_not(f_InheritsFrom(NULL, (Value[]){alg_subscript_get(v_Arguments, v_I), v_Declared}, 2)))) {
                                    return alg_bool(false);
                                }
                            }
                        }
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_bool(true);
    return alg_nil();
}

static Value m_ObjFunction_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_equal(alg_property(alg_property(v_this, "Declaration"), "Params"), alg_nil()))) {
        return alg_int(0);
    }
    return alg_property(alg_property(alg_property(v_this, "Declaration"), "Params"), "Length");
    return alg_nil();
}

static Value m_ObjFunction_ToString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_add(alg_add(alg_string("<fn "), alg_property(alg_property(alg_property(v_this, "Declaration"), "Name"), "Lexeme")), alg_char_value(62));
    return alg_nil();
}

static Value m_ObjFunction_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    volatile Value v_Arguments = args[1];
    (void)v_Arguments;
    volatile Value v_Env = alg_nil();
    (void)v_Env;
    volatile Value v_Count = alg_nil();
    (void)v_Count;
    (void)((v_Env = alg_new(k_Environment, NULL, 0)));
    (void)(alg_set_property(v_Env, "Enclosing", alg_property(v_this, "Closure")));
    {
        volatile Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(alg_property(v_this, "Declaration"), "Params"), "Length")))) {
            {
                {
                    (void)(alg_invoke(v_Env, "Define", (Value[]){alg_property(alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "Params"), v_I), "Lexeme"), alg_subscript_get(v_Arguments, v_I)}, 2));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    {
        AlgFrame frame_2;
        alg_push_frame(&frame_2);
        if (setjmp(frame_2.jump) == 0) {
            {
                (void)(alg_invoke(v_TheInterpreter, "ExecuteBlock", (Value[]){alg_property(alg_property(v_this, "Declaration"), "Body"), v_Env}, 2));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_2[] = {"Return"};
            int32_t which_2 = alg_handler(frame_2.raised, names_2, 1);
            if (which_2 == 0) {
                {
                    volatile Value v_e = frame_2.raised;
                    (void)v_e;
                    {
                        if (alg_truthy(alg_property(v_this, "IsInitializer"))) {
                            return alg_invoke(alg_property(v_this, "Closure"), "GetAt", (Value[]){alg_int(0), alg_string("this")}, 2);
                        }
                        return alg_property(v_e, "Value");
                    }
                }
            }
            else {
                alg_raise(frame_2.raised);
            }
        }
    }
    if (alg_truthy(alg_property(v_this, "IsInitializer"))) {
        return alg_invoke(alg_property(v_this, "Closure"), "GetAt", (Value[]){alg_int(0), alg_string("this")}, 2);
    }
    return alg_nil();
}

void init_ObjFunction(void) {
    fn_TypeNameOf = alg_closure("TypeNameOf", f_TypeNameOf, NULL, 0, 1);
    fn_NameOfClass = alg_closure("NameOfClass", f_NameOfClass, NULL, 0, 1);
    fn_InheritsFrom = alg_closure("InheritsFrom", f_InheritsFrom, NULL, 0, 2);
    k_ObjFunction = alg_class("ObjFunction", alg_nil());
    alg_class_field(k_ObjFunction, "Declaration");
    alg_class_field(k_ObjFunction, "Closure");
    alg_class_field(k_ObjFunction, "IsInitializer");
    alg_class_field(k_ObjFunction, "Owner");
    alg_class_field(k_ObjFunction, "Bound");
    alg_class_initializer(k_ObjFunction, i_ObjFunction);
    alg_class_method(k_ObjFunction, "Init", m_ObjFunction_Init_3_FunctionStmt_Environment_Boolean, 3, t_ObjFunction_Init_3_FunctionStmt_Environment_Boolean);
    alg_class_method(k_ObjFunction, "Bind", m_ObjFunction_Bind_1_ObjInstance, 1, t_ObjFunction_Bind_1_ObjInstance);
    alg_class_method(k_ObjFunction, "Fits", m_ObjFunction_Fits_1_List, 1, t_ObjFunction_Fits_1_List);
    alg_class_method(k_ObjFunction, "Arity", m_ObjFunction_Arity_0, 0, NULL);
    alg_class_method(k_ObjFunction, "ToString", m_ObjFunction_ToString_0, 0, NULL);
    alg_class_method(k_ObjFunction, "Call", m_ObjFunction_Call_2, 2, t_ObjFunction_Call_2);
}
