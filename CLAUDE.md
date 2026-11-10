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

**v0.2.7.** The language is **stable, not closed**: it changes only on measured
demand from a project using it, and the measurement goes in the proposal. That
is the whole policy, and it replaces the sentence this file used to carry about
the language being done — which had to be rewritten at every release that
disproved it.

v0.2.0 is the **bytecode machine** — a third processor, `algvm`, beside the
interpreter and the compiled back end — with a **precise garbage collector**
under both of them. The language itself gained nothing and had five rules
*corrected*, every one of them found by building a third processor rather than
by reading: [CLS-004] (a constructor goes through selection), [CLS-005] (field
initializers are seeded chain-first before any constructor body), [CLS-010]
(`super` is not exempt), [CLS-012] and [VAL-014] (NaN is not ordered, and the
inclusive comparisons are no exception).

v0.2.1 adds the one thing a library needs to BE one: [MOD-002]'s third place,
so `uses graph;` reaches a library a package manager installed rather than only
one beside the program. Found by trying to write the formula that installs it.

⚠️ **[MOD-002] is about the LOOKUP only, and [MOD-018] owns the rest.** A unit
name folds like any other identifier where the language decides anything with
it: two units whose names differ only in case are one name declared twice, and
the program is refused on every platform alike. Only whether `uses alpha;`
*finds* `Alpha.a24` is still the filesystem's.

⚠️ **macOS is the case-INSENSITIVE platform and Linux is the outlier**, which
is the opposite of the natural guess. Writing `unit.a24` beside `Unit.a24` on
APFS overwrites it — one file. So a two-unit case clash cannot even be written
in one directory here, which is why `conformance/modules/casea` and `caseb`
exist. Folding the *lookup* too would need a directory listing the core has not
got — see `PROPOSAL-DIRECTORY-LISTING.md`, and note the library's own
`Directory` is behind three `external`s the seed cannot reach.

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

⚠️ **There are five `[WARN]`s**, all in `ERR-010` and all checked against what
`algc` prints by `spec/spec.sh` — the lines compared **in order**. A warning
raised and not quoted there fails the run, so adding one means editing the
rule, a fixture and nothing else. Nothing in `compiler/*.a24` or `vm/*.a24`
raises any of them, which is checked by compiling both.

⚠️ **TWO FIXTURES, because the fifth is raised while EMITTING C.** An
interpreted run never reaches the C back end, so `spec/warning.a24` cannot
provoke it however it is written — `spec/warning-emitted.a24` is **compiled**
for that one, and `spec.sh` appends its warnings after the first fixture's.
Quote them in that order or the comparison fails on ordering alone.

⚠️ **A warning is the answer where a construct is LEGAL and carries a hidden
cost, and `conform.sh` is built for it.** `render()` drops `[WARN]` from BOTH
sides, because the front end is shared and the two processors raise a warning at
different moments — so a conformance case can exercise a warning but never see
it, and `spec.sh` is the only thing holding the wording. Without that, the
arity warning would have diverged every case with a wrong-count call in it,
`0049` among them.

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

  ⚠️ **Those three directories are GENERATED and git-ignored.** A case lives in
  `spec/ALGOL-24.md`, under the rule it pins, as a `##### conformance/NAME.a24`
  header followed by an ```` ```algol24 ```` block and a ```` ```console ````
  block holding `$ algc conformance/NAME.a24`, the expected output, and
  `exit: N` when it is not 0. `conform.sh` **deletes** `conformance/*.a24`,
  `*.out`, `*.args` and the `refusals/` equivalents and extracts them fresh —
  so a case written straight into the directory is a build artifact that the
  next run removes, and writing one there looked like the files being eaten by
  something. The point is that a case and the rule it demonstrates cannot
  drift: they are the same text.
- `RELEASES.md` — the cumulative release notes, newest first. What changed in
  each version and why, written for someone deciding whether to upgrade and for
  whoever maintains the website. **A release updates this**, and it quotes no
  counts for the reason nothing else here does.
