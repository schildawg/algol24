# The Algol-24 Programming Language Specification

> **Status: the specification is read, corrected and signed off.** Nineteen
> chapters and eight annexes, 273 rules. Every rule is **decided** — what the
> language should do — and every rule is claimed by a case: a program in
> `conformance/`, a refusal in `refusals/`, or a reproduction in `defects/`.
> None awaits one.
>
> ⚠️ **This document is the authority, and the implementation is measured
> against it** [1.1]. Where the two disagree, a defect in Annex F says so and
> carries a reproduction that passes while the fault persists. **Annex F is
> empty**: every defect it held has been fixed and `defects/` is empty with it.
> A rule ahead of the implementation says which of three things it is —
> `NOT YET IMPLEMENTED`, `PARTLY IMPLEMENTED`, or `PLANNED — a later generation`
> — and `spec/spec.sh` enforces that each points somewhere.
>
> Annex C records **36 divergences** between the interpreter and the C back end,
> and **all of them are withdrawn**: `./conform.sh` reports no gap, so every case
> the interpreter gets right the compiled back end gets right too. Annex D's
> eighteen advisory notes are all resolved. Annex H holds nine changes planned
> for later generations.
>
> ⚠️ **The entries stay after they are withdrawn**, and are worth more than the
> count. Each carries what was actually wrong, which in a dozen cases is not what
> the entry first recorded — several name a mistake in their own proposed fix.
>
> ⚠️ **From this tag onward the document leads and the implementation follows.**
> A defect is closed by changing the code; a rule is changed only by deciding to
> change the language, and the reason is recorded here when it is. See
> `spec/PLAN.md` for the generations.

---

## 1. Introduction

Algol-24 is a Pascal-flavoured, gradually typed language. This document
specifies its lexis, syntax, and semantics.

### 1.1 Authority

⚠️ **This specification is the authority.** Where an implementation differs from
a rule, the implementation is in error, and the difference is recorded as a
numbered defect in Annex F with a program that reproduces it.

That was not always so. Every rule here began as a description of what the
tree-walking interpreter in `compiler/*.a24` does, verified by **running** it
rather than by reading it — and most rules still are exactly that. A rule is
only allowed to depart from the implementation by an explicit decision, and when
it does it carries a marker:

> ⚠️ **NOT YET IMPLEMENTED.** … See DEF-nn.

⚠️ **A rule without such a marker describes behaviour that was observed.** A rule
with one describes behaviour that was decided. The distinction is what keeps the
document trustworthy, and it is why the markers are in the normative text rather
than in an annex.

⚠️ **The specification does not hedge.** Where a behaviour is kept despite
looking wrong, it is stated flatly and the misgiving goes to Annex D. A
specification that argues with itself cannot be conformed to.

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

**Every rule is claimed by a case**, cited as `conformance`, `refusal` or
`defect`. Which of the three is decided by one question — is the interpreter
right? — and `conformance/README.md` explains it. Where no case existed the
value was the literal `TBD`, so the gap was stated rather than left to be
discovered; **that backlog is now empty**, and `spec.sh` still requires the line
so a new rule cannot be added without one.

⚠️ A rule may cite more than one, and most cases pin more than one rule. A
partly implemented rule cites a conformance program for the half that works and
a defect for the half that does not, so the per-kind counts overlap and do not
sum to the total. `spec.sh --coverage` reports them separately.

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

**[SRC-001]**  Source text is **UTF-8**. A character, not a byte, is the unit
of measurement and of subscripting.

⚠️ A String carries its own **byte length** beside its pointer, so it may hold a
zero character. It is NUL-terminated as well, which keeps `as_text` cheap for
everything that builds a diagnostic; only the value-semantic operations —
concat, output, equality, hashing, `Copy`, `Pos`, `Length`, subscript — consult
the length.

    interpreter  compiler/Scanner.a24  ScanTokens
    compiler     bootstrap/algol.c     alg_length
    unit         Scan A Whole Program
    conformance  0128-text-is-characters.a24
    conformance  0131-a-string-holds-a-zero-character.a24

**[SRC-002]**  Outside comments, string literals and character literals, every
character must be one the scanner recognises — a letter [SRC-005], a digit, or
an operator or item of punctuation [LEX-012]. Any other is an error reading
`[line N] Error: Unexpected character: C`.

⚠️ The scanner used to refuse every non-ASCII byte outright, so no Unicode
character could appear in a program at all outside a comment or a literal.

    interpreter  compiler/Scanner.a24  ScanToken
    unit         Scan Unrecognized Character Is Recorded
    refusal      0001-unexpected-character.a24

**[SRC-003]**  Inside a comment, a string literal or a character literal, any
byte is permitted and is carried through unchanged. A program may therefore
hold text in any encoding, and the language will neither interpret nor validate
it.

    interpreter  compiler/Scanner.a24  ScanString
    compiler     bootstrap/algol.c     alg_string
    conformance  0001-source-is-utf8-text.a24

**[SRC-004]**  `Length` of a String is its count of **characters**, and
subscripting a String yields the character at that position. `Length('café')` is
4, and `'café'[3]` is `é`.

The same holds for every operation that counts or indexes text — `Copy`, `Pos`,
and `Ord` [16.2].

⚠️ **Counting characters came out faster than counting bytes**, which is not the
direction it looks. Subscripting text used to call `strlen` on the whole string
for every character, so the scanner walked its entire source once per character
read — quadratic, and nothing had noticed. Caching a string's character count
by pointer removed that: measured over three runs of `./test.sh`, 20.1 s against
21.2 s before.

    interpreter  compiler/Interpreter.a24  LengthNative
    compiler     bootstrap/algol.c         alg_length
    conformance  0128-text-is-characters.a24

⚠️ **[SRC-002] and [SRC-003] together mean an identifier is ASCII while a
string is not.** The restriction is on the *program text the scanner reads*,
not on the data a program may carry.

### 3.2 Letters and digits

**[SRC-005]**  The following classes are used by the grammar:

```
letter          = "a" … "z" | "A" … "Z" | "_" | unicode_character .
decimal_digit   = "0" … "9" .
hex_digit       = decimal_digit | "a" … "f" | "A" … "F" .
binary_digit    = "0" | "1" .
identifier_mark = "?" | "!" .
```

`unicode_character` is **any** character above U+007F, whatever Unicode
classifies it as. `café`, `Straße`, `日本`, `🙂` and `💩` are all identifiers.

⚠️ **There is no category test, and that is deliberate.** Nothing above U+007F
is excluded, so the language needs no Unicode tables at all — Annex G.3's
mangling escapes whatever C cannot spell as `U` followed by six hexadecimal
digits, and there is nothing left for a classification to decide.

⚠️ This briefly read `unicode_letter` literally, and the implementation grew a
659-range table of categories Lu, Ll, Lt, Lm and Lo to match. That excluded `🙂`
and `💩`, which are identifiers here, and the table answered a question the
language does not ask. Both were removed.

⚠️ A Unicode **digit** is therefore an ordinary identifier character. Only ASCII
`0`–`9` are digits to the *number* scanner, so `٠` cannot start a numeric
literal, but it may appear in a name.

⚠️ `decimal_digit` and `identifier_mark` are still ASCII, and a digit or a mark
may not **lead** [LEX-007]. A character above U+007F may.

    interpreter  compiler/Scanner.a24  IsAlpha
    compiler     compiler/CEmitter.a24  Escaped
    unit         Scan Identifier With A Question Mark
    conformance  0002-letters-and-digits.a24
    conformance  0128-text-is-characters.a24
    conformance  0139-unicode-identifiers.a24

⚠️ **An identifier mark is not a letter.** `?` and `!` may appear *within* an
identifier but may not begin one [LEX-007], so `Gate?` and `Gate!` are each a
single word — one word to the scanner, and one word to double-click — while `?`
and `!` alone are not identifiers at all. `_` is a letter and may lead.

Neither mark is an operator. The language spells negation `not` and inequality
`<>`, so nothing else wants the characters.

### 3.3 Line termination

**[SRC-006]**  A line ends at `#10`. A `#13` immediately preceding it is part of
the terminator and is absorbed with it, so a file with CRLF endings and the same
file with LF endings report identical line numbers.

⚠️ The two cases below are a **pair**, and neither proves the rule alone: they
are the same program with different line endings, and the rule is that they
report identically.

    interpreter  compiler/Scanner.a24  ScanToken
    unit         Scan Newline
    unit         Scan Comment Ends At Newline
    conformance  0006-line-endings-lf.a24
    conformance  0006-line-endings-crlf.a24

**[SRC-007]**  Any **other** `#13` is not a terminator. In source it is
whitespace [SRC-008]; in data it is ordinary text that `ReadLn` returns
[RT-016].

⚠️ A file whose only line endings are `#13` therefore holds **one line**, in
source and in data alike. Every diagnostic in such a source file reports
`line 1`.

⚠️ A sharper consequence, from this rule meeting [LEX-001]: a comment runs to
`#10` or to end of file, so **a `//` comment in a file with no `#10` anywhere
swallows the rest of the file**. A CR-only source beginning with a comment is
therefore an empty program that runs and does nothing, rather than one that
fails to compile.

This follows from having a single rule rather than three, and it is the reason
for having one: `#10` terminates everywhere, `#13#10` counts once, and a stray
`#13` is never a terminator in either subsystem. Admitting a lone `#13` as a
third convention would buy compatibility with a format no live system produces,
at the cost of changing how `ReadLn` splits data — so a program reading text
with embedded `#13` bytes that are not line endings would start dividing it
differently.

    interpreter  compiler/Scanner.a24  ScanToken
    conformance  0007-carriage-return-only.a24
    conformance  0009-comment-swallows-a-cr-only-file.a24

> A file with CRLF endings and the same file with LF endings report identical
> line numbers. A lone `#13` between two statements separates them as any other
> whitespace would. Verified.

**[SRC-008]**  Whitespace is the space, `#9` and `#13`. It separates tokens and
is otherwise insignificant.

    interpreter  compiler/Scanner.a24  ScanToken
    conformance  0003-line-termination.a24

**[SRC-009]**  The final line of a file need not be terminated.

    interpreter  compiler/Scanner.a24  IsAtEnd
    conformance  0004-final-line-need-not-be-terminated.a24

### 3.4 Case

**[SRC-010]**  Keywords are matched case-insensitively. `begin`, `Begin` and
`BEGIN` are the same keyword.

    interpreter  compiler/Scanner.a24  ScanIdentifier
    unit         Scan Keywords
    conformance  0005-keywords-are-case-insensitive.a24

**[SRC-011]**  Identifiers are matched **case-insensitively**, as keywords are.
`Xyz` and `xyz` are one name, and declaring both in one scope is a duplicate
[VAR-007].

⚠️ Folding is **ASCII-only**. `Straße` and `STRASSE` are different names.

⚠️ **This is a decision, not a gap, and it survived the letter table arriving.**
`compiler/Unicode.a24` carries the letters because [SRC-005] needs them;
admitting Unicode *case folding* is a separate change to this rule, not a
consequence of that one. Full folding maps `ß` to `ss`, which would make those
two one name — a different language from the one signed off here.

⚠️ Only the *lookup* is folded. A diagnostic quotes the lexeme **as written**, so
a program declaring `Xyz` and misspelling it `xyZ` is told about `xyZ`.

⚠️ Folding happens where a name becomes a **key**, never to the lexeme itself,
through one named function so that every store folds the same way as every
lookup. `compiler/Token.a24`'s `FoldCase` scans for an uppercase letter before
building anything, because a name that is already folded must not allocate.

⚠️ **Every diagnostic on the path had to be corrected.** Folding the key made
messages echo the key: a program writing `Shared` was told about `shared`, a
unit spelled `Deep` was reported as `deep`. A message names the occurrence the
program wrote.

    interpreter  compiler/Token.a24        FoldCase
    interpreter  compiler/Environment.a24  Get
    conformance  0126-identifiers-are-case-insensitive.a24
    refusal      0036-case-insensitive-duplicate.a24

⚠️ **Folding is uniform**, as Pascal's is: a name is a name whether it is a
keyword, a variable, a field, a method or a type [VAL-006]. A program may not
declare `Count` and `count` as two variables, and may not declare a variable
named `Begin` [LEX-009].

⚠️ **A module name is the one exception**, and it is not the language's to
make: a module names a file, and the filesystem decides how that name is
matched. See [MOD-002].

---

## 4. Lexical elements

### 4.1 Comments

**[LEX-001]**  A comment begins with `//` and runs to the end of the line, or to
the end of the file if no `#10` follows. It is discarded and forms no token.

    interpreter  compiler/Scanner.a24  ScanToken
    unit         Scan Comment
    unit         Scan Comment Ends At Newline
    conformance  0011-comments.a24

**[LEX-002]**  `///` is not a distinct form. The scanner sees `//` followed by a
comment whose first character is `/`, and treats it as any other comment.

    interpreter  compiler/Scanner.a24  ScanToken
    conformance  0011-comments.a24

> The project writes documentation comments as `///` by convention, and tools
> may treat them specially. The language does not.

**[LEX-003]**  There are no block comments and no nesting. `{ … }` and
`(* … *)` are not comments. The braces are refused as unexpected characters
[SRC-002]; the parenthesis form scans as a `(` followed by a `*`, which is not
a prefix operator, and fails with `Expect expression!`.

    interpreter  compiler/Scanner.a24  ScanToken
    refusal      0002-block-comment-braces.a24

### 4.2 Tokens

**[LEX-004]**  A token is an identifier, a keyword, a literal, or an operator
or item of punctuation. Whitespace and comments separate tokens and are
otherwise discarded.

    interpreter  compiler/Scanner.a24  ScanTokens
    unit         Scan Tokens
    conformance  0017-tokens-and-separation.a24

**[LEX-005]**  Where a shorter and a longer token both match, the longer is
taken. `<` followed by `>` is one `<>`; `<` followed by anything else is a `<`
on its own.

    interpreter  compiler/Scanner.a24  ScanToken
    unit         Scan Less Is Not Greedy
    conformance  0012-operators.a24

> `<<><=<` scans as `<`, `<>`, `<=`, `<` — four tokens.

**[LEX-006]**  There is no automatic semicolon insertion. A line ending is
whitespace and never stands in for a `;`.

    interpreter  compiler/Scanner.a24  ScanToken
    refusal      0004-no-semicolon-insertion.a24

### 4.3 Identifiers

**[LEX-007]**  An identifier is a **letter** followed by any number of letters,
digits and identifier marks. `letter`, `decimal_digit` and `identifier_mark`
are as defined in [SRC-005].

```
identifier = letter { letter | decimal_digit | identifier_mark } .
```

`Gate?`, `Send!`, `_under` and `a1b2` are identifiers. `Ready?Set` is one
identifier too: a mark does not end a word.

    interpreter  compiler/Scanner.a24  ScanIdentifier
    unit         Scan Identifier
    unit         Scan Identifier With A Question Mark
    conformance  0010-identifier-forms.a24
    conformance  0120-identifier-marks.a24

**[LEX-008]**  An identifier mark may not **begin** an identifier. `?` and `!`
alone are not identifiers, and neither are `?abc` and `!abc`: the mark is
refused as an unexpected character [SRC-002], because nothing else in the
language claims it.

    interpreter  compiler/Scanner.a24  IsMark
    refusal      0032-a-mark-may-not-begin-an-identifier.a24

> The rule exists so that `Gate?` can be one word without `?` also becoming a
> name. A trailing mark reads as punctuation on a word; a leading one reads as
> an operator the language does not have.

**[LEX-009]**  An identifier may not be spelled the same as a keyword in any
case, because the keyword is recognised first. `var begin := 7;` and
`var BEGIN := 7;` are both refused with `Expect variable name.`

    interpreter  compiler/Scanner.a24  ScanIdentifier
    unit         Scan Keywords
    refusal      0003-keyword-is-not-a-name.a24

### 4.4 Keywords

**[LEX-010]**  The following 42 words are keywords and are matched
case-insensitively per [SRC-010]:

```
and     as       begin   break   case    class     const   constructor
continue         div     do      else    end       except  exit
false   for      function        goto    if        in      is
nil     not      object  of      operator          or      private
procedure        property        public  raise     super   then
this    true     try     type    uses    var       while
```

No other word is a keyword. Every word not in this list is an identifier and
may be declared as a name.

⚠️ `print` used to be registered as a thirty-eighth, introducing a statement
[STM-022]. Neither was part of the language, and `var print := 7;` was refused
with `Expect variable name.`

    interpreter  compiler/Scanner.a24  Keywords
    unit         Scan Keywords
    conformance  0133-print-is-an-ordinary-name.a24

**[LEX-011]**  `unit`, `test` and `on` are **not** keywords. They are ordinary
identifiers that the grammar recognises by position — `unit` opening a file,
`test` before a block's quoted name, `on` introducing a handler — and each may
be used as a variable name.

    interpreter  compiler/Scanner.a24  Keywords
    interpreter  compiler/Parser.a24   UnitHeader
    unit         Parse On Is Not A Keyword
    conformance  0018-context-sensitive-words.a24

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
    conformance  0012-operators.a24

**[LEX-013]**  `=` is equality and `:=` is assignment. Inequality is `<>`.
There is no `==`, no `!=` and no `!` operator: negation is `not`, and `!` is an
identifier mark [SRC-005] rather than punctuation.

    interpreter  compiler/Scanner.a24   ScanToken
    interpreter  compiler/TokenType.a24 TOKEN_ASSIGN
    unit         Scan Operators
    conformance  0012-operators.a24

> Because `!` never begins a token [LEX-008], `A!=B` is unambiguous: it is the
> identifier `A!` compared with `B`. There is no `!=` for it to be mistaken for.

**[LEX-014]**  `and`, `or`, `not`, `in`, `is` and `as` are operators spelled as
keywords rather than punctuation, and are subject to [SRC-010].

    interpreter  compiler/Scanner.a24  Keywords
    unit         Scan Keywords
    conformance  0012-operators.a24

⚠️ `{` and `}` are not tokens of the language at all — not as comment
delimiters, not as block delimiters, and not as set constructors. A block is
`begin` … `end`; a collection literal uses `[` and `]`.

### 4.6 Integer literals

**[LEX-015]**  An integer literal is a run of digits in one of three bases,
with an optional separator between digits.

```
integer_lit = decimal_lit | hex_lit | binary_lit .

decimal_lit = decimal_digit { [ "_" ] decimal_digit } .
hex_lit     = "0x" hex_digit { [ "_" ] hex_digit } .
binary_lit  = "0b" binary_digit { [ "_" ] binary_digit } .
```

⚠️ The base prefix and the hexadecimal digits are matched **without regard to
case**, as every other name in the language is [SRC-011]: `0XFF`, `0xff` and
`0xFF` are one literal.

    interpreter  compiler/Scanner.a24  ScanNumber
    unit         Scan Number
    unit         Scan Integer Is Not A Double
    conformance  0013-integer-literals.a24

**[LEX-016]**  There are three bases — decimal, hexadecimal `0x` and binary
`0b` — and a digit separator `_`. A separator **separates two digits** and
carries no other meaning: it may not lead, trail, or stand beside anything but a
digit.

| | |
| --- | --- |
| `1_000_000` | ✓ |
| `0xFF`, `0b1010` | ✓ |
| `1_0_0` | ✓ — silly, and not worth a rule to forbid |
| `_100` | an **identifier** [SRC-005], and cannot also be a literal |
| `100_` | refused: nothing to the right to separate |
| `1_.5`, `1._5`, `1e_5` | refused: the neighbour is not a digit |
| `0x_FF` | refused: the prefix is not a digit either |

⚠️ **There is no octal.** It is a PDP-11 artefact, and `0755` silently meaning
493 is a classic defect; C# omits it for the same reason. Three bases where two
are used is a name the reader must know for nothing.

⚠️ **A comma separator is impossible rather than merely awkward.**
`F (1,000,000)` is already a call with three arguments and `[1,000,000]` a list
of three elements — both valid, with a different meaning. No lookahead resolves
it, because both readings are complete. `_` is the only separator available to a
language with comma-separated arguments and collection literals.

⚠️ **`0x` and `0b` rather than Turbo Pascal's `$FF`.** `$` is unclaimed, and
`$FF` would sit consistently beside `#10`, which the language already has for a
code point. But Turbo Pascal has no binary form at all, so `$FF` beside `0b1010`
would mix two traditions in one sentence. The choice is for coherence with the
binary form, not for modernity.

⚠️ **A separator does not survive into the value**, so `1_000` and `1000` are
the same literal and print alike.

    interpreter  compiler/Scanner.a24  ScanNumber
    conformance  0006-integer-bases-and-separators.a24
    refusal      0151-a-separator-must-separate-digits.a24

**[LEX-017]**  Leading zeros are permitted and carry no meaning. `007` is the
integer 7, not an octal.

    interpreter  compiler/Scanner.a24  ScanNumber
    conformance  0013-integer-literals.a24

**[LEX-018]**  An Integer is **unbounded**. Arithmetic never overflows: a result
too large for the machine's width grows to hold it.

⚠️ **This is the whole of the type.** "An `Integer` is an integer" is a sentence
a reader needs nothing else to understand, where "an `Integer` is a signed
32-bit value, and an operation whose result falls outside that range raises"
asks them to carry a boundary. Removing the boundary removes a category of
error rather than diagnosing it.

⚠️ **Cheaper than it sounds, and the reason is worth stating.** The wide path
begins past 2⁶³ and almost nothing reaches it — `algc` cannot, since its own
scanner accumulates digits through this very arithmetic. What an ordinary
program pays is one predicted branch per operation, which is exactly what the
range check it replaced already cost.

⚠️ **It used to wrap silently**, so `2147483647 + 1` was `-2147483648`; then it
raised [was LEX-018 as first written]; now it grows. Each step removed a way for
a program to be surprised, and the last one removes the surprise itself.

⚠️ **One implementation, not two.** The interpreter's `+` *is* the runtime's —
`Exit Left + Right` in `VisitBinary` compiles to `alg_add` — so the two cannot
disagree, and this landed in `bootstrap/algol.c` alone.

⚠️ **Signed overflow in C is undefined behaviour, not a wrap**, which is a
different problem and was already avoided: the arithmetic goes through
`__builtin_*_overflow`. What changed is only what happens on the overflow they
report — the same branch that raised now promotes.

⚠️ **The switch that turned the check off is gone.**
`-DALG_NO_OVERFLOW_CHECK` skipped a range check and left the defined wrap that
preceded it: a build that did not conform but did compute something. The same
branch now decides whether to promote, so skipping it would not be a faster
conforming build — it would be wrong answers. A check that may be turned off and
a promotion that may not are one line of C and a different bargain.

⚠️ **Crossing into a machine width is a separate question**, and one place
answers it. A subscript, a `Buffer` offset, a code point and an exit status all
need a number C can hold, so each asks for one and gets a diagnostic naming the
value rather than a truncation.

    interpreter  compiler/Interpreter.a24  VisitBinary
    compiler     bootstrap/algol.c         alg_add
    conformance  0041-integers-grow.a24
    conformance  0136-integer-range.a24

**[LEX-019]**  There is no negative literal. A leading `-` is the unary
operator applied to a non-negative literal, which is why `2-1` is a
subtraction rather than two adjacent expressions.

    interpreter  compiler/Scanner.a24  ScanToken
    conformance  0013-integer-literals.a24

### 4.7 Double literals

**[LEX-020]**  A double literal requires at least one digit on **both** sides
of the point, or an exponent [LEX-022] in place of the point.

```
double_lit = decimal_lit "." decimal_lit [ exponent ] | decimal_lit exponent .
```

    interpreter  compiler/Scanner.a24  ScanNumber
    unit         Scan Number Decimal
    conformance  0014-double-literals.a24

**[LEX-021]**  `1.` is therefore not a double. It is the integer `1` followed
by the `.` operator, and a program containing it fails with `Expect property
name after '.'.` Likewise `.5` is not a literal at all.

    interpreter  compiler/Scanner.a24  ScanNumber
    unit         Scan Integer Then Dot
    refusal      0005-trailing-dot-is-not-a-double.a24

**[LEX-022]**  A literal may carry an exponent, and one that does is a Double
whether or not it has a point.

```
exponent = ( "e" | "E" ) [ "+" | "-" ] decimal_digit { [ "_" ] decimal_digit } .
```

`1e5` is `100000.0`, `1.5e-3` is `0.0015`, and `1E300` is a Double.

⚠️ **The exponent decides the type**, which is why `1e5` is a Double rather than
an Integer of the same value. A form written to say "this is a magnitude" should
not answer with the type that cannot express most magnitudes.

⚠️ **This closed a place where the language printed a form it could not read.**
`Str` renders a large Double in exponent notation — `1.0E300` — and that text
was not a literal. Nothing was unreachable, because `Val` parsed the exponent
form and `Val(Str(X))` round-tripped; but a value could not be written into a
program the way the program wrote it out.

⚠️ **The sign belongs to the exponent, not to the literal.** [LEX-019] still
holds: there is no negative literal, and `-1e5` is the unary operator applied to
one. The `-` inside `1e-5` is part of the exponent and is not that operator.

    interpreter  compiler/Scanner.a24  ScanNumber
    conformance  0007-exponent-notation.a24

### 4.8 Character literals

**[LEX-023]**  A quoted literal denoting exactly one character is a Char rather
than a String. `'a'`, `'é'` and `''''` are all Chars; `''` is the empty String
and `'ab'` a String of two.

⚠️ **The measurement is on the VALUE, not on the source span.** A doubled quote
`''''` is two characters of source and one character of value, and it is the
value that decides — because the doubling is *notation for a character*, and
notation must not change a type.

⚠️ **This was the other way round, and was wrong.** Measuring the span made the
same character carry two types depending on how it was spelled:

```
''''  is Char  →  false            #39  is Char  →  true
''''  =  #39   →  false            a character not equal to itself
Ord ('''')     →  Ord failed: ''' has no ordinal.
```

⚠️ **This was wrong twice over.** The implementation measured the span, and
measured it in *bytes* — so `''''` was a String and `'é'` a String of length 2.
One line decided both, which is why they were corrected together.

    interpreter  compiler/Scanner.a24  ScanString
    unit         Scan One Character Is A Char
    conformance  0128-text-is-characters.a24

**[LEX-024]**  A Char may also be written `#` followed by decimal digits, giving
the character with that code point: `#65` is `A`, `#10` is a line feed and
`#233` is `é`. A `#` not followed by a digit is an error reading `[line N]
Error: Invalid character: C`.

```
char_lit = "'" ( source_character_other_than_quote | "''" ) "'"
         | "#" decimal_digit { decimal_digit } .
```

⚠️ `char_lit` and `string_lit` are not distinguished by the grammar — both open
with a quote — and are not meant to be. [LEX-023] decides between them by
counting the characters the literal denotes.

    interpreter  compiler/Scanner.a24  ScanChar
    unit         Scan Char By Code Point
    unit         Scan Char Without Digits
    conformance  0015-char-literals.a24

**[LEX-025]**  A Char is a Unicode code point: 0 … 10FFFF, excluding the
surrogate range D800 … DFFF, which encodes no character. A `#` literal outside
that range is refused when the program is read, with the shape every other
scan error has — `[line N] Error: …` — because that is where it is detected.

⚠️ A Char is held as its **UTF-8 encoding** — a String of one character and
possibly several bytes — and `alg_char_value` is the single place that encodes
it, so the two processors agree by construction rather than by both being
restricted to what a byte can hold.

⚠️ **The diagnostic half is done.** It used to arrive as
`Uncaught: Char is limited to 0..127.` with no line and no caret, because
`ScanChar` built the value by calling the `Char` built-in, which raises. It is a
scan error and is now reported as one [ERR-004]. The range moves with DEF-01 —
widening a Char is the same change as a String of characters rather than bytes.

    interpreter  compiler/Scanner.a24  ScanChar
    compiler     bootstrap/algol.c     alg_char
    refusal      0038-char-out-of-range.a24

**[LEX-026]**  A Char and a String are never equal, however alike they look.
`'a' = 'a'` is true because both sides are Chars; `Copy('abc', 0, 1) = 'a'` is
**false**, because `Copy` yields a String of length one and the Char `'a'` is
not it.

    interpreter  compiler/Interpreter.a24  IsEqual
    compiler     bootstrap/algol.c         equals
    conformance  0015-char-literals.a24

### 4.9 String literals

**[LEX-027]**  A string literal is enclosed in single quotes. A quote within it
is written twice.

```
string_lit = "'" { source_character_other_than_quote | "''" } "'" .
```

    interpreter  compiler/Scanner.a24  ScanString
    unit         Scan String
    unit         Scan Doubled Quote
    conformance  0016-string-literals.a24

**[LEX-028]**  There are no backslash escapes. `'a\nb'` is four characters, and
its element at index 1 is the backslash itself. A line feed is written `#10` and
concatenated.

    interpreter  compiler/Scanner.a24  ScanString
    conformance  0016-string-literals.a24

**[LEX-029]**  `''` is the empty String — zero characters, and there is no
empty Char. `''''` is the **Char** holding a quote: one character of value,
however many of source [LEX-023].

⚠️ `''''` and `#39` are therefore the same value, and equal. They are two
spellings of one character.

⚠️ The scanner measures the literal's **value**, not its source span, and that
one line decides two things: `'é'` is a Char rather than a String of two bytes,
and a doubled quote counts once.

⚠️ **There is then no literal for a one-character String**, and that is not a
loss. `var S : String := 'c';` is already a type mismatch for every character
but the quote [LEX-023], so `''''` being writable was an accident of the
measurement rather than a way of writing anything. Once a Char widens to a
String at an assignment context [VAR-004], `var S : String := 'a';` is how one
is written, and it works for every character alike.

    interpreter  compiler/Scanner.a24  ScanString
    unit         Scan Empty String
    unit         Scan An Escaped Quote Is A Char
    conformance  0016-string-literals.a24
    conformance  0130-a-doubled-quote-is-a-char.a24

**[LEX-030]**  A string literal may span lines. The line feed is part of its
value and advances the line count, so `'one` ⏎ `two'` is seven characters.

    interpreter  compiler/Scanner.a24  ScanString
    conformance  0016-string-literals.a24

**[LEX-031]**  A string that reaches the end of the file unclosed is an error
reading `[line N] Error: Unterminated string.`, where N is the line the string
**opened** on.

⚠️ A quote closes the string before it. A file with several stray quotes
therefore reports the last *unpaired* one, which is the string that actually
runs to the end.

    interpreter  compiler/Scanner.a24  ScanString
    unit         Scan Unterminated String
    conformance  0110-unterminated-string-line.a24

**[LEX-032]**  `#0` is not a Char. A code point of 0 is refused exactly as an
out-of-range one is [LEX-025], when the program is read.

⚠️ **Only the LITERAL is refused.** [LEX-025] puts a Char at 0 … 10FFFF and the
built-in `Char(0)` stays legal — which it must, because the scanner's own
end-of-input sentinel is `Char(0)`, and a scanner that cannot name its sentinel
cannot scan.

⚠️ `Str(Char(0))` no longer truncates: a String carries its own length
[SRC-001], so `Length('a' + Str(Char(0)) + 'b')` is 3.

    interpreter  compiler/Scanner.a24  ScanChar
    compiler     bootstrap/algol.c     alg_char
    refusal      0037-nul-char-literal.a24
    conformance  0131-a-string-holds-a-zero-character.a24

> Refusing `#0` is the smaller of the two available fixes and matches the range
> check that already exists. The larger one — giving a String an explicit length
> so it can hold a zero character — is the better language, and [SRC-001] already
> obliges a String to carry a character count distinct from its byte length, so
> the two changes meet. This rule is written so that adopting the larger fix
> later relaxes a restriction rather than reversing a guarantee.

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
    conformance  0019-declaration-forms.a24

**[VAR-002]**  A variable declared without an initializer holds `nil`, whatever
its declared type. **There is no zero value**: an uninitialized `Integer` is
`nil`, not `0`.

    interpreter  compiler/Interpreter.a24  VisitVarStmt
    conformance  0022-no-zero-value.a24

**[VAR-003]**  A declared type constrains the initializer and every later
assignment. A violation is the error `Type mismatch!`

    interpreter  compiler/TypeChecker.a24  Assignable
    refusal      0008-declared-type-constrains.a24

**[VAR-004]**  A value **widens** to reach a written type, and is converted at
the point it arrives. There are two widening pairs:

| From | To | Example |
| --- | --- | --- |
| Integer | Double | `var X : Double := 1;` gives `X` the Double `1.0` |
| Char | String | `var S : String := 'a';` gives `S` a String of length 1 |

The variable holds the wider type afterwards. A declaration never misdescribes
what it holds.

⚠️ A plain assignment and a field reached this **last**, and `D := 1` used to
leave `D` holding an Integer — a declaration describing something the variable
did not hold.

    interpreter  compiler/TypeChecker.a24  Assignable
    conformance  0025-operators-widen.a24
    conformance  0140-widening-at-every-context.a24

**[VAR-017]**  Widening applies wherever a value meets a written type — the six
**assignment contexts**, and nowhere else:

```
var X : T := E ;          const X : T := E ;
X := E ;                  Obj.Field := E ;
Exit E ;   (against a declared return type)
F (E) ;    (against a declared parameter type)
```

⚠️ **The interpreter does not know a variable's declared type at run time**, and
this is how the last two contexts are reached anyway. `Env` stores values, not
types, so a plain `X := 1` has nothing to consult — a declaration knows its own
type, and a parameter and a return type are on the function. The **TypeChecker
writes the declared type onto the assignment node**, having already computed it
to check the assignment, and the interpreter widens with it. A field is the same
arrangement on `SetExpr`.

⚠️ A field written through `this` needs the receiver's type, and `this` is
**deliberately untyped** so that a class's own code escapes the private-member
check. The class name is taken for the widening lookup alone, after visibility
has had its untyped receiver — typing `this` outright breaks that rule, which
the checker's own tests catch.

⚠️ **Comparison is not among them and does not widen.** `'a'` and
`Copy('abc', 0, 1)` remain unequal [LEX-026]. A widening converts *toward a
target type*, and an `=` supplies none — it would have to invent one, and
"convert when the sides differ" is the rule that makes `=` unpredictable. See
D-6, which weighs the same question for membership.

    interpreter  compiler/TypeChecker.a24  Assignable
    interpreter  compiler/Interpreter.a24  VisitAssignExpr
    conformance  0140-widening-at-every-context.a24

**[VAR-018]**  Narrowing is refused in every one of those contexts.
`var X : Integer := 1.5;` is a mismatch: the value does not fit, and choosing
how to lose the fraction is not a decision a declaration should make silently.
`var C : Char := 'ab';` is refused for the same reason.

    interpreter  compiler/TypeChecker.a24  Assignable
    refusal      0014-no-implicit-narrowing.a24

**[VAR-005]**  `nil` satisfies every declared type, so `var X : Integer := nil;`
is accepted.

    interpreter  compiler/TypeChecker.a24  Assignable
    compiler     bootstrap/algol.c         alg_is
    conformance  0022-no-zero-value.a24

**[VAR-006]**  `Any` is the declared type meaning *not known*. A variable
declared `Any` accepts every value.

It does **not** flow the other way. A value whose type is `Any`, or whose type
could not be determined at all, does not satisfy a written type: neither
`var I : Integer := A;` nor a later `I := A;` is accepted where `A` is `Any`.
The conversion must be written, and `as` [VAL-007] is how to write it.

⚠️ **A type is not a suggestion once it is written.** Where a program declares a
type, every value reaching that variable either has the type already or is
converted by an expression that says so and checks it. This is what lets a
declared type be relied upon — by a reader, and by the C back end, which can
only generate a machine representation for a variable whose type it may trust.

