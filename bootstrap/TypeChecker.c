/* Generated from Algol-24.  Do not edit. */
#include "TypeChecker.h"
#include "Console.h"
#include "Interpreter.h"
#include "Parser.h"
#include "Scanner.h"
#include "SourceCode.h"
#include "Token.h"
#include "TokenType.h"

Value f_rejects(Value **cells, Value *args, int32_t count);
Value k_typelookup;
static const char *t_typelookup_settype_2_string_string[] = { "Symbol : String", "TheType : String" };
static const char *t_typelookup_gettype_1_string[] = { "Symbol : String" };
Value k_typechecker;
static Value or_0;
static Value or_1;
static Value or_2;
static Value or_3;
static Value or_4;
static Value or_5;
static Value or_6;
static Value or_7;
static Value or_8;
static Value or_9;
static Value or_10;
static Value or_11;
static Value or_12;
static Value or_13;
static Value or_14;
static Value or_15;
static Value or_16;
static Value or_17;
static Value or_18;
static Value or_19;
static Value or_20;
static Value or_21;
static Value or_22;
static Value or_23;
static Value or_24;
static Value or_25;
static Value or_26;
static Value or_27;
static Value or_28;
static Value or_29;
static Value or_30;
static Value or_31;
static Value or_32;
static Value or_33;
static Value or_34;
static Value or_35;
static Value or_36;
static Value or_37;
static Value or_38;
static Value or_39;
static Value or_40;
static Value or_41;
static Value or_42;
static Value or_43;
static const char *t_typechecker_hiddenby_2_string_string[] = { "TheType : String", "Member : String" };
static const char *t_typechecker_typeofreceiver_1[] = { "Obj : Any" };
static const char *t_typechecker_propertiesof_1[] = { "TheStmt : Any" };
static const char *t_typechecker_declaresproperty_2_string_string[] = { "TheType : String", "Member : String" };
static const char *t_typechecker_checkvisibility_2_token[] = { "Obj : Any", "Member : Token" };
static const char *t_typechecker_assignable_2_string_string[] = { "Expected : String", "Actual : String" };
static const char *t_typechecker_mismatch_3_token_string_string[] = { "Where : Token", "Expected : String", "Actual : String" };
static const char *t_typechecker_resolve_1_list[] = { "Statements : List" };
static const char *t_typechecker_maptype_1[] = { "TheStmt : Any" };
static const char *t_typechecker_check_1[] = { "TheStmt : Any" };
static const char *t_typechecker_checkfunction_1[] = { "TheFunction : Any" };
static const char *t_typechecker_warnifdynamic_1[] = { "TheExpr : Any" };
static const char *t_typechecker_reduce_1[] = { "TheExpr : Any" };
static const char *t_typechecker_reducebinary_1[] = { "TheExpr : Any" };
static const char *t_typechecker_istexttype_1_string[] = { "TheType : String" };
static const char *t_typechecker_typeofvalue_1[] = { "Value : Any" };
static const char *t_typechecker_classnameof_1[] = { "Obj : Any" };
Value fn_rejects;
static const char *t_f_rejects[] = { "Source : String" };
Value v_hider;
bool d_hider;

static Value i_typelookup(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Scopes", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "Types", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "Parents", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "Inferred", alg_widen(alg_nil(), "TypeLookup"));
    alg_set_property(v_this, "DeclaredTypes", alg_widen(alg_set(), "Set"));
    alg_set_property(v_this, "Generics", alg_widen(alg_nil(), "TypeLookup"));
    alg_set_property(v_this, "CurrentClassName", alg_widen(alg_string(""), "String"));
    return alg_nil();
}

static Value m_typelookup_settype_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_symbol = alg_widen(args[0], "String");
    (void)v_symbol;
    Value v_thetype = alg_widen(args[1], "String");
    (void)v_thetype;
    if (alg_truthy(alg_property(alg_property(v_this, "Scopes"), "IsEmpty"))) {
        (void)(alg_invoke(alg_property(v_this, "Types"), "Put", (Value[]){v_symbol, v_thetype}, 2));
    } else {
        (void)(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1))), "Put", (Value[]){v_symbol, v_thetype}, 2));
    }
    return alg_nil();
}

static Value m_typelookup_gettype_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_symbol = alg_widen(args[0], "String");
    (void)v_symbol;
    {
        Value v_i = alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1));
        (void)v_i;
        for (; alg_truthy(alg_greater_equal(v_i, alg_int(0))); (v_i = alg_subtract(v_i, alg_int(1)))) {
            if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), v_i), "Contains", (Value[]){v_symbol}, 1))) {
                return alg_str(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), v_i), "Get", (Value[]){v_symbol}, 1));
            }
        }
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Types"), "Contains", (Value[]){v_symbol}, 1))) {
        return alg_str(alg_invoke(alg_property(v_this, "Types"), "Get", (Value[]){v_symbol}, 1));
    }
    return alg_string("");
    return alg_nil();
}

static Value m_typelookup_beginscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_invoke(alg_property(v_this, "Scopes"), "Add", (Value[]){alg_map()}, 1));
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Generics"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Generics"), "BeginScope", NULL, 0));
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Inferred"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Inferred"), "BeginScope", NULL, 0));
    }
    return alg_nil();
}

static Value m_typelookup_endscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_invoke(alg_property(v_this, "Scopes"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1))}, 1));
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Generics"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Generics"), "EndScope", NULL, 0));
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Inferred"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Inferred"), "EndScope", NULL, 0));
    }
    return alg_nil();
}

static Value i_typechecker(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Lookup", alg_nil());
    alg_set_property(v_this, "CurrentReturn", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "PrivateMembers", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "PropertyMembers", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "BuiltinTypes", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "Overloads", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "Signatures", alg_widen(alg_list(), "Set"));
    alg_set_property(v_this, "Warned", alg_widen(alg_list(), "Set"));
    return alg_nil();
}

