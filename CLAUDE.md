# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

Algol-24 is a Pascal-flavoured, gradually typed language. The compiler is
written in Algol-24 and compiles itself; it interprets a program or emits C for
it. `bootstrap/` holds the compiler's own output as checked-in C, so a C
compiler is the only prerequisite for a build.

**`ALGOL-24.md` is normative and development is spec-driven.** It states what
the language *shall* do, not what the implementations do — a rule is in it
because it is right, and where an implementation does not match, the rule stands
and names the issue tracking the gap. Several rules in it are true of no
processor yet, identifier case-insensitivity among them. The first release is
the point at which the spec says what it should say and the code does what the
spec says.

Three consequences when working here:

- **Never "correct" the spec to match the code.** A disagreement between them is
  a defect in the code, or an open decision, and both have homes below.
- **Defects are GitHub issues**, reproduced in `tests/defects/`, whose README is
  the offline index. They do not go in the spec: a specification that doubles as
  a bug list goes stale the first time a fix lands without an edit.
- **Open decisions live in the spec** under that heading — genuine questions
  about what the language means, each with a recommendation. They are the user's
  to settle, not mine, and each one blocks the release.

## Commands

```sh
./build.sh                        # two-stage build -> ./algc
./build.sh --clean                # rm -rf .build and ./algc first
./build.sh --reseed               # copy stage 2's C back into bootstrap/
cd bootstrap && ./build.sh        # the seed alone, from checked-in C

./compile.sh Prog.a24             # -> build/Prog   (OUT=dir to change it)
./compile.sh Prog.a24 --run a b   # ...and exec it with arguments

./test.sh                         # unit conformance compiled programs fixedpoint leaks memory
./test.sh unit                    # any one of those seven names

./algc                            # no arguments: runs the SAMPLE program in Main.a24
./algc Prog.a24                   # interpret
./algc --test Prog.a24            # run its test blocks
./algc --compile [--test] [--out=DIR] Prog.a24
```

`CC` (default `cc`) and `CFLAGS` (default `-std=c11 -O2`) are read by
`build.sh`, `compile.sh`, `test.sh` and `bootstrap/build.sh`. Each resolves
`ROOT` from `$0`, so they run from any working directory.

`--out` defaults to `out` and **the directory must already exist** — the
language has no way to create one, so every caller `mkdir -p`s first. Emitting
into a missing directory fails with `Rewrite failed: cannot open 'DIR/X.h'`.

There is no per-test filter. The unit granularity is a file:
`./algc --test compiler/Parser.a24` runs that module's `test` blocks. But a
module's tests can only reach what its own file `uses`.

**The order of the `uses` clauses in `compiler/Main.a24` is load-bearing, and
nothing in the file says so any more.** A module's functions close over the
environment its own file was loaded in, so `uses TypeChecker` must come *after*
`uses Scanner` and `uses Parser` — driving the checker over real source is the
only way to test it, and it can only reach a front end already loaded.
Reordering that block silently breaks TypeChecker's test blocks.

## The bootstrap loop

`bootstrap/*.c` is generated output **except** `algol.c` / `algol.h`, which are
the hand-written C runtime. `build.sh` and `test.sh` both exclude exactly
`algol.[ch]` and `build.sh` from every comparison, since those are not emitted
and would otherwise read as a permanent difference.

1. stage 1 — `cc bootstrap/*.c` → a working compiler in `.build/stage1`
2. stage 2 — that compiler compiles `compiler/Main.a24` → `.build/stage2` → `./algc`
3. the check — `diff -r` stage 2's C against `bootstrap/`

A difference means the seed is stale. `build.sh` reports it and carries on;
`test.sh fixedpoint` treats it as a hard failure. So the cycle for a compiler
change is **edit `compiler/` → `./build.sh` → `./test.sh` → `./build.sh
--reseed`**, committing `compiler/` and `bootstrap/` together.

