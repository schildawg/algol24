/* Generated from Algol-24.  Do not edit. */
#include "Main.h"
#include "Token.h"
#include "TokenType.h"
#include "Expr.h"
#include "Stmt.h"
#include "Environment.h"
#include "ObjFunction.h"
#include "ObjClass.h"
#include "ObjInstance.h"
#include "ObjEnum.h"
#include "ObjCollection.h"
#include "ObjBuffer.h"
#include "ObjFile.h"
#include "SourceCode.h"
#include "Console.h"
#include "Release.h"
#include "Scanner.h"
#include "Parser.h"
#include "TypeChecker.h"
#include "Resolver.h"
#include "Interpreter.h"
#include "CEmitter.h"

static Value f_readsource(Value **cells, Value *args, int32_t count);
static Value f_checkscanned(Value **cells, Value *args, int32_t count);
static Value f_runtests(Value **cells, Value *args, int32_t count);
static Value f_run(Value **cells, Value *args, int32_t count);
static Value f_reportruntime(Value **cells, Value *args, int32_t count);
static Value f_argumentsfrom(Value **cells, Value *args, int32_t count);
static Value f_compile(Value **cells, Value *args, int32_t count);
static Value f_copyfile(Value **cells, Value *args, int32_t count);
static Value f_runtimefolder(Value **cells, Value *args, int32_t count);
static Value f_usage(Value **cells, Value *args, int32_t count);
static Value f_main(Value **cells, Value *args, int32_t count);
static Value fn_readsource;
static const char *t_f_readsource[] = { "Name : String" };
static Value fn_checkscanned;
static Value fn_runtests;
static const char *t_f_runtests[] = { "Source : String", "FileName : String" };
static Value fn_run;
static const char *t_f_run[] = { "Source : String", "FileName : String" };
static Value fn_reportruntime;
static const char *t_f_reportruntime[] = { "Message : String" };
static Value fn_argumentsfrom;
static const char *t_f_argumentsfrom[] = { "First : Integer" };
static Value fn_compile;
static const char *t_f_compile[] = { "Source : String", "FileName : String", "WantTests : Boolean", "OutDir : String" };
static Value fn_copyfile;
static const char *t_f_copyfile[] = { "FromPath : String", "ToPath : String" };
static Value fn_runtimefolder;
static Value fn_usage;
static Value fn_main;

