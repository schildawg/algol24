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
    int32_t rh_1130 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(v_value, alg_nil())))) {
        Value ret_0 = alg_literal("nil");
        alg_root_top = rt_base;
        return ret_0;
    }
    alg_hold_top = rh_1130;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_BOOLEAN))) {
        Value ret_1 = alg_literal("Boolean");
        alg_root_top = rt_base;
        return ret_1;
    }
    alg_hold_top = rh_1130;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_INTEGER))) {
        Value ret_2 = alg_literal("Integer");
        alg_root_top = rt_base;
        return ret_2;
    }
    alg_hold_top = rh_1130;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_DOUBLE))) {
        Value ret_3 = alg_literal("Double");
        alg_root_top = rt_base;
        return ret_3;
    }
    alg_hold_top = rh_1130;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_STRING))) {
        Value ret_4 = alg_literal("String");
        alg_root_top = rt_base;
        return ret_4;
    }
    alg_hold_top = rh_1130;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_CHAR))) {
        Value ret_5 = alg_literal("Char");
        alg_root_top = rt_base;
        return ret_5;
    }
    alg_hold_top = rh_1130;
    if (alg_truthy(alg_is_class(v_value, k_objinstance))) {
        Value ret_6 = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_value, "Klass")), "Name"))));
        alg_root_top = rt_base;
        return ret_6;
    }
    alg_hold_top = rh_1130;
    if (alg_truthy(alg_is_class(v_value, k_objcollection))) {
        Value ret_7 = alg_hold(alg_property(v_value, "Kind"));
        alg_root_top = rt_base;
        return ret_7;
    }
    alg_hold_top = rh_1130;
    if (alg_truthy(alg_is(v_value, "ObjEnum"))) {
        Value ret_8 = alg_hold(alg_property(v_value, "TypeName"));
        alg_root_top = rt_base;
        return ret_8;
    }
    alg_hold_top = rh_1130;
    if (alg_truthy(alg_is_class(v_value, k_objfile))) {
        Value ret_9 = alg_literal("TextFile");
        alg_root_top = rt_base;
        return ret_9;
    }
    alg_hold_top = rh_1130;
    if (alg_truthy(alg_is_class(v_value, k_objbuffer))) {
        Value ret_10 = alg_literal("Buffer");
        alg_root_top = rt_base;
        return ret_10;
    }
    alg_hold_top = rh_1130;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_POINTER))) {
        Value ret_11 = alg_literal("Pointer");
        alg_root_top = rt_base;
        return ret_11;
    }
    alg_hold_top = rh_1130;
    Value ret_12 = alg_hold(f_nameofclass(NULL, (Value[]){v_value}, 1));
    alg_root_top = rt_base;
    return ret_12;
    alg_hold_top = rh_1130;
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
    int32_t rh_1131 = alg_hold_top;
    {
        AlgFrame frame_14;
        alg_push_frame(&frame_14);
        if (ALG_SETJMP(frame_14.jump) == 0) {
            {
                int32_t rh_1132 = alg_hold_top;
                volatile Value ret_15 = alg_hold(alg_property(v_obj, "ClassName"));
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_15;
                alg_hold_top = rh_1132;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_14[] = {"String"};
            int32_t which_14 = alg_handler(frame_14.raised, names_14, 1);
            if (which_14 == 0) {
                {
                    int32_t rt_1133 = alg_root_top;
                    volatile Value v_e = frame_14.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_16 = alg_literal("");
                    alg_root_top = rt_base;
                    return ret_16;
                    alg_root_top = rt_1133;
                }
            }
            else {
                alg_raise(frame_14.raised);
            }
        }
    }
    alg_hold_top = rh_1131;
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
    int32_t rh_1134 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_1134;
    (void)(alg_hold(alg_set_property(v_this, "Candidates", alg_hold(alg_list()))));
    alg_hold_top = rh_1134;
    (void)(alg_hold(alg_set_property(v_this, "Fallback", alg_nil())));
    alg_hold_top = rh_1134;
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
    int32_t rh_1135 = alg_hold_top;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Candidates"), "Add", (Value[]){v_thefunction}, 1)));
    alg_hold_top = rh_1135;
    Value ret_19 = alg_nil();
    alg_root_top = rt_base;
    return ret_19;
}

