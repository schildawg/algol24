# Proposal: A Bytecode VM

**From:** the language project. `vm/` has been reserved and empty since the
first commit, described as "a bytecode VM with a real GC".
**Status:** proposal, for decision. **Every number below was measured**, and
`vm/spike/measure.sh` reproduces every one of them.
**Concerns:** a third back end and a second binary — **no change to the
language**, item 0b included, which was checked rather than assumed.

---

## The goal, stated narrowly

**`shroom-slots` runs as bytecode on a VM**, instead of being compiled to C. The
VM itself is compiled to C by the existing back end, so the VM is native and the
game is not.

⚠️ **Measured, that means 30 frames a second for the Dew Drop Inn and 60 for
the reel engine** — see *Does the game fit?*. Whether 30 is acceptable for a
walking-and-dialogue game is a design question this proposal cannot settle, and
it is now the decision everything else waits on.

⚠️ **This is not the same project as giving the AOT path a garbage collector**,
and the two are easy to conflate because both are "a real GC".

| | fixes memory for | which serves |
| --- | --- | --- |
| a GC **in the VM** | programs run as bytecode | this proposal |
| a GC **in `algol.c`** | programs compiled to C | `PROPOSAL-GC.md` |

A game that stays AOT-compiled gets nothing from this. A game that runs on the
VM gets a managed heap and gives up native speed. Which of those is wanted is
the decision this proposal exists to inform, and the measurements below are
what it turns on.

---

## What was measured

### The dispatch floor

A loop of three instructions — an operand fetch, a stack write and a
decrement-and-branch — run tens of millions of times. Every row compiled with
`cc -std=c11 -O2` on the same machine, each figure the **median of five runs**,
and every row sized to take at least a second: an earlier draft of this table
had rows that finished in six milliseconds and measured the scheduler rather
than the loop.

| | M instr/s | against today |
| --- | --- | --- |
| **direct, AOT to C** — what the game does now | **140** | 1× |
| VM, `case` dispatch, 4 opcodes | 12.5 | 11× slower |
| VM, `case` dispatch, hot arms 31st of 34 | **5.3** | **26× slower** |
| **VM, table of subprograms, 34 opcodes** | **12.0** | **11.7× slower** |

Two readings, and the second is the one that shapes the design.

⚠️ **`case` costs more the further down the arm sits**, because there is no
`CaseStmt` node: each arm becomes an `IfStmt`, and the C it emits is a chain of
`alg_truthy(alg_equal(alg_declared(…), alg_int(N)))`. Measured at 2.4× between
first position and thirty-first — 12.5 against 5.3. A sixty-opcode interpreter
written the obvious way would run at about a fifth of its achievable speed, and
get slower with every opcode added.

**A table of subprograms is O(1) in the opcode count** and needs nothing from
the compiler — `Handlers[Op] ()` is [FUN-011], subprograms as values, which has
worked since v0.1.0. It recovers nearly all of the loss — 12.0 against 12.5 —
and it would still be 12.0 with two hundred opcodes.

### Where that sits against other languages

The 11.7× above is a ratio against this project's own AOT path, which says
nothing about whether the result is fast. Two outside reference points, the same
loop on the same machine:

| | M iter/s | against CPython |
| --- | --- | --- |
| C, the loop written directly | 3484 | 205× faster |
| C, a bytecode VM over the same three opcodes | 697 | 41× faster |
| Algol-24, AOT to C | 46.7 | **2.7× faster** |
| **CPython 3.12** | **17.0** | — |
| Algol-24, on the table-dispatch VM | 4.00 | **4.3× slower** |

**Algol-24 compiled to C is already faster than CPython**, which is the context
the 11.7× was missing. The VM would land a few times below CPython rather than
in a different class from it — and the next section is why that gap is smaller
than it looks, and mostly recoverable.

### Why the VM is slower than CPython, and by how much

