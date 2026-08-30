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
Value fn_readwholefile;
Value k_parser;
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
static Value or_49;
static Value or_50;
static const char *t_parser_init_1_list[] = { "List" };
static const char *t_parser_unitstem_1_string[] = { "String" };
static const char *t_parser_iscollectiontype_1_string[] = { "String" };
static const char *t_parser_recordprivate_1[] = { "Any" };
static const char *t_parser_directoryof_1_string[] = { "String" };
static const char *t_parser_resolvemodule_2_token_string[] = { "Token", "String" };
static const char *t_parser_declarationsection_1_boolean[] = { "Boolean" };
static const char *t_parser_readdeclarationsections_1_list[] = { "List" };
static const char *t_parser_readdeclarationsections_2_list_boolean[] = { "List", "Boolean" };
static const char *t_parser_forinstatement_1_token[] = { "Token" };
static const char *t_parser_vardeclaration_1_token[] = { "Token" };
static const char *t_parser_parsefunction_1_string[] = { "String" };
static const char *t_parser_subrangedeclaration_1_token[] = { "Token" };
static const char *t_parser_classdeclaration_1_string[] = { "String" };
static const char *t_parser_finishcall_1_expr[] = { "Expr" };
static const char *t_parser_match_1_tokentype[] = { "TokenType" };
static const char *t_parser_error_2_token_string[] = { "Token", "String" };
static const char *t_parser_consume_2_tokentype_string[] = { "TokenType", "String" };
static const char *t_parser_check_1_tokentype[] = { "TokenType" };
static const char *t_parser_checkword_1_string[] = { "String" };

Value f_readwholefile(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_name = alg_param(args[0], "String");
    (void)v_name;
    Value v_f = alg_text_file();
    (void)v_f;
    (void)(alg_invoke(v_f, "Assign", (Value[]){v_name}, 1));
    (void)(alg_invoke(v_f, "Reset", NULL, 0));
    Value v_result = alg_buffer(alg_int(0));
    (void)v_result;
    while (alg_truthy(alg_not(alg_property(v_f, "Eof")))) {
        {
            (void)(alg_invoke(v_result, "Append", (Value[]){alg_invoke(v_f, "ReadLn", NULL, 0)}, 1));
            (void)(alg_invoke(v_result, "Append", (Value[]){alg_char_value(10)}, 1));
        }
    }
    (void)(alg_invoke(v_f, "Close", NULL, 0));
    return alg_property(v_result, "Text");
    return alg_nil();
}

static Value i_parser(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Tokens", alg_nil());
    alg_set_property(v_this, "Current", alg_nil());
    alg_set_property(v_this, "FileName", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "Loaded", alg_widen(alg_map(), "Map"));
    alg_set_property(v_this, "PrivateNames", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "InPrivateSection", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "ClassPrivates", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "LoopDepth", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "InProcedure", alg_widen(alg_bool(false), "Boolean"));
    return alg_nil();
}

static Value m_parser_init_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_tokens = alg_widen(args[0], "List");
    (void)v_tokens;
    (void)(alg_set_property(v_this, "Tokens", alg_widen(v_tokens, "List")));
    (void)(alg_set_property(v_this, "Current", alg_widen(alg_int(0), "Integer")));
    return alg_nil();
}

static Value m_parser_unitheader_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)))) {
        return alg_nil();
    }
    if (alg_truthy(alg_not_equal(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "Lexeme"), alg_string("unit")))) {
        return alg_nil();
    }
    if (alg_truthy(alg_not_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVidentifier))) {
        return alg_nil();
    }
    (void)(alg_invoke(v_this, "Advance", NULL, 0));
    Value v_name = alg_invoke(v_this, "Advance", NULL, 0);
    (void)v_name;
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after unit name.")}, 2));
    Value v_expected = alg_invoke(v_this, "UnitStem", (Value[]){alg_property(v_this, "FileName")}, 1);
    (void)v_expected;
    if (alg_truthy((or_0 = alg_equal(v_expected, alg_string("")), alg_truthy(or_0) ? or_0 : alg_equal(v_expected, alg_string("REPL"))))) {
        return alg_nil();
    }
    if (alg_truthy(alg_not_equal(v_expected, alg_str(alg_property(v_name, "Lexeme"))))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_name, alg_add(alg_add(alg_add(alg_add(alg_string("Unit '"), alg_str(alg_property(v_name, "Lexeme"))), alg_string("' must match its file name '")), v_expected), alg_string("'."))}, 2));
    }
    return alg_nil();
}

static Value m_parser_unitstem_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_key = alg_widen(args[0], "String");
    (void)v_key;
    Value v_stem = alg_nil();
    (void)v_stem;
    (void)((v_stem = alg_widen(v_key, "String")));
    {
        Value v_i = alg_subtract(alg_text_length(v_key), alg_int(1));
        (void)v_i;
        while (alg_truthy(alg_greater_equal(v_i, alg_int(0)))) {
            {
                if (alg_truthy((or_1 = alg_equal(alg_subscript_get(v_key, v_i), alg_char_value(47)), alg_truthy(or_1) ? or_1 : alg_equal(alg_subscript_get(v_key, v_i), alg_char_value(92))))) {
                    {
                        (void)((v_stem = alg_widen(alg_copy(v_key, alg_add(v_i, alg_int(1)), alg_subtract(alg_subtract(alg_text_length(v_key), v_i), alg_int(1))), "String")));
                        (void)((v_i = alg_negate(alg_int(1))));
                    }
                }
                (void)((v_i = alg_subtract(v_i, alg_int(1))));
            }
        }
    }
    if (alg_truthy((or_2 = alg_greater(alg_text_length(v_stem), alg_int(4)), !alg_truthy(or_2) ? or_2 : alg_equal(alg_copy(v_stem, alg_subtract(alg_text_length(v_stem), alg_int(4)), alg_int(4)), alg_string(".a24"))))) {
        return alg_copy(v_stem, alg_int(0), alg_subtract(alg_text_length(v_stem), alg_int(4)));
    }
    return v_stem;
    return alg_nil();
}

static Value m_parser_parse_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_nil();
    (void)v_statements;
    (void)((v_statements = alg_widen(alg_list(), "List")));
    if (alg_truthy(alg_not_equal(alg_property(v_this, "FileName"), alg_string("")))) {
        (void)(alg_invoke(alg_property(v_this, "Loaded"), "Put", (Value[]){alg_property(v_this, "FileName"), alg_bool(true)}, 2));
    }
    (void)(alg_invoke(v_this, "UnitHeader", NULL, 0));
    while (alg_truthy(alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        {
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVuses}, 1))) {
                {
                    Value v_themodule = alg_invoke(v_this, "UsesStatement", NULL, 0);
                    (void)v_themodule;
                    if (alg_truthy(alg_not_equal(v_themodule, alg_nil()))) {
                        (void)(alg_invoke(v_statements, "Add", (Value[]){v_themodule}, 1));
                    }
                }
            } else {
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVprivate}, 1))) {
                    {
                        Value v_decl = alg_invoke(v_this, "Declaration", NULL, 0);
                        (void)v_decl;
                        (void)(alg_invoke(v_this, "RecordPrivate", (Value[]){v_decl}, 1));
                        (void)(alg_invoke(v_statements, "Add", (Value[]){v_decl}, 1));
                    }
                } else {
                    (void)(alg_invoke(v_statements, "Add", (Value[]){alg_invoke(v_this, "Declaration", NULL, 0)}, 1));
                }
            }
        }
    }
    return v_statements;
    return alg_nil();
}