static Value m_objoverloads_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1136 = alg_hold_top;
    Value ret_20 = alg_hold(alg_negate(alg_int(1)));
    alg_root_top = rt_base;
    return ret_20;
    alg_hold_top = rh_1136;
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
    int32_t rh_1137 = alg_hold_top;
    {
        int32_t rt_1138 = alg_root_top;
        Value loop_22 = alg_iterable(alg_property(v_this, "Candidates"));
        (void)loop_22;
        alg_root(&loop_22, 1);
        for (int32_t at_22 = 0; at_22 < alg_iterable_count(loop_22); at_22++) {
            alg_safe_point();
            int32_t rt_1139 = alg_root_top;
            Value v_thecandidate = alg_iterable_at(loop_22, at_22);
            (void)v_thecandidate;
            alg_root(&v_thecandidate, 1);
            {
                int32_t rh_1140 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_invoke(v_thecandidate, "Arity", NULL, 0)), v_count)))) {
                    Value ret_23 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_23;
                }
                alg_hold_top = rh_1140;
                if (alg_truthy(alg_hold((or_0 = alg_hold(alg_invoke(v_thecandidate, "Variadic", NULL, 0)), !alg_truthy(or_0) ? or_0 : alg_hold(alg_greater_equal(v_count, alg_hold(alg_subtract(alg_hold(alg_invoke(v_thecandidate, "Arity", NULL, 0)), alg_int(1))))))))) {
                    Value ret_24 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_24;
                }
                alg_hold_top = rh_1140;
            }
            alg_root_top = rt_1139;
        }
        alg_root_top = rt_1138;
    }
    alg_hold_top = rh_1137;
    Value ret_25 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_25;
    alg_hold_top = rh_1137;
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
    int32_t rh_1141 = alg_hold_top;
    {
        int32_t rt_1142 = alg_root_top;
        int32_t rh_1143 = alg_hold_top;
        Value v_pass = (alg_declared(d_exact, "EXACT"), v_exact);
        (void)v_pass;
        alg_root(&v_pass, 1);
        alg_hold_top = rh_1143;
        {
            int32_t rh_1144 = alg_hold_top;
            for (; (alg_hold_top = rh_1144, alg_truthy(alg_hold(alg_less_equal(v_pass, (alg_declared(d_absorbing, "ABSORBING"), v_absorbing))))); (alg_hold_top = rh_1144, (v_pass = alg_hold(alg_add(v_pass, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1145 = alg_root_top;
                    Value loop_27 = alg_iterable(alg_property(v_this, "Candidates"));
                    (void)loop_27;
                    alg_root(&loop_27, 1);
                    for (int32_t at_27 = 0; at_27 < alg_iterable_count(loop_27); at_27++) {
                        alg_safe_point();
                        int32_t rt_1146 = alg_root_top;
                        Value v_thecandidate = alg_iterable_at(loop_27, at_27);
                        (void)v_thecandidate;
                        alg_root(&v_thecandidate, 1);
                        if (alg_truthy(alg_hold(alg_invoke(v_thecandidate, "Selects", (Value[]){v_arguments, v_pass}, 2)))) {
                            Value ret_28 = v_thecandidate;
                            alg_root_top = rt_base;
                            return ret_28;
                        }
                        alg_root_top = rt_1146;
                    }
                    alg_root_top = rt_1145;
                }
            }
        }
        alg_hold_top = rh_1143;
        alg_root_top = rt_1142;
    }
    alg_hold_top = rh_1141;
    if (alg_truthy(alg_hold((or_1 = alg_hold(alg_not_equal(alg_property(v_this, "Fallback"), alg_nil())), !alg_truthy(or_1) ? or_1 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Declares", (Value[]){alg_hold(alg_property(v_arguments, "Length"))}, 1)))))))) {
        if (alg_truthy(alg_hold((or_2 = alg_hold(alg_equal(alg_hold(alg_invoke(alg_property(v_this, "Fallback"), "Arity", NULL, 0)), alg_hold(alg_negate(alg_int(1))))), alg_truthy(or_2) ? or_2 : alg_hold(alg_equal(alg_hold(alg_invoke(alg_property(v_this, "Fallback"), "Arity", NULL, 0)), alg_hold(alg_property(v_arguments, "Length")))))))) {
            Value ret_29 = alg_property(v_this, "Fallback");
            alg_root_top = rt_base;
            return ret_29;
        }
    }
    alg_hold_top = rh_1141;
    Value ret_30 = alg_nil();
    alg_root_top = rt_base;
    return ret_30;
    alg_hold_top = rh_1141;
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
    int32_t rh_1147 = alg_hold_top;
    Value v_chosen = alg_nil();
    (void)v_chosen;
    alg_root(&v_chosen, 1);
    alg_hold_top = rh_1147;
    (void)((v_chosen = alg_hold(alg_invoke(v_this, "Select", (Value[]){v_arguments}, 1))));
    alg_hold_top = rh_1147;
    if (alg_truthy(alg_hold(alg_equal(v_chosen, alg_nil())))) {
        alg_raise(alg_literal("No matching signature for function."));
    }
    alg_hold_top = rh_1147;
    Value ret_32 = alg_hold(alg_invoke(v_chosen, "Call", (Value[]){v_theinterpreter, v_arguments}, 2));
    alg_root_top = rt_base;
    return ret_32;
    alg_hold_top = rh_1147;
    Value ret_33 = alg_nil();
    alg_root_top = rt_base;
    return ret_33;
}

static Value m_objoverloads_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1148 = alg_hold_top;
    Value ret_34 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("<fn "), alg_property(v_this, "Name"))), alg_char_value(62)));
    alg_root_top = rt_base;
    return ret_34;
    alg_hold_top = rh_1148;
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
    int32_t rh_1149 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Receiver", v_receiver)));
    alg_hold_top = rh_1149;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_1149;
    Value ret_36 = alg_nil();
    alg_root_top = rt_base;
    return ret_36;
}

static Value m_numbermethod_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1150 = alg_hold_top;
    Value ret_37 = alg_int(0);
    alg_root_top = rt_base;
    return ret_37;
    alg_hold_top = rh_1150;
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
    int32_t rh_1151 = alg_hold_top;
    Value ret_39 = alg_hold(alg_str(alg_property(v_this, "Receiver")));
    alg_root_top = rt_base;
    return ret_39;
    alg_hold_top = rh_1151;
    Value ret_40 = alg_nil();
    alg_root_top = rt_base;
    return ret_40;
}

static Value m_numbermethod_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1152 = alg_hold_top;
    Value ret_41 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("<fn "), alg_hold(alg_str(alg_hold(alg_property(alg_property(v_this, "Name"), "Lexeme")))))), alg_char_value(62)));
    alg_root_top = rt_base;
    return ret_41;
    alg_hold_top = rh_1152;
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
    int32_t rh_1153 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Receiver", v_receiver)));
    alg_hold_top = rh_1153;
    (void)(alg_hold(alg_set_property(v_this, "Target", v_target)));
    alg_hold_top = rh_1153;
    Value ret_43 = alg_nil();
    alg_root_top = rt_base;
    return ret_43;
}

