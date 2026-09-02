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
static Value f_argumentsfrom(Value **cells, Value *args, int32_t count);
static Value f_compile(Value **cells, Value *args, int32_t count);
static Value f_folderof(Value **cells, Value *args, int32_t count);
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
static Value fn_argumentsfrom;
static const char *t_f_argumentsfrom[] = { "First : Integer" };
static Value fn_compile;
static const char *t_f_compile[] = { "Source : String", "FileName : String", "WantTests : Boolean", "OutDir : String" };
static Value v_version;
static bool d_version;
static Value fn_folderof;
static const char *t_f_folderof[] = { "Path : String" };
static Value fn_copyfile;
static const char *t_f_copyfile[] = { "FromPath : String", "ToPath : String" };
static Value fn_runtimefolder;
static Value fn_usage;
static Value fn_main;

static Value f_readsource(Value **cells, Value *args, int32_t count) {
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

static Value f_checkscanned(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
    if (alg_truthy((alg_declared(d_haderror, "HadError"), v_haderror))) {
        alg_raise(alg_str((alg_declared(d_lasterror, "LastError"), v_lasterror)));
    }
    return alg_nil();
}

static Value f_runtests(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    Value v_source = alg_param(args[0], "String");
    (void)v_source;
    Value v_filename = alg_param(args[1], "String");
    (void)v_filename;
    Value v_thescanner = alg_nil();
    (void)v_thescanner;
    Value v_theparser = alg_nil();
    (void)v_theparser;
    Value v_theresolver = alg_nil();
    (void)v_theresolver;
    Value v_theinterpreter = alg_nil();
    (void)v_theinterpreter;
    Value v_stmts = alg_nil();
    (void)v_stmts;
    (void)(alg_invoke(alg_singleton(k_sourcecode), "Begins", (Value[]){v_filename}, 1));
    (void)((v_thescanner = alg_widen(alg_new(k_scanner, (Value[]){v_source}, 1), "Scanner")));
    (void)((v_theparser = alg_widen(alg_new(k_parser, (Value[]){alg_invoke(v_thescanner, "ScanTokens", NULL, 0)}, 1), "Parser")));
    (void)(f_checkscanned(NULL, NULL, 0));
    (void)(alg_set_property(v_theparser, "FileName", alg_widen(v_filename, "String")));
    (void)((v_stmts = alg_widen(alg_invoke(v_theparser, "Parse", NULL, 0), "List")));
    (void)(f_checkscanned(NULL, NULL, 0));
    (void)((v_theinterpreter = alg_widen(alg_new(k_interpreter, NULL, 0), "Interpreter")));
    (void)((v_theresolver = alg_widen(alg_new(k_resolver, (Value[]){v_theinterpreter}, 1), "Resolver")));
    (void)(alg_invoke(v_theresolver, "ResolveAll", (Value[]){v_stmts}, 1));
    (void)(alg_invoke(alg_new(k_typechecker, NULL, 0), "Resolve", (Value[]){v_stmts}, 1));
    return alg_invoke(v_theinterpreter, "RunTests", (Value[]){v_stmts, v_filename}, 2);
    return alg_nil();
}

static Value f_run(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    Value v_source = alg_param(args[0], "String");
    (void)v_source;
    Value v_filename = alg_param(args[1], "String");
    (void)v_filename;
    Value v_thescanner = alg_nil();
    (void)v_thescanner;
    Value v_theparser = alg_nil();
    (void)v_theparser;
    Value v_theresolver = alg_nil();
    (void)v_theresolver;
    Value v_theinterpreter = alg_nil();
    (void)v_theinterpreter;
    Value v_tokens = alg_nil();
    (void)v_tokens;
    Value v_stmts = alg_nil();
    (void)v_stmts;
    (void)(alg_invoke(alg_singleton(k_sourcecode), "Begins", (Value[]){v_filename}, 1));
    (void)((v_thescanner = alg_widen(alg_new(k_scanner, (Value[]){v_source}, 1), "Scanner")));
    (void)((v_tokens = alg_widen(alg_invoke(v_thescanner, "ScanTokens", NULL, 0), "List")));
    (void)(f_checkscanned(NULL, NULL, 0));
    (void)((v_theparser = alg_widen(alg_new(k_parser, (Value[]){v_tokens}, 1), "Parser")));
    (void)(alg_set_property(v_theparser, "FileName", alg_widen(v_filename, "String")));
    (void)((v_stmts = alg_widen(alg_invoke(v_theparser, "Parse", NULL, 0), "List")));
    (void)(f_checkscanned(NULL, NULL, 0));
    (void)((v_theinterpreter = alg_widen(alg_new(k_interpreter, NULL, 0), "Interpreter")));
    (void)(alg_set_property(v_theinterpreter, "RootFile", alg_widen(v_filename, "String")));
    (void)((v_theresolver = alg_widen(alg_new(k_resolver, (Value[]){v_theinterpreter}, 1), "Resolver")));
    (void)(alg_invoke(v_theresolver, "ResolveAll", (Value[]){v_stmts}, 1));
    (void)(alg_invoke(alg_new(k_typechecker, NULL, 0), "Resolve", (Value[]){v_stmts}, 1));
    (void)(alg_invoke(v_theinterpreter, "Interpret", (Value[]){v_stmts}, 1));
    return alg_nil();
}

static Value f_argumentsfrom(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_first = alg_param(args[0], "Integer");
    (void)v_first;
    Value v_result = alg_widen(alg_list(), "List");
    (void)v_result;
    {
        Value v_i = v_first;
        (void)v_i;
        for (; alg_truthy(alg_less_equal(v_i, alg_param_count())); (v_i = alg_add(v_i, alg_int(1)))) {
            (void)(alg_invoke(v_result, "Add", (Value[]){alg_param_str(v_i)}, 1));
        }
    }
    return v_result;
    return alg_nil();
}

static Value f_compile(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 4);
    Value v_source = alg_param(args[0], "String");
    (void)v_source;
    Value v_filename = alg_param(args[1], "String");
    (void)v_filename;
    Value v_wanttests = alg_param(args[2], "Boolean");
    (void)v_wanttests;
    Value v_outdir = alg_param(args[3], "String");
    (void)v_outdir;
    Value v_thescanner = alg_nil();
    (void)v_thescanner;
    Value v_theparser = alg_nil();
    (void)v_theparser;
    Value v_stmts = alg_nil();
    (void)v_stmts;
    (void)(alg_invoke(alg_singleton(k_sourcecode), "Begins", (Value[]){v_filename}, 1));
    (void)((v_thescanner = alg_widen(alg_new(k_scanner, (Value[]){v_source}, 1), "Scanner")));
    (void)((v_theparser = alg_widen(alg_new(k_parser, (Value[]){alg_invoke(v_thescanner, "ScanTokens", NULL, 0)}, 1), "Parser")));
    (void)(f_checkscanned(NULL, NULL, 0));
    (void)(alg_set_property(v_theparser, "FileName", alg_widen(v_filename, "String")));
    (void)((v_stmts = alg_widen(alg_invoke(v_theparser, "Parse", NULL, 0), "List")));
    (void)(f_checkscanned(NULL, NULL, 0));
    Value v_theinterpreter = alg_new(k_interpreter, NULL, 0);
    (void)v_theinterpreter;
    (void)(alg_invoke(alg_new(k_resolver, (Value[]){v_theinterpreter}, 1), "ResolveAll", (Value[]){v_stmts}, 1));
    (void)(alg_invoke(alg_new(k_typechecker, NULL, 0), "Resolve", (Value[]){v_stmts}, 1));
    Value v_theemitter = alg_new(k_cemitter, NULL, 0);
    (void)v_theemitter;
    (void)(alg_invoke(v_theemitter, "CompilingFile", (Value[]){v_filename}, 1));
    if (alg_truthy(v_wanttests)) {
        (void)(alg_invoke(v_theemitter, "WithTests", NULL, 0));
    }
    Value v_thefiles = alg_invoke(v_theemitter, "Emit", (Value[]){v_stmts, alg_invoke(v_theemitter, "UnitNameOf", (Value[]){v_filename}, 1)}, 2);
    (void)v_thefiles;
    {
        Value loop_0 = alg_iterable(alg_invoke(v_thefiles, "Keys", NULL, 0));
        for (int32_t at_0 = 0; at_0 < alg_iterable_count(loop_0); at_0++) {
            Value v_name = alg_iterable_at(loop_0, at_0);
            (void)v_name;
            {
                Value v_out = alg_text_file();
                (void)v_out;
                (void)(alg_invoke(v_out, "Assign", (Value[]){alg_add(alg_add(v_outdir, alg_char_value(47)), alg_str(v_name))}, 1));
                (void)(alg_invoke(v_out, "Rewrite", NULL, 0));
                (void)(alg_invoke(v_out, "Write", (Value[]){alg_str(alg_invoke(v_thefiles, "Get", (Value[]){v_name}, 1))}, 1));
                (void)(alg_invoke(v_out, "Close", NULL, 0));
            }
        }
    }
    Value v_runtime = f_runtimefolder(NULL, NULL, 0);
    (void)v_runtime;
    if (alg_truthy(alg_equal(v_runtime, alg_string("")))) {
        (void)(alg_writeln(alg_add(alg_add(alg_string("[WARN] algol.c and algol.h were not found, so "), v_outdir), alg_string(" will not compile on its own."))));
    } else {
        {
            (void)(f_copyfile(NULL, (Value[]){alg_add(v_runtime, alg_string("/algol.c")), alg_add(v_outdir, alg_string("/algol.c"))}, 2));
            (void)(f_copyfile(NULL, (Value[]){alg_add(v_runtime, alg_string("/algol.h")), alg_add(v_outdir, alg_string("/algol.h"))}, 2));
        }
    }
    return alg_nil();
}

