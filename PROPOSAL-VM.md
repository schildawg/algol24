# Proposal: A Bytecode VM

**From:** the language project. `vm/` has been reserved and empty since the
first commit, described as "a bytecode VM with a real GC".
**Status:** proposal, for decision. **Every number below was measured**, and the
programs that produced them are in `vm/spike/`.
**Concerns:** a third back end and a second binary — no change to the language

---

## The goal, stated narrowly

**`shroom-slots` runs as bytecode on a VM**, instead of being compiled to C. The
VM itself is compiled to C by the existing back end, so the VM is native and the
game is not.

⚠️ **This is not the same project as giving the AOT path a garbage collector**,
and the two are easy to conflate because both are "a real GC".

| | fixes memory for | which serves |
| --- | --- | --- |
| a GC **in the VM** | programs run as bytecode | this proposal |
| a GC **in `algol.c`** | programs compiled to C | `memory-management.md`'s refcounting |

A game that stays AOT-compiled gets nothing from this. A game that runs on the
VM gets a managed heap and gives up native speed. Which of those is wanted is
the decision this proposal exists to inform, and the measurements below are
what it turns on.

---

## What was measured

### The dispatch floor

Three million instructions, each an operand fetch, a stack write and a
decrement-and-branch. Every row compiled to C with `-O2` on the same machine,
and each figure is the **median of five runs**.

| | M instr/s | against today |
| --- | --- | --- |
| **direct, AOT to C** — what the game does now | **136** | 1× |
| VM, `case` dispatch, 4 opcodes | 12.7 | 11× slower |
| VM, `case` dispatch, hot arms 31st of 34 | **5.3** | **26× slower** |
| **VM, table of subprograms, 34 opcodes** | **11.9** | **11× slower** |

⚠️ **The first row is the noisy one** — 115 to 143 across five runs, because at
0.021 s it is short enough for the scheduler to matter. The three VM rows vary
by under 1%, which is the comparison this proposal actually rests on.

Two readings, and the second is the one that shapes the design.

⚠️ **`case` costs more the further down the arm sits**, because there is no
`CaseStmt` node: each arm becomes an `IfStmt`, and the C it emits is a chain of
`alg_truthy(alg_equal(alg_declared(…), alg_int(N)))`. Measured at 2.4× between
first position and thirty-first — 12.7 against 5.3. A sixty-opcode interpreter
written the obvious way would run at about a fifth of its achievable speed, and
get slower with every opcode added.

**A table of subprograms is O(1) in the opcode count** and needs nothing from
the compiler — `Handlers[Op] ()` is [FUN-011], subprograms as values, which has
worked since v0.1.0. It recovers nearly all of the loss — 11.9 against 12.7 —
and it would still be 11.9 with two hundred opcodes.

### What that buys at 60 frames a second

At 11.9 M instructions a second, a 16.67 ms frame holds about **198,000
bytecode instructions**.

And the rule of thumb that follows: if the game's Algol-24 work takes **T**
milliseconds a frame today, on the VM it takes about **11 × T**. So:

> **If `shroom-slots` currently spends under about 1.5 ms a frame in Algol-24
> code, it fits at 60 fps on the VM.**

⚠️ **That is the number this proposal cannot measure and the next step must.**
It is a `clock()` either side of the logic half of the frame loop on the AOT
build, excluding the SDL present. Nothing else about the design matters until it
is known.

**A foreign call is one instruction, and that is what makes the budget
plausible.** `Foreign` is already a five-argument built-in mapped to
`alg_foreign_call`, so a `CALL_C` opcode costs one dispatch and then runs at
native speed. A blit taking 200 µs inside SDL costs the VM a single
instruction. The game is SDL-bound rather than logic-bound, so the 11× applies
to the cheap half of its frame.

### Why the AST is the memory problem, and where it goes