- `finished/` — proposals and plans whose subject has been built. Each carries a
  header saying what it decided, when that landed, and **what remains open**,
  because several still carry live questions. A proposal that was refused or is
  still open stays in the root.
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

  ⚠️ **`<=` and `>=` ARE opcodes, and spelling them as a negation was wrong
  about NaN.** `clox` emits `>=` as `OP_LESS` + `OP_NOT` and saves two numbers
  by it; every ordered comparison with NaN is false, so negating one answers
  **true** and `NaN <= 1.0` came out true where both other processors answer
  false. `OP_LESS_EQUAL` and `OP_GREATER_EQUAL` defer to the host's own
  operators, which is the rule the arithmetic already follows.

  ⚠️ **`<>` keeps its negation and is RIGHT to**, which is what makes the
  other two easy to get wrong by analogy. Equality is defined for NaN
  [VAL-011] — it is not equal to itself — so `OP_EQUAL` + `OP_NOT` answers
  true, which is what `NaN <> NaN` should say. Only the ORDERED pair breaks.

  ⚠️ **264 corpus programs could not catch it, and a library assertion
  could.** `AssertNear` guards itself with
  `not (Difference <= Tolerance)` — exactly the shape the negation inverts —
  so a NaN difference **passed** a test written to catch it, in four of
  `algol24-library`'s units at once. `conformance/0208` is the case now. The
  corpus had no program that compared a NaN at all.

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
  `fixedpoint.sh` never sees it. **`./vm/build.sh` is how it is built**, into
  `vm/algvm`.

  ⚠️ **Foreign calls are NOT a switch on the machine, and `algc`'s switch does
  not generalise to it.** A foreign call is a feature of the language
  [FUN-014], so `vm/build.sh` always passes `-DALG_FFI -lffi` and FAILS if it
  cannot, rather than producing a binary that answers `Foreign calls are not
  available in this build`. `algc` has the switch for a reason that does not
  apply here: the compiler must build from a C compiler and nothing else,
  because the only way into the language is a checked-in copy of its own
  output. The machine is built by someone who already has `algc` and is in no
  bootstrap path, so it carries the dependency.

  ⚠️ **One fixture therefore does not describe the machine, and the script says
  so rather than skipping it.** `conformance/0174`'s recorded output is a build
  WITHOUT libffi saying so at each call — `algc`'s default configuration
  [INI-008] — so `vm/conform.sh` compares that case against an `--ffi`
  interpreter it builds itself, and reports it on a line of its own. The
  fixture names itself: nothing but a no-foreign build prints that message, so
  the rule needs no list to maintain. Currently **259 identical to the fixture,
  1 identical to the FFI interpreter, 0 refused, 0 not applicable, 0
  diverged** — all 260 compared, none skipped.

  **`vm/conform.sh` is the third column** — the corpus on the machine, rendered
  exactly as `conform.sh` renders it, over **both** corpora. Currently **260
  identical, 0 refused by name, 0 not applicable, 0 diverged**: every case the
  corpus records, the machine answers as recorded. A refusal is work to do; a
  divergence is a bug, and refusing by name is what keeps the two apart — so
  the first refusal to reappear is the thing to look at.

  **`vm/REFERENCE.md` is the opcode reference, and `./vm/reference.sh` is what
  keeps it honest.** One uniform entry per opcode in the shape of the 1987 IBM
  Macro Assembler reference — Encoding, Stack, Operation, Satisfies, Raises,
  See also — written toward an assembly-like front end that would make the
  mnemonics user-facing syntax. **All 78 entries exist**, grouped by what an
  instruction is for with an alphabetical index, and `./vm/reference.sh` holds
  every one of them to `OpCode.a24`.

  ⚠️ **What no script can check is whether a sentence is TRUE, and the
  citations are the sharpest case.** The checker confirms a cited rule exists,
  not that it says what the entry claims — and five citations of `[EXP-020]`
  (operator overloading) were meant to be `[EXP-017]` (assignment is an
  expression), having been copied into four files before anything noticed. Read
  a citation in a comment as a pointer to check, never as a checked fact.

  ⚠️ **`OP_GET_MEMBER` and `OP_GET_FIELD` share ONE handler, and keeping both
  is a decision rather than a leftover.** They are one operation — a name from
  the constants, a value popped, whatever the shared `MemberOf` answers — and
  the difference is a CLASSIFICATION the emitter made: `OP_GET_FIELD` where it
  KNOWS the receiver's class (a field of `this`, or of a declared type) and
  `OP_GET_MEMBER` where the receiver is an arbitrary expression.

  That split is exactly the split between the member reads whose slot could be
  computed at emit time and the ones that cannot. A field read is **one Map
  lookup by folded name** where the field holds anything but nil and two where
  it holds nil, which is still the shape already optimised away for globals —
  a hash per access became a fixed index and a subscript, 12.8 against 13.1 M
  instr/s. A slot-indexed field read lands on `OP_GET_FIELD`, and collapsing
  the two would throw away the classification it needs.

  ⚠️ **The SECOND lookup is what tells a nil field from a name the class has
  not got, and dropping it raises on a perfectly good field.** `Map.Get`
  answers nil for a missing key and for a field seeded nil alike, so only a nil
  answer needs `Contains` — and `VmInstance` seeds every field of the chain
  present [CLS-006], which is what makes that question answerable at all.
  Removing the guard was seen to make `H.Empty` raise
  `Undefined property 'Empty'.`

  ⚠️ **`FindMethodFolded` and `HasPropertyFolded` exist because MemberOf folds
  ONCE and asks three questions.** Each call through the folding version would
  fold again — a string allocation per question, on the hottest path the
  machine has. The folding pair delegate to them, so the chain walk lives once.
  Worth **1.3–1.6% on the Inn** and nothing on `Fib`, which reads no fields;
  measured interleaved under the software renderer, because the effect is
  smaller than a real display's run-to-run variance.

  ⚠️ **It was `OP_PROPERTY`, and the name was wrong twice over.** It said the
  runtime's five properties and meant every member; and it sat one near-
  identical name from `OP_DECLARE_PROPERTY`, a pair that cost an afternoon when
  an emitter edit silently did not apply and emitted a valid opcode doing the
  wrong thing. An opcode's NUMBER is not interface but its MNEMONIC is, the
  more so with an assembly front end intended — so a misleading one is worth
  renaming while it is still cheap.

  ⚠️ **Four opcode doc comments had gone stale, and writing an entry from each
  is what found them.** `OP_CONSTANT` still said a chunk holds 256 constants
  and that a wider form would come "when a program needs it" — `OP_LONG` has
  existed for several increments; `OP_LIST` still quoted its 255-element cap;
  `OP_CLOSURE` still described its captures as bare slot numbers rather than
  flag-and-short descriptors; and `OP_RETURN` said it "stops the machine",
  which is only its floor-frame case. A fifth was a stray line: `OP_COUNT`'s
  one-line doc had been left stranded above `OP_CALL_NAMED` when that opcode
  was inserted below it.

  ⚠️ **The checker reads ONE row per entry, and that is the whole design.** The
  first bracketed row in an entry's fence carries the opcode's number, its
  operand letters and its byte count, all three compared against `OpCode.a24`
  and `OpShape`. Reading the letters from the whole row instead took the `b`
  and the `s` out of the words `5 bytes` and called every multi-operand opcode
  wrong.

  ⚠️ **It caught a stale number in its first run, in three files at once.**
  `OP_LONG`'s rationale said nineteen opcodes carry a constant index where
  twenty-four do, and the figure had been copied from `OpCode.a24` into
  `CLAUDE.md` and into the draft. No count belongs in that sentence; the
  argument for a prefix is that the number grows.

  ⚠️ **A section header is matched as a HEADER, not as a word that appears.** A
  loose substring match passed an entry whose `**Stack**` header had been
  mangled into prose, because the mangled line still contained the word — the
  one check of ten that did not go red when broken.

  ⚠️ **An opcode `OpShape` cannot describe must SAY so, and a name that is
  deliberately not an opcode must say that too.** `OP_CLOSURE` is variable-width
  and declares it in its fence, which exempts it from the shape comparison and
  lists it in the report rather than hiding it — dropping the marker is caught,
  and so is claiming it for an opcode whose shape is known. `OP_WIDE` is named
  in prose as a name that does not exist, and carries
  `<!-- reference.sh: not-an-opcode OP_WIDE -->` beside the sentence that needs
  it, so the exemption sits with its reason.

  ⚠️ **An opcode's NUMBER is not interface; its mnemonic is.** A script
  renumbers every opcode from its declaration order, so nothing may hard-code
  37 for `OP_LIST` — which the reference says outright, because an assembly
  front end would otherwise invite exactly that.

  ⚠️ **The STACK section is now THREE terms and two of them are measured.**
  `OpStack` declares `pops pushes needs` for every opcode, `vm/reference.sh`
  holds each entry to it, and `vm/Vm.a24` holds the declaration to a RUN — so
  an entry is two steps from something that executes. `pushes - pops` is what a
  run reveals; `needs` is what running one value shallower reveals, since `Pop`
  raises `The value stack underflowed.` and a peeking handler faults on a
  negative index instead.

  ⚠️ **`needs` exists because the two-term version was WRONG, and the probe
  that found it is the lesson.** Declaring `OP_DUP` as `1 2` instead of `0 1`
  passed both checks: the net is the same and it does fail at depth 0. So pops
  and "the depth required" are different questions — an instruction may READ
  the top without taking it, which is every assignment opcode [EXP-017] as well
  as `OP_DUP`.

  ⚠️ **All but ELEVEN opcodes are held to their declaration by a RUN, and the
  eleven are NAMED.** The gap is a declared `Unmeasurable` set compared
  against `OP_COUNT`, so an opcode added with neither a measurement nor a
  reason fails — and a name declared unmeasurable that IS measured fails too,
  since a stale exemption quietly shrinks what the test checks. Both
  directions were seen to go red before being trusted.

  The eleven, with their reasons: `OP_LOOP` and `OP_RETURN` do not come back;
  `OP_LONG` is a prefix, so measuring it measures what follows; `OP_RAISE`
  unwinds, so the SP afterwards is the handler's; `OP_THIS` reads below a base
  the floor frame has not got; and `OP_SET_FIELD`, `OP_GET_CELL`,
  `OP_SET_CELL`, `OP_INVOKE_NAMED`, `OP_INVOKE_EXT_NAMED` and `OP_SUPER` want a
  guest instance or a closure's cells — context the harness declines to build,
  because building it would make the measurement depend on the very opcodes it
  is measuring.

  ⚠️ **What made the other 36 reachable was PRIMING the stack with bytes, not
  a depth.** Most of them want something other than a number beneath them — a
  class, a collection, a cell, a defined global — so `MeasuredAfter` takes raw
  prime bytes and the caller says how deep they leave it. Every prime is
  two-byte pushes, which is what lets the depth probe drop the last one by
  dropping two bytes.

  ⚠️ **Three traps in the primes, each a real asymmetry rather than a slip.**
  The collection is the RIGHT operand of `in`, so it goes on top; `Length` the
  BUILT-IN takes text and answers
  `Length expects text; use .Length for a collection.`, where the property of
  that name answers a collection; and a one-element list has no index 1, which
  the Integer filler is.

  ⚠️ **`OP_PRINT` is measurable only because a test run SWALLOWS it.** `DoPrint`
  returns early under `TESTING`, which is what 0103 needs so a test body's
  output does not interleave with the report — and it is what lets the
  harness measure a printing instruction at all.

  ⚠️ **The SPLIT between pops and pushes is unobservable, and that is settled
  rather than assumed.** Popping a value and pushing two copies moves the stack
  exactly as reading it and pushing one does — checked with distinct sentinels,
  which showed slot 0 holding the same value either way. So the split says what
  the handler is written to mean and nothing can hold it to that; the
  difference and the depth are what the tests assert. `1 2 1` for `OP_DUP`
  still passes, and the doc comment says so.

  ⚠️ **Three traps in one small test, all of them in CLAUDE.md already.**
  `Set` takes a COLLECTION and not members, so `Set (A, B, C)` is
  `Expected 0 or 1 arguments but got 3.`; a one-character literal is a **Char**,
  which through v0.2.5 never equalled the String `Copy` answers, so a set of
  bare `'0'` matched nothing — **no longer so** [VAL-010]; and a second
  top-level `StackTerm` in `Vm.a24` clashed with the one
  in `OpCode.a24`, which is why both helpers live beside `OpStack`.

  ⚠️ **There is no `Split` built-in**, so `StackPart` cuts the terms out with
  `Pos` and `Copy` — and `Pos (Text, Part)` takes the text first.

  `Fib (27)` runs in **0.91 s on the VM against 6.24 s interpreted** — both
  native binaries, so that 6.9× is bytecode against an AST walk. It was 0.79 s
  before exceptions: the `try` around the dispatch loop costs about 15%.

  ⚠️ **FFI cost almost nothing, because the dynamic entry point is a
  BUILT-IN.** `Foreign` is one of [RT-001]'s thirty always-available names, so
  an `external` call needs no libffi of its own and no opcode: `VmFunction`
  carries Symbol, Library, Types and Returns, and `CallValue` hands those to
  the host's `Foreign` instead of entering a frame. That is the interpreter's
  own single line for it, so the machine's foreign call **is** the host's —
  including the message a build without libffi gives.

  ⚠️ **An external never reaches `EnterFrame`, so it checks its own count.**
  It has no bytecode to enter, and skipping the check let a wrong-arity call
  through to the foreign boundary.

  ⚠️ **`is Pointer` was a missing literal, not a missing feature.** The host
  answers `5 is Pointer` as false in every build, so the only thing wrong was
  that `pointer` was absent from `TESTABLE_TYPES` and from `TypeMatches`'s
  chain. A Pointer is only a *value* under `--ffi` [TYP-017]; the *test* is
  answerable always.

  ⚠️ **libffi IS here, and the note that said otherwise was wrong about both
  halves.** macOS ships it in the SDK: `-lffi` links against
  `MacOSX.sdk/usr/lib/libffi.tbd`, and the header is at
  `$(xcrun --show-sdk-path)/usr/include/ffi/ffi.h` — one directory down, which
  is why a bare `#include <ffi.h>` fails and `algol.c` writes
  `#include <ffi/ffi.h>` on Apple. `./bootstrap/build.sh --ffi` works as it
  stands. The claim had stood unchecked beside a note describing which cases an
  `--ffi` build fails, which cannot both be true; two minutes of `cc` settled
  it.

  ⚠️ **The machine's foreign path is VERIFIED, SDL included.** `algvm` built
  `--ffi` answers 0174 byte-identically to the interpreter, and a probe making
  real calls into `/opt/homebrew/lib/libSDL2.dylib` — `SDL_Init`,
  `SDL_CreateWindow` answering a Pointer, `SDL_GetNumVideoDisplays`,
  `SDL_DestroyWindow`, `SDL_Quit` — agrees line for line under
  `SDL_VIDEODRIVER=dummy`.

  ⚠️ **`in` takes a LITERAL, so a library path cannot be hoisted into a
  `const`.** `external 'SDL_Init' in SDL` is `Expect a library name after
  'in'`, which is why `hello.a24` repeats the dylib path at every declaration.

  ⚠️ **`'libm'` cannot be opened on macOS**, because libm is part of
  libSystem rather than a dylib of its own. 0174 expects that failure, so the
  case passes; a program wanting `pow` needs no library name at all.

  ⚠️ **A bare name inside a method is a VARIABLE first and a member of `this`
  second — except that a BUILT-IN comes last.** The full order is **[CLS-019]**,
  pinned by `conformance/0213`: a local, a capture, a **visible global**, a
  **field of the receiver**, then a built-in. A declared variable beats a field;
  a built-in loses to one, because a built-in is the only name in that list
  nobody wrote down in this program.

  The interpreter looks the variable up and reaches for `this` when that
  *raises* (`ThisField`) — and, since this was fixed, **also when it succeeds
  with a `Native`**, which is the step the built-ins used to jump: they live in
  the environment every file encloses, so the lookup never failed and a class
  with a field named `Pos` answered `<fn Pos>` from inside its own method. If
  the field is missing too it re-raises the ORIGINAL undefined-variable message.
  The emitter decides it statically instead: not a local, not a capture, not a
  visible global, and a member of the class being compiled. `VisibleSlot` exists
  as a question separate from `BareSlot`'s answer because a field WRITE must put
  the receiver on the stack before the value, so it cannot be decided after the
  value is already there.

  ⚠️ **The built-in tiebreak must ask for a FIELD, not a member, and going
  through `Get` introduced a divergence.** `ObjInstance.Get` answers `ClassName`
  and a bound method as well, so routing it there made a bare name answer a
  *method* of that name — `99` interpreted where the machine answers the
  built-in's arity complaint. `GetField` is the narrow accessor and [CLS-007] is
  why: a bare name read without parentheses is a **field** read, so a method of
  the name is reached by `this.M` or by a call and never bare. A bare *call* is
  a different question entirely — [MOD-017].

  ⚠️ **`CEmitter` had the mirror-image bug and nobody had reported it.** It
  tested only for a LOCAL before answering a field, so a **visible global**
  named after a field read as the field inside the class's own methods — the one
  answer of the three that the C back end gave alone, for an imported global as
  well as its own. `VisibleGlobal` guards the write as well as the read: a write
  that disagreed with the read would be worse than either.

  ⚠️ **Methods matter more than fields here.** Of shroom-slots' 28 units, the
  field half unblocked 2 and the bare *method* call unblocked **18** — the
  library writes `while not AtEnd () do` inside a class constantly. Both are
  the same implicit `this`; only the opcode differs (`OP_GET_FIELD` against
  `OP_INVOKE`).

  ⚠️ **A nested subprogram has its OWN frame, so `this` is not one below its
  base — it is a CAPTURE.** A method whose body declares a nested subprogram
  boxes the receiver as a local named `this`, which is the whole of what makes
  it reachable: a capture is found by NAME among the enclosing locals, so
  `this` has to be one of them. `EmitReceiver` then emits `OP_THIS` in a method
  and `OP_GET_CELL` in a subprogram nested inside one, and `MemberOfReceiver`
  asks the two together — a field read, a field write, a bare method call and
  an explicit `this` all go through that one pair. This is what `CEmitter`
  already did for the same problem, and 0148 is the case.

  ⚠️ **A nested subprogram's C SYMBOL was its bare name**, so two of one name
  in different parents emitted one function and the file did not compile:
  `error: redefinition of 'f_shared'`. `FunctionSymbol` qualifies a nested one
  by its parent's **symbol** rather than its parent's name, because a name is
  not unique — two overloads of one name each carry their signature, and a
  nested subprogram inside each would collide again.

  ⚠️ **The qualifier's ORDER is the whole of getting it right.** `NestedIn`
  must be this subprogram's symbol while its BODY is emitted and restored
  BEFORE its own prototype: left set, `FunctionSymbol` qualifies it by itself
  and the definition stops matching the closure that binds it. Set it before
  reading it and every nested subprogram is qualified by its own name instead.

  ⚠️ **A nested `external` binds a LOCAL, like any other nested subprogram.**
  `EmitForeign` declared a global handle whatever the nesting, so the enclosing
  body looked for a local of the name, found none, and the generated C called
  `alg_error("Undefined variable 'Len'.")`. Its symbol needs no qualifying
  there: `EmitForeign` is reached before `VisitFunctionStmt` touches
  `NestedIn`, so it still sees the enclosing subprogram's qualifier.

  ⚠️ **A NESTED `external` is still an external, and the machine answered
  NIL.** `CallValue` asked `Callee is VmFunction`, where a subprogram declared
  inside another is a `VmClosure` **wrapping** one — so the foreign path was
  skipped, the machine entered a body an external has not got, and the call
  answered nil. Not an error: a wrong answer, which is the worst shape a
  foreign call can fail in. Unwrap the closure before asking.

  ⚠️ **A HANDLER's variable is a local, so a boxing frame must BOX it.**
  `EmitHandlerArm` claimed the slot the raised value already occupies without
  the `OP_CELL` every other local-declaring site emits — so in a frame that
  declares a nested subprogram the handler's own first read answered
  `Undefined property 'Held'`, naming `VmCell`'s field at a program that has no
  such name. **Any `try` in such a frame was broken**, and the corpus of the day
  reach none of them. `conformance/0209` is the case.

  ⚠️ **`DeclaresNested` walked the handler ARM rather than its BODY**, which
  made the walk it already had useless. An arm is not a statement — it carries
  a `Name` and a `Body` — so no kind matched and it answered False for every
  handler there is; a nested subprogram declared inside an arm then sat in an
  unboxed frame and capturing the handler's variable reported
  `Undefined variable 'e'`. The existing note below says a missing statement
  kind is a wrong answer; so is a present one handed the wrong node.

  ⚠️ **`DeclaresNested` missing a statement kind is a WRONG ANSWER, not a
  refusal.** It decides whether a body boxes its locals, and it did not walk a
  `try` — so a nested subprogram inside one captured locals nobody had boxed,
  read whatever was in the slot, and a program that raises nothing took its
  handler. A counted `for` is a `WhileStmt` with an `Increment`, which is why
  that one was covered by accident. `LabelStmt` wraps what it labels, so
  missing it would miss everything under a label.

  ⚠️ **A PARENT's field initializers have to run too.** An instance already
  has every inherited field *present*, because `VmInstance` walks the chain for
  the names — what was missing was the value, so an inherited field read as
  nil. Parent first, so a subclass's initializer still wins by running after.
  Invisible until implicit `this` made the bare read reachable.

  ⚠️ **A refusal is only ever first in line.** Of the 7 corpus cases blocked on
  `A reference to 'X'`, implicit `this` fixed **2**; the other 5 wanted
  properties, `Elements` [TYP-011], `Compare` [VAL-014] and operator
  overloading — each of which is now implemented, and each of which was its own
  increment. Measure what a refusal is actually hiding before sizing the work
  behind it: one refusal's wording covered four unrelated features.

  ⚠️ **Refuse the PROTOCOL, not the shape.** Refusing iteration for every
  instance broke 0032, where an instance with no `Elements` must raise
  `Can only iterate a collection or a String.` — a fault in the program, not a
  gap in the machine. The refusal is conditional on the class declaring the
  protocol.

  ⚠️ **A limit must be phrased as a REFUSAL or `vm/conform.sh` calls it a
  divergence.** `EmitConstant`'s 256-constant cap raised a plain error, so a
  program the machine simply cannot hold looked like a wrong answer. The script
  sorts the two by the words `is not supported by the bytecode back end yet`.

  ⚠️ **ALL 28 shroom-slots units now compile and run**, and `verify.a24` — the
  phase-one gate that recomputes the slot math against the Unity export's
  recorded figures — answers **59 lines byte-identical to the interpreter** at
  **6.7×** its speed (11.97 s against 80.68 s). That matches `Fib`'s 6.9×, so
  the microbenchmark was not flattering the machine.

  ⚠️ **A method table holds a LIST per name, and nothing gathers it.** Two
  methods of a name are an overload set [FUN-013]; emitting `OP_METHOD` for
  each is what builds it, because `AddMethod` appends. The emitter needed only
  to stop refusing.

  ⚠️ **Each selection pass runs the WHOLE inheritance chain before the next
  begins** [EXP-014]. An exact match on a parent must beat a widened match on
  the child, or adding an overload to a subclass silently captures calls the
  parent was answering exactly — so it is pass-major over the chain, never
  class-major. And a failed match must **fall through** to the superclass
  rather than return, or a class declaring `Take (String)` hides an inherited
  `Take (Integer)` entirely. `ObjClass.Fitting` records having made that
  mistake; this mirrors the fix rather than rediscovering it.

  ⚠️ **The member tables must be keyed `unit:class`, and bare keying cost an
  afternoon.** shroom-slots declares a `Reel` in `walk` and another in `reels`,
  so one bare-keyed `CLASS_FIELDS` entry kept whichever was surveyed last and a
  field of the other read as an undefined name. The symptom appeared only when
  compiling `inn.a24`, which reaches both — every unit alone was fine, and so
  was every import of `inn` alone. **What found it was instrumenting the
  refusal** to print the unit and class; what hid it for twenty minutes was
  `grep` being case-sensitive where the language is not, so searching `Shown`
  missed nothing and searching the right file never happened.

  ⚠️ **A CONSTRUCTOR is held to its declared parameter types, and all three
  processors used to agree that it was not.** [CLS-004] said construction
  *checks its arity*, where a constructor is a member and a method overloads on
  the whole signature [FUN-013] — so the narrow sentence was an incomplete rule
  rather than a different one. The leniency was one thing in each processor: the
  interpreter fell through to `FindMethod` after `FindOverload` declined, the
  compiled back end passed `strict = false` at `algol.c`'s one `find_method`
  call for `Init` where an invoke and a `super` call pass `true`, and the
  machine carried an `ENTERING_INIT` flag put there deliberately to match the
  other two. Three identical wrong answers are no divergence, which is why
  nothing caught it — not the corpus, not the differential habit.
  `conformance/0204` is the case now.

  ⚠️ **An unchecked parameter is where a WRONG ANNOTATION lives, and the
  compiler's own source had one.** `compiler/Expr.a24` declared
  `LiteralExpr.Value : Expr` for a field holding a literal's *value* — an
  Integer, a String, a Boolean — and a gradually typed language has no other
  place a written type is inert enough to hide that. Fix the mis-declaration
  **before** making the check strict, or the change bricks the bootstrap.

  ⚠️ **A SYNTHESIZED arity-0 constructor HID the inherited one, and that one
  decision was three bugs.** The emitter gives a class with no constructor an
  `Init` that runs the field initializers — so a subclass declaring none got an
  arity-0 `Init` of its own, which (1) made `K ('s')` where the parent takes an
  Integer answer `Expected 0 arguments but got 1.` instead of naming the
  selection failure, because selection walked the chain and the fallback did
  not, and (2) meant the subclass's OWN field initializers never ran when the
  inherited constructor did — `K` with a field of its own read **nil** where
  both other processors read its initializer. The third was `super.Init`
  entering the parent's `Init`, which re-ran the parent chain's initializers:
  twice per instance, against [CLS-005].

  ⚠️ **The fix is a second entry point, `CTOR_BODY`, and the reason is
  ordering.** A constructor's body is emitted twice — as `Init`, with the field
  prologue ahead of it, and as `'ctor body'`, a method name holding a **space**
  that no program can write. A subclass declaring no constructor then gets one
  forwarding `Init` **per inherited signature**: its own chain's initializers,
  parent-first, then an `OP_INVOKE` of `'ctor body'`. Nothing else keeps the
  order the language needs — every field in the chain seeded before any
  constructor body — which is what lets a parent's constructor call an
  overridden method or read a subclass's field. `super.Init` reaches
  `'ctor body'` for the same reason.

  ⚠️ **`super` ACROSS A `uses` recursed until the stack overflowed, and the
  fix is to resolve the parent the way a bare name is resolved.** The super
  site asked `Script.QualifiedSlot (unit, Bare)`, which **allocates** when the
  key is absent — and a class in another unit is keyed `unit:name`, so a root
  file's `:b` matched nothing, a fresh and forever undefined global was
  claimed, and `super.Tag ()` called itself. `EmitInheritance` had always used
  `BareSlot` for the same name, which is why `class D (B)` worked while
  `super.M ()` inside it did not. `ClassSlotFrom` is the non-emitting version
  of the question, and a parent it cannot resolve is now refused by name.
  Pre-existing, and invisible to 262 corpus cases: the corpus has inheritance
  cases and module cases and had none of their **product** — the same gap that
  hid five bugs earlier in this work. `conformance/0206` is the case.

  ⚠️ **A MISSING MEMBER ON A SUPERCLASS answers `Undefined property 'X'.`,
  and the question was never about `Init`.** `super.Init` where the parent
  declares no constructor said three different things in three processors — and
  so did `super.Anything` the parent does not declare, which is what the
  divergence actually was. [CLS-010] is unqualified, so the rule had the answer
  all along: a name the parent chain does not declare is a member the class
  does not have. Each processor was wrong its own way, and none was a majority
  to defer to: `Only instances have properties.` interpreted (true of nothing —
  the receiver IS an instance and the fault is the name), `Undefined method on
  the superclass.` compiled (naming neither member nor class), and on the
  machine a **fabricated `<fn M>`** for a read plus a selection failure for a
  call. `conformance/0207` is the case.

  ⚠️ **The machine checks that in `DoSuper`, not at the call, because
  `super.M` is a VALUE** [FUN-011]. Binding one for a member nothing declares
  answered `<fn Missing>` — a wrong answer rather than a wrong message — and
  deferring the check to the call would have left that read intact.

  ⚠️ **`CTOR_BODY` moved to `vm/OpCode.a24` for the message's sake.** It is
  emitter-to-machine contract like an opcode's number, and the machine needs
  the name in order NOT to print it: `super.Init` reaches that entry, so the
  fault reported straight from the constant read `Undefined property
  'ctor body'.` for a parent that merely declares no constructor.
  `ReportedMember` answers the name a program could have written.

  ⚠️ **A VARIADIC constructor was the one subprogram in the language that did
  not gather**, in the interpreter and the compiled back end both. The same
  signature on a method and on a top-level function absorbed. Three separate
  places had to learn that a class absorbs too: `ObjClass.Absorbs` and
  `ObjClass.Variadic` (a class is not an `ObjFunction`, and the interpreter
  counts arguments before `ObjFunction.Call` ever reaches its `Absorb`), and
  `should_absorb` at `algol.c`'s construction site. A variadic mismatch is a
  **selection** failure and not a count [FUN-005, 0158] — the element type
  replaces the arity check and is stricter than it — so the split a plain call
  makes is mirrored rather than reinvented.

  ⚠️ **An `Exit` inside a CONSTRUCTOR answers the instance, not its own
  value.** `ObjFunction.Call` answers `this` on the Return path *and* on
  falling off the end, so both other processors do it and it is the language
  rather than one of them — though [CLS-004] does not say so. Emitting the
  value instead made `Atlas (S, Folder)` answer nil the moment its early
  `Exit` was taken, and the failure surfaced two calls later as
  `Undefined property 'Ready'` on a nil receiver. The value is still evaluated
  and dropped, because the interpreter evaluates it into the `Return` it raises.

  ⚠️ **The VM and the interpreter now produce IDENTICAL output on the Dew Drop
  Inn**, modulo the randomly-chosen barmaid — 32 lines, both stopping in the
  same place for the same reason.

  ⚠️ **That place is a bug in shroom-slots, not in the machine.**
  `inn.a24:422` declares `var PX := Edge;` and `chrome.a24:37` declares
  `function Px (N, Wide)`. Identifiers fold [SRC-011], so `PX` **is** `Px`, and
  `Px (14, Wide)` at `inn.a24:446` calls an Integer. Both processors say so.
  Renaming the local is the fix; it is used at 463 and 466 only.

  ⚠️ **`Can only call functions and classes.` is the wording**, and the
  machine had invented `Can only call a subprogram.` `conformance/0070`
  compares the real one but is refused for `ObjectStmt`, so the difference was
  latent until the Inn raised it and the two processors printed different text
  for one fault. A message no case reaches is still a divergence.

  ⚠️ **A LOCAL slot widens by the same prefix, and `OpShape` now has `l` for
  it.** Third instance of the one-byte operand, after globals and constants.
  The invariant that makes one flag sound is **at most one widenable operand
  per opcode**, and there is a test for it — `OP_CLOSURE` is the one that could
  break it, carrying an index *and* a slot per capture, so its capture slots
  stay narrow and a closure inside a subprogram of more than 256 locals is
  refused by name instead.

  ⚠️ **`NameOfType` answering 'Any' for a type it does not know is a silent
  selection failure.** `Pointer` was missing, so every Pointer reported `Any`,
  satisfied no declared type, and `Screen.DrawOnto (Tex : Pointer)` failed to
  select — reported as `No matching signature for function.`, which names the
  call and not the cause. The same omission had already cost `is Pointer`. A
  type missing from that chain cannot be refused, only mis-answered.

  ⚠️ **`bootstrap/algc` built `--ffi` FAILS two conformance cases**, and
  rightly: 0174 and DEF-37 record what a build *without* libffi says. Rebuild
  plainly before trusting `conform.sh` — two failures appeared that way and
  were the build, not the code. `vm/conform.sh` builds its own `--ffi` algc in
  its work directory for exactly this reason, so running it leaves no trap.

  ⚠️ **Rebuilding `bootstrap/algc` while a comparison is RUNNING invalidates
  it.** A harness that shells out to `algc` picks up whichever binary is on
  disk at the moment it spawns, so a rebuild part way through means the first
  half of a run and the second half used different compilers — and the failures
  that appear look like findings. Copy the binary somewhere stable and point the
  run at the copy.

  ⚠️ **A constant index widens by a PREFIX, not by a long form per opcode.**
  Most opcodes carry an index into the constants, so a long form each would be
  that many numbers, names, handlers and chances to miss one. **No count
  belongs in that sentence** — it said nineteen in three files while the figure
  had grown to twenty-four, which is the whole argument for the prefix making
  itself felt.
  `OP_LONG` precedes an instruction and widens its index — the JVM's `wide`,
  and it covers an opcode added later for free. Measured free on the narrow
  path: Fib (27) interleaved against the prior commit reads 0.98–0.99 s both
  ways.

  ⚠️ **It is `OP_LONG`, not `OP_WIDE`, because `OP_WIDEN` already exists** and
  widens a *value* to a declared type. Two opcodes a letter apart meaning
  unrelated things is a misreading waiting to happen — and it happened to me
  inside ten minutes, grepping a disassembly for the prefix and matching the
  other one.

  ⚠️ **The machine clears the wide flag on the first index READ; the
  disassembler cannot.** `ReadIndex` consults a flag, so it does not care where
  in the operands the index sits — which matters because `OP_BUILTIN` carries
  it first and `OP_OVERLOADS` carries it second. A disassembler has to know
  *which* operand it is, so `OpShape` tells `i` from `b`: an index from a mere
  byte. Widening "the first operand" would have rendered `OP_OVERLOADS`
  wrongly and put every later offset out.

  ⚠️ **Two prefixed instructions in a row is the case that catches a stale
  flag.** Clearing at the end of the instruction instead of at the read leaves
  the second one reading a byte where a short was written, and everything after
  it drifts. There is a test for exactly that pair.

  ⚠️ **A global slot is a SHORT where it has to be, and the cap was never the
  interesting part.** One byte addresses 256 globals; shroom-slots and its
  library declare about **1,700** names between them, so `OP_GET_GLOBAL_LONG`,
  `OP_DEFINE_GLOBAL_LONG` and `OP_SET_GLOBAL_LONG` take a short and the emitter
  picks the narrow form when the slot fits. That is `clox`'s split for its
  constants, kept for its reason: a global read is in the dispatch loop.
  Measured at **no cost** — Fib (27) is 0.96 s against 0.95 s before.

  ⚠️ **The 256-CONSTANT cap was waste, not a limit.** `AddConstant` appended
  without interning, so 400 globals each initialised to `7` took 400 constant
  slots and the chunk ran out. Interning primitives fixed it with no wide form
  needed. **The type is compared before the value**, because `1` and `1.0`
  compare equal and render differently — interning on equality alone would
  print the wrong one. An OBJECT is never interned: two subprogram bodies that
  compare equal are still two subprograms.

  ⚠️ **Two operand bytes are not one operand, so an opcode has a SHAPE.**
  `OpShape` answers one letter per operand — `b` a byte, `s` a short — and
  `OpOperands` is derived from it rather than listed beside it. A count could
  not describe `OP_EXTEND` once its slot went wide, because it carries a byte
  and a short *together*; the old count-plus-is-it-a-jump pair had already
  rendered `OP_INVOKE 5 1` as `OP_INVOKE 1281`.

  ⚠️ **What the REAL program wants is two features, and the corpus never said
  so.** With the cap gone, all 28 shroom-slots units compile past it, and what
  they stop on is: **20 units** on a bare field read inside a method (implicit
  `this`) and **8** on `external` (SDL). The corpus ranked implicit `this` at 7
  cases among 33 refusals and said nothing about the FFI. Point `algvm` at the
  program before choosing the next increment.

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

  ⚠️ **Absorption is the THIRD pass, and the pass ORDER is the rule.** Exact,
  then widening, then gathering — so "a fixed-arity signature beats a variadic
  one" is written nowhere [EXP-014] and needs no code of its own. Putting
  gathering anywhere but last makes a gathering candidate declared first win
  calls a fixed one answered exactly.

  ⚠️ **Gathering belongs in `EnterFrame`, not at the call sites.** Every way
  into a frame then absorbs on the same terms — a plain call, a method, a
  constructor and a selected overload — and 0158 exercises all four.

  ⚠️ **`Fits` must be asked before gathering, and comparing COUNTS is not
  enough.** `Total ('a', [1, 2, 3])` has the right count and passes the list;
  `Total ('a', 1)` has the right count too and still has to gather, because the
  Integer does not fit `List`. A count test alone silently binds the Integer to
  the list parameter.

  ⚠️ **A variadic mismatch is a SELECTION failure, not a count.** The element
  type *replaces* the arity check and is stricter than it, so
  `Total ('a', 1, 2, 'red')` fails because `'red'` is not an Integer — not
  because there are four arguments. `Expected 2 arguments but got 4.` is the
  plausible wrong answer, and 0158 compares the text.

  ⚠️ **Whether a parameter absorbs goes through `CanonicalType`**, not through
  a raw string compare. All three back ends used to test the written spelling
  against `'List'` exactly, so `list of Integer` did not absorb — a defect
  against [TYP-002], since a type is written as an identifier and folds like
  any other name. Fixed rather than matched; see the type-name note below.

  ⚠️ **The name-clash trap bit again, and it cost 76 divergences.** A
  top-level `Absorbs` and `SignatureOf` in `vm/Vm.a24` collided with
  `ObjFunction.Absorbs` and `Resolver.SignatureOf` — both **methods called
  bare from inside their own class** — and the whole corpus broke at once in
  cases with no variadic in them. What found it was this emitter's own new
  diagnostic, `Undefined variable 'SignatureOf'. Unit 'Vm' exports it; this
  file has no 'uses' for it`, naming the colliding unit outright. Run the clash
  check *before* adding a top-level name to `vm/*.a24`, not after.

  **`Fits` and `FitsAt` collide the same way and measure clean**, which is
  recorded so neither gets "fixed" on suspicion: `ObjFunction` has methods of
  both names and calls them bare, yet overload selection through `algvm`
  answers correctly — a `Char` argument takes the `Char` overload and a
  `String` the `String` one. Not every collision breaks; the ones that do break
  loudly and nowhere near themselves.

  ⚠️ **An extension is decided at the CALL, on the receiver's VALUE.** A
  member wins [EXP-022] and only the running receiver can say whether there is
  one, so `OP_INVOKE_EXT` carries the name, the argument count *and* the
  extension's slot and chooses at run time — the type system is gradual, so
  `X.Size ()` may be a method on one value and an extension on the next. The
  Resolver's `Extension` field says **could**, not does. `RespondsTo` is the
  choice, and it mirrors the interpreter's `Responds` rather than improving on
  it: a String answers only to `Length`, a number only to `ToString`, a Char to
  **nothing** — which is what lets an extension take one.

  ⚠️ **A host object cannot be asked whether it responds, so it is asked by
  name.** The interpreter can `try Obj.Get (Name)` and catch; the machine
  cannot, because a dynamic member name is unreachable from Algol-24. It checks
  `HOST_METHODS` — the same list `OP_INVOKE` dispatches against, so the two
  cannot drift — plus the runtime's five properties.

  ⚠️ **`S.Trim` without parentheses is a VALUE** [FUN-011], so `OP_EXTEND`
  pushes a `VmExtension` holding the receiver, and `OP_CALL` unpacks it. The
  receiver is held rather than re-evaluated because it is evaluated **once**
  whichever step answers — 0190 counts the calls to prove it. Unpacking at the
  call and not at `OP_EXTEND` is forced: only the call knows how many arguments
  were written.

  ⚠️ **`Prepend` must be given the receiver, not read it off the stack.** The
  two callers keep it in different places — `OP_INVOKE_EXT` has it in the
  callee's slot, a bound extension carries it *inside* the value sitting there.
  Taking it from the stack read the `VmExtension` itself as the receiver, and
  the extension then asked a function for its `Length`.

  ⚠️ **`extension` needs nothing at the declaration.** It is permission, not a
  kind of declaration, so dropping the refusal in `EmitFunction` was the whole
  of that half — the Parser has already refused it on a method, a constructor,
  a property and a nested subprogram.

  ⚠️ **Two byte operands are not a 16-bit operand, and `--list` conflated
  them.** A jump's pair is one distance; `OP_INVOKE`'s is a name index beside a
  count. Rendering every pair as `hi * 256 + lo` printed `OP_INVOKE 5 1` as
  `OP_INVOKE 1281`, so `OpReadsShort` now tells them apart. `OP_CLOSURE` was
  worse: `OpOperands` answers 0 for it because it is **variable-width** (a
  constant, a capture count, then one slot per capture), and its doc claimed
  `run.a24` special-cased it when `run.a24` did not — so every offset after a
  nested subprogram was fiction.

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

  ⚠️ **Overload selection is at the CALL, on the argument values** [FUN-013] —
  two passes, EXACT then WIDENING, candidates in declaration order so a tie
  goes to the one written first. The interpreter's third pass, ABSORBING, is
  for a **variadic** candidate, which the emitter refuses instead — two passes
  would otherwise pick a wrong candidate silently.

  ⚠️ **A subprogram carries its parameter types only so a set can select**, and
  they arrive **resolved**: a subrange is recorded as the type it constrains,
  because the subrange table is the compiler's and not a chunk's. With the
  types missing every candidate accepted everything and the first always won —
  which looks exactly like a selection bug rather than a missing field.

  ⚠️ **A `LabelStmt` WRAPS the statement it labels** — `Inner` — rather than
  preceding it. Emitting nothing for the label emitted nothing for the loop
  too, so `Outer: for ...` compiled to **no bytecode at all** and the whole
  loop silently vanished.

  ⚠️ **`break` and `continue` must close what they jump out of — both kinds.**
  Locals declared since the loop opened need an `OP_POP` each, *and* every
  `try` opened inside it needs an `OP_UNTRY`: the jump skips the one the `try`
  would have run, so the handler stack keeps an entry whose frame and stack
  depths are stale and the **next** raise unwinds to it. The corpus passed
  before that fix by luck.

  ⚠️ **`continue` lands on the INCREMENT, not the condition.** One target
  serves both loop forms — a counted `for` runs its step and falls into the
  backward jump, a `while` has no step and falls straight into it — which is
  also why `continue` needs no backward jump of its own.

  ⚠️ **Closures BOX rather than closing over stack slots**, which is what
  `CEmitter` already does for the same problem — so there is no open-upvalue
  list and nothing to close. A subprogram that declares a nested one boxes
  **every** local, conservatively, because working out exactly which are
  captured needs a free-variable analysis and boxing too many costs only an
  indirection. Capture-by-reference, outliving the call, and a fresh set per
  call [FUN-009, FUN-010] all fall out of the cell being heap-allocated.
  **One level of nesting**; two would need a capture to come from a capture,
  which is the distinction clox draws with its is-local flag.

  ⚠️ **Closures were ONE corpus case.** Measure the refusal list before
  choosing what to build: overloads are 8 cases, private members 5, nested
  `uses` 5. The biggest remaining *piece of work* was nearly the smallest gain.

  ⚠️ **`is` and `as` are not the same rule, in two places.** `nil` has **no
  type**, so `nil is X` is false for every X — but a *cast* passes nil, by
  [VAR-005]. And `is Any` is **false** for everything, where `as Any` always
  passes: `Any` is the absence of a written type rather than a type a value can
  be tested against. Both were true-for-everything first, and both are
  one-line differences in two handlers that look like they should agree.

  ⚠️ **`5 is Dog` answers false, not an error.** A type name the machine cannot
  test is the *emitter's* job to refuse; a declared class the value simply
  isn't is a fair question with a boring answer. Raising on it reported a gap
  that was not there.

  ⚠️ **Exceptions are a handler stack, not `setjmp`.** `OP_TRY` records where
  to resume **and the call depth and stack depth** it was opened at, so a raise
  several frames down puts all three back before the handler runs. A raise does
  **not** travel as a host exception, because a raised value may be any value
  and a host exception carries a String.

  ⚠️ **One `try` wraps the whole dispatch loop**, which is what makes a runtime
  error catchable [STM-020] — a host error arrives as a String and becomes a
  raise of it. One try for the run rather than one per instruction, and it
  still costs about 15%.

  ⚠️ **`except` arms are ordered MOST DERIVED FIRST by the emitter**, because
  they compile to a chain of type tests that runs in order — so the order *is*
  the selection rule [STM-018]. The catch-all is keyed `'default'` by the
  Parser and always goes last.

  ⚠️ **Three places where writing or reading does less than it looks.** Writing
  to a global does **not** bind it — only a declaration does [0044]. An
  instance is **closed**: writing an undeclared field raises rather than
  creating one [0169]. And `as` is a **check**, not a conversion — dropping it
  silently made `'text' as Integer` answer `'text'`.

  ⚠️ **A method's wrong argument count reports a selection failure where a
  subprogram's and a constructor's report the counts** [0049]. All five reports
  in that one case are compared, so the split is not a style choice.

  ⚠️ **Subprograms, classes and enums are HOISTED; a `var` is not.** A class is
  hoisted but its **parent is attached in source order** — binding the parent
  early reported `Undefined variable` for a name the program had declared
  perfectly well [0112].

  ⚠️ **An enum member with ordinal 0 is FALSEY, and the host cannot tell.**
  It sees one of the machine's objects and calls every object truthy, so
  `OP_NOT` and `OP_JUMP_IF_FALSE` go through the machine's own `Truthy` —
  the only place the machine must *not* defer to the host about truth
  [ENU-009].

  ⚠️ **`for ... in` asks the host what to visit.** `OP_ITER` builds a List by
  running the host's own `for ... in`, so a Map yields keys, a String yields
  Chars and a Set yields members without the machine deciding any of it. It
  **materializes** the sequence, so a collection mutated during its own loop
  would be iterated as it was — a recorded trade, since no corpus case does it.

  ⚠️ **Renumber opcodes from DECLARATION ORDER, never by hand.** Inserting one
  while renumbering those above it left a gap twice and a collision once, in
  four increments. `The Numbering Is Contiguous And Unique` is the test that
  catches it — and this sentence used to promise "a script that renumbers
  every opcode from its position in the file", which **does not exist**. There
  is no such script; the test is the whole safeguard. Simplest is to APPEND a
  new opcode above `OP_COUNT` and renumber nothing, which is sound because an
  opcode's number is not interface.

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
  `finished/PROPOSAL-GC.md` exists to fix.

  ⚠️ **An Algol-24 LOCAL is a GC root, and `CEmitter` emits the shadow stack
  that makes it one.** `alg_roots` covers module-level variables, whose
  addresses the emitter knows once; a local has no such address, so a frame
  registers its argument array as ONE entry, each block saves and restores
  `alg_root_top` across its own braces, and each local is one entry pushed where
  it is declared. Measured at **+5.8%** on the VM's Fib (27) and **+1.3%** on
  `algc --compile`: a per-call frame costs most where the callee does least,
  which is LTO's own finding in reverse.

  ⚠️ **`alg_root_top` is read and written DIRECTLY by generated code, and
  `alg_root` is inline.** A block boundary is far more common than a
  declaration, so a call per brace is a cost the generated code must not carry.
  Both live in `algol.h` for that reason, which is why the contract there
  exposes runtime internals it otherwise would not.

  ⚠️ **A return evaluates its value BEFORE truncating, and a raise truncates in
  `alg_raise`.** `return <expr>;` after the reset would evaluate an allocating
  expression with the frame already unregistered, so `EmitReturn` uses a slot —
  the shape `Exit` already had for popping try frames. And a raise skips every
  block between it and the handler, so `AlgFrame` records the depth at
  `alg_push_frame` and the raise restores it before the `longjmp`.

  ⚠️ **A `volatile` local must be registered as one.** The emitter marks a local
  inside a `try` volatile so it survives the `longjmp`; `AlgRoots.slots` is
  `volatile Value *` because registering it through a plain `Value *` compiled
  fine and cast the qualifier away 101 times in one build.

  ⚠️ **A TEMPORARY IS A ROOT TOO, and the gap this used to describe is
  closed.** An intermediate inside one expression — the left operand of a `+`
  whose right operand is a call — is in no local and no argument array, so the
  shadow stack could not see it. That was survivable while a collection
  happened only where a program ASKED for one, because an expression is never
  interrupted by its own statement boundary; it stopped being survivable the
  moment collection became automatic, because a safe point inside a CALLEE
  fires while the caller is part way through an expression. `CEmitter` wraps
  each intermediate in `alg_hold`, which pushes the VALUE and not a pointer to
  it — there is no C local whose address could be taken.

  ⚠️ **HOLDS HAVE A STACK OF THEIR OWN, and sharing the shadow stack was both
  slower and harder to emit.** An entry there is a pointer and a count, so a
  held value needed a third field and three stores where this needs one — and
  the two have different LIFETIMES: a declaration's root lives to the end of
  its block, a temporary to the end of its statement. Separate tops mean a
  statement boundary restores one without the other, so a declaration in the
  middle of a block needs no special case at all.

  ⚠️ **A LOOP'S CONDITION AND STEP ARE NOT STATEMENTS**, so nothing else
  releases what they hold — and they run once an ITERATION, so a temporary in
  either accumulated for the whole loop. Both reset first, through a comma
  expression in the C header.

  ⚠️ **An expression that answers VOID in C must not be held**, which is a
  compile error in the GENERATED file rather than in the emitter.
  `alg_writeln`, `alg_write`, `alg_stderr_line`, `alg_halt` and the three
  assertions are the list, and `CEmitter.VoidCall` reads it off the emitted
  text because that is where the decision has already been made.

  ⚠️ **The cost is 13% on the MACHINE and nothing measurable anywhere else.** A
  hold costs where a program moves heap references about, which is what the
  machine's handlers do once per instruction: `Fib (27)` on `algvm` is 0.79 s
  against 0.70 before, while compiled `Fib (27)` is unchanged because an
  Integer is not pushed at all. `collector/0006` is the case,
  and an explicit `Collect ()` CANNOT catch it — a call written as a statement
  is a statement boundary, so every live value is already a local.

  ⚠️ **A TEXTFILE is exempt from the sweep, because it is on a list the
  runtime walks** — `all_files`, which `close_open_files` reads at exit. A
  released `ObjFile` stayed linked with its `next` overwritten by
  `obj_release`'s free-list link, and `close_open_files` walked in a circle at
  exit, finding the handle already NULL every pass. Twenty-six minutes of spin
  on one run, every collecting run, never the baseline. The price of exempting
  rather than unlinking is that an abandoned TextFile is not reclaimed until
  the process ends; unlinking would also close it EARLY, which is observable
  because an unflushed write is lost.

  ⚠️ **A BUFFER WAS EXEMPT HERE TOO AND IS NOT ANY MORE, because its list had
  no reader.** `all_buffers` was written and never read — its one reader,
  `free_all_buffers`, was deleted when the arena stopped being freed at exit —
  so the exemption outlived its reason and cost an object body per Buffer
  forever. A program accumulating text the way this language recommends grew by
  48 bytes an iteration. `obj_release` frees its bytes now, guarded so that
  `Free` releasing one EARLY stays safe, and the list is gone.

  ⚠️ **"Poisoning works, reuse does not" was the whole diagnosis three times** —
  the registry duplicate, the missing local roots, and the file list. Under
  `ALG_POISON=1` a body is never handed back out, so any bug that needs reuse
  vanishes. Read that split first.

  ⚠️ **A stage label in a trace means "about to", not "done".** `[exit] files`
  prints *before* `close_open_files` runs; reading it the other way blamed the
  next stage along and sent a round of work at the wrong function.

  ⚠️ **The arena is NOT freed at exit, and `alg_shutdown` closes files only.**
  `atexit` is its one caller, so every `free` it did returned memory the kernel
  was about to reclaim. `free_all_buffers` and `seq_forget_spares` were deleted
  with the calls rather than left as dead code.

  ⚠️ **Collection is worth 2.4× on the Inn over a LONG run, and a figure here
  is worthless without its frame count.** 3,000 frames at `--collect 200000`:
  peak footprint **2.58 GB** against 6.10 GB uncollected, maximum resident
  **3.54 GB** against 5.28 GB, and 19 frames a second against 20 — so about 5%
  for 2.4× less memory.

  The figure this replaces read 8.1× from **30 frames** (14.53 GB against
  1.80 GB) and claimed maximum resident went the other way. Neither survives at
  3,000 frames, where both numbers move together and the ratio is a third of
  what the short run showed. A short run is dominated by start-up, so it
  measures the arena filling rather than a program in steady state.

  ⚠️ **`ALG_POISON=1` is how to debug this class at all.** The sweep retags
  each released body `OBJ_RELEASED`, withholds it from the free list, and
  `check_live` names the kind and the site at the first misuse — so `exit=139`
  becomes `The collector released a List that a value being printed still
  needs.` It still recycles the backing BLOCKS and withholds only the object
  body, which is what makes it diagnostic: the Inn ran to completion under it
  after releasing 19,369,686 objects, separating *marking is wrong* from
  *reuse is wrong* in one run.

  ⚠️ **A MODULE's statements get the same two passes the root's do, and for a
  long time they got one.** `EmitInheritance` was called only from the loop
  over the root file's statements, and a `ModuleStmt` is not a `ClassStmt` — so
  **no class declared in any unit ever had its parent attached**. An instance
  of such a subclass had none of its inherited fields, which is how the
  library's `AppendFile` — a subclass of `OutFile` declaring no fields of its
  own — failed as `Undefined property 'Handle'` on the parent's field. The one
  pass also meant a unit's declarations were not HOISTED, though a class and a
  subprogram are visible above their own declaration [0044, 0122].

  ⚠️ **The corpus has inheritance cases and module cases but not their
  PRODUCT.** 0068 and 0112 cover inheritance, 0085 covers transitive modules,
  and inheritance *inside* a unit needed a subclass whose parent is in that
  same unit, instantiated from an importing file. Five bugs this session hid in
  a combination of two features the corpus tests separately.

  ⚠️ **An overload set's candidates are PARKED IN SLOTS, not left on the
  stack.** `OP_OVERLOADS` reads a window of `Count` values from the top, and
  leaving each declaration's closure there until the last arrives only works
  when a name's declarations are ADJACENT IN THE FILE. Interleave two
  overloaded names — `Tint`, `Where`, `Tint`, `Where` — and the window takes
  one candidate of each, so a perfectly good call fails with `No matching
  signature for function.` Five lines reproduce it.

  ⚠️ **The corpus cannot catch that, and the reason generalises.** A focused
  case declares a name's variants together; a library organised by TOPIC
  declares `TextColor`, `WhereY`, `NormVideo` and only much later their
  `Window`-taking variants. So `algol24-library`'s `graph` interleaves nearly
  every overloaded name it has, and this one bug was **ten of its fourteen**
  divergences. When a real program fails where the corpus passes, suspect a
  shape a test case would never be written in.

  ⚠️ **The comment that described this was right about the mechanism and wrong
  about the premise** — "the set is built when the LAST of them is reached,
  because only then are all its candidates on the stack". True of the code,
  false of the stack. A comment stating a reason is still a claim.

  ⚠️ **`vm/conform.sh` runs BOTH corpora, and for a long time it ran only
  conformance/.** A `refusals/` case is a program that must FAIL with a
  particular diagnostic — exactly what a back end gets wrong quietly — and the
  omission hid `refusals/0042` for the machine's whole life: a lone
  subprogram's declared parameter type was never checked, so `G ('a string')`
  where `G` takes an Integer ran and printed the string. It stayed hidden
  because refuse-by-name answered most refusal cases with a refusal, so there
  was nothing to compare; the hole only began to bite once the machine started
  emitting run-time diagnostics instead. **A count that says `0 diverged` is
  only as good as the set it walked.**

  ⚠️ **`EmitWidening` emits for `double` and `string` ONLY, because those are
  the two that convert — and a declared type also has to be CHECKED.**
  `EnterFrame` asked `Fits` and then fell through to the arity check, so a
  wrong type at the right count entered the frame. [EXP-013] puts even a lone
  candidate through selection, so the answer is
  `No matching signature for function.` — guarded on the count, since a wrong
  count still reports the counts [0049].

  ⚠️ **A `test` block is a `FunctionStmt` whose NAME TOKEN is the quoted
  name**, which is how the interpreter finds them and how the machine used to
  miss them: it emitted every test in every imported unit as an ordinary
  subprogram. Without `--test` that is dead code that can never run — and one
  construct it lacks refuses the whole program. `graph.a24` has a test pinning
  its documented parameter names, written with named arguments, and emitting it
  refused **all 57** of the library's reference examples that import `graph`.
  So a test block is emitted only when `TESTS_WANTED` says the run asked for
  one, which is how `algvm --test` and an ordinary run share the emitter. `DeclaresATest` is the predicate, named so it collides with
  neither `CEmitter.IsTest` nor `Parser.IsTestBlock`.

  ⚠️ **A DECLARATION of a built-in's name is one overload set with it**
  [FUN-005, 0187], not a shadowing — the declaration answers the argument
  COUNTS it declares and the built-in keeps the rest. **The rule is about the
  count alone**, which is what makes it a decision the emitter can take rather
  than an instruction that tries one and falls back: `ObjOverloads.Declares`
  asks nothing about the argument types, so a declared count wins even when the
  argument types do not fit it — a failure rather than a reason to reach past
  the declaration. `EXACT_ARITIES` and `GATHERED_FROM` record what the visible
  declarations answer, a gathering parameter lowering the floor to its own
  arity minus one, and a non-subprogram declaration of the name — `class Stack`
  — recording a floor of zero because it simply binds the name. A lone
  gathering parameter is the shape `crt` and `graph` use to redirect `Write` to
  a graphical console, and it answers every count.

  ⚠️ **Nesting goes to ANY depth now [FUN-012], and the old limit was a wrong
  answer rather than a refusal.** `CompileNested` set `Boxing := False`, so a
  subprogram two deep went down the plain-function path, resolved an enclosing
  name to a capture index anyway, and read cell 0 of a frame with no cells —
  `Index 0 out of range 0..-1.` The guard meant to refuse it sat in
  `CompileNested`, which that path never reached. 0063 passes either way
  because its middle subprogram has no locals to capture.

  ⚠️ **A capture DESCRIPTOR is what makes depth work, and it is clox's
  is-local flag.** `OP_CLOSURE` now writes, per capture, a flag byte saying
  whether it comes from this frame's own slot — which holds a cell, since a
  frame that declares a nested subprogram boxes every local — or from a cell
  this frame itself captured. A child's capture list is the parent's locals
  followed by the parent's own captures, in that order, so a name reached from
  three levels out is captured again at each level. Conservative, like the
  boxing.

  ⚠️ **Two caps were operand WIDTH, not design, and both are gone.** The
  capture count and each descriptor index are unconditional shorts, and
  `OP_LIST`/`OP_MAP` take a short count — all three instructions run once per
  closure or literal rather than in the dispatch loop, so a fixed second byte
  costs nothing measurable. What bounds a literal now is the value stack, which
  answers `The value stack overflowed.` at run time instead of refusing a
  program the machine could nearly hold.

  ⚠️ **`FRAME_ROOM` was clox's 64 and made the machine the most restrictive of
  the three processors by an order of magnitude.** It stopped at 63 frames
  where the interpreter manages about 800 and the compiled back end more than
  50,000 — and recursive descent is an ordinary thing to write, this compiler's
  own parser being one. Now 1024, measured at **no runtime cost** (Fib (27) is
  1.23 s either way, depth being a bound and not a loop) and about **7.7 MB**
  more resident. Both other processors SEGFAULT at their own limit with no
  diagnostic, so the honest message is this machine's advantage.

  ⚠️ **`STACK_ROOM`'s multiplier was a GUARANTEE and is now only a margin.**
  It held while a local slot was one byte, making 256 every frame's ceiling;
  local slots widened to a short, so a frame may hold more and a program of
  very many locals can reach the value stack first after all.

  ⚠️ **A SINGLETON's members were keyed by `ClassKeyFor` and a class's are
  not**, which is two faults in one call. `ClassKeyFor` wants a FOLDED name, as
  its other callers pass, so a mixed-case `SourceCode` matched nothing and the
  members went under the key `''`; and it resolves through the unit's imports,
  which is the question to ask about a class being USED and the wrong one about
  a class being DECLARED. The symptom was `Undefined variable 'Lines'` — a bare
  field read inside a singleton's own method, which is how this compiler's own
  `SourceCode` is written, so it is what stopped `algvm` running `algc`.

  ⚠️ **A class declared INSIDE a subprogram works, and took THREE holes to
  fix.** `Survey` walks top-level statements and `ModuleStmt`s only, so such a
  class was in no member table — `SurveyBodies` is a second walk that records
  members and claims nothing. Its PARENT was never attached, because
  `EmitInheritance` reads a top-level class back from a global the class in a
  body has not got — it is attached inline instead, with the class still on the
  stack, which a body's lack of hoisting makes correct. And `ClassKeyFor` is
  blind to a body-declared class at two sites, since it resolves through
  `DECLARED_NAMES` and the unit's imports and such a class is in neither;
  `ParentKey` tries the unit's own entry first.

  ⚠️ **The machine HOSTS `algc`, and the front end plus the C back end are
  byte-exact.** `algvm compiler/Main.a24 --compile --out=DIR X.a24` emits C
  **identical** to `bootstrap/algc`'s, for programs of any size tried — so
  Scanner, Parser, Resolver, TypeChecker and CEmitter all run correctly on the
  machine. What unblocked it was the constructor-type divergence below;
  `LiteralExpr.Init (Value : Expr)` is handed a literal's VALUE, so a strict
  reading stopped the machine at the first literal it parsed.

  ⚠️ **`TRY_ROOM` was 128 and a tree walker opens a region per EVALUATION**,
  so the handler stack gave way at a recursion depth of about 125 — long before
  the call stack. Derived from `FRAME_ROOM` now, at two per frame.

  ⚠️ **A capacity limit must not be CATCHABLE, and that was the real bug.**
  [STM-020] makes a runtime error catchable, which is right for the program's
  own faults — but the machine's limits travel the same way, as a raised
  String, so an ordinary `except on e : String` swallowed them: `Deep (200)`
  guarded by a handler answered **125** where both other processors answer 200,
  silently. In the hosted compiler the raised String was bound where a loop
  counter belonged, and `I := I + 1` then concatenated onto
  `Too many nested try blocks.1111…`, which is what finally named it.
  `OUT_OF_ROOM` makes `Unwind` decline those four, so they escape to the
  driver as the diagnostics they are.

  ⚠️ **THE MACHINE COMPILES THE COMPILER, and the output IS the seed.**
  `algvm compiler/Main.a24 --compile --out=DIR compiler/Main.a24` emits C
  byte-identical to `bootstrap/algc`'s own emission and to every generated file
  in `bootstrap/` — and that C builds into a compiler passing its whole suite.
  30.85 s against 1.77 s native, so **17.4×**, well above `Fib`'s 6.9×:
  compilation allocates where `Fib` computes. Peak 3.07 GB resident, and the
  frame stack never goes deeper than **272**.

  ⚠️ **`algvm` → `algc` → `algc` is CORRECT and does not fit on 16 GB.** The
  machine hosting the compiler hosting the compiler emits byte-identical C for
  a 233-line unit (4.1 GB, 736 frames) and a 1198-line one (6.9 GB, 2095
  frames), and is **killed by the OS** at about 9 GB for anything larger —
  1605 lines reaches 9005 MB, and `Main.a24` itself 9166 MB after 52 minutes.
  The native two-level run needs 8.97 GB and succeeds, so the machine loses by
  **2%** on a box with 16 GB of RAM and swap capped at 4 GB.

  ⚠️ **Collecting harder does NOT help that, and it is the obvious wrong
  instinct.** Peak footprint is 64.25 GB at `--collect 200000` and 61.4 GB for
  the native run that uses no VM collector at all — the interval made no
  difference across 5×, because the memory is **live**: the outer tree-walker
  holds the inner compiler's whole AST and every environment. A collector
  cannot reclaim what is reachable. What this needs is a bigger machine, not a
  smaller interval.

  ⚠️ **Hosting an interpreter multiplies frame depth by about SEVEN, and that
  is what `FRAME_ROOM` has to cover.** Two points rather than a law: 256 frames
  at one level of hosting became 2095 at two, and 60 became 736 — so
  `3-level ≈ 320 + 6.93 × 2-level`, a fixed base plus a per-guest-frame cost,
  which fits better than a ratio. **The ratio alone misleads**: it reads 12.5×
  at depth 60 and 8.2× at depth 256, and projecting from the shallow point
  alone over-estimated `Main.a24`'s need by 50%.

  ⚠️ **THE MACHINE RUNS `algc`, AND THE WHOLE CORPUS AGREES.** All **196**
  conformance cases answer identically through the machine-hosted compiler —
  195 against `bootstrap/algc` directly, and `0174` against an `--ffi`
  interpreter, since `algvm` always has foreign calls where the default `algc`
  has none. Both back ends: `--compile` emits byte-identical C as well.

  ⚠️ **A frame that RETURNS from inside a `try` must close it, and that one bug
  was 68 of the 69 failures.** `OP_TRY` records a base and a stack depth; an
  `Exit` from inside the region skips the `OP_UNTRY` that would remove the
  record, so it outlived its frame and the NEXT raise unwound into a frame that
  no longer existed — reading slot 0 as whatever live code had since put there.
  CLAUDE.md already carried this rule for `break` and `continue`; `Exit` was
  never held to it.

  Fixed in `DoReturn` and not in the emitter, because a frame is left FOUR ways
  — an `Exit`, falling off the end, a constructor answering its instance, and a
  selected overload — and one runtime truncation covers all of them where four
  emitter sites would each be a chance to forget. `CallNested`'s restore does
  the same, since a nested run can leave a region open too.

  ⚠️ **It was found by the TRACE, and could not have been found by reading.**
  Both chunks' bytecode had already been disassembled and their stack
  discipline verified by hand — correctly. The fault was a RECORD outliving its
  frame, which only shows as a `base` that does not match the `depth`.

  ⚠️ **`--trace N` keeps a RING of the last N instructions**, with `ip`,
  opcode, `sp`, `base` and `depth` — dumped where a raised value escapes. A
  ring and not a stream, because the machine runs millions of instructions
  before a wrong answer surfaces and the last few hundred are what is wanted.
  `sp` and `base` are the columns that pay: correct bytecode with a wrong
  answer is a frame reading the wrong slot.

  ⚠️ **`--watch TEXT` is the part that made it work.** Dumping only where a
  raise ESCAPES found nothing, because the interesting raise is almost always
  caught — a machine fault inside a program that guards itself never reaches
  the driver. Watching for the message dumps the instant it is raised, caught
  or not.

  ⚠️ **The trace costs 2.5% when OFF**, which is one Boolean test an
  instruction: Fib (27) reads 1.22 s with it against 1.19 s without, four runs
  each. Paid by every program whether it asks or not. The first draft of that
  comment said "measured free" before anything had measured it.

  ⚠️ **`--list` walks EVERY chunk now, not just the script's.** A nested
  subprogram's body is a constant of the chunk that declares it, so listing
  only the root showed nothing of the code that misbehaves — and a method's
  body is where a slot question gets answered. The lister queues any
  `VmFunction` among the constants.

  ⚠️ **Where the remaining hunt stands, so it is not restarted from zero.**
  `0047` is the smallest failing case: the interpreter's `Handle` reaches
  `Env.Define (Handler.Name, Value)` with `Handler` **nil**, which means the
  `if Handler = Nil then raise Original;` two lines above answered FALSE for a
  nil. Tagging all six `Undefined property` sites in `MemberOf` confirms it —
  site 1834, receiver `nil=true`.

  Both chunks were then disassembled and their stack discipline traced BY HAND,
  and **both are correct**: `Handle`'s four slots (three parameters and
  `Handler`) are balanced across every branch, and `VisitTryStmt`'s three-arm
  handler chain leaves the raised value in slot 1 and balances to empty. The
  `OP_INVOKE 5 3` that enters `Handle` puts the receiver and all three
  arguments exactly where the callee expects them.

  So the emission is right and the fault is at RUN time — which makes the next
  step a trace of `Base` and `SP` at that call rather than more static reading.
  ⚠️ And inserting debug statements between the nil check and the use makes it
  PASS, so whatever it is, is sensitive to statement layout.

  Ruled out, each with its own probe, so none of these is worth retrying:
  handler binding against locals; multi-arm `except` selection including three
  arms binding one name; a field named `Name` with and without an initializer;
  several classes in one unit each declaring `Name`; the
  `if X = Nil and Y.Contains (K)` shape in isolation; a method called from
  inside an `except` arm; and Maps and Sets keyed by 500 instances. `algvm compiler/Main.a24 X.a24` — the interpret path — is
  correct for a program of 15 top-level statements and wrong at 16. The
  threshold is hard and the symptom varies with the program:
  `Operands must be numbers.`, `Undefined property 'Add'`,
  `Only instances have properties.`, or silence. Narrowed so far:

  - **Deterministic.** `ALG_POISON=1` changes nothing, so it is not the
    collector handing a live body back out.
  - **Not the front end.** The emitted C is identical for the same program, so
    everything up to and including CEmitter is faithful.
  - **Not the machine's collections.** A Map and a Set keyed by 500 instances
    answer every lookup correctly, and object keys compare by identity as
    [VAL-011] requires.
  - **Not a feature of the input.** The first reproduction needed a class with
    two nested-subprogram methods, which was a red herring — `var T := 0;`
    followed by sixteen `T := T + 1;` is enough.
  - **Nothing in `vm/*.a24` has a capacity of 16**, so the number is not an
    array bound in the machine.

  The reproduction is three lines of Python and worth keeping: generate N
  statements, run both ways, bisect N. 15 passes, 16 fails.

  ⚠️ **The C BACK END holds one too, as a closure of arity -1.** `alg_builtin`
