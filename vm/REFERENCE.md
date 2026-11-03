# The Algol-24 Bytecode Reference

⚠️ **A DRAFT of four entries out of 78**, written to test the format on the
awkward shapes before the other 74 are written in it. The four are chosen for
that and not for importance: `OP_LONG` is the prefix, `OP_CLOSURE` is the only
variable-width instruction, `OP_INVOKE_EXT` carries three operands of three
different kinds, and `OP_OVERLOADS` carries its index *second*.

⚠️ **Every encoding here is written by hand and nothing checks it yet.** The
machine's own `OpShape` already answers one letter per operand, so an entry
disagreeing with it is a defect in this file — and 78 hand-written encodings
will drift inside two increments. The intended end state is a `vm/reference.sh`
in the spirit of `spec/spec.sh`: every opcode below `OP_COUNT` has an entry,
every entry's encoding matches `OpShape` byte for byte, and every stated stack
effect matches an assertion. Until that exists, treat `vm/OpCode.a24` as the
authority and this file as commentary.

## How to read an entry

Each entry has the same six sections, in this order. A section with nothing to
say is omitted rather than filled with "none".

**Encoding** — the bytes, in order, inside a fence. The **first bracketed row
is read by `vm/reference.sh`**: its first bracket is the opcode's number in
decimal and the rest are its operand letters, which are compared against
`OpShape` and against the stated byte count. An instruction `OpShape` cannot
describe says `variable-width` in the fence, which exempts it from that
comparison and lists it in the checker's own report rather than hiding it. **An opcode's number is
not part of the interface**: opcodes are renumbered from their declaration
order in `vm/OpCode.a24` by a script, and inserting one renumbers those above
it. The *mnemonic* is the stable name. Nothing should hard-code 37 for
`OP_LIST`.

**Stack** — `pops P, pushes Q, needs R`, in slots, and **`vm/reference.sh`
compares all three against `OpStack` in `vm/OpCode.a24`**. This is the section
to read first. A correct emitter leaves a balanced stack, and the machine has
twice had a bug that produced the right answer while leaking a slot per
iteration — which is why the tests assert `SP` after a run and not only the
result.

`needs` is the least depth the instruction requires, and it is a third number
rather than the same as `pops` because an instruction may **read** the top
without taking it: `OP_DUP` and every assignment opcode need a value beneath
them and leave it there [EXP-020].

⚠️ **Of the three, two are measured and one is description.** `pushes - pops`
is what a run reveals, and `needs` is what running one value shallower reveals
— both are asserted against the machine by
`A Measurable Opcode Moves The Stack Exactly As It Declares`. The **split** is
not observable from outside, because popping a value and pushing two copies of
it moves the stack exactly as reading it and pushing one does; that was checked
with distinct sentinels rather than assumed. So `pops` and `pushes` separately
say what the handler is written to mean, and a reader should trust their
difference further than either alone.

**Operation** — what it does, in the fewest words that are still true.

**Satisfies** — the rules of `spec/ALGOL-24.md` this instruction exists to
serve, where there are any. This is the section a 1987 manual had no need for
and this one does: the machine is one of three processors of a specified
language, and an opcode that serves no rule is worth a second look.

**Raises** — the **exact** text, quoted. The wording is load-bearing: the
machine once invented `Can only call a subprogram.` where the language says
`Can only call functions and classes.`, and because the one case comparing
that text was refused for another reason, the two processors printed different
words for one fault until a real program hit it.

**See also** — the neighbours worth reading in the same sitting.

## Operand kinds

Four letters, which are the letters `OpShape` answers. The distinction that
matters is **which operands widen**:

| | | |
| --- | --- | --- |
| `i` | constant index | one byte, **two under `OP_LONG`** |
| `l` | local slot | one byte, **two under `OP_LONG`** |
| `b` | a plain byte — an argument count, a flag | always one, never widens |
| `s` | a short, high byte first | always two, never widens |

**At most one operand per opcode may widen**, and that invariant is what makes
a single prefix sound: the machine clears the flag on the first widenable read,
so it never has to know *where* among the operands that read sits. Both `i` and
`l` consult the same flag, and no opcode carries both. An instruction wanting a
second wide operand takes an `s` instead and pays the byte unconditionally,
which is what `OP_INVOKE_EXT`'s extension slot and `OP_CLOSURE`'s descriptors
do.

There are no flags and no addressing modes, so the two sections that fill most
of an 8086 page are absent here. There are no cycle counts either, and that is
deliberate: the cost of an instruction is dominated by which host routine its
handler calls, so a per-opcode table would be invented precision that goes
stale in silence. Where a figure has actually been measured it is quoted with
the workload it was measured on, and nowhere else.

