/* Generated from Algol-24.  Do not edit. */
#include "Parser.h"
#include "Console.h"
#include "Expr.h"
#include "Interpreter.h"
#include "Scanner.h"
#include "Stmt.h"
#include "Token.h"
#include "TokenType.h"

Value f_ReadWholeFile(Value **cells, Value *args, int32_t count);
Value fn_ReadWholeFile;
Value k_Parser;
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
static const char *t_Parser_Init_1_List[] = { "List" };
static const char *t_Parser_UnitStem_1_String[] = { "String" };
static const char *t_Parser_IsCollectionType_1_String[] = { "String" };
static const char *t_Parser_RecordPrivate_1[] = { "Any" };
static const char *t_Parser_DirectoryOf_1_String[] = { "String" };
static const char *t_Parser_ResolveModule_2_Token_String[] = { "Token", "String" };
static const char *t_Parser_DeclarationSection_1_Boolean[] = { "Boolean" };
static const char *t_Parser_ReadDeclarationSections_1_List[] = { "List" };
static const char *t_Parser_ReadDeclarationSections_2_List_Boolean[] = { "List", "Boolean" };
static const char *t_Parser_ForInStatement_1_Token[] = { "Token" };
static const char *t_Parser_VarDeclaration_1_Token[] = { "Token" };
static const char *t_Parser_ParseFunction_1_String[] = { "String" };
static const char *t_Parser_ClassDeclaration_1_String[] = { "String" };
static const char *t_Parser_FinishCall_1_Expr[] = { "Expr" };
static const char *t_Parser_Match_1_TokenType[] = { "TokenType" };
static const char *t_Parser_Error_2_Token_String[] = { "Token", "String" };
static const char *t_Parser_Consume_2_TokenType_String[] = { "TokenType", "String" };
static const char *t_Parser_Check_1_TokenType[] = { "TokenType" };
static const char *t_Parser_CheckWord_1_String[] = { "String" };

Value f_ReadWholeFile(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_F = alg_text_file();
    (void)v_F;
    (void)(alg_invoke(v_F, "Assign", (Value[]){v_Name}, 1));
    (void)(alg_invoke(v_F, "Reset", NULL, 0));
    Value v_Result = alg_buffer(alg_int(0));
    (void)v_Result;
    while (alg_truthy(alg_not(alg_property(v_F, "Eof")))) {
        {
            (void)(alg_invoke(v_Result, "Append", (Value[]){alg_invoke(v_F, "ReadLn", NULL, 0)}, 1));
            (void)(alg_invoke(v_Result, "Append", (Value[]){alg_char_value(10)}, 1));
        }
    }
    (void)(alg_invoke(v_F, "Close", NULL, 0));
    return alg_property(v_Result, "Text");
    return alg_nil();
}

static Value i_Parser(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Tokens", alg_nil());
    alg_set_property(v_this, "Current", alg_nil());
    alg_set_property(v_this, "FileName", alg_string(""));
    alg_set_property(v_this, "Loaded", alg_map());
    alg_set_property(v_this, "PrivateNames", alg_list());
    alg_set_property(v_this, "InPrivateSection", alg_bool(false));
    alg_set_property(v_this, "ClassPrivates", alg_list());
    alg_set_property(v_this, "LoopDepth", alg_int(0));
    alg_set_property(v_this, "InProcedure", alg_bool(false));
    return alg_nil();
}

static Value m_Parser_Init_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Tokens = args[0];
    (void)v_Tokens;
    (void)(alg_set_property(v_this, "Tokens", v_Tokens));
    (void)(alg_set_property(v_this, "Current", alg_int(0)));
    return alg_nil();
}

static Value m_Parser_UnitHeader_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_IDENTIFIER}, 1)))) {
        return alg_nil();
    }
    if (alg_truthy(alg_not_equal(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "Lexeme"), alg_string("unit")))) {
        return alg_nil();
    }
    if (alg_truthy(alg_not_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_TokenType_TOKEN_IDENTIFIER))) {
        return alg_nil();
    }
    (void)(alg_invoke(v_this, "Advance", NULL, 0));
    Value v_Name = alg_invoke(v_this, "Advance", NULL, 0);
    (void)v_Name;
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_string("Expect ';' after unit name.")}, 2));
    Value v_Expected = alg_invoke(v_this, "UnitStem", (Value[]){alg_property(v_this, "FileName")}, 1);
    (void)v_Expected;
    if (alg_truthy((or_0 = alg_equal(v_Expected, alg_string("")), alg_truthy(or_0) ? or_0 : alg_equal(v_Expected, alg_string("REPL"))))) {
        return alg_nil();
    }
    if (alg_truthy(alg_not_equal(v_Expected, alg_str(alg_property(v_Name, "Lexeme"))))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_Name, alg_add(alg_add(alg_add(alg_add(alg_string("Unit '"), alg_str(alg_property(v_Name, "Lexeme"))), alg_string("' must match its file name '")), v_Expected), alg_string("'."))}, 2));
    }
    return alg_nil();
}

static Value m_Parser_UnitStem_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Key = args[0];
    (void)v_Key;
    Value v_Stem = alg_nil();
    (void)v_Stem;
    (void)((v_Stem = v_Key));
    {
        Value v_I = alg_subtract(alg_length(v_Key), alg_int(1));
        (void)v_I;
        while (alg_truthy(alg_greater_equal(v_I, alg_int(0)))) {
            {
                if (alg_truthy((or_1 = alg_equal(alg_subscript_get(v_Key, v_I), alg_char_value(47)), alg_truthy(or_1) ? or_1 : alg_equal(alg_subscript_get(v_Key, v_I), alg_char_value(92))))) {
                    {
                        (void)((v_Stem = alg_copy(v_Key, alg_add(v_I, alg_int(1)), alg_subtract(alg_subtract(alg_length(v_Key), v_I), alg_int(1)))));
                        (void)((v_I = alg_negate(alg_int(1))));
                    }
                }
                (void)((v_I = alg_subtract(v_I, alg_int(1))));
            }
        }
    }
    if (alg_truthy((or_2 = alg_greater(alg_length(v_Stem), alg_int(4)), !alg_truthy(or_2) ? or_2 : alg_equal(alg_copy(v_Stem, alg_subtract(alg_length(v_Stem), alg_int(4)), alg_int(4)), alg_string(".a24"))))) {
        return alg_copy(v_Stem, alg_int(0), alg_subtract(alg_length(v_Stem), alg_int(4)));
    }
    return v_Stem;
    return alg_nil();
}

static Value m_Parser_Parse_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = alg_nil();
    (void)v_Statements;
    (void)((v_Statements = alg_list()));
    if (alg_truthy(alg_not_equal(alg_property(v_this, "FileName"), alg_string("")))) {
        (void)(alg_invoke(alg_property(v_this, "Loaded"), "Put", (Value[]){alg_property(v_this, "FileName"), alg_bool(true)}, 2));
    }
    (void)(alg_invoke(v_this, "UnitHeader", NULL, 0));
    while (alg_truthy(alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        {
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_USES}, 1))) {
                {
                    Value v_TheModule = alg_invoke(v_this, "UsesStatement", NULL, 0);
                    (void)v_TheModule;
                    if (alg_truthy(alg_not_equal(v_TheModule, alg_nil()))) {
                        (void)(alg_invoke(v_Statements, "Add", (Value[]){v_TheModule}, 1));
                    }
                }
            } else {
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_PRIVATE}, 1))) {
                    {
                        Value v_Decl = alg_invoke(v_this, "Declaration", NULL, 0);
                        (void)v_Decl;
                        (void)(alg_invoke(v_this, "RecordPrivate", (Value[]){v_Decl}, 1));
                        (void)(alg_invoke(v_Statements, "Add", (Value[]){v_Decl}, 1));
                    }
                } else {
                    (void)(alg_invoke(v_Statements, "Add", (Value[]){alg_invoke(v_this, "Declaration", NULL, 0)}, 1));
                }
            }
        }
    }
    return v_Statements;
    return alg_nil();
}

static Value m_Parser_Statement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_TYPE}, 1))) {
        return alg_invoke(v_this, "EnumDeclaration", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_CLASS}, 1))) {
        return alg_invoke(v_this, "ClassDeclaration", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_OBJECT}, 1))) {
        return alg_invoke(v_this, "ClassDeclaration", (Value[]){alg_string("object")}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_FUNCTION}, 1))) {
        return alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("function")}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_PROCEDURE}, 1))) {
        return alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("procedure")}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_VAR}, 1))) {
        return alg_invoke(v_this, "VarDeclaration", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_CONST}, 1))) {
        return alg_invoke(v_this, "ConstDeclaration", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_CASE}, 1))) {
        return alg_invoke(v_this, "CaseStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_IF}, 1))) {
        return alg_invoke(v_this, "IfStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_WHILE}, 1))) {
        return alg_invoke(v_this, "WhileStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_FOR}, 1))) {
        return alg_invoke(v_this, "ForStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_EXIT}, 1))) {
        return alg_invoke(v_this, "ReturnStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_TRY}, 1))) {
        return alg_invoke(v_this, "TryStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_BREAK}, 1))) {
        return alg_invoke(v_this, "BreakStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_RAISE}, 1))) {
        return alg_invoke(v_this, "RaiseStatement", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_PRINT}, 1))) {
        return alg_invoke(v_this, "PrintStatment", NULL, 0);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_BEGIN}, 1))) {
        return alg_new(k_BlockStmt, (Value[]){alg_invoke(v_this, "Block", NULL, 0)}, 1);
    }
    return alg_invoke(v_this, "ExpressionStatement", NULL, 0);
    return alg_nil();
}

static Value m_Parser_CaseStatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Left = alg_nil();
    (void)v_Left;
    Value v_Top = alg_nil();
    (void)v_Top;
    Value v_Current = alg_nil();
    (void)v_Current;
    Value v_Condition = alg_nil();
    (void)v_Condition;
    Value v_Branch = alg_nil();
    (void)v_Branch;
    (void)((v_Left = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_OF, alg_string("Expect 'of' after case condition.")}, 2));
    (void)((v_Top = alg_nil()));
    (void)((v_Current = alg_nil()));
    while (alg_truthy(alg_bool(true))) {
        {
            (void)((v_Condition = alg_new(k_BinaryExpr, (Value[]){v_Left, alg_invoke(v_this, "Equals", NULL, 0), alg_invoke(v_this, "Expression", NULL, 0)}, 3)));
            while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COMMA}, 1))) {
                (void)((v_Condition = alg_new(k_LogicalExpr, (Value[]){v_Condition, alg_invoke(v_this, "Either", NULL, 0), alg_new(k_BinaryExpr, (Value[]){v_Left, alg_invoke(v_this, "Equals", NULL, 0), alg_invoke(v_this, "Expression", NULL, 0)}, 3)}, 3)));
            }
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_COLON, alg_string("Expect ':' after condition.")}, 2));
            (void)((v_Branch = alg_new(k_IfStmt, (Value[]){v_Condition, alg_invoke(v_this, "Statement", NULL, 0), alg_nil()}, 3)));
            if (alg_truthy(alg_equal(v_Top, alg_nil()))) {
                (void)((v_Top = v_Branch));
            } else {
                (void)(alg_set_property(v_Current, "ElseBranch", v_Branch));
            }
            (void)((v_Current = v_Branch));
            if (alg_truthy((or_3 = alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_ELSE}, 1), alg_truthy(or_3) ? or_3 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_END}, 1)))) {
                break;
            }
        }
    }
    if (alg_truthy(alg_equal(alg_property(alg_invoke(v_this, "Previous", NULL, 0), "TypeOfToken"), e_TokenType_TOKEN_ELSE))) {
        {
            (void)(alg_set_property(v_Current, "ElseBranch", alg_invoke(v_this, "BodyStatement", NULL, 0)));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_END, alg_string("Expected 'end'.")}, 2));
        }
    }
    return v_Top;
    return alg_nil();
}

