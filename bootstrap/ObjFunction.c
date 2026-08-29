/* Generated from Algol-24.  Do not edit. */
#include "ObjFunction.h"
#include "Environment.h"
#include "Interpreter.h"
#include "ObjBuffer.h"
#include "ObjClass.h"
#include "ObjFile.h"
#include "ObjInstance.h"
#include "Stmt.h"
#include "Token.h"

Value f_typenameof(Value **cells, Value *args, int32_t count);
Value f_nameofclass(Value **cells, Value *args, int32_t count);
Value f_samesignature(Value **cells, Value *args, int32_t count);
Value f_widens(Value **cells, Value *args, int32_t count);
Value f_inheritsfrom(Value **cells, Value *args, int32_t count);
Value fn_typenameof;
Value fn_nameofclass;
Value k_objoverloads;
static const char *t_objoverloads_init_1_string[] = { "String" };
static const char *t_objoverloads_add_1[] = { "Any" };
static const char *t_objoverloads_select_1_list[] = { "List" };
static const char *t_objoverloads_call_2[] = { "Any", "Any" };
Value fn_samesignature;
static Value or_0;
static Value or_1;
Value fn_widens;
Value fn_inheritsfrom;
Value k_objfunction;
static Value or_2;
static Value or_3;
static Value or_4;
static Value or_5;
static const char *t_objfunction_init_3_functionstmt_environment_boolean[] = { "FunctionStmt", "Environment", "Boolean" };
static const char *t_objfunction_bind_1_objinstance[] = { "ObjInstance" };
static const char *t_objfunction_fits_2_list_boolean[] = { "List", "Boolean" };
static const char *t_objfunction_call_2[] = { "Any", "Any" };

Value f_typenameof(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_value = args[0];
    (void)v_value;
    if (alg_truthy(alg_equal(v_value, alg_nil()))) {
        return alg_string("nil");
    }
    if (alg_truthy(alg_is(v_value, "Boolean"))) {
        return alg_string("Boolean");
    }
    if (alg_truthy(alg_is(v_value, "Integer"))) {
        return alg_string("Integer");
    }
    if (alg_truthy(alg_is(v_value, "Double"))) {
        return alg_string("Double");
    }
    if (alg_truthy(alg_is(v_value, "String"))) {
        return alg_string("String");
    }
    if (alg_truthy(alg_is(v_value, "Char"))) {
        return alg_string("Char");
    }
    if (alg_truthy(alg_is(v_value, "ObjInstance"))) {
        return alg_str(alg_property(alg_property(v_value, "Klass"), "Name"));
    }
    if (alg_truthy(alg_is(v_value, "ObjCollection"))) {
        return alg_property(v_value, "Kind");
    }
    if (alg_truthy(alg_is(v_value, "ObjEnum"))) {
        return alg_property(v_value, "TypeName");
    }
    if (alg_truthy(alg_is(v_value, "ObjFile"))) {
        return alg_string("TextFile");
    }
    if (alg_truthy(alg_is(v_value, "ObjBuffer"))) {
        return alg_string("Buffer");
    }
    return f_nameofclass(NULL, (Value[]){v_value}, 1);
    return alg_nil();
}

Value f_nameofclass(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    volatile Value v_obj = args[0];
    (void)v_obj;
    {
        AlgFrame frame_0;
        alg_push_frame(&frame_0);
        if (ALG_SETJMP(frame_0.jump) == 0) {
            {
                volatile Value ret_1 = alg_property(v_obj, "ClassName");
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

static Value i_objoverloads(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Candidates", alg_nil());
    return alg_nil();
}

static Value m_objoverloads_init_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "String")));
    (void)(alg_set_property(v_this, "Candidates", alg_widen(alg_list(), "List")));
    return alg_nil();
}

static Value m_objoverloads_add_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thefunction = args[0];
    (void)v_thefunction;
    (void)(alg_invoke(alg_property(v_this, "Candidates"), "Add", (Value[]){v_thefunction}, 1));
    return alg_nil();
}

static Value m_objoverloads_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_negate(alg_int(1));
    return alg_nil();
}

