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
    Value v_name = alg_param_of(args[0], "String", "ReadWholeFile");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_350 = alg_hold_top;
    Value v_f = alg_hold(alg_text_file());
    (void)v_f;
    alg_root(&v_f, 1);
    alg_hold_top = rh_350;
    (void)(alg_hold(alg_invoke(v_f, "Assign", (Value[]){v_name}, 1)));
    alg_hold_top = rh_350;
    (void)(alg_hold(alg_invoke(v_f, "Reset", NULL, 0)));
    alg_hold_top = rh_350;
    Value v_result = alg_hold(alg_buffer(alg_int(0)));
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_350;
    {
        int32_t rh_351 = alg_hold_top;
        while ((alg_hold_top = rh_351, alg_truthy(alg_hold(alg_not(alg_hold(alg_property(v_f, "Eof"))))))) {
            alg_safe_point();
            {
                int32_t rh_352 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_result, "Append", (Value[]){alg_hold(alg_invoke(v_f, "ReadLn", NULL, 0))}, 1)));
                alg_hold_top = rh_352;
                (void)(alg_hold(alg_invoke(v_result, "Append", (Value[]){alg_char_value(10)}, 1)));
                alg_hold_top = rh_352;
            }
        }
    }
    alg_hold_top = rh_350;
    (void)(alg_hold(alg_invoke(v_f, "Close", NULL, 0)));
    alg_hold_top = rh_350;
    Value ret_0 = alg_hold(alg_property(v_result, "Text"));
    alg_root_top = rt_base;
    return ret_0;
    alg_hold_top = rh_350;
    Value ret_1 = alg_nil();
    alg_root_top = rt_base;
    return ret_1;
}

Value f_setmodulefolders(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_folders = alg_param_of(args[0], "List", "SetModuleFolders");
    (void)v_folders;
    alg_root(&v_folders, 1);
    int32_t rh_353 = alg_hold_top;
    (void)((alg_declared(d_moduleVfolders, "MODULE_FOLDERS"), (v_moduleVfolders = v_folders)));
    alg_hold_top = rh_353;
    Value ret_2 = alg_nil();
    alg_root_top = rt_base;
    return ret_2;
}

Value f_folderof(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_path = alg_param_of(args[0], "String", "FolderOf");
    (void)v_path;
    alg_root(&v_path, 1);
    int32_t rh_354 = alg_hold_top;
    Value v_cut = alg_hold(alg_negate(alg_int(1)));
    (void)v_cut;
    alg_root(&v_cut, 1);
    alg_hold_top = rh_354;
    {
        int32_t rt_355 = alg_root_top;
        int32_t rh_356 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_356;
        {
            int32_t rh_357 = alg_hold_top;
            for (; (alg_hold_top = rh_357, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_text_length(v_path)))))); (alg_hold_top = rh_357, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold((or_0 = alg_hold(alg_equal(alg_hold(alg_subscript_get(v_path, v_i)), alg_char_value(47))), alg_truthy(or_0) ? or_0 : alg_hold(alg_equal(alg_hold(alg_subscript_get(v_path, v_i)), alg_hold(alg_char(alg_int(92))))))))) {
                    (void)((v_cut = v_i));
                }
            }
        }
        alg_hold_top = rh_356;
        alg_root_top = rt_355;
    }
    alg_hold_top = rh_354;
    if (alg_truthy(alg_hold(alg_less(v_cut, alg_int(0))))) {
        Value ret_3 = alg_literal("");
        alg_root_top = rt_base;
        return ret_3;
    }
    alg_hold_top = rh_354;
    Value ret_4 = alg_hold(alg_copy(v_path, alg_int(0), v_cut));
    alg_root_top = rt_base;
    return ret_4;
    alg_hold_top = rh_354;
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

Value f_libraryfolders(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    int32_t rh_358 = alg_hold_top;
    Value v_own = alg_nil();
    (void)v_own;
    alg_root(&v_own, 1);
    alg_hold_top = rh_358;
    (void)((v_own = alg_hold(f_folderof(NULL, (Value[]){alg_hold(alg_param_str(alg_int(0)))}, 1))));
    alg_hold_top = rh_358;
    if (alg_truthy(alg_hold(alg_equal(v_own, alg_literal(""))))) {
        Value ret_6 = alg_hold(alg_list());
        alg_root_top = rt_base;
        return ret_6;
    }
    alg_hold_top = rh_358;
    Value ret_7 = alg_hold(alg_list_keep(alg_list_keep(alg_list(), alg_hold(alg_add(v_own, alg_literal("/lib")))), alg_hold(alg_add(v_own, alg_literal("/../share/algol24/lib")))));
    alg_root_top = rt_base;
    return ret_7;
    alg_hold_top = rh_358;
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
    alg_set_property(v_this, "FileName", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "Loaded", alg_widen(alg_hold(alg_map()), "Map"));
    alg_set_property(v_this, "Claimed", alg_widen(alg_hold(alg_map()), "Map"));
    alg_set_property(v_this, "PrivateNames", alg_widen(alg_hold(alg_list()), "List"));
    alg_set_property(v_this, "InPrivateSection", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "ClassPrivates", alg_widen(alg_hold(alg_list()), "List"));
    alg_set_property(v_this, "LoopDepth", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "InProcedure", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "SubprogramDepth", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "LastGeneric", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "PendingLabel", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "LoopLabels", alg_widen(alg_hold(alg_list()), "List"));
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
    int32_t rh_359 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Tokens", v_tokens)));
    alg_hold_top = rh_359;
    (void)(alg_hold(alg_set_property(v_this, "Current", alg_int(0))));
    alg_hold_top = rh_359;
    Value ret_9 = alg_nil();
    alg_root_top = rt_base;
    return ret_9;
}

static Value m_parser_unitheader_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_360 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)))))) {
        Value ret_10 = alg_nil();
        alg_root_top = rt_base;
        return ret_10;
    }
    alg_hold_top = rh_360;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), "Lexeme")), alg_literal("unit"))))) {
        Value ret_11 = alg_nil();
        alg_root_top = rt_base;
        return ret_11;
    }
    alg_hold_top = rh_360;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0)), "TypeOfToken")), e_tokentype_tokenVidentifier)))) {
        Value ret_12 = alg_nil();
        alg_root_top = rt_base;
        return ret_12;
    }
    alg_hold_top = rh_360;
    (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
    alg_hold_top = rh_360;
    Value v_name = alg_hold(alg_invoke(v_this, "Advance", NULL, 0));
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_360;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after unit name.")}, 2)));
    alg_hold_top = rh_360;
    Value v_expected = alg_hold(alg_invoke(v_this, "UnitStem", (Value[]){alg_property(v_this, "FileName")}, 1));
    (void)v_expected;
    alg_root(&v_expected, 1);
    alg_hold_top = rh_360;
    if (alg_truthy(alg_hold((or_1 = alg_hold(alg_equal(v_expected, alg_literal(""))), alg_truthy(or_1) ? or_1 : alg_hold(alg_equal(v_expected, alg_literal("REPL"))))))) {
        Value ret_13 = alg_nil();
        alg_root_top = rt_base;
        return ret_13;
    }
    alg_hold_top = rh_360;
    if (alg_truthy(alg_hold(alg_not_equal(v_expected, alg_hold(alg_str(alg_hold(alg_property(v_name, "Lexeme")))))))) {
        alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_name, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Unit '"), alg_hold(alg_str(alg_hold(alg_property(v_name, "Lexeme")))))), alg_literal("' must match its file name '"))), v_expected)), alg_literal("'.")))}, 2)));
    }
    alg_hold_top = rh_360;
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
    int32_t rh_361 = alg_hold_top;
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    alg_hold_top = rh_361;
    (void)((v_folded = alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_invoke(v_this, "UnitStem", (Value[]){v_path}, 1))}, 1))));
    alg_hold_top = rh_361;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Claimed"), "Contains", (Value[]){v_folded}, 1)))) {
        {
            int32_t rh_362 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "Claimed"), "Get", (Value[]){v_folded}, 1)))), v_path)))) {
                alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_where, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Two units whose names differ only in case: '"), alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "Claimed"), "Get", (Value[]){v_folded}, 1)))))), alg_literal("' and '"))), v_path)), alg_literal("'. A unit name is matched without regard to "))), alg_literal("case.")))}, 2)));
            }
            alg_hold_top = rh_362;
        }
    }
    alg_hold_top = rh_361;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Claimed"), "Put", (Value[]){v_folded, v_path}, 2)));
    alg_hold_top = rh_361;
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
    int32_t rh_363 = alg_hold_top;
    Value v_stem = alg_nil();
    (void)v_stem;
    alg_root(&v_stem, 1);
    alg_hold_top = rh_363;
    (void)((v_stem = v_key));
    alg_hold_top = rh_363;
    {
        int32_t rt_364 = alg_root_top;
        int32_t rh_365 = alg_hold_top;
        Value v_i = alg_hold(alg_subtract(alg_hold(alg_text_length(v_key)), alg_int(1)));
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_365;
        {
            int32_t rh_366 = alg_hold_top;
            for (; (alg_hold_top = rh_366, alg_truthy(alg_hold(alg_greater_equal(v_i, alg_int(0))))); (alg_hold_top = rh_366, (v_i = alg_hold(alg_subtract(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold((or_2 = alg_hold(alg_equal(alg_hold(alg_subscript_get(v_key, v_i)), alg_char_value(47))), alg_truthy(or_2) ? or_2 : alg_hold(alg_equal(alg_hold(alg_subscript_get(v_key, v_i)), alg_char_value(92))))))) {
                    {
                        int32_t rh_367 = alg_hold_top;
                        (void)((v_stem = alg_hold(alg_copy(v_key, alg_hold(alg_add(v_i, alg_int(1))), alg_hold(alg_subtract(alg_hold(alg_subtract(alg_hold(alg_text_length(v_key)), v_i)), alg_int(1)))))));
                        alg_hold_top = rh_367;
                        (void)((v_i = alg_hold(alg_negate(alg_int(1)))));
                        alg_hold_top = rh_367;
                    }
                }
            }
        }
        alg_hold_top = rh_365;
        alg_root_top = rt_364;
    }
    alg_hold_top = rh_363;
    if (alg_truthy(alg_hold((or_3 = alg_hold(alg_greater(alg_hold(alg_text_length(v_stem)), alg_int(4))), !alg_truthy(or_3) ? or_3 : alg_hold(alg_equal(alg_hold(alg_copy(v_stem, alg_hold(alg_subtract(alg_hold(alg_text_length(v_stem)), alg_int(4))), alg_int(4))), alg_literal(".a24"))))))) {
        Value ret_16 = alg_hold(alg_copy(v_stem, alg_int(0), alg_hold(alg_subtract(alg_hold(alg_text_length(v_stem)), alg_int(4)))));
        alg_root_top = rt_base;
        return ret_16;
    }
    alg_hold_top = rh_363;
    Value ret_17 = v_stem;
    alg_root_top = rt_base;
    return ret_17;
    alg_hold_top = rh_363;
    Value ret_18 = alg_nil();
    alg_root_top = rt_base;
    return ret_18;
}

static Value m_parser_parse_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_368 = alg_hold_top;
    Value v_statements = alg_nil();
    (void)v_statements;
    alg_root(&v_statements, 1);
    alg_hold_top = rh_368;
    (void)((v_statements = alg_hold(alg_list())));
    alg_hold_top = rh_368;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "FileName"), alg_literal(""))))) {
        {
            int32_t rh_369 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Loaded"), "Put", (Value[]){alg_property(v_this, "FileName"), alg_bool(true)}, 2)));
            alg_hold_top = rh_369;
            (void)(alg_hold(alg_invoke(v_this, "ClaimUnit", (Value[]){alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_property(v_this, "FileName")}, 2)));
            alg_hold_top = rh_369;
        }
    }
    alg_hold_top = rh_368;
    (void)(alg_hold(alg_invoke(v_this, "UnitHeader", NULL, 0)));
    alg_hold_top = rh_368;
    {
        int32_t rh_370 = alg_hold_top;
        while ((alg_hold_top = rh_370, alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0))))))) {
            alg_safe_point();
            {
                int32_t rh_371 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVuses}, 1)))) {
                    {
                        int32_t rt_372 = alg_root_top;
                        int32_t rh_373 = alg_hold_top;
                        Value v_themodule = alg_hold(alg_invoke(v_this, "UsesStatement", NULL, 0));
                        (void)v_themodule;
                        alg_root(&v_themodule, 1);
                        alg_hold_top = rh_373;
                        if (alg_truthy(alg_hold(alg_not_equal(v_themodule, alg_nil())))) {
                            (void)(alg_hold(alg_invoke(v_statements, "Add", (Value[]){v_themodule}, 1)));
                        }
                        alg_hold_top = rh_373;
                        alg_root_top = rt_372;
                    }
                } else {
                    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVprivate}, 1)))) {
                        {
                            int32_t rt_374 = alg_root_top;
                            int32_t rh_375 = alg_hold_top;
                            Value v_decl = alg_hold(alg_invoke(v_this, "Declaration", NULL, 0));
                            (void)v_decl;
                            alg_root(&v_decl, 1);
                            alg_hold_top = rh_375;
                            (void)(alg_hold(alg_invoke(v_this, "RecordPrivate", (Value[]){v_decl}, 1)));
                            alg_hold_top = rh_375;
                            (void)(alg_hold(alg_invoke(v_statements, "Add", (Value[]){v_decl}, 1)));
                            alg_hold_top = rh_375;
                            alg_root_top = rt_374;
                        }
                    } else {
                        (void)(alg_hold(alg_invoke(v_statements, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Declaration", NULL, 0))}, 1)));
                    }
                }
                alg_hold_top = rh_371;
            }
        }
    }
    alg_hold_top = rh_368;
    Value ret_19 = v_statements;
    alg_root_top = rt_base;
    return ret_19;
    alg_hold_top = rh_368;
    Value ret_20 = alg_nil();
    alg_root_top = rt_base;
    return ret_20;
}

static Value m_parser_statement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_376 = alg_hold_top;
    Value v_where = alg_nil();
    (void)v_where;
    alg_root(&v_where, 1);
    alg_hold_top = rh_376;
    Value v_parsed = alg_nil();
    (void)v_parsed;
    alg_root(&v_parsed, 1);
    alg_hold_top = rh_376;
    (void)((v_where = alg_hold(alg_invoke(v_this, "Peek", NULL, 0))));
    alg_hold_top = rh_376;
    (void)((v_parsed = alg_hold(alg_invoke(v_this, "StatementBody", NULL, 0))));
    alg_hold_top = rh_376;
    if (alg_truthy(alg_hold(alg_not_equal(v_parsed, alg_nil())))) {
        {
            int32_t rh_377 = alg_hold_top;
            (void)(alg_hold(alg_set_property(v_parsed, "Line", alg_hold(alg_property(v_where, "LineNumber")))));
            alg_hold_top = rh_377;
            (void)(alg_hold(alg_set_property(v_parsed, "File", alg_hold(alg_str(alg_hold(alg_property(v_where, "File")))))));
            alg_hold_top = rh_377;
        }
    }
    alg_hold_top = rh_376;
    Value ret_21 = v_parsed;
    alg_root_top = rt_base;
    return ret_21;
    alg_hold_top = rh_376;
    Value ret_22 = alg_nil();
    alg_root_top = rt_base;
    return ret_22;
}

static Value m_parser_statementbody_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_378 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVtype}, 1)))) {
        Value ret_23 = alg_hold(alg_invoke(v_this, "EnumDeclaration", NULL, 0));
        alg_root_top = rt_base;
        return ret_23;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVclass}, 1)))) {
        Value ret_24 = alg_hold(alg_invoke(v_this, "ClassDeclaration", NULL, 0));
        alg_root_top = rt_base;
        return ret_24;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVobject}, 1)))) {
        Value ret_25 = alg_hold(alg_invoke(v_this, "ClassDeclaration", (Value[]){alg_literal("object")}, 1));
        alg_root_top = rt_base;
        return ret_25;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsExtensionDeclaration", NULL, 0)))) {
        Value ret_26 = alg_hold(alg_invoke(v_this, "ExtensionDeclaration", NULL, 0));
        alg_root_top = rt_base;
        return ret_26;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVfunction}, 1)))) {
        Value ret_27 = alg_hold(alg_invoke(v_this, "ParseFunction", (Value[]){alg_literal("function"), alg_bool(false)}, 2));
        alg_root_top = rt_base;
        return ret_27;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVprocedure}, 1)))) {
        Value ret_28 = alg_hold(alg_invoke(v_this, "ParseFunction", (Value[]){alg_literal("procedure"), alg_bool(false)}, 2));
        alg_root_top = rt_base;
        return ret_28;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVvar}, 1)))) {
        Value ret_29 = alg_hold(alg_invoke(v_this, "VarDeclaration", NULL, 0));
        alg_root_top = rt_base;
        return ret_29;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVconst}, 1)))) {
        Value ret_30 = alg_hold(alg_invoke(v_this, "ConstDeclaration", NULL, 0));
        alg_root_top = rt_base;
        return ret_30;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold((or_4 = alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)), !alg_truthy(or_4) ? or_4 : alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0)), "TypeOfToken")), e_tokentype_tokenVcolon)))))) {
        Value ret_31 = alg_hold(alg_invoke(v_this, "LabelStatement", NULL, 0));
        alg_root_top = rt_base;
        return ret_31;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcase}, 1)))) {
        Value ret_32 = alg_hold(alg_invoke(v_this, "CaseStatement", NULL, 0));
        alg_root_top = rt_base;
        return ret_32;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVif}, 1)))) {
        Value ret_33 = alg_hold(alg_invoke(v_this, "IfStatement", NULL, 0));
        alg_root_top = rt_base;
        return ret_33;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVwhile}, 1)))) {
        Value ret_34 = alg_hold(alg_invoke(v_this, "WhileStatement", NULL, 0));
        alg_root_top = rt_base;
        return ret_34;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVfor}, 1)))) {
        Value ret_35 = alg_hold(alg_invoke(v_this, "ForStatement", NULL, 0));
        alg_root_top = rt_base;
        return ret_35;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVexit}, 1)))) {
        Value ret_36 = alg_hold(alg_invoke(v_this, "ReturnStatement", NULL, 0));
        alg_root_top = rt_base;
        return ret_36;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVtry}, 1)))) {
        Value ret_37 = alg_hold(alg_invoke(v_this, "TryStatement", NULL, 0));
        alg_root_top = rt_base;
        return ret_37;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVbreak}, 1)))) {
        Value ret_38 = alg_hold(alg_invoke(v_this, "BreakStatement", NULL, 0));
        alg_root_top = rt_base;
        return ret_38;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcontinue}, 1)))) {
        Value ret_39 = alg_hold(alg_invoke(v_this, "ContinueStatement", NULL, 0));
        alg_root_top = rt_base;
        return ret_39;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVgoto}, 1)))) {
        Value ret_40 = alg_hold(alg_invoke(v_this, "GotoStatement", NULL, 0));
        alg_root_top = rt_base;
        return ret_40;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVraise}, 1)))) {
        Value ret_41 = alg_hold(alg_invoke(v_this, "RaiseStatement", NULL, 0));
        alg_root_top = rt_base;
        return ret_41;
    }
    alg_hold_top = rh_378;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVbegin}, 1)))) {
        Value ret_42 = alg_hold(alg_new(k_blockstmt, (Value[]){alg_hold(alg_invoke(v_this, "Block", NULL, 0))}, 1));
        alg_root_top = rt_base;
        return ret_42;
    }
    alg_hold_top = rh_378;
    Value ret_43 = alg_hold(alg_invoke(v_this, "ExpressionStatement", NULL, 0));
    alg_root_top = rt_base;
    return ret_43;
    alg_hold_top = rh_378;
    Value ret_44 = alg_nil();
    alg_root_top = rt_base;
    return ret_44;
}