static Value m_Parser_Equals_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_new(k_Token, (Value[]){e_TokenType_TOKEN_EQUAL, alg_char_value(61), alg_nil(), alg_property(alg_invoke(v_this, "Previous", NULL, 0), "LineNumber")}, 4);
    return alg_nil();
}

static Value m_Parser_Either_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_new(k_Token, (Value[]){e_TokenType_TOKEN_OR, alg_string("or"), alg_nil(), alg_property(alg_invoke(v_this, "Previous", NULL, 0), "LineNumber")}, 4);
    return alg_nil();
}

static Value m_Parser_BodyStatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy((or_9 = (or_8 = (or_7 = (or_6 = (or_5 = (or_4 = alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_VAR}, 1), alg_truthy(or_4) ? or_4 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_CONST}, 1)), alg_truthy(or_5) ? or_5 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_TYPE}, 1)), alg_truthy(or_6) ? or_6 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_CLASS}, 1)), alg_truthy(or_7) ? or_7 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_OBJECT}, 1)), alg_truthy(or_8) ? or_8 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_FUNCTION}, 1)), alg_truthy(or_9) ? or_9 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_PROCEDURE}, 1)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_invoke(v_this, "Peek", NULL, 0), alg_string("A declaration cannot be a branch or loop body; use 'begin' ... 'end'.")}, 2));
    }
    return alg_invoke(v_this, "Statement", NULL, 0);
    return alg_nil();
}

static Value m_Parser_IsCollectionType_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TypeName = args[0];
    (void)v_TypeName;
    Value v_Lowered = alg_nil();
    (void)v_Lowered;
    (void)((v_Lowered = f_ToLower(NULL, (Value[]){v_TypeName}, 1)));
    return (or_13 = (or_12 = (or_11 = (or_10 = alg_equal(v_Lowered, alg_string("list")), alg_truthy(or_10) ? or_10 : alg_equal(v_Lowered, alg_string("map"))), alg_truthy(or_11) ? or_11 : alg_equal(v_Lowered, alg_string("set"))), alg_truthy(or_12) ? or_12 : alg_equal(v_Lowered, alg_string("stack"))), alg_truthy(or_13) ? or_13 : alg_equal(v_Lowered, alg_string("array")));
    return alg_nil();
}

static Value m_Parser_IfStatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Condition = alg_nil();
    (void)v_Condition;
    Value v_ThenBranch = alg_nil();
    (void)v_ThenBranch;
    Value v_ElseBranch = alg_nil();
    (void)v_ElseBranch;
    (void)((v_Condition = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_THEN, alg_string("Expect 'then' after if condition.")}, 2));
    (void)((v_ThenBranch = alg_invoke(v_this, "BodyStatement", NULL, 0)));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_ELSE}, 1))) {
        {
            (void)((v_ElseBranch = alg_invoke(v_this, "BodyStatement", NULL, 0)));
        }
    }
    return alg_new(k_IfStmt, (Value[]){v_Condition, v_ThenBranch, v_ElseBranch}, 3);
    return alg_nil();
}

static Value m_Parser_ForStatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Initializer = alg_nil();
    (void)v_Initializer;
    Value v_Increment = alg_nil();
    (void)v_Increment;
    Value v_Condition = alg_nil();
    (void)v_Condition;
    Value v_Body = alg_nil();
    (void)v_Body;
    Value v_StmtList = alg_nil();
    (void)v_StmtList;
    Value v_WhileList = alg_nil();
    (void)v_WhileList;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_SEMICOLON}, 1))) {
        (void)((v_Initializer = alg_nil()));
    } else {
        if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_VAR}, 1))) {
            {
                Value v_Name = alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect variable name.")}, 2);
                (void)v_Name;
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_IN}, 1))) {
                    return alg_invoke(v_this, "ForInStatement", (Value[]){v_Name}, 1);
                }
                (void)((v_Initializer = alg_invoke(v_this, "VarDeclaration", (Value[]){v_Name}, 1)));
            }
        } else {
            (void)((v_Initializer = alg_invoke(v_this, "ExpressionStatement", NULL, 0)));
        }
    }
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_SEMICOLON}, 1)))) {
        {
            (void)((v_Condition = alg_invoke(v_this, "Expression", NULL, 0)));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_string("Expect ';' after loop condition")}, 2));
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_DO}, 1)))) {
        {
            (void)((v_Increment = alg_invoke(v_this, "Expression", NULL, 0)));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_DO, alg_string("Expect 'do' after for clauses.")}, 2));
    (void)(alg_set_property(v_this, "LoopDepth", alg_add(alg_property(v_this, "LoopDepth"), alg_int(1))));
    (void)((v_Body = alg_invoke(v_this, "BodyStatement", NULL, 0)));
    (void)(alg_set_property(v_this, "LoopDepth", alg_subtract(alg_property(v_this, "LoopDepth"), alg_int(1))));
    if (alg_truthy(alg_not_equal(v_Increment, alg_nil()))) {
        {
            (void)((v_StmtList = alg_list()));
            (void)(alg_invoke(v_StmtList, "Add", (Value[]){v_Body}, 1));
            (void)(alg_invoke(v_StmtList, "Add", (Value[]){alg_new(k_ExpressionStmt, (Value[]){v_Increment}, 1)}, 1));
            (void)((v_Body = alg_new(k_BlockStmt, (Value[]){v_StmtList}, 1)));
        }
    }
    if (alg_truthy(alg_equal(v_Condition, alg_nil()))) {
        (void)((v_Condition = alg_new(k_LiteralExpr, (Value[]){alg_bool(true)}, 1)));
    }
    (void)((v_Body = alg_new(k_WhileStmt, (Value[]){v_Condition, v_Body}, 2)));
    if (alg_truthy(alg_not_equal(v_Initializer, alg_nil()))) {
        {
            (void)((v_WhileList = alg_list()));
            (void)(alg_invoke(v_WhileList, "Add", (Value[]){v_Initializer}, 1));
            (void)(alg_invoke(v_WhileList, "Add", (Value[]){v_Body}, 1));
            (void)((v_Body = alg_new(k_BlockStmt, (Value[]){v_WhileList}, 1)));
        }
    }
    return v_Body;
    return alg_nil();
}

static Value m_Parser_WhileStatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Condition = alg_nil();
    (void)v_Condition;
    Value v_Body = alg_nil();
    (void)v_Body;
    (void)((v_Condition = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_DO, alg_string("Expect 'do' after condition.")}, 2));
    (void)(alg_set_property(v_this, "LoopDepth", alg_add(alg_property(v_this, "LoopDepth"), alg_int(1))));
    (void)((v_Body = alg_invoke(v_this, "BodyStatement", NULL, 0)));
    (void)(alg_set_property(v_this, "LoopDepth", alg_subtract(alg_property(v_this, "LoopDepth"), alg_int(1))));
    return alg_new(k_WhileStmt, (Value[]){v_Condition, v_Body}, 2);
    return alg_nil();
}

static Value m_Parser_PrintStatment_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Value = alg_nil();
    (void)v_Value;
    (void)((v_Value = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_string("Expect ';' after value.")}, 2));
    return alg_new(k_PrintStmt, (Value[]){v_Value}, 1);
    return alg_nil();
}

static Value m_Parser_ReturnStatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Keyword = alg_nil();
    (void)v_Keyword;
    Value v_Value = alg_nil();
    (void)v_Value;
    (void)((v_Keyword = alg_invoke(v_this, "Previous", NULL, 0)));
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_SEMICOLON}, 1)))) {
        {
            if (alg_truthy(alg_property(v_this, "InProcedure"))) {
                alg_raise(alg_invoke(v_this, "Error", (Value[]){v_Keyword, alg_string("A procedure cannot exit a value.")}, 2));
            }
            (void)((v_Value = alg_invoke(v_this, "Expression", NULL, 0)));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_string("Expect ';' after exit value.")}, 2));
    return alg_new(k_ReturnStmt, (Value[]){v_Keyword, v_Value}, 2);
    return alg_nil();
}

