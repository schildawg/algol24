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
static Value or_88;
static Value or_89;
static Value or_90;
static Value or_91;
static Value or_92;
static Value or_93;
static Value or_94;
static Value or_95;
static Value or_96;
static Value or_97;
static Value or_98;
static Value or_99;
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
static const char *t_cemitter_isoverloadset_1_string[] = { "Name : String" };
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
static const char *t_cemitter_root_2_string_string[] = { "Slots : String", "Count : String" };
static const char *t_cemitter_declarelocal_2_string_string[] = { "Symbol : String", "Initial : String" };
static const char *t_cemitter_emitreturn_1_string[] = { "Value : String" };
static const char *t_cemitter_openroots_1_boolean[] = { "Declares : Boolean" };
static const char *t_cemitter_closeroots_1_string[] = { "Mark : String" };
static const char *t_cemitter_declareslocal_1_list[] = { "Statements : List" };
static const char *t_cemitter_declarecell_2_string_string[] = { "Name : String", "Initial : String" };
static const char *t_cemitter_hoistcells_1_list[] = { "Statements : List" };
static const char *t_cemitter_emithandlerbody_2_string[] = { "Handler : Any", "Frame : String" };
static const char *t_cemitter_declaredtypes_1[] = { "TheMethod : Any" };
static const char *t_cemitter_parametertable_1[] = { "TheMethod : Any" };
static const char *t_cemitter_collectshadowarities_2_list_list[] = { "Statements : List", "Hidden : List" };
static const char *t_cemitter_takesover_2_string_integer[] = { "Name : String", "Count : Integer" };
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
static const char *t_cemitter_ownglobal_1_string[] = { "Name : String" };
static const char *t_cemitter_visiblesubprogram_1_string[] = { "Name : String" };
static const char *t_cemitter_missingname_1_string[] = { "Name : String" };
static const char *t_cemitter_spelled_1_string[] = { "Name : String" };
static const char *t_cemitter_unreachable_1_string[] = { "Name : String" };
static const char *t_cemitter_boundvalue_3_string[] = { "Declared : Any", "Value : String", "Actual : Any" };
static const char *t_cemitter_elidable_2[] = { "Declared : Any", "Actual : Any" };
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
static const char *t_cemitter_invokingor_5_string_string_list_list_string[] = { "Receiver : String", "TheName : String", "Emitted : List", "Names : List", "Extension : String" };
static const char *t_cemitter_overloadedelsewhere_2_string_string[] = { "Unit : String", "Name : String" };
static const char *t_cemitter_extensionvalue_1_getexpr[] = { "TheExpr : GetExpr" };
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
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_depth = alg_param(args[0], "Integer");
    (void)v_depth;
    alg_root(&v_depth, 1);
    Value v_result = alg_string("");
    (void)v_result;
    alg_root(&v_result, 1);
    {
        int32_t rt_381 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, v_depth)); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)((v_result = alg_add(v_result, alg_string("    "))));
        }
        alg_root_top = rt_381;
    }
    Value ret_0 = v_result;
    alg_root_top = rt_base;
    return ret_0;
    Value ret_1 = alg_nil();
    alg_root_top = rt_base;
    return ret_1;
}

Value f_quotec(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_text = args[0];
    (void)v_text;
    alg_root(&v_text, 1);
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    (void)((v_result = alg_str(alg_char_value(34))));
    {
        int32_t rt_382 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_text))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_383 = alg_root_top;
                Value v_c = alg_subscript_get(alg_str(v_text), v_i);
                (void)v_c;
                alg_root(&v_c, 1);
                if (alg_truthy(alg_equal(v_c, alg_char_value(34)))) {
                    (void)((v_result = alg_add(v_result, alg_string("\\\""))));
                } else {
                    if (alg_truthy(alg_equal(v_c, alg_char_value(92)))) {
                        (void)((v_result = alg_add(v_result, alg_string("\\\\"))));
                    } else {
                        if (alg_truthy(alg_equal(v_c, alg_char_value(10)))) {
                            (void)((v_result = alg_add(v_result, alg_string("\\n"))));
                        } else {
                            if (alg_truthy(alg_equal(v_c, alg_char_value(9)))) {
                                (void)((v_result = alg_add(v_result, alg_string("\\t"))));
                            } else {
                                if (alg_truthy(alg_equal(v_c, alg_char_value(13)))) {
                                    (void)((v_result = alg_add(v_result, alg_string("\\r"))));
                                } else {
                                    (void)((v_result = alg_add(v_result, alg_str(v_c))));
                                }
                            }
                        }
                    }
                }
                alg_root_top = rt_383;
            }
        }
        alg_root_top = rt_382;
    }
    Value ret_2 = alg_add(v_result, alg_str(alg_char_value(34)));
    alg_root_top = rt_base;
    return ret_2;
    Value ret_3 = alg_nil();
    alg_root_top = rt_base;
    return ret_3;
}

static Value i_emitunit(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Name", alg_nil());
    alg_set_property(v_this, "Statements", alg_nil());
    alg_set_property(v_this, "Imports", alg_nil());
    alg_set_property(v_this, "PrivateNames", alg_nil());
    alg_set_property(v_this, "FileName", alg_nil());
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_emitunit_init_5_string_list_list_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_statements = alg_widen(args[1], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    Value v_imports = alg_widen(args[2], "List");
    (void)v_imports;
    alg_root(&v_imports, 1);
    Value v_privatenames = alg_widen(args[3], "List");
    (void)v_privatenames;
    alg_root(&v_privatenames, 1);
    Value v_filename = alg_widen(args[4], "String");
    (void)v_filename;
    alg_root(&v_filename, 1);
    (void)(alg_set_property(v_this, "Name", v_name));
    (void)(alg_set_property(v_this, "Statements", v_statements));
    (void)(alg_set_property(v_this, "Imports", v_imports));
    (void)(alg_set_property(v_this, "PrivateNames", v_privatenames));
    (void)(alg_set_property(v_this, "FileName", v_filename));
    Value ret_4 = alg_nil();
    alg_root_top = rt_base;
    return ret_4;
}

static Value i_cemitter(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Declarations", alg_widen(alg_buffer(alg_int(0)), "Buffer"));
    alg_set_property(v_this, "RootSymbols", alg_widen(alg_list(), "List"));
    alg_set_property(v_this, "RootMarks", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "FrameRoots", alg_widen(alg_string(""), "String"));
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
    alg_set_property(v_this, "CollectingInto", alg_nil());
    alg_set_property(v_this, "DeclaredIn", alg_nil());
    alg_set_property(v_this, "VisibleDeclared", alg_nil());
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
    alg_set_property(v_this, "ImportedFrom", alg_nil());
    alg_set_property(v_this, "AmbiguousImports", alg_nil());
    alg_set_property(v_this, "AmbiguousMembers", alg_nil());
    alg_set_property(v_this, "Boxed", alg_nil());
    alg_set_property(v_this, "Cells", alg_nil());
    alg_set_property(v_this, "Captured", alg_nil());
    alg_set_property(v_this, "Globals", alg_nil());
    alg_set_property(v_this, "TopLevel", alg_nil());
    alg_set_property(v_this, "GlobalsIn", alg_nil());
    alg_set_property(v_this, "UnitExports", alg_nil());
    alg_set_property(v_this, "UnitAll", alg_nil());
    alg_set_property(v_this, "ShadowNames", alg_nil());
    alg_set_property(v_this, "ShadowArities", alg_nil());
    alg_set_property(v_this, "ShadowWhole", alg_nil());
    alg_set_property(v_this, "Canonical", alg_nil());
    alg_set_property(v_this, "InsideNested", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "NestedIn", alg_widen(alg_string(""), "String"));
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
    alg_root_top = rt_base;
    return alg_nil();
}

static Value m_cemitter_init_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_set_property(v_this, "Locals", alg_list()));
    (void)(alg_set_property(v_this, "Declared", alg_set()));
    (void)(alg_set_property(v_this, "Classes", alg_map()));
    (void)(alg_set_property(v_this, "OwnClasses", alg_set()));
    (void)(alg_set_property(v_this, "Objects", alg_set()));
    (void)(alg_set_property(v_this, "EnumTypes", alg_set()));
    (void)(alg_set_property(v_this, "EnumMembers", alg_map()));
    (void)(alg_set_property(v_this, "VisibleFields", alg_set()));
    (void)(alg_set_property(v_this, "VisibleMethods", alg_set()));
    (void)(alg_set_property(v_this, "Renames", alg_map()));
    (void)(alg_set_property(v_this, "AmbiguousMembers", alg_map()));
    (void)(alg_set_property(v_this, "AmbiguousImports", alg_map()));
    (void)(alg_set_property(v_this, "Renamed", alg_set()));
    (void)(alg_set_property(v_this, "ImportedFrom", alg_map()));
    (void)(alg_set_property(v_this, "Overloaded", alg_set()));
    (void)(alg_set_property(v_this, "OverloadsIn", alg_map()));
    (void)(alg_set_property(v_this, "Tables", alg_set()));
    (void)(alg_set_property(v_this, "SetsBuilt", alg_set()));
    (void)(alg_set_property(v_this, "Boxed", alg_list()));
    (void)(alg_set_property(v_this, "Cells", alg_list()));
    (void)(alg_set_property(v_this, "Captured", alg_map()));
    (void)(alg_set_property(v_this, "Globals", alg_set()));
    (void)(alg_set_property(v_this, "GlobalsIn", alg_map()));
    (void)(alg_set_property(v_this, "DeclaredIn", alg_map()));
    (void)(alg_set_property(v_this, "CollectingInto", alg_set()));
    (void)(alg_set_property(v_this, "VisibleDeclared", alg_set()));
    (void)(alg_set_property(v_this, "TopLevel", alg_set()));
    (void)(alg_set_property(v_this, "UnitExports", alg_map()));
    (void)(alg_set_property(v_this, "UnitAll", alg_map()));
    (void)(alg_set_property(v_this, "ShadowNames", alg_set()));
    (void)(alg_set_property(v_this, "Canonical", alg_map()));
    (void)(alg_set_property(v_this, "Tests", alg_list()));
    (void)(alg_set_property(v_this, "TestFiles", alg_list()));
    (void)(alg_set_property(v_this, "TestSymbols", alg_list()));
    (void)(alg_set_property(v_this, "PrivateNames", alg_list()));
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

static Value m_cemitter_unsupported_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_construct = args[0];
    (void)v_construct;
    alg_root(&v_construct, 1);
    alg_raise(alg_add(alg_str(v_construct), alg_string(" is not supported by the C back end yet.")));
    Value ret_6 = alg_nil();
    alg_root_top = rt_base;
    return ret_6;
}

static Value m_cemitter_line_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_text = args[0];
    (void)v_text;
    alg_root(&v_text, 1);
    if (alg_truthy(alg_equal(alg_property(v_this, "Target"), alg_string("body")))) {
        (void)(alg_invoke(alg_property(v_this, "Body"), "Append", (Value[]){alg_add(alg_add(f_indentation(NULL, (Value[]){alg_property(v_this, "Depth")}, 1), alg_str(v_text)), alg_char_value(10))}, 1));
    } else {
        (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_add(f_indentation(NULL, (Value[]){alg_property(v_this, "Depth")}, 1), alg_str(v_text)), alg_char_value(10))}, 1));
    }
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
}

static Value m_cemitter_mangle_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_prefix = alg_widen(args[0], "String");
    (void)v_prefix;
    alg_root(&v_prefix, 1);
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Renames"), "Contains", (Value[]){alg_str(v_name)}, 1))) {
        Value ret_8 = alg_add(alg_add(alg_add(v_prefix, alg_invoke(v_this, "Escaped", (Value[]){alg_str(v_name)}, 1)), alg_string("__")), alg_invoke(v_this, "Escaped", (Value[]){alg_str(alg_invoke(alg_property(v_this, "Renames"), "Get", (Value[]){alg_str(v_name)}, 1))}, 1));
        alg_root_top = rt_base;
        return ret_8;
    }
    Value ret_9 = alg_invoke(v_this, "SymbolOf", (Value[]){v_prefix, alg_str(v_name)}, 2);
    alg_root_top = rt_base;
    return ret_9;
    Value ret_10 = alg_nil();
    alg_root_top = rt_base;
    return ret_10;
}

static Value m_cemitter_symbolof_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_prefix = alg_widen(args[0], "String");
    (void)v_prefix;
    alg_root(&v_prefix, 1);
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_11 = alg_add(v_prefix, alg_invoke(v_this, "Escaped", (Value[]){v_name}, 1));
    alg_root_top = rt_base;
    return ret_11;
    Value ret_12 = alg_nil();
    alg_root_top = rt_base;
    return ret_12;
}

static Value m_cemitter_classhandle_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_13 = alg_invoke(v_this, "Mangle", (Value[]){alg_string("k_"), v_name}, 2);
    alg_root_top = rt_base;
    return ret_13;
    Value ret_14 = alg_nil();
    alg_root_top = rt_base;
    return ret_14;
}

static Value m_cemitter_initname_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_15 = alg_invoke(v_this, "SymbolOf", (Value[]){alg_string("i_"), v_name}, 2);
    alg_root_top = rt_base;
    return ret_15;
    Value ret_16 = alg_nil();
    alg_root_top = rt_base;
    return ret_16;
}

static Value m_cemitter_enumtypename_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_17 = alg_invoke(v_this, "Mangle", (Value[]){alg_string("e_"), v_name}, 2);
    alg_root_top = rt_base;
    return ret_17;
    Value ret_18 = alg_nil();
    alg_root_top = rt_base;
    return ret_18;
}

static Value m_cemitter_enummembername_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_typename = alg_widen(args[0], "String");
    (void)v_typename;
    alg_root(&v_typename, 1);
    Value v_member = alg_widen(args[1], "String");
    (void)v_member;
    alg_root(&v_member, 1);
    Value ret_19 = alg_add(alg_add(alg_invoke(v_this, "Mangle", (Value[]){alg_string("e_"), v_typename}, 2), alg_char_value(95)), alg_invoke(v_this, "Escaped", (Value[]){v_member}, 1));
    alg_root_top = rt_base;
    return ret_19;
    Value ret_20 = alg_nil();
    alg_root_top = rt_base;
    return ret_20;
}

static Value m_cemitter_hexof_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_code = alg_widen(args[0], "Integer");
    (void)v_code;
    alg_root(&v_code, 1);
    Value v_result = alg_string("");
    (void)v_result;
    alg_root(&v_result, 1);
    Value v_left = alg_nil();
    (void)v_left;
    alg_root(&v_left, 1);
    (void)((v_left = v_code));
    {
        int32_t rt_384 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_int(6))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                (void)((v_result = alg_add(alg_copy(alg_string("0123456789ABCDEF"), alg_mod(v_left, alg_int(16)), alg_int(1)), v_result)));
                (void)((v_left = alg_div_int(v_left, alg_int(16))));
            }
        }
        alg_root_top = rt_384;
    }
    Value ret_21 = v_result;
    alg_root_top = rt_base;
    return ret_21;
    Value ret_22 = alg_nil();
    alg_root_top = rt_base;
    return ret_22;
}

static Value m_cemitter_escaped_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    (void)((v_result = alg_buffer(alg_int(0))));
    {
        int32_t rt_385 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_name))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_386 = alg_root_top;
                Value v_c = alg_subscript_get(alg_str(v_name), v_i);
                (void)v_c;
                alg_root(&v_c, 1);
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
                alg_root_top = rt_386;
            }
        }
        alg_root_top = rt_385;
    }
    Value ret_23 = alg_property(v_result, "Text");
    alg_root_top = rt_base;
    return ret_23;
    Value ret_24 = alg_nil();
    alg_root_top = rt_base;
    return ret_24;
}

static Value m_cemitter_sanitize_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_text = alg_widen(args[0], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    Value v_result = alg_string("");
    (void)v_result;
    alg_root(&v_result, 1);
    {
        int32_t rt_387 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_text))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_388 = alg_root_top;
                Value v_c = alg_subscript_get(alg_str(v_text), v_i);
                (void)v_c;
                alg_root(&v_c, 1);
                if (alg_truthy((or_7 = (or_5 = ((or_3 = alg_greater_equal(v_c, alg_char_value(97)), !alg_truthy(or_3) ? or_3 : alg_less_equal(v_c, alg_char_value(122)))), alg_truthy(or_5) ? or_5 : ((or_4 = alg_greater_equal(v_c, alg_char_value(65)), !alg_truthy(or_4) ? or_4 : alg_less_equal(v_c, alg_char_value(90))))), alg_truthy(or_7) ? or_7 : ((or_6 = alg_greater_equal(v_c, alg_char_value(48)), !alg_truthy(or_6) ? or_6 : alg_less_equal(v_c, alg_char_value(57))))))) {
                    (void)((v_result = alg_add(v_result, alg_str(v_c))));
                } else {
                    (void)((v_result = alg_add(v_result, alg_char_value(95))));
                }
                alg_root_top = rt_388;
            }
        }
        alg_root_top = rt_387;
    }
    Value ret_25 = v_result;
    alg_root_top = rt_base;
    return ret_25;
    Value ret_26 = alg_nil();
    alg_root_top = rt_base;
    return ret_26;
}

static Value m_cemitter_collectunits_5_list_string_list_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_privates = alg_widen(args[2], "List");
    (void)v_privates;
    alg_root(&v_privates, 1);
    Value v_units = alg_widen(args[3], "List");
    (void)v_units;
    alg_root(&v_units, 1);
    Value v_filename = alg_widen(args[4], "String");
    (void)v_filename;
    alg_root(&v_filename, 1);
    Value v_own = alg_nil();
    (void)v_own;
    alg_root(&v_own, 1);
    Value v_imports = alg_nil();
    (void)v_imports;
    alg_root(&v_imports, 1);
    (void)((v_own = alg_list()));
    (void)((v_imports = alg_list()));
    {
        int32_t rt_389 = alg_root_top;
        Value loop_27 = alg_iterable(v_statements);
        (void)loop_27;
        alg_root(&loop_27, 1);
        for (int32_t at_27 = 0; at_27 < alg_iterable_count(loop_27); at_27++) {
            int32_t rt_390 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_27, at_27);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                if (alg_truthy(alg_is(v_thestmt, "ModuleStmt"))) {
                    {
                        int32_t rt_391 = alg_root_top;
                        Value v_modulename = alg_invoke(v_this, "UnitNameOf", (Value[]){alg_str(alg_property(v_thestmt, "FileName"))}, 1);
                        (void)v_modulename;
                        alg_root(&v_modulename, 1);
                        (void)(alg_invoke(v_imports, "Add", (Value[]){v_modulename}, 1));
                        if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Statements"), alg_nil()))) {
                            (void)(alg_invoke(v_this, "CollectUnits", (Value[]){alg_property(v_thestmt, "Statements"), v_modulename, alg_property(v_thestmt, "PrivateNames"), v_units, alg_str(alg_property(v_thestmt, "FileName"))}, 5));
                        }
                        alg_root_top = rt_391;
                    }
                }
                (void)(alg_invoke(v_own, "Add", (Value[]){v_thestmt}, 1));
            }
            alg_root_top = rt_390;
        }
        alg_root_top = rt_389;
    }
    (void)(alg_invoke(v_units, "Add", (Value[]){alg_new(k_emitunit, (Value[]){v_name, v_own, v_imports, v_privates, v_filename}, 5)}, 1));
    Value ret_28 = alg_nil();
    alg_root_top = rt_base;
    return ret_28;
}

static Value m_cemitter_unitnameof_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_key = alg_widen(args[0], "String");
    (void)v_key;
    alg_root(&v_key, 1);
    Value v_start = alg_nil();
    (void)v_start;
    alg_root(&v_start, 1);
    Value v_stem = alg_nil();
    (void)v_stem;
    alg_root(&v_stem, 1);
    (void)((v_start = alg_int(0)));
    {
        int32_t rt_392 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_key))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_equal(alg_subscript_get(v_key, v_i), alg_char_value(47)))) {
                (void)((v_start = alg_add(v_i, alg_int(1))));
            }
        }
        alg_root_top = rt_392;
    }
    (void)((v_stem = alg_copy(v_key, v_start, alg_subtract(alg_text_length(v_key), v_start))));
    if (alg_truthy(alg_greater(alg_text_length(v_stem), alg_int(4)))) {
        if (alg_truthy(alg_equal(alg_copy(v_stem, alg_subtract(alg_text_length(v_stem), alg_int(4)), alg_int(4)), alg_string(".a24")))) {
            (void)((v_stem = alg_copy(v_stem, alg_int(0), alg_subtract(alg_text_length(v_stem), alg_int(4)))));
        }
    }
    Value ret_29 = alg_invoke(v_this, "Sanitize", (Value[]){v_stem}, 1);
    alg_root_top = rt_base;
    return ret_29;
    Value ret_30 = alg_nil();
    alg_root_top = rt_base;
    return ret_30;
}

static Value m_cemitter_variablename_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_31 = alg_invoke(v_this, "Mangle", (Value[]){alg_string("v_"), v_name}, 2);
    alg_root_top = rt_base;
    return ret_31;
    Value ret_32 = alg_nil();
    alg_root_top = rt_base;
    return ret_32;
}

static Value m_cemitter_declaredflag_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_33 = alg_invoke(v_this, "Mangle", (Value[]){alg_string("d_"), v_name}, 2);
    alg_root_top = rt_base;
    return ret_33;
    Value ret_34 = alg_nil();
    alg_root_top = rt_base;
    return ret_34;
}

static Value m_cemitter_functionname_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_35 = alg_invoke(v_this, "Mangle", (Value[]){alg_string("f_"), v_name}, 2);
    alg_root_top = rt_base;
    return ret_35;
    Value ret_36 = alg_nil();
    alg_root_top = rt_base;
    return ret_36;
}

static Value m_cemitter_handlename_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_37 = alg_invoke(v_this, "Mangle", (Value[]){alg_string("fn_"), v_name}, 2);
    alg_root_top = rt_base;
    return ret_37;
    Value ret_38 = alg_nil();
    alg_root_top = rt_base;
    return ret_38;
}

static Value m_cemitter_setname_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_39 = alg_invoke(v_this, "Mangle", (Value[]){alg_string("o_"), v_name}, 2);
    alg_root_top = rt_base;
    return ret_39;
    Value ret_40 = alg_nil();
    alg_root_top = rt_base;
    return ret_40;
}

static Value m_cemitter_isoverloadset_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1))) {
        Value ret_41 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_41;
    }
    {
        int32_t rt_393 = alg_root_top;
        Value loop_42 = alg_iterable(alg_invoke(alg_property(v_this, "ImportedFrom"), "Keys", NULL, 0));
        (void)loop_42;
        alg_root(&loop_42, 1);
        for (int32_t at_42 = 0; at_42 < alg_iterable_count(loop_42); at_42++) {
            int32_t rt_394 = alg_root_top;
            Value v_key = alg_iterable_at(loop_42, at_42);
            (void)v_key;
            alg_root(&v_key, 1);
            {
                if (alg_truthy(alg_not_equal(f_foldcase(NULL, (Value[]){alg_str(v_key)}, 1), f_foldcase(NULL, (Value[]){v_name}, 1)))) {
                    continue;
                }
                Value ret_43 = alg_invoke(v_this, "OverloadedElsewhere", (Value[]){alg_str(alg_invoke(alg_property(v_this, "ImportedFrom"), "Get", (Value[]){v_key}, 1)), v_name}, 2);
                alg_root_top = rt_base;
                return ret_43;
            }
            alg_root_top = rt_394;
        }
        alg_root_top = rt_393;
    }
    Value ret_44 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_44;
    Value ret_45 = alg_nil();
    alg_root_top = rt_base;
    return ret_45;
}

static Value m_cemitter_subprogramvalue_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_invoke(v_this, "IsOverloadSet", (Value[]){v_name}, 1))) {
        Value ret_46 = alg_invoke(v_this, "SetName", (Value[]){v_name}, 1);
        alg_root_top = rt_base;
        return ret_46;
    }
    Value ret_47 = alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1);
    alg_root_top = rt_base;
    return ret_47;
    Value ret_48 = alg_nil();
    alg_root_top = rt_base;
    return ret_48;
}

static Value m_cemitter_functionsymbol_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    Value v_name = alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"));
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1)))) {
        (void)((v_symbol = alg_invoke(v_this, "FunctionName", (Value[]){v_name}, 1)));
    } else {
        {
            int32_t rt_395 = alg_root_top;
            (void)((v_symbol = alg_add(alg_add(alg_invoke(v_this, "FunctionName", (Value[]){v_name}, 1), alg_char_value(95)), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length")))));
            Value v_types = alg_invoke(v_this, "DeclaredTypes", (Value[]){v_thestmt}, 1);
            (void)v_types;
            alg_root(&v_types, 1);
            {
                int32_t rt_396 = alg_root_top;
                Value loop_49 = alg_iterable(v_types);
                (void)loop_49;
                alg_root(&loop_49, 1);
                for (int32_t at_49 = 0; at_49 < alg_iterable_count(loop_49); at_49++) {
                    int32_t rt_397 = alg_root_top;
                    Value v_thetype = alg_iterable_at(loop_49, at_49);
                    (void)v_thetype;
                    alg_root(&v_thetype, 1);
                    if (alg_truthy(alg_not_equal(v_thetype, alg_string("Any")))) {
                        (void)((v_symbol = alg_add(alg_add(v_symbol, alg_char_value(95)), alg_invoke(v_this, "Escaped", (Value[]){alg_str(v_thetype)}, 1))));
                    }
                    alg_root_top = rt_397;
                }
                alg_root_top = rt_396;
            }
            alg_root_top = rt_395;
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "NestedIn"), alg_string("")))) {
        (void)((v_symbol = alg_add(alg_add(v_symbol, alg_string("_in_")), alg_property(v_this, "NestedIn"))));
    }
    Value ret_50 = v_symbol;
    alg_root_top = rt_base;
    return ret_50;
    Value ret_51 = alg_nil();
    alg_root_top = rt_base;
    return ret_51;
}

static Value m_cemitter_prototype_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_lead = alg_nil();
    (void)v_lead;
    alg_root(&v_lead, 1);
    (void)((v_lead = alg_string("static Value ")));
    if (alg_truthy(alg_invoke(v_this, "Exported", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1))) {
        (void)((v_lead = alg_string("Value ")));
    }
    Value ret_52 = alg_add(alg_add(v_lead, alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1)), alg_string("(Value **cells, Value *args, int32_t count)"));
    alg_root_top = rt_base;
    return ret_52;
    Value ret_53 = alg_nil();
    alg_root_top = rt_base;
    return ret_53;
}

static Value m_cemitter_runswhentesting_1_stmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "Stmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value ret_54 = (or_14 = (or_13 = (or_12 = (or_11 = (or_10 = (or_9 = (or_8 = alg_is(v_thestmt, "FunctionStmt"), alg_truthy(or_8) ? or_8 : alg_is(v_thestmt, "ClassStmt")), alg_truthy(or_9) ? or_9 : alg_is(v_thestmt, "ObjectStmt")), alg_truthy(or_10) ? or_10 : alg_is(v_thestmt, "EnumStmt")), alg_truthy(or_11) ? or_11 : alg_is(v_thestmt, "VarGroupStmt")), alg_truthy(or_12) ? or_12 : alg_is(v_thestmt, "VarStmt")), alg_truthy(or_13) ? or_13 : alg_is(v_thestmt, "SubrangeStmt")), alg_truthy(or_14) ? or_14 : alg_is(v_thestmt, "ModuleStmt"));
    alg_root_top = rt_base;
    return ret_54;
    Value ret_55 = alg_nil();
    alg_root_top = rt_base;
    return ret_55;
}

static Value m_cemitter_exported_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_property(v_this, "RootUnit"))) {
        Value ret_56 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_56;
    }
    Value ret_57 = alg_not(alg_invoke(alg_property(v_this, "PrivateNames"), "Contains", (Value[]){v_name}, 1));
    alg_root_top = rt_base;
    return ret_57;
    Value ret_58 = alg_nil();
    alg_root_top = rt_base;
    return ret_58;
}

static Value m_cemitter_declarevalue_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_symbol = alg_widen(args[0], "String");
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    (void)(alg_invoke(alg_property(v_this, "RootSymbols"), "Add", (Value[]){v_symbol}, 1));
    if (alg_truthy(alg_invoke(v_this, "Exported", (Value[]){v_name}, 1))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), v_symbol), alg_char_value(59)), alg_char_value(10))}, 1));
            (void)(alg_set_property(v_this, "Header", alg_add(alg_add(alg_add(alg_add(alg_property(v_this, "Header"), alg_string("extern Value ")), v_symbol), alg_char_value(59)), alg_char_value(10))));
        }
    } else {
        (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_symbol), alg_char_value(59)), alg_char_value(10))}, 1));
    }
    Value ret_59 = alg_nil();
    alg_root_top = rt_base;
    return ret_59;
}

static Value m_cemitter_declarevariable_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_symbol = alg_widen(args[0], "String");
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){v_symbol, v_name}, 2));
    if (alg_truthy(alg_invoke(v_this, "Exported", (Value[]){v_name}, 1))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("bool "), alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)), alg_char_value(59)), alg_char_value(10))}, 1));
            (void)(alg_set_property(v_this, "Header", alg_add(alg_add(alg_add(alg_add(alg_property(v_this, "Header"), alg_string("extern bool ")), alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)), alg_char_value(59)), alg_char_value(10))));
        }
    } else {
        (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static bool "), alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)), alg_char_value(59)), alg_char_value(10))}, 1));
    }
    Value ret_60 = alg_nil();
    alg_root_top = rt_base;
    return ret_60;
}

static Value m_cemitter_istest_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value ret_61 = alg_not_equal(alg_property(alg_property(v_thestmt, "Name"), "Literal"), alg_nil());
    alg_root_top = rt_base;
    return ret_61;
    Value ret_62 = alg_nil();
    alg_root_top = rt_base;
    return ret_62;
}

static Value m_cemitter_collectfunctions_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    {
        int32_t rt_398 = alg_root_top;
        Value loop_63 = alg_iterable(v_statements);
        (void)loop_63;
        alg_root(&loop_63, 1);
        for (int32_t at_63 = 0; at_63 < alg_iterable_count(loop_63); at_63++) {
            int32_t rt_399 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_63, at_63);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                if (alg_truthy(alg_is(v_thestmt, "FunctionStmt"))) {
                    {
                        if (alg_truthy(alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1)))) {
                            {
                                (void)(alg_invoke(alg_property(v_this, "Declared"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                                (void)(alg_invoke(alg_property(v_this, "CollectingInto"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                                (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                            }
                        }
                        (void)(alg_invoke(v_this, "CollectFunctions", (Value[]){alg_property(v_thestmt, "Body")}, 1));
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "ClassStmt"))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Classes"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), v_thestmt}, 2));
                        (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "ObjectStmt"))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Objects"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1)}, 1));
                        (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "EnumStmt"))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "EnumTypes"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                        (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                        {
                            int32_t rt_400 = alg_root_top;
                            Value loop_64 = alg_iterable(alg_property(v_thestmt, "Members"));
                            (void)loop_64;
                            alg_root(&loop_64, 1);
                            for (int32_t at_64 = 0; at_64 < alg_iterable_count(loop_64); at_64++) {
                                int32_t rt_401 = alg_root_top;
                                Value v_themember = alg_iterable_at(loop_64, at_64);
                                (void)v_themember;
                                alg_root(&v_themember, 1);
                                {
                                    int32_t rt_402 = alg_root_top;
                                    Value v_member = alg_str(alg_property(v_themember, "Lexeme"));
                                    (void)v_member;
                                    alg_root(&v_member, 1);
                                    if (alg_truthy(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_member}, 1))) {
                                        if (alg_truthy(alg_not_equal(alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_member}, 1)), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))))) {
                                            (void)(alg_invoke(v_this, "MarkAmbiguousMember", (Value[]){v_member, alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_member}, 1)), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 3));
                                        }
                                    }
                                    (void)(alg_invoke(alg_property(v_this, "EnumMembers"), "Put", (Value[]){v_member, alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                                    (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){v_member}, 1), v_member}, 2));
                                    alg_root_top = rt_402;
                                }
                                alg_root_top = rt_401;
                            }
                            alg_root_top = rt_400;
                        }
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "BlockStmt"))) {
                    (void)(alg_invoke(v_this, "CollectFunctions", (Value[]){alg_property(v_thestmt, "Statements")}, 1));
                }
            }
            alg_root_top = rt_399;
        }
        alg_root_top = rt_398;
    }
    Value ret_65 = alg_nil();
    alg_root_top = rt_base;
    return ret_65;
}

static Value m_cemitter_collectglobals_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    {
        int32_t rt_403 = alg_root_top;
        Value loop_66 = alg_iterable(v_statements);
        (void)loop_66;
        alg_root(&loop_66, 1);
        for (int32_t at_66 = 0; at_66 < alg_iterable_count(loop_66); at_66++) {
            int32_t rt_404 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_66, at_66);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                if (alg_truthy(alg_is(v_thestmt, "VarStmt"))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Globals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                        (void)(alg_invoke(alg_property(v_this, "CollectingInto"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                        (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_thestmt, "Name"), "Lexeme")}, 1), alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                    {
                        int32_t rt_405 = alg_root_top;
                        Value loop_67 = alg_iterable(alg_property(v_thestmt, "Names"));
                        (void)loop_67;
                        alg_root(&loop_67, 1);
                        for (int32_t at_67 = 0; at_67 < alg_iterable_count(loop_67); at_67++) {
                            int32_t rt_406 = alg_root_top;
                            Value v_thename = alg_iterable_at(loop_67, at_67);
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            {
                                (void)(alg_invoke(alg_property(v_this, "Globals"), "Add", (Value[]){alg_str(alg_property(v_thename, "Lexeme"))}, 1));
                                (void)(alg_invoke(alg_property(v_this, "CollectingInto"), "Add", (Value[]){alg_str(alg_property(v_thename, "Lexeme"))}, 1));
                                (void)(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_property(v_thename, "Lexeme")}, 1), alg_str(alg_property(v_thename, "Lexeme"))}, 2));
                            }
                            alg_root_top = rt_406;
                        }
                        alg_root_top = rt_405;
                    }
                }
                if (alg_truthy((or_15 = alg_is(v_thestmt, "FunctionStmt"), !alg_truthy(or_15) ? or_15 : alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1))))) {
                    {
                        if (alg_truthy((or_17 = (or_16 = alg_invoke(alg_property(v_this, "TopLevel"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1), alg_truthy(or_16) ? or_16 : alg_invoke(v_this, "Variadic", (Value[]){v_thestmt}, 1)), alg_truthy(or_17) ? or_17 : alg_greater(alg_property(alg_invoke(v_this, "BuiltinCounts", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1), "Length"), alg_int(0))))) {
                            (void)(alg_invoke(alg_property(v_this, "Overloaded"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                        }
                        (void)(alg_invoke(alg_property(v_this, "TopLevel"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                    }
                }
            }
            alg_root_top = rt_404;
        }
        alg_root_top = rt_403;
    }
    Value ret_68 = alg_nil();
    alg_root_top = rt_base;
    return ret_68;
}

static Value m_cemitter_compilingfile_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    (void)(alg_set_property(v_this, "SourceFile", v_name));
    Value ret_69 = alg_nil();
    alg_root_top = rt_base;
    return ret_69;
}

static Value m_cemitter_withtests_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_set_property(v_this, "EmitTests", alg_bool(true)));
    Value ret_70 = alg_nil();
    alg_root_top = rt_base;
    return ret_70;
}