⚠️ **The VM is not slower because it executes more instructions. It executes
far fewer.** CPython needs **11 bytecodes** per iteration of that loop —
disassembled, `LOAD_FAST`/`LOAD_CONST`/`BINARY_OP`/`STORE_FAST`/`COMPARE_OP`/
`POP_JUMP_IF_FALSE`/`JUMP_BACKWARD` — where this VM needs **3**, because
`DECJNZ` does the work of five of them.

| | bytecodes/iteration | ns per dispatch |
| --- | --- | --- |
| C bytecode VM | 3 | 0.5 |
| CPython 3.12 | 11 | **5.3** |
| this VM, today | 3 | **83** |

So each dispatch costs about **16× what CPython's does**, and a denser
instruction set claws back 3.7× of that. The net 4.3× is what survives.

The reason each dispatch costs so much is visible in the emitted C. This is the
whole dispatch loop as `CEmitter` writes it today:

```c
while (alg_truthy((alg_declared(d_running, "Running"), v_running))) {
    Value v_op = alg_cast(alg_subscript_get((alg_declared(d_code, "Code"), v_code),
                                            (alg_declared(d_ip, "IP"), v_ip)), "Integer");
    (void)((alg_declared(d_ip, "IP"), (v_ip = alg_add((alg_declared(d_ip, "IP"), v_ip), alg_int(1)))));
    (void)(alg_call(alg_subscript_get((alg_declared(d_handlers, "Handlers"), v_handlers), v_op), NULL, 0));
}
```

**Thirteen calls into `algol.c` per dispatch**, before the handler body runs —
and `build.sh` compiles with `-std=c11 -O2` and no `-flto`, so `algol.c` is a
separate translation unit and **not one of them can be inlined**. Each is doing
real work:

| | per dispatch |
| --- | --- |
| `alg_declared(d_ip, "IP")` | a definite-assignment check carrying the variable's **name as a string**, six times, for variables the Resolver already knows are assigned |
| `alg_subscript_get` | runtime tag dispatch over Map → Buffer → Set → Seq → Text before it can index |
| `alg_cast(…, "Integer")` | `subrange_of()`'s linear scan, then `alg_stricmp(type_name(v), "Integer")` — **a string comparison** |
| `alg_add` | tagged add, both tags switched on, overflow-to-unbounded checked |
| `alg_call` | indirect call through a tagged closure value, arity checked, frame pushed |

⚠️ **Boxing is not the difference.** CPython boxes integers as `PyObject*` with
refcounts and Algol-24 boxes them as tagged `Value`; the costs are comparable.
The difference is that **CPython's interpreter loop is hand-written C and this
one is Algol-24 compiled to C**, so the VM pays a second full layer of exactly
the tax it exists to implement. It is a bytecode interpreter whose own
interpreter loop runs at interpreted speed.

### What that costs, measured, and what removes it

Each row adds to the one above it. Same loop, median of five, every row over a
second:

| | M instr/s | VM | M op/s | AOT |
| --- | --- | --- | --- | --- |
| today, `-O2` | 12.00 | 1× | 140.01 | 1× |
| **+ `-flto`** | 14.83 | 1.24× | 198.85 | 1.42× |
| + widening elided where provably the identity | 22.13 | 1.84× | 495.05 | 3.54× |
| + `as T` resolved at emit time | 32.17 | 2.68× | — | — |
| **+ the dispatch loop itself written in C** | **54.91** | **4.58×** | — | — |

Three changes. The first two **touch neither the VM's design nor the language's
semantics**; the third is a design decision and is proposed separately as
item 0b.

**1. `-flto`, which is a build flag and nothing else.** Worth 24% to the VM
dispatch loop and 42% to the AOT spike. It also makes a separate emitter
optimisation unnecessary: eliding `alg_declared` at emit time measured within 3%
of LTO's own figure, because once the call is inlined the optimiser proves
`defined` is a known-true local by itself. The Resolver's knowledge was already
in the emitted C; only the translation-unit boundary was hiding it.

