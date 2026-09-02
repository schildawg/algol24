/* Generated from Algol-24.  Do not edit. */
#include "CEmitter.h"
#include "Expr.h"
#include "ObjFunction.h"
#include "Stmt.h"
#include "TokenType.h"
#include "Token.h"

Value f_indentation(Value **cells, Value *args, int32_t count);
Value f_quotec(Value **cells, Value *args, int32_t count);
Value v_hoistVabove;
bool d_hoistVabove;
Value fn_indentation;
static const char *t_f_indentation[] = { "Depth : Integer" };
Value fn_quotec;
static const char *t_f_quotec[] = { "Text : Any" };
Value k_emitunit;
static const char *t_emitunit_init_5_string_list_list_list_string[] = { "Name : String", "Statements : List", "Imports : List", "PrivateNames : List", "FileName : String" };
Value k_cemitter;
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
static Value or_74;
static Value or_75;
static Value or_76;
static Value or_77;
static Value or_78;
static Value or_79;
static Value or_80;
static Value or_81;
static Value or_82;
static Value or_83;
static Value or_84;
static Value or_85;
static Value or_86;
static Value or_87;
static const char *t_cemitter_unsupported_1[] = { "Construct : Any" };
static const char *t_cemitter_line_1[] = { "Text : Any" };
static const char *t_cemitter_mangle_2_string_string[] = { "Prefix : String", "Name : String" };
static const char *t_cemitter_symbolof_2_string_string[] = { "Prefix : String", "Name : String" };
static const char *t_cemitter_classhandle_1_string[] = { "Name : String" };
static const char *t_cemitter_initname_1_string[] = { "Name : String" };
static const char *t_cemitter_enumtypename_1_string[] = { "Name : String" };
static const char *t_cemitter_enummembername_2_string_string[] = { "TypeName : String", "Member : String" };
static const char *t_cemitter_hexof_1_integer[] = { "Code : Integer" };
static const char *t_cemitter_escaped_1_string[] = { "Name : String" };
static const char *t_cemitter_sanitize_1_string[] = { "Text : String" };
static const char *t_cemitter_collectunits_5_list_string_list_list_string[] = { "Statements : List", "Name : String", "Privates : List", "Units : List", "FileName : String" };
static const char *t_cemitter_unitnameof_1_string[] = { "Key : String" };
static const char *t_cemitter_variablename_1_string[] = { "Name : String" };
static const char *t_cemitter_declaredflag_1_string[] = { "Name : String" };
static const char *t_cemitter_functionname_1_string[] = { "Name : String" };
static const char *t_cemitter_handlename_1_string[] = { "Name : String" };
static const char *t_cemitter_setname_1_string[] = { "Name : String" };
static const char *t_cemitter_subprogramvalue_1_string[] = { "Name : String" };
static const char *t_cemitter_functionsymbol_1[] = { "TheStmt : Any" };
static const char *t_cemitter_prototype_1[] = { "TheStmt : Any" };
static const char *t_cemitter_runswhentesting_1_stmt[] = { "TheStmt : Stmt" };
static const char *t_cemitter_exported_1_string[] = { "Name : String" };
static const char *t_cemitter_declarevalue_2_string_string[] = { "Symbol : String", "Name : String" };
static const char *t_cemitter_declarevariable_2_string_string[] = { "Symbol : String", "Name : String" };
static const char *t_cemitter_istest_1[] = { "TheStmt : Any" };
static const char *t_cemitter_collectfunctions_1_list[] = { "Statements : List" };
static const char *t_cemitter_collectglobals_1_list[] = { "Statements : List" };
static const char *t_cemitter_compilingfile_1_string[] = { "Name : String" };
static const char *t_cemitter_emit_2_list_string[] = { "Statements : List", "Stem : String" };
static const char *t_cemitter_unitheader_1[] = { "Unit : Any" };
static const char *t_cemitter_unitsource_4_list_boolean_string[] = { "Unit : Any", "Units : List", "IsMain : Boolean", "Written : String" };
static const char *t_cemitter_upper_1_string[] = { "Text : String" };
static const char *t_cemitter_execute_1[] = { "TheStmt : Any" };
static const char *t_cemitter_evaluate_1[] = { "TheExpr : Any" };
static const char *t_cemitter_emittest_1[] = { "TheStmt : Any" };
static const char *t_cemitter_refusebarebinding_1[] = { "Body : Any" };
static const char *t_cemitter_declaresnested_1_list[] = { "Statements : List" };
static const char *t_cemitter_addonce_2_list_string[] = { "Names : List", "Name : String" };
static const char *t_cemitter_collectbindings_2_list_list[] = { "Statements : List", "Names : List" };
static const char *t_cemitter_boundnames_1[] = { "TheStmt : Any" };
static const char *t_cemitter_boxesfor_1_list[] = { "Body : List" };
static const char *t_cemitter_cell_1_string[] = { "Name : String" };
static const char *t_cemitter_cellpointer_1_string[] = { "Name : String" };
static const char *t_cemitter_visiblecells_2_map_list[] = { "Given : Map", "Own : List" };
static const char *t_cemitter_read_1_string[] = { "Name : String" };
static const char *t_cemitter_closureof_2_list[] = { "TheStmt : Any", "Cells : List" };
static const char *t_cemitter_containstry_1_list[] = { "Statements : List" };
static const char *t_cemitter_requirecell_1_string[] = { "Name : String" };
static const char *t_cemitter_closescope_1_list[] = { "Mark : List" };
static const char *t_cemitter_declarecell_2_string_string[] = { "Name : String", "Initial : String" };
static const char *t_cemitter_hoistcells_1_list[] = { "Statements : List" };
static const char *t_cemitter_emithandlerbody_2_string[] = { "Handler : Any", "Frame : String" };
static const char *t_cemitter_declaredtypes_1[] = { "TheMethod : Any" };
static const char *t_cemitter_parametertable_1[] = { "TheMethod : Any" };
static const char *t_cemitter_variadic_1[] = { "TheStmt : Any" };
static const char *t_cemitter_methodsymbol_2_string[] = { "Owner : String", "TheMethod : Any" };
static const char *t_cemitter_namesvisible_3_string_list_boolean[] = { "SuperName : String", "Own : List", "Fields : Boolean" };
static const char *t_cemitter_emitmethod_2_string[] = { "Owner : String", "TheMethod : Any" };
static const char *t_cemitter_emitclass_5_string_list_list_boolean[] = { "Name : String", "Superclass : Any", "Fields : List", "Methods : List", "IsObject : Boolean" };
static const char *t_cemitter_built_2_boolean_string[] = { "Hoisted : Boolean", "Text : String" };
static const char *t_cemitter_visitvarstmt_1_varstmt[] = { "TheStmt : VarStmt" };
static const char *t_cemitter_visitexpressionstmt_1_expressionstmt[] = { "TheStmt : ExpressionStmt" };
static const char *t_cemitter_pushlabels_1_list[] = { "Statements : List" };
static const char *t_cemitter_depthoflabel_1_string[] = { "TheLabel : String" };
static const char *t_cemitter_gototarget_1_string[] = { "TheLabel : String" };
static const char *t_cemitter_visitgotostmt_1_gotostmt[] = { "TheStmt : GotoStmt" };
static const char *t_cemitter_visitblockstmt_1_blockstmt[] = { "TheStmt : BlockStmt" };
static const char *t_cemitter_visitifstmt_1_ifstmt[] = { "TheStmt : IfStmt" };
static const char *t_cemitter_visitwhilestmt_1_whilestmt[] = { "TheStmt : WhileStmt" };
static const char *t_cemitter_emitcontinuetarget_1_string[] = { "TheLabel : String" };
static const char *t_cemitter_emitbreaktarget_1_string[] = { "TheLabel : String" };
static const char *t_cemitter_visitreturnstmt_1_returnstmt[] = { "TheStmt : ReturnStmt" };
static const char *t_cemitter_emitforeign_1_functionstmt[] = { "TheStmt : FunctionStmt" };
static const char *t_cemitter_visitfunctionstmt_1_functionstmt[] = { "TheStmt : FunctionStmt" };
static const char *t_cemitter_typetable_2_string_list[] = { "Symbol : String", "Types : List" };
static const char *t_cemitter_visitliteral_1_literalexpr[] = { "TheExpr : LiteralExpr" };
static const char *t_cemitter_visitvariableexpr_1_variableexpr[] = { "TheExpr : VariableExpr" };
static const char *t_cemitter_guarded_2_string_string[] = { "Name : String", "Text : String" };
static const char *t_cemitter_missingname_1_string[] = { "Name : String" };
static const char *t_cemitter_spelled_1_string[] = { "Name : String" };
static const char *t_cemitter_unreachable_1_string[] = { "Name : String" };
static const char *t_cemitter_boundvalue_2_string[] = { "Declared : Any", "Value : String" };
static const char *t_cemitter_visitassignexpr_1_assignexpr[] = { "TheExpr : AssignExpr" };
static const char *t_cemitter_visitgrouping_1_groupingexpr[] = { "TheExpr : GroupingExpr" };
static const char *t_cemitter_visitisexpr_1_isexpr[] = { "TheExpr : IsExpr" };
static const char *t_cemitter_visitunary_1_unaryexpr[] = { "TheExpr : UnaryExpr" };
static const char *t_cemitter_visitbinary_1_binaryexpr[] = { "TheExpr : BinaryExpr" };
static const char *t_cemitter_builtincounts_1_string[] = { "Name : String" };
static const char *t_cemitter_countsmessage_2_list_integer[] = { "Counts : List", "Got : Integer" };
static const char *t_cemitter_renamesof_2_string_string[] = { "Unit : String", "Name : String" };
static const char *t_cemitter_markambiguousimport_3_string_string_string[] = { "Name : String", "First : String", "Second : String" };
static const char *t_cemitter_markambiguousmember_3_string_string_string[] = { "Member : String", "First : String", "Second : String" };
static const char *t_cemitter_ambiguousmessage_2_string_string[] = { "Written : String", "Owners : String" };
static const char *t_cemitter_isassertion_1_string[] = { "Name : String" };
static const char *t_cemitter_builtin_2_string_integer[] = { "Name : String", "Count : Integer" };
static const char *t_cemitter_runtogether_1_list[] = { "Arguments : List" };
static const char *t_cemitter_anynamed_1_list[] = { "Names : List" };
static const char *t_cemitter_namearray_1_list[] = { "Names : List" };
static const char *t_cemitter_calling_3_string_list_list[] = { "Callee : String", "Emitted : List", "Names : List" };
static const char *t_cemitter_constructing_3_string_list_list[] = { "Handle : String", "Emitted : List", "Names : List" };
static const char *t_cemitter_invoking_4_string_string_list_list[] = { "Receiver : String", "TheName : String", "Emitted : List", "Names : List" };
static const char *t_cemitter_argumentarray_1_list[] = { "Arguments : List" };
static const char *t_cemitter_exportednames_1_emitunit[] = { "Unit : EmitUnit" };
static const char *t_cemitter_constructorfor_3_string_list_string[] = { "Name : String", "Arguments : List", "Joined : String" };
static const char *t_cemitter_unitcall_5_string_string_list_string_list[] = { "Unit : String", "Name : String", "Arguments : List", "Joined : String", "Names : List" };
static const char *t_cemitter_visitcall_1_callexpr[] = { "TheExpr : CallExpr" };
static const char *t_cemitter_visitlogical_1_logicalexpr[] = { "TheExpr : LogicalExpr" };
static const char *t_cemitter_boundargument_3_integer[] = { "Params : Any", "Types : Any", "I : Integer" };
static const char *t_cemitter_allliterals_1_collectionexpr[] = { "TheExpr : CollectionExpr" };
static const char *t_cemitter_visitcollectionexpr_1_collectionexpr[] = { "TheExpr : CollectionExpr" };
static const char *t_cemitter_hoistedcollection_1_collectionexpr[] = { "TheExpr : CollectionExpr" };
static const char *t_cemitter_computedcollection_1_collectionexpr[] = { "TheExpr : CollectionExpr" };
static const char *t_cemitter_visitsubscriptexpr_1_subscriptexpr[] = { "TheExpr : SubscriptExpr" };
static const char *t_cemitter_visitsetsubscriptexpr_1_setsubscriptexpr[] = { "TheExpr : SetSubscriptExpr" };
static const char *t_cemitter_unitvalue_2_string_string[] = { "Unit : String", "Name : String" };
static const char *t_cemitter_visitgetexpr_1_getexpr[] = { "TheExpr : GetExpr" };
static const char *t_cemitter_visitsetexpr_1_setexpr[] = { "TheExpr : SetExpr" };
static const char *t_cemitter_visitsuperexpr_1_superexpr[] = { "TheExpr : SuperExpr" };
static const char *t_cemitter_visitthisexpr_1_thisexpr[] = { "TheExpr : ThisExpr" };
static const char *t_cemitter_visitclassstmt_1_classstmt[] = { "TheStmt : ClassStmt" };
static const char *t_cemitter_visitobjectstmt_1_objectstmt[] = { "TheStmt : ObjectStmt" };
static const char *t_cemitter_visitsubrangestmt_1_subrangestmt[] = { "TheStmt : SubrangeStmt" };
static const char *t_cemitter_visitenumstmt_1_enumstmt[] = { "TheStmt : EnumStmt" };
static const char *t_cemitter_visittrystmt_1_trystmt[] = { "TheStmt : TryStmt" };
static const char *t_cemitter_visitraisestmt_1_raisestmt[] = { "TheStmt : RaiseStmt" };
static const char *t_cemitter_visitforinstmt_1_forinstmt[] = { "TheStmt : ForInStmt" };
static const char *t_cemitter_breaktarget_1_string[] = { "TheLabel : String" };
static const char *t_cemitter_continuetarget_1_string[] = { "TheLabel : String" };
static const char *t_cemitter_depthofloop_1_string[] = { "TheLabel : String" };
static const char *t_cemitter_popframesto_1_integer[] = { "From : Integer" };
static const char *t_cemitter_visitbreakstmt_1_breakstmt[] = { "TheStmt : BreakStmt" };
static const char *t_cemitter_visitcontinuestmt_1_continuestmt[] = { "TheStmt : ContinueStmt" };
static const char *t_cemitter_visitlabelstmt_1_labelstmt[] = { "TheStmt : LabelStmt" };
static const char *t_cemitter_visitvargroupstmt_1_vargroupstmt[] = { "TheStmt : VarGroupStmt" };
static const char *t_cemitter_visitmodulestmt_1_modulestmt[] = { "TheStmt : ModuleStmt" };

Value f_indentation(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_depth = alg_param(args[0], "Integer");
    (void)v_depth;
    Value v_result = alg_widen(alg_string(""), "String");
    (void)v_result;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, v_depth)); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)((v_result = alg_widen(alg_add(v_result, alg_string("    ")), "String")));
        }
    }
    return v_result;
    return alg_nil();
}

Value f_quotec(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_text = args[0];
    (void)v_text;
    Value v_result = alg_nil();
    (void)v_result;
    (void)((v_result = alg_widen(alg_str(alg_char_value(34)), "String")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_text))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                Value v_c = alg_subscript_get(alg_str(v_text), v_i);
                (void)v_c;
                if (alg_truthy(alg_equal(v_c, alg_char_value(34)))) {
                    (void)((v_result = alg_widen(alg_add(v_result, alg_string("\\\"")), "String")));
                } else {
                    if (alg_truthy(alg_equal(v_c, alg_char_value(92)))) {
                        (void)((v_result = alg_widen(alg_add(v_result, alg_string("\\\\")), "String")));
                    } else {
                        if (alg_truthy(alg_equal(v_c, alg_char_value(10)))) {
                            (void)((v_result = alg_widen(alg_add(v_result, alg_string("\\n")), "String")));
                        } else {
                            if (alg_truthy(alg_equal(v_c, alg_char_value(9)))) {
                                (void)((v_result = alg_widen(alg_add(v_result, alg_string("\\t")), "String")));
                            } else {
                                if (alg_truthy(alg_equal(v_c, alg_char_value(13)))) {
                                    (void)((v_result = alg_widen(alg_add(v_result, alg_string("\\r")), "String")));
                                } else {
                                    (void)((v_result = alg_widen(alg_add(v_result, alg_str(v_c)), "String")));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return alg_add(v_result, alg_str(alg_char_value(34)));
    return alg_nil();
}

static Value i_emitunit(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Statements", alg_nil());
    alg_set_property(v_this, "Imports", alg_nil());
    alg_set_property(v_this, "PrivateNames", alg_nil());
    alg_set_property(v_this, "FileName", alg_nil());
    return alg_nil();
}

static Value m_emitunit_init_5_string_list_list_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_statements = alg_widen(args[1], "List");
    (void)v_statements;
    Value v_imports = alg_widen(args[2], "List");
    (void)v_imports;
    Value v_privatenames = alg_widen(args[3], "List");
    (void)v_privatenames;
    Value v_filename = alg_widen(args[4], "String");
    (void)v_filename;
    (void)(alg_set_property(v_this, "Name", alg_widen(v_name, "String")));
    (void)(alg_set_property(v_this, "Statements", alg_widen(v_statements, "List")));
    (void)(alg_set_property(v_this, "Imports", alg_widen(v_imports, "List")));
    (void)(alg_set_property(v_this, "PrivateNames", alg_widen(v_privatenames, "List")));
    (void)(alg_set_property(v_this, "FileName", alg_widen(v_filename, "String")));
    return alg_nil();
}

static Value i_cemitter(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    alg_set_property(v_this, "Declarations", alg_widen(alg_buffer(alg_int(0)), "Buffer"));
    alg_set_property(v_this, "Functions", alg_widen(alg_buffer(alg_int(0)), "Buffer"));
    alg_set_property(v_this, "MainBody", alg_widen(alg_buffer(alg_int(0)), "Buffer"));
    alg_set_property(v_this, "Setup", alg_widen(alg_buffer(alg_int(0)), "Buffer"));
    alg_set_property(v_this, "Shells", alg_widen(alg_buffer(alg_int(0)), "Buffer"));
    alg_set_property(v_this, "Body", alg_widen(alg_buffer(alg_int(0)), "Buffer"));
    alg_set_property(v_this, "TestSymbols", alg_nil());
    alg_set_property(v_this, "Header", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "UnitName", alg_widen(alg_string("Main"), "String"));
    alg_set_property(v_this, "PrivateNames", alg_nil());
    alg_set_property(v_this, "RootUnit", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "UnitTests", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "Target", alg_widen(alg_string("main"), "String"));
    alg_set_property(v_this, "Depth", alg_widen(alg_int(1), "Integer"));
    alg_set_property(v_this, "AtTopLevel", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "Locals", alg_nil());
    alg_set_property(v_this, "Declared", alg_nil());
    alg_set_property(v_this, "Logicals", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "Loops", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "TryDepth", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "LoopTryDepth", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "LoopLabels", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "LoopDepths", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "Jumped", alg_widen(alg_list(), "Set"));
    alg_set_property(v_this, "LabelDepths", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "Volatiles", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "Renames", alg_nil());
    alg_set_property(v_this, "Overloaded", alg_nil());
    alg_set_property(v_this, "OverloadsIn", alg_nil());
    alg_set_property(v_this, "Tables", alg_nil());
    alg_set_property(v_this, "SetsBuilt", alg_nil());
    alg_set_property(v_this, "Renamed", alg_nil());
    alg_set_property(v_this, "AmbiguousImports", alg_nil());
    alg_set_property(v_this, "AmbiguousMembers", alg_nil());
    alg_set_property(v_this, "Boxed", alg_nil());
    alg_set_property(v_this, "Cells", alg_nil());
    alg_set_property(v_this, "Captured", alg_nil());
    alg_set_property(v_this, "Globals", alg_nil());
    alg_set_property(v_this, "TopLevel", alg_nil());
    alg_set_property(v_this, "UnitExports", alg_nil());
    alg_set_property(v_this, "UnitAll", alg_nil());
    alg_set_property(v_this, "ShadowNames", alg_nil());
    alg_set_property(v_this, "Canonical", alg_nil());
    alg_set_property(v_this, "InsideNested", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "EmitTests", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "Tests", alg_nil());
    alg_set_property(v_this, "TestFiles", alg_nil());
    alg_set_property(v_this, "CurrentFile", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "SourceFile", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "Classes", alg_nil());
    alg_set_property(v_this, "OwnClasses", alg_nil());
    alg_set_property(v_this, "Objects", alg_nil());
    alg_set_property(v_this, "EnumTypes", alg_nil());
    alg_set_property(v_this, "EnumMembers", alg_nil());
    alg_set_property(v_this, "CurrentClass", alg_widen(alg_string(""), "String"));
    alg_set_property(v_this, "VisibleFields", alg_nil());
    alg_set_property(v_this, "VisibleMethods", alg_nil());
    return alg_nil();
}

static Value m_cemitter_init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_set_property(v_this, "Locals", alg_widen(alg_list(), "List")));
    (void)(alg_set_property(v_this, "Declared", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "Classes", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "OwnClasses", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "Objects", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "EnumTypes", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "EnumMembers", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "VisibleFields", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "VisibleMethods", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "Renames", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "AmbiguousMembers", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "AmbiguousImports", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "Renamed", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "Overloaded", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "OverloadsIn", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "Tables", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "SetsBuilt", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "Boxed", alg_widen(alg_list(), "List")));
    (void)(alg_set_property(v_this, "Cells", alg_widen(alg_list(), "List")));
    (void)(alg_set_property(v_this, "Captured", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "Globals", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "TopLevel", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "UnitExports", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "UnitAll", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "ShadowNames", alg_widen(alg_set(), "Set")));
    (void)(alg_set_property(v_this, "Canonical", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "Tests", alg_widen(alg_list(), "List")));
    (void)(alg_set_property(v_this, "TestFiles", alg_widen(alg_list(), "List")));
    (void)(alg_set_property(v_this, "TestSymbols", alg_widen(alg_list(), "List")));
    (void)(alg_set_property(v_this, "PrivateNames", alg_widen(alg_list(), "List")));
    return alg_nil();
}

static Value m_cemitter_unsupported_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_construct = args[0];
    (void)v_construct;
    alg_raise(alg_add(alg_str(v_construct), alg_string(" is not supported by the C back end yet.")));
    return alg_nil();
}

static Value m_cemitter_line_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_text = args[0];
    (void)v_text;
    if (alg_truthy(alg_equal(alg_property(v_this, "Target"), alg_string("body")))) {
        (void)(alg_invoke(alg_property(v_this, "Body"), "Append", (Value[]){alg_add(alg_add(f_indentation(NULL, (Value[]){alg_property(v_this, "Depth")}, 1), alg_str(v_text)), alg_char_value(10))}, 1));
    } else {
        (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_add(f_indentation(NULL, (Value[]){alg_property(v_this, "Depth")}, 1), alg_str(v_text)), alg_char_value(10))}, 1));
    }
    return alg_nil();
}

static Value m_cemitter_mangle_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_prefix = alg_widen(args[0], "String");
    (void)v_prefix;
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Renames"), "Contains", (Value[]){alg_str(v_name)}, 1))) {
        return alg_add(alg_add(alg_add(v_prefix, alg_invoke(v_this, "Escaped", (Value[]){alg_str(v_name)}, 1)), alg_string("__")), alg_invoke(v_this, "Escaped", (Value[]){alg_str(alg_invoke(alg_property(v_this, "Renames"), "Get", (Value[]){alg_str(v_name)}, 1))}, 1));
    }
    return alg_invoke(v_this, "SymbolOf", (Value[]){v_prefix, alg_str(v_name)}, 2);
    return alg_nil();
}

static Value m_cemitter_symbolof_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_prefix = alg_widen(args[0], "String");
    (void)v_prefix;
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    return alg_add(v_prefix, alg_invoke(v_this, "Escaped", (Value[]){v_name}, 1));
    return alg_nil();
}

static Value m_cemitter_classhandle_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    return alg_invoke(v_this, "Mangle", (Value[]){alg_string("k_"), v_name}, 2);
    return alg_nil();
}

static Value m_cemitter_initname_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    return alg_invoke(v_this, "SymbolOf", (Value[]){alg_string("i_"), v_name}, 2);
    return alg_nil();
}

static Value m_cemitter_enumtypename_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    return alg_invoke(v_this, "Mangle", (Value[]){alg_string("e_"), v_name}, 2);
    return alg_nil();
}

static Value m_cemitter_enummembername_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_typename = alg_widen(args[0], "String");
    (void)v_typename;
    Value v_member = alg_widen(args[1], "String");
    (void)v_member;
    return alg_add(alg_add(alg_invoke(v_this, "Mangle", (Value[]){alg_string("e_"), v_typename}, 2), alg_char_value(95)), alg_invoke(v_this, "Escaped", (Value[]){v_member}, 1));
    return alg_nil();
}

static Value m_cemitter_hexof_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_code = alg_widen(args[0], "Integer");
    (void)v_code;
    Value v_result = alg_widen(alg_string(""), "String");
    (void)v_result;
    Value v_left = alg_nil();
    (void)v_left;
    (void)((v_left = alg_widen(v_code, "Integer")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_int(6))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                (void)((v_result = alg_widen(alg_add(alg_copy(alg_string("0123456789ABCDEF"), alg_mod(v_left, alg_int(16)), alg_int(1)), v_result), "String")));
                (void)((v_left = alg_widen(alg_divide(v_left, alg_int(16)), "Integer")));
            }
        }
    }
    return v_result;
    return alg_nil();
}

static Value m_cemitter_escaped_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_result = alg_nil();
    (void)v_result;
    (void)((v_result = alg_widen(alg_buffer(alg_int(0)), "Buffer")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_name))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                Value v_c = alg_subscript_get(alg_str(v_name), v_i);
                (void)v_c;
                if (alg_truthy((or_0 = alg_greater_equal(v_c, alg_char_value(97)), !alg_truthy(or_0) ? or_0 : alg_less_equal(v_c, alg_char_value(122))))) {
                    (void)(alg_invoke(v_result, "Append", (Value[]){alg_str(v_c)}, 1));
                } else {
                    if (alg_truthy((or_1 = alg_greater_equal(v_c, alg_char_value(48)), !alg_truthy(or_1) ? or_1 : alg_less_equal(v_c, alg_char_value(57))))) {
                        (void)(alg_invoke(v_result, "Append", (Value[]){alg_str(v_c)}, 1));
                    } else {
                        if (alg_truthy((or_2 = alg_greater_equal(v_c, alg_char_value(65)), !alg_truthy(or_2) ? or_2 : alg_less_equal(v_c, alg_char_value(90))))) {
                            (void)(alg_invoke(v_result, "Append", (Value[]){alg_char(alg_add(alg_ord(v_c), alg_int(32)))}, 1));
                        } else {
                            if (alg_truthy(alg_equal(v_c, alg_char_value(63)))) {
                                (void)(alg_invoke(v_result, "Append", (Value[]){alg_char_value(81)}, 1));
                            } else {
                                if (alg_truthy(alg_equal(v_c, alg_char_value(33)))) {
                                    (void)(alg_invoke(v_result, "Append", (Value[]){alg_char_value(69)}, 1));
                                } else {
                                    if (alg_truthy(alg_equal(v_c, alg_char_value(95)))) {
                                        (void)(alg_invoke(v_result, "Append", (Value[]){alg_char_value(86)}, 1));
                                    } else {
                                        (void)(alg_invoke(v_result, "Append", (Value[]){alg_add(alg_char_value(85), alg_invoke(v_this, "HexOf", (Value[]){alg_ord(v_c)}, 1))}, 1));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return alg_property(v_result, "Text");
    return alg_nil();
}

static Value m_cemitter_sanitize_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_text = alg_widen(args[0], "String");
    (void)v_text;
    Value v_result = alg_widen(alg_string(""), "String");
    (void)v_result;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_text))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                Value v_c = alg_subscript_get(alg_str(v_text), v_i);
                (void)v_c;
                if (alg_truthy((or_7 = (or_5 = ((or_3 = alg_greater_equal(v_c, alg_char_value(97)), !alg_truthy(or_3) ? or_3 : alg_less_equal(v_c, alg_char_value(122)))), alg_truthy(or_5) ? or_5 : ((or_4 = alg_greater_equal(v_c, alg_char_value(65)), !alg_truthy(or_4) ? or_4 : alg_less_equal(v_c, alg_char_value(90))))), alg_truthy(or_7) ? or_7 : ((or_6 = alg_greater_equal(v_c, alg_char_value(48)), !alg_truthy(or_6) ? or_6 : alg_less_equal(v_c, alg_char_value(57))))))) {
                    (void)((v_result = alg_widen(alg_add(v_result, alg_str(v_c)), "String")));
                } else {
                    (void)((v_result = alg_widen(alg_add(v_result, alg_char_value(95)), "String")));
                }
            }
        }
    }
    return v_result;
    return alg_nil();
}

static Value m_cemitter_collectunits_5_list_string_list_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    Value v_privates = alg_widen(args[2], "List");
    (void)v_privates;
    Value v_units = alg_widen(args[3], "List");
    (void)v_units;
    Value v_filename = alg_widen(args[4], "String");
    (void)v_filename;
    Value v_own = alg_nil();
    (void)v_own;
    Value v_imports = alg_nil();
    (void)v_imports;
    (void)((v_own = alg_widen(alg_list(), "List")));
    (void)((v_imports = alg_widen(alg_list(), "List")));
    {
        Value loop_0 = alg_iterable(v_statements);
        for (int32_t at_0 = 0; at_0 < alg_iterable_count(loop_0); at_0++) {
            Value v_thestmt = alg_iterable_at(loop_0, at_0);
            (void)v_thestmt;
            {
                if (alg_truthy(alg_is(v_thestmt, "ModuleStmt"))) {
                    {
                        Value v_modulename = alg_invoke(v_this, "UnitNameOf", (Value[]){alg_str(alg_property(v_thestmt, "FileName"))}, 1);
                        (void)v_modulename;
                        (void)(alg_invoke(v_imports, "Add", (Value[]){v_modulename}, 1));
                        if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Statements"), alg_nil()))) {
                            (void)(alg_invoke(v_this, "CollectUnits", (Value[]){alg_property(v_thestmt, "Statements"), v_modulename, alg_property(v_thestmt, "PrivateNames"), v_units, alg_str(alg_property(v_thestmt, "FileName"))}, 5));
                        }
                    }
                }
                (void)(alg_invoke(v_own, "Add", (Value[]){v_thestmt}, 1));
            }
        }
    }
    (void)(alg_invoke(v_units, "Add", (Value[]){alg_new(k_emitunit, (Value[]){v_name, v_own, v_imports, v_privates, v_filename}, 5)}, 1));
    return alg_nil();
}

