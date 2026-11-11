/* Generated from Algol-24.  Do not edit. */
#include "Token.h"
#include "TokenType.h"

Value f_definesubrange(Value **cells, Value *args, int32_t count);
Value f_subrangeindex(Value **cells, Value *args, int32_t count);
Value f_issubrange(Value **cells, Value *args, int32_t count);
Value f_underlyingtype(Value **cells, Value *args, int32_t count);
Value f_canonicaltype(Value **cells, Value *args, int32_t count);
Value f_foldcase(Value **cells, Value *args, int32_t count);
Value v_subrangeVnames;
bool d_subrangeVnames;
Value v_subrangeVlows;
bool d_subrangeVlows;
Value v_subrangeVhighs;
bool d_subrangeVhighs;
Value fn_definesubrange;
static const char *t_f_definesubrange[] = { "Name : Any", "Low : Integer", "High : Integer" };
Value fn_subrangeindex;
static const char *t_f_subrangeindex[] = { "Name : Any" };
Value fn_issubrange;
static const char *t_f_issubrange[] = { "Name : Any" };
Value fn_underlyingtype;
static const char *t_f_underlyingtype[] = { "Name : Any" };
Value v_typeVspellings;
bool d_typeVspellings;
Value fn_canonicaltype;
static const char *t_f_canonicaltype[] = { "Name : Any" };
Value fn_foldcase;
static const char *t_f_foldcase[] = { "Name : Any" };
Value k_token;
static const char *t_token_init_4_tokentype_string_integer[] = { "TypeOfToken : TokenType", "Lexeme : String", "Literal : Any", "LineNumber : Integer" };

Value f_definesubrange(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 3);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_name = args[0];
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_low = alg_param(args[1], "Integer");
    (void)v_low;
    alg_root(&v_low, 1);
    Value v_high = alg_param(args[2], "Integer");
    (void)v_high;
    alg_root(&v_high, 1);
    int32_t rh_2 = alg_hold_top;
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    alg_hold_top = rh_2;
    (void)((v_at = alg_hold(alg_invoke((alg_declared(d_subrangeVnames, "SUBRANGE_NAMES"), v_subrangeVnames), "IndexOf", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1))));
    alg_hold_top = rh_2;
    if (alg_truthy(alg_hold(alg_greater_equal(v_at, alg_int(0))))) {
        {
            int32_t rh_3 = alg_hold_top;
            (void)(alg_hold(alg_invoke((alg_declared(d_subrangeVlows, "SUBRANGE_LOWS"), v_subrangeVlows), "Set", (Value[]){v_at, v_low}, 2)));
            alg_hold_top = rh_3;
            (void)(alg_hold(alg_invoke((alg_declared(d_subrangeVhighs, "SUBRANGE_HIGHS"), v_subrangeVhighs), "Set", (Value[]){v_at, v_high}, 2)));
            alg_hold_top = rh_3;
            Value ret_0 = alg_nil();
            alg_root_top = rt_base;
            return ret_0;
            alg_hold_top = rh_3;
        }
    }
    alg_hold_top = rh_2;
    (void)(alg_hold(alg_invoke((alg_declared(d_subrangeVnames, "SUBRANGE_NAMES"), v_subrangeVnames), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)));
    alg_hold_top = rh_2;
    (void)(alg_hold(alg_invoke((alg_declared(d_subrangeVlows, "SUBRANGE_LOWS"), v_subrangeVlows), "Add", (Value[]){v_low}, 1)));
    alg_hold_top = rh_2;
    (void)(alg_hold(alg_invoke((alg_declared(d_subrangeVhighs, "SUBRANGE_HIGHS"), v_subrangeVhighs), "Add", (Value[]){v_high}, 1)));
    alg_hold_top = rh_2;
    Value ret_1 = alg_nil();
    alg_root_top = rt_base;
    return ret_1;
}

Value f_subrangeindex(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_name = args[0];
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_4 = alg_hold_top;
    Value ret_2 = alg_hold(alg_invoke((alg_declared(d_subrangeVnames, "SUBRANGE_NAMES"), v_subrangeVnames), "IndexOf", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1));
    alg_root_top = rt_base;
    return ret_2;
    alg_hold_top = rh_4;
    Value ret_3 = alg_nil();
    alg_root_top = rt_base;
    return ret_3;
}