static Value m_objextension_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1154 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_less(alg_hold(alg_invoke(alg_property(v_this, "Target"), "Arity", NULL, 0)), alg_int(0))))) {
        Value ret_44 = alg_hold(alg_negate(alg_int(1)));
        alg_root_top = rt_base;
        return ret_44;
    }
    alg_hold_top = rh_1154;
    Value ret_45 = alg_hold(alg_subtract(alg_hold(alg_invoke(alg_property(v_this, "Target"), "Arity", NULL, 0)), alg_int(1)));
    alg_root_top = rt_base;
    return ret_45;
    alg_hold_top = rh_1154;
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
    int32_t rh_1155 = alg_hold_top;
    Value v_all = alg_nil();
    (void)v_all;
    alg_root(&v_all, 1);
    alg_hold_top = rh_1155;
    (void)((v_all = alg_hold(alg_list())));
    alg_hold_top = rh_1155;
    (void)(alg_hold(alg_invoke(v_all, "Add", (Value[]){alg_property(v_this, "Receiver")}, 1)));
    alg_hold_top = rh_1155;
    {
        int32_t rt_1156 = alg_root_top;
        Value loop_47 = alg_iterable(v_arguments);
        (void)loop_47;
        alg_root(&loop_47, 1);
        for (int32_t at_47 = 0; at_47 < alg_iterable_count(loop_47); at_47++) {
            alg_safe_point();
            int32_t rt_1157 = alg_root_top;
            Value v_argument = alg_iterable_at(loop_47, at_47);
            (void)v_argument;
            alg_root(&v_argument, 1);
            (void)(alg_hold(alg_invoke(v_all, "Add", (Value[]){v_argument}, 1)));
            alg_root_top = rt_1157;
        }
        alg_root_top = rt_1156;
    }
    alg_hold_top = rh_1155;
    Value ret_48 = alg_hold(alg_invoke(alg_property(v_this, "Target"), "Call", (Value[]){v_theinterpreter, v_all}, 2));
    alg_root_top = rt_base;
    return ret_48;
    alg_hold_top = rh_1155;
    Value ret_49 = alg_nil();
    alg_root_top = rt_base;
    return ret_49;
}