static Value m_typechecker_init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_set_property(v_this, "Lookup", alg_widen(alg_new(k_typelookup, NULL, 0), "TypeLookup")));
    (void)(alg_set_property(alg_property(v_this, "Lookup"), "Generics", alg_new(k_typelookup, NULL, 0)));
    (void)(alg_set_property(alg_property(v_this, "Lookup"), "Inferred", alg_new(k_typelookup, NULL, 0)));
    {
        Value loop_0 = alg_iterable(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_string("List")), alg_string("Map")), alg_string("Set")), alg_string("Stack")), alg_string("Array")));
        for (int32_t at_0 = 0; at_0 < alg_iterable_count(loop_0); at_0++) {
            Value v_kind = alg_iterable_at(loop_0, at_0);
            (void)v_kind;
            {
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(v_kind, alg_string("::Length")), alg_string("Integer")}, 2));
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(v_kind, alg_string("::IsEmpty")), alg_string("Boolean")}, 2));
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(v_kind, alg_string("::Contains")), alg_string("Boolean")}, 2));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("List::IndexOf"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Array::IndexOf"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Map::Keys"), alg_string("List")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Map::Values"), alg_string("List")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Set::ToList"), alg_string("List")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("TextFile::ReadLn"), alg_string("String")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("TextFile::Eof"), alg_string("Boolean")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Buffer::Text"), alg_string("String")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Buffer::Length"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Buffer::IsEmpty"), alg_string("Boolean")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Buffer::GetInt"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Length"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Pos"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Copy"), alg_string("String")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Str"), alg_string("String")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Array"), alg_string("Array")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("List"), alg_string("List")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Map"), alg_string("Map")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Set"), alg_string("Set")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Stack"), alg_string("Stack")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Buffer"), alg_string("Buffer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("TextFile"), alg_string("TextFile")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("FileExists"), alg_string("Boolean")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("ParamCount"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("ParamStr"), alg_string("String")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Write"), alg_string("Nil")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("WriteLn"), alg_string("Nil")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Ord"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Char"), alg_string("Char")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Mod"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("clock"), alg_string("Double")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Copy"), alg_string("String")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Str"), alg_string("String")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("ParamStr"), alg_string("String")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Length"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Pos"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Ord"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("ParamCount"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("FileExists"), alg_string("Boolean")}, 2));
    {
        Value loop_1 = alg_iterable(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_string("Length")), alg_string("Pos")), alg_string("Copy")), alg_string("Str")), alg_string("Array")), alg_string("List")), alg_string("Map")), alg_string("Set")), alg_string("Stack")), alg_string("Buffer")), alg_string("TextFile")), alg_string("FileExists")), alg_string("ParamCount")), alg_string("ParamStr")), alg_string("Write")), alg_string("WriteLn")), alg_string("Ord")), alg_string("Val")), alg_string("Char")), alg_string("Max")), alg_string("Mod")), alg_string("clock")));
        for (int32_t at_1 = 0; at_1 < alg_iterable_count(loop_1); at_1++) {
            Value v_name = alg_iterable_at(loop_1, at_1);
            (void)v_name;
            (void)(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Put", (Value[]){v_name, alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){v_name}, 1)}, 2));
        }
    }
    {
        Value loop_2 = alg_iterable(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_string("Any")), alg_string("Boolean")), alg_string("Integer")), alg_string("Double")), alg_string("String")), alg_string("Char")), alg_string("List")), alg_string("Set")), alg_string("Stack")), alg_string("Array")), alg_string("Map")), alg_string("TextFile")), alg_string("Buffer")), alg_string("Byte")), alg_string("Word")), alg_string("Short")));
        for (int32_t at_2 = 0; at_2 < alg_iterable_count(loop_2); at_2++) {
            Value v_name = alg_iterable_at(loop_2, at_2);
            (void)v_name;
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes"), "Add", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1));
        }
    }
    return alg_nil();
}

static Value m_typechecker_hiddenby_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thetype = alg_widen(args[0], "String");
    (void)v_thetype;
    Value v_member = alg_widen(args[1], "String");
    (void)v_member;
    Value v_at = alg_nil();
    (void)v_at;
    Value v_seen = alg_nil();
    (void)v_seen;
    (void)((v_at = alg_widen(v_thetype, "String")));
    (void)((v_seen = alg_widen(alg_list(), "List")));
    while (alg_truthy((or_1 = (or_0 = alg_not_equal(v_at, alg_string("")), !alg_truthy(or_0) ? or_0 : alg_not_equal(v_at, alg_string("Any"))), !alg_truthy(or_1) ? or_1 : alg_not(alg_invoke(v_seen, "Contains", (Value[]){v_at}, 1))))) {
        {
            (void)(alg_invoke(v_seen, "Add", (Value[]){v_at}, 1));
            if (alg_truthy(alg_invoke(alg_property(v_this, "PrivateMembers"), "Contains", (Value[]){v_at}, 1))) {
                if (alg_truthy(alg_invoke(alg_invoke(alg_property(v_this, "PrivateMembers"), "Get", (Value[]){v_at}, 1), "Contains", (Value[]){v_member}, 1))) {
                    return v_at;
                }
            }
            (void)((v_at = alg_widen(alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_at}, 1)), "String")));
            if (alg_truthy(alg_equal(v_at, alg_string("nil")))) {
                (void)((v_at = alg_widen(alg_string(""), "String")));
            }
        }
    }
    return alg_string("");
    return alg_nil();
}

static Value m_typechecker_typeofreceiver_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_obj = args[0];
    (void)v_obj;
    Value v_thetype = alg_nil();
    (void)v_thetype;
    (void)((v_thetype = alg_widen(alg_invoke(v_this, "Reduce", (Value[]){v_obj}, 1), "String")));
    if (alg_truthy((or_3 = ((or_2 = alg_equal(v_thetype, alg_string("")), alg_truthy(or_2) ? or_2 : alg_equal(v_thetype, alg_string("Any")))), !alg_truthy(or_3) ? or_3 : alg_is(v_obj, "VariableExpr")))) {
        {
            Value v_deduced = alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Inferred"), "GetType", (Value[]){alg_str(alg_property(alg_property(v_obj, "Name"), "Lexeme"))}, 1);
            (void)v_deduced;
            if (alg_truthy(alg_not_equal(v_deduced, alg_string("")))) {
                return v_deduced;
            }
        }
    }
    return v_thetype;
    return alg_nil();
}

static Value m_typechecker_propertiesof_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = args[0];
    (void)v_thestmt;
    Value v_found = alg_nil();
    (void)v_found;
    (void)((v_found = alg_widen(alg_list(), "List")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Methods"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_property(alg_subscript_get(alg_property(v_thestmt, "Methods"), v_i), "IsProperty"))) {
                (void)(alg_invoke(v_found, "Add", (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_thestmt, "Methods"), v_i), "Name"), "Lexeme"))}, 1));
            }
        }
    }
    return v_found;
    return alg_nil();
}

static Value m_typechecker_declaresproperty_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thetype = alg_widen(args[0], "String");
    (void)v_thetype;
    Value v_member = alg_widen(args[1], "String");
    (void)v_member;
    Value v_at = alg_nil();
    (void)v_at;
    Value v_seen = alg_nil();
    (void)v_seen;
    (void)((v_at = alg_widen(v_thetype, "String")));
    (void)((v_seen = alg_widen(alg_list(), "List")));
    while (alg_truthy((or_5 = (or_4 = alg_not_equal(v_at, alg_string("")), !alg_truthy(or_4) ? or_4 : alg_not_equal(v_at, alg_string("Any"))), !alg_truthy(or_5) ? or_5 : alg_not(alg_invoke(v_seen, "Contains", (Value[]){v_at}, 1))))) {
        {
            (void)(alg_invoke(v_seen, "Add", (Value[]){v_at}, 1));
            if (alg_truthy(alg_invoke(alg_property(v_this, "PropertyMembers"), "Contains", (Value[]){v_at}, 1))) {
                if (alg_truthy(alg_invoke(alg_invoke(alg_property(v_this, "PropertyMembers"), "Get", (Value[]){v_at}, 1), "Contains", (Value[]){v_member}, 1))) {
                    return v_at;
                }
            }
            (void)((v_at = alg_widen(alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_at}, 1)), "String")));
            if (alg_truthy(alg_equal(v_at, alg_string("nil")))) {
                (void)((v_at = alg_widen(alg_string(""), "String")));
            }
        }
    }
    return alg_string("");
    return alg_nil();
}

