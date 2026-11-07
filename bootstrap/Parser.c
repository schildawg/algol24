/* Generated from Algol-24.  Do not edit. */
#include "Parser.h"
#include "Console.h"
#include "Expr.h"
#include "Interpreter.h"
#include "Scanner.h"
#include "Stmt.h"
#include "Token.h"
#include "TokenType.h"

Value f_readwholefile(Value **cells, Value *args, int32_t count);
Value f_setmodulefolders(Value **cells, Value *args, int32_t count);
Value f_folderof(Value **cells, Value *args, int32_t count);
Value f_libraryfolders(Value **cells, Value *args, int32_t count);
Value fn_readwholefile;
static const char *t_f_readwholefile[] = { "Name : String" };
Value v_moduleVfolders;
bool d_moduleVfolders;
Value fn_setmodulefolders;
static const char *t_f_setmodulefolders[] = { "Folders : List" };
static Value or_0;
Value fn_folderof;
static const char *t_f_folderof[] = { "Path : String" };
Value fn_libraryfolders;
Value k_parser;
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
static Value or_49;
static Value or_50;
static Value or_51;
static Value or_52;
static Value or_53;
static Value or_54;
static Value or_55;
static Value or_56;
static Value or_57;
static Value or_58;
static Value or_59;
static Value or_60;
static Value or_61;
static Value or_62;
static Value or_63;
static Value or_64;
static Value or_65;
static Value or_66;
static Value or_67;
static Value or_68;
static Value or_69;
static Value or_70;
static Value or_71;
static Value or_72;
static Value or_73;
static const char *t_parser_init_1_list[] = { "Tokens : List" };
static const char *t_parser_claimunit_2_token_string[] = { "Where : Token", "Path : String" };
static const char *t_parser_unitstem_1_string[] = { "Key : String" };
static const char *t_parser_iscollectiontype_1_string[] = { "TypeName : String" };
static const char *t_parser_recordprivate_1[] = { "Decl : Any" };
static const char *t_parser_resolvemodule_2_token_string[] = { "Where : Token", "ModuleName : String" };
static const char *t_parser_declarationsection_1_boolean[] = { "IsConstant : Boolean" };
static const char *t_parser_readdeclarationsections_1_list[] = { "Body : List" };
static const char *t_parser_readdeclarationsections_2_list_boolean[] = { "Body : List", "AllowVisibility : Boolean" };
static const char *t_parser_forinstatement_1_token[] = { "Name : Token" };
static const char *t_parser_enclosingloop_1_string[] = { "TheLabel : String" };
static const char *t_parser_jumplabel_2_token_string[] = { "Keyword : Token", "Verb : String" };
static const char *t_parser_vardeclaration_1_token[] = { "Name : Token" };
static const char *t_parser_parsefunction_2_string_boolean[] = { "Kind : String", "IsExtension : Boolean" };
static const char *t_parser_subrangedeclaration_1_token[] = { "Name : Token" };
static const char *t_parser_classdeclaration_1_string[] = { "Kind : String" };
static const char *t_parser_finishcall_1_expr[] = { "Callee : Expr" };
static const char *t_parser_argument_2_list_list[] = { "Arguments : List", "Names : List" };
static const char *t_parser_match_1_tokentype[] = { "TheType : TokenType" };
static const char *t_parser_error_2_token_string[] = { "TheToken : Token", "Message : String" };
static const char *t_parser_consume_2_tokentype_string[] = { "TypeOfToken : TokenType", "Message : String" };
static const char *t_parser_check_1_tokentype[] = { "TheType : TokenType" };
static const char *t_parser_checkword_1_string[] = { "Word : String" };

Value f_readwholefile(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_name = alg_param(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_f = alg_text_file();
    (void)v_f;
    alg_root(&v_f, 1);
    (void)(alg_invoke(v_f, "Assign", (Value[]){v_name}, 1));
    (void)(alg_invoke(v_f, "Reset", NULL, 0));
    Value v_result = alg_buffer(alg_int(0));
    (void)v_result;
    alg_root(&v_result, 1);
    while (alg_truthy(alg_not(alg_property(v_f, "Eof")))) {
        {
            (void)(alg_invoke(v_result, "Append", (Value[]){alg_invoke(v_f, "ReadLn", NULL, 0)}, 1));
            (void)(alg_invoke(v_result, "Append", (Value[]){alg_char_value(10)}, 1));
        }
    }
    (void)(alg_invoke(v_f, "Close", NULL, 0));
    Value ret_0 = alg_property(v_result, "Text");
    alg_root_top = rt_base;
    return ret_0;
    Value ret_1 = alg_nil();
    alg_root_top = rt_base;
    return ret_1;
}

Value f_setmodulefolders(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_folders = alg_param(args[0], "List");
    (void)v_folders;
    alg_root(&v_folders, 1);
    (void)((alg_declared(d_moduleVfolders, "MODULE_FOLDERS"), (v_moduleVfolders = v_folders)));
    Value ret_2 = alg_nil();
    alg_root_top = rt_base;
    return ret_2;
}

Value f_folderof(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_path = alg_param(args[0], "String");
    (void)v_path;
    alg_root(&v_path, 1);
    Value v_cut = alg_negate(alg_int(1));
    (void)v_cut;
    alg_root(&v_cut, 1);
    {
        int32_t rt_29 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_path))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy((or_0 = alg_equal(alg_subscript_get(v_path, v_i), alg_char_value(47)), alg_truthy(or_0) ? or_0 : alg_equal(alg_subscript_get(v_path, v_i), alg_char(alg_int(92)))))) {
                (void)((v_cut = v_i));
            }
        }
        alg_root_top = rt_29;
    }
    if (alg_truthy(alg_less(v_cut, alg_int(0)))) {
        Value ret_3 = alg_string("");
        alg_root_top = rt_base;
        return ret_3;
    }
    Value ret_4 = alg_copy(v_path, alg_int(0), v_cut);
    alg_root_top = rt_base;
    return ret_4;
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

Value f_libraryfolders(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_own = alg_nil();
    (void)v_own;
    alg_root(&v_own, 1);
    (void)((v_own = f_folderof(NULL, (Value[]){alg_param_str(alg_int(0))}, 1)));
    if (alg_truthy(alg_equal(v_own, alg_string("")))) {
        Value ret_6 = alg_list();
        alg_root_top = rt_base;
        return ret_6;
    }
    Value ret_7 = alg_list_keep(alg_list_keep(alg_list(), alg_add(v_own, alg_string("/lib"))), alg_add(v_own, alg_string("/../share/algol24/lib")));
    alg_root_top = rt_base;
    return ret_7;
    Value ret_8 = alg_nil();
    alg_root_top = rt_base;
    return ret_8;
}

static Value i_parser(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Tokens", alg_nil());
    alg_set_property(v_this, "Current", alg_nil());
    alg_set_property(v_this, "FileName", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "Loaded", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "Claimed", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "PrivateNames", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "InPrivateSection", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "ClassPrivates", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "LoopDepth", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "InProcedure", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "SubprogramDepth", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "LastGeneric", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "PendingLabel", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "LoopLabels", alg_widen(alg_list(), "List"));
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_parser_init_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_tokens = alg_widen(args[0], "List");
    (void)v_tokens;
    alg_root(&v_tokens, 1);
    (void)(alg_set_property(v_this, "Tokens", v_tokens));
    (void)(alg_set_property(v_this, "Current", alg_int(0)));
    Value ret_9 = alg_nil();
    alg_root_top = rt_base;
    return ret_9;
}

static Value m_parser_unitheader_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)))) {
        Value ret_10 = alg_nil();
        alg_root_top = rt_base;
        return ret_10;
    }
    if (alg_truthy(alg_not_equal(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "Lexeme"), alg_string("unit")))) {
        Value ret_11 = alg_nil();
        alg_root_top = rt_base;
        return ret_11;
    }
    if (alg_truthy(alg_not_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVidentifier))) {
        Value ret_12 = alg_nil();
        alg_root_top = rt_base;
        return ret_12;
    }
    (void)(alg_invoke(v_this, "Advance", NULL, 0));
    Value v_name = alg_invoke(v_this, "Advance", NULL, 0);
    (void)v_name;
    alg_root(&v_name, 1);
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after unit name.")}, 2));
    Value v_expected = alg_invoke(v_this, "UnitStem", (Value[]){alg_property(v_this, "FileName")}, 1);
    (void)v_expected;
    alg_root(&v_expected, 1);
    if (alg_truthy((or_1 = alg_equal(v_expected, alg_string("")), alg_truthy(or_1) ? or_1 : alg_equal(v_expected, alg_string("REPL"))))) {
        Value ret_13 = alg_nil();
        alg_root_top = rt_base;
        return ret_13;
    }
    if (alg_truthy(alg_not_equal(v_expected, alg_str(alg_property(v_name, "Lexeme"))))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_name, alg_add(alg_add(alg_add(alg_add(alg_string("Unit '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' must match its file name '")), v_expected), alg_string("'."))}, 2));
    }
    Value ret_14 = alg_nil();
    alg_root_top = rt_base;
    return ret_14;
}

static Value m_parser_claimunit_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_where = alg_widen(args[0], "Token");
    (void)v_where;
    alg_root(&v_where, 1);
    Value v_path = alg_widen(args[1], "String");
    (void)v_path;
    alg_root(&v_path, 1);
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    (void)((v_folded = f_foldcase(NULL, (Value[]){alg_invoke(v_this, "UnitStem", (Value[]){v_path}, 1)}, 1)));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Claimed"), "Contains", (Value[]){v_folded}, 1))) {
        {
            if (alg_truthy(alg_not_equal(alg_str(alg_invoke(alg_property(v_this, "Claimed"), "Get", (Value[]){v_folded}, 1)), v_path))) {
                alg_raise(alg_invoke(v_this, "Error", (Value[]){v_where, alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("Two units whose names differ only in case: '"), alg_str(alg_invoke(alg_property(v_this, "Claimed"), "Get", (Value[]){v_folded}, 1))), alg_string("' and '")), v_path), alg_string("'. A unit name is matched without regard to ")), alg_string("case."))}, 2));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Claimed"), "Put", (Value[]){v_folded, v_path}, 2));
    Value ret_15 = alg_nil();
    alg_root_top = rt_base;
    return ret_15;
}

static Value m_parser_unitstem_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_key = alg_widen(args[0], "String");
    (void)v_key;
    alg_root(&v_key, 1);
    Value v_stem = alg_nil();
    (void)v_stem;
    alg_root(&v_stem, 1);
    (void)((v_stem = v_key));
    {
        int32_t rt_30 = alg_root_top;
        Value v_i = alg_subtract(alg_text_length(v_key), alg_int(1));
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_greater_equal(v_i, alg_int(0))); (v_i = alg_subtract(v_i, alg_int(1)))) {
            if (alg_truthy((or_2 = alg_equal(alg_subscript_get(v_key, v_i), alg_char_value(47)), alg_truthy(or_2) ? or_2 : alg_equal(alg_subscript_get(v_key, v_i), alg_char_value(92))))) {
                {
                    (void)((v_stem = alg_copy(v_key, alg_add(v_i, alg_int(1)), alg_subtract(alg_subtract(alg_text_length(v_key), v_i), alg_int(1)))));
                    (void)((v_i = alg_negate(alg_int(1))));
                }
            }
        }
        alg_root_top = rt_30;
    }
    if (alg_truthy((or_3 = alg_greater(alg_text_length(v_stem), alg_int(4)), !alg_truthy(or_3) ? or_3 : alg_equal(alg_copy(v_stem, alg_subtract(alg_text_length(v_stem), alg_int(4)), alg_int(4)), alg_string(".a24"))))) {
        Value ret_16 = alg_copy(v_stem, alg_int(0), alg_subtract(alg_text_length(v_stem), alg_int(4)));
        alg_root_top = rt_base;
        return ret_16;
    }
    Value ret_17 = v_stem;
    alg_root_top = rt_base;
    return ret_17;
    Value ret_18 = alg_nil();
    alg_root_top = rt_base;
    return ret_18;
}

static Value m_parser_parse_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_nil();
    (void)v_statements;
    alg_root(&v_statements, 1);
    (void)((v_statements = alg_list()));
    if (alg_truthy(alg_not_equal(alg_property(v_this, "FileName"), alg_string("")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Loaded"), "Put", (Value[]){alg_property(v_this, "FileName"), alg_bool(true)}, 2));
            (void)(alg_invoke(v_this, "ClaimUnit", (Value[]){alg_invoke(v_this, "Peek", NULL, 0), alg_property(v_this, "FileName")}, 2));
        }
    }
    (void)(alg_invoke(v_this, "UnitHeader", NULL, 0));
    while (alg_truthy(alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        {
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVuses}, 1))) {
                {
                    int32_t rt_31 = alg_root_top;
                    Value v_themodule = alg_invoke(v_this, "UsesStatement", NULL, 0);
                    (void)v_themodule;
                    alg_root(&v_themodule, 1);
                    if (alg_truthy(alg_not_equal(v_themodule, alg_nil()))) {
                        (void)(alg_invoke(v_statements, "Add", (Value[]){v_themodule}, 1));
                    }
                    alg_root_top = rt_31;
                }
            } else {
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVprivate}, 1))) {
                    {
                        int32_t rt_32 = alg_root_top;
                        Value v_decl = alg_invoke(v_this, "Declaration", NULL, 0);
                        (void)v_decl;
                        alg_root(&v_decl, 1);
                        (void)(alg_invoke(v_this, "RecordPrivate", (Value[]){v_decl}, 1));
                        (void)(alg_invoke(v_statements, "Add", (Value[]){v_decl}, 1));
                        alg_root_top = rt_32;
                    }
                } else {
                    (void)(alg_invoke(v_statements, "Add", (Value[]){alg_invoke(v_this, "Declaration", NULL, 0)}, 1));
                }
            }
        }
    }
    Value ret_19 = v_statements;
    alg_root_top = rt_base;
    return ret_19;
    Value ret_20 = alg_nil();
    alg_root_top = rt_base;
    return ret_20;
}

static Value m_parser_statement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVtype}, 1))) {
        Value ret_21 = alg_invoke(v_this, "EnumDeclaration", NULL, 0);
        alg_root_top = rt_base;
        return ret_21;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVclass}, 1))) {
        Value ret_22 = alg_invoke(v_this, "ClassDeclaration", NULL, 0);
        alg_root_top = rt_base;
        return ret_22;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVobject}, 1))) {
        Value ret_23 = alg_invoke(v_this, "ClassDeclaration", (Value[]){alg_string("object")}, 1);
        alg_root_top = rt_base;
        return ret_23;
    }
    if (alg_truthy(alg_invoke(v_this, "IsExtensionDeclaration", NULL, 0))) {
        Value ret_24 = alg_invoke(v_this, "ExtensionDeclaration", NULL, 0);
        alg_root_top = rt_base;
        return ret_24;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVfunction}, 1))) {
        Value ret_25 = alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("function"), alg_bool(false)}, 2);
        alg_root_top = rt_base;
        return ret_25;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVprocedure}, 1))) {
        Value ret_26 = alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("procedure"), alg_bool(false)}, 2);
        alg_root_top = rt_base;
        return ret_26;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVvar}, 1))) {
        Value ret_27 = alg_invoke(v_this, "VarDeclaration", NULL, 0);
        alg_root_top = rt_base;
        return ret_27;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVconst}, 1))) {
        Value ret_28 = alg_invoke(v_this, "ConstDeclaration", NULL, 0);
        alg_root_top = rt_base;
        return ret_28;
    }
    if (alg_truthy((or_4 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1), !alg_truthy(or_4) ? or_4 : alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVcolon)))) {
        Value ret_29 = alg_invoke(v_this, "LabelStatement", NULL, 0);
        alg_root_top = rt_base;
        return ret_29;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcase}, 1))) {
        Value ret_30 = alg_invoke(v_this, "CaseStatement", NULL, 0);
        alg_root_top = rt_base;
        return ret_30;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVif}, 1))) {
        Value ret_31 = alg_invoke(v_this, "IfStatement", NULL, 0);
        alg_root_top = rt_base;
        return ret_31;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVwhile}, 1))) {
        Value ret_32 = alg_invoke(v_this, "WhileStatement", NULL, 0);
        alg_root_top = rt_base;
        return ret_32;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVfor}, 1))) {
        Value ret_33 = alg_invoke(v_this, "ForStatement", NULL, 0);
        alg_root_top = rt_base;
        return ret_33;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVexit}, 1))) {
        Value ret_34 = alg_invoke(v_this, "ReturnStatement", NULL, 0);
        alg_root_top = rt_base;
        return ret_34;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVtry}, 1))) {
        Value ret_35 = alg_invoke(v_this, "TryStatement", NULL, 0);
        alg_root_top = rt_base;
        return ret_35;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVbreak}, 1))) {
        Value ret_36 = alg_invoke(v_this, "BreakStatement", NULL, 0);
        alg_root_top = rt_base;
        return ret_36;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcontinue}, 1))) {
        Value ret_37 = alg_invoke(v_this, "ContinueStatement", NULL, 0);
        alg_root_top = rt_base;
        return ret_37;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVgoto}, 1))) {
        Value ret_38 = alg_invoke(v_this, "GotoStatement", NULL, 0);
        alg_root_top = rt_base;
        return ret_38;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVraise}, 1))) {
        Value ret_39 = alg_invoke(v_this, "RaiseStatement", NULL, 0);
        alg_root_top = rt_base;
        return ret_39;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVbegin}, 1))) {
        Value ret_40 = alg_new(k_blockstmt, (Value[]){alg_invoke(v_this, "Block", NULL, 0)}, 1);
        alg_root_top = rt_base;
        return ret_40;
    }
    Value ret_41 = alg_invoke(v_this, "ExpressionStatement", NULL, 0);
    alg_root_top = rt_base;
    return ret_41;
    Value ret_42 = alg_nil();
    alg_root_top = rt_base;
    return ret_42;
}