static Value m_objextension_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1158 = alg_hold_top;
    Value ret_50 = alg_hold(alg_invoke(alg_property(v_this, "Target"), "ToString", NULL, 0));
    alg_root_top = rt_base;
    return ret_50;
    alg_hold_top = rh_1158;
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
    int32_t rh_1159 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(alg_hold(alg_property(v_left, "Params")), "Length")), alg_hold(alg_property(alg_hold(alg_property(v_right, "Params")), "Length")))))) {
        Value ret_52 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_52;
    }
    alg_hold_top = rh_1159;
    {
        int32_t rt_1160 = alg_root_top;
        int32_t rh_1161 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1161;
        {
            int32_t rh_1162 = alg_hold_top;
            for (; (alg_hold_top = rh_1162, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_left, "Params")), "Length")))))); (alg_hold_top = rh_1162, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold(alg_not_equal(alg_hold(f_underlyingtype(NULL, (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_left, "ParamTypes")), v_i))}, 1)), alg_hold(f_underlyingtype(NULL, (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_right, "ParamTypes")), v_i))}, 1)))))) {
                    Value ret_53 = alg_bool(false);
                    alg_root_top = rt_base;
                    return ret_53;
                }
            }
        }
        alg_hold_top = rh_1161;
        alg_root_top = rt_1160;
    }
    alg_hold_top = rh_1159;
    Value ret_54 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_54;
    alg_hold_top = rh_1159;
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
    int32_t rh_1163 = alg_hold_top;
    {
        int32_t rt_1164 = alg_root_top;
        Value loop_56 = alg_iterable(v_names);
        (void)loop_56;
        alg_root(&loop_56, 1);
        for (int32_t at_56 = 0; at_56 < alg_iterable_count(loop_56); at_56++) {
            alg_safe_point();
            int32_t rt_1165 = alg_root_top;
            Value v_name = alg_iterable_at(loop_56, at_56);
            (void)v_name;
            alg_root(&v_name, 1);
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_str(v_name)), alg_literal(""))))) {
                Value ret_57 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_57;
            }
            alg_root_top = rt_1165;
        }
        alg_root_top = rt_1164;
    }
    alg_hold_top = rh_1163;
    Value ret_58 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_58;
    alg_hold_top = rh_1163;
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
    int32_t rh_1166 = alg_hold_top;
    if (alg_truthy(alg_hold((or_3 = alg_hold(alg_equal(v_declared, alg_literal("Double"))), !alg_truthy(or_3) ? or_3 : alg_hold(alg_equal(v_actual, alg_literal("Integer"))))))) {
        Value ret_60 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_60;
    }
    alg_hold_top = rh_1166;
    if (alg_truthy(alg_hold((or_4 = alg_hold(alg_equal(v_declared, alg_literal("String"))), !alg_truthy(or_4) ? or_4 : alg_hold(alg_equal(v_actual, alg_literal("Char"))))))) {
        Value ret_61 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_61;
    }
    alg_hold_top = rh_1166;
    Value ret_62 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_62;
    alg_hold_top = rh_1166;
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
    int32_t rh_1167 = alg_hold_top;
    Value v_klass = alg_nil();
    (void)v_klass;
    alg_root(&v_klass, 1);
    alg_hold_top = rh_1167;
    if (alg_truthy(alg_hold(alg_not((alg_is_class(v_value, k_objinstance)))))) {
        Value ret_64 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_64;
    }
    alg_hold_top = rh_1167;
    (void)((v_klass = alg_hold(alg_cast_class(alg_property(v_value, "Klass"), k_objclass, "ObjClass"))));
    alg_hold_top = rh_1167;
    {
        int32_t rh_1168 = alg_hold_top;
        while ((alg_hold_top = rh_1168, alg_truthy(alg_hold(alg_not_equal(v_klass, alg_nil()))))) {
            alg_safe_point();
            {
                int32_t rh_1169 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_klass, "Name"))}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_thename}, 1)))))) {
                    Value ret_65 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_65;
                }
                alg_hold_top = rh_1169;
                (void)((v_klass = alg_hold(alg_property(v_klass, "Superclass"))));
                alg_hold_top = rh_1169;
            }
        }
    }
    alg_hold_top = rh_1167;
    Value ret_66 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_66;
    alg_hold_top = rh_1167;
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
    int32_t rh_1170 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Closure", v_closure)));
    alg_hold_top = rh_1170;
    (void)(alg_hold(alg_set_property(v_this, "Declaration", v_declaration)));
    alg_hold_top = rh_1170;
    (void)(alg_hold(alg_set_property(v_this, "IsInitializer", v_isinitializer)));
    alg_hold_top = rh_1170;
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
    int32_t rh_1171 = alg_hold_top;
    Value v_env = alg_nil();
    (void)v_env;
    alg_root(&v_env, 1);
    alg_hold_top = rh_1171;
    (void)((v_env = alg_hold(alg_new(k_environment, NULL, 0))));
    alg_hold_top = rh_1171;
    (void)(alg_hold(alg_set_property(v_env, "Enclosing", alg_property(v_this, "Closure"))));
    alg_hold_top = rh_1171;
    (void)(alg_hold(alg_invoke(v_env, "Define", (Value[]){alg_literal("this"), v_instance}, 2)));
    alg_hold_top = rh_1171;
    Value v_result = alg_hold(alg_new(k_objfunction, (Value[]){alg_property(v_this, "Declaration"), v_env, alg_property(v_this, "IsInitializer")}, 3));
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_1171;
    (void)(alg_hold(alg_set_property(v_result, "Owner", alg_property(v_this, "Owner"))));
    alg_hold_top = rh_1171;
    (void)(alg_hold(alg_set_property(v_result, "Bound", v_instance)));
    alg_hold_top = rh_1171;
    Value ret_69 = v_result;
    alg_root_top = rt_base;
    return ret_69;
    alg_hold_top = rh_1171;
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
    int32_t rh_1172 = alg_hold_top;
    Value v_wanted = alg_hold(f_underlyingtype(NULL, (Value[]){v_declared}, 1));
    (void)v_wanted;
    alg_root(&v_wanted, 1);
    alg_hold_top = rh_1172;
    if (alg_truthy(alg_hold((or_5 = alg_hold(alg_equal(v_wanted, alg_literal(""))), alg_truthy(or_5) ? or_5 : alg_hold(alg_equal(v_wanted, alg_literal("Any"))))))) {
        Value ret_71 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_71;
    }
    alg_hold_top = rh_1172;
    Value v_actual = alg_hold(f_typenameof(NULL, (Value[]){v_argument}, 1));
    (void)v_actual;
    alg_root(&v_actual, 1);
    alg_hold_top = rh_1172;
    if (alg_truthy(alg_hold((or_7 = alg_hold((or_6 = alg_hold(alg_equal(v_actual, alg_literal("nil"))), alg_truthy(or_6) ? or_6 : alg_hold(alg_equal(v_actual, alg_literal("Any"))))), alg_truthy(or_7) ? or_7 : alg_hold(alg_equal(v_actual, v_wanted)))))) {
        Value ret_72 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_72;
    }
    alg_hold_top = rh_1172;
    if (alg_truthy(alg_hold(f_inheritsfrom(NULL, (Value[]){v_argument, v_wanted}, 2)))) {
        Value ret_73 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_73;
    }
    alg_hold_top = rh_1172;
    Value ret_74 = alg_hold((or_8 = v_widening, !alg_truthy(or_8) ? or_8 : alg_hold(f_widens(NULL, (Value[]){v_actual, v_wanted}, 2))));
    alg_root_top = rt_base;
    return ret_74;
    alg_hold_top = rh_1172;
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
    int32_t rh_1173 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_invoke(v_this, "Arity", NULL, 0)), alg_hold(alg_property(v_arguments, "Length")))))) {
        Value ret_76 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_76;
    }
    alg_hold_top = rh_1173;
    {
        int32_t rt_1174 = alg_root_top;
        int32_t rh_1175 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1175;
        {
            int32_t rh_1176 = alg_hold_top;
            for (; (alg_hold_top = rh_1176, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_arguments, "Length")))))); (alg_hold_top = rh_1176, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "FitsAt", (Value[]){alg_hold(alg_subscript_get(v_arguments, v_i)), alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(alg_property(v_this, "Declaration"), "ParamTypes")), v_i)))), v_widening}, 3)))))) {
                    Value ret_77 = alg_bool(false);
                    alg_root_top = rt_base;
                    return ret_77;
                }
            }
        }
        alg_hold_top = rh_1175;
        alg_root_top = rt_1174;
    }
    alg_hold_top = rh_1173;
    Value ret_78 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_78;
    alg_hold_top = rh_1173;
    Value ret_79 = alg_nil();
    alg_root_top = rt_base;
    return ret_79;
}