static Value m_parser_statement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVtype}, 1))) {
        return alg_invoke(v_this, "EnumDeclaration", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVclass}, 1))) {
        return alg_invoke(v_this, "ClassDeclaration", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVobject}, 1))) {
        return alg_invoke(v_this, "ClassDeclaration", (Value[]){alg_string("object")}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVfunction}, 1))) {
        return alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("function")}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVprocedure}, 1))) {
        return alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("procedure")}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVvar}, 1))) {
        return alg_invoke(v_this, "VarDeclaration", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVconst}, 1))) {
        return alg_invoke(v_this, "ConstDeclaration", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcase}, 1))) {
        return alg_invoke(v_this, "CaseStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVif}, 1))) {
        return alg_invoke(v_this, "IfStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVwhile}, 1))) {
        return alg_invoke(v_this, "WhileStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVfor}, 1))) {
        return alg_invoke(v_this, "ForStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVexit}, 1))) {
        return alg_invoke(v_this, "ReturnStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVtry}, 1))) {
        return alg_invoke(v_this, "TryStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVbreak}, 1))) {
        return alg_invoke(v_this, "BreakStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVraise}, 1))) {
        return alg_invoke(v_this, "RaiseStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVbegin}, 1))) {
        return alg_new(k_blockstmt, (Value[]){alg_invoke(v_this, "Block", NULL, 0)}, 1);
    }
    return alg_invoke(v_this, "ExpressionStatement", NULL, 0);
    return alg_nil();
}

static Value m_parser_casestatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_left = alg_nil();
    (void)v_left;
    Value v_top = alg_nil();
    (void)v_top;
    Value v_current = alg_nil();
    (void)v_current;
    Value v_condition = alg_nil();
    (void)v_condition;
    Value v_branch = alg_nil();
    (void)v_branch;
    (void)((v_left = alg_widen(alg_invoke(v_this, "Expression", NULL, 0), "Expr")));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVof, alg_string("Expect 'of' after case condition.")}, 2));
    (void)((v_top = alg_widen(alg_cast(alg_nil(), "IfStmt"), "IfStmt")));
    (void)((v_current = alg_widen(alg_cast(alg_nil(), "IfStmt"), "IfStmt")));
    while (alg_truthy(alg_bool(true))) {
        {
            (void)((v_condition = alg_widen(alg_new(k_binaryexpr, (Value[]){v_left, alg_invoke(v_this, "Equals", NULL, 0), alg_invoke(v_this, "Expression", NULL, 0)}, 3), "Expr")));
            while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))) {
                (void)((v_condition = alg_widen(alg_new(k_logicalexpr, (Value[]){v_condition, alg_invoke(v_this, "Either", NULL, 0), alg_new(k_binaryexpr, (Value[]){v_left, alg_invoke(v_this, "Equals", NULL, 0), alg_invoke(v_this, "Expression", NULL, 0)}, 3)}, 3), "Expr")));
            }
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVcolon, alg_string("Expect ':' after condition.")}, 2));
            (void)((v_branch = alg_widen(alg_new(k_ifstmt, (Value[]){v_condition, alg_invoke(v_this, "Statement", NULL, 0), alg_nil()}, 3), "IfStmt")));
            if (alg_truthy(alg_equal(v_top, alg_nil()))) {
                (void)((v_top = alg_widen(v_branch, "IfStmt")));
            } else {
                (void)(alg_set_property(v_current, "ElseBranch", alg_widen(v_branch, "Stmt")));
            }
            (void)((v_current = alg_widen(v_branch, "IfStmt")));
            if (alg_truthy((or_3 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVelse}, 1), alg_truthy(or_3) ? or_3 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVend}, 1)))) {
                break;
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(alg_invoke(v_this, "Previous", NULL, 0), "TypeOfToken"), e_tokentype_tokenVelse))) {
        {
            (void)(alg_set_property(v_current, "ElseBranch", alg_widen(alg_invoke(v_this, "BodyStatement", NULL, 0), "Stmt")));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVend, alg_string("Expected 'end'.")}, 2));
        }
    }
    return v_top;
    return alg_nil();
}

static Value m_parser_equals_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_new(k_token, (Value[]){e_tokentype_tokenVequal, alg_char_value(61), alg_nil(), alg_property(alg_invoke(v_this, "Previous", NULL, 0), "LineNumber")}, 4);
    return alg_nil();
}

static Value m_parser_either_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_new(k_token, (Value[]){e_tokentype_tokenVor, alg_string("or"), alg_nil(), alg_property(alg_invoke(v_this, "Previous", NULL, 0), "LineNumber")}, 4);
    return alg_nil();
}

static Value m_parser_bodystatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy((or_9 = (or_8 = (or_7 = (or_6 = (or_5 = (or_4 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVvar}, 1), alg_truthy(or_4) ? or_4 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVconst}, 1)), alg_truthy(or_5) ? or_5 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVtype}, 1)), alg_truthy(or_6) ? or_6 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVclass}, 1)), alg_truthy(or_7) ? or_7 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVobject}, 1)), alg_truthy(or_8) ? or_8 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVfunction}, 1)), alg_truthy(or_9) ? or_9 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVprocedure}, 1)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_invoke(v_this, "Peek", NULL, 0), alg_string("A declaration cannot be a branch or loop body; use 'begin' ... 'end'.")}, 2));
    }
    return alg_invoke(v_this, "Statement", NULL, 0);
    return alg_nil();
}

static Value m_parser_iscollectiontype_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_typename = alg_widen(args[0], "String");
    (void)v_typename;
    Value v_lowered = alg_nil();
    (void)v_lowered;
    (void)((v_lowered = alg_widen(f_tolower(NULL, (Value[]){v_typename}, 1), "String")));
    return (or_13 = (or_12 = (or_11 = (or_10 = alg_equal(v_lowered, alg_string("list")), alg_truthy(or_10) ? or_10 : alg_equal(v_lowered, alg_string("map"))), alg_truthy(or_11) ? or_11 : alg_equal(v_lowered, alg_string("set"))), alg_truthy(or_12) ? or_12 : alg_equal(v_lowered, alg_string("stack"))), alg_truthy(or_13) ? or_13 : alg_equal(v_lowered, alg_string("array")));
    return alg_nil();
}

static Value m_parser_ifstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_condition = alg_nil();
    (void)v_condition;
    Value v_thenbranch = alg_nil();
    (void)v_thenbranch;
    Value v_elsebranch = alg_nil();
    (void)v_elsebranch;
    (void)((v_condition = alg_widen(alg_invoke(v_this, "Expression", NULL, 0), "Expr")));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVthen, alg_string("Expect 'then' after if condition.")}, 2));
    (void)((v_thenbranch = alg_widen(alg_invoke(v_this, "BodyStatement", NULL, 0), "Stmt")));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVelse}, 1))) {
        {
            (void)((v_elsebranch = alg_widen(alg_invoke(v_this, "BodyStatement", NULL, 0), "Stmt")));
        }
    }
    return alg_new(k_ifstmt, (Value[]){v_condition, v_thenbranch, v_elsebranch}, 3);
    return alg_nil();
}

static Value m_parser_forstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    Value v_increment = alg_nil();
    (void)v_increment;
    Value v_condition = alg_nil();
    (void)v_condition;
    Value v_body = alg_nil();
    (void)v_body;
    Value v_stmtlist = alg_nil();
    (void)v_stmtlist;
    Value v_whilelist = alg_nil();
    (void)v_whilelist;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVsemicolon}, 1))) {
        (void)((v_initializer = alg_widen(alg_nil(), "Stmt")));
    } else {
        if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVvar}, 1))) {
            {
                Value v_name = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect variable name.")}, 2);
                (void)v_name;
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVin}, 1))) {
                    return alg_invoke(v_this, "ForInStatement", (Value[]){v_name}, 1);
                }
                (void)((v_initializer = alg_widen(alg_invoke(v_this, "VarDeclaration", (Value[]){v_name}, 1), "Stmt")));
            }
        } else {
            (void)((v_initializer = alg_widen(alg_invoke(v_this, "ExpressionStatement", NULL, 0), "Stmt")));
        }
    }
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVsemicolon}, 1)))) {
        {
            (void)((v_condition = alg_widen(alg_invoke(v_this, "Expression", NULL, 0), "Expr")));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after loop condition")}, 2));
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVdo}, 1)))) {
        {
            (void)((v_increment = alg_widen(alg_invoke(v_this, "Expression", NULL, 0), "Expr")));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdo, alg_string("Expect 'do' after for clauses.")}, 2));
    (void)(alg_set_property(v_this, "LoopDepth", alg_widen(alg_add(alg_property(v_this, "LoopDepth"), alg_int(1)), "Integer")));
    (void)((v_body = alg_widen(alg_invoke(v_this, "BodyStatement", NULL, 0), "Stmt")));
    (void)(alg_set_property(v_this, "LoopDepth", alg_widen(alg_subtract(alg_property(v_this, "LoopDepth"), alg_int(1)), "Integer")));
    if (alg_truthy(alg_not_equal(v_increment, alg_nil()))) {
        {
            (void)((v_stmtlist = alg_widen(alg_list(), "List")));
            (void)(alg_invoke(v_stmtlist, "Add", (Value[]){v_body}, 1));
            (void)(alg_invoke(v_stmtlist, "Add", (Value[]){alg_new(k_expressionstmt, (Value[]){v_increment}, 1)}, 1));
            (void)((v_body = alg_widen(alg_new(k_blockstmt, (Value[]){v_stmtlist}, 1), "Stmt")));
        }
    }
    if (alg_truthy(alg_equal(v_condition, alg_nil()))) {
        (void)((v_condition = alg_widen(alg_new(k_literalexpr, (Value[]){alg_bool(true)}, 1), "Expr")));
    }
    (void)((v_body = alg_widen(alg_new(k_whilestmt, (Value[]){v_condition, v_body}, 2), "Stmt")));
    if (alg_truthy(alg_not_equal(v_initializer, alg_nil()))) {
        {
            (void)((v_whilelist = alg_widen(alg_list(), "List")));
            (void)(alg_invoke(v_whilelist, "Add", (Value[]){v_initializer}, 1));
            (void)(alg_invoke(v_whilelist, "Add", (Value[]){v_body}, 1));
            (void)((v_body = alg_widen(alg_new(k_blockstmt, (Value[]){v_whilelist}, 1), "Stmt")));
        }
    }
    return v_body;
    return alg_nil();
}