static Value m_parser_casestatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_left = alg_nil();
    (void)v_left;
    alg_root(&v_left, 1);
    Value v_top = alg_nil();
    (void)v_top;
    alg_root(&v_top, 1);
    Value v_current = alg_nil();
    (void)v_current;
    alg_root(&v_current, 1);
    Value v_condition = alg_nil();
    (void)v_condition;
    alg_root(&v_condition, 1);
    Value v_branch = alg_nil();
    (void)v_branch;
    alg_root(&v_branch, 1);
    (void)((v_left = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVof, alg_string("Expect 'of' after case condition.")}, 2));
    (void)((v_top = alg_cast(alg_nil(), "IfStmt")));
    (void)((v_current = alg_cast(alg_nil(), "IfStmt")));
    while (alg_truthy(alg_bool(true))) {
        {
            (void)((v_condition = alg_widen(alg_new(k_binaryexpr, (Value[]){v_left, alg_invoke(v_this, "Equals", NULL, 0), alg_invoke(v_this, "Expression", NULL, 0)}, 3), "Expr")));
            while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))) {
                (void)((v_condition = alg_widen(alg_new(k_logicalexpr, (Value[]){v_condition, alg_invoke(v_this, "Either", NULL, 0), alg_new(k_binaryexpr, (Value[]){v_left, alg_invoke(v_this, "Equals", NULL, 0), alg_invoke(v_this, "Expression", NULL, 0)}, 3)}, 3), "Expr")));
            }
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVcolon, alg_string("Expect ':' after condition.")}, 2));
            (void)((v_branch = alg_new(k_ifstmt, (Value[]){v_condition, alg_invoke(v_this, "Statement", NULL, 0), alg_nil()}, 3)));
            if (alg_truthy(alg_equal(v_top, alg_nil()))) {
                (void)((v_top = v_branch));
            } else {
                (void)(alg_set_property(v_current, "ElseBranch", alg_widen(v_branch, "Stmt")));
            }
            (void)((v_current = v_branch));
            if (alg_truthy((or_5 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVelse}, 1), alg_truthy(or_5) ? or_5 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVend}, 1)))) {
                break;
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(alg_invoke(v_this, "Previous", NULL, 0), "TypeOfToken"), e_tokentype_tokenVelse))) {
        {
            (void)(alg_set_property(v_current, "ElseBranch", alg_invoke(v_this, "BodyStatement", NULL, 0)));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVend, alg_string("Expected 'end'.")}, 2));
        }
    }
    Value ret_43 = v_top;
    alg_root_top = rt_base;
    return ret_43;
    Value ret_44 = alg_nil();
    alg_root_top = rt_base;
    return ret_44;
}

static Value m_parser_equals_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_45 = alg_new(k_token, (Value[]){e_tokentype_tokenVequal, alg_char_value(61), alg_nil(), alg_property(alg_invoke(v_this, "Previous", NULL, 0), "LineNumber")}, 4);
    alg_root_top = rt_base;
    return ret_45;
    Value ret_46 = alg_nil();
    alg_root_top = rt_base;
    return ret_46;
}

static Value m_parser_either_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_47 = alg_new(k_token, (Value[]){e_tokentype_tokenVor, alg_string("or"), alg_nil(), alg_property(alg_invoke(v_this, "Previous", NULL, 0), "LineNumber")}, 4);
    alg_root_top = rt_base;
    return ret_47;
    Value ret_48 = alg_nil();
    alg_root_top = rt_base;
    return ret_48;
}

static Value m_parser_bodystatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy((or_11 = (or_10 = (or_9 = (or_8 = (or_7 = (or_6 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVvar}, 1), alg_truthy(or_6) ? or_6 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVconst}, 1)), alg_truthy(or_7) ? or_7 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVtype}, 1)), alg_truthy(or_8) ? or_8 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVclass}, 1)), alg_truthy(or_9) ? or_9 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVobject}, 1)), alg_truthy(or_10) ? or_10 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVfunction}, 1)), alg_truthy(or_11) ? or_11 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVprocedure}, 1)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_invoke(v_this, "Peek", NULL, 0), alg_string("A declaration cannot be a branch or loop body; use 'begin' ... 'end'.")}, 2));
    }
    Value ret_49 = alg_invoke(v_this, "Statement", NULL, 0);
    alg_root_top = rt_base;
    return ret_49;
    Value ret_50 = alg_nil();
    alg_root_top = rt_base;
    return ret_50;
}

static Value m_parser_iscollectiontype_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_typename = alg_widen(args[0], "String");
    (void)v_typename;
    alg_root(&v_typename, 1);
    Value v_lowered = alg_to_lower(v_typename);
    (void)v_lowered;
    alg_root(&v_lowered, 1);
    Value ret_51 = (or_15 = (or_14 = (or_13 = (or_12 = alg_equal(v_lowered, alg_string("list")), alg_truthy(or_12) ? or_12 : alg_equal(v_lowered, alg_string("map"))), alg_truthy(or_13) ? or_13 : alg_equal(v_lowered, alg_string("set"))), alg_truthy(or_14) ? or_14 : alg_equal(v_lowered, alg_string("stack"))), alg_truthy(or_15) ? or_15 : alg_equal(v_lowered, alg_string("array")));
    alg_root_top = rt_base;
    return ret_51;
    Value ret_52 = alg_nil();
    alg_root_top = rt_base;
    return ret_52;
}

static Value m_parser_ifstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_condition = alg_nil();
    (void)v_condition;
    alg_root(&v_condition, 1);
    Value v_thenbranch = alg_nil();
    (void)v_thenbranch;
    alg_root(&v_thenbranch, 1);
    Value v_elsebranch = alg_nil();
    (void)v_elsebranch;
    alg_root(&v_elsebranch, 1);
    (void)((v_condition = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVthen, alg_string("Expect 'then' after if condition.")}, 2));
    (void)((v_thenbranch = alg_invoke(v_this, "BodyStatement", NULL, 0)));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVelse}, 1))) {
        {
            (void)((v_elsebranch = alg_invoke(v_this, "BodyStatement", NULL, 0)));
        }
    }
    Value ret_53 = alg_new(k_ifstmt, (Value[]){v_condition, v_thenbranch, v_elsebranch}, 3);
    alg_root_top = rt_base;
    return ret_53;
    Value ret_54 = alg_nil();
    alg_root_top = rt_base;
    return ret_54;
}

static Value m_parser_forstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    Value v_increment = alg_nil();
    (void)v_increment;
    alg_root(&v_increment, 1);
    Value v_condition = alg_nil();
    (void)v_condition;
    alg_root(&v_condition, 1);
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    Value v_stmtlist = alg_nil();
    (void)v_stmtlist;
    alg_root(&v_stmtlist, 1);
    Value v_whilelist = alg_nil();
    (void)v_whilelist;
    alg_root(&v_whilelist, 1);
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVsemicolon}, 1))) {
        (void)((v_initializer = alg_widen(alg_nil(), "Stmt")));
    } else {
        if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVvar}, 1))) {
            {
                int32_t rt_33 = alg_root_top;
                Value v_name = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect variable name.")}, 2);
                (void)v_name;
                alg_root(&v_name, 1);
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVin}, 1))) {
                    Value ret_55 = alg_invoke(v_this, "ForInStatement", (Value[]){v_name}, 1);
                    alg_root_top = rt_base;
                    return ret_55;
                }
                (void)((v_initializer = alg_invoke(v_this, "VarDeclaration", (Value[]){v_name}, 1)));
                alg_root_top = rt_33;
            }
        } else {
            (void)((v_initializer = alg_invoke(v_this, "ExpressionStatement", NULL, 0)));
        }
    }
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVsemicolon}, 1)))) {
        {
            (void)((v_condition = alg_invoke(v_this, "Expression", NULL, 0)));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after loop condition")}, 2));
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVdo}, 1)))) {
        {
            (void)((v_increment = alg_invoke(v_this, "Expression", NULL, 0)));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdo, alg_string("Expect 'do' after for clauses.")}, 2));
    Value v_named = alg_invoke(v_this, "TakeLabel", NULL, 0);
    (void)v_named;
    alg_root(&v_named, 1);
    (void)(alg_set_property(v_this, "LoopDepth", alg_add(alg_property(v_this, "LoopDepth"), alg_int(1))));
    (void)((v_body = alg_invoke(v_this, "BodyStatement", NULL, 0)));
    (void)(alg_set_property(v_this, "LoopDepth", alg_subtract(alg_property(v_this, "LoopDepth"), alg_int(1))));
    (void)(alg_invoke(alg_property(v_this, "LoopLabels"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LoopLabels"), "Length"), alg_int(1))}, 1));
    if (alg_truthy(alg_equal(v_condition, alg_nil()))) {
        (void)((v_condition = alg_widen(alg_new(k_literalexpr, (Value[]){alg_bool(true)}, 1), "Expr")));
    }
    Value v_loop = alg_new(k_whilestmt, (Value[]){v_condition, v_body}, 2);
    (void)v_loop;
    alg_root(&v_loop, 1);
    (void)(alg_set_property(v_loop, "Increment", v_increment));
    (void)(alg_set_property(v_loop, "Label", v_named));
    (void)((v_body = alg_widen(v_loop, "Stmt")));
    if (alg_truthy(alg_not_equal(v_initializer, alg_nil()))) {
        {
            (void)((v_whilelist = alg_list()));
            (void)(alg_invoke(v_whilelist, "Add", (Value[]){v_initializer}, 1));
            (void)(alg_invoke(v_whilelist, "Add", (Value[]){v_body}, 1));
            (void)((v_body = alg_widen(alg_new(k_blockstmt, (Value[]){v_whilelist}, 1), "Stmt")));
        }
    }
    Value ret_56 = v_body;
    alg_root_top = rt_base;
    return ret_56;
    Value ret_57 = alg_nil();
    alg_root_top = rt_base;
    return ret_57;
}

static Value m_parser_whilestatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_condition = alg_nil();
    (void)v_condition;
    alg_root(&v_condition, 1);
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    (void)((v_condition = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdo, alg_string("Expect 'do' after condition.")}, 2));
    Value v_named = alg_invoke(v_this, "TakeLabel", NULL, 0);
    (void)v_named;
    alg_root(&v_named, 1);
    (void)(alg_set_property(v_this, "LoopDepth", alg_add(alg_property(v_this, "LoopDepth"), alg_int(1))));
    (void)((v_body = alg_invoke(v_this, "BodyStatement", NULL, 0)));
    (void)(alg_set_property(v_this, "LoopDepth", alg_subtract(alg_property(v_this, "LoopDepth"), alg_int(1))));
    (void)(alg_invoke(alg_property(v_this, "LoopLabels"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LoopLabels"), "Length"), alg_int(1))}, 1));
    Value v_loop = alg_new(k_whilestmt, (Value[]){v_condition, v_body}, 2);
    (void)v_loop;
    alg_root(&v_loop, 1);
    (void)(alg_set_property(v_loop, "Label", v_named));
    Value ret_58 = v_loop;
    alg_root_top = rt_base;
    return ret_58;
    Value ret_59 = alg_nil();
    alg_root_top = rt_base;
    return ret_59;
}

static Value m_parser_returnstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_keyword = alg_nil();
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    (void)((v_keyword = alg_invoke(v_this, "Previous", NULL, 0)));
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVsemicolon}, 1)))) {
        {
            if (alg_truthy(alg_property(v_this, "InProcedure"))) {
                alg_raise(alg_invoke(v_this, "Error", (Value[]){v_keyword, alg_string("A procedure cannot exit a value.")}, 2));
            }
            (void)((v_value = alg_invoke(v_this, "Expression", NULL, 0)));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after exit value.")}, 2));
    Value ret_60 = alg_new(k_returnstmt, (Value[]){v_keyword, v_value}, 2);
    alg_root_top = rt_base;
    return ret_60;
    Value ret_61 = alg_nil();
    alg_root_top = rt_base;
    return ret_61;
}

static Value m_parser_recordprivate_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_decl = args[0];
    (void)v_decl;
    alg_root(&v_decl, 1);
    if (alg_truthy((or_18 = (or_17 = (or_16 = alg_is(v_decl, "FunctionStmt"), alg_truthy(or_16) ? or_16 : alg_is(v_decl, "ClassStmt")), alg_truthy(or_17) ? or_17 : alg_is(v_decl, "ObjectStmt")), alg_truthy(or_18) ? or_18 : alg_is(v_decl, "VarStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_str(alg_property(alg_property(v_decl, "Name"), "Lexeme"))}, 1));
            Value ret_62 = alg_nil();
            alg_root_top = rt_base;
            return ret_62;
        }
    }
    if (alg_truthy(alg_is(v_decl, "VarGroupStmt"))) {
        {
            {
                int32_t rt_34 = alg_root_top;
                Value loop_63 = alg_iterable(alg_property(v_decl, "Names"));
                (void)loop_63;
                alg_root(&loop_63, 1);
                for (int32_t at_63 = 0; at_63 < alg_iterable_count(loop_63); at_63++) {
                    int32_t rt_35 = alg_root_top;
                    Value v_thename = alg_iterable_at(loop_63, at_63);
                    (void)v_thename;
                    alg_root(&v_thename, 1);
                    (void)(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_str(alg_property(v_thename, "Lexeme"))}, 1));
                    alg_root_top = rt_35;
                }
                alg_root_top = rt_34;
            }
            Value ret_64 = alg_nil();
            alg_root_top = rt_base;
            return ret_64;
        }
    }
    if (alg_truthy(alg_is(v_decl, "EnumStmt"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_str(alg_property(alg_property(v_decl, "Name"), "Lexeme"))}, 1));
            {
                int32_t rt_36 = alg_root_top;
                Value loop_65 = alg_iterable(alg_property(v_decl, "Members"));
                (void)loop_65;
                alg_root(&loop_65, 1);
                for (int32_t at_65 = 0; at_65 < alg_iterable_count(loop_65); at_65++) {
                    int32_t rt_37 = alg_root_top;
                    Value v_member = alg_iterable_at(loop_65, at_65);
                    (void)v_member;
                    alg_root(&v_member, 1);
                    (void)(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_str(alg_property(v_member, "Lexeme"))}, 1));
                    alg_root_top = rt_37;
                }
                alg_root_top = rt_36;
            }
            Value ret_66 = alg_nil();
            alg_root_top = rt_base;
            return ret_66;
        }
    }
    alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_invoke(v_this, "Previous", NULL, 0), alg_string("'private' must precede a declaration.")}, 2));
    Value ret_67 = alg_nil();
    alg_root_top = rt_base;
    return ret_67;
}