⚠️ Writing no type remains entirely permissive. `var A := M.Get (1);` is
ordinary and unremarkable; the rule bites only where a type was written down.

⚠️ **An assignment is now as strict as a declaration**, and getting there was an
inference problem rather than a rule problem. The asymmetry existed because
refusing an untyped value at an assignment refused *correct code*, and the wrong
trade would have been to punish a program for the checker's blind spot.

Three blind spots had to close first, and each was found by tightening the check
and seeing what the compiler's own sources tripped on:

| Blind spot | Fix |
| --- | --- |
| a variable declared without a type did not carry its deduced type into an expression | `Reduce` consults `Inferred`, which became **scoped** for the purpose |
| a bare name inside a method that is a **field** — an implicit `this.Field` — had no type, since a field is registered under `Class::Field` | look it up as a field, walking the inheritance chain, after the scoped lookup so a local still shadows |
| a `Buffer` held in a variable declared `Any` gave `.Text` no type | declare the variable `Buffer`; the emitter's own four buffers were `Any` |

⚠️ **Five sites in the compiler genuinely could not be typed**, and each was
given the `as` this rule prescribes — a member of an untyped parameter, a
subscript of one. That is the rule working as intended rather than a concession
to it: the conversion is written where the checker cannot see the type.

⚠️ **Scoping `Inferred` was not optional.** While one helper read it a stale
entry could only lose checking; once an ordinary variable's type comes from it, a
leftover `String` from another function's `C` makes a correct program fail to
check — the one kind of wrong answer that is not harmless. `Generics` was made
scoped for exactly this reason and the pattern was copied.

    interpreter  compiler/TypeChecker.a24  Assignable
    conformance  0020-any-accepts-every-value.a24
    conformance  0141-inference-carries-a-type.a24
    refusal      0048-assignment-escapes-the-type.a24

**[VAR-007]**  A name may not be declared twice in one scope. The second is
refused with `'X' is already defined.`

⚠️ **Two subprograms of one name are not a duplicate** where their signatures
differ: they are overloads [FUN-013], selected between at the call. Two with the
*same* signature are a duplicate like any other name.

    interpreter  compiler/Resolver.a24  CheckDuplicates
    unit         Resolve Duplicate Variable
    refusal      0009-no-redeclaration.a24

**[VAR-008]**  A collection may carry an element type, written `of`:
`var L : List of Integer := [];`. Every collection type accepts one — `List`,
`Map`, `Set` and `Array`.

⚠️ For a `Map` the element type is the **value** type, since that is what a
subscript and a `Get` yield [VAR-016]. A Map's keys are not constrained.

⚠️ **Wherever a type may be written**, which is every context [TYP-002] names —
a variable, a constant, a field, a **parameter** and a **return type**. The last
two did not parse: `Items : List of Integer` was `Expect ')' after parameters.`
and a return type stopped at the collection's name. Annex A's grammar has
described both since it was written, and only the parser disagreed.

    interpreter  compiler/Parser.a24  IsCollectionType
    interpreter  compiler/Parser.a24  ParameterType
    conformance  0019-declaration-forms.a24
    conformance  0121-element-type-on-every-collection.a24
    conformance  0157-element-types-on-parameters.a24

**[VAR-016]**  An element type is a **source of types for reads, and no
constraint on writes.** Given `var L : List of Integer`:

| Expression | Type |
| --- | --- |
| `L[0]` | Integer |
| `X` in `for var X in L` | Integer |
| `L.Add (V)` | accepts any `V`; the element type is not checked |

⚠️ The asymmetry is deliberate rather than an oversight to be tidied away. The
reading half is what makes a declared element type worth writing — it is how a
loop variable acquires a type without one being written on it — and it costs
nothing at run time. Checking every insertion is a different and much larger
commitment; see Annex H.

    interpreter  compiler/TypeChecker.a24  Reduce
    conformance  0021-element-types-flow-to-reads.a24

### 5.2 Sections

**[VAR-009]**  In the header of a function, procedure, class or object, `var`
may open a **section**: a run of declarations, each ending in `;`, closed by the
next section marker or by `begin`.

```
VarSection = "var" { identifier { "," identifier } [ ":" Type ] [ ":=" Expression ] ";" } .
```

    interpreter  compiler/Parser.a24  DeclarationSection
    unit         Parse A Function Local Var Section
    conformance  0023-sections.a24

**[VAR-010]**  Within a section several names may share one declaration:
`A, B : Integer;` declares both.

    interpreter  compiler/Parser.a24  DeclarationSection
    unit         Parse A Comma Group Stays A Group
    unit         Parse A Single Name Is Not A Group
    conformance  0023-sections.a24

**[VAR-011]**  A section is a feature of a **header**, not of a program body. At
the top level `var` declares exactly one name, and a run of declarations
beneath it is read as ordinary statements — `var A : Integer;` followed by
`B : String;` is refused.

⚠️ **Labels changed how it is refused, and the diagnostic got worse.** `B :`
is now read as a **label** [STM-010] on the statement `String;`, so the line
parses and fails at run time with `Undefined variable 'String'.` rather than at
parse time with `Expect ';' after expression.` The rule is unchanged and the
program is still refused; what is lost is that it used to be caught without
being run, so a mistaken section on a path never taken is now silent. This is
the price of a label needing no keyword, and it is the only place in the
language where the two forms collide.

    interpreter  compiler/Parser.a24  ReadDeclarationSections
    refusal      0010-no-section-at-top-level.a24

### 5.3 Constants

**[VAR-012]**  A constant is introduced by `const` and **must** be given a
value. Omitting the initializer is refused with `A constant must be given a
value.`

```
ConstDecl = "const" identifier [ ":" Type ] ":=" Expression ";" .
```

    interpreter  compiler/Parser.a24  ConstDeclaration
    unit         Parse A Constant Must Be Given A Value
    refusal      0011-const-must-be-given-a-value.a24

**[VAR-013]**  A constant may not be assigned to. The attempt is refused with
`Can't assign to constant 'C'.`

    interpreter  compiler/Resolver.a24  VisitAssignExpr
    refusal      0012-const-is-not-assignable.a24

**[VAR-014]**  ⚠️ A constant's initializer is an **ordinary expression evaluated
at run time**, not a constant expression. `const C := 1 + 2;` is legal, and so
is `const C := V;` where `V` is a variable — the constant takes whatever value
`V` held at that moment.

`const` therefore means *this binding may not be reassigned*, not *this value is
known before the program runs*.

    interpreter  compiler/Interpreter.a24  VisitVarStmt
    conformance  0024-const-is-a-runtime-expression.a24

**[VAR-015]**  `const` may open a section on the same terms as `var`, and the
two may appear together in one header.

    interpreter  compiler/Parser.a24  DeclarationSection
    unit         Parse A Const Section
    unit         Parse Var And Const Sections Together
    conformance  0023-sections.a24

---

## 6. Types

### 6.1 The kinds of type

**[TYP-001]**  A value has exactly one of these runtime types:

| Kind | Types |
| --- | --- |
| Primitive | `Integer`, `Double`, `String`, `Char`, `Boolean` |
| Declared | a class type, an enumeration type |
| Collection | `List`, `Set`, `Stack`, `Array`, `Map` |
| Resource | `Buffer`, `TextFile` |
| Unknown | `Any` — a declaration only, never a runtime type |

    interpreter  compiler/ObjFunction.a24  TypeNameOf
    compiler     bootstrap/algol.c         alg_is
    conformance  0026-the-runtime-types.a24

**[TYP-015]**  `Byte`, `Word` and `Short` are **subranges** of `Integer`, not
types of their own. Each names a low and a high bound:

| | |
| --- | --- |
| `Byte` | 0 .. 255 |
| `Word` | 0 .. 65535 |
| `Short` | −32768 .. 32767 |

A value is never *a Byte* — [TYP-001] still answers `Integer` — so a subrange
name appears only where a type is **written**, and the bounds are checked where
the value arrives: the six assignment contexts of [VAR-017], and nowhere else.

⚠️ **One feature instead of several special cases.** With [LEX-018] making an
Integer unbounded, a width is no longer a representation to match — only a range
to name. `Byte` is `0 .. 255` and says so.

⚠️ **`Short` is 16 bits, and Turbo Pascal's was not.** TP's `ShortInt` was 8
bits and its `Integer` 16; the modern reading is the one a reader can state
without looking it up, which is the test this language applies.

⚠️ **There is no unsigned family.** Unsigned types exist to buy one more bit
inside a fixed width and to say "not negative". An unbounded Integer removes the
first reason, and `0 ..` states the second directly rather than encoding it in a
name. It also avoids C#'s corner where `long + ulong` has no type to answer
with.

⚠️ **Selection ignores the bounds** [FUN-013]. Two subprograms differing only in
a parameter's range claim the **same signature** and are a duplicate — which is
the argument that rule already makes about return types: a call could never tell
them apart. Consulting the bounds would send `Take (200)` and `Take (300)` to
different subprograms, and would let *adding* an overload steal calls from one
that was already there.

⚠️ **`X is Byte` is nonetheless a range test**, and that is not a contradiction.
The principle is that a program may **ask** about a value; the language may not
silently **dispatch** on one. `is` is the question written where the programmer
wrote it.

⚠️ **The check lives where widening does, and that is safe for a reason.**
Widening converts and refuses nothing — making it refuse on a *type* mismatch
broke the compiler twice (C-24, C-25), because a String reaching a field
declared `Expr` is a shape real programs use. A *range* check cannot fire on
that shape: it applies only when the declared name is a subrange and the value
is already an Integer.

    interpreter  compiler/Interpreter.a24  InSubrange
    compiler     bootstrap/algol.c         in_subrange
    conformance  0153-subranges.a24

**[TYP-016]**  A program declares a subrange of its own with `type`, giving a
low and a high bound.

```
SubrangeDecl = "type" identifier "=" bound ".." bound ";" .
bound = [ "-" ] integer_lit .
```

```
type Digit   = 0 .. 9;
type Celsius = -273 .. 1000;
```

It behaves exactly as a predefined one [TYP-015]: an Integer for every question
about type, its own name for the question about range.

⚠️ **The bounds are literals, not expressions.** A subrange is hoisted like a
class and an enumeration, so its bounds must be known before anything runs — and
an expression would have to be *evaluated*, which needs the declaration to have
run already. The restriction can be relaxed later by admitting constants, and
nothing in the rule prevents it.

⚠️ **The sign is read by the declaration**, because [LEX-019] still holds: there
is no negative literal, and `-273` is the unary operator applied to one. Where
an expression cannot be evaluated, the same rule is applied by hand.

⚠️ **An empty subrange is refused where it is read.** `type Empty = 9 .. 0;` is
`A subrange must not be empty: 9 is above 0.` — it admits no value at all, so
every assignment through it would fail and the declaration is the only place
that can say why.

⚠️ **`type` declares two different things**, and which is decided by the
character after the `=`: a `(` begins an enumeration [ENU-001], anything else a
subrange. Both bind a name that denotes a type and neither binds a value.

    interpreter  compiler/Parser.a24    SubrangeDeclaration
    interpreter  compiler/Resolver.a24  VisitSubrangeStmt
    conformance  0154-declared-subranges.a24

**[TYP-014]**  `Real` is another spelling of `Double`. It is not a second type:
`X is Real` and `X is Double` answer alike, a parameter declared either accepts
the same arguments, and two subprograms differing only in which was written
claim the same signature [FUN-013].

⚠️ **An alias, not a conversion.** C# settled this shape: `int` *is*
`System.Int32`, one type with two names and no box between them. Java's
`int`/`Integer` duality — two things with almost the same name behaving
differently — is the arrangement this avoids.

⚠️ **The canonical spelling is `Double`**, and a diagnostic uses it: `X as Real`
on a String is `Cannot cast String to Double.` The alias telling a reader what it
is, is worth more than echoing what they wrote.

⚠️ **Turbo Pascal's `Real` was a 6-byte software float** from before the 8087,
with no C type to map onto. A type whose only distinction is a 1985 storage
format is the opposite of self-explanatory, so the name survives and the
representation does not. Delphi reached the same conclusion.

⚠️ **There is no `Single`.** A 32-bit float earns its place in a language whose
values are unboxed, by halving the storage of an array; Algol-24's values are
tagged and one size, so it would cost a reader "32-bit IEEE, less precision"
and buy nothing.

⚠️ **Replaced where a written type becomes something to compare**, and nowhere
else, so no part of the implementation past the front end knows the alias
exists — the C runtime has no case for it at all. `is` is canonicalised at its
two use sites rather than at the parser, because it carries a token where the
others carry a string.

    interpreter  compiler/Token.a24  CanonicalType
    conformance  0152-real-is-double.a24

**[TYP-002]**  A type is written as an identifier. The only compound form is a
collection type with an element type, written `of` — `List of Integer`,
`Map of Token` [VAR-008].

```
Type = identifier [ "of" identifier ] .
```

    interpreter  compiler/Parser.a24  VarDeclaration
    conformance  0026-the-runtime-types.a24

**[TYP-003]**  `Char` and `String` are distinct types, and a one-character
value is a `Char`. `'s' is String` is **false**.

⚠️ **Widening does not change this.** A Char widens to a String on its way into
a written type [VAR-004], but `is` asks what a value *is*, not what it could
become, and a type test is not one of the six assignment contexts [VAR-017]. A
Char that has widened is a String and answers so; the Char it came from is not.

    interpreter  compiler/ObjFunction.a24  TypeNameOf
    conformance  0026-the-runtime-types.a24

### 6.2 Any

**[TYP-004]**  `Any` is the declared type meaning *the type is not known*. A
variable declared `Any` accepts every value; a value of type `Any` does not
satisfy a written type without a cast [VAR-006]. No value ever reports `Any` as
its runtime type, so `X is Any` is false for every `X` [VAL-005].

    interpreter  compiler/TypeChecker.a24  Assignable
    conformance  0020-any-accepts-every-value.a24
    refusal      0013-any-does-not-satisfy-a-written-type.a24

> The asymmetry is the point of [VAR-006]: `Any` is where a type is not known,
> and a written type is a claim that it is. Moving from the first to the second
> is a conversion, and `as` is how one is written.

### 6.3 nil

**[TYP-005]**  `nil` is of no type at all. `nil is T` is **false** for every `T`,
including the type `nil` was declared as.

    interpreter  compiler/Interpreter.a24  VisitIsExpr
    compiler     bootstrap/algol.c         alg_is
    conformance  0027-nil-has-no-type.a24

**[TYP-006]**  `nil` nonetheless satisfies every declared type for the purpose
of assignment — see [VAR-005]. A value that is not there has no type to check,
and is accepted everywhere.

    interpreter  compiler/TypeChecker.a24  Assignable
    conformance  0027-nil-has-no-type.a24

**[TYP-013]**  A type name must denote a declared type. A name that denotes
nothing is refused when the program is read, rather than being read as a type no
value has.

⚠️ The name used never to be resolved: `1 is Nonexistent` was `false`, silently,
so a misspelled type answered false and the branch it guarded never ran — while
an undefined *variable* in the same position has always been
`Undefined variable 'X'`.

⚠️ **`Any` stays legal**, though `X is Any` is always false [VAL-005]. It names
something; it just never matches.

⚠️ Checked **folded**, because `is` folds at run time — `SatisfiesType` lowers
both sides, so `1 is dog` finds `class Dog` and refusing it here would refuse a
program that runs.

⚠️ Writing that case down found a second fault: `InheritsFrom` compared class
names **exactly** while `SatisfiesType` folded its direct match, so
`Puppy() is Dog` was true and `Puppy() is dog` was false — one operator
disagreeing with itself about case, and the C runtime folding both. Fixed with
this rule.

    interpreter  compiler/TypeChecker.a24  DeclaredTypes
    refusal      0040-unknown-type-name.a24
    conformance  0135-type-names-that-denote.a24

> This is not a gradual-typing case. Gradual typing concerns a *value* whose
> type is not known, which is ordinary; a type *name* is written by the
> programmer and must denote something.

### 6.4 Collection types

**[TYP-007]**  The five collection types are distinguished by their kind, and
each answers `is` to its own name only. A `List` is not a `Set`.

    interpreter  compiler/ObjCollection.a24  Kind
    conformance  0028-collection-types-are-distinct.a24

**[TYP-008]**  `Array` is fixed in size. Its elements begin as `nil`, it is
indexed from zero, and an index outside its bounds is the runtime error
`Index N out of range 0..M.` It does not grow on assignment.

    interpreter  compiler/ObjCollection.a24  At
    compiler     bootstrap/algol.c           alg_subscript_set
    conformance  0029-array-is-fixed.a24

**[TYP-009]**  A collection is **not** a class instance. It has no `ClassName`,
and asking for one is the error `Undefined property 'ClassName'.`

    interpreter  compiler/ObjCollection.a24  Get
    conformance  0030-collections-have-no-classname.a24

### 6.5 What a class type cannot do

These rules are normative in their own right, and together they say which
built-in behaviour a program cannot reproduce for a type of its own. Annex E
takes up what it would cost to lift each one.

**[TYP-010]**  A class instance is subscriptable when its class declares `Get`
taking one argument: `B[0]` calls `B.Get (0)`. Assignment needs `Put` taking
two: `B[0] := X` calls `B.Put (0, X)`. Without them, `B[0]` is the runtime error
`Subscript target should be an ordinal.`

⚠️ **The fifth structural protocol**, beside `Contains`, `ToString` [CLS-009],
`Elements` [TYP-011] and `Compare` [VAL-014]. It needs no member name of its
own: `Get` and `Put` are what the built-in collections already answer to
[COL-003], so a collection written in Algol-24 reuses the names rather than
being given a second set.

⚠️ **A `property` is not one of them**, though it is often listed beside them.
A protocol is *structural* — a class either happens to declare the member or it
does not — while a property is announced with a keyword [CLS-017]. The
difference matters when counting: there are five protocols and one declared
member kind, not six of anything.

⚠️ **The two forms are two members of different arity**, which is the one
question subscripting adds that no other operator has — and the language already
tells arities apart everywhere else, so nothing has to pair a getter with a
setter syntactically. A class declaring only `Get` is readable and not
assignable, which needs no separate way of saying so.

⚠️ **It is not an operator declaration**, and that was the change of mind. This
was H-4, folded into operator overloading (H-8) as "the same feature in a
particular spelling"; it turned out to want no operator feature at all.

    interpreter  compiler/Interpreter.a24  VisitSubscriptExpr
    compiler     bootstrap/algol.c         alg_subscript_get
    conformance  0171-a-class-that-subscripts.a24
    conformance  0031-instance-is-not-subscriptable.a24

**[TYP-011]**  A class instance is iterable when its class declares an
`Elements` method **taking no arguments**; `for var X in B do` then walks what
that method returns. An instance whose class declares no such method is the
runtime error `Can only iterate a collection or a String.`

```
class Bag;
var Items : List;
begin
    constructor Init (); begin this.Items := [10, 20, 30]; end
    function Elements (); begin Exit Items; end
end

for var X in Bag () do Write (X);      // 102030
```

⚠️ **The protocol is STRUCTURAL, not declared.** There is nothing to inherit
from and nothing to announce: a class either has the method or it does not. `Str`
works the same way through `ToString` [CLS-009], and `in` through a `Contains`
taking one argument — three protocols, one convention.

⚠️ **A protocol is a name AND a shape.** `Elements` taking an argument does not
implement this one, and such a class is simply not iterable. Neither processor
checked that: the interpreter asked for the first method of the name whatever
its shape, the runtime's `has_method` fell back to the same, and the two then
failed differently — `Index 0 out of range 0..-1.` against
`No matching signature for function.`, neither of them the message above.

⚠️ **The result is walked, not re-asked.** `Elements` may return another
instance that also declares `Elements`, and the chain resolves — which is what
stops a `List` whose `Elements` returns a `List` from recursing forever.

⚠️ **It is snapshotted like any other walk** [STM-009]. The method answers a
whole collection, so the loop has its elements before the first pass runs; a
lazy protocol would be a different feature and would take that guarantee away.

    interpreter  compiler/Interpreter.a24  ElementsOf
    compiler     bootstrap/algol.c         alg_iterable
    conformance  0032-instance-is-not-iterable.a24
    conformance  0165-a-class-that-iterates.a24

**[TYP-012]**  A class exposes a **field** without parentheses and a **method**
with them: a method named `Length` read as `B.Length` yields the function
itself, printing `<fn Length>`, where a collection's `Length` yields its count.

A class may also declare a **property**: a member read without parentheses,
whose read *is* the call [CLS-017].

⚠️ **The three are distinguished by their declarations, not by the call site.**
A field is a name in a `var` section, a method is `function` or `procedure`, and
a property is `property`. Nothing at a use site says which — `B.Count` looks the
same whichever it is — which is why the runtime decides, and why the emitter is
told at the declaration rather than working it out at the call.

⚠️ **A BUILT-IN member reads the same way.** `L.Sort` yields something callable
and prints `<fn Sort>`, because it is the same kind of thing as a bound method.
The spelling is the one the program wrote — a built-in member has no declaration
to take a canonical one from, where a method prints the name its declaration
used.

    interpreter  compiler/ObjInstance.a24  Get
    conformance  0033-no-computed-property.a24
    conformance  0149-a-built-in-member-as-a-value.a24

---

## 7. Properties of types and values

### 7.1 Assignability

**[VAL-001]**  A value is assignable to a declaration when its type is the
declared type, when the **declaration** is `Any`, when the value is `nil`, when
its class inherits from the declared class, or when it widens to the declared
type [VAR-004].

⚠️ A value *of* type `Any` is not assignable to a written type; only the reverse
holds [VAR-006].

    interpreter  compiler/TypeChecker.a24  Assignable
    conformance  0034-assignability.a24
    conformance  0140-widening-at-every-context.a24

**[VAL-002]**  Nothing else converts. The widenings are exactly the two of
[VAR-004] — Integer to Double and Char to String — and they apply only at the
assignment contexts of [VAR-017]. There is no narrowing, no conversion between a
number and a String, and no user-defined conversion.

    interpreter  compiler/TypeChecker.a24  Assignable
    conformance  0034-assignability.a24
    refusal      0014-no-implicit-narrowing.a24

### 7.2 Type tests

**[VAL-003]**  `X is T` is true when the runtime type of `X` is `T`, or is a
class inheriting from `T`. Inheritance is followed upward only: a `Dog` is an
`Animal`, and an `Animal` is not a `Dog`.

    interpreter  compiler/Interpreter.a24  VisitIsExpr
    compiler     bootstrap/algol.c         alg_is
    conformance  0035-type-tests.a24

**[VAL-004]**  `nil is T` is **false** for every `T`. A value that is not there
has no type to test.

    interpreter  compiler/Interpreter.a24  VisitIsExpr
    compiler     bootstrap/algol.c         alg_is
    conformance  0035-type-tests.a24

**[VAL-005]**  `X is Any` is **false** for every `X`. `Any` is a declaration,
never a runtime type.

⚠️ `Any` is nonetheless a legal type name in `is` [TYP-013]. It denotes
something; it just never matches.

    interpreter  compiler/Interpreter.a24  VisitIsExpr
    conformance  0035-type-tests.a24

**[VAL-006]**  The type name in `is` is matched case-insensitively, so
`1 is integer` is true. This is [SRC-011] applied to a type name and is not a
special case.

    interpreter  compiler/Interpreter.a24  VisitIsExpr
    conformance  0035-type-tests.a24

### 7.3 Casts

**[VAL-007]**  `X as T` is a **checked conversion**. It tells the checker that
the expression has type `T`, and verifies the claim when the program runs: if
`X` is not a `T`, the cast raises.

`nil` satisfies every type [VAR-005] and therefore passes every cast.

⚠️ `as` is the one construct that moves a value from untyped into typed
[VAR-006], so it carries the whole weight of that boundary. A cast that could
not fail would make the boundary a formality, and every declared type downstream
of it a claim nothing had checked.

A cast that does not hold raises `Cannot cast String to Integer.`

⚠️ The test is the one `is` uses [VAL-003] — the value's own type, or a class it
inherits from — and deliberately the same code, so `X as T` and `X is T` cannot
come to disagree about what `T` means.

    interpreter  compiler/Interpreter.a24  SatisfiesType
    conformance  0117-as-is-checked.a24

### 7.4 Truthiness

**[VAL-008]**  A value is **falsey** if it is `nil`, `False`, the Integer `0`, or
an enumeration member whose ordinal is `0`. Every other value is **truthy**.

⚠️ In particular these are all truthy: `0.0`, the empty String `''`, the empty
List `[]`, the empty Map `[:]`, and every `Char`.

⚠️ Truthiness is **independent of a value's contents**. A collection is a thing,
and a thing is there; `if not S then` therefore does not test emptiness, and
`if S.Length = 0 then` is the only spelling that does.

    interpreter  compiler/Interpreter.a24  IsTruthy
    compiler     bootstrap/algol.c         alg_truthy
    unit         Execute Logical Truthy
    unit         Evaluate Unary Bang Nil
    conformance  0036-truthiness.a24

> D-8 observes that Integer `0` is the odd one out, and that were it truthy the
> rule would reduce to "only `nil` and `False` are false". That is a change to
> what existing programs mean and is not scheduled; the rule as written is the
> decided one.

### 7.5 Equality

**[VAL-009]**  `=` and `<>` promote numerically. `1 = 1.0` is true, and so is
`0 = 0.0`.

    interpreter  compiler/Interpreter.a24  IsEqual
    compiler     bootstrap/algol.c         equals
    unit         Evaluate Binary Equal Equal
    conformance  0037-equality.a24

**[VAL-010]**  A `Char` is never equal to a `String` — see [LEX-026]. `'a'` and
`Copy('abc', 0, 1)` are not equal.

⚠️ **Widening does not reach equality**, and the asymmetry with [VAL-009] is
deliberate. A numeric promotion has one obvious target — the wider of the two
types — and converting toward it loses nothing. `Char` against `String` has no
target at all: it is a change of representation rather than a widening of value,
and picking a direction would mean `=` converting its operands differently
depending on which side they arrived on.

⚠️ The rule bites less often than it appears to. `'a' = 'a'` is already true,
because both sides are Chars; it is only reached when one side came from `Copy`,
`Str` or a subscript. The complaint worth acting on is how easily a
one-character String is produced by accident, not how `=` treats one.

    interpreter  compiler/Interpreter.a24  IsEqual
    conformance  0037-equality.a24

**[VAL-011]**  Class instances, collections and enumeration members compare by
**identity**, not by contents. `[1, 2] = [1, 2]` is **false**: they are two
collections. Two references to one collection are equal.

⚠️ **There is still no way for a class to say otherwise, and it is now a
choice rather than an absence.** A program may define `+`, `-`, `*`, `/` and
`div` [EXP-020]; `=` is deliberately not on that list. Equality is coupled to
membership by [VAL-013] — *if `X = Y` then a collection holding `Y` contains
`X`* — and an object key hashes by its address, so defining `=` without a hash
protocol to move with it would break a stated rule silently. That pairing is
what Java's `equals`/`hashCode` discipline exists for, and it is the whole of
what Annex H, H-17 has to settle.

⚠️ **Ordering is different, and landed in Generation 7** [VAL-014]. A class
declaring `Compare` orders with `<` and its three companions, because ordering
touches no hash and no membership — which is exactly why it was settled while
equality was not.

    interpreter  compiler/Interpreter.a24  IsEqual
    compiler     bootstrap/algol.c         equals
    conformance  0037-equality.a24

**[VAL-012]**  `nil = nil` is true.

    interpreter  compiler/Interpreter.a24  IsEqual
    unit         Evaluate Binary Bang Equal Nil
    conformance  0037-equality.a24

### 7.6 Membership

**[VAL-013]**  `in`, `Contains` and Map key lookup use the equality of
[VAL-009]. Membership and equality are one relation: if `X = Y` then a
collection holding `Y` contains `X`. `1 in [1.0]` is **true**, and a Map holding
the key `1` contains the key `1.0`.

⚠️ **The hash is what pays for it**, not the comparison. A Map and a Set bucket
by a hash, so an Integer and a Double of one value must reach the same slot or
`Contains` answers false for a key the Map holds. Every `int32` converts to a
`double` exactly, so both hash *as* a double and no range test can get it wrong.

⚠️ **`-0.0`, `0.0` and `0` are one key.** They were three while the comparison
was a `memcmp`, and the runtime said so in a comment this rule made stale.

⚠️ **NaN is the one departure, and this rule permits it.** The rule is an
*implication*: a pair that is not equal is unconstrained by it, and `NaN = NaN`
is false. All NaNs are one **key**, because a Map that cannot find a key it
holds is broken in a way no rule asks for.

⚠️ One implementation, not two: `ObjCollection` delegates to the host's own
`Contains`, so the interpreter's membership *is* the runtime's and the two
cannot disagree.

    interpreter  compiler/ObjCollection.a24  Invoke
    compiler     bootstrap/algol.c           strict_equals
    conformance  0127-membership-follows-equality.a24

> Each half was defensible alone, which is how they came to disagree: `=`
> promotes because arithmetic does, and membership is strict because a hash
> table cannot be built over a relation that promotes. The second reason is a
> statement about the implementation, not about the language, and it is the one
> that gives way — see D-6 for the cost.

### 7.7 Ordering

**[VAL-014]**  `<`, `<=`, `>` and `>=` apply to numbers and to **text**. Text
is ordered **lexicographically by code point**, and a prefix sorts before what
extends it: `'ab' < 'abc'`. Anything else is `Operands must be numbers.`

⚠️ **A `Char` and a `String` compare as text.** `'a' < 'ab'` is true, and the
one-character String `Str ('a')` orders identically to the Char `'a'` — the two
are still never *equal* [VAL-009], but they sit in one order.

⚠️ **Code points, not bytes.** UTF-8 was designed so that byte order and
code-point order agree, so an implementation comparing bytes is right by
accident; this one is written in terms of code points so that it is right on
purpose, and so that it cannot disagree with `Ord`.

⚠️ **Char ordering was by the FIRST BYTE and is now by the code point**, which
this rule never said either way. `'è'` and `'é'` are `C3 A8` and `C3 A9`, share
a lead byte, and compared **equal** — while `Ord` answered 232 and 233, so the
language disagreed with itself about which came first. Fixed with this rule.

A **class instance** orders when its class declares `Compare (Other) : Integer`,
answering negative, zero or positive. Without one, `A < B` on two instances is
`Operands must be numbers.`

⚠️ **The fourth structural protocol**, beside `Contains`, `ToString` [CLS-009]
and `Elements` [TYP-011]; subscripting [TYP-010] is the fifth. A name and a
shape: `Compare` taking one argument. There is no declaration keyword and no
precedence question, because `<` already has a precedence [EXP-001].

⚠️ **Ordering costs nothing that equality would.** It touches no hash and no
membership, so unlike [VAL-013]'s coupling of `=` with `in` there is no second
protocol that must move with it. That is why this is settled and equality is
not — see Annex H, H-17.

⚠️ **`Sort` does NOT ask `Compare`** [COL-013], and the asymmetry is forced
rather than chosen. The interpreter delegates `Sort` to the host's, and the
values it passes are `ObjInstance` — the *compiler's* class, not the program's —
so the host would look for `Compare` there and never find it. Answering compiled
and refusing interpreted is the divergence the corpus exists to catch, so
neither does it. Sorting by `Compare` wants an interpreter inside
`ObjCollection` and is a piece of work of its own.

⚠️ **`Sort` uses this ordering for TEXT** [COL-013], rather than a second one
that happens to agree. It compared with `strcmp`, which stops at an embedded
zero a String is entitled to hold and which orders bytes rather than
characters.

    interpreter  compiler/Interpreter.a24  VisitBinary
    compiler     bootstrap/algol.c         text_order
    compiler     bootstrap/algol.c         method_order
    unit         Evaluate Binary Greater Left Not Number
    conformance  0166-text-is-ordered.a24
    conformance  0170-a-class-that-orders.a24

> Ordering text used to mean comparing it character by character, which is what
> `compiler/CEmitter.a24`'s `TextLess` did — a function the compiler wrote for
> itself because the language provided no operator. It is gone.

---

## 8. Declarations and scope

### 8.1 Blocks

**[DCL-001]**  A block is `begin` … `end` and introduces a scope. A name
declared inside it is not visible after it: reading one is `Undefined variable
'X'.`

    interpreter  compiler/Resolver.a24  BeginScope
    conformance  0039-blocks-and-scope.a24

**[DCL-002]**  A block sees every name of the scopes enclosing it.

    interpreter  compiler/Resolver.a24  ResolveLocal
    unit         Resolve One Hop
    unit         Resolve Two Hops
    conformance  0039-blocks-and-scope.a24

### 8.2 Shadowing

**[DCL-003]**  A declaration shadows an outer one of the same name for the rest
of its scope. The outer binding is untouched and reappears when the scope ends.

    interpreter  compiler/Resolver.a24  Declare
    unit         Resolve Same Level
    conformance  0040-shadowing.a24

**[DCL-004]**  A `var` may shadow a `const`. The inner name is an ordinary
variable and may be assigned; the outer constant is unaffected.

    interpreter  compiler/Resolver.a24  DeclareBinding
    conformance  0040-shadowing.a24

### 8.3 Declaration and use

**[DCL-005]**  A local may not be read in its own initializer. `var X := X;`
inside a block is refused with `Can't read local variable in its own
initializer.`, even where an outer `X` exists.

    interpreter  compiler/Resolver.a24  ResolveLocal
    unit         Resolve Local Variable Is Own Initializer
    refusal      0015-own-initializer.a24

**[DCL-006]**  A **function or class** declared at the top level of a file is
visible throughout that file, wherever it is written. A call may precede the
declaration, so a program may be organized from the top down.

⚠️ **A class is declared in two phases**, which is what C gets from a header:
every top-level class name is bound to an empty class before anything runs, and
each is *filled in* — the same object, never replaced — when its declaration is
reached. A subclass written above its parent therefore ends up holding the
finished parent.

⚠️ **Binding the name is not enough**, and it looks as though it were. With only
the name bound, `var D := Dog ();` above the declaration built from an *empty*
class: an object that answered `D is Dog` and had none of Dog's methods. A
silent wrong answer, and worse than the `Undefined variable` it replaced. The
class is built during the hoist, not merely named.

⚠️ **A class inheriting from something that is not a top-level class *of this
file* is left where it stands**, and that is what keeps [CLS-014] reachable: at
hoist time a `var` has no value yet, so evaluating it would say `Undefined
variable` in place of `'X' is not a class.`

⚠️ **A parent from a module is one of those**, which is where the limit of
hoisting shows: a module runs at its `uses` [INI-003], so a class inheriting
across a module boundary is built where its declaration stands and the import
has to come first. Written above the `uses`, it is `Undefined variable 'Shape'.`
— a fact about when the name is bound, not about inheritance.

⚠️ Hoisting made an inheritance **cycle** reachable for the first time — a class
could not previously be declared above its parent at all — so [CLS-013]'s check
grew from a self-reference to a cycle.

    interpreter  compiler/Interpreter.a24  Hoist
    conformance  0122-functions-are-hoisted.a24
    conformance  0146-inherit-across-a-module.a24
    conformance  0147-inherit-before-the-import.a24
    refusal      0046-inherit-from-a-non-class.a24

**[DCL-016]**  A **variable or constant** is not visible before its declaration
has run. Its initializer is an expression evaluated in order [VAR-014], and a
name read before that has no value to give — so it is an error, not `nil`.

⚠️ The split is deliberate. A function or class declaration is complete as soon
as it is read and has nothing to execute; a `var` has an initializer whose
effects belong at the point it is written. Hoisting the first is what lets a
file be read top-down; hoisting the second would silently substitute `nil` for a
value that does not exist yet.

    interpreter  compiler/Interpreter.a24  VisitVarStmt
    conformance  0044-variables-are-not-hoisted.a24
    refusal      0033-a-variable-is-not-hoisted.a24

