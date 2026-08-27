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

**Every rule carries a `conformance` line**, and where no program exists yet its
value is the literal `TBD` — so the gap is stated in the specification rather
than left to be discovered. `spec.sh` requires the line, counts the TBDs, and
`grep 'conformance  TBD' ALGOL-24.md` is the corpus's backlog.

`unit` is cited where a test happens to pin the rule and omitted where none
does. It is deliberately not mandatory: a unit test is a test of algc, and
there is no intention that every rule of the language should have one. The
coverage report names the rules that lack one.

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

### 4.6 Integer literals

**[LEX-015]**  An integer literal is a run of decimal digits.

```
integer_lit = decimal_digit { decimal_digit } .
```

    interpreter  compiler/Scanner.a24  ScanNumber
    unit         Scan Number
    unit         Scan Integer Is Not A Double
    conformance  TBD

**[LEX-016]**  Decimal is the only base. There is no hexadecimal, octal or
binary form, and no digit separator. `0x10` is not a number: it scans as the
integer `0` followed by the identifier `x10`.

    interpreter  compiler/Scanner.a24  ScanNumber
    conformance  TBD

**[LEX-017]**  Leading zeros are permitted and carry no meaning. `007` is the
integer 7, not an octal.

    interpreter  compiler/Scanner.a24  ScanNumber
    conformance  TBD

**[LEX-018]**  An Integer is a signed 32-bit value. A literal outside that
range **wraps silently**, with no diagnostic: `2147483648` is the integer
`-2147483648`, and `99999999999999` is `276447231`. Arithmetic wraps the same
way, so `2147483647 + 1` is `-2147483648`.

    interpreter  compiler/Scanner.a24  ToInteger
    compiler     bootstrap/algol.c     alg_add
    conformance  TBD

> Both processors produce identical wrapped values. See Annex D.

**[LEX-019]**  There is no negative literal. A leading `-` is the unary
operator applied to a non-negative literal, which is why `2-1` is a
subtraction rather than two adjacent expressions.

    interpreter  compiler/Scanner.a24  ScanToken
    conformance  TBD

### 4.7 Double literals

**[LEX-020]**  A double literal requires at least one digit on **both** sides
of the point.

```
double_lit = decimal_digit { decimal_digit } "." decimal_digit { decimal_digit } .
```

    interpreter  compiler/Scanner.a24  ScanNumber
    unit         Scan Number Decimal
    conformance  TBD

**[LEX-021]**  `1.` is therefore not a double. It is the integer `1` followed
by the `.` operator, and a program containing it fails with `Expect property
name after '.'.` Likewise `.5` is not a literal at all.

    interpreter  compiler/Scanner.a24  ScanNumber
    unit         Scan Integer Then Dot
    conformance  TBD

**[LEX-022]**  There is no exponent notation. `1e5` scans as the integer `1`
followed by the identifier `e5`.

    interpreter  compiler/Scanner.a24  ScanNumber
    conformance  TBD

### 4.8 Character literals

**[LEX-023]**  A quoted literal enclosing exactly one byte **of source** is a
Char rather than a String. The measurement is taken on the raw span between the
quotes, not on the value.

    interpreter  compiler/Scanner.a24  ScanString
    unit         Scan One Character Is A Char
    conformance  TBD

**[LEX-024]**  A Char may also be written `#` followed by decimal digits, giving
the character with that code point: `#65` is `A` and `#10` is a line feed. A `#`
not followed by a digit is an error reading `[line N] Error: Invalid character:
C`.

```
char_lit = "'" source_byte "'" | "#" decimal_digit { decimal_digit } .
```

    interpreter  compiler/Scanner.a24  ScanChar
    unit         Scan Char By Code Point
    unit         Scan Char Without Digits
    conformance  TBD

**[LEX-025]**  A Char's code point is limited to 0 … 127. A larger value is a
runtime error reading `Char is limited to 0..127.`

    interpreter  compiler/Interpreter.a24  CharNative
    compiler     bootstrap/algol.c         alg_char
    conformance  TBD

**[LEX-026]**  A Char and a String are never equal, however alike they look.
`'a' = 'a'` is true because both sides are Chars; `Copy('abc', 0, 1) = 'a'` is
**false**, because `Copy` yields a String of length one and the Char `'a'` is
not it.

    interpreter  compiler/Interpreter.a24  IsEqual
    compiler     bootstrap/algol.c         equals
    conformance  TBD

### 4.9 String literals

**[LEX-027]**  A string literal is enclosed in single quotes. A quote within it
is written twice.

```
string_lit = "'" { source_byte_other_than_quote | "''" } "'" .
```

    interpreter  compiler/Scanner.a24  ScanString
    unit         Scan String
    unit         Scan Doubled Quote
    conformance  TBD

