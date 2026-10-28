# Plan: v0.1.6

**Status:** decided, not started. Four items, in the order they will land.
Written 2026-10-28.

Three of the four come from `algol24-library` as a user of the language, with
proposals carrying their own measurements: `PROPOSAL-BITWISE-OPERATORS.md`,
`PROPOSAL-NUMBER-FORMATTING.md`, and `SKETCH-STREAMING.md` group 5. The fourth
is two stale sentences in the specification that nothing checks.

---

## The policy this release should state

The language was described as feature-complete from v0.1.0 and *done*. That
sentence has now been rewritten twice and is wearing out. What has actually
happened, twice, is this:

> **The language is stable, not closed.** It changes only on measured demand
> from a project using it, and the measurement goes in the proposal.

Extension functions arrived that way in 0.1.5 and these three arrive that way
now. Saying it once in `CLAUDE.md` and the README stops it going stale every
release.

---

## 1. Two stale sentences in the specification

Neither is caught by any harness, and both are about [EXP-001].

**[EXP-001]'s table omits `div` and `mod` entirely.** They are operators —
[EXP-021] made `mod` one — and they appear nowhere in the precedence table.
Measured where they actually bind:

```console
$ algc prec.a24
5      -- 1 + 8 div 2, so div is tighter than +
8      -- 8 div 2 * 2, so they share a level, left to right
4      -- 1 + 7 mod 4
2      -- 2 * 7 mod 4
```

So level 3 reads `*` · `/` · `div` · `mod`, left-associative, and has done
since `mod` became an operator.

**[EXP-020] says "a fixed table of seven levels"** over a table with nine
rows. The argument it supports — that the overloadable operator list is closed
because there is nowhere to put a new precedence — is about to be superseded by
item 4, which rewrites the paragraph. For now the count is simply wrong.

Case `0045-precedence.a24` gains the two `div`/`mod` lines, so the table's new
claim is pinned by the corpus rather than by this document.

---

## 2. `Buffer.PutDouble`, in the core — **done**

`Buffer` has `PutInt`/`GetInt` and nothing for a Double, so a record holding a
price has no encoding in pure Algol-24. The library needs it for `RecordFile`.

⚠️ **The library had decided to do this itself and has changed its mind.**
`SKETCH-STREAMING.md` says "this library should fill that itself rather than ask
the language … not worth a proposal for something that has no wrong answer",
while conceding that "`Buffer.PutDouble` next to `PutInt` would be the more
natural home". It is going in the core, which means **the library must not also
write one**: two encoders of the same bytes would have to agree forever, and
that is the objection the number-formatting proposal makes about two renderers.

What lands:

| | |
| --- | --- |
| `PutDouble (At, X)` | eight bytes, IEEE 754, little-endian — `PutInt`'s byte order, measured |
| `GetDouble (At)` | the same eight bytes back |
| `PutWord (At, N)` | four bytes **unsigned**, 0 … 4294967295 |
| `GetWord (At)` | the same four bytes read unsigned, retiring the fixup below |

`GetWord` is not in any proposal; it answers the bitwise proposal's open
question 5. `if X < 0 then X := X + 4294967296` — undoing `GetInt`'s sign — is
duplicated in `crt` and `graph` today, and an unsigned reader retires both sites
independently of the operators.

⚠️ **`PutWord` is the one addition beyond what was asked for**, and the reason
is the asymmetry it avoids: with a reader and no writer, writing an unsigned
word means `PutInt (At, X - 4294967296)` — the inverse of the fixup being
retired. The specification already records fixing exactly this shape of gap
once, when `mod` became an operator so that a class defining `div` could define
its partner [EXP-020].

Unaligned offsets are accepted, as `PutInt`'s are.

**What landed.** [RT-022] carries the two new rows and says four things the
rule had not had to say before: the byte order is written down rather than
inherited, so a record crosses machines; the offset message names `Length - 8`
for a Double; `PutDouble` widens an Integer [VAL-001]; and eight bytes is IEEE
754 binary64, which is the one place this specification names a representation
— because a record format is a promise to something outside the program.
[RT-021]'s matrix gains a row, and `spec/spec.sh` now checks 25 pairs against
the interpreter rather than 21.

⚠️ **The member probe had a hazard, and the harness found it.** `spec/members.a24`
asks each kind for each name inside a `case`, and a `case` with no matching arm
falls through *without raising* — so a name added to the Buffer block alone read
as a member `TextFile` has. spec.sh reported all four as omitted from the matrix
for TextFile. The arm that raises is what makes an absence an answer rather than
a silence, and the hazard is now written down in the probe for the next name.