static Value m_objfunction_variadic_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1177 = alg_hold_top;
    Value v_last = alg_nil();
    (void)v_last;
    alg_root(&v_last, 1);
    alg_hold_top = rh_1177;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "Arity", NULL, 0)), alg_int(0))))) {
        Value ret_80 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_80;
    }
    alg_hold_top = rh_1177;
    (void)((v_last = alg_hold(alg_subtract(alg_hold(alg_invoke(v_this, "Arity", NULL, 0)), alg_int(1)))));
    alg_hold_top = rh_1177;
    if (alg_truthy(alg_hold(alg_greater_equal(v_last, alg_hold(alg_property(alg_hold(alg_property(alg_property(v_this, "Declaration"), "ParamTypes")), "Length")))))) {
        Value ret_81 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_81;
    }
    alg_hold_top = rh_1177;
    if (alg_truthy(alg_hold(alg_greater_equal(v_last, alg_hold(alg_property(alg_hold(alg_property(alg_property(v_this, "Declaration"), "ParamGenerics")), "Length")))))) {
        Value ret_82 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_82;
    }
    alg_hold_top = rh_1177;
    Value ret_83 = alg_hold((or_9 = alg_hold(alg_equal(alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(alg_property(v_this, "Declaration"), "ParamTypes")), v_last))}, 1)), alg_literal("List"))), !alg_truthy(or_9) ? or_9 : alg_hold(alg_not_equal(alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(alg_property(v_this, "Declaration"), "ParamGenerics")), v_last)))), alg_literal("")))));
    alg_root_top = rt_base;
    return ret_83;
    alg_hold_top = rh_1177;
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
    int32_t rh_1178 = alg_hold_top;
    Value v_fixed = alg_nil();
    (void)v_fixed;
    alg_root(&v_fixed, 1);
    alg_hold_top = rh_1178;
    Value v_element = alg_nil();
    (void)v_element;
    alg_root(&v_element, 1);
    alg_hold_top = rh_1178;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Variadic", NULL, 0)))))) {
        Value ret_85 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_85;
    }
    alg_hold_top = rh_1178;
    (void)((v_fixed = alg_hold(alg_subtract(alg_hold(alg_invoke(v_this, "Arity", NULL, 0)), alg_int(1)))));
    alg_hold_top = rh_1178;
    if (alg_truthy(alg_hold(alg_less(alg_hold(alg_property(v_arguments, "Length")), v_fixed)))) {
        Value ret_86 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_86;
    }
    alg_hold_top = rh_1178;
    {
        int32_t rt_1179 = alg_root_top;
        int32_t rh_1180 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1180;
        {
            int32_t rh_1181 = alg_hold_top;
            for (; (alg_hold_top = rh_1181, alg_truthy(alg_hold(alg_less(v_i, v_fixed)))); (alg_hold_top = rh_1181, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "FitsAt", (Value[]){alg_hold(alg_subscript_get(v_arguments, v_i)), alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(alg_property(v_this, "Declaration"), "ParamTypes")), v_i)))), alg_bool(true)}, 3)))))) {
                    Value ret_87 = alg_bool(false);
                    alg_root_top = rt_base;
                    return ret_87;
                }
            }
        }
        alg_hold_top = rh_1180;
        alg_root_top = rt_1179;
    }
    alg_hold_top = rh_1178;
    (void)((v_element = alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(alg_property(v_this, "Declaration"), "ParamGenerics")), v_fixed))))));
    alg_hold_top = rh_1178;
    {
        int32_t rt_1182 = alg_root_top;
        int32_t rh_1183 = alg_hold_top;
        Value v_i = v_fixed;
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1183;
        {
            int32_t rh_1184 = alg_hold_top;
            for (; (alg_hold_top = rh_1184, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_arguments, "Length")))))); (alg_hold_top = rh_1184, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "FitsAt", (Value[]){alg_hold(alg_subscript_get(v_arguments, v_i)), v_element, alg_bool(true)}, 3)))))) {
                    Value ret_88 = alg_bool(false);
                    alg_root_top = rt_base;
                    return ret_88;
                }
            }
        }
        alg_hold_top = rh_1183;
        alg_root_top = rt_1182;
    }
    alg_hold_top = rh_1178;
    Value ret_89 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_89;
    alg_hold_top = rh_1178;
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
    int32_t rh_1185 = alg_hold_top;
    Value v_gathered = alg_nil();
    (void)v_gathered;
    alg_root(&v_gathered, 1);
    alg_hold_top = rh_1185;
    Value v_rest = alg_nil();
    (void)v_rest;
    alg_root(&v_rest, 1);
    alg_hold_top = rh_1185;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Fits", (Value[]){v_arguments, alg_bool(true)}, 2)))) {
        Value ret_91 = v_arguments;
        alg_root_top = rt_base;
        return ret_91;
    }
    alg_hold_top = rh_1185;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Absorbs", (Value[]){v_arguments}, 1)))))) {
        Value ret_92 = v_arguments;
        alg_root_top = rt_base;
        return ret_92;
    }
    alg_hold_top = rh_1185;
    (void)((v_gathered = alg_hold(alg_list())));
    alg_hold_top = rh_1185;
    (void)((v_rest = alg_hold(alg_new(k_objcollection, (Value[]){alg_literal("List")}, 1))));
    alg_hold_top = rh_1185;
    {
        int32_t rt_1186 = alg_root_top;
        int32_t rh_1187 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1187;
        {
            int32_t rh_1188 = alg_hold_top;
            for (; (alg_hold_top = rh_1188, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_subtract(alg_hold(alg_invoke(v_this, "Arity", NULL, 0)), alg_int(1))))))); (alg_hold_top = rh_1188, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                (void)(alg_hold(alg_invoke(v_gathered, "Add", (Value[]){alg_hold(alg_subscript_get(v_arguments, v_i))}, 1)));
            }
        }
        alg_hold_top = rh_1187;
        alg_root_top = rt_1186;
    }
    alg_hold_top = rh_1185;
    {
        int32_t rt_1189 = alg_root_top;
        int32_t rh_1190 = alg_hold_top;
        Value v_i = alg_hold(alg_subtract(alg_hold(alg_invoke(v_this, "Arity", NULL, 0)), alg_int(1)));
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1190;
        {
            int32_t rh_1191 = alg_hold_top;
            for (; (alg_hold_top = rh_1191, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_arguments, "Length")))))); (alg_hold_top = rh_1191, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                (void)(alg_hold(alg_invoke(alg_hold(alg_property(v_rest, "Items")), "Add", (Value[]){alg_hold(alg_subscript_get(v_arguments, v_i))}, 1)));
            }
        }
        alg_hold_top = rh_1190;
        alg_root_top = rt_1189;
    }
    alg_hold_top = rh_1185;
    (void)(alg_hold(alg_invoke(v_gathered, "Add", (Value[]){v_rest}, 1)));
    alg_hold_top = rh_1185;
    Value ret_93 = v_gathered;
    alg_root_top = rt_base;
    return ret_93;
    alg_hold_top = rh_1185;
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
    int32_t rh_1192 = alg_hold_top;
    {
        int32_t rt_1193 = alg_root_top;
        int32_t rh_1194 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1194;
        {
            int32_t rh_1195 = alg_hold_top;
            for (; (alg_hold_top = rh_1195, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(alg_property(v_this, "Declaration"), "Params")), "Length")))))); (alg_hold_top = rh_1195, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_subscript_get(alg_hold(alg_property(alg_property(v_this, "Declaration"), "Params")), v_i)), "Lexeme"))))}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_thename}, 1)))))) {
                    Value ret_95 = v_i;
                    alg_root_top = rt_base;
                    return ret_95;
                }
            }
        }
        alg_hold_top = rh_1194;
        alg_root_top = rt_1193;
    }
    alg_hold_top = rh_1192;
    Value ret_96 = alg_hold(alg_negate(alg_int(1)));
    alg_root_top = rt_base;
    return ret_96;
    alg_hold_top = rh_1192;
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
    int32_t rh_1196 = alg_hold_top;
    Value v_slots = alg_nil();
    (void)v_slots;
    alg_root(&v_slots, 1);
    alg_hold_top = rh_1196;
    Value v_filled = alg_nil();
    (void)v_filled;
    alg_root(&v_filled, 1);
    alg_hold_top = rh_1196;
    if (alg_truthy(alg_hold(alg_not(alg_hold(f_anynamed(NULL, (Value[]){v_names}, 1)))))) {
        Value ret_98 = v_arguments;
        alg_root_top = rt_base;
        return ret_98;
    }
    alg_hold_top = rh_1196;
    (void)((v_slots = alg_hold(alg_list())));
    alg_hold_top = rh_1196;
    (void)((v_filled = alg_hold(alg_list())));
    alg_hold_top = rh_1196;
    {
        int32_t rt_1197 = alg_root_top;
        int32_t rh_1198 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1198;
        {
            int32_t rh_1199 = alg_hold_top;
            for (; (alg_hold_top = rh_1199, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_invoke(v_this, "Arity", NULL, 0)))))); (alg_hold_top = rh_1199, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_1200 = alg_hold_top;
                    (void)(alg_hold(alg_invoke(v_slots, "Add", (Value[]){alg_nil()}, 1)));
                    alg_hold_top = rh_1200;
                    (void)(alg_hold(alg_invoke(v_filled, "Add", (Value[]){alg_bool(false)}, 1)));
                    alg_hold_top = rh_1200;
                }
            }
        }
        alg_hold_top = rh_1198;
        alg_root_top = rt_1197;
    }
    alg_hold_top = rh_1196;
    {
        int32_t rt_1201 = alg_root_top;
        int32_t rh_1202 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1202;
        {
            int32_t rh_1203 = alg_hold_top;
            for (; (alg_hold_top = rh_1203, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_arguments, "Length")))))); (alg_hold_top = rh_1203, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1204 = alg_root_top;
                    int32_t rh_1205 = alg_hold_top;
                    Value v_thename = alg_literal("");
                    (void)v_thename;
                    alg_root(&v_thename, 1);
                    alg_hold_top = rh_1205;
                    if (alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_names, "Length")))))) {
                        (void)((v_thename = alg_hold(alg_str(alg_hold(alg_subscript_get(v_names, v_i))))));
                    }
                    alg_hold_top = rh_1205;
                    Value v_at = v_i;
                    (void)v_at;
                    alg_root(&v_at, 1);
                    alg_hold_top = rh_1205;
                    if (alg_truthy(alg_hold(alg_not_equal(v_thename, alg_literal(""))))) {
                        (void)((v_at = alg_hold(alg_invoke(v_this, "ParameterAt", (Value[]){v_thename}, 1))));
                    }
                    alg_hold_top = rh_1205;
                    if (alg_truthy(alg_hold((or_10 = alg_hold(alg_less(v_at, alg_int(0))), alg_truthy(or_10) ? or_10 : alg_hold(alg_greater_equal(v_at, alg_hold(alg_property(v_slots, "Length")))))))) {
                        Value ret_99 = alg_nil();
                        alg_root_top = rt_base;
                        return ret_99;
                    }
                    alg_hold_top = rh_1205;
                    if (alg_truthy(alg_hold(alg_subscript_get(v_filled, v_at)))) {
                        Value ret_100 = alg_nil();
                        alg_root_top = rt_base;
                        return ret_100;
                    }
                    alg_hold_top = rh_1205;
                    (void)(alg_hold(alg_subscript_set(v_slots, v_at, alg_hold(alg_subscript_get(v_arguments, v_i)))));
                    alg_hold_top = rh_1205;
                    (void)(alg_hold(alg_subscript_set(v_filled, v_at, alg_bool(true))));
                    alg_hold_top = rh_1205;
                    alg_root_top = rt_1204;
                }
            }
        }
        alg_hold_top = rh_1202;
        alg_root_top = rt_1201;
    }
    alg_hold_top = rh_1196;
    {
        int32_t rt_1206 = alg_root_top;
        Value loop_101 = alg_iterable(v_filled);
        (void)loop_101;
        alg_root(&loop_101, 1);
        for (int32_t at_101 = 0; at_101 < alg_iterable_count(loop_101); at_101++) {
            alg_safe_point();
            int32_t rt_1207 = alg_root_top;
            Value v_each = alg_iterable_at(loop_101, at_101);
            (void)v_each;
            alg_root(&v_each, 1);
            if (alg_truthy(alg_hold(alg_not(v_each)))) {
                Value ret_102 = alg_nil();
                alg_root_top = rt_base;
                return ret_102;
            }
            alg_root_top = rt_1207;
        }
        alg_root_top = rt_1206;
    }
    alg_hold_top = rh_1196;
    Value ret_103 = v_slots;
    alg_root_top = rt_base;
    return ret_103;
    alg_hold_top = rh_1196;
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
    int32_t rh_1208 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(v_pass, (alg_declared(d_absorbing, "ABSORBING"), v_absorbing))))) {
        Value ret_105 = alg_hold(alg_invoke(v_this, "Absorbs", (Value[]){v_arguments}, 1));
        alg_root_top = rt_base;
        return ret_105;
    }
    alg_hold_top = rh_1208;
    Value ret_106 = alg_hold(alg_invoke(v_this, "Fits", (Value[]){v_arguments, alg_hold(alg_equal(v_pass, (alg_declared(d_widening, "WIDENING"), v_widening)))}, 2));
    alg_root_top = rt_base;
    return ret_106;
    alg_hold_top = rh_1208;
    Value ret_107 = alg_nil();
    alg_root_top = rt_base;
    return ret_107;
}