Edit `bootstrap/algol.[ch]` in place — they are copied verbatim into every
emitted directory, so a runtime change takes effect without a reseed.

`fixedpoint` then builds generation 2, has it emit generation 3, and requires
g2 and g3 to be byte-identical. That is a **determinism** check: no hash-order
iteration, no timestamps, no addresses may reach the emitted text. Correct code
can fail it and nothing else here would notice.

## Architecture

`compiler/Main.a24` drives three entry paths — `Run`, `RunTests`, `Compile` —
through one front end:

```
Scanner -> Parser -> Resolver -> TypeChecker -> { Interpreter | CEmitter }
```

The shared prefix is deliberate: a program that fails to parse or check must
fail identically whichever back end is asked for, or the two stop describing one
language. Note the order — the Resolver runs **before** the TypeChecker in all
three paths.

`CheckScanned()` is called twice, after `ScanTokens` and again after `Parse`,
and the two are not redundant. Scan errors are recorded in a module-level
`HadError` rather than thrown, so the first call gets the *message* right
(before a parse error masks it) and the second gets the *coverage* (a scanner
built for an imported module sets the same flag, which the first call cannot
see).

| Module | Role |
|---|---|
| `Scanner` | source → tokens; keywords are case-insensitive, identifiers are not — see issue #1, the spec says they should be |
| `Parser` | tokens → `Stmt`/`Expr`; also **loads modules** — it reads `uses` files itself |
| `Resolver` | scope resolution and slot depths; owns the `Units` and `Dottable` sets |
| `TypeChecker` | gradual typing over a scoped `TypeLookup` |
| `Interpreter` | tree-walker — the reference implementation; `ALGOL-24.md` defines the language |
| `CEmitter` | emits C11, one translation unit per source file |
| `Environment` | lexical scopes, `Imports`, and the `Exports` set |
| `Obj*` | `ObjClass`, `ObjInstance`, `ObjFunction`, `ObjEnum`, `ObjCollection`, `ObjBuffer`, `ObjFile` |
| `SourceCode`, `Console` | singletons: source lines for error carets, and coloured reports |
| `AstPrinter`, `Token`, `TokenType`, `Expr`, `Stmt` | support |

Module loading lives in the `Parser`, not in `Main`, because the parser is what
follows a `uses` clause and `Main` is loaded last — a helper there would not be
in scope. A `uses` looks beside the importing file first (`Parser.FileName`),
then the working directory, and `Loaded` is **shared** between a file's parser
and its imports' parsers, which is what makes a diamond load once and stops a
cycle from recursing forever.

Non-transitivity is enforced in `Environment`: `Imports` is searched for each
module's **own** bindings only, never through that module's imports in turn.
That is also why the search cannot cycle — and it must not, because the real
dependency graph does.

`Resolver.Dottable` deliberately excludes classes and functions. Neither can
answer a dot, so the syntactic slot is free, and that is what lets
`Scanner.ScanTokens()` work in a file whose unit and primary class share a name.

### The emitter

- One `.c` + `.h` per **source** file, which is what lets `private` become C's
  `static`. File names are sanitized into C identifiers.
- **Every C symbol built from a user-written name goes through `Mangle` /
  `SymbolOf`.** Prefixes: `v_` variable, `f_` function, `k_` class, `m_` method,
  `e_` enum type/member, `i_` field initializer. A bare `'k_' + Name`
  concatenated by hand anywhere is a known bug returning — nine sites once did
  that and none of them mangled, so a name containing `?` emitted `k_Gate?` and
  cc refused it. `?` is legal in an Algol-24 identifier and becomes `_q`.
- `ClassHandle` and `EnumTypeName` go through `Mangle` (renames applied) while
  `InitName` does not. The rule is whether the symbol appears in a **header**.
- Unsupported constructs **raise by name** through `Unsupported(...)` (~21
  sites) rather than emitting nothing, so the covered subset stays honest. The
  messages are part of the observable surface and are compared, so treat their
  wording as fixed.

