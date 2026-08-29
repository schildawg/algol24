/* Generated from Algol-24.  Do not edit. */
#include "Main.h"
#include "AstPrinter.h"
#include "Token.h"
#include "TokenType.h"
#include "Unicode.h"
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

static Value f_ReadSource(Value **cells, Value *args, int32_t count);
static Value f_CheckScanned(Value **cells, Value *args, int32_t count);
static Value f_RunTests(Value **cells, Value *args, int32_t count);
static Value f_Run(Value **cells, Value *args, int32_t count);
static Value f_ArgumentsFrom(Value **cells, Value *args, int32_t count);
static Value f_Compile(Value **cells, Value *args, int32_t count);
static Value f_Usage(Value **cells, Value *args, int32_t count);
static Value f_Main(Value **cells, Value *args, int32_t count);
static Value v_SAMPLE;
static Value fn_ReadSource;
static Value fn_CheckScanned;
static Value fn_RunTests;
static Value fn_Run;
static Value fn_ArgumentsFrom;
static Value fn_Compile;
static Value fn_Usage;
static Value fn_Main;

static Value f_ReadSource(Value **cells, Value *args, int32_t count) {
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

static Value f_CheckScanned(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    if (alg_truthy(v_HadError)) {
        alg_raise(alg_str(v_LastError));
    }
    return alg_nil();
}

static Value f_RunTests(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Source = args[0];
    (void)v_Source;
    Value v_FileName = args[1];
    (void)v_FileName;
    Value v_TheScanner = alg_nil();
    (void)v_TheScanner;
    Value v_TheParser = alg_nil();
    (void)v_TheParser;
    Value v_TheResolver = alg_nil();
    (void)v_TheResolver;
    Value v_TheInterpreter = alg_nil();
    (void)v_TheInterpreter;
    Value v_Stmts = alg_nil();
    (void)v_Stmts;
    (void)(alg_invoke(alg_singleton(k_SourceCode), "Begins", (Value[]){v_FileName}, 1));
    (void)((v_TheScanner = alg_new(k_Scanner, (Value[]){v_Source}, 1)));
    (void)((v_TheParser = alg_new(k_Parser, (Value[]){alg_invoke(v_TheScanner, "ScanTokens", NULL, 0)}, 1)));
    (void)(f_CheckScanned(NULL, NULL, 0));
    (void)(alg_set_property(v_TheParser, "FileName", v_FileName));
    (void)((v_Stmts = alg_invoke(v_TheParser, "Parse", NULL, 0)));
    (void)(f_CheckScanned(NULL, NULL, 0));
    (void)((v_TheInterpreter = alg_new(k_Interpreter, NULL, 0)));
    (void)((v_TheResolver = alg_new(k_Resolver, (Value[]){v_TheInterpreter}, 1)));
    (void)(alg_invoke(v_TheResolver, "ResolveAll", (Value[]){v_Stmts}, 1));
    (void)(alg_invoke(alg_new(k_TypeChecker, NULL, 0), "Resolve", (Value[]){v_Stmts}, 1));
    return alg_invoke(v_TheInterpreter, "RunTests", (Value[]){v_Stmts, v_FileName}, 2);
    return alg_nil();
}

static Value f_Run(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Source = args[0];
    (void)v_Source;
    Value v_FileName = args[1];
    (void)v_FileName;
    Value v_TheScanner = alg_nil();
    (void)v_TheScanner;
    Value v_TheParser = alg_nil();
    (void)v_TheParser;
    Value v_TheResolver = alg_nil();
    (void)v_TheResolver;
    Value v_TheInterpreter = alg_nil();
    (void)v_TheInterpreter;
    Value v_Tokens = alg_nil();
    (void)v_Tokens;
    Value v_Stmts = alg_nil();
    (void)v_Stmts;
    (void)(alg_invoke(alg_singleton(k_SourceCode), "Begins", (Value[]){v_FileName}, 1));
    (void)((v_TheScanner = alg_new(k_Scanner, (Value[]){v_Source}, 1)));
    (void)((v_Tokens = alg_invoke(v_TheScanner, "ScanTokens", NULL, 0)));
    (void)(f_CheckScanned(NULL, NULL, 0));
    (void)((v_TheParser = alg_new(k_Parser, (Value[]){v_Tokens}, 1)));
    (void)(alg_set_property(v_TheParser, "FileName", v_FileName));
    (void)((v_Stmts = alg_invoke(v_TheParser, "Parse", NULL, 0)));
    (void)(f_CheckScanned(NULL, NULL, 0));
    (void)((v_TheInterpreter = alg_new(k_Interpreter, NULL, 0)));
    (void)(alg_set_property(v_TheInterpreter, "RootFile", v_FileName));
    (void)((v_TheResolver = alg_new(k_Resolver, (Value[]){v_TheInterpreter}, 1)));
    (void)(alg_invoke(v_TheResolver, "ResolveAll", (Value[]){v_Stmts}, 1));
    (void)(alg_invoke(alg_new(k_TypeChecker, NULL, 0), "Resolve", (Value[]){v_Stmts}, 1));
    (void)(alg_invoke(v_TheInterpreter, "Interpret", (Value[]){v_Stmts}, 1));
    return alg_nil();
}

static Value f_ArgumentsFrom(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_First = args[0];
    (void)v_First;
    Value v_Result = alg_list();
    (void)v_Result;
    {
        Value v_I = v_First;
        (void)v_I;
        while (alg_truthy(alg_less_equal(v_I, alg_param_count()))) {
            {
                (void)(alg_invoke(v_Result, "Add", (Value[]){alg_param_str(v_I)}, 1));
                (void)((v_I = alg_add(v_I, alg_int(1))));
            }
        }
    }
    return v_Result;
    return alg_nil();
}

static Value f_Compile(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Source = args[0];
    (void)v_Source;
    Value v_FileName = args[1];
    (void)v_FileName;
    Value v_WantTests = args[2];
    (void)v_WantTests;
    Value v_OutDir = args[3];
    (void)v_OutDir;
    Value v_TheScanner = alg_nil();
    (void)v_TheScanner;
    Value v_TheParser = alg_nil();
    (void)v_TheParser;
    Value v_Stmts = alg_nil();
    (void)v_Stmts;
    (void)(alg_invoke(alg_singleton(k_SourceCode), "Begins", (Value[]){v_FileName}, 1));
    (void)((v_TheScanner = alg_new(k_Scanner, (Value[]){v_Source}, 1)));
    (void)((v_TheParser = alg_new(k_Parser, (Value[]){alg_invoke(v_TheScanner, "ScanTokens", NULL, 0)}, 1)));
    (void)(f_CheckScanned(NULL, NULL, 0));
    (void)(alg_set_property(v_TheParser, "FileName", v_FileName));
    (void)((v_Stmts = alg_invoke(v_TheParser, "Parse", NULL, 0)));
    (void)(f_CheckScanned(NULL, NULL, 0));
    Value v_TheInterpreter = alg_new(k_Interpreter, NULL, 0);
    (void)v_TheInterpreter;
    (void)(alg_invoke(alg_new(k_Resolver, (Value[]){v_TheInterpreter}, 1), "ResolveAll", (Value[]){v_Stmts}, 1));
    (void)(alg_invoke(alg_new(k_TypeChecker, NULL, 0), "Resolve", (Value[]){v_Stmts}, 1));
    Value v_TheEmitter = alg_new(k_CEmitter, NULL, 0);
    (void)v_TheEmitter;
    (void)(alg_invoke(v_TheEmitter, "CompilingFile", (Value[]){v_FileName}, 1));
    if (alg_truthy(v_WantTests)) {
        (void)(alg_invoke(v_TheEmitter, "WithTests", NULL, 0));
    }
    Value v_TheFiles = alg_invoke(v_TheEmitter, "Emit", (Value[]){v_Stmts, alg_invoke(v_TheEmitter, "UnitNameOf", (Value[]){v_FileName}, 1)}, 2);
    (void)v_TheFiles;
    {
        Value loop_0 = alg_iterable(alg_invoke(v_TheFiles, "Keys", NULL, 0));
        for (int32_t at_0 = 0; at_0 < alg_iterable_count(loop_0); at_0++) {
            Value v_Name = alg_iterable_at(loop_0, at_0);
            (void)v_Name;
            {
                Value v_Out = alg_text_file();
                (void)v_Out;
                (void)(alg_invoke(v_Out, "Assign", (Value[]){alg_add(alg_add(v_OutDir, alg_char_value(47)), alg_str(v_Name))}, 1));
                (void)(alg_invoke(v_Out, "Rewrite", NULL, 0));
                (void)(alg_invoke(v_Out, "Write", (Value[]){alg_str(alg_invoke(v_TheFiles, "Get", (Value[]){v_Name}, 1))}, 1));
                (void)(alg_invoke(v_Out, "Close", NULL, 0));
            }
        }
    }
    return alg_nil();
}

static Value f_Usage(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
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

static Value f_Main(Value **cells, Value *args, int32_t count) {
    (void)cells; (void)args; (void)count;
    Value v_Name = alg_nil();
    (void)v_Name;
    if (alg_truthy(alg_equal(alg_param_count(), alg_int(0)))) {
        {
            (void)(f_Run(NULL, (Value[]){v_SAMPLE, alg_string("<sample>")}, 2));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("--help")))) {
        {
            (void)(f_Usage(NULL, NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("-h")))) {
        {
            (void)(f_Usage(NULL, NULL, 0));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("--compile")))) {
        {
            Value v_WantTests = alg_bool(false);
            (void)v_WantTests;
            Value v_OutDir = alg_string("out");
            (void)v_OutDir;
            (void)((v_Name = alg_string("")));
            {
                Value v_I = alg_int(2);
                (void)v_I;
                while (alg_truthy(alg_less_equal(v_I, alg_param_count()))) {
                    {
                        {
                            Value v_Arg = alg_param_str(v_I);
                            (void)v_Arg;
                            if (alg_truthy(alg_equal(v_Arg, alg_string("--test")))) {
                                (void)((v_WantTests = alg_bool(true)));
                            } else {
                                {
                                    if (alg_truthy(alg_equal(alg_copy(v_Arg, alg_int(0), alg_int(6)), alg_string("--out=")))) {
                                        (void)((v_OutDir = alg_copy(v_Arg, alg_int(6), alg_subtract(alg_length(v_Arg), alg_int(6)))));
                                    } else {
                                        (void)((v_Name = v_Arg));
                                    }
                                }
                            }
                        }
                        (void)((v_I = alg_add(v_I, alg_int(1))));
                    }
                }
            }
            if (alg_truthy(alg_not(alg_file_exists(v_Name)))) {
                {
                    alg_raise(alg_add(alg_string("algc: cannot open "), v_Name));
                }
            }
            (void)(f_Compile(NULL, (Value[]){f_ReadSource(NULL, (Value[]){v_Name}, 1), v_Name, v_WantTests, v_OutDir}, 4));
            return alg_nil();
        }
    }
    if (alg_truthy(alg_equal(alg_param_str(alg_int(1)), alg_string("--test")))) {
        {
            (void)((v_Name = alg_param_str(alg_int(2))));
            if (alg_truthy(alg_not(alg_file_exists(v_Name)))) {
                {
                    alg_raise(alg_add(alg_string("algc: cannot open "), v_Name));
                }
            }
            (void)(f_SetProgramArguments(NULL, (Value[]){f_ArgumentsFrom(NULL, (Value[]){alg_int(2)}, 1)}, 1));
            if (alg_truthy(alg_greater(f_RunTests(NULL, (Value[]){f_ReadSource(NULL, (Value[]){v_Name}, 1), v_Name}, 2), alg_int(0)))) {
                (void)(alg_halt(alg_int(70)));
            }
            return alg_nil();
        }
    }
    (void)((v_Name = alg_param_str(alg_int(1))));
    if (alg_truthy(alg_not(alg_file_exists(v_Name)))) {
        {
            alg_raise(alg_add(alg_string("algc: cannot open "), v_Name));
        }
    }
    (void)(f_SetProgramArguments(NULL, (Value[]){f_ArgumentsFrom(NULL, (Value[]){alg_int(1)}, 1)}, 1));
    (void)(f_Run(NULL, (Value[]){f_ReadSource(NULL, (Value[]){v_Name}, 1), v_Name}, 2));
    return alg_nil();
}

void init_Main(void) {
    fn_ReadSource = alg_closure("ReadSource", f_ReadSource, NULL, 0, 1);
    fn_CheckScanned = alg_closure("CheckScanned", f_CheckScanned, NULL, 0, 0);
    fn_RunTests = alg_closure("RunTests", f_RunTests, NULL, 0, 2);
    fn_Run = alg_closure("Run", f_Run, NULL, 0, 2);
    fn_ArgumentsFrom = alg_closure("ArgumentsFrom", f_ArgumentsFrom, NULL, 0, 1);
    fn_Compile = alg_closure("Compile", f_Compile, NULL, 0, 4);
    fn_Usage = alg_closure("Usage", f_Usage, NULL, 0, 0);
    fn_Main = alg_closure("Main", f_Main, NULL, 0, 0);
    v_SAMPLE = alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_add(alg_string("class Doughnut;"), alg_char_value(10)), alg_string("begin")), alg_char_value(10)), alg_string("    procedure Cook();")), alg_char_value(10)), alg_string("    begin")), alg_char_value(10)), alg_string("        WriteLn ('Fry until golden!');")), alg_char_value(10)), alg_string("    end")), alg_char_value(10)), alg_string("end")), alg_char_value(10)), alg_string("")), alg_char_value(10)), alg_string("class BostonCream(Doughnut);")), alg_char_value(10)), alg_string("begin")), alg_char_value(10)), alg_string("    procedure Cook();")), alg_char_value(10)), alg_string("    begin")), alg_char_value(10)), alg_string("        super.Cook();")), alg_char_value(10)), alg_string("        WriteLn ('Pipe full of custard and coat with chocolate!');")), alg_char_value(10)), alg_string("    end")), alg_char_value(10)), alg_string("end")), alg_char_value(10)), alg_string("")), alg_char_value(10)), alg_string("BostonCream().Cook();")), alg_char_value(10));
    (void)(f_Main(NULL, NULL, 0));
}

int main(int argc, char **argv) {
    alg_set_arguments(argc, argv);
    init_TokenType();
    init_Token();
    init_Expr();
    init_AstPrinter();
    init_Unicode();
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
