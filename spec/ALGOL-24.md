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
    unit         Scan A Whole Program
    conformance  TBD

⚠️ **Identifiers are permanent.** They are assigned once, never reused and
never renumbered; sections may be renamed and reordered freely. Numbering the
sections instead would mean that inserting one clause silently rots every
citation to everything after it.

The trailer is machine-readable and `spec/spec.sh` checks every line of it. The
four keys do different jobs, and two of them are easy to confuse:

| Key | Names | Answers |
| --- | --- | --- |
| `interpreter` | a file and symbol in `compiler/*.a24` | where the authority implements this |
| `compiler` | a file and symbol in `bootstrap/algol.c` | where the C back end implements it, when it has a say |
| `unit` | a test in the `compiler/` suite | evidence the rule *transcribes the authority accurately* |
| `conformance` | a program in `conformance/` | a check that *any implementation* obeys the rule |

⚠️ **`unit` is not conformance evidence, and the distinction is not pedantic.**
A unit test reaches into algc's own classes — it constructs a `Scanner` and
asserts token types — so it tests the implementation, not the language. It is
still worth citing, because [1.1] makes the interpreter normative and a test
pinning the interpreter's behaviour therefore pins the language's. But another
implementation has no `Scanner` class to test, so a unit test can never be run
against it. Only a conformance program can.

**Every rule carries both keys.** Where no conformance program exists yet the
value is the literal `TBD`, so the gap is stated in the specification rather
than left to be discovered. `spec.sh` counts them, and
`grep 'conformance  TBD' ALGOL-24.md` is the corpus's backlog.

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
    unit         Scan A Whole Program
    conformance  TBD

**[SRC-002]**  Outside comments, string literals and character literals, every
byte must be one the scanner recognises. Any other byte is an error reading
`[line N] Error: Unexpected character: C`.

    interpreter  compiler/Scanner.a24  ScanToken
    unit         Scan Unrecognized Character Is Recorded
    conformance  TBD

**[SRC-003]**  Inside a comment, a string literal or a character literal, any
byte is permitted and is carried through unchanged. A program may therefore
hold text in any encoding, and the language will neither interpret nor validate
it.

    interpreter  compiler/Scanner.a24  ScanString
    compiler     bootstrap/algol.c     alg_string
    conformance  TBD

**[SRC-004]**  `Length` of a String is its count of BYTES, and subscripting a
String yields the byte at that position. A multi-byte character therefore has a
length greater than one and can be subscripted into its parts.

    interpreter  compiler/Interpreter.a24  LengthNative
    compiler     bootstrap/algol.c         alg_length
    conformance  TBD

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
    unit         Scan Identifier With A Question Mark
    conformance  TBD

⚠️ **`?` is a letter; `!` is not.** `Gate?` is a single identifier — one word to
the scanner, and one word to double-click. `Gate!` is not: the `!` is refused as
an unexpected character. There is no `!` operator either; the language spells
negation `not` and inequality `<>`.

### 3.3 Line termination

**[SRC-006]**  A line ends at `#10`. It is the only byte that advances the line
count used by diagnostics.

    interpreter  compiler/Scanner.a24  ScanToken
    unit         Scan Newline
    unit         Scan Comment Ends At Newline
    conformance  TBD

**[SRC-007]**  `#13` is whitespace. It does not end a line, does not advance
the line count, and is not required to be followed by `#10`.

    interpreter  compiler/Scanner.a24  ScanToken
    conformance  TBD

> A file with CRLF endings and the same file with LF endings report identical
> line numbers. A lone `#13` between two statements separates them as any other
> whitespace would. Verified.

**[SRC-008]**  Whitespace is the space, `#9` and `#13`. It separates tokens and
is otherwise insignificant.

    interpreter  compiler/Scanner.a24  ScanToken
    conformance  TBD

**[SRC-009]**  The final line of a file need not be terminated.

    interpreter  compiler/Scanner.a24  IsAtEnd
    conformance  TBD

### 3.4 Case

**[SRC-010]**  Keywords are matched case-insensitively. `begin`, `Begin` and
`BEGIN` are the same keyword.

    interpreter  compiler/Scanner.a24  ScanIdentifier
    unit         Scan Keywords
    conformance  TBD

**[SRC-011]**  Identifiers are case-sensitive. `Xyz` and `xyz` are different
names, and only the keyword *lookup* is lowered — never the lexeme a token
carries.

    interpreter  compiler/Scanner.a24  ScanIdentifier
    unit         Scan Identifier
    conformance  TBD

⚠️ The asymmetry is deliberate and is the one place the language departs from
Pascal's uniform case-insensitivity. A program may declare `Count` and `count`
as two variables; it may not declare a variable named `Begin`.

---

## 4. Lexical elements

### 4.1 Comments