static Value m_typechecker_checkvisibility_2_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_obj = args[0];
    (void)v_obj;
    Value v_member = alg_widen(args[1], "Token");
    (void)v_member;
    Value v_thetype = alg_nil();
    (void)v_thetype;
    (void)((v_thetype = alg_widen(alg_invoke(v_this, "TypeOfReceiver", (Value[]){v_obj}, 1), "String")));
    Value v_owner = alg_invoke(v_this, "HiddenBy", (Value[]){v_thetype, alg_str(alg_property(v_member, "Lexeme"))}, 2);
    (void)v_owner;
    if (alg_truthy((or_6 = alg_equal(v_owner, alg_string("")), alg_truthy(or_6) ? or_6 : alg_equal(v_owner, alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"))))) {
        return alg_nil();
    }
    alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_property(v_member, "Lexeme")), alg_string("' is private to ")), v_owner), alg_char_value(46)));
    return alg_nil();
}

static Value m_typechecker_assignable_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_expected = alg_widen(args[0], "String");
    (void)v_expected;
    Value v_actual = alg_widen(args[1], "String");
    (void)v_actual;
    Value v_parent = alg_nil();
    (void)v_parent;
    (void)((v_expected = alg_widen(f_underlyingtype(NULL, (Value[]){v_expected}, 1), "String")));
    (void)((v_actual = alg_widen(f_underlyingtype(NULL, (Value[]){v_actual}, 1), "String")));
    if (alg_truthy((or_7 = alg_equal(v_expected, alg_string("")), alg_truthy(or_7) ? or_7 : alg_equal(v_actual, alg_string(""))))) {
        return alg_bool(true);
    }
    if (alg_truthy((or_8 = alg_equal(v_expected, alg_string("Any")), alg_truthy(or_8) ? or_8 : alg_equal(v_actual, alg_string("Any"))))) {
        return alg_bool(true);
    }
    if (alg_truthy(alg_equal(v_actual, alg_string("Nil")))) {
        return alg_bool(true);
    }
    if (alg_truthy(alg_equal(v_expected, v_actual))) {
        return alg_bool(true);
    }
    if (alg_truthy((or_9 = alg_equal(v_expected, alg_string("Double")), !alg_truthy(or_9) ? or_9 : alg_equal(v_actual, alg_string("Integer"))))) {
        return alg_bool(true);
    }
    if (alg_truthy((or_10 = alg_equal(v_expected, alg_string("String")), !alg_truthy(or_10) ? or_10 : alg_equal(v_actual, alg_string("Char"))))) {
        return alg_bool(true);
    }
    (void)((v_parent = alg_widen(alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_actual}, 1)), "String")));
    while (alg_truthy((or_11 = alg_not_equal(v_parent, alg_string("")), !alg_truthy(or_11) ? or_11 : alg_not_equal(v_parent, alg_string("nil"))))) {
        {
            if (alg_truthy(alg_equal(v_expected, v_parent))) {
                return alg_bool(true);
            }
            (void)((v_parent = alg_widen(alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_parent}, 1)), "String")));
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value m_typechecker_mismatch_3_token_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_where = alg_widen(args[0], "Token");
    (void)v_where;
    Value v_expected = alg_widen(args[1], "String");
    (void)v_expected;
    Value v_actual = alg_widen(args[2], "String");
    (void)v_actual;
    Value v_found = alg_nil();
    (void)v_found;
    Value v_message = alg_nil();
    (void)v_message;
    (void)((v_found = alg_widen(v_actual, "String")));
    if (alg_truthy(alg_equal(v_actual, alg_string("")))) {
        (void)((v_found = alg_widen(alg_string("an untyped expression"), "String")));
    }
    (void)((v_message = alg_widen(alg_add(alg_add(alg_add(alg_add(alg_string("Expected "), v_expected), alg_string(", found ")), v_found), alg_char_value(46)), "String")));
    (void)(alg_invoke(alg_singleton(k_console), "Error", (Value[]){v_where, v_message}, 2));
    return v_message;
    return alg_nil();
}

static Value m_typechecker_resolve_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(v_statements, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(v_this, "MapType", (Value[]){alg_subscript_get(v_statements, v_i)}, 1));
        }
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(v_statements, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_subscript_get(v_statements, v_i)}, 1));
        }
    }
    return alg_nil();
}