static Value f_readsource(Value **cells, Value *args, int32_t count) {
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

static Value f_checkscanned(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    if (alg_truthy((alg_declared(d_haderror, "HadError"), v_haderror))) {
        alg_raise(alg_str((alg_declared(d_lasterror, "LastError"), v_lasterror)));
    }
    Value ret_2 = alg_nil();
    alg_root_top = rt_base;
    return ret_2;
}

static Value f_runtests(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_source = alg_param(args[0], "String");
    (void)v_source;
    alg_root(&v_source, 1);
    Value v_filename = alg_param(args[1], "String");
    (void)v_filename;
    alg_root(&v_filename, 1);
    Value v_thescanner = alg_nil();
    (void)v_thescanner;
    alg_root(&v_thescanner, 1);
    Value v_theparser = alg_nil();
    (void)v_theparser;
    alg_root(&v_theparser, 1);
    Value v_theresolver = alg_nil();
    (void)v_theresolver;
    alg_root(&v_theresolver, 1);
    Value v_theinterpreter = alg_nil();
    (void)v_theinterpreter;
    alg_root(&v_theinterpreter, 1);
    Value v_stmts = alg_nil();
    (void)v_stmts;
    alg_root(&v_stmts, 1);
    (void)(alg_invoke(alg_singleton(k_sourcecode), "Begins", (Value[]){v_filename}, 1));
    (void)((v_thescanner = alg_new(k_scanner, (Value[]){v_source, v_filename}, 2)));
    (void)((v_theparser = alg_new(k_parser, (Value[]){alg_invoke(v_thescanner, "ScanTokens", NULL, 0)}, 1)));
    (void)(f_checkscanned(NULL, NULL, 0));
    (void)(alg_set_property(v_theparser, "FileName", v_filename));
    (void)((v_stmts = alg_invoke(v_theparser, "Parse", NULL, 0)));
    (void)(f_checkscanned(NULL, NULL, 0));
    (void)((v_theinterpreter = alg_new(k_interpreter, NULL, 0)));
    (void)((v_theresolver = alg_new(k_resolver, (Value[]){v_theinterpreter}, 1)));
    (void)(alg_invoke(v_theresolver, "ResolveAll", (Value[]){v_stmts}, 1));
    (void)(alg_invoke(alg_new(k_typechecker, NULL, 0), "Resolve", (Value[]){v_stmts}, 1));
    Value ret_3 = alg_invoke(v_theinterpreter, "RunTests", (Value[]){v_stmts, v_filename}, 2);
    alg_root_top = rt_base;
    return ret_3;
    Value ret_4 = alg_nil();
    alg_root_top = rt_base;
    return ret_4;
}

static Value f_run(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    volatile Value v_source = alg_param(args[0], "String");
    (void)v_source;
    alg_root(&v_source, 1);
    volatile Value v_filename = alg_param(args[1], "String");
    (void)v_filename;
    alg_root(&v_filename, 1);
    volatile Value v_thescanner = alg_nil();
    (void)v_thescanner;
    alg_root(&v_thescanner, 1);
    volatile Value v_theparser = alg_nil();
    (void)v_theparser;
    alg_root(&v_theparser, 1);
    volatile Value v_theresolver = alg_nil();
    (void)v_theresolver;
    alg_root(&v_theresolver, 1);
    volatile Value v_theinterpreter = alg_nil();
    (void)v_theinterpreter;
    alg_root(&v_theinterpreter, 1);
    volatile Value v_tokens = alg_nil();
    (void)v_tokens;
    alg_root(&v_tokens, 1);
    volatile Value v_stmts = alg_nil();
    (void)v_stmts;
    alg_root(&v_stmts, 1);
    (void)(alg_invoke(alg_singleton(k_sourcecode), "Begins", (Value[]){v_filename}, 1));
    (void)((v_thescanner = alg_new(k_scanner, (Value[]){v_source, v_filename}, 2)));
    (void)((v_tokens = alg_invoke(v_thescanner, "ScanTokens", NULL, 0)));
    (void)(f_checkscanned(NULL, NULL, 0));
    (void)((v_theparser = alg_new(k_parser, (Value[]){v_tokens}, 1)));
    (void)(alg_set_property(v_theparser, "FileName", v_filename));
    (void)((v_stmts = alg_invoke(v_theparser, "Parse", NULL, 0)));
    (void)(f_checkscanned(NULL, NULL, 0));
    (void)((v_theinterpreter = alg_new(k_interpreter, NULL, 0)));
    (void)(alg_set_property(v_theinterpreter, "RootFile", v_filename));
    (void)((v_theresolver = alg_new(k_resolver, (Value[]){v_theinterpreter}, 1)));
    (void)(alg_invoke(v_theresolver, "ResolveAll", (Value[]){v_stmts}, 1));
    (void)(alg_invoke(alg_new(k_typechecker, NULL, 0), "Resolve", (Value[]){v_stmts}, 1));
    {
        AlgFrame frame_5;
        alg_push_frame(&frame_5);
        if (ALG_SETJMP(frame_5.jump) == 0) {
            {
                (void)(alg_invoke(v_theinterpreter, "Interpret", (Value[]){v_stmts}, 1));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_5[] = {"String", "Any"};
            int32_t which_5 = alg_handler(frame_5.raised, names_5, 2);
            if (which_5 == 0) {
                {
                    int32_t rt_662 = alg_root_top;
                    volatile Value v_e = frame_5.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    (void)(f_reportruntime(NULL, (Value[]){v_e}, 1));
                    alg_root_top = rt_662;
                }
            }
            else if (which_5 == 1) {
                {
                    int32_t rt_663 = alg_root_top;
                    volatile Value v_e = frame_5.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    (void)(f_reportruntime(NULL, (Value[]){alg_str(v_e)}, 1));
                    alg_root_top = rt_663;
                }
            }
            else {
                alg_raise(frame_5.raised);
            }
        }
    }
    volatile Value ret_6 = alg_nil();
    alg_root_top = rt_base;
    return ret_6;
}

static Value f_reportruntime(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_message = alg_param(args[0], "String");
    (void)v_message;
    alg_root(&v_message, 1);
    (void)(alg_stderr_line(alg_add(alg_string("Uncaught: "), v_message)));
    if (alg_truthy(alg_greater((alg_declared(d_interpVsiteVline, "INTERP_SITE_LINE"), v_interpVsiteVline), alg_int(0)))) {
        (void)(alg_stderr_line(alg_add(alg_add(alg_add(alg_string("       at "), alg_invoke(alg_singleton(k_sourcecode), "Named", (Value[]){(alg_declared(d_interpVsiteVfile, "INTERP_SITE_FILE"), v_interpVsiteVfile)}, 1)), alg_char_value(58)), alg_str((alg_declared(d_interpVsiteVline, "INTERP_SITE_LINE"), v_interpVsiteVline)))));
    }
    (void)(alg_halt(alg_int(70)));
    Value ret_7 = alg_nil();
    alg_root_top = rt_base;
    return ret_7;
}

static Value f_argumentsfrom(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_first = alg_param(args[0], "Integer");
    (void)v_first;
    alg_root(&v_first, 1);
    Value v_result = alg_list();
    (void)v_result;
    alg_root(&v_result, 1);
    {
        int32_t rt_664 = alg_root_top;
        Value v_i = v_first;
        (void)v_i;
        alg_root(&v_i, 1);
        for (; alg_truthy(alg_less_equal(v_i, alg_param_count())); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(v_result, "Add", (Value[]){alg_param_str(v_i)}, 1));
        }
        alg_root_top = rt_664;
    }
    Value ret_8 = v_result;
    alg_root_top = rt_base;
    return ret_8;
    Value ret_9 = alg_nil();
    alg_root_top = rt_base;
    return ret_9;
}

static Value f_compile(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 4);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    volatile Value v_source = alg_param(args[0], "String");
    (void)v_source;
    alg_root(&v_source, 1);
    volatile Value v_filename = alg_param(args[1], "String");
    (void)v_filename;
    alg_root(&v_filename, 1);
    volatile Value v_wanttests = alg_param(args[2], "Boolean");
    (void)v_wanttests;
    alg_root(&v_wanttests, 1);
    volatile Value v_outdir = alg_param(args[3], "String");
    (void)v_outdir;
    alg_root(&v_outdir, 1);
    volatile Value v_thescanner = alg_nil();
    (void)v_thescanner;
    alg_root(&v_thescanner, 1);
    volatile Value v_theparser = alg_nil();
    (void)v_theparser;
    alg_root(&v_theparser, 1);
    volatile Value v_stmts = alg_nil();
    (void)v_stmts;
    alg_root(&v_stmts, 1);
    (void)(alg_invoke(alg_singleton(k_sourcecode), "Begins", (Value[]){v_filename}, 1));
    (void)((v_thescanner = alg_new(k_scanner, (Value[]){v_source, v_filename}, 2)));
    (void)((v_theparser = alg_new(k_parser, (Value[]){alg_invoke(v_thescanner, "ScanTokens", NULL, 0)}, 1)));
    (void)(f_checkscanned(NULL, NULL, 0));
    (void)(alg_set_property(v_theparser, "FileName", v_filename));
    (void)((v_stmts = alg_invoke(v_theparser, "Parse", NULL, 0)));
    (void)(f_checkscanned(NULL, NULL, 0));
    volatile Value v_theinterpreter = alg_new(k_interpreter, NULL, 0);
    (void)v_theinterpreter;
    alg_root(&v_theinterpreter, 1);
    (void)(alg_invoke(alg_new(k_resolver, (Value[]){v_theinterpreter}, 1), "ResolveAll", (Value[]){v_stmts}, 1));
    (void)(alg_invoke(alg_new(k_typechecker, NULL, 0), "Resolve", (Value[]){v_stmts}, 1));
    volatile Value v_theemitter = alg_new(k_cemitter, NULL, 0);
    (void)v_theemitter;
    alg_root(&v_theemitter, 1);
    (void)(alg_invoke(v_theemitter, "CompilingFile", (Value[]){v_filename}, 1));
    if (alg_truthy(v_wanttests)) {
        (void)(alg_invoke(v_theemitter, "WithTests", NULL, 0));
    }
    volatile Value v_thefiles = alg_invoke(v_theemitter, "Emit", (Value[]){v_stmts, alg_invoke(v_theemitter, "UnitNameOf", (Value[]){v_filename}, 1)}, 2);
    (void)v_thefiles;
    alg_root(&v_thefiles, 1);
    {
        int32_t rt_665 = alg_root_top;
        volatile Value loop_10 = alg_iterable(alg_invoke(v_thefiles, "Keys", NULL, 0));
        (void)loop_10;
        alg_root(&loop_10, 1);
        for (volatile int32_t at_10 = 0; at_10 < alg_iterable_count(loop_10); at_10++) {
            int32_t rt_666 = alg_root_top;
            volatile Value v_name = alg_iterable_at(loop_10, at_10);
            (void)v_name;
            alg_root(&v_name, 1);
            {
                int32_t rt_667 = alg_root_top;
                volatile Value v_out = alg_text_file();
                (void)v_out;
                alg_root(&v_out, 1);
                (void)(alg_invoke(v_out, "Assign", (Value[]){alg_add(alg_add(v_outdir, alg_char_value(47)), alg_str(v_name))}, 1));
                {
                    AlgFrame frame_11;
                    alg_push_frame(&frame_11);
                    if (ALG_SETJMP(frame_11.jump) == 0) {
                        {
                            (void)(alg_invoke(v_out, "Rewrite", NULL, 0));
                        }
                        alg_pop_frame();
                    }
                    else {
                        static const char *names_11[] = {"String"};
                        int32_t which_11 = alg_handler(frame_11.raised, names_11, 1);
                        if (which_11 == 0) {
                            {
                                int32_t rt_668 = alg_root_top;
                                volatile Value v_e = frame_11.raised;
                                (void)v_e;
                                alg_root(&v_e, 1);
                                alg_raise(alg_add(alg_add(alg_string("algc: cannot write into '"), v_outdir), alg_string("'. Does the directory exist?")));
                                alg_root_top = rt_668;
                            }
                        }
                        else {
                            alg_raise(frame_11.raised);
                        }
                    }
                }
                (void)(alg_invoke(v_out, "Write", (Value[]){alg_str(alg_invoke(v_thefiles, "Get", (Value[]){v_name}, 1))}, 1));
                (void)(alg_invoke(v_out, "Close", NULL, 0));
                alg_root_top = rt_667;
            }
            alg_root_top = rt_666;
        }
        alg_root_top = rt_665;
    }
    volatile Value v_runtime = f_runtimefolder(NULL, NULL, 0);
    (void)v_runtime;
    alg_root(&v_runtime, 1);
    if (alg_truthy(alg_equal(v_runtime, alg_string("")))) {
        (void)(alg_writeln(alg_add(alg_add(alg_string("[WARN] algol.c and algol.h were not found, so "), v_outdir), alg_string(" will not compile on its own."))));
    } else {
        {
            (void)(f_copyfile(NULL, (Value[]){alg_add(v_runtime, alg_string("/algol.c")), alg_add(v_outdir, alg_string("/algol.c"))}, 2));
            (void)(f_copyfile(NULL, (Value[]){alg_add(v_runtime, alg_string("/algol.h")), alg_add(v_outdir, alg_string("/algol.h"))}, 2));
        }
    }
    volatile Value ret_12 = alg_nil();
    alg_root_top = rt_base;
    return ret_12;
}

