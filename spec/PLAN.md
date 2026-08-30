# Plan: the road to v1

`spec/ALGOL-24.md` is written and every one of its rules is claimed by a case: a
program in `conformance/`, a refusal in `refusals/`, or a reproduction in
`defects/`. The conformance pass decided what the language *should* do. This
plan was the work of making the interpreter do it.

## ✅ Generation 1 is complete

**`defects/` is empty.** Thirty-five defects were found and all thirty-five are
fixed. The interpreter implements every rule the specification states.

The work also changed the specification in three places where the *rule* turned
out to be wrong rather than the code — [SRC-005] admitting all of Unicode rather
than letters, [LEX-025] on `Char(0)`, and DEF-13's recorded blocker naming the
wrong data structure. A rule is authoritative but not infallible; a
contradiction between a rule and the code is a question, not a verdict.

⚠️ **Three things were added to the language on the way**, each because a rule
could not be met without them: `Halt` [RT-018], so a driver can choose an exit
status without raising; Annex G.3's mangling, so any Unicode identifier can be
spelled in C; and an integer range check with a build switch, since [LEX-018]
costs per operation.

**Next is Generation 2**: Annex C's divergences become defects and are worked
through the same way, until conformance passes under *both* processors.

## ✅ Generation 2 is complete

**`./conform.sh` reports no gap.** All thirty-six Annex C entries are withdrawn,
so every case the interpreter gets right the compiled back end gets right too,
and the compiled `--test` report is identical to the interpreted one line for
line — 239 lines and 1,416 escape sequences over the whole suite.

Four of those entries were opened *during* the generation and closed with it
(C-35 to C-38), three of them found by writing a conformance case for something
only the interpreter had ever run.

⚠️ **A dozen entries were wrong about what was wrong**, and several named a
mistake in the fix they themselves proposed — C-20 wanted the member map keyed
by owner when the symbols were never the problem; C-24 wanted the check at the
call site when the callee is one place instead of many; C-2 read as a missing
mechanism when it was one missing case. The entries are kept for that, not for
the count.

⚠️ **Two were the interpreter's fault, not the compiler's** (C-4, C-37), which
the annex's own classification does not admit. A divergence says the two
processors disagree; it does not say which one is right.

⚠️ **Nothing was closed by narrowing the language.** Every entry was closed by
making the compiler do what the interpreter does, except where the interpreter
was the one in error — and no rule was weakened to make a gap go away.

## 0. The road to v1

| | | Ends when |
| --- | --- | --- |
| **Gen 0** | The specification is written and reviewed. | The spec is read carefully and signed off. Merge to `main`, tag **Gen 0**. |
| **Gen 1** | The spec is authoritative and conformance is enforcement. Work through the defects until there are none. | `defects/` is empty. Tag **Gen 1**. |
| **Gen 2** | Turn on the compiler. Annex C's divergences become defects and are worked through the same way. | Conformance passes under **both** processors and no defect remains. Tag **Gen 2**. |
| **Gen 3** | The numbers: what they are, how they are written, what may be asked of them. | The bar below. Tag **Gen 3**. |
| **v1** | New language features and a runtime library, prioritized, each staying within conformance. | Release. |

⚠️ **From Generation 3 onward a generation is complete only when every case in
`conformance/` and `refusals/` passes under BOTH processors** — the interpreter
and the compiled back end — with `./test.sh`, `./spec/spec.sh` and
`./fixedpoint.sh` green beside them. A compiler gap is a **failure**, not a
report.

⚠️ **The bar is enforced by `conform.sh` rather than stated here**, and that is
the point. Agreement between the two processors took a whole generation to
reach; a gate that only reports is a gate that lets it decay one accepted gap at
a time. `--lenient` still shows work in progress and is not a way to finish
anything.

⚠️ **This is what closes the door Generations 1 and 2 held open.** Through both
of them a gap was deliberately not a failure, because the compiler was expected
to trail while the interpreter was brought to the specification, and `--strict`
was the opt-in. The default is now the other way round.

