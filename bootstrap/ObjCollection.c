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
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "TheArity", alg_nil());
    return alg_nil();
}

static Value m_collectionmethod_init_3_objcollection_token_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_receiver = alg_widen(args[0], "ObjCollection");
    (void)v_receiver;
    Value v_name = alg_widen(args[1], "Token");
    (void)v_name;
    Value v_thearity = alg_widen(args[2], "Integer");
    (void)v_thearity;
    (void)(alg_set_property(v_this, "Receiver", alg_widen(v_receiver, "ObjCollection")));
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "Token")));
    (void)(alg_set_property(v_this, "TheArity", alg_widen(v_thearity, "Integer")));
    return alg_nil();
}

static Value m_collectionmethod_arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "TheArity");
    return alg_nil();
}

static Value m_collectionmethod_call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theinterpreter = args[0];
    (void)v_theinterpreter;
    Value v_arguments = args[1];
    (void)v_arguments;
    return alg_invoke(alg_property(v_this, "Receiver"), "Invoke", (Value[]){f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(v_this, "Name"), "Lexeme"))}, 1), v_arguments}, 2);
    return alg_nil();
}

static Value m_collectionmethod_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_add(alg_add(alg_string("<fn "), alg_str(alg_property(alg_property(v_this, "Name"), "Lexeme"))), alg_char_value(62));
    return alg_nil();
}

static Value i_objcollection(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Kind", alg_nil());
    alg_set_property(v_this, "Items", alg_nil());
    alg_set_property(v_this, "Pairs", alg_nil());
    return alg_nil();
}

static Value m_objcollection_init_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_kind = alg_widen(args[0], "String");
    (void)v_kind;
    (void)(alg_set_property(v_this, "Kind", alg_widen(v_kind, "String")));
    (void)(alg_set_property(v_this, "Items", alg_widen(alg_list(), "List")));
    (void)(alg_set_property(v_this, "Pairs", alg_widen(alg_map(), "Map")));
    return alg_nil();
}

