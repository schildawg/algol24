# Plan: v0.2.4 — the defect sweep

**Status:** reproduced, not started. Written 2026-11-06, on branch
`defect-sweep`.

Fifteen open defects from two projects using the language:
`shroom-slots/DEFECTS.md` (R-1 … R-15, thirteen open) and
`algol24.com/DEFECTS-FOUND.md` (D-1, D-2). **Every one was re-reproduced
against this tree** before anything was written here, with the reproductions
kept; what follows is what the reproductions showed rather than what the
reports claimed, and in three places those differ.

The fifteen collapse to **eight root causes.** Four defects are one bug — and
working through them has turned up **two more** that neither report names: a
visible global losing to a field of `this` in the C back end (fixed with item 2)
and a built-in held as a value (item 11, open).

| | defect | root cause | processor at fault |
| --- | --- | --- | --- |
| **1** | R-6, R-7, R-9, R-11 | CEmitter resolves a bare name against a program-wide table | compiled only |
| **2** | R-1 | a built-in beats a field of `this` | interpreted only |
| **3** | R-3 | one `SourceCode` holds every file | all three |
| **4** | R-8, R-10 | the compiler knows and waits | all three |
| **5** | R-2, R-4 | a diagnostic that carries no location | all three |
| **6** | D-1 | a unit name is compared case-sensitively | all three |
| **7** | R-15 | the runtime pair carries no version | the emitted runtime |
| **8** | D-2 | `vm/REFERENCE.md` states a total its own body contradicts | documentation |
| **11** | *found here* | a built-in held as a value is a wrong answer, not a refusal | compiled only |

