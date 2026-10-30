# CLAUDE.md

Guidance for Claude Code (claude.ai/code) working in this repository.

## What this is

Algol-24 (`.a24`) is a **retro-modern** language: classic Pascal syntax over
unbounded integers, full Unicode, gradual types, closures, extension functions
and a foreign function interface. Its compiler — `algc` — is written in Algol-24
and compiles itself. There is no JDK, no Maven, no make: a C compiler is the
only dependency, because the only way into the language is a checked-in copy of
its own output.

⚠️ **Do not describe it as "Pascal-flavored".** That sells it as a derivative of
an old thing, when the old-looking surface is the deliberate part and the
capability behind it is the point. Pascal may be named as the *syntax's*
lineage, never as the language's identity.

**v0.1.6.** The language is **stable, not closed**: it changes only on measured
demand from a project using it, and the measurement goes in the proposal. That
is the whole policy, and it replaces the sentence this file used to carry about
the language being done — which had to be rewritten at every release that
disproved it.

What the language still does not have is a library written in Algol-24, which is
the whole of what *alpha* means here; nothing in the language is provisional.

Opened twice so far, both times by `algol24-library` as a user:

- **Extension functions** in v0.1.5 [FUN-015]. A top-level subprogram marked
  `extension` may *also* be called with method syntax on its first parameter, so
  `S.Trim ()` and `Trim (S)` are one call.
- **Bitwise operators, a precision for `Str`, and wider `Buffer` accessors** in
  v0.1.6 [EXP-023], [EXP-024], [RT-028], [RT-022].

⚠️ **An extension is permission, not a new kind of declaration.** It is an
ordinary top-level subprogram whose first parameter has a written type, and
every later pass treats it as one: a member of the name always wins at a call
[EXP-022], visibility is the file's own `uses` list and nothing wider
[MOD-015], and `extension` is a context-sensitive identifier rather than a
keyword [LEX-011].