⚠️ **The Gen 2 gate is met**, and `conform.sh` now enforces it by default. The
relaxation described below is over.

⚠️ **Sections 1 to 7 below describe Generation 1's work** and are kept as its
record. The plan for the generation now in front of us is *Plan: Generation 3 —
the numbers*, which follows the rest of this section; nothing in §2's dependency
ordering or §3's sequence applies to it.

---

⚠️ **What changed at the Gen 1 → Gen 2 boundary is the corpus doctrine itself.**
Today a case is classified by one question — *is the interpreter right?* — and
compiler gaps are reported but do not fail the run
(`conformance/README.md`). At Gen 2 that relaxation ends: failing on a compiler
gap becomes the gate, and each Annex C entry earns a defect of its own.
The classification question does not change, because by then the interpreter
matches the specification and "is the interpreter right?" is answered yes
everywhere; what changes is that the compiler is no longer excused.

⚠️ **Four Annex C entries will not survive to Gen 2**, and should not be written
up as compiler defects when the time comes:

- **C-1** closes with DEF-24 — giving the root a module identity.
- **C-12** closes with DEF-17 — the language stops allowing what the compiler
  already refused.
- **C-6** may close with **H-6** rather than with a repair: giving a class a
  `property` member makes bare `B.Length` on a *method* an error, so the
  construct that segfaults stops being writable. That is a later generation, not
  Gen 2 work, so it may still need writing up as a compiler defect first.
- **C-4** and **C-9** *reverse*: [SRC-011] and [RT-017] make the compiler right
  and the interpreter the one to change, so they are Gen 1 work (DEF-02,
  DEF-26) rather than Gen 2 work.

⚠️ **Three of those four held; C-6 did not.** C-1 closed with DEF-24, C-12 with
DEF-17, and C-4 and C-9 reversed as predicted. C-6 was expected to close by
H-6 removing the construct that crashed, and instead closed with an ordinary
repair — the crash was a missing case in `as_text`, not a reason to withdraw the
spelling. A prediction about *how* an entry will close is worth less than the
entry itself.

⚠️ **Nothing after Gen 0 may change a rule without a reason recorded in the
specification.** The point of signing off is that the document stops being a
description of the implementation and starts being the thing the implementation
is measured against — so a defect is closed by changing the code, and a rule is
changed only by deciding to change the language.

# Plan: Generation 3 — the numbers

One subject. What a number **is**, how it is **written**, and what may be
**asked** of it. Every rule this generation touches lives in chapters 5, 7, 9
and 16, and nothing it does reaches chapter 14 — which is why H-3 is not in it.

⚠️ **The guiding question throughout is whether a reader can say what a thing is
without looking it up.** "An `Integer` is a 32-bit two's-complement integer, and
arithmetic that leaves that range raises" fails that test. "An `Integer` is an
integer" passes it. Most of what follows is downstream of preferring the second
sentence.

## The decisions, and why

**`Integer` is unbounded.** It grows rather than overflowing. This deletes a
category of error instead of diagnosing it, and it makes the type describable in
four words.

⚠️ **Cheaper than it sounds.** The slow path begins past 2⁶³, and almost no
program reaches it — `algc` cannot, since `Scanner.a24` compares digit strings
precisely because it may not do the arithmetic. The cost is one branch per
operation, which [LEX-018]'s range check already spends, plus an allocation only
where a program genuinely needs one.

**`Real` is an alias for `Double`.** Turbo Pascal's 6-byte software float was a
pre-8087 artefact with no C type to map onto. A type whose only distinction is a
1985 storage format is the opposite of self-explanatory. Delphi reached the same
conclusion.

| Algol-24 | C | Notes |
| --- | --- | --- |
| `Integer` | `int64_t`, widening past that | unbounded |
| `Single` | `float` | |
| `Double` | `double` | |
| `Real` | `double` | an alias for `Double`, not a fourth thing |

**`Byte`, `Word` and `Short` are subranges, not representations.**

```
type Byte  = 0 .. 255;
type Word  = 0 .. 65535;
type Short = -32768 .. 32767;
```