**[DCL-007]**  A free name in a function body is resolved **when the body runs**,
not where it is written. Two functions may therefore call each other, provided
neither is called before both declarations have run.

    interpreter  compiler/Interpreter.a24  LookupVariable
    conformance  0041-mutual-recursion.a24

> This is why mutual recursion works even under the current implementation,
> where [DCL-006] does not: the *call* inside a body is resolved late, so only a
> call at the top level, above the declaration, meets the missing binding.

### 8.4 Loop variables

**[DCL-008]**  A variable declared in a `for` header belongs to the loop, in
both forms, and is not visible after it ends.

For the counted form this follows from [DCL-001] rather than being a rule of its
own: `for` **desugars into a block** holding the initializer and a `while`, so
the variable is scoped because it is inside a block.

    interpreter  compiler/Parser.a24    ForStatement
    interpreter  compiler/Resolver.a24  VisitForInStmt
    unit         Parse For Statement
    conformance  0039-blocks-and-scope.a24

### 8.5 this and super

**[DCL-009]**  `this` outside a class is refused with `Can't use 'this' outside a
class.`

    interpreter  compiler/Resolver.a24  VisitThisExpr
    unit         This Is Never Caught
    refusal      0016-this-outside-a-class.a24

**[DCL-010]**  `super` outside a class is refused with `Can't use 'super'
outside a class.`, and inside a class having no superclass with `Can't use
'super' in a class with no superclass.`

    interpreter  compiler/Resolver.a24  VisitSuperExpr
    refusal      0017-super-outside-a-class.a24
    refusal      0018-super-with-no-superclass.a24

### 8.6 Visibility

**[DCL-011]**  `private:` and `public:` are section markers within a class or
object, each governing the members that follow it. A member declared under no
marker is public.

    interpreter  compiler/Parser.a24  ReadDeclarationSections
    unit         A Public Member Is Reachable From Outside
    unit         A Private Field Is Not Readable From Outside
    conformance  0042-visibility.a24
    refusal      0019-private-through-a-typed-receiver.a24

**[DCL-012]**  The body starts public however the header ended. A `private:` in
the header does not carry across `begin`.

    interpreter  compiler/Parser.a24  ReadDeclarationSections
    unit         The Body Starts Public However The Header Ended
    conformance  0042-visibility.a24

**[DCL-013]**  Privacy belongs to the **class**, not to the object. A method may
reach the private members of another instance of its own class.

    interpreter  compiler/TypeChecker.a24  CheckVisibility
    unit         Another Instance Of The Same Class Reaches Its Privates
    conformance  0042-visibility.a24

**[DCL-014]**  A subclass does not reach what its parent hid. Reading a parent's
private member through a receiver declared as the parent is refused with
`'N' is private to P.`

    interpreter  compiler/TypeChecker.a24  CheckVisibility
    unit         A Subclass Does Not Reach What Its Parent Hid
    refusal      0020-subclass-does-not-reach-what-a-parent-hid.a24

**[DCL-015]**  ⚠️ **`private:` is advisory.** It is checked **statically, and
only where the receiver's type is known**. Reached through a receiver declared
`Any`, or through a bare name inside a method — which resolves through `this`,
and `this` has no type — a private member is readable and writable from
anywhere.

```
var C : Any := Counter ();
WriteLn (C.Count);        // the private field, read
C.Count := 99;            // and written
```

This is normative: `private:` states an intention and buys a diagnostic wherever
types are written down. It is **not** a boundary, and a program must not rely on
it as one. Both processors agree, so it is a property of the language rather
than of one implementation.

⚠️ **The guarantee is therefore strongest exactly where it is least needed** —
in well-annotated code — and absent from the code most likely to be reaching
somewhere it should not. That is an honest description of a checker in a
gradually typed language, not an accident, and D-9 records what enforcing it
would cost.

⚠️ `as` becoming a checked conversion [VAL-007] does not close this. Member
access is not one of the assignment contexts [VAR-017], so nothing obliges a
receiver to be narrowed before it is read through.

    interpreter  compiler/TypeChecker.a24  CheckVisibility
    unit         A Private Member Is Caught Through A Declared Receiver
    conformance  0043-visibility-is-advisory.a24

---

## 9. Expressions

### 9.1 Precedence and associativity

**[EXP-001]**  Operators bind in this order, tightest first:

| | Operators |
| --- | --- |
| 1 | `f(…)` call · `a[i]` subscript · `a.b` property |
| 2 | `-` unary · `not` · `as` |
| 3 | `*` · `/` |
| 4 | `+` · `-` |
| 5 | `<` · `<=` · `>` · `>=` · `in` · `is` |
| 6 | `=` · `<>` |
| 7 | `and` |
| 8 | `or` |
| 9 | `:=` |

    interpreter  compiler/Parser.a24  Expression
    unit         Parse Term Plus
    unit         Parse Factor Star
    conformance  0045-precedence.a24

> `1 + 2 * 3` is 7, `-2 * 3` is -6, `not True and False` is false,
> `True or False and False` is true, and `False = False and False` is false.
> Each distinguishes its pair. Verified.

**[EXP-002]**  Binary operators of one level are left-associative:
`10 - 2 - 3` is 5 and `12 / 2 / 3` is 2.

    interpreter  compiler/Parser.a24  Term
    conformance  0045-precedence.a24

**[EXP-003]**  `as` binds **tightly**, at the level of unary `-` and `not`. It
applies to the operand beside it and to nothing further: `A and B as C` is
`A and (B as C)`, and `A as Integer > 3` is `(A as Integer) > 3`.

⚠️ The binding stopped being cosmetic when `as` became a checked conversion
[VAL-007]. Under the old reading `False and 5 as Integer` was
`(False and 5) as Integer` — a Boolean cast to Integer, which raises. It is now
`False and (5 as Integer)`, which is `False`.

    interpreter  compiler/Parser.a24  Unary
    conformance  0118-as-binds-tightly.a24

### 9.2 Arithmetic

**[EXP-004]**  Integer arithmetic yields an Integer, **including `/`**, which
divides and truncates toward zero: `7 / 2` is 3 and `-7 / 2` is -3.

    interpreter  compiler/Interpreter.a24  VisitBinary
    compiler     bootstrap/algol.c         alg_divide
    unit         Evaluate Binary Slash
    conformance  0046-arithmetic.a24

**[EXP-005]**  A Double on either side promotes the operation and the result:
`7.0 / 2` and `7 / 2.0` are both 3.5, and `1 + 2.0` is `3.0`.

    interpreter  compiler/Interpreter.a24  VisitBinary
    unit         Evaluate Binary Plus Mixed
    conformance  0046-arithmetic.a24

**[EXP-006]**  ⚠️ Integer division by zero is the runtime error `Division by
zero.` **Double division by zero is not an error**: it yields `Infinity`,
`-Infinity` or `NaN`, and the program continues.

⚠️ Whether dividing by zero is a fault or a value therefore depends on which
type reached the operator, and [EXP-005] promotes an Integer whenever it meets a
Double — so an edit far from the division can move it from one category to the
other. This is specified rather than merely tolerated: each behaviour is right
for its own type. IEEE 754 defines the Double case and there is no integer
infinity to return for the other.

    interpreter  compiler/Interpreter.a24  VisitBinary
    compiler     bootstrap/algol.c         alg_divide
    conformance  0047-division-by-zero.a24

**[EXP-007]**  Integer arithmetic never overflows: a result too large for the
machine's width grows to hold it [LEX-018].

⚠️ **A Double does not**, and the asymmetry is deliberate. A Double follows IEEE
754, so `1.0 / 0` is `Infinity` [EXP-006] rather than an error and precision is
lost silently past 2⁵³. An Integer is exact and unbounded; a Double is
approximate and bounded, and a program choosing between them is choosing
between those.

⚠️ **A mixed expression is Double arithmetic** [EXP-005], so
`2147483647 + 1.0` is `2.147483648E9` — the Integer promotes to a Double and the
exactness goes with it.

    compiler     bootstrap/algol.c  alg_add
    conformance  0041-integers-grow.a24
    conformance  0136-integer-range.a24

**[EXP-018]**  `A div B` is integer division, said deliberately. It truncates
toward zero as `/` does on two Integers, and **refuses** anything that is not an
Integer.

⚠️ **It says which division was meant.** `/` is integer division on two Integers
and real division as soon as a Double reaches it [EXP-004], [EXP-005] — so
`X / Y` cannot be read where `X` is declared `Any`, and an edit far from the
division can change which operation it is. `div` always truncates.

⚠️ **`/` is unchanged**, deliberately. Making it always real would be more
predictable, and is a migration through every division in the tree — `algc`'s
own included. `div` gives the programmer the option of saying plainly which was
meant, and breaks nothing.

⚠️ **Refusing a Double rather than truncating it** is the bargain `Mod` already
makes. A programmer writing `div` has said the operands are Integers; if they
are not, that is a mistake worth reporting rather than a conversion worth
performing silently.

⚠️ It binds as `*` and `/` do — a different operation, not a different
precedence, so `A + B div C` groups the way `A + B / C` does.

    interpreter  compiler/Interpreter.a24  IntegerDivide
    compiler     bootstrap/algol.c         alg_div_int
    conformance  0155-integer-division.a24

**[EXP-008]**  `+` concatenates when **either** operand is text, converting the
other. `'ab' + 1` is `ab1`, `1 + 'ab'` is `1ab`, and `'a' + 'b'` — two Chars — is
the String `ab`.

A **`Char` mixed with a number** is refused: `'a' + 1` is `A Char and a number
cannot be added; use Succ or Str.` So is `'a' - 1`, with `use Pred.`

⚠️ **A Char is an ordinal, so the mixed form reads two ways** — step the
character, or join it to the text `1` — and rather than pick one silently the
language makes the program say which: `Succ ('a')` [RT-020] for the step,
`Str ('a') + 1` for the join.

⚠️ **It used to concatenate, and that quietly widened the Char.** `Str` is how a
Char becomes a String, which is why `Line ('{')` must be declared `Any`
[LEX-026] — yet `'a' + 1` and `Str ('a') + 1` both gave `a1`, so in this one
place the widening happened without being asked for and `Str` was decorative.
[VAR-004] specifies widening **to reach a written type**, at a declaration; `+`
in an expression was never that rule being applied.

⚠️ **A String mixed with a number still concatenates.** A String is not an
ordinal, so `'ab' + 1` has only one reading and nothing to disambiguate.

    interpreter  compiler/Interpreter.a24  VisitBinary
    compiler     bootstrap/algol.c         alg_add
    unit         Evaluate Binary Plus String
    conformance  0025-operators-widen.a24
    conformance  0167-character-arithmetic.a24

**[EXP-019]**  `-` on **two Chars** answers the Integer distance between their
code points: `'z' - 'a'` is 25.

⚠️ **The only arithmetic a Char takes**, and it is the one that cannot be read
two ways: subtracting two ordinals is a distance and nothing else. Stepping is
`Succ` and `Pred` [RT-020], joining is `Str` and `+` [EXP-008].

⚠️ **Turbo Pascal has neither**, and this is a deliberate departure from it. TP
answers a distance with `Ord (X) - Ord (Y)`, which stays available and says the
same thing at greater length.

    interpreter  compiler/Interpreter.a24  VisitBinary
    compiler     bootstrap/algol.c         alg_subtract
    conformance  0167-character-arithmetic.a24

**[EXP-020]**  A class may define `+`, `-`, `*`, `/` and `div` for its own
instances, and unary `-`. The member is named for the operator, and takes one
argument — or **none**, which is what makes it the unary form.

```
class Money;
var Cents : Integer;
begin
    constructor Init (C : Integer); begin this.Cents := C; end

    operator + (Other : Money) : Money; begin Exit Money (Cents + Other.Cents); end
    operator * (N : Integer)   : Money; begin Exit Money (Cents * N); end
    operator - ()              : Money; begin Exit Money (-Cents); end
end
```

⚠️ **A closed list, and it has to be.** A new operator would need a precedence
and an associativity, and [EXP-001] is a fixed table of seven levels with
nowhere to put one. These five already have a place in it. `operator =` is
refused with `An operator must be one of + - * / div.`

⚠️ **The LEFT operand decides**, as a receiver does everywhere else in this
language: `Money * 3` is a Money and `3 * Money` is `Operands must be numbers.`
An operator is a member, and a member is reached through the value on its left.

⚠️ **Unary and binary are told apart by ARITY**, as the two forms of subscript
are [TYP-010]. `operator - (Other)` is subtraction and `operator - ()` is
negation; the language tells arities apart everywhere, so neither form needs a
word of its own.

⚠️ **This is the one place a keyword was chosen over a protocol**, after six
protocols in a row. `Compare` [VAL-014], `Get` and `Put` are not *translations*
of operators — `Compare` yields four of them, `Get` and `Put` are two halves of
one — while a `Plus` method would be a pure synonym for `+`, a name added
without a concept. Where the name says something the symbol does not, the
protocol wins; here it would not.

⚠️ **`not` and `:=` are not on the list.** `not` tests truthiness, which
[VAL-008] defines for every value, so a type overloading it lies about a
language-wide property rather than defining its own behaviour. `:=` is outside
the mechanism entirely: dispatch is on values [FUN-013], and the left of an
assignment is a location.

⚠️ **`Mod` is a function and `div` is an operator** [RT-011], so a class may
define `div` and never `mod`. The asymmetry predates this rule.

    interpreter  compiler/Parser.a24  ParseOperator
    compiler     bootstrap/algol.c    apply_operator
    conformance  0172-a-class-that-computes.a24
    refusal      0172-an-operator-not-on-the-list.a24

### 9.4 Logical operators

**[EXP-009]**  `and` and `or` **short-circuit**. The right operand is evaluated
only when the left does not decide the result.

    interpreter  compiler/Interpreter.a24  VisitLogical
    unit         Execute Logical And
    unit         Execute Logical Or
    conformance  0048-logical-operators.a24

**[EXP-010]**  Both operators test truthiness [VAL-008] rather than requiring a
Boolean.

    interpreter  compiler/Interpreter.a24  IsTruthy
    unit         Execute Logical Truthy
    conformance  0048-logical-operators.a24

### 9.5 Calls

**[EXP-011]**  A call checks arity. A mismatch is `Expected N arguments but got
M.`

⚠️ **Except where a count is not the callee's rule.** A subprogram whose last
parameter gathers trailing arguments [FUN-005] has a different count by design,
and reports `No matching signature for function.` instead — naming the count
would send the reader to look at the wrong thing, since what refused the call
was the element type. `Write` and `WriteLn` take any number of values [RT-001]
and so can never fail this way at all.

    interpreter  compiler/Interpreter.a24  VisitCall
    unit         Call Wrong Number Of Arguments
    conformance  0049-call-failures.a24
    conformance  0145-a-builtin-with-the-wrong-arity.a24

**[EXP-012]**  Calling something that is neither a function nor a class is
`Can only call functions and classes.`

    interpreter  compiler/Interpreter.a24  VisitCall
    unit         Call Non Function
    conformance  0049-call-failures.a24

**[EXP-013]**  Where a name is overloaded, selection is made on the **whole
signature** — the number of arguments and the type of each — and is made **at
run time**, from the arguments actually passed.

⚠️ **Run-time selection is required, not an implementation choice.** The type
system is gradual, so an argument's declared type may be `Any` or absent while
its value has a definite type: `var A : Any := 1;` passed to a name overloaded on
Integer and String selects the Integer. No static rule could reach that, and an
implementation must not resolve overloads at compile time on declared types
alone.

An argument may **name the parameter it fills** — `Log (Level: 'warn')`. The
arguments are then put in declaration order, so the order at the call site is
free.

⚠️ **The names select the signature**, which is why the feature exists. Run-time
selection above stays the rule, and stays right; what a programmer who *does*
know which overload they mean has lacked is a way to say so. A name identifies
one signature, where values only describe something several signatures might
accept.

⚠️ **Positional arguments come first and named ones after.** A positional
argument following a named one is refused, as is a parameter supplied twice, and
a name no parameter has. This is also what spares [FUN-005] a rule of its own:
gathering takes trailing *positional* arguments, and positional arguments end
exactly where naming begins — so naming the absorbing parameter turns gathering
off without anything having to say so.

⚠️ **`:` rather than `=>`, because the language already has this colon.**
`[k : v]` is a Map literal [COL-001]: a name on the left, a value on the right,
read by parsing an expression and then looking for a colon. A named argument
means the same thing and parses the same way. The ambiguity that usually rules
`:` out is absent — a colon in expression position normally meets a conditional
expression's `? :`, and this language has none, because `?` is an identifier
mark [LEX-008] and `Gate?` is one word.

⚠️ **A built-in has no named parameters.** Its parameters are not declared in
this language at all — they exist only as a count [RT-001] — so there is no name
to write, and `WriteLn (V: 'abc')` is *A built-in has no named parameters.*

    interpreter  compiler/Interpreter.a24  Arranged
    conformance  0160-named-arguments.a24
    refusal      0160-a-positional-argument-after-a-named-one.a24

    interpreter  compiler/ObjClass.a24  FindOverload
    compiler     bootstrap/algol.c      alg_invoke
    conformance  0050-overload-selection.a24

**[EXP-014]**  An overload is chosen by preferring an **exact match** on every
argument; failing that, one reachable by widening [VAR-004], since a parameter
is an assignment context [VAR-017]. When neither fits, the call fails with
`No matching signature for function.`

So a `Char` argument selects a `Char` parameter where one is declared, and
widens to a `String` parameter where it is not.

⚠️ **Selection makes three passes**, and the order is the rule: one admitting no
widening, then one admitting it, then one admitting **absorption** [FUN-005].
Adding widening to a single pass let *declaration order* decide instead —
`Take('a')` took a `String` overload declared above the `Char` one — which
`conformance/0050` caught at once.

⚠️ **The third pass is why "a fixed-arity signature beats a variadic one" is
written nowhere.** It is the pass order: absorption never runs when either of
the first two found something, so `Log ('warn', [1, 2])` passes the list rather
than gathering it into a second one holding it.

⚠️ Each pass runs over the **whole inheritance chain** before the next begins.
An exact match on a parent must beat a widened match on the child, or adding an
overload to a subclass would silently capture calls the parent was answering
exactly.

⚠️ **Inheritance is not widening.** A `Dog` fits an `Animal` parameter in both
passes, because that is the argument being what the parameter asks for rather
than being converted into it.

    interpreter  compiler/ObjClass.a24  FindOverload
    conformance  0050-overload-selection.a24
    conformance  0137-parameters-match-on-signature.a24

### 9.6 Subscripting

**[EXP-015]**  Subscripting a String yields the `Char` at that **character**
position, counted from zero [SRC-004]. An index outside the value is
`Index N out of range 0..M.`

⚠️ The position used to be counted in bytes, so a subscript into text outside
ASCII yielded part of a sequence rather than a character — `'café'[3]` was the
first half of a two-byte sequence. DEF-01 closed it; it is `é`.

    interpreter  compiler/Interpreter.a24  VisitSubscript
    compiler     bootstrap/algol.c         alg_subscript_get
    conformance  0051-string-subscript.a24

**[EXP-016]**  A class instance is subscripted through `Get` and `Put` — see
[TYP-010].

    interpreter  compiler/Interpreter.a24  VisitSubscript
    conformance  0031-instance-is-not-subscriptable.a24
    conformance  0171-a-class-that-subscripts.a24

### 9.7 Assignment

**[EXP-017]**  Assignment is an **expression**, and its value is the value
assigned: `X := (Y := 1)` leaves both at 1.

    interpreter  compiler/Parser.a24  Assignment
    unit         Resolve Assignment
    conformance  0052-assignment-is-an-expression.a24

---

## 10. Statements

### 10.1 Blocks and expression statements

**[STM-001]**  A block is `begin` … `end` and may be empty.

    interpreter  compiler/Interpreter.a24  VisitBlockStmt
    unit         Execute Block Statement
    conformance  0053-blocks-and-conditionals.a24

**[STM-002]**  A declaration may **not** stand as the body of a branch or a
loop. `if C then var X := 1;` is refused; the declaration must be inside a block.

⚠️ It used to be accepted, and the declared name **escaped into the enclosing
scope** — so whether the name existed was decided by a runtime condition, and a
loop body never entered behaved the same way.

⚠️ Fixing it **removed** a divergence rather than creating one: the C back end
already refused the construct (C-12), so the language, the compiler and the
interpreter now agree. It is the only entry in Annex C that closed by the
*language* moving.

⚠️ A declaration stays legal as a `try` body, which is a statement rather than a
branch: `try var X := 1; …` has to parse.

    interpreter  compiler/Parser.a24  BodyStatement
    refusal      0034-declaration-as-an-unbraced-body.a24

### 10.2 Conditionals

**[STM-003]**  `if Cond then S` with an optional `else S`. The condition is
tested for truthiness [VAL-008], not required to be a Boolean. A missing `then`
is `Expect 'then' after if condition.`

    interpreter  compiler/Interpreter.a24  VisitIfStmt
    unit         Execute If Statement
    unit         Execute Else Statement
    unit         Parse If Expect Then
    conformance  0053-blocks-and-conditionals.a24

**[STM-004]**  An `else` binds to the **nearest** unmatched `if`.

    interpreter  compiler/Parser.a24  IfStatement
    conformance  0053-blocks-and-conditionals.a24

### 10.3 Loops

**[STM-005]**  `while Cond do S`. A missing `do` is `Expect 'do' after
condition.`

    interpreter  compiler/Interpreter.a24  VisitWhileStmt
    unit         Execute While Loop
    unit         Parse While Expect Do
    conformance  0054-loops.a24

**[STM-006]**  The counted form is `for Init ; Cond ; Step do S`, and it
**desugars into a block** holding the initializer and a `while` — which is why
its variable is scoped [DCL-008].

⚠️ **The Step is held by the `while`, not appended to the body**, and `continue`
is the reason [STM-010]: with the step written at the end of the body, beginning
the next iteration jumped over it and the loop never ended.

    interpreter  compiler/Parser.a24  ForStatement
    unit         Execute For Loop
    unit         Parse For Statement
    conformance  0054-loops.a24
    conformance  0142-two-counted-loops-share-a-name.a24

**[STM-007]**  `for var X in C do S` walks a collection or a String. Over a
String it yields each `Char`; over a `Map` it yields each **key**.

    interpreter  compiler/Interpreter.a24  VisitForInStmt
    conformance  0054-loops.a24

**[STM-008]**  Iterating anything else is `Can only iterate a collection or a
String.` — see [TYP-011], which is where a class says it is iterable.

    interpreter  compiler/Interpreter.a24  VisitForInStmt
    conformance  0032-instance-is-not-iterable.a24

**[STM-009]**  ⚠️ The collection is **snapshotted** when the loop begins.
Adding to it inside the loop does not lengthen the walk.

    interpreter  compiler/Interpreter.a24  VisitForInStmt
    compiler     bootstrap/algol.c         alg_iterable
    conformance  0055-loop-snapshot.a24

**[STM-010]**  `break` leaves the innermost enclosing loop, and `continue`
begins its next iteration. Outside a loop either is refused **where it is
written** — a parse-time check — with `Must be inside a loop to use 'break'.` or
`Must be inside a loop to use 'continue'.`

A statement may be **labelled**, by writing a name and a colon before it, and
`break` or `continue` may then name which loop it means:

```
Outer:
for var I := 0; I < 3; I := I + 1 do
    for var J := 0; J < 3; J := J + 1 do
        if J = 1 then continue Outer;
```

A label naming no enclosing loop is refused where it is written, with
`No enclosing loop is labelled 'X'.` Labels are matched without regard to case,
like every other name [SRC-011].

⚠️ **`Name:` needs no keyword**, because `:=` scans as a single token [LEX-005]
and so `X := 1` cannot be read as a label on `= 1`. It is the third place this
shape appears and it means the same thing each time — a name on the left, the
thing it names on the right — beside the Map literal [COL-001] and a named
argument [EXP-013].

⚠️ **A labelled jump leaves every `try` opened inside the loop it names**, not
merely the innermost one, so more than one frame may have to be unwound at
once.

⚠️ **A `for` still takes its step.** `continue` skips the rest of the body and
nothing else, so `for var I := 0; I < 5; I := I + 1 do` with a `continue` in it
runs `I := I + 1` on that pass exactly as on every other. This is what separates
`continue` from `break`, which skips the step as well, because leaving a loop
means leaving all of it.

⚠️ **It is the reason a `for` is not merely a `while`.** A `for` desugars into a
while, and while the step was written at the end of the body a `continue` jumped
over it and the loop never ended — in both processors, since
`while (c) { body; step; }` skips the step in C for the same reason the
tree-walker does. The step is now held by the loop itself, so the interpreter
runs it after catching a `continue` and the C back end writes a real `for`.

    interpreter  compiler/Parser.a24  BreakStatement
    interpreter  compiler/Parser.a24  ContinueStatement
    unit         Parse Break Inside A While
    unit         Parse Break Outside A Loop
    conformance  0054-loops.a24
    conformance  0161-continue.a24
    conformance  0162-labelled-break-and-continue.a24
    refusal      0021-break-outside-a-loop.a24
    refusal      0161-continue-outside-a-loop.a24
    refusal      0162-a-label-no-enclosing-loop-has.a24

### 10.4 Case

**[STM-011]**  A `case` names a value, then arms, then `end`. An arm may list
several values separated by commas, and a final `else` is optional.

```
CaseStmt = "case" Expression "of" { Arm } [ "else" Statement ] "end" .
Arm      = Expression { "," Expression } ":" Statement .
```

    interpreter  compiler/Parser.a24  CaseStatement
    conformance  0056-case.a24

**[STM-012]**  ⚠️ `case` **desugars into an if/else-if chain**. There is no case
statement downstream of the parser, and two consequences follow from that rather
than from any rule of their own:

- Arms compare with `=` [VAL-009], so a `Double` matches an `Integer` arm of the
  same value — `1.0` matches the arm `1`.
- There is no fall-through. At most one arm runs.

    interpreter  compiler/Parser.a24  CaseStatement
    conformance  0056-case.a24

**[STM-013]**  When no arm matches and there is no `else`, nothing happens and
execution continues after the `end`.

    interpreter  compiler/Parser.a24  CaseStatement
    conformance  0056-case.a24

### 10.5 Exit

**[STM-014]**  `Exit` returns from the enclosing function or procedure, with a
value in a function and bare in a procedure. Statements after it do not run.

    interpreter  compiler/Interpreter.a24  VisitReturnStmt
    conformance  0057-exit.a24

**[STM-015]**  `Exit` at the top level is refused with `Can't return from
top-level code.`

    interpreter  compiler/Resolver.a24  VisitReturnStmt
    unit         Invalid Return
    refusal      0022-exit-at-top-level.a24

### 10.6 Exceptions

**[STM-016]**  `raise E` carries **any value** — a String, an Integer, a class
instance, anything.

    interpreter  compiler/Interpreter.a24  VisitRaiseStmt
    unit         Parse Raise
    conformance  0058-exceptions.a24

**[STM-017]**  A handler is written `on e : T do S` and matches on the runtime
type name of the raised value. A handler for a base class catches a derived
value.

    interpreter  compiler/Interpreter.a24  VisitTryStmt
    unit         Parse Try With A Typed Handler
    conformance  0058-exceptions.a24

**[STM-018]**  ⚠️ The **most derived** matching handler runs, however the
handlers are ordered. Writing the base first does not shadow the derived one.

⚠️ This is a deliberate departure from first-match, and [STM-023] is what makes
it total: two handlers for one type are refused, so "most derived" always names
exactly one handler and there is never a tie to break by position. The
commonest bug in a first-match language — a base handler written above a derived
one, quietly swallowing everything — cannot be written here.

    interpreter  compiler/Interpreter.a24  VisitTryStmt
    compiler     bootstrap/algol.c         alg_handler
    conformance  0058-exceptions.a24

**[STM-023]**  Two handlers for the same type on one `try` are refused with
`Duplicate handler for 'T'.`

    interpreter  compiler/Interpreter.a24  VisitTryStmt
    refusal      0023-duplicate-handler.a24

**[STM-019]**  A handler written without `on` is the catch-all and matches any
raised value.

    interpreter  compiler/Interpreter.a24  VisitTryStmt
    unit         Parse Untyped Handler Is The Catch All
    unit         Parse Empty Except Is The Catch All
    conformance  0058-exceptions.a24

**[STM-020]**  A runtime error raised by the language is catchable **as a
String**, carrying the diagnostic as its value: dividing by zero inside a `try`
is caught by `on e : String` with `e` equal to `Division by zero.`

    interpreter  compiler/Interpreter.a24  VisitTryStmt
    compiler     bootstrap/algol.c         alg_error
    conformance  0058-exceptions.a24

**[STM-021]**  A value raised and never caught ends the program, printing
`Uncaught: ` followed by the value, and exits with status **70**.

    interpreter  compiler/Main.a24  Main
    compiler     bootstrap/algol.c  alg_raise
    conformance  0059-uncaught-exits-70.a24

### 10.7 print

**[STM-022]**  There is no print statement. `WriteLn` [RT-015] writes a value
and a newline, and it is an ordinary built-in rather than syntax.

⚠️ The statement existed, and `print` was a keyword for it [LEX-010], so the
word could not be used as a name.

⚠️ **It also bypassed the test runner's output suppression**, which `Write` and
`WriteLn` respect — so a compiled suite printed the sample program before its
first test while interpreted it printed nothing. That behaviour went with the
statement, and nothing replaces it: output during a test run is suppressed for
every built-in alike.

    interpreter  compiler/Parser.a24  Statement
    conformance  0133-print-is-an-ordinary-name.a24
    refusal      0039-print-is-not-a-statement.a24

> This rule is stated in chapter 10 rather than being deleted, because a rule
> ID is permanent: [STM-022] has been cited, and a reader who follows the
> citation should find out what became of the statement rather than nothing.

### 10.8 Goto

**[STM-024]**  `goto` jumps to a label. The label must be in the **same block or
an enclosing one**, within the same subprogram, and the jump may go **forward or
backward**. Anything else is refused with `No label 'X' is in scope.`

```
GotoStmt = "goto" identifier ";" .
```

⚠️ **Direction is not the constraint; nesting is.** A backward jump costs
nothing that a forward one does not — the interpreter resumes a block at an
index, and an index may move either way, while C's `goto` has never cared. What
neither processor can do is jump **into** a nested block: the interpreter's jump
travels as an exception, which propagates outward and has no way inward, and C
would be skipping initializers. Pascal restricts it the same way and for the
same reason.

⚠️ **It may not leave the subprogram.** C's cannot, and the interpreter's would
unwind past the call it should have stayed inside.

⚠️ **The check is the Resolver's, not the parser's**, because a forward jump
names a label the parser has not reached yet. The Resolver has the whole block
in hand and so can answer for both directions at once — which is also where
`break` and `continue` differ: a loop they are inside has always been entered
already, so the parser can answer for those.

⚠️ **A jump out of a `try` must leave its frame.** The runtime's frame stack is
explicit, and a frame left behind points at a C frame that has returned; the
next `raise` then longjmps into it. A `goto` out of two `try` blocks to a
top-level label popped nothing at first, and the compiled program ran a handler
the interpreter never reached — the two processors disagreeing about a program,
which is the one thing the C back end exists not to do.

    interpreter  compiler/Resolver.a24  VisitGotoStmt
    conformance  0163-goto.a24
    refusal      0163-goto-into-a-nested-block.a24
    refusal      0164-goto-out-of-a-subprogram.a24

---

## 11. Functions, procedures and closures

### 11.1 Declarations

**[FUN-001]**  A subprogram is declared `function` or `procedure`. Parameters
may be typed or untyped, and a return type is optional.

```
FunDecl  = ( "function" | "procedure" ) identifier "(" [ Params ] ")"
           [ ":" Type ] ";" [ Sections ] Block .
Params   = identifier [ ":" Type ] { "," identifier [ ":" Type ] } .
```

    interpreter  compiler/Parser.a24  ParseFunction
    unit         Parse Function
    unit         Parse Function No Open Parenthesis
    conformance  0060-subprogram-declarations.a24

**[FUN-002]**  A subprogram that returns without a value yields `nil`.

    interpreter  compiler/Interpreter.a24  VisitReturnStmt
    conformance  0060-subprogram-declarations.a24

**[FUN-003]**  A **procedure** may not `Exit` a value. `Exit E;` inside one is
refused; `Exit;` and falling off the end are the ways a procedure returns, and
its result is always `nil` [FUN-002].

A **function** may `Exit` a value or not, and yields `nil` when it does not.

⚠️ A function declared **inside** a procedure may still exit a value: the
restriction belongs to the body being parsed, not to everything within it.

⚠️ The restriction is what makes the word mean something. Without it `procedure`
is a comment, and a reader cannot tell from a declaration whether a call has a
result worth using — which the C back end must also decide, and which every
caller must otherwise guard.

    interpreter  compiler/Parser.a24  ParseFunction
    conformance  0111-procedure-cannot-exit-a-value.a24
    refusal      0031-procedure-cannot-exit-a-value.a24

**[FUN-004]**  A declaration may not have more than 255 parameters:
`Can't have more than 255 parameters.`

    interpreter  compiler/Parser.a24  ParseFunction
    unit         Parse Function More Than 255 Parameters
    refusal      0024-too-many-parameters.a24

### 11.2 Parameters and results

**[FUN-005]**  A call checks the number of arguments — see [EXP-011] — unless
the subprogram's **last parameter is a `List of T`**, which **gathers** the
trailing arguments into a list. `Log ('warn', 1, 2)` is `Log ('warn', [1, 2])`,
and `Log ('warn')` is `Log ('warn', [])`.

⚠️ **An element type is what makes a parameter absorbing**, so a bare `List`
does not gather. There would be nothing to check the gathered arguments
against, and it leaves `List` as the spelling for a parameter that wants the
list itself and nothing else.

⚠️ **The element type replaces the arity check and is stricter than it.**
`Log ('warn', 1, 2, 'red')` against `List of Integer` is still refused, because
the stray argument is not an Integer — and it is refused with *No matching
signature for function.* rather than a count, which would name the wrong thing.

⚠️ **Gathering nothing yields the empty list.** That is structural and not a
default: absorbing none gives `[]` by the same rule that absorbing three gives
a list of three. It is what makes `WriteLn ()` an ordinary call [RT-001].

⚠️ **No new syntax, and that is the design rather than an economy.** The
declaration already says `List of T` [VAR-008]; absorption is a *reading* of a
type that exists, not a marker added to it. It became possible only when
element types were admitted on parameters — before that a bare `List` carried
no element type.

    interpreter  compiler/ObjFunction.a24  Absorbs
    conformance  0049-call-failures.a24
    conformance  0158-varargs-from-an-element-type.a24

**[FUN-006]**  A subprogram's declared parameter types are enforced on every
call, whether it is a top-level subprogram or a method. A parameter is an
assignment context [VAR-017], so an argument must have the declared type, widen
to it [VAR-004], or be `nil` [VAR-005].

⚠️ **One rule, one path.** Signature comparison used to run only when the callee
had an *owner* — that is, only for a method — so a top-level subprogram fell
through to an arity check and its annotation was a contract in one place and
decoration in the other. `Fits` is asked of every declared subprogram now.

⚠️ A **native** is still matched on arity alone, and correctly: its parameters
are not declared in this language, so it has a signature only in the sense of a
count.

    interpreter  compiler/Interpreter.a24  VisitCall
    conformance  0137-parameters-match-on-signature.a24
    refusal      0042-top-level-parameter-type.a24

