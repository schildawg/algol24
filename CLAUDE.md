# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

Algol-24 (`.a24`) is a Pascal-flavoured, gradually typed language whose compiler — `algc` — is written in Algol-24 and compiles itself. There is no JDK, no Maven, no make: a C compiler is the only dependency, because the only way into the language is a checked-in copy of its own output.

- `compiler/*.a24` — **the source of truth.** Scanner, Parser, Resolver, TypeChecker, tree-walking Interpreter, and the C back end.
- `bootstrap/` — the seed. `algol.c` / `algol.h` are the hand-written C runtime; **every other `.c`/`.h` is generated** from `compiler/*.a24` and is marked `/* Generated from Algol-24. Do not edit. */`. Edit the `.a24` and re-emit instead.
- `vscode/` — a self-contained VS Code extension (TextMate grammar + Test Explorer). No build step; see its README.
- `vm/` — empty. Reserved for a bytecode VM with a real GC (the runtime's bump allocator never frees; see the memory section of `bootstrap/algol.c`).

## Gen 0 — a clean repository

This is a **clean repository**, cut deliberately from the one these sources grew up in. The C was originally produced by feeding the Algol-24 sources through **JPascal**, a Java implementation that acted as the oracle. That tie is gone: the Algol-24 sources and the C together are **Gen 0**, the origin, with no ancestor.

Removed throughout `compiler/*.a24`, `bootstrap/algol.c`, `bootstrap/algol.h`, `bootstrap/build.sh` and `vscode/`:

- **JPascal**, and the Java identifiers standing in for it — `PascalInstance`, `PascalClass`, `PascalBuffer`, `PascalTextFile`, `Numbers.java`, `CEmitter.java`, `Scanner.java`, `AssertionInvoker`, `java.util`, `HashMap.toString`.
- **The old harnesses** — `compile.sh`, `seed.sh`, `run.sh`, `gate.sh`, `agate.sh`, `cgate.sh`, `refuse.sh`, `ctest.sh`, and a `.vscode/tasks.json`. The old `test.sh` and `fixedpoint.sh` went with them; the scripts of those names in this repository were written fresh and are described above.
- **The old corpus** — `atest/`, `ctest/`, `ctest/Lox/`, and unlocated appeals to "the corpus".
- **The old documents** — `ALGOL-24.md` (the language spec), `PLAN.md` (cited by line number), `BUFFER.md`, `MAP.md`, `REVIEW.md`, and the milestone IDs that indexed them (`step 8`–`step 15`, `C4`, `C17`, `C19`, `C20`).

Nothing in the tree now refers to a file that is not in it. Do not reintroduce an external authority for this language's behaviour: a comment justifying a rule should state it as a fact about Algol-24, or anchor it to the two implementations that actually exist — the tree-walking interpreter in `compiler/Interpreter.a24` and the C runtime in `bootstrap/algol.c`, which must agree with each other.

⚠️ **The language spec left with it.** Rules that used to cite `ALGOL-24.md` (that top-level functions do not overload; that `=` and membership disagree about `1` vs `1.0`) now assert themselves in comments with nothing behind them. Those claims are load-bearing and currently unsourced.

The surviving correctness anchor is the **seed fixed point** below, not conformance with anything outside this repository. Verified working after the cut: emitting twice from one binary is byte-identical, and a compiler built from the emitted C re-emits identical C (stage3 == stage2), with 221/221 tests passing at each stage.

(The *Lox* / *clox* lineage from *Crafting Interpreters* is a separate ancestry and was deliberately left in place.)

## Commands

Build the compiler from the seed (needs only a C compiler; ~2 s):

```sh
./bootstrap/build.sh          # -> bootstrap/algc
CC=clang CFLAGS=-O0 ./bootstrap/build.sh
```

Run, test, and compile (from the repository root, so `uses` resolves):

```sh
bootstrap/algc <file.a24>                       # run a program
bootstrap/algc --test <file.a24>                # run its test blocks
bootstrap/algc --test compiler/Main.a24         # the whole compiler suite (221 tests)
bootstrap/algc --compile --out=DIR <file.a24>   # emit C into DIR (must already exist)
bootstrap/algc --compile --test --out=DIR <f>   # emit the tests plus a runner
```

⚠️ **There is no per-test filter, and no per-file one either.** `--test X.a24` runs every test block reachable from `X.a24`, its imports included — the narrowest thing you can run is a leaf module. `compiler/Token.a24` (2 tests) and `compiler/Scanner.a24` are useful fast loops; `compiler/Main.a24` imports everything.

The emitted directory is *not* self-contained despite what `--help` says: the emitter writes `#include "algol.h"` but never the runtime itself. Copy it in:

```sh
cp bootstrap/algol.c bootstrap/algol.h DIR/ && cc -std=c11 -O2 -o DIR/prog DIR/*.c
```

## Known issues

**String concatenation used to have a memory problem that killed performance — fixed.** Strings are immutable and `+` copied both operands, and nothing is ever freed (`bootstrap/algol.c`'s arena never reclaims), so accumulating text a piece at a time retained every intermediate — roughly n²/2 bytes, all live. Measured: **807 MB for 40,000 appends compiled**, against 17 MB for the same loop through a `Buffer`.

`concat` now reserves double the room it needs and appends into that slack in place, so `S := S + 'x'` is linear: **1.7 MB compiled**, 77 MB interpreted (the residue there is the tree-walker's own per-iteration allocation, not the string). `Buffer` is still the right tool for large accumulation and the hot paths keep using it, but `+` is no longer a cliff.

⚠️ **Safe only because a String carries its own length.** The append overwrites the terminator an alias of the shorter view was relying on; the alias reads its own length everywhere that measures, compares or prints, and `as_text` hands a terminated copy to everything else. See `spec/ALGOL-24.md` Annex G.2, which also records that the fix *it* predicted — "append when the left operand is the arena's most recent allocation" — never fires, because `S + 'x'` allocates the Char first.

⚠️ **The test must be identity, not just a fitting capacity.** The left operand has to be the string the reserved block currently holds, pointer *and* length. Otherwise two appends from one base both succeed and the second overwrites the first.

**A file in an import cycle with the root — fixed.** The root used to be the one file never entered in the parser's `Loaded` map, so when a module imported the root back — `Parser` uses `Interpreter`, which uses `Parser` — the root was parsed a second time with its statements intact.

`Parser.Parse` now enters the file being parsed in `Loaded` before reading its own `uses` clauses, and `Interpreter.RegisterRoot` registers the root's environment (the globals themselves, not a copy) in `Modules` before its body runs. `--compile --test compiler/Parser.a24` emits where it used to refuse with `Two modules named 'Parser' is not supported by the C back end yet.`, which was the only known case of a valid program having no compiled form.

⚠️ **Registration is needed in every driver, not just `Run`.** An import-only node carries no statements, so a root that is not registered makes `VisitModuleStmt` take the not-yet-loaded branch and execute nothing at all. `--test` on a file in a cycle with the root failed on exactly that, and `RunTests` registers the root for the same reason `Interpret` does.

⚠️ **Identity is the path string.** `Loaded` keys on the resolved path, so the root's own name and the name a module resolves for it must match character for character.

### Running the tests

```sh
./test.sh                        # every test the compiler can reach (221)
./test.sh compiler/Scanner.a24   # that file, and everything it imports (26)
./test.sh -q                     # summary only; opens up if anything fails
```

Builds `bootstrap/algc` first if it isn't there. Exit is non-zero on any failure, and the last line is a one-line verdict.

⚠️ **There is no per-test or per-file filter** — naming a file runs every test block it can *reach*, its imports' included, so `Parser.a24` runs Scanner's and Token's too and reports a larger count than the file's own. `compiler/Main.a24` imports everything, which is what makes it the complete suite. The narrowest runnable thing is a leaf module.

⚠️ **A file that fails to parse reports nothing at all** — no report, no count, just a diagnostic on stderr. Zero tests run is not a clean run, so the script surfaces both streams and says `no tests ran` rather than passing.

The compiled back end runs the same suite (`--compile --test`, copy the runtime in, `cc`, run) and currently produces a report **identical line for line** to the interpreted one, all 221 tests — which is the strongest available check that the two implementations agree. `test.sh` does not do this yet; it only runs the interpreted half.

### Checking the fixed point

`./fixedpoint.sh` is the gate, and the only correctness anchor outside the test suite. It builds its own compiler from the seed (so it does not care about `bootstrap/algc`) and runs two checks that answer different questions:

- **Seed in sync** — is `bootstrap/*.c` what the compiler emits from `compiler/*.a24` today? Catches an edited `.a24` that was never reseeded.
- **Fixed point** — does the compiler emit the same C once compiled by itself? Catches a change to the emitter that alters how the compiler's own source comes out.

⚠️ **One reseed is not always enough**, which is why it iterates. Generation 1 holds the new emitter's *source* written by the *old* emitter's rules; only at generation 2 do the two agree. A change to how the compiler emits its own code takes two generations to settle, and nothing but this comparison reveals it.

Exit is non-zero on either failure. `--keep` leaves the generations behind (the converged one is what should be seeded); `--max=N` and `--source=FILE` are also accepted. Failing to settle at all points at run-to-run state leaking into emitted text — a map iterated in hash order, an address or capacity printed, a timestamp.

### Reseeding after a change to `compiler/*.a24`

`bootstrap/*.c` is a fixed point: the checked-in C is **byte-identical** to what the current compiler emits from `compiler/*.a24` (verified). Any change to the compiler must be reseeded through the old binary, or the seed and the source drift apart:

```sh
./bootstrap/build.sh                                     # stage 1, from the old seed
mkdir -p /tmp/stage2
bootstrap/algc --compile --out=/tmp/stage2 compiler/Main.a24
cp /tmp/stage2/*.c /tmp/stage2/*.h bootstrap/            # never overwrites algol.c/algol.h
./bootstrap/build.sh                                     # stage 2 builds itself
bootstrap/algc --test compiler/Main.a24
```

A useful invariant to check at any time: emit into a scratch directory and `diff` against `bootstrap/` — every file should be identical unless you changed the compiler.

## Architecture

One front end, two back ends. `compiler/Main.a24` wires it, and `Run`, `RunTests` and `Compile` deliberately share the same front end — a program that fails to parse or type-check must fail identically whichever back end is asked for, or the two stop describing one language.

```
Scanner → Parser → Resolver → TypeChecker → ┬→ Interpreter  (tree-walking)
                                            └→ CEmitter     (C11 + algol.c runtime)
```

- **Scanner** records errors instead of raising (`HadError` / `LastError`, module-level, not per instance). Drivers must ask — `Main.a24`'s `CheckScanned` is called *twice*, once after scanning for the right message and once after parsing for coverage of modules loaded by `uses`.
- **Parser** is also the module loader. A `uses Foo;` resolves `Foo.a24` beside the importing file first, then the working directory, parses it inline, and returns a `ModuleStmt`. The `Loaded` map is shared with sub-parsers so a diamond loads once; a re-import yields an empty module node rather than nothing, so the second importer still *sees* it. `private` at the top level marks a name unexported.
- **Resolver** binds variables to scope depth, tracks constants (every name is recorded, not just the constant ones, so an inner `var` may shadow an outer `const`), and decides whether a dotted name is a unit qualifier or a receiver. `System` — the built-ins — is in every file's unit set and is imported by nobody.
- **TypeChecker** is gradual: an unknown symbol answers `''`, which is normal rather than an error. Element types (`List of Token`) are scoped; class parents and inferred types are flat, since classes are top-level and never go out of scope.
- **Interpreter** is a tree walker. Built-ins are classes with `Arity` and `Call` wrapping the host's own operations, so interpreted `Length` *is* host `Length` and the two cannot disagree. `Obj*.a24` are its runtime objects (collections, files, buffers, enums, instances, closures).
- **CEmitter** **refuses by name** what it cannot emit (`'<X> is not supported by the C back end yet.'`) rather than emitting nothing — see the twenty `Unsupported (…)` call sites. Silent gaps would produce a binary that disagrees with the interpreter. Coverage is the language as this compiler uses it (it compiles itself, tests included); what remains refused are edge cases — an identifier C cannot spell, two modules claiming one name, a `var` as an unbraced branch, a function nested more than one level deep or declared inside a method, `super` as a value, a nested `uses`.

### Emitted C

One `.c`/`.h` pair per source unit. Names are mangled by kind — `v_` variable, `f_` function, `fn_` its closure value, `k_` class handle, `e_` enum, `c_` const — always through `Mangle`/`SymbolOf`, never by hand-concatenating a prefix. A private name colliding across units is renamed `Name__Unit`. Each unit gets an `init_<Unit>()`, and generated `main` calls them in dependency order before `init_Main()`, which runs the top-level statements.

`algol.h` is the contract between emitter and runtime and is heavily commented — read it before touching either side. Values are tagged (`Value` with a C11 anonymous union) because the checker is gradual and most expressions have no known C type at emit time. Method and property access dispatch at run time through `alg_invoke` / `alg_property`; overloads select on the whole signature, not arity. Exceptions are `setjmp`/`longjmp` over a frame stack, using the mask-free variants where the platform's are not already mask-free.

## Tests

Tests live inline in the source they cover, as `test 'Name'; begin … end` blocks using `AssertEqual`, `AssertTrue` and `Fail`. `--test` runs them instead of the program; the main block never executes. Failures exit 70, via `Halt(70)` — the driver used to `raise` for it, which printed `Uncaught: Tests failed.` after the report.

The compiled test runner reproduces the interpreter's report **line for line, including the `[ERROR]` line naming why each failure failed** — verified over the whole 221-test suite.

⚠️ It used to print only `FAIL` and throw the message away, which is how the two processors came to disagree about `AssertTrue`'s wording without anything noticing. A test failure prints exactly one `[ERROR]` line, not three: `Console.Error` adds a source line and a caret, and a test failure does not go through it.

⚠️ The file named is the **root**, not the file the failing test lives in, because `SourceCode` is one global keyed by line number. The compiled runner copies that deliberately, since the reports are compared.

⚠️ A failing run used to print `Uncaught: Tests failed.` interpreted and nothing compiled. `Halt` was added for it, so both now print only the report — a failing suite is identical through both processors too, not just a passing one.

## Working in `.a24`

Style is visible and consistent: `///` doc comments above declarations, `//` inline, and **`⚠️` marks a hard-won constraint** — a paragraph explaining why the obvious alternative was wrong. Those are load-bearing; read them before "simplifying" the code they guard, and write one when you fix something subtle.

Language points that bite when editing:

- `Exit` returns (`Exit Value;` in a function). Keywords are case-insensitive; `unit`, `test` and `on` are context-sensitive identifiers, not keywords.
- Strings are 0-based. `Pos` returns `-1` when absent; `Copy` clamps its end but not its start. **No backslash escapes** — `'\n'` is two characters; `#10` is a newline, `#27` is ESC.
- A one-character literal is a **Char**, never a String, and the two are never equal. `Str(…)` is how you widen — hence `Line('{')` needing `Any`.
- Truthiness is not Lox's: `nil`, `False`, the Integer `0`, and an enum member with ordinal 0 are falsey; `0.0`, `''` and any Char are truthy.
- `?` and `!` are identifier characters (`Gate?` is one word).
- Accumulate text with `Buffer`, not `Result := Result + Line` — the latter is O(n²) in memory that is never reclaimed, and this compiler's own largest source is over 100 KB.
- ⚠️ `uses` order in `Main.a24` matters: a module's functions close over the environment its file was loaded in, so `TypeChecker` must come after `Parser` for its test blocks to reach the parser.

If you add a token to `compiler/TokenType.a24` and register it in `Scanner.a24`'s `Keywords`, mirror it into `vscode/syntaxes/algol24.tmLanguage.json` — nothing checks that, and no test covers that directory.
