# Plan: ALGOL-24.md, the language specification

A detailed, normative specification for Algol-24, shaped after the Go Language
Specification. This document is the plan for writing it; it is not the
specification and carries no normative weight itself.

Nothing here has been written yet. The intent is that work can start from this
file without reconstructing the conversation that produced it.

---

## 1. Goal and authority

Gen 0 has no written definition of the language. Rules that used to cite the
old `ALGOL-24.md` now assert themselves in comments with nothing behind them —
that top-level functions do not overload, that `=` and membership disagree
about `1` versus `1.0`. The specification exists to give those claims a source.

⚠️ **The interpreter is the sole authority.** Where the tree-walking
interpreter in `compiler/*.a24` and the C runtime in `bootstrap/algol.c`
disagree, the interpreter defines the language and the compiler is in error.
No other implementation is consulted; there is no other implementation.

⚠️ **The specification is normative even where the behaviour is plainly
wrong.** If the interpreter treats the Integer `0` as falsey and `0.0` as
truthy, the specification says so, flatly and without hedging. Doubts do not
belong in the normative text — they belong in Annex D, which is not normative.
A specification that argues with itself cannot be conformed to.

⚠️ **Every normative claim is verified by RUNNING the interpreter, not by
reading it.** Reading produces plausible claims; running produces true ones.
This is not a style preference — every real finding in this codebase so far
came from executing something and comparing bytes.

---

## 2. Traceability

### 2.1 Stable rule IDs, not section numbers

Hierarchical section numbers (`§4.2.3`) are rejected as identifiers. Inserting
one clause renumbers everything after it, and every citation from code, tests
and annexes silently rots.

⚠️ This project has been bitten by exactly that failure three times already: a
TextMate keyword list nobody checked against the scanner, a test count quoted
as 277 when the suite could not produce it, and a back-end coverage claim that
listed `if` and `while` while the thing compiled itself. An unchecked copy goes
stale. A specification is the largest unchecked copy this repository would own.

Instead, each normative claim gets an **immutable ID**, assigned once, never
reused and never renumbered. Sections stay named and may be reordered freely.

Namespaces, numbered independently within each:

| ID | Chapter |
| --- | --- |
| `SRC` | Source code representation |
| `LEX` | Lexical elements |
| `TYP` | Types |
| `VAL` | Properties of types and values |
| `DCL` | Declarations and scope |
| `EXP` | Expressions |
| `STM` | Statements |
| `FUN` | Functions, procedures and closures |
| `CLS` | Classes and objects |
| `ENU` | Enumerations |
| `COL` | Collections |
| `MOD` | Modules |
| `RT` | Built-in functions |
| `INI` | Program initialization and execution |
| `ERR` | Errors and exceptions |
| `TST` | Test blocks |

One ID per **testable claim**, not per paragraph. Granularity is what makes a
citation worth having: `[LEX-012]` should name something a single test can
prove or disprove.

### 2.2 The shape of a rule

```
[LEX-012]  A one-character literal is a Char, never a String, and the two are
           never equal.  The length is measured on the raw span between the
           quotes: '' is the empty String, '''' is the quote itself and is a
           String of length one.

           interpreter  compiler/Scanner.a24 · ScanString
           compiler     bootstrap/algol.c · VAL_CHAR
           tests        Scan One Character Is A Char
                        Scan An Escaped Quote Is A String
```

The trailer is machine-readable. `interpreter` is mandatory — it is the
authority. `compiler` is optional and omitted where the back end has no say.
`tests` may be empty, and a rule with no test is a claim nobody has proven,
which the checker reports.

### 2.3 spec.sh — the checker

Written alongside the first chapter, not after the last. In the same spirit as
`fixedpoint.sh`: the point is that the document cannot quietly drift.

1. Every ID is unique, well-formed, and within a known namespace.
2. Every cited file exists, and every cited symbol is found inside it.
3. **Every cited test name exists in the suite.** Real names are enumerable
   from the report — `bootstrap/algc --test compiler/Main.a24`, ANSI stripped.
4. Coverage, both directions: rules citing no test (unproven claims), and tests
   no rule cites (undocumented behaviour).

Point 3 is the one that pays for the whole scheme. A rule citing a test that
has been renamed or deleted becomes a failure instead of a lie.

---

## 3. Structure

One file, `ALGOL-24.md`, as Go's specification is one file — searchable in a
browser, and the chapter count does not justify splitting. Go's shape carries
over: EBNF productions inline, terse normative prose, short examples.

Chapters, in Go's order where there is an analogue:

