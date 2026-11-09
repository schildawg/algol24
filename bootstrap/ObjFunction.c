/* Generated from Algol-24.  Do not edit. */
#include "ObjFunction.h"
#include "Environment.h"
#include "Interpreter.h"
#include "ObjBuffer.h"
#include "ObjClass.h"
#include "ObjCollection.h"
#include "ObjFile.h"
#include "ObjInstance.h"
#include "Stmt.h"
#include "Token.h"

Value f_typenameof(Value **cells, Value *args, int32_t count);
Value f_nameofclass(Value **cells, Value *args, int32_t count);
Value f_samesignature(Value **cells, Value *args, int32_t count);
Value f_anynamed(Value **cells, Value *args, int32_t count);
Value f_widens(Value **cells, Value *args, int32_t count);
Value f_inheritsfrom(Value **cells, Value *args, int32_t count);
Value fn_typenameof;
static const char *t_f_typenameof[] = { "Value : Any" };
Value fn_nameofclass;
static const char *t_f_nameofclass[] = { "Obj : Any" };
Value k_objoverloads;
static Value or_0;
static Value or_1;
static Value or_2;
static const char *t_objoverloads_init_1_string[] = { "Name : String" };
static const char *t_objoverloads_add_1[] = { "TheFunction : Any" };
static const char *t_objoverloads_declares_1_integer[] = { "Count : Integer" };
static const char *t_objoverloads_select_1_list[] = { "Arguments : List" };
static const char *t_objoverloads_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };
Value k_numbermethod;
static const char *t_numbermethod_init_2_token[] = { "Receiver : Any", "Name : Token" };
static const char *t_numbermethod_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };
Value k_objextension;
static const char *t_objextension_init_2[] = { "Receiver : Any", "Target : Any" };
static const char *t_objextension_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };
Value fn_samesignature;
static const char *t_f_samesignature[] = { "Left : Any", "Right : Any" };
Value fn_anynamed;
static const char *t_f_anynamed[] = { "Names : List" };
Value v_exact;
bool d_exact;
Value v_widening;
bool d_widening;
Value v_absorbing;
bool d_absorbing;
static Value or_3;
static Value or_4;
Value fn_widens;
static const char *t_f_widens[] = { "Actual : String", "Declared : String" };
Value fn_inheritsfrom;
static const char *t_f_inheritsfrom[] = { "Value : Any", "TheName : String" };
Value k_objfunction;
static Value or_5;
static Value or_6;
static Value or_7;
static Value or_8;
static Value or_9;
static Value or_10;
static const char *t_objfunction_init_3_functionstmt_environment_boolean[] = { "Declaration : FunctionStmt", "Closure : Environment", "IsInitializer : Boolean" };
static const char *t_objfunction_bind_1_objinstance[] = { "Instance : ObjInstance" };
static const char *t_objfunction_fitsat_3_string_boolean[] = { "Argument : Any", "Declared : String", "Widening : Boolean" };
static const char *t_objfunction_fits_2_list_boolean[] = { "Arguments : List", "Widening : Boolean" };
static const char *t_objfunction_absorbs_1_list[] = { "Arguments : List" };
static const char *t_objfunction_absorb_1_list[] = { "Arguments : List" };
static const char *t_objfunction_parameterat_1_string[] = { "TheName : String" };
static const char *t_objfunction_arrange_2_list_list[] = { "Arguments : List", "Names : List" };
static const char *t_objfunction_selects_2_list_integer[] = { "Arguments : List", "Pass : Integer" };
static const char *t_objfunction_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };

Value f_typenameof(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    if (alg_truthy(alg_equal(v_value, alg_nil()))) {
        Value ret_0 = alg_string("nil");
        alg_root_top = rt_base;
        return ret_0;
    }
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_BOOLEAN))) {
        Value ret_1 = alg_string("Boolean");
        alg_root_top = rt_base;
        return ret_1;
    }
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_INTEGER))) {
        Value ret_2 = alg_string("Integer");
        alg_root_top = rt_base;
        return ret_2;
    }
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_DOUBLE))) {
        Value ret_3 = alg_string("Double");
        alg_root_top = rt_base;
        return ret_3;
    }
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_STRING))) {
        Value ret_4 = alg_string("String");
        alg_root_top = rt_base;
        return ret_4;
    }
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_CHAR))) {
        Value ret_5 = alg_string("Char");
        alg_root_top = rt_base;
        return ret_5;
    }
    if (alg_truthy(alg_is(v_value, "ObjInstance"))) {
        Value ret_6 = alg_str(alg_property(alg_property(v_value, "Klass"), "Name"));
        alg_root_top = rt_base;
        return ret_6;
    }
    if (alg_truthy(alg_is(v_value, "ObjCollection"))) {
        Value ret_7 = alg_property(v_value, "Kind");
        alg_root_top = rt_base;
        return ret_7;
    }
    if (alg_truthy(alg_is(v_value, "ObjEnum"))) {
        Value ret_8 = alg_property(v_value, "TypeName");
        alg_root_top = rt_base;
        return ret_8;
    }
    if (alg_truthy(alg_is(v_value, "ObjFile"))) {
        Value ret_9 = alg_string("TextFile");
        alg_root_top = rt_base;
        return ret_9;
    }
    if (alg_truthy(alg_is(v_value, "ObjBuffer"))) {
        Value ret_10 = alg_string("Buffer");
        alg_root_top = rt_base;
        return ret_10;
    }
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_POINTER))) {
        Value ret_11 = alg_string("Pointer");
        alg_root_top = rt_base;
        return ret_11;
    }
    Value ret_12 = f_nameofclass(NULL, (Value[]){v_value}, 1);
    alg_root_top = rt_base;
    return ret_12;
    Value ret_13 = alg_nil();
    alg_root_top = rt_base;
    return ret_13;
}