static Value m_parser_resolvemodule_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_where = alg_widen(args[0], "Token");
    (void)v_where;
    alg_root(&v_where, 1);
    Value v_modulename = alg_widen(args[1], "String");
    (void)v_modulename;
    alg_root(&v_modulename, 1);
    Value v_thefile = alg_nil();
    (void)v_thefile;
    alg_root(&v_thefile, 1);
    Value v_dir = alg_nil();
    (void)v_dir;
    alg_root(&v_dir, 1);
    (void)((v_thefile = alg_add(v_modulename, alg_string(".a24"))));
    (void)((v_dir = f_folderof(NULL, (Value[]){alg_property(v_this, "FileName")}, 1)));
    if (alg_truthy(alg_not_equal(v_dir, alg_string("")))) {
        {
            int32_t rt_38 = alg_root_top;
            Value v_beside = alg_add(alg_add(v_dir, alg_char_value(47)), v_thefile);
            (void)v_beside;
            alg_root(&v_beside, 1);
            if (alg_truthy(alg_file_exists(v_beside))) {
                Value ret_68 = v_beside;
                alg_root_top = rt_base;
                return ret_68;
            }
            alg_root_top = rt_38;
        }
    }
    if (alg_truthy(alg_file_exists(v_thefile))) {
        Value ret_69 = v_thefile;
        alg_root_top = rt_base;
        return ret_69;
    }
    {
        int32_t rt_39 = alg_root_top;
        Value loop_70 = alg_iterable((alg_declared(d_moduleVfolders, "MODULE_FOLDERS"), v_moduleVfolders));
        (void)loop_70;
        alg_root(&loop_70, 1);
        for (int32_t at_70 = 0; at_70 < alg_iterable_count(loop_70); at_70++) {
            int32_t rt_40 = alg_root_top;
            Value v_folder = alg_iterable_at(loop_70, at_70);
            (void)v_folder;
            alg_root(&v_folder, 1);
            {
                int32_t rt_41 = alg_root_top;
                Value v_installed = alg_add(alg_add(alg_str(v_folder), alg_char_value(47)), v_thefile);
                (void)v_installed;
                alg_root(&v_installed, 1);
                if (alg_truthy(alg_file_exists(v_installed))) {
                    Value ret_71 = v_installed;
                    alg_root_top = rt_base;
                    return ret_71;
                }
                alg_root_top = rt_41;
            }
            alg_root_top = rt_40;
        }
        alg_root_top = rt_39;
    }
    Value v_searched = alg_string("the working directory");
    (void)v_searched;
    alg_root(&v_searched, 1);
    if (alg_truthy(alg_not_equal(v_dir, alg_string("")))) {
        (void)((v_searched = alg_add(alg_add(alg_char_value(39), v_dir), alg_string("' or the working directory"))));
    }
    {
        int32_t rt_42 = alg_root_top;
        Value loop_72 = alg_iterable((alg_declared(d_moduleVfolders, "MODULE_FOLDERS"), v_moduleVfolders));
        (void)loop_72;
        alg_root(&loop_72, 1);
        for (int32_t at_72 = 0; at_72 < alg_iterable_count(loop_72); at_72++) {
            int32_t rt_43 = alg_root_top;
            Value v_folder = alg_iterable_at(loop_72, at_72);
            (void)v_folder;
            alg_root(&v_folder, 1);
            (void)((v_searched = alg_add(alg_add(alg_add(v_searched, alg_string(", or '")), alg_str(v_folder)), alg_char_value(39))));
            alg_root_top = rt_43;
        }
        alg_root_top = rt_42;
    }
    alg_raise(alg_invoke(v_this, "Error", (Value[]){v_where, alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("Could not find module '"), v_modulename), alg_string("': no ")), v_thefile), alg_string(" in ")), v_searched), alg_char_value(46))}, 2));
    Value ret_73 = alg_nil();
    alg_root_top = rt_base;
    return ret_73;
}

static Value m_parser_usesstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_modulename = alg_nil();
    (void)v_modulename;
    alg_root(&v_modulename, 1);
    Value v_where = alg_nil();
    (void)v_where;
    alg_root(&v_where, 1);
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVstring}, 1))) {
        (void)((v_modulename = alg_str(alg_property(alg_invoke(v_this, "Previous", NULL, 0), "Literal"))));
    } else {
        (void)((v_modulename = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expected identifier.")}, 2), "Lexeme"))));
    }
    (void)((v_where = alg_invoke(v_this, "Previous", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expected ';'")}, 2));
    Value v_path = alg_invoke(v_this, "ResolveModule", (Value[]){v_where, v_modulename}, 2);
    (void)v_path;
    alg_root(&v_path, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Loaded"), "Contains", (Value[]){v_path}, 1))) {
        {
            int32_t rt_44 = alg_root_top;
            Value v_seen = alg_new(k_modulestmt, (Value[]){v_where, alg_nil(), alg_list()}, 3);
            (void)v_seen;
            alg_root(&v_seen, 1);
            (void)(alg_set_property(v_seen, "FileName", v_path));
            (void)(alg_set_property(v_seen, "UnitName", alg_invoke(v_this, "UnitStem", (Value[]){v_path}, 1)));
            Value ret_74 = v_seen;
            alg_root_top = rt_base;
            return ret_74;
            alg_root_top = rt_44;
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Loaded"), "Put", (Value[]){v_path, alg_bool(true)}, 2));
    (void)(alg_invoke(v_this, "ClaimUnit", (Value[]){v_where, v_path}, 2));
    Value v_subscanner = alg_new(k_scanner, (Value[]){f_readwholefile(NULL, (Value[]){v_path}, 1), v_path}, 2);
    (void)v_subscanner;
    alg_root(&v_subscanner, 1);
    Value v_subparser = alg_new(k_parser, (Value[]){alg_invoke(v_subscanner, "ScanTokens", NULL, 0)}, 1);
    (void)v_subparser;
    alg_root(&v_subparser, 1);
    (void)(alg_set_property(v_subparser, "FileName", v_path));
    (void)(alg_set_property(v_subparser, "Loaded", alg_property(v_this, "Loaded")));
    (void)(alg_set_property(v_subparser, "Claimed", alg_property(v_this, "Claimed")));
    Value v_result = alg_invoke(v_subparser, "Parse", NULL, 0);
    (void)v_result;
    alg_root(&v_result, 1);
    Value v_themodule = alg_new(k_modulestmt, (Value[]){v_where, v_result, alg_property(v_subparser, "PrivateNames")}, 3);
    (void)v_themodule;
    alg_root(&v_themodule, 1);
    (void)(alg_set_property(v_themodule, "FileName", v_path));
    (void)(alg_set_property(v_themodule, "UnitName", alg_invoke(v_this, "UnitStem", (Value[]){v_path}, 1)));
    Value ret_75 = v_themodule;
    alg_root_top = rt_base;
    return ret_75;
    Value ret_76 = alg_nil();
    alg_root_top = rt_base;
    return ret_76;
}

static Value m_parser_constdeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    (void)((v_name = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect constant name.")}, 2)));
    Value v_typename = alg_string("");
    (void)v_typename;
    alg_root(&v_typename, 1);
    Value v_generic = alg_string("");
    (void)v_generic;
    alg_root(&v_generic, 1);
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
        {
            (void)((v_typename = f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect type name.")}, 2), "Lexeme")}, 1)));
            if (alg_truthy((or_19 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_typename}, 1), !alg_truthy(or_19) ? or_19 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))) {
                (void)((v_generic = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect generic type.")}, 2), "Lexeme"))));
            }
        }
    }
    if (alg_truthy(alg_not(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVassign}, 1)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_name, alg_string("A constant must be given a value.")}, 2));
    }
    Value v_initializer = alg_invoke(v_this, "Expression", NULL, 0);
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after constant declaration.")}, 2));
    Value v_thevar = alg_new(k_varstmt, (Value[]){v_name, v_initializer}, 2);
    (void)v_thevar;
    alg_root(&v_thevar, 1);
    (void)(alg_set_property(v_thevar, "TypeName", v_typename));
    (void)(alg_set_property(v_thevar, "Generic", v_generic));
    (void)(alg_set_property(v_thevar, "IsConstant", alg_bool(true)));
    Value ret_77 = v_thevar;
    alg_root_top = rt_base;
    return ret_77;
    Value ret_78 = alg_nil();
    alg_root_top = rt_base;
    return ret_78;
}

static Value m_parser_matchvisibility_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy((or_20 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVprivate}, 1), !alg_truthy(or_20) ? or_20 : alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVcolon)))) {
        {
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_set_property(v_this, "InPrivateSection", alg_bool(true)));
            Value ret_79 = alg_bool(true);
            alg_root_top = rt_base;
            return ret_79;
        }
    }
    if (alg_truthy((or_21 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVpublic}, 1), !alg_truthy(or_21) ? or_21 : alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVcolon)))) {
        {
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_set_property(v_this, "InPrivateSection", alg_bool(false)));
            Value ret_80 = alg_bool(true);
            alg_root_top = rt_base;
            return ret_80;
        }
    }
    Value ret_81 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_81;
    Value ret_82 = alg_nil();
    alg_root_top = rt_base;
    return ret_82;
}

static Value m_parser_isdeclarationsection_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_83 = (or_23 = (or_22 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVvar}, 1), alg_truthy(or_22) ? or_22 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVconst}, 1)), alg_truthy(or_23) ? or_23 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVtype}, 1));
    alg_root_top = rt_base;
    return ret_83;
    Value ret_84 = alg_nil();
    alg_root_top = rt_base;
    return ret_84;
}

static Value m_parser_isnextsection_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        Value ret_85 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_85;
    }
    Value ret_86 = (or_30 = (or_29 = (or_28 = (or_27 = (or_26 = (or_25 = (or_24 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1), alg_truthy(or_24) ? or_24 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVbegin}, 1)), alg_truthy(or_25) ? or_25 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVfunction}, 1)), alg_truthy(or_26) ? or_26 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVprocedure}, 1)), alg_truthy(or_27) ? or_27 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVconstructor}, 1)), alg_truthy(or_28) ? or_28 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVvar}, 1)), alg_truthy(or_29) ? or_29 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVconst}, 1)), alg_truthy(or_30) ? or_30 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVtype}, 1));
    alg_root_top = rt_base;
    return ret_86;
    Value ret_87 = alg_nil();
    alg_root_top = rt_base;
    return ret_87;
}

static Value m_parser_declarationsection_1_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_isconstant = alg_widen(args[0], "Boolean");
    (void)v_isconstant;
    alg_root(&v_isconstant, 1);
    Value v_stmts = alg_nil();
    (void)v_stmts;
    alg_root(&v_stmts, 1);
    Value v_noun = alg_nil();
    (void)v_noun;
    alg_root(&v_noun, 1);
    (void)((v_stmts = alg_list()));
    (void)((v_noun = alg_string("variable")));
    if (alg_truthy(v_isconstant)) {
        (void)((v_noun = alg_string("constant")));
    }
    while (alg_truthy(alg_not(alg_invoke(v_this, "IsNextSection", NULL, 0)))) {
        {
            int32_t rt_45 = alg_root_top;
            while (alg_truthy(alg_invoke(v_this, "MatchVisibility", NULL, 0))) {
                {
                }
            }
            if (alg_truthy(alg_invoke(v_this, "IsNextSection", NULL, 0))) {
                break;
            }
            Value v_names = alg_list();
            (void)v_names;
            alg_root(&v_names, 1);
            (void)(alg_invoke(v_names, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_add(alg_add(alg_string("Expect "), v_noun), alg_string(" name."))}, 2)}, 1));
            while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))) {
                (void)(alg_invoke(v_names, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_add(alg_add(alg_string("Expect "), v_noun), alg_string(" name."))}, 2)}, 1));
            }
            if (alg_truthy(alg_property(v_this, "InPrivateSection"))) {
                {
                    int32_t rt_46 = alg_root_top;
                    Value loop_88 = alg_iterable(v_names);
                    (void)loop_88;
                    alg_root(&loop_88, 1);
                    for (int32_t at_88 = 0; at_88 < alg_iterable_count(loop_88); at_88++) {
                        int32_t rt_47 = alg_root_top;
                        Value v_thename = alg_iterable_at(loop_88, at_88);
                        (void)v_thename;
                        alg_root(&v_thename, 1);
                        (void)(alg_invoke(alg_property(v_this, "ClassPrivates"), "Add", (Value[]){alg_str(alg_property(v_thename, "Lexeme"))}, 1));
                        alg_root_top = rt_47;
                    }
                    alg_root_top = rt_46;
                }
            }
            Value v_typename = alg_string("");
            (void)v_typename;
            alg_root(&v_typename, 1);
            Value v_generic = alg_string("");
            (void)v_generic;
            alg_root(&v_generic, 1);
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
                {
                    (void)((v_typename = f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect type name.")}, 2), "Lexeme")}, 1)));
                    if (alg_truthy((or_31 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_typename}, 1), !alg_truthy(or_31) ? or_31 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))) {
                        (void)((v_generic = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect generic type.")}, 2), "Lexeme"))));
                    }
                }
            }
            Value v_initializer = alg_cast(alg_nil(), "Expr");
            (void)v_initializer;
            alg_root(&v_initializer, 1);
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVassign}, 1))) {
                (void)((v_initializer = alg_invoke(v_this, "Expression", NULL, 0)));
            } else {
                if (alg_truthy(v_isconstant)) {
                    alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_subscript_get(v_names, alg_int(0)), alg_string("A constant must be given a value.")}, 2));
                }
            }
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_add(alg_add(alg_string("Expect ';' after "), v_noun), alg_string(" declaration."))}, 2));
            if (alg_truthy(alg_equal(alg_property(v_names, "Length"), alg_int(1)))) {
                {
                    int32_t rt_48 = alg_root_top;
                    Value v_thevar = alg_new(k_varstmt, (Value[]){alg_subscript_get(v_names, alg_int(0)), v_initializer}, 2);
                    (void)v_thevar;
                    alg_root(&v_thevar, 1);
                    (void)(alg_set_property(v_thevar, "TypeName", v_typename));
                    (void)(alg_set_property(v_thevar, "Generic", v_generic));
                    (void)(alg_set_property(v_thevar, "IsConstant", v_isconstant));
                    (void)(alg_invoke(v_stmts, "Add", (Value[]){v_thevar}, 1));
                    alg_root_top = rt_48;
                }
            } else {
                {
                    int32_t rt_49 = alg_root_top;
                    Value v_thegroup = alg_new(k_vargroupstmt, (Value[]){v_names, v_initializer}, 2);
                    (void)v_thegroup;
                    alg_root(&v_thegroup, 1);
                    (void)(alg_set_property(v_thegroup, "TypeName", v_typename));
                    (void)(alg_set_property(v_thegroup, "Generic", v_generic));
                    (void)(alg_set_property(v_thegroup, "IsConstant", v_isconstant));
                    (void)(alg_invoke(v_stmts, "Add", (Value[]){v_thegroup}, 1));
                    alg_root_top = rt_49;
                }
            }
            alg_root_top = rt_45;
        }
    }
    Value ret_89 = v_stmts;
    alg_root_top = rt_base;
    return ret_89;
    Value ret_90 = alg_nil();
    alg_root_top = rt_base;
    return ret_90;
}

static Value m_parser_readdeclarationsections_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_body = alg_widen(args[0], "List");
    (void)v_body;
    alg_root(&v_body, 1);
    (void)(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_body, alg_bool(false)}, 2));
    Value ret_91 = alg_nil();
    alg_root_top = rt_base;
    return ret_91;
}