⚠️ **The 42% does not generalise, and an earlier draft of this document claimed
it did.** LTO removes the *call overhead* of crossing into `algol.c`; where the
callee does real work the overhead is a small fraction of it. Measured on this
compiler's own workloads:

| | LTO gain |
| --- | --- |
| the AOT spike — a tight arithmetic loop | **42%** |
| the VM dispatch loop | **24%** |
| `algc --test compiler/Main.a24` — allocation, maps, strings | **3%** |
| `algc --compile compiler/Main.a24` — buffer-heavy | **1%** |

So the flag is worth taking because it is free, and it is worth 24% *to a
dispatch loop specifically* — which is a tight loop of cheap operations and
therefore the shape that benefits. **What `shroom-slots` would gain is unknown
and probably nearer the 3% than the 42%**, and this document should not have
said otherwise.

**2. Eliding the vacuous guards at emit time.** `BoundValue` skips `alg_widen`
only when the declared type is `''` or `Any`, so a *fully annotated* program
pays for a conversion that provably cannot happen — and `ReduceBinary` ends
`if Left = Right then Exit Left;`, which means `Integer + Integer` really does
reduce to `Integer` and the elision is statically provable. The same holds for
`as T`: the checker knows `Code[IP]` where `Code : Buffer` yields an Integer,
and the emitter emits a `strcasecmp` anyway. Dropping **one** such cast from the
dispatch loop was worth 45%.

⚠️ **Gradual typing is currently backwards at the machine level: annotating a
variable makes the emitted code *slower*, not faster.** The untyped rows are the
fast ones above because `BoundValue` emits nothing for them. [VAL-001] does not
require that, and the premise of gradual typing — that a fully annotated program
behaves like a statically typed one — is exactly what these two fixes would
deliver.

**3. The dispatch loop in hand-written C, over the same Algol-24 handlers.**
Worth **1.7× to 2.0× at every point in the ladder**, and it stacks with the
other two:

| handlers | Algol-24 dispatch | C dispatch | |
| --- | --- | --- | --- |
| typed, `-O2` | 12.00 | 23.83 | 1.99× |
| typed, LTO | 14.83 | 30.26 | 2.04× |
| widening elided, LTO | 22.13 | 42.88 | 1.94× |
| **both elisions, LTO** | **32.17** | **54.91** | **1.71×** |

The multiplier *shrinks* as the other fixes land, which is the expected
direction: the elisions cheapen the dispatch loop too, so there is less left for
C to remove.

What C removes is specific. Per bytecode, the Algol-24 loop does
`alg_subscript_get(Handlers, Op)` and then `alg_call`, which walks six `is_obj`
tag checks — class, bound method, overload set, builtin-bound, extension —
before it reaches a plain closure. A C loop calls `f_dopushi(NULL, NULL, 0)`
directly, and touches `v_ip.integer` as a plain struct field rather than through
`alg_declared`/`alg_cast`/`alg_widen`/`alg_add`.

⚠️ **It is a bounded win, not a slope.** Caching the bytecode in a C array on
top of the C loop added only 6% more, which locates the remaining cost in the
**handler bodies**: `f_dopushi` is still an `alg_subscript_set` over an
`alg_cast` of an `alg_subscript_get`, plus two `alg_widen(alg_add(…))`. The
further ~38× to the hand-written C VM lives there, and moving it is just writing
the VM in C.

### Where that leaves the VM

| | M iter/s | against CPython |
| --- | --- | --- |
| Algol-24 AOT, both emitter fixes | 165.0 | 9.7× faster |
| Algol-24 AOT, today | 46.7 | 2.7× faster |
| **Algol-24 VM, all three fixes** | **18.3** | **1.08× faster** |
| **CPython 3.12** | **17.0** | — |
| Algol-24 VM, the two emitter fixes | 10.7 | 1.6× slower |
| Algol-24 VM, today | 4.00 | 4.3× slower |

**With all three, the VM reaches CPython parity.** That is the single most
decision-relevant number in this document: a bytecode VM for this language is
not condemned to be an order of magnitude below a mainstream interpreter.

