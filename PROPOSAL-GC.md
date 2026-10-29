# Proposal: A Garbage Collector for the Compiled Runtime

**From:** the language project. `bootstrap/algol.c`'s allocator has never freed
anything, and `vm/` has been reserved since the first commit for "a bytecode VM
with a real GC".
**Status:** a plan, for decision. **Every number below was measured**, and the
instrumentation that produced them is described in the appendix.
**Concerns:** `algol.c` and possibly `CEmitter.a24` — no change to the language

---

## Who this is for

**Every program `algc` compiles, which does *not* mean the VM needs it.** That
distinction is the whole of this section, and an earlier draft got it wrong in
both directions.

### What the VM needs, measured

A VM is written in Algol-24 and compiled to C, so its allocations go through
this arena like any other compiled program's. From that it is tempting to
conclude that a collector here is the VM's collector. **It is not**, and the
reason is that the VM's own execution does not allocate:

| the table-dispatch VM running | arena handed out |
| --- | --- |
| 300,000 instructions | 0 |
| 3,000,000 instructions | 0 |
| **12,000,000 instructions** | **0** |

Its entire footprint is **41 allocations and about 2 KB**, all at startup: one
`Buffer` for the bytecode, two list headers and their backing arrays for the
stack and the handler table, one closure per handler, and the report strings.
Flat in instruction count.

> **The VM's own memory needs nothing. Not a collector, not even a free — a
> bounded two kilobytes that never grows does not have a memory problem.**

⚠️ **This is why `PROPOSAL-VM.md`'s heap section stands, and why a draft of
this document wrongly declared it superseded.** That section says the VM's
*guest* heap must be `Buffer`s the VM manages itself, with its own free lists
and object headers. A collector in `algol.c` does not replace that, because the
guest's objects are the one population the VM cannot statically bound — which
is exactly the split `clox` makes:

| | |
| --- | --- |
| **clox's own** tables, stacks and arrays | `malloc`/`free` in `reallocate()`, freed when clox is done with them |
| **the guest's** objects — strings, closures, instances | the collector, rooted in clox's own structures |

So the VM reimplements its value types over bytes rather than using Algol-24's
`String`, `List` and `Map` for guest data — which is why `clox` has
`object.c`, `table.c` and `value.c` as hand-written files. **That is the price
of the design, and this proposal does not avoid it.**

⚠️ **The discipline that implies is testable, and the table above is the test.**
A handler that creates an Algol-24 object on the guest's behalf has leaked a
guest value into the host heap, where it is immortal. A VM whose arena stays
flat in instruction count is honouring the boundary; one whose arena grows has
broken it. That is a harness, not a code review.

### What does need it

Programs whose live set is bounded but whose *allocation* is not — and the
compiler is the measured example. That is the subject of the rest of this
document.

⚠️ **`shroom-slots` is a source of lessons, not the aim.** It is the largest
program written against this language, and the `ascii_one` interning and the
sequence spare list both came from watching it lose memory. But it is intended
to run **on the VM**, so it is a consumer of the VM's guest heap rather than of
this collector. Where this document cites it, it cites it as evidence about
allocation behaviour and nothing more.

---

## The problem, measured

`arena_alloc` is a bump pointer over 1 MB chunks and **the arena is freed only
at `alg_shutdown`.** So a program's memory grows with how long it runs rather
than with how much it holds.

### Nearly all of it is garbage

A program that builds a List of fifty, a Map of fifty and a fifty-node
structure per round and drops all three — so that **nothing survives a round by
construction**:

| rounds | compiled | interpreted |
| --- | --- | --- |
| 500 | 4.3 MB | 100.8 MB |
| 1,000 | 8.5 MB | 201.4 MB |
| 2,000 | **17.0 MB** | **402.6 MB** |

Exactly linear in both processors — **8.5 KB a round compiled, 201 KB a round
interpreted.**

