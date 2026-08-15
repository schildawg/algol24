/* Generated from Algol-24.  Do not edit. */
#include "ObjCollection.h"
#include "Token.h"

Value k_CollectionMethod;
static const char *t_CollectionMethod_Init_3_ObjCollection_String_Integer[] = { "ObjCollection", "String", "Integer" };
static const char *t_CollectionMethod_Call_2[] = { "Any", "Any" };
Value k_ObjCollection;
static const char *t_ObjCollection_Init_1_String[] = { "String" };
static const char *t_ObjCollection_Get_1_Token[] = { "Token" };
static const char *t_ObjCollection_AsList_1_List[] = { "List" };
static const char *t_ObjCollection_Invoke_2_String_List[] = { "String", "List" };
static const char *t_ObjCollection_At_1[] = { "Any" };
static const char *t_ObjCollection_PutAt_2[] = { "Any", "Any" };
static const char *t_ObjCollection_Allocate_1_Integer[] = { "Integer" };

static Value i_CollectionMethod(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Receiver", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "TheArity", alg_nil());
    return alg_nil();
}

static Value m_CollectionMethod_Init_3_ObjCollection_String_Integer(Value v_this, Value *args, int32_t count) {
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

static Value m_CollectionMethod_Arity_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "TheArity");
    return alg_nil();
}

static Value m_CollectionMethod_Call_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheInterpreter = args[0];
    (void)v_TheInterpreter;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    return alg_invoke(alg_property(v_this, "Receiver"), "Invoke", (Value[]){alg_property(v_this, "Name"), v_Arguments}, 2);
    return alg_nil();
}

static Value i_ObjCollection(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Kind", alg_nil());
    alg_set_property(v_this, "Items", alg_nil());
    alg_set_property(v_this, "Pairs", alg_nil());
    return alg_nil();
}

static Value m_ObjCollection_Init_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Kind = args[0];
    (void)v_Kind;
    (void)(alg_set_property(v_this, "Kind", v_Kind));
    (void)(alg_set_property(v_this, "Items", alg_list()));
    (void)(alg_set_property(v_this, "Pairs", alg_map()));
    return alg_nil();
}