static Value m_Parser_RecordPrivate_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Decl = args[0];
    (void)v_Decl;
    if (alg_truthy((or_16 = (or_15 = (or_14 = alg_is(v_Decl, "FunctionStmt"), alg_truthy(or_14) ? or_14 : alg_is(v_Decl, "ClassStmt")), alg_truthy(or_15) ? or_15 : alg_is(v_Decl, "ObjectStmt")), alg_truthy(or_16) ? or_16 : alg_is(v_Decl, "VarStmt")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_str(alg_property(alg_property(v_Decl, "Name"), "Lexeme"))}, 1));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_is(v_Decl, "VarGroupStmt"))) {
        {
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_Decl, "Names"), "Length")))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_Decl, "Names"), v_I), "Lexeme"))}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_is(v_Decl, "EnumStmt"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_str(alg_property(alg_property(v_Decl, "Name"), "Lexeme"))}, 1));
            {
                Value v_I = alg_int(0);
                (void)v_I;
                while (alg_truthy(alg_less(v_I, alg_property(alg_property(v_Decl, "Members"), "Length")))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "PrivateNames"), "Add", (Value[]){alg_str(alg_property(alg_subscript_get(alg_property(v_Decl, "Members"), v_I), "Lexeme"))}, 1));
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            return alg_nil();
        }
    }
    alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_invoke(v_this, "Previous", NULL, 0), alg_string("'private' must precede a declaration.")}, 2));
    return alg_nil();
}

static Value m_Parser_DirectoryOf_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Path = args[0];
    (void)v_Path;
    Value v_Cut = alg_negate(alg_int(1));
    (void)v_Cut;
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_length(v_Path)))) {
            {
                if (alg_truthy(alg_equal(alg_subscript_get(v_Path, v_I), alg_char_value(47)))) {
                    (void)((v_Cut = v_I));
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    if (alg_truthy(alg_less(v_Cut, alg_int(0)))) {
        return alg_string("");
    }
    return alg_copy(v_Path, alg_int(0), v_Cut);
    return alg_nil();
}

static Value m_Parser_ResolveModule_2_Token_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Where = args[0];
    (void)v_Where;
    Value v_ModuleName = args[1];
    (void)v_ModuleName;
    Value v_TheFile = alg_nil();
    (void)v_TheFile;
    Value v_Dir = alg_nil();
    (void)v_Dir;
    (void)((v_TheFile = alg_add(v_ModuleName, alg_string(".a24"))));
    (void)((v_Dir = alg_invoke(v_this, "DirectoryOf", (Value[]){alg_property(v_this, "FileName")}, 1)));
    if (alg_truthy(alg_not_equal(v_Dir, alg_string("")))) {
        {
            Value v_Beside = alg_add(alg_add(v_Dir, alg_char_value(47)), v_TheFile);
            (void)v_Beside;
            if (alg_truthy(alg_file_exists(v_Beside))) {
                return v_Beside;
            }
        }
    }
    if (alg_truthy(alg_file_exists(v_TheFile))) {
        return v_TheFile;
    }
    Value v_Searched = alg_string("the working directory");
    (void)v_Searched;
    if (alg_truthy(alg_not_equal(v_Dir, alg_string("")))) {
        (void)((v_Searched = alg_add(alg_add(alg_char_value(39), v_Dir), alg_string("' or the working directory"))));
    }
    alg_raise(alg_invoke(v_this, "Error", (Value[]){v_Where, alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("Could not find module '"), v_ModuleName), alg_string("': no ")), v_TheFile), alg_string(" in ")), v_Searched), alg_char_value(46))}, 2));
    return alg_nil();
}

static Value m_Parser_UsesStatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_ModuleName = alg_nil();
    (void)v_ModuleName;
    Value v_Where = alg_nil();
    (void)v_Where;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_STRING}, 1))) {
        (void)((v_ModuleName = alg_str(alg_property(alg_invoke(v_this, "Previous", NULL, 0), "Literal"))));
    } else {
        (void)((v_ModuleName = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expected identifier.")}, 2), "Lexeme"))));
    }
    (void)((v_Where = alg_invoke(v_this, "Previous", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_string("Expected ';'")}, 2));
    Value v_Path = alg_invoke(v_this, "ResolveModule", (Value[]){v_Where, v_ModuleName}, 2);
    (void)v_Path;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Loaded"), "Contains", (Value[]){v_Path}, 1))) {
        {
            Value v_Seen = alg_new(k_ModuleStmt, (Value[]){v_Where, alg_nil(), alg_list()}, 3);
            (void)v_Seen;
            (void)(alg_set_property(v_Seen, "FileName", v_Path));
            (void)(alg_set_property(v_Seen, "UnitName", alg_invoke(v_this, "UnitStem", (Value[]){v_Path}, 1)));
            return v_Seen;
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Loaded"), "Put", (Value[]){v_Path, alg_bool(true)}, 2));
    Value v_SubScanner = alg_new(k_Scanner, (Value[]){f_ReadWholeFile(NULL, (Value[]){v_Path}, 1)}, 1);
    (void)v_SubScanner;
    Value v_SubParser = alg_new(k_Parser, (Value[]){alg_invoke(v_SubScanner, "ScanTokens", NULL, 0)}, 1);
    (void)v_SubParser;
    (void)(alg_set_property(v_SubParser, "FileName", v_Path));
    (void)(alg_set_property(v_SubParser, "Loaded", alg_property(v_this, "Loaded")));
    Value v_Result = alg_invoke(v_SubParser, "Parse", NULL, 0);
    (void)v_Result;
    Value v_TheModule = alg_new(k_ModuleStmt, (Value[]){v_Where, v_Result, alg_property(v_SubParser, "PrivateNames")}, 3);
    (void)v_TheModule;
    (void)(alg_set_property(v_TheModule, "FileName", v_Path));
    (void)(alg_set_property(v_TheModule, "UnitName", alg_invoke(v_this, "UnitStem", (Value[]){v_Path}, 1)));
    return v_TheModule;
    return alg_nil();
}

static Value m_Parser_ConstDeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = alg_nil();
    (void)v_Name;
    (void)((v_Name = alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect constant name.")}, 2)));
    Value v_TypeName = alg_string("");
    (void)v_TypeName;
    Value v_Generic = alg_string("");
    (void)v_Generic;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COLON}, 1))) {
        {
            (void)((v_TypeName = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect type name.")}, 2), "Lexeme"))));
            if (alg_truthy((or_17 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_TypeName}, 1), !alg_truthy(or_17) ? or_17 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_OF}, 1)))) {
                (void)((v_Generic = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect generic type.")}, 2), "Lexeme"))));
            }
        }
    }
    if (alg_truthy(alg_not(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_ASSIGN}, 1)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_Name, alg_string("A constant must be given a value.")}, 2));
    }
    Value v_Initializer = alg_invoke(v_this, "Expression", NULL, 0);
    (void)v_Initializer;
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_string("Expect ';' after constant declaration.")}, 2));
    Value v_TheVar = alg_new(k_VarStmt, (Value[]){v_Name, v_Initializer}, 2);
    (void)v_TheVar;
    (void)(alg_set_property(v_TheVar, "TypeName", v_TypeName));
    (void)(alg_set_property(v_TheVar, "Generic", v_Generic));
    (void)(alg_set_property(v_TheVar, "IsConstant", alg_bool(true)));
    return v_TheVar;
    return alg_nil();
}

static Value m_Parser_MatchVisibility_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy((or_18 = alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_PRIVATE}, 1), !alg_truthy(or_18) ? or_18 : alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_TokenType_TOKEN_COLON)))) {
        {
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_set_property(v_this, "InPrivateSection", alg_bool(true)));
            return alg_bool(true);
        }
    }
    if (alg_truthy((or_19 = alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_PUBLIC}, 1), !alg_truthy(or_19) ? or_19 : alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_TokenType_TOKEN_COLON)))) {
        {
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)(alg_set_property(v_this, "InPrivateSection", alg_bool(false)));
            return alg_bool(true);
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value m_Parser_IsDeclarationSection_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return (or_21 = (or_20 = alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_VAR}, 1), alg_truthy(or_20) ? or_20 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_CONST}, 1)), alg_truthy(or_21) ? or_21 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_TYPE}, 1));
    return alg_nil();
}

static Value m_Parser_IsNextSection_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        return alg_bool(true);
    }
    return (or_28 = (or_27 = (or_26 = (or_25 = (or_24 = (or_23 = (or_22 = alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_END}, 1), alg_truthy(or_22) ? or_22 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_BEGIN}, 1)), alg_truthy(or_23) ? or_23 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_FUNCTION}, 1)), alg_truthy(or_24) ? or_24 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_PROCEDURE}, 1)), alg_truthy(or_25) ? or_25 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_CONSTRUCTOR}, 1)), alg_truthy(or_26) ? or_26 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_VAR}, 1)), alg_truthy(or_27) ? or_27 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_CONST}, 1)), alg_truthy(or_28) ? or_28 : alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_TYPE}, 1));
    return alg_nil();
}

