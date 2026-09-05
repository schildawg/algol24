# CLAUDE.md

Guidance for Claude Code (claude.ai/code) working in this repository.

## What this is

Algol-24 (`.a24`) is a **retro-modern** language: classic Pascal syntax over
unbounded integers, full Unicode, gradual types, closures and a foreign function
interface. Its compiler — `algc` — is written in Algol-24 and compiles itself.
There is no JDK, no Maven, no make: a C compiler is the only dependency, because
the only way into the language is a checked-in copy of its own output.

⚠️ **Do not describe it as "Pascal-flavored".** That sells it as a derivative of
an old thing, when the old-looking surface is the deliberate part and the
capability behind it is the point. Pascal may be named as the *syntax's*
lineage, never as the language's identity.

**v0.1.4.** The language has been feature-complete since v0.1.0 and is done.
What it does not have is a library written in Algol-24, which is the whole of
what *alpha* means here; nothing in the language is provisional.

- `spec/ALGOL-24.md` — **the authority.** Every rule is claimed by a case.
  The implementation is measured against it: where the two disagree,
  `spec/DEFECTS.md` names the defect and carries a program that reproduces it,
  and `spec/HISTORY.md` holds the closed divergences and settled questions.
- `compiler/*.a24` — the source. Scanner, Parser, Resolver, TypeChecker,
  tree-walking Interpreter, and the C back end.
- `bootstrap/` — the seed. `algol.c` / `algol.h` are the hand-written C runtime;
  **every other `.c`/`.h` is generated** from `compiler/*.a24` and is marked
  `/* Generated from Algol-24. Do not edit. */`. Edit the `.a24` and re-emit.
- `conformance/`, `refusals/`, `defects/` — the corpus. One question decides
  which directory a case belongs in: *is the interpreter right?*
- `spec/DOCUMENTATION.md` — how `///` doc comments are written here.
- `examples/hello-scripts/` — a pie chart and Unicode text drawn into an SDL2
  window by an Algol-24 program.
- `packaging/` — the Homebrew formula and its CI.
- `vm/` — empty. Reserved for a bytecode VM with a real GC (the runtime's bump
  allocator never frees; see the memory section of `bootstrap/algol.c`).

## Commands

Build the compiler from the seed (needs only a C compiler; ~2 s):

```sh
./bootstrap/build.sh          # -> bootstrap/algc
./bootstrap/build.sh --ffi    # ... able to call C, needs libffi
```

Run, test, and compile (from the repository root, so `uses` resolves):

```sh
bootstrap/algc <file.a24>                       # run a program
bootstrap/algc --test <file.a24>                # run its test blocks
bootstrap/algc --test compiler/Main.a24         # the whole compiler suite
bootstrap/algc --compile --out=DIR <file.a24>   # emit C into DIR (must already exist)
bootstrap/algc --compile --test --out=DIR <f>   # emit the tests plus a runner
```

The emitted directory **is** self-contained: `--compile` copies `algol.c` and
`algol.h` in beside the generated files, so `cc -std=c11 -O2 -o DIR/prog DIR/*.c`
is the whole build. `RuntimeFolder` in `Main.a24` looks in three places — beside
the binary, `bin/../share/algol24` for a package manager, and `bootstrap/`
relative to the working directory — because the language has no way to be told
its own install prefix.

⚠️ **An Integer is unbounded** (`LEX-018`): arithmetic past the machine width
grows rather than raising or wrapping, and demotes again the moment a result
fits. There is no build switch.

⚠️ **There is no per-test filter, and no per-file one either.** `--test X.a24`
runs every test block reachable from `X.a24`, its imports included — the
narrowest thing you can run is a leaf module. `compiler/Token.a24` (2 tests) is a
useful fast loop; `compiler/Main.a24` imports everything.

## The five harnesses

All five must pass. They are the definition of done.

```sh
./test.sh          # the unit tests, inline in the source they cover
./conform.sh       # the corpus, under BOTH processors
./spec/spec.sh     # every rule cites something that exists
./fixedpoint.sh    # the seed matches what the compiler emits, and emits itself
./docs.sh          # every unit is documented per spec/DOCUMENTATION.md
```

Each prints its own totals. **Do not copy those totals into this file or the
README**: every count written down here has gone stale, and a number in prose is
a claim nothing checks.

⚠️ **A compiler gap is a failure, not a report.** Every case in `conformance/`
and `refusals/` must pass under the interpreter *and* the compiled back end.
`conform.sh --lenient` shows work in progress and is not a way to finish
anything.

⚠️ **`./test.sh` takes a file name but not a test name**, and naming a file runs
every test it can *reach*. A file that fails to parse reports nothing at all, so
the script says `no tests ran` rather than passing.

### Checking the fixed point

`./fixedpoint.sh` builds its own compiler from the seed and runs two checks:
**seed in sync** (is `bootstrap/*.c` what the compiler emits today?) and **fixed
point** (does it emit the same C once compiled by itself?).

⚠️ **One reseed is not always enough**, which is why it iterates. Generation 1
holds the new emitter's *source* written by the *old* emitter's rules; only at
generation 2 do the two agree.