**[LEX-028]**  There are no backslash escapes. `'a\nb'` is four bytes, and its
element at index 1 is the backslash itself. A line feed is written `#10` and
concatenated.

    interpreter  compiler/Scanner.a24  ScanString
    conformance  TBD

**[LEX-029]**  `''` is the empty String. `''''` is a String of length one
holding a quote — **not** a Char, because [LEX-023] measures the source span,
which is two bytes.

    interpreter  compiler/Scanner.a24  ScanString
    unit         Scan Empty String
    unit         Scan An Escaped Quote Is A String
    conformance  TBD

**[LEX-030]**  A string literal may span lines. The line feed is part of its
value and advances the line count, so `'one` ⏎ `two'` is seven bytes.

    interpreter  compiler/Scanner.a24  ScanString
    conformance  TBD

**[LEX-031]**  A string that reaches the end of the file unclosed is an error
reading `[line N] Error: Unterminated string.`, where N is the line the scan
reached — not the line the string opened on.

    interpreter  compiler/Scanner.a24  ScanString
    unit         Scan Unterminated String
    conformance  TBD

**[LEX-032]**  A String cannot hold the Char whose code point is 0. The Char
itself is well formed and `#0 is Char` is true, but concatenating it into a
String truncates the String there: `Length('a' + Str(#0) + 'b')` is 2.

    interpreter  compiler/Interpreter.a24  StrNative
    compiler     bootstrap/algol.c         alg_string
    conformance  TBD

> Both processors agree. See Annex D.

---

## 5. Constants and variables

### 5.1 Variable declarations

**[VAR-001]**  A variable is introduced by `var`, with an optional declared type
and an optional initializer.

```
VarDecl = "var" identifier [ ":" Type ] [ ":=" Expression ] ";" .
Type    = identifier [ "of" identifier ] .
```

    interpreter  compiler/Parser.a24  VarDeclaration
    unit         Parse Var Statement
    unit         Parse Var Expect Semicolon
    conformance  TBD

**[VAR-002]**  A variable declared without an initializer holds `nil`, whatever
its declared type. **There is no zero value**: an uninitialized `Integer` is
`nil`, not `0`.

    interpreter  compiler/Interpreter.a24  VisitVarStmt
    conformance  TBD

**[VAR-003]**  A declared type constrains the initializer and every later
assignment. A violation is the error `Type mismatch!`

    interpreter  compiler/TypeChecker.a24  Assignable
    conformance  TBD

**[VAR-004]**  There is **no implicit numeric conversion** in a declaration.
`var X : Integer := 1.5;` is a mismatch, and so is `var X : Double := 1;` —
widening is refused as firmly as narrowing.

    interpreter  compiler/TypeChecker.a24  Assignable
    conformance  TBD

> See Annex D.

**[VAR-005]**  `nil` satisfies every declared type, so `var X : Integer := nil;`
is accepted.

    interpreter  compiler/TypeChecker.a24  Assignable
    compiler     bootstrap/algol.c         alg_is
    conformance  TBD

**[VAR-006]**  `Any` is the declared type meaning *not known*. It accepts every
value and is compatible in both directions.

    interpreter  compiler/TypeChecker.a24  Assignable
    conformance  TBD

**[VAR-007]**  A name may not be declared twice in one scope. The second is
refused with `'X' is already defined.`

    interpreter  compiler/Resolver.a24  CheckDuplicates
    unit         Resolve Duplicate Variable
    conformance  TBD

**[VAR-008]**  A collection may carry an element type, written `of`:
`var L : List of Integer := [];`. The element type is honoured only after
`List`.

    interpreter  compiler/Parser.a24  VarDeclaration
    conformance  TBD

### 5.2 Sections

**[VAR-009]**  In the header of a function, procedure, class or object, `var`
may open a **section**: a run of declarations, each ending in `;`, closed by the
next section marker or by `begin`.

```
VarSection = "var" { identifier { "," identifier } [ ":" Type ] [ ":=" Expression ] ";" } .
```

    interpreter  compiler/Parser.a24  DeclarationSection
    unit         Parse A Function Local Var Section
    conformance  TBD

**[VAR-010]**  Within a section several names may share one declaration:
`A, B : Integer;` declares both.

    interpreter  compiler/Parser.a24  DeclarationSection
    unit         Parse A Comma Group Stays A Group
    unit         Parse A Single Name Is Not A Group
    conformance  TBD

**[VAR-011]**  A section is a feature of a **header**, not of a program body. At
the top level `var` declares exactly one name, and a run of declarations
beneath it is read as ordinary statements — `var A : Integer;` followed by
`B : String;` fails on the second with `Expect ';' after expression.`

    interpreter  compiler/Parser.a24  ReadDeclarationSections
    conformance  TBD