static Value m_cemitter_emit_2_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    Value v_stem = alg_widen(args[1], "String");
    (void)v_stem;
    alg_root(&v_stem, 1);
    Value v_units = alg_nil();
    (void)v_units;
    alg_root(&v_units, 1);
    Value v_files = alg_nil();
    (void)v_files;
    alg_root(&v_files, 1);
    Value v_mainbodytext = alg_nil();
    (void)v_mainbodytext;
    alg_root(&v_mainbodytext, 1);
    (void)((v_units = alg_list()));
    (void)((v_files = alg_map()));
    (void)((v_mainbodytext = alg_string("")));
    (void)(alg_invoke(v_this, "CollectUnits", (Value[]){v_statements, v_stem, alg_list(), v_units, alg_property(v_this, "SourceFile")}, 5));
    Value v_seen = alg_set();
    (void)v_seen;
    alg_root(&v_seen, 1);
    {
        int32_t rt_407 = alg_root_top;
        Value loop_71 = alg_iterable(v_units);
        (void)loop_71;
        alg_root(&loop_71, 1);
        for (int32_t at_71 = 0; at_71 < alg_iterable_count(loop_71); at_71++) {
            int32_t rt_408 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_71, at_71);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            {
                if (alg_truthy(alg_invoke(v_seen, "Contains", (Value[]){alg_str(alg_property(v_theunit, "Name"))}, 1))) {
                    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("Two modules named '"), alg_str(alg_property(v_theunit, "Name"))), alg_char_value(39))}, 1));
                }
                (void)(alg_invoke(v_seen, "Add", (Value[]){alg_str(alg_property(v_theunit, "Name"))}, 1));
            }
            alg_root_top = rt_408;
        }
        alg_root_top = rt_407;
    }
    {
        int32_t rt_409 = alg_root_top;
        Value loop_72 = alg_iterable(v_units);
        (void)loop_72;
        alg_root(&loop_72, 1);
        for (int32_t at_72 = 0; at_72 < alg_iterable_count(loop_72); at_72++) {
            int32_t rt_410 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_72, at_72);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            {
                (void)(alg_set_property(v_this, "CollectingInto", alg_set()));
                (void)(alg_invoke(v_this, "CollectFunctions", (Value[]){alg_property(v_theunit, "Statements")}, 1));
                (void)(alg_invoke(alg_property(v_this, "DeclaredIn"), "Put", (Value[]){alg_str(alg_property(v_theunit, "Name")), alg_property(v_this, "CollectingInto")}, 2));
            }
            alg_root_top = rt_410;
        }
        alg_root_top = rt_409;
    }
    {
        int32_t rt_411 = alg_root_top;
        Value loop_73 = alg_iterable(v_units);
        (void)loop_73;
        alg_root(&loop_73, 1);
        for (int32_t at_73 = 0; at_73 < alg_iterable_count(loop_73); at_73++) {
            int32_t rt_412 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_73, at_73);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            {
                (void)(alg_set_property(v_this, "TopLevel", alg_set()));
                (void)(alg_set_property(v_this, "Overloaded", alg_set()));
                (void)(alg_set_property(v_this, "CollectingInto", alg_set()));
                (void)(alg_invoke(v_this, "CollectGlobals", (Value[]){alg_property(v_theunit, "Statements")}, 1));
                (void)(alg_invoke(alg_property(v_this, "GlobalsIn"), "Put", (Value[]){alg_str(alg_property(v_theunit, "Name")), alg_property(v_this, "CollectingInto")}, 2));
                (void)(alg_invoke(alg_property(v_this, "OverloadsIn"), "Put", (Value[]){alg_str(alg_property(v_theunit, "Name")), alg_property(v_this, "Overloaded")}, 2));
            }
            alg_root_top = rt_412;
        }
        alg_root_top = rt_411;
    }
    (void)(alg_set_property(v_this, "CollectingInto", alg_set()));
    {
        int32_t rt_413 = alg_root_top;
        Value loop_74 = alg_iterable(v_units);
        (void)loop_74;
        alg_root(&loop_74, 1);
        for (int32_t at_74 = 0; at_74 < alg_iterable_count(loop_74); at_74++) {
            int32_t rt_414 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_74, at_74);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            {
                int32_t rt_415 = alg_root_top;
                Value v_exported = alg_set();
                (void)v_exported;
                alg_root(&v_exported, 1);
                Value v_own = alg_property(v_theunit, "Statements");
                (void)v_own;
                alg_root(&v_own, 1);
                {
                    int32_t rt_416 = alg_root_top;
                    Value v_i = alg_int(0);
                    (void)v_i;
                    alg_root(&v_i, 1);
                    for (; alg_truthy(alg_less(v_i, alg_property(v_own, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        {
                            int32_t rt_417 = alg_root_top;
                            Value v_thestmt = alg_subscript_get(v_own, v_i);
                            (void)v_thestmt;
                            alg_root(&v_thestmt, 1);
                            if (alg_truthy((or_18 = alg_is(v_thestmt, "FunctionStmt"), !alg_truthy(or_18) ? or_18 : alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1))))) {
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
                                        int32_t rt_418 = alg_root_top;
                                        Value loop_75 = alg_iterable(alg_property(v_thestmt, "Members"));
                                        (void)loop_75;
                                        alg_root(&loop_75, 1);
                                        for (int32_t at_75 = 0; at_75 < alg_iterable_count(loop_75); at_75++) {
                                            int32_t rt_419 = alg_root_top;
                                            Value v_member = alg_iterable_at(loop_75, at_75);
                                            (void)v_member;
                                            alg_root(&v_member, 1);
                                            (void)(alg_invoke(v_exported, "Add", (Value[]){alg_str(alg_property(v_member, "Lexeme"))}, 1));
                                            alg_root_top = rt_419;
                                        }
                                        alg_root_top = rt_418;
                                    }
                                }
                            }
                            if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                                {
                                    int32_t rt_420 = alg_root_top;
                                    Value loop_76 = alg_iterable(alg_property(v_thestmt, "Names"));
                                    (void)loop_76;
                                    alg_root(&loop_76, 1);
                                    for (int32_t at_76 = 0; at_76 < alg_iterable_count(loop_76); at_76++) {
                                        int32_t rt_421 = alg_root_top;
                                        Value v_eachname = alg_iterable_at(loop_76, at_76);
                                        (void)v_eachname;
                                        alg_root(&v_eachname, 1);
                                        (void)(alg_invoke(v_exported, "Add", (Value[]){alg_str(alg_property(v_eachname, "Lexeme"))}, 1));
                                        alg_root_top = rt_421;
                                    }
                                    alg_root_top = rt_420;
                                }
                            }
                            alg_root_top = rt_417;
                        }
                    }
                    alg_root_top = rt_416;
                }
                Value v_everything = alg_set();
                (void)v_everything;
                alg_root(&v_everything, 1);
                {
                    int32_t rt_422 = alg_root_top;
                    Value v_i = alg_int(0);
                    (void)v_i;
                    alg_root(&v_i, 1);
                    for (; alg_truthy(alg_less(v_i, alg_property(alg_invoke(v_exported, "ToList", NULL, 0), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        (void)(alg_invoke(v_everything, "Add", (Value[]){alg_subscript_get(alg_invoke(v_exported, "ToList", NULL, 0), v_i)}, 1));
                    }
                    alg_root_top = rt_422;
                }
                (void)(alg_invoke(alg_property(v_this, "UnitAll"), "Put", (Value[]){alg_str(alg_property(v_theunit, "Name")), v_everything}, 2));
                Value v_hidden = alg_property(v_theunit, "PrivateNames");
                (void)v_hidden;
                alg_root(&v_hidden, 1);
                {
                    int32_t rt_423 = alg_root_top;
                    Value v_i = alg_int(0);
                    (void)v_i;
                    alg_root(&v_i, 1);
                    for (; alg_truthy(alg_less(v_i, alg_property(v_hidden, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        (void)(alg_invoke(v_exported, "Remove", (Value[]){alg_str(alg_subscript_get(v_hidden, v_i))}, 1));
                    }
                    alg_root_top = rt_423;
                }
                (void)(alg_invoke(alg_property(v_this, "UnitExports"), "Put", (Value[]){alg_str(alg_property(v_theunit, "Name")), v_exported}, 2));
                alg_root_top = rt_415;
            }
            alg_root_top = rt_414;
        }
        alg_root_top = rt_413;
    }
    Value v_exportedby = alg_map();
    (void)v_exportedby;
    alg_root(&v_exportedby, 1);
    {
        int32_t rt_424 = alg_root_top;
        Value v_u = alg_int(0);
        (void)v_u;
        alg_root(&v_u, 1);
        for (; alg_truthy(alg_less(v_u, alg_subtract(alg_property(v_units, "Length"), alg_int(1)))); (v_u = alg_add(v_u, alg_int(1)))) {
            {
                int32_t rt_425 = alg_root_top;
                Value v_visible = alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){alg_str(alg_property(alg_subscript_get(v_units, v_u), "Name"))}, 1), "Set");
                (void)v_visible;
                alg_root(&v_visible, 1);
                Value v_names = alg_invoke(v_this, "ExportedNames", (Value[]){alg_subscript_get(v_units, v_u)}, 1);
                (void)v_names;
                alg_root(&v_names, 1);
                {
                    int32_t rt_426 = alg_root_top;
                    Value v_i = alg_int(0);
                    (void)v_i;
                    alg_root(&v_i, 1);
                    for (; alg_truthy(alg_less(v_i, alg_property(v_names, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        {
                            int32_t rt_427 = alg_root_top;
                            Value v_thename = alg_str(alg_subscript_get(v_names, v_i));
                            (void)v_thename;
                            alg_root(&v_thename, 1);
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
                            alg_root_top = rt_427;
                        }
                    }
                    alg_root_top = rt_426;
                }
                alg_root_top = rt_425;
            }
        }
        alg_root_top = rt_424;
    }
    {
        int32_t rt_428 = alg_root_top;
        Value v_u = alg_int(0);
        (void)v_u;
        alg_root(&v_u, 1);
        for (; alg_truthy(alg_less(v_u, alg_property(v_units, "Length"))); (v_u = alg_add(v_u, alg_int(1)))) {
            {
                int32_t rt_429 = alg_root_top;
                Value v_unit = alg_subscript_get(v_units, v_u);
                (void)v_unit;
                alg_root(&v_unit, 1);
                (void)(alg_set_property(v_this, "Declarations", alg_buffer(alg_int(0))));
                (void)(alg_set_property(v_this, "RootSymbols", alg_list()));
                (void)(alg_set_property(v_this, "Functions", alg_buffer(alg_int(0))));
                (void)(alg_set_property(v_this, "Setup", alg_buffer(alg_int(0))));
                (void)(alg_set_property(v_this, "Shells", alg_buffer(alg_int(0))));
                (void)(alg_set_property(v_this, "Overloaded", alg_cast(alg_invoke(alg_property(v_this, "OverloadsIn"), "Get", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1), "Set")));
                (void)(alg_set_property(v_this, "SetsBuilt", alg_set()));
                (void)(alg_set_property(v_this, "OwnClasses", alg_set()));
                {
                    int32_t rt_430 = alg_root_top;
                    Value loop_77 = alg_iterable(alg_property(v_unit, "Statements"));
                    (void)loop_77;
                    alg_root(&loop_77, 1);
                    for (int32_t at_77 = 0; at_77 < alg_iterable_count(loop_77); at_77++) {
                        int32_t rt_431 = alg_root_top;
                        Value v_statement = alg_iterable_at(loop_77, at_77);
                        (void)v_statement;
                        alg_root(&v_statement, 1);
                        if (alg_truthy((or_19 = alg_is(v_statement, "ClassStmt"), alg_truthy(or_19) ? or_19 : alg_is(v_statement, "ObjectStmt")))) {
                            (void)(alg_invoke(alg_property(v_this, "OwnClasses"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_statement, "Name"), "Lexeme")}, 1)}, 1));
                        }
                        alg_root_top = rt_431;
                    }
                    alg_root_top = rt_430;
                }
                (void)(alg_set_property(v_this, "MainBody", alg_buffer(alg_int(0))));
                (void)(alg_set_property(v_this, "Header", alg_string("")));
                (void)(alg_set_property(v_this, "Target", alg_string("main")));
                (void)(alg_set_property(v_this, "Logicals", alg_int(0)));
                (void)(alg_set_property(v_this, "Loops", alg_int(0)));
                (void)(alg_set_property(v_this, "UnitTests", alg_int(0)));
                Value v_ismain = alg_equal(v_u, alg_subtract(alg_property(v_units, "Length"), alg_int(1)));
                (void)v_ismain;
                alg_root(&v_ismain, 1);
                if (alg_truthy(v_ismain)) {
                    (void)(alg_invoke(v_this, "EmitSubranges", NULL, 0));
                }
                (void)(alg_set_property(v_this, "UnitName", alg_str(alg_property(v_unit, "Name"))));
                (void)(alg_set_property(v_this, "PrivateNames", alg_cast(alg_property(v_unit, "PrivateNames"), "List")));
                (void)(alg_set_property(v_this, "RootUnit", v_ismain));
                (void)(alg_set_property(v_this, "CurrentFile", alg_str(alg_property(v_unit, "FileName"))));
                (void)(alg_set_property(v_this, "Renames", alg_map()));
                Value v_visible = alg_set();
                (void)v_visible;
                alg_root(&v_visible, 1);
                Value v_importowner = alg_map();
                (void)v_importowner;
                alg_root(&v_importowner, 1);
                (void)(alg_set_property(v_this, "AmbiguousImports", alg_map()));
                {
                    int32_t rt_432 = alg_root_top;
                    Value loop_78 = alg_iterable(alg_property(v_unit, "Imports"));
                    (void)loop_78;
                    alg_root(&loop_78, 1);
                    for (int32_t at_78 = 0; at_78 < alg_iterable_count(loop_78); at_78++) {
                        int32_t rt_433 = alg_root_top;
                        Value v_import = alg_iterable_at(loop_78, at_78);
                        (void)v_import;
                        alg_root(&v_import, 1);
                        if (alg_truthy(alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){alg_str(v_import)}, 1))) {
                            {
                                int32_t rt_434 = alg_root_top;
                                Value v_from = alg_str(v_import);
                                (void)v_from;
                                alg_root(&v_from, 1);
                                Value v_seen = alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_from}, 1), "Set")), "ToList", NULL, 0);
                                (void)v_seen;
                                alg_root(&v_seen, 1);
                                {
                                    int32_t rt_435 = alg_root_top;
                                    Value v_j = alg_int(0);
                                    (void)v_j;
                                    alg_root(&v_j, 1);
                                    for (; alg_truthy(alg_less(v_j, alg_property(v_seen, "Length"))); (v_j = alg_add(v_j, alg_int(1)))) {
                                        {
                                            int32_t rt_436 = alg_root_top;
                                            Value v_thename = alg_str(alg_subscript_get(v_seen, v_j));
                                            (void)v_thename;
                                            alg_root(&v_thename, 1);
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
                                            alg_root_top = rt_436;
                                        }
                                    }
                                    alg_root_top = rt_435;
                                }
                                alg_root_top = rt_434;
                            }
                        }
                        alg_root_top = rt_433;
                    }
                    alg_root_top = rt_432;
                }
                if (alg_truthy(alg_invoke(alg_property(v_this, "UnitAll"), "Contains", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1))) {
                    {
                        int32_t rt_437 = alg_root_top;
                        Value v_declares = alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitAll"), "Get", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1), "Set")), "ToList", NULL, 0);
                        (void)v_declares;
                        alg_root(&v_declares, 1);
                        {
                            int32_t rt_438 = alg_root_top;
                            Value loop_79 = alg_iterable(v_declares);
                            (void)loop_79;
                            alg_root(&loop_79, 1);
                            for (int32_t at_79 = 0; at_79 < alg_iterable_count(loop_79); at_79++) {
                                int32_t rt_439 = alg_root_top;
                                Value v_declare = alg_iterable_at(loop_79, at_79);
                                (void)v_declare;
                                alg_root(&v_declare, 1);
                                (void)(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Remove", (Value[]){alg_str(v_declare)}, 1));
                                alg_root_top = rt_439;
                            }
                            alg_root_top = rt_438;
                        }
                        alg_root_top = rt_437;
                    }
                }
                Value v_mine = alg_invoke(v_this, "ExportedNames", (Value[]){v_unit}, 1);
                (void)v_mine;
                alg_root(&v_mine, 1);
                {
                    int32_t rt_440 = alg_root_top;
                    Value v_i = alg_int(0);
                    (void)v_i;
                    alg_root(&v_i, 1);
                    for (; alg_truthy(alg_less(v_i, alg_property(v_mine, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        {
                            int32_t rt_441 = alg_root_top;
                            Value v_thename = alg_str(alg_subscript_get(v_mine, v_i));
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            if (alg_truthy(alg_invoke(v_visible, "Contains", (Value[]){v_thename}, 1))) {
                                if (alg_truthy((or_20 = v_ismain, alg_truthy(or_20) ? or_20 : alg_invoke(alg_property(v_unit, "PrivateNames"), "Contains", (Value[]){v_thename}, 1)))) {
                                    (void)(alg_invoke(alg_property(v_this, "Renames"), "Put", (Value[]){v_thename, alg_str(alg_property(v_unit, "Name"))}, 2));
                                }
                            }
                            if (alg_truthy(alg_invoke(alg_property(v_this, "Renamed"), "Contains", (Value[]){v_thename}, 1))) {
                                if (alg_truthy(alg_not(alg_invoke(alg_property(v_unit, "PrivateNames"), "Contains", (Value[]){v_thename}, 1)))) {
                                    (void)(alg_invoke(alg_property(v_this, "Renames"), "Put", (Value[]){v_thename, alg_str(alg_property(v_unit, "Name"))}, 2));
                                }
                            }
                            alg_root_top = rt_441;
                        }
                    }
                    alg_root_top = rt_440;
                }
                (void)(alg_set_property(v_this, "ImportedFrom", v_importowner));
                Value v_reached = alg_invoke(v_importowner, "Keys", NULL, 0);
                (void)v_reached;
                alg_root(&v_reached, 1);
                {
                    int32_t rt_442 = alg_root_top;
                    Value v_i = alg_int(0);
                    (void)v_i;
                    alg_root(&v_i, 1);
                    for (; alg_truthy(alg_less(v_i, alg_property(v_reached, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        {
                            int32_t rt_443 = alg_root_top;
                            Value v_thename = alg_str(alg_subscript_get(v_reached, v_i));
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            if (alg_truthy((or_21 = alg_invoke(alg_property(v_this, "Renamed"), "Contains", (Value[]){v_thename}, 1), !alg_truthy(or_21) ? or_21 : alg_not(alg_invoke(alg_property(v_this, "Renames"), "Contains", (Value[]){v_thename}, 1))))) {
                                if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Contains", (Value[]){v_thename}, 1)))) {
                                    (void)(alg_invoke(alg_property(v_this, "Renames"), "Put", (Value[]){v_thename, alg_str(alg_invoke(v_importowner, "Get", (Value[]){v_thename}, 1))}, 2));
                                }
                            }
                            alg_root_top = rt_443;
                        }
                    }
                    alg_root_top = rt_442;
                }
                (void)(alg_set_property(v_this, "ShadowNames", alg_set()));
                if (alg_truthy(alg_invoke(alg_property(v_this, "UnitAll"), "Contains", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1))) {
                    {
                        int32_t rt_444 = alg_root_top;
                        Value v_own = alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitAll"), "Get", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1), "Set")), "ToList", NULL, 0);
                        (void)v_own;
                        alg_root(&v_own, 1);
                        {
                            int32_t rt_445 = alg_root_top;
                            Value v_i = alg_int(0);
                            (void)v_i;
                            alg_root(&v_i, 1);
                            for (; alg_truthy(alg_less(v_i, alg_property(v_own, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                                (void)(alg_invoke(alg_property(v_this, "ShadowNames"), "Add", (Value[]){alg_subscript_get(v_own, v_i)}, 1));
                            }
                            alg_root_top = rt_445;
                        }
                        alg_root_top = rt_444;
                    }
                }
                {
                    int32_t rt_446 = alg_root_top;
                    Value loop_80 = alg_iterable(alg_property(v_unit, "Imports"));
                    (void)loop_80;
                    alg_root(&loop_80, 1);
                    for (int32_t at_80 = 0; at_80 < alg_iterable_count(loop_80); at_80++) {
                        int32_t rt_447 = alg_root_top;
                        Value v_theimport = alg_iterable_at(loop_80, at_80);
                        (void)v_theimport;
                        alg_root(&v_theimport, 1);
                        if (alg_truthy(alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){alg_str(v_theimport)}, 1))) {
                            {
                                int32_t rt_448 = alg_root_top;
                                Value v_seen = alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){alg_str(v_theimport)}, 1), "Set")), "ToList", NULL, 0);
                                (void)v_seen;
                                alg_root(&v_seen, 1);
                                {
                                    int32_t rt_449 = alg_root_top;
                                    Value v_j = alg_int(0);
                                    (void)v_j;
                                    alg_root(&v_j, 1);
                                    for (; alg_truthy(alg_less(v_j, alg_property(v_seen, "Length"))); (v_j = alg_add(v_j, alg_int(1)))) {
                                        (void)(alg_invoke(alg_property(v_this, "ShadowNames"), "Add", (Value[]){alg_subscript_get(v_seen, v_j)}, 1));
                                    }
                                    alg_root_top = rt_449;
                                }
                                alg_root_top = rt_448;
                            }
                        }
                        alg_root_top = rt_447;
                    }
                    alg_root_top = rt_446;
                }
                (void)(alg_set_property(v_this, "VisibleDeclared", alg_set()));
                if (alg_truthy(alg_invoke(alg_property(v_this, "DeclaredIn"), "Contains", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1))) {
                    {
                        int32_t rt_450 = alg_root_top;
                        Value v_mine = alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "DeclaredIn"), "Get", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1), "Set")), "ToList", NULL, 0);
                        (void)v_mine;
                        alg_root(&v_mine, 1);
                        {
                            int32_t rt_451 = alg_root_top;
                            Value v_i = alg_int(0);
                            (void)v_i;
                            alg_root(&v_i, 1);
                            for (; alg_truthy(alg_less(v_i, alg_property(v_mine, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                                (void)(alg_invoke(alg_property(v_this, "VisibleDeclared"), "Add", (Value[]){alg_subscript_get(v_mine, v_i)}, 1));
                            }
                            alg_root_top = rt_451;
                        }
                        alg_root_top = rt_450;
                    }
                }
                {
                    int32_t rt_452 = alg_root_top;
                    Value loop_81 = alg_iterable(alg_property(v_unit, "Imports"));
                    (void)loop_81;
                    alg_root(&loop_81, 1);
                    for (int32_t at_81 = 0; at_81 < alg_iterable_count(loop_81); at_81++) {
                        int32_t rt_453 = alg_root_top;
                        Value v_theimport = alg_iterable_at(loop_81, at_81);
                        (void)v_theimport;
                        alg_root(&v_theimport, 1);
                        if (alg_truthy((or_22 = alg_invoke(alg_property(v_this, "DeclaredIn"), "Contains", (Value[]){alg_str(v_theimport)}, 1), !alg_truthy(or_22) ? or_22 : alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){alg_str(v_theimport)}, 1)))) {
                            {
                                int32_t rt_454 = alg_root_top;
                                Value v_theirs = alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "DeclaredIn"), "Get", (Value[]){alg_str(v_theimport)}, 1), "Set")), "ToList", NULL, 0);
                                (void)v_theirs;
                                alg_root(&v_theirs, 1);
                                Value v_shown = alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){alg_str(v_theimport)}, 1), "Set");
                                (void)v_shown;
                                alg_root(&v_shown, 1);
                                {
                                    int32_t rt_455 = alg_root_top;
                                    Value v_j = alg_int(0);
                                    (void)v_j;
                                    alg_root(&v_j, 1);
                                    for (; alg_truthy(alg_less(v_j, alg_property(v_theirs, "Length"))); (v_j = alg_add(v_j, alg_int(1)))) {
                                        if (alg_truthy(alg_invoke(v_shown, "Contains", (Value[]){alg_subscript_get(v_theirs, v_j)}, 1))) {
                                            (void)(alg_invoke(alg_property(v_this, "VisibleDeclared"), "Add", (Value[]){alg_subscript_get(v_theirs, v_j)}, 1));
                                        }
                                    }
                                    alg_root_top = rt_455;
                                }
                                alg_root_top = rt_454;
                            }
                        }
                        alg_root_top = rt_453;
                    }
                    alg_root_top = rt_452;
                }
                (void)(alg_set_property(v_this, "ShadowArities", alg_set()));
                (void)(alg_set_property(v_this, "ShadowWhole", alg_set()));
                (void)(alg_invoke(v_this, "CollectShadowArities", (Value[]){alg_property(v_unit, "Statements"), alg_list()}, 2));
                {
                    int32_t rt_456 = alg_root_top;
                    Value loop_82 = alg_iterable(alg_property(v_unit, "Imports"));
                    (void)loop_82;
                    alg_root(&loop_82, 1);
                    for (int32_t at_82 = 0; at_82 < alg_iterable_count(loop_82); at_82++) {
                        int32_t rt_457 = alg_root_top;
                        Value v_theimport = alg_iterable_at(loop_82, at_82);
                        (void)v_theimport;
                        alg_root(&v_theimport, 1);
                        {
                            int32_t rt_458 = alg_root_top;
                            Value loop_83 = alg_iterable(v_units);
                            (void)loop_83;
                            alg_root(&loop_83, 1);
                            for (int32_t at_83 = 0; at_83 < alg_iterable_count(loop_83); at_83++) {
                                int32_t rt_459 = alg_root_top;
                                Value v_other = alg_iterable_at(loop_83, at_83);
                                (void)v_other;
                                alg_root(&v_other, 1);
                                if (alg_truthy(alg_equal(alg_str(alg_property(v_other, "Name")), alg_str(v_theimport)))) {
                                    (void)(alg_invoke(v_this, "CollectShadowArities", (Value[]){alg_property(v_other, "Statements"), alg_property(v_other, "PrivateNames")}, 2));
                                }
                                alg_root_top = rt_459;
                            }
                            alg_root_top = rt_458;
                        }
                        alg_root_top = rt_457;
                    }
                    alg_root_top = rt_456;
                }
                {
                    int32_t rt_460 = alg_root_top;
                    Value loop_84 = alg_iterable(alg_property(v_unit, "Statements"));
                    (void)loop_84;
                    alg_root(&loop_84, 1);
                    for (int32_t at_84 = 0; at_84 < alg_iterable_count(loop_84); at_84++) {
                        int32_t rt_461 = alg_root_top;
                        Value v_thestmt = alg_iterable_at(loop_84, at_84);
                        (void)v_thestmt;
                        alg_root(&v_thestmt, 1);
                        {
                            if (alg_truthy((or_23 = alg_is(v_thestmt, "FunctionStmt"), !alg_truthy(or_23) ? or_23 : alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1))))) {
                                {
                                    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_invoke(v_this, "Prototype", (Value[]){v_thestmt}, 1), alg_char_value(59)), alg_char_value(10))}, 1));
                                    if (alg_truthy(alg_invoke(v_this, "Exported", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1))) {
                                        (void)(alg_set_property(v_this, "Header", alg_add(alg_add(alg_add(alg_property(v_this, "Header"), alg_invoke(v_this, "Prototype", (Value[]){v_thestmt}, 1)), alg_char_value(59)), alg_char_value(10))));
                                    }
                                }
                            }
                        }
                        alg_root_top = rt_461;
                    }
                    alg_root_top = rt_460;
                }
                (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(true)));
                (void)(alg_invoke(v_this, "PushLabels", (Value[]){alg_property(v_unit, "Statements")}, 1));
                {
                    int32_t rt_462 = alg_root_top;
                    Value loop_85 = alg_iterable(alg_property(v_unit, "Statements"));
                    (void)loop_85;
                    alg_root(&loop_85, 1);
                    for (int32_t at_85 = 0; at_85 < alg_iterable_count(loop_85); at_85++) {
                        int32_t rt_463 = alg_root_top;
                        Value v_thestmt = alg_iterable_at(loop_85, at_85);
                        (void)v_thestmt;
                        alg_root(&v_thestmt, 1);
                        {
                            if (alg_truthy((or_25 = alg_invoke(v_this, "RunsWhenTesting", (Value[]){v_thestmt}, 1), alg_truthy(or_25) ? or_25 : alg_not(((or_24 = alg_property(v_this, "EmitTests"), !alg_truthy(or_24) ? or_24 : v_ismain)))))) {
                                {
                                    if (alg_truthy(alg_is(v_thestmt, "BlockStmt"))) {
                                        {
                                            (void)(alg_set_property(v_this, "Volatiles", alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_thestmt, "Statements")}, 1)));
                                            (void)(alg_set_property(v_this, "Boxed", alg_invoke(v_this, "BoxesFor", (Value[]){alg_property(v_thestmt, "Statements")}, 1)));
                                            (void)(alg_set_property(v_this, "Cells", alg_list()));
                                            (void)(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1));
                                            (void)(alg_set_property(v_this, "Boxed", alg_list()));
                                            (void)(alg_set_property(v_this, "Cells", alg_list()));
                                            (void)(alg_set_property(v_this, "Volatiles", alg_bool(false)));
                                        }
                                    } else {
                                        (void)(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1));
                                    }
                                }
                            }
                        }
                        alg_root_top = rt_463;
                    }
                    alg_root_top = rt_462;
                }
                (void)(alg_invoke(v_this, "PopLabels", NULL, 0));
                (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
                if (alg_truthy(v_ismain)) {
                    {
                        int32_t rt_464 = alg_root_top;
                        Value v_initbody = alg_property(v_this, "MainBody");
                        (void)v_initbody;
                        alg_root(&v_initbody, 1);
                        (void)(alg_set_property(v_this, "MainBody", alg_buffer(alg_int(0))));
                        if (alg_truthy(alg_property(v_this, "EmitTests"))) {
                            (void)(alg_invoke(v_this, "EmitTestRunner", NULL, 0));
                        }
                        (void)((v_mainbodytext = alg_property(alg_property(v_this, "MainBody"), "Text")));
                        (void)(alg_set_property(v_this, "MainBody", v_initbody));
                        alg_root_top = rt_464;
                    }
                }
                (void)(alg_invoke(v_files, "Put", (Value[]){alg_add(alg_str(alg_property(v_unit, "Name")), alg_string(".h")), alg_invoke(v_this, "UnitHeader", (Value[]){v_unit}, 1)}, 2));
                (void)(alg_invoke(v_files, "Put", (Value[]){alg_add(alg_str(alg_property(v_unit, "Name")), alg_string(".c")), alg_invoke(v_this, "UnitSource", (Value[]){v_unit, v_units, v_ismain, v_mainbodytext}, 4)}, 2));
                alg_root_top = rt_429;
            }
        }
        alg_root_top = rt_428;
    }
    Value ret_86 = v_files;
    alg_root_top = rt_base;
    return ret_86;
    Value ret_87 = alg_nil();
    alg_root_top = rt_base;
    return ret_87;
}

static Value m_cemitter_unitheader_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_unit = args[0];
    (void)v_unit;
    alg_root(&v_unit, 1);
    Value v_guard = alg_nil();
    (void)v_guard;
    alg_root(&v_guard, 1);
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    (void)((v_guard = alg_add(alg_add(alg_string("ALG_"), alg_invoke(v_this, "Upper", (Value[]){alg_str(alg_property(v_unit, "Name"))}, 1)), alg_string("_H"))));
    (void)((v_text = alg_add(alg_string("/* Generated from Algol-24.  Do not edit. */"), alg_char_value(10))));
    (void)((v_text = alg_add(alg_add(alg_add(v_text, alg_string("#ifndef ")), v_guard), alg_char_value(10))));
    (void)((v_text = alg_add(alg_add(alg_add(alg_add(v_text, alg_string("#define ")), v_guard), alg_char_value(10)), alg_char_value(10))));
    (void)((v_text = alg_add(alg_add(alg_add(v_text, alg_string("#include \"algol.h\"")), alg_char_value(10)), alg_char_value(10))));
    (void)((v_text = alg_add(v_text, alg_property(v_this, "Header"))));
    (void)((v_text = alg_add(alg_add(alg_add(alg_add(v_text, alg_string("void init_")), alg_str(alg_property(v_unit, "Name"))), alg_string("(void);")), alg_char_value(10))));
    (void)((v_text = alg_add(alg_add(alg_add(v_text, alg_char_value(10)), alg_string("#endif")), alg_char_value(10))));
    Value ret_88 = v_text;
    alg_root_top = rt_base;
    return ret_88;
    Value ret_89 = alg_nil();
    alg_root_top = rt_base;
    return ret_89;
}

