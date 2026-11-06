# The Algol-24 Bytecode Reference

All **78 opcodes** of the bytecode machine, one uniform entry each, in the
shape of the 1987 IBM Macro Assembler 2.00 reference. Written toward an
assembly-like front end that would make these mnemonics syntax a program can
be written in, rather than names internal to the back end.

⚠️ **`vm/OpCode.a24` is the authority and this file never argues with it.**
Every encoding below is written by hand, so each is a claim about a number and
an operand layout the machine already knows — and 78 hand-written encodings
with nothing checking them would drift inside two increments. So
`./vm/reference.sh` compares each entry's number, operand letters, byte count
and stack effect against `OpCode.a24`, and `vm/Vm.a24`'s own tests hold the
stack effect to a RUN. An entry is therefore two steps from something that
executes.

⚠️ **What no script can check is whether a sentence is TRUE**, and the
citations are the sharpest case: the checker confirms a cited rule exists, not
that the rule says what the entry claims. Five citations of `[EXP-020]` —
operator overloading — were meant to be `[EXP-017]`, assignment being an
expression, and they had been copied into four files before anything noticed.
Read a citation as a pointer to check, never as a checked fact.

## How to read an entry

Each entry has the same six sections, in this order. A section with nothing to
say is omitted rather than filled with "none".

**Encoding** — the bytes, in order, inside a fence. The **first bracketed row
is read by `vm/reference.sh`**: its first bracket is the opcode's number in
decimal and the rest are its operand letters, which are compared against
`OpShape` and against the stated byte count. An instruction `OpShape` cannot
describe says `variable-width` in the fence, which exempts it from that
comparison and lists it in the checker's own report rather than hiding it.
**An opcode's number is not part of the interface**: opcodes are renumbered
from their declaration order in `vm/OpCode.a24` by a script, and inserting
one renumbers those above it. The *mnemonic* is the stable name. Nothing
should hard-code 37 for `OP_LIST`.

**Stack** — `pops P, pushes Q, needs R`, in slots, and **`vm/reference.sh`
compares all three against `OpStack` in `vm/OpCode.a24`**. This is the section
to read first. A correct emitter leaves a balanced stack, and the machine has
twice had a bug that produced the right answer while leaking a slot per
iteration — which is why the tests assert `SP` after a run and not only the
result.

`needs` is the least depth the instruction requires, and it is a third number
rather than the same as `pops` because an instruction may **read** the top
without taking it: `OP_DUP` and every assignment opcode need a value beneath
them and leave it there [EXP-017].

⚠️ **Of the three, two are measured and one is description.** `pushes - pops`
is what a run reveals, and `needs` is what running one value shallower reveals.
Both are asserted against the machine for **67 of the 78 opcodes**; the other
eleven are named in `vm/Vm.a24` with the reason each cannot be run in
isolation, and a test fails if an opcode has neither a measurement nor a
reason — so the coverage cannot shrink in silence.

The **split** is not observable from outside, because popping a value and
pushing two copies of it moves the stack exactly as reading it and pushing one
does; that was checked with distinct sentinels rather than assumed. So `pops`
and `pushes` separately say what the handler is written to mean, and a reader
should trust their difference further than either alone.

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

## Index

Entries are grouped by what an instruction is for, which is how
`vm/OpCode.a24` numbers them and how `clox` numbers its own. Alphabetically:

`OP_ADD`  `OP_BIT_AND`  `OP_BIT_NOT`  `OP_BIT_OR`  
`OP_BIT_XOR`  `OP_BUILTIN`  `OP_CALL`  `OP_CALL_NAMED`  
`OP_CAST`  `OP_CELL`  `OP_CLASS`  `OP_CLOSURE`  
`OP_CONSTANT`  `OP_DECLARE_PROPERTY`  `OP_DEFINE_GLOBAL`  `OP_DEFINE_GLOBAL_LONG`  
`OP_DIV`  `OP_DIVIDE`  `OP_DUP`  `OP_ENUM`  
`OP_ENUM_MEMBER`  `OP_EQUAL`  `OP_EXTEND`  `OP_FALSE`  
`OP_FIELD`  `OP_GET_BOX`  `OP_GET_CELL`  `OP_GET_FIELD`  
`OP_GET_GLOBAL`  `OP_GET_GLOBAL_LONG`  `OP_GET_LOCAL`  `OP_GREATER`  
`OP_IN`  `OP_INHERIT`  `OP_INVOKE`  `OP_INVOKE_EXT`  
`OP_INVOKE_EXT_NAMED`  `OP_INVOKE_NAMED`  `OP_IS`  `OP_ITER`  
`OP_JUMP`  `OP_JUMP_IF_FALSE`  `OP_LESS`  `OP_LIST`  
`OP_LONG`  `OP_LOOP`  `OP_MAP`  `OP_METHOD`  
`OP_MOD`  `OP_MULTIPLY`  `OP_NEGATE`  `OP_NIL`  
`OP_NOT`  `OP_OVERLOADS`  `OP_POP`  `OP_PRINT`  
`OP_PROPERTY`  `OP_RAISE`  `OP_RETURN`  `OP_SET_BOX`  
`OP_SET_CELL`  `OP_SET_FIELD`  `OP_SET_GLOBAL`  `OP_SET_GLOBAL_LONG`  
`OP_SET_LOCAL`  `OP_SHIFT_LEFT`  `OP_SHIFT_RIGHT`  `OP_SINGLETON`  
`OP_SUBRANGE`  `OP_SUBSCRIPT_GET`  `OP_SUBSCRIPT_SET`  `OP_SUBTRACT`  
`OP_SUPER`  `OP_THIS`  `OP_TRUE`  `OP_TRY`  
`OP_UNTRY`  `OP_WIDEN`  

---

# Constants and literals

## OP_CONSTANT — Push A Constant

```
Encoding    [ 0 ][ i ]                        2 bytes
                                              3 under OP_LONG

            i    index into the chunk's constant table (widens)
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes the constant its operand names. Every literal a
program writes arrives this way, and so does every NAME the machine needs at
run time -- a field, a method, a type, a built-in -- because a member name
cannot be reached from a value in this language and has to be written into
the chunk as a literal.

The constants are INTERNED by type and then by value, which is not an
optimization but a fix: `AddConstant` once appended without interning, so
four hundred globals each initialized to `7` took four hundred slots and a
chunk ran out. The type is compared first because `1` and `1.0` compare
equal and render differently, and an OBJECT is never interned -- two
subprogram bodies that compare equal are still two subprograms.

**See also** — `OP_LONG`, `OP_NIL`, `OP_TRUE`, `OP_FALSE`.

## OP_NIL — Push Nil

```
Encoding    [ 1 ]                             1 byte
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes nil. Emitted for the literal, for a declaration with
no initializer, and as the value of a subprogram that runs off its end.

nil has NO TYPE, which is why `nil is X` is false for every X while `nil as
X` passes for every X [VAR-005]. Neither follows from this instruction; both
are decided by `OP_IS` and `OP_CAST`, and the two differ by one line each
for exactly this reason.

**See also** — `OP_TRUE`, `OP_FALSE`, `OP_CONSTANT`, `OP_IS`, `OP_CAST`.

## OP_TRUE — Push True

```
Encoding    [ 2 ]                             1 byte
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes True. A dedicated opcode rather than a constant, as
`clox` has it: a Boolean literal is common enough to be worth one byte
instead of two and a table slot.

**See also** — `OP_FALSE`, `OP_NIL`, `OP_NOT`.

## OP_FALSE — Push False

```
Encoding    [ 3 ]                             1 byte
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes False.

False is falsey and so is the Integer `0`, but they are not the same value:
`0 = False` is false. Truthiness is a question asked of a value, not a
conversion applied to one.

**See also** — `OP_TRUE`, `OP_NIL`, `OP_NOT`.

## OP_LIST — Build A List

```
Encoding    [ 37 ][ s ]                       3 bytes

            s    how many elements to take
```

**Stack** — pops n, pushes 1, needs n.

**Operation** — Builds a List from the n values above it and replaces them
with it. A literal rather than a constructor call: `[1, 2, 3]` is a
collection expression whose elements are expressions, so they are evaluated
onto the stack and gathered here.

The elements are read off the stack BY INDEX rather than popped, because
popping reverses them -- and a reversed list literal reads as a bug in the
parser rather than in the back end.

The count is a short, so what bounds a literal is the value stack it is
built on and not an operand width. A literal too large answers `The value
stack overflowed.` at run time, which is better than refusing a program the
machine could nearly hold.

**Satisfies** — [COL-001].

**Raises** — `The value stack overflowed.` for a literal larger than the
stack can hold.

**See also** — `OP_MAP`, `OP_CONSTANT`, `OP_SUBSCRIPT_GET`.

## OP_MAP — Build A Map

```
Encoding    [ 38 ][ s ]                       3 bytes

            s    how many PAIRS to take -- twice that many values
```

**Stack** — pops 2n, pushes 1, needs 2n.

**Operation** — Builds a Map from the n key-and-value pairs above it, key
first in each pair, and replaces them with it.

A Map keyed by a String is not reachable with a Char key: `['n': 21]` keys
it with a **Char** [TYP-003], and a reader asking for `Str ('n')` finds
nothing. That is the language's answer and not this instruction's, but it is
where it is usually met.

**Satisfies** — [COL-001].