static Value m_cemitter_unitnameof_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_key = alg_widen(args[0], "String");
    (void)v_key;
    Value v_start = alg_nil();
    (void)v_start;
    Value v_stem = alg_nil();
    (void)v_stem;
    (void)((v_start = alg_widen(alg_int(0), "Integer")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_key))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_equal(alg_subscript_get(v_key, v_i), alg_char_value(47)))) {
                (void)((v_start = alg_widen(alg_add(v_i, alg_int(1)), "Integer")));
            }
        }
    }
    (void)((v_stem = alg_widen(alg_copy(v_key, v_start, alg_subtract(alg_text_length(v_key), v_start)), "String")));
    if (alg_truthy(alg_greater(alg_text_length(v_stem), alg_int(4)))) {
        if (alg_truthy(alg_equal(alg_copy(v_stem, alg_subtract(alg_text_length(v_stem), alg_int(4)), alg_int(4)), alg_string(".a24")))) {
            (void)((v_stem = alg_widen(alg_copy(v_stem, alg_int(0), alg_subtract(alg_text_length(v_stem), alg_int(4))), "String")));
        }
    }
    return alg_invoke(v_this, "Sanitize", (Value[]){v_stem}, 1);
    return alg_nil();
}

static Value m_cemitter_variablename_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    return alg_invoke(v_this, "Mangle", (Value[]){alg_string("v_"), v_name}, 2);
    return alg_nil();
}

static Value m_cemitter_declaredflag_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    return alg_invoke(v_this, "Mangle", (Value[]){alg_string("d_"), v_name}, 2);
    return alg_nil();
}

static Value m_cemitter_functionname_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    return alg_invoke(v_this, "Mangle", (Value[]){alg_string("f_"), v_name}, 2);
    return alg_nil();
}

static Value m_cemitter_handlename_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    return alg_invoke(v_this, "Mangle", (Value[]){alg_string("fn_"), v_name}, 2);
    return alg_nil();
}

static Value m_cemitter_setname_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    return alg_invoke(v_this, "Mangle", (Value[]){alg_string("o_"), v_name}, 2);
    return alg_nil();
}

static Value m_cemitter_subprogramvalue_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1))) {
        return alg_invoke(v_this, "SetName", (Value[]){v_name}, 1);
    }
    return alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1);
    return alg_nil();
}

static Value m_cemitter_functionsymbol_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = args[0];
    (void)v_thestmt;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    Value v_name = alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"));
    (void)v_name;
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1)))) {
        return alg_invoke(v_this, "FunctionName", (Value[]){v_name}, 1);
    }
    (void)((v_symbol = alg_widen(alg_add(alg_add(alg_invoke(v_this, "FunctionName", (Value[]){v_name}, 1), alg_char_value(95)), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), "String")));
    Value v_types = alg_invoke(v_this, "DeclaredTypes", (Value[]){v_thestmt}, 1);
    (void)v_types;
    {
        Value loop_1 = alg_iterable(v_types);
        for (int32_t at_1 = 0; at_1 < alg_iterable_count(loop_1); at_1++) {
            Value v_thetype = alg_iterable_at(loop_1, at_1);
            (void)v_thetype;
            if (alg_truthy(alg_not_equal(v_thetype, alg_string("Any")))) {
                (void)((v_symbol = alg_widen(alg_add(alg_add(v_symbol, alg_char_value(95)), alg_invoke(v_this, "Escaped", (Value[]){alg_str(v_thetype)}, 1)), "String")));
            }
        }
    }
    return v_symbol;
    return alg_nil();
}

static Value m_cemitter_prototype_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = args[0];
    (void)v_thestmt;
    Value v_lead = alg_nil();
    (void)v_lead;
    (void)((v_lead = alg_widen(alg_string("static Value "), "String")));
    if (alg_truthy(alg_invoke(v_this, "Exported", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1))) {
        (void)((v_lead = alg_widen(alg_string("Value "), "String")));
    }
    return alg_add(alg_add(v_lead, alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1)), alg_string("(Value **cells, Value *args, int32_t count)"));
    return alg_nil();
}

static Value m_cemitter_runswhentesting_1_stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "Stmt");
    (void)v_thestmt;
    return (or_14 = (or_13 = (or_12 = (or_11 = (or_10 = (or_9 = (or_8 = alg_is(v_thestmt, "FunctionStmt"), alg_truthy(or_8) ? or_8 : alg_is(v_thestmt, "ClassStmt")), alg_truthy(or_9) ? or_9 : alg_is(v_thestmt, "ObjectStmt")), alg_truthy(or_10) ? or_10 : alg_is(v_thestmt, "EnumStmt")), alg_truthy(or_11) ? or_11 : alg_is(v_thestmt, "VarGroupStmt")), alg_truthy(or_12) ? or_12 : alg_is(v_thestmt, "VarStmt")), alg_truthy(or_13) ? or_13 : alg_is(v_thestmt, "SubrangeStmt")), alg_truthy(or_14) ? or_14 : alg_is(v_thestmt, "ModuleStmt"));
    return alg_nil();
}

static Value m_cemitter_exported_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    if (alg_truthy(alg_property(v_this, "RootUnit"))) {
        return alg_bool(false);
    }
    return alg_not(alg_invoke(alg_property(v_this, "PrivateNames"), "Contains", (Value[]){v_name}, 1));
    return alg_nil();
}

static Value m_cemitter_declarevalue_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_symbol = alg_widen(args[0], "String");
    (void)v_symbol;
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    if (alg_truthy(alg_invoke(v_this, "Exported", (Value[]){v_name}, 1))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), v_symbol), alg_char_value(59)), alg_char_value(10))}, 1));
            (void)(alg_set_property(v_this, "Header", alg_widen(alg_add(alg_add(alg_add(alg_add(alg_property(v_this, "Header"), alg_string("extern Value ")), v_symbol), alg_char_value(59)), alg_char_value(10)), "String")));
        }
    } else {
        (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_symbol), alg_char_value(59)), alg_char_value(10))}, 1));
    }
    return alg_nil();
}

static Value m_cemitter_declarevariable_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_symbol = alg_widen(args[0], "String");
    (void)v_symbol;
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){v_symbol, v_name}, 2));
    if (alg_truthy(alg_invoke(v_this, "Exported", (Value[]){v_name}, 1))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("bool "), alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)), alg_char_value(59)), alg_char_value(10))}, 1));
            (void)(alg_set_property(v_this, "Header", alg_widen(alg_add(alg_add(alg_add(alg_add(alg_property(v_this, "Header"), alg_string("extern bool ")), alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)), alg_char_value(59)), alg_char_value(10)), "String")));
        }
    } else {
        (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static bool "), alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)), alg_char_value(59)), alg_char_value(10))}, 1));
    }
    return alg_nil();
}

static Value m_cemitter_istest_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = args[0];
    (void)v_thestmt;
    return alg_not_equal(alg_property(alg_property(v_thestmt, "Name"), "Literal"), alg_nil());
    return alg_nil();
}

static Value m_cemitter_collectfunctions_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    {
        Value loop_2 = alg_iterable(v_statements);
        for (int32_t at_2 = 0; at_2 < alg_iterable_count(loop_2); at_2++) {
            Value v_thestmt = alg_iterable_at(loop_2, at_2);
            (void)v_thestmt;
            {
                if (alg_truthy(alg_is(v_thestmt, "FunctionStmt"))) {
                    {
                        if (alg_truthy(alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1)))) {
                            {
                                (void)(alg_invoke(alg_property(v_this, "Declared"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                                (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                            }
                        }
                        (void)(alg_invoke(v_this, "CollectFunctions", (Value[]){alg_property(v_thestmt, "Body")}, 1));
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "ClassStmt"))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Classes"), "Put", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), v_thestmt}, 2));
                        (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "ObjectStmt"))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Objects"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                        (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "EnumStmt"))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "EnumTypes"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                        (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                        {
                            Value loop_3 = alg_iterable(alg_property(v_thestmt, "Members"));
                            for (int32_t at_3 = 0; at_3 < alg_iterable_count(loop_3); at_3++) {
                                Value v_themember = alg_iterable_at(loop_3, at_3);
                                (void)v_themember;
                                {
                                    Value v_member = alg_str(alg_property(v_themember, "Lexeme"));
                                    (void)v_member;
                                    if (alg_truthy(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_member}, 1))) {
                                        if (alg_truthy(alg_not_equal(alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_member}, 1)), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))))) {
                                            (void)(alg_invoke(v_this, "MarkAmbiguousMember", (Value[]){v_member, alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_member}, 1)), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 3));
                                        }
                                    }
                                    (void)(alg_invoke(alg_property(v_this, "EnumMembers"), "Put", (Value[]){v_member, alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                                    (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){v_member}, 1), v_member}, 2));
                                }
                            }
                        }
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "BlockStmt"))) {
                    (void)(alg_invoke(v_this, "CollectFunctions", (Value[]){alg_property(v_thestmt, "Statements")}, 1));
                }
            }
        }
    }
    return alg_nil();
}

static Value m_cemitter_collectglobals_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    {
        Value loop_4 = alg_iterable(v_statements);
        for (int32_t at_4 = 0; at_4 < alg_iterable_count(loop_4); at_4++) {
            Value v_thestmt = alg_iterable_at(loop_4, at_4);
            (void)v_thestmt;
            {
                if (alg_truthy(alg_is(v_thestmt, "VarStmt"))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Globals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                        (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                    {
                        Value loop_5 = alg_iterable(alg_property(v_thestmt, "Names"));
                        for (int32_t at_5 = 0; at_5 < alg_iterable_count(loop_5); at_5++) {
                            Value v_thename = alg_iterable_at(loop_5, at_5);
                            (void)v_thename;
                            {
                                (void)(alg_invoke(alg_property(v_this, "Globals"), "Add", (Value[]){alg_str(alg_property(v_thename, "Lexeme"))}, 1));
                                (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_thename, "Lexeme")}, 1), alg_str(alg_property(v_thename, "Lexeme"))}, 2));
                            }
                        }
                    }
                }
                if (alg_truthy((or_15 = alg_is(v_thestmt, "FunctionStmt"), !alg_truthy(or_15) ? or_15 : alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1))))) {
                    {
                        if (alg_truthy((or_16 = alg_invoke(alg_property(v_this, "TopLevel"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1), alg_truthy(or_16) ? or_16 : alg_invoke(v_this, "Variadic", (Value[]){v_thestmt}, 1)))) {
                            (void)(alg_invoke(alg_property(v_this, "Overloaded"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                        }
                        (void)(alg_invoke(alg_property(v_this, "TopLevel"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                    }
                }
            }
        }
    }
    return alg_nil();
}

static Value m_cemitter_compilingfile_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    (void)(alg_set_property(v_this, "SourceFile", alg_widen(v_name, "String")));
    return alg_nil();
}

static Value m_cemitter_withtests_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_set_property(v_this, "EmitTests", alg_widen(alg_bool(true), "Boolean")));
    return alg_nil();
}

static Value m_cemitter_emit_2_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    Value v_stem = alg_widen(args[1], "String");
    (void)v_stem;
    Value v_units = alg_nil();
    (void)v_units;
    Value v_files = alg_nil();
    (void)v_files;
    Value v_mainbodytext = alg_nil();
    (void)v_mainbodytext;
    (void)((v_units = alg_widen(alg_list(), "List")));
    (void)((v_files = alg_widen(alg_map(), "Map")));
    (void)((v_mainbodytext = alg_widen(alg_string(""), "String")));
    (void)(alg_invoke(v_this, "CollectUnits", (Value[]){v_statements, v_stem, alg_list(), v_units, alg_property(v_this, "SourceFile")}, 5));
    Value v_seen = alg_set();
    (void)v_seen;
    {
        Value loop_6 = alg_iterable(v_units);
        for (int32_t at_6 = 0; at_6 < alg_iterable_count(loop_6); at_6++) {
            Value v_theunit = alg_iterable_at(loop_6, at_6);
            (void)v_theunit;
            {
                if (alg_truthy(alg_invoke(v_seen, "Contains", (Value[]){alg_str(alg_property(v_theunit, "Name"))}, 1))) {
                    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("Two modules named '"), alg_str(alg_property(v_theunit, "Name"))), alg_char_value(39))}, 1));
                }
                (void)(alg_invoke(v_seen, "Add", (Value[]){alg_str(alg_property(v_theunit, "Name"))}, 1));
            }
        }
    }
    {
        Value loop_7 = alg_iterable(v_units);
        for (int32_t at_7 = 0; at_7 < alg_iterable_count(loop_7); at_7++) {
            Value v_theunit = alg_iterable_at(loop_7, at_7);
            (void)v_theunit;
            (void)(alg_invoke(v_this, "CollectFunctions", (Value[]){alg_property(v_theunit, "Statements")}, 1));
        }
    }
    {
        Value loop_8 = alg_iterable(v_units);
        for (int32_t at_8 = 0; at_8 < alg_iterable_count(loop_8); at_8++) {
            Value v_theunit = alg_iterable_at(loop_8, at_8);
            (void)v_theunit;
            {
                (void)(alg_set_property(v_this, "TopLevel", alg_widen(alg_set(), "Set")));
                (void)(alg_set_property(v_this, "Overloaded", alg_widen(alg_set(), "Set")));
                (void)(alg_invoke(v_this, "CollectGlobals", (Value[]){alg_property(v_theunit, "Statements")}, 1));
                (void)(alg_invoke(alg_property(v_this, "OverloadsIn"), "Put", (Value[]){alg_str(alg_property(v_theunit, "Name")), alg_property(v_this, "Overloaded")}, 2));
            }
        }
    }
    {
        Value loop_9 = alg_iterable(v_units);
        for (int32_t at_9 = 0; at_9 < alg_iterable_count(loop_9); at_9++) {
            Value v_theunit = alg_iterable_at(loop_9, at_9);
            (void)v_theunit;
            {
                Value v_exported = alg_set();
                (void)v_exported;
                Value v_own = alg_property(v_theunit, "Statements");
                (void)v_own;
                {
                    Value v_i = alg_int(0);
                    (void)v_i;
                    for (; alg_truthy(alg_less(v_i, alg_property(v_own, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        {
                            Value v_thestmt = alg_subscript_get(v_own, v_i);
                            (void)v_thestmt;
                            if (alg_truthy((or_17 = alg_is(v_thestmt, "FunctionStmt"), !alg_truthy(or_17) ? or_17 : alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1))))) {
                                (void)(alg_invoke(v_exported, "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                            }
                            if (alg_truthy(alg_is(v_thestmt, "ClassStmt"))) {
                                (void)(alg_invoke(v_exported, "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                            }
                            if (alg_truthy(alg_is(v_thestmt, "ObjectStmt"))) {
                                (void)(alg_invoke(v_exported, "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                            }
                            if (alg_truthy(alg_is(v_thestmt, "VarStmt"))) {
                                (void)(alg_invoke(v_exported, "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                            }
                            if (alg_truthy(alg_is(v_thestmt, "EnumStmt"))) {
                                {
                                    (void)(alg_invoke(v_exported, "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                                    {
                                        Value loop_10 = alg_iterable(alg_property(v_thestmt, "Members"));
                                        for (int32_t at_10 = 0; at_10 < alg_iterable_count(loop_10); at_10++) {
                                            Value v_member = alg_iterable_at(loop_10, at_10);
                                            (void)v_member;
                                            (void)(alg_invoke(v_exported, "Add", (Value[]){alg_str(alg_property(v_member, "Lexeme"))}, 1));
                                        }
                                    }
                                }
                            }
                            if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                                {
                                    Value loop_11 = alg_iterable(alg_property(v_thestmt, "Names"));
                                    for (int32_t at_11 = 0; at_11 < alg_iterable_count(loop_11); at_11++) {
                                        Value v_eachname = alg_iterable_at(loop_11, at_11);
                                        (void)v_eachname;
                                        (void)(alg_invoke(v_exported, "Add", (Value[]){alg_str(alg_property(v_eachname, "Lexeme"))}, 1));
                                    }
                                }
                            }
                        }
                    }
                }
                Value v_everything = alg_set();
                (void)v_everything;
                {
                    Value v_i = alg_int(0);
                    (void)v_i;
                    for (; alg_truthy(alg_less(v_i, alg_property(alg_invoke(v_exported, "ToList", NULL, 0), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        (void)(alg_invoke(v_everything, "Add", (Value[]){alg_subscript_get(alg_invoke(v_exported, "ToList", NULL, 0), v_i)}, 1));
                    }
                }
                (void)(alg_invoke(alg_property(v_this, "UnitAll"), "Put", (Value[]){alg_str(alg_property(v_theunit, "Name")), v_everything}, 2));
                Value v_hidden = alg_property(v_theunit, "PrivateNames");
                (void)v_hidden;
                {
                    Value v_i = alg_int(0);
                    (void)v_i;
                    for (; alg_truthy(alg_less(v_i, alg_property(v_hidden, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        (void)(alg_invoke(v_exported, "Remove", (Value[]){alg_str(alg_subscript_get(v_hidden, v_i))}, 1));
                    }
                }
                (void)(alg_invoke(alg_property(v_this, "UnitExports"), "Put", (Value[]){alg_str(alg_property(v_theunit, "Name")), v_exported}, 2));
            }
        }
    }
    Value v_exportedby = alg_map();
    (void)v_exportedby;
    {
        Value v_u = alg_int(0);
        (void)v_u;
        for (; alg_truthy(alg_less(v_u, alg_subtract(alg_property(v_units, "Length"), alg_int(1)))); (v_u = alg_add(v_u, alg_int(1)))) {
            {
                Value v_visible = alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){alg_str(alg_property(alg_subscript_get(v_units, v_u), "Name"))}, 1), "Set");
                (void)v_visible;
                Value v_names = alg_invoke(v_this, "ExportedNames", (Value[]){alg_subscript_get(v_units, v_u)}, 1);
                (void)v_names;
                {
                    Value v_i = alg_int(0);
                    (void)v_i;
                    for (; alg_truthy(alg_less(v_i, alg_property(v_names, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        {
                            Value v_thename = alg_str(alg_subscript_get(v_names, v_i));
                            (void)v_thename;
                            if (alg_truthy(alg_invoke(v_visible, "Contains", (Value[]){v_thename}, 1))) {
                                {
                                    if (alg_truthy(alg_invoke(v_exportedby, "Contains", (Value[]){v_thename}, 1))) {
                                        {
                                            if (alg_truthy(alg_not_equal(alg_str(alg_invoke(v_exportedby, "Get", (Value[]){v_thename}, 1)), alg_str(alg_property(alg_subscript_get(v_units, v_u), "Name"))))) {
                                                (void)(alg_invoke(alg_property(v_this, "Renamed"), "Add", (Value[]){v_thename}, 1));
                                            }
                                        }
                                    } else {
                                        (void)(alg_invoke(v_exportedby, "Put", (Value[]){v_thename, alg_str(alg_property(alg_subscript_get(v_units, v_u), "Name"))}, 2));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    {
        Value v_u = alg_int(0);
        (void)v_u;
        for (; alg_truthy(alg_less(v_u, alg_property(v_units, "Length"))); (v_u = alg_add(v_u, alg_int(1)))) {
            {
                Value v_unit = alg_subscript_get(v_units, v_u);
                (void)v_unit;
                (void)(alg_set_property(v_this, "Declarations", alg_widen(alg_buffer(alg_int(0)), "Buffer")));
                (void)(alg_set_property(v_this, "Functions", alg_widen(alg_buffer(alg_int(0)), "Buffer")));
                (void)(alg_set_property(v_this, "Setup", alg_widen(alg_buffer(alg_int(0)), "Buffer")));
                (void)(alg_set_property(v_this, "Shells", alg_widen(alg_buffer(alg_int(0)), "Buffer")));
                (void)(alg_set_property(v_this, "Overloaded", alg_widen(alg_cast(alg_invoke(alg_property(v_this, "OverloadsIn"), "Get", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1), "Set"), "Set")));
                (void)(alg_set_property(v_this, "SetsBuilt", alg_widen(alg_set(), "Set")));
                (void)(alg_set_property(v_this, "OwnClasses", alg_widen(alg_set(), "Set")));
                {
                    Value loop_12 = alg_iterable(alg_property(v_unit, "Statements"));
                    for (int32_t at_12 = 0; at_12 < alg_iterable_count(loop_12); at_12++) {
                        Value v_statement = alg_iterable_at(loop_12, at_12);
                        (void)v_statement;
                        if (alg_truthy((or_18 = alg_is(v_statement, "ClassStmt"), alg_truthy(or_18) ? or_18 : alg_is(v_statement, "ObjectStmt")))) {
                            (void)(alg_invoke(alg_property(v_this, "OwnClasses"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_statement, "Name"), "Lexeme")}, 1)}, 1));
                        }
                    }
                }
                (void)(alg_set_property(v_this, "MainBody", alg_widen(alg_buffer(alg_int(0)), "Buffer")));
                (void)(alg_set_property(v_this, "Header", alg_widen(alg_string(""), "String")));
                (void)(alg_set_property(v_this, "Target", alg_widen(alg_string("main"), "String")));
                (void)(alg_set_property(v_this, "Logicals", alg_widen(alg_int(0), "Integer")));
                (void)(alg_set_property(v_this, "Loops", alg_widen(alg_int(0), "Integer")));
                (void)(alg_set_property(v_this, "UnitTests", alg_widen(alg_int(0), "Integer")));
                Value v_ismain = alg_equal(v_u, alg_subtract(alg_property(v_units, "Length"), alg_int(1)));
                (void)v_ismain;
                if (alg_truthy(v_ismain)) {
                    (void)(alg_invoke(v_this, "EmitSubranges", NULL, 0));
                }
                (void)(alg_set_property(v_this, "UnitName", alg_widen(alg_str(alg_property(v_unit, "Name")), "String")));
                (void)(alg_set_property(v_this, "PrivateNames", alg_widen(alg_cast(alg_property(v_unit, "PrivateNames"), "List"), "List")));
                (void)(alg_set_property(v_this, "RootUnit", alg_widen(v_ismain, "Boolean")));
                (void)(alg_set_property(v_this, "CurrentFile", alg_widen(alg_str(alg_property(v_unit, "FileName")), "String")));
                (void)(alg_set_property(v_this, "Renames", alg_widen(alg_map(), "Map")));
                Value v_visible = alg_set();
                (void)v_visible;
                Value v_importowner = alg_map();
                (void)v_importowner;
                (void)(alg_set_property(v_this, "AmbiguousImports", alg_widen(alg_map(), "Map")));
                {
                    Value loop_13 = alg_iterable(alg_property(v_unit, "Imports"));
                    for (int32_t at_13 = 0; at_13 < alg_iterable_count(loop_13); at_13++) {
                        Value v_import = alg_iterable_at(loop_13, at_13);
                        (void)v_import;
                        if (alg_truthy(alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){alg_str(v_import)}, 1))) {
                            {
                                Value v_from = alg_str(v_import);
                                (void)v_from;
                                Value v_seen = alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_from}, 1), "Set")), "ToList", NULL, 0);
                                (void)v_seen;
                                {
                                    Value v_j = alg_int(0);
                                    (void)v_j;
                                    for (; alg_truthy(alg_less(v_j, alg_property(v_seen, "Length"))); (v_j = alg_add(v_j, alg_int(1)))) {
                                        {
                                            Value v_thename = alg_str(alg_subscript_get(v_seen, v_j));
                                            (void)v_thename;
                                            (void)(alg_invoke(v_visible, "Add", (Value[]){v_thename}, 1));
                                            if (alg_truthy(alg_invoke(v_importowner, "Contains", (Value[]){v_thename}, 1))) {
                                                {
                                                    if (alg_truthy(alg_not_equal(alg_str(alg_invoke(v_importowner, "Get", (Value[]){v_thename}, 1)), v_from))) {
                                                        (void)(alg_invoke(v_this, "MarkAmbiguousImport", (Value[]){v_thename, alg_str(alg_invoke(v_importowner, "Get", (Value[]){v_thename}, 1)), v_from}, 3));
                                                    }
                                                }
                                            } else {
                                                (void)(alg_invoke(v_importowner, "Put", (Value[]){v_thename, v_from}, 2));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if (alg_truthy(alg_invoke(alg_property(v_this, "UnitAll"), "Contains", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1))) {
                    {
                        Value v_declares = alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitAll"), "Get", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1), "Set")), "ToList", NULL, 0);
                        (void)v_declares;
                        {
                            Value loop_14 = alg_iterable(v_declares);
                            for (int32_t at_14 = 0; at_14 < alg_iterable_count(loop_14); at_14++) {
                                Value v_declare = alg_iterable_at(loop_14, at_14);
                                (void)v_declare;
                                (void)(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Remove", (Value[]){alg_str(v_declare)}, 1));
                            }
                        }
                    }
                }
                Value v_mine = alg_invoke(v_this, "ExportedNames", (Value[]){v_unit}, 1);
                (void)v_mine;
                {
                    Value v_i = alg_int(0);
                    (void)v_i;
                    for (; alg_truthy(alg_less(v_i, alg_property(v_mine, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        {
                            Value v_thename = alg_str(alg_subscript_get(v_mine, v_i));
                            (void)v_thename;
                            if (alg_truthy(alg_invoke(v_visible, "Contains", (Value[]){v_thename}, 1))) {
                                if (alg_truthy((or_19 = v_ismain, alg_truthy(or_19) ? or_19 : alg_invoke(alg_property(v_unit, "PrivateNames"), "Contains", (Value[]){v_thename}, 1)))) {
                                    (void)(alg_invoke(alg_property(v_this, "Renames"), "Put", (Value[]){v_thename, alg_str(alg_property(v_unit, "Name"))}, 2));
                                }
                            }
                            if (alg_truthy(alg_invoke(alg_property(v_this, "Renamed"), "Contains", (Value[]){v_thename}, 1))) {
                                if (alg_truthy(alg_not(alg_invoke(alg_property(v_unit, "PrivateNames"), "Contains", (Value[]){v_thename}, 1)))) {
                                    (void)(alg_invoke(alg_property(v_this, "Renames"), "Put", (Value[]){v_thename, alg_str(alg_property(v_unit, "Name"))}, 2));
                                }
                            }
                        }
                    }
                }
                Value v_reached = alg_invoke(v_importowner, "Keys", NULL, 0);
                (void)v_reached;
                {
                    Value v_i = alg_int(0);
                    (void)v_i;
                    for (; alg_truthy(alg_less(v_i, alg_property(v_reached, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        {
                            Value v_thename = alg_str(alg_subscript_get(v_reached, v_i));
                            (void)v_thename;
                            if (alg_truthy((or_20 = alg_invoke(alg_property(v_this, "Renamed"), "Contains", (Value[]){v_thename}, 1), !alg_truthy(or_20) ? or_20 : alg_not(alg_invoke(alg_property(v_this, "Renames"), "Contains", (Value[]){v_thename}, 1))))) {
                                if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Contains", (Value[]){v_thename}, 1)))) {
                                    (void)(alg_invoke(alg_property(v_this, "Renames"), "Put", (Value[]){v_thename, alg_str(alg_invoke(v_importowner, "Get", (Value[]){v_thename}, 1))}, 2));
                                }
                            }
                        }
                    }
                }
                (void)(alg_set_property(v_this, "ShadowNames", alg_widen(alg_set(), "Set")));
                if (alg_truthy(alg_invoke(alg_property(v_this, "UnitAll"), "Contains", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1))) {
                    {
                        Value v_own = alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitAll"), "Get", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1), "Set")), "ToList", NULL, 0);
                        (void)v_own;
                        {
                            Value v_i = alg_int(0);
                            (void)v_i;
                            for (; alg_truthy(alg_less(v_i, alg_property(v_own, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                                (void)(alg_invoke(alg_property(v_this, "ShadowNames"), "Add", (Value[]){alg_subscript_get(v_own, v_i)}, 1));
                            }
                        }
                    }
                }
                {
                    Value loop_15 = alg_iterable(alg_property(v_unit, "Imports"));
                    for (int32_t at_15 = 0; at_15 < alg_iterable_count(loop_15); at_15++) {
                        Value v_theimport = alg_iterable_at(loop_15, at_15);
                        (void)v_theimport;
                        if (alg_truthy(alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){alg_str(v_theimport)}, 1))) {
                            {
                                Value v_seen = alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){alg_str(v_theimport)}, 1), "Set")), "ToList", NULL, 0);
                                (void)v_seen;
                                {
                                    Value v_j = alg_int(0);
                                    (void)v_j;
                                    for (; alg_truthy(alg_less(v_j, alg_property(v_seen, "Length"))); (v_j = alg_add(v_j, alg_int(1)))) {
                                        (void)(alg_invoke(alg_property(v_this, "ShadowNames"), "Add", (Value[]){alg_subscript_get(v_seen, v_j)}, 1));
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    Value loop_16 = alg_iterable(alg_property(v_unit, "Statements"));
                    for (int32_t at_16 = 0; at_16 < alg_iterable_count(loop_16); at_16++) {
                        Value v_thestmt = alg_iterable_at(loop_16, at_16);
                        (void)v_thestmt;
                        {
                            if (alg_truthy((or_21 = alg_is(v_thestmt, "FunctionStmt"), !alg_truthy(or_21) ? or_21 : alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1))))) {
                                {
                                    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_invoke(v_this, "Prototype", (Value[]){v_thestmt}, 1), alg_char_value(59)), alg_char_value(10))}, 1));
                                    if (alg_truthy(alg_invoke(v_this, "Exported", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1))) {
                                        (void)(alg_set_property(v_this, "Header", alg_widen(alg_add(alg_add(alg_add(alg_property(v_this, "Header"), alg_invoke(v_this, "Prototype", (Value[]){v_thestmt}, 1)), alg_char_value(59)), alg_char_value(10)), "String")));
                                    }
                                }
                            }
                        }
                    }
                }
                (void)(alg_set_property(v_this, "AtTopLevel", alg_widen(alg_bool(true), "Boolean")));
                (void)(alg_invoke(v_this, "PushLabels", (Value[]){alg_property(v_unit, "Statements")}, 1));
                {
                    Value loop_17 = alg_iterable(alg_property(v_unit, "Statements"));
                    for (int32_t at_17 = 0; at_17 < alg_iterable_count(loop_17); at_17++) {
                        Value v_thestmt = alg_iterable_at(loop_17, at_17);
                        (void)v_thestmt;
                        {
                            if (alg_truthy((or_23 = alg_invoke(v_this, "RunsWhenTesting", (Value[]){v_thestmt}, 1), alg_truthy(or_23) ? or_23 : alg_not(((or_22 = alg_property(v_this, "EmitTests"), !alg_truthy(or_22) ? or_22 : v_ismain)))))) {
                                {
                                    if (alg_truthy(alg_is(v_thestmt, "BlockStmt"))) {
                                        {
                                            (void)(alg_set_property(v_this, "Volatiles", alg_widen(alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_thestmt, "Statements")}, 1), "Boolean")));
                                            (void)(alg_set_property(v_this, "Boxed", alg_widen(alg_invoke(v_this, "BoxesFor", (Value[]){alg_property(v_thestmt, "Statements")}, 1), "List")));
                                            (void)(alg_set_property(v_this, "Cells", alg_widen(alg_list(), "List")));
                                            (void)(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1));
                                            (void)(alg_set_property(v_this, "Boxed", alg_widen(alg_list(), "List")));
                                            (void)(alg_set_property(v_this, "Cells", alg_widen(alg_list(), "List")));
                                            (void)(alg_set_property(v_this, "Volatiles", alg_widen(alg_bool(false), "Boolean")));
                                        }
                                    } else {
                                        (void)(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1));
                                    }
                                }
                            }
                        }
                    }
                }
                (void)(alg_invoke(v_this, "PopLabels", NULL, 0));
                (void)(alg_set_property(v_this, "AtTopLevel", alg_widen(alg_bool(false), "Boolean")));
                if (alg_truthy(v_ismain)) {
                    {
                        Value v_initbody = alg_property(v_this, "MainBody");
                        (void)v_initbody;
                        (void)(alg_set_property(v_this, "MainBody", alg_widen(alg_buffer(alg_int(0)), "Buffer")));
                        if (alg_truthy(alg_property(v_this, "EmitTests"))) {
                            (void)(alg_invoke(v_this, "EmitTestRunner", NULL, 0));
                        }
                        (void)((v_mainbodytext = alg_widen(alg_property(alg_property(v_this, "MainBody"), "Text"), "String")));
                        (void)(alg_set_property(v_this, "MainBody", alg_widen(v_initbody, "Buffer")));
                    }
                }
                (void)(alg_invoke(v_files, "Put", (Value[]){alg_add(alg_str(alg_property(v_unit, "Name")), alg_string(".h")), alg_invoke(v_this, "UnitHeader", (Value[]){v_unit}, 1)}, 2));
                (void)(alg_invoke(v_files, "Put", (Value[]){alg_add(alg_str(alg_property(v_unit, "Name")), alg_string(".c")), alg_invoke(v_this, "UnitSource", (Value[]){v_unit, v_units, v_ismain, v_mainbodytext}, 4)}, 2));
            }
        }
    }
    return v_files;
    return alg_nil();
}

static Value m_cemitter_unitheader_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_unit = args[0];
    (void)v_unit;
    Value v_guard = alg_nil();
    (void)v_guard;
    Value v_text = alg_nil();
    (void)v_text;
    (void)((v_guard = alg_widen(alg_add(alg_add(alg_string("ALG_"), alg_invoke(v_this, "Upper", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1)), alg_string("_H")), "String")));
    (void)((v_text = alg_widen(alg_add(alg_string("/* Generated from Algol-24.  Do not edit. */"), alg_char_value(10)), "String")));
    (void)((v_text = alg_widen(alg_add(alg_add(alg_add(v_text, alg_string("#ifndef ")), v_guard), alg_char_value(10)), "String")));
    (void)((v_text = alg_widen(alg_add(alg_add(alg_add(alg_add(v_text, alg_string("#define ")), v_guard), alg_char_value(10)), alg_char_value(10)), "String")));
    (void)((v_text = alg_widen(alg_add(alg_add(alg_add(v_text, alg_string("#include \"algol.h\"")), alg_char_value(10)), alg_char_value(10)), "String")));
    (void)((v_text = alg_widen(alg_add(v_text, alg_property(v_this, "Header")), "String")));
    (void)((v_text = alg_widen(alg_add(alg_add(alg_add(alg_add(v_text, alg_string("void init_")), alg_str(alg_property(v_unit, "Name"))), alg_string("(void);")), alg_char_value(10)), "String")));
    (void)((v_text = alg_widen(alg_add(alg_add(alg_add(v_text, alg_char_value(10)), alg_string("#endif")), alg_char_value(10)), "String")));
    return v_text;
    return alg_nil();
}

static Value m_cemitter_unitsource_4_list_boolean_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_unit = args[0];
    (void)v_unit;
    Value v_units = alg_widen(args[1], "List");
    (void)v_units;
    Value v_ismain = alg_widen(args[2], "Boolean");
    (void)v_ismain;
    Value v_written = alg_widen(args[3], "String");
    (void)v_written;
    Value v_text = alg_nil();
    (void)v_text;
    (void)((v_text = alg_widen(alg_add(alg_string("/* Generated from Algol-24.  Do not edit. */"), alg_char_value(10)), "String")));
    (void)((v_text = alg_widen(alg_add(alg_add(alg_add(alg_add(v_text, alg_string("#include \"")), alg_str(alg_property(v_unit, "Name"))), alg_string(".h\"")), alg_char_value(10)), "String")));
    {
        Value loop_18 = alg_iterable(alg_property(v_unit, "Imports"));
        for (int32_t at_18 = 0; at_18 < alg_iterable_count(loop_18); at_18++) {
            Value v_import = alg_iterable_at(loop_18, at_18);
            (void)v_import;
            (void)((v_text = alg_widen(alg_add(alg_add(alg_add(alg_add(v_text, alg_string("#include \"")), alg_str(v_import)), alg_string(".h\"")), alg_char_value(10)), "String")));
        }
    }
    (void)((v_text = alg_widen(alg_add(v_text, alg_char_value(10)), "String")));
    if (alg_truthy(alg_greater(alg_property(alg_property(v_this, "Declarations"), "Length"), alg_int(0)))) {
        (void)((v_text = alg_widen(alg_add(alg_add(v_text, alg_property(alg_property(v_this, "Declarations"), "Text")), alg_char_value(10)), "String")));
    }
    if (alg_truthy(alg_greater(alg_property(alg_property(v_this, "Functions"), "Length"), alg_int(0)))) {
        (void)((v_text = alg_widen(alg_add(v_text, alg_property(alg_property(v_this, "Functions"), "Text")), "String")));
    }
    (void)((v_text = alg_widen(alg_add(alg_add(alg_add(alg_add(v_text, alg_string("void init_")), alg_str(alg_property(v_unit, "Name"))), alg_string("(void) {")), alg_char_value(10)), "String")));
    (void)((v_text = alg_widen(alg_add(v_text, alg_property(alg_property(v_this, "Shells"), "Text")), "String")));
    (void)((v_text = alg_widen(alg_add(v_text, alg_property(alg_property(v_this, "Setup"), "Text")), "String")));
    (void)((v_text = alg_widen(alg_add(v_text, alg_property(alg_property(v_this, "MainBody"), "Text")), "String")));
    (void)((v_text = alg_widen(alg_add(alg_add(v_text, alg_char_value(125)), alg_char_value(10)), "String")));
    if (alg_truthy(v_ismain)) {
        {
            (void)((v_text = alg_widen(alg_add(alg_add(alg_add(v_text, alg_char_value(10)), alg_string("int main(int argc, char **argv) {")), alg_char_value(10)), "String")));
            (void)((v_text = alg_widen(alg_add(alg_add(v_text, alg_string("    alg_set_arguments(argc, argv);")), alg_char_value(10)), "String")));
            (void)((v_text = alg_widen(alg_add(alg_add(alg_add(alg_add(v_text, alg_string("    init_")), alg_str(alg_property(v_unit, "Name"))), alg_string("();")), alg_char_value(10)), "String")));
            (void)((v_text = alg_widen(alg_add(v_text, v_written), "String")));
            (void)((v_text = alg_widen(alg_add(alg_add(alg_add(alg_add(v_text, alg_string("    return 0;")), alg_char_value(10)), alg_char_value(125)), alg_char_value(10)), "String")));
        }
    }
    return v_text;
    return alg_nil();
}

static Value m_cemitter_upper_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_text = alg_widen(args[0], "String");
    (void)v_text;
    Value v_result = alg_nil();
    (void)v_result;
    (void)((v_result = alg_widen(alg_string(""), "String")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_text))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                Value v_c = alg_subscript_get(v_text, v_i);
                (void)v_c;
                if (alg_truthy(alg_greater_equal(v_c, alg_char_value(97)))) {
                    if (alg_truthy(alg_less_equal(v_c, alg_char_value(122)))) {
                        (void)((v_c = alg_char(alg_subtract(alg_ord(v_c), alg_int(32)))));
                    }
                }
                (void)((v_result = alg_widen(alg_add(v_result, v_c), "String")));
            }
        }
    }
    return v_result;
    return alg_nil();
}

static Value m_cemitter_emittestrunner_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_files = alg_nil();
    (void)v_files;
    {
        Value loop_19 = alg_iterable(alg_property(v_this, "TestSymbols"));
        for (int32_t at_19 = 0; at_19 < alg_iterable_count(loop_19); at_19++) {
            Value v_testsymbol = alg_iterable_at(loop_19, at_19);
            (void)v_testsymbol;
            (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), alg_str(v_testsymbol)), alg_string("(Value **cells, Value *args, int32_t count);")), alg_char_value(10))}, 1));
        }
    }
    (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_test_begin("), alg_str(alg_property(alg_property(v_this, "Tests"), "Length"))), alg_string(", ")), f_quotec(NULL, (Value[]){alg_property(v_this, "SourceFile")}, 1)), alg_string(");")), alg_char_value(10))}, 1));
    (void)((v_files = alg_widen(alg_list(), "List")));
    {
        Value loop_20 = alg_iterable(alg_property(v_this, "TestFiles"));
        for (int32_t at_20 = 0; at_20 < alg_iterable_count(loop_20); at_20++) {
            Value v_testfile = alg_iterable_at(loop_20, at_20);
            (void)v_testfile;
            if (alg_truthy(alg_not(alg_invoke(v_files, "Contains", (Value[]){v_testfile}, 1)))) {
                (void)(alg_invoke(v_files, "Add", (Value[]){v_testfile}, 1));
            }
        }
    }
    {
        Value loop_21 = alg_iterable(v_files);
        for (int32_t at_21 = 0; at_21 < alg_iterable_count(loop_21); at_21++) {
            Value v_file = alg_iterable_at(loop_21, at_21);
            (void)v_file;
            {
                (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("    alg_test_file("), f_quotec(NULL, (Value[]){alg_str(v_file)}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                Value v_ordered = alg_list();
                (void)v_ordered;
                {
                    Value v_i = alg_int(0);
                    (void)v_i;
                    for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_this, "Tests"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        if (alg_truthy(alg_equal(alg_subscript_get(alg_property(v_this, "TestFiles"), v_i), v_file))) {
                            (void)(alg_invoke(v_ordered, "Add", (Value[]){v_i}, 1));
                        }
                    }
                }
                {
                    Value v_a = alg_int(0);
                    (void)v_a;
                    for (; alg_truthy(alg_less(v_a, alg_property(v_ordered, "Length"))); (v_a = alg_add(v_a, alg_int(1)))) {
                        {
                            Value v_b = alg_add(v_a, alg_int(1));
                            (void)v_b;
                            for (; alg_truthy(alg_less(v_b, alg_property(v_ordered, "Length"))); (v_b = alg_add(v_b, alg_int(1)))) {
                                if (alg_truthy(alg_less(alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_this, "Tests"), alg_subscript_get(v_ordered, v_b)), "Name"), "Lexeme")), alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_this, "Tests"), alg_subscript_get(v_ordered, v_a)), "Name"), "Lexeme"))))) {
                                    {
                                        Value v_swap = alg_subscript_get(v_ordered, v_a);
                                        (void)v_swap;
                                        (void)(alg_subscript_set(v_ordered, v_a, alg_subscript_get(v_ordered, v_b)));
                                        (void)(alg_subscript_set(v_ordered, v_b, v_swap));
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    Value loop_22 = alg_iterable(v_ordered);
                    for (int32_t at_22 = 0; at_22 < alg_iterable_count(loop_22); at_22++) {
                        Value v_each = alg_iterable_at(loop_22, at_22);
                        (void)v_each;
                        (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_test_run("), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_this, "Tests"), v_each), "Name"), "Literal"))}, 1)), alg_string(", ")), alg_str(alg_subscript_get(alg_property(v_this, "TestSymbols"), v_each))), alg_string(");")), alg_char_value(10))}, 1));
                    }
                }
                (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_string("    alg_test_end_file();"), alg_char_value(10))}, 1));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_string("    return alg_test_summary();"), alg_char_value(10))}, 1));
    return alg_nil();
}