static Value m_parser_casestatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_379 = alg_hold_top;
    Value v_left = alg_nil();
    (void)v_left;
    alg_root(&v_left, 1);
    alg_hold_top = rh_379;
    Value v_top = alg_nil();
    (void)v_top;
    alg_root(&v_top, 1);
    alg_hold_top = rh_379;
    Value v_current = alg_nil();
    (void)v_current;
    alg_root(&v_current, 1);
    alg_hold_top = rh_379;
    Value v_condition = alg_nil();
    (void)v_condition;
    alg_root(&v_condition, 1);
    alg_hold_top = rh_379;
    Value v_branch = alg_nil();
    (void)v_branch;
    alg_root(&v_branch, 1);
    alg_hold_top = rh_379;
    (void)((v_left = alg_hold(alg_invoke(v_this, "Expression", NULL, 0))));
    alg_hold_top = rh_379;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVof, alg_literal("Expect 'of' after case condition.")}, 2)));
    alg_hold_top = rh_379;
    (void)((v_top = alg_cast_class(alg_nil(), k_ifstmt, "IfStmt")));
    alg_hold_top = rh_379;
    (void)((v_current = alg_cast_class(alg_nil(), k_ifstmt, "IfStmt")));
    alg_hold_top = rh_379;
    {
        int32_t rh_380 = alg_hold_top;
        while ((alg_hold_top = rh_380, alg_truthy(alg_bool(true)))) {
            alg_safe_point();
            {
                int32_t rh_381 = alg_hold_top;
                (void)((v_condition = alg_widen(alg_hold(alg_new(k_binaryexpr, (Value[]){v_left, alg_hold(alg_invoke(v_this, "Equals", NULL, 0)), alg_hold(alg_invoke(v_this, "Expression", NULL, 0))}, 3)), "Expr")));
                alg_hold_top = rh_381;
                {
                    int32_t rh_382 = alg_hold_top;
                    while ((alg_hold_top = rh_382, alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))))) {
                        alg_safe_point();
                        (void)((v_condition = alg_widen(alg_hold(alg_new(k_logicalexpr, (Value[]){v_condition, alg_hold(alg_invoke(v_this, "Either", NULL, 0)), alg_hold(alg_new(k_binaryexpr, (Value[]){v_left, alg_hold(alg_invoke(v_this, "Equals", NULL, 0)), alg_hold(alg_invoke(v_this, "Expression", NULL, 0))}, 3))}, 3)), "Expr")));
                    }
                }
                alg_hold_top = rh_381;
                (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVcolon, alg_literal("Expect ':' after condition.")}, 2)));
                alg_hold_top = rh_381;
                (void)((v_branch = alg_hold(alg_new(k_ifstmt, (Value[]){v_condition, alg_hold(alg_invoke(v_this, "Statement", NULL, 0)), alg_nil()}, 3))));
                alg_hold_top = rh_381;
                if (alg_truthy(alg_hold(alg_equal(v_top, alg_nil())))) {
                    (void)((v_top = v_branch));
                } else {
                    (void)(alg_hold(alg_set_property(v_current, "ElseBranch", alg_widen(v_branch, "Stmt"))));
                }
                alg_hold_top = rh_381;
                (void)((v_current = v_branch));
                alg_hold_top = rh_381;
                if (alg_truthy(alg_hold((or_5 = alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVelse}, 1)), alg_truthy(or_5) ? or_5 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVend}, 1)))))) {
                    break;
                }
                alg_hold_top = rh_381;
            }
        }
    }
    alg_hold_top = rh_379;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Previous", NULL, 0)), "TypeOfToken")), e_tokentype_tokenVelse)))) {
        {
            int32_t rh_383 = alg_hold_top;
            (void)(alg_hold(alg_set_property(v_current, "ElseBranch", alg_hold(alg_invoke(v_this, "BodyStatement", NULL, 0)))));
            alg_hold_top = rh_383;
            (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVend, alg_literal("Expected 'end'.")}, 2)));
            alg_hold_top = rh_383;
        }
    }
    alg_hold_top = rh_379;
    Value ret_45 = v_top;
    alg_root_top = rt_base;
    return ret_45;
    alg_hold_top = rh_379;
    Value ret_46 = alg_nil();
    alg_root_top = rt_base;
    return ret_46;
}

static Value m_parser_equals_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_384 = alg_hold_top;
    Value ret_47 = alg_hold(alg_new(k_token, (Value[]){e_tokentype_tokenVequal, alg_char_value(61), alg_nil(), alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Previous", NULL, 0)), "LineNumber"))}, 4));
    alg_root_top = rt_base;
    return ret_47;
    alg_hold_top = rh_384;
    Value ret_48 = alg_nil();
    alg_root_top = rt_base;
    return ret_48;
}

static Value m_parser_either_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_385 = alg_hold_top;
    Value ret_49 = alg_hold(alg_new(k_token, (Value[]){e_tokentype_tokenVor, alg_literal("or"), alg_nil(), alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Previous", NULL, 0)), "LineNumber"))}, 4));
    alg_root_top = rt_base;
    return ret_49;
    alg_hold_top = rh_385;
    Value ret_50 = alg_nil();
    alg_root_top = rt_base;
    return ret_50;
}

static Value m_parser_bodystatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_386 = alg_hold_top;
    if (alg_truthy(alg_hold((or_11 = alg_hold((or_10 = alg_hold((or_9 = alg_hold((or_8 = alg_hold((or_7 = alg_hold((or_6 = alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVvar}, 1)), alg_truthy(or_6) ? or_6 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVconst}, 1)))), alg_truthy(or_7) ? or_7 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVtype}, 1)))), alg_truthy(or_8) ? or_8 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVclass}, 1)))), alg_truthy(or_9) ? or_9 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVobject}, 1)))), alg_truthy(or_10) ? or_10 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVfunction}, 1)))), alg_truthy(or_11) ? or_11 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVprocedure}, 1)))))) {
        alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_literal("A declaration cannot be a branch or loop body; use 'begin' ... 'end'.")}, 2)));
    }
    alg_hold_top = rh_386;
    Value ret_51 = alg_hold(alg_invoke(v_this, "Statement", NULL, 0));
    alg_root_top = rt_base;
    return ret_51;
    alg_hold_top = rh_386;
    Value ret_52 = alg_nil();
    alg_root_top = rt_base;
    return ret_52;
}

static Value m_parser_iscollectiontype_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_typename = alg_widen(args[0], "String");
    (void)v_typename;
    alg_root(&v_typename, 1);
    int32_t rh_387 = alg_hold_top;
    Value v_lowered = alg_hold(alg_to_lower(v_typename));
    (void)v_lowered;
    alg_root(&v_lowered, 1);
    alg_hold_top = rh_387;
    Value ret_53 = alg_hold((or_15 = alg_hold((or_14 = alg_hold((or_13 = alg_hold((or_12 = alg_hold(alg_equal(v_lowered, alg_literal("list"))), alg_truthy(or_12) ? or_12 : alg_hold(alg_equal(v_lowered, alg_literal("map"))))), alg_truthy(or_13) ? or_13 : alg_hold(alg_equal(v_lowered, alg_literal("set"))))), alg_truthy(or_14) ? or_14 : alg_hold(alg_equal(v_lowered, alg_literal("stack"))))), alg_truthy(or_15) ? or_15 : alg_hold(alg_equal(v_lowered, alg_literal("array")))));
    alg_root_top = rt_base;
    return ret_53;
    alg_hold_top = rh_387;
    Value ret_54 = alg_nil();
    alg_root_top = rt_base;
    return ret_54;
}

static Value m_parser_ifstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_388 = alg_hold_top;
    Value v_condition = alg_nil();
    (void)v_condition;
    alg_root(&v_condition, 1);
    alg_hold_top = rh_388;
    Value v_thenbranch = alg_nil();
    (void)v_thenbranch;
    alg_root(&v_thenbranch, 1);
    alg_hold_top = rh_388;
    Value v_elsebranch = alg_nil();
    (void)v_elsebranch;
    alg_root(&v_elsebranch, 1);
    alg_hold_top = rh_388;
    (void)((v_condition = alg_hold(alg_invoke(v_this, "Expression", NULL, 0))));
    alg_hold_top = rh_388;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVthen, alg_literal("Expect 'then' after if condition.")}, 2)));
    alg_hold_top = rh_388;
    (void)((v_thenbranch = alg_hold(alg_invoke(v_this, "BodyStatement", NULL, 0))));
    alg_hold_top = rh_388;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVelse}, 1)))) {
        {
            int32_t rh_389 = alg_hold_top;
            (void)((v_elsebranch = alg_hold(alg_invoke(v_this, "BodyStatement", NULL, 0))));
            alg_hold_top = rh_389;
        }
    }
    alg_hold_top = rh_388;
    Value ret_55 = alg_hold(alg_new(k_ifstmt, (Value[]){v_condition, v_thenbranch, v_elsebranch}, 3));
    alg_root_top = rt_base;
    return ret_55;
    alg_hold_top = rh_388;
    Value ret_56 = alg_nil();
    alg_root_top = rt_base;
    return ret_56;
}

static Value m_parser_forstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_390 = alg_hold_top;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    alg_hold_top = rh_390;
    Value v_increment = alg_nil();
    (void)v_increment;
    alg_root(&v_increment, 1);
    alg_hold_top = rh_390;
    Value v_condition = alg_nil();
    (void)v_condition;
    alg_root(&v_condition, 1);
    alg_hold_top = rh_390;
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    alg_hold_top = rh_390;
    Value v_stmtlist = alg_nil();
    (void)v_stmtlist;
    alg_root(&v_stmtlist, 1);
    alg_hold_top = rh_390;
    Value v_whilelist = alg_nil();
    (void)v_whilelist;
    alg_root(&v_whilelist, 1);
    alg_hold_top = rh_390;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVsemicolon}, 1)))) {
        (void)((v_initializer = alg_widen(alg_nil(), "Stmt")));
    } else {
        if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVvar}, 1)))) {
            {
                int32_t rt_391 = alg_root_top;
                int32_t rh_392 = alg_hold_top;
                Value v_name = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect variable name.")}, 2));
                (void)v_name;
                alg_root(&v_name, 1);
                alg_hold_top = rh_392;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVin}, 1)))) {
                    Value ret_57 = alg_hold(alg_invoke(v_this, "ForInStatement", (Value[]){v_name}, 1));
                    alg_root_top = rt_base;
                    return ret_57;
                }
                alg_hold_top = rh_392;
                (void)((v_initializer = alg_hold(alg_invoke(v_this, "VarDeclaration", (Value[]){v_name}, 1))));
                alg_hold_top = rh_392;
                alg_root_top = rt_391;
            }
        } else {
            (void)((v_initializer = alg_hold(alg_invoke(v_this, "ExpressionStatement", NULL, 0))));
        }
    }
    alg_hold_top = rh_390;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVsemicolon}, 1)))))) {
        {
            int32_t rh_393 = alg_hold_top;
            (void)((v_condition = alg_hold(alg_invoke(v_this, "Expression", NULL, 0))));
            alg_hold_top = rh_393;
        }
    }
    alg_hold_top = rh_390;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after loop condition")}, 2)));
    alg_hold_top = rh_390;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVdo}, 1)))))) {
        {
            int32_t rh_394 = alg_hold_top;
            (void)((v_increment = alg_hold(alg_invoke(v_this, "Expression", NULL, 0))));
            alg_hold_top = rh_394;
        }
    }
    alg_hold_top = rh_390;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdo, alg_literal("Expect 'do' after for clauses.")}, 2)));
    alg_hold_top = rh_390;
    Value v_named = alg_hold(alg_invoke(v_this, "TakeLabel", NULL, 0));
    (void)v_named;
    alg_root(&v_named, 1);
    alg_hold_top = rh_390;
    (void)(alg_set_property(v_this, "LoopDepth", alg_hold(alg_add(alg_property(v_this, "LoopDepth"), alg_int(1)))));
    alg_hold_top = rh_390;
    (void)((v_body = alg_hold(alg_invoke(v_this, "BodyStatement", NULL, 0))));
    alg_hold_top = rh_390;
    (void)(alg_set_property(v_this, "LoopDepth", alg_hold(alg_subtract(alg_property(v_this, "LoopDepth"), alg_int(1)))));
    alg_hold_top = rh_390;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LoopLabels"), "RemoveAt", (Value[]){alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "LoopLabels"), "Length")), alg_int(1)))}, 1)));
    alg_hold_top = rh_390;
    if (alg_truthy(alg_hold(alg_equal(v_condition, alg_nil())))) {
        (void)((v_condition = alg_widen(alg_hold(alg_new(k_literalexpr, (Value[]){alg_bool(true)}, 1)), "Expr")));
    }
    alg_hold_top = rh_390;
    Value v_loop = alg_hold(alg_new(k_whilestmt, (Value[]){v_condition, v_body}, 2));
    (void)v_loop;
    alg_root(&v_loop, 1);
    alg_hold_top = rh_390;
    (void)(alg_hold(alg_set_property(v_loop, "Increment", v_increment)));
    alg_hold_top = rh_390;
    (void)(alg_hold(alg_set_property(v_loop, "Label", v_named)));
    alg_hold_top = rh_390;
    (void)((v_body = alg_widen(v_loop, "Stmt")));
    alg_hold_top = rh_390;
    if (alg_truthy(alg_hold(alg_not_equal(v_initializer, alg_nil())))) {
        {
            int32_t rh_395 = alg_hold_top;
            (void)((v_whilelist = alg_hold(alg_list())));
            alg_hold_top = rh_395;
            (void)(alg_hold(alg_invoke(v_whilelist, "Add", (Value[]){v_initializer}, 1)));
            alg_hold_top = rh_395;
            (void)(alg_hold(alg_invoke(v_whilelist, "Add", (Value[]){v_body}, 1)));
            alg_hold_top = rh_395;
            (void)((v_body = alg_widen(alg_hold(alg_new(k_blockstmt, (Value[]){v_whilelist}, 1)), "Stmt")));
            alg_hold_top = rh_395;
        }
    }
    alg_hold_top = rh_390;
    Value ret_58 = v_body;
    alg_root_top = rt_base;
    return ret_58;
    alg_hold_top = rh_390;
    Value ret_59 = alg_nil();
    alg_root_top = rt_base;
    return ret_59;
}

static Value m_parser_whilestatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_396 = alg_hold_top;
    Value v_condition = alg_nil();
    (void)v_condition;
    alg_root(&v_condition, 1);
    alg_hold_top = rh_396;
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    alg_hold_top = rh_396;
    (void)((v_condition = alg_hold(alg_invoke(v_this, "Expression", NULL, 0))));
    alg_hold_top = rh_396;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdo, alg_literal("Expect 'do' after condition.")}, 2)));
    alg_hold_top = rh_396;
    Value v_named = alg_hold(alg_invoke(v_this, "TakeLabel", NULL, 0));
    (void)v_named;
    alg_root(&v_named, 1);
    alg_hold_top = rh_396;
    (void)(alg_set_property(v_this, "LoopDepth", alg_hold(alg_add(alg_property(v_this, "LoopDepth"), alg_int(1)))));
    alg_hold_top = rh_396;
    (void)((v_body = alg_hold(alg_invoke(v_this, "BodyStatement", NULL, 0))));
    alg_hold_top = rh_396;
    (void)(alg_set_property(v_this, "LoopDepth", alg_hold(alg_subtract(alg_property(v_this, "LoopDepth"), alg_int(1)))));
    alg_hold_top = rh_396;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LoopLabels"), "RemoveAt", (Value[]){alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "LoopLabels"), "Length")), alg_int(1)))}, 1)));
    alg_hold_top = rh_396;
    Value v_loop = alg_hold(alg_new(k_whilestmt, (Value[]){v_condition, v_body}, 2));
    (void)v_loop;
    alg_root(&v_loop, 1);
    alg_hold_top = rh_396;
    (void)(alg_hold(alg_set_property(v_loop, "Label", v_named)));
    alg_hold_top = rh_396;
    Value ret_60 = v_loop;
    alg_root_top = rt_base;
    return ret_60;
    alg_hold_top = rh_396;
    Value ret_61 = alg_nil();
    alg_root_top = rt_base;
    return ret_61;
}

static Value m_parser_returnstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_397 = alg_hold_top;
    Value v_keyword = alg_nil();
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    alg_hold_top = rh_397;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_397;
    (void)((v_keyword = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
    alg_hold_top = rh_397;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVsemicolon}, 1)))))) {
        {
            int32_t rh_398 = alg_hold_top;
            if (alg_truthy(alg_property(v_this, "InProcedure"))) {
                alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_keyword, alg_literal("A procedure cannot exit a value.")}, 2)));
            }
            alg_hold_top = rh_398;
            (void)((v_value = alg_hold(alg_invoke(v_this, "Expression", NULL, 0))));
            alg_hold_top = rh_398;
        }
    }
    alg_hold_top = rh_397;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after exit value.")}, 2)));
    alg_hold_top = rh_397;
    Value ret_62 = alg_hold(alg_new(k_returnstmt, (Value[]){v_keyword, v_value}, 2));
    alg_root_top = rt_base;
    return ret_62;
    alg_hold_top = rh_397;
    Value ret_63 = alg_nil();
    alg_root_top = rt_base;
    return ret_63;
}

