/* Generated from Algol-24.  Do not edit. */
#include "ObjCollection.h"
#include "Token.h"

Value k_collectionmethod;
static const char *t_collectionmethod_init_3_objcollection_token_integer[] = { "Receiver : ObjCollection", "Name : Token", "TheArity : Integer" };
static const char *t_collectionmethod_call_2[] = { "TheInterpreter : Any", "Arguments : Any" };
Value k_objcollection;
static const char *t_objcollection_init_1_string[] = { "Kind : String" };
static const char *t_objcollection_get_1_token[] = { "TheName : Token" };
static const char *t_objcollection_aslist_1_list[] = { "From : List" };
static const char *t_objcollection_invoke_2_string_list[] = { "Name : String", "Arguments : List" };
static const char *t_objcollection_at_1[] = { "Index : Any" };
static const char *t_objcollection_putat_2[] = { "Index : Any", "Value : Any" };
static const char *t_objcollection_allocate_1_integer[] = { "Size : Integer" };

static Value i_collectionmethod(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "TheArity", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_collectionmethod_init_3_objcollection_token_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_receiver = alg_widen(args[0], "ObjCollection");
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

static Value m_collectionmethod_arity_0(Value v_this, Value *args, int32_t count) {
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

static Value m_collectionmethod_call_2(Value v_this, Value *args, int32_t count) {
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

static Value m_collectionmethod_tostring_0(Value v_this, Value *args, int32_t count) {
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

static Value i_objcollection(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Kind", alg_nil());
    alg_set_property(v_this, "Items", alg_nil());
    alg_set_property(v_this, "Pairs", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_objcollection_init_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_kind = alg_widen(args[0], "String");
    (void)v_kind;
    alg_root(&v_kind, 1);
    (void)(alg_set_property(v_this, "Kind", v_kind));
    (void)(alg_set_property(v_this, "Items", alg_list()));
    (void)(alg_set_property(v_this, "Pairs", alg_map()));
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
}

static Value m_objcollection_get_1_token(Value v_this, Value *args, int32_t count) {
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
    if (alg_truthy(alg_equal(v_member, alg_string("length")))) {
        Value ret_8 = alg_invoke(v_this, "Count", NULL, 0);
        alg_root_top = rt_base;
        return ret_8;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("isempty")))) {
        Value ret_9 = alg_equal(alg_invoke(v_this, "Count", NULL, 0), alg_int(0));
        alg_root_top = rt_base;
        return ret_9;
    }
    if (alg_truthy(alg_equal(v_member, alg_string("contains")))) {
        Value ret_10 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
        alg_root_top = rt_base;
        return ret_10;
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("List")))) {
        {
            if (alg_truthy(alg_equal(v_member, alg_string("get")))) {
                Value ret_11 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
                alg_root_top = rt_base;
                return ret_11;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("add")))) {
                Value ret_12 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
                alg_root_top = rt_base;
                return ret_12;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("insert")))) {
                Value ret_13 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(2)}, 3);
                alg_root_top = rt_base;
                return ret_13;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("removeat")))) {
                Value ret_14 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
                alg_root_top = rt_base;
                return ret_14;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("indexof")))) {
                Value ret_15 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
                alg_root_top = rt_base;
                return ret_15;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("sort")))) {
                Value ret_16 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
                alg_root_top = rt_base;
                return ret_16;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("clear")))) {
                Value ret_17 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
                alg_root_top = rt_base;
                return ret_17;
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Array")))) {
        {
            if (alg_truthy(alg_equal(v_member, alg_string("get")))) {
                Value ret_18 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
                alg_root_top = rt_base;
                return ret_18;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("set")))) {
                Value ret_19 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(2)}, 3);
                alg_root_top = rt_base;
                return ret_19;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("fill")))) {
                Value ret_20 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
                alg_root_top = rt_base;
                return ret_20;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("indexof")))) {
                Value ret_21 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
                alg_root_top = rt_base;
                return ret_21;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("sort")))) {
                Value ret_22 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
                alg_root_top = rt_base;
                return ret_22;
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        {
            if (alg_truthy(alg_equal(v_member, alg_string("get")))) {
                Value ret_23 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
                alg_root_top = rt_base;
                return ret_23;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("put")))) {
                Value ret_24 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(2)}, 3);
                alg_root_top = rt_base;
                return ret_24;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("remove")))) {
                Value ret_25 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
                alg_root_top = rt_base;
                return ret_25;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("keys")))) {
                Value ret_26 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
                alg_root_top = rt_base;
                return ret_26;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("values")))) {
                Value ret_27 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
                alg_root_top = rt_base;
                return ret_27;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("clear")))) {
                Value ret_28 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
                alg_root_top = rt_base;
                return ret_28;
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Set")))) {
        {
            if (alg_truthy(alg_equal(v_member, alg_string("add")))) {
                Value ret_29 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
                alg_root_top = rt_base;
                return ret_29;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("remove")))) {
                Value ret_30 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
                alg_root_top = rt_base;
                return ret_30;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("tolist")))) {
                Value ret_31 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
                alg_root_top = rt_base;
                return ret_31;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("clear")))) {
                Value ret_32 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
                alg_root_top = rt_base;
                return ret_32;
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Stack")))) {
        {
            if (alg_truthy(alg_equal(v_member, alg_string("push")))) {
                Value ret_33 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
                alg_root_top = rt_base;
                return ret_33;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("pop")))) {
                Value ret_34 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
                alg_root_top = rt_base;
                return ret_34;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("peek")))) {
                Value ret_35 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
                alg_root_top = rt_base;
                return ret_35;
            }
            if (alg_truthy(alg_equal(v_member, alg_string("clear")))) {
                Value ret_36 = alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
                alg_root_top = rt_base;
                return ret_36;
            }
        }
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_str(alg_property(v_thename, "Lexeme"))), alg_string("'.")));
    Value ret_37 = alg_nil();
    alg_root_top = rt_base;
    return ret_37;
}

