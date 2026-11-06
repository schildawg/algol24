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

  ⚠️ **`OP_PROPERTY` and `OP_GET_FIELD` have BYTE-IDENTICAL handlers**, which
  writing the reference is what surfaced: both read a name from the constants,
  pop a value and push what the one shared `MemberOf` answers. So they are one
  operation and the difference is what the emitter meant, not what the machine
  does. Whether both should exist is open; neither entry pretends otherwise.

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
  `OpStack` declares `pops pushes needs` for all 78 opcodes, `vm/reference.sh`
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

  ⚠️ **The SPLIT between pops and pushes is unobservable, and that is settled
  rather than assumed.** Popping a value and pushing two copies moves the stack
  exactly as reading it and pushing one does — checked with distinct sentinels,
  which showed slot 0 holding the same value either way. So the split says what
  the handler is written to mean and nothing can hold it to that; the
  difference and the depth are what the tests assert. `1 2 1` for `OP_DUP`
  still passes, and the doc comment says so.

  ⚠️ **Three traps in one small test, all of them in CLAUDE.md already.**
  `Set` takes a COLLECTION and not members, so `Set (A, B, C)` is
  `Expected 0 or 1 arguments but got 3.`; a one-character literal is a **Char**
  and never equals the String `Copy` answers, so a set of bare `'0'` matched
  nothing; and a second top-level `StackTerm` in `Vm.a24` clashed with the one
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
  second.** The interpreter looks the variable up and reaches for `this` only
  when that *raises* (`ThisField`), so a global of the name wins over a field
  of it — and if the field is missing too it re-raises the ORIGINAL
  undefined-variable message. The emitter decides it statically instead: not a
  local, not a capture, not a visible global, and a member of the class being
  compiled. `VisibleSlot` exists as a question separate from `BareSlot`'s
  answer because a field WRITE must put the receiver on the stack before the
  value, so it cannot be decided after the value is already there.

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
  four increments. There is a test for contiguous *and* unique, and the fix is
  a script that renumbers every opcode from its position in the file.

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

  ⚠️ **The remaining gap is a TEMPORARY, not a local.** An intermediate inside
  one expression — the list in `[MakeList (), Collect ()]` — is in no local and
  registered nowhere. It is reachable only by a collection that happens partway
  through evaluating an expression.

  ⚠️ **A Buffer AND a TextFile are exempt from the sweep, because both are on
  a list the runtime walks.** `all_buffers` and `all_files`. Only the Buffer was
  exempt, so a released `ObjFile` stayed linked with its `next` overwritten by
  `obj_release`'s free-list link — and `close_open_files` walked in a circle at
  exit, finding the handle already NULL every pass. Twenty-six minutes of spin
  on one run, every collecting run, never the baseline. The price of exempting
  rather than unlinking is that an abandoned TextFile is not reclaimed until the
  process ends.

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

  ⚠️ **A class declared INSIDE a subprogram is still a wrong answer.** The
  survey walks top-level statements and `ModuleStmt`s, so such a class is in no
  member table and a bare field read inside its method reports
  `Undefined variable`. The interpreter answers it. Not a refusal, which is
  what makes it worth writing down.

  ⚠️ **A guest object renders through `ToString`, and without one the host
  says `<Class> instance`.** `as_text` invokes a `ToString` it finds, which is
  why `Str (Green)` was right while `WriteLn ([Red, Green])` printed
  `[VmEnum instance, VmEnum instance]` — the machine answered `Str` itself and
  never gave the host anything to render. One method on `VmEnum` and one on
  `VmEnumType` fixes a member inside a collection, inside a diagnostic and on
  its own at once. Any machine object a program can see needs one.

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

  ⚠️ **The frame budget is MEASURED on the machine now, and the Inn misses 30
  fps.** A played session — 4,941 frames in 196.4 s with automatic collection
  on — runs at **39.75 ms a frame, 25 fps**, which is **119% of a 30 fps
  frame**. Quote that, not a short run: 30 frames reads 19–21 fps because the
  first frames dominate, and the game's own `frames`/`rate` lines are the only
  honest source.

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

  ⚠️ **A third finding is a decision, not a repair**, and it is the only one
  that helps the VM more than the AOT path: writing just the dispatch loop in
  C, over handlers that stay in Algol-24, measured a further **1.7×** and takes
  the VM to CPython parity. The real frame makes it **more** load-bearing than
  the projection did, not less — the old text said the Inn was at 94% of a 30
  fps frame without it, where the measurement says 119%, so it is the
  difference between missing 30 fps and clearing it. **If** the 1.7× held it
  would be 23.4 ms, 70% of a 30 fps frame; that factor came off a FOUR-OPCODE
  toy (`vm/spike/vmtable.a24`), so treat it as a reason to try rather than as a
  number. There is no barrier at the emitted-C level — a generated subprogram
  is already an ordinary C function — so what it would need is linkage, and
  `vm/spike/cdispatch.py` demonstrates it by patching a compiled variant. The
  catch is that giving C a stable name to call **freezes the `Value **cells,
  Value *args, int32_t count` calling convention**, which is private today and
  has changed before.