Value f_nameofclass(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    volatile Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    {
        AlgFrame frame_14;
        alg_push_frame(&frame_14);
        if (ALG_SETJMP(frame_14.jump) == 0) {
            {
                volatile Value ret_15 = alg_property(v_obj, "ClassName");
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_15;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_14[] = {"String"};
            int32_t which_14 = alg_handler(frame_14.raised, names_14, 1);
            if (which_14 == 0) {
                {
                    int32_t rt_267 = alg_root_top;
                    volatile Value v_e = frame_14.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_16 = alg_string("");
                    alg_root_top = rt_base;
                    return ret_16;
                    alg_root_top = rt_267;
                }
            }
            else {
                alg_raise(frame_14.raised);
            }
        }
    }
    volatile Value ret_17 = alg_nil();
    alg_root_top = rt_base;
    return ret_17;
}

static Value i_objoverloads(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Candidates", alg_nil());
    alg_set_property(v_this, "Fallback", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_objoverloads_init_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    (void)(alg_set_property(v_this, "Name", v_name));
    (void)(alg_set_property(v_this, "Candidates", alg_list()));
    (void)(alg_set_property(v_this, "Fallback", alg_nil()));
    Value ret_18 = alg_nil();
    alg_root_top = rt_base;
    return ret_18;
}

static Value m_objoverloads_add_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thefunction = args[0];
    (void)v_thefunction;
    alg_root(&v_thefunction, 1);
    (void)(alg_invoke(alg_property(v_this, "Candidates"), "Add", (Value[]){v_thefunction}, 1));
    Value ret_19 = alg_nil();
    alg_root_top = rt_base;
    return ret_19;
}

static Value m_objoverloads_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_20 = alg_negate(alg_int(1));
    alg_root_top = rt_base;
    return ret_20;
    Value ret_21 = alg_nil();
    alg_root_top = rt_base;
    return ret_21;
}

static Value m_objoverloads_declares_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_count = alg_widen(args[0], "Integer");
    (void)v_count;
    alg_root(&v_count, 1);
    {
        int32_t rt_268 = alg_root_top;
        Value loop_22 = alg_iterable(alg_property(v_this, "Candidates"));
        (void)loop_22;
        alg_root(&loop_22, 1);
        for (int32_t at_22 = 0; at_22 < alg_iterable_count(loop_22); at_22++) {
            int32_t rt_269 = alg_root_top;
            Value v_thecandidate = alg_iterable_at(loop_22, at_22);
            (void)v_thecandidate;
            alg_root(&v_thecandidate, 1);
            {
                if (alg_truthy(alg_equal(alg_invoke(v_thecandidate, "Arity", NULL, 0), v_count))) {
                    Value ret_23 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_23;
                }
                if (alg_truthy((or_0 = alg_invoke(v_thecandidate, "Variadic", NULL, 0), !alg_truthy(or_0) ? or_0 : alg_greater_equal(v_count, alg_subtract(alg_invoke(v_thecandidate, "Arity", NULL, 0), alg_int(1)))))) {
                    Value ret_24 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_24;
                }
            }
            alg_root_top = rt_269;
        }
        alg_root_top = rt_268;
    }
    Value ret_25 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_25;
    Value ret_26 = alg_nil();
    alg_root_top = rt_base;
    return ret_26;
}

static Value m_objoverloads_select_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    {
        int32_t rt_270 = alg_root_top;
        Value v_pass = (alg_declared(d_exact, "EXACT"), v_exact);
        (void)v_pass;
        alg_root(&v_pass, 1);
        for (; alg_truthy(alg_less_equal(v_pass, (alg_declared(d_absorbing, "ABSORBING"), v_absorbing))); (v_pass = alg_add(v_pass, alg_int(1)))) {
            {
                int32_t rt_271 = alg_root_top;
                Value loop_27 = alg_iterable(alg_property(v_this, "Candidates"));
                (void)loop_27;
                alg_root(&loop_27, 1);
                for (int32_t at_27 = 0; at_27 < alg_iterable_count(loop_27); at_27++) {
                    int32_t rt_272 = alg_root_top;
                    Value v_thecandidate = alg_iterable_at(loop_27, at_27);
                    (void)v_thecandidate;
                    alg_root(&v_thecandidate, 1);
                    if (alg_truthy(alg_invoke(v_thecandidate, "Selects", (Value[]){v_arguments, v_pass}, 2))) {
                        Value ret_28 = v_thecandidate;
                        alg_root_top = rt_base;
                        return ret_28;
                    }
                    alg_root_top = rt_272;
                }
                alg_root_top = rt_271;
            }
        }
        alg_root_top = rt_270;
    }
    if (alg_truthy((or_1 = alg_not_equal(alg_property(v_this, "Fallback"), alg_nil()), !alg_truthy(or_1) ? or_1 : alg_not(alg_invoke(v_this, "Declares", (Value[]){alg_property(v_arguments, "Length")}, 1))))) {
        if (alg_truthy((or_2 = alg_equal(alg_invoke(alg_property(v_this, "Fallback"), "Arity", NULL, 0), alg_negate(alg_int(1))), alg_truthy(or_2) ? or_2 : alg_equal(alg_invoke(alg_property(v_this, "Fallback"), "Arity", NULL, 0), alg_property(v_arguments, "Length"))))) {
            Value ret_29 = alg_property(v_this, "Fallback");
            alg_root_top = rt_base;
            return ret_29;
        }
    }
    Value ret_30 = alg_nil();
    alg_root_top = rt_base;
    return ret_30;
    Value ret_31 = alg_nil();
    alg_root_top = rt_base;
    return ret_31;
}