### Reseeding after a change to `compiler/*.a24`

`bootstrap/*.c` is a fixed point: the checked-in C is byte-identical to what the
current compiler emits. Any change must be reseeded through the old binary:

```sh
./bootstrap/build.sh                                     # stage 1, from the old seed
mkdir -p /tmp/stage2
bootstrap/algc --compile --out=/tmp/stage2 compiler/Main.a24
cp /tmp/stage2/*.c /tmp/stage2/*.h bootstrap/
./bootstrap/build.sh                                     # stage 2 builds itself
bootstrap/algc --test compiler/Main.a24
```

⚠️ **Copying a generation into `bootstrap/` does not remove what is no longer
generated.** Deleting a unit means deleting its `bootstrap/*.c` and `*.h` by
hand. This bit three times: `System.c` and `Core.c` in Generation 9, and
`AstPrinter.c` when that unit was cut.

⚠️ **A change that makes the compiler refuse its own sources bricks the
bootstrap.** The way out is the seed in git:
`git checkout -- bootstrap/ && ./bootstrap/build.sh`. So check *before* seeding:
build stage 2, emit again with it, and only then trust the change.

## Architecture

One front end, two back ends. `compiler/Main.a24` wires it, and `Run`, `RunTests`
and `Compile` deliberately share the same front end — a program that fails to
parse or type-check must fail identically whichever back end is asked for, or the
two stop describing one language.

```
Scanner → Parser → Resolver → TypeChecker → ┬→ Interpreter  (tree-walking)
                                            └→ CEmitter     (C11 + algol.c runtime)
```

- **Scanner** records errors instead of raising (`HadError` / `LastError`,
  module-level, not per instance). Drivers must ask — `Main.a24`'s
  `CheckScanned` is called *twice*, once after scanning for the right message and
  once after parsing for coverage of modules loaded by `uses`.
- **Parser** is also the module loader. A `uses Foo;` resolves `Foo.a24` beside
  the importing file first, then the working directory, parses it inline, and
  returns a `ModuleStmt`. The `Loaded` map is shared with sub-parsers so a
  diamond loads once; a re-import yields an **empty module node** rather than
  nothing, so the second importer still *sees* it. `Parse` enters its own file in
  `Loaded` before reading its `uses` clauses, which is what lets a module import
  the root back.
- **Resolver** binds variables to scope depth, tracks constants (every name is
  recorded, not just the constant ones, so an inner `var` may shadow an outer
  `const`), and decides whether a dotted name is a unit qualifier or a receiver.
  `System` — the built-ins — is in every file's unit set and is imported by
  nobody.
- **TypeChecker** is gradual: an unknown symbol answers `''`, which is normal
  rather than an error. Every check goes through one helper, `Assignable`.
- **Interpreter** is a tree walker. The built-ins are one class with a case, so
  interpreted `Length` *is* host `Length` and the two cannot disagree. `Obj*.a24`
  are its runtime objects.
- **CEmitter** **refuses by name** what it cannot emit
  (`'<X> is not supported by the C back end yet.'`) rather than emitting nothing.
  Silent gaps would produce a binary that disagrees with the interpreter.

### What the C back end refuses

Coverage is the language as this compiler uses it — it compiles itself, tests
included. What remains refused, by name:

| |
| --- |
| a `var` as an unbraced branch or loop body |
| a nested `uses` |
| two modules named the same |
| `'super'` outside a class |
| a capture of, or a read from, a nested function it cannot reach |
| a literal of a type it has no spelling for |
| a unary or binary operator it does not know |
| a call or assignment through a unit qualifier it cannot resolve |

### Emitted C

One `.c`/`.h` pair per source unit. Names are mangled by kind — `v_` variable,
`f_` function, `fn_` its closure value, `k_` class handle, `e_` enum, `c_` const,
`m_` method — always through `Mangle`/`SymbolOf`, never by hand-concatenating a
prefix. Each unit gets an `init_<Unit>()`, and generated `main` calls them in
dependency order before `init_Main()`.

Names are mangled per `spec/ALGOL-24.md` Annex G.3: every letter and digit
**lowercases**, `?` becomes `Q`, `!` becomes `E`, `_` becomes `V`, and any other
character becomes `U` plus six hexadecimal digits — so `🙂` emits as `U01F642`
and any Unicode identifier compiles.

⚠️ **The lowercasing is what makes the escapes possible.** Identifiers are
case-insensitive (`SRC-011`), so case carries no information and lowering is
lossless, which frees the whole uppercase range to mean "escape". Neither half
works alone, and adopting one without the other is not injective.

⚠️ **`_` is escaped, not passed through**, which is exactly what leaves it free
as a separator. Join composite symbols by escaping each part and putting a raw
separator between them — never escape a string that already contains one.

`algol.h` is the contract between emitter and runtime and is heavily commented —
read it before touching either side. Values are tagged (`Value` with a C11
anonymous union) because the checker is gradual and most expressions have no
known C type at emit time. Method and property access dispatch at run time
through `alg_invoke` / `alg_property`; overloads select on the whole signature,
not arity. Exceptions are `setjmp`/`longjmp` over a frame stack.