static Value m_parser_recordprivate_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_decl = args[0];
    (void)v_decl;
    alg_root(&v_decl, 1);
    int32_t rh_399 = alg_hold_top;
    if (alg_truthy(alg_hold((or_18 = alg_hold((or_17 = alg_hold((or_16 = alg_is_class(v_decl, k_functionstmt), alg_truthy(or_16) ? or_16 : alg_is_class(v_decl, k_classstmt))), alg_truthy(or_17) ? or_17 : alg_is_class(v_decl, k_objectstmt))), alg_truthy(or_18) ? or_18 : alg_is_class(v_decl, k_varstmt))))) {
        {
            int32_t rh_400 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_decl, "Name")), "Lexeme"))))}, 1)));
            alg_hold_top = rh_400;
            Value ret_64 = alg_nil();
            alg_root_top = rt_base;
            return ret_64;
            alg_hold_top = rh_400;
        }
    }
    alg_hold_top = rh_399;
    if (alg_truthy(alg_is_class(v_decl, k_vargroupstmt))) {
        {
            int32_t rh_401 = alg_hold_top;
            {
                int32_t rt_402 = alg_root_top;
                Value loop_65 = alg_iterable(alg_hold(alg_property(v_decl, "Names")));
                (void)loop_65;
                alg_root(&loop_65, 1);
                for (int32_t at_65 = 0; at_65 < alg_iterable_count(loop_65); at_65++) {
                    alg_safe_point();
                    int32_t rt_403 = alg_root_top;
                    Value v_thename = alg_iterable_at(loop_65, at_65);
                    (void)v_thename;
                    alg_root(&v_thename, 1);
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme"))))}, 1)));
                    alg_root_top = rt_403;
                }
                alg_root_top = rt_402;
            }
            alg_hold_top = rh_401;
            Value ret_66 = alg_nil();
            alg_root_top = rt_base;
            return ret_66;
            alg_hold_top = rh_401;
        }
    }
    alg_hold_top = rh_399;
    if (alg_truthy(alg_is_class(v_decl, k_enumstmt))) {
        {
            int32_t rh_404 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_decl, "Name")), "Lexeme"))))}, 1)));
            alg_hold_top = rh_404;
            {
                int32_t rt_405 = alg_root_top;
                Value loop_67 = alg_iterable(alg_hold(alg_property(v_decl, "Members")));
                (void)loop_67;
                alg_root(&loop_67, 1);
                for (int32_t at_67 = 0; at_67 < alg_iterable_count(loop_67); at_67++) {
                    alg_safe_point();
                    int32_t rt_406 = alg_root_top;
                    Value v_member = alg_iterable_at(loop_67, at_67);
                    (void)v_member;
                    alg_root(&v_member, 1);
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_member, "Lexeme"))))}, 1)));
                    alg_root_top = rt_406;
                }
                alg_root_top = rt_405;
            }
            alg_hold_top = rh_404;
            Value ret_68 = alg_nil();
            alg_root_top = rt_base;
            return ret_68;
            alg_hold_top = rh_404;
        }
    }
    alg_hold_top = rh_399;
    alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){alg_hold(alg_invoke(v_this, "Previous", NULL, 0)), alg_literal("'private' must precede a declaration.")}, 2)));
    alg_hold_top = rh_399;
    Value ret_69 = alg_nil();
    alg_root_top = rt_base;
    return ret_69;
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
    int32_t rh_407 = alg_hold_top;
    Value v_thefile = alg_nil();
    (void)v_thefile;
    alg_root(&v_thefile, 1);
    alg_hold_top = rh_407;
    Value v_dir = alg_nil();
    (void)v_dir;
    alg_root(&v_dir, 1);
    alg_hold_top = rh_407;
    (void)((v_thefile = alg_hold(alg_add(v_modulename, alg_literal(".a24")))));
    alg_hold_top = rh_407;
    (void)((v_dir = alg_hold(f_folderof(NULL, (Value[]){alg_property(v_this, "FileName")}, 1))));
    alg_hold_top = rh_407;
    if (alg_truthy(alg_hold(alg_not_equal(v_dir, alg_literal(""))))) {
        {
            int32_t rt_408 = alg_root_top;
            int32_t rh_409 = alg_hold_top;
            Value v_beside = alg_hold(alg_add(alg_hold(alg_add(v_dir, alg_char_value(47))), v_thefile));
            (void)v_beside;
            alg_root(&v_beside, 1);
            alg_hold_top = rh_409;
            if (alg_truthy(alg_hold(alg_file_exists(v_beside)))) {
                Value ret_70 = v_beside;
                alg_root_top = rt_base;
                return ret_70;
            }
            alg_hold_top = rh_409;
            alg_root_top = rt_408;
        }
    }
    alg_hold_top = rh_407;
    if (alg_truthy(alg_hold(alg_file_exists(v_thefile)))) {
        Value ret_71 = v_thefile;
        alg_root_top = rt_base;
        return ret_71;
    }
    alg_hold_top = rh_407;
    {
        int32_t rt_410 = alg_root_top;
        Value loop_72 = alg_iterable((alg_declared(d_moduleVfolders, "MODULE_FOLDERS"), v_moduleVfolders));
        (void)loop_72;
        alg_root(&loop_72, 1);
        for (int32_t at_72 = 0; at_72 < alg_iterable_count(loop_72); at_72++) {
            alg_safe_point();
            int32_t rt_411 = alg_root_top;
            Value v_folder = alg_iterable_at(loop_72, at_72);
            (void)v_folder;
            alg_root(&v_folder, 1);
            {
                int32_t rt_412 = alg_root_top;
                int32_t rh_413 = alg_hold_top;
                Value v_installed = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_str(v_folder)), alg_char_value(47))), v_thefile));
                (void)v_installed;
                alg_root(&v_installed, 1);
                alg_hold_top = rh_413;
                if (alg_truthy(alg_hold(alg_file_exists(v_installed)))) {
                    Value ret_73 = v_installed;
                    alg_root_top = rt_base;
                    return ret_73;
                }
                alg_hold_top = rh_413;
                alg_root_top = rt_412;
            }
            alg_root_top = rt_411;
        }
        alg_root_top = rt_410;
    }
    alg_hold_top = rh_407;
    Value v_searched = alg_literal("the working directory");
    (void)v_searched;
    alg_root(&v_searched, 1);
    alg_hold_top = rh_407;
    if (alg_truthy(alg_hold(alg_not_equal(v_dir, alg_literal(""))))) {
        (void)((v_searched = alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), v_dir)), alg_literal("' or the working directory")))));
    }
    alg_hold_top = rh_407;
    {
        int32_t rt_414 = alg_root_top;
        Value loop_74 = alg_iterable((alg_declared(d_moduleVfolders, "MODULE_FOLDERS"), v_moduleVfolders));
        (void)loop_74;
        alg_root(&loop_74, 1);
        for (int32_t at_74 = 0; at_74 < alg_iterable_count(loop_74); at_74++) {
            alg_safe_point();
            int32_t rt_415 = alg_root_top;
            Value v_folder = alg_iterable_at(loop_74, at_74);
            (void)v_folder;
            alg_root(&v_folder, 1);
            (void)((v_searched = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_searched, alg_literal(", or '"))), alg_hold(alg_str(v_folder)))), alg_char_value(39)))));
            alg_root_top = rt_415;
        }
        alg_root_top = rt_414;
    }
    alg_hold_top = rh_407;
    alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_where, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Could not find module '"), v_modulename)), alg_literal("': no "))), v_thefile)), alg_literal(" in "))), v_searched)), alg_char_value(46)))}, 2)));
    alg_hold_top = rh_407;
    Value ret_75 = alg_nil();
    alg_root_top = rt_base;
    return ret_75;
}

static Value m_parser_usesstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_416 = alg_hold_top;
    Value v_modulename = alg_nil();
    (void)v_modulename;
    alg_root(&v_modulename, 1);
    alg_hold_top = rh_416;
    Value v_where = alg_nil();
    (void)v_where;
    alg_root(&v_where, 1);
    alg_hold_top = rh_416;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVstring}, 1)))) {
        (void)((v_modulename = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Previous", NULL, 0)), "Literal"))))));
    } else {
        (void)((v_modulename = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expected identifier.")}, 2)), "Lexeme"))))));
    }
    alg_hold_top = rh_416;
    (void)((v_where = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
    alg_hold_top = rh_416;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expected ';'")}, 2)));
    alg_hold_top = rh_416;
    Value v_path = alg_hold(alg_invoke(v_this, "ResolveModule", (Value[]){v_where, v_modulename}, 2));
    (void)v_path;
    alg_root(&v_path, 1);
    alg_hold_top = rh_416;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Loaded"), "Contains", (Value[]){v_path}, 1)))) {
        {
            int32_t rt_417 = alg_root_top;
            int32_t rh_418 = alg_hold_top;
            Value v_seen = alg_hold(alg_new(k_modulestmt, (Value[]){v_where, alg_nil(), alg_hold(alg_list())}, 3));
            (void)v_seen;
            alg_root(&v_seen, 1);
            alg_hold_top = rh_418;
            (void)(alg_hold(alg_set_property(v_seen, "FileName", v_path)));
            alg_hold_top = rh_418;
            (void)(alg_hold(alg_set_property(v_seen, "UnitName", alg_hold(alg_invoke(v_this, "UnitStem", (Value[]){v_path}, 1)))));
            alg_hold_top = rh_418;
            Value ret_76 = v_seen;
            alg_root_top = rt_base;
            return ret_76;
            alg_hold_top = rh_418;
            alg_root_top = rt_417;
        }
    }
    alg_hold_top = rh_416;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Loaded"), "Put", (Value[]){v_path, alg_bool(true)}, 2)));
    alg_hold_top = rh_416;
    (void)(alg_hold(alg_invoke(v_this, "ClaimUnit", (Value[]){v_where, v_path}, 2)));
    alg_hold_top = rh_416;
    Value v_subscanner = alg_hold(alg_new(k_scanner, (Value[]){alg_hold(f_readwholefile(NULL, (Value[]){v_path}, 1)), v_path}, 2));
    (void)v_subscanner;
    alg_root(&v_subscanner, 1);
    alg_hold_top = rh_416;
    Value v_subparser = alg_hold(alg_new(k_parser, (Value[]){alg_hold(alg_invoke(v_subscanner, "ScanTokens", NULL, 0))}, 1));
    (void)v_subparser;
    alg_root(&v_subparser, 1);
    alg_hold_top = rh_416;
    (void)(alg_hold(alg_set_property(v_subparser, "FileName", v_path)));
    alg_hold_top = rh_416;
    (void)(alg_hold(alg_set_property(v_subparser, "Loaded", alg_property(v_this, "Loaded"))));
    alg_hold_top = rh_416;
    (void)(alg_hold(alg_set_property(v_subparser, "Claimed", alg_property(v_this, "Claimed"))));
    alg_hold_top = rh_416;
    Value v_result = alg_hold(alg_invoke(v_subparser, "Parse", NULL, 0));
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_416;
    Value v_themodule = alg_hold(alg_new(k_modulestmt, (Value[]){v_where, v_result, alg_hold(alg_property(v_subparser, "PrivateNames"))}, 3));
    (void)v_themodule;
    alg_root(&v_themodule, 1);
    alg_hold_top = rh_416;
    (void)(alg_hold(alg_set_property(v_themodule, "FileName", v_path)));
    alg_hold_top = rh_416;
    (void)(alg_hold(alg_set_property(v_themodule, "UnitName", alg_hold(alg_invoke(v_this, "UnitStem", (Value[]){v_path}, 1)))));
    alg_hold_top = rh_416;
    Value ret_77 = v_themodule;
    alg_root_top = rt_base;
    return ret_77;
    alg_hold_top = rh_416;
    Value ret_78 = alg_nil();
    alg_root_top = rt_base;
    return ret_78;
}

static Value m_parser_constdeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_419 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_419;
    (void)((v_name = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect constant name.")}, 2))));
    alg_hold_top = rh_419;
    Value v_typename = alg_literal("");
    (void)v_typename;
    alg_root(&v_typename, 1);
    alg_hold_top = rh_419;
    Value v_generic = alg_literal("");
    (void)v_generic;
    alg_root(&v_generic, 1);
    alg_hold_top = rh_419;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1)))) {
        {
            int32_t rh_420 = alg_hold_top;
            (void)((v_typename = alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect type name.")}, 2)), "Lexeme"))}, 1))));
            alg_hold_top = rh_420;
            if (alg_truthy(alg_hold((or_19 = alg_hold(alg_invoke(v_this, "IsCollectionType", (Value[]){v_typename}, 1)), !alg_truthy(or_19) ? or_19 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))))) {
                (void)((v_generic = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect generic type.")}, 2)), "Lexeme"))))));
            }
            alg_hold_top = rh_420;
        }
    }
    alg_hold_top = rh_419;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVassign}, 1)))))) {
        alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_name, alg_literal("A constant must be given a value.")}, 2)));
    }
    alg_hold_top = rh_419;
    Value v_initializer = alg_hold(alg_invoke(v_this, "Expression", NULL, 0));
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    alg_hold_top = rh_419;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after constant declaration.")}, 2)));
    alg_hold_top = rh_419;
    Value v_thevar = alg_hold(alg_new(k_varstmt, (Value[]){v_name, v_initializer}, 2));
    (void)v_thevar;
    alg_root(&v_thevar, 1);
    alg_hold_top = rh_419;
    (void)(alg_hold(alg_set_property(v_thevar, "TypeName", v_typename)));
    alg_hold_top = rh_419;
    (void)(alg_hold(alg_set_property(v_thevar, "Generic", v_generic)));
    alg_hold_top = rh_419;
    (void)(alg_hold(alg_set_property(v_thevar, "IsConstant", alg_bool(true))));
    alg_hold_top = rh_419;
    Value ret_79 = v_thevar;
    alg_root_top = rt_base;
    return ret_79;
    alg_hold_top = rh_419;
    Value ret_80 = alg_nil();
    alg_root_top = rt_base;
    return ret_80;
}

static Value m_parser_matchvisibility_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_421 = alg_hold_top;
    if (alg_truthy(alg_hold((or_20 = alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVprivate}, 1)), !alg_truthy(or_20) ? or_20 : alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0)), "TypeOfToken")), e_tokentype_tokenVcolon)))))) {
        {
            int32_t rh_422 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
            alg_hold_top = rh_422;
            (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
            alg_hold_top = rh_422;
            (void)(alg_set_property(v_this, "InPrivateSection", alg_bool(true)));
            alg_hold_top = rh_422;
            Value ret_81 = alg_bool(true);
            alg_root_top = rt_base;
            return ret_81;
            alg_hold_top = rh_422;
        }
    }
    alg_hold_top = rh_421;
    if (alg_truthy(alg_hold((or_21 = alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVpublic}, 1)), !alg_truthy(or_21) ? or_21 : alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0)), "TypeOfToken")), e_tokentype_tokenVcolon)))))) {
        {
            int32_t rh_423 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
            alg_hold_top = rh_423;
            (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
            alg_hold_top = rh_423;
            (void)(alg_set_property(v_this, "InPrivateSection", alg_bool(false)));
            alg_hold_top = rh_423;
            Value ret_82 = alg_bool(true);
            alg_root_top = rt_base;
            return ret_82;
            alg_hold_top = rh_423;
        }
    }
    alg_hold_top = rh_421;
    Value ret_83 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_83;
    alg_hold_top = rh_421;
    Value ret_84 = alg_nil();
    alg_root_top = rt_base;
    return ret_84;
}

static Value m_parser_isdeclarationsection_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_424 = alg_hold_top;
    Value ret_85 = alg_hold((or_23 = alg_hold((or_22 = alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVvar}, 1)), alg_truthy(or_22) ? or_22 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVconst}, 1)))), alg_truthy(or_23) ? or_23 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVtype}, 1))));
    alg_root_top = rt_base;
    return ret_85;
    alg_hold_top = rh_424;
    Value ret_86 = alg_nil();
    alg_root_top = rt_base;
    return ret_86;
}

static Value m_parser_isnextsection_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_425 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        Value ret_87 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_87;
    }
    alg_hold_top = rh_425;
    Value ret_88 = alg_hold((or_30 = alg_hold((or_29 = alg_hold((or_28 = alg_hold((or_27 = alg_hold((or_26 = alg_hold((or_25 = alg_hold((or_24 = alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1)), alg_truthy(or_24) ? or_24 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVbegin}, 1)))), alg_truthy(or_25) ? or_25 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVfunction}, 1)))), alg_truthy(or_26) ? or_26 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVprocedure}, 1)))), alg_truthy(or_27) ? or_27 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVconstructor}, 1)))), alg_truthy(or_28) ? or_28 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVvar}, 1)))), alg_truthy(or_29) ? or_29 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVconst}, 1)))), alg_truthy(or_30) ? or_30 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVtype}, 1))));
    alg_root_top = rt_base;
    return ret_88;
    alg_hold_top = rh_425;
    Value ret_89 = alg_nil();
    alg_root_top = rt_base;
    return ret_89;
}

static Value m_parser_declarationsection_1_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_isconstant = alg_widen(args[0], "Boolean");
    (void)v_isconstant;
    alg_root(&v_isconstant, 1);
    int32_t rh_426 = alg_hold_top;
    Value v_stmts = alg_nil();
    (void)v_stmts;
    alg_root(&v_stmts, 1);
    alg_hold_top = rh_426;
    Value v_noun = alg_nil();
    (void)v_noun;
    alg_root(&v_noun, 1);
    alg_hold_top = rh_426;
    (void)((v_stmts = alg_hold(alg_list())));
    alg_hold_top = rh_426;
    (void)((v_noun = alg_literal("variable")));
    alg_hold_top = rh_426;
    if (alg_truthy(v_isconstant)) {
        (void)((v_noun = alg_literal("constant")));
    }
    alg_hold_top = rh_426;
    {
        int32_t rh_427 = alg_hold_top;
        while ((alg_hold_top = rh_427, alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsNextSection", NULL, 0))))))) {
            alg_safe_point();
            {
                int32_t rt_428 = alg_root_top;
                int32_t rh_429 = alg_hold_top;
                {
                    int32_t rh_430 = alg_hold_top;
                    while ((alg_hold_top = rh_430, alg_truthy(alg_hold(alg_invoke(v_this, "MatchVisibility", NULL, 0))))) {
                        alg_safe_point();
                        {
                            int32_t rh_431 = alg_hold_top;
                        }
                    }
                }
                alg_hold_top = rh_429;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "IsNextSection", NULL, 0)))) {
                    break;
                }
                alg_hold_top = rh_429;
                Value v_names = alg_hold(alg_list());
                (void)v_names;
                alg_root(&v_names, 1);
                alg_hold_top = rh_429;
                (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expect "), v_noun)), alg_literal(" name.")))}, 2))}, 1)));
                alg_hold_top = rh_429;
                {
                    int32_t rh_432 = alg_hold_top;
                    while ((alg_hold_top = rh_432, alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))))) {
                        alg_safe_point();
                        (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expect "), v_noun)), alg_literal(" name.")))}, 2))}, 1)));
                    }
                }
                alg_hold_top = rh_429;
                if (alg_truthy(alg_property(v_this, "InPrivateSection"))) {
                    {
                        int32_t rt_433 = alg_root_top;
                        Value loop_90 = alg_iterable(v_names);
                        (void)loop_90;
                        alg_root(&loop_90, 1);
                        for (int32_t at_90 = 0; at_90 < alg_iterable_count(loop_90); at_90++) {
                            alg_safe_point();
                            int32_t rt_434 = alg_root_top;
                            Value v_thename = alg_iterable_at(loop_90, at_90);
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            (void)(alg_hold(alg_invoke(alg_property(v_this, "ClassPrivates"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme"))))}, 1)));
                            alg_root_top = rt_434;
                        }
                        alg_root_top = rt_433;
                    }
                }
                alg_hold_top = rh_429;
                Value v_typename = alg_literal("");
                (void)v_typename;
                alg_root(&v_typename, 1);
                alg_hold_top = rh_429;
                Value v_generic = alg_literal("");
                (void)v_generic;
                alg_root(&v_generic, 1);
                alg_hold_top = rh_429;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1)))) {
                    {
                        int32_t rh_435 = alg_hold_top;
                        (void)((v_typename = alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect type name.")}, 2)), "Lexeme"))}, 1))));
                        alg_hold_top = rh_435;
                        if (alg_truthy(alg_hold((or_31 = alg_hold(alg_invoke(v_this, "IsCollectionType", (Value[]){v_typename}, 1)), !alg_truthy(or_31) ? or_31 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))))) {
                            (void)((v_generic = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect generic type.")}, 2)), "Lexeme"))))));
                        }
                        alg_hold_top = rh_435;
                    }
                }
                alg_hold_top = rh_429;
                Value v_initializer = alg_cast_class(alg_nil(), k_expr, "Expr");
                (void)v_initializer;
                alg_root(&v_initializer, 1);
                alg_hold_top = rh_429;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVassign}, 1)))) {
                    (void)((v_initializer = alg_hold(alg_invoke(v_this, "Expression", NULL, 0))));
                } else {
                    if (alg_truthy(v_isconstant)) {
                        alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){alg_hold(alg_subscript_get(v_names, alg_int(0))), alg_literal("A constant must be given a value.")}, 2)));
                    }
                }
                alg_hold_top = rh_429;
                (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expect ';' after "), v_noun)), alg_literal(" declaration.")))}, 2)));
                alg_hold_top = rh_429;
                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_names, "Length")), alg_int(1))))) {
                    {
                        int32_t rt_436 = alg_root_top;
                        int32_t rh_437 = alg_hold_top;
                        Value v_thevar = alg_hold(alg_new(k_varstmt, (Value[]){alg_hold(alg_subscript_get(v_names, alg_int(0))), v_initializer}, 2));
                        (void)v_thevar;
                        alg_root(&v_thevar, 1);
                        alg_hold_top = rh_437;
                        (void)(alg_hold(alg_set_property(v_thevar, "TypeName", v_typename)));
                        alg_hold_top = rh_437;
                        (void)(alg_hold(alg_set_property(v_thevar, "Generic", v_generic)));
                        alg_hold_top = rh_437;
                        (void)(alg_hold(alg_set_property(v_thevar, "IsConstant", v_isconstant)));
                        alg_hold_top = rh_437;
                        (void)(alg_hold(alg_invoke(v_stmts, "Add", (Value[]){v_thevar}, 1)));
                        alg_hold_top = rh_437;
                        alg_root_top = rt_436;
                    }
                } else {
                    {
                        int32_t rt_438 = alg_root_top;
                        int32_t rh_439 = alg_hold_top;
                        Value v_thegroup = alg_hold(alg_new(k_vargroupstmt, (Value[]){v_names, v_initializer}, 2));
                        (void)v_thegroup;
                        alg_root(&v_thegroup, 1);
                        alg_hold_top = rh_439;
                        (void)(alg_hold(alg_set_property(v_thegroup, "TypeName", v_typename)));
                        alg_hold_top = rh_439;
                        (void)(alg_hold(alg_set_property(v_thegroup, "Generic", v_generic)));
                        alg_hold_top = rh_439;
                        (void)(alg_hold(alg_set_property(v_thegroup, "IsConstant", v_isconstant)));
                        alg_hold_top = rh_439;
                        (void)(alg_hold(alg_invoke(v_stmts, "Add", (Value[]){v_thegroup}, 1)));
                        alg_hold_top = rh_439;
                        alg_root_top = rt_438;
                    }
                }
                alg_hold_top = rh_429;
                alg_root_top = rt_428;
            }
        }
    }
    alg_hold_top = rh_426;
    Value ret_91 = v_stmts;
    alg_root_top = rt_base;
    return ret_91;
    alg_hold_top = rh_426;
    Value ret_92 = alg_nil();
    alg_root_top = rt_base;
    return ret_92;
}

