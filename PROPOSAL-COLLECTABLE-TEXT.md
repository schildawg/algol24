# Proposal: text the collector can reclaim

**Status:** **BUILT, MEASURED AND WITHDRAWN.** Written 2026-11-10 out of
chasing `shroom-slots` R-18 to its floor, implemented the same day, and
reverted on the measurement below. The design works; it cannot be afforded
until the compiled back end can collect, and that is blocked on something
else.

> ⚠️ **IT WORKS AND IT COSTS 143×.** The implementation is correct — all 247
> compiler tests pass with collection on, and a compiled program releases
> 200,000 text objects per batch where it released none. But
> `algc --compile compiler/Main.a24` goes from **78.4 MB to 11,247 MB**, and
> `algc --compile vm/run.a24` is killed by the operating system. The compiler
> is the heaviest text program in the tree and **it never collects**, so it
> pays the whole cost of ownership and receives none of the benefit.
>
> ⚠️ **THE BLOCKER IS NOT THIS DESIGN, it is that compiled Algol-24 has no
> automatic collection** — and that in turn is blocked because an intermediate
> inside one expression is in no local and registered nowhere, so there is no
> safe point to collect at. Until that is closed, giving text an owner trades
> a leak the arena can live with for a cost the compiler cannot.
>
> ⚠️ **RE-MEASURED 2026-11-10 AFTER THE BLOCKER WAS REMOVED, and it is still
> not affordable.** Compiled Algol-24 now collects at the top of every loop
> body, so the 143× was indeed measured against a client that never collected.
> With collection: `algc --compile` goes from **11,247 MB to 7,098** — better
> by 1.6× and still **90×** the 58.9 MB the safe point alone achieves.
>
> ⚠️ **COLLECTION WAS NECESSARY AND IS NOT SUFFICIENT, and the split says
> why.** `concat`'s growth fell **3.7×** — 251.9 MB per three million calls to
> 68.7 — because its own allocations are now owned and reclaimed. `Str (N)`
> did not move at all, because `as_text` renders an Integer into an
> **unowned** `arena_alloc(24)` that collectable text never touches. And the
> compiler's 90× is **live** text: a collector cannot reclaim what is
> reachable.
>
> ⚠️ **SO THE DESIGN MUST MAKE A STRING CHEAPER, not make its garbage
> collectable.** A three-character string goes from about 4 bytes of arena to
> 8 (a registry slot) plus 24 (an ObjText header) plus 16 (bytes rounded to a
> size class) — twelve times, on text that is alive, and the compiler holds
> millions of it. What that points to is a dedicated text heap with its own
> mark bitmap and bytes stored inline at their exact size, rather than one
> `Obj` and one registry entry per string. That is a different proposal.
>
> The sections below are as written before implementing, and the record of
> what implementing taught is at the end.

A `Value` holding text carries a raw `const char *` into the arena **with no
owning object**. The collector has nothing to sweep, the arena never frees, and
so every piece of text a program makes is held for the life of the process.
This proposes giving text an owner.

It is the second half of R-18. The first half — `ToUpper` and `ToLower`
answering a fresh copy per call — was fixed by interning, because folding
repeats. This half cannot be, and that is the whole argument.

---

## The demand, measured

**The Dew Drop Inn grows 43 KB a frame after R-18 is fixed**, down from 229,
and the remaining amount is text. Found by histogramming arena requests per
call site over 1200 frames:

| site | what it allocates | growth over 1200 frames |
| --- | --- | --- |
| `as_text`, `VAL_INT` arm | `arena_alloc(24)` per rendered Integer | **+977,722** |
| `concat` | `arena_alloc(max(64, (need + 1) * 2))` | **+587,164** |
| `file_read_line` | 128 bytes a line | +116,281 |

Reduced to minimal cases on the machine, both linear and unbounded:

| | per call |
| --- | --- |
| `Str (N)` in a loop | **23 bytes** |
| `'row ' + Str (N) + ' of many'` | **84 bytes** |