static Value m_cemitter_unitsource_4_list_boolean_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_unit = args[0];
    (void)v_unit;
    alg_root(&v_unit, 1);
    Value v_units = alg_widen(args[1], "List");
    (void)v_units;
    alg_root(&v_units, 1);
    Value v_ismain = alg_widen(args[2], "Boolean");
    (void)v_ismain;
    alg_root(&v_ismain, 1);
    Value v_written = alg_widen(args[3], "String");
    (void)v_written;
    alg_root(&v_written, 1);
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    (void)((v_text = alg_add(alg_string("/* Generated from Algol-24.  Do not edit. */"), alg_char_value(10))));
    (void)((v_text = alg_add(alg_add(alg_add(alg_add(v_text, alg_string("#include \"")), alg_str(alg_property(v_unit, "Name"))), alg_string(".h\"")), alg_char_value(10))));
    {
        int32_t rt_465 = alg_root_top;
        Value loop_90 = alg_iterable(alg_property(v_unit, "Imports"));
        (void)loop_90;
        alg_root(&loop_90, 1);
        for (int32_t at_90 = 0; at_90 < alg_iterable_count(loop_90); at_90++) {
            int32_t rt_466 = alg_root_top;
            Value v_import = alg_iterable_at(loop_90, at_90);
            (void)v_import;
            alg_root(&v_import, 1);
            (void)((v_text = alg_add(alg_add(alg_add(alg_add(v_text, alg_string("#include \"")), alg_str(v_import)), alg_string(".h\"")), alg_char_value(10))));
            alg_root_top = rt_466;
        }
        alg_root_top = rt_465;
    }
    (void)((v_text = alg_add(v_text, alg_char_value(10))));
    if (alg_truthy(alg_greater(alg_property(alg_property(v_this, "Declarations"), "Length"), alg_int(0)))) {
        (void)((v_text = alg_add(alg_add(v_text, alg_property(alg_property(v_this, "Declarations"), "Text")), alg_char_value(10))));
    }
    if (alg_truthy(alg_greater(alg_property(alg_property(v_this, "Functions"), "Length"), alg_int(0)))) {
        (void)((v_text = alg_add(v_text, alg_property(alg_property(v_this, "Functions"), "Text"))));
    }
    if (alg_truthy(alg_greater(alg_property(alg_property(v_this, "RootSymbols"), "Length"), alg_int(0)))) {
        {
            (void)((v_text = alg_add(alg_add(alg_add(alg_add(v_text, alg_string("static Value *roots_")), alg_str(alg_property(v_unit, "Name"))), alg_string("[] = {")), alg_char_value(10))));
            {
                int32_t rt_467 = alg_root_top;
                Value loop_91 = alg_iterable(alg_property(v_this, "RootSymbols"));
                (void)loop_91;
                alg_root(&loop_91, 1);
                for (int32_t at_91 = 0; at_91 < alg_iterable_count(loop_91); at_91++) {
                    int32_t rt_468 = alg_root_top;
                    Value v_each = alg_iterable_at(loop_91, at_91);
                    (void)v_each;
                    alg_root(&v_each, 1);
                    (void)((v_text = alg_add(alg_add(alg_add(alg_add(v_text, alg_string("    &")), alg_str(v_each)), alg_char_value(44)), alg_char_value(10))));
                    alg_root_top = rt_468;
                }
                alg_root_top = rt_467;
            }
            (void)((v_text = alg_add(alg_add(alg_add(v_text, alg_string("};")), alg_char_value(10)), alg_char_value(10))));
        }
    }
    (void)((v_text = alg_add(alg_add(alg_add(alg_add(v_text, alg_string("void init_")), alg_str(alg_property(v_unit, "Name"))), alg_string("(void) {")), alg_char_value(10))));
    if (alg_truthy(alg_greater(alg_property(alg_property(v_this, "RootSymbols"), "Length"), alg_int(0)))) {
        (void)((v_text = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(v_text, alg_string("    alg_roots(roots_")), alg_str(alg_property(v_unit, "Name"))), alg_string(", ")), alg_str(alg_property(alg_property(v_this, "RootSymbols"), "Length"))), alg_string(");")), alg_char_value(10))));
    }
    (void)((v_text = alg_add(v_text, alg_property(alg_property(v_this, "Shells"), "Text"))));
    (void)((v_text = alg_add(v_text, alg_property(alg_property(v_this, "Setup"), "Text"))));
    (void)((v_text = alg_add(v_text, alg_property(alg_property(v_this, "MainBody"), "Text"))));
    (void)((v_text = alg_add(alg_add(v_text, alg_char_value(125)), alg_char_value(10))));
    if (alg_truthy(v_ismain)) {
        {
            (void)((v_text = alg_add(alg_add(alg_add(v_text, alg_char_value(10)), alg_string("int main(int argc, char **argv) {")), alg_char_value(10))));
            (void)((v_text = alg_add(alg_add(v_text, alg_string("    alg_set_arguments(argc, argv);")), alg_char_value(10))));
            (void)((v_text = alg_add(alg_add(alg_add(alg_add(v_text, alg_string("    init_")), alg_str(alg_property(v_unit, "Name"))), alg_string("();")), alg_char_value(10))));
            (void)((v_text = alg_add(v_text, v_written)));
            (void)((v_text = alg_add(alg_add(alg_add(alg_add(v_text, alg_string("    return 0;")), alg_char_value(10)), alg_char_value(125)), alg_char_value(10))));
        }
    }
    Value ret_92 = v_text;
    alg_root_top = rt_base;
    return ret_92;
    Value ret_93 = alg_nil();
    alg_root_top = rt_base;
    return ret_93;
}

static Value m_cemitter_upper_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_text = alg_widen(args[0], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    (void)((v_result = alg_string("")));
    {
        int32_t rt_469 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_text))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_470 = alg_root_top;
                Value v_c = alg_subscript_get(v_text, v_i);
                (void)v_c;
                alg_root(&v_c, 1);
                if (alg_truthy(alg_greater_equal(v_c, alg_char_value(97)))) {
                    if (alg_truthy(alg_less_equal(v_c, alg_char_value(122)))) {
                        (void)((v_c = alg_char(alg_subtract(alg_ord(v_c), alg_int(32)))));
                    }
                }
                (void)((v_result = alg_add(v_result, v_c)));
                alg_root_top = rt_470;
            }
        }
        alg_root_top = rt_469;
    }
    Value ret_94 = v_result;
    alg_root_top = rt_base;
    return ret_94;
    Value ret_95 = alg_nil();
    alg_root_top = rt_base;
    return ret_95;
}

static Value m_cemitter_emittestrunner_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_files = alg_nil();
    (void)v_files;
    alg_root(&v_files, 1);
    {
        int32_t rt_471 = alg_root_top;
        Value loop_96 = alg_iterable(alg_property(v_this, "TestSymbols"));
        (void)loop_96;
        alg_root(&loop_96, 1);
        for (int32_t at_96 = 0; at_96 < alg_iterable_count(loop_96); at_96++) {
            int32_t rt_472 = alg_root_top;
            Value v_testsymbol = alg_iterable_at(loop_96, at_96);
            (void)v_testsymbol;
            alg_root(&v_testsymbol, 1);
            (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), alg_str(v_testsymbol)), alg_string("(Value **cells, Value *args, int32_t count);")), alg_char_value(10))}, 1));
            alg_root_top = rt_472;
        }
        alg_root_top = rt_471;
    }
    (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_test_begin("), alg_str(alg_property(alg_property(v_this, "Tests"), "Length"))), alg_string(", ")), f_quotec(NULL, (Value[]){alg_property(v_this, "SourceFile")}, 1)), alg_string(");")), alg_char_value(10))}, 1));
    (void)((v_files = alg_list()));
    {
        int32_t rt_473 = alg_root_top;
        Value loop_97 = alg_iterable(alg_property(v_this, "TestFiles"));
        (void)loop_97;
        alg_root(&loop_97, 1);
        for (int32_t at_97 = 0; at_97 < alg_iterable_count(loop_97); at_97++) {
            int32_t rt_474 = alg_root_top;
            Value v_testfile = alg_iterable_at(loop_97, at_97);
            (void)v_testfile;
            alg_root(&v_testfile, 1);
            if (alg_truthy(alg_not(alg_invoke(v_files, "Contains", (Value[]){v_testfile}, 1)))) {
                (void)(alg_invoke(v_files, "Add", (Value[]){v_testfile}, 1));
            }
            alg_root_top = rt_474;
        }
        alg_root_top = rt_473;
    }
    {
        int32_t rt_475 = alg_root_top;
        Value loop_98 = alg_iterable(v_files);
        (void)loop_98;
        alg_root(&loop_98, 1);
        for (int32_t at_98 = 0; at_98 < alg_iterable_count(loop_98); at_98++) {
            int32_t rt_476 = alg_root_top;
            Value v_file = alg_iterable_at(loop_98, at_98);
            (void)v_file;
            alg_root(&v_file, 1);
            {
                int32_t rt_477 = alg_root_top;
                (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("    alg_test_file("), f_quotec(NULL, (Value[]){alg_str(v_file)}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                Value v_ordered = alg_list();
                (void)v_ordered;
                alg_root(&v_ordered, 1);
                {
                    int32_t rt_478 = alg_root_top;
                    Value v_i = alg_int(0);
                    (void)v_i;
                    alg_root(&v_i, 1);
                    for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_this, "Tests"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                        if (alg_truthy(alg_equal(alg_subscript_get(alg_property(v_this, "TestFiles"), v_i), v_file))) {
                            (void)(alg_invoke(v_ordered, "Add", (Value[]){v_i}, 1));
                        }
                    }
                    alg_root_top = rt_478;
                }
                {
                    int32_t rt_479 = alg_root_top;
                    Value v_a = alg_int(0);
                    (void)v_a;
                    alg_root(&v_a, 1);
                    for (; alg_truthy(alg_less(v_a, alg_property(v_ordered, "Length"))); (v_a = alg_add(v_a, alg_int(1)))) {
                        {
                            int32_t rt_480 = alg_root_top;
                            Value v_b = alg_add(v_a, alg_int(1));
                            (void)v_b;
                            alg_root(&v_b, 1);
                            for (; alg_truthy(alg_less(v_b, alg_property(v_ordered, "Length"))); (v_b = alg_add(v_b, alg_int(1)))) {
                                if (alg_truthy(alg_less(alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_this, "Tests"), alg_subscript_get(v_ordered, v_b)), "Name"), "Lexeme")), alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_this, "Tests"), alg_subscript_get(v_ordered, v_a)), "Name"), "Lexeme"))))) {
                                    {
                                        int32_t rt_481 = alg_root_top;
                                        Value v_swap = alg_subscript_get(v_ordered, v_a);
                                        (void)v_swap;
                                        alg_root(&v_swap, 1);
                                        (void)(alg_subscript_set(v_ordered, v_a, alg_subscript_get(v_ordered, v_b)));
                                        (void)(alg_subscript_set(v_ordered, v_b, v_swap));
                                        alg_root_top = rt_481;
                                    }
                                }
                            }
                            alg_root_top = rt_480;
                        }
                    }
                    alg_root_top = rt_479;
                }
                {
                    int32_t rt_482 = alg_root_top;
                    Value loop_99 = alg_iterable(v_ordered);
                    (void)loop_99;
                    alg_root(&loop_99, 1);
                    for (int32_t at_99 = 0; at_99 < alg_iterable_count(loop_99); at_99++) {
                        int32_t rt_483 = alg_root_top;
                        Value v_each = alg_iterable_at(loop_99, at_99);
                        (void)v_each;
                        alg_root(&v_each, 1);
                        (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_test_run("), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(alg_subscript_get(alg_property(v_this, "Tests"), v_each), "Name"), "Literal"))}, 1)), alg_string(", ")), alg_str(alg_subscript_get(alg_property(v_this, "TestSymbols"), v_each))), alg_string(");")), alg_char_value(10))}, 1));
                        alg_root_top = rt_483;
                    }
                    alg_root_top = rt_482;
                }
                (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_string("    alg_test_end_file();"), alg_char_value(10))}, 1));
                alg_root_top = rt_477;
            }
            alg_root_top = rt_476;
        }
        alg_root_top = rt_475;
    }
    (void)(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_add(alg_string("    return alg_test_summary();"), alg_char_value(10))}, 1));
    Value ret_100 = alg_nil();
    alg_root_top = rt_base;
    return ret_100;
}

static Value m_cemitter_execute_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    (void)(alg_invoke(v_thestmt, "Accept", (Value[]){v_this}, 1));
    Value ret_101 = alg_nil();
    alg_root_top = rt_base;
    return ret_101;
}

static Value m_cemitter_evaluate_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = args[0];
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    (void)((v_text = alg_cast(alg_invoke(v_theexpr, "Accept", (Value[]){v_this}, 1), "String")));
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Cast"), alg_string("")))) {
        Value ret_102 = alg_add(alg_add(alg_add(alg_add(alg_string("alg_cast("), v_text), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(v_theexpr, "Cast"))}, 1)), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_102;
    }
    Value ret_103 = v_text;
    alg_root_top = rt_base;
    return ret_103;
    Value ret_104 = alg_nil();
    alg_root_top = rt_base;
    return ret_104;
}

static Value m_cemitter_emittest_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    (void)((v_symbol = alg_add(alg_add(alg_add(alg_string("t_"), alg_property(v_this, "UnitName")), alg_char_value(95)), alg_str(alg_property(v_this, "UnitTests")))));
    (void)(alg_set_property(v_this, "UnitTests", alg_add(alg_property(v_this, "UnitTests"), alg_int(1))));
    (void)(alg_invoke(alg_property(v_this, "Tests"), "Add", (Value[]){v_thestmt}, 1));
    (void)(alg_invoke(alg_property(v_this, "TestFiles"), "Add", (Value[]){alg_property(v_this, "CurrentFile")}, 1));
    (void)(alg_invoke(alg_property(v_this, "TestSymbols"), "Add", (Value[]){v_symbol}, 1));
    Value v_enclosingtarget = alg_property(v_this, "Target");
    (void)v_enclosingtarget;
    alg_root(&v_enclosingtarget, 1);
    Value v_enclosingbody = alg_property(v_this, "Body");
    (void)v_enclosingbody;
    alg_root(&v_enclosingbody, 1);
    Value v_enclosinglocals = alg_property(v_this, "Locals");
    (void)v_enclosinglocals;
    alg_root(&v_enclosinglocals, 1);
    Value v_enclosingtop = alg_property(v_this, "AtTopLevel");
    (void)v_enclosingtop;
    alg_root(&v_enclosingtop, 1);
    Value v_enclosingvolatiles = alg_property(v_this, "Volatiles");
    (void)v_enclosingvolatiles;
    alg_root(&v_enclosingvolatiles, 1);
    Value v_enclosingdepth = alg_property(v_this, "Depth");
    (void)v_enclosingdepth;
    alg_root(&v_enclosingdepth, 1);
    Value v_enclosingboxed = alg_property(v_this, "Boxed");
    (void)v_enclosingboxed;
    alg_root(&v_enclosingboxed, 1);
    Value v_enclosingcaptured = alg_property(v_this, "Captured");
    (void)v_enclosingcaptured;
    alg_root(&v_enclosingcaptured, 1);
    Value v_enclosingcells = alg_property(v_this, "Cells");
    (void)v_enclosingcells;
    alg_root(&v_enclosingcells, 1);
    (void)(alg_set_property(v_this, "Target", alg_string("body")));
    (void)(alg_set_property(v_this, "Body", alg_buffer(alg_int(0))));
    (void)(alg_set_property(v_this, "Depth", alg_int(1)));
    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
    (void)(alg_set_property(v_this, "Volatiles", alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_thestmt, "Body")}, 1)));
    (void)(alg_set_property(v_this, "Boxed", alg_invoke(v_this, "BoxesFor", (Value[]){alg_property(v_thestmt, "Body")}, 1)));
    (void)(alg_set_property(v_this, "Captured", alg_map()));
    (void)(alg_set_property(v_this, "Cells", alg_list()));
    (void)(alg_set_property(v_this, "Locals", alg_list()));
    Value v_enclosingtrydepth = alg_property(v_this, "TryDepth");
    (void)v_enclosingtrydepth;
    alg_root(&v_enclosingtrydepth, 1);
    Value v_enclosinglooptry = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosinglooptry;
    alg_root(&v_enclosinglooptry, 1);
    (void)(alg_set_property(v_this, "TryDepth", alg_int(0)));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_int(0)));
    (void)(alg_invoke(v_this, "HoistCells", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    (void)(alg_invoke(v_this, "PushLabels", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    {
        int32_t rt_484 = alg_root_top;
        Value loop_105 = alg_iterable(alg_property(v_thestmt, "Body"));
        (void)loop_105;
        alg_root(&loop_105, 1);
        for (int32_t at_105 = 0; at_105 < alg_iterable_count(loop_105); at_105++) {
            int32_t rt_485 = alg_root_top;
            Value v_each = alg_iterable_at(loop_105, at_105);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_invoke(v_this, "Execute", (Value[]){v_each}, 1));
            alg_root_top = rt_485;
        }
        alg_root_top = rt_484;
    }
    (void)(alg_invoke(v_this, "PopLabels", NULL, 0));
    Value v_written = alg_property(alg_property(v_this, "Body"), "Text");
    (void)v_written;
    alg_root(&v_written, 1);
    (void)(alg_set_property(v_this, "Target", v_enclosingtarget));
    (void)(alg_set_property(v_this, "Body", v_enclosingbody));
    (void)(alg_set_property(v_this, "Locals", v_enclosinglocals));
    (void)(alg_set_property(v_this, "AtTopLevel", v_enclosingtop));
    (void)(alg_set_property(v_this, "Volatiles", v_enclosingvolatiles));
    (void)(alg_set_property(v_this, "Depth", v_enclosingdepth));
    (void)(alg_set_property(v_this, "Boxed", v_enclosingboxed));
    (void)(alg_set_property(v_this, "Captured", v_enclosingcaptured));
    (void)(alg_set_property(v_this, "Cells", v_enclosingcells));
    (void)(alg_set_property(v_this, "TryDepth", v_enclosingtrydepth));
    (void)(alg_set_property(v_this, "LoopTryDepth", v_enclosinglooptry));
    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), v_symbol), alg_string("(Value **cells, Value *args, int32_t count);")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), v_symbol), alg_string("(Value **cells, Value *args, int32_t count) {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)cells; (void)args; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_written}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("    return alg_nil();"), alg_char_value(10)), alg_char_value(125)), alg_char_value(10)), alg_char_value(10))}, 1));
    Value ret_106 = alg_nil();
    alg_root_top = rt_base;
    return ret_106;
}

static Value m_cemitter_refusebarebinding_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_body = args[0];
    (void)v_body;
    alg_root(&v_body, 1);
    if (alg_truthy((or_26 = alg_is(v_body, "VarStmt"), alg_truthy(or_26) ? or_26 : alg_is(v_body, "VarGroupStmt")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("A 'var' as an unbraced branch or loop body")}, 1));
    }
    Value ret_107 = alg_nil();
    alg_root_top = rt_base;
    return ret_107;
}

static Value m_cemitter_declaresnested_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    {
        int32_t rt_486 = alg_root_top;
        Value loop_108 = alg_iterable(v_statements);
        (void)loop_108;
        alg_root(&loop_108, 1);
        for (int32_t at_108 = 0; at_108 < alg_iterable_count(loop_108); at_108++) {
            int32_t rt_487 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_108, at_108);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                if (alg_truthy(alg_is(v_thestmt, "FunctionStmt"))) {
                    Value ret_109 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_109;
                }
                if (alg_truthy((or_27 = alg_is(v_thestmt, "BlockStmt"), !alg_truthy(or_27) ? or_27 : alg_invoke(v_this, "DeclaresNested", (Value[]){alg_property(v_thestmt, "Statements")}, 1)))) {
                    Value ret_110 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_110;
                }
                if (alg_truthy((or_28 = alg_is(v_thestmt, "WhileStmt"), !alg_truthy(or_28) ? or_28 : alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "Body"))}, 1)))) {
                    Value ret_111 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_111;
                }
                if (alg_truthy((or_29 = alg_is(v_thestmt, "ForInStmt"), !alg_truthy(or_29) ? or_29 : alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "Body"))}, 1)))) {
                    Value ret_112 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_112;
                }
                if (alg_truthy(alg_is(v_thestmt, "IfStmt"))) {
                    {
                        if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "ThenBranch"))}, 1))) {
                            Value ret_113 = alg_bool(true);
                            alg_root_top = rt_base;
                            return ret_113;
                        }
                        if (alg_truthy((or_30 = alg_not_equal(alg_property(v_thestmt, "ElseBranch"), alg_nil()), !alg_truthy(or_30) ? or_30 : alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "ElseBranch"))}, 1)))) {
                            Value ret_114 = alg_bool(true);
                            alg_root_top = rt_base;
                            return ret_114;
                        }
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "TryStmt"))) {
                    {
                        int32_t rt_488 = alg_root_top;
                        if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "TryBlock"))}, 1))) {
                            Value ret_115 = alg_bool(true);
                            alg_root_top = rt_base;
                            return ret_115;
                        }
                        Value v_handlers = alg_invoke(alg_property(v_thestmt, "Handlers"), "Values", NULL, 0);
                        (void)v_handlers;
                        alg_root(&v_handlers, 1);
                        {
                            int32_t rt_489 = alg_root_top;
                            Value loop_116 = alg_iterable(v_handlers);
                            (void)loop_116;
                            alg_root(&loop_116, 1);
                            for (int32_t at_116 = 0; at_116 < alg_iterable_count(loop_116); at_116++) {
                                int32_t rt_490 = alg_root_top;
                                Value v_handler = alg_iterable_at(loop_116, at_116);
                                (void)v_handler;
                                alg_root(&v_handler, 1);
                                if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_list_keep(alg_list(), alg_property(v_handler, "Body"))}, 1))) {
                                    Value ret_117 = alg_bool(true);
                                    alg_root_top = rt_base;
                                    return ret_117;
                                }
                                alg_root_top = rt_490;
                            }
                            alg_root_top = rt_489;
                        }
                        alg_root_top = rt_488;
                    }
                }
            }
            alg_root_top = rt_487;
        }
        alg_root_top = rt_486;
    }
    Value ret_118 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_118;
    Value ret_119 = alg_nil();
    alg_root_top = rt_base;
    return ret_119;
}

static Value m_cemitter_addonce_2_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_names = alg_widen(args[0], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_not(alg_invoke(v_names, "Contains", (Value[]){v_name}, 1)))) {
        (void)(alg_invoke(v_names, "Add", (Value[]){v_name}, 1));
    }
    Value ret_120 = alg_nil();
    alg_root_top = rt_base;
    return ret_120;
}

static Value m_cemitter_collectbindings_2_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    Value v_names = alg_widen(args[1], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    {
        int32_t rt_491 = alg_root_top;
        Value loop_121 = alg_iterable(v_statements);
        (void)loop_121;
        alg_root(&loop_121, 1);
        for (int32_t at_121 = 0; at_121 < alg_iterable_count(loop_121); at_121++) {
            int32_t rt_492 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_121, at_121);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                if (alg_truthy(alg_is(v_thestmt, "VarStmt"))) {
                    (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
                }
                if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                    {
                        int32_t rt_493 = alg_root_top;
                        Value loop_122 = alg_iterable(alg_property(v_thestmt, "Names"));
                        (void)loop_122;
                        alg_root(&loop_122, 1);
                        for (int32_t at_122 = 0; at_122 < alg_iterable_count(loop_122); at_122++) {
                            int32_t rt_494 = alg_root_top;
                            Value v_thename = alg_iterable_at(loop_122, at_122);
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_str(alg_property(v_thename, "Lexeme"))}, 2));
                            alg_root_top = rt_494;
                        }
                        alg_root_top = rt_493;
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
                        int32_t rt_495 = alg_root_top;
                        (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "TryBlock")), v_names}, 2));
                        Value v_handlers = alg_invoke(alg_property(v_thestmt, "Handlers"), "Values", NULL, 0);
                        (void)v_handlers;
                        alg_root(&v_handlers, 1);
                        {
                            int32_t rt_496 = alg_root_top;
                            Value loop_123 = alg_iterable(v_handlers);
                            (void)loop_123;
                            alg_root(&loop_123, 1);
                            for (int32_t at_123 = 0; at_123 < alg_iterable_count(loop_123); at_123++) {
                                int32_t rt_497 = alg_root_top;
                                Value v_handler = alg_iterable_at(loop_123, at_123);
                                (void)v_handler;
                                alg_root(&v_handler, 1);
                                {
                                    (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_str(alg_property(v_handler, "Name"))}, 2));
                                    (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_list_keep(alg_list(), alg_property(v_handler, "Body")), v_names}, 2));
                                }
                                alg_root_top = rt_497;
                            }
                            alg_root_top = rt_496;
                        }
                        alg_root_top = rt_495;
                    }
                }
            }
            alg_root_top = rt_492;
        }
        alg_root_top = rt_491;
    }
    Value ret_124 = alg_nil();
    alg_root_top = rt_base;
    return ret_124;
}

static Value m_cemitter_boundnames_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    (void)((v_names = alg_list()));
    {
        int32_t rt_498 = alg_root_top;
        Value loop_125 = alg_iterable(alg_property(v_thestmt, "Params"));
        (void)loop_125;
        alg_root(&loop_125, 1);
        for (int32_t at_125 = 0; at_125 < alg_iterable_count(loop_125); at_125++) {
            int32_t rt_499 = alg_root_top;
            Value v_param = alg_iterable_at(loop_125, at_125);
            (void)v_param;
            alg_root(&v_param, 1);
            (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_str(alg_property(v_param, "Lexeme"))}, 2));
            alg_root_top = rt_499;
        }
        alg_root_top = rt_498;
    }
    (void)(alg_invoke(v_this, "CollectBindings", (Value[]){alg_property(v_thestmt, "Body"), v_names}, 2));
    Value ret_126 = v_names;
    alg_root_top = rt_base;
    return ret_126;
    Value ret_127 = alg_nil();
    alg_root_top = rt_base;
    return ret_127;
}

static Value m_cemitter_boxesfor_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_body = alg_widen(args[0], "List");
    (void)v_body;
    alg_root(&v_body, 1);
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    (void)((v_names = alg_list()));
    if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){v_body}, 1))) {
        (void)(alg_invoke(v_this, "CollectBindings", (Value[]){v_body, v_names}, 2));
    }
    Value ret_128 = v_names;
    alg_root_top = rt_base;
    return ret_128;
    Value ret_129 = alg_nil();
    alg_root_top = rt_base;
    return ret_129;
}

static Value m_cemitter_cell_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_130 = alg_invoke(v_this, "Mangle", (Value[]){alg_string("c_"), v_name}, 2);
    alg_root_top = rt_base;
    return ret_130;
    Value ret_131 = alg_nil();
    alg_root_top = rt_base;
    return ret_131;
}

static Value m_cemitter_thisref_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){alg_string("this")}, 1))) {
        Value ret_132 = alg_invoke(v_this, "Read", (Value[]){alg_string("this")}, 1);
        alg_root_top = rt_base;
        return ret_132;
    }
    Value ret_133 = alg_string("v_this");
    alg_root_top = rt_base;
    return ret_133;
    Value ret_134 = alg_nil();
    alg_root_top = rt_base;
    return ret_134;
}

static Value m_cemitter_cellpointer_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1))) {
        Value ret_135 = alg_add(alg_add(alg_string("cells["), alg_str(alg_invoke(alg_property(v_this, "Captured"), "Get", (Value[]){v_name}, 1))), alg_char_value(93));
        alg_root_top = rt_base;
        return ret_135;
    }
    Value ret_136 = alg_invoke(v_this, "Cell", (Value[]){v_name}, 1);
    alg_root_top = rt_base;
    return ret_136;
    Value ret_137 = alg_nil();
    alg_root_top = rt_base;
    return ret_137;
}

static Value m_cemitter_visiblecells_2_map_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_given = alg_widen(args[0], "Map");
    (void)v_given;
    alg_root(&v_given, 1);
    Value v_own = alg_widen(args[1], "List");
    (void)v_own;
    alg_root(&v_own, 1);
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    (void)((v_names = alg_invoke(v_given, "Keys", NULL, 0)));
    {
        int32_t rt_500 = alg_root_top;
        Value loop_138 = alg_iterable(v_own);
        (void)loop_138;
        alg_root(&loop_138, 1);
        for (int32_t at_138 = 0; at_138 < alg_iterable_count(loop_138); at_138++) {
            int32_t rt_501 = alg_root_top;
            Value v_each = alg_iterable_at(loop_138, at_138);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_str(v_each)}, 2));
            alg_root_top = rt_501;
        }
        alg_root_top = rt_500;
    }
    Value ret_139 = v_names;
    alg_root_top = rt_base;
    return ret_139;
    Value ret_140 = alg_nil();
    alg_root_top = rt_base;
    return ret_140;
}

static Value m_cemitter_read_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1))) {
        Value ret_141 = alg_add(alg_add(alg_string("(*cells["), alg_str(alg_invoke(alg_property(v_this, "Captured"), "Get", (Value[]){v_name}, 1))), alg_string("])"));
        alg_root_top = rt_base;
        return ret_141;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1))) {
        Value ret_142 = alg_add(alg_add(alg_string("(*"), alg_invoke(v_this, "Cell", (Value[]){v_name}, 1)), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_142;
    }
    Value ret_143 = alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)}, 2);
    alg_root_top = rt_base;
    return ret_143;
    Value ret_144 = alg_nil();
    alg_root_top = rt_base;
    return ret_144;
}

static Value m_cemitter_closureof_2_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_cells = alg_widen(args[1], "List");
    (void)v_cells;
    alg_root(&v_cells, 1);
    Value v_array = alg_nil();
    (void)v_array;
    alg_root(&v_array, 1);
    (void)((v_array = alg_string("NULL, 0")));
    if (alg_truthy(alg_greater(alg_property(v_cells, "Length"), alg_int(0)))) {
        {
            int32_t rt_502 = alg_root_top;
            Value v_joined = alg_string("");
            (void)v_joined;
            alg_root(&v_joined, 1);
            {
                int32_t rt_503 = alg_root_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less(v_i, alg_property(v_cells, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                            (void)((v_joined = alg_add(v_joined, alg_string(", "))));
                        }
                        (void)((v_joined = alg_add(v_joined, alg_invoke(v_this, "CellPointer", (Value[]){alg_str(alg_subscript_get(v_cells, v_i))}, 1))));
                    }
                }
                alg_root_top = rt_503;
            }
            (void)((v_array = alg_add(alg_add(alg_add(alg_string("(Value*[]){"), v_joined), alg_string("}, ")), alg_str(alg_property(v_cells, "Length")))));
            alg_root_top = rt_502;
        }
    }
    Value ret_145 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_closure("), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1)), alg_string(", ")), v_array), alg_string(", ")), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), alg_string(", ")), alg_invoke(v_this, "TypeTable", (Value[]){alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1), alg_invoke(v_this, "ParameterTable", (Value[]){v_thestmt}, 1)}, 2)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_145;
    Value ret_146 = alg_nil();
    alg_root_top = rt_base;
    return ret_146;
}

static Value m_cemitter_containstry_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    {
        int32_t rt_504 = alg_root_top;
        Value loop_147 = alg_iterable(v_statements);
        (void)loop_147;
        alg_root(&loop_147, 1);
        for (int32_t at_147 = 0; at_147 < alg_iterable_count(loop_147); at_147++) {
            int32_t rt_505 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_147, at_147);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                if (alg_truthy(alg_is(v_thestmt, "TryStmt"))) {
                    Value ret_148 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_148;
                }
                if (alg_truthy((or_31 = alg_is(v_thestmt, "BlockStmt"), !alg_truthy(or_31) ? or_31 : alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_thestmt, "Statements")}, 1)))) {
                    Value ret_149 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_149;
                }
                if (alg_truthy((or_32 = alg_is(v_thestmt, "WhileStmt"), !alg_truthy(or_32) ? or_32 : alg_invoke(v_this, "ContainsTry", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "Body"))}, 1)))) {
                    Value ret_150 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_150;
                }
                if (alg_truthy((or_33 = alg_is(v_thestmt, "ForInStmt"), !alg_truthy(or_33) ? or_33 : alg_invoke(v_this, "ContainsTry", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "Body"))}, 1)))) {
                    Value ret_151 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_151;
                }
                if (alg_truthy(alg_is(v_thestmt, "IfStmt"))) {
                    {
                        if (alg_truthy(alg_invoke(v_this, "ContainsTry", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "ThenBranch"))}, 1))) {
                            Value ret_152 = alg_bool(true);
                            alg_root_top = rt_base;
                            return ret_152;
                        }
                        if (alg_truthy((or_34 = alg_not_equal(alg_property(v_thestmt, "ElseBranch"), alg_nil()), !alg_truthy(or_34) ? or_34 : alg_invoke(v_this, "ContainsTry", (Value[]){alg_list_keep(alg_list(), alg_property(v_thestmt, "ElseBranch"))}, 1)))) {
                            Value ret_153 = alg_bool(true);
                            alg_root_top = rt_base;
                            return ret_153;
                        }
                    }
                }
            }
            alg_root_top = rt_505;
        }
        alg_root_top = rt_504;
    }
    Value ret_154 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_154;
    Value ret_155 = alg_nil();
    alg_root_top = rt_base;
    return ret_155;
}

static Value m_cemitter_local_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    if (alg_truthy(alg_property(v_this, "Volatiles"))) {
        Value ret_156 = alg_string("volatile Value ");
        alg_root_top = rt_base;
        return ret_156;
    }
    Value ret_157 = alg_string("Value ");
    alg_root_top = rt_base;
    return ret_157;
    Value ret_158 = alg_nil();
    alg_root_top = rt_base;
    return ret_158;
}

static Value m_cemitter_requirecell_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Cells"), "Contains", (Value[]){v_name}, 1)))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("A capture of '"), v_name), alg_char_value(39))}, 1));
    }
    Value ret_159 = alg_nil();
    alg_root_top = rt_base;
    return ret_159;
}

static Value m_cemitter_openscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value ret_160 = alg_list_keep(alg_list_keep(alg_list(), alg_property(alg_property(v_this, "Cells"), "Length")), alg_property(alg_property(v_this, "Locals"), "Length"));
    alg_root_top = rt_base;
    return ret_160;
    Value ret_161 = alg_nil();
    alg_root_top = rt_base;
    return ret_161;
}

static Value m_cemitter_closescope_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_mark = alg_widen(args[0], "List");
    (void)v_mark;
    alg_root(&v_mark, 1);
    while (alg_truthy(alg_greater(alg_property(alg_property(v_this, "Cells"), "Length"), alg_subscript_get(v_mark, alg_int(0))))) {
        (void)(alg_invoke(alg_property(v_this, "Cells"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "Cells"), "Length"), alg_int(1))}, 1));
    }
    while (alg_truthy(alg_greater(alg_property(alg_property(v_this, "Locals"), "Length"), alg_subscript_get(v_mark, alg_int(1))))) {
        (void)(alg_invoke(alg_property(v_this, "Locals"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "Locals"), "Length"), alg_int(1))}, 1));
    }
    Value ret_162 = alg_nil();
    alg_root_top = rt_base;
    return ret_162;
}

static Value m_cemitter_root_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_slots = alg_widen(args[0], "String");
    (void)v_slots;
    alg_root(&v_slots, 1);
    Value v_count = alg_widen(args[1], "String");
    (void)v_count;
    alg_root(&v_count, 1);
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("alg_root("), v_slots), alg_string(", ")), v_count), alg_string(");"))}, 1));
    Value ret_163 = alg_nil();
    alg_root_top = rt_base;
    return ret_163;
}

static Value m_cemitter_declarelocal_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_symbol = alg_widen(args[0], "String");
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    Value v_initial = alg_widen(args[1], "String");
    (void)v_initial;
    alg_root(&v_initial, 1);
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), v_symbol), alg_string(" = ")), v_initial), alg_char_value(59))}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), v_symbol), alg_char_value(59))}, 1));
    (void)(alg_invoke(v_this, "Root", (Value[]){alg_add(alg_char_value(38), v_symbol), alg_char_value(49)}, 2));
    Value ret_164 = alg_nil();
    alg_root_top = rt_base;
    return ret_164;
}

static Value m_cemitter_emitreturn_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_value = alg_widen(args[0], "String");
    (void)v_value;
    alg_root(&v_value, 1);
    if (alg_truthy(alg_equal(alg_property(v_this, "FrameRoots"), alg_string("")))) {
        {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("return "), v_value), alg_char_value(59))}, 1));
            Value ret_165 = alg_nil();
            alg_root_top = rt_base;
            return ret_165;
        }
    }
    Value v_slot = alg_add(alg_string("ret_"), alg_str(alg_property(v_this, "Loops")));
    (void)v_slot;
    alg_root(&v_slot, 1);
    (void)(alg_set_property(v_this, "Loops", alg_add(alg_property(v_this, "Loops"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), v_slot), alg_string(" = ")), v_value), alg_char_value(59))}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_root_top = "), alg_property(v_this, "FrameRoots")), alg_char_value(59))}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("return "), v_slot), alg_char_value(59))}, 1));
    Value ret_166 = alg_nil();
    alg_root_top = rt_base;
    return ret_166;
}