1. Introduction — scope, conformance, what "normative" means here, the
   interpreter's authority
2. Notation — the EBNF variant used
3. Source code representation — ASCII only, line termination, case-insensitive
   keywords
4. Lexical elements — comments, identifiers (`?` and `!` included), the 38
   keywords, operators, Integer and Double literals, Char and String literals,
   `#` code points, the absence of backslash escapes
5. Constants and variables
6. Types — Integer, Double, String, Char, Boolean, Any, nil; classes; enums;
   List, Set, Stack, Array, Map; Buffer; TextFile
7. Properties of types and values — assignability, gradual typing and what
   `Any` means, `is`, `as`, truthiness, equality against membership
8. Declarations and scope — blocks, shadowing, `const`, resolution depth,
   `this`, `super`, visibility
9. Expressions — precedence, operators, calls, overload selection,
   subscripting, parenthesis-free properties
10. Statements — `if`, `while`, `for`, `for … in`, `case`, `break`,
    `try`/`except`/`raise`, `print`, `Exit`
11. Functions, procedures and closures — constructors, getters and setters,
    capture, overloads
12. Classes and objects — fields, methods, `public`/`private`, inheritance,
    `ClassName`, `ToString`
13. Enumerations
14. Collections — insertion order, per-kind methods, Map key rules
15. Modules — `uses`, resolution order, exports, `private`, non-transitivity,
    unit qualification
16. Built-in functions
17. Program initialization and execution — top-level statements, the main
    block, module initialization order
18. Errors and exceptions — `raise`, handler matching by runtime type,
    most-derived wins, exit codes
19. **Test blocks** — `test`, the assertions, report format, ordering, exit
    codes. Go has no analogue; Algol-24 needs one, because the report is part
    of the observable surface both implementations must reproduce.
20. Annexes — A grammar summary · B built-in index · C compiler divergences ·
    D advisory notes

---

## 4. Annex C — compiler divergences (non-normative)

Where the C back end does not do what the interpreter does. Each entry: the
rule ID, the interpreter's behaviour (normative), the compiler's actual
behaviour, whether it refuses loudly or differs silently, and severity.

⚠️ A silent difference is far worse than a refusal, and the entries should say
which is which.

Seed entries, all observed:

- **A file in an import cycle with the root will not compile.** The root is
  never entered in the parser's `Loaded` map, so a module importing it back
  parses it twice; the emitter then sees two units of one name and refuses:
  `Two modules named 'Parser' is not supported by the C back end yet.` The
  same file runs correctly interpreted. Loud, and currently the only known
  case where a valid program has no compiled form.
- **A compiled assertion failure carries no message.** `alg_test_run` prints no
  `[ERROR]` line, because compiled code has no line information. The FAIL
  stands alone. Loud enough, and a property of the runtime rather than a bug.
- **Conformance requirement to state, not a divergence:** interpreted and
  compiled `--test` reports are byte-identical, colour included — 239 lines and
  1,416 escape sequences each for the full suite. Any difference is a defect in
  one of them.

## 5. Annex D — advisory notes (non-normative)

Where the specified behaviour looks like a mistake. Each entry: the rule as
specified, why it appears wrong, what would break if it changed, and a
recommendation. **No entry may weaken the normative text it refers to** — the
body states the behaviour; the annex argues about it.

Seed entries, all present in the language today:

- `=` promotes numerically while membership and Map keys compare strictly, so
  `1 = 1.0` is true but `1 in [1.0]` is false. `bootstrap/algol.c` already
  calls this a rough edge in its own comments.
- The Integer `0` is falsey and `0.0` is truthy.
- An enum member whose ordinal is zero is falsey, which makes the first member
  of every enumeration false and every later one true.
- `break` inside a function declared inside a loop is accepted, because the
  parser's loop depth is not reset on entering a function body. At run time it
  would escape the call.
- A method's signature is checked on call and a constructor's is not.
- Top-level functions do not overload; methods do.
- String indices are 0-based, `Pos` answers `-1` when absent, and `Copy` clamps
  its end but not its start.

---

## 6. Verification

Each chapter is accompanied by small `.a24` probes that demonstrate the
behaviour being specified. They are run, and their actual output recorded as
the chapter's examples.

This is the mechanism that keeps the specification honest: an example that was
reasoned about rather than executed is exactly the kind of plausible-and-wrong
claim this project keeps finding.

**Done, and both tiers landed together.** Probes live in `spec/probes/`, each
naming the rules it exercises, beside a `.actual` recording of what the
implementation did. `spec/probes/record.sh` re-runs them all and reports
anything that moved.