interns it by name in the RUNTIME, which is what makes `Length = Length` true
across units as well as within one — a static per generated unit would make two
reads two objects, where these compare by identity [VAL-011]. Arity -1 is the
interpreter's own convention (`Native ('Str', -1)`) and means the callee checks
the count; gathering cannot stand in for it, because a gathered list and a
single `List` argument arrive identically. `alg_writeln`, `alg_write` and
`alg_halt` answer **void** in C, so a thunk calls them and answers nil itself.
[FUN-011], `conformance/0216`.

⚠️ **The interned table is marked by the collector, and that is REASONED rather
than demonstrated.** It is a C static holding `Value`s, invisible to the
collector, and `OBJ_CLOSURE` is both marked and recycled by size class — so the
marking is necessary by construction. No probe would go red without it, though:
the released body is never handed back at its own size class, which is case
0004's trap. Do not remove it on the strength of a green run.

⚠️ **A BUILT-IN held as a value is a CONSTANT, not an opcode.** A built-in
  has no body to enter and no slot of its own, so reading one [FUN-011] pushes
  a `VmBuiltin` carrying its name, and `CallValue` sends that to the same
  `CallBuiltin (Name, Count)` dispatch `OP_BUILTIN` reaches — which is the
  whole guarantee: `var F := Length; F ('abc')` IS host `Length`, not a second
  one that would have to agree with it forever. The arity report comes free,
  since no arm matches a wrong count and the fallback already words it as a
  subprogram's.

  ⚠️ **It must be INTERNED or `Length = Length` is false.** A built-in is one
  value — the interpreter keeps a single native per name in the environment
  every file encloses — and these compare by identity [VAL-011], so a fresh
  object per read answers false. The table is program-wide and not per chunk,
  because a read in the script and a read inside a subprogram are the same
  built-in. Constant interning does not cover it: an OBJECT is never interned.

  ⚠️ **A built-in answers nothing about frames, so `CallValue` lifts the
  answer over the callee by hand.** The callee still sits beneath its
  arguments, where a subprogram's `OP_RETURN` would truncate to `Base - 1`.

  ⚠️ **Calling a subprogram held in a FIELD is a separate wrong answer, and it
  was found by probing this one.** `X.F := Up; X.F ('ab')` reports
  `C has no method f.` where the interpreter answers — the machine emits
  `OP_INVOKE` and `InvokeMember` never falls back to a field holding a
  callable. It fails identically for a plain subprogram, so it is nothing to
  do with built-ins; `var G := X.F; G ('ab')` works, which is what localises
  it to the invoke path.

  ⚠️ **A guest object renders through `ToString`, and without one the host
  says `<Class> instance`.** `as_text` invokes a `ToString` it finds, which is
  why `Str (Green)` was right while `WriteLn ([Red, Green])` printed
  `[VmEnum instance, VmEnum instance]` — the machine answered `Str` itself and
  never gave the host anything to render.

  ⚠️ **EVERY machine class a program can see needs one, and seven were
  missing.** `Rendered` is the machine's own renderer and is reached only when
  the machine renders the TOP value — from `OP_PRINT` and from `Str` — so a
  value the HOST renders, inside a collection or a diagnostic, went to
  `as_text` instead. `VmClass`, `VmSingleton`, `VmFunction`, `VmClosure`,
  `VmOverloads`, `VmExtension` and `VmInstance` each have one now: a class
  reads as its name, a singleton as its class's name, and a subprogram, an
  overload set, a closure and a bound extension all as `<fn Name>`.

  ⚠️ **`VmInstance` needed a HOOK, because `VmClass.a24` cannot import
  `Vm.a24`.** A class may say how its instances read [CLS-009], and reaching
  that means entering a frame, which only `Vm.a24` can do. So `VmClass.a24`
  holds `INSTANCE_RENDERER` and `RunChunk` fills it with `Rendered` — set
  there and not in a unit initializer, because a unit's bare statements do not
  run under `--test`.

  ⚠️ **THREE processor disagreements are closed, all by changing whoever was
  the odd one out.** None was covered by a case and none was settled by a rule,
  so each was decided by majority:

  - `Ord (X)` on an instance declaring `ToString` answered `'Fancy instance'`
    interpreted and `'F2'` the other two ways. `ObjInstance.ToString` never
    consulted the class's own rendering, which [CLS-009] gives it wherever a
    value is written — and the RUNTIME writes one inside its own diagnostics.
  - A CALL of a name that is both a field and a method took the FIELD
    interpreted and the METHOD the other two ways. A plain read answers the
    field in all three, which is what makes the call the only question.
  - `object S` declaring `ToString` printed the bare name on the MACHINE and
    `custom` the other two ways — the interpreter's singleton being a SUBCLASS
    of its instance, so its `Stringify` finds the method without being asked.
    That one was this machine's own regression, from adding
    `VmSingleton.ToString`.

  ⚠️ **The interpreter's two fixes both wanted a HOOK, for the reason the
  machine's did.** A class's declared rendering has to be *called*, which needs
  an interpreter — and `ObjInstance` cannot import the unit that imports it. So
  `INSTANCE_SHOWN` lives there and the interpreter installs `Shown` at
  construction.

  ⚠️ **That hook must NOT answer through `Stringify`.** `Stringify` ends in
  `Str (Value)`, which comes back to `ObjInstance.ToString` — so a class
  declaring nothing would recurse forever. It answers the default directly.

  ⚠️ **A method wins at a call by a flag the OUTERMOST member read clears.**
  `VisitCall` sets `MemberIsCallee` when its callee is a `GetExpr`;
  `VisitGetExpr` reads and clears it BEFORE evaluating the receiver. Without
  the clearing, `A.B.F (...)` would prefer a method for `B` on its way to `F`.

  ⚠️ **Two hooks may not share a name.** Naming the machine's
  `INSTANCE_SHOWN` too would have put one top-level name in two units that
  `vm/run.a24` imports both of; the machine's stays `INSTANCE_RENDERER`.

  ⚠️ **`Ord` of an enum member is the machine's answer, not the host's** — the
  same split truthiness has. The host holds one of the machine's objects and
  reports `has no ordinal` where the other two processors answer the position
  [ENU-010]. No corpus case asks, which is why it survived 260 of them.

  ⚠️ **An enumeration inside a subprogram is LOCALS, and the slots must be
  reserved first.** `OP_ENUM_MEMBER` reads the enumeration on top of the stack
  and pushes the member, which works for globals because defining one pops it
  and leaves the enumeration there. A local *is* its stack slot, so the members
  cannot stay on top: each is reserved nil, the enumeration goes above them,
  and every member is written back into its own slot and popped. The
  enumeration is boxed last, because `OP_ENUM_MEMBER` wanted it bare.

  ⚠️ **Named arguments reach a unit qualifier and an extension too.** A
  qualifier decides which declaration a call reaches and nothing else, so it
  takes `OP_CALL_NAMED` unchanged; an extension needs `OP_INVOKE_EXT_NAMED`,
  which packs the member name and the argument names into the one constant
  `OP_INVOKE_NAMED` already packs two names into — and **the receiver stays
  positional**, so the written names shift up one when it is prepended
  [FUN-016].

  ⚠️ **The ROOT file's unit name is the empty string, so `''` cannot mean "no
  unit".** Answering the visible-declaration question with a unit name and `''`
  for none made every top-level declaration read as no declaration at all, and
  0187 then sent a declared call to the built-in. Resolve and answer in one
  function, as `VisibleSlot` does.

  ⚠️ **Asking only about the CURRENT unit made that a silent divergence.** A
  program that `uses crt` and called `Write` reached the built-in and wrote to
  stdout, losing the redirect the interpreter honoured. `VisibleSlot`, not
  `DeclaredIn (CurrentUnit, …)`.

  ⚠️ **A FAST PATH is where a wrong answer hides, and `WriteLn`'s cost two
  bugs.** `WriteLn` with one argument short-circuits to `OP_PRINT` *above* the
  built-in branch, so it escaped both the visible-declaration question (the
  redirect) and the named-argument question (`WriteLn (V: 'abc')` printed
  `abc` instead of raising). Both guards sit on it now. Add a check to the
  general path and ask what skips it.

  ⚠️ **Named arguments are arranged at RUN TIME, and `OP_INVOKE_NAMED` packs
  two names into one constant.** The arrangement mirrors
  `ObjFunction.Arrange` — a slot per parameter, each filled once, all filled —
  so a name no parameter has, a parameter named twice and a half-filled call
  are one answer. It is run time because the callee may be a variable:
  `var F := Log; F (Message: 'held', Level: 'warn')` keeps the names of
  whatever `F` holds. And it is **why naming the absorbing parameter turns
  gathering off with no rule of its own** [FUN-005]: an arrangement has exactly
  the declared arity, so the exact pass takes it first. The member name and the
  argument names share one constant because at most one operand per opcode may
  widen.

  ⚠️ **A local named `Slots` shadows the VALUE STACK.** Writing the arrangement
  with `Slots` as its working list made `Slots[SP - Count + I]` read that list
  instead of the stack, arranging nothing. The stack is `Slots` because `Stack`
  is a built-in — same trap as a module-level table losing to a local.

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

  **A method is not the protection it looks like, and all three processors
  agree about it** — a bare call inside a class finds an imported unit's
  top-level function over the class's own method, which is **[MOD-017]** and
  `conformance/0212`. So before adding a top-level name to a program that
  imports `compiler/*.a24`, check it against every declaration there including
  the indented ones; `shroom-slots` keeps `tools/name-clash.py` for exactly
  this and it is worth copying.

  ⚠️ **VISIBILITY decides that, and the sentence above used to overstate it.**
  The subprogram wins only where the *unit declaring the class* can see it —
  its own declaration, or one of its own `uses`. A name declared in a unit that
  class's unit never imported does **not** enter the call, and the method
  answers. Both halves are measured: `Crated`, which imports `Sizer`, reaches
  `Sizer.Size` from inside its own method even at a matching argument count;
  `Boxed`, which imports nothing, reaches its own.

  ⚠️ **The C back end used to get the invisible half wrong, and it was four
  defects.** It asked whether any unit declares a subprogram of the name —
  program-wide — rather than whether one is visible here, so an unrelated unit
  growing a top-level `Measure` emitted
  `alg_error("Undefined variable 'Measure'...")` into an imported font unit's
  own C, at **eight** call sites, naming the wrong unit as the one to import.
  `DeclaredIn` and `VisibleDeclared` are the per-unit tables that answer it;
  `Declared` stays program-wide and now answers only `MissingName`'s
  program-wide question. See [MOD-016], [MOD-017] and `defects.sh`.

  ⚠️ **Four Buffer and Char traps, all of which compile and then misbehave.**
  `Str (B)` on a Buffer answers its PRINTED form, so use `B.Text`; `Buffer (N)`
  pre-fills N **zero** bytes and a Buffer holding one has no Text, so use
  `Buffer ()` to accumulate; `Length (B)` answers the printed form's length
  where a List raises (DEF-36), so use `B.Length`; and a one-character operator
  literal is a **Char**, which through v0.2.5 made `Op = '+'` against a String
  quietly false while `Op = '<>'` worked — refusing all the arithmetic while
  the comparisons passed. **That one no longer bites**: text compares as text
  [VAL-010].

  ⚠️ **`ClassNameOf` is a METHOD** on TypeChecker and on Interpreter, not a
  built-in. A third walker needs its own; it is `Node.ClassName` in a `try`.

  ⚠️ **`and` and `or` are a `LogicalExpr`, not a `BinaryExpr`.** They are their
  own node because they short-circuit.

  `vm/spike/` holds the programs that
  measured whether it is worth writing, and **`vm/spike/measure.sh` reproduces
  every figure** in `finished/PROPOSAL-VM.md` in about ten minutes — so run it rather
  than trusting a number quoted in prose. The short of it: an Algol-24 dispatch
  loop compiled to C runs about **12× slower** than the same work compiled
  directly, which is what the proposal weighs. Reserved for a real GC, because
  the runtime's bump allocator never frees — see the memory section of
  `bootstrap/algol.c`.

  ⚠️ **Two findings there are about the emitter, not the VM, and they are not
  conditional on it.** `build.sh` now probes for **`-flto`** and uses it
  (`LTO=0` opts out), because `algol.c` is a separate translation unit and every
  `alg_*` call crosses it. And `BoundValue` elides `alg_widen` where the
  declared type is `''` or `Any` **and now also where `Elidable` proves the call
  the identity** — the declared and actual types agree and the declared one is
  not a subrange. So annotating a variable costs nothing *where the checker
  knows the actual type*; where it does not, the annotation still buys a call,
  which is DEF-35's territory rather than this emitter's.

  ⚠️ **LTO's size depends entirely on the shape of the work**, and a number
  quoted without its workload is useless: 42% on a tight arithmetic loop, 24% on
  a VM dispatch loop, **3% on `algc --test` and 1% on `algc --compile`**. It
  removes call overhead, so it helps exactly where the callee does little. Do
  not repeat the 42% as though it were general -- `finished/PROPOSAL-VM.md` did, and it
  was wrong.

  ⚠️ **The frame budget is MEASURED on the machine, and the ALGOL-24 dispatch
  loop misses 30 fps where the C one clears it.** A played session on the
  Algol-24 loop — 4,941 frames in 196.4 s with automatic collection on — runs
  at **39.75 ms a frame, 25 fps**, which is **119% of a 30 fps frame**; the C
  loop below takes the same game to 32.18 ms. Quote a long run, not a short
  one: 30 frames reads 19–21 fps because the first frames dominate, and the
  game's own `frames`/`rate` lines are the only honest source.

  ⚠️ **The projection this section used to carry was optimistic by 2.2×.** It
  reasoned from the Inn spending **2.0 ms a frame** in compiled Algol-24 (plus
  0.3 ms in SDL) to 18.4 ms on the VM, "comfortably inside a 30 fps one"; the
  machine actually takes 39.75 ms. A per-frame cost projected through a
  microbenchmark factor is a guess, and this one was wrong in the direction
  that flatters the machine. The two facts that survive are about the *game*
  rather than the VM: it is **logic-bound, not SDL-bound** — foreign calls are
  13% of its frame — and **the Inn is the program that decides this, not
  `play`**, whose reel engine at 0.74 ms fits at 60 fps either way.

  ⚠️ **Collection is free at this scale, which 30 frames could not have
  shown.** The 25 fps above is *with* `--collect 5000000` running for the whole
  session, and the no-collection comparison over 30 frames reads 19 against 21
  — so the cost does not accumulate over thousands of frames. It buys **8.1×**
  less peak memory: 14.53 GB of footprint against **1.80 GB**.

  ⚠️ **THE DISPATCH LOOP IS IN C NOW, and it is 1.51× rather than the toy's
  1.7×.** `vm/dispatch.c` holds `alg_vm_dispatch` — eighty `case` arms calling
  the same Algol-24 handlers — and the Inn on a real display goes from **48.71
  ms a frame to 32.18 ms**, 20 fps to **31**, over 1500 frames. `Fib (27)`
  reads the same factor (1.35 s against 0.89 s), and that agreement is what
  says the factor belongs to the loop rather than to either program. So the
  Inn **clears 30 fps at 97% of the frame**, with nothing to spare.

  ⚠️ **A SOFTWARE RENDERER halves the measured gain.** Under
  `SDL_VIDEODRIVER=dummy` with `SDL_RENDER_DRIVER=software` the same pair reads
  52.47 ms against 42.96 — **1.22×** — because the renderer burns CPU inside
  SDL where the dispatch loop cannot reach it. Measure this one on a display or
  it understates by a third.

  ⚠️ **`vm/dispatch.c` is GENERATED, and `vm/dispatch.sh --check` is what keeps
  it honest.** The arms are written from `OpCode.a24`'s numbers and
  `Vm.a24`'s `BuildHandlers` table, so an opcode added to one and not the other
  fails the build rather than dispatching to the wrong handler.
  `vm/build.sh` runs the check before it compiles.

  ⚠️ **A FAST ARM IS A SHORTCUT PAST THE PLUMBING, NOT A SECOND
  IMPLEMENTATION, and `FAST` in `vm/dispatch.sh` is where they live.** One
  entry per opcode, generated into the switch like any other arm, and anything
  the fast path declines falls through to the Algol-24 handler — which stays
  the definition. `OP_ADD` is the first: two numbers held inline cannot be a
  `VmInstance`, so [EXP-020]'s overload check cannot apply, and `alg_add` still
  does the adding, so unbounded overflow and the type rules stay in one place.
  That is what keeps this out of the "two implementations to hold in agreement"
  trade a wholesale handler rewrite would make.

  ⚠️ **What a fast arm actually saves is the STACK, not the arithmetic.**
  `Slots` is an Array, so `Push` and `Pop` each go through
  `alg_subscript_get`/`alg_subscript_set`, which try Map, Buffer, Set,
  sequence and text in turn before they can index — 18.5% of the Inn's frame
  is stack plumbing against 19.5% for all arithmetic and comparison together.
  `alg_array_slots` is the companion to `alg_buffer_bytes` and answers the
  backing store; it is safe to touch that way only because the stack is
  allocated once at a fixed size and never grows.

  ⚠️ **`OP_ADD` alone is worth about 2.6%, and ONE OPCODE IS AT THE NOISE
  FLOOR.** Fib (27) reads 1.028–1.043× over four interleaved pairs; the Inn
  reads 1.036× and 1.015× over two, where the baseline alone spans
  26.95–27.46 ms. So measure the whole set at once rather than an arm at a
  time — a single arm cannot be told from variance on a real display.

  ⚠️ **A fast arm must be SEEN to run.** It is indistinguishable from an arm
  that always falls through, which would measure as a disappointing result
  rather than a broken one. Sabotaging the arithmetic made `2 + 3` answer
  1002 while `'ab' + 'cd'` stayed correct, which is the check worth repeating
  for each new arm.

  ⚠️ **`CodeBytes` is swapped per frame, so the loop re-reads the byte pointer
  EVERY instruction.** `alg_buffer_bytes` is in `algol.h` for that — caching it
  across instructions reads the previous frame's code after any call or return.

  ⚠️ **It is a FLAG, and both loops still exist.** `C_DISPATCH` is False in
  `Vm.a24` and `vm/run.a24` calls `UseCDispatch ()`, so the machine's own tests
  under `algc` exercise the Algol-24 loop while the shipped binary runs the C
  one. That is what lets `./test.sh vm/Vm.a24` keep testing the handlers, and
  it is also a drift risk: the two loops must agree, and only `vm/conform.sh`
  holds them to it.

  ⚠️ **A green run proves nothing until the C loop is seen to RUN.** It is
  reached through an `external` with no library name, so a binary that cannot
  find its own symbols does not run it. Sabotage an arm and watch the failure
  before trusting a figure.

  ⚠️ **THE TWO NAMES THE LOOP OFFERS THE GUEST ARE ANNOTATED, not left to a
  linker flag.** `ALG_VM_EXPORTED` is `__declspec(dllexport)` on Windows and
  `__attribute__((used, visibility("default")))` elsewhere — the first is what
  the LTO plugin understands and the second is what stops it discarding a
  function nothing references. Without it, `-flto` and
  `--export-all-symbols` disagreed about the ADDRESS on MinGW: the symbol was
  found, the pointer was not the function, and the call landed in the middle of
  nowhere. `foreign_resolve` could not catch it, because it checks for NULL and
  the answer was not NULL.

  ⚠️ **WINDOWS RUNS LTO PERFECTLY WELL, and blaming LTO was the wrong
  diagnosis.** `bootstrap/build.sh` probes for `-flto` too and `algc` works
  there; `algc` is simply never asked to find its own symbols. With the
  annotation Windows keeps both LTO and `--export-all-symbols`.

  ⚠️ **The flag is still PROBED, over (LTO, flag) PAIRS, and the probe RUNS.**
  `-export_dynamic` is Apple's, `--export-dynamic` is GNU/ELF's, and PE exports
  nothing from an executable without `--export-all-symbols` — so the spelling
  cannot be assumed. The probe puts its target in **its own translation unit**
  with the same annotation, links it as the real build does with `$LTO`,
  **calls through the pointer**, and compares its **output**. Every one of
  those four things was needed: a same-unit target, a NULL-check-only test, no
  LTO, or an exit-status test each passed a combination the real binary could
  not use. `-export_dynamic` on MinGW is the sharpest case — it links, and
  produces an executable that runs and prints nothing at all.

  ⚠️ **macOS needs NO flag at all, which is why a wrong one went unnoticed.**
  The lookup succeeds with `-export_dynamic`, with `-rdynamic` and with
  nothing, so the hard-coded flag was never load-bearing here and could not
  fail where it was written.

  ⚠️ **`--algol-loop` RUNS WITHOUT THE C LOOP, and not having it was its own
  gap.** The loop is an optimization over handlers that remain the definition,
  so there has to be a way to run without it — a platform where it misbehaved
  otherwise had no working machine and no way to say whether the loop was the
  cause. It is load-bearing: Fib (27) reads 0.69 s against 1.07 s.
  `CDISPATCH=0 ./vm/build.sh` leaves the loop out of the binary entirely, and
  `Vm.a24` asks `alg_vm_dispatch_present` inside a `try` so such a build falls
  back rather than dying at the first instruction.

  ⚠️ **THREE GREEN STEPS PRECEDED THE FAILURE, and that is the lesson.**
  `algvm --version` does not run the loop and `./test.sh vm/Vm.a24` runs the
  machine's tests under `algc`, which has the Algol-24 one — so **nothing in CI
  exercised the C loop until a program ran**. The two-live-loops arrangement is
  what hid it. And `test "$(...)" = ...` in the workflow hid the output and the
  diagnostic both, so three rounds saw only `exit code 1`.

  ⚠️ **The cost is that giving C a stable name to call FREEZES the
  `Value **cells, Value *args, int32_t count` calling convention**, which was
  private before this and has changed before.