⚠️ **The two emitter fixes WIDEN the gap between the back ends; only the C
dispatch narrows it.** They help straight-line code more than they help a
dispatch loop, because straight-line code is almost entirely the calls being
elided:

| | AOT : VM |
| --- | --- |
| today | 11.7× |
| the two emitter fixes | **15.4×** — worse |
| + C dispatch | **9.0×** — better |

So the two fixes that cost nothing and help everything are the ones that make
the VM look *worse* by comparison, and the one that helps only the VM is the one
that needs a design decision. Item 0 and item 0b are worth weighing separately
for exactly that reason.

### What that buys at 60 frames a second

| | per 16.67 ms frame |
| --- | --- |
| at 12.0 M instr/s, today | ~200,000 bytecode instructions |
| at 32.2 M instr/s, the two emitter fixes | ~536,000 bytecode instructions |
| **at 54.9 M instr/s, all three** | **~915,000 bytecode instructions** |

### Does the game fit? Measured, and the answer is no at sixty

This proposal used to say the frame cost was the one number it could not measure
and the next step must. It has now been measured, with `clock()` either side of
the frame loop's body in `shroom-slots` — stopping before `S.Present ()`, so the
window is the game's own work and not the driver's — over 1,200 frames of each
program.

⚠️ **The reel engine and the Dew Drop Inn are not the same program, and the Inn
is the one that decides this.** The machine is the reel engine; the Inn is the
game.

| | Algol-24 logic and draw, per frame |
| --- | --- |
| `play` — one machine, the reel engine | **0.74 ms** |
| **`inn` — the Dew Drop Inn** | **2.32 ms** |

Of the Inn's 2.32 ms, the part a VM would multiply is smaller, because a foreign
call costs one dispatch and then runs at native speed. Timed inside
`alg_foreign`, excluding the present and the frame cap:

| | |
| --- | --- |
| the frame window | 2.32 ms |
| of which foreign — SDL, 215 calls a frame | **0.31 ms** |
| **the Algol-24 remainder, which is what gets multiplied** | **~2.01 ms** |

Against the measured AOT-to-VM ratios:

| | VM frame cost | at 60 fps | at 30 fps |
| --- | --- | --- | --- |
| the two emitter fixes — 15.4× | **31.3 ms** | 188% — no | 94% — no headroom |
| **all three, with the C dispatch — 9.0×** | **18.4 ms** | **110% — no** | **55% — yes** |

> **The Dew Drop Inn does not fit at 60 fps on the VM, with or without the C
> dispatch. It fits comfortably at 30. The reel engine fits at 60 either way —
> 0.74 ms becomes 6.7 ms, two fifths of a frame.**

⚠️ **This makes item 0b load-bearing rather than an optimisation.** Without the
C dispatch the Inn sits at 94% of a 30 fps frame, which is not a budget. With
it, 55%.

⚠️ **And it corrects a claim this document made twice: the game is NOT
SDL-bound.** Foreign calls are **0.31 ms of 2.32**, or 13% — so the multiplier
applies to seven eighths of the frame rather than to "the cheap half" as an
earlier draft had it. `CALL_C` being one instruction is still true and still
matters; it is simply not what makes the budget work.

⚠️ **Treat the multiplier as an estimate.** The 9.0× and 15.4× come from a tight
integer loop. The Inn's own profile is string- and allocation-heavy — `concat`
is its largest single allocation site — and on the VM strings would go through
its own `ObjString` rather than Algol-24's, so the ratio could move either way.
**Measuring the ratio on a representative mix rather than a loop is the next
refinement**, and it is the only remaining number that could change the verdict
above.

**One correction of detail:** an `external` declaration is emitted as a call to
`alg_foreign`, not to the `alg_foreign_call` this document previously named.
`alg_foreign_call` is the dynamic `Foreign` built-in, which `shroom-slots` does
not use — measured at zero calls across 1,200 frames. A `CALL_C` opcode would
target `alg_foreign`.

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

