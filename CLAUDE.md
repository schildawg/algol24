# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

Algol-24 is a Pascal-flavoured, gradually typed language that compiles to C. The
compiler is **written in Algol-24 and compiles itself**; `bootstrap/` holds its
own output as checked-in C, so a C compiler is the only prerequisite.

`ALGOL-24.md` is the full language reference (built-ins, collection methods, and
a "Rough Edges" section listing the deliberate gaps). `README.md` is the tour.

## Commands

```sh
./build.sh                      # two-stage build -> ./algc  (~6s)
./build.sh --clean              # from scratch
./build.sh --reseed             # regenerate bootstrap/ after editing compiler/
./compile.sh Prog.a24 --run     # compile a program to native and run it

./test.sh                       # everything
./test.sh unit                  # the compiler's own 219 test blocks (~12s)
./test.sh conformance           # 8 language suites, interpreted
./test.sh compiled              # the same suites compiled -- reports must match
./test.sh programs              # per-program: interpreted output vs compiled
./test.sh fixedpoint            # the compiler reproduces itself byte for byte
./test.sh leaks                 # macOS 'leaks' on compiled programs

./algc Program.a24              # interpret
./algc --test Program.a24       # run its test blocks; raises (exit 70) on failure
./algc --compile --out=DIR F.a24  # emit C into DIR (DIR must already exist)
```

`CC` and `CFLAGS` (default `-std=c11 -O2`) are honoured by all three scripts.

There is no per-test filter. The unit granularity is a file: run
`./algc --test compiler/Parser.a24` to exercise one module's `test` blocks —
but note a module's tests can only reach what that file `uses`, which is why
`compiler/Main.a24` orders its `uses` clauses deliberately (see its comment
above `uses TypeChecker`).

## The bootstrap loop — the thing to get right

1. `bootstrap/*.c` (except `algol.[ch]`) is **generated**. Never hand-edit it.
2. `bootstrap/algol.c` and `bootstrap/algol.h` are the **hand-written C
   runtime**. Edit these here; they are excluded from every seed diff and are
   copied verbatim into each emitted directory.
3. `build.sh` builds the seed with `cc`, uses it to compile `compiler/*.a24`
   into `./algc`, then diffs stage 2's C against `bootstrap/`. A difference
   means the seed is stale — expected right after editing `compiler/`.
4. So the cycle for any compiler change is:
   **edit `compiler/` → `./build.sh` → `./test.sh` → `./build.sh --reseed` →
   commit `compiler/` and `bootstrap/` together.** `./test.sh fixedpoint`
   treats a stale seed as a hard failure.

`fixedpoint` also compiles the compiler with itself twice and requires the two
emissions to be byte-identical. That is a **determinism** check: no hash-order
iteration, no timestamps, no pointer values may reach the emitted text. Code
that is correct can still fail it, and nothing else here would notice.

## Architecture

One front end, two back ends. `compiler/Main.a24` drives all three entry paths
(`Run`, `RunTests`, `Compile`) through the identical prefix:

```
Scanner -> Parser -> Resolver -> TypeChecker -> { Interpreter | CEmitter }
```

The shared prefix is deliberate: a program that fails to parse or type-check
must fail identically whichever back end is asked for, or the two stop
describing one language.

| Module | Role |
|---|---|
| `Scanner` | source → tokens; also fills `SourceCode` |
| `Parser` | tokens → `Stmt`/`Expr` trees; resolves `uses` (looks beside the importing file, then the cwd) |
| `Resolver` | static scope resolution, hands slot depths to the interpreter |
| `TypeChecker` | gradual typing; `Any` is compatible in both directions |
| `Interpreter` | tree-walker — **this defines the language** |
| `CEmitter` | emits C, one translation unit per source file |
| `Obj*` | runtime values: `ObjClass`, `ObjInstance`, `ObjFunction`, `ObjEnum`, `ObjCollection`, `ObjFile` |
| `Environment` | lexical scopes, plus the overload table |
| `SourceCode`, `Console` | singletons: retained source lines for error carets, and formatted/coloured reports |

`Obj*` naming is shared across interpreter, emitter, and the eventual VM on
purpose — all three should say the same word for the same thing.

### Emitted C

- One `.c` + `.h` per **source** file, which is what lets `private` become C's
  `static`. File names are sanitized into C identifiers (`18-frames.a24` →
  `18_frames.c`).
- Name prefixes from `CEmitter`: `v_` variables, `f_` functions, `k_` classes,
  `m_` methods, `e_` enum types.
- Values are tagged `Value`s manipulated through `alg_*` calls in `algol.h`,
  because a gradually typed expression usually has no known C type at emit
  time. Where the type *is* known the emitter may emit the direct form — an
  optimization, not a requirement.
- ~93% of calls go through `alg_invoke`, a run-time lookup by method **name**.
  See `vm/README.md`; `vm/` is an intentionally empty placeholder.

## Testing philosophy

Nothing is compared against hand-written expected output. The interpreter
**is** the specification, so correctness is differential: a program is run both
ways and the two must agree. A bug that affects both halves equally is not
caught by `compiled`/`programs` — the conformance suites and the fixed point
are what cover that. Add cases to `tests/conformance/` (language semantics),
`tests/programs/` (interpreted-vs-compiled differential), or `test` blocks
inside `compiler/*.a24` (compiler internals).

The comparison strips ANSI colour and drops `[ERROR]` lines, because an
assertion failure prints a source caret when interpreted and compiled code has
no line information.

## Writing Algol-24

Beyond the reference, the things that most often bite:

- Semicolons **terminate**; the one before `end` is required.
- `Exit`, not `return`. Arguments are comma-separated and individually typed.
- A one-character literal is a `Char`, never a `String`; the two are never
  equal. `S[0]` is a `Char`, `Copy(S, 0, 1)` a `String`.
- Truthiness: `nil`, `False`, Integer `0`, and ordinal-0 enum members are
  falsey. `0.0`, `''`, and any `Char` are truthy.
- `Length` and `IsEmpty` are properties, not calls.
- `for` is C-shaped (`for var I := 0; I < 10; I := I + 1 do`), not `to`/`downto`.
- `uses` is not transitive — every file declares its own dependencies. Cycles
  are allowed. There is no qualified module access, so name collisions across
  modules are resolved by marking one `private`.
- Top-level functions cannot be overloaded (methods can); `finally` is
  unimplemented and reports itself by name. Both are documented in ALGOL-24.md.
- The compiler needs its own output directory to exist — the language has no
  way to create one, so callers `mkdir -p` first.

### Style in `compiler/`

`///` doc comments on declarations, explaining *why*. A `⚠️` marks a
non-obvious constraint that a future edit would otherwise break — treat those
as load-bearing and preserve them.

## Note

`README.md` says `cd bootstrap && ./build.sh`; there is no `bootstrap/build.sh`
in the tree. Use the top-level `./build.sh`.