**[FUN-007]**  A **method's** parameter types **are** enforced, because a method
goes through overload selection [EXP-013]. Passing a String where `Integer` is
declared is `No matching signature for function.`

    interpreter  compiler/ObjClass.a24  FindOverload
    refusal      0025-method-parameter-type-is-enforced.a24

> Types are checked because overload selection compares whole signatures
> [EXP-013]. That is why [FUN-013] matters beyond overloading itself: a
> subprogram that goes through selection has its parameters compared as a
> consequence, which is how DEF-19 was fixed: there was nothing to add, only a
> check to reach.

**[FUN-008]**  A declared **return** type **is** enforced. `Exit` of a value
that does not fit is `Type mismatch!`

    interpreter  compiler/TypeChecker.a24  Assignable
    refusal      0026-return-type-is-enforced.a24

### 11.3 Closures

**[FUN-009]**  A nested subprogram captures the enclosing variables **by
reference**, and the capture outlives the call that created it. A function
returning a nested one hands back something that keeps reading and writing the
same variable.

    interpreter  compiler/ObjFunction.a24  ObjFunction
    compiler     bootstrap/algol.c         alg_cell
    conformance  0061-closures.a24

**[FUN-010]**  Each call to the enclosing subprogram creates a **fresh** set of
captured variables. Two counters made the same way do not share a count.

    interpreter  compiler/Environment.a24  Environment
    compiler     bootstrap/algol.c         alg_closure
    conformance  0061-closures.a24

### 11.4 Subprograms as values

**[FUN-011]**  A subprogram's name used without a call is a value. It may be
assigned to a variable, passed as an argument, stored in a collection, and
called from wherever it comes to rest.

    interpreter  compiler/ObjFunction.a24  ObjFunction
    compiler     bootstrap/algol.c         alg_call
    unit         Interpret Local Function
    conformance  0062-subprograms-as-values.a24

### 11.5 Nesting

**[FUN-013]**  A **top-level** subprogram overloads on the whole signature,
exactly as a method does [EXP-013]. Several may share a name where their
signatures differ, and the call selects between them at run time from the
arguments actually passed.

```
function Area (N : Integer);              begin Exit 'integer';      end
function Area (S : String);               begin Exit 'string';       end
function Area (A : Integer, B : Integer); begin Exit 'two integers'; end
```

⚠️ **Two declarations claiming the SAME signature are still a duplicate**, and
the *parameter* types alone decide it. A return type does not distinguish an
overload — selection happens from the arguments, so two subprograms differing
only in what they return could never be told apart at a call. Neither do the
parameter names: `Take (A : Integer)` and `Take (B : Integer)` are one
signature, not two.

⚠️ **That is not contradicted by named arguments** [EXP-013], and the
distinction is worth keeping straight. Names cannot make two identical
signatures into an overload set; what they do is let a *call* say which of
several genuinely different signatures it means, which is a question about the
call site rather than about the declarations.

⚠️ The environment binds one name to one value, which is what made the
restriction look structural. The value can be a **set** of subprograms, and the
call selects from it exactly as a method call selects from a class's methods —
the mechanism was already here.

⚠️ Compiled, a name with more than one subprogram behind it is reached through
an overload set that selects at the call, and only such a name carries a
signature in its C symbol — see C-26. A lone **variadic** subprogram goes
through a set as well [FUN-005]: its own symbol takes a fixed number of
arguments, and an absorbing call has a different number by definition.

⚠️ Nothing in this specification ever restricted overloading to methods.
[EXP-013] and [EXP-014] describe selection without qualification; the
restriction lived in two of this document's own notes and in a comment in
`compiler/Resolver.a24`, none of which was a rule.

⚠️ **This was upstream of DEF-19.** A subprogram that goes through overload
selection has its declared parameter types compared as part of being selected —
which is exactly why a *method's* types were enforced and a top-level
subprogram's were not [FUN-006]. Fixing this fixed that.

    interpreter  compiler/ObjFunction.a24  ObjOverloads
    interpreter  compiler/Resolver.a24     SignatureOf
    conformance  0138-top-level-overloading.a24
    refusal      0043-same-signature-twice.a24

**[FUN-012]**  Subprograms may be declared inside subprograms, to any depth.

⚠️ **A method's body counts**, and is where the depth rule meets [CLS-011]: a
function declared in one closes over the method's locals *and* over `this`, so a
field read inside it resolves through the receiver the method was called on.
The C back end handles both the depth and that shape; C-38 records what the
second needed.

    interpreter  compiler/Parser.a24  ParseFunction
    conformance  0063-nesting.a24
    conformance  0148-a-function-inside-a-method.a24

---

## 12. Classes and objects

### 12.1 Declaration

**[CLS-001]**  A class is declared with an optional superclass, an optional
header of sections, and a body.

```
ClassDecl = "class" identifier [ "(" identifier ")" ] ";"
            [ Sections ] "begin" { Member } "end" .
```

    interpreter  compiler/Parser.a24  ClassDeclaration
    unit         Parse Class Declaration
    unit         Parse Class No Begin
    conformance  0064-class-declaration-and-fields.a24

**[CLS-002]**  Fields are declared in `var` sections of the header [VAR-009];
methods in the body. Visibility markers apply to both [DCL-011].

    interpreter  compiler/Parser.a24  ClassDeclaration
    conformance  0064-class-declaration-and-fields.a24

### 12.2 Construction

**[CLS-003]**  An instance is made by **calling the class**: `Point(3, 4)`.

    interpreter  compiler/Interpreter.a24  VisitCall
    compiler     bootstrap/algol.c         alg_new
    conformance  0065-construction.a24

**[CLS-004]**  A constructor is a member named `constructor Init`. Construction
checks its arity, and a class with no constructor takes no arguments —
`C(1, 2)` on such a class is `Expected 0 arguments but got 2.`

    interpreter  compiler/ObjClass.a24  FindMethod
    conformance  0065-construction.a24

**[CLS-005]**  ⚠️ A field's initializer is evaluated **once per instance**, at
construction. Two instances of a class whose field is `List := []` hold two
different Lists.

    interpreter  compiler/ObjClass.a24  SeedFields
    compiler     bootstrap/algol.c      alg_class_field
    conformance  0064-class-declaration-and-fields.a24

**[CLS-006]**  A field with no initializer begins as `nil` [VAR-002].

    interpreter  compiler/ObjClass.a24  SeedFields
    conformance  0064-class-declaration-and-fields.a24

### 12.3 Members

**[CLS-007]**  A field is read without parentheses and a method is called with
them. A `property` is read without them too, and its read is the call
[CLS-017].

    interpreter  compiler/ObjInstance.a24  Get
    unit         Call Setters And Getters
    conformance  0066-members.a24

**[CLS-008]**  Every instance answers `ClassName`, and does so **ahead of its
fields**: the name belongs to the language, so a field of that name cannot take
it.

    interpreter  compiler/ObjInstance.a24  Get
    compiler     bootstrap/algol.c         alg_property
    conformance  0066-members.a24

**[CLS-009]**  A class declaring `ToString()` — **taking no arguments** —
decides how its instances render through `Str` [RT-006] and wherever a value is
written [RT-015]. With none, an instance renders as its class name followed by
` instance` — `C instance`.

⚠️ **The arity is part of the protocol**, as it is for `Elements` [TYP-011]. A
`ToString` taking an argument does not implement this one and the default
rendering stands, rather than the call being attempted and failing.

    interpreter  compiler/Interpreter.a24  Stringify
    conformance  0066-members.a24
    conformance  0165-a-class-that-iterates.a24

**[CLS-010]**  Reading or calling a member the class does not have is
`Undefined property 'X'.`

    interpreter  compiler/ObjInstance.a24  Get
    unit         Call Undefined Getter
    conformance  0067-undefined-property.a24

### 12.4 Inheritance

**[CLS-011]**  `class D (B)` makes `D` inherit `B`'s fields and methods. A
method of the same name overrides the inherited one.

    interpreter  compiler/ObjClass.a24  FindMethod
    conformance  0068-inheritance.a24

**[CLS-012]**  `super.M()` calls the version above the class that declared the
calling method, not above the runtime class.

⚠️ It binds to the class that **declared** the method, not to the runtime class
of `this`. A method in `B` calling `super.Who()` reaches `A`'s version even when
the receiver is a `C` below `B`.

⚠️ **`super.M` read without calling it binds the parent's method to this
receiver**, exactly as `B.M` binds the receiver's own [CLS-011], and the search
starts in the same place. It is the only way a program can hold the
implementation an override replaced.

    interpreter  compiler/Interpreter.a24  VisitSuperExpr
    compiler     bootstrap/algol.c         alg_invoke_from
    compiler     bootstrap/algol.c         alg_bound_from
    conformance  0068-inheritance.a24
    conformance  0150-super-as-a-value.a24

**[CLS-013]**  A class may not inherit from itself: `A class can't inherit from
itself.`

    interpreter  compiler/Resolver.a24  VisitClassStmt
    unit         Inherit From Self
    refusal      0027-inherit-from-self.a24

**[CLS-014]**  A superclass must be a class, and is checked **where it is
declared** rather than where an instance is later built. Naming something that
is not a class is `'X' is not a class.`, beside the existing
`A class can't inherit from itself.` [CLS-013].

Naming a name that denotes nothing is `Undefined variable 'X'.`

⚠️ The check fires at the declaration, so a program that never constructs the
class is still refused. It used to ask the superclass for `.ClassName` first,
which raised `Only instances have properties.` before the comparison meant to
reject it could run — a sentence naming neither the class, nor the superclass,
nor inheritance.

⚠️ **A cycle counts as inheriting from itself.** `class A (B); class B (A);` ran
silently until classes were hoisted [DCL-006], leaving a superclass chain with
no end for method lookup to walk. It is refused with the same sentence the
direct case gives, because it is the same fault reached the long way round.

    interpreter  compiler/Interpreter.a24  VisitClassStmt
    interpreter  compiler/Resolver.a24     CheckInheritance
    unit         Inherit Not A Class
    conformance  0112-inherit-from-a-non-class.a24
    refusal      0047-inheritance-cycle.a24

### 12.5 Objects

**[CLS-015]**  `object N;` declares a class having exactly one instance, reached
by the name itself. The instance is built on first use, so an object may refer
to another declared later in the file.

    interpreter  compiler/Parser.a24  ClassDeclaration
    compiler     bootstrap/algol.c    alg_singleton
    unit         An Object Takes Visibility Sections
    conformance  0069-objects.a24

**[CLS-016]**  An object is not callable. `Config()` is `Can only call functions
and classes.`

    interpreter  compiler/Interpreter.a24  VisitCall
    conformance  0070-object-is-not-callable.a24

**[CLS-017]**  A `property` is a member of a class read **without parentheses**,
whose read is the call. It takes no parameters and may declare a return type.

```
class Stack;
var
private:
    Items : List;

begin
    constructor Init ();      begin this.Items := []; end
    procedure Push (V : Any); begin Items.Add (V); end

    property Count   : Integer; begin Exit Items.Length; end
    property IsEmpty : Boolean; begin Exit Items.Length = 0; end
end
```

Assigning to one is refused **where the receiver's type is known**, with
`'Count' is a property of Stack and cannot be assigned.` An inherited property
is still a property.

⚠️ **It exists to give a read-only view of internal state**, which nothing else
in the language could express. A field is public — readable **and writable** — or
private, meaning invisible [DCL-011]; there is no third state, so a `Stack`
written in Algol-24 could not protect its own count while showing it, and was
strictly worse than the built-in it imitates, whose `Length` cannot be assigned.

⚠️ **Nothing is checked at run time**, and that is deliberate. Assignment is
refused by the checker where the receiver's type is known and reported nowhere
when it is not — exactly as `private:` is silent there [DCL-015]. D-9 rejected
enforcing visibility at run time because it puts a check on every property
*access*; a check on writes alone would be cheaper, and is still not worth
buying a boundary the rest of the language does not have.

⚠️ **A parameter list would have nowhere to arrive from**, which is why the
declaration has none. Leaving the parentheses off is what says the member is
read rather than called.

    interpreter  compiler/Parser.a24       ParseProperty
    compiler     bootstrap/algol.c         alg_class_property
    conformance  0168-a-read-only-property.a24
    refusal      0168-assigning-to-a-property.a24

**[CLS-018]**  An instance is **closed**: assignment reaches only a field the
class declared. `B.Undeclared := 1` is `Undefined property 'Undeclared'.`

⚠️ **The interpreter allowed it until Generation 6**, which is Lox's
arrangement — a field appeared the moment something assigned to it. The C back
end never had it, because an instance there is a fixed array of slots taken from
the `var` section, so `B.Undeclared := 1` was `1` interpreted and refused
compiled. A divergence older than the properties that found it, covered by no
case, and held in place by a unit test inherited from Lox along with the
behaviour.

    interpreter  compiler/ObjInstance.a24  Set
    conformance  0169-an-instance-is-closed.a24

---

## 13. Enumerations

### 13.1 Declaration

**[ENU-001]**  An enumeration is declared with `type`, naming its members in
order.

```
EnumDecl = "type" identifier "=" "(" identifier { "," identifier } ")" ";" .
SubrangeDecl = "type" identifier "=" bound ".." bound ";" .
bound = [ "-" ] integer_lit .
```

    interpreter  compiler/Parser.a24  EnumDeclaration
    conformance  0071-enumerations.a24

**[ENU-002]**  Each member is bound as a **bare name** in the enclosing scope and
is also reachable qualified as `Type.Member`. Both spellings denote the **same
interned object**, so `RED = Colour.RED` is true.

    interpreter  compiler/ObjEnum.a24  ObjEnumType
    compiler     bootstrap/algol.c     alg_enum_member
    unit         Both Spellings Of An Enum Member Type As The Enum
    conformance  0071-enumerations.a24

**[ENU-003]**  Two enumerations **may** share a member name. Declaring
`type First = (A, B);` and `type Second = (A, C);` in one scope is accepted, and
neither declaration is affected by the other.

⚠️ The declaration used to be refused with `'A' is already defined.`, so adding
a member to one enumeration could break an unrelated one elsewhere in the
program — and `First.A`, which is unambiguous, never got a chance to help.

    interpreter  compiler/Interpreter.a24  VisitEnumStmt
    interpreter  compiler/Resolver.a24     CheckDuplicates
    conformance  0123-enumerations-may-share-member-names.a24

**[ENU-011]**  A **bare** member name bound by more than one enumeration in
scope is ambiguous, and using it is refused with
`'A' is ambiguous: First or Second.` The qualified form [ENU-002] resolves it:
`First.A` and `Second.A` are two different members.

A bare name bound by only one enumeration in scope is unambiguous and needs no
qualifier, which is the ordinary case and the reason members bind bare at all.

⚠️ **The refusal belongs to the use, not to the declaration.** Two enumerations
that never meet an ambiguous use coexist without complaint, and a program is
told about a name only where it actually cannot be resolved.

⚠️ The ambiguous name is **removed** from the scope's bindings rather than left
in it holding one of the two, so a bare read cannot quietly find one. The
qualified form is unaffected: it reaches the member through the enumeration
rather than through that binding.

⚠️ Compiled, the ambiguity is carried to the use and reported there in the same
words — see C-20, which was aimed at the symbols and did not need to be.

    interpreter  compiler/Environment.a24  MarkAmbiguous
    conformance  0123-enumerations-may-share-member-names.a24

**[ENU-004]**  Naming a member the type does not have is `Undefined enum member
'X'.`

    interpreter  compiler/ObjEnum.a24  ObjEnumType
    conformance  0072-unknown-enum-member.a24

### 13.2 Values

**[ENU-005]**  Members compare by **identity** [VAL-011]. A member of one
enumeration is never equal to a member of another, whatever they are called.

    interpreter  compiler/Interpreter.a24  IsEqual
    unit         An Enum Member Does Not Satisfy Another Enum
    conformance  0071-enumerations.a24

**[ENU-006]**  `M is T` is true for the member's own type and false for every
other.

    interpreter  compiler/Interpreter.a24  VisitIsExpr
    unit         An Enum Type Name Types As Itself
    conformance  0071-enumerations.a24

**[ENU-007]**  A member renders as its bare name: `Str(RED)` is `RED`.

    interpreter  compiler/ObjEnum.a24  ToString
    conformance  0071-enumerations.a24

**[ENU-008]**  Members are **not ordered**. `RED < GREEN` is `Operands must be
numbers.`

⚠️ A program that needs an order compares ordinals [ENU-010]. The operators are
left alone deliberately: `<` on two members would have to mean position, and
position is exactly the property [ENU-009] shows to be a trap when it acts
implicitly.

    interpreter  compiler/Interpreter.a24  VisitBinary
    conformance  0073-enum-members-are-not-ordered.a24

### 13.3 The ordinal

**[ENU-009]**  The **first member of every enumeration is falsey**, and every
later member is truthy, because truthiness reads the member's position
[VAL-008].

This is deliberate. It lets a program declare its own two-valued types and use
them directly in a condition, with no comparison and no conversion:

```
type Flag   = (Off, On);
type Answer = (No, Yes);

if F then …
```

⚠️ **The discipline it asks for: put the absent, off or zero member first.** The
position is part of the declaration's meaning, so reordering members changes the
truth of every condition written over them — in the same way, and for the same
reason, that reordering a `case`'s arms changes which one runs. The position is
readable [ENU-010], so nothing here is hidden.

⚠️ This compiler's own enumerations already follow the convention: `FUN_NONE`
and `CLASS_NONE` are the first members of `FunctionType` and `ClassType`.

    interpreter  compiler/Interpreter.a24  IsTruthy
    compiler     bootstrap/algol.c         alg_truthy
    conformance  0074-enum-truthiness.a24

**[ENU-010]**  A member answers `Ordinal`, its **zero-based position** in the
declaration. `RED.Ordinal` is 0 and `BLUE.Ordinal` is 2. It answers no other
property.

⚠️ The ordinal is what a program needs to order members [ENU-008], to index an
array by one, or to write one out and read it back. It also governs truthiness
[ENU-009], and a program could once discover that only by testing a member for
truth.

    interpreter  compiler/ObjEnum.a24  Get
    conformance  0113-enum-ordinal.a24

---

## 14. Collections

⚠️ **This chapter describes the collections as built-ins, which is what they are
today and not what they are meant to remain.** The intent is to move everything
not genuinely pinned to the core out into a unit written in Algol-24 — see
Annex E for which of the five are pinned and by what, and Annex H, H-9 for the
work. What survives in the core is `Array`, which nothing in the language can
express, and the literal forms `[…]` and `[:]`, which hand out the names `List`
and `Map` before any unit can.

⚠️ **The rules below are therefore expected to leave this specification**, and
their conformance cases with them. That is not a failure of either: a rule that
stops describing the *language* because its subject became a *library* has been
retired, not falsified, and the cases that pinned it become the unit tests of
the unit that replaces it. They are worth writing now precisely because they are
the behavioural target that unit has to meet.

⚠️ One rule in this chapter is **not** provisional in that way. [COL-007]
specifies insertion order for every collection, including `Set` and `Map`, and
any replacement must reproduce it — it was specified rather than left to the
representation because both processors must agree, and a unit is a third
implementation with the same obligation.

### 14.1 Construction

**[COL-001]**  A bracketed list of values is a `List`, and `[]` is an empty one.
A bracketed list of `key : value` pairs is a `Map`, and `[:]` is an empty one.

    interpreter  compiler/Parser.a24  Primary
    conformance  0075-collection-construction.a24
    conformance  0143-a-large-computed-literal.a24

**[COL-002]**  `List()`, `Set()`, `Stack()` and `Map()` construct empty
collections, `Set(L)` builds a Set from a collection, and `Array(N)` an Array of
`N` elements.

    interpreter  compiler/Interpreter.a24  ArrayNative
    compiler     bootstrap/algol.c         alg_array
    conformance  0075-collection-construction.a24

### 14.2 Members

**[COL-003]**  Every collection answers `Length` and `IsEmpty` as properties, and
`Contains` as a method. Everything else is per kind:

| | List | Set | Stack | Array | Map |
| --- | :-: | :-: | :-: | :-: | :-: |
| `Length` `IsEmpty` `Contains` | ● | ● | ● | ● | ● |
| `Get` | ● | | | ● | ● |
| `Add` | ● | ● | | | |
| `Insert` `RemoveAt` | ● | | | | |
| `IndexOf` `Sort` | ● | | | ● | |
| `Clear` | ● | ● | ● | | ● |
| `Remove` | | ● | | | ● |
| `Set` `Fill` | | | | ● | |
| `Put` `Keys` `Values` | | | | | ● |
| `ToList` | | ● | | | |
| `Push` `Pop` `Peek` | | | ● | | |

⚠️ This table is checked against the interpreter by `spec/spec.sh`, which asks
`spec/members.a24` which members each kind actually answers for. A matrix
transcribed into a specification and checked by nobody is the most rot-prone
thing this document can hold.

    interpreter  compiler/ObjCollection.a24  Get
    conformance  0076-collection-members.a24

**[COL-004]**  ⚠️ A `List` has **no `Remove`**. Removing a value from a List
means finding it with `IndexOf` and passing that to `RemoveAt`, while a `Set` and
a `Map` remove by value and by key directly.

⚠️ The asymmetry has a reason, and it is not an oversight. A List may hold the
same value more than once, so "remove this value" has no single meaning — the
first, the last, or all of them — while a Set holds each value once and a Map
each key once, so for those it has exactly one. Making a program write `IndexOf`
and `RemoveAt` is making it say which it meant.

    interpreter  compiler/ObjCollection.a24  Get
    conformance  0076-collection-members.a24

**[COL-005]**  A member a kind does not have is `Undefined property 'X'.`

⚠️ A member the kind *does* have is a value before it is a call, as a method of
an instance is [CLS-011]: `L.Sort` reads as something callable. That is also the
only way to ask whether a kind has a member without arranging arguments for it,
which is how `spec/members.a24` — the source [COL-003]'s matrix is checked
against — probes for one.

    interpreter  compiler/ObjCollection.a24  Get
    conformance  0077-undefined-collection-member.a24
    conformance  0144-a-collection-member-without-the-call.a24

**[COL-006]**  A collection member's name is matched **case-insensitively**,
as every name in the language is [SRC-011]. `L.Add(2)` and `L.add(2)` are the
same member.

⚠️ **This is the one place where the C back end was already right and the
interpreter was the one that changed** — C-4, now withdrawn. The compiler
compared these names with `alg_stricmp`, which was recorded as a divergence
while the interpreter was taken to be the authority; [SRC-011] reversed that.

⚠️ The comparison literals in `ObjCollection`, `ObjFile` and `ObjBuffer` are
written **folded**, and the incoming member is folded to meet them. The
diagnostic still quotes the member as the program wrote it: `L.Zap` is
`Undefined property 'Zap'.`, not `'zap'`.

    interpreter  compiler/ObjCollection.a24  Get
    conformance  0126-identifiers-are-case-insensitive.a24

### 14.3 Order

**[COL-007]**  Every collection iterates in **insertion order**, including
`Set` and `Map`. This is specified rather than left to the representation,
because both processors must produce the same output.

    interpreter  compiler/ObjCollection.a24  Items
    compiler     bootstrap/algol.c           alg_iterable
    conformance  0078-collection-order.a24

**[COL-008]**  Re-assigning an existing Map key keeps the key's **original
position**. `Put` on a key already present replaces the value and does not move
it to the end.

    interpreter  compiler/ObjCollection.a24  Invoke
    compiler     bootstrap/algol.c           alg_put
    conformance  0078-collection-order.a24

**[COL-009]**  `Keys()` and `Values()` answer in that same order, so the two
correspond element for element.

    interpreter  compiler/ObjCollection.a24  Invoke
    conformance  0078-collection-order.a24

### 14.4 Behaviour

**[COL-010]**  A `Set` holds each value once. Adding a value it already has
leaves its length unchanged.

    interpreter  compiler/ObjCollection.a24  Invoke
    conformance  0079-collection-behaviour.a24

**[COL-011]**  ⚠️ `Remove` answers **different kinds of thing** by kind. A `Map`
returns the value removed, and `nil` when the key was absent. A `Set` returns
whether there was anything to remove.

⚠️ Each answer is the useful one for its kind — a Map's removed value is worth
having, and a Set has nothing to hand back but whether it did anything — but the
two cannot be used interchangeably, and nothing in the call says which is coming.

    interpreter  compiler/ObjCollection.a24  Invoke
    compiler     bootstrap/algol.c           alg_remove
    conformance  0079-collection-behaviour.a24

**[COL-012]**  Membership — `Contains`, `in`, and Map key lookup — uses the
equality of [VAL-009], so a collection holding `1.0` contains `1`. See
[VAL-013].

⚠️ A collection still compares by **identity**, and that is unchanged: two Lists
of the same contents are not equal, so `[1] in [[1]]` is false. Promotion is
between the numeric types, not a structural comparison.

    interpreter  compiler/ObjCollection.a24  Invoke
    compiler     bootstrap/algol.c           strict_equals
    conformance  0127-membership-follows-equality.a24

**[COL-013]**  `Sort` orders in place and is **stable**. It orders numbers
against numbers and text against text; mixing them is `Can only sort numbers
against numbers, or text against text.`

⚠️ **Text is ordered by [VAL-014]**, the same ordering `<` gives, rather than by
a second one that happens to agree. It compared with `strcmp` until Generation 6
— bytes rather than characters, stopping at an embedded zero a String is
entitled to hold — which matched only because UTF-8 is designed so byte order
follows code-point order.

    interpreter  compiler/ObjCollection.a24  Invoke
    compiler     bootstrap/algol.c           alg_sort
    conformance  0080-sort.a24
    conformance  0166-text-is-ordered.a24

**[COL-014]**  Subscripting reads by position for a `List` and an `Array` and by
key for a `Map`. A `Set` has no positions and is refused with `Subscript target
should be an ordinal.`

    interpreter  compiler/ObjCollection.a24  At
    compiler     bootstrap/algol.c           alg_subscript_get
    conformance  0081-subscripting-by-kind.a24

**[COL-015]**  An `Array` is fixed in size and does not grow on assignment — see
[TYP-008].

    interpreter  compiler/ObjCollection.a24  At
    conformance  0029-array-is-fixed.a24

---

## 15. Modules

### 15.1 Importing

**[MOD-001]**  `uses` imports another file. A bare identifier names the file of
that name with `.a24` appended; a quoted string is a path.

```
UsesStmt = "uses" ( identifier | string_lit ) ";" .
```

    interpreter  compiler/Parser.a24  UsesStatement
    conformance  0082-module-import.a24

**[MOD-002]**  ⚠️ A module name is the one place [SRC-011] does **not** reach.
It names a file, and the filesystem decides how that name is matched — case-
insensitively on macOS and Windows, sensitively on Linux. `uses scanner` may
therefore find `Scanner.a24` on one machine and fail on another.

This is stated rather than fixed because the language does not own the
filesystem. A program that wants to run everywhere spells a module name exactly
as the file is named.

A module is looked for **beside the importing file first**, then
in the working directory. Two directories may therefore hold files of one name
without either reaching the other's. Failure is `Could not find module 'X': no
X.a24 in …`

    interpreter  compiler/Parser.a24  ResolveModule
    conformance  0082-module-import.a24

**[MOD-003]**  A module is loaded and executed **once**, keyed by its resolved
path, however many files import it. A second import of the same file sees the
names without re-running the body.

    interpreter  compiler/Parser.a24  UsesStatement
    conformance  0083-module-runs-once.a24

**[MOD-004]**  A file may open with `unit N;`. If present, `N` must match the
file's own name: `Unit 'Wrong' must match its file name 'Mismatch'.`

    interpreter  compiler/Parser.a24  UnitHeader
    refusal      0029-unit-name-must-match-the-file.a24

### 15.2 Exports

**[MOD-005]**  A module exports its top-level declarations, except those marked
`private`.

    interpreter  compiler/Interpreter.a24  VisitModuleStmt
    conformance  0082-module-import.a24

**[MOD-006]**  At the top level of a module, `private` precedes a **single
declaration** and hides it. It is not a section marker there, unlike inside a
class [DCL-011].

    interpreter  compiler/Parser.a24  RecordPrivate
    unit         Module Private Is Not A Section Marker
    conformance  0082-module-import.a24

**[MOD-007]**  A private name is invisible to an importer both bare and
qualified. Qualified, it is `Undefined name 'Hidden' in unit 'Mid'.`

    interpreter  compiler/Interpreter.a24  Qualified
    conformance  0084-module-private.a24

**[MOD-008]**  Two imported modules **may** export one name. Importing both is
accepted, and neither module is affected by the other.

⚠️ The import used to be refused with `'Clash' is already defined; mark it
private in one of the modules.` — advice to edit a module because of what some
other module, possibly written by someone else, happens to export.

    interpreter  compiler/Interpreter.a24  VisitModuleStmt
    conformance  0124-modules-may-share-exported-names.a24

**[MOD-013]**  A **bare** name exported by more than one imported module is
ambiguous, and using it is refused with
`'Shared' is ambiguous: Alpha or Beta.` The qualifier [MOD-010] resolves it:
`Alpha.Shared()` and `Beta.Shared()` are two different functions.

A bare name exported by only one imported module is unambiguous and needs no
qualifier, which is the ordinary case.

⚠️ **The refusal belongs to the use, not to the import.** Two modules that
export a common name and are never used ambiguously coexist without complaint,
and a program is told about a name only where it actually cannot be resolved.

⚠️ This is [ENU-011] applied to units, and for the same reason: a name that
cannot be resolved is a property of the *use*, not of the declaration. It also
removes the need for the advice the old diagnostic gave — a module should not
have to be edited because of what some other module, possibly written by someone
else, happens to export.

⚠️ Detected where the name is **resolved through the imports**, which is the
only place the ambiguity is real. Importing one module twice is not a clash with
itself: the same environment appearing twice in the import list is still one
module.

⚠️ Compiled, each owner's symbol takes its unit as a suffix and the bare use is
reported where it cannot be resolved — see C-21.

    interpreter  compiler/Environment.a24  OwnerOf
    conformance  0124-modules-may-share-exported-names.a24

### 15.3 Visibility

**[MOD-009]**  ⚠️ `uses` is **not transitive**. If `A` imports `B` and `B`
imports `C`, then `A` does not see `C`'s names — `B` may use them, and `A` may
not. The diagnostic names the unit that would export it:

```
Undefined variable 'DeepName'. Unit 'Deep' exports it; this file has no 'uses' for it.
```

    interpreter  compiler/Interpreter.a24  LookupVariable
    conformance  0085-uses-is-not-transitive.a24

**[MOD-010]**  An exported name may be qualified by its unit — `Mid.MidName()` —
and the qualifier is resolved statically as a unit rather than evaluated as a
value.

    interpreter  compiler/Interpreter.a24  Qualified
    conformance  0082-module-import.a24

**[MOD-011]**  `System` is the unit of the built-in functions. No file imports
it and every file may qualify against it: `System.Copy('abcdef', 0, 3)`.

    interpreter  compiler/Resolver.a24  Units
    conformance  0086-system-unit.a24

### 15.4 Cycles

**[MOD-012]**  A cycle **between modules** works. `A` uses `B` and `B` uses
`A`, and both are loaded, both bodies run, and the functions of each are
callable — because a module is loaded once by resolved path [MOD-003], so the
second import finds the entry already made rather than descending again.

Cycles of three and more behave the same way.

    interpreter  compiler/Parser.a24  UsesStatement
    conformance  0087-cycles-between-modules-work.a24

**[MOD-014]**  A cycle **through the root file** — a module importing the file
that is being run — works as [MOD-012] does. The root is a module in its own
right: a `uses` naming it resolves to the file already loaded, and to the
environment already running.

The root's environment is registered **before its own body runs**, which is
exactly the position an ordinary module is in when a cycle reaches it. An
import-only node carries no statements, so the importer needs the environment to
exist by the time it links to it; a name is looked up when it is *used*, by which
time everything has loaded.

⚠️ The root's own environment is the **globals**, not a copy, so the importer
sees the same bindings. It exports every name it declares.

⚠️ The root used to be the one file never entered in the loader's map, so a
module importing it back parsed it a **second** time and the two copies did not
share their names — the root's body printed and then its own imported name was
undefined. Compiled, the duplicate refused with `Two modules named 'X' is not
supported by the C back end yet.`, which was the only known case of a valid
program having no compiled form.

    interpreter  compiler/Parser.a24       Parse
    interpreter  compiler/Interpreter.a24  RegisterRoot
    conformance  0125-a-cycle-through-the-root.a24

---

## 16. Built-in functions

### 16.1 The set

**[RT-001]**  Twenty-eight names are built in. Twenty-five are always
available:

```
Length  Copy  Pos   Str        Ord   Char  Val
Succ    Pred
Max     Mod   clock
List    Set   Stack Array      Map   Buffer
TextFile      FileExists
ParamCount    ParamStr
Write   WriteLn    Halt
```

⚠️ The list is checked against the names the interpreter registers by
`spec/spec.sh`; Annex B is the index.

⚠️ A built-in is called like any other subprogram, so a call to one checks its
argument count [EXP-011] and reports it the same way — the name existing is what
separates that failure from a reference to something undeclared.

⚠️ **`Write` and `WriteLn` take any number of values**, rendered as `Str`
renders them [RT-019] and run together with nothing between them — so
`WriteLn ('ABC', 123)` writes `ABC123`, and `WriteLn (1, 2)` writes `12` rather
than `3`. `WriteLn ()` is the newline on its own, which is the same rule and not
a second form: rendering no values gives the empty string.

    interpreter  compiler/Interpreter.a24  Rendered
    conformance  0145-a-builtin-with-the-wrong-arity.a24
    conformance  0159-write-takes-any-number-of-values.a24
    conformance  0088-builtins.a24

**[RT-002]**  The remaining three — `AssertTrue`, `AssertEqual` and `Fail` — are
registered **only while `--test` is running** [see 19]. Calling one outside a
test run is `Undefined variable 'AssertTrue'.`

    interpreter  compiler/Interpreter.a24  RunTests
    refusal      0030-assert-outside-a-test-run.a24

### 16.2 Text

**[RT-003]**  `Length(V)` measures **text**, in characters [SRC-004]. It takes
a String or a Char. Given a collection it is refused — `Length expects text; use
.Length for a collection.` — because a collection's count is a property
[COL-003] and the two are different questions.

⚠️ It measured **bytes** rather than characters until DEF-01, so
`Length ('café')` was 5. It is 4.

⚠️ It used to stringify whatever it was given, so `Length([10, 20, 30])` was
**12** — the length of the rendering — where `L.Length` is 3. The failure mode
was the bad one: a *plausible number* rather than an error, and the two are
never equal, since a List of *n* one-digit numbers renders as `3n` characters.

⚠️ A program that means the rendering writes `Length(Str(L))`, which is what it
was getting by accident.

    interpreter  compiler/Interpreter.a24  LengthNative
    compiler     bootstrap/algol.c         alg_text_length
    conformance  0115-length-refuses-a-collection.a24

**[RT-017]**  A `String` answers `Length` as a **property**, its count of
characters: `'abc'.Length` is 3. This is the same count `Length('abc')` gives,
and the same spelling every collection uses [COL-003].

⚠️ A String is already iterable [STM-007] and subscriptable [EXP-015]; not
answering for its own length was the odd one out. The **compiled** back end
answered 3 while the interpreter refused, which was C-9 — the fix closed the
divergence by bringing the interpreter to the compiler, one of only two rules
where that was the direction.

    interpreter  compiler/Interpreter.a24  VisitGetExpr
    compiler     bootstrap/algol.c         alg_property
    conformance  0114-string-length-property.a24

**[RT-004]**  `Copy(Text, Begin, Length)` takes a substring, counting from zero.
The length is clamped to what remains, so `Copy('abcdef', 3, 99)` is `def`. A
start outside the text is `Copy failed: Start -2 out of range 0..6.`

    interpreter  compiler/Interpreter.a24  CopyNative
    compiler     bootstrap/algol.c         alg_copy
    conformance  0089-text-builtins.a24

**[RT-005]**  `Pos(Text, Part)` answers the zero-based index of `Part` within
`Text`, or **-1** when it is absent.

    interpreter  compiler/Interpreter.a24  PosNative
    compiler     bootstrap/algol.c         alg_pos
    conformance  0089-text-builtins.a24

**[RT-006]**  `Str(V)` renders any value: an Integer bare, a Double always with
a point (`1.0`), a Boolean lowercase (`true`), `nil` as `nil`, a List as
`[10, 20, 30]`, a Map as `[1:2]`, and an instance by its `ToString` [CLS-009].

    interpreter  compiler/Interpreter.a24  Stringify
    compiler     bootstrap/algol.c         alg_str
    conformance  0090-str.a24

**[RT-007]**  `Ord(C)` answers the code point of a single character, as an
**Integer**. Anything longer is `Ord failed: 'ab' has no ordinal.`

    interpreter  compiler/Interpreter.a24  OrdNative
    compiler     bootstrap/algol.c         alg_ord
    conformance  0089-text-builtins.a24

**[RT-008]**  `Char(N)` answers the character with code point `N`, over the
range of [LEX-025] — 0 … 10FFFF, excluding the surrogates. `Ord` and `Char` are
inverse across it.

⚠️ `Char(0)` is legal here, and only the **literal** `#0` is refused
[LEX-032] — the scanner's own end-of-input sentinel is `Char(0)`.

    interpreter  compiler/Interpreter.a24  CharNative
    compiler     bootstrap/algol.c         alg_char
    conformance  0128-text-is-characters.a24
    refusal      0038-char-out-of-range.a24