**And the VM's own memory is not part of this problem, which is what makes the
split clean.** Measured on `vmtable.a24` by linking it against an instrumented
`algol.c`: running 300,000, 3,000,000 and 12,000,000 instructions each hands out
**zero** arena bytes beyond startup. The whole footprint is **41 allocations and
about 2 KB** — the bytecode Buffer, two list headers and their arrays, one
closure per handler — and it is flat in instruction count.

So the division is `clox`'s, exactly:

| | |
| --- | --- |
| **the VM's own** stacks, tables and frames | bounded, allocated once; never freeing 2 KB is not a problem |
| **the guest's** objects | unbounded and unknowable to the VM, so `Buffer`s with the VM's own free lists and headers |

⚠️ **A handler must therefore never create an Algol-24 object on the guest's
behalf**, or a guest value has leaked into the host arena where nothing can
reclaim it. That boundary is testable by the measurement above — **an arena
flat in instruction count is the invariant** — and `PROPOSAL-GC.md` proposes
making it a harness.

⚠️ **A collector in `algol.c` does not replace any of this**, and a draft of
`PROPOSAL-GC.md` claimed it did. It would serve programs whose live set is
bounded while their allocation is not — `algc` itself, measured at 1,147 MB —
which is a different population from either row above.

---

## The proposal

### 0. Do the two cheap fixes first, whichever way this goes

`-flto` in `build.sh`, and eliding `alg_widen` and `alg_cast` where the checker
has already proved them vacuous. Measured above at 2.68× for a VM and 3.54× for
the AOT path.

⚠️ **This is the one item here that cannot be wasted.** It speeds up
`shroom-slots` as it ships today, it raises the VM's ceiling if the VM is built,
it makes `algc` itself faster, and it is the difference between gradual typing
rewarding annotation and punishing it. It also changes the decision this
proposal exists to inform, by moving the VM from 4.3× below CPython to 1.6×
below it — so it belongs **before** the decision, not after.

It needs no new rule, no corpus change, and no agreement about the VM.

### 0b. The dispatch loop in C, over Algol-24 handlers

The remaining 1.71×, and unlike item 0 this is a decision rather than a repair.
It is what takes the VM to CPython parity, and it is the only measured change
that narrows the gap to the AOT path.

⚠️ **It is also load-bearing rather than optional, which the frame measurement
settled.** Without it the Dew Drop Inn sits at 94% of a 30 fps frame — not a
budget. With it, 55%. So this item is not a late optimisation to weigh on its
merits; it is a prerequisite for the Inn running on the VM at all.

**What it is.** `vm/*.a24` holds the handlers, the object model and the
collector — every opcode's *meaning* stays in Algol-24. A hand-written
`vm/dispatch.c` of roughly fifteen lines holds the loop: fetch the opcode,
advance `IP`, `switch`, call the handler. It compiles alongside the emitted C
exactly as `algol.c` already does, so the build story is untouched — still
nothing but a C compiler.

⚠️ **It needs no change to the language, and an earlier draft of this document
proposed one before checking.** A top-level subprogram of a *unit* that is not
private **already** has external linkage and already appears in that unit's
generated header, because that is the mechanism by which one unit's C calls
another's. `Exported()` in `CEmitter.a24` decides it and `Prototype` drops the
`static`. So there is nothing to add — no `export` marker, no new rule, no
reseed.

`vm/spike/fromc/` demonstrates it end to end and `vm/spike/fromc/run.sh` runs
it. A unit declaring `Twice` and `SumTo` emits this header:

```c
Value f_twice(Value **cells, Value *args, int32_t count);
Value f_sumto(Value **cells, Value *args, int32_t count);
extern Value fn_twice;
extern Value fn_sumto;
void init_Hot(void);
```

and a hand-written `caller.c` that includes it calls `f_twice(NULL, &argument,
1)` directly, or `alg_call(fn_twice, &argument, 1)` to go through the closure
value the way a handler *table* would. Both answer what the interpreter does.

