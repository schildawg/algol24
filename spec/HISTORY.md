# Algol-24 — the record

What `spec/ALGOL-24.md` used to carry and no longer does. The specification
describes the language as it is; this describes how it got there.

Four things live here, and all four are closed or closing:

- **Compiler divergences** — thirty-seven places where the C back end did not do
  what the interpreter did. Every one is withdrawn.
- **Advisory notes** — eighteen questions raised during the conformance pass.
  Every one is resolved.
- **What could be written in Algol-24 itself** — a survey asking, for each
  built-in and collection, whether it is native because it *must* be. The
  answer turned out to be no, and every feature the survey asked for landed.
- **Planned generations** — seventeen changes intended for the language.
  Fifteen have landed; two have not, and those are the roadmap rather than the
  record.

The entries are kept because each records what was **actually** wrong, which in
a dozen cases is not what the entry first said — and in several is a mistake in
the fix the entry itself proposed. That is worth more than the count.

Defects are not here. A defect is a live disagreement between the specification
and the implementation, so it lives in `spec/DEFECTS.md`.

---

## Annex C — compiler divergences *(non-normative)*

Where the C back end does not do what the interpreter does. The interpreter is
the authority [1.1], so every entry here is a defect in the compiler rather than
a choice the language has made.

⚠️ **Every entry is withdrawn**, and `./conform.sh` reports no gap. They are
kept because each records what was actually wrong — which in a dozen cases is
not what the entry first said, and in several is a mistake in the fix the entry
itself proposed. Two were the *interpreter's* fault rather than the compiler's
(C-4, C-37), which the classification above does not admit and which is worth
seeing.

⚠️ A **loud** divergence refuses to compile and says why. A **silent** one
produces a program that runs and behaves differently. The second kind is far
worse, and the column says which each is.

⚠️ **Nothing here is tracked by a suite of its own.** A divergence is not a third
kind of case; it is an *outcome*. Every case in `conformance/` runs under both
processors, and a case the interpreter gets right and the compiler does not
fails its compiled half — that failure **is** the record of the divergence, and
`conform.sh` calls it a gap. **A gap fails the run**, from Generation 3 onward;
through Generations 1 and 2 it was reported instead, while the compiler was
deliberately allowed to trail. The classification of a case never depends on the
compiler's state:

| The interpreter is | The case goes in |
| --- | --- |
| right | `conformance/` or `refusals/`, even if the compiler is wrong |
| wrong | `defects/`, even if the compiler is right |

This was decided by the order the work came in rather than by tidiness. The
first goal was an interpreter that matches this specification; the next, a
compiler that matches the interpreter. Compiler gaps were therefore
**expected** to be red throughout the first, and the count was the progress
measure for the second. It has reached zero.

⚠️ The one thing that must not break is the compiler's ability to **build and
reproduce itself** — `./fixedpoint.sh` and `./test.sh`. A compiler that cannot
compile cannot produce the generation that fixes these entries.

⚠️ **An opt-out records nothing and notices nothing.** Twelve conformance cases
once carried a `// compiled: no` marker to keep the suite quiet. C-14 was found
within minutes of removing them, in a case that had been opted out since it was
written — and C-9, C-11 and C-13 had no reproduction at all while the markers
stood.

**C-1 — A file in an import cycle with the root will not compile.**
***Withdrawn.***

The root file was never entered in the parser's `Loaded` map, so a module
importing the root back parsed it a second time and the emitter saw two units of
one name — `Two modules named 'Parser' is not supported by the C back end yet.`
This was the only known case of a valid program having no compiled form.

⚠️ **Withdrawn because the cause was removed, not because the emitter changed.**
The root is registered as a module now [MOD-014], so the duplicate the emitter
was refusing no longer exists. `--compile --test compiler/Parser.a24` emits, and
`conformance/0125` compiles and runs identically to the interpreted form.

⚠️ The number is not reused. A withdrawn entry stays where it is, because the
divergence it described was real and citing it should keep working.

**C-2 — Functions may not nest more than one level deep.**
***Withdrawn.***
*(refers to [FUN-012])*

```
A function nested more than one level deep is not supported by the C back end yet.
```

Three levels of nesting ran correctly interpreted and refused to compile.

⚠️ **One missing case, not a missing mechanism.** A nested function is emitted
as a file-scope C function plus a closure over an array of heap cells, and a
cell was reachable in only one shape: a `c_x` local the enclosing function
declared. At depth two the enclosing function is *itself* nested, so the cells
it was **handed** are as much in scope where the inner declaration stands as the
ones it made — and those can only be named `cells[i]`. A capture list written
with the local form alone named locals that do not exist, so the refusal stood
in for the second shape.

⚠️ **The handed-down cells come first and in index order**, because the
receiving function reads them as `cells[i]` and the indices have to line up with
the array the closure is built from.

⚠️ **A function declared inside a METHOD is still refused**, and is a different
thing: a method's C function takes a receiver and no cell array, and a nested
function there closes over `this` as well as over the locals. Recorded as C-38.

**C-3 — A compiled assertion failure carries no message.**
***Withdrawn.***

`alg_test_run` printed no `[ERROR]` line, so the `FAIL` stood alone where the
interpreter also gave the assertion message. It prints the same line now — see
C-23, which is where the fix and the reasoning live.

⚠️ **The premise was wrong, not just the behavior.** This entry said compiled
code "has no line information to put in one", and inferred from that that the
whole line was unreproducible. Only the *caret* lines need a source position;
the message line carries the file name and the message and nothing else.

**C-4 — Collection member names are matched case-insensitively.**
***Withdrawn.***
*(refers to [COL-006])*

```
var L := [1];
L.add (2);
```

Interpreted this is `Undefined property 'add'.` Compiled it works, and the
program prints a length of 2.

⚠️ This is the first **silent** divergence recorded, and it runs in the more
dangerous direction: the compiler **accepts a program the language refuses**. A
program developed against the compiler can use lowercase member names
throughout and fail everywhere the moment it is run interpreted, with no warning
from either processor that the two disagree.

The C runtime compares collection members with `alg_stricmp`, which is
deliberate — but `bootstrap/algol.h` asserted alongside it that this was "what
the interpreter does", and it is not. That comment has been corrected.

⚠️ **Withdrawn in the compiler's favour**, which is the opposite of what this
entry proposed. [SRC-011] folds *every* name, so a built-in member is a name like
any other and `alg_stricmp` was right all along. The interpreter is what changed:
`ObjCollection`, `ObjFile` and `ObjBuffer` fold the incoming member and their
comparison literals are written folded to match.

⚠️ The entry's proposed fix — compare exactly in `alg_property` and `alg_invoke`
— would have been **wrong**, and it was written before [SRC-011] was enforced
anywhere. That is the hazard of recording a remedy alongside a divergence: the
divergence was real and the remedy assumed which side was at fault.

The number is not reused.

**C-5 — Module bodies run at a different time.**
***Withdrawn.***
*(refers to [INI-003], [INI-004])*

Interpreted, a `uses` runs its module where it appears, so root statements
interleave with module bodies in source order. Compiled, every module
initializer runs before any root statement.

```
WriteLn ('1 root');        interpreted        compiled
uses Alpha;                 1 root              Alpha body
WriteLn ('2 root');           Alpha body        Gamma body
uses Gamma;                 2 root              1 root
WriteLn ('3 root');           Gamma body        2 root
                            3 root              3 root
```

⚠️ Silent, and unlike C-4 it needs no unusual spelling to provoke: any program
whose modules print, open a file, or set a variable the root then reads will
behave differently under the two processors, and nothing warns.

The compiled shape follows from how the C is emitted — `main` calls each
`init_<Unit>()` and then `init_Main()` — and it is the easier order to produce,
since a module's initializer is a function and the root's body is not special.

The interpreter is the authority [1.1], so the compiler was wrong.

⚠️ **The `uses` had been filtered out of the statements entirely**, which is why
the emitter had no way to say *when*. It was split off as an import and dropped;
keeping it is most of the fix, and `VisitModuleStmt` — until now nothing but a
refusal for a nested `uses` — writes the call. `main` starts the root and
nothing else. [INI-004] then follows from the same mechanism rather than needing
its own: a module's `uses` clauses stand at the top of its body, so its
initializer runs them before its own statements.

⚠️ **A `uses` runs under `--test` too**, and had to be added to the set of
statements a test run keeps. Only the file being *tested* has its program held
back; while `main` started every module itself this did not matter, and the
moment the clause became what starts one, leaving it out would have given a test
run no modules at all.

⚠️ **Hoisting a class had to become conditional, and this is where the fix
turned out to be about more than order.** A class is built ahead of its file's
statements only when its parent is absent or is another class of the **same
file** — `Interpreter.Hoist`'s rule, which the emitter did not have. It built
every class in `Setup`, before any statement, and that was indistinguishable
from correct only because every module initializer ran first. With modules
starting at their clause, a class inheriting from one had to be built where its
declaration stands.

⚠️ **And that exposed a silent divergence hiding inside this one.** A class
inheriting from a module named *below* it is `Undefined variable 'Shape'.`
interpreted — nothing has bound the name yet — and compiled it *ran*, because
the parent's shell had been built before any statement. The compiler accepted a
program the language refuses. `alg_class_declared` reports the name, and
`conformance/0146` and `0147` pin both orders.

**Not a divergence, and worth stating as a requirement:** interpreted and
compiled `--test` reports are byte-identical, color included — 239 lines and
1,416 escape sequences for the full suite. Any difference between them is a
defect in one or the other.

---

**C-6 — Reading a method as a property crashes the compiled program.**
***Withdrawn.***
*(refers to [TYP-012])*

```
class Box;
begin
    function Size (); begin Exit 7; end
end

var B := Box ();
WriteLn (B.Size ());
WriteLn (B.Size);
```

Interpreted this prints `7` and then `<fn Size>`, which is what [TYP-012]
requires. Compiled it dies of `SIGSEGV` (exit 139) with **no output at all** —
the earlier `WriteLn` is lost with the buffer.

⚠️ This is the most serious divergence recorded so far, and it is worse than
C-4. C-4 accepts a program the language refuses; this one takes a program both
processors accept and crashes it, without a diagnostic, in the processor that is
supposed to be the fast one. `alg_property` has no case for a method reached
without a call.

⚠️ **The fault was in `as_text`, not in `alg_property`.** This entry blamed the
property lookup, which had handled a bare method for some time. `as_text` had no
case for a bound method and fell through to `collection_text`, which casts
anything that is not a Map to `ObjSeq *` and reads a count out of it. Both
processors print `<fn Length>` now.

⚠️ **`collection_text` was a catch-all and is not one any more**, which is the
half that mattered beyond this entry. Any heap object of an unhandled kind
reaching it crashed rather than saying anything; it names the kind and raises
now. A missing case should be a diagnostic, not a wild read.

⚠️ It closed by repair rather than by removal. H-6 once proposed making a bare
`B.Length` an error and retiring the construct instead; that proposal has since
been withdrawn — reading a method as a value is specified [FUN-011] and stays —
so the repair is now the whole answer rather than an interim one.

**C-7 — Four runtime diagnostics are worded differently.**
***Withdrawn.***
*(refers to [TYP-009], [TYP-010])*

| Program | Interpreted | Compiled |
| --- | --- | --- |
| `List ().ClassName` | `Undefined property 'ClassName'.` | `Only instances have properties.` |
| `B[0]` on an instance | `Subscript target should be an ordinal.` | `Only a collection or a String can be subscripted.` |
| `C (1, 2)` on a class with no constructor | `Expected 0 arguments but got 2.` | `This class takes no constructor arguments.` |
| `Color.Nope` | `Undefined enum member 'Nope'.` | `That enum has no such member.` |

Both processors refuse every one of them, so nothing runs that should not — but
the text differs, and [ERR-002] requires a diagnostic to be the same wherever it is
produced.

⚠️ **This entry recommended the wrong direction**, and the rules settle it. It
argued that the compiled wording was better and that the interpreter should move
toward the compiler. But all four texts are *pinned by rules* — [TYP-009],
[TYP-010], [EXP-011] and [ENU-004] each quote the interpreted wording — so the
compiler was simply wrong, and it moved.

⚠️ The aesthetic argument survives the fix and is worth keeping: `Subscript
target should be an ordinal.` does describe the *subscript* when the fault is the
*target*. That is a case for changing [TYP-010], which belongs in Annex D as a
proposal, not in the runtime as a divergence. Nothing here forecloses it.


**C-8 — An uncaught runtime error carries no `Uncaught:` prefix.**
***Withdrawn.***

| | |
| --- | --- |
| Interpreted | `Uncaught: Index 5 out of range 0..2.` |
| Compiled | `Index 5 out of range 0..2.` |

The message is identical; only the prefix the driver adds is missing.

⚠️ **Narrower than it was first recorded.** This entry said "every conformance
case ending in a runtime error meets this". It applies only to an error raised
by the **runtime** — a division by zero, a subscript out of range, no matching
signature. Two cases keep the prefix and were wrongly marked as meeting it:

| | |
| --- | --- |
| An explicit `raise` | prefix present in **both**; `raise 'boom'` gives `Uncaught: boom` either way |
| A scan, parse or type error | prefix present in **both**, because the front end is shared [1.1] |

The correction came from running the two processors against four cases whose
comments claimed a divergence they did not have.

⚠️ Unlike C-3, this was not a consequence of compiled code lacking line
information — the prefix needs nothing the compiled program does not have.

