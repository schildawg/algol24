/* Generated from Algol-24.  Do not edit. */
#include "ObjEnum.h"
#include "Token.h"

Value k_objenum;
static const char *t_objenum_init_3_string_string_integer[] = { "String", "String", "Integer" };
static const char *t_objenum_get_1_token[] = { "Token" };
Value k_objenumtype;
static const char *t_objenumtype_init_1_string[] = { "String" };
static const char *t_objenumtype_add_1_string[] = { "String" };
static const char *t_objenumtype_get_1_token[] = { "Token" };

static Value i_objenum(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "TypeName", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Ordinal", alg_nil());
    return alg_nil();
}

static Value m_objenum_init_3_string_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_typename = alg_widen(args[0], "String");
    (void)v_typename;
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    Value v_ordinal = alg_widen(args[2], "Integer");
    (void)v_ordinal;
    (void)(alg_set_property(v_this, "TypeName", alg_widen(v_typename, "String")));
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "String")));
    (void)(alg_set_property(v_this, "Ordinal", alg_widen(v_ordinal, "Integer")));
    return alg_nil();
}

static Value m_objenum_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "Name");
    return alg_nil();
}

static Value m_objenum_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thename = alg_widen(args[0], "Token");
    (void)v_thename;
    if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_property(v_thename, "Lexeme")}, 1), alg_string("ordinal")))) {
        return alg_property(v_this, "Ordinal");
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_str(alg_property(v_thename, "Lexeme"))), alg_string("'.")));
    return alg_nil();
}

static Value i_objenumtype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Members", alg_nil());
    return alg_nil();
}

static Value m_objenumtype_init_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "String")));
    (void)(alg_set_property(v_this, "Members", alg_widen(alg_map(), "Map")));
    return alg_nil();
}

static Value m_objenumtype_add_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_membername = alg_widen(args[0], "String");
    (void)v_membername;
    Value v_member = alg_nil();
    (void)v_member;
    (void)((v_member = alg_widen(alg_new(k_objenum, (Value[]){alg_property(v_this, "Name"), v_membername, alg_property(alg_property(v_this, "Members"), "Length")}, 3), "ObjEnum")));
    (void)(alg_invoke(alg_property(v_this, "Members"), "Put", (Value[]){f_foldcase(NULL, (Value[]){v_membername}, 1), v_member}, 2));
    return v_member;
    return alg_nil();
}

static Value m_objenumtype_get_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thename = alg_widen(args[0], "Token");
    (void)v_thename;
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Members"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_thename, "Lexeme")}, 1)}, 1)))) {
        alg_raise(alg_add(alg_add(alg_string("Undefined enum member '"), alg_property(v_thename, "Lexeme")), alg_string("'.")));
    }
    return alg_invoke(alg_property(v_this, "Members"), "Get", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_thename, "Lexeme")}, 1)}, 1);
    return alg_nil();
}

static Value m_objenumtype_tostring_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "Name");
    return alg_nil();
}

void init_ObjEnum(void) {
    k_objenum = alg_class("ObjEnum", alg_nil());
    k_objenumtype = alg_class("ObjEnumType", alg_nil());
    alg_class_field(k_objenum, "TypeName");
    alg_class_field(k_objenum, "Name");
    alg_class_field(k_objenum, "Ordinal");
    alg_class_initializer(k_objenum, i_objenum);
    alg_class_method(k_objenum, "Init", m_objenum_init_3_string_string_integer, 3, t_objenum_init_3_string_string_integer);
    alg_class_method(k_objenum, "ToString", m_objenum_tostring_0, 0, NULL);
    alg_class_method(k_objenum, "Get", m_objenum_get_1_token, 1, t_objenum_get_1_token);
    alg_class_field(k_objenumtype, "Name");
    alg_class_field(k_objenumtype, "Members");
    alg_class_initializer(k_objenumtype, i_objenumtype);
    alg_class_method(k_objenumtype, "Init", m_objenumtype_init_1_string, 1, t_objenumtype_init_1_string);
    alg_class_method(k_objenumtype, "Add", m_objenumtype_add_1_string, 1, t_objenumtype_add_1_string);
    alg_class_method(k_objenumtype, "Get", m_objenumtype_get_1_token, 1, t_objenumtype_get_1_token);
    alg_class_method(k_objenumtype, "ToString", m_objenumtype_tostring_0, 0, NULL);
}