static Value m_parser_readdeclarationsections_2_list_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_body = alg_widen(args[0], "List");
    (void)v_body;
    alg_root(&v_body, 1);
    Value v_allowvisibility = alg_widen(args[1], "Boolean");
    (void)v_allowvisibility;
    alg_root(&v_allowvisibility, 1);
    while (alg_truthy(alg_bool(true))) {
        {
            if (alg_truthy(v_allowvisibility)) {
                while (alg_truthy(alg_invoke(v_this, "MatchVisibility", NULL, 0))) {
                    {
                    }
                }
            }
            if (alg_truthy(alg_not(alg_invoke(v_this, "IsDeclarationSection", NULL, 0)))) {
                break;
            }
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVvar}, 1))) {
                {
                    int32_t rt_50 = alg_root_top;
                    Value v_section = alg_invoke(v_this, "DeclarationSection", (Value[]){alg_bool(false)}, 1);
                    (void)v_section;
                    alg_root(&v_section, 1);
                    {
                        int32_t rt_51 = alg_root_top;
                        Value loop_92 = alg_iterable(v_section);
                        (void)loop_92;
                        alg_root(&loop_92, 1);
                        for (int32_t at_92 = 0; at_92 < alg_iterable_count(loop_92); at_92++) {
                            int32_t rt_52 = alg_root_top;
                            Value v_declaration = alg_iterable_at(loop_92, at_92);
                            (void)v_declaration;
                            alg_root(&v_declaration, 1);
                            (void)(alg_invoke(v_body, "Add", (Value[]){v_declaration}, 1));
                            alg_root_top = rt_52;
                        }
                        alg_root_top = rt_51;
                    }
                    alg_root_top = rt_50;
                }
            } else {
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVconst}, 1))) {
                    {
                        int32_t rt_53 = alg_root_top;
                        Value v_section = alg_invoke(v_this, "DeclarationSection", (Value[]){alg_bool(true)}, 1);
                        (void)v_section;
                        alg_root(&v_section, 1);
                        {
                            int32_t rt_54 = alg_root_top;
                            Value loop_93 = alg_iterable(v_section);
                            (void)loop_93;
                            alg_root(&loop_93, 1);
                            for (int32_t at_93 = 0; at_93 < alg_iterable_count(loop_93); at_93++) {
                                int32_t rt_55 = alg_root_top;
                                Value v_declaration = alg_iterable_at(loop_93, at_93);
                                (void)v_declaration;
                                alg_root(&v_declaration, 1);
                                (void)(alg_invoke(v_body, "Add", (Value[]){v_declaration}, 1));
                                alg_root_top = rt_55;
                            }
                            alg_root_top = rt_54;
                        }
                        alg_root_top = rt_53;
                    }
                } else {
                    {
                        (void)(alg_invoke(v_this, "Advance", NULL, 0));
                        while (alg_truthy(alg_not(alg_invoke(v_this, "IsNextSection", NULL, 0)))) {
                            (void)(alg_invoke(v_body, "Add", (Value[]){alg_invoke(v_this, "EnumDeclaration", NULL, 0)}, 1));
                        }
                    }
                }
            }
        }
    }
    Value ret_94 = alg_nil();
    alg_root_top = rt_base;
    return ret_94;
}

static Value m_parser_forinstatement_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_iterable = alg_nil();
    (void)v_iterable;
    alg_root(&v_iterable, 1);
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    (void)((v_iterable = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdo, alg_string("Expect 'do' after 'for ... in' clause.")}, 2));
    Value v_named = alg_invoke(v_this, "TakeLabel", NULL, 0);
    (void)v_named;
    alg_root(&v_named, 1);
    (void)(alg_set_property(v_this, "LoopDepth", alg_add(alg_property(v_this, "LoopDepth"), alg_int(1))));
    (void)((v_body = alg_invoke(v_this, "BodyStatement", NULL, 0)));
    (void)(alg_set_property(v_this, "LoopDepth", alg_subtract(alg_property(v_this, "LoopDepth"), alg_int(1))));
    (void)(alg_invoke(alg_property(v_this, "LoopLabels"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LoopLabels"), "Length"), alg_int(1))}, 1));
    Value v_loop = alg_new(k_forinstmt, (Value[]){v_name, v_iterable, v_body}, 3);
    (void)v_loop;
    alg_root(&v_loop, 1);
    (void)(alg_set_property(v_loop, "Label", v_named));
    Value ret_95 = v_loop;
    alg_root_top = rt_base;
    return ret_95;
    Value ret_96 = alg_nil();
    alg_root_top = rt_base;
    return ret_96;
}

static Value m_parser_breakstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_keyword = alg_nil();
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    (void)((v_keyword = alg_invoke(v_this, "Previous", NULL, 0)));
    if (alg_truthy(alg_equal(alg_property(v_this, "LoopDepth"), alg_int(0)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_keyword, alg_string("Must be inside a loop to use 'break'.")}, 2));
    }
    Value v_named = alg_invoke(v_this, "JumpLabel", (Value[]){v_keyword, alg_string("break")}, 2);
    (void)v_named;
    alg_root(&v_named, 1);
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after 'break'.")}, 2));
    Value v_leaving = alg_new(k_breakstmt, (Value[]){v_keyword}, 1);
    (void)v_leaving;
    alg_root(&v_leaving, 1);
    (void)(alg_set_property(v_leaving, "Label", v_named));
    Value ret_97 = v_leaving;
    alg_root_top = rt_base;
    return ret_97;
    Value ret_98 = alg_nil();
    alg_root_top = rt_base;
    return ret_98;
}

static Value m_parser_labelstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    (void)((v_name = alg_invoke(v_this, "Advance", NULL, 0)));
    (void)(alg_invoke(v_this, "Advance", NULL, 0));
    (void)(alg_set_property(v_this, "PendingLabel", alg_str(alg_property(v_name, "Lexeme"))));
    Value v_inner = alg_invoke(v_this, "Statement", NULL, 0);
    (void)v_inner;
    alg_root(&v_inner, 1);
    (void)(alg_set_property(v_this, "PendingLabel", alg_string("")));
    Value ret_99 = alg_new(k_labelstmt, (Value[]){v_name, v_inner}, 2);
    alg_root_top = rt_base;
    return ret_99;
    Value ret_100 = alg_nil();
    alg_root_top = rt_base;
    return ret_100;
}

static Value m_parser_takelabel_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_taken = alg_nil();
    (void)v_taken;
    alg_root(&v_taken, 1);
    (void)((v_taken = alg_property(v_this, "PendingLabel")));
    (void)(alg_set_property(v_this, "PendingLabel", alg_string("")));
    (void)(alg_invoke(alg_property(v_this, "LoopLabels"), "Add", (Value[]){v_taken}, 1));
    Value ret_101 = v_taken;
    alg_root_top = rt_base;
    return ret_101;
    Value ret_102 = alg_nil();
    alg_root_top = rt_base;
    return ret_102;
}

static Value m_parser_enclosingloop_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    {
        int32_t rt_56 = alg_root_top;
        Value loop_103 = alg_iterable(alg_property(v_this, "LoopLabels"));
        (void)loop_103;
        alg_root(&loop_103, 1);
        for (int32_t at_103 = 0; at_103 < alg_iterable_count(loop_103); at_103++) {
            int32_t rt_57 = alg_root_top;
            Value v_looplabel = alg_iterable_at(loop_103, at_103);
            (void)v_looplabel;
            alg_root(&v_looplabel, 1);
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_str(v_looplabel)}, 1), f_foldcase(NULL, (Value[]){v_thelabel}, 1)))) {
                Value ret_104 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_104;
            }
            alg_root_top = rt_57;
        }
        alg_root_top = rt_56;
    }
    Value ret_105 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_105;
    Value ret_106 = alg_nil();
    alg_root_top = rt_base;
    return ret_106;
}

static Value m_parser_jumplabel_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_keyword = alg_widen(args[0], "Token");
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    Value v_verb = alg_widen(args[1], "String");
    (void)v_verb;
    alg_root(&v_verb, 1);
    Value v_named = alg_nil();
    (void)v_named;
    alg_root(&v_named, 1);
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)))) {
        Value ret_107 = alg_string("");
        alg_root_top = rt_base;
        return ret_107;
    }
    (void)((v_named = alg_str(alg_property(alg_invoke(v_this, "Advance", NULL, 0), "Lexeme"))));
    if (alg_truthy(alg_not(alg_invoke(v_this, "EnclosingLoop", (Value[]){v_named}, 1)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_keyword, alg_add(alg_add(alg_string("No enclosing loop is labelled '"), v_named), alg_string("'."))}, 2));
    }
    Value ret_108 = v_named;
    alg_root_top = rt_base;
    return ret_108;
    Value ret_109 = alg_nil();
    alg_root_top = rt_base;
    return ret_109;
}

static Value m_parser_continuestatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_keyword = alg_nil();
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    (void)((v_keyword = alg_invoke(v_this, "Previous", NULL, 0)));
    if (alg_truthy(alg_equal(alg_property(v_this, "LoopDepth"), alg_int(0)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_keyword, alg_string("Must be inside a loop to use 'continue'.")}, 2));
    }
    Value v_named = alg_invoke(v_this, "JumpLabel", (Value[]){v_keyword, alg_string("continue")}, 2);
    (void)v_named;
    alg_root(&v_named, 1);
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after 'continue'.")}, 2));
    Value v_beginning = alg_new(k_continuestmt, (Value[]){v_keyword}, 1);
    (void)v_beginning;
    alg_root(&v_beginning, 1);
    (void)(alg_set_property(v_beginning, "Label", v_named));
    Value ret_110 = v_beginning;
    alg_root_top = rt_base;
    return ret_110;
    Value ret_111 = alg_nil();
    alg_root_top = rt_base;
    return ret_111;
}

static Value m_parser_operatortoken_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy((or_36 = (or_35 = (or_34 = (or_33 = (or_32 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVplus}, 1), alg_truthy(or_32) ? or_32 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVminus}, 1)), alg_truthy(or_33) ? or_33 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVstar}, 1)), alg_truthy(or_34) ? or_34 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVslash}, 1)), alg_truthy(or_35) ? or_35 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVdiv}, 1)), alg_truthy(or_36) ? or_36 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVmod}, 1)))) {
        Value ret_112 = alg_invoke(v_this, "Advance", NULL, 0);
        alg_root_top = rt_base;
        return ret_112;
    }
    if (alg_truthy((or_41 = (or_40 = (or_39 = (or_38 = (or_37 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVampersand}, 1), alg_truthy(or_37) ? or_37 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVpipe}, 1)), alg_truthy(or_38) ? or_38 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVcaret}, 1)), alg_truthy(or_39) ? or_39 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVtilde}, 1)), alg_truthy(or_40) ? or_40 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVshiftVleft}, 1)), alg_truthy(or_41) ? or_41 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVshiftVright}, 1)))) {
        Value ret_113 = alg_invoke(v_this, "Advance", NULL, 0);
        alg_root_top = rt_base;
        return ret_113;
    }
    alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_invoke(v_this, "Peek", NULL, 0), alg_string("An operator must be one of + - * / div mod & | ^ ~ << >>.")}, 2));
    Value ret_114 = alg_nil();
    alg_root_top = rt_base;
    return ret_114;
}

static Value m_parser_parseoperator_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_params = alg_nil();
    (void)v_params;
    alg_root(&v_params, 1);
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    (void)((v_name = alg_invoke(v_this, "OperatorToken", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVleftVparen, alg_string("Expect '(' after operator.")}, 2));
    (void)((v_params = alg_list()));
    Value v_paramtypes = alg_list();
    (void)v_paramtypes;
    alg_root(&v_paramtypes, 1);
    Value v_paramgenerics = alg_list();
    (void)v_paramgenerics;
    alg_root(&v_paramgenerics, 1);
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVrightVparen}, 1)))) {
        {
            (void)(alg_invoke(v_params, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect parameter name.")}, 2)}, 1));
            (void)(alg_invoke(v_paramtypes, "Add", (Value[]){alg_invoke(v_this, "ParameterType", NULL, 0)}, 1));
            (void)(alg_invoke(v_paramgenerics, "Add", (Value[]){alg_property(v_this, "LastGeneric")}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_string("Expect ')' after operator parameters.")}, 2));
    if (alg_truthy(alg_greater(alg_property(v_params, "Length"), alg_int(1)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_name, alg_string("An operator takes one argument, or none for a unary one.")}, 2));
    }
    Value v_returntype = alg_string("");
    (void)v_returntype;
    alg_root(&v_returntype, 1);
    Value v_returngeneric = alg_string("");
    (void)v_returngeneric;
    alg_root(&v_returngeneric, 1);
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
        {
            (void)((v_returntype = f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect type name.")}, 2), "Lexeme")}, 1)));
            if (alg_truthy((or_42 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_returntype}, 1), !alg_truthy(or_42) ? or_42 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))) {
                (void)((v_returngeneric = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect generic type.")}, 2), "Lexeme"))));
            }
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after operator signature.")}, 2));
    (void)((v_body = alg_list()));
    (void)(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_body}, 1));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_string("Expect 'begin' before operator body.")}, 2));
    Value v_wasinprocedure = alg_property(v_this, "InProcedure");
    (void)v_wasinprocedure;
    alg_root(&v_wasinprocedure, 1);
    (void)(alg_set_property(v_this, "InProcedure", alg_bool(false)));
    (void)(alg_set_property(v_this, "SubprogramDepth", alg_add(alg_property(v_this, "SubprogramDepth"), alg_int(1))));
    Value v_rest = alg_invoke(v_this, "Block", NULL, 0);
    (void)v_rest;
    alg_root(&v_rest, 1);
    (void)(alg_set_property(v_this, "SubprogramDepth", alg_subtract(alg_property(v_this, "SubprogramDepth"), alg_int(1))));
    (void)(alg_set_property(v_this, "InProcedure", v_wasinprocedure));
    {
        int32_t rt_58 = alg_root_top;
        Value loop_115 = alg_iterable(v_rest);
        (void)loop_115;
        alg_root(&loop_115, 1);
        for (int32_t at_115 = 0; at_115 < alg_iterable_count(loop_115); at_115++) {
            int32_t rt_59 = alg_root_top;
            Value v_each = alg_iterable_at(loop_115, at_115);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_invoke(v_body, "Add", (Value[]){v_each}, 1));
            alg_root_top = rt_59;
        }
        alg_root_top = rt_58;
    }
    Value v_theoperator = alg_new(k_functionstmt, (Value[]){v_name, v_params, v_body}, 3);
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    (void)(alg_set_property(v_theoperator, "ReturnType", v_returntype));
    (void)(alg_set_property(v_theoperator, "ReturnGeneric", v_returngeneric));
    (void)(alg_set_property(v_theoperator, "ParamTypes", v_paramtypes));
    (void)(alg_set_property(v_theoperator, "ParamGenerics", v_paramgenerics));
    Value ret_116 = v_theoperator;
    alg_root_top = rt_base;
    return ret_116;
    Value ret_117 = alg_nil();
    alg_root_top = rt_base;
    return ret_117;
}