⚠️ **One line, and twelve cases.** `alg_raise` printed the prefix on its uncaught
path and `alg_error` did not, so an error raised by the *runtime* lost it while
an explicit `raise` kept it. That asymmetry inside one file is what made the
entry look larger and vaguer than it was: it was first recorded as "every
conformance case ending in a runtime error", narrowed once by testing, and is
in fact a single `fprintf`.


**C-10 — The compiled back end hoists variables.**
***Withdrawn.***
*(refers to [DCL-016])*

```
WriteLn (V);
var V := 7;
```

Interpreted this is `Undefined variable 'V'.` Compiled it printed `nil`.

Every top-level name is emitted at C file scope, so it exists from the start of
the program; a variable simply held `nil` until its initializer ran.

⚠️ **This was the silent direction again, and the worst instance of it.** The
compiler did not merely accept a refused program — it substituted a **value**
for a diagnostic, so the program ran to completion with `nil` where a number was
meant, and nothing anywhere said so.

⚠️ **The compiler was only half wrong.** Hoisting a *function, class or enum* is
what [DCL-006] requires, and the interpreter does it. Hoisting a *variable* is
what [DCL-016] forbids. One mechanism, correct for three kinds of declaration
and wrong about the fourth, which is why it took a rule split to describe — and
why the fix could not be to stop emitting names at file scope.

⚠️ **A `d_` bool beside the `v_` storage, and a RUNTIME check.** Nothing the
emitter can see decides it: a read may sit inside a function declared above the
variable and called from below it, which is legal and ordinary, so
`function Peek (); begin Exit Later; end` is correct or an error depending on
when `Peek` is called.

⚠️ **A bool rather than a sentinel `Value`**, so that nothing the language can
hold ever means "not yet declared". A sentinel could be printed, compared or
widened by any read the emitter failed to guard; the worst a missed guard can do
here is what the emitter already did.

⚠️ **An assignment is checked too.** A variable is bound by its *declaration*,
not by being written to, so `V := 5;` above `var V := 7;` is the same error a
read gets rather than a store the declaration then overwrites.

**C-11 — A top-level block is reordered.**
***Withdrawn.***

```
WriteLn ('one');
begin
    WriteLn ('two');
end
WriteLn ('three');
```

| Interpreted | Compiled |
| --- | --- |
| `one two three` | `one three two` |

A bare `begin` … `end` at the top level runs **in place** interpreted and
**after every other top-level statement** compiled. With two such blocks, both
are deferred and run in their own order at the end.

⚠️ **A counted `for` is affected too, and that is the case that matters.**
[STM-006] desugars it into a block holding the initializer and a `while`, so a
top-level counted loop is a top-level block and is deferred with the rest:

```
WriteLn ('one');
for var I := 1; I <= 2; I := I + 1 do WriteLn ('  loop ' + Str (I));
WriteLn ('two');
```

| Interpreted | Compiled |
| --- | --- |
| `one` `loop 1` `loop 2` `two` | `one` `two` `loop 1` `loop 2` |

A bare block at the top level is rare; a counted loop is ordinary code, so the
divergence is far more reachable than the entry first suggested. It was found by
running the first three-line program written to try the VS Code **Run Both**
command.

⚠️ **Scoped by running each shape.** These are *not* affected, because the block
in each is a body rather than a top-level statement: a `while` with a block
body, a `for … in`, and an `if`.

⚠️ **Statement order is not preserved**, which makes this the most damaging
silent divergence recorded. C-6 crashes, which is at least noticeable; C-10
substitutes `nil` for a diagnostic, which a careful reader may spot. This one
runs every statement, produces no error, and simply performs them in a different
order — so a program whose blocks write files, print, or set variables the rest
of the file reads will behave differently under the two processors with nothing
to indicate it.

The emitter treated a top-level block as the program's main body, which is right
for the one block a program conventionally ends with and wrong for a block
appearing anywhere else.

⚠️ **Deferring was unnecessary as well as wrong.** Its stated purpose was to run
the program body after every module had initialized, and that already held: the
root's initializer is the *last* one `main` calls. Every top-level statement is
emitted in order now, blocks included.

⚠️ **C-13 was the same bug**, reached through a counted loop rather than a bare
block, and closed with it.

⚠️ `conformance/0039` differed after this for a different reason: with the block
correctly scoped, a name read after the `end` does not exist, and the emitter
wrote a reference to it rather than refusing by name. That was C-34, and it is
closed too.

⚠️ It used to constrain the conformance corpus: a case using a bare top-level
block to demonstrate scoping could not be run under both processors.
`conformance/0040` puts its blocks inside procedures for exactly this reason,
which keeps the cross-check.


**C-13 — Two counted `for` loops sharing a variable name at the top level emit
invalid C.**
***Withdrawn.***
*(refers to [STM-006], [DCL-008])*

```
for var I := 0; I < 2; I := I + 1 do Write (I);
for var I := 0; I < 2; I := I + 1 do Write (I);
```

```
error: redefinition of 'v_I'
```

[STM-006] desugars a counted `for` into a block holding the initializer and a
`while`, which is why its variable is scoped [DCL-008]. At the top level the
emitter does not open a C block for it, so both loops declare `v_I` in one
scope. Inside a function or method it is emitted correctly, which is why the
compiler compiles itself — all sixty-eight of its own counted loops are inside
one.

⚠️ **The emitter breaks its own contract here.** It is supposed to refuse by
name what it cannot emit rather than emit something wrong. Instead it produces C
that `cc` rejects, so the diagnostic names `v_I` and a line in a generated file
rather than the loop the programmer wrote. A refusal from `algc` would be
strictly better than a valid-looking emission that fails downstream.

⚠️ **The same bug as C-11**, and closed with it. A top-level block was pulled
out and run at the end; a counted `for` desugars into a block, so an ordinary
loop was deferred and two of them declared one variable in one C scope. Every
top-level statement is emitted in order now, and a block opens a C block, so its
variable is a local.

⚠️ It constrained the corpus while it stood: `conformance/0054` puts its loops
inside a procedure, as `conformance/0040` does for C-11. Neither needs to now.


**C-14 — Compiled code does not check arity.**
***Withdrawn.***
*(refers to [EXP-011])*

```
function One (A); begin Exit A; end
WriteLn (One (1, 2));
WriteLn ('kept going');
```

Interpreted this is `Uncaught: Expected 1 arguments but got 2.` Compiled it
printed `1` and then `kept going` — the extra argument was discarded and the
program ran on. Too *few* arguments was accepted as well, and read past the end
of the argument array.

⚠️ **This was invisible while `conformance/0049` opted out of the compiled
half.** It was found within minutes of removing the opt-outs, which is the
argument for not having them: an opt-out records nothing and notices nothing,
and the case it silences is exactly the case that would have found the bug.

⚠️ **Only one call shape was unguarded, not all of them.** A nested function is
reached through `alg_call` and a method through `alg_invoke`, and both compared
counts already. A **top-level subprogram** is called by its own C symbol —
`f_one(NULL, args, 2)` — so nothing sits between the call and the body. The
check is emitted in the *callee*, for the reason `alg_param` is: the declared
arity is already there, and one place answers for every call site. Top-level
overloads are refused by name (C-2), so a symbol has exactly one arity.

⚠️ **Two different failures, and they are not interchangeable.** A subprogram
with one signature reports the counts. A **method** reports `No matching
signature for function.`, because arity is only part of what it selects on
[EXP-014] and a wrong count is one way for nothing to fit — there is no single
expected count to name. The runtime said `Wrong number of arguments.` for the
method case and `Wrong number of arguments to Init.` for a constructor, neither
of which any interpreted run produces; `0049` now pins all four shapes.

**C-15 — A call to an object will not compile.**
***Withdrawn.***
*(refers to [CLS-016])*

```
object Config;
begin
    function Value (); begin Exit 1; end
end
WriteLn (Config ());
```

```
A call to 'Config' is not supported by the C back end yet.
```

Interpreted the program runs until the call, which raises `Can only call
functions and classes.` [CLS-016].

The same refusal covers a call the emitter has no case for at all:

| Program | Interpreted | Compiled |
| --- | --- | --- |
| `Config ()` on an object | `Can only call functions and classes.` | `A call to 'Config' is not supported…` |
| `AssertTrue (True)` outside a test run | `Undefined variable 'AssertTrue'.` | `A call to 'AssertTrue' is not supported…` |

⚠️ The second is worth noticing because the interpreter is right for a reason
the emitter does not share: the assertions are registered **only while `--test`
is running** [RT-002], so outside one the name is simply not there. The emitter
sees a call to a name it cannot resolve and refuses it as unsupported, which
describes the emitter rather than the program.

⚠️ The program is a **valid** one whose defined behavior is to raise. The
emitter refused it rather than emitting something that raises, so a program the
language merely rejects at run time had no compiled form at all. That was the
right way round for a gap — loud, named, and impossible to miss — but it was
still a program the two processors did not agree on.

⚠️ **The runtime already had the wording.** `alg_call` says `Can only call
functions and classes.` for anything that is not callable, so emitting the call
rather than refusing it produces the language's own message: the singleton is
built first, as the interpreter evaluates the callee first, and handed to
`alg_call` like any other value. Both rows of the table above are closed — the
second by C-33, and for the same reason: neither program is one the back end
cannot express.

**C-16 — Inheriting from a non-class emits invalid C.**
***Withdrawn.***

*(refers to [CLS-014])*

```
var X := 1;
class C (X);
begin
end
```

```
error: use of undeclared identifier 'k_X'
```

The emitter writes `alg_class("C", k_X)` for a superclass that is not a class,
and `k_X` names a class handle that was never emitted because `X` is a variable.
The interpreter refuses the program with `'X' is not a class.`

⚠️ **The emitter broke its own contract**, as C-13 did: it is supposed to refuse
what it cannot emit, and instead produced C that `cc` rejected, naming a
generated symbol rather than the declaration the programmer wrote.

⚠️ **It refuses with the LANGUAGE's message**, not with "not supported by the C
back end yet" — this is a program that is *wrong*, not one this back end cannot
express. Both processors now say `'X' is not a class.` and the case stopped
being a gap rather than merely becoming a tidier one.

⚠️ **The emitter is the last chance to catch it.** The interpreter checks the
superclass when the declaration *runs*; a compiled program never runs its
declarations at emit time, so nothing else would have said anything.


**C-17 — An enum member has no properties compiled.**
***Withdrawn.***
*(refers to [ENU-010])*

`RED.Ordinal` was `Only instances have properties.` compiled, where the
interpreter answers `0`.

⚠️ **New in generation 1**, and expected: the interpreter gained the property
and the C runtime had not. `alg_property` needed the case `ObjEnum` had gained.

⚠️ **The ordinal was already there to answer with.** The runtime has carried it
since enums were emitted at all, because truthiness reads it — the first member
of every enumeration is falsey [ENU-009] — so a compiled program was governed by
a number it had no way to read, and could discover whether a member was falsey
only by testing it for truth.

**C-18 — `Length` of a collection is not refused compiled.**
***Withdrawn.***
*(refers to [RT-003])*

`Length([10, 20, 30])` is refused interpreted — `Length expects text; use
.Length for a collection.` — and compiled it returned the length of the
rendering, as the interpreter used to.

⚠️ **Silent, and the same trap the interpreter had just lost**: a plausible
number rather than an error.

⚠️ **The cause was one C function doing two jobs.** `Length(X)` and `X.Length`
are spelled alike and are not the same operation — one measures text, the other
answers a count — and the emitter mapped both onto `alg_length`, keyed by arity
so that it could. `alg_text_length` is the function; `alg_length` stays the
property. The comment on the emitter's builtin table asserted the two "mean the
same thing", which is what made the conflation look deliberate.

**C-19 — A cast is not checked compiled.**
***Withdrawn.***
*(refers to [VAL-007])*

```
var Bad : Any := 'text';
WriteLn (Bad as Integer);
```

Interpreted this is `Cannot cast String to Integer.` Compiled it printed `text`,
which is what the interpreter did before DEF-12.

⚠️ **The most consequential divergence recorded.** [VAR-006] routes every
untyped-to-typed crossing through `as`, so a compiled program had no verified
boundary anywhere: a value of the wrong type passed into a declared type and
nothing said so. The parser stored the cast on the expression and the emitter
read the field nowhere.

⚠️ **Fixed in the one place the interpreter fixes it.** `as` sets a *field* on
an expression rather than wrapping it, so both processors check it in their own
`Evaluate` — the single point every expression passes through, whatever its
shape. `alg_cast` is `alg_is` made a requirement, and parts company with it on
exactly one value: `nil` satisfies every type [VAR-005] and so passes every
cast, where it `is` nothing.

⚠️ The *precedence* half of the same work needed nothing: [EXP-003] is a parsing
rule and the front end is shared, so both processors already agreed that
`False and 5 as Integer` is `False`.

The compiled compiler ran its own 221 tests with every cast in its sources
checked, and reported identically to the interpreted run — which is the evidence
that the check is the interpreter's and not a stricter one.

**C-20 — Two enumerations binding one member is refused compiled.**
***Withdrawn.***

Two enumerations may share a member name [ENU-003] and the interpreter runs the
program, refusing only the ambiguous bare use [ENU-011]. The emitter refused the
whole program with `Two enumerations binding 'A' is not supported by the C back
end yet.`

