/* Generated from Algol-24.  Do not edit. */
#include "TestReport.h"
#include "Console.h"

Value f_testopening(Value **cells, Value *args, int32_t count);
Value f_testbanner(Value **cells, Value *args, int32_t count);
Value f_testline(Value **cells, Value *args, int32_t count);
Value f_testfailure(Value **cells, Value *args, int32_t count);
Value f_testtotals(Value **cells, Value *args, int32_t count);
Value v_leaderVwidth;
bool d_leaderVwidth;
Value fn_testopening;
static const char *t_f_testopening[] = { "Count : Integer" };
Value fn_testbanner;
static const char *t_f_testbanner[] = { "File : String" };
Value fn_testline;
static const char *t_f_testline[] = { "Name : String", "Status : String" };
Value fn_testfailure;
static const char *t_f_testfailure[] = { "RootFile : String", "Said : String" };
Value fn_testtotals;
static const char *t_f_testtotals[] = { "Passed : Integer", "Failed : Integer" };

Value f_testopening(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_count = alg_param_of(args[0], "Integer", "TestOpening");
    (void)v_count;
    alg_root(&v_count, 1);
    int32_t rh_199 = alg_hold_top;
    Value ret_0 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag), alg_literal("Running "))), alg_hold(alg_str(v_count)))), alg_literal(" tests...")));
    alg_root_top = rt_base;
    return ret_0;
    alg_hold_top = rh_199;
    Value ret_1 = alg_nil();
    alg_root_top = rt_base;
    return ret_1;
}

Value f_testbanner(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_file = alg_param_of(args[0], "String", "TestBanner");
    (void)v_file;
    alg_root(&v_file, 1);
    int32_t rh_200 = alg_hold_top;
    Value ret_2 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag), alg_literal("< "))), (alg_declared(d_ansiVcyan, "ANSI_CYAN"), v_ansiVcyan))), v_file)), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset))), alg_literal(" >")));
    alg_root_top = rt_base;
    return ret_2;
    alg_hold_top = rh_200;
    Value ret_3 = alg_nil();
    alg_root_top = rt_base;
    return ret_3;
}

Value f_testline(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_name = alg_param_of(args[0], "String", "TestLine");
    (void)v_name;
    alg_root(&v_name, 1);
    Value v_status = alg_param_of(args[1], "String", "TestLine");
    (void)v_status;
    alg_root(&v_status, 1);
    int32_t rh_201 = alg_hold_top;
    Value v_dots = alg_nil();
    (void)v_dots;
    alg_root(&v_dots, 1);
    alg_hold_top = rh_201;
    (void)((v_dots = alg_hold(alg_subtract((alg_declared(d_leaderVwidth, "LEADER_WIDTH"), v_leaderVwidth), alg_hold(alg_text_length(v_name))))));
    alg_hold_top = rh_201;
    if (alg_truthy(alg_hold(alg_less(v_dots, alg_int(1))))) {
        (void)((v_dots = alg_int(1)));
    }
    alg_hold_top = rh_201;
    Value v_leader = alg_literal("");
    (void)v_leader;
    alg_root(&v_leader, 1);
    alg_hold_top = rh_201;
    {
        int32_t rt_202 = alg_root_top;
        int32_t rh_203 = alg_hold_top;
        Value v_i = alg_int(0);
        (void)v_i;
        alg_root(&v_i, 1);
        alg_hold_top = rh_203;
        {
            int32_t rh_204 = alg_hold_top;
            for (; (alg_hold_top = rh_204, alg_truthy(alg_hold(alg_less(v_i, v_dots)))); (alg_hold_top = rh_204, (v_i = alg_hold(alg_add(v_i, alg_int(1)))))) {
                alg_safe_point();
                (void)((v_leader = alg_hold(alg_add(v_leader, alg_char_value(46)))));
            }
        }
        alg_hold_top = rh_203;
        alg_root_top = rt_202;
    }
    alg_hold_top = rh_201;
    Value v_tint = (alg_declared(d_ansiVgreen, "ANSI_GREEN"), v_ansiVgreen);
    (void)v_tint;
    alg_root(&v_tint, 1);
    alg_hold_top = rh_201;
    if (alg_truthy(alg_hold(alg_equal(v_status, alg_literal("FAIL"))))) {
        (void)((v_tint = (alg_declared(d_ansiVred, "ANSI_RED"), v_ansiVred)));
    }
    alg_hold_top = rh_201;
    Value ret_4 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag), alg_literal("Test: "))), v_name)), alg_char_value(32))), v_leader)), alg_literal(" [ "))), v_tint)), v_status)), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset))), alg_literal(" ]")));
    alg_root_top = rt_base;
    return ret_4;
    alg_hold_top = rh_201;
    Value ret_5 = alg_nil();
    alg_root_top = rt_base;
    return ret_5;
}