static Value m_parser_parseproperty_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    (void)((v_name = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect property name.")}, 2)));
    Value v_returntype = alg_string("");
    (void)v_returntype;
    alg_root(&v_returntype, 1);
    Value v_returngeneric = alg_string("");
    (void)v_returngeneric;
    alg_root(&v_returngeneric, 1);
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
        {
            (void)((v_returntype = f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect type name.")}, 2), "Lexeme")}, 1)));
            if (alg_truthy((or_43 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_returntype}, 1), !alg_truthy(or_43) ? or_43 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))) {
                (void)((v_returngeneric = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect generic type.")}, 2), "Lexeme"))));
            }
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after property signature.")}, 2));
    (void)((v_body = alg_list()));
    (void)(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_body}, 1));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_string("Expect 'begin' before property body.")}, 2));
    Value v_wasinprocedure = alg_property(v_this, "InProcedure");
    (void)v_wasinprocedure;
    alg_root(&v_wasinprocedure, 1);
    (void)(alg_set_property(v_this, "InProcedure", alg_bool(false)));
    (void)(alg_set_property(v_this, "SubprogramDepth", alg_add(alg_property(v_this, "SubprogramDepth"), alg_int(1))));
    Value v_rest = alg_invoke(v_this, "Block", NULL, 0);
    (void)v_rest;
    alg_root(&v_rest, 1);
    (void)(alg_set_property(v_this, "SubprogramDepth", alg_subtract(alg_property(v_this, "SubprogramDepth"), alg_int(1))));
    (void)(alg_set_property(v_this, "InProcedure", v_wasinprocedure));
    {
        int32_t rt_60 = alg_root_top;
        Value loop_118 = alg_iterable(v_rest);
        (void)loop_118;
        alg_root(&loop_118, 1);
        for (int32_t at_118 = 0; at_118 < alg_iterable_count(loop_118); at_118++) {
            int32_t rt_61 = alg_root_top;
            Value v_each = alg_iterable_at(loop_118, at_118);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_invoke(v_body, "Add", (Value[]){v_each}, 1));
            alg_root_top = rt_61;
        }
        alg_root_top = rt_60;
    }
    Value v_theproperty = alg_new(k_functionstmt, (Value[]){v_name, alg_list(), v_body}, 3);
    (void)v_theproperty;
    alg_root(&v_theproperty, 1);
    (void)(alg_set_property(v_theproperty, "ReturnType", v_returntype));
    (void)(alg_set_property(v_theproperty, "ReturnGeneric", v_returngeneric));
    (void)(alg_set_property(v_theproperty, "IsProperty", alg_bool(true)));
    Value ret_119 = v_theproperty;
    alg_root_top = rt_base;
    return ret_119;
    Value ret_120 = alg_nil();
    alg_root_top = rt_base;
    return ret_120;
}

static Value m_parser_gotostatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_keyword = alg_nil();
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    (void)((v_keyword = alg_invoke(v_this, "Previous", NULL, 0)));
    Value v_named = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect a label after 'goto'.")}, 2), "Lexeme"));
    (void)v_named;
    alg_root(&v_named, 1);
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after 'goto'.")}, 2));
    Value ret_121 = alg_new(k_gotostmt, (Value[]){v_keyword, v_named}, 2);
    alg_root_top = rt_base;
    return ret_121;
    Value ret_122 = alg_nil();
    alg_root_top = rt_base;
    return ret_122;
}

static Value m_parser_raisestatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_keyword = alg_nil();
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    (void)((v_keyword = alg_invoke(v_this, "Previous", NULL, 0)));
    (void)((v_value = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after raised value.")}, 2));
    Value ret_123 = alg_new(k_raisestmt, (Value[]){v_keyword, v_value}, 2);
    alg_root_top = rt_base;
    return ret_123;
    Value ret_124 = alg_nil();
    alg_root_top = rt_base;
    return ret_124;
}

static Value m_parser_trystatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_nil();
    (void)v_statements;
    alg_root(&v_statements, 1);
    Value v_handlers = alg_nil();
    (void)v_handlers;
    alg_root(&v_handlers, 1);
    Value v_hashandlers = alg_nil();
    (void)v_hashandlers;
    alg_root(&v_hashandlers, 1);
    Value v_variable = alg_nil();
    (void)v_variable;
    alg_root(&v_variable, 1);
    Value v_thetype = alg_nil();
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    Value v_trailing = alg_nil();
    (void)v_trailing;
    alg_root(&v_trailing, 1);
    Value v_exceptstmts = alg_nil();
    (void)v_exceptstmts;
    alg_root(&v_exceptstmts, 1);
    (void)((v_statements = alg_list()));
    while (alg_truthy((or_44 = alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVexcept}, 1)), !alg_truthy(or_44) ? or_44 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
        (void)(alg_invoke(v_statements, "Add", (Value[]){alg_invoke(v_this, "Statement", NULL, 0)}, 1));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVexcept, alg_string("Expect 'except' after try block.")}, 2));
    (void)((v_handlers = alg_map()));
    (void)((v_hashandlers = alg_bool(false)));
    while (alg_truthy(alg_invoke(v_this, "CheckWord", (Value[]){alg_string("on")}, 1))) {
        {
            (void)((v_hashandlers = alg_bool(true)));
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)((v_variable = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expected variable name.")}, 2)));
            (void)((v_thetype = alg_widen(alg_nil(), "Token")));
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
                (void)((v_thetype = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expected type.")}, 2)));
            }
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdo, alg_string("Expected 'do'.")}, 2));
            (void)((v_key = alg_string("default")));
            if (alg_truthy(alg_not_equal(v_thetype, alg_nil()))) {
                (void)((v_key = alg_str(alg_property(v_thetype, "Lexeme"))));
            }
            if (alg_truthy(alg_invoke(v_handlers, "Contains", (Value[]){v_key}, 1))) {
                {
                    if (alg_truthy(alg_equal(v_thetype, alg_nil()))) {
                        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_variable, alg_string("A handler for any exception is already given.")}, 2));
                    }
                    alg_raise(alg_invoke(v_this, "Error", (Value[]){v_thetype, alg_add(alg_add(alg_string("Duplicate handler for '"), v_key), alg_string("'."))}, 2));
                }
            }
            (void)(alg_invoke(v_handlers, "Put", (Value[]){v_key, alg_new(k_excepthandler, (Value[]){alg_str(alg_property(v_variable, "Lexeme")), alg_invoke(v_this, "Statement", NULL, 0)}, 2)}, 2));
        }
    }
    (void)((v_trailing = alg_invoke(v_this, "Peek", NULL, 0)));
    (void)((v_exceptstmts = alg_list()));
    while (alg_truthy((or_45 = alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1)), !alg_truthy(or_45) ? or_45 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
        (void)(alg_invoke(v_exceptstmts, "Add", (Value[]){alg_invoke(v_this, "Statement", NULL, 0)}, 1));
    }
    if (alg_truthy((or_46 = alg_not(v_hashandlers), alg_truthy(or_46) ? or_46 : alg_not(alg_property(v_exceptstmts, "IsEmpty"))))) {
        {
            if (alg_truthy((or_47 = alg_not(alg_property(v_exceptstmts, "IsEmpty")), !alg_truthy(or_47) ? or_47 : alg_invoke(v_handlers, "Contains", (Value[]){alg_string("default")}, 1)))) {
                alg_raise(alg_invoke(v_this, "Error", (Value[]){v_trailing, alg_string("A handler for any exception is already given by an untyped 'on'.")}, 2));
            }
            (void)(alg_invoke(v_handlers, "Put", (Value[]){alg_string("default"), alg_new(k_excepthandler, (Value[]){alg_string("Any"), alg_new(k_blockstmt, (Value[]){v_exceptstmts}, 1)}, 2)}, 2));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVend, alg_string("Expect 'end' after except block.")}, 2));
    Value ret_125 = alg_new(k_trystmt, (Value[]){alg_new(k_blockstmt, (Value[]){v_statements}, 1), v_handlers}, 2);
    alg_root_top = rt_base;
    return ret_125;
    Value ret_126 = alg_nil();
    alg_root_top = rt_base;
    return ret_126;
}

static Value m_parser_vardeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_127 = alg_invoke(v_this, "VarDeclaration", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect variable name.")}, 2)}, 1);
    alg_root_top = rt_base;
    return ret_127;
    Value ret_128 = alg_nil();
    alg_root_top = rt_base;
    return ret_128;
}

static Value m_parser_vardeclaration_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    Value v_typename = alg_string("");
    (void)v_typename;
    alg_root(&v_typename, 1);
    Value v_generic = alg_string("");
    (void)v_generic;
    alg_root(&v_generic, 1);
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
        {
            (void)((v_typename = f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect type name.")}, 2), "Lexeme")}, 1)));
            if (alg_truthy((or_48 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_typename}, 1), !alg_truthy(or_48) ? or_48 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))) {
                (void)((v_generic = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect generic type.")}, 2), "Lexeme"))));
            }
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVassign}, 1))) {
        {
            (void)((v_initializer = alg_invoke(v_this, "Expression", NULL, 0)));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after variable declaration.")}, 2));
    Value v_thevar = alg_new(k_varstmt, (Value[]){v_name, v_initializer}, 2);
    (void)v_thevar;
    alg_root(&v_thevar, 1);
    (void)(alg_set_property(v_thevar, "TypeName", v_typename));
    (void)(alg_set_property(v_thevar, "Generic", v_generic));
    Value ret_129 = v_thevar;
    alg_root_top = rt_base;
    return ret_129;
    Value ret_130 = alg_nil();
    alg_root_top = rt_base;
    return ret_130;
}

static Value m_parser_expressionstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    (void)((v_theexpr = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after expression.")}, 2));
    Value ret_131 = alg_new(k_expressionstmt, (Value[]){v_theexpr}, 1);
    alg_root_top = rt_base;
    return ret_131;
    Value ret_132 = alg_nil();
    alg_root_top = rt_base;
    return ret_132;
}

static Value m_parser_isextensiondeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_not(alg_invoke(v_this, "CheckWord", (Value[]){alg_string("extension")}, 1)))) {
        Value ret_133 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_133;
    }
    Value ret_134 = (or_49 = alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVfunction), alg_truthy(or_49) ? or_49 : alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVprocedure));
    alg_root_top = rt_base;
    return ret_134;
    Value ret_135 = alg_nil();
    alg_root_top = rt_base;
    return ret_135;
}

static Value m_parser_extensiondeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_word = alg_nil();
    (void)v_word;
    alg_root(&v_word, 1);
    (void)((v_word = alg_invoke(v_this, "Advance", NULL, 0)));
    if (alg_truthy(alg_greater(alg_property(v_this, "SubprogramDepth"), alg_int(0)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_word, alg_string("'extension' applies only to a top-level subprogram.")}, 2));
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVprocedure}, 1))) {
        Value ret_136 = alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("procedure"), alg_bool(true)}, 2);
        alg_root_top = rt_base;
        return ret_136;
    }
    (void)(alg_invoke(v_this, "Advance", NULL, 0));
    Value ret_137 = alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("function"), alg_bool(true)}, 2);
    alg_root_top = rt_base;
    return ret_137;
    Value ret_138 = alg_nil();
    alg_root_top = rt_base;
    return ret_138;
}

static Value m_parser_parsefunction_2_string_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_kind = alg_widen(args[0], "String");
    (void)v_kind;
    alg_root(&v_kind, 1);
    Value v_isextension = alg_widen(args[1], "Boolean");
    (void)v_isextension;
    alg_root(&v_isextension, 1);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_params = alg_nil();
    (void)v_params;
    alg_root(&v_params, 1);
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    (void)((v_name = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_add(alg_add(alg_string("Expect "), v_kind), alg_string(" name."))}, 2)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVleftVparen, alg_add(alg_add(alg_string("Expect '(' after "), v_kind), alg_string(" name."))}, 2));
    (void)((v_params = alg_list()));
    Value v_paramtypes = alg_list();
    (void)v_paramtypes;
    alg_root(&v_paramtypes, 1);
    Value v_paramgenerics = alg_list();
    (void)v_paramgenerics;
    alg_root(&v_paramgenerics, 1);
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVrightVparen}, 1)))) {
        {
            (void)(alg_invoke(v_params, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect parameter name.")}, 2)}, 1));
            (void)(alg_invoke(v_paramtypes, "Add", (Value[]){alg_invoke(v_this, "ParameterType", NULL, 0)}, 1));
            (void)(alg_invoke(v_paramgenerics, "Add", (Value[]){alg_property(v_this, "LastGeneric")}, 1));
            while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))) {
                {
                    if (alg_truthy(alg_greater_equal(alg_property(v_params, "Length"), alg_int(255)))) {
                        {
                            alg_raise(alg_string("Can't have more than 255 parameters."));
                        }
                    }
                    (void)(alg_invoke(v_params, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect parameter name.")}, 2)}, 1));
                    (void)(alg_invoke(v_paramtypes, "Add", (Value[]){alg_invoke(v_this, "ParameterType", NULL, 0)}, 1));
                    (void)(alg_invoke(v_paramgenerics, "Add", (Value[]){alg_property(v_this, "LastGeneric")}, 1));
                }
            }
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_string("Expect ')' after parameters.")}, 2));
    if (alg_truthy(v_isextension)) {
        {
            if (alg_truthy(alg_equal(alg_property(v_params, "Length"), alg_int(0)))) {
                alg_raise(alg_invoke(v_this, "Error", (Value[]){v_name, alg_string("An extension must declare a receiver.")}, 2));
            }
            if (alg_truthy(alg_equal(alg_str(alg_subscript_get(v_paramtypes, alg_int(0))), alg_string("")))) {
                alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_subscript_get(v_params, alg_int(0)), alg_string("An extension's receiver must have a written type.")}, 2));
            }
        }
    }
    Value v_returntype = alg_string("");
    (void)v_returntype;
    alg_root(&v_returntype, 1);
    Value v_returngeneric = alg_string("");
    (void)v_returngeneric;
    alg_root(&v_returngeneric, 1);
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
        (void)((v_returntype = f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect return type.")}, 2), "Lexeme")}, 1)));
    }
    if (alg_truthy((or_50 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_returntype}, 1), !alg_truthy(or_50) ? or_50 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))) {
        (void)((v_returngeneric = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect generic type.")}, 2), "Lexeme"))));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_add(alg_add(alg_string("Expect ';' after "), v_kind), alg_string(" signature."))}, 2));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVexternal}, 1))) {
        {
            int32_t rt_62 = alg_root_top;
            Value v_symbol = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVstring, alg_string("Expect a symbol name after 'external'.")}, 2);
            (void)v_symbol;
            alg_root(&v_symbol, 1);
            Value v_inlibrary = alg_string("");
            (void)v_inlibrary;
            alg_root(&v_inlibrary, 1);
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVin}, 1))) {
                (void)((v_inlibrary = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVstring, alg_string("Expect a library name after 'in'.")}, 2), "Literal"))));
            }
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after an external declaration.")}, 2));
            Value v_foreign = alg_new(k_functionstmt, (Value[]){v_name, v_params, alg_list()}, 3);
            (void)v_foreign;
            alg_root(&v_foreign, 1);
            (void)(alg_set_property(v_foreign, "ReturnType", v_returntype));
            (void)(alg_set_property(v_foreign, "ReturnGeneric", v_returngeneric));
            (void)(alg_set_property(v_foreign, "ParamTypes", v_paramtypes));
            (void)(alg_set_property(v_foreign, "ParamGenerics", v_paramgenerics));
            (void)(alg_set_property(v_foreign, "Symbol", alg_str(alg_property(v_symbol, "Literal"))));
            (void)(alg_set_property(v_foreign, "Library", v_inlibrary));
            (void)(alg_set_property(v_foreign, "IsExtension", v_isextension));
            Value ret_139 = v_foreign;
            alg_root_top = rt_base;
            return ret_139;
            alg_root_top = rt_62;
        }
    }
    (void)((v_body = alg_list()));
    (void)(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_body}, 1));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_add(alg_add(alg_string("Expect 'begin' before "), v_kind), alg_string(" body."))}, 2));
    Value v_wasinprocedure = alg_property(v_this, "InProcedure");
    (void)v_wasinprocedure;
    alg_root(&v_wasinprocedure, 1);
    (void)(alg_set_property(v_this, "InProcedure", alg_equal(v_kind, alg_string("procedure"))));
    (void)(alg_set_property(v_this, "SubprogramDepth", alg_add(alg_property(v_this, "SubprogramDepth"), alg_int(1))));
    Value v_rest = alg_invoke(v_this, "Block", NULL, 0);
    (void)v_rest;
    alg_root(&v_rest, 1);
    (void)(alg_set_property(v_this, "SubprogramDepth", alg_subtract(alg_property(v_this, "SubprogramDepth"), alg_int(1))));
    (void)(alg_set_property(v_this, "InProcedure", v_wasinprocedure));
    {
        int32_t rt_63 = alg_root_top;
        Value loop_140 = alg_iterable(v_rest);
        (void)loop_140;
        alg_root(&loop_140, 1);
        for (int32_t at_140 = 0; at_140 < alg_iterable_count(loop_140); at_140++) {
            int32_t rt_64 = alg_root_top;
            Value v_each = alg_iterable_at(loop_140, at_140);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_invoke(v_body, "Add", (Value[]){v_each}, 1));
            alg_root_top = rt_64;
        }
        alg_root_top = rt_63;
    }
    Value v_thefunction = alg_new(k_functionstmt, (Value[]){v_name, v_params, v_body}, 3);
    (void)v_thefunction;
    alg_root(&v_thefunction, 1);
    (void)(alg_set_property(v_thefunction, "ReturnType", v_returntype));
    (void)(alg_set_property(v_thefunction, "ReturnGeneric", v_returngeneric));
    (void)(alg_set_property(v_thefunction, "ParamTypes", v_paramtypes));
    (void)(alg_set_property(v_thefunction, "ParamGenerics", v_paramgenerics));
    (void)(alg_set_property(v_thefunction, "IsExtension", v_isextension));
    Value ret_141 = v_thefunction;
    alg_root_top = rt_base;
    return ret_141;
    Value ret_142 = alg_nil();
    alg_root_top = rt_base;
    return ret_142;
}