⚠️ **It used to be silent, and that was worse.** The emitter keys each member's C
symbol by the member name alone, so the second enumeration's entry overwrote the
first's and the first's members began resolving to the second's symbols. The
ambiguous use that [ENU-011] refuses printed a member instead. The refusal was
added deliberately, in preference to emitting a wrong answer.

⚠️ **The symbols were never the problem**, which is why the recorded fix — "key
the member map on the owning enumeration" — was aimed at the wrong thing. A
member's symbol already carries its type [G.3], and the *qualified* form goes
through `alg_property` on the enumeration rather than through the map at all.
Only the **bare** name has two answers, and having two answers is exactly what
[ENU-011] makes an error. So the ambiguity is carried to the use and reported
there, in the interpreter's words, after everything above it has run —
`Environment.Ambiguous` is consulted at the same moment for the same reason.

**C-21 — Two modules exporting one name is refused compiled.**
***Withdrawn.***

Two imported modules may export one name [MOD-008] and the interpreter runs the
program, refusing only the ambiguous bare use [MOD-013]. The emitter refused with
`Two modules exporting 'Shared' is not supported by the C back end yet.`

⚠️ Two modules exporting one **function** would emit cleanly from both back ends
and then die at the **linker** on a duplicate symbol — past anything a
compile-only check can observe — which is why the refusal was worth keeping
until the emitter learned to rename.

⚠️ **Renaming and resolving are different questions**, and the recorded fix named
only the first. The *symbol* is program-wide, so both owners take their unit as
a suffix wherever they are written. *Which* symbol a bare use means is per file:
one importing a single owner names it bare quite legally and must reach that
owner's suffixed symbol, and only one importing both has a name with no answer.
A qualified use resolves either way, which is what makes this a use-site error
rather than a refusal.

⚠️ **`Renames` had to stop being suspended at a qualified name and start being
replaced.** Clearing it was right only while an exported name could never be
renamed; with one that can, `Alpha.Shared()` emitted the unsuffixed name nothing
defines.

⚠️ **And it was C-2 that actually refused the program**, not this entry's check.
`TopLevel` accumulated across the whole program, so `Shared` in Alpha and
`Shared` in Beta read as an *overload* [FUN-013] and were refused as one — the
emitter reporting a language feature it does not have for a program using one it
does. The set is cleared per unit now, which is what the check always meant.

⚠️ **`Renames` also held the wrong thing.** It stored `Name__Unit` and `Mangle`
escaped that whole string, which is exactly what `Mangle`'s own note forbids: `_`
escapes to `V`, so the joined form and an identifier spelled `NameVVUnit` meet.
It stayed injective only by the accident of the name appearing twice, and nothing
in the compiler's own sources is renamed, so no emitted symbol ever showed it.

**C-22 — A Unicode identifier will not compile.**
***Withdrawn.***

Any Unicode character may appear in an identifier [SRC-005] and the emitter
refused it with `An identifier containing 'é' is not supported by the C back end
yet.` Annex G.3's scheme is implemented, so `🙂` emits as `U01F642` and
`conformance/0139` compiles to output identical to the interpreted run.

⚠️ **Adopting G.3 in part would not have worked**, which is why this waited. The
escape only becomes free once every letter is lowercased; adding `U` escapes to
the old pass-through scheme would have collided with an identifier spelled like
one. The two halves of G.3 are a single decision.

⚠️ **Three bootstrap generations**, not two. The old binary emits the new
scheme's *source* under the old rules, so generation 1 still carries old
symbols; generation 2 emits new ones; generation 3 is where the output stops
changing. `fixedpoint.sh` iterates for exactly this.

**C-23 — A compiled test run never says why a test failed.**
***Withdrawn.***

`alg_test_run` caught the failure and printed `FAIL` but never read the value
that was raised, so a compiled suite reported *that* a test failed and never
*what*. It prints the same `[ERROR] <file>: <message>` line the interpreter does
now, from `AlgFrame`'s `raised`.

⚠️ **There were no caret lines to worry about.** This entry assumed a test
failure printed three lines, of which compiled code could reproduce one. It
prints exactly **one**: `Console.Error` adds a source line and a caret, and a
test failure does not go through it. So no filtering was needed on either side —
the reports simply match.

⚠️ **The file named is the ROOT**, not the file the failing test lives in, and
the compiled runner had to copy that to agree. `SourceCode` is one global keyed
by line number, so the interpreter names the file the run started from whatever
module the test came from. Reproducing a fault is what agreement costs here.

⚠️ It is why the two processors could disagree about `AssertTrue`'s wording for
as long as they did: nothing that compares the two reports ever looked at this
line. Verified after the fix — the whole suite, 221 tests at the time, came out
identical line for line through both processors.

⚠️ **The last differing line is gone too.** A failing run used to print
`Uncaught: Tests failed.` interpreted and nothing compiled, because the driver
had to `raise` to set exit 70. `Halt` [RT-018] was added for it, and the
interpreted driver calls that instead — so neither side prints anything the
report did not ask for, and a failing suite is now identical through both
processors.

**C-24 — A compiled top-level subprogram is matched on arity, not signature.**
***Withdrawn.***
*(refers to [FUN-006])*

`function G (N : Integer)` called with a String is `No matching signature for
function.` interpreted and runs compiled, returning the String. The emitted call
checks the count and nothing else.

⚠️ **Silent, and in the dangerous direction**: the compiler accepts a program the
language refuses, so one developed against the compiler fails the moment it is
run interpreted. It is the same shape C-4 had, and the same remedy applies —
bring the compiler up, not the interpreter down.

⚠️ **Checked in the CALLEE, not at the call site.** The entry proposed the call
site; the callee is one place instead of many, and it is where the declared type
already is. `alg_param` raises what does not fit and widens what does.

⚠️ **Only a top-level subprogram goes through it.** A method's parameters are
checked when the overload is *selected*, and a constructor's are deliberately not
checked at all — see `find_method`'s `strict`. A top-level subprogram has no
selection step, which is exactly why the check had nowhere else to live.


**C-25 — A compiled value does not widen into a written type.**
***Withdrawn.***
*(refers to [VAR-017], [EXP-014])*

`function D (X : Double)` called as `D (1)` yields `1` compiled and `1.0`
interpreted. A parameter is an assignment context, so the argument should widen
on the way in and the parameter should hold the wider type.

⚠️ Distinct from C-24, which is about *refusing* a mismatch: this one is about
*converting* a match. A compiled program silently held an Integer where its own
declaration said Double.

⚠️ **Wider than a parameter.** The entry named only arguments; a declaration, a
`const`, a plain assignment, a field and a field's initializer were all
unconverted too. `alg_widen` is called at each, and the declared type reaches the
assignment and field cases **on the node**, written there by the TypeChecker —
the same arrangement the interpreter needed.

⚠️ **Selection had to learn to widen at the same moment**, or `Only ('a')` against
a `String` parameter found no method. `find_method` makes three passes — exact,
widening, then absorbing [FUN-005] — over the whole chain, the mirror of the
interpreter's, and for the same reason: one pass would let declaration order
decide.

⚠️ **Widening and checking are separate jobs, and conflating them broke the
bootstrap.** One helper that both converted and refused turned a String reaching
a field declared `Expr` into an error — a shape real programs use, since a
constructor's signature is unchecked by design. `alg_widen` converts and refuses
nothing; `alg_param` does both and is used only where a check belongs.


**C-26 — Two top-level subprograms of one name will not compile.**
***Withdrawn.***

A top-level subprogram overloads [FUN-013] and the interpreter selects between
them. The emitter refused with `Two subprograms named 'Take' is not supported by
the C back end yet.`

⚠️ **It used to emit and die at `cc`** — `redefinition of f_Take` — which is a
compiler producing a program it cannot build, and past anything the emitter's
own checks observe. The refusal was added with the rule.

⚠️ **The two halves the entry named were both needed, and the second is the one
that shapes the design.** `FunctionSymbol` mangles by signature so both
definitions can be spelled; and because the call site cannot know which
candidate it wants until it has its arguments, a name with more than one
subprogram behind it is reached through an **overload set** — one value per
name, holding every candidate with its **parameter list as written** — name,
type and element type each — which selects when called. `alg_call` on one is
`find_method` for subprograms: three passes, exact then widening then absorbing
[EXP-014], forwards within a pass so the first declared wins.

⚠️ **Only an overloaded name pays for it.** A name with a single subprogram
behind it is still called by its own symbol and still carries no signature
suffix, so the emitted C of every program without an overload is unchanged —
which is also what let the seed stay comparable across this change.

⚠️ **One message for both failures**, which is what the interpreter gives: a
wrong count and a wrong type are both "nothing fitted", and there is no single
expected arity to name when the candidates disagree about it.

⚠️ **The refusal was also firing across units**, which is how C-21 met it:
`TopLevel` accumulated program-wide, so one name in two files read as an
overload. Two subprograms in two files are not one, and the set is cleared per
unit.

**C-27 — A large literal of computed elements will not compile.**
***Withdrawn.***

A collection literal is emitted as nested `alg_list_keep` calls, one bracket
level per element, and `cc` gives up at 256 — clang says `bracket nesting level
exceeded maximum of 256`. Above a hundred elements the emitter builds the
literal in a helper function instead, one assignment per element, so depth stays
at one however many there are.

⚠️ That was only possible when every element was **itself a literal**. `[X, Y]`
reads two variables and a helper lifted to file scope cannot see them, so a large
literal with computed elements was refused by name rather than emitted as
something `cc` rejects: `A literal of 200 computed elements is not supported by
the C back end yet.`

⚠️ **It used to emit and die at `cc`**, which is the failure this back end exists
to avoid — found by a generated table of 659 ranges producing a 40 KB expression
nested 659 deep.

⚠️ **The elements are evaluated at the CALL and handed in**, which is the first
of the two fixes this entry proposed. One compound literal, so the bracket depth
is 1 however many there are — `ArgumentArray` builds every call's arguments the
same way, so this introduced no shape the emitted C did not already have.

⚠️ **A constant literal keeps the helper it had.** The two forms differ only in
where the elements are written, and keeping the first leaves the emitted C of
every existing large table exactly as it was.

⚠️ A Map's keys and values are **interleaved** into one array, key first: two
arrays would need two parameters and two compound literals for no gain.

**C-28 — An undefined collection member is not refused compiled.**
***Withdrawn.***
*(refers to [COL-005])*

`K.Get (0)` on a `Stack` is `Undefined property 'Get'.` interpreted — `Get`
belongs to a List, an Array and a Map — and compiled it ran and answered.

⚠️ Silent, and in the direction that matters: the compiler accepted a program
the language refuses.

⚠️ **The member table is per KIND, and the runtime's was flat.** Every name was
answered for every collection, so the kinds were distinguishable only by what
happened to work. `kind_has` mirrors `ObjCollection.Get`'s chain of kind tests;
the two are one table written twice and have to be read together.

**C-29 — An invalid subscript target is not refused compiled.**
***Withdrawn.***
*(refers to [TYP-010])*

Subscripting a Set is `Subscript target should be an ordinal.` interpreted, and
compiled it answered a value. Same cause as C-28: a Set is a sequence in the
runtime's representation, so the position path took it.

⚠️ **A Set reports as though it were not a collection at all**, which is what
`ObjCollection.At` does deliberately: there is no subscript path for a Set, so
it falls through to the complaint anything else without one gets.

Assignment was wrong in a second way the entry did not name — `'abc'[0] := 'x'`
answered `Only a collection can be subscripted.`, which is false of the receiver
in front of it. It is `Strings are immutable.` on both sides now.

**C-30 — `Max` and `Val` answer differently compiled.**
***Withdrawn.***
*(refers to [RT-010], [RT-011])*

| | Interpreted | Compiled |
| --- | --- | --- |
| `Max (3.5, 2)` | `-7`-style promotion, answering the larger | `Max expects Integers.` |
| `Val ('42')` | `42` | `42.0` |

⚠️ Two faults in one case, pulling opposite ways: `Max` refused what the
language admits, and `Val` answered a Double where the language says Integer.
Each was defensible alone and together they left `Max (Val (A), Val (B))`
failing for **every** input.

⚠️ **The digits are accumulated through `alg_multiply` and `alg_add`**, not
converted from the parsed double, and not for precision: those carry the range
check [LEX-018], so `Val ('99999999999')` raises `Integer overflow: 999999999 *
10.` exactly as the interpreter's does. A cast would answer a wrong number
quietly, and the language has no narrowing conversion to write instead.

**C-31 — A compiled class does not inherit from a parent declared below it.**
***Withdrawn.***
*(refers to [DCL-006])*

`class Puppy (Hound);` written above `class Hound;` linked to nothing compiled:
`Puppy () is Hound` was **false**, and the inherited method was then
`Undefined property 'Speak'.`

⚠️ The interpreter hoists a class in two phases for exactly this — the name is
bound before anything runs and filled in where the declaration stands, so the
subclass holds the finished parent. The emitter hoisted every top-level name
(C-10) and still got this wrong, which was worth noticing: hoisting *more* did
not make it right, because binding a name is not the same as the thing it names
existing.

⚠️ **The emitter now hoists in two phases too.** Every class in a unit is built
as an empty shell in one buffer, and the links, fields and methods follow in
another — so a child is linked to a parent that exists rather than to a handle
still holding `nil`. `alg_class_super` is the second phase; passing the parent
to `alg_class` could never have worked.

⚠️ **`total_fields` had to become lazy for it.** An instance's size is its
class's fields plus its ancestors', and it was maintained as fields were
registered — which needs the parent's fields to be in place before the child's.
With inheritance linked ahead of any field, there is no moment during setup at
which a running total would be right, so it is computed on first use and cached.
Safe because nothing instantiates a class until every `init_<Unit>()` has run.