### 16.3 Numeric

**[RT-009]**  `Val(S)` parses a number from text, answering an **Integer** where
the text has no point and a **Double** where it has one — reading the same
characters the literal rules do [LEX-015], [LEX-020]. Failure is `Val failed:
'abc' is not a number.`

⚠️ Text that is neither — `'1e5'`, which no literal rule spells [LEX-022] — is
a Double, since only an integer literal yields an Integer.

⚠️ **`Val` therefore has no static type**, and a checker cannot give it one: the
answer depends on the *content* of the text, not on its type. A typed
declaration needs a cast — `var D : Double := Val (S) as Double;` — which is
checked [VAL-007] and fails loudly when the text held the other kind. Declaring
`Val` to be Double, as this implementation once did, is a lie in both
directions: it refused `var I : Integer := Val ('42');`, which works.

    interpreter  compiler/Interpreter.a24  ValNative
    compiler     bootstrap/algol.c         alg_val
    conformance  0119-val-and-max.a24

**[RT-010]**  `Max(A, B)` takes any two numbers and promotes as every other
numeric operator does [EXP-005], so `Max(3.5, 2)` is `3.5`.

Anything that is not a number is `Max expects numbers.`

⚠️ **`Max`'s type comes from its arguments**, not from a table: two Integers give
an Integer and anything with a Double gives a Double. Declaring it Integer, as
this implementation once did, let `var M : Integer := Max (3.5, 2);` be accepted
and leave a **Double in an Integer** — a declared type violated with nothing
said, which is worse than refusing a correct program.

⚠️ **[RT-009] and [RT-010] were one defect, not two.** Individually each was
defensible; together they left `Max(Val(A), Val(B))` failing for **every**
input, so text holding two numbers could not be compared without going outside
both built-ins.

    interpreter  compiler/Interpreter.a24  MaxNative
    compiler     bootstrap/algol.c         alg_max
    conformance  0119-val-and-max.a24

**[RT-011]**  `Mod(A, B)` answers the remainder, whose sign follows the
dividend: `Mod(-7, 3)` is `-1`. A zero divisor is `Mod failed: Division by
zero.`

    interpreter  compiler/Interpreter.a24  ModNative
    compiler     bootstrap/algol.c         alg_mod
    conformance  0091-numeric-builtins.a24

**[RT-012]**  `clock()` answers the seconds since the epoch as a **Double**, at
millisecond resolution.

    interpreter  compiler/Interpreter.a24  ClockNative
    compiler     bootstrap/algol.c         alg_clock
    conformance  0091-numeric-builtins.a24

### 16.4 Environment

**[RT-013]**  `ParamStr(0)` is the program's own name and `ParamCount()` does
not count it, so a program run with no arguments reports zero.

    interpreter  compiler/Interpreter.a24  ParamCountNative
    compiler     bootstrap/algol.c         alg_param_count
    conformance  0092-environment-builtins.a24

**[RT-014]**  `FileExists(Name)` answers whether the named file exists.

    interpreter  compiler/Interpreter.a24  FileExistsNative
    compiler     bootstrap/algol.c         alg_file_exists
    conformance  0092-environment-builtins.a24

**[RT-015]**  `Write` and `WriteLn` write their stringified values to standard
output, `WriteLn` following them with `#10` — always that byte, never the host's
line separator, so one program writes the same bytes everywhere.

They take **any number of values** [RT-001], run together with nothing between
them, so `WriteLn ('ABC', 123)` writes `ABC123` and `WriteLn ()` is the newline
on its own.

    interpreter  compiler/Interpreter.a24  Rendered
    interpreter  compiler/Interpreter.a24  WriteLnNative
    compiler     bootstrap/algol.c         alg_writeln
    conformance  0093-write-and-writeln.a24
    conformance  0159-write-takes-any-number-of-values.a24

**[RT-016]**  `ReadLn` on a `TextFile` splits on the same rule as the scanner
[SRC-006], [SRC-007]: a line ends at `#10`, which is **not** returned; a `#13`
immediately before it comes off with it; and any other `#13` is ordinary text
returned as part of the line.

A file whose only line endings are `#13` is therefore read as a single line
containing those bytes.

    interpreter  compiler/ObjFile.a24  Invoke
    compiler     bootstrap/algol.c     file_read_line
    conformance  0008-readln-line-rule.a24

**[RT-019]**  A number answers `ToString`, which is `Str` by another spelling.
`5.ToString ()` is `'5'`.

⚠️ **C#'s arrangement, not Java's.** `5.ToString ()` works because an Integer is
a type with members, not because a box wraps a primitive. There is no second
kind of thing that compares differently under `=`, and nothing to unbox.
Java's `int`/`Integer` duality — two things with almost the same name behaving
differently — is what this avoids, and is the same objection [TYP-014] makes to
a `Real` that converts.

⚠️ **One rendering, so the two spellings cannot disagree.** `ToString` answers
exactly what `Str` does, including for a Double's shortest round-trip form and
for an Integer past the machine's width.

⚠️ **It reads without being called**, like every other member [COL-005]:
`var T := 7.ToString;` binds something callable and prints `<fn ToString>`
[TYP-012].

    interpreter  compiler/ObjFunction.a24  NumberMethod
    compiler     bootstrap/algol.c         number_method
    conformance  0156-number-members.a24

**[RT-020]**  `Succ(X)` and `Pred(X)` step an ordinal. A `Char` moves one code
point, an `Integer` moves one. `Succ ('a')` is `'b'` and `Pred (5)` is `4`.

Anything else is `Succ failed: 'X' has no ordinal.`, and a Char at the end of
the code-point range is `Succ failed: 'X' has no ordinal beyond it.`

⚠️ **An enum member is not stepped, and the gap is honest rather than chosen.**
Stepping one is the most Pascal use of `Succ` there is, but a member carries its
type's *name* and its ordinal rather than a pointer to the type, so there is no
way from a member to the list it belongs to. That link is a change of its own.

⚠️ **An Integer has no end to check** because it is unbounded [LEX-018]; a Char
does, stopping at U+10FFFF.

    interpreter  compiler/Interpreter.a24  SuccNative
    compiler     bootstrap/algol.c         alg_succ
    conformance  0167-character-arithmetic.a24

**[RT-018]**  `Halt(N)` ends the program at once with status `N`. Nothing after
it runs, and no enclosing `except` sees it — it is not an exception.

⚠️ **It is the only way a program can choose its own exit status.** Without it a
program that wants to exit non-zero has to `raise`, which prints `Uncaught: ` and
the raised value [ERR-008] — output the program did not ask for and cannot
suppress. `algc`'s own `--test` driver did exactly that, so a failing run printed
`Uncaught: Tests failed.` after the report, while the *compiled* form of the same
suite returned the status from `main` and printed nothing. That was the last line
on which the two processors disagreed.

⚠️ **Buffered output is flushed first.** `stdout` is block-buffered when it is
not a terminal, so ending the process without flushing discards whatever the
program has written — a report that halted would print nothing at all when
piped.

⚠️ The status is what the program passes. The host takes it modulo 256, as every
process exit status is; that is the operating system's rule, not this language's.

    interpreter  compiler/Interpreter.a24  HaltNative
    compiler     bootstrap/algol.c         alg_halt
    conformance  0134-halt.a24

---

## 17. Program initialization and execution

### 17.1 A program

**[INI-001]**  A program is one file. Its top-level statements are executed in
the order they are written, and there is no distinguished entry point — no
`main`, and no statement that begins execution.

⚠️ The compiled back end preserves this order too, and did not always: a bare
top-level block was deferred to the end of the program (C-11) and every module
body ran before any root statement (C-5). Both are closed, and
`conformance/0094` agrees through either processor.

    interpreter  compiler/Main.a24  Run
    conformance  0094-program-order.a24

**[INI-002]**  A **variable or constant** takes effect when its statement is
reached, so a name is undefined above its declaration [DCL-016]. A **function or
class** is visible throughout the file wherever it is written [DCL-006].

⚠️ A **variable** is still bound when its statement runs, and only a function or
a class is hoisted — `refusals/0033` pins the difference.

    interpreter  compiler/Interpreter.a24  Interpret
    conformance  0122-functions-are-hoisted.a24

### 17.2 Module initialization

**[INI-003]**  A `uses` loads and runs its module **at the point it appears**.
Root statements written between two `uses` clauses therefore run between the two
module bodies:

```
WriteLn ('1 root');          →  1 root
uses Alpha;                  →    Alpha body
WriteLn ('2 root');          →  2 root
uses Gamma;                  →    Gamma body
WriteLn ('3 root');          →  3 root
```

    interpreter  compiler/Interpreter.a24  VisitModuleStmt
    conformance  0095-module-init-order.a24

**[INI-004]**  A module is initialized once [MOD-003], and its imports are
initialized before it, so a module's own body may use anything it imported.

    interpreter  compiler/Interpreter.a24  VisitModuleStmt
    conformance  0095-module-init-order.a24

⚠️ **This follows from [INI-003] rather than needing its own mechanism**: a
module's `uses` clauses stand at the top of its body, so its initializer runs
them before its own statements. Compiled, the `uses` clause is what starts a
module — it used to run every module initializer before any root statement,
which is C-5.

### 17.3 Termination

**[INI-005]**  A program that reaches the end of its statements exits with
status **0**, and **only** such a program does. A run that never began — because
the file could not be read — is a failure and exits non-zero [INI-006].

⚠️ **No case in `conformance/` covers the second half, and none can.** Every
case is run by handing `algc` a file that exists, so a run that never began is
not reachable from inside the corpus. It is checked by hand:

```
$ bootstrap/algc /no/such/file.a24 ; echo $?
algc: cannot open /no/such/file.a24
70
```

It used to print that line and exit **0**, so the driver reported a failure and
reported success at the same time.

    interpreter  compiler/Main.a24  Main
    conformance  0094-program-order.a24

**[INI-006]**  Every failure the language reports exits with status **70** —
an uncaught `raise` [STM-021], and equally a scan, parse, resolution or type
error, which are reported before any statement runs.

    interpreter  compiler/Main.a24  CheckScanned
    compiler     bootstrap/algol.c  alg_error
    conformance  0096-exit-status.a24

> ⚠️ **One status for every kind of failure** is deliberate rather than
> unconsidered. A caller wanting to tell a compile error from a runtime one
> reads the diagnostic; the alternative — a second status for failures found
> before execution — buys a little for tooling and costs every existing caller a
> change. What was *not* deliberate was a failure exiting **0**, and that is fixed.

### 17.4 Arguments

**[INI-007]**  A program reads its command line through `ParamCount` and
`ParamStr` [RT-013]. `ParamStr(0)` is the program's own name, and arguments
follow from index 1.

    interpreter  compiler/Main.a24    ArgumentsFrom
    compiler     bootstrap/algol.c    alg_set_arguments
    conformance  0092-environment-builtins.a24

---

## 18. Errors

### 18.1 Phases

**[ERR-001]**  A program passes through five phases: **scan**, **parse**,
**resolve**, **check**, **run**. The first four complete over the whole program
— its imports included — before any statement is executed.

    interpreter  compiler/Main.a24  Run
    conformance  0097-error-phases.a24

**[ERR-002]**  An error in any of the first four phases means **no statement
runs at all**. A program cannot produce output and then fail to compile.

    interpreter  compiler/Main.a24  Run
    conformance  0097-error-phases.a24
    refusal      0008-declared-type-constrains.a24

**[ERR-003]**  A runtime error occurs during execution. Statements before it
have run and their output stands.

    interpreter  compiler/Interpreter.a24  Interpret
    conformance  0098-runtime-errors-follow-output.a24

### 18.2 Diagnostics

Diagnostics are part of the observable surface [1.2]; their wording and shape
are specified.

**[ERR-004]**  A **scan** error reads `[line N] Error: <message>` and carries no
source excerpt. Like every error in the first four phases it prevents execution
[ERR-002].

⚠️ **That is the whole of the requirement.** This rule previously went on to say
the error is "recorded rather than raised: the scanner sets a flag and keeps the
message, and a driver must ask" — which describes how *this* implementation
happens to work, not what an implementation must do. A specification that
mandates a mechanism forbids a better one; what matters is that the error is
reported in the shape above and that no statement runs. The mechanism, and the
hazard that comes with it, are recorded in Annex G, G.1.

    interpreter  compiler/Scanner.a24  HadError
    unit         Scan Unrecognized Character Is Recorded
    conformance  0099-scan-error-shape.a24

**[ERR-005]**  A **parse** or **resolution** error prints the message and a
three-line excerpt naming the file, the line, and the offending token:

```
Uncaught: Expect variable name.
[ERROR] e.a24: Expect variable name.
[ERROR] 2 | var := 1;
[ERROR]   | ^^^
```

    interpreter  compiler/Console.a24  Error
    conformance  0100-parse-error-shape.a24

**[ERR-006]**  A **type** error carries the same three-line excerpt a parse
error does [ERR-005], and names both types:

```
Uncaught: Expected Integer, found String.
[ERROR] e.a24: Expected Integer, found String.
[ERROR] 1 | var Count : Integer := 'text';
[ERROR]   |     ^^^^^
```

An expression the checker could not type at all is `an untyped expression`
rather than a type name:

```
Uncaught: Expected Integer, found an untyped expression.
```

⚠️ **The caret names the declaration or the assignment, not the offending
value.** A literal carries no token, so there is nothing inside the initializer
to point at without giving every expression one — and the message already names
both types, which is what the caret would otherwise have to convey.

⚠️ **This compounds with [ERR-002]:** a type error stops the program before any
statement runs, so there is no output to orient by either. The message is the
only information available, which is why it has to carry some.

    interpreter  compiler/TypeChecker.a24  Mismatch
    conformance  0108-type-error-shape.a24
    conformance  0109-type-error-untyped.a24

### 18.3 Catching

**[ERR-007]**  Only **runtime** errors are catchable, and they are caught as a
String carrying the diagnostic [STM-020].

    interpreter  compiler/Interpreter.a24  VisitTryStmt
    conformance  0101-catching.a24

**[ERR-008]**  A `try` around a scan, parse, resolution or type error catches
nothing, because those phases complete before the `try` is reached. Wrapping a
mistyped declaration in a handler does not suppress it.

    interpreter  compiler/Main.a24  Run
    conformance  0101-catching.a24

### 18.4 Status

**[ERR-009]**  Every failure exits with status **70**, whichever phase reported
it [INI-006].

⚠️ A failure that never reaches a phase at all — a file that cannot be read — is
still a failure and must not exit 0 [INI-005].

    interpreter  compiler/Main.a24  Main
    conformance  0096-exit-status.a24

### 18.4 Warnings

**[ERR-010]**  A **warning** reports a cost, not a fault. It is written with a
`[WARN]` tag in **yellow**, beside `[INFO]` and `[ERROR]`, and it is
**non-blocking**: the program compiles and runs exactly as it would without it,
and its exit status is unaffected [ERR-009].

One warning is raised. A call that will select among overloads **at run time**
[FUN-013] says so:

```
[WARN] spec/warning.a24:17: 'Log' selects among 3 overloads at run time.
```

⚠️ **The wording is checked against what is printed**, by `spec/spec.sh` running
`spec/warning.a24` — the treatment the keyword table, Annex B and [COL-003]'s
matrix already get, and for the same reason. A message quoted in a specification
and checked by nobody is the most rot-prone thing this document can hold.

⚠️ **It is not raised where a named argument decides the call** [EXP-013].
Naming the parameters identifies one signature, so nothing is left to select at
run time — the warning and its remedy arrived together, and a warning whose
remedy did not exist would point at nothing.

⚠️ **A warning is not a refusal, and the boundary matters.** Refusal is for what
the C back end cannot express; a construct that is legal and merely costly gets
a warning instead, which is what keeps `<X> is not supported by the C back end
yet.` meaning only one thing.

⚠️ **It is not part of a program's output**, and the corpus drops it from both
sides. The front end is shared, so the same warning appears when an interpreted
program *runs* and when a compiled one is *emitted* — different moments, so
comparing them would report a divergence where the two processors agree
completely. Dropped rather than suppressed: it is meant to be seen by whoever is
compiling, and only the comparison must not see it.

⚠️ **It is silent on this compiler.** No top-level name in `compiler/*.a24` is
overloaded, so `algc` compiling itself raises none at all — which is the
evidence that it is a scalpel rather than noise.

    interpreter  compiler/TypeChecker.a24  WarnIfDynamic
    interpreter  compiler/Console.a24      Warn
    conformance  0158-varargs-from-an-element-type.a24

---

## 19. Test blocks

A test block is a declaration that a test run executes and an ordinary run
ignores. The report it produces is specified line for line, because it is the
surface on which two implementations are compared.

### 19.1 Declaration

**[TST-001]**  A test is written `test` followed by a **quoted literal** naming
it, then a block.

```
TestDecl = "test" ( string_lit | char_lit ) ";" Block .
```

`test` is not a keyword [LEX-011]; it is recognised here by the quoted name that
follows it, so a variable may still be called `test`.

⚠️ **Either quoted form**, because the name is *text* and a one-character name is
an ordinary thing to write. `'X'` is a Char rather than a String [LEX-023], and
that distinction belongs to values rather than to a declaration naming itself.

    interpreter  compiler/Parser.a24  Declaration
    conformance  0102-test-declaration.a24
    conformance  0116-one-character-test-name.a24

**[TST-002]**  A test block is a declaration and does not run when the program
runs.

    interpreter  compiler/Interpreter.a24  HoistTests
    conformance  0102-test-declaration.a24

### 19.2 Running

**[TST-003]**  A test run executes the test blocks **instead of** the program.
The top-level statements do not run — only the declarations they would have
created.

    interpreter  compiler/Interpreter.a24  RunTests
    conformance  0103-a-test-run.a24

**[TST-004]**  Tests are collected from the root file and from every module it
reaches, each file contributing once however many ways it is reached.

    interpreter  compiler/Interpreter.a24  HoistTests
    conformance  0104-test-collection-and-order.a24

**[TST-005]**  Tests are reported **sorted by name within a file**, and files in
the order their first test was met — which for `uses` is load order. Source
order within a file is not preserved.

    interpreter  compiler/Interpreter.a24  RunTests
    conformance  0104-test-collection-and-order.a24

**[TST-006]**  A program's own `Write` and `WriteLn` output is **swallowed**
during a test run, so it cannot interleave with the report.

    interpreter  compiler/Interpreter.a24  SuppressOutput
    compiler     bootstrap/algol.c         alg_test_begin
    conformance  0103-a-test-run.a24

**[TST-007]**  A value raised inside a test body and not caught makes that test
**fail**; it does not end the run, and later tests still execute.

    interpreter  compiler/Interpreter.a24  RunTests
    compiler     bootstrap/algol.c         alg_test_run
    conformance  0105-report-format.a24

### 19.3 The report

**[TST-008]**  The report consists of these lines, in this order:

```
[INFO] Running N tests...
[INFO] < file >
[INFO] Test: <name> <leader> [ PASS ]
[ERROR] <file>: <message>          only after a FAIL, and only interpreted
[INFO]
[INFO] All N tests passed.
```

A file's block is opened by its `< file >` line, and a blank `[INFO] ` line
separates files and precedes the summary.

    interpreter  compiler/Interpreter.a24  Report
    compiler     bootstrap/algol.c         alg_test_run
    conformance  0105-report-format.a24

**[TST-009]**  The dot leader is `55 - Length(name)` dots, clamped to a minimum
of one, so a name longer than the banner still produces a well-formed line.

    interpreter  compiler/Interpreter.a24  Report
    compiler     bootstrap/algol.c         alg_test_run
    conformance  0106-dot-leader.a24

**[TST-010]**  The report is coloured, and the colours are part of it: the
`[INFO]` tag white and blue, `[ERROR]` white and red, the file name cyan, `PASS`
green, `FAIL` red, and the summary green when all passed and red otherwise.

⚠️ The escapes are emitted **unconditionally**, whether or not the output is a
terminal — the language has no way to ask — so anything reading a report strips
or transliterates them.

    interpreter  compiler/Console.a24  INFO
    compiler     bootstrap/algol.c     INFO_TAG
    conformance  0105-report-format.a24

**[TST-011]**  The summary is `All N tests passed.` or `N of M tests failed.`,
and the run exits **0** when every test passed and **70** when any failed.

    interpreter  compiler/Interpreter.a24  RunTests
    compiler     bootstrap/algol.c         alg_test_summary
    conformance  0103-a-test-run.a24

### 19.4 Assertions

**[TST-012]**  Three assertions exist, and only during a test run [RT-002]:

| Call | Message on failure |
| --- | --- |
| `AssertTrue(V)` | `Assertion failed.  Expected true but got 'V'.` |
| `AssertEqual(E, A)` | `Assertion failed.  Expected 'E' but got 'A'.` |
| `AssertEqual(E, A)`, where the two render alike | `Assertion failed.  Expected T 'E' but got U 'A'.` |
| `Fail(M)` | `Failed.  M` |

Two spaces follow the full stop in each.

⚠️ **The third form is not an alternative wording but a different case**, and it
is the reason the second is not enough: a `Char` and a `String` both render as
`3` and are never equal [LEX-026], so a message quoting only the rendered values
would read `Expected '3' but got '3'.` Naming the types is what makes that
legible. Both processors already do this, and it was missing from this table.

⚠️ Every form used to begin `Assertion 'left = right' failed.` — including
`AssertTrue`, which makes no comparison and has no left or right. The stem read
like a template nobody filled in.

⚠️ **The two processors disagreed here**, and nothing caught it: the C runtime
said only `Assertion failed.` for `AssertTrue`, with no value at all. A report
comparison drops the `[ERROR]` lines an assertion failure prints, so the one
message a programmer reads most often was outside everything that checks the two
against each other.

⚠️ Compiled, every one of these messages is printed, in the same words — see
C-23, where the premise that compiled code could not build the line was the part
that was wrong.

    interpreter  compiler/Interpreter.a24  AssertTrueNative
    compiler     bootstrap/algol.c         alg_assert_equal
    conformance  0132-assertion-messages.a24

**[TST-013]**  `AssertEqual` compares with `=` [VAL-009], so it promotes
numerically and holds a `Char` unequal to a `String` [LEX-026].

    interpreter  compiler/Interpreter.a24  AssertEqualNative
    conformance  0107-assert-equal-comparison.a24

### 19.5 Compiled runs

**[TST-014]**  The report is **the same from any implementation**, line for
line and colour for colour. It is the surface on which two implementations are
compared, so a difference in it is a difference in conformance and not a matter
of presentation.

⚠️ **Both processors meet this**, line for line and colour for colour, over the
whole suite — which is the strongest available check that the two implementations
agree, since a test report is built from almost everything the language has.

⚠️ The compiled report used to omit the `[ERROR]` line after a failure (C-3), on
the premise that compiled code carries no line information to build one from.
Only the *caret* lines need a source position; the message line carries the file
name and the message and nothing else.

⚠️ This rule previously stated only that the compiled report differs, which said
nothing about what an implementation must **do**. The requirement is agreement,
and it is now met.

    interpreter  compiler/Interpreter.a24  Report
    compiler     bootstrap/algol.c         alg_test_run
    conformance  0105-report-format.a24

---

## Annex A — grammar summary *(non-normative)*

Every production stated in the chapters, collected. This annex adds nothing:
each line appears in the chapter that specifies it, and `spec/spec.sh` checks
that none has been added here or lost from here.

⚠️ **The grammar is partial, deliberately.** Where a construct's shape was
verified by running it rather than by writing a production, the chapter states
it in prose and no production appears below. The gaps are named at the end of
this annex rather than filled with plausible-looking rules, because a production
nobody checked is exactly the kind of claim this specification exists to avoid.

### Lexical

```
letter          = "a" … "z" | "A" … "Z" | "_" | unicode_letter .
decimal_digit   = "0" … "9" .
hex_digit       = decimal_digit | "a" … "f" | "A" … "F" .
binary_digit    = "0" | "1" .
identifier_mark = "?" | "!" .

identifier      = letter { letter | decimal_digit | identifier_mark } .

integer_lit     = decimal_lit | hex_lit | binary_lit .
decimal_lit     = decimal_digit { [ "_" ] decimal_digit } .
hex_lit         = "0x" hex_digit { [ "_" ] hex_digit } .
binary_lit      = "0b" binary_digit { [ "_" ] binary_digit } .

double_lit      = decimal_lit "." decimal_lit [ exponent ] | decimal_lit exponent .
exponent        = ( "e" | "E" ) [ "+" | "-" ] decimal_lit .

char_lit        = "'" source_character "'" | "#" decimal_digit { decimal_digit } .
string_lit      = "'" { source_character_other_than_quote | "''" } "'" .
```

### Declarations

```
VarDecl    = "var" identifier [ ":" Type ] [ ":=" Expression ] ";" .
ConstDecl  = "const" identifier [ ":" Type ] ":=" Expression ";" .
Type       = identifier [ "of" identifier ] .

VarSection = "var" { identifier { "," identifier } [ ":" Type ]
                     [ ":=" Expression ] ";" } .

FunDecl    = ( "function" | "procedure" ) identifier "(" [ Params ] ")"
             [ ":" Type ] ";" [ Sections ] Block .
Params     = identifier [ ":" Type ] { "," identifier [ ":" Type ] } .

ClassDecl  = "class" identifier [ "(" identifier ")" ] ";"
             [ Sections ] "begin" { Member } "end" .
EnumDecl   = "type" identifier "=" "(" identifier { "," identifier } ")" ";" .
SubrangeDecl = "type" identifier "=" bound ".." bound ";" .
bound      = [ "-" ] integer_lit .

UsesStmt   = "uses" ( identifier | string_lit ) ";" .
TestDecl   = "test" string_lit ";" Block .
```

### Statements

```
CaseStmt = "case" Expression "of" { Arm } [ "else" Statement ] "end" .
Arm      = Expression { "," Expression } ":" Statement .
GotoStmt = "goto" identifier ";" .
```

### What is specified in prose instead

These constructs are specified by rule and verified by probe, without a
production:

| Construct | Specified by |
| --- | --- |
| Operator precedence and associativity | [EXP-001], [EXP-002] — a table, derived by running distinguishing cases |
| `if`, `while`, counted `for`, `for … in` | [STM-003] … [STM-007] |
| `break`, `Exit`, `raise`, `print` | [STM-010], [STM-014], [STM-016], [STM-022] |
| `try` / `except` / `on` handlers | [STM-017] … [STM-019] |
| Blocks and expression statements | [STM-001], [STM-002] |
| Visibility sections | [DCL-011], [DCL-012] |

⚠️ `Sections`, `Block`, `Member` and `Statement` are referenced above and not
themselves defined. Completing the grammar is worth doing; inventing those four
productions from memory is not.

---

## Annex B — index of built-in functions *(non-normative)*

The twenty-eight built-in names, with the rule specifying each. `spec/spec.sh`
checks this list against the names the interpreter actually registers.

| Name | Rule | Summary |
| --- | --- | --- |
| `AssertEqual` | [TST-012] | Fails unless two values are equal; test runs only |
| `AssertTrue` | [TST-012] | Fails unless a value is truthy; test runs only |
| `Fail` | [TST-012] | Fails outright with a message; test runs only |
| `Halt` | [RT-018] | Ends the program with a chosen exit status |
| `Array` | [COL-002] | An Array of N elements, each `nil` |
| `Buffer` | [E.2] | Growable bytes with an explicit lifetime |
| `List` | [COL-002] | An empty List |
| `Map` | [COL-002] | An empty Map |
| `Set` | [COL-002] | An empty Set, or a Set of a collection's values |
| `Stack` | [COL-002] | An empty Stack |
| `Char` | [RT-008] | The character with a code point, 0 … 10FFFF, surrogates excluded |
| `Copy` | [RT-004] | A substring, from a zero-based start, length clamped |
| `Length` | [RT-003] | ⚠️ The length of the argument's **text**, not a count |
| `Ord` | [RT-007] | The code point of one character, as an Integer |
| `Succ` | [RT-020] | The next ordinal — a Char or an Integer |
| `Pred` | [RT-020] | The previous ordinal, on the same terms |
| `Pos` | [RT-005] | A zero-based index, or -1 when absent |
| `Str` | [RT-006] | Any value rendered as text |
| `Val` | [RT-009] | A number parsed from text — an **Integer** without a point, a Double with one |
| `Max` | [RT-010] | The greater of two numbers, promoting as arithmetic does |
| `Mod` | [RT-011] | The remainder, its sign following the dividend |
| `clock` | [RT-012] | Seconds since the epoch, as a Double |
| `FileExists` | [RT-014] | Whether a named file exists |
| `TextFile` | [E.2] | A text file handle |
| `ParamCount` | [RT-013] | The argument count, not counting the program |
| `ParamStr` | [RT-013] | An argument by index; 0 is the program |
| `Write` | [RT-015] | Writes a value |
| `WriteLn` | [RT-015] | Writes a value and `#10` |

⚠️ `clock` is the only built-in spelled in lower case, and the only one whose
name is not a noun or an imperative. Nothing depends on this; it is noted
because a reader will wonder.

---

## Annex C — compiler divergences *(non-normative)*

Where the C back end does not do what the interpreter does. The interpreter is
the authority [1.1], so every entry here is a defect in the compiler rather than
a choice the language has made.

⚠️ **Every entry is withdrawn**, and `./conform.sh` reports no gap. They are
kept because each records what was actually wrong — which in a dozen cases is
not what the entry first said, and in several is a mistake in the fix the entry
itself proposed. Two were the *interpreter's* fault rather than the compiler's
(C-4, C-37), which the classification above does not admit and which is worth
seeing.

⚠️ A **loud** divergence refuses to compile and says why. A **silent** one
produces a program that runs and behaves differently. The second kind is far
worse, and the column says which each is.

⚠️ **Nothing here is tracked by a suite of its own.** A divergence is not a third
kind of case; it is an *outcome*. Every case in `conformance/` runs under both
processors, and a case the interpreter gets right and the compiler does not
fails its compiled half — that failure **is** the record of the divergence, and
`conform.sh` calls it a gap. **A gap fails the run**, from Generation 3 onward;
through Generations 1 and 2 it was reported instead, while the compiler was
deliberately allowed to trail. The classification of a case never depends on the
compiler's state:

| The interpreter is | The case goes in |
| --- | --- |
| right | `conformance/` or `refusals/`, even if the compiler is wrong |
| wrong | `defects/`, even if the compiler is right |

This follows the generation plan rather than tidiness. The goal of the first of
those generations was an interpreter that matches this specification; of the one
after, a compiler that matches the interpreter. Compiler gaps were therefore
**expected** to be red throughout the first, and the count was the progress
measure for the second. It has reached zero.

⚠️ The one thing that must not break is the compiler's ability to **build and
reproduce itself** — `./fixedpoint.sh` and `./test.sh`. A compiler that cannot
compile cannot produce the generation that fixes these entries.

⚠️ **An opt-out records nothing and notices nothing.** Twelve conformance cases
once carried a `// compiled: no` marker to keep the suite quiet. C-14 was found
within minutes of removing them, in a case that had been opted out since it was
written — and C-9, C-11 and C-13 had no reproduction at all while the markers
stood.

**C-1 — A file in an import cycle with the root will not compile.**
***Withdrawn.***

The root file was never entered in the parser's `Loaded` map, so a module
importing the root back parsed it a second time and the emitter saw two units of
one name — `Two modules named 'Parser' is not supported by the C back end yet.`
This was the only known case of a valid program having no compiled form.

⚠️ **Withdrawn because the cause was removed, not because the emitter changed.**
The root is registered as a module now [MOD-014], so the duplicate the emitter
was refusing no longer exists. `--compile --test compiler/Parser.a24` emits, and
`conformance/0125` compiles and runs identically to the interpreted form.

⚠️ The number is not reused. A withdrawn entry stays where it is, because the
divergence it described was real and citing it should keep working.

**C-2 — Functions may not nest more than one level deep.**
***Withdrawn.***
*(refers to [FUN-012])*

```
A function nested more than one level deep is not supported by the C back end yet.
```

Three levels of nesting ran correctly interpreted and refused to compile.

⚠️ **One missing case, not a missing mechanism.** A nested function is emitted
as a file-scope C function plus a closure over an array of heap cells, and a
cell was reachable in only one shape: a `c_x` local the enclosing function
declared. At depth two the enclosing function is *itself* nested, so the cells
it was **handed** are as much in scope where the inner declaration stands as the
ones it made — and those can only be named `cells[i]`. A capture list written
with the local form alone named locals that do not exist, so the refusal stood
in for the second shape.

⚠️ **The handed-down cells come first and in index order**, because the
receiving function reads them as `cells[i]` and the indices have to line up with
the array the closure is built from.

⚠️ **A function declared inside a METHOD is still refused**, and is a different
thing: a method's C function takes a receiver and no cell array, and a nested
function there closes over `this` as well as over the locals. Recorded as C-38.

**C-3 — A compiled assertion failure carries no message.**
***Withdrawn.***

`alg_test_run` printed no `[ERROR]` line, so the `FAIL` stood alone where the
interpreter also gave the assertion message. It prints the same line now — see
C-23, which is where the fix and the reasoning live.

⚠️ **The premise was wrong, not just the behaviour.** This entry said compiled
code "has no line information to put in one", and inferred from that that the
whole line was unreproducible. Only the *caret* lines need a source position;
the message line carries the file name and the message and nothing else.

**C-4 — Collection member names are matched case-insensitively.**
***Withdrawn.***
*(refers to [COL-006])*

```
var L := [1];
L.add (2);
```

Interpreted this is `Undefined property 'add'.` Compiled it works, and the
program prints a length of 2.