static Value m_parser_whilestatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_condition = alg_nil();
    (void)v_condition;
    Value v_body = alg_nil();
    (void)v_body;
    (void)((v_condition = alg_widen(alg_invoke(v_this, "Expression", NULL, 0), "Expr")));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdo, alg_string("Expect 'do' after condition.")}, 2));
    (void)(alg_set_property(v_this, "LoopDepth", alg_widen(alg_add(alg_property(v_this, "LoopDepth"), alg_int(1)), "Integer")));
    (void)((v_body = alg_widen(alg_invoke(v_this, "BodyStatement", NULL, 0), "Stmt")));
    (void)(alg_set_property(v_this, "LoopDepth", alg_widen(alg_subtract(alg_property(v_this, "LoopDepth"), alg_int(1)), "Integer")));
    return alg_new(k_whilestmt, (Value[]){v_condition, v_body}, 2);
    return alg_nil();
}

static Value m_parser_returnstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_keyword = alg_nil();
    (void)v_keyword;
    Value v_value = alg_nil();
    (void)v_value;
    (void)((v_keyword = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVsemicolon}, 1)))) {
        {
            if (alg_truthy(alg_property(v_this, "InProcedure"))) {
                alg_raise(alg_invoke(v_this, "Error", (Value[]){v_keyword, alg_string("A procedure cannot exit a value.")}, 2));
            }
            (void)((v_value = alg_widen(alg_invoke(v_this, "Expression", NULL, 0), "Expr")));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after exit value.")}, 2));
    return alg_new(k_returnstmt, (Value[]){v_keyword, v_value}, 2);
    return alg_nil();
}

static Value m_parser_recordprivate_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_decl = args[0];
    (void)v_decl;
    if (alg_truthy((or_16 = (or_15 = (or_14 = alg_is(v_decl, "FunctionStmt"), alg_truthy(or_14) ? or_14 : alg_is(v_decl, "ClassStmt")), alg_truthy(or_15) ? or_15 : alg_is(v_decl, "ObjectStmt")), alg_truthy(or_16) ? or_16 : alg_is(v_decl, "VarStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_str(alg_property(alg_property(v_decl, "Name"), "Lexeme"))}, 1));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_is(v_decl, "VarGroupStmt"))) {
        {
            {
                Value v_i = alg_int(0);
                (void)v_i;
                while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_decl, "Names"), "Length")))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_decl, "Names"), v_i), "Lexeme"))}, 1));
                        (void)((v_i = alg_add(v_i, alg_int(1))));
                    }
                }
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_is(v_decl, "EnumStmt"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_str(alg_property(alg_property(v_decl, "Name"), "Lexeme"))}, 1));
            {
                Value v_i = alg_int(0);
                (void)v_i;
                while (alg_truthy(alg_less(v_i, alg_property(alg_property(v_decl, "Members"), "Length")))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_decl, "Members"), v_i), "Lexeme"))}, 1));
                        (void)((v_i = alg_add(v_i, alg_int(1))));
                    }
                }
            }
            return alg_nil();
        }
    }
    alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_invoke(v_this, "Previous", NULL, 0), alg_string("'private' must precede a declaration.")}, 2));
    return alg_nil();
}

static Value m_parser_directoryof_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_path = alg_widen(args[0], "String");
    (void)v_path;
    Value v_cut = alg_widen(alg_negate(alg_int(1)), "Integer");
    (void)v_cut;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_text_length(v_path)))) {
            {
                if (alg_truthy(alg_equal(alg_subscript_get(v_path, v_i), alg_char_value(47)))) {
                    (void)((v_cut = alg_widen(v_i, "Integer")));
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_less(v_cut, alg_int(0)))) {
        return alg_string("");
    }
    return alg_copy(v_path, alg_int(0), v_cut);
    return alg_nil();
}

static Value m_parser_resolvemodule_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_where = alg_widen(args[0], "Token");
    (void)v_where;
    Value v_modulename = alg_widen(args[1], "String");
    (void)v_modulename;
    Value v_thefile = alg_nil();
    (void)v_thefile;
    Value v_dir = alg_nil();
    (void)v_dir;
    (void)((v_thefile = alg_widen(alg_add(v_modulename, alg_string(".a24")), "String")));
    (void)((v_dir = alg_widen(alg_invoke(v_this, "DirectoryOf", (Value[]){alg_property(v_this, "FileName")}, 1), "String")));
    if (alg_truthy(alg_not_equal(v_dir, alg_string("")))) {
        {
            Value v_beside = alg_add(alg_add(v_dir, alg_char_value(47)), v_thefile);
            (void)v_beside;
            if (alg_truthy(alg_file_exists(v_beside))) {
                return v_beside;
            }
        }
    }
    if (alg_truthy(alg_file_exists(v_thefile))) {
        return v_thefile;
    }
    Value v_searched = alg_string("the working directory");
    (void)v_searched;
    if (alg_truthy(alg_not_equal(v_dir, alg_string("")))) {
        (void)((v_searched = alg_add(alg_add(alg_char_value(39), v_dir), alg_string("' or the working directory"))));
    }
    alg_raise(alg_invoke(v_this, "Error", (Value[]){v_where, alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("Could not find module '"), v_modulename), alg_string("': no ")), v_thefile), alg_string(" in ")), v_searched), alg_char_value(46))}, 2));
    return alg_nil();
}

static Value m_parser_usesstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_modulename = alg_nil();
    (void)v_modulename;
    Value v_where = alg_nil();
    (void)v_where;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVstring}, 1))) {
        (void)((v_modulename = alg_widen(alg_str(alg_property(alg_invoke(v_this, "Previous", NULL, 0), "Literal")), "String")));
    } else {
        (void)((v_modulename = alg_widen(alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expected identifier.")}, 2), "Lexeme")), "String")));
    }
    (void)((v_where = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expected ';'")}, 2));
    Value v_path = alg_invoke(v_this, "ResolveModule", (Value[]){v_where, v_modulename}, 2);
    (void)v_path;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Loaded"), "Contains", (Value[]){v_path}, 1))) {
        {
            Value v_seen = alg_new(k_modulestmt, (Value[]){v_where, alg_nil(), alg_list()}, 3);
            (void)v_seen;
            (void)(alg_set_property(v_seen, "FileName", alg_widen(v_path, "String")));
            (void)(alg_set_property(v_seen, "UnitName", alg_widen(alg_invoke(v_this, "UnitStem", (Value[]){v_path}, 1), "String")));
            return v_seen;
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Loaded"), "Put", (Value[]){v_path, alg_bool(true)}, 2));
    Value v_subscanner = alg_new(k_scanner, (Value[]){f_readwholefile(NULL, (Value[]){v_path}, 1)}, 1);
    (void)v_subscanner;
    Value v_subparser = alg_new(k_parser, (Value[]){alg_invoke(v_subscanner, "ScanTokens", NULL, 0)}, 1);
    (void)v_subparser;
    (void)(alg_set_property(v_subparser, "FileName", alg_widen(v_path, "String")));
    (void)(alg_set_property(v_subparser, "Loaded", alg_widen(alg_property(v_this, "Loaded"), "Map")));
    Value v_result = alg_invoke(v_subparser, "Parse", NULL, 0);
    (void)v_result;
    Value v_themodule = alg_new(k_modulestmt, (Value[]){v_where, v_result, alg_property(v_subparser, "PrivateNames")}, 3);
    (void)v_themodule;
    (void)(alg_set_property(v_themodule, "FileName", alg_widen(v_path, "String")));
    (void)(alg_set_property(v_themodule, "UnitName", alg_widen(alg_invoke(v_this, "UnitStem", (Value[]){v_path}, 1), "String")));
    return v_themodule;
    return alg_nil();
}

static Value m_parser_constdeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_nil();
    (void)v_name;
    (void)((v_name = alg_widen(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect constant name.")}, 2), "Token")));
    Value v_typename = alg_string("");
    (void)v_typename;
    Value v_generic = alg_string("");
    (void)v_generic;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
        {
            (void)((v_typename = f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect type name.")}, 2), "Lexeme")}, 1)));
            if (alg_truthy((or_17 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_typename}, 1), !alg_truthy(or_17) ? or_17 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))) {
                (void)((v_generic = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect generic type.")}, 2), "Lexeme"))));
            }
        }
    }
    if (alg_truthy(alg_not(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVassign}, 1)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_name, alg_string("A constant must be given a value.")}, 2));
    }
    Value v_initializer = alg_invoke(v_this, "Expression", NULL, 0);
    (void)v_initializer;
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after constant declaration.")}, 2));
    Value v_thevar = alg_new(k_varstmt, (Value[]){v_name, v_initializer}, 2);
    (void)v_thevar;
    (void)(alg_set_property(v_thevar, "TypeName", alg_widen(v_typename, "String")));
    (void)(alg_set_property(v_thevar, "Generic", alg_widen(v_generic, "String")));
    (void)(alg_set_property(v_thevar, "IsConstant", alg_widen(alg_bool(true), "Boolean")));
    return v_thevar;
    return alg_nil();
}

static Value m_parser_matchvisibility_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy((or_18 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVprivate}, 1), !alg_truthy(or_18) ? or_18 : alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVcolon)))) {
        {
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_set_property(v_this, "InPrivateSection", alg_widen(alg_bool(true), "Boolean")));
            return alg_bool(true);
        }
    }
    if (alg_truthy((or_19 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVpublic}, 1), !alg_truthy(or_19) ? or_19 : alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVcolon)))) {
        {
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_set_property(v_this, "InPrivateSection", alg_widen(alg_bool(false), "Boolean")));
            return alg_bool(true);
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value m_parser_isdeclarationsection_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return (or_21 = (or_20 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVvar}, 1), alg_truthy(or_20) ? or_20 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVconst}, 1)), alg_truthy(or_21) ? or_21 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVtype}, 1));
    return alg_nil();
}