static Value f_folderof(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 1);
    Value v_path = alg_param(args[0], "String");
    (void)v_path;
    Value v_cut = alg_widen(alg_negate(alg_int(1)), "Integer");
    (void)v_cut;
    {
        Value v_i = alg_int(0);
        (void)v_i;
        for (; alg_truthy(alg_less(v_i, alg_text_length(v_path))); (v_i = alg_add(v_i, alg_int(1)))) {
            if (alg_truthy(alg_equal(alg_subscript_get(v_path, v_i), alg_char_value(47)))) {
                (void)((v_cut = alg_widen(v_i, "Integer")));
            }
        }
    }
    if (alg_truthy(alg_less(v_cut, alg_int(0)))) {
        return alg_string("");
    }
    return alg_copy(v_path, alg_int(0), v_cut);
    return alg_nil();
}

static Value f_copyfile(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 2);
    volatile Value v_frompath = alg_param(args[0], "String");
    (void)v_frompath;
    volatile Value v_topath = alg_param(args[1], "String");
    (void)v_topath;
    volatile Value v_source = alg_nil();
    (void)v_source;
    volatile Value v_target = alg_nil();
    (void)v_target;
    (void)((v_source = alg_widen(alg_text_file(), "TextFile")));
    (void)(alg_invoke(v_source, "Assign", (Value[]){v_frompath}, 1));
    {
        AlgFrame frame_1;
        alg_push_frame(&frame_1);
        if (ALG_SETJMP(frame_1.jump) == 0) {
            {
                (void)(alg_invoke(v_source, "Reset", NULL, 0));
            }
            alg_pop_frame();
        }
        else {
            static const char *names_1[] = {"String"};
            int32_t which_1 = alg_handler(frame_1.raised, names_1, 1);
            if (which_1 == 0) {
                {
                    volatile Value v_e = frame_1.raised;
                    (void)v_e;
                    return alg_bool(false);
                }
            }
            else {
                alg_raise(frame_1.raised);
            }
        }
    }
    (void)((v_target = alg_widen(alg_text_file(), "TextFile")));
    (void)(alg_invoke(v_target, "Assign", (Value[]){v_topath}, 1));
    (void)(alg_invoke(v_target, "Rewrite", NULL, 0));
    while (alg_truthy(alg_not(alg_property(v_source, "Eof")))) {
        (void)(alg_invoke(v_target, "WriteLn", (Value[]){alg_invoke(v_source, "ReadLn", NULL, 0)}, 1));
    }
    (void)(alg_invoke(v_source, "Close", NULL, 0));
    (void)(alg_invoke(v_target, "Close", NULL, 0));
    return alg_bool(true);
    return alg_nil();
}