static Value m_Parser_DeclarationSection_1_Boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_IsConstant = args[0];
    (void)v_IsConstant;
    Value v_Stmts = alg_nil();
    (void)v_Stmts;
    Value v_Noun = alg_nil();
    (void)v_Noun;
    (void)((v_Stmts = alg_list()));
    (void)((v_Noun = alg_string("variable")));
    if (alg_truthy(v_IsConstant)) {
        (void)((v_Noun = alg_string("constant")));
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
            Value v_Names = alg_list();
            (void)v_Names;
            (void)(alg_invoke(v_Names, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_add(alg_add(alg_string("Expect "), v_Noun), alg_string(" name."))}, 2)}, 1));
            while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COMMA}, 1))) {
                (void)(alg_invoke(v_Names, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_add(alg_add(alg_string("Expect "), v_Noun), alg_string(" name."))}, 2)}, 1));
            }
            if (alg_truthy(alg_property(v_this, "InPrivateSection"))) {
                {
                    Value v_I = alg_int(0);
                    (void)v_I;
                    while (alg_truthy(alg_less(v_I, alg_property(v_Names, "Length")))) {
                        {
                            (void)(alg_invoke(alg_property(v_this, "ClassPrivates"), "Add", (Value[]){alg_str(alg_property(alg_subscript_get(v_Names, v_I), "Lexeme"))}, 1));
                            (void)((v_I = alg_add(v_I, alg_int(1))));
                        }
                    }
                }
            }
            Value v_TypeName = alg_string("");
            (void)v_TypeName;
            Value v_Generic = alg_string("");
            (void)v_Generic;
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COLON}, 1))) {
                {
                    (void)((v_TypeName = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect type name.")}, 2), "Lexeme"))));
                    if (alg_truthy((or_29 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_TypeName}, 1), !alg_truthy(or_29) ? or_29 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_OF}, 1)))) {
                        (void)((v_Generic = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect generic type.")}, 2), "Lexeme"))));
                    }
                }
            }
            Value v_Initializer = alg_nil();
            (void)v_Initializer;
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_ASSIGN}, 1))) {
                (void)((v_Initializer = alg_invoke(v_this, "Expression", NULL, 0)));
            } else {
                if (alg_truthy(v_IsConstant)) {
                    alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_subscript_get(v_Names, alg_int(0)), alg_string("A constant must be given a value.")}, 2));
                }
            }
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_add(alg_add(alg_string("Expect ';' after "), v_Noun), alg_string(" declaration."))}, 2));
            if (alg_truthy(alg_equal(alg_property(v_Names, "Length"), alg_int(1)))) {
                {
                    Value v_TheVar = alg_new(k_VarStmt, (Value[]){alg_subscript_get(v_Names, alg_int(0)), v_Initializer}, 2);
                    (void)v_TheVar;
                    (void)(alg_set_property(v_TheVar, "TypeName", v_TypeName));
                    (void)(alg_set_property(v_TheVar, "Generic", v_Generic));
                    (void)(alg_set_property(v_TheVar, "IsConstant", v_IsConstant));
                    (void)(alg_invoke(v_Stmts, "Add", (Value[]){v_TheVar}, 1));
                }
            } else {
                {
                    Value v_TheGroup = alg_new(k_VarGroupStmt, (Value[]){v_Names, v_Initializer}, 2);
                    (void)v_TheGroup;
                    (void)(alg_set_property(v_TheGroup, "TypeName", v_TypeName));
                    (void)(alg_set_property(v_TheGroup, "Generic", v_Generic));
                    (void)(alg_set_property(v_TheGroup, "IsConstant", v_IsConstant));
                    (void)(alg_invoke(v_Stmts, "Add", (Value[]){v_TheGroup}, 1));
                }
            }
        }
    }
    return v_Stmts;
    return alg_nil();
}

static Value m_Parser_ReadDeclarationSections_1_List(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Body = args[0];
    (void)v_Body;
    (void)(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_Body, alg_bool(false)}, 2));
    return alg_nil();
}

static Value m_Parser_ReadDeclarationSections_2_List_Boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Body = args[0];
    (void)v_Body;
    Value v_AllowVisibility = args[1];
    (void)v_AllowVisibility;
    while (alg_truthy(alg_bool(true))) {
        {
            if (alg_truthy(v_AllowVisibility)) {
                while (alg_truthy(alg_invoke(v_this, "MatchVisibility", NULL, 0))) {
                    {
                    }
                }
            }
            if (alg_truthy(alg_not(alg_invoke(v_this, "IsDeclarationSection", NULL, 0)))) {
                break;
            }
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_VAR}, 1))) {
                {
                    Value v_Section = alg_invoke(v_this, "DeclarationSection", (Value[]){alg_bool(false)}, 1);
                    (void)v_Section;
                    {
                        Value v_I = alg_int(0);
                        (void)v_I;
                        while (alg_truthy(alg_less(v_I, alg_property(v_Section, "Length")))) {
                            {
                                (void)(alg_invoke(v_Body, "Add", (Value[]){alg_subscript_get(v_Section, v_I)}, 1));
                                (void)((v_I = alg_add(v_I, alg_int(1))));
                            }
                        }
                    }
                }
            } else {
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_CONST}, 1))) {
                    {
                        Value v_Section = alg_invoke(v_this, "DeclarationSection", (Value[]){alg_bool(true)}, 1);
                        (void)v_Section;
                        {
                            Value v_I = alg_int(0);
                            (void)v_I;
                            while (alg_truthy(alg_less(v_I, alg_property(v_Section, "Length")))) {
                                {
                                    (void)(alg_invoke(v_Body, "Add", (Value[]){alg_subscript_get(v_Section, v_I)}, 1));
                                    (void)((v_I = alg_add(v_I, alg_int(1))));
                                }
                            }
                        }
                    }
                } else {
                    {
                        (void)(alg_invoke(v_this, "Advance", NULL, 0));
                        while (alg_truthy(alg_not(alg_invoke(v_this, "IsNextSection", NULL, 0)))) {
                            (void)(alg_invoke(v_Body, "Add", (Value[]){alg_invoke(v_this, "EnumDeclaration", NULL, 0)}, 1));
                        }
                    }
                }
            }
        }
    }
    return alg_nil();
}

static Value m_Parser_ForInStatement_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Iterable = alg_nil();
    (void)v_Iterable;
    Value v_Body = alg_nil();
    (void)v_Body;
    (void)((v_Iterable = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_DO, alg_string("Expect 'do' after 'for ... in' clause.")}, 2));
    (void)(alg_set_property(v_this, "LoopDepth", alg_add(alg_property(v_this, "LoopDepth"), alg_int(1))));
    (void)((v_Body = alg_invoke(v_this, "BodyStatement", NULL, 0)));
    (void)(alg_set_property(v_this, "LoopDepth", alg_subtract(alg_property(v_this, "LoopDepth"), alg_int(1))));
    return alg_new(k_ForInStmt, (Value[]){v_Name, v_Iterable, v_Body}, 3);
    return alg_nil();
}

static Value m_Parser_BreakStatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Keyword = alg_nil();
    (void)v_Keyword;
    (void)((v_Keyword = alg_invoke(v_this, "Previous", NULL, 0)));
    if (alg_truthy(alg_equal(alg_property(v_this, "LoopDepth"), alg_int(0)))) {
        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_Keyword, alg_string("Must be inside a loop to use 'break'.")}, 2));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_string("Expect ';' after 'break'.")}, 2));
    return alg_new(k_BreakStmt, (Value[]){v_Keyword}, 1);
    return alg_nil();
}

static Value m_Parser_RaiseStatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Keyword = alg_nil();
    (void)v_Keyword;
    Value v_Value = alg_nil();
    (void)v_Value;
    (void)((v_Keyword = alg_invoke(v_this, "Previous", NULL, 0)));
    (void)((v_Value = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_string("Expect ';' after raised value.")}, 2));
    return alg_new(k_RaiseStmt, (Value[]){v_Keyword, v_Value}, 2);
    return alg_nil();
}

static Value m_Parser_TryStatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = alg_nil();
    (void)v_Statements;
    Value v_Handlers = alg_nil();
    (void)v_Handlers;
    Value v_HasHandlers = alg_nil();
    (void)v_HasHandlers;
    Value v_Variable = alg_nil();
    (void)v_Variable;
    Value v_TheType = alg_nil();
    (void)v_TheType;
    Value v_Key = alg_nil();
    (void)v_Key;
    Value v_Trailing = alg_nil();
    (void)v_Trailing;
    Value v_ExceptStmts = alg_nil();
    (void)v_ExceptStmts;
    (void)((v_Statements = alg_list()));
    while (alg_truthy((or_30 = alg_not(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_EXCEPT}, 1)), !alg_truthy(or_30) ? or_30 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
        (void)(alg_invoke(v_Statements, "Add", (Value[]){alg_invoke(v_this, "Statement", NULL, 0)}, 1));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_EXCEPT, alg_string("Expect 'except' after try block.")}, 2));
    (void)((v_Handlers = alg_map()));
    (void)((v_HasHandlers = alg_bool(false)));
    while (alg_truthy(alg_invoke(v_this, "CheckWord", (Value[]){alg_string("on")}, 1))) {
        {
            (void)((v_HasHandlers = alg_bool(true)));
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            (void)((v_Variable = alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expected variable name.")}, 2)));
            (void)((v_TheType = alg_nil()));
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COLON}, 1))) {
                (void)((v_TheType = alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expected type.")}, 2)));
            }
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_DO, alg_string("Expected 'do'.")}, 2));
            (void)((v_Key = alg_string("default")));
            if (alg_truthy(alg_not_equal(v_TheType, alg_nil()))) {
                (void)((v_Key = alg_str(alg_property(v_TheType, "Lexeme"))));
            }
            if (alg_truthy(alg_invoke(v_Handlers, "Contains", (Value[]){v_Key}, 1))) {
                {
                    if (alg_truthy(alg_equal(v_TheType, alg_nil()))) {
                        alg_raise(alg_invoke(v_this, "Error", (Value[]){v_Variable, alg_string("A handler for any exception is already given.")}, 2));
                    }
                    alg_raise(alg_invoke(v_this, "Error", (Value[]){v_TheType, alg_add(alg_add(alg_string("Duplicate handler for '"), v_Key), alg_string("'."))}, 2));
                }
            }
            (void)(alg_invoke(v_Handlers, "Put", (Value[]){v_Key, alg_new(k_ExceptHandler, (Value[]){alg_str(alg_property(v_Variable, "Lexeme")), alg_invoke(v_this, "Statement", NULL, 0)}, 2)}, 2));
        }
    }
    (void)((v_Trailing = alg_invoke(v_this, "Peek", NULL, 0)));
    (void)((v_ExceptStmts = alg_list()));
    while (alg_truthy((or_31 = alg_not(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_END}, 1)), !alg_truthy(or_31) ? or_31 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
        (void)(alg_invoke(v_ExceptStmts, "Add", (Value[]){alg_invoke(v_this, "Statement", NULL, 0)}, 1));
    }
    if (alg_truthy((or_32 = alg_not(v_HasHandlers), alg_truthy(or_32) ? or_32 : alg_not(alg_property(v_ExceptStmts, "IsEmpty"))))) {
        {
            if (alg_truthy((or_33 = alg_not(alg_property(v_ExceptStmts, "IsEmpty")), !alg_truthy(or_33) ? or_33 : alg_invoke(v_Handlers, "Contains", (Value[]){alg_string("default")}, 1)))) {
                alg_raise(alg_invoke(v_this, "Error", (Value[]){v_Trailing, alg_string("A handler for any exception is already given by an untyped 'on'.")}, 2));
            }
            (void)(alg_invoke(v_Handlers, "Put", (Value[]){alg_string("default"), alg_new(k_ExceptHandler, (Value[]){alg_string("Any"), alg_new(k_BlockStmt, (Value[]){v_ExceptStmts}, 1)}, 2)}, 2));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_END, alg_string("Expect 'end' after except block.")}, 2));
    return alg_new(k_TryStmt, (Value[]){alg_new(k_BlockStmt, (Value[]){v_Statements}, 1), v_Handlers}, 2);
    return alg_nil();
}

