# Proposal: text the collector can reclaim

> **FINISHED — built in v0.2.6.** Every String and Char in a program lives in
> a text heap the collector marks and sweeps, and `collector.sh`'s `flat-text`
> check holds it to the property that matters: ten times the work costs the
> same memory.
>
> ⚠️ **THIS IS THE THIRD ATTEMPT, and the two that were withdrawn are kept
> below.** They cost 143× and 90× on `algc --compile` and were reverted on the
> measurement. The conclusion drawn from them — *a string must be made cheaper
> rather than its garbage collectable* — was wrong, and the reason is the one
> line in `alg_str` that this version does not write.
>
> **What remains open:** a `TextFile`'s object body is still never reclaimed,
> because `all_files` is a list the runtime walks at exit; and the holds the
> emitter now writes are conservative, one per subexpression, where a sibling
> analysis would write far fewer.

## What it is

Text used to come from the arena, which never frees. So a String was permanent:
a program that built one per frame grew until the operating system killed it,
which is `shroom-slots` R-18 and was traced to `folded` before the floor turned
out to be lower than that.

The heap is small because of one decision: **a `Value` still carries
`const char *string`, pointing at the payload, with an eight-byte header
immediately before it.** Every one of the thirty places that reads a string's
bytes is unchanged. What moved is where the bytes come from, that they are
marked, and that they are swept.

```
    size   bytes of payload
    flags  FREE | PERM | MARK
    ────── payload, what a Value points at ──────
```

- **Blocks band.** Up to 512 bytes in steps of eight; above that to the next
  power of two, which wastes up to half and is what makes a large block
  REUSABLE. Exact sizing above the small bands would mean a long string
  released is never handed out again — a leak for any program reading a file
  line by line.
- **A literal is interned by its ADDRESS.** Generated code calls
  `alg_literal` with a C static whose address is stable for the run, so one
  permanent copy serves every call. The table grows; a fixed one was a quiet
  per-call allocation rather than a limit.
- **A render is text no `Value` owns** — what `as_text` answers for a number,
  a collection, a `Buffer(12)`. Those are released at the next safe point,
  which is sound for the same reason the temporaries gap was survivable: a
  collection happens only between statements, and a render is produced and
  consumed inside one expression.
- **`ALG_POISON=1` covers text too.** A released block is filled with `0xDD`
  and withheld, which is the same *marking is wrong* / *reuse is wrong* split
  the objects already had — and it is how the first bug in this work was
  localised in one run.

## What it needed from the emitter

⚠️ **An intermediate inside one expression is in no local and no argument
array, so the shadow stack could not see it.** That gap is older than this
work and `CLAUDE.md` already named it. It was survivable while a collection
happened only where a program asked for one, because an expression is never
interrupted by its own statement boundary — and it stopped being survivable
the moment collection became automatic, because a safe point inside a CALLEE
fires while the caller is part way through an expression.

So `CEmitter` wraps each intermediate in `alg_hold`, which pushes the VALUE
rather than a pointer to it: there is no C local whose address could be taken.

⚠️ **Holds get a stack of their own, and sharing the shadow stack was both
slower and harder to emit.** An entry there is a pointer and a count, so a
held value needed a third field and three stores where this needs one — and
the two have different LIFETIMES: a declaration's root lives to the end of its
block, a temporary to the end of its statement. Separate tops mean a statement
boundary restores one without the other, so a declaration in the middle of a
block needs no special case at all.

A loop's condition and step are not statements, so nothing else releases what
they hold — and they run once an ITERATION. They reset before each.

A Value that cannot reference the heap is not pushed, which is what keeps
arithmetic free: `Fib (27)` compiled is unchanged.

## What it cost, and what it saved

| | before | after |
| --- | --- | --- |
| `algc --compile compiler/Main.a24` | 53.0 MB, 3.07 s | **46.9 MB, 3.06 s** |
| `algc --test compiler/Main.a24` | 298.5 MB, 12.89 s | **258.3 MB, 13.60 s** |
| `Fib (27)` on `algvm` | 0.70 s | **0.79 s** |
| the Dew Drop Inn, software renderer | 43 fps | **42 fps** |
| the Inn's arena, 200 → 1000 frames | +20 KB a frame | **flat at 29.0 MB** |
| 2,000,000 discarded strings | 138.7 MB | **8.2 MB** |

⚠️ **The machine pays 13% and nothing else pays anything measurable.** A hold
costs where a program moves heap references about, which is what the machine's
handlers do once per instruction; compiled arithmetic pays only a type test.
The honest reading is that this buys flat memory for one program in three
paying an eighth of its speed.

## The two attempts that were withdrawn

Both gave text an `ObjText` of its own — an object the existing collector could
already mark and sweep — and both were reverted on the same measurement:
`algc --compile compiler/Main.a24` went from 78.4 MB to **11,247 MB** and then,
after automatic collection landed, to **7,098 MB**. Ninety times.

⚠️ **The conclusion drawn was wrong, and so was the second one.** The first
read was *the compiler never collects, so it pays the whole cost of ownership
and receives none of the benefit*; the second, after collection arrived, was
*a string must be made cheaper rather than its garbage collectable*. Neither
was it. `alg_str` answered a *copy* where it used to answer the same bytes with
a different tag — `Str` on something already text only widens a Char to a
String [TYP-003] — and the compiler calls it on nearly every name it handles,
including whole emitted units. **471,174 copies averaging 18 KB.** One line.

⚠️ **What found it was attribution, after reasoning had failed three times.**
A per-call-site histogram of the heap's own allocations named `alg_string_n`,
and the list of its callers is short enough to read. Two rounds of
*which-of-these-changed-behaviour* had already guessed wrong — at the chunk
displacement, which was real and worth 0.2%, and at `concat`'s doubling, which
turned out to make six big allocations in the whole run.

## What the gates learned

- **`collector/0006-a-temporary-is-a-root`** — and an explicit `Collect ()`
  cannot catch it, which is what makes the case worth reading. A call written
  as a statement IS a statement boundary, so every live value is a local. The
  collection has to arrive from somewhere the program did not ask for it.
- **`collector.sh`'s `flat-text`** — a text leak is invisible to output, so
  comparing what a program prints cannot catch one. It runs at two scales ten
  times apart and compares what the runtime reports. The small scale is 20,000
  rounds rather than 2,000 because the heap has to reach steady state first:
  2,000 peaks BELOW the figure it settles on, so comparing against it would
  read a leak as the heap merely warming up.
- **Both were seen to go red**, each against the fix it guards reinstated — the
  holds disabled for 0006, the fold cache's permanent blocks and the Buffer's
  sweep exemption for `flat-text`.