static Value m_cemitter_execute_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = args[0];
    (void)v_thestmt;
    (void)(alg_invoke(v_thestmt, "Accept", (Value[]){v_this}, 1));
    return alg_nil();
}

static Value m_cemitter_evaluate_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = args[0];
    (void)v_theexpr;
    Value v_text = alg_nil();
    (void)v_text;
    (void)((v_text = alg_widen(alg_cast(alg_invoke(v_theexpr, "Accept", (Value[]){v_this}, 1), "String"), "String")));
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Cast"), alg_string("")))) {
        return alg_add(alg_add(alg_add(alg_add(alg_string("alg_cast("), v_text), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(v_theexpr, "Cast"))}, 1)), alg_char_value(41));
    }
    return v_text;
    return alg_nil();
}

static Value m_cemitter_emittest_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = args[0];
    (void)v_thestmt;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    (void)((v_symbol = alg_widen(alg_add(alg_add(alg_add(alg_string("t_"), alg_property(v_this, "UnitName")), alg_char_value(95)), alg_str(alg_property(v_this, "UnitTests"))), "String")));
    (void)(alg_set_property(v_this, "UnitTests", alg_widen(alg_add(alg_property(v_this, "UnitTests"), alg_int(1)), "Integer")));
    (void)(alg_invoke(alg_property(v_this, "Tests"), "Add", (Value[]){v_thestmt}, 1));
    (void)(alg_invoke(alg_property(v_this, "TestFiles"), "Add", (Value[]){alg_property(v_this, "CurrentFile")}, 1));
    (void)(alg_invoke(alg_property(v_this, "TestSymbols"), "Add", (Value[]){v_symbol}, 1));
    Value v_enclosingtarget = alg_property(v_this, "Target");
    (void)v_enclosingtarget;
    Value v_enclosingbody = alg_property(v_this, "Body");
    (void)v_enclosingbody;
    Value v_enclosinglocals = alg_property(v_this, "Locals");
    (void)v_enclosinglocals;
    Value v_enclosingtop = alg_property(v_this, "AtTopLevel");
    (void)v_enclosingtop;
    Value v_enclosingvolatiles = alg_property(v_this, "Volatiles");
    (void)v_enclosingvolatiles;
    Value v_enclosingdepth = alg_property(v_this, "Depth");
    (void)v_enclosingdepth;
    Value v_enclosingboxed = alg_property(v_this, "Boxed");
    (void)v_enclosingboxed;
    Value v_enclosingcaptured = alg_property(v_this, "Captured");
    (void)v_enclosingcaptured;
    Value v_enclosingcells = alg_property(v_this, "Cells");
    (void)v_enclosingcells;
    (void)(alg_set_property(v_this, "Target", alg_widen(alg_string("body"), "String")));
    (void)(alg_set_property(v_this, "Body", alg_widen(alg_buffer(alg_int(0)), "Buffer")));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_int(1), "Integer")));
    (void)(alg_set_property(v_this, "AtTopLevel", alg_widen(alg_bool(false), "Boolean")));
    (void)(alg_set_property(v_this, "Volatiles", alg_widen(alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_thestmt, "Body")}, 1), "Boolean")));
    (void)(alg_set_property(v_this, "Boxed", alg_widen(alg_invoke(v_this, "BoxesFor", (Value[]){alg_property(v_thestmt, "Body")}, 1), "List")));
    (void)(alg_set_property(v_this, "Captured", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "Cells", alg_widen(alg_list(), "List")));
    (void)(alg_set_property(v_this, "Locals", alg_widen(alg_list(), "List")));
    Value v_enclosingtrydepth = alg_property(v_this, "TryDepth");
    (void)v_enclosingtrydepth;
    Value v_enclosinglooptry = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosinglooptry;
    (void)(alg_set_property(v_this, "TryDepth", alg_widen(alg_int(0), "Integer")));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_widen(alg_int(0), "Integer")));
    (void)(alg_invoke(v_this, "HoistCells", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    (void)(alg_invoke(v_this, "PushLabels", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    {
        Value loop_23 = alg_iterable(alg_property(v_thestmt, "Body"));
        for (int32_t at_23 = 0; at_23 < alg_iterable_count(loop_23); at_23++) {
            Value v_each = alg_iterable_at(loop_23, at_23);
            (void)v_each;
            (void)(alg_invoke(v_this, "Execute", (Value[]){v_each}, 1));
        }
    }
    (void)(alg_invoke(v_this, "PopLabels", NULL, 0));
    Value v_written = alg_property(alg_property(v_this, "Body"), "Text");
    (void)v_written;
    (void)(alg_set_property(v_this, "Target", alg_widen(v_enclosingtarget, "String")));
    (void)(alg_set_property(v_this, "Body", alg_widen(v_enclosingbody, "Buffer")));
    (void)(alg_set_property(v_this, "Locals", alg_widen(v_enclosinglocals, "List")));
    (void)(alg_set_property(v_this, "AtTopLevel", alg_widen(v_enclosingtop, "Boolean")));
    (void)(alg_set_property(v_this, "Volatiles", alg_widen(v_enclosingvolatiles, "Boolean")));
    (void)(alg_set_property(v_this, "Depth", alg_widen(v_enclosingdepth, "Integer")));
    (void)(alg_set_property(v_this, "Boxed", alg_widen(v_enclosingboxed, "List")));
    (void)(alg_set_property(v_this, "Captured", alg_widen(v_enclosingcaptured, "Map")));
    (void)(alg_set_property(v_this, "Cells", alg_widen(v_enclosingcells, "List")));
    (void)(alg_set_property(v_this, "TryDepth", alg_widen(v_enclosingtrydepth, "Integer")));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_widen(v_enclosinglooptry, "Integer")));
    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), v_symbol), alg_string("(Value **cells, Value *args, int32_t count);")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), v_symbol), alg_string("(Value **cells, Value *args, int32_t count) {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)cells; (void)args; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_written}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("    return alg_nil();"), alg_char_value(10)), alg_char_value(125)), alg_char_value(10)), alg_char_value(10))}, 1));
    return alg_nil();
}

static Value m_cemitter_refusebarebinding_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_body = args[0];
    (void)v_body;
    if (alg_truthy((or_24 = alg_is(v_body, "VarStmt"), alg_truthy(or_24) ? or_24 : alg_is(v_body, "VarGroupStmt")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("A 'var' as an unbraced branch or loop body")}, 1));
    }
    return alg_nil();
}

static Value m_cemitter_declaresnested_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    {
        Value loop_24 = alg_iterable(v_statements);
        for (int32_t at_24 = 0; at_24 < alg_iterable_count(loop_24); at_24++) {
            Value v_thestmt = alg_iterable_at(loop_24, at_24);
            (void)v_thestmt;
            {
                if (alg_truthy(alg_is(v_thestmt, "FunctionStmt"))) {
                    return alg_bool(true);
                }
                if (alg_truthy((or_25 = alg_is(v_thestmt, "BlockStmt"), !alg_truthy(or_25) ? or_25 : alg_invoke(v_this, "DeclaresNested", (Value[]){alg_property(v_thestmt, "Statements")}, 1)))) {
                    return alg_bool(true);
                }
                if (alg_truthy((or_26 = alg_is(v_thestmt, "WhileStmt"), !alg_truthy(or_26) ? or_26 : alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "Body"))}, 1)))) {
                    return alg_bool(true);
                }
                if (alg_truthy((or_27 = alg_is(v_thestmt, "ForInStmt"), !alg_truthy(or_27) ? or_27 : alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "Body"))}, 1)))) {
                    return alg_bool(true);
                }
                if (alg_truthy(alg_is(v_thestmt, "IfStmt"))) {
                    {
                        if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "ThenBranch"))}, 1))) {
                            return alg_bool(true);
                        }
                        if (alg_truthy((or_28 = alg_not_equal(alg_property(v_thestmt, "ElseBranch"), alg_nil()), !alg_truthy(or_28) ? or_28 : alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "ElseBranch"))}, 1)))) {
                            return alg_bool(true);
                        }
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "TryStmt"))) {
                    {
                        if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "TryBlock"))}, 1))) {
                            return alg_bool(true);
                        }
                        Value v_handlers = alg_invoke(alg_property(v_thestmt, "Handlers"), "Values", NULL, 0);
                        (void)v_handlers;
                        {
                            Value loop_25 = alg_iterable(v_handlers);
                            for (int32_t at_25 = 0; at_25 < alg_iterable_count(loop_25); at_25++) {
                                Value v_handler = alg_iterable_at(loop_25, at_25);
                                (void)v_handler;
                                if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_handler, "Body"))}, 1))) {
                                    return alg_bool(true);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value m_cemitter_addonce_2_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_names = alg_widen(args[0], "List");
    (void)v_names;
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    if (alg_truthy(alg_not(alg_invoke(v_names, "Contains", (Value[]){v_name}, 1)))) {
        (void)(alg_invoke(v_names, "Add", (Value[]){v_name}, 1));
    }
    return alg_nil();
}

static Value m_cemitter_collectbindings_2_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    Value v_names = alg_widen(args[1], "List");
    (void)v_names;
    {
        Value loop_26 = alg_iterable(v_statements);
        for (int32_t at_26 = 0; at_26 < alg_iterable_count(loop_26); at_26++) {
            Value v_thestmt = alg_iterable_at(loop_26, at_26);
            (void)v_thestmt;
            {
                if (alg_truthy(alg_is(v_thestmt, "VarStmt"))) {
                    (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                }
                if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                    {
                        Value loop_27 = alg_iterable(alg_property(v_thestmt, "Names"));
                        for (int32_t at_27 = 0; at_27 < alg_iterable_count(loop_27); at_27++) {
                            Value v_thename = alg_iterable_at(loop_27, at_27);
                            (void)v_thename;
                            (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_str(alg_property(v_thename, "Lexeme"))}, 2));
                        }
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "ForInStmt"))) {
                    {
                        (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                        (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "Body")), v_names}, 2));
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "BlockStmt"))) {
                    (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_property(v_thestmt, "Statements"), v_names}, 2));
                }
                if (alg_truthy(alg_is(v_thestmt, "WhileStmt"))) {
                    (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "Body")), v_names}, 2));
                }
                if (alg_truthy(alg_is(v_thestmt, "IfStmt"))) {
                    {
                        (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "ThenBranch")), v_names}, 2));
                        if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "ElseBranch"), alg_nil()))) {
                            (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "ElseBranch")), v_names}, 2));
                        }
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "TryStmt"))) {
                    {
                        (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "TryBlock")), v_names}, 2));
                        Value v_handlers = alg_invoke(alg_property(v_thestmt, "Handlers"), "Values", NULL, 0);
                        (void)v_handlers;
                        {
                            Value loop_28 = alg_iterable(v_handlers);
                            for (int32_t at_28 = 0; at_28 < alg_iterable_count(loop_28); at_28++) {
                                Value v_handler = alg_iterable_at(loop_28, at_28);
                                (void)v_handler;
                                {
                                    (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_str(alg_property(v_handler, "Name"))}, 2));
                                    (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_handler, "Body")), v_names}, 2));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return alg_nil();
}

static Value m_cemitter_boundnames_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = args[0];
    (void)v_thestmt;
    Value v_names = alg_nil();
    (void)v_names;
    (void)((v_names = alg_widen(alg_list(), "List")));
    {
        Value loop_29 = alg_iterable(alg_property(v_thestmt, "Params"));
        for (int32_t at_29 = 0; at_29 < alg_iterable_count(loop_29); at_29++) {
            Value v_param = alg_iterable_at(loop_29, at_29);
            (void)v_param;
            (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_str(alg_property(v_param, "Lexeme"))}, 2));
        }
    }
    (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_property(v_thestmt, "Body"), v_names}, 2));
    return v_names;
    return alg_nil();
}

static Value m_cemitter_boxesfor_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_body = alg_widen(args[0], "List");
    (void)v_body;
    Value v_names = alg_nil();
    (void)v_names;
    (void)((v_names = alg_widen(alg_list(), "List")));
    if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){v_body}, 1))) {
        (void)(alg_invoke(v_this, "CollectBindings", (Value[]){v_body, v_names}, 2));
    }
    return v_names;
    return alg_nil();
}

static Value m_cemitter_cell_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    return alg_invoke(v_this, "Mangle", (Value[]){alg_string("c_"), v_name}, 2);
    return alg_nil();
}

static Value m_cemitter_thisref_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){alg_string("this")}, 1))) {
        return alg_invoke(v_this, "Read", (Value[]){alg_string("this")}, 1);
    }
    return alg_string("v_this");
    return alg_nil();
}

static Value m_cemitter_cellpointer_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1))) {
        return alg_add(alg_add(alg_string("cells["), alg_str(alg_invoke(alg_property(v_this, "Captured"), "Get", (Value[]){v_name}, 1))), alg_char_value(93));
    }
    return alg_invoke(v_this, "Cell", (Value[]){v_name}, 1);
    return alg_nil();
}

static Value m_cemitter_visiblecells_2_map_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_given = alg_widen(args[0], "Map");
    (void)v_given;
    Value v_own = alg_widen(args[1], "List");
    (void)v_own;
    Value v_names = alg_nil();
    (void)v_names;
    (void)((v_names = alg_widen(alg_invoke(v_given, "Keys", NULL, 0), "List")));
    {
        Value loop_30 = alg_iterable(v_own);
        for (int32_t at_30 = 0; at_30 < alg_iterable_count(loop_30); at_30++) {
            Value v_each = alg_iterable_at(loop_30, at_30);
            (void)v_each;
            (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_str(v_each)}, 2));
        }
    }
    return v_names;
    return alg_nil();
}

static Value m_cemitter_read_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1))) {
        return alg_add(alg_add(alg_string("(*cells["), alg_str(alg_invoke(alg_property(v_this, "Captured"), "Get", (Value[]){v_name}, 1))), alg_string("])"));
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1))) {
        return alg_add(alg_add(alg_string("(*"), alg_invoke(v_this, "Cell", (Value[]){v_name}, 1)), alg_char_value(41));
    }
    return alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)}, 2);
    return alg_nil();
}

static Value m_cemitter_closureof_2_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = args[0];
    (void)v_thestmt;
    Value v_cells = alg_widen(args[1], "List");
    (void)v_cells;
    Value v_array = alg_nil();
    (void)v_array;
    (void)((v_array = alg_widen(alg_string("NULL, 0"), "String")));
    if (alg_truthy(alg_greater(alg_property(v_cells, "Length"), alg_int(0)))) {
        {
            Value v_joined = alg_string("");
            (void)v_joined;
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(v_cells, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                            (void)((v_joined = alg_add(v_joined, alg_string(", "))));
                        }
                        (void)((v_joined = alg_add(v_joined, alg_invoke(v_this, "CellPointer", (Value[]){alg_str(alg_subscript_get(v_cells, v_i))}, 1))));
                    }
                }
            }
            (void)((v_array = alg_widen(alg_add(alg_add(alg_add(alg_string("(Value*[]){"), v_joined), alg_string("}, ")), alg_str(alg_property(v_cells, "Length"))), "String")));
        }
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_closure("), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1)), alg_string(", ")), v_array), alg_string(", ")), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), alg_string(", ")), alg_invoke(v_this, "TypeTable", (Value[]){alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1), alg_invoke(v_this, "ParameterTable", (Value[]){v_thestmt}, 1)}, 2)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_containstry_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    {
        Value loop_31 = alg_iterable(v_statements);
        for (int32_t at_31 = 0; at_31 < alg_iterable_count(loop_31); at_31++) {
            Value v_thestmt = alg_iterable_at(loop_31, at_31);
            (void)v_thestmt;
            {
                if (alg_truthy(alg_is(v_thestmt, "TryStmt"))) {
                    return alg_bool(true);
                }
                if (alg_truthy((or_29 = alg_is(v_thestmt, "BlockStmt"), !alg_truthy(or_29) ? or_29 : alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_thestmt, "Statements")}, 1)))) {
                    return alg_bool(true);
                }
                if (alg_truthy((or_30 = alg_is(v_thestmt, "WhileStmt"), !alg_truthy(or_30) ? or_30 : alg_invoke(v_this, "ContainsTry", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "Body"))}, 1)))) {
                    return alg_bool(true);
                }
                if (alg_truthy((or_31 = alg_is(v_thestmt, "ForInStmt"), !alg_truthy(or_31) ? or_31 : alg_invoke(v_this, "ContainsTry", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "Body"))}, 1)))) {
                    return alg_bool(true);
                }
                if (alg_truthy(alg_is(v_thestmt, "IfStmt"))) {
                    {
                        if (alg_truthy(alg_invoke(v_this, "ContainsTry", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "ThenBranch"))}, 1))) {
                            return alg_bool(true);
                        }
                        if (alg_truthy((or_32 = alg_not_equal(alg_property(v_thestmt, "ElseBranch"), alg_nil()), !alg_truthy(or_32) ? or_32 : alg_invoke(v_this, "ContainsTry", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "ElseBranch"))}, 1)))) {
                            return alg_bool(true);
                        }
                    }
                }
            }
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value m_cemitter_local_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    if (alg_truthy(alg_property(v_this, "Volatiles"))) {
        return alg_string("volatile Value ");
    }
    return alg_string("Value ");
    return alg_nil();
}

