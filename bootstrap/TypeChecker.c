/* Generated from Algol-24.  Do not edit. */
#include "TypeChecker.h"
#include "Console.h"
#include "Interpreter.h"
#include "Parser.h"
#include "Scanner.h"
#include "SourceCode.h"
#include "Token.h"
#include "TokenType.h"

Value f_foldedbuiltins(Value **cells, Value *args, int32_t count);
Value f_rejects(Value **cells, Value *args, int32_t count);
Value f_candidates(Value **cells, Value *args, int32_t count);
Value k_typelookup;
static const char *t_typelookup_settype_2_string_string[] = { "Symbol : String", "TheType : String" };
static const char *t_typelookup_gettype_1_string[] = { "Symbol : String" };
Value fn_foldedbuiltins;
Value v_builtinVnames;
bool d_builtinVnames;
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
static Value or_44;
static Value or_45;
static Value or_46;
static Value or_47;
static Value or_48;
static const char *t_typechecker_hiddenby_2_string_string[] = { "TheType : String", "Member : String" };
static const char *t_typechecker_typeofreceiver_1[] = { "Obj : Any" };
static const char *t_typechecker_propertiesof_1[] = { "TheStmt : Any" };
static const char *t_typechecker_membersof_1[] = { "TheStmt : Any" };
static const char *t_typechecker_declaresmember_2_string_string[] = { "TheType : String", "Member : String" };
static const char *t_typechecker_declaresproperty_2_string_string[] = { "TheType : String", "Member : String" };
static const char *t_typechecker_elementof_1[] = { "Obj : Any" };
static const char *t_typechecker_checkelement_3_string_string_token[] = { "Element : String", "Actual : String", "Where : Token" };
static const char *t_typechecker_insertedat_1_string[] = { "Member : String" };
static const char *t_typechecker_checkliteral_3_string_token[] = { "Element : String", "Initializer : Any", "Where : Token" };
static const char *t_typechecker_checkvisibility_2_token[] = { "Obj : Any", "Member : Token" };
static const char *t_typechecker_assignable_2_string_string[] = { "Expected : String", "Actual : String" };
static const char *t_typechecker_mismatch_3_token_string_string[] = { "Where : Token", "Expected : String", "Actual : String" };
static const char *t_typechecker_resolve_1_list[] = { "Statements : List" };
static const char *t_typechecker_maptype_1[] = { "TheStmt : Any" };
static const char *t_typechecker_check_1[] = { "TheStmt : Any" };
static const char *t_typechecker_checkfunction_1[] = { "TheFunction : Any" };
static const char *t_typechecker_recordarity_2_string[] = { "TheStmt : Any", "Folded : String" };
static const char *t_typechecker_candidatesfor_2_string_integer[] = { "Folded : String", "Count : Integer" };
static const char *t_typechecker_warnifdynamic_1[] = { "TheExpr : Any" };
static const char *t_typechecker_warnifnoarity_1[] = { "TheExpr : Any" };
static const char *t_typechecker_warnifbitwisemeant_2_token_string[] = { "Op : Token", "TheType : String" };
static const char *t_typechecker_warnifshadowed_2_string[] = { "TheExpr : Any", "Owner : String" };
static const char *t_typechecker_reduce_1[] = { "TheExpr : Any" };
static const char *t_typechecker_reducebinary_1[] = { "TheExpr : Any" };
static const char *t_typechecker_istexttype_1_string[] = { "TheType : String" };
static const char *t_typechecker_typeofvalue_1[] = { "Value : Any" };
static const char *t_typechecker_classnameof_1[] = { "Obj : Any" };
Value fn_rejects;
static const char *t_f_rejects[] = { "Source : String" };
Value fn_candidates;
static const char *t_f_candidates[] = { "Source : String", "Name : String", "Count : Integer" };
Value v_hider;
bool d_hider;

static Value i_typelookup(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Scopes", alg_widen(alg_hold(alg_list()), "List"));
    alg_set_property(v_this, "Types", alg_widen(alg_hold(alg_map()), "Map"));
    alg_set_property(v_this, "Parents", alg_widen(alg_hold(alg_map()), "Map"));
    alg_set_property(v_this, "Inferred", alg_widen(alg_nil(), "TypeLookup"));
    alg_set_property(v_this, "DeclaredTypes", alg_widen(alg_hold(alg_set()), "Set"));
    alg_set_property(v_this, "Generics", alg_widen(alg_nil(), "TypeLookup"));
    alg_set_property(v_this, "CurrentClassName", alg_widen(alg_literal(""), "String"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_typelookup_settype_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_symbol = alg_widen(args[0], "String");
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    Value v_thetype = alg_widen(args[1], "String");
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    int32_t rh_1243 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_property(alg_property(v_this, "Scopes"), "IsEmpty")))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Types"), "Put", (Value[]){v_symbol, v_thetype}, 2)));
    } else {
        (void)(alg_hold(alg_invoke(alg_hold(alg_subscript_get(alg_property(v_this, "Scopes"), alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "Scopes"), "Length")), alg_int(1))))), "Put", (Value[]){v_symbol, v_thetype}, 2)));
    }
    alg_hold_top = rh_1243;
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

static Value m_typelookup_gettype_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_symbol = alg_widen(args[0], "String");
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    int32_t rh_1244 = alg_hold_top;
    {
        int32_t rt_1245 = alg_root_top;
        int32_t rh_1246 = alg_hold_top;
        Value v_i = alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "Scopes"), "Length")), alg_int(1)));
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1246;
        {
            int32_t rh_1247 = alg_hold_top;
            for (; (alg_hold_top = rh_1247, alg_truthy(alg_hold(alg_greater_equal(v_i, alg_int(0))))); (alg_hold_top = rh_1247, (v_i = alg_hold(alg_subtract(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold(alg_invoke(alg_hold(alg_subscript_get(alg_property(v_this, "Scopes"), v_i)), "Contains", (Value[]){v_symbol}, 1)))) {
                    Value ret_1 = alg_hold(alg_str(alg_hold(alg_invoke(alg_hold(alg_subscript_get(alg_property(v_this, "Scopes"), v_i)), "Get", (Value[]){v_symbol}, 1))));
                    alg_root_top = rt_base;
                    return ret_1;
                }
            }
        }
        alg_hold_top = rh_1246;
        alg_root_top = rt_1245;
    }
    alg_hold_top = rh_1244;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Types"), "Contains", (Value[]){v_symbol}, 1)))) {
        Value ret_2 = alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "Types"), "Get", (Value[]){v_symbol}, 1))));
        alg_root_top = rt_base;
        return ret_2;
    }
    alg_hold_top = rh_1244;
    Value ret_3 = alg_literal("");
    alg_root_top = rt_base;
    return ret_3;
    alg_hold_top = rh_1244;
    Value ret_4 = alg_nil();
    alg_root_top = rt_base;
    return ret_4;
}

static Value m_typelookup_beginscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1248 = alg_hold_top;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Scopes"), "Add", (Value[]){alg_hold(alg_map())}, 1)));
    alg_hold_top = rh_1248;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Generics"), alg_nil())))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Generics"), "BeginScope", NULL, 0)));
    }
    alg_hold_top = rh_1248;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Inferred"), alg_nil())))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Inferred"), "BeginScope", NULL, 0)));
    }
    alg_hold_top = rh_1248;
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

static Value m_typelookup_endscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1249 = alg_hold_top;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Scopes"), "RemoveAt", (Value[]){alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "Scopes"), "Length")), alg_int(1)))}, 1)));
    alg_hold_top = rh_1249;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Generics"), alg_nil())))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Generics"), "EndScope", NULL, 0)));
    }
    alg_hold_top = rh_1249;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "Inferred"), alg_nil())))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Inferred"), "EndScope", NULL, 0)));
    }
    alg_hold_top = rh_1249;
    Value ret_6 = alg_nil();
    alg_root_top = rt_base;
    return ret_6;
}

Value f_foldedbuiltins(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    int32_t rh_1250 = alg_hold_top;
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    alg_hold_top = rh_1250;
    (void)((v_names = alg_hold(alg_set())));
    alg_hold_top = rh_1250;
    {
        int32_t rt_1251 = alg_root_top;
        Value loop_7 = alg_iterable(alg_hold(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_literal("Array")), alg_literal("AssertEqual")), alg_literal("AssertTrue")), alg_literal("Buffer")), alg_literal("ChDir")), alg_literal("Char")), alg_literal("clock")), alg_literal("Collect")), alg_literal("Copy")), alg_literal("ErrorLn")), alg_literal("Fail")), alg_literal("Fields")), alg_literal("FileExists")), alg_literal("Foreign")), alg_literal("GetDir")), alg_literal("Halt")), alg_literal("Length")), alg_literal("List")), alg_literal("Map")), alg_literal("MkDir")), alg_literal("Ord")), alg_literal("ParamCount")), alg_literal("ParamStr")), alg_literal("Pos")), alg_literal("Pred")), alg_literal("RmDir")), alg_literal("Set")), alg_literal("Stack")), alg_literal("Str")), alg_literal("Succ")), alg_literal("TextFile")), alg_literal("ToLower")), alg_literal("ToUpper")), alg_literal("TypeOf")), alg_literal("Val")), alg_literal("Write")), alg_literal("WriteLn"))));
        (void)loop_7;
        alg_root(&loop_7, 1);
        for (int32_t at_7 = 0; at_7 < alg_iterable_count(loop_7); at_7++) {
            alg_safe_point();
            int32_t rt_1252 = alg_root_top;
            Value v_name = alg_iterable_at(loop_7, at_7);
            (void)v_name;
            alg_root(&v_name, 1);
            (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(v_name))}, 1))}, 1)));
            alg_root_top = rt_1252;
        }
        alg_root_top = rt_1251;
    }
    alg_hold_top = rh_1250;
    Value ret_8 = v_names;
    alg_root_top = rt_base;
    return ret_8;
    alg_hold_top = rh_1250;
    Value ret_9 = alg_nil();
    alg_root_top = rt_base;
    return ret_9;
}

static Value i_typechecker(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Lookup", alg_nil());
    alg_set_property(v_this, "CurrentReturn", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "PrivateMembers", alg_widen(alg_hold(alg_map()), "Map"));
    alg_set_property(v_this, "PropertyMembers", alg_widen(alg_hold(alg_map()), "Map"));
    alg_set_property(v_this, "Members", alg_widen(alg_hold(alg_map()), "Map"));
    alg_set_property(v_this, "BuiltinTypes", alg_widen(alg_hold(alg_map()), "Map"));
    alg_set_property(v_this, "Overloads", alg_widen(alg_hold(alg_map()), "Map"));
    alg_set_property(v_this, "Arities", alg_widen(alg_hold(alg_map()), "Map"));
    alg_set_property(v_this, "Variadics", alg_widen(alg_hold(alg_map()), "Map"));
    alg_set_property(v_this, "Signatures", alg_widen(alg_hold(alg_list()), "Set"));
    alg_set_property(v_this, "Warned", alg_widen(alg_hold(alg_list()), "Set"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_typechecker_init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1253 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Lookup", alg_hold(alg_new(k_typelookup, NULL, 0)))));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_set_property(alg_hold(alg_property(v_this, "Lookup")), "Generics", alg_hold(alg_new(k_typelookup, NULL, 0)))));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_set_property(alg_hold(alg_property(v_this, "Lookup")), "Inferred", alg_hold(alg_new(k_typelookup, NULL, 0)))));
    alg_hold_top = rh_1253;
    {
        int32_t rt_1254 = alg_root_top;
        Value loop_10 = alg_iterable(alg_hold(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_literal("List")), alg_literal("Map")), alg_literal("Set")), alg_literal("Stack")), alg_literal("Array"))));
        (void)loop_10;
        alg_root(&loop_10, 1);
        for (int32_t at_10 = 0; at_10 < alg_iterable_count(loop_10); at_10++) {
            alg_safe_point();
            int32_t rt_1255 = alg_root_top;
            Value v_kind = alg_iterable_at(loop_10, at_10);
            (void)v_kind;
            alg_root(&v_kind, 1);
            {
                int32_t rh_1256 = alg_hold_top;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_add(v_kind, alg_literal("::Length"))), alg_literal("Integer")}, 2)));
                alg_hold_top = rh_1256;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_add(v_kind, alg_literal("::IsEmpty"))), alg_literal("Boolean")}, 2)));
                alg_hold_top = rh_1256;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_add(v_kind, alg_literal("::Contains"))), alg_literal("Boolean")}, 2)));
                alg_hold_top = rh_1256;
            }
            alg_root_top = rt_1255;
        }
        alg_root_top = rt_1254;
    }
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("List::IndexOf"), alg_literal("Integer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Array::IndexOf"), alg_literal("Integer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Map::Keys"), alg_literal("List")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Map::Values"), alg_literal("List")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Set::ToList"), alg_literal("List")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("TextFile::ReadLn"), alg_literal("String")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("TextFile::Eof"), alg_literal("Boolean")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Buffer::Text"), alg_literal("String")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Buffer::Length"), alg_literal("Integer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Buffer::IsEmpty"), alg_literal("Boolean")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Buffer::GetInt"), alg_literal("Integer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Length"), alg_literal("Integer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Pos"), alg_literal("Integer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Copy"), alg_literal("String")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Str"), alg_literal("String")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Array"), alg_literal("Array")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("List"), alg_literal("List")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Map"), alg_literal("Map")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Set"), alg_literal("Set")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Stack"), alg_literal("Stack")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Buffer"), alg_literal("Buffer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("TextFile"), alg_literal("TextFile")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("FileExists"), alg_literal("Boolean")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("ParamCount"), alg_literal("Integer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("ParamStr"), alg_literal("String")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Write"), alg_literal("Nil")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("WriteLn"), alg_literal("Nil")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("MkDir"), alg_literal("Nil")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("RmDir"), alg_literal("Nil")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("ChDir"), alg_literal("Nil")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("GetDir"), alg_literal("String")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Ord"), alg_literal("Integer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Char"), alg_literal("Char")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("clock"), alg_literal("Double")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Copy"), alg_literal("String")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Str"), alg_literal("String")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("ParamStr"), alg_literal("String")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Length"), alg_literal("Integer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Pos"), alg_literal("Integer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("Ord"), alg_literal("Integer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("ParamCount"), alg_literal("Integer")}, 2)));
    alg_hold_top = rh_1253;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_literal("FileExists"), alg_literal("Boolean")}, 2)));
    alg_hold_top = rh_1253;
    {
        int32_t rt_1257 = alg_root_top;
        Value loop_11 = alg_iterable(alg_hold(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_literal("Length")), alg_literal("Pos")), alg_literal("Copy")), alg_literal("Str")), alg_literal("Array")), alg_literal("List")), alg_literal("Map")), alg_literal("Set")), alg_literal("Stack")), alg_literal("Buffer")), alg_literal("TextFile")), alg_literal("FileExists")), alg_literal("ParamCount")), alg_literal("ParamStr")), alg_literal("Write")), alg_literal("WriteLn")), alg_literal("Ord")), alg_literal("Val")), alg_literal("Char")), alg_literal("clock")), alg_literal("ToUpper")), alg_literal("ToLower")), alg_literal("MkDir")), alg_literal("RmDir")), alg_literal("ChDir")), alg_literal("GetDir"))));
        (void)loop_11;
        alg_root(&loop_11, 1);
        for (int32_t at_11 = 0; at_11 < alg_iterable_count(loop_11); at_11++) {
            alg_safe_point();
            int32_t rt_1258 = alg_root_top;
            Value v_name = alg_iterable_at(loop_11, at_11);
            (void)v_name;
            alg_root(&v_name, 1);
            (void)(alg_hold(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Put", (Value[]){v_name, alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){v_name}, 1))}, 2)));
            alg_root_top = rt_1258;
        }
        alg_root_top = rt_1257;
    }
    alg_hold_top = rh_1253;
    {
        int32_t rt_1259 = alg_root_top;
        Value loop_12 = alg_iterable(alg_hold(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_literal("Any")), alg_literal("Boolean")), alg_literal("Integer")), alg_literal("Double")), alg_literal("String")), alg_literal("Char")), alg_literal("List")), alg_literal("Set")), alg_literal("Stack")), alg_literal("Array")), alg_literal("Map")), alg_literal("TextFile")), alg_literal("Buffer")), alg_literal("Pointer")), alg_literal("Byte")), alg_literal("Word")), alg_literal("Short"))));
        (void)loop_12;
        alg_root(&loop_12, 1);
        for (int32_t at_12 = 0; at_12 < alg_iterable_count(loop_12); at_12++) {
            alg_safe_point();
            int32_t rt_1260 = alg_root_top;
            Value v_name = alg_iterable_at(loop_12, at_12);
            (void)v_name;
            alg_root(&v_name, 1);
            (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes")), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)));
            alg_root_top = rt_1260;
        }
        alg_root_top = rt_1259;
    }
    alg_hold_top = rh_1253;
    Value ret_13 = alg_nil();
    alg_root_top = rt_base;
    return ret_13;
}