⚠️ **One feature instead of five special cases**, and it is Pascal-native.
`type Digit = 0 .. 9` comes free with it, and the range check lands exactly where
[VAR-017]'s six assignment contexts already are.

**There is no signed/unsigned family.** Unsigned types exist to buy one more bit
inside a fixed width, and to say "this cannot be negative". Unbounded `Integer`
removes the first reason entirely, and `0 ..` states the second directly instead
of encoding it in a name the reader has to know.

⚠️ It also avoids C#'s worst corner here: `long + ulong` is a compile error
there, because no type holds both. Every mixture has an answer when `Integer`
holds everything.

**`Char` stays out of the numeric types.** Turbo Pascal made `Char` ordinal and
compatible with `Byte` because both were eight bits. Ours is a Unicode code
point, so the conflation is not available — and the language already commits to
a Char not being a number [LEX-026]. `Ord` and `Char` remain the explicit bridge.

**Promote on mixing; range-check on assignment.** Arithmetic promotes to at
least `Integer`, so `B + 1` on a `Byte` is an `Integer`; assigning the result
back into a `Byte` is what checks the range. This is C#'s rule, and it means
[LEX-018] survives — for subranges, at the six assignment contexts, where
`alg_param` already stands.

**Overload selection ignores ranges.** Two subprograms differing only in a
parameter's range claim the **same signature** and are a duplicate, refused by
[FUN-013] as it stands.

⚠️ **This is the argument [FUN-013] already makes about return types**: selection
happens from the arguments, so two subprograms that a call could never tell apart
are a duplicate rather than an overload. A range does not distinguish an overload
for the same reason.

⚠️ **The principle underneath: a program may ask about a value; the language may
not silently dispatch on one.** Value-dependent selection would send `Take (200)`
and `Take (300)` to different subprograms, and would let *adding* a `Byte`
overload steal calls from an `Integer` one that already existed.

⚠️ **Which is why `X is Byte` is a range test, and is not a contradiction.**
`is` is the program asking, explicitly, where it wrote the question.

**`div` is added; `/` is unchanged.** [EXP-004] makes `/` truncate on integers
and [EXP-005] makes it real when a Double is present, so `X / Y` means integer or
real division depending on what reaches it at run time — unreadable when `X` is
`Any`. `div` gives the programmer the option of saying which was meant, and
breaks nothing.

⚠️ **The option rather than the change**, deliberately. Making `/` always real
is more predictable and is a migration through every division in the tree,
`algc`'s own included. [EXP-006]'s existing ⚠️ already records the unease; `div`
answers it without spending the generation on it.

**Numbers answer members, C#'s way and not Java's.** `5.ToString ()` works
because `Integer` is a type with members, not because a box wraps a primitive.

⚠️ **Java's `int`/`Integer` duality is the thing to avoid**, not the model to
follow: `==` comparing boxes, `NullPointerException` from unboxing a null, a
cache that makes `==` work for small numbers and fail for large ones. Two things
with almost the same name behaving differently is the asymmetry Annex H already
rejected once, when it turned down `B.^Length` for computed properties.

⚠️ **The mechanism exists.** Gen 2 built `member_of` for receivers whose members
come from the runtime rather than from a class — collections, `Buffer`,
`TextFile`. Numbers are rows in that table, and read-without-calling comes free.

## Writing them — H-1 and H-2

**H-1: `0x` hexadecimal, `0b` binary, `_` separators. No octal.**

⚠️ **Octal is dropped deliberately.** It is a PDP-11 artefact, and `0755`
silently meaning 493 is a classic bug. C# has no octal literal for this reason.
Three bases where two are used is exactly what this language declines.

⚠️ **`0x`/`0b` rather than Turbo Pascal's `$FF`.** `$` is unclaimed and `$FF`
would sit consistently beside `#10`, which the language already has — but TP has
no binary literal at all, so `$FF` beside `0b1010` mixes two traditions in one
sentence. The choice is for coherence with binary, not for modernity.

**Separators: a separator separates two digits.**