static Value m_cemitter_requirecell_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Cells"), "Contains", (Value[]){v_name}, 1)))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("A capture of '"), v_name), alg_char_value(39))}, 1));
    }
    return alg_nil();
}

static Value m_cemitter_openscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_list_keep(alg_list_keep(alg_list(), alg_property(alg_property(v_this, "Cells"), "Length")), alg_property(alg_property(v_this, "Locals"), "Length"));
    return alg_nil();
}

static Value m_cemitter_closescope_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_mark = alg_widen(args[0], "List");
    (void)v_mark;
    while (alg_truthy(alg_greater(alg_property(alg_property(v_this, "Cells"), "Length"), alg_subscript_get(v_mark, alg_int(0))))) {
        (void)(alg_invoke(alg_property(v_this, "Cells"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "Cells"), "Length"), alg_int(1))}, 1));
    }
    while (alg_truthy(alg_greater(alg_property(alg_property(v_this, "Locals"), "Length"), alg_subscript_get(v_mark, alg_int(1))))) {
        (void)(alg_invoke(alg_property(v_this, "Locals"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "Locals"), "Length"), alg_int(1))}, 1));
    }
    return alg_nil();
}

static Value m_cemitter_declarecell_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_initial = alg_widen(args[1], "String");
    (void)v_initial;
    Value v_qualifier = alg_nil();
    (void)v_qualifier;
    (void)((v_qualifier = alg_widen(alg_string(""), "String")));
    if (alg_truthy(alg_property(v_this, "Volatiles"))) {
        (void)((v_qualifier = alg_widen(alg_string("volatile "), "String")));
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("Value *"), v_qualifier), alg_invoke(v_this, "Cell", (Value[]){v_name}, 1)), alg_string(" = alg_cell(")), v_initial), alg_string(");"))}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "Cell", (Value[]){v_name}, 1)), alg_char_value(59))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Cells"), "Add", (Value[]){v_name}, 1));
    return alg_nil();
}

static Value m_cemitter_hoistcells_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    {
        Value loop_32 = alg_iterable(v_statements);
        for (int32_t at_32 = 0; at_32 < alg_iterable_count(loop_32); at_32++) {
            Value v_thestmt = alg_iterable_at(loop_32, at_32);
            (void)v_thestmt;
            {
                if (alg_truthy((or_33 = alg_is(v_thestmt, "VarStmt"), !alg_truthy(or_33) ? or_33 : alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                        (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_string("alg_nil()")}, 2));
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                    {
                        Value loop_33 = alg_iterable(alg_property(v_thestmt, "Names"));
                        for (int32_t at_33 = 0; at_33 < alg_iterable_count(loop_33); at_33++) {
                            Value v_thename = alg_iterable_at(loop_33, at_33);
                            (void)v_thename;
                            if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(v_thename, "Lexeme"))}, 1))) {
                                {
                                    (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(v_thename, "Lexeme"))}, 1));
                                    (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_str(alg_property(v_thename, "Lexeme")), alg_string("alg_nil()")}, 2));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return alg_nil();
}

static Value m_cemitter_emithandlerbody_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_handler = args[0];
    (void)v_handler;
    Value v_frame = alg_widen(args[1], "String");
    (void)v_frame;
    Value v_mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_mark;
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_add(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(v_handler, "Name"))}, 1));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(v_handler, "Name"))}, 1))) {
        (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_str(alg_property(v_handler, "Name")), alg_add(v_frame, alg_string(".raised"))}, 2));
    } else {
        {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(v_handler, "Name"))}, 1)), alg_string(" = ")), v_frame), alg_string(".raised;"))}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(v_handler, "Name"))}, 1)), alg_char_value(59))}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_handler, "Body")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1));
    return alg_nil();
}

static Value m_cemitter_declaredtypes_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_themethod = args[0];
    (void)v_themethod;
    Value v_types = alg_nil();
    (void)v_types;
    (void)((v_types = alg_widen(alg_list(), "List")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_themethod, "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                Value v_declared = alg_str(alg_subscript_get(alg_property(v_themethod, "ParamTypes"), v_i));
                (void)v_declared;
                if (alg_truthy(alg_equal(v_declared, alg_string("")))) {
                    (void)((v_declared = alg_string("Any")));
                }
                (void)(alg_invoke(v_types, "Add", (Value[]){v_declared}, 1));
            }
        }
    }
    return v_types;
    return alg_nil();
}

static Value m_cemitter_parametertable_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_themethod = args[0];
    (void)v_themethod;
    Value v_written = alg_nil();
    (void)v_written;
    (void)((v_written = alg_widen(alg_list(), "List")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_themethod, "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                Value v_declared = alg_str(alg_subscript_get(alg_property(v_themethod, "ParamTypes"), v_i));
                (void)v_declared;
                if (alg_truthy(alg_equal(v_declared, alg_string("")))) {
                    (void)((v_declared = alg_string("Any")));
                }
                if (alg_truthy(alg_less(v_i, alg_property(alg_property(v_themethod, "ParamGenerics"), "Length")))) {
                    {
                        Value v_element = alg_str(alg_subscript_get(alg_property(v_themethod, "ParamGenerics"), v_i));
                        (void)v_element;
                        if (alg_truthy(alg_not_equal(v_element, alg_string("")))) {
                            (void)((v_declared = alg_add(alg_add(v_declared, alg_string(" of ")), v_element)));
                        }
                    }
                }
                (void)(alg_invoke(v_written, "Add", (Value[]){alg_add(alg_add(alg_str(alg_property(alg_subscript_get(alg_property(v_themethod, "Params"), v_i), "Lexeme")), alg_string(" : ")), v_declared)}, 1));
            }
        }
    }
    return v_written;
    return alg_nil();
}

static Value m_cemitter_variadic_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = args[0];
    (void)v_thestmt;
    if (alg_truthy(alg_equal(alg_property(alg_property(v_thestmt, "Params"), "Length"), alg_int(0)))) {
        return alg_bool(false);
    }
    Value v_last = alg_subtract(alg_property(alg_property(v_thestmt, "Params"), "Length"), alg_int(1));
    (void)v_last;
    if (alg_truthy(alg_greater_equal(v_last, alg_property(alg_property(v_thestmt, "ParamTypes"), "Length")))) {
        return alg_bool(false);
    }
    if (alg_truthy(alg_greater_equal(v_last, alg_property(alg_property(v_thestmt, "ParamGenerics"), "Length")))) {
        return alg_bool(false);
    }
    return (or_34 = alg_equal(alg_str(alg_subscript_get(alg_property(v_thestmt, "ParamTypes"), v_last)), alg_string("List")), !alg_truthy(or_34) ? or_34 : alg_not_equal(alg_str(alg_subscript_get(alg_property(v_thestmt, "ParamGenerics"), v_last)), alg_string("")));
    return alg_nil();
}

static Value m_cemitter_methodsymbol_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_owner = alg_widen(args[0], "String");
    (void)v_owner;
    Value v_themethod = args[1];
    (void)v_themethod;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    (void)((v_symbol = alg_widen(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("m_"), alg_invoke(v_this, "Escaped", (Value[]){v_owner}, 1)), alg_char_value(95)), alg_invoke(v_this, "Escaped", (Value[]){alg_str(alg_property(alg_property(v_themethod, "Name"), "Lexeme"))}, 1)), alg_char_value(95)), alg_str(alg_property(alg_property(v_themethod, "Params"), "Length"))), "String")));
    Value v_types = alg_invoke(v_this, "DeclaredTypes", (Value[]){v_themethod}, 1);
    (void)v_types;
    {
        Value loop_34 = alg_iterable(v_types);
        for (int32_t at_34 = 0; at_34 < alg_iterable_count(loop_34); at_34++) {
            Value v_thetype = alg_iterable_at(loop_34, at_34);
            (void)v_thetype;
            if (alg_truthy(alg_not_equal(v_thetype, alg_string("Any")))) {
                (void)((v_symbol = alg_widen(alg_add(alg_add(v_symbol, alg_char_value(95)), alg_invoke(v_this, "Escaped", (Value[]){alg_str(v_thetype)}, 1)), "String")));
            }
        }
    }
    return v_symbol;
    return alg_nil();
}

static Value m_cemitter_namesvisible_3_string_list_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_supername = alg_widen(args[0], "String");
    (void)v_supername;
    Value v_own = alg_widen(args[1], "List");
    (void)v_own;
    Value v_fields = alg_widen(args[2], "Boolean");
    (void)v_fields;
    Value v_names = alg_nil();
    (void)v_names;
    Value v_at = alg_nil();
    (void)v_at;
    (void)((v_names = alg_widen(alg_set(), "Set")));
    {
        Value loop_35 = alg_iterable(v_own);
        for (int32_t at_35 = 0; at_35 < alg_iterable_count(loop_35); at_35++) {
            Value v_each = alg_iterable_at(loop_35, at_35);
            (void)v_each;
            (void)(alg_invoke(v_names, "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_each, "Name"), "Lexeme")}, 1)}, 1));
        }
    }
    (void)((v_at = alg_widen(v_supername, "String")));
    while (alg_truthy(alg_not_equal(v_at, alg_string("")))) {
        {
            if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_at}, 1)))) {
                return v_names;
            }
            Value v_ancestor = alg_invoke(alg_property(v_this, "Classes"), "Get", (Value[]){v_at}, 1);
            (void)v_ancestor;
            Value v_inherited = alg_property(v_ancestor, "Methods");
            (void)v_inherited;
            if (alg_truthy(v_fields)) {
                (void)((v_inherited = alg_property(v_ancestor, "Fields")));
            }
            {
                Value loop_36 = alg_iterable(v_inherited);
                for (int32_t at_36 = 0; at_36 < alg_iterable_count(loop_36); at_36++) {
                    Value v_item = alg_iterable_at(loop_36, at_36);
                    (void)v_item;
                    (void)(alg_invoke(v_names, "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_item, "Name"), "Lexeme")}, 1)}, 1));
                }
            }
            (void)((v_at = alg_widen(alg_string(""), "String")));
            if (alg_truthy(alg_not_equal(alg_property(v_ancestor, "Superclass"), alg_nil()))) {
                (void)((v_at = alg_widen(alg_str(alg_property(alg_property(alg_property(v_ancestor, "Superclass"), "Name"), "Lexeme")), "String")));
            }
        }
    }
    return v_names;
    return alg_nil();
}

static Value m_cemitter_emitmethod_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_owner = alg_widen(args[0], "String");
    (void)v_owner;
    Value v_themethod = args[1];
    (void)v_themethod;
    Value v_enclosinglocals = alg_nil();
    (void)v_enclosinglocals;
    Value v_enclosingtop = alg_nil();
    (void)v_enclosingtop;
    Value v_enclosingdepth = alg_nil();
    (void)v_enclosingdepth;
    Value v_opening = alg_nil();
    (void)v_opening;
    (void)((v_enclosinglocals = alg_widen(alg_property(v_this, "Locals"), "List")));
    (void)((v_enclosingtop = alg_widen(alg_property(v_this, "AtTopLevel"), "Boolean")));
    (void)((v_enclosingdepth = alg_widen(alg_property(v_this, "Depth"), "Integer")));
    (void)(alg_set_property(v_this, "Locals", alg_widen(alg_list(), "List")));
    (void)(alg_set_property(v_this, "AtTopLevel", alg_widen(alg_bool(false), "Boolean")));
    Value v_enclosingtarget = alg_property(v_this, "Target");
    (void)v_enclosingtarget;
    Value v_enclosingbody = alg_property(v_this, "Body");
    (void)v_enclosingbody;
    (void)(alg_set_property(v_this, "Target", alg_widen(alg_string("body"), "String")));
    (void)(alg_set_property(v_this, "Body", alg_widen(alg_buffer(alg_int(0)), "Buffer")));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_int(1), "Integer")));
    Value v_enclosingvolatiles = alg_property(v_this, "Volatiles");
    (void)v_enclosingvolatiles;
    (void)(alg_set_property(v_this, "Volatiles", alg_widen(alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_themethod, "Body")}, 1), "Boolean")));
    Value v_enclosingboxed = alg_property(v_this, "Boxed");
    (void)v_enclosingboxed;
    Value v_enclosingcaptured = alg_property(v_this, "Captured");
    (void)v_enclosingcaptured;
    Value v_enclosingcells = alg_property(v_this, "Cells");
    (void)v_enclosingcells;
    (void)(alg_set_property(v_this, "Boxed", alg_widen(alg_list(), "List")));
    (void)(alg_set_property(v_this, "Captured", alg_widen(alg_map(), "Map")));
    (void)(alg_set_property(v_this, "Cells", alg_widen(alg_list(), "List")));
    if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_property(v_themethod, "Body")}, 1))) {
        {
            (void)(alg_set_property(v_this, "Boxed", alg_widen(alg_invoke(v_this, "BoundNames", (Value[]){v_themethod}, 1), "List")));
            (void)(alg_invoke(v_this, "AddOnce", (Value[]){alg_property(v_this, "Boxed"), alg_string("this")}, 2));
            (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_string("this"), alg_string("v_this")}, 2));
        }
    }
    Value v_enclosingtrydepth = alg_property(v_this, "TryDepth");
    (void)v_enclosingtrydepth;
    Value v_enclosinglooptry = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosinglooptry;
    (void)(alg_set_property(v_this, "TryDepth", alg_widen(alg_int(0), "Integer")));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_widen(alg_int(0), "Integer")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_themethod, "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                Value v_name = alg_str(alg_property(alg_subscript_get(alg_property(v_themethod, "Params"), v_i), "Lexeme"));
                (void)v_name;
                (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_name}, 1));
                Value v_slot = alg_add(alg_add(alg_string("args["), alg_str(v_i)), alg_char_value(93));
                (void)v_slot;
                if (alg_truthy(alg_less(v_i, alg_property(alg_property(v_themethod, "ParamTypes"), "Length")))) {
                    {
                        Value v_declared = alg_str(alg_subscript_get(alg_property(v_themethod, "ParamTypes"), v_i));
                        (void)v_declared;
                        if (alg_truthy((or_35 = alg_not_equal(v_declared, alg_string("")), !alg_truthy(or_35) ? or_35 : alg_not_equal(v_declared, alg_string("Any"))))) {
                            (void)((v_slot = alg_add(alg_add(alg_add(alg_add(alg_string("alg_widen("), v_slot), alg_string(", ")), f_quotec(NULL, (Value[]){v_declared}, 1)), alg_char_value(41))));
                        }
                    }
                }
                if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1))) {
                    (void)(alg_invoke(v_this, "DeclareCell", (Value[]){v_name, v_slot}, 2));
                } else {
                    {
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), alg_string(" = ")), v_slot), alg_char_value(59))}, 1));
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), alg_char_value(59))}, 1));
                    }
                }
            }
        }
    }
    (void)(alg_invoke(v_this, "HoistCells", (Value[]){alg_property(v_themethod, "Body")}, 1));
    (void)(alg_invoke(v_this, "PushLabels", (Value[]){alg_property(v_themethod, "Body")}, 1));
    {
        Value loop_37 = alg_iterable(alg_property(v_themethod, "Body"));
        for (int32_t at_37 = 0; at_37 < alg_iterable_count(loop_37); at_37++) {
            Value v_each = alg_iterable_at(loop_37, at_37);
            (void)v_each;
            (void)(alg_invoke(v_this, "Execute", (Value[]){v_each}, 1));
        }
    }
    (void)(alg_invoke(v_this, "PopLabels", NULL, 0));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("return alg_nil();")}, 1));
    Value v_written = alg_property(alg_property(v_this, "Body"), "Text");
    (void)v_written;
    (void)(alg_set_property(v_this, "Target", alg_widen(v_enclosingtarget, "String")));
    (void)(alg_set_property(v_this, "Body", alg_widen(v_enclosingbody, "Buffer")));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), alg_invoke(v_this, "MethodSymbol", (Value[]){v_owner, v_themethod}, 2)), alg_string("(Value v_this, Value *args, int32_t count) {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)v_this; (void)args; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_written}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_char_value(125), alg_char_value(10)), alg_char_value(10))}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(v_enclosingdepth, "Integer")));
    (void)(alg_set_property(v_this, "AtTopLevel", alg_widen(v_enclosingtop, "Boolean")));
    (void)(alg_set_property(v_this, "Locals", alg_widen(v_enclosinglocals, "List")));
    (void)(alg_set_property(v_this, "Volatiles", alg_widen(v_enclosingvolatiles, "Boolean")));
    (void)(alg_set_property(v_this, "Boxed", alg_widen(v_enclosingboxed, "List")));
    (void)(alg_set_property(v_this, "Captured", alg_widen(v_enclosingcaptured, "Map")));
    (void)(alg_set_property(v_this, "Cells", alg_widen(v_enclosingcells, "List")));
    (void)(alg_set_property(v_this, "TryDepth", alg_widen(v_enclosingtrydepth, "Integer")));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_widen(v_enclosinglooptry, "Integer")));
    return alg_nil();
}

static Value m_cemitter_emitclass_5_string_list_list_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_superclass = args[1];
    (void)v_superclass;
    Value v_fields = alg_widen(args[2], "List");
    (void)v_fields;
    Value v_methods = alg_widen(args[3], "List");
    (void)v_methods;
    Value v_isobject = alg_widen(args[4], "Boolean");
    (void)v_isobject;
    Value v_handle = alg_nil();
    (void)v_handle;
    Value v_supername = alg_nil();
    (void)v_supername;
    Value v_applied = alg_nil();
    (void)v_applied;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    Value v_enclosingclass = alg_nil();
    (void)v_enclosingclass;
    Value v_enclosingfields = alg_nil();
    (void)v_enclosingfields;
    Value v_enclosingmethods = alg_nil();
    (void)v_enclosingmethods;
    (void)((v_handle = alg_widen(alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1), "String")));
    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){v_handle, v_name}, 2));
    (void)((v_enclosingclass = alg_widen(alg_property(v_this, "CurrentClass"), "String")));
    (void)((v_enclosingfields = alg_widen(alg_property(v_this, "VisibleFields"), "Set")));
    (void)((v_enclosingmethods = alg_widen(alg_property(v_this, "VisibleMethods"), "Set")));
    (void)((v_supername = alg_widen(alg_string(""), "String")));
    if (alg_truthy(alg_not_equal(v_superclass, alg_nil()))) {
        (void)((v_supername = alg_widen(alg_str(alg_property(alg_property(v_superclass, "Name"), "Lexeme")), "String")));
    }
    (void)(alg_set_property(v_this, "CurrentClass", alg_widen(v_name, "String")));
    (void)(alg_set_property(v_this, "VisibleFields", alg_widen(alg_invoke(v_this, "NamesVisible", (Value[]){v_supername, v_fields, alg_bool(true)}, 3), "Set")));
    (void)(alg_set_property(v_this, "VisibleMethods", alg_widen(alg_invoke(v_this, "NamesVisible", (Value[]){v_supername, v_methods, alg_bool(false)}, 3), "Set")));
    Value v_declaresid = alg_bool(false);
    (void)v_declaresid;
    {
        Value loop_38 = alg_iterable(v_fields);
        for (int32_t at_38 = 0; at_38 < alg_iterable_count(loop_38); at_38++) {
            Value v_field = alg_iterable_at(loop_38, at_38);
            (void)v_field;
            if (alg_truthy(alg_equal(alg_str(alg_property(alg_property(v_field, "Name"), "Lexeme")), alg_string("Id")))) {
                (void)((v_declaresid = alg_bool(true)));
            }
        }
    }
    Value v_addid = (or_36 = v_isobject, !alg_truthy(or_36) ? or_36 : alg_not(v_declaresid));
    (void)v_addid;
    if (alg_truthy(v_addid)) {
        (void)(alg_invoke(alg_property(v_this, "VisibleFields"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_string("Id")}, 1)}, 1));
    }
    (void)((v_applied = alg_widen(alg_string(""), "String")));
    {
        Value loop_39 = alg_iterable(v_fields);
        for (int32_t at_39 = 0; at_39 < alg_iterable_count(loop_39); at_39++) {
            Value v_thefield = alg_iterable_at(loop_39, at_39);
            (void)v_thefield;
            {
                Value v_value = alg_string("alg_nil()");
                (void)v_value;
                if (alg_truthy(alg_not_equal(alg_property(v_thefield, "Initializer"), alg_nil()))) {
                    {
                        (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thefield, "Initializer")}, 1)));
                        (void)((v_value = alg_invoke(v_this, "BoundValue", (Value[]){alg_property(v_thefield, "TypeName"), v_value}, 2)));
                    }
                }
                (void)((v_applied = alg_widen(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(v_applied, alg_string("    alg_set_property(v_this, ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_thefield, "Name"), "Lexeme"))}, 1)), alg_string(", ")), v_value), alg_string(");")), alg_char_value(10)), "String")));
            }
        }
    }
    if (alg_truthy(v_addid)) {
        (void)((v_applied = alg_widen(alg_add(alg_add(alg_add(alg_add(v_applied, alg_string("    alg_set_property(v_this, \"Id\", alg_string(")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string("));")), alg_char_value(10)), "String")));
    }
    (void)((v_initializer = alg_widen(alg_invoke(v_this, "InitName", (Value[]){v_name}, 1), "String")));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_initializer), alg_string("(Value v_this, Value *args, int32_t count) {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)v_this; (void)args; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_applied}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("    return alg_nil();"), alg_char_value(10)), alg_char_value(125)), alg_char_value(10)), alg_char_value(10))}, 1));
    {
        Value loop_40 = alg_iterable(v_methods);
        for (int32_t at_40 = 0; at_40 < alg_iterable_count(loop_40); at_40++) {
            Value v_method = alg_iterable_at(loop_40, at_40);
            (void)v_method;
            (void)(alg_invoke(v_this, "EmitMethod", (Value[]){v_name, v_method}, 2));
        }
    }
    (void)(alg_set_property(v_this, "CurrentClass", alg_widen(v_enclosingclass, "String")));
    (void)(alg_set_property(v_this, "VisibleFields", alg_widen(v_enclosingfields, "Set")));
    (void)(alg_set_property(v_this, "VisibleMethods", alg_widen(v_enclosingmethods, "Set")));
    (void)(alg_invoke(alg_property(v_this, "Shells"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), v_handle), alg_string(" = alg_class(")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string(", alg_nil());")), alg_char_value(10))}, 1));
    Value v_hoisted = (or_37 = alg_equal(v_supername, alg_string("")), alg_truthy(or_37) ? or_37 : alg_invoke(alg_property(v_this, "OwnClasses"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_supername}, 1)}, 1));
    (void)v_hoisted;
    if (alg_truthy(alg_not_equal(v_supername, alg_string("")))) {
        {
            if (alg_truthy((or_38 = alg_not(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_supername}, 1)), !alg_truthy(or_38) ? or_38 : alg_not(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){v_supername}, 1))))) {
                alg_raise(alg_add(alg_add(alg_char_value(39), v_supername), alg_string("' is not a class.")));
            }
            if (alg_truthy(alg_not(v_hoisted))) {
                (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_add(alg_add(alg_string("alg_class_declared("), alg_invoke(v_this, "ClassHandle", (Value[]){v_supername}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){v_supername}, 1)), alg_string(");"))}, 2));
            }
            (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_add(alg_add(alg_string("alg_class_super("), v_handle), alg_string(", ")), alg_invoke(v_this, "ClassHandle", (Value[]){v_supername}, 1)), alg_string(");"))}, 2));
        }
    }
    {
        Value loop_41 = alg_iterable(v_fields);
        for (int32_t at_41 = 0; at_41 < alg_iterable_count(loop_41); at_41++) {
            Value v_eachfield = alg_iterable_at(loop_41, at_41);
            (void)v_eachfield;
            (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_add(alg_add(alg_string("alg_class_field("), v_handle), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_eachfield, "Name"), "Lexeme"))}, 1)), alg_string(");"))}, 2));
        }
    }
    if (alg_truthy(v_addid)) {
        (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_string("alg_class_field("), v_handle), alg_string(", \"Id\");"))}, 2));
    }
    (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_add(alg_add(alg_string("alg_class_initializer("), v_handle), alg_string(", ")), v_initializer), alg_string(");"))}, 2));
    {
        Value loop_42 = alg_iterable(v_methods);
        for (int32_t at_42 = 0; at_42 < alg_iterable_count(loop_42); at_42++) {
            Value v_themethod = alg_iterable_at(loop_42, at_42);
            (void)v_themethod;
            {
                Value v_types = alg_invoke(v_this, "ParameterTable", (Value[]){v_themethod}, 1);
                (void)v_types;
                Value v_table = alg_string("NULL");
                (void)v_table;
                if (alg_truthy(alg_greater(alg_property(v_types, "Length"), alg_int(0)))) {
                    {
                        (void)((v_table = alg_add(alg_string("t_"), alg_copy(alg_invoke(v_this, "MethodSymbol", (Value[]){v_name, v_themethod}, 2), alg_int(2), alg_subtract(alg_text_length(alg_invoke(v_this, "MethodSymbol", (Value[]){v_name, v_themethod}, 2)), alg_int(2))))));
                        Value v_quoted = alg_string("");
                        (void)v_quoted;
                        {
                            Value v_j = alg_int(0);
                            (void)v_j;
                            for (; alg_truthy(alg_less(v_j, alg_property(v_types, "Length"))); (v_j = alg_add(v_j, alg_int(1)))) {
                                {
                                    if (alg_truthy(alg_greater(v_j, alg_int(0)))) {
                                        (void)((v_quoted = alg_add(v_quoted, alg_string(", "))));
                                    }
                                    (void)((v_quoted = alg_add(v_quoted, f_quotec(NULL, (Value[]){alg_str(alg_subscript_get(v_types, v_j))}, 1))));
                                }
                            }
                        }
                        (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("static const char *"), v_table), alg_string("[] = { ")), v_quoted), alg_string(" };")), alg_char_value(10))}, 1));
                    }
                }
                if (alg_truthy(alg_property(v_themethod, "IsProperty"))) {
                    (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_class_property("), v_handle), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_themethod, "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "MethodSymbol", (Value[]){v_name, v_themethod}, 2)), alg_string(");"))}, 2));
                } else {
                    (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_class_method("), v_handle), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_themethod, "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "MethodSymbol", (Value[]){v_name, v_themethod}, 2)), alg_string(", ")), alg_str(alg_property(alg_property(v_themethod, "Params"), "Length"))), alg_string(", ")), v_table), alg_string(");"))}, 2));
                }
            }
        }
    }
    if (alg_truthy(v_isobject)) {
        (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_string("alg_class_is_object("), v_handle), alg_string(");"))}, 2));
    }
    return alg_nil();
}

static Value m_cemitter_built_2_boolean_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_hoisted = alg_widen(args[0], "Boolean");
    (void)v_hoisted;
    Value v_text = alg_widen(args[1], "String");
    (void)v_text;
    if (alg_truthy(v_hoisted)) {
        (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_string("    "), v_text), alg_char_value(10))}, 1));
    } else {
        (void)(alg_invoke(v_this, "Line", (Value[]){v_text}, 1));
    }
    return alg_nil();
}

static Value m_cemitter_visitvarstmt_1_varstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "VarStmt");
    (void)v_thestmt;
    Value v_value = alg_nil();
    (void)v_value;
    (void)((v_value = alg_widen(alg_string("alg_nil()"), "String")));
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Initializer"), alg_nil()))) {
        {
            (void)((v_value = alg_widen(alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Initializer")}, 1), "String")));
            if (alg_truthy((or_39 = alg_not_equal(alg_str(alg_property(v_thestmt, "TypeName")), alg_string("")), !alg_truthy(or_39) ? or_39 : alg_not_equal(alg_str(alg_property(v_thestmt, "TypeName")), alg_string("Any"))))) {
                (void)((v_value = alg_widen(alg_add(alg_add(alg_add(alg_add(alg_string("alg_widen("), v_value), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(v_thestmt, "TypeName"))}, 1)), alg_char_value(41)), "String")));
            }
        }
    }
    if (alg_truthy(alg_property(v_this, "AtTopLevel"))) {
        {
            (void)(alg_invoke(v_this, "DeclareVariable", (Value[]){alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1), alg_string(" = ")), v_value), alg_char_value(59))}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_invoke(v_this, "DeclaredFlag", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1), alg_string(" = true;"))}, 1));
        }
    } else {
        if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1))) {
            {
                (void)(alg_invoke(v_this, "RequireCell", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_char_value(42), alg_invoke(v_this, "Cell", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)), alg_string(" = ")), v_value), alg_char_value(59))}, 1));
            }
        } else {
            {
                (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)), alg_string(" = ")), v_value), alg_char_value(59))}, 1));
                (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)), alg_char_value(59))}, 1));
            }
        }
    }
    return alg_nil();
}