static Value m_typechecker_hiddenby_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thetype = alg_widen(args[0], "String");
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    Value v_member = alg_widen(args[1], "String");
    (void)v_member;
    alg_root(&v_member, 1);
    int32_t rh_1261 = alg_hold_top;
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    alg_hold_top = rh_1261;
    Value v_seen = alg_nil();
    (void)v_seen;
    alg_root(&v_seen, 1);
    alg_hold_top = rh_1261;
    (void)((v_at = v_thetype));
    alg_hold_top = rh_1261;
    (void)((v_seen = alg_hold(alg_list())));
    alg_hold_top = rh_1261;
    {
        int32_t rh_1262 = alg_hold_top;
        while ((alg_hold_top = rh_1262, alg_truthy(alg_hold((or_1 = alg_hold((or_0 = alg_hold(alg_not_equal(v_at, alg_literal(""))), !alg_truthy(or_0) ? or_0 : alg_hold(alg_not_equal(v_at, alg_literal("Any"))))), !alg_truthy(or_1) ? or_1 : alg_hold(alg_not(alg_hold(alg_invoke(v_seen, "Contains", (Value[]){v_at}, 1))))))))) {
            alg_safe_point();
            {
                int32_t rh_1263 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_seen, "Add", (Value[]){v_at}, 1)));
                alg_hold_top = rh_1263;
                if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "PrivateMembers"), "Contains", (Value[]){v_at}, 1)))) {
                    if (alg_truthy(alg_hold(alg_invoke(alg_hold(alg_invoke(alg_property(v_this, "PrivateMembers"), "Get", (Value[]){v_at}, 1)), "Contains", (Value[]){v_member}, 1)))) {
                        Value ret_14 = v_at;
                        alg_root_top = rt_base;
                        return ret_14;
                    }
                }
                alg_hold_top = rh_1263;
                (void)((v_at = alg_hold(alg_str(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Parents")), "Get", (Value[]){v_at}, 1))))));
                alg_hold_top = rh_1263;
                if (alg_truthy(alg_hold(alg_equal(v_at, alg_literal("nil"))))) {
                    (void)((v_at = alg_literal("")));
                }
                alg_hold_top = rh_1263;
            }
        }
    }
    alg_hold_top = rh_1261;
    Value ret_15 = alg_literal("");
    alg_root_top = rt_base;
    return ret_15;
    alg_hold_top = rh_1261;
    Value ret_16 = alg_nil();
    alg_root_top = rt_base;
    return ret_16;
}

static Value m_typechecker_typeofreceiver_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    int32_t rh_1264 = alg_hold_top;
    Value v_thetype = alg_nil();
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    alg_hold_top = rh_1264;
    (void)((v_thetype = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){v_obj}, 1))));
    alg_hold_top = rh_1264;
    if (alg_truthy(alg_hold((or_3 = (alg_hold((or_2 = alg_hold(alg_equal(v_thetype, alg_literal(""))), alg_truthy(or_2) ? or_2 : alg_hold(alg_equal(v_thetype, alg_literal("Any")))))), !alg_truthy(or_3) ? or_3 : alg_is(v_obj, "VariableExpr"))))) {
        {
            int32_t rt_1265 = alg_root_top;
            int32_t rh_1266 = alg_hold_top;
            Value v_deduced = alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Inferred")), "GetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_obj, "Name")), "Lexeme"))))}, 1));
            (void)v_deduced;
            alg_root(&v_deduced, 1);
            alg_hold_top = rh_1266;
            if (alg_truthy(alg_hold(alg_not_equal(v_deduced, alg_literal(""))))) {
                Value ret_17 = v_deduced;
                alg_root_top = rt_base;
                return ret_17;
            }
            alg_hold_top = rh_1266;
            alg_root_top = rt_1265;
        }
    }
    alg_hold_top = rh_1264;
    Value ret_18 = v_thetype;
    alg_root_top = rt_base;
    return ret_18;
    alg_hold_top = rh_1264;
    Value ret_19 = alg_nil();
    alg_root_top = rt_base;
    return ret_19;
}

static Value m_typechecker_propertiesof_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1267 = alg_hold_top;
    Value v_found = alg_nil();
    (void)v_found;
    alg_root(&v_found, 1);
    alg_hold_top = rh_1267;
    (void)((v_found = alg_hold(alg_list())));
    alg_hold_top = rh_1267;
    {
        int32_t rt_1268 = alg_root_top;
        Value loop_20 = alg_iterable(alg_hold(alg_property(v_thestmt, "Methods")));
        (void)loop_20;
        alg_root(&loop_20, 1);
        for (int32_t at_20 = 0; at_20 < alg_iterable_count(loop_20); at_20++) {
            alg_safe_point();
            int32_t rt_1269 = alg_root_top;
            Value v_method = alg_iterable_at(loop_20, at_20);
            (void)v_method;
            alg_root(&v_method, 1);
            if (alg_truthy(alg_hold(alg_property(v_method, "IsProperty")))) {
                (void)(alg_hold(alg_invoke(v_found, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_method, "Name")), "Lexeme"))))}, 1)));
            }
            alg_root_top = rt_1269;
        }
        alg_root_top = rt_1268;
    }
    alg_hold_top = rh_1267;
    Value ret_21 = v_found;
    alg_root_top = rt_base;
    return ret_21;
    alg_hold_top = rh_1267;
    Value ret_22 = alg_nil();
    alg_root_top = rt_base;
    return ret_22;
}

static Value m_typechecker_membersof_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1270 = alg_hold_top;
    Value v_found = alg_nil();
    (void)v_found;
    alg_root(&v_found, 1);
    alg_hold_top = rh_1270;
    (void)((v_found = alg_hold(alg_list())));
    alg_hold_top = rh_1270;
    {
        int32_t rt_1271 = alg_root_top;
        Value loop_23 = alg_iterable(alg_hold(alg_property(v_thestmt, "Fields")));
        (void)loop_23;
        alg_root(&loop_23, 1);
        for (int32_t at_23 = 0; at_23 < alg_iterable_count(loop_23); at_23++) {
            alg_safe_point();
            int32_t rt_1272 = alg_root_top;
            Value v_field = alg_iterable_at(loop_23, at_23);
            (void)v_field;
            alg_root(&v_field, 1);
            {
                int32_t rh_1273 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_found, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme"))))}, 1)));
                alg_hold_top = rh_1273;
            }
            alg_root_top = rt_1272;
        }
        alg_root_top = rt_1271;
    }
    alg_hold_top = rh_1270;
    {
        int32_t rt_1274 = alg_root_top;
        Value loop_24 = alg_iterable(alg_hold(alg_property(v_thestmt, "Methods")));
        (void)loop_24;
        alg_root(&loop_24, 1);
        for (int32_t at_24 = 0; at_24 < alg_iterable_count(loop_24); at_24++) {
            alg_safe_point();
            int32_t rt_1275 = alg_root_top;
            Value v_method = alg_iterable_at(loop_24, at_24);
            (void)v_method;
            alg_root(&v_method, 1);
            {
                int32_t rh_1276 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_found, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_method, "Name")), "Lexeme"))))}, 1)));
                alg_hold_top = rh_1276;
            }
            alg_root_top = rt_1275;
        }
        alg_root_top = rt_1274;
    }
    alg_hold_top = rh_1270;
    Value ret_25 = v_found;
    alg_root_top = rt_base;
    return ret_25;
    alg_hold_top = rh_1270;
    Value ret_26 = alg_nil();
    alg_root_top = rt_base;
    return ret_26;
}

static Value m_typechecker_declaresmember_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thetype = alg_widen(args[0], "String");
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    Value v_member = alg_widen(args[1], "String");
    (void)v_member;
    alg_root(&v_member, 1);
    int32_t rh_1277 = alg_hold_top;
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    alg_hold_top = rh_1277;
    Value v_seen = alg_nil();
    (void)v_seen;
    alg_root(&v_seen, 1);
    alg_hold_top = rh_1277;
    (void)((v_at = v_thetype));
    alg_hold_top = rh_1277;
    (void)((v_seen = alg_hold(alg_list())));
    alg_hold_top = rh_1277;
    {
        int32_t rh_1278 = alg_hold_top;
        while ((alg_hold_top = rh_1278, alg_truthy(alg_hold((or_5 = alg_hold((or_4 = alg_hold(alg_not_equal(v_at, alg_literal(""))), !alg_truthy(or_4) ? or_4 : alg_hold(alg_not_equal(v_at, alg_literal("Any"))))), !alg_truthy(or_5) ? or_5 : alg_hold(alg_not(alg_hold(alg_invoke(v_seen, "Contains", (Value[]){v_at}, 1))))))))) {
            alg_safe_point();
            {
                int32_t rh_1279 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_seen, "Add", (Value[]){v_at}, 1)));
                alg_hold_top = rh_1279;
                if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Members"), "Contains", (Value[]){v_at}, 1)))) {
                    {
                        int32_t rh_1280 = alg_hold_top;
                        {
                            int32_t rt_1281 = alg_root_top;
                            Value loop_27 = alg_iterable(alg_hold(alg_invoke(alg_property(v_this, "Members"), "Get", (Value[]){v_at}, 1)));
                            (void)loop_27;
                            alg_root(&loop_27, 1);
                            for (int32_t at_27 = 0; at_27 < alg_iterable_count(loop_27); at_27++) {
                                alg_safe_point();
                                int32_t rt_1282 = alg_root_top;
                                Value v_each = alg_iterable_at(loop_27, at_27);
                                (void)v_each;
                                alg_root(&v_each, 1);
                                {
                                    int32_t rh_1283 = alg_hold_top;
                                    if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(v_each))}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_member}, 1)))))) {
                                        Value ret_28 = v_at;
                                        alg_root_top = rt_base;
                                        return ret_28;
                                    }
                                    alg_hold_top = rh_1283;
                                }
                                alg_root_top = rt_1282;
                            }
                            alg_root_top = rt_1281;
                        }
                        alg_hold_top = rh_1280;
                    }
                }
                alg_hold_top = rh_1279;
                (void)((v_at = alg_hold(alg_str(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Parents")), "Get", (Value[]){v_at}, 1))))));
                alg_hold_top = rh_1279;
                if (alg_truthy(alg_hold(alg_equal(v_at, alg_literal("nil"))))) {
                    (void)((v_at = alg_literal("")));
                }
                alg_hold_top = rh_1279;
            }
        }
    }
    alg_hold_top = rh_1277;
    Value ret_29 = alg_literal("");
    alg_root_top = rt_base;
    return ret_29;
    alg_hold_top = rh_1277;
    Value ret_30 = alg_nil();
    alg_root_top = rt_base;
    return ret_30;
}

static Value m_typechecker_declaresproperty_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thetype = alg_widen(args[0], "String");
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    Value v_member = alg_widen(args[1], "String");
    (void)v_member;
    alg_root(&v_member, 1);
    int32_t rh_1284 = alg_hold_top;
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    alg_hold_top = rh_1284;
    Value v_seen = alg_nil();
    (void)v_seen;
    alg_root(&v_seen, 1);
    alg_hold_top = rh_1284;
    (void)((v_at = v_thetype));
    alg_hold_top = rh_1284;
    (void)((v_seen = alg_hold(alg_list())));
    alg_hold_top = rh_1284;
    {
        int32_t rh_1285 = alg_hold_top;
        while ((alg_hold_top = rh_1285, alg_truthy(alg_hold((or_7 = alg_hold((or_6 = alg_hold(alg_not_equal(v_at, alg_literal(""))), !alg_truthy(or_6) ? or_6 : alg_hold(alg_not_equal(v_at, alg_literal("Any"))))), !alg_truthy(or_7) ? or_7 : alg_hold(alg_not(alg_hold(alg_invoke(v_seen, "Contains", (Value[]){v_at}, 1))))))))) {
            alg_safe_point();
            {
                int32_t rh_1286 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_seen, "Add", (Value[]){v_at}, 1)));
                alg_hold_top = rh_1286;
                if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "PropertyMembers"), "Contains", (Value[]){v_at}, 1)))) {
                    if (alg_truthy(alg_hold(alg_invoke(alg_hold(alg_invoke(alg_property(v_this, "PropertyMembers"), "Get", (Value[]){v_at}, 1)), "Contains", (Value[]){v_member}, 1)))) {
                        Value ret_31 = v_at;
                        alg_root_top = rt_base;
                        return ret_31;
                    }
                }
                alg_hold_top = rh_1286;
                (void)((v_at = alg_hold(alg_str(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Parents")), "Get", (Value[]){v_at}, 1))))));
                alg_hold_top = rh_1286;
                if (alg_truthy(alg_hold(alg_equal(v_at, alg_literal("nil"))))) {
                    (void)((v_at = alg_literal("")));
                }
                alg_hold_top = rh_1286;
            }
        }
    }
    alg_hold_top = rh_1284;
    Value ret_32 = alg_literal("");
    alg_root_top = rt_base;
    return ret_32;
    alg_hold_top = rh_1284;
    Value ret_33 = alg_nil();
    alg_root_top = rt_base;
    return ret_33;
}

static Value m_typechecker_elementof_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    int32_t rh_1287 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_invoke(v_this, "ClassNameOf", (Value[]){v_obj}, 1)), alg_literal("VariableExpr"))))) {
        Value ret_34 = alg_literal("");
        alg_root_top = rt_base;
        return ret_34;
    }
    alg_hold_top = rh_1287;
    Value ret_35 = alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Generics")), "GetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_obj, "Name")), "Lexeme"))))}, 1));
    alg_root_top = rt_base;
    return ret_35;
    alg_hold_top = rh_1287;
    Value ret_36 = alg_nil();
    alg_root_top = rt_base;
    return ret_36;
}

static Value m_typechecker_checkelement_3_string_string_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_element = alg_widen(args[0], "String");
    (void)v_element;
    alg_root(&v_element, 1);
    Value v_actual = alg_widen(args[1], "String");
    (void)v_actual;
    alg_root(&v_actual, 1);
    Value v_where = alg_widen(args[2], "Token");
    (void)v_where;
    alg_root(&v_where, 1);
    int32_t rh_1288 = alg_hold_top;
    if (alg_truthy(alg_hold((or_8 = alg_hold(alg_equal(v_element, alg_literal(""))), alg_truthy(or_8) ? or_8 : alg_hold(alg_equal(v_element, alg_literal("Any"))))))) {
        Value ret_37 = alg_nil();
        alg_root_top = rt_base;
        return ret_37;
    }
    alg_hold_top = rh_1288;
    if (alg_truthy(alg_hold((or_9 = alg_hold(alg_equal(v_actual, alg_literal(""))), alg_truthy(or_9) ? or_9 : alg_hold(alg_equal(v_actual, alg_literal("Any"))))))) {
        Value ret_38 = alg_nil();
        alg_root_top = rt_base;
        return ret_38;
    }
    alg_hold_top = rh_1288;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Assignable", (Value[]){v_element, v_actual}, 2)))))) {
        alg_raise(alg_hold(alg_invoke(v_this, "Mismatch", (Value[]){v_where, v_element, v_actual}, 3)));
    }
    alg_hold_top = rh_1288;
    Value ret_39 = alg_nil();
    alg_root_top = rt_base;
    return ret_39;
}

static Value m_typechecker_insertedat_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_member = alg_widen(args[0], "String");
    (void)v_member;
    alg_root(&v_member, 1);
    int32_t rh_1289 = alg_hold_top;
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    alg_hold_top = rh_1289;
    (void)((v_folded = alg_hold(f_foldcase(NULL, (Value[]){v_member}, 1))));
    alg_hold_top = rh_1289;
    if (alg_truthy(alg_hold(alg_equal(v_folded, alg_literal("add"))))) {
        Value ret_40 = alg_int(0);
        alg_root_top = rt_base;
        return ret_40;
    }
    alg_hold_top = rh_1289;
    if (alg_truthy(alg_hold(alg_equal(v_folded, alg_literal("push"))))) {
        Value ret_41 = alg_int(0);
        alg_root_top = rt_base;
        return ret_41;
    }
    alg_hold_top = rh_1289;
    if (alg_truthy(alg_hold(alg_equal(v_folded, alg_literal("put"))))) {
        Value ret_42 = alg_int(1);
        alg_root_top = rt_base;
        return ret_42;
    }
    alg_hold_top = rh_1289;
    Value ret_43 = alg_hold(alg_negate(alg_int(1)));
    alg_root_top = rt_base;
    return ret_43;
    alg_hold_top = rh_1289;
    Value ret_44 = alg_nil();
    alg_root_top = rt_base;
    return ret_44;
}