**C-32 — Names are not matched without regard to case compiled.**
***Withdrawn.***
*(refers to [SRC-011])*

`GREET ('you')` calling `function Greet` is
`A call to 'GREET' is not supported by the C back end yet.`

⚠️ **The call was only the first layer.** Annex G.3's mangling already lowers
both spellings to `f_greet`, so the *symbol* was never the problem — the lookup
that decides which branch to take was keyed by the name as written. Fixing it
uncovered three more of exactly the same kind, each found by running the case
again:

| | |
| --- | --- |
| a **field** — `this.VALUE` against `Value` | `field_slot` compared with `strcmp` |
| a **method** — `B.DOUBLED ()` against `Doubled` | `find_method` hashed and compared the exact spelling |
| an **enum member** — `COLOUR.red` against `Color.Red` | the member scan compared with `strcmp` |

⚠️ **The emitter canonicalises, the runtime folds**, and the split is deliberate.
The emitter maps a name to the spelling it was declared with, once, so the sets
it consults stay as they are; the runtime folds its own field, method and enum
lookups because it has no declaration to consult. A name is still *emitted* as
written, so a diagnostic quotes what the program wrote.

⚠️ A comment in `alg_property` claimed the interpreter's fields were
case-sensitive too. That stopped being true when DEF-02 landed, and nothing
noticed until this entry was worked.

⚠️ The folded hash costs nothing measurable — three runs of `./test.sh` before
and after are the same to within noise, which matters because `find_method` is
the hottest path in the runtime.


**C-33 — An assertion outside a test run is refused compiled.**
***Withdrawn.***
*(refers to [RT-002])*

Calling `AssertTrue` outside `--test` is `Undefined variable 'AssertTrue'.`
interpreted — the name is registered only during a test run — and compiled it
was `A call to 'AssertTrue' is not supported by the C back end yet.`

⚠️ Both refused, so this was a wording difference like C-7 rather than a hole.
The compiled text named the back end for something that is a rule about the
*language*, which is the part that misled.

⚠️ **The bare name was already right**; only the call was wrong. `AssertTrue`
read as a value took the emitter's undefined-name path, and `AssertTrue (True)`
fell through the call table to the catch-all refusal — one name, two paths,
disagreeing about whether the program was wrong or the emitter was incapable.

**C-34 — A name that does not resolve emits invalid C.**
***Withdrawn.***
*(refers to [MOD-009], [DCL-008])*

A name the program cannot reach is a runtime error interpreted and a `cc`
failure compiled, because the emitter writes a reference to a symbol it never
declared. Two shapes reach it:

| | Interpreted | Compiled |
| --- | --- | --- |
| a name its imports do not export | `Undefined variable 'DeepName'.`, naming the unit that has it | `undeclared identifier 'f_deepname'` |
| a block-local name read after the `end` | `Undefined variable 'Inner'.` | `undeclared identifier 'v_inner'` |

⚠️ The second shape only became reachable when C-11 was fixed. Before that a
top-level block's variable was emitted at file scope, so it wrongly *did* exist
after the block and the program ran with no complaint at all.

⚠️ **Emitted as a RUNTIME error, not refused at compile time**, which is what the
interpreter does: a name is looked up when it is *used*, so a reference on a path
never taken is not an error at all. Refusing at emit time would reject programs
the language accepts. `UnitValue` had done exactly this for a *qualified* name all
along — `(alg_error("…"), alg_nil())` — and the bare forms now do the same.

⚠️ **`Declared` is not the same as reachable**, which is what the first shape
turned on. `Declared` spans the whole flattened program, so a function in a unit
this file never imported still counted as declared and the call emitted
`f_deepname` against a header that was never included. `uses` is not transitive
[MOD-009]; `ShadowNames` is what a unit can actually see.

⚠️ **The suggestion is part of the message and is reproduced.** `Undefined
variable 'X'.` alone is indistinguishable from a typo for a name the reader can
see in another file, so the compiled text names the unit too — the two outputs
are byte-identical. ⚠️ Units are walked in *name* order here where the
interpreter walks them in *load* order; with two units exporting one name the
two could still name different ones.

⚠️ The emitter breaks its own contract, as in C-13 and C-16: it should refuse by
name what it cannot emit rather than emit C that does not build.

**C-35 — A collection member read without calling it is refused compiled.**
***Withdrawn.***
*(refers to [COL-005])*

`var Sort := L.Sort;` binds a callable interpreted and was `Undefined property
'Sort'.` compiled. Only `Length` and `IsEmpty` were answered on this path, so of
the 41 kind/member pairs [COL-003] records, a compiled program could read 10.

⚠️ **This is the instance case again, one receiver kind later.** `alg_property`
already gained the note that a method reached without calling it binds to its
receiver — written because `algc`'s own `IsCallable` asks every value for its
`Arity`, so a compiled `algc` could not call anything at all. Collections were
not given the same treatment, and nothing noticed because nothing reads a
collection member without calling it.

⚠️ **Found by adding a conformance case for a probe.** `spec/members.a24` has
exercised exactly this since [COL-003]'s matrix was first checked — but it is a
*source* for `spec/spec.sh`, not a conformance case, so `conform.sh` never
compiled it and the divergence stayed invisible. A program only the interpreter
runs is not evidence about the language.

⚠️ **A Buffer and a TextFile were wrong the same way**, which the entry did not
say. All three receivers take their members from the runtime rather than from a
class, and all three answered only their bare properties. `ObjBuffer.Get` and
`ObjFile.Get` hand back a callable exactly as `ObjCollection.Get` does.

⚠️ **The tables had to carry an ARITY, not just membership.** What a read binds
is callable, and a callable has to know how many arguments it takes — the three
interpreter wrappers each carry one for precisely this check. There are now four
copies of that table and they have to be read together; `spec/spec.sh` checks
[COL-003] against the interpreter's, and `conformance/0144` is what compares the
compiled one against it.

**C-36 — A built-in called with the wrong arity is refused by name.**
***Withdrawn.***
*(refers to [EXP-011], [RT-001])*

`Length ('a', 'b')` is `Expected 1 arguments but got 2.` interpreted and was
`A call to 'Length' is not supported by the C back end yet.` compiled.

⚠️ **The name exists**, which is what made the compiled text wrong rather than
merely differently worded: it reported a gap in the back end for a program that
is simply a wrong call to a real built-in. The emitter's table is keyed by name
*and arity* (C-18), so a known name at an unknown count matched nothing and fell
through to the catch-all refusal.

⚠️ **Found while fixing C-33, and deliberately not fixed with it.** The obvious
move there — treat everything reaching the catch-all as an undefined name —
would have made this *worse*, answering `Undefined variable 'Length'.` for a
name the language defines. C-33 was narrowed to the three assertion names
instead.

⚠️ **The counts are asked of the tables, not listed again.** `BuiltinCounts`
probes the two tables that map a name to its runtime entry point, once per
count, so a built-in added to either is described the moment it is added. A
fifth transcription of those names is exactly the rot [COL-003]'s
matrix already needs a harness to guard against.

⚠️ **And the same key hid a missing feature.** `WriteLn ()` — the newline on its
own — had no mapping at all, because only `WriteLn/1` was in the table. A valid
program with no compiled form, which is what C-1 was and which this back end is
supposed to have none of.

**C-37 — A built-in member printed without being called reads differently.**
***Withdrawn.***
*(refers to [TYP-012])*

| | |
| --- | --- |
| Interpreted | `WriteLn (L.Sort)` was `CollectionMethod instance` |
| Compiled | `<fn Sort>` |

⚠️ **The interpreter was the one that was wrong here**, as in C-4 — and it is
the interpreter that changed. `CollectionMethod` names a class that exists only
inside `algc`; a program has no way to know it and nothing in the language
answers to it. A bound *method* prints `<fn Name>` [TYP-012], and a bound
built-in member is the same kind of thing.

⚠️ **The obstacle was the spelling, not the hook.** The three wrappers carried
the member name **folded**, because their tables are written folded to meet a
folded lookup [SRC-011], so the obvious `ToString` would have given `<fn sort>`.
They carry the **token** now: dispatch folds it, and the diagnostic reads the
lexeme, which needs no second table.

⚠️ **And the spelling is the call site's, on both sides.** A built-in member has
no declaration in the language to take a canonical spelling from — a bound
method prints the name its *declaration* used, and a member table is not a
declaration — so the only spelling the two processors can agree on is the one
the program wrote. `L.SORT` is `<fn SORT>` through both. The C runtime had
stored the table's spelling instead, on a stated worry about lifetime that was
unfounded: a call-site name is a string literal in the emitted C.

    conformance  0149-a-built-in-member-as-a-value.a24

**C-38 — A function declared inside a method will not compile.**
***Withdrawn.***
*(refers to [FUN-012], [CLS-011])*

```
A function declared inside a method is not supported by the C back end yet.
```

A method's body is a body like any other, so a function may be declared in one
and closes over what it can see there — which runs interpreted and is refused
compiled.

⚠️ **Split out of C-2 rather than fixed with it**, because it is a different
thing. C-2 was one missing shape in an existing mechanism; this needs a new one.
A method's C function takes a receiver and **no cell array**, so a body that
boxes has nowhere to put its cells, and a nested function there closes over
`this` as well as over the locals: `conformance/0148` reads a field bare, writes
one through `this`, and the write sticks.

⚠️ **Three pieces, and two were already written.** A method body boxes what a
nested function reads exactly as a function body does — the analysis existed and
was simply not called there. The **receiver joins the cells**, under the name the
language uses for it, because a nested function reading a field reaches it
through `this`. And every emission of the receiver goes through one place now,
which answers `v_this` in a method and reads the cell in a function nested
inside one.

⚠️ **`v_this` is a parameter, and that is the whole difficulty.** A method's C
function takes a receiver; a nested function takes cells and has no such
parameter. Writing `v_this` unconditionally is what made the shape unemittable,
and the five sites that wrote it — a field read, a field write, a bare method
call, `super`, and `this` itself — all had to ask instead.

A closure that escapes a method keeps its receiver: `C.Make (3)` hands back a
function that goes on mutating `C`'s field, and a second `Counter` gets its own.


**C-39 — `super` as a value will not compile.**
***Withdrawn.***
*(refers to [CLS-012], [CLS-011])*

```
'super' as a value is not supported by the C back end yet.
```

`var Parent := super.Speak;` runs interpreted and was refused compiled.

⚠️ **Found by the gate on the day it was tightened**, not by looking for it. The
generation bar became "every case passes under both processors", `conform.sh`
was changed to fail on a gap rather than report one, and the first thing needed
was a case that would prove the new gate bites. `super` as a value was the only
refusal still reachable — the other two the emitter names are refused by the
*parser* first, in both processors — so it served as the fixture and turned out
to be real work.

⚠️ **The refusal was older than the mechanism it needed.** `alg_invoke_from`
already searched from the declaring class, and `alg_bound` already bound a
method to a receiver; `alg_bound_from` is the two of them in one call. The
spelling had simply never been reached, because nothing in `compiler/*.a24`
holds `super.M` as a value.

> **A note on DEF-13, which this annex got wrong.** Its entry said the fix was
> blocked on "a registry of declared type names that does not exist —
> `Lookup.Parents` holds only classes that *have* a superclass, and enumerations
> are not tracked at all." `Parents` is the **inheritance** map and was never the
> registry. `Types` is, and all three declaring forms populate it: `ClassStmt`,
> `ObjectStmt` and `EnumStmt` each register their own name. The checker already
> refused `var E : Nonexistent := 1;` on that basis. The defect sat deferred
> through five waves on a misreading of which map to look at, and the fix came to
> three lines of registration and one check.
>
> ⚠️ The lesson is about *where* a blocker is recorded. "Blocked on machinery
> that does not exist" is a claim about the code, and it goes stale — or is wrong
> from the start — exactly like any other comment. It deserves the same
> re-checking as a `⚠️` before it is trusted a second time.

---

## Annex D — advisory notes *(non-normative)*

Where the specified behavior looks like a mistake. Nothing here weakens the
rule it refers to: the body states what the language does, and this annex
argues about it. Entries are added as the chapters that expose them are
written.

**D-1 — Integer overflow is silent.** *(refers to [LEX-018])*

**Resolved, and then resolved again.** The specification first required an
out-of-range literal to be refused when the program is read and an out-of-range
arithmetic result to raise. The two were separated because they cost
differently: a literal is checked once during the scan, while an arithmetic
result must be checked on every operation a program performs.

⚠️ **Both halves are now moot**, because [LEX-018] makes an Integer unbounded:
there is no range for a literal to be outside of, and no result to refuse. The
literal rule was deleted and the scanner's text comparison with it. What began
as "make the wrap an error" ended as "have no wrap" — the second answer is the
one a reader needs nothing else to understand.

⚠️ "What C does natively" was the wrong way to put it, and this note said it:
signed overflow in C is *undefined behavior*, not a wrap. The runtime had
always computed through the builtins to avoid that, so what it produced was a
defined wrap — and the same branch that reported it now decides to promote.

**D-2 — `?` alone is a valid identifier.** *(refers to [LEX-008])*

**Resolved.** `?` and `!` are identifier *marks* rather than letters [SRC-005]:
they continue an identifier and may not begin one [LEX-008], so `Gate?` and
`Send!` are single words while `?` and `!` alone are not identifiers at all.