**Three things the spike establishes that are easy to get wrong:**

| | |
| --- | --- |
| `init_<Unit>()` must run first | nothing in a unit is initialized until it does, and a generated `main` calls them in dependency order — a hand-written one has to do the same |
| the generated `main.c` is left out of the link | it has a `main` of its own; the hand-written file is the program |
| ⚠️ **the header's filename keeps its source spelling** | `Hot.h`, not `hot.h`, while the *symbols* inside are lowercased by Annex G.3 — so the wrong spelling compiles on macOS and fails on Linux, which is exactly how the Linux build broke once already |

**What it does still cost.** Depending on `f_name(Value **cells, Value *args,
int32_t count)` pins that signature. It is not a *new* exposure — the shape is
already in every generated header of every multi-unit program — but a VM would
be the first thing outside the emitter to actually depend on it, and it has
changed before. Worth deciding deliberately rather than by accident:

| | |
| --- | --- |
| depend on `f_name` directly | fastest, and what the measurement used; pins the convention |
| depend on `fn_name` through `alg_call` | survives a convention change, and gives most of the saving back — `alg_call` walks six tag checks, which is what the C loop exists to skip |
| put the loop in `algol.c` as a runtime service | no dependence either way; the runtime gains knowledge of bytecode, which it has no business having |

**What it costs the project's premise, which is less than it looks.**
`bootstrap/algol.c` is hand-written C and nobody counts it against "the compiler
is written in Algol-24", because the runtime is C by design. A dispatch loop is
plumbing of the same kind: it decodes a byte and calls a function, and holds no
opcode semantics at all. The claim worth protecting is that the VM's *behaviour*
is Algol-24, and that survives intact.

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
  and call frames cost more each. 12.0 M is the dispatch floor rather than a
  prediction of the mix.
- **That the CPython comparison generalises.** It is one loop of three integer
  operations, with no allocation, no calls, no strings and no collections.
  CPython is far worse than this at function calls and far better at anything
  backed by a C library, so the 1.6× is a position on this microbenchmark and
  not a claim about either language's speed. It is quoted to answer "is this in
  the same class as a mainstream interpreter", which it does, and nothing more.
- **That the two emitter fixes recover what the proxies measured.** The untyped
  and nocast rows are *upper bounds*: they delete the guards outright, where an
  emitter must first prove each one vacuous and will fail to prove some.
  `ReduceBinary` ending `if Left = Right then Exit Left;` makes
  `Integer + Integer` provable, but DEF-35 is a standing example of the checker
  not knowing a type it could.
- **That the C dispatch holds its 1.72× over a real instruction set.** It was
  measured over four opcodes whose handlers are three lines each. A sixty-opcode
  VM has larger and more varied handlers, so the dispatch is a smaller share of
  each instruction and the multiplier should fall. The direction is known and
  the size is not. ⚠️ **It is a ratio against handlers that stay in Algol-24** —
  it says nothing about a VM whose handlers are also C, which is the 37× still
  on the table and a different proposal.
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

1. ~~**Does the game fit?**~~ **Measured: the reel engine at 60 fps, the Dew
   Drop Inn at 30.** What replaces it is a design question rather than an
   engineering one — **is 30 fps acceptable for the Inn?** It is a walking and
   dialogue game rather than a twitch one, and the alternative is not 60 fps
   but a compiled build that leaks 9 MB a second. Everything else here waits on
   that answer.
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
5. **Does `case` get a jump table in `CEmitter`?** Worth about 5% to a
   table-dispatched VM — 12.5 against 12.0 — so not a prerequisite, but it
   would make the obvious way to write a dispatch loop also the fast way, and
   it would retire the 2.4× penalty an arm pays for sitting thirty-first.
   ⚠️ **`-flto` already takes most of that penalty out**, which weakens the
   case for the jump table: the arm-position cost measured 2.4× at `-O2`
   (12.52 against 5.27) and **1.9× with LTO** (16.73 against 8.72), because the
   `alg_truthy`/`alg_equal`/`alg_declared` chain an `IfStmt` emits is exactly
   what inlining collapses. The flag is worth more here than anywhere else
   measured.