static Value m_cemitter_openroots_1_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_declares = alg_widen(args[0], "Boolean");
    (void)v_declares;
    alg_root(&v_declares, 1);
    if (alg_truthy(alg_not(v_declares))) {
        Value ret_167 = alg_string("");
        alg_root_top = rt_base;
        return ret_167;
    }
    Value v_mark = alg_add(alg_string("rt_"), alg_str(alg_property(v_this, "RootMarks")));
    (void)v_mark;
    alg_root(&v_mark, 1);
    (void)(alg_set_property(v_this, "RootMarks", alg_add(alg_property(v_this, "RootMarks"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("int32_t "), v_mark), alg_string(" = alg_root_top;"))}, 1));
    Value ret_168 = v_mark;
    alg_root_top = rt_base;
    return ret_168;
    Value ret_169 = alg_nil();
    alg_root_top = rt_base;
    return ret_169;
}

static Value m_cemitter_closeroots_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_mark = alg_widen(args[0], "String");
    (void)v_mark;
    alg_root(&v_mark, 1);
    if (alg_truthy(alg_equal(v_mark, alg_string("")))) {
        Value ret_170 = alg_nil();
        alg_root_top = rt_base;
        return ret_170;
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_root_top = "), v_mark), alg_char_value(59))}, 1));
    Value ret_171 = alg_nil();
    alg_root_top = rt_base;
    return ret_171;
}

static Value m_cemitter_declareslocal_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    {
        int32_t rt_506 = alg_root_top;
        Value loop_172 = alg_iterable(v_statements);
        (void)loop_172;
        alg_root(&loop_172, 1);
        for (int32_t at_172 = 0; at_172 < alg_iterable_count(loop_172); at_172++) {
            int32_t rt_507 = alg_root_top;
            Value v_each = alg_iterable_at(loop_172, at_172);
            (void)v_each;
            alg_root(&v_each, 1);
            {
                if (alg_truthy((or_35 = alg_is(v_each, "VarStmt"), alg_truthy(or_35) ? or_35 : alg_is(v_each, "VarGroupStmt")))) {
                    Value ret_173 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_173;
                }
                if (alg_truthy(alg_is(v_each, "FunctionStmt"))) {
                    Value ret_174 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_174;
                }
                if (alg_truthy((or_36 = alg_is(v_each, "LabelStmt"), !alg_truthy(or_36) ? or_36 : alg_not_equal(alg_property(v_each, "Inner"), alg_nil())))) {
                    if (alg_truthy((or_37 = alg_is(alg_property(v_each, "Inner"), "VarStmt"), alg_truthy(or_37) ? or_37 : alg_is(alg_property(v_each, "Inner"), "VarGroupStmt")))) {
                        Value ret_175 = alg_bool(true);
                        alg_root_top = rt_base;
                        return ret_175;
                    }
                }
            }
            alg_root_top = rt_507;
        }
        alg_root_top = rt_506;
    }
    Value ret_176 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_176;
    Value ret_177 = alg_nil();
    alg_root_top = rt_base;
    return ret_177;
}

static Value m_cemitter_declarecell_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_initial = alg_widen(args[1], "String");
    (void)v_initial;
    alg_root(&v_initial, 1);
    Value v_qualifier = alg_nil();
    (void)v_qualifier;
    alg_root(&v_qualifier, 1);
    (void)((v_qualifier = alg_string("")));
    if (alg_truthy(alg_property(v_this, "Volatiles"))) {
        (void)((v_qualifier = alg_string("volatile ")));
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("Value *"), v_qualifier), alg_invoke(v_this, "Cell", (Value[]){v_name}, 1)), alg_string(" = alg_cell(")), v_initial), alg_string(");"))}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "Cell", (Value[]){v_name}, 1)), alg_char_value(59))}, 1));
    (void)(alg_invoke(v_this, "Root", (Value[]){alg_invoke(v_this, "Cell", (Value[]){v_name}, 1), alg_char_value(49)}, 2));
    (void)(alg_invoke(alg_property(v_this, "Cells"), "Add", (Value[]){v_name}, 1));
    Value ret_178 = alg_nil();
    alg_root_top = rt_base;
    return ret_178;
}

static Value m_cemitter_hoistcells_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    {
        int32_t rt_508 = alg_root_top;
        Value loop_179 = alg_iterable(v_statements);
        (void)loop_179;
        alg_root(&loop_179, 1);
        for (int32_t at_179 = 0; at_179 < alg_iterable_count(loop_179); at_179++) {
            int32_t rt_509 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_179, at_179);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                if (alg_truthy((or_38 = alg_is(v_thestmt, "VarStmt"), !alg_truthy(or_38) ? or_38 : alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
                        (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_string("alg_nil()")}, 2));
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                    {
                        int32_t rt_510 = alg_root_top;
                        Value loop_180 = alg_iterable(alg_property(v_thestmt, "Names"));
                        (void)loop_180;
                        alg_root(&loop_180, 1);
                        for (int32_t at_180 = 0; at_180 < alg_iterable_count(loop_180); at_180++) {
                            int32_t rt_511 = alg_root_top;
                            Value v_thename = alg_iterable_at(loop_180, at_180);
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(v_thename, "Lexeme"))}, 1))) {
                                {
                                    (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(v_thename, "Lexeme"))}, 1));
                                    (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_str(alg_property(v_thename, "Lexeme")), alg_string("alg_nil()")}, 2));
                                }
                            }
                            alg_root_top = rt_511;
                        }
                        alg_root_top = rt_510;
                    }
                }
            }
            alg_root_top = rt_509;
        }
        alg_root_top = rt_508;
    }
    Value ret_181 = alg_nil();
    alg_root_top = rt_base;
    return ret_181;
}

static Value m_cemitter_emithandlerbody_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_handler = args[0];
    (void)v_handler;
    alg_root(&v_handler, 1);
    Value v_frame = alg_widen(args[1], "String");
    (void)v_frame;
    alg_root(&v_frame, 1);
    Value v_mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_mark;
    alg_root(&v_mark, 1);
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    Value v_roots = alg_invoke(v_this, "OpenRoots", (Value[]){alg_bool(true)}, 1);
    (void)v_roots;
    alg_root(&v_roots, 1);
    (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(v_handler, "Name"))}, 1));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(v_handler, "Name"))}, 1))) {
        (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_str(alg_property(v_handler, "Name")), alg_add(v_frame, alg_string(".raised"))}, 2));
    } else {
        {
            (void)(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(v_handler, "Name"))}, 1), alg_add(v_frame, alg_string(".raised"))}, 2));
        }
    }
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_handler, "Body")}, 1));
    (void)(alg_invoke(v_this, "CloseRoots", (Value[]){v_roots}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1));
    Value ret_182 = alg_nil();
    alg_root_top = rt_base;
    return ret_182;
}

static Value m_cemitter_declaredtypes_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_themethod = args[0];
    (void)v_themethod;
    alg_root(&v_themethod, 1);
    Value v_types = alg_nil();
    (void)v_types;
    alg_root(&v_types, 1);
    (void)((v_types = alg_list()));
    {
        int32_t rt_512 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_themethod, "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_513 = alg_root_top;
                Value v_declared = alg_str(alg_subscript_get(alg_property(v_themethod, "ParamTypes"), v_i));
                (void)v_declared;
                alg_root(&v_declared, 1);
                if (alg_truthy(alg_equal(v_declared, alg_string("")))) {
                    (void)((v_declared = alg_string("Any")));
                }
                (void)(alg_invoke(v_types, "Add", (Value[]){v_declared}, 1));
                alg_root_top = rt_513;
            }
        }
        alg_root_top = rt_512;
    }
    Value ret_183 = v_types;
    alg_root_top = rt_base;
    return ret_183;
    Value ret_184 = alg_nil();
    alg_root_top = rt_base;
    return ret_184;
}

static Value m_cemitter_parametertable_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_themethod = args[0];
    (void)v_themethod;
    alg_root(&v_themethod, 1);
    Value v_written = alg_nil();
    (void)v_written;
    alg_root(&v_written, 1);
    (void)((v_written = alg_list()));
    {
        int32_t rt_514 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_themethod, "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_515 = alg_root_top;
                Value v_declared = alg_str(alg_subscript_get(alg_property(v_themethod, "ParamTypes"), v_i));
                (void)v_declared;
                alg_root(&v_declared, 1);
                if (alg_truthy(alg_equal(v_declared, alg_string("")))) {
                    (void)((v_declared = alg_string("Any")));
                }
                if (alg_truthy(alg_less(v_i, alg_property(alg_property(v_themethod, "ParamGenerics"), "Length")))) {
                    {
                        int32_t rt_516 = alg_root_top;
                        Value v_element = alg_str(alg_subscript_get(alg_property(v_themethod, "ParamGenerics"), v_i));
                        (void)v_element;
                        alg_root(&v_element, 1);
                        if (alg_truthy(alg_not_equal(v_element, alg_string("")))) {
                            (void)((v_declared = alg_add(alg_add(v_declared, alg_string(" of ")), v_element)));
                        }
                        alg_root_top = rt_516;
                    }
                }
                (void)(alg_invoke(v_written, "Add", (Value[]){alg_add(alg_add(alg_str(alg_property(alg_subscript_get(alg_property(v_themethod, "Params"), v_i), "Lexeme")), alg_string(" : ")), v_declared)}, 1));
                alg_root_top = rt_515;
            }
        }
        alg_root_top = rt_514;
    }
    Value ret_185 = v_written;
    alg_root_top = rt_base;
    return ret_185;
    Value ret_186 = alg_nil();
    alg_root_top = rt_base;
    return ret_186;
}

static Value m_cemitter_collectshadowarities_2_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    Value v_hidden = alg_widen(args[1], "List");
    (void)v_hidden;
    alg_root(&v_hidden, 1);
    {
        int32_t rt_517 = alg_root_top;
        Value loop_187 = alg_iterable(v_statements);
        (void)loop_187;
        alg_root(&loop_187, 1);
        for (int32_t at_187 = 0; at_187 < alg_iterable_count(loop_187); at_187++) {
            int32_t rt_518 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_187, at_187);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rt_519 = alg_root_top;
                Value v_named = (or_42 = (or_41 = (or_40 = (or_39 = alg_is(v_thestmt, "FunctionStmt"), alg_truthy(or_39) ? or_39 : alg_is(v_thestmt, "ClassStmt")), alg_truthy(or_40) ? or_40 : alg_is(v_thestmt, "ObjectStmt")), alg_truthy(or_41) ? or_41 : alg_is(v_thestmt, "VarStmt")), alg_truthy(or_42) ? or_42 : alg_is(v_thestmt, "EnumStmt"));
                (void)v_named;
                alg_root(&v_named, 1);
                if (alg_truthy(alg_not(v_named))) {
                    continue;
                }
                Value v_thename = alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"));
                (void)v_thename;
                alg_root(&v_thename, 1);
                Value v_privateQ = alg_bool(false);
                (void)v_privateQ;
                alg_root(&v_privateQ, 1);
                {
                    int32_t rt_520 = alg_root_top;
                    Value loop_188 = alg_iterable(v_hidden);
                    (void)loop_188;
                    alg_root(&loop_188, 1);
                    for (int32_t at_188 = 0; at_188 < alg_iterable_count(loop_188); at_188++) {
                        int32_t rt_521 = alg_root_top;
                        Value v_each = alg_iterable_at(loop_188, at_188);
                        (void)v_each;
                        alg_root(&v_each, 1);
                        if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_str(v_each)}, 1), f_foldcase(NULL, (Value[]){v_thename}, 1)))) {
                            (void)((v_privateQ = alg_bool(true)));
                        }
                        alg_root_top = rt_521;
                    }
                    alg_root_top = rt_520;
                }
                if (alg_truthy(v_privateQ)) {
                    continue;
                }
                if (alg_truthy(alg_not((alg_is(v_thestmt, "FunctionStmt"))))) {
                    {
                        (void)(alg_invoke(alg_property(v_this, "ShadowWhole"), "Add", (Value[]){v_thename}, 1));
                        continue;
                    }
                }
                if (alg_truthy(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1))) {
                    continue;
                }
                if (alg_truthy(alg_invoke(v_this, "Variadic", (Value[]){v_thestmt}, 1))) {
                    (void)(alg_invoke(alg_property(v_this, "ShadowArities"), "Add", (Value[]){alg_add(alg_add(v_thename, alg_string("/~")), alg_str(alg_subtract(alg_property(alg_property(v_thestmt, "Params"), "Length"), alg_int(1))))}, 1));
                } else {
                    (void)(alg_invoke(alg_property(v_this, "ShadowArities"), "Add", (Value[]){alg_add(alg_add(v_thename, alg_char_value(47)), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length")))}, 1));
                }
                alg_root_top = rt_519;
            }
            alg_root_top = rt_518;
        }
        alg_root_top = rt_517;
    }
    Value ret_189 = alg_nil();
    alg_root_top = rt_base;
    return ret_189;
}

static Value m_cemitter_takesover_2_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_count = alg_widen(args[1], "Integer");
    (void)v_count;
    alg_root(&v_count, 1);
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "ShadowNames"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_190 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_190;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "ShadowWhole"), "Contains", (Value[]){v_name}, 1))) {
        Value ret_191 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_191;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "ShadowArities"), "Contains", (Value[]){alg_add(alg_add(v_name, alg_char_value(47)), alg_str(v_count))}, 1))) {
        Value ret_192 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_192;
    }
    {
        int32_t rt_522 = alg_root_top;
        Value v_fixed = alg_int(0);
        (void)v_fixed;
        alg_root(&v_fixed, 1);
        for (; alg_truthy(alg_less_equal(v_fixed, v_count)); (v_fixed = alg_add(v_fixed, alg_int(1)))) {
            if (alg_truthy(alg_invoke(alg_property(v_this, "ShadowArities"), "Contains", (Value[]){alg_add(alg_add(v_name, alg_string("/~")), alg_str(v_fixed))}, 1))) {
                Value ret_193 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_193;
            }
        }
        alg_root_top = rt_522;
    }
    Value ret_194 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_194;
    Value ret_195 = alg_nil();
    alg_root_top = rt_base;
    return ret_195;
}

static Value m_cemitter_variadic_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    if (alg_truthy(alg_equal(alg_property(alg_property(v_thestmt, "Params"), "Length"), alg_int(0)))) {
        Value ret_196 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_196;
    }
    Value v_last = alg_subtract(alg_property(alg_property(v_thestmt, "Params"), "Length"), alg_int(1));
    (void)v_last;
    alg_root(&v_last, 1);
    if (alg_truthy(alg_greater_equal(v_last, alg_property(alg_property(v_thestmt, "ParamTypes"), "Length")))) {
        Value ret_197 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_197;
    }
    if (alg_truthy(alg_greater_equal(v_last, alg_property(alg_property(v_thestmt, "ParamGenerics"), "Length")))) {
        Value ret_198 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_198;
    }
    Value ret_199 = (or_43 = alg_equal(f_canonicaltype(NULL, (Value[]){alg_subscript_get(alg_property(v_thestmt, "ParamTypes"), v_last)}, 1), alg_string("List")), !alg_truthy(or_43) ? or_43 : alg_not_equal(alg_str(alg_subscript_get(alg_property(v_thestmt, "ParamGenerics"), v_last)), alg_string("")));
    alg_root_top = rt_base;
    return ret_199;
    Value ret_200 = alg_nil();
    alg_root_top = rt_base;
    return ret_200;
}

static Value m_cemitter_methodsymbol_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_owner = alg_widen(args[0], "String");
    (void)v_owner;
    alg_root(&v_owner, 1);
    Value v_themethod = args[1];
    (void)v_themethod;
    alg_root(&v_themethod, 1);
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    (void)((v_symbol = alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("m_"), alg_invoke(v_this, "Escaped", (Value[]){v_owner}, 1)), alg_char_value(95)), alg_invoke(v_this, "Escaped", (Value[]){alg_str(alg_property(alg_property(v_themethod, "Name"), "Lexeme"))}, 1)), alg_char_value(95)), alg_str(alg_property(alg_property(v_themethod, "Params"), "Length")))));
    Value v_types = alg_invoke(v_this, "DeclaredTypes", (Value[]){v_themethod}, 1);
    (void)v_types;
    alg_root(&v_types, 1);
    {
        int32_t rt_523 = alg_root_top;
        Value loop_201 = alg_iterable(v_types);
        (void)loop_201;
        alg_root(&loop_201, 1);
        for (int32_t at_201 = 0; at_201 < alg_iterable_count(loop_201); at_201++) {
            int32_t rt_524 = alg_root_top;
            Value v_thetype = alg_iterable_at(loop_201, at_201);
            (void)v_thetype;
            alg_root(&v_thetype, 1);
            if (alg_truthy(alg_not_equal(v_thetype, alg_string("Any")))) {
                (void)((v_symbol = alg_add(alg_add(v_symbol, alg_char_value(95)), alg_invoke(v_this, "Escaped", (Value[]){alg_str(v_thetype)}, 1))));
            }
            alg_root_top = rt_524;
        }
        alg_root_top = rt_523;
    }
    Value ret_202 = v_symbol;
    alg_root_top = rt_base;
    return ret_202;
    Value ret_203 = alg_nil();
    alg_root_top = rt_base;
    return ret_203;
}

static Value m_cemitter_namesvisible_3_string_list_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_supername = alg_widen(args[0], "String");
    (void)v_supername;
    alg_root(&v_supername, 1);
    Value v_own = alg_widen(args[1], "List");
    (void)v_own;
    alg_root(&v_own, 1);
    Value v_fields = alg_widen(args[2], "Boolean");
    (void)v_fields;
    alg_root(&v_fields, 1);
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    (void)((v_names = alg_set()));
    {
        int32_t rt_525 = alg_root_top;
        Value loop_204 = alg_iterable(v_own);
        (void)loop_204;
        alg_root(&loop_204, 1);
        for (int32_t at_204 = 0; at_204 < alg_iterable_count(loop_204); at_204++) {
            int32_t rt_526 = alg_root_top;
            Value v_each = alg_iterable_at(loop_204, at_204);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_invoke(v_names, "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_each, "Name"), "Lexeme")}, 1)}, 1));
            alg_root_top = rt_526;
        }
        alg_root_top = rt_525;
    }
    (void)((v_at = v_supername));
    while (alg_truthy(alg_not_equal(v_at, alg_string("")))) {
        {
            int32_t rt_527 = alg_root_top;
            if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_at}, 1)}, 1)))) {
                Value ret_205 = v_names;
                alg_root_top = rt_base;
                return ret_205;
            }
            Value v_ancestor = alg_invoke(alg_property(v_this, "Classes"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_at}, 1)}, 1);
            (void)v_ancestor;
            alg_root(&v_ancestor, 1);
            Value v_inherited = alg_property(v_ancestor, "Methods");
            (void)v_inherited;
            alg_root(&v_inherited, 1);
            if (alg_truthy(v_fields)) {
                (void)((v_inherited = alg_property(v_ancestor, "Fields")));
            }
            {
                int32_t rt_528 = alg_root_top;
                Value loop_206 = alg_iterable(v_inherited);
                (void)loop_206;
                alg_root(&loop_206, 1);
                for (int32_t at_206 = 0; at_206 < alg_iterable_count(loop_206); at_206++) {
                    int32_t rt_529 = alg_root_top;
                    Value v_item = alg_iterable_at(loop_206, at_206);
                    (void)v_item;
                    alg_root(&v_item, 1);
                    (void)(alg_invoke(v_names, "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_property(alg_property(v_item, "Name"), "Lexeme")}, 1)}, 1));
                    alg_root_top = rt_529;
                }
                alg_root_top = rt_528;
            }
            (void)((v_at = alg_string("")));
            if (alg_truthy(alg_not_equal(alg_property(v_ancestor, "Superclass"), alg_nil()))) {
                (void)((v_at = alg_str(alg_property(alg_property(alg_property(v_ancestor, "Superclass"), "Name"), "Lexeme"))));
            }
            alg_root_top = rt_527;
        }
    }
    Value ret_207 = v_names;
    alg_root_top = rt_base;
    return ret_207;
    Value ret_208 = alg_nil();
    alg_root_top = rt_base;
    return ret_208;
}

static Value m_cemitter_emitmethod_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_owner = alg_widen(args[0], "String");
    (void)v_owner;
    alg_root(&v_owner, 1);
    Value v_themethod = args[1];
    (void)v_themethod;
    alg_root(&v_themethod, 1);
    Value v_enclosinglocals = alg_nil();
    (void)v_enclosinglocals;
    alg_root(&v_enclosinglocals, 1);
    Value v_enclosingtop = alg_nil();
    (void)v_enclosingtop;
    alg_root(&v_enclosingtop, 1);
    Value v_enclosingdepth = alg_nil();
    (void)v_enclosingdepth;
    alg_root(&v_enclosingdepth, 1);
    Value v_opening = alg_nil();
    (void)v_opening;
    alg_root(&v_opening, 1);
    (void)((v_enclosinglocals = alg_property(v_this, "Locals")));
    (void)((v_enclosingtop = alg_property(v_this, "AtTopLevel")));
    (void)((v_enclosingdepth = alg_property(v_this, "Depth")));
    (void)(alg_set_property(v_this, "Locals", alg_list()));
    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
    Value v_enclosingtarget = alg_property(v_this, "Target");
    (void)v_enclosingtarget;
    alg_root(&v_enclosingtarget, 1);
    Value v_enclosingbody = alg_property(v_this, "Body");
    (void)v_enclosingbody;
    alg_root(&v_enclosingbody, 1);
    (void)(alg_set_property(v_this, "Target", alg_string("body")));
    (void)(alg_set_property(v_this, "Body", alg_buffer(alg_int(0))));
    (void)(alg_set_property(v_this, "Depth", alg_int(1)));
    Value v_enclosingvolatiles = alg_property(v_this, "Volatiles");
    (void)v_enclosingvolatiles;
    alg_root(&v_enclosingvolatiles, 1);
    (void)(alg_set_property(v_this, "Volatiles", alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_themethod, "Body")}, 1)));
    Value v_enclosingframeroots = alg_property(v_this, "FrameRoots");
    (void)v_enclosingframeroots;
    alg_root(&v_enclosingframeroots, 1);
    (void)(alg_set_property(v_this, "FrameRoots", alg_string("rt_base")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("int32_t "), alg_property(v_this, "FrameRoots")), alg_string(" = alg_root_top;"))}, 1));
    (void)(alg_invoke(v_this, "Root", (Value[]){alg_string("&v_this"), alg_char_value(49)}, 2));
    (void)(alg_invoke(v_this, "Root", (Value[]){alg_string("args"), alg_string("count")}, 2));
    Value v_enclosingboxed = alg_property(v_this, "Boxed");
    (void)v_enclosingboxed;
    alg_root(&v_enclosingboxed, 1);
    Value v_enclosingcaptured = alg_property(v_this, "Captured");
    (void)v_enclosingcaptured;
    alg_root(&v_enclosingcaptured, 1);
    Value v_enclosingcells = alg_property(v_this, "Cells");
    (void)v_enclosingcells;
    alg_root(&v_enclosingcells, 1);
    (void)(alg_set_property(v_this, "Boxed", alg_list()));
    (void)(alg_set_property(v_this, "Captured", alg_map()));
    (void)(alg_set_property(v_this, "Cells", alg_list()));
    if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_property(v_themethod, "Body")}, 1))) {
        {
            (void)(alg_set_property(v_this, "Boxed", alg_invoke(v_this, "BoundNames", (Value[]){v_themethod}, 1)));
            (void)(alg_invoke(v_this, "AddOnce", (Value[]){alg_property(v_this, "Boxed"), alg_string("this")}, 2));
            (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_string("this"), alg_string("v_this")}, 2));
        }
    }
    Value v_enclosingtrydepth = alg_property(v_this, "TryDepth");
    (void)v_enclosingtrydepth;
    alg_root(&v_enclosingtrydepth, 1);
    Value v_enclosinglooptry = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosinglooptry;
    alg_root(&v_enclosinglooptry, 1);
    (void)(alg_set_property(v_this, "TryDepth", alg_int(0)));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_int(0)));
    {
        int32_t rt_530 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_themethod, "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_531 = alg_root_top;
                Value v_name = alg_str(alg_property(alg_subscript_get(alg_property(v_themethod, "Params"), v_i), "Lexeme"));
                (void)v_name;
                alg_root(&v_name, 1);
                (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_name}, 1));
                Value v_slot = alg_add(alg_add(alg_string("args["), alg_str(v_i)), alg_char_value(93));
                (void)v_slot;
                alg_root(&v_slot, 1);
                if (alg_truthy(alg_less(v_i, alg_property(alg_property(v_themethod, "ParamTypes"), "Length")))) {
                    {
                        int32_t rt_532 = alg_root_top;
                        Value v_declared = alg_str(alg_subscript_get(alg_property(v_themethod, "ParamTypes"), v_i));
                        (void)v_declared;
                        alg_root(&v_declared, 1);
                        if (alg_truthy((or_44 = alg_not_equal(v_declared, alg_string("")), !alg_truthy(or_44) ? or_44 : alg_not_equal(v_declared, alg_string("Any"))))) {
                            (void)((v_slot = alg_add(alg_add(alg_add(alg_add(alg_string("alg_widen("), v_slot), alg_string(", ")), f_quotec(NULL, (Value[]){v_declared}, 1)), alg_char_value(41))));
                        }
                        alg_root_top = rt_532;
                    }
                }
                if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1))) {
                    (void)(alg_invoke(v_this, "DeclareCell", (Value[]){v_name, v_slot}, 2));
                } else {
                    {
                        (void)(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1), v_slot}, 2));
                    }
                }
                alg_root_top = rt_531;
            }
        }
        alg_root_top = rt_530;
    }
    (void)(alg_invoke(v_this, "HoistCells", (Value[]){alg_property(v_themethod, "Body")}, 1));
    (void)(alg_invoke(v_this, "PushLabels", (Value[]){alg_property(v_themethod, "Body")}, 1));
    {
        int32_t rt_533 = alg_root_top;
        Value loop_209 = alg_iterable(alg_property(v_themethod, "Body"));
        (void)loop_209;
        alg_root(&loop_209, 1);
        for (int32_t at_209 = 0; at_209 < alg_iterable_count(loop_209); at_209++) {
            int32_t rt_534 = alg_root_top;
            Value v_each = alg_iterable_at(loop_209, at_209);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_invoke(v_this, "Execute", (Value[]){v_each}, 1));
            alg_root_top = rt_534;
        }
        alg_root_top = rt_533;
    }
    (void)(alg_invoke(v_this, "PopLabels", NULL, 0));
    (void)(alg_invoke(v_this, "EmitReturn", (Value[]){alg_string("alg_nil()")}, 1));
    Value v_written = alg_property(alg_property(v_this, "Body"), "Text");
    (void)v_written;
    alg_root(&v_written, 1);
    (void)(alg_set_property(v_this, "Target", v_enclosingtarget));
    (void)(alg_set_property(v_this, "Body", v_enclosingbody));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), alg_invoke(v_this, "MethodSymbol", (Value[]){v_owner, v_themethod}, 2)), alg_string("(Value v_this, Value *args, int32_t count) {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)v_this; (void)args; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_written}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_char_value(125), alg_char_value(10)), alg_char_value(10))}, 1));
    (void)(alg_set_property(v_this, "Depth", v_enclosingdepth));
    (void)(alg_set_property(v_this, "AtTopLevel", v_enclosingtop));
    (void)(alg_set_property(v_this, "Locals", v_enclosinglocals));
    (void)(alg_set_property(v_this, "Volatiles", v_enclosingvolatiles));
    (void)(alg_set_property(v_this, "Boxed", v_enclosingboxed));
    (void)(alg_set_property(v_this, "Captured", v_enclosingcaptured));
    (void)(alg_set_property(v_this, "Cells", v_enclosingcells));
    (void)(alg_set_property(v_this, "TryDepth", v_enclosingtrydepth));
    (void)(alg_set_property(v_this, "LoopTryDepth", v_enclosinglooptry));
    (void)(alg_set_property(v_this, "FrameRoots", v_enclosingframeroots));
    Value ret_210 = alg_nil();
    alg_root_top = rt_base;
    return ret_210;
}

static Value m_cemitter_emitclass_5_string_list_list_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_superclass = args[1];
    (void)v_superclass;
    alg_root(&v_superclass, 1);
    Value v_fields = alg_widen(args[2], "List");
    (void)v_fields;
    alg_root(&v_fields, 1);
    Value v_methods = alg_widen(args[3], "List");
    (void)v_methods;
    alg_root(&v_methods, 1);
    Value v_isobject = alg_widen(args[4], "Boolean");
    (void)v_isobject;
    alg_root(&v_isobject, 1);
    Value v_handle = alg_nil();
    (void)v_handle;
    alg_root(&v_handle, 1);
    Value v_supername = alg_nil();
    (void)v_supername;
    alg_root(&v_supername, 1);
    Value v_applied = alg_nil();
    (void)v_applied;
    alg_root(&v_applied, 1);
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    Value v_enclosingclass = alg_nil();
    (void)v_enclosingclass;
    alg_root(&v_enclosingclass, 1);
    Value v_enclosingfields = alg_nil();
    (void)v_enclosingfields;
    alg_root(&v_enclosingfields, 1);
    Value v_enclosingmethods = alg_nil();
    (void)v_enclosingmethods;
    alg_root(&v_enclosingmethods, 1);
    (void)((v_handle = alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)));
    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){v_handle, v_name}, 2));
    (void)((v_enclosingclass = alg_property(v_this, "CurrentClass")));
    (void)((v_enclosingfields = alg_property(v_this, "VisibleFields")));
    (void)((v_enclosingmethods = alg_property(v_this, "VisibleMethods")));
    (void)((v_supername = alg_string("")));
    if (alg_truthy(alg_not_equal(v_superclass, alg_nil()))) {
        (void)((v_supername = alg_str(alg_property(alg_property(v_superclass, "Name"), "Lexeme"))));
    }
    (void)(alg_set_property(v_this, "CurrentClass", v_name));
    (void)(alg_set_property(v_this, "VisibleFields", alg_invoke(v_this, "NamesVisible", (Value[]){v_supername, v_fields, alg_bool(true)}, 3)));
    (void)(alg_set_property(v_this, "VisibleMethods", alg_invoke(v_this, "NamesVisible", (Value[]){v_supername, v_methods, alg_bool(false)}, 3)));
    Value v_declaresid = alg_bool(false);
    (void)v_declaresid;
    alg_root(&v_declaresid, 1);
    {
        int32_t rt_535 = alg_root_top;
        Value loop_211 = alg_iterable(v_fields);
        (void)loop_211;
        alg_root(&loop_211, 1);
        for (int32_t at_211 = 0; at_211 < alg_iterable_count(loop_211); at_211++) {
            int32_t rt_536 = alg_root_top;
            Value v_field = alg_iterable_at(loop_211, at_211);
            (void)v_field;
            alg_root(&v_field, 1);
            if (alg_truthy(alg_equal(alg_str(alg_property(alg_property(v_field, "Name"), "Lexeme")), alg_string("Id")))) {
                (void)((v_declaresid = alg_bool(true)));
            }
            alg_root_top = rt_536;
        }
        alg_root_top = rt_535;
    }
    Value v_addid = (or_45 = v_isobject, !alg_truthy(or_45) ? or_45 : alg_not(v_declaresid));
    (void)v_addid;
    alg_root(&v_addid, 1);
    if (alg_truthy(v_addid)) {
        (void)(alg_invoke(alg_property(v_this, "VisibleFields"), "Add", (Value[]){f_foldcase(NULL, (Value[]){alg_string("Id")}, 1)}, 1));
    }
    (void)((v_applied = alg_string("")));
    {
        int32_t rt_537 = alg_root_top;
        Value loop_212 = alg_iterable(v_fields);
        (void)loop_212;
        alg_root(&loop_212, 1);
        for (int32_t at_212 = 0; at_212 < alg_iterable_count(loop_212); at_212++) {
            int32_t rt_538 = alg_root_top;
            Value v_thefield = alg_iterable_at(loop_212, at_212);
            (void)v_thefield;
            alg_root(&v_thefield, 1);
            {
                int32_t rt_539 = alg_root_top;
                Value v_value = alg_string("alg_nil()");
                (void)v_value;
                alg_root(&v_value, 1);
                if (alg_truthy(alg_not_equal(alg_property(v_thefield, "Initializer"), alg_nil()))) {
                    {
                        (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thefield, "Initializer")}, 1)));
                        (void)((v_value = alg_invoke(v_this, "BoundValue", (Value[]){alg_property(v_thefield, "TypeName"), v_value, alg_string("")}, 3)));
                    }
                }
                (void)((v_applied = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(v_applied, alg_string("    alg_set_property(v_this, ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_thefield, "Name"), "Lexeme"))}, 1)), alg_string(", ")), v_value), alg_string(");")), alg_char_value(10))));
                alg_root_top = rt_539;
            }
            alg_root_top = rt_538;
        }
        alg_root_top = rt_537;
    }
    if (alg_truthy(v_addid)) {
        (void)((v_applied = alg_add(alg_add(alg_add(alg_add(v_applied, alg_string("    alg_set_property(v_this, \"Id\", alg_string(")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string("));")), alg_char_value(10))));
    }
    (void)((v_initializer = alg_invoke(v_this, "InitName", (Value[]){v_name}, 1)));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_initializer), alg_string("(Value v_this, Value *args, int32_t count) {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)v_this; (void)args; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    int32_t rt_base = alg_root_top;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    alg_root(&v_this, 1);"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_applied}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    alg_root_top = rt_base;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("    return alg_nil();"), alg_char_value(10)), alg_char_value(125)), alg_char_value(10)), alg_char_value(10))}, 1));
    {
        int32_t rt_540 = alg_root_top;
        Value loop_213 = alg_iterable(v_methods);
        (void)loop_213;
        alg_root(&loop_213, 1);
        for (int32_t at_213 = 0; at_213 < alg_iterable_count(loop_213); at_213++) {
            int32_t rt_541 = alg_root_top;
            Value v_method = alg_iterable_at(loop_213, at_213);
            (void)v_method;
            alg_root(&v_method, 1);
            (void)(alg_invoke(v_this, "EmitMethod", (Value[]){v_name, v_method}, 2));
            alg_root_top = rt_541;
        }
        alg_root_top = rt_540;
    }
    (void)(alg_set_property(v_this, "CurrentClass", v_enclosingclass));
    (void)(alg_set_property(v_this, "VisibleFields", v_enclosingfields));
    (void)(alg_set_property(v_this, "VisibleMethods", v_enclosingmethods));
    (void)(alg_invoke(alg_property(v_this, "Shells"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), v_handle), alg_string(" = alg_class(")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string(", alg_nil());")), alg_char_value(10))}, 1));
    Value v_hoisted = (or_46 = alg_equal(v_supername, alg_string("")), alg_truthy(or_46) ? or_46 : alg_invoke(alg_property(v_this, "OwnClasses"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_supername}, 1)}, 1));
    (void)v_hoisted;
    alg_root(&v_hoisted, 1);
    if (alg_truthy(alg_not_equal(v_supername, alg_string("")))) {
        {
            if (alg_truthy((or_47 = alg_not(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_supername}, 1)}, 1)), !alg_truthy(or_47) ? or_47 : alg_not(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_supername}, 1)}, 1))))) {
                alg_raise(alg_add(alg_add(alg_char_value(39), v_supername), alg_string("' is not a class.")));
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_supername}, 1)}, 1))) {
                (void)((v_supername = alg_str(alg_property(alg_property(alg_invoke(alg_property(v_this, "Classes"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_supername}, 1)}, 1), "Name"), "Lexeme"))));
            }
            if (alg_truthy(alg_not(v_hoisted))) {
                (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_add(alg_add(alg_string("alg_class_declared("), alg_invoke(v_this, "ClassHandle", (Value[]){v_supername}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){v_supername}, 1)), alg_string(");"))}, 2));
            }
            (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_add(alg_add(alg_string("alg_class_super("), v_handle), alg_string(", ")), alg_invoke(v_this, "ClassHandle", (Value[]){v_supername}, 1)), alg_string(");"))}, 2));
        }
    }
    {
        int32_t rt_542 = alg_root_top;
        Value loop_214 = alg_iterable(v_fields);
        (void)loop_214;
        alg_root(&loop_214, 1);
        for (int32_t at_214 = 0; at_214 < alg_iterable_count(loop_214); at_214++) {
            int32_t rt_543 = alg_root_top;
            Value v_eachfield = alg_iterable_at(loop_214, at_214);
            (void)v_eachfield;
            alg_root(&v_eachfield, 1);
            (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_add(alg_add(alg_string("alg_class_field("), v_handle), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_eachfield, "Name"), "Lexeme"))}, 1)), alg_string(");"))}, 2));
            alg_root_top = rt_543;
        }
        alg_root_top = rt_542;
    }
    if (alg_truthy(v_addid)) {
        (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_string("alg_class_field("), v_handle), alg_string(", \"Id\");"))}, 2));
    }
    (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_add(alg_add(alg_string("alg_class_initializer("), v_handle), alg_string(", ")), v_initializer), alg_string(");"))}, 2));
    {
        int32_t rt_544 = alg_root_top;
        Value loop_215 = alg_iterable(v_methods);
        (void)loop_215;
        alg_root(&loop_215, 1);
        for (int32_t at_215 = 0; at_215 < alg_iterable_count(loop_215); at_215++) {
            int32_t rt_545 = alg_root_top;
            Value v_themethod = alg_iterable_at(loop_215, at_215);
            (void)v_themethod;
            alg_root(&v_themethod, 1);
            {
                int32_t rt_546 = alg_root_top;
                Value v_types = alg_invoke(v_this, "ParameterTable", (Value[]){v_themethod}, 1);
                (void)v_types;
                alg_root(&v_types, 1);
                Value v_table = alg_string("NULL");
                (void)v_table;
                alg_root(&v_table, 1);
                if (alg_truthy(alg_greater(alg_property(v_types, "Length"), alg_int(0)))) {
                    {
                        int32_t rt_547 = alg_root_top;
                        (void)((v_table = alg_add(alg_string("t_"), alg_copy(alg_invoke(v_this, "MethodSymbol", (Value[]){v_name, v_themethod}, 2), alg_int(2), alg_subtract(alg_text_length(alg_invoke(v_this, "MethodSymbol", (Value[]){v_name, v_themethod}, 2)), alg_int(2))))));
                        Value v_quoted = alg_string("");
                        (void)v_quoted;
                        alg_root(&v_quoted, 1);
                        {
                            int32_t rt_548 = alg_root_top;
                            Value v_j = alg_int(0);
                            (void)v_j;
                            alg_root(&v_j, 1);
                            for (; alg_truthy(alg_less(v_j, alg_property(v_types, "Length"))); (v_j = alg_add(v_j, alg_int(1)))) {
                                {
                                    if (alg_truthy(alg_greater(v_j, alg_int(0)))) {
                                        (void)((v_quoted = alg_add(v_quoted, alg_string(", "))));
                                    }
                                    (void)((v_quoted = alg_add(v_quoted, f_quotec(NULL, (Value[]){alg_str(alg_subscript_get(v_types, v_j))}, 1))));
                                }
                            }
                            alg_root_top = rt_548;
                        }
                        (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("static const char *"), v_table), alg_string("[] = { ")), v_quoted), alg_string(" };")), alg_char_value(10))}, 1));
                        alg_root_top = rt_547;
                    }
                }
                if (alg_truthy(alg_property(v_themethod, "IsProperty"))) {
                    (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_class_property("), v_handle), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_themethod, "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "MethodSymbol", (Value[]){v_name, v_themethod}, 2)), alg_string(");"))}, 2));
                } else {
                    (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_class_method("), v_handle), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_themethod, "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "MethodSymbol", (Value[]){v_name, v_themethod}, 2)), alg_string(", ")), alg_str(alg_property(alg_property(v_themethod, "Params"), "Length"))), alg_string(", ")), v_table), alg_string(");"))}, 2));
                }
                alg_root_top = rt_546;
            }
            alg_root_top = rt_545;
        }
        alg_root_top = rt_544;
    }
    if (alg_truthy(v_isobject)) {
        (void)(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_add(alg_add(alg_string("alg_class_is_object("), v_handle), alg_string(");"))}, 2));
    }
    Value ret_216 = alg_nil();
    alg_root_top = rt_base;
    return ret_216;
}

