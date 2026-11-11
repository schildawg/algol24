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
    alg_set_property(v_this, "Scopes", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "Types", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "Parents", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "Inferred", alg_widen(alg_nil(), "TypeLookup"));
    alg_set_property(v_this, "DeclaredTypes", alg_widen(alg_set(), "Set"));
    alg_set_property(v_this, "Generics", alg_widen(alg_nil(), "TypeLookup"));
    alg_set_property(v_this, "CurrentClassName", alg_widen(alg_string(""), "String"));
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
    if (alg_truthy(alg_property(alg_property(v_this, "Scopes"), "IsEmpty"))) {
        (void)(alg_invoke(alg_property(v_this, "Types"), "Put", (Value[]){v_symbol, v_thetype}, 2));
    } else {
        (void)(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1))), "Put", (Value[]){v_symbol, v_thetype}, 2));
    }
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
    {
        int32_t rt_292 = alg_root_top;
        Value v_i = alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1));
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_greater_equal(v_i, alg_int(0))); (v_i = alg_subtract(v_i, alg_int(1)))) {
            alg_safe_point();
            if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), v_i), "Contains", (Value[]){v_symbol}, 1))) {
                Value ret_1 = alg_str(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), v_i), "Get", (Value[]){v_symbol}, 1));
                alg_root_top = rt_base;
                return ret_1;
            }
        }
        alg_root_top = rt_292;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Types"), "Contains", (Value[]){v_symbol}, 1))) {
        Value ret_2 = alg_str(alg_invoke(alg_property(v_this, "Types"), "Get", (Value[]){v_symbol}, 1));
        alg_root_top = rt_base;
        return ret_2;
    }
    Value ret_3 = alg_string("");
    alg_root_top = rt_base;
    return ret_3;
    Value ret_4 = alg_nil();
    alg_root_top = rt_base;
    return ret_4;
}

static Value m_typelookup_beginscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_invoke(alg_property(v_this, "Scopes"), "Add", (Value[]){alg_map()}, 1));
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Generics"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Generics"), "BeginScope", NULL, 0));
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Inferred"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Inferred"), "BeginScope", NULL, 0));
    }
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

static Value m_typelookup_endscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_invoke(alg_property(v_this, "Scopes"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1))}, 1));
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Generics"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Generics"), "EndScope", NULL, 0));
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Inferred"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Inferred"), "EndScope", NULL, 0));
    }
    Value ret_6 = alg_nil();
    alg_root_top = rt_base;
    return ret_6;
}

Value f_foldedbuiltins(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    (void)((v_names = alg_set()));
    {
        int32_t rt_293 = alg_root_top;
        Value loop_7 = alg_iterable(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_string("Array")), alg_string("AssertEqual")), alg_string("AssertTrue")), alg_string("Buffer")), alg_string("ChDir")), alg_string("Char")), alg_string("clock")), alg_string("Collect")), alg_string("Copy")), alg_string("ErrorLn")), alg_string("Fail")), alg_string("FileExists")), alg_string("Foreign")), alg_string("GetDir")), alg_string("Halt")), alg_string("Length")), alg_string("List")), alg_string("Map")), alg_string("MkDir")), alg_string("Ord")), alg_string("ParamCount")), alg_string("ParamStr")), alg_string("Pos")), alg_string("Pred")), alg_string("RmDir")), alg_string("Set")), alg_string("Stack")), alg_string("Str")), alg_string("Succ")), alg_string("TextFile")), alg_string("ToLower")), alg_string("ToUpper")), alg_string("Val")), alg_string("Write")), alg_string("WriteLn")));
        (void)loop_7;
        alg_root(&loop_7, 1);
        for (int32_t at_7 = 0; at_7 < alg_iterable_count(loop_7); at_7++) {
            alg_safe_point();
            int32_t rt_294 = alg_root_top;
            Value v_name = alg_iterable_at(loop_7, at_7);
            (void)v_name;
            alg_root(&v_name, 1);
            (void)(alg_invoke(v_names, "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_str(v_name)}, 1)}, 1));
            alg_root_top = rt_294;
        }
        alg_root_top = rt_293;
    }
    Value ret_8 = v_names;
    alg_root_top = rt_base;
    return ret_8;
    Value ret_9 = alg_nil();
    alg_root_top = rt_base;
    return ret_9;
}