**What it cost the project that reported it.** R-18 took the game to 10.1 GB
on a 15.6 GB device, where the low-memory killer took it with no error and
nothing in the crash buffer. Fixing the folding half removed 81% of the growth
rate and about 540 MB of the peak; the rest is this.

⚠️ **A RATE, NOT A CEILING, is what makes this worth doing.** 43 KB a frame at
30 fps is 2.3 GB in six hours. Nothing here fails a test or a corpus case: a
program that runs briefly is correct and a program left running is killed, and
the only difference is time.

---

## Why interning cannot answer it

Folding repeats. The machine folds the same handful of names — `add`,
`length`, a class's — for the life of the run, so a table of answers bounds the
cost at the number of **distinct** strings.

`Str (N)` for varying `N`, and `A + B` for varying text, answer differently
every time. A cache of their results delays the growth by the size of the cache
and changes nothing about its shape. That difference is why the folding half
was a patch and this half is a proposal.

---

## The shape

**A new object, `ObjText`, owns the bytes; the `Value` points at it.**

```c
typedef struct {
    Obj     obj;
    char   *bytes;
    int32_t length;
    int32_t capacity;     /* 0 means the bytes are not ours to free */
} ObjText;
```

That is structurally identical to `ObjSeq` — a header, a pointer and two
`int32_t` — so it needs no new machinery: `obj_class_of(sizeof(ObjText))`
already gives it a size class, and the bytes get a byte-size-classed pool
beside `seq_spares`.

`VAL_STRING` and `VAL_CHAR` carry `.obj` instead of `.string`. The `Value`
keeps its own `length`, which is what preserves the concatenation optimisation
below: two Values may share one `ObjText` and view different amounts of it.

### A literal is interned by its address

`alg_string("...")` is what generated C calls — 35 times in `Token.c` alone —
and its argument is a **C static literal** whose address is stable for the
process. Copying one per call would replace this leak with a worse one, so
literals are interned by pointer: one `ObjText` per distinct literal address,
with `capacity` 0 so release never frees bytes it does not own.

This is what `ascii_one` already does for the 128 one-character strings, and
for the same reason.

### What the collector then does

`ObjText` is swept like anything else: unmarked, its bytes go to the byte pool
if `capacity` is non-zero and its body to `obj_spares`. Nothing new is needed
in `mark_value` beyond the case, because a text object points at no Value and
so has no children to trace.

---

## What this does NOT change

- **No syntax, no rule, no built-in.** `Str`, `+`, `Copy`, `ToUpper` and the
  rest answer exactly what they answer now. This is a representation change
  behind `algol.h`.
- **Generated C is untouched.** It calls `alg_string`, `alg_str`, `alg_add`
  and never reads `.string` — checked: zero occurrences outside `algol.c`.
  So no reseed churn beyond the runtime pair, which is hand-written and copied
  verbatim.
- **`Buffer` stays as it is.** Its bytes are malloc'd and explicitly freed,
  which already makes it the one text in the language whose memory comes back.
  It remains the right tool for accumulating something large.

---

## What it costs, counted rather than guessed

| | count |
| --- | --- |
| sites constructing a text `Value` | **3** |
| direct reads of `.string` in the runtime | **30** |
| `VAL_STRING` type tests | **12** |
| sites in generated C | **0** |

Thirty mechanical rewrites behind one accessor, and three constructors to
split into "intern this literal" and "own these bytes".

⚠️ **AN ALLOCATION PER STRING IS THE REAL PRICE.** Today a rendered Integer is
one `arena_alloc(24)` and nothing else; afterwards it is an `ObjText` body plus
its bytes, both from size-classed pools, plus a registry entry. That is more
work per string in exchange for the memory coming back, and it must be
measured rather than assumed — `algc --compile` of the compiler is the honest
workload, since the compiler is the heaviest text program in the tree.

---

## The risks, and the one that is sharp

⚠️ **THE CONCATENATION OPTIMISATION MUST SURVIVE, and it is what makes `+`
linear rather than quadratic.** `concat` checks whether its left operand is the
**last thing the arena handed out** — `a.string == arena_tail_text` — and if so
writes the right operand into the slack in place. Without an equivalent, a loop
building text with `+` becomes quadratic, which is a far worse regression than
the leak being fixed.