static Value m_parser_readdeclarationsections_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_body = alg_widen(args[0], "List");
    (void)v_body;
    alg_root(&v_body, 1);
    int32_t rh_440 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_body, alg_bool(false)}, 2)));
    alg_hold_top = rh_440;
    Value ret_93 = alg_nil();
    alg_root_top = rt_base;
    return ret_93;
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
    int32_t rh_441 = alg_hold_top;
    {
        int32_t rh_442 = alg_hold_top;
        while ((alg_hold_top = rh_442, alg_truthy(alg_bool(true)))) {
            alg_safe_point();
            {
                int32_t rh_443 = alg_hold_top;
                if (alg_truthy(v_allowvisibility)) {
                    {
                        int32_t rh_444 = alg_hold_top;
                        while ((alg_hold_top = rh_444, alg_truthy(alg_hold(alg_invoke(v_this, "MatchVisibility", NULL, 0))))) {
                            alg_safe_point();
                            {
                                int32_t rh_445 = alg_hold_top;
                            }
                        }
                    }
                }
                alg_hold_top = rh_443;
                if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsDeclarationSection", NULL, 0)))))) {
                    break;
                }
                alg_hold_top = rh_443;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVvar}, 1)))) {
                    {
                        int32_t rt_446 = alg_root_top;
                        int32_t rh_447 = alg_hold_top;
                        Value v_section = alg_hold(alg_invoke(v_this, "DeclarationSection", (Value[]){alg_bool(false)}, 1));
                        (void)v_section;
                        alg_root(&v_section, 1);
                        alg_hold_top = rh_447;
                        {
                            int32_t rt_448 = alg_root_top;
                            Value loop_94 = alg_iterable(v_section);
                            (void)loop_94;
                            alg_root(&loop_94, 1);
                            for (int32_t at_94 = 0; at_94 < alg_iterable_count(loop_94); at_94++) {
                                alg_safe_point();
                                int32_t rt_449 = alg_root_top;
                                Value v_declaration = alg_iterable_at(loop_94, at_94);
                                (void)v_declaration;
                                alg_root(&v_declaration, 1);
                                (void)(alg_hold(alg_invoke(v_body, "Add", (Value[]){v_declaration}, 1)));
                                alg_root_top = rt_449;
                            }
                            alg_root_top = rt_448;
                        }
                        alg_hold_top = rh_447;
                        alg_root_top = rt_446;
                    }
                } else {
                    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVconst}, 1)))) {
                        {
                            int32_t rt_450 = alg_root_top;
                            int32_t rh_451 = alg_hold_top;
                            Value v_section = alg_hold(alg_invoke(v_this, "DeclarationSection", (Value[]){alg_bool(true)}, 1));
                            (void)v_section;
                            alg_root(&v_section, 1);
                            alg_hold_top = rh_451;
                            {
                                int32_t rt_452 = alg_root_top;
                                Value loop_95 = alg_iterable(v_section);
                                (void)loop_95;
                                alg_root(&loop_95, 1);
                                for (int32_t at_95 = 0; at_95 < alg_iterable_count(loop_95); at_95++) {
                                    alg_safe_point();
                                    int32_t rt_453 = alg_root_top;
                                    Value v_declaration = alg_iterable_at(loop_95, at_95);
                                    (void)v_declaration;
                                    alg_root(&v_declaration, 1);
                                    (void)(alg_hold(alg_invoke(v_body, "Add", (Value[]){v_declaration}, 1)));
                                    alg_root_top = rt_453;
                                }
                                alg_root_top = rt_452;
                            }
                            alg_hold_top = rh_451;
                            alg_root_top = rt_450;
                        }
                    } else {
                        {
                            int32_t rh_454 = alg_hold_top;
                            (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
                            alg_hold_top = rh_454;
                            {
                                int32_t rh_455 = alg_hold_top;
                                while ((alg_hold_top = rh_455, alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsNextSection", NULL, 0))))))) {
                                    alg_safe_point();
                                    (void)(alg_hold(alg_invoke(v_body, "Add", (Value[]){alg_hold(alg_invoke(v_this, "EnumDeclaration", NULL, 0))}, 1)));
                                }
                            }
                            alg_hold_top = rh_454;
                        }
                    }
                }
                alg_hold_top = rh_443;
            }
        }
    }
    alg_hold_top = rh_441;
    Value ret_96 = alg_nil();
    alg_root_top = rt_base;
    return ret_96;
}

static Value m_parser_forinstatement_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_456 = alg_hold_top;
    Value v_iterable = alg_nil();
    (void)v_iterable;
    alg_root(&v_iterable, 1);
    alg_hold_top = rh_456;
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    alg_hold_top = rh_456;
    (void)((v_iterable = alg_hold(alg_invoke(v_this, "Expression", NULL, 0))));
    alg_hold_top = rh_456;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdo, alg_literal("Expect 'do' after 'for ... in' clause.")}, 2)));
    alg_hold_top = rh_456;
    Value v_named = alg_hold(alg_invoke(v_this, "TakeLabel", NULL, 0));
    (void)v_named;
    alg_root(&v_named, 1);
    alg_hold_top = rh_456;
    (void)(alg_set_property(v_this, "LoopDepth", alg_hold(alg_add(alg_property(v_this, "LoopDepth"), alg_int(1)))));
    alg_hold_top = rh_456;
    (void)((v_body = alg_hold(alg_invoke(v_this, "BodyStatement", NULL, 0))));
    alg_hold_top = rh_456;
    (void)(alg_set_property(v_this, "LoopDepth", alg_hold(alg_subtract(alg_property(v_this, "LoopDepth"), alg_int(1)))));
    alg_hold_top = rh_456;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LoopLabels"), "RemoveAt", (Value[]){alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "LoopLabels"), "Length")), alg_int(1)))}, 1)));
    alg_hold_top = rh_456;
    Value v_loop = alg_hold(alg_new(k_forinstmt, (Value[]){v_name, v_iterable, v_body}, 3));
    (void)v_loop;
    alg_root(&v_loop, 1);
    alg_hold_top = rh_456;
    (void)(alg_hold(alg_set_property(v_loop, "Label", v_named)));
    alg_hold_top = rh_456;
    Value ret_97 = v_loop;
    alg_root_top = rt_base;
    return ret_97;
    alg_hold_top = rh_456;
    Value ret_98 = alg_nil();
    alg_root_top = rt_base;
    return ret_98;
}

static Value m_parser_breakstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_457 = alg_hold_top;
    Value v_keyword = alg_nil();
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    alg_hold_top = rh_457;
    (void)((v_keyword = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
    alg_hold_top = rh_457;
    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "LoopDepth"), alg_int(0))))) {
        alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_keyword, alg_literal("Must be inside a loop to use 'break'.")}, 2)));
    }
    alg_hold_top = rh_457;
    Value v_named = alg_hold(alg_invoke(v_this, "JumpLabel", (Value[]){v_keyword, alg_literal("break")}, 2));
    (void)v_named;
    alg_root(&v_named, 1);
    alg_hold_top = rh_457;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after 'break'.")}, 2)));
    alg_hold_top = rh_457;
    Value v_leaving = alg_hold(alg_new(k_breakstmt, (Value[]){v_keyword}, 1));
    (void)v_leaving;
    alg_root(&v_leaving, 1);
    alg_hold_top = rh_457;
    (void)(alg_hold(alg_set_property(v_leaving, "Label", v_named)));
    alg_hold_top = rh_457;
    Value ret_99 = v_leaving;
    alg_root_top = rt_base;
    return ret_99;
    alg_hold_top = rh_457;
    Value ret_100 = alg_nil();
    alg_root_top = rt_base;
    return ret_100;
}

static Value m_parser_labelstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_458 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_458;
    (void)((v_name = alg_hold(alg_invoke(v_this, "Advance", NULL, 0))));
    alg_hold_top = rh_458;
    (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
    alg_hold_top = rh_458;
    (void)(alg_set_property(v_this, "PendingLabel", alg_hold(alg_str(alg_hold(alg_property(v_name, "Lexeme"))))));
    alg_hold_top = rh_458;
    Value v_inner = alg_hold(alg_invoke(v_this, "Statement", NULL, 0));
    (void)v_inner;
    alg_root(&v_inner, 1);
    alg_hold_top = rh_458;
    (void)(alg_set_property(v_this, "PendingLabel", alg_literal("")));
    alg_hold_top = rh_458;
    Value ret_101 = alg_hold(alg_new(k_labelstmt, (Value[]){v_name, v_inner}, 2));
    alg_root_top = rt_base;
    return ret_101;
    alg_hold_top = rh_458;
    Value ret_102 = alg_nil();
    alg_root_top = rt_base;
    return ret_102;
}

static Value m_parser_takelabel_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_459 = alg_hold_top;
    Value v_taken = alg_nil();
    (void)v_taken;
    alg_root(&v_taken, 1);
    alg_hold_top = rh_459;
    (void)((v_taken = alg_property(v_this, "PendingLabel")));
    alg_hold_top = rh_459;
    (void)(alg_set_property(v_this, "PendingLabel", alg_literal("")));
    alg_hold_top = rh_459;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LoopLabels"), "Add", (Value[]){v_taken}, 1)));
    alg_hold_top = rh_459;
    Value ret_103 = v_taken;
    alg_root_top = rt_base;
    return ret_103;
    alg_hold_top = rh_459;
    Value ret_104 = alg_nil();
    alg_root_top = rt_base;
    return ret_104;
}

static Value m_parser_enclosingloop_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    int32_t rh_460 = alg_hold_top;
    {
        int32_t rt_461 = alg_root_top;
        Value loop_105 = alg_iterable(alg_property(v_this, "LoopLabels"));
        (void)loop_105;
        alg_root(&loop_105, 1);
        for (int32_t at_105 = 0; at_105 < alg_iterable_count(loop_105); at_105++) {
            alg_safe_point();
            int32_t rt_462 = alg_root_top;
            Value v_looplabel = alg_iterable_at(loop_105, at_105);
            (void)v_looplabel;
            alg_root(&v_looplabel, 1);
            if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(v_looplabel))}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_thelabel}, 1)))))) {
                Value ret_106 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_106;
            }
            alg_root_top = rt_462;
        }
        alg_root_top = rt_461;
    }
    alg_hold_top = rh_460;
    Value ret_107 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_107;
    alg_hold_top = rh_460;
    Value ret_108 = alg_nil();
    alg_root_top = rt_base;
    return ret_108;
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
    int32_t rh_463 = alg_hold_top;
    Value v_named = alg_nil();
    (void)v_named;
    alg_root(&v_named, 1);
    alg_hold_top = rh_463;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)))))) {
        Value ret_109 = alg_literal("");
        alg_root_top = rt_base;
        return ret_109;
    }
    alg_hold_top = rh_463;
    (void)((v_named = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)), "Lexeme"))))));
    alg_hold_top = rh_463;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "EnclosingLoop", (Value[]){v_named}, 1)))))) {
        alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_keyword, alg_hold(alg_add(alg_hold(alg_add(alg_literal("No enclosing loop is labelled '"), v_named)), alg_literal("'.")))}, 2)));
    }
    alg_hold_top = rh_463;
    Value ret_110 = v_named;
    alg_root_top = rt_base;
    return ret_110;
    alg_hold_top = rh_463;
    Value ret_111 = alg_nil();
    alg_root_top = rt_base;
    return ret_111;
}

static Value m_parser_continuestatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_464 = alg_hold_top;
    Value v_keyword = alg_nil();
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    alg_hold_top = rh_464;
    (void)((v_keyword = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
    alg_hold_top = rh_464;
    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "LoopDepth"), alg_int(0))))) {
        alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_keyword, alg_literal("Must be inside a loop to use 'continue'.")}, 2)));
    }
    alg_hold_top = rh_464;
    Value v_named = alg_hold(alg_invoke(v_this, "JumpLabel", (Value[]){v_keyword, alg_literal("continue")}, 2));
    (void)v_named;
    alg_root(&v_named, 1);
    alg_hold_top = rh_464;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after 'continue'.")}, 2)));
    alg_hold_top = rh_464;
    Value v_beginning = alg_hold(alg_new(k_continuestmt, (Value[]){v_keyword}, 1));
    (void)v_beginning;
    alg_root(&v_beginning, 1);
    alg_hold_top = rh_464;
    (void)(alg_hold(alg_set_property(v_beginning, "Label", v_named)));
    alg_hold_top = rh_464;
    Value ret_112 = v_beginning;
    alg_root_top = rt_base;
    return ret_112;
    alg_hold_top = rh_464;
    Value ret_113 = alg_nil();
    alg_root_top = rt_base;
    return ret_113;
}

static Value m_parser_operatortoken_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_465 = alg_hold_top;
    if (alg_truthy(alg_hold((or_36 = alg_hold((or_35 = alg_hold((or_34 = alg_hold((or_33 = alg_hold((or_32 = alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVplus}, 1)), alg_truthy(or_32) ? or_32 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVminus}, 1)))), alg_truthy(or_33) ? or_33 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVstar}, 1)))), alg_truthy(or_34) ? or_34 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVslash}, 1)))), alg_truthy(or_35) ? or_35 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVdiv}, 1)))), alg_truthy(or_36) ? or_36 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVmod}, 1)))))) {
        Value ret_114 = alg_hold(alg_invoke(v_this, "Advance", NULL, 0));
        alg_root_top = rt_base;
        return ret_114;
    }
    alg_hold_top = rh_465;
    if (alg_truthy(alg_hold((or_41 = alg_hold((or_40 = alg_hold((or_39 = alg_hold((or_38 = alg_hold((or_37 = alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVampersand}, 1)), alg_truthy(or_37) ? or_37 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVpipe}, 1)))), alg_truthy(or_38) ? or_38 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVcaret}, 1)))), alg_truthy(or_39) ? or_39 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVtilde}, 1)))), alg_truthy(or_40) ? or_40 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVshiftVleft}, 1)))), alg_truthy(or_41) ? or_41 : alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVshiftVright}, 1)))))) {
        Value ret_115 = alg_hold(alg_invoke(v_this, "Advance", NULL, 0));
        alg_root_top = rt_base;
        return ret_115;
    }
    alg_hold_top = rh_465;
    alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_literal("An operator must be one of + - * / div mod & | ^ ~ << >>.")}, 2)));
    alg_hold_top = rh_465;
    Value ret_116 = alg_nil();
    alg_root_top = rt_base;
    return ret_116;
}

static Value m_parser_parseoperator_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_466 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_466;
    Value v_params = alg_nil();
    (void)v_params;
    alg_root(&v_params, 1);
    alg_hold_top = rh_466;
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    alg_hold_top = rh_466;
    (void)((v_name = alg_hold(alg_invoke(v_this, "OperatorToken", NULL, 0))));
    alg_hold_top = rh_466;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVleftVparen, alg_literal("Expect '(' after operator.")}, 2)));
    alg_hold_top = rh_466;
    (void)((v_params = alg_hold(alg_list())));
    alg_hold_top = rh_466;
    Value v_paramtypes = alg_hold(alg_list());
    (void)v_paramtypes;
    alg_root(&v_paramtypes, 1);
    alg_hold_top = rh_466;
    Value v_paramgenerics = alg_hold(alg_list());
    (void)v_paramgenerics;
    alg_root(&v_paramgenerics, 1);
    alg_hold_top = rh_466;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVrightVparen}, 1)))))) {
        {
            int32_t rh_467 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_params, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect parameter name.")}, 2))}, 1)));
            alg_hold_top = rh_467;
            (void)(alg_hold(alg_invoke(v_paramtypes, "Add", (Value[]){alg_hold(alg_invoke(v_this, "ParameterType", NULL, 0))}, 1)));
            alg_hold_top = rh_467;
            (void)(alg_hold(alg_invoke(v_paramgenerics, "Add", (Value[]){alg_property(v_this, "LastGeneric")}, 1)));
            alg_hold_top = rh_467;
        }
    }
    alg_hold_top = rh_466;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_literal("Expect ')' after operator parameters.")}, 2)));
    alg_hold_top = rh_466;
    if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(v_params, "Length")), alg_int(1))))) {
        alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_name, alg_literal("An operator takes one argument, or none for a unary one.")}, 2)));
    }
    alg_hold_top = rh_466;
    Value v_returntype = alg_literal("");
    (void)v_returntype;
    alg_root(&v_returntype, 1);
    alg_hold_top = rh_466;
    Value v_returngeneric = alg_literal("");
    (void)v_returngeneric;
    alg_root(&v_returngeneric, 1);
    alg_hold_top = rh_466;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1)))) {
        {
            int32_t rh_468 = alg_hold_top;
            (void)((v_returntype = alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect type name.")}, 2)), "Lexeme"))}, 1))));
            alg_hold_top = rh_468;
            if (alg_truthy(alg_hold((or_42 = alg_hold(alg_invoke(v_this, "IsCollectionType", (Value[]){v_returntype}, 1)), !alg_truthy(or_42) ? or_42 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))))) {
                (void)((v_returngeneric = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect generic type.")}, 2)), "Lexeme"))))));
            }
            alg_hold_top = rh_468;
        }
    }
    alg_hold_top = rh_466;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after operator signature.")}, 2)));
    alg_hold_top = rh_466;
    (void)((v_body = alg_hold(alg_list())));
    alg_hold_top = rh_466;
    (void)(alg_hold(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_body}, 1)));
    alg_hold_top = rh_466;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_literal("Expect 'begin' before operator body.")}, 2)));
    alg_hold_top = rh_466;
    Value v_wasinprocedure = alg_property(v_this, "InProcedure");
    (void)v_wasinprocedure;
    alg_root(&v_wasinprocedure, 1);
    alg_hold_top = rh_466;
    (void)(alg_set_property(v_this, "InProcedure", alg_bool(false)));
    alg_hold_top = rh_466;
    (void)(alg_set_property(v_this, "SubprogramDepth", alg_hold(alg_add(alg_property(v_this, "SubprogramDepth"), alg_int(1)))));
    alg_hold_top = rh_466;
    Value v_rest = alg_hold(alg_invoke(v_this, "Block", NULL, 0));
    (void)v_rest;
    alg_root(&v_rest, 1);
    alg_hold_top = rh_466;
    (void)(alg_set_property(v_this, "SubprogramDepth", alg_hold(alg_subtract(alg_property(v_this, "SubprogramDepth"), alg_int(1)))));
    alg_hold_top = rh_466;
    (void)(alg_set_property(v_this, "InProcedure", v_wasinprocedure));
    alg_hold_top = rh_466;
    {
        int32_t rt_469 = alg_root_top;
        Value loop_117 = alg_iterable(v_rest);
        (void)loop_117;
        alg_root(&loop_117, 1);
        for (int32_t at_117 = 0; at_117 < alg_iterable_count(loop_117); at_117++) {
            alg_safe_point();
            int32_t rt_470 = alg_root_top;
            Value v_each = alg_iterable_at(loop_117, at_117);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_hold(alg_invoke(v_body, "Add", (Value[]){v_each}, 1)));
            alg_root_top = rt_470;
        }
        alg_root_top = rt_469;
    }
    alg_hold_top = rh_466;
    Value v_theoperator = alg_hold(alg_new(k_functionstmt, (Value[]){v_name, v_params, v_body}, 3));
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    alg_hold_top = rh_466;
    (void)(alg_hold(alg_set_property(v_theoperator, "ReturnType", v_returntype)));
    alg_hold_top = rh_466;
    (void)(alg_hold(alg_set_property(v_theoperator, "ReturnGeneric", v_returngeneric)));
    alg_hold_top = rh_466;
    (void)(alg_hold(alg_set_property(v_theoperator, "ParamTypes", v_paramtypes)));
    alg_hold_top = rh_466;
    (void)(alg_hold(alg_set_property(v_theoperator, "ParamGenerics", v_paramgenerics)));
    alg_hold_top = rh_466;
    Value ret_118 = v_theoperator;
    alg_root_top = rt_base;
    return ret_118;
    alg_hold_top = rh_466;
    Value ret_119 = alg_nil();
    alg_root_top = rt_base;
    return ret_119;
}