The implementation classed `?` as a letter, so it led; and it did not admit `!`
in an identifier at all. Tracked by DEF-03, and fixed there: `Gate?` and `Send!`
are words, and `?bad` is `Unexpected character: ?`.

**D-3 — `#0` is constructible but unstorable.** *(refers to [LEX-032])*

**Resolved by refusing it.** `#0` is not a Char [LEX-032], and is refused when
the program is read exactly as an out-of-range code point is [LEX-025]. That is
the smaller of the two available fixes and matches a check the scanner already
performs.

The larger fix — giving a String an explicit length so it can hold a zero
character — remains the better language, and [SRC-001] already obliges a String
to carry a character count distinct from its byte length, so the two changes
meet. [LEX-032] is worded so that adopting it later relaxes a restriction
rather than reversing a guarantee. Tracked by DEF-08.

⚠️ **The larger fix landed anyway.** A String carries its own byte length now,
so `'a' + Str (Char (0)) + 'b'` is three characters long, prints as three and
compares equal to itself. Only the **literal** `#0` is still refused, which is
what [LEX-032] says and all it says.

**D-4 — Widening is refused as firmly as narrowing.** *(refers to [VAR-004])*

`var X : Integer := 1.5;` should certainly be refused: the value does not fit.
But `var X : Double := 1;` is refused on the same terms, and there the value
fits exactly and every arithmetic operation in the language already promotes an
Integer to a Double when the two meet. A programmer who writes `: Double` and
initializes with `0` is told the types do not match.

**Resolved, and generalized.** Widening follows Pascal: Integer to Double and
Char to String, at any of the six assignment contexts [VAR-017], converting at
the point the value arrives. The open question — whether `X` then holds a Double
or an Integer a declaration lied about — is answered explicitly: it holds a
Double [VAR-004]. Narrowing stays refused [VAR-018]. **Implemented.**

⚠️ **Why this is a defect and not a later generation.** The question was asked
directly, and the answer turns on whether the language *lacks* widening or *has
it inconsistently*. It has it: `1 + 1.5` is `2.5` and `'a' + 'bc'` is `abc`
today. Only the paths carrying a written type refuse, so a declared type means
something narrower than the operators do. An absent facility goes to Annex H —
H-1's alternate bases are absent, with nothing in the language to be
inconsistent with. One path disagreeing with the rest of the same language is a
fault.

⚠️ Equality was deliberately left out. Pascal converts in comparisons too, which
would make `Copy('abc', 0, 1) = 'a'` true and reverse [LEX-026] — the one part
of this that changes what an existing program *means* rather than accepting a
program that was refused. It belongs with D-6, in the chapter that specifies
`=`.

**D-5 — `const` promises less than it appears to.** *(refers to [VAR-014])*

`const C := V;` is legal where `V` is a variable, so a constant's value need not
be known before the program runs. The word means only that the binding cannot
be reassigned. A reader who takes `const` to mean a compile-time constant — as
Pascal's does, and as most languages' do — will be wrong about when the
initializer runs and about what the compiler can assume.

**Resolved by keeping it.** The run-time form is genuinely useful for a value
computed once at startup, and nothing here is broken — the word means *this
binding may not be reassigned*, which [VAR-014] now states plainly rather than
leaving to be inferred. A true compile-time constant, if one is ever wanted,
needs a different word rather than a narrowing of this one.

**D-6 — Equality and membership disagree.** *(refers to [VAL-009], [VAL-013])*

`1 = 1.0` is true, and `1 in [1.0]` is false. A Map holding the key `1` does not
contain `1.0`. Each rule is defensible alone — `=` promotes because arithmetic
does, and membership is strict because a hash table cannot be built over a
relation that promotes — but together they mean a program can hold two values it
calls equal and find only one of them in a collection.

`bootstrap/algol.c` already names this a rough edge in its own comments, which
is a fair sign it was noticed and not resolved.

**Resolved in favour of `=`.** Membership and equality are one relation
[VAL-013], paid for by hashing an Integer and a Double of the same numeric value
to the same bucket. Making `=` strict instead would have been the far larger
change and would surprise every program doing ordinary arithmetic.

⚠️ The reason the two diverged is worth keeping: `=` promotes because arithmetic
does, and membership was strict because a hash table cannot be built over a
promoting relation. The second is a statement about the implementation and the
first about the language, which is what decided it.

**Implemented.** `strict_equals` promotes and `hash_value` brings both numeric
types to one slot.

**D-7 — `as` is an unchecked assertion.** *(refers to [VAL-007])*

`X as Integer` where `X` holds `'text'` yields `'text'` and raises nothing. The
cast silences the checker and is never verified, so the one construct a
programmer reaches for when they know more than the checker does is also the one
that cannot tell them when they are wrong.

**Resolved, and done.** `as` is a checked conversion and raises when the value
is not of the named type [VAL-007]. The cost falls only on programs that use `as`, which
are the programs that asked for the assurance, and a cast that cannot fail is
not an assurance at all.

⚠️ This decision is what makes [VAR-006] tenable. `as` is the only way a value
crosses from untyped into typed, so the strictness there is only reasonable if
the crossing is verified; an unchecked cast would have made the boundary a
formality and every declared type beyond it a claim nothing had checked. The two
rules were decided together and neither stands alone. Both are now implemented.

**D-8 — Empty is truthy.** *(refers to [VAL-008])*

`0` is falsey, but `0.0`, `''`, `[]` and `[:]` are all truthy. So
`if not S then` does not mean what a reader coming from most languages will
expect it to mean, and `if S.Length = 0 then` is the only reliable spelling.

The rule is at least short to state, and it makes truthiness independent of a
value's contents — a collection is a thing, and a thing is there.

**Resolved by keeping it.** [VAL-008] now states plainly that truthiness is
independent of a value's contents, and that `if S.Length = 0 then` is the only
spelling that tests emptiness.

⚠️ The observation still stands and is **not scheduled**: Integer `0` is the odd
one out, and were it truthy the rule would reduce to the genuinely simple "only
`nil` and `False` are false". That changes what existing programs mean rather
than admitting programs that were refused, so it belongs to neither annex until
someone decides to take it — recorded here so the option is not lost.

**D-9 — Visibility is advisory.** *(refers to [DCL-015])*

`private:` is checked by the type checker, and only where the receiver's type is
known. `var C : Any := Counter(); C.Count` yields the private field and raises
nothing. A subclass reading its parent's private member by bare name gets it,
because a bare name inside a method resolves through `this`, and `this` reduces
to no type at all — while the same member through a receiver declared as the
parent is correctly refused.

So the guarantee is real for code that annotates its types and absent for code
that does not, which is the opposite of where a guarantee is most wanted. It is
also not a security property and was never meant to be: the checker is advisory
by design in a gradually typed language.

⚠️ Any fix collides with a deliberate decision recorded in the checker: `this`
reduces to nothing precisely so that a class's own code is free of the
visibility rule. Typing `this` as its class would make the bare-name case work
and would also make every `this.Private` inside a subclass an error the language
currently allows.

**Resolved by saying so plainly.** [DCL-015] now states normatively that
`private:` is advisory — an intention that buys a diagnostic wherever types are
written, and not a boundary a program may rely on.

⚠️ The alternative was enforcing it at run time on the instance, where the class
is always known. That closes the hole completely and was the earlier
recommendation here, but it puts a check on **every property access** — which is
the cost the whole type-system direction of this specification exists to avoid.
[VAR-006] tightened declarations so the C back end could trust a declared type
and emit without runtime checks; paying one back here, on the most frequent
operation a program performs, would trade away more than it buys.

Nothing is lost that was ever really held: the guarantee was already absent
whenever a type was omitted, and the change is to stop implying otherwise.

**D-10 — Integer division by zero raises; Double division by zero does not.**
*(refers to [EXP-006])*

`1 / 0` is the runtime error `Division by zero.` `1.0 / 0` is `Infinity`, and
`0.0 / 0` is `NaN`, and neither stops the program. So whether dividing by zero
is a bug or a value depends on which numeric type reached the operator — and
[EXP-005] means an Integer becomes a Double whenever it meets one, so the same
expression can change category with an edit far from it.

The Double behavior is IEEE 754 and is what C does for free; the Integer
behavior has no such answer available, since there is no integer infinity to
produce.

**Resolved by keeping both.** [EXP-006] now states the asymmetry as a rule
rather than leaving it to be discovered, and says why: each behavior is correct
for its own type. Raising on Double division would depart from IEEE 754 for no
gain, and returning a value for Integer division would have to invent one, since
there is no integer infinity.

⚠️ The genuinely surprising part is not the asymmetry but its reach: [EXP-005]
promotes an Integer whenever it meets a Double, so an edit far from a division
can move it from the raising category to the value-producing one. That is
recorded in the rule.

**D-11 — A parameter's declared type is decoration on a function and a contract
on a method.** *(refers to [FUN-006], [FUN-007])*

`function F(N : Integer)` accepts a String, a Double or a Boolean without
complaint. The same signature as a method refuses all three with `No matching
signature for function.` Nothing in the language says the two differ, and the
annotation looks identical in both places.

The cause is structural rather than deliberate: a method goes through overload
selection, which compares whole signatures, and a top-level function does not
overload [see 8.3] so nothing ever compares its parameters. Only the arity is
checked.

⚠️ Note the direction of the surprise. A declared return type IS enforced
[FUN-008], so within one declaration the result is checked and the arguments are
not — which is the reverse of what a reader would guess, since arguments come
from outside and are the less trustworthy of the two.

**Resolved.** [FUN-006] requires parameter types to be enforced on every call,
top-level subprogram or method alike. The check already existed in `Fits`; what
was missing was calling it when there is nothing to select between. Tracked by
DEF-19, and fixed there.

⚠️ This was not really an open question by the time it was reached: [VAR-017]
had already listed a parameter as one of the six assignment contexts, so
[FUN-006] as written contradicted a decided rule. The direction-of-surprise
note above still stands and is worth keeping — a declared *return* type is
checked while the arguments are not, which is the reverse of what a reader would
guess.

**D-12 — Inheriting from a non-class reports the wrong thing.**
*(refers to [CLS-014])*

```
var X := 1;
class C (X);
begin
end
```

fails with `Only instances have properties.` — a sentence naming neither the
class, nor the superclass, nor inheritance, and describing a property access the
program never wrote. The message belongs to the machinery rather than to the
mistake.

⚠️ **Corrected.** This entry previously said the check happens where the
superclass is *used* rather than where it is declared. It does not: the
declaration above is refused even when the class is never constructed. Only the
wording is at fault, which makes this smaller than it was recorded as being —
and is why it was worth running rather than reasoning about.

Diagnostics are part of the observable surface [1.2], so this is a specified
behavior and not merely a rough edge — a conforming implementation must
reproduce the misleading sentence exactly.

**Resolved.** [CLS-014] requires the shape the other inheritance errors already
use — `'X' is not a class.`, beside `A class can't inherit from itself.` The
check already happens in the right place, so this is a message and nothing else.
Done: `VisitClassStmt` tests the superclass with `is` rather than asking it for
a property, so the comparison meant to reject it is now reached.

**D-13 — Truthiness reads a value a program cannot.** *(refers to [ENU-009],
[ENU-010])*

The first member of every enumeration is falsey, because truthiness reads the
member's ordinal — and the ordinal is not reachable from the language. `RED` is
false and `GREEN` is true, and a program can discover which is which only by
testing each for truth.

So `if Color then` depends on where a member sits in a list that the program
cannot inspect, and reordering an enumeration's members silently changes the
truth of every conditional written over it. Nothing warns, because nothing
about the declaration looks conditional.

The rule exists so that enumerations behave like the small integers they are
represented by, which is a real convention and not an accident.

**Resolved, in both halves and in opposite directions.**

[ENU-010] requires a member to answer `Ordinal`, its zero-based position, so the
value that governs the behavior can be read and compared. `Ordinal` already
existed on the implementation's own class and simply was not published. Done.

[ENU-009] is **kept**, and stated as a feature rather than tolerated as a
quirk — position-based truthiness is what makes `(Off, On)` and `(No, Yes)`
usable directly in a condition. The entry below records the reasoning, which
began as an argument for changing it and ended as the argument for keeping it.

⚠️ **[ENU-009] is settled: it stays.** The case against it was: an enumeration member is not a number, nothing else in the language makes a
declared name falsey by position, and reordering an enumeration silently changes
the truth of every conditional written over it.

⚠️ **The case for it is stronger, and was missed when this entry was written.**
Position-based truthiness is what lets a program declare its own two-valued
types and use them directly in a condition:

```
type Flag   = (Off, On);
type Answer = (No, Yes);
```

`if F then` reads correctly for both, with no comparison and no conversion. The
convention that falls out — put the absent, off or zero member first — is
already the one this compiler follows in `FUN_NONE` and `CLASS_NONE`. Under that
reading the rule is a feature with a discipline attached, not a trap, and the
discipline is the same one a `case` statement already asks for.

⚠️ **And the original complaint is half answered.** This entry's title says
truthiness reads a value a program *cannot* — but [ENU-010] now requires the
ordinal to be readable. Position-based truthiness over a *visible* position is a
stated rule rather than hidden machinery, which is most of what was wrong with
it.

⚠️ **A further prospect, TABLED and separable: it could remove the built-in
Boolean**, leaving `type Boolean = (False, True)` as an ordinary enumeration.
This is not decided and is not scheduled. Two costs argue for keeping the two
questions apart:

- **[ENU-011] collides with it.** Members bind bare, so any program declaring an
  enumeration with a `True`, `False`, `Yes` or `No` member would make that bare
  name ambiguous — and those names appear in almost every program. Boolean would
  have to be exempt from the ambiguity rule, which is a special case
  reintroduced one level down.
- **Representation.** `VAL_BOOL` is a distinct runtime tag while an enumeration
  member is an interned object, so this puts an indirection on the most common
  value a program has. That runs against the reason [VAR-006] was tightened.

`true` and `false` are also keywords [LEX-010], which would drop from 37 to 35.

Changing it would reverse part of [VAL-008], which the conformance pass decided
in chapter 7, so it is recorded here rather than taken unilaterally. Evidence
gathered for whoever decides: the compiler's own two enumerations are compared
explicitly at all five of their use sites — `if CurrentFunction = FUN_NONE then`
— and never tested for truth bare, so the change is safe against the largest
body of Algol-24 that exists.

**D-14 — Circular imports fail, and say something else.** *(refers to
[MOD-012])*

⚠️ **This entry was largely wrong, and running it is what showed that.** It said
a cycle between two modules fails with `Type mismatch!` It does not: cycles
between modules **work**, and so do cycles of three or more [MOD-012].

The `Type mismatch!` came from the probe's own fixtures, which returned `'A'`
and `'B'` from functions declared `: String`. A one-character literal is a Char
[LEX-023], so those functions failed whether or not any cycle existed — the
recording was evidence of DEF-10 and was read as evidence about modules. The
fixtures now return two-character strings and the probe records `Ay`.

What remains true is the **root** case [MOD-014]: a module importing the file
being run leaves the root's own imported names undefined, after the root's body
has already printed. Compiled, the same shape used to refuse with `Two modules
named 'X'` (C-1) — closed by giving the root a module identity, which is what
[MOD-014] asks for and what the fix below describes.

So there is one shape of problem rather than three, and it is the one this
repository already knew about — the root is never entered in the loader's map,
so it is parsed twice.

**Resolved.** [MOD-012] states that cycles between modules work, which they do.
[MOD-014] requires the root case to work the same way; DEF-24 tracked the
distance and closed it.

The fix is to give the root a module identity, so a `uses` pointing back at it
resolves to the copy already loaded — what [MOD-003] does for every other file
and what makes [MOD-012] work. That is more than a guard: an import-only node
carries no statements, and the importer genuinely needs the root's exports, so
the root must be registered with its environment **before its own body runs**.

Refusing the root cycle by name would be an improvement on the present
diagnostic and is much the smaller change, but it settles for less than
[MOD-014] asks.

⚠️ **Not hypothetical for this repository, and narrower than it once read.**
`compiler/Parser.a24` uses `Interpreter`, which uses `Parser` — a cycle between
two modules, which works, interpreted and compiled alike. The compiler compiles
itself and reaches a fixed point.

What fails is making a file in that cycle the **root**:
`algc --compile compiler/Parser.a24` refuses with `Two modules named 'Parser' is
not supported by the C back end yet.` [Annex C, C-1]. `compiler/Main.a24` is
unaffected because nothing imports it, which is why the whole suite compiles.
An earlier version of this entry said the compiler's own source could not be
compiled by itself; that was wrong.

**D-15 — Two different things are spelled `Length`.** *(refers to [RT-003])*

```
var L := [10, 20, 30];
L.Length      →  3
Length(L)     → 12
```

The property answers the collection's count. The function stringifies its
argument and measures the text, so `Length(L)` is the length of `[10, 20, 30]`.
`LengthNative` is literally `Exit Length(Str(Arguments[0]))`.

⚠️ The failure mode is the bad one: the wrong call returns a **plausible
number** rather than an error. A program asking `Length(L)` of a collection gets
an answer, uses it, and is wrong.

⚠️ **Corrected.** This entry claimed the two coincide for small lists of
one-digit numbers before diverging. They never coincide: a List of *n* one-digit
numbers renders as `[1, 2, 3]`, which is `3n` characters, against a count of
*n* — so `0/2`, `1/3`, `2/6`, `3/9`. The claim was plausible and wrong, and the
rule is no weaker without it.

The function is right for its intended argument. `Length('abc')` is 3, which is
what a Pascal programmer expects, and the collection property is right too. Only
the shared name is wrong.

**Resolved.** [RT-003] refuses `Length` of a collection —
`Length expects text; use .Length for a collection.` A program that means the
count says so, and one that means the rendering writes `Length(Str(L))`, which
is what it was getting by accident. Done.

⚠️ Verified safe against the largest body of Algol-24 that exists: every
`Length(…)` call in `compiler/*.a24` is on text.

⚠️ [RT-017] closes the other half of the confusion by giving a String the same
`.Length` property every collection has, so `.Length` becomes the uniform
spelling for "how many" and `Length(…)` is left meaning only "how long is this
text".

**D-16 — `Val` always yields a Double, and `Max` never accepts one.** *(refers
to [RT-009], [RT-010])*

`Val('42')` is `42.0`, not `42`, so text that plainly holds an integer cannot be
parsed into one — and the result then cannot be passed to `Max`, which refuses
anything but Integers with `Max expects Integers.` The two built-ins are
individually defensible and jointly unusable: `Max(Val(A), Val(B))` fails for
every input.

Given [VAR-004], which refuses `var X : Integer := 1.5;` and even
`var X : Double := 1;`, a program has no smooth path from parsed text to an
Integer at all.

**Resolved, both halves.** [RT-009] makes `Val` answer an Integer where the
text has no point and a Double where it has one, reading the same characters the
literal rules do [LEX-015], [LEX-020]. [RT-010] lets `Max` take any two numbers,
promoting as every other numeric operator does [EXP-005] — and `Max` has since
left the core for `lib/Core`, so what fixed this is library code now.

⚠️ They are **one** defect, DEF-27, rather than two. Either change alone helps,
but only both together make `Max(Val(A), Val(B))` — which failed for every input
— work at all.

**D-17 — A type error says only "Type mismatch!"** *(refers to [ERR-006])*

Every mismatch the checker finds produces the same five words, with no file, no
line, no token and neither of the types involved. In a seven-line program the
diagnostic is:

```
Uncaught: Type mismatch!
```

and nothing else. The parser and resolver, by contrast, print the file, the
line, the source text and a caret under the offending token [ERR-005] — so the
machinery for a good diagnostic already exists, is already used two phases
earlier, and the checker simply does not reach for it.

⚠️ This compounds with [ERR-002]: because a type error stops the program before
any statement runs, a programmer gets no output to orient by either. The message
is the only information available, and it carries none.

⚠️ And with [FUN-006]: a parameter's declared type is unenforced, so mismatches
surface in fewer places than a reader expects — which makes the ones that do
surface harder to locate, not easier.

**Resolved.** [ERR-006] now requires the three-line excerpt a parse error
carries [ERR-005] and both type names — `Expected Integer, found String.` The
token is in hand at every one of the five sites that raise this, so the
information is discarded rather than absent, and `Console.Error` already
produces the shape two phases earlier.

⚠️ **Done.** [ERR-006] is implemented: all five sites report through
`Console.Error` with the offending token and both type names. It was the
cheapest improvement in this annex and the first taken, because every later
generation-1 fix produces type errors while it is being debugged.

⚠️ One refinement the implementation forced, recorded rather than quietly made:
this entry's example put the caret under the offending *value*. A literal
carries no token, so the caret names the declaration instead — reaching the
value would mean giving every expression a token, which is a change to
`Expr.a24` and the parser for a caret the message already makes unnecessary.

**D-18 — `AssertTrue` reports a comparison it did not make.** *(refers to
[TST-012])*

`AssertTrue(False)` fails with:

```
Assertion 'left = right' failed.
```

There is no left and no right. The message belongs to `AssertEqual`, which
appends `Expected 'E' but got 'A'.` to the same stem, and `AssertTrue` reuses
the stem and supplies no operands — so the reader is told an equality failed
when a truth test did, and given nothing about what was actually false.

`Fail(M)` produces `Failed.  M`, with two spaces, which is a third shape again.

**Resolved, and further than recommended.** The phantom stem goes from *every*
form, not only from `AssertTrue`: `'left = right'` names operands that no
message ever fills in, and reads like a template left unfinished. [TST-012] now
specifies `Assertion failed.` followed by two spaces and a clause that carries
the actual values — `Expected true but got 'V'.` for `AssertTrue`, and
`Expected 'E' but got 'A'.` for `AssertEqual`. Tracked by DEF-30.

⚠️ The type-naming form was **missing from the table entirely** and is kept: a
`Char` and a `String` both render as `3`, so a message quoting only the rendered
values would read `Expected '3' but got '3'.` Both processors already produce
it. Documenting it was as valuable as fixing the stem.

⚠️ Any change here alters the report, which [TST-008] specifies and which both
processors must reproduce byte for byte — so it is a change to the observable
surface and to `bootstrap/algol.c` in the same breath, not a cosmetic edit.

---

## Annex E — what could be written in Algol-24 itself *(non-normative)*

The collections and the built-in functions are native today. This annex asked,
for each, whether it is native because it *must* be or only because it always
has been — and what one feature would have to be added to unbind it.

⚠️ **Every feature it asked for has landed**, in Generations 5 through 8:
iteration [TYP-011], a read-only property [CLS-017], subscripting [TYP-010],
ordering [VAL-014], arithmetic [EXP-020] and element types on insertion
[VAR-016]. The survey's question is answered, and the answer is that nothing in
the language pins them.

⚠️ **The intent changed shape, and this annex no longer states it.** It said the
collections would be **moved** out. Annex H, H-9 now proposes a
second implementation **beside** the native ones, written in Algol-24 and built
on `Array`, with the compiler rewritten onto it and the natives retiring only
once that is proven — so nothing breaks at any step, and a library
implementation is free to offer a contract the core does not, such as a `Map`
that does not pay for [COL-007]'s insertion order.

⚠️ **And it is library work rather than language work**, which decides how it is
tested: `conformance/` and `refusals/` pin the language, so a library written
*in* the language is unit-tested and documented on its own instead.

The reason is the one below, and it is worth more than the tidiness: anything
written in Algol-24 rather than in the runtime is one less thing the C back end
and the interpreter can disagree about — and Annex C ran to thirty-seven
entries, numbered to C-39, before every one of them was withdrawn.

⚠️ **Three rules did the pinning, and all three are gone.** A class can be
iterated as of Generation 5 [TYP-011], can expose a read-only property as of
Generation 6 [CLS-017], and can be subscripted as of Generation 7 [TYP-010] —
and it can order [VAL-014] and compute [EXP-020] besides. `conformance/0171`
ends with a `Stack` written in Algol-24 that is subscripted, iterated, ordered
and answers `Length` without parentheses. **Nothing in the language pins the
collections to being native any longer.**

⚠️ **And nothing outside the language pins them either**, which was the last
objection standing. This annex claimed a foreign function interface had to come
first — that a unit could only be a saving if it could reach what it needed
without the runtime growing a built-in for every call. It was wrong: what a
collections unit needs is **storage**, and the storage it needs is `Array`,
which this annex itself keeps native as "the primitive the others are built on".
A library implementation asks chapter 16 for nothing, so H-9 waits on nothing at
all — and the foreign function interface has since landed anyway [FUN-014],
which settles the objection from the other side too.

⚠️ **This paragraph has now been rewritten in three consecutive staleness
passes**, each time to remove one more thing from the list. That is worth
leaving on the record: an annex that argues from what the language *cannot* do
goes stale exactly as fast as the language improves.

### E.1 The collections

**Array — pinned, and rightly so.**

`Array` is fixed-size, indexed in constant time, and holds arbitrary values.
Nothing in the language can express that. `Buffer` stores bytes rather than
values; a linked structure of class instances gives O(n) access; and a class
cannot be subscripted in any case. It is the one collection that is genuinely
primitive.

*Recommendation:* keep it native, and treat it as the primitive the others are
built on rather than as one collection among five.

**Stack — unbound already, in all but syntax.**

A `Stack` is `Push`, `Pop`, `Peek` and a count over a sequence. It can be
written in Algol-24 today, in full, as a class holding a `List` — and has been:
`spec/probes/TYP-012-stack-and-set-in-algol24.a24` is a working one, beside a
`Set` whose membership test is a hand-written scan using no native `Contains`,
and a `Mod` built from arithmetic alone. All three behave as the built-ins do.

Nothing about it is primitive: no literal claims its name, no subscript is
needed, and its whole surface is method calls.

There is no visible difference left. `S.Length` reads without parentheses as
the built-in's does, now that a class may declare a `property` [CLS-017] — which
was the one thing this entry said it was waiting on.

*Recommendation:* the best first candidate for a library implementation, and it
waits on nothing — not on the language, and not on H-14 either. Written over an
`Array`, which stays, rather than over the native `List` it would stand beside:
a wrapper inherits the very contract an alternative exists to differ from.

**Set — writable today; would want hashing later.**

`Set` needs membership. Over a `List` with a linear scan it can be written
immediately, and the probe named above does exactly that. A hashed version is
also expressible: `Ord` yields a character's code point as an Integer —
`Ord('A')` is 65 — so a string hash can be computed in the language without
reaching for anything native.

Nothing pins it syntactically. `Set(L)` is an ordinary constructor call, not a
literal form.

*Recommendation:* movable, and the performance question is separable — ship the
linear version as a unit, hash it later if it matters.