static Value m_objoverloads_call_2(Value v_this, Value *args, int32_t count) {
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
    Value v_chosen = alg_nil();
    (void)v_chosen;
    alg_root(&v_chosen, 1);
    (void)((v_chosen = alg_invoke(v_this, "Select", (Value[]){v_arguments}, 1)));
    if (alg_truthy(alg_equal(v_chosen, alg_nil()))) {
        alg_raise(alg_string("No matching signature for function."));
    }
    Value ret_32 = alg_invoke(v_chosen, "Call", (Value[]){v_theinterpreter, v_arguments}, 2);
    alg_root_top = rt_base;
    return ret_32;
    Value ret_33 = alg_nil();
    alg_root_top = rt_base;
    return ret_33;
}

static Value m_objoverloads_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_34 = alg_add(alg_add(alg_string("<fn "), alg_property(v_this, "Name")), alg_char_value(62));
    alg_root_top = rt_base;
    return ret_34;
    Value ret_35 = alg_nil();
    alg_root_top = rt_base;
    return ret_35;
}

static Value i_numbermethod(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_numbermethod_init_2_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_receiver = args[0];
    (void)v_receiver;
    alg_root(&v_receiver, 1);
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    (void)(alg_set_property(v_this, "Receiver", v_receiver));
    (void)(alg_set_property(v_this, "Name", v_name));
    Value ret_36 = alg_nil();
    alg_root_top = rt_base;
    return ret_36;
}

static Value m_numbermethod_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_37 = alg_int(0);
    alg_root_top = rt_base;
    return ret_37;
    Value ret_38 = alg_nil();
    alg_root_top = rt_base;
    return ret_38;
}

static Value m_numbermethod_call_2(Value v_this, Value *args, int32_t count) {
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
    Value ret_39 = alg_str(alg_property(v_this, "Receiver"));
    alg_root_top = rt_base;
    return ret_39;
    Value ret_40 = alg_nil();
    alg_root_top = rt_base;
    return ret_40;
}

static Value m_numbermethod_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_41 = alg_add(alg_add(alg_string("<fn "), alg_str(alg_property(alg_property(v_this, "Name"), "Lexeme"))), alg_char_value(62));
    alg_root_top = rt_base;
    return ret_41;
    Value ret_42 = alg_nil();
    alg_root_top = rt_base;
    return ret_42;
}

static Value i_objextension(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Target", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_objextension_init_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_receiver = args[0];
    (void)v_receiver;
    alg_root(&v_receiver, 1);
    Value v_target = args[1];
    (void)v_target;
    alg_root(&v_target, 1);
    (void)(alg_set_property(v_this, "Receiver", v_receiver));
    (void)(alg_set_property(v_this, "Target", v_target));
    Value ret_43 = alg_nil();
    alg_root_top = rt_base;
    return ret_43;
}

static Value m_objextension_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_less(alg_invoke(alg_property(v_this, "Target"), "Arity", NULL, 0), alg_int(0)))) {
        Value ret_44 = alg_negate(alg_int(1));
        alg_root_top = rt_base;
        return ret_44;
    }
    Value ret_45 = alg_subtract(alg_invoke(alg_property(v_this, "Target"), "Arity", NULL, 0), alg_int(1));
    alg_root_top = rt_base;
    return ret_45;
    Value ret_46 = alg_nil();
    alg_root_top = rt_base;
    return ret_46;
}

static Value m_objextension_call_2(Value v_this, Value *args, int32_t count) {
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
    Value v_all = alg_nil();
    (void)v_all;
    alg_root(&v_all, 1);
    (void)((v_all = alg_list()));
    (void)(alg_invoke(v_all, "Add", (Value[]){alg_property(v_this, "Receiver")}, 1));
    {
        int32_t rt_273 = alg_root_top;
        Value loop_47 = alg_iterable(v_arguments);
        (void)loop_47;
        alg_root(&loop_47, 1);
        for (int32_t at_47 = 0; at_47 < alg_iterable_count(loop_47); at_47++) {
            int32_t rt_274 = alg_root_top;
            Value v_argument = alg_iterable_at(loop_47, at_47);
            (void)v_argument;
            alg_root(&v_argument, 1);
            (void)(alg_invoke(v_all, "Add", (Value[]){v_argument}, 1));
            alg_root_top = rt_274;
        }
        alg_root_top = rt_273;
    }
    Value ret_48 = alg_invoke(alg_property(v_this, "Target"), "Call", (Value[]){v_theinterpreter, v_all}, 2);
    alg_root_top = rt_base;
    return ret_48;
    Value ret_49 = alg_nil();
    alg_root_top = rt_base;
    return ret_49;
}

static Value m_objextension_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_50 = alg_invoke(alg_property(v_this, "Target"), "ToString", NULL, 0);
    alg_root_top = rt_base;
    return ret_50;
    Value ret_51 = alg_nil();
    alg_root_top = rt_base;
    return ret_51;
}

Value f_samesignature(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_left = args[0];
    (void)v_left;
    alg_root(&v_left, 1);
    Value v_right = args[1];
    (void)v_right;
    alg_root(&v_right, 1);
    if (alg_truthy(alg_not_equal(alg_property(alg_property(v_left, "Params"), "Length"), alg_property(alg_property(v_right, "Params"), "Length")))) {
        Value ret_52 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_52;
    }
    {
        int32_t rt_275 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_left, "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_not_equal(f_underlyingtype(NULL, (Value[]){alg_subscript_get(alg_property(v_left, "ParamTypes"), v_i)}, 1), f_underlyingtype(NULL, (Value[]){alg_subscript_get(alg_property(v_right, "ParamTypes"), v_i)}, 1)))) {
                Value ret_53 = alg_bool(false);
                alg_root_top = rt_base;
                return ret_53;
            }
        }
        alg_root_top = rt_275;
    }
    Value ret_54 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_54;
    Value ret_55 = alg_nil();
    alg_root_top = rt_base;
    return ret_55;
}

