# Code Review — Algol-24

First reviewed at commit `18b2e38` (2026-08-13). Re-reviewed after the
closure-capture fix (`dbe5d92`), then after the scan-error, `?`-identifier, and
symbol-constructor changes (`c102a2e`), then after `Buffer` (`ba465bd`), then
after the `Map` hash index and the refusal documentation (`e86c86f`).
**Re-reviewed again 2026-08-14** against the working tree, after **shadowable
built-ins and units** landed, and **again after the scope fixes** for C9–C12.
**Re-reviewed 2026-08-15** against the working tree at `99c01cb`, after the four
**hot-path fixes** in `bootstrap/algol.[ch]` that answer [D3](#d3).
macOS (arm64, Apple clang), and this round **also on Linux/glibc in a container**,
which is where the one new finding lives.

**Method.** Read `compiler/`, `bootstrap/algol.[ch]`, and the build/test
harnesses; emitted C for several programs and compiled it under `-std=c11 -Wall
-Wextra -O2`; wrote adversarial probe programs and ran them through both back
ends differentially; measured memory, stack frames, and dispatch cost.

This round the probes were aimed at **scope**, since that is what the change is
about: multi-file programs in which the shadowing declaration and the use of the
built-in are in *different* files, qualification across a `uses` chain, and each
of the precedence rules the new prose promises. I also rebuilt the pre-change
compiler from `HEAD`'s checked-in seed and diffed its emission against the
working tree's for the same program, so that "this used to work" is a
measurement rather than a reading of the diff.

Full `./test.sh` is green (`unit conformance compiled programs fixedpoint leaks
memory`; 8 suites both ways, 28 differential programs, 3 leak canaries, 3 memory
budgets), and `./build.sh` reports `seed: current` — the seed was regenerated
with the change, so `compiler/` and `bootstrap/` agree. All nine `JPascal` gates
(`gate ctest agate atest refuse leakcheck memcheck cgate fixedpoint`) pass, which
matters this round because `bootstrap/algol.[ch]` and
`JPascal/src/main/resources/runtime/algol.[ch]` are byte-identical — I diffed
them — so a runtime change is a change to both compilers at once.

**On the first pass the suite being green was the thing to be careful about.**
Every test the change originally shipped put the shadowing declaration and the
use of the shadowed name in **one file** — the case the rule got right. The case
it got wrong was two files, and nothing in the corpus looked at it. That gap is
now closed by `tests/programs/UnitScope.a24`, which is a three-file arrangement
built for exactly this.

**On the follow-up round** I re-ran every probe from the previous pass rather
than reading the diff for the fixes, kept the pre-change compiler around to keep
telling regressions apart from longstanding gaps, and swept the previously
verified behaviours to check none of them had moved. One new finding came out of
that sweep — [C13](#c13) — and it is pre-existing, confirmed by reproducing it on
the `e86c86f` compiler.

**This round is a performance change to the runtime, so the probes changed
shape.** A green suite proves the semantics did not move; it says nothing about
whether the numbers are real or whether the code is portable. So: the pre-change
compiler was rebuilt from `HEAD`'s seed and both were timed on the same machine;
the two emissions were diffed to check the claim that only one token changes;
`alg_stricmp` was compared against `strcasecmp` exhaustively over the byte range
rather than argued about; every write site of the new `MethodEntry.hash` was
enumerated; and **the whole bootstrap loop was run on Linux/glibc under
`gcc:14`**, which is where [C14](#c14) came from. Nothing on macOS can see it.

---

## Verdict

Well above typical hobby-compiler quality. The emitted C compiles clean under
`-Wall -Wextra -O2` with **zero warnings** — generated C usually fails this
badly — and the runtime handles C's undefined-behaviour corners deliberately
rather than accidentally, with comments saying *why* in each case. The testing
architecture (differential + conformance + byte-identical fixed point) is better
than a lot of production compilers.

**Since the first review:** C1 is fixed, and the fix went considerably further
than what I recommended — it found four additional defects of the same family
that I had not identified (see [C1](#c1)). One narrow case of the same class
remains ([C4](#c4)). The design items are unchanged; the runtime was not
touched.

**Since `dbe5d92`:** every open correctness finding is now closed. Scan errors
are reported ([H4](#h4)) — a genuine front-end divergence I had missed. `?`
identifiers are supported, and [H2](#h2) was resolved the other way from my
recommendation (keep the non-injective `_q` mapping and document it), which I
agree is the better call. [C5](#c5) is fixed structurally rather than
site-by-site: every C symbol is now built by a named constructor, so the class
of bug is gone rather than its nine instances. [C4](#c4) is refused by name
instead of fixed, on the discovery that the interpreter has no single answer to
reproduce. [H3](#h3) and the `bootstrap/build.sh` nit are gone.

**Since `c102a2e`:** [D1](#d1) — the highest-severity item on the board and the
one I expected to be deferred to project 3 — is **fixed**, and fixed by adding a
type rather than a collector. `Buffer` is in the runtime, the interpreter, the
emitter, the type checker, and the reference. The compiler now uses it for both
of its accumulation sites, and its own peak memory to compile itself went from
**1,252 MB to 82 MB**.

The diagnosis behind that fix corrects mine. I had located the cliff in
`CEmitter`, which builds every emitted file by `Text := Text + ...`. That was
real but secondary: **reading** a source file with `Result := Result + Line` cost
more than emitting one, and I never looked at `ReadWholeFile`. Measured
separately below — reading `CEmitter.a24` alone was 273 MB, and the naive read of
all 22 modules accounts for ~918 MB of the old 1,252 MB peak, about 73%.

**Since `ba465bd`:** [D2](#d2) is **fixed** — `Map` carries a hash index, and
`--test compiler/Main.a24` went from **11.71 s to 8.22 s**, within 0.02 s of what
the prototype predicted. [C2](#c2) is **fixed** too, by the route I recommended:
`ALGOL-24.md` gained a §9 tabulating every refusal. Both went further than I
asked. The index came with the `strict_equals` change I said had to come first,
which **closes a real divergence between the back ends** — `NaN` and `-0.0` as
collection members answered differently under `algc` and JPascal, and nothing
could see it. `Collections.a24` and `tests/programs/Maps.a24` now pin it. The
`Map.Remove` return value was fixed in the same pass (a `Map` answers with the
value removed, not a Boolean), which I had not found.

**And [C7](#c7) is fixed** — the one regression the `Map` index introduced, of
exactly the class [D1](#d1) had just closed. `map_reindex` reused its table, and
draining a 10,000-entry `Map` went back from **1,277 MB to 8 MB**.

**The more valuable half of that fix is the instrument.** `./test.sh memory` is
new: three programs, each carrying its own `/// MAXRSS:` budget. That closes the
gap that let both memory findings through — every other gate compares *output*,
and `leaks` compares *unreachable* memory, which is not the same question. I
verified this the hard way rather than taking it on trust: the broken build
allocates 1,279 MB and macOS `leaks --atExit`, pointed directly at it, still
reports **`0 leaks for 0 total leaked bytes`**. Nothing was leaked. Far too much
was allocated. Those are different failures and now have different instruments.

**Since `e86c86f` — shadowable built-ins and units.** This is the largest change
reviewed so far and the most ambitious: it adds a name-resolution rule to a
language that already had one, and it does it in four passes at once. The design
is right, and the part I would have expected to go wrong has not. In particular
the precedence rule — local, then a top-level name that can answer a dot, then a
unit — is implemented exactly as documented, both back ends agree on all three
tiers, and the observation that carries the whole feature (a bare class name has
never been able to answer a dot, so `Scanner.Scanner` is free) is correct.
[C6](#c6) is **fixed**, and fixed more thoroughly than I recommended: I asked for
`Classes.Contains` to move above the constructor block, and instead the built-in
tables moved *last*, behind everything the program binds, which closes the same
hole for functions and file-scope `var`s as well.

The first pass found the fix **scoped wrong** — shadowing applied program-wide
where the language scopes it per file, which turned working multi-file programs
into build failures ([C9](#c9)), with the same mistake in the type checker
([C10](#c10)).

**Since the scope fixes — all four are fixed, and verified against my own
repros rather than the new tests.** Every probe that failed now agrees across
back ends:

| | Before | After |
|---|---|---|
| [C9](#c9) cross-file function shadow | `cc` error | `SHADOWER-MAX` / `9`, both ways |
| [C9](#c9) cross-file `var` shadow | `cc` error | `12!`, both ways |
| [C9](#c9) realistic shape (helper in main, library uses the built-in) | `cc` error | `the shadow` / `4`, both ways |
| [C10](#c10) typed shadow poisoning an unrelated module | `Type mismatch!` | `the shadow` / `4`, both ways |
| [C10](#c10) `var N : Integer := System.Max(1, 2)` | `Type mismatch!` | `2`, both ways |
| [C11](#c11) `Shapes.Sides := 9` | `cc` error | `4` / `9`, both ways |
| [C12](#c12) `'\\'` in the stem rule | never matched | `'\'`, and the rule is computed once |

**Three of the four went further than what I asked for**, and the way they did
is worth recording:

- **[C9](#c9)/[C10](#c10)** were fixed by scoping the sets per unit — and
  `tests/programs/UnitScope.a24` is a better test than the one I sketched. It is
  three files, and each line is chosen to fail differently: a unit that *exports*
  a shadow (so the importer inherits it), a unit that imports nothing (so it must
  see the built-in whatever anyone else declared), and the root file's own
  declaration. A program-wide set passes some of those lines and fails others,
  which is what makes it a real discriminator rather than a re-run.
- **[C11](#c11)** was *implemented* rather than refused, which is the better of
  the two options I offered — a module variable being one binding everywhere made
  read-only qualified access the odd case. `System.Max := 3` is separately
  refused, by name, with a §9 row (`An assignment to 'Unit.X'`) and the
  interpreter's `Can't assign to 'Max' in unit 'System'.` beside it.
- **[C12](#c12)** was fixed at the root: the stem is now computed once in the
  Parser and carried on `ModuleStmt.UnitName`, so the Resolver and the
  Interpreter read one value instead of deriving it twice. That is the
  deduplication rather than the literal fix, and it removes the class.

**And a bug I did not find came out of the same work:** `tests/programs/
BlockScope.a24` fixes a local that went on shadowing after its block ended,
because the emitters cleared the in-scope set at function boundaries and not
block boundaries. It was found by the compiler tripping over itself — a `var
Exported` in a loop in `CEmitter.a24`, which has a method of that name. That is
the same hazard the previous round's ⚠️ described, now fixed rather than worked
around.

**Open:** [C13](#c13) is new, **pre-existing, and not caused by this change** — a
three-deep `uses` chain has never compiled. [C8](#c8) is partly addressed.
[D3](#d3)–[D4](#d4) and [C3](#c3) are unchanged. **Nothing here blocks the
commit.**

**Since `99c01cb` — the four hot-path fixes.** [D3](#d3) is partly answered, by
about 25 lines of `bootstrap/algol.[ch]` and one token of emitted-C difference.
I reproduced the headline independently rather than reading the numbers: the
pre-change compiler rebuilt from `HEAD`'s checked-in seed interprets `fib(30)`
in **18.76 s**, the working tree in **7.70 s**, and the emitted C for
`compiler/Main.a24` differs between them **only** in `setjmp` → `ALG_SETJMP`.
Each of the four changes is safe, and I checked them individually rather than
trusting the suite: the hash in `MethodEntry` has exactly one write site and the
`strcmp` still guards; `alg_stricmp` agrees with `strcasecmp` on 3,065,025 byte
pairs with zero mismatches; the `field_slot` first-byte test is a pure filter.

**The diagnosis corrects mine, in the direction that matters.** I had attributed
the whole 18.5 s to name-based dispatch. About a quarter of it was
`sigprocmask` — a syscall per interpreted call, because `Exit` is a raise and
BSD's `setjmp` saves the signal mask. My own D3 measurement showed 2.03 s of
*system* time, which no `strcmp` can explain, and I did not read it.

**One new finding blocked it, and is now fixed.** [C14](#c14): the macro that
fixes the syscall was guarded on `_WIN32`, so its `#else` claimed Linux, where
`_longjmp` is not declared under `-std=c11` — `./build.sh` failed at stage 1 on
`gcc:14` with the documented default `CFLAGS`. The guard now names the platforms
that actually have the behaviour, in both trees, and the ⚠️ records why the old
test was wrong. **Re-verified**: the pair is selected correctly across six
platform/standard combinations; the whole loop including `fixedpoint` runs on
Linux; `./test.sh` and all nine `JPascal` gates are green on macOS; and
`fib(30)` still interprets in 7.93 s against the pre-change 19.21 s, so the fix
cost the platform the optimisation was written for nothing.

**Since `9d1601f` — the `uses`-chain initialisers.** [C13](#c13) is fixed, and
the fix declines the obvious shortcut: rather than widening `main`'s `#include`
list to the transitive closure — which would put headers for modules the root
never named into the root's translation unit — `main` **declares** the
initialisers it cannot reach, as the test runner already does one function down.
Verified against my original repro plus a five-deep chain, a `uses` cycle
reached transitively, a module whose file name needs sanitising
(`init_deep_mod`), and the shipped diamond; `tests/programs/Chain.a24` fails the
old emitter with exactly three undeclared initialisers, which I checked. Green
on macOS and on Linux/`gcc:14`, including `fixedpoint` both places.

Probing that fix in `--test` mode turned up [C15](#c15), which is **new to the
review, pre-existing, and untouched by this change**: a `test` block more than
one `uses` hop from the root fails interpreted with `Undefined variable
'<the test's own name>'` and passes compiled. Both interpreters agree with each
other; both emitters agree with each other; so it is the front end diverging
from the back end. `Chain.a24` closes the blind spot for `Run` and not for
`RunTests`.

**Nothing blocks the commit.** Open items are the long tail: [C15](#c15)
(pre-existing), [C8](#c8) (prose, item 7 added this round), [C3](#c3),
[D3](#d3)'s architectural remainder, [D4](#d4) by choice, and the three `E`
items.

---

## Findings

| # | Finding | Severity | Status |
|---|---|---|---|
| [C1](#c1) | Closure capture broken in the main block and in `test` blocks | **High** | ✅ **Fixed** |
| [C5](#c5) | `?` is not mangled out of class, object, or enum symbols | **High** | ✅ **Fixed** |
| [C4](#c4) | A `var` as an unbraced branch or case-arm body is boxed but never declared | Medium | ✅ Refused by name |
| [D1](#d1) | Arena never frees → string accumulation is quadratic in *memory* | **High** | ✅ **Fixed** (`Buffer`) |
| [C7](#c7) | `map_reindex` reallocates on every `Remove` → draining a `Map` is quadratic in *memory* | **High** | ✅ **Fixed** (+ `./test.sh memory`) |
| [D2](#d2) | `Map` is a linear scan → O(n²) comparisons to fill | Medium | ✅ **Fixed** (hash index, −30% interpreted) |
| [C6](#c6) | A class named after a builtin constructor wins interpreted, loses compiled | Medium | ✅ **Fixed** (tables consulted last) |
| [C9](#c9) | Builtin shadowing was program-wide in `CEmitter`, not per file → unrelated files stopped compiling | **High** | ✅ **Fixed** (+ `UnitScope.a24`) |
| [C10](#c10) | The same scope error in `TypeChecker`, and `System.X` inherited the shadow's type | Medium | ✅ **Fixed** |
| [C14](#c14) | `_setjmp`/`_longjmp` guarded on `_WIN32` → the seed did not build on Linux/glibc at the documented `-std=c11` | **High** | ✅ **Fixed** (verified on both platforms) |
| [C15](#c15) | `--test`: a test two `uses` hops down fails interpreted, passes compiled | Medium | Open (new, **pre-existing**) |
| [C13](#c13) | A three-deep `uses` chain emits `init_X()` without including `X.h` | Medium | ✅ **Fixed** (+ `Chain.a24`) |
| [D3](#d3) | Name-based dispatch on every call and field access | Medium | Partly addressed — **2.4× measured** |
| [C8](#c8) | Factual errors in the prose, one in a ⚠️ | Low | Partly fixed |
| [C11](#c11) | Assignment through a unit qualifier was not refused, it failed at `cc` | Low | ✅ **Fixed** (implemented) |
| [C12](#c12) | `'\\'` is a String, so two of the three unit-stem functions never split on `\` | Low | ✅ **Fixed** (stem computed once) |
| [C2](#c2) | Back-end refusals are correct but undocumented | Low | ✅ **Fixed** (`ALGOL-24.md` §9) |
| [C3](#c3) | Deep recursion segfaults with no message | Low | Open |
| [D4](#d4) | `volatile` applied to every local of any body containing `try` | Low | Open (by choice) |
| [E1](#e1) | Unreachable `return alg_nil();` after every real return | Cosmetic | Open |
| [E2](#e2) | `(void)(...)` wrapped around `void`-returning calls | Cosmetic | Open |
| [E3](#e3) | Argument compound literals do not overlap at `-O0` | Cosmetic | Open |
| [H1](#h1) | `README.md` referenced a `bootstrap/build.sh` that did not exist | Doc | ✅ Fixed |
| [H2](#h2) | `Mangle`'s `?` → `_q` branch is unreachable, and would collide | Trivial | ✅ Resolved (kept + documented) |
| [H4](#h4) | Scan errors were recorded and never reported | **High** | ✅ **Fixed** |
| [H3](#h3) | Duplicated comment in `VisitCall` | Trivial | ✅ Fixed |

---

## Correctness

### <a name="c1"></a>C1 — Closure capture in the main block and in `test` blocks: Fixed

**Verified fixed.** Both original reproductions now emit C that compiles under
`-Wall -Wextra -O2` and produces the interpreted answer:

```pascal
begin
    var K := 7;
    function Grab();
    begin
        Exit K;
    end
    WriteLn(Grab());       // interpreted 7; compiled 7
end
```

The root cause I identified was right but incomplete. I described a two-site
omission — the `IsMain` branch and `EmitTest` never populating `Boxed` — and
recommended mirroring `EmitFunction`'s setup into both. The fix does that, via a
shared `BoxesFor` helper (`CEmitter.a24:1158`) called from `IsMain`
(`:742`), `EmitTest` (`:889`), and the function path, with `Boxed`/`Captured`/
`Cells` saved and restored at each. It then goes on to fix four more defects of
the same family that my review did not find:

1. **The capture list was built from the wrong set.** It came from the enclosing
   `Boxed`, which is decided for a whole body before a line is written — so it
   contained names declared *later* or in a *sibling* block, and the capture
   list could name a cell that did not exist yet. The fix introduces `Cells`
   (`:226`), the boxed names whose cell has actually been emitted and is still
   in scope, with `OpenScope`/`CloseScope` (`:1275`, `:1280`) tracking C block
   lifetime. Capture lists are now built from `Cells`. A function declared above
   a `var` of its own body was enough to hit the old bug.

2. **`for ... in` loop variables were never boxed.** `CollectBindings` listed
   the loop variable, but the emission site (`:2550`) always emitted a plain
   local, so a capture list named a `c_F` nothing declared. Now boxed via
   `DeclareCell` *inside* the loop, which also gives the per-iteration capture
   the interpreter's fresh-environment-per-iteration semantics require.

3. **`try` bindings were invisible to both `DeclaresNested` and
   `CollectBindings`.** A function declared inside a `try`, or inside a handler
   capturing the handler's own variable, read its captures as plain locals. Both
   walkers now have `TryStmt` arms (`:1039`, `:1082`), and `EmitHandlerBody`
   (`:1341`) boxes the handler variable when it is captured.

4. **`TryDepth` leaked into nested bodies.** A function declared inside a `try`
   popped the *enclosing* function's frame on return, so a later raise found no
   handler and died `Uncaught` with a working `except` ten lines above. Now
   saved and zeroed at every body boundary, including method bodies. Verified:

   ```pascal
   try
       var Inside := 3;
       function Doubled();  begin Exit Inside * 2; end
       WriteLn(Doubled());  raise 'boom';
   except
       on E : String do WriteLn('caught ' + E);
   end
   ```
   Both back ends: `6` / `caught boom` / `after`.

Two further improvements beyond the bug itself:

- **`HoistCells` (`:1316`)** declares each boxed cell empty at the top of the
  block that binds it, so a nested function may capture a variable declared
  *below* it — which the interpreter allows, because the closure keeps the
  environment and the binding lands in it before the call. The `var` becomes a
  write through the cell. Correctly done per *block* rather than per function;
  the ⚠️ explains that hoisting per function would make all iterations of a loop
  share one cell.
- **`Unreachable` (`:2039`)**, the safety net I recommended as item 3. It fires
  when a nested body reads a name that is neither a local nor a file-scope
  global, calling `Unsupported` rather than emitting a bare `v_Name`. `Globals`
  (`:240`) is collected up front by `CollectGlobals` (`:607`) rather than in
  emission order, which is the right call — a function declared above a
  top-level `var` still reads it.

I probed the guard for false positives with a nested function reading a
top-level function, a top-level `var`, a class, an enum member, and an `object`
in one expression. All five pass through correctly; interpreted and compiled
output match (`1101004falsehi`).

The regression tests are in the right places: `tests/programs/Closures.a24`
gained main-block, declared-before-use, declared-after-use, try/handler,
per-iteration-block, and `for ... in` capture cases;
`tests/conformance/Declarations.a24` gained the `test`-block capture. That
matches recommendation 4, plus the two cases I did not think of.

**Remaining recommendation.** None for C1 itself. The one gap left in the same
family is [C4](#c4), which the `Unreachable` net does not cover because it is a
*write* in the enclosing body rather than a *read* from a nested one.

---

### <a name="c4"></a>C4 — A `var` as an unbraced branch or case-arm body: Refused by name

**Resolved, and resolved better than I recommended.** I proposed making
`HoistCells` recurse into non-`BlockStmt` bodies so the case would *work*. The
change refuses it instead, via `RefuseBareBinding` (`CEmitter.a24:1033`), on a
finding that makes my recommendation wrong: **the interpreter has no single
answer for the emitter to reproduce.**

I verified the four constructs interpreted:

| Body | Interpreted meaning |
|---|---|
| `if Flag then var Y := 5;` | binding leaks to the enclosing scope; `WriteLn(Y)` after prints `5` |
| `case N of 1: var Y := 5; end` | same -- leaks |
| `while N < 1 do var W := ...;` | same -- leaks |
| `for var E in [...] do var W := E;` | scoped per iteration; `WriteLn(W)` after is `Undefined variable 'W'` |

The emitter brace-wraps every body, which reproduces *neither* the leak nor the
per-iteration scoping. Hoisting to the enclosing block — my suggestion — would
have matched three constructs and silently changed the meaning of the fourth.
Refusing is right, and it is consistent with how the back end handles every
other construct it cannot represent faithfully.

Verified: all five shapes (`if`, `if`/`else`, `while`, `for ... in`, `case` arm)
now report

```
Uncaught: A 'var' as an unbraced branch or loop body is not supported by the C back end yet.
```

with exit 70 and no files written, where they previously emitted uncompilable C.
Unbraced bodies that are *not* a `var` still work in both back ends, and
`tests/programs/Closures.a24` gained a braced case with a ⚠️ explaining why the
unbraced form cannot appear in a differential program.

**`RequireCell` (`:1267`) is also in**, my second recommendation: the write-side
invariant. A `var` whose name is boxed now asserts its cell exists before
writing through it, so an assignment through an undeclared cell is structurally
impossible regardless of what new body shape appears. That is the general form
of the bug, and it is now closed independently of the four specific shapes.

**One correction to the documentation, now reverted — and it still does not
reproduce.** The ⚠️ at `CEmitter.a24:1035-1041` and the matching note in
`ALGOL-24.md:682` state that `while` "redefines it on the second pass and dies
with `'W' is already defined`". I corrected both last round after measuring;
this round's changes put the original wording back.

Re-measured against the current build, to be sure I had not been wrong the first
time:

```pascal
begin
    var M := 0;
    while M < 3 do var W := M := M + 1;
    WriteLn('survived');
    WriteLn(W);
end
```
```
survived
3
```

The loop runs its three iterations, `var W := ...` executes three times without
error, and `W` is readable after the loop holding `3`. So `while` leaks exactly
as `if` and `case` do; there is no redefinition error. The message `'X' is
already defined` lives at `Interpreter.a24:1665` and is about module-level name
collisions ("mark it private in one of the modules"), which this never reaches.

The argument for refusing is unaffected either way — `for ... in` still scopes
per iteration where the other three leak, and braces match neither — so nothing
depends on it except the ⚠️ itself. Flagging rather than re-editing, since the
comment is yours and a third round of the same one-line change is not useful;
but by this project's own convention a ⚠️ carrying a fact that does not hold is
worse than no ⚠️, because the next person to touch `RefuseBareBinding` will trust
it. If JPascal genuinely behaves that way, saying so explicitly ("JPascal
redefines it and dies with …; here it leaks") would keep both facts and be true
in both repos.

---

### <a name="c5"></a>C5 — `?` in class, object, and enum symbols: Fixed

**Verified fixed, structurally.** I listed six unmangled sites and recommended
either patching them or — better — giving the emitter one constructor per symbol
kind. The change does the latter, and found **nine** sites rather than my six:
I missed the `object` singleton reference, `alg_new` for construction,
`alg_invoke_from` for `super`, and the declared parameter types inside an
overload's method symbol.

`SymbolOf` (`:353`) is now the single chokepoint, with `ClassHandle`,
`InitName`, `EnumTypeName`, `EnumMemberName` beside the existing `Cell`,
`VariableName`, `FunctionName`, and `MethodSymbol`. A grep for a raw `'k_' +`
now returns only the ⚠️ that warns against writing one — which is the property
that makes this stay fixed.

All five reproductions from the previous round now compile clean under
`-Wall -Wextra -O2` and match interpreted output: enum member, enum type, class,
`object`, and `class Kid?(Base?)`. I extended the probes further, and these also
pass:

- a module whose **file name** carries a `?` (`uses Helpers?`);
- `G is Gate?` (correct — it goes through `QuoteC` as a runtime string, never a
  symbol);
- **overload dispatch on a `?`-typed parameter** (`Tell(G : Gate?)` against
  `Tell(N : Integer)`), which is the site I had not thought to check and which
  the change fixed anyway.

`tests/programs/Questions.a24` now covers the type-level surface it was missing:
`type State = (Idle?, Busy?)`, `class Gate?`, `class Latch?(Gate?)`, and
`object Tally?`.

**The backstop is in too** — my fourth recommendation. `QuestionsOut` (`:395`)
now refuses any character that is not a letter, digit, underscore, or `?` rather
than emitting it, through `Unsupported`. Nothing can reach it today, since the
scanner admits nothing else. That is the point: it is the one place a future
identifier character would have to be taught about, and it fails there rather
than in `cc`.

---

### <a name="c2"></a>C2 — Back-end refusals are correct but undocumented: Fixed

**Severity was Low (documentation).** `ALGOL-24.md` gained **§9, "What the C
back end refuses"** — a table of every refusal, the message it produces, and
whether a program can reach it. That is the section I recommended, and it does
three things I did not ask for and should have:

- It separates **reachable** refusals from **guards** and says so explicitly,
  with a ⚠️ that "guard" means no program is *known* to reach it rather than
  that none can. That is the honest framing; my list did not distinguish them.
- It records that the two compilers report a refusal **differently** — JPascal
  prints `[ERROR] …` and exits 65, `algc` raises and exits 70 — and that the
  text between is what the table gives. That divergence is real, unavoidable
  (the language has no `Halt`), and was undocumented.
- It names the two things that look like refusals and are not: unchecked module
  visibility when compiling, and `ParamStr(0)`.

Verified against the tree rather than read: the reachable refusals fire with the
documented wording, write **no** files, and exit 70. Reproductions in the
[appendix](#refusals-verified).

Two errors in the new table are recorded under [C8](#c8) — the site count, and
one row that transcribes a source variable instead of the message. Neither
touches the mechanism.

The one thing §9 asks for that does not exist here is the enforcement: it
mentions a development repository's `./refuse.sh` that runs a program per
reachable refusal under both compilers and requires the wording to match. That
harness is not in this tree, so the ⚠️ on `Unsupported` — "matched word for word
against JPascal" — is still a claim nothing checks. `'super' as a value` was
fixed this round precisely because it had drifted, which is the argument for the
harness rather than against it.

---

### <a name="c7"></a>C7 — `map_reindex` reallocates on every `Remove`: Fixed, and now measured

**Severity was High**, introduced by the [D2](#d2) fix and closed in the same
working tree. `map_reindex` (`algol.c:557`) reuses its table when the size has
not changed:

```c
if (map->index == NULL || slots != map->index_mask + 1) {
    map->index = arena_alloc((size_t)slots * sizeof(int32_t));
}
map->index_mask = slots - 1;
```

| n, draining a `Map` | broken | fixed |
|---|---|---|
| 10,000 | 1,277 MB | 8 MB |
| 20,000 | 5,113 MB | 15 MB |
| 40,000 | *(swapping)* | 27 MB |

Verified beyond the number: the full suite is green including `fixedpoint`,
`--test compiler/Main.a24` is unchanged at 8.24 s, and the adversarial `Map`
probe — thresholds, drain-and-refill, `Clear` twice, mixed key types, object
keys, order after removal — produces output byte-identical to the pre-fix run,
interpreted and compiled. The fix changes nothing observable, which is the whole
of what it should do.

The ⚠️ I asked for is there and is better than the one I proposed: it names the
three callers, says which two must allocate, gives both measurements, and then
quotes the sentence on `alg_remove` that made the cost easy to miss —
*"that is O(n), but the memmove above already is, so nothing regresses"* — and
says explicitly that it is true of **time**. A future reader who reaches for the
allocation now meets the argument, not just the rule.

**The instrument matters more than the fix.** `./test.sh memory` compiles each
`tests/mem/` program at `-O2`, runs it under `/usr/bin/time -l`, and fails it
against a `/// MAXRSS:` budget in its own header. Three programs: `Accumulate`
(4 MB of 64), `Drain` (3 MB of 64), `Fill` (10 MB of 64).

I checked the three things that decide whether a canary is worth having:

- **It fires.** Reverting the one-line fix in a scratch tree: `FAIL Drain — 1436
  MB, over its 64 MB budget`, section exit **70**. A canary nobody has watched
  fail is a canary nobody knows is alive.
- **`leaks` genuinely cannot see it**, which is the justification for adding a
  second instrument rather than a case to the first. Pointed straight at the
  broken `Drain` — not at the existing canaries, which never touch the path —
  macOS `leaks --atExit` reports `0 leaks for 0 total leaked bytes` on a run
  with a **1,279 MB** peak. The arena returns every chunk at exit, so by that
  instrument's definition nothing is wrong.
- **The budgets measure what they claim.** `Fill`'s 10 MB is the arithmetic:
  100,000 entries × 32-byte `MapEntry` is 3.2 MB, the doubling garbage sums to
  about the same again, and the index and its own doublings add ~3 MB. The
  headroom is 6× there and ~16× on the other two — loose on purpose, as the ⚠️
  says, so this tracks a change in *complexity* rather than a change in machine.
  Every bug of this class has been two to three orders of magnitude over.

One note rather than a finding: the section pins `-std=c11 -O2` instead of
honouring `CFLAGS`, exactly as `leaks` pins `-O0 -g`. That is right — a budget
is not comparable across optimisation levels — but `CLAUDE.md` still says
`CFLAGS` is "honoured by all three scripts", which is now true of the build and
not of two test sections.

<details>
<summary>The original finding, kept for the reproduction and the arithmetic</summary>

`map_reindex` (`algol.c:563`) begins by allocating:

```c
map->index      = arena_alloc((size_t)slots * sizeof(int32_t));
map->index_mask = slots - 1;
```

It has three callers. Two of them are growing the table and must allocate. The
third is `alg_remove` (`algol.c:730`), which rebuilds **at the same size**:

```c
if (map->index != NULL) map_reindex(map, map->index_mask + 1);
```

The rebuild is correct and the ⚠️ above it explains exactly why a rebuild is
required rather than a patch. The defect is only that it does not reuse the
table it already has. The arena never frees, so removing *n* entries from an
*n*-entry `Map` abandons *n* full tables.

Measured, interpreted, on a program that fills a `Map` and then removes every
key (`Drain.a24`, in the [appendix](#c7-repro)):

| n | `ba465bd` (linear scan) | working tree | with the one-line fix |
|---|---|---|---|
| 10,000 | 8 MB | **1,277 MB** | 8 MB |
| 20,000 | 13 MB | **5,113 MB** | 15 MB |
| 40,000 | 25 MB | *(swapping)* | 27 MB |

Exactly 4× per doubling — quadratic, and the arithmetic confirms the mechanism
rather than merely correlating with it. At n = 10,000 the table has grown to
32,768 slots, so the removals abandon 10,000 × 32,768 × 4 bytes = 1,250 MB,
against 1,277 MB measured. At 20,000 the table is 65,536 slots: 5,000 MB
predicted, 5,113 MB measured.

**Why nothing caught it.** `tests/programs/Maps.a24` removes 100 keys from a
200-entry `Map` — the right pattern, two orders of magnitude below the size
where it shows. `./test.sh leaks` runs `leaks`, which reports *unreachable*
memory, and every one of these tables is reachable from the arena's chunk list
until `alg_shutdown`, so it is not a leak by that definition — the same reason
`leaks` was clean throughout [D1](#d1). And the compiler itself never calls
`Remove` on a `Map` (`ObjCollection.a24:249` is the implementation, not a use),
so no build or test workload touches the path at scale. **This is latent for the
compiler and live for every Algol-24 program.**

**The fix** was to allocate only when the size actually changes — shipped, and
shown at the top of this section.

**Worth a ⚠️ of its own**, because the reuse looks like a micro-optimisation and
reads as safe to undo. It is not: it is what keeps `Remove` from being quadratic
in memory. The existing ⚠️ on `alg_remove` already says "that is O(n), but the
memmove above already is, so nothing regresses" — true of *time*, and it is the
sentence that makes the memory cost easy to miss.

</details>

---

### <a name="c8"></a>C8 — Factual errors in the prose (now six)

**Severity: Low.** Grouped because they are all the same kind of mistake — a
number or a name asserted rather than measured — and two of them are now inside a
⚠️, which `CLAUDE.md` says is load-bearing and to be preserved. A false ⚠️ is
worse than no ⚠️, because the next person will design around it.

**Status after the scope fixes:** item 6 is fixed and the stray `ctest/` pointer
is gone; item 5 is fixed in one of its three homes; items 1–4 are unchanged.
Nothing here is patched by me — the ⚠️ prose is yours, so these are reported
rather than edited.

| | Item | Status |
|---|---|---|
| 1 | `SourceCode.a24` ⚠️ overstates its own case by ~300× | Open |
| 2 | §9 count is one higher than `algc`'s | Open (still 1 out) |
| 3 | `An identifier containing 'c'` transcribes the loop variable | Open |
| 4 | `Cannot` vs JPascal's `Can't`, two Parser messages | Open |
| 5 | "seventeen of the twenty-two units" is eighteen | Partly fixed |
| 6 | `unit` header mismatch not reported in the documented format | ✅ Fixed |
| 7 | `algol.c:517` credits the *mangler* with refusing non-ASCII; it is the scanner | Open (new) |

**1. `SourceCode.a24:10` overstates its own case by about 300×.** The ⚠️ says
the `Map` it replaced "was the single largest consumer of Map lookups in the
whole compiler" and cost "about 4.5 million comparisons per file".

Instrumented `map_index` in two builds of `ba465bd` — one with `Lines` as a
`Map`, one with the new `List` — and counted, running `--test compiler/Main.a24`:

| | `map_index` calls | comparisons |
|---|---|---|
| `Lines` as a `Map` | 24,303,113 | 4,360,748,611 |
| `Lines` as a `List` | 24,288,279 | 4,345,614,029 |
| **difference** | 14,834 | **15,134,582** |

`SourceCode` accounts for **0.35%** of the compiler's `map_index` comparisons,
not the largest share. The mechanism in the ⚠️ is right — Σ n(n−1)/2 over
`compiler/*.a24` predicts 15,469,743, which lands within 3% of the measurement —
but "4.5 million per file" is true only of the three ~3,000-line modules; the
median module is ~200 lines and costs ~20,000.

And it buys no time. A `ba465bd` compiler with *only* the `SourceCode` change
runs `--test compiler/Main.a24` in **11.85 s** against the unchanged 11.71 s —
that is, nothing, inside the noise. The whole of the 30% is the hash index.

The change is still right, and the ⚠️'s other sentence is the one that carries
it: *"The keys were 1, 2, 3, ... in order, which is a List with extra steps."*
That is true, needs no measurement, and would survive the index making `Map`
fast. **Recommendation: keep the change, cut the magnitude claim to that
sentence.**

**2. `ALGOL-24.md` §9 now says "There are seventeen such places." `algc` has
sixteen.** The off-by-one has now survived two rounds intact, both times because
each round added a real refusal to both sides: `'System.X' as a value`, then
`An assignment to 'Unit.X'`. Recounted after the fixes — 19 `Unsupported (...)`
call sites collapsing to **16** distinct constructs, against 16 table rows of
which one covers two (`Unary`/`Binary`), so the table describes 17. The extra one
is still `A class field`
(`CEmitter.java:1973`, `visitClassVarExpr`) — `compiler/Expr.a24` has no
`ClassVarExpr` node at all, so there is nothing in `algc` for it to refuse. The
row belongs in a shared reference, but it needs a note that only one front end
builds the node; as written the count is wrong for the compiler the reader is
holding.

**3. The `An identifier containing 'c'` row transcribes the source, not the
message.** Both implementations interpolate the offending character
(`CEmitter.a24:421`, `CEmitter.java:483`); `c` is the loop variable. The table
promises exact wording everywhere else, so this reads as a literal lowercase
`c`.

**4. The `Cannot` → `Can't` sweep missed the Parser.** Every Resolver message
now matches JPascal word for word — I checked all seven. Two remain:

| `algc` | JPascal |
|---|---|
| `Parser.a24:1002` `Cannot have more than 255 parameters.` | `Parser.java:799` `Can't have more than 255 parameters.` |
| `Parser.a24:1605` `Cannot have more than 255 arguments.` | `Parser.java:1080` `Can't have more than 255 arguments.` |

Same class of divergence, same fix. Still open; the lines have moved to
`Parser.a24:1063` and `:1666`, and the two `AssertEqual`s are now at `:2492` and
`:2549`.

**5. "Seventeen of the twenty-two units" is eighteen. Partly fixed —
`ALGOL-24.md:410` now says eighteen; the other two homes still say seventeen,
and both are inside a ⚠️:** `compiler/Resolver.a24:51` and
`tests/programs/lib/Shapes.a24:5`. Counted: `compiler/` holds 22 `.a24` files,
and **18** declare a public `class` of the file's own name — AstPrinter,
CEmitter, Environment, Expr, Interpreter, ObjBuffer, ObjClass, ObjCollection,
ObjEnum, ObjFile, ObjFunction, ObjInstance, Parser, Resolver, Scanner, Stmt,
Token, TypeChecker. None is `private`. The remaining four are `Console` and
`SourceCode` (which declare an `object` of their name, and are the "two of the
compiler's own units are shaped this way" the neighbouring ⚠️ mentions — that
count is **correct**), plus `Main` and `TokenType`, which declare no type of
their name at all. The argument does not depend on the number, which is why this
is Low; but 18 of 22 makes it more strongly than 17 does.

**6. The `unit` header mismatch is not reported in the format `ALGOL-24.md`
shows. ✅ Fixed** — it now goes through the Parser's `Error`, so it carries the
file, the line and a caret under the offending name:

```
[ERROR] Hdr.a24: Unit 'Wrongg' must match its file name 'Wrong'.
[ERROR] 1 | unit Wrongg;
[ERROR]   |      ^^^^^^
```

Original finding below.

The reference gives:

```
[ERROR] Shapes.a24: Unit 'Shape' must match its file name 'Shapes'.
```

The actual output is a bare `Uncaught:` line with no file, no `[ERROR]` tag and
no source caret:

```
Uncaught: Unit 'Wrongg' must match its file name 'Wrong'.
```

The cause is that `UnitHeader` uses `raise` where every other parse error goes
through the Parser's `Error`. I checked the contrast directly: an ordinary syntax
error in the same module reports `[ERROR] <file>: ...` with the offending line
and a caret. The message itself is right and is identical interpreted and
compiled — only the framing differs, which is why this is Low rather than a
divergence. Routing it through `Error (Name, '...')` would give it the file, the
line and the caret for free.

**The stray `ctest/Units.a24` pointer in `tests/conformance/Modules.a24` is
gone.** ✅

---

**7. The new `alg_stricmp` ⚠️ credits the wrong stage.** `bootstrap/algol.c:517`
says "Identifiers in this language are ASCII — **the mangler** refuses anything
else". The claim it supports is true; the attribution is a stage early. A
non-ASCII identifier never reaches the mangler, because the scanner rejects the
byte:

```
$ printf 'class Caf\xc3\xa9;\nbegin\nend\n' > Uni.a24
$ ./algc Uni.a24
Uncaught: [line 1] Error: Unexpected character: ...      (exit 70)
```

Identical interpreted and compiled, from `Scanner.a24:180`. The reason this is
worth a line rather than nothing is that the ⚠️ is doing load-bearing work — it
is the argument that dropping `strcasecmp` is safe — and a reader checking that
argument will go looking in `Mangle` and find no such refusal. Reading
`the scanner` for `the mangler` makes it exact. (The safety argument holds
either way, and by a wider margin than the ⚠️ claims: see [D3](#d3).)

The same sentence appears in `JPascal/CLAUDE.md`.

### <a name="c6"></a>C6 — A class named after a builtin constructor wins interpreted and loses compiled: Fixed

**Severity was Medium. Fixed, and generalised past what I asked for.**

I recommended moving `Classes.Contains (Name)` above the builtin constructor
block. The change does something better: it computes

```pascal
var Shadowed := Classes.Contains (Name) or Objects.Contains (Name)
             or EnumTypes.Contains (Name) or Globals.Contains (Name)
             or TopLevel.Contains (Name);
```

and consults the built-in tables **only if that is false** — so the tables are
the last thing tried rather than the first, which is the order the interpreter's
environment chain always had. That closes the hole for classes, objects, enum
types, top-level `var`s and top-level functions in one rule instead of one of
them, and it makes the emitter's ordering *say* what the interpreter's scoping
*does* rather than coincide with it.

Two details are exactly right and worth calling out, because getting either
wrong would have been easy:

- **`TopLevel` rather than `Declared`.** `Declared` holds nested functions too,
  and a nested `function Set` is not in scope outside its parent. Using it would
  have shadowed `Set()` across the whole file. I verified the distinction holds:
  a nested `Max` gives `nested-max` inside its parent and `2` outside it,
  identically in both back ends.
- **A collection literal never goes through the constructor**, so `[:]` still
  builds a real `Map` where a `class Map` is declared. Asserted in
  `tests/programs/Shadowing.a24` and it passes.

`tests/programs/Shadowing.a24` is a good test of this — it carries the negative
cases as deliberately as the positive ones.

**What is not fixed is the scope of the rule**, which is a new finding rather
than this one: see [C9](#c9). The original report below is kept for the record.

<details>
<summary>Original finding, at <code>ba465bd</code></summary>

**Severity: Medium. Pre-existing — `Buffer` joins it rather than causes it.**
Found while probing whether the new `Buffer` name was safe to introduce.

Declaring a class whose name is a builtin constructor compiles without complaint
and means two different things:

```pascal
class Buffer;
begin
    function Hello() : String; begin Exit 'mine'; end
end
begin
    var B := Buffer();
    WriteLn(B.Hello());
end
```

| | Result |
|---|---|
| Interpreted | `mine` — the user class wins |
| Compiled | `Undefined property 'Hello'.` — the builtin wins |

I checked that this is not new. It reproduces identically for `TextFile`, and for
`List`, `Stack` and `Map` with a different message (`Only instances have
properties.`):

| Class named | Interpreted | Compiled |
|---|---|---|
| `Buffer` | `mine` | `Undefined property 'Hello'.` |
| `TextFile` | `mine` | `Undefined property 'Hello'.` |
| `List`, `Stack`, `Map` | `mine` | `Only instances have properties.` |

The cause is ordering in `CEmitter.VisitCall`. A *variable* shadowing a builtin
is handled correctly and has a ⚠️ saying so — `var Set := ...` then `Set(42)`
calls the variable, which I verified matches interpreted. But the builtin
constructor block is tried *before* `Classes.Contains (Name)`, so a class of the
same name never gets the chance. The interpreter looks the name up in scope
first, where a class declaration has already bound it.

This is the class of divergence the project's own standard is hardest on: it is
not a refusal and not a crash, it is two back ends quietly disagreeing about what
a program means, which is exactly what `Unsupported` exists to prevent.

**Recommendation.** Move the `Classes.Contains (Name)` test *above* the builtin
constructor block, so a declared class shadows the builtin the way a declared
variable already does. That makes the compiled path match the interpreted one and
is a reordering rather than new logic. If that turns out to disturb something —
the constructor block also serves names that are never classes — the fallback is
a refusal via `Unsupported ('A class named after a built-in constructor')`, which
at least fails loudly. Either is better than the present silence. Worth a
`tests/programs/` case once it is settled; the shadowing rule is currently
asserted for variables and not for classes.

</details>

---

### <a name="c9"></a>C9 — Builtin shadowing is program-wide in `CEmitter`, where the language scopes it per file: Fixed

**Severity was High.** Fixed, and covered by a test that discriminates rather
than merely re-runs.

All three repros below now agree across back ends — verified by re-running my own
programs, not by reading the diff:

| Repro | Result |
|---|---|
| cross-file `function Max` | `SHADOWER-MAX` / `9` |
| cross-file `var Str` | `12!` |
| helper in main, library uses the built-in | `the shadow` / `4` |

`tests/programs/UnitScope.a24` is the regression test, and it is better than the
two-file case I recommended. Three files are the smallest arrangement that tells
a per-file rule apart from a program-wide one, and it uses all three: `lib/Loud`
*exports* a `Str`, so the root file inherits that shadow; `lib/Quiet` imports
nothing, so every name in it must be the built-in whatever anyone else declared;
and the root file declares its own `Length`. A program-wide set passes some of
those six lines and fails others. Its ⚠️ says exactly this, which is the right
thing for a test whose value is in what it would catch.

The original finding is kept below for the record.

<details>
<summary>Original finding, against the first version of the change</summary>

**Severity: High. A regression against `e86c86f`.** This is the one thing I would
fix before committing.

`Shadowed` is computed from `Classes`, `Objects`, `EnumTypes`, `Globals` and
`TopLevel`. All five are filled by walking **every unit** into one flat set:

```pascal
for var U := 0; U < Units.Length; U := U + 1 do
    CollectGlobals (Units[U].Statements);
```

So a top-level declaration in *any* file suppresses the built-in of that name in
*every* file. The interpreter does not do this, and cannot: built-ins are the
outermost environment, each module's globals enclose it separately, and `uses` is
not transitive — so a file that never imported the declaring module has no way to
see the declaration and must find the built-in.

The consequence is not a wrong answer. It is that **the program stops
compiling**, because the emitting file names a function it has no declaration
for.

The realistic shape, and the one I would expect to hit first — a helper in the
main program, and a library that just uses the built-in:

```pascal
// Main2.a24
uses 'lib/Util';

function Length (X);            // an ordinary helper
begin
    Exit 'the shadow';
end

begin
    WriteLn (Length ('abc'));
    WriteLn (Longest (['a', 'bbbb', 'cc']));
end
```

```pascal
// lib/Util.a24 -- imports nothing, uses the builtin Length
function Longest (Items : List) : Integer;
var
    Best : Integer := 0;
begin
    for var I := 0; I < Items.Length; I := I + 1 do
        if Length (Items[I]) > Best then Best := Length (Items[I]);
    Exit Best;
end
```

| | Result |
|---|---|
| Interpreted | `the shadow` / `4` — correct |
| Compiled | **does not build** |

```
./Util.c:19:36: error: assigning to 'Value' from incompatible type 'int'
    (void)((v_Best = f_Length(NULL, (Value[]){alg_subscript_get(v_Items, v_I)}, 1)));
```

`Util.c` emits `f_Length`, which lives in `Main2.c` and is not declared in
`Util.h` — so C falls back to an implicit `int` return.

The same holds for a file-scope `var`. `var Str := 'x';` in one file makes an
unrelated file's `Str(12)` emit `alg_call(v_Str, ...)` and fail with `use of
undeclared identifier 'v_Str'`. And it holds whether or not the declaration is
`private` — a `private` one becomes C's `static`, so the failure moves from the
compile to the link.

**This is a regression, measured rather than inferred.** I rebuilt the
pre-change compiler from `HEAD`'s checked-in `bootstrap/*.c` and emitted the same
program with both:

| | `Innocent.c`, which does not import the shadower |
|---|---|
| `e86c86f` | `return alg_max(alg_int(3), alg_int(9));` — builds, prints `9` |
| working tree | `return f_Max(NULL, (Value[]){alg_int(3), alg_int(9)}, 2);` — **does not build** |

Worth being fair about what the old compiler got wrong, because it is the reason
for the change: at `e86c86f` the *importing* file was wrong the other way — it
printed `9` where the interpreter printed `SHADOWER-MAX`, which is [C6](#c6). So
the change trades a silent wrong answer in the importing file for a build failure
in a non-importing one. The first is worse in kind. The second is worse in blast
radius, because it takes down files that were correct.

**Recommendation.** The per-unit information already exists — `CollectGlobals`
and the `UnitExports` loop both run per unit, and `UnitExports` is already
exactly "what this unit declares, less its `private` names". Build the shadow set
the same way: per unit, then union each unit's own set with the sets of the units
it `uses`, and consult *that* when emitting that unit's statements. That is the
same non-transitive closure `Units` already computes in the Resolver, so the rule
is one both passes can state identically.

If the full closure is more than this change should carry, the cheap correct
version is to make the shadow set **the emitting unit's own declarations plus its
direct imports'**, which is what `uses` means and is what the interpreter's chain
walks. The current flat set should not ship either way: it is the only thing here
that turns a working program into one that does not build.

A `tests/programs/` case would catch it — the shape is two files where the
shadowing declaration and the use are separated, which is precisely what the
present corpus does not have.

</details>

---

### <a name="c10"></a>C10 — The same scope error in `TypeChecker`, and `System.X` inherits the shadow's type: Fixed

**Severity was Medium.** Both symptoms fixed.

A typed shadow in the root file no longer retypes the built-in inside a module
that never imported it — the program that reported `Type mismatch!` now prints
`the shadow` / `4` identically both ways. And `System.X` no longer inherits the
shadow's type:

```pascal
function Max (A, B) : String;
begin
    Exit 'mine';
end

begin
    var N : Integer := System.Max (1, 2);   // now 2, was Type mismatch!
end
```

The same holds for `System.Length` under a typed `function Length` shadow (`4`).
That restores the example `README.md` and `ALGOL-24.md` both lead with, in the
one situation the feature exists for.

The original finding is kept below for the record.

<details>
<summary>Original finding, against the first version of the change</summary>

**Severity: Medium.** Two symptoms, one cause, and the cause is [C9](#c9)'s: a
shadow's declared type is applied program-wide.

**1. A typed shadow anywhere retypes the built-in everywhere.** Give the helper
in [C9](#c9) a return type and the program is rejected before it runs, by both
back ends alike:

```pascal
function Length (X) : String;   // in Main2.a24
```
```
Uncaught: Type mismatch!
```

The failure is inside `lib/Util.a24`, at `if Length (Items[I]) > Best`, in a file
that never imported the shadow. Because both back ends share the front end they
agree, so no differential gate can see this — it is the same class of front-end
divergence the `TypeChecker` change in this diff was written to close, one level
up.

**2. `System.X` takes its type from the shadow rather than from the built-in.**
`VisitGetExpr` returns `Lookup.GetType (Name)` for a qualified name, with the
comment that "qualification only says where to look". That is true of *which
binding*, but the type table it consults has already been overwritten by the
shadow — so the qualified form inherits precisely the type it exists to get past:

```pascal
function Max (A, B) : String;
begin
    Exit 'mine';
end

begin
    var N : Integer := System.Max (1, 2);   // Uncaught: Type mismatch!
end
```

Without the shadow the same line yields `2`. This is the example given in
**`README.md` and `ALGOL-24.md` both** — `WriteLn (System.Max (1, 2))` survives
only because `WriteLn` takes `Any`; bind it to a typed variable and it stops.

**Recommendation.** For (1), scope the type table the way [C9](#c9) scopes the
shadow set — the two want the same per-unit-plus-imports view and should be built
once. For (2), `System.X` should be typed from the **built-in registry**, not
from `Lookup`: it is by construction never a user binding, so a lookup that can
return one is the wrong lookup. If the registry is not reachable from the type
checker, returning `Any` for `System.X` is a sound and much smaller fix — gradual
typing already makes `Any` compatible in both directions, so it costs a check
nothing currently performs and unblocks the documented form.

</details>

---

### <a name="c11"></a>C11 — Assignment through a unit qualifier is not refused, it fails at `cc`: Fixed, by implementing it

**Severity was Low.** I offered two options — refuse it, or implement it — and
noted that refusing sat awkwardly beside the reference's insistence that a module
variable is *one binding* wherever it is reached. It was implemented, which is
the better call:

```pascal
uses 'lib/Shapes';
begin
    WriteLn (Shapes.Sides);   // 4
    Shapes.Sides := 9;
    WriteLn (Shapes.Sides);   // 9
end
```

Identical interpreted and compiled. The case the back end genuinely cannot do is
refused by name instead of reaching `cc`, with a §9 row of its own:

```
interpreted   Uncaught: Can't assign to 'Max' in unit 'System'.
compiled      Uncaught: An assignment to 'System.Max' is not supported by the C back end yet.
```

<details>
<summary>Original finding, against the first version of the change</summary>

**Severity: Low.**

`ALGOL-24.md` says a qualified name lets you "read a unit's `var` through it",
and `tests/programs/Units.a24` reads `Shapes.Sides`. Writing one is not handled:
`VisitSetExpr` was not given the `Unit` treatment `VisitGetExpr` was, in the
Resolver or in either back end.

```pascal
uses 'lib/Shapes';
begin
    Shapes.Sides := 9;
end
```

| | Result |
|---|---|
| Interpreted | `Uncaught: Only instances have fields.` |
| Compiled | **does not build** — `k_Shapes` used as a value |

The interpreted message is defensible but misleading (nothing here is an
instance, and the reader's mistake was qualifying an assignment). The compiled
side is the actual problem: this is a construct the back end does not support and
it does not say so, which is the one thing §9 exists to guarantee.

**Recommendation.** Decide the semantics, then make both ends agree. Refusing is
perfectly reasonable and cheapest — `Unsupported ('An assignment through a unit')`
plus a §9 row — but note that read-only qualified access is slightly odd given
that the reference is explicit that a module variable is *one binding* everywhere
it is reached, so writing it through a qualifier is the natural companion to
reading it. If it is meant to work, the Resolver change mirrors `VisitGetExpr`
and the emitter's is `VariableName (Name) + ' = ' + ...`. Either way it should
not reach `cc`.

</details>

---

### <a name="c12"></a>C12 — `'\\'` is a two-character String, so two of the three stem functions never split on a backslash: Fixed, at the root

**Severity was Low.** Fixed the way I hoped rather than the way I asked.

The literal is corrected — `Parser.a24:149` now reads `Key[I] = '\'` — but the
part that matters is that **the rule is no longer written three times**. The
Parser computes the stem once and stores it on the node, as
`ModuleStmt.UnitName` (`Stmt.a24:248`), and the two passes that had to agree now
read that one value instead of deriving it:

| | Before | After |
|---|---|---|
| `Resolver` | its own `UnitName`/`StemOf` | `Str (Stmt.UnitName)` |
| `Interpreter` | its own `UnitNameOf` | `Str (TheStmt.UnitName)` |

That removes the class of bug rather than the instance: the Resolver decides
*whether* a name is a unit and the Interpreter decides *which* environment it
reaches, so those two disagreeing was the whole hazard, and they can no longer
disagree.

`CEmitter.UnitNameOf` survives and splits only on `/`. That is correct and not
an oversight — it answers a different question (the C **file** name, so it ends
in `Sanitize`) and is called for the root file, which has no `ModuleStmt` to
carry a stem. Worth one note: the doc comment on `Parser.UnitStem` still says
*"The Resolver and the Interpreter each work this out the same way for the same
reason"*, which was true before the fix and is now the opposite of what the code
does. Small, but it is the sentence a future reader would use to justify adding
a fourth copy.

<details>
<summary>Original finding, against the first version of the change</summary>

**Severity: Low.** Latent rather than reachable, but it is a ⚠️ waiting to be
believed.

The file-stem rule is written **three times** — `Parser.UnitStem`,
`Resolver.UnitName`, and `Interpreter.UnitNameOf` — and the three do not agree:

| | separator test |
|---|---|
| `Resolver.a24` `UnitName` | `if Key[I] = '/' or Key[I] = '\'` |
| `Parser.a24:143` `UnitStem` | `if Key[I] = '/' or Key[I] = '\\'` |
| `Interpreter.a24:1154` `UnitNameOf` | `if Key[I] = '/' or Key[I] = '\\'` |

A doubled quote is the only escape the scanner has, so `'\\'` is not an escaped
backslash — it is a **String** of two characters. And `Key[I]` is a `Char`, which
the reference is explicit can never equal a `String`. Verified:

```
'\'  is Char    -> true
'\\' is Char    -> false,  is String -> true,  Length -> 2
'\' = '\\'      -> false
```

So the Resolver splits Windows-style paths and the other two silently do not.
The Resolver decides *whether* a name is a unit and the Interpreter decides
*which* environment it reaches, so on a `\`-separated import they would disagree:
resolved as unit `ModA`, keyed as unit `lib\ModA`, and the program would get
`Undefined name 'X' in unit 'ModA'.` for a name the unit plainly exports.

Not reachable today — a `\` path does not open on this platform, so nothing gets
that far — which is why this is Low and not a correctness finding.

**Recommendation.** Two things, and the second matters more. Fix the literal to
`'\'` in both places. Then collapse the three copies into one: the comments
already acknowledge the duplication (*"the Resolver and the Interpreter each work
this out the same way for the same reason"*, *"this is the interpreter's copy of
that one rule"*), and this finding is what that duplication costs — three
transcriptions of five lines, and one of them drifted before the feature had
shipped. `Parser.UnitStem` and `Interpreter.UnitNameOf` are byte-identical to
each other; `Resolver.UnitName` differs only in using a helper and an early
`Exit`. One function in a module all three already `uses` would remove the class
of bug, and a `test` block on it would pin the rule that a unit is its file stem
— which is currently asserted nowhere.

</details>

---

### <a name="c15"></a>C15 — `--test`: a test block two `uses` hops down fails interpreted and passes compiled

**Severity: Medium. New, pre-existing, in the front end rather than either
emitter.** Found by probing [C13](#c13)'s fix in `--test` mode, which the fix
does not touch and `Chain.a24` does not cover.

A `test` block in a module more than one `uses` hop from the root is reported as
failing, with an error naming **the test's own name as an undefined variable** —
while the compiled binary built from the same source runs it and passes. The
minimal repro is three files whose test bodies are all `AssertEqual (1, 1)`, so
nothing about it depends on what a test can reach:

| | `depth 0` | `depth 1` | `depth 2` |
|---|---|---|---|
| algc / JPascal interpreted | PASS | PASS | **FAIL** — `Undefined variable ''depth 2''` |
| algc / JPascal compiled | PASS | PASS | PASS |

Depth is the whole variable: two files never fails, three does, and more depth
adds more failures. The program itself runs correctly in all four paths, so this
is only `--test`. The `--test` emission from the two compilers is byte-identical
for this program, so `cgate` cannot see it either.

**It is not the documented limitation.** `CLAUDE.md` says a module's tests can
only reach what that file `uses` — that is about what a test *body* may
reference. Here the bodies reference nothing, the test does not run at all, and
the diagnostic blames a string literal.

**Recommendation.** Find why `RunTests` resolves a test at depth ≥ 2 into a
variable lookup of its own name — the message suggests the test-name expression
is evaluated in a scope where the module's bindings were never installed, the
same "closure walked, environment not" shape as C13 one layer up. And **add a
`--test` chain fixture**: that is the real fix to the blind spot, because
`compiler/Main.a24` is a star and has every test-carrying module at depth 1 by
construction.

Full detail, including the repro and the four-path table, is in the sibling
repository's `REVIEW.md`.

---

### <a name="c13"></a>C13 — A three-deep `uses` chain emits `init_X()` without including `X.h`: Fixed

**Severity: Medium. New to this review, but pre-existing — not caused by this
change.** Found by the regression sweep, not by the feature.

A valid program that the interpreter runs does not compile:

```pascal
// Root.a24
uses 'lib/Mid';
begin
    WriteLn (Mid ());
end
```
```pascal
// lib/Mid.a24
uses 'lib/Deep';
function Mid () : String;
begin
    Exit 'mid via ' + Deep ();
end
```
```pascal
// lib/Deep.a24
function Deep () : String;
begin
    Exit 'deep';
end
```

| | Result |
|---|---|
| Interpreted | `mid via deep` |
| Compiled | `error: call to undeclared function 'init_Deep'` |

No units, no classes, no shadowing — a plain chain. The mechanism is a mismatch
between two things the emitter derives separately. `Root.c` runs the init
sequence for the **whole transitive closure**, but includes only its **direct**
imports:

```c
/* Root.c */
#include "Root.h"
#include "Mid.h"      /* Deep.h is not here */
...
    init_Deep();      /* ...but this is */
    init_Mid();
    init_Root();
```

Initialising the closure is right — `Deep`'s file-scope `var`s must be set up
before `Mid` runs. Declaring only the direct imports is also defensible. The two
just have to agree, and they do not.

**Confirmed pre-existing.** The compiler built from `e86c86f`'s checked-in seed
produces the byte-identical error on the same program, so nothing in the units
work introduced it.

**Why nothing caught it.** Every module in `tests/programs/lib/` and
`tests/conformance/` is a leaf — no test module `uses` another, so the corpus has
no chain deeper than two. And the compiler itself cannot trip it: `Main.a24`
directly `uses` **all 21** of the other modules, so its import graph is a star,
and every `init_X()` it emits is covered by a direct `#include`. The one program
guaranteed to be compiled every single build is the one shape immune to this.

**Recommendation.** Emit the include list from the same closure the init sequence
walks — the root file already knows both, since it computes the closure to order
the inits. A `tests/programs/` case is cheap and is the real fix to the blind
spot: three files, `Root → Mid → Deep`, which the differential runner would have
failed on immediately. It is worth adding even before the emitter change, because
the corpus being all-leaves is what let this sit.

---

### <a name="c14"></a>C14 — `ALG_SETJMP` was guarded on the wrong axis: the seed did not build on Linux — Fixed

**Severity: High. ✅ Fixed** in `bootstrap/algol.h` and in `JPascal`'s copy
(`f67642d`, *"The comment said BSD; the guard said 'not Windows'"*). The
recommended guard was taken verbatim, and the ⚠️ was rewritten to record **why
the old test was wrong** rather than simply replaced — so the next person to
reach for `#if defined(_WIN32)` finds the reason it fails written down. That is
the same instinct as the two negative results in [D3](#d3), and it is the right
one.

**Verified on both platforms, at the level the finding was made.** The guard now
selects exactly as intended, checked by compiling the real `algol.h` and jumping
through it rather than by reading the `#if`:

| | macOS `c11` | macOS `gnu11` | glibc `c11` | glibc `gnu11` | glibc `c17` | glibc `gnu17` |
|---|---|---|---|---|---|---|
| pair chosen | `_setjmp` | `_setjmp` | `setjmp` | `_setjmp` | `setjmp` | `_setjmp` |
| jump works | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |

**The whole bootstrap loop now runs on Linux**, `gcc:14`, `CFLAGS="-std=c11
-O2"` — the case that previously failed at stage 1:

```
  stage 1: building the seed with gcc
  stage 2: that compiler compiles compiler/
  seed:    current -- compiler/ emits exactly the checked-in C
All green: unit          (221 tests)
All green: conformance   (8 suites)
All green: compiled      (8 suites)
All green: programs      (28 differential)
All green: fixedpoint    (seed current; generations 2 and 3 identical)
```

`fixedpoint` passing on a second toolchain is worth more than the rest of that
list. It is the determinism check, and until now "no hash order, no timestamps,
no pointer values reach the emitted text" had only ever been demonstrated
against one compiler on one platform.

**And the ⚠️'s claim that the standard pair costs glibc nothing is true — I
measured it rather than trusting the header.** Same source, two builds, the only
difference being which pair the guard selects:

| | `-std=c11` (standard) | `-std=gnu11` (fast) |
|---|---|---|
| `fib(30)`, best of 3 | 7.715 s | 7.693 s |
| system time | 0.358 s | 0.359 s |

Identical inside noise. (A first, cold run showed 8.29 s against 7.74 s and I
nearly wrote it up; three interleaved runs made it a page-fault artefact of the
freshly linked binary. Worth recording because the finding it would have
supported — that glibc still pays for `longjmp` — is plausible and wrong.) So
the `__GLIBC__` clause earns its place by keeping parity under `-std=gnu11`,
not by buying anything under the default.

**macOS is unaffected, as intended:** `fib(30)` interprets in **7.93 s** against
the pre-change **19.21 s**, system time 0.21 s against 1.97 s. The guard fix
costs the platform the optimisation was written for exactly nothing.

<details>
<summary>The original finding, as reported</summary>

**Severity: High.** New, and introduced by this change. It does not affect
macOS, which is why every gate on both sides is green.

`bootstrap/algol.h:29-35` picks the mask-free jump pair by asking whether the
host is Windows:

```c
#if defined(_WIN32)
#define ALG_SETJMP(buf)       setjmp(buf)
#define ALG_LONGJMP(buf, val) longjmp(buf, val)
#else
#define ALG_SETJMP(buf)       _setjmp(buf)
#define ALG_LONGJMP(buf, val) _longjmp(buf, val)
#endif
```

The `#else` therefore covers Linux, and `_setjmp`/`_longjmp` are **not ISO C**.
glibc's `<setjmp.h>` declares them under a feature-test guard:

```c
extern int _setjmp (struct __jmp_buf_tag __env[1]) __THROWNL;   /* unconditional */

#if defined __USE_MISC || defined __USE_XOPEN
extern void _longjmp (struct __jmp_buf_tag __env[1], int __val) ...;
#endif
```

`-std=c11` defines `__STRICT_ANSI__`, so neither `__USE_MISC` nor `__USE_XOPEN`
is set and **`_longjmp` is never declared**. Since GCC 14, an implicit function
declaration is an *error*, not a warning. `CFLAGS` defaults to `-std=c11 -O2`,
which `CLAUDE.md` documents and all three scripts honour, so this is the default
build on the default toolchain:

```
$ docker run --rm -v $PWD:/w -w /w gcc:14 sh -c 'CC=gcc ./build.sh'
./algol.h:34:31: error: implicit declaration of function '_longjmp';
                        did you mean 'longjmp'? [-Wimplicit-function-declaration]
   34 | #define ALG_LONGJMP(buf, val) _longjmp(buf, val)
./algol.c:2064:1: warning: 'noreturn' function does return
FAIL  the seed does not build
```

Note the second line. Even where the implicit declaration is tolerated, the
compiler no longer knows the callee does not return, and `alg_raise` — declared
`_Noreturn` — falls off its end.

**And the `#else` branch buys Linux nothing anyway.** Four lines above the guard
above, glibc has:

```c
/* Do not save the signal mask.  This is equivalent to the `_setjmp'
   BSD function.  */
#define setjmp(env)	_setjmp (env)
```

That `#define` is outside `__USE_POSIX`, so under `-std=c11` plain `setjmp`
**already is** `_setjmp` on glibc. The saved-mask syscall the change is chasing
is a BSD behaviour, exactly as the ⚠️ says — the guard just does not test for
BSD. The condition is "is this a BSD-derived libc", not "is this not Windows".

**Recommendation.** Ask the question the ⚠️ already answers correctly. This
variant was compiled and run on both platforms across `c11`, `gnu11`, `c17` and
`gnu17`, and picks the fast pair in every case where it is both legal and
worth having:

```c
#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) \
 || defined(__OpenBSD__) || defined(__DragonFly__) \
 || (defined(__GLIBC__) && (defined(__USE_MISC) || defined(__USE_XOPEN)))
#define ALG_SETJMP(buf)       _setjmp(buf)
#define ALG_LONGJMP(buf, val) _longjmp(buf, val)
#else
#define ALG_SETJMP(buf)       setjmp(buf)
#define ALG_LONGJMP(buf, val) longjmp(buf, val)
#endif
```

| | macOS | glibc `-std=c11` | glibc `-std=gnu11` |
|---|---|---|---|
| chosen pair | `_setjmp` | `setjmp` | `_setjmp` |
| mask saved? | no | no (glibc aliases it) | no |
| builds | ✅ | ✅ | ✅ |

The `__GLIBC__` clause is what keeps the win on Linux for anyone who overrides
`CFLAGS` with `-std=gnu11`, where plain `setjmp` does go through
`__sigsetjmp(env, 1)`. It is safe to read `__USE_MISC` there because
`#include <setjmp.h>` sits immediately above and pulls in `<features.h>`.
Dropping the clause and keeping only the BSD list is also correct, and costs
only that one case.

⚠️ **This is not `bootstrap/`-only.** `bootstrap/algol.[ch]` is the hand-written
runtime and is copied verbatim into every emitted directory, and it is
byte-identical to `JPascal/src/main/resources/runtime/algol.h` — I diffed both
files across the two repositories and they match exactly. JPascal shipped the
same guard in `74ffe8b`, so the fix belongs in both trees or `cgate` starts
comparing two different runtimes.

**Verified with the fix in place.** With the guard above, a container running
`gcc:14` and `CFLAGS=-std=c11 -O2` completes the whole loop:

```
  stage 1: building the seed with gcc
  stage 2: that compiler compiles compiler/
  seed:    current -- compiler/ emits exactly the checked-in C
Built /w/algc
ok    Collections/Objects/Enumerations/Declarations/Exceptions/Modules/Files/Core
All green: conformance
All green: compiled
```

That is the first time this compiler has been shown to self-host on a non-Apple
platform in this review, and it is worth a line in the README once the guard is
right — the project's claim is that a C compiler is the only prerequisite.

</details>

**The gap that hid it is still open, and it is not a code gap.** Nine gates,
three implementations, a byte-identical fixed point — all on macOS with Apple
clang. A change to `algol.[ch]` that builds here and nowhere else passes the
entire matrix, which is exactly what happened. The emitted C is deliberately
plain; the *runtime* is the file where `#if` lines live, so it is the one that
needs a second toolchain. The cheapest useful version is not a gate at all — one
invocation, by hand, when `algol.[ch]` changes:

```sh
docker run --rm -v "$PWD:/w" -w /w gcc:14 \
    sh -c 'CC=gcc ./build.sh && ./test.sh conformance compiled programs fixedpoint'
```

Under two minutes on a warm image, and it would have caught this before the
commit. `-std=c11` is the setting that matters: it is the documented default and
the strictest thing the code claims to support.

---

### <a name="c3"></a>C3 — Deep recursion segfaults with no message

**Severity: Low.** Unchanged.

`Down(1000000)` dies with SIGSEGV (exit 139) compiled, and the interpreter dies
the same way at around 60,000 frames — earlier, since each Algol frame costs
several C frames. No message in either case.

The two back ends agree, so this is not a differential failure. But a bare
segfault is a hostile failure mode for a language that otherwise reports errors
with a source caret, and it is the one runtime failure a beginner is most likely
to hit.

**Recommendation.** Low priority, but a depth counter in `alg_call`/`alg_invoke`
and in the interpreter's call path, tripping at a configurable limit and going
through `alg_error("Stack overflow.")`, would cost one increment per call and
turn a crash into a catchable error consistent with everything else. If that
increment is judged too expensive on the hot path, the alternative is a
documented note in `ALGOL-24.md` that recursion depth is bounded by the C stack
and overflow is not diagnosed.

---

## Design decisions worth revisiting

These are documented as deliberate. I am flagging them anyway because I think
two of them have consequences that are not stated, and the stated rationale does
not fully cover them. [D1](#d1) is now closed; the runtime gained ~300 lines for
it and `bootstrap/algol.[ch]` is no longer untouched since the first review.

### <a name="d1"></a>D1 — Quadratic string accumulation: Fixed, by adding `Buffer`

**Was High. Closed.** This was the item I expected to sit open until project 3,
because I framed it as needing either a collector or an unsound trick. It is
closed instead by a new type, which needs neither.

**The reframing that made it tractable** — and which I want to record, because it
is the part I got to late — is that this was never a *reclamation* problem. The
arena's "never free an individual object" decision is untouched and still right.
The cliff was one of allocation *volume*: `S := S + X` allocates a fresh string
and copies both operands, so n appends allocate ∑ lengths ≈ n²/2 bytes, and
whether or not there is a collector is irrelevant to how much garbage gets made.
A growable buffer that appends in place makes n appends cost under 2n. No
ownership analysis, no GC.

**My diagnosis of *where* the cliff was being paid was wrong.** I located it in
`CEmitter`, which builds every emitted file by `Text := Text + ...`, and wrote
that "it works today only because compiler output is small." Both halves were
off. Output is not small — `CEmitter.c` is ~700 KB — and the emitter was the
*lesser* of the two sites. `Parser.ReadWholeFile` and `Main.ReadSource` both read
a source file with `Result := Result + F.ReadLn() + #10`, which copies the whole
file so far on every line. I never looked at either.

Measured on the same 98 KB source, one file, nothing else running:

| Reading `compiler/CEmitter.a24` | Peak RSS |
|---|---|
| `Result := Result + Line + #10` | **273 MB** |
| `Result.Append(Line); Result.Append(#10)` | **4 MB** |

Summed over the 22 modules a full self-compile reads — n·lines/2 per file, times
two concatenations per line — the naive read accounts for **~918 MB**, or 73% of
the old 1,252 MB peak. The emitter was the remaining ~330 MB. So the fix is
correct and the emphasis in the commit message is correct: reading cost more than
emitting.

**The result, measured now** (`./algc --compile`, peak RSS, before → after):

| Module | Source | Before | After |
|---|---|---|---|
| `Console.a24` | 4 KB | 39 MB | **8 MB** |
| `Scanner.a24` | 27 KB | 38 MB | **8 MB** |
| `Parser.a24` | 88 KB | — | **48 MB** |
| `CEmitter.a24` | 95 KB | 1,189 MB | **87 MB** |
| `Main.a24` | 10 KB | 1,252 MB | **82 MB** |

**What I checked, beyond the suite.** `./test.sh` is green including
`fixedpoint`, which is the load-bearing one here: capacity is a function of
allocation history, and the compiler now builds its output in buffers, so if
capacity could reach the emitted text the twice-identical check would fail. It
does not. `./test.sh leaks` covers the new non-arena allocation via
`tests/leak/Buffers.a24`, which is well aimed — it exercises the three cases that
nothing else would (never-freed at shutdown, several `realloc` steps, and an
explicit `Free` followed by shutdown finding it already gone) and states in its
header why each one is there.

I ran twelve differential edge cases not covered by `tests/programs/Buffers.a24`
— negative and non-Integer sizes, negative `Resize`, unknown property, unknown
method, non-Integer subscript, `Buffer` equality and self-equality, a `Buffer` in
a `Map`, `+` against a `Buffer`, `Append` of a `Char`, and `Resize` down to zero.
**All twelve produce byte-identical output from both back ends, including every
error message.** The freed-buffer surface matches too: `Str(B)` gives
`Buffer(freed)` and `B is Buffer` stays `true` in both, while every other member
raises `That Buffer has been freed.` in both.

Three design choices in the implementation are worth calling out as good, because
each one closes a divergence that would otherwise have been found much later:

- **`Free` poisons rather than merely deallocating.** A `Free` that only released
  memory would be a no-op under an implementation with no manual memory and real
  under one that has it, so a use-after-free would read fine one way and be
  undefined the other. Marking the buffer dead and raising on any later access is
  the only rule both can keep. `as_buffer` is the single gate every read and
  write passes through, which is what makes it hold.
- **A zero byte has no `Text`.** A compiled `String` is a NUL-terminated `char *`
  and an interpreted one is not, so `Buffer(4).Text` would have been `''` one way
  and four characters the other — on the *default* shape of a sized buffer, which
  makes it easy to reach. Refusing costs one O(n) scan on a call that already
  copies O(n).
- **Printing shows the size, never the capacity or the contents.** Capacity is
  allocation history; letting it print would make emitted C depend on how the
  compiler grew its buffers, and `fixedpoint` would catch it as an unexplained
  diff.

**One factual error in the new prose.** `ALGOL-24.md:222` says the cliff "bites
hardest compiled, where nothing is reclaimed at all — under the interpreter the
JVM collects the intermediates, so the cost is time rather than a ceiling." That
is not true of *this* implementation. `algc` is compiled C on the same arena, so
both paths pay the same ceiling — measured on the 40,000-append loop, **775 MB
interpreted against 770 MB compiled**. The sentence is presumably carried over
from JPascal, where it holds; here it tells a reader the interpreted path is safe
when it is not. The rest of the section, including the table, is accurate.

**Remaining, and small.** The naive idiom is still quadratic, which the reference
now says plainly and correctly. Making `S := S + 'x'` itself linear needs an
explicit length in the string representation — a change to every site that makes
or reads a `Value` string, not a patch to `concat`. Correctly deferred. Note for
the record that my earlier estimate of "maybe thirty lines" for an in-place
`concat` was wrong and I retracted it: strings are bare `const char *` with no
length, so growing one in place is visible to every alias.

### <a name="d2"></a>D2 — `Map` lookup is a linear scan: Fixed, by a hash index

**Severity was Medium.** `ObjMap` now carries a side index — open addressing,
linear probing, power-of-two size, `-1` for empty — built at 8 entries and
doubled past half load. `entries` is untouched and still holds insertion order.
That is the shape I prototyped, implemented better than the prototype was.

**What it bought**, measured against `ba465bd` on this machine:

| | `ba465bd` | working tree |
|---|---|---|
| `--test compiler/Main.a24` | 11.71 s | **8.22 s** (−30%) |
| `--test compiler/Parser.a24` | 10.35 s | **7.41 s** (−28%) |
| `--compile compiler/Main.a24` | 2.61 s | 2.56 s (−2%) |
| peak RSS compiling `Main.a24` | 83 MB | 83 MB |

Within 0.02 s of the prototype's numbers, and the split is the one the prototype
predicted: the win is the interpreter, not the build.

**The three constraints I flagged are all handled, and each carries a ⚠️ saying
what the plausible wrong version looks like** — which is the more useful half:

- `alg_remove` rebuilds rather than patches, and the ⚠️ names the failure
  ("every later key pointing one entry past itself, which reads as a Map whose
  values have quietly shifted rather than as a crash"). Correct, and the source
  of [C7](#c7) — see there.
- `Clear` drops the index, with a ⚠️ that says the failure is silent.
- The ⚠️ on `ObjMap` explains that hashing an object by its address is legal
  *only* because nothing iterates the index, and cites both `PLAN.md:206` and the
  time the same bug was made in Java. That is the constraint I was most worried
  about and it is now the best-documented thing in the file.

**Verified beyond the gates.** The gates pass, but a hash index can pass all of
them and still be wrong at a size no test reaches, so I probed it directly
(`Probe.a24`, [appendix](#c7-repro)) — interpreted and compiled output identical
throughout:

- every size across the build threshold and both doublings — 7, 8, 9, 16, 17,
  32, 33, 64, 65 — all keys findable, no phantom key at `n`;
- drain-to-empty then refill, which leaves `count = 0` with a **non-`NULL`**
  index, a state `Clear` never produces;
- removing the last entry (a zero-byte `memmove`) and the only entry;
- 50 put/remove cycles of one key over a 20-entry `Map`;
- `Clear` mid-life, refill smaller, `Clear` again;
- insertion order preserved after removing every other key of 60;
- map literals, and a duplicate key in a literal (first position, last value);
- `Integer 1` / `Double 1.0` / `String '1'` / `Char 'a'` / `True` / `nil` as
  keys in one `Map` — six distinct keys, which is what mixing the type into the
  hash is for;
- two equal strings built separately as one key, which is what pins
  hashing-by-contents;
- `List` values as keys, hashed by identity, with `[4]` not finding `[4]`.

**Determinism holds.** `fixedpoint` is green, and I separately emitted
`compiler/Main.a24` from **five independent processes** — so five different ASLR
layouts — and all five hashed identically. Probe order depends on addresses;
nothing observable does, because lookup answers with a position and every hit is
confirmed by `strict_equals`. Rebuilding always from `entries` is what makes
that true, and the comment on `map_reindex` says so.

**The equality contract was settled first, which was the right order.**
`strict_equals` now compares a `Double` by bits, with all `NaN`s canonicalised
to one key. This is not a new rule — it is what `Double.equals` has always done,
so `algc` and JPascal disagreed about `NaN` and `-0.0` as `Map` keys and as
`Set`/`List` members, and no gate could see it. Making a `Double` hashable
forced the question, since a value not equal to itself can be stored and never
retrieved. `Collections.a24` gained four tests that pin it, including the
distinction that matters: the `=` **operator** still gives IEEE's answers, and
only membership changed.

The rest of this section is the original analysis, kept because the measurements
are what argued for the shape that was built.

---

**Severity: Medium.** Prototyped and measured; the numbers moved the
recommendation, so they are recorded here in full.

**Quadratic in *time*, not memory — unlike [D1](#d1).** `map_index`
(`algol.c:476`) scans every entry and calls `strict_equals` on each, so `Get`,
`Put`, `Contains` and `Remove` are all O(n) and filling a map costs O(n²)
*comparisons*. Growth itself is fine: `map_put` doubles, so the arena garbage
left by the discarded entry arrays sums to ~n, not n². This is a CPU problem,
and the `Buffer` fix has no bearing on it.

Measured, compiled at `-O2`, against the identical loop writing into a `List` so
the string building and loop overhead cancel out:

| n | fill a `Map` | same loop into a `List` |
|---|---|---|
| 8,000 | 0.25 s | 0.12 s |
| 16,000 | 0.52 s | 0.14 s |
| 32,000 | 1.79 s | 0.15 s |
| 64,000 | 7.25 s | 0.15 s |

~4.3× per doubling against a flat baseline. Textbook.

**What it costs *this* project today.** I instrumented `map_index` to count
calls and comparisons:

| Workload | Lookups | Comparisons | Largest map |
|---|---|---|---|
| `--compile compiler/Scanner.a24` | 10,701 | 712 K | 887 |
| `--compile compiler/CEmitter.a24` | 148,202 | 30.7 M | 4,480 |
| `--compile compiler/Main.a24` | 167,358 | 35.5 M | 5,049 |
| `--test compiler/Parser.a24` | 18,125,239 | **3.54 G** | 3,834 |

The compile path averages ~212 comparisons per lookup; the interpreter path
does **3.5 billion** `strict_equals` calls to run one module's test blocks. The
biggest single contributor is unglamorous: `SourceCode.Lines` (`SourceCode.a24:12`)
is a `Map` keyed by line number with one entry per source line, refilled per
file, so scanning a 3,000-line module inserts 3,000 keys each scanning all the
previous ones. `Environment.Values` and the resolver's `Locals` are next.

**Prototyped the fix and measured it.** I implemented the side index described
below in a scratch copy of `algol.c` — `entries` untouched and still in
insertion order, plus an open-addressed `int32_t` index from key to position,
built at 8 entries and kept under half load. ~70 lines.

| | linear scan | hash index |
|---|---|---|
| `--compile compiler/Main.a24` | 2.60 s | 2.55 s |
| `--test compiler/Main.a24` | 11.78 s | **8.24 s** |

It passes all 221 unit tests, all 8 conformance suites, and produces
**byte-identical output to the stock compiler** on all 23 differential programs
and on the emitted C for `compiler/Main.a24` — which is the property that
matters, since `fixedpoint` would otherwise catch it.

**This changes my recommendation.** I previously wrote that this was worth doing
"before the VM, not after, because the compiler itself uses maps heavily." The
first half of that was overstated: **compilation gets 2%**, which is nothing.
The win is entirely in the *interpreter* — **30% off the unit-test suite** —
because the tree-walker does three orders of magnitude more lookups than the
emitter. So it is worth doing for the edit-test loop and for anyone running
Algol-24 interpreted, and it is not worth doing for build times. It is also not
urgent for the VM, which will have its own lookup story.

**Three constraints the prototype turned up**, none of them in my original note:

- **`alg_remove` invalidates the whole index above the removed slot.** It
  `memmove`s the tail down one to keep insertion order, so every stored position
  shifts. The index must be rebuilt, not patched. That is O(n) — but `Remove`
  already pays O(n) for the `memmove`, so nothing regresses.
- **`Clear` must drop the index**, not just set `count = 0`.
- **Hashing an object by its address is safe, but only because nothing iterates
  the index.** `entries` keeps insertion order and is what `Keys`, `Values` and
  iteration read; if the index ever became the iteration source, pointer values
  would reach emitted text and `fixedpoint` would start failing intermittently.
  Worth a ⚠️ if this is implemented.

And the constraint I did have right: `strict_equals` requires an exact type
match, so the hash must key on type *and* value together — `1` and `1.0` are
different keys and must land in different slots. That is also why the `1 in
[1.0]` inconsistency in `ALGOL-24.md`'s rough edges cannot be fixed by promoting
on lookup.

### <a name="d3"></a>D3 — Name-based dispatch on every call and field access

**Severity: Medium. Partly addressed, and the diagnosis behind it corrects
mine.** The architectural item stands and belongs to project 3; what changed is
that a quarter of the cost I attributed to dispatch **was never dispatch**.

I wrote below that `fib(30)` runs 18.5 s interpreted against 0.023 s compiled,
and put the gap down to name lookup. Measured again on the working tree, with
the pre-change compiler rebuilt from `HEAD`'s checked-in seed for the baseline:

| | before (`99c01cb`) | after | |
|---|---|---|---|
| `algc` interpreting `fib(30)` | 18.76 s | **7.70 s** | 2.44× |
| of which **system** time | 2.03 s | **0.29 s** | 7× |
| `algc` compiling `compiler/Main.a24` | 2.98 s | **2.63 s** | 1.13× |

**The system-time column is the finding, and it is not one I made.** No amount
of `strcmp` produces two seconds of kernel time. On BSD-derived systems
`setjmp`/`longjmp` save and restore the signal mask — a `sigprocmask` each way —
and this interpreter implements `Exit` as a raise, so it paid one syscall per
interpreted call. Nothing in the runtime installs a handler or blocks a signal,
so there was no mask worth preserving. That is the single largest item and it
sits in a header, not in the dispatcher. My own §D3 measurement contained the
evidence and I read past it.

The other three are dispatch, and the arithmetic checks out against the
call volume the commit message reports (2.7 M interpreted calls → 285 M
`alg_property` and 147 M `find_method` calls):

- **`alg_stricmp` in place of `strcasecmp`.** `strcasecmp_l` goes through locale
  tables and came out *ahead of `strcmp`* in the profile. I verified the
  replacement is not merely close but **exactly equivalent**: 3,065,025 pairs —
  every ordered pair of one-byte strings over the full 1..255 range, plus three
  million random strings of length 0–8 over the same range — compared against
  `strcasecmp` for matching sign. **Zero mismatches.** The ⚠️ justifies this by
  identifiers being ASCII, which is true (`Scanner.a24:180` refuses anything
  else — see [C8](#c8) item 7), but the guarantee is stronger than that: the
  runtime never calls `setlocale`, so `strcasecmp` was folding ASCII and nothing
  else to begin with.
- **A name hash in `MethodEntry`, compared before the `strcmp`.** Correct by
  construction: `alg_class_method` (`algol.c:1180`) is the *only* site that
  writes a `MethodEntry`, and it hashes with the same seed and the same
  `hash_bytes` that `find_method` uses, so a mismatch can never be a false
  negative. The `strcmp` still guards, so a collision costs a comparison and
  nothing else. The growth path `memcpy`s whole entries, carrying the hash.
- **The first byte inline in `field_slot`.** Same shape, no hash.

**Two negative results are recorded in the ⚠️s, and they are the valuable
part** — a per-class method index cut the average scan from 15.2 entries to 1.00
and bought 0.5%, and hashing field names is *slower* because field lists average
1.8 entries. Both were measured rather than argued, and both are exactly the
"obvious fix" a future reader would otherwise try. Keeping the negative result
next to the code that declines to use it is the right call.

**What this does and does not change.** The compiled-vs-interpreted gap on
`fib(30)` narrows from ~800× to **~330×** (7.70 s against 0.023 s), and the gap
to the Java tree-walker from ~27× to **~10×** (0.77 s). That is a real
improvement to every compiled program, for about 25 lines and one token of
emitted-C difference. It is not a step toward the VM and does not pretend to be:
the remaining cost is call *volume*, not lookup, and no lookup optimisation
touches it. Treating the compiled tree-walker as a bonus rather than a goal, and
saying so in the commit, is the right framing — the reason to take these is that
each is cheap, safe, and helps everything the compiler emits.

⚠️ The one thing to fix before this ships is [C14](#c14): the `ALG_SETJMP` guard
tests for Windows where it means to test for BSD, and the seed stops building on
Linux.

**The original finding, unchanged:**

`alg_invoke` → `find_method` (`algol.c`) walks the superclass chain doing
`strcmp` per method entry, on every method call. `alg_property` → `field_slot`
does the same per field, on every field read — including a bare `Name` inside a
method of the class that declares it, where the slot is statically known at emit
time.

`vm/README.md` names this precisely (93% of calls go through `alg_invoke`) and
argues correctly that a gradually typed emitter frequently does not know the
receiver's type, so the VM's answer has to survive that rather than assume it
away. Measured cost of the tree-walker it is meant to replace: `fib(30)` runs in
**0.023 s** compiled against **18.5 s** interpreted, an ~800× gap.

**Recommendation.** Agree with deferring the general case. But two narrow wins
are available now without any of the VM's machinery, and both are cases where
the emitter *does* know the type:

- Inside a method, a bare field reference resolves to `alg_property(v_this,
  "Name")` (`CEmitter.a24:1894`). The class is known at that point, and its
  field list is closed and ordered — `algol.h:165-173` says so explicitly. Emit
  a slot index instead of a name.
- A `super.M()` call already emits `alg_invoke_from(k_Dog, ...)` with the class
  handle. The method could be resolved to a direct `m_` symbol at emit time
  whenever the superclass chain is fully known within the unit.

Both are strictly local to the emitter and would remove the majority of `strcmp`
traffic from typical class-heavy code, which also makes the eventual VM's
benchmark honest.

### <a name="d4"></a>D4 — `volatile` on every local of a body containing `try`

**Severity: Low.** Correct as written; noting the cost.

`ContainsTry` (`CEmitter.a24:1141`) drives a blanket `volatile` on every local of
any body containing a `try`, and the ⚠️ above it explains why: a non-volatile
local modified between `setjmp` and `longjmp` is indeterminate, which happens to
work at `-O0` and is a real hazard at `-O2`. Over-application is called out as
deliberate — precise liveness analysis is real work, and only bodies using `try`
pay.

I verified the hazard is genuinely covered, including a `try` inside a C-style
`for` mutating outer locals (`for` desugars into `BlockStmt { init; WhileStmt }`,
so `ContainsTry`'s `BlockStmt`/`WhileStmt` arms reach it; `case` desugars into
`IfStmt` chains, likewise covered). The C1 fix extended the qualifier correctly
to the new `DeclareCell` path (`:1188`), so hoisted cells in a `try` body get
`Value *volatile` as before.

**Recommendation.** Keep it. The cost is that a hot function containing one
`try` loses register allocation for *all* its locals, and the compiler's own
`Interpreter.c` has 61 `volatile` declarations as a result. If that ever shows
up in a profile, the cheap refinement is not liveness analysis but scope: only
locals declared *outside* the `try` can be affected by the jump, so locals
declared strictly inside a `try` block or inside a handler need no qualifier.
That is a syntactic test, not an analysis, and would cut most of the 61.

---

## Emitted-code quality

The emitted C is genuinely readable and maps almost line-for-line onto its
source. `super.Speak()` comes out as `alg_invoke_from(k_Dog, v_this, "Speak",
NULL, 0)`, which is obvious at a glance. Local shadowing of a field is handled
correctly. The `v_`/`f_`/`k_`/`m_`/`e_` prefixes are load-bearing rather than
cosmetic: they make collision with a C keyword structurally impossible, since
`v_int` is never `int`.

The closure emission after the fix reads well — the capture list is literally
the cells in scope at the declaration:

```c
Value *c_K = alg_cell(alg_nil());
(void)c_K;
*c_K = alg_int(7);
Value v_Grab = alg_closure("Grab", f_Grab, (Value*[]){c_K}, 1, 0);
```

Runtime UB handling is deliberate and commented: unsigned arithmetic for signed
overflow, `INT32_MIN / -1`, division by zero, and the `alg_error` path copying
its message into the arena before `longjmp` because the caller's buffer is about
to be unwound (`algol.c:1550-1565`) — that last one is a subtle bug the author
clearly hit and fixed.

The remaining items are cosmetic and unchanged.

### <a name="e1"></a>E1 — Unreachable `return alg_nil();`

Every emitted function body ends with `return alg_nil();` even when the
preceding statement is an unconditional `return`:

```c
static Value m_Animal_Speak_0(Value v_this, Value *args, int32_t count) {
    (void)v_this; (void)args; (void)count;
    return alg_add(alg_property(v_this, "Name"), alg_string(" makes a sound"));
    return alg_nil();
}
```

Harmless — no warning under `-Wall -Wextra`, and the optimiser drops it.

**Recommendation.** Optional. Suppressing it requires knowing whether the body
falls through, which is a small reachability check the emitter does not
currently do. Not worth adding on its own; worth taking for free if such an
analysis appears for another reason. Leaving it is fine — the unconditional
emission is what makes the "every function returns a Value" invariant trivially
true.

### <a name="e2"></a>E2 — `(void)` cast around `void`-returning calls

`alg_writeln` and `alg_write` return `void` (`algol.h:303-304`), but statement
emission wraps every expression statement uniformly:

```c
(void)(alg_writeln(alg_property(v_A, "Name")));
```

This casts a `void` expression to `void`. Legal C, no warning, no effect.

**Recommendation.** Cosmetic only. If the statement emitter ever gains a notion
of which builtins return a value, drop the wrapper for those. Not worth a
special case now.

### <a name="e3"></a>E3 — Argument compound literals do not overlap at `-O0`

Arguments are passed as compound literals — `alg_new(k_Animal, (Value[]){...},
1)` — which have block lifetime. At `-O2` clang overlaps them completely: a
synthetic `main` with 400 three-argument calls has a 64-byte frame. At `-O0`
they do not overlap: the same function takes **32,032 bytes** of stack, roughly
80 bytes per call site.

In practice this is bounded — the largest `-O0` frame in the compiler's own
generated code is ~5 KB (`CEmitter.c`), with `Parser.c` at ~2.2 KB. But
`./test.sh leaks` builds at `-O0 -g`, and stack cost there grows linearly with
call-site count per function.

**Recommendation.** No action. Recorded so it is not rediscovered as a mystery
if a very large generated function ever overflows a thread stack in a debug
build. The fix, if ever needed, is to hoist a single reusable `Value args[N]`
array per function rather than one literal per call site.

---

## Documentation and hygiene

### <a name="h1"></a>H1 — `bootstrap/build.sh`: Fixed

The script `README.md:9` advertises now exists, which is the resolution I
recommended (restore it rather than delete the claim). `build.sh:69` also gained
a `-x build.sh` exclusion with a ⚠️ explaining that neither the runtime nor the
hand-written script is generated, so neither appears in stage 2's output — the
right fix, and it makes the previously mysterious exclusion in `test.sh`
self-explanatory.

**The nit I raised is fixed too.** `bootstrap/build.sh:12-13` referred to
`algc/*.a24` and `./seed.sh --update`, neither of which exists; it now says
`compiler/*.a24` and `./build.sh --reseed`. That matters because this file is
the entry point for someone who has only the seed.

### <a name="h2"></a>H2 — `Mangle`'s `?` branch: Resolved

The branch is no longer dead: `IsAlpha` (`Scanner.a24`) now admits `?`, so
`Ready?` scans as one identifier and the `_q` mapping is live.

The collision I raised was resolved the *other* way from my recommendation —
kept and documented rather than made injective — and I think that is the better
call. `ALGOL-24.md:139` and the ⚠️ at `CEmitter.a24:345-351` both state it
plainly: the mapping is not injective, a scope declaring both `Ready?` and
`Ready_q` emits one symbol twice, and cc rejects it as a duplicate declaration.
Verified, including the multi-`?` form (`A??` against `A_q?`):

```
error: redefinition of 'v_Ready_q'
```

That is the right trade. The failure mode is a confusing message on a program
nobody writes, never wrong code; the injective alternative (`_` → `__`) would
rename every symbol in every emitted file, and the ⚠️ notes the corpus is full
of `TOKEN_` and `ANSI_`. Documenting the sharp edge and moving on is consistent
with how the project handles its other deliberate gaps.

Note this resolves the *mapping*; it does not resolve where the mapping is
applied — see [C5](#c5).

### <a name="h4"></a>H4 — Scan errors were recorded and never reported: Fixed

**Was High.** Not in my original review — I missed it. It is the most serious of
the bugs fixed in this round.

`Scanner` recorded an unrecognized character in `HadError`/`LastError` and
produced no token, and no driver ever asked. So `var A @ := 1;` scanned to a
token stream with the `@` silently dropped, and `algc` ran and compiled a
program the reference front end refuses — the two disagreeing about what is a
valid program, with nothing in the suite able to see it.

`CheckScanned` (`Main.a24:96`) is now called **twice** in each of the three
entry paths, which was my recommendation and which the ⚠️ explains precisely:
after `ScanTokens` to get the *message* right, and after `Parse` to get the
*coverage*, since `HadError` is module state that a `uses` clause's own scanner
also sets.

Both halves verified. All three messages the scanner can produce now surface, in
both the interpreted and compiled paths, with exit 70 and no files written:

| Program | Reported |
|---|---|
| `var A @ := 1;` | `[line 2] Error: Unexpected character: @` |
| `WriteLn('unterminated` | `[line 4] Error: Unterminated string.` |
| `var C := #x;` | `[line 2] Error: Invalid character: x` |

The unterminated-string case is the one the second call fixed: previously the
parse error raised first and it was reported as `Expect expression!`. A stray
`@` inside a `uses`d module is still caught, which only the post-`Parse` call
can see, and the `--test` path reports it too.

**One correction to my previous note.** I listed `var X := 1.;` as a second
masked scan error. It is not — the scanner never flags it. That `Invalid
character` branch belongs to `ScanChar` (the `#65` code-point form), and `1.`
scans cleanly as `1` followed by `.`, so `Expect property name after '.'.` is a
genuine parse error and the right message. There was only ever one masked case,
and it is fixed.

**Remaining suggestion (unchanged).** A conformance case per scan error
asserting exit 70 and the message. `tests/programs/` cannot express "both back
ends refuse this identically", and these three messages are now part of the
observable language.

---

### <a name="h3"></a>H3 — Duplicated comment in `VisitCall`: Fixed

The abbreviated restatement is gone; the full ⚠️ about a bound name shadowing
every builtin remains.

---

## What is worth preserving

Listed explicitly because a future refactor could erode it without noticing.

- **A bare class name has never been able to answer a dot.** This is the
  observation the whole unit feature rests on: because `Thing.Get()` on a bare
  class is `Only instances have properties.` in every version of this language,
  the dotted slot beside a class name is free, and `class Scanner` inside
  `Scanner.a24` can coexist with the unit `Scanner`. Eighteen of the compiler's
  own 22 units are that shape, so this is not a corner — it is the common case.
  Anything that later gives bare classes static members takes the unit syntax
  with it.
- **`Dottable` deliberately excludes classes and functions.** The ⚠️ at
  `Resolver.a24:44` is load-bearing for the same reason, from the other side.
  Adding classes to that set "for symmetry" would silently disable qualification
  for most of the compiler.
- **The precedence order is the language's existing order, not a new one.**
  Local, then a top-level name that can answer a dot, then a unit — nearest
  binding first, exactly as every other name resolves. I probed all three tiers
  and both back ends agree on each. Stated this way the rule needs no special
  case; stated as "units unless X" it would grow them.
- **⚠️ Program-wide over-approximation is safe for `Dottable` and unsafe for the
  shadow set, and the difference is direction.** `Dottable` can only ever
  *decline* to qualify, so an `object Console` in one file costs another file its
  qualifier and changes no meaning. The shadow set ([C9](#c9)) changes which
  binding a bare name reaches, so the same over-approximation breaks files that
  never opted in. The Resolver's comment gets this exactly right for its own set;
  the emitter's does not distinguish, and that is the bug.
- **The negative cases in `tests/programs/Shadowing.a24`.** A nested shadow that
  must not leak, a literal that must not reach the constructor, a property that
  must not be treated as a call. Each is a way the fix could have been written
  too broadly, and each is asserted rather than assumed. The file is a model for
  how to test a resolution change — its one gap is that everything in it lives in
  one file, which is what let [C9](#c9) through.
- **The fixed point is a determinism check, not just a correctness one.** The
  comment at `test.sh:151-155` says so. Any change that lets hash-order
  iteration, a timestamp, or an address reach emitted text will be caught here
  and nowhere else. `Map`'s insertion-order guarantee (D2) is part of what makes
  this hold — a hash index must not change iteration order.
- **The shared front end.** `Main.a24:166-172` explains that the emitter is one
  more consumer of the same statements the interpreter gets, so a program that
  fails to parse or check fails identically for both back ends. C1 was what it
  looks like when the two paths diverge below that point.
- **`Cells` as a scope-tracked list, distinct from `Boxed`.** The ⚠️ at
  `CEmitter.a24:226` is the most important comment added by the fix: `Boxed` is
  a whole-body decision and `Cells` is a point-in-emission fact, and conflating
  them is what made capture lists name cells that did not exist. Any future
  edit that reaches for `Boxed` when building a capture list reintroduces the
  bug.
- **Refusal over broken output.** `Unsupported` with an exact message and exit
  70, no partial files written. Four of this round's changes are applications of
  it — `Unreachable` on the read side, `RequireCell` on the write side,
  `RefuseBareBinding` where the interpreter has no single answer to reproduce,
  and `QuestionsOut`'s illegal-character guard. The pattern is now the project's
  main tool for keeping the two back ends honest with each other.
- **`Buffer`'s two refusals, `Free`-poisoning and no-`Text`-with-a-zero-byte.**
  Both look like gratuitous strictness and neither is: each one is a place where
  the two back ends *could* have quietly disagreed, closed by making the stricter
  behaviour the specified one. `as_buffer` being the single gate is what makes
  the first hold, the way `SymbolOf` makes C5 hold. A future edit that reads
  `buffer->bytes` without going through it reopens the hole.
- **Nothing observable may depend on a `Buffer`'s capacity.** `Length` is the
  size; printing shows the size; capacity is unreachable. The compiler now builds
  its own output in buffers, so the day that stops being true is the day
  `fixedpoint` starts failing for a reason nobody enjoys diagnosing. The ⚠️ in
  `algol.c` says this; it is now load-bearing in a way it was not when written.
- **`leaks` and `memory` ask different questions, and the difference is the
  whole point of the second one.** `leaks` asks whether memory was still
  *reachable* at exit; the arena returns every chunk it took, so a program that
  allocated 1.28 GB it never needed still reports `0 leaks for 0 total leaked
  bytes` — verified against the broken build, pointed straight at it. Anyone who
  later reads `tests/mem/` as "the leak tests with a number attached" and folds
  the two together removes the only instrument that can see [D1](#d1)'s and
  [C7](#c7)'s failure mode. The ⚠️ in `test.sh` and the one in `Drain.a24` both
  say so; keep both, because the person deleting the section will only read one.
- **The `MAXRSS` budgets are loose on purpose.** They are several times the real
  figure so the check tracks a change in complexity rather than a change in
  machine. Tightening them to "realistic" values converts a stable canary into a
  flaky one and is the most likely way this section gets switched off.
- **`entries` is the only thing that knows a `Map`'s order, and the index is
  only ever asked "where".** The ⚠️ on `ObjMap` says this and says why it is
  legality rather than tidiness: an object key hashes by its address, so the day
  the index becomes an iteration source is the day `fixedpoint` starts failing
  intermittently. `map_reindex` walking `entries` in order is the other half —
  it means a rebuild from scratch is always correct and the two can never
  disagree about contents. Any edit that inserts into the index without going
  through `entries` breaks both properties at once.
- **A `Double` is a key by its bits.** Not a performance choice — it is what
  makes a `Double` hashable at all, and it is what `Double.equals` has always
  done, so it is the two back ends agreeing rather than one of them choosing.
  Reverting `strict_equals`'s `VAL_DOUBLE` case to `==` reopens a divergence
  that nothing except `Collections.a24` can now see. The ⚠️ that the `=`
  *operator* is deliberately unaffected is the part most likely to be "fixed"
  by someone tidying up.
- **`SymbolOf` as the single place a name becomes a C symbol.** The ⚠️ at
  `CEmitter.a24:344-351` names the nine sites that used to build one by hand and
  says a bare `'k_' + Name` anywhere is the bug returning. That is the comment
  that keeps C5 fixed; a grep for it is a one-second review check.
- **Zero warnings under `-Wall -Wextra`.** Cheap to keep, expensive to recover.
  Worth wiring into `test.sh` as an explicit gate rather than relying on the
  default `CFLAGS`.
- **The ⚠️ convention.** Each one marks a constraint that a plausible edit would
  break, and several encode a bug that was already paid for once
  (`CollectBindings`' `VarGroupStmt` and `TryStmt` notes, `alg_error`'s message
  copy, the `volatile` rationale, `HoistCells`' per-block requirement). They are
  load-bearing.

---

## Appendix — reproductions

Kept as the cases that found the bugs, and as candidates for the suite. The
first two blocks below are closed; the rest are open.

### Now refused by name (were uncompilable C)

All five report `A 'var' as an unbraced branch or loop body is not supported by
the C back end yet.`, exit 70, no files written:

```pascal
if Flag then var Y := 5;                  // and the if/else form
while N < 1 do var W := N := N + 1;
for var E in [1, 2] do var W := E;
case N of 1: var Y := 5; end
```

Interpreted, the first three leak `Y`/`W` to the enclosing scope; the `for ...
in` form scopes it per iteration, so a read after the loop is `Undefined
variable 'W'`. That disagreement is why refusing beats reproducing.

### Now working (were uncompilable C)

```pascal
type State = (Idle?, Busy?);   class Gate?;   class Latch?(Gate?);   object Tally?;
```

plus a module file named `Helpers?.a24` reached by `uses Helpers?`, `G is Gate?`,
and overload dispatch on a `?`-typed parameter. All match interpreted output and
compile clean under `-Wall -Wextra -O2`.

### Still refused, by design

```pascal
begin
    var Ready?  := 1;
    var Ready_q := 2;      // both mangle to v_Ready_q
end
```
```
error: redefinition of 'v_Ready_q'
```

Documented at `ALGOL-24.md:139` and `CEmitter.a24:383-389`. Never wrong code —
see [H2](#h2).

### Scan errors, all three messages

Exit 70 interpreted and compiled, no files written:

```pascal
var A @ := 1;          // [line 2] Error: Unexpected character: @
WriteLn('unterminated  // [line 4] Error: Unterminated string.
var C := #x;           // [line 2] Error: Invalid character: x
```

### <a name="refusals-verified"></a>Refusals, verified against §9

Each reports the wording `ALGOL-24.md` §9 gives, exits **70**, and leaves the
output directory **empty**.

```pascal
class Dog;                              // Can't return a value from an initializer.
begin                                   // (refused by the Resolver, so both paths)
    procedure Init (N : String);
    begin
        Exit 5;
    end
end

var F := super.M;                       // 'super' as a value is not supported by
                                        // the C back end yet.  Runs interpreted.

if True then var X := 1;                // A 'var' as an unbraced branch or loop body
                                        // is not supported by the C back end yet.
```

The `super` case is the one worth keeping: it runs fine interpreted and is
refused compiled, which is precisely the surface §9 exists to describe.

### <a name="c7-repro"></a>C7 — draining a `Map`: now `tests/mem/Drain.a24`

Fixed, and the reproduction became the regression test. To confirm the canary is
alive, drop the `if` from `map_reindex` and run `./test.sh memory`:

```
FAIL  Drain -- 1436 MB, over its 64 MB budget
1 of 1 sections failed.                            # exit 70
```

The same broken binary under macOS `leaks --atExit`, with a 1,279 MB peak:

```
Process 32282: 0 leaks for 0 total leaked bytes.
```

That pair is the argument for the `memory` section in two lines, and is worth
re-running if anyone ever proposes merging it back into `leaks`.

The rest of the `Map` probe — thresholds, drain-and-refill, `Clear` twice, mixed
key types, object keys, order after removal, itemised under [D2](#d2) — produced
identical interpreted and compiled output on every build tested, before and
after the fix.

### <a name="c9-repro"></a>C9 — a shadow in one file breaks a file that never imported it

Three files. `Innocent.a24` imports nothing and calls the built-in `Max`.

```pascal
// Shadower.a24
function Max (A, B) : String;
begin
    Exit 'SHADOWER-MAX';
end
```
```pascal
// Innocent.a24  -- does NOT import Shadower
function AskInnocent () : Any;
begin
    Exit Max (3, 9);
end
```
```pascal
// Leak.a24
uses Shadower;
uses Innocent;

begin
    WriteLn (Max (3, 9));
    WriteLn (AskInnocent ());
end
```

Interpreted — correct, and what the compiled program must match:

```
SHADOWER-MAX
9
```

Compiled against the working tree:

```
./Innocent.c:9:12: error: returning 'int' from a function with incompatible result type 'Value'
    return f_Max(NULL, (Value[]){alg_int(3), alg_int(9)}, 2);
2 errors generated.
```

The same program against the pre-change compiler, rebuilt from `HEAD`'s seed —
it builds and runs, and shows [C6](#c6) instead:

```
9
9
```

So line 2 was right at `e86c86f` and is now a build failure; line 1 was wrong and
is now right. The emitted line is the whole difference:

| | `Innocent.c` |
|---|---|
| `e86c86f` | `return alg_max(alg_int(3), alg_int(9));` |
| working tree | `return f_Max(NULL, (Value[]){alg_int(3), alg_int(9)}, 2);` |

The file-scope-`var` variant, same cause, different message — `var Str := 'x';`
in one file, `Str(12)` in another that does not import it:

```
./GInnocent.c:9:29: error: use of undeclared identifier 'v_Str'
```

### <a name="c10-repro"></a>C10 — `System.X` inherits the shadow's type

```pascal
function Max (A, B) : String;
begin
    Exit 'mine';
end

begin
    var N : Integer := System.Max (1, 2);
    WriteLn (N);
end
```

`Uncaught: Type mismatch!`, both back ends. Delete the shadow and the same line
prints `2`. `WriteLn (System.Max (1, 2))` — the form the reference and the
`README` both show — passes either way, because `WriteLn` takes `Any`.

### Verified working, for the record

Each of these agrees interpreted and compiled:

| Probe | Result |
|---|---|
| `object Vals` outranks unit `Vals` | `the object` |
| file-scope `var Vals` outranks unit `Vals` | `a map` / `1` |
| a nested `Max` shadows inside its parent only | `nested-max` / `2` |
| enum through a unit — `Palette.Pick()`, `Palette.Red`, `Palette.Colour.Blue` | `Green` / `Red` / `Blue` |
| `System.Max` as a value | `2` interpreted, refused by name compiled |
| `System.Nope(1)` | `Undefined name 'Nope' in unit 'System'.` / refused by name |
| qualification across two `uses` hops (non-transitive) | `Undefined variable 'Shapes'.` interpreted; compiled inherits the pre-existing gap that an undefined name at file scope reaches `cc` — reproduces without units, so not new |
| two files with stem `Dup` | last-one-wins interpreted, as documented; compiled refuses with `Two modules named 'Dup'` |
| `unit` header mismatch | same message both ways (framing aside — [C8](#c8) item 6) |

### <a name="c14-repro"></a>C14 — the seed on Linux, before and after

Both runs are the same tree, the same `CFLAGS`, the same image. Only
`bootstrap/algol.h`'s `#if` differs.

```sh
$ docker run --rm -v "$PWD:/w" -w /w gcc:14 sh -c 'CC=gcc CFLAGS="-std=c11 -O2" ./build.sh'

# as committed
./algol.h:34:31: error: implicit declaration of function '_longjmp' ...
./algol.c:2064:1: warning: 'noreturn' function does return
FAIL  the seed does not build

# with the guard testing for BSD instead of for Windows
  stage 1: building the seed with gcc
  stage 2: that compiler compiles compiler/
  seed:    current -- compiler/ emits exactly the checked-in C
Built /w/algc
All green: conformance
All green: compiled
```

The one-line demonstration that this is about the guard and not about the
technique, run in the same image:

```c
#include <setjmp.h>
static jmp_buf b;
int main(void){ if(_setjmp(b)==0) _longjmp(b,1); return 0; }
```

```
gcc -std=c11    →  error: implicit declaration of function '_longjmp'
gcc -std=gnu11  →  ok
```

### <a name="stricmp-repro"></a>`alg_stricmp` against `strcasecmp`, exhaustively

Not a finding — the evidence for [D3](#d3)'s claim that the substitution is
exact rather than merely adequate. Every ordered pair of one-byte strings over
`1..255`, then three million random pairs of length 0–8 over the same range,
comparing the *sign* of each result:

```
compared 3065025 pairs, 0 mismatches
```

The reason it is exact for non-ASCII too, which the ⚠️ does not claim: nothing
in the runtime calls `setlocale`, so `strcasecmp` was already folding in the `C`
locale, where only `A`–`Z` fold.

### Still open — the design items

**C4's ⚠️ — `while` does not raise `'W' is already defined`** (prints `survived`
then `3`; the binding leaks, as in `if` and `case`)

```pascal
begin
    var M := 0;
    while M < 3 do var W := M := M + 1;
    WriteLn('survived');
    WriteLn(W);
end
```

**D1's cliff, still present for the naive idiom** — and the linear alternative
beside it. 40,000 appends: **770 MB** the first way, **under 1 MB** the second.
Both back ends agree on the first (775 MB interpreted, 770 MB compiled), which
is what `ALGOL-24.md:222` currently denies.

```pascal
begin
    var S := '';
    for var I := 0; I < 40000; I := I + 1 do
        S := S + 'x';

    var B := Buffer();
    for var I := 0; I < 40000; I := I + 1 do
        B.Append('x');
    var T := B.Text;
end
```

**D4 — `volatile` correctness under `-O2`** (passes; worth keeping as a
regression test)

```pascal
begin
    var Total := 0;
    var Log := '';
    for var I := 0; I < 5; I := I + 1 do
    begin
        try
            Total := Total + I;
            Log := Log + Str(I);
            if I = 3 then raise 'boom';
            Total := Total + 100;
        except
            on E : String do Log := Log + '[' + E + ']';
        end
    end
    WriteLn(Total);      // 410
    WriteLn(Log);        // 0123[boom]4
end
```

**C-style `for` loop variable is shared, not per-iteration** (both back ends
print `3 3 3` — settled semantics, but worth a test since `for ... in` is
deliberately the opposite)

```pascal
begin
    var Made := [];
    for var I := 0; I < 3; I := I + 1 do
    begin
        function Held();
        begin
            Exit I;
        end
        Made.Add(Held);
    end
    for var F in Made do WriteLn(F());
end
```
