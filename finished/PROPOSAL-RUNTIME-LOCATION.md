# Proposal: a location on a runtime error

> **FINISHED — decided and built in v0.2.4.** A runtime error names its file
> and line in the tree walker and the bytecode machine. **Compiled Algol-24
> carries no source information at run time, by decision** [ERR-003] — a program
> wanting it runs under the machine, which can disassemble itself.
>
> It needed a language addition first: `ErrorLn` [RT-030], because the language
> had no way to reach the error stream at all. The ordering half landed with it,
> since `ErrorLn` flushes.
>
> **What remains open:** the **call stack**, which this document deliberately
> put out of scope. Every processor would need a named per-call record and the C
> back end has none.

**Status:** proposed, not decided. Written 2026-11-07, out of
`PLAN-0.2.4.md` item 9.

A runtime error prints one sentence and nothing else:

```console
$ algc rt.a24
Uncaught: Operands must be numbers.
```

No file, no line, no call stack, in **all three processors** — so it is not a
divergence, and it is the whole of what a program gets when it fails. A syntax
error prints the file, the line, the source and a caret [ERR-005]; a runtime
error prints a sentence.

**There is a second half to this, and it is not independent** — the program's
own output appears *after* the diagnostic that stopped it. That looked like a
three-line fix and is not; see *The ordering half* below. Both halves want the
same thing.

---

## The ordering half, and why it is here rather than already done

```console
$ algc rt.a24 2>&1 | cat
Uncaught: Operands must be numbers.
before
```

`before` is printed by the program *before* it fails and appears *after*. The
cause is exact: the diagnostic goes to **stderr**, which is unbuffered, while
the program's output goes to **stdout**, which is block-buffered the moment it
is redirected — so the output is still in its buffer when the diagnostic is
written, and `exit` flushes it afterwards. At a terminal nothing looks wrong,
because stdout is line-buffered there; piped or redirected, **every program
appears to fail before it printed anything**, and a program's last output
before dying is the most useful thing it has.

`fflush(stdout)` before the sentence fixes it. It was implemented — one
`report_uncaught` for both uncaught sites, with the raised value rendered
*before* the flush because a guest `ToString` [CLS-009] may print on its way to
answering — and then **reverted**.

⚠️ **Because it reorders every LOCATED diagnostic too.** `Console.Error` writes
its three-line excerpt to **stdout**, while the front end is still running; the
`Uncaught:` sentence is written by the driver afterwards. So chronologically the
excerpt comes first, and the order the specification records —

```
Uncaught: Expect variable name.
[ERROR] conformance/0100-parse-error-shape.a24: Expect variable name.
[ERROR] 1 | var := 1;
[ERROR]   | ^^^
```

— **is itself a buffering artefact.** Flushing honestly inverts it to
excerpt-then-sentence: the detail before the summary, and the summary then
repeating the first `[ERROR]` line. Nothing in R-5 asks for that, and it is a
change to what every compile error in the language looks like.

Measured: **41 recorded cases** change, not the 27 the ordering alone accounts
for. The other fourteen are located cases, held in the recorded order by the
very artefact being removed.

**So the two halves share one cause: the report is printed by two layers at two
times and neither owns it.** The front end prints the excerpt as it fails; the
driver prints the sentence when it catches nothing. Getting the order right
means the **driver owning the whole report** — which is exactly what the
location half needs anyway, since that is where a runtime error's own excerpt
would have to come from.

Doing the flush alone buys a correct order for runtime errors at the price of a
worse one for every parse error. That is why it is in this proposal and not in
v0.2.4.

---

## Why it has no location, which is not an oversight

**All three processors raise from one place: the host runtime.** Take `X - 1`
where `X` holds text:

| | |
| --- | --- |
| compiled | generated C calls `alg_subtract(x, one)` |
| interpreted | the interpreter is itself a compiled Algol-24 program, so its `Left - Right` on guest values **is** `alg_subtract` inside `Interpreter.c` |
| on the machine | `DoSubtract` defers to the host's `-`, which is `alg_subtract` again |

and that function is:

```c
if (!is_number(a) || !is_number(b)) alg_error("Operands must be numbers.");
```

It is handed two `Value`s and nothing else. No file, no line, no notion that a
guest program exists.

**So the message has no location because the code that produces it cannot have
one** — and that is the mechanism which guarantees the three processors agree
about what an operator means. `CLAUDE.md` states it as a principle: interpreted
`Length` *is* host `Length`, so the two cannot disagree. The missing location is
the price of that identity, which is also why the defect has lasted: every
obvious place to fix it is a place that does not know the answer.

The raiser cannot know. Only the **caller** can, so the caller must publish it.

---

## The constraint that shapes the whole design

A runtime error is **catchable** [STM-020] and arrives as a String. Counted:

| | |
| --- | --- |
| corpus cases that print a caught message | **69** |
| assertions in `compiler/*.a24` comparing one exactly | **20** |
| handlers in `algol24-library` | **38** |

⚠️ **So the location must NOT go into the raised value.** Put it in the message
and every `except on e : String do WriteLn (e)` changes text, all twenty
compiler assertions — `AssertEqual ('Operands must be numbers.', e)` — fail, and
the bootstrap goes with them.

It therefore travels **beside** the value and is printed only where the raise
escapes uncaught. A caught error stays byte-identical to today, and so do those
69 cases.

---

## The decision that scopes this: compiled carries nothing

⚠️ **Decided, and now in [ERR-003]: compiled Algol-24 does not carry source
information at run time.** Carrying it means the emitted C storing a position
before every statement — a cost every program pays forever so that a failing
one can be read. The nearest measured comparison is the collector's shadow
stack at **+5.8%** for a root per block, and statements are more frequent than
blocks. A program compiled for speed should not pay for a diagnostic it is not
having.