## The collector

⚠️ **ALL THREE PROCESSORS COLLECT, and the interpreter's refusal was stale.**
`Collect ()` is a request [RT-029] and every processor now honours it. The tree
walker answered `0` until v0.2.4, reasoned as *"its live values sit in C locals
all through a recursive evaluator"* — true when written, and overtaken by the
shadow stack: the walker is itself a compiled Algol-24 program, so its
evaluator's locals are exactly what the collector walks. Removing the refusal
released **1,400,104** objects where it had answered 0, with all 275 corpus
cases byte-identical to the run that declined.

⚠️ **The COMPILED back end has had a precise collector since v0.2.0, and
`collector.sh` tests it and nothing else.** This is easy to misremember as a VM
feature: it is not. `CEmitter` emits the roots and the shadow stack, and the
VM's roots come free from that because `Slots`, `GlobalCells` and the frame
arrays are module-level variables of `Vm.a24`. A program may depend on neither
the count nor on anything being freed: `Collect` changes how much memory a
correct program uses and never what it computes.

⚠️ **The tree walker collects automatically too, every `INTERP_COLLECT_EVERY`
statements (200,000).** Its safe point is a STATEMENT BOUNDARY, the walker's
equivalent of the machine's top-of-dispatch-loop. Measured on
`algc --test slotmath.a24`, the heaviest interpreted run there is: **5.57 GB and
32.42 s without, 2.01 GB and 35.22 s with** — about 2.8× less memory for about
9% more time. That is R-13, which was reported as the interpreter running away
with memory the compiler does not need.