⚠️ **There are three `[WARN]`s**, all in `ERR-010` and all checked against what
`algc` prints by `spec/spec.sh` running `spec/warning.a24` — the lines compared
**in order**. A warning raised and not quoted there fails the run, so adding a
fourth means editing the rule, the fixture and nothing else. Nothing in
`compiler/*.a24` raises any of the three.

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
- `vm/` — the bytecode VM, now started. `OpCode.a24`, `Chunk.a24` and
  `Vm.a24` hold 24 opcodes — constants, locals, globals, comparisons,
  arithmetic, jumps — enough for a `while` loop, at **13.1 M instr/s** over a
  realistic mix. 32 tests, agreeing byte for byte under both processors.
  Numbered as clox numbers them, so the book reads alongside the file. Run them
  with **`./test.sh vm/Vm.a24`**: `test.sh`'s default root is
  `compiler/Main.a24`, which does not import the VM, so **the VM's tests are
  not in the default run.**

  ⚠️ **A global is a SLOT, not a name — this departs from clox deliberately.**
  The Resolver binds every variable before emission, so a module-level one gets
  a fixed index and a subscript instead of clox's hash-per-access. Measured at
  **12.8 M instr/s against a local's 13.1**, so the definite-assignment check
  costs about 3%. Two consequences: an emitter needs a **pre-pass**, because a
  module-level subprogram may refer to a global declared *below* it; and the
  chunk still carries `GlobalNames`, read **only** to say which variable was
  `Undefined` — a declaration is what defines a global, so `var X;` is nil
  while a read from above its declaration raises.

  ⚠️ **`and` and `or` need no opcodes**, and must not get any. They yield an
  *operand* [EXP-010], which is exactly what a jump plus an `OP_POP` produces,
  and `OP_JUMP_IF_FALSE` deliberately does not pop so that the operand is still
  there. Truthiness is free for the same reason the arithmetic is: a guest value
  **is** a host value, so the host's own `not` decides it and the machine cannot
  hold a second opinion.

  ⚠️ **`IP := IP + ReadShort ()` is a bug, and it fails as a plausible wrong
  answer.** The left `IP` is read before `ReadShort` advances it past the two
  operand bytes, so the jump lands two bytes short — on the operand of whatever
  follows. Read the distance into a local first.

  ⚠️ **Assert `SP` after a run, not just the answer.** A backward jump landing
  early still computes the right result when the result is read from a local
  slot, while leaking a value per iteration — that passed 25 tests. A correct
  emitter leaves a balanced stack, and checking it is what catches the class.

  ⚠️ **Two things cost 3x each in a dispatch loop, both found by measuring.**
  A unit's bare STATEMENTS do not run under `--test` -- only a declaration's
  initializer does -- so the handler table is built by `BuildHandlers ()` and
  assigned in the `var`; a table half-built the other way fails as `Can only
  call functions and classes` at the first instruction. And reading the chunk
  through `Running.At (IP)` dispatches by method NAME through the runtime once
  per instruction: 5.2 M instr/s against **16.1 M** for the same loop reading a
  module-level Buffer lifted out of the chunk at `Run`.

  **`vm/run.a24` is a second binary, not a mode of `algc`** — it imports the
  compiler's front end rather than being imported into it, so `compiler/` is
  untouched and the VM stays out of the seed. `compiler/VmEmitter.a24` is the
  third back end, reached from there and **not** from `Main.a24`, which is why
  `fixedpoint.sh` never sees it.

  **`vm/conform.sh` is the third column** — the corpus on the machine, rendered
  exactly as `conform.sh` renders it. Currently **77 identical, 110 refused by
  name, 7 not applicable, 0 diverged** — "not applicable" being a case that
  asks for `--test`, which the machine has no mode for. A refusal is work to do; a divergence is a bug, and
  refusing by name is what keeps the two apart.

  With functions and call frames in, `Fib (27)` runs in **0.79 s on the VM
  against 6.26 s interpreted** — both native binaries, so that 7.9× is bytecode
  against an AST walk.

  ⚠️ **A global slot must mean the same thing in every chunk of one program.**
  A table per chunk let a subprogram resolve its own name to slot 0 of its own
  table where the caller had it in slot 2 of the script's, so recursion read
  the wrong variable and answered 28 where 55 was right. Every global resolves
  against the outermost chunk.

  ⚠️ **Only a name the pre-pass CLAIMED may be emitted as a global.** Resolving
  every unknown name to a fresh slot turned a built-in into `Undefined variable
  'Str'` — a wrong answer where a refusal was wanted. Built-ins, captures and
  overload sets are each refused by name now, which is why the refused count
  went *up* while divergences went to zero.

  ⚠️ **`STACK_ROOM` is derived from `FRAME_ROOM`, as clox derives it.** With the
  two equal, runaway recursion overflowed the *value* stack first and said so —
  true, but about the wrong thing.

  ⚠️ **A built-in is called by NAME, and every arm ends in the host's own.**
  `OP_BUILTIN` carries the name's constant index and an argument count, and
  `DoBuiltin` dispatches on both — because six built-ins are variadic. That
  keeps the interpreter's guarantee for a third processor: `Length` on the
  machine **is** host `Length`, rather than a second one that must agree
  forever.

  ⚠️ **`ParamCount` and `ParamStr` are the exception and cannot be forwarded.**
  The host's answer is about the *process*, which is the driver, not the program
  being run — so the machine keeps its own `Arguments` and the driver calls
  `SetArguments`. The interpreter has the identical split with its own
  `ProgramArguments`, which is the thing to copy rather than rediscover.

  ⚠️ **A collection literal is read off the stack by INDEX, not popped.**
  Popping reverses the elements, and a reversed list literal reads as a parser
  bug rather than as a back-end one.

  ⚠️ **A dynamic member name cannot be reached from Algol-24**, so `is`,
  properties, built-ins and method invocation are each a chain with the name
  written as a literal in every arm — the same shape four times. The emitter
  refuses any name the chain lacks, so a gap is work to do rather than a wrong
  answer. Methods and built-ins key on the **name and the count**, because one
  name means different things at different arities: `Append` with one argument
  is a Buffer's, with none a TextFile's.

  ⚠️ **A member call is an EXPRESSION, even when it reads like a procedure.**
  Treating `Sort`, `Clear` and `Remove` as void and pushing nil was right for
  most and wrong for the ones with something to say — `Remove` answers the
  value removed from a Map and a Boolean from a Set [COL-011]. Every arm pushes
  the call's result.

  ⚠️ **Classes are `VmClass`/`VmInstance`, and a member read is ONE path.**
  Fields, `ClassName`, methods and the runtime's five properties are all
  answered by `MemberOf`, in that order — a class declaring `Length` shadows
  the runtime's property, which is the asymmetry [CLS-007] rests on, and
  `ClassName` answers **ahead of** a field of that name [CLS-008].

  ⚠️ **Widening is an opcode and it has five contexts, not one.** A
  declaration, an assignment, a **parameter**, a **declared return type** and a
  **field** — each is an assignment context [VAL-001], and 0140 names all five.
  Missing any of them is a quietly wrong number rather than a failure. A
  subrange annotation is refused, because its bounds live in the compiler's
  table and a chunk cannot reach them.

  ⚠️ **`Exit` inside a loop leaves the whole subprogram.** An untyped parameter
  stopped every later one from being widened, because the skip was written as
  `Exit` rather than a condition.

  ⚠️ **`Stack` is a built-in**, so the machine's value stack is called `Slots`.
  A module-level `Stack` shadowed it inside the built-in dispatcher and a guest
  program calling `Stack ()` reached the Array instead.

  ⚠️ **"Every opcode has a handler" compares against `DoUnknown`** rather than
  running each opcode. The running version needed a special case per opcode
  whose operand is a constant INDEX — a type name, a built-in name, a property,
  something callable — and each one it lacked failed as a refusal that looked
  like a real finding. It still catches a gap in the numbering, which is what
  it is for.

  ⚠️ **A collection built-in crosses the guest-heap boundary.** `List`, `Map`,
  `Set`, `Array`, `Buffer`, `Stack` and `TextFile` hand back a **host** object
  in an arena that never frees. Deliberate for now and matching the
  interpreter, but it is exactly what the `Buffer` guest heap in
  `PROPOSAL-GC.md` exists to fix.

  ⚠️ **The machine may not import anything from `compiler/`.** `TypeNameOf`
  looked like a built-in and is a function of `compiler/ObjFunction`, so `is`
  is a chain over the five primitive type names using the host's own `is` with
  each written as a literal — the language's answer rather than an imitation.
  It cannot reach a subrange or a class, because `alg_is` takes the type as a
  string the **emitter** wrote, so the emitter refuses every other type name.

  ⚠️ **`uses` takes a PATH when the name is quoted** — `uses 'vm/OpCode';`,
  `uses 'compiler/Parser';`. The corpus has used `uses 'modules/Alpha';`
  throughout from the start. A bare name may not contain `/`.

  ⚠️ **A top-level subprogram shadows another unit's class METHOD of the same
  name, and this cost fifteen renames.** `Vm.a24` declaring `Peek` broke
  `Parser.Peek() : Token`, which `Parser` calls bare ten times — surfacing as
  `Expected Token, found Any` at a line number in the merged source map,
  nowhere near either declaration. Then `BeginScope`, `EndScope` and
  `ResolveLocal` all collided with `Resolver` methods at once.

  **A method is not the protection it looks like, and both processors agree
  about it** — a bare call inside a class finds an imported unit's top-level
  function over the class's own method. So before adding a top-level name to a
  program that imports `compiler/*.a24`, check it against every declaration
  there including the indented ones; `shroom-slots` keeps
  `tools/name-clash.py` for exactly this and it is worth copying.

  ⚠️ **Four Buffer and Char traps, all of which compile and then misbehave.**
  `Str (B)` on a Buffer answers its PRINTED form, so use `B.Text`; `Buffer (N)`
  pre-fills N **zero** bytes and a Buffer holding one has no Text, so use
  `Buffer ()` to accumulate; `Length (B)` answers the printed form's length
  where a List raises (DEF-36), so use `B.Length`; and a one-character operator
  literal is a **Char**, so `Op = '+'` against a String is quietly false while
  `Op = '<>'` works — which refused all the arithmetic while the comparisons
  passed.

  ⚠️ **`ClassNameOf` is a METHOD** on TypeChecker and on Interpreter, not a
  built-in. A third walker needs its own; it is `Node.ClassName` in a `try`.

  ⚠️ **`and` and `or` are a `LogicalExpr`, not a `BinaryExpr`.** They are their
  own node because they short-circuit.

  `vm/spike/` holds the programs that
  measured whether it is worth writing, and **`vm/spike/measure.sh` reproduces
  every figure** in `PROPOSAL-VM.md` in about ten minutes — so run it rather
  than trusting a number quoted in prose. The short of it: an Algol-24 dispatch
  loop compiled to C runs about **12× slower** than the same work compiled
  directly, which is what the proposal weighs. Reserved for a real GC, because
  the runtime's bump allocator never frees — see the memory section of
  `bootstrap/algol.c`.

  ⚠️ **Two findings there are about the emitter, not the VM, and they are not
  conditional on it.** `build.sh` now probes for **`-flto`** and uses it
  (`LTO=0` opts out), because `algol.c` is a separate translation unit and every
  `alg_*` call crosses it. And `BoundValue` elides `alg_widen` only for `''` and
  `Any`, so **annotating a variable currently makes the emitted code slower**,
  which is backwards for a gradually typed language.

  ⚠️ **LTO's size depends entirely on the shape of the work**, and a number
  quoted without its workload is useless: 42% on a tight arithmetic loop, 24% on
  a VM dispatch loop, **3% on `algc --test` and 1% on `algc --compile`**. It
  removes call overhead, so it helps exactly where the callee does little. Do
  not repeat the 42% as though it were general -- `PROPOSAL-VM.md` did, and it
  was wrong.

  ⚠️ **The frame budget is measured now, and the answer is 30 fps.** The Dew
  Drop Inn spends **2.0 ms a frame** in Algol-24 (plus 0.3 ms in SDL), so on the
  VM it needs 18.4 ms — over a 60 fps frame and comfortably inside a 30 fps
  one. The reel engine, at 0.74 ms, fits at 60 either way. **The Inn is the
  program that decides this, not `play`** — and the game is *logic*-bound, not
  SDL-bound: foreign calls are 13% of its frame.

  ⚠️ **A third finding is a decision, not a repair**, and it is the only one
  that helps the VM more than the AOT path: writing just the dispatch loop in
  C, over handlers that stay in Algol-24, measured a further **1.7×** and takes
  the VM to CPython parity. The frame measurement makes it **load-bearing** --
  without it the Inn is at 94% of a 30 fps frame. There is no barrier at the emitted-C level — a
  generated subprogram is already an ordinary C function — so what it would
  need is linkage, and `vm/spike/cdispatch.py` demonstrates it by patching a
  compiled variant. The catch is that giving C a stable name to call **freezes
  the `Value **cells, Value *args, int32_t count` calling convention**, which
  is private today and has changed before.

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
- An **extension** is declared `extension function F (Receiver : T, …)` at the
  top level only, and the receiver's type must be written: an untyped one would
  be a member of everything. It is refused on a method, a constructor, a
  property and a nested subprogram. Both spellings always work, so a plain
  function may gain or lose the word without breaking a call site.
