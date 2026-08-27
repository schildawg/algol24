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

---

## 4. Lexical elements

### 4.1 Comments

**[LEX-001]**  A comment begins with `//` and runs to the end of the line, or to
the end of the file if no `#10` follows. It is discarded and forms no token.

    interpreter  compiler/Scanner.a24  ScanToken
    tests        Scan Comment
    tests        Scan Comment Ends At Newline

**[LEX-002]**  `///` is not a distinct form. The scanner sees `//` followed by a
comment whose first character is `/`, and treats it as any other comment.

    interpreter  compiler/Scanner.a24  ScanToken

> The project writes documentation comments as `///` by convention, and tools
> may treat them specially. The language does not.

**[LEX-003]**  There are no block comments and no nesting. `{ … }` and
`(* … *)` are not comments: the braces are refused as unexpected characters,
and the parenthesis form is read as an expression.

    interpreter  compiler/Scanner.a24  ScanToken

### 4.2 Tokens

**[LEX-004]**  A token is an identifier, a keyword, a literal, or an operator
or item of punctuation. Whitespace and comments separate tokens and are
otherwise discarded.

    interpreter  compiler/Scanner.a24  ScanTokens
    tests        Scan Tokens

**[LEX-005]**  Where a shorter and a longer token both match, the longer is
taken. `<` followed by `>` is one `<>`; `<` followed by anything else is a `<`
on its own.

    interpreter  compiler/Scanner.a24  ScanToken
    tests        Scan Less Is Not Greedy

> `<<><=<` scans as `<`, `<>`, `<=`, `<` — four tokens.

**[LEX-006]**  There is no automatic semicolon insertion. A line ending is
whitespace and never stands in for a `;`.

    interpreter  compiler/Scanner.a24  ScanToken

### 4.3 Identifiers

**[LEX-007]**  An identifier is a letter followed by any number of letters and
digits. `letter` and `decimal_digit` are as defined in [SRC-005], so `_` and
`?` are letters.

```
identifier = letter { letter | decimal_digit } .
```

    interpreter  compiler/Scanner.a24  ScanIdentifier
    tests        Scan Identifier
    tests        Scan Identifier With A Question Mark

**[LEX-008]**  Because `?` and `_` are letters, either may begin an identifier,
and `?` alone is a well-formed identifier.

    interpreter  compiler/Scanner.a24  IsAlpha

> `var ?abc := 7;` declares a variable. So does `var ? := 7;`. See Annex D.

**[LEX-009]**  An identifier may not be spelled the same as a keyword in any
case, because the keyword is recognised first. `var begin := 7;` and
`var BEGIN := 7;` are both refused with `Expect variable name.`

    interpreter  compiler/Scanner.a24  ScanIdentifier
    tests        Scan Keywords

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
    tests        Scan Keywords

**[LEX-011]**  `unit`, `test` and `on` are **not** keywords. They are ordinary
identifiers that the grammar recognises by position — `unit` opening a file,
`test` before a block's quoted name, `on` introducing a handler — and each may
be used as a variable name.

    interpreter  compiler/Scanner.a24  Keywords
    interpreter  compiler/Parser.a24   UnitHeader
    tests        Parse On Is Not A Keyword

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
    tests        Scan Operators

**[LEX-013]**  `=` is equality and `:=` is assignment. Inequality is `<>`.
There is no `==`, no `!` and no `!=`; `!` is not a character the scanner
accepts anywhere outside a comment or a literal.

    interpreter  compiler/Scanner.a24   ScanToken
    interpreter  compiler/TokenType.a24 TOKEN_ASSIGN
    tests        Scan Operators

**[LEX-014]**  `and`, `or`, `not`, `in`, `is` and `as` are operators spelled as
keywords rather than punctuation, and are subject to [SRC-010].

    interpreter  compiler/Scanner.a24  Keywords
    tests        Scan Keywords

⚠️ `{` and `}` are not tokens of the language at all — not as comment
delimiters, not as block delimiters, and not as set constructors. A block is
`begin` … `end`; a collection literal uses `[` and `]`.