Covered by `conformance/0175-resource-members.a24` and
`conformance/0176-a-buffers-bytes.a24` under both processors, which is how
`PutInt` is covered too — there is no unit test for any Buffer member, because
`ObjBuffer` delegates every one of them to the host and the corpus is what
proves the two processors agree. A record of the shape `RecordFile` wants —
an Integer id, a Double price and a packed colour word — round-trips
byte-identically through both, `-0.0`, `NaN`, `Infinity`, `1.0E300` and
`1.0E-300` included.

---

## 3. `Str (X, Decimals)` and `Str (X, Width, Decimals)`

Accepted as proposed. The proposal's argument is that a library cannot do this
correctly and measured why: text surgery on `Str`'s output gets a wrong digit
for `8.835` and answers `1.23` for `0.00001234`, while `Round (X * 100) / 100`
answers `2.68` for `2.675` because the product is `267.50000000000006`.

**The five open questions, answered:**

1. **Overload `Str`** rather than adding a name. One renderer, as [RT-006]
   already promises.
2. **`NaN` and `Infinity` render as the word**, padded to `Width`. Not refused,
   and never as digits.
3. **`Decimals` of zero gives no trailing point.** `Str (2.5, 0)` is `2`.
4. **Take both overloads.** The three-argument form is nearly free once
   precision exists, and a column is the actual use.
5. **Decline `Str (5, 2)` for Integers**, so one arity keeps one meaning.

⚠️ **One implementation note is what makes it safe.** Both processors must route
through a **single new C primitive** over `snprintf ("%.*f")`. Correct rounding
from the binary value and ties-to-even then come from the same place `Round`
gets them, and the two renderers cannot drift. A second implementation in
Algol-24 would be the two-renderer problem the proposal objects to, arrived at
from the other direction.

Arity settles all three forms statically, so no call site warns [ERR-010].

---

## 4. Bitwise operators

Six, on Integer operands, over the unbounded Integer the language already has:
**`&`** and, **`|`** or, **`^`** exclusive or, **`~`** complement, **`<<`**
shift left, **`>>`** shift right.

### Semantics: infinite two's complement

Every Integer is two's complement extended infinitely to the left — a
non-negative value has infinitely many leading zeros, a negative one infinitely
many leading ones. Every operation is then total and closed with no width named
anywhere: `~0` is `-1`, `-1 & 5` is `5`, `1 << 70` grows as [EXP-007] already
promises. This is the part only the language can get right, and it is why the
library's foreign `alg_xor` — which truncates to 32 bits and sign-extends back —
cannot generalize.

`>>` is an **arithmetic** shift and is *not* `div`: `-7 >> 1` is `-4` (floor)
while `-7 div 2` is `-3` (truncate toward zero). A negative shift count is
refused rather than read as a shift the other way.

A bitwise operator on a Double is refused, not reinterpreted.

### Symbols, not words

Decided. None of `& | ^ ~ << >>` is lexed today, so **no existing program can
change meaning** — a lexer addition rather than a reinterpretation. Word
operators would be new keywords, and [LEX-011]'s context-sensitive trick does
not extend to an infix position.

⚠️ **The half-Pascal trap is the real reason.** Turbo Pascal's answer is
`and`/`or`/`xor`/`not` bitwise-on-integers *plus* `shl`/`shr`. This language
cannot take the first half — see below — so adopting `shl`/`shr` alone would
look like Pascal and behave unlike it, which is the same "plausible wrong
number" the library is complaining about. A clean break does not pretend.

### Precedence

[EXP-001] gains three levels and two entries. Final table:

| | Operators |
| --- | --- |
| 1 | `f(…)` call · `a[i]` subscript · `a.b` property |
| 2 | `-` unary · `~` · `not` · `as` |
| 3 | `*` · `/` · `div` · `mod` · `<<` · `>>` |
| 4 | `+` · `-` |
| 5 | `&` |
| 6 | `^` |
| 7 | `\|` |
| 8 | `<` · `<=` · `>` · `>=` · `in` · `is` |
| 9 | `=` · `<>` |
| 10 | `and` |
| 11 | `or` |
| 12 | `:=` |

The bitwise three sit **between arithmetic and comparison**, so
`Flags & Mask = 0` means `(Flags & Mask) = 0`. C binds `&` looser than `==`,
which is regarded as a mistake and carries a warning in every modern C; this
avoids inheriting it. `&` over `^` over `|` keeps the uncontroversial part of
C's order.