⚠️ This is the first **silent** divergence recorded, and it runs in the more
dangerous direction: the compiler **accepts a program the language refuses**. A
program developed against the compiler can use lowercase member names
throughout and fail everywhere the moment it is run interpreted, with no warning
from either processor that the two disagree.

The C runtime compares collection members with `alg_stricmp`, which is
deliberate — but `bootstrap/algol.h` asserted alongside it that this was "what
the interpreter does", and it is not. That comment has been corrected.

⚠️ **Withdrawn in the compiler's favour**, which is the opposite of what this
entry proposed. [SRC-011] folds *every* name, so a built-in member is a name like
any other and `alg_stricmp` was right all along. The interpreter is what changed:
`ObjCollection`, `ObjFile` and `ObjBuffer` fold the incoming member and their
comparison literals are written folded to match.

⚠️ The entry's proposed fix — compare exactly in `alg_property` and `alg_invoke`
— would have been **wrong**, and it was written before [SRC-011] was enforced
anywhere. That is the hazard of recording a remedy alongside a divergence: the
divergence was real and the remedy assumed which side was at fault.

The number is not reused.

**C-5 — Module bodies run at a different time.**
***Withdrawn.***
*(refers to [INI-003], [INI-004])*

Interpreted, a `uses` runs its module where it appears, so root statements
interleave with module bodies in source order. Compiled, every module
initializer runs before any root statement.

```
WriteLn ('1 root');        interpreted        compiled
uses Alpha;                 1 root              Alpha body
WriteLn ('2 root');           Alpha body        Gamma body
uses Gamma;                 2 root              1 root
WriteLn ('3 root');           Gamma body        2 root
                            3 root              3 root
```

⚠️ Silent, and unlike C-4 it needs no unusual spelling to provoke: any program
whose modules print, open a file, or set a variable the root then reads will
behave differently under the two processors, and nothing warns.

The compiled shape follows from how the C is emitted — `main` calls each
`init_<Unit>()` and then `init_Main()` — and it is the easier order to produce,
since a module's initializer is a function and the root's body is not special.

The interpreter is the authority [1.1], so the compiler was wrong.

⚠️ **The `uses` had been filtered out of the statements entirely**, which is why
the emitter had no way to say *when*. It was split off as an import and dropped;
keeping it is most of the fix, and `VisitModuleStmt` — until now nothing but a
refusal for a nested `uses` — writes the call. `main` starts the root and
nothing else. [INI-004] then follows from the same mechanism rather than needing
its own: a module's `uses` clauses stand at the top of its body, so its
initializer runs them before its own statements.

⚠️ **A `uses` runs under `--test` too**, and had to be added to the set of
statements a test run keeps. Only the file being *tested* has its program held
back; while `main` started every module itself this did not matter, and the
moment the clause became what starts one, leaving it out would have given a test
run no modules at all.

⚠️ **Hoisting a class had to become conditional, and this is where the fix
turned out to be about more than order.** A class is built ahead of its file's
statements only when its parent is absent or is another class of the **same
file** — `Interpreter.Hoist`'s rule, which the emitter did not have. It built
every class in `Setup`, before any statement, and that was indistinguishable
from correct only because every module initializer ran first. With modules
starting at their clause, a class inheriting from one had to be built where its
declaration stands.

⚠️ **And that exposed a silent divergence hiding inside this one.** A class
inheriting from a module named *below* it is `Undefined variable 'Shape'.`
interpreted — nothing has bound the name yet — and compiled it *ran*, because
the parent's shell had been built before any statement. The compiler accepted a
program the language refuses. `alg_class_declared` reports the name, and
`conformance/0146` and `0147` pin both orders.

**Not a divergence, and worth stating as a requirement:** interpreted and
compiled `--test` reports are byte-identical, colour included — 239 lines and
1,416 escape sequences for the full suite. Any difference between them is a
defect in one or the other.

---

**C-6 — Reading a method as a property crashes the compiled program.**
***Withdrawn.***
*(refers to [TYP-012])*

```
class Box;
begin
    function Size (); begin Exit 7; end
end

var B := Box ();
WriteLn (B.Size ());
WriteLn (B.Size);
```

Interpreted this prints `7` and then `<fn Size>`, which is what [TYP-012]
requires. Compiled it dies of `SIGSEGV` (exit 139) with **no output at all** —
the earlier `WriteLn` is lost with the buffer.

⚠️ This is the most serious divergence recorded so far, and it is worse than
C-4. C-4 accepts a program the language refuses; this one takes a program both
processors accept and crashes it, without a diagnostic, in the processor that is
supposed to be the fast one. `alg_property` has no case for a method reached
without a call.

⚠️ **The fault was in `as_text`, not in `alg_property`.** This entry blamed the
property lookup, which had handled a bare method for some time. `as_text` had no
case for a bound method and fell through to `collection_text`, which casts
anything that is not a Map to `ObjSeq *` and reads a count out of it. Both
processors print `<fn Length>` now.

⚠️ **`collection_text` was a catch-all and is not one any more**, which is the
half that mattered beyond this entry. Any heap object of an unhandled kind
reaching it crashed rather than saying anything; it names the kind and raises
now. A missing case should be a diagnostic, not a wild read.

⚠️ It closed by repair rather than by removal. H-6 once proposed making a bare
`B.Length` an error and retiring the construct instead; that proposal has since
been withdrawn — reading a method as a value is specified [FUN-011] and stays —
so the repair is now the whole answer rather than an interim one.

**C-7 — Four runtime diagnostics are worded differently.**
***Withdrawn.***
*(refers to [TYP-009], [TYP-010])*

| Program | Interpreted | Compiled |
| --- | --- | --- |
| `List ().ClassName` | `Undefined property 'ClassName'.` | `Only instances have properties.` |
| `B[0]` on an instance | `Subscript target should be an ordinal.` | `Only a collection or a String can be subscripted.` |
| `C (1, 2)` on a class with no constructor | `Expected 0 arguments but got 2.` | `This class takes no constructor arguments.` |
| `Colour.Nope` | `Undefined enum member 'Nope'.` | `That enum has no such member.` |

Both processors refuse every one of them, so nothing runs that should not — but
the text differs, and [ERR-002] requires a diagnostic to be the same wherever it is
produced.

⚠️ **This entry recommended the wrong direction**, and the rules settle it. It
argued that the compiled wording was better and that the interpreter should move
toward the compiler. But all four texts are *pinned by rules* — [TYP-009],
[TYP-010], [EXP-011] and [ENU-004] each quote the interpreted wording — so the
compiler was simply wrong, and it moved.

⚠️ The aesthetic argument survives the fix and is worth keeping: `Subscript
target should be an ordinal.` does describe the *subscript* when the fault is the
*target*. That is a case for changing [TYP-010], which belongs in Annex D as a
proposal, not in the runtime as a divergence. Nothing here forecloses it.


**C-8 — An uncaught runtime error carries no `Uncaught:` prefix.**
***Withdrawn.***

| | |
| --- | --- |
| Interpreted | `Uncaught: Index 5 out of range 0..2.` |
| Compiled | `Index 5 out of range 0..2.` |

The message is identical; only the prefix the driver adds is missing.

⚠️ **Narrower than it was first recorded.** This entry said "every conformance
case ending in a runtime error meets this". It applies only to an error raised
by the **runtime** — a division by zero, a subscript out of range, no matching
signature. Two cases keep the prefix and were wrongly marked as meeting it:

| | |
| --- | --- |
| An explicit `raise` | prefix present in **both**; `raise 'boom'` gives `Uncaught: boom` either way |
| A scan, parse or type error | prefix present in **both**, because the front end is shared [1.1] |

The correction came from running the two processors against four cases whose
comments claimed a divergence they did not have.

⚠️ Unlike C-3, this was not a consequence of compiled code lacking line
information — the prefix needs nothing the compiled program does not have.

⚠️ **One line, and twelve cases.** `alg_raise` printed the prefix on its uncaught
path and `alg_error` did not, so an error raised by the *runtime* lost it while
an explicit `raise` kept it. That asymmetry inside one file is what made the
entry look larger and vaguer than it was: it was first recorded as "every
conformance case ending in a runtime error", narrowed once by testing, and is
in fact a single `fprintf`.


**C-10 — The compiled back end hoists variables.**
***Withdrawn.***
*(refers to [DCL-016])*

```
WriteLn (V);
var V := 7;
```

Interpreted this is `Undefined variable 'V'.` Compiled it printed `nil`.

Every top-level name is emitted at C file scope, so it exists from the start of
the program; a variable simply held `nil` until its initializer ran.

⚠️ **This was the silent direction again, and the worst instance of it.** The
compiler did not merely accept a refused program — it substituted a **value**
for a diagnostic, so the program ran to completion with `nil` where a number was
meant, and nothing anywhere said so.

⚠️ **The compiler was only half wrong.** Hoisting a *function, class or enum* is
what [DCL-006] requires, and the interpreter does it. Hoisting a *variable* is
what [DCL-016] forbids. One mechanism, correct for three kinds of declaration
and wrong about the fourth, which is why it took a rule split to describe — and
why the fix could not be to stop emitting names at file scope.

⚠️ **A `d_` bool beside the `v_` storage, and a RUNTIME check.** Nothing the
emitter can see decides it: a read may sit inside a function declared above the
variable and called from below it, which is legal and ordinary, so
`function Peek (); begin Exit Later; end` is correct or an error depending on
when `Peek` is called.

⚠️ **A bool rather than a sentinel `Value`**, so that nothing the language can
hold ever means "not yet declared". A sentinel could be printed, compared or
widened by any read the emitter failed to guard; the worst a missed guard can do
here is what the emitter already did.

⚠️ **An assignment is checked too.** A variable is bound by its *declaration*,
not by being written to, so `V := 5;` above `var V := 7;` is the same error a
read gets rather than a store the declaration then overwrites.

**C-11 — A top-level block is reordered.**
***Withdrawn.***

```
WriteLn ('one');
begin
    WriteLn ('two');
end
WriteLn ('three');
```

| Interpreted | Compiled |
| --- | --- |
| `one two three` | `one three two` |

A bare `begin` … `end` at the top level runs **in place** interpreted and
**after every other top-level statement** compiled. With two such blocks, both
are deferred and run in their own order at the end.

⚠️ **A counted `for` is affected too, and that is the case that matters.**
[STM-006] desugars it into a block holding the initializer and a `while`, so a
top-level counted loop is a top-level block and is deferred with the rest:

```
WriteLn ('one');
for var I := 1; I <= 2; I := I + 1 do WriteLn ('  loop ' + Str (I));
WriteLn ('two');
```

| Interpreted | Compiled |
| --- | --- |
| `one` `loop 1` `loop 2` `two` | `one` `two` `loop 1` `loop 2` |

A bare block at the top level is rare; a counted loop is ordinary code, so the
divergence is far more reachable than the entry first suggested. It was found by
running the first three-line program written to try the VS Code **Run Both**
command.

⚠️ **Scoped by running each shape.** These are *not* affected, because the block
in each is a body rather than a top-level statement: a `while` with a block
body, a `for … in`, and an `if`.

⚠️ **Statement order is not preserved**, which makes this the most damaging
silent divergence recorded. C-6 crashes, which is at least noticeable; C-10
substitutes `nil` for a diagnostic, which a careful reader may spot. This one
runs every statement, produces no error, and simply performs them in a different
order — so a program whose blocks write files, print, or set variables the rest
of the file reads will behave differently under the two processors with nothing
to indicate it.

The emitter treated a top-level block as the program's main body, which is right
for the one block a program conventionally ends with and wrong for a block
appearing anywhere else.

⚠️ **Deferring was unnecessary as well as wrong.** Its stated purpose was to run
the program body after every module had initialized, and that already held: the
root's initializer is the *last* one `main` calls. Every top-level statement is
emitted in order now, blocks included.

⚠️ **C-13 was the same bug**, reached through a counted loop rather than a bare
block, and closed with it.

⚠️ `conformance/0039` differed after this for a different reason: with the block
correctly scoped, a name read after the `end` does not exist, and the emitter
wrote a reference to it rather than refusing by name. That was C-34, and it is
closed too.

⚠️ It used to constrain the conformance corpus: a case using a bare top-level
block to demonstrate scoping could not be run under both processors.
`conformance/0040` puts its blocks inside procedures for exactly this reason,
which keeps the cross-check.


**C-13 — Two counted `for` loops sharing a variable name at the top level emit
invalid C.**
***Withdrawn.***
*(refers to [STM-006], [DCL-008])*

```
for var I := 0; I < 2; I := I + 1 do Write (I);
for var I := 0; I < 2; I := I + 1 do Write (I);
```

```
error: redefinition of 'v_I'
```

[STM-006] desugars a counted `for` into a block holding the initializer and a
`while`, which is why its variable is scoped [DCL-008]. At the top level the
emitter does not open a C block for it, so both loops declare `v_I` in one
scope. Inside a function or method it is emitted correctly, which is why the
compiler compiles itself — all sixty-eight of its own counted loops are inside
one.

⚠️ **The emitter breaks its own contract here.** It is supposed to refuse by
name what it cannot emit rather than emit something wrong. Instead it produces C
that `cc` rejects, so the diagnostic names `v_I` and a line in a generated file
rather than the loop the programmer wrote. A refusal from `algc` would be
strictly better than a valid-looking emission that fails downstream.

⚠️ **The same bug as C-11**, and closed with it. A top-level block was pulled
out and run at the end; a counted `for` desugars into a block, so an ordinary
loop was deferred and two of them declared one variable in one C scope. Every
top-level statement is emitted in order now, and a block opens a C block, so its
variable is a local.

⚠️ It constrained the corpus while it stood: `conformance/0054` puts its loops
inside a procedure, as `conformance/0040` does for C-11. Neither needs to now.


**C-14 — Compiled code does not check arity.**
***Withdrawn.***
*(refers to [EXP-011])*

```
function One (A); begin Exit A; end
WriteLn (One (1, 2));
WriteLn ('kept going');
```

Interpreted this is `Uncaught: Expected 1 arguments but got 2.` Compiled it
printed `1` and then `kept going` — the extra argument was discarded and the
program ran on. Too *few* arguments was accepted as well, and read past the end
of the argument array.

⚠️ **This was invisible while `conformance/0049` opted out of the compiled
half.** It was found within minutes of removing the opt-outs, which is the
argument for not having them: an opt-out records nothing and notices nothing,
and the case it silences is exactly the case that would have found the bug.

⚠️ **Only one call shape was unguarded, not all of them.** A nested function is
reached through `alg_call` and a method through `alg_invoke`, and both compared
counts already. A **top-level subprogram** is called by its own C symbol —
`f_one(NULL, args, 2)` — so nothing sits between the call and the body. The
check is emitted in the *callee*, for the reason `alg_param` is: the declared
arity is already there, and one place answers for every call site. Top-level
overloads are refused by name (C-2), so a symbol has exactly one arity.

⚠️ **Two different failures, and they are not interchangeable.** A subprogram
with one signature reports the counts. A **method** reports `No matching
signature for function.`, because arity is only part of what it selects on
[EXP-014] and a wrong count is one way for nothing to fit — there is no single
expected count to name. The runtime said `Wrong number of arguments.` for the
method case and `Wrong number of arguments to Init.` for a constructor, neither
of which any interpreted run produces; `0049` now pins all four shapes.

**C-15 — A call to an object will not compile.**
***Withdrawn.***
*(refers to [CLS-016])*

```
object Config;
begin
    function Value (); begin Exit 1; end
end
WriteLn (Config ());
```

```
A call to 'Config' is not supported by the C back end yet.
```

Interpreted the program runs until the call, which raises `Can only call
functions and classes.` [CLS-016].

The same refusal covers a call the emitter has no case for at all:

| Program | Interpreted | Compiled |
| --- | --- | --- |
| `Config ()` on an object | `Can only call functions and classes.` | `A call to 'Config' is not supported…` |
| `AssertTrue (True)` outside a test run | `Undefined variable 'AssertTrue'.` | `A call to 'AssertTrue' is not supported…` |

⚠️ The second is worth noticing because the interpreter is right for a reason
the emitter does not share: the assertions are registered **only while `--test`
is running** [RT-002], so outside one the name is simply not there. The emitter
sees a call to a name it cannot resolve and refuses it as unsupported, which
describes the emitter rather than the program.

⚠️ The program is a **valid** one whose defined behaviour is to raise. The
emitter refused it rather than emitting something that raises, so a program the
language merely rejects at run time had no compiled form at all. That was the
right way round for a gap — loud, named, and impossible to miss — but it was
still a program the two processors did not agree on.

⚠️ **The runtime already had the wording.** `alg_call` says `Can only call
functions and classes.` for anything that is not callable, so emitting the call
rather than refusing it produces the language's own message: the singleton is
built first, as the interpreter evaluates the callee first, and handed to
`alg_call` like any other value. Both rows of the table above are closed — the
second by C-33, and for the same reason: neither program is one the back end
cannot express.

**C-16 — Inheriting from a non-class emits invalid C.**
***Withdrawn.***

*(refers to [CLS-014])*

```
var X := 1;
class C (X);
begin
end
```

```
error: use of undeclared identifier 'k_X'
```

The emitter writes `alg_class("C", k_X)` for a superclass that is not a class,
and `k_X` names a class handle that was never emitted because `X` is a variable.
The interpreter refuses the program with `'X' is not a class.`

⚠️ **The emitter broke its own contract**, as C-13 did: it is supposed to refuse
what it cannot emit, and instead produced C that `cc` rejected, naming a
generated symbol rather than the declaration the programmer wrote.

⚠️ **It refuses with the LANGUAGE's message**, not with "not supported by the C
back end yet" — this is a program that is *wrong*, not one this back end cannot
express. Both processors now say `'X' is not a class.` and the case stopped
being a gap rather than merely becoming a tidier one.

⚠️ **The emitter is the last chance to catch it.** The interpreter checks the
superclass when the declaration *runs*; a compiled program never runs its
declarations at emit time, so nothing else would have said anything.


**C-17 — An enum member has no properties compiled.**
***Withdrawn.***
*(refers to [ENU-010])*

`RED.Ordinal` was `Only instances have properties.` compiled, where the
interpreter answers `0`.

⚠️ **New in generation 1**, and expected: the interpreter gained the property
and the C runtime had not. `alg_property` needed the case `ObjEnum` had gained.

⚠️ **The ordinal was already there to answer with.** The runtime has carried it
since enums were emitted at all, because truthiness reads it — the first member
of every enumeration is falsey [ENU-009] — so a compiled program was governed by
a number it had no way to read, and could discover whether a member was falsey
only by testing it for truth.

**C-18 — `Length` of a collection is not refused compiled.**
***Withdrawn.***
*(refers to [RT-003])*

`Length([10, 20, 30])` is refused interpreted — `Length expects text; use
.Length for a collection.` — and compiled it returned the length of the
rendering, as the interpreter used to.

⚠️ **Silent, and the same trap the interpreter had just lost**: a plausible
number rather than an error.

⚠️ **The cause was one C function doing two jobs.** `Length(X)` and `X.Length`
are spelled alike and are not the same operation — one measures text, the other
answers a count — and the emitter mapped both onto `alg_length`, keyed by arity
so that it could. `alg_text_length` is the function; `alg_length` stays the
property. The comment on the emitter's builtin table asserted the two "mean the
same thing", which is what made the conflation look deliberate.

**C-19 — A cast is not checked compiled.**
***Withdrawn.***
*(refers to [VAL-007])*

```
var Bad : Any := 'text';
WriteLn (Bad as Integer);
```

Interpreted this is `Cannot cast String to Integer.` Compiled it printed `text`,
which is what the interpreter did before DEF-12.

⚠️ **The most consequential divergence recorded.** [VAR-006] routes every
untyped-to-typed crossing through `as`, so a compiled program had no verified
boundary anywhere: a value of the wrong type passed into a declared type and
nothing said so. The parser stored the cast on the expression and the emitter
read the field nowhere.

⚠️ **Fixed in the one place the interpreter fixes it.** `as` sets a *field* on
an expression rather than wrapping it, so both processors check it in their own
`Evaluate` — the single point every expression passes through, whatever its
shape. `alg_cast` is `alg_is` made a requirement, and parts company with it on
exactly one value: `nil` satisfies every type [VAR-005] and so passes every
cast, where it `is` nothing.

⚠️ The *precedence* half of the same work needed nothing: [EXP-003] is a parsing
rule and the front end is shared, so both processors already agreed that
`False and 5 as Integer` is `False`.

The compiled compiler runs its own 221 tests with every cast in its sources now
checked, and reports identically to the interpreted run — which is the evidence
that the check is the interpreter's and not a stricter one.

**C-20 — Two enumerations binding one member is refused compiled.**
***Withdrawn.***

Two enumerations may share a member name [ENU-003] and the interpreter runs the
program, refusing only the ambiguous bare use [ENU-011]. The emitter refused the
whole program with `Two enumerations binding 'A' is not supported by the C back
end yet.`

⚠️ **It used to be silent, and that was worse.** The emitter keys each member's C
symbol by the member name alone, so the second enumeration's entry overwrote the
first's and the first's members began resolving to the second's symbols. The
ambiguous use that [ENU-011] refuses printed a member instead. The refusal was
added deliberately, in preference to emitting a wrong answer.

⚠️ **The symbols were never the problem**, which is why the recorded fix — "key
the member map on the owning enumeration" — was aimed at the wrong thing. A
member's symbol already carries its type [G.3], and the *qualified* form goes
through `alg_property` on the enumeration rather than through the map at all.
Only the **bare** name has two answers, and having two answers is exactly what
[ENU-011] makes an error. So the ambiguity is carried to the use and reported
there, in the interpreter's words, after everything above it has run —
`Environment.Ambiguous` is consulted at the same moment for the same reason.

**C-21 — Two modules exporting one name is refused compiled.**
***Withdrawn.***

Two imported modules may export one name [MOD-008] and the interpreter runs the
program, refusing only the ambiguous bare use [MOD-013]. The emitter refused with
`Two modules exporting 'Shared' is not supported by the C back end yet.`

⚠️ Two modules exporting one **function** would emit cleanly from both back ends
and then die at the **linker** on a duplicate symbol — past anything a
compile-only check can observe — which is why the refusal was worth keeping
until the emitter learned to rename.

⚠️ **Renaming and resolving are different questions**, and the recorded fix named
only the first. The *symbol* is program-wide, so both owners take their unit as
a suffix wherever they are written. *Which* symbol a bare use means is per file:
one importing a single owner names it bare quite legally and must reach that
owner's suffixed symbol, and only one importing both has a name with no answer.
A qualified use resolves either way, which is what makes this a use-site error
rather than a refusal.

⚠️ **`Renames` had to stop being suspended at a qualified name and start being
replaced.** Clearing it was right only while an exported name could never be
renamed; with one that can, `Alpha.Shared()` emitted the unsuffixed name nothing
defines.

⚠️ **And it was C-2 that actually refused the program**, not this entry's check.
`TopLevel` accumulated across the whole program, so `Shared` in Alpha and
`Shared` in Beta read as an *overload* [FUN-013] and were refused as one — the
emitter reporting a language feature it does not have for a program using one it
does. The set is cleared per unit now, which is what the check always meant.

⚠️ **`Renames` also held the wrong thing.** It stored `Name__Unit` and `Mangle`
escaped that whole string, which is exactly what `Mangle`'s own note forbids: `_`
escapes to `V`, so the joined form and an identifier spelled `NameVVUnit` meet.
It stayed injective only by the accident of the name appearing twice, and nothing
in the compiler's own sources is renamed, so no emitted symbol ever showed it.

**C-22 — A Unicode identifier will not compile.**
***Withdrawn.***

Any Unicode character may appear in an identifier [SRC-005] and the emitter
refused it with `An identifier containing 'é' is not supported by the C back end
yet.` Annex G.3's scheme is implemented, so `🙂` emits as `U01F642` and
`conformance/0139` compiles to output identical to the interpreted run.

⚠️ **Adopting G.3 in part would not have worked**, which is why this waited. The
escape only becomes free once every letter is lowercased; adding `U` escapes to
the old pass-through scheme would have collided with an identifier spelled like
one. The two halves of G.3 are a single decision.

⚠️ **Three bootstrap generations**, not two. The old binary emits the new
scheme's *source* under the old rules, so generation 1 still carries old
symbols; generation 2 emits new ones; generation 3 is where the output stops
changing. `fixedpoint.sh` iterates for exactly this.

**C-23 — A compiled test run never says why a test failed.**
***Withdrawn.***

`alg_test_run` caught the failure and printed `FAIL` but never read the value
that was raised, so a compiled suite reported *that* a test failed and never
*what*. It prints the same `[ERROR] <file>: <message>` line the interpreter does
now, from `AlgFrame`'s `raised`.

⚠️ **There were no caret lines to worry about.** This entry assumed a test
failure printed three lines, of which compiled code could reproduce one. It
prints exactly **one**: `Console.Error` adds a source line and a caret, and a
test failure does not go through it. So no filtering was needed on either side —
the reports simply match.

⚠️ **The file named is the ROOT**, not the file the failing test lives in, and
the compiled runner had to copy that to agree. `SourceCode` is one global keyed
by line number, so the interpreter names the file the run started from whatever
module the test came from. Reproducing a fault is what agreement costs here.

⚠️ It is why the two processors could disagree about `AssertTrue`'s wording for
as long as they did: nothing that compares the two reports ever looked at this
line. Verified after the fix — the whole 221-test suite is now identical line for
line through both processors.

⚠️ **The last differing line is gone too.** A failing run used to print
`Uncaught: Tests failed.` interpreted and nothing compiled, because the driver
had to `raise` to set exit 70. `Halt` [RT-018] was added for it, and the
interpreted driver calls that instead — so neither side prints anything the
report did not ask for, and a failing suite is now identical through both
processors.

**C-24 — A compiled top-level subprogram is matched on arity, not signature.**
***Withdrawn.***
*(refers to [FUN-006])*

`function G (N : Integer)` called with a String is `No matching signature for
function.` interpreted and runs compiled, returning the String. The emitted call
checks the count and nothing else.

⚠️ **Silent, and in the dangerous direction**: the compiler accepts a program the
language refuses, so one developed against the compiler fails the moment it is
run interpreted. It is the same shape C-4 had, and the same remedy applies —
bring the compiler up, not the interpreter down.

⚠️ **Checked in the CALLEE, not at the call site.** The entry proposed the call
site; the callee is one place instead of many, and it is where the declared type
already is. `alg_param` raises what does not fit and widens what does.

⚠️ **Only a top-level subprogram goes through it.** A method's parameters are
checked when the overload is *selected*, and a constructor's are deliberately not
checked at all — see `find_method`'s `strict`. A top-level subprogram has no
selection step, which is exactly why the check had nowhere else to live.


**C-25 — A compiled value does not widen into a written type.**
***Withdrawn.***
*(refers to [VAR-017], [EXP-014])*

`function D (X : Double)` called as `D (1)` yields `1` compiled and `1.0`
interpreted. A parameter is an assignment context, so the argument should widen
on the way in and the parameter should hold the wider type.

⚠️ Distinct from C-24, which is about *refusing* a mismatch: this one is about
*converting* a match. A compiled program silently held an Integer where its own
declaration said Double.

⚠️ **Wider than a parameter.** The entry named only arguments; a declaration, a
`const`, a plain assignment, a field and a field's initializer were all
unconverted too. `alg_widen` is called at each, and the declared type reaches the
assignment and field cases **on the node**, written there by the TypeChecker —
the same arrangement the interpreter needed.

⚠️ **Selection had to learn to widen at the same moment**, or `Only ('a')` against
a `String` parameter found no method. `find_method` makes three passes — exact,
widening, then absorbing [FUN-005] — over the whole chain, the mirror of the
interpreter's, and for the same reason: one pass would let declaration order
decide.

⚠️ **Widening and checking are separate jobs, and conflating them broke the
bootstrap.** One helper that both converted and refused turned a String reaching
a field declared `Expr` into an error — a shape real programs use, since a
constructor's signature is unchecked by design. `alg_widen` converts and refuses
nothing; `alg_param` does both and is used only where a check belongs.


**C-26 — Two top-level subprograms of one name will not compile.**
***Withdrawn.***

A top-level subprogram overloads [FUN-013] and the interpreter selects between
them. The emitter refused with `Two subprograms named 'Take' is not supported by
the C back end yet.`

⚠️ **It used to emit and die at `cc`** — `redefinition of f_Take` — which is a
compiler producing a program it cannot build, and past anything the emitter's
own checks observe. The refusal was added with the rule.

⚠️ **The two halves the entry named were both needed, and the second is the one
that shapes the design.** `FunctionSymbol` mangles by signature so both
definitions can be spelled; and because the call site cannot know which
candidate it wants until it has its arguments, a name with more than one
subprogram behind it is reached through an **overload set** — one value per
name, holding every candidate with its **parameter list as written** — name,
type and element type each — which selects when called. `alg_call` on one is
`find_method` for subprograms: three passes, exact then widening then absorbing
[EXP-014], forwards within a pass so the first declared wins.

⚠️ **Only an overloaded name pays for it.** A name with a single subprogram
behind it is still called by its own symbol and still carries no signature
suffix, so the emitted C of every program without an overload is unchanged —
which is also what let the seed stay comparable across this change.

⚠️ **One message for both failures**, which is what the interpreter gives: a
wrong count and a wrong type are both "nothing fitted", and there is no single
expected arity to name when the candidates disagree about it.

⚠️ **The refusal was also firing across units**, which is how C-21 met it:
`TopLevel` accumulated program-wide, so one name in two files read as an
overload. Two subprograms in two files are not one, and the set is cleared per
unit.

**C-27 — A large literal of computed elements will not compile.**
***Withdrawn.***

A collection literal is emitted as nested `alg_list_keep` calls, one bracket
level per element, and `cc` gives up at 256 — clang says `bracket nesting level
exceeded maximum of 256`. Above a hundred elements the emitter builds the
literal in a helper function instead, one assignment per element, so depth stays
at one however many there are.

⚠️ That was only possible when every element was **itself a literal**. `[X, Y]`
reads two variables and a helper lifted to file scope cannot see them, so a large
literal with computed elements was refused by name rather than emitted as
something `cc` rejects: `A literal of 200 computed elements is not supported by
the C back end yet.`

⚠️ **It used to emit and die at `cc`**, which is the failure this back end exists
to avoid — found by a generated table of 659 ranges producing a 40 KB expression
nested 659 deep.

⚠️ **The elements are evaluated at the CALL and handed in**, which is the first
of the two fixes this entry proposed. One compound literal, so the bracket depth
is 1 however many there are — `ArgumentArray` builds every call's arguments the
same way, so this introduced no shape the emitted C did not already have.

⚠️ **A constant literal keeps the helper it had.** The two forms differ only in
where the elements are written, and keeping the first leaves the emitted C of
every existing large table — `compiler/Unicode.a24`'s 659 ranges among them —
exactly as it was.

⚠️ A Map's keys and values are **interleaved** into one array, key first: two
arrays would need two parameters and two compound literals for no gain.

**C-28 — An undefined collection member is not refused compiled.**
***Withdrawn.***
*(refers to [COL-005])*

`K.Get (0)` on a `Stack` is `Undefined property 'Get'.` interpreted — `Get`
belongs to a List, an Array and a Map — and compiled it ran and answered.

⚠️ Silent, and in the direction that matters: the compiler accepted a program
the language refuses.

⚠️ **The member table is per KIND, and the runtime's was flat.** Every name was
answered for every collection, so the kinds were distinguishable only by what
happened to work. `kind_has` mirrors `ObjCollection.Get`'s chain of kind tests;
the two are one table written twice and have to be read together.

**C-29 — An invalid subscript target is not refused compiled.**
***Withdrawn.***
*(refers to [TYP-010])*

Subscripting a Set is `Subscript target should be an ordinal.` interpreted, and
compiled it answered a value. Same cause as C-28: a Set is a sequence in the
runtime's representation, so the position path took it.

⚠️ **A Set reports as though it were not a collection at all**, which is what
`ObjCollection.At` does deliberately: there is no subscript path for a Set, so
it falls through to the complaint anything else without one gets.

Assignment was wrong in a second way the entry did not name — `'abc'[0] := 'x'`
answered `Only a collection can be subscripted.`, which is false of the receiver
in front of it. It is `Strings are immutable.` on both sides now.

**C-30 — `Max` and `Val` answer differently compiled.**
***Withdrawn.***
*(refers to [RT-010], [RT-011])*

| | Interpreted | Compiled |
| --- | --- | --- |
| `Max (3.5, 2)` | `-7`-style promotion, answering the larger | `Max expects Integers.` |
| `Val ('42')` | `42` | `42.0` |

⚠️ Two faults in one case, pulling opposite ways: `Max` refused what the
language admits, and `Val` answered a Double where the language says Integer.
Each was defensible alone and together they left `Max (Val (A), Val (B))`
failing for **every** input.

⚠️ **The digits are accumulated through `alg_multiply` and `alg_add`**, not
converted from the parsed double, and not for precision: those carry the range
check [LEX-018], so `Val ('99999999999')` raises `Integer overflow: 999999999 *
10.` exactly as the interpreter's does. A cast would answer a wrong number
quietly, and the language has no narrowing conversion to write instead.

**C-31 — A compiled class does not inherit from a parent declared below it.**
***Withdrawn.***
*(refers to [DCL-006])*

`class Puppy (Hound);` written above `class Hound;` linked to nothing compiled:
`Puppy () is Hound` was **false**, and the inherited method was then
`Undefined property 'Speak'.`

⚠️ The interpreter hoists a class in two phases for exactly this — the name is
bound before anything runs and filled in where the declaration stands, so the
subclass holds the finished parent. The emitter hoisted every top-level name
(C-10) and still got this wrong, which was worth noticing: hoisting *more* did
not make it right, because binding a name is not the same as the thing it names
existing.

⚠️ **The emitter now hoists in two phases too.** Every class in a unit is built
as an empty shell in one buffer, and the links, fields and methods follow in
another — so a child is linked to a parent that exists rather than to a handle
still holding `nil`. `alg_class_super` is the second phase; passing the parent
to `alg_class` could never have worked.

⚠️ **`total_fields` had to become lazy for it.** An instance's size is its
class's fields plus its ancestors', and it was maintained as fields were
registered — which needs the parent's fields to be in place before the child's.
With inheritance linked ahead of any field, there is no moment during setup at
which a running total would be right, so it is computed on first use and cached.
Safe because nothing instantiates a class until every `init_<Unit>()` has run.

**C-32 — Names are not matched without regard to case compiled.**
***Withdrawn.***
*(refers to [SRC-011])*

`GREET ('you')` calling `function Greet` is
`A call to 'GREET' is not supported by the C back end yet.`

⚠️ **The call was only the first layer.** Annex G.3's mangling already lowers
both spellings to `f_greet`, so the *symbol* was never the problem — the lookup
that decides which branch to take was keyed by the name as written. Fixing it
uncovered three more of exactly the same kind, each found by running the case
again:

| | |
| --- | --- |
| a **field** — `this.VALUE` against `Value` | `field_slot` compared with `strcmp` |
| a **method** — `B.DOUBLED ()` against `Doubled` | `find_method` hashed and compared the exact spelling |
| an **enum member** — `COLOUR.red` against `Colour.Red` | the member scan compared with `strcmp` |

⚠️ **The emitter canonicalises, the runtime folds**, and the split is deliberate.
The emitter maps a name to the spelling it was declared with, once, so the sets
it consults stay as they are; the runtime folds its own field, method and enum
lookups because it has no declaration to consult. A name is still *emitted* as
written, so a diagnostic quotes what the program wrote.

⚠️ A comment in `alg_property` claimed the interpreter's fields were
case-sensitive too. That stopped being true when DEF-02 landed, and nothing
noticed until this entry was worked.

