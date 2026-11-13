/* Generated from Algol-24.  Do not edit. */
#include "CEmitter.h"
#include "Console.h"
#include "Expr.h"
#include "ObjFunction.h"
#include "SourceCode.h"
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
static Value or_100;
static Value or_101;
static Value or_102;
static Value or_103;
static Value or_104;
static Value or_105;
static Value or_106;
static Value or_107;
static Value or_108;
static Value or_109;
static Value or_110;
static Value or_111;
static Value or_112;
static Value or_113;
static Value or_114;
static Value or_115;
static Value or_116;
static Value or_117;
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
static const char *t_cemitter_executeheld_2_string[] = { "TheStmt : Any", "Mark : String" };
static const char *t_cemitter_voidcall_1_string[] = { "Text : String" };
static const char *t_cemitter_needshold_1[] = { "TheExpr : Any" };
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
static const char *t_cemitter_visibleglobal_1_string[] = { "Name : String" };
static const char *t_cemitter_visiblesubprogram_1_string[] = { "Name : String" };
static const char *t_cemitter_missing_2_string_token[] = { "Name : String", "Where : Token" };
static const char *t_cemitter_missingname_1_string[] = { "Name : String" };
static const char *t_cemitter_spelled_1_string[] = { "Name : String" };
static const char *t_cemitter_unreachable_1_string[] = { "Name : String" };
static const char *t_cemitter_boundvalue_3_string[] = { "Declared : Any", "Value : String", "Actual : Any" };
static const char *t_cemitter_elidable_2[] = { "Declared : Any", "Actual : Any" };
static const char *t_cemitter_visitassignexpr_1_assignexpr[] = { "TheExpr : AssignExpr" };
static const char *t_cemitter_visitgrouping_1_groupingexpr[] = { "TheExpr : GroupingExpr" };
static const char *t_cemitter_declarestype_1_string[] = { "Name : String" };
static const char *t_cemitter_resolvedkind_1_string[] = { "Name : String" };
static const char *t_cemitter_builtintypename_1_string[] = { "Name : String" };
static const char *t_cemitter_resolvedclass_1_string[] = { "Name : String" };
static const char *t_cemitter_visitisexpr_1_isexpr[] = { "TheExpr : IsExpr" };
static const char *t_cemitter_visitunary_1_unaryexpr[] = { "TheExpr : UnaryExpr" };
static const char *t_cemitter_visitbinary_1_binaryexpr[] = { "TheExpr : BinaryExpr" };
static const char *t_cemitter_builtincounts_1_string[] = { "Name : String" };
static const char *t_cemitter_countsmessage_2_list_integer[] = { "Counts : List", "Got : Integer" };
static const char *t_cemitter_countsphrase_1_list[] = { "Counts : List" };
static const char *t_cemitter_renamesof_2_string_string[] = { "Unit : String", "Name : String" };
static const char *t_cemitter_markambiguousimport_3_string_string_string[] = { "Name : String", "First : String", "Second : String" };
static const char *t_cemitter_markambiguousmember_3_string_string_string[] = { "Member : String", "First : String", "Second : String" };
static const char *t_cemitter_ambiguousmessage_2_string_string[] = { "Written : String", "Owners : String" };
static const char *t_cemitter_isassertion_1_string[] = { "Name : String" };
static const char *t_cemitter_builtinhandle_1_string[] = { "Name : String" };
static const char *t_cemitter_emitbuiltinthunk_3_string_string_list[] = { "Symbol : String", "Name : String", "Counts : List" };
static const char *t_cemitter_voidbuiltin_1_string[] = { "Name : String" };
static const char *t_cemitter_builtin_2_string_integer[] = { "Name : String", "Count : Integer" };
static const char *t_cemitter_joiningbuiltin_2_string_list[] = { "Name : String", "Arguments : List" };
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
static const char *t_cemitter_boundargument_3_integer[] = { "Called : Any", "Types : Any", "I : Integer" };
static const char *t_cemitter_reportedname_1[] = { "TheStmt : Any" };
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
    Value v_depth = alg_param_of(args[0], "Integer", "Indentation");
    (void)v_depth;
    alg_root(&v_depth, 1);
    int32_t rh_1474 = alg_hold_top;
    Value v_result = alg_literal("");
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_1474;
    {
        int32_t rt_1475 = alg_root_top;
        int32_t rh_1476 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1476;
        {
            int32_t rh_1477 = alg_hold_top;
            for (; (alg_hold_top = rh_1477, alg_truthy(alg_hold(alg_less(v_i, v_depth)))); (alg_hold_top = rh_1477, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                (void)((v_result = alg_hold(alg_add(v_result, alg_literal("    ")))));
            }
        }
        alg_hold_top = rh_1476;
        alg_root_top = rt_1475;
    }
    alg_hold_top = rh_1474;
    Value ret_0 = v_result;
    alg_root_top = rt_base;
    return ret_0;
    alg_hold_top = rh_1474;
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
    int32_t rh_1478 = alg_hold_top;
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_1478;
    (void)((v_result = alg_hold(alg_str(alg_char_value(34)))));
    alg_hold_top = rh_1478;
    {
        int32_t rt_1479 = alg_root_top;
        int32_t rh_1480 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1480;
        {
            int32_t rh_1481 = alg_hold_top;
            for (; (alg_hold_top = rh_1481, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_text_length(v_text)))))); (alg_hold_top = rh_1481, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1482 = alg_root_top;
                    int32_t rh_1483 = alg_hold_top;
                    Value v_c = alg_hold(alg_subscript_get(alg_hold(alg_str(v_text)), v_i));
                    (void)v_c;
                    alg_root(&v_c, 1);
                    alg_hold_top = rh_1483;
                    if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(34))))) {
                        (void)((v_result = alg_hold(alg_add(v_result, alg_literal("\\\"")))));
                    } else {
                        if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(92))))) {
                            (void)((v_result = alg_hold(alg_add(v_result, alg_literal("\\\\")))));
                        } else {
                            if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(10))))) {
                                (void)((v_result = alg_hold(alg_add(v_result, alg_literal("\\n")))));
                            } else {
                                if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(9))))) {
                                    (void)((v_result = alg_hold(alg_add(v_result, alg_literal("\\t")))));
                                } else {
                                    if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(13))))) {
                                        (void)((v_result = alg_hold(alg_add(v_result, alg_literal("\\r")))));
                                    } else {
                                        (void)((v_result = alg_hold(alg_add(v_result, alg_hold(alg_str(v_c))))));
                                    }
                                }
                            }
                        }
                    }
                    alg_hold_top = rh_1483;
                    alg_root_top = rt_1482;
                }
            }
        }
        alg_hold_top = rh_1480;
        alg_root_top = rt_1479;
    }
    alg_hold_top = rh_1478;
    Value ret_2 = alg_hold(alg_add(v_result, alg_hold(alg_str(alg_char_value(34)))));
    alg_root_top = rt_base;
    return ret_2;
    alg_hold_top = rh_1478;
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
    int32_t rh_1484 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Name", v_name)));
    alg_hold_top = rh_1484;
    (void)(alg_hold(alg_set_property(v_this, "Statements", v_statements)));
    alg_hold_top = rh_1484;
    (void)(alg_hold(alg_set_property(v_this, "Imports", v_imports)));
    alg_hold_top = rh_1484;
    (void)(alg_hold(alg_set_property(v_this, "PrivateNames", v_privatenames)));
    alg_hold_top = rh_1484;
    (void)(alg_hold(alg_set_property(v_this, "FileName", v_filename)));
    alg_hold_top = rh_1484;
    Value ret_4 = alg_nil();
    alg_root_top = rt_base;
    return ret_4;
}

static Value i_cemitter(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_set_property(v_this, "Declarations", alg_widen(alg_hold(alg_buffer(alg_int(0))), "Buffer"));
    alg_set_property(v_this, "RootSymbols", alg_widen(alg_hold(alg_list()), "List"));
    alg_set_property(v_this, "RootMarks", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "FrameRoots", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "Functions", alg_widen(alg_hold(alg_buffer(alg_int(0))), "Buffer"));
    alg_set_property(v_this, "MainBody", alg_widen(alg_hold(alg_buffer(alg_int(0))), "Buffer"));
    alg_set_property(v_this, "Setup", alg_widen(alg_hold(alg_buffer(alg_int(0))), "Buffer"));
    alg_set_property(v_this, "Shells", alg_widen(alg_hold(alg_buffer(alg_int(0))), "Buffer"));
    alg_set_property(v_this, "Body", alg_widen(alg_hold(alg_buffer(alg_int(0))), "Buffer"));
    alg_set_property(v_this, "TestSymbols", alg_nil());
    alg_set_property(v_this, "Header", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "UnitName", alg_widen(alg_literal("Main"), "String"));
    alg_set_property(v_this, "PrivateNames", alg_nil());
    alg_set_property(v_this, "RootUnit", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "UnitTests", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "Target", alg_widen(alg_literal("main"), "String"));
    alg_set_property(v_this, "Depth", alg_widen(alg_int(1), "Integer"));
    alg_set_property(v_this, "AtTopLevel", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "Locals", alg_nil());
    alg_set_property(v_this, "Declared", alg_nil());
    alg_set_property(v_this, "CollectingInto", alg_nil());
    alg_set_property(v_this, "DeclaredIn", alg_nil());
    alg_set_property(v_this, "VisibleDeclared", alg_nil());
    alg_set_property(v_this, "ClassesIn", alg_nil());
    alg_set_property(v_this, "ClassCounts", alg_nil());
    alg_set_property(v_this, "VisibleClasses", alg_nil());
    alg_set_property(v_this, "Logicals", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "Loops", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "TryDepth", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "LoopTryDepth", alg_widen(alg_int(0), "Integer"));
    alg_set_property(v_this, "LoopLabels", alg_widen(alg_hold(alg_list()), "List"));
    alg_set_property(v_this, "LoopDepths", alg_widen(alg_hold(alg_list()), "List"));
    alg_set_property(v_this, "Jumped", alg_widen(alg_hold(alg_list()), "Set"));
    alg_set_property(v_this, "LabelDepths", alg_widen(alg_hold(alg_list()), "List"));
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
    alg_set_property(v_this, "Warned", alg_nil());
    alg_set_property(v_this, "BuiltinThunks", alg_nil());
    alg_set_property(v_this, "Canonical", alg_nil());
    alg_set_property(v_this, "InsideNested", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "NestedIn", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "EmitTests", alg_widen(alg_bool(false), "Boolean"));
    alg_set_property(v_this, "Tests", alg_nil());
    alg_set_property(v_this, "TestFiles", alg_nil());
    alg_set_property(v_this, "CurrentFile", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "SourceFile", alg_widen(alg_literal(""), "String"));
    alg_set_property(v_this, "Classes", alg_nil());
    alg_set_property(v_this, "OwnClasses", alg_nil());
    alg_set_property(v_this, "Objects", alg_nil());
    alg_set_property(v_this, "EnumTypes", alg_nil());
    alg_set_property(v_this, "EnumMembers", alg_nil());
    alg_set_property(v_this, "CurrentClass", alg_widen(alg_literal(""), "String"));
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
    int32_t rh_1485 = alg_hold_top;
    (void)(alg_hold(alg_set_property(v_this, "Locals", alg_hold(alg_list()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Declared", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Classes", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "OwnClasses", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Objects", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "EnumTypes", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "EnumMembers", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "VisibleFields", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "VisibleMethods", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Renames", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "AmbiguousMembers", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "AmbiguousImports", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Renamed", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "ImportedFrom", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Overloaded", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "OverloadsIn", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Tables", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "SetsBuilt", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Boxed", alg_hold(alg_list()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Cells", alg_hold(alg_list()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Captured", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Globals", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "GlobalsIn", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "DeclaredIn", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "CollectingInto", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "VisibleDeclared", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "ClassesIn", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "ClassCounts", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "VisibleClasses", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "TopLevel", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "UnitExports", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "UnitAll", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "ShadowNames", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Warned", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "BuiltinThunks", alg_hold(alg_set()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Canonical", alg_hold(alg_map()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "Tests", alg_hold(alg_list()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "TestFiles", alg_hold(alg_list()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "TestSymbols", alg_hold(alg_list()))));
    alg_hold_top = rh_1485;
    (void)(alg_hold(alg_set_property(v_this, "PrivateNames", alg_hold(alg_list()))));
    alg_hold_top = rh_1485;
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
    int32_t rh_1486 = alg_hold_top;
    alg_raise(alg_hold(alg_add(alg_hold(alg_str(v_construct)), alg_literal(" is not supported by the C back end yet."))));
    alg_hold_top = rh_1486;
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
    int32_t rh_1487 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "Target"), alg_literal("body"))))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Body"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(f_indentation(NULL, (Value[]){alg_property(v_this, "Depth")}, 1)), alg_hold(alg_str(v_text)))), alg_char_value(10)))}, 1)));
    } else {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(f_indentation(NULL, (Value[]){alg_property(v_this, "Depth")}, 1)), alg_hold(alg_str(v_text)))), alg_char_value(10)))}, 1)));
    }
    alg_hold_top = rh_1487;
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
    int32_t rh_1488 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Renames"), "Contains", (Value[]){alg_hold(alg_str(v_name))}, 1)))) {
        Value ret_8 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_prefix, alg_hold(alg_invoke(v_this, "Escaped", (Value[]){alg_hold(alg_str(v_name))}, 1)))), alg_literal("__"))), alg_hold(alg_invoke(v_this, "Escaped", (Value[]){alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "Renames"), "Get", (Value[]){alg_hold(alg_str(v_name))}, 1))))}, 1))));
        alg_root_top = rt_base;
        return ret_8;
    }
    alg_hold_top = rh_1488;
    Value ret_9 = alg_hold(alg_invoke(v_this, "SymbolOf", (Value[]){v_prefix, alg_hold(alg_str(v_name))}, 2));
    alg_root_top = rt_base;
    return ret_9;
    alg_hold_top = rh_1488;
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
    int32_t rh_1489 = alg_hold_top;
    Value ret_11 = alg_hold(alg_add(v_prefix, alg_hold(alg_invoke(v_this, "Escaped", (Value[]){v_name}, 1))));
    alg_root_top = rt_base;
    return ret_11;
    alg_hold_top = rh_1489;
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
    int32_t rh_1490 = alg_hold_top;
    Value ret_13 = alg_hold(alg_invoke(v_this, "Mangle", (Value[]){alg_literal("k_"), v_name}, 2));
    alg_root_top = rt_base;
    return ret_13;
    alg_hold_top = rh_1490;
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
    int32_t rh_1491 = alg_hold_top;
    Value ret_15 = alg_hold(alg_invoke(v_this, "SymbolOf", (Value[]){alg_literal("i_"), v_name}, 2));
    alg_root_top = rt_base;
    return ret_15;
    alg_hold_top = rh_1491;
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
    int32_t rh_1492 = alg_hold_top;
    Value ret_17 = alg_hold(alg_invoke(v_this, "Mangle", (Value[]){alg_literal("e_"), v_name}, 2));
    alg_root_top = rt_base;
    return ret_17;
    alg_hold_top = rh_1492;
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
    int32_t rh_1493 = alg_hold_top;
    Value ret_19 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(v_this, "Mangle", (Value[]){alg_literal("e_"), v_typename}, 2)), alg_char_value(95))), alg_hold(alg_invoke(v_this, "Escaped", (Value[]){v_member}, 1))));
    alg_root_top = rt_base;
    return ret_19;
    alg_hold_top = rh_1493;
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
    int32_t rh_1494 = alg_hold_top;
    Value v_result = alg_literal("");
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_1494;
    Value v_left = alg_nil();
    (void)v_left;
    alg_root(&v_left, 1);
    alg_hold_top = rh_1494;
    (void)((v_left = v_code));
    alg_hold_top = rh_1494;
    {
        int32_t rt_1495 = alg_root_top;
        int32_t rh_1496 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1496;
        {
            int32_t rh_1497 = alg_hold_top;
            for (; (alg_hold_top = rh_1497, alg_truthy(alg_hold(alg_less(v_i, alg_int(6))))); (alg_hold_top = rh_1497, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_1498 = alg_hold_top;
                    (void)((v_result = alg_hold(alg_add(alg_hold(alg_copy(alg_literal("0123456789ABCDEF"), alg_hold(alg_mod(v_left, alg_int(16))), alg_int(1))), v_result))));
                    alg_hold_top = rh_1498;
                    (void)((v_left = alg_hold(alg_div_int(v_left, alg_int(16)))));
                    alg_hold_top = rh_1498;
                }
            }
        }
        alg_hold_top = rh_1496;
        alg_root_top = rt_1495;
    }
    alg_hold_top = rh_1494;
    Value ret_21 = v_result;
    alg_root_top = rt_base;
    return ret_21;
    alg_hold_top = rh_1494;
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
    int32_t rh_1499 = alg_hold_top;
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_1499;
    (void)((v_result = alg_hold(alg_buffer(alg_int(0)))));
    alg_hold_top = rh_1499;
    {
        int32_t rt_1500 = alg_root_top;
        int32_t rh_1501 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1501;
        {
            int32_t rh_1502 = alg_hold_top;
            for (; (alg_hold_top = rh_1502, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_text_length(v_name)))))); (alg_hold_top = rh_1502, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1503 = alg_root_top;
                    int32_t rh_1504 = alg_hold_top;
                    Value v_c = alg_hold(alg_subscript_get(alg_hold(alg_str(v_name)), v_i));
                    (void)v_c;
                    alg_root(&v_c, 1);
                    alg_hold_top = rh_1504;
                    if (alg_truthy(alg_hold((or_0 = alg_hold(alg_greater_equal(v_c, alg_char_value(97))), !alg_truthy(or_0) ? or_0 : alg_hold(alg_less_equal(v_c, alg_char_value(122))))))) {
                        (void)(alg_hold(alg_invoke(v_result, "Append", (Value[]){alg_hold(alg_str(v_c))}, 1)));
                    } else {
                        if (alg_truthy(alg_hold((or_1 = alg_hold(alg_greater_equal(v_c, alg_char_value(48))), !alg_truthy(or_1) ? or_1 : alg_hold(alg_less_equal(v_c, alg_char_value(57))))))) {
                            (void)(alg_hold(alg_invoke(v_result, "Append", (Value[]){alg_hold(alg_str(v_c))}, 1)));
                        } else {
                            if (alg_truthy(alg_hold((or_2 = alg_hold(alg_greater_equal(v_c, alg_char_value(65))), !alg_truthy(or_2) ? or_2 : alg_hold(alg_less_equal(v_c, alg_char_value(90))))))) {
                                (void)(alg_hold(alg_invoke(v_result, "Append", (Value[]){alg_hold(alg_char(alg_hold(alg_add(alg_hold(alg_ord(v_c)), alg_int(32)))))}, 1)));
                            } else {
                                if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(63))))) {
                                    (void)(alg_hold(alg_invoke(v_result, "Append", (Value[]){alg_char_value(81)}, 1)));
                                } else {
                                    if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(33))))) {
                                        (void)(alg_hold(alg_invoke(v_result, "Append", (Value[]){alg_char_value(69)}, 1)));
                                    } else {
                                        if (alg_truthy(alg_hold(alg_equal(v_c, alg_char_value(95))))) {
                                            (void)(alg_hold(alg_invoke(v_result, "Append", (Value[]){alg_char_value(86)}, 1)));
                                        } else {
                                            (void)(alg_hold(alg_invoke(v_result, "Append", (Value[]){alg_hold(alg_add(alg_char_value(85), alg_hold(alg_invoke(v_this, "HexOf", (Value[]){alg_hold(alg_ord(v_c))}, 1))))}, 1)));
                                        }
                                    }
                                }
                            }
                        }
                    }
                    alg_hold_top = rh_1504;
                    alg_root_top = rt_1503;
                }
            }
        }
        alg_hold_top = rh_1501;
        alg_root_top = rt_1500;
    }
    alg_hold_top = rh_1499;
    Value ret_23 = alg_hold(alg_property(v_result, "Text"));
    alg_root_top = rt_base;
    return ret_23;
    alg_hold_top = rh_1499;
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
    int32_t rh_1505 = alg_hold_top;
    Value v_result = alg_literal("");
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_1505;
    {
        int32_t rt_1506 = alg_root_top;
        int32_t rh_1507 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1507;
        {
            int32_t rh_1508 = alg_hold_top;
            for (; (alg_hold_top = rh_1508, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_text_length(v_text)))))); (alg_hold_top = rh_1508, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1509 = alg_root_top;
                    int32_t rh_1510 = alg_hold_top;
                    Value v_c = alg_hold(alg_subscript_get(alg_hold(alg_str(v_text)), v_i));
                    (void)v_c;
                    alg_root(&v_c, 1);
                    alg_hold_top = rh_1510;
                    if (alg_truthy(alg_hold((or_7 = alg_hold((or_5 = (alg_hold((or_3 = alg_hold(alg_greater_equal(v_c, alg_char_value(97))), !alg_truthy(or_3) ? or_3 : alg_hold(alg_less_equal(v_c, alg_char_value(122)))))), alg_truthy(or_5) ? or_5 : (alg_hold((or_4 = alg_hold(alg_greater_equal(v_c, alg_char_value(65))), !alg_truthy(or_4) ? or_4 : alg_hold(alg_less_equal(v_c, alg_char_value(90)))))))), alg_truthy(or_7) ? or_7 : (alg_hold((or_6 = alg_hold(alg_greater_equal(v_c, alg_char_value(48))), !alg_truthy(or_6) ? or_6 : alg_hold(alg_less_equal(v_c, alg_char_value(57)))))))))) {
                        (void)((v_result = alg_hold(alg_add(v_result, alg_hold(alg_str(v_c))))));
                    } else {
                        (void)((v_result = alg_hold(alg_add(v_result, alg_char_value(95)))));
                    }
                    alg_hold_top = rh_1510;
                    alg_root_top = rt_1509;
                }
            }
        }
        alg_hold_top = rh_1507;
        alg_root_top = rt_1506;
    }
    alg_hold_top = rh_1505;
    Value ret_25 = v_result;
    alg_root_top = rt_base;
    return ret_25;
    alg_hold_top = rh_1505;
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
    int32_t rh_1511 = alg_hold_top;
    Value v_own = alg_nil();
    (void)v_own;
    alg_root(&v_own, 1);
    alg_hold_top = rh_1511;
    Value v_imports = alg_nil();
    (void)v_imports;
    alg_root(&v_imports, 1);
    alg_hold_top = rh_1511;
    (void)((v_own = alg_hold(alg_list())));
    alg_hold_top = rh_1511;
    (void)((v_imports = alg_hold(alg_list())));
    alg_hold_top = rh_1511;
    {
        int32_t rt_1512 = alg_root_top;
        Value loop_27 = alg_iterable(v_statements);
        (void)loop_27;
        alg_root(&loop_27, 1);
        for (int32_t at_27 = 0; at_27 < alg_iterable_count(loop_27); at_27++) {
            alg_safe_point();
            int32_t rt_1513 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_27, at_27);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rh_1514 = alg_hold_top;
                if (alg_truthy(alg_is_class(v_thestmt, k_modulestmt))) {
                    {
                        int32_t rt_1515 = alg_root_top;
                        int32_t rh_1516 = alg_hold_top;
                        Value v_modulename = alg_hold(alg_invoke(v_this, "UnitNameOf", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "FileName"))))}, 1));
                        (void)v_modulename;
                        alg_root(&v_modulename, 1);
                        alg_hold_top = rh_1516;
                        (void)(alg_hold(alg_invoke(v_imports, "Add", (Value[]){v_modulename}, 1)));
                        alg_hold_top = rh_1516;
                        if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Statements")), alg_nil())))) {
                            (void)(alg_hold(alg_invoke(v_this, "CollectUnits", (Value[]){alg_hold(alg_property(v_thestmt, "Statements")), v_modulename, alg_hold(alg_property(v_thestmt, "PrivateNames")), v_units, alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "FileName"))))}, 5)));
                        }
                        alg_hold_top = rh_1516;
                        alg_root_top = rt_1515;
                    }
                }
                alg_hold_top = rh_1514;
                (void)(alg_hold(alg_invoke(v_own, "Add", (Value[]){v_thestmt}, 1)));
                alg_hold_top = rh_1514;
            }
            alg_root_top = rt_1513;
        }
        alg_root_top = rt_1512;
    }
    alg_hold_top = rh_1511;
    (void)(alg_hold(alg_invoke(v_units, "Add", (Value[]){alg_hold(alg_new(k_emitunit, (Value[]){v_name, v_own, v_imports, v_privates, v_filename}, 5))}, 1)));
    alg_hold_top = rh_1511;
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
    int32_t rh_1517 = alg_hold_top;
    Value v_start = alg_nil();
    (void)v_start;
    alg_root(&v_start, 1);
    alg_hold_top = rh_1517;
    Value v_stem = alg_nil();
    (void)v_stem;
    alg_root(&v_stem, 1);
    alg_hold_top = rh_1517;
    (void)((v_start = alg_int(0)));
    alg_hold_top = rh_1517;
    {
        int32_t rt_1518 = alg_root_top;
        int32_t rh_1519 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1519;
        {
            int32_t rh_1520 = alg_hold_top;
            for (; (alg_hold_top = rh_1520, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_text_length(v_key)))))); (alg_hold_top = rh_1520, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_subscript_get(v_key, v_i)), alg_char_value(47))))) {
                    (void)((v_start = alg_hold(alg_add(v_i, alg_int(1)))));
                }
            }
        }
        alg_hold_top = rh_1519;
        alg_root_top = rt_1518;
    }
    alg_hold_top = rh_1517;
    (void)((v_stem = alg_hold(alg_copy(v_key, v_start, alg_hold(alg_subtract(alg_hold(alg_text_length(v_key)), v_start))))));
    alg_hold_top = rh_1517;
    if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_text_length(v_stem)), alg_int(4))))) {
        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_copy(v_stem, alg_hold(alg_subtract(alg_hold(alg_text_length(v_stem)), alg_int(4))), alg_int(4))), alg_literal(".a24"))))) {
            (void)((v_stem = alg_hold(alg_copy(v_stem, alg_int(0), alg_hold(alg_subtract(alg_hold(alg_text_length(v_stem)), alg_int(4)))))));
        }
    }
    alg_hold_top = rh_1517;
    Value ret_29 = alg_hold(alg_invoke(v_this, "Sanitize", (Value[]){v_stem}, 1));
    alg_root_top = rt_base;
    return ret_29;
    alg_hold_top = rh_1517;
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
    int32_t rh_1521 = alg_hold_top;
    Value ret_31 = alg_hold(alg_invoke(v_this, "Mangle", (Value[]){alg_literal("v_"), v_name}, 2));
    alg_root_top = rt_base;
    return ret_31;
    alg_hold_top = rh_1521;
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
    int32_t rh_1522 = alg_hold_top;
    Value ret_33 = alg_hold(alg_invoke(v_this, "Mangle", (Value[]){alg_literal("d_"), v_name}, 2));
    alg_root_top = rt_base;
    return ret_33;
    alg_hold_top = rh_1522;
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
    int32_t rh_1523 = alg_hold_top;
    Value ret_35 = alg_hold(alg_invoke(v_this, "Mangle", (Value[]){alg_literal("f_"), v_name}, 2));
    alg_root_top = rt_base;
    return ret_35;
    alg_hold_top = rh_1523;
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
    int32_t rh_1524 = alg_hold_top;
    Value ret_37 = alg_hold(alg_invoke(v_this, "Mangle", (Value[]){alg_literal("fn_"), v_name}, 2));
    alg_root_top = rt_base;
    return ret_37;
    alg_hold_top = rh_1524;
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
    int32_t rh_1525 = alg_hold_top;
    Value ret_39 = alg_hold(alg_invoke(v_this, "Mangle", (Value[]){alg_literal("o_"), v_name}, 2));
    alg_root_top = rt_base;
    return ret_39;
    alg_hold_top = rh_1525;
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
    int32_t rh_1526 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_41 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_41;
    }
    alg_hold_top = rh_1526;
    {
        int32_t rt_1527 = alg_root_top;
        Value loop_42 = alg_iterable(alg_hold(alg_invoke(alg_property(v_this, "ImportedFrom"), "Keys", NULL, 0)));
        (void)loop_42;
        alg_root(&loop_42, 1);
        for (int32_t at_42 = 0; at_42 < alg_iterable_count(loop_42); at_42++) {
            alg_safe_point();
            int32_t rt_1528 = alg_root_top;
            Value v_key = alg_iterable_at(loop_42, at_42);
            (void)v_key;
            alg_root(&v_key, 1);
            {
                int32_t rh_1529 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_not_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(v_key))}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1)))))) {
                    continue;
                }
                alg_hold_top = rh_1529;
                Value ret_43 = alg_hold(alg_invoke(v_this, "OverloadedElsewhere", (Value[]){alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "ImportedFrom"), "Get", (Value[]){v_key}, 1)))), v_name}, 2));
                alg_root_top = rt_base;
                return ret_43;
                alg_hold_top = rh_1529;
            }
            alg_root_top = rt_1528;
        }
        alg_root_top = rt_1527;
    }
    alg_hold_top = rh_1526;
    Value ret_44 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_44;
    alg_hold_top = rh_1526;
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
    int32_t rh_1530 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsOverloadSet", (Value[]){v_name}, 1)))) {
        Value ret_46 = alg_hold(alg_invoke(v_this, "SetName", (Value[]){v_name}, 1));
        alg_root_top = rt_base;
        return ret_46;
    }
    alg_hold_top = rh_1530;
    Value ret_47 = alg_hold(alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1));
    alg_root_top = rt_base;
    return ret_47;
    alg_hold_top = rh_1530;
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
    int32_t rh_1531 = alg_hold_top;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    alg_hold_top = rh_1531;
    Value v_name = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))));
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_1531;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1)))))) {
        (void)((v_symbol = alg_hold(alg_invoke(v_this, "FunctionName", (Value[]){v_name}, 1))));
    } else {
        {
            int32_t rt_1532 = alg_root_top;
            int32_t rh_1533 = alg_hold_top;
            (void)((v_symbol = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(v_this, "FunctionName", (Value[]){v_name}, 1)), alg_char_value(95))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length"))))))));
            alg_hold_top = rh_1533;
            Value v_types = alg_hold(alg_invoke(v_this, "DeclaredTypes", (Value[]){v_thestmt}, 1));
            (void)v_types;
            alg_root(&v_types, 1);
            alg_hold_top = rh_1533;
            {
                int32_t rt_1534 = alg_root_top;
                Value loop_49 = alg_iterable(v_types);
                (void)loop_49;
                alg_root(&loop_49, 1);
                for (int32_t at_49 = 0; at_49 < alg_iterable_count(loop_49); at_49++) {
                    alg_safe_point();
                    int32_t rt_1535 = alg_root_top;
                    Value v_thetype = alg_iterable_at(loop_49, at_49);
                    (void)v_thetype;
                    alg_root(&v_thetype, 1);
                    if (alg_truthy(alg_hold(alg_not_equal(v_thetype, alg_literal("Any"))))) {
                        (void)((v_symbol = alg_hold(alg_add(alg_hold(alg_add(v_symbol, alg_char_value(95))), alg_hold(alg_invoke(v_this, "Escaped", (Value[]){alg_hold(alg_str(v_thetype))}, 1))))));
                    }
                    alg_root_top = rt_1535;
                }
                alg_root_top = rt_1534;
            }
            alg_hold_top = rh_1533;
            alg_root_top = rt_1532;
        }
    }
    alg_hold_top = rh_1531;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "NestedIn"), alg_literal(""))))) {
        (void)((v_symbol = alg_hold(alg_add(alg_hold(alg_add(v_symbol, alg_literal("_in_"))), alg_property(v_this, "NestedIn")))));
    }
    alg_hold_top = rh_1531;
    Value ret_50 = v_symbol;
    alg_root_top = rt_base;
    return ret_50;
    alg_hold_top = rh_1531;
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
    int32_t rh_1536 = alg_hold_top;
    Value v_lead = alg_nil();
    (void)v_lead;
    alg_root(&v_lead, 1);
    alg_hold_top = rh_1536;
    (void)((v_lead = alg_literal("static Value ")));
    alg_hold_top = rh_1536;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Exported", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)))) {
        (void)((v_lead = alg_literal("Value ")));
    }
    alg_hold_top = rh_1536;
    Value ret_52 = alg_hold(alg_add(alg_hold(alg_add(v_lead, alg_hold(alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1)))), alg_literal("(Value **cells, Value *args, int32_t count)")));
    alg_root_top = rt_base;
    return ret_52;
    alg_hold_top = rh_1536;
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
    int32_t rh_1537 = alg_hold_top;
    Value ret_54 = alg_hold((or_14 = alg_hold((or_13 = alg_hold((or_12 = alg_hold((or_11 = alg_hold((or_10 = alg_hold((or_9 = alg_hold((or_8 = alg_is_class(v_thestmt, k_functionstmt), alg_truthy(or_8) ? or_8 : alg_is_class(v_thestmt, k_classstmt))), alg_truthy(or_9) ? or_9 : alg_is_class(v_thestmt, k_objectstmt))), alg_truthy(or_10) ? or_10 : alg_is_class(v_thestmt, k_enumstmt))), alg_truthy(or_11) ? or_11 : alg_is_class(v_thestmt, k_vargroupstmt))), alg_truthy(or_12) ? or_12 : alg_is_class(v_thestmt, k_varstmt))), alg_truthy(or_13) ? or_13 : alg_is_class(v_thestmt, k_subrangestmt))), alg_truthy(or_14) ? or_14 : alg_is_class(v_thestmt, k_modulestmt)));
    alg_root_top = rt_base;
    return ret_54;
    alg_hold_top = rh_1537;
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
    int32_t rh_1538 = alg_hold_top;
    if (alg_truthy(alg_property(v_this, "RootUnit"))) {
        Value ret_56 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_56;
    }
    alg_hold_top = rh_1538;
    Value ret_57 = alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "PrivateNames"), "Contains", (Value[]){v_name}, 1))));
    alg_root_top = rt_base;
    return ret_57;
    alg_hold_top = rh_1538;
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
    int32_t rh_1539 = alg_hold_top;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "RootSymbols"), "Add", (Value[]){v_symbol}, 1)));
    alg_hold_top = rh_1539;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Exported", (Value[]){v_name}, 1)))) {
        {
            int32_t rh_1540 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Value "), v_symbol)), alg_char_value(59))), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_1540;
            (void)(alg_set_property(v_this, "Header", alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_property(v_this, "Header"), alg_literal("extern Value "))), v_symbol)), alg_char_value(59))), alg_char_value(10)))));
            alg_hold_top = rh_1540;
        }
    } else {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static Value "), v_symbol)), alg_char_value(59))), alg_char_value(10)))}, 1)));
    }
    alg_hold_top = rh_1539;
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
    int32_t rh_1541 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "DeclareValue", (Value[]){v_symbol, v_name}, 2)));
    alg_hold_top = rh_1541;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Exported", (Value[]){v_name}, 1)))) {
        {
            int32_t rh_1542 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("bool "), alg_hold(alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)))), alg_char_value(59))), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_1542;
            (void)(alg_set_property(v_this, "Header", alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_property(v_this, "Header"), alg_literal("extern bool "))), alg_hold(alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)))), alg_char_value(59))), alg_char_value(10)))));
            alg_hold_top = rh_1542;
        }
    } else {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static bool "), alg_hold(alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)))), alg_char_value(59))), alg_char_value(10)))}, 1)));
    }
    alg_hold_top = rh_1541;
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
    int32_t rh_1543 = alg_hold_top;
    Value ret_61 = alg_hold(alg_not_equal(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Literal")), alg_nil()));
    alg_root_top = rt_base;
    return ret_61;
    alg_hold_top = rh_1543;
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
    int32_t rh_1544 = alg_hold_top;
    {
        int32_t rt_1545 = alg_root_top;
        Value loop_63 = alg_iterable(v_statements);
        (void)loop_63;
        alg_root(&loop_63, 1);
        for (int32_t at_63 = 0; at_63 < alg_iterable_count(loop_63); at_63++) {
            alg_safe_point();
            int32_t rt_1546 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_63, at_63);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rh_1547 = alg_hold_top;
                if (alg_truthy(alg_is_class(v_thestmt, k_functionstmt))) {
                    {
                        int32_t rh_1548 = alg_hold_top;
                        if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1)))))) {
                            {
                                int32_t rh_1549 = alg_hold_top;
                                (void)(alg_hold(alg_invoke(alg_property(v_this, "Declared"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                                alg_hold_top = rh_1549;
                                (void)(alg_hold(alg_invoke(alg_property(v_this, "CollectingInto"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                                alg_hold_top = rh_1549;
                                (void)(alg_hold(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1)), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 2)));
                                alg_hold_top = rh_1549;
                            }
                        }
                        alg_hold_top = rh_1548;
                        (void)(alg_hold(alg_invoke(v_this, "CollectFunctions", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1)));
                        alg_hold_top = rh_1548;
                    }
                }
                alg_hold_top = rh_1547;
                if (alg_truthy(alg_is_class(v_thestmt, k_classstmt))) {
                    {
                        int32_t rh_1550 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1)), v_thestmt}, 2)));
                        alg_hold_top = rh_1550;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1)), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 2)));
                        alg_hold_top = rh_1550;
                    }
                }
                alg_hold_top = rh_1547;
                if (alg_truthy(alg_is_class(v_thestmt, k_objectstmt))) {
                    {
                        int32_t rh_1551 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Objects"), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1))}, 1)));
                        alg_hold_top = rh_1551;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1)), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 2)));
                        alg_hold_top = rh_1551;
                    }
                }
                alg_hold_top = rh_1547;
                if (alg_truthy(alg_is_class(v_thestmt, k_enumstmt))) {
                    {
                        int32_t rh_1552 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "EnumTypes"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                        alg_hold_top = rh_1552;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1)), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 2)));
                        alg_hold_top = rh_1552;
                        {
                            int32_t rt_1553 = alg_root_top;
                            Value loop_64 = alg_iterable(alg_hold(alg_property(v_thestmt, "Members")));
                            (void)loop_64;
                            alg_root(&loop_64, 1);
                            for (int32_t at_64 = 0; at_64 < alg_iterable_count(loop_64); at_64++) {
                                alg_safe_point();
                                int32_t rt_1554 = alg_root_top;
                                Value v_themember = alg_iterable_at(loop_64, at_64);
                                (void)v_themember;
                                alg_root(&v_themember, 1);
                                {
                                    int32_t rt_1555 = alg_root_top;
                                    int32_t rh_1556 = alg_hold_top;
                                    Value v_member = alg_hold(alg_str(alg_hold(alg_property(v_themember, "Lexeme"))));
                                    (void)v_member;
                                    alg_root(&v_member, 1);
                                    alg_hold_top = rh_1556;
                                    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_member}, 1)))) {
                                        if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_member}, 1)))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))))))) {
                                            (void)(alg_hold(alg_invoke(v_this, "MarkAmbiguousMember", (Value[]){v_member, alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_member}, 1)))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 3)));
                                        }
                                    }
                                    alg_hold_top = rh_1556;
                                    (void)(alg_hold(alg_invoke(alg_property(v_this, "EnumMembers"), "Put", (Value[]){v_member, alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 2)));
                                    alg_hold_top = rh_1556;
                                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_member}, 1)), v_member}, 2)));
                                    alg_hold_top = rh_1556;
                                    alg_root_top = rt_1555;
                                }
                                alg_root_top = rt_1554;
                            }
                            alg_root_top = rt_1553;
                        }
                        alg_hold_top = rh_1552;
                    }
                }
                alg_hold_top = rh_1547;
                if (alg_truthy(alg_is_class(v_thestmt, k_blockstmt))) {
                    (void)(alg_hold(alg_invoke(v_this, "CollectFunctions", (Value[]){alg_hold(alg_property(v_thestmt, "Statements"))}, 1)));
                }
                alg_hold_top = rh_1547;
            }
            alg_root_top = rt_1546;
        }
        alg_root_top = rt_1545;
    }
    alg_hold_top = rh_1544;
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
    int32_t rh_1557 = alg_hold_top;
    {
        int32_t rt_1558 = alg_root_top;
        Value loop_66 = alg_iterable(v_statements);
        (void)loop_66;
        alg_root(&loop_66, 1);
        for (int32_t at_66 = 0; at_66 < alg_iterable_count(loop_66); at_66++) {
            alg_safe_point();
            int32_t rt_1559 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_66, at_66);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rh_1560 = alg_hold_top;
                if (alg_truthy(alg_is_class(v_thestmt, k_varstmt))) {
                    {
                        int32_t rh_1561 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Globals"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                        alg_hold_top = rh_1561;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "CollectingInto"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                        alg_hold_top = rh_1561;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))}, 1)), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 2)));
                        alg_hold_top = rh_1561;
                    }
                }
                alg_hold_top = rh_1560;
                if (alg_truthy(alg_is_class(v_thestmt, k_vargroupstmt))) {
                    {
                        int32_t rt_1562 = alg_root_top;
                        Value loop_67 = alg_iterable(alg_hold(alg_property(v_thestmt, "Names")));
                        (void)loop_67;
                        alg_root(&loop_67, 1);
                        for (int32_t at_67 = 0; at_67 < alg_iterable_count(loop_67); at_67++) {
                            alg_safe_point();
                            int32_t rt_1563 = alg_root_top;
                            Value v_thename = alg_iterable_at(loop_67, at_67);
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            {
                                int32_t rh_1564 = alg_hold_top;
                                (void)(alg_hold(alg_invoke(alg_property(v_this, "Globals"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme"))))}, 1)));
                                alg_hold_top = rh_1564;
                                (void)(alg_hold(alg_invoke(alg_property(v_this, "CollectingInto"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme"))))}, 1)));
                                alg_hold_top = rh_1564;
                                (void)(alg_hold(alg_invoke(alg_property(v_this, "Canonical"), "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(v_thename, "Lexeme"))}, 1)), alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme"))))}, 2)));
                                alg_hold_top = rh_1564;
                            }
                            alg_root_top = rt_1563;
                        }
                        alg_root_top = rt_1562;
                    }
                }
                alg_hold_top = rh_1560;
                if (alg_truthy(alg_hold((or_15 = alg_is_class(v_thestmt, k_functionstmt), !alg_truthy(or_15) ? or_15 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1)))))))) {
                    {
                        int32_t rh_1565 = alg_hold_top;
                        if (alg_truthy(alg_hold((or_17 = alg_hold((or_16 = alg_hold(alg_invoke(alg_property(v_this, "TopLevel"), "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)), alg_truthy(or_16) ? or_16 : alg_hold(alg_invoke(v_this, "Variadic", (Value[]){v_thestmt}, 1)))), alg_truthy(or_17) ? or_17 : alg_hold(alg_greater(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "BuiltinCounts", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)), "Length")), alg_int(0))))))) {
                            (void)(alg_hold(alg_invoke(alg_property(v_this, "Overloaded"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                        }
                        alg_hold_top = rh_1565;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "TopLevel"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                        alg_hold_top = rh_1565;
                    }
                }
                alg_hold_top = rh_1560;
            }
            alg_root_top = rt_1559;
        }
        alg_root_top = rt_1558;
    }
    alg_hold_top = rh_1557;
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
    int32_t rh_1566 = alg_hold_top;
    (void)(alg_set_property(v_this, "SourceFile", v_name));
    alg_hold_top = rh_1566;
    Value ret_69 = alg_nil();
    alg_root_top = rt_base;
    return ret_69;
}

static Value m_cemitter_withtests_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1567 = alg_hold_top;
    (void)(alg_set_property(v_this, "EmitTests", alg_bool(true)));
    alg_hold_top = rh_1567;
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
    int32_t rh_1568 = alg_hold_top;
    Value v_units = alg_nil();
    (void)v_units;
    alg_root(&v_units, 1);
    alg_hold_top = rh_1568;
    Value v_files = alg_nil();
    (void)v_files;
    alg_root(&v_files, 1);
    alg_hold_top = rh_1568;
    Value v_mainbodytext = alg_nil();
    (void)v_mainbodytext;
    alg_root(&v_mainbodytext, 1);
    alg_hold_top = rh_1568;
    (void)((v_units = alg_hold(alg_list())));
    alg_hold_top = rh_1568;
    (void)((v_files = alg_hold(alg_map())));
    alg_hold_top = rh_1568;
    (void)((v_mainbodytext = alg_literal("")));
    alg_hold_top = rh_1568;
    (void)(alg_hold(alg_invoke(v_this, "CollectUnits", (Value[]){v_statements, v_stem, alg_hold(alg_list()), v_units, alg_property(v_this, "SourceFile")}, 5)));
    alg_hold_top = rh_1568;
    Value v_seen = alg_hold(alg_set());
    (void)v_seen;
    alg_root(&v_seen, 1);
    alg_hold_top = rh_1568;
    {
        int32_t rt_1569 = alg_root_top;
        Value loop_71 = alg_iterable(v_units);
        (void)loop_71;
        alg_root(&loop_71, 1);
        for (int32_t at_71 = 0; at_71 < alg_iterable_count(loop_71); at_71++) {
            alg_safe_point();
            int32_t rt_1570 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_71, at_71);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            {
                int32_t rh_1571 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_invoke(v_seen, "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theunit, "Name"))))}, 1)))) {
                    (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("Two modules named '"), alg_hold(alg_str(alg_hold(alg_property(v_theunit, "Name")))))), alg_char_value(39)))}, 1)));
                }
                alg_hold_top = rh_1571;
                (void)(alg_hold(alg_invoke(v_seen, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theunit, "Name"))))}, 1)));
                alg_hold_top = rh_1571;
            }
            alg_root_top = rt_1570;
        }
        alg_root_top = rt_1569;
    }
    alg_hold_top = rh_1568;
    {
        int32_t rt_1572 = alg_root_top;
        Value loop_72 = alg_iterable(v_units);
        (void)loop_72;
        alg_root(&loop_72, 1);
        for (int32_t at_72 = 0; at_72 < alg_iterable_count(loop_72); at_72++) {
            alg_safe_point();
            int32_t rt_1573 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_72, at_72);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            {
                int32_t rh_1574 = alg_hold_top;
                (void)(alg_set_property(v_this, "CollectingInto", alg_hold(alg_set())));
                alg_hold_top = rh_1574;
                (void)(alg_hold(alg_invoke(v_this, "CollectFunctions", (Value[]){alg_hold(alg_property(v_theunit, "Statements"))}, 1)));
                alg_hold_top = rh_1574;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "DeclaredIn"), "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theunit, "Name")))), alg_property(v_this, "CollectingInto")}, 2)));
                alg_hold_top = rh_1574;
            }
            alg_root_top = rt_1573;
        }
        alg_root_top = rt_1572;
    }
    alg_hold_top = rh_1568;
    {
        int32_t rt_1575 = alg_root_top;
        Value loop_73 = alg_iterable(v_units);
        (void)loop_73;
        alg_root(&loop_73, 1);
        for (int32_t at_73 = 0; at_73 < alg_iterable_count(loop_73); at_73++) {
            alg_safe_point();
            int32_t rt_1576 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_73, at_73);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            {
                int32_t rt_1577 = alg_root_top;
                int32_t rh_1578 = alg_hold_top;
                Value v_mine = alg_hold(alg_set());
                (void)v_mine;
                alg_root(&v_mine, 1);
                alg_hold_top = rh_1578;
                {
                    int32_t rt_1579 = alg_root_top;
                    Value loop_74 = alg_iterable(alg_hold(alg_property(v_theunit, "Statements")));
                    (void)loop_74;
                    alg_root(&loop_74, 1);
                    for (int32_t at_74 = 0; at_74 < alg_iterable_count(loop_74); at_74++) {
                        alg_safe_point();
                        int32_t rt_1580 = alg_root_top;
                        Value v_thestmt = alg_iterable_at(loop_74, at_74);
                        (void)v_thestmt;
                        alg_root(&v_thestmt, 1);
                        if (alg_truthy(alg_is_class(v_thestmt, k_classstmt))) {
                            {
                                int32_t rt_1581 = alg_root_top;
                                int32_t rh_1582 = alg_hold_top;
                                Value v_spelt = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))));
                                (void)v_spelt;
                                alg_root(&v_spelt, 1);
                                alg_hold_top = rh_1582;
                                Value v_key = alg_hold(f_foldcase(NULL, (Value[]){v_spelt}, 1));
                                (void)v_key;
                                alg_root(&v_key, 1);
                                alg_hold_top = rh_1582;
                                (void)(alg_hold(alg_invoke(v_mine, "Add", (Value[]){v_spelt}, 1)));
                                alg_hold_top = rh_1582;
                                if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "ClassCounts"), "Contains", (Value[]){v_key}, 1)))) {
                                    (void)(alg_hold(alg_invoke(alg_property(v_this, "ClassCounts"), "Put", (Value[]){v_key, alg_hold(alg_add((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "ClassCounts"), "Get", (Value[]){v_key}, 1), ALG_KIND_INTEGER, "Integer"))), alg_int(1)))}, 2)));
                                } else {
                                    (void)(alg_hold(alg_invoke(alg_property(v_this, "ClassCounts"), "Put", (Value[]){v_key, alg_int(1)}, 2)));
                                }
                                alg_hold_top = rh_1582;
                                alg_root_top = rt_1581;
                            }
                        }
                        alg_root_top = rt_1580;
                    }
                    alg_root_top = rt_1579;
                }
                alg_hold_top = rh_1578;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "ClassesIn"), "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theunit, "Name")))), v_mine}, 2)));
                alg_hold_top = rh_1578;
                alg_root_top = rt_1577;
            }
            alg_root_top = rt_1576;
        }
        alg_root_top = rt_1575;
    }
    alg_hold_top = rh_1568;
    {
        int32_t rt_1583 = alg_root_top;
        Value loop_75 = alg_iterable(v_units);
        (void)loop_75;
        alg_root(&loop_75, 1);
        for (int32_t at_75 = 0; at_75 < alg_iterable_count(loop_75); at_75++) {
            alg_safe_point();
            int32_t rt_1584 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_75, at_75);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            {
                int32_t rh_1585 = alg_hold_top;
                (void)(alg_set_property(v_this, "TopLevel", alg_hold(alg_set())));
                alg_hold_top = rh_1585;
                (void)(alg_set_property(v_this, "Overloaded", alg_hold(alg_set())));
                alg_hold_top = rh_1585;
                (void)(alg_set_property(v_this, "CollectingInto", alg_hold(alg_set())));
                alg_hold_top = rh_1585;
                (void)(alg_hold(alg_invoke(v_this, "CollectGlobals", (Value[]){alg_hold(alg_property(v_theunit, "Statements"))}, 1)));
                alg_hold_top = rh_1585;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "GlobalsIn"), "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theunit, "Name")))), alg_property(v_this, "CollectingInto")}, 2)));
                alg_hold_top = rh_1585;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "OverloadsIn"), "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theunit, "Name")))), alg_property(v_this, "Overloaded")}, 2)));
                alg_hold_top = rh_1585;
            }
            alg_root_top = rt_1584;
        }
        alg_root_top = rt_1583;
    }
    alg_hold_top = rh_1568;
    (void)(alg_set_property(v_this, "CollectingInto", alg_hold(alg_set())));
    alg_hold_top = rh_1568;
    {
        int32_t rt_1586 = alg_root_top;
        Value loop_76 = alg_iterable(v_units);
        (void)loop_76;
        alg_root(&loop_76, 1);
        for (int32_t at_76 = 0; at_76 < alg_iterable_count(loop_76); at_76++) {
            alg_safe_point();
            int32_t rt_1587 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_76, at_76);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            {
                int32_t rt_1588 = alg_root_top;
                int32_t rh_1589 = alg_hold_top;
                Value v_exported = alg_hold(alg_set());
                (void)v_exported;
                alg_root(&v_exported, 1);
                alg_hold_top = rh_1589;
                Value v_own = alg_hold(alg_property(v_theunit, "Statements"));
                (void)v_own;
                alg_root(&v_own, 1);
                alg_hold_top = rh_1589;
                {
                    int32_t rt_1590 = alg_root_top;
                    int32_t rh_1591 = alg_hold_top;
                    Value v_i = alg_int(0);
                    (void)v_i;
                    alg_root(&v_i, 1);
                    alg_hold_top = rh_1591;
                    {
                        int32_t rh_1592 = alg_hold_top;
                        for (; (alg_hold_top = rh_1592, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_own, "Length")))))); (alg_hold_top = rh_1592, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                            alg_safe_point();
                            {
                                int32_t rt_1593 = alg_root_top;
                                int32_t rh_1594 = alg_hold_top;
                                Value v_thestmt = alg_hold(alg_subscript_get(v_own, v_i));
                                (void)v_thestmt;
                                alg_root(&v_thestmt, 1);
                                alg_hold_top = rh_1594;
                                if (alg_truthy(alg_hold((or_18 = alg_is_class(v_thestmt, k_functionstmt), !alg_truthy(or_18) ? or_18 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1)))))))) {
                                    (void)(alg_hold(alg_invoke(v_exported, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                                }
                                alg_hold_top = rh_1594;
                                if (alg_truthy(alg_is_class(v_thestmt, k_classstmt))) {
                                    (void)(alg_hold(alg_invoke(v_exported, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                                }
                                alg_hold_top = rh_1594;
                                if (alg_truthy(alg_is_class(v_thestmt, k_objectstmt))) {
                                    (void)(alg_hold(alg_invoke(v_exported, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                                }
                                alg_hold_top = rh_1594;
                                if (alg_truthy(alg_is_class(v_thestmt, k_varstmt))) {
                                    (void)(alg_hold(alg_invoke(v_exported, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                                }
                                alg_hold_top = rh_1594;
                                if (alg_truthy(alg_is_class(v_thestmt, k_enumstmt))) {
                                    {
                                        int32_t rh_1595 = alg_hold_top;
                                        (void)(alg_hold(alg_invoke(v_exported, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                                        alg_hold_top = rh_1595;
                                        {
                                            int32_t rt_1596 = alg_root_top;
                                            Value loop_77 = alg_iterable(alg_hold(alg_property(v_thestmt, "Members")));
                                            (void)loop_77;
                                            alg_root(&loop_77, 1);
                                            for (int32_t at_77 = 0; at_77 < alg_iterable_count(loop_77); at_77++) {
                                                alg_safe_point();
                                                int32_t rt_1597 = alg_root_top;
                                                Value v_member = alg_iterable_at(loop_77, at_77);
                                                (void)v_member;
                                                alg_root(&v_member, 1);
                                                (void)(alg_hold(alg_invoke(v_exported, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_member, "Lexeme"))))}, 1)));
                                                alg_root_top = rt_1597;
                                            }
                                            alg_root_top = rt_1596;
                                        }
                                        alg_hold_top = rh_1595;
                                    }
                                }
                                alg_hold_top = rh_1594;
                                if (alg_truthy(alg_is_class(v_thestmt, k_vargroupstmt))) {
                                    {
                                        int32_t rt_1598 = alg_root_top;
                                        Value loop_78 = alg_iterable(alg_hold(alg_property(v_thestmt, "Names")));
                                        (void)loop_78;
                                        alg_root(&loop_78, 1);
                                        for (int32_t at_78 = 0; at_78 < alg_iterable_count(loop_78); at_78++) {
                                            alg_safe_point();
                                            int32_t rt_1599 = alg_root_top;
                                            Value v_eachname = alg_iterable_at(loop_78, at_78);
                                            (void)v_eachname;
                                            alg_root(&v_eachname, 1);
                                            (void)(alg_hold(alg_invoke(v_exported, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_eachname, "Lexeme"))))}, 1)));
                                            alg_root_top = rt_1599;
                                        }
                                        alg_root_top = rt_1598;
                                    }
                                }
                                alg_hold_top = rh_1594;
                                alg_root_top = rt_1593;
                            }
                        }
                    }
                    alg_hold_top = rh_1591;
                    alg_root_top = rt_1590;
                }
                alg_hold_top = rh_1589;
                Value v_everything = alg_hold(alg_set());
                (void)v_everything;
                alg_root(&v_everything, 1);
                alg_hold_top = rh_1589;
                {
                    int32_t rt_1600 = alg_root_top;
                    int32_t rh_1601 = alg_hold_top;
                    Value v_i = alg_int(0);
                    (void)v_i;
                    alg_root(&v_i, 1);
                    alg_hold_top = rh_1601;
                    {
                        int32_t rh_1602 = alg_hold_top;
                        for (; (alg_hold_top = rh_1602, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_invoke(v_exported, "ToList", NULL, 0)), "Length")))))); (alg_hold_top = rh_1602, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                            alg_safe_point();
                            (void)(alg_hold(alg_invoke(v_everything, "Add", (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_invoke(v_exported, "ToList", NULL, 0)), v_i))}, 1)));
                        }
                    }
                    alg_hold_top = rh_1601;
                    alg_root_top = rt_1600;
                }
                alg_hold_top = rh_1589;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "UnitAll"), "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theunit, "Name")))), v_everything}, 2)));
                alg_hold_top = rh_1589;
                Value v_hidden = alg_hold(alg_property(v_theunit, "PrivateNames"));
                (void)v_hidden;
                alg_root(&v_hidden, 1);
                alg_hold_top = rh_1589;
                {
                    int32_t rt_1603 = alg_root_top;
                    int32_t rh_1604 = alg_hold_top;
                    Value v_i = alg_int(0);
                    (void)v_i;
                    alg_root(&v_i, 1);
                    alg_hold_top = rh_1604;
                    {
                        int32_t rh_1605 = alg_hold_top;
                        for (; (alg_hold_top = rh_1605, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_hidden, "Length")))))); (alg_hold_top = rh_1605, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                            alg_safe_point();
                            (void)(alg_hold(alg_invoke(v_exported, "Remove", (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_hidden, v_i))))}, 1)));
                        }
                    }
                    alg_hold_top = rh_1604;
                    alg_root_top = rt_1603;
                }
                alg_hold_top = rh_1589;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "UnitExports"), "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theunit, "Name")))), v_exported}, 2)));
                alg_hold_top = rh_1589;
                alg_root_top = rt_1588;
            }
            alg_root_top = rt_1587;
        }
        alg_root_top = rt_1586;
    }
    alg_hold_top = rh_1568;
    Value v_exportedby = alg_hold(alg_map());
    (void)v_exportedby;
    alg_root(&v_exportedby, 1);
    alg_hold_top = rh_1568;
    {
        int32_t rt_1606 = alg_root_top;
        int32_t rh_1607 = alg_hold_top;
        Value v_u = alg_int(0);
        (void)v_u;
        alg_root(&v_u, 1);
        alg_hold_top = rh_1607;
        {
            int32_t rh_1608 = alg_hold_top;
            for (; (alg_hold_top = rh_1608, alg_truthy(alg_hold(alg_less(v_u, alg_hold(alg_subtract(alg_hold(alg_property(v_units, "Length")), alg_int(1))))))); (alg_hold_top = rh_1608, (v_u = alg_hold(alg_add(v_u, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1609 = alg_root_top;
                    int32_t rh_1610 = alg_hold_top;
                    Value v_visible = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_subscript_get(v_units, v_u)), "Name"))))}, 1), ALG_KIND_SET, "Set"));
                    (void)v_visible;
                    alg_root(&v_visible, 1);
                    alg_hold_top = rh_1610;
                    Value v_names = alg_hold(alg_invoke(v_this, "ExportedNames", (Value[]){alg_hold(alg_subscript_get(v_units, v_u))}, 1));
                    (void)v_names;
                    alg_root(&v_names, 1);
                    alg_hold_top = rh_1610;
                    {
                        int32_t rt_1611 = alg_root_top;
                        int32_t rh_1612 = alg_hold_top;
                        Value v_i = alg_int(0);
                        (void)v_i;
                        alg_root(&v_i, 1);
                        alg_hold_top = rh_1612;
                        {
                            int32_t rh_1613 = alg_hold_top;
                            for (; (alg_hold_top = rh_1613, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_names, "Length")))))); (alg_hold_top = rh_1613, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                                alg_safe_point();
                                {
                                    int32_t rt_1614 = alg_root_top;
                                    int32_t rh_1615 = alg_hold_top;
                                    Value v_thename = alg_hold(alg_str(alg_hold(alg_subscript_get(v_names, v_i))));
                                    (void)v_thename;
                                    alg_root(&v_thename, 1);
                                    alg_hold_top = rh_1615;
                                    if (alg_truthy(alg_hold(alg_invoke(v_visible, "Contains", (Value[]){v_thename}, 1)))) {
                                        {
                                            int32_t rh_1616 = alg_hold_top;
                                            if (alg_truthy(alg_hold(alg_invoke(v_exportedby, "Contains", (Value[]){v_thename}, 1)))) {
                                                {
                                                    int32_t rh_1617 = alg_hold_top;
                                                    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_str(alg_hold(alg_invoke(v_exportedby, "Get", (Value[]){v_thename}, 1)))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_subscript_get(v_units, v_u)), "Name")))))))) {
                                                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Renamed"), "Add", (Value[]){v_thename}, 1)));
                                                    }
                                                    alg_hold_top = rh_1617;
                                                }
                                            } else {
                                                (void)(alg_hold(alg_invoke(v_exportedby, "Put", (Value[]){v_thename, alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_subscript_get(v_units, v_u)), "Name"))))}, 2)));
                                            }
                                            alg_hold_top = rh_1616;
                                        }
                                    }
                                    alg_hold_top = rh_1615;
                                    alg_root_top = rt_1614;
                                }
                            }
                        }
                        alg_hold_top = rh_1612;
                        alg_root_top = rt_1611;
                    }
                    alg_hold_top = rh_1610;
                    alg_root_top = rt_1609;
                }
            }
        }
        alg_hold_top = rh_1607;
        alg_root_top = rt_1606;
    }
    alg_hold_top = rh_1568;
    {
        int32_t rt_1618 = alg_root_top;
        int32_t rh_1619 = alg_hold_top;
        Value v_u = alg_int(0);
        (void)v_u;
        alg_root(&v_u, 1);
        alg_hold_top = rh_1619;
        {
            int32_t rh_1620 = alg_hold_top;
            for (; (alg_hold_top = rh_1620, alg_truthy(alg_hold(alg_less(v_u, alg_hold(alg_property(v_units, "Length")))))); (alg_hold_top = rh_1620, (v_u = alg_hold(alg_add(v_u, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1621 = alg_root_top;
                    int32_t rh_1622 = alg_hold_top;
                    Value v_unit = alg_hold(alg_subscript_get(v_units, v_u));
                    (void)v_unit;
                    alg_root(&v_unit, 1);
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "Declarations", alg_hold(alg_buffer(alg_int(0)))));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "RootSymbols", alg_hold(alg_list())));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "Functions", alg_hold(alg_buffer(alg_int(0)))));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "Setup", alg_hold(alg_buffer(alg_int(0)))));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "Shells", alg_hold(alg_buffer(alg_int(0)))));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "BuiltinThunks", alg_hold(alg_set())));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "Overloaded", alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "OverloadsIn"), "Get", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))}, 1), ALG_KIND_SET, "Set"))));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "SetsBuilt", alg_hold(alg_set())));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "OwnClasses", alg_hold(alg_set())));
                    alg_hold_top = rh_1622;
                    {
                        int32_t rt_1623 = alg_root_top;
                        Value loop_79 = alg_iterable(alg_hold(alg_property(v_unit, "Statements")));
                        (void)loop_79;
                        alg_root(&loop_79, 1);
                        for (int32_t at_79 = 0; at_79 < alg_iterable_count(loop_79); at_79++) {
                            alg_safe_point();
                            int32_t rt_1624 = alg_root_top;
                            Value v_statement = alg_iterable_at(loop_79, at_79);
                            (void)v_statement;
                            alg_root(&v_statement, 1);
                            if (alg_truthy(alg_hold((or_19 = alg_is_class(v_statement, k_classstmt), alg_truthy(or_19) ? or_19 : alg_is_class(v_statement, k_objectstmt))))) {
                                (void)(alg_hold(alg_invoke(alg_property(v_this, "OwnClasses"), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_statement, "Name")), "Lexeme"))}, 1))}, 1)));
                            }
                            alg_root_top = rt_1624;
                        }
                        alg_root_top = rt_1623;
                    }
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "MainBody", alg_hold(alg_buffer(alg_int(0)))));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "Header", alg_literal("")));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "Target", alg_literal("main")));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "Logicals", alg_int(0)));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "Loops", alg_int(0)));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "UnitTests", alg_int(0)));
                    alg_hold_top = rh_1622;
                    Value v_ismain = alg_hold(alg_equal(v_u, alg_hold(alg_subtract(alg_hold(alg_property(v_units, "Length")), alg_int(1)))));
                    (void)v_ismain;
                    alg_root(&v_ismain, 1);
                    alg_hold_top = rh_1622;
                    if (alg_truthy(v_ismain)) {
                        (void)(alg_hold(alg_invoke(v_this, "EmitSubranges", NULL, 0)));
                    }
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "UnitName", alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "PrivateNames", alg_hold(alg_cast_kind(alg_property(v_unit, "PrivateNames"), ALG_KIND_LIST, "List"))));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "RootUnit", v_ismain));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "CurrentFile", alg_hold(alg_str(alg_hold(alg_property(v_unit, "FileName"))))));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "Renames", alg_hold(alg_map())));
                    alg_hold_top = rh_1622;
                    Value v_visible = alg_hold(alg_set());
                    (void)v_visible;
                    alg_root(&v_visible, 1);
                    alg_hold_top = rh_1622;
                    Value v_importowner = alg_hold(alg_map());
                    (void)v_importowner;
                    alg_root(&v_importowner, 1);
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "AmbiguousImports", alg_hold(alg_map())));
                    alg_hold_top = rh_1622;
                    {
                        int32_t rt_1625 = alg_root_top;
                        Value loop_80 = alg_iterable(alg_hold(alg_property(v_unit, "Imports")));
                        (void)loop_80;
                        alg_root(&loop_80, 1);
                        for (int32_t at_80 = 0; at_80 < alg_iterable_count(loop_80); at_80++) {
                            alg_safe_point();
                            int32_t rt_1626 = alg_root_top;
                            Value v_import = alg_iterable_at(loop_80, at_80);
                            (void)v_import;
                            alg_root(&v_import, 1);
                            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){alg_hold(alg_str(v_import))}, 1)))) {
                                {
                                    int32_t rt_1627 = alg_root_top;
                                    int32_t rh_1628 = alg_hold_top;
                                    Value v_from = alg_hold(alg_str(v_import));
                                    (void)v_from;
                                    alg_root(&v_from, 1);
                                    alg_hold_top = rh_1628;
                                    Value v_seen = alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_from}, 1), ALG_KIND_SET, "Set"))), "ToList", NULL, 0));
                                    (void)v_seen;
                                    alg_root(&v_seen, 1);
                                    alg_hold_top = rh_1628;
                                    {
                                        int32_t rt_1629 = alg_root_top;
                                        int32_t rh_1630 = alg_hold_top;
                                        Value v_j = alg_int(0);
                                        (void)v_j;
                                        alg_root(&v_j, 1);
                                        alg_hold_top = rh_1630;
                                        {
                                            int32_t rh_1631 = alg_hold_top;
                                            for (; (alg_hold_top = rh_1631, alg_truthy(alg_hold(alg_less(v_j, alg_hold(alg_property(v_seen, "Length")))))); (alg_hold_top = rh_1631, (v_j = alg_hold(alg_add(v_j, alg_int(1)))))) {
                                                alg_safe_point();
                                                {
                                                    int32_t rt_1632 = alg_root_top;
                                                    int32_t rh_1633 = alg_hold_top;
                                                    Value v_thename = alg_hold(alg_str(alg_hold(alg_subscript_get(v_seen, v_j))));
                                                    (void)v_thename;
                                                    alg_root(&v_thename, 1);
                                                    alg_hold_top = rh_1633;
                                                    (void)(alg_hold(alg_invoke(v_visible, "Add", (Value[]){v_thename}, 1)));
                                                    alg_hold_top = rh_1633;
                                                    if (alg_truthy(alg_hold(alg_invoke(v_importowner, "Contains", (Value[]){v_thename}, 1)))) {
                                                        {
                                                            int32_t rh_1634 = alg_hold_top;
                                                            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_str(alg_hold(alg_invoke(v_importowner, "Get", (Value[]){v_thename}, 1)))), v_from)))) {
                                                                (void)(alg_hold(alg_invoke(v_this, "MarkAmbiguousImport", (Value[]){v_thename, alg_hold(alg_str(alg_hold(alg_invoke(v_importowner, "Get", (Value[]){v_thename}, 1)))), v_from}, 3)));
                                                            }
                                                            alg_hold_top = rh_1634;
                                                        }
                                                    } else {
                                                        (void)(alg_hold(alg_invoke(v_importowner, "Put", (Value[]){v_thename, v_from}, 2)));
                                                    }
                                                    alg_hold_top = rh_1633;
                                                    alg_root_top = rt_1632;
                                                }
                                            }
                                        }
                                        alg_hold_top = rh_1630;
                                        alg_root_top = rt_1629;
                                    }
                                    alg_hold_top = rh_1628;
                                    alg_root_top = rt_1627;
                                }
                            }
                            alg_root_top = rt_1626;
                        }
                        alg_root_top = rt_1625;
                    }
                    alg_hold_top = rh_1622;
                    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "UnitAll"), "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))}, 1)))) {
                        {
                            int32_t rt_1635 = alg_root_top;
                            int32_t rh_1636 = alg_hold_top;
                            Value v_declares = alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "UnitAll"), "Get", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))}, 1), ALG_KIND_SET, "Set"))), "ToList", NULL, 0));
                            (void)v_declares;
                            alg_root(&v_declares, 1);
                            alg_hold_top = rh_1636;
                            {
                                int32_t rt_1637 = alg_root_top;
                                Value loop_81 = alg_iterable(v_declares);
                                (void)loop_81;
                                alg_root(&loop_81, 1);
                                for (int32_t at_81 = 0; at_81 < alg_iterable_count(loop_81); at_81++) {
                                    alg_safe_point();
                                    int32_t rt_1638 = alg_root_top;
                                    Value v_declare = alg_iterable_at(loop_81, at_81);
                                    (void)v_declare;
                                    alg_root(&v_declare, 1);
                                    (void)(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Remove", (Value[]){alg_hold(alg_str(v_declare))}, 1)));
                                    alg_root_top = rt_1638;
                                }
                                alg_root_top = rt_1637;
                            }
                            alg_hold_top = rh_1636;
                            alg_root_top = rt_1635;
                        }
                    }
                    alg_hold_top = rh_1622;
                    Value v_mine = alg_hold(alg_invoke(v_this, "ExportedNames", (Value[]){v_unit}, 1));
                    (void)v_mine;
                    alg_root(&v_mine, 1);
                    alg_hold_top = rh_1622;
                    {
                        int32_t rt_1639 = alg_root_top;
                        int32_t rh_1640 = alg_hold_top;
                        Value v_i = alg_int(0);
                        (void)v_i;
                        alg_root(&v_i, 1);
                        alg_hold_top = rh_1640;
                        {
                            int32_t rh_1641 = alg_hold_top;
                            for (; (alg_hold_top = rh_1641, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_mine, "Length")))))); (alg_hold_top = rh_1641, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                                alg_safe_point();
                                {
                                    int32_t rt_1642 = alg_root_top;
                                    int32_t rh_1643 = alg_hold_top;
                                    Value v_thename = alg_hold(alg_str(alg_hold(alg_subscript_get(v_mine, v_i))));
                                    (void)v_thename;
                                    alg_root(&v_thename, 1);
                                    alg_hold_top = rh_1643;
                                    if (alg_truthy(alg_hold(alg_invoke(v_visible, "Contains", (Value[]){v_thename}, 1)))) {
                                        if (alg_truthy(alg_hold((or_20 = v_ismain, alg_truthy(or_20) ? or_20 : alg_hold(alg_invoke(alg_hold(alg_property(v_unit, "PrivateNames")), "Contains", (Value[]){v_thename}, 1)))))) {
                                            (void)(alg_hold(alg_invoke(alg_property(v_this, "Renames"), "Put", (Value[]){v_thename, alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))}, 2)));
                                        }
                                    }
                                    alg_hold_top = rh_1643;
                                    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Renamed"), "Contains", (Value[]){v_thename}, 1)))) {
                                        if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_hold(alg_property(v_unit, "PrivateNames")), "Contains", (Value[]){v_thename}, 1)))))) {
                                            (void)(alg_hold(alg_invoke(alg_property(v_this, "Renames"), "Put", (Value[]){v_thename, alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))}, 2)));
                                        }
                                    }
                                    alg_hold_top = rh_1643;
                                    alg_root_top = rt_1642;
                                }
                            }
                        }
                        alg_hold_top = rh_1640;
                        alg_root_top = rt_1639;
                    }
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "ImportedFrom", v_importowner));
                    alg_hold_top = rh_1622;
                    Value v_reached = alg_hold(alg_invoke(v_importowner, "Keys", NULL, 0));
                    (void)v_reached;
                    alg_root(&v_reached, 1);
                    alg_hold_top = rh_1622;
                    {
                        int32_t rt_1644 = alg_root_top;
                        int32_t rh_1645 = alg_hold_top;
                        Value v_i = alg_int(0);
                        (void)v_i;
                        alg_root(&v_i, 1);
                        alg_hold_top = rh_1645;
                        {
                            int32_t rh_1646 = alg_hold_top;
                            for (; (alg_hold_top = rh_1646, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_reached, "Length")))))); (alg_hold_top = rh_1646, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                                alg_safe_point();
                                {
                                    int32_t rt_1647 = alg_root_top;
                                    int32_t rh_1648 = alg_hold_top;
                                    Value v_thename = alg_hold(alg_str(alg_hold(alg_subscript_get(v_reached, v_i))));
                                    (void)v_thename;
                                    alg_root(&v_thename, 1);
                                    alg_hold_top = rh_1648;
                                    if (alg_truthy(alg_hold((or_21 = alg_hold(alg_invoke(alg_property(v_this, "Renamed"), "Contains", (Value[]){v_thename}, 1)), !alg_truthy(or_21) ? or_21 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Renames"), "Contains", (Value[]){v_thename}, 1)))))))) {
                                        if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Contains", (Value[]){v_thename}, 1)))))) {
                                            (void)(alg_hold(alg_invoke(alg_property(v_this, "Renames"), "Put", (Value[]){v_thename, alg_hold(alg_str(alg_hold(alg_invoke(v_importowner, "Get", (Value[]){v_thename}, 1))))}, 2)));
                                        }
                                    }
                                    alg_hold_top = rh_1648;
                                    alg_root_top = rt_1647;
                                }
                            }
                        }
                        alg_hold_top = rh_1645;
                        alg_root_top = rt_1644;
                    }
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "ShadowNames", alg_hold(alg_set())));
                    alg_hold_top = rh_1622;
                    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "UnitAll"), "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))}, 1)))) {
                        {
                            int32_t rt_1649 = alg_root_top;
                            int32_t rh_1650 = alg_hold_top;
                            Value v_own = alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "UnitAll"), "Get", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))}, 1), ALG_KIND_SET, "Set"))), "ToList", NULL, 0));
                            (void)v_own;
                            alg_root(&v_own, 1);
                            alg_hold_top = rh_1650;
                            {
                                int32_t rt_1651 = alg_root_top;
                                int32_t rh_1652 = alg_hold_top;
                                Value v_i = alg_int(0);
                                (void)v_i;
                                alg_root(&v_i, 1);
                                alg_hold_top = rh_1652;
                                {
                                    int32_t rh_1653 = alg_hold_top;
                                    for (; (alg_hold_top = rh_1653, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_own, "Length")))))); (alg_hold_top = rh_1653, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                                        alg_safe_point();
                                        (void)(alg_hold(alg_invoke(alg_property(v_this, "ShadowNames"), "Add", (Value[]){alg_hold(alg_subscript_get(v_own, v_i))}, 1)));
                                    }
                                }
                                alg_hold_top = rh_1652;
                                alg_root_top = rt_1651;
                            }
                            alg_hold_top = rh_1650;
                            alg_root_top = rt_1649;
                        }
                    }
                    alg_hold_top = rh_1622;
                    {
                        int32_t rt_1654 = alg_root_top;
                        Value loop_82 = alg_iterable(alg_hold(alg_property(v_unit, "Imports")));
                        (void)loop_82;
                        alg_root(&loop_82, 1);
                        for (int32_t at_82 = 0; at_82 < alg_iterable_count(loop_82); at_82++) {
                            alg_safe_point();
                            int32_t rt_1655 = alg_root_top;
                            Value v_theimport = alg_iterable_at(loop_82, at_82);
                            (void)v_theimport;
                            alg_root(&v_theimport, 1);
                            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){alg_hold(alg_str(v_theimport))}, 1)))) {
                                {
                                    int32_t rt_1656 = alg_root_top;
                                    int32_t rh_1657 = alg_hold_top;
                                    Value v_seen = alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){alg_hold(alg_str(v_theimport))}, 1), ALG_KIND_SET, "Set"))), "ToList", NULL, 0));
                                    (void)v_seen;
                                    alg_root(&v_seen, 1);
                                    alg_hold_top = rh_1657;
                                    {
                                        int32_t rt_1658 = alg_root_top;
                                        int32_t rh_1659 = alg_hold_top;
                                        Value v_j = alg_int(0);
                                        (void)v_j;
                                        alg_root(&v_j, 1);
                                        alg_hold_top = rh_1659;
                                        {
                                            int32_t rh_1660 = alg_hold_top;
                                            for (; (alg_hold_top = rh_1660, alg_truthy(alg_hold(alg_less(v_j, alg_hold(alg_property(v_seen, "Length")))))); (alg_hold_top = rh_1660, (v_j = alg_hold(alg_add(v_j, alg_int(1)))))) {
                                                alg_safe_point();
                                                (void)(alg_hold(alg_invoke(alg_property(v_this, "ShadowNames"), "Add", (Value[]){alg_hold(alg_subscript_get(v_seen, v_j))}, 1)));
                                            }
                                        }
                                        alg_hold_top = rh_1659;
                                        alg_root_top = rt_1658;
                                    }
                                    alg_hold_top = rh_1657;
                                    alg_root_top = rt_1656;
                                }
                            }
                            alg_root_top = rt_1655;
                        }
                        alg_root_top = rt_1654;
                    }
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "VisibleDeclared", alg_hold(alg_set())));
                    alg_hold_top = rh_1622;
                    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "DeclaredIn"), "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))}, 1)))) {
                        {
                            int32_t rt_1661 = alg_root_top;
                            int32_t rh_1662 = alg_hold_top;
                            Value v_mine = alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "DeclaredIn"), "Get", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))}, 1), ALG_KIND_SET, "Set"))), "ToList", NULL, 0));
                            (void)v_mine;
                            alg_root(&v_mine, 1);
                            alg_hold_top = rh_1662;
                            {
                                int32_t rt_1663 = alg_root_top;
                                int32_t rh_1664 = alg_hold_top;
                                Value v_i = alg_int(0);
                                (void)v_i;
                                alg_root(&v_i, 1);
                                alg_hold_top = rh_1664;
                                {
                                    int32_t rh_1665 = alg_hold_top;
                                    for (; (alg_hold_top = rh_1665, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_mine, "Length")))))); (alg_hold_top = rh_1665, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                                        alg_safe_point();
                                        (void)(alg_hold(alg_invoke(alg_property(v_this, "VisibleDeclared"), "Add", (Value[]){alg_hold(alg_subscript_get(v_mine, v_i))}, 1)));
                                    }
                                }
                                alg_hold_top = rh_1664;
                                alg_root_top = rt_1663;
                            }
                            alg_hold_top = rh_1662;
                            alg_root_top = rt_1661;
                        }
                    }
                    alg_hold_top = rh_1622;
                    {
                        int32_t rt_1666 = alg_root_top;
                        Value loop_83 = alg_iterable(alg_hold(alg_property(v_unit, "Imports")));
                        (void)loop_83;
                        alg_root(&loop_83, 1);
                        for (int32_t at_83 = 0; at_83 < alg_iterable_count(loop_83); at_83++) {
                            alg_safe_point();
                            int32_t rt_1667 = alg_root_top;
                            Value v_theimport = alg_iterable_at(loop_83, at_83);
                            (void)v_theimport;
                            alg_root(&v_theimport, 1);
                            if (alg_truthy(alg_hold((or_22 = alg_hold(alg_invoke(alg_property(v_this, "DeclaredIn"), "Contains", (Value[]){alg_hold(alg_str(v_theimport))}, 1)), !alg_truthy(or_22) ? or_22 : alg_hold(alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){alg_hold(alg_str(v_theimport))}, 1)))))) {
                                {
                                    int32_t rt_1668 = alg_root_top;
                                    int32_t rh_1669 = alg_hold_top;
                                    Value v_theirs = alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "DeclaredIn"), "Get", (Value[]){alg_hold(alg_str(v_theimport))}, 1), ALG_KIND_SET, "Set"))), "ToList", NULL, 0));
                                    (void)v_theirs;
                                    alg_root(&v_theirs, 1);
                                    alg_hold_top = rh_1669;
                                    Value v_shown = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){alg_hold(alg_str(v_theimport))}, 1), ALG_KIND_SET, "Set"));
                                    (void)v_shown;
                                    alg_root(&v_shown, 1);
                                    alg_hold_top = rh_1669;
                                    {
                                        int32_t rt_1670 = alg_root_top;
                                        int32_t rh_1671 = alg_hold_top;
                                        Value v_j = alg_int(0);
                                        (void)v_j;
                                        alg_root(&v_j, 1);
                                        alg_hold_top = rh_1671;
                                        {
                                            int32_t rh_1672 = alg_hold_top;
                                            for (; (alg_hold_top = rh_1672, alg_truthy(alg_hold(alg_less(v_j, alg_hold(alg_property(v_theirs, "Length")))))); (alg_hold_top = rh_1672, (v_j = alg_hold(alg_add(v_j, alg_int(1)))))) {
                                                alg_safe_point();
                                                if (alg_truthy(alg_hold(alg_invoke(v_shown, "Contains", (Value[]){alg_hold(alg_subscript_get(v_theirs, v_j))}, 1)))) {
                                                    (void)(alg_hold(alg_invoke(alg_property(v_this, "VisibleDeclared"), "Add", (Value[]){alg_hold(alg_subscript_get(v_theirs, v_j))}, 1)));
                                                }
                                            }
                                        }
                                        alg_hold_top = rh_1671;
                                        alg_root_top = rt_1670;
                                    }
                                    alg_hold_top = rh_1669;
                                    alg_root_top = rt_1668;
                                }
                            }
                            alg_root_top = rt_1667;
                        }
                        alg_root_top = rt_1666;
                    }
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "VisibleClasses", alg_hold(alg_set())));
                    alg_hold_top = rh_1622;
                    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "ClassesIn"), "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))}, 1)))) {
                        {
                            int32_t rt_1673 = alg_root_top;
                            int32_t rh_1674 = alg_hold_top;
                            Value v_myclasses = alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "ClassesIn"), "Get", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))}, 1), ALG_KIND_SET, "Set"))), "ToList", NULL, 0));
                            (void)v_myclasses;
                            alg_root(&v_myclasses, 1);
                            alg_hold_top = rh_1674;
                            {
                                int32_t rt_1675 = alg_root_top;
                                int32_t rh_1676 = alg_hold_top;
                                Value v_i = alg_int(0);
                                (void)v_i;
                                alg_root(&v_i, 1);
                                alg_hold_top = rh_1676;
                                {
                                    int32_t rh_1677 = alg_hold_top;
                                    for (; (alg_hold_top = rh_1677, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_myclasses, "Length")))))); (alg_hold_top = rh_1677, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                                        alg_safe_point();
                                        (void)(alg_hold(alg_invoke(alg_property(v_this, "VisibleClasses"), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_myclasses, v_i))))}, 1))}, 1)));
                                    }
                                }
                                alg_hold_top = rh_1676;
                                alg_root_top = rt_1675;
                            }
                            alg_hold_top = rh_1674;
                            alg_root_top = rt_1673;
                        }
                    }
                    alg_hold_top = rh_1622;
                    {
                        int32_t rt_1678 = alg_root_top;
                        Value loop_84 = alg_iterable(alg_hold(alg_property(v_unit, "Imports")));
                        (void)loop_84;
                        alg_root(&loop_84, 1);
                        for (int32_t at_84 = 0; at_84 < alg_iterable_count(loop_84); at_84++) {
                            alg_safe_point();
                            int32_t rt_1679 = alg_root_top;
                            Value v_theimport = alg_iterable_at(loop_84, at_84);
                            (void)v_theimport;
                            alg_root(&v_theimport, 1);
                            if (alg_truthy(alg_hold((or_23 = alg_hold(alg_invoke(alg_property(v_this, "ClassesIn"), "Contains", (Value[]){alg_hold(alg_str(v_theimport))}, 1)), !alg_truthy(or_23) ? or_23 : alg_hold(alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){alg_hold(alg_str(v_theimport))}, 1)))))) {
                                {
                                    int32_t rt_1680 = alg_root_top;
                                    int32_t rh_1681 = alg_hold_top;
                                    Value v_theirs = alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "ClassesIn"), "Get", (Value[]){alg_hold(alg_str(v_theimport))}, 1), ALG_KIND_SET, "Set"))), "ToList", NULL, 0));
                                    (void)v_theirs;
                                    alg_root(&v_theirs, 1);
                                    alg_hold_top = rh_1681;
                                    Value v_shown = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){alg_hold(alg_str(v_theimport))}, 1), ALG_KIND_SET, "Set"));
                                    (void)v_shown;
                                    alg_root(&v_shown, 1);
                                    alg_hold_top = rh_1681;
                                    {
                                        int32_t rt_1682 = alg_root_top;
                                        int32_t rh_1683 = alg_hold_top;
                                        Value v_j = alg_int(0);
                                        (void)v_j;
                                        alg_root(&v_j, 1);
                                        alg_hold_top = rh_1683;
                                        {
                                            int32_t rh_1684 = alg_hold_top;
                                            for (; (alg_hold_top = rh_1684, alg_truthy(alg_hold(alg_less(v_j, alg_hold(alg_property(v_theirs, "Length")))))); (alg_hold_top = rh_1684, (v_j = alg_hold(alg_add(v_j, alg_int(1)))))) {
                                                alg_safe_point();
                                                if (alg_truthy(alg_hold(alg_invoke(v_shown, "Contains", (Value[]){alg_hold(alg_subscript_get(v_theirs, v_j))}, 1)))) {
                                                    (void)(alg_hold(alg_invoke(alg_property(v_this, "VisibleClasses"), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_theirs, v_j))))}, 1))}, 1)));
                                                }
                                            }
                                        }
                                        alg_hold_top = rh_1683;
                                        alg_root_top = rt_1682;
                                    }
                                    alg_hold_top = rh_1681;
                                    alg_root_top = rt_1680;
                                }
                            }
                            alg_root_top = rt_1679;
                        }
                        alg_root_top = rt_1678;
                    }
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "ShadowArities", alg_hold(alg_set())));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "ShadowWhole", alg_hold(alg_set())));
                    alg_hold_top = rh_1622;
                    (void)(alg_hold(alg_invoke(v_this, "CollectShadowArities", (Value[]){alg_hold(alg_property(v_unit, "Statements")), alg_hold(alg_list())}, 2)));
                    alg_hold_top = rh_1622;
                    {
                        int32_t rt_1685 = alg_root_top;
                        Value loop_85 = alg_iterable(alg_hold(alg_property(v_unit, "Imports")));
                        (void)loop_85;
                        alg_root(&loop_85, 1);
                        for (int32_t at_85 = 0; at_85 < alg_iterable_count(loop_85); at_85++) {
                            alg_safe_point();
                            int32_t rt_1686 = alg_root_top;
                            Value v_theimport = alg_iterable_at(loop_85, at_85);
                            (void)v_theimport;
                            alg_root(&v_theimport, 1);
                            {
                                int32_t rt_1687 = alg_root_top;
                                Value loop_86 = alg_iterable(v_units);
                                (void)loop_86;
                                alg_root(&loop_86, 1);
                                for (int32_t at_86 = 0; at_86 < alg_iterable_count(loop_86); at_86++) {
                                    alg_safe_point();
                                    int32_t rt_1688 = alg_root_top;
                                    Value v_other = alg_iterable_at(loop_86, at_86);
                                    (void)v_other;
                                    alg_root(&v_other, 1);
                                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_str(alg_hold(alg_property(v_other, "Name")))), alg_hold(alg_str(v_theimport)))))) {
                                        (void)(alg_hold(alg_invoke(v_this, "CollectShadowArities", (Value[]){alg_hold(alg_property(v_other, "Statements")), alg_hold(alg_property(v_other, "PrivateNames"))}, 2)));
                                    }
                                    alg_root_top = rt_1688;
                                }
                                alg_root_top = rt_1687;
                            }
                            alg_root_top = rt_1686;
                        }
                        alg_root_top = rt_1685;
                    }
                    alg_hold_top = rh_1622;
                    {
                        int32_t rt_1689 = alg_root_top;
                        Value loop_87 = alg_iterable(alg_hold(alg_property(v_unit, "Statements")));
                        (void)loop_87;
                        alg_root(&loop_87, 1);
                        for (int32_t at_87 = 0; at_87 < alg_iterable_count(loop_87); at_87++) {
                            alg_safe_point();
                            int32_t rt_1690 = alg_root_top;
                            Value v_thestmt = alg_iterable_at(loop_87, at_87);
                            (void)v_thestmt;
                            alg_root(&v_thestmt, 1);
                            {
                                int32_t rh_1691 = alg_hold_top;
                                if (alg_truthy(alg_hold((or_24 = alg_is_class(v_thestmt, k_functionstmt), !alg_truthy(or_24) ? or_24 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1)))))))) {
                                    {
                                        int32_t rh_1692 = alg_hold_top;
                                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(v_this, "Prototype", (Value[]){v_thestmt}, 1)), alg_char_value(59))), alg_char_value(10)))}, 1)));
                                        alg_hold_top = rh_1692;
                                        if (alg_truthy(alg_hold(alg_invoke(v_this, "Exported", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)))) {
                                            (void)(alg_set_property(v_this, "Header", alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_property(v_this, "Header"), alg_hold(alg_invoke(v_this, "Prototype", (Value[]){v_thestmt}, 1)))), alg_char_value(59))), alg_char_value(10)))));
                                        }
                                        alg_hold_top = rh_1692;
                                    }
                                }
                                alg_hold_top = rh_1691;
                            }
                            alg_root_top = rt_1690;
                        }
                        alg_root_top = rt_1689;
                    }
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(true)));
                    alg_hold_top = rh_1622;
                    (void)(alg_hold(alg_invoke(v_this, "PushLabels", (Value[]){alg_hold(alg_property(v_unit, "Statements"))}, 1)));
                    alg_hold_top = rh_1622;
                    Value v_holds = alg_hold(alg_invoke(v_this, "OpenHolds", NULL, 0));
                    (void)v_holds;
                    alg_root(&v_holds, 1);
                    alg_hold_top = rh_1622;
                    {
                        int32_t rt_1693 = alg_root_top;
                        Value loop_88 = alg_iterable(alg_hold(alg_property(v_unit, "Statements")));
                        (void)loop_88;
                        alg_root(&loop_88, 1);
                        for (int32_t at_88 = 0; at_88 < alg_iterable_count(loop_88); at_88++) {
                            alg_safe_point();
                            int32_t rt_1694 = alg_root_top;
                            Value v_thestmt = alg_iterable_at(loop_88, at_88);
                            (void)v_thestmt;
                            alg_root(&v_thestmt, 1);
                            {
                                int32_t rh_1695 = alg_hold_top;
                                if (alg_truthy(alg_hold((or_26 = alg_hold(alg_invoke(v_this, "RunsWhenTesting", (Value[]){v_thestmt}, 1)), alg_truthy(or_26) ? or_26 : alg_hold(alg_not((alg_hold((or_25 = alg_property(v_this, "EmitTests"), !alg_truthy(or_25) ? or_25 : v_ismain))))))))) {
                                    {
                                        int32_t rh_1696 = alg_hold_top;
                                        if (alg_truthy(alg_is_class(v_thestmt, k_blockstmt))) {
                                            {
                                                int32_t rh_1697 = alg_hold_top;
                                                (void)(alg_set_property(v_this, "Volatiles", alg_hold(alg_invoke(v_this, "ContainsTry", (Value[]){alg_hold(alg_property(v_thestmt, "Statements"))}, 1))));
                                                alg_hold_top = rh_1697;
                                                (void)(alg_set_property(v_this, "Boxed", alg_hold(alg_invoke(v_this, "BoxesFor", (Value[]){alg_hold(alg_property(v_thestmt, "Statements"))}, 1))));
                                                alg_hold_top = rh_1697;
                                                (void)(alg_set_property(v_this, "Cells", alg_hold(alg_list())));
                                                alg_hold_top = rh_1697;
                                                (void)(alg_hold(alg_invoke(v_this, "ExecuteHeld", (Value[]){v_thestmt, v_holds}, 2)));
                                                alg_hold_top = rh_1697;
                                                (void)(alg_set_property(v_this, "Boxed", alg_hold(alg_list())));
                                                alg_hold_top = rh_1697;
                                                (void)(alg_set_property(v_this, "Cells", alg_hold(alg_list())));
                                                alg_hold_top = rh_1697;
                                                (void)(alg_set_property(v_this, "Volatiles", alg_bool(false)));
                                                alg_hold_top = rh_1697;
                                            }
                                        } else {
                                            (void)(alg_hold(alg_invoke(v_this, "ExecuteHeld", (Value[]){v_thestmt, v_holds}, 2)));
                                        }
                                        alg_hold_top = rh_1696;
                                    }
                                }
                                alg_hold_top = rh_1695;
                            }
                            alg_root_top = rt_1694;
                        }
                        alg_root_top = rt_1693;
                    }
                    alg_hold_top = rh_1622;
                    (void)(alg_hold(alg_invoke(v_this, "PopLabels", NULL, 0)));
                    alg_hold_top = rh_1622;
                    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
                    alg_hold_top = rh_1622;
                    if (alg_truthy(v_ismain)) {
                        {
                            int32_t rt_1698 = alg_root_top;
                            int32_t rh_1699 = alg_hold_top;
                            Value v_initbody = alg_property(v_this, "MainBody");
                            (void)v_initbody;
                            alg_root(&v_initbody, 1);
                            alg_hold_top = rh_1699;
                            (void)(alg_set_property(v_this, "MainBody", alg_hold(alg_buffer(alg_int(0)))));
                            alg_hold_top = rh_1699;
                            if (alg_truthy(alg_property(v_this, "EmitTests"))) {
                                (void)(alg_hold(alg_invoke(v_this, "EmitTestRunner", NULL, 0)));
                            }
                            alg_hold_top = rh_1699;
                            (void)((v_mainbodytext = alg_hold(alg_property(alg_property(v_this, "MainBody"), "Text"))));
                            alg_hold_top = rh_1699;
                            (void)(alg_set_property(v_this, "MainBody", v_initbody));
                            alg_hold_top = rh_1699;
                            alg_root_top = rt_1698;
                        }
                    }
                    alg_hold_top = rh_1622;
                    (void)(alg_hold(alg_invoke(v_files, "Put", (Value[]){alg_hold(alg_add(alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name")))), alg_literal(".h"))), alg_hold(alg_invoke(v_this, "UnitHeader", (Value[]){v_unit}, 1))}, 2)));
                    alg_hold_top = rh_1622;
                    (void)(alg_hold(alg_invoke(v_files, "Put", (Value[]){alg_hold(alg_add(alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name")))), alg_literal(".c"))), alg_hold(alg_invoke(v_this, "UnitSource", (Value[]){v_unit, v_units, v_ismain, v_mainbodytext}, 4))}, 2)));
                    alg_hold_top = rh_1622;
                    alg_root_top = rt_1621;
                }
            }
        }
        alg_hold_top = rh_1619;
        alg_root_top = rt_1618;
    }
    alg_hold_top = rh_1568;
    Value ret_89 = v_files;
    alg_root_top = rt_base;
    return ret_89;
    alg_hold_top = rh_1568;
    Value ret_90 = alg_nil();
    alg_root_top = rt_base;
    return ret_90;
}

static Value m_cemitter_unitheader_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_unit = args[0];
    (void)v_unit;
    alg_root(&v_unit, 1);
    int32_t rh_1700 = alg_hold_top;
    Value v_guard = alg_nil();
    (void)v_guard;
    alg_root(&v_guard, 1);
    alg_hold_top = rh_1700;
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    alg_hold_top = rh_1700;
    (void)((v_guard = alg_hold(alg_add(alg_hold(alg_add(alg_literal("ALG_"), alg_hold(alg_invoke(v_this, "Upper", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name"))))}, 1)))), alg_literal("_H")))));
    alg_hold_top = rh_1700;
    (void)((v_text = alg_hold(alg_add(alg_literal("/* Generated from Algol-24.  Do not edit. */"), alg_char_value(10)))));
    alg_hold_top = rh_1700;
    (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("#ifndef "))), v_guard)), alg_char_value(10)))));
    alg_hold_top = rh_1700;
    (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("#define "))), v_guard)), alg_char_value(10))), alg_char_value(10)))));
    alg_hold_top = rh_1700;
    (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("#include \"algol.h\""))), alg_char_value(10))), alg_char_value(10)))));
    alg_hold_top = rh_1700;
    (void)((v_text = alg_hold(alg_add(v_text, alg_property(v_this, "Header")))));
    alg_hold_top = rh_1700;
    (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("void init_"))), alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name")))))), alg_literal("(void);"))), alg_char_value(10)))));
    alg_hold_top = rh_1700;
    (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_char_value(10))), alg_literal("#endif"))), alg_char_value(10)))));
    alg_hold_top = rh_1700;
    Value ret_91 = v_text;
    alg_root_top = rt_base;
    return ret_91;
    alg_hold_top = rh_1700;
    Value ret_92 = alg_nil();
    alg_root_top = rt_base;
    return ret_92;
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
    int32_t rh_1701 = alg_hold_top;
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    alg_hold_top = rh_1701;
    (void)((v_text = alg_hold(alg_add(alg_literal("/* Generated from Algol-24.  Do not edit. */"), alg_char_value(10)))));
    alg_hold_top = rh_1701;
    (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("#include \""))), alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name")))))), alg_literal(".h\""))), alg_char_value(10)))));
    alg_hold_top = rh_1701;
    {
        int32_t rt_1702 = alg_root_top;
        Value loop_93 = alg_iterable(alg_hold(alg_property(v_unit, "Imports")));
        (void)loop_93;
        alg_root(&loop_93, 1);
        for (int32_t at_93 = 0; at_93 < alg_iterable_count(loop_93); at_93++) {
            alg_safe_point();
            int32_t rt_1703 = alg_root_top;
            Value v_import = alg_iterable_at(loop_93, at_93);
            (void)v_import;
            alg_root(&v_import, 1);
            (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("#include \""))), alg_hold(alg_str(v_import)))), alg_literal(".h\""))), alg_char_value(10)))));
            alg_root_top = rt_1703;
        }
        alg_root_top = rt_1702;
    }
    alg_hold_top = rh_1701;
    (void)((v_text = alg_hold(alg_add(v_text, alg_char_value(10)))));
    alg_hold_top = rh_1701;
    if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(alg_property(v_this, "Declarations"), "Length")), alg_int(0))))) {
        (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(v_text, alg_hold(alg_property(alg_property(v_this, "Declarations"), "Text")))), alg_char_value(10)))));
    }
    alg_hold_top = rh_1701;
    if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(alg_property(v_this, "Functions"), "Length")), alg_int(0))))) {
        (void)((v_text = alg_hold(alg_add(v_text, alg_hold(alg_property(alg_property(v_this, "Functions"), "Text"))))));
    }
    alg_hold_top = rh_1701;
    if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(alg_property(v_this, "RootSymbols"), "Length")), alg_int(0))))) {
        {
            int32_t rh_1704 = alg_hold_top;
            (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("static Value *roots_"))), alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name")))))), alg_literal("[] = {"))), alg_char_value(10)))));
            alg_hold_top = rh_1704;
            {
                int32_t rt_1705 = alg_root_top;
                Value loop_94 = alg_iterable(alg_property(v_this, "RootSymbols"));
                (void)loop_94;
                alg_root(&loop_94, 1);
                for (int32_t at_94 = 0; at_94 < alg_iterable_count(loop_94); at_94++) {
                    alg_safe_point();
                    int32_t rt_1706 = alg_root_top;
                    Value v_each = alg_iterable_at(loop_94, at_94);
                    (void)v_each;
                    alg_root(&v_each, 1);
                    (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("    &"))), alg_hold(alg_str(v_each)))), alg_char_value(44))), alg_char_value(10)))));
                    alg_root_top = rt_1706;
                }
                alg_root_top = rt_1705;
            }
            alg_hold_top = rh_1704;
            (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("};"))), alg_char_value(10))), alg_char_value(10)))));
            alg_hold_top = rh_1704;
        }
    }
    alg_hold_top = rh_1701;
    (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("void init_"))), alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name")))))), alg_literal("(void) {"))), alg_char_value(10)))));
    alg_hold_top = rh_1701;
    if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(alg_property(v_this, "RootSymbols"), "Length")), alg_int(0))))) {
        (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("    alg_roots(roots_"))), alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name")))))), alg_literal(", "))), alg_hold(alg_str(alg_hold(alg_property(alg_property(v_this, "RootSymbols"), "Length")))))), alg_literal(");"))), alg_char_value(10)))));
    }
    alg_hold_top = rh_1701;
    (void)((v_text = alg_hold(alg_add(v_text, alg_hold(alg_property(alg_property(v_this, "Shells"), "Text"))))));
    alg_hold_top = rh_1701;
    (void)((v_text = alg_hold(alg_add(v_text, alg_hold(alg_property(alg_property(v_this, "Setup"), "Text"))))));
    alg_hold_top = rh_1701;
    (void)((v_text = alg_hold(alg_add(v_text, alg_hold(alg_property(alg_property(v_this, "MainBody"), "Text"))))));
    alg_hold_top = rh_1701;
    (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(v_text, alg_char_value(125))), alg_char_value(10)))));
    alg_hold_top = rh_1701;
    if (alg_truthy(v_ismain)) {
        {
            int32_t rh_1707 = alg_hold_top;
            (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_char_value(10))), alg_literal("int main(int argc, char **argv) {"))), alg_char_value(10)))));
            alg_hold_top = rh_1707;
            (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("    alg_set_arguments(argc, argv);"))), alg_char_value(10)))));
            alg_hold_top = rh_1707;
            (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("    init_"))), alg_hold(alg_str(alg_hold(alg_property(v_unit, "Name")))))), alg_literal("();"))), alg_char_value(10)))));
            alg_hold_top = rh_1707;
            (void)((v_text = alg_hold(alg_add(v_text, v_written))));
            alg_hold_top = rh_1707;
            (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_text, alg_literal("    return 0;"))), alg_char_value(10))), alg_char_value(125))), alg_char_value(10)))));
            alg_hold_top = rh_1707;
        }
    }
    alg_hold_top = rh_1701;
    Value ret_95 = v_text;
    alg_root_top = rt_base;
    return ret_95;
    alg_hold_top = rh_1701;
    Value ret_96 = alg_nil();
    alg_root_top = rt_base;
    return ret_96;
}

static Value m_cemitter_upper_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_text = alg_widen(args[0], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    int32_t rh_1708 = alg_hold_top;
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_1708;
    (void)((v_result = alg_literal("")));
    alg_hold_top = rh_1708;
    {
        int32_t rt_1709 = alg_root_top;
        int32_t rh_1710 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1710;
        {
            int32_t rh_1711 = alg_hold_top;
            for (; (alg_hold_top = rh_1711, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_text_length(v_text)))))); (alg_hold_top = rh_1711, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1712 = alg_root_top;
                    int32_t rh_1713 = alg_hold_top;
                    Value v_c = alg_hold(alg_subscript_get(v_text, v_i));
                    (void)v_c;
                    alg_root(&v_c, 1);
                    alg_hold_top = rh_1713;
                    if (alg_truthy(alg_hold(alg_greater_equal(v_c, alg_char_value(97))))) {
                        if (alg_truthy(alg_hold(alg_less_equal(v_c, alg_char_value(122))))) {
                            (void)((v_c = alg_hold(alg_char(alg_hold(alg_subtract(alg_hold(alg_ord(v_c)), alg_int(32)))))));
                        }
                    }
                    alg_hold_top = rh_1713;
                    (void)((v_result = alg_hold(alg_add(v_result, v_c))));
                    alg_hold_top = rh_1713;
                    alg_root_top = rt_1712;
                }
            }
        }
        alg_hold_top = rh_1710;
        alg_root_top = rt_1709;
    }
    alg_hold_top = rh_1708;
    Value ret_97 = v_result;
    alg_root_top = rt_base;
    return ret_97;
    alg_hold_top = rh_1708;
    Value ret_98 = alg_nil();
    alg_root_top = rt_base;
    return ret_98;
}

static Value m_cemitter_emittestrunner_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1714 = alg_hold_top;
    Value v_files = alg_nil();
    (void)v_files;
    alg_root(&v_files, 1);
    alg_hold_top = rh_1714;
    {
        int32_t rt_1715 = alg_root_top;
        Value loop_99 = alg_iterable(alg_property(v_this, "TestSymbols"));
        (void)loop_99;
        alg_root(&loop_99, 1);
        for (int32_t at_99 = 0; at_99 < alg_iterable_count(loop_99); at_99++) {
            alg_safe_point();
            int32_t rt_1716 = alg_root_top;
            Value v_testsymbol = alg_iterable_at(loop_99, at_99);
            (void)v_testsymbol;
            alg_root(&v_testsymbol, 1);
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Value "), alg_hold(alg_str(v_testsymbol)))), alg_literal("(Value **cells, Value *args, int32_t count);"))), alg_char_value(10)))}, 1)));
            alg_root_top = rt_1716;
        }
        alg_root_top = rt_1715;
    }
    alg_hold_top = rh_1714;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    alg_test_begin("), alg_hold(alg_str(alg_hold(alg_property(alg_property(v_this, "Tests"), "Length")))))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_property(v_this, "SourceFile")}, 1)))), alg_literal(");"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1714;
    (void)((v_files = alg_hold(alg_list())));
    alg_hold_top = rh_1714;
    {
        int32_t rt_1717 = alg_root_top;
        Value loop_100 = alg_iterable(alg_property(v_this, "TestFiles"));
        (void)loop_100;
        alg_root(&loop_100, 1);
        for (int32_t at_100 = 0; at_100 < alg_iterable_count(loop_100); at_100++) {
            alg_safe_point();
            int32_t rt_1718 = alg_root_top;
            Value v_testfile = alg_iterable_at(loop_100, at_100);
            (void)v_testfile;
            alg_root(&v_testfile, 1);
            if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_files, "Contains", (Value[]){v_testfile}, 1)))))) {
                (void)(alg_hold(alg_invoke(v_files, "Add", (Value[]){v_testfile}, 1)));
            }
            alg_root_top = rt_1718;
        }
        alg_root_top = rt_1717;
    }
    alg_hold_top = rh_1714;
    {
        int32_t rt_1719 = alg_root_top;
        Value loop_101 = alg_iterable(v_files);
        (void)loop_101;
        alg_root(&loop_101, 1);
        for (int32_t at_101 = 0; at_101 < alg_iterable_count(loop_101); at_101++) {
            alg_safe_point();
            int32_t rt_1720 = alg_root_top;
            Value v_file = alg_iterable_at(loop_101, at_101);
            (void)v_file;
            alg_root(&v_file, 1);
            {
                int32_t rt_1721 = alg_root_top;
                int32_t rh_1722 = alg_hold_top;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    alg_test_file("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(v_file))}, 1)))), alg_literal(");"))), alg_char_value(10)))}, 1)));
                alg_hold_top = rh_1722;
                Value v_ordered = alg_hold(alg_list());
                (void)v_ordered;
                alg_root(&v_ordered, 1);
                alg_hold_top = rh_1722;
                {
                    int32_t rt_1723 = alg_root_top;
                    int32_t rh_1724 = alg_hold_top;
                    Value v_i = alg_int(0);
                    (void)v_i;
                    alg_root(&v_i, 1);
                    alg_hold_top = rh_1724;
                    {
                        int32_t rh_1725 = alg_hold_top;
                        for (; (alg_hold_top = rh_1725, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_property(v_this, "Tests"), "Length")))))); (alg_hold_top = rh_1725, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                            alg_safe_point();
                            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_subscript_get(alg_property(v_this, "TestFiles"), v_i)), v_file)))) {
                                (void)(alg_hold(alg_invoke(v_ordered, "Add", (Value[]){v_i}, 1)));
                            }
                        }
                    }
                    alg_hold_top = rh_1724;
                    alg_root_top = rt_1723;
                }
                alg_hold_top = rh_1722;
                {
                    int32_t rt_1726 = alg_root_top;
                    int32_t rh_1727 = alg_hold_top;
                    Value v_a = alg_int(0);
                    (void)v_a;
                    alg_root(&v_a, 1);
                    alg_hold_top = rh_1727;
                    {
                        int32_t rh_1728 = alg_hold_top;
                        for (; (alg_hold_top = rh_1728, alg_truthy(alg_hold(alg_less(v_a, alg_hold(alg_property(v_ordered, "Length")))))); (alg_hold_top = rh_1728, (v_a = alg_hold(alg_add(v_a, alg_int(1)))))) {
                            alg_safe_point();
                            {
                                int32_t rt_1729 = alg_root_top;
                                int32_t rh_1730 = alg_hold_top;
                                Value v_b = alg_hold(alg_add(v_a, alg_int(1)));
                                (void)v_b;
                                alg_root(&v_b, 1);
                                alg_hold_top = rh_1730;
                                {
                                    int32_t rh_1731 = alg_hold_top;
                                    for (; (alg_hold_top = rh_1731, alg_truthy(alg_hold(alg_less(v_b, alg_hold(alg_property(v_ordered, "Length")))))); (alg_hold_top = rh_1731, (v_b = alg_hold(alg_add(v_b, alg_int(1)))))) {
                                        alg_safe_point();
                                        if (alg_truthy(alg_hold(alg_less(alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_subscript_get(alg_property(v_this, "Tests"), alg_hold(alg_subscript_get(v_ordered, v_b)))), "Name")), "Lexeme")))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_subscript_get(alg_property(v_this, "Tests"), alg_hold(alg_subscript_get(v_ordered, v_a)))), "Name")), "Lexeme")))))))) {
                                            {
                                                int32_t rt_1732 = alg_root_top;
                                                int32_t rh_1733 = alg_hold_top;
                                                Value v_swap = alg_hold(alg_subscript_get(v_ordered, v_a));
                                                (void)v_swap;
                                                alg_root(&v_swap, 1);
                                                alg_hold_top = rh_1733;
                                                (void)(alg_hold(alg_subscript_set(v_ordered, v_a, alg_hold(alg_subscript_get(v_ordered, v_b)))));
                                                alg_hold_top = rh_1733;
                                                (void)(alg_hold(alg_subscript_set(v_ordered, v_b, v_swap)));
                                                alg_hold_top = rh_1733;
                                                alg_root_top = rt_1732;
                                            }
                                        }
                                    }
                                }
                                alg_hold_top = rh_1730;
                                alg_root_top = rt_1729;
                            }
                        }
                    }
                    alg_hold_top = rh_1727;
                    alg_root_top = rt_1726;
                }
                alg_hold_top = rh_1722;
                {
                    int32_t rt_1734 = alg_root_top;
                    Value loop_102 = alg_iterable(v_ordered);
                    (void)loop_102;
                    alg_root(&loop_102, 1);
                    for (int32_t at_102 = 0; at_102 < alg_iterable_count(loop_102); at_102++) {
                        alg_safe_point();
                        int32_t rt_1735 = alg_root_top;
                        Value v_each = alg_iterable_at(loop_102, at_102);
                        (void)v_each;
                        alg_root(&v_each, 1);
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    alg_test_run("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_subscript_get(alg_property(v_this, "Tests"), v_each)), "Name")), "Literal"))))}, 1)))), alg_literal(", "))), alg_hold(alg_str(alg_hold(alg_subscript_get(alg_property(v_this, "TestSymbols"), v_each)))))), alg_literal(");"))), alg_char_value(10)))}, 1)));
                        alg_root_top = rt_1735;
                    }
                    alg_root_top = rt_1734;
                }
                alg_hold_top = rh_1722;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    alg_test_end_file();"), alg_char_value(10)))}, 1)));
                alg_hold_top = rh_1722;
                alg_root_top = rt_1721;
            }
            alg_root_top = rt_1720;
        }
        alg_root_top = rt_1719;
    }
    alg_hold_top = rh_1714;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "MainBody"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    return alg_test_summary();"), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1714;
    Value ret_103 = alg_nil();
    alg_root_top = rt_base;
    return ret_103;
}

static Value m_cemitter_execute_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1736 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_thestmt, "Accept", (Value[]){v_this}, 1)));
    alg_hold_top = rh_1736;
    Value ret_104 = alg_nil();
    alg_root_top = rt_base;
    return ret_104;
}

static Value m_cemitter_evaluate_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = args[0];
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1737 = alg_hold_top;
    Value v_text = alg_nil();
    (void)v_text;
    alg_root(&v_text, 1);
    alg_hold_top = rh_1737;
    (void)((v_text = alg_hold(alg_cast_kind(alg_invoke(v_theexpr, "Accept", (Value[]){v_this}, 1), ALG_KIND_STRING, "String"))));
    alg_hold_top = rh_1737;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_theexpr, "Cast")), alg_literal(""))))) {
        {
            int32_t rt_1738 = alg_root_top;
            int32_t rh_1739 = alg_hold_top;
            Value v_kind = alg_hold(alg_invoke(v_this, "ResolvedKind", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "Cast"))))}, 1));
            (void)v_kind;
            alg_root(&v_kind, 1);
            alg_hold_top = rh_1739;
            if (alg_truthy(alg_hold(alg_not_equal(v_kind, alg_literal(""))))) {
                (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_cast_kind("), v_text)), alg_literal(", "))), v_kind)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "Cast"))))}, 1)))), alg_char_value(41)))));
            } else {
                {
                    int32_t rt_1740 = alg_root_top;
                    int32_t rh_1741 = alg_hold_top;
                    Value v_handle = alg_hold(alg_invoke(v_this, "ResolvedClass", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "Cast"))))}, 1));
                    (void)v_handle;
                    alg_root(&v_handle, 1);
                    alg_hold_top = rh_1741;
                    if (alg_truthy(alg_hold(alg_not_equal(v_handle, alg_literal(""))))) {
                        (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_cast_class("), v_text)), alg_literal(", "))), v_handle)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "Cast"))))}, 1)))), alg_char_value(41)))));
                    } else {
                        (void)((v_text = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_cast("), v_text)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "Cast"))))}, 1)))), alg_char_value(41)))));
                    }
                    alg_hold_top = rh_1741;
                    alg_root_top = rt_1740;
                }
            }
            alg_hold_top = rh_1739;
            alg_root_top = rt_1738;
        }
    }
    alg_hold_top = rh_1737;
    if (alg_truthy(alg_hold((or_27 = alg_hold(alg_invoke(v_this, "NeedsHold", (Value[]){v_theexpr}, 1)), !alg_truthy(or_27) ? or_27 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "VoidCall", (Value[]){v_text}, 1)))))))) {
        Value ret_105 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_hold("), v_text)), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_105;
    }
    alg_hold_top = rh_1737;
    Value ret_106 = v_text;
    alg_root_top = rt_base;
    return ret_106;
    alg_hold_top = rh_1737;
    Value ret_107 = alg_nil();
    alg_root_top = rt_base;
    return ret_107;
}

static Value m_cemitter_emittest_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1742 = alg_hold_top;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    alg_hold_top = rh_1742;
    (void)((v_symbol = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("t_"), alg_property(v_this, "UnitName"))), alg_char_value(95))), alg_hold(alg_str(alg_property(v_this, "UnitTests")))))));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "UnitTests", alg_hold(alg_add(alg_property(v_this, "UnitTests"), alg_int(1)))));
    alg_hold_top = rh_1742;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Tests"), "Add", (Value[]){v_thestmt}, 1)));
    alg_hold_top = rh_1742;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "TestFiles"), "Add", (Value[]){alg_property(v_this, "CurrentFile")}, 1)));
    alg_hold_top = rh_1742;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "TestSymbols"), "Add", (Value[]){v_symbol}, 1)));
    alg_hold_top = rh_1742;
    Value v_enclosingtarget = alg_property(v_this, "Target");
    (void)v_enclosingtarget;
    alg_root(&v_enclosingtarget, 1);
    alg_hold_top = rh_1742;
    Value v_enclosingbody = alg_property(v_this, "Body");
    (void)v_enclosingbody;
    alg_root(&v_enclosingbody, 1);
    alg_hold_top = rh_1742;
    Value v_enclosinglocals = alg_property(v_this, "Locals");
    (void)v_enclosinglocals;
    alg_root(&v_enclosinglocals, 1);
    alg_hold_top = rh_1742;
    Value v_enclosingtop = alg_property(v_this, "AtTopLevel");
    (void)v_enclosingtop;
    alg_root(&v_enclosingtop, 1);
    alg_hold_top = rh_1742;
    Value v_enclosingvolatiles = alg_property(v_this, "Volatiles");
    (void)v_enclosingvolatiles;
    alg_root(&v_enclosingvolatiles, 1);
    alg_hold_top = rh_1742;
    Value v_enclosingdepth = alg_property(v_this, "Depth");
    (void)v_enclosingdepth;
    alg_root(&v_enclosingdepth, 1);
    alg_hold_top = rh_1742;
    Value v_enclosingboxed = alg_property(v_this, "Boxed");
    (void)v_enclosingboxed;
    alg_root(&v_enclosingboxed, 1);
    alg_hold_top = rh_1742;
    Value v_enclosingcaptured = alg_property(v_this, "Captured");
    (void)v_enclosingcaptured;
    alg_root(&v_enclosingcaptured, 1);
    alg_hold_top = rh_1742;
    Value v_enclosingcells = alg_property(v_this, "Cells");
    (void)v_enclosingcells;
    alg_root(&v_enclosingcells, 1);
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Target", alg_literal("body")));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Body", alg_hold(alg_buffer(alg_int(0)))));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Depth", alg_int(1)));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Volatiles", alg_hold(alg_invoke(v_this, "ContainsTry", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1))));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Boxed", alg_hold(alg_invoke(v_this, "BoxesFor", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1))));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Captured", alg_hold(alg_map())));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Cells", alg_hold(alg_list())));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Locals", alg_hold(alg_list())));
    alg_hold_top = rh_1742;
    Value v_enclosingtrydepth = alg_property(v_this, "TryDepth");
    (void)v_enclosingtrydepth;
    alg_root(&v_enclosingtrydepth, 1);
    alg_hold_top = rh_1742;
    Value v_enclosinglooptry = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosinglooptry;
    alg_root(&v_enclosinglooptry, 1);
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "TryDepth", alg_int(0)));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_int(0)));
    alg_hold_top = rh_1742;
    (void)(alg_hold(alg_invoke(v_this, "HoistCells", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1)));
    alg_hold_top = rh_1742;
    (void)(alg_hold(alg_invoke(v_this, "PushLabels", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1)));
    alg_hold_top = rh_1742;
    Value v_holds = alg_hold(alg_invoke(v_this, "OpenHolds", NULL, 0));
    (void)v_holds;
    alg_root(&v_holds, 1);
    alg_hold_top = rh_1742;
    {
        int32_t rt_1743 = alg_root_top;
        Value loop_108 = alg_iterable(alg_hold(alg_property(v_thestmt, "Body")));
        (void)loop_108;
        alg_root(&loop_108, 1);
        for (int32_t at_108 = 0; at_108 < alg_iterable_count(loop_108); at_108++) {
            alg_safe_point();
            int32_t rt_1744 = alg_root_top;
            Value v_each = alg_iterable_at(loop_108, at_108);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_hold(alg_invoke(v_this, "ExecuteHeld", (Value[]){v_each, v_holds}, 2)));
            alg_root_top = rt_1744;
        }
        alg_root_top = rt_1743;
    }
    alg_hold_top = rh_1742;
    (void)(alg_hold(alg_invoke(v_this, "PopLabels", NULL, 0)));
    alg_hold_top = rh_1742;
    Value v_written = alg_hold(alg_property(alg_property(v_this, "Body"), "Text"));
    (void)v_written;
    alg_root(&v_written, 1);
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Target", v_enclosingtarget));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Body", v_enclosingbody));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Locals", v_enclosinglocals));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "AtTopLevel", v_enclosingtop));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Volatiles", v_enclosingvolatiles));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Depth", v_enclosingdepth));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Boxed", v_enclosingboxed));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Captured", v_enclosingcaptured));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "Cells", v_enclosingcells));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "TryDepth", v_enclosingtrydepth));
    alg_hold_top = rh_1742;
    (void)(alg_set_property(v_this, "LoopTryDepth", v_enclosinglooptry));
    alg_hold_top = rh_1742;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Value "), v_symbol)), alg_literal("(Value **cells, Value *args, int32_t count);"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1742;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Value "), v_symbol)), alg_literal("(Value **cells, Value *args, int32_t count) {"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1742;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    (void)cells; (void)args; (void)count;"), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1742;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_written}, 1)));
    alg_hold_top = rh_1742;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    return alg_nil();"), alg_char_value(10))), alg_char_value(125))), alg_char_value(10))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1742;
    Value ret_109 = alg_nil();
    alg_root_top = rt_base;
    return ret_109;
}

static Value m_cemitter_refusebarebinding_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_body = args[0];
    (void)v_body;
    alg_root(&v_body, 1);
    int32_t rh_1745 = alg_hold_top;
    if (alg_truthy(alg_hold((or_28 = alg_is_class(v_body, k_varstmt), alg_truthy(or_28) ? or_28 : alg_is_class(v_body, k_vargroupstmt))))) {
        (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_literal("A 'var' as an unbraced branch or loop body")}, 1)));
    }
    alg_hold_top = rh_1745;
    Value ret_110 = alg_nil();
    alg_root_top = rt_base;
    return ret_110;
}

static Value m_cemitter_declaresnested_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_1746 = alg_hold_top;
    {
        int32_t rt_1747 = alg_root_top;
        Value loop_111 = alg_iterable(v_statements);
        (void)loop_111;
        alg_root(&loop_111, 1);
        for (int32_t at_111 = 0; at_111 < alg_iterable_count(loop_111); at_111++) {
            alg_safe_point();
            int32_t rt_1748 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_111, at_111);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rh_1749 = alg_hold_top;
                if (alg_truthy(alg_is_class(v_thestmt, k_functionstmt))) {
                    Value ret_112 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_112;
                }
                alg_hold_top = rh_1749;
                if (alg_truthy(alg_hold((or_29 = alg_is_class(v_thestmt, k_blockstmt), !alg_truthy(or_29) ? or_29 : alg_hold(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_hold(alg_property(v_thestmt, "Statements"))}, 1)))))) {
                    Value ret_113 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_113;
                }
                alg_hold_top = rh_1749;
                if (alg_truthy(alg_hold((or_30 = alg_is_class(v_thestmt, k_whilestmt), !alg_truthy(or_30) ? or_30 : alg_hold(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "Body"))))}, 1)))))) {
                    Value ret_114 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_114;
                }
                alg_hold_top = rh_1749;
                if (alg_truthy(alg_hold((or_31 = alg_is_class(v_thestmt, k_forinstmt), !alg_truthy(or_31) ? or_31 : alg_hold(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "Body"))))}, 1)))))) {
                    Value ret_115 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_115;
                }
                alg_hold_top = rh_1749;
                if (alg_truthy(alg_is_class(v_thestmt, k_ifstmt))) {
                    {
                        int32_t rh_1750 = alg_hold_top;
                        if (alg_truthy(alg_hold(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "ThenBranch"))))}, 1)))) {
                            Value ret_116 = alg_bool(true);
                            alg_root_top = rt_base;
                            return ret_116;
                        }
                        alg_hold_top = rh_1750;
                        if (alg_truthy(alg_hold((or_32 = alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "ElseBranch")), alg_nil())), !alg_truthy(or_32) ? or_32 : alg_hold(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "ElseBranch"))))}, 1)))))) {
                            Value ret_117 = alg_bool(true);
                            alg_root_top = rt_base;
                            return ret_117;
                        }
                        alg_hold_top = rh_1750;
                    }
                }
                alg_hold_top = rh_1749;
                if (alg_truthy(alg_is_class(v_thestmt, k_trystmt))) {
                    {
                        int32_t rt_1751 = alg_root_top;
                        int32_t rh_1752 = alg_hold_top;
                        if (alg_truthy(alg_hold(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "TryBlock"))))}, 1)))) {
                            Value ret_118 = alg_bool(true);
                            alg_root_top = rt_base;
                            return ret_118;
                        }
                        alg_hold_top = rh_1752;
                        Value v_handlers = alg_hold(alg_invoke(alg_hold(alg_property(v_thestmt, "Handlers")), "Values", NULL, 0));
                        (void)v_handlers;
                        alg_root(&v_handlers, 1);
                        alg_hold_top = rh_1752;
                        {
                            int32_t rt_1753 = alg_root_top;
                            Value loop_119 = alg_iterable(v_handlers);
                            (void)loop_119;
                            alg_root(&loop_119, 1);
                            for (int32_t at_119 = 0; at_119 < alg_iterable_count(loop_119); at_119++) {
                                alg_safe_point();
                                int32_t rt_1754 = alg_root_top;
                                Value v_handler = alg_iterable_at(loop_119, at_119);
                                (void)v_handler;
                                alg_root(&v_handler, 1);
                                if (alg_truthy(alg_hold(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_handler, "Body"))))}, 1)))) {
                                    Value ret_120 = alg_bool(true);
                                    alg_root_top = rt_base;
                                    return ret_120;
                                }
                                alg_root_top = rt_1754;
                            }
                            alg_root_top = rt_1753;
                        }
                        alg_hold_top = rh_1752;
                        alg_root_top = rt_1751;
                    }
                }
                alg_hold_top = rh_1749;
            }
            alg_root_top = rt_1748;
        }
        alg_root_top = rt_1747;
    }
    alg_hold_top = rh_1746;
    Value ret_121 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_121;
    alg_hold_top = rh_1746;
    Value ret_122 = alg_nil();
    alg_root_top = rt_base;
    return ret_122;
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
    int32_t rh_1755 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(v_names, "Contains", (Value[]){v_name}, 1)))))) {
        (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){v_name}, 1)));
    }
    alg_hold_top = rh_1755;
    Value ret_123 = alg_nil();
    alg_root_top = rt_base;
    return ret_123;
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
    int32_t rh_1756 = alg_hold_top;
    {
        int32_t rt_1757 = alg_root_top;
        Value loop_124 = alg_iterable(v_statements);
        (void)loop_124;
        alg_root(&loop_124, 1);
        for (int32_t at_124 = 0; at_124 < alg_iterable_count(loop_124); at_124++) {
            alg_safe_point();
            int32_t rt_1758 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_124, at_124);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rh_1759 = alg_hold_top;
                if (alg_truthy(alg_is_class(v_thestmt, k_varstmt))) {
                    (void)(alg_hold(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 2)));
                }
                alg_hold_top = rh_1759;
                if (alg_truthy(alg_is_class(v_thestmt, k_vargroupstmt))) {
                    {
                        int32_t rt_1760 = alg_root_top;
                        Value loop_125 = alg_iterable(alg_hold(alg_property(v_thestmt, "Names")));
                        (void)loop_125;
                        alg_root(&loop_125, 1);
                        for (int32_t at_125 = 0; at_125 < alg_iterable_count(loop_125); at_125++) {
                            alg_safe_point();
                            int32_t rt_1761 = alg_root_top;
                            Value v_thename = alg_iterable_at(loop_125, at_125);
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            (void)(alg_hold(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme"))))}, 2)));
                            alg_root_top = rt_1761;
                        }
                        alg_root_top = rt_1760;
                    }
                }
                alg_hold_top = rh_1759;
                if (alg_truthy(alg_is_class(v_thestmt, k_forinstmt))) {
                    {
                        int32_t rh_1762 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 2)));
                        alg_hold_top = rh_1762;
                        (void)(alg_hold(alg_invoke(v_this, "CollectBindings", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "Body")))), v_names}, 2)));
                        alg_hold_top = rh_1762;
                    }
                }
                alg_hold_top = rh_1759;
                if (alg_truthy(alg_is_class(v_thestmt, k_blockstmt))) {
                    (void)(alg_hold(alg_invoke(v_this, "CollectBindings", (Value[]){alg_hold(alg_property(v_thestmt, "Statements")), v_names}, 2)));
                }
                alg_hold_top = rh_1759;
                if (alg_truthy(alg_is_class(v_thestmt, k_whilestmt))) {
                    (void)(alg_hold(alg_invoke(v_this, "CollectBindings", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "Body")))), v_names}, 2)));
                }
                alg_hold_top = rh_1759;
                if (alg_truthy(alg_is_class(v_thestmt, k_ifstmt))) {
                    {
                        int32_t rh_1763 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(v_this, "CollectBindings", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "ThenBranch")))), v_names}, 2)));
                        alg_hold_top = rh_1763;
                        if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "ElseBranch")), alg_nil())))) {
                            (void)(alg_hold(alg_invoke(v_this, "CollectBindings", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "ElseBranch")))), v_names}, 2)));
                        }
                        alg_hold_top = rh_1763;
                    }
                }
                alg_hold_top = rh_1759;
                if (alg_truthy(alg_is_class(v_thestmt, k_trystmt))) {
                    {
                        int32_t rt_1764 = alg_root_top;
                        int32_t rh_1765 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(v_this, "CollectBindings", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "TryBlock")))), v_names}, 2)));
                        alg_hold_top = rh_1765;
                        Value v_handlers = alg_hold(alg_invoke(alg_hold(alg_property(v_thestmt, "Handlers")), "Values", NULL, 0));
                        (void)v_handlers;
                        alg_root(&v_handlers, 1);
                        alg_hold_top = rh_1765;
                        {
                            int32_t rt_1766 = alg_root_top;
                            Value loop_126 = alg_iterable(v_handlers);
                            (void)loop_126;
                            alg_root(&loop_126, 1);
                            for (int32_t at_126 = 0; at_126 < alg_iterable_count(loop_126); at_126++) {
                                alg_safe_point();
                                int32_t rt_1767 = alg_root_top;
                                Value v_handler = alg_iterable_at(loop_126, at_126);
                                (void)v_handler;
                                alg_root(&v_handler, 1);
                                {
                                    int32_t rh_1768 = alg_hold_top;
                                    (void)(alg_hold(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_hold(alg_str(alg_hold(alg_property(v_handler, "Name"))))}, 2)));
                                    alg_hold_top = rh_1768;
                                    (void)(alg_hold(alg_invoke(v_this, "CollectBindings", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_handler, "Body")))), v_names}, 2)));
                                    alg_hold_top = rh_1768;
                                }
                                alg_root_top = rt_1767;
                            }
                            alg_root_top = rt_1766;
                        }
                        alg_hold_top = rh_1765;
                        alg_root_top = rt_1764;
                    }
                }
                alg_hold_top = rh_1759;
            }
            alg_root_top = rt_1758;
        }
        alg_root_top = rt_1757;
    }
    alg_hold_top = rh_1756;
    Value ret_127 = alg_nil();
    alg_root_top = rt_base;
    return ret_127;
}

static Value m_cemitter_boundnames_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1769 = alg_hold_top;
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    alg_hold_top = rh_1769;
    (void)((v_names = alg_hold(alg_list())));
    alg_hold_top = rh_1769;
    {
        int32_t rt_1770 = alg_root_top;
        Value loop_128 = alg_iterable(alg_hold(alg_property(v_thestmt, "Params")));
        (void)loop_128;
        alg_root(&loop_128, 1);
        for (int32_t at_128 = 0; at_128 < alg_iterable_count(loop_128); at_128++) {
            alg_safe_point();
            int32_t rt_1771 = alg_root_top;
            Value v_param = alg_iterable_at(loop_128, at_128);
            (void)v_param;
            alg_root(&v_param, 1);
            (void)(alg_hold(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_hold(alg_str(alg_hold(alg_property(v_param, "Lexeme"))))}, 2)));
            alg_root_top = rt_1771;
        }
        alg_root_top = rt_1770;
    }
    alg_hold_top = rh_1769;
    (void)(alg_hold(alg_invoke(v_this, "CollectBindings", (Value[]){alg_hold(alg_property(v_thestmt, "Body")), v_names}, 2)));
    alg_hold_top = rh_1769;
    Value ret_129 = v_names;
    alg_root_top = rt_base;
    return ret_129;
    alg_hold_top = rh_1769;
    Value ret_130 = alg_nil();
    alg_root_top = rt_base;
    return ret_130;
}

static Value m_cemitter_boxesfor_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_body = alg_widen(args[0], "List");
    (void)v_body;
    alg_root(&v_body, 1);
    int32_t rh_1772 = alg_hold_top;
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    alg_hold_top = rh_1772;
    (void)((v_names = alg_hold(alg_list())));
    alg_hold_top = rh_1772;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "DeclaresNested", (Value[]){v_body}, 1)))) {
        (void)(alg_hold(alg_invoke(v_this, "CollectBindings", (Value[]){v_body, v_names}, 2)));
    }
    alg_hold_top = rh_1772;
    Value ret_131 = v_names;
    alg_root_top = rt_base;
    return ret_131;
    alg_hold_top = rh_1772;
    Value ret_132 = alg_nil();
    alg_root_top = rt_base;
    return ret_132;
}

static Value m_cemitter_cell_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1773 = alg_hold_top;
    Value ret_133 = alg_hold(alg_invoke(v_this, "Mangle", (Value[]){alg_literal("c_"), v_name}, 2));
    alg_root_top = rt_base;
    return ret_133;
    alg_hold_top = rh_1773;
    Value ret_134 = alg_nil();
    alg_root_top = rt_base;
    return ret_134;
}

static Value m_cemitter_thisref_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1774 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){alg_literal("this")}, 1)))) {
        Value ret_135 = alg_hold(alg_invoke(v_this, "Read", (Value[]){alg_literal("this")}, 1));
        alg_root_top = rt_base;
        return ret_135;
    }
    alg_hold_top = rh_1774;
    Value ret_136 = alg_literal("v_this");
    alg_root_top = rt_base;
    return ret_136;
    alg_hold_top = rh_1774;
    Value ret_137 = alg_nil();
    alg_root_top = rt_base;
    return ret_137;
}

static Value m_cemitter_cellpointer_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1775 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_138 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("cells["), alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "Captured"), "Get", (Value[]){v_name}, 1)))))), alg_char_value(93)));
        alg_root_top = rt_base;
        return ret_138;
    }
    alg_hold_top = rh_1775;
    Value ret_139 = alg_hold(alg_invoke(v_this, "Cell", (Value[]){v_name}, 1));
    alg_root_top = rt_base;
    return ret_139;
    alg_hold_top = rh_1775;
    Value ret_140 = alg_nil();
    alg_root_top = rt_base;
    return ret_140;
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
    int32_t rh_1776 = alg_hold_top;
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    alg_hold_top = rh_1776;
    (void)((v_names = alg_hold(alg_invoke(v_given, "Keys", NULL, 0))));
    alg_hold_top = rh_1776;
    {
        int32_t rt_1777 = alg_root_top;
        Value loop_141 = alg_iterable(v_own);
        (void)loop_141;
        alg_root(&loop_141, 1);
        for (int32_t at_141 = 0; at_141 < alg_iterable_count(loop_141); at_141++) {
            alg_safe_point();
            int32_t rt_1778 = alg_root_top;
            Value v_each = alg_iterable_at(loop_141, at_141);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_hold(alg_invoke(v_this, "AddOnce", (Value[]){v_names, alg_hold(alg_str(v_each))}, 2)));
            alg_root_top = rt_1778;
        }
        alg_root_top = rt_1777;
    }
    alg_hold_top = rh_1776;
    Value ret_142 = v_names;
    alg_root_top = rt_base;
    return ret_142;
    alg_hold_top = rh_1776;
    Value ret_143 = alg_nil();
    alg_root_top = rt_base;
    return ret_143;
}

static Value m_cemitter_read_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1779 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_144 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(*cells["), alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "Captured"), "Get", (Value[]){v_name}, 1)))))), alg_literal("])")));
        alg_root_top = rt_base;
        return ret_144;
    }
    alg_hold_top = rh_1779;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_145 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(*"), alg_hold(alg_invoke(v_this, "Cell", (Value[]){v_name}, 1)))), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_145;
    }
    alg_hold_top = rh_1779;
    Value ret_146 = alg_hold(alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_hold(alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1))}, 2));
    alg_root_top = rt_base;
    return ret_146;
    alg_hold_top = rh_1779;
    Value ret_147 = alg_nil();
    alg_root_top = rt_base;
    return ret_147;
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
    int32_t rh_1780 = alg_hold_top;
    Value v_array = alg_nil();
    (void)v_array;
    alg_root(&v_array, 1);
    alg_hold_top = rh_1780;
    (void)((v_array = alg_literal("NULL, 0")));
    alg_hold_top = rh_1780;
    if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(v_cells, "Length")), alg_int(0))))) {
        {
            int32_t rt_1781 = alg_root_top;
            int32_t rh_1782 = alg_hold_top;
            Value v_joined = alg_literal("");
            (void)v_joined;
            alg_root(&v_joined, 1);
            alg_hold_top = rh_1782;
            {
                int32_t rt_1783 = alg_root_top;
                int32_t rh_1784 = alg_hold_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_1784;
                {
                    int32_t rh_1785 = alg_hold_top;
                    for (; (alg_hold_top = rh_1785, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_cells, "Length")))))); (alg_hold_top = rh_1785, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                        alg_safe_point();
                        {
                            int32_t rh_1786 = alg_hold_top;
                            if (alg_truthy(alg_hold(alg_greater(v_i, alg_int(0))))) {
                                (void)((v_joined = alg_hold(alg_add(v_joined, alg_literal(", ")))));
                            }
                            alg_hold_top = rh_1786;
                            (void)((v_joined = alg_hold(alg_add(v_joined, alg_hold(alg_invoke(v_this, "CellPointer", (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_cells, v_i))))}, 1))))));
                            alg_hold_top = rh_1786;
                        }
                    }
                }
                alg_hold_top = rh_1784;
                alg_root_top = rt_1783;
            }
            alg_hold_top = rh_1782;
            (void)((v_array = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("(Value*[]){"), v_joined)), alg_literal("}, "))), alg_hold(alg_str(alg_hold(alg_property(v_cells, "Length"))))))));
            alg_hold_top = rh_1782;
            alg_root_top = rt_1781;
        }
    }
    alg_hold_top = rh_1780;
    Value ret_148 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_closure("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1)))), alg_literal(", "))), v_array)), alg_literal(", "))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length")))))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "TypeTable", (Value[]){alg_hold(alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1)), alg_hold(alg_invoke(v_this, "ParameterTable", (Value[]){v_thestmt}, 1))}, 2)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_148;
    alg_hold_top = rh_1780;
    Value ret_149 = alg_nil();
    alg_root_top = rt_base;
    return ret_149;
}

static Value m_cemitter_containstry_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_1787 = alg_hold_top;
    {
        int32_t rt_1788 = alg_root_top;
        Value loop_150 = alg_iterable(v_statements);
        (void)loop_150;
        alg_root(&loop_150, 1);
        for (int32_t at_150 = 0; at_150 < alg_iterable_count(loop_150); at_150++) {
            alg_safe_point();
            int32_t rt_1789 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_150, at_150);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rh_1790 = alg_hold_top;
                if (alg_truthy(alg_is_class(v_thestmt, k_trystmt))) {
                    Value ret_151 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_151;
                }
                alg_hold_top = rh_1790;
                if (alg_truthy(alg_hold((or_33 = alg_is_class(v_thestmt, k_blockstmt), !alg_truthy(or_33) ? or_33 : alg_hold(alg_invoke(v_this, "ContainsTry", (Value[]){alg_hold(alg_property(v_thestmt, "Statements"))}, 1)))))) {
                    Value ret_152 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_152;
                }
                alg_hold_top = rh_1790;
                if (alg_truthy(alg_hold((or_34 = alg_is_class(v_thestmt, k_whilestmt), !alg_truthy(or_34) ? or_34 : alg_hold(alg_invoke(v_this, "ContainsTry", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "Body"))))}, 1)))))) {
                    Value ret_153 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_153;
                }
                alg_hold_top = rh_1790;
                if (alg_truthy(alg_hold((or_35 = alg_is_class(v_thestmt, k_forinstmt), !alg_truthy(or_35) ? or_35 : alg_hold(alg_invoke(v_this, "ContainsTry", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "Body"))))}, 1)))))) {
                    Value ret_154 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_154;
                }
                alg_hold_top = rh_1790;
                if (alg_truthy(alg_is_class(v_thestmt, k_ifstmt))) {
                    {
                        int32_t rh_1791 = alg_hold_top;
                        if (alg_truthy(alg_hold(alg_invoke(v_this, "ContainsTry", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "ThenBranch"))))}, 1)))) {
                            Value ret_155 = alg_bool(true);
                            alg_root_top = rt_base;
                            return ret_155;
                        }
                        alg_hold_top = rh_1791;
                        if (alg_truthy(alg_hold((or_36 = alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "ElseBranch")), alg_nil())), !alg_truthy(or_36) ? or_36 : alg_hold(alg_invoke(v_this, "ContainsTry", (Value[]){alg_hold(alg_list_keep(alg_list(), alg_hold(alg_property(v_thestmt, "ElseBranch"))))}, 1)))))) {
                            Value ret_156 = alg_bool(true);
                            alg_root_top = rt_base;
                            return ret_156;
                        }
                        alg_hold_top = rh_1791;
                    }
                }
                alg_hold_top = rh_1790;
            }
            alg_root_top = rt_1789;
        }
        alg_root_top = rt_1788;
    }
    alg_hold_top = rh_1787;
    Value ret_157 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_157;
    alg_hold_top = rh_1787;
    Value ret_158 = alg_nil();
    alg_root_top = rt_base;
    return ret_158;
}

static Value m_cemitter_local_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1792 = alg_hold_top;
    if (alg_truthy(alg_property(v_this, "Volatiles"))) {
        Value ret_159 = alg_literal("volatile Value ");
        alg_root_top = rt_base;
        return ret_159;
    }
    alg_hold_top = rh_1792;
    Value ret_160 = alg_literal("Value ");
    alg_root_top = rt_base;
    return ret_160;
    alg_hold_top = rh_1792;
    Value ret_161 = alg_nil();
    alg_root_top = rt_base;
    return ret_161;
}

static Value m_cemitter_requirecell_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1793 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Cells"), "Contains", (Value[]){v_name}, 1)))))) {
        (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("A capture of '"), v_name)), alg_char_value(39)))}, 1)));
    }
    alg_hold_top = rh_1793;
    Value ret_162 = alg_nil();
    alg_root_top = rt_base;
    return ret_162;
}

static Value m_cemitter_openscope_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1794 = alg_hold_top;
    Value ret_163 = alg_hold(alg_list_keep(alg_list_keep(alg_list(), alg_hold(alg_property(alg_property(v_this, "Cells"), "Length"))), alg_hold(alg_property(alg_property(v_this, "Locals"), "Length"))));
    alg_root_top = rt_base;
    return ret_163;
    alg_hold_top = rh_1794;
    Value ret_164 = alg_nil();
    alg_root_top = rt_base;
    return ret_164;
}

static Value m_cemitter_closescope_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_mark = alg_widen(args[0], "List");
    (void)v_mark;
    alg_root(&v_mark, 1);
    int32_t rh_1795 = alg_hold_top;
    {
        int32_t rh_1796 = alg_hold_top;
        while ((alg_hold_top = rh_1796, alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(alg_property(v_this, "Cells"), "Length")), alg_hold(alg_subscript_get(v_mark, alg_int(0)))))))) {
            alg_safe_point();
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Cells"), "RemoveAt", (Value[]){alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "Cells"), "Length")), alg_int(1)))}, 1)));
        }
    }
    alg_hold_top = rh_1795;
    {
        int32_t rh_1797 = alg_hold_top;
        while ((alg_hold_top = rh_1797, alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(alg_property(v_this, "Locals"), "Length")), alg_hold(alg_subscript_get(v_mark, alg_int(1)))))))) {
            alg_safe_point();
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "RemoveAt", (Value[]){alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "Locals"), "Length")), alg_int(1)))}, 1)));
        }
    }
    alg_hold_top = rh_1795;
    Value ret_165 = alg_nil();
    alg_root_top = rt_base;
    return ret_165;
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
    int32_t rh_1798 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_root("), v_slots)), alg_literal(", "))), v_count)), alg_literal(");")))}, 1)));
    alg_hold_top = rh_1798;
    Value ret_166 = alg_nil();
    alg_root_top = rt_base;
    return ret_166;
}

static Value m_cemitter_emitsafepoint_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1799 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_literal("alg_safe_point();")}, 1)));
    alg_hold_top = rh_1799;
    Value ret_167 = alg_nil();
    alg_root_top = rt_base;
    return ret_167;
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
    int32_t rh_1800 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(v_this, "Local", NULL, 0)), v_symbol)), alg_literal(" = "))), v_initial)), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_1800;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("(void)"), v_symbol)), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_1800;
    (void)(alg_hold(alg_invoke(v_this, "Root", (Value[]){alg_hold(alg_add(alg_char_value(38), v_symbol)), alg_char_value(49)}, 2)));
    alg_hold_top = rh_1800;
    Value ret_168 = alg_nil();
    alg_root_top = rt_base;
    return ret_168;
}

static Value m_cemitter_emitreturn_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_value = alg_widen(args[0], "String");
    (void)v_value;
    alg_root(&v_value, 1);
    int32_t rh_1801 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "FrameRoots"), alg_literal(""))))) {
        {
            int32_t rh_1802 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("return "), v_value)), alg_char_value(59)))}, 1)));
            alg_hold_top = rh_1802;
            Value ret_169 = alg_nil();
            alg_root_top = rt_base;
            return ret_169;
            alg_hold_top = rh_1802;
        }
    }
    alg_hold_top = rh_1801;
    Value v_slot = alg_hold(alg_add(alg_literal("ret_"), alg_hold(alg_str(alg_property(v_this, "Loops")))));
    (void)v_slot;
    alg_root(&v_slot, 1);
    alg_hold_top = rh_1801;
    (void)(alg_set_property(v_this, "Loops", alg_hold(alg_add(alg_property(v_this, "Loops"), alg_int(1)))));
    alg_hold_top = rh_1801;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(v_this, "Local", NULL, 0)), v_slot)), alg_literal(" = "))), v_value)), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_1801;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_root_top = "), alg_property(v_this, "FrameRoots"))), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_1801;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("return "), v_slot)), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_1801;
    Value ret_170 = alg_nil();
    alg_root_top = rt_base;
    return ret_170;
}

static Value m_cemitter_openroots_1_boolean(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_declares = alg_widen(args[0], "Boolean");
    (void)v_declares;
    alg_root(&v_declares, 1);
    int32_t rh_1803 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(v_declares)))) {
        Value ret_171 = alg_literal("");
        alg_root_top = rt_base;
        return ret_171;
    }
    alg_hold_top = rh_1803;
    Value v_mark = alg_hold(alg_add(alg_literal("rt_"), alg_hold(alg_str(alg_property(v_this, "RootMarks")))));
    (void)v_mark;
    alg_root(&v_mark, 1);
    alg_hold_top = rh_1803;
    (void)(alg_set_property(v_this, "RootMarks", alg_hold(alg_add(alg_property(v_this, "RootMarks"), alg_int(1)))));
    alg_hold_top = rh_1803;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("int32_t "), v_mark)), alg_literal(" = alg_root_top;")))}, 1)));
    alg_hold_top = rh_1803;
    Value ret_172 = v_mark;
    alg_root_top = rt_base;
    return ret_172;
    alg_hold_top = rh_1803;
    Value ret_173 = alg_nil();
    alg_root_top = rt_base;
    return ret_173;
}

static Value m_cemitter_closeroots_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_mark = alg_widen(args[0], "String");
    (void)v_mark;
    alg_root(&v_mark, 1);
    int32_t rh_1804 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(v_mark, alg_literal(""))))) {
        Value ret_174 = alg_nil();
        alg_root_top = rt_base;
        return ret_174;
    }
    alg_hold_top = rh_1804;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_root_top = "), v_mark)), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_1804;
    Value ret_175 = alg_nil();
    alg_root_top = rt_base;
    return ret_175;
}

static Value m_cemitter_openholds_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1805 = alg_hold_top;
    Value v_mark = alg_hold(alg_add(alg_literal("rh_"), alg_hold(alg_str(alg_property(v_this, "RootMarks")))));
    (void)v_mark;
    alg_root(&v_mark, 1);
    alg_hold_top = rh_1805;
    (void)(alg_set_property(v_this, "RootMarks", alg_hold(alg_add(alg_property(v_this, "RootMarks"), alg_int(1)))));
    alg_hold_top = rh_1805;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("int32_t "), v_mark)), alg_literal(" = alg_hold_top;")))}, 1)));
    alg_hold_top = rh_1805;
    Value ret_176 = v_mark;
    alg_root_top = rt_base;
    return ret_176;
    alg_hold_top = rh_1805;
    Value ret_177 = alg_nil();
    alg_root_top = rt_base;
    return ret_177;
}

static Value m_cemitter_executeheld_2_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    Value v_mark = alg_widen(args[1], "String");
    (void)v_mark;
    alg_root(&v_mark, 1);
    int32_t rh_1806 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){v_thestmt}, 1)));
    alg_hold_top = rh_1806;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_hold_top = "), v_mark)), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_1806;
    Value ret_178 = alg_nil();
    alg_root_top = rt_base;
    return ret_178;
}

static Value m_cemitter_voidcall_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_text = alg_widen(args[0], "String");
    (void)v_text;
    alg_root(&v_text, 1);
    int32_t rh_1807 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_pos(v_text, alg_literal("alg_writeln("))), alg_int(0))))) {
        Value ret_179 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_179;
    }
    alg_hold_top = rh_1807;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_pos(v_text, alg_literal("alg_writeln_blank("))), alg_int(0))))) {
        Value ret_180 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_180;
    }
    alg_hold_top = rh_1807;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_pos(v_text, alg_literal("alg_write("))), alg_int(0))))) {
        Value ret_181 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_181;
    }
    alg_hold_top = rh_1807;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_pos(v_text, alg_literal("alg_stderr_line("))), alg_int(0))))) {
        Value ret_182 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_182;
    }
    alg_hold_top = rh_1807;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_pos(v_text, alg_literal("alg_halt("))), alg_int(0))))) {
        Value ret_183 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_183;
    }
    alg_hold_top = rh_1807;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_pos(v_text, alg_literal("alg_assert_true("))), alg_int(0))))) {
        Value ret_184 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_184;
    }
    alg_hold_top = rh_1807;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_pos(v_text, alg_literal("alg_assert_equal("))), alg_int(0))))) {
        Value ret_185 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_185;
    }
    alg_hold_top = rh_1807;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_pos(v_text, alg_literal("alg_assert_fail("))), alg_int(0))))) {
        Value ret_186 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_186;
    }
    alg_hold_top = rh_1807;
    Value ret_187 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_187;
    alg_hold_top = rh_1807;
    Value ret_188 = alg_nil();
    alg_root_top = rt_base;
    return ret_188;
}

static Value m_cemitter_needshold_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = args[0];
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1808 = alg_hold_top;
    Value ret_189 = alg_hold(alg_not((alg_hold((or_41 = alg_hold((or_40 = alg_hold((or_39 = alg_hold((or_38 = alg_hold((or_37 = alg_is_class(v_theexpr, k_literalexpr), alg_truthy(or_37) ? or_37 : alg_is_class(v_theexpr, k_variableexpr))), alg_truthy(or_38) ? or_38 : alg_is_class(v_theexpr, k_thisexpr))), alg_truthy(or_39) ? or_39 : alg_is_class(v_theexpr, k_isexpr))), alg_truthy(or_40) ? or_40 : alg_is_class(v_theexpr, k_groupingexpr))), alg_truthy(or_41) ? or_41 : alg_is_class(v_theexpr, k_assignexpr))))));
    alg_root_top = rt_base;
    return ret_189;
    alg_hold_top = rh_1808;
    Value ret_190 = alg_nil();
    alg_root_top = rt_base;
    return ret_190;
}

static Value m_cemitter_declareslocal_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_1809 = alg_hold_top;
    {
        int32_t rt_1810 = alg_root_top;
        Value loop_191 = alg_iterable(v_statements);
        (void)loop_191;
        alg_root(&loop_191, 1);
        for (int32_t at_191 = 0; at_191 < alg_iterable_count(loop_191); at_191++) {
            alg_safe_point();
            int32_t rt_1811 = alg_root_top;
            Value v_each = alg_iterable_at(loop_191, at_191);
            (void)v_each;
            alg_root(&v_each, 1);
            {
                int32_t rh_1812 = alg_hold_top;
                if (alg_truthy(alg_hold((or_42 = alg_is_class(v_each, k_varstmt), alg_truthy(or_42) ? or_42 : alg_is_class(v_each, k_vargroupstmt))))) {
                    Value ret_192 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_192;
                }
                alg_hold_top = rh_1812;
                if (alg_truthy(alg_is_class(v_each, k_functionstmt))) {
                    Value ret_193 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_193;
                }
                alg_hold_top = rh_1812;
                if (alg_truthy(alg_hold((or_43 = alg_is_class(v_each, k_labelstmt), !alg_truthy(or_43) ? or_43 : alg_hold(alg_not_equal(alg_hold(alg_property(v_each, "Inner")), alg_nil())))))) {
                    if (alg_truthy(alg_hold((or_44 = alg_is_class(alg_hold(alg_property(v_each, "Inner")), k_varstmt), alg_truthy(or_44) ? or_44 : alg_is_class(alg_hold(alg_property(v_each, "Inner")), k_vargroupstmt))))) {
                        Value ret_194 = alg_bool(true);
                        alg_root_top = rt_base;
                        return ret_194;
                    }
                }
                alg_hold_top = rh_1812;
            }
            alg_root_top = rt_1811;
        }
        alg_root_top = rt_1810;
    }
    alg_hold_top = rh_1809;
    Value ret_195 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_195;
    alg_hold_top = rh_1809;
    Value ret_196 = alg_nil();
    alg_root_top = rt_base;
    return ret_196;
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
    int32_t rh_1813 = alg_hold_top;
    Value v_qualifier = alg_nil();
    (void)v_qualifier;
    alg_root(&v_qualifier, 1);
    alg_hold_top = rh_1813;
    (void)((v_qualifier = alg_literal("")));
    alg_hold_top = rh_1813;
    if (alg_truthy(alg_property(v_this, "Volatiles"))) {
        (void)((v_qualifier = alg_literal("volatile ")));
    }
    alg_hold_top = rh_1813;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Value *"), v_qualifier)), alg_hold(alg_invoke(v_this, "Cell", (Value[]){v_name}, 1)))), alg_literal(" = alg_cell("))), v_initial)), alg_literal(");")))}, 1)));
    alg_hold_top = rh_1813;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("(void)"), alg_hold(alg_invoke(v_this, "Cell", (Value[]){v_name}, 1)))), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_1813;
    (void)(alg_hold(alg_invoke(v_this, "Root", (Value[]){alg_hold(alg_invoke(v_this, "Cell", (Value[]){v_name}, 1)), alg_char_value(49)}, 2)));
    alg_hold_top = rh_1813;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Cells"), "Add", (Value[]){v_name}, 1)));
    alg_hold_top = rh_1813;
    Value ret_197 = alg_nil();
    alg_root_top = rt_base;
    return ret_197;
}

static Value m_cemitter_hoistcells_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_1814 = alg_hold_top;
    {
        int32_t rt_1815 = alg_root_top;
        Value loop_198 = alg_iterable(v_statements);
        (void)loop_198;
        alg_root(&loop_198, 1);
        for (int32_t at_198 = 0; at_198 < alg_iterable_count(loop_198); at_198++) {
            alg_safe_point();
            int32_t rt_1816 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_198, at_198);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rh_1817 = alg_hold_top;
                if (alg_truthy(alg_hold((or_45 = alg_is_class(v_thestmt, k_varstmt), !alg_truthy(or_45) ? or_45 : alg_hold(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)))))) {
                    {
                        int32_t rh_1818 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                        alg_hold_top = rh_1818;
                        (void)(alg_hold(alg_invoke(v_this, "DeclareCell", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), alg_literal("alg_nil()")}, 2)));
                        alg_hold_top = rh_1818;
                    }
                }
                alg_hold_top = rh_1817;
                if (alg_truthy(alg_is_class(v_thestmt, k_vargroupstmt))) {
                    {
                        int32_t rt_1819 = alg_root_top;
                        Value loop_199 = alg_iterable(alg_hold(alg_property(v_thestmt, "Names")));
                        (void)loop_199;
                        alg_root(&loop_199, 1);
                        for (int32_t at_199 = 0; at_199 < alg_iterable_count(loop_199); at_199++) {
                            alg_safe_point();
                            int32_t rt_1820 = alg_root_top;
                            Value v_thename = alg_iterable_at(loop_199, at_199);
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme"))))}, 1)))) {
                                {
                                    int32_t rh_1821 = alg_hold_top;
                                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme"))))}, 1)));
                                    alg_hold_top = rh_1821;
                                    (void)(alg_hold(alg_invoke(v_this, "DeclareCell", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme")))), alg_literal("alg_nil()")}, 2)));
                                    alg_hold_top = rh_1821;
                                }
                            }
                            alg_root_top = rt_1820;
                        }
                        alg_root_top = rt_1819;
                    }
                }
                alg_hold_top = rh_1817;
            }
            alg_root_top = rt_1816;
        }
        alg_root_top = rt_1815;
    }
    alg_hold_top = rh_1814;
    Value ret_200 = alg_nil();
    alg_root_top = rt_base;
    return ret_200;
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
    int32_t rh_1822 = alg_hold_top;
    Value v_mark = alg_hold(alg_invoke(v_this, "OpenScope", NULL, 0));
    (void)v_mark;
    alg_root(&v_mark, 1);
    alg_hold_top = rh_1822;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1)));
    alg_hold_top = rh_1822;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_1822;
    Value v_roots = alg_hold(alg_invoke(v_this, "OpenRoots", (Value[]){alg_bool(true)}, 1));
    (void)v_roots;
    alg_root(&v_roots, 1);
    alg_hold_top = rh_1822;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_handler, "Name"))))}, 1)));
    alg_hold_top = rh_1822;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_handler, "Name"))))}, 1)))) {
        (void)(alg_hold(alg_invoke(v_this, "DeclareCell", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_handler, "Name")))), alg_hold(alg_add(v_frame, alg_literal(".raised")))}, 2)));
    } else {
        {
            int32_t rh_1823 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_hold(alg_invoke(v_this, "VariableName", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_handler, "Name"))))}, 1)), alg_hold(alg_add(v_frame, alg_literal(".raised")))}, 2)));
            alg_hold_top = rh_1823;
        }
    }
    alg_hold_top = rh_1822;
    (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_handler, "Body"))}, 1)));
    alg_hold_top = rh_1822;
    (void)(alg_hold(alg_invoke(v_this, "CloseRoots", (Value[]){v_roots}, 1)));
    alg_hold_top = rh_1822;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_1822;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1)));
    alg_hold_top = rh_1822;
    (void)(alg_hold(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1)));
    alg_hold_top = rh_1822;
    Value ret_201 = alg_nil();
    alg_root_top = rt_base;
    return ret_201;
}

static Value m_cemitter_declaredtypes_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_themethod = args[0];
    (void)v_themethod;
    alg_root(&v_themethod, 1);
    int32_t rh_1824 = alg_hold_top;
    Value v_types = alg_nil();
    (void)v_types;
    alg_root(&v_types, 1);
    alg_hold_top = rh_1824;
    (void)((v_types = alg_hold(alg_list())));
    alg_hold_top = rh_1824;
    {
        int32_t rt_1825 = alg_root_top;
        int32_t rh_1826 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1826;
        {
            int32_t rh_1827 = alg_hold_top;
            for (; (alg_hold_top = rh_1827, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_themethod, "Params")), "Length")))))); (alg_hold_top = rh_1827, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1828 = alg_root_top;
                    int32_t rh_1829 = alg_hold_top;
                    Value v_declared = alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(v_themethod, "ParamTypes")), v_i))));
                    (void)v_declared;
                    alg_root(&v_declared, 1);
                    alg_hold_top = rh_1829;
                    if (alg_truthy(alg_hold(alg_equal(v_declared, alg_literal(""))))) {
                        (void)((v_declared = alg_literal("Any")));
                    }
                    alg_hold_top = rh_1829;
                    (void)(alg_hold(alg_invoke(v_types, "Add", (Value[]){v_declared}, 1)));
                    alg_hold_top = rh_1829;
                    alg_root_top = rt_1828;
                }
            }
        }
        alg_hold_top = rh_1826;
        alg_root_top = rt_1825;
    }
    alg_hold_top = rh_1824;
    Value ret_202 = v_types;
    alg_root_top = rt_base;
    return ret_202;
    alg_hold_top = rh_1824;
    Value ret_203 = alg_nil();
    alg_root_top = rt_base;
    return ret_203;
}

static Value m_cemitter_parametertable_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_themethod = args[0];
    (void)v_themethod;
    alg_root(&v_themethod, 1);
    int32_t rh_1830 = alg_hold_top;
    Value v_written = alg_nil();
    (void)v_written;
    alg_root(&v_written, 1);
    alg_hold_top = rh_1830;
    (void)((v_written = alg_hold(alg_list())));
    alg_hold_top = rh_1830;
    {
        int32_t rt_1831 = alg_root_top;
        int32_t rh_1832 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1832;
        {
            int32_t rh_1833 = alg_hold_top;
            for (; (alg_hold_top = rh_1833, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_themethod, "Params")), "Length")))))); (alg_hold_top = rh_1833, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1834 = alg_root_top;
                    int32_t rh_1835 = alg_hold_top;
                    Value v_declared = alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(v_themethod, "ParamTypes")), v_i))));
                    (void)v_declared;
                    alg_root(&v_declared, 1);
                    alg_hold_top = rh_1835;
                    if (alg_truthy(alg_hold(alg_equal(v_declared, alg_literal(""))))) {
                        (void)((v_declared = alg_literal("Any")));
                    }
                    alg_hold_top = rh_1835;
                    if (alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_themethod, "ParamGenerics")), "Length")))))) {
                        {
                            int32_t rt_1836 = alg_root_top;
                            int32_t rh_1837 = alg_hold_top;
                            Value v_element = alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(v_themethod, "ParamGenerics")), v_i))));
                            (void)v_element;
                            alg_root(&v_element, 1);
                            alg_hold_top = rh_1837;
                            if (alg_truthy(alg_hold(alg_not_equal(v_element, alg_literal(""))))) {
                                (void)((v_declared = alg_hold(alg_add(alg_hold(alg_add(v_declared, alg_literal(" of "))), v_element))));
                            }
                            alg_hold_top = rh_1837;
                            alg_root_top = rt_1836;
                        }
                    }
                    alg_hold_top = rh_1835;
                    (void)(alg_hold(alg_invoke(v_written, "Add", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_subscript_get(alg_hold(alg_property(v_themethod, "Params")), v_i)), "Lexeme")))), alg_literal(" : "))), v_declared))}, 1)));
                    alg_hold_top = rh_1835;
                    alg_root_top = rt_1834;
                }
            }
        }
        alg_hold_top = rh_1832;
        alg_root_top = rt_1831;
    }
    alg_hold_top = rh_1830;
    Value ret_204 = v_written;
    alg_root_top = rt_base;
    return ret_204;
    alg_hold_top = rh_1830;
    Value ret_205 = alg_nil();
    alg_root_top = rt_base;
    return ret_205;
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
    int32_t rh_1838 = alg_hold_top;
    {
        int32_t rt_1839 = alg_root_top;
        Value loop_206 = alg_iterable(v_statements);
        (void)loop_206;
        alg_root(&loop_206, 1);
        for (int32_t at_206 = 0; at_206 < alg_iterable_count(loop_206); at_206++) {
            alg_safe_point();
            int32_t rt_1840 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_206, at_206);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rt_1841 = alg_root_top;
                int32_t rh_1842 = alg_hold_top;
                Value v_named = alg_hold((or_49 = alg_hold((or_48 = alg_hold((or_47 = alg_hold((or_46 = alg_is_class(v_thestmt, k_functionstmt), alg_truthy(or_46) ? or_46 : alg_is_class(v_thestmt, k_classstmt))), alg_truthy(or_47) ? or_47 : alg_is_class(v_thestmt, k_objectstmt))), alg_truthy(or_48) ? or_48 : alg_is_class(v_thestmt, k_varstmt))), alg_truthy(or_49) ? or_49 : alg_is_class(v_thestmt, k_enumstmt)));
                (void)v_named;
                alg_root(&v_named, 1);
                alg_hold_top = rh_1842;
                if (alg_truthy(alg_hold(alg_not(v_named)))) {
                    continue;
                }
                alg_hold_top = rh_1842;
                Value v_thename = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))));
                (void)v_thename;
                alg_root(&v_thename, 1);
                alg_hold_top = rh_1842;
                Value v_privateQ = alg_bool(false);
                (void)v_privateQ;
                alg_root(&v_privateQ, 1);
                alg_hold_top = rh_1842;
                {
                    int32_t rt_1843 = alg_root_top;
                    Value loop_207 = alg_iterable(v_hidden);
                    (void)loop_207;
                    alg_root(&loop_207, 1);
                    for (int32_t at_207 = 0; at_207 < alg_iterable_count(loop_207); at_207++) {
                        alg_safe_point();
                        int32_t rt_1844 = alg_root_top;
                        Value v_each = alg_iterable_at(loop_207, at_207);
                        (void)v_each;
                        alg_root(&v_each, 1);
                        if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(v_each))}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_thename}, 1)))))) {
                            (void)((v_privateQ = alg_bool(true)));
                        }
                        alg_root_top = rt_1844;
                    }
                    alg_root_top = rt_1843;
                }
                alg_hold_top = rh_1842;
                if (alg_truthy(v_privateQ)) {
                    continue;
                }
                alg_hold_top = rh_1842;
                if (alg_truthy(alg_hold(alg_not((alg_is_class(v_thestmt, k_functionstmt)))))) {
                    {
                        int32_t rh_1845 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "ShadowWhole"), "Add", (Value[]){v_thename}, 1)));
                        alg_hold_top = rh_1845;
                        continue;
                        alg_hold_top = rh_1845;
                    }
                }
                alg_hold_top = rh_1842;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1)))) {
                    continue;
                }
                alg_hold_top = rh_1842;
                if (alg_truthy(alg_hold(alg_invoke(v_this, "Variadic", (Value[]){v_thestmt}, 1)))) {
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "ShadowArities"), "Add", (Value[]){alg_hold(alg_add(alg_hold(alg_add(v_thename, alg_literal("/~"))), alg_hold(alg_str(alg_hold(alg_subtract(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length")), alg_int(1)))))))}, 1)));
                } else {
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "ShadowArities"), "Add", (Value[]){alg_hold(alg_add(alg_hold(alg_add(v_thename, alg_char_value(47))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length"))))))}, 1)));
                }
                alg_hold_top = rh_1842;
                alg_root_top = rt_1841;
            }
            alg_root_top = rt_1840;
        }
        alg_root_top = rt_1839;
    }
    alg_hold_top = rh_1838;
    Value ret_208 = alg_nil();
    alg_root_top = rt_base;
    return ret_208;
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
    int32_t rh_1846 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "ShadowNames"), "Contains", (Value[]){v_name}, 1)))))) {
        Value ret_209 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_209;
    }
    alg_hold_top = rh_1846;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "ShadowWhole"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_210 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_210;
    }
    alg_hold_top = rh_1846;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "ShadowArities"), "Contains", (Value[]){alg_hold(alg_add(alg_hold(alg_add(v_name, alg_char_value(47))), alg_hold(alg_str(v_count))))}, 1)))) {
        Value ret_211 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_211;
    }
    alg_hold_top = rh_1846;
    {
        int32_t rt_1847 = alg_root_top;
        int32_t rh_1848 = alg_hold_top;
        Value v_fixed = alg_int(0);
        (void)v_fixed;
        alg_root(&v_fixed, 1);
        alg_hold_top = rh_1848;
        {
            int32_t rh_1849 = alg_hold_top;
            for (; (alg_hold_top = rh_1849, alg_truthy(alg_hold(alg_less_equal(v_fixed, v_count)))); (alg_hold_top = rh_1849, (v_fixed = alg_hold(alg_add(v_fixed, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "ShadowArities"), "Contains", (Value[]){alg_hold(alg_add(alg_hold(alg_add(v_name, alg_literal("/~"))), alg_hold(alg_str(v_fixed))))}, 1)))) {
                    Value ret_212 = alg_bool(true);
                    alg_root_top = rt_base;
                    return ret_212;
                }
            }
        }
        alg_hold_top = rh_1848;
        alg_root_top = rt_1847;
    }
    alg_hold_top = rh_1846;
    Value ret_213 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_213;
    alg_hold_top = rh_1846;
    Value ret_214 = alg_nil();
    alg_root_top = rt_base;
    return ret_214;
}

static Value m_cemitter_variadic_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1850 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length")), alg_int(0))))) {
        Value ret_215 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_215;
    }
    alg_hold_top = rh_1850;
    Value v_last = alg_hold(alg_subtract(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length")), alg_int(1)));
    (void)v_last;
    alg_root(&v_last, 1);
    alg_hold_top = rh_1850;
    if (alg_truthy(alg_hold(alg_greater_equal(v_last, alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "ParamTypes")), "Length")))))) {
        Value ret_216 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_216;
    }
    alg_hold_top = rh_1850;
    if (alg_truthy(alg_hold(alg_greater_equal(v_last, alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "ParamGenerics")), "Length")))))) {
        Value ret_217 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_217;
    }
    alg_hold_top = rh_1850;
    Value ret_218 = alg_hold((or_50 = alg_hold(alg_equal(alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_thestmt, "ParamTypes")), v_last))}, 1)), alg_literal("List"))), !alg_truthy(or_50) ? or_50 : alg_hold(alg_not_equal(alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(v_thestmt, "ParamGenerics")), v_last)))), alg_literal("")))));
    alg_root_top = rt_base;
    return ret_218;
    alg_hold_top = rh_1850;
    Value ret_219 = alg_nil();
    alg_root_top = rt_base;
    return ret_219;
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
    int32_t rh_1851 = alg_hold_top;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    alg_hold_top = rh_1851;
    (void)((v_symbol = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("m_"), alg_hold(alg_invoke(v_this, "Escaped", (Value[]){v_owner}, 1)))), alg_char_value(95))), alg_hold(alg_invoke(v_this, "Escaped", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_themethod, "Name")), "Lexeme"))))}, 1)))), alg_char_value(95))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_themethod, "Params")), "Length"))))))));
    alg_hold_top = rh_1851;
    Value v_types = alg_hold(alg_invoke(v_this, "DeclaredTypes", (Value[]){v_themethod}, 1));
    (void)v_types;
    alg_root(&v_types, 1);
    alg_hold_top = rh_1851;
    {
        int32_t rt_1852 = alg_root_top;
        Value loop_220 = alg_iterable(v_types);
        (void)loop_220;
        alg_root(&loop_220, 1);
        for (int32_t at_220 = 0; at_220 < alg_iterable_count(loop_220); at_220++) {
            alg_safe_point();
            int32_t rt_1853 = alg_root_top;
            Value v_thetype = alg_iterable_at(loop_220, at_220);
            (void)v_thetype;
            alg_root(&v_thetype, 1);
            if (alg_truthy(alg_hold(alg_not_equal(v_thetype, alg_literal("Any"))))) {
                (void)((v_symbol = alg_hold(alg_add(alg_hold(alg_add(v_symbol, alg_char_value(95))), alg_hold(alg_invoke(v_this, "Escaped", (Value[]){alg_hold(alg_str(v_thetype))}, 1))))));
            }
            alg_root_top = rt_1853;
        }
        alg_root_top = rt_1852;
    }
    alg_hold_top = rh_1851;
    Value ret_221 = v_symbol;
    alg_root_top = rt_base;
    return ret_221;
    alg_hold_top = rh_1851;
    Value ret_222 = alg_nil();
    alg_root_top = rt_base;
    return ret_222;
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
    int32_t rh_1854 = alg_hold_top;
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    alg_hold_top = rh_1854;
    Value v_at = alg_nil();
    (void)v_at;
    alg_root(&v_at, 1);
    alg_hold_top = rh_1854;
    (void)((v_names = alg_hold(alg_set())));
    alg_hold_top = rh_1854;
    {
        int32_t rt_1855 = alg_root_top;
        Value loop_223 = alg_iterable(v_own);
        (void)loop_223;
        alg_root(&loop_223, 1);
        for (int32_t at_223 = 0; at_223 < alg_iterable_count(loop_223); at_223++) {
            alg_safe_point();
            int32_t rt_1856 = alg_root_top;
            Value v_each = alg_iterable_at(loop_223, at_223);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_each, "Name")), "Lexeme"))}, 1))}, 1)));
            alg_root_top = rt_1856;
        }
        alg_root_top = rt_1855;
    }
    alg_hold_top = rh_1854;
    (void)((v_at = v_supername));
    alg_hold_top = rh_1854;
    {
        int32_t rh_1857 = alg_hold_top;
        while ((alg_hold_top = rh_1857, alg_truthy(alg_hold(alg_not_equal(v_at, alg_literal("")))))) {
            alg_safe_point();
            {
                int32_t rt_1858 = alg_root_top;
                int32_t rh_1859 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_at}, 1))}, 1)))))) {
                    Value ret_224 = v_names;
                    alg_root_top = rt_base;
                    return ret_224;
                }
                alg_hold_top = rh_1859;
                Value v_ancestor = alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_at}, 1))}, 1));
                (void)v_ancestor;
                alg_root(&v_ancestor, 1);
                alg_hold_top = rh_1859;
                Value v_inherited = alg_hold(alg_property(v_ancestor, "Methods"));
                (void)v_inherited;
                alg_root(&v_inherited, 1);
                alg_hold_top = rh_1859;
                if (alg_truthy(v_fields)) {
                    (void)((v_inherited = alg_hold(alg_property(v_ancestor, "Fields"))));
                }
                alg_hold_top = rh_1859;
                {
                    int32_t rt_1860 = alg_root_top;
                    Value loop_225 = alg_iterable(v_inherited);
                    (void)loop_225;
                    alg_root(&loop_225, 1);
                    for (int32_t at_225 = 0; at_225 < alg_iterable_count(loop_225); at_225++) {
                        alg_safe_point();
                        int32_t rt_1861 = alg_root_top;
                        Value v_item = alg_iterable_at(loop_225, at_225);
                        (void)v_item;
                        alg_root(&v_item, 1);
                        (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_item, "Name")), "Lexeme"))}, 1))}, 1)));
                        alg_root_top = rt_1861;
                    }
                    alg_root_top = rt_1860;
                }
                alg_hold_top = rh_1859;
                (void)((v_at = alg_literal("")));
                alg_hold_top = rh_1859;
                if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_ancestor, "Superclass")), alg_nil())))) {
                    (void)((v_at = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_ancestor, "Superclass")), "Name")), "Lexeme"))))));
                }
                alg_hold_top = rh_1859;
                alg_root_top = rt_1858;
            }
        }
    }
    alg_hold_top = rh_1854;
    Value ret_226 = v_names;
    alg_root_top = rt_base;
    return ret_226;
    alg_hold_top = rh_1854;
    Value ret_227 = alg_nil();
    alg_root_top = rt_base;
    return ret_227;
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
    int32_t rh_1862 = alg_hold_top;
    Value v_enclosinglocals = alg_nil();
    (void)v_enclosinglocals;
    alg_root(&v_enclosinglocals, 1);
    alg_hold_top = rh_1862;
    Value v_enclosingtop = alg_nil();
    (void)v_enclosingtop;
    alg_root(&v_enclosingtop, 1);
    alg_hold_top = rh_1862;
    Value v_enclosingdepth = alg_nil();
    (void)v_enclosingdepth;
    alg_root(&v_enclosingdepth, 1);
    alg_hold_top = rh_1862;
    Value v_opening = alg_nil();
    (void)v_opening;
    alg_root(&v_opening, 1);
    alg_hold_top = rh_1862;
    (void)((v_enclosinglocals = alg_property(v_this, "Locals")));
    alg_hold_top = rh_1862;
    (void)((v_enclosingtop = alg_property(v_this, "AtTopLevel")));
    alg_hold_top = rh_1862;
    (void)((v_enclosingdepth = alg_property(v_this, "Depth")));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Locals", alg_hold(alg_list())));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
    alg_hold_top = rh_1862;
    Value v_enclosingtarget = alg_property(v_this, "Target");
    (void)v_enclosingtarget;
    alg_root(&v_enclosingtarget, 1);
    alg_hold_top = rh_1862;
    Value v_enclosingbody = alg_property(v_this, "Body");
    (void)v_enclosingbody;
    alg_root(&v_enclosingbody, 1);
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Target", alg_literal("body")));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Body", alg_hold(alg_buffer(alg_int(0)))));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Depth", alg_int(1)));
    alg_hold_top = rh_1862;
    Value v_enclosingvolatiles = alg_property(v_this, "Volatiles");
    (void)v_enclosingvolatiles;
    alg_root(&v_enclosingvolatiles, 1);
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Volatiles", alg_hold(alg_invoke(v_this, "ContainsTry", (Value[]){alg_hold(alg_property(v_themethod, "Body"))}, 1))));
    alg_hold_top = rh_1862;
    Value v_enclosingframeroots = alg_property(v_this, "FrameRoots");
    (void)v_enclosingframeroots;
    alg_root(&v_enclosingframeroots, 1);
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "FrameRoots", alg_literal("rt_base")));
    alg_hold_top = rh_1862;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("int32_t "), alg_property(v_this, "FrameRoots"))), alg_literal(" = alg_root_top;")))}, 1)));
    alg_hold_top = rh_1862;
    (void)(alg_hold(alg_invoke(v_this, "Root", (Value[]){alg_literal("&v_this"), alg_char_value(49)}, 2)));
    alg_hold_top = rh_1862;
    (void)(alg_hold(alg_invoke(v_this, "Root", (Value[]){alg_literal("args"), alg_literal("count")}, 2)));
    alg_hold_top = rh_1862;
    Value v_enclosingboxed = alg_property(v_this, "Boxed");
    (void)v_enclosingboxed;
    alg_root(&v_enclosingboxed, 1);
    alg_hold_top = rh_1862;
    Value v_enclosingcaptured = alg_property(v_this, "Captured");
    (void)v_enclosingcaptured;
    alg_root(&v_enclosingcaptured, 1);
    alg_hold_top = rh_1862;
    Value v_enclosingcells = alg_property(v_this, "Cells");
    (void)v_enclosingcells;
    alg_root(&v_enclosingcells, 1);
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Boxed", alg_hold(alg_list())));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Captured", alg_hold(alg_map())));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Cells", alg_hold(alg_list())));
    alg_hold_top = rh_1862;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_hold(alg_property(v_themethod, "Body"))}, 1)))) {
        {
            int32_t rh_1863 = alg_hold_top;
            (void)(alg_set_property(v_this, "Boxed", alg_hold(alg_invoke(v_this, "BoundNames", (Value[]){v_themethod}, 1))));
            alg_hold_top = rh_1863;
            (void)(alg_hold(alg_invoke(v_this, "AddOnce", (Value[]){alg_property(v_this, "Boxed"), alg_literal("this")}, 2)));
            alg_hold_top = rh_1863;
            (void)(alg_hold(alg_invoke(v_this, "DeclareCell", (Value[]){alg_literal("this"), alg_literal("v_this")}, 2)));
            alg_hold_top = rh_1863;
        }
    }
    alg_hold_top = rh_1862;
    Value v_enclosingtrydepth = alg_property(v_this, "TryDepth");
    (void)v_enclosingtrydepth;
    alg_root(&v_enclosingtrydepth, 1);
    alg_hold_top = rh_1862;
    Value v_enclosinglooptry = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosinglooptry;
    alg_root(&v_enclosinglooptry, 1);
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "TryDepth", alg_int(0)));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_int(0)));
    alg_hold_top = rh_1862;
    {
        int32_t rt_1864 = alg_root_top;
        int32_t rh_1865 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1865;
        {
            int32_t rh_1866 = alg_hold_top;
            for (; (alg_hold_top = rh_1866, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_themethod, "Params")), "Length")))))); (alg_hold_top = rh_1866, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1867 = alg_root_top;
                    int32_t rh_1868 = alg_hold_top;
                    Value v_name = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_subscript_get(alg_hold(alg_property(v_themethod, "Params")), v_i)), "Lexeme"))));
                    (void)v_name;
                    alg_root(&v_name, 1);
                    alg_hold_top = rh_1868;
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_name}, 1)));
                    alg_hold_top = rh_1868;
                    Value v_slot = alg_hold(alg_add(alg_hold(alg_add(alg_literal("args["), alg_hold(alg_str(v_i)))), alg_char_value(93)));
                    (void)v_slot;
                    alg_root(&v_slot, 1);
                    alg_hold_top = rh_1868;
                    if (alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_themethod, "ParamTypes")), "Length")))))) {
                        {
                            int32_t rt_1869 = alg_root_top;
                            int32_t rh_1870 = alg_hold_top;
                            Value v_declared = alg_hold(alg_str(alg_hold(alg_subscript_get(alg_hold(alg_property(v_themethod, "ParamTypes")), v_i))));
                            (void)v_declared;
                            alg_root(&v_declared, 1);
                            alg_hold_top = rh_1870;
                            if (alg_truthy(alg_hold((or_51 = alg_hold(alg_not_equal(v_declared, alg_literal(""))), !alg_truthy(or_51) ? or_51 : alg_hold(alg_not_equal(v_declared, alg_literal("Any"))))))) {
                                (void)((v_slot = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_widen("), v_slot)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){v_declared}, 1)))), alg_char_value(41)))));
                            }
                            alg_hold_top = rh_1870;
                            alg_root_top = rt_1869;
                        }
                    }
                    alg_hold_top = rh_1868;
                    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1)))) {
                        (void)(alg_hold(alg_invoke(v_this, "DeclareCell", (Value[]){v_name, v_slot}, 2)));
                    } else {
                        {
                            int32_t rh_1871 = alg_hold_top;
                            (void)(alg_hold(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_hold(alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), v_slot}, 2)));
                            alg_hold_top = rh_1871;
                        }
                    }
                    alg_hold_top = rh_1868;
                    alg_root_top = rt_1867;
                }
            }
        }
        alg_hold_top = rh_1865;
        alg_root_top = rt_1864;
    }
    alg_hold_top = rh_1862;
    (void)(alg_hold(alg_invoke(v_this, "HoistCells", (Value[]){alg_hold(alg_property(v_themethod, "Body"))}, 1)));
    alg_hold_top = rh_1862;
    (void)(alg_hold(alg_invoke(v_this, "PushLabels", (Value[]){alg_hold(alg_property(v_themethod, "Body"))}, 1)));
    alg_hold_top = rh_1862;
    Value v_holds = alg_hold(alg_invoke(v_this, "OpenHolds", NULL, 0));
    (void)v_holds;
    alg_root(&v_holds, 1);
    alg_hold_top = rh_1862;
    {
        int32_t rt_1872 = alg_root_top;
        Value loop_228 = alg_iterable(alg_hold(alg_property(v_themethod, "Body")));
        (void)loop_228;
        alg_root(&loop_228, 1);
        for (int32_t at_228 = 0; at_228 < alg_iterable_count(loop_228); at_228++) {
            alg_safe_point();
            int32_t rt_1873 = alg_root_top;
            Value v_each = alg_iterable_at(loop_228, at_228);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_hold(alg_invoke(v_this, "ExecuteHeld", (Value[]){v_each, v_holds}, 2)));
            alg_root_top = rt_1873;
        }
        alg_root_top = rt_1872;
    }
    alg_hold_top = rh_1862;
    (void)(alg_hold(alg_invoke(v_this, "PopLabels", NULL, 0)));
    alg_hold_top = rh_1862;
    (void)(alg_hold(alg_invoke(v_this, "EmitReturn", (Value[]){alg_literal("alg_nil()")}, 1)));
    alg_hold_top = rh_1862;
    Value v_written = alg_hold(alg_property(alg_property(v_this, "Body"), "Text"));
    (void)v_written;
    alg_root(&v_written, 1);
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Target", v_enclosingtarget));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Body", v_enclosingbody));
    alg_hold_top = rh_1862;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static Value "), alg_hold(alg_invoke(v_this, "MethodSymbol", (Value[]){v_owner, v_themethod}, 2)))), alg_literal("(Value v_this, Value *args, int32_t count) {"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1862;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    (void)v_this; (void)args; (void)count;"), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1862;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_written}, 1)));
    alg_hold_top = rh_1862;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_char_value(125), alg_char_value(10))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Depth", v_enclosingdepth));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "AtTopLevel", v_enclosingtop));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Locals", v_enclosinglocals));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Volatiles", v_enclosingvolatiles));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Boxed", v_enclosingboxed));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Captured", v_enclosingcaptured));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "Cells", v_enclosingcells));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "TryDepth", v_enclosingtrydepth));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "LoopTryDepth", v_enclosinglooptry));
    alg_hold_top = rh_1862;
    (void)(alg_set_property(v_this, "FrameRoots", v_enclosingframeroots));
    alg_hold_top = rh_1862;
    Value ret_229 = alg_nil();
    alg_root_top = rt_base;
    return ret_229;
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
    int32_t rh_1874 = alg_hold_top;
    Value v_handle = alg_nil();
    (void)v_handle;
    alg_root(&v_handle, 1);
    alg_hold_top = rh_1874;
    Value v_supername = alg_nil();
    (void)v_supername;
    alg_root(&v_supername, 1);
    alg_hold_top = rh_1874;
    Value v_applied = alg_nil();
    (void)v_applied;
    alg_root(&v_applied, 1);
    alg_hold_top = rh_1874;
    Value v_initializer = alg_nil();
    (void)v_initializer;
    alg_root(&v_initializer, 1);
    alg_hold_top = rh_1874;
    Value v_enclosingclass = alg_nil();
    (void)v_enclosingclass;
    alg_root(&v_enclosingclass, 1);
    alg_hold_top = rh_1874;
    Value v_enclosingfields = alg_nil();
    (void)v_enclosingfields;
    alg_root(&v_enclosingfields, 1);
    alg_hold_top = rh_1874;
    Value v_enclosingmethods = alg_nil();
    (void)v_enclosingmethods;
    alg_root(&v_enclosingmethods, 1);
    alg_hold_top = rh_1874;
    (void)((v_handle = alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1))));
    alg_hold_top = rh_1874;
    (void)(alg_hold(alg_invoke(v_this, "DeclareValue", (Value[]){v_handle, v_name}, 2)));
    alg_hold_top = rh_1874;
    (void)((v_enclosingclass = alg_property(v_this, "CurrentClass")));
    alg_hold_top = rh_1874;
    (void)((v_enclosingfields = alg_property(v_this, "VisibleFields")));
    alg_hold_top = rh_1874;
    (void)((v_enclosingmethods = alg_property(v_this, "VisibleMethods")));
    alg_hold_top = rh_1874;
    (void)((v_supername = alg_literal("")));
    alg_hold_top = rh_1874;
    if (alg_truthy(alg_hold(alg_not_equal(v_superclass, alg_nil())))) {
        (void)((v_supername = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_superclass, "Name")), "Lexeme"))))));
    }
    alg_hold_top = rh_1874;
    (void)(alg_set_property(v_this, "CurrentClass", v_name));
    alg_hold_top = rh_1874;
    (void)(alg_set_property(v_this, "VisibleFields", alg_hold(alg_invoke(v_this, "NamesVisible", (Value[]){v_supername, v_fields, alg_bool(true)}, 3))));
    alg_hold_top = rh_1874;
    (void)(alg_set_property(v_this, "VisibleMethods", alg_hold(alg_invoke(v_this, "NamesVisible", (Value[]){v_supername, v_methods, alg_bool(false)}, 3))));
    alg_hold_top = rh_1874;
    Value v_declaresid = alg_bool(false);
    (void)v_declaresid;
    alg_root(&v_declaresid, 1);
    alg_hold_top = rh_1874;
    {
        int32_t rt_1875 = alg_root_top;
        Value loop_230 = alg_iterable(v_fields);
        (void)loop_230;
        alg_root(&loop_230, 1);
        for (int32_t at_230 = 0; at_230 < alg_iterable_count(loop_230); at_230++) {
            alg_safe_point();
            int32_t rt_1876 = alg_root_top;
            Value v_field = alg_iterable_at(loop_230, at_230);
            (void)v_field;
            alg_root(&v_field, 1);
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_field, "Name")), "Lexeme")))), alg_literal("Id"))))) {
                (void)((v_declaresid = alg_bool(true)));
            }
            alg_root_top = rt_1876;
        }
        alg_root_top = rt_1875;
    }
    alg_hold_top = rh_1874;
    Value v_addid = alg_hold((or_52 = v_isobject, !alg_truthy(or_52) ? or_52 : alg_hold(alg_not(v_declaresid))));
    (void)v_addid;
    alg_root(&v_addid, 1);
    alg_hold_top = rh_1874;
    if (alg_truthy(v_addid)) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "VisibleFields"), "Add", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_literal("Id")}, 1))}, 1)));
    }
    alg_hold_top = rh_1874;
    (void)((v_applied = alg_literal("")));
    alg_hold_top = rh_1874;
    {
        int32_t rt_1877 = alg_root_top;
        Value loop_231 = alg_iterable(v_fields);
        (void)loop_231;
        alg_root(&loop_231, 1);
        for (int32_t at_231 = 0; at_231 < alg_iterable_count(loop_231); at_231++) {
            alg_safe_point();
            int32_t rt_1878 = alg_root_top;
            Value v_thefield = alg_iterable_at(loop_231, at_231);
            (void)v_thefield;
            alg_root(&v_thefield, 1);
            {
                int32_t rt_1879 = alg_root_top;
                int32_t rh_1880 = alg_hold_top;
                Value v_value = alg_literal("alg_nil()");
                (void)v_value;
                alg_root(&v_value, 1);
                alg_hold_top = rh_1880;
                if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thefield, "Initializer")), alg_nil())))) {
                    {
                        int32_t rh_1881 = alg_hold_top;
                        (void)((v_value = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thefield, "Initializer"))}, 1))));
                        alg_hold_top = rh_1881;
                        (void)((v_value = alg_hold(alg_invoke(v_this, "BoundValue", (Value[]){alg_hold(alg_property(v_thefield, "TypeName")), v_value, alg_literal("")}, 3))));
                        alg_hold_top = rh_1881;
                    }
                }
                alg_hold_top = rh_1880;
                (void)((v_applied = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_applied, alg_literal("    alg_set_property(v_this, "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thefield, "Name")), "Lexeme"))))}, 1)))), alg_literal(", "))), v_value)), alg_literal(");"))), alg_char_value(10)))));
                alg_hold_top = rh_1880;
                alg_root_top = rt_1879;
            }
            alg_root_top = rt_1878;
        }
        alg_root_top = rt_1877;
    }
    alg_hold_top = rh_1874;
    if (alg_truthy(v_addid)) {
        (void)((v_applied = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_applied, alg_literal("    alg_set_property(v_this, \"Id\", alg_literal("))), alg_hold(f_quotec(NULL, (Value[]){v_name}, 1)))), alg_literal("));"))), alg_char_value(10)))));
    }
    alg_hold_top = rh_1874;
    (void)((v_initializer = alg_hold(alg_invoke(v_this, "InitName", (Value[]){v_name}, 1))));
    alg_hold_top = rh_1874;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static Value "), v_initializer)), alg_literal("(Value v_this, Value *args, int32_t count) {"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1874;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    (void)v_this; (void)args; (void)count;"), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1874;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    int32_t rt_base = alg_root_top;"), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1874;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    alg_root(&v_this, 1);"), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1874;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_applied}, 1)));
    alg_hold_top = rh_1874;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    alg_root_top = rt_base;"), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1874;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    return alg_nil();"), alg_char_value(10))), alg_char_value(125))), alg_char_value(10))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1874;
    {
        int32_t rt_1882 = alg_root_top;
        Value loop_232 = alg_iterable(v_methods);
        (void)loop_232;
        alg_root(&loop_232, 1);
        for (int32_t at_232 = 0; at_232 < alg_iterable_count(loop_232); at_232++) {
            alg_safe_point();
            int32_t rt_1883 = alg_root_top;
            Value v_method = alg_iterable_at(loop_232, at_232);
            (void)v_method;
            alg_root(&v_method, 1);
            (void)(alg_hold(alg_invoke(v_this, "EmitMethod", (Value[]){v_name, v_method}, 2)));
            alg_root_top = rt_1883;
        }
        alg_root_top = rt_1882;
    }
    alg_hold_top = rh_1874;
    (void)(alg_set_property(v_this, "CurrentClass", v_enclosingclass));
    alg_hold_top = rh_1874;
    (void)(alg_set_property(v_this, "VisibleFields", v_enclosingfields));
    alg_hold_top = rh_1874;
    (void)(alg_set_property(v_this, "VisibleMethods", v_enclosingmethods));
    alg_hold_top = rh_1874;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Shells"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    "), v_handle)), alg_literal(" = alg_class("))), alg_hold(f_quotec(NULL, (Value[]){v_name}, 1)))), alg_literal(", alg_nil());"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1874;
    Value v_hoisted = alg_hold((or_53 = alg_hold(alg_equal(v_supername, alg_literal(""))), alg_truthy(or_53) ? or_53 : alg_hold(alg_invoke(alg_property(v_this, "OwnClasses"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_supername}, 1))}, 1))));
    (void)v_hoisted;
    alg_root(&v_hoisted, 1);
    alg_hold_top = rh_1874;
    if (alg_truthy(alg_hold(alg_not_equal(v_supername, alg_literal(""))))) {
        {
            int32_t rh_1884 = alg_hold_top;
            if (alg_truthy(alg_hold((or_54 = alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_supername}, 1))}, 1)))), !alg_truthy(or_54) ? or_54 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_supername}, 1))}, 1)))))))) {
                alg_raise(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), v_supername)), alg_literal("' is not a class."))));
            }
            alg_hold_top = rh_1884;
            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_supername}, 1))}, 1)))) {
                (void)((v_supername = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_supername}, 1))}, 1)), "Name")), "Lexeme"))))));
            }
            alg_hold_top = rh_1884;
            if (alg_truthy(alg_hold(alg_not(v_hoisted)))) {
                (void)(alg_hold(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_class_declared("), alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){v_supername}, 1)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){v_supername}, 1)))), alg_literal(");")))}, 2)));
            }
            alg_hold_top = rh_1884;
            (void)(alg_hold(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_class_super("), v_handle)), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){v_supername}, 1)))), alg_literal(");")))}, 2)));
            alg_hold_top = rh_1884;
        }
    }
    alg_hold_top = rh_1874;
    {
        int32_t rt_1885 = alg_root_top;
        Value loop_233 = alg_iterable(v_fields);
        (void)loop_233;
        alg_root(&loop_233, 1);
        for (int32_t at_233 = 0; at_233 < alg_iterable_count(loop_233); at_233++) {
            alg_safe_point();
            int32_t rt_1886 = alg_root_top;
            Value v_eachfield = alg_iterable_at(loop_233, at_233);
            (void)v_eachfield;
            alg_root(&v_eachfield, 1);
            (void)(alg_hold(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_class_field("), v_handle)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_eachfield, "Name")), "Lexeme"))))}, 1)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_eachfield, "TypeName"))))}, 1))}, 1)))), alg_literal(");")))}, 2)));
            alg_root_top = rt_1886;
        }
        alg_root_top = rt_1885;
    }
    alg_hold_top = rh_1874;
    if (alg_truthy(v_addid)) {
        (void)(alg_hold(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_class_field("), v_handle)), alg_literal(", \"Id\", \"String\");")))}, 2)));
    }
    alg_hold_top = rh_1874;
    (void)(alg_hold(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_class_initializer("), v_handle)), alg_literal(", "))), v_initializer)), alg_literal(");")))}, 2)));
    alg_hold_top = rh_1874;
    {
        int32_t rt_1887 = alg_root_top;
        Value loop_234 = alg_iterable(v_methods);
        (void)loop_234;
        alg_root(&loop_234, 1);
        for (int32_t at_234 = 0; at_234 < alg_iterable_count(loop_234); at_234++) {
            alg_safe_point();
            int32_t rt_1888 = alg_root_top;
            Value v_themethod = alg_iterable_at(loop_234, at_234);
            (void)v_themethod;
            alg_root(&v_themethod, 1);
            {
                int32_t rt_1889 = alg_root_top;
                int32_t rh_1890 = alg_hold_top;
                Value v_types = alg_hold(alg_invoke(v_this, "ParameterTable", (Value[]){v_themethod}, 1));
                (void)v_types;
                alg_root(&v_types, 1);
                alg_hold_top = rh_1890;
                Value v_table = alg_literal("NULL");
                (void)v_table;
                alg_root(&v_table, 1);
                alg_hold_top = rh_1890;
                if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(v_types, "Length")), alg_int(0))))) {
                    {
                        int32_t rt_1891 = alg_root_top;
                        int32_t rh_1892 = alg_hold_top;
                        (void)((v_table = alg_hold(alg_add(alg_literal("t_"), alg_hold(alg_copy(alg_hold(alg_invoke(v_this, "MethodSymbol", (Value[]){v_name, v_themethod}, 2)), alg_int(2), alg_hold(alg_subtract(alg_hold(alg_text_length(alg_hold(alg_invoke(v_this, "MethodSymbol", (Value[]){v_name, v_themethod}, 2)))), alg_int(2)))))))));
                        alg_hold_top = rh_1892;
                        Value v_quoted = alg_literal("");
                        (void)v_quoted;
                        alg_root(&v_quoted, 1);
                        alg_hold_top = rh_1892;
                        {
                            int32_t rt_1893 = alg_root_top;
                            int32_t rh_1894 = alg_hold_top;
                            Value v_j = alg_int(0);
                            (void)v_j;
                            alg_root(&v_j, 1);
                            alg_hold_top = rh_1894;
                            {
                                int32_t rh_1895 = alg_hold_top;
                                for (; (alg_hold_top = rh_1895, alg_truthy(alg_hold(alg_less(v_j, alg_hold(alg_property(v_types, "Length")))))); (alg_hold_top = rh_1895, (v_j = alg_hold(alg_add(v_j, alg_int(1)))))) {
                                    alg_safe_point();
                                    {
                                        int32_t rh_1896 = alg_hold_top;
                                        if (alg_truthy(alg_hold(alg_greater(v_j, alg_int(0))))) {
                                            (void)((v_quoted = alg_hold(alg_add(v_quoted, alg_literal(", ")))));
                                        }
                                        alg_hold_top = rh_1896;
                                        (void)((v_quoted = alg_hold(alg_add(v_quoted, alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_types, v_j))))}, 1))))));
                                        alg_hold_top = rh_1896;
                                    }
                                }
                            }
                            alg_hold_top = rh_1894;
                            alg_root_top = rt_1893;
                        }
                        alg_hold_top = rh_1892;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static const char *"), v_table)), alg_literal("[] = { "))), v_quoted)), alg_literal(" };"))), alg_char_value(10)))}, 1)));
                        alg_hold_top = rh_1892;
                        alg_root_top = rt_1891;
                    }
                }
                alg_hold_top = rh_1890;
                if (alg_truthy(alg_hold(alg_property(v_themethod, "IsProperty")))) {
                    (void)(alg_hold(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_class_property("), v_handle)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_themethod, "Name")), "Lexeme"))))}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "MethodSymbol", (Value[]){v_name, v_themethod}, 2)))), alg_literal(");")))}, 2)));
                } else {
                    (void)(alg_hold(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_class_method("), v_handle)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_themethod, "Name")), "Lexeme"))))}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "MethodSymbol", (Value[]){v_name, v_themethod}, 2)))), alg_literal(", "))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_themethod, "Params")), "Length")))))), alg_literal(", "))), v_table)), alg_literal(");")))}, 2)));
                }
                alg_hold_top = rh_1890;
                alg_root_top = rt_1889;
            }
            alg_root_top = rt_1888;
        }
        alg_root_top = rt_1887;
    }
    alg_hold_top = rh_1874;
    if (alg_truthy(v_isobject)) {
        (void)(alg_hold(alg_invoke(v_this, "Built", (Value[]){v_hoisted, alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_class_is_object("), v_handle)), alg_literal(");")))}, 2)));
    }
    alg_hold_top = rh_1874;
    Value ret_235 = alg_nil();
    alg_root_top = rt_base;
    return ret_235;
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
    int32_t rh_1897 = alg_hold_top;
    if (alg_truthy(v_hoisted)) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("    "), v_text)), alg_char_value(10)))}, 1)));
    } else {
        (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){v_text}, 1)));
    }
    alg_hold_top = rh_1897;
    Value ret_236 = alg_nil();
    alg_root_top = rt_base;
    return ret_236;
}

static Value m_cemitter_visitvarstmt_1_varstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "VarStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1898 = alg_hold_top;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_1898;
    (void)((v_value = alg_literal("alg_nil()")));
    alg_hold_top = rh_1898;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Initializer")), alg_nil())))) {
        {
            int32_t rh_1899 = alg_hold_top;
            (void)((v_value = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Initializer"))}, 1))));
            alg_hold_top = rh_1899;
            (void)((v_value = alg_hold(alg_invoke(v_this, "BoundValue", (Value[]){alg_hold(alg_property(v_thestmt, "TypeName")), v_value, alg_hold(alg_property(v_thestmt, "Actual"))}, 3))));
            alg_hold_top = rh_1899;
        }
    }
    alg_hold_top = rh_1898;
    if (alg_truthy(alg_property(v_this, "AtTopLevel"))) {
        {
            int32_t rh_1900 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "DeclareVariable", (Value[]){alg_hold(alg_invoke(v_this, "VariableName", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 2)));
            alg_hold_top = rh_1900;
            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(v_this, "VariableName", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)), alg_literal(" = "))), v_value)), alg_char_value(59)))}, 1)));
            alg_hold_top = rh_1900;
            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_invoke(v_this, "DeclaredFlag", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)), alg_literal(" = true;")))}, 1)));
            alg_hold_top = rh_1900;
        }
    } else {
        if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)))) {
            {
                int32_t rh_1901 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_this, "RequireCell", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                alg_hold_top = rh_1901;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                alg_hold_top = rh_1901;
                (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(42), alg_hold(alg_invoke(v_this, "Cell", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)))), alg_literal(" = "))), v_value)), alg_char_value(59)))}, 1)));
                alg_hold_top = rh_1901;
            }
        } else {
            {
                int32_t rh_1902 = alg_hold_top;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                alg_hold_top = rh_1902;
                (void)(alg_hold(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_hold(alg_invoke(v_this, "VariableName", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)), v_value}, 2)));
                alg_hold_top = rh_1902;
            }
        }
    }
    alg_hold_top = rh_1898;
    Value ret_237 = alg_nil();
    alg_root_top = rt_base;
    return ret_237;
}

static Value m_cemitter_visitexpressionstmt_1_expressionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ExpressionStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1903 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("(void)("), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Expression"))}, 1)))), alg_literal(");")))}, 1)));
    alg_hold_top = rh_1903;
    Value ret_238 = alg_nil();
    alg_root_top = rt_base;
    return ret_238;
}

static Value m_cemitter_pushlabels_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_statements = alg_widen(args[0], "List");
    (void)v_statements;
    alg_root(&v_statements, 1);
    int32_t rh_1904 = alg_hold_top;
    Value v_here = alg_nil();
    (void)v_here;
    alg_root(&v_here, 1);
    alg_hold_top = rh_1904;
    (void)((v_here = alg_hold(alg_map())));
    alg_hold_top = rh_1904;
    {
        int32_t rt_1905 = alg_root_top;
        Value loop_239 = alg_iterable(v_statements);
        (void)loop_239;
        alg_root(&loop_239, 1);
        for (int32_t at_239 = 0; at_239 < alg_iterable_count(loop_239); at_239++) {
            alg_safe_point();
            int32_t rt_1906 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_239, at_239);
            (void)v_statement;
            alg_root(&v_statement, 1);
            if (alg_truthy(alg_is_class(v_statement, k_labelstmt))) {
                (void)(alg_hold(alg_invoke(v_here, "Put", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_statement, "Name")), "Lexeme"))))}, 1)), alg_property(v_this, "TryDepth")}, 2)));
            }
            alg_root_top = rt_1906;
        }
        alg_root_top = rt_1905;
    }
    alg_hold_top = rh_1904;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LabelDepths"), "Add", (Value[]){v_here}, 1)));
    alg_hold_top = rh_1904;
    Value ret_240 = alg_nil();
    alg_root_top = rt_base;
    return ret_240;
}

static Value m_cemitter_poplabels_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_1907 = alg_hold_top;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LabelDepths"), "RemoveAt", (Value[]){alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "LabelDepths"), "Length")), alg_int(1)))}, 1)));
    alg_hold_top = rh_1907;
    Value ret_241 = alg_nil();
    alg_root_top = rt_base;
    return ret_241;
}

static Value m_cemitter_depthoflabel_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    int32_t rh_1908 = alg_hold_top;
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    alg_hold_top = rh_1908;
    (void)((v_folded = alg_hold(f_foldcase(NULL, (Value[]){v_thelabel}, 1))));
    alg_hold_top = rh_1908;
    {
        int32_t rt_1909 = alg_root_top;
        int32_t rh_1910 = alg_hold_top;
        Value v_s = alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "LabelDepths"), "Length")), alg_int(1)));
        (void)v_s;
        alg_root(&v_s, 1);
        alg_hold_top = rh_1910;
        {
            int32_t rh_1911 = alg_hold_top;
            for (; (alg_hold_top = rh_1911, alg_truthy(alg_hold(alg_greater_equal(v_s, alg_int(0))))); (alg_hold_top = rh_1911, (v_s = alg_hold(alg_subtract(v_s, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold(alg_invoke(alg_hold(alg_subscript_get(alg_property(v_this, "LabelDepths"), v_s)), "Contains", (Value[]){v_folded}, 1)))) {
                    Value ret_242 = alg_hold(alg_cast_kind(alg_invoke(alg_hold(alg_subscript_get(alg_property(v_this, "LabelDepths"), v_s)), "Get", (Value[]){v_folded}, 1), ALG_KIND_INTEGER, "Integer"));
                    alg_root_top = rt_base;
                    return ret_242;
                }
            }
        }
        alg_hold_top = rh_1910;
        alg_root_top = rt_1909;
    }
    alg_hold_top = rh_1908;
    Value ret_243 = alg_property(v_this, "TryDepth");
    alg_root_top = rt_base;
    return ret_243;
    alg_hold_top = rh_1908;
    Value ret_244 = alg_nil();
    alg_root_top = rt_base;
    return ret_244;
}

static Value m_cemitter_gototarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    int32_t rh_1912 = alg_hold_top;
    Value ret_245 = alg_hold(alg_add(alg_literal("lg_"), alg_hold(alg_invoke(v_this, "Escaped", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_thelabel}, 1))}, 1))));
    alg_root_top = rt_base;
    return ret_245;
    alg_hold_top = rh_1912;
    Value ret_246 = alg_nil();
    alg_root_top = rt_base;
    return ret_246;
}

static Value m_cemitter_visitgotostmt_1_gotostmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "GotoStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1913 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_hold(alg_invoke(v_this, "DepthOfLabel", (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1))}, 1)));
    alg_hold_top = rh_1913;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("goto "), alg_hold(alg_invoke(v_this, "GotoTarget", (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1)))), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_1913;
    Value ret_247 = alg_nil();
    alg_root_top = rt_base;
    return ret_247;
}

static Value m_cemitter_visitblockstmt_1_blockstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "BlockStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1914 = alg_hold_top;
    Value v_mark = alg_hold(alg_invoke(v_this, "OpenScope", NULL, 0));
    (void)v_mark;
    alg_root(&v_mark, 1);
    alg_hold_top = rh_1914;
    Value v_enclosingtop = alg_property(v_this, "AtTopLevel");
    (void)v_enclosingtop;
    alg_root(&v_enclosingtop, 1);
    alg_hold_top = rh_1914;
    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
    alg_hold_top = rh_1914;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1)));
    alg_hold_top = rh_1914;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_1914;
    Value v_roots = alg_hold(alg_invoke(v_this, "OpenRoots", (Value[]){alg_hold(alg_invoke(v_this, "DeclaresLocal", (Value[]){alg_hold(alg_property(v_thestmt, "Statements"))}, 1))}, 1));
    (void)v_roots;
    alg_root(&v_roots, 1);
    alg_hold_top = rh_1914;
    (void)(alg_hold(alg_invoke(v_this, "HoistCells", (Value[]){alg_hold(alg_property(v_thestmt, "Statements"))}, 1)));
    alg_hold_top = rh_1914;
    (void)(alg_hold(alg_invoke(v_this, "PushLabels", (Value[]){alg_hold(alg_property(v_thestmt, "Statements"))}, 1)));
    alg_hold_top = rh_1914;
    Value v_holds = alg_hold(alg_invoke(v_this, "OpenHolds", NULL, 0));
    (void)v_holds;
    alg_root(&v_holds, 1);
    alg_hold_top = rh_1914;
    {
        int32_t rt_1915 = alg_root_top;
        Value loop_248 = alg_iterable(alg_hold(alg_property(v_thestmt, "Statements")));
        (void)loop_248;
        alg_root(&loop_248, 1);
        for (int32_t at_248 = 0; at_248 < alg_iterable_count(loop_248); at_248++) {
            alg_safe_point();
            int32_t rt_1916 = alg_root_top;
            Value v_statement = alg_iterable_at(loop_248, at_248);
            (void)v_statement;
            alg_root(&v_statement, 1);
            (void)(alg_hold(alg_invoke(v_this, "ExecuteHeld", (Value[]){v_statement, v_holds}, 2)));
            alg_root_top = rt_1916;
        }
        alg_root_top = rt_1915;
    }
    alg_hold_top = rh_1914;
    (void)(alg_hold(alg_invoke(v_this, "PopLabels", NULL, 0)));
    alg_hold_top = rh_1914;
    (void)(alg_hold(alg_invoke(v_this, "CloseRoots", (Value[]){v_roots}, 1)));
    alg_hold_top = rh_1914;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_1914;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1)));
    alg_hold_top = rh_1914;
    (void)(alg_set_property(v_this, "AtTopLevel", v_enclosingtop));
    alg_hold_top = rh_1914;
    (void)(alg_hold(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1)));
    alg_hold_top = rh_1914;
    Value ret_249 = alg_nil();
    alg_root_top = rt_base;
    return ret_249;
}

static Value m_cemitter_visitifstmt_1_ifstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "IfStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1917 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_hold(alg_property(v_thestmt, "ThenBranch"))}, 1)));
    alg_hold_top = rh_1917;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "ElseBranch")), alg_nil())))) {
        (void)(alg_hold(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_hold(alg_property(v_thestmt, "ElseBranch"))}, 1)));
    }
    alg_hold_top = rh_1917;
    Value v_mark = alg_hold(alg_invoke(v_this, "OpenScope", NULL, 0));
    (void)v_mark;
    alg_root(&v_mark, 1);
    alg_hold_top = rh_1917;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("if (alg_truthy("), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Condition"))}, 1)))), alg_literal(")) {")))}, 1)));
    alg_hold_top = rh_1917;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_1917;
    (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_thestmt, "ThenBranch"))}, 1)));
    alg_hold_top = rh_1917;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_1917;
    (void)(alg_hold(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1)));
    alg_hold_top = rh_1917;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "ElseBranch")), alg_nil())))) {
        {
            int32_t rh_1918 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_literal("} else {")}, 1)));
            alg_hold_top = rh_1918;
            (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
            alg_hold_top = rh_1918;
            (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_thestmt, "ElseBranch"))}, 1)));
            alg_hold_top = rh_1918;
            (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
            alg_hold_top = rh_1918;
            (void)(alg_hold(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1)));
            alg_hold_top = rh_1918;
        }
    }
    alg_hold_top = rh_1917;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1)));
    alg_hold_top = rh_1917;
    Value ret_250 = alg_nil();
    alg_root_top = rt_base;
    return ret_250;
}

static Value m_cemitter_visitwhilestmt_1_whilestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "WhileStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1919 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1)));
    alg_hold_top = rh_1919;
    Value v_mark = alg_hold(alg_invoke(v_this, "OpenScope", NULL, 0));
    (void)v_mark;
    alg_root(&v_mark, 1);
    alg_hold_top = rh_1919;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1)));
    alg_hold_top = rh_1919;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_1919;
    Value v_holds = alg_hold(alg_invoke(v_this, "OpenHolds", NULL, 0));
    (void)v_holds;
    alg_root(&v_holds, 1);
    alg_hold_top = rh_1919;
    Value v_reset = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_hold_top = "), v_holds)), alg_literal(", ")));
    (void)v_reset;
    alg_root(&v_reset, 1);
    alg_hold_top = rh_1919;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Increment")), alg_nil())))) {
        (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("for (; "), v_reset)), alg_literal("alg_truthy("))), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Condition"))}, 1)))), alg_literal(")); "))), v_reset)), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Increment"))}, 1)))), alg_literal(")) {")))}, 1)));
    } else {
        (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("while ("), v_reset)), alg_literal("alg_truthy("))), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Condition"))}, 1)))), alg_literal("))) {")))}, 1)));
    }
    alg_hold_top = rh_1919;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_1919;
    (void)(alg_hold(alg_invoke(v_this, "EmitSafePoint", NULL, 0)));
    alg_hold_top = rh_1919;
    Value v_enclosingloopdepth = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosingloopdepth;
    alg_root(&v_enclosingloopdepth, 1);
    alg_hold_top = rh_1919;
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_property(v_this, "TryDepth")));
    alg_hold_top = rh_1919;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LoopLabels"), "Add", (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1)));
    alg_hold_top = rh_1919;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LoopDepths"), "Add", (Value[]){alg_property(v_this, "TryDepth")}, 1)));
    alg_hold_top = rh_1919;
    (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1)));
    alg_hold_top = rh_1919;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LoopLabels"), "RemoveAt", (Value[]){alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "LoopLabels"), "Length")), alg_int(1)))}, 1)));
    alg_hold_top = rh_1919;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LoopDepths"), "RemoveAt", (Value[]){alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "LoopDepths"), "Length")), alg_int(1)))}, 1)));
    alg_hold_top = rh_1919;
    (void)(alg_set_property(v_this, "LoopTryDepth", v_enclosingloopdepth));
    alg_hold_top = rh_1919;
    (void)(alg_hold(alg_invoke(v_this, "EmitContinueTarget", (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1)));
    alg_hold_top = rh_1919;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_1919;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1)));
    alg_hold_top = rh_1919;
    (void)(alg_hold(alg_invoke(v_this, "EmitBreakTarget", (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1)));
    alg_hold_top = rh_1919;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_1919;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1)));
    alg_hold_top = rh_1919;
    (void)(alg_hold(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1)));
    alg_hold_top = rh_1919;
    Value ret_251 = alg_nil();
    alg_root_top = rt_base;
    return ret_251;
}

static Value m_cemitter_emitcontinuetarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    int32_t rh_1920 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(v_thelabel, alg_literal(""))))) {
        Value ret_252 = alg_nil();
        alg_root_top = rt_base;
        return ret_252;
    }
    alg_hold_top = rh_1920;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Jumped"), "Contains", (Value[]){alg_hold(alg_invoke(v_this, "ContinueTarget", (Value[]){v_thelabel}, 1))}, 1)))))) {
        Value ret_253 = alg_nil();
        alg_root_top = rt_base;
        return ret_253;
    }
    alg_hold_top = rh_1920;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_invoke(v_this, "ContinueTarget", (Value[]){v_thelabel}, 1)), alg_literal(": ;")))}, 1)));
    alg_hold_top = rh_1920;
    Value ret_254 = alg_nil();
    alg_root_top = rt_base;
    return ret_254;
}

static Value m_cemitter_emitbreaktarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    int32_t rh_1921 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(v_thelabel, alg_literal(""))))) {
        Value ret_255 = alg_nil();
        alg_root_top = rt_base;
        return ret_255;
    }
    alg_hold_top = rh_1921;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Jumped"), "Contains", (Value[]){alg_hold(alg_invoke(v_this, "BreakTarget", (Value[]){v_thelabel}, 1))}, 1)))))) {
        Value ret_256 = alg_nil();
        alg_root_top = rt_base;
        return ret_256;
    }
    alg_hold_top = rh_1921;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_invoke(v_this, "BreakTarget", (Value[]){v_thelabel}, 1)), alg_literal(": ;")))}, 1)));
    alg_hold_top = rh_1921;
    Value ret_257 = alg_nil();
    alg_root_top = rt_base;
    return ret_257;
}

static Value m_cemitter_visitreturnstmt_1_returnstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ReturnStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1922 = alg_hold_top;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_1922;
    (void)((v_value = alg_literal("alg_nil()")));
    alg_hold_top = rh_1922;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Value")), alg_nil())))) {
        (void)((v_value = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Value"))}, 1))));
    }
    alg_hold_top = rh_1922;
    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "TryDepth"), alg_int(0))))) {
        {
            int32_t rh_1923 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "EmitReturn", (Value[]){v_value}, 1)));
            alg_hold_top = rh_1923;
            Value ret_258 = alg_nil();
            alg_root_top = rt_base;
            return ret_258;
            alg_hold_top = rh_1923;
        }
    }
    alg_hold_top = rh_1922;
    Value v_slot = alg_hold(alg_add(alg_literal("ret_"), alg_hold(alg_str(alg_property(v_this, "Loops")))));
    (void)v_slot;
    alg_root(&v_slot, 1);
    alg_hold_top = rh_1922;
    (void)(alg_set_property(v_this, "Loops", alg_hold(alg_add(alg_property(v_this, "Loops"), alg_int(1)))));
    alg_hold_top = rh_1922;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(v_this, "Local", NULL, 0)), v_slot)), alg_literal(" = "))), v_value)), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_1922;
    {
        int32_t rt_1924 = alg_root_top;
        int32_t rh_1925 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1925;
        {
            int32_t rh_1926 = alg_hold_top;
            for (; (alg_hold_top = rh_1926, alg_truthy(alg_hold(alg_less(v_i, alg_property(v_this, "TryDepth"))))); (alg_hold_top = rh_1926, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_literal("alg_pop_frame();")}, 1)));
            }
        }
        alg_hold_top = rh_1925;
        alg_root_top = rt_1924;
    }
    alg_hold_top = rh_1922;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "FrameRoots"), alg_literal(""))))) {
        (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_root_top = "), alg_property(v_this, "FrameRoots"))), alg_char_value(59)))}, 1)));
    }
    alg_hold_top = rh_1922;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("return "), v_slot)), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_1922;
    Value ret_259 = alg_nil();
    alg_root_top = rt_base;
    return ret_259;
}

static Value m_cemitter_emitforeign_1_functionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "FunctionStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1927 = alg_hold_top;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    alg_hold_top = rh_1927;
    (void)((v_symbol = alg_hold(alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1))));
    alg_hold_top = rh_1927;
    Value v_table = alg_hold(alg_invoke(v_this, "TypeTable", (Value[]){v_symbol, alg_hold(alg_invoke(v_this, "ParameterTable", (Value[]){v_thestmt}, 1))}, 2));
    (void)v_table;
    alg_root(&v_table, 1);
    alg_hold_top = rh_1927;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Value "), v_symbol)), alg_literal("(Value **cells, Value *args, int32_t count) {"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1927;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    (void)cells; (void)count;"), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1927;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    return alg_foreign("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "Symbol"))))}, 1)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "Library"))))}, 1)))), alg_literal(", "))), v_table)), alg_literal(", "))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length")))))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "ReturnType"))))}, 1)))), alg_literal(", args);"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1927;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_char_value(125), alg_char_value(10))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1927;
    Value v_name = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))));
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_1927;
    if (alg_truthy(alg_hold(alg_not(alg_property(v_this, "AtTopLevel"))))) {
        {
            int32_t rh_1928 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_name}, 1)));
            alg_hold_top = rh_1928;
            (void)(alg_hold(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_hold(alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_closure("), alg_hold(f_quotec(NULL, (Value[]){v_name}, 1)))), alg_literal(", "))), v_symbol)), alg_literal(", NULL, 0, "))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length")))))), alg_literal(", "))), v_table)), alg_char_value(41)))}, 2)));
            alg_hold_top = rh_1928;
            Value ret_260 = alg_nil();
            alg_root_top = rt_base;
            return ret_260;
            alg_hold_top = rh_1928;
        }
    }
    alg_hold_top = rh_1927;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1)))) {
        {
            int32_t rh_1929 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){alg_hold(alg_invoke(v_this, "SetName", (Value[]){v_name}, 1))}, 1)))))) {
                {
                    int32_t rh_1930 = alg_hold_top;
                    (void)(alg_hold(alg_invoke(v_this, "DeclareValue", (Value[]){alg_hold(alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)), v_name}, 2)));
                    alg_hold_top = rh_1930;
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    "), alg_hold(alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)))), alg_literal(" = alg_overloads("))), alg_hold(f_quotec(NULL, (Value[]){v_name}, 1)))), alg_literal(");"))), alg_char_value(10)))}, 1)));
                    alg_hold_top = rh_1930;
                }
            }
            alg_hold_top = rh_1929;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    alg_overload("), alg_hold(alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)))), alg_literal(", "))), v_symbol)), alg_literal(", "))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length")))))), alg_literal(", "))), v_table)), alg_literal(");"))), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_1929;
            Value ret_261 = alg_nil();
            alg_root_top = rt_base;
            return ret_261;
            alg_hold_top = rh_1929;
        }
    }
    alg_hold_top = rh_1927;
    (void)(alg_hold(alg_invoke(v_this, "DeclareValue", (Value[]){alg_hold(alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1)), v_name}, 2)));
    alg_hold_top = rh_1927;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    "), alg_hold(alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1)))), alg_literal(" = alg_closure("))), alg_hold(f_quotec(NULL, (Value[]){v_name}, 1)))), alg_literal(", "))), v_symbol)), alg_literal(", NULL, 0, "))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length")))))), alg_literal(", "))), v_table)), alg_literal(");"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1927;
    Value ret_262 = alg_nil();
    alg_root_top = rt_base;
    return ret_262;
}

static Value m_cemitter_visitfunctionstmt_1_functionstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "FunctionStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_1931 = alg_hold_top;
    Value v_enclosinglocals = alg_nil();
    (void)v_enclosinglocals;
    alg_root(&v_enclosinglocals, 1);
    alg_hold_top = rh_1931;
    Value v_enclosingtop = alg_nil();
    (void)v_enclosingtop;
    alg_root(&v_enclosingtop, 1);
    alg_hold_top = rh_1931;
    Value v_enclosingdepth = alg_nil();
    (void)v_enclosingdepth;
    alg_root(&v_enclosingdepth, 1);
    alg_hold_top = rh_1931;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1)))) {
        {
            int32_t rh_1932 = alg_hold_top;
            if (alg_truthy(alg_property(v_this, "EmitTests"))) {
                (void)(alg_hold(alg_invoke(v_this, "EmitTest", (Value[]){v_thestmt}, 1)));
            }
            alg_hold_top = rh_1932;
            Value ret_263 = alg_nil();
            alg_root_top = rt_base;
            return ret_263;
            alg_hold_top = rh_1932;
        }
    }
    alg_hold_top = rh_1931;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Symbol")), alg_literal(""))))) {
        {
            int32_t rh_1933 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "EmitForeign", (Value[]){v_thestmt}, 1)));
            alg_hold_top = rh_1933;
            Value ret_264 = alg_nil();
            alg_root_top = rt_base;
            return ret_264;
            alg_hold_top = rh_1933;
        }
    }
    alg_hold_top = rh_1931;
    Value v_nested = alg_hold(alg_not(alg_property(v_this, "AtTopLevel")));
    (void)v_nested;
    alg_root(&v_nested, 1);
    alg_hold_top = rh_1931;
    Value v_enclosingsymbol = alg_hold(alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1));
    (void)v_enclosingsymbol;
    alg_root(&v_enclosingsymbol, 1);
    alg_hold_top = rh_1931;
    (void)((v_enclosinglocals = alg_property(v_this, "Locals")));
    alg_hold_top = rh_1931;
    (void)((v_enclosingtop = alg_property(v_this, "AtTopLevel")));
    alg_hold_top = rh_1931;
    (void)((v_enclosingdepth = alg_property(v_this, "Depth")));
    alg_hold_top = rh_1931;
    Value v_enclosingboxed = alg_property(v_this, "Boxed");
    (void)v_enclosingboxed;
    alg_root(&v_enclosingboxed, 1);
    alg_hold_top = rh_1931;
    Value v_enclosingcaptured = alg_property(v_this, "Captured");
    (void)v_enclosingcaptured;
    alg_root(&v_enclosingcaptured, 1);
    alg_hold_top = rh_1931;
    Value v_enclosingcells = alg_property(v_this, "Cells");
    (void)v_enclosingcells;
    alg_root(&v_enclosingcells, 1);
    alg_hold_top = rh_1931;
    Value v_enclosingnested = alg_property(v_this, "InsideNested");
    (void)v_enclosingnested;
    alg_root(&v_enclosingnested, 1);
    alg_hold_top = rh_1931;
    Value v_enclosingnestedin = alg_property(v_this, "NestedIn");
    (void)v_enclosingnestedin;
    alg_root(&v_enclosingnestedin, 1);
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "NestedIn", v_enclosingsymbol));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Locals", alg_hold(alg_list())));
    alg_hold_top = rh_1931;
    Value v_inherited = alg_hold(alg_invoke(v_this, "VisibleCells", (Value[]){alg_property(v_this, "Captured"), v_enclosingcells}, 2));
    (void)v_inherited;
    alg_root(&v_inherited, 1);
    alg_hold_top = rh_1931;
    if (alg_truthy(v_nested)) {
        {
            int32_t rt_1934 = alg_root_top;
            int32_t rh_1935 = alg_hold_top;
            Value v_index = alg_hold(alg_map());
            (void)v_index;
            alg_root(&v_index, 1);
            alg_hold_top = rh_1935;
            {
                int32_t rt_1936 = alg_root_top;
                int32_t rh_1937 = alg_hold_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_1937;
                {
                    int32_t rh_1938 = alg_hold_top;
                    for (; (alg_hold_top = rh_1938, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_inherited, "Length")))))); (alg_hold_top = rh_1938, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                        alg_safe_point();
                        (void)(alg_hold(alg_invoke(v_index, "Put", (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_inherited, v_i)))), v_i}, 2)));
                    }
                }
                alg_hold_top = rh_1937;
                alg_root_top = rt_1936;
            }
            alg_hold_top = rh_1935;
            (void)(alg_set_property(v_this, "Captured", v_index));
            alg_hold_top = rh_1935;
            (void)(alg_set_property(v_this, "InsideNested", alg_bool(true)));
            alg_hold_top = rh_1935;
            alg_root_top = rt_1934;
        }
    } else {
        (void)(alg_set_property(v_this, "Captured", alg_hold(alg_map())));
    }
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Cells", alg_hold(alg_list())));
    alg_hold_top = rh_1931;
    Value v_enclosingvolatiles = alg_property(v_this, "Volatiles");
    (void)v_enclosingvolatiles;
    alg_root(&v_enclosingvolatiles, 1);
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Volatiles", alg_hold(alg_invoke(v_this, "ContainsTry", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1))));
    alg_hold_top = rh_1931;
    Value v_enclosingtrydepth = alg_property(v_this, "TryDepth");
    (void)v_enclosingtrydepth;
    alg_root(&v_enclosingtrydepth, 1);
    alg_hold_top = rh_1931;
    Value v_enclosinglooptry = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosinglooptry;
    alg_root(&v_enclosinglooptry, 1);
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "TryDepth", alg_int(0)));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_int(0)));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Boxed", alg_hold(alg_list())));
    alg_hold_top = rh_1931;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "DeclaresNested", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1)))) {
        (void)(alg_set_property(v_this, "Boxed", alg_hold(alg_invoke(v_this, "BoundNames", (Value[]){v_thestmt}, 1))));
    }
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "AtTopLevel", alg_bool(false)));
    alg_hold_top = rh_1931;
    Value v_enclosingtarget = alg_property(v_this, "Target");
    (void)v_enclosingtarget;
    alg_root(&v_enclosingtarget, 1);
    alg_hold_top = rh_1931;
    Value v_enclosingbody = alg_property(v_this, "Body");
    (void)v_enclosingbody;
    alg_root(&v_enclosingbody, 1);
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Target", alg_literal("body")));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Body", alg_hold(alg_buffer(alg_int(0)))));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Depth", alg_int(1)));
    alg_hold_top = rh_1931;
    if (alg_truthy(alg_hold(alg_not(v_nested)))) {
        (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_arity(count, "), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length")))))), alg_literal(");")))}, 1)));
    }
    alg_hold_top = rh_1931;
    Value v_enclosingframeroots = alg_property(v_this, "FrameRoots");
    (void)v_enclosingframeroots;
    alg_root(&v_enclosingframeroots, 1);
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "FrameRoots", alg_literal("rt_base")));
    alg_hold_top = rh_1931;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("int32_t "), alg_property(v_this, "FrameRoots"))), alg_literal(" = alg_root_top;")))}, 1)));
    alg_hold_top = rh_1931;
    (void)(alg_hold(alg_invoke(v_this, "Root", (Value[]){alg_literal("args"), alg_literal("count")}, 2)));
    alg_hold_top = rh_1931;
    if (alg_truthy(v_nested)) {
        {
            int32_t rt_1939 = alg_root_top;
            int32_t rh_1940 = alg_hold_top;
            Value v_i = alg_int(0);
            (void)v_i;
            alg_root(&v_i, 1);
            alg_hold_top = rh_1940;
            {
                int32_t rh_1941 = alg_hold_top;
                for (; (alg_hold_top = rh_1941, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_inherited, "Length")))))); (alg_hold_top = rh_1941, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                    alg_safe_point();
                    (void)(alg_hold(alg_invoke(v_this, "Root", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("cells["), alg_hold(alg_str(v_i)))), alg_char_value(93))), alg_char_value(49)}, 2)));
                }
            }
            alg_hold_top = rh_1940;
            alg_root_top = rt_1939;
        }
    }
    alg_hold_top = rh_1931;
    {
        int32_t rt_1942 = alg_root_top;
        int32_t rh_1943 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1943;
        {
            int32_t rh_1944 = alg_hold_top;
            for (; (alg_hold_top = rh_1944, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length")))))); (alg_hold_top = rh_1944, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1945 = alg_root_top;
                    int32_t rh_1946 = alg_hold_top;
                    Value v_paramname = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_subscript_get(alg_hold(alg_property(v_thestmt, "Params")), v_i)), "Lexeme"))));
                    (void)v_paramname;
                    alg_root(&v_paramname, 1);
                    alg_hold_top = rh_1946;
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_paramname}, 1)));
                    alg_hold_top = rh_1946;
                    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_paramname}, 1)))) {
                        {
                            int32_t rt_1947 = alg_root_top;
                            int32_t rh_1948 = alg_hold_top;
                            Value v_qualifier = alg_literal("Value *");
                            (void)v_qualifier;
                            alg_root(&v_qualifier, 1);
                            alg_hold_top = rh_1948;
                            if (alg_truthy(alg_property(v_this, "Volatiles"))) {
                                (void)((v_qualifier = alg_literal("Value *volatile ")));
                            }
                            alg_hold_top = rh_1948;
                            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_qualifier, alg_hold(alg_invoke(v_this, "Cell", (Value[]){v_paramname}, 1)))), alg_literal(" = alg_cell("))), alg_hold(alg_invoke(v_this, "BoundArgument", (Value[]){alg_hold(alg_invoke(v_this, "ReportedName", (Value[]){v_thestmt}, 1)), alg_hold(alg_property(v_thestmt, "ParamTypes")), v_i}, 3)))), alg_literal(");")))}, 1)));
                            alg_hold_top = rh_1948;
                            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("(void)"), alg_hold(alg_invoke(v_this, "Cell", (Value[]){v_paramname}, 1)))), alg_char_value(59)))}, 1)));
                            alg_hold_top = rh_1948;
                            (void)(alg_hold(alg_invoke(alg_property(v_this, "Cells"), "Add", (Value[]){v_paramname}, 1)));
                            alg_hold_top = rh_1948;
                            alg_root_top = rt_1947;
                        }
                    } else {
                        {
                            int32_t rh_1949 = alg_hold_top;
                            (void)(alg_hold(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_hold(alg_invoke(v_this, "VariableName", (Value[]){v_paramname}, 1)), alg_hold(alg_invoke(v_this, "BoundArgument", (Value[]){alg_hold(alg_invoke(v_this, "ReportedName", (Value[]){v_thestmt}, 1)), alg_hold(alg_property(v_thestmt, "ParamTypes")), v_i}, 3))}, 2)));
                            alg_hold_top = rh_1949;
                        }
                    }
                    alg_hold_top = rh_1946;
                    alg_root_top = rt_1945;
                }
            }
        }
        alg_hold_top = rh_1943;
        alg_root_top = rt_1942;
    }
    alg_hold_top = rh_1931;
    (void)(alg_hold(alg_invoke(v_this, "HoistCells", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1)));
    alg_hold_top = rh_1931;
    (void)(alg_hold(alg_invoke(v_this, "PushLabels", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1)));
    alg_hold_top = rh_1931;
    Value v_holds = alg_hold(alg_invoke(v_this, "OpenHolds", NULL, 0));
    (void)v_holds;
    alg_root(&v_holds, 1);
    alg_hold_top = rh_1931;
    {
        int32_t rt_1950 = alg_root_top;
        Value loop_265 = alg_iterable(alg_hold(alg_property(v_thestmt, "Body")));
        (void)loop_265;
        alg_root(&loop_265, 1);
        for (int32_t at_265 = 0; at_265 < alg_iterable_count(loop_265); at_265++) {
            alg_safe_point();
            int32_t rt_1951 = alg_root_top;
            Value v_each = alg_iterable_at(loop_265, at_265);
            (void)v_each;
            alg_root(&v_each, 1);
            (void)(alg_hold(alg_invoke(v_this, "ExecuteHeld", (Value[]){v_each, v_holds}, 2)));
            alg_root_top = rt_1951;
        }
        alg_root_top = rt_1950;
    }
    alg_hold_top = rh_1931;
    (void)(alg_hold(alg_invoke(v_this, "PopLabels", NULL, 0)));
    alg_hold_top = rh_1931;
    (void)(alg_hold(alg_invoke(v_this, "EmitReturn", (Value[]){alg_literal("alg_nil()")}, 1)));
    alg_hold_top = rh_1931;
    Value v_written = alg_hold(alg_property(alg_property(v_this, "Body"), "Text"));
    (void)v_written;
    alg_root(&v_written, 1);
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Target", v_enclosingtarget));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Body", v_enclosingbody));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "NestedIn", v_enclosingnestedin));
    alg_hold_top = rh_1931;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(v_this, "Prototype", (Value[]){v_thestmt}, 1)), alg_literal(" {"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1931;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    (void)cells; (void)args; (void)count;"), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1931;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){v_written}, 1)));
    alg_hold_top = rh_1931;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_char_value(125), alg_char_value(10))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1931;
    Value v_capturedcells = v_inherited;
    (void)v_capturedcells;
    alg_root(&v_capturedcells, 1);
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "FrameRoots", v_enclosingframeroots));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Depth", v_enclosingdepth));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "AtTopLevel", v_enclosingtop));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Locals", v_enclosinglocals));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Volatiles", v_enclosingvolatiles));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Boxed", v_enclosingboxed));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Captured", v_enclosingcaptured));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "Cells", v_enclosingcells));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "TryDepth", v_enclosingtrydepth));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "LoopTryDepth", v_enclosinglooptry));
    alg_hold_top = rh_1931;
    (void)(alg_set_property(v_this, "InsideNested", v_enclosingnested));
    alg_hold_top = rh_1931;
    Value v_name = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))));
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_1931;
    if (alg_truthy(v_nested)) {
        {
            int32_t rh_1952 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_name}, 1)));
            alg_hold_top = rh_1952;
            (void)(alg_hold(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_hold(alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), alg_hold(alg_invoke(v_this, "ClosureOf", (Value[]){v_thestmt, v_capturedcells}, 2))}, 2)));
            alg_hold_top = rh_1952;
        }
    } else {
        if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1)))) {
            {
                int32_t rh_1953 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "SetsBuilt"), "Contains", (Value[]){v_name}, 1)))))) {
                    {
                        int32_t rh_1954 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "SetsBuilt"), "Add", (Value[]){v_name}, 1)));
                        alg_hold_top = rh_1954;
                        (void)(alg_hold(alg_invoke(v_this, "DeclareValue", (Value[]){alg_hold(alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)), v_name}, 2)));
                        alg_hold_top = rh_1954;
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    "), alg_hold(alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)))), alg_literal(" = alg_overloads("))), alg_hold(f_quotec(NULL, (Value[]){v_name}, 1)))), alg_literal(");"))), alg_char_value(10)))}, 1)));
                        alg_hold_top = rh_1954;
                    }
                }
                alg_hold_top = rh_1953;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    alg_overload("), alg_hold(alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1)))), alg_literal(", "))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Params")), "Length")))))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "TypeTable", (Value[]){alg_hold(alg_invoke(v_this, "FunctionSymbol", (Value[]){v_thestmt}, 1)), alg_hold(alg_invoke(v_this, "ParameterTable", (Value[]){v_thestmt}, 1))}, 2)))), alg_literal(");"))), alg_char_value(10)))}, 1)));
                alg_hold_top = rh_1953;
            }
        } else {
            {
                int32_t rh_1955 = alg_hold_top;
                (void)(alg_hold(alg_invoke(v_this, "DeclareValue", (Value[]){alg_hold(alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1)), v_name}, 2)));
                alg_hold_top = rh_1955;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    "), alg_hold(alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1)))), alg_literal(" = "))), alg_hold(alg_invoke(v_this, "ClosureOf", (Value[]){v_thestmt, alg_hold(alg_list())}, 2)))), alg_char_value(59))), alg_char_value(10)))}, 1)));
                alg_hold_top = rh_1955;
            }
        }
    }
    alg_hold_top = rh_1931;
    Value ret_266 = alg_nil();
    alg_root_top = rt_base;
    return ret_266;
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
    int32_t rh_1956 = alg_hold_top;
    Value v_table = alg_nil();
    (void)v_table;
    alg_root(&v_table, 1);
    alg_hold_top = rh_1956;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_types, "Length")), alg_int(0))))) {
        Value ret_267 = alg_literal("NULL");
        alg_root_top = rt_base;
        return ret_267;
    }
    alg_hold_top = rh_1956;
    (void)((v_table = alg_hold(alg_add(alg_literal("t_"), v_symbol))));
    alg_hold_top = rh_1956;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Tables"), "Contains", (Value[]){v_table}, 1)))) {
        Value ret_268 = v_table;
        alg_root_top = rt_base;
        return ret_268;
    }
    alg_hold_top = rh_1956;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Tables"), "Add", (Value[]){v_table}, 1)));
    alg_hold_top = rh_1956;
    Value v_quoted = alg_literal("");
    (void)v_quoted;
    alg_root(&v_quoted, 1);
    alg_hold_top = rh_1956;
    {
        int32_t rt_1957 = alg_root_top;
        int32_t rh_1958 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_1958;
        {
            int32_t rh_1959 = alg_hold_top;
            for (; (alg_hold_top = rh_1959, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_types, "Length")))))); (alg_hold_top = rh_1959, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_1960 = alg_hold_top;
                    if (alg_truthy(alg_hold(alg_greater(v_i, alg_int(0))))) {
                        (void)((v_quoted = alg_hold(alg_add(v_quoted, alg_literal(", ")))));
                    }
                    alg_hold_top = rh_1960;
                    (void)((v_quoted = alg_hold(alg_add(v_quoted, alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_types, v_i))))}, 1))))));
                    alg_hold_top = rh_1960;
                }
            }
        }
        alg_hold_top = rh_1958;
        alg_root_top = rt_1957;
    }
    alg_hold_top = rh_1956;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static const char *"), v_table)), alg_literal("[] = { "))), v_quoted)), alg_literal(" };"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_1956;
    Value ret_269 = v_table;
    alg_root_top = rt_base;
    return ret_269;
    alg_hold_top = rh_1956;
    Value ret_270 = alg_nil();
    alg_root_top = rt_base;
    return ret_270;
}

static Value m_cemitter_visitliteral_1_literalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "LiteralExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1961 = alg_hold_top;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_1961;
    (void)((v_value = alg_hold(alg_property(v_theexpr, "Value"))));
    alg_hold_top = rh_1961;
    if (alg_truthy(alg_hold(alg_equal(v_value, alg_nil())))) {
        Value ret_271 = alg_literal("alg_nil()");
        alg_root_top = rt_base;
        return ret_271;
    }
    alg_hold_top = rh_1961;
    if (alg_truthy(alg_hold(alg_equal(v_value, alg_bool(true))))) {
        Value ret_272 = alg_literal("alg_bool(true)");
        alg_root_top = rt_base;
        return ret_272;
    }
    alg_hold_top = rh_1961;
    if (alg_truthy(alg_hold(alg_equal(v_value, alg_bool(false))))) {
        Value ret_273 = alg_literal("alg_bool(false)");
        alg_root_top = rt_base;
        return ret_273;
    }
    alg_hold_top = rh_1961;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_INTEGER))) {
        {
            int32_t rh_1962 = alg_hold_top;
            if (alg_truthy(alg_hold((or_55 = alg_hold(alg_greater(v_value, alg_int(9223372036854775807))), alg_truthy(or_55) ? or_55 : alg_hold(alg_less(v_value, alg_hold(alg_negate(alg_int(9223372036854775807))))))))) {
                Value ret_274 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_integer("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(v_value))}, 1)))), alg_char_value(41)));
                alg_root_top = rt_base;
                return ret_274;
            }
            alg_hold_top = rh_1962;
            Value ret_275 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_int("), alg_hold(alg_str(v_value)))), alg_char_value(41)));
            alg_root_top = rt_base;
            return ret_275;
            alg_hold_top = rh_1962;
        }
    }
    alg_hold_top = rh_1961;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_DOUBLE))) {
        Value ret_276 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_double("), alg_hold(alg_str(v_value)))), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_276;
    }
    alg_hold_top = rh_1961;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_STRING))) {
        Value ret_277 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_literal("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(v_value))}, 1)))), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_277;
    }
    alg_hold_top = rh_1961;
    if (alg_truthy(alg_is_kind(v_value, ALG_KIND_CHAR))) {
        Value ret_278 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_char_value("), alg_hold(alg_str(alg_hold(alg_ord(v_value)))))), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_278;
    }
    alg_hold_top = rh_1961;
    (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_hold(alg_add(alg_literal("A literal of type "), alg_hold(f_typenameof(NULL, (Value[]){v_value}, 1))))}, 1)));
    alg_hold_top = rh_1961;
    Value ret_279 = alg_nil();
    alg_root_top = rt_base;
    return ret_279;
}

static Value m_cemitter_visitvariableexpr_1_variableexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "VariableExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1963 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_1963;
    (void)((v_name = alg_hold(alg_invoke(v_this, "Spelled", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 1))));
    alg_hold_top = rh_1963;
    if (alg_truthy(alg_hold((or_56 = alg_hold(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1)), alg_truthy(or_56) ? or_56 : alg_hold(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1)))))) {
        Value ret_280 = alg_hold(alg_invoke(v_this, "Read", (Value[]){v_name}, 1));
        alg_root_top = rt_base;
        return ret_280;
    }
    alg_hold_top = rh_1963;
    if (alg_truthy(alg_hold((or_59 = alg_hold((or_58 = alg_hold((or_57 = alg_hold(alg_not_equal(alg_property(v_this, "CurrentClass"), alg_literal(""))), !alg_truthy(or_57) ? or_57 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)))))), !alg_truthy(or_58) ? or_58 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "VisibleGlobal", (Value[]){v_name}, 1)))))), !alg_truthy(or_59) ? or_59 : alg_hold(alg_invoke(alg_property(v_this, "VisibleFields"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))))) {
        Value ret_281 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_property("), alg_hold(alg_invoke(v_this, "ThisRef", NULL, 0)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){v_name}, 1)))), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_281;
    }
    alg_hold_top = rh_1963;
    if (alg_truthy(alg_hold((or_60 = alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)))), !alg_truthy(or_60) ? or_60 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "OwnGlobal", (Value[]){v_name}, 1)))))))) {
        {
            int32_t rh_1964 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Contains", (Value[]){v_name}, 1)))) {
                Value ret_282 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_error("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_invoke(v_this, "AmbiguousMessage", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme")))), alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Get", (Value[]){v_name}, 1))))}, 2))}, 1)))), alg_literal("), alg_nil())")));
                alg_root_top = rt_base;
                return ret_282;
            }
            alg_hold_top = rh_1964;
            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Contains", (Value[]){v_name}, 1)))) {
                Value ret_283 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_error("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_invoke(v_this, "AmbiguousMessage", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme")))), alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Get", (Value[]){v_name}, 1))))}, 2))}, 1)))), alg_literal("), alg_nil())")));
                alg_root_top = rt_base;
                return ret_283;
            }
            alg_hold_top = rh_1964;
            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_name}, 1)))) {
                Value ret_284 = alg_hold(alg_invoke(v_this, "EnumMemberName", (Value[]){alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_name}, 1)))), v_name}, 2));
                alg_root_top = rt_base;
                return ret_284;
            }
            alg_hold_top = rh_1964;
            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "EnumTypes"), "Contains", (Value[]){v_name}, 1)))) {
                Value ret_285 = alg_hold(alg_invoke(v_this, "EnumTypeName", (Value[]){v_name}, 1));
                alg_root_top = rt_base;
                return ret_285;
            }
            alg_hold_top = rh_1964;
            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))) {
                Value ret_286 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_singleton("), alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)))), alg_char_value(41)));
                alg_root_top = rt_base;
                return ret_286;
            }
            alg_hold_top = rh_1964;
            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1)))) {
                Value ret_287 = alg_hold(alg_invoke(v_this, "SubprogramValue", (Value[]){v_name}, 1));
                alg_root_top = rt_base;
                return ret_287;
            }
            alg_hold_top = rh_1964;
        }
    }
    alg_hold_top = rh_1963;
    (void)(alg_hold(alg_invoke(v_this, "Unreachable", (Value[]){v_name}, 1)));
    alg_hold_top = rh_1963;
    if (alg_truthy(alg_hold((or_63 = alg_hold((or_62 = alg_hold((or_61 = alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)))), !alg_truthy(or_61) ? or_61 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))))), !alg_truthy(or_62) ? or_62 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))))), !alg_truthy(or_63) ? or_63 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))))))) {
        {
            int32_t rh_1965 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "ShadowNames"), "Contains", (Value[]){v_name}, 1)))))) {
                {
                    int32_t rt_1966 = alg_root_top;
                    int32_t rh_1967 = alg_hold_top;
                    Value v_held = alg_hold(alg_invoke(v_this, "BuiltinHandle", (Value[]){v_name}, 1));
                    (void)v_held;
                    alg_root(&v_held, 1);
                    alg_hold_top = rh_1967;
                    if (alg_truthy(alg_hold(alg_not_equal(v_held, alg_literal(""))))) {
                        Value ret_288 = v_held;
                        alg_root_top = rt_base;
                        return ret_288;
                    }
                    alg_hold_top = rh_1967;
                    alg_root_top = rt_1966;
                }
            }
            alg_hold_top = rh_1965;
            Value ret_289 = alg_hold(alg_invoke(v_this, "Missing", (Value[]){v_name, alg_hold(alg_property(v_theexpr, "Name"))}, 2));
            alg_root_top = rt_base;
            return ret_289;
            alg_hold_top = rh_1965;
        }
    }
    alg_hold_top = rh_1963;
    if (alg_truthy(alg_hold((or_65 = alg_hold((or_64 = alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)), !alg_truthy(or_64) ? or_64 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)))))), !alg_truthy(or_65) ? or_65 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))))))) {
        {
            int32_t rh_1968 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "VisibleClasses"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))) {
                Value ret_290 = alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1));
                alg_root_top = rt_base;
                return ret_290;
            }
            alg_hold_top = rh_1968;
            (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_literal("A class held as a value where its handle is out of scope")}, 1)));
            alg_hold_top = rh_1968;
        }
    }
    alg_hold_top = rh_1963;
    Value ret_291 = alg_hold(alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_hold(alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1))}, 2));
    alg_root_top = rt_base;
    return ret_291;
    alg_hold_top = rh_1963;
    Value ret_292 = alg_nil();
    alg_root_top = rt_base;
    return ret_292;
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
    int32_t rh_1969 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_293 = v_text;
        alg_root_top = rt_base;
        return ret_293;
    }
    alg_hold_top = rh_1969;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))))) {
        Value ret_294 = v_text;
        alg_root_top = rt_base;
        return ret_294;
    }
    alg_hold_top = rh_1969;
    Value ret_295 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_declared("), alg_hold(alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){v_name}, 1)))), alg_literal("), "))), v_text)), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_295;
    alg_hold_top = rh_1969;
    Value ret_296 = alg_nil();
    alg_root_top = rt_base;
    return ret_296;
}

static Value m_cemitter_ownglobal_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1970 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "GlobalsIn"), "Contains", (Value[]){alg_property(v_this, "UnitName")}, 1)))))) {
        Value ret_297 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_297;
    }
    alg_hold_top = rh_1970;
    Value ret_298 = alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "GlobalsIn"), "Get", (Value[]){alg_property(v_this, "UnitName")}, 1), ALG_KIND_SET, "Set"))), "Contains", (Value[]){v_name}, 1));
    alg_root_top = rt_base;
    return ret_298;
    alg_hold_top = rh_1970;
    Value ret_299 = alg_nil();
    alg_root_top = rt_base;
    return ret_299;
}

static Value m_cemitter_visibleglobal_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1971 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "OwnGlobal", (Value[]){v_name}, 1)))) {
        Value ret_300 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_300;
    }
    alg_hold_top = rh_1971;
    Value ret_301 = alg_hold((or_66 = alg_hold(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)), !alg_truthy(or_66) ? or_66 : alg_hold(alg_invoke(alg_property(v_this, "ShadowNames"), "Contains", (Value[]){v_name}, 1))));
    alg_root_top = rt_base;
    return ret_301;
    alg_hold_top = rh_1971;
    Value ret_302 = alg_nil();
    alg_root_top = rt_base;
    return ret_302;
}

static Value m_cemitter_visiblesubprogram_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1972 = alg_hold_top;
    Value ret_303 = alg_hold(alg_invoke(alg_property(v_this, "VisibleDeclared"), "Contains", (Value[]){v_name}, 1));
    alg_root_top = rt_base;
    return ret_303;
    alg_hold_top = rh_1972;
    Value ret_304 = alg_nil();
    alg_root_top = rt_base;
    return ret_304;
}

static Value m_cemitter_missing_2_string_token(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_where = alg_widen(args[1], "Token");
    (void)v_where;
    alg_root(&v_where, 1);
    int32_t rh_1973 = alg_hold_top;
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_1973;
    if (alg_truthy(alg_hold((or_67 = alg_hold(alg_not(alg_property(v_this, "EmitTests"))), !alg_truthy(or_67) ? or_67 : alg_hold(alg_invoke(v_this, "IsAssertion", (Value[]){v_name}, 1)))))) {
        Value ret_305 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_error("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_invoke(v_this, "MissingName", (Value[]){v_name}, 1))}, 1)))), alg_literal("), alg_nil())")));
        alg_root_top = rt_base;
        return ret_305;
    }
    alg_hold_top = rh_1973;
    (void)((v_key = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("missing:"), alg_hold(alg_str(alg_hold(alg_property(v_where, "LineNumber")))))), alg_char_value(58))), alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))))));
    alg_hold_top = rh_1973;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Warned"), "Contains", (Value[]){v_key}, 1)))))) {
        {
            int32_t rh_1974 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Warned"), "Add", (Value[]){v_key}, 1)));
            alg_hold_top = rh_1974;
            (void)(alg_hold(alg_invoke(alg_singleton(k_console), "Warn", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(alg_singleton(k_sourcecode), "Named", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_where, "File"))))}, 1)), alg_char_value(58))), alg_hold(alg_str(alg_hold(alg_property(v_where, "LineNumber")))))), alg_literal(": "))), alg_hold(alg_invoke(v_this, "MissingName", (Value[]){v_name}, 1))))}, 1)));
            alg_hold_top = rh_1974;
        }
    }
    alg_hold_top = rh_1973;
    Value ret_306 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_error("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_invoke(v_this, "MissingName", (Value[]){v_name}, 1))}, 1)))), alg_literal("), alg_nil())")));
    alg_root_top = rt_base;
    return ret_306;
    alg_hold_top = rh_1973;
    Value ret_307 = alg_nil();
    alg_root_top = rt_base;
    return ret_307;
}

static Value m_cemitter_missingname_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1975 = alg_hold_top;
    Value v_units = alg_nil();
    (void)v_units;
    alg_root(&v_units, 1);
    alg_hold_top = rh_1975;
    (void)((v_units = alg_hold(alg_invoke(alg_property(v_this, "UnitExports"), "Keys", NULL, 0))));
    alg_hold_top = rh_1975;
    {
        int32_t rt_1976 = alg_root_top;
        Value loop_308 = alg_iterable(v_units);
        (void)loop_308;
        alg_root(&loop_308, 1);
        for (int32_t at_308 = 0; at_308 < alg_iterable_count(loop_308); at_308++) {
            alg_safe_point();
            int32_t rt_1977 = alg_root_top;
            Value v_theunit = alg_iterable_at(loop_308, at_308);
            (void)v_theunit;
            alg_root(&v_theunit, 1);
            if (alg_truthy(alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_theunit}, 1), ALG_KIND_SET, "Set"))), "Contains", (Value[]){v_name}, 1)))) {
                Value ret_309 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined variable '"), v_name)), alg_literal("'. Unit '"))), alg_hold(alg_str(v_theunit)))), alg_literal("' exports it; this file has no 'uses' for it.")));
                alg_root_top = rt_base;
                return ret_309;
            }
            alg_root_top = rt_1977;
        }
        alg_root_top = rt_1976;
    }
    alg_hold_top = rh_1975;
    Value ret_310 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined variable '"), v_name)), alg_literal("'.")));
    alg_root_top = rt_base;
    return ret_310;
    alg_hold_top = rh_1975;
    Value ret_311 = alg_nil();
    alg_root_top = rt_base;
    return ret_311;
}

static Value m_cemitter_spelled_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1978 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_312 = alg_hold(alg_str(v_name));
        alg_root_top = rt_base;
        return ret_312;
    }
    alg_hold_top = rh_1978;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Canonical"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))) {
        Value ret_313 = alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "Canonical"), "Get", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1))));
        alg_root_top = rt_base;
        return ret_313;
    }
    alg_hold_top = rh_1978;
    Value ret_314 = alg_hold(alg_str(v_name));
    alg_root_top = rt_base;
    return ret_314;
    alg_hold_top = rh_1978;
    Value ret_315 = alg_nil();
    alg_root_top = rt_base;
    return ret_315;
}

static Value m_cemitter_unreachable_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1979 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_property(v_this, "InsideNested"))))) {
        Value ret_316 = alg_nil();
        alg_root_top = rt_base;
        return ret_316;
    }
    alg_hold_top = rh_1979;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_317 = alg_nil();
        alg_root_top = rt_base;
        return ret_317;
    }
    alg_hold_top = rh_1979;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_318 = alg_nil();
        alg_root_top = rt_base;
        return ret_318;
    }
    alg_hold_top = rh_1979;
    (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("Reading '"), v_name)), alg_literal("' from a nested function")))}, 1)));
    alg_hold_top = rh_1979;
    Value ret_319 = alg_nil();
    alg_root_top = rt_base;
    return ret_319;
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
    int32_t rh_1980 = alg_hold_top;
    if (alg_truthy(alg_hold((or_68 = alg_hold(alg_equal(alg_hold(alg_str(v_declared)), alg_literal(""))), alg_truthy(or_68) ? or_68 : alg_hold(alg_equal(alg_hold(alg_str(v_declared)), alg_literal("Any"))))))) {
        Value ret_320 = alg_hold(alg_str(v_value));
        alg_root_top = rt_base;
        return ret_320;
    }
    alg_hold_top = rh_1980;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "Elidable", (Value[]){v_declared, v_actual}, 2)))) {
        Value ret_321 = alg_hold(alg_str(v_value));
        alg_root_top = rt_base;
        return ret_321;
    }
    alg_hold_top = rh_1980;
    Value ret_322 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_widen("), alg_hold(alg_str(v_value)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(v_declared))}, 1)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_322;
    alg_hold_top = rh_1980;
    Value ret_323 = alg_nil();
    alg_root_top = rt_base;
    return ret_323;
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
    int32_t rh_1981 = alg_hold_top;
    if (alg_truthy(alg_hold((or_69 = alg_hold(alg_equal(alg_hold(alg_str(v_actual)), alg_literal(""))), alg_truthy(or_69) ? or_69 : alg_hold(alg_equal(alg_hold(alg_str(v_actual)), alg_literal("Any"))))))) {
        Value ret_324 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_324;
    }
    alg_hold_top = rh_1981;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(f_foldcase(NULL, (Value[]){v_declared}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_actual}, 1)))))) {
        Value ret_325 = alg_bool(false);
        alg_root_top = rt_base;
        return ret_325;
    }
    alg_hold_top = rh_1981;
    Value ret_326 = alg_hold(alg_not(alg_hold(f_issubrange(NULL, (Value[]){v_declared}, 1))));
    alg_root_top = rt_base;
    return ret_326;
    alg_hold_top = rh_1981;
    Value ret_327 = alg_nil();
    alg_root_top = rt_base;
    return ret_327;
}

static Value m_cemitter_visitassignexpr_1_assignexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "AssignExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1982 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_1982;
    (void)((v_name = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))));
    alg_hold_top = rh_1982;
    Value v_written = alg_hold(alg_invoke(v_this, "BoundValue", (Value[]){alg_hold(alg_property(v_theexpr, "Declared")), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1)), alg_hold(alg_property(v_theexpr, "Actual"))}, 3));
    (void)v_written;
    alg_root(&v_written, 1);
    alg_hold_top = rh_1982;
    if (alg_truthy(alg_hold((or_70 = alg_hold(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1)), alg_truthy(or_70) ? or_70 : alg_hold(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1)))))) {
        Value ret_328 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(40), alg_hold(alg_invoke(v_this, "Read", (Value[]){v_name}, 1)))), alg_literal(" = "))), v_written)), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_328;
    }
    alg_hold_top = rh_1982;
    if (alg_truthy(alg_hold((or_73 = alg_hold((or_72 = alg_hold((or_71 = alg_hold(alg_not_equal(alg_property(v_this, "CurrentClass"), alg_literal(""))), !alg_truthy(or_71) ? or_71 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)))))), !alg_truthy(or_72) ? or_72 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "VisibleGlobal", (Value[]){v_name}, 1)))))), !alg_truthy(or_73) ? or_73 : alg_hold(alg_invoke(alg_property(v_this, "VisibleFields"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))))) {
        Value ret_329 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_set_property("), alg_hold(alg_invoke(v_this, "ThisRef", NULL, 0)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){v_name}, 1)))), alg_literal(", "))), v_written)), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_329;
    }
    alg_hold_top = rh_1982;
    (void)(alg_hold(alg_invoke(v_this, "Unreachable", (Value[]){v_name}, 1)));
    alg_hold_top = rh_1982;
    Value ret_330 = alg_hold(alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(40), alg_hold(alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)))), alg_literal(" = "))), v_written)), alg_char_value(41)))}, 2));
    alg_root_top = rt_base;
    return ret_330;
    alg_hold_top = rh_1982;
    Value ret_331 = alg_nil();
    alg_root_top = rt_base;
    return ret_331;
}

static Value m_cemitter_visitgrouping_1_groupingexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GroupingExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1983 = alg_hold_top;
    Value ret_332 = alg_hold(alg_add(alg_hold(alg_add(alg_char_value(40), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Expression"))}, 1)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_332;
    alg_hold_top = rh_1983;
    Value ret_333 = alg_nil();
    alg_root_top = rt_base;
    return ret_333;
}

static Value m_cemitter_declarestype_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1984 = alg_hold_top;
    Value v_key = alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1));
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_1984;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_key}, 1)))) {
        Value ret_334 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_334;
    }
    alg_hold_top = rh_1984;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){v_key}, 1)))) {
        Value ret_335 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_335;
    }
    alg_hold_top = rh_1984;
    if (alg_truthy(alg_hold(alg_greater_equal(alg_hold(f_subrangeindex(NULL, (Value[]){v_name}, 1)), alg_int(0))))) {
        Value ret_336 = alg_bool(true);
        alg_root_top = rt_base;
        return ret_336;
    }
    alg_hold_top = rh_1984;
    {
        int32_t rt_1985 = alg_root_top;
        Value loop_337 = alg_iterable(alg_property(v_this, "EnumTypes"));
        (void)loop_337;
        alg_root(&loop_337, 1);
        for (int32_t at_337 = 0; at_337 < alg_iterable_count(loop_337); at_337++) {
            alg_safe_point();
            int32_t rt_1986 = alg_root_top;
            Value v_declared = alg_iterable_at(loop_337, at_337);
            (void)v_declared;
            alg_root(&v_declared, 1);
            if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){v_declared}, 1)), v_key)))) {
                Value ret_338 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_338;
            }
            alg_root_top = rt_1986;
        }
        alg_root_top = rt_1985;
    }
    alg_hold_top = rh_1984;
    Value ret_339 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_339;
    alg_hold_top = rh_1984;
    Value ret_340 = alg_nil();
    alg_root_top = rt_base;
    return ret_340;
}

static Value m_cemitter_resolvedkind_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1987 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "DeclaresType", (Value[]){v_name}, 1)))) {
        Value ret_341 = alg_literal("");
        alg_root_top = rt_base;
        return ret_341;
    }
    alg_hold_top = rh_1987;
    Value ret_342 = alg_hold(alg_invoke(v_this, "BuiltinTypeName", (Value[]){v_name}, 1));
    alg_root_top = rt_base;
    return ret_342;
    alg_hold_top = rh_1987;
    Value ret_343 = alg_nil();
    alg_root_top = rt_base;
    return ret_343;
}

static Value m_cemitter_builtintypename_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1988 = alg_hold_top;
    Value v_key = alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1));
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("boolean"))))) {
        Value ret_344 = alg_literal("ALG_KIND_BOOLEAN");
        alg_root_top = rt_base;
        return ret_344;
    }
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("integer"))))) {
        Value ret_345 = alg_literal("ALG_KIND_INTEGER");
        alg_root_top = rt_base;
        return ret_345;
    }
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("double"))))) {
        Value ret_346 = alg_literal("ALG_KIND_DOUBLE");
        alg_root_top = rt_base;
        return ret_346;
    }
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("string"))))) {
        Value ret_347 = alg_literal("ALG_KIND_STRING");
        alg_root_top = rt_base;
        return ret_347;
    }
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("char"))))) {
        Value ret_348 = alg_literal("ALG_KIND_CHAR");
        alg_root_top = rt_base;
        return ret_348;
    }
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("pointer"))))) {
        Value ret_349 = alg_literal("ALG_KIND_POINTER");
        alg_root_top = rt_base;
        return ret_349;
    }
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("list"))))) {
        Value ret_350 = alg_literal("ALG_KIND_LIST");
        alg_root_top = rt_base;
        return ret_350;
    }
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("set"))))) {
        Value ret_351 = alg_literal("ALG_KIND_SET");
        alg_root_top = rt_base;
        return ret_351;
    }
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("stack"))))) {
        Value ret_352 = alg_literal("ALG_KIND_STACK");
        alg_root_top = rt_base;
        return ret_352;
    }
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("array"))))) {
        Value ret_353 = alg_literal("ALG_KIND_ARRAY");
        alg_root_top = rt_base;
        return ret_353;
    }
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("map"))))) {
        Value ret_354 = alg_literal("ALG_KIND_MAP");
        alg_root_top = rt_base;
        return ret_354;
    }
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("textfile"))))) {
        Value ret_355 = alg_literal("ALG_KIND_TEXTFILE");
        alg_root_top = rt_base;
        return ret_355;
    }
    alg_hold_top = rh_1988;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("buffer"))))) {
        Value ret_356 = alg_literal("ALG_KIND_BUFFER");
        alg_root_top = rt_base;
        return ret_356;
    }
    alg_hold_top = rh_1988;
    Value ret_357 = alg_literal("");
    alg_root_top = rt_base;
    return ret_357;
    alg_hold_top = rh_1988;
    Value ret_358 = alg_nil();
    alg_root_top = rt_base;
    return ret_358;
}

static Value m_cemitter_resolvedclass_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1989 = alg_hold_top;
    Value v_key = alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1));
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_1989;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){v_key}, 1)))))) {
        Value ret_359 = alg_literal("");
        alg_root_top = rt_base;
        return ret_359;
    }
    alg_hold_top = rh_1989;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "VisibleClasses"), "Contains", (Value[]){v_key}, 1)))))) {
        Value ret_360 = alg_literal("");
        alg_root_top = rt_base;
        return ret_360;
    }
    alg_hold_top = rh_1989;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_invoke(v_this, "BuiltinTypeName", (Value[]){v_name}, 1)), alg_literal(""))))) {
        Value ret_361 = alg_literal("");
        alg_root_top = rt_base;
        return ret_361;
    }
    alg_hold_top = rh_1989;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "ClassCounts"), "Contains", (Value[]){v_key}, 1)))))) {
        Value ret_362 = alg_literal("");
        alg_root_top = rt_base;
        return ret_362;
    }
    alg_hold_top = rh_1989;
    if (alg_truthy(alg_hold(alg_not_equal((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "ClassCounts"), "Get", (Value[]){v_key}, 1), ALG_KIND_INTEGER, "Integer"))), alg_int(1))))) {
        Value ret_363 = alg_literal("");
        alg_root_top = rt_base;
        return ret_363;
    }
    alg_hold_top = rh_1989;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){v_key}, 1)))) {
        Value ret_364 = alg_literal("");
        alg_root_top = rt_base;
        return ret_364;
    }
    alg_hold_top = rh_1989;
    if (alg_truthy(alg_hold(alg_greater_equal(alg_hold(f_subrangeindex(NULL, (Value[]){v_name}, 1)), alg_int(0))))) {
        Value ret_365 = alg_literal("");
        alg_root_top = rt_base;
        return ret_365;
    }
    alg_hold_top = rh_1989;
    {
        int32_t rt_1990 = alg_root_top;
        Value loop_366 = alg_iterable(alg_property(v_this, "EnumTypes"));
        (void)loop_366;
        alg_root(&loop_366, 1);
        for (int32_t at_366 = 0; at_366 < alg_iterable_count(loop_366); at_366++) {
            alg_safe_point();
            int32_t rt_1991 = alg_root_top;
            Value v_declared = alg_iterable_at(loop_366, at_366);
            (void)v_declared;
            alg_root(&v_declared, 1);
            if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){v_declared}, 1)), v_key)))) {
                Value ret_367 = alg_literal("");
                alg_root_top = rt_base;
                return ret_367;
            }
            alg_root_top = rt_1991;
        }
        alg_root_top = rt_1990;
    }
    alg_hold_top = rh_1989;
    Value ret_368 = alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Get", (Value[]){v_key}, 1)), "Name")), "Lexeme"))))}, 1));
    alg_root_top = rt_base;
    return ret_368;
    alg_hold_top = rh_1989;
    Value ret_369 = alg_nil();
    alg_root_top = rt_base;
    return ret_369;
}

static Value m_cemitter_visitisexpr_1_isexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "IsExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1992 = alg_hold_top;
    Value v_written = alg_nil();
    (void)v_written;
    alg_root(&v_written, 1);
    alg_hold_top = rh_1992;
    Value v_kind = alg_nil();
    (void)v_kind;
    alg_root(&v_kind, 1);
    alg_hold_top = rh_1992;
    Value v_handle = alg_nil();
    (void)v_handle;
    alg_root(&v_handle, 1);
    alg_hold_top = rh_1992;
    (void)((v_written = alg_hold(f_canonicaltype(NULL, (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "TypeName")), "Lexeme"))}, 1))));
    alg_hold_top = rh_1992;
    (void)((v_kind = alg_hold(alg_invoke(v_this, "ResolvedKind", (Value[]){v_written}, 1))));
    alg_hold_top = rh_1992;
    if (alg_truthy(alg_hold(alg_not_equal(v_kind, alg_literal(""))))) {
        Value ret_370 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_is_kind("), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)))), alg_literal(", "))), v_kind)), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_370;
    }
    alg_hold_top = rh_1992;
    (void)((v_handle = alg_hold(alg_invoke(v_this, "ResolvedClass", (Value[]){v_written}, 1))));
    alg_hold_top = rh_1992;
    if (alg_truthy(alg_hold(alg_not_equal(v_handle, alg_literal(""))))) {
        Value ret_371 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_is_class("), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)))), alg_literal(", "))), v_handle)), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_371;
    }
    alg_hold_top = rh_1992;
    Value ret_372 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_is("), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){v_written}, 1)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_372;
    alg_hold_top = rh_1992;
    Value ret_373 = alg_nil();
    alg_root_top = rt_base;
    return ret_373;
}

static Value m_cemitter_visitunary_1_unaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "UnaryExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1993 = alg_hold_top;
    Value v_operand = alg_nil();
    (void)v_operand;
    alg_root(&v_operand, 1);
    alg_hold_top = rh_1993;
    (void)((v_operand = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1))));
    alg_hold_top = rh_1993;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVminus)))) {
        Value ret_374 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_negate("), v_operand)), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_374;
    } else {
        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVnot)))) {
            Value ret_375 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_not("), v_operand)), alg_char_value(41)));
            alg_root_top = rt_base;
            return ret_375;
        } else {
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVtilde)))) {
                Value ret_376 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_bit_not("), v_operand)), alg_char_value(41)));
                alg_root_top = rt_base;
                return ret_376;
            }
        }
    }
    alg_hold_top = rh_1993;
    (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("Unary '"), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "Lexeme")))))), alg_char_value(39)))}, 1)));
    alg_hold_top = rh_1993;
    Value ret_377 = alg_nil();
    alg_root_top = rt_base;
    return ret_377;
}

static Value m_cemitter_visitbinary_1_binaryexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "BinaryExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_1994 = alg_hold_top;
    Value v_left = alg_nil();
    (void)v_left;
    alg_root(&v_left, 1);
    alg_hold_top = rh_1994;
    Value v_right = alg_nil();
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_1994;
    Value v_call = alg_nil();
    (void)v_call;
    alg_root(&v_call, 1);
    alg_hold_top = rh_1994;
    (void)((v_left = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Left"))}, 1))));
    alg_hold_top = rh_1994;
    (void)((v_right = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1))));
    alg_hold_top = rh_1994;
    (void)((v_call = alg_literal("")));
    alg_hold_top = rh_1994;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVplus)))) {
        (void)((v_call = alg_literal("alg_add")));
    } else {
        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVminus)))) {
            (void)((v_call = alg_literal("alg_subtract")));
        } else {
            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVstar)))) {
                (void)((v_call = alg_literal("alg_multiply")));
            } else {
                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVslash)))) {
                    (void)((v_call = alg_literal("alg_divide")));
                } else {
                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVdiv)))) {
                        (void)((v_call = alg_literal("alg_div_int")));
                    } else {
                        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVmod)))) {
                            (void)((v_call = alg_literal("alg_mod")));
                        } else {
                            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVgreater)))) {
                                (void)((v_call = alg_literal("alg_greater")));
                            } else {
                                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVgreaterVequal)))) {
                                    (void)((v_call = alg_literal("alg_greater_equal")));
                                } else {
                                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVless)))) {
                                        (void)((v_call = alg_literal("alg_less")));
                                    } else {
                                        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVlessVequal)))) {
                                            (void)((v_call = alg_literal("alg_less_equal")));
                                        } else {
                                            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVequal)))) {
                                                (void)((v_call = alg_literal("alg_equal")));
                                            } else {
                                                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVnotVequal)))) {
                                                    (void)((v_call = alg_literal("alg_not_equal")));
                                                } else {
                                                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVin)))) {
                                                        (void)((v_call = alg_literal("alg_in")));
                                                    } else {
                                                        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVampersand)))) {
                                                            (void)((v_call = alg_literal("alg_bit_and")));
                                                        } else {
                                                            if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVpipe)))) {
                                                                (void)((v_call = alg_literal("alg_bit_or")));
                                                            } else {
                                                                if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVcaret)))) {
                                                                    (void)((v_call = alg_literal("alg_bit_xor")));
                                                                } else {
                                                                    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVshiftVleft)))) {
                                                                        (void)((v_call = alg_literal("alg_shift_left")));
                                                                    } else {
                                                                        if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVshiftVright)))) {
                                                                            (void)((v_call = alg_literal("alg_shift_right")));
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
    alg_hold_top = rh_1994;
    if (alg_truthy(alg_hold(alg_equal(v_call, alg_literal(""))))) {
        (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("Binary '"), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "Lexeme")))))), alg_char_value(39)))}, 1)));
    }
    alg_hold_top = rh_1994;
    Value ret_378 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_call, alg_char_value(40))), v_left)), alg_literal(", "))), v_right)), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_378;
    alg_hold_top = rh_1994;
    Value ret_379 = alg_nil();
    alg_root_top = rt_base;
    return ret_379;
}

static Value m_cemitter_builtincounts_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_1995 = alg_hold_top;
    Value v_counts = alg_nil();
    (void)v_counts;
    alg_root(&v_counts, 1);
    alg_hold_top = rh_1995;
    (void)((v_counts = alg_hold(alg_list())));
    alg_hold_top = rh_1995;
    {
        int32_t rt_1996 = alg_root_top;
        int32_t rh_1997 = alg_hold_top;
        Value v_k = alg_int(0);
        (void)v_k;
        alg_root(&v_k, 1);
        alg_hold_top = rh_1997;
        {
            int32_t rh_1998 = alg_hold_top;
            for (; (alg_hold_top = rh_1998, alg_truthy(alg_hold(alg_less_equal(v_k, alg_int(3))))); (alg_hold_top = rh_1998, (v_k = alg_hold(alg_add(v_k, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_1999 = alg_root_top;
                    int32_t rh_2000 = alg_hold_top;
                    Value v_probe = alg_hold(alg_list());
                    (void)v_probe;
                    alg_root(&v_probe, 1);
                    alg_hold_top = rh_2000;
                    {
                        int32_t rt_2001 = alg_root_top;
                        int32_t rh_2002 = alg_hold_top;
                        Value v_i = alg_int(0);
                        (void)v_i;
                        alg_root(&v_i, 1);
                        alg_hold_top = rh_2002;
                        {
                            int32_t rh_2003 = alg_hold_top;
                            for (; (alg_hold_top = rh_2003, alg_truthy(alg_hold(alg_less(v_i, v_k)))); (alg_hold_top = rh_2003, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                                alg_safe_point();
                                (void)(alg_hold(alg_invoke(v_probe, "Add", (Value[]){alg_char_value(48)}, 1)));
                            }
                        }
                        alg_hold_top = rh_2002;
                        alg_root_top = rt_2001;
                    }
                    alg_hold_top = rh_2000;
                    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_invoke(v_this, "Builtin", (Value[]){v_name, v_k}, 2)), alg_literal(""))))) {
                        (void)(alg_hold(alg_invoke(v_counts, "Add", (Value[]){v_k}, 1)));
                    } else {
                        if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_invoke(v_this, "ConstructorFor", (Value[]){v_name, v_probe, alg_char_value(48)}, 3)), alg_literal(""))))) {
                            (void)(alg_hold(alg_invoke(v_counts, "Add", (Value[]){v_k}, 1)));
                        }
                    }
                    alg_hold_top = rh_2000;
                    alg_root_top = rt_1999;
                }
            }
        }
        alg_hold_top = rh_1997;
        alg_root_top = rt_1996;
    }
    alg_hold_top = rh_1995;
    Value ret_380 = v_counts;
    alg_root_top = rt_base;
    return ret_380;
    alg_hold_top = rh_1995;
    Value ret_381 = alg_nil();
    alg_root_top = rt_base;
    return ret_381;
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
    int32_t rh_2004 = alg_hold_top;
    Value v_expected = alg_nil();
    (void)v_expected;
    alg_root(&v_expected, 1);
    alg_hold_top = rh_2004;
    (void)((v_expected = alg_literal("")));
    alg_hold_top = rh_2004;
    {
        int32_t rt_2005 = alg_root_top;
        int32_t rh_2006 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2006;
        {
            int32_t rh_2007 = alg_hold_top;
            for (; (alg_hold_top = rh_2007, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_counts, "Length")))))); (alg_hold_top = rh_2007, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_2008 = alg_hold_top;
                    if (alg_truthy(alg_hold(alg_greater(v_i, alg_int(0))))) {
                        {
                            int32_t rh_2009 = alg_hold_top;
                            if (alg_truthy(alg_hold(alg_equal(v_i, alg_hold(alg_subtract(alg_hold(alg_property(v_counts, "Length")), alg_int(1))))))) {
                                (void)((v_expected = alg_hold(alg_add(v_expected, alg_literal(" or ")))));
                            } else {
                                (void)((v_expected = alg_hold(alg_add(v_expected, alg_literal(", ")))));
                            }
                            alg_hold_top = rh_2009;
                        }
                    }
                    alg_hold_top = rh_2008;
                    (void)((v_expected = alg_hold(alg_add(v_expected, alg_hold(alg_str(alg_hold(alg_subscript_get(v_counts, v_i))))))));
                    alg_hold_top = rh_2008;
                }
            }
        }
        alg_hold_top = rh_2006;
        alg_root_top = rt_2005;
    }
    alg_hold_top = rh_2004;
    Value ret_382 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Expected "), v_expected)), alg_literal(" arguments but got "))), alg_hold(alg_str(v_got)))), alg_char_value(46)));
    alg_root_top = rt_base;
    return ret_382;
    alg_hold_top = rh_2004;
    Value ret_383 = alg_nil();
    alg_root_top = rt_base;
    return ret_383;
}

static Value m_cemitter_countsphrase_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_counts = alg_widen(args[0], "List");
    (void)v_counts;
    alg_root(&v_counts, 1);
    int32_t rh_2010 = alg_hold_top;
    Value v_expected = alg_nil();
    (void)v_expected;
    alg_root(&v_expected, 1);
    alg_hold_top = rh_2010;
    (void)((v_expected = alg_literal("")));
    alg_hold_top = rh_2010;
    {
        int32_t rt_2011 = alg_root_top;
        int32_t rh_2012 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2012;
        {
            int32_t rh_2013 = alg_hold_top;
            for (; (alg_hold_top = rh_2013, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_counts, "Length")))))); (alg_hold_top = rh_2013, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_2014 = alg_hold_top;
                    if (alg_truthy(alg_hold(alg_greater(v_i, alg_int(0))))) {
                        {
                            int32_t rh_2015 = alg_hold_top;
                            if (alg_truthy(alg_hold(alg_equal(v_i, alg_hold(alg_subtract(alg_hold(alg_property(v_counts, "Length")), alg_int(1))))))) {
                                (void)((v_expected = alg_hold(alg_add(v_expected, alg_literal(" or ")))));
                            } else {
                                (void)((v_expected = alg_hold(alg_add(v_expected, alg_literal(", ")))));
                            }
                            alg_hold_top = rh_2015;
                        }
                    }
                    alg_hold_top = rh_2014;
                    (void)((v_expected = alg_hold(alg_add(v_expected, alg_hold(alg_str(alg_hold(alg_subscript_get(v_counts, v_i))))))));
                    alg_hold_top = rh_2014;
                }
            }
        }
        alg_hold_top = rh_2012;
        alg_root_top = rt_2011;
    }
    alg_hold_top = rh_2010;
    Value ret_384 = v_expected;
    alg_root_top = rt_base;
    return ret_384;
    alg_hold_top = rh_2010;
    Value ret_385 = alg_nil();
    alg_root_top = rt_base;
    return ret_385;
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
    int32_t rh_2016 = alg_hold_top;
    Value v_only = alg_nil();
    (void)v_only;
    alg_root(&v_only, 1);
    alg_hold_top = rh_2016;
    (void)((v_only = alg_hold(alg_map())));
    alg_hold_top = rh_2016;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Renamed"), "Contains", (Value[]){v_name}, 1)))) {
        (void)(alg_hold(alg_invoke(v_only, "Put", (Value[]){v_name, v_unit}, 2)));
    }
    alg_hold_top = rh_2016;
    Value ret_386 = v_only;
    alg_root_top = rt_base;
    return ret_386;
    alg_hold_top = rh_2016;
    Value ret_387 = alg_nil();
    alg_root_top = rt_base;
    return ret_387;
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
    int32_t rh_2017 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Contains", (Value[]){v_name}, 1)))))) {
        {
            int32_t rh_2018 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Put", (Value[]){v_name, alg_hold(alg_add(alg_hold(alg_add(v_first, alg_literal(" or "))), v_second))}, 2)));
            alg_hold_top = rh_2018;
            Value ret_388 = alg_nil();
            alg_root_top = rt_base;
            return ret_388;
            alg_hold_top = rh_2018;
        }
    }
    alg_hold_top = rh_2017;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Put", (Value[]){v_name, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Get", (Value[]){v_name}, 1)))), alg_literal(" or "))), v_second))}, 2)));
    alg_hold_top = rh_2017;
    Value ret_389 = alg_nil();
    alg_root_top = rt_base;
    return ret_389;
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
    int32_t rh_2019 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Contains", (Value[]){v_member}, 1)))))) {
        {
            int32_t rh_2020 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Put", (Value[]){v_member, alg_hold(alg_add(alg_hold(alg_add(v_first, alg_literal(" or "))), v_second))}, 2)));
            alg_hold_top = rh_2020;
            Value ret_390 = alg_nil();
            alg_root_top = rt_base;
            return ret_390;
            alg_hold_top = rh_2020;
        }
    }
    alg_hold_top = rh_2019;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Put", (Value[]){v_member, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Get", (Value[]){v_member}, 1)))), alg_literal(" or "))), v_second))}, 2)));
    alg_hold_top = rh_2019;
    Value ret_391 = alg_nil();
    alg_root_top = rt_base;
    return ret_391;
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
    int32_t rh_2021 = alg_hold_top;
    Value ret_392 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), v_written)), alg_literal("' is ambiguous: "))), v_owners)), alg_char_value(46)));
    alg_root_top = rt_base;
    return ret_392;
    alg_hold_top = rh_2021;
    Value ret_393 = alg_nil();
    alg_root_top = rt_base;
    return ret_393;
}

static Value m_cemitter_isassertion_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_2022 = alg_hold_top;
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    alg_hold_top = rh_2022;
    (void)((v_folded = alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))));
    alg_hold_top = rh_2022;
    Value ret_394 = alg_hold((or_75 = alg_hold((or_74 = alg_hold(alg_equal(v_folded, alg_literal("asserttrue"))), alg_truthy(or_74) ? or_74 : alg_hold(alg_equal(v_folded, alg_literal("assertequal"))))), alg_truthy(or_75) ? or_75 : alg_hold(alg_equal(v_folded, alg_literal("fail")))));
    alg_root_top = rt_base;
    return ret_394;
    alg_hold_top = rh_2022;
    Value ret_395 = alg_nil();
    alg_root_top = rt_base;
    return ret_395;
}

static Value m_cemitter_builtinhandle_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_2023 = alg_hold_top;
    Value v_counts = alg_nil();
    (void)v_counts;
    alg_root(&v_counts, 1);
    alg_hold_top = rh_2023;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    alg_hold_top = rh_2023;
    (void)((v_counts = alg_hold(alg_invoke(v_this, "BuiltinCounts", (Value[]){v_name}, 1))));
    alg_hold_top = rh_2023;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_counts, "Length")), alg_int(0))))) {
        Value ret_396 = alg_literal("");
        alg_root_top = rt_base;
        return ret_396;
    }
    alg_hold_top = rh_2023;
    (void)((v_symbol = alg_hold(alg_invoke(v_this, "Mangle", (Value[]){alg_literal("bq_"), v_name}, 2))));
    alg_hold_top = rh_2023;
    if (alg_truthy(alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "BuiltinThunks"), "Contains", (Value[]){v_symbol}, 1)))))) {
        {
            int32_t rh_2024 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "BuiltinThunks"), "Add", (Value[]){v_symbol}, 1)));
            alg_hold_top = rh_2024;
            (void)(alg_hold(alg_invoke(v_this, "EmitBuiltinThunk", (Value[]){v_symbol, v_name, v_counts}, 3)));
            alg_hold_top = rh_2024;
        }
    }
    alg_hold_top = rh_2023;
    Value ret_397 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_builtin("), alg_hold(f_quotec(NULL, (Value[]){v_name}, 1)))), alg_literal(", "))), v_symbol)), alg_literal(", ALG_ANY_ARITY, NULL)")));
    alg_root_top = rt_base;
    return ret_397;
    alg_hold_top = rh_2023;
    Value ret_398 = alg_nil();
    alg_root_top = rt_base;
    return ret_398;
}

static Value m_cemitter_emitbuiltinthunk_3_string_string_list(Value v_this, Value *args, int32_t count) {
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
    Value v_counts = alg_widen(args[2], "List");
    (void)v_counts;
    alg_root(&v_counts, 1);
    int32_t rh_2025 = alg_hold_top;
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    alg_hold_top = rh_2025;
    (void)((v_folded = alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))));
    alg_hold_top = rh_2025;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static Value "), v_symbol)), alg_literal("(Value **cells, Value *args, int32_t count) {"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_2025;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    (void)cells;"), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_2025;
    if (alg_truthy(alg_hold((or_77 = alg_hold((or_76 = alg_hold(alg_equal(v_folded, alg_literal("write"))), alg_truthy(or_76) ? or_76 : alg_hold(alg_equal(v_folded, alg_literal("writeln"))))), alg_truthy(or_77) ? or_77 : alg_hold(alg_equal(v_folded, alg_literal("errorln"))))))) {
        {
            int32_t rh_2026 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(v_folded, alg_literal("writeln"))))) {
                (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    if (count == 0) { alg_writeln_blank(); return alg_nil(); }"), alg_char_value(10)))}, 1)));
            } else {
                if (alg_truthy(alg_hold(alg_equal(v_folded, alg_literal("errorln"))))) {
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    if (count == 0) { alg_stderr_line(alg_literal(\"\")); return alg_nil(); }"), alg_char_value(10)))}, 1)));
                } else {
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    if (count == 0) return alg_nil();"), alg_char_value(10)))}, 1)));
                }
            }
            alg_hold_top = rh_2026;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    Value joined = alg_str(args[0]);"), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_2026;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    for (int32_t i = 1; i < count; i++)"), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_2026;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("        joined = alg_add(joined, alg_str(args[i]));"), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_2026;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    "), alg_hold(alg_invoke(v_this, "Builtin", (Value[]){v_name, alg_int(1)}, 2)))), alg_literal("(joined);"))), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_2026;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    return alg_nil();"), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_2026;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_char_value(125), alg_char_value(10))), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_2026;
            Value ret_399 = alg_nil();
            alg_root_top = rt_base;
            return ret_399;
            alg_hold_top = rh_2026;
        }
    }
    alg_hold_top = rh_2025;
    {
        int32_t rt_2027 = alg_root_top;
        int32_t rh_2028 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2028;
        {
            int32_t rh_2029 = alg_hold_top;
            for (; (alg_hold_top = rh_2029, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_counts, "Length")))))); (alg_hold_top = rh_2029, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rt_2030 = alg_root_top;
                    int32_t rh_2031 = alg_hold_top;
                    Value v_count = alg_hold(alg_cast_kind(alg_subscript_get(v_counts, v_i), ALG_KIND_INTEGER, "Integer"));
                    (void)v_count;
                    alg_root(&v_count, 1);
                    alg_hold_top = rh_2031;
                    Value v_passed = alg_literal("");
                    (void)v_passed;
                    alg_root(&v_passed, 1);
                    alg_hold_top = rh_2031;
                    {
                        int32_t rt_2032 = alg_root_top;
                        int32_t rh_2033 = alg_hold_top;
                        Value v_a = alg_int(0);
                        (void)v_a;
                        alg_root(&v_a, 1);
                        alg_hold_top = rh_2033;
                        {
                            int32_t rh_2034 = alg_hold_top;
                            for (; (alg_hold_top = rh_2034, alg_truthy(alg_hold(alg_less(v_a, v_count)))); (alg_hold_top = rh_2034, (v_a = alg_hold(alg_add(v_a, alg_int(1)))))) {
                                alg_safe_point();
                                {
                                    int32_t rh_2035 = alg_hold_top;
                                    if (alg_truthy(alg_hold(alg_greater(v_a, alg_int(0))))) {
                                        (void)((v_passed = alg_hold(alg_add(v_passed, alg_literal(", ")))));
                                    }
                                    alg_hold_top = rh_2035;
                                    (void)((v_passed = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_passed, alg_literal("args["))), alg_hold(alg_str(v_a)))), alg_char_value(93)))));
                                    alg_hold_top = rh_2035;
                                }
                            }
                        }
                        alg_hold_top = rh_2033;
                        alg_root_top = rt_2032;
                    }
                    alg_hold_top = rh_2031;
                    if (alg_truthy(alg_hold(alg_invoke(v_this, "VoidBuiltin", (Value[]){v_name}, 1)))) {
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    if (count == "), alg_hold(alg_str(v_count)))), alg_literal(") { "))), alg_hold(alg_invoke(v_this, "Builtin", (Value[]){v_name, v_count}, 2)))), alg_char_value(40))), v_passed)), alg_literal("); return alg_nil(); }"))), alg_char_value(10)))}, 1)));
                    } else {
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    if (count == "), alg_hold(alg_str(v_count)))), alg_literal(") return "))), alg_hold(alg_invoke(v_this, "Builtin", (Value[]){v_name, v_count}, 2)))), alg_char_value(40))), v_passed)), alg_literal(");"))), alg_char_value(10)))}, 1)));
                    }
                    alg_hold_top = rh_2031;
                    alg_root_top = rt_2030;
                }
            }
        }
        alg_hold_top = rh_2028;
        alg_root_top = rt_2027;
    }
    alg_hold_top = rh_2025;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_counts, "Length")), alg_int(1))))) {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    alg_arity(count, "), alg_hold(alg_str(alg_hold(alg_subscript_get(v_counts, alg_int(0))))))), alg_literal(");"))), alg_char_value(10)))}, 1)));
    } else {
        (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    alg_arity_counts(count, "), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_invoke(v_this, "CountsPhrase", (Value[]){v_counts}, 1))}, 1)))), alg_literal(");"))), alg_char_value(10)))}, 1)));
    }
    alg_hold_top = rh_2025;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    return alg_nil();"), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_2025;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_char_value(125), alg_char_value(10))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_2025;
    Value ret_400 = alg_nil();
    alg_root_top = rt_base;
    return ret_400;
}

static Value m_cemitter_voidbuiltin_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_name = alg_widen(args[0], "String");
    (void)v_name;
    alg_root(&v_name, 1);
    int32_t rh_2036 = alg_hold_top;
    Value v_folded = alg_nil();
    (void)v_folded;
    alg_root(&v_folded, 1);
    alg_hold_top = rh_2036;
    (void)((v_folded = alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))));
    alg_hold_top = rh_2036;
    Value ret_401 = alg_hold((or_80 = alg_hold((or_79 = alg_hold((or_78 = alg_hold(alg_equal(v_folded, alg_literal("write"))), alg_truthy(or_78) ? or_78 : alg_hold(alg_equal(v_folded, alg_literal("writeln"))))), alg_truthy(or_79) ? or_79 : alg_hold(alg_equal(v_folded, alg_literal("errorln"))))), alg_truthy(or_80) ? or_80 : alg_hold(alg_equal(v_folded, alg_literal("halt")))));
    alg_root_top = rt_base;
    return ret_401;
    alg_hold_top = rh_2036;
    Value ret_402 = alg_nil();
    alg_root_top = rt_base;
    return ret_402;
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
    int32_t rh_2037 = alg_hold_top;
    Value v_key = alg_nil();
    (void)v_key;
    alg_root(&v_key, 1);
    alg_hold_top = rh_2037;
    (void)((v_key = alg_hold(alg_add(alg_hold(alg_add(alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1)), alg_char_value(47))), alg_hold(alg_str(v_count))))));
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("errorln/1"))))) {
        Value ret_403 = alg_literal("alg_stderr_line");
        alg_root_top = rt_base;
        return ret_403;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("writeln/1"))))) {
        Value ret_404 = alg_literal("alg_writeln");
        alg_root_top = rt_base;
        return ret_404;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("writeln/0"))))) {
        Value ret_405 = alg_literal("alg_writeln_blank");
        alg_root_top = rt_base;
        return ret_405;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("write/1"))))) {
        Value ret_406 = alg_literal("alg_write");
        alg_root_top = rt_base;
        return ret_406;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("str/1"))))) {
        Value ret_407 = alg_literal("alg_str");
        alg_root_top = rt_base;
        return ret_407;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("str/2"))))) {
        Value ret_408 = alg_literal("alg_str_fixed");
        alg_root_top = rt_base;
        return ret_408;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("str/3"))))) {
        Value ret_409 = alg_literal("alg_str_padded");
        alg_root_top = rt_base;
        return ret_409;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("fields/1"))))) {
        Value ret_410 = alg_literal("alg_fields");
        alg_root_top = rt_base;
        return ret_410;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("typeof/1"))))) {
        Value ret_411 = alg_literal("alg_type_of");
        alg_root_top = rt_base;
        return ret_411;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("member/2"))))) {
        Value ret_412 = alg_literal("alg_member");
        alg_root_top = rt_base;
        return ret_412;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("invoke/3"))))) {
        Value ret_413 = alg_literal("alg_invoke_by_name");
        alg_root_top = rt_base;
        return ret_413;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("new/2"))))) {
        Value ret_414 = alg_literal("alg_construct");
        alg_root_top = rt_base;
        return ret_414;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("setmember/3"))))) {
        Value ret_415 = alg_literal("alg_set_member");
        alg_root_top = rt_base;
        return ret_415;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("length/1"))))) {
        Value ret_416 = alg_literal("alg_text_length");
        alg_root_top = rt_base;
        return ret_416;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("copy/3"))))) {
        Value ret_417 = alg_literal("alg_copy");
        alg_root_top = rt_base;
        return ret_417;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("pos/2"))))) {
        Value ret_418 = alg_literal("alg_pos");
        alg_root_top = rt_base;
        return ret_418;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("pos/3"))))) {
        Value ret_419 = alg_literal("alg_pos_from");
        alg_root_top = rt_base;
        return ret_419;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("toupper/1"))))) {
        Value ret_420 = alg_literal("alg_to_upper");
        alg_root_top = rt_base;
        return ret_420;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("tolower/1"))))) {
        Value ret_421 = alg_literal("alg_to_lower");
        alg_root_top = rt_base;
        return ret_421;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("char/1"))))) {
        Value ret_422 = alg_literal("alg_char");
        alg_root_top = rt_base;
        return ret_422;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("ord/1"))))) {
        Value ret_423 = alg_literal("alg_ord");
        alg_root_top = rt_base;
        return ret_423;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("val/1"))))) {
        Value ret_424 = alg_literal("alg_val");
        alg_root_top = rt_base;
        return ret_424;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("succ/1"))))) {
        Value ret_425 = alg_literal("alg_succ");
        alg_root_top = rt_base;
        return ret_425;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("pred/1"))))) {
        Value ret_426 = alg_literal("alg_pred");
        alg_root_top = rt_base;
        return ret_426;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("foreign/5"))))) {
        Value ret_427 = alg_literal("alg_foreign_call");
        alg_root_top = rt_base;
        return ret_427;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("clock/0"))))) {
        Value ret_428 = alg_literal("alg_clock");
        alg_root_top = rt_base;
        return ret_428;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("collect/0"))))) {
        Value ret_429 = alg_literal("alg_collected");
        alg_root_top = rt_base;
        return ret_429;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("halt/1"))))) {
        Value ret_430 = alg_literal("alg_halt");
        alg_root_top = rt_base;
        return ret_430;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_property(v_this, "EmitTests"))) {
        {
            int32_t rh_2038 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("asserttrue/1"))))) {
                Value ret_431 = alg_literal("alg_assert_true");
                alg_root_top = rt_base;
                return ret_431;
            }
            alg_hold_top = rh_2038;
            if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("assertequal/2"))))) {
                Value ret_432 = alg_literal("alg_assert_equal");
                alg_root_top = rt_base;
                return ret_432;
            }
            alg_hold_top = rh_2038;
            if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("fail/1"))))) {
                Value ret_433 = alg_literal("alg_assert_fail");
                alg_root_top = rt_base;
                return ret_433;
            }
            alg_hold_top = rh_2038;
        }
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("fileexists/1"))))) {
        Value ret_434 = alg_literal("alg_file_exists");
        alg_root_top = rt_base;
        return ret_434;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("mkdir/1"))))) {
        Value ret_435 = alg_literal("alg_mkdir");
        alg_root_top = rt_base;
        return ret_435;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("rmdir/1"))))) {
        Value ret_436 = alg_literal("alg_rmdir");
        alg_root_top = rt_base;
        return ret_436;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("chdir/1"))))) {
        Value ret_437 = alg_literal("alg_chdir");
        alg_root_top = rt_base;
        return ret_437;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("getdir/0"))))) {
        Value ret_438 = alg_literal("alg_getdir");
        alg_root_top = rt_base;
        return ret_438;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("paramcount/0"))))) {
        Value ret_439 = alg_literal("alg_param_count");
        alg_root_top = rt_base;
        return ret_439;
    }
    alg_hold_top = rh_2037;
    if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("paramstr/1"))))) {
        Value ret_440 = alg_literal("alg_param_str");
        alg_root_top = rt_base;
        return ret_440;
    }
    alg_hold_top = rh_2037;
    Value ret_441 = alg_literal("");
    alg_root_top = rt_base;
    return ret_441;
    alg_hold_top = rh_2037;
    Value ret_442 = alg_nil();
    alg_root_top = rt_base;
    return ret_442;
}

static Value m_cemitter_joiningbuiltin_2_string_list(Value v_this, Value *args, int32_t count) {
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
    int32_t rh_2039 = alg_hold_top;
    Value v_one = alg_nil();
    (void)v_one;
    alg_root(&v_one, 1);
    alg_hold_top = rh_2039;
    (void)((v_one = alg_hold(alg_invoke(v_this, "Builtin", (Value[]){v_name, alg_int(1)}, 2))));
    alg_hold_top = rh_2039;
    if (alg_truthy(alg_hold((or_82 = alg_hold((or_81 = alg_hold(alg_not_equal(v_one, alg_literal("alg_writeln"))), !alg_truthy(or_81) ? or_81 : alg_hold(alg_not_equal(v_one, alg_literal("alg_write"))))), !alg_truthy(or_82) ? or_82 : alg_hold(alg_not_equal(v_one, alg_literal("alg_stderr_line"))))))) {
        Value ret_443 = alg_literal("");
        alg_root_top = rt_base;
        return ret_443;
    }
    alg_hold_top = rh_2039;
    if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(v_arguments, "Length")), alg_int(1))))) {
        Value ret_444 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_one, alg_char_value(40))), alg_hold(alg_invoke(v_this, "RunTogether", (Value[]){v_arguments}, 1)))), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_444;
    }
    alg_hold_top = rh_2039;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(0))))) {
        {
            int32_t rh_2040 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(v_one, alg_literal("alg_writeln"))))) {
                Value ret_445 = alg_literal("alg_writeln_blank()");
                alg_root_top = rt_base;
                return ret_445;
            }
            alg_hold_top = rh_2040;
            Value ret_446 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_one, alg_literal("(alg_literal("))), alg_hold(f_quotec(NULL, (Value[]){alg_literal("")}, 1)))), alg_literal("))")));
            alg_root_top = rt_base;
            return ret_446;
            alg_hold_top = rh_2040;
        }
    }
    alg_hold_top = rh_2039;
    Value ret_447 = alg_literal("");
    alg_root_top = rt_base;
    return ret_447;
    alg_hold_top = rh_2039;
    Value ret_448 = alg_nil();
    alg_root_top = rt_base;
    return ret_448;
}

static Value m_cemitter_runtogether_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    int32_t rh_2041 = alg_hold_top;
    Value v_result = alg_nil();
    (void)v_result;
    alg_root(&v_result, 1);
    alg_hold_top = rh_2041;
    (void)((v_result = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_str("), alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, alg_int(0))))))), alg_char_value(41)))));
    alg_hold_top = rh_2041;
    {
        int32_t rt_2042 = alg_root_top;
        int32_t rh_2043 = alg_hold_top;
        Value v_i = alg_int(1);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2043;
        {
            int32_t rh_2044 = alg_hold_top;
            for (; (alg_hold_top = rh_2044, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_arguments, "Length")))))); (alg_hold_top = rh_2044, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                (void)((v_result = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_add("), v_result)), alg_literal(", alg_str("))), alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, v_i)))))), alg_literal("))")))));
            }
        }
        alg_hold_top = rh_2043;
        alg_root_top = rt_2042;
    }
    alg_hold_top = rh_2041;
    Value ret_449 = v_result;
    alg_root_top = rt_base;
    return ret_449;
    alg_hold_top = rh_2041;
    Value ret_450 = alg_nil();
    alg_root_top = rt_base;
    return ret_450;
}

static Value m_cemitter_anynamed_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_names = alg_widen(args[0], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    int32_t rh_2045 = alg_hold_top;
    {
        int32_t rt_2046 = alg_root_top;
        Value loop_451 = alg_iterable(v_names);
        (void)loop_451;
        alg_root(&loop_451, 1);
        for (int32_t at_451 = 0; at_451 < alg_iterable_count(loop_451); at_451++) {
            alg_safe_point();
            int32_t rt_2047 = alg_root_top;
            Value v_name = alg_iterable_at(loop_451, at_451);
            (void)v_name;
            alg_root(&v_name, 1);
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_str(v_name)), alg_literal(""))))) {
                Value ret_452 = alg_bool(true);
                alg_root_top = rt_base;
                return ret_452;
            }
            alg_root_top = rt_2047;
        }
        alg_root_top = rt_2046;
    }
    alg_hold_top = rh_2045;
    Value ret_453 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_453;
    alg_hold_top = rh_2045;
    Value ret_454 = alg_nil();
    alg_root_top = rt_base;
    return ret_454;
}

static Value m_cemitter_namearray_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_names = alg_widen(args[0], "List");
    (void)v_names;
    alg_root(&v_names, 1);
    int32_t rh_2048 = alg_hold_top;
    Value v_joined = alg_literal("");
    (void)v_joined;
    alg_root(&v_joined, 1);
    alg_hold_top = rh_2048;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_names, "Length")), alg_int(0))))) {
        Value ret_455 = alg_literal("NULL");
        alg_root_top = rt_base;
        return ret_455;
    }
    alg_hold_top = rh_2048;
    {
        int32_t rt_2049 = alg_root_top;
        int32_t rh_2050 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2050;
        {
            int32_t rh_2051 = alg_hold_top;
            for (; (alg_hold_top = rh_2051, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_names, "Length")))))); (alg_hold_top = rh_2051, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_2052 = alg_hold_top;
                    if (alg_truthy(alg_hold(alg_greater(v_i, alg_int(0))))) {
                        (void)((v_joined = alg_hold(alg_add(v_joined, alg_literal(", ")))));
                    }
                    alg_hold_top = rh_2052;
                    (void)((v_joined = alg_hold(alg_add(v_joined, alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_names, v_i))))}, 1))))));
                    alg_hold_top = rh_2052;
                }
            }
        }
        alg_hold_top = rh_2050;
        alg_root_top = rt_2049;
    }
    alg_hold_top = rh_2048;
    Value ret_456 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(const char*[]){"), v_joined)), alg_char_value(125)));
    alg_root_top = rt_base;
    return ret_456;
    alg_hold_top = rh_2048;
    Value ret_457 = alg_nil();
    alg_root_top = rt_base;
    return ret_457;
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
    int32_t rh_2053 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(f_anynamed(NULL, (Value[]){v_names}, 1)))))) {
        Value ret_458 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_call("), v_callee)), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)))), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_458;
    }
    alg_hold_top = rh_2053;
    Value ret_459 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_call_named("), v_callee)), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "NameArray", (Value[]){v_names}, 1)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_459;
    alg_hold_top = rh_2053;
    Value ret_460 = alg_nil();
    alg_root_top = rt_base;
    return ret_460;
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
    int32_t rh_2054 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(f_anynamed(NULL, (Value[]){v_names}, 1)))))) {
        Value ret_461 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_new("), v_handle)), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)))), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_461;
    }
    alg_hold_top = rh_2054;
    Value ret_462 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_new_named("), v_handle)), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "NameArray", (Value[]){v_names}, 1)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_462;
    alg_hold_top = rh_2054;
    Value ret_463 = alg_nil();
    alg_root_top = rt_base;
    return ret_463;
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
    int32_t rh_2055 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(f_anynamed(NULL, (Value[]){v_names}, 1)))))) {
        Value ret_464 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_invoke("), v_receiver)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){v_thename}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)))), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_464;
    }
    alg_hold_top = rh_2055;
    Value ret_465 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_invoke_named("), v_receiver)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){v_thename}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "NameArray", (Value[]){v_names}, 1)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_465;
    alg_hold_top = rh_2055;
    Value ret_466 = alg_nil();
    alg_root_top = rt_base;
    return ret_466;
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
    int32_t rh_2056 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_hold(f_anynamed(NULL, (Value[]){v_names}, 1)))))) {
        Value ret_467 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_invoke_or("), v_receiver)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){v_thename}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)))), alg_literal(", "))), v_extension)), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_467;
    }
    alg_hold_top = rh_2056;
    Value ret_468 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_invoke_or_named("), v_receiver)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){v_thename}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "NameArray", (Value[]){v_names}, 1)))), alg_literal(", "))), v_extension)), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_468;
    alg_hold_top = rh_2056;
    Value ret_469 = alg_nil();
    alg_root_top = rt_base;
    return ret_469;
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
    int32_t rh_2057 = alg_hold_top;
    Value v_theirs = alg_nil();
    (void)v_theirs;
    alg_root(&v_theirs, 1);
    alg_hold_top = rh_2057;
    {
        int32_t rt_2058 = alg_root_top;
        Value loop_470 = alg_iterable(alg_hold(alg_invoke(alg_property(v_this, "OverloadsIn"), "Keys", NULL, 0)));
        (void)loop_470;
        alg_root(&loop_470, 1);
        for (int32_t at_470 = 0; at_470 < alg_iterable_count(loop_470); at_470++) {
            alg_safe_point();
            int32_t rt_2059 = alg_root_top;
            Value v_key = alg_iterable_at(loop_470, at_470);
            (void)v_key;
            alg_root(&v_key, 1);
            {
                int32_t rh_2060 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_not_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(v_key))}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_unit}, 1)))))) {
                    continue;
                }
                alg_hold_top = rh_2060;
                (void)((v_theirs = alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "OverloadsIn"), "Get", (Value[]){v_key}, 1), ALG_KIND_SET, "Set"))));
                alg_hold_top = rh_2060;
                {
                    int32_t rt_2061 = alg_root_top;
                    Value loop_471 = alg_iterable(alg_hold(alg_invoke(v_theirs, "ToList", NULL, 0)));
                    (void)loop_471;
                    alg_root(&loop_471, 1);
                    for (int32_t at_471 = 0; at_471 < alg_iterable_count(loop_471); at_471++) {
                        alg_safe_point();
                        int32_t rt_2062 = alg_root_top;
                        Value v_each = alg_iterable_at(loop_471, at_471);
                        (void)v_each;
                        alg_root(&v_each, 1);
                        if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(v_each))}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1)))))) {
                            Value ret_472 = alg_bool(true);
                            alg_root_top = rt_base;
                            return ret_472;
                        }
                        alg_root_top = rt_2062;
                    }
                    alg_root_top = rt_2061;
                }
                alg_hold_top = rh_2060;
            }
            alg_root_top = rt_2059;
        }
        alg_root_top = rt_2058;
    }
    alg_hold_top = rh_2057;
    Value ret_473 = alg_bool(false);
    alg_root_top = rt_base;
    return ret_473;
    alg_hold_top = rh_2057;
    Value ret_474 = alg_nil();
    alg_root_top = rt_base;
    return ret_474;
}

static Value m_cemitter_extensionvalue_1_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2063 = alg_hold_top;
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_2063;
    Value v_unit = alg_nil();
    (void)v_unit;
    alg_root(&v_unit, 1);
    alg_hold_top = rh_2063;
    (void)((v_name = alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "Extension"))))));
    alg_hold_top = rh_2063;
    (void)((v_unit = alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "ExtensionUnit"))))));
    alg_hold_top = rh_2063;
    if (alg_truthy(alg_hold(alg_equal(v_unit, alg_literal(""))))) {
        Value ret_475 = alg_hold(alg_invoke(v_this, "SubprogramValue", (Value[]){v_name}, 1));
        alg_root_top = rt_base;
        return ret_475;
    }
    alg_hold_top = rh_2063;
    if (alg_truthy(alg_hold(alg_invoke(v_this, "OverloadedElsewhere", (Value[]){v_unit, v_name}, 2)))) {
        Value ret_476 = alg_hold(alg_invoke(v_this, "SetName", (Value[]){v_name}, 1));
        alg_root_top = rt_base;
        return ret_476;
    }
    alg_hold_top = rh_2063;
    Value ret_477 = alg_hold(alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1));
    alg_root_top = rt_base;
    return ret_477;
    alg_hold_top = rh_2063;
    Value ret_478 = alg_nil();
    alg_root_top = rt_base;
    return ret_478;
}

static Value m_cemitter_argumentarray_1_list(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_arguments = alg_widen(args[0], "List");
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    int32_t rh_2064 = alg_hold_top;
    Value v_joined = alg_literal("");
    (void)v_joined;
    alg_root(&v_joined, 1);
    alg_hold_top = rh_2064;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(0))))) {
        Value ret_479 = alg_literal("NULL, 0");
        alg_root_top = rt_base;
        return ret_479;
    }
    alg_hold_top = rh_2064;
    {
        int32_t rt_2065 = alg_root_top;
        int32_t rh_2066 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2066;
        {
            int32_t rh_2067 = alg_hold_top;
            for (; (alg_hold_top = rh_2067, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_arguments, "Length")))))); (alg_hold_top = rh_2067, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_2068 = alg_hold_top;
                    if (alg_truthy(alg_hold(alg_greater(v_i, alg_int(0))))) {
                        (void)((v_joined = alg_hold(alg_add(v_joined, alg_literal(", ")))));
                    }
                    alg_hold_top = rh_2068;
                    (void)((v_joined = alg_hold(alg_add(v_joined, alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, v_i))))))));
                    alg_hold_top = rh_2068;
                }
            }
        }
        alg_hold_top = rh_2066;
        alg_root_top = rt_2065;
    }
    alg_hold_top = rh_2064;
    Value ret_480 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("(Value[]){"), v_joined)), alg_literal("}, "))), alg_hold(alg_str(alg_hold(alg_property(v_arguments, "Length"))))));
    alg_root_top = rt_base;
    return ret_480;
    alg_hold_top = rh_2064;
    Value ret_481 = alg_nil();
    alg_root_top = rt_base;
    return ret_481;
}

static Value m_cemitter_exportednames_1_emitunit(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_unit = alg_widen(args[0], "EmitUnit");
    (void)v_unit;
    alg_root(&v_unit, 1);
    int32_t rh_2069 = alg_hold_top;
    Value v_names = alg_nil();
    (void)v_names;
    alg_root(&v_names, 1);
    alg_hold_top = rh_2069;
    (void)((v_names = alg_hold(alg_list())));
    alg_hold_top = rh_2069;
    {
        int32_t rt_2070 = alg_root_top;
        Value loop_482 = alg_iterable(alg_hold(alg_property(v_unit, "Statements")));
        (void)loop_482;
        alg_root(&loop_482, 1);
        for (int32_t at_482 = 0; at_482 < alg_iterable_count(loop_482); at_482++) {
            alg_safe_point();
            int32_t rt_2071 = alg_root_top;
            Value v_thestmt = alg_iterable_at(loop_482, at_482);
            (void)v_thestmt;
            alg_root(&v_thestmt, 1);
            {
                int32_t rh_2072 = alg_hold_top;
                if (alg_truthy(alg_hold((or_83 = alg_is_class(v_thestmt, k_functionstmt), !alg_truthy(or_83) ? or_83 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "IsTest", (Value[]){v_thestmt}, 1)))))))) {
                    (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                }
                alg_hold_top = rh_2072;
                if (alg_truthy(alg_is_class(v_thestmt, k_classstmt))) {
                    (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                }
                alg_hold_top = rh_2072;
                if (alg_truthy(alg_is_class(v_thestmt, k_objectstmt))) {
                    (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                }
                alg_hold_top = rh_2072;
                if (alg_truthy(alg_is_class(v_thestmt, k_varstmt))) {
                    (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                }
                alg_hold_top = rh_2072;
                if (alg_truthy(alg_is_class(v_thestmt, k_enumstmt))) {
                    {
                        int32_t rh_2073 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
                        alg_hold_top = rh_2073;
                        {
                            int32_t rt_2074 = alg_root_top;
                            Value loop_483 = alg_iterable(alg_hold(alg_property(v_thestmt, "Members")));
                            (void)loop_483;
                            alg_root(&loop_483, 1);
                            for (int32_t at_483 = 0; at_483 < alg_iterable_count(loop_483); at_483++) {
                                alg_safe_point();
                                int32_t rt_2075 = alg_root_top;
                                Value v_member = alg_iterable_at(loop_483, at_483);
                                (void)v_member;
                                alg_root(&v_member, 1);
                                (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_member, "Lexeme"))))}, 1)));
                                alg_root_top = rt_2075;
                            }
                            alg_root_top = rt_2074;
                        }
                        alg_hold_top = rh_2073;
                    }
                }
                alg_hold_top = rh_2072;
                if (alg_truthy(alg_is_class(v_thestmt, k_vargroupstmt))) {
                    {
                        int32_t rt_2076 = alg_root_top;
                        Value loop_484 = alg_iterable(alg_hold(alg_property(v_thestmt, "Names")));
                        (void)loop_484;
                        alg_root(&loop_484, 1);
                        for (int32_t at_484 = 0; at_484 < alg_iterable_count(loop_484); at_484++) {
                            alg_safe_point();
                            int32_t rt_2077 = alg_root_top;
                            Value v_thename = alg_iterable_at(loop_484, at_484);
                            (void)v_thename;
                            alg_root(&v_thename, 1);
                            (void)(alg_hold(alg_invoke(v_names, "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme"))))}, 1)));
                            alg_root_top = rt_2077;
                        }
                        alg_root_top = rt_2076;
                    }
                }
                alg_hold_top = rh_2072;
            }
            alg_root_top = rt_2071;
        }
        alg_root_top = rt_2070;
    }
    alg_hold_top = rh_2069;
    Value ret_485 = v_names;
    alg_root_top = rt_base;
    return ret_485;
    alg_hold_top = rh_2069;
    Value ret_486 = alg_nil();
    alg_root_top = rt_base;
    return ret_486;
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
    int32_t rh_2078 = alg_hold_top;
    if (alg_truthy(alg_hold((or_84 = alg_hold(alg_equal(v_name, alg_literal("List"))), !alg_truthy(or_84) ? or_84 : alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(0))))))) {
        Value ret_487 = alg_literal("alg_list()");
        alg_root_top = rt_base;
        return ret_487;
    }
    alg_hold_top = rh_2078;
    if (alg_truthy(alg_hold((or_85 = alg_hold(alg_equal(v_name, alg_literal("Map"))), !alg_truthy(or_85) ? or_85 : alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(0))))))) {
        Value ret_488 = alg_literal("alg_map()");
        alg_root_top = rt_base;
        return ret_488;
    }
    alg_hold_top = rh_2078;
    if (alg_truthy(alg_hold((or_86 = alg_hold(alg_equal(v_name, alg_literal("Stack"))), !alg_truthy(or_86) ? or_86 : alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(0))))))) {
        Value ret_489 = alg_literal("alg_stack()");
        alg_root_top = rt_base;
        return ret_489;
    }
    alg_hold_top = rh_2078;
    if (alg_truthy(alg_hold((or_87 = alg_hold(alg_equal(v_name, alg_literal("Set"))), !alg_truthy(or_87) ? or_87 : alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(0))))))) {
        Value ret_490 = alg_literal("alg_set()");
        alg_root_top = rt_base;
        return ret_490;
    }
    alg_hold_top = rh_2078;
    if (alg_truthy(alg_hold((or_88 = alg_hold(alg_equal(v_name, alg_literal("Set"))), !alg_truthy(or_88) ? or_88 : alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(1))))))) {
        Value ret_491 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_set_of("), v_joined)), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_491;
    }
    alg_hold_top = rh_2078;
    if (alg_truthy(alg_hold((or_89 = alg_hold(alg_equal(v_name, alg_literal("Array"))), !alg_truthy(or_89) ? or_89 : alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(1))))))) {
        Value ret_492 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_array("), v_joined)), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_492;
    }
    alg_hold_top = rh_2078;
    if (alg_truthy(alg_hold((or_90 = alg_hold(alg_equal(v_name, alg_literal("TextFile"))), !alg_truthy(or_90) ? or_90 : alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(0))))))) {
        Value ret_493 = alg_literal("alg_text_file()");
        alg_root_top = rt_base;
        return ret_493;
    }
    alg_hold_top = rh_2078;
    if (alg_truthy(alg_hold((or_91 = alg_hold(alg_equal(v_name, alg_literal("Buffer"))), !alg_truthy(or_91) ? or_91 : alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(0))))))) {
        Value ret_494 = alg_literal("alg_buffer(alg_int(0))");
        alg_root_top = rt_base;
        return ret_494;
    }
    alg_hold_top = rh_2078;
    if (alg_truthy(alg_hold((or_92 = alg_hold(alg_equal(v_name, alg_literal("Buffer"))), !alg_truthy(or_92) ? or_92 : alg_hold(alg_equal(alg_hold(alg_property(v_arguments, "Length")), alg_int(1))))))) {
        Value ret_495 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_buffer("), v_joined)), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_495;
    }
    alg_hold_top = rh_2078;
    Value ret_496 = alg_literal("");
    alg_root_top = rt_base;
    return ret_496;
    alg_hold_top = rh_2078;
    Value ret_497 = alg_nil();
    alg_root_top = rt_base;
    return ret_497;
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
    int32_t rh_2079 = alg_hold_top;
    if (alg_truthy(alg_hold((or_93 = alg_hold(alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){v_unit}, 1)), !alg_truthy(or_93) ? or_93 : alg_hold(alg_not(alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_unit}, 1), ALG_KIND_SET, "Set"))), "Contains", (Value[]){v_name}, 1)))))))) {
        Value ret_498 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_error("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined name '"), v_name)), alg_literal("' in unit '"))), v_unit)), alg_literal("'.")))}, 1)))), alg_literal("), alg_nil())")));
        alg_root_top = rt_base;
        return ret_498;
    }
    alg_hold_top = rh_2079;
    if (alg_truthy(alg_hold(alg_equal(v_unit, alg_literal("System"))))) {
        {
            int32_t rt_2080 = alg_root_top;
            int32_t rh_2081 = alg_hold_top;
            Value v_joining = alg_hold(alg_invoke(v_this, "JoiningBuiltin", (Value[]){v_name, v_arguments}, 2));
            (void)v_joining;
            alg_root(&v_joining, 1);
            alg_hold_top = rh_2081;
            if (alg_truthy(alg_hold(alg_not_equal(v_joining, alg_literal(""))))) {
                Value ret_499 = v_joining;
                alg_root_top = rt_base;
                return ret_499;
            }
            alg_hold_top = rh_2081;
            Value v_thebuiltin = alg_hold(alg_invoke(v_this, "Builtin", (Value[]){v_name, alg_hold(alg_property(v_arguments, "Length"))}, 2));
            (void)v_thebuiltin;
            alg_root(&v_thebuiltin, 1);
            alg_hold_top = rh_2081;
            if (alg_truthy(alg_hold(alg_not_equal(v_thebuiltin, alg_literal(""))))) {
                Value ret_500 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_thebuiltin, alg_char_value(40))), v_joined)), alg_char_value(41)));
                alg_root_top = rt_base;
                return ret_500;
            }
            alg_hold_top = rh_2081;
            Value v_theconstructor = alg_hold(alg_invoke(v_this, "ConstructorFor", (Value[]){v_name, v_arguments, v_joined}, 3));
            (void)v_theconstructor;
            alg_root(&v_theconstructor, 1);
            alg_hold_top = rh_2081;
            if (alg_truthy(alg_hold(alg_not_equal(v_theconstructor, alg_literal(""))))) {
                Value ret_501 = v_theconstructor;
                alg_root_top = rt_base;
                return ret_501;
            }
            alg_hold_top = rh_2081;
            (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("A call to '"), v_unit)), alg_char_value(46))), v_name)), alg_char_value(39)))}, 1)));
            alg_hold_top = rh_2081;
            alg_root_top = rt_2080;
        }
    }
    alg_hold_top = rh_2079;
    Value v_saved = alg_property(v_this, "Renames");
    (void)v_saved;
    alg_root(&v_saved, 1);
    alg_hold_top = rh_2079;
    (void)(alg_set_property(v_this, "Renames", alg_hold(alg_invoke(v_this, "RenamesOf", (Value[]){v_unit, v_name}, 2))));
    alg_hold_top = rh_2079;
    Value v_built = alg_literal("");
    (void)v_built;
    alg_root(&v_built, 1);
    alg_hold_top = rh_2079;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))) {
        (void)((v_built = alg_hold(alg_invoke(v_this, "Constructing", (Value[]){alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)), v_arguments, v_names}, 3))));
    } else {
        if (alg_truthy(alg_hold((or_94 = alg_hold(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1)), !alg_truthy(or_94) ? or_94 : alg_hold(alg_invoke(alg_property(v_this, "Overloaded"), "Contains", (Value[]){v_name}, 1)))))) {
            (void)((v_built = alg_hold(alg_invoke(v_this, "Calling", (Value[]){alg_hold(alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)), v_arguments, v_names}, 3))));
        } else {
            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1)))) {
                if (alg_truthy(alg_hold(f_anynamed(NULL, (Value[]){v_names}, 1)))) {
                    (void)((v_built = alg_hold(alg_invoke(v_this, "Calling", (Value[]){alg_hold(alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1)), v_arguments, v_names}, 3))));
                } else {
                    (void)((v_built = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(v_this, "FunctionName", (Value[]){v_name}, 1)), alg_literal("(NULL, "))), alg_hold(alg_invoke(v_this, "ArgumentArray", (Value[]){v_arguments}, 1)))), alg_char_value(41)))));
                }
            } else {
                if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))) {
                    (void)((v_built = alg_hold(alg_invoke(v_this, "Calling", (Value[]){alg_hold(alg_invoke(v_this, "Read", (Value[]){v_name}, 1)), v_arguments, v_names}, 3))));
                }
            }
        }
    }
    alg_hold_top = rh_2079;
    (void)(alg_set_property(v_this, "Renames", v_saved));
    alg_hold_top = rh_2079;
    if (alg_truthy(alg_hold(alg_not_equal(v_built, alg_literal(""))))) {
        Value ret_502 = v_built;
        alg_root_top = rt_base;
        return ret_502;
    }
    alg_hold_top = rh_2079;
    (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("A call to '"), v_unit)), alg_char_value(46))), v_name)), alg_char_value(39)))}, 1)));
    alg_hold_top = rh_2079;
    Value ret_503 = alg_literal("");
    alg_root_top = rt_base;
    return ret_503;
    alg_hold_top = rh_2079;
    Value ret_504 = alg_nil();
    alg_root_top = rt_base;
    return ret_504;
}

static Value m_cemitter_visitcall_1_callexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CallExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2082 = alg_hold_top;
    Value v_arguments = alg_nil();
    (void)v_arguments;
    alg_root(&v_arguments, 1);
    alg_hold_top = rh_2082;
    Value v_joined = alg_nil();
    (void)v_joined;
    alg_root(&v_joined, 1);
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_is_class(alg_hold(alg_property(v_theexpr, "Callee")), k_superexpr))) {
        {
            int32_t rt_2083 = alg_root_top;
            int32_t rh_2084 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "CurrentClass"), alg_literal(""))))) {
                (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_literal("'super' outside a class")}, 1)));
            }
            alg_hold_top = rh_2084;
            Value v_emitted = alg_hold(alg_list());
            (void)v_emitted;
            alg_root(&v_emitted, 1);
            alg_hold_top = rh_2084;
            {
                int32_t rt_2085 = alg_root_top;
                Value loop_505 = alg_iterable(alg_hold(alg_property(v_theexpr, "Arguments")));
                (void)loop_505;
                alg_root(&loop_505, 1);
                for (int32_t at_505 = 0; at_505 < alg_iterable_count(loop_505); at_505++) {
                    alg_safe_point();
                    int32_t rt_2086 = alg_root_top;
                    Value v_argument = alg_iterable_at(loop_505, at_505);
                    (void)v_argument;
                    alg_root(&v_argument, 1);
                    (void)(alg_hold(alg_invoke(v_emitted, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){v_argument}, 1))}, 1)));
                    alg_root_top = rt_2086;
                }
                alg_root_top = rt_2085;
            }
            alg_hold_top = rh_2084;
            Value ret_506 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_invoke_from("), alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){alg_property(v_this, "CurrentClass")}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ThisRef", NULL, 0)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Method")), "Lexeme"))))}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ArgumentArray", (Value[]){v_emitted}, 1)))), alg_char_value(41)));
            alg_root_top = rt_base;
            return ret_506;
            alg_hold_top = rh_2084;
            alg_root_top = rt_2083;
        }
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold((or_95 = alg_is_class(alg_hold(alg_property(v_theexpr, "Callee")), k_getexpr), !alg_truthy(or_95) ? or_95 : alg_hold(alg_not_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Unit")), alg_literal(""))))))) {
        {
            int32_t rt_2087 = alg_root_top;
            int32_t rh_2088 = alg_hold_top;
            Value v_emitted = alg_hold(alg_list());
            (void)v_emitted;
            alg_root(&v_emitted, 1);
            alg_hold_top = rh_2088;
            {
                int32_t rt_2089 = alg_root_top;
                Value loop_507 = alg_iterable(alg_hold(alg_property(v_theexpr, "Arguments")));
                (void)loop_507;
                alg_root(&loop_507, 1);
                for (int32_t at_507 = 0; at_507 < alg_iterable_count(loop_507); at_507++) {
                    alg_safe_point();
                    int32_t rt_2090 = alg_root_top;
                    Value v_theargument = alg_iterable_at(loop_507, at_507);
                    (void)v_theargument;
                    alg_root(&v_theargument, 1);
                    (void)(alg_hold(alg_invoke(v_emitted, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){v_theargument}, 1))}, 1)));
                    alg_root_top = rt_2090;
                }
                alg_root_top = rt_2089;
            }
            alg_hold_top = rh_2088;
            Value v_text = alg_literal("");
            (void)v_text;
            alg_root(&v_text, 1);
            alg_hold_top = rh_2088;
            {
                int32_t rt_2091 = alg_root_top;
                int32_t rh_2092 = alg_hold_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_2092;
                {
                    int32_t rh_2093 = alg_hold_top;
                    for (; (alg_hold_top = rh_2093, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_emitted, "Length")))))); (alg_hold_top = rh_2093, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                        alg_safe_point();
                        {
                            int32_t rh_2094 = alg_hold_top;
                            if (alg_truthy(alg_hold(alg_greater(v_i, alg_int(0))))) {
                                (void)((v_text = alg_hold(alg_add(v_text, alg_literal(", ")))));
                            }
                            alg_hold_top = rh_2094;
                            (void)((v_text = alg_hold(alg_add(v_text, alg_hold(alg_str(alg_hold(alg_subscript_get(v_emitted, v_i))))))));
                            alg_hold_top = rh_2094;
                        }
                    }
                }
                alg_hold_top = rh_2092;
                alg_root_top = rt_2091;
            }
            alg_hold_top = rh_2088;
            Value ret_508 = alg_hold(alg_invoke(v_this, "UnitCall", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Unit")))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name")), "Lexeme")))), v_emitted, v_text, alg_hold(alg_property(v_theexpr, "ArgumentNames"))}, 5));
            alg_root_top = rt_base;
            return ret_508;
            alg_hold_top = rh_2088;
            alg_root_top = rt_2087;
        }
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_is_class(alg_hold(alg_property(v_theexpr, "Callee")), k_getexpr))) {
        {
            int32_t rt_2095 = alg_root_top;
            int32_t rh_2096 = alg_hold_top;
            Value v_receiver = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Obj"))}, 1));
            (void)v_receiver;
            alg_root(&v_receiver, 1);
            alg_hold_top = rh_2096;
            Value v_emitted = alg_hold(alg_list());
            (void)v_emitted;
            alg_root(&v_emitted, 1);
            alg_hold_top = rh_2096;
            {
                int32_t rt_2097 = alg_root_top;
                Value loop_509 = alg_iterable(alg_hold(alg_property(v_theexpr, "Arguments")));
                (void)loop_509;
                alg_root(&loop_509, 1);
                for (int32_t at_509 = 0; at_509 < alg_iterable_count(loop_509); at_509++) {
                    alg_safe_point();
                    int32_t rt_2098 = alg_root_top;
                    Value v_eachargument = alg_iterable_at(loop_509, at_509);
                    (void)v_eachargument;
                    alg_root(&v_eachargument, 1);
                    (void)(alg_hold(alg_invoke(v_emitted, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){v_eachargument}, 1))}, 1)));
                    alg_root_top = rt_2098;
                }
                alg_root_top = rt_2097;
            }
            alg_hold_top = rh_2096;
            if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Extension")))), alg_literal(""))))) {
                Value ret_510 = alg_hold(alg_invoke(v_this, "InvokingOr", (Value[]){v_receiver, alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name")), "Lexeme")))), v_emitted, alg_hold(alg_property(v_theexpr, "ArgumentNames")), alg_hold(alg_invoke(v_this, "ExtensionValue", (Value[]){alg_hold(alg_property(v_theexpr, "Callee"))}, 1))}, 5));
                alg_root_top = rt_base;
                return ret_510;
            }
            alg_hold_top = rh_2096;
            Value ret_511 = alg_hold(alg_invoke(v_this, "Invoking", (Value[]){v_receiver, alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name")), "Lexeme")))), v_emitted, alg_hold(alg_property(v_theexpr, "ArgumentNames"))}, 4));
            alg_root_top = rt_base;
            return ret_511;
            alg_hold_top = rh_2096;
            alg_root_top = rt_2095;
        }
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold(alg_not((alg_is_class(alg_hold(alg_property(v_theexpr, "Callee")), k_variableexpr)))))) {
        {
            int32_t rt_2099 = alg_root_top;
            int32_t rh_2100 = alg_hold_top;
            Value v_emitted = alg_hold(alg_list());
            (void)v_emitted;
            alg_root(&v_emitted, 1);
            alg_hold_top = rh_2100;
            {
                int32_t rt_2101 = alg_root_top;
                Value loop_512 = alg_iterable(alg_hold(alg_property(v_theexpr, "Arguments")));
                (void)loop_512;
                alg_root(&loop_512, 1);
                for (int32_t at_512 = 0; at_512 < alg_iterable_count(loop_512); at_512++) {
                    alg_safe_point();
                    int32_t rt_2102 = alg_root_top;
                    Value v_item = alg_iterable_at(loop_512, at_512);
                    (void)v_item;
                    alg_root(&v_item, 1);
                    (void)(alg_hold(alg_invoke(v_emitted, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){v_item}, 1))}, 1)));
                    alg_root_top = rt_2102;
                }
                alg_root_top = rt_2101;
            }
            alg_hold_top = rh_2100;
            Value ret_513 = alg_hold(alg_invoke(v_this, "Calling", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Callee"))}, 1)), v_emitted, alg_hold(alg_property(v_theexpr, "ArgumentNames"))}, 3));
            alg_root_top = rt_base;
            return ret_513;
            alg_hold_top = rh_2100;
            alg_root_top = rt_2099;
        }
    }
    alg_hold_top = rh_2082;
    (void)((v_arguments = alg_hold(alg_list())));
    alg_hold_top = rh_2082;
    {
        int32_t rt_2103 = alg_root_top;
        int32_t rh_2104 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2104;
        {
            int32_t rh_2105 = alg_hold_top;
            for (; (alg_hold_top = rh_2105, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Arguments")), "Length")))))); (alg_hold_top = rh_2105, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                (void)(alg_hold(alg_invoke(v_arguments, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_theexpr, "Arguments")), v_i))}, 1))}, 1)));
            }
        }
        alg_hold_top = rh_2104;
        alg_root_top = rt_2103;
    }
    alg_hold_top = rh_2082;
    (void)((v_joined = alg_literal("")));
    alg_hold_top = rh_2082;
    {
        int32_t rt_2106 = alg_root_top;
        int32_t rh_2107 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2107;
        {
            int32_t rh_2108 = alg_hold_top;
            for (; (alg_hold_top = rh_2108, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_arguments, "Length")))))); (alg_hold_top = rh_2108, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_2109 = alg_hold_top;
                    if (alg_truthy(alg_hold(alg_greater(v_i, alg_int(0))))) {
                        (void)((v_joined = alg_hold(alg_add(v_joined, alg_literal(", ")))));
                    }
                    alg_hold_top = rh_2109;
                    (void)((v_joined = alg_hold(alg_add(v_joined, alg_hold(alg_str(alg_hold(alg_subscript_get(v_arguments, v_i))))))));
                    alg_hold_top = rh_2109;
                }
            }
        }
        alg_hold_top = rh_2107;
        alg_root_top = rt_2106;
    }
    alg_hold_top = rh_2082;
    Value v_name = alg_hold(alg_invoke(v_this, "Spelled", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name")), "Lexeme"))))}, 1));
    (void)v_name;
    alg_root(&v_name, 1);
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold((or_97 = alg_hold((or_96 = alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)), alg_truthy(or_96) ? or_96 : alg_hold(alg_invoke(alg_property(v_this, "Captured"), "Contains", (Value[]){v_name}, 1)))), alg_truthy(or_97) ? or_97 : alg_hold(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1)))))) {
        Value ret_514 = alg_hold(alg_invoke(v_this, "Calling", (Value[]){alg_hold(alg_invoke(v_this, "Read", (Value[]){v_name}, 1)), v_arguments, alg_hold(alg_property(v_theexpr, "ArgumentNames"))}, 3));
        alg_root_top = rt_base;
        return ret_514;
    }
    alg_hold_top = rh_2082;
    Value v_shadowed = alg_hold(alg_invoke(v_this, "TakesOver", (Value[]){v_name, alg_hold(alg_property(v_arguments, "Length"))}, 2));
    (void)v_shadowed;
    alg_root(&v_shadowed, 1);
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold((or_99 = alg_hold((or_98 = alg_hold(alg_not(v_shadowed)), !alg_truthy(or_98) ? or_98 : alg_hold(f_anynamed(NULL, (Value[]){alg_hold(alg_property(v_theexpr, "ArgumentNames"))}, 1)))), !alg_truthy(or_99) ? or_99 : alg_hold(alg_greater(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "BuiltinCounts", (Value[]){v_name}, 1)), "Length")), alg_int(0))))))) {
        Value ret_515 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_error("), alg_hold(f_quotec(NULL, (Value[]){alg_literal("A built-in has no named parameters.")}, 1)))), alg_literal("), alg_nil())")));
        alg_root_top = rt_base;
        return ret_515;
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold(alg_not(v_shadowed)))) {
        {
            int32_t rt_2110 = alg_root_top;
            int32_t rh_2111 = alg_hold_top;
            Value v_joining = alg_hold(alg_invoke(v_this, "JoiningBuiltin", (Value[]){v_name, v_arguments}, 2));
            (void)v_joining;
            alg_root(&v_joining, 1);
            alg_hold_top = rh_2111;
            if (alg_truthy(alg_hold(alg_not_equal(v_joining, alg_literal(""))))) {
                Value ret_516 = v_joining;
                alg_root_top = rt_base;
                return ret_516;
            }
            alg_hold_top = rh_2111;
            alg_root_top = rt_2110;
        }
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold(alg_not(v_shadowed)))) {
        {
            int32_t rt_2112 = alg_root_top;
            int32_t rh_2113 = alg_hold_top;
            Value v_thebuiltin = alg_hold(alg_invoke(v_this, "Builtin", (Value[]){v_name, alg_hold(alg_property(v_arguments, "Length"))}, 2));
            (void)v_thebuiltin;
            alg_root(&v_thebuiltin, 1);
            alg_hold_top = rh_2113;
            if (alg_truthy(alg_hold(alg_not_equal(v_thebuiltin, alg_literal(""))))) {
                Value ret_517 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_thebuiltin, alg_char_value(40))), v_joined)), alg_char_value(41)));
                alg_root_top = rt_base;
                return ret_517;
            }
            alg_hold_top = rh_2113;
            alg_root_top = rt_2112;
        }
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold(alg_not(v_shadowed)))) {
        {
            int32_t rt_2114 = alg_root_top;
            int32_t rh_2115 = alg_hold_top;
            Value v_theconstructor = alg_hold(alg_invoke(v_this, "ConstructorFor", (Value[]){v_name, v_arguments, v_joined}, 3));
            (void)v_theconstructor;
            alg_root(&v_theconstructor, 1);
            alg_hold_top = rh_2115;
            if (alg_truthy(alg_hold(alg_not_equal(v_theconstructor, alg_literal(""))))) {
                Value ret_518 = v_theconstructor;
                alg_root_top = rt_base;
                return ret_518;
            }
            alg_hold_top = rh_2115;
            alg_root_top = rt_2114;
        }
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold((or_101 = alg_hold((or_100 = alg_hold(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1)), !alg_truthy(or_100) ? or_100 : alg_hold(alg_not(v_shadowed)))), !alg_truthy(or_101) ? or_101 : alg_hold(alg_greater(alg_hold(alg_property(alg_hold(alg_invoke(v_this, "BuiltinCounts", (Value[]){v_name}, 1)), "Length")), alg_int(0))))))) {
        Value ret_519 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_error("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("No matching signature for "), v_name)), alg_char_value(46)))}, 1)))), alg_literal("), alg_nil())")));
        alg_root_top = rt_base;
        return ret_519;
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))) {
        Value ret_520 = alg_hold(alg_invoke(v_this, "Constructing", (Value[]){alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)), v_arguments, alg_hold(alg_property(v_theexpr, "ArgumentNames"))}, 3));
        alg_root_top = rt_base;
        return ret_520;
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))) {
        Value ret_521 = alg_hold(alg_invoke(v_this, "Calling", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_singleton("), alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)))), alg_char_value(41))), v_arguments, alg_hold(alg_property(v_theexpr, "ArgumentNames"))}, 3));
        alg_root_top = rt_base;
        return ret_521;
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_522 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_error("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_invoke(v_this, "AmbiguousMessage", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name")), "Lexeme")))), alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousImports"), "Get", (Value[]){v_name}, 1))))}, 2))}, 1)))), alg_literal("), alg_nil())")));
        alg_root_top = rt_base;
        return ret_522;
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold((or_103 = alg_hold((or_102 = alg_hold(alg_not_equal(alg_property(v_this, "CurrentClass"), alg_literal(""))), !alg_truthy(or_102) ? or_102 : alg_hold(alg_not(alg_hold(alg_invoke(v_this, "VisibleSubprogram", (Value[]){v_name}, 1)))))), !alg_truthy(or_103) ? or_103 : alg_hold(alg_invoke(alg_property(v_this, "VisibleMethods"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))))) {
        Value ret_523 = alg_hold(alg_invoke(v_this, "Invoking", (Value[]){alg_hold(alg_invoke(v_this, "ThisRef", NULL, 0)), v_name, v_arguments, alg_hold(alg_property(v_theexpr, "ArgumentNames"))}, 4));
        alg_root_top = rt_base;
        return ret_523;
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold((or_104 = alg_hold(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1)), !alg_truthy(or_104) ? or_104 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "ShadowNames"), "Contains", (Value[]){v_name}, 1)))))))) {
        Value ret_524 = alg_hold(alg_invoke(v_this, "Missing", (Value[]){v_name, alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name"))}, 2));
        alg_root_top = rt_base;
        return ret_524;
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold((or_105 = alg_hold(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1)), !alg_truthy(or_105) ? or_105 : alg_hold(alg_invoke(v_this, "IsOverloadSet", (Value[]){v_name}, 1)))))) {
        Value ret_525 = alg_hold(alg_invoke(v_this, "Calling", (Value[]){alg_hold(alg_invoke(v_this, "SetName", (Value[]){v_name}, 1)), v_arguments, alg_hold(alg_property(v_theexpr, "ArgumentNames"))}, 3));
        alg_root_top = rt_base;
        return ret_525;
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1)))) {
        {
            int32_t rh_2116 = alg_hold_top;
            if (alg_truthy(alg_hold(f_anynamed(NULL, (Value[]){alg_hold(alg_property(v_theexpr, "ArgumentNames"))}, 1)))) {
                Value ret_526 = alg_hold(alg_invoke(v_this, "Calling", (Value[]){alg_hold(alg_invoke(v_this, "HandleName", (Value[]){v_name}, 1)), v_arguments, alg_hold(alg_property(v_theexpr, "ArgumentNames"))}, 3));
                alg_root_top = rt_base;
                return ret_526;
            }
            alg_hold_top = rh_2116;
            Value ret_527 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(v_this, "FunctionName", (Value[]){v_name}, 1)), alg_literal("(NULL, "))), alg_hold(alg_invoke(v_this, "ArgumentArray", (Value[]){v_arguments}, 1)))), alg_char_value(41)));
            alg_root_top = rt_base;
            return ret_527;
            alg_hold_top = rh_2116;
        }
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))) {
        Value ret_528 = alg_hold(alg_invoke(v_this, "Calling", (Value[]){alg_hold(alg_invoke(v_this, "Read", (Value[]){v_name}, 1)), v_arguments, alg_hold(alg_property(v_theexpr, "ArgumentNames"))}, 3));
        alg_root_top = rt_base;
        return ret_528;
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold((or_106 = alg_hold(alg_not(alg_property(v_this, "EmitTests"))), !alg_truthy(or_106) ? or_106 : alg_hold(alg_invoke(v_this, "IsAssertion", (Value[]){v_name}, 1)))))) {
        Value ret_529 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_error("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_invoke(v_this, "MissingName", (Value[]){v_name}, 1))}, 1)))), alg_literal("), alg_nil())")));
        alg_root_top = rt_base;
        return ret_529;
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold(alg_not(v_shadowed)))) {
        {
            int32_t rt_2117 = alg_root_top;
            int32_t rh_2118 = alg_hold_top;
            Value v_counts = alg_hold(alg_invoke(v_this, "BuiltinCounts", (Value[]){v_name}, 1));
            (void)v_counts;
            alg_root(&v_counts, 1);
            alg_hold_top = rh_2118;
            if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(v_counts, "Length")), alg_int(0))))) {
                Value ret_530 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_error("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_invoke(v_this, "CountsMessage", (Value[]){v_counts, alg_hold(alg_property(v_arguments, "Length"))}, 2))}, 1)))), alg_literal("), alg_nil())")));
                alg_root_top = rt_base;
                return ret_530;
            }
            alg_hold_top = rh_2118;
            alg_root_top = rt_2117;
        }
    }
    alg_hold_top = rh_2082;
    if (alg_truthy(alg_hold((or_113 = alg_hold((or_112 = alg_hold((or_111 = alg_hold((or_110 = alg_hold((or_109 = alg_hold((or_108 = alg_hold((or_107 = alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Contains", (Value[]){v_name}, 1)))), !alg_truthy(or_107) ? or_107 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))))), !alg_truthy(or_108) ? or_108 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))))), !alg_truthy(or_109) ? or_109 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))))), !alg_truthy(or_110) ? or_110 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1)))))), !alg_truthy(or_111) ? or_111 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "EnumTypes"), "Contains", (Value[]){v_name}, 1)))))), !alg_truthy(or_112) ? or_112 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_name}, 1)))))), !alg_truthy(or_113) ? or_113 : alg_hold(alg_not(alg_hold(alg_invoke(alg_property(v_this, "AmbiguousMembers"), "Contains", (Value[]){v_name}, 1)))))))) {
        Value ret_531 = alg_hold(alg_invoke(v_this, "Missing", (Value[]){v_name, alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Callee")), "Name"))}, 2));
        alg_root_top = rt_base;
        return ret_531;
    }
    alg_hold_top = rh_2082;
    (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("A call to '"), v_name)), alg_char_value(39)))}, 1)));
    alg_hold_top = rh_2082;
    Value ret_532 = alg_nil();
    alg_root_top = rt_base;
    return ret_532;
}

static Value m_cemitter_visitlogical_1_logicalexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "LogicalExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2119 = alg_hold_top;
    Value v_slot = alg_nil();
    (void)v_slot;
    alg_root(&v_slot, 1);
    alg_hold_top = rh_2119;
    Value v_test = alg_nil();
    (void)v_test;
    alg_root(&v_test, 1);
    alg_hold_top = rh_2119;
    Value v_left = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Left"))}, 1));
    (void)v_left;
    alg_root(&v_left, 1);
    alg_hold_top = rh_2119;
    Value v_right = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Right"))}, 1));
    (void)v_right;
    alg_root(&v_right, 1);
    alg_hold_top = rh_2119;
    (void)((v_slot = alg_hold(alg_add(alg_literal("or_"), alg_hold(alg_str(alg_property(v_this, "Logicals")))))));
    alg_hold_top = rh_2119;
    (void)(alg_set_property(v_this, "Logicals", alg_hold(alg_add(alg_property(v_this, "Logicals"), alg_int(1)))));
    alg_hold_top = rh_2119;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static Value "), v_slot)), alg_char_value(59))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_2119;
    (void)((v_test = alg_literal("!alg_truthy(")));
    alg_hold_top = rh_2119;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Op")), "TypeOfToken")), e_tokentype_tokenVor)))) {
        (void)((v_test = alg_literal("alg_truthy(")));
    }
    alg_hold_top = rh_2119;
    Value ret_533 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(40), v_slot)), alg_literal(" = "))), v_left)), alg_literal(", "))), v_test)), v_slot)), alg_literal(") ? "))), v_slot)), alg_literal(" : "))), v_right)), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_533;
    alg_hold_top = rh_2119;
    Value ret_534 = alg_nil();
    alg_root_top = rt_base;
    return ret_534;
}

static Value m_cemitter_boundargument_3_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_called = args[0];
    (void)v_called;
    alg_root(&v_called, 1);
    Value v_types = args[1];
    (void)v_types;
    alg_root(&v_types, 1);
    Value v_i = alg_widen(args[2], "Integer");
    (void)v_i;
    alg_root(&v_i, 1);
    int32_t rh_2120 = alg_hold_top;
    Value v_slot = alg_hold(alg_add(alg_hold(alg_add(alg_literal("args["), alg_hold(alg_str(v_i)))), alg_char_value(93)));
    (void)v_slot;
    alg_root(&v_slot, 1);
    alg_hold_top = rh_2120;
    if (alg_truthy(alg_hold(alg_greater_equal(v_i, alg_hold(alg_property(v_types, "Length")))))) {
        Value ret_535 = v_slot;
        alg_root_top = rt_base;
        return ret_535;
    }
    alg_hold_top = rh_2120;
    Value v_declared = alg_hold(alg_str(alg_hold(alg_subscript_get(v_types, v_i))));
    (void)v_declared;
    alg_root(&v_declared, 1);
    alg_hold_top = rh_2120;
    if (alg_truthy(alg_hold((or_114 = alg_hold(alg_equal(v_declared, alg_literal(""))), alg_truthy(or_114) ? or_114 : alg_hold(alg_equal(v_declared, alg_literal("Any"))))))) {
        Value ret_536 = v_slot;
        alg_root_top = rt_base;
        return ret_536;
    }
    alg_hold_top = rh_2120;
    Value ret_537 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_param_of("), v_slot)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){v_declared}, 1)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(v_called))}, 1)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_537;
    alg_hold_top = rh_2120;
    Value ret_538 = alg_nil();
    alg_root_top = rt_base;
    return ret_538;
}

static Value m_cemitter_reportedname_1(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = args[0];
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2121 = alg_hold_top;
    Value v_written = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))));
    (void)v_written;
    alg_root(&v_written, 1);
    alg_hold_top = rh_2121;
    if (alg_truthy(alg_hold(alg_not_equal(alg_property(v_this, "CurrentClass"), alg_literal(""))))) {
        Value ret_539 = alg_hold(alg_add(alg_hold(alg_add(alg_property(v_this, "CurrentClass"), alg_char_value(46))), v_written));
        alg_root_top = rt_base;
        return ret_539;
    }
    alg_hold_top = rh_2121;
    Value ret_540 = v_written;
    alg_root_top = rt_base;
    return ret_540;
    alg_hold_top = rh_2121;
    Value ret_541 = alg_nil();
    alg_root_top = rt_base;
    return ret_541;
}

static Value m_cemitter_allliterals_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2122 = alg_hold_top;
    {
        int32_t rt_2123 = alg_root_top;
        Value loop_542 = alg_iterable(alg_hold(alg_property(v_theexpr, "Values")));
        (void)loop_542;
        alg_root(&loop_542, 1);
        for (int32_t at_542 = 0; at_542 < alg_iterable_count(loop_542); at_542++) {
            alg_safe_point();
            int32_t rt_2124 = alg_root_top;
            Value v_value = alg_iterable_at(loop_542, at_542);
            (void)v_value;
            alg_root(&v_value, 1);
            if (alg_truthy(alg_hold(alg_not((alg_is_class(v_value, k_literalexpr)))))) {
                Value ret_543 = alg_bool(false);
                alg_root_top = rt_base;
                return ret_543;
            }
            alg_root_top = rt_2124;
        }
        alg_root_top = rt_2123;
    }
    alg_hold_top = rh_2122;
    if (alg_truthy(alg_hold(alg_property(v_theexpr, "IsMap")))) {
        {
            int32_t rt_2125 = alg_root_top;
            Value loop_544 = alg_iterable(alg_hold(alg_property(v_theexpr, "Keys")));
            (void)loop_544;
            alg_root(&loop_544, 1);
            for (int32_t at_544 = 0; at_544 < alg_iterable_count(loop_544); at_544++) {
                alg_safe_point();
                int32_t rt_2126 = alg_root_top;
                Value v_key = alg_iterable_at(loop_544, at_544);
                (void)v_key;
                alg_root(&v_key, 1);
                if (alg_truthy(alg_hold(alg_not((alg_is_class(v_key, k_literalexpr)))))) {
                    Value ret_545 = alg_bool(false);
                    alg_root_top = rt_base;
                    return ret_545;
                }
                alg_root_top = rt_2126;
            }
            alg_root_top = rt_2125;
        }
    }
    alg_hold_top = rh_2122;
    Value ret_546 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_546;
    alg_hold_top = rh_2122;
    Value ret_547 = alg_nil();
    alg_root_top = rt_base;
    return ret_547;
}

static Value m_cemitter_visitcollectionexpr_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2127 = alg_hold_top;
    Value v_built = alg_nil();
    (void)v_built;
    alg_root(&v_built, 1);
    alg_hold_top = rh_2127;
    if (alg_truthy(alg_hold(alg_greater(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Values")), "Length")), (alg_declared(d_hoistVabove, "HOIST_ABOVE"), v_hoistVabove))))) {
        {
            int32_t rh_2128 = alg_hold_top;
            if (alg_truthy(alg_hold(alg_invoke(v_this, "AllLiterals", (Value[]){v_theexpr}, 1)))) {
                Value ret_548 = alg_hold(alg_invoke(v_this, "HoistedCollection", (Value[]){v_theexpr}, 1));
                alg_root_top = rt_base;
                return ret_548;
            }
            alg_hold_top = rh_2128;
            Value ret_549 = alg_hold(alg_invoke(v_this, "ComputedCollection", (Value[]){v_theexpr}, 1));
            alg_root_top = rt_base;
            return ret_549;
            alg_hold_top = rh_2128;
        }
    }
    alg_hold_top = rh_2127;
    if (alg_truthy(alg_hold(alg_property(v_theexpr, "IsMap")))) {
        {
            int32_t rh_2129 = alg_hold_top;
            (void)((v_built = alg_literal("alg_map()")));
            alg_hold_top = rh_2129;
            {
                int32_t rt_2130 = alg_root_top;
                int32_t rh_2131 = alg_hold_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_2131;
                {
                    int32_t rh_2132 = alg_hold_top;
                    for (; (alg_hold_top = rh_2132, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Keys")), "Length")))))); (alg_hold_top = rh_2132, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                        alg_safe_point();
                        (void)((v_built = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_map_keep("), v_built)), alg_literal(", "))), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_theexpr, "Keys")), v_i))}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_theexpr, "Values")), v_i))}, 1)))), alg_char_value(41)))));
                    }
                }
                alg_hold_top = rh_2131;
                alg_root_top = rt_2130;
            }
            alg_hold_top = rh_2129;
            Value ret_550 = v_built;
            alg_root_top = rt_base;
            return ret_550;
            alg_hold_top = rh_2129;
        }
    }
    alg_hold_top = rh_2127;
    (void)((v_built = alg_literal("alg_list()")));
    alg_hold_top = rh_2127;
    {
        int32_t rt_2133 = alg_root_top;
        Value loop_551 = alg_iterable(alg_hold(alg_property(v_theexpr, "Values")));
        (void)loop_551;
        alg_root(&loop_551, 1);
        for (int32_t at_551 = 0; at_551 < alg_iterable_count(loop_551); at_551++) {
            alg_safe_point();
            int32_t rt_2134 = alg_root_top;
            Value v_value = alg_iterable_at(loop_551, at_551);
            (void)v_value;
            alg_root(&v_value, 1);
            (void)((v_built = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_list_keep("), v_built)), alg_literal(", "))), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){v_value}, 1)))), alg_char_value(41)))));
            alg_root_top = rt_2134;
        }
        alg_root_top = rt_2133;
    }
    alg_hold_top = rh_2127;
    Value ret_552 = v_built;
    alg_root_top = rt_base;
    return ret_552;
    alg_hold_top = rh_2127;
    Value ret_553 = alg_nil();
    alg_root_top = rt_base;
    return ret_553;
}

static Value m_cemitter_hoistedcollection_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2135 = alg_hold_top;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    alg_hold_top = rh_2135;
    (void)((v_symbol = alg_hold(alg_add(alg_literal("lit_"), alg_hold(alg_str(alg_property(v_this, "Loops")))))));
    alg_hold_top = rh_2135;
    (void)(alg_set_property(v_this, "Loops", alg_hold(alg_add(alg_property(v_this, "Loops"), alg_int(1)))));
    alg_hold_top = rh_2135;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static Value "), v_symbol)), alg_literal("(void);"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_2135;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static Value "), v_symbol)), alg_literal("(void) {"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_2135;
    if (alg_truthy(alg_hold(alg_property(v_theexpr, "IsMap")))) {
        {
            int32_t rh_2136 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    Value it = alg_map();"), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_2136;
            {
                int32_t rt_2137 = alg_root_top;
                int32_t rh_2138 = alg_hold_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_2138;
                {
                    int32_t rh_2139 = alg_hold_top;
                    for (; (alg_hold_top = rh_2139, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Keys")), "Length")))))); (alg_hold_top = rh_2139, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                        alg_safe_point();
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    it = alg_map_keep(it, "), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_theexpr, "Keys")), v_i))}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_theexpr, "Values")), v_i))}, 1)))), alg_literal(");"))), alg_char_value(10)))}, 1)));
                    }
                }
                alg_hold_top = rh_2138;
                alg_root_top = rt_2137;
            }
            alg_hold_top = rh_2136;
        }
    } else {
        {
            int32_t rh_2140 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    Value it = alg_list();"), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_2140;
            {
                int32_t rt_2141 = alg_root_top;
                Value loop_554 = alg_iterable(alg_hold(alg_property(v_theexpr, "Values")));
                (void)loop_554;
                alg_root(&loop_554, 1);
                for (int32_t at_554 = 0; at_554 < alg_iterable_count(loop_554); at_554++) {
                    alg_safe_point();
                    int32_t rt_2142 = alg_root_top;
                    Value v_thevalue = alg_iterable_at(loop_554, at_554);
                    (void)v_thevalue;
                    alg_root(&v_thevalue, 1);
                    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    it = alg_list_keep(it, "), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){v_thevalue}, 1)))), alg_literal(");"))), alg_char_value(10)))}, 1)));
                    alg_root_top = rt_2142;
                }
                alg_root_top = rt_2141;
            }
            alg_hold_top = rh_2140;
        }
    }
    alg_hold_top = rh_2135;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    return it;"), alg_char_value(10))), alg_char_value(125))), alg_char_value(10))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_2135;
    Value ret_555 = alg_hold(alg_add(v_symbol, alg_literal("()")));
    alg_root_top = rt_base;
    return ret_555;
    alg_hold_top = rh_2135;
    Value ret_556 = alg_nil();
    alg_root_top = rt_base;
    return ret_556;
}

static Value m_cemitter_computedcollection_1_collectionexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "CollectionExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2143 = alg_hold_top;
    Value v_symbol = alg_nil();
    (void)v_symbol;
    alg_root(&v_symbol, 1);
    alg_hold_top = rh_2143;
    Value v_joined = alg_nil();
    (void)v_joined;
    alg_root(&v_joined, 1);
    alg_hold_top = rh_2143;
    (void)((v_symbol = alg_hold(alg_add(alg_literal("lit_"), alg_hold(alg_str(alg_property(v_this, "Loops")))))));
    alg_hold_top = rh_2143;
    (void)(alg_set_property(v_this, "Loops", alg_hold(alg_add(alg_property(v_this, "Loops"), alg_int(1)))));
    alg_hold_top = rh_2143;
    (void)((v_joined = alg_literal("")));
    alg_hold_top = rh_2143;
    Value v_emitted = alg_hold(alg_list());
    (void)v_emitted;
    alg_root(&v_emitted, 1);
    alg_hold_top = rh_2143;
    {
        int32_t rt_2144 = alg_root_top;
        int32_t rh_2145 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2145;
        {
            int32_t rh_2146 = alg_hold_top;
            for (; (alg_hold_top = rh_2146, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Values")), "Length")))))); (alg_hold_top = rh_2146, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_2147 = alg_hold_top;
                    if (alg_truthy(alg_hold(alg_property(v_theexpr, "IsMap")))) {
                        (void)(alg_hold(alg_invoke(v_emitted, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_theexpr, "Keys")), v_i))}, 1))}, 1)));
                    }
                    alg_hold_top = rh_2147;
                    (void)(alg_hold(alg_invoke(v_emitted, "Add", (Value[]){alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_subscript_get(alg_hold(alg_property(v_theexpr, "Values")), v_i))}, 1))}, 1)));
                    alg_hold_top = rh_2147;
                }
            }
        }
        alg_hold_top = rh_2145;
        alg_root_top = rt_2144;
    }
    alg_hold_top = rh_2143;
    {
        int32_t rt_2148 = alg_root_top;
        int32_t rh_2149 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2149;
        {
            int32_t rh_2150 = alg_hold_top;
            for (; (alg_hold_top = rh_2150, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_emitted, "Length")))))); (alg_hold_top = rh_2150, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                {
                    int32_t rh_2151 = alg_hold_top;
                    if (alg_truthy(alg_hold(alg_greater(v_i, alg_int(0))))) {
                        (void)((v_joined = alg_hold(alg_add(v_joined, alg_literal(", ")))));
                    }
                    alg_hold_top = rh_2151;
                    (void)((v_joined = alg_hold(alg_add(v_joined, alg_hold(alg_str(alg_hold(alg_subscript_get(v_emitted, v_i))))))));
                    alg_hold_top = rh_2151;
                }
            }
        }
        alg_hold_top = rh_2149;
        alg_root_top = rt_2148;
    }
    alg_hold_top = rh_2143;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static Value "), v_symbol)), alg_literal("(Value *e);"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_2143;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static Value "), v_symbol)), alg_literal("(Value *e) {"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_2143;
    if (alg_truthy(alg_hold(alg_property(v_theexpr, "IsMap")))) {
        {
            int32_t rh_2152 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    Value it = alg_map();"), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_2152;
            {
                int32_t rt_2153 = alg_root_top;
                int32_t rh_2154 = alg_hold_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_2154;
                {
                    int32_t rh_2155 = alg_hold_top;
                    for (; (alg_hold_top = rh_2155, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Values")), "Length")))))); (alg_hold_top = rh_2155, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                        alg_safe_point();
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    it = alg_map_keep(it, e["), alg_hold(alg_str(alg_hold(alg_multiply(v_i, alg_int(2))))))), alg_literal("], e["))), alg_hold(alg_str(alg_hold(alg_add(alg_hold(alg_multiply(v_i, alg_int(2))), alg_int(1))))))), alg_literal("]);"))), alg_char_value(10)))}, 1)));
                    }
                }
                alg_hold_top = rh_2154;
                alg_root_top = rt_2153;
            }
            alg_hold_top = rh_2152;
        }
    } else {
        {
            int32_t rh_2156 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_literal("    Value it = alg_list();"), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_2156;
            {
                int32_t rt_2157 = alg_root_top;
                int32_t rh_2158 = alg_hold_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_2158;
                {
                    int32_t rh_2159 = alg_hold_top;
                    for (; (alg_hold_top = rh_2159, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Values")), "Length")))))); (alg_hold_top = rh_2159, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                        alg_safe_point();
                        (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    it = alg_list_keep(it, e["), alg_hold(alg_str(v_i)))), alg_literal("]);"))), alg_char_value(10)))}, 1)));
                    }
                }
                alg_hold_top = rh_2158;
                alg_root_top = rt_2157;
            }
            alg_hold_top = rh_2156;
        }
    }
    alg_hold_top = rh_2143;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Functions"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    return it;"), alg_char_value(10))), alg_char_value(125))), alg_char_value(10))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_2143;
    Value ret_557 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_symbol, alg_literal("((Value[]){"))), v_joined)), alg_literal("})")));
    alg_root_top = rt_base;
    return ret_557;
    alg_hold_top = rh_2143;
    Value ret_558 = alg_nil();
    alg_root_top = rt_base;
    return ret_558;
}

static Value m_cemitter_visitsubscriptexpr_1_subscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SubscriptExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2160 = alg_hold_top;
    Value ret_559 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_subscript_get("), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Index"))}, 1)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_559;
    alg_hold_top = rh_2160;
    Value ret_560 = alg_nil();
    alg_root_top = rt_base;
    return ret_560;
}

static Value m_cemitter_visitsetsubscriptexpr_1_setsubscriptexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SetSubscriptExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2161 = alg_hold_top;
    Value ret_561 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_subscript_set("), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Index"))}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_561;
    alg_hold_top = rh_2161;
    Value ret_562 = alg_nil();
    alg_root_top = rt_base;
    return ret_562;
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
    int32_t rh_2162 = alg_hold_top;
    if (alg_truthy(alg_hold((or_115 = alg_hold(alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){v_unit}, 1)), !alg_truthy(or_115) ? or_115 : alg_hold(alg_not(alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_unit}, 1), ALG_KIND_SET, "Set"))), "Contains", (Value[]){v_name}, 1)))))))) {
        Value ret_563 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_error("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined name '"), v_name)), alg_literal("' in unit '"))), v_unit)), alg_literal("'.")))}, 1)))), alg_literal("), alg_nil())")));
        alg_root_top = rt_base;
        return ret_563;
    }
    alg_hold_top = rh_2162;
    if (alg_truthy(alg_hold(alg_equal(v_unit, alg_literal("System"))))) {
        (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), v_unit)), alg_char_value(46))), v_name)), alg_literal("' as a value")))}, 1)));
    }
    alg_hold_top = rh_2162;
    Value v_saved = alg_property(v_this, "Renames");
    (void)v_saved;
    alg_root(&v_saved, 1);
    alg_hold_top = rh_2162;
    (void)(alg_set_property(v_this, "Renames", alg_hold(alg_invoke(v_this, "RenamesOf", (Value[]){v_unit, v_name}, 2))));
    alg_hold_top = rh_2162;
    Value v_built = alg_literal("");
    (void)v_built;
    alg_root(&v_built, 1);
    alg_hold_top = rh_2162;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "EnumMembers"), "Contains", (Value[]){v_name}, 1)))) {
        (void)((v_built = alg_hold(alg_invoke(v_this, "EnumMemberName", (Value[]){alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){v_name}, 1)))), v_name}, 2))));
    } else {
        if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "EnumTypes"), "Contains", (Value[]){v_name}, 1)))) {
            (void)((v_built = alg_hold(alg_invoke(v_this, "EnumTypeName", (Value[]){v_name}, 1))));
        } else {
            if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Objects"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))) {
                (void)((v_built = alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_singleton("), alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1)))), alg_char_value(41)))));
            } else {
                if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Classes"), "Contains", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_name}, 1))}, 1)))) {
                    (void)((v_built = alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){v_name}, 1))));
                } else {
                    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Declared"), "Contains", (Value[]){v_name}, 1)))) {
                        (void)((v_built = alg_hold(alg_invoke(v_this, "SubprogramValue", (Value[]){v_name}, 1))));
                    } else {
                        if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))) {
                            (void)((v_built = alg_hold(alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_hold(alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1))}, 2))));
                        }
                    }
                }
            }
        }
    }
    alg_hold_top = rh_2162;
    (void)(alg_set_property(v_this, "Renames", v_saved));
    alg_hold_top = rh_2162;
    if (alg_truthy(alg_hold(alg_not_equal(v_built, alg_literal(""))))) {
        Value ret_564 = v_built;
        alg_root_top = rt_base;
        return ret_564;
    }
    alg_hold_top = rh_2162;
    (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(39), v_unit)), alg_char_value(46))), v_name)), alg_literal("' as a value")))}, 1)));
    alg_hold_top = rh_2162;
    Value ret_565 = alg_literal("");
    alg_root_top = rt_base;
    return ret_565;
    alg_hold_top = rh_2162;
    Value ret_566 = alg_nil();
    alg_root_top = rt_base;
    return ret_566;
}

static Value m_cemitter_visitgetexpr_1_getexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "GetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2163 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_theexpr, "Unit")), alg_literal(""))))) {
        Value ret_567 = alg_hold(alg_invoke(v_this, "UnitValue", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "Unit")))), alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 2));
        alg_root_top = rt_base;
        return ret_567;
    }
    alg_hold_top = rh_2163;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "Extension")))), alg_literal(""))))) {
        Value ret_568 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_property_or("), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ExtensionValue", (Value[]){v_theexpr}, 1)))), alg_char_value(41)));
        alg_root_top = rt_base;
        return ret_568;
    }
    alg_hold_top = rh_2163;
    Value ret_569 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_property("), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 1)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_569;
    alg_hold_top = rh_2163;
    Value ret_570 = alg_nil();
    alg_root_top = rt_base;
    return ret_570;
}

static Value m_cemitter_visitsetexpr_1_setexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SetExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2164 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_theexpr, "Unit")), alg_literal(""))))) {
        {
            int32_t rt_2165 = alg_root_top;
            int32_t rh_2166 = alg_hold_top;
            Value v_written = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1));
            (void)v_written;
            alg_root(&v_written, 1);
            alg_hold_top = rh_2166;
            Value v_unit = alg_hold(alg_str(alg_hold(alg_property(v_theexpr, "Unit"))));
            (void)v_unit;
            alg_root(&v_unit, 1);
            alg_hold_top = rh_2166;
            Value v_name = alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))));
            (void)v_name;
            alg_root(&v_name, 1);
            alg_hold_top = rh_2166;
            if (alg_truthy(alg_hold((or_116 = alg_hold(alg_invoke(alg_property(v_this, "UnitExports"), "Contains", (Value[]){v_unit}, 1)), !alg_truthy(or_116) ? or_116 : alg_hold(alg_not(alg_hold(alg_invoke((alg_hold(alg_cast_kind(alg_invoke(alg_property(v_this, "UnitExports"), "Get", (Value[]){v_unit}, 1), ALG_KIND_SET, "Set"))), "Contains", (Value[]){v_name}, 1)))))))) {
                Value ret_571 = alg_hold(alg_add(alg_hold(alg_add(alg_literal("(alg_error("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("Undefined name '"), v_name)), alg_literal("' in unit '"))), v_unit)), alg_literal("'.")))}, 1)))), alg_literal("), alg_nil())")));
                alg_root_top = rt_base;
                return ret_571;
            }
            alg_hold_top = rh_2166;
            if (alg_truthy(alg_hold((or_117 = alg_hold(alg_not_equal(v_unit, alg_literal("System"))), !alg_truthy(or_117) ? or_117 : alg_hold(alg_invoke(alg_property(v_this, "Globals"), "Contains", (Value[]){v_name}, 1)))))) {
                Value ret_572 = alg_hold(alg_invoke(v_this, "Guarded", (Value[]){v_name, alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(40), alg_hold(alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)))), alg_literal(" = "))), v_written)), alg_char_value(41)))}, 2));
                alg_root_top = rt_base;
                return ret_572;
            }
            alg_hold_top = rh_2166;
            (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("An assignment to '"), v_unit)), alg_char_value(46))), v_name)), alg_char_value(39)))}, 1)));
            alg_hold_top = rh_2166;
            alg_root_top = rt_2165;
        }
    }
    alg_hold_top = rh_2164;
    Value ret_573 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_set_property("), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Obj"))}, 1)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Name")), "Lexeme"))))}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "BoundValue", (Value[]){alg_hold(alg_property(v_theexpr, "Declared")), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_theexpr, "Value"))}, 1)), alg_hold(alg_property(v_theexpr, "Actual"))}, 3)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_573;
    alg_hold_top = rh_2164;
    Value ret_574 = alg_nil();
    alg_root_top = rt_base;
    return ret_574;
}

static Value m_cemitter_visitsuperexpr_1_superexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "SuperExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2167 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_property(v_this, "CurrentClass"), alg_literal(""))))) {
        (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_literal("'super' outside a class")}, 1)));
    }
    alg_hold_top = rh_2167;
    Value ret_575 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_bound_from("), alg_hold(alg_invoke(v_this, "ClassHandle", (Value[]){alg_property(v_this, "CurrentClass")}, 1)))), alg_literal(", "))), alg_hold(alg_invoke(v_this, "ThisRef", NULL, 0)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_theexpr, "Method")), "Lexeme"))))}, 1)))), alg_char_value(41)));
    alg_root_top = rt_base;
    return ret_575;
    alg_hold_top = rh_2167;
    Value ret_576 = alg_nil();
    alg_root_top = rt_base;
    return ret_576;
}

static Value m_cemitter_visitthisexpr_1_thisexpr(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_theexpr = alg_widen(args[0], "ThisExpr");
    (void)v_theexpr;
    alg_root(&v_theexpr, 1);
    int32_t rh_2168 = alg_hold_top;
    Value ret_577 = alg_hold(alg_invoke(v_this, "ThisRef", NULL, 0));
    alg_root_top = rt_base;
    return ret_577;
    alg_hold_top = rh_2168;
    Value ret_578 = alg_nil();
    alg_root_top = rt_base;
    return ret_578;
}

static Value m_cemitter_visitclassstmt_1_classstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ClassStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2169 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "EmitClass", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), alg_hold(alg_property(v_thestmt, "Superclass")), alg_hold(alg_property(v_thestmt, "Fields")), alg_hold(alg_property(v_thestmt, "Methods")), alg_bool(false)}, 5)));
    alg_hold_top = rh_2169;
    Value ret_579 = alg_nil();
    alg_root_top = rt_base;
    return ret_579;
}

static Value m_cemitter_visitobjectstmt_1_objectstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ObjectStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2170 = alg_hold_top;
    (void)(alg_hold(alg_invoke(v_this, "EmitClass", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), alg_hold(alg_property(v_thestmt, "Superclass")), alg_hold(alg_property(v_thestmt, "Fields")), alg_hold(alg_property(v_thestmt, "Methods")), alg_bool(true)}, 5)));
    alg_hold_top = rh_2170;
    Value ret_580 = alg_nil();
    alg_root_top = rt_base;
    return ret_580;
}

static Value m_cemitter_visitsubrangestmt_1_subrangestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "SubrangeStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2171 = alg_hold_top;
    Value ret_581 = alg_nil();
    alg_root_top = rt_base;
    return ret_581;
}

static Value m_cemitter_emitsubranges_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    int32_t rh_2172 = alg_hold_top;
    {
        int32_t rt_2173 = alg_root_top;
        int32_t rh_2174 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2174;
        {
            int32_t rh_2175 = alg_hold_top;
            for (; (alg_hold_top = rh_2175, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property((alg_declared(d_subrangeVnames, "SUBRANGE_NAMES"), v_subrangeVnames), "Length")))))); (alg_hold_top = rh_2175, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                (void)(alg_hold(alg_invoke(alg_property(v_this, "Shells"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    alg_subrange("), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get((alg_declared(d_subrangeVnames, "SUBRANGE_NAMES"), v_subrangeVnames), v_i))))}, 1)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get((alg_declared(d_subrangeVlows, "SUBRANGE_LOWS"), v_subrangeVlows), v_i))))}, 1)))), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get((alg_declared(d_subrangeVhighs, "SUBRANGE_HIGHS"), v_subrangeVhighs), v_i))))}, 1)))), alg_literal(");"))), alg_char_value(10)))}, 1)));
            }
        }
        alg_hold_top = rh_2174;
        alg_root_top = rt_2173;
    }
    alg_hold_top = rh_2172;
    Value ret_582 = alg_nil();
    alg_root_top = rt_base;
    return ret_582;
}

static Value m_cemitter_visitenumstmt_1_enumstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "EnumStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2176 = alg_hold_top;
    Value v_thetype = alg_nil();
    (void)v_thetype;
    alg_root(&v_thetype, 1);
    alg_hold_top = rh_2176;
    (void)((v_thetype = alg_hold(alg_invoke(v_this, "EnumTypeName", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1))));
    alg_hold_top = rh_2176;
    (void)(alg_hold(alg_invoke(v_this, "DeclareValue", (Value[]){v_thetype, alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 2)));
    alg_hold_top = rh_2176;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    "), v_thetype)), alg_literal(" = alg_enum_type("))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)))), alg_literal(");"))), alg_char_value(10)))}, 1)));
    alg_hold_top = rh_2176;
    {
        int32_t rt_2177 = alg_root_top;
        Value loop_583 = alg_iterable(alg_hold(alg_property(v_thestmt, "Members")));
        (void)loop_583;
        alg_root(&loop_583, 1);
        for (int32_t at_583 = 0; at_583 < alg_iterable_count(loop_583); at_583++) {
            alg_safe_point();
            int32_t rt_2178 = alg_root_top;
            Value v_member = alg_iterable_at(loop_583, at_583);
            (void)v_member;
            alg_root(&v_member, 1);
            {
                int32_t rt_2179 = alg_root_top;
                int32_t rh_2180 = alg_hold_top;
                Value v_symbol = alg_hold(alg_invoke(v_this, "EnumMemberName", (Value[]){alg_hold(alg_str(alg_hold(alg_invoke(alg_property(v_this, "EnumMembers"), "Get", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_member, "Lexeme"))))}, 1)))), alg_hold(alg_str(alg_hold(alg_property(v_member, "Lexeme"))))}, 2));
                (void)v_symbol;
                alg_root(&v_symbol, 1);
                alg_hold_top = rh_2180;
                (void)(alg_hold(alg_invoke(v_this, "DeclareValue", (Value[]){v_symbol, alg_hold(alg_str(alg_hold(alg_property(v_member, "Lexeme"))))}, 2)));
                alg_hold_top = rh_2180;
                (void)(alg_hold(alg_invoke(alg_property(v_this, "Setup"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("    "), v_symbol)), alg_literal(" = alg_enum_member("))), v_thetype)), alg_literal(", "))), alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_member, "Lexeme"))))}, 1)))), alg_literal(");"))), alg_char_value(10)))}, 1)));
                alg_hold_top = rh_2180;
                alg_root_top = rt_2179;
            }
            alg_root_top = rt_2178;
        }
        alg_root_top = rt_2177;
    }
    alg_hold_top = rh_2176;
    Value ret_584 = alg_nil();
    alg_root_top = rt_base;
    return ret_584;
}

static Value m_cemitter_visittrystmt_1_trystmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "TryStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2181 = alg_hold_top;
    Value v_id = alg_nil();
    (void)v_id;
    alg_root(&v_id, 1);
    alg_hold_top = rh_2181;
    Value v_frame = alg_nil();
    (void)v_frame;
    alg_root(&v_frame, 1);
    alg_hold_top = rh_2181;
    Value v_handlers = alg_nil();
    (void)v_handlers;
    alg_root(&v_handlers, 1);
    alg_hold_top = rh_2181;
    Value v_catchall = alg_nil();
    (void)v_catchall;
    alg_root(&v_catchall, 1);
    alg_hold_top = rh_2181;
    Value v_keys = alg_nil();
    (void)v_keys;
    alg_root(&v_keys, 1);
    alg_hold_top = rh_2181;
    (void)((v_id = alg_property(v_this, "Loops")));
    alg_hold_top = rh_2181;
    (void)(alg_set_property(v_this, "Loops", alg_hold(alg_add(alg_property(v_this, "Loops"), alg_int(1)))));
    alg_hold_top = rh_2181;
    (void)((v_frame = alg_hold(alg_add(alg_literal("frame_"), alg_hold(alg_str(v_id))))));
    alg_hold_top = rh_2181;
    (void)((v_handlers = alg_hold(alg_list())));
    alg_hold_top = rh_2181;
    (void)((v_catchall = alg_nil()));
    alg_hold_top = rh_2181;
    (void)((v_keys = alg_hold(alg_invoke(alg_hold(alg_property(v_thestmt, "Handlers")), "Keys", NULL, 0))));
    alg_hold_top = rh_2181;
    {
        int32_t rt_2182 = alg_root_top;
        Value loop_585 = alg_iterable(v_keys);
        (void)loop_585;
        alg_root(&loop_585, 1);
        for (int32_t at_585 = 0; at_585 < alg_iterable_count(loop_585); at_585++) {
            alg_safe_point();
            int32_t rt_2183 = alg_root_top;
            Value v_key = alg_iterable_at(loop_585, at_585);
            (void)v_key;
            alg_root(&v_key, 1);
            {
                int32_t rh_2184 = alg_hold_top;
                if (alg_truthy(alg_hold(alg_equal(v_key, alg_literal("default"))))) {
                    (void)((v_catchall = alg_hold(alg_invoke(alg_hold(alg_property(v_thestmt, "Handlers")), "Get", (Value[]){v_key}, 1))));
                } else {
                    (void)(alg_hold(alg_invoke(v_handlers, "Add", (Value[]){v_key}, 1)));
                }
                alg_hold_top = rh_2184;
            }
            alg_root_top = rt_2183;
        }
        alg_root_top = rt_2182;
    }
    alg_hold_top = rh_2181;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1)));
    alg_hold_top = rh_2181;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_2181;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("AlgFrame "), v_frame)), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_2181;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_push_frame(&"), v_frame)), alg_literal(");")))}, 1)));
    alg_hold_top = rh_2181;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("if (ALG_SETJMP("), v_frame)), alg_literal(".jump) == 0) {")))}, 1)));
    alg_hold_top = rh_2181;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_2181;
    (void)(alg_set_property(v_this, "TryDepth", alg_hold(alg_add(alg_property(v_this, "TryDepth"), alg_int(1)))));
    alg_hold_top = rh_2181;
    (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_thestmt, "TryBlock"))}, 1)));
    alg_hold_top = rh_2181;
    (void)(alg_set_property(v_this, "TryDepth", alg_hold(alg_subtract(alg_property(v_this, "TryDepth"), alg_int(1)))));
    alg_hold_top = rh_2181;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_literal("alg_pop_frame();")}, 1)));
    alg_hold_top = rh_2181;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_2181;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1)));
    alg_hold_top = rh_2181;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_literal("else {")}, 1)));
    alg_hold_top = rh_2181;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_2181;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_handlers, "Length")), alg_int(0))))) {
        (void)(alg_hold(alg_invoke(v_this, "EmitHandlerBody", (Value[]){v_catchall, v_frame}, 2)));
    } else {
        {
            int32_t rt_2185 = alg_root_top;
            int32_t rh_2186 = alg_hold_top;
            Value v_names = alg_literal("");
            (void)v_names;
            alg_root(&v_names, 1);
            alg_hold_top = rh_2186;
            {
                int32_t rt_2187 = alg_root_top;
                int32_t rh_2188 = alg_hold_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_2188;
                {
                    int32_t rh_2189 = alg_hold_top;
                    for (; (alg_hold_top = rh_2189, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_handlers, "Length")))))); (alg_hold_top = rh_2189, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                        alg_safe_point();
                        {
                            int32_t rh_2190 = alg_hold_top;
                            if (alg_truthy(alg_hold(alg_greater(v_i, alg_int(0))))) {
                                (void)((v_names = alg_hold(alg_add(v_names, alg_literal(", ")))));
                            }
                            alg_hold_top = rh_2190;
                            (void)((v_names = alg_hold(alg_add(v_names, alg_hold(f_quotec(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(v_handlers, v_i))))}, 1))))));
                            alg_hold_top = rh_2190;
                        }
                    }
                }
                alg_hold_top = rh_2188;
                alg_root_top = rt_2187;
            }
            alg_hold_top = rh_2186;
            Value v_table = alg_hold(alg_add(alg_literal("names_"), alg_hold(alg_str(v_id))));
            (void)v_table;
            alg_root(&v_table, 1);
            alg_hold_top = rh_2186;
            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static const char *"), v_table)), alg_literal("[] = {"))), v_names)), alg_literal("};")))}, 1)));
            alg_hold_top = rh_2186;
            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("int32_t which_"), alg_hold(alg_str(v_id)))), alg_literal(" = alg_handler("))), v_frame)), alg_literal(".raised, "))), v_table)), alg_literal(", "))), alg_hold(alg_str(alg_hold(alg_property(v_handlers, "Length")))))), alg_literal(");")))}, 1)));
            alg_hold_top = rh_2186;
            {
                int32_t rt_2191 = alg_root_top;
                int32_t rh_2192 = alg_hold_top;
                Value v_i = alg_int(0);
                (void)v_i;
                alg_root(&v_i, 1);
                alg_hold_top = rh_2192;
                {
                    int32_t rh_2193 = alg_hold_top;
                    for (; (alg_hold_top = rh_2193, alg_truthy(alg_hold(alg_less(v_i, alg_hold(alg_property(v_handlers, "Length")))))); (alg_hold_top = rh_2193, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                        alg_safe_point();
                        {
                            int32_t rt_2194 = alg_root_top;
                            int32_t rh_2195 = alg_hold_top;
                            Value v_lead = alg_literal("else if");
                            (void)v_lead;
                            alg_root(&v_lead, 1);
                            alg_hold_top = rh_2195;
                            if (alg_truthy(alg_hold(alg_equal(v_i, alg_int(0))))) {
                                (void)((v_lead = alg_literal("if")));
                            }
                            alg_hold_top = rh_2195;
                            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_lead, alg_literal(" (which_"))), alg_hold(alg_str(v_id)))), alg_literal(" == "))), alg_hold(alg_str(v_i)))), alg_literal(") {")))}, 1)));
                            alg_hold_top = rh_2195;
                            (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
                            alg_hold_top = rh_2195;
                            (void)(alg_hold(alg_invoke(v_this, "EmitHandlerBody", (Value[]){alg_hold(alg_invoke(alg_hold(alg_property(v_thestmt, "Handlers")), "Get", (Value[]){alg_hold(alg_subscript_get(v_handlers, v_i))}, 1)), v_frame}, 2)));
                            alg_hold_top = rh_2195;
                            (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
                            alg_hold_top = rh_2195;
                            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1)));
                            alg_hold_top = rh_2195;
                            alg_root_top = rt_2194;
                        }
                    }
                }
                alg_hold_top = rh_2192;
                alg_root_top = rt_2191;
            }
            alg_hold_top = rh_2186;
            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_literal("else {")}, 1)));
            alg_hold_top = rh_2186;
            (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
            alg_hold_top = rh_2186;
            if (alg_truthy(alg_hold(alg_not_equal(v_catchall, alg_nil())))) {
                (void)(alg_hold(alg_invoke(v_this, "EmitHandlerBody", (Value[]){v_catchall, v_frame}, 2)));
            } else {
                (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_raise("), v_frame)), alg_literal(".raised);")))}, 1)));
            }
            alg_hold_top = rh_2186;
            (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
            alg_hold_top = rh_2186;
            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1)));
            alg_hold_top = rh_2186;
            alg_root_top = rt_2185;
        }
    }
    alg_hold_top = rh_2181;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_2181;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1)));
    alg_hold_top = rh_2181;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_2181;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1)));
    alg_hold_top = rh_2181;
    Value ret_586 = alg_nil();
    alg_root_top = rt_base;
    return ret_586;
}

static Value m_cemitter_visitraisestmt_1_raisestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "RaiseStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2196 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_thestmt, "Value")), alg_nil())))) {
        (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_literal("alg_raise(alg_nil());")}, 1)));
    } else {
        (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_raise("), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Value"))}, 1)))), alg_literal(");")))}, 1)));
    }
    alg_hold_top = rh_2196;
    Value ret_587 = alg_nil();
    alg_root_top = rt_base;
    return ret_587;
}

static Value m_cemitter_visitforinstmt_1_forinstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ForInStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2197 = alg_hold_top;
    Value v_id = alg_nil();
    (void)v_id;
    alg_root(&v_id, 1);
    alg_hold_top = rh_2197;
    Value v_snapshot = alg_nil();
    (void)v_snapshot;
    alg_root(&v_snapshot, 1);
    alg_hold_top = rh_2197;
    Value v_index = alg_nil();
    (void)v_index;
    alg_root(&v_index, 1);
    alg_hold_top = rh_2197;
    Value v_counter = alg_nil();
    (void)v_counter;
    alg_root(&v_counter, 1);
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "RefuseBareBinding", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1)));
    alg_hold_top = rh_2197;
    (void)((v_id = alg_property(v_this, "Loops")));
    alg_hold_top = rh_2197;
    (void)(alg_set_property(v_this, "Loops", alg_hold(alg_add(alg_property(v_this, "Loops"), alg_int(1)))));
    alg_hold_top = rh_2197;
    (void)((v_snapshot = alg_hold(alg_add(alg_literal("loop_"), alg_hold(alg_str(v_id))))));
    alg_hold_top = rh_2197;
    (void)((v_index = alg_hold(alg_add(alg_literal("at_"), alg_hold(alg_str(v_id))))));
    alg_hold_top = rh_2197;
    Value v_mark = alg_hold(alg_invoke(v_this, "OpenScope", NULL, 0));
    (void)v_mark;
    alg_root(&v_mark, 1);
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(123)}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_2197;
    Value v_outerroots = alg_hold(alg_invoke(v_this, "OpenRoots", (Value[]){alg_bool(true)}, 1));
    (void)v_outerroots;
    alg_root(&v_outerroots, 1);
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "DeclareLocal", (Value[]){v_snapshot, alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_iterable("), alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Iterable"))}, 1)))), alg_char_value(41)))}, 2)));
    alg_hold_top = rh_2197;
    (void)((v_counter = alg_literal("int32_t ")));
    alg_hold_top = rh_2197;
    if (alg_truthy(alg_property(v_this, "Volatiles"))) {
        (void)((v_counter = alg_literal("volatile int32_t ")));
    }
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("for ("), v_counter)), v_index)), alg_literal(" = 0; "))), v_index)), alg_literal(" < alg_iterable_count("))), v_snapshot)), alg_literal("); "))), v_index)), alg_literal("++) {")))}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_add(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "EmitSafePoint", NULL, 0)));
    alg_hold_top = rh_2197;
    Value v_iterroots = alg_hold(alg_invoke(v_this, "OpenRoots", (Value[]){alg_bool(true)}, 1));
    (void)v_iterroots;
    alg_root(&v_iterroots, 1);
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)));
    alg_hold_top = rh_2197;
    Value v_element = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("alg_iterable_at("), v_snapshot)), alg_literal(", "))), v_index)), alg_char_value(41)));
    (void)v_element;
    alg_root(&v_element, 1);
    alg_hold_top = rh_2197;
    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)))) {
        (void)(alg_hold(alg_invoke(v_this, "DeclareCell", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme")))), v_element}, 2)));
    } else {
        {
            int32_t rh_2198 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_hold(alg_invoke(v_this, "VariableName", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)), v_element}, 2)));
            alg_hold_top = rh_2198;
        }
    }
    alg_hold_top = rh_2197;
    Value v_enclosingloopdepth = alg_property(v_this, "LoopTryDepth");
    (void)v_enclosingloopdepth;
    alg_root(&v_enclosingloopdepth, 1);
    alg_hold_top = rh_2197;
    (void)(alg_set_property(v_this, "LoopTryDepth", alg_property(v_this, "TryDepth")));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LoopLabels"), "Add", (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LoopDepths"), "Add", (Value[]){alg_property(v_this, "TryDepth")}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_thestmt, "Body"))}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LoopLabels"), "RemoveAt", (Value[]){alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "LoopLabels"), "Length")), alg_int(1)))}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "LoopDepths"), "RemoveAt", (Value[]){alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "LoopDepths"), "Length")), alg_int(1)))}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_set_property(v_this, "LoopTryDepth", v_enclosingloopdepth));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "EmitContinueTarget", (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "CloseRoots", (Value[]){v_iterroots}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "EmitBreakTarget", (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "CloseRoots", (Value[]){v_outerroots}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_set_property(v_this, "Depth", alg_hold(alg_subtract(alg_property(v_this, "Depth"), alg_int(1)))));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_char_value(125)}, 1)));
    alg_hold_top = rh_2197;
    (void)(alg_hold(alg_invoke(v_this, "CloseScope", (Value[]){v_mark}, 1)));
    alg_hold_top = rh_2197;
    Value ret_588 = alg_nil();
    alg_root_top = rt_base;
    return ret_588;
}

static Value m_cemitter_breaktarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    int32_t rh_2199 = alg_hold_top;
    Value ret_589 = alg_hold(alg_add(alg_literal("lb_"), alg_hold(alg_invoke(v_this, "Escaped", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_thelabel}, 1))}, 1))));
    alg_root_top = rt_base;
    return ret_589;
    alg_hold_top = rh_2199;
    Value ret_590 = alg_nil();
    alg_root_top = rt_base;
    return ret_590;
}

static Value m_cemitter_continuetarget_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    int32_t rh_2200 = alg_hold_top;
    Value ret_591 = alg_hold(alg_add(alg_literal("lc_"), alg_hold(alg_invoke(v_this, "Escaped", (Value[]){alg_hold(f_foldcase(NULL, (Value[]){v_thelabel}, 1))}, 1))));
    alg_root_top = rt_base;
    return ret_591;
    alg_hold_top = rh_2200;
    Value ret_592 = alg_nil();
    alg_root_top = rt_base;
    return ret_592;
}

static Value m_cemitter_depthofloop_1_string(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thelabel = alg_widen(args[0], "String");
    (void)v_thelabel;
    alg_root(&v_thelabel, 1);
    int32_t rh_2201 = alg_hold_top;
    {
        int32_t rt_2202 = alg_root_top;
        int32_t rh_2203 = alg_hold_top;
        Value v_i = alg_hold(alg_subtract(alg_hold(alg_property(alg_property(v_this, "LoopLabels"), "Length")), alg_int(1)));
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2203;
        {
            int32_t rh_2204 = alg_hold_top;
            for (; (alg_hold_top = rh_2204, alg_truthy(alg_hold(alg_greater_equal(v_i, alg_int(0))))); (alg_hold_top = rh_2204, (v_i = alg_hold(alg_subtract(v_i, alg_int(1)))))) {
                alg_safe_point();
                if (alg_truthy(alg_hold(alg_equal(alg_hold(f_foldcase(NULL, (Value[]){alg_hold(alg_str(alg_hold(alg_subscript_get(alg_property(v_this, "LoopLabels"), v_i))))}, 1)), alg_hold(f_foldcase(NULL, (Value[]){v_thelabel}, 1)))))) {
                    Value ret_593 = alg_hold(alg_cast_kind(alg_subscript_get(alg_property(v_this, "LoopDepths"), v_i), ALG_KIND_INTEGER, "Integer"));
                    alg_root_top = rt_base;
                    return ret_593;
                }
            }
        }
        alg_hold_top = rh_2203;
        alg_root_top = rt_2202;
    }
    alg_hold_top = rh_2201;
    Value ret_594 = alg_property(v_this, "LoopTryDepth");
    alg_root_top = rt_base;
    return ret_594;
    alg_hold_top = rh_2201;
    Value ret_595 = alg_nil();
    alg_root_top = rt_base;
    return ret_595;
}

static Value m_cemitter_popframesto_1_integer(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_from = alg_widen(args[0], "Integer");
    (void)v_from;
    alg_root(&v_from, 1);
    int32_t rh_2205 = alg_hold_top;
    {
        int32_t rt_2206 = alg_root_top;
        int32_t rh_2207 = alg_hold_top;
        Value v_i = v_from;
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_2207;
        {
            int32_t rh_2208 = alg_hold_top;
            for (; (alg_hold_top = rh_2208, alg_truthy(alg_hold(alg_less(v_i, alg_property(v_this, "TryDepth"))))); (alg_hold_top = rh_2208, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_literal("alg_pop_frame();")}, 1)));
            }
        }
        alg_hold_top = rh_2207;
        alg_root_top = rt_2206;
    }
    alg_hold_top = rh_2205;
    Value ret_596 = alg_nil();
    alg_root_top = rt_base;
    return ret_596;
}

static Value m_cemitter_visitbreakstmt_1_breakstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "BreakStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2209 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_thestmt, "Label")), alg_literal(""))))) {
        {
            int32_t rh_2210 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_property(v_this, "LoopTryDepth")}, 1)));
            alg_hold_top = rh_2210;
            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_literal("break;")}, 1)));
            alg_hold_top = rh_2210;
            Value ret_597 = alg_nil();
            alg_root_top = rt_base;
            return ret_597;
            alg_hold_top = rh_2210;
        }
    }
    alg_hold_top = rh_2209;
    (void)(alg_hold(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_hold(alg_invoke(v_this, "DepthOfLoop", (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1))}, 1)));
    alg_hold_top = rh_2209;
    Value v_target = alg_hold(alg_invoke(v_this, "BreakTarget", (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1));
    (void)v_target;
    alg_root(&v_target, 1);
    alg_hold_top = rh_2209;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Jumped"), "Add", (Value[]){v_target}, 1)));
    alg_hold_top = rh_2209;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("goto "), v_target)), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_2209;
    Value ret_598 = alg_nil();
    alg_root_top = rt_base;
    return ret_598;
}

static Value m_cemitter_visitcontinuestmt_1_continuestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ContinueStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2211 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(alg_hold(alg_property(v_thestmt, "Label")), alg_literal(""))))) {
        {
            int32_t rh_2212 = alg_hold_top;
            (void)(alg_hold(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_property(v_this, "LoopTryDepth")}, 1)));
            alg_hold_top = rh_2212;
            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_literal("continue;")}, 1)));
            alg_hold_top = rh_2212;
            Value ret_599 = alg_nil();
            alg_root_top = rt_base;
            return ret_599;
            alg_hold_top = rh_2212;
        }
    }
    alg_hold_top = rh_2211;
    (void)(alg_hold(alg_invoke(v_this, "PopFramesTo", (Value[]){alg_hold(alg_invoke(v_this, "DepthOfLoop", (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1))}, 1)));
    alg_hold_top = rh_2211;
    Value v_target = alg_hold(alg_invoke(v_this, "ContinueTarget", (Value[]){alg_hold(alg_property(v_thestmt, "Label"))}, 1));
    (void)v_target;
    alg_root(&v_target, 1);
    alg_hold_top = rh_2211;
    (void)(alg_hold(alg_invoke(alg_property(v_this, "Jumped"), "Add", (Value[]){v_target}, 1)));
    alg_hold_top = rh_2211;
    (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("goto "), v_target)), alg_char_value(59)))}, 1)));
    alg_hold_top = rh_2211;
    Value ret_600 = alg_nil();
    alg_root_top = rt_base;
    return ret_600;
}

static Value m_cemitter_visitlabelstmt_1_labelstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "LabelStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2213 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_property(v_thestmt, "Targeted")))) {
        (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_invoke(v_this, "GotoTarget", (Value[]){alg_hold(alg_str(alg_hold(alg_property(alg_hold(alg_property(v_thestmt, "Name")), "Lexeme"))))}, 1)), alg_literal(": ;")))}, 1)));
    }
    alg_hold_top = rh_2213;
    (void)(alg_hold(alg_invoke(v_this, "Execute", (Value[]){alg_hold(alg_property(v_thestmt, "Inner"))}, 1)));
    alg_hold_top = rh_2213;
    Value ret_601 = alg_nil();
    alg_root_top = rt_base;
    return ret_601;
}

static Value m_cemitter_visitvargroupstmt_1_vargroupstmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "VarGroupStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2214 = alg_hold_top;
    Value v_value = alg_nil();
    (void)v_value;
    alg_root(&v_value, 1);
    alg_hold_top = rh_2214;
    Value v_shared = alg_nil();
    (void)v_shared;
    alg_root(&v_shared, 1);
    alg_hold_top = rh_2214;
    (void)((v_value = alg_literal("alg_nil()")));
    alg_hold_top = rh_2214;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Initializer")), alg_nil())))) {
        (void)((v_value = alg_hold(alg_invoke(v_this, "Evaluate", (Value[]){alg_hold(alg_property(v_thestmt, "Initializer"))}, 1))));
    }
    alg_hold_top = rh_2214;
    (void)((v_shared = alg_hold(alg_add(alg_literal("shared_"), alg_hold(alg_str(alg_property(v_this, "Loops")))))));
    alg_hold_top = rh_2214;
    (void)(alg_set_property(v_this, "Loops", alg_hold(alg_add(alg_property(v_this, "Loops"), alg_int(1)))));
    alg_hold_top = rh_2214;
    if (alg_truthy(alg_property(v_this, "AtTopLevel"))) {
        {
            int32_t rh_2215 = alg_hold_top;
            (void)(alg_hold(alg_invoke(alg_property(v_this, "Declarations"), "Append", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_literal("static Value "), v_shared)), alg_char_value(59))), alg_char_value(10)))}, 1)));
            alg_hold_top = rh_2215;
            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(v_shared, alg_literal(" = "))), v_value)), alg_char_value(59)))}, 1)));
            alg_hold_top = rh_2215;
        }
    } else {
        (void)(alg_hold(alg_invoke(v_this, "DeclareLocal", (Value[]){v_shared, v_value}, 2)));
    }
    alg_hold_top = rh_2214;
    {
        int32_t rt_2216 = alg_root_top;
        Value loop_602 = alg_iterable(alg_hold(alg_property(v_thestmt, "Names")));
        (void)loop_602;
        alg_root(&loop_602, 1);
        for (int32_t at_602 = 0; at_602 < alg_iterable_count(loop_602); at_602++) {
            alg_safe_point();
            int32_t rt_2217 = alg_root_top;
            Value v_thename = alg_iterable_at(loop_602, at_602);
            (void)v_thename;
            alg_root(&v_thename, 1);
            {
                int32_t rt_2218 = alg_root_top;
                int32_t rh_2219 = alg_hold_top;
                Value v_name = alg_hold(alg_str(alg_hold(alg_property(v_thename, "Lexeme"))));
                (void)v_name;
                alg_root(&v_name, 1);
                alg_hold_top = rh_2219;
                if (alg_truthy(alg_property(v_this, "AtTopLevel"))) {
                    {
                        int32_t rh_2220 = alg_hold_top;
                        (void)(alg_hold(alg_invoke(v_this, "DeclareVariable", (Value[]){alg_hold(alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), v_name}, 2)));
                        alg_hold_top = rh_2220;
                        (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), alg_literal(" = "))), v_shared)), alg_char_value(59)))}, 1)));
                        alg_hold_top = rh_2220;
                        (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_invoke(v_this, "DeclaredFlag", (Value[]){v_name}, 1)), alg_literal(" = true;")))}, 1)));
                        alg_hold_top = rh_2220;
                    }
                } else {
                    if (alg_truthy(alg_hold(alg_invoke(alg_property(v_this, "Boxed"), "Contains", (Value[]){v_name}, 1)))) {
                        {
                            int32_t rh_2221 = alg_hold_top;
                            (void)(alg_hold(alg_invoke(v_this, "RequireCell", (Value[]){v_name}, 1)));
                            alg_hold_top = rh_2221;
                            (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_name}, 1)));
                            alg_hold_top = rh_2221;
                            (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_char_value(42), alg_hold(alg_invoke(v_this, "Cell", (Value[]){v_name}, 1)))), alg_literal(" = "))), v_shared)), alg_char_value(59)))}, 1)));
                            alg_hold_top = rh_2221;
                        }
                    } else {
                        {
                            int32_t rh_2222 = alg_hold_top;
                            (void)(alg_hold(alg_invoke(alg_property(v_this, "Locals"), "Add", (Value[]){v_name}, 1)));
                            alg_hold_top = rh_2222;
                            (void)(alg_hold(alg_invoke(v_this, "DeclareLocal", (Value[]){alg_hold(alg_invoke(v_this, "VariableName", (Value[]){v_name}, 1)), v_shared}, 2)));
                            alg_hold_top = rh_2222;
                        }
                    }
                }
                alg_hold_top = rh_2219;
                alg_root_top = rt_2218;
            }
            alg_root_top = rt_2217;
        }
        alg_root_top = rt_2216;
    }
    alg_hold_top = rh_2214;
    Value ret_603 = alg_nil();
    alg_root_top = rt_base;
    return ret_603;
}

static Value m_cemitter_visitmodulestmt_1_modulestmt(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    int32_t rt_base = alg_root_top;
    alg_root(&v_this, 1);
    alg_root(args, count);
    Value v_thestmt = alg_widen(args[0], "ModuleStmt");
    (void)v_thestmt;
    alg_root(&v_thestmt, 1);
    int32_t rh_2223 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_not(alg_property(v_this, "AtTopLevel"))))) {
        (void)(alg_hold(alg_invoke(v_this, "Unsupported", (Value[]){alg_literal("A nested 'uses'")}, 1)));
    }
    alg_hold_top = rh_2223;
    if (alg_truthy(alg_hold(alg_not_equal(alg_hold(alg_property(v_thestmt, "Statements")), alg_nil())))) {
        (void)(alg_hold(alg_invoke(v_this, "Line", (Value[]){alg_hold(alg_add(alg_hold(alg_add(alg_literal("init_"), alg_hold(alg_invoke(v_this, "UnitNameOf", (Value[]){alg_hold(alg_str(alg_hold(alg_property(v_thestmt, "FileName"))))}, 1)))), alg_literal("();")))}, 1)));
    }
    alg_hold_top = rh_2223;
    Value ret_604 = alg_nil();
    alg_root_top = rt_base;
    return ret_604;
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
    alg_class_field(k_emitunit, "Name", "String");
    alg_class_field(k_emitunit, "Statements", "List");
    alg_class_field(k_emitunit, "Imports", "List");
    alg_class_field(k_emitunit, "PrivateNames", "List");
    alg_class_field(k_emitunit, "FileName", "String");
    alg_class_initializer(k_emitunit, i_emitunit);
    alg_class_method(k_emitunit, "Init", m_emitunit_init_5_string_list_list_list_string, 5, t_emitunit_init_5_string_list_list_list_string);
    alg_class_field(k_cemitter, "Declarations", "Buffer");
    alg_class_field(k_cemitter, "RootSymbols", "List");
    alg_class_field(k_cemitter, "RootMarks", "Integer");
    alg_class_field(k_cemitter, "FrameRoots", "String");
    alg_class_field(k_cemitter, "Functions", "Buffer");
    alg_class_field(k_cemitter, "MainBody", "Buffer");
    alg_class_field(k_cemitter, "Setup", "Buffer");
    alg_class_field(k_cemitter, "Shells", "Buffer");
    alg_class_field(k_cemitter, "Body", "Buffer");
    alg_class_field(k_cemitter, "TestSymbols", "List");
    alg_class_field(k_cemitter, "Header", "String");
    alg_class_field(k_cemitter, "UnitName", "String");
    alg_class_field(k_cemitter, "PrivateNames", "List");
    alg_class_field(k_cemitter, "RootUnit", "Boolean");
    alg_class_field(k_cemitter, "UnitTests", "Integer");
    alg_class_field(k_cemitter, "Target", "String");
    alg_class_field(k_cemitter, "Depth", "Integer");
    alg_class_field(k_cemitter, "AtTopLevel", "Boolean");
    alg_class_field(k_cemitter, "Locals", "List");
    alg_class_field(k_cemitter, "Declared", "Set");
    alg_class_field(k_cemitter, "CollectingInto", "Set");
    alg_class_field(k_cemitter, "DeclaredIn", "Map");
    alg_class_field(k_cemitter, "VisibleDeclared", "Set");
    alg_class_field(k_cemitter, "ClassesIn", "Map");
    alg_class_field(k_cemitter, "ClassCounts", "Map");
    alg_class_field(k_cemitter, "VisibleClasses", "Set");
    alg_class_field(k_cemitter, "Logicals", "Integer");
    alg_class_field(k_cemitter, "Loops", "Integer");
    alg_class_field(k_cemitter, "TryDepth", "Integer");
    alg_class_field(k_cemitter, "LoopTryDepth", "Integer");
    alg_class_field(k_cemitter, "LoopLabels", "List");
    alg_class_field(k_cemitter, "LoopDepths", "List");
    alg_class_field(k_cemitter, "Jumped", "Set");
    alg_class_field(k_cemitter, "LabelDepths", "List");
    alg_class_field(k_cemitter, "Volatiles", "Boolean");
    alg_class_field(k_cemitter, "Renames", "Map");
    alg_class_field(k_cemitter, "Overloaded", "Set");
    alg_class_field(k_cemitter, "OverloadsIn", "Map");
    alg_class_field(k_cemitter, "Tables", "Set");
    alg_class_field(k_cemitter, "SetsBuilt", "Set");
    alg_class_field(k_cemitter, "Renamed", "Set");
    alg_class_field(k_cemitter, "ImportedFrom", "Map");
    alg_class_field(k_cemitter, "AmbiguousImports", "Map");
    alg_class_field(k_cemitter, "AmbiguousMembers", "Map");
    alg_class_field(k_cemitter, "Boxed", "List");
    alg_class_field(k_cemitter, "Cells", "List");
    alg_class_field(k_cemitter, "Captured", "Map");
    alg_class_field(k_cemitter, "Globals", "Set");
    alg_class_field(k_cemitter, "TopLevel", "Set");
    alg_class_field(k_cemitter, "GlobalsIn", "Map");
    alg_class_field(k_cemitter, "UnitExports", "Map");
    alg_class_field(k_cemitter, "UnitAll", "Map");
    alg_class_field(k_cemitter, "ShadowNames", "Set");
    alg_class_field(k_cemitter, "ShadowArities", "Set");
    alg_class_field(k_cemitter, "ShadowWhole", "Set");
    alg_class_field(k_cemitter, "Warned", "Set");
    alg_class_field(k_cemitter, "BuiltinThunks", "Set");
    alg_class_field(k_cemitter, "Canonical", "Map");
    alg_class_field(k_cemitter, "InsideNested", "Boolean");
    alg_class_field(k_cemitter, "NestedIn", "String");
    alg_class_field(k_cemitter, "EmitTests", "Boolean");
    alg_class_field(k_cemitter, "Tests", "List");
    alg_class_field(k_cemitter, "TestFiles", "List");
    alg_class_field(k_cemitter, "CurrentFile", "String");
    alg_class_field(k_cemitter, "SourceFile", "String");
    alg_class_field(k_cemitter, "Classes", "Map");
    alg_class_field(k_cemitter, "OwnClasses", "Set");
    alg_class_field(k_cemitter, "Objects", "Set");
    alg_class_field(k_cemitter, "EnumTypes", "Set");
    alg_class_field(k_cemitter, "EnumMembers", "Map");
    alg_class_field(k_cemitter, "CurrentClass", "String");
    alg_class_field(k_cemitter, "VisibleFields", "Set");
    alg_class_field(k_cemitter, "VisibleMethods", "Set");
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
    alg_class_method(k_cemitter, "EmitSafePoint", m_cemitter_emitsafepoint_0, 0, NULL);
    alg_class_method(k_cemitter, "DeclareLocal", m_cemitter_declarelocal_2_string_string, 2, t_cemitter_declarelocal_2_string_string);
    alg_class_method(k_cemitter, "EmitReturn", m_cemitter_emitreturn_1_string, 1, t_cemitter_emitreturn_1_string);
    alg_class_method(k_cemitter, "OpenRoots", m_cemitter_openroots_1_boolean, 1, t_cemitter_openroots_1_boolean);
    alg_class_method(k_cemitter, "CloseRoots", m_cemitter_closeroots_1_string, 1, t_cemitter_closeroots_1_string);
    alg_class_method(k_cemitter, "OpenHolds", m_cemitter_openholds_0, 0, NULL);
    alg_class_method(k_cemitter, "ExecuteHeld", m_cemitter_executeheld_2_string, 2, t_cemitter_executeheld_2_string);
    alg_class_method(k_cemitter, "VoidCall", m_cemitter_voidcall_1_string, 1, t_cemitter_voidcall_1_string);
    alg_class_method(k_cemitter, "NeedsHold", m_cemitter_needshold_1, 1, t_cemitter_needshold_1);
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
    alg_class_method(k_cemitter, "VisibleGlobal", m_cemitter_visibleglobal_1_string, 1, t_cemitter_visibleglobal_1_string);
    alg_class_method(k_cemitter, "VisibleSubprogram", m_cemitter_visiblesubprogram_1_string, 1, t_cemitter_visiblesubprogram_1_string);
    alg_class_method(k_cemitter, "Missing", m_cemitter_missing_2_string_token, 2, t_cemitter_missing_2_string_token);
    alg_class_method(k_cemitter, "MissingName", m_cemitter_missingname_1_string, 1, t_cemitter_missingname_1_string);
    alg_class_method(k_cemitter, "Spelled", m_cemitter_spelled_1_string, 1, t_cemitter_spelled_1_string);
    alg_class_method(k_cemitter, "Unreachable", m_cemitter_unreachable_1_string, 1, t_cemitter_unreachable_1_string);
    alg_class_method(k_cemitter, "BoundValue", m_cemitter_boundvalue_3_string, 3, t_cemitter_boundvalue_3_string);
    alg_class_method(k_cemitter, "Elidable", m_cemitter_elidable_2, 2, t_cemitter_elidable_2);
    alg_class_method(k_cemitter, "VisitAssignExpr", m_cemitter_visitassignexpr_1_assignexpr, 1, t_cemitter_visitassignexpr_1_assignexpr);
    alg_class_method(k_cemitter, "VisitGrouping", m_cemitter_visitgrouping_1_groupingexpr, 1, t_cemitter_visitgrouping_1_groupingexpr);
    alg_class_method(k_cemitter, "DeclaresType", m_cemitter_declarestype_1_string, 1, t_cemitter_declarestype_1_string);
    alg_class_method(k_cemitter, "ResolvedKind", m_cemitter_resolvedkind_1_string, 1, t_cemitter_resolvedkind_1_string);
    alg_class_method(k_cemitter, "BuiltinTypeName", m_cemitter_builtintypename_1_string, 1, t_cemitter_builtintypename_1_string);
    alg_class_method(k_cemitter, "ResolvedClass", m_cemitter_resolvedclass_1_string, 1, t_cemitter_resolvedclass_1_string);
    alg_class_method(k_cemitter, "VisitIsExpr", m_cemitter_visitisexpr_1_isexpr, 1, t_cemitter_visitisexpr_1_isexpr);
    alg_class_method(k_cemitter, "VisitUnary", m_cemitter_visitunary_1_unaryexpr, 1, t_cemitter_visitunary_1_unaryexpr);
    alg_class_method(k_cemitter, "VisitBinary", m_cemitter_visitbinary_1_binaryexpr, 1, t_cemitter_visitbinary_1_binaryexpr);
    alg_class_method(k_cemitter, "BuiltinCounts", m_cemitter_builtincounts_1_string, 1, t_cemitter_builtincounts_1_string);
    alg_class_method(k_cemitter, "CountsMessage", m_cemitter_countsmessage_2_list_integer, 2, t_cemitter_countsmessage_2_list_integer);
    alg_class_method(k_cemitter, "CountsPhrase", m_cemitter_countsphrase_1_list, 1, t_cemitter_countsphrase_1_list);
    alg_class_method(k_cemitter, "RenamesOf", m_cemitter_renamesof_2_string_string, 2, t_cemitter_renamesof_2_string_string);
    alg_class_method(k_cemitter, "MarkAmbiguousImport", m_cemitter_markambiguousimport_3_string_string_string, 3, t_cemitter_markambiguousimport_3_string_string_string);
    alg_class_method(k_cemitter, "MarkAmbiguousMember", m_cemitter_markambiguousmember_3_string_string_string, 3, t_cemitter_markambiguousmember_3_string_string_string);
    alg_class_method(k_cemitter, "AmbiguousMessage", m_cemitter_ambiguousmessage_2_string_string, 2, t_cemitter_ambiguousmessage_2_string_string);
    alg_class_method(k_cemitter, "IsAssertion", m_cemitter_isassertion_1_string, 1, t_cemitter_isassertion_1_string);
    alg_class_method(k_cemitter, "BuiltinHandle", m_cemitter_builtinhandle_1_string, 1, t_cemitter_builtinhandle_1_string);
    alg_class_method(k_cemitter, "EmitBuiltinThunk", m_cemitter_emitbuiltinthunk_3_string_string_list, 3, t_cemitter_emitbuiltinthunk_3_string_string_list);
    alg_class_method(k_cemitter, "VoidBuiltin", m_cemitter_voidbuiltin_1_string, 1, t_cemitter_voidbuiltin_1_string);
    alg_class_method(k_cemitter, "Builtin", m_cemitter_builtin_2_string_integer, 2, t_cemitter_builtin_2_string_integer);
    alg_class_method(k_cemitter, "JoiningBuiltin", m_cemitter_joiningbuiltin_2_string_list, 2, t_cemitter_joiningbuiltin_2_string_list);
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
    alg_class_method(k_cemitter, "ReportedName", m_cemitter_reportedname_1, 1, t_cemitter_reportedname_1);
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
    int32_t rh_1473 = alg_hold_top;
    alg_hold_top = rh_1473;
    alg_hold_top = rh_1473;
    alg_hold_top = rh_1473;
    alg_hold_top = rh_1473;
    alg_hold_top = rh_1473;
    alg_hold_top = rh_1473;
    alg_hold_top = rh_1473;
    v_hoistVabove = alg_int(100);
    d_hoistVabove = true;
    alg_hold_top = rh_1473;
    alg_hold_top = rh_1473;
    alg_hold_top = rh_1473;
    alg_hold_top = rh_1473;
    alg_hold_top = rh_1473;
}