| | |
| --- | --- |
| `1_000_000` | ✓ |
| `1_0_0` | ✓ — silly, harmless, not worth a rule to forbid |
| `_100` | **already an identifier** [SRC-005]; it cannot also be a literal |
| `100_` | refused — nothing to the right to separate |
| `1_.5`, `1._5`, `1e_5` | refused — the neighbour is not a digit |
| `0x_FF` | refused — the prefix is not a digit either |

⚠️ **A comma was considered and is impossible, not merely awkward.**
`F (1,000,000)` is a call with three arguments and `[1,000,000]` is a list of
three elements — both valid Algol-24 today, with a different meaning. No
lookahead resolves it, because both readings are complete.

**H-2: exponent notation.** `1e5`, `1.5e-3`. This closes a real asymmetry rather
than adding a convenience: `Str` prints a large Double as `1.0E300` and the
language cannot read back what it wrote.

## What it deletes

The satisfying half, and a fair measure of whether the design is right:

- **[LEX-033]** — an integer literal outside Integer's range. Vacuous once no
  literal is out of range.
- **`ExceedsInteger`** in `Scanner.a24`, and its ⚠️ about comparing digits as
  text because strings are not ordered.
- **Annex G.4's `-DALG_NO_OVERFLOW_CHECK`** — probably. Its stated reason is
  that [LEX-018] costs per operation; if `Integer` never overflows, the switch is
  disabling a subrange check that is nowhere near a hot path.
- **`Char (N)`'s hand-written 0..10FFFF check**, which becomes a subrange like
  any other.

## Rules that change

| Rule | Change |
| --- | --- |
| [LEX-016] | bases and separators arrive |
| [LEX-018] | Integer stops being 32-bit; the raise survives for subranges |
| [LEX-022] | exponent notation arrives |
| [LEX-033] | **deleted** |
| [TYP-001] | the runtime type table gains `Single`; `Real` named as an alias |
| [TYP-002] | subrange declaration form |
| [VAR-004] | the widening lattice replaces the two pairs |
| [VAR-017] | unchanged in shape; the range check joins the widening already there |
| [VAR-018] | narrowing, restated against subranges |
| [EXP-004] | `div`, and `/` restated |
| [EXP-005] | promotion restated as a lattice |
| [EXP-006] | survives intact |
| [EXP-007] | "32-bit" goes |
| [VAL-009] | equality across the widened set |
| [RT-009] | `Val` answers across the set |
| [RT-010] | `Max` follows the lattice |
| Annex B | numeric members — `ToString` and what else is decided |

## Order

1. **The type set and the lattice**, interpreter first, then the C runtime.
   Nothing else can be checked until `type_name` answers for the new types.
2. **Subranges**, including the check in `alg_param` and the case in `alg_is`.
3. **The scanner** — H-1, H-2, and the deletions, in one pass over number
   scanning rather than three.
4. **`div`**, which is a token, a rule and an operator case.
5. **Members on numbers**, last, because it is additive and gated by nothing.

⚠️ **Unbounded arithmetic must be written once, not twice.** The interpreter's
arithmetic *is* the host's, so the two processors agree by construction — as
long as the bignum lives in `bootstrap/algol.c` and the interpreter reaches it
through the same operators every other Algol-24 program does. Writing a second
implementation in `compiler/*.a24` would reintroduce exactly the class of
divergence Gen 2 spent itself closing.

⚠️ **Every operation that needs a machine integer needs one honest gate** — a
subscript, a `Buffer` offset, `Char (n)`, a hash. "Give me an `int32` or fail"
in one place, not a silent truncation in several.

## Not in this generation, and why

- **H-3, element types checked on insertion.** It is a collections change, not a
  numbers one. ⚠️ And doing it now may be work that H-9 redoes: `List of Integer`
  is a checker-side annotation today, and once collections are a unit written in
  Algol-24 the same constraint on a *user-written* class needs something like
  generics, which the language does not have.
- **H-8, operator overloading**, and with it any notion of `Integer` as a class.
  Arithmetic is the hottest path in the language, `algc` bootstraps on it, and
  overloading is the one item on the list that aesthetics argues *against*.