static Value m_parser_parseproperty_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_471 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_471;
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    alg_hold_top = rh_471;
    (void)((v_name = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect property name.")}, 2))));
    alg_hold_top = rh_471;
    Value v_returntype = alg_literal("");
    (void)v_returntype;
    alg_root(&v_returntype, 1);
    alg_hold_top = rh_471;
    Value v_returngeneric = alg_literal("");
    (void)v_returngeneric;
    alg_root(&v_returngeneric, 1);
    alg_hold_top = rh_471;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1)))) {
        {
            int32_t rh_472 = alg_hold_top;
            (void)((v_returntype = alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect type name.")}, 2)), "Lexeme"))}, 1))));
            alg_hold_top = rh_472;
            if (alg_truthy(alg_hold((or_43 = alg_hold(alg_invoke(v_this, "IsCollectionType", (Value[]){v_returntype}, 1)), !alg_truthy(or_43) ? or_43 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))))) {
                (void)((v_returngeneric = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect generic type.")}, 2)), "Lexeme"))))));
            }
            alg_hold_top = rh_472;
        }
    }
    alg_hold_top = rh_471;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after property signature.")}, 2)));
    alg_hold_top = rh_471;
    (void)((v_body = alg_hold(alg_list())));
    alg_hold_top = rh_471;
    (void)(alg_hold(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_body}, 1)));
    alg_hold_top = rh_471;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_literal("Expect 'begin' before property body.")}, 2)));
    alg_hold_top = rh_471;
    Value v_wasinprocedure = alg_property(v_this, "InProcedure");
    (void)v_wasinprocedure;
    alg_root(&v_wasinprocedure, 1);
    alg_hold_top = rh_471;
    (void)(alg_set_property(v_this, "InProcedure", alg_bool(false)));
    alg_hold_top = rh_471;
    (void)(alg_set_property(v_this, "SubprogramDepth", alg_hold(alg_add(alg_property(v_this, "SubprogramDepth"), alg_int(1)))));
    alg_hold_top = rh_471;
    Value v_rest = alg_hold(alg_invoke(v_this, "Block", NULL, 0));
    (void)v_rest;
    alg_root(&v_rest, 1);
    alg_hold_top = rh_471;
    (void)(alg_set_property(v_this, "SubprogramDepth", alg_hold(alg_subtract(alg_property(v_this, "SubprogramDepth"), alg_int(1)))));
    alg_hold_top = rh_471;
    (void)(alg_set_property(v_this, "InProcedure", v_wasinprocedure));
    alg_hold_top = rh_471;
    {
        int32_t rt_473 = alg_root_top;
        Value loop_120 = alg_iterable(v_rest);
        (void)loop_120;
        alg_root(&loop_120, 1);
        for (int32_t at_120 = 0; at_120 < alg_iterable_count(loop_120); at_120++) {
            alg_safe_point();
            int32_t rt_474 = alg_root_top;
            Value v_each = alg_iterable_at(loop_120, at_120);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_hold(alg_invoke(v_body, "Add", (Value[]){v_each}, 1)));
            alg_root_top = rt_474;
        }
        alg_root_top = rt_473;
    }
    alg_hold_top = rh_471;
    Value v_theproperty = alg_hold(alg_new(k_functionstmt, (Value[]){v_name, alg_hold(alg_list()), v_body}, 3));
    (void)v_theproperty;
    alg_root(&v_theproperty, 1);
    alg_hold_top = rh_471;
    (void)(alg_hold(alg_set_property(v_theproperty, "ReturnType", v_returntype)));
    alg_hold_top = rh_471;
    (void)(alg_hold(alg_set_property(v_theproperty, "ReturnGeneric", v_returngeneric)));
    alg_hold_top = rh_471;
    (void)(alg_hold(alg_set_property(v_theproperty, "IsProperty", alg_bool(true))));
    alg_hold_top = rh_471;
    Value ret_121 = v_theproperty;
    alg_root_top = rt_base;
    return ret_121;
    alg_hold_top = rh_471;
    Value ret_122 = alg_nil();
    alg_root_top = rt_base;
    return ret_122;
}

static Value m_parser_gotostatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_475 = alg_hold_top;
    Value v_keyword = alg_nil();
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    alg_hold_top = rh_475;
    (void)((v_keyword = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
    alg_hold_top = rh_475;
    Value v_named = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect a label after 'goto'.")}, 2)), "Lexeme"))));
    (void)v_named;
    alg_root(&v_named, 1);
    alg_hold_top = rh_475;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after 'goto'.")}, 2)));
    alg_hold_top = rh_475;
    Value ret_123 = alg_hold(alg_new(k_gotostmt, (Value[]){v_keyword, v_named}, 2));
    alg_root_top = rt_base;
    return ret_123;
    alg_hold_top = rh_475;
    Value ret_124 = alg_nil();
    alg_root_top = rt_base;
    return ret_124;
}

static Value m_parser_raisestatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_476 = alg_hold_top;
    Value v_keyword = alg_nil();
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    alg_hold_top = rh_476;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_476;
    (void)((v_keyword = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
    alg_hold_top = rh_476;
    (void)((v_value = alg_hold(alg_invoke(v_this, "Expression", NULL, 0))));
    alg_hold_top = rh_476;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after raised value.")}, 2)));
    alg_hold_top = rh_476;
    Value ret_125 = alg_hold(alg_new(k_raisestmt, (Value[]){v_keyword, v_value}, 2));
    alg_root_top = rt_base;
    return ret_125;
    alg_hold_top = rh_476;
    Value ret_126 = alg_nil();
    alg_root_top = rt_base;
    return ret_126;
}

static Value m_parser_trystatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_477 = alg_hold_top;
    Value v_statements = alg_nil();
    (void)v_statements;
    alg_root(&v_statements, 1);
    alg_hold_top = rh_477;
    Value v_handlers = alg_nil();
    (void)v_handlers;
    alg_root(&v_handlers, 1);
    alg_hold_top = rh_477;
    Value v_hashandlers = alg_nil();
    (void)v_hashandlers;
    alg_root(&v_hashandlers, 1);
    alg_hold_top = rh_477;
    Value v_variable = alg_nil();
    (void)v_variable;
    alg_root(&v_variable, 1);
    alg_hold_top = rh_477;
    Value v_thetype = alg_nil();
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    alg_hold_top = rh_477;
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_477;
    Value v_trailing = alg_nil();
    (void)v_trailing;
    alg_root(&v_trailing, 1);
    alg_hold_top = rh_477;
    Value v_exceptstmts = alg_nil();
    (void)v_exceptstmts;
    alg_root(&v_exceptstmts, 1);
    alg_hold_top = rh_477;
    (void)((v_statements = alg_hold(alg_list())));
    alg_hold_top = rh_477;
    {
        int32_t rh_478 = alg_hold_top;
        while ((alg_hold_top = rh_478, alg_truthy(alg_hold((or_44 = alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVexcept}, 1)))), !alg_truthy(or_44) ? or_44 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0))))))))) {
            alg_safe_point();
            (void)(alg_hold(alg_invoke(v_statements, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Statement", NULL, 0))}, 1)));
        }
    }
    alg_hold_top = rh_477;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVexcept, alg_literal("Expect 'except' after try block.")}, 2)));
    alg_hold_top = rh_477;
    (void)((v_handlers = alg_hold(alg_map())));
    alg_hold_top = rh_477;
    (void)((v_hashandlers = alg_bool(false)));
    alg_hold_top = rh_477;
    {
        int32_t rh_479 = alg_hold_top;
        while ((alg_hold_top = rh_479, alg_truthy(alg_hold(alg_invoke(v_this, "CheckWord", (Value[]){alg_literal("on")}, 1))))) {
            alg_safe_point();
            {
                int32_t rh_480 = alg_hold_top;
                (void)((v_hashandlers = alg_bool(true)));
                alg_hold_top = rh_480;
                (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
                alg_hold_top = rh_480;
                (void)((v_variable = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expected variable name.")}, 2))));
                alg_hold_top = rh_480;
                (void)((v_thetype = alg_widen(alg_nil(), "Token")));
                alg_hold_top = rh_480;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1)))) {
                    (void)((v_thetype = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expected type.")}, 2))));
                }
                alg_hold_top = rh_480;
                (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdo, alg_literal("Expected 'do'.")}, 2)));
                alg_hold_top = rh_480;
                (void)((v_key = alg_literal("default")));
                alg_hold_top = rh_480;
                if (alg_truthy(alg_hold(alg_not_equal(v_thetype, alg_nil())))) {
                    (void)((v_key = alg_hold(alg_str(alg_hold(alg_property(v_thetype, "Lexeme"))))));
                }
                alg_hold_top = rh_480;
                if (alg_truthy(alg_hold(alg_invoke(v_handlers, "Contains", (Value[]){v_key}, 1)))) {
                    {
                        int32_t rh_481 = alg_hold_top;
                        if (alg_truthy(alg_hold(alg_equal(v_thetype, alg_nil())))) {
                            alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_variable, alg_literal("A handler for any exception is already given.")}, 2)));
                        }
                        alg_hold_top = rh_481;
                        alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_thetype, alg_hold(alg_add(alg_hold(alg_add(alg_literal("Duplicate handler for '"), v_key)), alg_literal("'.")))}, 2)));
                        alg_hold_top = rh_481;
                    }
                }
                alg_hold_top = rh_480;
                (void)(alg_hold(alg_invoke(v_handlers, "Put", (Value[]){v_key, alg_hold(alg_new(k_excepthandler, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_variable, "Lexeme")))), alg_hold(alg_invoke(v_this, "Statement", NULL, 0))}, 2))}, 2)));
                alg_hold_top = rh_480;
            }
        }
    }
    alg_hold_top = rh_477;
    (void)((v_trailing = alg_hold(alg_invoke(v_this, "Peek", NULL, 0))));
    alg_hold_top = rh_477;
    (void)((v_exceptstmts = alg_hold(alg_list())));
    alg_hold_top = rh_477;
    {
        int32_t rh_482 = alg_hold_top;
        while ((alg_hold_top = rh_482, alg_truthy(alg_hold((or_45 = alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1)))), !alg_truthy(or_45) ? or_45 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0))))))))) {
            alg_safe_point();
            (void)(alg_hold(alg_invoke(v_exceptstmts, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Statement", NULL, 0))}, 1)));
        }
    }
    alg_hold_top = rh_477;
    if (alg_truthy(alg_hold((or_46 = alg_hold(alg_not(v_hashandlers)), alg_truthy(or_46) ? or_46 : alg_hold(alg_not(alg_hold(alg_property(v_exceptstmts, "IsEmpty")))))))) {
        {
            int32_t rh_483 = alg_hold_top;
            if (alg_truthy(alg_hold((or_47 = alg_hold(alg_not(alg_hold(alg_property(v_exceptstmts, "IsEmpty")))), !alg_truthy(or_47) ? or_47 : alg_hold(alg_invoke(v_handlers, "Contains", (Value[]){alg_literal("default")}, 1)))))) {
                alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_trailing, alg_literal("A handler for any exception is already given by an untyped 'on'.")}, 2)));
            }
            alg_hold_top = rh_483;
            (void)(alg_hold(alg_invoke(v_handlers, "Put", (Value[]){alg_literal("default"), alg_hold(alg_new(k_excepthandler, (Value[]){alg_literal("Any"), alg_hold(alg_new(k_blockstmt, (Value[]){v_exceptstmts}, 1))}, 2))}, 2)));
            alg_hold_top = rh_483;
        }
    }
    alg_hold_top = rh_477;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVend, alg_literal("Expect 'end' after except block.")}, 2)));
    alg_hold_top = rh_477;
    Value ret_127 = alg_hold(alg_new(k_trystmt, (Value[]){alg_hold(alg_new(k_blockstmt, (Value[]){v_statements}, 1)), v_handlers}, 2));
    alg_root_top = rt_base;
    return ret_127;
    alg_hold_top = rh_477;
    Value ret_128 = alg_nil();
    alg_root_top = rt_base;
    return ret_128;
}

static Value m_parser_vardeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_484 = alg_hold_top;
    Value ret_129 = alg_hold(alg_invoke(v_this, "VarDeclaration", (Value[]){alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect variable name.")}, 2))}, 1));
    alg_root_top = rt_base;
    return ret_129;
    alg_hold_top = rh_484;
    Value ret_130 = alg_nil();
    alg_root_top = rt_base;
    return ret_130;
}

static Value m_parser_vardeclaration_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_485 = alg_hold_top;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    alg_hold_top = rh_485;
    Value v_typename = alg_literal("");
    (void)v_typename;
    alg_root(&v_typename, 1);
    alg_hold_top = rh_485;
    Value v_generic = alg_literal("");
    (void)v_generic;
    alg_root(&v_generic, 1);
    alg_hold_top = rh_485;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1)))) {
        {
            int32_t rh_486 = alg_hold_top;
            (void)((v_typename = alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect type name.")}, 2)), "Lexeme"))}, 1))));
            alg_hold_top = rh_486;
            if (alg_truthy(alg_hold((or_48 = alg_hold(alg_invoke(v_this, "IsCollectionType", (Value[]){v_typename}, 1)), !alg_truthy(or_48) ? or_48 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))))) {
                (void)((v_generic = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect generic type.")}, 2)), "Lexeme"))))));
            }
            alg_hold_top = rh_486;
        }
    }
    alg_hold_top = rh_485;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVassign}, 1)))) {
        {
            int32_t rh_487 = alg_hold_top;
            (void)((v_initializer = alg_hold(alg_invoke(v_this, "Expression", NULL, 0))));
            alg_hold_top = rh_487;
        }
    }
    alg_hold_top = rh_485;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after variable declaration.")}, 2)));
    alg_hold_top = rh_485;
    Value v_thevar = alg_hold(alg_new(k_varstmt, (Value[]){v_name, v_initializer}, 2));
    (void)v_thevar;
    alg_root(&v_thevar, 1);
    alg_hold_top = rh_485;
    (void)(alg_hold(alg_set_property(v_thevar, "TypeName", v_typename)));
    alg_hold_top = rh_485;
    (void)(alg_hold(alg_set_property(v_thevar, "Generic", v_generic)));
    alg_hold_top = rh_485;
    Value ret_131 = v_thevar;
    alg_root_top = rt_base;
    return ret_131;
    alg_hold_top = rh_485;
    Value ret_132 = alg_nil();
    alg_root_top = rt_base;
    return ret_132;
}

static Value m_parser_expressionstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_488 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_488;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "Expression", NULL, 0))));
    alg_hold_top = rh_488;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after expression.")}, 2)));
    alg_hold_top = rh_488;
    Value ret_133 = alg_hold(alg_new(k_expressionstmt, (Value[]){v_theexpr}, 1));
    alg_root_top = rt_base;
    return ret_133;
    alg_hold_top = rh_488;
    Value ret_134 = alg_nil();
    alg_root_top = rt_base;
    return ret_134;
}

static Value m_parser_isextensiondeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_489 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "CheckWord", (Value[]){alg_literal("extension")}, 1)))))) {
        Value ret_135 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_135;
    }
    alg_hold_top = rh_489;
    Value ret_136 = alg_hold((or_49 = alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0)), "TypeOfToken")), e_tokentype_tokenVfunction)), alg_truthy(or_49) ? or_49 : alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0)), "TypeOfToken")), e_tokentype_tokenVprocedure))));
    alg_root_top = rt_base;
    return ret_136;
    alg_hold_top = rh_489;
    Value ret_137 = alg_nil();
    alg_root_top = rt_base;
    return ret_137;
}