static Value m_parser_isnextsection_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        return alg_bool(true);
    }
    return (or_28 = (or_27 = (or_26 = (or_25 = (or_24 = (or_23 = (or_22 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1), alg_truthy(or_22) ? or_22 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVbegin}, 1)), alg_truthy(or_23) ? or_23 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVfunction}, 1)), alg_truthy(or_24) ? or_24 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVprocedure}, 1)), alg_truthy(or_25) ? or_25 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVconstructor}, 1)), alg_truthy(or_26) ? or_26 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVvar}, 1)), alg_truthy(or_27) ? or_27 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVconst}, 1)), alg_truthy(or_28) ? or_28 : alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVtype}, 1));
    return alg_nil();
}

static Value m_parser_declarationsection_1_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_isconstant = alg_widen(args[0], "Boolean");
    (void)v_isconstant;
    Value v_stmts = alg_nil();
    (void)v_stmts;
    Value v_noun = alg_nil();
    (void)v_noun;
    (void)((v_stmts = alg_widen(alg_list(), "List")));
    (void)((v_noun = alg_widen(alg_string("variable"), "String")));
    if (alg_truthy(v_isconstant)) {
        (void)((v_noun = alg_widen(alg_string("constant"), "String")));
    }
    while (alg_truthy(alg_not(alg_invoke(v_this, "IsNextSection", NULL, 0)))) {
        {
            while (alg_truthy(alg_invoke(v_this, "MatchVisibility", NULL, 0))) {
                {
                }
            }
            if (alg_truthy(alg_invoke(v_this, "IsNextSection", NULL, 0))) {
                break;
            }
            Value v_names = alg_list();
            (void)v_names;
            (void)(alg_invoke(v_names, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_add(alg_add(alg_string("Expect "), v_noun), alg_string(" name."))}, 2)}, 1));
            while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))) {
                (void)(alg_invoke(v_names, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_add(alg_add(alg_string("Expect "), v_noun), alg_string(" name."))}, 2)}, 1));
            }
            if (alg_truthy(alg_property(v_this, "InPrivateSection"))) {
                {
                    Value v_i = alg_int(0);
                    (void)v_i;
                    while (alg_truthy(alg_less(v_i, alg_property(v_names, "Length")))) {
                        {
                            (void)(alg_invoke(alg_property(v_this, "ClassPrivates"), "Add", (Value[]){alg_str(alg_property(alg_subscript_get(v_names, v_i), "Lexeme"))}, 1));
                            (void)((v_i = alg_add(v_i, alg_int(1))));
                        }
                    }
                }
            }
            Value v_typename = alg_string("");
            (void)v_typename;
            Value v_generic = alg_string("");
            (void)v_generic;
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
                {
                    (void)((v_typename = f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect type name.")}, 2), "Lexeme")}, 1)));
                    if (alg_truthy((or_29 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_typename}, 1), !alg_truthy(or_29) ? or_29 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))) {
                        (void)((v_generic = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect generic type.")}, 2), "Lexeme"))));
                    }
                }
            }
            Value v_initializer = alg_cast(alg_nil(), "Expr");
            (void)v_initializer;
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
                    Value v_thevar = alg_new(k_varstmt, (Value[]){alg_subscript_get(v_names, alg_int(0)), v_initializer}, 2);
                    (void)v_thevar;
                    (void)(alg_set_property(v_thevar, "TypeName", alg_widen(v_typename, "String")));
                    (void)(alg_set_property(v_thevar, "Generic", alg_widen(v_generic, "String")));
                    (void)(alg_set_property(v_thevar, "IsConstant", alg_widen(v_isconstant, "Boolean")));
                    (void)(alg_invoke(v_stmts, "Add", (Value[]){v_thevar}, 1));
                }
            } else {
                {
                    Value v_thegroup = alg_new(k_vargroupstmt, (Value[]){v_names, v_initializer}, 2);
                    (void)v_thegroup;
                    (void)(alg_set_property(v_thegroup, "TypeName", alg_widen(v_typename, "String")));
                    (void)(alg_set_property(v_thegroup, "Generic", alg_widen(v_generic, "String")));
                    (void)(alg_set_property(v_thegroup, "IsConstant", alg_widen(v_isconstant, "Boolean")));
                    (void)(alg_invoke(v_stmts, "Add", (Value[]){v_thegroup}, 1));
                }
            }
        }
    }
    return v_stmts;
    return alg_nil();
}

static Value m_parser_readdeclarationsections_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_body = alg_widen(args[0], "List");
    (void)v_body;
    (void)(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_body, alg_bool(false)}, 2));
    return alg_nil();
}

static Value m_parser_readdeclarationsections_2_list_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_body = alg_widen(args[0], "List");
    (void)v_body;
    Value v_allowvisibility = alg_widen(args[1], "Boolean");
    (void)v_allowvisibility;
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
                    Value v_section = alg_invoke(v_this, "DeclarationSection", (Value[]){alg_bool(false)}, 1);
                    (void)v_section;
                    {
                        Value v_i = alg_int(0);
                        (void)v_i;
                        while (alg_truthy(alg_less(v_i, alg_property(v_section, "Length")))) {
                            {
                                (void)(alg_invoke(v_body, "Add", (Value[]){alg_subscript_get(v_section, v_i)}, 1));
                                (void)((v_i = alg_add(v_i, alg_int(1))));
                            }
                        }
                    }
                }
            } else {
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVconst}, 1))) {
                    {
                        Value v_section = alg_invoke(v_this, "DeclarationSection", (Value[]){alg_bool(true)}, 1);
                        (void)v_section;
                        {
                            Value v_i = alg_int(0);
                            (void)v_i;
                            while (alg_truthy(alg_less(v_i, alg_property(v_section, "Length")))) {
                                {
                                    (void)(alg_invoke(v_body, "Add", (Value[]){alg_subscript_get(v_section, v_i)}, 1));
                                    (void)((v_i = alg_add(v_i, alg_int(1))));
                                }
                            }
                        }
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
    return alg_nil();
}

static Value m_parser_forinstatement_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_iterable = alg_nil();
    (void)v_iterable;
    Value v_body = alg_nil();
    (void)v_body;
    (void)((v_iterable = alg_widen(alg_invoke(v_this, "Expression", NULL, 0), "Expr")));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdo, alg_string("Expect 'do' after 'for ... in' clause.")}, 2));
    (void)(alg_set_property(v_this, "LoopDepth", alg_widen(alg_add(alg_property(v_this, "LoopDepth"), alg_int(1)), "Integer")));
    (void)((v_body = alg_widen(alg_invoke(v_this, "BodyStatement", NULL, 0), "Stmt")));
    (void)(alg_set_property(v_this, "LoopDepth", alg_widen(alg_subtract(alg_property(v_this, "LoopDepth"), alg_int(1)), "Integer")));
    return alg_new(k_forinstmt, (Value[]){v_name, v_iterable, v_body}, 3);
    return alg_nil();
}