- **Wrapping arithmetic.** `hash_folded` relies on `uint32_t` wraparound, and
  that is fine while hashing stays native. It becomes a language question only
  if H-9 moves `Map` and `Set` into a unit that must express a mixing step.

## Also due

**Annex H gains an entry for named parameters**, which are intended and are
recorded in no document. They would let an overload be identified at compile
time, giving the programmer the option of static resolution where selection is
otherwise from the values actually passed [FUN-013].

---

## 1. What "done" means

```
./conform.sh --interpreted     every case green, and defects/ empty
./spec/spec.sh                 0 rules NOT YET IMPLEMENTED, 0 PARTLY
./test.sh                      the compiler's own suite still passes
./fixedpoint.sh                the seed is in sync and the fixed point holds
```

⚠️ **`fixedpoint.sh` is the constraint, not a formality.** Every change here is a
change to a compiler written in the language it compiles, and it must be
reseeded through the old binary before the new behaviour can be relied on. A
change to how the compiler emits its own code takes **two** generations to
settle — generation 1 holds the new rules written by the old emitter — which is
why the script iterates and why one reseed is not always enough.

⚠️ **The compiler must keep compiling.** Compiler gaps going red is expected and
fine; `algc` failing to build itself is not, because it is what produces the
generation that closes them.

## 2. Order, and why it is not free

Most defects are independent. Seven are not, and the dependencies were found
while writing the cases rather than by reading the code.

**DEF-12 before DEF-09.** [VAR-006] routes every untyped-to-typed crossing
through `as`. Tightening the assignment path while `as` still checks nothing
moves the hole rather than closing it.

**DEF-10 with DEF-19.** A parameter is an assignment context, so it must
**widen** as well as match. Enforcing parameter types before widening works
would start refusing a Char argument reaching a String parameter, which is
correct code.

**DEF-27 with DEF-10.** Once widening works, `Max` promoting is the rule the
operators already use rather than a special case in one built-in.

**DEF-02 needs `Console.a24` renamed first.** It declares a module-level
`const INFO` and an object member `procedure Info`, and likewise `ERROR` and
`Error`. Under folded lookup the member shadows the constant inside `Info`
itself and the compiler breaks.

**DEF-04 needs `SAMPLE` rewritten first.** `compiler/Main.a24`'s built-in sample
program — what `algc` runs when given no arguments — is written with `print`, so
removing the statement breaks it.

**DEF-14 is the hash, not the comparison.** A Map and a Set bucket by a hash, so
an Integer and a Double of one value must land in the same bucket or `Contains`
answers false for a key the Map holds. Changing only the comparison leaves the
bug.

**DEF-06 splits.** The range moves with DEF-01, since a Char wider than a byte
and a String of characters are the same change. The *diagnostic* half — a scan
error escaping as an uncaught raise with no line — is independent and worth
doing whatever the range turns out to be.

⚠️ **DEF-15 must not be fixed by copying the compiler.** The compiled back end
hoists every top-level name; [DCL-006] wants functions and classes hoisted and
[DCL-016] wants variables not. One mechanism, correct for one kind of
declaration and not the other.

## 3. Suggested sequence

**Wave 1 — done.** DEF-29 (a type error says what and where),
DEF-07 (the opening line), DEF-18 (a procedure may not `Exit` a value), DEF-20
(name the class), DEF-21 (publish `Ordinal`), DEF-25 (`Length` refuses a
collection), DEF-26 (a String answers `.Length`), DEF-28 (a file that cannot be
read exits non-zero), DEF-31 (a one-character test name), and DEF-06's
diagnostic half.

⚠️ **DEF-13 was deferred out of wave 1 for a reason that was not true.** It was
said to need "a registry of declared type names, and there is none:
`Lookup.Parents` holds only classes that *have* a superclass". `Parents` is the
inheritance map; `Types` is the registry, and `ClassStmt`, `ObjectStmt` and
`EnumStmt` all populate it. It belonged in wave 1 after all, and the fear that it
would refuse the compiler's own sources did not materialise.