static Value m_parser_parametertype_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_set_property(v_this, "LastGeneric", alg_string("")));
    if (alg_truthy(alg_not(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1)))) {
        Value ret_143 = alg_string("");
        alg_root_top = rt_base;
        return ret_143;
    }
    Value v_typename = f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect type name.")}, 2), "Lexeme")}, 1);
    (void)v_typename;
    alg_root(&v_typename, 1);
    if (alg_truthy((or_51 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_typename}, 1), !alg_truthy(or_51) ? or_51 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))) {
        (void)(alg_set_property(v_this, "LastGeneric", alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect generic type.")}, 2), "Lexeme"))));
    }
    Value ret_144 = v_typename;
    alg_root_top = rt_base;
    return ret_144;
    Value ret_145 = alg_nil();
    alg_root_top = rt_base;
    return ret_145;
}

static Value m_parser_block_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_nil();
    (void)v_statements;
    alg_root(&v_statements, 1);
    (void)((v_statements = alg_list()));
    while (alg_truthy((or_52 = alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1)), !alg_truthy(or_52) ? or_52 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
        {
            (void)(alg_invoke(v_statements, "Add", (Value[]){alg_invoke(v_this, "Declaration", NULL, 0)}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVend, alg_string("Expect 'end' after block.")}, 2));
    Value ret_146 = v_statements;
    alg_root_top = rt_base;
    return ret_146;
    Value ret_147 = alg_nil();
    alg_root_top = rt_base;
    return ret_147;
}

static Value m_parser_assignment_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_equals = alg_nil();
    (void)v_equals;
    alg_root(&v_equals, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    (void)((v_theexpr = alg_invoke(v_this, "ParseOr", NULL, 0)));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVassign}, 1))) {
        {
            (void)((v_equals = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_value = alg_invoke(v_this, "Assignment", NULL, 0)));
            if (alg_truthy(alg_equal(alg_property(v_theexpr, "ClassName"), alg_string("VariableExpr")))) {
                Value ret_148 = alg_new(k_assignexpr, (Value[]){alg_property(v_theexpr, "Name"), v_value}, 2);
                alg_root_top = rt_base;
                return ret_148;
            } else {
                if (alg_truthy(alg_equal(alg_property(v_theexpr, "ClassName"), alg_string("GetExpr")))) {
                    Value ret_149 = alg_new(k_setexpr, (Value[]){alg_property(v_theexpr, "Obj"), alg_property(v_theexpr, "Name"), v_value}, 3);
                    alg_root_top = rt_base;
                    return ret_149;
                } else {
                    if (alg_truthy(alg_equal(alg_property(v_theexpr, "ClassName"), alg_string("SubscriptExpr")))) {
                        Value ret_150 = alg_new(k_setsubscriptexpr, (Value[]){alg_property(v_theexpr, "Obj"), alg_property(v_theexpr, "Index"), v_value, alg_property(v_theexpr, "Bracket")}, 4);
                        alg_root_top = rt_base;
                        return ret_150;
                    }
                }
            }
            alg_raise(alg_string("Invalid assignment target."));
        }
    }
    Value ret_151 = v_theexpr;
    alg_root_top = rt_base;
    return ret_151;
    Value ret_152 = alg_nil();
    alg_root_top = rt_base;
    return ret_152;
}

static Value m_parser_parseor_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_op = alg_nil();
    (void)v_op;
    alg_root(&v_op, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    (void)((v_theexpr = alg_invoke(v_this, "ParseAnd", NULL, 0)));
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVor}, 1))) {
        {
            (void)((v_op = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_right = alg_invoke(v_this, "ParseAnd", NULL, 0)));
            (void)((v_theexpr = alg_widen(alg_new(k_logicalexpr, (Value[]){v_theexpr, v_op, v_right}, 3), "Expr")));
        }
    }
    Value ret_153 = v_theexpr;
    alg_root_top = rt_base;
    return ret_153;
    Value ret_154 = alg_nil();
    alg_root_top = rt_base;
    return ret_154;
}

static Value m_parser_parseand_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_op = alg_nil();
    (void)v_op;
    alg_root(&v_op, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    (void)((v_theexpr = alg_invoke(v_this, "Equality", NULL, 0)));
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVand}, 1))) {
        {
            (void)((v_op = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_right = alg_invoke(v_this, "Equality", NULL, 0)));
            (void)((v_theexpr = alg_widen(alg_new(k_logicalexpr, (Value[]){v_theexpr, v_op, v_right}, 3), "Expr")));
        }
    }
    Value ret_155 = v_theexpr;
    alg_root_top = rt_base;
    return ret_155;
    Value ret_156 = alg_nil();
    alg_root_top = rt_base;
    return ret_156;
}

static Value m_parser_expression_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    (void)((v_theexpr = alg_invoke(v_this, "Assignment", NULL, 0)));
    Value ret_157 = v_theexpr;
    alg_root_top = rt_base;
    return ret_157;
    Value ret_158 = alg_nil();
    alg_root_top = rt_base;
    return ret_158;
}

static Value m_parser_declaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_invoke(v_this, "IsTestBlock", NULL, 0))) {
        Value ret_159 = alg_invoke(v_this, "TestDeclaration", NULL, 0);
        alg_root_top = rt_base;
        return ret_159;
    }
    Value ret_160 = alg_invoke(v_this, "Statement", NULL, 0);
    alg_root_top = rt_base;
    return ret_160;
    Value ret_161 = alg_nil();
    alg_root_top = rt_base;
    return ret_161;
}

static Value m_parser_istestblock_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)))) {
        Value ret_162 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_162;
    }
    if (alg_truthy(alg_not_equal(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "Lexeme"), alg_string("test")))) {
        Value ret_163 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_163;
    }
    Value ret_164 = (or_53 = alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVstring), alg_truthy(or_53) ? or_53 : alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVchar));
    alg_root_top = rt_base;
    return ret_164;
    Value ret_165 = alg_nil();
    alg_root_top = rt_base;
    return ret_165;
}

static Value m_parser_testdeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    (void)(alg_invoke(v_this, "Advance", NULL, 0));
    if (alg_truthy(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVchar}, 1))) {
        (void)((v_name = alg_invoke(v_this, "Advance", NULL, 0)));
    } else {
        (void)((v_name = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVstring, alg_string("Expect a test name.")}, 2)));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after test name.")}, 2));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_string("Expect 'begin' before test body.")}, 2));
    (void)((v_body = alg_invoke(v_this, "Block", NULL, 0)));
    Value ret_166 = alg_new(k_functionstmt, (Value[]){v_name, alg_list(), v_body}, 3);
    alg_root_top = rt_base;
    return ret_166;
    Value ret_167 = alg_nil();
    alg_root_top = rt_base;
    return ret_167;
}

static Value m_parser_enumdeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_members = alg_nil();
    (void)v_members;
    alg_root(&v_members, 1);
    (void)((v_name = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect enum name.")}, 2)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVequal, alg_string("Expect '=' after enum declaration.")}, 2));
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVleftVparen}, 1)))) {
        Value ret_168 = alg_invoke(v_this, "SubrangeDeclaration", (Value[]){v_name}, 1);
        alg_root_top = rt_base;
        return ret_168;
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVleftVparen, alg_string("Expect '(' before enum members.")}, 2));
    (void)((v_members = alg_list()));
    (void)(alg_invoke(v_members, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect member name.")}, 2)}, 1));
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))) {
        (void)(alg_invoke(v_members, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect member name.")}, 2)}, 1));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_string("Expect ')' after enum members.")}, 2));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after enum declaration.")}, 2));
    Value ret_169 = alg_new(k_enumstmt, (Value[]){v_name, v_members}, 2);
    alg_root_top = rt_base;
    return ret_169;
    Value ret_170 = alg_nil();
    alg_root_top = rt_base;
    return ret_170;
}

static Value m_parser_subrangedeclaration_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_low = alg_nil();
    (void)v_low;
    alg_root(&v_low, 1);
    Value v_high = alg_nil();
    (void)v_high;
    alg_root(&v_high, 1);
    (void)((v_low = alg_invoke(v_this, "SubrangeBound", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdotVdot, alg_string("Expect '..' between subrange bounds.")}, 2));
    (void)((v_high = alg_invoke(v_this, "SubrangeBound", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after subrange declaration.")}, 2));
    if (alg_truthy(alg_greater(v_low, v_high))) {
        (void)(alg_invoke(v_this, "Error", (Value[]){v_name, alg_add(alg_add(alg_add(alg_add(alg_string("A subrange must not be empty: "), alg_str(v_low)), alg_string(" is above ")), alg_str(v_high)), alg_char_value(46))}, 2));
    }
    Value ret_171 = alg_new(k_subrangestmt, (Value[]){v_name, v_low, v_high}, 3);
    alg_root_top = rt_base;
    return ret_171;
    Value ret_172 = alg_nil();
    alg_root_top = rt_base;
    return ret_172;
}

static Value m_parser_subrangebound_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_negative = alg_nil();
    (void)v_negative;
    alg_root(&v_negative, 1);
    (void)((v_negative = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVminus}, 1)));
    Value v_bound = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVinteger, alg_string("Expect an integer bound.")}, 2);
    (void)v_bound;
    alg_root(&v_bound, 1);
    if (alg_truthy(v_negative)) {
        Value ret_173 = alg_subtract(alg_int(0), (alg_cast(alg_property(v_bound, "Literal"), "Integer")));
        alg_root_top = rt_base;
        return ret_173;
    }
    Value ret_174 = alg_cast(alg_property(v_bound, "Literal"), "Integer");
    alg_root_top = rt_base;
    return ret_174;
    Value ret_175 = alg_nil();
    alg_root_top = rt_base;
    return ret_175;
}

static Value m_parser_classdeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_176 = alg_invoke(v_this, "ClassDeclaration", (Value[]){alg_string("class")}, 1);
    alg_root_top = rt_base;
    return ret_176;
    Value ret_177 = alg_nil();
    alg_root_top = rt_base;
    return ret_177;
}

static Value m_parser_classdeclaration_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_kind = alg_widen(args[0], "String");
    (void)v_kind;
    alg_root(&v_kind, 1);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_methods = alg_nil();
    (void)v_methods;
    alg_root(&v_methods, 1);
    Value v_fields = alg_nil();
    (void)v_fields;
    alg_root(&v_fields, 1);
    Value v_superclass = alg_nil();
    (void)v_superclass;
    alg_root(&v_superclass, 1);
    (void)((v_name = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_add(alg_add(alg_string("Expect "), v_kind), alg_string(" name."))}, 2)));
    (void)((v_superclass = alg_cast(alg_nil(), "VariableExpr")));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVparen}, 1))) {
        {
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect superclass name.")}, 2));
            (void)((v_superclass = alg_new(k_variableexpr, (Value[]){alg_invoke(v_this, "Previous", NULL, 0)}, 1)));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_string("Expect ')' after superclass name.")}, 2));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_add(alg_add(alg_string("Expect ';' after "), v_kind), alg_string(" declaration."))}, 2));
    (void)(alg_set_property(v_this, "ClassPrivates", alg_list()));
    (void)(alg_set_property(v_this, "InPrivateSection", alg_bool(false)));
    (void)((v_fields = alg_list()));
    Value v_section = alg_list();
    (void)v_section;
    alg_root(&v_section, 1);
    (void)(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_section, alg_bool(true)}, 2));
    {
        int32_t rt_65 = alg_root_top;
        Value loop_178 = alg_iterable(v_section);
        (void)loop_178;
        alg_root(&loop_178, 1);
        for (int32_t at_178 = 0; at_178 < alg_iterable_count(loop_178); at_178++) {
            int32_t rt_66 = alg_root_top;
            Value v_each = alg_iterable_at(loop_178, at_178);
            (void)v_each;
            alg_root(&v_each, 1);
            {
                if (alg_truthy(alg_is(v_each, "VarGroupStmt"))) {
                    {
                        {
                            int32_t rt_67 = alg_root_top;
                            Value loop_179 = alg_iterable(alg_property(v_each, "Names"));
                            (void)loop_179;
                            alg_root(&loop_179, 1);
                            for (int32_t at_179 = 0; at_179 < alg_iterable_count(loop_179); at_179++) {
                                int32_t rt_68 = alg_root_top;
                                Value v_thename = alg_iterable_at(loop_179, at_179);
                                (void)v_thename;
                                alg_root(&v_thename, 1);
                                {
                                    int32_t rt_69 = alg_root_top;
                                    Value v_field = alg_new(k_varstmt, (Value[]){v_thename, alg_property(v_each, "Initializer")}, 2);
                                    (void)v_field;
                                    alg_root(&v_field, 1);
                                    (void)(alg_set_property(v_field, "TypeName", alg_widen(alg_property(v_each, "TypeName"), "String")));
                                    (void)(alg_set_property(v_field, "Generic", alg_widen(alg_property(v_each, "Generic"), "String")));
                                    (void)(alg_invoke(v_fields, "Add", (Value[]){v_field}, 1));
                                    alg_root_top = rt_69;
                                }
                                alg_root_top = rt_68;
                            }
                            alg_root_top = rt_67;
                        }
                    }
                } else {
                    (void)(alg_invoke(v_fields, "Add", (Value[]){v_each}, 1));
                }
            }
            alg_root_top = rt_66;
        }
        alg_root_top = rt_65;
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_add(alg_add(alg_string("Expect 'begin' before "), v_kind), alg_string(" body."))}, 2));
    (void)(alg_set_property(v_this, "InPrivateSection", alg_bool(false)));
    (void)((v_methods = alg_list()));
    while (alg_truthy((or_54 = alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1)), !alg_truthy(or_54) ? or_54 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
        {
            int32_t rt_70 = alg_root_top;
            while (alg_truthy(alg_invoke(v_this, "MatchVisibility", NULL, 0))) {
                {
                }
            }
            if (alg_truthy((or_55 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1), alg_truthy(or_55) ? or_55 : alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
                break;
            }
            Value v_method = alg_nil();
            (void)v_method;
            alg_root(&v_method, 1);
            if (alg_truthy(alg_invoke(v_this, "CheckWord", (Value[]){alg_string("extension")}, 1))) {
                alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_invoke(v_this, "Peek", NULL, 0), alg_string("'extension' applies only to a top-level subprogram.")}, 2));
            }
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVconstructor}, 1))) {
                (void)((v_method = alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("constructor"), alg_bool(false)}, 2)));
            } else {
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVprocedure}, 1))) {
                    (void)((v_method = alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("procedure"), alg_bool(false)}, 2)));
                } else {
                    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVproperty}, 1))) {
                        (void)((v_method = alg_invoke(v_this, "ParseProperty", NULL, 0)));
                    } else {
                        if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVoperator}, 1))) {
                            (void)((v_method = alg_invoke(v_this, "ParseOperator", NULL, 0)));
                        } else {
                            {
                                (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVfunction, alg_string("Expect 'function', 'procedure' or 'constructor' in class body.")}, 2));
                                (void)((v_method = alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("method"), alg_bool(false)}, 2)));
                            }
                        }
                    }
                }
            }
            if (alg_truthy(alg_property(v_this, "InPrivateSection"))) {
                (void)(alg_invoke(alg_property(v_this, "ClassPrivates"), "Add", (Value[]){alg_str(alg_property(alg_property(v_method, "Name"), "Lexeme"))}, 1));
            }
            (void)(alg_invoke(v_methods, "Add", (Value[]){v_method}, 1));
            alg_root_top = rt_70;
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVend, alg_add(alg_add(alg_string("Expect 'end' after "), v_kind), alg_string(" body."))}, 2));
    if (alg_truthy(alg_equal(v_kind, alg_string("object")))) {
        {
            int32_t rt_71 = alg_root_top;
            Value v_theobject = alg_new(k_objectstmt, (Value[]){v_name, v_superclass, v_methods, v_fields}, 4);
            (void)v_theobject;
            alg_root(&v_theobject, 1);
            (void)(alg_set_property(v_theobject, "PrivateMembers", alg_property(v_this, "ClassPrivates")));
            Value ret_180 = v_theobject;
            alg_root_top = rt_base;
            return ret_180;
            alg_root_top = rt_71;
        }
    }
    Value v_theclass = alg_new(k_classstmt, (Value[]){v_name, v_superclass, v_methods, v_fields}, 4);
    (void)v_theclass;
    alg_root(&v_theclass, 1);
    (void)(alg_set_property(v_theclass, "PrivateMembers", alg_property(v_this, "ClassPrivates")));
    Value ret_181 = v_theclass;
    alg_root_top = rt_base;
    return ret_181;
    Value ret_182 = alg_nil();
    alg_root_top = rt_base;
    return ret_182;
}