Value f_anynamed(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_names = alg_param(args[0], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    {
        int32_t rt_276 = alg_root_top;
        Value loop_56 = alg_iterable(v_names);
        (void)loop_56;
        alg_root(&loop_56, 1);
        for (int32_t at_56 = 0; at_56 < alg_iterable_count(loop_56); at_56++) {
            int32_t rt_277 = alg_root_top;
            Value v_name = alg_iterable_at(loop_56, at_56);
            (void)v_name;
            alg_root(&v_name, 1);
            if (alg_truthy(alg_not_equal(alg_str(v_name), alg_string("")))) {
                Value ret_57 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_57;
            }
            alg_root_top = rt_277;
        }
        alg_root_top = rt_276;
    }
    Value ret_58 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_58;
    Value ret_59 = alg_nil();
    alg_root_top = rt_base;
    return ret_59;
}

Value f_widens(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_actual = alg_param(args[0], "String");
    (void)v_actual;
    alg_root(&v_actual, 1);
    Value v_declared = alg_param(args[1], "String");
    (void)v_declared;
    alg_root(&v_declared, 1);
    if (alg_truthy((or_3 = alg_equal(v_declared, alg_string("Double")), !alg_truthy(or_3) ? or_3 : alg_equal(v_actual, alg_string("Integer"))))) {
        Value ret_60 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_60;
    }
    if (alg_truthy((or_4 = alg_equal(v_declared, alg_string("String")), !alg_truthy(or_4) ? or_4 : alg_equal(v_actual, alg_string("Char"))))) {
        Value ret_61 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_61;
    }
    Value ret_62 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_62;
    Value ret_63 = alg_nil();
    alg_root_top = rt_base;
    return ret_63;
}

Value f_inheritsfrom(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    Value v_thename = alg_param(args[1], "String");
    (void)v_thename;
    alg_root(&v_thename, 1);
    Value v_klass = alg_nil();
    (void)v_klass;
    alg_root(&v_klass, 1);
    if (alg_truthy(alg_not((alg_is(v_value, "ObjInstance"))))) {
        Value ret_64 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_64;
    }
    (void)((v_klass = alg_cast(alg_property(v_value, "Klass"), "ObjClass")));
    while (alg_truthy(alg_not_equal(v_klass, alg_nil()))) {
        {
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(v_klass, "Name")}, 1), f_foldcase(NULL, (Value[]){v_thename}, 1)))) {
                Value ret_65 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_65;
            }
            (void)((v_klass = alg_property(v_klass, "Superclass")));
        }
    }
    Value ret_66 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_66;
    Value ret_67 = alg_nil();
    alg_root_top = rt_base;
    return ret_67;
}

static Value i_objfunction(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Declaration", alg_nil());
    alg_set_property(v_this, "Closure", alg_nil());
    alg_set_property(v_this, "IsInitializer", alg_nil());
    alg_set_property(v_this, "Owner", alg_widen(alg_nil(), "ObjClass"));
    alg_set_property(v_this, "Bound", alg_widen(alg_nil(), "ObjInstance"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_objfunction_init_3_functionstmt_environment_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_declaration = alg_widen(args[0], "FunctionStmt");
    (void)v_declaration;
    alg_root(&v_declaration, 1);
    Value v_closure = alg_widen(args[1], "Environment");
    (void)v_closure;
    alg_root(&v_closure, 1);
    Value v_isinitializer = alg_widen(args[2], "Boolean");
    (void)v_isinitializer;
    alg_root(&v_isinitializer, 1);
    (void)(alg_set_property(v_this, "Closure", v_closure));
    (void)(alg_set_property(v_this, "Declaration", v_declaration));
    (void)(alg_set_property(v_this, "IsInitializer", v_isinitializer));
    Value ret_68 = alg_nil();
    alg_root_top = rt_base;
    return ret_68;
}

static Value m_objfunction_bind_1_objinstance(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_instance = alg_widen(args[0], "ObjInstance");
    (void)v_instance;
    alg_root(&v_instance, 1);
    Value v_env = alg_nil();
    (void)v_env;
    alg_root(&v_env, 1);
    (void)((v_env = alg_new(k_environment, NULL, 0)));
    (void)(alg_set_property(v_env, "Enclosing", alg_property(v_this, "Closure")));
    (void)(alg_invoke(v_env, "Define", (Value[]){alg_string("this"), v_instance}, 2));
    Value v_result = alg_new(k_objfunction, (Value[]){alg_property(v_this, "Declaration"), v_env, alg_property(v_this, "IsInitializer")}, 3);
    (void)v_result;
    alg_root(&v_result, 1);
    (void)(alg_set_property(v_result, "Owner", alg_property(v_this, "Owner")));
    (void)(alg_set_property(v_result, "Bound", v_instance));
    Value ret_69 = v_result;
    alg_root_top = rt_base;
    return ret_69;
    Value ret_70 = alg_nil();
    alg_root_top = rt_base;
    return ret_70;
}

static Value m_objfunction_fitsat_3_string_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_argument = args[0];
    (void)v_argument;
    alg_root(&v_argument, 1);
    Value v_declared = alg_widen(args[1], "String");
    (void)v_declared;
    alg_root(&v_declared, 1);
    Value v_widening = alg_widen(args[2], "Boolean");
    (void)v_widening;
    alg_root(&v_widening, 1);
    Value v_wanted = f_underlyingtype(NULL, (Value[]){v_declared}, 1);
    (void)v_wanted;
    alg_root(&v_wanted, 1);
    if (alg_truthy((or_5 = alg_equal(v_wanted, alg_string("")), alg_truthy(or_5) ? or_5 : alg_equal(v_wanted, alg_string("Any"))))) {
        Value ret_71 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_71;
    }
    Value v_actual = f_typenameof(NULL, (Value[]){v_argument}, 1);
    (void)v_actual;
    alg_root(&v_actual, 1);
    if (alg_truthy((or_7 = (or_6 = alg_equal(v_actual, alg_string("nil")), alg_truthy(or_6) ? or_6 : alg_equal(v_actual, alg_string("Any"))), alg_truthy(or_7) ? or_7 : alg_equal(v_actual, v_wanted)))) {
        Value ret_72 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_72;
    }
    if (alg_truthy(f_inheritsfrom(NULL, (Value[]){v_argument, v_wanted}, 2))) {
        Value ret_73 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_73;
    }
    Value ret_74 = (or_8 = v_widening, !alg_truthy(or_8) ? or_8 : f_widens(NULL, (Value[]){v_actual, v_wanted}, 2));
    alg_root_top = rt_base;
    return ret_74;
    Value ret_75 = alg_nil();
    alg_root_top = rt_base;
    return ret_75;
}

static Value m_objfunction_fits_2_list_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_widening = alg_widen(args[1], "Boolean");
    (void)v_widening;
    alg_root(&v_widening, 1);
    if (alg_truthy(alg_not_equal(alg_invoke(v_this, "Arity", NULL, 0), alg_property(v_arguments, "Length")))) {
        Value ret_76 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_76;
    }
    {
        int32_t rt_278 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_arguments, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_not(alg_invoke(v_this, "FitsAt", (Value[]){alg_subscript_get(v_arguments, v_i), alg_str(alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "ParamTypes"), v_i)), v_widening}, 3)))) {
                Value ret_77 = alg_bool(false);
                alg_root_top = rt_base;
                return ret_77;
            }
        }
        alg_root_top = rt_278;
    }
    Value ret_78 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_78;
    Value ret_79 = alg_nil();
    alg_root_top = rt_base;
    return ret_79;
}