Value f_testfailure(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_rootfile = alg_param_of(args[0], "String", "TestFailure");
    (void)v_rootfile;
    alg_root(&v_rootfile, 1);
    Value v_said = alg_param_of(args[1], "String", "TestFailure");
    (void)v_said;
    alg_root(&v_said, 1);
    int32_t rh_205 = alg_hold_top;
    Value ret_6 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_errorVtag, "ERROR_TAG"), v_errorVtag), v_rootfile)), alg_literal(": "))), v_said));
    alg_root_top = rt_base;
    return ret_6;
    alg_hold_top = rh_205;
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
}

Value f_testtotals(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_passed = alg_param_of(args[0], "Integer", "TestTotals");
    (void)v_passed;
    alg_root(&v_passed, 1);
    Value v_failed = alg_param_of(args[1], "Integer", "TestTotals");
    (void)v_failed;
    alg_root(&v_failed, 1);
    int32_t rh_206 = alg_hold_top;
    if (alg_truthy(alg_hold(alg_equal(v_failed, alg_int(0))))) {
        Value ret_8 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag), (alg_declared(d_ansiVgreen, "ANSI_GREEN"), v_ansiVgreen))), alg_literal("All "))), alg_hold(alg_str(v_passed)))), alg_literal(" tests passed."))), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)));
        alg_root_top = rt_base;
        return ret_8;
    }
    alg_hold_top = rh_206;
    Value ret_9 = alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add(alg_hold(alg_add((alg_declared(d_infoVtag, "INFO_TAG"), v_infoVtag), (alg_declared(d_ansiVred, "ANSI_RED"), v_ansiVred))), alg_hold(alg_str(v_failed)))), alg_literal(" of "))), alg_hold(alg_str(alg_hold(alg_add(v_passed, v_failed)))))), alg_literal(" tests failed."))), (alg_declared(d_ansiVreset, "ANSI_RESET"), v_ansiVreset)));
    alg_root_top = rt_base;
    return ret_9;
    alg_hold_top = rh_206;
    Value ret_10 = alg_nil();
    alg_root_top = rt_base;
    return ret_10;
}

static Value *roots_TestReport[] = {
    &v_leaderVwidth,
    &fn_testopening,
    &fn_testbanner,
    &fn_testline,
    &fn_testfailure,
    &fn_testtotals,
};

void init_TestReport(void) {
    alg_roots(roots_TestReport, 6);
    fn_testopening = alg_closure("TestOpening", f_testopening, NULL, 0, 1, t_f_testopening);
    fn_testbanner = alg_closure("TestBanner", f_testbanner, NULL, 0, 1, t_f_testbanner);
    fn_testline = alg_closure("TestLine", f_testline, NULL, 0, 2, t_f_testline);
    fn_testfailure = alg_closure("TestFailure", f_testfailure, NULL, 0, 2, t_f_testfailure);
    fn_testtotals = alg_closure("TestTotals", f_testtotals, NULL, 0, 2, t_f_testtotals);
    int32_t rh_198 = alg_hold_top;
    alg_hold_top = rh_198;
    v_leaderVwidth = alg_int(55);
    d_leaderVwidth = true;
    alg_hold_top = rh_198;
    alg_hold_top = rh_198;
    alg_hold_top = rh_198;
    alg_hold_top = rh_198;
    alg_hold_top = rh_198;
    alg_hold_top = rh_198;
}