⚠️ **Wave 1 opened three compiler gaps and closed one.** C-16, C-17 and C-18 are
new because the interpreter moved and the C runtime has not; C-9 closed, because
the interpreter came up to the compiler. That is the expected shape — the
compiler is generation 2 — but the count going *up* while the language gets more
correct is worth expecting rather than being alarmed by.

⚠️ **DEF-29 — done.** It was taken first for the reason it should have been:
every later fix produces type errors while it is being debugged, and each one
used to say `Type mismatch!` and nothing else. All five sites now report through
`Console.Error` with the offending token and both type names, and the two cases
that pinned it are `conformance/0108` and `0109`.

**Wave 2 — DEF-12 and DEF-16 done.** `as` is a checked conversion and binds at
the unary level. ⚠️ The order mattered exactly as recorded: `False and 5 as
Integer` was `(False and 5) as Integer` under the old precedence, which is a
Boolean cast to Integer — harmless while a cast did nothing, and a raise the
moment DEF-12 landed. Remaining:
DEF-10 (mostly) and DEF-27 done. **DEF-33 remains, and it is bigger than this
plan assumed.**

⚠️ **DEF-33 is not a wave-2-sized change.** Making a top-level subprogram
overload needs more than relaxing `CheckDuplicates`: an environment binds one
name to one value, so two functions of a name cannot both be reachable. Methods
get selection from `ObjClass.FindOverload`, and top-level functions have no
equivalent structure — the fix needs an overload set in the environment, or
mangled names resolved at the call. DEF-19 waits on it, as recorded.

⚠️ **DEF-10 is four contexts of six**, and the remainder is structural rather
than fiddly: the interpreter does not know a variable's declared type at run
time. `Env` stores values, not types, so a plain `X := 1` has nothing to widen
against. Closing it means storing declared types in the environment, or
annotating the assignment node from the checker — which is the same plumbing
DEF-09 needs, so the two want doing together.

⚠️ **DEF-33 before DEF-19, and DEF-19 probably closes with it.** Making a
top-level subprogram overload sends it through `FindOverload`, which compares
whole signatures — so its declared parameter types are checked as a consequence.
Attempting DEF-19 separately means writing a comparison path DEF-33 then makes
redundant.

**Wave 3 — done except DEF-05.** DEF-03 (identifier marks), DEF-17 (a
declaration may not be an unbraced body — ⚠️ this one *removed* C-12, the only
Annex C entry to close by the language moving), DEF-11 (`of` on every
collection), and DEF-15's function half.

⚠️ **DEF-15's class half was tried and backed out.** A class declaration
*evaluates* its superclass, so hoisting the declaration hoists the evaluation —
which broke `class B (A); … class A;` and made [CLS-014]'s `'X' is not a class.`
unreachable for any name declared in the same file. It needs a two-phase
declaration: bind the name at hoist time, resolve the superclass where the
declaration stands.

**DEF-05 remains**: the literal half is small and local, the arithmetic half
touches every operator.

**Wave 4 — done.** DEF-22 and DEF-23 were the same defect twice: a name two
things could bind was refused where it was *declared* rather than where it could
not be resolved. DEF-24 gave the root a module identity, which withdrew **C-1**
— the only known case of a valid program having no compiled form. DEF-02 folded
every name.

⚠️ **DEF-02 reversed C-4 in the COMPILER's favour**, the opposite of what that
entry proposed. Its recorded remedy — "compare exactly in `alg_property`" —
would have been wrong; `alg_stricmp` was right all along. A remedy written
beside a divergence assumes which side is at fault, and that assumption ages
badly.

⚠️ **Every diagnostic on the folded path was wrong at first**, and the
conformance corpus found each one: `'shared'` for `Shared`, unit `'deep'` for
`Deep`, `'x'` for `X`. Folding the key made the messages echo the key. When a
fix touches how names are looked up, expect to fix what the messages say too.

**Wave 5 — done.** DEF-01, DEF-06's range, DEF-32, DEF-08 and DEF-14. Text is
characters, a Char is a full code point, `''''` is a Char, a String carries its
own length, and membership follows equality.