static Value m_typechecker_maptype_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = args[0];
    (void)v_thestmt;
    Value v_kind = alg_nil();
    (void)v_kind;
    (void)((v_kind = alg_widen(alg_invoke(v_this, "ClassNameOf", (Value[]){v_thestmt}, 1), "String")));
    if (alg_truthy(alg_equal(v_kind, alg_string("ClassStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "PrivateMembers"), "Put", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "PrivateMembers")}, 2));
            (void)(alg_invoke(alg_property(v_this, "PropertyMembers"), "Put", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_invoke(v_this, "PropertiesOf", (Value[]){v_thestmt}, 1)}, 2));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 2));
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)}, 1));
            if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Superclass"), alg_nil()))) {
                (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Put", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(alg_property(alg_property(v_thestmt, "Superclass"), "Name"), "Lexeme")}, 2));
            }
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Fields"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_property(alg_subscript_get(alg_property(v_thestmt, "Fields"), v_i), "Name"), "Lexeme")), alg_property(alg_subscript_get(alg_property(v_thestmt, "Fields"), v_i), "TypeName")}, 2));
                        (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_thestmt, "Fields"), v_i), "Name"), "Lexeme")), alg_property(alg_subscript_get(alg_property(v_thestmt, "Fields"), v_i), "Generic")}, 2));
                    }
                }
            }
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Methods"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_property(alg_subscript_get(alg_property(v_thestmt, "Methods"), v_i), "Name"), "Lexeme")), alg_property(alg_subscript_get(alg_property(v_thestmt, "Methods"), v_i), "ReturnType")}, 2));
                }
            }
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ObjectStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "PrivateMembers"), "Put", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "PrivateMembers")}, 2));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 2));
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)}, 1));
            if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Superclass"), alg_nil()))) {
                (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Put", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(alg_property(alg_property(v_thestmt, "Superclass"), "Name"), "Lexeme")}, 2));
            }
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Fields"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_property(alg_subscript_get(alg_property(v_thestmt, "Fields"), v_i), "Name"), "Lexeme")), alg_property(alg_subscript_get(alg_property(v_thestmt, "Fields"), v_i), "TypeName")}, 2));
                        (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_thestmt, "Fields"), v_i), "Name"), "Lexeme")), alg_property(alg_subscript_get(alg_property(v_thestmt, "Fields"), v_i), "Generic")}, 2));
                    }
                }
            }
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Methods"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_property(alg_subscript_get(alg_property(v_thestmt, "Methods"), v_i), "Name"), "Lexeme")), alg_property(alg_subscript_get(alg_property(v_thestmt, "Methods"), v_i), "ReturnType")}, 2));
                }
            }
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("FunctionStmt")))) {
        {
            Value v_folded = f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1);
            (void)v_folded;
            Value v_signature = alg_add(alg_add(v_folded, alg_char_value(47)), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length")));
            (void)v_signature;
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "ParamTypes"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)((v_signature = alg_add(alg_add(v_signature, alg_char_value(47)), f_foldcase(NULL, (Value[]){alg_str(alg_subscript_get(alg_property(v_thestmt, "ParamTypes"), v_i))}, 1))));
                }
            }
            if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Signatures"), "Contains", (Value[]){v_signature}, 1)))) {
                {
                    (void)(alg_invoke(alg_property(v_this, "Signatures"), "Add", (Value[]){v_signature}, 1));
                    Value v_seen = alg_int(0);
                    (void)v_seen;
                    if (alg_truthy(alg_invoke(alg_property(v_this, "Overloads"), "Contains", (Value[]){v_folded}, 1))) {
                        (void)((v_seen = alg_cast(alg_invoke(alg_property(v_this, "Overloads"), "Get", (Value[]){v_folded}, 1), "Integer")));
                    }
                    (void)(alg_invoke(alg_property(v_this, "Overloads"), "Put", (Value[]){v_folded, alg_add(v_seen, alg_int(1))}, 2));
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(v_thestmt, "ReturnType")}, 2));
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "ReturnGeneric")}, 2));
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("SubrangeStmt")))) {
        (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)}, 1));
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("EnumStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 2));
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)}, 1));
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Members"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_subscript_get(alg_property(v_thestmt, "Members"), v_i), "Lexeme"), alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 2));
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_subscript_get(alg_property(v_thestmt, "Members"), v_i), "Lexeme")), alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 2));
                    }
                }
            }
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("VarStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(v_thestmt, "TypeName")}, 2));
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "Generic")}, 2));
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("VarGroupStmt")))) {
        {
            Value v_i = alg_int(0);
            (void)v_i;
            for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Names"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                {
                    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_subscript_get(alg_property(v_thestmt, "Names"), v_i), "Lexeme"), alg_property(v_thestmt, "TypeName")}, 2));
                    (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_thestmt, "Names"), v_i), "Lexeme")), alg_property(v_thestmt, "Generic")}, 2));
                }
            }
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ModuleStmt")))) {
        if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Statements"), alg_nil()))) {
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Statements"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(v_this, "MapType", (Value[]){alg_subscript_get(alg_property(v_thestmt, "Statements"), v_i)}, 1));
                }
            }
        }
    }
    return alg_nil();
}