static Value m_objcollection_aslist_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_from = alg_widen(args[0], "List");
    (void)v_from;
    alg_root(&v_from, 1);
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    (void)((v_result = alg_new(k_objcollection, (Value[]){alg_string("List")}, 1)));
    {
        int32_t rt_23 = alg_root_top;
        Value loop_38 = alg_iterable(v_from);
        (void)loop_38;
        alg_root(&loop_38, 1);
        for (int32_t at_38 = 0; at_38 < alg_iterable_count(loop_38); at_38++) {
            int32_t rt_24 = alg_root_top;
            Value v_each = alg_iterable_at(loop_38, at_38);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_invoke(alg_property(v_result, "Items"), "Add", (Value[]){v_each}, 1));
            alg_root_top = rt_24;
        }
        alg_root_top = rt_23;
    }
    Value ret_39 = v_result;
    alg_root_top = rt_base;
    return ret_39;
    Value ret_40 = alg_nil();
    alg_root_top = rt_base;
    return ret_40;
}

static Value m_objcollection_invoke_2_string_list(Value v_this, Value *args, int32_t count) {
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
    if (alg_truthy(alg_equal(v_name, alg_string("contains")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
                Value ret_41 = alg_invoke(alg_property(v_this, "Pairs"), "Contains", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
                alg_root_top = rt_base;
                return ret_41;
            }
            Value ret_42 = alg_invoke(alg_property(v_this, "Items"), "Contains", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
            alg_root_top = rt_base;
            return ret_42;
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("get")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
                Value ret_43 = alg_invoke(alg_property(v_this, "Pairs"), "Get", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
                alg_root_top = rt_base;
                return ret_43;
            }
            Value ret_44 = alg_invoke(alg_property(v_this, "Items"), "Get", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
            alg_root_top = rt_base;
            return ret_44;
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("add")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Set")))) {
                {
                    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Items"), "Contains", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1)))) {
                        (void)(alg_invoke(alg_property(v_this, "Items"), "Add", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1));
                    }
                    Value ret_45 = alg_subscript_get(v_arguments, alg_int(0));
                    alg_root_top = rt_base;
                    return ret_45;
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Items"), "Add", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1));
            Value ret_46 = alg_subscript_get(v_arguments, alg_int(0));
            alg_root_top = rt_base;
            return ret_46;
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("set")))) {
        {
            (void)(alg_subscript_set(alg_property(v_this, "Items"), alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1))));
            Value ret_47 = alg_subscript_get(v_arguments, alg_int(1));
            alg_root_top = rt_base;
            return ret_47;
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("put")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Pairs"), "Put", (Value[]){alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1))}, 2));
            Value ret_48 = alg_subscript_get(v_arguments, alg_int(1));
            alg_root_top = rt_base;
            return ret_48;
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("insert")))) {
        Value ret_49 = alg_invoke(alg_property(v_this, "Items"), "Insert", (Value[]){alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1))}, 2);
        alg_root_top = rt_base;
        return ret_49;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("removeat")))) {
        Value ret_50 = alg_invoke(alg_property(v_this, "Items"), "RemoveAt", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        alg_root_top = rt_base;
        return ret_50;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("indexof")))) {
        Value ret_51 = alg_invoke(alg_property(v_this, "Items"), "IndexOf", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        alg_root_top = rt_base;
        return ret_51;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("sort")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Items"), "Sort", NULL, 0));
            Value ret_52 = alg_nil();
            alg_root_top = rt_base;
            return ret_52;
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("fill")))) {
        {
            {
                int32_t rt_25 = alg_root_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_this, "Items"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_subscript_set(alg_property(v_this, "Items"), v_i, alg_subscript_get(v_arguments, alg_int(0))));
                }
                alg_root_top = rt_25;
            }
            Value ret_53 = alg_nil();
            alg_root_top = rt_base;
            return ret_53;
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("keys")))) {
        Value ret_54 = alg_invoke(v_this, "AsList", (Value[]){alg_invoke(alg_property(v_this, "Pairs"), "Keys", NULL, 0)}, 1);
        alg_root_top = rt_base;
        return ret_54;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("values")))) {
        Value ret_55 = alg_invoke(v_this, "AsList", (Value[]){alg_invoke(alg_property(v_this, "Pairs"), "Values", NULL, 0)}, 1);
        alg_root_top = rt_base;
        return ret_55;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("tolist")))) {
        Value ret_56 = alg_invoke(v_this, "AsList", (Value[]){alg_property(v_this, "Items")}, 1);
        alg_root_top = rt_base;
        return ret_56;
    }
    if (alg_truthy(alg_equal(v_name, alg_string("remove")))) {
        {
            int32_t rt_26 = alg_root_top;
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
                {
                    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Pairs"), "Contains", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1)))) {
                        Value ret_57 = alg_nil();
                        alg_root_top = rt_base;
                        return ret_57;
                    }
                    Value ret_58 = alg_invoke(alg_property(v_this, "Pairs"), "Remove", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
                    alg_root_top = rt_base;
                    return ret_58;
                }
            }
            Value v_at = alg_invoke(alg_property(v_this, "Items"), "IndexOf", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
            (void)v_at;
            alg_root(&v_at, 1);
            if (alg_truthy(alg_less(v_at, alg_int(0)))) {
                Value ret_59 = alg_bool(false);
                alg_root_top = rt_base;
                return ret_59;
            }
            (void)(alg_invoke(alg_property(v_this, "Items"), "RemoveAt", (Value[]){v_at}, 1));
            Value ret_60 = alg_bool(true);
            alg_root_top = rt_base;
            return ret_60;
            alg_root_top = rt_26;
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("push")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Items"), "Add", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1));
            Value ret_61 = alg_subscript_get(v_arguments, alg_int(0));
            alg_root_top = rt_base;
            return ret_61;
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("pop")))) {
        {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_this, "Items"), "Length"), alg_int(0)))) {
                alg_raise(alg_string("Pop from an empty Stack."));
            }
            Value ret_62 = alg_invoke(alg_property(v_this, "Items"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "Items"), "Length"), alg_int(1))}, 1);
            alg_root_top = rt_base;
            return ret_62;
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("peek")))) {
        {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_this, "Items"), "Length"), alg_int(0)))) {
                alg_raise(alg_string("Peek at an empty Stack."));
            }
            Value ret_63 = alg_subscript_get(alg_property(v_this, "Items"), alg_subtract(alg_property(alg_property(v_this, "Items"), "Length"), alg_int(1)));
            alg_root_top = rt_base;
            return ret_63;
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("clear")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
                (void)(alg_invoke(alg_property(v_this, "Pairs"), "Clear", NULL, 0));
            } else {
                (void)(alg_invoke(alg_property(v_this, "Items"), "Clear", NULL, 0));
            }
            Value ret_64 = alg_nil();
            alg_root_top = rt_base;
            return ret_64;
        }
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined method '"), v_name), alg_string("'.")));
    Value ret_65 = alg_nil();
    alg_root_top = rt_base;
    return ret_65;
}