Two are not repairs and are handled as their own items at the end: **R-5** (a
runtime error carries no location) is a feature spanning three processors, and
**R-13** (the interpreter's memory) is now measured and is not what the report
supposed.

---

## What the reproductions corrected

Three claims in the incoming reports do not survive being run.

**R-2 is half fixed already.** The second repro — a class member named
`Object` — now answers `Expect method name.` *with* file, line, source and
caret. Only the `end;` half is still a bare sentence. The report, audited
2026-11-06, says it still reproduces verbatim; one of its two cases does not.

**R-11's "second half" is not a divergence, and the interpreter is right.** The
report says a unit's own `const Depth` called as `Depth ('x', 5)` resolves to
the integer interpreted, and that "neither back end picks the one the
language's own shadowing rule implies". Run here, the interpreter **and the
machine** both answer `Can only call functions and classes.` — two against one,
and a file's own declaration winning inside it is exactly the rule. So R-11 is
not two bugs with the language undecided between them; it is one CEmitter bug,
the same one as R-6, R-7 and R-9.

**R-13 is localised, and the report's hypothesis is disproven.** The report
supposes "interpreting now loads every unit in the directory rather than only
what `uses` names, so three large new units are being parsed and held". Measured
per unit, `--test` costs:

| unit | test blocks | maximum resident |
| --- | --- | --- |
| `json.a24` | 5 | 0.00 GB |
| `reels.a24` | 8 | 0.02 GB |
| `slotmath.a24` | 13 | **5.56 GB** |
| `machine.a24` | 26 | 5.89 GB |

It does not scale with units loaded or tests run. One unit accounts for all of
it, and the unit that imports it costs 6% more rather than twice as much. See
item 10.

---

## 1. CEmitter resolves a bare name against a program-wide table  ·  DONE

**Landed.** Four defects, one fix. `defects.sh` reports R-6, R-7, R-9 and R-11
fixed and **zero** error stubs in the emitted C across all four; the corpus is
green under both processors; the seed is a fixed point in one generation.

Two rules were written for it, because the behaviour the fix implements was
**unstated** and the two halves of it are different questions. [MOD-016] — a
file's own top-level declaration is resolved before its imports. [MOD-017] — a
top-level subprogram *visible in a file* is resolved before a member of a class
declared in that file, and one that is not visible does not enter the question.
`conformance/0211` and `0212` pin them, byte-identical under all three
processors, over six new fixtures in `conformance/modules/`.

**The real-world sightings were the convincing check, not the reductions.**
shroom-slots' two documented R-9 collisions, put back:

| | before | after |
| --- | --- | --- |
| a top-level `Measure` beside `uses text` | **8** stubs inside `text.c` | 0 |
| the `Word` / `json.a24` reduction | aborts, blaming the wrong file | `ab = true,  cd = 5` |

Those eight were latent aborts in `Font.DrawRight`, `Font.Wrap` and
`Font.DrawBlockMid` — a unit the program never edited.

**One claim in `CLAUDE.md` was wrong and is corrected.** It said a top-level
subprogram shadows another unit's class method and that both processors agree,
which overstates it: that holds only where the *class's own unit* can see the
subprogram. Measured both ways before the rule was written — `Crated`, which
imports `Sizer`, reaches `Sizer.Size` from inside its own method even at a
matching argument count, and all three processors answer `3` rather than `1000`.

**One adjacent case was probed and is NOT a fifth defect:** a callable held in
an imported unit's global, called bare, resolves correctly in both back ends.

---

**R-6, R-7, R-9 and R-11 are one bug.** It is the largest item here, it is the
only one that makes a program pay out a wrong answer (R-6), and the interpreter
and the machine agree against the C back end in all four.

`Emit` builds its declaration tables in a loop over every unit:

```
for var TheUnit in Units do
    CollectFunctions (TheUnit.Statements);      // CEmitter.a24:1020

for var TheUnit in Units do
    CollectGlobals (TheUnit.Statements);        // CEmitter.a24:1027
```

So `Declared`, `Globals`, `EnumMembers`, `EnumTypes`, `Classes` and `Objects`
each end up holding **every name every unit declares**, with nothing recording
which unit declared it. The per-unit visibility machinery already exists one
loop below — `UnitExports`, `UnitAll`, `ShadowNames`, `Visible`, `ImportOwner`
are all computed per unit — and the resolution paths do not consult it.

Two consequences, and each is two of the four defects:

**A name declared in any unit is treated as visible in every unit.** The bare
call path reads

```
if CurrentClass <> '' and not Declared.Contains (Name)
                      and VisibleMethods.Contains (FoldCase (Name)) then
    Exit Invoking (ThisRef (), Name, Arguments, ...);     // CEmitter.a24:3799

if Declared.Contains (Name) and not ShadowNames.Contains (Name) then
    Exit '(alg_error(' + QuoteC (MissingName (Name)) + '), alg_nil())';
```

`Declared` holding another unit's `Size` is enough to skip the implicit-`this`
invoke and fall into the error stub — **inside the blameless unit's own `.c`**,
naming the wrong unit as the one that should have been imported. That is R-9,
and R-11 is the same shape with a `const` in place of a method.

**An imported declaration beats the file's own variable.** `VisitVariableExpr`
consults `EnumMembers` and `Declared` before it ever reaches `Globals`:

```
if EnumMembers.Contains (Name) then Exit EnumMemberName (...);   // R-6
...
if Declared.Contains (Name) then Exit SubprogramValue (Name);    // R-7, R-11
...
Exit Guarded (Name, VariableName (Name));                        // never reached
```

R-6 is the worst of the fifteen because of where that lands: the enum member
is emitted in place of the variable, so every assignment to it is discarded
in silence and the name is permanently truthy. In shroom-slots it meant a game
that paid out every win and charged for no spin, with the balance climbing from
5,000 to 196,576 and nothing warning.

### The resolution order, taken from the two processors that agree

Not invented here. Each line is what the interpreter and the machine both do,
confirmed by a reproduction:

1. a local, then a capture
2. **the file's own top-level declaration** — `var`, `const`, subprogram, class,
   enumeration (R-6, R-7, R-11)
3. a member of `this` (R-9; and item 2 below)
4. **a name its own `uses` makes visible**, and nothing wider (R-9)
5. a built-in

### The fix

Key the declaration tables by unit, as the member tables were keyed `unit:class`
for the VM emitter after the same class of bug cost an afternoon there. The flat
sets stay for the questions that are genuinely program-wide (`MissingName` asks
"does any unit export this", and should); resolution moves to the per-unit ones.

**Three traps this repository has already recorded and this change walks into
all three.** Every key folds [SRC-011], and folding the writes while missing one
read is what `fixedpoint.sh` caught last time. The root file's unit name is the
**empty string**, so `''` cannot double as "no unit" — the VM emitter's own note
says so. And a per-unit table must be consulted through one function, not
inlined at each of the six sites, or the next read added will be the one that
does not fold.

### Checking it

Four conformance cases, one per defect, each pinning the product of two features
the corpus tests separately — which is precisely the gap all four hid in. The
reproductions are already written; they become cases under [MOD-005] and
[SRC-010].

A fifth check is worth more than any of them: **a program-wide grep of the
emitted C for `alg_error("Undefined`**. shroom-slots' `build.sh` added exactly
that after R-9 cost it an afternoon, and on first run it found three latent
aborts nobody had reached. That belongs in `conform.sh`, not in every project's
build script.

---

## 2. A built-in beats a field of `this`  ·  DONE

**Landed, and it was two defects rather than one.** Probing R-1's edges turned
up a second divergence of the same shape — the **opposite** processor was the
odd one out — and a third that is new work and is now item 11.

The resolution order is written down as **[CLS-019]** and `conformance/0213`
pins it, byte-identical under all three. Every step of it was measured rather
than assumed:

| a bare name inside a method | interpreted | machine | compiled | fixed |
| --- | --- | --- | --- | --- |
| a field named after a **built-in** | `<fn Pos>` | field | field | the **interpreter** |
| a visible **global** named after a field | global | global | **field** | the **C back end** |
| a **method** named after a built-in | built-in | built-in | *cannot* | item 11 |

**The second one was not in either report.** Only a LOCAL was tested for before
the C emitter answered a field, so a declared global named after a field read as
the field inside the class's own methods — and an *imported* global did too. The
guard is `VisibleGlobal`, and it went on the write as well as the read: a write
that disagreed with the read would be worse than either.

**The first fix was too wide at first, and the probe is what caught it.**
Routing the built-in tiebreak through `ObjInstance.Get` made a bare name answer
a *method* of that name, because `Get` answers ClassName and bound methods as
well as fields — so the interpreter started answering `99` where the machine
answers the built-in's arity complaint. A new divergence introduced by the fix
for one. `GetField` is the narrow accessor, and [CLS-007] is why it is the right
one: a bare name read without parentheses is a **field** read, so a method of
the name is reached by `this.M` or by a call and never bare.

---

**R-1**, and the interpreter is the odd one out — confirmed two against one:

```
                     interpreted   compiled   machine
bare name in method   <fn Pos>        42         42
```

A field named after a built-in is reachable as `this.Pos` and from outside the
class, and not by the bare name inside it. The interpreter looks a bare name up
as a variable and reaches for `this` only when that *raises*; a built-in is a
name in the environment every file encloses, so the lookup succeeds and
`ThisField` is never reached.

The machine already decides this statically and its order is the one to copy:
not a local, not a capture, **not a visible global**, and a member of the class
being compiled. So a program-declared global still beats a field — which is the
documented behaviour and must not change — while a built-in does not.

It bites rather than annoys because nothing fails at the point of confusion: the
method answers a function value and the program dies later in unrelated
arithmetic, with R-5's locationless message. The 33 built-in names include
`Pos`, `Length`, `Copy`, `Str`, `Val`, `Write`, `Set`, `Map`, `List` and
`Buffer`, all of them plausible field names.

---

## 3. One `SourceCode` holds every file  ·  DONE

**Landed, and it was smaller than this plan estimated.** `SourceCode` holds a
**Map of file to lines** instead of one list and one name; `Token` gained
`File : String := ''`; `Scanner` gained a two-argument constructor that names
the file it is scanning; `Console.Error` reads the token's file. Both directions
now answer correctly:

| the error is in | before | after |
| --- | --- | --- |
| the imported unit | the **program**'s name, the unit's text | `badunit.a24`, its own line 4 |
| the program | its name, the **unit's** text | `r3b.a24`, its own line 3 |

**What made it small was that tokens are made in ONE place.** 38 sites construct
a `Token` in `Scanner.a24`, but every one of them goes through `AddToken` — so
the stamp is three lines, counting the EOF token made separately. `Offset` had
already set the precedent for an additive field with a default, so the
one-argument constructor stays for the unit tests, which scan a string that is
no file at all.

**Blast radius was ONE case, and the measurement that said zero was broken.**
41 recorded cases print an `[ERROR]` line naming a file; exactly one of them —
`refusals/0029-unit-name-must-match-the-file` — imports a module, and it
recorded the *program's* name over the module's line 4. The corpus caught it.

⚠️ **The first measurement reported zero because every path it tested was
malformed.** A `grep -n` left the line number glued to each path —
`11159refusals/0029-…` — so the `[ -f ]` guard skipped all 41 files, the counter
stayed at 0, and the answer looked like a finding. A loop that tests files and
finds none should say so; this one said "0 importing a module", which is what a
real zero looks like. **Make an existence check print what it skipped.**

That near-miss is the same shape as R-3 itself: the corpus has located-error
cases and module cases and had almost none of their *product* — one, which is
what makes this the fourth time this repository has recorded that sentence.

`refusals/0199` is the new case, and what it pinned before the fix is the
sharpest statement of the defect: the diagnostic named a **three-line program**
and quoted **line 12**.

⚠️ **The first version of this regressed the MACHINE in 36 cases, and it was
the same trap in a new coat.** `SourceCode.Get` resolved an empty file name to
the root; `SourceCode.Add` did not. A scanner given no file name therefore
STORED its lines under `''` and they were LOOKED UP under the root's name, so
every located diagnostic lost its source line — and `vm/run.a24` is exactly
that caller, naming its file to `Begins` and not to the `Scanner`. `conform.sh`
was green throughout, because the compiler's own drivers all name the file;
`vm/conform.sh` is what went red.

One `Keyed` function now answers it for the write, the read **and** the printed
name, which is the only arrangement in which they cannot disagree — and
`vm/run.a24` names its file to the Scanner as well. The lesson is already in
`CLAUDE.md` about folding a table's keys: *folding the writes and five of six
reads* is the shape, and resolving a key on the read alone is the same mistake.

**The test report is untouched, and deliberately so.** It names the root file
[CLAUDE.md, `TestReport.RootFile`] and prints exactly one `[ERROR]` line, going
nowhere near `Console.Error` — checked by failing a test inside an imported unit
rather than assumed.

---

**R-3**, and the cause is in the unit's own doc comment:

> It holds one file at a time, which is why a diagnostic names the ROOT file
> rather than the file the line lives in.

`Main` calls `SourceCode.Begins (FileName)` for the root. The Parser then loads
each imported file and its scanner calls `SourceCode.Add` — which **overwrites
lines in place** and never renames. So the name is the root's and the text is
whichever file last wrote that line number. Both directions reproduce:

| the error is in | name printed | text printed |
| --- | --- | --- |
| the imported unit | the **program** | the unit's line — right text, wrong name |
| the program | the program | the **unit's** line — right name, wrong text |

Either way the reader is sent to an innocent line in the wrong file, which is
where the search starts. It has cost shroom-slots "a minute each time" by its
own account, repeatedly, and it is the reason R-8's sighting quotes an
`external` declaration that has nothing wrong with it.

**The fix.** `Token` gains a file; `SourceCode` holds a record per file rather
than one; `Console.Error` reads the token's file instead of the singleton's.
`Token.Offset` is already a field with a default, so `File : String := ''` is
additive and the constructor keeps its arity — but this is a change to the seed
and wants its reseed checked before anything leans on it.

⚠️ The two processors' reports are **compared line for line**, so the compiled
test runner has to learn the same thing in the same commit or `conform.sh` goes
red for the fix rather than the bug.

---

## 4. The compiler knows and waits  ·  DONE

**Landed as two warnings.** `ERR-010` now documents five, and `spec/spec.sh`
holds every one of them to what is printed.

**R-10** needed almost no new machinery: `CandidatesFor` already knew which
declarations take a given count, variadics included. It fires on shroom-slots'
own historical mistake, reproduced by dropping an argument from their `Glitter`
call — the one their report says was *caught by reading the signature out of
curiosity, not by any check*:

```
[WARN] machine.a24:6937: 'Glitter' is called with 6 argument(s), which no declaration of it takes.
```

**R-8** went in `CEmitter`, where the knowledge already was. Its real sighting:

```
[WARN] lobby.a24:5: Undefined variable 'LoadTexture'. Unit 'image' exports it; this file has no 'uses' for it.
```

Only the moment was ever wrong — `MissingName` had already searched for the
exporting unit in order to word that sentence.

⚠️ **TWO FALSE POSITIVES, both found by measuring and neither by reasoning.**
Each would have cost the reader's trust in all five warnings.

`ObjFunction.Fits` is a **method** called by its bare name, and `vm/Vm.a24`
declares a top-level `Fits` — a pair `CLAUDE.md` records as measuring clean.
The warning compared the call against the wrong declaration entirely, because
`Overloads` knows only top-level names. Which of the two a bare call reaches is
decided by **visibility** [MOD-017], a per-file question the checker does not
answer, so it now declines to guess about any name the enclosing class declares.

`testing.a24` calls the built-in `Fail` where `harness` also exports one, so
the *missing-uses* site fired **before** the assertion exemption and warned
about a name used legitimately. The exemption moved into the one helper every
site passes through.

**Clean across everything measurable**: the compiler, the VM, shroom-slots'
twelve programs and the library's twelve units raise **zero** warnings between
them — and none of the unrefusable shapes warns: gathering, both overloads, a
held subprogram, and a declared built-in name at its own count *and* at the
built-in's [RT-027].

⚠️ **The fifth warning needed a second fixture.** It is raised while **emitting
C**, so an interpreted run cannot provoke it however the program is written;
`spec/warning-emitted.a24` is compiled rather than run, and `spec/spec.sh`
appends that run's warnings to the first fixture's. Seen red by shifting a line.

**Two smaller things.** `FoldedBuiltins` had to be declared **above** the `var`
whose initializer calls it — hoisting notwithstanding, it answered
`Undefined variable` at unit-init time. And `CEmitter` needed `uses Console`
and `uses SourceCode`; it had used neither before.

---

**The shape is settled and it is a `[WARN]`, not a refusal** — decided on two
facts rather than in advance.

[DCL-007] makes a free name in a body resolve **when the body runs**, so a name
nothing declares, used on a path that never runs, is a program the language
permits today. Refusing it would make a class of working programs illegal,
which is a language change and not a defect fix. The same is true of R-10: the
call is reached or it is not. So what is wanted is the cost made **visible**,
not forbidden — which is this repository's stated preference wherever a
construct is legal and carries a hidden cost.

⚠️ **And a `[WARN]` cannot break the corpus, which was checked rather than
hoped.** `conform.sh`'s `render()` already drops `[WARN]` lines from BOTH
sides, with the reason written beside it: a warning is a diagnostic *about* a
program rather than output *of* it, and the two processors raise it at different
moments precisely because the front end is shared. Without that, a warning on
any wrong-arity call would have diverged every case that has one — `0049` among
them.

So the work is: both warnings in the **shared front end**, so all three
processors raise them alike; `ERR-010` and `spec/warning.a24` gain an entry
each, which `CLAUDE.md` says is the whole of adding one.

### What measuring this found first

⚠️ **A NEW DEFECT, and a worse one than either R-8 or R-10: every built-in's
name was case-sensitive in the C back end.** Found by asking whether a refusal
would be safe — the emitted `alg_error("Undefined` stubs *are* that
measurement, and the library had one that nothing accounted for.

`Builtin (Name, Count)` compared `Name + '/' + Count` against the canonical
spellings as literals, with no folding, where a built-in's name is an
identifier and identifiers fold [SRC-011]. Eleven of eleven spellings tried
became stubs that compile, link, pass every gate and abort when the line runs:

```
writeln  WRITELN  STR  length  copy  POS  toupper  ord  CHAR  succ  Clock
```

**It bit unevenly, which is why it lasted.** A built-in whose canonical
spelling is the one people write never missed, and `clock` is the only one
spelt lower-case — so writing the natural `Clock` was enough.
`algol24-library`'s `graph.a24` had exactly that, waiting for a caller.

The fix is `FoldCase` on the key plus its thirty-one literals, as
`IsAssertion` already did; every caller routes through `Builtin`, so one point
covers all of them. `conformance/0215` pins it.

**It was also the prerequisite.** Stub counts before and after, which is what
makes a diagnostic here safe to attempt rather than a guess:

| | before | after |
| --- | --- | --- |
| the compiler's own self-compile | 0 | 0 |
| shroom-slots' five programs | 0 | 0 |
| the library's twelve units | 9 | **6** |

The six are all `Fail` — an assertion outside `--test`, which is the documented
exemption. So every real program now carries only that.

---

**R-8 and R-10.** Both are facts the compiler holds while compiling and reports
when the line runs, so both survive every gate and reach a person — or, in
shroom-slots' case, an Android device with no console, where the language's
good message is written to a stream nobody is reading and the player sees the
app vanish.

**R-8 — a name nothing declares.** The emitted C already carries

```c
alg_error("Undefined variable 'Helper'. Unit 'image' exports it; this file has no 'uses' for it.")
```

which is the best message in the language and arrives at the worst time. Every
fact in it was known at emit time: `MissingName` searched `UnitExports` to word
it. Reporting it as a refusal costs nothing and turns a fault that needs the
right code path exercised into one that cannot be committed. `IsAssertion`
outside `--test` emits a stub deliberately and must stay exempt.

**R-10 — a call whose argument count matches no declared arity.** Interpreted,
compiled and on the machine alike: `Three (1, 2)` compiles, links, passes every
gate and dies when reached. It cost shroom-slots a shipped program that could
not start at all, for however long the signature had had twelve parameters,
because the one call site sits past a `Halt` the unattended gate returns before.

This one must be **narrow or it is wrong.** Overload selection is at run time
[EXP-013] and no annotation changes that, so a compile-time count check is sound
only where the callee resolves to exactly one visible declaration, that
declaration gathers nothing [FUN-005], and the count matches none of its
arities. A call through a variable, a built-in, an overload set or a gathering
parameter is not refusable and must pass through untouched.

Both want a `[WARN]` rather than a refusal if the narrow form still refuses a
program that works — the repository's own preference where a construct is legal
but carries a hidden cost. R-8's is not legal and should refuse; R-10's narrow
case is not legal either. Decide on the measurement, not in advance.

---

## 5. A diagnostic that carries no location  ·  DONE

**Landed. R-2 was a defect against a rule already written**, which is why it
wanted a case rather than a rule: [ERR-005] says a parse error prints the
message and a three-line excerpt naming the file, the line and the offending
token, and `Expect expression!` was the one instance that did not. A rule
holding for all but one of its instances is how that one survived, so
`conformance/0214` pins it beside `0100`.

The caret lands on the offending token — `end;` reports at the `;`, which is
the thing that is wrong.

**R-4 gets no conformance case, deliberately.** It is a *driver* diagnostic
about a command line rather than a property of a program, and the corpus runs
programs. `defects.sh` checks it instead. There is no portable directory test
to ask before writing — `FileExists` opens the path, and `fopen` on a directory
succeeds on macOS and Linux and fails on Windows, which is the defect
`installed.sh` exists to guard — so the failure is **caught and named** rather
than predicted:

```console
$ algc --compile --out=nodir p.a24
Uncaught: algc: cannot write into 'nodir'. Does the directory exist?
```

---

**R-2** is one line. `Expect expression!` is the only parse error raised bare:

```
raise 'Expect expression!';                      // Parser.a24:2447
```

Every other goes through `Error (TheToken, Message)`, which calls
`Console.Error` and answers the message to be raised. `raise Error (Peek (),
'Expect expression!')` raises the identical value, so the test at Parser.a24:2639
still passes, and the location arrives. It is the most likely typo in a
Pascal-shaped language — a semicolon after `end` — and it currently reports
nothing but the sentence.

**R-4** is a message naming a symptom. `--compile --out=nodir` answers
`Rewrite failed: cannot open 'nodir/ok.h'.`, which sends the reader after a
permission or a name problem rather than a missing `mkdir`. There is no portable
directory test — `FileExists` opens the path, and `fopen` on a directory
succeeds on macOS and Linux and fails on Windows, which is the defect
`installed.sh` exists to guard — so the honest fix is to catch the first write's
failure and name the directory: `algc: the output directory 'nodir' does not
exist.`

---

## 6. A unit name is compared case-sensitively  ·  DONE

**Landed as the split, and the decision turned on a measurement that reversed
the premise.**

⚠️ **macOS is the case-INSENSITIVE one; Linux is the outlier.** Writing
`unit.a24` beside `Unit.a24` on this machine's APFS **overwrote** it — one
file, the first spelling kept, the second write's contents. So the two files
cannot both exist here, which is why D-1's reproduction needs two directories.
macOS and Windows fold; only Linux distinguishes. (APFS can be formatted
case-sensitive, so even one platform is not uniform.)

That settles what the fix had to be: **fold everything the language owns, and
leave the filesystem what the language does not.**

- **The language owns** the unit registry and the file a back end names after a
  unit. Two units whose names fold together are one name declared twice, and
  the program is refused — **identically on all three processors**, which is
  [MOD-018] and `refusals/0200`.
- **The filesystem owns** whether `uses alpha;` *finds* `Alpha.a24`.
  [MOD-002] has always said so, and now says which half it is talking about.

**The refusal is in the PARSER, not in a back end.** `CEmitter`'s existing
`Two modules named 'X'` is a C-back-end refusal, so folding that alone would
have left the interpreter running the program and the machine answering
`Undefined variable`. `ClaimUnit` records each loaded file's folded stem as it
is first read, which is the one place all three processors pass through. The
root claims its name too: nothing can import the root, but a back end names a
file after it like any other.

**The diagnostic names the two paths and no unit name**, because neither file's
spelling is the name of the clash and the folded spelling is one no file wrote
[SRC-011].

**`PROPOSAL-DIRECTORY-LISTING.md` carries what this does NOT do.** Folding the
*lookup* needs the language to enumerate a directory, and [RT-026] gives it no
way to. `algol24-library` has one — `class Directory` and `Entries`, Turbo
Pascal's `FindFirst`/`FindNext` as an object — but behind **three `external`
declarations**, which the module loader cannot reach: it is in the seed, `algc`
builds without `--ffi` [INI-008], and the library is a separate repository. So
the capability exists in the language and is unreachable from the one place
that would make [MOD-002] platform-independent. That asymmetry is the
proposal's argument, and the C for it is already written and tested in
`fileffi.c`.

---

**D-1**, and the refusal it needs already exists:

```
if Seen.Contains (Str (TheUnit.Name)) then
    Unsupported ('Two modules named ''' + Str (TheUnit.Name) + '''');   // CEmitter.a24:1013
```

A unit name is an identifier and identifiers fold [SRC-011], so `Alpha` and
`alpha` **are one name** — and that comparison is the one place in the compiler
that does not know it. Two units differing only in case slip past a refusal
written to catch them, and then:

| | |
| --- | --- |
| interpreted | prints both lines |
| `algvm` | `Uncaught: Undefined variable 'FromLower'.` |
| compiled | one `.c` for two units; `Main.c` calls `f_fromupper`, `Alpha.c` holds `f_fromlower`, `cc` stops |

Folding that comparison refuses the program in all three, which the report
itself calls the defensible answer and better than either present behaviour.
The Parser's `Loaded` map is keyed by **path**, not by name, so it needs the
same fold for `algvm`'s half.

⚠️ **This is NOT simply a rule already carried, and the plan said so before
reading [MOD-002].** That rule states outright that a module name is *the one
place [SRC-011] does **not** reach* — the filesystem decides how it is matched,
case-insensitively on macOS and Windows and **sensitively on Linux**. So on
Linux `Alpha` and `alpha` are two legitimately distinct units, each satisfying
[MOD-004] against its own file name, and a program may legitimately use both.
Folding the comparison would refuse a program that is **legal on Linux** in
order to fix one that is broken on macOS.

So item 6 is a decision and not just an edit, and it should be taken
deliberately:

| | what it does | cost |
| --- | --- | --- |
| **fold the comparison** | refuses the program under all three, everywhere | refuses a program Linux allows; [MOD-002] has to gain a sentence saying the registry folds where the *lookup* does not |
| **fix the mechanisms** | C filename from the unit's **path** rather than its name; the machine's registry keyed by path, as the Parser's `Loaded` map already is | keeps both units working wherever the filesystem does, but gives no diagnostic — and a case-insensitive filesystem still cannot hold the two `.c` files, so the compiled half needs the path-derived name regardless |
| **both** | mechanisms fixed, and a `[WARN]` where two unit names fold together | the most work, and the only one that is right on both platforms |

**Recommended: both.** The path-derived output filename is needed anyway — it
is the only thing that makes the compiled half work on a case-sensitive
filesystem — and a `[WARN]` is this repository's stated preference where a
construct is legal but carries a hidden cost. What is NOT defensible is the
present state, where the refusal that exists was written to catch exactly this
and misses it.

What does still hold from the first reading: [MOD-002] is about *finding* a unit
by name, and both units here are found by explicit path. What goes wrong
afterwards is a registry and an output filename, both of which the language
owns.

---

## 7. The runtime pair carries no version  ·  DONE

**Landed, and the check was seen red in all three directions before being
trusted.** `ALG_RUNTIME_VERSION 203` in `algol.h`, a `_Static_assert` in
`algol.c`, and a `spec/spec.sh` section holding both to `compiler/Release.a24`.

A mismatched pair now gives **one** error naming the real fault where it gave
twenty naming symptoms:

```console
algol.c:6:1: error: static assertion failed due to requirement '106 == 203':
             algol.c and algol.h are from different releases
```

Bumping any one of the three alone turns the gate red, each with its own
message — `Release.a24 is 0.2.4 (= 204) and algol.h says 203`, and so on. That
was checked by doing it, because a green check nobody has seen go red proves
nothing.

⚠️ **The version is 203 and not 204: `Release.a24` still says 0.2.3.** The
release bump belongs to the release, and the gate now makes it a three-file
change — which is the point, since a version in two places with nothing
comparing them is what `Release.a24` was created to end.

---

**R-15.** `--compile` emits `algol.c` and `algol.h` together and they are a
pair; nothing records which release either came from, and nothing notices when
they disagree. Anything assembling a build from both the compiler's output and
the compiler's source tree can pick up one of each — which shroom-slots'
`make-android.sh` did, and got twenty `cc` errors reading as a corrupt runtime:

```
gen/algol.c:3377:20: error: call to undeclared function 'alg_collect'
gen/algol.c:3390:61: error: no member named 'marked' in 'Obj'
```

A v0.2.3 body against a 0.1.6 header. Nothing in those twenty errors says *two
versions*.

**The fix is two lines**, and the version already exists in one place:
`compiler/Release.a24` holds `const VERSION := '0.2.3'`.

```c
/* algol.h */   #define ALG_RUNTIME_VERSION 20204
/* algol.c */   _Static_assert (ALG_RUNTIME_VERSION == 20204,
                                "algol.c and algol.h are from different releases");
```

⚠️ Both files are **hand-written and copied verbatim** by `--compile`, so
nothing derives that number from `Release.a24` and it will drift. A line in
`spec/spec.sh` holding the three together is the half that makes it stay true —
without it this is a third place to bump by hand, which is the problem
`Release.a24` was created to end.

It would also catch a stale `gen/` left by an earlier compiler, which is the
other way to arrive here.

---

## 8. `vm/REFERENCE.md` states a total its own body contradicts  ·  DONE

**Landed, and the fix was to DELETE the figure rather than correct it.** A
number in prose is a claim nothing checks, and this repository's own `OP_LONG`
rationale once carried a stale nineteen-for-twenty-four in three files at once.
So the three stale sentences now say *every opcode*, *a file of hand-written
encodings* and *all but eleven*, and a note at the head says why no count is
written there.

**`./vm/reference.sh` prints the figure, having counted it** — and the report is
now a total with a breakdown under it rather than two lines that happen to sum
to one:

```
opcodes declared by OpCode.a24 : 80
  entries agreeing with it     : 79
  variable-width, shape not compared : 1
  no entry yet                 : 0
```

⚠️ **The three parts are DISJOINT, which is exactly why they were misread.** A
variable-width entry `continue`s before the agreeing count increments, so
nothing on the page told a reader whether the lines were parts of a whole or
alternatives to it — and taking the first for the total is how 79 nearly
reached the website. The script now **asserts that the parts sum to the
total**, which was seen red by dropping one of them.

`defects.sh` checks for the absence of a count rather than the presence of the
right one, since stating it correctly today is what went stale before.

---

**D-2**, in the one document whose stated discipline is that it never argues
with `OpCode.a24`. The file says **78 opcodes** twice; `OpCode.a24` declares 81
`const OP_`, the last being the `OP_COUNT` sentinel, so there are **80** — and
the reference carries exactly 80 `## OP_` entries. Its body is right and its
opening sentence is wrong.

`./vm/reference.sh` reports it in two lines easy to read as one:

```
described       : 79
variable-width  : 1
```

which sum to 80, and taking the first for the total is how this nearly reached
the website as 79. Fix both sentences, and have the script print one
unambiguous total.

⚠️ **No count belongs in prose that nothing checks** — this repository's own
`OP_LONG` rationale carried a stale nineteen-for-twenty-four in three files at
once. The sentence should say what the number is *for* and let the script carry
the figure.

---

## 9. R-5 — a runtime error carries no location

Not a repair. A runtime error prints one sentence and nothing else:

```console
$ algc rt2.a24
Uncaught: Operands must be numbers.
before
```

No file, no line, no call stack, in all three processors — so it is not a
divergence, and it is the whole of what a program gets when it fails. It
compounds with every silent defect above, because each of their symptoms *is* a
runtime error at a distance: R-1's field becomes a function value and the
program dies later in unrelated arithmetic with exactly this message.

**Two halves, and they are very different sizes.**

The ordering half is cheap and real: `before` is printed by the program before
the failure and appears after it, because the message goes to stderr and the
output to stdout unflushed. Flushing stdout before writing a diagnostic fixes it.

The location half is a feature. A runtime error would have to carry the
statement it happened in, through three processors, with the reports still
byte-identical — the interpreter tracking the executing statement's token, the
C back end emitting a line per statement, and the machine mapping bytecode back
to source. That is a release of its own, and it is the single largest
improvement available to anyone using the language.

**Proposed:** take the ordering half now, and write `PROPOSAL-RUNTIME-LOCATION.md`
for the rest rather than starting it inside a defect sweep.

---

## 10. R-13 — the interpreter's memory

Not a repair either, and the report's hypothesis is disproven. Measured above:
one unit accounts for 5.56 GB of a 5.89 GB run, and the unit importing it costs
6% more rather than twice as much. Nothing is being loaded that `uses` did not
name.

What it is, is the thing `CLAUDE.md` and [RT-029] already state: **the
interpreter has no collector and conformantly cannot.** Its live values sit in
C locals all through a recursive evaluator, where no collector can see them, so
`Collect ()` answers 0 and releasing would free something still in use. The
compiled back end and the machine both have precise roots and reclaim; the
interpreter's arena only grows. A unit whose tests churn collections — slot math
over 25 machines — therefore costs whatever it allocates, once.

So R-13 is a **limit with a measured cause**, not a leak. Three honest answers:

1. **Record it and close it.** The measurement replaces the report's hypothesis,
   and `verify-c`/`harness-c` are what gate shroom-slots anyway.
2. **Give the interpreter precise roots.** The shadow stack `CEmitter` emits for
   locals is exactly the missing piece, and the recursive evaluator is exactly
   why it is hard. A release of its own.
3. **Say so where a user meets it.** An interpreted run past some footprint
   could `[WARN]` that the interpreter does not collect and name the compiled
   back end. Cheap, and it turns a mystery into a known cost.

**Recommended: 1 and 3.** 2 belongs in a proposal beside item 9, and the two
share a cause — the recursive evaluator holding values where nothing can see
them.

---

## 11. The C back end cannot hold a built-in as a value  ·  DONE

**Landed, and the design mirrors the interpreter rather than inventing one.** A
held built-in is a closure of **arity -1** — which is exactly
`Native ('Str', -1)`, the interpreter's own convention for a variadic built-in.
`alg_call` skips its arity check for -1 and the thunk checks for itself.

⚠️ **Gathering was tried first and is WRONG.** A `types` of `List of Any` makes
`should_absorb` gather any count — but a gathered list and a single `List`
argument arrive identically, so the thunk could not tell `Str ([1, 2])` from
`Str (1, 2)`.

**Two small runtime helpers.** `alg_builtin(name, fn, arity, types)` interns by
name — required and not an optimisation, since these compare by identity
[VAL-011] — and it interns in the **runtime** so identity holds **across
units**: a static per generated unit would make `Length` read in one unit a
different object from one read in another, where the interpreter keeps a single
native per name in the scope every file encloses. And `alg_arity_counts`,
because `alg_arity` knows one expected count and an overload set answers
`No matching signature for function.` — right for a subprogram, wrong here
where the fault is the count alone.

**Three things the tests caught that reading would not have.**

`alg_writeln`, `alg_write` and `alg_halt` return **void** in C where they answer
nil in the language, so a thunk calls them and answers nil itself.

`BuiltinThunks` was not reset per unit, so the first unit emitted `bq_length`
and every later unit referenced it undeclared — `use of undeclared identifier
bq_length`. Found by the cross-unit interning test, which is the test that only
exists because interning had to be proven across units.

`RuntimeFolder` picked up a **stale `algol.h`** left beside a scratchpad binary.
Mine to clean up, but worth recording: `--compile` copies the runtime from
beside the binary FIRST, so a scratch binary with an old pair next to it
compiles against the old pair.

⚠️ **ONE THING IS REASONED AND NOT VERIFIED, and this says so rather than
claiming it.** The interned table is a C static holding `Value`s, invisible to
the collector, so it is marked in `alg_collect` — and `OBJ_CLOSURE` is both
marked and recycled by size class, so the marking is necessary by construction.
But **no probe would go red with the marking removed**: the released body is
never handed back at its own size class in anything that could be constructed —
Lists are the wrong band, and churning closures through a nested subprogram did
not reuse that block either. By this project's own standard a green collector
result proves nothing until it has been seen red, so the marking stays because
it is correct and free, not because a test holds it.

**Verified, all three byte-identical**: `Length`, `Copy`, `Str` at one, two and
three arities, `WriteLn` joining any count, `Length = Length` true and
`Length = Copy` false, interning across units, every arity complaint word for
word, and [RT-027]'s split — a declared `Length (A, B)` answers at two
arguments while the built-in keeps one. `conformance/0216` pins it under
[FUN-011].

**Clean on the real programs**: shroom-slots' five and the library's twelve
raise zero warnings and carry only the six `Fail` stubs the assertion exemption
accounts for.

---

**New, found by probing item 2's edges.** Not in either incoming report, and
not a reported shape of any of the fifteen.

[FUN-011] makes a subprogram's name without parentheses a value, and [RT-001]'s
built-ins are names like any other. Both other processors do it; the C back end
raises, with no class in sight:

```algol24
var F := Length;
WriteLn (F ('abc'));
WriteLn (Str (Length = Length));
```

| | |
| --- | --- |
| interpreted | `3` then `true` |
| machine | `3` then `true` |
| compiled | `Uncaught: Undefined variable 'Length'.` |

**It is a wrong answer where the C back end's own rule is to refuse by name.**
`CEmitter`'s bare-name path has no arm for a built-in held as a value — the
built-ins are reached only at a *call* — so the name falls through to
`MissingName` and an `alg_error` stub. A program that holds one therefore
compiles, links, and fails when the line runs: the same shape as R-8 and R-10,
in a construct the specification plainly allows.

**The machine already shows the way, and the note is in `CLAUDE.md`:** a
built-in held as a value is a **constant**, not an opcode — `VmBuiltin` carries
the name and `CallValue` sends it to the same dispatch `OP_BUILTIN` reaches, so
`var F := Length; F ('abc')` **is** host `Length` rather than a second one that
must agree with it forever. It must also be **interned**, or `Length = Length`
is false, since these compare by identity [VAL-011]. The C back end needs the
same two properties: one value per built-in name, reaching `alg_*` by that name.

⚠️ **Its first visible symptom was inside [CLS-019]'s own case**, which is why
`conformance/0213` pins the receiver spelling and not the bare one. A case
comparing the bare spelling of a method named after a built-in would be red for
this gap rather than for the rule it is meant to pin.

---

## Order of work

Grouped so each step can be gated before the next, and the seed changes come
late:

| | item | why here |
| --- | --- | --- |
| 1 | ~~**1** — CEmitter's per-unit tables~~ **DONE** | four defects, one fix, and the only silent wrong answer |
| 2 | ~~**2** — field of `this` beats a built-in~~ **DONE** | the other divergence; small, and R-5's worst symptom |
| 3 | ~~**6** — two units differing only in case~~ **DONE** | a DECISION, not an edit: see the table in item 6 |
| 4 | ~~**5** — R-2's one line, R-4's message~~ **DONE** | smallest things here |
| 5 | ~~**7** — the runtime pair's version~~ **DONE** | two lines plus the harness line that keeps it true |
| 6 | ~~**8** — the reference's total~~ **DONE** | documentation, and the script that holds it |
| 7 | ~~**4** — R-8 and R-10 at compile time~~ **DONE** | changes what the compiler accepts; wants the corpus green first |
| 8 | ~~**3** — `Token` gains a file~~ **DONE** | touches the seed and both processors' reports |
| 9 | ~~**11** — a built-in held as a value~~ **DONE** | found by this sweep, not reported; the C back end gives a wrong answer where its own rule is to refuse |
| 10 | **9**, **10** — R-5's flush; R-13 recorded | the two that are not repairs |

**Every item lands with its conformance case**, written into
`spec/ALGOL-24.md` under the rule it pins — not into `conformance/`, which is
generated and would eat it. The gate for the release is the seven harnesses plus
the three machine gates, with `fixedpoint.sh` given the iterations it needs: two
of these items change the seed.

**What the corpus could not catch, and why it keeps happening.** Of the eight
root causes, five hid in the *product* of two features the corpus tests
separately — inheritance and modules, a class and an import, a unit and the
program that links it. That is the fifth time this repository has recorded that
sentence. Each case written for this release should be a product, not a feature.