static Value m_objoverloads_select_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_this, "Candidates"), "Length")))) {
            {
                if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Candidates"), v_i), "Fits", (Value[]){v_arguments, alg_bool(false)}, 2))) {
                    return alg_subscript_get(alg_property(v_this, "Candidates"), v_i);
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_this, "Candidates"), "Length")))) {
            {
                if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Candidates"), v_i), "Fits", (Value[]){v_arguments, alg_bool(true)}, 2))) {
                    return alg_subscript_get(alg_property(v_this, "Candidates"), v_i);
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_nil();
    return alg_nil();
}

static Value m_objoverloads_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    Value v_chosen = alg_nil();
    (void)v_chosen;
    (void)((v_chosen = alg_invoke(v_this, "Select", (Value[]){v_arguments}, 1)));
    if (alg_truthy(alg_equal(v_chosen, alg_nil()))) {
        alg_raise(alg_string("No matching signature for function."));
    }
    return alg_invoke(v_chosen, "Call", (Value[]){v_theinterpreter, v_arguments}, 2);
    return alg_nil();
}

static Value m_objoverloads_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_add(alg_add(alg_string("<fn "), alg_property(v_this, "Name")), alg_char_value(62));
    return alg_nil();
}

Value f_samesignature(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_left = args[0];
    (void)v_left;
    Value v_right = args[1];
    (void)v_right;
    if (alg_truthy(alg_not_equal(alg_property(alg_property(v_left, "Params"), "Length"), alg_property(alg_property(v_right, "Params"), "Length")))) {
        return alg_bool(false);
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_left, "Params"), "Length")))) {
            {
                if (alg_truthy(alg_not_equal(alg_str(alg_subscript_get(alg_property(v_left, "ParamTypes"), v_i)), alg_str(alg_subscript_get(alg_property(v_right, "ParamTypes"), v_i))))) {
                    return alg_bool(false);
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_bool(true);
    return alg_nil();
}

Value f_widens(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_actual = alg_param(args[0], "String");
    (void)v_actual;
    Value v_declared = alg_param(args[1], "String");
    (void)v_declared;
    if (alg_truthy((or_0 = alg_equal(v_declared, alg_string("Double")), !alg_truthy(or_0) ? or_0 : alg_equal(v_actual, alg_string("Integer"))))) {
        return alg_bool(true);
    }
    if (alg_truthy((or_1 = alg_equal(v_declared, alg_string("String")), !alg_truthy(or_1) ? or_1 : alg_equal(v_actual, alg_string("Char"))))) {
        return alg_bool(true);
    }
    return alg_bool(false);
    return alg_nil();
}

Value f_inheritsfrom(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_value = args[0];
    (void)v_value;
    Value v_thename = alg_param(args[1], "String");
    (void)v_thename;
    Value v_klass = alg_nil();
    (void)v_klass;
    if (alg_truthy(alg_not((alg_is(v_value, "ObjInstance"))))) {
        return alg_bool(false);
    }
    (void)((v_klass = alg_widen(alg_cast(alg_property(v_value, "Klass"), "ObjClass"), "ObjClass")));
    while (alg_truthy(alg_not_equal(v_klass, alg_nil()))) {
        {
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(v_klass, "Name")}, 1), f_foldcase(NULL, (Value[]){v_thename}, 1)))) {
                return alg_bool(true);
            }
            (void)((v_klass = alg_widen(alg_property(v_klass, "Superclass"), "ObjClass")));
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value i_objfunction(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Declaration", alg_nil());
    alg_set_property(v_this, "Closure", alg_nil());
    alg_set_property(v_this, "IsInitializer", alg_nil());
    alg_set_property(v_this, "Owner", alg_widen(alg_nil(), "ObjClass"));
    alg_set_property(v_this, "Bound", alg_widen(alg_nil(), "ObjInstance"));
    return alg_nil();
}