static Value m_cemitter_visitexpressionstmt_1_expressionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "ExpressionStmt");
    (void)v_thestmt;
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Expression")}, 1)), alg_string(");"))}, 1));
    return alg_nil();
}

static Value m_cemitter_pushlabels_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    Value v_here = alg_nil();
    (void)v_here;
    (void)((v_here = alg_widen(alg_map(), "Map")));
    {
        Value loop_43 = alg_iterable(v_statements);
        for (int32_t at_43 = 0; at_43 < alg_iterable_count(loop_43); at_43++) {
            Value v_statement = alg_iterable_at(loop_43, at_43);
            (void)v_statement;
            if (alg_truthy(alg_is(v_statement, "LabelStmt"))) {
                (void)(alg_invoke(v_here, "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(v_statement, "Name"), "Lexeme"))}, 1), alg_property(v_this, "TryDepth")}, 2));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "LabelDepths"), "Add", (Value[]){v_here}, 1));
    return alg_nil();
}

static Value m_cemitter_poplabels_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    (void)(alg_invoke(alg_property(v_this, "LabelDepths"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LabelDepths"), "Length"), alg_int(1))}, 1));
    return alg_nil();
}

static Value m_cemitter_depthoflabel_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    Value v_folded = alg_nil();
    (void)v_folded;
    (void)((v_folded = alg_widen(f_foldcase(NULL, (Value[]){v_thelabel}, 1), "String")));
    {
        Value v_s = alg_subtract(alg_property(alg_property(v_this, "LabelDepths"), "Length"), alg_int(1));
        (void)v_s;
        for (; alg_truthy(alg_greater_equal(v_s, alg_int(0))); (v_s = alg_subtract(v_s, alg_int(1)))) {
            if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "LabelDepths"), v_s), "Contains", (Value[]){v_folded}, 1))) {
                return alg_cast(alg_invoke(alg_subscript_get(alg_property(v_this, "LabelDepths"), v_s), "Get", (Value[]){v_folded}, 1), "Integer");
            }
        }
    }
    return alg_property(v_this, "TryDepth");
    return alg_nil();
}

static Value m_cemitter_gototarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    return alg_add(alg_string("lg_"), alg_invoke(v_this, "Escaped", (Value[]){f_foldcase(NULL, (Value[]){v_thelabel}, 1)}, 1));
    return alg_nil();
}

static Value m_cemitter_visitgotostmt_1_gotostmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "GotoStmt");
    (void)v_thestmt;
    (void)(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_invoke(v_this, "DepthOfLabel", (Value[]){alg_property(v_thestmt, "Label")}, 1)}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("goto "), alg_invoke(v_this, "GotoTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1)), alg_char_value(59))}, 1));
    return alg_nil();
}

static Value m_cemitter_visitblockstmt_1_blockstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "BlockStmt");
    (void)v_thestmt;
    Value v_mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_mark;
    Value v_enclosingtop = alg_property(v_this, "AtTopLevel");
    (void)v_enclosingtop;
    (void)(alg_set_property(v_this, "AtTopLevel", alg_widen(alg_bool(false), "Boolean")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_add(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "HoistCells", (Value[]){alg_property(v_thestmt, "Statements")}, 1));
    (void)(alg_invoke(v_this, "PushLabels", (Value[]){alg_property(v_thestmt, "Statements")}, 1));
    {
        Value loop_44 = alg_iterable(alg_property(v_thestmt, "Statements"));
        for (int32_t at_44 = 0; at_44 < alg_iterable_count(loop_44); at_44++) {
            Value v_statement = alg_iterable_at(loop_44, at_44);
            (void)v_statement;
            (void)(alg_invoke(v_this, "Execute", (Value[]){v_statement}, 1));
        }
    }
    (void)(alg_invoke(v_this, "PopLabels", NULL, 0));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_set_property(v_this, "AtTopLevel", alg_widen(v_enclosingtop, "Boolean")));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1));
    return alg_nil();
}

static Value m_cemitter_visitifstmt_1_ifstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "IfStmt");
    (void)v_thestmt;
    (void)(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_property(v_thestmt, "ThenBranch")}, 1));
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "ElseBranch"), alg_nil()))) {
        (void)(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_property(v_thestmt, "ElseBranch")}, 1));
    }
    Value v_mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_mark;
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("if (alg_truthy("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Condition")}, 1)), alg_string(")) {"))}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_add(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "ThenBranch")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1));
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "ElseBranch"), alg_nil()))) {
        {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("} else {")}, 1));
            (void)(alg_set_property(v_this, "Depth", alg_widen(alg_add(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
            (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "ElseBranch")}, 1));
            (void)(alg_set_property(v_this, "Depth", alg_widen(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
            (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    return alg_nil();
}

static Value m_cemitter_visitwhilestmt_1_whilestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "WhileStmt");
    (void)v_thestmt;
    (void)(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    Value v_mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_mark;
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Increment"), alg_nil()))) {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("for (; alg_truthy("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Condition")}, 1)), alg_string("); ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Increment")}, 1)), alg_string(") {"))}, 1));
    } else {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("while (alg_truthy("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Condition")}, 1)), alg_string(")) {"))}, 1));
    }
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_add(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    Value v_enclosingloopdepth = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosingloopdepth;
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_widen(alg_property(v_this, "TryDepth"), "Integer")));
    (void)(alg_invoke(alg_property(v_this, "LoopLabels"), "Add", (Value[]){alg_property(v_thestmt, "Label")}, 1));
    (void)(alg_invoke(alg_property(v_this, "LoopDepths"), "Add", (Value[]){alg_property(v_this, "TryDepth")}, 1));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    (void)(alg_invoke(alg_property(v_this, "LoopLabels"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LoopLabels"), "Length"), alg_int(1))}, 1));
    (void)(alg_invoke(alg_property(v_this, "LoopDepths"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LoopDepths"), "Length"), alg_int(1))}, 1));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_widen(v_enclosingloopdepth, "Integer")));
    (void)(alg_invoke(v_this, "EmitContinueTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "EmitBreakTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1));
    return alg_nil();
}

static Value m_cemitter_emitcontinuetarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    if (alg_truthy(alg_equal(v_thelabel, alg_string("")))) {
        return alg_nil();
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Jumped"), "Contains", (Value[]){alg_invoke(v_this, "ContinueTarget", (Value[]){v_thelabel}, 1)}, 1)))) {
        return alg_nil();
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_invoke(v_this, "ContinueTarget", (Value[]){v_thelabel}, 1), alg_string(": ;"))}, 1));
    return alg_nil();
}

static Value m_cemitter_emitbreaktarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    if (alg_truthy(alg_equal(v_thelabel, alg_string("")))) {
        return alg_nil();
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Jumped"), "Contains", (Value[]){alg_invoke(v_this, "BreakTarget", (Value[]){v_thelabel}, 1)}, 1)))) {
        return alg_nil();
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_invoke(v_this, "BreakTarget", (Value[]){v_thelabel}, 1), alg_string(": ;"))}, 1));
    return alg_nil();
}

static Value m_cemitter_visitreturnstmt_1_returnstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "ReturnStmt");
    (void)v_thestmt;
    Value v_value = alg_nil();
    (void)v_value;
    (void)((v_value = alg_widen(alg_string("alg_nil()"), "String")));
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Value"), alg_nil()))) {
        (void)((v_value = alg_widen(alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Value")}, 1), "String")));
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "TryDepth"), alg_int(0)))) {
        {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("return "), v_value), alg_char_value(59))}, 1));
            return alg_nil();
        }
    }
    Value v_slot = alg_add(alg_string("ret_"), alg_str(alg_property(v_this, "Loops")));
    (void)v_slot;
    (void)(alg_set_property(v_this, "Loops", alg_widen(alg_add(alg_property(v_this, "Loops"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), v_slot), alg_string(" = ")), v_value), alg_char_value(59))}, 1));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(v_this, "TryDepth"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("alg_pop_frame();")}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("return "), v_slot), alg_char_value(59))}, 1));
    return alg_nil();
}

static Value m_cemitter_emitforeign_1_functionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "FunctionStmt");
    (void)v_thestmt;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    (void)((v_symbol = alg_widen(alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1), "String")));
    Value v_table = alg_invoke(v_this, "TypeTable", (Value[]){v_symbol, alg_invoke(v_this, "ParameterTable", (Value[]){v_thestmt}, 1)}, 2);
    (void)v_table;
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), v_symbol), alg_string("(Value **cells, Value *args, int32_t count) {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)cells; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    return alg_foreign("), f_quotec(NULL, (Value[]){alg_str(alg_property(v_thestmt, "Symbol"))}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(v_thestmt, "Library"))}, 1)), alg_string(", ")), v_table), alg_string(", ")), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(v_thestmt, "ReturnType"))}, 1)), alg_string(", args);")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_char_value(125), alg_char_value(10)), alg_char_value(10))}, 1));
    Value v_name = alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"));
    (void)v_name;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1))) {
        {
            if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)}, 1)))) {
                {
                    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){alg_invoke(v_this, "SetName", (Value[]){v_name}, 1), v_name}, 2));
                    (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)), alg_string(" = alg_overloads(")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_overload("), alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)), alg_string(", ")), v_symbol), alg_string(", ")), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), alg_string(", ")), v_table), alg_string(");")), alg_char_value(10))}, 1));
            return alg_nil();
        }
    }
    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1), v_name}, 2));
    (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1)), alg_string(" = alg_closure(")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string(", ")), v_symbol), alg_string(", NULL, 0, ")), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), alg_string(", ")), v_table), alg_string(");")), alg_char_value(10))}, 1));
    return alg_nil();
}

static Value m_cemitter_visitfunctionstmt_1_functionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "FunctionStmt");
    (void)v_thestmt;
    Value v_enclosinglocals = alg_nil();
    (void)v_enclosinglocals;
    Value v_enclosingtop = alg_nil();
    (void)v_enclosingtop;
    Value v_enclosingdepth = alg_nil();
    (void)v_enclosingdepth;
    if (alg_truthy(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1))) {
        {
            if (alg_truthy(alg_property(v_this, "EmitTests"))) {
                (void)(alg_invoke(v_this, "EmitTest", (Value[]){v_thestmt}, 1));
            }
            return alg_nil();
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Symbol"), alg_string("")))) {
        {
            (void)(alg_invoke(v_this, "EmitForeign", (Value[]){v_thestmt}, 1));
            return alg_nil();
        }
    }
    Value v_nested = alg_not(alg_property(v_this, "AtTopLevel"));
    (void)v_nested;
    (void)((v_enclosinglocals = alg_widen(alg_property(v_this, "Locals"), "List")));
    (void)((v_enclosingtop = alg_widen(alg_property(v_this, "AtTopLevel"), "Boolean")));
    (void)((v_enclosingdepth = alg_widen(alg_property(v_this, "Depth"), "Integer")));
    Value v_enclosingboxed = alg_property(v_this, "Boxed");
    (void)v_enclosingboxed;
    Value v_enclosingcaptured = alg_property(v_this, "Captured");
    (void)v_enclosingcaptured;
    Value v_enclosingcells = alg_property(v_this, "Cells");
    (void)v_enclosingcells;
    Value v_enclosingnested = alg_property(v_this, "InsideNested");
    (void)v_enclosingnested;
    (void)(alg_set_property(v_this, "Locals", alg_widen(alg_list(), "List")));
    Value v_inherited = alg_invoke(v_this, "VisibleCells", (Value[]){alg_property(v_this, "Captured"), v_enclosingcells}, 2);
    (void)v_inherited;
    if (alg_truthy(v_nested)) {
        {
            Value v_index = alg_map();
            (void)v_index;
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(v_inherited, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(v_index, "Put", (Value[]){alg_str(alg_subscript_get(v_inherited, v_i)), v_i}, 2));
                }
            }
            (void)(alg_set_property(v_this, "Captured", alg_widen(v_index, "Map")));
            (void)(alg_set_property(v_this, "InsideNested", alg_widen(alg_bool(true), "Boolean")));
        }
    } else {
        (void)(alg_set_property(v_this, "Captured", alg_widen(alg_map(), "Map")));
    }
    (void)(alg_set_property(v_this, "Cells", alg_widen(alg_list(), "List")));
    Value v_enclosingvolatiles = alg_property(v_this, "Volatiles");
    (void)v_enclosingvolatiles;
    (void)(alg_set_property(v_this, "Volatiles", alg_widen(alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_thestmt, "Body")}, 1), "Boolean")));
    Value v_enclosingtrydepth = alg_property(v_this, "TryDepth");
    (void)v_enclosingtrydepth;
    Value v_enclosinglooptry = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosinglooptry;
    (void)(alg_set_property(v_this, "TryDepth", alg_widen(alg_int(0), "Integer")));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_widen(alg_int(0), "Integer")));
    (void)(alg_set_property(v_this, "Boxed", alg_widen(alg_list(), "List")));
    if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_property(v_thestmt, "Body")}, 1))) {
        (void)(alg_set_property(v_this, "Boxed", alg_widen(alg_invoke(v_this, "BoundNames", (Value[]){v_thestmt}, 1), "List")));
    }
    (void)(alg_set_property(v_this, "AtTopLevel", alg_widen(alg_bool(false), "Boolean")));
    Value v_enclosingtarget = alg_property(v_this, "Target");
    (void)v_enclosingtarget;
    Value v_enclosingbody = alg_property(v_this, "Body");
    (void)v_enclosingbody;
    (void)(alg_set_property(v_this, "Target", alg_widen(alg_string("body"), "String")));
    (void)(alg_set_property(v_this, "Body", alg_widen(alg_buffer(alg_int(0)), "Buffer")));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_int(1), "Integer")));
    if (alg_truthy(alg_not(v_nested))) {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_arity(count, "), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), alg_string(");"))}, 1));
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                Value v_paramname = alg_str(alg_property(alg_subscript_get(alg_property(v_thestmt, "Params"), v_i), "Lexeme"));
                (void)v_paramname;
                (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_paramname}, 1));
                if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_paramname}, 1))) {
                    {
                        Value v_qualifier = alg_string("Value *");
                        (void)v_qualifier;
                        if (alg_truthy(alg_property(v_this, "Volatiles"))) {
                            (void)((v_qualifier = alg_string("Value *volatile ")));
                        }
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(v_qualifier, alg_invoke(v_this, "Cell", (Value[]){v_paramname}, 1)), alg_string(" = alg_cell(")), alg_invoke(v_this, "BoundArgument", (Value[]){alg_property(v_thestmt, "Params"), alg_property(v_thestmt, "ParamTypes"), v_i}, 3)), alg_string(");"))}, 1));
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "Cell", (Value[]){v_paramname}, 1)), alg_char_value(59))}, 1));
                        (void)(alg_invoke(alg_property(v_this, "Cells"), "Add", (Value[]){v_paramname}, 1));
                    }
                } else {
                    {
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){v_paramname}, 1)), alg_string(" = ")), alg_invoke(v_this, "BoundArgument", (Value[]){alg_property(v_thestmt, "Params"), alg_property(v_thestmt, "ParamTypes"), v_i}, 3)), alg_char_value(59))}, 1));
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "VariableName", (Value[]){v_paramname}, 1)), alg_char_value(59))}, 1));
                    }
                }
            }
        }
    }
    (void)(alg_invoke(v_this, "HoistCells", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    (void)(alg_invoke(v_this, "PushLabels", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    {
        Value loop_45 = alg_iterable(alg_property(v_thestmt, "Body"));
        for (int32_t at_45 = 0; at_45 < alg_iterable_count(loop_45); at_45++) {
            Value v_each = alg_iterable_at(loop_45, at_45);
            (void)v_each;
            (void)(alg_invoke(v_this, "Execute", (Value[]){v_each}, 1));
        }
    }
    (void)(alg_invoke(v_this, "PopLabels", NULL, 0));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("return alg_nil();")}, 1));
    Value v_written = alg_property(alg_property(v_this, "Body"), "Text");
    (void)v_written;
    (void)(alg_set_property(v_this, "Target", alg_widen(v_enclosingtarget, "String")));
    (void)(alg_set_property(v_this, "Body", alg_widen(v_enclosingbody, "Buffer")));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_invoke(v_this, "Prototype", (Value[]){v_thestmt}, 1), alg_string(" {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)cells; (void)args; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_written}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_char_value(125), alg_char_value(10)), alg_char_value(10))}, 1));
    Value v_capturedcells = v_inherited;
    (void)v_capturedcells;
    (void)(alg_set_property(v_this, "Depth", alg_widen(v_enclosingdepth, "Integer")));
    (void)(alg_set_property(v_this, "AtTopLevel", alg_widen(v_enclosingtop, "Boolean")));
    (void)(alg_set_property(v_this, "Locals", alg_widen(v_enclosinglocals, "List")));
    (void)(alg_set_property(v_this, "Volatiles", alg_widen(v_enclosingvolatiles, "Boolean")));
    (void)(alg_set_property(v_this, "Boxed", alg_widen(v_enclosingboxed, "List")));
    (void)(alg_set_property(v_this, "Captured", alg_widen(v_enclosingcaptured, "Map")));
    (void)(alg_set_property(v_this, "Cells", alg_widen(v_enclosingcells, "List")));
    (void)(alg_set_property(v_this, "TryDepth", alg_widen(v_enclosingtrydepth, "Integer")));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_widen(v_enclosinglooptry, "Integer")));
    (void)(alg_set_property(v_this, "InsideNested", alg_widen(v_enclosingnested, "Boolean")));
    Value v_name = alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"));
    (void)v_name;
    if (alg_truthy(v_nested)) {
        {
            (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_name}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), alg_string(" = ")), alg_invoke(v_this, "ClosureOf", (Value[]){v_thestmt, v_capturedcells}, 2)), alg_char_value(59))}, 1));
        }
    } else {
        if (alg_truthy(alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1))) {
            {
                if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "SetsBuilt"), "Contains", (Value[]){v_name}, 1)))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "SetsBuilt"), "Add", (Value[]){v_name}, 1));
                        (void)(alg_invoke(v_this, "DeclareValue", (Value[]){alg_invoke(v_this, "SetName", (Value[]){v_name}, 1), v_name}, 2));
                        (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)), alg_string(" = alg_overloads(")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                    }
                }
                (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_overload("), alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)), alg_string(", ")), alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1)), alg_string(", ")), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), alg_string(", ")), alg_invoke(v_this, "TypeTable", (Value[]){alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1), alg_invoke(v_this, "ParameterTable", (Value[]){v_thestmt}, 1)}, 2)), alg_string(");")), alg_char_value(10))}, 1));
            }
        } else {
            {
                (void)(alg_invoke(v_this, "DeclareValue", (Value[]){alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1), v_name}, 2));
                (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1)), alg_string(" = ")), alg_invoke(v_this, "ClosureOf", (Value[]){v_thestmt, alg_list()}, 2)), alg_char_value(59)), alg_char_value(10))}, 1));
            }
        }
    }
    return alg_nil();
}

static Value m_cemitter_typetable_2_string_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_symbol = alg_widen(args[0], "String");
    (void)v_symbol;
    Value v_types = alg_widen(args[1], "List");
    (void)v_types;
    Value v_table = alg_nil();
    (void)v_table;
    if (alg_truthy(alg_equal(alg_property(v_types, "Length"), alg_int(0)))) {
        return alg_string("NULL");
    }
    (void)((v_table = alg_widen(alg_add(alg_string("t_"), v_symbol), "String")));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Tables"), "Contains", (Value[]){v_table}, 1))) {
        return v_table;
    }
    (void)(alg_invoke(alg_property(v_this, "Tables"), "Add", (Value[]){v_table}, 1));
    Value v_quoted = alg_string("");
    (void)v_quoted;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(v_types, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                    (void)((v_quoted = alg_add(v_quoted, alg_string(", "))));
                }
                (void)((v_quoted = alg_add(v_quoted, f_quotec(NULL, (Value[]){alg_str(alg_subscript_get(v_types, v_i))}, 1))));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("static const char *"), v_table), alg_string("[] = { ")), v_quoted), alg_string(" };")), alg_char_value(10))}, 1));
    return v_table;
    return alg_nil();
}

static Value m_cemitter_visitliteral_1_literalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "LiteralExpr");
    (void)v_theexpr;
    Value v_value = alg_nil();
    (void)v_value;
    (void)((v_value = alg_property(v_theexpr, "Value")));
    if (alg_truthy(alg_equal(v_value, alg_nil()))) {
        return alg_string("alg_nil()");
    }
    if (alg_truthy(alg_equal(v_value, alg_bool(true)))) {
        return alg_string("alg_bool(true)");
    }
    if (alg_truthy(alg_equal(v_value, alg_bool(false)))) {
        return alg_string("alg_bool(false)");
    }
    if (alg_truthy(alg_is(v_value, "Integer"))) {
        {
            if (alg_truthy((or_40 = alg_greater(v_value, alg_int(9223372036854775807)), alg_truthy(or_40) ? or_40 : alg_less(v_value, alg_negate(alg_int(9223372036854775807)))))) {
                return alg_add(alg_add(alg_string("alg_integer("), f_quotec(NULL, (Value[]){alg_str(v_value)}, 1)), alg_char_value(41));
            }
            return alg_add(alg_add(alg_string("alg_int("), alg_str(v_value)), alg_char_value(41));
        }
    }
    if (alg_truthy(alg_is(v_value, "Double"))) {
        return alg_add(alg_add(alg_string("alg_double("), alg_str(v_value)), alg_char_value(41));
    }
    if (alg_truthy(alg_is(v_value, "String"))) {
        return alg_add(alg_add(alg_string("alg_string("), f_quotec(NULL, (Value[]){alg_str(v_value)}, 1)), alg_char_value(41));
    }
    if (alg_truthy(alg_is(v_value, "Char"))) {
        return alg_add(alg_add(alg_string("alg_char_value("), alg_str(alg_ord(v_value))), alg_char_value(41));
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_string("A literal of type "), f_typenameof(NULL, (Value[]){v_value}, 1))}, 1));
    return alg_nil();
}

static Value m_cemitter_visitvariableexpr_1_variableexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "VariableExpr");
    (void)v_theexpr;
    Value v_name = alg_nil();
    (void)v_name;
    (void)((v_name = alg_widen(alg_invoke(v_this, "Spelled", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1), "String")));
    if (alg_truthy((or_41 = alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1), alg_truthy(or_41) ? or_41 : alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1)))) {
        return alg_invoke(v_this, "Read", (Value[]){v_name}, 1);
    }
    if (alg_truthy((or_43 = (or_42 = alg_not_equal(alg_property(v_this, "CurrentClass"), alg_string("")), !alg_truthy(or_42) ? or_42 : alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_43) ? or_43 : alg_invoke(alg_property(v_this, "VisibleFields"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1)))) {
        return alg_add(alg_add(alg_add(alg_add(alg_string("alg_property("), alg_invoke(v_this, "ThisRef", NULL, 0)), alg_string(", ")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_char_value(41));
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)))) {
        {
            if (alg_truthy(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Contains", (Value[]){v_name}, 1))) {
                return alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "AmbiguousMessage", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme")), alg_str(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Get", (Value[]){v_name}, 1))}, 2)}, 1)), alg_string("), alg_nil())"));
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Contains", (Value[]){v_name}, 1))) {
                return alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "AmbiguousMessage", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme")), alg_str(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Get", (Value[]){v_name}, 1))}, 2)}, 1)), alg_string("), alg_nil())"));
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_name}, 1))) {
                return alg_invoke(v_this, "EnumMemberName", (Value[]){alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_name}, 1)), v_name}, 2);
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "EnumTypes"), "Contains", (Value[]){v_name}, 1))) {
                return alg_invoke(v_this, "EnumTypeName", (Value[]){v_name}, 1);
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){v_name}, 1))) {
                return alg_add(alg_add(alg_string("alg_singleton("), alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)), alg_char_value(41));
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1))) {
                return alg_invoke(v_this, "SubprogramValue", (Value[]){v_name}, 1);
            }
        }
    }
    (void)(alg_invoke(v_this, "Unreachable", (Value[]){v_name}, 1));
    if (alg_truthy((or_46 = (or_45 = (or_44 = alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)), !alg_truthy(or_44) ? or_44 : alg_not(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_45) ? or_45 : alg_not(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_46) ? or_46 : alg_not(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){v_name}, 1))))) {
        return alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "MissingName", (Value[]){v_name}, 1)}, 1)), alg_string("), alg_nil())"));
    }
    return alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)}, 2);
    return alg_nil();
}

static Value m_cemitter_guarded_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_text = alg_widen(args[1], "String");
    (void)v_text;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1))) {
        return v_text;
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))) {
        return v_text;
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("(alg_declared("), alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string("), ")), v_text), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_missingname_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_units = alg_nil();
    (void)v_units;
    (void)((v_units = alg_widen(alg_invoke(alg_property(v_this, "UnitExports"), "Keys", NULL, 0), "List")));
    {
        Value loop_46 = alg_iterable(v_units);
        for (int32_t at_46 = 0; at_46 < alg_iterable_count(loop_46); at_46++) {
            Value v_theunit = alg_iterable_at(loop_46, at_46);
            (void)v_theunit;
            if (alg_truthy(alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_theunit}, 1), "Set")), "Contains", (Value[]){v_name}, 1))) {
                return alg_add(alg_add(alg_add(alg_add(alg_string("Undefined variable '"), v_name), alg_string("'. Unit '")), alg_str(v_theunit)), alg_string("' exports it; this file has no 'uses' for it."));
            }
        }
    }
    return alg_add(alg_add(alg_string("Undefined variable '"), v_name), alg_string("'."));
    return alg_nil();
}

static Value m_cemitter_spelled_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1))) {
        return alg_str(v_name);
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Canonical"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
        return alg_str(alg_invoke(alg_property(v_this, "Canonical"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1));
    }
    return alg_str(v_name);
    return alg_nil();
}

static Value m_cemitter_unreachable_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    if (alg_truthy(alg_not(alg_property(v_this, "InsideNested")))) {
        return alg_nil();
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1))) {
        return alg_nil();
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1))) {
        return alg_nil();
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("Reading '"), v_name), alg_string("' from a nested function"))}, 1));
    return alg_nil();
}

static Value m_cemitter_boundvalue_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_declared = args[0];
    (void)v_declared;
    Value v_value = alg_widen(args[1], "String");
    (void)v_value;
    if (alg_truthy((or_47 = alg_equal(alg_str(v_declared), alg_string("")), alg_truthy(or_47) ? or_47 : alg_equal(alg_str(v_declared), alg_string("Any"))))) {
        return alg_str(v_value);
    }
    return alg_add(alg_add(alg_add(alg_add(alg_string("alg_widen("), alg_str(v_value)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(v_declared)}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_visitassignexpr_1_assignexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "AssignExpr");
    (void)v_theexpr;
    Value v_name = alg_nil();
    (void)v_name;
    (void)((v_name = alg_widen(alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme")), "String")));
    Value v_written = alg_invoke(v_this, "BoundValue", (Value[]){alg_property(v_theexpr, "Declared"), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1)}, 2);
    (void)v_written;
    if (alg_truthy((or_48 = alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1), alg_truthy(or_48) ? or_48 : alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1)))) {
        return alg_add(alg_add(alg_add(alg_add(alg_char_value(40), alg_invoke(v_this, "Read", (Value[]){v_name}, 1)), alg_string(" = ")), v_written), alg_char_value(41));
    }
    if (alg_truthy((or_50 = (or_49 = alg_not_equal(alg_property(v_this, "CurrentClass"), alg_string("")), !alg_truthy(or_49) ? or_49 : alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_50) ? or_50 : alg_invoke(alg_property(v_this, "VisibleFields"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1)))) {
        return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_set_property("), alg_invoke(v_this, "ThisRef", NULL, 0)), alg_string(", ")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string(", ")), v_written), alg_char_value(41));
    }
    (void)(alg_invoke(v_this, "Unreachable", (Value[]){v_name}, 1));
    return alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_add(alg_add(alg_add(alg_add(alg_char_value(40), alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), alg_string(" = ")), v_written), alg_char_value(41))}, 2);
    return alg_nil();
}

static Value m_cemitter_visitgrouping_1_groupingexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "GroupingExpr");
    (void)v_theexpr;
    return alg_add(alg_add(alg_char_value(40), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Expression")}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_visitisexpr_1_isexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "IsExpr");
    (void)v_theexpr;
    return alg_add(alg_add(alg_add(alg_add(alg_string("alg_is("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){f_canonicaltype(NULL, (Value[]){alg_property(alg_property(v_theexpr, "TypeName"), "Lexeme")}, 1)}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_visitunary_1_unaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "UnaryExpr");
    (void)v_theexpr;
    Value v_operand = alg_nil();
    (void)v_operand;
    (void)((v_operand = alg_widen(alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Right")}, 1), "String")));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVminus))) {
        return alg_add(alg_add(alg_string("alg_negate("), v_operand), alg_char_value(41));
    } else {
        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVnot))) {
            return alg_add(alg_add(alg_string("alg_not("), v_operand), alg_char_value(41));
        }
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("Unary '"), alg_str(alg_property(alg_property(v_theexpr, "Op"), "Lexeme"))), alg_char_value(39))}, 1));
    return alg_nil();
}