- ⚠️ **`and` is not bitwise and never was.** It tests truthiness and yields an
  *operand* [EXP-010], so `6 and 3` is 3 where `6 & 3` is 2 — the Pascal
  reader's trap, and now a `[WARN]` where an operand's type is Integer. `&`,
  `|`, `^`, `~`, `<<` and `>>` are the bitwise six [EXP-023], over an Integer
  that is two's complement extended infinitely to the left, so `~0` is -1 and
  `1 << 70` grows.
- ⚠️ **`>>` is not `div`.** It floors where `div` truncates toward zero, so
  `-7 >> 1` is -4 and `-7 div 2` is -3 [EXP-024]. They agree whenever the
  shifted-out bits are zero, which is what makes the difference easy to miss.
- `Str (X, Decimals)` renders a Double with exactly that many places and never
  in exponent form, and `Str (X, Width, Decimals)` right-aligns it [RT-028].
  Correctly rounded from the value, so `Str (2.675, 2)` is 2.67; text surgery
  on `Str (X)` cannot get that right and the arithmetic cannot either.

If you add a token to `compiler/TokenType.a24` and register it in `Scanner.a24`'s
`Keywords`, mirror it into `vscode/syntaxes/algol24.tmLanguage.json` —
`spec/spec.sh` checks that every keyword appears in the editor grammar.

⚠️ **A token that is a SYMBOL is not checked**, because that check reads the
keyword table. The six bitwise symbols still went into the grammar, and a new
one should too — for the reader rather than for the harness. Match it *before*
the comparison rule if it starts with `<` or `>`, or `<<` colours as two `<`s.

⚠️ **A new operator cannot be used in `compiler/*.a24` until the seed lexes
it.** The generation that introduces one has to be written without it — the
bitwise operators were implemented in `div`/`mod` arithmetic first and rewritten
to use themselves after the reseed. Expect two commits, and expect
`fixedpoint.sh` to need more than one generation.

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
types — **named arguments** are the only thing that removes it. Both spellings
of an extension call raise it alike, the receiver counting as the argument it
is, because they are one call [FUN-016].