static Value m_Parser_VarDeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_invoke(v_this, "VarDeclaration", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect variable name.")}, 2)}, 1);
    return alg_nil();
}

static Value m_Parser_VarDeclaration_1_Token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = args[0];
    (void)v_Name;
    Value v_Initializer = alg_nil();
    (void)v_Initializer;
    Value v_TypeName = alg_string("");
    (void)v_TypeName;
    Value v_Generic = alg_string("");
    (void)v_Generic;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COLON}, 1))) {
        {
            (void)((v_TypeName = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect type name.")}, 2), "Lexeme"))));
            if (alg_truthy((or_34 = alg_invoke(v_this, "IsCollectionType", (Value[]){v_TypeName}, 1), !alg_truthy(or_34) ? or_34 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_OF}, 1)))) {
                (void)((v_Generic = alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect generic type.")}, 2), "Lexeme"))));
            }
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_ASSIGN}, 1))) {
        {
            (void)((v_Initializer = alg_invoke(v_this, "Expression", NULL, 0)));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_string("Expect ';' after variable declaration.")}, 2));
    Value v_TheVar = alg_new(k_VarStmt, (Value[]){v_Name, v_Initializer}, 2);
    (void)v_TheVar;
    (void)(alg_set_property(v_TheVar, "TypeName", v_TypeName));
    (void)(alg_set_property(v_TheVar, "Generic", v_Generic));
    return v_TheVar;
    return alg_nil();
}

static Value m_Parser_ExpressionStatement_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = alg_nil();
    (void)v_TheExpr;
    (void)((v_TheExpr = alg_invoke(v_this, "Expression", NULL, 0)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_string("Expect ';' after expression.")}, 2));
    return alg_new(k_ExpressionStmt, (Value[]){v_TheExpr}, 1);
    return alg_nil();
}

static Value m_Parser_ParseFunction_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Kind = args[0];
    (void)v_Kind;
    Value v_Name = alg_nil();
    (void)v_Name;
    Value v_Params = alg_nil();
    (void)v_Params;
    Value v_Body = alg_nil();
    (void)v_Body;
    (void)((v_Name = alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_add(alg_add(alg_string("Expect "), v_Kind), alg_string(" name."))}, 2)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_LEFT_PAREN, alg_add(alg_add(alg_string("Expect '(' after "), v_Kind), alg_string(" name."))}, 2));
    (void)((v_Params = alg_list()));
    Value v_ParamTypes = alg_list();
    (void)v_ParamTypes;
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_RIGHT_PAREN}, 1)))) {
        {
            (void)(alg_invoke(v_Params, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect parameter name.")}, 2)}, 1));
            (void)(alg_invoke(v_ParamTypes, "Add", (Value[]){alg_invoke(v_this, "ParameterType", NULL, 0)}, 1));
            while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COMMA}, 1))) {
                {
                    if (alg_truthy(alg_greater_equal(alg_property(v_Params, "Length"), alg_int(255)))) {
                        {
                            alg_raise(alg_string("Can't have more than 255 parameters."));
                        }
                    }
                    (void)(alg_invoke(v_Params, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect parameter name.")}, 2)}, 1));
                    (void)(alg_invoke(v_ParamTypes, "Add", (Value[]){alg_invoke(v_this, "ParameterType", NULL, 0)}, 1));
                }
            }
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_RIGHT_PAREN, alg_string("Expect ')' after parameters.")}, 2));
    Value v_ReturnType = alg_string("");
    (void)v_ReturnType;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COLON}, 1))) {
        (void)((v_ReturnType = alg_property(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect return type.")}, 2), "Lexeme")));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_add(alg_add(alg_string("Expect ';' after "), v_Kind), alg_string(" signature."))}, 2));
    (void)((v_Body = alg_list()));
    (void)(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_Body}, 1));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_BEGIN, alg_add(alg_add(alg_string("Expect 'begin' before "), v_Kind), alg_string(" body."))}, 2));
    Value v_WasInProcedure = alg_property(v_this, "InProcedure");
    (void)v_WasInProcedure;
    (void)(alg_set_property(v_this, "InProcedure", alg_equal(v_Kind, alg_string("procedure"))));
    Value v_Rest = alg_invoke(v_this, "Block", NULL, 0);
    (void)v_Rest;
    (void)(alg_set_property(v_this, "InProcedure", v_WasInProcedure));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Rest, "Length")))) {
            {
                (void)(alg_invoke(v_Body, "Add", (Value[]){alg_subscript_get(v_Rest, v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    Value v_TheFunction = alg_new(k_FunctionStmt, (Value[]){v_Name, v_Params, v_Body}, 3);
    (void)v_TheFunction;
    (void)(alg_set_property(v_TheFunction, "ReturnType", v_ReturnType));
    (void)(alg_set_property(v_TheFunction, "ParamTypes", v_ParamTypes));
    return v_TheFunction;
    return alg_nil();
}

static Value m_Parser_ParameterType_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_not(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COLON}, 1)))) {
        return alg_string("");
    }
    return alg_property(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect type name.")}, 2), "Lexeme");
    return alg_nil();
}

static Value m_Parser_Block_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Statements = alg_nil();
    (void)v_Statements;
    (void)((v_Statements = alg_list()));
    while (alg_truthy((or_35 = alg_not(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_END}, 1)), !alg_truthy(or_35) ? or_35 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
        {
            (void)(alg_invoke(v_Statements, "Add", (Value[]){alg_invoke(v_this, "Declaration", NULL, 0)}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_END, alg_string("Expect 'end' after block.")}, 2));
    return v_Statements;
    return alg_nil();
}

static Value m_Parser_Assignment_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = alg_nil();
    (void)v_TheExpr;
    Value v_Equals = alg_nil();
    (void)v_Equals;
    Value v_Value = alg_nil();
    (void)v_Value;
    (void)((v_TheExpr = alg_invoke(v_this, "ParseOr", NULL, 0)));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_ASSIGN}, 1))) {
        {
            (void)((v_Equals = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_Value = alg_invoke(v_this, "Assignment", NULL, 0)));
            if (alg_truthy(alg_equal(alg_property(v_TheExpr, "ClassName"), alg_string("VariableExpr")))) {
                return alg_new(k_AssignExpr, (Value[]){alg_property(v_TheExpr, "Name"), v_Value}, 2);
            } else {
                if (alg_truthy(alg_equal(alg_property(v_TheExpr, "ClassName"), alg_string("GetExpr")))) {
                    return alg_new(k_SetExpr, (Value[]){alg_property(v_TheExpr, "Obj"), alg_property(v_TheExpr, "Name"), v_Value}, 3);
                } else {
                    if (alg_truthy(alg_equal(alg_property(v_TheExpr, "ClassName"), alg_string("SubscriptExpr")))) {
                        return alg_new(k_SetSubscriptExpr, (Value[]){alg_property(v_TheExpr, "Obj"), alg_property(v_TheExpr, "Index"), v_Value, alg_property(v_TheExpr, "Bracket")}, 4);
                    }
                }
            }
            alg_raise(alg_string("Invalid assignment target."));
        }
    }
    return v_TheExpr;
    return alg_nil();
}

static Value m_Parser_ParseOr_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = alg_nil();
    (void)v_TheExpr;
    Value v_Op = alg_nil();
    (void)v_Op;
    Value v_Right = alg_nil();
    (void)v_Right;
    (void)((v_TheExpr = alg_invoke(v_this, "ParseAnd", NULL, 0)));
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_OR}, 1))) {
        {
            (void)((v_Op = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_Right = alg_invoke(v_this, "ParseAnd", NULL, 0)));
            (void)((v_TheExpr = alg_new(k_LogicalExpr, (Value[]){v_TheExpr, v_Op, v_Right}, 3)));
        }
    }
    return v_TheExpr;
    return alg_nil();
}

static Value m_Parser_ParseAnd_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = alg_nil();
    (void)v_TheExpr;
    Value v_Op = alg_nil();
    (void)v_Op;
    Value v_Right = alg_nil();
    (void)v_Right;
    (void)((v_TheExpr = alg_invoke(v_this, "Equality", NULL, 0)));
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_AND}, 1))) {
        {
            (void)((v_Op = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_Right = alg_invoke(v_this, "Equality", NULL, 0)));
            (void)((v_TheExpr = alg_new(k_LogicalExpr, (Value[]){v_TheExpr, v_Op, v_Right}, 3)));
        }
    }
    return v_TheExpr;
    return alg_nil();
}

static Value m_Parser_Expression_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = alg_nil();
    (void)v_TheExpr;
    (void)((v_TheExpr = alg_invoke(v_this, "Assignment", NULL, 0)));
    return v_TheExpr;
    return alg_nil();
}

static Value m_Parser_Declaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_invoke(v_this, "IsTestBlock", NULL, 0))) {
        return alg_invoke(v_this, "TestDeclaration", NULL, 0);
    }
    return alg_invoke(v_this, "Statement", NULL, 0);
    return alg_nil();
}

static Value m_Parser_IsTestBlock_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_IDENTIFIER}, 1)))) {
        return alg_bool(false);
    }
    if (alg_truthy(alg_not_equal(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "Lexeme"), alg_string("test")))) {
        return alg_bool(false);
    }
    return (or_36 = alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_TokenType_TOKEN_STRING), alg_truthy(or_36) ? or_36 : alg_equal(alg_property(alg_invoke(v_this, "PeekNext", NULL, 0), "TypeOfToken"), e_TokenType_TOKEN_CHAR));
    return alg_nil();
}