static Value m_cemitter_visitbinary_1_binaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "BinaryExpr");
    (void)v_theexpr;
    Value v_left = alg_nil();
    (void)v_left;
    Value v_right = alg_nil();
    (void)v_right;
    Value v_call = alg_nil();
    (void)v_call;
    (void)((v_left = alg_widen(alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Left")}, 1), "String")));
    (void)((v_right = alg_widen(alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Right")}, 1), "String")));
    (void)((v_call = alg_widen(alg_string(""), "String")));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVplus))) {
        (void)((v_call = alg_widen(alg_string("alg_add"), "String")));
    } else {
        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVminus))) {
            (void)((v_call = alg_widen(alg_string("alg_subtract"), "String")));
        } else {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVstar))) {
                (void)((v_call = alg_widen(alg_string("alg_multiply"), "String")));
            } else {
                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVslash))) {
                    (void)((v_call = alg_widen(alg_string("alg_divide"), "String")));
                } else {
                    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVdiv))) {
                        (void)((v_call = alg_widen(alg_string("alg_div_int"), "String")));
                    } else {
                        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVgreater))) {
                            (void)((v_call = alg_widen(alg_string("alg_greater"), "String")));
                        } else {
                            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVgreaterVequal))) {
                                (void)((v_call = alg_widen(alg_string("alg_greater_equal"), "String")));
                            } else {
                                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVless))) {
                                    (void)((v_call = alg_widen(alg_string("alg_less"), "String")));
                                } else {
                                    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVlessVequal))) {
                                        (void)((v_call = alg_widen(alg_string("alg_less_equal"), "String")));
                                    } else {
                                        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVequal))) {
                                            (void)((v_call = alg_widen(alg_string("alg_equal"), "String")));
                                        } else {
                                            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVnotVequal))) {
                                                (void)((v_call = alg_widen(alg_string("alg_not_equal"), "String")));
                                            } else {
                                                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVin))) {
                                                    (void)((v_call = alg_widen(alg_string("alg_in"), "String")));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (alg_truthy(alg_equal(v_call, alg_string("")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("Binary '"), alg_str(alg_property(alg_property(v_theexpr, "Op"), "Lexeme"))), alg_char_value(39))}, 1));
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(v_call, alg_char_value(40)), v_left), alg_string(", ")), v_right), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_builtincounts_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_counts = alg_nil();
    (void)v_counts;
    (void)((v_counts = alg_widen(alg_list(), "List")));
    {
        Value v_k = alg_int(0);
        (void)v_k;
        for (; alg_truthy(alg_less_equal(v_k, alg_int(3))); (v_k = alg_add(v_k, alg_int(1)))) {
            {
                Value v_probe = alg_list();
                (void)v_probe;
                {
                    Value v_i = alg_int(0);
                    (void)v_i;
                    for (; alg_truthy(alg_less(v_i, v_k)); (v_i = alg_add(v_i, alg_int(1)))) {
                        (void)(alg_invoke(v_probe, "Add", (Value[]){alg_char_value(48)}, 1));
                    }
                }
                if (alg_truthy(alg_not_equal(alg_invoke(v_this, "Builtin", (Value[]){v_name, v_k}, 2), alg_string("")))) {
                    (void)(alg_invoke(v_counts, "Add", (Value[]){v_k}, 1));
                } else {
                    if (alg_truthy(alg_not_equal(alg_invoke(v_this, "ConstructorFor", (Value[]){v_name, v_probe, alg_char_value(48)}, 3), alg_string("")))) {
                        (void)(alg_invoke(v_counts, "Add", (Value[]){v_k}, 1));
                    }
                }
            }
        }
    }
    return v_counts;
    return alg_nil();
}

static Value m_cemitter_countsmessage_2_list_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_counts = alg_widen(args[0], "List");
    (void)v_counts;
    Value v_got = alg_widen(args[1], "Integer");
    (void)v_got;
    Value v_expected = alg_nil();
    (void)v_expected;
    (void)((v_expected = alg_widen(alg_string(""), "String")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(v_counts, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                    (void)((v_expected = alg_widen(alg_add(v_expected, alg_string(" or ")), "String")));
                }
                (void)((v_expected = alg_widen(alg_add(v_expected, alg_str(alg_subscript_get(v_counts, v_i))), "String")));
            }
        }
    }
    return alg_add(alg_add(alg_add(alg_add(alg_string("Expected "), v_expected), alg_string(" arguments but got ")), alg_str(v_got)), alg_char_value(46));
    return alg_nil();
}

static Value m_cemitter_renamesof_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_unit = alg_widen(args[0], "String");
    (void)v_unit;
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    Value v_only = alg_nil();
    (void)v_only;
    (void)((v_only = alg_widen(alg_map(), "Map")));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Renamed"), "Contains", (Value[]){v_name}, 1))) {
        (void)(alg_invoke(v_only, "Put", (Value[]){v_name, v_unit}, 2));
    }
    return v_only;
    return alg_nil();
}

static Value m_cemitter_markambiguousimport_3_string_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_first = alg_widen(args[1], "String");
    (void)v_first;
    Value v_second = alg_widen(args[2], "String");
    (void)v_second;
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Contains", (Value[]){v_name}, 1)))) {
        {
            (void)(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Put", (Value[]){v_name, alg_add(alg_add(v_first, alg_string(" or ")), v_second)}, 2));
            return alg_nil();
        }
    }
    (void)(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Put", (Value[]){v_name, alg_add(alg_add(alg_str(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Get", (Value[]){v_name}, 1)), alg_string(" or ")), v_second)}, 2));
    return alg_nil();
}

static Value m_cemitter_markambiguousmember_3_string_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_member = alg_widen(args[0], "String");
    (void)v_member;
    Value v_first = alg_widen(args[1], "String");
    (void)v_first;
    Value v_second = alg_widen(args[2], "String");
    (void)v_second;
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Contains", (Value[]){v_member}, 1)))) {
        {
            (void)(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Put", (Value[]){v_member, alg_add(alg_add(v_first, alg_string(" or ")), v_second)}, 2));
            return alg_nil();
        }
    }
    (void)(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Put", (Value[]){v_member, alg_add(alg_add(alg_str(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Get", (Value[]){v_member}, 1)), alg_string(" or ")), v_second)}, 2));
    return alg_nil();
}

static Value m_cemitter_ambiguousmessage_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_written = alg_widen(args[0], "String");
    (void)v_written;
    Value v_owners = alg_widen(args[1], "String");
    (void)v_owners;
    return alg_add(alg_add(alg_add(alg_add(alg_char_value(39), v_written), alg_string("' is ambiguous: ")), v_owners), alg_char_value(46));
    return alg_nil();
}

static Value m_cemitter_isassertion_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_folded = alg_nil();
    (void)v_folded;
    (void)((v_folded = alg_widen(f_foldcase(NULL, (Value[]){v_name}, 1), "String")));
    return (or_52 = (or_51 = alg_equal(v_folded, alg_string("asserttrue")), alg_truthy(or_51) ? or_51 : alg_equal(v_folded, alg_string("assertequal"))), alg_truthy(or_52) ? or_52 : alg_equal(v_folded, alg_string("fail")));
    return alg_nil();
}

static Value m_cemitter_builtin_2_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_count = alg_widen(args[1], "Integer");
    (void)v_count;
    Value v_key = alg_nil();
    (void)v_key;
    (void)((v_key = alg_widen(alg_add(alg_add(v_name, alg_char_value(47)), alg_str(v_count)), "String")));
    if (alg_truthy(alg_equal(v_key, alg_string("WriteLn/1")))) {
        return alg_string("alg_writeln");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("WriteLn/0")))) {
        return alg_string("alg_writeln_blank");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Write/1")))) {
        return alg_string("alg_write");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Str/1")))) {
        return alg_string("alg_str");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Length/1")))) {
        return alg_string("alg_text_length");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Copy/3")))) {
        return alg_string("alg_copy");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Pos/2")))) {
        return alg_string("alg_pos");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Pos/3")))) {
        return alg_string("alg_pos_from");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("ToUpper/1")))) {
        return alg_string("alg_to_upper");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("ToLower/1")))) {
        return alg_string("alg_to_lower");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Char/1")))) {
        return alg_string("alg_char");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Ord/1")))) {
        return alg_string("alg_ord");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Val/1")))) {
        return alg_string("alg_val");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Succ/1")))) {
        return alg_string("alg_succ");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Pred/1")))) {
        return alg_string("alg_pred");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Foreign/5")))) {
        return alg_string("alg_foreign_call");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Mod/2")))) {
        return alg_string("alg_mod");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("clock/0")))) {
        return alg_string("alg_clock");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Halt/1")))) {
        return alg_string("alg_halt");
    }
    if (alg_truthy(alg_property(v_this, "EmitTests"))) {
        {
            if (alg_truthy(alg_equal(v_key, alg_string("AssertTrue/1")))) {
                return alg_string("alg_assert_true");
            }
            if (alg_truthy(alg_equal(v_key, alg_string("AssertEqual/2")))) {
                return alg_string("alg_assert_equal");
            }
            if (alg_truthy(alg_equal(v_key, alg_string("Fail/1")))) {
                return alg_string("alg_assert_fail");
            }
        }
    }
    if (alg_truthy(alg_equal(v_key, alg_string("FileExists/1")))) {
        return alg_string("alg_file_exists");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("MkDir/1")))) {
        return alg_string("alg_mkdir");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("RmDir/1")))) {
        return alg_string("alg_rmdir");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("ChDir/1")))) {
        return alg_string("alg_chdir");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("GetDir/0")))) {
        return alg_string("alg_getdir");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("ParamCount/0")))) {
        return alg_string("alg_param_count");
    }
    if (alg_truthy(alg_equal(v_key, alg_string("ParamStr/1")))) {
        return alg_string("alg_param_str");
    }
    return alg_string("");
    return alg_nil();
}

static Value m_cemitter_runtogether_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    Value v_result = alg_nil();
    (void)v_result;
    (void)((v_result = alg_widen(alg_add(alg_add(alg_string("alg_str("), alg_str(alg_subscript_get(v_arguments, alg_int(0)))), alg_char_value(41)), "String")));
    {
        Value v_i = alg_int(1);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(v_arguments, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)((v_result = alg_widen(alg_add(alg_add(alg_add(alg_add(alg_string("alg_add("), v_result), alg_string(", alg_str(")), alg_str(alg_subscript_get(v_arguments, v_i))), alg_string("))")), "String")));
        }
    }
    return v_result;
    return alg_nil();
}

static Value m_cemitter_anynamed_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_names = alg_widen(args[0], "List");
    (void)v_names;
    {
        Value loop_47 = alg_iterable(v_names);
        for (int32_t at_47 = 0; at_47 < alg_iterable_count(loop_47); at_47++) {
            Value v_name = alg_iterable_at(loop_47, at_47);
            (void)v_name;
            if (alg_truthy(alg_not_equal(alg_str(v_name), alg_string("")))) {
                return alg_bool(true);
            }
        }
    }
    return alg_bool(false);
    return alg_nil();
}

static Value m_cemitter_namearray_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_names = alg_widen(args[0], "List");
    (void)v_names;
    Value v_joined = alg_widen(alg_string(""), "String");
    (void)v_joined;
    if (alg_truthy(alg_equal(alg_property(v_names, "Length"), alg_int(0)))) {
        return alg_string("NULL");
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(v_names, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                    (void)((v_joined = alg_widen(alg_add(v_joined, alg_string(", ")), "String")));
                }
                (void)((v_joined = alg_widen(alg_add(v_joined, f_quotec(NULL, (Value[]){alg_str(alg_subscript_get(v_names, v_i))}, 1)), "String")));
            }
        }
    }
    return alg_add(alg_add(alg_string("(const char*[]){"), v_joined), alg_char_value(125));
    return alg_nil();
}

static Value m_cemitter_calling_3_string_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_callee = alg_widen(args[0], "String");
    (void)v_callee;
    Value v_emitted = alg_widen(args[1], "List");
    (void)v_emitted;
    Value v_names = alg_widen(args[2], "List");
    (void)v_names;
    if (alg_truthy(alg_not(f_anynamed(NULL, (Value[]){v_names}, 1)))) {
        return alg_add(alg_add(alg_add(alg_add(alg_string("alg_call("), v_callee), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_char_value(41));
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_call_named("), v_callee), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_string(", ")), alg_invoke(v_this, "NameArray", (Value[]){v_names}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_constructing_3_string_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_handle = alg_widen(args[0], "String");
    (void)v_handle;
    Value v_emitted = alg_widen(args[1], "List");
    (void)v_emitted;
    Value v_names = alg_widen(args[2], "List");
    (void)v_names;
    if (alg_truthy(alg_not(f_anynamed(NULL, (Value[]){v_names}, 1)))) {
        return alg_add(alg_add(alg_add(alg_add(alg_string("alg_new("), v_handle), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_char_value(41));
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_new_named("), v_handle), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_string(", ")), alg_invoke(v_this, "NameArray", (Value[]){v_names}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_invoking_4_string_string_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_receiver = alg_widen(args[0], "String");
    (void)v_receiver;
    Value v_thename = alg_widen(args[1], "String");
    (void)v_thename;
    Value v_emitted = alg_widen(args[2], "List");
    (void)v_emitted;
    Value v_names = alg_widen(args[3], "List");
    (void)v_names;
    if (alg_truthy(alg_not(f_anynamed(NULL, (Value[]){v_names}, 1)))) {
        return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_invoke("), v_receiver), alg_string(", ")), f_quotec(NULL, (Value[]){v_thename}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_char_value(41));
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_invoke_named("), v_receiver), alg_string(", ")), f_quotec(NULL, (Value[]){v_thename}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_string(", ")), alg_invoke(v_this, "NameArray", (Value[]){v_names}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_argumentarray_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    Value v_joined = alg_widen(alg_string(""), "String");
    (void)v_joined;
    if (alg_truthy(alg_equal(alg_property(v_arguments, "Length"), alg_int(0)))) {
        return alg_string("NULL, 0");
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(v_arguments, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                    (void)((v_joined = alg_widen(alg_add(v_joined, alg_string(", ")), "String")));
                }
                (void)((v_joined = alg_widen(alg_add(v_joined, alg_str(alg_subscript_get(v_arguments, v_i))), "String")));
            }
        }
    }
    return alg_add(alg_add(alg_add(alg_string("(Value[]){"), v_joined), alg_string("}, ")), alg_str(alg_property(v_arguments, "Length")));
    return alg_nil();
}

static Value m_cemitter_exportednames_1_emitunit(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_unit = alg_widen(args[0], "EmitUnit");
    (void)v_unit;
    Value v_names = alg_nil();
    (void)v_names;
    (void)((v_names = alg_widen(alg_list(), "List")));
    {
        Value loop_48 = alg_iterable(alg_property(v_unit, "Statements"));
        for (int32_t at_48 = 0; at_48 < alg_iterable_count(loop_48); at_48++) {
            Value v_thestmt = alg_iterable_at(loop_48, at_48);
            (void)v_thestmt;
            {
                if (alg_truthy((or_53 = alg_is(v_thestmt, "FunctionStmt"), !alg_truthy(or_53) ? or_53 : alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1))))) {
                    (void)(alg_invoke(v_names, "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                }
                if (alg_truthy(alg_is(v_thestmt, "ClassStmt"))) {
                    (void)(alg_invoke(v_names, "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                }
                if (alg_truthy(alg_is(v_thestmt, "ObjectStmt"))) {
                    (void)(alg_invoke(v_names, "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                }
                if (alg_truthy(alg_is(v_thestmt, "VarStmt"))) {
                    (void)(alg_invoke(v_names, "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                }
                if (alg_truthy(alg_is(v_thestmt, "EnumStmt"))) {
                    {
                        (void)(alg_invoke(v_names, "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                        {
                            Value loop_49 = alg_iterable(alg_property(v_thestmt, "Members"));
                            for (int32_t at_49 = 0; at_49 < alg_iterable_count(loop_49); at_49++) {
                                Value v_member = alg_iterable_at(loop_49, at_49);
                                (void)v_member;
                                (void)(alg_invoke(v_names, "Add", (Value[]){alg_str(alg_property(v_member, "Lexeme"))}, 1));
                            }
                        }
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                    {
                        Value loop_50 = alg_iterable(alg_property(v_thestmt, "Names"));
                        for (int32_t at_50 = 0; at_50 < alg_iterable_count(loop_50); at_50++) {
                            Value v_thename = alg_iterable_at(loop_50, at_50);
                            (void)v_thename;
                            (void)(alg_invoke(v_names, "Add", (Value[]){alg_str(alg_property(v_thename, "Lexeme"))}, 1));
                        }
                    }
                }
            }
        }
    }
    return v_names;
    return alg_nil();
}

static Value m_cemitter_constructorfor_3_string_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    Value v_arguments = alg_widen(args[1], "List");
    (void)v_arguments;
    Value v_joined = alg_widen(args[2], "String");
    (void)v_joined;
    if (alg_truthy((or_54 = alg_equal(v_name, alg_string("List")), !alg_truthy(or_54) ? or_54 : alg_equal(alg_property(v_arguments, "Length"), alg_int(0))))) {
        return alg_string("alg_list()");
    }
    if (alg_truthy((or_55 = alg_equal(v_name, alg_string("Map")), !alg_truthy(or_55) ? or_55 : alg_equal(alg_property(v_arguments, "Length"), alg_int(0))))) {
        return alg_string("alg_map()");
    }
    if (alg_truthy((or_56 = alg_equal(v_name, alg_string("Stack")), !alg_truthy(or_56) ? or_56 : alg_equal(alg_property(v_arguments, "Length"), alg_int(0))))) {
        return alg_string("alg_stack()");
    }
    if (alg_truthy((or_57 = alg_equal(v_name, alg_string("Set")), !alg_truthy(or_57) ? or_57 : alg_equal(alg_property(v_arguments, "Length"), alg_int(0))))) {
        return alg_string("alg_set()");
    }
    if (alg_truthy((or_58 = alg_equal(v_name, alg_string("Set")), !alg_truthy(or_58) ? or_58 : alg_equal(alg_property(v_arguments, "Length"), alg_int(1))))) {
        return alg_add(alg_add(alg_string("alg_set_of("), v_joined), alg_char_value(41));
    }
    if (alg_truthy((or_59 = alg_equal(v_name, alg_string("Array")), !alg_truthy(or_59) ? or_59 : alg_equal(alg_property(v_arguments, "Length"), alg_int(1))))) {
        return alg_add(alg_add(alg_string("alg_array("), v_joined), alg_char_value(41));
    }
    if (alg_truthy((or_60 = alg_equal(v_name, alg_string("TextFile")), !alg_truthy(or_60) ? or_60 : alg_equal(alg_property(v_arguments, "Length"), alg_int(0))))) {
        return alg_string("alg_text_file()");
    }
    if (alg_truthy((or_61 = alg_equal(v_name, alg_string("Buffer")), !alg_truthy(or_61) ? or_61 : alg_equal(alg_property(v_arguments, "Length"), alg_int(0))))) {
        return alg_string("alg_buffer(alg_int(0))");
    }
    if (alg_truthy((or_62 = alg_equal(v_name, alg_string("Buffer")), !alg_truthy(or_62) ? or_62 : alg_equal(alg_property(v_arguments, "Length"), alg_int(1))))) {
        return alg_add(alg_add(alg_string("alg_buffer("), v_joined), alg_char_value(41));
    }
    return alg_string("");
    return alg_nil();
}

static Value m_cemitter_unitcall_5_string_string_list_string_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_unit = alg_widen(args[0], "String");
    (void)v_unit;
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    Value v_arguments = alg_widen(args[2], "List");
    (void)v_arguments;
    Value v_joined = alg_widen(args[3], "String");
    (void)v_joined;
    Value v_names = alg_widen(args[4], "List");
    (void)v_names;
    if (alg_truthy((or_63 = alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){v_unit}, 1), !alg_truthy(or_63) ? or_63 : alg_not(alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_unit}, 1), "Set")), "Contains", (Value[]){v_name}, 1))))) {
        return alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), v_name), alg_string("' in unit '")), v_unit), alg_string("'."))}, 1)), alg_string("), alg_nil())"));
    }
    if (alg_truthy(alg_equal(v_unit, alg_string("System")))) {
        {
            Value v_thebuiltin = alg_invoke(v_this, "Builtin", (Value[]){v_name, alg_property(v_arguments, "Length")}, 2);
            (void)v_thebuiltin;
            if (alg_truthy(alg_not_equal(v_thebuiltin, alg_string("")))) {
                return alg_add(alg_add(alg_add(v_thebuiltin, alg_char_value(40)), v_joined), alg_char_value(41));
            }
            Value v_theconstructor = alg_invoke(v_this, "ConstructorFor", (Value[]){v_name, v_arguments, v_joined}, 3);
            (void)v_theconstructor;
            if (alg_truthy(alg_not_equal(v_theconstructor, alg_string("")))) {
                return v_theconstructor;
            }
            (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("A call to '"), v_unit), alg_char_value(46)), v_name), alg_char_value(39))}, 1));
        }
    }
    Value v_saved = alg_property(v_this, "Renames");
    (void)v_saved;
    (void)(alg_set_property(v_this, "Renames", alg_widen(alg_invoke(v_this, "RenamesOf", (Value[]){v_unit, v_name}, 2), "Map")));
    Value v_built = alg_string("");
    (void)v_built;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_name}, 1))) {
        (void)((v_built = alg_invoke(v_this, "Constructing", (Value[]){alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1), v_arguments, v_names}, 3)));
    } else {
        if (alg_truthy((or_64 = alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1), !alg_truthy(or_64) ? or_64 : alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1)))) {
            (void)((v_built = alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "SetName", (Value[]){v_name}, 1), v_arguments, v_names}, 3)));
        } else {
            if (alg_truthy(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1))) {
                if (alg_truthy(f_anynamed(NULL, (Value[]){v_names}, 1))) {
                    (void)((v_built = alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1), v_arguments, v_names}, 3)));
                } else {
                    (void)((v_built = alg_add(alg_add(alg_add(alg_invoke(v_this, "FunctionName", (Value[]){v_name}, 1), alg_string("(NULL, ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_arguments}, 1)), alg_char_value(41))));
                }
            } else {
                if (alg_truthy(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1))) {
                    (void)((v_built = alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "Read", (Value[]){v_name}, 1), v_arguments, v_names}, 3)));
                }
            }
        }
    }
    (void)(alg_set_property(v_this, "Renames", alg_widen(v_saved, "Map")));
    if (alg_truthy(alg_not_equal(v_built, alg_string("")))) {
        return v_built;
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("A call to '"), v_unit), alg_char_value(46)), v_name), alg_char_value(39))}, 1));
    return alg_string("");
    return alg_nil();
}

static Value m_cemitter_visitcall_1_callexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "CallExpr");
    (void)v_theexpr;
    Value v_arguments = alg_nil();
    (void)v_arguments;
    Value v_joined = alg_nil();
    (void)v_joined;
    if (alg_truthy(alg_is(alg_property(v_theexpr, "Callee"), "SuperExpr"))) {
        {
            if (alg_truthy(alg_equal(alg_property(v_this, "CurrentClass"), alg_string("")))) {
                (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("'super' outside a class")}, 1));
            }
            Value v_emitted = alg_list();
            (void)v_emitted;
            {
                Value loop_51 = alg_iterable(alg_property(v_theexpr, "Arguments"));
                for (int32_t at_51 = 0; at_51 < alg_iterable_count(loop_51); at_51++) {
                    Value v_argument = alg_iterable_at(loop_51, at_51);
                    (void)v_argument;
                    (void)(alg_invoke(v_emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){v_argument}, 1)}, 1));
                }
            }
            return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_invoke_from("), alg_invoke(v_this, "ClassHandle", (Value[]){alg_property(v_this, "CurrentClass")}, 1)), alg_string(", ")), alg_invoke(v_this, "ThisRef", NULL, 0)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Method"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_char_value(41));
        }
    }
    if (alg_truthy((or_65 = alg_is(alg_property(v_theexpr, "Callee"), "GetExpr"), !alg_truthy(or_65) ? or_65 : alg_not_equal(alg_property(alg_property(v_theexpr, "Callee"), "Unit"), alg_string(""))))) {
        {
            Value v_emitted = alg_list();
            (void)v_emitted;
            {
                Value loop_52 = alg_iterable(alg_property(v_theexpr, "Arguments"));
                for (int32_t at_52 = 0; at_52 < alg_iterable_count(loop_52); at_52++) {
                    Value v_theargument = alg_iterable_at(loop_52, at_52);
                    (void)v_theargument;
                    (void)(alg_invoke(v_emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){v_theargument}, 1)}, 1));
                }
            }
            Value v_text = alg_string("");
            (void)v_text;
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(v_emitted, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                            (void)((v_text = alg_add(v_text, alg_string(", "))));
                        }
                        (void)((v_text = alg_add(v_text, alg_str(alg_subscript_get(v_emitted, v_i)))));
                    }
                }
            }
            return alg_invoke(v_this, "UnitCall", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Callee"), "Unit")), alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme")), v_emitted, v_text, alg_property(v_theexpr, "ArgumentNames")}, 5);
        }
    }
    if (alg_truthy(alg_is(alg_property(v_theexpr, "Callee"), "GetExpr"))) {
        {
            Value v_receiver = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(alg_property(v_theexpr, "Callee"), "Obj")}, 1);
            (void)v_receiver;
            Value v_emitted = alg_list();
            (void)v_emitted;
            {
                Value loop_53 = alg_iterable(alg_property(v_theexpr, "Arguments"));
                for (int32_t at_53 = 0; at_53 < alg_iterable_count(loop_53); at_53++) {
                    Value v_eachargument = alg_iterable_at(loop_53, at_53);
                    (void)v_eachargument;
                    (void)(alg_invoke(v_emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){v_eachargument}, 1)}, 1));
                }
            }
            return alg_invoke(v_this, "Invoking", (Value[]){v_receiver, alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme")), v_emitted, alg_property(v_theexpr, "ArgumentNames")}, 4);
        }
    }
    if (alg_truthy(alg_not((alg_is(alg_property(v_theexpr, "Callee"), "VariableExpr"))))) {
        {
            Value v_emitted = alg_list();
            (void)v_emitted;
            {
                Value loop_54 = alg_iterable(alg_property(v_theexpr, "Arguments"));
                for (int32_t at_54 = 0; at_54 < alg_iterable_count(loop_54); at_54++) {
                    Value v_item = alg_iterable_at(loop_54, at_54);
                    (void)v_item;
                    (void)(alg_invoke(v_emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){v_item}, 1)}, 1));
                }
            }
            return alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Callee")}, 1), v_emitted, alg_property(v_theexpr, "ArgumentNames")}, 3);
        }
    }
    (void)((v_arguments = alg_widen(alg_list(), "List")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Arguments"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(v_arguments, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Arguments"), v_i)}, 1)}, 1));
        }
    }
    (void)((v_joined = alg_widen(alg_string(""), "String")));
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(v_arguments, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                    (void)((v_joined = alg_widen(alg_add(v_joined, alg_string(", ")), "String")));
                }
                (void)((v_joined = alg_widen(alg_add(v_joined, alg_str(alg_subscript_get(v_arguments, v_i))), "String")));
            }
        }
    }
    Value v_name = alg_invoke(v_this, "Spelled", (Value[]){alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme"))}, 1);
    (void)v_name;
    if (alg_truthy((or_67 = (or_66 = alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1), alg_truthy(or_66) ? or_66 : alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1)), alg_truthy(or_67) ? or_67 : alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1)))) {
        return alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "Read", (Value[]){v_name}, 1), v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 3);
    }
    Value v_shadowed = alg_invoke(alg_property(v_this, "ShadowNames"), "Contains", (Value[]){v_name}, 1);
    (void)v_shadowed;
    if (alg_truthy((or_69 = (or_68 = alg_not(v_shadowed), !alg_truthy(or_68) ? or_68 : f_anynamed(NULL, (Value[]){alg_property(v_theexpr, "ArgumentNames")}, 1)), !alg_truthy(or_69) ? or_69 : alg_greater(alg_property(alg_invoke(v_this, "BuiltinCounts", (Value[]){v_name}, 1), "Length"), alg_int(0))))) {
        return alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_string("A built-in has no named parameters.")}, 1)), alg_string("), alg_nil())"));
    }
    if (alg_truthy((or_70 = alg_not(v_shadowed), !alg_truthy(or_70) ? or_70 : alg_greater(alg_property(v_arguments, "Length"), alg_int(1))))) {
        {
            Value v_one = alg_invoke(v_this, "Builtin", (Value[]){v_name, alg_int(1)}, 2);
            (void)v_one;
            if (alg_truthy((or_71 = alg_equal(v_one, alg_string("alg_writeln")), alg_truthy(or_71) ? or_71 : alg_equal(v_one, alg_string("alg_write"))))) {
                return alg_add(alg_add(alg_add(v_one, alg_char_value(40)), alg_invoke(v_this, "RunTogether", (Value[]){v_arguments}, 1)), alg_char_value(41));
            }
        }
    }
    if (alg_truthy(alg_not(v_shadowed))) {
        {
            Value v_thebuiltin = alg_invoke(v_this, "Builtin", (Value[]){v_name, alg_property(v_arguments, "Length")}, 2);
            (void)v_thebuiltin;
            if (alg_truthy(alg_not_equal(v_thebuiltin, alg_string("")))) {
                return alg_add(alg_add(alg_add(v_thebuiltin, alg_char_value(40)), v_joined), alg_char_value(41));
            }
        }
    }
    if (alg_truthy(alg_not(v_shadowed))) {
        {
            Value v_theconstructor = alg_invoke(v_this, "ConstructorFor", (Value[]){v_name, v_arguments, v_joined}, 3);
            (void)v_theconstructor;
            if (alg_truthy(alg_not_equal(v_theconstructor, alg_string("")))) {
                return v_theconstructor;
            }
        }
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_name}, 1))) {
        return alg_invoke(v_this, "Constructing", (Value[]){alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1), v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 3);
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){v_name}, 1))) {
        return alg_invoke(v_this, "Calling", (Value[]){alg_add(alg_add(alg_string("alg_singleton("), alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)), alg_char_value(41)), v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 3);
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Contains", (Value[]){v_name}, 1))) {
        return alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "AmbiguousMessage", (Value[]){alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme")), alg_str(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Get", (Value[]){v_name}, 1))}, 2)}, 1)), alg_string("), alg_nil())"));
    }
    if (alg_truthy((or_73 = (or_72 = alg_not_equal(alg_property(v_this, "CurrentClass"), alg_string("")), !alg_truthy(or_72) ? or_72 : alg_not(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_73) ? or_73 : alg_invoke(alg_property(v_this, "VisibleMethods"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1)))) {
        return alg_invoke(v_this, "Invoking", (Value[]){alg_invoke(v_this, "ThisRef", NULL, 0), v_name, v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 4);
    }
    if (alg_truthy((or_74 = alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1), !alg_truthy(or_74) ? or_74 : alg_not(alg_invoke(alg_property(v_this, "ShadowNames"), "Contains", (Value[]){v_name}, 1))))) {
        return alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "MissingName", (Value[]){v_name}, 1)}, 1)), alg_string("), alg_nil())"));
    }
    if (alg_truthy((or_75 = alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1), !alg_truthy(or_75) ? or_75 : alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1)))) {
        return alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "SetName", (Value[]){v_name}, 1), v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 3);
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1))) {
        {
            if (alg_truthy(f_anynamed(NULL, (Value[]){alg_property(v_theexpr, "ArgumentNames")}, 1))) {
                return alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1), v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 3);
            }
            return alg_add(alg_add(alg_add(alg_invoke(v_this, "FunctionName", (Value[]){v_name}, 1), alg_string("(NULL, ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_arguments}, 1)), alg_char_value(41));
        }
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1))) {
        return alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "Read", (Value[]){v_name}, 1), v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 3);
    }
    if (alg_truthy((or_76 = alg_not(alg_property(v_this, "EmitTests")), !alg_truthy(or_76) ? or_76 : alg_invoke(v_this, "IsAssertion", (Value[]){v_name}, 1)))) {
        return alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "MissingName", (Value[]){v_name}, 1)}, 1)), alg_string("), alg_nil())"));
    }
    if (alg_truthy(alg_not(v_shadowed))) {
        {
            Value v_counts = alg_invoke(v_this, "BuiltinCounts", (Value[]){v_name}, 1);
            (void)v_counts;
            if (alg_truthy(alg_greater(alg_property(v_counts, "Length"), alg_int(0)))) {
                return alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "CountsMessage", (Value[]){v_counts, alg_property(v_arguments, "Length")}, 2)}, 1)), alg_string("), alg_nil())"));
            }
        }
    }
    if (alg_truthy((or_83 = (or_82 = (or_81 = (or_80 = (or_79 = (or_78 = (or_77 = alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)), !alg_truthy(or_77) ? or_77 : alg_not(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_78) ? or_78 : alg_not(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_79) ? or_79 : alg_not(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_80) ? or_80 : alg_not(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_81) ? or_81 : alg_not(alg_invoke(alg_property(v_this, "EnumTypes"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_82) ? or_82 : alg_not(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_83) ? or_83 : alg_not(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Contains", (Value[]){v_name}, 1))))) {
        return alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "MissingName", (Value[]){v_name}, 1)}, 1)), alg_string("), alg_nil())"));
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("A call to '"), v_name), alg_char_value(39))}, 1));
    return alg_nil();
}