| | |
| --- | --- |
| source — `compiler/*.a24`, 21,258 lines | 0.65 MB |
| **peak RSS, front end and AST only** | **35 MB** (3 MB baseline) |
| peak RSS, front end and emit | 64 MB |
| emitted C, for scale | 1.2 MB |
| **peak RSS, the same AST *executing* its tests** | **1731 MB** |

So the AST is roughly **fifty times the source**, and against a bytecode
artifact it would be thirty to a hundred times. None of it can be given back:
`algol.c` has **49 `arena_alloc` sites and no frees**.

⚠️ **A GC in the VM cannot reclaim the AST**, because the AST is not on the VM's
heap — it is in the compiler's arena, which has no notion of release. Nor can
regions: mark-and-rewind is frame-scoped, and "free the tree but keep the
bytecode built from it" is not a frame.

**Process exit is the only garbage collector the front end has.** Which is the
argument for persisting bytecode — not caching:

```
algc --emit prog.a24 -o prog.a24c    builds the AST, writes bytecode, EXITS
algvm prog.a24c                      loads bytecode; memory is the managed heap
```

The 1731 MB row is the thing the VM is for. The 35 MB row is the thing the
process boundary is for.

### Where a heap can live

**`Buffer` is the only freeable memory in the language.** `Free` calls C's
`free`, `Resize` reallocs, and byte access plus `PutInt`, `PutWord`,
`PutDouble`, `GetWord` and `GetDouble` give a byte-level representation. Every
other allocation comes from the arena.

⚠️ **So the VM's heap must be Buffers it manages itself** — its own free lists,
its own object headers. If VM objects are Algol-24 instances, the collector is
decorative: it would mark and sweep while the memory underneath grew forever,
which is the problem the VM exists to solve.

There is a convergence worth noting: the byte primitives the library asked for
in v0.1.6 to encode a record are exactly the primitives a byte-level heap needs.

---

## The proposal

### 1. A third back end, not a second front end

```
Scanner → Parser → Resolver → TypeChecker → ┬→ Interpreter  (tree-walking)
                                            ├→ CEmitter     (C11)
                                            └→ VmEmitter    (bytecode) → algvm
```

The interpreter stays the authority [1.1]. A VM divergence is a **gap**, exactly
as a compiler gap is today, and `conform.sh --lenient` already has the
vocabulary for it. That is deliberately the same structure that has worked for
two back ends rather than a new one.

### 2. One front end, because single-pass cannot express the language

`clox` emits bytecode as it parses, so its AST exists only as the shape of
`parsePrecedence`'s recursion, written down in postorder as that recursion
unwinds. It can do that because **Lox defers to run time everything it cannot
settle in one pass** — globals are `OP_GET_GLOBAL` with a string constant and a
hash lookup — and because Lox has no overloads and no type checker.

Algol-24 cannot defer its equivalents, because they are decisions rather than
lookups:

| | needs |
| --- | --- |
| `CollectDottable` | every object in the program, before the first expression |
| `CollectExtensions` | every extension, so a call may stand above its declaration |
| `ObjOverloads.Select` | the whole overload set, program-wide [FUN-013] |
| `MapType` | every class's members, before any expression is reduced |

⚠️ **DEF-35 is in the defect list precisely because one corner is still
effectively single-pass.** Adopting single-pass would be adopting that defect as
the architecture.

What to take from `clox` is the mechanism rather than the structure:
**backpatching** (`emitJump` writes `0xffff` and `patchJump` fills it in) is
exactly what `VmEmitter` needs for `if`, `while`, `case`, `break`, `continue`
and `goto`, and **postorder emission** over the AST produces the same bytecode
`clox` gets from its call stack.

### 3. Port the back half of `zlox`, not the whole of it

`chunk`, `value`, `obj`, `table`, `vm`, `gc`. The front half — `scanner`,
`compiler` — is replaced by the existing front end plus `VmEmitter`, which keeps
the project's own invariant: *a program that fails to parse must fail
identically whichever back end is asked for.*

### 4. Dispatch through a table from the first opcode