**List — pinned by its literal, not by its behavior.**

A growable sequence over `Array`, doubling when full, is straightforward
Algol-24. What pins `List` is syntax: `[1, 2]` produces one, so the language
itself hands the name out. Subscripting [TYP-010] and `for … in` [TYP-011]
would also have to be lifted, or every use would read `L.Get(I)`.

*Recommendation:* unbinding this one is worth doing only if user-defined
subscript and iteration arrive first. Otherwise the unit is strictly worse to
use than the built-in it replaces.

**Map — pinned by its literal, doubly.**

`[:]` and `[k:v]` produce a Map, so the name is claimed the way `List`'s is,
and the natural `M[K]` needs [TYP-010] as well. The implementation itself is
ordinary: two sequences, or `Array` buckets with an `Ord`-based hash.

⚠️ Insertion order is specified behavior, not an accident of the
implementation, so any replacement must keep it.

*Recommendation:* same as `List`, and after it. The literal is the harder half:
a language that lets a unit claim `[:]` is a much larger language.

### E.2 The built-in functions

| Native | Could it be written in Algol-24? |
| --- | --- |
| `Max`, `Mod` | Yes, today, from arithmetic alone. |
| `Copy`, `Pos` | Yes, from `Length` and subscripting a String, at a cost in speed. |
| `Val` | Yes, given `Ord` for digits. |
| `Ord`, `Char` | No. They convert between a character and its code point, and nothing else reaches that representation. |
| `Length` | No, for `String`. A user type's own length is [TYP-012]. |
| `Str` | No. Rendering a `Double` in the specified shortest round-trip form needs the value's bits, which the language cannot see. |
| `clock`, `TextFile`, `FileExists` | Yes, now. `external` reaches `time`, `fopen` and `stat` directly [FUN-014]. |
| `Buffer` | Yes, now, over `malloc` and `free` — though `Address` [TYP-017] would have nothing to hand out but a `Pointer` it got from one. |
| `Write`, `WriteLn` | Yes, now, over `fputs` — but not their rendering, which is `Str`'s [RT-006]. |
| `ParamCount`, `ParamStr` | No. `argc` and `argv` are the runtime's, and a foreign call cannot ask for them. |

⚠️ **Three of those rows said "No. The operating system is not otherwise
reachable"** until Generation 8, and the sentence was true when it was written.
[FUN-014] is what made it false: a program that can declare `fopen` can write a
file handle of its own. The answers left are the ones where the obstacle is not
the operating system but this runtime's own state.

### E.3 The one feature that unbinds the most

Of the three pins, **[TYP-012], the missing getter, is the cheapest and buys the
most**. It is a declaration form rather than a semantic change; it makes `Stack`
and `Set` writable as units indistinguishable from the built-ins; and it is
needed by ordinary user classes regardless of whether any collection ever moves.

Subscript [TYP-010] is next, and iteration [TYP-011] after it — those two
together are what `List` and `Map` wait on, and both are larger changes, because
each means dispatching a language construct into user code.

---

---

## Annex H — planned for later generations *(non-normative)*

Changes intended for the language that are **not defects**. The implementation
is right about these; the specification describes the language as it now is, and
each of these will change a rule when it arrives.

⚠️ The distinction matters to the corpus. A defect gets a reverse conformance
test that passes while the wrong behavior persists. A planned change gets an
ordinary conformance test or refusal pinning the **current** rule, which turns
red when the generation lands — deliberately, because that is the moment the
rule changes and the test should change with it.

**H-1 — Other bases and digit separators.**
***Landed in Generation 3.*** *(changed [LEX-016])*

Hexadecimal, octal and binary integer literals, and a separator within a run of
digits. Now covered by `conformance/0006-integer-bases-and-separators.a24`; the
refusal that pinned the old rule went with the generation.

**H-2 — Exponent notation.**
***Landed in Generation 3.*** *(changed [LEX-022])*

A double literal with an exponent. Now covered by
`conformance/0007-exponent-notation.a24`.

⚠️ This one closed a genuine asymmetry rather than only adding a convenience:
`Str` **prints** a large Double in exponent form — `1.0E300` — and the language
could not read back what it wrote. Nothing was unreachable, because `Val` parses
the exponent form, but the round trip went through a built-in rather than
through the source.

**H-3 — Element types checked on insertion.**
***Landed in Generation 8.*** *(changed [VAR-016])*

`L.Add ('text')` on a `List of Integer` is refused, and so are the other four
routes in: `Push`, `Put`, subscript assignment, and the collection literal at a
declaration.

⚠️ **The entry's own warning was the design.** It said every route had to be
covered "or the check becomes a fence with a gate in it, which is worse than no
fence because it invites the declared type to be trusted". Five routes, five
refusal cases — one apiece, because the check is the type checker's and a
refused program never runs, so no single case can show two.

⚠️ **Checked where the receiver's type is known, and nowhere else**, at no
run-time cost — the bargain a property [CLS-017] and `private:` [DCL-015]
already make. The element type is available only for a plain name, which is the
same limit *reading* one has: there is nowhere to have written the element type
of an arbitrary expression.

⚠️ **It checks and does not convert.** `D.Add (2)` into a `List of Double` is
accepted and stores the Integer. Widening reaches a *written type* [VAR-004],
and an element is not one.

⚠️ **`conformance/0021` predicted its own change** and said so: "Insertion is
NOT checked… this is what H-3 would change." It changed it.

**H-4 — A subscript operator a class may declare.**
***Folded into H-15.*** *(will change [TYP-010])*

Subscripting turned out not to want an operator declaration at all: it is a
structural protocol, and landed as **H-15** in Generation 7.

⚠️ **The entry is kept for the record, not for a pointer.** It was kept at first
because [TYP-010] and [EXP-016] said "see Annex H, H-4"; both were rewritten
when H-15 landed and neither says it now. What it still earns its place for is
the history — this number was proposed as a *subscript operator*, folded into
operator overloading as "the same feature in a particular spelling", and finally
turned out to want no operator at all. A reader meeting the gap between H-3 and
H-5 should find out that a question was asked and answered differently, rather
than that a number was skipped.

**H-5 — An iteration protocol a class may implement.**
***Largely landed in Generation 5.*** *(changed [TYP-011], [CLS-009])*

A class declaring `Elements` taking no arguments is iterable, and always was —
the interpreter's `ElementsOf` and the runtime's `alg_iterable` both had it, in
agreement. What was missing was the **rule**, and an unspecified protocol had
already drifted: an `Elements` of the wrong arity failed differently in the two
processors, and a `Contains` of the wrong arity answered `1 in B` with **true**
interpreted while raising compiled — a wrong answer, not merely a wrong message.
[TYP-011] now states the protocol and both sides check the shape.

⚠️ **What is left is not iteration but its neighbors.** Two questions the
protocol raises and does not answer:

| | |
| --- | --- |
| A class that iterates like a `Map` | A built-in `Map` yields its **keys** [STM-007]. A class can return a list of keys, but has no way to say it is pair-shaped, so `for var K in M` and a user-written map cannot mean the same thing. |
| `Elements` returning `this` | The result is walked rather than re-asked, which stops the ordinary chain from recursing — but a class whose `Elements` answers itself recurses without bound in both processors. |

⚠️ **Membership has no rule of its own.** `Contains` on a class instance is
implemented in both processors and specified nowhere: [COL-012] governs the
*equality* membership uses, not the protocol that lets a class answer it. The
same paragraph [TYP-011] now carries for `Elements` is owed to `in`.

**H-6 — A read-only property a class may expose.**
***Landed in Generation 6.*** *(changed [TYP-012]; added [CLS-017], [CLS-018])*

`property Count : Integer; begin Exit Items.Length; end` — a member kind beside
`function` and `procedure`, read without parentheses, with the read being the
call. Assignment is refused where the receiver's type is known.

⚠️ **The need was a read-only view, not parentheses.** A field is public —
readable *and writable* — or private, meaning invisible, so a `Stack` written in
Algol-24 could not protect its own count while showing it, and was strictly
worse than the built-in whose `Length` cannot be assigned.

⚠️ **The runtime is told at the DECLARATION, not asked at the call.** Nothing at
a use site says whether `B.Count` is a field, a method or a property, and the
receiver's class is not known until run time — so `alg_class_property` marks the
member when the class is built and `alg_property` reads the mark.

⚠️ **The sigil half was withdrawn before any of this was built.** An earlier
shape made a bare `B.Length` on a method an error and introduced `@` to replace
it; that displaced a construct which works and is specified [FUN-011] in order
to free a spelling.

⚠️ **It found a divergence older than itself** [CLS-018]. Instances were open in
the interpreter and closed in the compiled back end — Lox's arrangement against
fixed slots — so `B.Undeclared := 1` was `1` interpreted and refused compiled.
No case covered it, and a unit test inherited from Lox was holding the
interpreter's half in place.

**H-7 — Ordering for Strings.**
***Landed in Generation 6.*** *(changed [VAL-014], [COL-013])*

`'ab' < 'cd'` was the runtime error `Operands must be numbers.`, so a program
needing to order text compared it character by character — which is what
`compiler/CEmitter.a24`'s `TextLess` did, a function the compiler wrote for
itself because the language did not provide the operator. `TextLess` is gone.

⚠️ **One change in the runtime served both processors.** The interpreter's
`VisitBinary` evaluates `Left < Right` in the host language, so interpreted `<`
*is* `alg_less` — the arrangement that makes interpreted `Length` and host
`Length` one function [RT-003]. Teaching the four comparison operators about
text gave the tree-walker the same ordering in the same commit, with nothing in
`Interpreter.a24` to change.

⚠️ **It uncovered an older fault than itself.** `Char` ordering compared
`a.string[0]` — the first **byte** of a UTF-8 encoding — so `'è'` and `'é'`
shared a lead byte and compared **equal**, while `Ord` answered 232 and 233. The
language disagreed with itself about which of two characters came first, in both
processors alike, and no case covered it because [VAL-014] never said how Chars
order.

⚠️ **And a second ordering nobody had noticed.** `Sort` compared with `strcmp`
[COL-013] — bytes rather than characters, stopping at an embedded zero a String
is entitled to hold. It agreed with the new operator only because UTF-8 is
designed so byte order matches code-point order, which is right by accident.
Both now go through one function.

**H-8 — Arithmetic operators a program may define.**
***Landed in Generation 7.*** *(added [EXP-020])*

`+`, `-`, `*`, `/`, `div` and unary `-` on a program's own type, declared
`operator + (Other : Money) : Money;`.

⚠️ **What is left of an entry that once claimed most of this annex.** It called
itself "the umbrella over much of Annex H"; H-6's property and H-7's ordering
landed in Generation 6 without it, and subscripting (H-15) and comparison
(H-16) landed in Generation 7 as **protocols**. Arithmetic was the only part
that wanted an operator declaration.

⚠️ **The one place a keyword beat a protocol, after five of them in a row.**
`Compare`, `Get` and `Put` are not translations of operators — `Compare` yields
four of them, `Get` and `Put` are two halves of one — while a `Plus` method
would be a pure synonym for `+`: a name added without a concept. Where the name
says something the symbol does not, the protocol wins; here it would not.

⚠️ **Adding the keyword broke the compiler's own source**, which is the hazard
this repository has met before: `Operator` was a local variable in
`Parser.a24`, sixteen times over, and became unspellable the moment the word
was reserved. The same collision renamed `Break` to `Broke` and Lox's
`Expr.Get.object` to `Obj`. The language's word wins and the compiler adapts.

⚠️ **The left operand decides**, as a receiver does everywhere else.
`Money * 3` is a Money; `3 * Money` is `Operands must be numbers.`

**H-9 — A collections library written in Algol-24.**
*(after v0.1.0; changes no rule)*

Collections written in Algol-24, **built on `Array`**, added **beside** the
native ones rather than replacing them. The compiler is then rewritten onto
them, and the natives retire only in a later generation once it is running on
the replacements — so nothing breaks at any step.

⚠️ **This entry used to propose moving chapter 14 out, and that was the wrong
shape.** Moving would break every program that says `Set ()` without a `uses`,
and force a choice between an import in every file and an implicitly-loaded
file that would make the language depend on something being on disk. Adding a
second implementation raises neither question.

⚠️ **The reason is more than tidiness: the core's contract is not the only
reasonable one.** [COL-007] pins insertion order for `Map` and `Set`, and pays
for it — `ObjMap` carries entries in insertion order *plus* a side index. A
library implementation may reasonably choose an unordered map with different
costs. That makes the library worth having whether or not the natives ever
retire, which the old framing did not.

⚠️ **Built on `Array`, never as a wrapper.** A wrapper around the native
collections inherits the very contract the alternative exists to differ from,
and buys nothing. `Array` is fixed-size, so growth is by doubling and copying —
the real thing.

⚠️ **`Array` has no consumer today.** The compiler constructs it nowhere, and
annotates it nowhere; the collection this annex calls "the primitive the others
are built on" is exercised only by the corpus. The library would be its first
real use, which is worth knowing before relying on it.

⚠️ **THIS IS LIBRARY WORK, NOT LANGUAGE WORK**, and the difference decides how
it is tested and where it is written down. `conformance/` and `refusals/` pin
**the language**; a library written *in* the language does not belong in either.
It gets **comprehensive unit tests**, one target per collection, and library
documentation of its own — not rules in this specification.