static Value m_objfunction_variadic_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_last = alg_nil();
    (void)v_last;
    alg_root(&v_last, 1);
    if (alg_truthy(alg_equal(alg_invoke(v_this, "Arity", NULL, 0), alg_int(0)))) {
        Value ret_80 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_80;
    }
    (void)((v_last = alg_subtract(alg_invoke(v_this, "Arity", NULL, 0), alg_int(1))));
    if (alg_truthy(alg_greater_equal(v_last, alg_property(alg_property(alg_property(v_this, "Declaration"), "ParamTypes"), "Length")))) {
        Value ret_81 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_81;
    }
    if (alg_truthy(alg_greater_equal(v_last, alg_property(alg_property(alg_property(v_this, "Declaration"), "ParamGenerics"), "Length")))) {
        Value ret_82 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_82;
    }
    Value ret_83 = (or_9 = alg_equal(f_canonicaltype(NULL, (Value[]){alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "ParamTypes"), v_last)}, 1), alg_string("List")), !alg_truthy(or_9) ? or_9 : alg_not_equal(alg_str(alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "ParamGenerics"), v_last)), alg_string("")));
    alg_root_top = rt_base;
    return ret_83;
    Value ret_84 = alg_nil();
    alg_root_top = rt_base;
    return ret_84;
}

static Value m_objfunction_absorbs_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_fixed = alg_nil();
    (void)v_fixed;
    alg_root(&v_fixed, 1);
    Value v_element = alg_nil();
    (void)v_element;
    alg_root(&v_element, 1);
    if (alg_truthy(alg_not(alg_invoke(v_this, "Variadic", NULL, 0)))) {
        Value ret_85 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_85;
    }
    (void)((v_fixed = alg_subtract(alg_invoke(v_this, "Arity", NULL, 0), alg_int(1))));
    if (alg_truthy(alg_less(alg_property(v_arguments, "Length"), v_fixed))) {
        Value ret_86 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_86;
    }
    {
        int32_t rt_279 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, v_fixed)); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_not(alg_invoke(v_this, "FitsAt", (Value[]){alg_subscript_get(v_arguments, v_i), alg_str(alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "ParamTypes"), v_i)), alg_bool(true)}, 3)))) {
                Value ret_87 = alg_bool(false);
                alg_root_top = rt_base;
                return ret_87;
            }
        }
        alg_root_top = rt_279;
    }
    (void)((v_element = alg_str(alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "ParamGenerics"), v_fixed))));
    {
        int32_t rt_280 = alg_root_top;
        Value v_i = v_fixed;
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_arguments, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_not(alg_invoke(v_this, "FitsAt", (Value[]){alg_subscript_get(v_arguments, v_i), v_element, alg_bool(true)}, 3)))) {
                Value ret_88 = alg_bool(false);
                alg_root_top = rt_base;
                return ret_88;
            }
        }
        alg_root_top = rt_280;
    }
    Value ret_89 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_89;
    Value ret_90 = alg_nil();
    alg_root_top = rt_base;
    return ret_90;
}