static Value m_typechecker_check_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = args[0];
    (void)v_thestmt;
    Value v_kind = alg_nil();
    (void)v_kind;
    (void)((v_kind = alg_widen(alg_invoke(v_this, "ClassNameOf", (Value[]){v_thestmt}, 1), "String")));
    if (alg_truthy(alg_equal(v_kind, alg_string("VarStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(v_thestmt, "TypeName")}, 2));
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "Generic")}, 2));
            if (alg_truthy((or_12 = alg_not_equal(alg_property(v_thestmt, "Initializer"), alg_nil()), !alg_truthy(or_12) ? or_12 : alg_equal(alg_property(v_thestmt, "TypeName"), alg_string(""))))) {
                (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Inferred"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Initializer")}, 1)}, 2));
            }
            if (alg_truthy((or_13 = alg_not_equal(alg_property(v_thestmt, "Initializer"), alg_nil()), !alg_truthy(or_13) ? or_13 : alg_not_equal(alg_property(v_thestmt, "TypeName"), alg_string(""))))) {
                {
                    Value v_actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Initializer")}, 1);
                    (void)v_actual;
                    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "TypeName"), alg_string("Any")))) {
                        if (alg_truthy((or_15 = (or_14 = alg_equal(v_actual, alg_string("")), alg_truthy(or_14) ? or_14 : alg_equal(v_actual, alg_string("Any"))), alg_truthy(or_15) ? or_15 : alg_not(alg_invoke(v_this, "Assignable", (Value[]){alg_property(v_thestmt, "TypeName"), v_actual}, 2))))) {
                            alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_property(v_thestmt, "Name"), alg_property(v_thestmt, "TypeName"), v_actual}, 3));
                        }
                    }
                }
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("VarGroupStmt")))) {
        {
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Names"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_subscript_get(alg_property(v_thestmt, "Names"), v_i), "Lexeme"), alg_property(v_thestmt, "TypeName")}, 2));
                        (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_thestmt, "Names"), v_i), "Lexeme")), alg_property(v_thestmt, "Generic")}, 2));
                    }
                }
            }
            if (alg_truthy((or_16 = alg_not_equal(alg_property(v_thestmt, "Initializer"), alg_nil()), !alg_truthy(or_16) ? or_16 : alg_not_equal(alg_property(v_thestmt, "TypeName"), alg_string(""))))) {
                {
                    Value v_actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Initializer")}, 1);
                    (void)v_actual;
                    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "TypeName"), alg_string("Any")))) {
                        if (alg_truthy((or_18 = (or_17 = alg_equal(v_actual, alg_string("")), alg_truthy(or_17) ? or_17 : alg_equal(v_actual, alg_string("Any"))), alg_truthy(or_18) ? or_18 : alg_not(alg_invoke(v_this, "Assignable", (Value[]){alg_property(v_thestmt, "TypeName"), v_actual}, 2))))) {
                            alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_subscript_get(alg_property(v_thestmt, "Names"), alg_int(0)), alg_property(v_thestmt, "TypeName"), v_actual}, 3));
                        }
                    }
                }
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ExpressionStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Expression")}, 1));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("BlockStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Statements"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(v_this, "Check", (Value[]){alg_subscript_get(alg_property(v_thestmt, "Statements"), v_i)}, 1));
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("IfStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Condition")}, 1));
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_thestmt, "ThenBranch")}, 1));
            if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "ElseBranch"), alg_nil()))) {
                (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_thestmt, "ElseBranch")}, 1));
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ForInStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Iterable")}, 1));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
            Value v_element = alg_string("");
            (void)v_element;
            if (alg_truthy(alg_is(alg_property(v_thestmt, "Iterable"), "VariableExpr"))) {
                (void)((v_element = alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "GetType", (Value[]){alg_str(alg_property(alg_property(alg_property(v_thestmt, "Iterable"), "Name"), "Lexeme"))}, 1)));
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_element}, 2));
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_thestmt, "Body")}, 1));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("WhileStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Condition")}, 1));
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_thestmt, "Body")}, 1));
            if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Increment"), alg_nil()))) {
                (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Increment")}, 1));
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("LabelStmt")))) {
        {
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_thestmt, "Inner")}, 1));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ReturnStmt")))) {
        {
            if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Value"), alg_nil()))) {
                {
                    Value v_actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Value")}, 1);
                    (void)v_actual;
                    if (alg_truthy(alg_not(alg_invoke(v_this, "Assignable", (Value[]){alg_property(v_this, "CurrentReturn"), v_actual}, 2)))) {
                        alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_property(v_thestmt, "Keyword"), alg_property(v_this, "CurrentReturn"), v_actual}, 3));
                    }
                }
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("TryStmt")))) {
        {
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_thestmt, "TryBlock")}, 1));
            Value v_keys = alg_invoke(alg_property(v_thestmt, "Handlers"), "Keys", NULL, 0);
            (void)v_keys;
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(v_keys, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(alg_invoke(alg_property(v_thestmt, "Handlers"), "Get", (Value[]){alg_subscript_get(v_keys, v_i)}, 1), "Body")}, 1));
                }
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("BreakStmt")))) {
        return alg_nil();
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ModuleStmt")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_thestmt, "Statements"), alg_nil()))) {
                return alg_nil();
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
            {
                Value loop_3 = alg_iterable(alg_property(v_this, "BuiltinTypes"));
                for (int32_t at_3 = 0; at_3 < alg_iterable_count(loop_3); at_3++) {
                    Value v_name = alg_iterable_at(loop_3, at_3);
                    (void)v_name;
                    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){v_name, alg_str(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Get", (Value[]){v_name}, 1))}, 2));
                }
            }
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Statements"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(v_this, "MapType", (Value[]){alg_subscript_get(alg_property(v_thestmt, "Statements"), v_i)}, 1));
                }
            }
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Statements"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(v_this, "Check", (Value[]){alg_subscript_get(alg_property(v_thestmt, "Statements"), v_i)}, 1));
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("RaiseStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Value")}, 1));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("FunctionStmt")))) {
        {
            (void)(alg_invoke(v_this, "CheckFunction", (Value[]){v_thestmt}, 1));
            return alg_nil();
        }
    }
    if (alg_truthy((or_19 = alg_equal(v_kind, alg_string("ObjectStmt")), alg_truthy(or_19) ? or_19 : alg_equal(v_kind, alg_string("ClassStmt"))))) {
        {
            Value v_enclosing = alg_property(alg_property(v_this, "Lookup"), "CurrentClassName");
            (void)v_enclosing;
            (void)(alg_set_property(alg_property(v_this, "Lookup"), "CurrentClassName", alg_widen(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), "String")));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Fields"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        Value v_field = alg_subscript_get(alg_property(v_thestmt, "Fields"), v_i);
                        (void)v_field;
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_field, "Name"), "Lexeme"), alg_property(v_field, "TypeName")}, 2));
                        (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_field, "Name"), "Lexeme")), alg_property(v_field, "Generic")}, 2));
                    }
                }
            }
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Methods"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(v_this, "CheckFunction", (Value[]){alg_subscript_get(alg_property(v_thestmt, "Methods"), v_i)}, 1));
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
            (void)(alg_set_property(alg_property(v_this, "Lookup"), "CurrentClassName", alg_widen(v_enclosing, "String")));
            return alg_nil();
        }
    }
    return alg_nil();
}

static Value m_typechecker_checkfunction_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thefunction = args[0];
    (void)v_thefunction;
    Value v_enclosing = alg_nil();
    (void)v_enclosing;
    (void)((v_enclosing = alg_widen(alg_property(v_this, "CurrentReturn"), "String")));
    (void)(alg_set_property(v_this, "CurrentReturn", alg_widen(alg_cast(alg_property(v_thefunction, "ReturnType"), "String"), "String")));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thefunction, "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_subscript_get(alg_property(v_thefunction, "Params"), v_i), "Lexeme"), alg_str(alg_subscript_get(alg_property(v_thefunction, "ParamTypes"), v_i))}, 2));
                if (alg_truthy(alg_less(v_i, alg_property(alg_property(v_thefunction, "ParamGenerics"), "Length")))) {
                    (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_thefunction, "Params"), v_i), "Lexeme")), alg_str(alg_subscript_get(alg_property(v_thefunction, "ParamGenerics"), v_i))}, 2));
                }
            }
        }
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thefunction, "Body"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_subscript_get(alg_property(v_thefunction, "Body"), v_i)}, 1), alg_string("FunctionStmt")))) {
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(alg_subscript_get(alg_property(v_thefunction, "Body"), v_i), "Name"), "Lexeme"), alg_property(alg_subscript_get(alg_property(v_thefunction, "Body"), v_i), "ReturnType")}, 2));
            }
        }
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thefunction, "Body"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_subscript_get(alg_property(v_thefunction, "Body"), v_i)}, 1));
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
    (void)(alg_set_property(v_this, "CurrentReturn", alg_widen(v_enclosing, "String")));
    return alg_nil();
}

static Value m_typechecker_warnifdynamic_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    Value v_folded = alg_nil();
    (void)v_folded;
    Value v_seen = alg_nil();
    (void)v_seen;
    Value v_key = alg_nil();
    (void)v_key;
    if (alg_truthy(alg_not_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_property(v_theexpr, "Callee")}, 1), alg_string("VariableExpr")))) {
        return alg_nil();
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "ArgumentNames"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_not_equal(alg_str(alg_subscript_get(alg_property(v_theexpr, "ArgumentNames"), v_i)), alg_string("")))) {
                return alg_nil();
            }
        }
    }
    (void)((v_folded = alg_widen(f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme"))}, 1), "String")));
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Overloads"), "Contains", (Value[]){v_folded}, 1)))) {
        return alg_nil();
    }
    (void)((v_seen = alg_widen(alg_cast(alg_invoke(alg_property(v_this, "Overloads"), "Get", (Value[]){v_folded}, 1), "Integer"), "Integer")));
    if (alg_truthy(alg_less(v_seen, alg_int(2)))) {
        return alg_nil();
    }
    (void)((v_key = alg_widen(alg_add(alg_add(alg_str(alg_property(alg_property(v_theexpr, "Paren"), "LineNumber")), alg_char_value(58)), v_folded), "String")));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Warned"), "Contains", (Value[]){v_key}, 1))) {
        return alg_nil();
    }
    (void)(alg_invoke(alg_property(v_this, "Warned"), "Add", (Value[]){v_key}, 1));
    (void)(alg_invoke(alg_singleton(k_console), "Warn", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_invoke(alg_singleton(k_sourcecode), "Name", NULL, 0), alg_char_value(58)), alg_str(alg_property(alg_property(v_theexpr, "Paren"), "LineNumber"))), alg_string(": '")), alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme"))), alg_string("' selects among ")), alg_str(v_seen)), alg_string(" overloads at run time."))}, 1));
    return alg_nil();
}