static Value m_Parser_TestDeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = alg_nil();
    (void)v_Name;
    Value v_Body = alg_nil();
    (void)v_Body;
    (void)(alg_invoke(v_this, "Advance", NULL, 0));
    if (alg_truthy(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_CHAR}, 1))) {
        (void)((v_Name = alg_invoke(v_this, "Advance", NULL, 0)));
    } else {
        (void)((v_Name = alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_STRING, alg_string("Expect a test name.")}, 2)));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_string("Expect ';' after test name.")}, 2));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_BEGIN, alg_string("Expect 'begin' before test body.")}, 2));
    (void)((v_Body = alg_invoke(v_this, "Block", NULL, 0)));
    return alg_new(k_FunctionStmt, (Value[]){v_Name, alg_list(), v_Body}, 3);
    return alg_nil();
}

static Value m_Parser_EnumDeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Name = alg_nil();
    (void)v_Name;
    Value v_Members = alg_nil();
    (void)v_Members;
    (void)((v_Name = alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect enum name.")}, 2)));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_EQUAL, alg_string("Expect '=' after enum declaration.")}, 2));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_LEFT_PAREN, alg_string("Expect '(' before enum members.")}, 2));
    (void)((v_Members = alg_list()));
    (void)(alg_invoke(v_Members, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect member name.")}, 2)}, 1));
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COMMA}, 1))) {
        (void)(alg_invoke(v_Members, "Add", (Value[]){alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect member name.")}, 2)}, 1));
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_RIGHT_PAREN, alg_string("Expect ')' after enum members.")}, 2));
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_string("Expect ';' after enum declaration.")}, 2));
    return alg_new(k_EnumStmt, (Value[]){v_Name, v_Members}, 2);
    return alg_nil();
}

static Value m_Parser_ClassDeclaration_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_invoke(v_this, "ClassDeclaration", (Value[]){alg_string("class")}, 1);
    return alg_nil();
}

static Value m_Parser_ClassDeclaration_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Kind = args[0];
    (void)v_Kind;
    Value v_Name = alg_nil();
    (void)v_Name;
    Value v_Methods = alg_nil();
    (void)v_Methods;
    Value v_Fields = alg_nil();
    (void)v_Fields;
    Value v_Superclass = alg_nil();
    (void)v_Superclass;
    (void)((v_Name = alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_add(alg_add(alg_string("Expect "), v_Kind), alg_string(" name."))}, 2)));
    (void)((v_Superclass = alg_nil()));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_LEFT_PAREN}, 1))) {
        {
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect superclass name.")}, 2));
            (void)((v_Superclass = alg_new(k_VariableExpr, (Value[]){alg_invoke(v_this, "Previous", NULL, 0)}, 1)));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_RIGHT_PAREN, alg_string("Expect ')' after superclass name.")}, 2));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_SEMICOLON, alg_add(alg_add(alg_string("Expect ';' after "), v_Kind), alg_string(" declaration."))}, 2));
    (void)(alg_set_property(v_this, "ClassPrivates", alg_list()));
    (void)(alg_set_property(v_this, "InPrivateSection", alg_bool(false)));
    (void)((v_Fields = alg_list()));
    Value v_Section = alg_list();
    (void)v_Section;
    (void)(alg_invoke(v_this, "ReadDeclarationSections", (Value[]){v_Section, alg_bool(true)}, 2));
    {
        Value v_I = alg_int(0);
        (void)v_I;
        while (alg_truthy(alg_less(v_I, alg_property(v_Section, "Length")))) {
            {
                {
                    Value v_Each = alg_subscript_get(v_Section, v_I);
                    (void)v_Each;
                    if (alg_truthy(alg_is(v_Each, "VarGroupStmt"))) {
                        {
                            {
                                Value v_J = alg_int(0);
                                (void)v_J;
                                while (alg_truthy(alg_less(v_J, alg_property(alg_property(v_Each, "Names"), "Length")))) {
                                    {
                                        {
                                            Value v_Field = alg_new(k_VarStmt, (Value[]){alg_subscript_get(alg_property(v_Each, "Names"), v_J), alg_property(v_Each, "Initializer")}, 2);
                                            (void)v_Field;
                                            (void)(alg_set_property(v_Field, "TypeName", alg_property(v_Each, "TypeName")));
                                            (void)(alg_set_property(v_Field, "Generic", alg_property(v_Each, "Generic")));
                                            (void)(alg_invoke(v_Fields, "Add", (Value[]){v_Field}, 1));
                                        }
                                        (void)((v_J = alg_add(v_J, alg_int(1))));
                                    }
                                }
                            }
                        }
                    } else {
                        (void)(alg_invoke(v_Fields, "Add", (Value[]){v_Each}, 1));
                    }
                }
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_BEGIN, alg_add(alg_add(alg_string("Expect 'begin' before "), v_Kind), alg_string(" body."))}, 2));
    (void)(alg_set_property(v_this, "InPrivateSection", alg_bool(false)));
    (void)((v_Methods = alg_list()));
    while (alg_truthy((or_37 = alg_not(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_END}, 1)), !alg_truthy(or_37) ? or_37 : alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0))))) {
        {
            while (alg_truthy(alg_invoke(v_this, "MatchVisibility", NULL, 0))) {
                {
                }
            }
            if (alg_truthy((or_38 = alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_END}, 1), alg_truthy(or_38) ? or_38 : alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
                break;
            }
            Value v_Method = alg_nil();
            (void)v_Method;
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_CONSTRUCTOR}, 1))) {
                (void)((v_Method = alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("constructor")}, 1)));
            } else {
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_PROCEDURE}, 1))) {
                    (void)((v_Method = alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("procedure")}, 1)));
                } else {
                    {
                        (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_FUNCTION, alg_string("Expect 'function', 'procedure' or 'constructor' in class body.")}, 2));
                        (void)((v_Method = alg_invoke(v_this, "ParseFunction", (Value[]){alg_string("method")}, 1)));
                    }
                }
            }
            if (alg_truthy(alg_property(v_this, "InPrivateSection"))) {
                (void)(alg_invoke(alg_property(v_this, "ClassPrivates"), "Add", (Value[]){alg_str(alg_property(alg_property(v_Method, "Name"), "Lexeme"))}, 1));
            }
            (void)(alg_invoke(v_Methods, "Add", (Value[]){v_Method}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_END, alg_add(alg_add(alg_string("Expect 'end' after "), v_Kind), alg_string(" body."))}, 2));
    if (alg_truthy(alg_equal(v_Kind, alg_string("object")))) {
        {
            Value v_TheObject = alg_new(k_ObjectStmt, (Value[]){v_Name, v_Superclass, v_Methods, v_Fields}, 4);
            (void)v_TheObject;
            (void)(alg_set_property(v_TheObject, "PrivateMembers", alg_property(v_this, "ClassPrivates")));
            return v_TheObject;
        }
    }
    Value v_TheClass = alg_new(k_ClassStmt, (Value[]){v_Name, v_Superclass, v_Methods, v_Fields}, 4);
    (void)v_TheClass;
    (void)(alg_set_property(v_TheClass, "PrivateMembers", alg_property(v_this, "ClassPrivates")));
    return v_TheClass;
    return alg_nil();
}

static Value m_Parser_Equality_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = alg_nil();
    (void)v_TheExpr;
    Value v_Operator = alg_nil();
    (void)v_Operator;
    Value v_Right = alg_nil();
    (void)v_Right;
    (void)((v_TheExpr = alg_invoke(v_this, "Comparison", NULL, 0)));
    while (alg_truthy((or_39 = alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_NOT_EQUAL}, 1), alg_truthy(or_39) ? or_39 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_EQUAL}, 1)))) {
        {
            (void)((v_Operator = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_Right = alg_invoke(v_this, "Comparison", NULL, 0)));
            (void)((v_TheExpr = alg_new(k_BinaryExpr, (Value[]){v_TheExpr, v_Operator, v_Right}, 3)));
        }
    }
    return v_TheExpr;
    return alg_nil();
}

static Value m_Parser_Comparison_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = alg_nil();
    (void)v_TheExpr;
    Value v_Operator = alg_nil();
    (void)v_Operator;
    Value v_Right = alg_nil();
    (void)v_Right;
    (void)((v_TheExpr = alg_invoke(v_this, "Term", NULL, 0)));
    while (alg_truthy(alg_bool(true))) {
        {
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_IS}, 1))) {
                {
                    (void)((v_TheExpr = alg_new(k_IsExpr, (Value[]){v_TheExpr, alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect type name after 'is'.")}, 2)}, 2)));
                }
            } else {
                if (alg_truthy((or_43 = (or_42 = (or_41 = (or_40 = alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_GREATER}, 1), alg_truthy(or_40) ? or_40 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_GREATER_EQUAL}, 1)), alg_truthy(or_41) ? or_41 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_LESS}, 1)), alg_truthy(or_42) ? or_42 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_LESS_EQUAL}, 1)), alg_truthy(or_43) ? or_43 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_IN}, 1)))) {
                    {
                        (void)((v_Operator = alg_invoke(v_this, "Previous", NULL, 0)));
                        (void)((v_Right = alg_invoke(v_this, "Term", NULL, 0)));
                        (void)((v_TheExpr = alg_new(k_BinaryExpr, (Value[]){v_TheExpr, v_Operator, v_Right}, 3)));
                    }
                } else {
                    return v_TheExpr;
                }
            }
        }
    }
    return v_TheExpr;
    return alg_nil();
}

static Value m_Parser_Term_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = alg_nil();
    (void)v_TheExpr;
    Value v_Operator = alg_nil();
    (void)v_Operator;
    Value v_Right = alg_nil();
    (void)v_Right;
    (void)((v_TheExpr = alg_invoke(v_this, "Factor", NULL, 0)));
    while (alg_truthy((or_44 = alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_MINUS}, 1), alg_truthy(or_44) ? or_44 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_PLUS}, 1)))) {
        {
            (void)((v_Operator = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_Right = alg_invoke(v_this, "Factor", NULL, 0)));
            (void)((v_TheExpr = alg_new(k_BinaryExpr, (Value[]){v_TheExpr, v_Operator, v_Right}, 3)));
        }
    }
    return v_TheExpr;
    return alg_nil();
}