⚠️ **A collection literal above a hundred elements is emitted as a helper
function**, not as nested calls, because `cc` gives up at 256 bracket levels.
That only works when every element is itself a literal; a large literal of
*computed* elements is passed into a helper instead.

## Tests

Tests live inline in the source they cover, as `test 'Name'; begin … end` blocks
using `AssertEqual`, `AssertTrue` and `Fail`. `--test` runs them instead of the
program; the main block never executes. Failures exit 70 via `Halt(70)`.

The compiled test runner reproduces the interpreter's report **line for line,
including the `[ERROR]` line naming why each failure failed.**

⚠️ A test failure prints exactly one `[ERROR]` line, not three: `Console.Error`
adds a source line and a caret, and a test failure does not go through it.

⚠️ The file named is the **root**, not the file the failing test lives in,
because `SourceCode` is one global keyed by line number. The compiled runner
copies that deliberately, since the reports are compared.

## Documentation comments

`spec/DOCUMENTATION.md` is the convention and `./docs.sh` enforces it. In short:

- A `///` block documents the declaration beneath it. A **unit** is documented
  above its `unit Name;` header, which must come **before** the `uses` clauses.
- The summary is one sentence, ending in a full stop, wrapping no further than a
  second line, and saying something the signature does not.
- Sections, in order: `# Raises`, `# Safety`, `# Examples`, `# Satisfies`,
  `# Since`. `# Examples` cites a test by name rather than carrying a fragment.
- `# Satisfies` names the rules a declaration implements, sorted, on the lowest
  declaration they apply to.
- **No `⚠️` in a doc comment.** It reads as a hazard needing action, where what
  is being recorded is settled knowledge. State the constraint in the
  paragraph's first sentence instead.
- No author, no date, no version, no change log, no `@param` vocabulary.

⚠️ `docs.sh` treats a file with a `unit` declaration as one that must be fully
documented. That is the scheduling mechanism, and it is also why every unit now
carries a header.

## Working in `.a24`

Style is visible and consistent: `///` doc comments above declarations, `//`
inline. Language points that bite when editing:

- `Exit` returns (`Exit Value;` in a function). Keywords are case-insensitive;
  `unit`, `test` and `on` are context-sensitive identifiers, not keywords.
- Strings are 0-based. `Pos` returns `-1` when absent; `Copy` clamps its end but
  not its start. **No backslash escapes** — `'\n'` is two characters; `#10` is a
  newline, `#27` is ESC.
- A one-character literal is a **Char**, never a String, and the two are never
  equal. `Str(…)` is how you widen.
- `/` is **real division** and always answers a Double, so `7 / 2` is 3.5 and
  `4 / 2` is `2.0`. `div` and `mod` are the Integer pair: both refuse a Double
  rather than truncating it, and both are the only things that raise on a zero
  divisor — `7 / 0` is `Infinity`. There is no `Mod` built-in.
- Truthiness is not Lox's: `nil`, `False`, the Integer `0`, and an enum member
  with ordinal 0 are falsey; `0.0`, `''` and any Char are truthy.
- `?` and `!` are identifier characters (`Gate?` is one word).
- Accumulate text with `Buffer` for anything large. `+` is linear, not
  quadratic — concatenation appends into reserved slack — but a `Buffer` is
  still the right tool, and the emitter's five buffers are the difference
  between 1.25 GB and tens of MB.
- ⚠️ `uses` order in `Main.a24` matters: a module's functions close over the
  environment its file was loaded in, so `TypeChecker` must come after `Parser`
  for its test blocks to reach the parser.
- ⚠️ The `for var X in C do` form has **no slot for a type**. Only the counted
  `for var I : Integer := 0; …` form accepts one.

If you add a token to `compiler/TokenType.a24` and register it in `Scanner.a24`'s
`Keywords`, mirror it into `vscode/syntaxes/algol24.tmLanguage.json` —
`spec/spec.sh` checks that every keyword appears in the editor grammar.

## Known issues

**DEF-34 — `Val` follows `strtod`'s acceptance rather than the language's literal
rules**, so `'0x1F'` answers a Double where a hex literal is an Integer. Any fix
must keep the precision: an Algol-24 rewrite got every acceptance case right and
then read `1.0E300` back as `1.0000000000000002E300`.

**DEF-35 — a type inferred from an initializer is invisible above the
declaration.** A module-level `var` or `const` declared below a body that reads
it has no type there, so a *correct* program is refused with `Expected Integer,
found an untyped expression.` It reaches this compiler's own sources:
`ObjFunction.a24` declares `EXACT` below `Select`, which reads it, so writing
`for var Pass : Integer := EXACT;` makes `algc` refuse the file it was built
from.

⚠️ **Overload selection is at run time and no amount of type annotation changes
that.** [EXP-013] requires it: the type system is gradual, so an argument's
declared type may be `Any` while its value has a definite type. The `[WARN]` a
call raises is decided by whether the *name* is overloaded, never by argument
types — **named arguments** are the only thing that removes it.