static Value m_typechecker_reduce_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    Value v_kind = alg_nil();
    (void)v_kind;
    if (alg_truthy(alg_equal(v_theexpr, alg_nil()))) {
        return alg_string("");
    }
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Cast"), alg_string("")))) {
        return alg_property(v_theexpr, "Cast");
    }
    (void)((v_kind = alg_widen(alg_invoke(v_this, "ClassNameOf", (Value[]){v_theexpr}, 1), "String")));
    if (alg_truthy(alg_equal(v_kind, alg_string("LiteralExpr")))) {
        return alg_invoke(v_this, "TypeOfValue", (Value[]){alg_property(v_theexpr, "Value")}, 1);
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("GroupingExpr")))) {
        return alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Expression")}, 1);
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("VariableExpr")))) {
        {
            Value v_written = alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1);
            (void)v_written;
            if (alg_truthy(alg_not_equal(v_written, alg_string("")))) {
                return v_written;
            }
            if (alg_truthy(alg_not_equal(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"), alg_string("")))) {
                {
                    Value v_owner = alg_str(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"));
                    (void)v_owner;
                    while (alg_truthy(alg_not_equal(v_owner, alg_string("")))) {
                        {
                            Value v_asfield = alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_add(alg_add(v_owner, alg_string("::")), alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme")))}, 1);
                            (void)v_asfield;
                            if (alg_truthy(alg_not_equal(v_asfield, alg_string("")))) {
                                return v_asfield;
                            }
                            if (alg_truthy(alg_not(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Contains", (Value[]){v_owner}, 1)))) {
                                (void)((v_owner = alg_string("")));
                            } else {
                                (void)((v_owner = alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_owner}, 1))));
                            }
                        }
                    }
                }
            }
            return alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Inferred"), "GetType", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("UnaryExpr")))) {
        {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVnot))) {
                return alg_string("Boolean");
            }
            return alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Right")}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("IsExpr")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
            if (alg_truthy(alg_not(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){f_canonicaltype(NULL, (Value[]){alg_property(alg_property(v_theexpr, "TypeName"), "Lexeme")}, 1)}, 1)}, 1)))) {
                {
                    Value v_message = alg_add(alg_add(alg_string("Unknown type '"), alg_str(alg_property(alg_property(v_theexpr, "TypeName"), "Lexeme"))), alg_string("'."));
                    (void)v_message;
                    (void)(alg_invoke(alg_singleton(k_console), "Error", (Value[]){alg_property(v_theexpr, "TypeName"), v_message}, 2));
                    alg_raise(v_message);
                }
            }
            return alg_string("Boolean");
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("BinaryExpr")))) {
        return alg_invoke(v_this, "ReduceBinary", (Value[]){v_theexpr}, 1);
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("LogicalExpr")))) {
        return alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Left")}, 1);
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("AssignExpr")))) {
        {
            Value v_declared = alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1);
            (void)v_declared;
            Value v_actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Value")}, 1);
            (void)v_actual;
            if (alg_truthy((or_20 = alg_not_equal(v_declared, alg_string("")), !alg_truthy(or_20) ? or_20 : alg_not_equal(v_declared, alg_string("Any"))))) {
                if (alg_truthy((or_22 = (or_21 = alg_equal(v_actual, alg_string("")), alg_truthy(or_21) ? or_21 : alg_equal(v_actual, alg_string("Any"))), alg_truthy(or_22) ? or_22 : alg_not(alg_invoke(v_this, "Assignable", (Value[]){v_declared, v_actual}, 2))))) {
                    alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_property(v_theexpr, "Name"), v_declared, v_actual}, 3));
                }
            }
            (void)(alg_set_property(v_theexpr, "Declared", v_declared));
            return v_declared;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("CallExpr")))) {
        {
            Value v_argtypes = alg_list();
            (void)v_argtypes;
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Arguments"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(v_argtypes, "Add", (Value[]){alg_invoke(v_this, "Reduce", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Arguments"), v_i)}, 1)}, 1));
                }
            }
            (void)(alg_invoke(v_this, "WarnIfDynamic", (Value[]){v_theexpr}, 1));
            if (alg_truthy(alg_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_property(v_theexpr, "Callee")}, 1), alg_string("VariableExpr")))) {
                if (alg_truthy((or_23 = alg_equal(alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme")), alg_string("Max")), !alg_truthy(or_23) ? or_23 : alg_equal(alg_property(v_argtypes, "Length"), alg_int(2))))) {
                    {
                        if (alg_truthy((or_24 = alg_equal(alg_str(alg_subscript_get(v_argtypes, alg_int(0))), alg_string("Double")), alg_truthy(or_24) ? or_24 : alg_equal(alg_str(alg_subscript_get(v_argtypes, alg_int(1))), alg_string("Double"))))) {
                            return alg_string("Double");
                        }
                        if (alg_truthy((or_25 = alg_equal(alg_str(alg_subscript_get(v_argtypes, alg_int(0))), alg_string("Integer")), !alg_truthy(or_25) ? or_25 : alg_equal(alg_str(alg_subscript_get(v_argtypes, alg_int(1))), alg_string("Integer"))))) {
                            return alg_string("Integer");
                        }
                        return alg_string("");
                    }
                }
            }
            return alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Callee")}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("GetExpr")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_theexpr, "Unit"), alg_string("System")))) {
                {
                    if (alg_truthy(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1))) {
                        return alg_str(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Get", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1));
                    }
                    return alg_string("");
                }
            }
            if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Unit"), alg_string("")))) {
                return alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1);
            }
            (void)(alg_invoke(v_this, "CheckVisibility", (Value[]){alg_property(v_theexpr, "Obj"), alg_property(v_theexpr, "Name")}, 2));
            Value v_owner = alg_invoke(v_this, "TypeOfReceiver", (Value[]){alg_property(v_theexpr, "Obj")}, 1);
            (void)v_owner;
            if (alg_truthy((or_26 = alg_equal(v_owner, alg_string("")), alg_truthy(or_26) ? or_26 : alg_equal(v_owner, alg_string("Any"))))) {
                return alg_string("");
            }
            return alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_add(alg_add(v_owner, alg_string("::")), alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("SetExpr")))) {
        {
            if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Unit"), alg_string("")))) {
                return alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Value")}, 1);
            }
            (void)(alg_invoke(v_this, "CheckVisibility", (Value[]){alg_property(v_theexpr, "Obj"), alg_property(v_theexpr, "Name")}, 2));
            Value v_owner = alg_invoke(v_this, "TypeOfReceiver", (Value[]){alg_property(v_theexpr, "Obj")}, 1);
            (void)v_owner;
            Value v_actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Value")}, 1);
            (void)v_actual;
            if (alg_truthy((or_27 = alg_equal(v_owner, alg_string("")), !alg_truthy(or_27) ? or_27 : alg_is(alg_property(v_theexpr, "Obj"), "ThisExpr")))) {
                (void)((v_owner = alg_str(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"))));
            }
            if (alg_truthy((or_28 = alg_not_equal(v_owner, alg_string("")), !alg_truthy(or_28) ? or_28 : alg_not_equal(v_owner, alg_string("Any"))))) {
                {
                    Value v_declaring = alg_invoke(v_this, "DeclaresProperty", (Value[]){v_owner, alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 2);
                    (void)v_declaring;
                    if (alg_truthy(alg_not_equal(v_declaring, alg_string("")))) {
                        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))), alg_string("' is a property of ")), v_declaring), alg_string(" and cannot be assigned.")));
                    }
                    Value v_declared = alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_add(alg_add(v_owner, alg_string("::")), alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1);
                    (void)v_declared;
                    if (alg_truthy((or_30 = (or_29 = alg_not_equal(v_declared, alg_string("")), !alg_truthy(or_29) ? or_29 : alg_not_equal(v_declared, alg_string("Any"))), !alg_truthy(or_30) ? or_30 : alg_not_equal(v_actual, alg_string(""))))) {
                        if (alg_truthy((or_31 = alg_equal(v_actual, alg_string("Any")), alg_truthy(or_31) ? or_31 : alg_not(alg_invoke(v_this, "Assignable", (Value[]){v_declared, v_actual}, 2))))) {
                            alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_property(v_theexpr, "Name"), v_declared, v_actual}, 3));
                        }
                    }
                    (void)(alg_set_property(v_theexpr, "Declared", v_declared));
                }
            }
            return v_actual;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ThisExpr")))) {
        return alg_string("");
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("CollectionExpr")))) {
        {
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Values"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Values"), v_i)}, 1));
                }
            }
            if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
                return alg_string("Map");
            }
            return alg_string("List");
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("SubscriptExpr")))) {
        {
            Value v_owner = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Obj")}, 1);
            (void)v_owner;
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Index")}, 1));
            if (alg_truthy(alg_invoke(v_this, "IsTextType", (Value[]){v_owner}, 1))) {
                return alg_string("Char");
            }
            if (alg_truthy(alg_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_property(v_theexpr, "Obj")}, 1), alg_string("VariableExpr")))) {
                return alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "GetType", (Value[]){alg_str(alg_property(alg_property(alg_property(v_theexpr, "Obj"), "Name"), "Lexeme"))}, 1);
            }
            return alg_string("");
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("SetSubscriptExpr")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Index")}, 1));
            return alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Value")}, 1);
        }
    }
    return alg_string("");
    return alg_nil();
}