6. **Overload selection.** Resolved per call site at emit time where the types
   are known, or an opcode that selects at run time as the interpreter does?
   [EXP-013] requires the latter where types are not known.
7. ~~**Is `-flto` safe to make the default?**~~ **Settled: it is on, probed.**
   `build.sh` compiles and links a trivial program with `-flto` and uses the
   flag only if that succeeds, because the probe has to cover the link — that
   is where `-flto` fails, when a toolchain has no linker plugin. `LTO=0`
   turns it off. Costs about 1.7 s of link time on this machine.
8. **Does eliding the guards need a conformance case?** The elision is only
   sound where the checker has proved the types equal, so a case that *relies*
   on `alg_widen` firing — a subrange assignment that must raise — belongs in
   the corpus before the optimisation lands, not after.
9. ~~**How does C reach an Algol-24 subprogram?**~~ **Settled: it already
   can**, for any non-private top-level subprogram of a unit, and
   `vm/spike/fromc/` demonstrates it. What remains open is narrower and still
   worth deciding: **through `f_name` or through `fn_name` and `alg_call`?**
   The first is what the 1.71× was measured with and pins the calling
   convention; the second survives a change to it and hands most of the saving
   back. See the table in item 0b.
10. **If the dispatch loop is C, what else wants to be?** The honest answer is
   "measure before deciding", because the handler bodies are where the
   remaining 38× sits and each one moved is a piece of the VM that stops being
   Algol-24. ⚠️ **The slope here runs all the way to a C VM**, and the stopping
   point should be chosen deliberately rather than arrived at. A loop that
   decodes a byte and calls a function holds no semantics; a handler holds all
   of them.

---

## What this does not ask for

- **No change to the language, item 0b included.** Table dispatch is
  [FUN-011], the foreign opcode is the existing `Foreign` built-in, the heap is
  `Buffer`, and a unit's public subprograms are *already* callable from C —
  `vm/spike/fromc/` proves it. Nothing here needs a new rule.
- **Not a replacement for the tree-walking interpreter.** It stays the
  authority.
- **Not a replacement for the C back end.** AOT to native stays the way to ship
  a program that needs native speed.
- **No bytecode specification.** The opcodes are proposed after a Lox-shaped VM
  runs, which is the order that lets the corpus judge each one.

---

## Appendix: how the evidence was gathered

Everything above came from running the language, not from reading it, and
**`vm/spike/measure.sh` reproduces every figure in the measurement tables** —
roughly ten minutes from a built `bootstrap/algc`.

**The dispatch rows** are `vm/spike/direct.a24`, `vm.a24`, `vm60.a24` and
`vmtable.a24`, compiled with `algc --compile` and `cc -std=c11 -O2`, timed with
the `clock()` built-in and reported as the median of five runs.

**The annotation variants** are generated from `direct.a24` and `vmtable.a24` by
the script rather than checked in, because each is a mechanical edit and keeping
five near-copies in sync is how a table goes stale: *untyped* strips every
written type from a declaration, which is what eliding `alg_widen` where it is
provably the identity would amount to, and *nocast* additionally drops
`as Integer` from the dispatch loop, which is what resolving a cast at emit time
would amount to. Both are proxies measured for their cost, not proposed as the
way to write the VM.

**The C-dispatch rows** are produced by `vm/spike/cdispatch.py`, which rewrites
the emitted `while Running` loop of a *compiled* variant into a hand-written C
one and leaves everything else alone — the handlers, the opcode numbering and
every piece of VM state stay exactly as `CEmitter` wrote them. This works
without any change to the language because a generated subprogram is already an
ordinary C function, `static Value f_dopushi(Value **cells, Value *args,
int32_t count)`, and the patched loop is in the same translation unit.

