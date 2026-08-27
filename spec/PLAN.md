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

Tiering, so this does not balloon:

- **Tier 1 (in scope from the start):** probes are written and run while
  drafting; their real output becomes the examples.
- **Tier 2 (later):** probes are kept in `spec/examples/`, and `spec.sh`
  re-runs them and asserts the recorded output still matches.

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

Each program is run under every processor and compared against the expected
output AND against the other processor. That second comparison is already known
to be sharp: it is how the full test report was shown identical across the two,
239 lines including colour.

⚠️ Write output with `WriteLn`, never `print` — `print` is being removed from
the language, and a corpus built on it would rot on the day it goes.

Seed the corpus from the Annex D entries. They are the highest-risk behaviours
and the ones a second implementation is likeliest to get wrong: `1 = 1.0` while
`1 in [1.0]` is false, a falsey Integer `0` beside a truthy `0.0`, a falsey
first enum member.

### 7.3 One harness, two directories

Conformance and refusal cases differ only in what is expected — a valid program
with expected stdout and status zero, against an invalid one with an expected
diagnostic and a non-zero status. Same runner, same `spec:` header, two
directories. Build it once.

### 7.4 Screen output in unit tests

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

## 8. Phasing

Realistically 15,000–25,000 words. Delivering it in one drop is how it gets
done badly.

| Phase | Content | Rough size |
| --- | --- | --- |
| 1 | Skeleton, ID scheme, `spec.sh`, and **two chapters done properly** — Lexical elements and Types — as the pattern to review | ~1 day |
| 2 | Core semantics: values, declarations, expressions, statements, functions | |
| 3 | Classes, enums, collections, modules, built-ins, initialization, errors, test blocks | |
| 4 | Annexes C and D in full; `spec.sh` swept over every rule; grammar summary | |

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