### The runtime (`bootstrap/algol.h`)

Read this header first for any back-end work; it is the most precise statement
of the language's semantics in the repository.

- Emitted code manipulates tagged `Value`s through `alg_*` calls, because a
  gradually typed expression usually has no known C type at emit time. Where the
  type *is* known the emitter may emit the direct form — an optimization, not a
  requirement.
- `alg_property` / `alg_invoke` dispatch **by name at run time**. One emitted
  call covers an instance field, a collection's `Length`, and a method on
  either. Overloads select on the whole signature, also at run time.
- Method names match case-sensitively on a class and case-insensitively on a
  built-in collection, matching the interpreter.
- Exceptions are `setjmp`/`longjmp` over a frame stack, using the mask-free
  variants via `ALG_SETJMP`. The `#if` names the platforms that *have* the
  signal-mask behaviour; writing it as `!_WIN32` broke the glibc build under this
  project's own default `CFLAGS`.
- Every collection iterates in insertion order, and re-assigning an existing Map
  key keeps its original position. That is specified by the language, because
  both back ends must print the same thing.

## Testing

Nothing is compared against hand-written expected output. `ALGOL-24.md` is the
specification and the interpreter is the reference implementation, so correctness
is differential: a program runs both ways and the two must agree. A bug affecting both halves equally is invisible to
`compiled` and `programs` — the conformance suites and the fixed point are what
cover that.

| Target | What it does |
|---|---|
| `unit` | `--test compiler/Main.a24` — the compiler's own `test` blocks |
| `conformance` | 8 suites in `tests/conformance/`, interpreted |
| `compiled` | the same 8, emitted and built; reports and exit codes must match |
| `programs` | 30 files in `tests/programs/`, interpreted output vs compiled |
| `fixedpoint` | seed freshness, then g2 vs g3 byte-identical |
| `leaks` | macOS `leaks -atExit` on `tests/leak/` (built `-O0 -g`) |
| `memory` | `/usr/bin/time -l` peak RSS on `tests/mem/` against a budget |

Comparison strips ANSI colour and drops `[ERROR]` lines: an assertion failure
prints a source caret when interpreted, and compiled code has no line
information. What is compared is which tests passed, plus the exit code.

**`leaks` and `memory` are different instruments, not one with two numbers.**
`leaks` asks what was still *reachable* at exit, and the arena frees every chunk
it took — so a program that allocated 1.27 GB it never needed still reported
"0 leaks for 0 total leaked bytes". That is a real bug this repository shipped
(`Map.Remove` rebuilding the hash index into a fresh table each call). Each
`tests/mem/` program carries its own budget in a `/// MAXRSS: <MB>` header, and
the budgets are deliberately loose — they measure a change in complexity, not a
change in machine.

Suites are listed explicitly in `test.sh`'s `SUITES` array; `programs`, `leak`
and `mem` glob their directories. A new conformance suite has to be added to
that array.

`collide.sh` and `depth.sh` are **generating** harnesses and are not part of
`test.sh` at all. Everything in `test.sh` is a pinned case; these two write
programs, varying one along an axis the language allows and asserting an
invariant. They are the only search in the repository, and they run bare —
one compiler and `cc`, nothing set:

```sh
./collide.sh    # 24 mutants: 6 declaration kinds x {root,module} x {public,private}
./depth.sh      # uses-chains of depth 1..8
```

`collide.sh` varies **names**, because per-file emission makes a name the only
way one file's C can conflict with another's. Its oracle is negative — a named
refusal is legal, emitting C that `cc` or `ld` rejects never is — and since
over-refusal would slip past that, a second clause pins the partition as a rule
(refused **iff** host is a module and the name is public) and asserts the
refusal *sentence*, not just the bucket. Keep both in step with the refusal
messages; the wording is load-bearing here as well as in `Unsupported(...)`.

