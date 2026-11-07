# Plan: v0.2.4 — the defect sweep

**Status:** reproduced, not started. Written 2026-11-06, on branch
`defect-sweep`.

Fifteen open defects from two projects using the language:
`shroom-slots/DEFECTS.md` (R-1 … R-15, thirteen open) and
`algol24.com/DEFECTS-FOUND.md` (D-1, D-2). **Every one was re-reproduced
against this tree** before anything was written here, with the reproductions
kept; what follows is what the reproductions showed rather than what the
reports claimed, and in three places those differ.

The fifteen collapse to **eight root causes.** Four defects are one bug.

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

## 2. A built-in beats a field of `this`

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

## 3. One `SourceCode` holds every file

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

## 4. The compiler knows and waits

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

## 5. A diagnostic that carries no location

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

## 6. A unit name is compared case-sensitively

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

## 7. The runtime pair carries no version

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

## 8. `vm/REFERENCE.md` states a total its own body contradicts

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

## Order of work

Grouped so each step can be gated before the next, and the seed changes come
late:

| | item | why here |
| --- | --- | --- |
| 1 | ~~**1** — CEmitter's per-unit tables~~ **DONE** | four defects, one fix, and the only silent wrong answer |
| 2 | **2** — field of `this` beats a built-in | the other divergence; small, and R-5's worst symptom |
| 3 | **6** — fold the unit-name comparison | small, one rule, refuses in all three |
| 4 | **5** — R-2's one line, R-4's message | smallest things here |
| 5 | **7** — the runtime pair's version | two lines plus the harness line that keeps it true |
| 6 | **8** — the reference's total | documentation, and the script that holds it |
| 7 | **4** — R-8 and R-10 at compile time | changes what the compiler accepts; wants the corpus green first |
| 8 | **3** — `Token` gains a file | touches the seed and both processors' reports |
| 9 | **9**, **10** — R-5's flush; R-13 recorded | the two that are not repairs |

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