static Value m_typechecker_checkliteral_3_string_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_element = alg_widen(args[0], "String");
    (void)v_element;
    alg_root(&v_element, 1);
    Value v_initializer = args[1];
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    Value v_where = alg_widen(args[2], "Token");
    (void)v_where;
    alg_root(&v_where, 1);
    int32_t rh_1290 = alg_hold_top;
    if (alg_truthy(alg_hold((or_10 = alg_hold(alg_equal(v_element, alg_literal(""))), alg_truthy(or_10) ? or_10 : alg_hold(alg_equal(v_element, alg_literal("Any"))))))) {
        Value ret_45 = alg_nil();
        alg_root_top = rt_base;
        return ret_45;
    }
    alg_hold_top = rh_1290;
    if (alg_truthy(alg_hold(alg_equal(v_initializer, alg_nil())))) {
        Value ret_46 = alg_nil();
        alg_root_top = rt_base;
        return ret_46;
    }
    alg_hold_top = rh_1290;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_invoke(v_this, "ClassNameOf", (Value[]){v_initializer}, 1)), alg_literal("CollectionExpr"))))) {
        Value ret_47 = alg_nil();
        alg_root_top = rt_base;
        return ret_47;
    }
    alg_hold_top = rh_1290;
    {
        int32_t rt_1291 = alg_root_top;
        Value loop_48 = alg_iterable(alg_hold(alg_property(v_initializer, "Values")));
        (void)loop_48;
        alg_root(&loop_48, 1);
        for (int32_t at_48 = 0; at_48 < alg_iterable_count(loop_48); at_48++) {
            alg_safe_point();
            int32_t rt_1292 = alg_root_top;
            Value v_value = alg_iterable_at(loop_48, at_48);
            (void)v_value;
            alg_root(&v_value, 1);
            (void)(alg_hold(alg_invoke(v_this, "CheckElement", (Value[]){v_element, alg_hold(alg_invoke(v_this, "Reduce", (Value[]){v_value}, 1)), v_where}, 3)));
            alg_root_top = rt_1292;
        }
        alg_root_top = rt_1291;
    }
    alg_hold_top = rh_1290;
    Value ret_49 = alg_nil();
    alg_root_top = rt_base;
    return ret_49;
}

static Value m_typechecker_checkvisibility_2_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    Value v_member = alg_widen(args[1], "Token");
    (void)v_member;
    alg_root(&v_member, 1);
    int32_t rh_1293 = alg_hold_top;
    Value v_thetype = alg_nil();
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    alg_hold_top = rh_1293;
    (void)((v_thetype = alg_hold(alg_invoke(v_this, "TypeOfReceiver", (Value[]){v_obj}, 1))));
    alg_hold_top = rh_1293;
    Value v_owner = alg_hold(alg_invoke(v_this, "HiddenBy", (Value[]){v_thetype, alg_hold(alg_str(alg_hold(alg_property(v_member, "Lexeme"))))}, 2));
    (void)v_owner;
    alg_root(&v_owner, 1);
    alg_hold_top = rh_1293;
    if (alg_truthy(alg_hold((or_11 = alg_hold(alg_equal(v_owner, alg_literal(""))), alg_truthy(or_11) ? or_11 : alg_hold(alg_equal(v_owner, alg_hold(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName")))))))) {
        Value ret_50 = alg_nil();
        alg_root_top = rt_base;
        return ret_50;
    }
    alg_hold_top = rh_1293;
    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), alg_hold(alg_property(v_member, "Lexeme")))), alg_literal("' is private to "))), v_owner)), alg_char_value(46))));
    alg_hold_top = rh_1293;
    Value ret_51 = alg_nil();
    alg_root_top = rt_base;
    return ret_51;
}

static Value m_typechecker_assignable_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_expected = alg_widen(args[0], "String");
    (void)v_expected;
    alg_root(&v_expected, 1);
    Value v_actual = alg_widen(args[1], "String");
    (void)v_actual;
    alg_root(&v_actual, 1);
    int32_t rh_1294 = alg_hold_top;
    Value v_parent = alg_nil();
    (void)v_parent;
    alg_root(&v_parent, 1);
    alg_hold_top = rh_1294;
    (void)((v_expected = alg_hold(f_underlyingtype(NULL, (Value[]){v_expected}, 1))));
    alg_hold_top = rh_1294;
    (void)((v_actual = alg_hold(f_underlyingtype(NULL, (Value[]){v_actual}, 1))));
    alg_hold_top = rh_1294;
    if (alg_truthy(alg_hold((or_12 = alg_hold(alg_equal(v_expected, alg_literal(""))), alg_truthy(or_12) ? or_12 : alg_hold(alg_equal(v_actual, alg_literal(""))))))) {
        Value ret_52 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_52;
    }
    alg_hold_top = rh_1294;
    if (alg_truthy(alg_hold((or_13 = alg_hold(alg_equal(v_expected, alg_literal("Any"))), alg_truthy(or_13) ? or_13 : alg_hold(alg_equal(v_actual, alg_literal("Any"))))))) {
        Value ret_53 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_53;
    }
    alg_hold_top = rh_1294;
    if (alg_truthy(alg_hold(alg_equal(v_actual, alg_literal("Nil"))))) {
        Value ret_54 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_54;
    }
    alg_hold_top = rh_1294;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){v_expected}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_actual}, 1)))))) {
        Value ret_55 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_55;
    }
    alg_hold_top = rh_1294;
    if (alg_truthy(alg_hold((or_14 = alg_hold(alg_equal(v_expected, alg_literal("Double"))), !alg_truthy(or_14) ? or_14 : alg_hold(alg_equal(v_actual, alg_literal("Integer"))))))) {
        Value ret_56 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_56;
    }
    alg_hold_top = rh_1294;
    if (alg_truthy(alg_hold((or_15 = alg_hold(alg_equal(v_expected, alg_literal("String"))), !alg_truthy(or_15) ? or_15 : alg_hold(alg_equal(v_actual, alg_literal("Char"))))))) {
        Value ret_57 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_57;
    }
    alg_hold_top = rh_1294;
    (void)((v_parent = alg_hold(alg_str(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Parents")), "Get", (Value[]){v_actual}, 1))))));
    alg_hold_top = rh_1294;
    {
        int32_t rh_1295 = alg_hold_top;
        while ((alg_hold_top = rh_1295, alg_truthy(alg_hold((or_16 = alg_hold(alg_not_equal(v_parent, alg_literal(""))), !alg_truthy(or_16) ? or_16 : alg_hold(alg_not_equal(v_parent, alg_literal("nil")))))))) {
            alg_safe_point();
            {
                int32_t rh_1296 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){v_expected}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_parent}, 1)))))) {
                    Value ret_58 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_58;
                }
                alg_hold_top = rh_1296;
                (void)((v_parent = alg_hold(alg_str(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Parents")), "Get", (Value[]){v_parent}, 1))))));
                alg_hold_top = rh_1296;
            }
        }
    }
    alg_hold_top = rh_1294;
    Value ret_59 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_59;
    alg_hold_top = rh_1294;
    Value ret_60 = alg_nil();
    alg_root_top = rt_base;
    return ret_60;
}

static Value m_typechecker_mismatch_3_token_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_where = alg_widen(args[0], "Token");
    (void)v_where;
    alg_root(&v_where, 1);
    Value v_expected = alg_widen(args[1], "String");
    (void)v_expected;
    alg_root(&v_expected, 1);
    Value v_actual = alg_widen(args[2], "String");
    (void)v_actual;
    alg_root(&v_actual, 1);
    int32_t rh_1297 = alg_hold_top;
    Value v_found = alg_nil();
    (void)v_found;
    alg_root(&v_found, 1);
    alg_hold_top = rh_1297;
    Value v_message = alg_nil();
    (void)v_message;
    alg_root(&v_message, 1);
    alg_hold_top = rh_1297;
    (void)((v_found = v_actual));
    alg_hold_top = rh_1297;
    if (alg_truthy(alg_hold(alg_equal(v_actual, alg_literal(""))))) {
        (void)((v_found = alg_literal("an untyped expression")));
    }
    alg_hold_top = rh_1297;
    (void)((v_message = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expected "), v_expected)), alg_literal(", found "))), v_found)), alg_char_value(46)))));
    alg_hold_top = rh_1297;
    (void)(alg_hold(alg_invoke(alg_singleton(k_console), "Error", (Value[]){v_where, v_message}, 2)));
    alg_hold_top = rh_1297;
    Value ret_61 = v_message;
    alg_root_top = rt_base;
    return ret_61;
    alg_hold_top = rh_1297;
    Value ret_62 = alg_nil();
    alg_root_top = rt_base;
    return ret_62;
}

static Value m_typechecker_resolve_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_1298 = alg_hold_top;
    {
        int32_t rt_1299 = alg_root_top;
        Value loop_63 = alg_iterable(v_statements);
        (void)loop_63;
        alg_root(&loop_63, 1);
        for (int32_t at_63 = 0; at_63 < alg_iterable_count(loop_63); at_63++) {
            alg_safe_point();
            int32_t rt_1300 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_63, at_63);
            (void)v_statement;
            alg_root(&v_statement, 1);
            (void)(alg_hold(alg_invoke(v_this, "MapType", (Value[]){v_statement}, 1)));
            alg_root_top = rt_1300;
        }
        alg_root_top = rt_1299;
    }
    alg_hold_top = rh_1298;
    {
        int32_t rt_1301 = alg_root_top;
        Value loop_64 = alg_iterable(v_statements);
        (void)loop_64;
        alg_root(&loop_64, 1);
        for (int32_t at_64 = 0; at_64 < alg_iterable_count(loop_64); at_64++) {
            alg_safe_point();
            int32_t rt_1302 = alg_root_top;
            Value v_thestatement = alg_iterable_at(loop_64, at_64);
            (void)v_thestatement;
            alg_root(&v_thestatement, 1);
            (void)(alg_hold(alg_invoke(v_this, "Check", (Value[]){v_thestatement}, 1)));
            alg_root_top = rt_1302;
        }
        alg_root_top = rt_1301;
    }
    alg_hold_top = rh_1298;
    Value ret_65 = alg_nil();
    alg_root_top = rt_base;
    return ret_65;
}

static Value m_typechecker_maptype_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1303 = alg_hold_top;
    Value v_kind = alg_nil();
    (void)v_kind;
    alg_root(&v_kind, 1);
    alg_hold_top = rh_1303;
    (void)((v_kind = alg_hold(alg_invoke(v_this, "ClassNameOf", (Value[]){v_thestmt}, 1))));
    alg_hold_top = rh_1303;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("ClassStmt"))))) {
        {
            int32_t rh_1304 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "PrivateMembers"), "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), alg_hold(alg_property(v_thestmt, "PrivateMembers"))}, 2)));
            alg_hold_top = rh_1304;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "PropertyMembers"), "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), alg_hold(alg_invoke(v_this, "PropertiesOf", (Value[]){v_thestmt}, 1))}, 2)));
            alg_hold_top = rh_1304;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Members"), "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), alg_hold(alg_invoke(v_this, "MembersOf", (Value[]){v_thestmt}, 1))}, 2)));
            alg_hold_top = rh_1304;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 2)));
            alg_hold_top = rh_1304;
            (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes")), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))}, 1)));
            alg_hold_top = rh_1304;
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Superclass")), alg_nil())))) {
                (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Parents")), "Put", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Superclass")), "Name")), "Lexeme"))}, 2)));
            }
            alg_hold_top = rh_1304;
            {
                int32_t rt_1305 = alg_root_top;
                Value loop_66 = alg_iterable(alg_hold(alg_property(v_thestmt, "Fields")));
                (void)loop_66;
                alg_root(&loop_66, 1);
                for (int32_t at_66 = 0; at_66 < alg_iterable_count(loop_66); at_66++) {
                    alg_safe_point();
                    int32_t rt_1306 = alg_root_top;
                    Value v_field = alg_iterable_at(loop_66, at_66);
                    (void)v_field;
                    alg_root(&v_field, 1);
                    {
                        int32_t rh_1307 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_literal("::"))), alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme")))), alg_hold(alg_property(v_field, "TypeName"))}, 2)));
                        alg_hold_top = rh_1307;
                        (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Generics")), "SetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme")))), alg_hold(alg_property(v_field, "Generic"))}, 2)));
                        alg_hold_top = rh_1307;
                    }
                    alg_root_top = rt_1306;
                }
                alg_root_top = rt_1305;
            }
            alg_hold_top = rh_1304;
            {
                int32_t rt_1308 = alg_root_top;
                Value loop_67 = alg_iterable(alg_hold(alg_property(v_thestmt, "Methods")));
                (void)loop_67;
                alg_root(&loop_67, 1);
                for (int32_t at_67 = 0; at_67 < alg_iterable_count(loop_67); at_67++) {
                    alg_safe_point();
                    int32_t rt_1309 = alg_root_top;
                    Value v_method = alg_iterable_at(loop_67, at_67);
                    (void)v_method;
                    alg_root(&v_method, 1);
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_literal("::"))), alg_hold(alg_property(alg_hold(alg_property(v_method, "Name")), "Lexeme")))), alg_hold(alg_property(v_method, "ReturnType"))}, 2)));
                    alg_root_top = rt_1309;
                }
                alg_root_top = rt_1308;
            }
            alg_hold_top = rh_1304;
        }
    }
    alg_hold_top = rh_1303;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("ObjectStmt"))))) {
        {
            int32_t rh_1310 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "PrivateMembers"), "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), alg_hold(alg_property(v_thestmt, "PrivateMembers"))}, 2)));
            alg_hold_top = rh_1310;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Members"), "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), alg_hold(alg_invoke(v_this, "MembersOf", (Value[]){v_thestmt}, 1))}, 2)));
            alg_hold_top = rh_1310;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 2)));
            alg_hold_top = rh_1310;
            (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes")), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))}, 1)));
            alg_hold_top = rh_1310;
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Superclass")), alg_nil())))) {
                (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Parents")), "Put", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Superclass")), "Name")), "Lexeme"))}, 2)));
            }
            alg_hold_top = rh_1310;
            {
                int32_t rt_1311 = alg_root_top;
                Value loop_68 = alg_iterable(alg_hold(alg_property(v_thestmt, "Fields")));
                (void)loop_68;
                alg_root(&loop_68, 1);
                for (int32_t at_68 = 0; at_68 < alg_iterable_count(loop_68); at_68++) {
                    alg_safe_point();
                    int32_t rt_1312 = alg_root_top;
                    Value v_thefield = alg_iterable_at(loop_68, at_68);
                    (void)v_thefield;
                    alg_root(&v_thefield, 1);
                    {
                        int32_t rh_1313 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_literal("::"))), alg_hold(alg_property(alg_hold(alg_property(v_thefield, "Name")), "Lexeme")))), alg_hold(alg_property(v_thefield, "TypeName"))}, 2)));
                        alg_hold_top = rh_1313;
                        (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Generics")), "SetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thefield, "Name")), "Lexeme")))), alg_hold(alg_property(v_thefield, "Generic"))}, 2)));
                        alg_hold_top = rh_1313;
                    }
                    alg_root_top = rt_1312;
                }
                alg_root_top = rt_1311;
            }
            alg_hold_top = rh_1310;
            {
                int32_t rt_1314 = alg_root_top;
                Value loop_69 = alg_iterable(alg_hold(alg_property(v_thestmt, "Methods")));
                (void)loop_69;
                alg_root(&loop_69, 1);
                for (int32_t at_69 = 0; at_69 < alg_iterable_count(loop_69); at_69++) {
                    alg_safe_point();
                    int32_t rt_1315 = alg_root_top;
                    Value v_themethod = alg_iterable_at(loop_69, at_69);
                    (void)v_themethod;
                    alg_root(&v_themethod, 1);
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_literal("::"))), alg_hold(alg_property(alg_hold(alg_property(v_themethod, "Name")), "Lexeme")))), alg_hold(alg_property(v_themethod, "ReturnType"))}, 2)));
                    alg_root_top = rt_1315;
                }
                alg_root_top = rt_1314;
            }
            alg_hold_top = rh_1310;
        }
    }
    alg_hold_top = rh_1303;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("FunctionStmt"))))) {
        {
            int32_t rt_1316 = alg_root_top;
            int32_t rh_1317 = alg_hold_top;
            Value v_folded = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1));
            (void)v_folded;
            alg_root(&v_folded, 1);
            alg_hold_top = rh_1317;
            Value v_signature = alg_hold(alg_add(alg_hold(alg_add(v_folded, alg_char_value(47))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length"))))));
            (void)v_signature;
            alg_root(&v_signature, 1);
            alg_hold_top = rh_1317;
            {
                int32_t rt_1318 = alg_root_top;
                Value loop_70 = alg_iterable(alg_hold(alg_property(v_thestmt, "ParamTypes")));
                (void)loop_70;
                alg_root(&loop_70, 1);
                for (int32_t at_70 = 0; at_70 < alg_iterable_count(loop_70); at_70++) {
                    alg_safe_point();
                    int32_t rt_1319 = alg_root_top;
                    Value v_paramtype = alg_iterable_at(loop_70, at_70);
                    (void)v_paramtype;
                    alg_root(&v_paramtype, 1);
                    (void)((v_signature = alg_hold(alg_add(alg_hold(alg_add(v_signature, alg_char_value(47))), alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(v_paramtype))}, 1))))));
                    alg_root_top = rt_1319;
                }
                alg_root_top = rt_1318;
            }
            alg_hold_top = rh_1317;
            if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Signatures"), "Contains", (Value[]){v_signature}, 1)))))) {
                {
                    int32_t rt_1320 = alg_root_top;
                    int32_t rh_1321 = alg_hold_top;
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Signatures"), "Add", (Value[]){v_signature}, 1)));
                    alg_hold_top = rh_1321;
                    Value v_seen = alg_int(0);
                    (void)v_seen;
                    alg_root(&v_seen, 1);
                    alg_hold_top = rh_1321;
                    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Overloads"), "Contains", (Value[]){v_folded}, 1)))) {
                        (void)((v_seen = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "Overloads"), "Get", (Value[]){v_folded}, 1), ALG_KIND_INTEGER, "Integer"))));
                    }
                    alg_hold_top = rh_1321;
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Overloads"), "Put", (Value[]){v_folded, alg_hold(alg_add(v_seen, alg_int(1)))}, 2)));
                    alg_hold_top = rh_1321;
                    (void)(alg_hold(alg_invoke(v_this, "RecordArity", (Value[]){v_thestmt, v_folded}, 2)));
                    alg_hold_top = rh_1321;
                    alg_root_top = rt_1320;
                }
            }
            alg_hold_top = rh_1317;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_hold(alg_property(v_thestmt, "ReturnType"))}, 2)));
            alg_hold_top = rh_1317;
            (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Generics")), "SetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), alg_hold(alg_property(v_thestmt, "ReturnGeneric"))}, 2)));
            alg_hold_top = rh_1317;
            alg_root_top = rt_1316;
        }
    }
    alg_hold_top = rh_1303;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("SubrangeStmt"))))) {
        (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes")), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))}, 1)));
    }
    alg_hold_top = rh_1303;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("EnumStmt"))))) {
        {
            int32_t rh_1322 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 2)));
            alg_hold_top = rh_1322;
            (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes")), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))}, 1)));
            alg_hold_top = rh_1322;
            {
                int32_t rt_1323 = alg_root_top;
                Value loop_71 = alg_iterable(alg_hold(alg_property(v_thestmt, "Members")));
                (void)loop_71;
                alg_root(&loop_71, 1);
                for (int32_t at_71 = 0; at_71 < alg_iterable_count(loop_71); at_71++) {
                    alg_safe_point();
                    int32_t rt_1324 = alg_root_top;
                    Value v_member = alg_iterable_at(loop_71, at_71);
                    (void)v_member;
                    alg_root(&v_member, 1);
                    {
                        int32_t rh_1325 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(v_member, "Lexeme")), alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 2)));
                        alg_hold_top = rh_1325;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_literal("::"))), alg_hold(alg_property(v_member, "Lexeme")))), alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 2)));
                        alg_hold_top = rh_1325;
                    }
                    alg_root_top = rt_1324;
                }
                alg_root_top = rt_1323;
            }
            alg_hold_top = rh_1322;
        }
    }
    alg_hold_top = rh_1303;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("VarStmt"))))) {
        {
            int32_t rh_1326 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_hold(alg_property(v_thestmt, "TypeName"))}, 2)));
            alg_hold_top = rh_1326;
            (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Generics")), "SetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), alg_hold(alg_property(v_thestmt, "Generic"))}, 2)));
            alg_hold_top = rh_1326;
        }
    }
    alg_hold_top = rh_1303;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("VarGroupStmt"))))) {
        {
            int32_t rt_1327 = alg_root_top;
            Value loop_72 = alg_iterable(alg_hold(alg_property(v_thestmt, "Names")));
            (void)loop_72;
            alg_root(&loop_72, 1);
            for (int32_t at_72 = 0; at_72 < alg_iterable_count(loop_72); at_72++) {
                alg_safe_point();
                int32_t rt_1328 = alg_root_top;
                Value v_thename = alg_iterable_at(loop_72, at_72);
                (void)v_thename;
                alg_root(&v_thename, 1);
                {
                    int32_t rh_1329 = alg_hold_top;
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(v_thename, "Lexeme")), alg_hold(alg_property(v_thestmt, "TypeName"))}, 2)));
                    alg_hold_top = rh_1329;
                    (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Generics")), "SetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme")))), alg_hold(alg_property(v_thestmt, "Generic"))}, 2)));
                    alg_hold_top = rh_1329;
                }
                alg_root_top = rt_1328;
            }
            alg_root_top = rt_1327;
        }
    }
    alg_hold_top = rh_1303;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("ModuleStmt"))))) {
        if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Statements")), alg_nil())))) {
            {
                int32_t rt_1330 = alg_root_top;
                Value loop_73 = alg_iterable(alg_hold(alg_property(v_thestmt, "Statements")));
                (void)loop_73;
                alg_root(&loop_73, 1);
                for (int32_t at_73 = 0; at_73 < alg_iterable_count(loop_73); at_73++) {
                    alg_safe_point();
                    int32_t rt_1331 = alg_root_top;
                    Value v_thestatement = alg_iterable_at(loop_73, at_73);
                    (void)v_thestatement;
                    alg_root(&v_thestatement, 1);
                    (void)(alg_hold(alg_invoke(v_this, "MapType", (Value[]){v_thestatement}, 1)));
                    alg_root_top = rt_1331;
                }
                alg_root_top = rt_1330;
            }
        }
    }
    alg_hold_top = rh_1303;
    Value ret_74 = alg_nil();
    alg_root_top = rt_base;
    return ret_74;
}

