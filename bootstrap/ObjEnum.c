/* Generated from Algol-24.  Do not edit. */
#include "ObjEnum.h"
#include "Token.h"

Value k_objenum;
static const char *t_objenum_init_3_string_string_integer[] = { "TypeName : String", "Name : String", "Ordinal : Integer" };
static const char *t_objenum_get_1_token[] = { "TheName : Token" };
Value k_objenumtype;
static const char *t_objenumtype_init_1_string[] = { "Name : String" };
static const char *t_objenumtype_add_1_string[] = { "MemberName : String" };
static const char *t_objenumtype_get_1_token[] = { "TheName : Token" };

static Value i_objenum(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "TypeName", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Ordinal", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_objenum_init_3_string_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_typename = alg_widen(args[0], "String");
    (void)v_typename;
    alg_root(&v_typename, 1);
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_ordinal = alg_widen(args[2], "Integer");
    (void)v_ordinal;
    alg_root(&v_ordinal, 1);
    int32_t rh_322 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "TypeName", v_typename)));
    alg_hold_top = rh_322;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_322;
    (void)(alg_hold(alg_set_property(v_this, "Ordinal", v_ordinal)));
    alg_hold_top = rh_322;
    Value ret_0 = alg_nil();
    alg_root_top = rt_base;
    return ret_0;
}

static Value m_objenum_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_323 = alg_hold_top;
    Value ret_1 = alg_property(v_this, "Name");
    alg_root_top = rt_base;
    return ret_1;
    alg_hold_top = rh_323;
    Value ret_2 = alg_nil();
    alg_root_top = rt_base;
    return ret_2;
}

static Value m_objenum_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thename = alg_widen(args[0], "Token");
    (void)v_thename;
    alg_root(&v_thename, 1);
    int32_t rh_324 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_thename, "Lexeme"))}, 1)), alg_literal("ordinal"))))) {
        Value ret_3 = alg_property(v_this, "Ordinal");
        alg_root_top = rt_base;
        return ret_3;
    }
    alg_hold_top = rh_324;
    alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined property '"), alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme")))))), alg_literal("'."))));
    alg_hold_top = rh_324;
    Value ret_4 = alg_nil();
    alg_root_top = rt_base;
    return ret_4;
}

static Value i_objenumtype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Members", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_objenumtype_init_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_325 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_325;
    (void)(alg_hold(alg_set_property(v_this, "Members", alg_hold(alg_map()))));
    alg_hold_top = rh_325;
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

static Value m_objenumtype_add_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_membername = alg_widen(args[0], "String");
    (void)v_membername;
    alg_root(&v_membername, 1);
    int32_t rh_326 = alg_hold_top;
    Value v_member = alg_nil();
    (void)v_member;
    alg_root(&v_member, 1);
    alg_hold_top = rh_326;
    (void)((v_member = alg_hold(alg_new(k_objenum, (Value[]){alg_property(v_this, "Name"), v_membername, alg_hold(alg_property(alg_property(v_this, "Members"), "Length"))}, 3))));
    alg_hold_top = rh_326;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Members"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_membername}, 1)), v_member}, 2)));
    alg_hold_top = rh_326;
    Value ret_6 = v_member;
    alg_root_top = rt_base;
    return ret_6;
    alg_hold_top = rh_326;
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
}

static Value m_objenumtype_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thename = alg_widen(args[0], "Token");
    (void)v_thename;
    alg_root(&v_thename, 1);
    int32_t rh_327 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Members"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_thename, "Lexeme"))}, 1))}, 1)))))) {
        alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined enum member '"), alg_hold(alg_property(v_thename, "Lexeme")))), alg_literal("'."))));
    }
    alg_hold_top = rh_327;
    Value ret_8 = alg_hold(alg_invoke(alg_property(v_this, "Members"), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_thename, "Lexeme"))}, 1))}, 1));
    alg_root_top = rt_base;
    return ret_8;
    alg_hold_top = rh_327;
    Value ret_9 = alg_nil();
    alg_root_top = rt_base;
    return ret_9;
}

static Value m_objenumtype_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_328 = alg_hold_top;
    Value ret_10 = alg_property(v_this, "Name");
    alg_root_top = rt_base;
    return ret_10;
    alg_hold_top = rh_328;
    Value ret_11 = alg_nil();
    alg_root_top = rt_base;
    return ret_11;
}

static Value *roots_ObjEnum[] = {
    &k_objenum,
    &k_objenumtype,
};

void init_ObjEnum(void) {
    alg_roots(roots_ObjEnum, 2);
    k_objenum = alg_class("ObjEnum", alg_nil());
    k_objenumtype = alg_class("ObjEnumType", alg_nil());
    alg_class_field(k_objenum, "TypeName", "String");
    alg_class_field(k_objenum, "Name", "String");
    alg_class_field(k_objenum, "Ordinal", "Integer");
    alg_class_initializer(k_objenum, i_objenum);
    alg_class_method(k_objenum, "Init", m_objenum_init_3_string_string_integer, 3, t_objenum_init_3_string_string_integer);
    alg_class_method(k_objenum, "ToString", m_objenum_tostring_0, 0, NULL);
    alg_class_method(k_objenum, "Get", m_objenum_get_1_token, 1, t_objenum_get_1_token);
    alg_class_field(k_objenumtype, "Name", "String");
    alg_class_field(k_objenumtype, "Members", "Map");
    alg_class_initializer(k_objenumtype, i_objenumtype);
    alg_class_method(k_objenumtype, "Init", m_objenumtype_init_1_string, 1, t_objenumtype_init_1_string);
    alg_class_method(k_objenumtype, "Add", m_objenumtype_add_1_string, 1, t_objenumtype_add_1_string);
    alg_class_method(k_objenumtype, "Get", m_objenumtype_get_1_token, 1, t_objenumtype_get_1_token);
    alg_class_method(k_objenumtype, "ToString", m_objenumtype_tostring_0, 0, NULL);
    int32_t rh_321 = alg_hold_top;
    alg_hold_top = rh_321;
    alg_hold_top = rh_321;
    alg_hold_top = rh_321;
}
