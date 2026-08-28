/* Generated from Algol-24.  Do not edit. */
#include "TypeChecker.h"
#include "Console.h"
#include "Interpreter.h"
#include "Parser.h"
#include "Scanner.h"
#include "Token.h"
#include "TokenType.h"

Value f_Rejects(Value **cells, Value *args, int32_t count);
Value k_TypeLookup;
static const char *t_TypeLookup_SetType_2_String_String[] = { "String", "String" };
static const char *t_TypeLookup_GetType_1_String[] = { "String" };
Value k_TypeChecker;
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
static const char *t_TypeChecker_HiddenBy_2_String_String[] = { "String", "String" };
static const char *t_TypeChecker_TypeOfReceiver_1[] = { "Any" };
static const char *t_TypeChecker_CheckVisibility_2_Token[] = { "Any", "Token" };
static const char *t_TypeChecker_Assignable_2_String_String[] = { "String", "String" };
static const char *t_TypeChecker_Mismatch_3_Token_String_String[] = { "Token", "String", "String" };
static const char *t_TypeChecker_Resolve_1_List[] = { "List" };
static const char *t_TypeChecker_MapType_1[] = { "Any" };
static const char *t_TypeChecker_Check_1[] = { "Any" };
static const char *t_TypeChecker_CheckFunction_1[] = { "Any" };
static const char *t_TypeChecker_Reduce_1[] = { "Any" };
static const char *t_TypeChecker_ReduceBinary_1[] = { "Any" };
static const char *t_TypeChecker_IsTextType_1_String[] = { "String" };
static const char *t_TypeChecker_TypeOfValue_1[] = { "Any" };
static const char *t_TypeChecker_ClassNameOf_1[] = { "Any" };
Value fn_Rejects;
Value v_HIDER;

static Value i_TypeLookup(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Scopes", alg_list());
    alg_set_property(v_this, "Types", alg_map());
    alg_set_property(v_this, "Parents", alg_map());
    alg_set_property(v_this, "Inferred", alg_map());
    alg_set_property(v_this, "Generics", alg_nil());
    alg_set_property(v_this, "CurrentClassName", alg_string(""));
    return alg_nil();
}

static Value m_TypeLookup_SetType_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Symbol = args[0];
    (void)v_Symbol;
    Value v_TheType = args[1];
    (void)v_TheType;
    if (alg_truthy(alg_property(alg_property(v_this, "Scopes"), "IsEmpty"))) {
        (void)(alg_invoke(alg_property(v_this, "Types"), "Put", (Value[]){v_Symbol, v_TheType}, 2));
    } else {
        (void)(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1))), "Put", (Value[]){v_Symbol, v_TheType}, 2));
    }
    return alg_nil();
}

static Value m_TypeLookup_GetType_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Symbol = args[0];
    (void)v_Symbol;
    {
        Value v_I = alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1));
        (void)v_I;
        while (alg_truthy(alg_greater_equal(v_I, alg_int(0)))) {
            {
                if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), v_I), "Contains", (Value[]){v_Symbol}, 1))) {
                    return alg_str(alg_invoke(alg_subscript_get(alg_property(v_this, "Scopes"), v_I), "Get", (Value[]){v_Symbol}, 1));
                }
                (void)((v_I = alg_subtract(v_I, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Types"), "Contains", (Value[]){v_Symbol}, 1))) {
        return alg_str(alg_invoke(alg_property(v_this, "Types"), "Get", (Value[]){v_Symbol}, 1));
    }
    return alg_string("");
    return alg_nil();
}

static Value m_TypeLookup_BeginScope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_invoke(alg_property(v_this, "Scopes"), "Add", (Value[]){alg_map()}, 1));
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Generics"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Generics"), "BeginScope", NULL, 0));
    }
    return alg_nil();
}

static Value m_TypeLookup_EndScope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_invoke(alg_property(v_this, "Scopes"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "Scopes"), "Length"), alg_int(1))}, 1));
    if (alg_truthy(alg_not_equal(alg_property(v_this, "Generics"), alg_nil()))) {
        (void)(alg_invoke(alg_property(v_this, "Generics"), "EndScope", NULL, 0));
    }
    return alg_nil();
}

static Value i_TypeChecker(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Lookup", alg_nil());
    alg_set_property(v_this, "CurrentReturn", alg_string(""));
    alg_set_property(v_this, "PrivateMembers", alg_map());
    alg_set_property(v_this, "BuiltinTypes", alg_map());
    return alg_nil();
}