static Value m_typechecker_check_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1332 = alg_hold_top;
    Value v_kind = alg_nil();
    (void)v_kind;
    alg_root(&v_kind, 1);
    alg_hold_top = rh_1332;
    (void)((v_kind = alg_hold(alg_invoke(v_this, "ClassNameOf", (Value[]){v_thestmt}, 1))));
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("VarStmt"))))) {
        {
            int32_t rh_1333 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), alg_hold(alg_property(v_thestmt, "TypeName"))}, 2)));
            alg_hold_top = rh_1333;
            (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Generics")), "SetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), alg_hold(alg_property(v_thestmt, "Generic"))}, 2)));
            alg_hold_top = rh_1333;
            if (alg_truthy(alg_hold((or_17 = alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Initializer")), alg_nil())), !alg_truthy(or_17) ? or_17 : alg_hold(alg_equal(alg_hold(alg_property(v_thestmt, "TypeName")), alg_literal(""))))))) {
                (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Inferred")), "SetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_thestmt, "Initializer"))}, 1))}, 2)));
            }
            alg_hold_top = rh_1333;
            (void)(alg_hold(alg_invoke(v_this, "CheckLiteral", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "Generic")))), alg_hold(alg_property(v_thestmt, "Initializer")), alg_hold(alg_property(v_thestmt, "Name"))}, 3)));
            alg_hold_top = rh_1333;
            if (alg_truthy(alg_hold((or_18 = alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Initializer")), alg_nil())), !alg_truthy(or_18) ? or_18 : alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "TypeName")), alg_literal(""))))))) {
                {
                    int32_t rt_1334 = alg_root_top;
                    int32_t rh_1335 = alg_hold_top;
                    Value v_actual = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_thestmt, "Initializer"))}, 1));
                    (void)v_actual;
                    alg_root(&v_actual, 1);
                    alg_hold_top = rh_1335;
                    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "TypeName")), alg_literal("Any"))))) {
                        if (alg_truthy(alg_hold((or_20 = alg_hold((or_19 = alg_hold(alg_equal(v_actual, alg_literal(""))), alg_truthy(or_19) ? or_19 : alg_hold(alg_equal(v_actual, alg_literal("Any"))))), alg_truthy(or_20) ? or_20 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Assignable", (Value[]){alg_hold(alg_property(v_thestmt, "TypeName")), v_actual}, 2)))))))) {
                            alg_raise(alg_hold(alg_invoke(v_this, "Mismatch", (Value[]){alg_hold(alg_property(v_thestmt, "Name")), alg_hold(alg_property(v_thestmt, "TypeName")), v_actual}, 3)));
                        }
                    }
                    alg_hold_top = rh_1335;
                    (void)(alg_hold(alg_set_property(v_thestmt, "Actual", v_actual)));
                    alg_hold_top = rh_1335;
                    alg_root_top = rt_1334;
                }
            }
            alg_hold_top = rh_1333;
            Value ret_75 = alg_nil();
            alg_root_top = rt_base;
            return ret_75;
            alg_hold_top = rh_1333;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("VarGroupStmt"))))) {
        {
            int32_t rh_1336 = alg_hold_top;
            {
                int32_t rt_1337 = alg_root_top;
                Value loop_76 = alg_iterable(alg_hold(alg_property(v_thestmt, "Names")));
                (void)loop_76;
                alg_root(&loop_76, 1);
                for (int32_t at_76 = 0; at_76 < alg_iterable_count(loop_76); at_76++) {
                    alg_safe_point();
                    int32_t rt_1338 = alg_root_top;
                    Value v_thename = alg_iterable_at(loop_76, at_76);
                    (void)v_thename;
                    alg_root(&v_thename, 1);
                    {
                        int32_t rh_1339 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(v_thename, "Lexeme")), alg_hold(alg_property(v_thestmt, "TypeName"))}, 2)));
                        alg_hold_top = rh_1339;
                        (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Generics")), "SetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme")))), alg_hold(alg_property(v_thestmt, "Generic"))}, 2)));
                        alg_hold_top = rh_1339;
                    }
                    alg_root_top = rt_1338;
                }
                alg_root_top = rt_1337;
            }
            alg_hold_top = rh_1336;
            if (alg_truthy(alg_hold((or_21 = alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Initializer")), alg_nil())), !alg_truthy(or_21) ? or_21 : alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "TypeName")), alg_literal(""))))))) {
                {
                    int32_t rt_1340 = alg_root_top;
                    int32_t rh_1341 = alg_hold_top;
                    Value v_actual = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_thestmt, "Initializer"))}, 1));
                    (void)v_actual;
                    alg_root(&v_actual, 1);
                    alg_hold_top = rh_1341;
                    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "TypeName")), alg_literal("Any"))))) {
                        if (alg_truthy(alg_hold((or_23 = alg_hold((or_22 = alg_hold(alg_equal(v_actual, alg_literal(""))), alg_truthy(or_22) ? or_22 : alg_hold(alg_equal(v_actual, alg_literal("Any"))))), alg_truthy(or_23) ? or_23 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Assignable", (Value[]){alg_hold(alg_property(v_thestmt, "TypeName")), v_actual}, 2)))))))) {
                            alg_raise(alg_hold(alg_invoke(v_this, "Mismatch", (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_thestmt, "Names")), alg_int(0))), alg_hold(alg_property(v_thestmt, "TypeName")), v_actual}, 3)));
                        }
                    }
                    alg_hold_top = rh_1341;
                    (void)(alg_hold(alg_set_property(v_thestmt, "Actual", v_actual)));
                    alg_hold_top = rh_1341;
                    alg_root_top = rt_1340;
                }
            }
            alg_hold_top = rh_1336;
            Value ret_77 = alg_nil();
            alg_root_top = rt_base;
            return ret_77;
            alg_hold_top = rh_1336;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("ExpressionStmt"))))) {
        {
            int32_t rh_1342 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_thestmt, "Expression"))}, 1)));
            alg_hold_top = rh_1342;
            Value ret_78 = alg_nil();
            alg_root_top = rt_base;
            return ret_78;
            alg_hold_top = rh_1342;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("BlockStmt"))))) {
        {
            int32_t rh_1343 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0)));
            alg_hold_top = rh_1343;
            {
                int32_t rt_1344 = alg_root_top;
                Value loop_79 = alg_iterable(alg_hold(alg_property(v_thestmt, "Statements")));
                (void)loop_79;
                alg_root(&loop_79, 1);
                for (int32_t at_79 = 0; at_79 < alg_iterable_count(loop_79); at_79++) {
                    alg_safe_point();
                    int32_t rt_1345 = alg_root_top;
                    Value v_statement = alg_iterable_at(loop_79, at_79);
                    (void)v_statement;
                    alg_root(&v_statement, 1);
                    (void)(alg_hold(alg_invoke(v_this, "Check", (Value[]){v_statement}, 1)));
                    alg_root_top = rt_1345;
                }
                alg_root_top = rt_1344;
            }
            alg_hold_top = rh_1343;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0)));
            alg_hold_top = rh_1343;
            Value ret_80 = alg_nil();
            alg_root_top = rt_base;
            return ret_80;
            alg_hold_top = rh_1343;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("IfStmt"))))) {
        {
            int32_t rh_1346 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_thestmt, "Condition"))}, 1)));
            alg_hold_top = rh_1346;
            (void)(alg_hold(alg_invoke(v_this, "Check", (Value[]){alg_hold(alg_property(v_thestmt, "ThenBranch"))}, 1)));
            alg_hold_top = rh_1346;
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "ElseBranch")), alg_nil())))) {
                (void)(alg_hold(alg_invoke(v_this, "Check", (Value[]){alg_hold(alg_property(v_thestmt, "ElseBranch"))}, 1)));
            }
            alg_hold_top = rh_1346;
            Value ret_81 = alg_nil();
            alg_root_top = rt_base;
            return ret_81;
            alg_hold_top = rh_1346;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("ForInStmt"))))) {
        {
            int32_t rt_1347 = alg_root_top;
            int32_t rh_1348 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_thestmt, "Iterable"))}, 1)));
            alg_hold_top = rh_1348;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0)));
            alg_hold_top = rh_1348;
            Value v_element = alg_literal("");
            (void)v_element;
            alg_root(&v_element, 1);
            alg_hold_top = rh_1348;
            if (alg_truthy(alg_is(alg_hold(alg_property(v_thestmt, "Iterable")), "VariableExpr"))) {
                (void)((v_element = alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Generics")), "GetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Iterable")), "Name")), "Lexeme"))))}, 1))));
            }
            alg_hold_top = rh_1348;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), v_element}, 2)));
            alg_hold_top = rh_1348;
            (void)(alg_hold(alg_invoke(v_this, "Check", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1)));
            alg_hold_top = rh_1348;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0)));
            alg_hold_top = rh_1348;
            Value ret_82 = alg_nil();
            alg_root_top = rt_base;
            return ret_82;
            alg_hold_top = rh_1348;
            alg_root_top = rt_1347;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("WhileStmt"))))) {
        {
            int32_t rh_1349 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_thestmt, "Condition"))}, 1)));
            alg_hold_top = rh_1349;
            (void)(alg_hold(alg_invoke(v_this, "Check", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1)));
            alg_hold_top = rh_1349;
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Increment")), alg_nil())))) {
                (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_thestmt, "Increment"))}, 1)));
            }
            alg_hold_top = rh_1349;
            Value ret_83 = alg_nil();
            alg_root_top = rt_base;
            return ret_83;
            alg_hold_top = rh_1349;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("LabelStmt"))))) {
        {
            int32_t rh_1350 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Check", (Value[]){alg_hold(alg_property(v_thestmt, "Inner"))}, 1)));
            alg_hold_top = rh_1350;
            Value ret_84 = alg_nil();
            alg_root_top = rt_base;
            return ret_84;
            alg_hold_top = rh_1350;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("ReturnStmt"))))) {
        {
            int32_t rh_1351 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Value")), alg_nil())))) {
                {
                    int32_t rt_1352 = alg_root_top;
                    int32_t rh_1353 = alg_hold_top;
                    Value v_actual = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_thestmt, "Value"))}, 1));
                    (void)v_actual;
                    alg_root(&v_actual, 1);
                    alg_hold_top = rh_1353;
                    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Assignable", (Value[]){alg_property(v_this, "CurrentReturn"), v_actual}, 2)))))) {
                        alg_raise(alg_hold(alg_invoke(v_this, "Mismatch", (Value[]){alg_hold(alg_property(v_thestmt, "Keyword")), alg_property(v_this, "CurrentReturn"), v_actual}, 3)));
                    }
                    alg_hold_top = rh_1353;
                    alg_root_top = rt_1352;
                }
            }
            alg_hold_top = rh_1351;
            Value ret_85 = alg_nil();
            alg_root_top = rt_base;
            return ret_85;
            alg_hold_top = rh_1351;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("TryStmt"))))) {
        {
            int32_t rt_1354 = alg_root_top;
            int32_t rh_1355 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Check", (Value[]){alg_hold(alg_property(v_thestmt, "TryBlock"))}, 1)));
            alg_hold_top = rh_1355;
            Value v_keys = alg_hold(alg_invoke(alg_hold(alg_property(v_thestmt, "Handlers")), "Keys", NULL, 0));
            (void)v_keys;
            alg_root(&v_keys, 1);
            alg_hold_top = rh_1355;
            {
                int32_t rt_1356 = alg_root_top;
                Value loop_86 = alg_iterable(v_keys);
                (void)loop_86;
                alg_root(&loop_86, 1);
                for (int32_t at_86 = 0; at_86 < alg_iterable_count(loop_86); at_86++) {
                    alg_safe_point();
                    int32_t rt_1357 = alg_root_top;
                    Value v_key = alg_iterable_at(loop_86, at_86);
                    (void)v_key;
                    alg_root(&v_key, 1);
                    (void)(alg_hold(alg_invoke(v_this, "Check", (Value[]){alg_hold(alg_property(alg_hold(alg_invoke(alg_hold(alg_property(v_thestmt, "Handlers")), "Get", (Value[]){v_key}, 1)), "Body"))}, 1)));
                    alg_root_top = rt_1357;
                }
                alg_root_top = rt_1356;
            }
            alg_hold_top = rh_1355;
            Value ret_87 = alg_nil();
            alg_root_top = rt_base;
            return ret_87;
            alg_hold_top = rh_1355;
            alg_root_top = rt_1354;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("BreakStmt"))))) {
        Value ret_88 = alg_nil();
        alg_root_top = rt_base;
        return ret_88;
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("ModuleStmt"))))) {
        {
            int32_t rh_1358 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_thestmt, "Statements")), alg_nil())))) {
                Value ret_89 = alg_nil();
                alg_root_top = rt_base;
                return ret_89;
            }
            alg_hold_top = rh_1358;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0)));
            alg_hold_top = rh_1358;
            {
                int32_t rt_1359 = alg_root_top;
                Value loop_90 = alg_iterable(alg_property(v_this, "BuiltinTypes"));
                (void)loop_90;
                alg_root(&loop_90, 1);
                for (int32_t at_90 = 0; at_90 < alg_iterable_count(loop_90); at_90++) {
                    alg_safe_point();
                    int32_t rt_1360 = alg_root_top;
                    Value v_name = alg_iterable_at(loop_90, at_90);
                    (void)v_name;
                    alg_root(&v_name, 1);
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){v_name, alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Get", (Value[]){v_name}, 1))))}, 2)));
                    alg_root_top = rt_1360;
                }
                alg_root_top = rt_1359;
            }
            alg_hold_top = rh_1358;
            {
                int32_t rt_1361 = alg_root_top;
                Value loop_91 = alg_iterable(alg_hold(alg_property(v_thestmt, "Statements")));
                (void)loop_91;
                alg_root(&loop_91, 1);
                for (int32_t at_91 = 0; at_91 < alg_iterable_count(loop_91); at_91++) {
                    alg_safe_point();
                    int32_t rt_1362 = alg_root_top;
                    Value v_thestatement = alg_iterable_at(loop_91, at_91);
                    (void)v_thestatement;
                    alg_root(&v_thestatement, 1);
                    (void)(alg_hold(alg_invoke(v_this, "MapType", (Value[]){v_thestatement}, 1)));
                    alg_root_top = rt_1362;
                }
                alg_root_top = rt_1361;
            }
            alg_hold_top = rh_1358;
            {
                int32_t rt_1363 = alg_root_top;
                Value loop_92 = alg_iterable(alg_hold(alg_property(v_thestmt, "Statements")));
                (void)loop_92;
                alg_root(&loop_92, 1);
                for (int32_t at_92 = 0; at_92 < alg_iterable_count(loop_92); at_92++) {
                    alg_safe_point();
                    int32_t rt_1364 = alg_root_top;
                    Value v_eachstatement = alg_iterable_at(loop_92, at_92);
                    (void)v_eachstatement;
                    alg_root(&v_eachstatement, 1);
                    (void)(alg_hold(alg_invoke(v_this, "Check", (Value[]){v_eachstatement}, 1)));
                    alg_root_top = rt_1364;
                }
                alg_root_top = rt_1363;
            }
            alg_hold_top = rh_1358;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0)));
            alg_hold_top = rh_1358;
            Value ret_93 = alg_nil();
            alg_root_top = rt_base;
            return ret_93;
            alg_hold_top = rh_1358;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("RaiseStmt"))))) {
        {
            int32_t rh_1365 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_thestmt, "Value"))}, 1)));
            alg_hold_top = rh_1365;
            Value ret_94 = alg_nil();
            alg_root_top = rt_base;
            return ret_94;
            alg_hold_top = rh_1365;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("FunctionStmt"))))) {
        {
            int32_t rh_1366 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "CheckFunction", (Value[]){v_thestmt}, 1)));
            alg_hold_top = rh_1366;
            Value ret_95 = alg_nil();
            alg_root_top = rt_base;
            return ret_95;
            alg_hold_top = rh_1366;
        }
    }
    alg_hold_top = rh_1332;
    if (alg_truthy(alg_hold((or_24 = alg_hold(alg_equal(v_kind, alg_literal("ObjectStmt"))), alg_truthy(or_24) ? or_24 : alg_hold(alg_equal(v_kind, alg_literal("ClassStmt"))))))) {
        {
            int32_t rt_1367 = alg_root_top;
            int32_t rh_1368 = alg_hold_top;
            Value v_enclosing = alg_hold(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"));
            (void)v_enclosing;
            alg_root(&v_enclosing, 1);
            alg_hold_top = rh_1368;
            (void)(alg_hold(alg_set_property(alg_property(v_this, "Lookup"), "CurrentClassName", alg_widen(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")), "String"))));
            alg_hold_top = rh_1368;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0)));
            alg_hold_top = rh_1368;
            {
                int32_t rt_1369 = alg_root_top;
                Value loop_96 = alg_iterable(alg_hold(alg_property(v_thestmt, "Fields")));
                (void)loop_96;
                alg_root(&loop_96, 1);
                for (int32_t at_96 = 0; at_96 < alg_iterable_count(loop_96); at_96++) {
                    alg_safe_point();
                    int32_t rt_1370 = alg_root_top;
                    Value v_field = alg_iterable_at(loop_96, at_96);
                    (void)v_field;
                    alg_root(&v_field, 1);
                    {
                        int32_t rh_1371 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme")), alg_hold(alg_property(v_field, "TypeName"))}, 2)));
                        alg_hold_top = rh_1371;
                        (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Generics")), "SetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme")))), alg_hold(alg_property(v_field, "Generic"))}, 2)));
                        alg_hold_top = rh_1371;
                    }
                    alg_root_top = rt_1370;
                }
                alg_root_top = rt_1369;
            }
            alg_hold_top = rh_1368;
            {
                int32_t rt_1372 = alg_root_top;
                Value loop_97 = alg_iterable(alg_hold(alg_property(v_thestmt, "Methods")));
                (void)loop_97;
                alg_root(&loop_97, 1);
                for (int32_t at_97 = 0; at_97 < alg_iterable_count(loop_97); at_97++) {
                    alg_safe_point();
                    int32_t rt_1373 = alg_root_top;
                    Value v_method = alg_iterable_at(loop_97, at_97);
                    (void)v_method;
                    alg_root(&v_method, 1);
                    (void)(alg_hold(alg_invoke(v_this, "CheckFunction", (Value[]){v_method}, 1)));
                    alg_root_top = rt_1373;
                }
                alg_root_top = rt_1372;
            }
            alg_hold_top = rh_1368;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0)));
            alg_hold_top = rh_1368;
            (void)(alg_hold(alg_set_property(alg_property(v_this, "Lookup"), "CurrentClassName", v_enclosing)));
            alg_hold_top = rh_1368;
            Value ret_98 = alg_nil();
            alg_root_top = rt_base;
            return ret_98;
            alg_hold_top = rh_1368;
            alg_root_top = rt_1367;
        }
    }
    alg_hold_top = rh_1332;
    Value ret_99 = alg_nil();
    alg_root_top = rt_base;
    return ret_99;
}