## The collector

⚠️ **`Collect ()` is a REQUEST [RT-029], and the two processors answer it
differently by the rule rather than against it.** The interpreter answers `0`
— its live values sit in C locals all through a recursive evaluator, where no
collector can see them, so releasing would free something still in use. The
compiled back end and the bytecode machine release. A program may depend on
neither the count nor on anything being freed: `Collect` changes how much
memory a correct program uses and never what it computes.

⚠️ **AUTOMATIC collection is wired and still OFF by default, but no longer
because it is unsafe — that claim is DISPROVEN and the default has simply not
been revisited.** `Vm.a24` collects at a safe point: the top of the dispatch
loop, after an instruction has finished, where every live guest value is on
`Slots` or in a module-level variable.

The note this replaces said the Inn failed under it as
`Only instances have properties.` or blocked outright, and that the root set
had a gap the corpus did not reach. Measured again on 2026-11-04 at four
intervals — `--collect` 5,000,000, 2,000,000, 200,000 and 20,000 — the Inn
**closes cleanly every time**, and at **3,000 frames** with the 200,000
interval its output is line-for-line identical to a run with no collection at
all. Most likely the gap was closed by the precise-roots and shadow-stack work
that landed after the note was written, which is exactly the missing-root class
it was describing.

⚠️ **What that does NOT license is flipping the default**, which is a
behavioural change rather than a documentation one, and the evidence has a
shape worth knowing: a SCRIPTED walk (`--push 0 -1`), headless video, one path
through the game. A played session touches more. `--collect N` on `vm/run.a24`
turns it on; an explicit `Collect ()` is unaffected and works either way.

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

⚠️ **A Buffer is never swept.** Its bytes are malloc'd, it is on a list of its
own, and `Free` releases it explicitly. An object the language can already
release is not the collector's business.

**Two kinds of memory the sweep cannot return yet.** An instance's `slots` is
allocated at exactly its field count rather than a size class, so
`seq_recycle` declines it — 206 MB of the compiler's arena. And a Map's `index`
is an `int32_t` array, a different element size from the `Value` blocks the
spare lists keep.

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

## The six harnesses

All six must pass. They are the definition of done.

```sh
./test.sh          # the unit tests, inline in the source they cover
./conform.sh       # the corpus, under BOTH processors
./spec/spec.sh     # every rule cites something that exists
./fixedpoint.sh    # the seed matches what the compiler emits, and emits itself
./docs.sh          # every unit is documented per spec/DOCUMENTATION.md
./collector.sh     # the collector keeps what a program holds, both ways
```

Each prints its own totals. **Do not copy those totals into this file or the
README**: every count written down here has gone stale, and a number in prose is
a claim nothing checks.

⚠️ **`./collector.sh` runs the COMPILED back end only, and that is the rule
rather than an omission.** `Collect` is a request [RT-029]: the interpreter
answers 0 because its live values sit in C locals all through a recursive
evaluator, so declining is its conformant answer and there is nothing to
compare against. `conform.sh` is where the two processors are held to each
other.

⚠️ **Every collector case runs TWICE — plainly and under `ALG_POISON=1`** —
because that split *is* the diagnosis. Poisoning withholds a released body
instead of reusing it, so a case that passes one way and fails the other says
whether marking or reuse is at fault. Three bugs in the hunt that produced
these cases had exactly that signature.

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
  parent and after `of`. This was a defect until v0.1.6 — `1 is integer` was
  true while `var X : integer` was refused — and the sharpest symptom was
  silent: gathering is decided by the written type being a `List` with an
  element type [FUN-005], so `list of Integer` did not absorb and the call
  failed as a wrong argument count. A diagnostic answers in the **canonical**
  spelling, which is [TYP-014]'s treatment of `Real` reaching case too.
- ⚠️ **Folding a table's keys means folding every READ, and missing one broke
  the next generation rather than this one.** `CEmitter` keys its class and
  singleton tables by name; folding the writes and five of six reads left every
  singleton reference emitting `alg_error("Undefined variable 'SourceCode'…")`
  into the generated C. Tests passed, the corpus passed, and `fixedpoint.sh`
  caught it — which is what it iterates for.
- ⚠️ **A Map keyed by a String is not reachable with a Char key.** A field map
  uses String keys, and `Fields.Put ('n', 21)` keys it with a **Char**
  [TYP-003] — adding a SECOND entry while the String one still held nil. Both
  `Contains ('n')` and `Contains (Str ('n'))` then answer true about different
  entries, and the symptom reads as the *reader* being broken: `MemberOf`
  returned nil for a field that was plainly there. `Str ('n')` is the key.
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