---

## OP_LONG — Widen The Next Instruction's Index

```
Encoding    [ 69 ]                                        1 byte

            No operands.  Its operand is the whole instruction that
            follows it, opcode included.
```

**Stack** — pops 0, pushes 0, needs 0.

**Operation** — sets a flag, then runs the next instruction. That instruction's
one widenable operand — its constant index (`i`) or its local slot (`l`) — is
read as a short instead of a byte, and the flag is cleared **by that read**.

A prefix rather than a long form per opcode, which is what the JVM's `wide`
does and for the same reason: most opcodes here carry an index into the
constants, so a long form each would be that many numbers, names, handlers and
chances to forget one. A prefix is one of each, and it covers an opcode added
later for free. Measured free on the narrow path: `Fib (27)` interleaved
against the prior commit reads 0.98–0.99 s both ways.

⚠️ No count is quoted above, and the first draft of this entry quoted one — it
said nineteen, copied from this opcode's own doc comment, where the figure had
grown to twenty-four without anything noticing. That is the failure this file's
header warns about, reproduced inside an hour of warning about it.

Only the widenable operand widens. A count beside it stays a byte and a short
beside it is already two, so `OP_INVOKE_EXT` under the prefix reads a short, a
byte and a short.

⚠️ The flag is cleared on the **read**, not at the end of the instruction. That
is what lets the machine stay ignorant of where the index sits among the
operands — `OP_BUILTIN` carries it first and `OP_OVERLOADS` carries it second,
and both work. Clearing it at the end of the instruction instead leaves a
second prefixed instruction reading a byte where a short was written, and
every offset after that drifts. There is a test for exactly that pair.

<!-- reference.sh: not-an-opcode OP_WIDE -->
⚠️ It is `OP_LONG` and not `OP_WIDE` because **`OP_WIDEN` already exists** and
widens a *value* to a declared type. Two opcodes a letter apart meaning
unrelated things is a misreading waiting to happen, and it has happened here
once already — inside ten minutes, grepping a disassembly for one and matching
the other.

**Satisfies** — nothing directly. It is an encoding, not a language feature.

**See also** — `OP_WIDEN` (which is unrelated), `OP_CONSTANT`, `OP_GET_LOCAL`.

---

## OP_CLOSURE — Make A Closure

```
Encoding    [ 61 ][ i ][ s ]  then one 3-byte descriptor per capture

            i    constant index of the subprogram's body (widens)
            s    how many cells to capture

            descriptor:  [ b ][ s ]
                         b    1 = from this frame's own slot
                              0 = from a cell this frame captured
                         s    which slot, or which cell

            Total: 3 + 3n bytes, or 4 + 3n under OP_LONG.

            variable-width -- OpShape cannot describe this one
```

**Stack** — pops 0, pushes 1, needs 0. The closure is what it leaves.

⚠️ **This is the only variable-width instruction, and `OpShape` answers `''`
for it** — which is a deliberate lie that every walker has to know about.
`--list` special-cases it. The disassembler once treated it as a bare opcode,
which put every later offset out by the captures, so a listing of any chunk
containing a nested subprogram was fiction from that point on. Its doc comment
then claimed `run.a24` special-cased it while `run.a24` did not; a comment
stating a reason is still a claim.

**Operation** — reads the body from the constants, collects `n` cells from the
enclosing frame as the descriptors direct, and pushes a closure over them.

Closures here **box** rather than close over stack slots, which is what the C
back end already does for the same problem — so there is no open-upvalue list
and nothing to close when a frame returns. A subprogram that declares a nested
one boxes **every** local, conservatively, because working out exactly which
are captured needs a free-variable analysis and boxing too many costs only an
indirection.

The descriptor's flag is `clox`'s is-local flag under another name, and it is
the whole of what makes nesting work to any depth: a child's capture list is
its parent's locals followed by its parent's own captures, so a name reached
from three levels out is captured again at each level on the way down.

⚠️ Without that flag this was not a refusal but a **wrong answer**. The
grandchild took the plain-subprogram path, resolved an enclosing name to a
capture index anyway, and read cell 0 of a frame that had no cells —
`Index 0 out of range 0..-1.` The guard meant to refuse it sat in a function
that path never reached, and `conformance/0063` passes either way because its
middle subprogram has no locals to capture.

The count and the descriptor indices are **shorts unconditionally** rather than
bytes with a cap on them. The prefix is spent on the body's constant index and
at most one operand may widen, and this instruction runs once per closure made
rather than in the dispatch loop — so the fixed width costs nothing measurable
and removes the cap outright.