**Raises** — `The value stack overflowed.` for a literal larger than the
stack can hold.

**See also** — `OP_LIST`, `OP_IN`, `OP_SUBSCRIPT_GET`.

---

# The stack itself

## OP_POP — Discard The Top

```
Encoding    [ 4 ]                             1 byte
```

**Stack** — pops 1, pushes 0, needs 1.

**Operation** — Discards the value on top. Emitted after an expression used
as a statement, for each local going out of scope at the end of a block, and
by `break` and `continue` for every local declared since the loop opened.

⚠️ A jump out of a loop must close what it jumped out of -- the locals with
an `OP_POP` each AND every `try` opened inside it with an `OP_UNTRY`, since
the jump skips the one the `try` would have run. Without that the handler
stack keeps an entry whose frame and stack depths are stale, and the NEXT
raise unwinds to it. The corpus passed before that was fixed, by luck.

**Raises** — `The value stack underflowed.` when there is nothing to
discard, which means the bytecode is wrong rather than the program.

**See also** — `OP_DUP`, `OP_UNTRY`, `OP_JUMP`.

## OP_DUP — Duplicate The Top

```
Encoding    [ 51 ]                            1 byte
```

**Stack** — pops 0, pushes 1, needs 1.

**Operation** — Pushes a second copy of the value on top. Wanted by the
chain an `except` compiles to: each arm tests the raised value's type and
must leave it for the next arm to test.

⚠️ Its declared `0 1 1` is the reason the stack vocabulary carries three
terms rather than two. Declaring it `1 2` instead passes every check a two-
term model can make -- the net is the same, and it does fail on an empty
stack -- so `pops` and `needs` are different questions, and an instruction
may read the top without taking it.

**See also** — `OP_POP`, `OP_TRY`, `OP_RAISE`.

---

# Locals

## OP_GET_LOCAL — Push A Local

```
Encoding    [ 5 ][ l ]                        2 bytes
                                              3 under OP_LONG

            l    the slot, counted from the frame's base (widens)
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes a local, read from its stack slot. A local LIVES in
the slot the expression stack grew it into, so reading one is a subscript
and not a lookup -- which is the whole reason a compiler resolves locals
before emitting anything.

Measured at 13.1 M instructions a second against a global's 12.8, over a
realistic mix.

**See also** — `OP_SET_LOCAL`, `OP_GET_BOX`, `OP_GET_GLOBAL`, `OP_LONG`.

## OP_SET_LOCAL — Store A Local

```
Encoding    [ 6 ][ l ]                        2 bytes
                                              3 under OP_LONG

            l    the slot, counted from the frame's base (widens)
```

**Stack** — pops 0, pushes 0, needs 1.
The value stays, which is why this pops nothing.

**Operation** — Stores the top into a local's slot and LEAVES it on the
stack.

It stays because assignment is an expression [EXP-017]: `X := (Y := 1)`
leaves both at 1. A statement that discards the value emits an `OP_POP` of
its own; an expression that uses it does not.

**Satisfies** — [EXP-017].

**See also** — `OP_GET_LOCAL`, `OP_SET_BOX`, `OP_SET_GLOBAL`, `OP_POP`.

---

# Globals

## OP_GET_GLOBAL — Push A Global

```
Encoding    [ 7 ][ b ]                        2 bytes

            b    the slot -- a plain byte, never widened
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes a global, read from its slot.

⚠️ A SLOT and not a name, and this is where the machine departs from `clox`
deliberately. The Resolver binds every variable before emission, so a
module-level one gets a fixed index and a subscript instead of a hash per
access. Two consequences: an emitter needs a PRE-PASS, because a module-
level subprogram may refer to a global declared below it; and the chunk
still carries `GlobalNames`, read ONLY to say which variable was undefined.

A global slot must mean the same thing in every chunk of one program. A
table per chunk let a subprogram resolve its own name to slot 0 of its own
table where the caller had it in slot 2 of the script's, so recursion read
the wrong variable and answered 28 where 55 was right. Every global resolves
against the outermost chunk.

**Raises** — `Undefined variable '<name>'.` for a slot nothing has defined
-- a read from above the declaration that defines it. A declaration is what
defines a global, so `var X;` is nil while a read above it raises.

**See also** — `OP_GET_GLOBAL_LONG`, `OP_DEFINE_GLOBAL`, `OP_SET_GLOBAL`,
`OP_GET_LOCAL`.

## OP_GET_GLOBAL_LONG — Push A Global From A Wide Slot

```
Encoding    [ 64 ][ s ]                       3 bytes

            s    the slot, as a short
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes a global whose slot one byte cannot reach. The
emitter picks the narrow form wherever the slot fits, which is `clox`'s
split for its constants kept for its reason: a global read is in the
dispatch loop.

One byte addresses 256 globals, and a real program is nowhere near that --
shroom-slots and its library declare about 1,700 names between them, so this
form is not an exotic case but the ordinary one above the first 256.
Measured at no cost: Fib (27) is 0.96 s against 0.95 s before the split
existed.

**Raises** — `Undefined variable '<name>'.`, as the narrow form does.

**See also** — `OP_GET_GLOBAL`, `OP_DEFINE_GLOBAL_LONG`,
`OP_SET_GLOBAL_LONG`.

## OP_DEFINE_GLOBAL — Define A Global

```
Encoding    [ 8 ][ b ]                        2 bytes

            b    the slot -- a plain byte, never widened
```

**Stack** — pops 1, pushes 0, needs 1.

**Operation** — Pops a value and defines a global with it. This is a
DECLARATION executing, which is what makes the global defined: `var X;` with
no initializer defines it as nil rather than leaving it undefined.

⚠️ Writing to a global does NOT define it -- only a declaration does. That
asymmetry is what lets a read from above a declaration raise while the
declaration itself may store nil.

**Satisfies** — [DCL-001].

**See also** — `OP_DEFINE_GLOBAL_LONG`, `OP_GET_GLOBAL`, `OP_SET_GLOBAL`.

## OP_DEFINE_GLOBAL_LONG — Define A Global At A Wide Slot

```
Encoding    [ 65 ][ s ]                       3 bytes

            s    the slot, as a short
```

**Stack** — pops 1, pushes 0, needs 1.

**Operation** — Pops a value and defines a global whose slot one byte cannot
reach.

**Satisfies** — [DCL-001].

**See also** — `OP_DEFINE_GLOBAL`, `OP_GET_GLOBAL_LONG`,
`OP_SET_GLOBAL_LONG`.

## OP_SET_GLOBAL — Store A Global

```
Encoding    [ 9 ][ b ]                        2 bytes

            b    the slot -- a plain byte, never widened
```

**Stack** — pops 0, pushes 0, needs 1.
The value stays.

**Operation** — Stores the top into a global's slot and leaves it there, for
the reason `OP_SET_LOCAL` gives [EXP-017].

**Satisfies** — [EXP-017].

**Raises** — `Undefined variable '<name>'.` for a slot nothing has defined.
A write does not define a global; it requires one.

**See also** — `OP_SET_GLOBAL_LONG`, `OP_DEFINE_GLOBAL`, `OP_SET_LOCAL`.

## OP_SET_GLOBAL_LONG — Store A Global At A Wide Slot

```
Encoding    [ 66 ][ s ]                       3 bytes

            s    the slot, as a short
```

**Stack** — pops 0, pushes 0, needs 1.
The value stays.

**Operation** — Stores the top into a wide global slot and leaves it there.

**Satisfies** — [EXP-017].

**Raises** — `Undefined variable '<name>'.`, as the narrow form does.

**See also** — `OP_SET_GLOBAL`, `OP_GET_GLOBAL_LONG`,
`OP_DEFINE_GLOBAL_LONG`.

---

# Cells, and the closures over them

## OP_CELL — Box The Top

```
Encoding    [ 56 ]                            1 byte
```

**Stack** — pops 1, pushes 1, needs 1.

**Operation** — Replaces the value on top with a heap cell holding it.
Emitted for a local that a nested subprogram can see, so the slot holds the
CELL from the moment the local is declared.

Closures here BOX rather than closing over stack slots, which is what the C
back end already does for the same problem -- so there is no open-upvalue
list and nothing to close when a frame returns. A subprogram that declares a
nested one boxes EVERY local, conservatively: working out exactly which are
captured needs a free-variable analysis, and boxing too many costs only an
indirection.

Capture by reference, outliving the call, and a fresh set per call all fall
out of the cell being heap-allocated rather than needing anything of their
own [FUN-009], [FUN-010].

**Satisfies** — [FUN-009], [FUN-010].

**See also** — `OP_CLOSURE`, `OP_GET_BOX`, `OP_SET_BOX`, `OP_GET_CELL`.

## OP_GET_BOX — Push What A Boxed Local Holds

```
Encoding    [ 57 ][ l ]                       2 bytes
                                              3 under OP_LONG

            l    the slot holding the cell (widens)
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes what the cell in a local slot holds -- one
instruction, where the slot holds the cell and the cell holds the value. For
the ENCLOSING subprogram, whose boxed locals sit in slots; the nested one
reads the same cells through `OP_GET_CELL`, having them as captures rather
than as locals.

**See also** — `OP_SET_BOX`, `OP_CELL`, `OP_GET_CELL`, `OP_GET_LOCAL`.

## OP_SET_BOX — Store Into A Boxed Local