static Value m_parser_extensiondeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_490 = alg_hold_top;
    Value v_word = alg_nil();
    (void)v_word;
    alg_root(&v_word, 1);
    alg_hold_top = rh_490;
    (void)((v_word = alg_hold(alg_invoke(v_this, "Advance", NULL, 0))));
    alg_hold_top = rh_490;
    if (alg_truthy(alg_hold(alg_greater(alg_property(v_this, "SubprogramDepth"), alg_int(0))))) {
        alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_word, alg_literal("'extension' applies only to a top-level subprogram.")}, 2)));
    }
    alg_hold_top = rh_490;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVprocedure}, 1)))) {
        Value ret_138 = alg_hold(alg_invoke(v_this, "ParseFunction", (Value[]){alg_literal("procedure"), alg_bool(true)}, 2));
        alg_root_top = rt_base;
        return ret_138;
    }
    alg_hold_top = rh_490;
    (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
    alg_hold_top = rh_490;
    Value ret_139 = alg_hold(alg_invoke(v_this, "ParseFunction", (Value[]){alg_literal("function"), alg_bool(true)}, 2));
    alg_root_top = rt_base;
    return ret_139;
    alg_hold_top = rh_490;
    Value ret_140 = alg_nil();
    alg_root_top = rt_base;
    return ret_140;
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
    int32_t rh_491 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_491;
    Value v_params = alg_nil();
    (void)v_params;
    alg_root(&v_params, 1);
    alg_hold_top = rh_491;
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    alg_hold_top = rh_491;
    (void)((v_name = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expect "), v_kind)), alg_literal(" name.")))}, 2))));
    alg_hold_top = rh_491;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVleftVparen, alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expect '(' after "), v_kind)), alg_literal(" name.")))}, 2)));
    alg_hold_top = rh_491;
    (void)((v_params = alg_hold(alg_list())));
    alg_hold_top = rh_491;
    Value v_paramtypes = alg_hold(alg_list());
    (void)v_paramtypes;
    alg_root(&v_paramtypes, 1);
    alg_hold_top = rh_491;
    Value v_paramgenerics = alg_hold(alg_list());
    (void)v_paramgenerics;
    alg_root(&v_paramgenerics, 1);
    alg_hold_top = rh_491;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVrightVparen}, 1)))))) {
        {
            int32_t rh_492 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_params, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect parameter name.")}, 2))}, 1)));
            alg_hold_top = rh_492;
            (void)(alg_hold(alg_invoke(v_paramtypes, "Add", (Value[]){alg_hold(alg_invoke(v_this, "ParameterType", NULL, 0))}, 1)));
            alg_hold_top = rh_492;
            (void)(alg_hold(alg_invoke(v_paramgenerics, "Add", (Value[]){alg_property(v_this, "LastGeneric")}, 1)));
            alg_hold_top = rh_492;
            {
                int32_t rh_493 = alg_hold_top;
                while ((alg_hold_top = rh_493, alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))))) {
                    alg_safe_point();
                    {
                        int32_t rh_494 = alg_hold_top;
                        if (alg_truthy(alg_hold(alg_greater_equal(alg_hold(alg_property(v_params, "Length")), alg_int(255))))) {
                            {
                                int32_t rh_495 = alg_hold_top;
                                alg_raise(alg_literal("Can't have more than 255 parameters."));
                                alg_hold_top = rh_495;
                            }
                        }
                        alg_hold_top = rh_494;
                        (void)(alg_hold(alg_invoke(v_params, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect parameter name.")}, 2))}, 1)));
                        alg_hold_top = rh_494;
                        (void)(alg_hold(alg_invoke(v_paramtypes, "Add", (Value[]){alg_hold(alg_invoke(v_this, "ParameterType", NULL, 0))}, 1)));
                        alg_hold_top = rh_494;
                        (void)(alg_hold(alg_invoke(v_paramgenerics, "Add", (Value[]){alg_property(v_this, "LastGeneric")}, 1)));
                        alg_hold_top = rh_494;
                    }
                }
            }
            alg_hold_top = rh_492;
        }
    }
    alg_hold_top = rh_491;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_literal("Expect ')' after parameters.")}, 2)));
    alg_hold_top = rh_491;
    if (alg_truthy(v_isextension)) {
        {
            int32_t rh_496 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_params, "Length")), alg_int(0))))) {
                alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_name, alg_literal("An extension must declare a receiver.")}, 2)));
            }
            alg_hold_top = rh_496;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_str(alg_hold(alg_subscript_get(v_paramtypes, alg_int(0))))), alg_literal(""))))) {
                alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){alg_hold(alg_subscript_get(v_params, alg_int(0))), alg_literal("An extension's receiver must have a written type.")}, 2)));
            }
            alg_hold_top = rh_496;
        }
    }
    alg_hold_top = rh_491;
    Value v_returntype = alg_literal("");
    (void)v_returntype;
    alg_root(&v_returntype, 1);
    alg_hold_top = rh_491;
    Value v_returngeneric = alg_literal("");
    (void)v_returngeneric;
    alg_root(&v_returngeneric, 1);
    alg_hold_top = rh_491;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1)))) {
        (void)((v_returntype = alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect return type.")}, 2)), "Lexeme"))}, 1))));
    }
    alg_hold_top = rh_491;
    if (alg_truthy(alg_hold((or_50 = alg_hold(alg_invoke(v_this, "IsCollectionType", (Value[]){v_returntype}, 1)), !alg_truthy(or_50) ? or_50 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))))) {
        (void)((v_returngeneric = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect generic type.")}, 2)), "Lexeme"))))));
    }
    alg_hold_top = rh_491;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expect ';' after "), v_kind)), alg_literal(" signature.")))}, 2)));
    alg_hold_top = rh_491;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVexternal}, 1)))) {
        {
            int32_t rt_497 = alg_root_top;
            int32_t rh_498 = alg_hold_top;
            Value v_symbol = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVstring, alg_literal("Expect a symbol name after 'external'.")}, 2));
            (void)v_symbol;
            alg_root(&v_symbol, 1);
            alg_hold_top = rh_498;
            Value v_inlibrary = alg_literal("");
            (void)v_inlibrary;
            alg_root(&v_inlibrary, 1);
            alg_hold_top = rh_498;
            if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVin}, 1)))) {
                (void)((v_inlibrary = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVstring, alg_literal("Expect a library name after 'in'.")}, 2)), "Literal"))))));
            }
            alg_hold_top = rh_498;
            (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after an external declaration.")}, 2)));
            alg_hold_top = rh_498;
            Value v_foreign = alg_hold(alg_new(k_functionstmt, (Value[]){v_name, v_params, alg_hold(alg_list())}, 3));
            (void)v_foreign;
            alg_root(&v_foreign, 1);
            alg_hold_top = rh_498;
            (void)(alg_hold(alg_set_property(v_foreign, "ReturnType", v_returntype)));
            alg_hold_top = rh_498;
            (void)(alg_hold(alg_set_property(v_foreign, "ReturnGeneric", v_returngeneric)));
            alg_hold_top = rh_498;
            (void)(alg_hold(alg_set_property(v_foreign, "ParamTypes", v_paramtypes)));
            alg_hold_top = rh_498;
            (void)(alg_hold(alg_set_property(v_foreign, "ParamGenerics", v_paramgenerics)));
            alg_hold_top = rh_498;
            (void)(alg_hold(alg_set_property(v_foreign, "Symbol", alg_hold(alg_str(alg_hold(alg_property(v_symbol, "Literal")))))));
            alg_hold_top = rh_498;
            (void)(alg_hold(alg_set_property(v_foreign, "Library", v_inlibrary)));
            alg_hold_top = rh_498;
            (void)(alg_hold(alg_set_property(v_foreign, "IsExtension", v_isextension)));
            alg_hold_top = rh_498;
            Value ret_141 = v_foreign;
            alg_root_top = rt_base;
            return ret_141;
            alg_hold_top = rh_498;
            alg_root_top = rt_497;
        }
    }
    alg_hold_top = rh_491;
    (void)((v_body = alg_hold(alg_list())));
    alg_hold_top = rh_491;
    (void)(alg_hold(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_body}, 1)));
    alg_hold_top = rh_491;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expect 'begin' before "), v_kind)), alg_literal(" body.")))}, 2)));
    alg_hold_top = rh_491;
    Value v_wasinprocedure = alg_property(v_this, "InProcedure");
    (void)v_wasinprocedure;
    alg_root(&v_wasinprocedure, 1);
    alg_hold_top = rh_491;
    (void)(alg_set_property(v_this, "InProcedure", alg_hold(alg_equal(v_kind, alg_literal("procedure")))));
    alg_hold_top = rh_491;
    (void)(alg_set_property(v_this, "SubprogramDepth", alg_hold(alg_add(alg_property(v_this, "SubprogramDepth"), alg_int(1)))));
    alg_hold_top = rh_491;
    Value v_rest = alg_hold(alg_invoke(v_this, "Block", NULL, 0));
    (void)v_rest;
    alg_root(&v_rest, 1);
    alg_hold_top = rh_491;
    (void)(alg_set_property(v_this, "SubprogramDepth", alg_hold(alg_subtract(alg_property(v_this, "SubprogramDepth"), alg_int(1)))));
    alg_hold_top = rh_491;
    (void)(alg_set_property(v_this, "InProcedure", v_wasinprocedure));
    alg_hold_top = rh_491;
    {
        int32_t rt_499 = alg_root_top;
        Value loop_142 = alg_iterable(v_rest);
        (void)loop_142;
        alg_root(&loop_142, 1);
        for (int32_t at_142 = 0; at_142 < alg_iterable_count(loop_142); at_142++) {
            alg_safe_point();
            int32_t rt_500 = alg_root_top;
            Value v_each = alg_iterable_at(loop_142, at_142);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_hold(alg_invoke(v_body, "Add", (Value[]){v_each}, 1)));
            alg_root_top = rt_500;
        }
        alg_root_top = rt_499;
    }
    alg_hold_top = rh_491;
    Value v_thefunction = alg_hold(alg_new(k_functionstmt, (Value[]){v_name, v_params, v_body}, 3));
    (void)v_thefunction;
    alg_root(&v_thefunction, 1);
    alg_hold_top = rh_491;
    (void)(alg_hold(alg_set_property(v_thefunction, "ReturnType", v_returntype)));
    alg_hold_top = rh_491;
    (void)(alg_hold(alg_set_property(v_thefunction, "ReturnGeneric", v_returngeneric)));
    alg_hold_top = rh_491;
    (void)(alg_hold(alg_set_property(v_thefunction, "ParamTypes", v_paramtypes)));
    alg_hold_top = rh_491;
    (void)(alg_hold(alg_set_property(v_thefunction, "ParamGenerics", v_paramgenerics)));
    alg_hold_top = rh_491;
    (void)(alg_hold(alg_set_property(v_thefunction, "IsExtension", v_isextension)));
    alg_hold_top = rh_491;
    Value ret_143 = v_thefunction;
    alg_root_top = rt_base;
    return ret_143;
    alg_hold_top = rh_491;
    Value ret_144 = alg_nil();
    alg_root_top = rt_base;
    return ret_144;
}

static Value m_parser_parametertype_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_501 = alg_hold_top;
    (void)(alg_set_property(v_this, "LastGeneric", alg_literal("")));
    alg_hold_top = rh_501;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1)))))) {
        Value ret_145 = alg_literal("");
        alg_root_top = rt_base;
        return ret_145;
    }
    alg_hold_top = rh_501;
    Value v_typename = alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect type name.")}, 2)), "Lexeme"))}, 1));
    (void)v_typename;
    alg_root(&v_typename, 1);
    alg_hold_top = rh_501;
    if (alg_truthy(alg_hold((or_51 = alg_hold(alg_invoke(v_this, "IsCollectionType", (Value[]){v_typename}, 1)), !alg_truthy(or_51) ? or_51 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))))) {
        (void)(alg_set_property(v_this, "LastGeneric", alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect generic type.")}, 2)), "Lexeme"))))));
    }
    alg_hold_top = rh_501;
    Value ret_146 = v_typename;
    alg_root_top = rt_base;
    return ret_146;
    alg_hold_top = rh_501;
    Value ret_147 = alg_nil();
    alg_root_top = rt_base;
    return ret_147;
}

static Value m_parser_block_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_502 = alg_hold_top;
    Value v_statements = alg_nil();
    (void)v_statements;
    alg_root(&v_statements, 1);
    alg_hold_top = rh_502;
    (void)((v_statements = alg_hold(alg_list())));
    alg_hold_top = rh_502;
    {
        int32_t rh_503 = alg_hold_top;
        while ((alg_hold_top = rh_503, alg_truthy(alg_hold((or_52 = alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1)))), !alg_truthy(or_52) ? or_52 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0))))))))) {
            alg_safe_point();
            {
                int32_t rh_504 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_statements, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Declaration", NULL, 0))}, 1)));
                alg_hold_top = rh_504;
            }
        }
    }
    alg_hold_top = rh_502;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVend, alg_literal("Expect 'end' after block.")}, 2)));
    alg_hold_top = rh_502;
    Value ret_148 = v_statements;
    alg_root_top = rt_base;
    return ret_148;
    alg_hold_top = rh_502;
    Value ret_149 = alg_nil();
    alg_root_top = rt_base;
    return ret_149;
}

static Value m_parser_assignment_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_505 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_505;
    Value v_equals = alg_nil();
    (void)v_equals;
    alg_root(&v_equals, 1);
    alg_hold_top = rh_505;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_505;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "ParseOr", NULL, 0))));
    alg_hold_top = rh_505;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVassign}, 1)))) {
        {
            int32_t rh_506 = alg_hold_top;
            (void)((v_equals = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
            alg_hold_top = rh_506;
            (void)((v_value = alg_hold(alg_invoke(v_this, "Assignment", NULL, 0))));
            alg_hold_top = rh_506;
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_theexpr, "ClassName")), alg_literal("VariableExpr"))))) {
                Value ret_150 = alg_hold(alg_new(k_assignexpr, (Value[]){alg_hold(alg_property(v_theexpr, "Name")), v_value}, 2));
                alg_root_top = rt_base;
                return ret_150;
            } else {
                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_theexpr, "ClassName")), alg_literal("GetExpr"))))) {
                    Value ret_151 = alg_hold(alg_new(k_setexpr, (Value[]){alg_hold(alg_property(v_theexpr, "Obj")), alg_hold(alg_property(v_theexpr, "Name")), v_value}, 3));
                    alg_root_top = rt_base;
                    return ret_151;
                } else {
                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_theexpr, "ClassName")), alg_literal("SubscriptExpr"))))) {
                        Value ret_152 = alg_hold(alg_new(k_setsubscriptexpr, (Value[]){alg_hold(alg_property(v_theexpr, "Obj")), alg_hold(alg_property(v_theexpr, "Index")), v_value, alg_hold(alg_property(v_theexpr, "Bracket"))}, 4));
                        alg_root_top = rt_base;
                        return ret_152;
                    }
                }
            }
            alg_hold_top = rh_506;
            alg_raise(alg_literal("Invalid assignment target."));
            alg_hold_top = rh_506;
        }
    }
    alg_hold_top = rh_505;
    Value ret_153 = v_theexpr;
    alg_root_top = rt_base;
    return ret_153;
    alg_hold_top = rh_505;
    Value ret_154 = alg_nil();
    alg_root_top = rt_base;
    return ret_154;
}

static Value m_parser_parseor_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_507 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_507;
    Value v_op = alg_nil();
    (void)v_op;
    alg_root(&v_op, 1);
    alg_hold_top = rh_507;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_507;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "ParseAnd", NULL, 0))));
    alg_hold_top = rh_507;
    {
        int32_t rh_508 = alg_hold_top;
        while ((alg_hold_top = rh_508, alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVor}, 1))))) {
            alg_safe_point();
            {
                int32_t rh_509 = alg_hold_top;
                (void)((v_op = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
                alg_hold_top = rh_509;
                (void)((v_right = alg_hold(alg_invoke(v_this, "ParseAnd", NULL, 0))));
                alg_hold_top = rh_509;
                (void)((v_theexpr = alg_widen(alg_hold(alg_new(k_logicalexpr, (Value[]){v_theexpr, v_op, v_right}, 3)), "Expr")));
                alg_hold_top = rh_509;
            }
        }
    }
    alg_hold_top = rh_507;
    Value ret_155 = v_theexpr;
    alg_root_top = rt_base;
    return ret_155;
    alg_hold_top = rh_507;
    Value ret_156 = alg_nil();
    alg_root_top = rt_base;
    return ret_156;
}

static Value m_parser_parseand_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_510 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_510;
    Value v_op = alg_nil();
    (void)v_op;
    alg_root(&v_op, 1);
    alg_hold_top = rh_510;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_510;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "Equality", NULL, 0))));
    alg_hold_top = rh_510;
    {
        int32_t rh_511 = alg_hold_top;
        while ((alg_hold_top = rh_511, alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVand}, 1))))) {
            alg_safe_point();
            {
                int32_t rh_512 = alg_hold_top;
                (void)((v_op = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
                alg_hold_top = rh_512;
                (void)((v_right = alg_hold(alg_invoke(v_this, "Equality", NULL, 0))));
                alg_hold_top = rh_512;
                (void)((v_theexpr = alg_widen(alg_hold(alg_new(k_logicalexpr, (Value[]){v_theexpr, v_op, v_right}, 3)), "Expr")));
                alg_hold_top = rh_512;
            }
        }
    }
    alg_hold_top = rh_510;
    Value ret_157 = v_theexpr;
    alg_root_top = rt_base;
    return ret_157;
    alg_hold_top = rh_510;
    Value ret_158 = alg_nil();
    alg_root_top = rt_base;
    return ret_158;
}

static Value m_parser_expression_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_513 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_513;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "Assignment", NULL, 0))));
    alg_hold_top = rh_513;
    Value ret_159 = v_theexpr;
    alg_root_top = rt_base;
    return ret_159;
    alg_hold_top = rh_513;
    Value ret_160 = alg_nil();
    alg_root_top = rt_base;
    return ret_160;
}

static Value m_parser_declaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_514 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsTestBlock", NULL, 0)))) {
        Value ret_161 = alg_hold(alg_invoke(v_this, "TestDeclaration", NULL, 0));
        alg_root_top = rt_base;
        return ret_161;
    }
    alg_hold_top = rh_514;
    Value ret_162 = alg_hold(alg_invoke(v_this, "Statement", NULL, 0));
    alg_root_top = rt_base;
    return ret_162;
    alg_hold_top = rh_514;
    Value ret_163 = alg_nil();
    alg_root_top = rt_base;
    return ret_163;
}

static Value m_parser_istestblock_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_515 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)))))) {
        Value ret_164 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_164;
    }
    alg_hold_top = rh_515;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), "Lexeme")), alg_literal("test"))))) {
        Value ret_165 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_165;
    }
    alg_hold_top = rh_515;
    Value ret_166 = alg_hold((or_53 = alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0)), "TypeOfToken")), e_tokentype_tokenVstring)), alg_truthy(or_53) ? or_53 : alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0)), "TypeOfToken")), e_tokentype_tokenVchar))));
    alg_root_top = rt_base;
    return ret_166;
    alg_hold_top = rh_515;
    Value ret_167 = alg_nil();
    alg_root_top = rt_base;
    return ret_167;
}

static Value m_parser_testdeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_516 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_516;
    Value v_body = alg_nil();
    (void)v_body;
    alg_root(&v_body, 1);
    alg_hold_top = rh_516;
    (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
    alg_hold_top = rh_516;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVchar}, 1)))) {
        (void)((v_name = alg_hold(alg_invoke(v_this, "Advance", NULL, 0))));
    } else {
        (void)((v_name = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVstring, alg_literal("Expect a test name.")}, 2))));
    }
    alg_hold_top = rh_516;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after test name.")}, 2)));
    alg_hold_top = rh_516;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_literal("Expect 'begin' before test body.")}, 2)));
    alg_hold_top = rh_516;
    (void)((v_body = alg_hold(alg_invoke(v_this, "Block", NULL, 0))));
    alg_hold_top = rh_516;
    Value ret_168 = alg_hold(alg_new(k_functionstmt, (Value[]){v_name, alg_hold(alg_list()), v_body}, 3));
    alg_root_top = rt_base;
    return ret_168;
    alg_hold_top = rh_516;
    Value ret_169 = alg_nil();
    alg_root_top = rt_base;
    return ret_169;
}

static Value m_parser_enumdeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_517 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_517;
    Value v_members = alg_nil();
    (void)v_members;
    alg_root(&v_members, 1);
    alg_hold_top = rh_517;
    (void)((v_name = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect enum name.")}, 2))));
    alg_hold_top = rh_517;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVequal, alg_literal("Expect '=' after enum declaration.")}, 2)));
    alg_hold_top = rh_517;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVleftVparen}, 1)))))) {
        Value ret_170 = alg_hold(alg_invoke(v_this, "SubrangeDeclaration", (Value[]){v_name}, 1));
        alg_root_top = rt_base;
        return ret_170;
    }
    alg_hold_top = rh_517;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVleftVparen, alg_literal("Expect '(' before enum members.")}, 2)));
    alg_hold_top = rh_517;
    (void)((v_members = alg_hold(alg_list())));
    alg_hold_top = rh_517;
    (void)(alg_hold(alg_invoke(v_members, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect member name.")}, 2))}, 1)));
    alg_hold_top = rh_517;
    {
        int32_t rh_518 = alg_hold_top;
        while ((alg_hold_top = rh_518, alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))))) {
            alg_safe_point();
            (void)(alg_hold(alg_invoke(v_members, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect member name.")}, 2))}, 1)));
        }
    }
    alg_hold_top = rh_517;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_literal("Expect ')' after enum members.")}, 2)));
    alg_hold_top = rh_517;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after enum declaration.")}, 2)));
    alg_hold_top = rh_517;
    Value ret_171 = alg_hold(alg_new(k_enumstmt, (Value[]){v_name, v_members}, 2));
    alg_root_top = rt_base;
    return ret_171;
    alg_hold_top = rh_517;
    Value ret_172 = alg_nil();
    alg_root_top = rt_base;
    return ret_172;
}

static Value m_parser_subrangedeclaration_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_519 = alg_hold_top;
    Value v_low = alg_nil();
    (void)v_low;
    alg_root(&v_low, 1);
    alg_hold_top = rh_519;
    Value v_high = alg_nil();
    (void)v_high;
    alg_root(&v_high, 1);
    alg_hold_top = rh_519;
    (void)((v_low = alg_hold(alg_invoke(v_this, "SubrangeBound", NULL, 0))));
    alg_hold_top = rh_519;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdotVdot, alg_literal("Expect '..' between subrange bounds.")}, 2)));
    alg_hold_top = rh_519;
    (void)((v_high = alg_hold(alg_invoke(v_this, "SubrangeBound", NULL, 0))));
    alg_hold_top = rh_519;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_literal("Expect ';' after subrange declaration.")}, 2)));
    alg_hold_top = rh_519;
    if (alg_truthy(alg_hold(alg_greater(v_low, v_high)))) {
        (void)(alg_hold(alg_invoke(v_this, "Error", (Value[]){v_name, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("A subrange must not be empty: "), alg_hold(alg_str(v_low)))), alg_literal(" is above "))), alg_hold(alg_str(v_high)))), alg_char_value(46)))}, 2)));
    }
    alg_hold_top = rh_519;
    Value ret_173 = alg_hold(alg_new(k_subrangestmt, (Value[]){v_name, v_low, v_high}, 3));
    alg_root_top = rt_base;
    return ret_173;
    alg_hold_top = rh_519;
    Value ret_174 = alg_nil();
    alg_root_top = rt_base;
    return ret_174;
}

static Value m_parser_subrangebound_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_520 = alg_hold_top;
    Value v_negative = alg_nil();
    (void)v_negative;
    alg_root(&v_negative, 1);
    alg_hold_top = rh_520;
    (void)((v_negative = alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVminus}, 1))));
    alg_hold_top = rh_520;
    Value v_bound = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVinteger, alg_literal("Expect an integer bound.")}, 2));
    (void)v_bound;
    alg_root(&v_bound, 1);
    alg_hold_top = rh_520;
    if (alg_truthy(v_negative)) {
        Value ret_175 = alg_hold(alg_subtract(alg_int(0), (alg_hold(alg_cast_kind(alg_property(v_bound, "Literal"), ALG_KIND_INTEGER, "Integer")))));
        alg_root_top = rt_base;
        return ret_175;
    }
    alg_hold_top = rh_520;
    Value ret_176 = alg_hold(alg_cast_kind(alg_property(v_bound, "Literal"), ALG_KIND_INTEGER, "Integer"));
    alg_root_top = rt_base;
    return ret_176;
    alg_hold_top = rh_520;
    Value ret_177 = alg_nil();
    alg_root_top = rt_base;
    return ret_177;
}

static Value m_parser_classdeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_521 = alg_hold_top;
    Value ret_178 = alg_hold(alg_invoke(v_this, "ClassDeclaration", (Value[]){alg_literal("class")}, 1));
    alg_root_top = rt_base;
    return ret_178;
    alg_hold_top = rh_521;
    Value ret_179 = alg_nil();
    alg_root_top = rt_base;
    return ret_179;
}