static Value m_objfunction_absorb_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_gathered = alg_nil();
    (void)v_gathered;
    alg_root(&v_gathered, 1);
    Value v_rest = alg_nil();
    (void)v_rest;
    alg_root(&v_rest, 1);
    if (alg_truthy(alg_invoke(v_this, "Fits", (Value[]){v_arguments, alg_bool(true)}, 2))) {
        Value ret_91 = v_arguments;
        alg_root_top = rt_base;
        return ret_91;
    }
    if (alg_truthy(alg_not(alg_invoke(v_this, "Absorbs", (Value[]){v_arguments}, 1)))) {
        Value ret_92 = v_arguments;
        alg_root_top = rt_base;
        return ret_92;
    }
    (void)((v_gathered = alg_list()));
    (void)((v_rest = alg_new(k_objcollection, (Value[]){alg_string("List")}, 1)));
    {
        int32_t rt_281 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_subtract(alg_invoke(v_this, "Arity", NULL, 0), alg_int(1)))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(v_gathered, "Add", (Value[]){alg_subscript_get(v_arguments, v_i)}, 1));
        }
        alg_root_top = rt_281;
    }
    {
        int32_t rt_282 = alg_root_top;
        Value v_i = alg_subtract(alg_invoke(v_this, "Arity", NULL, 0), alg_int(1));
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_arguments, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(alg_property(v_rest, "Items"), "Add", (Value[]){alg_subscript_get(v_arguments, v_i)}, 1));
        }
        alg_root_top = rt_282;
    }
    (void)(alg_invoke(v_gathered, "Add", (Value[]){v_rest}, 1));
    Value ret_93 = v_gathered;
    alg_root_top = rt_base;
    return ret_93;
    Value ret_94 = alg_nil();
    alg_root_top = rt_base;
    return ret_94;
}

static Value m_objfunction_parameterat_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thename = alg_widen(args[0], "String");
    (void)v_thename;
    alg_root(&v_thename, 1);
    {
        int32_t rt_283 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(alg_property(v_this, "Declaration"), "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "Params"), v_i), "Lexeme"))}, 1), f_foldcase(NULL, (Value[]){v_thename}, 1)))) {
                Value ret_95 = v_i;
                alg_root_top = rt_base;
                return ret_95;
            }
        }
        alg_root_top = rt_283;
    }
    Value ret_96 = alg_negate(alg_int(1));
    alg_root_top = rt_base;
    return ret_96;
    Value ret_97 = alg_nil();
    alg_root_top = rt_base;
    return ret_97;
}

static Value m_objfunction_arrange_2_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_names = alg_widen(args[1], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    Value v_slots = alg_nil();
    (void)v_slots;
    alg_root(&v_slots, 1);
    Value v_filled = alg_nil();
    (void)v_filled;
    alg_root(&v_filled, 1);
    if (alg_truthy(alg_not(f_anynamed(NULL, (Value[]){v_names}, 1)))) {
        Value ret_98 = v_arguments;
        alg_root_top = rt_base;
        return ret_98;
    }
    (void)((v_slots = alg_list()));
    (void)((v_filled = alg_list()));
    {
        int32_t rt_284 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_invoke(v_this, "Arity", NULL, 0))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                (void)(alg_invoke(v_slots, "Add", (Value[]){alg_nil()}, 1));
                (void)(alg_invoke(v_filled, "Add", (Value[]){alg_bool(false)}, 1));
            }
        }
        alg_root_top = rt_284;
    }
    {
        int32_t rt_285 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_arguments, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_286 = alg_root_top;
                Value v_thename = alg_string("");
                (void)v_thename;
                alg_root(&v_thename, 1);
                if (alg_truthy(alg_less(v_i, alg_property(v_names, "Length")))) {
                    (void)((v_thename = alg_str(alg_subscript_get(v_names, v_i))));
                }
                Value v_at = v_i;
                (void)v_at;
                alg_root(&v_at, 1);
                if (alg_truthy(alg_not_equal(v_thename, alg_string("")))) {
                    (void)((v_at = alg_invoke(v_this, "ParameterAt", (Value[]){v_thename}, 1)));
                }
                if (alg_truthy((or_10 = alg_less(v_at, alg_int(0)), alg_truthy(or_10) ? or_10 : alg_greater_equal(v_at, alg_property(v_slots, "Length"))))) {
                    Value ret_99 = alg_nil();
                    alg_root_top = rt_base;
                    return ret_99;
                }
                if (alg_truthy(alg_subscript_get(v_filled, v_at))) {
                    Value ret_100 = alg_nil();
                    alg_root_top = rt_base;
                    return ret_100;
                }
                (void)(alg_subscript_set(v_slots, v_at, alg_subscript_get(v_arguments, v_i)));
                (void)(alg_subscript_set(v_filled, v_at, alg_bool(true)));
                alg_root_top = rt_286;
            }
        }
        alg_root_top = rt_285;
    }
    {
        int32_t rt_287 = alg_root_top;
        Value loop_101 = alg_iterable(v_filled);
        (void)loop_101;
        alg_root(&loop_101, 1);
        for (int32_t at_101 = 0; at_101 < alg_iterable_count(loop_101); at_101++) {
            int32_t rt_288 = alg_root_top;
            Value v_each = alg_iterable_at(loop_101, at_101);
            (void)v_each;
            alg_root(&v_each, 1);
            if (alg_truthy(alg_not(v_each))) {
                Value ret_102 = alg_nil();
                alg_root_top = rt_base;
                return ret_102;
            }
            alg_root_top = rt_288;
        }
        alg_root_top = rt_287;
    }
    Value ret_103 = v_slots;
    alg_root_top = rt_base;
    return ret_103;
    Value ret_104 = alg_nil();
    alg_root_top = rt_base;
    return ret_104;
}