`depth.sh` varies `uses` **depth**, and its reason to exist is a **count**:
`--test` must run one test per module plus the root's. Nothing in `test.sh`
counts tests, so a chunk of them silently ceasing to be collected is invisible
to every other gate — `./test.sh unit` would still report all green. Same
relationship as `leaks` and `memory`.

A failing mutant is not a fixture. These are the search; `tests/` is the pinned
record. Promote a failure into a suite by hand once it has failed, rather than
checking in all 24.

`tests/defects/` is **not** one of these and must not be added to `SUITES`. It
holds reproductions of known defects, written to assert the intended behavior,
so every file in it fails on purpose. Its own `run.sh` inverts the usual
convention and exits non-zero only when a reproduction *passes* — that is the
signal the defect is fixed and the file should move into a real suite. See its
README for what is currently in there.

## Writing Algol-24

Verified against `Scanner.a24`, `TokenType.a24` and `algol.h`:

- Pascal's operators, not C's: `=` is equality, `:=` assignment, `<>`
  inequality. There is no `==`, `!` or `!=`.
- Semicolons **terminate**; the one before `end` is required.
- `Exit` returns, and takes the value. There is no `return`.
- Keywords are case-insensitive (`begin`/`Begin`/`BEGIN`); identifiers are not.
  `?` is a legal identifier character.
- `unit`, `test` and `on` are **context-sensitive identifiers, not keywords** —
  a variable may be called `test`. There is no `finally` in the token set at
  all; the language's nearest thing is an untyped `except` handler.
- A one-character literal is a `Char`, never a `String`, and the two are never
  equal. `S[0]` is a `Char`, `Copy(S, 0, 1)` a `String`.
- Truthiness is not C's: `nil`, `False`, the **Integer** `0`, and an enum member
  of ordinal 0 are falsey. `0.0`, `''` and any `Char` are truthy. The first
  member of an enum being falsey is why `TokenType` values must be *compared*,
  never tested for truth.
- Integer `/` Integer is integer division; a Double on either side promotes.
  `+` concatenates when either side is a String.
- `Length` and `IsEmpty` are properties, written without parentheses.
- `for` is C-shaped (`for var I := 0; I < 10; I := I + 1 do`). `for ... in`
  snapshots the collection first, so mutating it inside the loop is safe.
- String indices are 0-based. `Pos` returns -1 when absent; `Copy` clamps its
  end but not its start.
- `uses` takes a bare name or a quoted path (`uses 'lib/Shapes';`). Every file
  is also a unit named by its file, so `Scanner.ScanTokens()` reaches the same
  export the bare name does. `System` is the built-ins, in scope everywhere and
  imported by nobody — it is the only way back to a name the file has shadowed.
  Qualification reaches exports only, so it is not a way around `private`.

### Style in `compiler/`

`///` doc comments on declarations, explaining *why* rather than what.

That prose is the author's. If a comment looks factually wrong, report it rather
than editing it.

A `⚠️` paragraph marks a hard-won constraint — a reason something is the way it
is, usually written after the alternative failed. There are 315 of them across
47 files: 265 in `compiler/`, 50 in `tests/`, plus more in `bootstrap/algol.c`,
`algol.h` and the shell scripts. `bench/` has none. **Read the `⚠️` above
anything that looks accidental before changing it**; that is what they are for.

Some of that prose is stale, and correcting it is a separate job from the code.
Known cases: references to a sibling Java implementation and to harnesses that
do not live here; `CEmitter.a24` opening by calling itself a "walking skeleton"
covering only literals and simple statements, which the self-hosting build
plainly contradicts; and `algol.c`'s claim that identifier comparison uses
case-insensitive semantics "which is what the interpreter uses", when the
interpreter does no such thing for identifiers (see issue #1). Trust the code
and the tests over the prose, and report a wrong comment rather than quietly
editing it.