static Value m_cemitter_visitlogical_1_logicalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "LogicalExpr");
    (void)v_theexpr;
    Value v_slot = alg_nil();
    (void)v_slot;
    Value v_test = alg_nil();
    (void)v_test;
    Value v_left = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Left")}, 1);
    (void)v_left;
    Value v_right = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Right")}, 1);
    (void)v_right;
    (void)((v_slot = alg_widen(alg_add(alg_string("or_"), alg_str(alg_property(v_this, "Logicals"))), "String")));
    (void)(alg_set_property(v_this, "Logicals", alg_widen(alg_add(alg_property(v_this, "Logicals"), alg_int(1)), "Integer")));
    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_slot), alg_char_value(59)), alg_char_value(10))}, 1));
    (void)((v_test = alg_widen(alg_string("!alg_truthy("), "String")));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVor))) {
        (void)((v_test = alg_widen(alg_string("alg_truthy("), "String")));
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_char_value(40), v_slot), alg_string(" = ")), v_left), alg_string(", ")), v_test), v_slot), alg_string(") ? ")), v_slot), alg_string(" : ")), v_right), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_boundargument_3_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_params = args[0];
    (void)v_params;
    Value v_types = args[1];
    (void)v_types;
    Value v_i = alg_widen(args[2], "Integer");
    (void)v_i;
    Value v_slot = alg_add(alg_add(alg_string("args["), alg_str(v_i)), alg_char_value(93));
    (void)v_slot;
    if (alg_truthy(alg_greater_equal(v_i, alg_property(v_types, "Length")))) {
        return v_slot;
    }
    Value v_declared = alg_str(alg_subscript_get(v_types, v_i));
    (void)v_declared;
    if (alg_truthy((or_84 = alg_equal(v_declared, alg_string("")), alg_truthy(or_84) ? or_84 : alg_equal(v_declared, alg_string("Any"))))) {
        return v_slot;
    }
    return alg_add(alg_add(alg_add(alg_add(alg_string("alg_param("), v_slot), alg_string(", ")), f_quotec(NULL, (Value[]){v_declared}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_allliterals_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    {
        Value loop_55 = alg_iterable(alg_property(v_theexpr, "Values"));
        for (int32_t at_55 = 0; at_55 < alg_iterable_count(loop_55); at_55++) {
            Value v_value = alg_iterable_at(loop_55, at_55);
            (void)v_value;
            if (alg_truthy(alg_not((alg_is(v_value, "LiteralExpr"))))) {
                return alg_bool(false);
            }
        }
    }
    if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
        {
            Value loop_56 = alg_iterable(alg_property(v_theexpr, "Keys"));
            for (int32_t at_56 = 0; at_56 < alg_iterable_count(loop_56); at_56++) {
                Value v_key = alg_iterable_at(loop_56, at_56);
                (void)v_key;
                if (alg_truthy(alg_not((alg_is(v_key, "LiteralExpr"))))) {
                    return alg_bool(false);
                }
            }
        }
    }
    return alg_bool(true);
    return alg_nil();
}

static Value m_cemitter_visitcollectionexpr_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    Value v_built = alg_nil();
    (void)v_built;
    if (alg_truthy(alg_greater(alg_property(alg_property(v_theexpr, "Values"), "Length"), (alg_declared(d_hoistVabove, "HOIST_ABOVE"), v_hoistVabove)))) {
        {
            if (alg_truthy(alg_invoke(v_this, "AllLiterals", (Value[]){v_theexpr}, 1))) {
                return alg_invoke(v_this, "HoistedCollection", (Value[]){v_theexpr}, 1);
            }
            return alg_invoke(v_this, "ComputedCollection", (Value[]){v_theexpr}, 1);
        }
    }
    if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
        {
            (void)((v_built = alg_widen(alg_string("alg_map()"), "String")));
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Keys"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)((v_built = alg_widen(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_map_keep("), v_built), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Keys"), v_i)}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Values"), v_i)}, 1)), alg_char_value(41)), "String")));
                }
            }
            return v_built;
        }
    }
    (void)((v_built = alg_widen(alg_string("alg_list()"), "String")));
    {
        Value loop_57 = alg_iterable(alg_property(v_theexpr, "Values"));
        for (int32_t at_57 = 0; at_57 < alg_iterable_count(loop_57); at_57++) {
            Value v_value = alg_iterable_at(loop_57, at_57);
            (void)v_value;
            (void)((v_built = alg_widen(alg_add(alg_add(alg_add(alg_add(alg_string("alg_list_keep("), v_built), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){v_value}, 1)), alg_char_value(41)), "String")));
        }
    }
    return v_built;
    return alg_nil();
}

static Value m_cemitter_hoistedcollection_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    (void)((v_symbol = alg_widen(alg_add(alg_string("lit_"), alg_str(alg_property(v_this, "Loops"))), "String")));
    (void)(alg_set_property(v_this, "Loops", alg_widen(alg_add(alg_property(v_this, "Loops"), alg_int(1)), "Integer")));
    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_symbol), alg_string("(void);")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_symbol), alg_string("(void) {")), alg_char_value(10))}, 1));
    if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    Value it = alg_map();"), alg_char_value(10))}, 1));
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Keys"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    it = alg_map_keep(it, "), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Keys"), v_i)}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Values"), v_i)}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                }
            }
        }
    } else {
        {
            (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    Value it = alg_list();"), alg_char_value(10))}, 1));
            {
                Value loop_58 = alg_iterable(alg_property(v_theexpr, "Values"));
                for (int32_t at_58 = 0; at_58 < alg_iterable_count(loop_58); at_58++) {
                    Value v_thevalue = alg_iterable_at(loop_58, at_58);
                    (void)v_thevalue;
                    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("    it = alg_list_keep(it, "), alg_invoke(v_this, "Evaluate", (Value[]){v_thevalue}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                }
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("    return it;"), alg_char_value(10)), alg_char_value(125)), alg_char_value(10)), alg_char_value(10))}, 1));
    return alg_add(v_symbol, alg_string("()"));
    return alg_nil();
}

static Value m_cemitter_computedcollection_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    Value v_joined = alg_nil();
    (void)v_joined;
    (void)((v_symbol = alg_widen(alg_add(alg_string("lit_"), alg_str(alg_property(v_this, "Loops"))), "String")));
    (void)(alg_set_property(v_this, "Loops", alg_widen(alg_add(alg_property(v_this, "Loops"), alg_int(1)), "Integer")));
    (void)((v_joined = alg_widen(alg_string(""), "String")));
    Value v_emitted = alg_list();
    (void)v_emitted;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Values"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
                    (void)(alg_invoke(v_emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Keys"), v_i)}, 1)}, 1));
                }
                (void)(alg_invoke(v_emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Values"), v_i)}, 1)}, 1));
            }
        }
    }
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(v_emitted, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                    (void)((v_joined = alg_widen(alg_add(v_joined, alg_string(", ")), "String")));
                }
                (void)((v_joined = alg_widen(alg_add(v_joined, alg_str(alg_subscript_get(v_emitted, v_i))), "String")));
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_symbol), alg_string("(Value *e);")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_symbol), alg_string("(Value *e) {")), alg_char_value(10))}, 1));
    if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    Value it = alg_map();"), alg_char_value(10))}, 1));
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Values"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    it = alg_map_keep(it, e["), alg_str(alg_multiply(v_i, alg_int(2)))), alg_string("], e[")), alg_str(alg_add(alg_multiply(v_i, alg_int(2)), alg_int(1)))), alg_string("]);")), alg_char_value(10))}, 1));
                }
            }
        }
    } else {
        {
            (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    Value it = alg_list();"), alg_char_value(10))}, 1));
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Values"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("    it = alg_list_keep(it, e["), alg_str(v_i)), alg_string("]);")), alg_char_value(10))}, 1));
                }
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("    return it;"), alg_char_value(10)), alg_char_value(125)), alg_char_value(10)), alg_char_value(10))}, 1));
    return alg_add(alg_add(alg_add(v_symbol, alg_string("((Value[]){")), v_joined), alg_string("})"));
    return alg_nil();
}

static Value m_cemitter_visitsubscriptexpr_1_subscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "SubscriptExpr");
    (void)v_theexpr;
    return alg_add(alg_add(alg_add(alg_add(alg_string("alg_subscript_get("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Index")}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_visitsetsubscriptexpr_1_setsubscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "SetSubscriptExpr");
    (void)v_theexpr;
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_subscript_set("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Index")}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_unitvalue_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_unit = alg_widen(args[0], "String");
    (void)v_unit;
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    if (alg_truthy((or_85 = alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){v_unit}, 1), !alg_truthy(or_85) ? or_85 : alg_not(alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_unit}, 1), "Set")), "Contains", (Value[]){v_name}, 1))))) {
        return alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), v_name), alg_string("' in unit '")), v_unit), alg_string("'."))}, 1)), alg_string("), alg_nil())"));
    }
    if (alg_truthy(alg_equal(v_unit, alg_string("System")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_char_value(39), v_unit), alg_char_value(46)), v_name), alg_string("' as a value"))}, 1));
    }
    Value v_saved = alg_property(v_this, "Renames");
    (void)v_saved;
    (void)(alg_set_property(v_this, "Renames", alg_widen(alg_invoke(v_this, "RenamesOf", (Value[]){v_unit, v_name}, 2), "Map")));
    Value v_built = alg_string("");
    (void)v_built;
    if (alg_truthy(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_name}, 1))) {
        (void)((v_built = alg_invoke(v_this, "EnumMemberName", (Value[]){alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_name}, 1)), v_name}, 2)));
    } else {
        if (alg_truthy(alg_invoke(alg_property(v_this, "EnumTypes"), "Contains", (Value[]){v_name}, 1))) {
            (void)((v_built = alg_invoke(v_this, "EnumTypeName", (Value[]){v_name}, 1)));
        } else {
            if (alg_truthy(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){v_name}, 1))) {
                (void)((v_built = alg_add(alg_add(alg_string("alg_singleton("), alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)), alg_char_value(41))));
            } else {
                if (alg_truthy(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_name}, 1))) {
                    (void)((v_built = alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)));
                } else {
                    if (alg_truthy(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1))) {
                        (void)((v_built = alg_invoke(v_this, "SubprogramValue", (Value[]){v_name}, 1)));
                    } else {
                        if (alg_truthy(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1))) {
                            (void)((v_built = alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)}, 2)));
                        }
                    }
                }
            }
        }
    }
    (void)(alg_set_property(v_this, "Renames", alg_widen(v_saved, "Map")));
    if (alg_truthy(alg_not_equal(v_built, alg_string("")))) {
        return v_built;
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_char_value(39), v_unit), alg_char_value(46)), v_name), alg_string("' as a value"))}, 1));
    return alg_string("");
    return alg_nil();
}

static Value m_cemitter_visitgetexpr_1_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "GetExpr");
    (void)v_theexpr;
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Unit"), alg_string("")))) {
        return alg_invoke(v_this, "UnitValue", (Value[]){alg_str(alg_property(v_theexpr, "Unit")), alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 2);
    }
    return alg_add(alg_add(alg_add(alg_add(alg_string("alg_property("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_visitsetexpr_1_setexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "SetExpr");
    (void)v_theexpr;
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Unit"), alg_string("")))) {
        {
            Value v_written = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1);
            (void)v_written;
            Value v_unit = alg_str(alg_property(v_theexpr, "Unit"));
            (void)v_unit;
            Value v_name = alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"));
            (void)v_name;
            if (alg_truthy((or_86 = alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){v_unit}, 1), !alg_truthy(or_86) ? or_86 : alg_not(alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_unit}, 1), "Set")), "Contains", (Value[]){v_name}, 1))))) {
                return alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), v_name), alg_string("' in unit '")), v_unit), alg_string("'."))}, 1)), alg_string("), alg_nil())"));
            }
            if (alg_truthy((or_87 = alg_not_equal(v_unit, alg_string("System")), !alg_truthy(or_87) ? or_87 : alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))) {
                return alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_add(alg_add(alg_add(alg_add(alg_char_value(40), alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), alg_string(" = ")), v_written), alg_char_value(41))}, 2);
            }
            (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("An assignment to '"), v_unit), alg_char_value(46)), v_name), alg_char_value(39))}, 1));
        }
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_set_property("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "BoundValue", (Value[]){alg_property(v_theexpr, "Declared"), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1)}, 2)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_visitsuperexpr_1_superexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "SuperExpr");
    (void)v_theexpr;
    if (alg_truthy(alg_equal(alg_property(v_this, "CurrentClass"), alg_string("")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("'super' outside a class")}, 1));
    }
    return alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_bound_from("), alg_invoke(v_this, "ClassHandle", (Value[]){alg_property(v_this, "CurrentClass")}, 1)), alg_string(", ")), alg_invoke(v_this, "ThisRef", NULL, 0)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Method"), "Lexeme"))}, 1)), alg_char_value(41));
    return alg_nil();
}

static Value m_cemitter_visitthisexpr_1_thisexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_theexpr = alg_widen(args[0], "ThisExpr");
    (void)v_theexpr;
    return alg_invoke(v_this, "ThisRef", NULL, 0);
    return alg_nil();
}

static Value m_cemitter_visitclassstmt_1_classstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "ClassStmt");
    (void)v_thestmt;
    (void)(alg_invoke(v_this, "EmitClass", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "Superclass"), alg_property(v_thestmt, "Fields"), alg_property(v_thestmt, "Methods"), alg_bool(false)}, 5));
    return alg_nil();
}

static Value m_cemitter_visitobjectstmt_1_objectstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "ObjectStmt");
    (void)v_thestmt;
    (void)(alg_invoke(v_this, "EmitClass", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "Superclass"), alg_property(v_thestmt, "Fields"), alg_property(v_thestmt, "Methods"), alg_bool(true)}, 5));
    return alg_nil();
}

static Value m_cemitter_visitsubrangestmt_1_subrangestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "SubrangeStmt");
    (void)v_thestmt;
    return alg_nil();
}

static Value m_cemitter_emitsubranges_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property((alg_declared(d_subrangeVnames, "SUBRANGE_NAMES"), v_subrangeVnames), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(alg_property(v_this, "Shells"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_subrange("), f_quotec(NULL, (Value[]){alg_str(alg_subscript_get((alg_declared(d_subrangeVnames, "SUBRANGE_NAMES"), v_subrangeVnames), v_i))}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_subscript_get((alg_declared(d_subrangeVlows, "SUBRANGE_LOWS"), v_subrangeVlows), v_i))}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_subscript_get((alg_declared(d_subrangeVhighs, "SUBRANGE_HIGHS"), v_subrangeVhighs), v_i))}, 1)), alg_string(");")), alg_char_value(10))}, 1));
        }
    }
    return alg_nil();
}

static Value m_cemitter_visitenumstmt_1_enumstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "EnumStmt");
    (void)v_thestmt;
    Value v_thetype = alg_nil();
    (void)v_thetype;
    (void)((v_thetype = alg_widen(alg_invoke(v_this, "EnumTypeName", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1), "String")));
    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){v_thetype, alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
    (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), v_thetype), alg_string(" = alg_enum_type(")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)), alg_string(");")), alg_char_value(10))}, 1));
    {
        Value loop_59 = alg_iterable(alg_property(v_thestmt, "Members"));
        for (int32_t at_59 = 0; at_59 < alg_iterable_count(loop_59); at_59++) {
            Value v_member = alg_iterable_at(loop_59, at_59);
            (void)v_member;
            {
                Value v_symbol = alg_invoke(v_this, "EnumMemberName", (Value[]){alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){alg_str(alg_property(v_member, "Lexeme"))}, 1)), alg_str(alg_property(v_member, "Lexeme"))}, 2);
                (void)v_symbol;
                (void)(alg_invoke(v_this, "DeclareValue", (Value[]){v_symbol, alg_str(alg_property(v_member, "Lexeme"))}, 2));
                (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), v_symbol), alg_string(" = alg_enum_member(")), v_thetype), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(v_member, "Lexeme"))}, 1)), alg_string(");")), alg_char_value(10))}, 1));
            }
        }
    }
    return alg_nil();
}

static Value m_cemitter_visittrystmt_1_trystmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "TryStmt");
    (void)v_thestmt;
    Value v_id = alg_nil();
    (void)v_id;
    Value v_frame = alg_nil();
    (void)v_frame;
    Value v_handlers = alg_nil();
    (void)v_handlers;
    Value v_catchall = alg_nil();
    (void)v_catchall;
    Value v_keys = alg_nil();
    (void)v_keys;
    (void)((v_id = alg_widen(alg_property(v_this, "Loops"), "Integer")));
    (void)(alg_set_property(v_this, "Loops", alg_widen(alg_add(alg_property(v_this, "Loops"), alg_int(1)), "Integer")));
    (void)((v_frame = alg_widen(alg_add(alg_string("frame_"), alg_str(v_id)), "String")));
    (void)((v_handlers = alg_widen(alg_list(), "List")));
    (void)((v_catchall = alg_nil()));
    (void)((v_keys = alg_widen(alg_invoke(alg_property(v_thestmt, "Handlers"), "Keys", NULL, 0), "List")));
    {
        Value loop_60 = alg_iterable(v_keys);
        for (int32_t at_60 = 0; at_60 < alg_iterable_count(loop_60); at_60++) {
            Value v_key = alg_iterable_at(loop_60, at_60);
            (void)v_key;
            {
                if (alg_truthy(alg_equal(v_key, alg_string("default")))) {
                    (void)((v_catchall = alg_invoke(alg_property(v_thestmt, "Handlers"), "Get", (Value[]){v_key}, 1)));
                } else {
                    (void)(alg_invoke(v_handlers, "Add", (Value[]){v_key}, 1));
                }
            }
        }
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_add(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("AlgFrame "), v_frame), alg_char_value(59))}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_push_frame(&"), v_frame), alg_string(");"))}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("if (ALG_SETJMP("), v_frame), alg_string(".jump) == 0) {"))}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_add(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_set_property(v_this, "TryDepth", alg_widen(alg_add(alg_property(v_this, "TryDepth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "TryBlock")}, 1));
    (void)(alg_set_property(v_this, "TryDepth", alg_widen(alg_subtract(alg_property(v_this, "TryDepth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("alg_pop_frame();")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("else {")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_add(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    if (alg_truthy(alg_equal(alg_property(v_handlers, "Length"), alg_int(0)))) {
        (void)(alg_invoke(v_this, "EmitHandlerBody", (Value[]){v_catchall, v_frame}, 2));
    } else {
        {
            Value v_names = alg_string("");
            (void)v_names;
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(v_handlers, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                            (void)((v_names = alg_add(v_names, alg_string(", "))));
                        }
                        (void)((v_names = alg_add(v_names, f_quotec(NULL, (Value[]){alg_str(alg_subscript_get(v_handlers, v_i))}, 1))));
                    }
                }
            }
            Value v_table = alg_add(alg_string("names_"), alg_str(v_id));
            (void)v_table;
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("static const char *"), v_table), alg_string("[] = {")), v_names), alg_string("};"))}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("int32_t which_"), alg_str(v_id)), alg_string(" = alg_handler(")), v_frame), alg_string(".raised, ")), v_table), alg_string(", ")), alg_str(alg_property(v_handlers, "Length"))), alg_string(");"))}, 1));
            {
                Value v_i = alg_int(0);
                (void)v_i;
                for (; alg_truthy(alg_less(v_i, alg_property(v_handlers, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        Value v_lead = alg_string("else if");
                        (void)v_lead;
                        if (alg_truthy(alg_equal(v_i, alg_int(0)))) {
                            (void)((v_lead = alg_string("if")));
                        }
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(v_lead, alg_string(" (which_")), alg_str(v_id)), alg_string(" == ")), alg_str(v_i)), alg_string(") {"))}, 1));
                        (void)(alg_set_property(v_this, "Depth", alg_widen(alg_add(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
                        (void)(alg_invoke(v_this, "EmitHandlerBody", (Value[]){alg_invoke(alg_property(v_thestmt, "Handlers"), "Get", (Value[]){alg_subscript_get(v_handlers, v_i)}, 1), v_frame}, 2));
                        (void)(alg_set_property(v_this, "Depth", alg_widen(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
                    }
                }
            }
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("else {")}, 1));
            (void)(alg_set_property(v_this, "Depth", alg_widen(alg_add(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
            if (alg_truthy(alg_not_equal(v_catchall, alg_nil()))) {
                (void)(alg_invoke(v_this, "EmitHandlerBody", (Value[]){v_catchall, v_frame}, 2));
            } else {
                (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_raise("), v_frame), alg_string(".raised);"))}, 1));
            }
            (void)(alg_set_property(v_this, "Depth", alg_widen(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
        }
    }
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    return alg_nil();
}

static Value m_cemitter_visitraisestmt_1_raisestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "RaiseStmt");
    (void)v_thestmt;
    if (alg_truthy(alg_equal(alg_property(v_thestmt, "Value"), alg_nil()))) {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("alg_raise(alg_nil());")}, 1));
    } else {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_raise("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Value")}, 1)), alg_string(");"))}, 1));
    }
    return alg_nil();
}

static Value m_cemitter_visitforinstmt_1_forinstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "ForInStmt");
    (void)v_thestmt;
    Value v_id = alg_nil();
    (void)v_id;
    Value v_snapshot = alg_nil();
    (void)v_snapshot;
    Value v_index = alg_nil();
    (void)v_index;
    Value v_counter = alg_nil();
    (void)v_counter;
    (void)(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    (void)((v_id = alg_widen(alg_property(v_this, "Loops"), "Integer")));
    (void)(alg_set_property(v_this, "Loops", alg_widen(alg_add(alg_property(v_this, "Loops"), alg_int(1)), "Integer")));
    (void)((v_snapshot = alg_widen(alg_add(alg_string("loop_"), alg_str(v_id)), "String")));
    (void)((v_index = alg_widen(alg_add(alg_string("at_"), alg_str(v_id)), "String")));
    Value v_mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_mark;
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_add(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), v_snapshot), alg_string(" = alg_iterable(")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Iterable")}, 1)), alg_string(");"))}, 1));
    (void)((v_counter = alg_widen(alg_string("int32_t "), "String")));
    if (alg_truthy(alg_property(v_this, "Volatiles"))) {
        (void)((v_counter = alg_widen(alg_string("volatile int32_t "), "String")));
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("for ("), v_counter), v_index), alg_string(" = 0; ")), v_index), alg_string(" < alg_iterable_count(")), v_snapshot), alg_string("); ")), v_index), alg_string("++) {"))}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_add(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
    Value v_element = alg_add(alg_add(alg_add(alg_add(alg_string("alg_iterable_at("), v_snapshot), alg_string(", ")), v_index), alg_char_value(41));
    (void)v_element;
    if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1))) {
        (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), v_element}, 2));
    } else {
        {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)), alg_string(" = ")), v_element), alg_char_value(59))}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)), alg_char_value(59))}, 1));
        }
    }
    Value v_enclosingloopdepth = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosingloopdepth;
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_widen(alg_property(v_this, "TryDepth"), "Integer")));
    (void)(alg_invoke(alg_property(v_this, "LoopLabels"), "Add", (Value[]){alg_property(v_thestmt, "Label")}, 1));
    (void)(alg_invoke(alg_property(v_this, "LoopDepths"), "Add", (Value[]){alg_property(v_this, "TryDepth")}, 1));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    (void)(alg_invoke(alg_property(v_this, "LoopLabels"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LoopLabels"), "Length"), alg_int(1))}, 1));
    (void)(alg_invoke(alg_property(v_this, "LoopDepths"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LoopDepths"), "Length"), alg_int(1))}, 1));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_widen(v_enclosingloopdepth, "Integer")));
    (void)(alg_invoke(v_this, "EmitContinueTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "EmitBreakTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_widen(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)), "Integer")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1));
    return alg_nil();
}

static Value m_cemitter_breaktarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    return alg_add(alg_string("lb_"), alg_invoke(v_this, "Escaped", (Value[]){f_foldcase(NULL, (Value[]){v_thelabel}, 1)}, 1));
    return alg_nil();
}

static Value m_cemitter_continuetarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    return alg_add(alg_string("lc_"), alg_invoke(v_this, "Escaped", (Value[]){f_foldcase(NULL, (Value[]){v_thelabel}, 1)}, 1));
    return alg_nil();
}

static Value m_cemitter_depthofloop_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    {
        Value v_i = alg_subtract(alg_property(alg_property(v_this, "LoopLabels"), "Length"), alg_int(1));
        (void)v_i;
        for (; alg_truthy(alg_greater_equal(v_i, alg_int(0))); (v_i = alg_subtract(v_i, alg_int(1)))) {
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_str(alg_subscript_get(alg_property(v_this, "LoopLabels"), v_i))}, 1), f_foldcase(NULL, (Value[]){v_thelabel}, 1)))) {
                return alg_cast(alg_subscript_get(alg_property(v_this, "LoopDepths"), v_i), "Integer");
            }
        }
    }
    return alg_property(v_this, "LoopTryDepth");
    return alg_nil();
}

static Value m_cemitter_popframesto_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_from = alg_widen(args[0], "Integer");
    (void)v_from;
    {
        Value v_i = v_from;
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_property(v_this, "TryDepth"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("alg_pop_frame();")}, 1));
        }
    }
    return alg_nil();
}

static Value m_cemitter_visitbreakstmt_1_breakstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "BreakStmt");
    (void)v_thestmt;
    if (alg_truthy(alg_equal(alg_property(v_thestmt, "Label"), alg_string("")))) {
        {
            (void)(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_property(v_this, "LoopTryDepth")}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("break;")}, 1));
            return alg_nil();
        }
    }
    (void)(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_invoke(v_this, "DepthOfLoop", (Value[]){alg_property(v_thestmt, "Label")}, 1)}, 1));
    Value v_target = alg_invoke(v_this, "BreakTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1);
    (void)v_target;
    (void)(alg_invoke(alg_property(v_this, "Jumped"), "Add", (Value[]){v_target}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("goto "), v_target), alg_char_value(59))}, 1));
    return alg_nil();
}

static Value m_cemitter_visitcontinuestmt_1_continuestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "ContinueStmt");
    (void)v_thestmt;
    if (alg_truthy(alg_equal(alg_property(v_thestmt, "Label"), alg_string("")))) {
        {
            (void)(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_property(v_this, "LoopTryDepth")}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("continue;")}, 1));
            return alg_nil();
        }
    }
    (void)(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_invoke(v_this, "DepthOfLoop", (Value[]){alg_property(v_thestmt, "Label")}, 1)}, 1));
    Value v_target = alg_invoke(v_this, "ContinueTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1);
    (void)v_target;
    (void)(alg_invoke(alg_property(v_this, "Jumped"), "Add", (Value[]){v_target}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("goto "), v_target), alg_char_value(59))}, 1));
    return alg_nil();
}