static Value m_cemitter_built_2_boolean_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_hoisted = alg_widen(args[0], "Boolean");
    (void)v_hoisted;
    alg_root(&v_hoisted, 1);
    Value v_text = alg_widen(args[1], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    if (alg_truthy(v_hoisted)) {
        (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_string("    "), v_text), alg_char_value(10))}, 1));
    } else {
        (void)(alg_invoke(v_this, "Line", (Value[]){v_text}, 1));
    }
    Value ret_217 = alg_nil();
    alg_root_top = rt_base;
    return ret_217;
}

static Value m_cemitter_visitvarstmt_1_varstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "VarStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    (void)((v_value = alg_string("alg_nil()")));
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Initializer"), alg_nil()))) {
        {
            (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Initializer")}, 1)));
            (void)((v_value = alg_invoke(v_this, "BoundValue", (Value[]){alg_property(v_thestmt, "TypeName"), v_value, alg_property(v_thestmt, "Actual")}, 3)));
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
                (void)(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1), v_value}, 2));
            }
        }
    }
    Value ret_218 = alg_nil();
    alg_root_top = rt_base;
    return ret_218;
}

static Value m_cemitter_visitexpressionstmt_1_expressionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ExpressionStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Expression")}, 1)), alg_string(");"))}, 1));
    Value ret_219 = alg_nil();
    alg_root_top = rt_base;
    return ret_219;
}

static Value m_cemitter_pushlabels_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    Value v_here = alg_nil();
    (void)v_here;
    alg_root(&v_here, 1);
    (void)((v_here = alg_map()));
    {
        int32_t rt_549 = alg_root_top;
        Value loop_220 = alg_iterable(v_statements);
        (void)loop_220;
        alg_root(&loop_220, 1);
        for (int32_t at_220 = 0; at_220 < alg_iterable_count(loop_220); at_220++) {
            int32_t rt_550 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_220, at_220);
            (void)v_statement;
            alg_root(&v_statement, 1);
            if (alg_truthy(alg_is(v_statement, "LabelStmt"))) {
                (void)(alg_invoke(v_here, "Put", (Value[]){f_foldcase(NULL, (Value[]){alg_str(alg_property(alg_property(v_statement, "Name"), "Lexeme"))}, 1), alg_property(v_this, "TryDepth")}, 2));
            }
            alg_root_top = rt_550;
        }
        alg_root_top = rt_549;
    }
    (void)(alg_invoke(alg_property(v_this, "LabelDepths"), "Add", (Value[]){v_here}, 1));
    Value ret_221 = alg_nil();
    alg_root_top = rt_base;
    return ret_221;
}

static Value m_cemitter_poplabels_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    (void)(alg_invoke(alg_property(v_this, "LabelDepths"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LabelDepths"), "Length"), alg_int(1))}, 1));
    Value ret_222 = alg_nil();
    alg_root_top = rt_base;
    return ret_222;
}

static Value m_cemitter_depthoflabel_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    (void)((v_folded = f_foldcase(NULL, (Value[]){v_thelabel}, 1)));
    {
        int32_t rt_551 = alg_root_top;
        Value v_s = alg_subtract(alg_property(alg_property(v_this, "LabelDepths"), "Length"), alg_int(1));
        (void)v_s;
        alg_root(&v_s, 1);
        for (; alg_truthy(alg_greater_equal(v_s, alg_int(0))); (v_s = alg_subtract(v_s, alg_int(1)))) {
            if (alg_truthy(alg_invoke(alg_subscript_get(alg_property(v_this, "LabelDepths"), v_s), "Contains", (Value[]){v_folded}, 1))) {
                Value ret_223 = alg_cast(alg_invoke(alg_subscript_get(alg_property(v_this, "LabelDepths"), v_s), "Get", (Value[]){v_folded}, 1), "Integer");
                alg_root_top = rt_base;
                return ret_223;
            }
        }
        alg_root_top = rt_551;
    }
    Value ret_224 = alg_property(v_this, "TryDepth");
    alg_root_top = rt_base;
    return ret_224;
    Value ret_225 = alg_nil();
    alg_root_top = rt_base;
    return ret_225;
}

static Value m_cemitter_gototarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    Value ret_226 = alg_add(alg_string("lg_"), alg_invoke(v_this, "Escaped", (Value[]){f_foldcase(NULL, (Value[]){v_thelabel}, 1)}, 1));
    alg_root_top = rt_base;
    return ret_226;
    Value ret_227 = alg_nil();
    alg_root_top = rt_base;
    return ret_227;
}

static Value m_cemitter_visitgotostmt_1_gotostmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "GotoStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    (void)(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_invoke(v_this, "DepthOfLabel", (Value[]){alg_property(v_thestmt, "Label")}, 1)}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("goto "), alg_invoke(v_this, "GotoTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1)), alg_char_value(59))}, 1));
    Value ret_228 = alg_nil();
    alg_root_top = rt_base;
    return ret_228;
}

static Value m_cemitter_visitblockstmt_1_blockstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "BlockStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_mark;
    alg_root(&v_mark, 1);
    Value v_enclosingtop = alg_property(v_this, "AtTopLevel");
    (void)v_enclosingtop;
    alg_root(&v_enclosingtop, 1);
    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    Value v_roots = alg_invoke(v_this, "OpenRoots", (Value[]){alg_invoke(v_this, "DeclaresLocal", (Value[]){alg_property(v_thestmt, "Statements")}, 1)}, 1);
    (void)v_roots;
    alg_root(&v_roots, 1);
    (void)(alg_invoke(v_this, "HoistCells", (Value[]){alg_property(v_thestmt, "Statements")}, 1));
    (void)(alg_invoke(v_this, "PushLabels", (Value[]){alg_property(v_thestmt, "Statements")}, 1));
    {
        int32_t rt_552 = alg_root_top;
        Value loop_229 = alg_iterable(alg_property(v_thestmt, "Statements"));
        (void)loop_229;
        alg_root(&loop_229, 1);
        for (int32_t at_229 = 0; at_229 < alg_iterable_count(loop_229); at_229++) {
            int32_t rt_553 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_229, at_229);
            (void)v_statement;
            alg_root(&v_statement, 1);
            (void)(alg_invoke(v_this, "Execute", (Value[]){v_statement}, 1));
            alg_root_top = rt_553;
        }
        alg_root_top = rt_552;
    }
    (void)(alg_invoke(v_this, "PopLabels", NULL, 0));
    (void)(alg_invoke(v_this, "CloseRoots", (Value[]){v_roots}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_set_property(v_this, "AtTopLevel", v_enclosingtop));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1));
    Value ret_230 = alg_nil();
    alg_root_top = rt_base;
    return ret_230;
}

static Value m_cemitter_visitifstmt_1_ifstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "IfStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    (void)(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_property(v_thestmt, "ThenBranch")}, 1));
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "ElseBranch"), alg_nil()))) {
        (void)(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_property(v_thestmt, "ElseBranch")}, 1));
    }
    Value v_mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_mark;
    alg_root(&v_mark, 1);
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("if (alg_truthy("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Condition")}, 1)), alg_string(")) {"))}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "ThenBranch")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1));
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "ElseBranch"), alg_nil()))) {
        {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("} else {")}, 1));
            (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
            (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "ElseBranch")}, 1));
            (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
            (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1));
        }
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    Value ret_231 = alg_nil();
    alg_root_top = rt_base;
    return ret_231;
}

static Value m_cemitter_visitwhilestmt_1_whilestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "WhileStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    (void)(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    Value v_mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_mark;
    alg_root(&v_mark, 1);
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Increment"), alg_nil()))) {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("for (; alg_truthy("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Condition")}, 1)), alg_string("); ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Increment")}, 1)), alg_string(") {"))}, 1));
    } else {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("while (alg_truthy("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Condition")}, 1)), alg_string(")) {"))}, 1));
    }
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    Value v_enclosingloopdepth = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosingloopdepth;
    alg_root(&v_enclosingloopdepth, 1);
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_property(v_this, "TryDepth")));
    (void)(alg_invoke(alg_property(v_this, "LoopLabels"), "Add", (Value[]){alg_property(v_thestmt, "Label")}, 1));
    (void)(alg_invoke(alg_property(v_this, "LoopDepths"), "Add", (Value[]){alg_property(v_this, "TryDepth")}, 1));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    (void)(alg_invoke(alg_property(v_this, "LoopLabels"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LoopLabels"), "Length"), alg_int(1))}, 1));
    (void)(alg_invoke(alg_property(v_this, "LoopDepths"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LoopDepths"), "Length"), alg_int(1))}, 1));
    (void)(alg_set_property(v_this, "LoopTryDepth", v_enclosingloopdepth));
    (void)(alg_invoke(v_this, "EmitContinueTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "EmitBreakTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1));
    Value ret_232 = alg_nil();
    alg_root_top = rt_base;
    return ret_232;
}

static Value m_cemitter_emitcontinuetarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    if (alg_truthy(alg_equal(v_thelabel, alg_string("")))) {
        Value ret_233 = alg_nil();
        alg_root_top = rt_base;
        return ret_233;
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Jumped"), "Contains", (Value[]){alg_invoke(v_this, "ContinueTarget", (Value[]){v_thelabel}, 1)}, 1)))) {
        Value ret_234 = alg_nil();
        alg_root_top = rt_base;
        return ret_234;
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_invoke(v_this, "ContinueTarget", (Value[]){v_thelabel}, 1), alg_string(": ;"))}, 1));
    Value ret_235 = alg_nil();
    alg_root_top = rt_base;
    return ret_235;
}

static Value m_cemitter_emitbreaktarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    if (alg_truthy(alg_equal(v_thelabel, alg_string("")))) {
        Value ret_236 = alg_nil();
        alg_root_top = rt_base;
        return ret_236;
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Jumped"), "Contains", (Value[]){alg_invoke(v_this, "BreakTarget", (Value[]){v_thelabel}, 1)}, 1)))) {
        Value ret_237 = alg_nil();
        alg_root_top = rt_base;
        return ret_237;
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_invoke(v_this, "BreakTarget", (Value[]){v_thelabel}, 1), alg_string(": ;"))}, 1));
    Value ret_238 = alg_nil();
    alg_root_top = rt_base;
    return ret_238;
}

static Value m_cemitter_visitreturnstmt_1_returnstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ReturnStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    (void)((v_value = alg_string("alg_nil()")));
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Value"), alg_nil()))) {
        (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Value")}, 1)));
    }
    if (alg_truthy(alg_equal(alg_property(v_this, "TryDepth"), alg_int(0)))) {
        {
            (void)(alg_invoke(v_this, "EmitReturn", (Value[]){v_value}, 1));
            Value ret_239 = alg_nil();
            alg_root_top = rt_base;
            return ret_239;
        }
    }
    Value v_slot = alg_add(alg_string("ret_"), alg_str(alg_property(v_this, "Loops")));
    (void)v_slot;
    alg_root(&v_slot, 1);
    (void)(alg_set_property(v_this, "Loops", alg_add(alg_property(v_this, "Loops"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_invoke(v_this, "Local", NULL, 0), v_slot), alg_string(" = ")), v_value), alg_char_value(59))}, 1));
    {
        int32_t rt_554 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_this, "TryDepth"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("alg_pop_frame();")}, 1));
        }
        alg_root_top = rt_554;
    }
    if (alg_truthy(alg_not_equal(alg_property(v_this, "FrameRoots"), alg_string("")))) {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_root_top = "), alg_property(v_this, "FrameRoots")), alg_char_value(59))}, 1));
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("return "), v_slot), alg_char_value(59))}, 1));
    Value ret_240 = alg_nil();
    alg_root_top = rt_base;
    return ret_240;
}

static Value m_cemitter_emitforeign_1_functionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "FunctionStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    (void)((v_symbol = alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1)));
    Value v_table = alg_invoke(v_this, "TypeTable", (Value[]){v_symbol, alg_invoke(v_this, "ParameterTable", (Value[]){v_thestmt}, 1)}, 2);
    (void)v_table;
    alg_root(&v_table, 1);
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("Value "), v_symbol), alg_string("(Value **cells, Value *args, int32_t count) {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)cells; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    return alg_foreign("), f_quotec(NULL, (Value[]){alg_str(alg_property(v_thestmt, "Symbol"))}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(v_thestmt, "Library"))}, 1)), alg_string(", ")), v_table), alg_string(", ")), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(v_thestmt, "ReturnType"))}, 1)), alg_string(", args);")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_char_value(125), alg_char_value(10)), alg_char_value(10))}, 1));
    Value v_name = alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"));
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_not(alg_property(v_this, "AtTopLevel")))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_name}, 1));
            (void)(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1), alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_closure("), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string(", ")), v_symbol), alg_string(", NULL, 0, ")), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), alg_string(", ")), v_table), alg_char_value(41))}, 2));
            Value ret_241 = alg_nil();
            alg_root_top = rt_base;
            return ret_241;
        }
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1))) {
        {
            if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)}, 1)))) {
                {
                    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){alg_invoke(v_this, "SetName", (Value[]){v_name}, 1), v_name}, 2));
                    (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)), alg_string(" = alg_overloads(")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                }
            }
            (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_overload("), alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)), alg_string(", ")), v_symbol), alg_string(", ")), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), alg_string(", ")), v_table), alg_string(");")), alg_char_value(10))}, 1));
            Value ret_242 = alg_nil();
            alg_root_top = rt_base;
            return ret_242;
        }
    }
    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1), v_name}, 2));
    (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1)), alg_string(" = alg_closure(")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string(", ")), v_symbol), alg_string(", NULL, 0, ")), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), alg_string(", ")), v_table), alg_string(");")), alg_char_value(10))}, 1));
    Value ret_243 = alg_nil();
    alg_root_top = rt_base;
    return ret_243;
}

static Value m_cemitter_visitfunctionstmt_1_functionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "FunctionStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_enclosinglocals = alg_nil();
    (void)v_enclosinglocals;
    alg_root(&v_enclosinglocals, 1);
    Value v_enclosingtop = alg_nil();
    (void)v_enclosingtop;
    alg_root(&v_enclosingtop, 1);
    Value v_enclosingdepth = alg_nil();
    (void)v_enclosingdepth;
    alg_root(&v_enclosingdepth, 1);
    if (alg_truthy(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1))) {
        {
            if (alg_truthy(alg_property(v_this, "EmitTests"))) {
                (void)(alg_invoke(v_this, "EmitTest", (Value[]){v_thestmt}, 1));
            }
            Value ret_244 = alg_nil();
            alg_root_top = rt_base;
            return ret_244;
        }
    }
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Symbol"), alg_string("")))) {
        {
            (void)(alg_invoke(v_this, "EmitForeign", (Value[]){v_thestmt}, 1));
            Value ret_245 = alg_nil();
            alg_root_top = rt_base;
            return ret_245;
        }
    }
    Value v_nested = alg_not(alg_property(v_this, "AtTopLevel"));
    (void)v_nested;
    alg_root(&v_nested, 1);
    Value v_enclosingsymbol = alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1);
    (void)v_enclosingsymbol;
    alg_root(&v_enclosingsymbol, 1);
    (void)((v_enclosinglocals = alg_property(v_this, "Locals")));
    (void)((v_enclosingtop = alg_property(v_this, "AtTopLevel")));
    (void)((v_enclosingdepth = alg_property(v_this, "Depth")));
    Value v_enclosingboxed = alg_property(v_this, "Boxed");
    (void)v_enclosingboxed;
    alg_root(&v_enclosingboxed, 1);
    Value v_enclosingcaptured = alg_property(v_this, "Captured");
    (void)v_enclosingcaptured;
    alg_root(&v_enclosingcaptured, 1);
    Value v_enclosingcells = alg_property(v_this, "Cells");
    (void)v_enclosingcells;
    alg_root(&v_enclosingcells, 1);
    Value v_enclosingnested = alg_property(v_this, "InsideNested");
    (void)v_enclosingnested;
    alg_root(&v_enclosingnested, 1);
    Value v_enclosingnestedin = alg_property(v_this, "NestedIn");
    (void)v_enclosingnestedin;
    alg_root(&v_enclosingnestedin, 1);
    (void)(alg_set_property(v_this, "NestedIn", v_enclosingsymbol));
    (void)(alg_set_property(v_this, "Locals", alg_list()));
    Value v_inherited = alg_invoke(v_this, "VisibleCells", (Value[]){alg_property(v_this, "Captured"), v_enclosingcells}, 2);
    (void)v_inherited;
    alg_root(&v_inherited, 1);
    if (alg_truthy(v_nested)) {
        {
            int32_t rt_555 = alg_root_top;
            Value v_index = alg_map();
            (void)v_index;
            alg_root(&v_index, 1);
            {
                int32_t rt_556 = alg_root_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less(v_i, alg_property(v_inherited, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(v_index, "Put", (Value[]){alg_str(alg_subscript_get(v_inherited, v_i)), v_i}, 2));
                }
                alg_root_top = rt_556;
            }
            (void)(alg_set_property(v_this, "Captured", v_index));
            (void)(alg_set_property(v_this, "InsideNested", alg_bool(true)));
            alg_root_top = rt_555;
        }
    } else {
        (void)(alg_set_property(v_this, "Captured", alg_map()));
    }
    (void)(alg_set_property(v_this, "Cells", alg_list()));
    Value v_enclosingvolatiles = alg_property(v_this, "Volatiles");
    (void)v_enclosingvolatiles;
    alg_root(&v_enclosingvolatiles, 1);
    (void)(alg_set_property(v_this, "Volatiles", alg_invoke(v_this, "ContainsTry", (Value[]){alg_property(v_thestmt, "Body")}, 1)));
    Value v_enclosingtrydepth = alg_property(v_this, "TryDepth");
    (void)v_enclosingtrydepth;
    alg_root(&v_enclosingtrydepth, 1);
    Value v_enclosinglooptry = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosinglooptry;
    alg_root(&v_enclosinglooptry, 1);
    (void)(alg_set_property(v_this, "TryDepth", alg_int(0)));
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_int(0)));
    (void)(alg_set_property(v_this, "Boxed", alg_list()));
    if (alg_truthy(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_property(v_thestmt, "Body")}, 1))) {
        (void)(alg_set_property(v_this, "Boxed", alg_invoke(v_this, "BoundNames", (Value[]){v_thestmt}, 1)));
    }
    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
    Value v_enclosingtarget = alg_property(v_this, "Target");
    (void)v_enclosingtarget;
    alg_root(&v_enclosingtarget, 1);
    Value v_enclosingbody = alg_property(v_this, "Body");
    (void)v_enclosingbody;
    alg_root(&v_enclosingbody, 1);
    (void)(alg_set_property(v_this, "Target", alg_string("body")));
    (void)(alg_set_property(v_this, "Body", alg_buffer(alg_int(0))));
    (void)(alg_set_property(v_this, "Depth", alg_int(1)));
    if (alg_truthy(alg_not(v_nested))) {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_arity(count, "), alg_str(alg_property(alg_property(v_thestmt, "Params"), "Length"))), alg_string(");"))}, 1));
    }
    Value v_enclosingframeroots = alg_property(v_this, "FrameRoots");
    (void)v_enclosingframeroots;
    alg_root(&v_enclosingframeroots, 1);
    (void)(alg_set_property(v_this, "FrameRoots", alg_string("rt_base")));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("int32_t "), alg_property(v_this, "FrameRoots")), alg_string(" = alg_root_top;"))}, 1));
    (void)(alg_invoke(v_this, "Root", (Value[]){alg_string("args"), alg_string("count")}, 2));
    if (alg_truthy(v_nested)) {
        {
            int32_t rt_557 = alg_root_top;
            Value v_i = alg_int(0);
            (void)v_i;
            alg_root(&v_i, 1);
            for (; alg_truthy(alg_less(v_i, alg_property(v_inherited, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                (void)(alg_invoke(v_this, "Root", (Value[]){alg_add(alg_add(alg_string("cells["), alg_str(v_i)), alg_char_value(93)), alg_char_value(49)}, 2));
            }
            alg_root_top = rt_557;
        }
    }
    {
        int32_t rt_558 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_thestmt, "Params"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                int32_t rt_559 = alg_root_top;
                Value v_paramname = alg_str(alg_property(alg_subscript_get(alg_property(v_thestmt, "Params"), v_i), "Lexeme"));
                (void)v_paramname;
                alg_root(&v_paramname, 1);
                (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_paramname}, 1));
                if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_paramname}, 1))) {
                    {
                        int32_t rt_560 = alg_root_top;
                        Value v_qualifier = alg_string("Value *");
                        (void)v_qualifier;
                        alg_root(&v_qualifier, 1);
                        if (alg_truthy(alg_property(v_this, "Volatiles"))) {
                            (void)((v_qualifier = alg_string("Value *volatile ")));
                        }
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(v_qualifier, alg_invoke(v_this, "Cell", (Value[]){v_paramname}, 1)), alg_string(" = alg_cell(")), alg_invoke(v_this, "BoundArgument", (Value[]){alg_property(v_thestmt, "Params"), alg_property(v_thestmt, "ParamTypes"), v_i}, 3)), alg_string(");"))}, 1));
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("(void)"), alg_invoke(v_this, "Cell", (Value[]){v_paramname}, 1)), alg_char_value(59))}, 1));
                        (void)(alg_invoke(alg_property(v_this, "Cells"), "Add", (Value[]){v_paramname}, 1));
                        alg_root_top = rt_560;
                    }
                } else {
                    {
                        (void)(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_invoke(v_this, "VariableName", (Value[]){v_paramname}, 1), alg_invoke(v_this, "BoundArgument", (Value[]){alg_property(v_thestmt, "Params"), alg_property(v_thestmt, "ParamTypes"), v_i}, 3)}, 2));
                    }
                }
                alg_root_top = rt_559;
            }
        }
        alg_root_top = rt_558;
    }
    (void)(alg_invoke(v_this, "HoistCells", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    (void)(alg_invoke(v_this, "PushLabels", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    {
        int32_t rt_561 = alg_root_top;
        Value loop_246 = alg_iterable(alg_property(v_thestmt, "Body"));
        (void)loop_246;
        alg_root(&loop_246, 1);
        for (int32_t at_246 = 0; at_246 < alg_iterable_count(loop_246); at_246++) {
            int32_t rt_562 = alg_root_top;
            Value v_each = alg_iterable_at(loop_246, at_246);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_invoke(v_this, "Execute", (Value[]){v_each}, 1));
            alg_root_top = rt_562;
        }
        alg_root_top = rt_561;
    }
    (void)(alg_invoke(v_this, "PopLabels", NULL, 0));
    (void)(alg_invoke(v_this, "EmitReturn", (Value[]){alg_string("alg_nil()")}, 1));
    Value v_written = alg_property(alg_property(v_this, "Body"), "Text");
    (void)v_written;
    alg_root(&v_written, 1);
    (void)(alg_set_property(v_this, "Target", v_enclosingtarget));
    (void)(alg_set_property(v_this, "Body", v_enclosingbody));
    (void)(alg_set_property(v_this, "NestedIn", v_enclosingnestedin));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_invoke(v_this, "Prototype", (Value[]){v_thestmt}, 1), alg_string(" {")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    (void)cells; (void)args; (void)count;"), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_written}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_char_value(125), alg_char_value(10)), alg_char_value(10))}, 1));
    Value v_capturedcells = v_inherited;
    (void)v_capturedcells;
    alg_root(&v_capturedcells, 1);
    (void)(alg_set_property(v_this, "FrameRoots", v_enclosingframeroots));
    (void)(alg_set_property(v_this, "Depth", v_enclosingdepth));
    (void)(alg_set_property(v_this, "AtTopLevel", v_enclosingtop));
    (void)(alg_set_property(v_this, "Locals", v_enclosinglocals));
    (void)(alg_set_property(v_this, "Volatiles", v_enclosingvolatiles));
    (void)(alg_set_property(v_this, "Boxed", v_enclosingboxed));
    (void)(alg_set_property(v_this, "Captured", v_enclosingcaptured));
    (void)(alg_set_property(v_this, "Cells", v_enclosingcells));
    (void)(alg_set_property(v_this, "TryDepth", v_enclosingtrydepth));
    (void)(alg_set_property(v_this, "LoopTryDepth", v_enclosinglooptry));
    (void)(alg_set_property(v_this, "InsideNested", v_enclosingnested));
    Value v_name = alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"));
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(v_nested)) {
        {
            (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_name}, 1));
            (void)(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1), alg_invoke(v_this, "ClosureOf", (Value[]){v_thestmt, v_capturedcells}, 2)}, 2));
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
    Value ret_247 = alg_nil();
    alg_root_top = rt_base;
    return ret_247;
}

static Value m_cemitter_typetable_2_string_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_symbol = alg_widen(args[0], "String");
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    Value v_types = alg_widen(args[1], "List");
    (void)v_types;
    alg_root(&v_types, 1);
    Value v_table = alg_nil();
    (void)v_table;
    alg_root(&v_table, 1);
    if (alg_truthy(alg_equal(alg_property(v_types, "Length"), alg_int(0)))) {
        Value ret_248 = alg_string("NULL");
        alg_root_top = rt_base;
        return ret_248;
    }
    (void)((v_table = alg_add(alg_string("t_"), v_symbol)));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Tables"), "Contains", (Value[]){v_table}, 1))) {
        Value ret_249 = v_table;
        alg_root_top = rt_base;
        return ret_249;
    }
    (void)(alg_invoke(alg_property(v_this, "Tables"), "Add", (Value[]){v_table}, 1));
    Value v_quoted = alg_string("");
    (void)v_quoted;
    alg_root(&v_quoted, 1);
    {
        int32_t rt_563 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_types, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                    (void)((v_quoted = alg_add(v_quoted, alg_string(", "))));
                }
                (void)((v_quoted = alg_add(v_quoted, f_quotec(NULL, (Value[]){alg_str(alg_subscript_get(v_types, v_i))}, 1))));
            }
        }
        alg_root_top = rt_563;
    }
    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("static const char *"), v_table), alg_string("[] = { ")), v_quoted), alg_string(" };")), alg_char_value(10))}, 1));
    Value ret_250 = v_table;
    alg_root_top = rt_base;
    return ret_250;
    Value ret_251 = alg_nil();
    alg_root_top = rt_base;
    return ret_251;
}

static Value m_cemitter_visitliteral_1_literalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "LiteralExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    (void)((v_value = alg_property(v_theexpr, "Value")));
    if (alg_truthy(alg_equal(v_value, alg_nil()))) {
        Value ret_252 = alg_string("alg_nil()");
        alg_root_top = rt_base;
        return ret_252;
    }
    if (alg_truthy(alg_equal(v_value, alg_bool(true)))) {
        Value ret_253 = alg_string("alg_bool(true)");
        alg_root_top = rt_base;
        return ret_253;
    }
    if (alg_truthy(alg_equal(v_value, alg_bool(false)))) {
        Value ret_254 = alg_string("alg_bool(false)");
        alg_root_top = rt_base;
        return ret_254;
    }
    if (alg_truthy(alg_is(v_value, "Integer"))) {
        {
            if (alg_truthy((or_48 = alg_greater(v_value, alg_int(9223372036854775807)), alg_truthy(or_48) ? or_48 : alg_less(v_value, alg_negate(alg_int(9223372036854775807)))))) {
                Value ret_255 = alg_add(alg_add(alg_string("alg_integer("), f_quotec(NULL, (Value[]){alg_str(v_value)}, 1)), alg_char_value(41));
                alg_root_top = rt_base;
                return ret_255;
            }
            Value ret_256 = alg_add(alg_add(alg_string("alg_int("), alg_str(v_value)), alg_char_value(41));
            alg_root_top = rt_base;
            return ret_256;
        }
    }
    if (alg_truthy(alg_is(v_value, "Double"))) {
        Value ret_257 = alg_add(alg_add(alg_string("alg_double("), alg_str(v_value)), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_257;
    }
    if (alg_truthy(alg_is(v_value, "String"))) {
        Value ret_258 = alg_add(alg_add(alg_string("alg_string("), f_quotec(NULL, (Value[]){alg_str(v_value)}, 1)), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_258;
    }
    if (alg_truthy(alg_is(v_value, "Char"))) {
        Value ret_259 = alg_add(alg_add(alg_string("alg_char_value("), alg_str(alg_ord(v_value))), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_259;
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_string("A literal of type "), f_typenameof(NULL, (Value[]){v_value}, 1))}, 1));
    Value ret_260 = alg_nil();
    alg_root_top = rt_base;
    return ret_260;
}

static Value m_cemitter_visitvariableexpr_1_variableexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "VariableExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    (void)((v_name = alg_invoke(v_this, "Spelled", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1)));
    if (alg_truthy((or_49 = alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1), alg_truthy(or_49) ? or_49 : alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_261 = alg_invoke(v_this, "Read", (Value[]){v_name}, 1);
        alg_root_top = rt_base;
        return ret_261;
    }
    if (alg_truthy((or_51 = (or_50 = alg_not_equal(alg_property(v_this, "CurrentClass"), alg_string("")), !alg_truthy(or_50) ? or_50 : alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_51) ? or_51 : alg_invoke(alg_property(v_this, "VisibleFields"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1)))) {
        Value ret_262 = alg_add(alg_add(alg_add(alg_add(alg_string("alg_property("), alg_invoke(v_this, "ThisRef", NULL, 0)), alg_string(", ")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_262;
    }
    if (alg_truthy((or_52 = alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)), !alg_truthy(or_52) ? or_52 : alg_not(alg_invoke(v_this, "OwnGlobal", (Value[]){v_name}, 1))))) {
        {
            if (alg_truthy(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Contains", (Value[]){v_name}, 1))) {
                Value ret_263 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "AmbiguousMessage", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme")), alg_str(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Get", (Value[]){v_name}, 1))}, 2)}, 1)), alg_string("), alg_nil())"));
                alg_root_top = rt_base;
                return ret_263;
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Contains", (Value[]){v_name}, 1))) {
                Value ret_264 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "AmbiguousMessage", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme")), alg_str(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Get", (Value[]){v_name}, 1))}, 2)}, 1)), alg_string("), alg_nil())"));
                alg_root_top = rt_base;
                return ret_264;
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_name}, 1))) {
                Value ret_265 = alg_invoke(v_this, "EnumMemberName", (Value[]){alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_name}, 1)), v_name}, 2);
                alg_root_top = rt_base;
                return ret_265;
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "EnumTypes"), "Contains", (Value[]){v_name}, 1))) {
                Value ret_266 = alg_invoke(v_this, "EnumTypeName", (Value[]){v_name}, 1);
                alg_root_top = rt_base;
                return ret_266;
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
                Value ret_267 = alg_add(alg_add(alg_string("alg_singleton("), alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)), alg_char_value(41));
                alg_root_top = rt_base;
                return ret_267;
            }
            if (alg_truthy(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1))) {
                Value ret_268 = alg_invoke(v_this, "SubprogramValue", (Value[]){v_name}, 1);
                alg_root_top = rt_base;
                return ret_268;
            }
        }
    }
    (void)(alg_invoke(v_this, "Unreachable", (Value[]){v_name}, 1));
    if (alg_truthy((or_55 = (or_54 = (or_53 = alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)), !alg_truthy(or_53) ? or_53 : alg_not(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_54) ? or_54 : alg_not(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))), !alg_truthy(or_55) ? or_55 : alg_not(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))))) {
        Value ret_269 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "MissingName", (Value[]){v_name}, 1)}, 1)), alg_string("), alg_nil())"));
        alg_root_top = rt_base;
        return ret_269;
    }
    Value ret_270 = alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)}, 2);
    alg_root_top = rt_base;
    return ret_270;
    Value ret_271 = alg_nil();
    alg_root_top = rt_base;
    return ret_271;
}