static Value m_typechecker_checkfunction_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thefunction = args[0];
    (void)v_thefunction;
    alg_root(&v_thefunction, 1);
    int32_t rh_1374 = alg_hold_top;
    Value v_enclosing = alg_nil();
    (void)v_enclosing;
    alg_root(&v_enclosing, 1);
    alg_hold_top = rh_1374;
    (void)((v_enclosing = alg_property(v_this, "CurrentReturn")));
    alg_hold_top = rh_1374;
    (void)(alg_set_property(v_this, "CurrentReturn", alg_hold(alg_cast_kind(alg_property(v_thefunction, "ReturnType"), ALG_KIND_STRING, "String"))));
    alg_hold_top = rh_1374;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0)));
    alg_hold_top = rh_1374;
    {
        int32_t rt_1375 = alg_root_top;
        int32_t rh_1376 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1376;
        {
            int32_t rh_1377 = alg_hold_top;
            for (; (alg_hold_top = rh_1377, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_thefunction, "Params")), "Length")))))); (alg_hold_top = rh_1377, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_1378 = alg_hold_top;
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(alg_hold(alg_subscript_get(alg_hold(alg_property(v_thefunction, "Params")), v_i)), "Lexeme")), alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(v_thefunction, "ParamTypes")), v_i))))}, 2)));
                    alg_hold_top = rh_1378;
                    if (alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_thefunction, "ParamGenerics")), "Length")))))) {
                        (void)(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Generics")), "SetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_subscript_get(alg_hold(alg_property(v_thefunction, "Params")), v_i)), "Lexeme")))), alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(v_thefunction, "ParamGenerics")), v_i))))}, 2)));
                    }
                    alg_hold_top = rh_1378;
                }
            }
        }
        alg_hold_top = rh_1376;
        alg_root_top = rt_1375;
    }
    alg_hold_top = rh_1374;
    {
        int32_t rt_1379 = alg_root_top;
        Value loop_100 = alg_iterable(alg_hold(alg_property(v_thefunction, "Body")));
        (void)loop_100;
        alg_root(&loop_100, 1);
        for (int32_t at_100 = 0; at_100 < alg_iterable_count(loop_100); at_100++) {
            alg_safe_point();
            int32_t rt_1380 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_100, at_100);
            (void)v_statement;
            alg_root(&v_statement, 1);
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "ClassNameOf", (Value[]){v_statement}, 1)), alg_literal("FunctionStmt"))))) {
                (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_statement, "Name")), "Lexeme")), alg_hold(alg_property(v_statement, "ReturnType"))}, 2)));
            }
            alg_root_top = rt_1380;
        }
        alg_root_top = rt_1379;
    }
    alg_hold_top = rh_1374;
    {
        int32_t rt_1381 = alg_root_top;
        Value loop_101 = alg_iterable(alg_hold(alg_property(v_thefunction, "Body")));
        (void)loop_101;
        alg_root(&loop_101, 1);
        for (int32_t at_101 = 0; at_101 < alg_iterable_count(loop_101); at_101++) {
            alg_safe_point();
            int32_t rt_1382 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_101, at_101);
            (void)v_statement;
            alg_root(&v_statement, 1);
            (void)(alg_hold(alg_invoke(v_this, "Check", (Value[]){v_statement}, 1)));
            alg_root_top = rt_1382;
        }
        alg_root_top = rt_1381;
    }
    alg_hold_top = rh_1374;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0)));
    alg_hold_top = rh_1374;
    (void)(alg_set_property(v_this, "CurrentReturn", v_enclosing));
    alg_hold_top = rh_1374;
    Value ret_102 = alg_nil();
    alg_root_top = rt_base;
    return ret_102;
}

static Value m_typechecker_recordarity_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_folded = alg_widen(args[1], "String");
    (void)v_folded;
    alg_root(&v_folded, 1);
    int32_t rh_1383 = alg_hold_top;
    Value v_count = alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length"));
    (void)v_count;
    alg_root(&v_count, 1);
    alg_hold_top = rh_1383;
    Value v_gathers = alg_bool(false);
    (void)v_gathers;
    alg_root(&v_gathers, 1);
    alg_hold_top = rh_1383;
    if (alg_truthy(alg_hold(alg_greater(v_count, alg_int(0))))) {
        (void)((v_gathers = alg_hold((or_25 = alg_hold(alg_equal(alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_thestmt, "ParamTypes")), alg_hold(alg_subtract(v_count, alg_int(1)))))}, 1)), alg_literal("List"))), !alg_truthy(or_25) ? or_25 : alg_hold(alg_not_equal(alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(v_thestmt, "ParamGenerics")), alg_hold(alg_subtract(v_count, alg_int(1))))))), alg_literal("")))))));
    }
    alg_hold_top = rh_1383;
    if (alg_truthy(v_gathers)) {
        {
            int32_t rh_1384 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Variadics"), "Contains", (Value[]){v_folded}, 1)))))) {
                (void)(alg_hold(alg_invoke(alg_property(v_this, "Variadics"), "Put", (Value[]){v_folded, alg_hold(alg_list())}, 2)));
            }
            alg_hold_top = rh_1384;
            (void)(alg_hold(alg_invoke(alg_hold(alg_invoke(alg_property(v_this, "Variadics"), "Get", (Value[]){v_folded}, 1)), "Add", (Value[]){alg_hold(alg_subtract(v_count, alg_int(1)))}, 1)));
            alg_hold_top = rh_1384;
            Value ret_103 = alg_nil();
            alg_root_top = rt_base;
            return ret_103;
            alg_hold_top = rh_1384;
        }
    }
    alg_hold_top = rh_1383;
    Value v_key = alg_hold(alg_add(alg_hold(alg_add(v_folded, alg_char_value(47))), alg_hold(alg_str(v_count))));
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_1383;
    Value v_taken = alg_int(0);
    (void)v_taken;
    alg_root(&v_taken, 1);
    alg_hold_top = rh_1383;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Arities"), "Contains", (Value[]){v_key}, 1)))) {
        (void)((v_taken = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "Arities"), "Get", (Value[]){v_key}, 1), ALG_KIND_INTEGER, "Integer"))));
    }
    alg_hold_top = rh_1383;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Arities"), "Put", (Value[]){v_key, alg_hold(alg_add(v_taken, alg_int(1)))}, 2)));
    alg_hold_top = rh_1383;
    Value ret_104 = alg_nil();
    alg_root_top = rt_base;
    return ret_104;
}

static Value m_typechecker_candidatesfor_2_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_folded = alg_widen(args[0], "String");
    (void)v_folded;
    alg_root(&v_folded, 1);
    Value v_count = alg_widen(args[1], "Integer");
    (void)v_count;
    alg_root(&v_count, 1);
    int32_t rh_1385 = alg_hold_top;
    Value v_total = alg_nil();
    (void)v_total;
    alg_root(&v_total, 1);
    alg_hold_top = rh_1385;
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_1385;
    (void)((v_total = alg_int(0)));
    alg_hold_top = rh_1385;
    (void)((v_key = alg_hold(alg_add(alg_hold(alg_add(v_folded, alg_char_value(47))), alg_hold(alg_str(v_count))))));
    alg_hold_top = rh_1385;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Arities"), "Contains", (Value[]){v_key}, 1)))) {
        (void)((v_total = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "Arities"), "Get", (Value[]){v_key}, 1), ALG_KIND_INTEGER, "Integer"))));
    }
    alg_hold_top = rh_1385;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Variadics"), "Contains", (Value[]){v_folded}, 1)))) {
        {
            int32_t rt_1386 = alg_root_top;
            Value loop_105 = alg_iterable(alg_hold(alg_invoke(alg_property(v_this, "Variadics"), "Get", (Value[]){v_folded}, 1)));
            (void)loop_105;
            alg_root(&loop_105, 1);
            for (int32_t at_105 = 0; at_105 < alg_iterable_count(loop_105); at_105++) {
                alg_safe_point();
                int32_t rt_1387 = alg_root_top;
                Value v_fixed = alg_iterable_at(loop_105, at_105);
                (void)v_fixed;
                alg_root(&v_fixed, 1);
                if (alg_truthy(alg_hold(alg_greater_equal(v_count, (alg_cast_kind(v_fixed, ALG_KIND_INTEGER, "Integer")))))) {
                    (void)((v_total = alg_hold(alg_add(v_total, alg_int(1)))));
                }
                alg_root_top = rt_1387;
            }
            alg_root_top = rt_1386;
        }
    }
    alg_hold_top = rh_1385;
    Value ret_106 = v_total;
    alg_root_top = rt_base;
    return ret_106;
    alg_hold_top = rh_1385;
    Value ret_107 = alg_nil();
    alg_root_top = rt_base;
    return ret_107;
}