> **Nothing survives a round, so the live set is one round's worth however many
> rounds run. The overshoot factor is therefore the round count: a program that
> loops two thousand times holds two thousand copies of its garbage, and a
> program that loops forever holds all of it.**

⚠️ **An earlier draft of this document quoted the interpreted column as though
it were the program's own allocation.** It is not — it is the interpreter's
per-expression allocation on top of the program's, and conflating them
overstated a compiled program's appetite by 24×. The error is worth recording
because the two columns answer different questions, and because **the
interpreter is the authority every other processor is measured against**: it is
the heavier consumer by a wide margin, and nothing in this plan is specific to
compiled code.

⚠️ **The VM is not in either column.** Its own execution allocates nothing —
see *Who this is for*. A guest program running *on* it would allocate, which is
what the VM's own `Buffer` heap is for.

### Where it goes, in a real program

`algc --test compiler/Main.a24` hands out **1,147 MB** against a 3 MB baseline.
⚠️ **It is a mixed workload** — a compiled front end parsing and checking, then
the *interpreter* executing 245 test bodies — which is why it is List-heavy
where the purely compiled churn above is Map-heavy. By call site:

| | MB | allocations | average |
| --- | --- | --- | --- |
| `seq_append` — a List's backing array | **392** | 3,191,735 | 128 B |
| `alg_new` — an instance's field slots | 206 | 2,770,886 | 77 B |
| `map_put` — a Map's entry table | **203** | 826,186 | 258 B |
| `sequence` — the ObjSeq header itself | 183 | **8,014,890** | 24 B |
| `alg_new` — the ObjInstance header | 63 | 2,770,886 | 24 B |
| `concat` — string concatenation | 44 | 719,585 | 64 B |
| `alg_map` — the ObjMap header | 39 | 1,013,757 | 40 B |
| `alg_bound` — a bound method | 12 | 407,309 | 32 B |

**Headers dominate by count and arrays by volume.** Eight million ObjSeq
headers at 24 bytes is the largest single population in the process — every
list literal, every gathered argument list, every temporary.

⚠️ **The compiler is the right program to measure, which an earlier draft also
got backwards.** It is the largest program written in Algol-24, and **a VM will
look far more like it than like a game**: long-running, allocating small
objects continuously, holding a modest working set. The shapes to design for
are the two tables above, and both are this compiler's.

---

## What already works, and what it teaches

Three mechanisms already recover memory, and none of them is a collector. They
are worth reading before adding one, because each exploits a *local* ownership
fact that a general collector cannot assume.

| | |
| --- | --- |
| **In-place growth.** `seq_append` and `concat` extend a block where it stands when it is the last thing the arena handed out — no copy, nothing abandoned. | costs a pointer comparison |
| **The sequence spare list.** A grown-out-of `items` block goes onto a per-size-class free list threaded through the blocks themselves. Safe because *an `items` block never leaves its ObjSeq* — the pointer is assigned in exactly one function, so the old block is unreachable **by construction rather than by promise**. | the staircase of abandoned capacities was "two thirds of all the memory one game was losing" |
| **`Buffer` is malloc'd, not arena'd.** `Free` calls `free`, `Resize` reallocs, and `free_all_buffers` sweeps at exit. It is the only memory the language can explicitly release. | the program must say when |

⚠️ **The lesson is that the big wins so far came from proving a narrow
ownership claim, not from tracing.** The spare list works because one pointer
has one owner. Before building a collector, the question worth asking of each
row in the table above is whether the same kind of claim holds — the Map entry
table (203 MB) looks like exactly the same shape as the List backing array, and
has no spare list.

---

## What an explicit `Free` would and would not buy

⚠️ **`Free` is an interface; a free list is the mechanism — and the mechanism is
the work.** This was prototyped rather than argued: `alg_release` was added to
`algol.c` in a scratch copy, reached as `Free` on a List and a Map, and the
churn program was run with and without it.