```
Encoding    [ 58 ][ l ]                       2 bytes
                                              3 under OP_LONG

            l    the slot holding the cell (widens)
```

**Stack** — pops 0, pushes 0, needs 1.
The value stays.

**Operation** — Stores the top into the cell in a local slot and leaves it
on the stack.

**Satisfies** — [EXP-017].

**See also** — `OP_GET_BOX`, `OP_SET_CELL`, `OP_SET_LOCAL`.

## OP_GET_CELL — Push What A Captured Cell Holds

```
Encoding    [ 59 ][ l ]                       2 bytes
                                              3 under OP_LONG

            l    the capture's index (widens)
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes what one of this frame's captured cells holds. The
index is the position the closure's descriptors put it in, so a capture is
found by NAME at emit time and by INDEX at run time.

This is also how a nested subprogram reaches an enclosing method's RECEIVER.
A method whose body declares a nested subprogram boxes `this` as a local of
that name, which is the whole of what makes it reachable: a capture is found
by name among the enclosing locals, so `this` has to be one of them.

**Satisfies** — [FUN-009], [FUN-012].

**See also** — `OP_SET_CELL`, `OP_CLOSURE`, `OP_GET_BOX`, `OP_THIS`.

## OP_SET_CELL — Store Into A Captured Cell

```
Encoding    [ 60 ][ l ]                       2 bytes
                                              3 under OP_LONG

            l    the capture's index (widens)