static Value m_typechecker_warnifdynamic_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = args[0];
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1388 = alg_hold_top;
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    alg_hold_top = rh_1388;
    Value v_seen = alg_nil();
    (void)v_seen;
    alg_root(&v_seen, 1);
    alg_hold_top = rh_1388;
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_1388;
    Value v_count = alg_nil();
    (void)v_count;
    alg_root(&v_count, 1);
    alg_hold_top = rh_1388;
    (void)((v_count = alg_hold(alg_cast_kind(alg_property(alg_hold(alg_property(v_theexpr, "Arguments")), "Length"), ALG_KIND_INTEGER, "Integer"))));
    alg_hold_top = rh_1388;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_hold(alg_property(v_theexpr, "Callee"))}, 1)), alg_literal("GetExpr"))))) {
        {
            int32_t rh_1389 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Extension")))), alg_literal(""))))) {
                Value ret_108 = alg_nil();
                alg_root_top = rt_base;
                return ret_108;
            }
            alg_hold_top = rh_1389;
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Unit")), alg_literal(""))))) {
                Value ret_109 = alg_nil();
                alg_root_top = rt_base;
                return ret_109;
            }
            alg_hold_top = rh_1389;
            (void)((v_count = alg_hold(alg_add(v_count, alg_int(1)))));
            alg_hold_top = rh_1389;
        }
    } else {
        if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_hold(alg_property(v_theexpr, "Callee"))}, 1)), alg_literal("VariableExpr"))))) {
            Value ret_110 = alg_nil();
            alg_root_top = rt_base;
            return ret_110;
        }
    }
    alg_hold_top = rh_1388;
    {
        int32_t rt_1390 = alg_root_top;
        Value loop_111 = alg_iterable(alg_hold(alg_property(v_theexpr, "ArgumentNames")));
        (void)loop_111;
        alg_root(&loop_111, 1);
        for (int32_t at_111 = 0; at_111 < alg_iterable_count(loop_111); at_111++) {
            alg_safe_point();
            int32_t rt_1391 = alg_root_top;
            Value v_argumentname = alg_iterable_at(loop_111, at_111);
            (void)v_argumentname;
            alg_root(&v_argumentname, 1);
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_str(v_argumentname)), alg_literal(""))))) {
                Value ret_112 = alg_nil();
                alg_root_top = rt_base;
                return ret_112;
            }
            alg_root_top = rt_1391;
        }
        alg_root_top = rt_1390;
    }
    alg_hold_top = rh_1388;
    (void)((v_folded = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name")), "Lexeme"))))}, 1))));
    alg_hold_top = rh_1388;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Overloads"), "Contains", (Value[]){v_folded}, 1)))))) {
        Value ret_113 = alg_nil();
        alg_root_top = rt_base;
        return ret_113;
    }
    alg_hold_top = rh_1388;
    (void)((v_seen = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "Overloads"), "Get", (Value[]){v_folded}, 1), ALG_KIND_INTEGER, "Integer"))));
    alg_hold_top = rh_1388;
    if (alg_truthy(alg_hold(alg_less(v_seen, alg_int(2))))) {
        Value ret_114 = alg_nil();
        alg_root_top = rt_base;
        return ret_114;
    }
    alg_hold_top = rh_1388;
    (void)((v_seen = alg_hold(alg_invoke(v_this, "CandidatesFor", (Value[]){v_folded, v_count}, 2))));
    alg_hold_top = rh_1388;
    if (alg_truthy(alg_hold(alg_less(v_seen, alg_int(2))))) {
        Value ret_115 = alg_nil();
        alg_root_top = rt_base;
        return ret_115;
    }
    alg_hold_top = rh_1388;
    (void)((v_key = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Paren")), "LineNumber")))), alg_char_value(58))), v_folded))));
    alg_hold_top = rh_1388;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Warned"), "Contains", (Value[]){v_key}, 1)))) {
        Value ret_116 = alg_nil();
        alg_root_top = rt_base;
        return ret_116;
    }
    alg_hold_top = rh_1388;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Warned"), "Add", (Value[]){v_key}, 1)));
    alg_hold_top = rh_1388;
    (void)(alg_hold(alg_invoke(alg_singleton(k_console), "Warn", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(alg_singleton(k_sourcecode), "Named", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Paren")), "File"))))}, 1)), alg_char_value(58))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Paren")), "LineNumber")))))), alg_literal(": '"))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name")), "Lexeme")))))), alg_literal("' selects among "))), alg_hold(alg_str(v_seen)))), alg_literal(" overloads at run time.")))}, 1)));
    alg_hold_top = rh_1388;
    Value ret_117 = alg_nil();
    alg_root_top = rt_base;
    return ret_117;
}

static Value m_typechecker_warnifnoarity_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = args[0];
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1392 = alg_hold_top;
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    alg_hold_top = rh_1392;
    Value v_count = alg_nil();
    (void)v_count;
    alg_root(&v_count, 1);
    alg_hold_top = rh_1392;
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_1392;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_hold(alg_property(v_theexpr, "Callee"))}, 1)), alg_literal("VariableExpr"))))) {
        Value ret_118 = alg_nil();
        alg_root_top = rt_base;
        return ret_118;
    }
    alg_hold_top = rh_1392;
    {
        int32_t rt_1393 = alg_root_top;
        Value loop_119 = alg_iterable(alg_hold(alg_property(v_theexpr, "ArgumentNames")));
        (void)loop_119;
        alg_root(&loop_119, 1);
        for (int32_t at_119 = 0; at_119 < alg_iterable_count(loop_119); at_119++) {
            alg_safe_point();
            int32_t rt_1394 = alg_root_top;
            Value v_argumentname = alg_iterable_at(loop_119, at_119);
            (void)v_argumentname;
            alg_root(&v_argumentname, 1);
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_str(v_argumentname)), alg_literal(""))))) {
                Value ret_120 = alg_nil();
                alg_root_top = rt_base;
                return ret_120;
            }
            alg_root_top = rt_1394;
        }
        alg_root_top = rt_1393;
    }
    alg_hold_top = rh_1392;
    (void)((v_folded = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name")), "Lexeme"))))}, 1))));
    alg_hold_top = rh_1392;
    if (alg_truthy(alg_hold(alg_invoke((alg_declared(d_builtinVnames, "BUILTIN_NAMES"), v_builtinVnames), "Contains", (Value[]){v_folded}, 1)))) {
        Value ret_121 = alg_nil();
        alg_root_top = rt_base;
        return ret_121;
    }
    alg_hold_top = rh_1392;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Overloads"), "Contains", (Value[]){v_folded}, 1)))))) {
        Value ret_122 = alg_nil();
        alg_root_top = rt_base;
        return ret_122;
    }
    alg_hold_top = rh_1392;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName")), alg_literal(""))))) {
        if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_invoke(v_this, "DeclaresMember", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName")))), v_folded}, 2)), alg_literal(""))))) {
            Value ret_123 = alg_nil();
            alg_root_top = rt_base;
            return ret_123;
        }
    }
    alg_hold_top = rh_1392;
    (void)((v_count = alg_hold(alg_cast_kind(alg_property(alg_hold(alg_property(v_theexpr, "Arguments")), "Length"), ALG_KIND_INTEGER, "Integer"))));
    alg_hold_top = rh_1392;
    if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_invoke(v_this, "CandidatesFor", (Value[]){v_folded, v_count}, 2)), alg_int(0))))) {
        Value ret_124 = alg_nil();
        alg_root_top = rt_base;
        return ret_124;
    }
    alg_hold_top = rh_1392;
    (void)((v_key = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("arity:"), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Paren")), "LineNumber")))))), alg_char_value(58))), v_folded))));
    alg_hold_top = rh_1392;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Warned"), "Contains", (Value[]){v_key}, 1)))) {
        Value ret_125 = alg_nil();
        alg_root_top = rt_base;
        return ret_125;
    }
    alg_hold_top = rh_1392;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Warned"), "Add", (Value[]){v_key}, 1)));
    alg_hold_top = rh_1392;
    (void)(alg_hold(alg_invoke(alg_singleton(k_console), "Warn", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(alg_singleton(k_sourcecode), "Named", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Paren")), "File"))))}, 1)), alg_char_value(58))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Paren")), "LineNumber")))))), alg_literal(": '"))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name")), "Lexeme")))))), alg_literal("' is called with "))), alg_hold(alg_str(v_count)))), alg_literal(" argument(s), which no declaration of it takes.")))}, 1)));
    alg_hold_top = rh_1392;
    Value ret_126 = alg_nil();
    alg_root_top = rt_base;
    return ret_126;
}

static Value m_typechecker_warnifbitwisemeant_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_op = alg_widen(args[0], "Token");
    (void)v_op;
    alg_root(&v_op, 1);
    Value v_thetype = alg_widen(args[1], "String");
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    int32_t rh_1395 = alg_hold_top;
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_1395;
    if (alg_truthy(alg_hold(alg_not_equal(v_thetype, alg_literal("Integer"))))) {
        Value ret_127 = alg_nil();
        alg_root_top = rt_base;
        return ret_127;
    }
    alg_hold_top = rh_1395;
    (void)((v_key = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_str(alg_hold(alg_property(v_op, "LineNumber")))), alg_literal(":bits:"))), alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_op, "Lexeme"))))}, 1))))));
    alg_hold_top = rh_1395;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Warned"), "Contains", (Value[]){v_key}, 1)))) {
        Value ret_128 = alg_nil();
        alg_root_top = rt_base;
        return ret_128;
    }
    alg_hold_top = rh_1395;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Warned"), "Add", (Value[]){v_key}, 1)));
    alg_hold_top = rh_1395;
    (void)(alg_hold(alg_invoke(alg_singleton(k_console), "Warn", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(alg_singleton(k_sourcecode), "Named", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_op, "File"))))}, 1)), alg_char_value(58))), alg_hold(alg_str(alg_hold(alg_property(v_op, "LineNumber")))))), alg_literal(": an operand of '"))), alg_hold(alg_str(alg_hold(alg_property(v_op, "Lexeme")))))), alg_literal("' is an Integer, where '&', '|' and '~' "))), alg_literal("are the bitwise operators.")))}, 1)));
    alg_hold_top = rh_1395;
    Value ret_129 = alg_nil();
    alg_root_top = rt_base;
    return ret_129;
}

static Value m_typechecker_warnifshadowed_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = args[0];
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_owner = alg_widen(args[1], "String");
    (void)v_owner;
    alg_root(&v_owner, 1);
    int32_t rh_1396 = alg_hold_top;
    Value v_declaring = alg_nil();
    (void)v_declaring;
    alg_root(&v_declaring, 1);
    alg_hold_top = rh_1396;
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_1396;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "Extension")))), alg_literal(""))))) {
        Value ret_130 = alg_nil();
        alg_root_top = rt_base;
        return ret_130;
    }
    alg_hold_top = rh_1396;
    (void)((v_declaring = alg_hold(alg_invoke(v_this, "DeclaresMember", (Value[]){v_owner, alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 2))));
    alg_hold_top = rh_1396;
    if (alg_truthy(alg_hold(alg_equal(v_declaring, alg_literal(""))))) {
        Value ret_131 = alg_nil();
        alg_root_top = rt_base;
        return ret_131;
    }
    alg_hold_top = rh_1396;
    (void)((v_key = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "LineNumber")))), alg_literal(":member:"))), alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 1))))));
    alg_hold_top = rh_1396;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Warned"), "Contains", (Value[]){v_key}, 1)))) {
        Value ret_132 = alg_nil();
        alg_root_top = rt_base;
        return ret_132;
    }
    alg_hold_top = rh_1396;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Warned"), "Add", (Value[]){v_key}, 1)));
    alg_hold_top = rh_1396;
    (void)(alg_hold(alg_invoke(alg_singleton(k_console), "Warn", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(alg_singleton(k_sourcecode), "Named", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "File"))))}, 1)), alg_char_value(58))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "LineNumber")))))), alg_literal(": '"))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme")))))), alg_literal("' is a member of "))), v_declaring)), alg_literal(", so the extension of that name is not reached.")))}, 1)));
    alg_hold_top = rh_1396;
    Value ret_133 = alg_nil();
    alg_root_top = rt_base;
    return ret_133;
}