static Value m_cemitter_guarded_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_text = alg_widen(args[1], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1))) {
        Value ret_272 = v_text;
        alg_root_top = rt_base;
        return ret_272;
    }
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_273 = v_text;
        alg_root_top = rt_base;
        return ret_273;
    }
    Value ret_274 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("(alg_declared("), alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string("), ")), v_text), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_274;
    Value ret_275 = alg_nil();
    alg_root_top = rt_base;
    return ret_275;
}

static Value m_cemitter_ownglobal_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "GlobalsIn"), "Contains", (Value[]){alg_property(v_this, "UnitName")}, 1)))) {
        Value ret_276 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_276;
    }
    Value ret_277 = alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "GlobalsIn"), "Get", (Value[]){alg_property(v_this, "UnitName")}, 1), "Set")), "Contains", (Value[]){v_name}, 1);
    alg_root_top = rt_base;
    return ret_277;
    Value ret_278 = alg_nil();
    alg_root_top = rt_base;
    return ret_278;
}

static Value m_cemitter_visiblesubprogram_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value ret_279 = alg_invoke(alg_property(v_this, "VisibleDeclared"), "Contains", (Value[]){v_name}, 1);
    alg_root_top = rt_base;
    return ret_279;
    Value ret_280 = alg_nil();
    alg_root_top = rt_base;
    return ret_280;
}

static Value m_cemitter_missingname_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_units = alg_nil();
    (void)v_units;
    alg_root(&v_units, 1);
    (void)((v_units = alg_invoke(alg_property(v_this, "UnitExports"), "Keys", NULL, 0)));
    {
        int32_t rt_564 = alg_root_top;
        Value loop_281 = alg_iterable(v_units);
        (void)loop_281;
        alg_root(&loop_281, 1);
        for (int32_t at_281 = 0; at_281 < alg_iterable_count(loop_281); at_281++) {
            int32_t rt_565 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_281, at_281);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            if (alg_truthy(alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_theunit}, 1), "Set")), "Contains", (Value[]){v_name}, 1))) {
                Value ret_282 = alg_add(alg_add(alg_add(alg_add(alg_string("Undefined variable '"), v_name), alg_string("'. Unit '")), alg_str(v_theunit)), alg_string("' exports it; this file has no 'uses' for it."));
                alg_root_top = rt_base;
                return ret_282;
            }
            alg_root_top = rt_565;
        }
        alg_root_top = rt_564;
    }
    Value ret_283 = alg_add(alg_add(alg_string("Undefined variable '"), v_name), alg_string("'."));
    alg_root_top = rt_base;
    return ret_283;
    Value ret_284 = alg_nil();
    alg_root_top = rt_base;
    return ret_284;
}

static Value m_cemitter_spelled_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1))) {
        Value ret_285 = alg_str(v_name);
        alg_root_top = rt_base;
        return ret_285;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Canonical"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
        Value ret_286 = alg_str(alg_invoke(alg_property(v_this, "Canonical"), "Get", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1));
        alg_root_top = rt_base;
        return ret_286;
    }
    Value ret_287 = alg_str(v_name);
    alg_root_top = rt_base;
    return ret_287;
    Value ret_288 = alg_nil();
    alg_root_top = rt_base;
    return ret_288;
}

static Value m_cemitter_unreachable_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy(alg_not(alg_property(v_this, "InsideNested")))) {
        Value ret_289 = alg_nil();
        alg_root_top = rt_base;
        return ret_289;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1))) {
        Value ret_290 = alg_nil();
        alg_root_top = rt_base;
        return ret_290;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1))) {
        Value ret_291 = alg_nil();
        alg_root_top = rt_base;
        return ret_291;
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("Reading '"), v_name), alg_string("' from a nested function"))}, 1));
    Value ret_292 = alg_nil();
    alg_root_top = rt_base;
    return ret_292;
}

static Value m_cemitter_boundvalue_3_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_declared = args[0];
    (void)v_declared;
    alg_root(&v_declared, 1);
    Value v_value = alg_widen(args[1], "String");
    (void)v_value;
    alg_root(&v_value, 1);
    Value v_actual = args[2];
    (void)v_actual;
    alg_root(&v_actual, 1);
    if (alg_truthy((or_56 = alg_equal(alg_str(v_declared), alg_string("")), alg_truthy(or_56) ? or_56 : alg_equal(alg_str(v_declared), alg_string("Any"))))) {
        Value ret_293 = alg_str(v_value);
        alg_root_top = rt_base;
        return ret_293;
    }
    if (alg_truthy(alg_invoke(v_this, "Elidable", (Value[]){v_declared, v_actual}, 2))) {
        Value ret_294 = alg_str(v_value);
        alg_root_top = rt_base;
        return ret_294;
    }
    Value ret_295 = alg_add(alg_add(alg_add(alg_add(alg_string("alg_widen("), alg_str(v_value)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(v_declared)}, 1)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_295;
    Value ret_296 = alg_nil();
    alg_root_top = rt_base;
    return ret_296;
}

static Value m_cemitter_elidable_2(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_declared = args[0];
    (void)v_declared;
    alg_root(&v_declared, 1);
    Value v_actual = args[1];
    (void)v_actual;
    alg_root(&v_actual, 1);
    if (alg_truthy((or_57 = alg_equal(alg_str(v_actual), alg_string("")), alg_truthy(or_57) ? or_57 : alg_equal(alg_str(v_actual), alg_string("Any"))))) {
        Value ret_297 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_297;
    }
    if (alg_truthy(alg_not_equal(f_foldcase(NULL, (Value[]){v_declared}, 1), f_foldcase(NULL, (Value[]){v_actual}, 1)))) {
        Value ret_298 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_298;
    }
    Value ret_299 = alg_not(f_issubrange(NULL, (Value[]){v_declared}, 1));
    alg_root_top = rt_base;
    return ret_299;
    Value ret_300 = alg_nil();
    alg_root_top = rt_base;
    return ret_300;
}

static Value m_cemitter_visitassignexpr_1_assignexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "AssignExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    (void)((v_name = alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))));
    Value v_written = alg_invoke(v_this, "BoundValue", (Value[]){alg_property(v_theexpr, "Declared"), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1), alg_property(v_theexpr, "Actual")}, 3);
    (void)v_written;
    alg_root(&v_written, 1);
    if (alg_truthy((or_58 = alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1), alg_truthy(or_58) ? or_58 : alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_301 = alg_add(alg_add(alg_add(alg_add(alg_char_value(40), alg_invoke(v_this, "Read", (Value[]){v_name}, 1)), alg_string(" = ")), v_written), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_301;
    }
    if (alg_truthy((or_60 = (or_59 = alg_not_equal(alg_property(v_this, "CurrentClass"), alg_string("")), !alg_truthy(or_59) ? or_59 : alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_60) ? or_60 : alg_invoke(alg_property(v_this, "VisibleFields"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1)))) {
        Value ret_302 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_set_property("), alg_invoke(v_this, "ThisRef", NULL, 0)), alg_string(", ")), f_quotec(NULL, (Value[]){v_name}, 1)), alg_string(", ")), v_written), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_302;
    }
    (void)(alg_invoke(v_this, "Unreachable", (Value[]){v_name}, 1));
    Value ret_303 = alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_add(alg_add(alg_add(alg_add(alg_char_value(40), alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), alg_string(" = ")), v_written), alg_char_value(41))}, 2);
    alg_root_top = rt_base;
    return ret_303;
    Value ret_304 = alg_nil();
    alg_root_top = rt_base;
    return ret_304;
}

static Value m_cemitter_visitgrouping_1_groupingexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GroupingExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value ret_305 = alg_add(alg_add(alg_char_value(40), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Expression")}, 1)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_305;
    Value ret_306 = alg_nil();
    alg_root_top = rt_base;
    return ret_306;
}

static Value m_cemitter_visitisexpr_1_isexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "IsExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value ret_307 = alg_add(alg_add(alg_add(alg_add(alg_string("alg_is("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){f_canonicaltype(NULL, (Value[]){alg_property(alg_property(v_theexpr, "TypeName"), "Lexeme")}, 1)}, 1)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_307;
    Value ret_308 = alg_nil();
    alg_root_top = rt_base;
    return ret_308;
}

static Value m_cemitter_visitunary_1_unaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "UnaryExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_operand = alg_nil();
    (void)v_operand;
    alg_root(&v_operand, 1);
    (void)((v_operand = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Right")}, 1)));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVminus))) {
        Value ret_309 = alg_add(alg_add(alg_string("alg_negate("), v_operand), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_309;
    } else {
        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVnot))) {
            Value ret_310 = alg_add(alg_add(alg_string("alg_not("), v_operand), alg_char_value(41));
            alg_root_top = rt_base;
            return ret_310;
        } else {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVtilde))) {
                Value ret_311 = alg_add(alg_add(alg_string("alg_bit_not("), v_operand), alg_char_value(41));
                alg_root_top = rt_base;
                return ret_311;
            }
        }
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("Unary '"), alg_str(alg_property(alg_property(v_theexpr, "Op"), "Lexeme"))), alg_char_value(39))}, 1));
    Value ret_312 = alg_nil();
    alg_root_top = rt_base;
    return ret_312;
}

static Value m_cemitter_visitbinary_1_binaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "BinaryExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_left = alg_nil();
    (void)v_left;
    alg_root(&v_left, 1);
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    Value v_call = alg_nil();
    (void)v_call;
    alg_root(&v_call, 1);
    (void)((v_left = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Left")}, 1)));
    (void)((v_right = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Right")}, 1)));
    (void)((v_call = alg_string("")));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVplus))) {
        (void)((v_call = alg_string("alg_add")));
    } else {
        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVminus))) {
            (void)((v_call = alg_string("alg_subtract")));
        } else {
            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVstar))) {
                (void)((v_call = alg_string("alg_multiply")));
            } else {
                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVslash))) {
                    (void)((v_call = alg_string("alg_divide")));
                } else {
                    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVdiv))) {
                        (void)((v_call = alg_string("alg_div_int")));
                    } else {
                        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVmod))) {
                            (void)((v_call = alg_string("alg_mod")));
                        } else {
                            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVgreater))) {
                                (void)((v_call = alg_string("alg_greater")));
                            } else {
                                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVgreaterVequal))) {
                                    (void)((v_call = alg_string("alg_greater_equal")));
                                } else {
                                    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVless))) {
                                        (void)((v_call = alg_string("alg_less")));
                                    } else {
                                        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVlessVequal))) {
                                            (void)((v_call = alg_string("alg_less_equal")));
                                        } else {
                                            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVequal))) {
                                                (void)((v_call = alg_string("alg_equal")));
                                            } else {
                                                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVnotVequal))) {
                                                    (void)((v_call = alg_string("alg_not_equal")));
                                                } else {
                                                    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVin))) {
                                                        (void)((v_call = alg_string("alg_in")));
                                                    } else {
                                                        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVampersand))) {
                                                            (void)((v_call = alg_string("alg_bit_and")));
                                                        } else {
                                                            if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVpipe))) {
                                                                (void)((v_call = alg_string("alg_bit_or")));
                                                            } else {
                                                                if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVcaret))) {
                                                                    (void)((v_call = alg_string("alg_bit_xor")));
                                                                } else {
                                                                    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVshiftVleft))) {
                                                                        (void)((v_call = alg_string("alg_shift_left")));
                                                                    } else {
                                                                        if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVshiftVright))) {
                                                                            (void)((v_call = alg_string("alg_shift_right")));
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
                        }
                    }
                }
            }
        }
    }
    if (alg_truthy(alg_equal(v_call, alg_string("")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("Binary '"), alg_str(alg_property(alg_property(v_theexpr, "Op"), "Lexeme"))), alg_char_value(39))}, 1));
    }
    Value ret_313 = alg_add(alg_add(alg_add(alg_add(alg_add(v_call, alg_char_value(40)), v_left), alg_string(", ")), v_right), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_313;
    Value ret_314 = alg_nil();
    alg_root_top = rt_base;
    return ret_314;
}

static Value m_cemitter_builtincounts_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_counts = alg_nil();
    (void)v_counts;
    alg_root(&v_counts, 1);
    (void)((v_counts = alg_list()));
    {
        int32_t rt_566 = alg_root_top;
        Value v_k = alg_int(0);
        (void)v_k;
        alg_root(&v_k, 1);
        for (; alg_truthy(alg_less_equal(v_k, alg_int(3))); (v_k = alg_add(v_k, alg_int(1)))) {
            {
                int32_t rt_567 = alg_root_top;
                Value v_probe = alg_list();
                (void)v_probe;
                alg_root(&v_probe, 1);
                {
                    int32_t rt_568 = alg_root_top;
                    Value v_i = alg_int(0);
                    (void)v_i;
                    alg_root(&v_i, 1);
                    for (; alg_truthy(alg_less(v_i, v_k)); (v_i = alg_add(v_i, alg_int(1)))) {
                        (void)(alg_invoke(v_probe, "Add", (Value[]){alg_char_value(48)}, 1));
                    }
                    alg_root_top = rt_568;
                }
                if (alg_truthy(alg_not_equal(alg_invoke(v_this, "Builtin", (Value[]){v_name, v_k}, 2), alg_string("")))) {
                    (void)(alg_invoke(v_counts, "Add", (Value[]){v_k}, 1));
                } else {
                    if (alg_truthy(alg_not_equal(alg_invoke(v_this, "ConstructorFor", (Value[]){v_name, v_probe, alg_char_value(48)}, 3), alg_string("")))) {
                        (void)(alg_invoke(v_counts, "Add", (Value[]){v_k}, 1));
                    }
                }
                alg_root_top = rt_567;
            }
        }
        alg_root_top = rt_566;
    }
    Value ret_315 = v_counts;
    alg_root_top = rt_base;
    return ret_315;
    Value ret_316 = alg_nil();
    alg_root_top = rt_base;
    return ret_316;
}

static Value m_cemitter_countsmessage_2_list_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_counts = alg_widen(args[0], "List");
    (void)v_counts;
    alg_root(&v_counts, 1);
    Value v_got = alg_widen(args[1], "Integer");
    (void)v_got;
    alg_root(&v_got, 1);
    Value v_expected = alg_nil();
    (void)v_expected;
    alg_root(&v_expected, 1);
    (void)((v_expected = alg_string("")));
    {
        int32_t rt_569 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_counts, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                    {
                        if (alg_truthy(alg_equal(v_i, alg_subtract(alg_property(v_counts, "Length"), alg_int(1))))) {
                            (void)((v_expected = alg_add(v_expected, alg_string(" or "))));
                        } else {
                            (void)((v_expected = alg_add(v_expected, alg_string(", "))));
                        }
                    }
                }
                (void)((v_expected = alg_add(v_expected, alg_str(alg_subscript_get(v_counts, v_i)))));
            }
        }
        alg_root_top = rt_569;
    }
    Value ret_317 = alg_add(alg_add(alg_add(alg_add(alg_string("Expected "), v_expected), alg_string(" arguments but got ")), alg_str(v_got)), alg_char_value(46));
    alg_root_top = rt_base;
    return ret_317;
    Value ret_318 = alg_nil();
    alg_root_top = rt_base;
    return ret_318;
}

static Value m_cemitter_renamesof_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_unit = alg_widen(args[0], "String");
    (void)v_unit;
    alg_root(&v_unit, 1);
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_only = alg_nil();
    (void)v_only;
    alg_root(&v_only, 1);
    (void)((v_only = alg_map()));
    if (alg_truthy(alg_invoke(alg_property(v_this, "Renamed"), "Contains", (Value[]){v_name}, 1))) {
        (void)(alg_invoke(v_only, "Put", (Value[]){v_name, v_unit}, 2));
    }
    Value ret_319 = v_only;
    alg_root_top = rt_base;
    return ret_319;
    Value ret_320 = alg_nil();
    alg_root_top = rt_base;
    return ret_320;
}

static Value m_cemitter_markambiguousimport_3_string_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_first = alg_widen(args[1], "String");
    (void)v_first;
    alg_root(&v_first, 1);
    Value v_second = alg_widen(args[2], "String");
    (void)v_second;
    alg_root(&v_second, 1);
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Contains", (Value[]){v_name}, 1)))) {
        {
            (void)(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Put", (Value[]){v_name, alg_add(alg_add(v_first, alg_string(" or ")), v_second)}, 2));
            Value ret_321 = alg_nil();
            alg_root_top = rt_base;
            return ret_321;
        }
    }
    (void)(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Put", (Value[]){v_name, alg_add(alg_add(alg_str(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Get", (Value[]){v_name}, 1)), alg_string(" or ")), v_second)}, 2));
    Value ret_322 = alg_nil();
    alg_root_top = rt_base;
    return ret_322;
}

static Value m_cemitter_markambiguousmember_3_string_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_member = alg_widen(args[0], "String");
    (void)v_member;
    alg_root(&v_member, 1);
    Value v_first = alg_widen(args[1], "String");
    (void)v_first;
    alg_root(&v_first, 1);
    Value v_second = alg_widen(args[2], "String");
    (void)v_second;
    alg_root(&v_second, 1);
    if (alg_truthy(alg_not(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Contains", (Value[]){v_member}, 1)))) {
        {
            (void)(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Put", (Value[]){v_member, alg_add(alg_add(v_first, alg_string(" or ")), v_second)}, 2));
            Value ret_323 = alg_nil();
            alg_root_top = rt_base;
            return ret_323;
        }
    }
    (void)(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Put", (Value[]){v_member, alg_add(alg_add(alg_str(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Get", (Value[]){v_member}, 1)), alg_string(" or ")), v_second)}, 2));
    Value ret_324 = alg_nil();
    alg_root_top = rt_base;
    return ret_324;
}

static Value m_cemitter_ambiguousmessage_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_written = alg_widen(args[0], "String");
    (void)v_written;
    alg_root(&v_written, 1);
    Value v_owners = alg_widen(args[1], "String");
    (void)v_owners;
    alg_root(&v_owners, 1);
    Value ret_325 = alg_add(alg_add(alg_add(alg_add(alg_char_value(39), v_written), alg_string("' is ambiguous: ")), v_owners), alg_char_value(46));
    alg_root_top = rt_base;
    return ret_325;
    Value ret_326 = alg_nil();
    alg_root_top = rt_base;
    return ret_326;
}

static Value m_cemitter_isassertion_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    (void)((v_folded = f_foldcase(NULL, (Value[]){v_name}, 1)));
    Value ret_327 = (or_62 = (or_61 = alg_equal(v_folded, alg_string("asserttrue")), alg_truthy(or_61) ? or_61 : alg_equal(v_folded, alg_string("assertequal"))), alg_truthy(or_62) ? or_62 : alg_equal(v_folded, alg_string("fail")));
    alg_root_top = rt_base;
    return ret_327;
    Value ret_328 = alg_nil();
    alg_root_top = rt_base;
    return ret_328;
}

static Value m_cemitter_builtin_2_string_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_count = alg_widen(args[1], "Integer");
    (void)v_count;
    alg_root(&v_count, 1);
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    (void)((v_key = alg_add(alg_add(v_name, alg_char_value(47)), alg_str(v_count))));
    if (alg_truthy(alg_equal(v_key, alg_string("WriteLn/1")))) {
        Value ret_329 = alg_string("alg_writeln");
        alg_root_top = rt_base;
        return ret_329;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("WriteLn/0")))) {
        Value ret_330 = alg_string("alg_writeln_blank");
        alg_root_top = rt_base;
        return ret_330;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Write/1")))) {
        Value ret_331 = alg_string("alg_write");
        alg_root_top = rt_base;
        return ret_331;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Str/1")))) {
        Value ret_332 = alg_string("alg_str");
        alg_root_top = rt_base;
        return ret_332;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Str/2")))) {
        Value ret_333 = alg_string("alg_str_fixed");
        alg_root_top = rt_base;
        return ret_333;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Str/3")))) {
        Value ret_334 = alg_string("alg_str_padded");
        alg_root_top = rt_base;
        return ret_334;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Length/1")))) {
        Value ret_335 = alg_string("alg_text_length");
        alg_root_top = rt_base;
        return ret_335;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Copy/3")))) {
        Value ret_336 = alg_string("alg_copy");
        alg_root_top = rt_base;
        return ret_336;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Pos/2")))) {
        Value ret_337 = alg_string("alg_pos");
        alg_root_top = rt_base;
        return ret_337;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Pos/3")))) {
        Value ret_338 = alg_string("alg_pos_from");
        alg_root_top = rt_base;
        return ret_338;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("ToUpper/1")))) {
        Value ret_339 = alg_string("alg_to_upper");
        alg_root_top = rt_base;
        return ret_339;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("ToLower/1")))) {
        Value ret_340 = alg_string("alg_to_lower");
        alg_root_top = rt_base;
        return ret_340;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Char/1")))) {
        Value ret_341 = alg_string("alg_char");
        alg_root_top = rt_base;
        return ret_341;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Ord/1")))) {
        Value ret_342 = alg_string("alg_ord");
        alg_root_top = rt_base;
        return ret_342;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Val/1")))) {
        Value ret_343 = alg_string("alg_val");
        alg_root_top = rt_base;
        return ret_343;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Succ/1")))) {
        Value ret_344 = alg_string("alg_succ");
        alg_root_top = rt_base;
        return ret_344;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Pred/1")))) {
        Value ret_345 = alg_string("alg_pred");
        alg_root_top = rt_base;
        return ret_345;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Foreign/5")))) {
        Value ret_346 = alg_string("alg_foreign_call");
        alg_root_top = rt_base;
        return ret_346;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("clock/0")))) {
        Value ret_347 = alg_string("alg_clock");
        alg_root_top = rt_base;
        return ret_347;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Collect/0")))) {
        Value ret_348 = alg_string("alg_collected");
        alg_root_top = rt_base;
        return ret_348;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("Halt/1")))) {
        Value ret_349 = alg_string("alg_halt");
        alg_root_top = rt_base;
        return ret_349;
    }
    if (alg_truthy(alg_property(v_this, "EmitTests"))) {
        {
            if (alg_truthy(alg_equal(v_key, alg_string("AssertTrue/1")))) {
                Value ret_350 = alg_string("alg_assert_true");
                alg_root_top = rt_base;
                return ret_350;
            }
            if (alg_truthy(alg_equal(v_key, alg_string("AssertEqual/2")))) {
                Value ret_351 = alg_string("alg_assert_equal");
                alg_root_top = rt_base;
                return ret_351;
            }
            if (alg_truthy(alg_equal(v_key, alg_string("Fail/1")))) {
                Value ret_352 = alg_string("alg_assert_fail");
                alg_root_top = rt_base;
                return ret_352;
            }
        }
    }
    if (alg_truthy(alg_equal(v_key, alg_string("FileExists/1")))) {
        Value ret_353 = alg_string("alg_file_exists");
        alg_root_top = rt_base;
        return ret_353;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("MkDir/1")))) {
        Value ret_354 = alg_string("alg_mkdir");
        alg_root_top = rt_base;
        return ret_354;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("RmDir/1")))) {
        Value ret_355 = alg_string("alg_rmdir");
        alg_root_top = rt_base;
        return ret_355;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("ChDir/1")))) {
        Value ret_356 = alg_string("alg_chdir");
        alg_root_top = rt_base;
        return ret_356;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("GetDir/0")))) {
        Value ret_357 = alg_string("alg_getdir");
        alg_root_top = rt_base;
        return ret_357;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("ParamCount/0")))) {
        Value ret_358 = alg_string("alg_param_count");
        alg_root_top = rt_base;
        return ret_358;
    }
    if (alg_truthy(alg_equal(v_key, alg_string("ParamStr/1")))) {
        Value ret_359 = alg_string("alg_param_str");
        alg_root_top = rt_base;
        return ret_359;
    }
    Value ret_360 = alg_string("");
    alg_root_top = rt_base;
    return ret_360;
    Value ret_361 = alg_nil();
    alg_root_top = rt_base;
    return ret_361;
}

static Value m_cemitter_runtogether_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    (void)((v_result = alg_add(alg_add(alg_string("alg_str("), alg_str(alg_subscript_get(v_arguments, alg_int(0)))), alg_char_value(41))));
    {
        int32_t rt_570 = alg_root_top;
        Value v_i = alg_int(1);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_arguments, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)((v_result = alg_add(alg_add(alg_add(alg_add(alg_string("alg_add("), v_result), alg_string(", alg_str(")), alg_str(alg_subscript_get(v_arguments, v_i))), alg_string("))"))));
        }
        alg_root_top = rt_570;
    }
    Value ret_362 = v_result;
    alg_root_top = rt_base;
    return ret_362;
    Value ret_363 = alg_nil();
    alg_root_top = rt_base;
    return ret_363;
}

static Value m_cemitter_anynamed_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_names = alg_widen(args[0], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    {
        int32_t rt_571 = alg_root_top;
        Value loop_364 = alg_iterable(v_names);
        (void)loop_364;
        alg_root(&loop_364, 1);
        for (int32_t at_364 = 0; at_364 < alg_iterable_count(loop_364); at_364++) {
            int32_t rt_572 = alg_root_top;
            Value v_name = alg_iterable_at(loop_364, at_364);
            (void)v_name;
            alg_root(&v_name, 1);
            if (alg_truthy(alg_not_equal(alg_str(v_name), alg_string("")))) {
                Value ret_365 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_365;
            }
            alg_root_top = rt_572;
        }
        alg_root_top = rt_571;
    }
    Value ret_366 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_366;
    Value ret_367 = alg_nil();
    alg_root_top = rt_base;
    return ret_367;
}

static Value m_cemitter_namearray_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_names = alg_widen(args[0], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    Value v_joined = alg_string("");
    (void)v_joined;
    alg_root(&v_joined, 1);
    if (alg_truthy(alg_equal(alg_property(v_names, "Length"), alg_int(0)))) {
        Value ret_368 = alg_string("NULL");
        alg_root_top = rt_base;
        return ret_368;
    }
    {
        int32_t rt_573 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_names, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                    (void)((v_joined = alg_add(v_joined, alg_string(", "))));
                }
                (void)((v_joined = alg_add(v_joined, f_quotec(NULL, (Value[]){alg_str(alg_subscript_get(v_names, v_i))}, 1))));
            }
        }
        alg_root_top = rt_573;
    }
    Value ret_369 = alg_add(alg_add(alg_string("(const char*[]){"), v_joined), alg_char_value(125));
    alg_root_top = rt_base;
    return ret_369;
    Value ret_370 = alg_nil();
    alg_root_top = rt_base;
    return ret_370;
}

static Value m_cemitter_calling_3_string_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_callee = alg_widen(args[0], "String");
    (void)v_callee;
    alg_root(&v_callee, 1);
    Value v_emitted = alg_widen(args[1], "List");
    (void)v_emitted;
    alg_root(&v_emitted, 1);
    Value v_names = alg_widen(args[2], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    if (alg_truthy(alg_not(f_anynamed(NULL, (Value[]){v_names}, 1)))) {
        Value ret_371 = alg_add(alg_add(alg_add(alg_add(alg_string("alg_call("), v_callee), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_371;
    }
    Value ret_372 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_call_named("), v_callee), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_string(", ")), alg_invoke(v_this, "NameArray", (Value[]){v_names}, 1)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_372;
    Value ret_373 = alg_nil();
    alg_root_top = rt_base;
    return ret_373;
}

static Value m_cemitter_constructing_3_string_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_handle = alg_widen(args[0], "String");
    (void)v_handle;
    alg_root(&v_handle, 1);
    Value v_emitted = alg_widen(args[1], "List");
    (void)v_emitted;
    alg_root(&v_emitted, 1);
    Value v_names = alg_widen(args[2], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    if (alg_truthy(alg_not(f_anynamed(NULL, (Value[]){v_names}, 1)))) {
        Value ret_374 = alg_add(alg_add(alg_add(alg_add(alg_string("alg_new("), v_handle), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_374;
    }
    Value ret_375 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_new_named("), v_handle), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_string(", ")), alg_invoke(v_this, "NameArray", (Value[]){v_names}, 1)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_375;
    Value ret_376 = alg_nil();
    alg_root_top = rt_base;
    return ret_376;
}

static Value m_cemitter_invoking_4_string_string_list_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_receiver = alg_widen(args[0], "String");
    (void)v_receiver;
    alg_root(&v_receiver, 1);
    Value v_thename = alg_widen(args[1], "String");
    (void)v_thename;
    alg_root(&v_thename, 1);
    Value v_emitted = alg_widen(args[2], "List");
    (void)v_emitted;
    alg_root(&v_emitted, 1);
    Value v_names = alg_widen(args[3], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    if (alg_truthy(alg_not(f_anynamed(NULL, (Value[]){v_names}, 1)))) {
        Value ret_377 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_invoke("), v_receiver), alg_string(", ")), f_quotec(NULL, (Value[]){v_thename}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_377;
    }
    Value ret_378 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_invoke_named("), v_receiver), alg_string(", ")), f_quotec(NULL, (Value[]){v_thename}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_string(", ")), alg_invoke(v_this, "NameArray", (Value[]){v_names}, 1)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_378;
    Value ret_379 = alg_nil();
    alg_root_top = rt_base;
    return ret_379;
}

static Value m_cemitter_invokingor_5_string_string_list_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_receiver = alg_widen(args[0], "String");
    (void)v_receiver;
    alg_root(&v_receiver, 1);
    Value v_thename = alg_widen(args[1], "String");
    (void)v_thename;
    alg_root(&v_thename, 1);
    Value v_emitted = alg_widen(args[2], "List");
    (void)v_emitted;
    alg_root(&v_emitted, 1);
    Value v_names = alg_widen(args[3], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    Value v_extension = alg_widen(args[4], "String");
    (void)v_extension;
    alg_root(&v_extension, 1);
    if (alg_truthy(alg_not(f_anynamed(NULL, (Value[]){v_names}, 1)))) {
        Value ret_380 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_invoke_or("), v_receiver), alg_string(", ")), f_quotec(NULL, (Value[]){v_thename}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_string(", ")), v_extension), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_380;
    }
    Value ret_381 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_invoke_or_named("), v_receiver), alg_string(", ")), f_quotec(NULL, (Value[]){v_thename}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_string(", ")), alg_invoke(v_this, "NameArray", (Value[]){v_names}, 1)), alg_string(", ")), v_extension), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_381;
    Value ret_382 = alg_nil();
    alg_root_top = rt_base;
    return ret_382;
}

static Value m_cemitter_overloadedelsewhere_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_unit = alg_widen(args[0], "String");
    (void)v_unit;
    alg_root(&v_unit, 1);
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_theirs = alg_nil();
    (void)v_theirs;
    alg_root(&v_theirs, 1);
    {
        int32_t rt_574 = alg_root_top;
        Value loop_383 = alg_iterable(alg_invoke(alg_property(v_this, "OverloadsIn"), "Keys", NULL, 0));
        (void)loop_383;
        alg_root(&loop_383, 1);
        for (int32_t at_383 = 0; at_383 < alg_iterable_count(loop_383); at_383++) {
            int32_t rt_575 = alg_root_top;
            Value v_key = alg_iterable_at(loop_383, at_383);
            (void)v_key;
            alg_root(&v_key, 1);
            {
                if (alg_truthy(alg_not_equal(f_foldcase(NULL, (Value[]){alg_str(v_key)}, 1), f_foldcase(NULL, (Value[]){v_unit}, 1)))) {
                    continue;
                }
                (void)((v_theirs = alg_cast(alg_invoke(alg_property(v_this, "OverloadsIn"), "Get", (Value[]){v_key}, 1), "Set")));
                {
                    int32_t rt_576 = alg_root_top;
                    Value loop_384 = alg_iterable(alg_invoke(v_theirs, "ToList", NULL, 0));
                    (void)loop_384;
                    alg_root(&loop_384, 1);
                    for (int32_t at_384 = 0; at_384 < alg_iterable_count(loop_384); at_384++) {
                        int32_t rt_577 = alg_root_top;
                        Value v_each = alg_iterable_at(loop_384, at_384);
                        (void)v_each;
                        alg_root(&v_each, 1);
                        if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_str(v_each)}, 1), f_foldcase(NULL, (Value[]){v_name}, 1)))) {
                            Value ret_385 = alg_bool(true);
                            alg_root_top = rt_base;
                            return ret_385;
                        }
                        alg_root_top = rt_577;
                    }
                    alg_root_top = rt_576;
                }
            }
            alg_root_top = rt_575;
        }
        alg_root_top = rt_574;
    }
    Value ret_386 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_386;
    Value ret_387 = alg_nil();
    alg_root_top = rt_base;
    return ret_387;
}

static Value m_cemitter_extensionvalue_1_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_unit = alg_nil();
    (void)v_unit;
    alg_root(&v_unit, 1);
    (void)((v_name = alg_str(alg_property(v_theexpr, "Extension"))));
    (void)((v_unit = alg_str(alg_property(v_theexpr, "ExtensionUnit"))));
    if (alg_truthy(alg_equal(v_unit, alg_string("")))) {
        Value ret_388 = alg_invoke(v_this, "SubprogramValue", (Value[]){v_name}, 1);
        alg_root_top = rt_base;
        return ret_388;
    }
    if (alg_truthy(alg_invoke(v_this, "OverloadedElsewhere", (Value[]){v_unit, v_name}, 2))) {
        Value ret_389 = alg_invoke(v_this, "SetName", (Value[]){v_name}, 1);
        alg_root_top = rt_base;
        return ret_389;
    }
    Value ret_390 = alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1);
    alg_root_top = rt_base;
    return ret_390;
    Value ret_391 = alg_nil();
    alg_root_top = rt_base;
    return ret_391;
}

static Value m_cemitter_argumentarray_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_joined = alg_string("");
    (void)v_joined;
    alg_root(&v_joined, 1);
    if (alg_truthy(alg_equal(alg_property(v_arguments, "Length"), alg_int(0)))) {
        Value ret_392 = alg_string("NULL, 0");
        alg_root_top = rt_base;
        return ret_392;
    }
    {
        int32_t rt_578 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_arguments, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                    (void)((v_joined = alg_add(v_joined, alg_string(", "))));
                }
                (void)((v_joined = alg_add(v_joined, alg_str(alg_subscript_get(v_arguments, v_i)))));
            }
        }
        alg_root_top = rt_578;
    }
    Value ret_393 = alg_add(alg_add(alg_add(alg_string("(Value[]){"), v_joined), alg_string("}, ")), alg_str(alg_property(v_arguments, "Length")));
    alg_root_top = rt_base;
    return ret_393;
    Value ret_394 = alg_nil();
    alg_root_top = rt_base;
    return ret_394;
}