static Value f_copyfile(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    volatile Value v_frompath = alg_param(args[0], "String");
    (void)v_frompath;
    alg_root(&v_frompath, 1);
    volatile Value v_topath = alg_param(args[1], "String");
    (void)v_topath;
    alg_root(&v_topath, 1);
    volatile Value v_source = alg_nil();
    (void)v_source;
    alg_root(&v_source, 1);
    volatile Value v_target = alg_nil();
    (void)v_target;
    alg_root(&v_target, 1);
    (void)((v_source = alg_text_file()));
    (void)(alg_invoke(v_source, "Assign", (Value[]){v_frompath}, 1));
    {
        AlgFrame frame_13;
        alg_push_frame(&frame_13);
        if (ALG_SETJMP(frame_13.jump) == 0) {
            {
                (void)(alg_invoke(v_source, "Reset", NULL, 0));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_13[] = {"String"};
            int32_t which_13 = alg_handler(frame_13.raised, names_13, 1);
            if (which_13 == 0) {
                {
                    int32_t rt_669 = alg_root_top;
                    volatile Value v_e = frame_13.raised;
                    (void)v_e;
                    alg_root(&v_e, 1);
                    volatile Value ret_14 = alg_bool(false);
                    alg_root_top = rt_base;
                    return ret_14;
                    alg_root_top = rt_669;
                }
            }
            else {
                alg_raise(frame_13.raised);
            }
        }
    }
    (void)((v_target = alg_text_file()));
    (void)(alg_invoke(v_target, "Assign", (Value[]){v_topath}, 1));
    (void)(alg_invoke(v_target, "Rewrite", NULL, 0));
    while (alg_truthy(alg_not(alg_property(v_source, "Eof")))) {
        (void)(alg_invoke(v_target, "WriteLn", (Value[]){alg_invoke(v_source, "ReadLn", NULL, 0)}, 1));
    }
    (void)(alg_invoke(v_source, "Close", NULL, 0));
    (void)(alg_invoke(v_target, "Close", NULL, 0));
    volatile Value ret_15 = alg_bool(true);
    alg_root_top = rt_base;
    return ret_15;
    volatile Value ret_16 = alg_nil();
    alg_root_top = rt_base;
    return ret_16;
}

static Value f_runtimefolder(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_own = alg_nil();
    (void)v_own;
    alg_root(&v_own, 1);
    (void)((v_own = f_folderof(NULL, (Value[]){alg_param_str(alg_int(0))}, 1)));
    if (alg_truthy(alg_not_equal(v_own, alg_string("")))) {
        {
            if (alg_truthy(alg_file_exists(alg_add(v_own, alg_string("/algol.h"))))) {
                Value ret_17 = v_own;
                alg_root_top = rt_base;
                return ret_17;
            }
            if (alg_truthy(alg_file_exists(alg_add(v_own, alg_string("/../share/algol24/algol.h"))))) {
                Value ret_18 = alg_add(v_own, alg_string("/../share/algol24"));
                alg_root_top = rt_base;
                return ret_18;
            }
        }
    }
    if (alg_truthy(alg_file_exists(alg_string("bootstrap/algol.h")))) {
        Value ret_19 = alg_string("bootstrap");
        alg_root_top = rt_base;
        return ret_19;
    }
    Value ret_20 = alg_string("");
    alg_root_top = rt_base;
    return ret_20;
    Value ret_21 = alg_nil();
    alg_root_top = rt_base;
    return ret_21;
}

static Value f_usage(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    (void)(alg_writeln(alg_string("algc -- the Algol-24 compiler.")));
    (void)(alg_writeln(alg_string("")));
    (void)(alg_writeln(alg_string("Usage:")));
    (void)(alg_writeln(alg_string("  algc <file.a24>                    run a program")));
    (void)(alg_writeln(alg_string("  algc --test <file.a24>             run its test blocks")));
    (void)(alg_writeln(alg_string("  algc --compile [--out=DIR] <file>  emit C into DIR (default: out)")));
    (void)(alg_writeln(alg_string("  algc --compile --test <file>       emit the tests and a runner")));
    (void)(alg_writeln(alg_string("  algc --version                     the version")));
    (void)(alg_writeln(alg_string("  algc --help                        this")));
    (void)(alg_writeln(alg_string("")));
    (void)(alg_writeln(alg_string("The emitted directory carries the runtime with it, so:")));
    (void)(alg_writeln(alg_string("  cc -std=c11 -O2 -o <name> <dir>/*.c")));
    Value ret_22 = alg_nil();
    alg_root_top = rt_base;
    return ret_22;
}

static Value f_main(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
    int32_t rt_base = alg_root_top;
    alg_root(args, count);
    Value v_name = alg_nil();
    (void)v_name;
    alg_root(&v_name, 1);
    (void)(f_setmodulefolders(NULL, (Value[]){f_libraryfolders(NULL, NULL, 0)}, 1));
    if (alg_truthy(alg_equal(alg_param_count(), alg_int(0)))) {
        {
            (void)(f_usage(NULL, NULL, 0));
            Value ret_23 = alg_nil();
            alg_root_top = rt_base;
            return ret_23;
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("--help")))) {
        {
            (void)(f_usage(NULL, NULL, 0));
            Value ret_24 = alg_nil();
            alg_root_top = rt_base;
            return ret_24;
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("-h")))) {
        {
            (void)(f_usage(NULL, NULL, 0));
            Value ret_25 = alg_nil();
            alg_root_top = rt_base;
            return ret_25;
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("--version")))) {
        {
            (void)(alg_writeln(alg_add(alg_string("algc "), (alg_declared(d_version, "VERSION"), v_version))));
            Value ret_26 = alg_nil();
            alg_root_top = rt_base;
            return ret_26;
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("--compile")))) {
        {
            int32_t rt_670 = alg_root_top;
            Value v_wanttests = alg_bool(false);
            (void)v_wanttests;
            alg_root(&v_wanttests, 1);
            Value v_outdir = alg_string("out");
            (void)v_outdir;
            alg_root(&v_outdir, 1);
            (void)((v_name = alg_string("")));
            {
                int32_t rt_671 = alg_root_top;
                Value v_i = alg_int(2);
                (void)v_i;
                alg_root(&v_i, 1);
                for (; alg_truthy(alg_less_equal(v_i, alg_param_count())); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        int32_t rt_672 = alg_root_top;
                        Value v_arg = alg_param_str(v_i);
                        (void)v_arg;
                        alg_root(&v_arg, 1);
                        if (alg_truthy(alg_equal(v_arg, alg_string("--test")))) {
                            (void)((v_wanttests = alg_bool(true)));
                        } else {
                            {
                                if (alg_truthy(alg_equal(alg_copy(v_arg, alg_int(0), alg_int(6)), alg_string("--out=")))) {
                                    (void)((v_outdir = alg_copy(v_arg, alg_int(6), alg_subtract(alg_text_length(v_arg), alg_int(6)))));
                                } else {
                                    (void)((v_name = v_arg));
                                }
                            }
                        }
                        alg_root_top = rt_672;
                    }
                }
                alg_root_top = rt_671;
            }
            if (alg_truthy(alg_not(alg_file_exists(v_name)))) {
                {
                    alg_raise(alg_add(alg_string("algc: cannot open "), v_name));
                }
            }
            (void)(f_compile(NULL, (Value[]){f_readsource(NULL, (Value[]){v_name}, 1), v_name, v_wanttests, v_outdir}, 4));
            Value ret_27 = alg_nil();
            alg_root_top = rt_base;
            return ret_27;
            alg_root_top = rt_670;
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("--test")))) {
        {
            (void)((v_name = alg_param_str(alg_int(2))));
            if (alg_truthy(alg_not(alg_file_exists(v_name)))) {
                {
                    alg_raise(alg_add(alg_string("algc: cannot open "), v_name));
                }
            }
            (void)(f_setprogramarguments(NULL, (Value[]){f_argumentsfrom(NULL, (Value[]){alg_int(2)}, 1)}, 1));
            if (alg_truthy(alg_greater(f_runtests(NULL, (Value[]){f_readsource(NULL, (Value[]){v_name}, 1), v_name}, 2), alg_int(0)))) {
                (void)(alg_halt(alg_int(70)));
            }
            Value ret_28 = alg_nil();
            alg_root_top = rt_base;
            return ret_28;
        }
    }
    (void)((v_name = alg_param_str(alg_int(1))));
    if (alg_truthy(alg_not(alg_file_exists(v_name)))) {
        {
            alg_raise(alg_add(alg_string("algc: cannot open "), v_name));
        }
    }
    (void)(f_setprogramarguments(NULL, (Value[]){f_argumentsfrom(NULL, (Value[]){alg_int(1)}, 1)}, 1));
    (void)(f_run(NULL, (Value[]){f_readsource(NULL, (Value[]){v_name}, 1), v_name}, 2));
    Value ret_29 = alg_nil();
    alg_root_top = rt_base;
    return ret_29;
}