```

**Stack** — pops 0, pushes 0, needs 1.
The value stays.

**Operation** — Stores the top into one of this frame's captured cells and
leaves it on the stack. A write through a capture is visible to every
closure over the same cell and to the subprogram that made it, which is what
capture by reference means [FUN-009].

**Satisfies** — [EXP-017], [FUN-009].

**See also** — `OP_GET_CELL`, `OP_SET_BOX`, `OP_CLOSURE`.

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

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Reads the body from the constants, collects n cells from the
enclosing frame as the descriptors direct, and pushes a closure over them.

A descriptor is a flag byte and a short: the flag says whether the cell
comes from this frame's own SLOT -- which holds a cell, since a frame that
declares a nested subprogram boxes every local -- or from a cell this frame
itself CAPTURED. That second case is `clox`'s is-local flag under another
name, and it is the whole of what makes nesting work to any depth: a child's
capture list is its parent's locals followed by its parent's own captures,
so a name reached from three levels out is captured again at each level on
the way down.

⚠️ This is the only variable-width instruction, and `OpShape` answers `''`
for it -- a deliberate lie every walker has to know about. `--list` special-
cases it. The disassembler once treated it as a bare opcode, which put every
later offset out by the captures, so a listing of any chunk containing a
nested subprogram was fiction from that point on. Its doc comment then
claimed `run.a24` special-cased it while `run.a24` did not; a comment
stating a reason is still a claim.

⚠️ Without the flag this was not a refusal but a WRONG ANSWER. A subprogram
two deep took the plain-subprogram path, resolved an enclosing name to a
capture index anyway, and read cell 0 of a frame that had no cells -- `Index
0 out of range 0..-1.` The guard meant to refuse it sat in a function that
path never reached, and `conformance/0063` passes either way because its
middle subprogram has no locals to capture.

The count and the descriptor indices are SHORTS unconditionally rather than
bytes with a cap. The prefix is spent on the body's constant index and at
most one operand may widen, and this instruction runs once per closure made
rather than in the dispatch loop -- so the fixed width costs nothing
measurable and removes the cap outright.

**Satisfies** — [FUN-009], [FUN-010], [FUN-012]. Capture by reference,
outliving the call, a fresh set per call, and nesting to any depth -- all
four falling out of the cell being heap-allocated.

**See also** — `OP_CELL`, `OP_GET_CELL`, `OP_SET_CELL`, `OP_GET_BOX`,
`OP_SET_BOX`.

---

# Arithmetic

## OP_ADD — Add

```
Encoding    [ 13 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two values and pushes their sum. The HOST's own `+`
decides it, so `+` concatenates when either operand is text and converts the
other [EXP-008], an Integer result never overflows but grows [EXP-007], and
a Double on either side promotes the result [EXP-005]. None of that is this
instruction's doing, and that is the point: a guest value IS a host value,
so the machine cannot hold a second opinion about arithmetic.

A class may define `+` for its own instances [EXP-020], and an instance
operand is sent to that method before the host is asked.

**Satisfies** — [EXP-004], [EXP-005], [EXP-007], [EXP-008], [EXP-020],
[LEX-018].

**Raises** — `Operands must be two numbers, or two strings.`

**See also** — `OP_SUBTRACT`, `OP_MULTIPLY`, `OP_DIVIDE`, `OP_NEGATE`.

## OP_SUBTRACT — Subtract

```
Encoding    [ 14 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two values and pushes the lower less the upper.

**Satisfies** — [EXP-004], [EXP-005], [EXP-007], [EXP-020].

**Raises** — `Operands must be numbers.`

**See also** — `OP_ADD`, `OP_NEGATE`, `OP_MULTIPLY`.

## OP_MULTIPLY — Multiply

```
Encoding    [ 15 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two values and pushes their product.

**Satisfies** — [EXP-004], [EXP-005], [EXP-007], [EXP-020].

**Raises** — `Operands must be numbers.`

**See also** — `OP_ADD`, `OP_DIVIDE`, `OP_DIV`.

## OP_DIVIDE — Divide

```
Encoding    [ 16 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two values and pushes the quotient, which is ALWAYS a
Double: `/` is real division in this language, so `7 / 2` is 3.5 and `4 / 2`
is `2.0` [EXP-004].

⚠️ Division by zero is NOT an error here. `7 / 0` yields `Infinity`, and `0
/ 0` a `NaN` [EXP-006]. `OP_DIV` and `OP_MOD` are the two that raise, which
is why they are separate opcodes and not this one rounded.

**Satisfies** — [EXP-004], [EXP-005], [EXP-006], [EXP-020].

**Raises** — nothing for a zero divisor. `Operands must be numbers.`
otherwise.

**See also** — `OP_DIV`, `OP_MOD`, `OP_MULTIPLY`.

## OP_DIV — Integer Divide

```
Encoding    [ 17 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two Integers and pushes the quotient, truncated toward
zero. Not `OP_DIVIDE` rounded: `div` REFUSES a Double rather than truncating
it, and it is one of the two things in the language that raise on a zero
divisor.

⚠️ `div` is not `>>`. This truncates toward zero where a right shift floors,
so `-7 div 2` is -3 and `-7 >> 1` is -4 [EXP-024]. They agree whenever the
shifted-out bits are zero, which is what makes the difference easy to miss.

**Satisfies** — [EXP-004], [EXP-020], [EXP-024].

**Raises** — `div expects Integers.` for a Double operand, and `Division by
zero.` for a zero divisor.

**See also** — `OP_MOD`, `OP_DIVIDE`, `OP_SHIFT_RIGHT`.

## OP_MOD — Integer Remainder

```
Encoding    [ 18 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two Integers and pushes the remainder. The `div` pair:
it refuses a Double and raises on a zero divisor.

There is no `Mod` built-in. `mod` is an operator and only an operator.

**Satisfies** — [EXP-004], [EXP-020].

**Raises** — `mod expects Integers.` for a Double operand, and `Division by
zero.` for a zero divisor.

**See also** — `OP_DIV`, `OP_DIVIDE`.

## OP_NEGATE — Negate

```
Encoding    [ 28 ]                            1 byte
```

**Stack** — pops 1, pushes 1, needs 1.

**Operation** — Replaces the number on top with its negation. A class may
define unary `-` for its own instances [EXP-020].

**Satisfies** — [EXP-020].

**Raises** — `Operand must be a number.`

**See also** — `OP_SUBTRACT`, `OP_NOT`, `OP_BIT_NOT`.

---

# Bitwise

## OP_BIT_AND — Bitwise And

```
Encoding    [ 20 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two Integers and pushes their bitwise and. Over an
Integer that is two's complement extended infinitely to the left, so nothing
here has to know how wide an Integer is -- the host's operators already do
not [EXP-023], [LEX-018].

⚠️ `and` is NOT this. `and` tests truthiness and yields an operand
[EXP-010], so `6 and 3` is 3 where `6 & 3` is 2 -- the Pascal reader's trap,
and a `[WARN]` in the front end where an operand's type is Integer.

**Satisfies** — [EXP-023], [LEX-018].

**Raises** — `& expects Integers.`

**See also** — `OP_BIT_OR`, `OP_BIT_XOR`, `OP_BIT_NOT`, `OP_JUMP_IF_FALSE`.

## OP_BIT_OR — Bitwise Or

```
Encoding    [ 21 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two Integers and pushes their bitwise or.

**Satisfies** — [EXP-023].

**Raises** — `| expects Integers.`

**See also** — `OP_BIT_AND`, `OP_BIT_XOR`, `OP_BIT_NOT`.

## OP_BIT_XOR — Bitwise Exclusive Or

```
Encoding    [ 22 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two Integers and pushes their bitwise exclusive or.

**Satisfies** — [EXP-023].

**Raises** — `^ expects Integers.`

**See also** — `OP_BIT_AND`, `OP_BIT_OR`, `OP_BIT_NOT`.

## OP_BIT_NOT — Bitwise Complement

```
Encoding    [ 23 ]                            1 byte
```

**Stack** — pops 1, pushes 1, needs 1.

**Operation** — Replaces the Integer on top with its bitwise complement.
Two's complement extended infinitely to the left, so `~0` is -1 [EXP-023].

**Satisfies** — [EXP-023].

**Raises** — `~ expects an Integer.` -- singular, where the binary six say
`Integers`.

**See also** — `OP_BIT_AND`, `OP_NEGATE`, `OP_NOT`.

## OP_SHIFT_LEFT — Shift Left

```
Encoding    [ 24 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two Integers and shifts the lower left by the upper. An
Integer is unbounded, so a shift GROWS rather than discarding the high bits:
`1 << 70` is an exact power of two [EXP-023], [LEX-018].

**Satisfies** — [EXP-023], [LEX-018].

**Raises** — `<< expects Integers.`

**See also** — `OP_SHIFT_RIGHT`, `OP_BIT_AND`.

## OP_SHIFT_RIGHT — Shift Right

```
Encoding    [ 25 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two Integers and shifts the lower right by the upper.
FLOORS where `div` truncates toward zero, so `-7 >> 1` is -4 and `-7 div 2`
is -3 [EXP-024] -- which is why the two are separate opcodes and neither is
the other with a sign fixed up.

**Satisfies** — [EXP-024].

**Raises** — `>> expects Integers.`

**See also** — `OP_SHIFT_LEFT`, `OP_DIV`.

---

# Comparison and truth

## OP_EQUAL — Compare Equal

```
Encoding    [ 10 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two values and pushes whether they are equal. Host
equality, so a Char and a one-character String are UNEQUAL here exactly as
they are everywhere else in the language [TYP-003], and class instances,
collections and enumeration members compare by identity rather than contents
[VAL-011].

A class may define `Compare` and have it consulted [VAL-014].

**Satisfies** — [VAL-011], [VAL-013], [VAL-014].

**See also** — `OP_GREATER`, `OP_LESS`, `OP_IN`, `OP_NOT`.

## OP_GREATER — Compare Greater

```
Encoding    [ 11 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two values and pushes whether the lower is greater than
the upper.

Enumeration members are NOT ordered: `RED < GREEN` is `Operands must be
numbers.` [ENU-008]. Their ordinal is reachable, and comparing that is the
program's business.

**Satisfies** — [ENU-008], [VAL-014].

**Raises** — `Operands must be numbers.`

**See also** — `OP_LESS`, `OP_EQUAL`.

## OP_LESS — Compare Less

```
Encoding    [ 12 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops two values and pushes whether the lower is less than
the upper.

**Satisfies** — [ENU-008], [VAL-014].

**Raises** — `Operands must be numbers.`

**See also** — `OP_GREATER`, `OP_EQUAL`.

## OP_NOT — Logical Not

```
Encoding    [ 27 ]                            1 byte
```

**Stack** — pops 1, pushes 1, needs 1.

**Operation** — Replaces the top with whether it was falsey. Falsey is this
language's reading and not Lox's: nil, False, the Integer `0` and an
enumeration member of ordinal zero are falsey, where `0.0`, the empty String
and any Char are truthy.

⚠️ This goes through the MACHINE's own truthiness and not the host's, and it
is the one place the machine must not defer. The host sees one of the
machine's objects for an enum member and calls every object truthy, so a
member of ordinal zero would come back true [ENU-009].

**Satisfies** — [ENU-009].

**See also** — `OP_JUMP_IF_FALSE`, `OP_TRUE`, `OP_FALSE`, `OP_BIT_NOT`.

## OP_IN — Test Membership

```
Encoding    [ 19 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Pops a value and a collection and pushes whether the
collection has it. The host's own `in` decides it, which is what makes a Map
test its KEYS and a String test for a substring without this instruction
knowing the difference.

**Satisfies** — [VAL-013], [COL-001].

**Raises** — `Right operand of 'in' must be a collection or a String.`

**See also** — `OP_EQUAL`, `OP_ITER`, `OP_MAP`.

---

# Types

## OP_IS — Test A Type

```
Encoding    [ 26 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the type's NAME (widens)
```

**Stack** — pops 1, pushes 1, needs 1.

**Operation** — Replaces the top with whether it is of the written type. A
RANGE test for a subrange and a type test otherwise, which is what the
host's own `is` already decides -- so this asks it rather than
reimplementing it.

⚠️ `is` and `as` are not the same rule, in two places. `nil` has no type, so
`nil is X` is false for every X where `nil as X` passes [VAR-005]; and `is
Any` is FALSE for everything where `as Any` always passes, `Any` being the
absence of a written type rather than a type a value can be tested against.
Both were true-for-everything first, and both are one-line differences in
two handlers that look like they should agree.

⚠️ `5 is Dog` answers false, not an error. A type name the MACHINE cannot
test is the emitter's job to refuse; a declared class the value simply isn't
is a fair question with a boring answer. Raising on it reported a gap that
was not there.

A type missing from the machine's chain cannot be refused, only mis-
answered: `Pointer` was once absent, so every Pointer reported its type as
`Any`, satisfied no declared type, and an overload taking one failed to
select -- reported as `No matching signature for function.`, which names the
call and not the cause. A Pointer is only a VALUE under `--ffi` [TYP-017];
the TEST is answerable always.

**Satisfies** — [TYP-001], [TYP-002], [TYP-017], [VAR-005], [ENU-006].

**See also** — `OP_CAST`, `OP_WIDEN`, `OP_SUBRANGE`.

## OP_CAST — Check A Type

```
Encoding    [ 55 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the type's NAME (widens)
```

**Stack** — pops 0, pushes 0, needs 1.
The value is read and left where it was.

**Operation** — Checks the value on top against a type and LEAVES it. `as`
is a check and not a conversion: it answers the same value or raises.

⚠️ Dropping it silently made `'text' as Integer` answer `'text'`. A cast
that converts nothing still has to fail.

nil satisfies every type and so passes every cast [VAR-005], and `as Any`
always passes.

**Satisfies** — [TYP-001], [VAR-005].

**Raises** — `Cannot cast <type> to <type>.`

**See also** — `OP_IS`, `OP_WIDEN`.

## OP_WIDEN — Widen To A Declared Type

```
Encoding    [ 47 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the type's NAME (widens)
```

**Stack** — pops 1, pushes 1, needs 1.

**Operation** — Widens the value on top to a declared type: Integer to
Double and Char to String, and nothing else, which is the whole of what the
language's widening does [VAL-001], [VAL-002], [VAR-004].

⚠️ There are FIVE assignment contexts, not one: a declaration, an
assignment, a PARAMETER, a declared RETURN TYPE, and a FIELD. Missing any of
them is a quietly wrong number rather than a failure, and `conformance/0140`
names all five.

A subrange annotation widens nothing and instead CHECKS, which is
`OP_SUBRANGE`'s business -- the bounds live in a table the chunk has to be
told about.

**Satisfies** — [VAL-001], [VAL-002], [VAR-004].

**Raises** — `<value> is not in <name>.` where the declared type is a
subrange and the value is outside it.

**See also** — `OP_CAST`, `OP_IS`, `OP_SUBRANGE`.

## OP_SUBRANGE — Record A Subrange's Bounds

```
Encoding    [ 76 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    a constant holding the name, the low bound and the high bound
                 (widens)
```

**Stack** — pops 0, pushes 0, needs 0.

**Operation** — Records a subrange's bounds in the machine's own table.
Emitted once per subrange before anything else runs, which is what the C
back end does with `alg_subrange` in a unit's initializer -- so the three
processors answer a range check from one shape of table rather than three.

The bounds travel as a CONSTANT and never as operands, because an Integer is
unbounded [LEX-018] and `type Big = 0..99999999999999999999` is legal.

**Satisfies** — [TYP-002], [LEX-018].

**See also** — `OP_WIDEN`, `OP_IS`, `OP_CAST`.

---

# Control flow

## OP_JUMP — Jump

```
Encoding    [ 30 ][ s ]                       3 bytes

            s    the distance, high byte first, unsigned and forward only
```

**Stack** — pops 0, pushes 0, needs 0.

**Operation** — Jumps forward unconditionally.

⚠️ `IP := IP + ReadShort ()` is a bug, and it fails as a plausible wrong
answer: the left `IP` is read before `ReadShort` advances past the two
operand bytes, so the jump lands two bytes short -- on the operand of
whatever follows. Read the distance into a local first.

**See also** — `OP_LOOP`, `OP_JUMP_IF_FALSE`.

## OP_JUMP_IF_FALSE — Jump If Falsey

```
Encoding    [ 31 ][ s ]                       3 bytes

            s    the distance, high byte first, unsigned and forward only
```

**Stack** — pops 0, pushes 0, needs 1.
Deliberately does not pop.

**Operation** — Jumps forward when the value on top is falsey, WITHOUT
popping it.

Leaving the value is what lets `and` and `or` need no opcodes of their own,
and they must not get any: they yield an OPERAND [EXP-010], which is exactly
what a jump plus an `OP_POP` produces. The operand is still there for the
next instruction to use.

Truthiness goes through the machine's own and not the host's, for the reason
`OP_NOT` gives: an enumeration member of ordinal zero is falsey and the host
would call it truthy [ENU-009].

**Satisfies** — [EXP-009], [EXP-010], [ENU-009].

**See also** — `OP_JUMP`, `OP_NOT`, `OP_POP`, `OP_LOOP`.

## OP_LOOP — Jump Backward

```
Encoding    [ 33 ][ s ]                       3 bytes

            s    the distance, high byte first, subtracted
```

**Stack** — pops 0, pushes 0, needs 0.

**Operation** — Jumps backward. A separate opcode from `OP_JUMP` rather than
a signed operand, because a distance that is always subtracted needs no sign
and a byte pair that is never negative is easier to read in a disassembly.

⚠️ Assert `SP` after a run, not just the answer. A backward jump landing
early still computes the right result when the result is read from a local
slot, while leaking a value per iteration -- that passed 25 tests. A correct
emitter leaves a balanced stack, and checking it is what catches the class.

`continue` lands on the INCREMENT, not the condition. One target serves both
loop forms -- a counted `for` runs its step and falls into the backward
jump, a `while` has no step and falls straight into it -- which is also why
`continue` needs no backward jump of its own.

**Satisfies** — [STM-009].

**See also** — `OP_JUMP`, `OP_JUMP_IF_FALSE`, `OP_POP`.

---

# Exceptions

## OP_TRY — Open A Protected Region

```
Encoding    [ 52 ][ s ]                       3 bytes

            s    the distance to its handlers
```

**Stack** — pops 0, pushes 0, needs 0.

**Operation** — Opens a protected region, recording where to resume AND the
call depth and the stack depth it was opened at -- so a raise several frames
down can put all three back before the handler runs.

Exceptions are a handler stack and not `setjmp`. A raise does not travel as
a host exception, because a raised value may be any value at all and a host
exception carries a String.

One `try` wraps the whole dispatch loop as well, which is what makes a
RUNTIME error catchable [STM-020]: a host error arrives as a String and
becomes a raise of it. One try for the run rather than one per instruction,
and it still costs about 15% -- Fib (27) was 0.79 s before exceptions
existed and is 0.91 s with them.

**Satisfies** — [STM-017], [STM-020].

**Raises** — `Too many nested try blocks.`

**See also** — `OP_UNTRY`, `OP_RAISE`, `OP_DUP`, `OP_JUMP`.

## OP_UNTRY — Close A Protected Region

```
Encoding    [ 53 ]                            1 byte
```

**Stack** — pops 0, pushes 0, needs 0.

**Operation** — Closes the innermost protected region without raising -- the
`try` completed, so its handlers are no longer reachable.

⚠️ `break` and `continue` must emit one of these for every `try` opened
inside the loop they leave, as well as an `OP_POP` per local. The jump skips
the `OP_UNTRY` the `try` would have run, so the handler stack keeps an entry
whose frame and stack depths are stale and the NEXT raise unwinds to it.

**Satisfies** — [STM-017].

**See also** — `OP_TRY`, `OP_RAISE`, `OP_POP`.

## OP_RAISE — Raise

```
Encoding    [ 54 ]                            1 byte
```

**Stack** — pops 1, pushes 0, needs 1.

**Operation** — Pops a value and raises it, unwinding the machine's own
handler stack to the innermost protected region -- restoring the call depth
and the stack depth that region recorded.

`except` arms are ordered MOST DERIVED FIRST by the emitter, because they
compile to a chain of type tests that runs in order -- so the order IS the
selection rule [STM-018]. The catch-all is keyed `'default'` by the parser
and always goes last [STM-019].

A raise with nothing protecting it escapes as the same String the
interpreter reports [RT-012].

**Satisfies** — [STM-017], [STM-018], [STM-019], [RT-012].

**Raises** — whatever value the program raised, which may be of any type.

**See also** — `OP_TRY`, `OP_UNTRY`, `OP_DUP`.

---

# Calls

## OP_CALL — Call

```
Encoding    [ 32 ][ b ]                       2 bytes

            b    the argument count
```

**Stack** — pops n+1, pushes 1, needs n+1.

**Operation** — Calls the value beneath its arguments. The callee is pushed
first and the arguments after it, so at the call the callee sits at `SP -
count - 1`.

⚠️ The new frame's slot 0 is the FIRST ARGUMENT, which differs from `clox`,
where slot 0 is the callee. Here the callee's slot is one BELOW the base,
which is also where `OP_THIS` finds a receiver -- so the two cases share one
layout rather than needing separate ones.

A variadic callee ABSORBS its trailing arguments here, in `EnterFrame`
rather than at the call site, so every way into a frame absorbs on the same
terms: a plain call, a method, a constructor and a selected overload.
`conformance/0158` exercises all four.

An EXTERNAL never enters a frame at all -- it has no bytecode to enter -- so
it checks its own argument count, and skipping that check once let a wrong-
arity call through to the foreign boundary [FUN-014].

**Satisfies** — [EXP-011], [EXP-012], [EXP-013], [FUN-005], [FUN-011],
[FUN-014].

**Raises** — `Can only call functions and classes.` for a callee that is
neither; `Expected <n> arguments but got <m>.` for a wrong count; `No
matching signature for function.` where selection finds no candidate --
including a lone candidate whose declared parameter type the argument does
not fit, since [EXP-013] puts even one candidate through selection.

**See also** — `OP_CALL_NAMED`, `OP_RETURN`, `OP_INVOKE`, `OP_OVERLOADS`,
`OP_CLOSURE`.

## OP_CALL_NAMED — Call With Named Arguments

```
Encoding    [ 71 ][ i ][ b ]                  3 bytes
                                              4 under OP_LONG

            i    constant index of the written NAMES -- one entry per argument,
                 empty for a positional one (widens)
            b    the argument count
```

**Stack** — pops n+1, pushes 1, needs n+1.

**Operation** — Calls the value beneath its arguments, arranging them
against the callee's parameter names first. The arrangement mirrors the
interpreter's own -- a slot per parameter, each filled once, all filled --
so a name no parameter has, a parameter named twice and a half-filled call
are one answer.

It is arranged at RUN TIME because the callee may be a variable: `var F :=
Log; F (Message: 'held', Level: 'warn')` keeps the names of whatever `F`
holds.

That is also why naming the absorbing parameter turns gathering off with no
rule of its own [FUN-005]: an arrangement has exactly the declared arity, so
the exact pass takes it first.

A separate opcode rather than a flag on `OP_CALL`, because the names cost a
constant index and the ordinary call is in the hot path. A unit QUALIFIER
needs nothing further -- a qualifier decides which declaration a call
reaches and nothing else, so it takes this instruction unchanged.

**Satisfies** — [EXP-013], [FUN-005], [FUN-016], [MOD-010].

**Raises** — `A built-in has no named parameters.` where the callee is one
-- a built-in's parameters exist only as a count [RT-001]. Otherwise what
`OP_CALL` raises.

**See also** — `OP_CALL`, `OP_INVOKE_NAMED`, `OP_INVOKE_EXT_NAMED`.

## OP_RETURN — Return

```
Encoding    [ 70 ]                            1 byte
```

**Stack** — pops frame, pushes 1, needs 1.
`frame` is not a number: what it takes is whatever its own frame had put
there.

**Operation** — Pops the answer, discards everything else the frame put on
the stack -- the callee beneath its arguments included -- and resumes the
caller.

At the FLOOR frame it stops the machine instead, the value becoming the
run's answer. Same instruction, last of its job: there is no frame to go
back to.

⚠️ An `Exit` inside a CONSTRUCTOR answers the INSTANCE, not its own value --
both other processors do it, so it is the language rather than one of them,
though [CLS-004] does not say so. Emitting the value instead made a
constructor answer nil the moment its early `Exit` was taken, and the
failure surfaced two calls later as a property read on a nil receiver. The
value is still evaluated and dropped, because the interpreter evaluates it
into the `Return` it raises.

`Exit` inside a loop leaves the whole subprogram, not the loop.

**Satisfies** — [STM-009], [CLS-004], [FUN-011].

**See also** — `OP_CALL`, `OP_THIS`, `OP_POP`.

## OP_OVERLOADS — Gather An Overload Set

```
Encoding    [ 62 ][ b ][ i ]                  3 bytes
                                              4 under OP_LONG

            b    how many candidates to gather
            i    constant index of the shared name (widens)
                 ⚠️ The index is the SECOND operand here. OP_BUILTIN carries
                 the same two the other way round.
```

**Stack** — pops n, pushes 1, needs n.

**Operation** — Reads a window of n values from the top of the stack BY
INDEX rather than by popping, so the candidates keep declaration order, and
pushes a set holding them. Order decides a tie within a selection pass, and
popping would reverse it.

A set rather than a slot each, because the declarations share one name and
selection happens at the call, on the argument values.

⚠️ This instruction is the reason an emitter must PARK candidates in slots.
Reading a window from the top only works when a name's declarations are
adjacent in the file. Interleave two overloaded names -- `Tint`, `Where`,
`Tint`, `Where` -- and the window takes one candidate of each, so a
perfectly good call fails with `No matching signature for function.` Five
lines reproduce it, and the corpus cannot catch it: a focused case declares
a name's variants together, where a library organized by topic declares
`TextColor` and `WhereY` long before their `Window`-taking variants. That
one bug was ten of `algol24-library`'s fourteen divergences.

⚠️ It is also why the operand ORDER matters more than it looks. Rendering
"the first operand" as the widenable one would print this instruction
wrongly and put every later offset out, which is what `OpShape` telling `i`
from `b` exists to prevent. The machine itself does not care -- it clears
the flag on the first index READ, wherever that falls -- but a disassembler
has to know.

**Satisfies** — [FUN-013], [EXP-013], [EXP-014]. Two declarations of one
name are an overload set; selection is at the call, on the values; and the
passes run exact, then widening, then absorbing, over the whole inheritance
chain before the next begins.

**See also** — `OP_BUILTIN`, `OP_CALL`, `OP_CALL_NAMED`.

## OP_BUILTIN — Call A Built-In

```
Encoding    [ 63 ][ i ][ b ]                  3 bytes
                                              4 under OP_LONG

            i    constant index of the built-in's NAME (widens)
            b    the argument count
```

**Stack** — pops n, pushes 1, needs n.

**Operation** — Calls one of the always-available built-ins [RT-001],
dispatching on the NAME and the COUNT together -- because six of them are
variadic and one name means different things at different arities.

By name rather than by a number per built-in, and every arm ends in the
host's OWN: `Length` on the machine IS host `Length`, rather than a second
one that would have to agree with it forever. That keeps the interpreter's
guarantee for a third processor.

⚠️ `ParamCount` and `ParamStr` are the exception and cannot be forwarded.
The host's answer is about the PROCESS, which is the driver and not the
program being run -- so the machine keeps its own arguments and the driver
sets them. The interpreter has the identical split.

A DECLARATION of a built-in's name forms one overload set with it: the
declaration answers the argument COUNTS it declares and the built-in keeps
the rest [FUN-005]. The emitter decides which this instruction is reached
for, on the count alone.

**Satisfies** — [RT-001], [RT-015], [FUN-005].

**Raises** — whatever the built-in raises, the message being the host's own.
`A built-in has no named parameters.` where names were written at the call.

**See also** — `OP_CALL`, `OP_OVERLOADS`, `OP_PRINT`.

---

# Collections at run time

## OP_SUBSCRIPT_GET — Read A Subscript

```
Encoding    [ 34 ]                            1 byte
```

**Stack** — pops 2, pushes 1, needs 2.

**Operation** — Replaces a collection and an index above it with the element
the index names. No operand: the index is a VALUE, pushed above the
collection, so this needs no help from the constant table.

A class may declare `Get` and be subscripted through it, which is what makes
the protocol a protocol rather than a privilege of the built-in collections.
Refusing it for every instance broke `conformance/0032`, where an instance
with no such member must raise -- a fault in the program, not a gap in the
machine.

**Satisfies** — [COL-001], [TYP-011].

**Raises** — `Subscript target should be an ordinal.` for a target that is
neither a collection nor an instance declaring the protocol, and `Index <n>
out of range <low>..<high>.` beyond the end.

**See also** — `OP_SUBSCRIPT_SET`, `OP_ITER`, `OP_PROPERTY`, `OP_LIST`.

## OP_SUBSCRIPT_SET — Write A Subscript

```
Encoding    [ 35 ]                            1 byte
```

**Stack** — pops 3, pushes 1, needs 3.
The value stays.

**Operation** — Stores a value at an index and LEAVES it on the stack. The
collection, the index and the value, in that order.

A `List` has no `Remove` [COL-004], so a program shortening one does it by
rebuilding; nothing here is involved in that.

**Satisfies** — [EXP-017], [COL-001].

**Raises** — `Subscript target should be an ordinal.` and `Index <n> out of
range <low>..<high>.`

**See also** — `OP_SUBSCRIPT_GET`, `OP_SET_FIELD`.

## OP_ITER — Materialize A Sequence

```
Encoding    [ 48 ]                            1 byte
```

**Stack** — pops 1, pushes 1, needs 1.

**Operation** — Replaces a collection with a List of the elements `for ...
in` would visit. The HOST's own iteration decides them, which is what makes
a Map yield its keys, a String yield its Chars and a Set yield its members
without this instruction knowing the difference.

It MATERIALIZES the sequence, so a collection mutated during its own loop
would be iterated as it was. A recorded trade: no corpus case does it.

A class declaring `Elements` is iterable through it [TYP-011]. The refusal
here was once unconditional for an instance, which broke the case where an
instance WITHOUT the protocol must raise -- so the question is whether the
class declares it, not whether the value is an instance.

**Satisfies** — [STM-009], [TYP-011], [COL-001].

**Raises** — `Can only iterate a collection or a String.`

**See also** — `OP_IN`, `OP_SUBSCRIPT_GET`, `OP_LIST`.

## OP_PROPERTY — Read A Runtime Property

```
Encoding    [ 36 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the property's name (widens)
```

**Stack** — pops 1, pushes 1, needs 1.

**Operation** — Replaces the top with one of the five properties the runtime
has -- `Length`, `Text`, `Eof`, `IsEmpty` and `Address` -- or with any other
member the one shared member lookup answers.

⚠️ Its handler is BYTE-IDENTICAL to `OP_GET_FIELD`'s. Both read a name from
the constants, pop a value, and push what one shared lookup answers -- so
the two opcodes are one operation, and the difference is what the EMITTER
meant rather than what the machine does. The lookup answers fields,
`ClassName`, methods and these five in that one order, which is why a class
declaring `Length` shadows the runtime's property [CLS-007] and `ClassName`
answers ahead of a field of that name [CLS-008]. Whether both opcodes should
exist is an open question; the reference's job here is to say that they do
and that nothing distinguishes them.

⚠️ Not `OP_DECLARE_PROPERTY`, which declares a property OF A CLASS. These
two were one name for a while, and the collision was silent: an emitter edit
appeared to do nothing and the instruction emitted was valid but wrong.

Each of the five is written as a LITERAL in the lookup's chain, because a
property cannot be reached from a name held in a variable -- the same
constraint `OP_IS` works under.

**Satisfies** — [RT-001], [CLS-007], [CLS-008], [TYP-017].

**Raises** — `Undefined property '<name>'.`

**See also** — `OP_DECLARE_PROPERTY`, `OP_GET_FIELD`, `OP_INVOKE`.

---

# Classes

## OP_CLASS — Push A New Class

```
Encoding    [ 40 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the class's name (widens)
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes a new, empty class. Its fields, methods and parent
are attached by the instructions that follow, each of which leaves the class
on the stack for the next.

Classes are HOISTED, as subprograms and enumerations are -- but a class's
PARENT is attached in source order [CLS-016]. Binding the parent early
reported `Undefined variable` for a name the program had declared perfectly
well.

**Satisfies** — [CLS-016], [DCL-002].

**See also** — `OP_FIELD`, `OP_METHOD`, `OP_INHERIT`, `OP_SINGLETON`.

## OP_FIELD — Declare A Field

```
Encoding    [ 42 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the field's name (widens)
```

**Stack** — pops 0, pushes 0, needs 1.
The class is read and left.

**Operation** — Records a field NAME on the class on top, which it leaves
there.

The name and not a value: an instance begins with every field PRESENT and
nil, so a field with no initializer reads as nil [CLS-006] rather than as an
undefined property. An initializer is separate code, run by the constructor.

⚠️ An instance is CLOSED. Writing an undeclared field raises rather than
creating one, which is what makes this instruction load-bearing rather than
documentation.

A PARENT's field initializers have to run too. An instance already has every
inherited field present, because the instance walks the chain for the names
-- what was missing was the VALUE, so an inherited field read as nil. Parent
first, so a subclass's initializer still wins by running after.

**Satisfies** — [CLS-006].

**See also** — `OP_CLASS`, `OP_GET_FIELD`, `OP_SET_FIELD`, `OP_METHOD`.

## OP_METHOD — Declare A Method

```
Encoding    [ 41 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the method's name (widens)
```

**Stack** — pops 1, pushes 0, needs 2.
The class is read and left.

**Operation** — Pops a callable and records it as a method of the class
beneath it, which it leaves there.

A method table holds a LIST per name, and nothing gathers it: two methods of
one name are an overload set [FUN-013], and emitting this instruction for
each is what builds it, because adding appends.

⚠️ Each selection pass runs the WHOLE inheritance chain before the next
begins [EXP-014]. An exact match on a parent must beat a widened match on
the child, or adding an overload to a subclass silently captures calls the
parent was answering exactly -- so it is pass-major over the chain, never
class-major. And a failed match must FALL THROUGH to the superclass rather
than return, or a class declaring `Take (String)` hides an inherited `Take
(Integer)` entirely.

**Satisfies** — [FUN-013], [EXP-014], [CLS-009].

**See also** — `OP_DECLARE_PROPERTY`, `OP_INVOKE`, `OP_CLASS`, `OP_SUPER`.

## OP_DECLARE_PROPERTY — Declare A Property

```
Encoding    [ 73 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the property's name (widens)
```

**Stack** — pops 1, pushes 0, needs 2.
The class is read and left.

**Operation** — Everything `OP_METHOD` does, plus the note that READING this
name calls it. A property is a method the program never writes parentheses
for.

⚠️ Not `OP_PROPERTY`, which already existed and reads one of the runtime's
five. The two were one name briefly, and the collision was silent in the
worst way: an emitter edit did not apply, and the instruction emitted was a
valid opcode doing the wrong thing.

**Satisfies** — [CLS-007].

**See also** — `OP_PROPERTY`, `OP_METHOD`, `OP_GET_FIELD`.

## OP_INHERIT — Attach A Parent

```
Encoding    [ 43 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the parent's NAME, carried only so a
                 diagnostic can quote it (widens)
```

**Stack** — pops 1, pushes 0, needs 2.
The subclass is read and left.

**Operation** — Pops a class and makes it the parent of the class beneath
it, which it leaves. A pointer rather than `clox`'s copy-down of the
parent's methods, because selection walks the chain anyway -- it has to, for
the pass-major order [EXP-014] to be possible at all.

⚠️ A MODULE's statements get the same two passes the root's do, and for a
long time they got one: the pass that attaches parents was reached only from
the loop over the root file's statements. So no class declared in any unit
ever had its parent attached, and an instance of such a subclass had none of
its inherited fields. The corpus has inheritance cases and module cases but
not their PRODUCT.

**Satisfies** — [CLS-009], [CLS-013], [EXP-014].

**Raises** — `'<name>' is not a class.` for a parent that is not one, and `A
class can't inherit from itself.` [CLS-013].

**See also** — `OP_CLASS`, `OP_SUPER`, `OP_METHOD`.

## OP_SINGLETON — Make An Object

```
Encoding    [ 75 ]                            1 byte
```

**Stack** — pops 1, pushes 1, needs 1.

**Operation** — Replaces the class on top with an OBJECT of it -- a class
having exactly one instance, reached by the name itself [CLS-015]. Built on
first use.

⚠️ A singleton's members must be keyed the way a class's are. Keying them
through the member-table helper instead was two faults in one call: that
helper wants a FOLDED name, so a mixed-case name matched nothing and the
members went under an empty key; and it resolves through the unit's imports,
which is the question to ask about a class being USED and the wrong one
about a class being DECLARED. The symptom was `Undefined variable` on a bare
field read inside a singleton's own method -- which is how this compiler's
own source-line table is written, so it is what stopped the machine running
the compiler.

**Satisfies** — [CLS-015].

**See also** — `OP_CLASS`, `OP_GET_FIELD`, `OP_THIS`.

## OP_THIS — Push The Receiver

```
Encoding    [ 44 ]                            1 byte
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes the receiver of the running frame. It sits one BELOW
the frame's base, where a plain call keeps the callee -- so `this` is a
subscript and needs no slot of its own.

⚠️ A subprogram NESTED inside a method has a frame of its own, so the
receiver is not one below its base and this instruction cannot find it.
There it is read from the cell the method boxed it into, with `OP_GET_CELL`
-- a method whose body declares a nested subprogram boxes `this` as a local
of that name, which is the whole of what makes it reachable.

A bare name inside a method is a VARIABLE first and a member of `this`
second. The interpreter looks the variable up and reaches for `this` only
when that RAISES, so a global of the name wins over a field of it. The
emitter decides it statically instead: not a local, not a capture, not a
visible global, and a member of the class being compiled.

**Satisfies** — [CLS-004], [FUN-012].

**See also** — `OP_GET_CELL`, `OP_GET_FIELD`, `OP_INVOKE`, `OP_SUPER`.

## OP_GET_FIELD — Read A Field

```
Encoding    [ 45 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the field's name (widens)
```

**Stack** — pops 1, pushes 1, needs 1.

**Operation** — Replaces an instance on top with one of its fields. Fields,
`ClassName`, methods and the runtime's five properties are all answered by
one path, in that order -- so a class declaring `Length` shadows the
runtime's property [CLS-007] and `ClassName` answers ahead of a field of
that name [CLS-008].

⚠️ Its handler is byte-identical to `OP_PROPERTY`'s, which that entry says
more about: one shared lookup answers fields, `ClassName`, methods and the
runtime's five properties, in that order.

Of shroom-slots' 28 units, the bare FIELD read unblocked 2 and the bare
METHOD call unblocked 18 -- the library writes `while not AtEnd () do`
inside a class constantly. Both are the same implicit `this`; only the
opcode differs.

**Satisfies** — [CLS-007], [CLS-008].

**Raises** — `Undefined property '<name>'.` for a name nothing answers. NOT
`Only an instance has fields.` -- that is `OP_SET_FIELD`'s, and a READ of a
member on a non-instance is simply an undefined property.

**See also** — `OP_SET_FIELD`, `OP_THIS`, `OP_PROPERTY`, `OP_INVOKE`.

## OP_SET_FIELD — Write A Field

```
Encoding    [ 46 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the field's name (widens)
```

**Stack** — pops 2, pushes 1, needs 2.
The value stays; the instance goes.

**Operation** — Stores a value in an instance's field and LEAVES the value
on the stack. The instance is pushed first and the value above it.

⚠️ That ORDER is why the emitter must decide a bare name's meaning before
emitting the value: the receiver has to be underneath, so the question
cannot be answered after the value is already there.

An instance is closed -- writing an undeclared field raises rather than
creating one.

**Satisfies** — [EXP-017], [CLS-006].

**Raises** — `Only an instance has fields.` and `Undefined property
'<name>'.`

**See also** — `OP_GET_FIELD`, `OP_FIELD`, `OP_SUBSCRIPT_SET`.

## OP_INVOKE — Invoke A Method

```
Encoding    [ 39 ][ i ][ b ]                  3 bytes
                                              4 under OP_LONG

            i    constant index of the method's NAME (widens)
            b    the argument count
```

**Stack** — pops n+1, pushes 1, needs n+1.

**Operation** — Calls a method on the value beneath its arguments,
dispatching on the NAME and the COUNT together -- because one name means
different things at different arities: `Append` with one argument is a
Buffer's, with none a TextFile's.

A member call is an EXPRESSION, even when it reads like a procedure.
Treating `Sort`, `Clear` and `Remove` as void and pushing nil was right for
most and wrong for the ones with something to say -- `Remove` answers the
value removed from a Map and a Boolean from a Set [COL-011].

⚠️ A method's wrong argument count reports a SELECTION failure where a
subprogram's and a constructor's report the counts. All five reports in
`conformance/0049` are compared, so the split is not a style choice.

⚠️ A FIELD of the name holding a callable is called where no method of the
name exists -- `X.F := Up; X.F ('ab')`. Where BOTH are declared the METHOD
wins, which is the compiled back end's answer and not the interpreter's:
that case is a three-way split left standing rather than settled here.

⚠️ `<Class> has no method <name>.` was this machine's own invention and is
gone. Both other processors answer `Undefined property` in every shape -- an
undeclared name, one missing up the chain, one on a singleton -- nothing in
the corpus reached it, and a VM test had pinned the wrong wording.

**Satisfies** — [EXP-013], [EXP-014], [FUN-013], [COL-011], [CLS-009].

**Raises** — `Undefined property '<name>'.` for a name nothing in the chain
declares -- and nothing a FIELD of the name holds either, since a field
holding a callable is called [FUN-011]; `No matching signature for
function.` where the name is declared and selection finds no candidate,
which is also what a single method called at the wrong count gives, where a
subprogram and a constructor report the counts instead [0049]; `Can only
call functions and classes.` where the field holds something that is not
callable.

**See also** — `OP_INVOKE_NAMED`, `OP_INVOKE_EXT`, `OP_CALL`, `OP_METHOD`.

## OP_INVOKE_NAMED — Invoke A Method With Named Arguments

```
Encoding    [ 72 ][ i ][ b ]                  3 bytes
                                              4 under OP_LONG

            i    ONE constant: the member's name, then the argument names
                 (widens)
            b    the argument count
```

**Stack** — pops n+1, pushes 1, needs n+1.

**Operation** — Invokes a member whose arguments were written with names,
arranging them against the method's parameter names first.

⚠️ One constant carries BOTH -- element 0 is the member's name and the rest
are the argument names. Two constant indices would break the invariant that
at most one operand per opcode is widenable, which is what makes the
`OP_LONG` prefix sound.

**Satisfies** — [EXP-013], [FUN-016].

**Raises** — what `OP_INVOKE` raises, plus `A built-in has no named
parameters.` where the member resolves to one.

**See also** — `OP_INVOKE`, `OP_CALL_NAMED`, `OP_INVOKE_EXT_NAMED`.

## OP_SUPER — Push A Super Member

```
Encoding    [ 74 ][ i ][ s ]                  4 bytes
                                              5 under OP_LONG

            i    constant index of the member's name (widens)
            s    the parent class's global slot, as a short
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes `super.Member` -- the member bound to `this`, looked
up starting at the parent of the class the code was WRITTEN in.

The parent is resolved from the operand and not from the receiver, because a
method of C reached on an instance of D still means C's parent [CLS-012].

The whole of it is a VALUE [FUN-011], so the call form needs nothing of its
own: the general-expression path emits this and then `OP_CALL`.

The slot is unconditionally a short, as `OP_INVOKE_EXT`'s is, because the
instruction already spends its one widenable operand on the name.

**Satisfies** — [CLS-012], [FUN-011].

**See also** — `OP_INVOKE`, `OP_THIS`, `OP_INHERIT`, `OP_CALL`.

---

# Extensions

## OP_EXTEND — Bind A Member Or An Extension

```
Encoding    [ 67 ][ i ][ s ]                  4 bytes
                                              5 under OP_LONG

            i    constant index of the member's NAME (widens)
            s    the extension's global slot, as a short
```

**Stack** — pops 1, pushes 1, needs 1.

**Operation** — Reads a member, or binds a visible EXTENSION where there is
no member. Step two of [EXP-022] without a call after it, which is a value
[FUN-011]: `S.Trim` without parentheses is the subprogram with its receiver
already attached.

The receiver is HELD in the bound value rather than re-evaluated, because it
is evaluated ONCE whichever step answers -- `conformance/0190` counts the
calls to prove it. Unpacking at the call and not here is forced: only the
call knows how many arguments were written.

⚠️ A bound extension keeps its receiver INSIDE the value, where
`OP_INVOKE_EXT` has it in the callee's slot. So the receiver must be PASSED
to the prepend rather than read off the stack; taking it from the stack read
the bound value itself as the receiver, and the extension then asked a
subprogram for its `Length`.

**Satisfies** — [EXP-022], [FUN-011], [FUN-015].

**Raises** — `Undefined variable '<name>'.` where the extension's slot was
never defined, naming the global rather than the member.

**See also** — `OP_INVOKE_EXT`, `OP_CALL`, `OP_PROPERTY`.

## OP_INVOKE_EXT — Invoke A Member, Or An Extension

```
Encoding    [ 68 ][ i ][ b ][ s ]             5 bytes
                                              6 under OP_LONG

            i    constant index of the member's name (widens)
            b    how many arguments were written
            s    the extension's global slot, as a short
```

**Stack** — pops n+1, pushes 1, needs n+1.

**Operation** — Asks the receiver's VALUE whether it has a member of the
name. Where it does, that member is invoked. Where it does not, the
extension in the given global slot is called with the receiver PREPENDED as
its first argument, after which it is an ordinary call.

Both halves in one instruction, because nothing at the call site can decide
it earlier: a member wins [EXP-022], and only the running receiver can say
whether there is one. The type system is gradual, so `X.Size ()` may be a
method on one value and an extension on the next -- the Resolver's note says
COULD, not does.

This entry is why the operand kinds are worth a table of their own. It
carries three operands of three different widths, and it is the instruction
that proves the one-widenable-operand invariant holds: the name's index
widens under the prefix, the argument count never does, and the slot is a
short because an extension may live anywhere among a program's globals and
one byte reaches only the first 256.

A host object cannot be ASKED whether it responds, so it is asked by name:
the machine checks the same list `OP_INVOKE` dispatches against, so the two
cannot drift. A String answers only to `Length`, a number only to
`ToString`, and a Char to NOTHING -- which is what lets an extension take
one.

**Satisfies** — [EXP-022], [FUN-015], [FUN-016]. A member always wins; both
spellings of an extension call are one call, the receiver counting as the
argument it is.

**Raises** — `Undefined variable '<name>'.` where the extension's slot was
never defined, naming the global rather than the member. Otherwise
everything a call can raise, the extension path being an ordinary call from
the prepend onwards.

**See also** — `OP_INVOKE`, `OP_INVOKE_EXT_NAMED`, `OP_EXTEND`, `OP_CALL`.

## OP_INVOKE_EXT_NAMED — Invoke A Member Or Extension With Named Arguments

```
Encoding    [ 77 ][ i ][ b ][ s ]             5 bytes
                                              6 under OP_LONG

            i    ONE constant: the member's name, then the argument names
                 (widens)
            b    how many arguments were written
            s    the extension's global slot, as a short
```

**Stack** — pops n+1, pushes 1, needs n+1.

**Operation** — The two halves of `OP_INVOKE_EXT` and the two halves of
`OP_INVOKE_NAMED` at once: the receiver's value decides whether there is a
member [EXP-022], and the names are arranged against whichever answers.

⚠️ The RECEIVER stays positional whichever spelling the call used [FUN-016],
so the written names shift up one when it is prepended. Both spellings of an
extension call are one call, and the receiver counts as the argument it is.

**Satisfies** — [EXP-022], [FUN-015], [FUN-016].

**Raises** — what `OP_INVOKE_EXT` raises, plus what an arrangement raises
for a name no parameter has.

**See also** — `OP_INVOKE_EXT`, `OP_INVOKE_NAMED`, `OP_CALL_NAMED`.

---

# Enumerations

## OP_ENUM — Push A New Enumeration

```
Encoding    [ 49 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the enumeration's name (widens)
```

**Stack** — pops 0, pushes 1, needs 0.

**Operation** — Pushes a new, empty enumeration. Its members are added by
the instructions that follow, each of which leaves it on the stack.

Enumerations are hoisted, as classes and subprograms are [DCL-002].

**Satisfies** — [ENU-001], [DCL-002].

**See also** — `OP_ENUM_MEMBER`, `OP_IS`, `OP_CLASS`.

## OP_ENUM_MEMBER — Add An Enumeration Member

```
Encoding    [ 50 ][ i ]                       2 bytes
                                              3 under OP_LONG

            i    constant index of the member's name (widens)
```

**Stack** — pops 0, pushes 1, needs 1.
The enumeration is read and left; the member goes above it.

**Operation** — Adds the next member to the enumeration on top and PUSHES
it, leaving the enumeration beneath. Pushed so the emitter can bind the bare
name immediately: a member binds both bare and qualified, and both reach the
one interned object [ENU-002].

⚠️ An enumeration inside a SUBPROGRAM is locals, and the slots must be
reserved first. This instruction reads the enumeration on TOP, which works
for globals because defining one pops it and leaves the enumeration there --
but a local IS its stack slot, so the members cannot stay on top. Each is
reserved nil, the enumeration goes above them, and every member is written
back into its own slot and popped. The enumeration is boxed last, because
this instruction wanted it bare.

A member's ORDINAL is the machine's answer and not the host's -- the same
split truthiness has. The host holds one of the machine's objects and
reports no ordinal where the other two processors answer the position
[ENU-010]. No corpus case asks, which is why it survived 260 of them.

A member renders as its own NAME [ENU-007], and it renders through a
`ToString` the host invokes -- without one, a member inside a collection
printed as an instance of the machine's own class while `Str` of it was
right. Any machine object a program can see needs one.

**Satisfies** — [ENU-001], [ENU-002], [ENU-007], [ENU-009], [ENU-010].

**Raises** — `Undefined enum member '<name>'.` when a member is later read
by a name the enumeration has not got.

**See also** — `OP_ENUM`, `OP_IS`, `OP_NOT`.

---

# Output

## OP_PRINT — Write A Line

```
Encoding    [ 29 ]                            1 byte
```

**Stack** — pops 1, pushes 0, needs 1.

**Operation** — Pops a value and writes it, as `WriteLn` does. One
instruction where the general built-in path is three, which is why it exists
at all.

⚠️ A FAST PATH is where a wrong answer hides, and this one's cost two bugs.
The emitter reaches for it above the built-in branch, so it escaped both the
visible-declaration question -- a program importing a unit that REDIRECTS
`WriteLn` had the redirect silently ignored and its text went to stdout --
and the named-argument question, so `WriteLn (V: 'abc')` printed `abc`
instead of raising. Both guards sit on it now. Add a check to the general
path and ask what skips it.

A guest object renders through a `ToString` the host invokes, and without
one the host says `<Class> instance`.

**Satisfies** — [RT-015].

**See also** — `OP_BUILTIN`, `OP_POP`.

---

# Encoding

## OP_LONG — Widen The Next Instruction's Index

```
Encoding    [ 69 ]                            1 byte

            No operands.  Its operand is the whole instruction that
            follows it, opcode included.
```

**Stack** — pops 0, pushes 0, needs 0.

**Operation** — Sets a flag, then runs the next instruction. That
instruction's one widenable operand -- its constant index (`i`) or its local
slot (`l`) -- is read as a short instead of a byte, and the flag is cleared
BY THAT READ.

A prefix rather than a long form per opcode, which is what the JVM's `wide`
does and for the same reason: most opcodes here carry an index into the
constants, so a long form each would be that many numbers, names, handlers
and chances to forget one. A prefix is one of each, and it covers an opcode
added later for free. Measured free on the narrow path: Fib (27) interleaved
against the prior commit reads 0.98-0.99 s both ways.

⚠️ No count is quoted above, and the first draft of this entry quoted one --
it said nineteen, copied from this opcode's own doc comment, where the
figure had grown to twenty-four without anything noticing. That is the
failure this file's header warns about, reproduced inside an hour of warning
about it.

Only the widenable operand widens. A count beside it stays a byte and a
short beside it is already two, so `OP_INVOKE_EXT` under the prefix reads a
short, a byte and a short.

⚠️ The flag is cleared on the READ, not at the end of the instruction. That
is what lets the machine stay ignorant of where the index sits among the
operands -- `OP_BUILTIN` carries it first and `OP_OVERLOADS` carries it
second, and both work. Clearing it at the end instead leaves a second
prefixed instruction reading a byte where a short was written, and every
offset after that drifts. There is a test for exactly that pair.

⚠️ It is `OP_LONG` and not `OP_WIDE` because **`OP_WIDEN` already exists**
and widens a VALUE to a declared type. Two opcodes a letter apart meaning
unrelated things is a misreading waiting to happen, and it has happened here
once already -- inside ten minutes, grepping a disassembly for one and
matching the other. <!-- reference.sh: not-an-opcode OP_WIDE -->

**Satisfies** — nothing directly. It is an encoding, not a language feature.

**See also** — `OP_WIDEN`, `OP_CONSTANT`, `OP_GET_LOCAL`, `OP_INVOKE_EXT`.