⚠️ **A probe records what the implementation DOES and asserts nothing about
what it SHOULD do.** It is evidence and a change detector, not a test, and a
rule whose probe runs green is still `conformance TBD`. Keeping the two apart
is what allows the specification to be written before the conformance
commitments are decided — writing a conformance case the moment a behaviour is
discovered would canonize every defect on sight.

The plan had originally deferred keeping the probes to a later tier. That was
wrong in a way worth recording: the probes for chapters 3 and 4 were written,
run, and thrown away, and a later conformance pass would have had to derive all
33 of them again without knowing which edges had mattered. Freshness is not
about memory, which does not persist between sessions — it is about whether the
artifact was saved.

---

## 7. Testing

Three tiers, and they are not interchangeable.

| Tier | Tests | Lives in | Judged by |
| --- | --- | --- | --- |
| Unit | algc's own internals | `test` blocks in `compiler/*.a24` | assertions, in-process |
| Conformance | the language | `conformance/*.a24`, standalone programs | exact stdout and exit status, compared across implementations |
| Refusal | programs the language must reject | `refusals/*.a24`, one case per file | exact diagnostic and exit status, from outside the language |

⚠️ **A unit test can never be a conformance test.** The suite in `compiler/`
reaches into algc's own classes — `uses Scanner`, `Parser (…)`,
`TypeChecker().Resolve (…)`. Another implementation exposes none of that. Those
tests are valuable, and they test the compiler, not the language.

### 7.1 Refusals

⚠️ **A refusal test is a test of a program that cannot exist.** Any in-language
harness needs a loadable program; a refusal case is by definition not loadable.
Refusals can therefore only be judged from outside the language, by running a
file and inspecting what came back.

Observed, and the reason this is not a matter of taste: a file holding three
test blocks, one of which contains `var X : Integer := 'text';`, produces

```
Uncaught: Type mismatch!
```

and no report whatsoever. The other two tests do not fail — they never run.
Because `uses` parses a module inline, a refused module takes the suites of
every file importing it down as well.

⚠️ **One case per file, and this is forced rather than stylistic.** The first
refusal aborts the run, so a second case in the same file is unreachable: it
would sit permanently untested while appearing to be covered, which is worse
than having no test at all.

```
refusals/
  0001-type-mismatch.a24        one invalid construct, nothing else
  0001-type-mismatch.expected   exact diagnostic
  0001-type-mismatch.exit       expected status
```

Two facts must be RECORDED per case, because neither can be inferred:

- **Which processors must refuse it.** A front-end refusal — scanner, parser,
  resolver, checker — must be refused by both the interpreter and the compiled
  program, with the same message. That is the strongest conformance property in
  this scheme, because the two share a front end and any divergence is a defect
  by construction. An emitter refusal applies to `--compile` only; a link
  failure surfaces from `cc` and is compile-only.
- **Refusal or runtime error.** Both exit non-zero, so "did it fail" does not
  separate them. A refusal is rejected BEFORE execution; a runtime error ran and
  then raised. Conflating them lets a program that dies halfway masquerade as
  one that was correctly rejected.

This is the role the old `refuse.sh` played. It went with the JPascal cut, and
what replaces it compares the two implementations that exist against each other
rather than against an absent oracle.

Note on `Rejects` in `compiler/TypeChecker.a24` — 29 of that file's 30 tests use
it, across 41 assertions. It is a unit test of the type checker and keeps its
value as one; it is not language-level refusal testing and cannot become it.

⚠️ It also returns a Boolean and discards the message, so a test passes when the
source is rejected for ANY reason, including a typo in the test's own source.
Replacing it with a `RejectedWith (Source, Message)` that asserts the exact text
should come before the count of tests using it grows further.

### 7.2 Conformance

Standalone programs. Not unit tests, and not snippets embedded in the
specification:

- Unit tests are disqualified above.
- Snippets need extraction tooling to be runnable, and that tooling is a tax
  that drifts — the exact failure the rule IDs exist to prevent.
- A program needs only "can this implementation run a file and produce output",
  which is the smallest surface any implementation must have.

```
conformance/
  0001-char-vs-string.a24     // spec: LEX-012, LEX-013
  0001-char-vs-string.out     expected stdout, byte-exact
  0001-char-vs-string.exit    optional, default 0
```

`.out` is a **gold master**: an authored statement of what the program should
print, not a recording of what it happens to print.

Each program is checked twice, and the two checks do different work.