static Value m_TypeChecker_Init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_set_property(v_this, "Lookup", alg_new(k_TypeLookup, NULL, 0)));
    (void)(alg_set_property(alg_property(v_this, "Lookup"), "Generics", alg_new(k_TypeLookup, NULL, 0)));
    {
        Value loop_0 = alg_iterable(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_string("List")), alg_string("Map")), alg_string("Set")), alg_string("Stack")), alg_string("Array")));
        for (int32_t at_0 = 0; at_0 < alg_iterable_count(loop_0); at_0++) {
            Value v_Kind = alg_iterable_at(loop_0, at_0);
            (void)v_Kind;
            {
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(v_Kind, alg_string("::Length")), alg_string("Integer")}, 2));
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(v_Kind, alg_string("::IsEmpty")), alg_string("Boolean")}, 2));
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(v_Kind, alg_string("::Contains")), alg_string("Boolean")}, 2));
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
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Val"), alg_string("Double")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Char"), alg_string("Char")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Max"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("Mod"), alg_string("Integer")}, 2));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_string("clock"), alg_string("Double")}, 2));
    {
        Value loop_1 = alg_iterable(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_string("Length")), alg_string("Pos")), alg_string("Copy")), alg_string("Str")), alg_string("Array")), alg_string("List")), alg_string("Map")), alg_string("Set")), alg_string("Stack")), alg_string("Buffer")), alg_string("TextFile")), alg_string("FileExists")), alg_string("ParamCount")), alg_string("ParamStr")), alg_string("Write")), alg_string("WriteLn")), alg_string("Ord")), alg_string("Val")), alg_string("Char")), alg_string("Max")), alg_string("Mod")), alg_string("clock")));
        for (int32_t at_1 = 0; at_1 < alg_iterable_count(loop_1); at_1++) {
            Value v_Name = alg_iterable_at(loop_1, at_1);
            (void)v_Name;
            (void)(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Put", (Value[]){v_Name, alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){v_Name}, 1)}, 2));
        }
    }
    return alg_nil();
}

static Value m_TypeChecker_HiddenBy_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheType = args[0];
    (void)v_TheType;
    Value v_Member = args[1];
    (void)v_Member;
    Value v_At = alg_nil();
    (void)v_At;
    Value v_Seen = alg_nil();
    (void)v_Seen;
    (void)((v_At = v_TheType));
    (void)((v_Seen = alg_list()));
    while (alg_truthy((or_1 = (or_0 = alg_not_equal(v_At, alg_string("")), !alg_truthy(or_0) ? or_0 : alg_not_equal(v_At, alg_string("Any"))), !alg_truthy(or_1) ? or_1 : alg_not(alg_invoke(v_Seen, "Contains", (Value[]){v_At}, 1))))) {
        {
            (void)(alg_invoke(v_Seen, "Add", (Value[]){v_At}, 1));
            if (alg_truthy(alg_invoke(alg_property(v_this, "PrivateMembers"), "Contains", (Value[]){v_At}, 1))) {
                if (alg_truthy(alg_invoke(alg_invoke(alg_property(v_this, "PrivateMembers"), "Get", (Value[]){v_At}, 1), "Contains", (Value[]){v_Member}, 1))) {
                    return v_At;
                }
            }
            (void)((v_At = alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_At}, 1))));
            if (alg_truthy(alg_equal(v_At, alg_string("nil")))) {
                (void)((v_At = alg_string("")));
            }
        }
    }
    return alg_string("");
    return alg_nil();
}

static Value m_TypeChecker_TypeOfReceiver_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Obj = args[0];
    (void)v_Obj;
    Value v_TheType = alg_nil();
    (void)v_TheType;
    (void)((v_TheType = alg_invoke(v_this, "Reduce", (Value[]){v_Obj}, 1)));
    if (alg_truthy((or_3 = ((or_2 = alg_equal(v_TheType, alg_string("")), alg_truthy(or_2) ? or_2 : alg_equal(v_TheType, alg_string("Any")))), !alg_truthy(or_3) ? or_3 : alg_is(v_Obj, "VariableExpr")))) {
        {
            Value v_Deduced = alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Inferred"), "Get", (Value[]){alg_str(alg_property(alg_property(v_Obj, "Name"), "Lexeme"))}, 1));
            (void)v_Deduced;
            if (alg_truthy((or_4 = alg_not_equal(v_Deduced, alg_string("nil")), !alg_truthy(or_4) ? or_4 : alg_not_equal(v_Deduced, alg_string(""))))) {
                return v_Deduced;
            }
        }
    }
    return v_TheType;
    return alg_nil();
}

static Value m_TypeChecker_CheckVisibility_2_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Obj = args[0];
    (void)v_Obj;
    Value v_Member = args[1];
    (void)v_Member;
    Value v_TheType = alg_nil();
    (void)v_TheType;
    (void)((v_TheType = alg_invoke(v_this, "TypeOfReceiver", (Value[]){v_Obj}, 1)));
    Value v_Owner = alg_invoke(v_this, "HiddenBy", (Value[]){v_TheType, alg_str(alg_property(v_Member, "Lexeme"))}, 2);
    (void)v_Owner;
    if (alg_truthy((or_5 = alg_equal(v_Owner, alg_string("")), alg_truthy(or_5) ? or_5 : alg_equal(v_Owner, alg_property(alg_property(v_this, "Lookup"), "CurrentClassName"))))) {
        return alg_nil();
    }
    alg_raise(alg_add(alg_add(alg_add(alg_add(alg_string("'"), alg_property(v_Member, "Lexeme")), alg_string("' is private to ")), v_Owner), alg_char_value(46)));
    return alg_nil();
}

