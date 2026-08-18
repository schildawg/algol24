# tests/defects

Reproductions of known defects, written as tests that **assert the intended
behavior** and therefore fail today. A file here is a specification of what
should happen, not a record of what does.

When a defect is fixed its file starts passing. That is the signal to move it
into a real suite — `tests/conformance/` if it belongs to the language's
observable surface, `tests/programs/` if the interpreted and compiled runs are
what matter — and delete it from here. This directory should shrink.

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

## The current contents: identifier case

Identifiers in Algol-24 are meant to be case-insensitive, in keeping with the
Pascal tradition the language follows elsewhere and with the case-insensitive
matching of keywords. They are not. Every file here is one surface on which
they are not.

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
the wording:
an unresolved *callee* is reported as `A call to 'ANSWER' is not supported by
the C back end yet`, which sends the reader looking for a missing feature
instead of a misspelled name.

## Migration risk

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