**What a program gets instead is the machine.** `algvm` runs the same program
and can disassemble it: `--list` walks every chunk, `--trace N` keeps a ring of
the last N instructions with `sp`, `base` and `depth`, and `--watch TEXT` dumps
the instant a message is raised, caught or not. That is the division of labour
the machine exists for.

**So this proposal is about TWO processors, not three** — which makes it
materially smaller than it looked, since the C back end was the expensive third
and the only one with a per-statement cost in the hot path.

⚠️ **And it makes one harness change mandatory rather than optional.**
`conform.sh` compares the interpreter against the compiled back end. A location
present in one and absent in the other is a divergence it would report and
should not — it is the same situation as a `[WARN]`, which `render` already
drops from both sides because a diagnostic *about* a program is not output *of*
it. Whatever carries the location must be dropped the same way, or **every
runtime-error case in the corpus diverges at once**. That is not a detail to
discover during the work.

---

## The mechanism, per processor

One sink in the runtime: a *publish* that each processor calls, captured by the
raise and printed only if nothing catches.

```c
void alg_at(const char *file, int32_t line);
```

| | how | cost |
| --- | --- | --- |
| **machine** | a `Lines` buffer parallel to `Chunk.Code`, written per instruction by the emitter, read as `Lines[IP]` only at a raise | **zero on the happy path**; memory per instruction |
| **interpreter** | publish per statement as it executes | one store per statement, in a tree-walker already 6.9× slower than the machine |
| **C back end** | ~~a store per statement~~ | **out of scope by decision** — see above |

**The machine's is clox's own answer** and costs nothing until something fails.
`Chunk` carries `Code`, `Count`, `Constants`, `GlobalNames` and `GlobalKeys`
today and no line information at all, so this is additive.

**The C back end is out**, which is what shrank this proposal from three
mechanisms to two — and the two that remain are the cheap ones. The machine
pays memory and no time; the tree walker pays one store per statement in a
walker already 6.9× slower than the machine, where a 9% cost was just accepted
for automatic collection and bought 2.8× less memory.

---

## What is in, and what is deliberately out

**In:** the file and the line of an uncaught runtime error, reported with the
same three-line excerpt a parse error gets — reusing `Console.Error`, which
v0.2.4 made file-accurate rather than root-accurate [ERR-005], so a fault inside
an imported unit already names that unit.

**Out, for a later increment: the CALL STACK.** Every processor would need a
named per-call record, and the C back end has none — `AlgFrame` is the `try`
frame (a `jmp_buf`, a previous pointer, the raised value and a root depth), and
`AlgRoots` carries a slot pointer and a count with no name. `CLAUDE.md` warns
that path is hot and already carries the 5.8%.

Feasible nearly free on the machine, cheap in the interpreter, expensive in the
C back end — which is exactly the shape that makes three byte-identical reports
hard. A stack is worth having and is worth its own decision.

---

## The blast radius, measured

⚠️ **61 recorded cases would gain an excerpt** — every conformance or refusals
case whose `Uncaught:` line carries no `[ERROR]` lines today, which is what
identifies a *runtime* error as against a parse, scan or type one.

Each needs its expected output regenerated, and each then becomes a claim that
*this* is the right line. That is the real work in this proposal: not the
plumbing, but 61 assertions about which line a failure belongs to.

(For comparison, v0.2.4's own ordering fix moved an `Uncaught:` line in **27**
of them, and the plan's first estimate of a comparable number was wrong because
the measurement was broken — so this one was counted twice, by two different
means.)

---

## The decisions this needs

**Who owns the report.** This is the one that unblocks the ordering half as
well. Today the front end prints the excerpt and the driver prints the
sentence; if the driver printed both, the order would be its to choose rather
than the buffering's, and a runtime error could carry an excerpt by the same
route. It also settles whether the sentence leads or trails, which is currently
decided by accident.

**Which line, for an expression spanning several?** One rule, stated once, or
the three processors will not agree. The statement's **first** line is the
candidate: it is what all three can publish cheaply and what the parse-error
excerpt already shows.

**A caught-then-reraised error** — does it keep the original site or take the
site of the `raise` that re-threw it? The second is easier and is probably also
what a reader wants, but it loses the original.

**`--test`.** `TestReport` names the ROOT file deliberately and prints exactly
one `[ERROR]` line, and the compiled runner copies that because the two reports
are compared line for line. Does a runtime failure inside a test gain a
location, and on which of those lines?

**Flag or default**, given the C back end's cost.

**Whether a location belongs on a HOST error at all.** `Operands must be
numbers.` comes from the runtime; `Undefined property 'X'.` comes from the
runtime; but a `raise` written by the program is the program's own, and it
already has a token. It may be worth doing the program's own raises first —
they are the cheap half and need no per-statement publishing at all.

---

## Why it is worth a release of its own

It is the single largest improvement available to anyone writing in this
language, because it is the symptom every silent defect becomes. Of the
fifteen defects v0.2.4 closed, the ones that cost the most time cost it this
way: a field named after a built-in answered a function value and the program
died **later, in unrelated arithmetic, with this message** [R-1, R-5]; a
program-level name shadowed a unit's method and the abort arrived on a device
with no console at all [R-9].

`shroom-slots` records the compounding directly: *"it compounds with R-1 because
that defect's symptom IS a runtime error at a distance."*

Fixing it does not prevent those defects. It makes the next one of them cost a
minute instead of an afternoon.