static Value m_parser_breakstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_keyword = alg_nil();
    (void)v_keyword;
    (void)((v_keyword = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
    if (alg_truthy(alg_equal(alg_property(v_this, "LoopDepth"), alg_int(0)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_keyword, alg_string("Must be inside a loop to use 'break'.")}, 2));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after 'break'.")}, 2));
    return alg_new(k_breakstmt, (Value[]){v_keyword}, 1);
    return alg_nil();
}

static Value m_parser_raisestatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_keyword = alg_nil();
    (void)v_keyword;
    Value v_value = alg_nil();
    (void)v_value;
    (void)((v_keyword = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
    (void)((v_value = alg_widen(alg_invoke(v_this, "Expression", NULL, 0), "Expr")));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after raised value.")}, 2));
    return alg_new(k_raisestmt, (Value[]){v_keyword, v_value}, 2);
    return alg_nil();
}

static Value m_parser_trystatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_nil();
    (void)v_statements;
    Value v_handlers = alg_nil();
    (void)v_handlers;
    Value v_hashandlers = alg_nil();
    (void)v_hashandlers;
    Value v_variable = alg_nil();
    (void)v_variable;
    Value v_thetype = alg_nil();
    (void)v_thetype;
    Value v_key = alg_nil();
    (void)v_key;
    Value v_trailing = alg_nil();
    (void)v_trailing;
    Value v_exceptstmts = alg_nil();
    (void)v_exceptstmts;
    (void)((v_statements = alg_widen(alg_list(), "List")));
    while (alg_truthy((or_30 = alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVexcept}, 1)), !alg_truthy(or_30) ? or_30 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
        (void)(alg_invoke(v_statements, "Add", (Value[]){alg_invoke(v_this, "Statement", NULL, 0)}, 1));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVexcept, alg_string("Expect 'except' after try block.")}, 2));
    (void)((v_handlers = alg_widen(alg_map(), "Map")));
    (void)((v_hashandlers = alg_widen(alg_bool(false), "Boolean")));
    while (alg_truthy(alg_invoke(v_this, "CheckWord", (Value[]){alg_string("on")}, 1))) {
        {
            (void)((v_hashandlers = alg_widen(alg_bool(true), "Boolean")));
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)((v_variable = alg_widen(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expected variable name.")}, 2), "Token")));
            (void)((v_thetype = alg_widen(alg_nil(), "Token")));
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
                (void)((v_thetype = alg_widen(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expected type.")}, 2), "Token")));
            }
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdo, alg_string("Expected 'do'.")}, 2));
            (void)((v_key = alg_widen(alg_string("default"), "String")));
            if (alg_truthy(alg_not_equal(v_thetype, alg_nil()))) {
                (void)((v_key = alg_widen(alg_str(alg_property(v_thetype, "Lexeme")), "String")));
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
    (void)((v_trailing = alg_widen(alg_invoke(v_this, "Peek", NULL, 0), "Token")));
    (void)((v_exceptstmts = alg_widen(alg_list(), "List")));
    while (alg_truthy((or_31 = alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1)), !alg_truthy(or_31) ? or_31 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
        (void)(alg_invoke(v_exceptstmts, "Add", (Value[]){alg_invoke(v_this, "Statement", NULL, 0)}, 1));
    }
    if (alg_truthy((or_32 = alg_not(v_hashandlers), alg_truthy(or_32) ? or_32 : alg_not(alg_property(v_exceptstmts, "IsEmpty"))))) {
        {
            if (alg_truthy((or_33 = alg_not(alg_property(v_exceptstmts, "IsEmpty")), !alg_truthy(or_33) ? or_33 : alg_invoke(v_handlers, "Contains", (Value[]){alg_string("default")}, 1)))) {
                alg_raise(alg_invoke(v_this, "Error", (Value[]){v_trailing, alg_string("A handler for any exception is already given by an untyped 'on'.")}, 2));
            }
            (void)(alg_invoke(v_handlers, "Put", (Value[]){alg_string("default"), alg_new(k_excepthandler, (Value[]){alg_string("Any"), alg_new(k_blockstmt, (Value[]){v_exceptstmts}, 1)}, 2)}, 2));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVend, alg_string("Expect 'end' after except block.")}, 2));
    return alg_new(k_trystmt, (Value[]){alg_new(k_blockstmt, (Value[]){v_statements}, 1), v_handlers}, 2);
    return alg_nil();
}

static Value m_parser_vardeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_invoke(v_this, "VarDeclaration", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect variable name.")}, 2)}, 1);
    return alg_nil();
}

static Value m_parser_vardeclaration_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    Value v_typename = alg_string("");
    (void)v_typename;
    Value v_generic = alg_string("");
    (void)v_generic;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
        {
            (void)((v_typename = f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect type name.")}, 2), "Lexeme")}, 1)));
            if (alg_truthy((or_34 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_typename}, 1), !alg_truthy(or_34) ? or_34 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVof}, 1)))) {
                (void)((v_generic = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect generic type.")}, 2), "Lexeme"))));
            }
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVassign}, 1))) {
        {
            (void)((v_initializer = alg_widen(alg_invoke(v_this, "Expression", NULL, 0), "Expr")));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after variable declaration.")}, 2));
    Value v_thevar = alg_new(k_varstmt, (Value[]){v_name, v_initializer}, 2);
    (void)v_thevar;
    (void)(alg_set_property(v_thevar, "TypeName", alg_widen(v_typename, "String")));
    (void)(alg_set_property(v_thevar, "Generic", alg_widen(v_generic, "String")));
    return v_thevar;
    return alg_nil();
}

static Value m_parser_expressionstatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    (void)((v_theexpr = alg_widen(alg_invoke(v_this, "Expression", NULL, 0), "Expr")));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after expression.")}, 2));
    return alg_new(k_expressionstmt, (Value[]){v_theexpr}, 1);
    return alg_nil();
}

static Value m_parser_parsefunction_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_kind = alg_widen(args[0], "String");
    (void)v_kind;
    Value v_name = alg_nil();
    (void)v_name;
    Value v_params = alg_nil();
    (void)v_params;
    Value v_body = alg_nil();
    (void)v_body;
    (void)((v_name = alg_widen(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_add(alg_add(alg_string("Expect "), v_kind), alg_string(" name."))}, 2), "Token")));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVleftVparen, alg_add(alg_add(alg_string("Expect '(' after "), v_kind), alg_string(" name."))}, 2));
    (void)((v_params = alg_widen(alg_list(), "List")));
    Value v_paramtypes = alg_list();
    (void)v_paramtypes;
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVrightVparen}, 1)))) {
        {
            (void)(alg_invoke(v_params, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect parameter name.")}, 2)}, 1));
            (void)(alg_invoke(v_paramtypes, "Add", (Value[]){alg_invoke(v_this, "ParameterType", NULL, 0)}, 1));
            while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))) {
                {
                    if (alg_truthy(alg_greater_equal(alg_property(v_params, "Length"), alg_int(255)))) {
                        {
                            alg_raise(alg_string("Can't have more than 255 parameters."));
                        }
                    }
                    (void)(alg_invoke(v_params, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect parameter name.")}, 2)}, 1));
                    (void)(alg_invoke(v_paramtypes, "Add", (Value[]){alg_invoke(v_this, "ParameterType", NULL, 0)}, 1));
                }
            }
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_string("Expect ')' after parameters.")}, 2));
    Value v_returntype = alg_string("");
    (void)v_returntype;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
        (void)((v_returntype = alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect return type.")}, 2), "Lexeme")));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_add(alg_add(alg_string("Expect ';' after "), v_kind), alg_string(" signature."))}, 2));
    (void)((v_body = alg_widen(alg_list(), "List")));
    (void)(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_body}, 1));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_add(alg_add(alg_string("Expect 'begin' before "), v_kind), alg_string(" body."))}, 2));
    Value v_wasinprocedure = alg_property(v_this, "InProcedure");
    (void)v_wasinprocedure;
    (void)(alg_set_property(v_this, "InProcedure", alg_widen(alg_equal(v_kind, alg_string("procedure")), "Boolean")));
    Value v_rest = alg_invoke(v_this, "Block", NULL, 0);
    (void)v_rest;
    (void)(alg_set_property(v_this, "InProcedure", alg_widen(v_wasinprocedure, "Boolean")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_rest, "Length")))) {
            {
                (void)(alg_invoke(v_body, "Add", (Value[]){alg_subscript_get(v_rest, v_i)}, 1));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    Value v_thefunction = alg_new(k_functionstmt, (Value[]){v_name, v_params, v_body}, 3);
    (void)v_thefunction;
    (void)(alg_set_property(v_thefunction, "ReturnType", alg_widen(v_returntype, "String")));
    (void)(alg_set_property(v_thefunction, "ParamTypes", alg_widen(v_paramtypes, "List")));
    return v_thefunction;
    return alg_nil();
}

static Value m_parser_parametertype_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_not(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1)))) {
        return alg_string("");
    }
    return f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect type name.")}, 2), "Lexeme")}, 1);
    return alg_nil();
}

static Value m_parser_block_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_nil();
    (void)v_statements;
    (void)((v_statements = alg_widen(alg_list(), "List")));
    while (alg_truthy((or_35 = alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1)), !alg_truthy(or_35) ? or_35 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
        {
            (void)(alg_invoke(v_statements, "Add", (Value[]){alg_invoke(v_this, "Declaration", NULL, 0)}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVend, alg_string("Expect 'end' after block.")}, 2));
    return v_statements;
    return alg_nil();
}