⚠️ **AUTOMATIC collection is ON by default on the machine, at 2,000,000
instructions, and `--collect 0` is how to turn it off.** `Vm.a24` collects at a
safe point: the top of the dispatch loop, after an instruction has finished,
where every live guest value is on `Slots` or in a module-level variable.

⚠️ **The interval is a MEASUREMENT and the knee is sharp.** Compiling the
compiler on the machine: off is 30.59 s and 2952 MB; 5,000,000 is 32.03 s and
780 MB; **2,000,000 is 32.38 s and 707 MB**; 1,000,000 is 33.27 s and 674 MB;
200,000 is 39.59 s and 658 MB. So below the knee the time climbs while the
memory does not — 200,000 costs five times as much time as 2,000,000 to save
7% more memory. About **4x less memory for about 6% of the time**, and a
program that allocates almost nothing pays the same 5% because the counter is
tested per instruction either way (Fib (27) is 1.29 s off, 1.35 s on).

⚠️ **The DEFAULT is the machine's, not the driver's — and the split is
deliberate.** `COLLECT_EVERY` stays 0 in `Vm.a24`, so an embedder that sets
nothing collects nothing; `vm/run.a24` supplies the policy. The right number is
a measurement rather than a fact, which is why it does not belong in the
machine.

The claim this replaces said automatic collection was UNSAFE and named the Inn
failing as `Only instances have properties.` Disproven, most likely by the
precise-roots and shadow-stack work that landed after it was written — exactly
the missing-root class it described. The note that replaced *that* one said
flipping the default was unlicensed because the evidence was "a scripted walk,
headless video, one path through the game". That is what the flip answered:
**the whole corpus (0 diverged), `algol24-library`'s suite across every
unit, shroom-slots' `verify.a24` 59 lines identical to the interpreter, the
compiler's own self-compile byte-identical, and the Inn closing cleanly at 400
frames — 19 fps against 20.** An explicit `Collect ()` was always unaffected
and works either way.