static Value m_objfunction_init_3_functionstmt_environment_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_declaration = alg_widen(args[0], "FunctionStmt");
    (void)v_declaration;
    Value v_closure = alg_widen(args[1], "Environment");
    (void)v_closure;
    Value v_isinitializer = alg_widen(args[2], "Boolean");
    (void)v_isinitializer;
    (void)(alg_set_property(v_this, "Closure", alg_widen(v_closure, "Environment")));
    (void)(alg_set_property(v_this, "Declaration", alg_widen(v_declaration, "FunctionStmt")));
    (void)(alg_set_property(v_this, "IsInitializer", alg_widen(v_isinitializer, "Boolean")));
    return alg_nil();
}

static Value m_objfunction_bind_1_objinstance(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_instance = alg_widen(args[0], "ObjInstance");
    (void)v_instance;
    Value v_env = alg_nil();
    (void)v_env;
    (void)((v_env = alg_widen(alg_new(k_environment, NULL, 0), "Environment")));
    (void)(alg_set_property(v_env, "Enclosing", alg_widen(alg_property(v_this, "Closure"), "Environment")));
    (void)(alg_invoke(v_env, "Define", (Value[]){alg_string("this"), v_instance}, 2));
    Value v_result = alg_new(k_objfunction, (Value[]){alg_property(v_this, "Declaration"), v_env, alg_property(v_this, "IsInitializer")}, 3);
    (void)v_result;
    (void)(alg_set_property(v_result, "Owner", alg_widen(alg_property(v_this, "Owner"), "ObjClass")));
    (void)(alg_set_property(v_result, "Bound", alg_widen(v_instance, "ObjInstance")));
    return v_result;
    return alg_nil();
}

static Value m_objfunction_fits_2_list_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    Value v_widening = alg_widen(args[1], "Boolean");
    (void)v_widening;
    if (alg_truthy(alg_not_equal(alg_invoke(v_this, "Arity", NULL, 0), alg_property(v_arguments, "Length")))) {
        return alg_bool(false);
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_arguments, "Length")))) {
            {
                {
                    Value v_declared = alg_str(alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "ParamTypes"), v_i));
                    (void)v_declared;
                    if (alg_truthy((or_2 = alg_not_equal(v_declared, alg_string("")), !alg_truthy(or_2) ? or_2 : alg_not_equal(v_declared, alg_string("Any"))))) {
                        {
                            Value v_actual = f_typenameof(NULL, (Value[]){alg_subscript_get(v_arguments, v_i)}, 1);
                            (void)v_actual;
                            if (alg_truthy((or_4 = (or_3 = alg_not_equal(v_actual, alg_string("nil")), !alg_truthy(or_3) ? or_3 : alg_not_equal(v_actual, alg_string("Any"))), !alg_truthy(or_4) ? or_4 : alg_not_equal(v_actual, v_declared)))) {
                                {
                                    Value v_fitted = f_inheritsfrom(NULL, (Value[]){alg_subscript_get(v_arguments, v_i), v_declared}, 2);
                                    (void)v_fitted;
                                    if (alg_truthy((or_5 = alg_not(v_fitted), !alg_truthy(or_5) ? or_5 : v_widening))) {
                                        (void)((v_fitted = f_widens(NULL, (Value[]){v_actual, v_declared}, 2)));
                                    }
                                    if (alg_truthy(alg_not(v_fitted))) {
                                        return alg_bool(false);
                                    }
                                }
                            }
                        }
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    return alg_bool(true);
    return alg_nil();
}

static Value m_objfunction_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_equal(alg_property(alg_property(v_this, "Declaration"), "Params"), alg_nil()))) {
        return alg_int(0);
    }
    return alg_property(alg_property(alg_property(v_this, "Declaration"), "Params"), "Length");
    return alg_nil();
}

static Value m_objfunction_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_add(alg_add(alg_string("<fn "), alg_property(alg_property(alg_property(v_this, "Declaration"), "Name"), "Lexeme")), alg_char_value(62));
    return alg_nil();
}