⚠️ **Nothing in the language is owed for it.** Iteration [TYP-011], a read-only
property [CLS-017], subscripting [TYP-010], ordering [VAL-014] and arithmetic
[EXP-020] all landed in Generations 5 through 7, and H-3 closed the element
types. A collection written in Algol-24 reads as the built-in does.

**H-10 — Varargs from an element type.**
***Landed in Generation 4.*** *(changed [FUN-005], [RT-001])*

A subprogram whose **last parameter is a `List of T`** may be called with the
elements written directly, and the call builds the list:

| written | means |
| --- | --- |
| `Log ('warn', 1, 2)` | `Log ('warn', [1, 2])` |
| `Log ('warn')` | `Log ('warn', [])` |

Both columns are legal, and the right-hand one wins where they meet.

⚠️ **No new syntax, and that is the design rather than an economy.** The
declaration already says `List of T` [VAR-008]; absorption is a *reading* of a
type that exists, not a marker added to it. It became possible only when element
types were admitted on parameters — before that a bare `List` carried no element
type, and the trailing arguments would have had nothing to be checked against.

⚠️ **"Fixed arity beats variadic" is not a rule here, it is the pass order.**
Selection is already two passes, exact before widening [EXP-014]. Absorption is
a third, so an exact match always wins and `Log ('warn', [1, 2])` passes the list
rather than absorbing it into a one-element one. The tiebreak that other
languages state in prose falls out of machinery this language already has.

⚠️ **The element type replaces the arity check and is stricter than it.**
`Log ('warn', 1, 2, 'red')` is still an error when the parameter is
`List of Integer`, because the stray argument fails the element type. What is
given up is given up only for `List of Any`, which is already the declaration
that means "anything".

⚠️ **Absorbing zero is what makes `WriteLn` ordinary**, and is the case that
decided it. `WriteLn` was a native of arity −1 with a hand-written branch on
`Arguments.Length = 0`; rendering the whole argument list gave `''` for none,
so the blank line stopped being a special case and `WriteLn ('ABC', 123)` —
which had not been legal — arrived with it [RT-015]. Requiring at least one
argument was considered and rejected on that example alone. The empty list is **structural, not a default**:
absorbing nothing yields `[]` by the same rule that absorbing three yields a
three-element list, so this is not default arguments under another name.

⚠️ **The cost is one list per call, and this runtime never frees one** — the
arena has no collector. The mitigation is expressible in the language and
changes no call site: declare a fixed overload beside the variadic one, and the
exact pass takes the hot calls without allocating.

    procedure WriteLn (S : String);           // exact pass -- builds nothing
    procedure WriteLn (Items : List of Any);  // absorption pass

**H-11 — Named arguments.**
***Landed in Generation 4.*** *(changed [EXP-013])*

An argument may name the parameter it fills — `Log (Level: 'warn', Items: [1])`.

⚠️ **The point is overload selection at compile time.** Selection is at run
time, from the values actually passed [FUN-013], because a declared type may be
`Any` and no static rule could reach the right overload from that. That is the
right default for a gradually typed language and it does not change. What is
missing is a way for a programmer who *does* know which overload they mean to
say so, and naming the parameters says it — a name identifies one signature,
where values only describe something several signatures might accept. Static
resolution becomes **available**, not mandatory.

⚠️ **`:` rather than `=>`, because the language already has this colon.**
`[k : v]` is a Map literal [COL-001]: a name on the left, a value on the right,
parsed by reading an expression and then looking for a colon. A named argument
means the same thing and parses the same way. `=>` would be a second punctuation
for a meaning already spelled.

⚠️ **The ambiguity that usually rules `:` out is absent here.** A colon in
expression position normally collides with a conditional expression's `? :`;
this language has no conditional expression, because `?` is an identifier mark
[LEX-008] and `Gate?` is one word. The `:` in `case … of` is a statement's.

⚠️ **Positional arguments first, named ones after.** A positional argument
following a named one is refused, as is a parameter supplied twice.

⚠️ **Which is also why H-10 needs no rule about the two meeting.** Absorption
takes trailing *positional* arguments, and positional arguments end exactly
where naming begins. `Log ('warn', Items: [1, 2])` names the absorbing parameter,
so nothing absorbs; `Log ('warn', 1, 2, Items: [3])` supplies it twice and is
caught by a rule named arguments need anyway. The two features share one rule
set, which is the argument for bringing them in one generation rather than two.

**H-12 — A warning for a call that binds at run time.**
***Landed in Generation 4.*** *(a diagnostic, not a rule)*

A third severity beside `[INFO]` and `[ERROR]` — **`[WARN]`, in yellow** —
reporting that a call selects among overloads at run time rather than
statically. Non-blocking: the program compiles and runs.

    [WARN] Main.a24:12: 'Log' selects among 3 overloads at run time.

⚠️ **It makes a cost visible without forbidding it.** Run-time selection is the
language's rule and stays so [FUN-013]; H-11 gives a programmer the means to
avoid it in a particular call. The warning is what connects the two — without it
the cost is real and invisible, and the remedy has nothing to point at.

⚠️ **It is silent on this compiler**, which is the evidence that it is a scalpel
and not noise: no top-level name in `compiler/*.a24` is overloaded, so over a
hundred kilobytes of Algol-24 raise no warning at all.

⚠️ **The corpus has to drop it, from both sides.** This entry predicted that
standard error would be the answer; it is not, because `Console` writes every
diagnostic this compiler produces — `[INFO]` and `[ERROR]` included — to
standard output, and `conform.sh` captures both streams anyway. The real
difficulty is the one the prediction was reaching for: the front end is shared,
so a warning appears when an interpreted program *runs* and when a compiled one
is *emitted*, which are different moments. `render()` therefore filters `[WARN]`
lines out of both sides before comparing.

⚠️ **Dropped rather than suppressed.** The warning is meant to be seen by
whoever is compiling; it is only the comparison that must not see it. A warning
that changed a program's recorded output would be a warning that changed the
program — and this one changes nothing, which is what *non-blocking* means.

⚠️ **The tag belongs in `Console.a24` beside the other two.** `ANSI_YELLOW` is
already defined there, and `WARN_TAG` follows `INFO_TAG` and `ERROR_TAG`
exactly — including the ⚠️ those two carry about their names: `WARN_TAG` rather
than `WARN`, because names are matched without regard to case [SRC-011] and a
`procedure Warn` beside it would be the same name.

**H-13 — Character arithmetic, the Pascal way.**
***Landed in Generation 6.*** *(changed [EXP-008], [RT-001]; added [EXP-019], [RT-020])*

`'z' - 'a'` is 25, `Succ` and `Pred` step an ordinal, and `'a' + 1` is refused.
Turbo Pascal's model with one departure: TP answers a distance with
`Ord (X) - Ord (Y)`, which stays available and says the same thing at greater
length.

⚠️ **Refusing `'a' + 1` was the repair, and the reason to do this.** `Str` is how
a Char widens to a String — that is why `Line ('{')` must be declared `Any` —
yet `'a' + 1` and `Str ('a') + 1` both gave `a1`, so in that one place widening
happened without being asked for and `Str` was decorative. The two differ now.

⚠️ **The C model was declined.** `'a' + 1` yielding `'b'` puts arithmetic on `+`
and makes the operator mean a step or a join depending on its right operand.
`Succ` costs one word, says what it does, and leaves `+` meaning one thing.

⚠️ **Breaking in the safer direction**, and the blast radius was measured before
the change: no `Char + Integer` appears anywhere in `compiler/*.a24`, and the
expression becomes an **error** rather than quietly computing something else.

⚠️ **An enum member is not stepped** [RT-020]. A member carries its type's name
and its ordinal rather than a pointer to the type, so there is no way from a
member to the list it belongs to — the gap is honest rather than chosen.

**H-14 — A foreign function interface.**
***Stages 1 and 2 landed in Generation 8.***
*(added [FUN-014], [TYP-017], [INI-008])*

A program declares a C function and calls it — scalars, `String` and `Pointer`,
with the library named or the running program searched. **SDL is the target**,
and a graphics library written in Algol-24 over it is the reason the entry
exists; stage 1 is what a window on screen needs.

⚠️ **The interpreter was never the difficulty**, which the entry once claimed.
The tree-walker cannot call C, but it runs *inside* `algc`, which is a C program
— so the marshalling lives in the runtime, the interpreter reaches it through a
built-in, and a compiled program calls it directly. Neither can drift from the
other because there is nothing to drift.

⚠️ **libffi, compiled in optionally** [INI-008]. The default build has neither
libffi nor `dlopen`, so the **bootstrap** still needs a C compiler and nothing
else — which is what that constraint has always been about. It is the language's
first configuration, and the corpus runs the default one.

⚠️ **`Pointer` is a type of its own, and renders without its address.** An
Integer would carry the address faithfully, and that is the objection rather
than a limitation: a handle should not be arithmetic'd. Printing the address
would make output depend on where the allocator put something — the
non-determinism the fixed-point check exists to catch.

⚠️ **Stage 2 needed one property, not a mechanism.** A `Buffer` answers
`Address` [TYP-017], so a program builds a C struct in bytes it owns and hands
the address over; `memcpy` writing `ABCD` into a Buffer that held `....` is the
whole proof. No struct-by-value marshalling, and nothing implicit — passing a
`Buffer` where a `Pointer` is declared would have taken its address silently.

⚠️ **What remains is stage 3: calling back into Algol-24.** SDL can mostly be
driven by a polling loop instead, so it may wait indefinitely.

⚠️ **Four keyword collisions in two generations.** `external` broke a field of
that name in `Stmt.a24`, as `operator` broke a local in `Parser.a24`, and as
`break` once forced `Broke`. Reserving a word makes it unspellable everywhere,
and this repository keeps relearning it.

**H-15 — Subscripting through `Get` and `Put`.**
***Landed in Generation 7.*** *(changed [TYP-010], [EXP-016])*

`B[0]` calls `B.Get (0)` and `B[0] := X` calls `B.Put (0, X)`. The fifth
structural protocol, needing no member name of its own — `Get` and `Put` are
what the built-in collections already answer to [COL-003].

⚠️ **It wanted no operator feature at all**, which is the change of mind this
entry records. It was H-4, folded into operator overloading as "the same feature
in a particular spelling"; asking what it actually added turned up one thing —
that it needs **two** members where every other operator needs one — and that
question answers itself the moment the two are ordinary members of different
arity.

⚠️ **A class declaring only `Get` is readable and not assignable**, and needs no
separate way of saying so.

⚠️ **This is what the protocol run was for.** A `Stack` written in Algol-24 is
now subscripted, iterated [TYP-011], ordered [VAL-014] and answers `Length`
without parentheses [CLS-017] — the four things Annex E named as pinning the
collections to being native. `conformance/0171` ends with one.

**H-16 — Ordering through `Compare`.**
***Landed in Generation 7.*** *(changed [VAL-014])*

A class declaring `Compare (Other) : Integer` orders with `<`, `<=`, `>` and
`>=`. The fourth structural protocol, needing no declaration keyword and raising
no precedence question, because `<` already has a precedence.

⚠️ **It cost nothing equality would**, which is why it is settled and H-17 is
not: ordering touches no hash and no membership, so no second protocol has to
move with it.

⚠️ **"And `Sort` gets it for free" was wrong**, and the entry said it before it
was built. `Sort` gets it free *compiled* — the interpreter delegates `Sort` to
the host's, whose values are `ObjInstance`, this compiler's own class rather
than the program's, so the host looks for `Compare` there and never finds it.
Answering compiled while refusing interpreted is the divergence the corpus
exists to catch, so the runtime's `Sort` does not ask either. Sorting by
`Compare` wants an interpreter inside `ObjCollection` and is its own work.

⚠️ **The interpreter could not delegate the operators either**, for the same
reason, and this is the fourth protocol to hit it — `Ord` on an enum member and
`Stringify` on a `ToString` were the first two. `VisitBinary` replaces the
operands with the `Compare` result and `0`, so the four comparisons below it run
unchanged rather than being written a second time.

**H-17 — Equality, and the hash that must come with it.**
*(will change [VAL-011], [VAL-013])*

A class deciding what `=` means for its instances. Today comparison is by
**identity** [VAL-011] with no way to say otherwise, so two values that are
alike are never equal.

⚠️ **The coupling is the whole difficulty, and it is a rule rather than an
implementation detail.** [VAL-013] states that membership and equality are one
relation: *if `X = Y` then a collection holding `Y` contains `X`*. A Map and a
Set bucket by a hash, and an object key hashes by its **address** — so the
moment two distinct instances compare equal, `A = B` is true while `B in [A]` is
false, and a specified rule is broken silently.

⚠️ **Which is exactly why Java pairs `equals` with `hashCode`**, and the
discipline is the argument *for* this feature rather than against it: the two
must move together, so a language that offers one must offer the other and say
so. Java cannot enforce the pairing either; what it does is make the obligation
explicit and famous.

⚠️ **The fixed point is NOT an obstacle, though it first looked like one.**
`ObjMap`'s index carries a warning that an address-keyed hash deciding iteration
order would make the fixed-point check fail intermittently — "the worst failure
mode this project has", and a bug already made once. Reading it again: it
describes a design that was **rejected**. Entries stay in insertion order and
nothing iterates the index, which is what makes the index legal. A user-defined
hash changes which bucket a key lands in and not the order anything is read in,
so the hazard is already neutralised structurally.

⚠️ **What it does need is both processors**, as ever: an interpreted `Equals`
and a compiled one, and a hash protocol in each, agreeing exactly. That is the
real size of the entry.