| | arena, 2,000 rounds |
| --- | --- |
| churn, leaking | 11.7 MB |
| churn, calling `Items.Free ()` and `Table.Free ()` | **11.7 MB** |

**No difference at all**, and the two reasons are the whole lesson:

| | |
| --- | --- |
| **a Map has nowhere to put a freed block.** `alg_release` nulls the pointers and the entry table is abandoned exactly as before — nulling a pointer is not reclaiming | there is no map equivalent of `seq_spares` |
| **a List barely needs it.** `seq_append`'s in-place growth already extends the block where it stands, so the staircase the spare list exists for mostly does not form | the compiled churn allocates 2,000 items blocks for 2,000 rounds — one each |

⚠️ **And the spare list matches size classes exactly**, so a freed capacity-64
block does not serve the next round's request for capacity 8. An explicit
`Free` would want a sloppier match, or the allocator would want size-classed
pools generally — which is open question 4, and which `Free` depends on rather
than replaces.

So an explicit `Free` is worth having, but **it is the last step of this plan
rather than a shortcut past it.** Steps 1 and 2 are what make it mean anything.

---

## Could the VM borrow Algol-24's collections instead?

The VM cannot hold an Algol-24 `List` or `Map` *in* its `Buffer` heap — a Buffer
holds bytes and the language offers no way to put a reference in one. The way
around that is a **handle table**: the guest object stores an index, an
Algol-24 `List` holds the real collections, and the VM's sweep releases the slot.
It needs nothing new from the language.

**What it would buy, measured.** The same workload three ways:

| | |
| --- | --- |
| guest field access through Algol-24's own `Map` (C) | **22.2 M op/s** |
| the same through a hash table hand-rolled over `Buffer` bytes | **10.8 M op/s** |

So borrowing the native collection is worth about **2×** — smaller than it
sounds, because the native path pays `alg_invoke` method dispatch, which offsets
its C implementation.

**What the indirection costs, measured.** Reaching a `Map` directly against
reaching it through a handle table:

| | |
| --- | --- |
| direct | **16.7 M read/s** |
| through the handle table | **10.5 M read/s** |

⚠️ **About 1.6×, which very nearly cancels the 2× it was bought for.** The two
microbenchmarks are not tight enough to call a winner, and that is the finding:
**the handle table is not obviously worth its complexity** — free lists,
slot reuse and a release hook — over simply writing the table over bytes.

**And it cannot serve the object the VM needs most.** By constraint 1 an
Algol-24 String borrows its bytes and has no header, so there is nothing for a
`Free` to release and no way to tell a literal from an arena allocation. Guest
strings therefore have to live in the `Buffer` heap whatever happens — and
**`ObjString` is the single most important object in a Lox-shaped VM.** Once the
byte-level machinery exists for strings, a table and an array over bytes are
incremental rather than a new category of work.

⚠️ **The release hook itself is the easy part, and worth saying so.** "Call
`Free` when the collector reaps the object" is a finalizer, which is a
notoriously hard feature in general — ordering, resurrection, running mid-collection.
Here it is none of those: the VM calls it synchronously, during its own sweep, on
objects it has just proved unreachable in a heap it solely owns, and `Free` does
not allocate. The hard part is not the hook; it is that `Free` has nothing to
give the memory back to — see above.

---

## Four constraints the runtime imposes

These are what make this a design problem rather than a matter of picking a
textbook algorithm. Each is read from `algol.c` or `algol.h`.

### 1. A String has no header and does not own its bytes

```c
Value alg_string_n(const char *s, int32_t n) {
    Value v;
    v.type   = VAL_STRING;
    v.length = n;
    v.string = s;       /* borrowed -- never copied */
    return v;
}
```

A `VAL_STRING` is **not an `Obj` at all.** Its bytes may live in a C string
literal, in the static `ascii_one[128][2]` table, or in the arena, and
**nothing in the Value distinguishes them.** So a collector cannot trace a
string, cannot free one, and cannot move one.