- **Against `.out`** — catches "both implementations are wrong". They share a
  front end, so their agreeing about anything scanning, parsing or type-checking
  decides is weak evidence: both would agree on the same defect. Only an
  authored expectation can catch that.
- **Against the other processor** — catches back-end divergence, where the two
  genuinely differ. That comparison is known to be sharp: it is how the full
  test report was shown identical across the two, 239 lines including colour.

Neither subsumes the other, so both are kept.

⚠️ Write output with `WriteLn`, never `print` — `print` is being removed from
the language, and a corpus built on it would rot on the day it goes.

Seed the corpus from the Annex D entries. They are the highest-risk behaviours
and the ones a second implementation is likeliest to get wrong: `1 = 1.0` while
`1 in [1.0]` is false, a falsey Integer `0` beside a truthy `0.0`, a falsey
first enum member.

#### Authoring a case, and the record toggle

The intended flow for a new case is to write the program, record what it
actually does, and then edit that down to what it *should* do. The gap between
the two is not an inconvenience — it is where findings come from. If recording
and then editing produces a diff, either the program is wrong or the language
is, and the second outcome is an Annex D entry.

For a rule already settled, the stronger variant is to author `.out` from the
specification first and run afterwards, so the implementation's answer is never
seen before committing to the right one.

⚠️ Golden testing's characteristic failure is canonizing a regression: output
changes, the expectation is blessed, the test goes green and the defect is now
the specification. Three rules keep the toggle from becoming that path.

1. **Recording writes `.actual`, never `.out`.** Moving it across is a
   deliberate act after reading the diff. This preserves the authoring flow and
   removes the one-keystroke route from "output changed" to "test passes".
2. **Refuse to record when the two processors disagree.** There is no single
   "what IS" in that case, and recording either one silently buries a
   divergence.
3. **Never record in CI.**

### 7.3 Colour in expectations

Conformance programs emit no escapes — colour lives in the report and in
`Console`'s diagnostics, never in `WriteLn` — so that corpus is plain text and
byte-exact needs no help. Refusal expectations capture diagnostics, which are
coloured, and would otherwise be files full of raw escape bytes: unreadable to
author and worse to review.

Do not strip them. **Transliterate**:

```
\033[31m  ->  [RED]
\033[0m   ->  [RESET]
```

⚠️ Comparing transliterated text is exactly as strong as comparing raw bytes,
provided the mapping is TOTAL and INJECTIVE. Stripping is neither — many inputs
collapse onto one output, so a wrong colour and a right one compare equal, and
a colour defect can never be caught by the corpus. Transliteration keeps the
comparison intact and gains legibility; it is not a weakening, and it is the
reason to prefer it rather than mere tidiness.

The palette is a closed set of seven — RESET, RED, GREEN, YELLOW, BLUE, CYAN,
WHITE — defined in `compiler/Console.a24` and mirrored in `bootstrap/algol.c`,
so a total mapping is small and easy to keep current.

Two rules make it safe:

- **An escape with no mapping renders visibly and distinctly** — `[ESC:35m]` —
  never passed through untouched and never dropped. An unexpected colour has to
  surface as a diff rather than vanish into the transform.
- **If the raw bytes already contain a sentinel literally, refuse to
  transliterate that case and compare raw.** Checked before the transform, this
  makes ambiguity impossible rather than merely unlikely.

The failure diff is the other beneficiary: `expected [GREEN]PASS[RESET], got
[RED]PASS[RESET]` says what went wrong, where two rows of escape bytes do not.

### 7.4 One harness, two directories

Conformance and refusal cases differ only in what is expected — a valid program
with expected stdout and status zero, against an invalid one with an expected
diagnostic and a non-zero status. Same runner, same `spec:` header, two
directories. Build it once.

### 7.5 Screen output in unit tests

A test body cannot currently observe what the program under test wrote: during
a run both implementations DISCARD it — the interpreter through
`OutputSuppressed`, the C runtime by returning early from `alg_write` and
`alg_writeln` when `in_tests`.

The semantics wanted are a screen buffer cleared at the start of each test and
readable by the body. The capture point already exists in both; it drops the
text instead of keeping it.

⚠️ Reach it through a NATIVE ACCESSOR rather than an implicit parameter to the
test block. A test body is emitted as `AlgFunction (cells, args, count)` and
invoked by `alg_test_run` as `body (NULL, NULL, 0)`; passing an implicit
argument changes that signature, the runner, and the emitter, in both
implementations. An accessor needs none of it, and is explicit in the source
where an implicit name is invisible.

Three changes, all small:

1. Interpreter: append to a Buffer instead of discarding.
2. C runtime: append instead of returning early.
3. Runner: clear the buffer before each test body.

## 7.5 Which suite a case belongs in

⚠️ **One question decides it: is the interpreter right?** The compiler's state
never enters into the classification.

| The interpreter is | The case goes in |
| --- | --- |
| right | `conformance/` or `refusals/`, **even if the compiler is wrong** |
| wrong | `defects/`, **even if the compiler is right** |

This follows the generation plan rather than tidiness. The goal of the next
generation is an interpreter that matches the specification; the goal of the one
after is a compiler that matches the interpreter. Classifying by the compiler's
state would mix two generations of work into one suite.

**A divergence is an outcome, not a category.** Every conformance case runs under
both processors. One the interpreter gets right and the compiler does not fails
its compiled half, and that failure *is* the record of the divergence — so there
is no divergence suite, and Annex C entries are reproduced by ordinary
conformance cases.

`conform.sh` therefore reports **two verdicts**:

- **the language** — the interpreted half, which must be green. This is the gate.
- **the compiler** — gaps, counted and listed. Expected while the compiler
  trails, and not a failure unless `--strict` is given.

⚠️ A third question is asked elsewhere and is the one that must not break: does
the compiler still **build and reproduce itself**? That is `./fixedpoint.sh` and
`./test.sh`. A compiler that cannot compile cannot produce the generation that
closes these gaps.

⚠️ **An opt-out records nothing and notices nothing.** Twelve conformance cases
carried a `// compiled: no` marker to keep the suite quiet about a known
divergence. C-14 — compiled code does not check arity **at all** — was found
within minutes of removing them, in a case that had been opted out since the day
it was written. C-9, C-11 and C-13 had no reproduction anywhere while the markers
stood. The markers are gone and will not come back.

### 7.6 A retired rule is not a falsified one

⚠️ A case leaves the corpus for two very different reasons, and they must not
look alike in a diff.

**Withdrawn** — the case pinned the wrong behaviour. `refusals/0028` pinned two
enumerations being unable to share a member name; the decision went the other
way, so the case was deleted and a defect took its place. This is a correction,
and the case was wrong from the moment it was written.

**Retired** — the rule stopped describing the *language*. The collections are
moving out of the core into a unit written in Algol-24 (Annex H, H-9), and when
they do, most of chapter 14's rules leave the specification and their
conformance cases become **unit tests of that unit**. Nothing was wrong; the
subject changed from a language feature to a library.

The chapter 14 cases are worth writing now for exactly that reason: they are the
behavioural target the unit has to meet, and writing them before the move is
what makes the move checkable.

⚠️ Two things survive the move and are not provisional: `Array`, which nothing
in the language can express, and [COL-007]'s insertion order, which binds a unit
as a third implementation exactly as it binds the two processors.

## 8. Phasing

Realistically 15,000–25,000 words. Delivering it in one drop is how it gets
done badly.

| Phase | Content | Status |
| --- | --- | --- |
| 1 | Skeleton, ID scheme, `spec.sh`, source representation, lexical elements | **done** |
| 2 | Core semantics: constants and variables, types, values, scope, expressions, statements | **done** |
| 3 | Functions, classes, enums, collections, modules, built-ins, initialization, errors, test blocks | **done** |
| 4 | Annexes A–E; `spec.sh` swept over every rule and both tables | **done** |
| 5 | **The conformance pass** — deciding, rule by rule, what the language *should* do | chapters 3–4 done |

### Phase 5 progress

| Chapter | Rules | Decided |
| --- | --- | --- |
| 3 Source code representation | 11 | Unicode text; identifiers fold ASCII case; `#10` is the sole line terminator |
| 4 Lexical elements | 33 | Char is a code point; `?` and `!` are trailing identifier marks; overflow is refused or raised; `print` leaves the language |
| 5 Constants and variables | 18 | A written type is enforced everywhere; `as` becomes checked; Pascal widening at six assignment contexts; element types flow to reads |
| 6 Types | 13 | `is` must name a declared type; the three limits on a class type become planned work, not faults |
| 7 Properties of types and values | 14 | Membership follows equality; Pascal's `Char`/`String` equality rejected; truthiness kept |
| 8 Declarations and scope | 16 | Functions and classes hoist, variables do not; `private:` is normatively advisory |
| 9 Expressions | 17 | `as` binds tightly; a parameter widens like any assignment context; division-by-zero asymmetry kept |
| 10 Statements | 23 | A declaration may not be an unbraced body; most-derived handler selection kept and made total |
| 11 Functions and closures | 12 | `procedure` may not `Exit` a value; parameter types enforced everywhere |
| 12 Classes and objects | 16 | Inheriting from a non-class gets a message about inheritance |
| 13 Enumerations | 11 | Shared member names accepted, ambiguity refused at the use; a member answers `Ordinal`; whether the first member is falsey is **open** |
| 14 Collections | 15 | Member names fold case; membership follows equality; the member matrix is checked live |
| 15 Modules | 14 | Modules may share exported names, ambiguity refused at the use; cycles between modules **work** |
| 16 Built-in functions | 17 | `Length` refuses a collection; a String gains `.Length`; `Val` and `Max` made usable together |
| 17 onwards | 30 | — |

