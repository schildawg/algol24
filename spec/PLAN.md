# Plan: Generation 1 — an interpreter that matches the specification

`spec/ALGOL-24.md` is written and every one of its 260 rules is claimed by a
case: a program in `conformance/`, a refusal in `refusals/`, or a reproduction
in `defects/`. The conformance pass decided what the language *should* do. This
plan is the work of making the interpreter do it.

**17 defects stand between the two.** *(33 found; sixteen fixed; DEF-09, DEF-10 and DEF-15 partly.)* Each one is a rule the specification
states and the interpreter does not implement, with a case in `defects/` that
passes while the fault persists and turns red the moment it stops.

## 0. The road to v1

| | | Ends when |
| --- | --- | --- |
| **Gen 0** | The specification is written and reviewed. | The spec is read carefully and signed off. Merge to `main`, tag **Gen 0**. |
| **Gen 1** | The spec is authoritative and conformance is enforcement. Work through the defects until there are none. | `defects/` is empty. Tag **Gen 1**. |
| **Gen 2** | Turn on the compiler. Annex C's divergences become defects and are worked through the same way. | Conformance passes under **both** processors and no defect remains. Tag **Gen 2**. |
| **v1** | New language features and a runtime library, prioritized, each staying within conformance. | Release. |

⚠️ **What changes at the Gen 1 → Gen 2 boundary is the corpus doctrine itself.**
Today a case is classified by one question — *is the interpreter right?* — and
compiler gaps are reported but do not fail the run
(`conformance/README.md`). At Gen 2 that relaxation ends: `./conform.sh
--strict` becomes the gate, and each Annex C entry earns a defect of its own.
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

⚠️ **Nothing after Gen 0 may change a rule without a reason recorded in the
specification.** The point of signing off is that the document stops being a
description of the implementation and starts being the thing the implementation
is measured against — so a defect is closed by changing the code, and a rule is
changed only by deciding to change the language.

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
| DEF-15 | two-phase class declaration. Hoisting classes broke `class B (A); … class A;` because a class declaration *evaluates* its superclass. Functions are hoisted; classes need the name bound before the body runs. |

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
generation 2, and `./conform.sh --strict` is the gate that will open it. Four
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