static Value m_typechecker_reduce_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = args[0];
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1397 = alg_hold_top;
    Value v_kind = alg_nil();
    (void)v_kind;
    alg_root(&v_kind, 1);
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_theexpr, alg_nil())))) {
        Value ret_134 = alg_literal("");
        alg_root_top = rt_base;
        return ret_134;
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_theexpr, "Cast")), alg_literal(""))))) {
        Value ret_135 = alg_hold(alg_property(v_theexpr, "Cast"));
        alg_root_top = rt_base;
        return ret_135;
    }
    alg_hold_top = rh_1397;
    (void)((v_kind = alg_hold(alg_invoke(v_this, "ClassNameOf", (Value[]){v_theexpr}, 1))));
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("LiteralExpr"))))) {
        Value ret_136 = alg_hold(alg_invoke(v_this, "TypeOfValue", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1));
        alg_root_top = rt_base;
        return ret_136;
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("GroupingExpr"))))) {
        Value ret_137 = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Expression"))}, 1));
        alg_root_top = rt_base;
        return ret_137;
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("VariableExpr"))))) {
        {
            int32_t rt_1398 = alg_root_top;
            int32_t rh_1399 = alg_hold_top;
            Value v_written = alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))}, 1));
            (void)v_written;
            alg_root(&v_written, 1);
            alg_hold_top = rh_1399;
            if (alg_truthy(alg_hold(alg_not_equal(v_written, alg_literal(""))))) {
                Value ret_138 = v_written;
                alg_root_top = rt_base;
                return ret_138;
            }
            alg_hold_top = rh_1399;
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName")), alg_literal(""))))) {
                {
                    int32_t rt_1400 = alg_root_top;
                    int32_t rh_1401 = alg_hold_top;
                    Value v_owner = alg_hold(alg_str(alg_hold(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"))));
                    (void)v_owner;
                    alg_root(&v_owner, 1);
                    alg_hold_top = rh_1401;
                    {
                        int32_t rh_1402 = alg_hold_top;
                        while ((alg_hold_top = rh_1402, alg_truthy(alg_hold(alg_not_equal(v_owner, alg_literal("")))))) {
                            alg_safe_point();
                            {
                                int32_t rt_1403 = alg_root_top;
                                int32_t rh_1404 = alg_hold_top;
                                Value v_asfield = alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_hold(alg_add(alg_hold(alg_add(v_owner, alg_literal("::"))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))))}, 1));
                                (void)v_asfield;
                                alg_root(&v_asfield, 1);
                                alg_hold_top = rh_1404;
                                if (alg_truthy(alg_hold(alg_not_equal(v_asfield, alg_literal(""))))) {
                                    Value ret_139 = v_asfield;
                                    alg_root_top = rt_base;
                                    return ret_139;
                                }
                                alg_hold_top = rh_1404;
                                if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Parents")), "Contains", (Value[]){v_owner}, 1)))))) {
                                    (void)((v_owner = alg_literal("")));
                                } else {
                                    (void)((v_owner = alg_hold(alg_str(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Parents")), "Get", (Value[]){v_owner}, 1))))));
                                }
                                alg_hold_top = rh_1404;
                                alg_root_top = rt_1403;
                            }
                        }
                    }
                    alg_hold_top = rh_1401;
                    alg_root_top = rt_1400;
                }
            }
            alg_hold_top = rh_1399;
            Value ret_140 = alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Inferred")), "GetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 1));
            alg_root_top = rt_base;
            return ret_140;
            alg_hold_top = rh_1399;
            alg_root_top = rt_1398;
        }
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("UnaryExpr"))))) {
        {
            int32_t rh_1405 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVnot)))) {
                {
                    int32_t rh_1406 = alg_hold_top;
                    (void)(alg_hold(alg_invoke(v_this, "WarnIfBitwiseMeant", (Value[]){alg_hold(alg_property(v_theexpr, "Op")), alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1))}, 2)));
                    alg_hold_top = rh_1406;
                    Value ret_141 = alg_literal("Boolean");
                    alg_root_top = rt_base;
                    return ret_141;
                    alg_hold_top = rh_1406;
                }
            }
            alg_hold_top = rh_1405;
            Value ret_142 = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1));
            alg_root_top = rt_base;
            return ret_142;
            alg_hold_top = rh_1405;
        }
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("IsExpr"))))) {
        {
            int32_t rh_1407 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)));
            alg_hold_top = rh_1407;
            if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes")), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "TypeName")), "Lexeme"))}, 1))}, 1))}, 1)))))) {
                {
                    int32_t rt_1408 = alg_root_top;
                    int32_t rh_1409 = alg_hold_top;
                    Value v_message = alg_hold(alg_add(alg_hold(alg_add(alg_literal("Unknown type '"), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "TypeName")), "Lexeme")))))), alg_literal("'.")));
                    (void)v_message;
                    alg_root(&v_message, 1);
                    alg_hold_top = rh_1409;
                    (void)(alg_hold(alg_invoke(alg_singleton(k_console), "Error", (Value[]){alg_hold(alg_property(v_theexpr, "TypeName")), v_message}, 2)));
                    alg_hold_top = rh_1409;
                    alg_raise(v_message);
                    alg_hold_top = rh_1409;
                    alg_root_top = rt_1408;
                }
            }
            alg_hold_top = rh_1407;
            Value ret_143 = alg_literal("Boolean");
            alg_root_top = rt_base;
            return ret_143;
            alg_hold_top = rh_1407;
        }
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("BinaryExpr"))))) {
        Value ret_144 = alg_hold(alg_invoke(v_this, "ReduceBinary", (Value[]){v_theexpr}, 1));
        alg_root_top = rt_base;
        return ret_144;
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("LogicalExpr"))))) {
        {
            int32_t rt_1410 = alg_root_top;
            int32_t rh_1411 = alg_hold_top;
            Value v_side = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Left"))}, 1));
            (void)v_side;
            alg_root(&v_side, 1);
            alg_hold_top = rh_1411;
            (void)(alg_hold(alg_invoke(v_this, "WarnIfBitwiseMeant", (Value[]){alg_hold(alg_property(v_theexpr, "Op")), v_side}, 2)));
            alg_hold_top = rh_1411;
            (void)(alg_hold(alg_invoke(v_this, "WarnIfBitwiseMeant", (Value[]){alg_hold(alg_property(v_theexpr, "Op")), alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1))}, 2)));
            alg_hold_top = rh_1411;
            Value ret_145 = v_side;
            alg_root_top = rt_base;
            return ret_145;
            alg_hold_top = rh_1411;
            alg_root_top = rt_1410;
        }
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("AssignExpr"))))) {
        {
            int32_t rt_1412 = alg_root_top;
            int32_t rh_1413 = alg_hold_top;
            Value v_declared = alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))}, 1));
            (void)v_declared;
            alg_root(&v_declared, 1);
            alg_hold_top = rh_1413;
            Value v_actual = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1));
            (void)v_actual;
            alg_root(&v_actual, 1);
            alg_hold_top = rh_1413;
            if (alg_truthy(alg_hold((or_26 = alg_hold(alg_not_equal(v_declared, alg_literal(""))), !alg_truthy(or_26) ? or_26 : alg_hold(alg_not_equal(v_declared, alg_literal("Any"))))))) {
                if (alg_truthy(alg_hold((or_28 = alg_hold((or_27 = alg_hold(alg_equal(v_actual, alg_literal(""))), alg_truthy(or_27) ? or_27 : alg_hold(alg_equal(v_actual, alg_literal("Any"))))), alg_truthy(or_28) ? or_28 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Assignable", (Value[]){v_declared, v_actual}, 2)))))))) {
                    alg_raise(alg_hold(alg_invoke(v_this, "Mismatch", (Value[]){alg_hold(alg_property(v_theexpr, "Name")), v_declared, v_actual}, 3)));
                }
            }
            alg_hold_top = rh_1413;
            (void)(alg_hold(alg_set_property(v_theexpr, "Declared", v_declared)));
            alg_hold_top = rh_1413;
            (void)(alg_hold(alg_set_property(v_theexpr, "Actual", v_actual)));
            alg_hold_top = rh_1413;
            Value ret_146 = v_declared;
            alg_root_top = rt_base;
            return ret_146;
            alg_hold_top = rh_1413;
            alg_root_top = rt_1412;
        }
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("CallExpr"))))) {
        {
            int32_t rt_1414 = alg_root_top;
            int32_t rh_1415 = alg_hold_top;
            Value v_argtypes = alg_hold(alg_list());
            (void)v_argtypes;
            alg_root(&v_argtypes, 1);
            alg_hold_top = rh_1415;
            {
                int32_t rt_1416 = alg_root_top;
                Value loop_147 = alg_iterable(alg_hold(alg_property(v_theexpr, "Arguments")));
                (void)loop_147;
                alg_root(&loop_147, 1);
                for (int32_t at_147 = 0; at_147 < alg_iterable_count(loop_147); at_147++) {
                    alg_safe_point();
                    int32_t rt_1417 = alg_root_top;
                    Value v_argument = alg_iterable_at(loop_147, at_147);
                    (void)v_argument;
                    alg_root(&v_argument, 1);
                    (void)(alg_hold(alg_invoke(v_argtypes, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Reduce", (Value[]){v_argument}, 1))}, 1)));
                    alg_root_top = rt_1417;
                }
                alg_root_top = rt_1416;
            }
            alg_hold_top = rh_1415;
            (void)(alg_hold(alg_invoke(v_this, "WarnIfDynamic", (Value[]){v_theexpr}, 1)));
            alg_hold_top = rh_1415;
            (void)(alg_hold(alg_invoke(v_this, "WarnIfNoArity", (Value[]){v_theexpr}, 1)));
            alg_hold_top = rh_1415;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_hold(alg_property(v_theexpr, "Callee"))}, 1)), alg_literal("GetExpr"))))) {
                {
                    int32_t rt_1418 = alg_root_top;
                    int32_t rh_1419 = alg_hold_top;
                    Value v_at = alg_hold(alg_invoke(v_this, "InsertedAt", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name")), "Lexeme"))))}, 1));
                    (void)v_at;
                    alg_root(&v_at, 1);
                    alg_hold_top = rh_1419;
                    if (alg_truthy(alg_hold((or_29 = alg_hold(alg_greater_equal(v_at, alg_int(0))), !alg_truthy(or_29) ? or_29 : alg_hold(alg_less(v_at, alg_hold(alg_property(v_argtypes, "Length")))))))) {
                        (void)(alg_hold(alg_invoke(v_this, "CheckElement", (Value[]){alg_hold(alg_invoke(v_this, "ElementOf", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Obj"))}, 1)), alg_hold(alg_str(alg_hold(alg_subscript_get(v_argtypes, v_at)))), alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name"))}, 3)));
                    }
                    alg_hold_top = rh_1419;
                    alg_root_top = rt_1418;
                }
            }
            alg_hold_top = rh_1415;
            Value ret_148 = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Callee"))}, 1));
            alg_root_top = rt_base;
            return ret_148;
            alg_hold_top = rh_1415;
            alg_root_top = rt_1414;
        }
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("GetExpr"))))) {
        {
            int32_t rt_1420 = alg_root_top;
            int32_t rh_1421 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_theexpr, "Unit")), alg_literal("System"))))) {
                {
                    int32_t rh_1422 = alg_hold_top;
                    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 1)))) {
                        Value ret_149 = alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Get", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 1))));
                        alg_root_top = rt_base;
                        return ret_149;
                    }
                    alg_hold_top = rh_1422;
                    Value ret_150 = alg_literal("");
                    alg_root_top = rt_base;
                    return ret_150;
                    alg_hold_top = rh_1422;
                }
            }
            alg_hold_top = rh_1421;
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_theexpr, "Unit")), alg_literal(""))))) {
                Value ret_151 = alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 1));
                alg_root_top = rt_base;
                return ret_151;
            }
            alg_hold_top = rh_1421;
            (void)(alg_hold(alg_invoke(v_this, "CheckVisibility", (Value[]){alg_hold(alg_property(v_theexpr, "Obj")), alg_hold(alg_property(v_theexpr, "Name"))}, 2)));
            alg_hold_top = rh_1421;
            Value v_owner = alg_hold(alg_invoke(v_this, "TypeOfReceiver", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1));
            (void)v_owner;
            alg_root(&v_owner, 1);
            alg_hold_top = rh_1421;
            if (alg_truthy(alg_hold((or_30 = alg_hold(alg_equal(v_owner, alg_literal(""))), alg_truthy(or_30) ? or_30 : alg_hold(alg_equal(v_owner, alg_literal("Any"))))))) {
                Value ret_152 = alg_literal("");
                alg_root_top = rt_base;
                return ret_152;
            }
            alg_hold_top = rh_1421;
            (void)(alg_hold(alg_invoke(v_this, "WarnIfShadowed", (Value[]){v_theexpr, v_owner}, 2)));
            alg_hold_top = rh_1421;
            Value ret_153 = alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_hold(alg_add(alg_hold(alg_add(v_owner, alg_literal("::"))), alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 1));
            alg_root_top = rt_base;
            return ret_153;
            alg_hold_top = rh_1421;
            alg_root_top = rt_1420;
        }
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("SetExpr"))))) {
        {
            int32_t rt_1423 = alg_root_top;
            int32_t rh_1424 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_theexpr, "Unit")), alg_literal(""))))) {
                Value ret_154 = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1));
                alg_root_top = rt_base;
                return ret_154;
            }
            alg_hold_top = rh_1424;
            (void)(alg_hold(alg_invoke(v_this, "CheckVisibility", (Value[]){alg_hold(alg_property(v_theexpr, "Obj")), alg_hold(alg_property(v_theexpr, "Name"))}, 2)));
            alg_hold_top = rh_1424;
            Value v_owner = alg_hold(alg_invoke(v_this, "TypeOfReceiver", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1));
            (void)v_owner;
            alg_root(&v_owner, 1);
            alg_hold_top = rh_1424;
            Value v_actual = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1));
            (void)v_actual;
            alg_root(&v_actual, 1);
            alg_hold_top = rh_1424;
            if (alg_truthy(alg_hold((or_31 = alg_hold(alg_equal(v_owner, alg_literal(""))), !alg_truthy(or_31) ? or_31 : alg_is(alg_hold(alg_property(v_theexpr, "Obj")), "ThisExpr"))))) {
                (void)((v_owner = alg_hold(alg_str(alg_hold(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"))))));
            }
            alg_hold_top = rh_1424;
            if (alg_truthy(alg_hold((or_32 = alg_hold(alg_not_equal(v_owner, alg_literal(""))), !alg_truthy(or_32) ? or_32 : alg_hold(alg_not_equal(v_owner, alg_literal("Any"))))))) {
                {
                    int32_t rt_1425 = alg_root_top;
                    int32_t rh_1426 = alg_hold_top;
                    Value v_declaring = alg_hold(alg_invoke(v_this, "DeclaresProperty", (Value[]){v_owner, alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 2));
                    (void)v_declaring;
                    alg_root(&v_declaring, 1);
                    alg_hold_top = rh_1426;
                    if (alg_truthy(alg_hold(alg_not_equal(v_declaring, alg_literal(""))))) {
                        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme")))))), alg_literal("' is a property of "))), v_declaring)), alg_literal(" and cannot be assigned."))));
                    }
                    alg_hold_top = rh_1426;
                    Value v_declared = alg_hold(alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_hold(alg_add(alg_hold(alg_add(v_owner, alg_literal("::"))), alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 1));
                    (void)v_declared;
                    alg_root(&v_declared, 1);
                    alg_hold_top = rh_1426;
                    if (alg_truthy(alg_hold((or_34 = alg_hold((or_33 = alg_hold(alg_not_equal(v_declared, alg_literal(""))), !alg_truthy(or_33) ? or_33 : alg_hold(alg_not_equal(v_declared, alg_literal("Any"))))), !alg_truthy(or_34) ? or_34 : alg_hold(alg_not_equal(v_actual, alg_literal(""))))))) {
                        if (alg_truthy(alg_hold((or_35 = alg_hold(alg_equal(v_actual, alg_literal("Any"))), alg_truthy(or_35) ? or_35 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Assignable", (Value[]){v_declared, v_actual}, 2)))))))) {
                            alg_raise(alg_hold(alg_invoke(v_this, "Mismatch", (Value[]){alg_hold(alg_property(v_theexpr, "Name")), v_declared, v_actual}, 3)));
                        }
                    }
                    alg_hold_top = rh_1426;
                    (void)(alg_hold(alg_set_property(v_theexpr, "Declared", v_declared)));
                    alg_hold_top = rh_1426;
                    (void)(alg_hold(alg_set_property(v_theexpr, "Actual", v_actual)));
                    alg_hold_top = rh_1426;
                    alg_root_top = rt_1425;
                }
            }
            alg_hold_top = rh_1424;
            Value ret_155 = v_actual;
            alg_root_top = rt_base;
            return ret_155;
            alg_hold_top = rh_1424;
            alg_root_top = rt_1423;
        }
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("ThisExpr"))))) {
        Value ret_156 = alg_literal("");
        alg_root_top = rt_base;
        return ret_156;
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("CollectionExpr"))))) {
        {
            int32_t rh_1427 = alg_hold_top;
            {
                int32_t rt_1428 = alg_root_top;
                Value loop_157 = alg_iterable(alg_hold(alg_property(v_theexpr, "Values")));
                (void)loop_157;
                alg_root(&loop_157, 1);
                for (int32_t at_157 = 0; at_157 < alg_iterable_count(loop_157); at_157++) {
                    alg_safe_point();
                    int32_t rt_1429 = alg_root_top;
                    Value v_thevalue = alg_iterable_at(loop_157, at_157);
                    (void)v_thevalue;
                    alg_root(&v_thevalue, 1);
                    (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){v_thevalue}, 1)));
                    alg_root_top = rt_1429;
                }
                alg_root_top = rt_1428;
            }
            alg_hold_top = rh_1427;
            if (alg_truthy(alg_hold(alg_property(v_theexpr, "IsMap")))) {
                Value ret_158 = alg_literal("Map");
                alg_root_top = rt_base;
                return ret_158;
            }
            alg_hold_top = rh_1427;
            Value ret_159 = alg_literal("List");
            alg_root_top = rt_base;
            return ret_159;
            alg_hold_top = rh_1427;
        }
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("SubscriptExpr"))))) {
        {
            int32_t rt_1430 = alg_root_top;
            int32_t rh_1431 = alg_hold_top;
            Value v_owner = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1));
            (void)v_owner;
            alg_root(&v_owner, 1);
            alg_hold_top = rh_1431;
            (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Index"))}, 1)));
            alg_hold_top = rh_1431;
            if (alg_truthy(alg_hold(alg_invoke(v_this, "IsTextType", (Value[]){v_owner}, 1)))) {
                Value ret_160 = alg_literal("Char");
                alg_root_top = rt_base;
                return ret_160;
            }
            alg_hold_top = rh_1431;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)), alg_literal("VariableExpr"))))) {
                Value ret_161 = alg_hold(alg_invoke(alg_hold(alg_property(alg_property(v_this, "Lookup"), "Generics")), "GetType", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Obj")), "Name")), "Lexeme"))))}, 1));
                alg_root_top = rt_base;
                return ret_161;
            }
            alg_hold_top = rh_1431;
            Value ret_162 = alg_literal("");
            alg_root_top = rt_base;
            return ret_162;
            alg_hold_top = rh_1431;
            alg_root_top = rt_1430;
        }
    }
    alg_hold_top = rh_1397;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("SetSubscriptExpr"))))) {
        {
            int32_t rt_1432 = alg_root_top;
            int32_t rh_1433 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)));
            alg_hold_top = rh_1433;
            (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Index"))}, 1)));
            alg_hold_top = rh_1433;
            Value v_stored = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1));
            (void)v_stored;
            alg_root(&v_stored, 1);
            alg_hold_top = rh_1433;
            (void)(alg_hold(alg_invoke(v_this, "CheckElement", (Value[]){alg_hold(alg_invoke(v_this, "ElementOf", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)), v_stored, alg_hold(alg_property(v_theexpr, "Bracket"))}, 3)));
            alg_hold_top = rh_1433;
            Value ret_163 = v_stored;
            alg_root_top = rt_base;
            return ret_163;
            alg_hold_top = rh_1433;
            alg_root_top = rt_1432;
        }
    }
    alg_hold_top = rh_1397;
    Value ret_164 = alg_literal("");
    alg_root_top = rt_base;
    return ret_164;
    alg_hold_top = rh_1397;
    Value ret_165 = alg_nil();
    alg_root_top = rt_base;
    return ret_165;
}