static Value m_cemitter_exportednames_1_emitunit(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_unit = alg_widen(args[0], "EmitUnit");
    (void)v_unit;
    alg_root(&v_unit, 1);
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    (void)((v_names = alg_list()));
    {
        int32_t rt_579 = alg_root_top;
        Value loop_395 = alg_iterable(alg_property(v_unit, "Statements"));
        (void)loop_395;
        alg_root(&loop_395, 1);
        for (int32_t at_395 = 0; at_395 < alg_iterable_count(loop_395); at_395++) {
            int32_t rt_580 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_395, at_395);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                if (alg_truthy((or_63 = alg_is(v_thestmt, "FunctionStmt"), !alg_truthy(or_63) ? or_63 : alg_not(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1))))) {
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
                            int32_t rt_581 = alg_root_top;
                            Value loop_396 = alg_iterable(alg_property(v_thestmt, "Members"));
                            (void)loop_396;
                            alg_root(&loop_396, 1);
                            for (int32_t at_396 = 0; at_396 < alg_iterable_count(loop_396); at_396++) {
                                int32_t rt_582 = alg_root_top;
                                Value v_member = alg_iterable_at(loop_396, at_396);
                                (void)v_member;
                                alg_root(&v_member, 1);
                                (void)(alg_invoke(v_names, "Add", (Value[]){alg_str(alg_property(v_member, "Lexeme"))}, 1));
                                alg_root_top = rt_582;
                            }
                            alg_root_top = rt_581;
                        }
                    }
                }
                if (alg_truthy(alg_is(v_thestmt, "VarGroupStmt"))) {
                    {
                        int32_t rt_583 = alg_root_top;
                        Value loop_397 = alg_iterable(alg_property(v_thestmt, "Names"));
                        (void)loop_397;
                        alg_root(&loop_397, 1);
                        for (int32_t at_397 = 0; at_397 < alg_iterable_count(loop_397); at_397++) {
                            int32_t rt_584 = alg_root_top;
                            Value v_thename = alg_iterable_at(loop_397, at_397);
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            (void)(alg_invoke(v_names, "Add", (Value[]){alg_str(alg_property(v_thename, "Lexeme"))}, 1));
                            alg_root_top = rt_584;
                        }
                        alg_root_top = rt_583;
                    }
                }
            }
            alg_root_top = rt_580;
        }
        alg_root_top = rt_579;
    }
    Value ret_398 = v_names;
    alg_root_top = rt_base;
    return ret_398;
    Value ret_399 = alg_nil();
    alg_root_top = rt_base;
    return ret_399;
}

static Value m_cemitter_constructorfor_3_string_list_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_arguments = alg_widen(args[1], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_joined = alg_widen(args[2], "String");
    (void)v_joined;
    alg_root(&v_joined, 1);
    if (alg_truthy((or_64 = alg_equal(v_name, alg_string("List")), !alg_truthy(or_64) ? or_64 : alg_equal(alg_property(v_arguments, "Length"), alg_int(0))))) {
        Value ret_400 = alg_string("alg_list()");
        alg_root_top = rt_base;
        return ret_400;
    }
    if (alg_truthy((or_65 = alg_equal(v_name, alg_string("Map")), !alg_truthy(or_65) ? or_65 : alg_equal(alg_property(v_arguments, "Length"), alg_int(0))))) {
        Value ret_401 = alg_string("alg_map()");
        alg_root_top = rt_base;
        return ret_401;
    }
    if (alg_truthy((or_66 = alg_equal(v_name, alg_string("Stack")), !alg_truthy(or_66) ? or_66 : alg_equal(alg_property(v_arguments, "Length"), alg_int(0))))) {
        Value ret_402 = alg_string("alg_stack()");
        alg_root_top = rt_base;
        return ret_402;
    }
    if (alg_truthy((or_67 = alg_equal(v_name, alg_string("Set")), !alg_truthy(or_67) ? or_67 : alg_equal(alg_property(v_arguments, "Length"), alg_int(0))))) {
        Value ret_403 = alg_string("alg_set()");
        alg_root_top = rt_base;
        return ret_403;
    }
    if (alg_truthy((or_68 = alg_equal(v_name, alg_string("Set")), !alg_truthy(or_68) ? or_68 : alg_equal(alg_property(v_arguments, "Length"), alg_int(1))))) {
        Value ret_404 = alg_add(alg_add(alg_string("alg_set_of("), v_joined), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_404;
    }
    if (alg_truthy((or_69 = alg_equal(v_name, alg_string("Array")), !alg_truthy(or_69) ? or_69 : alg_equal(alg_property(v_arguments, "Length"), alg_int(1))))) {
        Value ret_405 = alg_add(alg_add(alg_string("alg_array("), v_joined), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_405;
    }
    if (alg_truthy((or_70 = alg_equal(v_name, alg_string("TextFile")), !alg_truthy(or_70) ? or_70 : alg_equal(alg_property(v_arguments, "Length"), alg_int(0))))) {
        Value ret_406 = alg_string("alg_text_file()");
        alg_root_top = rt_base;
        return ret_406;
    }
    if (alg_truthy((or_71 = alg_equal(v_name, alg_string("Buffer")), !alg_truthy(or_71) ? or_71 : alg_equal(alg_property(v_arguments, "Length"), alg_int(0))))) {
        Value ret_407 = alg_string("alg_buffer(alg_int(0))");
        alg_root_top = rt_base;
        return ret_407;
    }
    if (alg_truthy((or_72 = alg_equal(v_name, alg_string("Buffer")), !alg_truthy(or_72) ? or_72 : alg_equal(alg_property(v_arguments, "Length"), alg_int(1))))) {
        Value ret_408 = alg_add(alg_add(alg_string("alg_buffer("), v_joined), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_408;
    }
    Value ret_409 = alg_string("");
    alg_root_top = rt_base;
    return ret_409;
    Value ret_410 = alg_nil();
    alg_root_top = rt_base;
    return ret_410;
}

static Value m_cemitter_unitcall_5_string_string_list_string_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_unit = alg_widen(args[0], "String");
    (void)v_unit;
    alg_root(&v_unit, 1);
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_arguments = alg_widen(args[2], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_joined = alg_widen(args[3], "String");
    (void)v_joined;
    alg_root(&v_joined, 1);
    Value v_names = alg_widen(args[4], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    if (alg_truthy((or_73 = alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){v_unit}, 1), !alg_truthy(or_73) ? or_73 : alg_not(alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_unit}, 1), "Set")), "Contains", (Value[]){v_name}, 1))))) {
        Value ret_411 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), v_name), alg_string("' in unit '")), v_unit), alg_string("'."))}, 1)), alg_string("), alg_nil())"));
        alg_root_top = rt_base;
        return ret_411;
    }
    if (alg_truthy(alg_equal(v_unit, alg_string("System")))) {
        {
            int32_t rt_585 = alg_root_top;
            Value v_thebuiltin = alg_invoke(v_this, "Builtin", (Value[]){v_name, alg_property(v_arguments, "Length")}, 2);
            (void)v_thebuiltin;
            alg_root(&v_thebuiltin, 1);
            if (alg_truthy(alg_not_equal(v_thebuiltin, alg_string("")))) {
                Value ret_412 = alg_add(alg_add(alg_add(v_thebuiltin, alg_char_value(40)), v_joined), alg_char_value(41));
                alg_root_top = rt_base;
                return ret_412;
            }
            Value v_theconstructor = alg_invoke(v_this, "ConstructorFor", (Value[]){v_name, v_arguments, v_joined}, 3);
            (void)v_theconstructor;
            alg_root(&v_theconstructor, 1);
            if (alg_truthy(alg_not_equal(v_theconstructor, alg_string("")))) {
                Value ret_413 = v_theconstructor;
                alg_root_top = rt_base;
                return ret_413;
            }
            (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("A call to '"), v_unit), alg_char_value(46)), v_name), alg_char_value(39))}, 1));
            alg_root_top = rt_585;
        }
    }
    Value v_saved = alg_property(v_this, "Renames");
    (void)v_saved;
    alg_root(&v_saved, 1);
    (void)(alg_set_property(v_this, "Renames", alg_invoke(v_this, "RenamesOf", (Value[]){v_unit, v_name}, 2)));
    Value v_built = alg_string("");
    (void)v_built;
    alg_root(&v_built, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
        (void)((v_built = alg_invoke(v_this, "Constructing", (Value[]){alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1), v_arguments, v_names}, 3)));
    } else {
        if (alg_truthy((or_74 = alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1), !alg_truthy(or_74) ? or_74 : alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1)))) {
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
    (void)(alg_set_property(v_this, "Renames", v_saved));
    if (alg_truthy(alg_not_equal(v_built, alg_string("")))) {
        Value ret_414 = v_built;
        alg_root_top = rt_base;
        return ret_414;
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("A call to '"), v_unit), alg_char_value(46)), v_name), alg_char_value(39))}, 1));
    Value ret_415 = alg_string("");
    alg_root_top = rt_base;
    return ret_415;
    Value ret_416 = alg_nil();
    alg_root_top = rt_base;
    return ret_416;
}

static Value m_cemitter_visitcall_1_callexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CallExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_arguments = alg_nil();
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    Value v_joined = alg_nil();
    (void)v_joined;
    alg_root(&v_joined, 1);
    if (alg_truthy(alg_is(alg_property(v_theexpr, "Callee"), "SuperExpr"))) {
        {
            int32_t rt_586 = alg_root_top;
            if (alg_truthy(alg_equal(alg_property(v_this, "CurrentClass"), alg_string("")))) {
                (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("'super' outside a class")}, 1));
            }
            Value v_emitted = alg_list();
            (void)v_emitted;
            alg_root(&v_emitted, 1);
            {
                int32_t rt_587 = alg_root_top;
                Value loop_417 = alg_iterable(alg_property(v_theexpr, "Arguments"));
                (void)loop_417;
                alg_root(&loop_417, 1);
                for (int32_t at_417 = 0; at_417 < alg_iterable_count(loop_417); at_417++) {
                    int32_t rt_588 = alg_root_top;
                    Value v_argument = alg_iterable_at(loop_417, at_417);
                    (void)v_argument;
                    alg_root(&v_argument, 1);
                    (void)(alg_invoke(v_emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){v_argument}, 1)}, 1));
                    alg_root_top = rt_588;
                }
                alg_root_top = rt_587;
            }
            Value ret_418 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_invoke_from("), alg_invoke(v_this, "ClassHandle", (Value[]){alg_property(v_this, "CurrentClass")}, 1)), alg_string(", ")), alg_invoke(v_this, "ThisRef", NULL, 0)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Method"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)), alg_char_value(41));
            alg_root_top = rt_base;
            return ret_418;
            alg_root_top = rt_586;
        }
    }
    if (alg_truthy((or_75 = alg_is(alg_property(v_theexpr, "Callee"), "GetExpr"), !alg_truthy(or_75) ? or_75 : alg_not_equal(alg_property(alg_property(v_theexpr, "Callee"), "Unit"), alg_string(""))))) {
        {
            int32_t rt_589 = alg_root_top;
            Value v_emitted = alg_list();
            (void)v_emitted;
            alg_root(&v_emitted, 1);
            {
                int32_t rt_590 = alg_root_top;
                Value loop_419 = alg_iterable(alg_property(v_theexpr, "Arguments"));
                (void)loop_419;
                alg_root(&loop_419, 1);
                for (int32_t at_419 = 0; at_419 < alg_iterable_count(loop_419); at_419++) {
                    int32_t rt_591 = alg_root_top;
                    Value v_theargument = alg_iterable_at(loop_419, at_419);
                    (void)v_theargument;
                    alg_root(&v_theargument, 1);
                    (void)(alg_invoke(v_emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){v_theargument}, 1)}, 1));
                    alg_root_top = rt_591;
                }
                alg_root_top = rt_590;
            }
            Value v_text = alg_string("");
            (void)v_text;
            alg_root(&v_text, 1);
            {
                int32_t rt_592 = alg_root_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less(v_i, alg_property(v_emitted, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                            (void)((v_text = alg_add(v_text, alg_string(", "))));
                        }
                        (void)((v_text = alg_add(v_text, alg_str(alg_subscript_get(v_emitted, v_i)))));
                    }
                }
                alg_root_top = rt_592;
            }
            Value ret_420 = alg_invoke(v_this, "UnitCall", (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Callee"), "Unit")), alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme")), v_emitted, v_text, alg_property(v_theexpr, "ArgumentNames")}, 5);
            alg_root_top = rt_base;
            return ret_420;
            alg_root_top = rt_589;
        }
    }
    if (alg_truthy(alg_is(alg_property(v_theexpr, "Callee"), "GetExpr"))) {
        {
            int32_t rt_593 = alg_root_top;
            Value v_receiver = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(alg_property(v_theexpr, "Callee"), "Obj")}, 1);
            (void)v_receiver;
            alg_root(&v_receiver, 1);
            Value v_emitted = alg_list();
            (void)v_emitted;
            alg_root(&v_emitted, 1);
            {
                int32_t rt_594 = alg_root_top;
                Value loop_421 = alg_iterable(alg_property(v_theexpr, "Arguments"));
                (void)loop_421;
                alg_root(&loop_421, 1);
                for (int32_t at_421 = 0; at_421 < alg_iterable_count(loop_421); at_421++) {
                    int32_t rt_595 = alg_root_top;
                    Value v_eachargument = alg_iterable_at(loop_421, at_421);
                    (void)v_eachargument;
                    alg_root(&v_eachargument, 1);
                    (void)(alg_invoke(v_emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){v_eachargument}, 1)}, 1));
                    alg_root_top = rt_595;
                }
                alg_root_top = rt_594;
            }
            if (alg_truthy(alg_not_equal(alg_str(alg_property(alg_property(v_theexpr, "Callee"), "Extension")), alg_string("")))) {
                Value ret_422 = alg_invoke(v_this, "InvokingOr", (Value[]){v_receiver, alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme")), v_emitted, alg_property(v_theexpr, "ArgumentNames"), alg_invoke(v_this, "ExtensionValue", (Value[]){alg_property(v_theexpr, "Callee")}, 1)}, 5);
                alg_root_top = rt_base;
                return ret_422;
            }
            Value ret_423 = alg_invoke(v_this, "Invoking", (Value[]){v_receiver, alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme")), v_emitted, alg_property(v_theexpr, "ArgumentNames")}, 4);
            alg_root_top = rt_base;
            return ret_423;
            alg_root_top = rt_593;
        }
    }
    if (alg_truthy(alg_not((alg_is(alg_property(v_theexpr, "Callee"), "VariableExpr"))))) {
        {
            int32_t rt_596 = alg_root_top;
            Value v_emitted = alg_list();
            (void)v_emitted;
            alg_root(&v_emitted, 1);
            {
                int32_t rt_597 = alg_root_top;
                Value loop_424 = alg_iterable(alg_property(v_theexpr, "Arguments"));
                (void)loop_424;
                alg_root(&loop_424, 1);
                for (int32_t at_424 = 0; at_424 < alg_iterable_count(loop_424); at_424++) {
                    int32_t rt_598 = alg_root_top;
                    Value v_item = alg_iterable_at(loop_424, at_424);
                    (void)v_item;
                    alg_root(&v_item, 1);
                    (void)(alg_invoke(v_emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){v_item}, 1)}, 1));
                    alg_root_top = rt_598;
                }
                alg_root_top = rt_597;
            }
            Value ret_425 = alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Callee")}, 1), v_emitted, alg_property(v_theexpr, "ArgumentNames")}, 3);
            alg_root_top = rt_base;
            return ret_425;
            alg_root_top = rt_596;
        }
    }
    (void)((v_arguments = alg_list()));
    {
        int32_t rt_599 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Arguments"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(v_arguments, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Arguments"), v_i)}, 1)}, 1));
        }
        alg_root_top = rt_599;
    }
    (void)((v_joined = alg_string("")));
    {
        int32_t rt_600 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_arguments, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                    (void)((v_joined = alg_add(v_joined, alg_string(", "))));
                }
                (void)((v_joined = alg_add(v_joined, alg_str(alg_subscript_get(v_arguments, v_i)))));
            }
        }
        alg_root_top = rt_600;
    }
    Value v_name = alg_invoke(v_this, "Spelled", (Value[]){alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme"))}, 1);
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy((or_77 = (or_76 = alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1), alg_truthy(or_76) ? or_76 : alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1)), alg_truthy(or_77) ? or_77 : alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_426 = alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "Read", (Value[]){v_name}, 1), v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 3);
        alg_root_top = rt_base;
        return ret_426;
    }
    Value v_shadowed = alg_invoke(v_this, "TakesOver", (Value[]){v_name, alg_property(v_arguments, "Length")}, 2);
    (void)v_shadowed;
    alg_root(&v_shadowed, 1);
    if (alg_truthy((or_79 = (or_78 = alg_not(v_shadowed), !alg_truthy(or_78) ? or_78 : f_anynamed(NULL, (Value[]){alg_property(v_theexpr, "ArgumentNames")}, 1)), !alg_truthy(or_79) ? or_79 : alg_greater(alg_property(alg_invoke(v_this, "BuiltinCounts", (Value[]){v_name}, 1), "Length"), alg_int(0))))) {
        Value ret_427 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_string("A built-in has no named parameters.")}, 1)), alg_string("), alg_nil())"));
        alg_root_top = rt_base;
        return ret_427;
    }
    if (alg_truthy((or_80 = alg_not(v_shadowed), !alg_truthy(or_80) ? or_80 : alg_greater(alg_property(v_arguments, "Length"), alg_int(1))))) {
        {
            int32_t rt_601 = alg_root_top;
            Value v_one = alg_invoke(v_this, "Builtin", (Value[]){v_name, alg_int(1)}, 2);
            (void)v_one;
            alg_root(&v_one, 1);
            if (alg_truthy((or_81 = alg_equal(v_one, alg_string("alg_writeln")), alg_truthy(or_81) ? or_81 : alg_equal(v_one, alg_string("alg_write"))))) {
                Value ret_428 = alg_add(alg_add(alg_add(v_one, alg_char_value(40)), alg_invoke(v_this, "RunTogether", (Value[]){v_arguments}, 1)), alg_char_value(41));
                alg_root_top = rt_base;
                return ret_428;
            }
            alg_root_top = rt_601;
        }
    }
    if (alg_truthy(alg_not(v_shadowed))) {
        {
            int32_t rt_602 = alg_root_top;
            Value v_thebuiltin = alg_invoke(v_this, "Builtin", (Value[]){v_name, alg_property(v_arguments, "Length")}, 2);
            (void)v_thebuiltin;
            alg_root(&v_thebuiltin, 1);
            if (alg_truthy(alg_not_equal(v_thebuiltin, alg_string("")))) {
                Value ret_429 = alg_add(alg_add(alg_add(v_thebuiltin, alg_char_value(40)), v_joined), alg_char_value(41));
                alg_root_top = rt_base;
                return ret_429;
            }
            alg_root_top = rt_602;
        }
    }
    if (alg_truthy(alg_not(v_shadowed))) {
        {
            int32_t rt_603 = alg_root_top;
            Value v_theconstructor = alg_invoke(v_this, "ConstructorFor", (Value[]){v_name, v_arguments, v_joined}, 3);
            (void)v_theconstructor;
            alg_root(&v_theconstructor, 1);
            if (alg_truthy(alg_not_equal(v_theconstructor, alg_string("")))) {
                Value ret_430 = v_theconstructor;
                alg_root_top = rt_base;
                return ret_430;
            }
            alg_root_top = rt_603;
        }
    }
    if (alg_truthy((or_83 = (or_82 = alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1), !alg_truthy(or_82) ? or_82 : alg_not(v_shadowed)), !alg_truthy(or_83) ? or_83 : alg_greater(alg_property(alg_invoke(v_this, "BuiltinCounts", (Value[]){v_name}, 1), "Length"), alg_int(0))))) {
        Value ret_431 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_string("No matching signature for function.")}, 1)), alg_string("), alg_nil())"));
        alg_root_top = rt_base;
        return ret_431;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
        Value ret_432 = alg_invoke(v_this, "Constructing", (Value[]){alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1), v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 3);
        alg_root_top = rt_base;
        return ret_432;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
        Value ret_433 = alg_invoke(v_this, "Calling", (Value[]){alg_add(alg_add(alg_string("alg_singleton("), alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)), alg_char_value(41)), v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 3);
        alg_root_top = rt_base;
        return ret_433;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Contains", (Value[]){v_name}, 1))) {
        Value ret_434 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "AmbiguousMessage", (Value[]){alg_str(alg_property(alg_property(alg_property(v_theexpr, "Callee"), "Name"), "Lexeme")), alg_str(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Get", (Value[]){v_name}, 1))}, 2)}, 1)), alg_string("), alg_nil())"));
        alg_root_top = rt_base;
        return ret_434;
    }
    if (alg_truthy((or_85 = (or_84 = alg_not_equal(alg_property(v_this, "CurrentClass"), alg_string("")), !alg_truthy(or_84) ? or_84 : alg_not(alg_invoke(v_this, "VisibleSubprogram", (Value[]){v_name}, 1))), !alg_truthy(or_85) ? or_85 : alg_invoke(alg_property(v_this, "VisibleMethods"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1)))) {
        Value ret_435 = alg_invoke(v_this, "Invoking", (Value[]){alg_invoke(v_this, "ThisRef", NULL, 0), v_name, v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 4);
        alg_root_top = rt_base;
        return ret_435;
    }
    if (alg_truthy((or_86 = alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1), !alg_truthy(or_86) ? or_86 : alg_not(alg_invoke(alg_property(v_this, "ShadowNames"), "Contains", (Value[]){v_name}, 1))))) {
        Value ret_436 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "MissingName", (Value[]){v_name}, 1)}, 1)), alg_string("), alg_nil())"));
        alg_root_top = rt_base;
        return ret_436;
    }
    if (alg_truthy((or_87 = alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1), !alg_truthy(or_87) ? or_87 : alg_invoke(v_this, "IsOverloadSet", (Value[]){v_name}, 1)))) {
        Value ret_437 = alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "SetName", (Value[]){v_name}, 1), v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 3);
        alg_root_top = rt_base;
        return ret_437;
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1))) {
        {
            if (alg_truthy(f_anynamed(NULL, (Value[]){alg_property(v_theexpr, "ArgumentNames")}, 1))) {
                Value ret_438 = alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1), v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 3);
                alg_root_top = rt_base;
                return ret_438;
            }
            Value ret_439 = alg_add(alg_add(alg_add(alg_invoke(v_this, "FunctionName", (Value[]){v_name}, 1), alg_string("(NULL, ")), alg_invoke(v_this, "ArgumentArray", (Value[]){v_arguments}, 1)), alg_char_value(41));
            alg_root_top = rt_base;
            return ret_439;
        }
    }
    if (alg_truthy(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1))) {
        Value ret_440 = alg_invoke(v_this, "Calling", (Value[]){alg_invoke(v_this, "Read", (Value[]){v_name}, 1), v_arguments, alg_property(v_theexpr, "ArgumentNames")}, 3);
        alg_root_top = rt_base;
        return ret_440;
    }
    if (alg_truthy((or_88 = alg_not(alg_property(v_this, "EmitTests")), !alg_truthy(or_88) ? or_88 : alg_invoke(v_this, "IsAssertion", (Value[]){v_name}, 1)))) {
        Value ret_441 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "MissingName", (Value[]){v_name}, 1)}, 1)), alg_string("), alg_nil())"));
        alg_root_top = rt_base;
        return ret_441;
    }
    if (alg_truthy(alg_not(v_shadowed))) {
        {
            int32_t rt_604 = alg_root_top;
            Value v_counts = alg_invoke(v_this, "BuiltinCounts", (Value[]){v_name}, 1);
            (void)v_counts;
            alg_root(&v_counts, 1);
            if (alg_truthy(alg_greater(alg_property(v_counts, "Length"), alg_int(0)))) {
                Value ret_442 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "CountsMessage", (Value[]){v_counts, alg_property(v_arguments, "Length")}, 2)}, 1)), alg_string("), alg_nil())"));
                alg_root_top = rt_base;
                return ret_442;
            }
            alg_root_top = rt_604;
        }
    }
    if (alg_truthy((or_95 = (or_94 = (or_93 = (or_92 = (or_91 = (or_90 = (or_89 = alg_not(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)), !alg_truthy(or_89) ? or_89 : alg_not(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_90) ? or_90 : alg_not(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))), !alg_truthy(or_91) ? or_91 : alg_not(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))), !alg_truthy(or_92) ? or_92 : alg_not(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_93) ? or_93 : alg_not(alg_invoke(alg_property(v_this, "EnumTypes"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_94) ? or_94 : alg_not(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_name}, 1))), !alg_truthy(or_95) ? or_95 : alg_not(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Contains", (Value[]){v_name}, 1))))) {
        Value ret_443 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_invoke(v_this, "MissingName", (Value[]){v_name}, 1)}, 1)), alg_string("), alg_nil())"));
        alg_root_top = rt_base;
        return ret_443;
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_string("A call to '"), v_name), alg_char_value(39))}, 1));
    Value ret_444 = alg_nil();
    alg_root_top = rt_base;
    return ret_444;
}

static Value m_cemitter_visitlogical_1_logicalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "LogicalExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_slot = alg_nil();
    (void)v_slot;
    alg_root(&v_slot, 1);
    Value v_test = alg_nil();
    (void)v_test;
    alg_root(&v_test, 1);
    Value v_left = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Left")}, 1);
    (void)v_left;
    alg_root(&v_left, 1);
    Value v_right = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Right")}, 1);
    (void)v_right;
    alg_root(&v_right, 1);
    (void)((v_slot = alg_add(alg_string("or_"), alg_str(alg_property(v_this, "Logicals")))));
    (void)(alg_set_property(v_this, "Logicals", alg_add(alg_property(v_this, "Logicals"), alg_int(1))));
    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_slot), alg_char_value(59)), alg_char_value(10))}, 1));
    (void)((v_test = alg_string("!alg_truthy(")));
    if (alg_truthy(alg_equal(alg_property(alg_property(v_theexpr, "Op"), "TypeOfToken"), e_tokentype_tokenVor))) {
        (void)((v_test = alg_string("alg_truthy(")));
    }
    Value ret_445 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_char_value(40), v_slot), alg_string(" = ")), v_left), alg_string(", ")), v_test), v_slot), alg_string(") ? ")), v_slot), alg_string(" : ")), v_right), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_445;
    Value ret_446 = alg_nil();
    alg_root_top = rt_base;
    return ret_446;
}

static Value m_cemitter_boundargument_3_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_params = args[0];
    (void)v_params;
    alg_root(&v_params, 1);
    Value v_types = args[1];
    (void)v_types;
    alg_root(&v_types, 1);
    Value v_i = alg_widen(args[2], "Integer");
    (void)v_i;
    alg_root(&v_i, 1);
    Value v_slot = alg_add(alg_add(alg_string("args["), alg_str(v_i)), alg_char_value(93));
    (void)v_slot;
    alg_root(&v_slot, 1);
    if (alg_truthy(alg_greater_equal(v_i, alg_property(v_types, "Length")))) {
        Value ret_447 = v_slot;
        alg_root_top = rt_base;
        return ret_447;
    }
    Value v_declared = alg_str(alg_subscript_get(v_types, v_i));
    (void)v_declared;
    alg_root(&v_declared, 1);
    if (alg_truthy((or_96 = alg_equal(v_declared, alg_string("")), alg_truthy(or_96) ? or_96 : alg_equal(v_declared, alg_string("Any"))))) {
        Value ret_448 = v_slot;
        alg_root_top = rt_base;
        return ret_448;
    }
    Value ret_449 = alg_add(alg_add(alg_add(alg_add(alg_string("alg_param("), v_slot), alg_string(", ")), f_quotec(NULL, (Value[]){v_declared}, 1)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_449;
    Value ret_450 = alg_nil();
    alg_root_top = rt_base;
    return ret_450;
}

static Value m_cemitter_allliterals_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    {
        int32_t rt_605 = alg_root_top;
        Value loop_451 = alg_iterable(alg_property(v_theexpr, "Values"));
        (void)loop_451;
        alg_root(&loop_451, 1);
        for (int32_t at_451 = 0; at_451 < alg_iterable_count(loop_451); at_451++) {
            int32_t rt_606 = alg_root_top;
            Value v_value = alg_iterable_at(loop_451, at_451);
            (void)v_value;
            alg_root(&v_value, 1);
            if (alg_truthy(alg_not((alg_is(v_value, "LiteralExpr"))))) {
                Value ret_452 = alg_bool(false);
                alg_root_top = rt_base;
                return ret_452;
            }
            alg_root_top = rt_606;
        }
        alg_root_top = rt_605;
    }
    if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
        {
            int32_t rt_607 = alg_root_top;
            Value loop_453 = alg_iterable(alg_property(v_theexpr, "Keys"));
            (void)loop_453;
            alg_root(&loop_453, 1);
            for (int32_t at_453 = 0; at_453 < alg_iterable_count(loop_453); at_453++) {
                int32_t rt_608 = alg_root_top;
                Value v_key = alg_iterable_at(loop_453, at_453);
                (void)v_key;
                alg_root(&v_key, 1);
                if (alg_truthy(alg_not((alg_is(v_key, "LiteralExpr"))))) {
                    Value ret_454 = alg_bool(false);
                    alg_root_top = rt_base;
                    return ret_454;
                }
                alg_root_top = rt_608;
            }
            alg_root_top = rt_607;
        }
    }
    Value ret_455 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_455;
    Value ret_456 = alg_nil();
    alg_root_top = rt_base;
    return ret_456;
}

static Value m_cemitter_visitcollectionexpr_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_built = alg_nil();
    (void)v_built;
    alg_root(&v_built, 1);
    if (alg_truthy(alg_greater(alg_property(alg_property(v_theexpr, "Values"), "Length"), (alg_declared(d_hoistVabove, "HOIST_ABOVE"), v_hoistVabove)))) {
        {
            if (alg_truthy(alg_invoke(v_this, "AllLiterals", (Value[]){v_theexpr}, 1))) {
                Value ret_457 = alg_invoke(v_this, "HoistedCollection", (Value[]){v_theexpr}, 1);
                alg_root_top = rt_base;
                return ret_457;
            }
            Value ret_458 = alg_invoke(v_this, "ComputedCollection", (Value[]){v_theexpr}, 1);
            alg_root_top = rt_base;
            return ret_458;
        }
    }
    if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
        {
            (void)((v_built = alg_string("alg_map()")));
            {
                int32_t rt_609 = alg_root_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Keys"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)((v_built = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_map_keep("), v_built), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Keys"), v_i)}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Values"), v_i)}, 1)), alg_char_value(41))));
                }
                alg_root_top = rt_609;
            }
            Value ret_459 = v_built;
            alg_root_top = rt_base;
            return ret_459;
        }
    }
    (void)((v_built = alg_string("alg_list()")));
    {
        int32_t rt_610 = alg_root_top;
        Value loop_460 = alg_iterable(alg_property(v_theexpr, "Values"));
        (void)loop_460;
        alg_root(&loop_460, 1);
        for (int32_t at_460 = 0; at_460 < alg_iterable_count(loop_460); at_460++) {
            int32_t rt_611 = alg_root_top;
            Value v_value = alg_iterable_at(loop_460, at_460);
            (void)v_value;
            alg_root(&v_value, 1);
            (void)((v_built = alg_add(alg_add(alg_add(alg_add(alg_string("alg_list_keep("), v_built), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){v_value}, 1)), alg_char_value(41))));
            alg_root_top = rt_611;
        }
        alg_root_top = rt_610;
    }
    Value ret_461 = v_built;
    alg_root_top = rt_base;
    return ret_461;
    Value ret_462 = alg_nil();
    alg_root_top = rt_base;
    return ret_462;
}

static Value m_cemitter_hoistedcollection_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    (void)((v_symbol = alg_add(alg_string("lit_"), alg_str(alg_property(v_this, "Loops")))));
    (void)(alg_set_property(v_this, "Loops", alg_add(alg_property(v_this, "Loops"), alg_int(1))));
    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_symbol), alg_string("(void);")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_symbol), alg_string("(void) {")), alg_char_value(10))}, 1));
    if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    Value it = alg_map();"), alg_char_value(10))}, 1));
            {
                int32_t rt_612 = alg_root_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Keys"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    it = alg_map_keep(it, "), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Keys"), v_i)}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Values"), v_i)}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                }
                alg_root_top = rt_612;
            }
        }
    } else {
        {
            (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    Value it = alg_list();"), alg_char_value(10))}, 1));
            {
                int32_t rt_613 = alg_root_top;
                Value loop_463 = alg_iterable(alg_property(v_theexpr, "Values"));
                (void)loop_463;
                alg_root(&loop_463, 1);
                for (int32_t at_463 = 0; at_463 < alg_iterable_count(loop_463); at_463++) {
                    int32_t rt_614 = alg_root_top;
                    Value v_thevalue = alg_iterable_at(loop_463, at_463);
                    (void)v_thevalue;
                    alg_root(&v_thevalue, 1);
                    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("    it = alg_list_keep(it, "), alg_invoke(v_this, "Evaluate", (Value[]){v_thevalue}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                    alg_root_top = rt_614;
                }
                alg_root_top = rt_613;
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("    return it;"), alg_char_value(10)), alg_char_value(125)), alg_char_value(10)), alg_char_value(10))}, 1));
    Value ret_464 = alg_add(v_symbol, alg_string("()"));
    alg_root_top = rt_base;
    return ret_464;
    Value ret_465 = alg_nil();
    alg_root_top = rt_base;
    return ret_465;
}