⚠️ **Shifts sit with the multiplicatives, which is a deliberate departure** from
both C and Python, where they bind below `+` and `-`. The reason is that
`1 << N - 1` is a mask in practice, and tight shifts give `(1 << N) - 1` rather
than `1 << (N - 1)`. It wants saying in the rule rather than leaving to
discovery.

### `and`, `or` and `not` are not reused, and the evidence says they could be

The question was whether reusing them would break existing code. It would not,
and they are still not being reused.

A probe compiler was built in a worktree, reporting whenever an operand of
`and`, `or` or `not` is an Integer at run time, and every suite was run under
it:

| | tests | Integer operands seen |
| --- | --- | --- |
| `compiler/` | 243 | **0** |
| `algol24-library` | 807 | **0** |
| `shroom-slots` | 724 | **0** |

The probe is validated rather than assumed: over the conformance corpus it fires
on exactly `0048-logical-operators` — [EXP-010]'s own case, which uses Integer
operands deliberately — and `0118-as-binds-tightly`. A static scan agrees: of
2,133 operator uses of `and`/`or` across the three trees, every one whose
operand looks numeric is a comparison *containing* something numeric.

⚠️ **The reason not to reuse them is short-circuiting, not breakage.** `and` and
`or` short-circuit and yield an operand [EXP-010]; bitwise operators must
evaluate both sides. Under gradual typing the compiler cannot know which a given
`A and B` is, so it would have to evaluate the left, inspect its *value's* type,
and only then decide whether to evaluate the right. The same expression would
short-circuit on one call and not the next, depending on data — so a side effect
would fire or not for reasons no diagnostic could sit on. A changed result is
bad; that is worse.

⚠️ **And `not` is refused for a reason the language already gives.** [EXP-020]
refuses `operator not` for a class because "`not` tests truthiness, which
[VAL-008] defines for every value, so a type overloading it lies about a
language-wide property". Reusing `not` in the core would do what the language
forbids its users.

### The third `[WARN]`

Since nothing in the ecosystem relies on Integer `and`/`or`, the trap the
library records as `DEFECTS.md` H-3 can become a diagnostic at no cost:

```
[WARN] file:N: an operand of 'and' is an Integer; '&' is the bitwise operator.
```

Non-blocking, breaks nothing, and catches the Pascal reader who writes `6 and 3`
expecting `2`. [ERR-010] states it as the third warning and `spec/spec.sh`
already compares every `[WARN]` the fixture raises against the lines the rule
quotes, in order — so the harness takes it without a change. Case
`0048-logical-operators` gains the quoted warning.

### Operator overloading

[EXP-020]'s list is closed "because a new operator would need a precedence and
an associativity, and [EXP-001] is a fixed table … with nowhere to put one".
Item 4 puts six somewhere, so the objection dissolves and the same work carries
both: a class may define `&`, `|`, `^`, `<<`, `>>` and unary `~` for its own
instances, on the terms every other operator already has — the left operand
decides, and arity tells unary from binary.

`~` is the interesting one: it is unary, so `operator ~ ()` with no parameter,
exactly as `operator - ()` is negation. Unlike `not`, `~` claims nothing
language-wide — there is no `[VAL-008]` for bit patterns — so the argument that
keeps `not` off the list does not reach it.

---

## Order, and the gate for each

Each lands on its own and leaves all five harnesses green.

| | What | Why here |
| --- | --- | --- |
| 1 | The two stale sentences, and `0045` pinning `div`/`mod` | An afternoon, no code, and it corrects what item 4 is about to build on |
| 2 | `PutDouble` / `GetDouble` / `GetWord` | Mechanical: `PutInt` is the precedent through every pass |
| 3 | `Str` overloads | One C primitive, two arities, the proposal's measured rounding table as the cases |
| 4 | Bitwise operators | Touches [EXP-001], which nothing has touched in five releases |

⚠️ **Item 4 is the one with a reseed hazard.** New tokens mean
`compiler/TokenType.a24`, `Scanner.a24`'s `Keywords`, and the editor grammar
that `spec/spec.sh` checks against it. A change that makes the compiler refuse
its own sources bricks the bootstrap, so build stage 2 and emit again with it
before copying anything into `bootstrap/`.

## What this release does not do

- **Rotation, population count, bit scan.** Expressible once the six exist, and
  nothing has asked.
- **Bitwise operations on a Double**, or any reinterpretation of its bits.
- **A format-string function.** `Format ('%08.3f', X)` is a different proposal
  with a mini-language in it, and item 3 is not a step toward it.
- **A fixed-width integer type.** The unbounded Integer is the model; item 4 is
  written to fit it rather than around it.
- **Removing `graph`'s `alg_xor`.** That is the library's call once the operator
  is measured in the pixel loop.