static Value m_objfunction_selects_2_list_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_pass = alg_widen(args[1], "Integer");
    (void)v_pass;
    alg_root(&v_pass, 1);
    if (alg_truthy(alg_equal(v_pass, (alg_declared(d_absorbing, "ABSORBING"), v_absorbing)))) {
        Value ret_105 = alg_invoke(v_this, "Absorbs", (Value[]){v_arguments}, 1);
        alg_root_top = rt_base;
        return ret_105;
    }
    Value ret_106 = alg_invoke(v_this, "Fits", (Value[]){v_arguments, alg_equal(v_pass, (alg_declared(d_widening, "WIDENING"), v_widening))}, 2);
    alg_root_top = rt_base;
    return ret_106;
    Value ret_107 = alg_nil();
    alg_root_top = rt_base;
    return ret_107;
}

static Value m_objfunction_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_equal(alg_property(alg_property(v_this, "Declaration"), "Params"), alg_nil()))) {
        Value ret_108 = alg_int(0);
        alg_root_top = rt_base;
        return ret_108;
    }
    Value ret_109 = alg_property(alg_property(alg_property(v_this, "Declaration"), "Params"), "Length");
    alg_root_top = rt_base;
    return ret_109;
    Value ret_110 = alg_nil();
    alg_root_top = rt_base;
    return ret_110;
}

static Value m_objfunction_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_111 = alg_add(alg_add(alg_string("<fn "), alg_property(alg_property(alg_property(v_this, "Declaration"), "Name"), "Lexeme")), alg_char_value(62));
    alg_root_top = rt_base;
    return ret_111;
    Value ret_112 = alg_nil();
    alg_root_top = rt_base;
    return ret_112;
}

static Value m_objfunction_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    alg_root(&v_theinterpreter, 1);
    volatile Value v_arguments = args[1];
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    volatile Value v_env = alg_nil();
    (void)v_env;
    alg_root(&v_env, 1);
    volatile Value v_count = alg_nil();
    (void)v_count;
    alg_root(&v_count, 1);
    (void)((v_env = alg_new(k_environment, NULL, 0)));
    (void)(alg_set_property(v_env, "Enclosing", alg_property(v_this, "Closure")));
    (void)((v_arguments = alg_invoke(v_this, "Absorb", (Value[]){v_arguments}, 1)));
    if (alg_truthy(alg_not_equal(alg_property(alg_property(v_this, "Declaration"), "Symbol"), alg_string("")))) {
        volatile Value ret_113 = alg_foreign_call(alg_property(alg_property(v_this, "Declaration"), "Symbol"), alg_property(alg_property(v_this, "Declaration"), "Library"), alg_property(alg_property(v_this, "Declaration"), "ParamTypes"), alg_property(alg_property(v_this, "Declaration"), "ReturnType"), v_arguments);
        alg_root_top = rt_base;
        return ret_113;
    }
    {
        int32_t rt_289 = alg_root_top;
        volatile Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(alg_property(v_this, "Declaration"), "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_290 = alg_root_top;
                volatile Value v_declared = alg_string("");
                (void)v_declared;
                alg_root(&v_declared, 1);
                if (alg_truthy(alg_less(v_i, alg_property(alg_property(alg_property(v_this, "Declaration"), "ParamTypes"), "Length")))) {
                    (void)((v_declared = alg_str(alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "ParamTypes"), v_i))));
                }
                (void)(alg_invoke(v_env, "Define", (Value[]){alg_property(alg_subscript_get(alg_property(alg_property(v_this, "Declaration"), "Params"), v_i), "Lexeme"), alg_invoke(v_theinterpreter, "Widen", (Value[]){alg_subscript_get(v_arguments, v_i), v_declared}, 2)}, 2));
                alg_root_top = rt_290;
            }
        }
        alg_root_top = rt_289;
    }
    {
        AlgFrame frame_114;
        alg_push_frame(&frame_114);
        if (ALG_SETJMP(frame_114.jump) == 0) {
            {
                (void)(alg_invoke(v_theinterpreter, "ExecuteBlock", (Value[]){alg_property(alg_property(v_this, "Declaration"), "Body"), v_env}, 2));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_114[] = {"Return"};
            int32_t which_114 = alg_handler(frame_114.raised, names_114, 1);
            if (which_114 == 0) {
                {
                    int32_t rt_291 = alg_root_top;
                    volatile Value v_e = frame_114.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    {
                        if (alg_truthy(alg_property(v_this, "IsInitializer"))) {
                            volatile Value ret_115 = alg_invoke(alg_property(v_this, "Closure"), "GetAt", (Value[]){alg_int(0), alg_string("this")}, 2);
                            alg_root_top = rt_base;
                            return ret_115;
                        }
                        volatile Value ret_116 = alg_invoke(v_theinterpreter, "Widen", (Value[]){alg_property(v_e, "Value"), alg_str(alg_property(alg_property(v_this, "Declaration"), "ReturnType"))}, 2);
                        alg_root_top = rt_base;
                        return ret_116;
                    }
                    alg_root_top = rt_291;
                }
            }
            else {
                alg_raise(frame_114.raised);
            }
        }
    }
    if (alg_truthy(alg_property(v_this, "IsInitializer"))) {
        volatile Value ret_117 = alg_invoke(alg_property(v_this, "Closure"), "GetAt", (Value[]){alg_int(0), alg_string("this")}, 2);
        alg_root_top = rt_base;
        return ret_117;
    }
    volatile Value ret_118 = alg_nil();
    alg_root_top = rt_base;
    return ret_118;
}

static Value *roots_ObjFunction[] = {
    &fn_typenameof,
    &fn_nameofclass,
    &k_objoverloads,
    &k_numbermethod,
    &k_objextension,
    &fn_samesignature,
    &fn_anynamed,
    &v_exact,
    &v_widening,
    &v_absorbing,
    &fn_widens,
    &fn_inheritsfrom,
    &k_objfunction,
};