static Value m_cemitter_visitlabelstmt_1_labelstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "LabelStmt");
    (void)v_thestmt;
    if (alg_truthy(alg_property(v_thestmt, "Targeted"))) {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_invoke(v_this, "GotoTarget", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1), alg_string(": ;"))}, 1));
    }
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "Inner")}, 1));
    return alg_nil();
}

static Value m_cemitter_visitvargroupstmt_1_vargroupstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "VarGroupStmt");
    (void)v_thestmt;
    Value v_value = alg_nil();
    (void)v_value;
    Value v_shared = alg_nil();
    (void)v_shared;
    (void)((v_value = alg_widen(alg_string("alg_nil()"), "String")));
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Initializer"), alg_nil()))) {
        (void)((v_value = alg_widen(alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Initializer")}, 1), "String")));
    }
    (void)((v_shared = alg_widen(alg_add(alg_string("shared_"), alg_str(alg_property(v_this, "Loops"))), "String")));
    (void)(alg_set_property(v_this, "Loops", alg_widen(alg_add(alg_property(v_this, "Loops"), alg_int(1)), "Integer")));
    if (alg_truthy(alg_property(v_this, "AtTopLevel"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_shared), alg_char_value(59)), alg_char_value(10))}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(v_shared, alg_string(" = ")), v_value), alg_char_value(59))}, 1));
        }
    } else {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), v_shared), alg_string(" = ")), v_value), alg_char_value(59))}, 1));
    }
    {
        Value loop_61 = alg_iterable(alg_property(v_thestmt, "Names"));
        for (int32_t at_61 = 0; at_61 < alg_iterable_count(loop_61); at_61++) {
            Value v_thename = alg_iterable_at(loop_61, at_61);
            (void)v_thename;
            {
                Value v_name = alg_str(alg_property(v_thename, "Lexeme"));
                (void)v_name;
                if (alg_truthy(alg_property(v_this, "AtTopLevel"))) {
                    {
                        (void)(alg_invoke(v_this, "DeclareVariable", (Value[]){alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1), v_name}, 2));
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1), alg_string(" = ")), v_shared), alg_char_value(59))}, 1));
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1), alg_string(" = true;"))}, 1));
                    }
                } else {
                    if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1))) {
                        {
                            (void)(alg_invoke(v_this, "RequireCell", (Value[]){v_name}, 1));
                            (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_name}, 1));
                            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_char_value(42), alg_invoke(v_this, "Cell", (Value[]){v_name}, 1)), alg_string(" = ")), v_shared), alg_char_value(59))}, 1));
                        }
                    } else {
                        {
                            (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_name}, 1));
                            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), alg_string(" = ")), v_shared), alg_char_value(59))}, 1));
                            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), alg_char_value(59))}, 1));
                        }
                    }
                }
            }
        }
    }
    return alg_nil();
}

static Value m_cemitter_visitmodulestmt_1_modulestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    Value v_thestmt = alg_widen(args[0], "ModuleStmt");
    (void)v_thestmt;
    if (alg_truthy(alg_not(alg_property(v_this, "AtTopLevel")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("A nested 'uses'")}, 1));
    }
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Statements"), alg_nil()))) {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("init_"), alg_invoke(v_this, "UnitNameOf", (Value[]){alg_str(alg_property(v_thestmt, "FileName"))}, 1)), alg_string("();"))}, 1));
    }
    return alg_nil();
}

void init_CEmitter(void) {
    k_emitunit = alg_class("EmitUnit", alg_nil());
    k_cemitter = alg_class("CEmitter", alg_nil());
    fn_indentation = alg_closure("Indentation", f_indentation, NULL, 0, 1, t_f_indentation);
    fn_quotec = alg_closure("QuoteC", f_quotec, NULL, 0, 1, t_f_quotec);
    alg_class_field(k_emitunit, "Name");
    alg_class_field(k_emitunit, "Statements");
    alg_class_field(k_emitunit, "Imports");
    alg_class_field(k_emitunit, "PrivateNames");
    alg_class_field(k_emitunit, "FileName");
    alg_class_initializer(k_emitunit, i_emitunit);
    alg_class_method(k_emitunit, "Init", m_emitunit_init_5_string_list_list_list_string, 5, t_emitunit_init_5_string_list_list_list_string);
    alg_class_field(k_cemitter, "Declarations");
    alg_class_field(k_cemitter, "Functions");
    alg_class_field(k_cemitter, "MainBody");
    alg_class_field(k_cemitter, "Setup");
    alg_class_field(k_cemitter, "Shells");
    alg_class_field(k_cemitter, "Body");
    alg_class_field(k_cemitter, "TestSymbols");
    alg_class_field(k_cemitter, "Header");
    alg_class_field(k_cemitter, "UnitName");
    alg_class_field(k_cemitter, "PrivateNames");
    alg_class_field(k_cemitter, "RootUnit");
    alg_class_field(k_cemitter, "UnitTests");
    alg_class_field(k_cemitter, "Target");
    alg_class_field(k_cemitter, "Depth");
    alg_class_field(k_cemitter, "AtTopLevel");
    alg_class_field(k_cemitter, "Locals");
    alg_class_field(k_cemitter, "Declared");
    alg_class_field(k_cemitter, "Logicals");
    alg_class_field(k_cemitter, "Loops");
    alg_class_field(k_cemitter, "TryDepth");
    alg_class_field(k_cemitter, "LoopTryDepth");
    alg_class_field(k_cemitter, "LoopLabels");
    alg_class_field(k_cemitter, "LoopDepths");
    alg_class_field(k_cemitter, "Jumped");
    alg_class_field(k_cemitter, "LabelDepths");
    alg_class_field(k_cemitter, "Volatiles");
    alg_class_field(k_cemitter, "Renames");
    alg_class_field(k_cemitter, "Overloaded");
    alg_class_field(k_cemitter, "OverloadsIn");
    alg_class_field(k_cemitter, "Tables");
    alg_class_field(k_cemitter, "SetsBuilt");
    alg_class_field(k_cemitter, "Renamed");
    alg_class_field(k_cemitter, "AmbiguousImports");
    alg_class_field(k_cemitter, "AmbiguousMembers");
    alg_class_field(k_cemitter, "Boxed");
    alg_class_field(k_cemitter, "Cells");
    alg_class_field(k_cemitter, "Captured");
    alg_class_field(k_cemitter, "Globals");
    alg_class_field(k_cemitter, "TopLevel");
    alg_class_field(k_cemitter, "UnitExports");
    alg_class_field(k_cemitter, "UnitAll");
    alg_class_field(k_cemitter, "ShadowNames");
    alg_class_field(k_cemitter, "Canonical");
    alg_class_field(k_cemitter, "InsideNested");
    alg_class_field(k_cemitter, "EmitTests");
    alg_class_field(k_cemitter, "Tests");
    alg_class_field(k_cemitter, "TestFiles");
    alg_class_field(k_cemitter, "CurrentFile");
    alg_class_field(k_cemitter, "SourceFile");
    alg_class_field(k_cemitter, "Classes");
    alg_class_field(k_cemitter, "OwnClasses");
    alg_class_field(k_cemitter, "Objects");
    alg_class_field(k_cemitter, "EnumTypes");
    alg_class_field(k_cemitter, "EnumMembers");
    alg_class_field(k_cemitter, "CurrentClass");
    alg_class_field(k_cemitter, "VisibleFields");
    alg_class_field(k_cemitter, "VisibleMethods");
    alg_class_initializer(k_cemitter, i_cemitter);
    alg_class_method(k_cemitter, "Init", m_cemitter_init_0, 0, NULL);
    alg_class_method(k_cemitter, "Unsupported", m_cemitter_unsupported_1, 1, t_cemitter_unsupported_1);
    alg_class_method(k_cemitter, "Line", m_cemitter_line_1, 1, t_cemitter_line_1);
    alg_class_method(k_cemitter, "Mangle", m_cemitter_mangle_2_string_string, 2, t_cemitter_mangle_2_string_string);
    alg_class_method(k_cemitter, "SymbolOf", m_cemitter_symbolof_2_string_string, 2, t_cemitter_symbolof_2_string_string);
    alg_class_method(k_cemitter, "ClassHandle", m_cemitter_classhandle_1_string, 1, t_cemitter_classhandle_1_string);
    alg_class_method(k_cemitter, "InitName", m_cemitter_initname_1_string, 1, t_cemitter_initname_1_string);
    alg_class_method(k_cemitter, "EnumTypeName", m_cemitter_enumtypename_1_string, 1, t_cemitter_enumtypename_1_string);
    alg_class_method(k_cemitter, "EnumMemberName", m_cemitter_enummembername_2_string_string, 2, t_cemitter_enummembername_2_string_string);
    alg_class_method(k_cemitter, "HexOf", m_cemitter_hexof_1_integer, 1, t_cemitter_hexof_1_integer);
    alg_class_method(k_cemitter, "Escaped", m_cemitter_escaped_1_string, 1, t_cemitter_escaped_1_string);
    alg_class_method(k_cemitter, "Sanitize", m_cemitter_sanitize_1_string, 1, t_cemitter_sanitize_1_string);
    alg_class_method(k_cemitter, "CollectUnits", m_cemitter_collectunits_5_list_string_list_list_string, 5, t_cemitter_collectunits_5_list_string_list_list_string);
    alg_class_method(k_cemitter, "UnitNameOf", m_cemitter_unitnameof_1_string, 1, t_cemitter_unitnameof_1_string);
    alg_class_method(k_cemitter, "VariableName", m_cemitter_variablename_1_string, 1, t_cemitter_variablename_1_string);
    alg_class_method(k_cemitter, "DeclaredFlag", m_cemitter_declaredflag_1_string, 1, t_cemitter_declaredflag_1_string);
    alg_class_method(k_cemitter, "FunctionName", m_cemitter_functionname_1_string, 1, t_cemitter_functionname_1_string);
    alg_class_method(k_cemitter, "HandleName", m_cemitter_handlename_1_string, 1, t_cemitter_handlename_1_string);
    alg_class_method(k_cemitter, "SetName", m_cemitter_setname_1_string, 1, t_cemitter_setname_1_string);
    alg_class_method(k_cemitter, "SubprogramValue", m_cemitter_subprogramvalue_1_string, 1, t_cemitter_subprogramvalue_1_string);
    alg_class_method(k_cemitter, "FunctionSymbol", m_cemitter_functionsymbol_1, 1, t_cemitter_functionsymbol_1);
    alg_class_method(k_cemitter, "Prototype", m_cemitter_prototype_1, 1, t_cemitter_prototype_1);
    alg_class_method(k_cemitter, "RunsWhenTesting", m_cemitter_runswhentesting_1_stmt, 1, t_cemitter_runswhentesting_1_stmt);
    alg_class_method(k_cemitter, "Exported", m_cemitter_exported_1_string, 1, t_cemitter_exported_1_string);
    alg_class_method(k_cemitter, "DeclareValue", m_cemitter_declarevalue_2_string_string, 2, t_cemitter_declarevalue_2_string_string);
    alg_class_method(k_cemitter, "DeclareVariable", m_cemitter_declarevariable_2_string_string, 2, t_cemitter_declarevariable_2_string_string);
    alg_class_method(k_cemitter, "IsTest", m_cemitter_istest_1, 1, t_cemitter_istest_1);
    alg_class_method(k_cemitter, "CollectFunctions", m_cemitter_collectfunctions_1_list, 1, t_cemitter_collectfunctions_1_list);
    alg_class_method(k_cemitter, "CollectGlobals", m_cemitter_collectglobals_1_list, 1, t_cemitter_collectglobals_1_list);
    alg_class_method(k_cemitter, "CompilingFile", m_cemitter_compilingfile_1_string, 1, t_cemitter_compilingfile_1_string);
    alg_class_method(k_cemitter, "WithTests", m_cemitter_withtests_0, 0, NULL);
    alg_class_method(k_cemitter, "Emit", m_cemitter_emit_2_list_string, 2, t_cemitter_emit_2_list_string);
    alg_class_method(k_cemitter, "UnitHeader", m_cemitter_unitheader_1, 1, t_cemitter_unitheader_1);
    alg_class_method(k_cemitter, "UnitSource", m_cemitter_unitsource_4_list_boolean_string, 4, t_cemitter_unitsource_4_list_boolean_string);
    alg_class_method(k_cemitter, "Upper", m_cemitter_upper_1_string, 1, t_cemitter_upper_1_string);
    alg_class_method(k_cemitter, "EmitTestRunner", m_cemitter_emittestrunner_0, 0, NULL);
    alg_class_method(k_cemitter, "Execute", m_cemitter_execute_1, 1, t_cemitter_execute_1);
    alg_class_method(k_cemitter, "Evaluate", m_cemitter_evaluate_1, 1, t_cemitter_evaluate_1);
    alg_class_method(k_cemitter, "EmitTest", m_cemitter_emittest_1, 1, t_cemitter_emittest_1);
    alg_class_method(k_cemitter, "RefuseBareBinding", m_cemitter_refusebarebinding_1, 1, t_cemitter_refusebarebinding_1);
    alg_class_method(k_cemitter, "DeclaresNested", m_cemitter_declaresnested_1_list, 1, t_cemitter_declaresnested_1_list);
    alg_class_method(k_cemitter, "AddOnce", m_cemitter_addonce_2_list_string, 2, t_cemitter_addonce_2_list_string);
    alg_class_method(k_cemitter, "CollectBindings", m_cemitter_collectbindings_2_list_list, 2, t_cemitter_collectbindings_2_list_list);
    alg_class_method(k_cemitter, "BoundNames", m_cemitter_boundnames_1, 1, t_cemitter_boundnames_1);
    alg_class_method(k_cemitter, "BoxesFor", m_cemitter_boxesfor_1_list, 1, t_cemitter_boxesfor_1_list);
    alg_class_method(k_cemitter, "Cell", m_cemitter_cell_1_string, 1, t_cemitter_cell_1_string);
    alg_class_method(k_cemitter, "ThisRef", m_cemitter_thisref_0, 0, NULL);
    alg_class_method(k_cemitter, "CellPointer", m_cemitter_cellpointer_1_string, 1, t_cemitter_cellpointer_1_string);
    alg_class_method(k_cemitter, "VisibleCells", m_cemitter_visiblecells_2_map_list, 2, t_cemitter_visiblecells_2_map_list);
    alg_class_method(k_cemitter, "Read", m_cemitter_read_1_string, 1, t_cemitter_read_1_string);
    alg_class_method(k_cemitter, "ClosureOf", m_cemitter_closureof_2_list, 2, t_cemitter_closureof_2_list);
    alg_class_method(k_cemitter, "ContainsTry", m_cemitter_containstry_1_list, 1, t_cemitter_containstry_1_list);
    alg_class_method(k_cemitter, "Local", m_cemitter_local_0, 0, NULL);
    alg_class_method(k_cemitter, "RequireCell", m_cemitter_requirecell_1_string, 1, t_cemitter_requirecell_1_string);
    alg_class_method(k_cemitter, "OpenScope", m_cemitter_openscope_0, 0, NULL);
    alg_class_method(k_cemitter, "CloseScope", m_cemitter_closescope_1_list, 1, t_cemitter_closescope_1_list);
    alg_class_method(k_cemitter, "DeclareCell", m_cemitter_declarecell_2_string_string, 2, t_cemitter_declarecell_2_string_string);
    alg_class_method(k_cemitter, "HoistCells", m_cemitter_hoistcells_1_list, 1, t_cemitter_hoistcells_1_list);
    alg_class_method(k_cemitter, "EmitHandlerBody", m_cemitter_emithandlerbody_2_string, 2, t_cemitter_emithandlerbody_2_string);
    alg_class_method(k_cemitter, "DeclaredTypes", m_cemitter_declaredtypes_1, 1, t_cemitter_declaredtypes_1);
    alg_class_method(k_cemitter, "ParameterTable", m_cemitter_parametertable_1, 1, t_cemitter_parametertable_1);
    alg_class_method(k_cemitter, "Variadic", m_cemitter_variadic_1, 1, t_cemitter_variadic_1);
    alg_class_method(k_cemitter, "MethodSymbol", m_cemitter_methodsymbol_2_string, 2, t_cemitter_methodsymbol_2_string);
    alg_class_method(k_cemitter, "NamesVisible", m_cemitter_namesvisible_3_string_list_boolean, 3, t_cemitter_namesvisible_3_string_list_boolean);
    alg_class_method(k_cemitter, "EmitMethod", m_cemitter_emitmethod_2_string, 2, t_cemitter_emitmethod_2_string);
    alg_class_method(k_cemitter, "EmitClass", m_cemitter_emitclass_5_string_list_list_boolean, 5, t_cemitter_emitclass_5_string_list_list_boolean);
    alg_class_method(k_cemitter, "Built", m_cemitter_built_2_boolean_string, 2, t_cemitter_built_2_boolean_string);
    alg_class_method(k_cemitter, "VisitVarStmt", m_cemitter_visitvarstmt_1_varstmt, 1, t_cemitter_visitvarstmt_1_varstmt);
    alg_class_method(k_cemitter, "VisitExpressionStmt", m_cemitter_visitexpressionstmt_1_expressionstmt, 1, t_cemitter_visitexpressionstmt_1_expressionstmt);
    alg_class_method(k_cemitter, "PushLabels", m_cemitter_pushlabels_1_list, 1, t_cemitter_pushlabels_1_list);
    alg_class_method(k_cemitter, "PopLabels", m_cemitter_poplabels_0, 0, NULL);
    alg_class_method(k_cemitter, "DepthOfLabel", m_cemitter_depthoflabel_1_string, 1, t_cemitter_depthoflabel_1_string);
    alg_class_method(k_cemitter, "GotoTarget", m_cemitter_gototarget_1_string, 1, t_cemitter_gototarget_1_string);
    alg_class_method(k_cemitter, "VisitGotoStmt", m_cemitter_visitgotostmt_1_gotostmt, 1, t_cemitter_visitgotostmt_1_gotostmt);
    alg_class_method(k_cemitter, "VisitBlockStmt", m_cemitter_visitblockstmt_1_blockstmt, 1, t_cemitter_visitblockstmt_1_blockstmt);
    alg_class_method(k_cemitter, "VisitIfStmt", m_cemitter_visitifstmt_1_ifstmt, 1, t_cemitter_visitifstmt_1_ifstmt);
    alg_class_method(k_cemitter, "VisitWhileStmt", m_cemitter_visitwhilestmt_1_whilestmt, 1, t_cemitter_visitwhilestmt_1_whilestmt);
    alg_class_method(k_cemitter, "EmitContinueTarget", m_cemitter_emitcontinuetarget_1_string, 1, t_cemitter_emitcontinuetarget_1_string);
    alg_class_method(k_cemitter, "EmitBreakTarget", m_cemitter_emitbreaktarget_1_string, 1, t_cemitter_emitbreaktarget_1_string);
    alg_class_method(k_cemitter, "VisitReturnStmt", m_cemitter_visitreturnstmt_1_returnstmt, 1, t_cemitter_visitreturnstmt_1_returnstmt);
    alg_class_method(k_cemitter, "EmitForeign", m_cemitter_emitforeign_1_functionstmt, 1, t_cemitter_emitforeign_1_functionstmt);
    alg_class_method(k_cemitter, "VisitFunctionStmt", m_cemitter_visitfunctionstmt_1_functionstmt, 1, t_cemitter_visitfunctionstmt_1_functionstmt);
    alg_class_method(k_cemitter, "TypeTable", m_cemitter_typetable_2_string_list, 2, t_cemitter_typetable_2_string_list);
    alg_class_method(k_cemitter, "VisitLiteral", m_cemitter_visitliteral_1_literalexpr, 1, t_cemitter_visitliteral_1_literalexpr);
    alg_class_method(k_cemitter, "VisitVariableExpr", m_cemitter_visitvariableexpr_1_variableexpr, 1, t_cemitter_visitvariableexpr_1_variableexpr);
    alg_class_method(k_cemitter, "Guarded", m_cemitter_guarded_2_string_string, 2, t_cemitter_guarded_2_string_string);
    alg_class_method(k_cemitter, "MissingName", m_cemitter_missingname_1_string, 1, t_cemitter_missingname_1_string);
    alg_class_method(k_cemitter, "Spelled", m_cemitter_spelled_1_string, 1, t_cemitter_spelled_1_string);
    alg_class_method(k_cemitter, "Unreachable", m_cemitter_unreachable_1_string, 1, t_cemitter_unreachable_1_string);
    alg_class_method(k_cemitter, "BoundValue", m_cemitter_boundvalue_2_string, 2, t_cemitter_boundvalue_2_string);
    alg_class_method(k_cemitter, "VisitAssignExpr", m_cemitter_visitassignexpr_1_assignexpr, 1, t_cemitter_visitassignexpr_1_assignexpr);
    alg_class_method(k_cemitter, "VisitGrouping", m_cemitter_visitgrouping_1_groupingexpr, 1, t_cemitter_visitgrouping_1_groupingexpr);
    alg_class_method(k_cemitter, "VisitIsExpr", m_cemitter_visitisexpr_1_isexpr, 1, t_cemitter_visitisexpr_1_isexpr);
    alg_class_method(k_cemitter, "VisitUnary", m_cemitter_visitunary_1_unaryexpr, 1, t_cemitter_visitunary_1_unaryexpr);
    alg_class_method(k_cemitter, "VisitBinary", m_cemitter_visitbinary_1_binaryexpr, 1, t_cemitter_visitbinary_1_binaryexpr);
    alg_class_method(k_cemitter, "BuiltinCounts", m_cemitter_builtincounts_1_string, 1, t_cemitter_builtincounts_1_string);
    alg_class_method(k_cemitter, "CountsMessage", m_cemitter_countsmessage_2_list_integer, 2, t_cemitter_countsmessage_2_list_integer);
    alg_class_method(k_cemitter, "RenamesOf", m_cemitter_renamesof_2_string_string, 2, t_cemitter_renamesof_2_string_string);
    alg_class_method(k_cemitter, "MarkAmbiguousImport", m_cemitter_markambiguousimport_3_string_string_string, 3, t_cemitter_markambiguousimport_3_string_string_string);
    alg_class_method(k_cemitter, "MarkAmbiguousMember", m_cemitter_markambiguousmember_3_string_string_string, 3, t_cemitter_markambiguousmember_3_string_string_string);
    alg_class_method(k_cemitter, "AmbiguousMessage", m_cemitter_ambiguousmessage_2_string_string, 2, t_cemitter_ambiguousmessage_2_string_string);
    alg_class_method(k_cemitter, "IsAssertion", m_cemitter_isassertion_1_string, 1, t_cemitter_isassertion_1_string);
    alg_class_method(k_cemitter, "Builtin", m_cemitter_builtin_2_string_integer, 2, t_cemitter_builtin_2_string_integer);
    alg_class_method(k_cemitter, "RunTogether", m_cemitter_runtogether_1_list, 1, t_cemitter_runtogether_1_list);
    alg_class_method(k_cemitter, "AnyNamed", m_cemitter_anynamed_1_list, 1, t_cemitter_anynamed_1_list);
    alg_class_method(k_cemitter, "NameArray", m_cemitter_namearray_1_list, 1, t_cemitter_namearray_1_list);
    alg_class_method(k_cemitter, "Calling", m_cemitter_calling_3_string_list_list, 3, t_cemitter_calling_3_string_list_list);
    alg_class_method(k_cemitter, "Constructing", m_cemitter_constructing_3_string_list_list, 3, t_cemitter_constructing_3_string_list_list);
    alg_class_method(k_cemitter, "Invoking", m_cemitter_invoking_4_string_string_list_list, 4, t_cemitter_invoking_4_string_string_list_list);
    alg_class_method(k_cemitter, "ArgumentArray", m_cemitter_argumentarray_1_list, 1, t_cemitter_argumentarray_1_list);
    alg_class_method(k_cemitter, "ExportedNames", m_cemitter_exportednames_1_emitunit, 1, t_cemitter_exportednames_1_emitunit);
    alg_class_method(k_cemitter, "ConstructorFor", m_cemitter_constructorfor_3_string_list_string, 3, t_cemitter_constructorfor_3_string_list_string);
    alg_class_method(k_cemitter, "UnitCall", m_cemitter_unitcall_5_string_string_list_string_list, 5, t_cemitter_unitcall_5_string_string_list_string_list);
    alg_class_method(k_cemitter, "VisitCall", m_cemitter_visitcall_1_callexpr, 1, t_cemitter_visitcall_1_callexpr);
    alg_class_method(k_cemitter, "VisitLogical", m_cemitter_visitlogical_1_logicalexpr, 1, t_cemitter_visitlogical_1_logicalexpr);
    alg_class_method(k_cemitter, "BoundArgument", m_cemitter_boundargument_3_integer, 3, t_cemitter_boundargument_3_integer);
    alg_class_method(k_cemitter, "AllLiterals", m_cemitter_allliterals_1_collectionexpr, 1, t_cemitter_allliterals_1_collectionexpr);
    alg_class_method(k_cemitter, "VisitCollectionExpr", m_cemitter_visitcollectionexpr_1_collectionexpr, 1, t_cemitter_visitcollectionexpr_1_collectionexpr);
    alg_class_method(k_cemitter, "HoistedCollection", m_cemitter_hoistedcollection_1_collectionexpr, 1, t_cemitter_hoistedcollection_1_collectionexpr);
    alg_class_method(k_cemitter, "ComputedCollection", m_cemitter_computedcollection_1_collectionexpr, 1, t_cemitter_computedcollection_1_collectionexpr);
    alg_class_method(k_cemitter, "VisitSubscriptExpr", m_cemitter_visitsubscriptexpr_1_subscriptexpr, 1, t_cemitter_visitsubscriptexpr_1_subscriptexpr);
    alg_class_method(k_cemitter, "VisitSetSubscriptExpr", m_cemitter_visitsetsubscriptexpr_1_setsubscriptexpr, 1, t_cemitter_visitsetsubscriptexpr_1_setsubscriptexpr);
    alg_class_method(k_cemitter, "UnitValue", m_cemitter_unitvalue_2_string_string, 2, t_cemitter_unitvalue_2_string_string);
    alg_class_method(k_cemitter, "VisitGetExpr", m_cemitter_visitgetexpr_1_getexpr, 1, t_cemitter_visitgetexpr_1_getexpr);
    alg_class_method(k_cemitter, "VisitSetExpr", m_cemitter_visitsetexpr_1_setexpr, 1, t_cemitter_visitsetexpr_1_setexpr);
    alg_class_method(k_cemitter, "VisitSuperExpr", m_cemitter_visitsuperexpr_1_superexpr, 1, t_cemitter_visitsuperexpr_1_superexpr);
    alg_class_method(k_cemitter, "VisitThisExpr", m_cemitter_visitthisexpr_1_thisexpr, 1, t_cemitter_visitthisexpr_1_thisexpr);
    alg_class_method(k_cemitter, "VisitClassStmt", m_cemitter_visitclassstmt_1_classstmt, 1, t_cemitter_visitclassstmt_1_classstmt);
    alg_class_method(k_cemitter, "VisitObjectStmt", m_cemitter_visitobjectstmt_1_objectstmt, 1, t_cemitter_visitobjectstmt_1_objectstmt);
    alg_class_method(k_cemitter, "VisitSubrangeStmt", m_cemitter_visitsubrangestmt_1_subrangestmt, 1, t_cemitter_visitsubrangestmt_1_subrangestmt);
    alg_class_method(k_cemitter, "EmitSubranges", m_cemitter_emitsubranges_0, 0, NULL);
    alg_class_method(k_cemitter, "VisitEnumStmt", m_cemitter_visitenumstmt_1_enumstmt, 1, t_cemitter_visitenumstmt_1_enumstmt);
    alg_class_method(k_cemitter, "VisitTryStmt", m_cemitter_visittrystmt_1_trystmt, 1, t_cemitter_visittrystmt_1_trystmt);
    alg_class_method(k_cemitter, "VisitRaiseStmt", m_cemitter_visitraisestmt_1_raisestmt, 1, t_cemitter_visitraisestmt_1_raisestmt);
    alg_class_method(k_cemitter, "VisitForInStmt", m_cemitter_visitforinstmt_1_forinstmt, 1, t_cemitter_visitforinstmt_1_forinstmt);
    alg_class_method(k_cemitter, "BreakTarget", m_cemitter_breaktarget_1_string, 1, t_cemitter_breaktarget_1_string);
    alg_class_method(k_cemitter, "ContinueTarget", m_cemitter_continuetarget_1_string, 1, t_cemitter_continuetarget_1_string);
    alg_class_method(k_cemitter, "DepthOfLoop", m_cemitter_depthofloop_1_string, 1, t_cemitter_depthofloop_1_string);
    alg_class_method(k_cemitter, "PopFramesTo", m_cemitter_popframesto_1_integer, 1, t_cemitter_popframesto_1_integer);
    alg_class_method(k_cemitter, "VisitBreakStmt", m_cemitter_visitbreakstmt_1_breakstmt, 1, t_cemitter_visitbreakstmt_1_breakstmt);
    alg_class_method(k_cemitter, "VisitContinueStmt", m_cemitter_visitcontinuestmt_1_continuestmt, 1, t_cemitter_visitcontinuestmt_1_continuestmt);
    alg_class_method(k_cemitter, "VisitLabelStmt", m_cemitter_visitlabelstmt_1_labelstmt, 1, t_cemitter_visitlabelstmt_1_labelstmt);
    alg_class_method(k_cemitter, "VisitVarGroupStmt", m_cemitter_visitvargroupstmt_1_vargroupstmt, 1, t_cemitter_visitvargroupstmt_1_vargroupstmt);
    alg_class_method(k_cemitter, "VisitModuleStmt", m_cemitter_visitmodulestmt_1_modulestmt, 1, t_cemitter_visitmodulestmt_1_modulestmt);
    v_hoistVabove = alg_int(100);
    d_hoistVabove = true;
}