⚠️ **Chapter 16 corrected an Annex D entry that had invented a detail.** D-15
said `Length(L)` and `L.Length` "even coincide at small sizes before
diverging". They never coincide: a List of *n* one-digit numbers renders as `3n`
characters against a count of *n*. The claim was plausible, was never run, and
had been repeated into a defect case before the recording contradicted it.

⚠️ That is the third inherited claim this pass to fail on contact with a run —
after [CLS-014]'s superclass timing and [MOD-012]'s cycles. All three were
written from reasoning about the code rather than from executing it, and all
three were wrong in the same direction: more confident than the evidence
supported.

⚠️ **Chapter 15 overturned a rule that had been wrong since it was written, and
a probe was the reason.** [MOD-012] said "circular imports do not work" and gave
`Type mismatch!` as the evidence. Cycles between modules work fine. The
`Type mismatch!` came from the probe's own fixtures, which returned `'A'` and
`'B'` from functions declared `: String` — a one-character literal is a Char
[LEX-023], so those functions failed whether or not a cycle existed.

A probe recorded a real failure, of a different thing, and the rule was written
from it. The recording was never wrong; the inference was. ⚠️ **A probe proves
that a program did something, not why** — and a fixture that fails for an
unrelated reason is indistinguishable from one that fails for the reason being
studied.

⚠️ **Two of chapter 14's fifteen rules contradicted decisions already made**, and
neither was a judgement call. [COL-006] said collection member names are matched
exactly, which [SRC-011] reversed in chapter 3. [COL-012] said membership
compares strictly, which [VAL-013] reversed in chapter 7. Both now cite the
defect that already tracks them — DEF-02 and DEF-14 — rather than carrying a
second, contradictory statement of the same behaviour.

⚠️ [COL-006] is **the one place where the C back end is already right and the
interpreter is the one to change.** Every other Annex C entry runs the other
way.

⚠️ **Chapter 13 left a rule undecided on purpose.** [ENU-009] makes the first
member of every enumeration falsey, so reordering an enumeration silently
changes the truth of every conditional written over it. That looks wrong, and
the evidence says changing it is safe — the compiler's own two enumerations are
compared explicitly at all five use sites and never tested bare. But changing it
reverses part of [VAL-008], which chapter 7 decided, and reopening a decided
rule is not a call to make while writing the chapter that meets it. It is
recorded in D-13 with the evidence attached.

⚠️ **Chapter 12 corrected a rule by running it.** [CLS-014] and D-12 both said
the superclass check happens at construction. It does not — the declaration is
refused even when the class is never constructed, which a `WriteLn` on either
side of it shows immediately. The defect is a message and nothing else, which
makes it much smaller than it had been recorded as being. Reading the code had
produced the wrong answer twice; one run settled it.

⚠️ **Chapter 11 had almost nothing to decide, and that is the expected shape
from here.** [FUN-006] said a top-level parameter's declared type is not
enforced — but [VAR-017] had already listed a parameter as one of the six
assignment contexts, so it was a contradiction to propagate rather than a
judgement to make. Chapters 3–10 decided the rules the later chapters merely
apply, so the later chapters are mostly bookkeeping with occasional real
questions.

`./spec/spec.sh --gaps` reports which chapters still have rules with no case,
and which rules they are.

⚠️ **Chapter 10 produced the first defect whose fix REMOVES a divergence.** The
C back end already refuses a declaration as an unbraced branch body (C-12), and
[STM-002] now refuses it too — so fixing DEF-17 leaves the language, the
compiler and the interpreter agreeing. Every other entry in Annex C needs the
compiler brought up to the language; this one needs the language brought down to
the compiler, and the compiler was right.

⚠️ **C-13 is the first case of the emitter breaking its own contract.** It is
supposed to refuse by name what it cannot emit; instead it emitted C that `cc`
rejects, so the diagnostic named a generated symbol rather than the loop the
programmer wrote. A refusal is strictly better than a valid-looking emission
that fails downstream, and that distinction is worth applying to any future gap
found in the emitter.