static Value m_objfunction_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    volatile Value v_arguments = args[1];
    (void)v_arguments;
    volatile Value v_env = alg_nil();
    (void)v_env;
    volatile Value v_count = alg_nil();
    (void)v_count;
    (void)((v_env = alg_widen(alg_new(k_environment, NULL, 0), "Environment")));
    (void)(alg_set_property(v_env, "Enclosing", alg_widen(alg_property(v_this, "Closure"), "Environment")));
    {
        volatile Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(alg_property(alg_property(v_this, "Declaration"), "Params"), "Length")))) {
            {
                {
                    volatile Value v_declared = alg_string("");
                    (void)v_declared;
                    if (alg_truthy(alg_less(v_i, alg_property(alg_property(alg_property(v_this, "Declaration"), "ParamTypes"), "Length")))) {
                        (void)((v_declared = alg_str(alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "ParamTypes"), v_i))));
                    }
                    (void)(alg_invoke(v_env, "Define", (Value[]){alg_property(alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "Params"), v_i), "Lexeme"), alg_invoke(v_theinterpreter, "Widen", (Value[]){alg_subscript_get(v_arguments, v_i), v_declared}, 2)}, 2));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    {
        AlgFrame frame_2;
        alg_push_frame(&frame_2);
        if (ALG_SETJMP(frame_2.jump) == 0) {
            {
                (void)(alg_invoke(v_theinterpreter, "ExecuteBlock", (Value[]){alg_property(alg_property(v_this, "Declaration"), "Body"), v_env}, 2));
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
                        return alg_invoke(v_theinterpreter, "Widen", (Value[]){alg_property(v_e, "Value"), alg_str(alg_property(alg_property(v_this, "Declaration"), "ReturnType"))}, 2);
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
    fn_typenameof = alg_closure("TypeNameOf", f_typenameof, NULL, 0, 1);
    fn_nameofclass = alg_closure("NameOfClass", f_nameofclass, NULL, 0, 1);
    k_objoverloads = alg_class("ObjOverloads", alg_nil());
    alg_class_field(k_objoverloads, "Name");
    alg_class_field(k_objoverloads, "Candidates");
    alg_class_initializer(k_objoverloads, i_objoverloads);
    alg_class_method(k_objoverloads, "Init", m_objoverloads_init_1_string, 1, t_objoverloads_init_1_string);
    alg_class_method(k_objoverloads, "Add", m_objoverloads_add_1, 1, t_objoverloads_add_1);
    alg_class_method(k_objoverloads, "Arity", m_objoverloads_arity_0, 0, NULL);
    alg_class_method(k_objoverloads, "Select", m_objoverloads_select_1_list, 1, t_objoverloads_select_1_list);
    alg_class_method(k_objoverloads, "Call", m_objoverloads_call_2, 2, t_objoverloads_call_2);
    alg_class_method(k_objoverloads, "ToString", m_objoverloads_tostring_0, 0, NULL);
    fn_samesignature = alg_closure("SameSignature", f_samesignature, NULL, 0, 2);
    fn_widens = alg_closure("Widens", f_widens, NULL, 0, 2);
    fn_inheritsfrom = alg_closure("InheritsFrom", f_inheritsfrom, NULL, 0, 2);
    k_objfunction = alg_class("ObjFunction", alg_nil());
    alg_class_field(k_objfunction, "Declaration");
    alg_class_field(k_objfunction, "Closure");
    alg_class_field(k_objfunction, "IsInitializer");
    alg_class_field(k_objfunction, "Owner");
    alg_class_field(k_objfunction, "Bound");
    alg_class_initializer(k_objfunction, i_objfunction);
    alg_class_method(k_objfunction, "Init", m_objfunction_init_3_functionstmt_environment_boolean, 3, t_objfunction_init_3_functionstmt_environment_boolean);
    alg_class_method(k_objfunction, "Bind", m_objfunction_bind_1_objinstance, 1, t_objfunction_bind_1_objinstance);
    alg_class_method(k_objfunction, "Fits", m_objfunction_fits_2_list_boolean, 2, t_objfunction_fits_2_list_boolean);
    alg_class_method(k_objfunction, "Arity", m_objfunction_arity_0, 0, NULL);
    alg_class_method(k_objfunction, "ToString", m_objfunction_tostring_0, 0, NULL);
    alg_class_method(k_objfunction, "Call", m_objfunction_call_2, 2, t_objfunction_call_2);
}