static Value m_parser_classdeclaration_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_kind = alg_widen(args[0], "String");
    (void)v_kind;
    alg_root(&v_kind, 1);
    int32_t rh_522 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_522;
    Value v_methods = alg_nil();
    (void)v_methods;
    alg_root(&v_methods, 1);
    alg_hold_top = rh_522;
    Value v_fields = alg_nil();
    (void)v_fields;
    alg_root(&v_fields, 1);
    alg_hold_top = rh_522;
    Value v_superclass = alg_nil();
    (void)v_superclass;
    alg_root(&v_superclass, 1);
    alg_hold_top = rh_522;
    (void)((v_name = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expect "), v_kind)), alg_literal(" name.")))}, 2))));
    alg_hold_top = rh_522;
    (void)((v_superclass = alg_cast_class(alg_nil(), k_variableexpr, "VariableExpr")));
    alg_hold_top = rh_522;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVparen}, 1)))) {
        {
            int32_t rh_523 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect superclass name.")}, 2)));
            alg_hold_top = rh_523;
            (void)((v_superclass = alg_hold(alg_new(k_variableexpr, (Value[]){alg_hold(alg_invoke(v_this, "Previous", NULL, 0))}, 1))));
            alg_hold_top = rh_523;
            (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_literal("Expect ')' after superclass name.")}, 2)));
            alg_hold_top = rh_523;
        }
    }
    alg_hold_top = rh_522;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expect ';' after "), v_kind)), alg_literal(" declaration.")))}, 2)));
    alg_hold_top = rh_522;
    (void)(alg_set_property(v_this, "ClassPrivates", alg_hold(alg_list())));
    alg_hold_top = rh_522;
    (void)(alg_set_property(v_this, "InPrivateSection", alg_bool(false)));
    alg_hold_top = rh_522;
    (void)((v_fields = alg_hold(alg_list())));
    alg_hold_top = rh_522;
    Value v_section = alg_hold(alg_list());
    (void)v_section;
    alg_root(&v_section, 1);
    alg_hold_top = rh_522;
    (void)(alg_hold(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_section, alg_bool(true)}, 2)));
    alg_hold_top = rh_522;
    {
        int32_t rt_524 = alg_root_top;
        Value loop_180 = alg_iterable(v_section);
        (void)loop_180;
        alg_root(&loop_180, 1);
        for (int32_t at_180 = 0; at_180 < alg_iterable_count(loop_180); at_180++) {
            alg_safe_point();
            int32_t rt_525 = alg_root_top;
            Value v_each = alg_iterable_at(loop_180, at_180);
            (void)v_each;
            alg_root(&v_each, 1);
            {
                int32_t rh_526 = alg_hold_top;
                if (alg_truthy(alg_is_class(v_each, k_vargroupstmt))) {
                    {
                        int32_t rh_527 = alg_hold_top;
                        {
                            int32_t rt_528 = alg_root_top;
                            Value loop_181 = alg_iterable(alg_hold(alg_property(v_each, "Names")));
                            (void)loop_181;
                            alg_root(&loop_181, 1);
                            for (int32_t at_181 = 0; at_181 < alg_iterable_count(loop_181); at_181++) {
                                alg_safe_point();
                                int32_t rt_529 = alg_root_top;
                                Value v_thename = alg_iterable_at(loop_181, at_181);
                                (void)v_thename;
                                alg_root(&v_thename, 1);
                                {
                                    int32_t rt_530 = alg_root_top;
                                    int32_t rh_531 = alg_hold_top;
                                    Value v_field = alg_hold(alg_new(k_varstmt, (Value[]){v_thename, alg_hold(alg_property(v_each, "Initializer"))}, 2));
                                    (void)v_field;
                                    alg_root(&v_field, 1);
                                    alg_hold_top = rh_531;
                                    (void)(alg_hold(alg_set_property(v_field, "TypeName", alg_widen(alg_hold(alg_property(v_each, "TypeName")), "String"))));
                                    alg_hold_top = rh_531;
                                    (void)(alg_hold(alg_set_property(v_field, "Generic", alg_widen(alg_hold(alg_property(v_each, "Generic")), "String"))));
                                    alg_hold_top = rh_531;
                                    (void)(alg_hold(alg_invoke(v_fields, "Add", (Value[]){v_field}, 1)));
                                    alg_hold_top = rh_531;
                                    alg_root_top = rt_530;
                                }
                                alg_root_top = rt_529;
                            }
                            alg_root_top = rt_528;
                        }
                        alg_hold_top = rh_527;
                    }
                } else {
                    (void)(alg_hold(alg_invoke(v_fields, "Add", (Value[]){v_each}, 1)));
                }
                alg_hold_top = rh_526;
            }
            alg_root_top = rt_525;
        }
        alg_root_top = rt_524;
    }
    alg_hold_top = rh_522;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expect 'begin' before "), v_kind)), alg_literal(" body.")))}, 2)));
    alg_hold_top = rh_522;
    (void)(alg_set_property(v_this, "InPrivateSection", alg_bool(false)));
    alg_hold_top = rh_522;
    (void)((v_methods = alg_hold(alg_list())));
    alg_hold_top = rh_522;
    {
        int32_t rh_532 = alg_hold_top;
        while ((alg_hold_top = rh_532, alg_truthy(alg_hold((or_54 = alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1)))), !alg_truthy(or_54) ? or_54 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0))))))))) {
            alg_safe_point();
            {
                int32_t rt_533 = alg_root_top;
                int32_t rh_534 = alg_hold_top;
                {
                    int32_t rh_535 = alg_hold_top;
                    while ((alg_hold_top = rh_535, alg_truthy(alg_hold(alg_invoke(v_this, "MatchVisibility", NULL, 0))))) {
                        alg_safe_point();
                        {
                            int32_t rh_536 = alg_hold_top;
                        }
                    }
                }
                alg_hold_top = rh_534;
                if (alg_truthy(alg_hold((or_55 = alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1)), alg_truthy(or_55) ? or_55 : alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0)))))) {
                    break;
                }
                alg_hold_top = rh_534;
                Value v_method = alg_nil();
                (void)v_method;
                alg_root(&v_method, 1);
                alg_hold_top = rh_534;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "CheckWord", (Value[]){alg_literal("extension")}, 1)))) {
                    alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_literal("'extension' applies only to a top-level subprogram.")}, 2)));
                }
                alg_hold_top = rh_534;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVconstructor}, 1)))) {
                    (void)((v_method = alg_hold(alg_invoke(v_this, "ParseFunction", (Value[]){alg_literal("constructor"), alg_bool(false)}, 2))));
                } else {
                    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVprocedure}, 1)))) {
                        (void)((v_method = alg_hold(alg_invoke(v_this, "ParseFunction", (Value[]){alg_literal("procedure"), alg_bool(false)}, 2))));
                    } else {
                        if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVproperty}, 1)))) {
                            (void)((v_method = alg_hold(alg_invoke(v_this, "ParseProperty", NULL, 0))));
                        } else {
                            if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVoperator}, 1)))) {
                                (void)((v_method = alg_hold(alg_invoke(v_this, "ParseOperator", NULL, 0))));
                            } else {
                                {
                                    int32_t rh_537 = alg_hold_top;
                                    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVfunction, alg_literal("Expect 'function', 'procedure' or 'constructor' in class body.")}, 2)));
                                    alg_hold_top = rh_537;
                                    (void)((v_method = alg_hold(alg_invoke(v_this, "ParseFunction", (Value[]){alg_literal("method"), alg_bool(false)}, 2))));
                                    alg_hold_top = rh_537;
                                }
                            }
                        }
                    }
                }
                alg_hold_top = rh_534;
                if (alg_truthy(alg_property(v_this, "InPrivateSection"))) {
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "ClassPrivates"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_method, "Name")), "Lexeme"))))}, 1)));
                }
                alg_hold_top = rh_534;
                (void)(alg_hold(alg_invoke(v_methods, "Add", (Value[]){v_method}, 1)));
                alg_hold_top = rh_534;
                alg_root_top = rt_533;
            }
        }
    }
    alg_hold_top = rh_522;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVend, alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expect 'end' after "), v_kind)), alg_literal(" body.")))}, 2)));
    alg_hold_top = rh_522;
    if (alg_truthy(alg_hold(alg_equal(v_kind, alg_literal("object"))))) {
        {
            int32_t rt_538 = alg_root_top;
            int32_t rh_539 = alg_hold_top;
            Value v_theobject = alg_hold(alg_new(k_objectstmt, (Value[]){v_name, v_superclass, v_methods, v_fields}, 4));
            (void)v_theobject;
            alg_root(&v_theobject, 1);
            alg_hold_top = rh_539;
            (void)(alg_hold(alg_set_property(v_theobject, "PrivateMembers", alg_property(v_this, "ClassPrivates"))));
            alg_hold_top = rh_539;
            Value ret_182 = v_theobject;
            alg_root_top = rt_base;
            return ret_182;
            alg_hold_top = rh_539;
            alg_root_top = rt_538;
        }
    }
    alg_hold_top = rh_522;
    Value v_theclass = alg_hold(alg_new(k_classstmt, (Value[]){v_name, v_superclass, v_methods, v_fields}, 4));
    (void)v_theclass;
    alg_root(&v_theclass, 1);
    alg_hold_top = rh_522;
    (void)(alg_hold(alg_set_property(v_theclass, "PrivateMembers", alg_property(v_this, "ClassPrivates"))));
    alg_hold_top = rh_522;
    Value ret_183 = v_theclass;
    alg_root_top = rt_base;
    return ret_183;
    alg_hold_top = rh_522;
    Value ret_184 = alg_nil();
    alg_root_top = rt_base;
    return ret_184;
}

static Value m_parser_equality_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_540 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_540;
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    alg_hold_top = rh_540;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_540;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "Comparison", NULL, 0))));
    alg_hold_top = rh_540;
    {
        int32_t rh_541 = alg_hold_top;
        while ((alg_hold_top = rh_541, alg_truthy(alg_hold((or_56 = alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVnotVequal}, 1)), alg_truthy(or_56) ? or_56 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVequal}, 1))))))) {
            alg_safe_point();
            {
                int32_t rh_542 = alg_hold_top;
                (void)((v_theoperator = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
                alg_hold_top = rh_542;
                (void)((v_right = alg_hold(alg_invoke(v_this, "Comparison", NULL, 0))));
                alg_hold_top = rh_542;
                (void)((v_theexpr = alg_widen(alg_hold(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3)), "Expr")));
                alg_hold_top = rh_542;
            }
        }
    }
    alg_hold_top = rh_540;
    Value ret_185 = v_theexpr;
    alg_root_top = rt_base;
    return ret_185;
    alg_hold_top = rh_540;
    Value ret_186 = alg_nil();
    alg_root_top = rt_base;
    return ret_186;
}

static Value m_parser_comparison_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_543 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_543;
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    alg_hold_top = rh_543;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_543;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "BitOr", NULL, 0))));
    alg_hold_top = rh_543;
    {
        int32_t rh_544 = alg_hold_top;
        while ((alg_hold_top = rh_544, alg_truthy(alg_bool(true)))) {
            alg_safe_point();
            {
                int32_t rh_545 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVis}, 1)))) {
                    {
                        int32_t rh_546 = alg_hold_top;
                        (void)((v_theexpr = alg_widen(alg_hold(alg_new(k_isexpr, (Value[]){v_theexpr, alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect type name after 'is'.")}, 2))}, 2)), "Expr")));
                        alg_hold_top = rh_546;
                    }
                } else {
                    if (alg_truthy(alg_hold((or_60 = alg_hold((or_59 = alg_hold((or_58 = alg_hold((or_57 = alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVgreater}, 1)), alg_truthy(or_57) ? or_57 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVgreaterVequal}, 1)))), alg_truthy(or_58) ? or_58 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVless}, 1)))), alg_truthy(or_59) ? or_59 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVlessVequal}, 1)))), alg_truthy(or_60) ? or_60 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVin}, 1)))))) {
                        {
                            int32_t rh_547 = alg_hold_top;
                            (void)((v_theoperator = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
                            alg_hold_top = rh_547;
                            (void)((v_right = alg_hold(alg_invoke(v_this, "BitOr", NULL, 0))));
                            alg_hold_top = rh_547;
                            (void)((v_theexpr = alg_widen(alg_hold(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3)), "Expr")));
                            alg_hold_top = rh_547;
                        }
                    } else {
                        Value ret_187 = v_theexpr;
                        alg_root_top = rt_base;
                        return ret_187;
                    }
                }
                alg_hold_top = rh_545;
            }
        }
    }
    alg_hold_top = rh_543;
    Value ret_188 = v_theexpr;
    alg_root_top = rt_base;
    return ret_188;
    alg_hold_top = rh_543;
    Value ret_189 = alg_nil();
    alg_root_top = rt_base;
    return ret_189;
}

static Value m_parser_bitor_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_548 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_548;
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    alg_hold_top = rh_548;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_548;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "BitXor", NULL, 0))));
    alg_hold_top = rh_548;
    {
        int32_t rh_549 = alg_hold_top;
        while ((alg_hold_top = rh_549, alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVpipe}, 1))))) {
            alg_safe_point();
            {
                int32_t rh_550 = alg_hold_top;
                (void)((v_theoperator = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
                alg_hold_top = rh_550;
                (void)((v_right = alg_hold(alg_invoke(v_this, "BitXor", NULL, 0))));
                alg_hold_top = rh_550;
                (void)((v_theexpr = alg_widen(alg_hold(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3)), "Expr")));
                alg_hold_top = rh_550;
            }
        }
    }
    alg_hold_top = rh_548;
    Value ret_190 = v_theexpr;
    alg_root_top = rt_base;
    return ret_190;
    alg_hold_top = rh_548;
    Value ret_191 = alg_nil();
    alg_root_top = rt_base;
    return ret_191;
}

static Value m_parser_bitxor_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_551 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_551;
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    alg_hold_top = rh_551;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_551;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "BitAnd", NULL, 0))));
    alg_hold_top = rh_551;
    {
        int32_t rh_552 = alg_hold_top;
        while ((alg_hold_top = rh_552, alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcaret}, 1))))) {
            alg_safe_point();
            {
                int32_t rh_553 = alg_hold_top;
                (void)((v_theoperator = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
                alg_hold_top = rh_553;
                (void)((v_right = alg_hold(alg_invoke(v_this, "BitAnd", NULL, 0))));
                alg_hold_top = rh_553;
                (void)((v_theexpr = alg_widen(alg_hold(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3)), "Expr")));
                alg_hold_top = rh_553;
            }
        }
    }
    alg_hold_top = rh_551;
    Value ret_192 = v_theexpr;
    alg_root_top = rt_base;
    return ret_192;
    alg_hold_top = rh_551;
    Value ret_193 = alg_nil();
    alg_root_top = rt_base;
    return ret_193;
}

static Value m_parser_bitand_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_554 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_554;
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    alg_hold_top = rh_554;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_554;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "Term", NULL, 0))));
    alg_hold_top = rh_554;
    {
        int32_t rh_555 = alg_hold_top;
        while ((alg_hold_top = rh_555, alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVampersand}, 1))))) {
            alg_safe_point();
            {
                int32_t rh_556 = alg_hold_top;
                (void)((v_theoperator = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
                alg_hold_top = rh_556;
                (void)((v_right = alg_hold(alg_invoke(v_this, "Term", NULL, 0))));
                alg_hold_top = rh_556;
                (void)((v_theexpr = alg_widen(alg_hold(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3)), "Expr")));
                alg_hold_top = rh_556;
            }
        }
    }
    alg_hold_top = rh_554;
    Value ret_194 = v_theexpr;
    alg_root_top = rt_base;
    return ret_194;
    alg_hold_top = rh_554;
    Value ret_195 = alg_nil();
    alg_root_top = rt_base;
    return ret_195;
}

static Value m_parser_term_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_557 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_557;
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    alg_hold_top = rh_557;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_557;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "Factor", NULL, 0))));
    alg_hold_top = rh_557;
    {
        int32_t rh_558 = alg_hold_top;
        while ((alg_hold_top = rh_558, alg_truthy(alg_hold((or_61 = alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVminus}, 1)), alg_truthy(or_61) ? or_61 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVplus}, 1))))))) {
            alg_safe_point();
            {
                int32_t rh_559 = alg_hold_top;
                (void)((v_theoperator = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
                alg_hold_top = rh_559;
                (void)((v_right = alg_hold(alg_invoke(v_this, "Factor", NULL, 0))));
                alg_hold_top = rh_559;
                (void)((v_theexpr = alg_widen(alg_hold(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3)), "Expr")));
                alg_hold_top = rh_559;
            }
        }
    }
    alg_hold_top = rh_557;
    Value ret_196 = v_theexpr;
    alg_root_top = rt_base;
    return ret_196;
    alg_hold_top = rh_557;
    Value ret_197 = alg_nil();
    alg_root_top = rt_base;
    return ret_197;
}

static Value m_parser_factor_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_560 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_560;
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    alg_hold_top = rh_560;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_560;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "Unary", NULL, 0))));
    alg_hold_top = rh_560;
    {
        int32_t rh_561 = alg_hold_top;
        while ((alg_hold_top = rh_561, alg_truthy(alg_hold((or_66 = alg_hold((or_65 = alg_hold((or_64 = alg_hold((or_63 = alg_hold((or_62 = alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVslash}, 1)), alg_truthy(or_62) ? or_62 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVstar}, 1)))), alg_truthy(or_63) ? or_63 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVdiv}, 1)))), alg_truthy(or_64) ? or_64 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVmod}, 1)))), alg_truthy(or_65) ? or_65 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVshiftVleft}, 1)))), alg_truthy(or_66) ? or_66 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVshiftVright}, 1))))))) {
            alg_safe_point();
            {
                int32_t rh_562 = alg_hold_top;
                (void)((v_theoperator = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
                alg_hold_top = rh_562;
                (void)((v_right = alg_hold(alg_invoke(v_this, "Unary", NULL, 0))));
                alg_hold_top = rh_562;
                (void)((v_theexpr = alg_widen(alg_hold(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_theoperator, v_right}, 3)), "Expr")));
                alg_hold_top = rh_562;
            }
        }
    }
    alg_hold_top = rh_560;
    Value ret_198 = v_theexpr;
    alg_root_top = rt_base;
    return ret_198;
    alg_hold_top = rh_560;
    Value ret_199 = alg_nil();
    alg_root_top = rt_base;
    return ret_199;
}