static Value m_objcollection_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thename = alg_widen(args[0], "Token");
    (void)v_thename;
    Value v_member = alg_nil();
    (void)v_member;
    (void)((v_member = alg_widen(f_foldcase(NULL, (Value[]){alg_property(v_thename, "Lexeme")}, 1), "String")));
    if (alg_truthy(alg_equal(v_member, alg_string("length")))) {
        return alg_invoke(v_this, "Count", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_member, alg_string("isempty")))) {
        return alg_equal(alg_invoke(v_this, "Count", NULL, 0), alg_int(0));
    }
    if (alg_truthy(alg_equal(v_member, alg_string("contains")))) {
        return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("List")))) {
        {
            if (alg_truthy(alg_equal(v_member, alg_string("get")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("add")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("insert")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(2)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("removeat")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("indexof")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("sort")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("clear")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Array")))) {
        {
            if (alg_truthy(alg_equal(v_member, alg_string("get")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("set")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(2)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("fill")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("indexof")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("sort")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        {
            if (alg_truthy(alg_equal(v_member, alg_string("get")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("put")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(2)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("remove")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("keys")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("values")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("clear")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Set")))) {
        {
            if (alg_truthy(alg_equal(v_member, alg_string("add")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("remove")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("tolist")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("clear")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Stack")))) {
        {
            if (alg_truthy(alg_equal(v_member, alg_string("push")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("pop")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("peek")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
            }
            if (alg_truthy(alg_equal(v_member, alg_string("clear")))) {
                return alg_new(k_collectionmethod, (Value[]){v_this, v_thename, alg_int(0)}, 3);
            }
        }
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_str(alg_property(v_thename, "Lexeme"))), alg_string("'.")));
    return alg_nil();
}

static Value m_objcollection_aslist_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_from = alg_widen(args[0], "List");
    (void)v_from;
    Value v_result = alg_nil();
    (void)v_result;
    (void)((v_result = alg_widen(alg_new(k_objcollection, (Value[]){alg_string("List")}, 1), "ObjCollection")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(v_from, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(alg_property(v_result, "Items"), "Add", (Value[]){alg_subscript_get(v_from, v_i)}, 1));
        }
    }
    return v_result;
    return alg_nil();
}

static Value m_objcollection_invoke_2_string_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_arguments = alg_widen(args[1], "List");
    (void)v_arguments;
    if (alg_truthy(alg_equal(v_name, alg_string("contains")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
                return alg_invoke(alg_property(v_this, "Pairs"), "Contains", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
            }
            return alg_invoke(alg_property(v_this, "Items"), "Contains", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("get")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
                return alg_invoke(alg_property(v_this, "Pairs"), "Get", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
            }
            return alg_invoke(alg_property(v_this, "Items"), "Get", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("add")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Set")))) {
                {
                    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Items"), "Contains", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1)))) {
                        (void)(alg_invoke(alg_property(v_this, "Items"), "Add", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1));
                    }
                    return alg_subscript_get(v_arguments, alg_int(0));
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Items"), "Add", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1));
            return alg_subscript_get(v_arguments, alg_int(0));
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("set")))) {
        {
            (void)(alg_subscript_set(alg_property(v_this, "Items"), alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1))));
            return alg_subscript_get(v_arguments, alg_int(1));
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("put")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Pairs"), "Put", (Value[]){alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1))}, 2));
            return alg_subscript_get(v_arguments, alg_int(1));
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("insert")))) {
        return alg_invoke(alg_property(v_this, "Items"), "Insert", (Value[]){alg_subscript_get(v_arguments, alg_int(0)), alg_subscript_get(v_arguments, alg_int(1))}, 2);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("removeat")))) {
        return alg_invoke(alg_property(v_this, "Items"), "RemoveAt", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("indexof")))) {
        return alg_invoke(alg_property(v_this, "Items"), "IndexOf", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("sort")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Items"), "Sort", NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("fill")))) {
        {
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_this, "Items"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_subscript_set(alg_property(v_this, "Items"), v_i, alg_subscript_get(v_arguments, alg_int(0))));
                }
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("keys")))) {
        return alg_invoke(v_this, "AsList", (Value[]){alg_invoke(alg_property(v_this, "Pairs"), "Keys", NULL, 0)}, 1);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("values")))) {
        return alg_invoke(v_this, "AsList", (Value[]){alg_invoke(alg_property(v_this, "Pairs"), "Values", NULL, 0)}, 1);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("tolist")))) {
        return alg_invoke(v_this, "AsList", (Value[]){alg_property(v_this, "Items")}, 1);
    }
    if (alg_truthy(alg_equal(v_name, alg_string("remove")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
                {
                    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Pairs"), "Contains", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1)))) {
                        return alg_nil();
                    }
                    return alg_invoke(alg_property(v_this, "Pairs"), "Remove", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
                }
            }
            Value v_at = alg_invoke(alg_property(v_this, "Items"), "IndexOf", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1);
            (void)v_at;
            if (alg_truthy(alg_less(v_at, alg_int(0)))) {
                return alg_bool(false);
            }
            (void)(alg_invoke(alg_property(v_this, "Items"), "RemoveAt", (Value[]){v_at}, 1));
            return alg_bool(true);
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("push")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Items"), "Add", (Value[]){alg_subscript_get(v_arguments, alg_int(0))}, 1));
            return alg_subscript_get(v_arguments, alg_int(0));
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("pop")))) {
        {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_this, "Items"), "Length"), alg_int(0)))) {
                alg_raise(alg_string("Pop from an empty Stack."));
            }
            return alg_invoke(alg_property(v_this, "Items"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "Items"), "Length"), alg_int(1))}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("peek")))) {
        {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_this, "Items"), "Length"), alg_int(0)))) {
                alg_raise(alg_string("Peek at an empty Stack."));
            }
            return alg_subscript_get(alg_property(v_this, "Items"), alg_subtract(alg_property(alg_property(v_this, "Items"), "Length"), alg_int(1)));
        }
    }
    if (alg_truthy(alg_equal(v_name, alg_string("clear")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
                (void)(alg_invoke(alg_property(v_this, "Pairs"), "Clear", NULL, 0));
            } else {
                (void)(alg_invoke(alg_property(v_this, "Items"), "Clear", NULL, 0));
            }
            return alg_nil();
        }
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined method '"), v_name), alg_string("'.")));
    return alg_nil();
}

static Value m_objcollection_at_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_index = args[0];
    (void)v_index;
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        return alg_invoke(alg_property(v_this, "Pairs"), "Get", (Value[]){v_index}, 1);
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Set")))) {
        alg_raise(alg_string("Subscript target should be an ordinal."));
    }
    return alg_subscript_get(alg_property(v_this, "Items"), v_index);
    return alg_nil();
}

static Value m_objcollection_putat_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_index = args[0];
    (void)v_index;
    Value v_value = args[1];
    (void)v_value;
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        (void)(alg_invoke(alg_property(v_this, "Pairs"), "Put", (Value[]){v_index, v_value}, 2));
    } else {
        if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Set")))) {
            alg_raise(alg_string("Subscript target should be an ordinal."));
        } else {
            (void)(alg_subscript_set(alg_property(v_this, "Items"), v_index, v_value));
        }
    }
    return v_value;
    return alg_nil();
}

static Value m_objcollection_allocate_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_size = alg_widen(args[0], "Integer");
    (void)v_size;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, v_size)); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(alg_property(v_this, "Items"), "Add", (Value[]){alg_nil()}, 1));
        }
    }
    return alg_nil();
}

static Value m_objcollection_count_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        return alg_property(alg_property(v_this, "Pairs"), "Length");
    }
    return alg_property(alg_property(v_this, "Items"), "Length");
    return alg_nil();
}

static Value m_objcollection_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        return alg_str(alg_property(v_this, "Pairs"));
    }
    return alg_str(alg_property(v_this, "Items"));
    return alg_nil();
}

void init_ObjCollection(void) {
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