static Value m_parser_assignment_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    Value v_equals = alg_nil();
    (void)v_equals;
    Value v_value = alg_nil();
    (void)v_value;
    (void)((v_theexpr = alg_widen(alg_invoke(v_this, "ParseOr", NULL, 0), "Expr")));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVassign}, 1))) {
        {
            (void)((v_equals = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
            (void)((v_value = alg_widen(alg_invoke(v_this, "Assignment", NULL, 0), "Expr")));
            if (alg_truthy(alg_equal(alg_property(v_theexpr, "ClassName"), alg_string("VariableExpr")))) {
                return alg_new(k_assignexpr, (Value[]){alg_property(v_theexpr, "Name"), v_value}, 2);
            } else {
                if (alg_truthy(alg_equal(alg_property(v_theexpr, "ClassName"), alg_string("GetExpr")))) {
                    return alg_new(k_setexpr, (Value[]){alg_property(v_theexpr, "Obj"), alg_property(v_theexpr, "Name"), v_value}, 3);
                } else {
                    if (alg_truthy(alg_equal(alg_property(v_theexpr, "ClassName"), alg_string("SubscriptExpr")))) {
                        return alg_new(k_setsubscriptexpr, (Value[]){alg_property(v_theexpr, "Obj"), alg_property(v_theexpr, "Index"), v_value, alg_property(v_theexpr, "Bracket")}, 4);
                    }
                }
            }
            alg_raise(alg_string("Invalid assignment target."));
        }
    }
    return v_theexpr;
    return alg_nil();
}

static Value m_parser_parseor_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    Value v_op = alg_nil();
    (void)v_op;
    Value v_right = alg_nil();
    (void)v_right;
    (void)((v_theexpr = alg_widen(alg_invoke(v_this, "ParseAnd", NULL, 0), "Expr")));
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVor}, 1))) {
        {
            (void)((v_op = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
            (void)((v_right = alg_widen(alg_invoke(v_this, "ParseAnd", NULL, 0), "Expr")));
            (void)((v_theexpr = alg_widen(alg_new(k_logicalexpr, (Value[]){v_theexpr, v_op, v_right}, 3), "Expr")));
        }
    }
    return v_theexpr;
    return alg_nil();
}

static Value m_parser_parseand_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    Value v_op = alg_nil();
    (void)v_op;
    Value v_right = alg_nil();
    (void)v_right;
    (void)((v_theexpr = alg_widen(alg_invoke(v_this, "Equality", NULL, 0), "Expr")));
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVand}, 1))) {
        {
            (void)((v_op = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
            (void)((v_right = alg_widen(alg_invoke(v_this, "Equality", NULL, 0), "Expr")));
            (void)((v_theexpr = alg_widen(alg_new(k_logicalexpr, (Value[]){v_theexpr, v_op, v_right}, 3), "Expr")));
        }
    }
    return v_theexpr;
    return alg_nil();
}

static Value m_parser_expression_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    (void)((v_theexpr = alg_widen(alg_invoke(v_this, "Assignment", NULL, 0), "Expr")));
    return v_theexpr;
    return alg_nil();
}

static Value m_parser_declaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_invoke(v_this, "IsTestBlock", NULL, 0))) {
        return alg_invoke(v_this, "TestDeclaration", NULL, 0);
    }
    return alg_invoke(v_this, "Statement", NULL, 0);
    return alg_nil();
}

static Value m_parser_istestblock_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)))) {
        return alg_bool(false);
    }
    if (alg_truthy(alg_not_equal(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "Lexeme"), alg_string("test")))) {
        return alg_bool(false);
    }
    return (or_36 = alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVstring), alg_truthy(or_36) ? or_36 : alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_tokentype_tokenVchar));
    return alg_nil();
}

static Value m_parser_testdeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_nil();
    (void)v_name;
    Value v_body = alg_nil();
    (void)v_body;
    (void)(alg_invoke(v_this, "Advance", NULL, 0));
    if (alg_truthy(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVchar}, 1))) {
        (void)((v_name = alg_widen(alg_invoke(v_this, "Advance", NULL, 0), "Token")));
    } else {
        (void)((v_name = alg_widen(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVstring, alg_string("Expect a test name.")}, 2), "Token")));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after test name.")}, 2));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_string("Expect 'begin' before test body.")}, 2));
    (void)((v_body = alg_widen(alg_invoke(v_this, "Block", NULL, 0), "List")));
    return alg_new(k_functionstmt, (Value[]){v_name, alg_list(), v_body}, 3);
    return alg_nil();
}

static Value m_parser_enumdeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_nil();
    (void)v_name;
    Value v_members = alg_nil();
    (void)v_members;
    (void)((v_name = alg_widen(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect enum name.")}, 2), "Token")));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVequal, alg_string("Expect '=' after enum declaration.")}, 2));
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVleftVparen}, 1)))) {
        return alg_invoke(v_this, "SubrangeDeclaration", (Value[]){v_name}, 1);
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVleftVparen, alg_string("Expect '(' before enum members.")}, 2));
    (void)((v_members = alg_widen(alg_list(), "List")));
    (void)(alg_invoke(v_members, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect member name.")}, 2)}, 1));
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))) {
        (void)(alg_invoke(v_members, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect member name.")}, 2)}, 1));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_string("Expect ')' after enum members.")}, 2));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after enum declaration.")}, 2));
    return alg_new(k_enumstmt, (Value[]){v_name, v_members}, 2);
    return alg_nil();
}

static Value m_parser_subrangedeclaration_1_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "Token");
    (void)v_name;
    Value v_low = alg_nil();
    (void)v_low;
    Value v_high = alg_nil();
    (void)v_high;
    (void)((v_low = alg_widen(alg_invoke(v_this, "SubrangeBound", NULL, 0), "Integer")));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdotVdot, alg_string("Expect '..' between subrange bounds.")}, 2));
    (void)((v_high = alg_widen(alg_invoke(v_this, "SubrangeBound", NULL, 0), "Integer")));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_string("Expect ';' after subrange declaration.")}, 2));
    if (alg_truthy(alg_greater(v_low, v_high))) {
        (void)(alg_invoke(v_this, "Error", (Value[]){v_name, alg_add(alg_add(alg_add(alg_add(alg_string("A subrange must not be empty: "), alg_str(v_low)), alg_string(" is above ")), alg_str(v_high)), alg_char_value(46))}, 2));
    }
    return alg_new(k_subrangestmt, (Value[]){v_name, v_low, v_high}, 3);
    return alg_nil();
}

static Value m_parser_subrangebound_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_negative = alg_nil();
    (void)v_negative;
    (void)((v_negative = alg_widen(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVminus}, 1), "Boolean")));
    Value v_bound = alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVinteger, alg_string("Expect an integer bound.")}, 2);
    (void)v_bound;
    if (alg_truthy(v_negative)) {
        return alg_subtract(alg_int(0), (alg_cast(alg_property(v_bound, "Literal"), "Integer")));
    }
    return alg_cast(alg_property(v_bound, "Literal"), "Integer");
    return alg_nil();
}

static Value m_parser_classdeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_invoke(v_this, "ClassDeclaration", (Value[]){alg_string("class")}, 1);
    return alg_nil();
}

static Value m_parser_classdeclaration_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_kind = alg_widen(args[0], "String");
    (void)v_kind;
    Value v_name = alg_nil();
    (void)v_name;
    Value v_methods = alg_nil();
    (void)v_methods;
    Value v_fields = alg_nil();
    (void)v_fields;
    Value v_superclass = alg_nil();
    (void)v_superclass;
    (void)((v_name = alg_widen(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_add(alg_add(alg_string("Expect "), v_kind), alg_string(" name."))}, 2), "Token")));
    (void)((v_superclass = alg_widen(alg_cast(alg_nil(), "VariableExpr"), "VariableExpr")));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVparen}, 1))) {
        {
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect superclass name.")}, 2));
            (void)((v_superclass = alg_widen(alg_new(k_variableexpr, (Value[]){alg_invoke(v_this, "Previous", NULL, 0)}, 1), "VariableExpr")));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_string("Expect ')' after superclass name.")}, 2));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVsemicolon, alg_add(alg_add(alg_string("Expect ';' after "), v_kind), alg_string(" declaration."))}, 2));
    (void)(alg_set_property(v_this, "ClassPrivates", alg_widen(alg_list(), "List")));
    (void)(alg_set_property(v_this, "InPrivateSection", alg_widen(alg_bool(false), "Boolean")));
    (void)((v_fields = alg_widen(alg_list(), "List")));
    Value v_section = alg_list();
    (void)v_section;
    (void)(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_section, alg_bool(true)}, 2));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        while (alg_truthy(alg_less(v_i, alg_property(v_section, "Length")))) {
            {
                {
                    Value v_each = alg_subscript_get(v_section, v_i);
                    (void)v_each;
                    if (alg_truthy(alg_is(v_each, "VarGroupStmt"))) {
                        {
                            {
                                Value v_j = alg_int(0);
                                (void)v_j;
                                while (alg_truthy(alg_less(v_j, alg_property(alg_property(v_each, "Names"), "Length")))) {
                                    {
                                        {
                                            Value v_field = alg_new(k_varstmt, (Value[]){alg_subscript_get(alg_property(v_each, "Names"), v_j), alg_property(v_each, "Initializer")}, 2);
                                            (void)v_field;
                                            (void)(alg_set_property(v_field, "TypeName", alg_widen(alg_property(v_each, "TypeName"), "String")));
                                            (void)(alg_set_property(v_field, "Generic", alg_widen(alg_property(v_each, "Generic"), "String")));
                                            (void)(alg_invoke(v_fields, "Add", (Value[]){v_field}, 1));
                                        }
                                        (void)((v_j = alg_add(v_j, alg_int(1))));
                                    }
                                }
                            }
                        }
                    } else {
                        (void)(alg_invoke(v_fields, "Add", (Value[]){v_each}, 1));
                    }
                }
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVbegin, alg_add(alg_add(alg_string("Expect 'begin' before "), v_kind), alg_string(" body."))}, 2));
    (void)(alg_set_property(v_this, "InPrivateSection", alg_widen(alg_bool(false), "Boolean")));
    (void)((v_methods = alg_widen(alg_list(), "List")));
    while (alg_truthy((or_37 = alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1)), !alg_truthy(or_37) ? or_37 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
        {
            while (alg_truthy(alg_invoke(v_this, "MatchVisibility", NULL, 0))) {
                {
                }
            }
            if (alg_truthy((or_38 = alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVend}, 1), alg_truthy(or_38) ? or_38 : alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
                break;
            }
            Value v_method = alg_nil();
            (void)v_method;
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVconstructor}, 1))) {
                (void)((v_method = alg_widen(alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("constructor")}, 1), "Stmt")));
            } else {
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVprocedure}, 1))) {
                    (void)((v_method = alg_widen(alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("procedure")}, 1), "Stmt")));
                } else {
                    {
                        (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVfunction, alg_string("Expect 'function', 'procedure' or 'constructor' in class body.")}, 2));
                        (void)((v_method = alg_widen(alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("method")}, 1), "Stmt")));
                    }
                }
            }
            if (alg_truthy(alg_property(v_this, "InPrivateSection"))) {
                (void)(alg_invoke(alg_property(v_this, "ClassPrivates"), "Add", (Value[]){alg_str(alg_property(alg_property(v_method, "Name"), "Lexeme"))}, 1));
            }
            (void)(alg_invoke(v_methods, "Add", (Value[]){v_method}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVend, alg_add(alg_add(alg_string("Expect 'end' after "), v_kind), alg_string(" body."))}, 2));
    if (alg_truthy(alg_equal(v_kind, alg_string("object")))) {
        {
            Value v_theobject = alg_new(k_objectstmt, (Value[]){v_name, v_superclass, v_methods, v_fields}, 4);
            (void)v_theobject;
            (void)(alg_set_property(v_theobject, "PrivateMembers", alg_widen(alg_property(v_this, "ClassPrivates"), "List")));
            return v_theobject;
        }
    }
    Value v_theclass = alg_new(k_classstmt, (Value[]){v_name, v_superclass, v_methods, v_fields}, 4);
    (void)v_theclass;
    (void)(alg_set_property(v_theclass, "PrivateMembers", alg_widen(alg_property(v_this, "ClassPrivates"), "List")));
    return v_theclass;
    return alg_nil();
}