Not a `case`. Writing it as a `case` and converting later means rewriting the
core of the VM once it holds sixty opcodes.

### 5. Build it against the existing corpus

259 conformance cases with byte-exact expected output, already run under two
processors by a harness built to compare them. A third column is nearly free,
and the VM has a real acceptance suite from its first opcode.

⚠️ **Necessary and not sufficient.** The corpus tests language semantics; it
cannot see GC correctness under pressure, deep recursion, stack exhaustion or
bytecode round-tripping. Those want tests of their own, and they are where VMs
actually break.

---

## What the spike does not establish

- **The instruction mix.** The measured instructions are cheap ones. Real
  opcodes doing `alg_add` on tagged values, string interning, property lookup
  and call frames cost more each. 11.9 M is the dispatch floor rather than a
  prediction of the mix.
- **GC pause behaviour**, which for a 60 fps game is as important as throughput
  and is not a throughput question.
- **The heap design.** That Buffers *can* hold a heap is measured; that a
  collector over them performs is not.
- **The gap between Lox and Algol-24.** Lox has no exceptions, enumerations,
  subranges, five collections, operators on classes, properties, gradual
  run-time type checks, foreign calls, unbounded integers, or **run-time
  overload selection on the whole signature** — which is the one genuinely
  hostile to a bytecode design. A Lox-shaped VM is perhaps a third of the way;
  the rest is the interesting work.

---

## Open questions

1. **Does the game fit?** The 1.4 ms threshold above. Everything else is
   premature until this is measured.
2. **Does `algvm` ship as a second binary, or as a mode of `algc`?** A mode
   keeps one artifact and pays the 35 MB; a second binary gets the process
   boundary that makes the memory argument work.
3. **Is the bytecode file a committed artifact?** If it is, it is a second seed,
   with a version stamp and a staleness check. If it is not, `--emit` is a build
   step every program needs.
4. **What is the object representation?** `clox` offers NaN-boxing and a tagged
   struct. NaN-boxing wants fixed-width 64-bit bit manipulation; an Algol-24
   Integer is unbounded, so the tagged form is the likely answer — but it is the
   decision the heap design hangs on.
5. **Does `case` get a jump table in `CEmitter`?** Worth about 6% to a
   table-dispatched VM — 12.7 against 11.9 — so not a prerequisite — but it
   would make the obvious
   way to write a dispatch loop also the fast way.
6. **Overload selection.** Resolved per call site at emit time where the types
   are known, or an opcode that selects at run time as the interpreter does?
   [EXP-013] requires the latter where types are not known.

---

## What this does not ask for

- **No change to the language.** Table dispatch is [FUN-011], the foreign opcode
  is the existing `Foreign` built-in, the heap is `Buffer`. Nothing here needs a
  new rule.
- **Not a replacement for the tree-walking interpreter.** It stays the
  authority.
- **Not a replacement for the C back end.** AOT to native stays the way to ship
  a program that needs native speed.
- **No bytecode specification.** The opcodes are proposed after a Lox-shaped VM
  runs, which is the order that lets the corpus judge each one.

---

## Appendix: how the evidence was gathered

Everything above came from running the language, not from reading it. The four
dispatch rows are `vm/spike/direct.a24`, `vm.a24`, `vm60.a24` and
`vmtable.a24`, each compiled with `algc --compile` and `cc -std=c11 -O2`, timed
with the `clock()` built-in over three million instructions and reported as the
median of five runs. The memory rows are
`/usr/bin/time -l` over `algc compiler/Main.a24`, `algc --compile … Main.a24`
and `algc --test compiler/Main.a24`. The arena figures are counted in
`bootstrap/algol.c`; that `Buffer.Free` calls `free` is read from
`buffer_method`. `Foreign`'s arity and its mapping to `alg_foreign_call` are
read from `Interpreter.a24` and `CEmitter.a24`. The `clox` mechanisms are quoted
from `~/projects/clox/compiler.c`.