**Satisfies** — [FUN-009], [FUN-010], [FUN-012]. Capture by reference,
outliving the call, a fresh set per call, and nesting to any depth. All four
fall out of the cell being heap-allocated.

**See also** — `OP_CELL`, `OP_GET_CELL`, `OP_SET_CELL`, `OP_GET_BOX`,
`OP_SET_BOX`.

---

## OP_INVOKE_EXT — Invoke A Member, Or An Extension

```
Encoding    [ 68 ][ i ][ b ][ s ]                     5 bytes
                                                      6 under OP_LONG

            i    constant index of the member's name (widens)
            b    how many arguments were written
            s    the extension's global slot
```

**Stack** — pops n+1, pushes 1, needs n+1. The receiver sits beneath the
arguments, `b + 1` slots down from the top, and the call's result replaces the
whole window.

**Operation** — asks the receiver's **value** whether it has a member of the
name. Where it does, that member is invoked. Where it does not, the extension
in the given global slot is called with the receiver **prepended as its first
argument**, after which it is an ordinary call.

Both halves in one instruction, because nothing at the call site can decide it
earlier: a member wins, and only the running receiver can say whether there is
one. The type system is gradual, so `X.Size ()` may be a method on one value
and an extension on the next — the Resolver's `Extension` field says *could*,
not *does*.

This entry is the reason the operand kinds are worth a table of their own. It
carries three operands of three different widths, and it is the instruction
that proves the one-widenable-operand invariant holds: the name's index widens
under the prefix, the argument count never does, and the slot is a short
because an extension may live anywhere among a program's globals and one byte
reaches only the first 256.

⚠️ The receiver is **passed** to the prepend rather than read off the stack,
because the two callers keep it in different places — this instruction has it
in the callee's slot, while a bound extension carries it *inside* the value
sitting there. Taking it from the stack read the bound value itself as the
receiver, and the extension then asked a subprogram for its `Length`.

**Satisfies** — [EXP-022], [FUN-015], [FUN-016]. A member always wins; both
spellings of an extension call are one call, the receiver counting as the
argument it is.

**Raises** — `Undefined variable '<name>'.` where the extension's slot was
never defined, naming the global rather than the member.

Everything a call can raise, the extension path being an ordinary call from
the prepend onwards: `Can only call functions and classes.`,
`Expected <n> arguments but got <m>.`, `No matching signature for function.`

**See also** — `OP_INVOKE`, `OP_INVOKE_EXT_NAMED`, `OP_EXTEND`, `OP_CALL`.

---

## OP_OVERLOADS — Gather An Overload Set

```
Encoding    [ 62 ][ b ][ i ]                          3 bytes
                                                      4 under OP_LONG

            b    how many candidates to gather
            i    constant index of the shared name (widens)

            ⚠️ The index is the SECOND operand here.  OP_BUILTIN carries
            the same two the other way round.
```

**Stack** — pops n, pushes 1, needs n. The set replaces the candidates.

**Operation** — reads a window of `b` values from the top of the stack **by
index rather than by popping**, so the candidates keep declaration order, and
pushes a set holding them. Order decides a tie within a selection pass, and
popping would reverse it.

A set rather than a slot each, because the declarations share one name and
selection happens at the call, on the argument values.

⚠️ **This instruction is the reason an emitter must park candidates in slots.**
Reading a window from the top only works when a name's declarations are
*adjacent in the file*. Interleave two overloaded names — `Tint`, `Where`,
`Tint`, `Where` — and the window takes one candidate of each, so a perfectly
good call fails with `No matching signature for function.` Five lines reproduce
it, and the corpus cannot catch it: a focused test case declares a name's
variants together, where a library organised by topic declares `TextColor` and
`WhereY` long before their `Window`-taking variants. That one bug was ten of
`algol24-library`'s fourteen divergences.

⚠️ **It is also why the operand order matters more than it looks.** Rendering
"the first operand" as the widenable one would print this instruction wrongly
and put every later offset out, which is what `OpShape` telling `i` from `b`
exists to prevent. The machine itself does not care — it clears the flag on the
first index *read*, wherever that read falls — but a disassembler has to know.

**Satisfies** — [FUN-013], [EXP-013], [EXP-014]. Two declarations of one name
are an overload set; selection is at the call, on the values; and the passes
run exact, then widening, then absorbing, over the whole inheritance chain
before the next begins.

**See also** — `OP_BUILTIN` (the same two operands, reversed), `OP_CALL`,
`OP_CALL_NAMED`.