static Value m_parser_equality_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    Value v_operator = alg_nil();
    (void)v_operator;
    Value v_right = alg_nil();
    (void)v_right;
    (void)((v_theexpr = alg_widen(alg_invoke(v_this, "Comparison", NULL, 0), "Expr")));
    while (alg_truthy((or_39 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVnotVequal}, 1), alg_truthy(or_39) ? or_39 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVequal}, 1)))) {
        {
            (void)((v_operator = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
            (void)((v_right = alg_widen(alg_invoke(v_this, "Comparison", NULL, 0), "Expr")));
            (void)((v_theexpr = alg_widen(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_operator, v_right}, 3), "Expr")));
        }
    }
    return v_theexpr;
    return alg_nil();
}

static Value m_parser_comparison_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    Value v_operator = alg_nil();
    (void)v_operator;
    Value v_right = alg_nil();
    (void)v_right;
    (void)((v_theexpr = alg_widen(alg_invoke(v_this, "Term", NULL, 0), "Expr")));
    while (alg_truthy(alg_bool(true))) {
        {
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVis}, 1))) {
                {
                    (void)((v_theexpr = alg_widen(alg_new(k_isexpr, (Value[]){v_theexpr, alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect type name after 'is'.")}, 2)}, 2), "Expr")));
                }
            } else {
                if (alg_truthy((or_43 = (or_42 = (or_41 = (or_40 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVgreater}, 1), alg_truthy(or_40) ? or_40 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVgreaterVequal}, 1)), alg_truthy(or_41) ? or_41 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVless}, 1)), alg_truthy(or_42) ? or_42 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVlessVequal}, 1)), alg_truthy(or_43) ? or_43 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVin}, 1)))) {
                    {
                        (void)((v_operator = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
                        (void)((v_right = alg_widen(alg_invoke(v_this, "Term", NULL, 0), "Expr")));
                        (void)((v_theexpr = alg_widen(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_operator, v_right}, 3), "Expr")));
                    }
                } else {
                    return v_theexpr;
                }
            }
        }
    }
    return v_theexpr;
    return alg_nil();
}

static Value m_parser_term_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    Value v_operator = alg_nil();
    (void)v_operator;
    Value v_right = alg_nil();
    (void)v_right;
    (void)((v_theexpr = alg_widen(alg_invoke(v_this, "Factor", NULL, 0), "Expr")));
    while (alg_truthy((or_44 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVminus}, 1), alg_truthy(or_44) ? or_44 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVplus}, 1)))) {
        {
            (void)((v_operator = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
            (void)((v_right = alg_widen(alg_invoke(v_this, "Factor", NULL, 0), "Expr")));
            (void)((v_theexpr = alg_widen(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_operator, v_right}, 3), "Expr")));
        }
    }
    return v_theexpr;
    return alg_nil();
}

static Value m_parser_factor_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    Value v_operator = alg_nil();
    (void)v_operator;
    Value v_right = alg_nil();
    (void)v_right;
    (void)((v_theexpr = alg_widen(alg_invoke(v_this, "Unary", NULL, 0), "Expr")));
    while (alg_truthy((or_46 = (or_45 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVslash}, 1), alg_truthy(or_45) ? or_45 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVstar}, 1)), alg_truthy(or_46) ? or_46 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVdiv}, 1)))) {
        {
            (void)((v_operator = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
            (void)((v_right = alg_widen(alg_invoke(v_this, "Unary", NULL, 0), "Expr")));
            (void)((v_theexpr = alg_widen(alg_new(k_binaryexpr, (Value[]){v_theexpr, v_operator, v_right}, 3), "Expr")));
        }
    }
    return v_theexpr;
    return alg_nil();
}

static Value m_parser_unary_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_operator = alg_nil();
    (void)v_operator;
    Value v_right = alg_nil();
    (void)v_right;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    if (alg_truthy((or_47 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVnot}, 1), alg_truthy(or_47) ? or_47 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVminus}, 1)))) {
        {
            (void)((v_operator = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
            (void)((v_right = alg_widen(alg_invoke(v_this, "Unary", NULL, 0), "Expr")));
            return alg_new(k_unaryexpr, (Value[]){v_operator, v_right}, 2);
        }
    }
    (void)((v_theexpr = alg_widen(alg_invoke(v_this, "Call", NULL, 0), "Expr")));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVas}, 1))) {
        (void)(alg_set_property(v_theexpr, "Cast", alg_widen(f_canonicaltype(NULL, (Value[]){alg_property(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect typecast identifier.")}, 2), "Lexeme")}, 1), "String")));
    }
    return v_theexpr;
    return alg_nil();
}

static Value m_parser_collectionliteral_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_keys = alg_nil();
    (void)v_keys;
    Value v_values = alg_nil();
    (void)v_values;
    Value v_ismap = alg_nil();
    (void)v_ismap;
    (void)((v_keys = alg_widen(alg_list(), "List")));
    (void)((v_values = alg_widen(alg_list(), "List")));
    (void)((v_ismap = alg_widen(alg_bool(false), "Boolean")));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
        {
            (void)((v_ismap = alg_widen(alg_bool(true), "Boolean")));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVbracket, alg_string("Expect ']' after map.")}, 2));
            return alg_new(k_collectionexpr, (Value[]){alg_bool(true), v_keys, v_values}, 3);
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVrightVbracket}, 1))) {
        return alg_new(k_collectionexpr, (Value[]){alg_bool(false), v_keys, v_values}, 3);
    }
    Value v_first = alg_invoke(v_this, "Expression", NULL, 0);
    (void)v_first;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcolon}, 1))) {
        {
            (void)((v_ismap = alg_widen(alg_bool(true), "Boolean")));
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
    return alg_new(k_collectionexpr, (Value[]){v_ismap, v_keys, v_values}, 3);
    return alg_nil();
}

static Value m_parser_call_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    Value v_name = alg_nil();
    (void)v_name;
    (void)((v_theexpr = alg_widen(alg_invoke(v_this, "Primary", NULL, 0), "Expr")));
    while (alg_truthy(alg_bool(true))) {
        {
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVparen}, 1))) {
                (void)((v_theexpr = alg_widen(alg_invoke(v_this, "FinishCall", (Value[]){v_theexpr}, 1), "Expr")));
            } else {
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVbracket}, 1))) {
                    {
                        Value v_bracket = alg_invoke(v_this, "Previous", NULL, 0);
                        (void)v_bracket;
                        Value v_index = alg_invoke(v_this, "Expression", NULL, 0);
                        (void)v_index;
                        (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVbracket, alg_string("Expect ']' after subscript.")}, 2));
                        (void)((v_theexpr = alg_widen(alg_new(k_subscriptexpr, (Value[]){v_theexpr, v_index, v_bracket}, 3), "Expr")));
                    }
                } else {
                    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVdot}, 1))) {
                        {
                            (void)((v_name = alg_widen(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect property name after '.'.")}, 2), "Token")));
                            (void)((v_theexpr = alg_widen(alg_new(k_getexpr, (Value[]){v_theexpr, v_name}, 2), "Expr")));
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return v_theexpr;
    return alg_nil();
}

static Value m_parser_finishcall_1_expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_callee = alg_widen(args[0], "Expr");
    (void)v_callee;
    Value v_arguments = alg_nil();
    (void)v_arguments;
    Value v_paren = alg_nil();
    (void)v_paren;
    (void)((v_arguments = alg_widen(alg_list(), "List")));
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVrightVparen}, 1)))) {
        {
            (void)(alg_invoke(v_arguments, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
            while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVcomma}, 1))) {
                {
                    if (alg_truthy(alg_greater_equal(alg_property(v_arguments, "Length"), alg_int(255)))) {
                        alg_raise(alg_string("Can't have more than 255 arguments."));
                    }
                    (void)(alg_invoke(v_arguments, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
                }
            }
        }
    }
    (void)((v_paren = alg_widen(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_string("Expect ')' after arguments.")}, 2), "Token")));
    return alg_new(k_callexpr, (Value[]){v_callee, v_paren, v_arguments}, 3);
    return alg_nil();
}