static Value m_typechecker_reducebinary_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = args[0];
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1434 = alg_hold_top;
    Value v_left = alg_nil();
    (void)v_left;
    alg_root(&v_left, 1);
    alg_hold_top = rh_1434;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_1434;
    Value v_op = alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken"));
    (void)v_op;
    alg_root(&v_op, 1);
    alg_hold_top = rh_1434;
    if (alg_truthy(alg_hold((or_40 = alg_hold((or_39 = alg_hold((or_38 = alg_hold((or_37 = alg_hold((or_36 = alg_hold(alg_equal(v_op, e_tokentype_tokenVgreater)), alg_truthy(or_36) ? or_36 : alg_hold(alg_equal(v_op, e_tokentype_tokenVgreaterVequal)))), alg_truthy(or_37) ? or_37 : alg_hold(alg_equal(v_op, e_tokentype_tokenVless)))), alg_truthy(or_38) ? or_38 : alg_hold(alg_equal(v_op, e_tokentype_tokenVlessVequal)))), alg_truthy(or_39) ? or_39 : alg_hold(alg_equal(v_op, e_tokentype_tokenVequal)))), alg_truthy(or_40) ? or_40 : alg_hold(alg_equal(v_op, e_tokentype_tokenVnotVequal)))))) {
        {
            int32_t rh_1435 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Left"))}, 1)));
            alg_hold_top = rh_1435;
            (void)(alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1)));
            alg_hold_top = rh_1435;
            Value ret_166 = alg_literal("Boolean");
            alg_root_top = rt_base;
            return ret_166;
            alg_hold_top = rh_1435;
        }
    }
    alg_hold_top = rh_1434;
    (void)((v_left = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Left"))}, 1))));
    alg_hold_top = rh_1434;
    (void)((v_right = alg_hold(alg_invoke(v_this, "Reduce", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1))));
    alg_hold_top = rh_1434;
    if (alg_truthy(alg_hold((or_43 = alg_hold((or_42 = alg_hold((or_41 = alg_hold(alg_equal(v_left, alg_literal(""))), alg_truthy(or_41) ? or_41 : alg_hold(alg_equal(v_right, alg_literal(""))))), alg_truthy(or_42) ? or_42 : alg_hold(alg_equal(v_left, alg_literal("Any"))))), alg_truthy(or_43) ? or_43 : alg_hold(alg_equal(v_right, alg_literal("Any"))))))) {
        Value ret_167 = alg_literal("");
        alg_root_top = rt_base;
        return ret_167;
    }
    alg_hold_top = rh_1434;
    if (alg_truthy(alg_hold(alg_equal(v_op, e_tokentype_tokenVin)))) {
        Value ret_168 = alg_literal("Boolean");
        alg_root_top = rt_base;
        return ret_168;
    }
    alg_hold_top = rh_1434;
    if (alg_truthy(alg_hold((or_45 = alg_hold(alg_equal(v_op, e_tokentype_tokenVplus)), !alg_truthy(or_45) ? or_45 : (alg_hold((or_44 = alg_hold(alg_invoke(v_this, "IsTextType", (Value[]){v_left}, 1)), alg_truthy(or_44) ? or_44 : alg_hold(alg_invoke(v_this, "IsTextType", (Value[]){v_right}, 1))))))))) {
        Value ret_169 = alg_literal("String");
        alg_root_top = rt_base;
        return ret_169;
    }
    alg_hold_top = rh_1434;
    if (alg_truthy(alg_hold(alg_equal(v_op, e_tokentype_tokenVslash)))) {
        Value ret_170 = alg_literal("Double");
        alg_root_top = rt_base;
        return ret_170;
    }
    alg_hold_top = rh_1434;
    if (alg_truthy(alg_hold((or_46 = alg_hold(alg_equal(v_op, e_tokentype_tokenVdiv)), alg_truthy(or_46) ? or_46 : alg_hold(alg_equal(v_op, e_tokentype_tokenVmod)))))) {
        Value ret_171 = alg_literal("Integer");
        alg_root_top = rt_base;
        return ret_171;
    }
    alg_hold_top = rh_1434;
    if (alg_truthy(alg_hold((or_47 = alg_hold(alg_equal(v_left, alg_literal("Double"))), alg_truthy(or_47) ? or_47 : alg_hold(alg_equal(v_right, alg_literal("Double"))))))) {
        Value ret_172 = alg_literal("Double");
        alg_root_top = rt_base;
        return ret_172;
    }
    alg_hold_top = rh_1434;
    if (alg_truthy(alg_hold(alg_equal(v_left, v_right)))) {
        Value ret_173 = v_left;
        alg_root_top = rt_base;
        return ret_173;
    }
    alg_hold_top = rh_1434;
    Value ret_174 = alg_literal("");
    alg_root_top = rt_base;
    return ret_174;
    alg_hold_top = rh_1434;
    Value ret_175 = alg_nil();
    alg_root_top = rt_base;
    return ret_175;
}

static Value m_typechecker_istexttype_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thetype = alg_widen(args[0], "String");
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    int32_t rh_1436 = alg_hold_top;
    Value ret_176 = alg_hold((or_48 = alg_hold(alg_equal(v_thetype, alg_literal("String"))), alg_truthy(or_48) ? or_48 : alg_hold(alg_equal(v_thetype, alg_literal("Char")))));
    alg_root_top = rt_base;
    return ret_176;
    alg_hold_top = rh_1436;
    Value ret_177 = alg_nil();
    alg_root_top = rt_base;
    return ret_177;
}

static Value m_typechecker_typeofvalue_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_value = args[0];
    (void)v_value;
    alg_root(&v_value, 1);
    int32_t rh_1437 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(v_value, alg_nil())))) {
        Value ret_178 = alg_literal("Nil");
        alg_root_top = rt_base;
        return ret_178;
    }
    alg_hold_top = rh_1437;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_BOOLEAN))) {
        Value ret_179 = alg_literal("Boolean");
        alg_root_top = rt_base;
        return ret_179;
    }
    alg_hold_top = rh_1437;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_INTEGER))) {
        Value ret_180 = alg_literal("Integer");
        alg_root_top = rt_base;
        return ret_180;
    }
    alg_hold_top = rh_1437;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_DOUBLE))) {
        Value ret_181 = alg_literal("Double");
        alg_root_top = rt_base;
        return ret_181;
    }
    alg_hold_top = rh_1437;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_CHAR))) {
        Value ret_182 = alg_literal("Char");
        alg_root_top = rt_base;
        return ret_182;
    }
    alg_hold_top = rh_1437;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_STRING))) {
        Value ret_183 = alg_literal("String");
        alg_root_top = rt_base;
        return ret_183;
    }
    alg_hold_top = rh_1437;
    Value ret_184 = alg_hold(alg_invoke(v_this, "ClassNameOf", (Value[]){v_value}, 1));
    alg_root_top = rt_base;
    return ret_184;
    alg_hold_top = rh_1437;
    Value ret_185 = alg_nil();
    alg_root_top = rt_base;
    return ret_185;
}

static Value m_typechecker_classnameof_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    volatile Value v_obj = args[0];
    (void)v_obj;
    alg_root(&v_obj, 1);
    int32_t rh_1438 = alg_hold_top;
    {
        AlgFrame frame_186;
        alg_push_frame(&frame_186);
        if (ALG_SETJMP(frame_186.jump) == 0) {
            {
                int32_t rh_1439 = alg_hold_top;
                volatile Value ret_187 = alg_hold(alg_property(v_obj, "ClassName"));
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_187;
                alg_hold_top = rh_1439;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_186[] = {"String"};
            int32_t which_186 = alg_handler(frame_186.raised, names_186, 1);
            if (which_186 == 0) {
                {
                    int32_t rt_1440 = alg_root_top;
                    volatile Value v_e = frame_186.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_188 = alg_literal("");
                    alg_root_top = rt_base;
                    return ret_188;
                    alg_root_top = rt_1440;
                }
            }
            else {
                alg_raise(frame_186.raised);
            }
        }
    }
    alg_hold_top = rh_1438;
    volatile Value ret_189 = alg_nil();
    alg_root_top = rt_base;
    return ret_189;
}

Value f_rejects(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    volatile Value v_source = alg_param(args[0], "String");
    (void)v_source;
    alg_root(&v_source, 1);
    int32_t rh_1441 = alg_hold_top;
    volatile Value v_thescanner = alg_hold(alg_new(k_scanner, (Value[]){v_source}, 1));
    (void)v_thescanner;
    alg_root(&v_thescanner, 1);
    alg_hold_top = rh_1441;
    volatile Value v_theparser = alg_hold(alg_new(k_parser, (Value[]){alg_hold(alg_invoke(v_thescanner, "ScanTokens", NULL, 0))}, 1));
    (void)v_theparser;
    alg_root(&v_theparser, 1);
    alg_hold_top = rh_1441;
    {
        AlgFrame frame_190;
        alg_push_frame(&frame_190);
        if (ALG_SETJMP(frame_190.jump) == 0) {
            {
                int32_t rh_1442 = alg_hold_top;
                (void)(alg_hold(alg_invoke(alg_hold(alg_new(k_typechecker, NULL, 0)), "Resolve", (Value[]){alg_hold(alg_invoke(v_theparser, "Parse", NULL, 0))}, 1)));
                alg_hold_top = rh_1442;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_190[] = {"String"};
            int32_t which_190 = alg_handler(frame_190.raised, names_190, 1);
            if (which_190 == 0) {
                {
                    int32_t rt_1443 = alg_root_top;
                    volatile Value v_e = frame_190.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_191 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_191;
                    alg_root_top = rt_1443;
                }
            }
            else {
                alg_raise(frame_190.raised);
            }
        }
    }
    alg_hold_top = rh_1441;
    volatile Value ret_192 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_192;
    alg_hold_top = rh_1441;
    volatile Value ret_193 = alg_nil();
    alg_root_top = rt_base;
    return ret_193;
}

Value f_candidates(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 3);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_source = alg_param(args[0], "String");
    (void)v_source;
    alg_root(&v_source, 1);
    Value v_name = alg_param(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_count = alg_param(args[2], "Integer");
    (void)v_count;
    alg_root(&v_count, 1);
    int32_t rh_1444 = alg_hold_top;
    Value v_thescanner = alg_hold(alg_new(k_scanner, (Value[]){v_source}, 1));
    (void)v_thescanner;
    alg_root(&v_thescanner, 1);
    alg_hold_top = rh_1444;
    Value v_theparser = alg_hold(alg_new(k_parser, (Value[]){alg_hold(alg_invoke(v_thescanner, "ScanTokens", NULL, 0))}, 1));
    (void)v_theparser;
    alg_root(&v_theparser, 1);
    alg_hold_top = rh_1444;
    Value v_thechecker = alg_hold(alg_new(k_typechecker, NULL, 0));
    (void)v_thechecker;
    alg_root(&v_thechecker, 1);
    alg_hold_top = rh_1444;
    (void)(alg_hold(alg_invoke(v_thechecker, "Resolve", (Value[]){alg_hold(alg_invoke(v_theparser, "Parse", NULL, 0))}, 1)));
    alg_hold_top = rh_1444;
    Value ret_194 = alg_hold(alg_invoke(v_thechecker, "CandidatesFor", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1)), v_count}, 2));
    alg_root_top = rt_base;
    return ret_194;
    alg_hold_top = rh_1444;
    Value ret_195 = alg_nil();
    alg_root_top = rt_base;
    return ret_195;
}

static Value *roots_TypeChecker[] = {
    &k_typelookup,
    &fn_foldedbuiltins,
    &v_builtinVnames,
    &k_typechecker,
    &fn_rejects,
    &fn_candidates,
    &v_hider,
};

void init_TypeChecker(void) {
    alg_roots(roots_TypeChecker, 7);
    k_typelookup = alg_class("TypeLookup", alg_nil());
    k_typechecker = alg_class("TypeChecker", alg_nil());
    alg_class_field(k_typelookup, "Scopes", "List");
    alg_class_field(k_typelookup, "Types", "Map");
    alg_class_field(k_typelookup, "Parents", "Map");
    alg_class_field(k_typelookup, "Inferred", "TypeLookup");
    alg_class_field(k_typelookup, "DeclaredTypes", "Set");
    alg_class_field(k_typelookup, "Generics", "TypeLookup");
    alg_class_field(k_typelookup, "CurrentClassName", "String");
    alg_class_initializer(k_typelookup, i_typelookup);
    alg_class_method(k_typelookup, "SetType", m_typelookup_settype_2_string_string, 2, t_typelookup_settype_2_string_string);
    alg_class_method(k_typelookup, "GetType", m_typelookup_gettype_1_string, 1, t_typelookup_gettype_1_string);
    alg_class_method(k_typelookup, "BeginScope", m_typelookup_beginscope_0, 0, NULL);
    alg_class_method(k_typelookup, "EndScope", m_typelookup_endscope_0, 0, NULL);
    fn_foldedbuiltins = alg_closure("FoldedBuiltins", f_foldedbuiltins, NULL, 0, 0, NULL);
    alg_class_field(k_typechecker, "Lookup", "TypeLookup");
    alg_class_field(k_typechecker, "CurrentReturn", "String");
    alg_class_field(k_typechecker, "PrivateMembers", "Map");
    alg_class_field(k_typechecker, "PropertyMembers", "Map");
    alg_class_field(k_typechecker, "Members", "Map");
    alg_class_field(k_typechecker, "BuiltinTypes", "Map");
    alg_class_field(k_typechecker, "Overloads", "Map");
    alg_class_field(k_typechecker, "Arities", "Map");
    alg_class_field(k_typechecker, "Variadics", "Map");
    alg_class_field(k_typechecker, "Signatures", "Set");
    alg_class_field(k_typechecker, "Warned", "Set");
    alg_class_initializer(k_typechecker, i_typechecker);
    alg_class_method(k_typechecker, "Init", m_typechecker_init_0, 0, NULL);
    alg_class_method(k_typechecker, "HiddenBy", m_typechecker_hiddenby_2_string_string, 2, t_typechecker_hiddenby_2_string_string);
    alg_class_method(k_typechecker, "TypeOfReceiver", m_typechecker_typeofreceiver_1, 1, t_typechecker_typeofreceiver_1);
    alg_class_method(k_typechecker, "PropertiesOf", m_typechecker_propertiesof_1, 1, t_typechecker_propertiesof_1);
    alg_class_method(k_typechecker, "MembersOf", m_typechecker_membersof_1, 1, t_typechecker_membersof_1);
    alg_class_method(k_typechecker, "DeclaresMember", m_typechecker_declaresmember_2_string_string, 2, t_typechecker_declaresmember_2_string_string);
    alg_class_method(k_typechecker, "DeclaresProperty", m_typechecker_declaresproperty_2_string_string, 2, t_typechecker_declaresproperty_2_string_string);
    alg_class_method(k_typechecker, "ElementOf", m_typechecker_elementof_1, 1, t_typechecker_elementof_1);
    alg_class_method(k_typechecker, "CheckElement", m_typechecker_checkelement_3_string_string_token, 3, t_typechecker_checkelement_3_string_string_token);
    alg_class_method(k_typechecker, "InsertedAt", m_typechecker_insertedat_1_string, 1, t_typechecker_insertedat_1_string);
    alg_class_method(k_typechecker, "CheckLiteral", m_typechecker_checkliteral_3_string_token, 3, t_typechecker_checkliteral_3_string_token);
    alg_class_method(k_typechecker, "CheckVisibility", m_typechecker_checkvisibility_2_token, 2, t_typechecker_checkvisibility_2_token);
    alg_class_method(k_typechecker, "Assignable", m_typechecker_assignable_2_string_string, 2, t_typechecker_assignable_2_string_string);
    alg_class_method(k_typechecker, "Mismatch", m_typechecker_mismatch_3_token_string_string, 3, t_typechecker_mismatch_3_token_string_string);
    alg_class_method(k_typechecker, "Resolve", m_typechecker_resolve_1_list, 1, t_typechecker_resolve_1_list);
    alg_class_method(k_typechecker, "MapType", m_typechecker_maptype_1, 1, t_typechecker_maptype_1);
    alg_class_method(k_typechecker, "Check", m_typechecker_check_1, 1, t_typechecker_check_1);
    alg_class_method(k_typechecker, "CheckFunction", m_typechecker_checkfunction_1, 1, t_typechecker_checkfunction_1);
    alg_class_method(k_typechecker, "RecordArity", m_typechecker_recordarity_2_string, 2, t_typechecker_recordarity_2_string);
    alg_class_method(k_typechecker, "CandidatesFor", m_typechecker_candidatesfor_2_string_integer, 2, t_typechecker_candidatesfor_2_string_integer);
    alg_class_method(k_typechecker, "WarnIfDynamic", m_typechecker_warnifdynamic_1, 1, t_typechecker_warnifdynamic_1);
    alg_class_method(k_typechecker, "WarnIfNoArity", m_typechecker_warnifnoarity_1, 1, t_typechecker_warnifnoarity_1);
    alg_class_method(k_typechecker, "WarnIfBitwiseMeant", m_typechecker_warnifbitwisemeant_2_token_string, 2, t_typechecker_warnifbitwisemeant_2_token_string);
    alg_class_method(k_typechecker, "WarnIfShadowed", m_typechecker_warnifshadowed_2_string, 2, t_typechecker_warnifshadowed_2_string);
    alg_class_method(k_typechecker, "Reduce", m_typechecker_reduce_1, 1, t_typechecker_reduce_1);
    alg_class_method(k_typechecker, "ReduceBinary", m_typechecker_reducebinary_1, 1, t_typechecker_reducebinary_1);
    alg_class_method(k_typechecker, "IsTextType", m_typechecker_istexttype_1_string, 1, t_typechecker_istexttype_1_string);
    alg_class_method(k_typechecker, "TypeOfValue", m_typechecker_typeofvalue_1, 1, t_typechecker_typeofvalue_1);
    alg_class_method(k_typechecker, "ClassNameOf", m_typechecker_classnameof_1, 1, t_typechecker_classnameof_1);
    fn_rejects = alg_closure("Rejects", f_rejects, NULL, 0, 1, t_f_rejects);
    fn_candidates = alg_closure("Candidates", f_candidates, NULL, 0, 3, t_f_candidates);
    int32_t rh_1242 = alg_hold_top;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    v_builtinVnames = alg_hold(f_foldedbuiltins(NULL, NULL, 0));
    d_builtinVnames = true;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    v_hider = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("class Counter;"), alg_char_value(10))), alg_literal("private:"))), alg_char_value(10))), alg_literal("    var Count : Integer := 0;"))), alg_char_value(10))), alg_literal("begin"))), alg_char_value(10))), alg_literal("    procedure Bump();"))), alg_char_value(10))), alg_literal("    begin"))), alg_char_value(10))), alg_literal("        Count := Count + 1;"))), alg_char_value(10))), alg_literal("    end"))), alg_char_value(10))), alg_literal("private:"))), alg_char_value(10))), alg_literal("    procedure Advance();"))), alg_char_value(10))), alg_literal("    begin"))), alg_char_value(10))), alg_literal("    end"))), alg_char_value(10))), alg_literal("end"))), alg_char_value(10)));
    d_hider = true;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
    alg_hold_top = rh_1242;
}