static Value m_ObjCollection_Get_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheName = args[0];
    (void)v_TheName;
    Value v_Member = alg_nil();
    (void)v_Member;
    (void)((v_Member = alg_property(v_TheName, "Lexeme")));
    if (alg_truthy(alg_equal(v_Member, alg_string("Length")))) {
        return alg_invoke(v_this, "Count", NULL, 0);
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("IsEmpty")))) {
        return alg_equal(alg_invoke(v_this, "Count", NULL, 0), alg_int(0));
    }
    if (alg_truthy(alg_equal(v_Member, alg_string("Contains")))) {
        return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("List")))) {
        {
            if (alg_truthy(alg_equal(v_Member, alg_string("Get")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Add")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Insert")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(2)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("RemoveAt")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("IndexOf")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Sort")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Clear")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Array")))) {
        {
            if (alg_truthy(alg_equal(v_Member, alg_string("Get")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Set")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(2)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Fill")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("IndexOf")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Sort")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        {
            if (alg_truthy(alg_equal(v_Member, alg_string("Get")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Put")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(2)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Remove")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Keys")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Values")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Clear")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Set")))) {
        {
            if (alg_truthy(alg_equal(v_Member, alg_string("Add")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Remove")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("ToList")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Clear")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Stack")))) {
        {
            if (alg_truthy(alg_equal(v_Member, alg_string("Push")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(1)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Pop")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Peek")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
            }
            if (alg_truthy(alg_equal(v_Member, alg_string("Clear")))) {
                return alg_new(k_CollectionMethod, (Value[]){v_this, v_Member, alg_int(0)}, 3);
            }
        }
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), v_Member), alg_string("'.")));
    return alg_nil();
}

static Value m_ObjCollection_AsList_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_From = args[0];
    (void)v_From;
    Value v_Result = alg_nil();
    (void)v_Result;
    (void)((v_Result = alg_new(k_ObjCollection, (Value[]){alg_string("List")}, 1)));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_From, "Length")))) {
            {
                (void)(alg_invoke(alg_property(v_Result, "Items"), "Add", (Value[]){alg_subscript_get(v_From, v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Result;
    return alg_nil();
}

static Value m_ObjCollection_Invoke_2_String_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Arguments = args[1];
    (void)v_Arguments;
    if (alg_truthy(alg_equal(v_Name, alg_string("Contains")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
                return alg_invoke(alg_property(v_this, "Pairs"), "Contains", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
            }
            return alg_invoke(alg_property(v_this, "Items"), "Contains", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Get")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
                return alg_invoke(alg_property(v_this, "Pairs"), "Get", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
            }
            return alg_invoke(alg_property(v_this, "Items"), "Get", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Add")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Set")))) {
                {
                    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Items"), "Contains", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1)))) {
                        (void)(alg_invoke(alg_property(v_this, "Items"), "Add", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1));
                    }
                    return alg_subscript_get(v_Arguments, alg_int(0));
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Items"), "Add", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1));
            return alg_subscript_get(v_Arguments, alg_int(0));
        }
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Set")))) {
        {
            (void)(alg_subscript_set(alg_property(v_this, "Items"), alg_subscript_get(v_Arguments, alg_int(0)), alg_subscript_get(v_Arguments, alg_int(1))));
            return alg_subscript_get(v_Arguments, alg_int(1));
        }
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Put")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Pairs"), "Put", (Value[]){alg_subscript_get(v_Arguments, alg_int(0)), alg_subscript_get(v_Arguments, alg_int(1))}, 2));
            return alg_subscript_get(v_Arguments, alg_int(1));
        }
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Insert")))) {
        return alg_invoke(alg_property(v_this, "Items"), "Insert", (Value[]){alg_subscript_get(v_Arguments, alg_int(0)), alg_subscript_get(v_Arguments, alg_int(1))}, 2);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("RemoveAt")))) {
        return alg_invoke(alg_property(v_this, "Items"), "RemoveAt", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("IndexOf")))) {
        return alg_invoke(alg_property(v_this, "Items"), "IndexOf", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Sort")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Items"), "Sort", NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Fill")))) {
        {
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_this, "Items"), "Length")))) {
                    {
                        (void)(alg_subscript_set(alg_property(v_this, "Items"), v_I, alg_subscript_get(v_Arguments, alg_int(0))));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Keys")))) {
        return alg_invoke(v_this, "AsList", (Value[]){alg_invoke(alg_property(v_this, "Pairs"), "Keys", NULL, 0)}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Values")))) {
        return alg_invoke(v_this, "AsList", (Value[]){alg_invoke(alg_property(v_this, "Pairs"), "Values", NULL, 0)}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("ToList")))) {
        return alg_invoke(v_this, "AsList", (Value[]){alg_property(v_this, "Items")}, 1);
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Remove")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
                {
                    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Pairs"), "Contains", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1)))) {
                        return alg_nil();
                    }
                    return alg_invoke(alg_property(v_this, "Pairs"), "Remove", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
                }
            }
            Value v_At = alg_invoke(alg_property(v_this, "Items"), "IndexOf", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1);
            (void)v_At;
            if (alg_truthy(alg_less(v_At, alg_int(0)))) {
                return alg_bool(false);
            }
            (void)(alg_invoke(alg_property(v_this, "Items"), "RemoveAt", (Value[]){v_At}, 1));
            return alg_bool(true);
        }
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Push")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Items"), "Add", (Value[]){alg_subscript_get(v_Arguments, alg_int(0))}, 1));
            return alg_subscript_get(v_Arguments, alg_int(0));
        }
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Pop")))) {
        {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_this, "Items"), "Length"), alg_int(0)))) {
                alg_raise(alg_string("Pop from an empty Stack."));
            }
            return alg_invoke(alg_property(v_this, "Items"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "Items"), "Length"), alg_int(1))}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Peek")))) {
        {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_this, "Items"), "Length"), alg_int(0)))) {
                alg_raise(alg_string("Peek at an empty Stack."));
            }
            return alg_subscript_get(alg_property(v_this, "Items"), alg_subtract(alg_property(alg_property(v_this, "Items"), "Length"), alg_int(1)));
        }
    }
    if (alg_truthy(alg_equal(v_Name, alg_string("Clear")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
                (void)(alg_invoke(alg_property(v_this, "Pairs"), "Clear", NULL, 0));
            } else {
                (void)(alg_invoke(alg_property(v_this, "Items"), "Clear", NULL, 0));
            }
            return alg_nil();
        }
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined method '"), v_Name), alg_string("'.")));
    return alg_nil();
}