static Value m_TypeChecker_Assignable_2_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Expected = args[0];
    (void)v_Expected;
    Value v_Actual = args[1];
    (void)v_Actual;
    Value v_Parent = alg_nil();
    (void)v_Parent;
    if (alg_truthy((or_6 = alg_equal(v_Expected, alg_string("")), alg_truthy(or_6) ? or_6 : alg_equal(v_Actual, alg_string(""))))) {
        return alg_bool(true);
    }
    if (alg_truthy((or_7 = alg_equal(v_Expected, alg_string("Any")), alg_truthy(or_7) ? or_7 : alg_equal(v_Actual, alg_string("Any"))))) {
        return alg_bool(true);
    }
    if (alg_truthy(alg_equal(v_Actual, alg_string("Nil")))) {
        return alg_bool(true);
    }
    if (alg_truthy(alg_equal(v_Expected, v_Actual))) {
        return alg_bool(true);
    }
    if (alg_truthy((or_8 = alg_equal(v_Expected, alg_string("Double")), !alg_truthy(or_8) ? or_8 : alg_equal(v_Actual, alg_string("Integer"))))) {
        return alg_bool(true);
    }
    if (alg_truthy((or_9 = alg_equal(v_Expected, alg_string("String")), !alg_truthy(or_9) ? or_9 : alg_equal(v_Actual, alg_string("Char"))))) {
        return alg_bool(true);
    }
    (void)((v_Parent = alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_Actual}, 1))));
    while (alg_truthy((or_10 = alg_not_equal(v_Parent, alg_string("")), !alg_truthy(or_10) ? or_10 : alg_not_equal(v_Parent, alg_string("nil"))))) {
        {
            if (alg_truthy(alg_equal(v_Expected, v_Parent))) {
                return alg_bool(true);
            }
            (void)((v_Parent = alg_str(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Get", (Value[]){v_Parent}, 1))));
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value m_TypeChecker_Mismatch_3_Token_String_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Where = args[0];
    (void)v_Where;
    Value v_Expected = args[1];
    (void)v_Expected;
    Value v_Actual = args[2];
    (void)v_Actual;
    Value v_Found = alg_nil();
    (void)v_Found;
    Value v_Message = alg_nil();
    (void)v_Message;
    (void)((v_Found = v_Actual));
    if (alg_truthy(alg_equal(v_Actual, alg_string("")))) {
        (void)((v_Found = alg_string("an untyped expression")));
    }
    (void)((v_Message = alg_add(alg_add(alg_add(alg_add(alg_string("Expected "), v_Expected), alg_string(", found ")), v_Found), alg_char_value(46))));
    (void)(alg_invoke(alg_singleton(k_Console), "Error", (Value[]){v_Where, v_Message}, 2));
    return v_Message;
    return alg_nil();
}

static Value m_TypeChecker_Resolve_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = args[0];
    (void)v_Statements;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Statements, "Length")))) {
            {
                (void)(alg_invoke(v_this, "MapType", (Value[]){alg_subscript_get(v_Statements, v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Statements, "Length")))) {
            {
                (void)(alg_invoke(v_this, "Check", (Value[]){alg_subscript_get(v_Statements, v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return alg_nil();
}

static Value m_TypeChecker_MapType_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Kind = alg_nil();
    (void)v_Kind;
    (void)((v_Kind = alg_invoke(v_this, "ClassNameOf", (Value[]){v_TheStmt}, 1)));
    if (alg_truthy(alg_equal(v_Kind, alg_string("ClassStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "PrivateMembers"), "Put", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")), alg_property(v_TheStmt, "PrivateMembers")}, 2));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")}, 2));
            if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Superclass"), alg_nil()))) {
                (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Put", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_property(alg_property(alg_property(v_TheStmt, "Superclass"), "Name"), "Lexeme")}, 2));
            }
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Fields"), "Length")))) {
                    {
                        {
                            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Fields"), v_I), "Name"), "Lexeme")), alg_property(alg_subscript_get(alg_property(v_TheStmt, "Fields"), v_I), "TypeName")}, 2));
                            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Fields"), v_I), "Name"), "Lexeme")), alg_property(alg_subscript_get(alg_property(v_TheStmt, "Fields"), v_I), "Generic")}, 2));
                        }
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Methods"), "Length")))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Methods"), v_I), "Name"), "Lexeme")), alg_property(alg_subscript_get(alg_property(v_TheStmt, "Methods"), v_I), "ReturnType")}, 2));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("ObjectStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "PrivateMembers"), "Put", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")), alg_property(v_TheStmt, "PrivateMembers")}, 2));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")}, 2));
            if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Superclass"), alg_nil()))) {
                (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Parents"), "Put", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_property(alg_property(alg_property(v_TheStmt, "Superclass"), "Name"), "Lexeme")}, 2));
            }
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Fields"), "Length")))) {
                    {
                        {
                            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Fields"), v_I), "Name"), "Lexeme")), alg_property(alg_subscript_get(alg_property(v_TheStmt, "Fields"), v_I), "TypeName")}, 2));
                            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Fields"), v_I), "Name"), "Lexeme")), alg_property(alg_subscript_get(alg_property(v_TheStmt, "Fields"), v_I), "Generic")}, 2));
                        }
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Methods"), "Length")))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Methods"), v_I), "Name"), "Lexeme")), alg_property(alg_subscript_get(alg_property(v_TheStmt, "Methods"), v_I), "ReturnType")}, 2));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("FunctionStmt")))) {
        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_property(v_TheStmt, "ReturnType")}, 2));
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("EnumStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")}, 2));
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Members"), "Length")))) {
                    {
                        {
                            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_subscript_get(alg_property(v_TheStmt, "Members"), v_I), "Lexeme"), alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")}, 2));
                            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_add(alg_add(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_string("::")), alg_property(alg_subscript_get(alg_property(v_TheStmt, "Members"), v_I), "Lexeme")), alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")}, 2));
                        }
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("VarStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_property(v_TheStmt, "TypeName")}, 2));
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")), alg_property(v_TheStmt, "Generic")}, 2));
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("VarGroupStmt")))) {
        {
            Value v_I = alg_int(0);
            (void)v_I;
            while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Names"), "Length")))) {
                {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_I), "Lexeme"), alg_property(v_TheStmt, "TypeName")}, 2));
                        (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_I), "Lexeme")), alg_property(v_TheStmt, "Generic")}, 2));
                    }
                    (void)((v_I = alg_add(v_I, alg_int(1))));
                }
            }
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("ModuleStmt")))) {
        if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Statements"), alg_nil()))) {
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Statements"), "Length")))) {
                    {
                        (void)(alg_invoke(v_this, "MapType", (Value[]){alg_subscript_get(alg_property(v_TheStmt, "Statements"), v_I)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
        }
    }
    return alg_nil();
}

static Value m_TypeChecker_Check_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheStmt = args[0];
    (void)v_TheStmt;
    Value v_Kind = alg_nil();
    (void)v_Kind;
    (void)((v_Kind = alg_invoke(v_this, "ClassNameOf", (Value[]){v_TheStmt}, 1)));
    if (alg_truthy(alg_equal(v_Kind, alg_string("VarStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), alg_property(v_TheStmt, "TypeName")}, 2));
            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")), alg_property(v_TheStmt, "Generic")}, 2));
            if (alg_truthy((or_11 = alg_not_equal(alg_property(v_TheStmt, "Initializer"), alg_nil()), !alg_truthy(or_11) ? or_11 : alg_equal(alg_property(v_TheStmt, "TypeName"), alg_string(""))))) {
                (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Inferred"), "Put", (Value[]){alg_str(alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")), alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheStmt, "Initializer")}, 1)}, 2));
            }
            if (alg_truthy((or_12 = alg_not_equal(alg_property(v_TheStmt, "Initializer"), alg_nil()), !alg_truthy(or_12) ? or_12 : alg_not_equal(alg_property(v_TheStmt, "TypeName"), alg_string(""))))) {
                {
                    Value v_Actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheStmt, "Initializer")}, 1);
                    (void)v_Actual;
                    if (alg_truthy((or_14 = (or_13 = alg_equal(v_Actual, alg_string("")), alg_truthy(or_13) ? or_13 : alg_equal(v_Actual, alg_string("Any"))), alg_truthy(or_14) ? or_14 : alg_not(alg_invoke(v_this, "Assignable", (Value[]){alg_property(v_TheStmt, "TypeName"), v_Actual}, 2))))) {
                        alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_property(v_TheStmt, "Name"), alg_property(v_TheStmt, "TypeName"), v_Actual}, 3));
                    }
                }
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("VarGroupStmt")))) {
        {
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Names"), "Length")))) {
                    {
                        {
                            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_I), "Lexeme"), alg_property(v_TheStmt, "TypeName")}, 2));
                            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_TheStmt, "Names"), v_I), "Lexeme")), alg_property(v_TheStmt, "Generic")}, 2));
                        }
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            if (alg_truthy((or_15 = alg_not_equal(alg_property(v_TheStmt, "Initializer"), alg_nil()), !alg_truthy(or_15) ? or_15 : alg_not_equal(alg_property(v_TheStmt, "TypeName"), alg_string(""))))) {
                {
                    Value v_Actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheStmt, "Initializer")}, 1);
                    (void)v_Actual;
                    if (alg_truthy((or_17 = (or_16 = alg_equal(v_Actual, alg_string("")), alg_truthy(or_16) ? or_16 : alg_equal(v_Actual, alg_string("Any"))), alg_truthy(or_17) ? or_17 : alg_not(alg_invoke(v_this, "Assignable", (Value[]){alg_property(v_TheStmt, "TypeName"), v_Actual}, 2))))) {
                        alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_subscript_get(alg_property(v_TheStmt, "Names"), alg_int(0)), alg_property(v_TheStmt, "TypeName"), v_Actual}, 3));
                    }
                }
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("ExpressionStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheStmt, "Expression")}, 1));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("PrintStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheStmt, "Expression")}, 1));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("BlockStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Statements"), "Length")))) {
                    {
                        (void)(alg_invoke(v_this, "Check", (Value[]){alg_subscript_get(alg_property(v_TheStmt, "Statements"), v_I)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("IfStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheStmt, "Condition")}, 1));
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_TheStmt, "ThenBranch")}, 1));
            if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "ElseBranch"), alg_nil()))) {
                (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_TheStmt, "ElseBranch")}, 1));
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("ForInStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheStmt, "Iterable")}, 1));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
            Value v_Element = alg_string("");
            (void)v_Element;
            if (alg_truthy(alg_is(alg_property(v_TheStmt, "Iterable"), "VariableExpr"))) {
                (void)((v_Element = alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "GetType", (Value[]){alg_str(alg_property(alg_property(alg_property(v_TheStmt, "Iterable"), "Name"), "Lexeme"))}, 1)));
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_TheStmt, "Name"), "Lexeme"), v_Element}, 2));
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_TheStmt, "Body")}, 1));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("WhileStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheStmt, "Condition")}, 1));
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_TheStmt, "Body")}, 1));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("ReturnStmt")))) {
        {
            if (alg_truthy(alg_not_equal(alg_property(v_TheStmt, "Value"), alg_nil()))) {
                {
                    Value v_Actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheStmt, "Value")}, 1);
                    (void)v_Actual;
                    if (alg_truthy(alg_not(alg_invoke(v_this, "Assignable", (Value[]){alg_property(v_this, "CurrentReturn"), v_Actual}, 2)))) {
                        alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_property(v_TheStmt, "Keyword"), alg_property(v_this, "CurrentReturn"), v_Actual}, 3));
                    }
                }
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("TryStmt")))) {
        {
            (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(v_TheStmt, "TryBlock")}, 1));
            Value v_Keys = alg_invoke(alg_property(v_TheStmt, "Handlers"), "Keys", NULL, 0);
            (void)v_Keys;
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(v_Keys, "Length")))) {
                    {
                        (void)(alg_invoke(v_this, "Check", (Value[]){alg_property(alg_invoke(alg_property(v_TheStmt, "Handlers"), "Get", (Value[]){alg_subscript_get(v_Keys, v_I)}, 1), "Body")}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("BreakStmt")))) {
        return alg_nil();
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("ModuleStmt")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_TheStmt, "Statements"), alg_nil()))) {
                return alg_nil();
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
            {
                Value loop_2 = alg_iterable(alg_property(v_this, "BuiltinTypes"));
                for (int32_t at_2 = 0; at_2 < alg_iterable_count(loop_2); at_2++) {
                    Value v_Name = alg_iterable_at(loop_2, at_2);
                    (void)v_Name;
                    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){v_Name, alg_str(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Get", (Value[]){v_Name}, 1))}, 2));
                }
            }
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Statements"), "Length")))) {
                    {
                        (void)(alg_invoke(v_this, "MapType", (Value[]){alg_subscript_get(alg_property(v_TheStmt, "Statements"), v_I)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Statements"), "Length")))) {
                    {
                        (void)(alg_invoke(v_this, "Check", (Value[]){alg_subscript_get(alg_property(v_TheStmt, "Statements"), v_I)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("RaiseStmt")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheStmt, "Value")}, 1));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("FunctionStmt")))) {
        {
            (void)(alg_invoke(v_this, "CheckFunction", (Value[]){v_TheStmt}, 1));
            return alg_nil();
        }
    }
    if (alg_truthy((or_18 = alg_equal(v_Kind, alg_string("ObjectStmt")), alg_truthy(or_18) ? or_18 : alg_equal(v_Kind, alg_string("ClassStmt"))))) {
        {
            Value v_Enclosing = alg_property(alg_property(v_this, "Lookup"), "CurrentClassName");
            (void)v_Enclosing;
            (void)(alg_set_property(alg_property(v_this, "Lookup"), "CurrentClassName", alg_property(alg_property(v_TheStmt, "Name"), "Lexeme")));
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Fields"), "Length")))) {
                    {
                        {
                            Value v_Field = alg_subscript_get(alg_property(v_TheStmt, "Fields"), v_I);
                            (void)v_Field;
                            (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(v_Field, "Name"), "Lexeme"), alg_property(v_Field, "TypeName")}, 2));
                            (void)(alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "SetType", (Value[]){alg_str(alg_property(alg_property(v_Field, "Name"), "Lexeme")), alg_property(v_Field, "Generic")}, 2));
                        }
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheStmt, "Methods"), "Length")))) {
                    {
                        (void)(alg_invoke(v_this, "CheckFunction", (Value[]){alg_subscript_get(alg_property(v_TheStmt, "Methods"), v_I)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
            (void)(alg_set_property(alg_property(v_this, "Lookup"), "CurrentClassName", v_Enclosing));
            return alg_nil();
        }
    }
    return alg_nil();
}

static Value m_TypeChecker_CheckFunction_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheFunction = args[0];
    (void)v_TheFunction;
    Value v_Enclosing = alg_nil();
    (void)v_Enclosing;
    (void)((v_Enclosing = alg_property(v_this, "CurrentReturn")));
    (void)(alg_set_property(v_this, "CurrentReturn", alg_property(v_TheFunction, "ReturnType")));
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "BeginScope", NULL, 0));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheFunction, "Params"), "Length")))) {
            {
                (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_subscript_get(alg_property(v_TheFunction, "Params"), v_I), "Lexeme"), alg_str(alg_subscript_get(alg_property(v_TheFunction, "ParamTypes"), v_I))}, 2));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheFunction, "Body"), "Length")))) {
            {
                if (alg_truthy(alg_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_subscript_get(alg_property(v_TheFunction, "Body"), v_I)}, 1), alg_string("FunctionStmt")))) {
                    (void)(alg_invoke(alg_property(v_this, "Lookup"), "SetType", (Value[]){alg_property(alg_property(alg_subscript_get(alg_property(v_TheFunction, "Body"), v_I), "Name"), "Lexeme"), alg_property(alg_subscript_get(alg_property(v_TheFunction, "Body"), v_I), "ReturnType")}, 2));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheFunction, "Body"), "Length")))) {
            {
                (void)(alg_invoke(v_this, "Check", (Value[]){alg_subscript_get(alg_property(v_TheFunction, "Body"), v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Lookup"), "EndScope", NULL, 0));
    (void)(alg_set_property(v_this, "CurrentReturn", v_Enclosing));
    return alg_nil();
}

static Value m_TypeChecker_Reduce_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Kind = alg_nil();
    (void)v_Kind;
    if (alg_truthy(alg_equal(v_TheExpr, alg_nil()))) {
        return alg_string("");
    }
    if (alg_truthy(alg_not_equal(alg_property(v_TheExpr, "Cast"), alg_string("")))) {
        return alg_property(v_TheExpr, "Cast");
    }
    (void)((v_Kind = alg_invoke(v_this, "ClassNameOf", (Value[]){v_TheExpr}, 1)));
    if (alg_truthy(alg_equal(v_Kind, alg_string("LiteralExpr")))) {
        return alg_invoke(v_this, "TypeOfValue", (Value[]){alg_property(v_TheExpr, "Value")}, 1);
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("GroupingExpr")))) {
        return alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Expression")}, 1);
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("VariableExpr")))) {
        return alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_property(alg_property(v_TheExpr, "Name"), "Lexeme")}, 1);
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("UnaryExpr")))) {
        {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken"), e_TokenType_TOKEN_NOT))) {
                return alg_string("Boolean");
            }
            return alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Right")}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("IsExpr")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Obj")}, 1));
            return alg_string("Boolean");
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("BinaryExpr")))) {
        return alg_invoke(v_this, "ReduceBinary", (Value[]){v_TheExpr}, 1);
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("LogicalExpr")))) {
        return alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Left")}, 1);
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("AssignExpr")))) {
        {
            Value v_Declared = alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_property(alg_property(v_TheExpr, "Name"), "Lexeme")}, 1);
            (void)v_Declared;
            Value v_Actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Value")}, 1);
            (void)v_Actual;
            if (alg_truthy(alg_not(alg_invoke(v_this, "Assignable", (Value[]){v_Declared, v_Actual}, 2)))) {
                alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_property(v_TheExpr, "Name"), v_Declared, v_Actual}, 3));
            }
            return v_Declared;
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("CallExpr")))) {
        {
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Arguments"), "Length")))) {
                    {
                        (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Arguments"), v_I)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Callee")}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("GetExpr")))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_TheExpr, "Unit"), alg_string("System")))) {
                {
                    if (alg_truthy(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_TheExpr, "Name"), "Lexeme"))}, 1))) {
                        return alg_str(alg_invoke(alg_property(v_this, "BuiltinTypes"), "Get", (Value[]){alg_str(alg_property(alg_property(v_TheExpr, "Name"), "Lexeme"))}, 1));
                    }
                    return alg_string("");
                }
            }
            if (alg_truthy(alg_not_equal(alg_property(v_TheExpr, "Unit"), alg_string("")))) {
                return alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_str(alg_property(alg_property(v_TheExpr, "Name"), "Lexeme"))}, 1);
            }
            (void)(alg_invoke(v_this, "CheckVisibility", (Value[]){alg_property(v_TheExpr, "Obj"), alg_property(v_TheExpr, "Name")}, 2));
            Value v_Owner = alg_invoke(v_this, "TypeOfReceiver", (Value[]){alg_property(v_TheExpr, "Obj")}, 1);
            (void)v_Owner;
            if (alg_truthy((or_19 = alg_equal(v_Owner, alg_string("")), alg_truthy(or_19) ? or_19 : alg_equal(v_Owner, alg_string("Any"))))) {
                return alg_string("");
            }
            return alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_add(alg_add(v_Owner, alg_string("::")), alg_property(alg_property(v_TheExpr, "Name"), "Lexeme"))}, 1);
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("SetExpr")))) {
        {
            if (alg_truthy(alg_not_equal(alg_property(v_TheExpr, "Unit"), alg_string("")))) {
                return alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Value")}, 1);
            }
            (void)(alg_invoke(v_this, "CheckVisibility", (Value[]){alg_property(v_TheExpr, "Obj"), alg_property(v_TheExpr, "Name")}, 2));
            Value v_Owner = alg_invoke(v_this, "TypeOfReceiver", (Value[]){alg_property(v_TheExpr, "Obj")}, 1);
            (void)v_Owner;
            Value v_Actual = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Value")}, 1);
            (void)v_Actual;
            if (alg_truthy((or_20 = alg_not_equal(v_Owner, alg_string("")), !alg_truthy(or_20) ? or_20 : alg_not_equal(v_Owner, alg_string("Any"))))) {
                {
                    Value v_Declared = alg_invoke(alg_property(v_this, "Lookup"), "GetType", (Value[]){alg_add(alg_add(v_Owner, alg_string("::")), alg_property(alg_property(v_TheExpr, "Name"), "Lexeme"))}, 1);
                    (void)v_Declared;
                    if (alg_truthy(alg_not(alg_invoke(v_this, "Assignable", (Value[]){v_Declared, v_Actual}, 2)))) {
                        alg_raise(alg_invoke(v_this, "Mismatch", (Value[]){alg_property(v_TheExpr, "Name"), v_Declared, v_Actual}, 3));
                    }
                }
            }
            return v_Actual;
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("ThisExpr")))) {
        return alg_string("");
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("CollectionExpr")))) {
        {
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_TheExpr, "Values"), "Length")))) {
                    {
                        (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_subscript_get(alg_property(v_TheExpr, "Values"), v_I)}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            if (alg_truthy(alg_property(v_TheExpr, "IsMap"))) {
                return alg_string("Map");
            }
            return alg_string("List");
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("SubscriptExpr")))) {
        {
            Value v_Owner = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Obj")}, 1);
            (void)v_Owner;
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Index")}, 1));
            if (alg_truthy(alg_invoke(v_this, "IsTextType", (Value[]){v_Owner}, 1))) {
                return alg_string("Char");
            }
            if (alg_truthy(alg_equal(alg_invoke(v_this, "ClassNameOf", (Value[]){alg_property(v_TheExpr, "Obj")}, 1), alg_string("VariableExpr")))) {
                return alg_invoke(alg_property(alg_property(v_this, "Lookup"), "Generics"), "GetType", (Value[]){alg_str(alg_property(alg_property(alg_property(v_TheExpr, "Obj"), "Name"), "Lexeme"))}, 1);
            }
            return alg_string("");
        }
    }
    if (alg_truthy(alg_equal(v_Kind, alg_string("SetSubscriptExpr")))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Obj")}, 1));
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Index")}, 1));
            return alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Value")}, 1);
        }
    }
    return alg_string("");
    return alg_nil();
}

