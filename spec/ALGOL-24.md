# The Algol-24 Programming Language Specification

> **Status: in progress.** Chapters are written and verified one at a time; a
> chapter absent from this document is unspecified, not unconstrained. See
> `spec/PLAN.md` for what is planned and in what order.

---

## 1. Introduction

Algol-24 is a Pascal-flavoured, gradually typed language. This document
specifies its lexis, syntax, and semantics.

### 1.1 Authority

⚠️ **The tree-walking interpreter in `compiler/*.a24` is the sole authority.**
Where it and the C runtime in `bootstrap/algol.c` disagree, the interpreter
defines the language and the compiler is in error. There is no other
implementation and no external oracle.

⚠️ **This specification is normative even where the behaviour is plainly
wrong.** If the interpreter treats the Integer `0` as falsey and `0.0` as
truthy, this document says so, flatly. Doubts are recorded in Annex D, which is
not normative, so that the normative text never argues with itself. A
specification that hedges cannot be conformed to.

Every normative statement here was verified by *running* the interpreter, not
by reading it.

### 1.2 Conformance

An implementation conforms if, for every program, it produces the output and
the exit status this document requires. Diagnostics are part of that surface:
their wording is specified, because it is what a user sees and what one
implementation can be compared against another by.

Where a rule is marked **compile-only** or **interpret-only**, it constrains
that processor alone.

### 1.3 How to read a rule

Every normative statement carries an immutable identifier and its evidence:

**[SRC-000]**  An example rule, stating one thing that a single test can prove
or disprove.

    interpreter  compiler/Scanner.a24  ScanToken
    compiler     bootstrap/algol.c     alg_error
    tests        Scan A Whole Program

⚠️ **Identifiers are permanent.** They are assigned once, never reused and
never renumbered; sections may be renamed and reordered freely. Numbering the
sections instead would mean that inserting one clause silently rots every
citation to everything after it.

The trailer is machine-readable, and `spec/spec.sh` checks it: that each cited
file exists, that each cited symbol is found in it, and that each cited test
name is a test the suite actually runs. A rule citing no test is a claim nobody
has proven, and the checker reports it.

Non-normative material — annexes, notes, and anything under a heading marked
*(non-normative)* — carries no identifiers and constrains nothing.

---

## 2. Notation

The syntax is given in Extended Backus-Naur Form, following the Go
specification's conventions:

```
Production  = production_name "=" [ Expression ] "." .
Expression  = Term { "|" Term } .
Term        = Factor { Factor } .
Factor      = production_name | token [ "…" token ] | Group | Option | Repetition .
Group       = "(" Expression ")" .
Option      = "[" Expression "]" .
Repetition  = "{" Expression "}" .
```

Lowercase production names denote lexical tokens; uppercase names denote
non-terminals. Tokens are enclosed in double quotes.

The form `a … b` means the set of characters from `a` through `b` inclusive.
The symbol `∅` marks an empty alternative.

⚠️ A quoted token in this document is matched **case-insensitively if it is a
keyword** and exactly otherwise. See [SRC-010].

---

## 3. Source code representation

### 3.1 Characters

**[SRC-001]**  Source text is a sequence of bytes. The language attaches no
encoding to it; a byte is the unit of both storage and measurement.

    interpreter  compiler/Scanner.a24  ScanTokens
    compiler     bootstrap/algol.c     alg_length
    tests        Scan A Whole Program

**[SRC-002]**  Outside comments, string literals and character literals, every
byte must be one the scanner recognises. Any other byte is an error reading
`[line N] Error: Unexpected character: C`.

    interpreter  compiler/Scanner.a24  ScanToken
    tests        Scan Unrecognized Character Is Recorded

**[SRC-003]**  Inside a comment, a string literal or a character literal, any
byte is permitted and is carried through unchanged. A program may therefore
hold text in any encoding, and the language will neither interpret nor validate
it.

    interpreter  compiler/Scanner.a24  ScanString
    compiler     bootstrap/algol.c     alg_string

**[SRC-004]**  `Length` of a String is its count of BYTES, and subscripting a
String yields the byte at that position. A multi-byte character therefore has a
length greater than one and can be subscripted into its parts.

    interpreter  compiler/Interpreter.a24  LengthNative
    compiler     bootstrap/algol.c         alg_length

> `Length('café')` is 5, not 4, in both processors. Verified.

⚠️ **[SRC-002] and [SRC-003] together mean an identifier is ASCII while a
string is not.** The restriction is on the *program text the scanner reads*,
not on the data a program may carry.

### 3.2 Letters and digits

**[SRC-005]**  The following classes are used by the grammar:

```
letter        = "a" … "z" | "A" … "Z" | "_" | "?" .
decimal_digit = "0" … "9" .
```

    interpreter  compiler/Scanner.a24  IsAlpha
    tests        Scan Identifier With A Question Mark

⚠️ **`?` is a letter; `!` is not.** `Gate?` is a single identifier — one word to
the scanner, and one word to double-click. `Gate!` is not: the `!` is refused as
an unexpected character. There is no `!` operator either; the language spells
negation `not` and inequality `<>`.

### 3.3 Line termination

**[SRC-006]**  A line ends at `#10`. It is the only byte that advances the line
count used by diagnostics.

    interpreter  compiler/Scanner.a24  ScanToken
    tests        Scan Newline
    tests        Scan Comment Ends At Newline

**[SRC-007]**  `#13` is whitespace. It does not end a line, does not advance
the line count, and is not required to be followed by `#10`.

    interpreter  compiler/Scanner.a24  ScanToken

> A file with CRLF endings and the same file with LF endings report identical
> line numbers. A lone `#13` between two statements separates them as any other
> whitespace would. Verified.

**[SRC-008]**  Whitespace is the space, `#9` and `#13`. It separates tokens and
is otherwise insignificant.

    interpreter  compiler/Scanner.a24  ScanToken

**[SRC-009]**  The final line of a file need not be terminated.

    interpreter  compiler/Scanner.a24  IsAtEnd

### 3.4 Case

**[SRC-010]**  Keywords are matched case-insensitively. `begin`, `Begin` and
`BEGIN` are the same keyword.

    interpreter  compiler/Scanner.a24  ScanIdentifier
    tests        Scan Keywords

**[SRC-011]**  Identifiers are case-sensitive. `Xyz` and `xyz` are different
names, and only the keyword *lookup* is lowered — never the lexeme a token
carries.

    interpreter  compiler/Scanner.a24  ScanIdentifier
    tests        Scan Identifier

⚠️ The asymmetry is deliberate and is the one place the language departs from
Pascal's uniform case-insensitivity. A program may declare `Count` and `count`
as two variables; it may not declare a variable named `Begin`.
