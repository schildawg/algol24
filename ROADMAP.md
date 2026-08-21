# Roadmap to 1.0

The backlog **is** the first release. Schildawg specified it feature by feature,
Plumb wrote it up as issues and conformance tests, and when it is empty Algol-24
is at v1. Nothing here proposes deferring any of it.

What this document adds is **order**, which is the one thing left open — the
issues gate one another, and much of the gating is recorded inside issue bodies
rather than anywhere a reader would look.

**Thirty-eight open issues — thirty-four of them language defects — and no open
decisions.** The release criterion's first half is met: what stands between here
and 1.0 is work rather than questions.

⚠️ Count these with an explicit limit. `gh issue list` silently defaults to
`--limit 30`, which is below the backlog and will quietly under-report it.

Owned by Tiller. Written against `43207e9`, in which Plumb folded all seven
rulings into [`ALGOL-24.md`](ALGOL-24.md) and filed the implementation work each
one left behind.

> **This document is derived and disposable.** The
> [issues](https://github.com/schildawg/algol24/issues) are the source of truth,
> and the `priority/N` label on each one is the durable artefact — it lives
> where the truth lives. This file is a summary for reading the shape of the
> release in one place. When it drifts from the issues, the issues win and this
> gets rewritten from them, priorities re-derived. Do not resolve a
> disagreement in its favour.

---

## How to read this

Two orthogonal things are in play, and conflating them is the easy mistake.

**Priority (`priority/1` … `priority/7`) is pull order.** It is baked into the
issue labels. The rule is mechanical: *if A gates B, A has a strictly lower
number than B*, and *if A makes B easier, A is lower too*. A Developer may pull
anything in the lowest-numbered band that still has work left in it. Ties are
deliberate — there are 5 ones and 8 twos, and any of them is a legitimate next
pull.

**A milestone is a coherent state of the language**, something describable in a
sentence. Milestones are ordered; priorities decide what to take *within* the
work that is currently reachable.

The two agree because both derive from the same dependency graph — 26 gating
edges, verified to have no violations — but they answer different questions.

---

## ⚠️ The constraint that shapes everything: reseeds serialize

Every change to `compiler/` ends in `./build.sh --reseed`, which commits
`compiler/` together with the regenerated `bootstrap/`. That generated C covers
every emitted symbol in the compiler.

**Two tracks worked in parallel will conflict in `bootstrap/` on nearly every
file, and the conflict cannot be resolved by hand** — you would have to drop one
side and re-reseed. This backlog does not parallelize the way its dependency
graph suggests. In practice: one reseed owner, or land milestones strictly in
order, or batch several issues into one reseed.

Two consequences that drove the ordering below:

- **Work that churns the whole seed goes first.** Anything touching `Mangle`,
  identifier case folding, or the symbol scheme rewrites every symbol in
  `bootstrap/`. Landing it late means every other track's seed diff gets
  rewritten underneath it. That is why M1 and M2 are where they are.
- **`bootstrap/algol.[ch]` is the exception.** The hand-written runtime is
  copied verbatim into every emitted directory, so a change there takes effect
  **without a reseed**.

### This is a capacity limit, not only a merge risk

Worth stating plainly, because it decides how many people can work on Algol-24
at once and no amount of git discipline changes it.

If two tracks that both reseed cannot be merged by hand, then M1's whole-seed
work — `Mangle`, the case fold, the symbol scheme — is **not parallelisable at
all**. Not "cheaper done first": there is no branch, worktree or convention
under which two people do it concurrently and both results survive. Separate
worktrees protect each session's *uncommitted* files from the other; they do
nothing about two people regenerating the same hundred-odd generated files.

So while a whole-seed track is held, the work a second person can pick up is a
**short and enumerable list** — everything that touches no `compiler/` source:

| | Priority | Touches |
|---|---|---|
| [#23](https://github.com/schildawg/algol24/issues/23) | `priority/1` | `compile.sh` — shell only, no compiler and no runtime |
| [#27](https://github.com/schildawg/algol24/issues/27) | `priority/1` | `bootstrap/algol.c` — guards in `collection_method` |
| [#33](https://github.com/schildawg/algol24/issues/33) | `priority/3` | `bootstrap/algol.c` — the same guards, by kind |
| [#40](https://github.com/schildawg/algol24/issues/40) | `priority/4` | `bootstrap/algol.c` — the `Uncaught: ` prefix at the reporting point |
| [#24](https://github.com/schildawg/algol24/issues/24) [#26](https://github.com/schildawg/algol24/issues/26) [#25](https://github.com/schildawg/algol24/issues/25) | `4`/`5`/`6` | `bootstrap/algol.[ch]` for the SDL side; the built-in registration still needs `compiler/` |

That is the whole of it, and it is a better list than it looks: **two of the
five are `priority/1`**, so the highest-value concurrent work and the
highest-value serialised work do not compete.

⚠️ #33's *interpreter* half is [#41](https://github.com/schildawg/algol24/issues/41),
which is `compiler/ObjCollection.a24` and does need a reseed. The pair splits
neatly along the line: runtime guard concurrent, interpreter table serialised.

---

## ⚠️ Ten issues have no reproduction, and that gates closing them

Prime Directive condition 1 is *"every test associated with the issue passes"*,
and it is measured against `tests/defects/`. **An issue with no reproduction has
nothing to close against** — a Developer can fix it, run every suite green, and
still not have met condition 1.

Plumb owns those files and records ten as owed. Ordered by the priority this
document gives them:

| | Priority | Reproduction |
|---|---|---|
| [#27](https://github.com/schildawg/algol24/issues/27) | `priority/1` | **owed** |
| [#37](https://github.com/schildawg/algol24/issues/37) [#42](https://github.com/schildawg/algol24/issues/42) | `priority/2` | owed |
| [#33](https://github.com/schildawg/algol24/issues/33) [#41](https://github.com/schildawg/algol24/issues/41) [#44](https://github.com/schildawg/algol24/issues/44) | `priority/3` | owed |
| [#39](https://github.com/schildawg/algol24/issues/39) [#40](https://github.com/schildawg/algol24/issues/40) [#45](https://github.com/schildawg/algol24/issues/45) | `priority/4` | owed |
| [#29](https://github.com/schildawg/algol24/issues/29) | `priority/5` | owed |

**This is a dependency that runs across roles rather than between issues**, and
it is the one kind the priority labels cannot express: they order the
*Developer's* queue, and here Plumb is upstream of it.

🚩 **#27 is the sharp case.** It is `priority/1`, it is the only crash in the
backlog, it is one of the five things pullable while the seed is held — and it
has no reproduction. Whoever fixes it first has nothing to prove it fixed.

Three further rows read *not reproducible here* and are **not** arrears:
[#4](https://github.com/schildawg/algol24/issues/4) is covered in
`tests/defects/refuse/`, since its correct outcome is a refusal and a refusal is
the absence of a run; [#28](https://github.com/schildawg/algol24/issues/28)
closes on a count and [#43](https://github.com/schildawg/algol24/issues/43) is
behaviour-preserving, so neither will ever have a file.

Of the ten, Plumb reports **#33, #41 and #42 are writable now** that the `Set`
rules are settled, and **#37, #44 and #45 wait on #37's replacement wording** —
which is itself a reason to take #37 early, beyond the one already given.

---

## M1 — Ground: freeze the symbols, stop the crash, make the tools honest

*Nothing computes a wrong answer silently, nothing segfaults, and the symbol
scheme every later milestone emits into is settled.*

| | Priority | Issue |
|---|---|---|
| [#23](https://github.com/schildawg/algol24/issues/23) | `priority/1` | `compile.sh` silently discards every option but `--run` |
| [#27](https://github.com/schildawg/algol24/issues/27) | `priority/1` | A wrong-arity call to a collection method segfaults compiled code |
| [#3](https://github.com/schildawg/algol24/issues/3) | `priority/1` | Two enum members can emit one C symbol |
| [#33](https://github.com/schildawg/algol24/issues/33) | `priority/3` | Compiled code lets a `Set` hold duplicates and an `Array` change length |
| [#41](https://github.com/schildawg/algol24/issues/41) | `priority/3` | The interpreter refuses harmless collection synonyms and `S[0]` on a `Set` |
| [#5](https://github.com/schildawg/algol24/issues/5) | `priority/3` | The `Length` built-in measures a collection's rendering |

**Start with #23.** It is a shell script, it gates nothing, and it is P1 anyway:
`./compile.sh X --test` currently reports success for a *failing* suite, so a
Developer verifying any other ticket in this document can get a green they did
not earn. It is upstream of every verification here and it is an hour's work.

**#3 before anything Unicode.** It fixes a silent wrong answer today *and* it is
where the separator scheme is chosen. `_` is a legal identifier character, so
`e_` + type + `_` + member has never been injective. Both
[#2](https://github.com/schildawg/algol24/issues/2) and
[#18](https://github.com/schildawg/algol24/issues/18) build on that scheme;
choosing it twice is the waste to avoid.

**#33 and #41 are two halves of one rule** — the compiled guard and the
interpreter's matching permissiveness — and neither gates the other. They may be
pulled together or apart.

⚠️ **The `Set` ruling is neither of the two answers that were on the table**, so
read [*Positions on a `Set`*](ALGOL-24.md) before starting. It is not
"refuse" and not "deduplicate":

| Call on a `Set` already containing `V` | Meaning |
|---|---|
| `S.Add(V)`, `S.Push(V)` | nothing happens; `V` keeps the position it has |
| `S.Insert(I, V)` | `V` **moves** to position `I` |
| `S.Set(I, V)` | refused: `Cannot hold two equal elements.` |
| `S.Fill(V)` | every element becomes `V`, so the set collapses to `V` alone |

So most of #33 and #41 is **acceptance** testing in `tests/defects/`, not
refusal fixtures in `tests/defects/refuse/`.

⚠️ `Cannot hold two equal elements.` exists in **neither processor** — verified
by grep across `compiler/` and `bootstrap/`. It is a new sentence, and refusal
sentences are compared verbatim by the harness, so it has to be written exactly
once and identically on both sides.

**A pattern worth sweeping for, not three coincidences.** #27, #33 and
[#42](https://github.com/schildawg/algol24/issues/42) are all the same shape in
`bootstrap/algol.c`: a name-keyed dispatch branch with no receiver guard at the
tail of a chain. Whoever takes #27 should look for the rest rather than fixing
only the three we tripped over.

---

## M2 — Text: Unicode, and strings as collections of `Char`

*Schildawg's highest-value milestone. Text is code points, identifiers admit the
world's letters, and a name means the same thing however it is spelled.*

| | Priority | Issue |
|---|---|---|
| [#6](https://github.com/schildawg/algol24/issues/6) | `priority/1` | A `String` is a sequence of bytes, and the specification says code points |
| [#2](https://github.com/schildawg/algol24/issues/2) | `priority/2` | Identifiers do not accept `!` or Unicode letters |
| [#1](https://github.com/schildawg/algol24/issues/1) | `priority/2` | Identifiers are case-sensitive and are meant to be case-insensitive |
| [#42](https://github.com/schildawg/algol24/issues/42) | `priority/2` | A `String` does not answer the non-mutating collection members |

**Why the Unicode headline issue is P2 and not P1.** #2 is the one that *sounds*
like Unicode support, and two things sit above it. #3 (M1) must fix the symbol
scheme first, because every non-ASCII code point needs an injective mapping into
a C identifier. And #6 makes #2 dramatically easier: the scanner has no notion
of a code point today, so it refuses **per byte** — one `é` produces two errors
and echoes raw bytes, which is why
[`tests/defects/run.sh`](tests/defects/run.sh) had to move its output filters to
`LC_ALL=C`. #6 is what makes the scanner code-point aware; doing #2 first means
building that awareness in the error path and then rebuilding it for strings.

**So the whole Unicode story is four tickets: #3, #6, then #2 and #1 together.**

⚠️ **#6 is the largest single item in the backlog and the only one carrying a
measurable performance risk.** It forces the string storage decision, and
`Scanner.a24` reads its source as `Source[Current]`. If `S[i]` becomes O(n) over
UTF-8 storage, the scanner becomes O(n²) over the ~14k lines of its own source
that every build scans. Plumb sketched three representations and favoured
option 3 — keep UTF-8, accept O(n) indexing, and give the scanner a **cursor**,
since its access is sequential and only *spelled* as random access. Measure
before committing: `./test.sh memory` and the `/// MAXRSS:` budgets in
`tests/mem/` exist precisely to catch a change in complexity.

⚠️ #1 and #2 may land in either order, but **whichever lands second must revisit
the other's assumption** — `alg_stricmp` (`algol.c:522`) folds ASCII on the
stated grounds that identifiers *are* ASCII, which stops being true when #2
closes. Landing them together avoids the revisit.

⚠️ **#42 must not land apart from #6, and this is the hardest edge in the
graph.** If a `String` is a collection of `Char`, then `S.Length` counts code
points — so `S.Length`, `Length (S)` and `for C in S` have to agree on the unit.
Fixing them to different units is worse than fixing neither, because it converts
one known gap into a silent disagreement. #42 is priced `priority/2` rather than
lower for exactly this reason: it needs to surface directly behind #6 rather
than sink to where a Developer would pull it months later.

---

## M3 — The type system means something

*Annotations are inferred where they can be, enforced consistently where they
are written, and diagnostics point at the source.*

| | Priority | Issue |
|---|---|---|
| [#28](https://github.com/schildawg/algol24/issues/28) | `priority/1` | Type inference is incomplete — 285 sites in `compiler/` |
| [#37](https://github.com/schildawg/algol24/issues/37) | `priority/2` | `Type mismatch!` carries no file, line or caret |
| [#4](https://github.com/schildawg/algol24/issues/4) | `priority/3` | An unresolved name emits invalid C instead of being refused |
| [#7](https://github.com/schildawg/algol24/issues/7) | `priority/3` | `Char` does not widen to `String`, `Integer` does not widen to `Double` |
| [#14](https://github.com/schildawg/algol24/issues/14) | `priority/3` | Only `List` takes an element type |
| [#43](https://github.com/schildawg/algol24/issues/43) | `priority/2` | Untyped and `Any` are two representations in `TypeChecker` and are one type |
| [#44](https://github.com/schildawg/algol24/issues/44) | `priority/3` | Assignability accepts `Any` in both directions |
| [#45](https://github.com/schildawg/algol24/issues/45) | `priority/4` | Delete `as` once the checker no longer needs it |

**The order inside this milestone is the whole point.** The sequence ruled in
[#32](https://github.com/schildawg/algol24/issues/32) is:

1. unify untyped and `Any` in `TypeChecker`
2. fix inference — [#28](https://github.com/schildawg/algol24/issues/28)
3. make `Assignable` asymmetric, on all five paths
4. delete `as`

Applying step 3 before step 2 would demand 285 `as` casts in `compiler/` — the
exact casts step 4 exists to delete.

All four now have tickets — [#43](https://github.com/schildawg/algol24/issues/43),
#28, [#44](https://github.com/schildawg/algol24/issues/44) and
[#45](https://github.com/schildawg/algol24/issues/45). Three of them did not
when this document was first written; #28 sat in the neighbourhood and read as
covering a chain it is only the middle of.

**#43 is the one to pull today.** It is the only step of the four not waiting on
#28: both spellings short-circuit identically at `TypeChecker.a24:288-289`, so
merging them is **behaviour-preserving**. It must also land *before* #44 rather
than with it — written against two representations the asymmetric rule becomes
four conditions with a chance for the pair to drift, and a drift between
"untyped" and `Any` is precisely the distinction the ruling says does not exist.

**#45 closes on a count, not an edit**, which is the useful shape for this
graph: **63 `as` casts in `compiler/` at `43207e9`**, across nine files —
Interpreter 18, Environment 14, CEmitter 11, TypeChecker 6, Parser 5, ObjClass
4, Resolver 3, ObjInstance 1, Scanner 1. Each is a place the checker gave up.
The keyword goes when that number does, and if it stalls well above zero that is
a finding about **#28**, not a reason to keep `as`.

⚠️ `Environment.a24`'s fourteen are nearly all one shape —
`Imports[I] as Environment`, `Owner as Environment`, `Enclosing as Environment`:
a subscript and a field read whose type the class declaration already states.
That is `SubscriptExpr` and `GetExpr` in #28's table, and a small self-contained
root — likely the cheapest place to demonstrate that the 63 falls.

⚠️ **#45 is the only source-compatibility break in the backlog.** Any Algol-24
program outside this repository using `as` stops parsing. Acceptable pre-1.0,
and a reason not to let it drift past the release.

**#32's final ruling tightened this dependency rather than loosening it.** An
unannotated declaration now *infers* its type, and the inferred type describes
the variable without constraining what may be written to it. So inference
decides whether an annotated declaration can be **satisfied at all**, not merely
how well it is checked. The ordering below was prudent when written; it is now
load-bearing.

**#37 before step 3, not after.** Today a type mismatch is comparatively rare
because the checker often has no type to compare with. After #28 and #32 it
becomes the diagnostic a programmer meets most — and it is the worst one in the
compiler, with no position and no type names, raised byte-identically from five
different sites — **and those five sites are precisely the ones the asymmetry
rule fires from.** Fixing it afterwards means the stricter rule's debut is
several hundred positionless errors. This was contingent when written; the
ruling went the way that triggers it, so it is now unconditional.

`ALGOL-24.md`'s *Static errors* section now states positively that every static
error carries file, line and caret, naming #37 as the gap — so this is a
conformance failure against the specification rather than a wish.

**#7 is the most user-visible wrongness in the entire backlog.** `'A' = Str('A')`
answers `False` today, silently, which means a `Map` keyed with `'A'` cannot be
found with `Str('A')` and the program meets it as a lookup that mysteriously
misses. It needs #6 (M2) for the code-point ordering rule.

---

## M4 — Numbers

*One ladder, one literal rule, and the spellings a modern language is expected
to accept.*

| | Priority | Issue |
|---|---|---|
| [#8](https://github.com/schildawg/algol24/issues/8) | `priority/2` | An integer literal too large for `Integer` is silently truncated |
| [#9](https://github.com/schildawg/algol24/issues/9) | `priority/4` | `Byte`, `Short`, `Long` and `Single` do not exist |
| [#10](https://github.com/schildawg/algol24/issues/10) | `priority/5` | No hex, octal, binary, exponent or digit separators |

**#8 first and it does not have to wait for this milestone.** It is P2, it is
wrong today with no new types involved, and refusing an oversized literal is
correct under either type set — the smaller change. Doing #10 before #8 would
multiply the ways to hit a silent truncation, since `0xFFFFFFFF` is eight
characters.

⚠️ #9 imposes a hard requirement that comes from
[#11](https://github.com/schildawg/algol24/issues/11) in M5: **every type that
may appear in a signature must be distinguishable at run time.** With `F(Byte)`
and `F(Integer)` declared and a `Byte` argument, a static resolver picks
`F(Byte)` while a runtime storing `Byte` as a plain integer picks `F(Integer)` —
same call, two functions, no diagnostic. Design the tags for that now rather
than retrofitting.

---

## M5 — Calls resolve correctly, and resolve the same way twice

*A call selects the most specific candidate, and the compiler and the runtime
always agree on which.*

| | Priority | Issue |
|---|---|---|
| [#12](https://github.com/schildawg/algol24/issues/12) | `priority/2` | Overload resolution is first-declared-wins rather than most-specific |
| [#13](https://github.com/schildawg/algol24/issues/13) | `priority/2` | A call matching no signature runs anyway when compiled |
| [#22](https://github.com/schildawg/algol24/issues/22) | `priority/2` | A wrong-arity call is not checked when compiled |
| [#11](https://github.com/schildawg/algol24/issues/11) | `priority/5` | Top-level functions cannot be overloaded |
| [#15](https://github.com/schildawg/algol24/issues/15) | `priority/6` | Parameters have no defaults, and arguments cannot be named |
| [#16](https://github.com/schildawg/algol24/issues/16) | `priority/7` | No variadic parameters, and no way to spread |

**#13 and #22 are one defect in two reports** — the compiled path treats a
declared parameter type *and* a declared arity as hints. Worth pulling together.
Both are also what #27 (M1) crashes through, so M1 will have touched the
neighbourhood.

**The standing cost to design for.** Every call-site feature added here has to
be visible to the *runtime* dispatcher, or the compiled and interpreted halves
resolve differently: parameter types (#9), then parameter names (#15), then a
variadic flag (#16) — three registration fields, added one at a time.
`alg_class_method` carries a name, an arity and a type signature today. Cheaper
to design for than to retrofit.

---

## M6 — Modules, statements and objects

*The remaining language surface, mostly independent of everything above.*

| | Priority | Issue |
|---|---|---|
| [#17](https://github.com/schildawg/algol24/issues/17) | `priority/3` | A type name cannot be qualified by its unit |
| [#18](https://github.com/schildawg/algol24/issues/18) | `priority/4` | Two units cannot export the same name |
| [#20](https://github.com/schildawg/algol24/issues/20) | `priority/4` | The `constructor` keyword is decorative |
| [#21](https://github.com/schildawg/algol24/issues/21) | `priority/4` | A constructor invoked on an instance yields the instance / `nil` |
| [#39](https://github.com/schildawg/algol24/issues/39) | `priority/4` | Compiled code defers every `begin…end` block to the end of the program |
| [#40](https://github.com/schildawg/algol24/issues/40) | `priority/4` | An uncaught built-in error prints without the `Uncaught: ` prefix compiled |
| [#19](https://github.com/schildawg/algol24/issues/19) | `priority/5` | No `continue`, no statement labels, and no `goto` |
| [#29](https://github.com/schildawg/algol24/issues/29) | `priority/5` | Subscript refusal sentence differs between processors |

**#17 before #18, and the reproduction proves it.** `DuplicateExport.a24`
currently fails on its qualified *type annotations*, before the duplicate export
is ever reached — so qualified type names must land first or that reproduction
cannot reach the defect it exists for. #18 additionally needs #3's separator
(M1), because making `Name__Unit` the mechanism for every duplicated export puts
far more names through a join that has never been injective.

**#19 is internally ordered.** `continue` and the labels are independent and can
land first; `goto` follows, and it is the only part of the backlog that requires
the *interpreter* to change shape — block execution has to become resumable,
because an exception travels only outward and a backward jump does not.

**#40 is the free one.** It touches `bootstrap/algol.c` and nothing else, so it
needs no reseed — the only non-graphics ticket in the backlog that can be pulled
while another track holds the seed. ⚠️ The prefix belongs at the *reporting*
point, not at each `alg_error` call site: a message that gets **caught** must not
carry the word `Uncaught`, or a handler inspecting the string would see it.

**#39 is self-contained** — `CEmitter.a24:1091-1100`, emitting the root unit's
block statements inline in `init_Root` rather than hoisting them into `main`.

---

## M7 — Graphics (runs alongside)

*Client-driven, and the only external demand signal in the backlog.*

| | Priority | Issue |
|---|---|---|
| [#24](https://github.com/schildawg/algol24/issues/24) | `priority/4` | `Draw` cannot take a source rectangle |
| [#26](https://github.com/schildawg/algol24/issues/26) | `priority/5` | A window cannot be full-screen, and there is no logical size |
| [#25](https://github.com/schildawg/algol24/issues/25) | `priority/6` | `Draw` cannot scale |

**This is the one milestone that genuinely parallelizes**, because the SDL work
lives in `bootstrap/algol.[ch]`, which is copied verbatim and needs no reseed.
The built-in registration in the interpreter and emitter still does, so it is
partial — but the bulk of it can proceed while another track holds the reseed.

**#24 first.** It has no workaround, and it is the primitive that lets text be
written *in* Algol-24 as a library — a bitmap font is a `Map` of glyph rects and
a loop over `Draw` — rather than putting font loading, metrics and shaping
inside the compiler. That is exactly what
[Future directions](ALGOL-24.md#future-directions) argues for.

**#26 ahead of #25.** #25 has a workaround an artist would use anyway (export
the art at the size you need). #26 is one SDL call — `SDL_RenderSetLogicalSize`
— that would delete the reporting project's `scale-art.sh`, its 6.7 MB of
pre-scaled PNGs, and a pair of scale constants threaded through every
coordinate. Better value at similar cost.

⚠️ #24 overloads `Draw` **by arity**, so until #12 (M5) lands, declaration order
decides which form a call reaches. Either sequence #24 after #12 or accept the
order-sensitivity knowingly.

---

## Housekeeping

Nothing outstanding. [#30](https://github.com/schildawg/algol24/issues/30) —
`(* … *)` comments in the issue prose — is **closed**, and turned out to be
wider than filed: the form was in `ALGOL-24.md` itself as well, 12 lines across
4 blocks, plus 36 comments across fourteen issues. Plumb then parsed all 47
`pascal` blocks in the specification and swept for `==`, `!=`, C-style `!`,
`return` and both brace comment forms, finding no second instance.

---

## Explicitly out of scope for 1.0

Not deferred backlog — never in it.

- **Primitives with methods** — `8.DownTo(1)`, `'123'.IntegerValue()`. A
  direction Schildawg likes and will discuss with Plumb. It weighed on the
  ruling that a `String` answers the collection members — which is why
  `S.Length` was allowed rather than refused — but the feature itself is
  post-1.0.
- **A foreign function interface** — the intended path for native capabilities,
  so that a capability becomes a library rather than an edit to the compiler and
  two reseeds. Named in
  [Future directions](ALGOL-24.md#future-directions); does not block the
  release.

---

## Open questions

Both of the questions this document opened with are answered. #34's
refuse-or-deduplicate was ruled — and came out as neither, see M1 — and the
`ParamStr(0)` absoluteness question Plumb closed by **naming it unspecified** in
the specification rather than guessing: both processors answer an absolute path,
but the edge cases (`algc` invoked with no arguments, or under `--test`) were
unprobed, and naming a hole beats writing a rule nobody checked. That is the
right call and I would leave it named rather than spend a probe on it now.

What is open instead:

1. **The project board is behind.** `gh project item-list 2` shows
   items #1–#23; everything filed since is invisible to it.

   Schildawg has since ruled that **the issues are the source of truth** and
   this document is a disposable summary, which settles the part that mattered:
   nobody should be pulling from a view. If the board is kept anyway, the split
   worth defending is Plumb's — **reasoning here, status there, neither
   duplicating the other's job**, since a board field cannot hold a dependency
   argument and a markdown file cannot hold state without going stale.