⚠️ **The interning this enables is load-bearing and must not be broken for the
collector's convenience**: sharing one pointer for every ASCII character took a
game frame's allocations down by three quarters. Any design that gives strings
a header pays that back.

The measurement is kind here — strings are 44 MB of 1,147, or **4%** — so
leaving them exactly as they are is a defensible first answer.

### 2. The roots are on the C stack

Generated code holds values in ordinary C locals — `Value v_op = …;` — and
there is no shadow stack, no registration, and no place that enumerates them.
**A precise collector is therefore impossible without changing every emitted
function**, which means changing `CEmitter`, reseeding, and paying on every
call. A collector here either scans the C stack conservatively or is not
precise.

⚠️ **The VM escapes this, and that is a fact about the VM's own collector
rather than about this one.** A VM keeps its state in *explicit data
structures*: its value stack is one object, its globals another, its frames a
third, and the guest program's values live inside those rather than in the C
locals of the dispatch loop. So a VM can enumerate its roots exactly — which is
what makes the `Buffer`-based guest heap in `PROPOSAL-VM.md` tractable, and it
is a reason that design is *easier* than it sounds, not a reason to replace it.

### 3. `Obj` has no room for collector state

```c
typedef struct { ObjType type; } Obj;
```

No mark bit, no forwarding pointer, no link to the next allocation. Every
collector needs at least one, so every one of the object constructors changes.

### 4. The arena has no object boundaries

`arena_alloc` returns a bump pointer. Given an interior pointer you cannot find
the object it belongs to, and given an object you cannot free it: there is no
header, no size, and no free list. **Sweeping requires an allocation list that
does not exist.**

---

## The options, against those constraints

| | handles roots | needs an Obj header | strings | the catch |
| --- | --- | --- | --- | --- |
| **scoped region / rewind** | nothing to trace | **no** | go with the region | the program must say when, and nothing may escape |
| **destructors** | nothing to trace | yes | cannot own borrowed bytes | ownership and move semantics |
| **conservative mark–sweep** | scans the C stack | yes | leaves them | ⚠️ `-flto`, pauses, stale stack words |
| reference counting | needs none at all | yes (a count) | cannot count a borrowed pointer | ⚠️ taxes every `Value` copy |
| copying / generational | no | yes (forwarding) | **cannot move a string** | ruled out by constraints 1 and 3 |

Two are ruled out outright.

**Copying and generational collection** cannot move a String, by constraint 1,
and have nowhere to put a forwarding pointer, by constraint 3.

⚠️ **Reference counting taxes the copy of a `Value`, which is the most common
operation in emitted C.** This project has just spent a release *removing*
per-assignment overhead — `alg_widen` is now elided where it is provably the
identity, and `-flto` is on. A retain/release on every assignment gives that
back and more. It also cannot count a String, and it leaks cycles, and an AST
is full of them.

**The remaining three are the fork in the plan**, and which is right depends on
something already measured: the compiler's garbage has a *known* lifetime.
A collector is machinery for lifetimes that cannot be known, and paying for it
where they can be is the wrong trade — which is the argument for starting with
a region and keeping mark–sweep for the case where a program cannot cooperate.

---

## The plan

⚠️ **The order matters more than usual here, because step 3 is a real fork and
steps 1 and 2 are worth doing whichever way it goes.**

### 1. Take the ownership wins — they need no collector at all

| | MB | the claim to prove |
| --- | --- | --- |
| a Map's entry table | **203** | the one `seq_spares` already proves for a List's backing array: the table never leaves its ObjMap |
| an instance's field slots | 206 | the slots block never leaves its ObjInstance |

**36% of the compiler's arena, by the mechanism already in the file**, needing
no header, no roots, no collector and no decision. Both look like exactly the
shape `seq_append` already handles.