### 5.3 Constants

**[VAR-012]**  A constant is introduced by `const` and **must** be given a
value. Omitting the initializer is refused with `A constant must be given a
value.`

```
ConstDecl = "const" identifier [ ":" Type ] ":=" Expression ";" .
```

    interpreter  compiler/Parser.a24  ConstDeclaration
    unit         Parse A Constant Must Be Given A Value
    conformance  TBD

**[VAR-013]**  A constant may not be assigned to. The attempt is refused with
`Can't assign to constant 'C'.`

    interpreter  compiler/Resolver.a24  VisitAssignExpr
    conformance  TBD

**[VAR-014]**  ⚠️ A constant's initializer is an **ordinary expression evaluated
at run time**, not a constant expression. `const C := 1 + 2;` is legal, and so
is `const C := V;` where `V` is a variable — the constant takes whatever value
`V` held at that moment.

`const` therefore means *this binding may not be reassigned*, not *this value is
known before the program runs*.

    interpreter  compiler/Interpreter.a24  VisitVarStmt
    conformance  TBD

**[VAR-015]**  `const` may open a section on the same terms as `var`, and the
two may appear together in one header.

    interpreter  compiler/Parser.a24  DeclarationSection
    unit         Parse A Const Section
    unit         Parse Var And Const Sections Together
    conformance  TBD

---

## Annex D — advisory notes *(non-normative)*

Where the specified behaviour looks like a mistake. Nothing here weakens the
rule it refers to: the body states what the language does, and this annex
argues about it. Entries are added as the chapters that expose them are
written.

**D-1 — Integer overflow is silent.** *(refers to [LEX-018])*

A literal or an arithmetic result outside the signed 32-bit range wraps with no
diagnostic, so `2147483648` is `-2147483648` and `99999999999999` is
`276447231`. A program can compute a wrong answer and give no sign of it.

Both processors wrap identically, so this is at least consistent, and the
wrapping is what C does natively — making it free in the compiler and
deliberate work to detect. Changing it would mean either a check on every
arithmetic operation or a widened Integer, and it would break any program
relying on the wrap.

*Recommended:* raise on overflow. A language whose compiler is written in
itself cannot afford a silent wrong answer in its own arithmetic, and the cost
is a branch on operations that are not this language's bottleneck.

**D-2 — `?` alone is a valid identifier.** *(refers to [LEX-008])*

Because `?` is classed as a letter so that `Gate?` scans as one word, it may
also *begin* an identifier, and `var ? := 7;` declares a variable named `?`.
That is almost certainly not intended; it falls out of the letter class rather
than from any decision.

*Recommended:* keep `?` as a trailing character only — a letter for the purpose
of continuing an identifier, not of starting one. No plausible program relies
on the current rule, and the change is confined to `IsAlpha` and its caller.

**D-3 — `#0` is constructible but unstorable.** *(refers to [LEX-032])*

`#0` yields a Char, and a Char is a value like any other, but putting one into
a String silently truncates it. The String type is C's NUL-terminated
representation showing through, and the language does not say so anywhere.

*Recommended:* either refuse `#0` at construction, as [LEX-025] already refuses
128 and above, or give String an explicit length so it can hold a zero byte.
Refusing is much the smaller change and matches the existing range check;
storing it honestly is the better language.

**D-4 — Widening is refused as firmly as narrowing.** *(refers to [VAR-004])*

`var X : Integer := 1.5;` should certainly be refused: the value does not fit.
But `var X : Double := 1;` is refused on the same terms, and there the value
fits exactly and every arithmetic operation in the language already promotes an
Integer to a Double when the two meet. A programmer who writes `: Double` and
initializes with `0` is told the types do not match.

The rule is at least symmetric and easy to state, and any relaxation has to
answer what `var X : Double := 1;` then makes `X` — a Double holding 1.0, or an
Integer that a declaration lied about.

*Recommended:* permit Integer where Double is declared, converting at the point
of assignment, and leave narrowing refused. It matches what the arithmetic
already does, and the alternative teaches that a declared type means something
narrower than the operators do.

**D-5 — `const` promises less than it appears to.** *(refers to [VAR-014])*

`const C := V;` is legal where `V` is a variable, so a constant's value need not
be known before the program runs. The word means only that the binding cannot
be reassigned. A reader who takes `const` to mean a compile-time constant — as
Pascal's does, and as most languages' do — will be wrong about when the
initializer runs and about what the compiler can assume.

Nothing here is broken, and the run-time form is genuinely useful for a value
computed once at startup.

*Recommended:* keep the behaviour and say so plainly in the language's own
documentation, which currently does not. If a true compile-time constant is
wanted later it needs a different word, not a narrowing of this one.