static Value m_objcollection_at_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_index = args[0];
    (void)v_index;
    alg_root(&v_index, 1);
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        Value ret_66 = alg_invoke(alg_property(v_this, "Pairs"), "Get", (Value[]){v_index}, 1);
        alg_root_top = rt_base;
        return ret_66;
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Set")))) {
        alg_raise(alg_string("Subscript target should be an ordinal."));
    }
    Value ret_67 = alg_subscript_get(alg_property(v_this, "Items"), v_index);
    alg_root_top = rt_base;
    return ret_67;
    Value ret_68 = alg_nil();
    alg_root_top = rt_base;
    return ret_68;
}

static Value m_objcollection_putat_2(Value v_this, Value *args, int32_t count) {
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
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        (void)(alg_invoke(alg_property(v_this, "Pairs"), "Put", (Value[]){v_index, v_value}, 2));
    } else {
        if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Set")))) {
            alg_raise(alg_string("Subscript target should be an ordinal."));
        } else {
            (void)(alg_subscript_set(alg_property(v_this, "Items"), v_index, v_value));
        }
    }
    Value ret_69 = v_value;
    alg_root_top = rt_base;
    return ret_69;
    Value ret_70 = alg_nil();
    alg_root_top = rt_base;
    return ret_70;
}

static Value m_objcollection_allocate_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_size = alg_widen(args[0], "Integer");
    (void)v_size;
    alg_root(&v_size, 1);
    {
        int32_t rt_27 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, v_size)); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(alg_property(v_this, "Items"), "Add", (Value[]){alg_nil()}, 1));
        }
        alg_root_top = rt_27;
    }
    Value ret_71 = alg_nil();
    alg_root_top = rt_base;
    return ret_71;
}