⚠️ **`ToUpper` AND `ToLower` INTERN THEIR ANSWERS, because the arena never
frees and a fold is a COPY.** That made the cost proportional to the number of
CALLS rather than to the number of distinct strings — and the machine folds a
name for every member read and every built-in call, so a loop containing one
call to a built-in grew without bound. It took `shroom-slots` to 10.1 GB on a
15.6 GB device, where the low-memory killer took it with no error and nothing
in the crash buffer, because nothing had gone wrong in the program. R-18.
`folded` now keys a 4096-slot table on the input bytes; the minimal case goes
from 64.5/111.0/173.0 MB at 1/4/8 M calls to **flat at 49 MB**.

⚠️ **THE KEY IS A COPY OF THE INPUT, and the table is BOUNDED by overwriting.**
A Buffer's bytes move when it grows and `Free` releases them, so storing the
caller's pointer would compare against memory that had become something else.
And the input may be program DATA rather than a name — a program folding a
million lines must not fill the table — so a slot is overwritten rather than
chained: a hot name keeps its slot, cold text pays the copy it would have paid
anyway. Eviction FORGETS rather than reclaims, since the arena cannot.

⚠️ **4096 slots is enough, measured: 65536 changes nothing.** So the Inn's
remaining growth is not this table thrashing.

⚠️ **R-18's own minimal case was NOT minimal, and the List in it was
incidental.** It reported a List that "does not give its memory back", and
both free lists round-trip perfectly — 83,430 item blocks and 83,622 object
bodies returned per sweep and fully consumed by the next cycle. A loop
containing `Length ('abc')` and nothing else leaks at the same rate.

⚠️ **WHAT FOUND IT WAS A HISTOGRAM OF ARENA REQUESTS BY CALL SITE**, after
reading got nowhere. Sizes alone said 8–15 bytes and that was not enough; a
`__LINE__` histogram named the line in one run. Worth repeating for the next
arena question: `obj_alloc` and the items array showed flat while one line
climbed by exactly 2 per iteration.

⚠️ **COMPILED ALGOL-24 COLLECTS AUTOMATICALLY NOW, at the top of every loop
body.** It used to collect only where a program called `Collect` itself, so
R-18's case compiled was 156.8/611.8/1222.4 MB at 1/4/8 M lists; it is **flat
at 17.4 MB**. `alg_safe_point` is `static inline` in `algol.h` and
`CEmitter.EmitSafePoint` puts one at the top of each loop body — both forms,
`WhileStmt` and `ForInStmt`.

⚠️ **THE EMITTER HAS TO PLACE IT, because the runtime cannot know where it is
safe.** An intermediate inside one expression is in no local and registered
nowhere — `alg_add(v_t, alg_text_length(alg_str(v_i)))` holds a string the
shadow stack cannot see — so collecting from `obj_alloc` would sweep a value
in use. At the top of a loop body every live value is a registered local or a
module-level root, which is the compiled equivalent of the machine's
top-of-dispatch-loop and the walker's statement boundary. A `for ... in`'s
snapshot is safe there because `DeclareLocal` roots it.

⚠️ **A LOOP IS THE ONLY SHAPE THAT ALLOCATES WITHOUT BOUND**, which is why
this is per iteration rather than per statement. The tree walker ticks per
statement because it has no cheaper boundary; compiled code has one.

⚠️ **It makes the compiler 24% LIGHTER at no cost in time**, measured
interleaved: `algc --compile compiler/Main.a24` goes from 77.8 MB to **58.9**,
and 2.91 s either way.

⚠️ **AN EARLIER FIGURE SAID THE PEAK DID NOT FALL, and it was measuring the
wrong binary.** Generation 2 is emitted BY generation 1, so it *emits* safe
points without *containing* any — only generation 3 collects while it
compiles. Comparing gen1 against gen2 compares two binaries that both lack
them. After a reseed the real comparison is available and goes the other way.
Anything measuring a change to CEmitter must reach the generation that
contains it.

