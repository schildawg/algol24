# Roadmap to 1.0

The backlog **is** the first release. Schildawg specified it feature by feature,
Plumb wrote it up as issues and conformance tests, and when it is empty Algol-24
is at v1. Nothing here proposes deferring any of it.

What this document adds is **order**, which is the one thing left open — the
issues gate one another, and much of the gating is recorded inside issue bodies
rather than anywhere a reader would look.

Owned by Tiller. Written against `c24cbb5`, after the seven open decisions in
[`ALGOL-24.md`](ALGOL-24.md#open-decisions) were ruled.

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
  **without a reseed**. That is what lets the graphics work (M7) genuinely run
  alongside everything else.

---

## M1 — Ground: freeze the symbols, stop the crash, make the tools honest

*Nothing computes a wrong answer silently, nothing segfaults, and the symbol
scheme every later milestone emits into is settled.*

| | Priority | Issue |
|---|---|---|
| [#23](https://github.com/schildawg/algol24/issues/23) | `priority/1` | `compile.sh` silently discards every option but `--run` |
| [#27](https://github.com/schildawg/algol24/issues/27) | `priority/1` | A wrong-arity call to a collection method segfaults compiled code |
| [#3](https://github.com/schildawg/algol24/issues/3) | `priority/1` | Two enum members can emit one C symbol |
| [#34](https://github.com/schildawg/algol24/issues/34) | `priority/2` | **DECIDED** — collection methods refused only where they violate the kind's invariant |
| [#33](https://github.com/schildawg/algol24/issues/33) | `priority/3` | Compiled code lets a `Set` hold duplicates and an `Array` change length |
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

⚠️ #34 is a specification write and must land before #33, which implements it.
#34 also leaves **one sub-question open** — for a `Set`, whether `Push`,
`Insert` and `Set` are *refused* or *accepted and deduplicated*. Both preserve
uniqueness. It decides whether #33's reproductions belong in `tests/defects/` or
`tests/defects/refuse/`, so it needs answering before they are written.

**A pattern worth sweeping for, not three coincidences.** #27, #33 and
[#35](https://github.com/schildawg/algol24/issues/35) are all the same shape in
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
| [#35](https://github.com/schildawg/algol24/issues/35) | `priority/4` | **DECIDED** — a `String` is a collection of `Char` |

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

⚠️ #35 must not be fixed to a different unit than #6. `S.Length`, `Length (S)`
and `for C in S` all have to agree, and #6 is what makes them agree.

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
| [#32](https://github.com/schildawg/algol24/issues/32) | `priority/3` | **DECIDED** — untyped and `Any` are one concept, and `Any` does not widen back |

**The order inside this milestone is the whole point, and #32 is last.**
Applying the strict rule before inference is complete would demand 285 `as`
casts in `compiler/` — the exact casts the ruling exists to let you delete. The
sequence is: unify untyped and `Any` → fix inference (#28) → make `Assignable`
asymmetric (#32) → delete `as`.

**#37 before #32, not after.** Today a type mismatch is comparatively rare
because the checker often has no type to compare with. After #28 and #32 it
becomes the diagnostic a programmer meets most — and it is the worst one in the
compiler, with no position and no type names, raised byte-identically from five
different sites. Fixing it afterwards means the stricter rule's debut is several
hundred positionless errors.

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
| [#31](https://github.com/schildawg/algol24/issues/31) | `priority/4` | **DECIDED** — top-level execution is source order |
| [#36](https://github.com/schildawg/algol24/issues/36) | `priority/4` | **DECIDED** — `Uncaught: <message>` in both processors |
| [#19](https://github.com/schildawg/algol24/issues/19) | `priority/5` | No `continue`, no statement labels, and no `goto` |
| [#29](https://github.com/schildawg/algol24/issues/29) | `priority/5` | Subscript refusal sentence differs between processors |
| [#38](https://github.com/schildawg/algol24/issues/38) | `priority/5` | **DECIDED** — `ParamStr(0)` names the program |

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

**#38 needs no implementation at all.** Both processors are already correct; the
ruling records what they do. It is a specification edit for Plumb.

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

| | Priority | Issue |
|---|---|---|
| [#30](https://github.com/schildawg/algol24/issues/30) | `priority/5` | Issue examples use `(* … *)` comments, which are not a comment form |

Cosmetic, cheap, and for Plumb. Worth doing early anyway: a Developer pasting a
reproduction out of an issue gets `Expect expression!` and will reasonably think
the feature is broken rather than the comment.

---

## Explicitly out of scope for 1.0

Not deferred backlog — never in it.

- **Primitives with methods** — `8.DownTo(1)`, `'123'.IntegerValue()`. A
  direction Schildawg likes and will discuss with Plumb. It weighed on the
  ruling in [#35](https://github.com/schildawg/algol24/issues/35), which is why
  `S.Length` was allowed rather than refused, but the feature itself is post-1.0.
- **A foreign function interface** — the intended path for native capabilities,
  so that a capability becomes a library rather than an edit to the compiler and
  two reseeds. Named in
  [Future directions](ALGOL-24.md#future-directions); does not block the
  release.

---

## Open questions

1. **#34 — for a `Set`, refuse or deduplicate?** Whether `S.Push(x)`,
   `S.Insert(0, x)` and `S.Set(i, x)` are refused outright or accepted and
   deduplicated. Both preserve uniqueness, so both satisfy the ruling. Blocks
   writing #33's reproductions.
2. **#38 — is `ParamStr(0)` guaranteed absolute?** Both processors answer an
   absolute path today; whether that is promised, and what `./algc` with no
   arguments or `--test` answers, is unprobed. Specify or name as unspecified.