void init_ObjFunction(void) {
    alg_roots(roots_ObjFunction, 13);
    k_objoverloads = alg_class("ObjOverloads", alg_nil());
    k_numbermethod = alg_class("NumberMethod", alg_nil());
    k_objextension = alg_class("ObjExtension", alg_nil());
    k_objfunction = alg_class("ObjFunction", alg_nil());
    fn_typenameof = alg_closure("TypeNameOf", f_typenameof, NULL, 0, 1, t_f_typenameof);
    fn_nameofclass = alg_closure("NameOfClass", f_nameofclass, NULL, 0, 1, t_f_nameofclass);
    alg_class_field(k_objoverloads, "Name");
    alg_class_field(k_objoverloads, "Candidates");
    alg_class_field(k_objoverloads, "Fallback");
    alg_class_initializer(k_objoverloads, i_objoverloads);
    alg_class_method(k_objoverloads, "Init", m_objoverloads_init_1_string, 1, t_objoverloads_init_1_string);
    alg_class_method(k_objoverloads, "Add", m_objoverloads_add_1, 1, t_objoverloads_add_1);
    alg_class_method(k_objoverloads, "Arity", m_objoverloads_arity_0, 0, NULL);
    alg_class_method(k_objoverloads, "Declares", m_objoverloads_declares_1_integer, 1, t_objoverloads_declares_1_integer);
    alg_class_method(k_objoverloads, "Select", m_objoverloads_select_1_list, 1, t_objoverloads_select_1_list);
    alg_class_method(k_objoverloads, "Call", m_objoverloads_call_2, 2, t_objoverloads_call_2);
    alg_class_method(k_objoverloads, "ToString", m_objoverloads_tostring_0, 0, NULL);
    alg_class_field(k_numbermethod, "Receiver");
    alg_class_field(k_numbermethod, "Name");
    alg_class_initializer(k_numbermethod, i_numbermethod);
    alg_class_method(k_numbermethod, "Init", m_numbermethod_init_2_token, 2, t_numbermethod_init_2_token);
    alg_class_method(k_numbermethod, "Arity", m_numbermethod_arity_0, 0, NULL);
    alg_class_method(k_numbermethod, "Call", m_numbermethod_call_2, 2, t_numbermethod_call_2);
    alg_class_method(k_numbermethod, "ToString", m_numbermethod_tostring_0, 0, NULL);
    alg_class_field(k_objextension, "Receiver");
    alg_class_field(k_objextension, "Target");
    alg_class_initializer(k_objextension, i_objextension);
    alg_class_method(k_objextension, "Init", m_objextension_init_2, 2, t_objextension_init_2);
    alg_class_method(k_objextension, "Arity", m_objextension_arity_0, 0, NULL);
    alg_class_method(k_objextension, "Call", m_objextension_call_2, 2, t_objextension_call_2);
    alg_class_method(k_objextension, "ToString", m_objextension_tostring_0, 0, NULL);
    fn_samesignature = alg_closure("SameSignature", f_samesignature, NULL, 0, 2, t_f_samesignature);
    fn_anynamed = alg_closure("AnyNamed", f_anynamed, NULL, 0, 1, t_f_anynamed);
    fn_widens = alg_closure("Widens", f_widens, NULL, 0, 2, t_f_widens);
    fn_inheritsfrom = alg_closure("InheritsFrom", f_inheritsfrom, NULL, 0, 2, t_f_inheritsfrom);
    alg_class_field(k_objfunction, "Declaration");
    alg_class_field(k_objfunction, "Closure");
    alg_class_field(k_objfunction, "IsInitializer");
    alg_class_field(k_objfunction, "Owner");
    alg_class_field(k_objfunction, "Bound");
    alg_class_initializer(k_objfunction, i_objfunction);
    alg_class_method(k_objfunction, "Init", m_objfunction_init_3_functionstmt_environment_boolean, 3, t_objfunction_init_3_functionstmt_environment_boolean);
    alg_class_method(k_objfunction, "Bind", m_objfunction_bind_1_objinstance, 1, t_objfunction_bind_1_objinstance);
    alg_class_method(k_objfunction, "FitsAt", m_objfunction_fitsat_3_string_boolean, 3, t_objfunction_fitsat_3_string_boolean);
    alg_class_method(k_objfunction, "Fits", m_objfunction_fits_2_list_boolean, 2, t_objfunction_fits_2_list_boolean);
    alg_class_method(k_objfunction, "Variadic", m_objfunction_variadic_0, 0, NULL);
    alg_class_method(k_objfunction, "Absorbs", m_objfunction_absorbs_1_list, 1, t_objfunction_absorbs_1_list);
    alg_class_method(k_objfunction, "Absorb", m_objfunction_absorb_1_list, 1, t_objfunction_absorb_1_list);
    alg_class_method(k_objfunction, "ParameterAt", m_objfunction_parameterat_1_string, 1, t_objfunction_parameterat_1_string);
    alg_class_method(k_objfunction, "Arrange", m_objfunction_arrange_2_list_list, 2, t_objfunction_arrange_2_list_list);
    alg_class_method(k_objfunction, "Selects", m_objfunction_selects_2_list_integer, 2, t_objfunction_selects_2_list_integer);
    alg_class_method(k_objfunction, "Arity", m_objfunction_arity_0, 0, NULL);
    alg_class_method(k_objfunction, "ToString", m_objfunction_tostring_0, 0, NULL);
    alg_class_method(k_objfunction, "Call", m_objfunction_call_2, 2, t_objfunction_call_2);
    init_Interpreter();
    v_exact = alg_int(0);
    d_exact = true;
    v_widening = alg_int(1);
    d_widening = true;
    v_absorbing = alg_int(2);
    d_absorbing = true;
}