static Value m_TypeChecker_ReduceBinary_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = args[0];
    (void)v_TheExpr;
    Value v_Left = alg_nil();
    (void)v_Left;
    Value v_Right = alg_nil();
    (void)v_Right;
    Value v_Op = alg_property(alg_property(v_TheExpr, "Op"), "TypeOfToken");
    (void)v_Op;
    if (alg_truthy((or_25 = (or_24 = (or_23 = (or_22 = (or_21 = alg_equal(v_Op, e_TokenType_TOKEN_GREATER), alg_truthy(or_21) ? or_21 : alg_equal(v_Op, e_TokenType_TOKEN_GREATER_EQUAL)), alg_truthy(or_22) ? or_22 : alg_equal(v_Op, e_TokenType_TOKEN_LESS)), alg_truthy(or_23) ? or_23 : alg_equal(v_Op, e_TokenType_TOKEN_LESS_EQUAL)), alg_truthy(or_24) ? or_24 : alg_equal(v_Op, e_TokenType_TOKEN_EQUAL)), alg_truthy(or_25) ? or_25 : alg_equal(v_Op, e_TokenType_TOKEN_NOT_EQUAL)))) {
        {
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Left")}, 1));
            (void)(alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Right")}, 1));
            return alg_string("Boolean");
        }
    }
    (void)((v_Left = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Left")}, 1)));
    (void)((v_Right = alg_invoke(v_this, "Reduce", (Value[]){alg_property(v_TheExpr, "Right")}, 1)));
    if (alg_truthy((or_28 = (or_27 = (or_26 = alg_equal(v_Left, alg_string("")), alg_truthy(or_26) ? or_26 : alg_equal(v_Right, alg_string(""))), alg_truthy(or_27) ? or_27 : alg_equal(v_Left, alg_string("Any"))), alg_truthy(or_28) ? or_28 : alg_equal(v_Right, alg_string("Any"))))) {
        return alg_string("");
    }
    if (alg_truthy(alg_equal(v_Op, e_TokenType_TOKEN_IN))) {
        return alg_string("Boolean");
    }
    if (alg_truthy((or_30 = alg_equal(v_Op, e_TokenType_TOKEN_PLUS), !alg_truthy(or_30) ? or_30 : ((or_29 = alg_invoke(v_this, "IsTextType", (Value[]){v_Left}, 1), alg_truthy(or_29) ? or_29 : alg_invoke(v_this, "IsTextType", (Value[]){v_Right}, 1)))))) {
        return alg_string("String");
    }
    if (alg_truthy((or_31 = alg_equal(v_Left, alg_string("Double")), alg_truthy(or_31) ? or_31 : alg_equal(v_Right, alg_string("Double"))))) {
        return alg_string("Double");
    }
    if (alg_truthy(alg_equal(v_Left, v_Right))) {
        return v_Left;
    }
    return alg_string("");
    return alg_nil();
}

static Value m_TypeChecker_IsTextType_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheType = args[0];
    (void)v_TheType;
    return (or_32 = alg_equal(v_TheType, alg_string("String")), alg_truthy(or_32) ? or_32 : alg_equal(v_TheType, alg_string("Char")));
    return alg_nil();
}

static Value m_TypeChecker_TypeOfValue_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Value = args[0];
    (void)v_Value;
    if (alg_truthy(alg_equal(v_Value, alg_nil()))) {
        return alg_string("Nil");
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
    if (alg_truthy(alg_is(v_Value, "Char"))) {
        return alg_string("Char");
    }
    if (alg_truthy(alg_is(v_Value, "String"))) {
        return alg_string("String");
    }
    return alg_invoke(v_this, "ClassNameOf", (Value[]){v_Value}, 1);
    return alg_nil();
}

static Value m_TypeChecker_ClassNameOf_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    volatile Value v_Obj = args[0];
    (void)v_Obj;
    {
        AlgFrame frame_3;
        alg_push_frame(&frame_3);
        if (ALG_SETJMP(frame_3.jump) == 0) {
            {
                volatile Value ret_4 = alg_property(v_Obj, "ClassName");
                alg_pop_frame();
                return ret_4;
            }
            alg_pop_frame();
        }
        else {
            static const char *names_3[] = {"String"};
            int32_t which_3 = alg_handler(frame_3.raised, names_3, 1);
            if (which_3 == 0) {
                {
                    volatile Value v_e = frame_3.raised;
                    (void)v_e;
                    return alg_string("");
                }
            }
            else {
                alg_raise(frame_3.raised);
            }
        }
    }
    return alg_nil();
}