⚠️ **A dispatch loop that exited early would report a flattering figure**, not a
failing one, because the instruction count the spikes print is derived from
`ITERATIONS` rather than counted. So `measure.sh` also builds both forms at a
thousand iterations with `--probe` and prints the VM's final state; they agree
at `ip=6 sp=1 stack0=0 running=0`, which is what makes the two forms equivalent
rather than merely comparable. Any future change to the patcher wants that check
re-read, not just the rates compared.

**The outside reference points** are `vm/spike/cdirect.c`, `cvm.c` and
`loop.py`. `cdirect.c` carries a compiler barrier that is load-bearing: without
it the optimiser deletes the loop and the program reports an infinite rate,
which is how an earlier draft of this proposal came to quote a C figure that
measured dead-code elimination. The bytecode count for CPython is read off
`JUMP_BACKWARD`'s target by `vm/spike/disasm.py` rather than eyeballed.

⚠️ **Every row is sized to run for at least a second.** An earlier draft timed
rows that finished in six milliseconds, which measured the scheduler — the
AOT rows swung between 115 and 143 for that reason, and one swung by 2× between
consecutive runs. Any new row added here wants the same treatment.

⚠️ **`measure.sh` reports operations a second and two tables here report
iterations a second**, which is a factor of three — the loop body is three
operations. So the script's `loop.py (CPython) 51.04` is the 17.0 in the
per-iteration tables, and its `vm-typed 12.00` is the 4.00. The dispatch tables
keep the script's own units.

⚠️ **Expect the last digit to move.** Run-to-run variation is 1% to 2% even at
these durations, so a figure here and the same figure from the script may differ
in the second decimal — the tables carry one run of `measure.sh`, not an
average of several. Anything that matters to a conclusion in this document has a
margin far wider than that; if a future change makes a decision turn on 2%, that
is the signal to measure properly rather than to quote harder.

**The per-dispatch figures** are the measured rate divided by the instructions
an iteration: three for the Algol-24 and C VMs, eleven for CPython.

**The emitted C** quoted in full is `vmtable.a24` compiled with
`algc --compile`; the thirteen runtime calls are counted from that output, and
`alg_declared`, `alg_cast`, `alg_truthy` and `alg_subscript_get` are read from
`bootstrap/algol.c`. That `build.sh` passes `-std=c11 -O2` and no `-flto` is
read from `bootstrap/build.sh`; that `BoundValue` elides only `''` and `Any` is
read from `compiler/CEmitter.a24`, and that `ReduceBinary` ends
`if Left = Right then Exit Left;` from `compiler/TypeChecker.a24`.

**The frame rows** are `clock()` either side of the frame loop's body in
`shroom-slots` — `machine.a24`'s loop for the reel engine and `inn.a24`'s for
the Inn — accumulated over 1,200 frames and divided, with the window ending
**before** `S.Present ()` so that it covers the game's own work rather than the
driver's. The instrumentation was reverted afterwards; it is six lines in each
file.

The foreign split is `alg_foreign` wrapped in a scratch `algol.c` to accumulate
the time inside it, attributed per frame with `SDL_RenderPresent` as the frame
boundary. ⚠️ **Two exclusions are load-bearing there**: `SDL_Delay` is the frame
cap rather than work *and* falls after the present, and everything before the
first present is loading art — counting either against a frame window that
never contained them is how a first attempt reported more foreign time than the
program's entire runtime.

**The memory rows** are `/usr/bin/time -l` over `algc compiler/Main.a24`,
`algc --compile … Main.a24` and `algc --test compiler/Main.a24`. The arena
figures are counted in `bootstrap/algol.c`; that `Buffer.Free` calls `free` is
read from `buffer_method`. `Foreign`'s arity and its mapping to
`alg_foreign_call` are read from `Interpreter.a24` and `CEmitter.a24`. The
`clox` mechanisms are quoted from `~/projects/clox/compiler.c`.