static Value m_Parser_Factor_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = alg_nil();
    (void)v_TheExpr;
    Value v_Operator = alg_nil();
    (void)v_Operator;
    Value v_Right = alg_nil();
    (void)v_Right;
    (void)((v_TheExpr = alg_invoke(v_this, "Unary", NULL, 0)));
    while (alg_truthy((or_45 = alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_SLASH}, 1), alg_truthy(or_45) ? or_45 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_STAR}, 1)))) {
        {
            (void)((v_Operator = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_Right = alg_invoke(v_this, "Unary", NULL, 0)));
            (void)((v_TheExpr = alg_new(k_BinaryExpr, (Value[]){v_TheExpr, v_Operator, v_Right}, 3)));
        }
    }
    return v_TheExpr;
    return alg_nil();
}

static Value m_Parser_Unary_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Operator = alg_nil();
    (void)v_Operator;
    Value v_Right = alg_nil();
    (void)v_Right;
    Value v_TheExpr = alg_nil();
    (void)v_TheExpr;
    if (alg_truthy((or_46 = alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_NOT}, 1), alg_truthy(or_46) ? or_46 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_MINUS}, 1)))) {
        {
            (void)((v_Operator = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)((v_Right = alg_invoke(v_this, "Unary", NULL, 0)));
            return alg_new(k_UnaryExpr, (Value[]){v_Operator, v_Right}, 2);
        }
    }
    (void)((v_TheExpr = alg_invoke(v_this, "Call", NULL, 0)));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_AS}, 1))) {
        (void)(alg_set_property(v_TheExpr, "Cast", alg_str(alg_property(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect typecast identifier.")}, 2), "Lexeme"))));
    }
    return v_TheExpr;
    return alg_nil();
}

static Value m_Parser_CollectionLiteral_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Keys = alg_nil();
    (void)v_Keys;
    Value v_Values = alg_nil();
    (void)v_Values;
    Value v_IsMap = alg_nil();
    (void)v_IsMap;
    (void)((v_Keys = alg_list()));
    (void)((v_Values = alg_list()));
    (void)((v_IsMap = alg_bool(false)));
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COLON}, 1))) {
        {
            (void)((v_IsMap = alg_bool(true)));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_RIGHT_BRACKET, alg_string("Expect ']' after map.")}, 2));
            return alg_new(k_CollectionExpr, (Value[]){alg_bool(true), v_Keys, v_Values}, 3);
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_RIGHT_BRACKET}, 1))) {
        return alg_new(k_CollectionExpr, (Value[]){alg_bool(false), v_Keys, v_Values}, 3);
    }
    Value v_First = alg_invoke(v_this, "Expression", NULL, 0);
    (void)v_First;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COLON}, 1))) {
        {
            (void)((v_IsMap = alg_bool(true)));
            (void)(alg_invoke(v_Keys, "Add", (Value[]){v_First}, 1));
            (void)(alg_invoke(v_Values, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
        }
    } else {
        (void)(alg_invoke(v_Values, "Add", (Value[]){v_First}, 1));
    }
    while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COMMA}, 1))) {
        {
            if (alg_truthy(v_IsMap)) {
                {
                    (void)(alg_invoke(v_Keys, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
                    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_COLON, alg_string("Expect ':' after key.")}, 2));
                    (void)(alg_invoke(v_Values, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
                }
            } else {
                (void)(alg_invoke(v_Values, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
            }
        }
    }
    (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_RIGHT_BRACKET, alg_string("Expect ']' after list.")}, 2));
    return alg_new(k_CollectionExpr, (Value[]){v_IsMap, v_Keys, v_Values}, 3);
    return alg_nil();
}

static Value m_Parser_Call_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = alg_nil();
    (void)v_TheExpr;
    Value v_Name = alg_nil();
    (void)v_Name;
    (void)((v_TheExpr = alg_invoke(v_this, "Primary", NULL, 0)));
    while (alg_truthy(alg_bool(true))) {
        {
            if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_LEFT_PAREN}, 1))) {
                (void)((v_TheExpr = alg_invoke(v_this, "FinishCall", (Value[]){v_TheExpr}, 1)));
            } else {
                if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_LEFT_BRACKET}, 1))) {
                    {
                        Value v_Bracket = alg_invoke(v_this, "Previous", NULL, 0);
                        (void)v_Bracket;
                        Value v_Index = alg_invoke(v_this, "Expression", NULL, 0);
                        (void)v_Index;
                        (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_RIGHT_BRACKET, alg_string("Expect ']' after subscript.")}, 2));
                        (void)((v_TheExpr = alg_new(k_SubscriptExpr, (Value[]){v_TheExpr, v_Index, v_Bracket}, 3)));
                    }
                } else {
                    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_DOT}, 1))) {
                        {
                            (void)((v_Name = alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect property name after '.'.")}, 2)));
                            (void)((v_TheExpr = alg_new(k_GetExpr, (Value[]){v_TheExpr, v_Name}, 2)));
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return v_TheExpr;
    return alg_nil();
}

static Value m_Parser_FinishCall_1_Expr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Callee = args[0];
    (void)v_Callee;
    Value v_Arguments = alg_nil();
    (void)v_Arguments;
    Value v_Paren = alg_nil();
    (void)v_Paren;
    (void)((v_Arguments = alg_list()));
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_RIGHT_PAREN}, 1)))) {
        {
            (void)(alg_invoke(v_Arguments, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
            while (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_COMMA}, 1))) {
                {
                    if (alg_truthy(alg_greater_equal(alg_property(v_Arguments, "Length"), alg_int(255)))) {
                        alg_raise(alg_string("Can't have more than 255 arguments."));
                    }
                    (void)(alg_invoke(v_Arguments, "Add", (Value[]){alg_invoke(v_this, "Expression", NULL, 0)}, 1));
                }
            }
        }
    }
    (void)((v_Paren = alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_RIGHT_PAREN, alg_string("Expect ')' after arguments.")}, 2)));
    return alg_new(k_CallExpr, (Value[]){v_Callee, v_Paren, v_Arguments}, 3);
    return alg_nil();
}

static Value m_Parser_Primary_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheExpr = alg_nil();
    (void)v_TheExpr;
    Value v_Keyword = alg_nil();
    (void)v_Keyword;
    Value v_Method = alg_nil();
    (void)v_Method;
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_FALSE}, 1))) {
        return alg_new(k_LiteralExpr, (Value[]){alg_bool(false)}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_TRUE}, 1))) {
        return alg_new(k_LiteralExpr, (Value[]){alg_bool(true)}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_NIL}, 1))) {
        return alg_new(k_LiteralExpr, (Value[]){alg_nil()}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_LEFT_BRACKET}, 1))) {
        return alg_invoke(v_this, "CollectionLiteral", NULL, 0);
    }
    if (alg_truthy((or_49 = (or_48 = (or_47 = alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_INTEGER}, 1), alg_truthy(or_47) ? or_47 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_NUMBER}, 1)), alg_truthy(or_48) ? or_48 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_STRING}, 1)), alg_truthy(or_49) ? or_49 : alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_CHAR}, 1)))) {
        {
            return alg_new(k_LiteralExpr, (Value[]){alg_property(alg_invoke(v_this, "Previous", NULL, 0), "Literal")}, 1);
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_SUPER}, 1))) {
        {
            (void)((v_Keyword = alg_invoke(v_this, "Previous", NULL, 0)));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_DOT, alg_string("Expect '.' after 'super'.")}, 2));
            (void)((v_Method = alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_IDENTIFIER, alg_string("Expect superclass method name.")}, 2)));
            return alg_new(k_SuperExpr, (Value[]){v_Keyword, v_Method}, 2);
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_THIS}, 1))) {
        return alg_new(k_ThisExpr, (Value[]){alg_invoke(v_this, "Previous", NULL, 0)}, 1);
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_IDENTIFIER}, 1))) {
        {
            return alg_new(k_VariableExpr, (Value[]){alg_invoke(v_this, "Previous", NULL, 0)}, 1);
        }
    }
    if (alg_truthy(alg_invoke(v_this, "Match", (Value[]){e_TokenType_TOKEN_LEFT_PAREN}, 1))) {
        {
            (void)((v_TheExpr = alg_invoke(v_this, "Expression", NULL, 0)));
            (void)(alg_invoke(v_this, "Consume", (Value[]){e_TokenType_TOKEN_RIGHT_PAREN, alg_string("Expect ')' after expression.")}, 2));
            return alg_new(k_GroupingExpr, (Value[]){v_TheExpr}, 1);
        }
    }
    alg_raise(alg_string("Expect expression!"));
    return alg_nil();
}

static Value m_Parser_Match_1_TokenType(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheType = args[0];
    (void)v_TheType;
    if (alg_truthy(alg_invoke(v_this, "Check", (Value[]){v_TheType}, 1))) {
        {
            (void)(alg_invoke(v_this, "Advance", NULL, 0));
            return alg_bool(true);
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value m_Parser_Error_2_Token_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheToken = args[0];
    (void)v_TheToken;
    Value v_Message = args[1];
    (void)v_Message;
    (void)(alg_invoke(alg_singleton(k_Console), "Error", (Value[]){v_TheToken, v_Message}, 2));
    return v_Message;
    return alg_nil();
}

static Value m_Parser_Consume_2_TokenType_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TypeOfToken = args[0];
    (void)v_TypeOfToken;
    Value v_Message = args[1];
    (void)v_Message;
    if (alg_truthy(alg_invoke(v_this, "Check", (Value[]){v_TypeOfToken}, 1))) {
        return alg_invoke(v_this, "Advance", NULL, 0);
    }
    alg_raise(alg_invoke(v_this, "Error", (Value[]){alg_invoke(v_this, "Previous", NULL, 0), v_Message}, 2));
    return alg_nil();
}

static Value m_Parser_Check_1_TokenType(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_TheType = args[0];
    (void)v_TheType;
    if (alg_truthy(alg_invoke(v_this, "IsAtEnd", NULL, 0))) {
        return alg_bool(false);
    }
    return alg_equal(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "TypeOfToken"), v_TheType);
    return alg_nil();
}

static Value m_Parser_CheckWord_1_String(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_Word = args[0];
    (void)v_Word;
    if (alg_truthy(alg_not(alg_invoke(v_this, "Check", (Value[]){e_TokenType_TOKEN_IDENTIFIER}, 1)))) {
        return alg_bool(false);
    }
    return alg_equal(f_ToLower(NULL, (Value[]){alg_str(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "Lexeme"))}, 1), v_Word);
    return alg_nil();
}