static Value m_typechecker_reducebinary_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    Value v_left = alg_nil();
    (void)v_left;
    Value v_right = alg_nil();
    (void)v_right;
    Value v_op = alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken");
    (void)v_op;
    if (alg_truthy((or_36 = (or_35 = (or_34 = (or_33 = (or_32 = alg_equal(v_op, e_tokentype_tokenVgreater), alg_truthy(or_32) ? or_32 : alg_equal(v_op, e_tokentype_tokenVgreaterVequal)), alg_truthy(or_33) ? or_33 : alg_equal(v_op, e_tokentype_tokenVless)), alg_truthy(or_34) ? or_34 : alg_equal(v_op, e_tokentype_tokenVlessVequal)), alg_truthy(or_35) ? or_35 : alg_equal(v_op, e_tokentype_tokenVequal)), alg_truthy(or_36) ? or_36 : alg_equal(v_op, e_tokentype_tokenVnotVequal)))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Left")}, 1));
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Right")}, 1));
            return alg_string("Boolean");
        }
    }
    (void)((v_left = alg_widen(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Left")}, 1), "String")));
    (void)((v_right = alg_widen(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Right")}, 1), "String")));
    if (alg_truthy((or_39 = (or_38 = (or_37 = alg_equal(v_left, alg_string("")), alg_truthy(or_37) ? or_37 : alg_equal(v_right, alg_string(""))), alg_truthy(or_38) ? or_38 : alg_equal(v_left, alg_string("Any"))), alg_truthy(or_39) ? or_39 : alg_equal(v_right, alg_string("Any"))))) {
        return alg_string("");
    }
    if (alg_truthy(alg_equal(v_op, e_tokentype_tokenVin))) {
        return alg_string("Boolean");
    }
    if (alg_truthy((or_41 = alg_equal(v_op, e_tokentype_tokenVplus), !alg_truthy(or_41) ? or_41 : ((or_40 = alg_invoke(v_this, "IsTextType", (Value[]){v_left}, 1), alg_truthy(or_40) ? or_40 : alg_invoke(v_this, "IsTextType", (Value[]){v_right}, 1)))))) {
        return alg_string("String");
    }
    if (alg_truthy((or_42 = alg_equal(v_left, alg_string("Double")), alg_truthy(or_42) ? or_42 : alg_equal(v_right, alg_string("Double"))))) {
        return alg_string("Double");
    }
    if (alg_truthy(alg_equal(v_left, v_right))) {
        return v_left;
    }
    return alg_string("");
    return alg_nil();
}

static Value m_typechecker_istexttype_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thetype = alg_widen(args[0], "String");
    (void)v_thetype;
    return (or_43 = alg_equal(v_thetype, alg_string("String")), alg_truthy(or_43) ? or_43 : alg_equal(v_thetype, alg_string("Char")));
    return alg_nil();
}

static Value m_typechecker_typeofvalue_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_value = args[0];
    (void)v_value;
    if (alg_truthy(alg_equal(v_value, alg_nil()))) {
        return alg_string("Nil");
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
    if (alg_truthy(alg_is(v_value, "Char"))) {
        return alg_string("Char");
    }
    if (alg_truthy(alg_is(v_value, "String"))) {
        return alg_string("String");
    }
    return alg_invoke(v_this, "ClassNameOf", (Value[]){v_value}, 1);
    return alg_nil();
}

static Value m_typechecker_classnameof_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_obj = args[0];
    (void)v_obj;
    {
        AlgFrame frame_4;
        alg_push_frame(&frame_4);
        if (ALG_SETJMP(frame_4.jump) == 0) {
            {
                volatile Value ret_5 = alg_property(v_obj, "ClassName");
                alg_pop_frame();
                return ret_5;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_4[] = {"String"};
            int32_t which_4 = alg_handler(frame_4.raised, names_4, 1);
            if (which_4 == 0) {
                {
                    volatile Value v_e = frame_4.raised;
                    (void)v_e;
                    return alg_string("");
                }
            }
            else {
                alg_raise(frame_4.raised);
            }
        }
    }
    return alg_nil();
}

Value f_rejects(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    volatile Value v_source = alg_param(args[0], "String");
    (void)v_source;
    volatile Value v_thescanner = alg_new(k_scanner, (Value[]){v_source}, 1);
    (void)v_thescanner;
    volatile Value v_theparser = alg_new(k_parser, (Value[]){alg_invoke(v_thescanner, "ScanTokens", NULL, 0)}, 1);
    (void)v_theparser;
    {
        AlgFrame frame_6;
        alg_push_frame(&frame_6);
        if (ALG_SETJMP(frame_6.jump) == 0) {
            {
                (void)(alg_invoke(alg_new(k_typechecker, NULL, 0), "Resolve", (Value[]){alg_invoke(v_theparser, "Parse", NULL, 0)}, 1));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_6[] = {"String"};
            int32_t which_6 = alg_handler(frame_6.raised, names_6, 1);
            if (which_6 == 0) {
                {
                    volatile Value v_e = frame_6.raised;
                    (void)v_e;
                    return alg_bool(true);
                }
            }
            else {
                alg_raise(frame_6.raised);
            }
        }
    }
    return alg_bool(false);
    return alg_nil();
}

void init_TypeChecker(void) {
    k_typelookup = alg_class("TypeLookup", alg_nil());
    k_typechecker = alg_class("TypeChecker", alg_nil());
    alg_class_field(k_typelookup, "Scopes");
    alg_class_field(k_typelookup, "Types");
    alg_class_field(k_typelookup, "Parents");
    alg_class_field(k_typelookup, "Inferred");
    alg_class_field(k_typelookup, "DeclaredTypes");
    alg_class_field(k_typelookup, "Generics");
    alg_class_field(k_typelookup, "CurrentClassName");
    alg_class_initializer(k_typelookup, i_typelookup);
    alg_class_method(k_typelookup, "SetType", m_typelookup_settype_2_string_string, 2, t_typelookup_settype_2_string_string);
    alg_class_method(k_typelookup, "GetType", m_typelookup_gettype_1_string, 1, t_typelookup_gettype_1_string);
    alg_class_method(k_typelookup, "BeginScope", m_typelookup_beginscope_0, 0, NULL);
    alg_class_method(k_typelookup, "EndScope", m_typelookup_endscope_0, 0, NULL);
    alg_class_field(k_typechecker, "Lookup");
    alg_class_field(k_typechecker, "CurrentReturn");
    alg_class_field(k_typechecker, "PrivateMembers");
    alg_class_field(k_typechecker, "PropertyMembers");
    alg_class_field(k_typechecker, "BuiltinTypes");
    alg_class_field(k_typechecker, "Overloads");
    alg_class_field(k_typechecker, "Signatures");
    alg_class_field(k_typechecker, "Warned");
    alg_class_initializer(k_typechecker, i_typechecker);
    alg_class_method(k_typechecker, "Init", m_typechecker_init_0, 0, NULL);
    alg_class_method(k_typechecker, "HiddenBy", m_typechecker_hiddenby_2_string_string, 2, t_typechecker_hiddenby_2_string_string);
    alg_class_method(k_typechecker, "TypeOfReceiver", m_typechecker_typeofreceiver_1, 1, t_typechecker_typeofreceiver_1);
    alg_class_method(k_typechecker, "PropertiesOf", m_typechecker_propertiesof_1, 1, t_typechecker_propertiesof_1);
    alg_class_method(k_typechecker, "DeclaresProperty", m_typechecker_declaresproperty_2_string_string, 2, t_typechecker_declaresproperty_2_string_string);
    alg_class_method(k_typechecker, "CheckVisibility", m_typechecker_checkvisibility_2_token, 2, t_typechecker_checkvisibility_2_token);
    alg_class_method(k_typechecker, "Assignable", m_typechecker_assignable_2_string_string, 2, t_typechecker_assignable_2_string_string);
    alg_class_method(k_typechecker, "Mismatch", m_typechecker_mismatch_3_token_string_string, 3, t_typechecker_mismatch_3_token_string_string);
    alg_class_method(k_typechecker, "Resolve", m_typechecker_resolve_1_list, 1, t_typechecker_resolve_1_list);
    alg_class_method(k_typechecker, "MapType", m_typechecker_maptype_1, 1, t_typechecker_maptype_1);
    alg_class_method(k_typechecker, "Check", m_typechecker_check_1, 1, t_typechecker_check_1);
    alg_class_method(k_typechecker, "CheckFunction", m_typechecker_checkfunction_1, 1, t_typechecker_checkfunction_1);
    alg_class_method(k_typechecker, "WarnIfDynamic", m_typechecker_warnifdynamic_1, 1, t_typechecker_warnifdynamic_1);
    alg_class_method(k_typechecker, "Reduce", m_typechecker_reduce_1, 1, t_typechecker_reduce_1);
    alg_class_method(k_typechecker, "ReduceBinary", m_typechecker_reducebinary_1, 1, t_typechecker_reducebinary_1);
    alg_class_method(k_typechecker, "IsTextType", m_typechecker_istexttype_1_string, 1, t_typechecker_istexttype_1_string);
    alg_class_method(k_typechecker, "TypeOfValue", m_typechecker_typeofvalue_1, 1, t_typechecker_typeofvalue_1);
    alg_class_method(k_typechecker, "ClassNameOf", m_typechecker_classnameof_1, 1, t_typechecker_classnameof_1);
    fn_rejects = alg_closure("Rejects", f_rejects, NULL, 0, 1, t_f_rejects);
    v_hider = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("class Counter;"), alg_char_value(10)), alg_string("private:")), alg_char_value(10)), alg_string("    var Count : Integer := 0;")), alg_char_value(10)), alg_string("begin")), alg_char_value(10)), alg_string("    procedure Bump();")), alg_char_value(10)), alg_string("    begin")), alg_char_value(10)), alg_string("        Count := Count + 1;")), alg_char_value(10)), alg_string("    end")), alg_char_value(10)), alg_string("private:")), alg_char_value(10)), alg_string("    procedure Advance();")), alg_char_value(10)), alg_string("    begin")), alg_char_value(10)), alg_string("    end")), alg_char_value(10)), alg_string("end")), alg_char_value(10));
    d_hider = true;
}