static Value m_parser_equality_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    (void)((v_theexpr = alg_invoke(v_this, "Comparison", NULL, 0)));
    while (alg_truthy((or_56 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVnotVequal}, 1), alg_truthy(or_56) ? or_56 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVequal}, 1)))) {
        {
            (void)((v_theoperator = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_right = alg_invoke(v_this, "Comparison", NULL, 0)));
            (void)((v_theexpr = alg_widen(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3), "Expr")));
        }
    }
    Value ret_183 = v_theexpr;
    alg_root_top = rt_base;
    return ret_183;
    Value ret_184 = alg_nil();
    alg_root_top = rt_base;
    return ret_184;
}

static Value m_parser_comparison_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    (void)((v_theexpr = alg_invoke(v_this, "BitOr", NULL, 0)));
    while (alg_truthy(alg_bool(true))) {
        {
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVis}, 1))) {
                {
                    (void)((v_theexpr = alg_widen(alg_new(k_isexpr, (Value[]){v_theexpr, alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect type name after 'is'.")}, 2)}, 2), "Expr")));
                }
            } else {
                if (alg_truthy((or_60 = (or_59 = (or_58 = (or_57 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVgreater}, 1), alg_truthy(or_57) ? or_57 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVgreaterVequal}, 1)), alg_truthy(or_58) ? or_58 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVless}, 1)), alg_truthy(or_59) ? or_59 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVlessVequal}, 1)), alg_truthy(or_60) ? or_60 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVin}, 1)))) {
                    {
                        (void)((v_theoperator = alg_invoke(v_this, "Previous", NULL, 0)));
                        (void)((v_right = alg_invoke(v_this, "BitOr", NULL, 0)));
                        (void)((v_theexpr = alg_widen(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3), "Expr")));
                    }
                } else {
                    Value ret_185 = v_theexpr;
                    alg_root_top = rt_base;
                    return ret_185;
                }
            }
        }
    }
    Value ret_186 = v_theexpr;
    alg_root_top = rt_base;
    return ret_186;
    Value ret_187 = alg_nil();
    alg_root_top = rt_base;
    return ret_187;
}

static Value m_parser_bitor_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    (void)((v_theexpr = alg_invoke(v_this, "BitXor", NULL, 0)));
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVpipe}, 1))) {
        {
            (void)((v_theoperator = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_right = alg_invoke(v_this, "BitXor", NULL, 0)));
            (void)((v_theexpr = alg_widen(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3), "Expr")));
        }
    }
    Value ret_188 = v_theexpr;
    alg_root_top = rt_base;
    return ret_188;
    Value ret_189 = alg_nil();
    alg_root_top = rt_base;
    return ret_189;
}

static Value m_parser_bitxor_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    (void)((v_theexpr = alg_invoke(v_this, "BitAnd", NULL, 0)));
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcaret}, 1))) {
        {
            (void)((v_theoperator = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_right = alg_invoke(v_this, "BitAnd", NULL, 0)));
            (void)((v_theexpr = alg_widen(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3), "Expr")));
        }
    }
    Value ret_190 = v_theexpr;
    alg_root_top = rt_base;
    return ret_190;
    Value ret_191 = alg_nil();
    alg_root_top = rt_base;
    return ret_191;
}

static Value m_parser_bitand_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    (void)((v_theexpr = alg_invoke(v_this, "Term", NULL, 0)));
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVampersand}, 1))) {
        {
            (void)((v_theoperator = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_right = alg_invoke(v_this, "Term", NULL, 0)));
            (void)((v_theexpr = alg_widen(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3), "Expr")));
        }
    }
    Value ret_192 = v_theexpr;
    alg_root_top = rt_base;
    return ret_192;
    Value ret_193 = alg_nil();
    alg_root_top = rt_base;
    return ret_193;
}

static Value m_parser_term_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    (void)((v_theexpr = alg_invoke(v_this, "Factor", NULL, 0)));
    while (alg_truthy((or_61 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVminus}, 1), alg_truthy(or_61) ? or_61 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVplus}, 1)))) {
        {
            (void)((v_theoperator = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_right = alg_invoke(v_this, "Factor", NULL, 0)));
            (void)((v_theexpr = alg_widen(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3), "Expr")));
        }
    }
    Value ret_194 = v_theexpr;
    alg_root_top = rt_base;
    return ret_194;
    Value ret_195 = alg_nil();
    alg_root_top = rt_base;
    return ret_195;
}

static Value m_parser_factor_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    (void)((v_theexpr = alg_invoke(v_this, "Unary", NULL, 0)));
    while (alg_truthy((or_66 = (or_65 = (or_64 = (or_63 = (or_62 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVslash}, 1), alg_truthy(or_62) ? or_62 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVstar}, 1)), alg_truthy(or_63) ? or_63 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVdiv}, 1)), alg_truthy(or_64) ? or_64 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVmod}, 1)), alg_truthy(or_65) ? or_65 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVshiftVleft}, 1)), alg_truthy(or_66) ? or_66 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVshiftVright}, 1)))) {
        {
            (void)((v_theoperator = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_right = alg_invoke(v_this, "Unary", NULL, 0)));
            (void)((v_theexpr = alg_widen(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3), "Expr")));
        }
    }
    Value ret_196 = v_theexpr;
    alg_root_top = rt_base;
    return ret_196;
    Value ret_197 = alg_nil();
    alg_root_top = rt_base;
    return ret_197;
}

static Value m_parser_unary_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    if (alg_truthy((or_68 = (or_67 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVnot}, 1), alg_truthy(or_67) ? or_67 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVminus}, 1)), alg_truthy(or_68) ? or_68 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVtilde}, 1)))) {
        {
            (void)((v_theoperator = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_right = alg_invoke(v_this, "Unary", NULL, 0)));
            Value ret_198 = alg_new(k_unaryexpr, (Value[]){v_theoperator, v_right}, 2);
            alg_root_top = rt_base;
            return ret_198;
        }
    }
    (void)((v_theexpr = alg_invoke(v_this, "Call", NULL, 0)));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVas}, 1))) {
        (void)(alg_set_property(v_theexpr, "Cast", f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect typecast identifier.")}, 2), "Lexeme")}, 1)));
    }
    Value ret_199 = v_theexpr;
    alg_root_top = rt_base;
    return ret_199;
    Value ret_200 = alg_nil();
    alg_root_top = rt_base;
    return ret_200;
}

static Value m_parser_collectionliteral_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_keys = alg_nil();
    (void)v_keys;
    alg_root(&v_keys, 1);
    Value v_values = alg_nil();
    (void)v_values;
    alg_root(&v_values, 1);
    Value v_ismap = alg_nil();
    (void)v_ismap;
    alg_root(&v_ismap, 1);
    (void)((v_keys = alg_list()));
    (void)((v_values = alg_list()));
    (void)((v_ismap = alg_bool(false)));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
        {
            (void)((v_ismap = alg_bool(true)));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVbracket, alg_string("Expect ']' after map.")}, 2));
            Value ret_201 = alg_new(k_collectionexpr, (Value[]){alg_bool(true), v_keys, v_values}, 3);
            alg_root_top = rt_base;
            return ret_201;
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVrightVbracket}, 1))) {
        Value ret_202 = alg_new(k_collectionexpr, (Value[]){alg_bool(false), v_keys, v_values}, 3);
        alg_root_top = rt_base;
        return ret_202;
    }
    Value v_first = alg_invoke(v_this, "Expression", NULL, 0);
    (void)v_first;
    alg_root(&v_first, 1);
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
        {
            (void)((v_ismap = alg_bool(true)));
            (void)(alg_invoke(v_keys, "Add", (Value[]){v_first}, 1));
            (void)(alg_invoke(v_values, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
        }
    } else {
        (void)(alg_invoke(v_values, "Add", (Value[]){v_first}, 1));
    }
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))) {
        {
            if (alg_truthy(v_ismap)) {
                {
                    (void)(alg_invoke(v_keys, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
                    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVcolon, alg_string("Expect ':' after key.")}, 2));
                    (void)(alg_invoke(v_values, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
                }
            } else {
                (void)(alg_invoke(v_values, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
            }
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVbracket, alg_string("Expect ']' after list.")}, 2));
    Value ret_203 = alg_new(k_collectionexpr, (Value[]){v_ismap, v_keys, v_values}, 3);
    alg_root_top = rt_base;
    return ret_203;
    Value ret_204 = alg_nil();
    alg_root_top = rt_base;
    return ret_204;
}

static Value m_parser_call_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    (void)((v_theexpr = alg_invoke(v_this, "Primary", NULL, 0)));
    while (alg_truthy(alg_bool(true))) {
        {
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVparen}, 1))) {
                (void)((v_theexpr = alg_invoke(v_this, "FinishCall", (Value[]){v_theexpr}, 1)));
            } else {
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVbracket}, 1))) {
                    {
                        int32_t rt_72 = alg_root_top;
                        Value v_bracket = alg_invoke(v_this, "Previous", NULL, 0);
                        (void)v_bracket;
                        alg_root(&v_bracket, 1);
                        Value v_index = alg_invoke(v_this, "Expression", NULL, 0);
                        (void)v_index;
                        alg_root(&v_index, 1);
                        (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVbracket, alg_string("Expect ']' after subscript.")}, 2));
                        (void)((v_theexpr = alg_widen(alg_new(k_subscriptexpr, (Value[]){v_theexpr, v_index, v_bracket}, 3), "Expr")));
                        alg_root_top = rt_72;
                    }
                } else {
                    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVdot}, 1))) {
                        {
                            (void)((v_name = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect property name after '.'.")}, 2)));
                            (void)((v_theexpr = alg_widen(alg_new(k_getexpr, (Value[]){v_theexpr, v_name}, 2), "Expr")));
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    Value ret_205 = v_theexpr;
    alg_root_top = rt_base;
    return ret_205;
    Value ret_206 = alg_nil();
    alg_root_top = rt_base;
    return ret_206;
}

static Value m_parser_finishcall_1_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_callee = alg_widen(args[0], "Expr");
    (void)v_callee;
    alg_root(&v_callee, 1);
    Value v_arguments = alg_nil();
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    Value v_paren = alg_nil();
    (void)v_paren;
    alg_root(&v_paren, 1);
    (void)((v_arguments = alg_list()));
    (void)((v_names = alg_list()));
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVrightVparen}, 1)))) {
        {
            (void)(alg_invoke(v_this, "Argument", (Value[]){v_arguments, v_names}, 2));
            while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))) {
                {
                    if (alg_truthy(alg_greater_equal(alg_property(v_arguments, "Length"), alg_int(255)))) {
                        alg_raise(alg_string("Can't have more than 255 arguments."));
                    }
                    (void)(alg_invoke(v_this, "Argument", (Value[]){v_arguments, v_names}, 2));
                }
            }
        }
    }
    (void)((v_paren = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_string("Expect ')' after arguments.")}, 2)));
    Value v_thecall = alg_new(k_callexpr, (Value[]){v_callee, v_paren, v_arguments}, 3);
    (void)v_thecall;
    alg_root(&v_thecall, 1);
    (void)(alg_set_property(v_thecall, "ArgumentNames", v_names));
    Value ret_207 = v_thecall;
    alg_root_top = rt_base;
    return ret_207;
    Value ret_208 = alg_nil();
    alg_root_top = rt_base;
    return ret_208;
}

static Value m_parser_argument_2_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_names = alg_widen(args[1], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    if (alg_truthy((or_69 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1), !alg_truthy(or_69) ? or_69 : alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVcolon)))) {
        {
            int32_t rt_73 = alg_root_top;
            Value v_thename = alg_str(alg_property(alg_invoke(v_this, "Advance", NULL, 0), "Lexeme"));
            (void)v_thename;
            alg_root(&v_thename, 1);
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_invoke(v_names, "Add", (Value[]){v_thename}, 1));
            (void)(alg_invoke(v_arguments, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
            Value ret_209 = alg_nil();
            alg_root_top = rt_base;
            return ret_209;
            alg_root_top = rt_73;
        }
    }
    if (alg_truthy((or_70 = alg_greater(alg_property(v_names, "Length"), alg_int(0)), !alg_truthy(or_70) ? or_70 : alg_not_equal(alg_str(alg_subscript_get(v_names, alg_subtract(alg_property(v_names, "Length"), alg_int(1)))), alg_string(""))))) {
        alg_raise(alg_string("A positional argument cannot follow a named one."));
    }
    (void)(alg_invoke(v_names, "Add", (Value[]){alg_string("")}, 1));
    (void)(alg_invoke(v_arguments, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
    Value ret_210 = alg_nil();
    alg_root_top = rt_base;
    return ret_210;
}

static Value m_parser_primary_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_keyword = alg_nil();
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    Value v_method = alg_nil();
    (void)v_method;
    alg_root(&v_method, 1);
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVfalse}, 1))) {
        Value ret_211 = alg_new(k_literalexpr, (Value[]){alg_bool(false)}, 1);
        alg_root_top = rt_base;
        return ret_211;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVtrue}, 1))) {
        Value ret_212 = alg_new(k_literalexpr, (Value[]){alg_bool(true)}, 1);
        alg_root_top = rt_base;
        return ret_212;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVnil}, 1))) {
        Value ret_213 = alg_new(k_literalexpr, (Value[]){alg_nil()}, 1);
        alg_root_top = rt_base;
        return ret_213;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVbracket}, 1))) {
        Value ret_214 = alg_invoke(v_this, "CollectionLiteral", NULL, 0);
        alg_root_top = rt_base;
        return ret_214;
    }
    if (alg_truthy((or_73 = (or_72 = (or_71 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVinteger}, 1), alg_truthy(or_71) ? or_71 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVnumber}, 1)), alg_truthy(or_72) ? or_72 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVstring}, 1)), alg_truthy(or_73) ? or_73 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVchar}, 1)))) {
        {
            Value ret_215 = alg_new(k_literalexpr, (Value[]){alg_property(alg_invoke(v_this, "Previous", NULL, 0), "Literal")}, 1);
            alg_root_top = rt_base;
            return ret_215;
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVsuper}, 1))) {
        {
            (void)((v_keyword = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdot, alg_string("Expect '.' after 'super'.")}, 2));
            (void)((v_method = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect superclass method name.")}, 2)));
            Value ret_216 = alg_new(k_superexpr, (Value[]){v_keyword, v_method}, 2);
            alg_root_top = rt_base;
            return ret_216;
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVthis}, 1))) {
        Value ret_217 = alg_new(k_thisexpr, (Value[]){alg_invoke(v_this, "Previous", NULL, 0)}, 1);
        alg_root_top = rt_base;
        return ret_217;
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVidentifier}, 1))) {
        {
            Value ret_218 = alg_new(k_variableexpr, (Value[]){alg_invoke(v_this, "Previous", NULL, 0)}, 1);
            alg_root_top = rt_base;
            return ret_218;
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVparen}, 1))) {
        {
            (void)((v_theexpr = alg_invoke(v_this, "Expression", NULL, 0)));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_string("Expect ')' after expression.")}, 2));
            Value ret_219 = alg_new(k_groupingexpr, (Value[]){v_theexpr}, 1);
            alg_root_top = rt_base;
            return ret_219;
        }
    }
    alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_invoke(v_this, "Peek", NULL, 0), alg_string("Expect expression!")}, 2));
    Value ret_220 = alg_nil();
    alg_root_top = rt_base;
    return ret_220;
}