static Value f_runtimefolder(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
    Value v_own = alg_nil();
    (void)v_own;
    (void)((v_own = alg_widen(f_folderof(NULL, (Value[]){alg_param_str(alg_int(0))}, 1), "String")));
    if (alg_truthy(alg_not_equal(v_own, alg_string("")))) {
        {
            if (alg_truthy(alg_file_exists(alg_add(v_own, alg_string("/algol.h"))))) {
                return v_own;
            }
            if (alg_truthy(alg_file_exists(alg_add(v_own, alg_string("/../share/algol24/algol.h"))))) {
                return alg_add(v_own, alg_string("/../share/algol24"));
            }
        }
    }
    if (alg_truthy(alg_file_exists(alg_string("bootstrap/algol.h")))) {
        return alg_string("bootstrap");
    }
    return alg_string("");
    return alg_nil();
}

static Value f_usage(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
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
    return alg_nil();
}

static Value f_main(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
    Value v_name = alg_nil();
    (void)v_name;
    if (alg_truthy(alg_equal(alg_param_count(), alg_int(0)))) {
        {
            (void)(f_usage(NULL, NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("--help")))) {
        {
            (void)(f_usage(NULL, NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("-h")))) {
        {
            (void)(f_usage(NULL, NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("--version")))) {
        {
            (void)(alg_writeln(alg_add(alg_string("algc "), (alg_declared(d_version, "VERSION"), v_version))));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("--compile")))) {
        {
            Value v_wanttests = alg_bool(false);
            (void)v_wanttests;
            Value v_outdir = alg_string("out");
            (void)v_outdir;
            (void)((v_name = alg_widen(alg_string(""), "String")));
            {
                Value v_i = alg_int(2);
                (void)v_i;
                for (; alg_truthy(alg_less_equal(v_i, alg_param_count())); (v_i = alg_add(v_i, alg_int(1)))) {
                    {
                        Value v_arg = alg_param_str(v_i);
                        (void)v_arg;
                        if (alg_truthy(alg_equal(v_arg, alg_string("--test")))) {
                            (void)((v_wanttests = alg_bool(true)));
                        } else {
                            {
                                if (alg_truthy(alg_equal(alg_copy(v_arg, alg_int(0), alg_int(6)), alg_string("--out=")))) {
                                    (void)((v_outdir = alg_copy(v_arg, alg_int(6), alg_subtract(alg_text_length(v_arg), alg_int(6)))));
                                } else {
                                    (void)((v_name = alg_widen(v_arg, "String")));
                                }
                            }
                        }
                    }
                }
            }
            if (alg_truthy(alg_not(alg_file_exists(v_name)))) {
                {
                    alg_raise(alg_add(alg_string("algc: cannot open "), v_name));
                }
            }
            (void)(f_compile(NULL, (Value[]){f_readsource(NULL, (Value[]){v_name}, 1), v_name, v_wanttests, v_outdir}, 4));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("--test")))) {
        {
            (void)((v_name = alg_widen(alg_param_str(alg_int(2)), "String")));
            if (alg_truthy(alg_not(alg_file_exists(v_name)))) {
                {
                    alg_raise(alg_add(alg_string("algc: cannot open "), v_name));
                }
            }
            (void)(f_setprogramarguments(NULL, (Value[]){f_argumentsfrom(NULL, (Value[]){alg_int(2)}, 1)}, 1));
            if (alg_truthy(alg_greater(f_runtests(NULL, (Value[]){f_readsource(NULL, (Value[]){v_name}, 1), v_name}, 2), alg_int(0)))) {
                (void)(alg_halt(alg_int(70)));
            }
            return alg_nil();
        }
    }
    (void)((v_name = alg_widen(alg_param_str(alg_int(1)), "String")));
    if (alg_truthy(alg_not(alg_file_exists(v_name)))) {
        {
            alg_raise(alg_add(alg_string("algc: cannot open "), v_name));
        }
    }
    (void)(f_setprogramarguments(NULL, (Value[]){f_argumentsfrom(NULL, (Value[]){alg_int(1)}, 1)}, 1));
    (void)(f_run(NULL, (Value[]){f_readsource(NULL, (Value[]){v_name}, 1), v_name}, 2));
    return alg_nil();
}

void init_Main(void) {
    alg_subrange("byte", "0", "255");
    alg_subrange("word", "0", "65535");
    alg_subrange("short", "-32768", "32767");
    fn_readsource = alg_closure("ReadSource", f_readsource, NULL, 0, 1, t_f_readsource);
    fn_checkscanned = alg_closure("CheckScanned", f_checkscanned, NULL, 0, 0, NULL);
    fn_runtests = alg_closure("RunTests", f_runtests, NULL, 0, 2, t_f_runtests);
    fn_run = alg_closure("Run", f_run, NULL, 0, 2, t_f_run);
    fn_argumentsfrom = alg_closure("ArgumentsFrom", f_argumentsfrom, NULL, 0, 1, t_f_argumentsfrom);
    fn_compile = alg_closure("Compile", f_compile, NULL, 0, 4, t_f_compile);
    fn_folderof = alg_closure("FolderOf", f_folderof, NULL, 0, 1, t_f_folderof);
    fn_copyfile = alg_closure("CopyFile", f_copyfile, NULL, 0, 2, t_f_copyfile);
    fn_runtimefolder = alg_closure("RuntimeFolder", f_runtimefolder, NULL, 0, 0, NULL);
    fn_usage = alg_closure("Usage", f_usage, NULL, 0, 0, NULL);
    fn_main = alg_closure("Main", f_main, NULL, 0, 0, NULL);
    init_Token();
    init_Expr();
    init_Stmt();
    init_Environment();
    init_ObjFunction();
    init_TypeChecker();
    init_CEmitter();
    v_version = alg_string("0.1.1");
    d_version = true;
    (void)(f_main(NULL, NULL, 0));
}

int main(int argc, char **argv) {
    alg_set_arguments(argc, argv);
    init_Main();
    return 0;
}