⚠️ **Chapter 9 was mostly propagation, and that is the shape to expect from
here.** Two of its rules cited rules that had been decided against them —
[EXP-007] said arithmetic wraps and pointed at [LEX-018], which says it raises;
[EXP-015] counted bytes and pointed at [SRC-004], which counts characters. A
rule that cites its own contradiction is the specific rot the ID scheme makes
findable and nothing automatic catches.

⚠️ **A defect case must distinguish the two behaviours, not merely exhibit the
current one.** The first draft of DEF-16 recorded `5` for a cast covering a
conjunction — which is what the *fixed* behaviour prints too, since a cast has
no runtime effect yet and `and` yields an operand. It would have passed forever
and proved nothing. Only the parse failure separates the readings, so that is
the whole of the case. This is the same failure as the CRLF probe git
normalized and the three empty probes: an artefact that agrees for the wrong
reason.

⚠️ **Chapter 8's main decision required splitting one rule in two because the
two processors were each wrong about a different half.** The compiled back end
hoists every top-level name; the interpreter hoists none. Hoisting a function or
class is right — nothing executes, and it lets a file be read top-down — so
[DCL-006] says so and the interpreter is the defect. Hoisting a *variable* is
wrong — its initializer runs in order, and reading early yields `nil` where an
error is honest — so [DCL-016] says so and the compiler is the defect. One
mechanism, correct for one kind of declaration and not the other.

⚠️ **The corpus itself is now shaped by a divergence.** C-11 reorders a bare
top-level `begin` … `end`, so any case using one to demonstrate scoping cannot
run under both processors. `conformance/0040` puts its blocks inside procedures
to keep the cross-check rather than opting out — worth doing wherever a case can
be rewritten to avoid a known divergence instead of surrendering half its
value.

⚠️ **Three of chapter 7's probes were empty files** — a header comment and no
program. `record.sh` recorded "no output, exit 0" as their behaviour and
reported green, so nine rules cited evidence that did not exist while the change
detector said nothing had shifted. All nine turned out to be correct when
finally run, which is luck rather than method. `record.sh` now rejects a probe
with no executable line.

⚠️ The general lesson is about what a green harness means. A check that cannot
distinguish "ran and produced nothing" from "there was nothing to run" reports
success for both, and the failure is invisible precisely because the artefact
exists.

⚠️ **Chapter 6 found the worst divergence recorded so far**, and found it only
because `conform.sh` refuses to record an expectation when the two processors
disagree. Reading a method as a property — `B.Length` with no parentheses —
prints `<fn Length>` interpreted and **segfaults** compiled, with no output at
all. Five of chapter 6's nine cases were skipped by that guard; three were real
divergences (C-6, C-7, C-8). None of them would have been noticed by running the
interpreter alone, which is what every probe in `spec/probes/` does.

⚠️ **Chapter 4 added a rule and did not renumber anything**, which is the ID
scheme earning its keep. Splitting integer overflow into a literal check and an
arithmetic check needed a second rule; it became [LEX-033] and sits between
[LEX-018] and [LEX-019] in the text. Under section numbering every citation
after it would have moved.

Two conventions came out of chapter 4 and now apply to every chapter after it:

- **A rule ahead of the implementation says which of three things it is.** `NOT
  YET IMPLEMENTED` (wrong outright — must cite a defect), `PARTLY IMPLEMENTED`
  (wrong in part — must name one in prose), or `PLANNED — a later generation`
  (not wrong at all — Annex H). `spec.sh` enforces all three, and rejects a rule
  claiming to be both wrong and planned.
- **Annex H exists** because "we will add hex literals later" is not a defect.
  The implementation is right about it, so the corpus pins the *current* rule
  with an ordinary refusal, which turns red exactly when the generation lands.

**Chapter 5 decided two rules together that do not stand alone.** `as` becomes a
checked conversion [VAL-007] *and* a written type is enforced wherever a value
reaches the variable [VAR-006]. The order matters to whoever implements them:
[VAR-006] routes every untyped-to-typed crossing through `as`, so tightening the
assignment path while `as` still checks nothing would move the hole rather than
close it. DEF-12 before DEF-09.

⚠️ The goal driving both is a **fully typed source** the C back end can rely on.
A declared type that some path can violate is not a type the emitter may use to
choose a machine representation, which is why the permissive reading was
rejected even though it produces fewer diagnostics.