Under this proposal the equivalent is better rather than merely equal: an
`ObjText` carries its own `capacity`, so the question becomes whether the left
operand's object has slack, with no dependence on arena layout at all. The old
check could only ever fire for the most recent allocation; this one fires
whenever the object has room.

**Two Values sharing one `ObjText` is then normal**, and safe because the
`Value` carries the length: extending in place lengthens the object and the
older Value continues to view the shorter prefix. That is exactly what the
present trick does, and the reason it is already correct.

⚠️ **A `Char` is text too**, and `alg_char_value` has two paths — the interned
`ascii_one` table for ASCII and an arena copy for everything above it. Both
need the same treatment, and the ASCII table is already the interning this
proposal generalises.

**An interior pointer must not survive the change.** Anything that holds a
`const char *` obtained from a Value across an allocation is holding something
the collector may move or free. The present code is safe only because nothing
is ever freed; that stops being true.

---

## Alternatives considered

**Trace the arena and sweep it.** Keep `.string`, and at collection time find
the block each live string points into. It changes no read site, which is its
appeal, but recovering a block from an interior pointer needs a sorted table or
a per-chunk bitmap, and the arena would have to stop being a bump allocator.
More machinery, in the hottest allocator, for the same answer.

**Widen `Value` with an owner field.** 16 bytes becomes 24 — every stack slot,
every List element, every argument. Rejected on cost: it taxes every program
and every type to fix one.

**Intern everything.** Bounded tables delay rather than bound, as above. It is
the fix for folding and not for this.

**Do nothing, and tell programs to use `Buffer`.** Honest, and already the
standing advice — but `Str (N)` has no `Buffer` form, and a program cannot
avoid rendering numbers. It is a mitigation rather than an answer.

---

## Why it is not in v0.2.6

v0.2.6 is R-18's folding half, which is measured, contained and flat. This half
changes the representation of the most common value in the language, so it
wants its own release and its own measurement — particularly of the cost named
above, which no part of this document has yet measured.


---

## What implementing it taught

Built on 2026-11-10 and reverted the same day. Four things are worth keeping.

**The representation change is small and the estimate held.** 3 construction
sites, 31 reads behind one accessor, 2 switches, and nothing in generated C —
as counted above. `cc` enumerated every site once `.string` left the union,
which is the technique to use again.

**Two bugs in it, and both are the same shape.** `text_static` interned a
literal by `((uintptr_t)s) >> 3`, which **discards the low bits** — and
`ascii_one` is a `[128][2]` array whose rows are two bytes apart, so every
four code points landed in one slot. The probes then filled and the fallback
answered **`alg_string_n`**, which is `VAL_STRING`, for a `Char`. So
`Source[I]` handed a one-character String to a parameter declared `Char` and
every call of the scanner's `IsAlpha` failed selection. A fallback must carry
the type it was asked for, and a pointer hash must not assume alignment.

**`mark_value` read only `VAL_OBJ`.** Text carries an object without being
`VAL_OBJ`, so the first collection swept the whole program's text while it was
in use. It presented as a segfault partway through the scanner tests, and what
localised it was that **247 tests passed with collection off and crashed with
it on** — the fastest split available for anything the collector touches.

⚠️ **AND THE COST IS STRUCTURAL RATHER THAN A DETAIL OF THIS ATTEMPT.** A
collectable string needs a registry slot, an object header, and bytes rounded
to a size class; today it needs only the bytes. For short strings that is
roughly an order of magnitude, and the compiler makes tens of millions of them
and never collects. Inlining the bytes in the object would save one allocation
and lose the body free list, because `obj_size_of` answers a fixed size per
type. No arrangement of those parts gets a never-collecting program back to
78 MB.

**So the order is forced**: automatic collection in compiled code first, then
this. The attempt is kept at `/dev/null` deliberately — it is a small enough
change to redo from this document when the blocker moves, and a stale copy on
a branch would be worse than none.