⚠️ The folded hash costs nothing measurable — three runs of `./test.sh` before
and after are the same to within noise, which matters because `find_method` is
the hottest path in the runtime.


**C-33 — An assertion outside a test run is refused compiled.**
***Withdrawn.***
*(refers to [RT-002])*

Calling `AssertTrue` outside `--test` is `Undefined variable 'AssertTrue'.`
interpreted — the name is registered only during a test run — and compiled it
was `A call to 'AssertTrue' is not supported by the C back end yet.`

⚠️ Both refused, so this was a wording difference like C-7 rather than a hole.
The compiled text named the back end for something that is a rule about the
*language*, which is the part that misled.

⚠️ **The bare name was already right**; only the call was wrong. `AssertTrue`
read as a value took the emitter's undefined-name path, and `AssertTrue (True)`
fell through the call table to the catch-all refusal — one name, two paths,
disagreeing about whether the program was wrong or the emitter was incapable.

**C-34 — A name that does not resolve emits invalid C.**
***Withdrawn.***
*(refers to [MOD-009], [DCL-008])*

A name the program cannot reach is a runtime error interpreted and a `cc`
failure compiled, because the emitter writes a reference to a symbol it never
declared. Two shapes reach it:

| | Interpreted | Compiled |
| --- | --- | --- |
| a name its imports do not export | `Undefined variable 'DeepName'.`, naming the unit that has it | `undeclared identifier 'f_deepname'` |
| a block-local name read after the `end` | `Undefined variable 'Inner'.` | `undeclared identifier 'v_inner'` |

⚠️ The second shape only became reachable when C-11 was fixed. Before that a
top-level block's variable was emitted at file scope, so it wrongly *did* exist
after the block and the program ran with no complaint at all.

⚠️ **Emitted as a RUNTIME error, not refused at compile time**, which is what the
interpreter does: a name is looked up when it is *used*, so a reference on a path
never taken is not an error at all. Refusing at emit time would reject programs
the language accepts. `UnitValue` had done exactly this for a *qualified* name all
along — `(alg_error("…"), alg_nil())` — and the bare forms now do the same.

⚠️ **`Declared` is not the same as reachable**, which is what the first shape
turned on. `Declared` spans the whole flattened program, so a function in a unit
this file never imported still counted as declared and the call emitted
`f_deepname` against a header that was never included. `uses` is not transitive
[MOD-009]; `ShadowNames` is what a unit can actually see.

⚠️ **The suggestion is part of the message and is reproduced.** `Undefined
variable 'X'.` alone is indistinguishable from a typo for a name the reader can
see in another file, so the compiled text names the unit too — the two outputs
are byte-identical. ⚠️ Units are walked in *name* order here where the
interpreter walks them in *load* order; with two units exporting one name the
two could still name different ones.

⚠️ The emitter breaks its own contract, as in C-13 and C-16: it should refuse by
name what it cannot emit rather than emit C that does not build.

**C-35 — A collection member read without calling it is refused compiled.**
***Withdrawn.***
*(refers to [COL-005])*

`var Sort := L.Sort;` binds a callable interpreted and was `Undefined property
'Sort'.` compiled. Only `Length` and `IsEmpty` were answered on this path, so of
the 41 kind/member pairs [COL-003] records, a compiled program could read 10.

⚠️ **This is the instance case again, one receiver kind later.** `alg_property`
already gained the note that a method reached without calling it binds to its
receiver — written because `algc`'s own `IsCallable` asks every value for its
`Arity`, so a compiled `algc` could not call anything at all. Collections were
not given the same treatment, and nothing noticed because nothing reads a
collection member without calling it.

⚠️ **Found by adding a conformance case for a probe.** `spec/members.a24` has
exercised exactly this since [COL-003]'s matrix was first checked — but it is a
*source* for `spec/spec.sh`, not a conformance case, so `conform.sh` never
compiled it and the divergence stayed invisible. A program only the interpreter
runs is not evidence about the language.

⚠️ **A Buffer and a TextFile were wrong the same way**, which the entry did not
say. All three receivers take their members from the runtime rather than from a
class, and all three answered only their bare properties. `ObjBuffer.Get` and
`ObjFile.Get` hand back a callable exactly as `ObjCollection.Get` does.

⚠️ **The tables had to carry an ARITY, not just membership.** What a read binds
is callable, and a callable has to know how many arguments it takes — the three
interpreter wrappers each carry one for precisely this check. There are now four
copies of that table and they have to be read together; `spec/spec.sh` checks
[COL-003] against the interpreter's, and `conformance/0144` is what compares the
compiled one against it.

**C-36 — A built-in called with the wrong arity is refused by name.**
***Withdrawn.***
*(refers to [EXP-011], [RT-001])*

`Length ('a', 'b')` is `Expected 1 arguments but got 2.` interpreted and was
`A call to 'Length' is not supported by the C back end yet.` compiled.

⚠️ **The name exists**, which is what made the compiled text wrong rather than
merely differently worded: it reported a gap in the back end for a program that
is simply a wrong call to a real built-in. The emitter's table is keyed by name
*and arity* (C-18), so a known name at an unknown count matched nothing and fell
through to the catch-all refusal.

⚠️ **Found while fixing C-33, and deliberately not fixed with it.** The obvious
move there — treat everything reaching the catch-all as an undefined name —
would have made this *worse*, answering `Undefined variable 'Length'.` for a
name the language defines. C-33 was narrowed to the three assertion names
instead.

⚠️ **The counts are asked of the tables, not listed again.** `BuiltinCounts`
probes the two tables that map a name to its runtime entry point, once per
count, so a built-in added to either is described the moment it is added. A
fifth transcription of the twenty-eight names is exactly the rot [COL-003]'s
matrix already needs a harness to guard against.

⚠️ **And the same key hid a missing feature.** `WriteLn ()` — the newline on its
own — had no mapping at all, because only `WriteLn/1` was in the table. A valid
program with no compiled form, which is what C-1 was and which this back end is
supposed to have none of.

**C-37 — A built-in member printed without being called reads differently.**
***Withdrawn.***
*(refers to [TYP-012])*

| | |
| --- | --- |
| Interpreted | `WriteLn (L.Sort)` was `CollectionMethod instance` |
| Compiled | `<fn Sort>` |

⚠️ **The interpreter was the one that was wrong here**, as in C-4 — and it is
the interpreter that changed. `CollectionMethod` names a class that exists only
inside `algc`; a program has no way to know it and nothing in the language
answers to it. A bound *method* prints `<fn Name>` [TYP-012], and a bound
built-in member is the same kind of thing.

⚠️ **The obstacle was the spelling, not the hook.** The three wrappers carried
the member name **folded**, because their tables are written folded to meet a
folded lookup [SRC-011], so the obvious `ToString` would have given `<fn sort>`.
They carry the **token** now: dispatch folds it, and the diagnostic reads the
lexeme, which needs no second table.

⚠️ **And the spelling is the call site's, on both sides.** A built-in member has
no declaration in the language to take a canonical spelling from — a bound
method prints the name its *declaration* used, and a member table is not a
declaration — so the only spelling the two processors can agree on is the one
the program wrote. `L.SORT` is `<fn SORT>` through both. The C runtime had
stored the table's spelling instead, on a stated worry about lifetime that was
unfounded: a call-site name is a string literal in the emitted C.

    conformance  0149-a-built-in-member-as-a-value.a24

**C-38 — A function declared inside a method will not compile.**
***Withdrawn.***
*(refers to [FUN-012], [CLS-011])*

```
A function declared inside a method is not supported by the C back end yet.
```

A method's body is a body like any other, so a function may be declared in one
and closes over what it can see there — which runs interpreted and is refused
compiled.

⚠️ **Split out of C-2 rather than fixed with it**, because it is a different
thing. C-2 was one missing shape in an existing mechanism; this needs a new one.
A method's C function takes a receiver and **no cell array**, so a body that
boxes has nowhere to put its cells, and a nested function there closes over
`this` as well as over the locals: `conformance/0148` reads a field bare, writes
one through `this`, and the write sticks.

⚠️ **Three pieces, and two were already written.** A method body boxes what a
nested function reads exactly as a function body does — the analysis existed and
was simply not called there. The **receiver joins the cells**, under the name the
language uses for it, because a nested function reading a field reaches it
through `this`. And every emission of the receiver goes through one place now,
which answers `v_this` in a method and reads the cell in a function nested
inside one.

⚠️ **`v_this` is a parameter, and that is the whole difficulty.** A method's C
function takes a receiver; a nested function takes cells and has no such
parameter. Writing `v_this` unconditionally is what made the shape unemittable,
and the five sites that wrote it — a field read, a field write, a bare method
call, `super`, and `this` itself — all had to ask instead.

A closure that escapes a method keeps its receiver: `C.Make (3)` hands back a
function that goes on mutating `C`'s field, and a second `Counter` gets its own.


**C-39 — `super` as a value will not compile.**
***Withdrawn.***
*(refers to [CLS-012], [CLS-011])*

```
'super' as a value is not supported by the C back end yet.
```

`var Parent := super.Speak;` runs interpreted and was refused compiled.

⚠️ **Found by the gate on the day it was tightened**, not by looking for it. The
generation bar became "every case passes under both processors", `conform.sh`
was changed to fail on a gap rather than report one, and the first thing needed
was a case that would prove the new gate bites. `super` as a value was the only
refusal still reachable — the other two the emitter names are refused by the
*parser* first, in both processors — so it served as the fixture and turned out
to be real work.

⚠️ **The refusal was older than the mechanism it needed.** `alg_invoke_from`
already searched from the declaring class, and `alg_bound` already bound a
method to a receiver; `alg_bound_from` is the two of them in one call. The
spelling had simply never been reached, because nothing in `compiler/*.a24`
holds `super.M` as a value.

> **A note on DEF-13, which this annex got wrong.** Its entry said the fix was
> blocked on "a registry of declared type names that does not exist —
> `Lookup.Parents` holds only classes that *have* a superclass, and enumerations
> are not tracked at all." `Parents` is the **inheritance** map and was never the
> registry. `Types` is, and all three declaring forms populate it: `ClassStmt`,
> `ObjectStmt` and `EnumStmt` each register their own name. The checker already
> refused `var E : Nonexistent := 1;` on that basis. The defect sat deferred
> through five waves on a misreading of which map to look at, and the fix came to
> three lines of registration and one check.
>
> ⚠️ The lesson is about *where* a blocker is recorded. "Blocked on machinery
> that does not exist" is a claim about the code, and it goes stale — or is wrong
> from the start — exactly like any other comment. It deserves the same
> re-checking as a `⚠️` before it is trusted a second time.


## Annex D — advisory notes *(non-normative)*

Where the specified behaviour looks like a mistake. Nothing here weakens the
rule it refers to: the body states what the language does, and this annex
argues about it. Entries are added as the chapters that expose them are
written.

**D-1 — Integer overflow is silent.** *(refers to [LEX-018])*

**Resolved, and then resolved again.** The specification first required an
out-of-range literal to be refused when the program is read and an out-of-range
arithmetic result to raise. The two were separated because they cost
differently: a literal is checked once during the scan, while an arithmetic
result must be checked on every operation a program performs.

⚠️ **Both halves are now moot**, because [LEX-018] makes an Integer unbounded:
there is no range for a literal to be outside of, and no result to refuse. The
literal rule was deleted and the scanner's text comparison with it. What began
as "make the wrap an error" ended as "have no wrap" — the second answer is the
one a reader needs nothing else to understand.

⚠️ "What C does natively" was the wrong way to put it, and this note said it:
signed overflow in C is *undefined behaviour*, not a wrap. The runtime had
always computed through the builtins to avoid that, so what it produced was a
defined wrap — and the same branch that reported it now decides to promote.

**D-2 — `?` alone is a valid identifier.** *(refers to [LEX-008])*

**Resolved.** `?` and `!` are identifier *marks* rather than letters [SRC-005]:
they continue an identifier and may not begin one [LEX-008], so `Gate?` and
`Send!` are single words while `?` and `!` alone are not identifiers at all.

The implementation classed `?` as a letter, so it led; and it did not admit `!`
in an identifier at all. Tracked by DEF-03, and fixed there: `Gate?` and `Send!`
are words, and `?bad` is `Unexpected character: ?`.

**D-3 — `#0` is constructible but unstorable.** *(refers to [LEX-032])*

**Resolved by refusing it.** `#0` is not a Char [LEX-032], and is refused when
the program is read exactly as an out-of-range code point is [LEX-025]. That is
the smaller of the two available fixes and matches a check the scanner already
performs.

The larger fix — giving a String an explicit length so it can hold a zero
character — remains the better language, and [SRC-001] already obliges a String
to carry a character count distinct from its byte length, so the two changes
meet. [LEX-032] is worded so that adopting it later relaxes a restriction
rather than reversing a guarantee. Tracked by DEF-08.

⚠️ **The larger fix landed anyway.** A String carries its own byte length now,
so `'a' + Str (Char (0)) + 'b'` is three characters long, prints as three and
compares equal to itself. Only the **literal** `#0` is still refused, which is
what [LEX-032] says and all it says.

**D-4 — Widening is refused as firmly as narrowing.** *(refers to [VAR-004])*

`var X : Integer := 1.5;` should certainly be refused: the value does not fit.
But `var X : Double := 1;` is refused on the same terms, and there the value
fits exactly and every arithmetic operation in the language already promotes an
Integer to a Double when the two meet. A programmer who writes `: Double` and
initializes with `0` is told the types do not match.

**Resolved, and generalized.** Widening follows Pascal: Integer to Double and
Char to String, at any of the six assignment contexts [VAR-017], converting at
the point the value arrives. The open question — whether `X` then holds a Double
or an Integer a declaration lied about — is answered explicitly: it holds a
Double [VAR-004]. Narrowing stays refused [VAR-018]. **Implemented.**

⚠️ **Why this is a defect and not a later generation.** The question was asked
directly, and the answer turns on whether the language *lacks* widening or *has
it inconsistently*. It has it: `1 + 1.5` is `2.5` and `'a' + 'bc'` is `abc`
today. Only the paths carrying a written type refuse, so a declared type means
something narrower than the operators do. An absent facility goes to Annex H —
H-1's alternate bases are absent, with nothing in the language to be
inconsistent with. One path disagreeing with the rest of the same language is a
fault.

⚠️ Equality was deliberately left out. Pascal converts in comparisons too, which
would make `Copy('abc', 0, 1) = 'a'` true and reverse [LEX-026] — the one part
of this that changes what an existing program *means* rather than accepting a
program that was refused. It belongs with D-6, in the chapter that specifies
`=`.

**D-5 — `const` promises less than it appears to.** *(refers to [VAR-014])*

`const C := V;` is legal where `V` is a variable, so a constant's value need not
be known before the program runs. The word means only that the binding cannot
be reassigned. A reader who takes `const` to mean a compile-time constant — as
Pascal's does, and as most languages' do — will be wrong about when the
initializer runs and about what the compiler can assume.

**Resolved by keeping it.** The run-time form is genuinely useful for a value
computed once at startup, and nothing here is broken — the word means *this
binding may not be reassigned*, which [VAR-014] now states plainly rather than
leaving to be inferred. A true compile-time constant, if one is ever wanted,
needs a different word rather than a narrowing of this one.

**D-6 — Equality and membership disagree.** *(refers to [VAL-009], [VAL-013])*

`1 = 1.0` is true, and `1 in [1.0]` is false. A Map holding the key `1` does not
contain `1.0`. Each rule is defensible alone — `=` promotes because arithmetic
does, and membership is strict because a hash table cannot be built over a
relation that promotes — but together they mean a program can hold two values it
calls equal and find only one of them in a collection.

`bootstrap/algol.c` already names this a rough edge in its own comments, which
is a fair sign it was noticed and not resolved.

**Resolved in favour of `=`.** Membership and equality are one relation
[VAL-013], paid for by hashing an Integer and a Double of the same numeric value
to the same bucket. Making `=` strict instead would have been the far larger
change and would surprise every program doing ordinary arithmetic.

⚠️ The reason the two diverged is worth keeping: `=` promotes because arithmetic
does, and membership was strict because a hash table cannot be built over a
promoting relation. The second is a statement about the implementation and the
first about the language, which is what decided it.

**Implemented.** `strict_equals` promotes and `hash_value` brings both numeric
types to one slot.

**D-7 — `as` is an unchecked assertion.** *(refers to [VAL-007])*

`X as Integer` where `X` holds `'text'` yields `'text'` and raises nothing. The
cast silences the checker and is never verified, so the one construct a
programmer reaches for when they know more than the checker does is also the one
that cannot tell them when they are wrong.

**Resolved, and done.** `as` is a checked conversion and raises when the value
is not of the named type [VAL-007]. The cost falls only on programs that use `as`, which
are the programs that asked for the assurance, and a cast that cannot fail is
not an assurance at all.

⚠️ This decision is what makes [VAR-006] tenable. `as` is the only way a value
crosses from untyped into typed, so the strictness there is only reasonable if
the crossing is verified; an unchecked cast would have made the boundary a
formality and every declared type beyond it a claim nothing had checked. The two
rules were decided together and neither stands alone. Both are now implemented.

**D-8 — Empty is truthy.** *(refers to [VAL-008])*

`0` is falsey, but `0.0`, `''`, `[]` and `[:]` are all truthy. So
`if not S then` does not mean what a reader coming from most languages will
expect it to mean, and `if S.Length = 0 then` is the only reliable spelling.

The rule is at least short to state, and it makes truthiness independent of a
value's contents — a collection is a thing, and a thing is there.

**Resolved by keeping it.** [VAL-008] now states plainly that truthiness is
independent of a value's contents, and that `if S.Length = 0 then` is the only
spelling that tests emptiness.

⚠️ The observation still stands and is **not scheduled**: Integer `0` is the odd
one out, and were it truthy the rule would reduce to the genuinely simple "only
`nil` and `False` are false". That changes what existing programs mean rather
than admitting programs that were refused, so it belongs to neither annex until
someone decides to take it — recorded here so the option is not lost.

**D-9 — Visibility is advisory.** *(refers to [DCL-015])*

`private:` is checked by the type checker, and only where the receiver's type is
known. `var C : Any := Counter(); C.Count` yields the private field and raises
nothing. A subclass reading its parent's private member by bare name gets it,
because a bare name inside a method resolves through `this`, and `this` reduces
to no type at all — while the same member through a receiver declared as the
parent is correctly refused.

So the guarantee is real for code that annotates its types and absent for code
that does not, which is the opposite of where a guarantee is most wanted. It is
also not a security property and was never meant to be: the checker is advisory
by design in a gradually typed language.

⚠️ Any fix collides with a deliberate decision recorded in the checker: `this`
reduces to nothing precisely so that a class's own code is free of the
visibility rule. Typing `this` as its class would make the bare-name case work
and would also make every `this.Private` inside a subclass an error the language
currently allows.

**Resolved by saying so plainly.** [DCL-015] now states normatively that
`private:` is advisory — an intention that buys a diagnostic wherever types are
written, and not a boundary a program may rely on.

⚠️ The alternative was enforcing it at run time on the instance, where the class
is always known. That closes the hole completely and was the earlier
recommendation here, but it puts a check on **every property access** — which is
the cost the whole type-system direction of this specification exists to avoid.
[VAR-006] tightened declarations so the C back end could trust a declared type
and emit without runtime checks; paying one back here, on the most frequent
operation a program performs, would trade away more than it buys.

Nothing is lost that was ever really held: the guarantee was already absent
whenever a type was omitted, and the change is to stop implying otherwise.

**D-10 — Integer division by zero raises; Double division by zero does not.**
*(refers to [EXP-006])*

`1 / 0` is the runtime error `Division by zero.` `1.0 / 0` is `Infinity`, and
`0.0 / 0` is `NaN`, and neither stops the program. So whether dividing by zero
is a bug or a value depends on which numeric type reached the operator — and
[EXP-005] means an Integer becomes a Double whenever it meets one, so the same
expression can change category with an edit far from it.

The Double behaviour is IEEE 754 and is what C does for free; the Integer
behaviour has no such answer available, since there is no integer infinity to
produce.

**Resolved by keeping both.** [EXP-006] now states the asymmetry as a rule
rather than leaving it to be discovered, and says why: each behaviour is correct
for its own type. Raising on Double division would depart from IEEE 754 for no
gain, and returning a value for Integer division would have to invent one, since
there is no integer infinity.

⚠️ The genuinely surprising part is not the asymmetry but its reach: [EXP-005]
promotes an Integer whenever it meets a Double, so an edit far from a division
can move it from the raising category to the value-producing one. That is
recorded in the rule.

**D-11 — A parameter's declared type is decoration on a function and a contract
on a method.** *(refers to [FUN-006], [FUN-007])*

`function F(N : Integer)` accepts a String, a Double or a Boolean without
complaint. The same signature as a method refuses all three with `No matching
signature for function.` Nothing in the language says the two differ, and the
annotation looks identical in both places.

The cause is structural rather than deliberate: a method goes through overload
selection, which compares whole signatures, and a top-level function does not
overload [see 8.3] so nothing ever compares its parameters. Only the arity is
checked.

⚠️ Note the direction of the surprise. A declared return type IS enforced
[FUN-008], so within one declaration the result is checked and the arguments are
not — which is the reverse of what a reader would guess, since arguments come
from outside and are the less trustworthy of the two.

**Resolved.** [FUN-006] requires parameter types to be enforced on every call,
top-level subprogram or method alike. The check already existed in `Fits`; what
was missing was calling it when there is nothing to select between. Tracked by
DEF-19, and fixed there.

⚠️ This was not really an open question by the time it was reached: [VAR-017]
had already listed a parameter as one of the six assignment contexts, so
[FUN-006] as written contradicted a decided rule. The direction-of-surprise
note above still stands and is worth keeping — a declared *return* type is
checked while the arguments are not, which is the reverse of what a reader would
guess.

**D-12 — Inheriting from a non-class reports the wrong thing.**
*(refers to [CLS-014])*

```
var X := 1;
class C (X);
begin
end
```

fails with `Only instances have properties.` — a sentence naming neither the
class, nor the superclass, nor inheritance, and describing a property access the
program never wrote. The message belongs to the machinery rather than to the
mistake.

⚠️ **Corrected.** This entry previously said the check happens where the
superclass is *used* rather than where it is declared. It does not: the
declaration above is refused even when the class is never constructed. Only the
wording is at fault, which makes this smaller than it was recorded as being —
and is why it was worth running rather than reasoning about.

Diagnostics are part of the observable surface [1.2], so this is a specified
behaviour and not merely a rough edge — a conforming implementation must
reproduce the misleading sentence exactly.

**Resolved.** [CLS-014] requires the shape the other inheritance errors already
use — `'X' is not a class.`, beside `A class can't inherit from itself.` The
check already happens in the right place, so this is a message and nothing else.
Done: `VisitClassStmt` tests the superclass with `is` rather than asking it for
a property, so the comparison meant to reject it is now reached.

**D-13 — Truthiness reads a value a program cannot.** *(refers to [ENU-009],
[ENU-010])*

The first member of every enumeration is falsey, because truthiness reads the
member's ordinal — and the ordinal is not reachable from the language. `RED` is
false and `GREEN` is true, and a program can discover which is which only by
testing each for truth.

So `if Colour then` depends on where a member sits in a list that the program
cannot inspect, and reordering an enumeration's members silently changes the
truth of every conditional written over it. Nothing warns, because nothing
about the declaration looks conditional.

The rule exists so that enumerations behave like the small integers they are
represented by, which is a real convention and not an accident.

**Resolved, in both halves and in opposite directions.**

[ENU-010] requires a member to answer `Ordinal`, its zero-based position, so the
value that governs the behaviour can be read and compared. `Ordinal` already
existed on the implementation's own class and simply was not published. Done.

[ENU-009] is **kept**, and stated as a feature rather than tolerated as a
quirk — position-based truthiness is what makes `(Off, On)` and `(No, Yes)`
usable directly in a condition. The entry below records the reasoning, which
began as an argument for changing it and ended as the argument for keeping it.

⚠️ **[ENU-009] is settled: it stays.** The case against it was: an enumeration member is not a number, nothing else in the language makes a
declared name falsey by position, and reordering an enumeration silently changes
the truth of every conditional written over it.

⚠️ **The case for it is stronger, and was missed when this entry was written.**
Position-based truthiness is what lets a program declare its own two-valued
types and use them directly in a condition:

```
type Flag   = (Off, On);
type Answer = (No, Yes);
```

`if F then` reads correctly for both, with no comparison and no conversion. The
convention that falls out — put the absent, off or zero member first — is
already the one this compiler follows in `FUN_NONE` and `CLASS_NONE`. Under that
reading the rule is a feature with a discipline attached, not a trap, and the
discipline is the same one a `case` statement already asks for.

⚠️ **And the original complaint is half answered.** This entry's title says
truthiness reads a value a program *cannot* — but [ENU-010] now requires the
ordinal to be readable. Position-based truthiness over a *visible* position is a
stated rule rather than hidden machinery, which is most of what was wrong with
it.

⚠️ **A further prospect, TABLED and separable: it could remove the built-in
Boolean**, leaving `type Boolean = (False, True)` as an ordinary enumeration.
This is not decided and is not scheduled. Two costs argue for keeping the two
questions apart:

- **[ENU-011] collides with it.** Members bind bare, so any program declaring an
  enumeration with a `True`, `False`, `Yes` or `No` member would make that bare
  name ambiguous — and those names appear in almost every program. Boolean would
  have to be exempt from the ambiguity rule, which is a special case
  reintroduced one level down.
- **Representation.** `VAL_BOOL` is a distinct runtime tag while an enumeration
  member is an interned object, so this puts an indirection on the most common
  value a program has. That runs against the reason [VAR-006] was tightened.

`true` and `false` are also keywords [LEX-010], which would drop from 37 to 35.

Changing it would reverse part of [VAL-008], which the conformance pass decided
in chapter 7, so it is recorded here rather than taken unilaterally. Evidence
gathered for whoever decides: the compiler's own two enumerations are compared
explicitly at all five of their use sites — `if CurrentFunction = FUN_NONE then`
— and never tested for truth bare, so the change is safe against the largest
body of Algol-24 that exists.

**D-14 — Circular imports fail, and say something else.** *(refers to
[MOD-012])*

⚠️ **This entry was largely wrong, and running it is what showed that.** It said
a cycle between two modules fails with `Type mismatch!` It does not: cycles
between modules **work**, and so do cycles of three or more [MOD-012].

The `Type mismatch!` came from the probe's own fixtures, which returned `'A'`
and `'B'` from functions declared `: String`. A one-character literal is a Char
[LEX-023], so those functions failed whether or not any cycle existed — the
recording was evidence of DEF-10 and was read as evidence about modules. The
fixtures now return two-character strings and the probe records `Ay`.

What remains true is the **root** case [MOD-014]: a module importing the file
being run leaves the root's own imported names undefined, after the root's body
has already printed. Compiled, the same shape used to refuse with `Two modules
named 'X'` (C-1) — closed by giving the root a module identity, which is what
[MOD-014] asks for and what the fix below describes.

So there is one shape of problem rather than three, and it is the one this
repository already knew about — the root is never entered in the loader's map,
so it is parsed twice.

**Resolved.** [MOD-012] states that cycles between modules work, which they do.
[MOD-014] requires the root case to work the same way; DEF-24 tracked the
distance and closed it.

The fix is to give the root a module identity, so a `uses` pointing back at it
resolves to the copy already loaded — what [MOD-003] does for every other file
and what makes [MOD-012] work. That is more than a guard: an import-only node
carries no statements, and the importer genuinely needs the root's exports, so
the root must be registered with its environment **before its own body runs**.

Refusing the root cycle by name would be an improvement on the present
diagnostic and is much the smaller change, but it settles for less than
[MOD-014] asks.

⚠️ **Not hypothetical for this repository, and narrower than it once read.**
`compiler/Parser.a24` uses `Interpreter`, which uses `Parser` — a cycle between
two modules, which works, interpreted and compiled alike. The compiler compiles
itself and reaches a fixed point.

What fails is making a file in that cycle the **root**:
`algc --compile compiler/Parser.a24` refuses with `Two modules named 'Parser' is
not supported by the C back end yet.` [Annex C, C-1]. `compiler/Main.a24` is
unaffected because nothing imports it, which is why the whole suite compiles.
An earlier version of this entry said the compiler's own source could not be
compiled by itself; that was wrong.

**D-15 — Two different things are spelled `Length`.** *(refers to [RT-003])*

```
var L := [10, 20, 30];
L.Length      →  3
Length(L)     → 12
```

The property answers the collection's count. The function stringifies its
argument and measures the text, so `Length(L)` is the length of `[10, 20, 30]`.
`LengthNative` is literally `Exit Length(Str(Arguments[0]))`.

⚠️ The failure mode is the bad one: the wrong call returns a **plausible
number** rather than an error. A program asking `Length(L)` of a collection gets
an answer, uses it, and is wrong.

⚠️ **Corrected.** This entry claimed the two coincide for small lists of
one-digit numbers before diverging. They never coincide: a List of *n* one-digit
numbers renders as `[1, 2, 3]`, which is `3n` characters, against a count of
*n* — so `0/2`, `1/3`, `2/6`, `3/9`. The claim was plausible and wrong, and the
rule is no weaker without it.

The function is right for its intended argument. `Length('abc')` is 3, which is
what a Pascal programmer expects, and the collection property is right too. Only
the shared name is wrong.

**Resolved.** [RT-003] refuses `Length` of a collection —
`Length expects text; use .Length for a collection.` A program that means the
count says so, and one that means the rendering writes `Length(Str(L))`, which
is what it was getting by accident. Done.

⚠️ Verified safe against the largest body of Algol-24 that exists: every
`Length(…)` call in `compiler/*.a24` is on text.

⚠️ [RT-017] closes the other half of the confusion by giving a String the same
`.Length` property every collection has, so `.Length` becomes the uniform
spelling for "how many" and `Length(…)` is left meaning only "how long is this
text".

**D-16 — `Val` always yields a Double, and `Max` never accepts one.** *(refers
to [RT-009], [RT-010])*

`Val('42')` is `42.0`, not `42`, so text that plainly holds an integer cannot be
parsed into one — and the result then cannot be passed to `Max`, which refuses
anything but Integers with `Max expects Integers.` The two built-ins are
individually defensible and jointly unusable: `Max(Val(A), Val(B))` fails for
every input.

Given [VAR-004], which refuses `var X : Integer := 1.5;` and even
`var X : Double := 1;`, a program has no smooth path from parsed text to an
Integer at all.

**Resolved, both halves.** [RT-009] makes `Val` answer an Integer where the
text has no point and a Double where it has one, reading the same characters the
literal rules do [LEX-015], [LEX-020]. [RT-010] lets `Max` take any two numbers,
promoting as every other numeric operator does [EXP-005].

⚠️ They are **one** defect, DEF-27, rather than two. Either change alone helps,
but only both together make `Max(Val(A), Val(B))` — which failed for every input
— work at all.

**D-17 — A type error says only "Type mismatch!"** *(refers to [ERR-006])*

Every mismatch the checker finds produces the same five words, with no file, no
line, no token and neither of the types involved. In a seven-line program the
diagnostic is:

```
Uncaught: Type mismatch!
```

and nothing else. The parser and resolver, by contrast, print the file, the
line, the source text and a caret under the offending token [ERR-005] — so the
machinery for a good diagnostic already exists, is already used two phases
earlier, and the checker simply does not reach for it.

⚠️ This compounds with [ERR-002]: because a type error stops the program before
any statement runs, a programmer gets no output to orient by either. The message
is the only information available, and it carries none.

⚠️ And with [FUN-006]: a parameter's declared type is unenforced, so mismatches
surface in fewer places than a reader expects — which makes the ones that do
surface harder to locate, not easier.

**Resolved.** [ERR-006] now requires the three-line excerpt a parse error
carries [ERR-005] and both type names — `Expected Integer, found String.` The
token is in hand at every one of the five sites that raise this, so the
information is discarded rather than absent, and `Console.Error` already
produces the shape two phases earlier.

⚠️ **Done.** [ERR-006] is implemented: all five sites report through
`Console.Error` with the offending token and both type names. It was the
cheapest improvement in this annex and the first taken, because every later
generation-1 fix produces type errors while it is being debugged.

⚠️ One refinement the implementation forced, recorded rather than quietly made:
this entry's example put the caret under the offending *value*. A literal
carries no token, so the caret names the declaration instead — reaching the
value would mean giving every expression a token, which is a change to
`Expr.a24` and the parser for a caret the message already makes unnecessary.

**D-18 — `AssertTrue` reports a comparison it did not make.** *(refers to
[TST-012])*

`AssertTrue(False)` fails with:

```
Assertion 'left = right' failed.
```

There is no left and no right. The message belongs to `AssertEqual`, which
appends `Expected 'E' but got 'A'.` to the same stem, and `AssertTrue` reuses
the stem and supplies no operands — so the reader is told an equality failed
when a truth test did, and given nothing about what was actually false.

`Fail(M)` produces `Failed.  M`, with two spaces, which is a third shape again.

**Resolved, and further than recommended.** The phantom stem goes from *every*
form, not only from `AssertTrue`: `'left = right'` names operands that no
message ever fills in, and reads like a template left unfinished. [TST-012] now
specifies `Assertion failed.` followed by two spaces and a clause that carries
the actual values — `Expected true but got 'V'.` for `AssertTrue`, and
`Expected 'E' but got 'A'.` for `AssertEqual`. Tracked by DEF-30.

⚠️ The type-naming form was **missing from the table entirely** and is kept: a
`Char` and a `String` both render as `3`, so a message quoting only the rendered
values would read `Expected '3' but got '3'.` Both processors already produce
it. Documenting it was as valuable as fixing the stem.

⚠️ Any change here alters the report, which [TST-008] specifies and which both
processors must reproduce byte for byte — so it is a change to the observable
surface and to `bootstrap/algol.c` in the same breath, not a cosmetic edit.
## Annex E — what could be written in Algol-24 itself *(non-normative)*

The collections and the built-in functions are native today. This annex asks,
for each, whether it is native because it *must* be or only because it always
has been — and what one feature would have to be added to unbind it.

⚠️ **This is the plan, not an idle question.** The intent is to move the
collections out of the core language and into a unit written in Algol-24
wherever they are not genuinely pinned, and this annex is the survey of what
that costs. Annex H, H-9 carries the work; chapter 14 records the behaviour the
unit will have to reproduce.

The reason is the one below, and it is worth more than the tidiness: everything
moved out of the runtime is one less thing the C back end and the interpreter
can disagree about — and Annex C ran to thirty-seven entries, numbered to C-39,
before every one of them was withdrawn.

⚠️ **Three rules did the pinning, and all three are gone.** A class can be
iterated as of Generation 5 [TYP-011], can expose a read-only property as of
Generation 6 [CLS-017], and can be subscripted as of Generation 7 [TYP-010] —
and it can order [VAL-014] and compute [EXP-020] besides. `conformance/0171`
ends with a `Stack` written in Algol-24 that is subscripted, iterated, ordered
and answers `Length` without parentheses. **Nothing in the language pins the
collections to being native any longer.**

⚠️ **What remains is not a language question but a runtime one**, and it is
H-14. A unit is only a saving if it can reach what it needs without the runtime
growing a built-in for every call, or everything removed from chapter 14 arrives
back in chapter 16 and is paid for twice.

⚠️ **This paragraph has now been rewritten in three consecutive staleness
passes**, each time to remove one more thing from the list. That is worth
leaving on the record: an annex that argues from what the language *cannot* do
goes stale exactly as fast as the language improves.

### E.1 The collections

**Array — pinned, and rightly so.**