⚠️ **Counting characters came out FASTER than counting bytes**, which is not the
direction it looks. Subscripting text called `strlen` on the whole string for
every character, so the scanner walked its entire source once per character
read — quadratic, and nothing had noticed.

⚠️ **The performance fix Annex G.2 predicted does not work**, and the section now
says so. "Append in place when the left operand is the arena's most recent
allocation" **never fires**: `S + 'x'` evaluates the Char first, and a Char is an
arena allocation, so something always sits between the string and the free
space. Reserving double the room instead puts the slack inside the string's own
block. Compiled, 40,000 appends went from **807 MB to 1.7 MB**.

⚠️ **The test suite caught a memory-corruption bug in that fix**, as corrupted
ANSI escapes. The check must be *identity* — pointer **and** length — not merely
a fitting capacity, or two appends from one base both succeed and the second
overwrites the first.

⚠️ **`#0` is refused only as a LITERAL.** `Char(0)` had to stay legal: the
scanner's own end-of-input sentinel is `Char(0)`, and refusing it left the
compiler unable to scan anything, including itself. That cost a bootstrap cycle
to find.

**Wave 6 — done.** DEF-30 (assertion messages) and DEF-04 (remove `print`).

⚠️ **DEF-30 revealed the two processors already disagreed** and nothing had
caught it: the runtime said `Assertion failed.` for `AssertTrue` where the
interpreter said `Assertion 'left = right' failed.` **C-23** records why it was
invisible — a compiled test run never prints the message at all, so the one
diagnostic a programmer reads most often sits outside everything that compares
the two reports.

⚠️ **DEF-04 could not be a deletion.** The compiler's own sources used `print`
fifty-odd times, `SAMPLE` included. The test sources were rewritten to bare
expression statements rather than to `WriteLn`, because that preserves the AST
shape the tests assert on.

### What is left, and why

All six waves are through. Nine defects remain, and none is simply "not done
yet" — each is blocked on a piece of machinery this compiler does not have.

| | Blocked on |
| --- | --- |
| DEF-09 | inference. `Lookup.Inferred` records a type and `Reduce` never consults it, so a local's type is unknown to the checker. |

⚠️ **DEF-13 is done, and was never blocked.** It was recorded as needing "a
registry of declared type names that does not exist", naming `Lookup.Parents` —
the *inheritance* map. The registry is `Types`, which every declaring form
already populates. Deferred through five waves on a misreading; the fix was
three lines of registration and one check.

| DEF-10 | the interpreter does not know a variable's declared type at run time. Widening works at a declaration, a `const`, a parameter and a return type because the declaration is in hand there; a plain **assignment** and a **field** have nothing to consult. |

⚠️ **DEF-19 and DEF-10b are done**, and they closed together for the reason the
entries predicted: signature comparison ran only for methods, so unifying it
enforced a top-level subprogram's parameter types — and `Fits` had to learn to
widen at the same moment, or `F (1)` into `X : Double` would have started
failing. Selection gained a second pass so an exact match still wins.

### The bootstrap trap

⚠️ **A change that makes the compiler refuse its own sources bricks the
bootstrap.** It happened once, doing DEF-09: the stricter checker was seeded,
and the seeded compiler then refused `compiler/*.a24` — so it could not emit a
new compiler, and there was no way forward from inside the tree.

The way out is the seed in git:

```sh
git checkout -- bootstrap/ && ./bootstrap/build.sh
```

⚠️ **So check before seeding, not after.** After building stage 2, emit the
compiler again with it — `algc --compile --out=/tmp/stage3 compiler/Main.a24` —
and only then trust the change. A stage-1 emit proves nothing about a rule the
stage-1 binary does not yet enforce.

## 4. Working rules

**Fix the rule the case names, and no more.** Each defect cites the rules it
violates; the case in `defects/` is the acceptance test. When it stops
reproducing, `conform.sh` reports `CHANGED` — that is the signal to promote it
to `conformance/` and delete the Annex F entry, not a failure.