Value f_issubrange(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_name = args[0];
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_5 = alg_hold_top;
    Value ret_4 = alg_hold(alg_greater_equal(alg_hold(f_subrangeindex(NULL, (Value[]){v_name}, 1)), alg_int(0)));
    alg_root_top = rt_base;
    return ret_4;
    alg_hold_top = rh_5;
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

Value f_underlyingtype(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_name = args[0];
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_6 = alg_hold_top;
    if (alg_truthy(alg_hold(f_issubrange(NULL, (Value[]){v_name}, 1)))) {
        Value ret_6 = alg_literal("Integer");
        alg_root_top = rt_base;
        return ret_6;
    }
    alg_hold_top = rh_6;
    Value ret_7 = alg_hold(f_canonicaltype(NULL, (Value[]){v_name}, 1));
    alg_root_top = rt_base;
    return ret_7;
    alg_hold_top = rh_6;
    Value ret_8 = alg_nil();
    alg_root_top = rt_base;
    return ret_8;
}

Value f_canonicaltype(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_name = args[0];
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_7 = alg_hold_top;
    Value v_folded = alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1));
    (void)v_folded;
    alg_root(&v_folded, 1);
    alg_hold_top = rh_7;
    if (alg_truthy(alg_hold(alg_invoke((alg_declared(d_typeVspellings, "TYPE_SPELLINGS"), v_typeVspellings), "Contains", (Value[]){v_folded}, 1)))) {
        Value ret_9 = alg_hold(alg_str(alg_hold(alg_invoke((alg_declared(d_typeVspellings, "TYPE_SPELLINGS"), v_typeVspellings), "Get", (Value[]){v_folded}, 1))));
        alg_root_top = rt_base;
        return ret_9;
    }
    alg_hold_top = rh_7;
    Value ret_10 = alg_hold(alg_str(v_name));
    alg_root_top = rt_base;
    return ret_10;
    alg_hold_top = rh_7;
    Value ret_11 = alg_nil();
    alg_root_top = rt_base;
    return ret_11;
}

Value f_foldcase(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_name = args[0];
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_8 = alg_hold_top;
    Value ret_12 = alg_hold(alg_cast_kind(alg_to_lower(alg_hold(alg_str(v_name))), ALG_KIND_STRING, "String"));
    alg_root_top = rt_base;
    return ret_12;
    alg_hold_top = rh_8;
    Value ret_13 = alg_nil();
    alg_root_top = rt_base;
    return ret_13;
}

static Value i_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "TypeOfToken", alg_nil());
    alg_set_property(v_this, "Lexeme", alg_nil());
    alg_set_property(v_this, "Literal", alg_nil());
    alg_set_property(v_this, "LineNumber", alg_nil());
    alg_set_property(v_this, "Offset", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "File", alg_widen(alg_literal(""), "String"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_token_init_4_tokentype_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_typeoftoken = alg_widen(args[0], "TokenType");
    (void)v_typeoftoken;
    alg_root(&v_typeoftoken, 1);
    Value v_lexeme = alg_widen(args[1], "String");
    (void)v_lexeme;
    alg_root(&v_lexeme, 1);
    Value v_literal = args[2];
    (void)v_literal;
    alg_root(&v_literal, 1);
    Value v_linenumber = alg_widen(args[3], "Integer");
    (void)v_linenumber;
    alg_root(&v_linenumber, 1);
    int32_t rh_9 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "TypeOfToken", v_typeoftoken)));
    alg_hold_top = rh_9;
    (void)(alg_hold(alg_set_property(v_this, "Lexeme", v_lexeme)));
    alg_hold_top = rh_9;
    (void)(alg_hold(alg_set_property(v_this, "Literal", v_literal)));
    alg_hold_top = rh_9;
    (void)(alg_hold(alg_set_property(v_this, "LineNumber", v_linenumber)));
    alg_hold_top = rh_9;
    Value ret_14 = alg_nil();
    alg_root_top = rt_base;
    return ret_14;
}

