# tests/defects

Reproductions of known defects, written as tests that **assert the intended
behavior** and therefore fail today. A file here is a specification of what
should happen, not a record of what does.

When a defect is fixed its file starts passing. That is the signal to move it
into a real suite — `tests/conformance/` if it belongs to the language's
observable surface, `tests/programs/` if the interpreted and compiled runs are
what matter — and delete it from here. This directory should shrink.

This README is also the project's **offline index of open defects**. Issues on
GitHub carry the discussion and the decisions; this file carries the summary, and
it is here rather than at the repository root because it sits beside programs
that fail if it drifts. A defect belongs here or in an issue — **not in
`ALGOL-24.md`**, which describes what the language *is*. The specification keeps
only genuine ambiguity: places where the language does not determine an answer
and a reader must not depend on one. Where a defect makes a stated rule
unreliable today, the specification carries a one-line pointer to the issue and
nothing more.

⚠️ **The index covers every open defect, including ones with no reproduction
here.** Reproducibility decides whether a defect gets a file in this directory;
it does not decide whether the defect is listed. A build script that reports
success on a failing suite is no less broken for being unwritable as a `test`
block, and someone reading this file offline needs to know about it. Language
defects and [tooling defects](#tooling-defects) are kept in separate tables
because only the first kind is measured by a reproduction — see
[Ownership](#ownership).

## Open defects

Defects in the **language**: a rule that `ALGOL-24.md` states and a processor
gets wrong. Each is reproduced by the files named, and those files are the
definition of done.

| # | Issue | Reproduced by |
|---|---|---|
| [1](https://github.com/schildawg/algol24/issues/1) | Identifiers are case-sensitive and are meant not to be | the twelve `Case…` files |
| [2](https://github.com/schildawg/algol24/issues/2) | Identifiers reject `!` and Unicode letters | the three `Chars…` files |
| [3](https://github.com/schildawg/algol24/issues/3) | Two enum members can emit one C symbol | `EnumMemberSymbol` |
| [4](https://github.com/schildawg/algol24/issues/4) | An unresolved name emits invalid C | *not reproducible here* |
| [5](https://github.com/schildawg/algol24/issues/5) | `Length` measures a collection's rendering | `LengthBuiltin` |
| [6](https://github.com/schildawg/algol24/issues/6) | A `String` is bytes, not code points | `StringCodePoints`, `StringCodePointsAstral`, `CharScalarRange` |
| [7](https://github.com/schildawg/algol24/issues/7) | No widening; `'A' = Str('A')` is `False`; text has no order | `TypeWidening`, `TypeEquality`, `TypeOrdering` |
| [8](https://github.com/schildawg/algol24/issues/8) | An integer literal too large for `Integer` is truncated | `LiteralRange` |
| [9](https://github.com/schildawg/algol24/issues/9) | `Byte`, `Short`, `Long`, `Single` and the numeric conversions do not exist | `NumericTypes` |
| [10](https://github.com/schildawg/algol24/issues/10) | No hex, octal, binary, exponent or `_` separators in literals | `NumberBases`, `NumberExponent`, `NumberSeparators` |
| [11](https://github.com/schildawg/algol24/issues/11) | A top-level function cannot be overloaded | `OverloadTopLevel` |
| [12](https://github.com/schildawg/algol24/issues/12) | Overload resolution is first-declared-wins | `OverloadSpecificity` |
| [13](https://github.com/schildawg/algol24/issues/13) | A no-match call runs anyway when compiled | `OverloadNoMatch` |
| [14](https://github.com/schildawg/algol24/issues/14) | Only `List` takes an element type, only on a variable | `ElementTypeCollections`, `ElementTypePositions` |
| [15](https://github.com/schildawg/algol24/issues/15) | No parameter defaults, and no named arguments | `ParamDefaults`, `ParamNamed`, `ParamNamedResolution` |
| [16](https://github.com/schildawg/algol24/issues/16) | No variadic parameters and no spread argument | `VariadicCollect`, `VariadicSpread`, `VariadicResolution` |
| [17](https://github.com/schildawg/algol24/issues/17) | A type name cannot be qualified by its unit | `QualifiedTypeName` |
| [18](https://github.com/schildawg/algol24/issues/18) | Two units cannot export the same name | `DuplicateExport` |
| [19](https://github.com/schildawg/algol24/issues/19) | No `continue`, labels, labelled `break` or `goto` | `ContinueStatement`, `LabelledBreak`, `GotoStatement` |
| [20](https://github.com/schildawg/algol24/issues/20) | The `constructor` keyword is decorative; `Init` decides | `ConstructorKeyword`, `ConstructorOverload`, `ConstructorNamed` |
| [21](https://github.com/schildawg/algol24/issues/21) | `X.Init(5)` yields the instance interpreted, `nil` compiled | `ConstructorReinvoke` |
| [22](https://github.com/schildawg/algol24/issues/22) | A wrong-arity call is unchecked when compiled and returns an answer | `ArityFunction`, `ArityBuiltin` |
| [27](https://github.com/schildawg/algol24/issues/27) | A wrong-arity call to a collection method segfaults compiled code | `ArityCollectionTooFew`, `ArityCollectionTooMany`, `ArityCollectionPartial` |
| [28](https://github.com/schildawg/algol24/issues/28) | Type inference is incomplete: 285 sites reach a declared type with no type | *not reproducible here* |
| [29](https://github.com/schildawg/algol24/issues/29) | Subscripting a non-subscriptable value raises a different sentence in each | *not written yet* |
| [33](https://github.com/schildawg/algol24/issues/33) | Compiled: a `Set` holds duplicates and an `Array` changes length | *not written yet* |
| [37](https://github.com/schildawg/algol24/issues/37) | `Type mismatch!` reports no position and names neither type | *not written yet* |
| [39](https://github.com/schildawg/algol24/issues/39) | Compiled code defers every `begin … end` block to the end of the program | *not written yet* |
| [40](https://github.com/schildawg/algol24/issues/40) | Compiled: an uncaught built-in error prints without the `Uncaught: ` prefix | *not written yet* |
| [41](https://github.com/schildawg/algol24/issues/41) | The interpreter refuses harmless collection synonyms and `S[0]` on a `Set` | *not written yet* |
| [42](https://github.com/schildawg/algol24/issues/42) | A `String` does not answer the non-mutating collection members | `StringCollectionMembers`, `StringImmutable` |
| [43](https://github.com/schildawg/algol24/issues/43) | Untyped and `Any` are two representations in `TypeChecker` and are one type | *not reproducible here* |
| [44](https://github.com/schildawg/algol24/issues/44) | Assignability is symmetric, and only a declaration is checked strictly | *not written yet* |
| [45](https://github.com/schildawg/algol24/issues/45) | `as` outlives the checker gap it exists to paper over | *not written yet* |

⚠️ **The eight rows marked *not written yet* are reproductions I owe.** Most were
filed on 2026-08-20, when the last of the open decisions were settled — each
ruling turned into a defect the moment the specification stated the rule. They
are listed because the index is the offline record of what is known to be
broken, and a defect with no reproduction is no less broken; but Prime Directive
condition 1 has nothing to measure for them until the files exist, so a fix for
one of these closes on the ordinary evidence rather than on a file flipping to
passing.

**Three rows read *not reproducible here*, and that phrase means two different
things.** Issue 4 *is* reproduced — in `refuse/`, for the reason given below.
Issues 28 and 43 will never have a file at all, and are marked so rather than
reading as arrears:

- **Issue 28 is a count** — the 285 sites where inference gives up — measured by
  re-running the instrumented checker the issue describes, not by a `test`
  block. Issue 45 is partly a count too, of the 63 `as` casts in `compiler/`
  that exist only because of issue 28.
- **Issue 43 is behaviour-preserving.** Merging two representations of "no type
  known" into one changes which programs are accepted not at all, so there is
  nothing for a reproduction to assert. `./test.sh` and the fixed point are its
  whole check.

Issues 44 and 45 want `refuse/` cases rather than `test` blocks, and both are
blocked behind issue 37 — that directory asserts the refusal **sentence**, and
37 is the issue that changes it.

Some rules cannot be reproduced as a `test` block at all: where the correct
outcome is that a program is **refused**, there is no observable behaviour to
assert, because a refusal is the absence of a run. Four issues hit that wall
today — 4, 14, 15 and 18 — which is what `refuse/` is for. See its README; it
runs as part of `run.sh`.

That directory is about to grow. Issues 32, 33, 37, 41 and 42 each turn on a
refusal — an `Any` reaching a declared type, an `Array` asked to change length,
a `String` asked to mutate — so those cases belong there rather than here.
`refuse/` asserts the refusal **sentence**, which is why issue 37 wants its
wording settled before any of them is written.

Issues 33 and 41 split across both directories, now that the `Set` question is
settled. Most of what they cover is an **acceptance** — `S.Push(V)` leaving a
present element where it is, `S.Insert(I, V)` moving it to `I`, `Stack.Add`,
`List.Pop`, `S[0]` — which is an ordinary `test` block here. Only
`S.Set(I, V)` onto a value already present at another index is a refusal, and it
needs a sentence that does not exist in either processor yet:
`Cannot hold two equal elements.`

Six of these fail in one half only, which is why `run.sh` builds as well as
interprets. `EnumMemberSymbol`, `OverloadNoMatch` and the three
`ArityCollection…` files pass interpreted and fail compiled; `LengthBuiltin` is
the mirror, passing compiled, because there the normative half is the one that
is wrong.

`StringCollectionMembers` fails both ways but at **different assertions**, which
is worth knowing before reading its output: interpreted it stops at the first,
because `Only instances have properties.` rejects the whole dotted form on a
`String`; compiled it stops at the third, because `Length` and `IsEmpty` already
answer. The compiled half is two members short of the rule, not five.

## Tooling defects

Defects in the **scripts and harnesses** rather than in the language. They are
listed here so the offline index is complete, and kept in their own table
because nothing in this directory reproduces them.

| # | Issue | Bites when |
|---|---|---|
| [23](https://github.com/schildawg/algol24/issues/23) | `compile.sh` silently discards every option but `--run` | you type `--test`, or mistype `--run` |

⚠️ **These are not measured by a reproduction, and so are not measured by Prime
Directive condition 1.** A language defect closes when its `.a24` files start
passing, which is a fact anyone can check by running `run.sh`. A tooling defect
closes when someone fixes the script and says so. That is a weaker standard, and
naming it is better than letting the two kinds sit in one table where the
difference would be invisible.

⚠️ **A tooling defect is not a conformance gap.** Nothing in this section means
a processor fails to implement `ALGOL-24.md`. Issue 23 in particular compromises
no gate: `test.sh` invokes `algc` directly and never goes through `compile.sh`,
so the reported state of the repository is accurate. It is a hazard for a person
at a terminal — which is exactly the reader this file is written for.

## Ownership

**These tests belong to the specification, and they are the definition of done.**
Prime Directive condition 1 — *every test associated with the issue passes* — is
measured here.

That is a claim about the **files**, not about every row of the index above.
[Tooling defects](#tooling-defects) have no reproduction and therefore no such
measure; they are listed so the offline index is complete, and they close by
someone fixing the script. Everything below concerns the `.a24` files.

The Developer and the Tester may add tests of their own, and should. **Neither
may remove a test from this directory.** A fix that cannot pass a reproduction
has not closed the issue, and deleting the reproduction does not change that; if
a test looks wrong, say so on the issue and it will be argued out there, where
the reasoning survives.

Two things that are *not* removal:

- **Graduating a reproduction.** When a defect is genuinely fixed its file starts
  passing, and the design is that it then moves into `tests/conformance/` or
  `tests/programs/` and leaves this directory. That is the intended lifecycle —
  see the note above about this directory shrinking. The prohibition is on
  deleting a test that still fails.
- **Correcting a test that tests the wrong thing.** A reproduction can be wrong;
  they are written by hand against a specification that is itself under
  construction. Raise it on the issue rather than editing it in place, because
  changing what a ticket must satisfy while someone is working on it moves the
  goalposts underneath them.

## Running them

```sh
./tests/defects/run.sh            # every file, with the reason each still fails
./algc --test tests/defects/CaseLocalVariable.a24   # one of them
./algc tests/defects/refuse/UnresolvedName.a24      # one refusal case
```

Two kinds of file are checked. A `.a24` in this directory is a `test` block
asserting the intended behaviour; a `.a24` in `refuse/` is a program that must
be **refused**, carrying the sentence it must be refused with in a
`/// REFUSE:` header.

`run.sh` exits **non-zero only when a reproduction passes**, which is the
inverse of a normal suite. Failure is the expected state here, so an exit code
that tracked it would be red on every run and would tell nobody anything; a
reproduction that starts passing is the event worth acting on.

For that reason this directory is **not** in `test.sh`'s `SUITES` array and must
not be added to it. `./test.sh` stays green while these fail.

## Issue 42 — a `String` is a collection of `Char`

Two files, and they are two different changes rather than one split in half.

| File | Asks that | Fails because |
|---|---|---|
| `StringCollectionMembers` | `Length`, `IsEmpty`, `Contains`, `IndexOf`, `Get`, `ToList` answer | a `String` never reaches the collection members |
| `StringImmutable` | `Add`, `Insert`, `Clear` refuse with `Strings are immutable.` | it is refused for the wrong reason, by both |

⚠️ **`StringImmutable` looks nearly fixed and is not.** Both processors already
*refuse* those calls, so an exit code tells you nothing — the assertion is the
**sentence**. Interpreted answers `Only instances have properties.`, which
rejects `S.Anything` identically and is therefore not about immutability at all.
Compiled answers `Only a List or a Set has 'Add'.`, which is a receiver
complaint: it would refuse a `String` even if strings were mutable. Neither is
the guard; both are the absence of one.

⚠️ **Its first assertion passes today, deliberately.** `S[0] := 'z'` already
raises `Strings are immutable.` under both, so it pins the wording the method
forms must match. A fix that invented a second sentence would leave the language
saying two things about one rule.

⚠️ **The two files must not be merged**, because a fix that routed `String`
through the collection path *without* adding the immutability guard would make
the first pass and leave a `String` mutable — worse than the defect, and
indistinguishable inside one file.

⚠️ **ASCII only, and that is load-bearing.** If a `String` is a collection of
`Char` then `S.Length` counts code points, and today it counts bytes —
[issue 6](https://github.com/schildawg/algol24/issues/6). These files test
whether the members are *reachable*; the unit is 6's. The two must land
together, because `S.Length`, `Length (S)` and `for C in S` have to agree on it.

## Issue 27 — wrong-arity collection calls

Three files, one fault, three failure modes — and they are separate because a
partial fix closes some and not others.

| File | The call | Compiled, at `43207e9` |
|---|---|---|
| `ArityCollectionTooFew` | `L.Get ()` | **SIGSEGV**, exit 139, no output |
| `ArityCollectionTooMany` | `L.Get (0, 99)` | exit 0 — the surplus is discarded and the call answers |
| `ArityCollectionPartial` | `M.Put (1)` | exit 0 — and the collection is silently corrupted |

`collection_method` (`bootstrap/algol.c:2345`) opens with `(void)count;` and
then indexes `args[0]`, or `args[0]` and `args[1]`, in every branch. So a
zero-argument call dereferences a null pointer, a one-argument call to a
two-argument method reads past the end of a valid array, and a surplus argument
is never looked at.

⚠️ **`ArityCollectionPartial` is the one to read first**, although the crash is
the one the issue is named for. It neither crashes nor refuses: the
out-of-bounds read is *written into the collection*, so `M.Put (1)` leaves a map
holding a key whose value is whatever was in memory, and `L.Insert (0)` leaves a
list one element longer than it was. Both render as though empty. An
indeterminate value that prints as nothing is indistinguishable from an empty
string until something compares it — which makes this quieter than the segfault
and therefore worse.

⚠️ **The crash needs its own file** because it takes the process down: any test
block after it never reports, and the harness would show one silent failure
where there are several.

⚠️ **A receiver guard is not what is missing**, though the issue suggests it.
The collection operations themselves already check — `alg_get` and its
neighbours call `as_sequence(...)`, which is why `var N := 5; N.Get (0)` answers
`Only a collection has 'Get'.` compiled rather than misbehaving. The arity is
the whole of the fault. Note that the guard cannot help here in any case:
`args[0]` is evaluated before `alg_get` is entered.

## Issue 2 — identifier characters

`ALGOL-24.md` admits Unicode letters, decimal digits, `_`, `?` and `!` in an
identifier. The scanner's alphabet is `A`–`Z`, `a`–`z`, `_`, `?` and the ASCII
digits, so two of those are unimplemented and every other byte is refused during
scanning.

| File | Asks for | Fails with |
|---|---|---|
| `CharsBang` | `Commit!` | `Unexpected character: !` |
| `CharsUnicodeLatin` | `Café`, `Größe` | `Unexpected character:` + a raw byte |
| `CharsUnicodeNonLatin` | `Δelta`, `半径` | `Unexpected character:` + a raw byte |

All three are refused before any statement runs, so no test is reported — the
same shape as `CaseEnumMember` and `CaseTypeName` below.

The two Unicode files are separate because they can be fixed apart. Latin-1
letters are two UTF-8 bytes each; the second file mixes two- and three-byte
characters, and Greek carries a case pairing (Δ/δ) where Han carries none. A fix
that widens the alphabet bytewise passes the first and fails the second.

`CharsBang` also asserts `Ready?`, which works today, so a change that reaches
`!` and breaks `?` fails visibly instead of silently.

Note that the scanner has no notion of a code point: it refuses a non-ASCII
character **as a byte**, one error per byte it occupies. That is why `run.sh`
runs its output filters under `LC_ALL=C` — the reproduction's own error message
is not valid UTF-8.

## Issue 1 — identifier case

Identifiers are meant to be case-insensitive, in keeping with the Pascal
tradition the language follows elsewhere and with the case-insensitive matching
of keywords. They are not. Every file below is one surface on which they are
not.

Three surfaces already fold case and are not represented here, since a test of
them would pass: keywords, in the scanner; the type-name operand of `is`, in
both processors; and built-in member names in the C runtime — though not in the
interpreter, which is `CaseCollectionMember` below.

| File | Surface | Interpreted (normative) | Compiled |
|---|---|---|---|
| `CaseLocalVariable` | local variable | `Undefined variable 'count'.` | `cc`: undeclared `v_count` |
| `CaseParameter` | parameter | `Undefined variable 'value'.` | `cc`: undeclared `v_value` |
| `CaseFunctionName` | function name | `Undefined variable 'ANSWER'.` | emit refused |
| `CaseClassName` | class name | `Undefined variable 'thing'.` | emit refused |
| `CaseFieldName` | field | `Undefined property 'name'.` | same, at run time |
| `CaseMethodName` | method | `Undefined property 'SPEAK'.` | same, at run time |
| `CaseEnumMember` | enum member | `Type mismatch!`, file abandoned | emit refused |
| `CaseTypeName` | type name in an annotation | `Type mismatch!`, file abandoned | emit refused |
| `CaseUnitQualifier` | unit name as a qualifier | `Undefined variable 'CASEUNIT'.` | `cc`: undeclared `v_CASEUNIT` |
| `CaseAssignment` | assignment target | `Undefined variable 'total'.` | `cc`: undeclared `v_total` |
| `CaseSecondDeclaration` | two spellings, two variables | assertion fails, got `1` | assertion fails |
| `CaseCollectionMember` | built-in collection member | `Undefined property 'contains'.` | **passes** |

`lib/CaseUnit.a24`, `lib/Shapes.a24`, `lib/Round.a24` and `lib/Flat.a24` are
fixtures — for `CaseUnitQualifier`, `QualifiedTypeName` and `DuplicateExport` —
and carry no tests of their own.

Four things in that table are worth more than the row they occupy.

**Only one row is a processor disagreement.** `CaseCollectionMember` fails
interpreted and passes compiled, because the runtime already compares built-in
member names case-insensitively while the interpreter's tables compare exactly.
Every other row fails both ways, which is why no differential test in this
repository has ever caught any of them. The interpreter is normative, so its
answer is the language's answer today — but on this row the runtime is the half
that is already right, and the interpreter's tables are what will have to move.

**Two rows never run a test at all.** `CaseEnumMember` and `CaseTypeName` fail
during type checking, which abandons the whole file, so nothing after them in
the same file would be reported. That is why each has a file to itself, and it
is a good reason to keep one case per file here generally.

**`CaseSecondDeclaration` is the quiet one.** Every other row fails loudly with
an unresolved name. That one compiles clean, binds twice, and leaves a program
that meant one variable holding two, with no diagnostic anywhere. It is the only
row that can corrupt a working program rather than refusing to run it. Its file
records the one assumption it makes about the fix — that a second spelling
rebinds rather than becoming a duplicate-declaration error — and what to do if
that assumption turns out wrong.

**The compiled column contains two defects that are not about case.** A
case-mismatched name is simply one more way to produce a name the resolver
cannot find, and an unresolved name reaches `cc` as invalid C rather than being
diagnosed — that is a separate defect, recorded in `ALGOL-24.md` under
*Unresolved names in compiled code*, and these files inherit it. The second is
the wording: an unresolved *callee* is reported as `A call to 'ANSWER' is not
supported by the C back end yet`, which sends the reader looking for a missing
feature instead of a misspelled name.

### Migration risk for the case fold

None that can be found in this repository. Tokenizing every `.a24` under
`compiler/`, `tests/` and `bench/` — comments and string literals stripped — and
grouping identifiers by their lower-cased form turns up exactly one file that
spells one name two ways: `compiler/Parser.a24` has `EOF` alongside `Eof`, and
`Text` alongside `text`. In both pairs one member is a bare identifier and the
other appears only after a dot (`F.Eof`, `Result.Text`), so they occupy
different name spaces and neither pair is a collision.

So the fix should require no change to any existing source. It will require a
reseed if the fold lands anywhere upstream of `Mangle`, since that changes every
emitted C symbol.

## Issue 3 — enum member symbols

An enum member's C symbol is the type name, `_` and the member name. `_` is a
legal identifier character, so that join cannot be injective: with
`Fruit_Kind = (Ripe, …)` and `Fruit = (Kind_Ripe, …)` both spelling
`e_Fruit_Kind_Ripe`, two `static Value` at file scope merge as tentative
definitions and the second initializer overwrites the first.

Unlike everything else here this is not a missing feature but a **silent wrong
answer** — nothing refuses it, `cc` builds it, and the unqualified `Ripe`
evaluates to `Fruit.Kind_Ripe`. Qualified access hides it, because
`Fruit_Kind.Ripe` resolves by name at run time and never reads the merged
variable. That is why no existing gate catches it: a corpus that qualifies its
enum members is immune.

The same argument reaches the `__` separating a renamed symbol from its unit,
where the identifier `a__b` collides with `a` renamed against unit `b`. The
fixed-length prefixes (`v_`, `f_`, `k_`, `m_`, `e_`, `i_`) are unaffected.

## Issue 5 — the Length built-in

`Length([1, 2])` is `6` interpreted and `2` compiled: the interpreter's built-in
renders its argument and measures the rendering, since `Str([1, 2])` is six
characters. The property form is `2` under both and is what a program should use
until this is fixed.

The rare case where the **normative half is the wrong one**. Everywhere else the
interpreter defines the language and a compiled disagreement is the compiler's
fault; here the interpreter's built-in is what has to change. `LengthBuiltin`
therefore passes compiled and fails interpreted.

`Length (S)` on a string is a different path, is correct under both, and is
asserted in the same file so a fix cannot quietly break it.

## Issue 6 — strings are bytes

`ALGOL-24.md` specifies a `String` as a sequence of `Char` counted and indexed in
**code points**. Both processors store UTF-8 bytes and count those, so
`Length('héllo')` is `6` and `'héllo'[1]` is the leading byte of `é` rather than
`é`.

Output is already byte-transparent — `WriteLn('😀')` prints correctly under both
— so nothing is corrupted. The unit is simply wrong, and a program restricted to
characters 0 through 127 cannot tell, which is why the compiler compiles itself
under the current behaviour.

`CharScalarRange` isolates the part that is broken regardless of which model
wins: `Char(200)` and `#200` are refused with `Char is limited to 0..127.`,
while indexing a string **manufactures** a `Char` whose `Ord` is 195. The type
produces values its own constructors reject.

`StringCodePointsAstral` is separate from `StringCodePoints` because an emoji is
four bytes in UTF-8 but **two units in UTF-16**. An implementation that counts
UTF-16 units passes the two-byte file and fails this one, reporting a length of
2 where the answer is 1.

The issue carries the storage question, which is not deferrable: `Scanner.a24`
reads its source as `Source[Current]`, so code-point indexing over UTF-8 storage
would make the scanner O(n²) over its own input.

## Issue 7 — how the types interact

`ALGOL-24.md` takes Turbo Pascal's assignment compatibility as its base: a
conversion that loses nothing and cannot fail happens without being asked, and
never runs backwards. `Char` widens to `String`, `Integer` to `Double`. Equality
widens to a common type and compares there; where there is no common type the
values are simply unequal, which is what lets a collection hold mixed types.
Ordering covers text as well as numbers, by code point.

None of it is implemented. `'A' = Str('A')` is `False` under both processors,
`var D : Double := 1` is rejected, and `Str('abc') < Str('abd')` raises
`Operands must be numbers.`

**`TypeEquality` is the one to fix first.** Answering `False` for two identical
pieces of text is worse than either alternative — a language may convert them or
refuse the comparison, but a silent `False` gives the program no way to notice.
And equality is what `Contains`, `Map` keys and `case` labels are built on, so a
`Map` keyed with `'A'` cannot be found with `Str('A')`; the program meets this
as a lookup that mysteriously misses rather than as a type error.

⚠️ The conversion is already implemented somewhere. A `Char` argument is
accepted for a `String` parameter today — `Take('A')` works where
`var S : String := 'A'` does not — so this is the declaration-versus-assignment
asymmetry appearing on a third path, not a missing conversion.

## Issues 8 and 9 — the numeric types

`ALGOL-24.md` specifies ten predeclared types; six exist. `Byte`, `Short`, `Long`
and `Single` are new, as are the conversion functions `Byte(N)` … `Double(N)`
and `Round(X)`.

The design is three rules. One **ladder** —
`Byte → Short → Integer → Long → Single → Double` — along which values widen
implicitly and never leftwards, with a binary operator promoting both operands
to the further position. `Byte` and `Short` are **storage types**, so arithmetic
on them yields an `Integer` and neither ever appears as an operator's result;
that is what keeps the operator rules to a ladder instead of a table of every
pair. And narrowing is **explicit**, spelled as the type name applied to a value
— the convention `Char(N)` already follows — raising when the value does not
fit rather than truncating.

There is no `Real`, deliberately. Turbo Pascal's `Real` is a 48-bit software
format from the days when the 8087 was optional, and Delphi redefined it as an
alias for `Double`, so a `Real`/`Double` pair means 48/64 in one Pascal and
64/64 in the other. `Single` and `Double` are also Turbo Pascal names and are
unambiguous.

⚠️ `LiteralRange` is a defect **today**, with no new types involved:
`10000000000` reads as `1410065408` under both processors, silently. That is not
the specified `Integer` wrap — arithmetic wrapping operates on values the author
wrote, whereas here the literal itself is altered before the program starts. A
constant is the one place a processor always has enough information to refuse.

## Issue 10 — number literals

`ALGOL-24.md` admits `0xFFFF`, `0o1234`, `0b1111`, `1.1e-9` and `1_000_000`.
None of them scan; each is read as a number followed by an identifier.

⚠️ **This is a scanner change and reaches the emitter not at all**, which was
checked rather than assumed. `VisitLiteral` emits `alg_int(Str(Value))` — the
value re-rendered, never the lexeme — so `0b1111` arrives in C as
`alg_int(15)`. That matters, because C11 has no `0b`, no `0o` and no digit
separators: had the lexeme leaked, three of the five forms would have broken the
build rather than merely misbehaved. The exponent case is already proven, since
`Str` renders a `Double` in E notation and the literal `1000000000.0` reaches C
as `alg_double(1.0E9)` on every build today.

⚠️ **The separator is the one with real ambiguity.** `_` already begins an
identifier, so `1_000` has two valid readings and the number scanner has to win.
The other four forms are unambiguous, since no identifier may begin with a
digit.

Two rules worth knowing because they are choices rather than conventions. A
leading zero does **not** make a literal octal — `0123` is one hundred and
twenty-three. And every base denotes a **value**, not a bit pattern, so
`0xFFFFFFFF` is 4294967295 and by the literal rule a `Long`; it is not `-1`,
which is where the language parts company with Java.

Do [#8](https://github.com/schildawg/algol24/issues/8) first. A hex literal
overruns `Integer` in eight characters, so adding bases before the range rule is
fixed multiplies the ways to hit a silent truncation.

## Issues 11, 12 and 13 — overloading

Methods overload today, in both processors, and the emitter already mangles a
signature into the symbol — `m_P_Show_1_Integer` beside `m_P_Show_1_String`.
Top-level functions are refused with `'Show' is already defined.` whatever their
signatures, so **the same two declarations are legal inside a class and illegal
outside one**. That is a place the language stopped rather than a decision it
made, and #11 removes it.

The rule `ALGOL-24.md` now states is exact match, then widening, then `Any`,
with genuine ties an error and **declaration order deciding nothing**.

⚠️ **Fix 12 and 13 before 11.** Both are defects in the *existing* method
overloading and #11 would inherit them. Resolution is first-declared-wins today,
so writing `Take(Any)` above `Take(Integer)` makes `Take(1)` select the `Any`
one — and a static resolver naturally picks the most specific candidate, so
leaving the run time order-dependent guarantees the two paths disagree the
moment direct calls are emitted. And a call matching no signature runs anyway
when compiled, which is exactly what an unresolved overload degrades into.

⚠️ The compile-time path is an **optimization and must be invisible**: the
candidate chosen statically has to be the one the run-time rule would choose.
That constrains the runtime as much as the compiler — every type that can appear
in a signature needs a distinct tag, or `F(Byte)` and `F(Integer)` resolve one
way statically and the other way dynamically. Recorded against #9.

## Issue 14 — element types

Every collection takes an element type, writable wherever a type may be written
— declaration, parameter, result. One argument for `List`, `Array`, `Set` and
`Stack`; two for `Map`, parenthesised.

⚠️ **Map's arguments are parenthesised because of the comma.** A parameter list
already separates parameters with one, so `(M : Map of String, Integer)` needs a
reader to count, and `(M : Map of String, N : Integer)` — meaning a Map plus an
`N` — gets a baffling error as the parser takes `N` for the value type. The
single-argument form may be parenthesised too, so one rule covers everything:
after `of`, a type or a parenthesised list of them.

`(` rather than `[` because `[` means a *value* here — a list literal or a
subscript — and `Map of [String, Integer]` reads like a list holding two
variables called `String` and `Integer`. The language already writes a
parenthesised comma list in a type declaration: `type Pair = (Alpha, Beta);`

⚠️ **The check is static only, and that has a consequence worth stating.** A
collection carries no element type at run time, so a value of unknown static
type reaches a `List of Integer` unchallenged and is never checked again. Which
is why an element type is **not part of a signature** for overloading:
`F(List of Integer)` and `F(List of String)` are one signature. Were they
distinct, a dynamically resolved call could not choose between them, and the
rule that compile-time resolution must agree with run-time resolution would
become unkeepable.

## Issue 15 — defaults and named arguments

A parameter may declare a default with `:=`, and an argument may name its
parameter with `=>`.

⚠️ **Neither spelling was free to choose.** `=` cannot mark a named argument
because `H (Index = 1)` **already parses today** — as a call passing the
comparison `Index = 1`, failing only because `Index` is not in scope at the call
site. Using `=` would silently change what an existing program means. And `:=`
rather than `=` for a default because `=` is equality here: Delphi spells a
default with `=`, but Delphi also spells a constant that way, whereas this
language writes `const D := '…'` and `var X : Integer := 1`.

⚠️ **Read which call earns the feature.** With `Adjust(Index : Integer)` and
`Adjust(Percentage : Single)` declared, `Adjust(1)` and `Adjust(Index => 1)`
agree already — an exact `Integer` beats a widening to `Single` under the
existing rule, so naming the parameter documents the choice without changing it.
It is `Adjust(Percentage => 1)` that positional calling **cannot express at
all**.

⚠️ **Parameter names are not part of a signature.** Two functions differing only
in parameter names are a duplicate declaration. Were they distinct, every
positional call would be ambiguous between them, and a feature meant to remove
doubt would create it.

⚠️ **The run time must carry parameter names.** A call on a receiver whose class
is not known statically is resolved when it is made, so `alg_class_method` needs
names alongside the arity and type signature it registers today — otherwise a
named call resolves one way through the compiler and another through the
dispatcher, which is exactly what #11's rule forbids.

Do this after #11, #12 and #13. It extends overload resolution, and extending it
while resolution is still first-declared-wins and a no-match still runs when
compiled would build on two known-broken foundations.

## Issue 16 — variadics and spread

A parameter's type may be followed by `...`, collecting the remaining positional
arguments into a `List of T`; an argument may be followed by `...`, spreading a
collection into separate arguments.

⚠️ **The spelling is free here in a way it is not everywhere.** A type is always
a bare identifier — `var C : Shapes.Circle` is rejected while `var C : Circle`
is accepted — so a dot never follows a type name anywhere in the grammar. Nor
does `..` or `...` scan today, Pascal's range operator having never been
adopted.

⚠️ **Spreading is explicit, and that is the design rather than a simplification.**
Java spreads an array implicitly, so the meaning of `f(x)` depends on `x`'s
static type — a known trap there and a worse one here, where a gradually typed
argument often has no static type to depend on. With a marker, `Parts` is one
argument that happens to be a list and `Parts...` is its elements, and neither
reading requires knowing anything about types. Forwarding is what earns it:
without a spread a variadic function cannot pass its own arguments to another
one.

⚠️ **Variadic is a fourth rung, not a second phase.** Below exact, widening and
`Any`, so a fixed-arity candidate always beats a variadic one and
`F(S : String)` alongside `F(S : String...)` is unambiguous on `F('x')`. Other
languages describe this as a resolution phase tried after the first fails;
written as a rung it needs no phases and the ladder stays single.

⚠️ **The third field the dispatcher has been asked for.** The run time must know
a method is variadic, after parameter types (#9) and parameter names (#15).
Every call-site feature has to be visible to the dispatcher or the two halves
resolve differently — a standing cost of #11's rule, and cheaper to design for
than to retrofit.

## Issue 17 — qualified type names

A unit-qualified name works wherever a **value** is expected and nowhere a
**type** is expected. `Shapes.Circle()` constructs today; `var C : Shapes.Circle`
and `C is Shapes.Circle` are both refused, because `TypeName = identifier` and a
qualified one is simply not in the grammar.

⚠️ **The gap is larger than the inconsistency.** Two units exporting one name is
refused outright, and the interpreter's advice — "mark it private in one of the
modules" — tells you to avoid the collision rather than resolve it. A qualified
type name is the mechanism that would resolve it, so this is the smaller half of
a bigger question the spec deliberately leaves open: whether two units may export
one name at all, which needs the emitter to disambiguate two `k_Circle` symbols
across translation units.

⚠️ This corrects #16. That issue justified the `...` spelling on types being bare
identifiers. They should not be — but the spelling survives anyway, because one
token of lookahead separates the two uses of `.`: a dot continuing a qualified
name is followed by an identifier, and a dot beginning `...` is not. So
`Shapes.Circle...` parses. The reasoning changed; the syntax did not.

## Issue 18 — two units exporting one name

Two units may export the same name, with qualification distinguishing them at
each use. Refused outright today.

⚠️ **The interpreter's advice is the tell.** *"Mark it private in one of the
modules"* asks a programmer to **avoid** the collision rather than resolve it,
which is only ever the advice of a language with no way to say which name is
meant. A module system whose names must be globally unique has not separated
anything. This and #17 are one feature in two halves.

⚠️ **#17 first, and this reproduction proves it.** `DuplicateExport` currently
fails with `Expect ';' after variable declaration.` — its qualified *type
annotations* are refused before the duplicate export is reached. Strip them and
the real message appears. So the file cannot reach the defect it exists for
until qualified type names land.

⚠️ **And it widens #3.** `CEmitter` already renames a colliding symbol as
`Name__Unit`, used today only for root and `private` collisions. Extending that
to every duplicated export puts far more names through a separator that is **not
injective** — `_` is a legal identifier character, so `a__b` collides with `a`
renamed against unit `b`. Choose the separator before this lands; the mangling
scheme in #3 frees the whole upper-case range, so a capital costs nothing.

## Issue 19 — continue, labels and goto

A label names a **statement**, in one namespace: `break L` leaves it,
`continue L` begins its next iteration, `goto L` re-enters it from the
beginning. No `label` declaration section is needed, because `Ident :` cannot be
confused with the start of an assignment — `:=` is a single token.

⚠️ **`continue` is wanted by this compiler already.** Its own source works around
the absence in three places, each saying so in a comment: an `if` around a loop
body in `Interpreter.a24`, a nested `while` in `Parser.a24`, a guarded branch in
`CEmitter.a24` where *"an `Exit` here would abandon the whole of CollectUnits"*.

⚠️ **`goto L` and `continue L` on one loop label differ**, and `GotoStatement`
pins it: `continue` runs the next iteration, `goto` restarts the statement,
initializer and all. Both well defined, and someone will expect them to be the
same.

⚠️ **A goto may name a label in its own block or an enclosing one, never inward,
and the reason is the exception frame stack rather than taste.** Every jump pops
the frames between here and there; the emitter already keeps a `LoopTryDepth` so
a `break` can do it, added after a `break` out of a `try` left the runtime's
frame stack pointing at a returned C frame — *"It did not survive algc compiling
itself, which is where it was found."* A jump outward has a depth to restore
because those frames exist. A jump inward does not, because the frames that
block would have opened were never opened.

⚠️ **Backward `goto` is the one shape change**, and not where it looks. Forward
jumps unwind like `break`. Backward ones cannot: an exception travels only
outward, so a tree-walker needs block execution to become **resumable** — unwind
to the block holding the label, then re-enter its statement list at that index.
The C side is easy by comparison, since C has `goto` and the same-function rule
keeps every jump inside one C function.

## Issue 20 — constructors

A member declared `constructor` is a constructor; the name does not matter.
Exactly inverted today — `function Init` **is** a constructor and
`constructor Make` is not.

⚠️ **The intent was already written down and never wired up.** `Parser.a24:1432`,
beside the code that consumes the keyword and discards it: *"A constructor is
spelled `constructor`, not named `init`."* Every constructor semantic keys on the
lexeme instead — `FindOverload('Init', …)` in `ObjClass`, `Name.Lexeme = 'Init'`
in `Resolver` and again in `Interpreter`. Turbo Pascal is the model and is the
same way round: the keyword makes a constructor there, which is why
`New(P, Init)` names it at the call.

⚠️ **Overloading is a divergence, not a missing feature.** `ObjClass.Call` is
written to do it — *"A constructor overloads like any other method"* sits above
`FindOverload('Init', Arguments)` — but a single-valued `Arity()` gate fires
first and refuses the call. The machinery is three lines below the gate that
stops it. Compiled has no gate, so `Point(1, 2)` works there and raises here.

⚠️ **Migration costs nothing**, which is worth knowing before the change looks
frightening: all 63 constructors in the corpus are already spelled
`constructor Init`, no method is named `Init` without the keyword, and no
`constructor` carries another name.

## Issue 21 — re-invoking a constructor

`X.Init(5)` re-runs the constructor over an existing instance under both
processors, and they disagree about the result: the instance interpreted, `nil`
compiled.

⚠️ **The specification chooses `nil`, overruling the normative half**, and says
so rather than quietly following the interpreter. A constructor may not return a
value — `Exit this` inside one is refused — so a construct that returns one when
reached a different way is two rules where there should be one. The
interpreter's answer is inherited from Lox, where an initializer returns `this`
so `new Foo()` has something to evaluate to; here construction is its own path
and `W(1)` already yields the instance.

Three neighbouring behaviours turned out to be **correct** and have been pinned
in `tests/conformance/Objects.a24` rather than left here: the superclass
constructor is not called automatically, a call on `this` reaches the
most-derived override, and that override sees *initialised* fields. The last is
where the language beats both its neighbours — C++ dispatches to the base, Java
dispatches to the derived override but shows it uninitialised fields, and
neither trap exists here because initialisers are not staged per class.

⚠️ Writing those tests produced a live instance of #7: `AssertEqual('S', Trace)`
fails with *"Expected Char 'S' but got String 'S'"*, because a one-character
literal is a `Char` and a `Char` does not compare equal to a `String`. The
conformance file now uses `Str('S')` and carries a note saying why.

## Issue 22 — wrong-arity calls

`ALGOL-24.md` says a call with too few or too many arguments raises
`Expected N arguments but got M.`, and lists that message under **run-time
errors** — so it is catchable as a `String`. Three faults sit under that one
rule, and the four call kinds behave three different ways.

| Call kind | Interpreted | Compiled |
|---|---|---|
| top-level function, too few | raises, exit 70 | **prints the answer, exit 0** |
| top-level function, too many | raises, exit 70 | **prints the answer, exit 0** |
| method | `No matching signature for function.` | `Wrong number of arguments.` |
| built-in | raises, exit 70 | **whole program refused at emit time** |

⚠️ **The first is a wrong answer, not a late refusal.** Emitted code calls with
whatever was written and missing parameters arrive as `nil`, so a body that does
not touch them returns normally — `Three(1)` on a three-parameter function
prints its result and exits 0. This is the shape the differential suites exist
to catch and structurally cannot: nothing in `tests/programs/` calls anything
with the wrong arity, so the two halves never disagreed where anyone was looking.

⚠️ **A body that uses its parameters hides it.** Summing them fails compiled with
`Operands must be two numbers, or two strings.`, which looks like the arity being
caught and is `nil` reaching `+`. `ArityFunction`'s function returns a constant
for exactly this reason, and says so.

⚠️ **The built-in diagnostic is false.** `Copy('hello')` is refused with *"A call
to `Copy` is not supported by the C back end yet"* — but `Copy` is supported.
`CEmitter.Builtin` keys its table on name *and* arity (`'Copy/3'`), so a wrong
count misses the entry and falls through to the `Unsupported(...)` path meant for
constructs the back end has not implemented. A fix wants to keep that path for
genuinely unsupported constructs and report arity as arity.

The two reproductions are **kept in separate files deliberately**: the built-in
fault aborts the whole translation unit, so sharing a file would stop
`ArityFunction`'s tests from ever being emitted and the harness would report one
failure where there are two.

⚠️ Arity is knowable in the shared front end, so the check *could* be static —
but the specification currently says it is not, and the reproductions assert the
specification. That reading is worth revisiting rather than assuming: parameter
defaults make the legal count a range (#15), variadics make it open-ended (#16),
and a spread whose collection length is unknown before the program runs makes
arity genuinely dynamic. The last means it cannot become purely static, which
argues for fixing the compiled side to check at run time rather than moving the
check forward. The issue carries that as an open question.

## Issue 23 — compile.sh drops its options

**A tooling defect, not a conformance gap** — the first entry of that kind in
this index, and the reason the index now has two tables.

`compile.sh` takes `$1` as the program and compares `$2` against exactly one
literal:

```sh
program=$1; shift
run=false
if [ "${1-}" = "--run" ]; then run=true; shift; fi
```

There is no `else`, so every other option in that position is silently dropped.

The sharpest form is a file whose only test **fails**. `algc --test` reports
`1 of 1 tests failed.` and exits 70; `./compile.sh Failing.a24 --test` prints
`Built build/Failing` and exits 0, and the binary it built then runs, prints
nothing and exits 0 as well. The flag was discarded, so the *program* was
emitted — and a file of nothing but test blocks has an empty main block.

**A failing suite reports success twice.** A run that tested nothing is
indistinguishable from a run that passed, which is worse than an error and worse
than the flag not existing at all.

⚠️ `--rnu` is the variant worth fixing first. A mistyped `--run` means the
program is built and never executed, and the script's last line is `Built …`
either way — nothing separates "you asked me to run it and I did not" from "you
did not ask me to". `--test` at least leaves a binary that can be run by hand.

`./compile.sh --test P.a24` — flag before the program — *is* caught, but by
accident: `--test` becomes the program name and the file-existence check reports
`No such program: --test`. That is not argument validation, and it stops working
the moment someone creates a file with an option-shaped name.

⚠️ Any fix has to keep `--run a b` passing `a b` to the *program*, so
`./compile.sh P.a24 --run --test` must give `--test` to the program and not to
`algc`. `sdl.sh` parses options before the source file for that reason and can
be read as a worked example.