static Value m_parser_match_1_tokentype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thetype = alg_widen(args[0], "TokenType");
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    if (alg_truthy(alg_invoke(v_this, "Check", (Value[]){v_thetype}, 1))) {
        {
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            Value ret_221 = alg_bool(true);
            alg_root_top = rt_base;
            return ret_221;
        }
    }
    Value ret_222 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_222;
    Value ret_223 = alg_nil();
    alg_root_top = rt_base;
    return ret_223;
}

static Value m_parser_error_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thetoken = alg_widen(args[0], "Token");
    (void)v_thetoken;
    alg_root(&v_thetoken, 1);
    Value v_message = alg_widen(args[1], "String");
    (void)v_message;
    alg_root(&v_message, 1);
    (void)(alg_invoke(alg_singleton(k_console), "Error", (Value[]){v_thetoken, v_message}, 2));
    Value ret_224 = v_message;
    alg_root_top = rt_base;
    return ret_224;
    Value ret_225 = alg_nil();
    alg_root_top = rt_base;
    return ret_225;
}

static Value m_parser_consume_2_tokentype_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_typeoftoken = alg_widen(args[0], "TokenType");
    (void)v_typeoftoken;
    alg_root(&v_typeoftoken, 1);
    Value v_message = alg_widen(args[1], "String");
    (void)v_message;
    alg_root(&v_message, 1);
    if (alg_truthy(alg_invoke(v_this, "Check", (Value[]){v_typeoftoken}, 1))) {
        Value ret_226 = alg_invoke(v_this, "Advance", NULL, 0);
        alg_root_top = rt_base;
        return ret_226;
    }
    alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_invoke(v_this, "Previous", NULL, 0), v_message}, 2));
    Value ret_227 = alg_nil();
    alg_root_top = rt_base;
    return ret_227;
}

static Value m_parser_check_1_tokentype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thetype = alg_widen(args[0], "TokenType");
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        Value ret_228 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_228;
    }
    Value ret_229 = alg_equal(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "TypeOfToken"), v_thetype);
    alg_root_top = rt_base;
    return ret_229;
    Value ret_230 = alg_nil();
    alg_root_top = rt_base;
    return ret_230;
}

static Value m_parser_checkword_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_word = alg_widen(args[0], "String");
    (void)v_word;
    alg_root(&v_word, 1);
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)))) {
        Value ret_231 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_231;
    }
    Value ret_232 = alg_equal(alg_to_lower(alg_str(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "Lexeme"))), v_word);
    alg_root_top = rt_base;
    return ret_232;
    Value ret_233 = alg_nil();
    alg_root_top = rt_base;
    return ret_233;
}

static Value m_parser_advance_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        (void)(alg_set_property(v_this, "Current", alg_add(alg_property(v_this, "Current"), alg_int(1))));
    }
    Value ret_234 = alg_invoke(v_this, "Previous", NULL, 0);
    alg_root_top = rt_base;
    return ret_234;
    Value ret_235 = alg_nil();
    alg_root_top = rt_base;
    return ret_235;
}

static Value m_parser_isatend_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_236 = alg_equal(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "TypeOfToken"), e_tokentype_eof);
    alg_root_top = rt_base;
    return ret_236;
    Value ret_237 = alg_nil();
    alg_root_top = rt_base;
    return ret_237;
}

static Value m_parser_peek_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_238 = alg_subscript_get(alg_property(v_this, "Tokens"), alg_property(v_this, "Current"));
    alg_root_top = rt_base;
    return ret_238;
    Value ret_239 = alg_nil();
    alg_root_top = rt_base;
    return ret_239;
}

static Value m_parser_peeknext_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_greater_equal(alg_add(alg_property(v_this, "Current"), alg_int(1)), alg_property(alg_property(v_this, "Tokens"), "Length")))) {
        Value ret_240 = alg_subscript_get(alg_property(v_this, "Tokens"), alg_subtract(alg_property(alg_property(v_this, "Tokens"), "Length"), alg_int(1)));
        alg_root_top = rt_base;
        return ret_240;
    }
    Value ret_241 = alg_subscript_get(alg_property(v_this, "Tokens"), alg_add(alg_property(v_this, "Current"), alg_int(1)));
    alg_root_top = rt_base;
    return ret_241;
    Value ret_242 = alg_nil();
    alg_root_top = rt_base;
    return ret_242;
}

static Value m_parser_previous_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_243 = alg_subscript_get(alg_property(v_this, "Tokens"), alg_subtract(alg_property(v_this, "Current"), alg_int(1)));
    alg_root_top = rt_base;
    return ret_243;
    Value ret_244 = alg_nil();
    alg_root_top = rt_base;
    return ret_244;
}

static Value *roots_Parser[] = {
    &fn_readwholefile,
    &v_moduleVfolders,
    &fn_setmodulefolders,
    &fn_folderof,
    &fn_libraryfolders,
    &k_parser,
};

void init_Parser(void) {
    alg_roots(roots_Parser, 6);
    k_parser = alg_class("Parser", alg_nil());
    fn_readwholefile = alg_closure("ReadWholeFile", f_readwholefile, NULL, 0, 1, t_f_readwholefile);
    fn_setmodulefolders = alg_closure("SetModuleFolders", f_setmodulefolders, NULL, 0, 1, t_f_setmodulefolders);
    fn_folderof = alg_closure("FolderOf", f_folderof, NULL, 0, 1, t_f_folderof);
    fn_libraryfolders = alg_closure("LibraryFolders", f_libraryfolders, NULL, 0, 0, NULL);
    alg_class_field(k_parser, "Tokens");
    alg_class_field(k_parser, "Current");
    alg_class_field(k_parser, "FileName");
    alg_class_field(k_parser, "Loaded");
    alg_class_field(k_parser, "Claimed");
    alg_class_field(k_parser, "PrivateNames");
    alg_class_field(k_parser, "InPrivateSection");
    alg_class_field(k_parser, "ClassPrivates");
    alg_class_field(k_parser, "LoopDepth");
    alg_class_field(k_parser, "InProcedure");
    alg_class_field(k_parser, "SubprogramDepth");
    alg_class_field(k_parser, "LastGeneric");
    alg_class_field(k_parser, "PendingLabel");
    alg_class_field(k_parser, "LoopLabels");
    alg_class_initializer(k_parser, i_parser);
    alg_class_method(k_parser, "Init", m_parser_init_1_list, 1, t_parser_init_1_list);
    alg_class_method(k_parser, "UnitHeader", m_parser_unitheader_0, 0, NULL);
    alg_class_method(k_parser, "ClaimUnit", m_parser_claimunit_2_token_string, 2, t_parser_claimunit_2_token_string);
    alg_class_method(k_parser, "UnitStem", m_parser_unitstem_1_string, 1, t_parser_unitstem_1_string);
    alg_class_method(k_parser, "Parse", m_parser_parse_0, 0, NULL);
    alg_class_method(k_parser, "Statement", m_parser_statement_0, 0, NULL);
    alg_class_method(k_parser, "CaseStatement", m_parser_casestatement_0, 0, NULL);
    alg_class_method(k_parser, "Equals", m_parser_equals_0, 0, NULL);
    alg_class_method(k_parser, "Either", m_parser_either_0, 0, NULL);
    alg_class_method(k_parser, "BodyStatement", m_parser_bodystatement_0, 0, NULL);
    alg_class_method(k_parser, "IsCollectionType", m_parser_iscollectiontype_1_string, 1, t_parser_iscollectiontype_1_string);
    alg_class_method(k_parser, "IfStatement", m_parser_ifstatement_0, 0, NULL);
    alg_class_method(k_parser, "ForStatement", m_parser_forstatement_0, 0, NULL);
    alg_class_method(k_parser, "WhileStatement", m_parser_whilestatement_0, 0, NULL);
    alg_class_method(k_parser, "ReturnStatement", m_parser_returnstatement_0, 0, NULL);
    alg_class_method(k_parser, "RecordPrivate", m_parser_recordprivate_1, 1, t_parser_recordprivate_1);
    alg_class_method(k_parser, "ResolveModule", m_parser_resolvemodule_2_token_string, 2, t_parser_resolvemodule_2_token_string);
    alg_class_method(k_parser, "UsesStatement", m_parser_usesstatement_0, 0, NULL);
    alg_class_method(k_parser, "ConstDeclaration", m_parser_constdeclaration_0, 0, NULL);
    alg_class_method(k_parser, "MatchVisibility", m_parser_matchvisibility_0, 0, NULL);
    alg_class_method(k_parser, "IsDeclarationSection", m_parser_isdeclarationsection_0, 0, NULL);
    alg_class_method(k_parser, "IsNextSection", m_parser_isnextsection_0, 0, NULL);
    alg_class_method(k_parser, "DeclarationSection", m_parser_declarationsection_1_boolean, 1, t_parser_declarationsection_1_boolean);
    alg_class_method(k_parser, "ReadDeclarationSections", m_parser_readdeclarationsections_1_list, 1, t_parser_readdeclarationsections_1_list);
    alg_class_method(k_parser, "ReadDeclarationSections", m_parser_readdeclarationsections_2_list_boolean, 2, t_parser_readdeclarationsections_2_list_boolean);
    alg_class_method(k_parser, "ForInStatement", m_parser_forinstatement_1_token, 1, t_parser_forinstatement_1_token);
    alg_class_method(k_parser, "BreakStatement", m_parser_breakstatement_0, 0, NULL);
    alg_class_method(k_parser, "LabelStatement", m_parser_labelstatement_0, 0, NULL);
    alg_class_method(k_parser, "TakeLabel", m_parser_takelabel_0, 0, NULL);
    alg_class_method(k_parser, "EnclosingLoop", m_parser_enclosingloop_1_string, 1, t_parser_enclosingloop_1_string);
    alg_class_method(k_parser, "JumpLabel", m_parser_jumplabel_2_token_string, 2, t_parser_jumplabel_2_token_string);
    alg_class_method(k_parser, "ContinueStatement", m_parser_continuestatement_0, 0, NULL);
    alg_class_method(k_parser, "OperatorToken", m_parser_operatortoken_0, 0, NULL);
    alg_class_method(k_parser, "ParseOperator", m_parser_parseoperator_0, 0, NULL);
    alg_class_method(k_parser, "ParseProperty", m_parser_parseproperty_0, 0, NULL);
    alg_class_method(k_parser, "GotoStatement", m_parser_gotostatement_0, 0, NULL);
    alg_class_method(k_parser, "RaiseStatement", m_parser_raisestatement_0, 0, NULL);
    alg_class_method(k_parser, "TryStatement", m_parser_trystatement_0, 0, NULL);
    alg_class_method(k_parser, "VarDeclaration", m_parser_vardeclaration_0, 0, NULL);
    alg_class_method(k_parser, "VarDeclaration", m_parser_vardeclaration_1_token, 1, t_parser_vardeclaration_1_token);
    alg_class_method(k_parser, "ExpressionStatement", m_parser_expressionstatement_0, 0, NULL);
    alg_class_method(k_parser, "IsExtensionDeclaration", m_parser_isextensiondeclaration_0, 0, NULL);
    alg_class_method(k_parser, "ExtensionDeclaration", m_parser_extensiondeclaration_0, 0, NULL);
    alg_class_method(k_parser, "ParseFunction", m_parser_parsefunction_2_string_boolean, 2, t_parser_parsefunction_2_string_boolean);
    alg_class_method(k_parser, "ParameterType", m_parser_parametertype_0, 0, NULL);
    alg_class_method(k_parser, "Block", m_parser_block_0, 0, NULL);
    alg_class_method(k_parser, "Assignment", m_parser_assignment_0, 0, NULL);
    alg_class_method(k_parser, "ParseOr", m_parser_parseor_0, 0, NULL);
    alg_class_method(k_parser, "ParseAnd", m_parser_parseand_0, 0, NULL);
    alg_class_method(k_parser, "Expression", m_parser_expression_0, 0, NULL);
    alg_class_method(k_parser, "Declaration", m_parser_declaration_0, 0, NULL);
    alg_class_method(k_parser, "IsTestBlock", m_parser_istestblock_0, 0, NULL);
    alg_class_method(k_parser, "TestDeclaration", m_parser_testdeclaration_0, 0, NULL);
    alg_class_method(k_parser, "EnumDeclaration", m_parser_enumdeclaration_0, 0, NULL);
    alg_class_method(k_parser, "SubrangeDeclaration", m_parser_subrangedeclaration_1_token, 1, t_parser_subrangedeclaration_1_token);
    alg_class_method(k_parser, "SubrangeBound", m_parser_subrangebound_0, 0, NULL);
    alg_class_method(k_parser, "ClassDeclaration", m_parser_classdeclaration_0, 0, NULL);
    alg_class_method(k_parser, "ClassDeclaration", m_parser_classdeclaration_1_string, 1, t_parser_classdeclaration_1_string);
    alg_class_method(k_parser, "Equality", m_parser_equality_0, 0, NULL);
    alg_class_method(k_parser, "Comparison", m_parser_comparison_0, 0, NULL);
    alg_class_method(k_parser, "BitOr", m_parser_bitor_0, 0, NULL);
    alg_class_method(k_parser, "BitXor", m_parser_bitxor_0, 0, NULL);
    alg_class_method(k_parser, "BitAnd", m_parser_bitand_0, 0, NULL);
    alg_class_method(k_parser, "Term", m_parser_term_0, 0, NULL);
    alg_class_method(k_parser, "Factor", m_parser_factor_0, 0, NULL);
    alg_class_method(k_parser, "Unary", m_parser_unary_0, 0, NULL);
    alg_class_method(k_parser, "CollectionLiteral", m_parser_collectionliteral_0, 0, NULL);
    alg_class_method(k_parser, "Call", m_parser_call_0, 0, NULL);
    alg_class_method(k_parser, "FinishCall", m_parser_finishcall_1_expr, 1, t_parser_finishcall_1_expr);
    alg_class_method(k_parser, "Argument", m_parser_argument_2_list_list, 2, t_parser_argument_2_list_list);
    alg_class_method(k_parser, "Primary", m_parser_primary_0, 0, NULL);
    alg_class_method(k_parser, "Match", m_parser_match_1_tokentype, 1, t_parser_match_1_tokentype);
    alg_class_method(k_parser, "Error", m_parser_error_2_token_string, 2, t_parser_error_2_token_string);
    alg_class_method(k_parser, "Consume", m_parser_consume_2_tokentype_string, 2, t_parser_consume_2_tokentype_string);
    alg_class_method(k_parser, "Check", m_parser_check_1_tokentype, 1, t_parser_check_1_tokentype);
    alg_class_method(k_parser, "CheckWord", m_parser_checkword_1_string, 1, t_parser_checkword_1_string);
    alg_class_method(k_parser, "Advance", m_parser_advance_0, 0, NULL);
    alg_class_method(k_parser, "IsAtEnd", m_parser_isatend_0, 0, NULL);
    alg_class_method(k_parser, "Peek", m_parser_peek_0, 0, NULL);
    alg_class_method(k_parser, "PeekNext", m_parser_peeknext_0, 0, NULL);
    alg_class_method(k_parser, "Previous", m_parser_previous_0, 0, NULL);
    v_moduleVfolders = alg_list();
    d_moduleVfolders = true;
}