⚠️ **`alg_tick_every` IS THE POLICY and `ALG_COLLECT_EVERY` overrides it**,
default 100,000 iterations. The three processors now each state their own
interval over one shared mechanism — the machine in `vm/run.a24`, the walker
in `Interpreter.a24`, and a compiled program here — where before this one had
nowhere to state anything.

⚠️ **The Inn is 81% better and not flat.** Growth over 1000 frames falls from
229 KB a frame to **43**, and peak drops about 540 MB, measured interleaved.

⚠️ **THE REST OF IT IS TEXT, AND A STRING IS NOT COLLECTABLE.** The same
histogram found the remaining 43 KB a frame in three lines, and they are one
family: `as_text` rendering an Integer (`arena_alloc(24)`, +977,722 over 1200
frames), string **concatenation** (`arena_alloc(max(64, (need+1)*2))`,
+587,164), and `file_read_line` (128 bytes a line, +116,281). Measured on
minimal cases, both unbounded and linear:

| | per call |
| --- | --- |
| `Str (N)` in a loop | **23 bytes** |
| `'row ' + Str (N) + ' of many'` | **84 bytes** |

⚠️ **THREE OF THEM WERE SCRATCH RATHER THAN RESULT, and those are fixed.**
A render and a line-read allocate a working buffer whose answer is consumed at
once, so neither needs the arena:

| | before | after |
| --- | --- | --- |
| `Str (N)` | 23 bytes a call | **7.8** |
| `'row ' + Str (N) + ' of many'` | 84 bytes an iteration | **38** |
| the Inn's arena | 119 MB, +43 KB a frame | **68 MB, +20** |

`as_text` renders an Integer into one of **four rotating scratch buffers**
instead of `arena_alloc(24)`; `file_read_line` keeps **one buffer it reuses**
rather than taking 128 bytes a line and another 256 when a line outgrows it;
and `concat`'s floor went from **64 bytes to 32**, which was most of its cost
for short text while still leaving a short result twice the room it asked for.

⚠️ **A SCRATCH ANSWER MUST BE COPIED BEFORE IT BECOMES A VALUE**, and that is
the whole hazard. `alg_str` copies at the length the render actually had, and
the `ToString` property goes through `alg_str` for the same reason rather than
calling `alg_string(as_text(...))` — which would have left a Value pointing at
a buffer the next four renders overwrite. Text itself never uses scratch: it
answers its own durable bytes, which is why `concat`'s left-and-right pair and
the FFI's eight marshalled strings are safe.

⚠️ **DOUBLING SURVIVES, and it is what the floor protects.** Repeated `+` stays
linear because the slack is what the in-place extension writes into — 400 k,
800 k and 1.6 M appends measure 0, 0.01 and 0.03 s, where a quadratic would
show sixteen times. Lowering the floor further would start to cost that.

⚠️ **The Inn's RSS barely moves while its ARENA halves**, which is the measure
to trust here: RSS is dominated by SDL and lags the arena's reservation. 13.4
KB a frame of RSS against 43 of arena before; 12.5 against 20 after.

⚠️ **INTERNING CANNOT FIX THE REST, which is what makes it structural rather
than another R-18.** Folding repeats — the machine folds the same handful of
names forever — so a table of answers bounds it. `Str (N)` for varying N and
`A + B` for varying text produce a DIFFERENT answer every time, so a cache
only delays the growth.

The reason is one sentence: a `VAL_STRING` carries a raw `const char *` into
the arena **with no owning object**, so the collector has nothing to sweep and
the arena never frees. Every `Str`, every `+`, every `Copy` and every fold is
held for the life of the process. Making strings collectable means giving them
an owner the registry can walk, which is a change to the value representation
and wants a proposal rather than a patch.

⚠️ **`Buffer` IS THE EXISTING ANSWER and the note recommending it undersells
why.** CLAUDE.md has long said to accumulate text with `Buffer` "for anything
large" on the grounds that `+` is linear — the stronger reason is that a
Buffer's bytes are **malloc'd and explicitly freed**, so a Buffer is the only
text in the language whose memory comes back.

⚠️ **The registry must be COMPACTED by the sweep, or collection costs O(every
object ever allocated).** Keeping released objects registered made clearing
marks and sweeping both walk the whole history, so each collection grew slower
than the last and the Inn could not finish 120 frames. A released object leaves
the registry and `obj_alloc` re-enters it if it is ever handed out again.

⚠️ **A free-list link must not go in the object's FIRST word.** `seq_recycle`
puts one there because a bare block has no header to protect; an OBJECT does.
Writing it at offset zero put it straight over `type`, `marked` and `dead` —
destroying the `dead` flag the line above had just set, so the next collection
read a garbage byte and released the same object twice. It goes after
`sizeof(Obj)`, where every object has at least a pointer.

⚠️ **VM startup dominates a short run and is not the frame cost.** 10 frames of
the Inn is 488 ms of frames inside a **41.5 s** process: the machine compiles
the whole program first. Quote the game's own `frames`/`rate` lines, never
process wall time.

⚠️ **Roots are PRECISE because a module-level variable is a C static.**
`CEmitter` emits `static Value *roots_<Unit>[]` of their addresses and calls
`alg_roots` in `init_<Unit>()`. No stack scanning, no guessing — and the VM's
roots come free from it, because `Slots`, `GlobalCells`, `Cells` and the frame
arrays are module-level variables of `Vm.a24`. The VM's *structures* need no
tracer either: `Chunk`, `VmFunction` and `VmClass` are ordinary classes, so
they arrive as `OBJ_INSTANCE` and the generic slot walk covers them.

⚠️ **A released object KEEPS its registry slot, so it needs a `dead` bit.** It
keeps its place in the arena and may be handed out again, so without the bit
the next collection finds it unmarked and releases it twice — one block on a
free list twice, handed to two owners. And `obj_release` must set that bit
FIRST, because it recycles the owned block before discovering whether the
object's own body has a size class, and an early return would otherwise leave
a recycled block for the next sweep to recycle again.

⚠️ **The owned block is where the memory is.** A List's `items` array is 392 MB
of the compiler's arena against 183 MB for the headers, so a sweep hands the
array back to `seq_recycle`'s size-class lists — the same lists a growing List
draws from. Measured: a program keeping one List and abandoning 100,000 peaks
at 17.50 MB uncollected and **1.39 MB** collecting every 1000 iterations.

⚠️ **A Buffer IS swept now, and `Free` is how a program releases one EARLY.**
Its bytes are malloc'd, so `obj_release` frees them rather than handing a block
to a spare list. The claim this replaces — that an object the language can
already release is not the collector's business — was true of nothing: it meant
a body per Buffer was permanent, which `collector.sh`'s `flat-text` now
catches.

**Two kinds of memory the sweep cannot return yet.** An instance's `slots` is
allocated at exactly its field count rather than a size class, so
`seq_recycle` declines it — 206 MB of the compiler's arena. And a Map's `index`
is an `int32_t` array, a different element size from the `Value` blocks the
spare lists keep.

## The text heap

⚠️ **EVERY STRING AND CHAR IS COLLECTABLE, and text used to be permanent.** It
came from the arena, which never frees, so a program building one string a
frame grew until the operating system killed it — `shroom-slots` R-18, whose
floor turned out to be lower than the `folded` cache it was first traced to.
`finished/PROPOSAL-COLLECTABLE-TEXT.md` is the record, including the two
attempts that were built and withdrawn.

⚠️ **A `Value` STILL CARRIES `const char *string`, which is the whole reason
this is small.** The pointer is the payload and an eight-byte header sits
immediately before it, so all thirty places that read a string's bytes are
unchanged — only construction, marking and sweeping moved. The two withdrawn
attempts each gave text an `ObjText` of its own and touched every reader.

⚠️ **ONE function sets a text Value's bytes, and that is the invariant marking
depends on.** `text_value` is the only assignment to `.string` in the runtime
— `grep '\.string *='` says so — which is what makes `text_head(v.string)`
safe in `mark_value`. A Value pointing anywhere else would have the collector
writing its mark into whatever lies eight bytes before it.

⚠️ **A LITERAL IS INTERNED BY ITS ADDRESS**, not by its bytes. Generated code
calls `alg_literal` with a C static whose address is stable for the run, so one
permanent copy serves every call — and the hash MIXES the low bits, because
shifting them away assumes distinct literals are eight-byte aligned and
`ascii_one` is a `[128][2]` array whose rows are two bytes apart.

⚠️ **A BLOCK ABOVE 512 BYTES BANDS TO THE NEXT POWER OF TWO**, wasting up to
half, and that is what makes a large block REUSABLE. Sizing those exactly
would mean a long string released is never handed out again — a leak for any
program reading a file line by line.

⚠️ **A RENDER is text no `Value` owns**, which is what `as_text` answers for a
collection or a `Buffer(12)`. Those are released at the next safe point, which
is sound for the same reason the temporaries gap was survivable: a collection
happens only between statements, and a render is produced and consumed inside
one expression. An Integer still renders into a rotating scratch buffer and
allocates nothing at all.

⚠️ **`Str` ON SOMETHING ALREADY TEXT MUST NOT COPY, and one line that did cost
EIGHT GIGABYTES.** `Str` only widens a Char to a String there [TYP-003] — a
change of tag and not of bytes — and the compiler calls it on nearly every name
it handles, including whole emitted units. Routing it through `alg_string_n`,
which copies into the heap, took `algc --compile` of its own sources from 53 MB
to 6.9 GB: **471,174 copies averaging 18 KB**. It is also what the two
withdrawn attempts were really measuring, and why both concluded the wrong
thing.

⚠️ **What found that was ATTRIBUTION, after reasoning had failed three
times.** A per-call-site histogram of the heap's own allocations named
`alg_string_n` in one run; the list of its callers in `algol.c` is short enough
to read. Two rounds of guessing had already landed on the chunk displacement
(real, worth 0.2%) and on `concat`'s doubling (six big allocations in the whole
run).

⚠️ **`ALG_MEM_REPORT=1` writes what the heap and the arena hold at exit**, and
it earns its place: the figure above is what it printed. Chunks, room, bytes
used, bytes live and the sweep count, plus the arena's total. It costs one
counter per CHUNK.

⚠️ **THE FOLD CACHE'S SLOTS ARE ROOTS, and permanent was a leak.** `folded`
remembers an answer per input; overwriting a slot forgot its key and its answer
where nothing could free them, so two million different inputs left two million
answers behind — 61 MB of live text in a battery written to prove there was
none. The occupied slots are marked instead, so an evicted entry is simply no
longer marked and a Value still holding an answer keeps it through the ordinary
root path.

⚠️ **A FILE OWNS ITS LINE BUFFER, and a shared one could not be returned.**
`lookahead` holds a line until a later statement consumes it, so a copy per
line was the price of sharing — and a program reading a large file paid it per
line and never got it back. Per file there is no copy at all: nothing points at
the buffer while `looked` is false.

⚠️ **A STORED `const char *` MUST BE COPIED OUT OF THE HEAP.** An `ObjFile`
keeps its name for as long as it is open, and the Value it came from may be
swept long before — so `file_name_argument` copies into the arena, where a
handful per program is the right trade.

⚠️ **AND ANY CACHE KEYED ON A TEXT ADDRESS MUST BE DROPPED WHEN THE BLOCK IS
RELEASED, which is the one thing the heap changed about an address.** While
text came from an arena that never freed, a pointer identified its bytes for
the life of the process — so (pointer, byte length) was a safe identity, and
`text_info` cached a string's character count and its all-ASCII flag under
exactly that key. A recycled block breaks it: a different string of the same
BYTE length arrives at the same address and is answered with the old one's
count. `text_release` calls `text_forget_info`, and `text_info_slot` is one
function so the cache and its invalidation cannot disagree about where an
entry lives — a wrong slot there is a cache miss rather than a failure, so it
would never surface.

⚠️ **IT TAKES A MULTI-BYTE CHARACTER TO SHOW AT ALL**, which is why one
program found it and no gate did. In all-ASCII text the character count IS the
byte count, so a stale entry answers the same number and nothing is wrong.
`algol24.com` D-3 is the report: one line in 27,875, where
`bytes=41 cached(ascii=0 chars=39) real(ascii=1 chars=41)` — a 41-byte line
carrying one em dash is 39 characters, and the plain-ASCII 41-byte line that
landed on its block afterwards was answered 39 and came back two characters
short. Twelve stale hits in a 500 KB render, six in each direction.

⚠️ **WHAT FOUND IT WAS RECOMPUTING ON A CACHE HIT AND COMPARING**, after three
probes guessed wrong — the first had the direction backwards, the next two had
the right direction and never hit, because reuse at the same address with the
entry still live is a coincidence a small program does not reach. The check
printed the mechanism in one run. `collector/0007` is the case, and it took
the exact byte lengths off that output to be reproducible at all: `Copy` rather
than concatenation, because concatenation reserves slack for the in-place
extension and two strings built that way never land in one size band.

⚠️ **`alg_collect` MUST NOT BAIL WHEN THERE ARE NO OBJECTS.** It returned early
on `obj_registry == NULL`, which skipped the text sweep — and a program that
does nothing but build text allocates no object at all, so two million
discarded strings got not one collection: 138.7 MB where it should be 8.2.

⚠️ **`ALG_TEXT_CHECK=1` RECOMPUTES WHAT THE CACHE ANSWERED and faults where
the two disagree**, which is what `ALG_POISON=1` does for a released object
body. It exists because the wrong answer is otherwise INVISIBLE: a stale
character count is a plausible number, it truncates one line in a megabyte,
nothing crashes, and the program that notices has to be rendering enough text
to hit the coincidence. It costs one `getenv` per cache HIT, which is already
the path that does no work.

⚠️ **IT IS A DIAGNOSTIC AS MUCH AS A GATE, and that is worth being honest
about: nothing in this repository's harnesses trips it today.** `collector.sh`
runs every case a third way under it, but the coincidence it catches — a block
recycled at the same address with its cache entry still live — is one a small
program does not reach. D-3 was found by a program in ANOTHER project rendering
half a megabyte of mixed text, and this repository has no equivalent. So
`collector/0007` is the regression gate; this is what makes the next one of
its class cost one run instead of an afternoon.

⚠️ **`ALG_POISON=1` COVERS TEXT**, filling a released block with `0xDD` and
withholding it, which is the same *marking is wrong* / *reuse is wrong* split
the objects have. It is how the first bug in this work was localised in one
run — and the probe that found the SECOND needed a stale READ to be caught
rather than a released one, because a short string read from a reused block
sees the free-list pointer, whose bytes include zeros.


## Commands

Build the compiler from the seed (needs only a C compiler; ~2 s):

