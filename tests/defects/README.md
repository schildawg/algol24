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

## Open defects

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

Issue 4 has no file because every reproduction here must be a `test` block that
*passes* once fixed, and the correct outcome there is that the program is
**refused** — which no passing test can express. Fixtures of that shape would
need a different harness.

Two of these fail in the compiled half only, which is why `run.sh` builds as well
as interprets: `EnumMemberSymbol` passes interpreted and computes the wrong
answer compiled, and `LengthBuiltin` is the mirror — it passes compiled, because
here the normative half is the one that is wrong.

## Running them

```sh
./tests/defects/run.sh            # every file, with the reason each still fails
./algc --test tests/defects/CaseLocalVariable.a24   # one of them
```

`run.sh` exits **non-zero only when a reproduction passes**, which is the
inverse of a normal suite. Failure is the expected state here, so an exit code
that tracked it would be red on every run and would tell nobody anything; a
reproduction that starts passing is the event worth acting on.

For that reason this directory is **not** in `test.sh`'s `SUITES` array and must
not be added to it. `./test.sh` stays green while these fail.

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

`lib/CaseUnit.a24` is a fixture for `CaseUnitQualifier` and carries no tests of
its own.

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