static Value m_ObjCollection_At_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Index = args[0];
    (void)v_Index;
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        return alg_invoke(alg_property(v_this, "Pairs"), "Get", (Value[]){v_Index}, 1);
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Set")))) {
        alg_raise(alg_string("Subscript target should be an ordinal."));
    }
    return alg_subscript_get(alg_property(v_this, "Items"), v_Index);
    return alg_nil();
}

static Value m_ObjCollection_PutAt_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Index = args[0];
    (void)v_Index;
    Value v_Value = args[1];
    (void)v_Value;
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        (void)(alg_invoke(alg_property(v_this, "Pairs"), "Put", (Value[]){v_Index, v_Value}, 2));
    } else {
        if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Set")))) {
            alg_raise(alg_string("Subscript target should be an ordinal."));
        } else {
            (void)(alg_subscript_set(alg_property(v_this, "Items"), v_Index, v_Value));
        }
    }
    return v_Value;
    return alg_nil();
}

static Value m_ObjCollection_Allocate_1_Integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Size = args[0];
    (void)v_Size;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, v_Size))) {
            {
                (void)(alg_invoke(alg_property(v_this, "Items"), "Add", (Value[]){alg_nil()}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_ObjCollection_Count_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        return alg_property(alg_property(v_this, "Pairs"), "Length");
    }
    return alg_property(alg_property(v_this, "Items"), "Length");
    return alg_nil();
}

static Value m_ObjCollection_ToString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_equal(alg_property(v_this, "Kind"), alg_string("Map")))) {
        return alg_str(alg_property(v_this, "Pairs"));
    }
    return alg_str(alg_property(v_this, "Items"));
    return alg_nil();
}

void init_ObjCollection(void) {
    k_CollectionMethod = alg_class("CollectionMethod", alg_nil());
    alg_class_field(k_CollectionMethod, "Receiver");
    alg_class_field(k_CollectionMethod, "Name");
    alg_class_field(k_CollectionMethod, "TheArity");
    alg_class_initializer(k_CollectionMethod, i_CollectionMethod);
    alg_class_method(k_CollectionMethod, "Init", m_CollectionMethod_Init_3_ObjCollection_String_Integer, 3, t_CollectionMethod_Init_3_ObjCollection_String_Integer);
    alg_class_method(k_CollectionMethod, "Arity", m_CollectionMethod_Arity_0, 0, NULL);
    alg_class_method(k_CollectionMethod, "Call", m_CollectionMethod_Call_2, 2, t_CollectionMethod_Call_2);
    k_ObjCollection = alg_class("ObjCollection", alg_nil());
    alg_class_field(k_ObjCollection, "Kind");
    alg_class_field(k_ObjCollection, "Items");
    alg_class_field(k_ObjCollection, "Pairs");
    alg_class_initializer(k_ObjCollection, i_ObjCollection);
    alg_class_method(k_ObjCollection, "Init", m_ObjCollection_Init_1_String, 1, t_ObjCollection_Init_1_String);
    alg_class_method(k_ObjCollection, "Get", m_ObjCollection_Get_1_Token, 1, t_ObjCollection_Get_1_Token);
    alg_class_method(k_ObjCollection, "AsList", m_ObjCollection_AsList_1_List, 1, t_ObjCollection_AsList_1_List);
    alg_class_method(k_ObjCollection, "Invoke", m_ObjCollection_Invoke_2_String_List, 2, t_ObjCollection_Invoke_2_String_List);
    alg_class_method(k_ObjCollection, "At", m_ObjCollection_At_1, 1, t_ObjCollection_At_1);
    alg_class_method(k_ObjCollection, "PutAt", m_ObjCollection_PutAt_2, 2, t_ObjCollection_PutAt_2);
    alg_class_method(k_ObjCollection, "Allocate", m_ObjCollection_Allocate_1_Integer, 1, t_ObjCollection_Allocate_1_Integer);
    alg_class_method(k_ObjCollection, "Count", m_ObjCollection_Count_0, 0, NULL);
    alg_class_method(k_ObjCollection, "ToString", m_ObjCollection_ToString_0, 0, NULL);
}