**Reseed before believing anything.** `bootstrap/*.c` is a fixed point. A change
to `compiler/*.a24` that has not been reseeded is not yet real, and running
`algc` under `algc` is unreliable for anything large.

**A rule that names a field, a flag or a call order is describing the
implementation.** Two rules were written that way and had to be rewritten
([ERR-004] mandated a flag, [TST-014] described the compiler). If a fix makes a
rule easier to state, the rule was probably describing machinery.

⚠️ **Before recording any new case, ask what it would print if the
implementation were already right.** If that is what you are about to record,
the case proves nothing. See `conformance/README.md`, which carries this and the
rest of the corpus doctrine.

## 5. Not in this generation

**The compiler.** 28 gaps in Annex C, expected to stay red throughout. They are
generation 2, and failing on a compiler gap is the gate that will open it. Four
will close as a side effect of this generation — C-1 with DEF-24, C-12 with
DEF-17, and C-4 and C-9 reverse, becoming interpreter defects that this
generation fixes.

**Six planned generations** in Annex H: alternate bases and digit separators,
exponent notation, element types checked on insertion, a subscript operator, an
iteration protocol, a computed property, ordering for Strings, operator
overloading, and the collections as a unit written in Algol-24. ⚠️ H-4, H-5 and
H-6 are prerequisites for H-9, not companions to it.

**Two decisions deliberately left open**, recorded in Annex D rather than lost:

- Whether the built-in `Boolean` should become `type Boolean = (False, True)`.
  Tabled. ⚠️ [ENU-011] collides with it — members bind bare, so any program
  declaring `True`, `False`, `Yes` or `No` as a member name would make that name
  ambiguous at every bare use — and `VAL_BOOL` is a distinct runtime tag where
  an enum member is an interned object.
- Whether Integer `0` should be truthy, which would reduce truthiness to "only
  `nil` and `False` are false". It changes what existing programs mean, so it
  belongs to neither annex until someone takes it.

## 6. Still unbuilt

**Screen output in test blocks.** One of the three testing forms asked for at
the start, and the only one never built: a buffer cleared before each test body
and readable from it, so a test can assert on what a program printed. Nothing in
this plan depends on it, and it is the natural first feature to add once the
interpreter conforms.

⚠️ The design question recorded at the time is still open: whether the buffer is
a `Buffer` reachable from Algol-24 or an opaque native. A `Buffer` brings `Free`
and its poisoning rule into the test runner's lifetime, which is a larger
surface than the feature needs.

**Continuous integration.** There is none. `spec.sh`, `conform.sh`, `test.sh`
and `fixedpoint.sh` all exit non-zero on failure and are ready to be gates;
nothing runs them but a person. ⚠️ `conform.sh --record` refuses to run when
`CI` is set, which is the only preparation made so far.

## 7. What the conformance pass produced

For the record, and because the numbers say where the effort went.

| | |
| --- | --- |
| Rules | 261, none awaiting a case |
| Case files | 171 — 108 conformance, 29 refusals, 34 defects |
| Rules citing a conformance program | 196 |
| Rules citing a refusal | 30 |
| Rules citing a defect | 47 |
| Probes | 134 |

⚠️ **Those three do not sum to 260, and are not meant to.** A case usually
pins several rules — 1.7 on average, and `conformance/0058-exceptions.a24`
covers five — and a rule that is *partly* implemented cites both a conformance
program for the half that works and a defect for the half that does not. The
number that must reach 260 is **accounted for**, which `spec.sh` reports
separately and gates on.
| Annex C — compiler divergences | 15 |
| Annex D — advisory notes | 18, every one resolved |
| Annex H — planned generations | 9 |
| Checked tables | keywords, built-ins, grammar productions, the collection member matrix |

⚠️ **Three rules were overturned by running them**, having been written from
reading the code: [CLS-014] said the superclass check happens at construction
(it happens at the declaration), [MOD-012] said circular imports do not work
(they work), and D-15 invented a coincidence between `Length(L)` and `L.Length`
that never occurs. All three erred the same way — more confident than the
evidence supported.