⚠️ **They are a constant-factor saving on an unbounded problem** — they make the
staircase shallower without stopping it climbing — so they are not a substitute
for step 3. They are simply the cheapest memory left in the runtime.

### 2. Give `Obj` a header and the arena an allocation list

Constraints 3 and 4. A mark bit and a link to the next allocation, set by the
~20 object constructors, and a sweep that can walk the list. **Nothing in step 3
is possible without this, and it is the same prerequisite whichever branch is
taken** — explicit release needs to find an object's extent just as much as a
collector does.

**Strings stay out of it**, by constraint 1. They are 4% of the arena and
cannot be traced without changing `Value` and breaking the interning that a
measured three quarters of a game frame's allocations depended on.

### 3. The fork: collect, or release explicitly

This is the decision this document exists to frame, and it is genuinely open.

| | what it is | for | against |
| --- | --- | --- | --- |
| **conservative mark–sweep** | scan the C stack and statics for words pointing into the arena, sweep the rest | works for *any* compiled program with no cooperation and no emitter change | ⚠️ interacts badly with `-flto`, which is now on; a stale stack word keeps dead objects alive; stop-the-world pauses |
| **explicit release** | a scoped region, or destructors, or both | ⚠️ **far cheaper, and it fits the measured problem exactly** — the compiler's AST has a known lifetime: parse, use, discard | unsound if anything escapes, and the program must say when |

**Where I would start is explicit release, and the measurement is why.** The
churn program's live set is one round in two thousand; the compiler's AST is
discarded per file and per test. **That is a known lifetime, and a collector is
machinery for lifetimes you cannot know.** A region marks the arena's
high-water mark and rewinds to it, which costs a pointer and needs neither a
stack scan nor a pause.

⚠️ **A region and a destructor are not the same answer, and the compiler wants
the region.** An AST is not one object with one owner — it is millions of nodes
in a tangled graph. A destructor must walk it and must know nobody else holds a
node, which is ownership and move semantics, and those sit badly with gradual
typing and with `Value` being copied freely. A region does not care about the
graph; it frees the span.

**Destructors have their own strong case, and it is about resources rather than
memory.** A file, a `Buffer`, a foreign handle wants closing when its holder
dies; today `close_open_files` and `free_all_buffers` sweep at exit and nothing
closes earlier. That is worth having on its own terms and should be argued on
them, not folded into this.

⚠️ **The honest risk in the region branch is escape, and `algc` demonstrates
it**: `SourceCode` is one global keyed by line number, so something does
outlive a file's parse. A region per file is unsound until that is dealt with,
and finding the other escapes is the actual work of this step.

### 4. Conservative mark–sweep eventually, for programs that cannot cooperate

A language whose arbitrary programs grow without bound has a problem that
explicit release does not solve, because it requires the program to know. That
is a real gap and worth closing — later, informed by whether step 3 turned out
to be sufficient for the programs that exist.

---

## What this does not ask for

- **Not the VM's collector.** The VM's own memory is 2 KB and needs nothing;
  its *guest* heap is `Buffer`s it manages itself, per `PROPOSAL-VM.md`.
  Nothing here changes that, and an earlier draft wrongly said it did.
- **No change to the language** for steps 1 and 2. Step 3 needs one either way
  — a region needs markers and destructors need a declaration — and that is the
  decision, not a side effect of it.
- **No change to `CEmitter`** for steps 1, 2 or a region. Only conservative
  scanning and destructors would reach it.
- **No change to how a String is represented.** Constraint 1 stands, strings
  stay borrowed and uncollected, and at 4% of the arena that is a deliberate
  trade rather than an oversight.
- **Not a replacement for `Buffer`.** It stays explicitly managed, which is
  what makes it the right tool for bulk bytes — and the model the guest heap
  and any region both follow.

---

## Open questions

