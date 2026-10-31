# Algol-24 — defects

Where the implementation does not do what `spec/ALGOL-24.md` requires.

The specification is the authority: where the two disagree, the implementation
is in error and the difference is recorded here. Each entry names the rules it
violates, what the implementation does today, and the program in `defects/` that
reproduces it.

A defect's test is a **reverse conformance test**. It records the wrong
behavior and passes while that behavior persists, turning **red when the defect
stops reproducing** — because a fix is as much a change to be noticed as a
regression, and a suite that is permanently red is a suite nobody reads.

`./conform.sh` runs these alongside the conformance corpus, interpreted only: a
defect is a statement about the interpreter, and whether the compiler happens to
share the fault says nothing about whether the interpreter still has it.

---

**DEF-34 — `Val` accepts and refuses by `strtod`'s rules, not the language's.**
*(violates [RT-009])*

[RT-009] says `Val` reads "the same characters the literal rules do". It reads
what C's `strtod` reads:

| | is | should be |
| --- | --- | --- |
| `Val ('0x1F')` | Double `31.0` | Integer `31` [LEX-016] |
| `Val ('1_000')` | refused | Integer `1000` |
| `Val (' 42')` | Double `42.0` | refused |
| `Val ('.5')`, `Val ('5.')` | accepted | refused [LEX-020] |
| `Val ('+7')` | Double `7.0` | refused |

⚠️ **The fix must not cost precision.** `Val` is the scanner's number parser, so
whatever it does is what a literal means. An Algol-24 rewrite got every form
above right and then read `1.0E300` back as `1.0000000000000002E300`, because a
correctly-rounded decimal-to-binary conversion is a hard numerical problem and
repeated multiplication is not one. What is wanted is `strtod`'s arithmetic
behind the language's acceptance test — a check on the text *before* handing it
over, not a replacement for it.

    defect  DEF-34-val-follows-strtod.a24

**DEF-37 — `Foreign` reads its argument list as a host sequence, which it is
only when compiled.** *(violates [RT-001], [INI-008])*

[RT-001] makes `Foreign` one of the thirty always-available built-ins, so a
program may call it directly and not only through an `external` declaration.
`alg_foreign_call` casts its `args` to the runtime's own sequence and reads a
count from it. Under the compiled back end that is what a List is; interpreted,
a guest List is an `ObjCollection`, so the count comes from an unrelated field.

A call passing **one** argument is therefore refused for passing too many:

| | answers |
| --- | --- |
| compiled | `Foreign calls are not available in this build: 'strlen' cannot be reached.` |
| interpreted | `A foreign call takes at most eight arguments.` |

The compiled answer is right — [INI-008] is what a build without libffi owes.

⚠️ **It is a type-confused read rather than only a wrong message.** The count is
an `int32_t` taken from whatever field sits at that offset, and the loop that
follows indexes `items[i]` that many times. Here it happens to exceed eight and
be refused; an object laid out differently could pass the check and then read
past the end. That is why this is filed as a defect rather than as a
diagnostic's wording.

**An `external` declaration is unaffected under both processors**, which is
what makes the defect narrow: the interpreter reaches the runtime with
arguments that are already host sequences, so `TextLength ('abc')` answers
correctly interpreted and compiled alike. Only a direct call differs. The
bytecode machine is also unaffected, because it is compiled.

The fix belongs on the Algol-24 side rather than in `algol.c`: the built-in
should hand the runtime a host sequence, as the interpreter's own external path
already does, rather than teaching the C runtime about the interpreter's object
layout.

    defects  DEF-37-foreign-misreads-an-interpreted-list.a24

**DEF-35 — A type inferred from an initializer is invisible above the declaration.**
*(violates [VAR-006], [DCL-007])*

[DCL-007] resolves a free name in a subprogram body when the body **runs**, not
where it is written, so a subprogram may read a module-level `var` or `const`
declared below it provided the call comes after that declaration. The checker
does not follow it that far. A declaration whose type is **inferred** is not
recorded until the checker walks the declaration itself, so a body checked above
it reduces the name to no type at all — and [VAR-006] then refuses the
assignment, because a value whose type could not be determined does not satisfy
a written type:

| | |
| --- | --- |
| `Bound := LIMIT;` above `const LIMIT := 7;` | `Expected Integer, found an untyped expression.` |
| the same file with `const LIMIT : Integer := 7;` | runs, prints `7` |

⚠️ **[VAR-006] already rejects this class of fault.** Its own note records that
refusing an untyped value at an assignment "refused *correct code*, and the
wrong trade would have been to punish a program for the checker's blind spot",
and lists three blind spots that had to close for that reason. This is a fourth
of the same family: the value has a type, and the checker has simply not reached
it yet.

⚠️ **It reaches this compiler's own sources.** `ObjFunction.a24` declares
`EXACT`, `WIDENING` and `ABSORBING` below `Select`, which reads them, and
`ObjClass.a24` imports them for the same use — so writing the natural annotation
on that loop, `for var Pass : Integer := EXACT;`, makes `algc` refuse the file it
was built from. The absence of a type is the only reason it compiles, which is
the opposite of what a gradual type system should reward.

⚠️ **A `var` behaves the same way as a `const`**, so this is about the order of
declaration rather than about constants.

    defect  DEF-35-inference-stops-at-a-later-declaration.a24

⚠️ **This annex held thirty-three defects and holds two.** Every other one has
been fixed and its reproduction removed. Three of them turned out to be the **rule's** fault
rather than the implementation's, and were closed by changing this document —
`SRC-005` on Unicode identifiers, `LEX-025` on `Char(0)`, and a blocker recorded
in a defect entry that named the wrong data structure. The note at the end of
Annex C keeps that last one, because the lesson is about where a blocker is
written down rather than about the defect.
