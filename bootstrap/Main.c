/* Generated from Algol-24.  Do not edit. */
#include "Main.h"
#include "AstPrinter.h"
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
static Value f_usage(Value **cells, Value *args, int32_t count);
static Value f_main(Value **cells, Value *args, int32_t count);
static Value v_sample;
static bool d_sample;
static Value fn_readsource;
static Value fn_checkscanned;
static Value fn_runtests;
static Value fn_run;
static Value fn_argumentsfrom;
static Value fn_compile;
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
        while (alg_truthy(alg_less_equal(v_i, alg_param_count()))) {
            {
                (void)(alg_invoke(v_result, "Add", (Value[]){alg_param_str(v_i)}, 1));
                (void)((v_i = alg_add(v_i, alg_int(1))));
            }
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
    (void)(alg_writeln(alg_string("  algc --help                        this")));
    (void)(alg_writeln(alg_string("")));
    (void)(alg_writeln(alg_string("The emitted directory is self-contained: cc *.c -o <name>")));
    return alg_nil();
}

static Value f_main(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    alg_arity(count, 0);
    Value v_name = alg_nil();
    (void)v_name;
    if (alg_truthy(alg_equal(alg_param_count(), alg_int(0)))) {
        {
            (void)(f_run(NULL, (Value[]){(alg_declared(d_sample, "SAMPLE"), v_sample), alg_string("<sample>")}, 2));
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
                while (alg_truthy(alg_less_equal(v_i, alg_param_count()))) {
                    {
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
                        (void)((v_i = alg_add(v_i, alg_int(1))));
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
    fn_readsource = alg_closure("ReadSource", f_readsource, NULL, 0, 1);
    fn_checkscanned = alg_closure("CheckScanned", f_checkscanned, NULL, 0, 0);
    fn_runtests = alg_closure("RunTests", f_runtests, NULL, 0, 2);
    fn_run = alg_closure("Run", f_run, NULL, 0, 2);
    fn_argumentsfrom = alg_closure("ArgumentsFrom", f_argumentsfrom, NULL, 0, 1);
    fn_compile = alg_closure("Compile", f_compile, NULL, 0, 4);
    fn_usage = alg_closure("Usage", f_usage, NULL, 0, 0);
    fn_main = alg_closure("Main", f_main, NULL, 0, 0);
    v_sample = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("class Doughnut;"), alg_char_value(10)), alg_string("begin")), alg_char_value(10)), alg_string("    procedure Cook();")), alg_char_value(10)), alg_string("    begin")), alg_char_value(10)), alg_string("        WriteLn ('Fry until golden!');")), alg_char_value(10)), alg_string("    end")), alg_char_value(10)), alg_string("end")), alg_char_value(10)), alg_string("")), alg_char_value(10)), alg_string("class BostonCream(Doughnut);")), alg_char_value(10)), alg_string("begin")), alg_char_value(10)), alg_string("    procedure Cook();")), alg_char_value(10)), alg_string("    begin")), alg_char_value(10)), alg_string("        super.Cook();")), alg_char_value(10)), alg_string("        WriteLn ('Pipe full of custard and coat with chocolate!');")), alg_char_value(10)), alg_string("    end")), alg_char_value(10)), alg_string("end")), alg_char_value(10)), alg_string("")), alg_char_value(10)), alg_string("BostonCream().Cook();")), alg_char_value(10));
    d_sample = true;
    (void)(f_main(NULL, NULL, 0));
}

int main(int argc, char **argv) {
    alg_set_arguments(argc, argv);
    init_TokenType();
    init_Token();
    init_Expr();
    init_AstPrinter();
    init_Stmt();
    init_Environment();
    init_SourceCode();
    init_Scanner();
    init_Console();
    init_ObjBuffer();
    init_ObjInstance();
    init_ObjClass();
    init_ObjCollection();
    init_ObjEnum();
    init_ObjFile();
    init_Parser();
    init_Resolver();
    init_Interpreter();
    init_ObjFunction();
    init_TypeChecker();
    init_CEmitter();
    init_Main();
    return 0;
}