Value f_Rejects(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    volatile Value v_Source = args[0];
    (void)v_Source;
    volatile Value v_TheScanner = alg_new(k_Scanner, (Value[]){v_Source}, 1);
    (void)v_TheScanner;
    volatile Value v_TheParser = alg_new(k_Parser, (Value[]){alg_invoke(v_TheScanner, "ScanTokens", NULL, 0)}, 1);
    (void)v_TheParser;
    {
        AlgFrame frame_5;
        alg_push_frame(&frame_5);
        if (ALG_SETJMP(frame_5.jump) == 0) {
            {
                (void)(alg_invoke(alg_new(k_TypeChecker, NULL, 0), "Resolve", (Value[]){alg_invoke(v_TheParser, "Parse", NULL, 0)}, 1));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_5[] = {"String"};
            int32_t which_5 = alg_handler(frame_5.raised, names_5, 1);
            if (which_5 == 0) {
                {
                    volatile Value v_e = frame_5.raised;
                    (void)v_e;
                    return alg_bool(true);
                }
            }
            else {
                alg_raise(frame_5.raised);
            }
        }
    }
    return alg_bool(false);
    return alg_nil();
}

void init_TypeChecker(void) {
    k_TypeLookup = alg_class("TypeLookup", alg_nil());
    alg_class_field(k_TypeLookup, "Scopes");
    alg_class_field(k_TypeLookup, "Types");
    alg_class_field(k_TypeLookup, "Parents");
    alg_class_field(k_TypeLookup, "Inferred");
    alg_class_field(k_TypeLookup, "Generics");
    alg_class_field(k_TypeLookup, "CurrentClassName");
    alg_class_initializer(k_TypeLookup, i_TypeLookup);
    alg_class_method(k_TypeLookup, "SetType", m_TypeLookup_SetType_2_String_String, 2, t_TypeLookup_SetType_2_String_String);
    alg_class_method(k_TypeLookup, "GetType", m_TypeLookup_GetType_1_String, 1, t_TypeLookup_GetType_1_String);
    alg_class_method(k_TypeLookup, "BeginScope", m_TypeLookup_BeginScope_0, 0, NULL);
    alg_class_method(k_TypeLookup, "EndScope", m_TypeLookup_EndScope_0, 0, NULL);
    k_TypeChecker = alg_class("TypeChecker", alg_nil());
    alg_class_field(k_TypeChecker, "Lookup");
    alg_class_field(k_TypeChecker, "CurrentReturn");
    alg_class_field(k_TypeChecker, "PrivateMembers");
    alg_class_field(k_TypeChecker, "BuiltinTypes");
    alg_class_initializer(k_TypeChecker, i_TypeChecker);
    alg_class_method(k_TypeChecker, "Init", m_TypeChecker_Init_0, 0, NULL);
    alg_class_method(k_TypeChecker, "HiddenBy", m_TypeChecker_HiddenBy_2_String_String, 2, t_TypeChecker_HiddenBy_2_String_String);
    alg_class_method(k_TypeChecker, "TypeOfReceiver", m_TypeChecker_TypeOfReceiver_1, 1, t_TypeChecker_TypeOfReceiver_1);
    alg_class_method(k_TypeChecker, "CheckVisibility", m_TypeChecker_CheckVisibility_2_Token, 2, t_TypeChecker_CheckVisibility_2_Token);
    alg_class_method(k_TypeChecker, "Assignable", m_TypeChecker_Assignable_2_String_String, 2, t_TypeChecker_Assignable_2_String_String);
    alg_class_method(k_TypeChecker, "Mismatch", m_TypeChecker_Mismatch_3_Token_String_String, 3, t_TypeChecker_Mismatch_3_Token_String_String);
    alg_class_method(k_TypeChecker, "Resolve", m_TypeChecker_Resolve_1_List, 1, t_TypeChecker_Resolve_1_List);
    alg_class_method(k_TypeChecker, "MapType", m_TypeChecker_MapType_1, 1, t_TypeChecker_MapType_1);
    alg_class_method(k_TypeChecker, "Check", m_TypeChecker_Check_1, 1, t_TypeChecker_Check_1);
    alg_class_method(k_TypeChecker, "CheckFunction", m_TypeChecker_CheckFunction_1, 1, t_TypeChecker_CheckFunction_1);
    alg_class_method(k_TypeChecker, "Reduce", m_TypeChecker_Reduce_1, 1, t_TypeChecker_Reduce_1);
    alg_class_method(k_TypeChecker, "ReduceBinary", m_TypeChecker_ReduceBinary_1, 1, t_TypeChecker_ReduceBinary_1);
    alg_class_method(k_TypeChecker, "IsTextType", m_TypeChecker_IsTextType_1_String, 1, t_TypeChecker_IsTextType_1_String);
    alg_class_method(k_TypeChecker, "TypeOfValue", m_TypeChecker_TypeOfValue_1, 1, t_TypeChecker_TypeOfValue_1);
    alg_class_method(k_TypeChecker, "ClassNameOf", m_TypeChecker_ClassNameOf_1, 1, t_TypeChecker_ClassNameOf_1);
    fn_Rejects = alg_closure("Rejects", f_Rejects, NULL, 0, 1);
    v_HIDER = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("class Counter;"), alg_char_value(10)), alg_string("private:")), alg_char_value(10)), alg_string("    var Count : Integer := 0;")), alg_char_value(10)), alg_string("begin")), alg_char_value(10)), alg_string("    procedure Bump();")), alg_char_value(10)), alg_string("    begin")), alg_char_value(10)), alg_string("        Count := Count + 1;")), alg_char_value(10)), alg_string("    end")), alg_char_value(10)), alg_string("private:")), alg_char_value(10)), alg_string("    procedure Advance();")), alg_char_value(10)), alg_string("    begin")), alg_char_value(10)), alg_string("    end")), alg_char_value(10)), alg_string("end")), alg_char_value(10));
}