static Value m_token_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_10 = alg_hold_top;
    Value ret_15 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_str(alg_property(v_this, "TypeOfToken"))), alg_char_value(32))), alg_property(v_this, "Lexeme"))), alg_char_value(32))), alg_property(v_this, "Literal")));
    alg_root_top = rt_base;
    return ret_15;
    alg_hold_top = rh_10;
    Value ret_16 = alg_nil();
    alg_root_top = rt_base;
    return ret_16;
}

static Value *roots_Token[] = {
    &v_subrangeVnames,
    &v_subrangeVlows,
    &v_subrangeVhighs,
    &fn_definesubrange,
    &fn_subrangeindex,
    &fn_issubrange,
    &fn_underlyingtype,
    &v_typeVspellings,
    &fn_canonicaltype,
    &fn_foldcase,
    &k_token,
};

void init_Token(void) {
    alg_roots(roots_Token, 11);
    k_token = alg_class("Token", alg_nil());
    fn_definesubrange = alg_closure("DefineSubrange", f_definesubrange, NULL, 0, 3, t_f_definesubrange);
    fn_subrangeindex = alg_closure("SubrangeIndex", f_subrangeindex, NULL, 0, 1, t_f_subrangeindex);
    fn_issubrange = alg_closure("IsSubrange", f_issubrange, NULL, 0, 1, t_f_issubrange);
    fn_underlyingtype = alg_closure("UnderlyingType", f_underlyingtype, NULL, 0, 1, t_f_underlyingtype);
    fn_canonicaltype = alg_closure("CanonicalType", f_canonicaltype, NULL, 0, 1, t_f_canonicaltype);
    fn_foldcase = alg_closure("FoldCase", f_foldcase, NULL, 0, 1, t_f_foldcase);
    alg_class_field(k_token, "TypeOfToken");
    alg_class_field(k_token, "Lexeme");
    alg_class_field(k_token, "Literal");
    alg_class_field(k_token, "LineNumber");
    alg_class_field(k_token, "Offset");
    alg_class_field(k_token, "File");
    alg_class_initializer(k_token, i_token);
    alg_class_method(k_token, "Init", m_token_init_4_tokentype_string_integer, 4, t_token_init_4_tokentype_string_integer);
    alg_class_method(k_token, "ToString", m_token_tostring_0, 0, NULL);
    int32_t rh_1 = alg_hold_top;
    init_TokenType();
    alg_hold_top = rh_1;
    v_subrangeVnames = alg_hold(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_literal("byte")), alg_literal("word")), alg_literal("short")));
    d_subrangeVnames = true;
    alg_hold_top = rh_1;
    v_subrangeVlows = alg_hold(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_int(0)), alg_int(0)), alg_hold(alg_negate(alg_int(32768)))));
    d_subrangeVlows = true;
    alg_hold_top = rh_1;
    v_subrangeVhighs = alg_hold(alg_list_keep(alg_list_keep(alg_list_keep(alg_list(), alg_int(255)), alg_int(65535)), alg_int(32767)));
    d_subrangeVhighs = true;
    alg_hold_top = rh_1;
    alg_hold_top = rh_1;
    alg_hold_top = rh_1;
    alg_hold_top = rh_1;
    alg_hold_top = rh_1;
    v_typeVspellings = alg_hold(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map_keep(alg_map(), alg_literal("integer"), alg_literal("Integer")), alg_literal("double"), alg_literal("Double")), alg_literal("string"), alg_literal("String")), alg_literal("char"), alg_literal("Char")), alg_literal("boolean"), alg_literal("Boolean")), alg_literal("any"), alg_literal("Any")), alg_literal("list"), alg_literal("List")), alg_literal("set"), alg_literal("Set")), alg_literal("map"), alg_literal("Map")), alg_literal("array"), alg_literal("Array")), alg_literal("stack"), alg_literal("Stack")), alg_literal("buffer"), alg_literal("Buffer")), alg_literal("textfile"), alg_literal("TextFile")), alg_literal("pointer"), alg_literal("Pointer")), alg_literal("real"), alg_literal("Double")));
    d_typeVspellings = true;
    alg_hold_top = rh_1;
    alg_hold_top = rh_1;
    alg_hold_top = rh_1;
    alg_hold_top = rh_1;
    alg_hold_top = rh_1;
    alg_hold_top = rh_1;
}