**[LEX-001]**  A comment begins with `//` and runs to the end of the line, or to
the end of the file if no `#10` follows. It is discarded and forms no token.

    interpreter  compiler/Scanner.a24  ScanToken
    unit         Scan Comment
    unit         Scan Comment Ends At Newline
    conformance  TBD

**[LEX-002]**  `///` is not a distinct form. The scanner sees `//` followed by a
comment whose first character is `/`, and treats it as any other comment.

    interpreter  compiler/Scanner.a24  ScanToken
    conformance  TBD

> The project writes documentation comments as `///` by convention, and tools
> may treat them specially. The language does not.

**[LEX-003]**  There are no block comments and no nesting. `{ … }` and
`(* … *)` are not comments: the braces are refused as unexpected characters,
and the parenthesis form is read as an expression.

    interpreter  compiler/Scanner.a24  ScanToken
    conformance  TBD

### 4.2 Tokens

**[LEX-004]**  A token is an identifier, a keyword, a literal, or an operator
or item of punctuation. Whitespace and comments separate tokens and are
otherwise discarded.

    interpreter  compiler/Scanner.a24  ScanTokens
    unit         Scan Tokens
    conformance  TBD

**[LEX-005]**  Where a shorter and a longer token both match, the longer is
taken. `<` followed by `>` is one `<>`; `<` followed by anything else is a `<`
on its own.

    interpreter  compiler/Scanner.a24  ScanToken
    unit         Scan Less Is Not Greedy
    conformance  TBD

> `<<><=<` scans as `<`, `<>`, `<=`, `<` — four tokens.

**[LEX-006]**  There is no automatic semicolon insertion. A line ending is
whitespace and never stands in for a `;`.

    interpreter  compiler/Scanner.a24  ScanToken
    conformance  TBD

### 4.3 Identifiers

**[LEX-007]**  An identifier is a letter followed by any number of letters and
digits. `letter` and `decimal_digit` are as defined in [SRC-005], so `_` and
`?` are letters.

```
identifier = letter { letter | decimal_digit } .
```

    interpreter  compiler/Scanner.a24  ScanIdentifier
    unit         Scan Identifier
    unit         Scan Identifier With A Question Mark
    conformance  TBD

**[LEX-008]**  Because `?` and `_` are letters, either may begin an identifier,
and `?` alone is a well-formed identifier.

    interpreter  compiler/Scanner.a24  IsAlpha
    conformance  TBD

> `var ?abc := 7;` declares a variable. So does `var ? := 7;`. See Annex D.

**[LEX-009]**  An identifier may not be spelled the same as a keyword in any
case, because the keyword is recognised first. `var begin := 7;` and
`var BEGIN := 7;` are both refused with `Expect variable name.`

    interpreter  compiler/Scanner.a24  ScanIdentifier
    unit         Scan Keywords
    conformance  TBD

### 4.4 Keywords

**[LEX-010]**  The following 38 words are keywords and are matched
case-insensitively per [SRC-010]:

```
and     as       begin   break   case    class     const   constructor
do      else     end     except  exit    false     for     function
if      in       is      nil     not     object    of      or
print   private  procedure       public  raise     super   then
this    true     try     type    uses    var       while
```

    interpreter  compiler/Scanner.a24  Keywords
    unit         Scan Keywords
    conformance  TBD

**[LEX-011]**  `unit`, `test` and `on` are **not** keywords. They are ordinary
identifiers that the grammar recognises by position — `unit` opening a file,
`test` before a block's quoted name, `on` introducing a handler — and each may
be used as a variable name.

    interpreter  compiler/Scanner.a24  Keywords
    interpreter  compiler/Parser.a24   UnitHeader
    unit         Parse On Is Not A Keyword
    conformance  TBD

> `var test := 7;` is a valid declaration, and so are the `unit` and `on`
> forms. Verified in all three.

### 4.5 Operators and punctuation

**[LEX-012]**  The following are operators and punctuation:

```
(    )    [    ]    ,    .    ;    :
+    -    *    /    =    :=
<    <=   >    >=   <>
```

    interpreter  compiler/Scanner.a24  ScanToken
    unit         Scan Operators
    conformance  TBD

**[LEX-013]**  `=` is equality and `:=` is assignment. Inequality is `<>`.
There is no `==`, no `!` and no `!=`; `!` is not a character the scanner
accepts anywhere outside a comment or a literal.

    interpreter  compiler/Scanner.a24   ScanToken
    interpreter  compiler/TokenType.a24 TOKEN_ASSIGN
    unit         Scan Operators
    conformance  TBD

**[LEX-014]**  `and`, `or`, `not`, `in`, `is` and `as` are operators spelled as
keywords rather than punctuation, and are subject to [SRC-010].

    interpreter  compiler/Scanner.a24  Keywords
    unit         Scan Keywords
    conformance  TBD

⚠️ `{` and `}` are not tokens of the language at all — not as comment
delimiters, not as block delimiters, and not as set constructors. A block is
`begin` … `end`; a collection literal uses `[` and `]`.