**Defect or generation: the test that decides it.** The question came up over
widening and is worth stating once, because every later chapter will meet it.
Ask whether the language *lacks* the facility or *has it inconsistently*.

- Annex H, a later generation: nothing in the language knows about the thing.
  Alternate bases (H-1) are absent everywhere; there is no rule for them to
  disagree with.
- Annex F, a defect: the rule exists and is applied elsewhere, and one path does
  not follow it. `1 + 1.5` is `2.5` and `'a' + 'bc'` is `abc`, so widening is
  settled behaviour — only the paths carrying a *written* type refuse it, which
  makes a declared type mean something narrower than the operators do.

⚠️ A useful secondary check: does the change only make more programs legal, or
does it change what an existing program *means*? The second kind needs more care
whichever annex it lands in. Widening at an assignment context is additive;
widening at `=` would reverse [LEX-026], which is why that half was held back
for the chapter that specifies `=`.

⚠️ Deciding [VAL-007] from chapter 5 reached **forward** into chapter 7, as
chapter 4 reached back into chapter 3 over `letter`. This keeps happening and is
not a sign of bad chapter order: the rules are a graph and the chapters are a
sequence. Both times the out-of-chapter rule was fully rewritten rather than
left for its own turn, because a half-decided rule is worse than an undecided
one.

**Where the first draft landed.** 19 chapters, 5 annexes, 248 rules, ~16,700
words, 133 probes. Every rule was verified by running the interpreter. The
checker verifies 318 file citations, 101 unit-test citations, the keyword table
against `Scanner.a24`, Annex A against the chapters, and Annex B against the
built-ins the interpreter registers.

⚠️ **248 of 248 rules still carry `conformance TBD`**, which is the plan working
rather than failing: probes are evidence, and evidence is not a commitment.

What the writing found, none of which was visible from reading:

- **5 compiler divergences** (Annex C), two of them **silent** — collection
  member names matched case-insensitively by the compiler and not the
  interpreter, and module bodies running at different times under the two.
- **18 behaviours that look like defects** (Annex D).
- Several false claims in the source itself, since corrected: `algol.h`
  asserting the C runtime's case-insensitive lookup was "what the interpreter
  does", and a stale comment claiming `Ord` returns a Double.
- Four citations to symbols that do not exist, each rejected by `spec.sh`
  before it could reach a commit.

⚠️ Phase 1 is the decision point. If the rule format, the voice or the
granularity is wrong, that should surface after a day rather than a week.

The testing work in §7 runs alongside, in this order and for these reasons:

1. **The harness**, because conformance and refusals share it and neither can
   start without it.
2. **The refusal corpus**, because the cases are the cheapest to write — one
   construct each — and carry the highest signal: front-end refusals must match
   across both processors, so the corpus is a conformance check from its first
   entry.
3. **The conformance corpus**, seeded from Annex D.
4. **Screen capture**, last of the four. It is the only one that changes the
   language's own behaviour rather than observing it, and the unit suite should
   be the thing that catches a mistake in it.

---

## 9. Open decisions

Settled:

- One file for the specification, Go-style. — *decided*
- Stable rule IDs over section numbers. — *decided*
- The interpreter is the authority; normative even when wrong. — *decided*
- Refusals are judged out of process, one case per file. — *decided*
- Conformance is standalone programs, not unit tests or extracted snippets.
  — *decided*
- One harness serving both corpora. — *decided*
- Screen output through a native accessor, not an implicit parameter to the
  test block. — *decided*
- `print` is being removed, so no corpus may depend on it. — *decided*

Still open:

- Whether the Tier 2 executable probes are in scope, or a later pass.
- Whether `spec.sh` gates CI or is merely runnable. There is no CI yet.
- Whether Annex D entries should carry a recommended disposition (fix / keep
  and document / defer), or only describe. A disposition is more useful and
  more opinionated.
- Whether a refusal case must pass on BOTH processors from the day it is
  written, or may be recorded as interpreted-only until the compiler catches
  up. The second is more practical and risks a corpus that quietly excuses the
  compiler.
- Whether the screen buffer is a `Buffer` reachable from Algol-24 or an opaque
  native. A `Buffer` brings `Free` and its poisoning rule into the test
  runner's lifetime, which is a larger surface than the feature needs.
- The sentinel form for transliterated colour. `[RED]` is the most readable and
  the most likely to collide with ordinary output; something like `‹RED›` or
  `<ESC:RED>` trades a little legibility for a collision that will never
  happen. The refuse-on-collision rule in §7.3 makes either safe, so this is a
  question of taste rather than correctness.