```sh
./bootstrap/build.sh          # -> bootstrap/algc
./bootstrap/build.sh --ffi    # ... able to call C, needs libffi
./vm/build.sh                 # -> vm/algvm, which ALWAYS calls C
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

## The harnesses

All of them must pass. They are the definition of done.

```sh
./test.sh          # the unit tests, inline in the source they cover
./conform.sh       # the corpus, under BOTH processors
./spec/spec.sh     # every rule cites something that exists; the release agrees
./fixedpoint.sh    # the seed matches what the compiler emits, and emits itself
./docs.sh          # every unit is documented per spec/DOCUMENTATION.md
./collector.sh     # the collector keeps what a program holds, both ways
./installed.sh     # a program reaches an installed unit by name
./defects.sh       # every defect a project using the language reported
```

And the machine's three, which `test.sh`'s default root does not reach:

```sh
./test.sh vm/Vm.a24   # the machine's own tests
./vm/conform.sh       # the corpus on the machine, both corpora
./vm/reference.sh     # every opcode entry agrees with OpCode.a24
```

⚠️ **EVERY SCRIPT HERE IS sh AND awk, AND THAT IS A RULE RATHER THAN A
HABIT.** A C compiler is the only thing this repository needs to build itself,
so a generator or checker that reaches for python quietly makes that untrue —
`docs.sh` has carried the sentence since it was written, and `vm/dispatch.sh`
was added in python anyway, because the rule was stated only inside another
script where nothing surfaced it. The Windows job is what caught it:
`./vm/build.sh` died with `python3: command not found` on the one platform
where the checked-in `vm/dispatch.c` would then have gone unchecked. Ported to
awk, and the port was verified by generating byte-identical output to what
python wrote.

⚠️ **The count used to be in this heading and went stale twice.** There were
six, then seven, then eight; a number in a heading is a claim nothing checks,
which is the same rule this file applies to every other count.

⚠️ **`./defects.sh` is the newest and is a REGRESSION gate rather than a
development one.** It carries every defect `shroom-slots` and `algol24.com`
reported — sixteen — each reduced to the smallest program that shows it, and it
was written red and finished green. Seven of them divide the processors, so
those checks compare the three answers to each other rather than to recorded
text: a divergence has no single expected output, and comparing is what stays
honest if the right answer is later decided differently than the script
guessed.

⚠️ **It caught two things neither corpus did**, which is the argument for
keeping it. A **stale `vm/algvm`** — both binaries link the hand-written
`algol.c`, and `vm/conform.sh` builds its own `algc` while using the
checked-in machine, so a stale machine passes there and fails a three-way
comparison. And the **error-stub grep** over emitted C, which `shroom-slots`
added after one cost it an afternoon and which found three latent aborts on its
first run.

⚠️ **`spec/spec.sh` now also holds the RELEASE in its three places.**
`compiler/Release.a24`'s `VERSION`, `bootstrap/algol.h`'s
`ALG_RUNTIME_VERSION` and the `_Static_assert` in `bootstrap/algol.c` must
agree, so bumping the release is a three-file change or the gate goes red.
Both halves of the runtime are hand-written and copied verbatim by `--compile`,
so nothing derives either number — this check is the only thing that keeps them
in step, and it was seen red in all three directions before being trusted.

⚠️ **The runtime pair is a PAIR, and a mismatched one used to read as a corrupt
runtime.** `--compile` emits `algol.c` and `algol.h` together and the body uses
what the header declares. Anything assembling a build out of both the
compiler's output and a checkout of the compiler can take one of each — a
project packaging for Android did, and got twenty `cc` errors beginning
`call to undeclared function 'alg_collect'`, none of which said *two versions*.
The assertion makes it one line.

⚠️ **`./installed.sh` asks the one question every other gate assumes away.**
They all run from the repository root with a program's modules beside it, so
none of them asks whether a program in some *other* directory can reach a unit
installed somewhere else. Two portability defects hid in that gap and neither
was reachable from any corpus case of the day: `FolderOf` cut a path at `/`
alone, so a Windows binary found no install prefix at all; and `FileExists`
OPENS the path, and `fopen` on a **directory** succeeds on macOS and Linux and
fails on Windows, so a tested `lib` was found on two platforms and not the
third.

⚠️ **It would have caught NEITHER on a Unix, which was checked rather than
assumed.** With the directory test put back it still passes 9 of 9 on macOS —
`fopen` on a directory succeeding here is exactly why the defect reached
Windows undetected. So the separator defect is guarded by a Parser unit test
handing `FolderOf` a literal backslash, and the directory defect by this script
running in the **windows** workflow. What it guards everywhere is the layout
itself: both places a processor looks, under all three processors, and that a
nearer unit still wins.

Each prints its own totals. **Do not copy those totals into this file or the
README**: every count written down here has gone stale, and a number in prose is
a claim nothing checks.

⚠️ **`./collector.sh` runs the COMPILED back end only**, which was the rule
when the interpreter declined and is now merely where the cases happen to run.
The interpreter collects too, so there would be something to compare — worth
revisiting if a collector case ever needs to be about more than the compiled
path. `conform.sh` is where the processors are held to each other.

⚠️ **Every collector case runs TWICE — plainly and under `ALG_POISON=1`** —
because that split *is* the diagnosis. Poisoning withholds a released body
instead of reusing it, so a case that passes one way and fails the other says
whether marking or reuse is at fault. Three bugs in the hunt that produced
these cases had exactly that signature.

⚠️ **`flat-text` IS A SCALE CASE AND NOT AN OUTPUT ONE, because a text leak
is invisible to output.** Comparing what a program prints cannot catch one, so
`collector/flat-text.a24` takes a round count and is run at two scales ten
times apart with `ALG_MEM_REPORT=1`: the memory the runtime reports must be
the SAME. The small scale is **20,000 rather than 2,000** because the heap has
to reach steady state first — 2,000 rounds peaks BELOW the figure it settles
on, so comparing against that would read a leak as the heap merely warming up.
It was seen red against both leaks it guards: the fold cache's permanent
blocks, and a Buffer exempt from the sweep.

⚠️ **A collector failure may be a HANG, so each run is bounded** (`--limit N`,
default 120s). 0004 guards a released TextFile left linked in `all_files`, whose
symptom was `close_open_files` walking in a circle at exit — comparing output
alone waits for it forever.

⚠️ **A green collector case proves nothing until it has been seen to go red.**
0004 passed with the bug deliberately reinstated, because a released body only
does damage when it is handed to an object OF ITS OWN SIZE CLASS: the case
churned Lists, `sizeof(ObjSeq)` is a different band from `sizeof(ObjFile)`, and
the bodies were never reused. It now allocates handles after the collection and
fails in 30 seconds with the fix removed. Validate a new case against the
reverted fix before trusting it.

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

⚠️ **`is` and `as` AGAINST A BUILT-IN TYPE ARE RESOLVED AT EMIT TIME, and the
two functions they used to call were the heaviest in a profile of a real
program.** `alg_is` and `alg_cast` take the type as a string the emitter wrote,
so every test paid a linear scan of the subrange table and a case-insensitive
comparison for something fixed when the C was written.
`CEmitter.ResolvedKind` answers an `ALG_KIND_*` code for the thirteen built-in
type names, and `alg_is_kind` / `alg_cast_kind` are `static inline` in
`algol.h`, so the test is an integer compare. Measured at **11% on the VM's
Fib (27)** — 0.89 s to 0.79 — and **10% on the Dew Drop Inn**, 32.18 ms a frame
to 28.82, 31 fps to 34.

⚠️ **A BUILT-IN TYPE NAME IS NOT RESERVED, which is the whole of what the guard
is for.** `class List` is legal, and after it `X is List` must answer for an
instance of that class *as well as* for a List — both are true today. So
`ResolvedKind` refuses any name the program declares as a class, a singleton,
an enumeration or a subrange, and every one of those keeps the string form.
Resolving one of them would be a silently wrong answer rather than a failure,
which is why `DeclaresType` asks four questions and not one.

⚠️ **INLINE is more than half the gain, measured both ways.** Interning the
names *behind* `alg_is` at run time — the same resolution, still an
out-of-line call — measured **1.05×** on the Inn where resolving at emit time
measures **1.12×**. That is why `Obj`'s layout is public in `algol.h`, for the
same reason `alg_root_top` is.

⚠️ **A CLASS NAME IS RESOLVED TO ITS HANDLE TOO, and that walk compares
`ObjClass` POINTERS rather than names.** `alg_is_class`/`alg_cast_class` are
out of line, unlike the built-in pair, because `ObjClass` is private to
`algol.c` and exposing it would be a far wider contract than `Obj`'s three
fields; the win here is the strings rather than the call, since the name
version compares one per class per level and a member read walks that chain
several times. All 43 class tests in `Vm.c` resolve. Measured at **1.11× on
Fib (27)** — 0.79 s to 0.71 — and about **1.04× on the Inn**.

⚠️ **FOUR conditions decide it, and every one is correctness rather than
caution.** `CEmitter.ResolvedClass` requires that the program declare a class
of the name; that the handle be IN SCOPE in the file being emitted, since it is
a C symbol and `static` in a root file; that **exactly one** class carry the
name; and that no built-in type name, singleton, enumeration or subrange share
it. Two of those were seen to go red before being trusted.

⚠️ **TWO CLASSES OF ONE NAME ARE TWO OBJECTS, where the other two processors
match a class by NAME.** `Interpreter.SatisfiesType` ends in `InheritsFrom`,
which walks comparing names, so an instance of *one* unit's `Thing` answers
true for the *other* unit's `Thing`. Comparing handles answers false. Removing
the uniqueness guard was seen to produce exactly that divergence, so a repeated
name keeps the string form.

⚠️ **A class sharing a BUILT-IN's name is reachable by either route.**
`class List` is legal and `[1] is List` is **true** as well as `X is List` on
an instance — the value's own type name answers for the List where no chain
walk can. So `BuiltinTypeName` is asked without regard to declarations, which
is why it is split from `ResolvedKind`: the two callers want opposite things
from one list.

⚠️ **RUN-TO-RUN VARIANCE ON A REAL DISPLAY IS THE SAME SIZE AS THIS EFFECT, and
reading two separate runs said it did nothing.** 1500-frame runs read 28.82 ms
and 28.81 ms, which looked like a ceiling and nearly got written down as one;
interleaved 1200-frame pairs read 29.95 → 28.79 and 28.75 → 27.48, and the same
binary spans 28.75–29.95 by itself. Interleave the pairs for anything under
about 5% here, and prefer the software renderer when the question is purely
about CPU: `SDL_VIDEODRIVER=dummy` with `SDL_RENDER_DRIVER=software` reads
41.13 → 40.09 ms over 1500 frames, which is the cleanest form of this one.

⚠️ **It is worth ~10% where type tests are hot and NOTHING where they are
not.** `algc --compile` is unchanged at 1.00× and `algc --test` gains 4%: the
compile path is string building, where the tree walker asks `is` per node. The
VM gains because its handlers are full of `is`/`as` — 243 sites in `vm/*.a24`,
71% of them against a built-in type. `finished/PROPOSAL-VM.md` put this rung at
**1.45×**, off a three-instruction loop where one `alg_cast` was a thirteenth
of the iteration; a toy rung does not transfer, and this is the second time
that has been measured.

## Tests

Tests live inline in the source they cover, as `test 'Name'; begin … end` blocks
using `AssertEqual`, `AssertTrue` and `Fail`. `--test` runs them instead of the
program; the main block never executes. Failures exit 70 via `Halt(70)`.

The compiled test runner reproduces the interpreter's report **line for line,
including the `[ERROR]` line naming why each failure failed.**

⚠️ A test failure prints exactly one `[ERROR]` line, not three: `Console.Error`
adds a source line and a caret, and a test failure does not go through it.

⚠️ **COMPILED ALGOL-24 DOES NOT CARRY SOURCE INFORMATION AT RUN TIME, and
that is a DECISION rather than a gap** — [ERR-003]. Carrying it means the
emitted C storing a position before every statement, which every program would
pay for so that a failing one could be read; the shadow stack's +5.8% for a
root per block is the nearest measured comparison. **What a program gets
instead is the machine**, which runs the same program and can disassemble it:
`--list`, `--trace N` and `--watch TEXT`. That is the division of labour
`algvm` exists for. The interpreter and the machine ARE expected to carry a
location and do not yet, which is a defect — `finished/PROPOSAL-RUNTIME-LOCATION.md`.

⚠️ **A RUNTIME ERROR NAMES ITS FILE AND LINE in the tree walker and the
machine, and NOT in compiled Algol-24** [ERR-003]. The location is a SECOND
line — `       at file:line` — and never part of the message, which is forced:
69 corpus cases print a caught message, 20 assertions here compare one exactly,
and the library has 38 handlers.

⚠️ **BOTH harnesses drop that line, and teaching only one cost 37
divergences.** `conform.sh` and `vm/conform.sh` keep separate copies of
`render()`, deliberately identical — so a rule applied to one must be applied
to the other. The processors are MEANT to differ here, so a location in one and
absent in another is agreement rather than divergence.

⚠️ **Each processor finds the location its own way, and the machine's is
free.** The tree walker publishes per statement (`Stmt` carries `Line`/`File`,
stamped at `Parser.Statement`, the one funnel); the machine **recovers it from
`IP`** where its dispatch loop catches a host error, so it pays nothing until
something fails. Its line table is SPARSE — an entry only where the line
changes, one pair per statement rather than clox's one per byte.

⚠️ **STDOUT IS FLUSHED BEFORE ANY DIAGNOSTIC NOW, and that reordered every
LOCATED one.** `Console.Error` writes its excerpt to stdout as the front end
fails and the `Uncaught:` sentence goes to stderr afterwards — so the excerpt
was always written first and only *appeared* second because it sat in a buffer.
[ERR-005] shows excerpt-then-sentence, which is what every other compiler
prints. 75 cases in the specification, one defect `.current` file and one prose
example were regenerated for it.

⚠️ **`bootstrap/algc` AND `vm/algvm` both link the hand-written `algol.c`, so
changing it means rebuilding BOTH.** Rebuilding only the compiler left the
machine on the old runtime, and `defects.sh` caught it where neither corpus did
— `vm/conform.sh` builds its own `algc` but uses the checked-in machine, so a
stale machine passes there and fails a three-way comparison.

⚠️ The file named is the **root**, not the file the failing test lives in. The
compiled runner copies that deliberately, since the reports are compared, and
`TestReport.RootFile` is where it comes from.

⚠️ **That is now the TEST REPORT only, and `SourceCode` no longer works that
way.** It used to hold one file's lines and one name, so a *located* diagnostic
named the root too — and the scanner for an imported file overwrote lines in
place without renaming, so the name and the quoted text could come from
different files. A `Token` carries its own `File` now, `SourceCode` keys a
record per file, and `Console.Error` reads the token's. [ERR-005],
`refusals/0199`.

⚠️ **An empty file name means the ROOT, and ONE function must answer that for
the write, the read and the printed name.** Resolving it on the read alone
stored a nameless scanner's lines under `''` and looked them up under the
root's, so every located diagnostic lost its source line — 36 cases, on the
MACHINE only, because `vm/run.a24` names its file to `Begins` rather than to
the `Scanner` while the compiler's own drivers name it to both. `conform.sh`
stayed green and `vm/conform.sh` went red, which is the pair worth running
together after touching this.

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
- A one-character literal is a **Char** and not a String — the TYPES differ,
  so `'a' is String` is false — but **the two are equal where the text is the
  same** [VAL-010]. `'a' = Copy ('abc', 0, 1)` is true, a Map keyed either way
  is reached by the other, and only differing text makes an equality fail.
  `Str(…)` still widens, and is still needed where a *type* is wanted.
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
- ⚠️ **ALL_CAPS is not a namespace.** Identifiers are case-insensitive
  [SRC-011], so a module-level `HIDDEN` and a local `var Hidden` are **one
  name** and the local wins — `HIDDEN.Put` then runs on whatever the local
  holds and reports `Undefined property 'Put'`, which reads like a type bug
  rather than a shadowing one. Give a module-level table a name no local would
  reach for: the underscores in `ENUM_NAMES` and `CLASS_PARENTS` are what has
  kept those safe, and single-word `HIDDEN` is what was not.
- ⚠️ **A written type name FOLDS, and `CanonicalType` is the one place that
  decides it.** A type is written as an identifier [TYP-002], so `integer` is
  `Integer` in a declaration, a parameter, a return type, a class header's
  parent and after `of`. This was a defect through v0.1.6 — `1 is integer` was
  true while `var X : integer` was refused — and the sharpest symptom was
  silent: gathering is decided by the written type being a `List` with an
  element type [FUN-005], so `list of Integer` did not absorb and the call
  failed as a wrong argument count. A diagnostic answers in the **canonical**
  spelling, which is [TYP-014]'s treatment of `Real` reaching case too.
- ⚠️ **A BUILT-IN's name folds too, and `CEmitter.Builtin` was the one table
  that did not.** It compared `Name + '/' + Count` against the canonical
  spellings as literals, so `writeln`, `STR`, `length` and `Clock` each missed
  the table, fell through to `MissingName` and became an
  `alg_error("Undefined variable ...")` stub — a latent abort in the C back end
  where both other processors answer. Eleven of eleven spellings tried. It bit
  unevenly, which is why it lasted: a built-in whose canonical spelling is the
  one people write never missed, and **`clock` is the only one spelt
  lower-case**, so writing the natural `Clock` was enough —
  `algol24-library`'s `graph.a24` had exactly that, waiting for a caller.
  `conformance/0215`.
- ⚠️ **Folding a table's keys means folding every READ, and missing one broke
  the next generation rather than this one.** `CEmitter` keys its class and
  singleton tables by name; folding the writes and five of six reads left every
  singleton reference emitting `alg_error("Undefined variable 'SourceCode'…")`
  into the generated C. Tests passed, the corpus passed, and `fixedpoint.sh`
  caught it — which is what it iterates for.
- ⚠️ **A Map keyed by a String WAS not reachable with a Char key, and that trap
  is gone.** Through v0.2.5 a field map used String keys while
  `Fields.Put ('n', 21)` keyed it with a **Char**, adding a SECOND entry while
  the String one still held nil — and the symptom read as the *reader* being
  broken, `MemberOf` answering nil for a field that was plainly there.
  Membership is equality [VAL-013] and the hash folds the two tags, so one key
  is now one entry whichever way it is written. Recorded because the shape of
  the old symptom is worth recognising in anything written before the change.
- ⚠️ **`Str (X)` does not give the checker a String when `X` is untyped.** The
  type does not propagate — `ToLower (Str (Thing.Field))` is an *untyped*
  expression, so a parameter declared `String` refuses it and the message is
  `Expected String, found an untyped expression`. `as String` is the fix, and
  it is the same cast the duck-typed passes already use for `as Set` and
  `as List`.
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
- **`ErrorLn` writes to the ERROR stream** [RT-030], taking any number of values
  and joining them exactly as `WriteLn` does — one call is one line. It flushes
  standard output first, so a program's own output cannot appear after a
  diagnostic written after it. It is how a program says something is wrong
  without corrupting what it produced; `raise` [STM-016] is how it fails.
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

**A nested subprogram calling a SIBLING nested one answers
`Undefined variable 'X'.` in the C back end**, and with no `external` involved
at all — `function Sized` and `function Ask` in one body, where `Ask` calls
`Sized`, compiles and then fails at run time. A wrong answer rather than one of
the back end's documented refusals, and the interpreter and the machine both
run it. Verified separately rather than assumed to be part of the nested-symbol
defects below, which are fixed: the same shape fails identically without a
foreign call in it.

⚠️ **It is what a nested-external case must avoid**, which is why
`conformance/0210` calls its externals where they are declared. A case that
reached through a sibling would turn `conform.sh` red for a different defect
than the one it pins.

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
