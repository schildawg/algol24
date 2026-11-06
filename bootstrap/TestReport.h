/* Generated from Algol-24.  Do not edit. */
#ifndef ALG_TESTREPORT_H
#define ALG_TESTREPORT_H

#include "algol.h"

Value f_testopening(Value **cells, Value *args, int32_t count);
Value f_testbanner(Value **cells, Value *args, int32_t count);
Value f_testline(Value **cells, Value *args, int32_t count);
Value f_testfailure(Value **cells, Value *args, int32_t count);
Value f_testtotals(Value **cells, Value *args, int32_t count);
extern Value v_leaderVwidth;
extern bool d_leaderVwidth;
extern Value fn_testopening;
extern Value fn_testbanner;
extern Value fn_testline;
extern Value fn_testfailure;
extern Value fn_testtotals;
void init_TestReport(void);

#endif