1. **Region or destructors, for the compiler?** The fork in step 3. The
   argument above favours a region for the AST and destructors for resources,
   which may mean both eventually and should not mean both at once.
2. **What else escapes a file's parse besides `SourceCode`?** A region per file
   is unsound until that list is complete, and assembling it is the real work
   of step 3 rather than the rewind itself.
3. **Does a Map's entry table really never escape its ObjMap?** `seq_spares`
   rests on that claim being checkable by reading one file. The same reading
   has to be done for `map_put`, and the claim is worth more than the 203 MB if
   it turns out to be false somewhere.
4. **Eight million ObjSeq headers — should the arena hand out small fixed sizes
   from a pool?** A 24-byte header is the most numerous allocation in the
   process by a factor of two and a half, and a size-classed free list for them
   is simpler than anything in step 3.
5. **Does a conservative scan work at all under `-flto`?** LTO is on by
   default now, and an aggressively optimised build may keep the only pointer
   to an object in a callee-saved register a naive scan never examines. This
   decides whether step 4 is even feasible, and it is cheap to test before
   relying on it.
6. **Does the interpreter want this too?** It is the tree-walking processor, it
   allocates through the same arena, and it is the authority every other back
   end is measured against. It would benefit identically, and nothing in this
   plan is specific to compiled code.
7. **Should "the arena stays flat" become a harness?** The measurement that
   settled the VM's needs is three runs at different instruction counts. The
   same check would catch a handler leaking a guest value into the host heap —
   the one discipline the `Buffer` guest heap depends on — and `vm/spike/`
   already has the shape of it.

---

## Appendix: how the evidence was gathered

The arena table came from instrumenting `bootstrap/algol.c` in a scratch copy,
not from reading it. `arena_alloc` was renamed `arena_alloc_real` and replaced
by a macro passing `__LINE__`, which tallies bytes and counts into two arrays
indexed by line and dumps them at `alg_shutdown` when `ALG_ARENA_REPORT` is
set. About twenty lines.

**The VM table** is `vm/spike/vmtable.a24` at three iteration counts, compiled
with `algc --compile` and then **linked against the instrumented `algol.c`
instead of the copy `--compile` places beside it** — which is the whole trick,
and is available to any program. It is also how a real VM should be checked
against the boundary its guest heap depends on.

**The churn table** is a program that builds a List of 50, a Map of 50 and a
50-node linked structure per round and keeps none of them, run at three round
counts under the same instrumentation, with peak RSS from `/usr/bin/time -l`
alongside. Its point is that the arena grows linearly in rounds while the live
set does not grow at all, which is what makes the overshoot a statement about the
allocator rather than about the program. ⚠️ **The interpreted and compiled
columns were conflated in an earlier draft** -- the instrumented `algc`
*interpreting* the churn program reports its own per-expression allocation too,
so the compiled figures come from linking the program against the instrumented
`algol.c` instead, which is the same trick the VM table uses.

⚠️ **It counts bytes handed out, not bytes live** — which for this allocator is
the same thing for the arena, since nothing is returned to it before exit, but
is **not** the same thing for the sequence spare list: a recycled `items` block
is reused without a new `arena_alloc`, so the 392 MB row is demand the spare
list could not satisfy rather than memory abandoned.

The 3 MB baseline and the earlier 1,731 MB peak-RSS figure are
`/usr/bin/time -l`, and the gap between 1,147 MB of arena and 1,731 MB of RSS is
`Buffer`s — which are malloc'd rather than arena'd — plus chunk rounding.

The four constraints are read from the current `bootstrap/algol.c` and
`bootstrap/algol.h`: `alg_string_n` and `ascii_one` for the first, the emitted C
of any spike in `vm/spike/` for the second, the `Obj` typedef for the third, and
`arena_alloc` for the fourth. The three existing mechanisms are `seq_append`,
`seq_spares`/`seq_recycle` and `free_all_buffers`, whose own comments are quoted
where they say it better.