static Value m_objfunction_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1209 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_property(v_this, "Declaration"), "Params")), alg_nil())))) {
        Value ret_108 = alg_int(0);
        alg_root_top = rt_base;
        return ret_108;
    }
    alg_hold_top = rh_1209;
    Value ret_109 = alg_hold(alg_property(alg_hold(alg_property(alg_property(v_this, "Declaration"), "Params")), "Length"));
    alg_root_top = rt_base;
    return ret_109;
    alg_hold_top = rh_1209;
    Value ret_110 = alg_nil();
    alg_root_top = rt_base;
    return ret_110;
}

static Value m_objfunction_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1210 = alg_hold_top;
    Value ret_111 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("<fn "), alg_hold(alg_property(alg_hold(alg_property(alg_property(v_this, "Declaration"), "Name")), "Lexeme")))), alg_char_value(62)));
    alg_root_top = rt_base;
    return ret_111;
    alg_hold_top = rh_1210;
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
    int32_t rh_1211 = alg_hold_top;
    volatile Value v_env = alg_nil();
    (void)v_env;
    alg_root(&v_env, 1);
    alg_hold_top = rh_1211;
    volatile Value v_count = alg_nil();
    (void)v_count;
    alg_root(&v_count, 1);
    alg_hold_top = rh_1211;
    (void)((v_env = alg_hold(alg_new(k_environment, NULL, 0))));
    alg_hold_top = rh_1211;
    (void)(alg_hold(alg_set_property(v_env, "Enclosing", alg_property(v_this, "Closure"))));
    alg_hold_top = rh_1211;
    (void)((v_arguments = alg_hold(alg_invoke(v_this, "Absorb", (Value[]){v_arguments}, 1))));
    alg_hold_top = rh_1211;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(alg_property(v_this, "Declaration"), "Symbol")), alg_literal(""))))) {
        volatile Value ret_113 = alg_hold(alg_foreign_call(alg_hold(alg_property(alg_property(v_this, "Declaration"), "Symbol")), alg_hold(alg_property(alg_property(v_this, "Declaration"), "Library")), alg_hold(alg_property(alg_property(v_this, "Declaration"), "ParamTypes")), alg_hold(alg_property(alg_property(v_this, "Declaration"), "ReturnType")), v_arguments));
        alg_root_top = rt_base;
        return ret_113;
    }
    alg_hold_top = rh_1211;
    {
        int32_t rt_1212 = alg_root_top;
        int32_t rh_1213 = alg_hold_top;
        volatile Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1213;
        {
            int32_t rh_1214 = alg_hold_top;
            for (; (alg_hold_top = rh_1214, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(alg_property(v_this, "Declaration"), "Params")), "Length")))))); (alg_hold_top = rh_1214, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1215 = alg_root_top;
                    int32_t rh_1216 = alg_hold_top;
                    volatile Value v_declared = alg_literal("");
                    (void)v_declared;
                    alg_root(&v_declared, 1);
                    alg_hold_top = rh_1216;
                    if (alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(alg_property(v_this, "Declaration"), "ParamTypes")), "Length")))))) {
                        (void)((v_declared = alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(alg_property(v_this, "Declaration"), "ParamTypes")), v_i))))));
                    }
                    alg_hold_top = rh_1216;
                    (void)(alg_hold(alg_invoke(v_env, "Define", (Value[]){alg_hold(alg_property(alg_hold(alg_subscript_get(alg_hold(alg_property(alg_property(v_this, "Declaration"), "Params")), v_i)), "Lexeme")), alg_hold(alg_invoke(v_theinterpreter, "Widen", (Value[]){alg_hold(alg_subscript_get(v_arguments, v_i)), v_declared}, 2))}, 2)));
                    alg_hold_top = rh_1216;
                    alg_root_top = rt_1215;
                }
            }
        }
        alg_hold_top = rh_1213;
        alg_root_top = rt_1212;
    }
    alg_hold_top = rh_1211;
    {
        AlgFrame frame_114;
        alg_push_frame(&frame_114);
        if (ALG_SETJMP(frame_114.jump) == 0) {
            {
                int32_t rh_1217 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_theinterpreter, "ExecuteBlock", (Value[]){alg_hold(alg_property(alg_property(v_this, "Declaration"), "Body")), v_env}, 2)));
                alg_hold_top = rh_1217;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_114[] = {"Return"};
            int32_t which_114 = alg_handler(frame_114.raised, names_114, 1);
            if (which_114 == 0) {
                {
                    int32_t rt_1218 = alg_root_top;
                    volatile Value v_e = frame_114.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    {
                        int32_t rh_1219 = alg_hold_top;
                        if (alg_truthy(alg_property(v_this, "IsInitializer"))) {
                            volatile Value ret_115 = alg_hold(alg_invoke(alg_property(v_this, "Closure"), "GetAt", (Value[]){alg_int(0), alg_literal("this")}, 2));
                            alg_root_top = rt_base;
                            return ret_115;
                        }
                        alg_hold_top = rh_1219;
                        volatile Value ret_116 = alg_hold(alg_invoke(v_theinterpreter, "Widen", (Value[]){alg_hold(alg_property(v_e, "Value")), alg_hold(alg_str(alg_hold(alg_property(alg_property(v_this, "Declaration"), "ReturnType"))))}, 2));
                        alg_root_top = rt_base;
                        return ret_116;
                        alg_hold_top = rh_1219;
                    }
                    alg_root_top = rt_1218;
                }
            }
            else {
                alg_raise(frame_114.raised);
            }
        }
    }
    alg_hold_top = rh_1211;
    if (alg_truthy(alg_property(v_this, "IsInitializer"))) {
        volatile Value ret_117 = alg_hold(alg_invoke(alg_property(v_this, "Closure"), "GetAt", (Value[]){alg_int(0), alg_literal("this")}, 2));
        alg_root_top = rt_base;
        return ret_117;
    }
    alg_hold_top = rh_1211;
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
    alg_class_field(k_objoverloads, "Name", "String");
    alg_class_field(k_objoverloads, "Candidates", "List");
    alg_class_field(k_objoverloads, "Fallback", "Any");
    alg_class_initializer(k_objoverloads, i_objoverloads);
    alg_class_method(k_objoverloads, "Init", m_objoverloads_init_1_string, 1, t_objoverloads_init_1_string);
    alg_class_method(k_objoverloads, "Add", m_objoverloads_add_1, 1, t_objoverloads_add_1);
    alg_class_method(k_objoverloads, "Arity", m_objoverloads_arity_0, 0, NULL);
    alg_class_method(k_objoverloads, "Declares", m_objoverloads_declares_1_integer, 1, t_objoverloads_declares_1_integer);
    alg_class_method(k_objoverloads, "Select", m_objoverloads_select_1_list, 1, t_objoverloads_select_1_list);
    alg_class_method(k_objoverloads, "Call", m_objoverloads_call_2, 2, t_objoverloads_call_2);
    alg_class_method(k_objoverloads, "ToString", m_objoverloads_tostring_0, 0, NULL);
    alg_class_field(k_numbermethod, "Receiver", "Any");
    alg_class_field(k_numbermethod, "Name", "Token");
    alg_class_initializer(k_numbermethod, i_numbermethod);
    alg_class_method(k_numbermethod, "Init", m_numbermethod_init_2_token, 2, t_numbermethod_init_2_token);
    alg_class_method(k_numbermethod, "Arity", m_numbermethod_arity_0, 0, NULL);
    alg_class_method(k_numbermethod, "Call", m_numbermethod_call_2, 2, t_numbermethod_call_2);
    alg_class_method(k_numbermethod, "ToString", m_numbermethod_tostring_0, 0, NULL);
    alg_class_field(k_objextension, "Receiver", "Any");
    alg_class_field(k_objextension, "Target", "Any");
    alg_class_initializer(k_objextension, i_objextension);
    alg_class_method(k_objextension, "Init", m_objextension_init_2, 2, t_objextension_init_2);
    alg_class_method(k_objextension, "Arity", m_objextension_arity_0, 0, NULL);
    alg_class_method(k_objextension, "Call", m_objextension_call_2, 2, t_objextension_call_2);
    alg_class_method(k_objextension, "ToString", m_objextension_tostring_0, 0, NULL);
    fn_samesignature = alg_closure("SameSignature", f_samesignature, NULL, 0, 2, t_f_samesignature);
    fn_anynamed = alg_closure("AnyNamed", f_anynamed, NULL, 0, 1, t_f_anynamed);
    fn_widens = alg_closure("Widens", f_widens, NULL, 0, 2, t_f_widens);
    fn_inheritsfrom = alg_closure("InheritsFrom", f_inheritsfrom, NULL, 0, 2, t_f_inheritsfrom);
    alg_class_field(k_objfunction, "Declaration", "FunctionStmt");
    alg_class_field(k_objfunction, "Closure", "Environment");
    alg_class_field(k_objfunction, "IsInitializer", "Boolean");
    alg_class_field(k_objfunction, "Owner", "ObjClass");
    alg_class_field(k_objfunction, "Bound", "ObjInstance");
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
    int32_t rh_1129 = alg_hold_top;
    alg_hold_top = rh_1129;
    init_Interpreter();
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    v_exact = alg_int(0);
    d_exact = true;
    alg_hold_top = rh_1129;
    v_widening = alg_int(1);
    d_widening = true;
    alg_hold_top = rh_1129;
    v_absorbing = alg_int(2);
    d_absorbing = true;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
    alg_hold_top = rh_1129;
}