static Value i_typechecker(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Lookup", alg_nil());
    alg_set_property(v_this, "CurrentReturn", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "PrivateMembers", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "PropertyMembers", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "Members", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "BuiltinTypes", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "Overloads", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "Arities", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "Variadics", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "Signatures", alg_widen(alg_list(), "Set"));
    alg_set_property(v_this, "Warned", alg_widen(alg_list(), "Set"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_typechecker_init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_set_property(v_this, "Lookup", alg_new(k_typelookup, NULL, 0)));
    (void)(alg_set_property(alg_property(v_this, "Lookup"), "Generics", alg_new(k_typelookup, NULL, 0)));
    (void)(alg_set_property(alg_property(v_this, "Lookup"), "Inferred", alg_new(k_typelookup, NULL, 0)));
    {
        int32_t rt_295 = alg_root_top;
        Value loop_10 = alg_iterable(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_string("List")), alg_string("Map")), alg_string("Set")), alg_string("Stack")), alg_string("Array")));
        (void)loop_10;
        alg_root(&loop_10, 1);
        for (int32_t at_10 = 0; at_10 < alg_iterable_count(loop_10); at_10++) {
            alg_safe_point();
            int32_t rt_296 = alg_root_top;
            Value v_kind = alg_iterable_at(loop_10, at_10);
            (void)v_kind;
            alg_root(&v_kind, 1);
            {
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(v_kind, alg_string("::Length")), alg_string("Integer")}, 2));
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(v_kind, alg_string("::IsEmpty")), alg_string("Boolean")}, 2));
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(v_kind, alg_string("::Contains")), alg_string("Boolean")}, 2));
            }
            alg_root_top = rt_296;
        }
        alg_root_top = rt_295;
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
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("MkDir"), alg_string("Nil")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("RmDir"), alg_string("Nil")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("ChDir"), alg_string("Nil")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("GetDir"), alg_string("String")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Ord"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Char"), alg_string("Char")}, 2));
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
        int32_t rt_297 = alg_root_top;
        Value loop_11 = alg_iterable(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_string("Length")), alg_string("Pos")), alg_string("Copy")), alg_string("Str")), alg_string("Array")), alg_string("List")), alg_string("Map")), alg_string("Set")), alg_string("Stack")), alg_string("Buffer")), alg_string("TextFile")), alg_string("FileExists")), alg_string("ParamCount")), alg_string("ParamStr")), alg_string("Write")), alg_string("WriteLn")), alg_string("Ord")), alg_string("Val")), alg_string("Char")), alg_string("clock")), alg_string("ToUpper")), alg_string("ToLower")), alg_string("MkDir")), alg_string("RmDir")), alg_string("ChDir")), alg_string("GetDir")));
        (void)loop_11;
        alg_root(&loop_11, 1);
        for (int32_t at_11 = 0; at_11 < alg_iterable_count(loop_11); at_11++) {
            alg_safe_point();
            int32_t rt_298 = alg_root_top;
            Value v_name = alg_iterable_at(loop_11, at_11);
            (void)v_name;
            alg_root(&v_name, 1);
            (void)(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Put", (Value[]){v_name, alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){v_name}, 1)}, 2));
            alg_root_top = rt_298;
        }
        alg_root_top = rt_297;
    }
    {
        int32_t rt_299 = alg_root_top;
        Value loop_12 = alg_iterable(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_string("Any")), alg_string("Boolean")), alg_string("Integer")), alg_string("Double")), alg_string("String")), alg_string("Char")), alg_string("List")), alg_string("Set")), alg_string("Stack")), alg_string("Array")), alg_string("Map")), alg_string("TextFile")), alg_string("Buffer")), alg_string("Pointer")), alg_string("Byte")), alg_string("Word")), alg_string("Short")));
        (void)loop_12;
        alg_root(&loop_12, 1);
        for (int32_t at_12 = 0; at_12 < alg_iterable_count(loop_12); at_12++) {
            alg_safe_point();
            int32_t rt_300 = alg_root_top;
            Value v_name = alg_iterable_at(loop_12, at_12);
            (void)v_name;
            alg_root(&v_name, 1);
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes"), "Add", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1));
            alg_root_top = rt_300;
        }
        alg_root_top = rt_299;
    }
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
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    Value v_seen = alg_nil();
    (void)v_seen;
    alg_root(&v_seen, 1);
    (void)((v_at = v_thetype));
    (void)((v_seen = alg_list()));
    while (alg_truthy((or_1 = (or_0 = alg_not_equal(v_at, alg_string("")), !alg_truthy(or_0) ? or_0 : alg_not_equal(v_at, alg_string("Any"))), !alg_truthy(or_1) ? or_1 : alg_not(alg_invoke(v_seen, "Contains", (Value[]){v_at}, 1))))) {
        alg_safe_point();
        {
            (void)(alg_invoke(v_seen, "Add", (Value[]){v_at}, 1));
            if (alg_truthy(alg_invoke(alg_property(v_this, "PrivateMembers"), "Contains", (Value[]){v_at}, 1))) {
                if (alg_truthy(alg_invoke(alg_invoke(alg_property(v_this, "PrivateMembers"), "Get", (Value[]){v_at}, 1), "Contains", (Value[]){v_member}, 1))) {
                    Value ret_14 = v_at;
                    alg_root_top = rt_base;
                    return ret_14;
                }
            }
            (void)((v_at = alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_at}, 1))));
            if (alg_truthy(alg_equal(v_at, alg_string("nil")))) {
                (void)((v_at = alg_string("")));
            }
        }
    }
    Value ret_15 = alg_string("");
    alg_root_top = rt_base;
    return ret_15;
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
    Value v_thetype = alg_nil();
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    (void)((v_thetype = alg_invoke(v_this, "Reduce", (Value[]){v_obj}, 1)));
    if (alg_truthy((or_3 = ((or_2 = alg_equal(v_thetype, alg_string("")), alg_truthy(or_2) ? or_2 : alg_equal(v_thetype, alg_string("Any")))), !alg_truthy(or_3) ? or_3 : alg_is(v_obj, "VariableExpr")))) {
        {
            int32_t rt_301 = alg_root_top;
            Value v_deduced = alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Inferred"), "GetType", (Value[]){alg_str(alg_property(alg_property(v_obj, "Name"), "Lexeme"))}, 1);
            (void)v_deduced;
            alg_root(&v_deduced, 1);
            if (alg_truthy(alg_not_equal(v_deduced, alg_string("")))) {
                Value ret_17 = v_deduced;
                alg_root_top = rt_base;
                return ret_17;
            }
            alg_root_top = rt_301;
        }
    }
    Value ret_18 = v_thetype;
    alg_root_top = rt_base;
    return ret_18;
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
    Value v_found = alg_nil();
    (void)v_found;
    alg_root(&v_found, 1);
    (void)((v_found = alg_list()));
    {
        int32_t rt_302 = alg_root_top;
        Value loop_20 = alg_iterable(alg_property(v_thestmt, "Methods"));
        (void)loop_20;
        alg_root(&loop_20, 1);
        for (int32_t at_20 = 0; at_20 < alg_iterable_count(loop_20); at_20++) {
            alg_safe_point();
            int32_t rt_303 = alg_root_top;
            Value v_method = alg_iterable_at(loop_20, at_20);
            (void)v_method;
            alg_root(&v_method, 1);
            if (alg_truthy(alg_property(v_method, "IsProperty"))) {
                (void)(alg_invoke(v_found, "Add", (Value[]){alg_str(alg_property(alg_property(v_method, "Name"), "Lexeme"))}, 1));
            }
            alg_root_top = rt_303;
        }
        alg_root_top = rt_302;
    }
    Value ret_21 = v_found;
    alg_root_top = rt_base;
    return ret_21;
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
    Value v_found = alg_nil();
    (void)v_found;
    alg_root(&v_found, 1);
    (void)((v_found = alg_list()));
    {
        int32_t rt_304 = alg_root_top;
        Value loop_23 = alg_iterable(alg_property(v_thestmt, "Fields"));
        (void)loop_23;
        alg_root(&loop_23, 1);
        for (int32_t at_23 = 0; at_23 < alg_iterable_count(loop_23); at_23++) {
            alg_safe_point();
            int32_t rt_305 = alg_root_top;
            Value v_field = alg_iterable_at(loop_23, at_23);
            (void)v_field;
            alg_root(&v_field, 1);
            {
                (void)(alg_invoke(v_found, "Add", (Value[]){alg_str(alg_property(alg_property(v_field, "Name"), "Lexeme"))}, 1));
            }
            alg_root_top = rt_305;
        }
        alg_root_top = rt_304;
    }
    {
        int32_t rt_306 = alg_root_top;
        Value loop_24 = alg_iterable(alg_property(v_thestmt, "Methods"));
        (void)loop_24;
        alg_root(&loop_24, 1);
        for (int32_t at_24 = 0; at_24 < alg_iterable_count(loop_24); at_24++) {
            alg_safe_point();
            int32_t rt_307 = alg_root_top;
            Value v_method = alg_iterable_at(loop_24, at_24);
            (void)v_method;
            alg_root(&v_method, 1);
            {
                (void)(alg_invoke(v_found, "Add", (Value[]){alg_str(alg_property(alg_property(v_method, "Name"), "Lexeme"))}, 1));
            }
            alg_root_top = rt_307;
        }
        alg_root_top = rt_306;
    }
    Value ret_25 = v_found;
    alg_root_top = rt_base;
    return ret_25;
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
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    Value v_seen = alg_nil();
    (void)v_seen;
    alg_root(&v_seen, 1);
    (void)((v_at = v_thetype));
    (void)((v_seen = alg_list()));
    while (alg_truthy((or_5 = (or_4 = alg_not_equal(v_at, alg_string("")), !alg_truthy(or_4) ? or_4 : alg_not_equal(v_at, alg_string("Any"))), !alg_truthy(or_5) ? or_5 : alg_not(alg_invoke(v_seen, "Contains", (Value[]){v_at}, 1))))) {
        alg_safe_point();
        {
            (void)(alg_invoke(v_seen, "Add", (Value[]){v_at}, 1));
            if (alg_truthy(alg_invoke(alg_property(v_this, "Members"), "Contains", (Value[]){v_at}, 1))) {
                {
                    {
                        int32_t rt_308 = alg_root_top;
                        Value loop_27 = alg_iterable(alg_invoke(alg_property(v_this, "Members"), "Get", (Value[]){v_at}, 1));
                        (void)loop_27;
                        alg_root(&loop_27, 1);
                        for (int32_t at_27 = 0; at_27 < alg_iterable_count(loop_27); at_27++) {
                            alg_safe_point();
                            int32_t rt_309 = alg_root_top;
                            Value v_each = alg_iterable_at(loop_27, at_27);
                            (void)v_each;
                            alg_root(&v_each, 1);
                            {
                                if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_str(v_each)}, 1), f_foldcase(NULL, (Value[]){v_member}, 1)))) {
                                    Value ret_28 = v_at;
                                    alg_root_top = rt_base;
                                    return ret_28;
                                }
                            }
                            alg_root_top = rt_309;
                        }
                        alg_root_top = rt_308;
                    }
                }
            }
            (void)((v_at = alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_at}, 1))));
            if (alg_truthy(alg_equal(v_at, alg_string("nil")))) {
                (void)((v_at = alg_string("")));
            }
        }
    }
    Value ret_29 = alg_string("");
    alg_root_top = rt_base;
    return ret_29;
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
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    Value v_seen = alg_nil();
    (void)v_seen;
    alg_root(&v_seen, 1);
    (void)((v_at = v_thetype));
    (void)((v_seen = alg_list()));
    while (alg_truthy((or_7 = (or_6 = alg_not_equal(v_at, alg_string("")), !alg_truthy(or_6) ? or_6 : alg_not_equal(v_at, alg_string("Any"))), !alg_truthy(or_7) ? or_7 : alg_not(alg_invoke(v_seen, "Contains", (Value[]){v_at}, 1))))) {
        alg_safe_point();
        {
            (void)(alg_invoke(v_seen, "Add", (Value[]){v_at}, 1));
            if (alg_truthy(alg_invoke(alg_property(v_this, "PropertyMembers"), "Contains", (Value[]){v_at}, 1))) {
                if (alg_truthy(alg_invoke(alg_invoke(alg_property(v_this, "PropertyMembers"), "Get", (Value[]){v_at}, 1), "Contains", (Value[]){v_member}, 1))) {
                    Value ret_31 = v_at;
                    alg_root_top = rt_base;
                    return ret_31;
                }
            }
            (void)((v_at = alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_at}, 1))));
            if (alg_truthy(alg_equal(v_at, alg_string("nil")))) {
                (void)((v_at = alg_string("")));
            }
        }
    }
    Value ret_32 = alg_string("");
    alg_root_top = rt_base;
    return ret_32;
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
    if (alg_truthy(alg_not_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){v_obj}, 1), alg_string("VariableExpr")))) {
        Value ret_34 = alg_string("");
        alg_root_top = rt_base;
        return ret_34;
    }
    Value ret_35 = alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "GetType", (Value[]){alg_str(alg_property(alg_property(v_obj, "Name"), "Lexeme"))}, 1);
    alg_root_top = rt_base;
    return ret_35;
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
    if (alg_truthy((or_8 = alg_equal(v_element, alg_string("")), alg_truthy(or_8) ? or_8 : alg_equal(v_element, alg_string("Any"))))) {
        Value ret_37 = alg_nil();
        alg_root_top = rt_base;
        return ret_37;
    }
    if (alg_truthy((or_9 = alg_equal(v_actual, alg_string("")), alg_truthy(or_9) ? or_9 : alg_equal(v_actual, alg_string("Any"))))) {
        Value ret_38 = alg_nil();
        alg_root_top = rt_base;
        return ret_38;
    }
    if (alg_truthy(alg_not(alg_invoke(v_this, "Assignable", (Value[]){v_element, v_actual}, 2)))) {
        alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){v_where, v_element, v_actual}, 3));
    }
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
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    (void)((v_folded = f_foldcase(NULL, (Value[]){v_member}, 1)));
    if (alg_truthy(alg_equal(v_folded, alg_string("add")))) {
        Value ret_40 = alg_int(0);
        alg_root_top = rt_base;
        return ret_40;
    }
    if (alg_truthy(alg_equal(v_folded, alg_string("push")))) {
        Value ret_41 = alg_int(0);
        alg_root_top = rt_base;
        return ret_41;
    }
    if (alg_truthy(alg_equal(v_folded, alg_string("put")))) {
        Value ret_42 = alg_int(1);
        alg_root_top = rt_base;
        return ret_42;
    }
    Value ret_43 = alg_negate(alg_int(1));
    alg_root_top = rt_base;
    return ret_43;
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
    if (alg_truthy((or_10 = alg_equal(v_element, alg_string("")), alg_truthy(or_10) ? or_10 : alg_equal(v_element, alg_string("Any"))))) {
        Value ret_45 = alg_nil();
        alg_root_top = rt_base;
        return ret_45;
    }
    if (alg_truthy(alg_equal(v_initializer, alg_nil()))) {
        Value ret_46 = alg_nil();
        alg_root_top = rt_base;
        return ret_46;
    }
    if (alg_truthy(alg_not_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){v_initializer}, 1), alg_string("CollectionExpr")))) {
        Value ret_47 = alg_nil();
        alg_root_top = rt_base;
        return ret_47;
    }
    {
        int32_t rt_310 = alg_root_top;
        Value loop_48 = alg_iterable(alg_property(v_initializer, "Values"));
        (void)loop_48;
        alg_root(&loop_48, 1);
        for (int32_t at_48 = 0; at_48 < alg_iterable_count(loop_48); at_48++) {
            alg_safe_point();
            int32_t rt_311 = alg_root_top;
            Value v_value = alg_iterable_at(loop_48, at_48);
            (void)v_value;
            alg_root(&v_value, 1);
            (void)(alg_invoke(v_this, "CheckElement", (Value[]){v_element, alg_invoke(v_this, "Reduce", (Value[]){v_value}, 1), v_where}, 3));
            alg_root_top = rt_311;
        }
        alg_root_top = rt_310;
    }
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
    Value v_thetype = alg_nil();
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    (void)((v_thetype = alg_invoke(v_this, "TypeOfReceiver", (Value[]){v_obj}, 1)));
    Value v_owner = alg_invoke(v_this, "HiddenBy", (Value[]){v_thetype, alg_str(alg_property(v_member, "Lexeme"))}, 2);
    (void)v_owner;
    alg_root(&v_owner, 1);
    if (alg_truthy((or_11 = alg_equal(v_owner, alg_string("")), alg_truthy(or_11) ? or_11 : alg_equal(v_owner, alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"))))) {
        Value ret_50 = alg_nil();
        alg_root_top = rt_base;
        return ret_50;
    }
    alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_property(v_member, "Lexeme")), alg_string("' is private to ")), v_owner), alg_char_value(46)));
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
    Value v_parent = alg_nil();
    (void)v_parent;
    alg_root(&v_parent, 1);
    (void)((v_expected = f_underlyingtype(NULL, (Value[]){v_expected}, 1)));
    (void)((v_actual = f_underlyingtype(NULL, (Value[]){v_actual}, 1)));
    if (alg_truthy((or_12 = alg_equal(v_expected, alg_string("")), alg_truthy(or_12) ? or_12 : alg_equal(v_actual, alg_string(""))))) {
        Value ret_52 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_52;
    }
    if (alg_truthy((or_13 = alg_equal(v_expected, alg_string("Any")), alg_truthy(or_13) ? or_13 : alg_equal(v_actual, alg_string("Any"))))) {
        Value ret_53 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_53;
    }
    if (alg_truthy(alg_equal(v_actual, alg_string("Nil")))) {
        Value ret_54 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_54;
    }
    if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){v_expected}, 1), f_foldcase(NULL, (Value[]){v_actual}, 1)))) {
        Value ret_55 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_55;
    }
    if (alg_truthy((or_14 = alg_equal(v_expected, alg_string("Double")), !alg_truthy(or_14) ? or_14 : alg_equal(v_actual, alg_string("Integer"))))) {
        Value ret_56 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_56;
    }
    if (alg_truthy((or_15 = alg_equal(v_expected, alg_string("String")), !alg_truthy(or_15) ? or_15 : alg_equal(v_actual, alg_string("Char"))))) {
        Value ret_57 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_57;
    }
    (void)((v_parent = alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_actual}, 1))));
    while (alg_truthy((or_16 = alg_not_equal(v_parent, alg_string("")), !alg_truthy(or_16) ? or_16 : alg_not_equal(v_parent, alg_string("nil"))))) {
        alg_safe_point();
        {
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){v_expected}, 1), f_foldcase(NULL, (Value[]){v_parent}, 1)))) {
                Value ret_58 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_58;
            }
            (void)((v_parent = alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_parent}, 1))));
        }
    }
    Value ret_59 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_59;
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
    Value v_found = alg_nil();
    (void)v_found;
    alg_root(&v_found, 1);
    Value v_message = alg_nil();
    (void)v_message;
    alg_root(&v_message, 1);
    (void)((v_found = v_actual));
    if (alg_truthy(alg_equal(v_actual, alg_string("")))) {
        (void)((v_found = alg_string("an untyped expression")));
    }
    (void)((v_message = alg_add(alg_add(alg_add(alg_add(alg_string("Expected "), v_expected), alg_string(", found ")), v_found), alg_char_value(46))));
    (void)(alg_invoke(alg_singleton(k_console), "Error", (Value[]){v_where, v_message}, 2));
    Value ret_61 = v_message;
    alg_root_top = rt_base;
    return ret_61;
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
    {
        int32_t rt_312 = alg_root_top;
        Value loop_63 = alg_iterable(v_statements);
        (void)loop_63;
        alg_root(&loop_63, 1);
        for (int32_t at_63 = 0; at_63 < alg_iterable_count(loop_63); at_63++) {
            alg_safe_point();
            int32_t rt_313 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_63, at_63);
            (void)v_statement;
            alg_root(&v_statement, 1);
            (void)(alg_invoke(v_this, "MapType", (Value[]){v_statement}, 1));
            alg_root_top = rt_313;
        }
        alg_root_top = rt_312;
    }
    {
        int32_t rt_314 = alg_root_top;
        Value loop_64 = alg_iterable(v_statements);
        (void)loop_64;
        alg_root(&loop_64, 1);
        for (int32_t at_64 = 0; at_64 < alg_iterable_count(loop_64); at_64++) {
            alg_safe_point();
            int32_t rt_315 = alg_root_top;
            Value v_thestatement = alg_iterable_at(loop_64, at_64);
            (void)v_thestatement;
            alg_root(&v_thestatement, 1);
            (void)(alg_invoke(v_this, "Check", (Value[]){v_thestatement}, 1));
            alg_root_top = rt_315;
        }
        alg_root_top = rt_314;
    }
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
    Value v_kind = alg_nil();
    (void)v_kind;
    alg_root(&v_kind, 1);
    (void)((v_kind = alg_invoke(v_this, "ClassNameOf", (Value[]){v_thestmt}, 1)));
    if (alg_truthy(alg_equal(v_kind, alg_string("ClassStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "PrivateMembers"), "Put", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "PrivateMembers")}, 2));
            (void)(alg_invoke(alg_property(v_this, "PropertyMembers"), "Put", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_invoke(v_this, "PropertiesOf", (Value[]){v_thestmt}, 1)}, 2));
            (void)(alg_invoke(alg_property(v_this, "Members"), "Put", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_invoke(v_this, "MembersOf", (Value[]){v_thestmt}, 1)}, 2));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 2));
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)}, 1));
            if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Superclass"), alg_nil()))) {
                (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Put", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(alg_property(alg_property(v_thestmt, "Superclass"), "Name"), "Lexeme")}, 2));
            }
            {
                int32_t rt_316 = alg_root_top;
                Value loop_66 = alg_iterable(alg_property(v_thestmt, "Fields"));
                (void)loop_66;
                alg_root(&loop_66, 1);
                for (int32_t at_66 = 0; at_66 < alg_iterable_count(loop_66); at_66++) {
                    alg_safe_point();
                    int32_t rt_317 = alg_root_top;
                    Value v_field = alg_iterable_at(loop_66, at_66);
                    (void)v_field;
                    alg_root(&v_field, 1);
                    {
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_property(v_field, "Name"), "Lexeme")), alg_property(v_field, "TypeName")}, 2));
                        (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_field, "Name"), "Lexeme")), alg_property(v_field, "Generic")}, 2));
                    }
                    alg_root_top = rt_317;
                }
                alg_root_top = rt_316;
            }
            {
                int32_t rt_318 = alg_root_top;
                Value loop_67 = alg_iterable(alg_property(v_thestmt, "Methods"));
                (void)loop_67;
                alg_root(&loop_67, 1);
                for (int32_t at_67 = 0; at_67 < alg_iterable_count(loop_67); at_67++) {
                    alg_safe_point();
                    int32_t rt_319 = alg_root_top;
                    Value v_method = alg_iterable_at(loop_67, at_67);
                    (void)v_method;
                    alg_root(&v_method, 1);
                    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_property(v_method, "Name"), "Lexeme")), alg_property(v_method, "ReturnType")}, 2));
                    alg_root_top = rt_319;
                }
                alg_root_top = rt_318;
            }
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ObjectStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "PrivateMembers"), "Put", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "PrivateMembers")}, 2));
            (void)(alg_invoke(alg_property(v_this, "Members"), "Put", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_invoke(v_this, "MembersOf", (Value[]){v_thestmt}, 1)}, 2));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 2));
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)}, 1));
            if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Superclass"), alg_nil()))) {
                (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Put", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(alg_property(alg_property(v_thestmt, "Superclass"), "Name"), "Lexeme")}, 2));
            }
            {
                int32_t rt_320 = alg_root_top;
                Value loop_68 = alg_iterable(alg_property(v_thestmt, "Fields"));
                (void)loop_68;
                alg_root(&loop_68, 1);
                for (int32_t at_68 = 0; at_68 < alg_iterable_count(loop_68); at_68++) {
                    alg_safe_point();
                    int32_t rt_321 = alg_root_top;
                    Value v_thefield = alg_iterable_at(loop_68, at_68);
                    (void)v_thefield;
                    alg_root(&v_thefield, 1);
                    {
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_property(v_thefield, "Name"), "Lexeme")), alg_property(v_thefield, "TypeName")}, 2));
                        (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_thefield, "Name"), "Lexeme")), alg_property(v_thefield, "Generic")}, 2));
                    }
                    alg_root_top = rt_321;
                }
                alg_root_top = rt_320;
            }
            {
                int32_t rt_322 = alg_root_top;
                Value loop_69 = alg_iterable(alg_property(v_thestmt, "Methods"));
                (void)loop_69;
                alg_root(&loop_69, 1);
                for (int32_t at_69 = 0; at_69 < alg_iterable_count(loop_69); at_69++) {
                    alg_safe_point();
                    int32_t rt_323 = alg_root_top;
                    Value v_themethod = alg_iterable_at(loop_69, at_69);
                    (void)v_themethod;
                    alg_root(&v_themethod, 1);
                    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_property(v_themethod, "Name"), "Lexeme")), alg_property(v_themethod, "ReturnType")}, 2));
                    alg_root_top = rt_323;
                }
                alg_root_top = rt_322;
            }
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("FunctionStmt")))) {
        {
            int32_t rt_324 = alg_root_top;
            Value v_folded = f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1);
            (void)v_folded;
            alg_root(&v_folded, 1);
            Value v_signature = alg_add(alg_add(v_folded, alg_char_value(47)), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length")));
            (void)v_signature;
            alg_root(&v_signature, 1);
            {
                int32_t rt_325 = alg_root_top;
                Value loop_70 = alg_iterable(alg_property(v_thestmt, "ParamTypes"));
                (void)loop_70;
                alg_root(&loop_70, 1);
                for (int32_t at_70 = 0; at_70 < alg_iterable_count(loop_70); at_70++) {
                    alg_safe_point();
                    int32_t rt_326 = alg_root_top;
                    Value v_paramtype = alg_iterable_at(loop_70, at_70);
                    (void)v_paramtype;
                    alg_root(&v_paramtype, 1);
                    (void)((v_signature = alg_add(alg_add(v_signature, alg_char_value(47)), f_foldcase(NULL, (Value[]){alg_str(v_paramtype)}, 1))));
                    alg_root_top = rt_326;
                }
                alg_root_top = rt_325;
            }
            if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Signatures"), "Contains", (Value[]){v_signature}, 1)))) {
                {
                    int32_t rt_327 = alg_root_top;
                    (void)(alg_invoke(alg_property(v_this, "Signatures"), "Add", (Value[]){v_signature}, 1));
                    Value v_seen = alg_int(0);
                    (void)v_seen;
                    alg_root(&v_seen, 1);
                    if (alg_truthy(alg_invoke(alg_property(v_this, "Overloads"), "Contains", (Value[]){v_folded}, 1))) {
                        (void)((v_seen = alg_cast_kind(alg_invoke(alg_property(v_this, "Overloads"), "Get", (Value[]){v_folded}, 1), ALG_KIND_INTEGER, "Integer")));
                    }
                    (void)(alg_invoke(alg_property(v_this, "Overloads"), "Put", (Value[]){v_folded, alg_add(v_seen, alg_int(1))}, 2));
                    (void)(alg_invoke(v_this, "RecordArity", (Value[]){v_thestmt, v_folded}, 2));
                    alg_root_top = rt_327;
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(v_thestmt, "ReturnType")}, 2));
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "ReturnGeneric")}, 2));
            alg_root_top = rt_324;
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
                int32_t rt_328 = alg_root_top;
                Value loop_71 = alg_iterable(alg_property(v_thestmt, "Members"));
                (void)loop_71;
                alg_root(&loop_71, 1);
                for (int32_t at_71 = 0; at_71 < alg_iterable_count(loop_71); at_71++) {
                    alg_safe_point();
                    int32_t rt_329 = alg_root_top;
                    Value v_member = alg_iterable_at(loop_71, at_71);
                    (void)v_member;
                    alg_root(&v_member, 1);
                    {
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(v_member, "Lexeme"), alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 2));
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_string("::")), alg_property(v_member, "Lexeme")), alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 2));
                    }
                    alg_root_top = rt_329;
                }
                alg_root_top = rt_328;
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
            int32_t rt_330 = alg_root_top;
            Value loop_72 = alg_iterable(alg_property(v_thestmt, "Names"));
            (void)loop_72;
            alg_root(&loop_72, 1);
            for (int32_t at_72 = 0; at_72 < alg_iterable_count(loop_72); at_72++) {
                alg_safe_point();
                int32_t rt_331 = alg_root_top;
                Value v_thename = alg_iterable_at(loop_72, at_72);
                (void)v_thename;
                alg_root(&v_thename, 1);
                {
                    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(v_thename, "Lexeme"), alg_property(v_thestmt, "TypeName")}, 2));
                    (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(v_thename, "Lexeme")), alg_property(v_thestmt, "Generic")}, 2));
                }
                alg_root_top = rt_331;
            }
            alg_root_top = rt_330;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ModuleStmt")))) {
        if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Statements"), alg_nil()))) {
            {
                int32_t rt_332 = alg_root_top;
                Value loop_73 = alg_iterable(alg_property(v_thestmt, "Statements"));
                (void)loop_73;
                alg_root(&loop_73, 1);
                for (int32_t at_73 = 0; at_73 < alg_iterable_count(loop_73); at_73++) {
                    alg_safe_point();
                    int32_t rt_333 = alg_root_top;
                    Value v_thestatement = alg_iterable_at(loop_73, at_73);
                    (void)v_thestatement;
                    alg_root(&v_thestatement, 1);
                    (void)(alg_invoke(v_this, "MapType", (Value[]){v_thestatement}, 1));
                    alg_root_top = rt_333;
                }
                alg_root_top = rt_332;
            }
        }
    }
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
    Value v_kind = alg_nil();
    (void)v_kind;
    alg_root(&v_kind, 1);
    (void)((v_kind = alg_invoke(v_this, "ClassNameOf", (Value[]){v_thestmt}, 1)));
    if (alg_truthy(alg_equal(v_kind, alg_string("VarStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), alg_property(v_thestmt, "TypeName")}, 2));
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "Generic")}, 2));
            if (alg_truthy((or_17 = alg_not_equal(alg_property(v_thestmt, "Initializer"), alg_nil()), !alg_truthy(or_17) ? or_17 : alg_equal(alg_property(v_thestmt, "TypeName"), alg_string(""))))) {
                (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Inferred"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Initializer")}, 1)}, 2));
            }
            (void)(alg_invoke(v_this, "CheckLiteral", (Value[]){alg_str(alg_property(v_thestmt, "Generic")), alg_property(v_thestmt, "Initializer"), alg_property(v_thestmt, "Name")}, 3));
            if (alg_truthy((or_18 = alg_not_equal(alg_property(v_thestmt, "Initializer"), alg_nil()), !alg_truthy(or_18) ? or_18 : alg_not_equal(alg_property(v_thestmt, "TypeName"), alg_string(""))))) {
                {
                    int32_t rt_334 = alg_root_top;
                    Value v_actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Initializer")}, 1);
                    (void)v_actual;
                    alg_root(&v_actual, 1);
                    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "TypeName"), alg_string("Any")))) {
                        if (alg_truthy((or_20 = (or_19 = alg_equal(v_actual, alg_string("")), alg_truthy(or_19) ? or_19 : alg_equal(v_actual, alg_string("Any"))), alg_truthy(or_20) ? or_20 : alg_not(alg_invoke(v_this, "Assignable", (Value[]){alg_property(v_thestmt, "TypeName"), v_actual}, 2))))) {
                            alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_property(v_thestmt, "Name"), alg_property(v_thestmt, "TypeName"), v_actual}, 3));
                        }
                    }
                    (void)(alg_set_property(v_thestmt, "Actual", v_actual));
                    alg_root_top = rt_334;
                }
            }
            Value ret_75 = alg_nil();
            alg_root_top = rt_base;
            return ret_75;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("VarGroupStmt")))) {
        {
            {
                int32_t rt_335 = alg_root_top;
                Value loop_76 = alg_iterable(alg_property(v_thestmt, "Names"));
                (void)loop_76;
                alg_root(&loop_76, 1);
                for (int32_t at_76 = 0; at_76 < alg_iterable_count(loop_76); at_76++) {
                    alg_safe_point();
                    int32_t rt_336 = alg_root_top;
                    Value v_thename = alg_iterable_at(loop_76, at_76);
                    (void)v_thename;
                    alg_root(&v_thename, 1);
                    {
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(v_thename, "Lexeme"), alg_property(v_thestmt, "TypeName")}, 2));
                        (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(v_thename, "Lexeme")), alg_property(v_thestmt, "Generic")}, 2));
                    }
                    alg_root_top = rt_336;
                }
                alg_root_top = rt_335;
            }
            if (alg_truthy((or_21 = alg_not_equal(alg_property(v_thestmt, "Initializer"), alg_nil()), !alg_truthy(or_21) ? or_21 : alg_not_equal(alg_property(v_thestmt, "TypeName"), alg_string(""))))) {
                {
                    int32_t rt_337 = alg_root_top;
                    Value v_actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Initializer")}, 1);
                    (void)v_actual;
                    alg_root(&v_actual, 1);
                    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "TypeName"), alg_string("Any")))) {
                        if (alg_truthy((or_23 = (or_22 = alg_equal(v_actual, alg_string("")), alg_truthy(or_22) ? or_22 : alg_equal(v_actual, alg_string("Any"))), alg_truthy(or_23) ? or_23 : alg_not(alg_invoke(v_this, "Assignable", (Value[]){alg_property(v_thestmt, "TypeName"), v_actual}, 2))))) {
                            alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_subscript_get(alg_property(v_thestmt, "Names"), alg_int(0)), alg_property(v_thestmt, "TypeName"), v_actual}, 3));
                        }
                    }
                    (void)(alg_set_property(v_thestmt, "Actual", v_actual));
                    alg_root_top = rt_337;
                }
            }
            Value ret_77 = alg_nil();
            alg_root_top = rt_base;
            return ret_77;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ExpressionStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Expression")}, 1));
            Value ret_78 = alg_nil();
            alg_root_top = rt_base;
            return ret_78;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("BlockStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
            {
                int32_t rt_338 = alg_root_top;
                Value loop_79 = alg_iterable(alg_property(v_thestmt, "Statements"));
                (void)loop_79;
                alg_root(&loop_79, 1);
                for (int32_t at_79 = 0; at_79 < alg_iterable_count(loop_79); at_79++) {
                    alg_safe_point();
                    int32_t rt_339 = alg_root_top;
                    Value v_statement = alg_iterable_at(loop_79, at_79);
                    (void)v_statement;
                    alg_root(&v_statement, 1);
                    (void)(alg_invoke(v_this, "Check", (Value[]){v_statement}, 1));
                    alg_root_top = rt_339;
                }
                alg_root_top = rt_338;
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
            Value ret_80 = alg_nil();
            alg_root_top = rt_base;
            return ret_80;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("IfStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Condition")}, 1));
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_thestmt, "ThenBranch")}, 1));
            if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "ElseBranch"), alg_nil()))) {
                (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_thestmt, "ElseBranch")}, 1));
            }
            Value ret_81 = alg_nil();
            alg_root_top = rt_base;
            return ret_81;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ForInStmt")))) {
        {
            int32_t rt_340 = alg_root_top;
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Iterable")}, 1));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
            Value v_element = alg_string("");
            (void)v_element;
            alg_root(&v_element, 1);
            if (alg_truthy(alg_is(alg_property(v_thestmt, "Iterable"), "VariableExpr"))) {
                (void)((v_element = alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "GetType", (Value[]){alg_str(alg_property(alg_property(alg_property(v_thestmt, "Iterable"), "Name"), "Lexeme"))}, 1)));
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), v_element}, 2));
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_thestmt, "Body")}, 1));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
            Value ret_82 = alg_nil();
            alg_root_top = rt_base;
            return ret_82;
            alg_root_top = rt_340;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("WhileStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Condition")}, 1));
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_thestmt, "Body")}, 1));
            if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Increment"), alg_nil()))) {
                (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Increment")}, 1));
            }
            Value ret_83 = alg_nil();
            alg_root_top = rt_base;
            return ret_83;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("LabelStmt")))) {
        {
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_thestmt, "Inner")}, 1));
            Value ret_84 = alg_nil();
            alg_root_top = rt_base;
            return ret_84;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ReturnStmt")))) {
        {
            if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Value"), alg_nil()))) {
                {
                    int32_t rt_341 = alg_root_top;
                    Value v_actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Value")}, 1);
                    (void)v_actual;
                    alg_root(&v_actual, 1);
                    if (alg_truthy(alg_not(alg_invoke(v_this, "Assignable", (Value[]){alg_property(v_this, "CurrentReturn"), v_actual}, 2)))) {
                        alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_property(v_thestmt, "Keyword"), alg_property(v_this, "CurrentReturn"), v_actual}, 3));
                    }
                    alg_root_top = rt_341;
                }
            }
            Value ret_85 = alg_nil();
            alg_root_top = rt_base;
            return ret_85;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("TryStmt")))) {
        {
            int32_t rt_342 = alg_root_top;
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_thestmt, "TryBlock")}, 1));
            Value v_keys = alg_invoke(alg_property(v_thestmt, "Handlers"), "Keys", NULL, 0);
            (void)v_keys;
            alg_root(&v_keys, 1);
            {
                int32_t rt_343 = alg_root_top;
                Value loop_86 = alg_iterable(v_keys);
                (void)loop_86;
                alg_root(&loop_86, 1);
                for (int32_t at_86 = 0; at_86 < alg_iterable_count(loop_86); at_86++) {
                    alg_safe_point();
                    int32_t rt_344 = alg_root_top;
                    Value v_key = alg_iterable_at(loop_86, at_86);
                    (void)v_key;
                    alg_root(&v_key, 1);
                    (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(alg_invoke(alg_property(v_thestmt, "Handlers"), "Get", (Value[]){v_key}, 1), "Body")}, 1));
                    alg_root_top = rt_344;
                }
                alg_root_top = rt_343;
            }
            Value ret_87 = alg_nil();
            alg_root_top = rt_base;
            return ret_87;
            alg_root_top = rt_342;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("BreakStmt")))) {
        Value ret_88 = alg_nil();
        alg_root_top = rt_base;
        return ret_88;
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ModuleStmt")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_thestmt, "Statements"), alg_nil()))) {
                Value ret_89 = alg_nil();
                alg_root_top = rt_base;
                return ret_89;
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
            {
                int32_t rt_345 = alg_root_top;
                Value loop_90 = alg_iterable(alg_property(v_this, "BuiltinTypes"));
                (void)loop_90;
                alg_root(&loop_90, 1);
                for (int32_t at_90 = 0; at_90 < alg_iterable_count(loop_90); at_90++) {
                    alg_safe_point();
                    int32_t rt_346 = alg_root_top;
                    Value v_name = alg_iterable_at(loop_90, at_90);
                    (void)v_name;
                    alg_root(&v_name, 1);
                    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){v_name, alg_str(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Get", (Value[]){v_name}, 1))}, 2));
                    alg_root_top = rt_346;
                }
                alg_root_top = rt_345;
            }
            {
                int32_t rt_347 = alg_root_top;
                Value loop_91 = alg_iterable(alg_property(v_thestmt, "Statements"));
                (void)loop_91;
                alg_root(&loop_91, 1);
                for (int32_t at_91 = 0; at_91 < alg_iterable_count(loop_91); at_91++) {
                    alg_safe_point();
                    int32_t rt_348 = alg_root_top;
                    Value v_thestatement = alg_iterable_at(loop_91, at_91);
                    (void)v_thestatement;
                    alg_root(&v_thestatement, 1);
                    (void)(alg_invoke(v_this, "MapType", (Value[]){v_thestatement}, 1));
                    alg_root_top = rt_348;
                }
                alg_root_top = rt_347;
            }
            {
                int32_t rt_349 = alg_root_top;
                Value loop_92 = alg_iterable(alg_property(v_thestmt, "Statements"));
                (void)loop_92;
                alg_root(&loop_92, 1);
                for (int32_t at_92 = 0; at_92 < alg_iterable_count(loop_92); at_92++) {
                    alg_safe_point();
                    int32_t rt_350 = alg_root_top;
                    Value v_eachstatement = alg_iterable_at(loop_92, at_92);
                    (void)v_eachstatement;
                    alg_root(&v_eachstatement, 1);
                    (void)(alg_invoke(v_this, "Check", (Value[]){v_eachstatement}, 1));
                    alg_root_top = rt_350;
                }
                alg_root_top = rt_349;
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
            Value ret_93 = alg_nil();
            alg_root_top = rt_base;
            return ret_93;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("RaiseStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_thestmt, "Value")}, 1));
            Value ret_94 = alg_nil();
            alg_root_top = rt_base;
            return ret_94;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("FunctionStmt")))) {
        {
            (void)(alg_invoke(v_this, "CheckFunction", (Value[]){v_thestmt}, 1));
            Value ret_95 = alg_nil();
            alg_root_top = rt_base;
            return ret_95;
        }
    }
    if (alg_truthy((or_24 = alg_equal(v_kind, alg_string("ObjectStmt")), alg_truthy(or_24) ? or_24 : alg_equal(v_kind, alg_string("ClassStmt"))))) {
        {
            int32_t rt_351 = alg_root_top;
            Value v_enclosing = alg_property(alg_property(v_this, "Lookup"), "CurrentClassName");
            (void)v_enclosing;
            alg_root(&v_enclosing, 1);
            (void)(alg_set_property(alg_property(v_this, "Lookup"), "CurrentClassName", alg_widen(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"), "String")));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
            {
                int32_t rt_352 = alg_root_top;
                Value loop_96 = alg_iterable(alg_property(v_thestmt, "Fields"));
                (void)loop_96;
                alg_root(&loop_96, 1);
                for (int32_t at_96 = 0; at_96 < alg_iterable_count(loop_96); at_96++) {
                    alg_safe_point();
                    int32_t rt_353 = alg_root_top;
                    Value v_field = alg_iterable_at(loop_96, at_96);
                    (void)v_field;
                    alg_root(&v_field, 1);
                    {
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_field, "Name"), "Lexeme"), alg_property(v_field, "TypeName")}, 2));
                        (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_field, "Name"), "Lexeme")), alg_property(v_field, "Generic")}, 2));
                    }
                    alg_root_top = rt_353;
                }
                alg_root_top = rt_352;
            }
            {
                int32_t rt_354 = alg_root_top;
                Value loop_97 = alg_iterable(alg_property(v_thestmt, "Methods"));
                (void)loop_97;
                alg_root(&loop_97, 1);
                for (int32_t at_97 = 0; at_97 < alg_iterable_count(loop_97); at_97++) {
                    alg_safe_point();
                    int32_t rt_355 = alg_root_top;
                    Value v_method = alg_iterable_at(loop_97, at_97);
                    (void)v_method;
                    alg_root(&v_method, 1);
                    (void)(alg_invoke(v_this, "CheckFunction", (Value[]){v_method}, 1));
                    alg_root_top = rt_355;
                }
                alg_root_top = rt_354;
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
            (void)(alg_set_property(alg_property(v_this, "Lookup"), "CurrentClassName", v_enclosing));
            Value ret_98 = alg_nil();
            alg_root_top = rt_base;
            return ret_98;
            alg_root_top = rt_351;
        }
    }
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
    Value v_enclosing = alg_nil();
    (void)v_enclosing;
    alg_root(&v_enclosing, 1);
    (void)((v_enclosing = alg_property(v_this, "CurrentReturn")));
    (void)(alg_set_property(v_this, "CurrentReturn", alg_cast_kind(alg_property(v_thefunction, "ReturnType"), ALG_KIND_STRING, "String")));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
    {
        int32_t rt_356 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thefunction, "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            alg_safe_point();
            {
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_subscript_get(alg_property(v_thefunction, "Params"), v_i), "Lexeme"), alg_str(alg_subscript_get(alg_property(v_thefunction, "ParamTypes"), v_i))}, 2));
                if (alg_truthy(alg_less(v_i, alg_property(alg_property(v_thefunction, "ParamGenerics"), "Length")))) {
                    (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_thefunction, "Params"), v_i), "Lexeme")), alg_str(alg_subscript_get(alg_property(v_thefunction, "ParamGenerics"), v_i))}, 2));
                }
            }
        }
        alg_root_top = rt_356;
    }
    {
        int32_t rt_357 = alg_root_top;
        Value loop_100 = alg_iterable(alg_property(v_thefunction, "Body"));
        (void)loop_100;
        alg_root(&loop_100, 1);
        for (int32_t at_100 = 0; at_100 < alg_iterable_count(loop_100); at_100++) {
            alg_safe_point();
            int32_t rt_358 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_100, at_100);
            (void)v_statement;
            alg_root(&v_statement, 1);
            if (alg_truthy(alg_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){v_statement}, 1), alg_string("FunctionStmt")))) {
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_statement, "Name"), "Lexeme"), alg_property(v_statement, "ReturnType")}, 2));
            }
            alg_root_top = rt_358;
        }
        alg_root_top = rt_357;
    }
    {
        int32_t rt_359 = alg_root_top;
        Value loop_101 = alg_iterable(alg_property(v_thefunction, "Body"));
        (void)loop_101;
        alg_root(&loop_101, 1);
        for (int32_t at_101 = 0; at_101 < alg_iterable_count(loop_101); at_101++) {
            alg_safe_point();
            int32_t rt_360 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_101, at_101);
            (void)v_statement;
            alg_root(&v_statement, 1);
            (void)(alg_invoke(v_this, "Check", (Value[]){v_statement}, 1));
            alg_root_top = rt_360;
        }
        alg_root_top = rt_359;
    }
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
    (void)(alg_set_property(v_this, "CurrentReturn", v_enclosing));
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
    Value v_count = alg_property(alg_property(v_thestmt, "Params"), "Length");
    (void)v_count;
    alg_root(&v_count, 1);
    Value v_gathers = alg_bool(false);
    (void)v_gathers;
    alg_root(&v_gathers, 1);
    if (alg_truthy(alg_greater(v_count, alg_int(0)))) {
        (void)((v_gathers = (or_25 = alg_equal(f_canonicaltype(NULL, (Value[]){alg_subscript_get(alg_property(v_thestmt, "ParamTypes"), alg_subtract(v_count, alg_int(1)))}, 1), alg_string("List")), !alg_truthy(or_25) ? or_25 : alg_not_equal(alg_str(alg_subscript_get(alg_property(v_thestmt, "ParamGenerics"), alg_subtract(v_count, alg_int(1)))), alg_string("")))));
    }
    if (alg_truthy(v_gathers)) {
        {
            if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Variadics"), "Contains", (Value[]){v_folded}, 1)))) {
                (void)(alg_invoke(alg_property(v_this, "Variadics"), "Put", (Value[]){v_folded, alg_list()}, 2));
            }
            (void)(alg_invoke(alg_invoke(alg_property(v_this, "Variadics"), "Get", (Value[]){v_folded}, 1), "Add", (Value[]){alg_subtract(v_count, alg_int(1))}, 1));
            Value ret_103 = alg_nil();
            alg_root_top = rt_base;
            return ret_103;
        }
    }
    Value v_key = alg_add(alg_add(v_folded, alg_char_value(47)), alg_str(v_count));
    (void)v_key;
    alg_root(&v_key, 1);
    Value v_taken = alg_int(0);
    (void)v_taken;
    alg_root(&v_taken, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Arities"), "Contains", (Value[]){v_key}, 1))) {
        (void)((v_taken = alg_cast_kind(alg_invoke(alg_property(v_this, "Arities"), "Get", (Value[]){v_key}, 1), ALG_KIND_INTEGER, "Integer")));
    }
    (void)(alg_invoke(alg_property(v_this, "Arities"), "Put", (Value[]){v_key, alg_add(v_taken, alg_int(1))}, 2));
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
    Value v_total = alg_nil();
    (void)v_total;
    alg_root(&v_total, 1);
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    (void)((v_total = alg_int(0)));
    (void)((v_key = alg_add(alg_add(v_folded, alg_char_value(47)), alg_str(v_count))));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Arities"), "Contains", (Value[]){v_key}, 1))) {
        (void)((v_total = alg_cast_kind(alg_invoke(alg_property(v_this, "Arities"), "Get", (Value[]){v_key}, 1), ALG_KIND_INTEGER, "Integer")));
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Variadics"), "Contains", (Value[]){v_folded}, 1))) {
        {
            int32_t rt_361 = alg_root_top;
            Value loop_105 = alg_iterable(alg_invoke(alg_property(v_this, "Variadics"), "Get", (Value[]){v_folded}, 1));
            (void)loop_105;
            alg_root(&loop_105, 1);
            for (int32_t at_105 = 0; at_105 < alg_iterable_count(loop_105); at_105++) {
                alg_safe_point();
                int32_t rt_362 = alg_root_top;
                Value v_fixed = alg_iterable_at(loop_105, at_105);
                (void)v_fixed;
                alg_root(&v_fixed, 1);
                if (alg_truthy(alg_greater_equal(v_count, (alg_cast_kind(v_fixed, ALG_KIND_INTEGER, "Integer"))))) {
                    (void)((v_total = alg_add(v_total, alg_int(1))));
                }
                alg_root_top = rt_362;
            }
            alg_root_top = rt_361;
        }
    }
    Value ret_106 = v_total;
    alg_root_top = rt_base;
    return ret_106;
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
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    Value v_seen = alg_nil();
    (void)v_seen;
    alg_root(&v_seen, 1);
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    Value v_count = alg_nil();
    (void)v_count;
    alg_root(&v_count, 1);
    (void)((v_count = alg_cast_kind(alg_property(alg_property(v_theexpr, "Arguments"), "Length"), ALG_KIND_INTEGER, "Integer")));
    if (alg_truthy(alg_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_property(v_theexpr, "Callee")}, 1), alg_string("GetExpr")))) {
        {
            if (alg_truthy(alg_equal(alg_str(alg_property(alg_property(v_theexpr, "Callee"), "Extension")), alg_string("")))) {
                Value ret_108 = alg_nil();
                alg_root_top = rt_base;
                return ret_108;
            }
            if (alg_truthy(alg_not_equal(alg_property(alg_property(v_theexpr, "Callee"), "Unit"), alg_string("")))) {
                Value ret_109 = alg_nil();
                alg_root_top = rt_base;
                return ret_109;
            }
            (void)((v_count = alg_add(v_count, alg_int(1))));
        }
    } else {
        if (alg_truthy(alg_not_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_property(v_theexpr, "Callee")}, 1), alg_string("VariableExpr")))) {
            Value ret_110 = alg_nil();
            alg_root_top = rt_base;
            return ret_110;
        }
    }
    {
        int32_t rt_363 = alg_root_top;
        Value loop_111 = alg_iterable(alg_property(v_theexpr, "ArgumentNames"));
        (void)loop_111;
        alg_root(&loop_111, 1);
        for (int32_t at_111 = 0; at_111 < alg_iterable_count(loop_111); at_111++) {
            alg_safe_point();
            int32_t rt_364 = alg_root_top;
            Value v_argumentname = alg_iterable_at(loop_111, at_111);
            (void)v_argumentname;
            alg_root(&v_argumentname, 1);
            if (alg_truthy(alg_not_equal(alg_str(v_argumentname), alg_string("")))) {
                Value ret_112 = alg_nil();
                alg_root_top = rt_base;
                return ret_112;
            }
            alg_root_top = rt_364;
        }
        alg_root_top = rt_363;
    }
    (void)((v_folded = f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme"))}, 1)));
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Overloads"), "Contains", (Value[]){v_folded}, 1)))) {
        Value ret_113 = alg_nil();
        alg_root_top = rt_base;
        return ret_113;
    }
    (void)((v_seen = alg_cast_kind(alg_invoke(alg_property(v_this, "Overloads"), "Get", (Value[]){v_folded}, 1), ALG_KIND_INTEGER, "Integer")));
    if (alg_truthy(alg_less(v_seen, alg_int(2)))) {
        Value ret_114 = alg_nil();
        alg_root_top = rt_base;
        return ret_114;
    }
    (void)((v_seen = alg_invoke(v_this, "CandidatesFor", (Value[]){v_folded, v_count}, 2)));
    if (alg_truthy(alg_less(v_seen, alg_int(2)))) {
        Value ret_115 = alg_nil();
        alg_root_top = rt_base;
        return ret_115;
    }
    (void)((v_key = alg_add(alg_add(alg_str(alg_property(alg_property(v_theexpr, "Paren"), "LineNumber")), alg_char_value(58)), v_folded)));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Warned"), "Contains", (Value[]){v_key}, 1))) {
        Value ret_116 = alg_nil();
        alg_root_top = rt_base;
        return ret_116;
    }
    (void)(alg_invoke(alg_property(v_this, "Warned"), "Add", (Value[]){v_key}, 1));
    (void)(alg_invoke(alg_singleton(k_console), "Warn", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_invoke(alg_singleton(k_sourcecode), "Named", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Paren"), "File"))}, 1), alg_char_value(58)), alg_str(alg_property(alg_property(v_theexpr, "Paren"), "LineNumber"))), alg_string(": '")), alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme"))), alg_string("' selects among ")), alg_str(v_seen)), alg_string(" overloads at run time."))}, 1));
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
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    Value v_count = alg_nil();
    (void)v_count;
    alg_root(&v_count, 1);
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    if (alg_truthy(alg_not_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_property(v_theexpr, "Callee")}, 1), alg_string("VariableExpr")))) {
        Value ret_118 = alg_nil();
        alg_root_top = rt_base;
        return ret_118;
    }
    {
        int32_t rt_365 = alg_root_top;
        Value loop_119 = alg_iterable(alg_property(v_theexpr, "ArgumentNames"));
        (void)loop_119;
        alg_root(&loop_119, 1);
        for (int32_t at_119 = 0; at_119 < alg_iterable_count(loop_119); at_119++) {
            alg_safe_point();
            int32_t rt_366 = alg_root_top;
            Value v_argumentname = alg_iterable_at(loop_119, at_119);
            (void)v_argumentname;
            alg_root(&v_argumentname, 1);
            if (alg_truthy(alg_not_equal(alg_str(v_argumentname), alg_string("")))) {
                Value ret_120 = alg_nil();
                alg_root_top = rt_base;
                return ret_120;
            }
            alg_root_top = rt_366;
        }
        alg_root_top = rt_365;
    }
    (void)((v_folded = f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme"))}, 1)));
    if (alg_truthy(alg_invoke((alg_declared(d_builtinVnames, "BUILTIN_NAMES"), v_builtinVnames), "Contains", (Value[]){v_folded}, 1))) {
        Value ret_121 = alg_nil();
        alg_root_top = rt_base;
        return ret_121;
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Overloads"), "Contains", (Value[]){v_folded}, 1)))) {
        Value ret_122 = alg_nil();
        alg_root_top = rt_base;
        return ret_122;
    }
    if (alg_truthy(alg_not_equal(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"), alg_string("")))) {
        if (alg_truthy(alg_not_equal(alg_invoke(v_this, "DeclaresMember", (Value[]){alg_str(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName")), v_folded}, 2), alg_string("")))) {
            Value ret_123 = alg_nil();
            alg_root_top = rt_base;
            return ret_123;
        }
    }
    (void)((v_count = alg_cast_kind(alg_property(alg_property(v_theexpr, "Arguments"), "Length"), ALG_KIND_INTEGER, "Integer")));
    if (alg_truthy(alg_greater(alg_invoke(v_this, "CandidatesFor", (Value[]){v_folded, v_count}, 2), alg_int(0)))) {
        Value ret_124 = alg_nil();
        alg_root_top = rt_base;
        return ret_124;
    }
    (void)((v_key = alg_add(alg_add(alg_add(alg_string("arity:"), alg_str(alg_property(alg_property(v_theexpr, "Paren"), "LineNumber"))), alg_char_value(58)), v_folded)));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Warned"), "Contains", (Value[]){v_key}, 1))) {
        Value ret_125 = alg_nil();
        alg_root_top = rt_base;
        return ret_125;
    }
    (void)(alg_invoke(alg_property(v_this, "Warned"), "Add", (Value[]){v_key}, 1));
    (void)(alg_invoke(alg_singleton(k_console), "Warn", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_invoke(alg_singleton(k_sourcecode), "Named", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Paren"), "File"))}, 1), alg_char_value(58)), alg_str(alg_property(alg_property(v_theexpr, "Paren"), "LineNumber"))), alg_string(": '")), alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme"))), alg_string("' is called with ")), alg_str(v_count)), alg_string(" argument(s), which no declaration of it takes."))}, 1));
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
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    if (alg_truthy(alg_not_equal(v_thetype, alg_string("Integer")))) {
        Value ret_127 = alg_nil();
        alg_root_top = rt_base;
        return ret_127;
    }
    (void)((v_key = alg_add(alg_add(alg_str(alg_property(v_op, "LineNumber")), alg_string(":bits:")), f_foldcase(NULL, (Value[]){alg_str(alg_property(v_op, "Lexeme"))}, 1))));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Warned"), "Contains", (Value[]){v_key}, 1))) {
        Value ret_128 = alg_nil();
        alg_root_top = rt_base;
        return ret_128;
    }
    (void)(alg_invoke(alg_property(v_this, "Warned"), "Add", (Value[]){v_key}, 1));
    (void)(alg_invoke(alg_singleton(k_console), "Warn", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_invoke(alg_singleton(k_sourcecode), "Named", (Value[]){alg_str(alg_property(v_op, "File"))}, 1), alg_char_value(58)), alg_str(alg_property(v_op, "LineNumber"))), alg_string(": an operand of '")), alg_str(alg_property(v_op, "Lexeme"))), alg_string("' is an Integer, where '&', '|' and '~' ")), alg_string("are the bitwise operators."))}, 1));
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
    Value v_declaring = alg_nil();
    (void)v_declaring;
    alg_root(&v_declaring, 1);
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    if (alg_truthy(alg_equal(alg_str(alg_property(v_theexpr, "Extension")), alg_string("")))) {
        Value ret_130 = alg_nil();
        alg_root_top = rt_base;
        return ret_130;
    }
    (void)((v_declaring = alg_invoke(v_this, "DeclaresMember", (Value[]){v_owner, alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 2)));
    if (alg_truthy(alg_equal(v_declaring, alg_string("")))) {
        Value ret_131 = alg_nil();
        alg_root_top = rt_base;
        return ret_131;
    }
    (void)((v_key = alg_add(alg_add(alg_str(alg_property(alg_property(v_theexpr, "Name"), "LineNumber")), alg_string(":member:")), f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1))));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Warned"), "Contains", (Value[]){v_key}, 1))) {
        Value ret_132 = alg_nil();
        alg_root_top = rt_base;
        return ret_132;
    }
    (void)(alg_invoke(alg_property(v_this, "Warned"), "Add", (Value[]){v_key}, 1));
    (void)(alg_invoke(alg_singleton(k_console), "Warn", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_invoke(alg_singleton(k_sourcecode), "Named", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "File"))}, 1), alg_char_value(58)), alg_str(alg_property(alg_property(v_theexpr, "Name"), "LineNumber"))), alg_string(": '")), alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))), alg_string("' is a member of ")), v_declaring), alg_string(", so the extension of that name is not reached."))}, 1));
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
    Value v_kind = alg_nil();
    (void)v_kind;
    alg_root(&v_kind, 1);
    if (alg_truthy(alg_equal(v_theexpr, alg_nil()))) {
        Value ret_134 = alg_string("");
        alg_root_top = rt_base;
        return ret_134;
    }
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Cast"), alg_string("")))) {
        Value ret_135 = alg_property(v_theexpr, "Cast");
        alg_root_top = rt_base;
        return ret_135;
    }
    (void)((v_kind = alg_invoke(v_this, "ClassNameOf", (Value[]){v_theexpr}, 1)));
    if (alg_truthy(alg_equal(v_kind, alg_string("LiteralExpr")))) {
        Value ret_136 = alg_invoke(v_this, "TypeOfValue", (Value[]){alg_property(v_theexpr, "Value")}, 1);
        alg_root_top = rt_base;
        return ret_136;
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("GroupingExpr")))) {
        Value ret_137 = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Expression")}, 1);
        alg_root_top = rt_base;
        return ret_137;
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("VariableExpr")))) {
        {
            int32_t rt_367 = alg_root_top;
            Value v_written = alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1);
            (void)v_written;
            alg_root(&v_written, 1);
            if (alg_truthy(alg_not_equal(v_written, alg_string("")))) {
                Value ret_138 = v_written;
                alg_root_top = rt_base;
                return ret_138;
            }
            if (alg_truthy(alg_not_equal(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"), alg_string("")))) {
                {
                    int32_t rt_368 = alg_root_top;
                    Value v_owner = alg_str(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"));
                    (void)v_owner;
                    alg_root(&v_owner, 1);
                    while (alg_truthy(alg_not_equal(v_owner, alg_string("")))) {
                        alg_safe_point();
                        {
                            int32_t rt_369 = alg_root_top;
                            Value v_asfield = alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_add(alg_add(v_owner, alg_string("::")), alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme")))}, 1);
                            (void)v_asfield;
                            alg_root(&v_asfield, 1);
                            if (alg_truthy(alg_not_equal(v_asfield, alg_string("")))) {
                                Value ret_139 = v_asfield;
                                alg_root_top = rt_base;
                                return ret_139;
                            }
                            if (alg_truthy(alg_not(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Contains", (Value[]){v_owner}, 1)))) {
                                (void)((v_owner = alg_string("")));
                            } else {
                                (void)((v_owner = alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_owner}, 1))));
                            }
                            alg_root_top = rt_369;
                        }
                    }
                    alg_root_top = rt_368;
                }
            }
            Value ret_140 = alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Inferred"), "GetType", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1);
            alg_root_top = rt_base;
            return ret_140;
            alg_root_top = rt_367;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("UnaryExpr")))) {
        {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVnot))) {
                {
                    (void)(alg_invoke(v_this, "WarnIfBitwiseMeant", (Value[]){alg_property(v_theexpr, "Op"), alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Right")}, 1)}, 2));
                    Value ret_141 = alg_string("Boolean");
                    alg_root_top = rt_base;
                    return ret_141;
                }
            }
            Value ret_142 = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Right")}, 1);
            alg_root_top = rt_base;
            return ret_142;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("IsExpr")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
            if (alg_truthy(alg_not(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "DeclaredTypes"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){f_canonicaltype(NULL, (Value[]){alg_property(alg_property(v_theexpr, "TypeName"), "Lexeme")}, 1)}, 1)}, 1)))) {
                {
                    int32_t rt_370 = alg_root_top;
                    Value v_message = alg_add(alg_add(alg_string("Unknown type '"), alg_str(alg_property(alg_property(v_theexpr, "TypeName"), "Lexeme"))), alg_string("'."));
                    (void)v_message;
                    alg_root(&v_message, 1);
                    (void)(alg_invoke(alg_singleton(k_console), "Error", (Value[]){alg_property(v_theexpr, "TypeName"), v_message}, 2));
                    alg_raise(v_message);
                    alg_root_top = rt_370;
                }
            }
            Value ret_143 = alg_string("Boolean");
            alg_root_top = rt_base;
            return ret_143;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("BinaryExpr")))) {
        Value ret_144 = alg_invoke(v_this, "ReduceBinary", (Value[]){v_theexpr}, 1);
        alg_root_top = rt_base;
        return ret_144;
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("LogicalExpr")))) {
        {
            int32_t rt_371 = alg_root_top;
            Value v_side = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Left")}, 1);
            (void)v_side;
            alg_root(&v_side, 1);
            (void)(alg_invoke(v_this, "WarnIfBitwiseMeant", (Value[]){alg_property(v_theexpr, "Op"), v_side}, 2));
            (void)(alg_invoke(v_this, "WarnIfBitwiseMeant", (Value[]){alg_property(v_theexpr, "Op"), alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Right")}, 1)}, 2));
            Value ret_145 = v_side;
            alg_root_top = rt_base;
            return ret_145;
            alg_root_top = rt_371;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("AssignExpr")))) {
        {
            int32_t rt_372 = alg_root_top;
            Value v_declared = alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_property(alg_property(v_theexpr, "Name"), "Lexeme")}, 1);
            (void)v_declared;
            alg_root(&v_declared, 1);
            Value v_actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Value")}, 1);
            (void)v_actual;
            alg_root(&v_actual, 1);
            if (alg_truthy((or_26 = alg_not_equal(v_declared, alg_string("")), !alg_truthy(or_26) ? or_26 : alg_not_equal(v_declared, alg_string("Any"))))) {
                if (alg_truthy((or_28 = (or_27 = alg_equal(v_actual, alg_string("")), alg_truthy(or_27) ? or_27 : alg_equal(v_actual, alg_string("Any"))), alg_truthy(or_28) ? or_28 : alg_not(alg_invoke(v_this, "Assignable", (Value[]){v_declared, v_actual}, 2))))) {
                    alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_property(v_theexpr, "Name"), v_declared, v_actual}, 3));
                }
            }
            (void)(alg_set_property(v_theexpr, "Declared", v_declared));
            (void)(alg_set_property(v_theexpr, "Actual", v_actual));
            Value ret_146 = v_declared;
            alg_root_top = rt_base;
            return ret_146;
            alg_root_top = rt_372;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("CallExpr")))) {
        {
            int32_t rt_373 = alg_root_top;
            Value v_argtypes = alg_list();
            (void)v_argtypes;
            alg_root(&v_argtypes, 1);
            {
                int32_t rt_374 = alg_root_top;
                Value loop_147 = alg_iterable(alg_property(v_theexpr, "Arguments"));
                (void)loop_147;
                alg_root(&loop_147, 1);
                for (int32_t at_147 = 0; at_147 < alg_iterable_count(loop_147); at_147++) {
                    alg_safe_point();
                    int32_t rt_375 = alg_root_top;
                    Value v_argument = alg_iterable_at(loop_147, at_147);
                    (void)v_argument;
                    alg_root(&v_argument, 1);
                    (void)(alg_invoke(v_argtypes, "Add", (Value[]){alg_invoke(v_this, "Reduce", (Value[]){v_argument}, 1)}, 1));
                    alg_root_top = rt_375;
                }
                alg_root_top = rt_374;
            }
            (void)(alg_invoke(v_this, "WarnIfDynamic", (Value[]){v_theexpr}, 1));
            (void)(alg_invoke(v_this, "WarnIfNoArity", (Value[]){v_theexpr}, 1));
            if (alg_truthy(alg_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_property(v_theexpr, "Callee")}, 1), alg_string("GetExpr")))) {
                {
                    int32_t rt_376 = alg_root_top;
                    Value v_at = alg_invoke(v_this, "InsertedAt", (Value[]){alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme"))}, 1);
                    (void)v_at;
                    alg_root(&v_at, 1);
                    if (alg_truthy((or_29 = alg_greater_equal(v_at, alg_int(0)), !alg_truthy(or_29) ? or_29 : alg_less(v_at, alg_property(v_argtypes, "Length"))))) {
                        (void)(alg_invoke(v_this, "CheckElement", (Value[]){alg_invoke(v_this, "ElementOf", (Value[]){alg_property(alg_property(v_theexpr, "Callee"), "Obj")}, 1), alg_str(alg_subscript_get(v_argtypes, v_at)), alg_property(alg_property(v_theexpr, "Callee"), "Name")}, 3));
                    }
                    alg_root_top = rt_376;
                }
            }
            Value ret_148 = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Callee")}, 1);
            alg_root_top = rt_base;
            return ret_148;
            alg_root_top = rt_373;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("GetExpr")))) {
        {
            int32_t rt_377 = alg_root_top;
            if (alg_truthy(alg_equal(alg_property(v_theexpr, "Unit"), alg_string("System")))) {
                {
                    if (alg_truthy(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1))) {
                        Value ret_149 = alg_str(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Get", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1));
                        alg_root_top = rt_base;
                        return ret_149;
                    }
                    Value ret_150 = alg_string("");
                    alg_root_top = rt_base;
                    return ret_150;
                }
            }
            if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Unit"), alg_string("")))) {
                Value ret_151 = alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1);
                alg_root_top = rt_base;
                return ret_151;
            }
            (void)(alg_invoke(v_this, "CheckVisibility", (Value[]){alg_property(v_theexpr, "Obj"), alg_property(v_theexpr, "Name")}, 2));
            Value v_owner = alg_invoke(v_this, "TypeOfReceiver", (Value[]){alg_property(v_theexpr, "Obj")}, 1);
            (void)v_owner;
            alg_root(&v_owner, 1);
            if (alg_truthy((or_30 = alg_equal(v_owner, alg_string("")), alg_truthy(or_30) ? or_30 : alg_equal(v_owner, alg_string("Any"))))) {
                Value ret_152 = alg_string("");
                alg_root_top = rt_base;
                return ret_152;
            }
            (void)(alg_invoke(v_this, "WarnIfShadowed", (Value[]){v_theexpr, v_owner}, 2));
            Value ret_153 = alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_add(alg_add(v_owner, alg_string("::")), alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1);
            alg_root_top = rt_base;
            return ret_153;
            alg_root_top = rt_377;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("SetExpr")))) {
        {
            int32_t rt_378 = alg_root_top;
            if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Unit"), alg_string("")))) {
                Value ret_154 = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Value")}, 1);
                alg_root_top = rt_base;
                return ret_154;
            }
            (void)(alg_invoke(v_this, "CheckVisibility", (Value[]){alg_property(v_theexpr, "Obj"), alg_property(v_theexpr, "Name")}, 2));
            Value v_owner = alg_invoke(v_this, "TypeOfReceiver", (Value[]){alg_property(v_theexpr, "Obj")}, 1);
            (void)v_owner;
            alg_root(&v_owner, 1);
            Value v_actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Value")}, 1);
            (void)v_actual;
            alg_root(&v_actual, 1);
            if (alg_truthy((or_31 = alg_equal(v_owner, alg_string("")), !alg_truthy(or_31) ? or_31 : alg_is(alg_property(v_theexpr, "Obj"), "ThisExpr")))) {
                (void)((v_owner = alg_str(alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"))));
            }
            if (alg_truthy((or_32 = alg_not_equal(v_owner, alg_string("")), !alg_truthy(or_32) ? or_32 : alg_not_equal(v_owner, alg_string("Any"))))) {
                {
                    int32_t rt_379 = alg_root_top;
                    Value v_declaring = alg_invoke(v_this, "DeclaresProperty", (Value[]){v_owner, alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 2);
                    (void)v_declaring;
                    alg_root(&v_declaring, 1);
                    if (alg_truthy(alg_not_equal(v_declaring, alg_string("")))) {
                        alg_raise(alg_add(alg_add(alg_add(alg_add(alg_char_value(39), alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))), alg_string("' is a property of ")), v_declaring), alg_string(" and cannot be assigned.")));
                    }
                    Value v_declared = alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_add(alg_add(v_owner, alg_string("::")), alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1);
                    (void)v_declared;
                    alg_root(&v_declared, 1);
                    if (alg_truthy((or_34 = (or_33 = alg_not_equal(v_declared, alg_string("")), !alg_truthy(or_33) ? or_33 : alg_not_equal(v_declared, alg_string("Any"))), !alg_truthy(or_34) ? or_34 : alg_not_equal(v_actual, alg_string(""))))) {
                        if (alg_truthy((or_35 = alg_equal(v_actual, alg_string("Any")), alg_truthy(or_35) ? or_35 : alg_not(alg_invoke(v_this, "Assignable", (Value[]){v_declared, v_actual}, 2))))) {
                            alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_property(v_theexpr, "Name"), v_declared, v_actual}, 3));
                        }
                    }
                    (void)(alg_set_property(v_theexpr, "Declared", v_declared));
                    (void)(alg_set_property(v_theexpr, "Actual", v_actual));
                    alg_root_top = rt_379;
                }
            }
            Value ret_155 = v_actual;
            alg_root_top = rt_base;
            return ret_155;
            alg_root_top = rt_378;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("ThisExpr")))) {
        Value ret_156 = alg_string("");
        alg_root_top = rt_base;
        return ret_156;
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("CollectionExpr")))) {
        {
            {
                int32_t rt_380 = alg_root_top;
                Value loop_157 = alg_iterable(alg_property(v_theexpr, "Values"));
                (void)loop_157;
                alg_root(&loop_157, 1);
                for (int32_t at_157 = 0; at_157 < alg_iterable_count(loop_157); at_157++) {
                    alg_safe_point();
                    int32_t rt_381 = alg_root_top;
                    Value v_thevalue = alg_iterable_at(loop_157, at_157);
                    (void)v_thevalue;
                    alg_root(&v_thevalue, 1);
                    (void)(alg_invoke(v_this, "Reduce", (Value[]){v_thevalue}, 1));
                    alg_root_top = rt_381;
                }
                alg_root_top = rt_380;
            }
            if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
                Value ret_158 = alg_string("Map");
                alg_root_top = rt_base;
                return ret_158;
            }
            Value ret_159 = alg_string("List");
            alg_root_top = rt_base;
            return ret_159;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("SubscriptExpr")))) {
        {
            int32_t rt_382 = alg_root_top;
            Value v_owner = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Obj")}, 1);
            (void)v_owner;
            alg_root(&v_owner, 1);
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Index")}, 1));
            if (alg_truthy(alg_invoke(v_this, "IsTextType", (Value[]){v_owner}, 1))) {
                Value ret_160 = alg_string("Char");
                alg_root_top = rt_base;
                return ret_160;
            }
            if (alg_truthy(alg_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_property(v_theexpr, "Obj")}, 1), alg_string("VariableExpr")))) {
                Value ret_161 = alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "GetType", (Value[]){alg_str(alg_property(alg_property(alg_property(v_theexpr, "Obj"), "Name"), "Lexeme"))}, 1);
                alg_root_top = rt_base;
                return ret_161;
            }
            Value ret_162 = alg_string("");
            alg_root_top = rt_base;
            return ret_162;
            alg_root_top = rt_382;
        }
    }
    if (alg_truthy(alg_equal(v_kind, alg_string("SetSubscriptExpr")))) {
        {
            int32_t rt_383 = alg_root_top;
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Obj")}, 1));
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Index")}, 1));
            Value v_stored = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Value")}, 1);
            (void)v_stored;
            alg_root(&v_stored, 1);
            (void)(alg_invoke(v_this, "CheckElement", (Value[]){alg_invoke(v_this, "ElementOf", (Value[]){alg_property(v_theexpr, "Obj")}, 1), v_stored, alg_property(v_theexpr, "Bracket")}, 3));
            Value ret_163 = v_stored;
            alg_root_top = rt_base;
            return ret_163;
            alg_root_top = rt_383;
        }
    }
    Value ret_164 = alg_string("");
    alg_root_top = rt_base;
    return ret_164;
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
    Value v_left = alg_nil();
    (void)v_left;
    alg_root(&v_left, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    Value v_op = alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken");
    (void)v_op;
    alg_root(&v_op, 1);
    if (alg_truthy((or_40 = (or_39 = (or_38 = (or_37 = (or_36 = alg_equal(v_op, e_tokentype_tokenVgreater), alg_truthy(or_36) ? or_36 : alg_equal(v_op, e_tokentype_tokenVgreaterVequal)), alg_truthy(or_37) ? or_37 : alg_equal(v_op, e_tokentype_tokenVless)), alg_truthy(or_38) ? or_38 : alg_equal(v_op, e_tokentype_tokenVlessVequal)), alg_truthy(or_39) ? or_39 : alg_equal(v_op, e_tokentype_tokenVequal)), alg_truthy(or_40) ? or_40 : alg_equal(v_op, e_tokentype_tokenVnotVequal)))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Left")}, 1));
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Right")}, 1));
            Value ret_166 = alg_string("Boolean");
            alg_root_top = rt_base;
            return ret_166;
        }
    }
    (void)((v_left = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Left")}, 1)));
    (void)((v_right = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_theexpr, "Right")}, 1)));
    if (alg_truthy((or_43 = (or_42 = (or_41 = alg_equal(v_left, alg_string("")), alg_truthy(or_41) ? or_41 : alg_equal(v_right, alg_string(""))), alg_truthy(or_42) ? or_42 : alg_equal(v_left, alg_string("Any"))), alg_truthy(or_43) ? or_43 : alg_equal(v_right, alg_string("Any"))))) {
        Value ret_167 = alg_string("");
        alg_root_top = rt_base;
        return ret_167;
    }
    if (alg_truthy(alg_equal(v_op, e_tokentype_tokenVin))) {
        Value ret_168 = alg_string("Boolean");
        alg_root_top = rt_base;
        return ret_168;
    }
    if (alg_truthy((or_45 = alg_equal(v_op, e_tokentype_tokenVplus), !alg_truthy(or_45) ? or_45 : ((or_44 = alg_invoke(v_this, "IsTextType", (Value[]){v_left}, 1), alg_truthy(or_44) ? or_44 : alg_invoke(v_this, "IsTextType", (Value[]){v_right}, 1)))))) {
        Value ret_169 = alg_string("String");
        alg_root_top = rt_base;
        return ret_169;
    }
    if (alg_truthy(alg_equal(v_op, e_tokentype_tokenVslash))) {
        Value ret_170 = alg_string("Double");
        alg_root_top = rt_base;
        return ret_170;
    }
    if (alg_truthy((or_46 = alg_equal(v_op, e_tokentype_tokenVdiv), alg_truthy(or_46) ? or_46 : alg_equal(v_op, e_tokentype_tokenVmod)))) {
        Value ret_171 = alg_string("Integer");
        alg_root_top = rt_base;
        return ret_171;
    }
    if (alg_truthy((or_47 = alg_equal(v_left, alg_string("Double")), alg_truthy(or_47) ? or_47 : alg_equal(v_right, alg_string("Double"))))) {
        Value ret_172 = alg_string("Double");
        alg_root_top = rt_base;
        return ret_172;
    }
    if (alg_truthy(alg_equal(v_left, v_right))) {
        Value ret_173 = v_left;
        alg_root_top = rt_base;
        return ret_173;
    }
    Value ret_174 = alg_string("");
    alg_root_top = rt_base;
    return ret_174;
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
    Value ret_176 = (or_48 = alg_equal(v_thetype, alg_string("String")), alg_truthy(or_48) ? or_48 : alg_equal(v_thetype, alg_string("Char")));
    alg_root_top = rt_base;
    return ret_176;
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
    if (alg_truthy(alg_equal(v_value, alg_nil()))) {
        Value ret_178 = alg_string("Nil");
        alg_root_top = rt_base;
        return ret_178;
    }
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_BOOLEAN))) {
        Value ret_179 = alg_string("Boolean");
        alg_root_top = rt_base;
        return ret_179;
    }
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_INTEGER))) {
        Value ret_180 = alg_string("Integer");
        alg_root_top = rt_base;
        return ret_180;
    }
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_DOUBLE))) {
        Value ret_181 = alg_string("Double");
        alg_root_top = rt_base;
        return ret_181;
    }
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_CHAR))) {
        Value ret_182 = alg_string("Char");
        alg_root_top = rt_base;
        return ret_182;
    }
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_STRING))) {
        Value ret_183 = alg_string("String");
        alg_root_top = rt_base;
        return ret_183;
    }
    Value ret_184 = alg_invoke(v_this, "ClassNameOf", (Value[]){v_value}, 1);
    alg_root_top = rt_base;
    return ret_184;
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
    {
        AlgFrame frame_186;
        alg_push_frame(&frame_186);
        if (ALG_SETJMP(frame_186.jump) == 0) {
            {
                volatile Value ret_187 = alg_property(v_obj, "ClassName");
                alg_pop_frame();
                alg_root_top = rt_base;
                return ret_187;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_186[] = {"String"};
            int32_t which_186 = alg_handler(frame_186.raised, names_186, 1);
            if (which_186 == 0) {
                {
                    int32_t rt_384 = alg_root_top;
                    volatile Value v_e = frame_186.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_188 = alg_string("");
                    alg_root_top = rt_base;
                    return ret_188;
                    alg_root_top = rt_384;
                }
            }
            else {
                alg_raise(frame_186.raised);
            }
        }
    }
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
    volatile Value v_thescanner = alg_new(k_scanner, (Value[]){v_source}, 1);
    (void)v_thescanner;
    alg_root(&v_thescanner, 1);
    volatile Value v_theparser = alg_new(k_parser, (Value[]){alg_invoke(v_thescanner, "ScanTokens", NULL, 0)}, 1);
    (void)v_theparser;
    alg_root(&v_theparser, 1);
    {
        AlgFrame frame_190;
        alg_push_frame(&frame_190);
        if (ALG_SETJMP(frame_190.jump) == 0) {
            {
                (void)(alg_invoke(alg_new(k_typechecker, NULL, 0), "Resolve", (Value[]){alg_invoke(v_theparser, "Parse", NULL, 0)}, 1));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_190[] = {"String"};
            int32_t which_190 = alg_handler(frame_190.raised, names_190, 1);
            if (which_190 == 0) {
                {
                    int32_t rt_385 = alg_root_top;
                    volatile Value v_e = frame_190.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_191 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_191;
                    alg_root_top = rt_385;
                }
            }
            else {
                alg_raise(frame_190.raised);
            }
        }
    }
    volatile Value ret_192 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_192;
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
    Value v_thescanner = alg_new(k_scanner, (Value[]){v_source}, 1);
    (void)v_thescanner;
    alg_root(&v_thescanner, 1);
    Value v_theparser = alg_new(k_parser, (Value[]){alg_invoke(v_thescanner, "ScanTokens", NULL, 0)}, 1);
    (void)v_theparser;
    alg_root(&v_theparser, 1);
    Value v_thechecker = alg_new(k_typechecker, NULL, 0);
    (void)v_thechecker;
    alg_root(&v_thechecker, 1);
    (void)(alg_invoke(v_thechecker, "Resolve", (Value[]){alg_invoke(v_theparser, "Parse", NULL, 0)}, 1));
    Value ret_194 = alg_invoke(v_thechecker, "CandidatesFor", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1), v_count}, 2);
    alg_root_top = rt_base;
    return ret_194;
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
    fn_foldedbuiltins = alg_closure("FoldedBuiltins", f_foldedbuiltins, NULL, 0, 0, NULL);
    alg_class_field(k_typechecker, "Lookup");
    alg_class_field(k_typechecker, "CurrentReturn");
    alg_class_field(k_typechecker, "PrivateMembers");
    alg_class_field(k_typechecker, "PropertyMembers");
    alg_class_field(k_typechecker, "Members");
    alg_class_field(k_typechecker, "BuiltinTypes");
    alg_class_field(k_typechecker, "Overloads");
    alg_class_field(k_typechecker, "Arities");
    alg_class_field(k_typechecker, "Variadics");
    alg_class_field(k_typechecker, "Signatures");
    alg_class_field(k_typechecker, "Warned");
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
    v_builtinVnames = f_foldedbuiltins(NULL, NULL, 0);
    d_builtinVnames = true;
    v_hider = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("class Counter;"), alg_char_value(10)), alg_string("private:")), alg_char_value(10)), alg_string("    var Count : Integer := 0;")), alg_char_value(10)), alg_string("begin")), alg_char_value(10)), alg_string("    procedure Bump();")), alg_char_value(10)), alg_string("    begin")), alg_char_value(10)), alg_string("        Count := Count + 1;")), alg_char_value(10)), alg_string("    end")), alg_char_value(10)), alg_string("private:")), alg_char_value(10)), alg_string("    procedure Advance();")), alg_char_value(10)), alg_string("    begin")), alg_char_value(10)), alg_string("    end")), alg_char_value(10)), alg_string("end")), alg_char_value(10));
    d_hider = true;
}