static Value m_objcollection_count_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        Value ret_72 = alg_property(alg_property(v_this, "Pairs"), "Length");
        alg_root_top = rt_base;
        return ret_72;
    }
    Value ret_73 = alg_property(alg_property(v_this, "Items"), "Length");
    alg_root_top = rt_base;
    return ret_73;
    Value ret_74 = alg_nil();
    alg_root_top = rt_base;
    return ret_74;
}

static Value m_objcollection_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        Value ret_75 = alg_str(alg_property(v_this, "Pairs"));
        alg_root_top = rt_base;
        return ret_75;
    }
    Value ret_76 = alg_str(alg_property(v_this, "Items"));
    alg_root_top = rt_base;
    return ret_76;
    Value ret_77 = alg_nil();
    alg_root_top = rt_base;
    return ret_77;
}

static Value *roots_ObjCollection[] = {
    &k_collectionmethod,
    &k_objcollection,
};

void init_ObjCollection(void) {
    alg_roots(roots_ObjCollection, 2);
    k_collectionmethod = alg_class("CollectionMethod", alg_nil());
    k_objcollection = alg_class("ObjCollection", alg_nil());
    alg_class_field(k_collectionmethod, "Receiver");
    alg_class_field(k_collectionmethod, "Name");
    alg_class_field(k_collectionmethod, "TheArity");
    alg_class_initializer(k_collectionmethod, i_collectionmethod);
    alg_class_method(k_collectionmethod, "Init", m_collectionmethod_init_3_objcollection_token_integer, 3, t_collectionmethod_init_3_objcollection_token_integer);
    alg_class_method(k_collectionmethod, "Arity", m_collectionmethod_arity_0, 0, NULL);
    alg_class_method(k_collectionmethod, "Call", m_collectionmethod_call_2, 2, t_collectionmethod_call_2);
    alg_class_method(k_collectionmethod, "ToString", m_collectionmethod_tostring_0, 0, NULL);
    alg_class_field(k_objcollection, "Kind");
    alg_class_field(k_objcollection, "Items");
    alg_class_field(k_objcollection, "Pairs");
    alg_class_initializer(k_objcollection, i_objcollection);
    alg_class_method(k_objcollection, "Init", m_objcollection_init_1_string, 1, t_objcollection_init_1_string);
    alg_class_method(k_objcollection, "Get", m_objcollection_get_1_token, 1, t_objcollection_get_1_token);
    alg_class_method(k_objcollection, "AsList", m_objcollection_aslist_1_list, 1, t_objcollection_aslist_1_list);
    alg_class_method(k_objcollection, "Invoke", m_objcollection_invoke_2_string_list, 2, t_objcollection_invoke_2_string_list);
    alg_class_method(k_objcollection, "At", m_objcollection_at_1, 1, t_objcollection_at_1);
    alg_class_method(k_objcollection, "PutAt", m_objcollection_putat_2, 2, t_objcollection_putat_2);
    alg_class_method(k_objcollection, "Allocate", m_objcollection_allocate_1_integer, 1, t_objcollection_allocate_1_integer);
    alg_class_method(k_objcollection, "Count", m_objcollection_count_0, 0, NULL);
    alg_class_method(k_objcollection, "ToString", m_objcollection_tostring_0, 0, NULL);
}