static Value m_parser_unary_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_563 = alg_hold_top;
    Value v_theoperator = alg_nil();
    (void)v_theoperator;
    alg_root(&v_theoperator, 1);
    alg_hold_top = rh_563;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_563;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_563;
    if (alg_truthy(alg_hold((or_68 = alg_hold((or_67 = alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVnot}, 1)), alg_truthy(or_67) ? or_67 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVminus}, 1)))), alg_truthy(or_68) ? or_68 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVtilde}, 1)))))) {
        {
            int32_t rh_564 = alg_hold_top;
            (void)((v_theoperator = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
            alg_hold_top = rh_564;
            (void)((v_right = alg_hold(alg_invoke(v_this, "Unary", NULL, 0))));
            alg_hold_top = rh_564;
            Value ret_200 = alg_hold(alg_new(k_unaryexpr, (Value[]){v_theoperator, v_right}, 2));
            alg_root_top = rt_base;
            return ret_200;
            alg_hold_top = rh_564;
        }
    }
    alg_hold_top = rh_563;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "Call", NULL, 0))));
    alg_hold_top = rh_563;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVas}, 1)))) {
        (void)(alg_hold(alg_set_property(v_theexpr, "Cast", alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect typecast identifier.")}, 2)), "Lexeme"))}, 1)))));
    }
    alg_hold_top = rh_563;
    Value ret_201 = v_theexpr;
    alg_root_top = rt_base;
    return ret_201;
    alg_hold_top = rh_563;
    Value ret_202 = alg_nil();
    alg_root_top = rt_base;
    return ret_202;
}

static Value m_parser_collectionliteral_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_565 = alg_hold_top;
    Value v_keys = alg_nil();
    (void)v_keys;
    alg_root(&v_keys, 1);
    alg_hold_top = rh_565;
    Value v_values = alg_nil();
    (void)v_values;
    alg_root(&v_values, 1);
    alg_hold_top = rh_565;
    Value v_ismap = alg_nil();
    (void)v_ismap;
    alg_root(&v_ismap, 1);
    alg_hold_top = rh_565;
    (void)((v_keys = alg_hold(alg_list())));
    alg_hold_top = rh_565;
    (void)((v_values = alg_hold(alg_list())));
    alg_hold_top = rh_565;
    (void)((v_ismap = alg_bool(false)));
    alg_hold_top = rh_565;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1)))) {
        {
            int32_t rh_566 = alg_hold_top;
            (void)((v_ismap = alg_bool(true)));
            alg_hold_top = rh_566;
            (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVbracket, alg_literal("Expect ']' after map.")}, 2)));
            alg_hold_top = rh_566;
            Value ret_203 = alg_hold(alg_new(k_collectionexpr, (Value[]){alg_bool(true), v_keys, v_values}, 3));
            alg_root_top = rt_base;
            return ret_203;
            alg_hold_top = rh_566;
        }
    }
    alg_hold_top = rh_565;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVrightVbracket}, 1)))) {
        Value ret_204 = alg_hold(alg_new(k_collectionexpr, (Value[]){alg_bool(false), v_keys, v_values}, 3));
        alg_root_top = rt_base;
        return ret_204;
    }
    alg_hold_top = rh_565;
    Value v_first = alg_hold(alg_invoke(v_this, "Expression", NULL, 0));
    (void)v_first;
    alg_root(&v_first, 1);
    alg_hold_top = rh_565;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1)))) {
        {
            int32_t rh_567 = alg_hold_top;
            (void)((v_ismap = alg_bool(true)));
            alg_hold_top = rh_567;
            (void)(alg_hold(alg_invoke(v_keys, "Add", (Value[]){v_first}, 1)));
            alg_hold_top = rh_567;
            (void)(alg_hold(alg_invoke(v_values, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Expression", NULL, 0))}, 1)));
            alg_hold_top = rh_567;
        }
    } else {
        (void)(alg_hold(alg_invoke(v_values, "Add", (Value[]){v_first}, 1)));
    }
    alg_hold_top = rh_565;
    {
        int32_t rh_568 = alg_hold_top;
        while ((alg_hold_top = rh_568, alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))))) {
            alg_safe_point();
            {
                int32_t rh_569 = alg_hold_top;
                if (alg_truthy(v_ismap)) {
                    {
                        int32_t rh_570 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(v_keys, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Expression", NULL, 0))}, 1)));
                        alg_hold_top = rh_570;
                        (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVcolon, alg_literal("Expect ':' after key.")}, 2)));
                        alg_hold_top = rh_570;
                        (void)(alg_hold(alg_invoke(v_values, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Expression", NULL, 0))}, 1)));
                        alg_hold_top = rh_570;
                    }
                } else {
                    (void)(alg_hold(alg_invoke(v_values, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Expression", NULL, 0))}, 1)));
                }
                alg_hold_top = rh_569;
            }
        }
    }
    alg_hold_top = rh_565;
    (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVbracket, alg_literal("Expect ']' after list.")}, 2)));
    alg_hold_top = rh_565;
    Value ret_205 = alg_hold(alg_new(k_collectionexpr, (Value[]){v_ismap, v_keys, v_values}, 3));
    alg_root_top = rt_base;
    return ret_205;
    alg_hold_top = rh_565;
    Value ret_206 = alg_nil();
    alg_root_top = rt_base;
    return ret_206;
}

static Value m_parser_call_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_571 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_571;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_571;
    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "Primary", NULL, 0))));
    alg_hold_top = rh_571;
    {
        int32_t rh_572 = alg_hold_top;
        while ((alg_hold_top = rh_572, alg_truthy(alg_bool(true)))) {
            alg_safe_point();
            {
                int32_t rh_573 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVparen}, 1)))) {
                    (void)((v_theexpr = alg_hold(alg_invoke(v_this, "FinishCall", (Value[]){v_theexpr}, 1))));
                } else {
                    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVbracket}, 1)))) {
                        {
                            int32_t rt_574 = alg_root_top;
                            int32_t rh_575 = alg_hold_top;
                            Value v_bracket = alg_hold(alg_invoke(v_this, "Previous", NULL, 0));
                            (void)v_bracket;
                            alg_root(&v_bracket, 1);
                            alg_hold_top = rh_575;
                            Value v_index = alg_hold(alg_invoke(v_this, "Expression", NULL, 0));
                            (void)v_index;
                            alg_root(&v_index, 1);
                            alg_hold_top = rh_575;
                            (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVbracket, alg_literal("Expect ']' after subscript.")}, 2)));
                            alg_hold_top = rh_575;
                            (void)((v_theexpr = alg_widen(alg_hold(alg_new(k_subscriptexpr, (Value[]){v_theexpr, v_index, v_bracket}, 3)), "Expr")));
                            alg_hold_top = rh_575;
                            alg_root_top = rt_574;
                        }
                    } else {
                        if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVdot}, 1)))) {
                            {
                                int32_t rh_576 = alg_hold_top;
                                (void)((v_name = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect property name after '.'.")}, 2))));
                                alg_hold_top = rh_576;
                                (void)((v_theexpr = alg_widen(alg_hold(alg_new(k_getexpr, (Value[]){v_theexpr, v_name}, 2)), "Expr")));
                                alg_hold_top = rh_576;
                            }
                        } else {
                            break;
                        }
                    }
                }
                alg_hold_top = rh_573;
            }
        }
    }
    alg_hold_top = rh_571;
    Value ret_207 = v_theexpr;
    alg_root_top = rt_base;
    return ret_207;
    alg_hold_top = rh_571;
    Value ret_208 = alg_nil();
    alg_root_top = rt_base;
    return ret_208;
}

static Value m_parser_finishcall_1_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_callee = alg_widen(args[0], "Expr");
    (void)v_callee;
    alg_root(&v_callee, 1);
    int32_t rh_577 = alg_hold_top;
    Value v_arguments = alg_nil();
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    alg_hold_top = rh_577;
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    alg_hold_top = rh_577;
    Value v_paren = alg_nil();
    (void)v_paren;
    alg_root(&v_paren, 1);
    alg_hold_top = rh_577;
    (void)((v_arguments = alg_hold(alg_list())));
    alg_hold_top = rh_577;
    (void)((v_names = alg_hold(alg_list())));
    alg_hold_top = rh_577;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVrightVparen}, 1)))))) {
        {
            int32_t rh_578 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Argument", (Value[]){v_arguments, v_names}, 2)));
            alg_hold_top = rh_578;
            {
                int32_t rh_579 = alg_hold_top;
                while ((alg_hold_top = rh_579, alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))))) {
                    alg_safe_point();
                    {
                        int32_t rh_580 = alg_hold_top;
                        if (alg_truthy(alg_hold(alg_greater_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(255))))) {
                            alg_raise(alg_literal("Can't have more than 255 arguments."));
                        }
                        alg_hold_top = rh_580;
                        (void)(alg_hold(alg_invoke(v_this, "Argument", (Value[]){v_arguments, v_names}, 2)));
                        alg_hold_top = rh_580;
                    }
                }
            }
            alg_hold_top = rh_578;
        }
    }
    alg_hold_top = rh_577;
    (void)((v_paren = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_literal("Expect ')' after arguments.")}, 2))));
    alg_hold_top = rh_577;
    Value v_thecall = alg_hold(alg_new(k_callexpr, (Value[]){v_callee, v_paren, v_arguments}, 3));
    (void)v_thecall;
    alg_root(&v_thecall, 1);
    alg_hold_top = rh_577;
    (void)(alg_hold(alg_set_property(v_thecall, "ArgumentNames", v_names)));
    alg_hold_top = rh_577;
    Value ret_209 = v_thecall;
    alg_root_top = rt_base;
    return ret_209;
    alg_hold_top = rh_577;
    Value ret_210 = alg_nil();
    alg_root_top = rt_base;
    return ret_210;
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
    int32_t rh_581 = alg_hold_top;
    if (alg_truthy(alg_hold((or_69 = alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)), !alg_truthy(or_69) ? or_69 : alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "PeekNext", NULL, 0)), "TypeOfToken")), e_tokentype_tokenVcolon)))))) {
        {
            int32_t rt_582 = alg_root_top;
            int32_t rh_583 = alg_hold_top;
            Value v_thename = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)), "Lexeme"))));
            (void)v_thename;
            alg_root(&v_thename, 1);
            alg_hold_top = rh_583;
            (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
            alg_hold_top = rh_583;
            (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){v_thename}, 1)));
            alg_hold_top = rh_583;
            (void)(alg_hold(alg_invoke(v_arguments, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Expression", NULL, 0))}, 1)));
            alg_hold_top = rh_583;
            Value ret_211 = alg_nil();
            alg_root_top = rt_base;
            return ret_211;
            alg_hold_top = rh_583;
            alg_root_top = rt_582;
        }
    }
    alg_hold_top = rh_581;
    if (alg_truthy(alg_hold((or_70 = alg_hold(alg_greater(alg_hold(alg_property(v_names, "Length")), alg_int(0))), !alg_truthy(or_70) ? or_70 : alg_hold(alg_not_equal(alg_hold(alg_str(alg_hold(alg_subscript_get(v_names, alg_hold(alg_subtract(alg_hold(alg_property(v_names, "Length")), alg_int(1))))))), alg_literal(""))))))) {
        alg_raise(alg_literal("A positional argument cannot follow a named one."));
    }
    alg_hold_top = rh_581;
    (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_literal("")}, 1)));
    alg_hold_top = rh_581;
    (void)(alg_hold(alg_invoke(v_arguments, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Expression", NULL, 0))}, 1)));
    alg_hold_top = rh_581;
    Value ret_212 = alg_nil();
    alg_root_top = rt_base;
    return ret_212;
}

static Value m_parser_primary_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_584 = alg_hold_top;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    alg_hold_top = rh_584;
    Value v_keyword = alg_nil();
    (void)v_keyword;
    alg_root(&v_keyword, 1);
    alg_hold_top = rh_584;
    Value v_method = alg_nil();
    (void)v_method;
    alg_root(&v_method, 1);
    alg_hold_top = rh_584;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVfalse}, 1)))) {
        Value ret_213 = alg_hold(alg_new(k_literalexpr, (Value[]){alg_bool(false)}, 1));
        alg_root_top = rt_base;
        return ret_213;
    }
    alg_hold_top = rh_584;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVtrue}, 1)))) {
        Value ret_214 = alg_hold(alg_new(k_literalexpr, (Value[]){alg_bool(true)}, 1));
        alg_root_top = rt_base;
        return ret_214;
    }
    alg_hold_top = rh_584;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVnil}, 1)))) {
        Value ret_215 = alg_hold(alg_new(k_literalexpr, (Value[]){alg_nil()}, 1));
        alg_root_top = rt_base;
        return ret_215;
    }
    alg_hold_top = rh_584;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVbracket}, 1)))) {
        Value ret_216 = alg_hold(alg_invoke(v_this, "CollectionLiteral", NULL, 0));
        alg_root_top = rt_base;
        return ret_216;
    }
    alg_hold_top = rh_584;
    if (alg_truthy(alg_hold((or_73 = alg_hold((or_72 = alg_hold((or_71 = alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVinteger}, 1)), alg_truthy(or_71) ? or_71 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVnumber}, 1)))), alg_truthy(or_72) ? or_72 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVstring}, 1)))), alg_truthy(or_73) ? or_73 : alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVchar}, 1)))))) {
        {
            int32_t rh_585 = alg_hold_top;
            Value ret_217 = alg_hold(alg_new(k_literalexpr, (Value[]){alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Previous", NULL, 0)), "Literal"))}, 1));
            alg_root_top = rt_base;
            return ret_217;
            alg_hold_top = rh_585;
        }
    }
    alg_hold_top = rh_584;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVsuper}, 1)))) {
        {
            int32_t rh_586 = alg_hold_top;
            (void)((v_keyword = alg_hold(alg_invoke(v_this, "Previous", NULL, 0))));
            alg_hold_top = rh_586;
            (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdot, alg_literal("Expect '.' after 'super'.")}, 2)));
            alg_hold_top = rh_586;
            (void)((v_method = alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_literal("Expect superclass method name.")}, 2))));
            alg_hold_top = rh_586;
            Value ret_218 = alg_hold(alg_new(k_superexpr, (Value[]){v_keyword, v_method}, 2));
            alg_root_top = rt_base;
            return ret_218;
            alg_hold_top = rh_586;
        }
    }
    alg_hold_top = rh_584;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVthis}, 1)))) {
        Value ret_219 = alg_hold(alg_new(k_thisexpr, (Value[]){alg_hold(alg_invoke(v_this, "Previous", NULL, 0))}, 1));
        alg_root_top = rt_base;
        return ret_219;
    }
    alg_hold_top = rh_584;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVidentifier}, 1)))) {
        {
            int32_t rh_587 = alg_hold_top;
            Value ret_220 = alg_hold(alg_new(k_variableexpr, (Value[]){alg_hold(alg_invoke(v_this, "Previous", NULL, 0))}, 1));
            alg_root_top = rt_base;
            return ret_220;
            alg_hold_top = rh_587;
        }
    }
    alg_hold_top = rh_584;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVparen}, 1)))) {
        {
            int32_t rh_588 = alg_hold_top;
            (void)((v_theexpr = alg_hold(alg_invoke(v_this, "Expression", NULL, 0))));
            alg_hold_top = rh_588;
            (void)(alg_hold(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_literal("Expect ')' after expression.")}, 2)));
            alg_hold_top = rh_588;
            Value ret_221 = alg_hold(alg_new(k_groupingexpr, (Value[]){v_theexpr}, 1));
            alg_root_top = rt_base;
            return ret_221;
            alg_hold_top = rh_588;
        }
    }
    alg_hold_top = rh_584;
    alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), alg_literal("Expect expression!")}, 2)));
    alg_hold_top = rh_584;
    Value ret_222 = alg_nil();
    alg_root_top = rt_base;
    return ret_222;
}

static Value m_parser_match_1_tokentype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thetype = alg_widen(args[0], "TokenType");
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    int32_t rh_589 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Check", (Value[]){v_thetype}, 1)))) {
        {
            int32_t rh_590 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Advance", NULL, 0)));
            alg_hold_top = rh_590;
            Value ret_223 = alg_bool(true);
            alg_root_top = rt_base;
            return ret_223;
            alg_hold_top = rh_590;
        }
    }
    alg_hold_top = rh_589;
    Value ret_224 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_224;
    alg_hold_top = rh_589;
    Value ret_225 = alg_nil();
    alg_root_top = rt_base;
    return ret_225;
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
    int32_t rh_591 = alg_hold_top;
    (void)(alg_hold(alg_invoke(alg_singleton(k_console), "Error", (Value[]){v_thetoken, v_message}, 2)));
    alg_hold_top = rh_591;
    Value ret_226 = v_message;
    alg_root_top = rt_base;
    return ret_226;
    alg_hold_top = rh_591;
    Value ret_227 = alg_nil();
    alg_root_top = rt_base;
    return ret_227;
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
    int32_t rh_592 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Check", (Value[]){v_typeoftoken}, 1)))) {
        Value ret_228 = alg_hold(alg_invoke(v_this, "Advance", NULL, 0));
        alg_root_top = rt_base;
        return ret_228;
    }
    alg_hold_top = rh_592;
    alg_raise(alg_hold(alg_invoke(v_this, "Error", (Value[]){alg_hold(alg_invoke(v_this, "Previous", NULL, 0)), v_message}, 2)));
    alg_hold_top = rh_592;
    Value ret_229 = alg_nil();
    alg_root_top = rt_base;
    return ret_229;
}

static Value m_parser_check_1_tokentype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thetype = alg_widen(args[0], "TokenType");
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    int32_t rh_593 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        Value ret_230 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_230;
    }
    alg_hold_top = rh_593;
    Value ret_231 = alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), "TypeOfToken")), v_thetype));
    alg_root_top = rt_base;
    return ret_231;
    alg_hold_top = rh_593;
    Value ret_232 = alg_nil();
    alg_root_top = rt_base;
    return ret_232;
}

static Value m_parser_checkword_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_word = alg_widen(args[0], "String");
    (void)v_word;
    alg_root(&v_word, 1);
    int32_t rh_594 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)))))) {
        Value ret_233 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_233;
    }
    alg_hold_top = rh_594;
    Value ret_234 = alg_hold(alg_equal(alg_hold(alg_to_lower(alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), "Lexeme")))))), v_word));
    alg_root_top = rt_base;
    return ret_234;
    alg_hold_top = rh_594;
    Value ret_235 = alg_nil();
    alg_root_top = rt_base;
    return ret_235;
}

static Value m_parser_advance_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_595 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsAtEnd", NULL, 0)))))) {
        (void)(alg_set_property(v_this, "Current", alg_hold(alg_add(alg_property(v_this, "Current"), alg_int(1)))));
    }
    alg_hold_top = rh_595;
    Value ret_236 = alg_hold(alg_invoke(v_this, "Previous", NULL, 0));
    alg_root_top = rt_base;
    return ret_236;
    alg_hold_top = rh_595;
    Value ret_237 = alg_nil();
    alg_root_top = rt_base;
    return ret_237;
}

static Value m_parser_isatend_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_596 = alg_hold_top;
    Value ret_238 = alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "Peek", NULL, 0)), "TypeOfToken")), e_tokentype_eof));
    alg_root_top = rt_base;
    return ret_238;
    alg_hold_top = rh_596;
    Value ret_239 = alg_nil();
    alg_root_top = rt_base;
    return ret_239;
}

static Value m_parser_peek_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_597 = alg_hold_top;
    Value ret_240 = alg_hold(alg_subscript_get(alg_property(v_this, "Tokens"), alg_property(v_this, "Current")));
    alg_root_top = rt_base;
    return ret_240;
    alg_hold_top = rh_597;
    Value ret_241 = alg_nil();
    alg_root_top = rt_base;
    return ret_241;
}

static Value m_parser_peeknext_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_598 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_greater_equal(alg_hold(alg_add(alg_property(v_this, "Current"), alg_int(1))), alg_hold(alg_property(alg_property(v_this, "Tokens"), "Length")))))) {
        Value ret_242 = alg_hold(alg_subscript_get(alg_property(v_this, "Tokens"), alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "Tokens"), "Length")), alg_int(1)))));
        alg_root_top = rt_base;
        return ret_242;
    }
    alg_hold_top = rh_598;
    Value ret_243 = alg_hold(alg_subscript_get(alg_property(v_this, "Tokens"), alg_hold(alg_add(alg_property(v_this, "Current"), alg_int(1)))));
    alg_root_top = rt_base;
    return ret_243;
    alg_hold_top = rh_598;
    Value ret_244 = alg_nil();
    alg_root_top = rt_base;
    return ret_244;
}

static Value m_parser_previous_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_599 = alg_hold_top;
    Value ret_245 = alg_hold(alg_subscript_get(alg_property(v_this, "Tokens"), alg_hold(alg_subtract(alg_property(v_this, "Current"), alg_int(1)))));
    alg_root_top = rt_base;
    return ret_245;
    alg_hold_top = rh_599;
    Value ret_246 = alg_nil();
    alg_root_top = rt_base;
    return ret_246;
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
    alg_class_field(k_parser, "Tokens", "List");
    alg_class_field(k_parser, "Current", "Integer");
    alg_class_field(k_parser, "FileName", "String");
    alg_class_field(k_parser, "Loaded", "Map");
    alg_class_field(k_parser, "Claimed", "Map");
    alg_class_field(k_parser, "PrivateNames", "List");
    alg_class_field(k_parser, "InPrivateSection", "Boolean");
    alg_class_field(k_parser, "ClassPrivates", "List");
    alg_class_field(k_parser, "LoopDepth", "Integer");
    alg_class_field(k_parser, "InProcedure", "Boolean");
    alg_class_field(k_parser, "SubprogramDepth", "Integer");
    alg_class_field(k_parser, "LastGeneric", "String");
    alg_class_field(k_parser, "PendingLabel", "String");
    alg_class_field(k_parser, "LoopLabels", "List");
    alg_class_initializer(k_parser, i_parser);
    alg_class_method(k_parser, "Init", m_parser_init_1_list, 1, t_parser_init_1_list);
    alg_class_method(k_parser, "UnitHeader", m_parser_unitheader_0, 0, NULL);
    alg_class_method(k_parser, "ClaimUnit", m_parser_claimunit_2_token_string, 2, t_parser_claimunit_2_token_string);
    alg_class_method(k_parser, "UnitStem", m_parser_unitstem_1_string, 1, t_parser_unitstem_1_string);
    alg_class_method(k_parser, "Parse", m_parser_parse_0, 0, NULL);
    alg_class_method(k_parser, "Statement", m_parser_statement_0, 0, NULL);
    alg_class_method(k_parser, "StatementBody", m_parser_statementbody_0, 0, NULL);
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
    int32_t rh_349 = alg_hold_top;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    v_moduleVfolders = alg_hold(alg_list());
    d_moduleVfolders = true;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
    alg_hold_top = rh_349;
}