`Array` is fixed-size, indexed in constant time, and holds arbitrary values.
Nothing in the language can express that. `Buffer` stores bytes rather than
values; a linked structure of class instances gives O(n) access; and a class
cannot be subscripted in any case. It is the one collection that is genuinely
primitive.

*Recommendation:* keep it native, and treat it as the primitive the others are
built on rather than as one collection among five.

**Stack — unbound already, in all but syntax.**

A `Stack` is `Push`, `Pop`, `Peek` and a count over a sequence. It can be
written in Algol-24 today, in full, as a class holding a `List` — and has been:
`spec/probes/TYP-012-stack-and-set-in-algol24.a24` is a working one, beside a
`Set` whose membership test is a hand-written scan using no native `Contains`,
and a `Mod` built from arithmetic alone. All three behave as the built-ins do.

Nothing about it is primitive: no literal claims its name, no subscript is
needed, and its whole surface is method calls.

There is no visible difference left. `S.Length` reads without parentheses as
the built-in's does, now that a class may declare a `property` [CLS-017] — which
was the one thing this entry said it was waiting on.

*Recommendation:* the best first candidate to move into a unit, and it now waits
on nothing of its own. What it waits on is H-14: a unit is only a saving if it
can reach what it needs without the runtime growing a built-in for every call.

**Set — writable today; would want hashing later.**

`Set` needs membership. Over a `List` with a linear scan it can be written
immediately, and the probe named above does exactly that. A hashed version is
also expressible: `Ord` yields a character's code point as an Integer —
`Ord('A')` is 65 — so a string hash can be computed in the language without
reaching for anything native.

Nothing pins it syntactically. `Set(L)` is an ordinary constructor call, not a
literal form.

*Recommendation:* movable, and the performance question is separable — ship the
linear version as a unit, hash it later if it matters.

**List — pinned by its literal, not by its behaviour.**

A growable sequence over `Array`, doubling when full, is straightforward
Algol-24. What pins `List` is syntax: `[1, 2]` produces one, so the language
itself hands the name out. Subscripting [TYP-010] and `for … in` [TYP-011]
would also have to be lifted, or every use would read `L.Get(I)`.

*Recommendation:* unbinding this one is worth doing only if user-defined
subscript and iteration arrive first. Otherwise the unit is strictly worse to
use than the built-in it replaces.

**Map — pinned by its literal, doubly.**

`[:]` and `[k:v]` produce a Map, so the name is claimed the way `List`'s is,
and the natural `M[K]` needs [TYP-010] as well. The implementation itself is
ordinary: two sequences, or `Array` buckets with an `Ord`-based hash.

⚠️ Insertion order is specified behaviour, not an accident of the
implementation, so any replacement must keep it.

*Recommendation:* same as `List`, and after it. The literal is the harder half:
a language that lets a unit claim `[:]` is a much larger language.

### E.2 The built-in functions

| Native | Could it be written in Algol-24? |
| --- | --- |
| `Max`, `Mod` | Yes, today, from arithmetic alone. |
| `Copy`, `Pos` | Yes, from `Length` and subscripting a String, at a cost in speed. |
| `Val` | Yes, given `Ord` for digits. |
| `Ord`, `Char` | No. They convert between a character and its code point, and nothing else reaches that representation. |
| `Length` | No, for `String`. A user type's own length is [TYP-012]. |
| `Str` | No. Rendering a `Double` in the specified shortest round-trip form needs the value's bits, which the language cannot see. |
| `clock`, `TextFile`, `FileExists`, `ParamCount`, `ParamStr` | No. The operating system is not otherwise reachable. |
| `Buffer` | No. It is a memory primitive with an explicit lifetime. |
| `Write`, `WriteLn` | No. Output is not otherwise reachable. |

### E.3 The one feature that unbinds the most

Of the three pins, **[TYP-012], the missing getter, is the cheapest and buys the
most**. It is a declaration form rather than a semantic change; it makes `Stack`
and `Set` writable as units indistinguishable from the built-ins; and it is
needed by ordinary user classes regardless of whether any collection ever moves.

Subscript [TYP-010] is next, and iteration [TYP-011] after it — those two
together are what `List` and `Map` wait on, and both are larger changes, because
each means dispatching a language construct into user code.

---



## Annex F — defects *(non-normative)*

Where the implementation does not do what this specification requires. Each
entry names the rules it violates, what the implementation does today, and the
program in `defects/` that reproduces it.

⚠️ A defect's test is a **reverse conformance test**: it records the wrong
behaviour and passes while that behaviour persists. It turns **red when the
defect stops reproducing**, because a fix is as much a change to be noticed as a
regression — and a suite that is permanently red is a suite nobody reads.

⚠️ **This annex is empty, and that is a result rather than an absence.** It held
thirty-three defects; every one has been fixed and its reproduction removed, so
`defects/` is empty with it. Three of them turned out to be the **rule's** fault
rather than the implementation's, and were closed by changing this document —
`SRC-005` on Unicode identifiers, `LEX-025` on `Char(0)`, and a blocker recorded
in a defect entry that named the wrong data structure. The note at the end of
Annex C keeps that last one, because the lesson is about where a blocker is
written down rather than about the defect.

## Annex G — implementation notes *(non-normative)*

Guidance for implementers. Nothing here is a rule; an implementation may reach
these ends by other means.

### G.1 Reporting a scan error

[ERR-004] specifies the shape of a scan error and that it prevents execution. It
deliberately says nothing about the mechanism, because this implementation's
mechanism has a hazard worth describing rather than mandating.

`compiler/Scanner.a24` **records** rather than raises: it sets `HadError` and
keeps the message in `LastError`, and a driver must ask. Two consequences follow:

- **A driver that does not ask carries on** over a damaged token stream.
  `compiler/Main.a24` calls `CheckScanned` **twice** — once after scanning for
  the right message, and once after parsing so that modules loaded by `uses` are
  covered — and both calls are load-bearing.
- ⚠️ **`HadError` and `LastError` are module-level, not per instance.** Two
  scanners in one process share them, so an error from one is visible to the
  other and a later clean scan does not clear an earlier failure. Nothing in the
  language reaches this — a program cannot construct a `Scanner` — but any tool
  that scans more than one source in a process can.

An implementation that raises instead has neither problem and conforms equally.

### G.2 The cost of `+` on Strings, and what fixes it

**Fixed.** This section is kept because the reasoning is worth having, and
because the fix it proposed was *not* the one that worked.

A String is immutable and `concat` copied both operands, so building one a piece
at a time allocated the sum of the lengths — about n²/2 bytes — and the arena
never reclaims, so all of it stayed live:

| 40,000 appends of `S := S + 'x'` | before | after |
| --- | --- | --- |
| compiled | 807 MB | **1.7 MB** |
| interpreted | 882 MB | **77 MB** |

The interpreted figure still carries the tree-walker's own per-iteration
allocation, which is unrelated; it is linear in n now, where it was quadratic.

⚠️ **This is an allocation-volume problem, not a reclamation one.** A collector
would not help: the bytes are allocated whether or not they are later freed, and
the copying is what makes it quadratic. `Buffer` avoids it by appending in
place, which is why the compiler's own hot paths use one.

⚠️ **The fix this section proposed does not work, and it is instructive.** It
said: append in place when the left operand is *the arena's most recent
allocation* — write at `arena_next`, bump, return the left operand's pointer.

That test **never fires**. `S := S + 'x'` evaluates `'x'` first, and a Char is an
arena allocation, so something always sits between the string and the free
space. The prediction assumed the concatenation was the only allocator in the
statement, and it never is.

**What works is reserving the room in advance.** `concat` allocates double what
it needs and remembers the capacity, so the slack lies *inside* the string's own
block where no later allocation can take it. A subsequent append writes into
that slack; when it runs out, the next copy doubles again. A string built a
piece at a time is then copied a logarithmic number of times rather than once
per piece. No collector, no refcounting, no escape analysis.

⚠️ **What makes it unsafe is that a String is a NUL-terminated `char *`.** Any
other value holding that pointer would see the extension, because its length is
read from the bytes:

```
var A := 'ab' + 'cd';     A is the most recent allocation
var B := A;               B aliases it
var C := A + 'ef';        extending in place would change B
```

⚠️ **An explicit length makes it safe**, and for a reason worth stating exactly:
`B` holds `{p, 4}` and reads only `[0, 4)`, which the append never touches — it
writes at `p + 4` and yields `{p, 6}`. The alias is correct because it carries
its own length rather than looking for a terminator. This is why the two changes
had to land in that order, and they did.

⚠️ **Capacity is not enough on its own: the test must be IDENTITY.** The left
operand has to *be* the string the reserved block currently holds — pointer
**and** length together. Checking only that the capacity fits lets two appends
from one base both succeed, and the second overwrites the first:

```
var A := 'x';   var B := A + 'y';   var C := A + 'z';
```

leaves `B` reading `xz`. This was found by the compiler's own test suite
printing corrupted ANSI escapes, because `Console` builds its tags by
concatenating shared constants — so a shared operand was appended to twice.

⚠️ **The consumers cost less than this section feared.** It expected every
consumer handing a String's bytes to C to need the length. In practice only the
value-semantic operations do — concat, output, equality, hashing, `Copy`, `Pos`,
`Length`, subscript. The twenty-odd places that build a *diagnostic* still want a
plain C string, and get one: `as_text` checks the byte at the length and copies
only when an append has overwritten a terminator, which is one comparison on a
path that almost never takes it.

### G.3 Mangling identifiers into C

The C back end must map an Algol-24 identifier — which may hold `_`, **any
Unicode character**, and the marks `?` and `!` [SRC-005] — onto a C identifier,
which may not.

Because identifiers are case-insensitive [SRC-011], **case carries no
information**, and lowercasing the name is lossless. That frees the entire
uppercase range to act as escape markers:

| Source | Emitted |
| --- | --- |
| any letter or digit | lowercased |
| `?` | `Q` |
| `!` | `E` |
| `_` | `V` |
| any other character | `U` followed by six hexadecimal digits |

⚠️ **The last row is what admits all of Unicode.** `🙂` is U+1F642 and emits as
`U01F642`. Nothing has to be classified or excluded, which is why [SRC-005]
needs no letter table and the language carries none.

`_` remains unused by the mapping and is therefore available as a separator
wherever two escapes would otherwise run together ambiguously.

The per-kind prefixes keep the emitter's names clear of C's. Every one is built
by a constructor of its own, never by concatenating a prefix by hand:

| | |
| --- | --- |
| `v_` | a variable, or a constant — a `const` differs in what may assign to it, not in how it is stored |
| `d_` | the flag saying a file-scope variable's declaration has run [DCL-016] |
| `c_` | a **cell**: a variable a nested function captured, which lives on the heap |
| `f_` | a subprogram |
| `fn_` | its closure, so the name can be used as a value [FUN-011] |
| `o_` | the set of subprograms sharing one name — or a lone **variadic** one, whose C symbol takes a fixed count and so cannot answer an absorbing call [FUN-013], [FUN-005] |
| `k_` | a class or an object |
| `i_` | its field initializer |
| `m_` | a method, with its signature |
| `e_` | an enumeration, and with a member appended, one of its members |
| `t_` | the **parameter list** a subprogram or method was declared with, as a static array the runtime selects against |
| `lb_` | where a labelled `break` lands — after the loop [STM-010] |
| `lc_` | where a labelled `continue` lands — the last thing in the loop's body, so falling off the end runs the C `for` increment |
| `lg_` | where a `goto` lands [STM-024] |

⚠️ A prefix names a *kind*, so a name that reaches C twice reaches it through
two constructors rather than one string built by hand: `d_` goes through
`Mangle` exactly as `v_` does, or a variable spelled `Gate?` would have a legal
symbol and an illegal flag.

⚠️ Symbols not derived from a name at all — a hoisted literal, a method's
parameter-type table, a test body, a `try` frame — are numbered rather than
mangled, and need none of this.

⚠️ **This scheme is injective, and the one it replaced was not.** That one wrote
`?` as `_q` and passed letters through untouched, so `Ready?` and `Ready_q`
emitted one symbol between them and `cc` refused the result. Here they are
`readyQ` and `readyVq`.

⚠️ **The same argument answers the escape's own collision.** An identifier
spelled `U01F642` and the character `🙂` would both want that symbol; lowercasing
separates them into `u01f642` and `U01F642`.

⚠️ The two decisions depend on each other. Lowercasing is only lossless because
identifiers are case-insensitive, and the uppercase escape space only exists
because of the lowercasing. Neither works alone.

⚠️ **`_` is escaped to `V` rather than passed through**, which is what leaves it
free as a separator. A caller joining parts — a method's owner and name, an
enum's type and member, a private name and its unit — escapes each part and puts
a raw `_` between them. Escaping the *joined* string instead would put the
separator back into the alphabet the escape uses: `Name__Unit` would give
`nameVVunit`, which an identifier spelled `NameVVUnit` also gives.



---

---

## Annex H — planned for later generations *(non-normative)*

Changes intended for the language that are **not defects**. The implementation
is right about these; the specification describes the language as it now is, and
each of these will change a rule when it arrives.

⚠️ The distinction matters to the corpus. A defect gets a reverse conformance
test that passes while the wrong behaviour persists. A planned change gets an
ordinary conformance test or refusal pinning the **current** rule, which turns
red when the generation lands — deliberately, because that is the moment the
rule changes and the test should change with it.

**H-1 — Other bases and digit separators.**
***Landed in Generation 3.*** *(changed [LEX-016])*

Hexadecimal, octal and binary integer literals, and a separator within a run of
digits. Now covered by `conformance/0006-integer-bases-and-separators.a24`; the
refusal that pinned the old rule went with the generation.

**H-2 — Exponent notation.**
***Landed in Generation 3.*** *(changed [LEX-022])*

A double literal with an exponent. Now covered by
`conformance/0007-exponent-notation.a24`.

⚠️ This one closed a genuine asymmetry rather than only adding a convenience:
`Str` **prints** a large Double in exponent form — `1.0E300` — and the language
could not read back what it wrote. Nothing was unreachable, because `Val` parses
the exponent form, but the round trip went through a built-in rather than
through the source.

**H-3 — Element types checked on insertion.** *(will change [VAR-016])*

An element type constrains what may be put into a collection, so
`L.Add ('text')` on a `List of Integer` is refused. Today it is a source of
types for reads only and insertion is unchecked. Pinned by
`conformance/0021-element-types-flow-to-reads.a24`, whose `Add` line is the part
that will change.

⚠️ Larger than it looks, and the reason it is not being done now: every route
into a collection has to be covered — `Add`, `Put`, `Push`, subscript
assignment, and the collection literals — or the check becomes a fence with a
gate in it, which is worse than no fence because it invites the declared type to
be trusted.

**H-4 — A subscript operator a class may declare.**
***Folded into H-15.*** *(will change [TYP-010])*

Subscripting turned out not to want an operator declaration at all: it is a
structural protocol, and landed as **H-15** in Generation 7.

⚠️ **The entry is kept for the record, not for a pointer.** It was kept at first
because [TYP-010] and [EXP-016] said "see Annex H, H-4"; both were rewritten
when H-15 landed and neither says it now. What it still earns its place for is
the history — this number was proposed as a *subscript operator*, folded into
operator overloading as "the same feature in a particular spelling", and finally
turned out to want no operator at all. A reader meeting the gap between H-3 and
H-5 should find out that a question was asked and answered differently, rather
than that a number was skipped.

**H-5 — An iteration protocol a class may implement.**
***Largely landed in Generation 5.*** *(changed [TYP-011], [CLS-009])*

A class declaring `Elements` taking no arguments is iterable, and always was —
the interpreter's `ElementsOf` and the runtime's `alg_iterable` both had it, in
agreement. What was missing was the **rule**, and an unspecified protocol had
already drifted: an `Elements` of the wrong arity failed differently in the two
processors, and a `Contains` of the wrong arity answered `1 in B` with **true**
interpreted while raising compiled — a wrong answer, not merely a wrong message.
[TYP-011] now states the protocol and both sides check the shape.

⚠️ **What is left is not iteration but its neighbours.** Two questions the
protocol raises and does not answer:

| | |
| --- | --- |
| A class that iterates like a `Map` | A built-in `Map` yields its **keys** [STM-007]. A class can return a list of keys, but has no way to say it is pair-shaped, so `for var K in M` and a user-written map cannot mean the same thing. |
| `Elements` returning `this` | The result is walked rather than re-asked, which stops the ordinary chain from recursing — but a class whose `Elements` answers itself recurses without bound in both processors. |

⚠️ **Membership has no rule of its own.** `Contains` on a class instance is
implemented in both processors and specified nowhere: [COL-012] governs the
*equality* membership uses, not the protocol that lets a class answer it. The
same paragraph [TYP-011] now carries for `Elements` is owed to `in`.

**H-6 — A read-only property a class may expose.**
***Landed in Generation 6.*** *(changed [TYP-012]; added [CLS-017], [CLS-018])*

`property Count : Integer; begin Exit Items.Length; end` — a member kind beside
`function` and `procedure`, read without parentheses, with the read being the
call. Assignment is refused where the receiver's type is known.

⚠️ **The need was a read-only view, not parentheses.** A field is public —
readable *and writable* — or private, meaning invisible, so a `Stack` written in
Algol-24 could not protect its own count while showing it, and was strictly
worse than the built-in whose `Length` cannot be assigned.

⚠️ **The runtime is told at the DECLARATION, not asked at the call.** Nothing at
a use site says whether `B.Count` is a field, a method or a property, and the
receiver's class is not known until run time — so `alg_class_property` marks the
member when the class is built and `alg_property` reads the mark.

⚠️ **The sigil half was withdrawn before any of this was built.** An earlier
shape made a bare `B.Length` on a method an error and introduced `@` to replace
it; that displaced a construct which works and is specified [FUN-011] in order
to free a spelling.

⚠️ **It found a divergence older than itself** [CLS-018]. Instances were open in
the interpreter and closed in the compiled back end — Lox's arrangement against
fixed slots — so `B.Undeclared := 1` was `1` interpreted and refused compiled.
No case covered it, and a unit test inherited from Lox was holding the
interpreter's half in place.

**H-7 — Ordering for Strings.**
***Landed in Generation 6.*** *(changed [VAL-014], [COL-013])*

`'ab' < 'cd'` was the runtime error `Operands must be numbers.`, so a program
needing to order text compared it character by character — which is what
`compiler/CEmitter.a24`'s `TextLess` did, a function the compiler wrote for
itself because the language did not provide the operator. `TextLess` is gone.

⚠️ **One change in the runtime served both processors.** The interpreter's
`VisitBinary` evaluates `Left < Right` in the host language, so interpreted `<`
*is* `alg_less` — the arrangement that makes interpreted `Length` and host
`Length` one function [RT-003]. Teaching the four comparison operators about
text gave the tree-walker the same ordering in the same commit, with nothing in
`Interpreter.a24` to change.

⚠️ **It uncovered an older fault than itself.** `Char` ordering compared
`a.string[0]` — the first **byte** of a UTF-8 encoding — so `'è'` and `'é'`
shared a lead byte and compared **equal**, while `Ord` answered 232 and 233. The
language disagreed with itself about which of two characters came first, in both
processors alike, and no case covered it because [VAL-014] never said how Chars
order.

⚠️ **And a second ordering nobody had noticed.** `Sort` compared with `strcmp`
[COL-013] — bytes rather than characters, stopping at an embedded zero a String
is entitled to hold. It agreed with the new operator only because UTF-8 is
designed so byte order matches code-point order, which is right by accident.
Both now go through one function.

**H-8 — Arithmetic operators a program may define.**
***Landed in Generation 7.*** *(added [EXP-020])*

`+`, `-`, `*`, `/`, `div` and unary `-` on a program's own type, declared
`operator + (Other : Money) : Money;`.

⚠️ **What is left of an entry that once claimed most of this annex.** It called
itself "the umbrella over much of Annex H"; H-6's property and H-7's ordering
landed in Generation 6 without it, and subscripting (H-15) and comparison
(H-16) landed in Generation 7 as **protocols**. Arithmetic was the only part
that wanted an operator declaration.

⚠️ **The one place a keyword beat a protocol, after six protocols in a row.**
`Compare`, `Get` and `Put` are not translations of operators — `Compare` yields
four of them, `Get` and `Put` are two halves of one — while a `Plus` method
would be a pure synonym for `+`: a name added without a concept. Where the name
says something the symbol does not, the protocol wins; here it would not.

⚠️ **Adding the keyword broke the compiler's own source**, which is the hazard
this repository has met before: `Operator` was a local variable in
`Parser.a24`, sixteen times over, and became unspellable the moment the word
was reserved. The same collision renamed `Break` to `Broke` and Lox's
`Expr.Get.object` to `Obj`. The language's word wins and the compiler adapts.

⚠️ **The left operand decides**, as a receiver does everywhere else.
`Money * 3` is a Money; `3 * Money` is `Operands must be numbers.`

**H-9 — The collections as a unit written in Algol-24.**
*(will retire most of chapter 14)*

Everything in chapter 14 that is not genuinely pinned moves out of the core and
into a unit written in Algol-24. Annex E is the survey of what is pinned and by
what; in short:

| | |
| --- | --- |
| `Array` | **stays.** Fixed-size, constant-time, holding arbitrary values — nothing in the language can express it, and it is the primitive the others are built on. |
| `Stack` | movable today. Its whole surface is method calls and no literal claims its name. The best first candidate. |
| `Set` | movable today with a linear scan; hashable later using `Ord`. |
| `List` | pinned by `[…]` alone now. Subscripting and iteration both arrived, so what holds it is the literal claiming its name and nothing else. |
| `Map` | pinned by `[:]` and `[k : v]`. `M[K]` is answerable now through `Get` and `Put` [TYP-010], so the literals are all that remain. |

⚠️ **H-14 comes first.** Moving a collection out is only a saving if the unit
can reach what it needs without the runtime growing a built-in for every call —
otherwise everything removed from chapter 14 arrives back in chapter 16, and
this is paid for twice.

⚠️ **Nothing in the language is owed any longer.** Iteration landed in
Generation 5 [TYP-011], a read-only property in Generation 6 [CLS-017], and
subscripting, ordering and arithmetic in Generation 7 [TYP-010], [VAL-014],
[EXP-020]. A `List` written in Algol-24 reads `L[0]`, answers `L.Length` without
parentheses, walks in a `for ... in` and orders — so it is no longer strictly
worse to use than the built-in it would replace, which is what made the trade
not worth making.

⚠️ **[COL-007] is the constraint that outlives the move.** Insertion order is
specified for every collection, `Set` and `Map` included, so a unit is a third
implementation bound by it exactly as the two processors are.

⚠️ **The point is Annex C.** Everything moved out of the runtime is one thing
the two processors can no longer disagree about — which is worth doing even now
that the annex has no open entry, because it removes the *opportunity* rather
than the current instance. `spec/probes/TYP-012-stack-and-set-in-algol24.a24` already holds a
working `Stack` and `Set` written in the language, so the path is not
speculative.

⚠️ When a collection moves, its rules leave this specification and its
conformance cases become **unit tests of the unit**. A rule retired because its
subject became a library has not been falsified — the distinction matters to
anyone reading `conformance/` later and wondering where the cases went.

**H-10 — Varargs from an element type.**
***Landed in Generation 4.*** *(changed [FUN-005], [RT-001])*

A subprogram whose **last parameter is a `List of T`** may be called with the
elements written directly, and the call builds the list:

| written | means |
| --- | --- |
| `Log ('warn', 1, 2)` | `Log ('warn', [1, 2])` |
| `Log ('warn')` | `Log ('warn', [])` |

Both columns are legal, and the right-hand one wins where they meet.

⚠️ **No new syntax, and that is the design rather than an economy.** The
declaration already says `List of T` [VAR-008]; absorption is a *reading* of a
type that exists, not a marker added to it. It became possible only when element
types were admitted on parameters — before that a bare `List` carried no element
type, and the trailing arguments would have had nothing to be checked against.

⚠️ **"Fixed arity beats variadic" is not a rule here, it is the pass order.**
Selection is already two passes, exact before widening [EXP-014]. Absorption is
a third, so an exact match always wins and `Log ('warn', [1, 2])` passes the list
rather than absorbing it into a one-element one. The tiebreak that other
languages state in prose falls out of machinery this language already has.

⚠️ **The element type replaces the arity check and is stricter than it.**
`Log ('warn', 1, 2, 'red')` is still an error when the parameter is
`List of Integer`, because the stray argument fails the element type. What is
given up is given up only for `List of Any`, which is already the declaration
that means "anything".

⚠️ **Absorbing zero is what makes `WriteLn` ordinary**, and is the case that
decided it. `WriteLn` was a native of arity −1 with a hand-written branch on
`Arguments.Length = 0`; rendering the whole argument list gave `''` for none,
so the blank line stopped being a special case and `WriteLn ('ABC', 123)` —
which had not been legal — arrived with it [RT-015]. Requiring at least one
argument was considered and rejected on that example alone. The empty list is **structural, not a default**:
absorbing nothing yields `[]` by the same rule that absorbing three yields a
three-element list, so this is not default arguments under another name.

⚠️ **The cost is one list per call, and this runtime never frees one** — the
arena has no collector. The mitigation is expressible in the language and
changes no call site: declare a fixed overload beside the variadic one, and the
exact pass takes the hot calls without allocating.

    procedure WriteLn (S : String);           // exact pass -- builds nothing
    procedure WriteLn (Items : List of Any);  // absorption pass

**H-11 — Named arguments.**
***Landed in Generation 4.*** *(changed [EXP-013])*

An argument may name the parameter it fills — `Log (Level: 'warn', Items: [1])`.

⚠️ **The point is overload selection at compile time.** Selection is at run
time, from the values actually passed [FUN-013], because a declared type may be
`Any` and no static rule could reach the right overload from that. That is the
right default for a gradually typed language and it does not change. What is
missing is a way for a programmer who *does* know which overload they mean to
say so, and naming the parameters says it — a name identifies one signature,
where values only describe something several signatures might accept. Static
resolution becomes **available**, not mandatory.

⚠️ **`:` rather than `=>`, because the language already has this colon.**
`[k : v]` is a Map literal [COL-001]: a name on the left, a value on the right,
parsed by reading an expression and then looking for a colon. A named argument
means the same thing and parses the same way. `=>` would be a second punctuation
for a meaning already spelled.

⚠️ **The ambiguity that usually rules `:` out is absent here.** A colon in
expression position normally collides with a conditional expression's `? :`;
this language has no conditional expression, because `?` is an identifier mark
[LEX-008] and `Gate?` is one word. The `:` in `case … of` is a statement's.

⚠️ **Positional arguments first, named ones after.** A positional argument
following a named one is refused, as is a parameter supplied twice.

⚠️ **Which is also why H-10 needs no rule about the two meeting.** Absorption
takes trailing *positional* arguments, and positional arguments end exactly
where naming begins. `Log ('warn', Items: [1, 2])` names the absorbing parameter,
so nothing absorbs; `Log ('warn', 1, 2, Items: [3])` supplies it twice and is
caught by a rule named arguments need anyway. The two features share one rule
set, which is the argument for bringing them in one generation rather than two.

**H-12 — A warning for a call that binds at run time.**
***Landed in Generation 4.*** *(a diagnostic, not a rule)*

A third severity beside `[INFO]` and `[ERROR]` — **`[WARN]`, in yellow** —
reporting that a call selects among overloads at run time rather than
statically. Non-blocking: the program compiles and runs.

    [WARN] Main.a24:12: 'Log' selects among 3 overloads at run time.

⚠️ **It makes a cost visible without forbidding it.** Run-time selection is the
language's rule and stays so [FUN-013]; H-11 gives a programmer the means to
avoid it in a particular call. The warning is what connects the two — without it
the cost is real and invisible, and the remedy has nothing to point at.

⚠️ **It is silent on this compiler**, which is the evidence that it is a scalpel
and not noise: no top-level name in `compiler/*.a24` is overloaded, so over a
hundred kilobytes of Algol-24 raise no warning at all.

⚠️ **The corpus has to drop it, from both sides.** This entry predicted that
standard error would be the answer; it is not, because `Console` writes every
diagnostic this compiler produces — `[INFO]` and `[ERROR]` included — to
standard output, and `conform.sh` captures both streams anyway. The real
difficulty is the one the prediction was reaching for: the front end is shared,
so a warning appears when an interpreted program *runs* and when a compiled one
is *emitted*, which are different moments. `render()` therefore filters `[WARN]`
lines out of both sides before comparing.

⚠️ **Dropped rather than suppressed.** The warning is meant to be seen by
whoever is compiling; it is only the comparison that must not see it. A warning
that changed a program's recorded output would be a warning that changed the
program — and this one changes nothing, which is what *non-blocking* means.

⚠️ **The tag belongs in `Console.a24` beside the other two.** `ANSI_YELLOW` is
already defined there, and `WARN_TAG` follows `INFO_TAG` and `ERROR_TAG`
exactly — including the ⚠️ those two carry about their names: `WARN_TAG` rather
than `WARN`, because names are matched without regard to case [SRC-011] and a
`procedure Warn` beside it would be the same name.

**H-13 — Character arithmetic, the Pascal way.**
***Landed in Generation 6.*** *(changed [EXP-008], [RT-001]; added [EXP-019], [RT-020])*

`'z' - 'a'` is 25, `Succ` and `Pred` step an ordinal, and `'a' + 1` is refused.
Turbo Pascal's model with one departure: TP answers a distance with
`Ord (X) - Ord (Y)`, which stays available and says the same thing at greater
length.

⚠️ **Refusing `'a' + 1` was the repair, and the reason to do this.** `Str` is how
a Char widens to a String — that is why `Line ('{')` must be declared `Any` —
yet `'a' + 1` and `Str ('a') + 1` both gave `a1`, so in that one place widening
happened without being asked for and `Str` was decorative. The two differ now.

⚠️ **The C model was declined.** `'a' + 1` yielding `'b'` puts arithmetic on `+`
and makes the operator mean a step or a join depending on its right operand.
`Succ` costs one word, says what it does, and leaves `+` meaning one thing.

⚠️ **Breaking in the safer direction**, and the blast radius was measured before
the change: no `Char + Integer` appears anywhere in `compiler/*.a24`, and the
expression becomes an **error** rather than quietly computing something else.

⚠️ **An enum member is not stepped** [RT-020]. A member carries its type's name
and its ordinal rather than a pointer to the type, so there is no way from a
member to the list it belongs to — the gap is honest rather than chosen.

**H-14 — A foreign function interface.** *(will change [RT-001], and more)*

A way to declare and call a C function directly, so that the built-ins can stop
being a closed set of twenty-eight names the runtime has to carry.

⚠️ **This is the prerequisite for H-9, not a companion to it.** Moving the
collections into a unit written in Algol-24 is only a saving if the unit can
reach what it needs without the runtime growing a built-in for every call it
wants — otherwise each thing removed from chapter 14 arrives back in chapter 16.
Taken in the other order, H-9 would be paid for twice.

⚠️ **The interpreter is the difficulty, and it is a real one.** A compiled
program can call anything it is linked against — the back end already emits C
and the runtime already is C. The tree-walker cannot: it would need `dlopen`,
`dlsym` and a way to marshal a tagged `Value` into a C calling convention it
does not know at compile time. An FFI that works compiled and not interpreted
would be a **gap by construction**, and a generation is not complete until both
processors pass every case.

⚠️ **Which makes the shape of the declaration the whole design.** A signature
narrow enough that the interpreter can dispatch it from a fixed table of
supported forms is a different feature from one that admits arbitrary C, and
choosing between them is the first decision, not a detail of it. The narrow one
may be enough: what the collections actually need is memory, comparison and
counted loops, not the whole of libc.

⚠️ **It also changes what "the two processors agree" can mean.** A foreign call
has behaviour this specification does not define and cannot check, so the rules
will have to say where conformance stops — the first place in this language
where that sentence has to be written.

**H-15 — Subscripting through `Get` and `Put`.**
***Landed in Generation 7.*** *(changed [TYP-010], [EXP-016])*

`B[0]` calls `B.Get (0)` and `B[0] := X` calls `B.Put (0, X)`. The fifth
structural protocol, needing no member name of its own — `Get` and `Put` are
what the built-in collections already answer to [COL-003].

⚠️ **It wanted no operator feature at all**, which is the change of mind this
entry records. It was H-4, folded into operator overloading as "the same feature
in a particular spelling"; asking what it actually added turned up one thing —
that it needs **two** members where every other operator needs one — and that
question answers itself the moment the two are ordinary members of different
arity.

⚠️ **A class declaring only `Get` is readable and not assignable**, and needs no
separate way of saying so.

⚠️ **This is what the protocol run was for.** A `Stack` written in Algol-24 is
now subscripted, iterated [TYP-011], ordered [VAL-014] and answers `Length`
without parentheses [CLS-017] — the four things Annex E named as pinning the
collections to being native. `conformance/0171` ends with one.

**H-16 — Ordering through `Compare`.**
***Landed in Generation 7.*** *(changed [VAL-014])*

A class declaring `Compare (Other) : Integer` orders with `<`, `<=`, `>` and
`>=`. The fourth structural protocol, needing no declaration keyword and raising
no precedence question, because `<` already has a precedence.

⚠️ **It cost nothing equality would**, which is why it is settled and H-17 is
not: ordering touches no hash and no membership, so no second protocol has to
move with it.

⚠️ **"And `Sort` gets it for free" was wrong**, and the entry said it before it
was built. `Sort` gets it free *compiled* — the interpreter delegates `Sort` to
the host's, whose values are `ObjInstance`, this compiler's own class rather
than the program's, so the host looks for `Compare` there and never finds it.
Answering compiled while refusing interpreted is the divergence the corpus
exists to catch, so the runtime's `Sort` does not ask either. Sorting by
`Compare` wants an interpreter inside `ObjCollection` and is its own work.

⚠️ **The interpreter could not delegate the operators either**, for the same
reason, and this is the fourth protocol to hit it — `Ord` on an enum member and
`Stringify` on a `ToString` were the first two. `VisitBinary` replaces the
operands with the `Compare` result and `0`, so the four comparisons below it run
unchanged rather than being written a second time.

**H-17 — Equality, and the hash that must come with it.**
*(will change [VAL-011], [VAL-013])*

A class deciding what `=` means for its instances. Today comparison is by
**identity** [VAL-011] with no way to say otherwise, so two values that are
alike are never equal.

⚠️ **The coupling is the whole difficulty, and it is a rule rather than an
implementation detail.** [VAL-013] states that membership and equality are one
relation: *if `X = Y` then a collection holding `Y` contains `X`*. A Map and a
Set bucket by a hash, and an object key hashes by its **address** — so the
moment two distinct instances compare equal, `A = B` is true while `B in [A]` is
false, and a specified rule is broken silently.

⚠️ **Which is exactly why Java pairs `equals` with `hashCode`**, and the
discipline is the argument *for* this feature rather than against it: the two
must move together, so a language that offers one must offer the other and say
so. Java cannot enforce the pairing either; what it does is make the obligation
explicit and famous.

⚠️ **The fixed point is NOT an obstacle, though it first looked like one.**
`ObjMap`'s index carries a warning that an address-keyed hash deciding iteration
order would make the fixed-point check fail intermittently — "the worst failure
mode this project has", and a bug already made once. Reading it again: it
describes a design that was **rejected**. Entries stay in insertion order and
nothing iterates the index, which is what makes the index legal. A user-defined
hash changes which bucket a key lands in and not the order anything is read in,
so the hazard is already neutralised structurally.

⚠️ **What it does need is both processors**, as ever: an interpreted `Equals`
and a compiled one, and a hash protocol in each, agreeing exactly. That is the
real size of the entry.