static Value m_cemitter_computedcollection_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    Value v_joined = alg_nil();
    (void)v_joined;
    alg_root(&v_joined, 1);
    (void)((v_symbol = alg_add(alg_string("lit_"), alg_str(alg_property(v_this, "Loops")))));
    (void)(alg_set_property(v_this, "Loops", alg_add(alg_property(v_this, "Loops"), alg_int(1))));
    (void)((v_joined = alg_string("")));
    Value v_emitted = alg_list();
    (void)v_emitted;
    alg_root(&v_emitted, 1);
    {
        int32_t rt_615 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Values"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
                    (void)(alg_invoke(v_emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Keys"), v_i)}, 1)}, 1));
                }
                (void)(alg_invoke(v_emitted, "Add", (Value[]){alg_invoke(v_this, "Evaluate", (Value[]){alg_subscript_get(alg_property(v_theexpr, "Values"), v_i)}, 1)}, 1));
            }
        }
        alg_root_top = rt_615;
    }
    {
        int32_t rt_616 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_emitted, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            {
                if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                    (void)((v_joined = alg_add(v_joined, alg_string(", "))));
                }
                (void)((v_joined = alg_add(v_joined, alg_str(alg_subscript_get(v_emitted, v_i)))));
            }
        }
        alg_root_top = rt_616;
    }
    (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_symbol), alg_string("(Value *e);")), alg_char_value(10))}, 1));
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_symbol), alg_string("(Value *e) {")), alg_char_value(10))}, 1));
    if (alg_truthy(alg_property(v_theexpr, "IsMap"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    Value it = alg_map();"), alg_char_value(10))}, 1));
            {
                int32_t rt_617 = alg_root_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Values"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    it = alg_map_keep(it, e["), alg_str(alg_multiply(v_i, alg_int(2)))), alg_string("], e[")), alg_str(alg_add(alg_multiply(v_i, alg_int(2)), alg_int(1)))), alg_string("]);")), alg_char_value(10))}, 1));
                }
                alg_root_top = rt_617;
            }
        }
    } else {
        {
            (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_string("    Value it = alg_list();"), alg_char_value(10))}, 1));
            {
                int32_t rt_618 = alg_root_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less(v_i, alg_property(alg_property(v_theexpr, "Values"), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("    it = alg_list_keep(it, e["), alg_str(v_i)), alg_string("]);")), alg_char_value(10))}, 1));
                }
                alg_root_top = rt_618;
            }
        }
    }
    (void)(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("    return it;"), alg_char_value(10)), alg_char_value(125)), alg_char_value(10)), alg_char_value(10))}, 1));
    Value ret_466 = alg_add(alg_add(alg_add(v_symbol, alg_string("((Value[]){")), v_joined), alg_string("})"));
    alg_root_top = rt_base;
    return ret_466;
    Value ret_467 = alg_nil();
    alg_root_top = rt_base;
    return ret_467;
}

static Value m_cemitter_visitsubscriptexpr_1_subscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SubscriptExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value ret_468 = alg_add(alg_add(alg_add(alg_add(alg_string("alg_subscript_get("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Index")}, 1)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_468;
    Value ret_469 = alg_nil();
    alg_root_top = rt_base;
    return ret_469;
}

static Value m_cemitter_visitsetsubscriptexpr_1_setsubscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SetSubscriptExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value ret_470 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_subscript_set("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Index")}, 1)), alg_string(", ")), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_470;
    Value ret_471 = alg_nil();
    alg_root_top = rt_base;
    return ret_471;
}

static Value m_cemitter_unitvalue_2_string_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_unit = alg_widen(args[0], "String");
    (void)v_unit;
    alg_root(&v_unit, 1);
    Value v_name = alg_widen(args[1], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    if (alg_truthy((or_97 = alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){v_unit}, 1), !alg_truthy(or_97) ? or_97 : alg_not(alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_unit}, 1), "Set")), "Contains", (Value[]){v_name}, 1))))) {
        Value ret_472 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), v_name), alg_string("' in unit '")), v_unit), alg_string("'."))}, 1)), alg_string("), alg_nil())"));
        alg_root_top = rt_base;
        return ret_472;
    }
    if (alg_truthy(alg_equal(v_unit, alg_string("System")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_char_value(39), v_unit), alg_char_value(46)), v_name), alg_string("' as a value"))}, 1));
    }
    Value v_saved = alg_property(v_this, "Renames");
    (void)v_saved;
    alg_root(&v_saved, 1);
    (void)(alg_set_property(v_this, "Renames", alg_invoke(v_this, "RenamesOf", (Value[]){v_unit, v_name}, 2)));
    Value v_built = alg_string("");
    (void)v_built;
    alg_root(&v_built, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_name}, 1))) {
        (void)((v_built = alg_invoke(v_this, "EnumMemberName", (Value[]){alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_name}, 1)), v_name}, 2)));
    } else {
        if (alg_truthy(alg_invoke(alg_property(v_this, "EnumTypes"), "Contains", (Value[]){v_name}, 1))) {
            (void)((v_built = alg_invoke(v_this, "EnumTypeName", (Value[]){v_name}, 1)));
        } else {
            if (alg_truthy(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
                (void)((v_built = alg_add(alg_add(alg_string("alg_singleton("), alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)), alg_char_value(41))));
            } else {
                if (alg_truthy(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){f_foldcase(NULL, (Value[]){v_name}, 1)}, 1))) {
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
    (void)(alg_set_property(v_this, "Renames", v_saved));
    if (alg_truthy(alg_not_equal(v_built, alg_string("")))) {
        Value ret_473 = v_built;
        alg_root_top = rt_base;
        return ret_473;
    }
    (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_char_value(39), v_unit), alg_char_value(46)), v_name), alg_string("' as a value"))}, 1));
    Value ret_474 = alg_string("");
    alg_root_top = rt_base;
    return ret_474;
    Value ret_475 = alg_nil();
    alg_root_top = rt_base;
    return ret_475;
}

static Value m_cemitter_visitgetexpr_1_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Unit"), alg_string("")))) {
        Value ret_476 = alg_invoke(v_this, "UnitValue", (Value[]){alg_str(alg_property(v_theexpr, "Unit")), alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 2);
        alg_root_top = rt_base;
        return ret_476;
    }
    if (alg_truthy(alg_not_equal(alg_str(alg_property(v_theexpr, "Extension")), alg_string("")))) {
        Value ret_477 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_property_or("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "ExtensionValue", (Value[]){v_theexpr}, 1)), alg_char_value(41));
        alg_root_top = rt_base;
        return ret_477;
    }
    Value ret_478 = alg_add(alg_add(alg_add(alg_add(alg_string("alg_property("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_478;
    Value ret_479 = alg_nil();
    alg_root_top = rt_base;
    return ret_479;
}

static Value m_cemitter_visitsetexpr_1_setexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    if (alg_truthy(alg_not_equal(alg_property(v_theexpr, "Unit"), alg_string("")))) {
        {
            int32_t rt_619 = alg_root_top;
            Value v_written = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1);
            (void)v_written;
            alg_root(&v_written, 1);
            Value v_unit = alg_str(alg_property(v_theexpr, "Unit"));
            (void)v_unit;
            alg_root(&v_unit, 1);
            Value v_name = alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"));
            (void)v_name;
            alg_root(&v_name, 1);
            if (alg_truthy((or_98 = alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){v_unit}, 1), !alg_truthy(or_98) ? or_98 : alg_not(alg_invoke((alg_cast(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_unit}, 1), "Set")), "Contains", (Value[]){v_name}, 1))))) {
                Value ret_480 = alg_add(alg_add(alg_string("(alg_error("), f_quotec(NULL, (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("Undefined name '"), v_name), alg_string("' in unit '")), v_unit), alg_string("'."))}, 1)), alg_string("), alg_nil())"));
                alg_root_top = rt_base;
                return ret_480;
            }
            if (alg_truthy((or_99 = alg_not_equal(v_unit, alg_string("System")), !alg_truthy(or_99) ? or_99 : alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))) {
                Value ret_481 = alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_add(alg_add(alg_add(alg_add(alg_char_value(40), alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), alg_string(" = ")), v_written), alg_char_value(41))}, 2);
                alg_root_top = rt_base;
                return ret_481;
            }
            (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("An assignment to '"), v_unit), alg_char_value(46)), v_name), alg_char_value(39))}, 1));
            alg_root_top = rt_619;
        }
    }
    Value ret_482 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_set_property("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Obj")}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Name"), "Lexeme"))}, 1)), alg_string(", ")), alg_invoke(v_this, "BoundValue", (Value[]){alg_property(v_theexpr, "Declared"), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_theexpr, "Value")}, 1), alg_property(v_theexpr, "Actual")}, 3)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_482;
    Value ret_483 = alg_nil();
    alg_root_top = rt_base;
    return ret_483;
}

static Value m_cemitter_visitsuperexpr_1_superexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SuperExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    if (alg_truthy(alg_equal(alg_property(v_this, "CurrentClass"), alg_string("")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("'super' outside a class")}, 1));
    }
    Value ret_484 = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("alg_bound_from("), alg_invoke(v_this, "ClassHandle", (Value[]){alg_property(v_this, "CurrentClass")}, 1)), alg_string(", ")), alg_invoke(v_this, "ThisRef", NULL, 0)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_theexpr, "Method"), "Lexeme"))}, 1)), alg_char_value(41));
    alg_root_top = rt_base;
    return ret_484;
    Value ret_485 = alg_nil();
    alg_root_top = rt_base;
    return ret_485;
}

static Value m_cemitter_visitthisexpr_1_thisexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "ThisExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    Value ret_486 = alg_invoke(v_this, "ThisRef", NULL, 0);
    alg_root_top = rt_base;
    return ret_486;
    Value ret_487 = alg_nil();
    alg_root_top = rt_base;
    return ret_487;
}

static Value m_cemitter_visitclassstmt_1_classstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ClassStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    (void)(alg_invoke(v_this, "EmitClass", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "Superclass"), alg_property(v_thestmt, "Fields"), alg_property(v_thestmt, "Methods"), alg_bool(false)}, 5));
    Value ret_488 = alg_nil();
    alg_root_top = rt_base;
    return ret_488;
}

static Value m_cemitter_visitobjectstmt_1_objectstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ObjectStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    (void)(alg_invoke(v_this, "EmitClass", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), alg_property(v_thestmt, "Superclass"), alg_property(v_thestmt, "Fields"), alg_property(v_thestmt, "Methods"), alg_bool(true)}, 5));
    Value ret_489 = alg_nil();
    alg_root_top = rt_base;
    return ret_489;
}

static Value m_cemitter_visitsubrangestmt_1_subrangestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "SubrangeStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value ret_490 = alg_nil();
    alg_root_top = rt_base;
    return ret_490;
}

static Value m_cemitter_emitsubranges_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    {
        int32_t rt_620 = alg_root_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property((alg_declared(d_subrangeVnames, "SUBRANGE_NAMES"), v_subrangeVnames), "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(alg_property(v_this, "Shells"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    alg_subrange("), f_quotec(NULL, (Value[]){alg_str(alg_subscript_get((alg_declared(d_subrangeVnames, "SUBRANGE_NAMES"), v_subrangeVnames), v_i))}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_subscript_get((alg_declared(d_subrangeVlows, "SUBRANGE_LOWS"), v_subrangeVlows), v_i))}, 1)), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_subscript_get((alg_declared(d_subrangeVhighs, "SUBRANGE_HIGHS"), v_subrangeVhighs), v_i))}, 1)), alg_string(");")), alg_char_value(10))}, 1));
        }
        alg_root_top = rt_620;
    }
    Value ret_491 = alg_nil();
    alg_root_top = rt_base;
    return ret_491;
}

static Value m_cemitter_visitenumstmt_1_enumstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "EnumStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_thetype = alg_nil();
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    (void)((v_thetype = alg_invoke(v_this, "EnumTypeName", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)));
    (void)(alg_invoke(v_this, "DeclareValue", (Value[]){v_thetype, alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 2));
    (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), v_thetype), alg_string(" = alg_enum_type(")), f_quotec(NULL, (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1)), alg_string(");")), alg_char_value(10))}, 1));
    {
        int32_t rt_621 = alg_root_top;
        Value loop_492 = alg_iterable(alg_property(v_thestmt, "Members"));
        (void)loop_492;
        alg_root(&loop_492, 1);
        for (int32_t at_492 = 0; at_492 < alg_iterable_count(loop_492); at_492++) {
            int32_t rt_622 = alg_root_top;
            Value v_member = alg_iterable_at(loop_492, at_492);
            (void)v_member;
            alg_root(&v_member, 1);
            {
                int32_t rt_623 = alg_root_top;
                Value v_symbol = alg_invoke(v_this, "EnumMemberName", (Value[]){alg_str(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){alg_str(alg_property(v_member, "Lexeme"))}, 1)), alg_str(alg_property(v_member, "Lexeme"))}, 2);
                (void)v_symbol;
                alg_root(&v_symbol, 1);
                (void)(alg_invoke(v_this, "DeclareValue", (Value[]){v_symbol, alg_str(alg_property(v_member, "Lexeme"))}, 2));
                (void)(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("    "), v_symbol), alg_string(" = alg_enum_member(")), v_thetype), alg_string(", ")), f_quotec(NULL, (Value[]){alg_str(alg_property(v_member, "Lexeme"))}, 1)), alg_string(");")), alg_char_value(10))}, 1));
                alg_root_top = rt_623;
            }
            alg_root_top = rt_622;
        }
        alg_root_top = rt_621;
    }
    Value ret_493 = alg_nil();
    alg_root_top = rt_base;
    return ret_493;
}

static Value m_cemitter_visittrystmt_1_trystmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "TryStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_id = alg_nil();
    (void)v_id;
    alg_root(&v_id, 1);
    Value v_frame = alg_nil();
    (void)v_frame;
    alg_root(&v_frame, 1);
    Value v_handlers = alg_nil();
    (void)v_handlers;
    alg_root(&v_handlers, 1);
    Value v_catchall = alg_nil();
    (void)v_catchall;
    alg_root(&v_catchall, 1);
    Value v_keys = alg_nil();
    (void)v_keys;
    alg_root(&v_keys, 1);
    (void)((v_id = alg_property(v_this, "Loops")));
    (void)(alg_set_property(v_this, "Loops", alg_add(alg_property(v_this, "Loops"), alg_int(1))));
    (void)((v_frame = alg_add(alg_string("frame_"), alg_str(v_id))));
    (void)((v_handlers = alg_list()));
    (void)((v_catchall = alg_nil()));
    (void)((v_keys = alg_invoke(alg_property(v_thestmt, "Handlers"), "Keys", NULL, 0)));
    {
        int32_t rt_624 = alg_root_top;
        Value loop_494 = alg_iterable(v_keys);
        (void)loop_494;
        alg_root(&loop_494, 1);
        for (int32_t at_494 = 0; at_494 < alg_iterable_count(loop_494); at_494++) {
            int32_t rt_625 = alg_root_top;
            Value v_key = alg_iterable_at(loop_494, at_494);
            (void)v_key;
            alg_root(&v_key, 1);
            {
                if (alg_truthy(alg_equal(v_key, alg_string("default")))) {
                    (void)((v_catchall = alg_invoke(alg_property(v_thestmt, "Handlers"), "Get", (Value[]){v_key}, 1)));
                } else {
                    (void)(alg_invoke(v_handlers, "Add", (Value[]){v_key}, 1));
                }
            }
            alg_root_top = rt_625;
        }
        alg_root_top = rt_624;
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("AlgFrame "), v_frame), alg_char_value(59))}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_push_frame(&"), v_frame), alg_string(");"))}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("if (ALG_SETJMP("), v_frame), alg_string(".jump) == 0) {"))}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_set_property(v_this, "TryDepth", alg_add(alg_property(v_this, "TryDepth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "TryBlock")}, 1));
    (void)(alg_set_property(v_this, "TryDepth", alg_subtract(alg_property(v_this, "TryDepth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("alg_pop_frame();")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("else {")}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    if (alg_truthy(alg_equal(alg_property(v_handlers, "Length"), alg_int(0)))) {
        (void)(alg_invoke(v_this, "EmitHandlerBody", (Value[]){v_catchall, v_frame}, 2));
    } else {
        {
            int32_t rt_626 = alg_root_top;
            Value v_names = alg_string("");
            (void)v_names;
            alg_root(&v_names, 1);
            {
                int32_t rt_627 = alg_root_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less(v_i, alg_property(v_handlers, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        if (alg_truthy(alg_greater(v_i, alg_int(0)))) {
                            (void)((v_names = alg_add(v_names, alg_string(", "))));
                        }
                        (void)((v_names = alg_add(v_names, f_quotec(NULL, (Value[]){alg_str(alg_subscript_get(v_handlers, v_i))}, 1))));
                    }
                }
                alg_root_top = rt_627;
            }
            Value v_table = alg_add(alg_string("names_"), alg_str(v_id));
            (void)v_table;
            alg_root(&v_table, 1);
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_string("static const char *"), v_table), alg_string("[] = {")), v_names), alg_string("};"))}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("int32_t which_"), alg_str(v_id)), alg_string(" = alg_handler(")), v_frame), alg_string(".raised, ")), v_table), alg_string(", ")), alg_str(alg_property(v_handlers, "Length"))), alg_string(");"))}, 1));
            {
                int32_t rt_628 = alg_root_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less(v_i, alg_property(v_handlers, "Length"))); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        int32_t rt_629 = alg_root_top;
                        Value v_lead = alg_string("else if");
                        (void)v_lead;
                        alg_root(&v_lead, 1);
                        if (alg_truthy(alg_equal(v_i, alg_int(0)))) {
                            (void)((v_lead = alg_string("if")));
                        }
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(v_lead, alg_string(" (which_")), alg_str(v_id)), alg_string(" == ")), alg_str(v_i)), alg_string(") {"))}, 1));
                        (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
                        (void)(alg_invoke(v_this, "EmitHandlerBody", (Value[]){alg_invoke(alg_property(v_thestmt, "Handlers"), "Get", (Value[]){alg_subscript_get(v_handlers, v_i)}, 1), v_frame}, 2));
                        (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
                        (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
                        alg_root_top = rt_629;
                    }
                }
                alg_root_top = rt_628;
            }
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("else {")}, 1));
            (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
            if (alg_truthy(alg_not_equal(v_catchall, alg_nil()))) {
                (void)(alg_invoke(v_this, "EmitHandlerBody", (Value[]){v_catchall, v_frame}, 2));
            } else {
                (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_raise("), v_frame), alg_string(".raised);"))}, 1));
            }
            (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
            alg_root_top = rt_626;
        }
    }
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    Value ret_495 = alg_nil();
    alg_root_top = rt_base;
    return ret_495;
}

static Value m_cemitter_visitraisestmt_1_raisestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "RaiseStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    if (alg_truthy(alg_equal(alg_property(v_thestmt, "Value"), alg_nil()))) {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("alg_raise(alg_nil());")}, 1));
    } else {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("alg_raise("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Value")}, 1)), alg_string(");"))}, 1));
    }
    Value ret_496 = alg_nil();
    alg_root_top = rt_base;
    return ret_496;
}

static Value m_cemitter_visitforinstmt_1_forinstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ForInStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_id = alg_nil();
    (void)v_id;
    alg_root(&v_id, 1);
    Value v_snapshot = alg_nil();
    (void)v_snapshot;
    alg_root(&v_snapshot, 1);
    Value v_index = alg_nil();
    (void)v_index;
    alg_root(&v_index, 1);
    Value v_counter = alg_nil();
    (void)v_counter;
    alg_root(&v_counter, 1);
    (void)(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    (void)((v_id = alg_property(v_this, "Loops")));
    (void)(alg_set_property(v_this, "Loops", alg_add(alg_property(v_this, "Loops"), alg_int(1))));
    (void)((v_snapshot = alg_add(alg_string("loop_"), alg_str(v_id))));
    (void)((v_index = alg_add(alg_string("at_"), alg_str(v_id))));
    Value v_mark = alg_invoke(v_this, "OpenScope", NULL, 0);
    (void)v_mark;
    alg_root(&v_mark, 1);
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    Value v_outerroots = alg_invoke(v_this, "OpenRoots", (Value[]){alg_bool(true)}, 1);
    (void)v_outerroots;
    alg_root(&v_outerroots, 1);
    (void)(alg_invoke(v_this, "DeclareLocal", (Value[]){v_snapshot, alg_add(alg_add(alg_string("alg_iterable("), alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Iterable")}, 1)), alg_char_value(41))}, 2));
    (void)((v_counter = alg_string("int32_t ")));
    if (alg_truthy(alg_property(v_this, "Volatiles"))) {
        (void)((v_counter = alg_string("volatile int32_t ")));
    }
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("for ("), v_counter), v_index), alg_string(" = 0; ")), v_index), alg_string(" < alg_iterable_count(")), v_snapshot), alg_string("); ")), v_index), alg_string("++) {"))}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_add(alg_property(v_this, "Depth"), alg_int(1))));
    Value v_iterroots = alg_invoke(v_this, "OpenRoots", (Value[]){alg_bool(true)}, 1);
    (void)v_iterroots;
    alg_root(&v_iterroots, 1);
    (void)(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1));
    Value v_element = alg_add(alg_add(alg_add(alg_add(alg_string("alg_iterable_at("), v_snapshot), alg_string(", ")), v_index), alg_char_value(41));
    (void)v_element;
    alg_root(&v_element, 1);
    if (alg_truthy(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1))) {
        (void)(alg_invoke(v_this, "DeclareCell", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme")), v_element}, 2));
    } else {
        {
            (void)(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_invoke(v_this, "VariableName", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1), v_element}, 2));
        }
    }
    Value v_enclosingloopdepth = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosingloopdepth;
    alg_root(&v_enclosingloopdepth, 1);
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_property(v_this, "TryDepth")));
    (void)(alg_invoke(alg_property(v_this, "LoopLabels"), "Add", (Value[]){alg_property(v_thestmt, "Label")}, 1));
    (void)(alg_invoke(alg_property(v_this, "LoopDepths"), "Add", (Value[]){alg_property(v_this, "TryDepth")}, 1));
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "Body")}, 1));
    (void)(alg_invoke(alg_property(v_this, "LoopLabels"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LoopLabels"), "Length"), alg_int(1))}, 1));
    (void)(alg_invoke(alg_property(v_this, "LoopDepths"), "RemoveAt", (Value[]){alg_subtract(alg_property(alg_property(v_this, "LoopDepths"), "Length"), alg_int(1))}, 1));
    (void)(alg_set_property(v_this, "LoopTryDepth", v_enclosingloopdepth));
    (void)(alg_invoke(v_this, "EmitContinueTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1));
    (void)(alg_invoke(v_this, "CloseRoots", (Value[]){v_iterroots}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "EmitBreakTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1));
    (void)(alg_invoke(v_this, "CloseRoots", (Value[]){v_outerroots}, 1));
    (void)(alg_set_property(v_this, "Depth", alg_subtract(alg_property(v_this, "Depth"), alg_int(1))));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1));
    (void)(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1));
    Value ret_497 = alg_nil();
    alg_root_top = rt_base;
    return ret_497;
}

static Value m_cemitter_breaktarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    Value ret_498 = alg_add(alg_string("lb_"), alg_invoke(v_this, "Escaped", (Value[]){f_foldcase(NULL, (Value[]){v_thelabel}, 1)}, 1));
    alg_root_top = rt_base;
    return ret_498;
    Value ret_499 = alg_nil();
    alg_root_top = rt_base;
    return ret_499;
}

static Value m_cemitter_continuetarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    Value ret_500 = alg_add(alg_string("lc_"), alg_invoke(v_this, "Escaped", (Value[]){f_foldcase(NULL, (Value[]){v_thelabel}, 1)}, 1));
    alg_root_top = rt_base;
    return ret_500;
    Value ret_501 = alg_nil();
    alg_root_top = rt_base;
    return ret_501;
}

static Value m_cemitter_depthofloop_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    {
        int32_t rt_630 = alg_root_top;
        Value v_i = alg_subtract(alg_property(alg_property(v_this, "LoopLabels"), "Length"), alg_int(1));
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_greater_equal(v_i, alg_int(0))); (v_i = alg_subtract(v_i, alg_int(1)))) {
            if (alg_truthy(alg_equal(f_foldcase(NULL, (Value[]){alg_str(alg_subscript_get(alg_property(v_this, "LoopLabels"), v_i))}, 1), f_foldcase(NULL, (Value[]){v_thelabel}, 1)))) {
                Value ret_502 = alg_cast(alg_subscript_get(alg_property(v_this, "LoopDepths"), v_i), "Integer");
                alg_root_top = rt_base;
                return ret_502;
            }
        }
        alg_root_top = rt_630;
    }
    Value ret_503 = alg_property(v_this, "LoopTryDepth");
    alg_root_top = rt_base;
    return ret_503;
    Value ret_504 = alg_nil();
    alg_root_top = rt_base;
    return ret_504;
}

static Value m_cemitter_popframesto_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_from = alg_widen(args[0], "Integer");
    (void)v_from;
    alg_root(&v_from, 1);
    {
        int32_t rt_631 = alg_root_top;
        Value v_i = v_from;
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less(v_i, alg_property(v_this, "TryDepth"))); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("alg_pop_frame();")}, 1));
        }
        alg_root_top = rt_631;
    }
    Value ret_505 = alg_nil();
    alg_root_top = rt_base;
    return ret_505;
}

static Value m_cemitter_visitbreakstmt_1_breakstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "BreakStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    if (alg_truthy(alg_equal(alg_property(v_thestmt, "Label"), alg_string("")))) {
        {
            (void)(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_property(v_this, "LoopTryDepth")}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("break;")}, 1));
            Value ret_506 = alg_nil();
            alg_root_top = rt_base;
            return ret_506;
        }
    }
    (void)(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_invoke(v_this, "DepthOfLoop", (Value[]){alg_property(v_thestmt, "Label")}, 1)}, 1));
    Value v_target = alg_invoke(v_this, "BreakTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1);
    (void)v_target;
    alg_root(&v_target, 1);
    (void)(alg_invoke(alg_property(v_this, "Jumped"), "Add", (Value[]){v_target}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("goto "), v_target), alg_char_value(59))}, 1));
    Value ret_507 = alg_nil();
    alg_root_top = rt_base;
    return ret_507;
}

static Value m_cemitter_visitcontinuestmt_1_continuestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ContinueStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    if (alg_truthy(alg_equal(alg_property(v_thestmt, "Label"), alg_string("")))) {
        {
            (void)(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_property(v_this, "LoopTryDepth")}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_string("continue;")}, 1));
            Value ret_508 = alg_nil();
            alg_root_top = rt_base;
            return ret_508;
        }
    }
    (void)(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_invoke(v_this, "DepthOfLoop", (Value[]){alg_property(v_thestmt, "Label")}, 1)}, 1));
    Value v_target = alg_invoke(v_this, "ContinueTarget", (Value[]){alg_property(v_thestmt, "Label")}, 1);
    (void)v_target;
    alg_root(&v_target, 1);
    (void)(alg_invoke(alg_property(v_this, "Jumped"), "Add", (Value[]){v_target}, 1));
    (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("goto "), v_target), alg_char_value(59))}, 1));
    Value ret_509 = alg_nil();
    alg_root_top = rt_base;
    return ret_509;
}

static Value m_cemitter_visitlabelstmt_1_labelstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "LabelStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    if (alg_truthy(alg_property(v_thestmt, "Targeted"))) {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_invoke(v_this, "GotoTarget", (Value[]){alg_str(alg_property(alg_property(v_thestmt, "Name"), "Lexeme"))}, 1), alg_string(": ;"))}, 1));
    }
    (void)(alg_invoke(v_this, "Execute", (Value[]){alg_property(v_thestmt, "Inner")}, 1));
    Value ret_510 = alg_nil();
    alg_root_top = rt_base;
    return ret_510;
}

static Value m_cemitter_visitvargroupstmt_1_vargroupstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "VarGroupStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    Value v_shared = alg_nil();
    (void)v_shared;
    alg_root(&v_shared, 1);
    (void)((v_value = alg_string("alg_nil()")));
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Initializer"), alg_nil()))) {
        (void)((v_value = alg_invoke(v_this, "Evaluate", (Value[]){alg_property(v_thestmt, "Initializer")}, 1)));
    }
    (void)((v_shared = alg_add(alg_string("shared_"), alg_str(alg_property(v_this, "Loops")))));
    (void)(alg_set_property(v_this, "Loops", alg_add(alg_property(v_this, "Loops"), alg_int(1))));
    if (alg_truthy(alg_property(v_this, "AtTopLevel"))) {
        {
            (void)(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_add(alg_add(alg_add(alg_string("static Value "), v_shared), alg_char_value(59)), alg_char_value(10))}, 1));
            (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_add(v_shared, alg_string(" = ")), v_value), alg_char_value(59))}, 1));
        }
    } else {
        (void)(alg_invoke(v_this, "DeclareLocal", (Value[]){v_shared, v_value}, 2));
    }
    {
        int32_t rt_632 = alg_root_top;
        Value loop_511 = alg_iterable(alg_property(v_thestmt, "Names"));
        (void)loop_511;
        alg_root(&loop_511, 1);
        for (int32_t at_511 = 0; at_511 < alg_iterable_count(loop_511); at_511++) {
            int32_t rt_633 = alg_root_top;
            Value v_thename = alg_iterable_at(loop_511, at_511);
            (void)v_thename;
            alg_root(&v_thename, 1);
            {
                int32_t rt_634 = alg_root_top;
                Value v_name = alg_str(alg_property(v_thename, "Lexeme"));
                (void)v_name;
                alg_root(&v_name, 1);
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
                            (void)(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1), v_shared}, 2));
                        }
                    }
                }
                alg_root_top = rt_634;
            }
            alg_root_top = rt_633;
        }
        alg_root_top = rt_632;
    }
    Value ret_512 = alg_nil();
    alg_root_top = rt_base;
    return ret_512;
}

static Value m_cemitter_visitmodulestmt_1_modulestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ModuleStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    if (alg_truthy(alg_not(alg_property(v_this, "AtTopLevel")))) {
        (void)(alg_invoke(v_this, "Unsupported", (Value[]){alg_string("A nested 'uses'")}, 1));
    }
    if (alg_truthy(alg_not_equal(alg_property(v_thestmt, "Statements"), alg_nil()))) {
        (void)(alg_invoke(v_this, "Line", (Value[]){alg_add(alg_add(alg_string("init_"), alg_invoke(v_this, "UnitNameOf", (Value[]){alg_str(alg_property(v_thestmt, "FileName"))}, 1)), alg_string("();"))}, 1));
    }
    Value ret_513 = alg_nil();
    alg_root_top = rt_base;
    return ret_513;
}

static Value *roots_CEmitter[] = {
    &v_hoistVabove,
    &fn_indentation,
    &fn_quotec,
    &k_emitunit,
    &k_cemitter,
};

void init_CEmitter(void) {
    alg_roots(roots_CEmitter, 5);
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
    alg_class_field(k_cemitter, "RootSymbols");
    alg_class_field(k_cemitter, "RootMarks");
    alg_class_field(k_cemitter, "FrameRoots");
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
    alg_class_field(k_cemitter, "CollectingInto");
    alg_class_field(k_cemitter, "DeclaredIn");
    alg_class_field(k_cemitter, "VisibleDeclared");
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
    alg_class_field(k_cemitter, "ImportedFrom");
    alg_class_field(k_cemitter, "AmbiguousImports");
    alg_class_field(k_cemitter, "AmbiguousMembers");
    alg_class_field(k_cemitter, "Boxed");
    alg_class_field(k_cemitter, "Cells");
    alg_class_field(k_cemitter, "Captured");
    alg_class_field(k_cemitter, "Globals");
    alg_class_field(k_cemitter, "TopLevel");
    alg_class_field(k_cemitter, "GlobalsIn");
    alg_class_field(k_cemitter, "UnitExports");
    alg_class_field(k_cemitter, "UnitAll");
    alg_class_field(k_cemitter, "ShadowNames");
    alg_class_field(k_cemitter, "ShadowArities");
    alg_class_field(k_cemitter, "ShadowWhole");
    alg_class_field(k_cemitter, "Canonical");
    alg_class_field(k_cemitter, "InsideNested");
    alg_class_field(k_cemitter, "NestedIn");
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
    alg_class_method(k_cemitter, "IsOverloadSet", m_cemitter_isoverloadset_1_string, 1, t_cemitter_isoverloadset_1_string);
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
    alg_class_method(k_cemitter, "Root", m_cemitter_root_2_string_string, 2, t_cemitter_root_2_string_string);
    alg_class_method(k_cemitter, "DeclareLocal", m_cemitter_declarelocal_2_string_string, 2, t_cemitter_declarelocal_2_string_string);
    alg_class_method(k_cemitter, "EmitReturn", m_cemitter_emitreturn_1_string, 1, t_cemitter_emitreturn_1_string);
    alg_class_method(k_cemitter, "OpenRoots", m_cemitter_openroots_1_boolean, 1, t_cemitter_openroots_1_boolean);
    alg_class_method(k_cemitter, "CloseRoots", m_cemitter_closeroots_1_string, 1, t_cemitter_closeroots_1_string);
    alg_class_method(k_cemitter, "DeclaresLocal", m_cemitter_declareslocal_1_list, 1, t_cemitter_declareslocal_1_list);
    alg_class_method(k_cemitter, "DeclareCell", m_cemitter_declarecell_2_string_string, 2, t_cemitter_declarecell_2_string_string);
    alg_class_method(k_cemitter, "HoistCells", m_cemitter_hoistcells_1_list, 1, t_cemitter_hoistcells_1_list);
    alg_class_method(k_cemitter, "EmitHandlerBody", m_cemitter_emithandlerbody_2_string, 2, t_cemitter_emithandlerbody_2_string);
    alg_class_method(k_cemitter, "DeclaredTypes", m_cemitter_declaredtypes_1, 1, t_cemitter_declaredtypes_1);
    alg_class_method(k_cemitter, "ParameterTable", m_cemitter_parametertable_1, 1, t_cemitter_parametertable_1);
    alg_class_method(k_cemitter, "CollectShadowArities", m_cemitter_collectshadowarities_2_list_list, 2, t_cemitter_collectshadowarities_2_list_list);
    alg_class_method(k_cemitter, "TakesOver", m_cemitter_takesover_2_string_integer, 2, t_cemitter_takesover_2_string_integer);
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
    alg_class_method(k_cemitter, "OwnGlobal", m_cemitter_ownglobal_1_string, 1, t_cemitter_ownglobal_1_string);
    alg_class_method(k_cemitter, "VisibleSubprogram", m_cemitter_visiblesubprogram_1_string, 1, t_cemitter_visiblesubprogram_1_string);
    alg_class_method(k_cemitter, "MissingName", m_cemitter_missingname_1_string, 1, t_cemitter_missingname_1_string);
    alg_class_method(k_cemitter, "Spelled", m_cemitter_spelled_1_string, 1, t_cemitter_spelled_1_string);
    alg_class_method(k_cemitter, "Unreachable", m_cemitter_unreachable_1_string, 1, t_cemitter_unreachable_1_string);
    alg_class_method(k_cemitter, "BoundValue", m_cemitter_boundvalue_3_string, 3, t_cemitter_boundvalue_3_string);
    alg_class_method(k_cemitter, "Elidable", m_cemitter_elidable_2, 2, t_cemitter_elidable_2);
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
    alg_class_method(k_cemitter, "InvokingOr", m_cemitter_invokingor_5_string_string_list_list_string, 5, t_cemitter_invokingor_5_string_string_list_list_string);
    alg_class_method(k_cemitter, "OverloadedElsewhere", m_cemitter_overloadedelsewhere_2_string_string, 2, t_cemitter_overloadedelsewhere_2_string_string);
    alg_class_method(k_cemitter, "ExtensionValue", m_cemitter_extensionvalue_1_getexpr, 1, t_cemitter_extensionvalue_1_getexpr);
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