static Value *roots_Main[] = {
    &fn_readsource,
    &fn_checkscanned,
    &fn_runtests,
    &fn_run,
    &fn_reportruntime,
    &fn_argumentsfrom,
    &fn_compile,
    &fn_copyfile,
    &fn_runtimefolder,
    &fn_usage,
    &fn_main,
};

void init_Main(void) {
    alg_roots(roots_Main, 11);
    alg_subrange("byte", "0", "255");
    alg_subrange("word", "0", "65535");
    alg_subrange("short", "-32768", "32767");
    fn_readsource = alg_closure("ReadSource", f_readsource, NULL, 0, 1, t_f_readsource);
    fn_checkscanned = alg_closure("CheckScanned", f_checkscanned, NULL, 0, 0, NULL);
    fn_runtests = alg_closure("RunTests", f_runtests, NULL, 0, 2, t_f_runtests);
    fn_run = alg_closure("Run", f_run, NULL, 0, 2, t_f_run);
    fn_reportruntime = alg_closure("ReportRuntime", f_reportruntime, NULL, 0, 1, t_f_reportruntime);
    fn_argumentsfrom = alg_closure("ArgumentsFrom", f_argumentsfrom, NULL, 0, 1, t_f_argumentsfrom);
    fn_compile = alg_closure("Compile", f_compile, NULL, 0, 4, t_f_compile);
    fn_copyfile = alg_closure("CopyFile", f_copyfile, NULL, 0, 2, t_f_copyfile);
    fn_runtimefolder = alg_closure("RuntimeFolder", f_runtimefolder, NULL, 0, 0, NULL);
    fn_usage = alg_closure("Usage", f_usage, NULL, 0, 0, NULL);
    fn_main = alg_closure("Main", f_main, NULL, 0, 0, NULL);
    init_Token();
    init_Expr();
    init_Stmt();
    init_Environment();
    init_ObjFunction();
    init_Release();
    init_TypeChecker();
    init_CEmitter();
    (void)(f_main(NULL, NULL, 0));
}

int main(int argc, char **argv) {
    alg_set_arguments(argc, argv);
    init_Main();
    return 0;
}