static Value m_Parser_Advance_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_not(alg_invoke(v_this, "IsAtEnd", NULL, 0)))) {
        (void)(alg_set_property(v_this, "Current", alg_add(alg_property(v_this, "Current"), alg_int(1))));
    }
    return alg_invoke(v_this, "Previous", NULL, 0);
    return alg_nil();
}

static Value m_Parser_IsAtEnd_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_equal(alg_property(alg_invoke(v_this, "Peek", NULL, 0), "TypeOfToken"), e_TokenType_EOF);
    return alg_nil();
}

static Value m_Parser_Peek_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_subscript_get(alg_property(v_this, "Tokens"), alg_property(v_this, "Current"));
    return alg_nil();
}

static Value m_Parser_PeekNext_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_greater_equal(alg_add(alg_property(v_this, "Current"), alg_int(1)), alg_property(alg_property(v_this, "Tokens"), "Length")))) {
        return alg_subscript_get(alg_property(v_this, "Tokens"), alg_subtract(alg_property(alg_property(v_this, "Tokens"), "Length"), alg_int(1)));
    }
    return alg_subscript_get(alg_property(v_this, "Tokens"), alg_add(alg_property(v_this, "Current"), alg_int(1)));
    return alg_nil();
}

static Value m_Parser_Previous_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_subscript_get(alg_property(v_this, "Tokens"), alg_subtract(alg_property(v_this, "Current"), alg_int(1)));
    return alg_nil();
}

void init_Parser(void) {
    fn_ReadWholeFile = alg_closure("ReadWholeFile", f_ReadWholeFile, NULL, 0, 1);
    k_Parser = alg_class("Parser", alg_nil());
    alg_class_field(k_Parser, "Tokens");
    alg_class_field(k_Parser, "Current");
    alg_class_field(k_Parser, "FileName");
    alg_class_field(k_Parser, "Loaded");
    alg_class_field(k_Parser, "PrivateNames");
    alg_class_field(k_Parser, "InPrivateSection");
    alg_class_field(k_Parser, "ClassPrivates");
    alg_class_field(k_Parser, "LoopDepth");
    alg_class_field(k_Parser, "InProcedure");
    alg_class_initializer(k_Parser, i_Parser);
    alg_class_method(k_Parser, "Init", m_Parser_Init_1_List, 1, t_Parser_Init_1_List);
    alg_class_method(k_Parser, "UnitHeader", m_Parser_UnitHeader_0, 0, NULL);
    alg_class_method(k_Parser, "UnitStem", m_Parser_UnitStem_1_String, 1, t_Parser_UnitStem_1_String);
    alg_class_method(k_Parser, "Parse", m_Parser_Parse_0, 0, NULL);
    alg_class_method(k_Parser, "Statement", m_Parser_Statement_0, 0, NULL);
    alg_class_method(k_Parser, "CaseStatement", m_Parser_CaseStatement_0, 0, NULL);
    alg_class_method(k_Parser, "Equals", m_Parser_Equals_0, 0, NULL);
    alg_class_method(k_Parser, "Either", m_Parser_Either_0, 0, NULL);
    alg_class_method(k_Parser, "BodyStatement", m_Parser_BodyStatement_0, 0, NULL);
    alg_class_method(k_Parser, "IsCollectionType", m_Parser_IsCollectionType_1_String, 1, t_Parser_IsCollectionType_1_String);
    alg_class_method(k_Parser, "IfStatement", m_Parser_IfStatement_0, 0, NULL);
    alg_class_method(k_Parser, "ForStatement", m_Parser_ForStatement_0, 0, NULL);
    alg_class_method(k_Parser, "WhileStatement", m_Parser_WhileStatement_0, 0, NULL);
    alg_class_method(k_Parser, "PrintStatment", m_Parser_PrintStatment_0, 0, NULL);
    alg_class_method(k_Parser, "ReturnStatement", m_Parser_ReturnStatement_0, 0, NULL);
    alg_class_method(k_Parser, "RecordPrivate", m_Parser_RecordPrivate_1, 1, t_Parser_RecordPrivate_1);
    alg_class_method(k_Parser, "DirectoryOf", m_Parser_DirectoryOf_1_String, 1, t_Parser_DirectoryOf_1_String);
    alg_class_method(k_Parser, "ResolveModule", m_Parser_ResolveModule_2_Token_String, 2, t_Parser_ResolveModule_2_Token_String);
    alg_class_method(k_Parser, "UsesStatement", m_Parser_UsesStatement_0, 0, NULL);
    alg_class_method(k_Parser, "ConstDeclaration", m_Parser_ConstDeclaration_0, 0, NULL);
    alg_class_method(k_Parser, "MatchVisibility", m_Parser_MatchVisibility_0, 0, NULL);
    alg_class_method(k_Parser, "IsDeclarationSection", m_Parser_IsDeclarationSection_0, 0, NULL);
    alg_class_method(k_Parser, "IsNextSection", m_Parser_IsNextSection_0, 0, NULL);
    alg_class_method(k_Parser, "DeclarationSection", m_Parser_DeclarationSection_1_Boolean, 1, t_Parser_DeclarationSection_1_Boolean);
    alg_class_method(k_Parser, "ReadDeclarationSections", m_Parser_ReadDeclarationSections_1_List, 1, t_Parser_ReadDeclarationSections_1_List);
    alg_class_method(k_Parser, "ReadDeclarationSections", m_Parser_ReadDeclarationSections_2_List_Boolean, 2, t_Parser_ReadDeclarationSections_2_List_Boolean);
    alg_class_method(k_Parser, "ForInStatement", m_Parser_ForInStatement_1_Token, 1, t_Parser_ForInStatement_1_Token);
    alg_class_method(k_Parser, "BreakStatement", m_Parser_BreakStatement_0, 0, NULL);
    alg_class_method(k_Parser, "RaiseStatement", m_Parser_RaiseStatement_0, 0, NULL);
    alg_class_method(k_Parser, "TryStatement", m_Parser_TryStatement_0, 0, NULL);
    alg_class_method(k_Parser, "VarDeclaration", m_Parser_VarDeclaration_0, 0, NULL);
    alg_class_method(k_Parser, "VarDeclaration", m_Parser_VarDeclaration_1_Token, 1, t_Parser_VarDeclaration_1_Token);
    alg_class_method(k_Parser, "ExpressionStatement", m_Parser_ExpressionStatement_0, 0, NULL);
    alg_class_method(k_Parser, "ParseFunction", m_Parser_ParseFunction_1_String, 1, t_Parser_ParseFunction_1_String);
    alg_class_method(k_Parser, "ParameterType", m_Parser_ParameterType_0, 0, NULL);
    alg_class_method(k_Parser, "Block", m_Parser_Block_0, 0, NULL);
    alg_class_method(k_Parser, "Assignment", m_Parser_Assignment_0, 0, NULL);
    alg_class_method(k_Parser, "ParseOr", m_Parser_ParseOr_0, 0, NULL);
    alg_class_method(k_Parser, "ParseAnd", m_Parser_ParseAnd_0, 0, NULL);
    alg_class_method(k_Parser, "Expression", m_Parser_Expression_0, 0, NULL);
    alg_class_method(k_Parser, "Declaration", m_Parser_Declaration_0, 0, NULL);
    alg_class_method(k_Parser, "IsTestBlock", m_Parser_IsTestBlock_0, 0, NULL);
    alg_class_method(k_Parser, "TestDeclaration", m_Parser_TestDeclaration_0, 0, NULL);
    alg_class_method(k_Parser, "EnumDeclaration", m_Parser_EnumDeclaration_0, 0, NULL);
    alg_class_method(k_Parser, "ClassDeclaration", m_Parser_ClassDeclaration_0, 0, NULL);
    alg_class_method(k_Parser, "ClassDeclaration", m_Parser_ClassDeclaration_1_String, 1, t_Parser_ClassDeclaration_1_String);
    alg_class_method(k_Parser, "Equality", m_Parser_Equality_0, 0, NULL);
    alg_class_method(k_Parser, "Comparison", m_Parser_Comparison_0, 0, NULL);
    alg_class_method(k_Parser, "Term", m_Parser_Term_0, 0, NULL);
    alg_class_method(k_Parser, "Factor", m_Parser_Factor_0, 0, NULL);
    alg_class_method(k_Parser, "Unary", m_Parser_Unary_0, 0, NULL);
    alg_class_method(k_Parser, "CollectionLiteral", m_Parser_CollectionLiteral_0, 0, NULL);
    alg_class_method(k_Parser, "Call", m_Parser_Call_0, 0, NULL);
    alg_class_method(k_Parser, "FinishCall", m_Parser_FinishCall_1_Expr, 1, t_Parser_FinishCall_1_Expr);
    alg_class_method(k_Parser, "Primary", m_Parser_Primary_0, 0, NULL);
    alg_class_method(k_Parser, "Match", m_Parser_Match_1_TokenType, 1, t_Parser_Match_1_TokenType);
    alg_class_method(k_Parser, "Error", m_Parser_Error_2_Token_String, 2, t_Parser_Error_2_Token_String);
    alg_class_method(k_Parser, "Consume", m_Parser_Consume_2_TokenType_String, 2, t_Parser_Consume_2_TokenType_String);
    alg_class_method(k_Parser, "Check", m_Parser_Check_1_TokenType, 1, t_Parser_Check_1_TokenType);
    alg_class_method(k_Parser, "CheckWord", m_Parser_CheckWord_1_String, 1, t_Parser_CheckWord_1_String);
    alg_class_method(k_Parser, "Advance", m_Parser_Advance_0, 0, NULL);
    alg_class_method(k_Parser, "IsAtEnd", m_Parser_IsAtEnd_0, 0, NULL);
    alg_class_method(k_Parser, "Peek", m_Parser_Peek_0, 0, NULL);
    alg_class_method(k_Parser, "PeekNext", m_Parser_PeekNext_0, 0, NULL);
    alg_class_method(k_Parser, "Previous", m_Parser_Previous_0, 0, NULL);
}