static Value m_parser_primary_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_nil();
    (void)v_theexpr;
    Value v_keyword = alg_nil();
    (void)v_keyword;
    Value v_method = alg_nil();
    (void)v_method;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVfalse}, 1))) {
        return alg_new(k_literalexpr, (Value[]){alg_bool(false)}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVtrue}, 1))) {
        return alg_new(k_literalexpr, (Value[]){alg_bool(true)}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVnil}, 1))) {
        return alg_new(k_literalexpr, (Value[]){alg_nil()}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVbracket}, 1))) {
        return alg_invoke(v_this, "CollectionLiteral", NULL, 0);
    }
    if (alg_truthy((or_50 = (or_49 = (or_48 = alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVinteger}, 1), alg_truthy(or_48) ? or_48 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVnumber}, 1)), alg_truthy(or_49) ? or_49 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVstring}, 1)), alg_truthy(or_50) ? or_50 : alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVchar}, 1)))) {
        {
            return alg_new(k_literalexpr, (Value[]){alg_property(alg_invoke(v_this, "Previous", NULL, 0), "Literal")}, 1);
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVsuper}, 1))) {
        {
            (void)((v_keyword = alg_widen(alg_invoke(v_this, "Previous", NULL, 0), "Token")));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVdot, alg_string("Expect '.' after 'super'.")}, 2));
            (void)((v_method = alg_widen(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVidentifier, alg_string("Expect superclass method name.")}, 2), "Token")));
            return alg_new(k_superexpr, (Value[]){v_keyword, v_method}, 2);
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVthis}, 1))) {
        return alg_new(k_thisexpr, (Value[]){alg_invoke(v_this, "Previous", NULL, 0)}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVidentifier}, 1))) {
        {
            return alg_new(k_variableexpr, (Value[]){alg_invoke(v_this, "Previous", NULL, 0)}, 1);
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_tokentype_tokenVleftVparen}, 1))) {
        {
            (void)((v_theexpr = alg_widen(alg_invoke(v_this, "Expression", NULL, 0), "Expr")));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_tokentype_tokenVrightVparen, alg_string("Expect ')' after expression.")}, 2));
            return alg_new(k_groupingexpr, (Value[]){v_theexpr}, 1);
        }
    }
    alg_raise(alg_string("Expect expression!"));
    return alg_nil();
}

static Value m_parser_match_1_tokentype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thetype = alg_widen(args[0], "TokenType");
    (void)v_thetype;
    if (alg_truthy(alg_invoke(v_this, "Check", (Value[]){v_thetype}, 1))) {
        {
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            return alg_bool(true);
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value m_parser_error_2_token_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thetoken = alg_widen(args[0], "Token");
    (void)v_thetoken;
    Value v_message = alg_widen(args[1], "String");
    (void)v_message;
    (void)(alg_invoke(alg_singleton(k_console), "Error", (Value[]){v_thetoken, v_message}, 2));
    return v_message;
    return alg_nil();
}

static Value m_parser_consume_2_tokentype_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_typeoftoken = alg_widen(args[0], "TokenType");
    (void)v_typeoftoken;
    Value v_message = alg_widen(args[1], "String");
    (void)v_message;
    if (alg_truthy(alg_invoke(v_this, "Check", (Value[]){v_typeoftoken}, 1))) {
        return alg_invoke(v_this, "Advance", NULL, 0);
    }
    alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_invoke(v_this, "Previous", NULL, 0), v_message}, 2));
    return alg_nil();
}

static Value m_parser_check_1_tokentype(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thetype = alg_widen(args[0], "TokenType");
    (void)v_thetype;
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        return alg_bool(false);
    }
    return alg_equal(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "TypeOfToken"), v_thetype);
    return alg_nil();
}

static Value m_parser_checkword_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_word = alg_widen(args[0], "String");
    (void)v_word;
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_tokentype_tokenVidentifier}, 1)))) {
        return alg_bool(false);
    }
    return alg_equal(f_tolower(NULL, (Value[]){alg_str(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "Lexeme"))}, 1), v_word);
    return alg_nil();
}

static Value m_parser_advance_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        (void)(alg_set_property(v_this, "Current", alg_widen(alg_add(alg_property(v_this, "Current"), alg_int(1)), "Integer")));
    }
    return alg_invoke(v_this, "Previous", NULL, 0);
    return alg_nil();
}

static Value m_parser_isatend_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_equal(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "TypeOfToken"), e_tokentype_eof);
    return alg_nil();
}

static Value m_parser_peek_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_subscript_get(alg_property(v_this, "Tokens"), alg_property(v_this, "Current"));
    return alg_nil();
}

static Value m_parser_peeknext_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_greater_equal(alg_add(alg_property(v_this, "Current"), alg_int(1)), alg_property(alg_property(v_this, "Tokens"), "Length")))) {
        return alg_subscript_get(alg_property(v_this, "Tokens"), alg_subtract(alg_property(alg_property(v_this, "Tokens"), "Length"), alg_int(1)));
    }
    return alg_subscript_get(alg_property(v_this, "Tokens"), alg_add(alg_property(v_this, "Current"), alg_int(1)));
    return alg_nil();
}

static Value m_parser_previous_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_subscript_get(alg_property(v_this, "Tokens"), alg_subtract(alg_property(v_this, "Current"), alg_int(1)));
    return alg_nil();
}

void init_Parser(void) {
    k_parser = alg_class("Parser", alg_nil());
    fn_readwholefile = alg_closure("ReadWholeFile", f_readwholefile, NULL, 0, 1);
    alg_class_field(k_parser, "Tokens");
    alg_class_field(k_parser, "Current");
    alg_class_field(k_parser, "FileName");
    alg_class_field(k_parser, "Loaded");
    alg_class_field(k_parser, "PrivateNames");
    alg_class_field(k_parser, "InPrivateSection");
    alg_class_field(k_parser, "ClassPrivates");
    alg_class_field(k_parser, "LoopDepth");
    alg_class_field(k_parser, "InProcedure");
    alg_class_initializer(k_parser, i_parser);
    alg_class_method(k_parser, "Init", m_parser_init_1_list, 1, t_parser_init_1_list);
    alg_class_method(k_parser, "UnitHeader", m_parser_unitheader_0, 0, NULL);
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
    alg_class_method(k_parser, "DirectoryOf", m_parser_directoryof_1_string, 1, t_parser_directoryof_1_string);
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
    alg_class_method(k_parser, "RaiseStatement", m_parser_raisestatement_0, 0, NULL);
    alg_class_method(k_parser, "TryStatement", m_parser_trystatement_0, 0, NULL);
    alg_class_method(k_parser, "VarDeclaration", m_parser_vardeclaration_0, 0, NULL);
    alg_class_method(k_parser, "VarDeclaration", m_parser_vardeclaration_1_token, 1, t_parser_vardeclaration_1_token);
    alg_class_method(k_parser, "ExpressionStatement", m_parser_expressionstatement_0, 0, NULL);
    alg_class_method(k_parser, "ParseFunction", m_parser_parsefunction_1_string, 1, t_parser_parsefunction_1_string);
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
    alg_class_method(k_parser, "Term", m_parser_term_0, 0, NULL);
    alg_class_method(k_parser, "Factor", m_parser_factor_0, 0, NULL);
    alg_class_method(k_parser, "Unary", m_parser_unary_0, 0, NULL);
    alg_class_method(k_parser, "CollectionLiteral", m_parser_collectionliteral_0, 0, NULL);
    alg_class_method(k_parser, "Call", m_parser_call_0, 0, NULL);
    alg_class_method(k_parser, "FinishCall", m_parser_finishcall_1_expr, 1, t_parser_finishcall_1_expr);
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
}
