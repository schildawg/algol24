/* Generated from Algol-24.  Do not edit. */
#include "ObjEnum.h"
#include "Token.h"

Value k_ObjEnum;
static const char *t_ObjEnum_Init_3_String_String_Integer[] = { "String", "String", "Integer" };
static const char *t_ObjEnum_Get_1_Token[] = { "Token" };
Value k_ObjEnumType;
static const char *t_ObjEnumType_Init_1_String[] = { "String" };
static const char *t_ObjEnumType_Add_1_String[] = { "String" };
static const char *t_ObjEnumType_Get_1_Token[] = { "Token" };

static Value i_ObjEnum(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "TypeName", alg_nil());
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Ordinal", alg_nil());
    return alg_nil();
}

static Value m_ObjEnum_Init_3_String_String_Integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TypeName = args[0];
    (void)v_TypeName;
    Value v_Name = args[1];
    (void)v_Name;
    Value v_Ordinal = args[2];
    (void)v_Ordinal;
    (void)(alg_set_property(v_this, "TypeName", v_TypeName));
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Ordinal", v_Ordinal));
    return alg_nil();
}

static Value m_ObjEnum_ToString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "Name");
    return alg_nil();
}

static Value m_ObjEnum_Get_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheName = args[0];
    (void)v_TheName;
    if (alg_truthy(alg_equal(alg_str(alg_property(v_TheName, "Lexeme")), alg_string("Ordinal")))) {
        return alg_property(v_this, "Ordinal");
    }
    alg_raise(alg_add(alg_add(alg_string("Undefined property '"), alg_str(alg_property(v_TheName, "Lexeme"))), alg_string("'.")));
    return alg_nil();
}

static Value i_ObjEnumType(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Members", alg_nil());
    return alg_nil();
}

static Value m_ObjEnumType_Init_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    (void)(alg_set_property(v_this, "Name", v_Name));
    (void)(alg_set_property(v_this, "Members", alg_map()));
    return alg_nil();
}

static Value m_ObjEnumType_Add_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_MemberName = args[0];
    (void)v_MemberName;
    Value v_Member = alg_nil();
    (void)v_Member;
    (void)((v_Member = alg_new(k_ObjEnum, (Value[]){alg_property(v_this, "Name"), v_MemberName, alg_property(alg_property(v_this, "Members"), "Length")}, 3)));
    (void)(alg_invoke(alg_property(v_this, "Members"), "Put", (Value[]){v_MemberName, v_Member}, 2));
    return v_Member;
    return alg_nil();
}

static Value m_ObjEnumType_Get_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheName = args[0];
    (void)v_TheName;
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Members"), "Contains", (Value[]){alg_property(v_TheName, "Lexeme")}, 1)))) {
        alg_raise(alg_add(alg_add(alg_string("Undefined enum member '"), alg_property(v_TheName, "Lexeme")), alg_string("'.")));
    }
    return alg_invoke(alg_property(v_this, "Members"), "Get", (Value[]){alg_property(v_TheName, "Lexeme")}, 1);
    return alg_nil();
}

static Value m_ObjEnumType_ToString_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_property(v_this, "Name");
    return alg_nil();
}

void init_ObjEnum(void) {
    k_ObjEnum = alg_class("ObjEnum", alg_nil());
    alg_class_field(k_ObjEnum, "TypeName");
    alg_class_field(k_ObjEnum, "Name");
    alg_class_field(k_ObjEnum, "Ordinal");
    alg_class_initializer(k_ObjEnum, i_ObjEnum);
    alg_class_method(k_ObjEnum, "Init", m_ObjEnum_Init_3_String_String_Integer, 3, t_ObjEnum_Init_3_String_String_Integer);
    alg_class_method(k_ObjEnum, "ToString", m_ObjEnum_ToString_0, 0, NULL);
    alg_class_method(k_ObjEnum, "Get", m_ObjEnum_Get_1_Token, 1, t_ObjEnum_Get_1_Token);
    k_ObjEnumType = alg_class("ObjEnumType", alg_nil());
    alg_class_field(k_ObjEnumType, "Name");
    alg_class_field(k_ObjEnumType, "Members");
    alg_class_initializer(k_ObjEnumType, i_ObjEnumType);
    alg_class_method(k_ObjEnumType, "Init", m_ObjEnumType_Init_1_String, 1, t_ObjEnumType_Init_1_String);
    alg_class_method(k_ObjEnumType, "Add", m_ObjEnumType_Add_1_String, 1, t_ObjEnumType_Add_1_String);
    alg_class_method(k_ObjEnumType, "Get", m_ObjEnumType_Get_1_Token, 1, t_ObjEnumType_Get_1_Token);
    alg_class_method(k_ObjEnumType, "ToString", m_ObjEnumType_ToString_0, 0, NULL);
}
