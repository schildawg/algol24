# The Algol-24 Programming Language Specification

> **Algol-24 v0.1.0.** Nineteen chapters and three annexes, 280 rules. Every
> rule is decided — what the language should do — and every rule is claimed by a
> case: a program in `conformance/`, a refusal in `refusals/`, or a reproduction
> in `defects/`.
>
> This document describes the language and nothing else. Where the
> implementation disagrees with it, `spec/DEFECTS.md` records the difference and
> carries a program that reproduces it. How the language arrived — the
> divergences that were closed, the questions that were settled, the changes once
> planned — is in `spec/HISTORY.md`.

---

## 1. Introduction

Algol-24 is a retro-modern, gradually typed language: classic Pascal syntax over
unbounded integers, full Unicode, gradual types, closures and a foreign function
interface. This document specifies its lexis, syntax, and semantics.

### 1.1 Authority

**This specification is the authority.** Where an implementation differs from
a rule, the implementation is in error, and the difference is recorded in
`spec/DEFECTS.md` with a program that reproduces it.

That was not always so. Every rule here began as a description of what the
tree-walking interpreter in `compiler/*.a24` does, verified by **running** it
rather than by reading it — and most rules still are exactly that. A rule is
only allowed to depart from the implementation by an explicit decision, and when
it does it carries a marker:

> **NOT YET IMPLEMENTED.** … See DEF-nn.

**A rule without such a marker describes behavior that was observed.** A rule
with one describes behavior that was decided. The distinction is what keeps the
document trustworthy, and it is why the markers are in the normative text rather
than in an annex.

**The specification does not hedge.** Where a behavior is kept despite
looking wrong, it is stated flatly. A specification that argues with itself
cannot be conformed to.

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

    unit         Scan A Whole Program
    conformance  TBD

**Identifiers are permanent.** They are assigned once, never reused and
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

**`unit` is not conformance evidence, and the distinction is not pedantic.**
A unit test reaches into algc's own classes — it constructs a `Scanner` and
asserts token types — so it tests the implementation, not the language. It is
still worth citing, because [1.1] makes the interpreter normative and a test
pinning the interpreter's behavior therefore pins the language's. But another
implementation has no `Scanner` class to test, so a unit test can never be run
against it. Only a conformance program can.

**Every rule is claimed by a case**, cited as `conformance`, `refusal` or
`defect`. Which of the three is decided by one question — is the interpreter
right? — and `conformance/README.md` explains it. Where no case existed the
value was the literal `TBD`, so the gap was stated rather than left to be
discovered; **that backlog is now empty**, and `spec.sh` still requires the line
so a new rule cannot be added without one.

A rule may cite more than one, and most cases pin more than one rule. A
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

A quoted token in this document is matched **case-insensitively if it is a
keyword** and exactly otherwise. See [SRC-010].

---

## 3. Source code representation

### 3.1 Characters

**[SRC-001]**  Source text is **UTF-8**. A character, not a byte, is the unit
of measurement and of subscripting.

A String carries its own **byte length** beside its pointer, so it may hold a
zero character. It is NUL-terminated as well, which keeps `as_text` cheap for
everything that builds a diagnostic; only the value-semantic operations —
concat, output, equality, hashing, `Copy`, `Pos`, `Length`, subscript — consult
the length.

    unit         Scan A Whole Program

##### conformance/0128-text-is-characters.a24

```algol24
var S := 'café';

WriteLn (Length (S));
WriteLn (S[3]);
WriteLn (Copy (S, 1, 3));
WriteLn (Pos (S, 'é'));
WriteLn (Ord (S[3]));

// A Char is a Unicode code point, and Char and Ord are inverses across the
// whole range [LEX-025].
WriteLn (Char (233));
WriteLn (Ord (Char (233)) = 233);
WriteLn (Length (Str (Char (233))));

// A one-character literal is a Char however many BYTES it takes [LEX-023].
WriteLn ('é' is Char);

// ANY Unicode character may appear in an identifier [SRC-005], and the
// scanner admits every byte above 127 without classifying it [SRC-002].
var café := 3;
WriteLn (café);

// Any script, and no category test -- there is nothing above U+007F that is
// excluded, so the language needs no Unicode tables.
var 日本 := 4;
var Ωμέγα := 5;
WriteLn (日本 + Ωμέγα);

// Including an emoji, which may also LEAD a name -- only a digit and the
// marks '?' and '!' may not [LEX-007].
var 🙂 := 'happy';
var 💩 := 'oops';
WriteLn (🙂 + ' ' + 💩);

// A Unicode DIGIT is an ordinary identifier character too.  Only ASCII 0-9 are
// digits to the number scanner, so this can never start a numeric literal.
var ٠x := 6;
WriteLn (٠x);

// Folding is ASCII-only [SRC-011], so these are two names, not one.
var Straße := 'ok';
WriteLn (Straße);
```

```console
$ algc conformance/0128-text-is-characters.a24
4
é
afé
3
233
é
true
1
true
3
9
happy oops
6
ok
```

##### conformance/0131-a-string-holds-a-zero-character.a24

```algol24
var S := 'a' + Str (Char (0)) + 'b';

WriteLn (Length (S));
WriteLn (Ord (S[1]));

// Equality compares the bytes it has, rather than stopping at the zero.
WriteLn (S = 'a' + Str (Char (0)) + 'b');
WriteLn (Copy (S, 1, 2) = Str (Char (0)) + 'b');

// And so does the hash, or a Map would not find a key it holds.
var M := [S : 'held'];
WriteLn (M.Contains ('a' + Str (Char (0)) + 'b'));

// Characters are still characters [SRC-004].
WriteLn (Length ('café'));
```

```console
$ algc conformance/0131-a-string-holds-a-zero-character.a24
3
0
true
true
true
4
```

**[SRC-002]**  Outside comments, string literals and character literals, every
character must be one the scanner recognizes — a letter [SRC-005], a digit, or
an operator or item of punctuation [LEX-012]. Any other is an error reading
`[line N] Error: Unexpected character: C`.

The scanner used to refuse every non-ASCII byte outright, so no Unicode
character could appear in a program at all outside a comment or a literal.

    unit         Scan Unrecognized Character Is Recorded

##### refusals/0001-unexpected-character.a24

```algol24
// '$' is not a character the scanner recognizes.
var A := 1;
$
```

```console
$ algc refusals/0001-unexpected-character.a24
Uncaught: [line 3] Error: Unexpected character: $
exit: 70
```

**[SRC-003]**  Inside a comment, a string literal or a character literal, any
byte is permitted and is carried through unchanged. A program may therefore
hold text in any encoding, and the language will neither interpret nor validate
it.

##### conformance/0001-source-is-utf8-text.a24

```algol24
// Any byte is permitted inside a comment or a literal: café, naïve, 日本語.
WriteLn ('café');
WriteLn ('日本語');
```

```console
$ algc conformance/0001-source-is-utf8-text.a24
café
日本語
```

**[SRC-004]**  `Length` of a String is its count of **characters**, and
subscripting a String yields the character at that position. `Length('café')` is
4, and `'café'[3]` is `é`.

The same holds for every operation that counts or indexes text — `Copy`, `Pos`,
and `Ord` [16.2].

**Counting characters came out faster than counting bytes**, which is not the
direction it looks. Subscripting text used to call `strlen` on the whole string
for every character, so the scanner walked its entire source once per character
read — quadratic, and nothing had noticed. Caching a string's character count
by pointer removed that: measured over three runs of `./test.sh`, 20.1 s against
21.2 s before.

    conformance  0128-text-is-characters.a24

**[SRC-002] and [SRC-003] together mean an identifier is ASCII while a
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

**There is no category test, and that is deliberate.** Nothing above U+007F
is excluded, so the language needs no Unicode tables at all — Annex G.3's
mangling escapes whatever C cannot spell as `U` followed by six hexadecimal
digits, and there is nothing left for a classification to decide.

This briefly read `unicode_letter` literally, and the implementation grew a
659-range table of categories Lu, Ll, Lt, Lm and Lo to match. That excluded `🙂`
and `💩`, which are identifiers here, and the table answered a question the
language does not ask. Both were removed.

A Unicode **digit** is therefore an ordinary identifier character. Only ASCII
`0`–`9` are digits to the *number* scanner, so `٠` cannot start a numeric
literal, but it may appear in a name.

`decimal_digit` and `identifier_mark` are still ASCII, and a digit or a mark
may not **lead** [LEX-007]. A character above U+007F may.

    unit         Scan Identifier With A Question Mark

##### conformance/0002-letters-and-digits.a24

```algol24
var Gate? := 1;
var _under := 2;
var a1b2 := 3;
WriteLn (Gate? + _under + a1b2);
```

```console
$ algc conformance/0002-letters-and-digits.a24
6
```
    conformance  0128-text-is-characters.a24

##### conformance/0139-unicode-identifiers.a24

```algol24
var café  := 1;
var Straße := 2;
var 日本   := 4;
var Ωμέγα := 8;
WriteLn (café + Straße + 日本 + Ωμέγα);

// An emoji may LEAD a name; only a digit and the marks may not [LEX-007].
var 🙂 := 'happy';
var 💩 := 'oops';
WriteLn (🙂 + ' ' + 💩);

// A Unicode DIGIT is an ordinary identifier character.  Only ASCII 0-9 are
// digits to the number scanner, so this can never start a numeric literal.
var ٠x := 16;
WriteLn (٠x);

// The marks, which are ASCII and trail only.
var Gate?  := 32;
var Gate!  := 64;
var Ready_Set := 128;
WriteLn (Gate? + Gate! + Ready_Set);

// TWO NAMES THAT MUST NOT COLLIDE, which is why these two.  A mangling that
// wrote '?' as '_q' and passed letters through untouched would emit ONE symbol
// for both, and cc would refuse the result.  Escaping is injective: they are
// 'readyQ' and 'readyVq'.
var Ready?  := 'from the mark';
var Ready_q := 'from the letters';
WriteLn (Ready? + ' / ' + Ready_q);

// And the collision the NEW scheme has to avoid in turn: an identifier
// spelled like an escape.  Lowercasing is what separates them -- 'u01f642'
// against 'U01F642' -- which is why case-insensitivity [SRC-011] and the escape
// space depend on each other.
var U01F642 := 'spelled out';
WriteLn (U01F642 + ' / ' + 🙂);

// Folding is ASCII-only [SRC-011], so these stay two names.
var STRASSE := 256;
WriteLn (Straße + STRASSE);
```

```console
$ algc conformance/0139-unicode-identifiers.a24
15
happy oops
16
224
from the mark / from the letters
spelled out / happy
258
```

**An identifier mark is not a letter.** `?` and `!` may appear *within* an
identifier but may not begin one [LEX-007], so `Gate?` and `Gate!` are each a
single word — one word to the scanner, and one word to double-click — while `?`
and `!` alone are not identifiers at all. `_` is a letter and may lead.

Neither mark is an operator. The language spells negation `not` and inequality
`<>`, so nothing else wants the characters.

### 3.3 Line termination

**[SRC-006]**  A line ends at `#10`. A `#13` immediately preceding it is part of
the terminator and is absorbed with it, so a file with CRLF endings and the same
file with LF endings report identical line numbers.

The two cases below are a **pair**, and neither proves the rule alone: they
are the same program with different line endings, and the rule is that they
report identically.

    unit         Scan Newline
    unit         Scan Comment Ends At Newline

##### conformance/0006-line-endings-lf.a24

```algol24
var A := 1;
var B := 2;
$
```

```console
$ algc conformance/0006-line-endings-lf.a24
Uncaught: [line 3] Error: Unexpected character: $
exit: 70
```

##### conformance/0006-line-endings-crlf.a24

```algol24
var A := 1;
var B := 2;
$
```

```console
$ algc conformance/0006-line-endings-crlf.a24
Uncaught: [line 3] Error: Unexpected character: $
exit: 70
```

**[SRC-007]**  Any **other** `#13` is not a terminator. In source it is
whitespace [SRC-008]; in data it is ordinary text that `ReadLn` returns
[RT-016].

A file whose only line endings are `#13` therefore holds **one line**, in
source and in data alike. Every diagnostic in such a source file reports
`line 1`.

A sharper consequence, from this rule meeting [LEX-001]: a comment runs to
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

##### conformance/0007-carriage-return-only.a24

```algol24

```

```console
$ algc conformance/0007-carriage-return-only.a24
```

##### conformance/0009-comment-swallows-a-cr-only-file.a24

```algol24

```

```console
$ algc conformance/0009-comment-swallows-a-cr-only-file.a24
```

> A file with CRLF endings and the same file with LF endings report identical
> line numbers. A lone `#13` between two statements separates them as any other
> whitespace would. Verified.

**[SRC-008]**  Whitespace is the space, `#9` and `#13`. It separates tokens and
is otherwise insignificant.

##### conformance/0003-line-termination.a24

```algol24
// #10 ends a line; space and #9 separate tokens and mean nothing else.
var	A	:=	1;
var   B   :=   2;
WriteLn (A + B);
```

```console
$ algc conformance/0003-line-termination.a24
3
```

**[SRC-009]**  The final line of a file need not be terminated.

##### conformance/0004-final-line-need-not-be-terminated.a24

```algol24
WriteLn ('first');
WriteLn ('last, with no terminator after it');
```

```console
$ algc conformance/0004-final-line-need-not-be-terminated.a24
first
last, with no terminator after it
```

### 3.4 Case

**[SRC-010]**  Keywords are matched case-insensitively. `begin`, `Begin` and
`BEGIN` are the same keyword.

    unit         Scan Keywords

##### conformance/0005-keywords-are-case-insensitive.a24

```algol24
BEGIN
    WriteLn ('upper');
END
Begin
    WriteLn ('mixed');
End
begin
    WriteLn ('lower');
end
```

```console
$ algc conformance/0005-keywords-are-case-insensitive.a24
upper
mixed
lower
```

**[SRC-011]**  Identifiers are matched **case-insensitively**, as keywords are.
`Xyz` and `xyz` are one name, and declaring both in one scope is a duplicate
[VAR-007].

Folding is **ASCII-only**. `Straße` and `STRASSE` are different names.

**This is a decision, not a gap.** Admitting Unicode *case folding* would be a
change to this rule in its own right, and it is not implied by [SRC-005]
admitting every character above U+007F as a letter — that rule needs no tables
precisely because it classifies nothing. Full folding maps `ß` to `ss`, which
would make those two one name — a different language from the one signed off
here.

Only the *lookup* is folded. A diagnostic quotes the lexeme **as written**, so
a program declaring `Xyz` and misspelling it `xyZ` is told about `xyZ`.

Folding happens where a name becomes a **key**, never to the lexeme itself,
through one named function so that every store folds the same way as every
lookup. `compiler/Token.a24`'s `FoldCase` scans for an uppercase letter before
building anything, because a name that is already folded must not allocate.

**Every diagnostic on the path had to be corrected.** Folding the key made
messages echo the key: a program writing `Shared` was told about `shared`, a
unit spelled `Deep` was reported as `deep`. A message names the occurrence the
program wrote.

##### conformance/0126-identifiers-are-case-insensitive.a24

```algol24
// A variable.
var Total := 0;
TOTAL := total + 5;
WriteLn (ToTaL);

// A field and a method, including the implicit 'this' path inside a method.
class Box;
var Value : Integer;
begin
    constructor Init (V : Integer); begin this.VALUE := V; end
    function Doubled (); begin Exit value * 2; end
end

var B := Box (21);
WriteLn (B.DOUBLED ());
WriteLn (b.value);

// A function.
function Greet (Who : String); begin Exit 'hi ' + Who; end
WriteLn (GREET ('you'));

// An enumeration and its members.  The member still PRINTS as it was
// declared -- only the lookup folds.
type Colour = (Red, Green);
WriteLn (COLOUR.red);
WriteLn (GREEN);

// A built-in member folds too, and this is the half that is easy to miss:
// were 'L.add' to answer 'Undefined property' in one processor and work in the
// other, a program written against either would fail against the other.
var L := [1];
L.add (2);
WriteLn (L.LENGTH);

var S := 'hi';
WriteLn (S.Length);
```

```console
$ algc conformance/0126-identifiers-are-case-insensitive.a24
5
42
21
hi you
Red
Green
2
2
```

##### refusals/0036-case-insensitive-duplicate.a24

```algol24
var Xyz := 1;
var xyz := 2;
```

```console
$ algc refusals/0036-case-insensitive-duplicate.a24
Uncaught: 'xyz' is already defined.
exit: 70
```

**Folding is uniform**, as Pascal's is: a name is a name whether it is a
keyword, a variable, a field, a method or a type [VAL-006]. A program may not
declare `Count` and `count` as two variables, and may not declare a variable
named `Begin` [LEX-009].

**A module name is the one exception**, and it is not the language's to
make: a module names a file, and the filesystem decides how that name is
matched. See [MOD-002].

---

## 4. Lexical elements

### 4.1 Comments

**[LEX-001]**  A comment begins with `//` and runs to the end of the line, or to
the end of the file if no `#10` follows. It is discarded and forms no token.

    unit         Scan Comment
    unit         Scan Comment Ends At Newline

##### conformance/0011-comments.a24

```algol24
// A comment runs to the end of the line.
WriteLn ('one');   // and may follow code on the same line
/// LEX-002: three slashes are not a distinct form.  The scanner sees '//'
/// followed by a comment whose first character is '/'.
WriteLn ('two');
//WriteLn ('never');
WriteLn ('three');
```

```console
$ algc conformance/0011-comments.a24
one
two
three
```

**[LEX-002]**  `///` is not a distinct form. The scanner sees `//` followed by a
comment whose first character is `/`, and treats it as any other comment.

    conformance  0011-comments.a24

> The project writes documentation comments as `///` by convention, and tools
> may treat them specially. The language does not.

**[LEX-003]**  There are no block comments and no nesting. `{ … }` and
`(* … *)` are not comments. The braces are refused as unexpected characters
[SRC-002]; the parenthesis form scans as a `(` followed by a `*`, which is not
a prefix operator, and fails with `Expect expression!`.

##### refusals/0002-block-comment-braces.a24

```algol24
{ this is not a comment }
WriteLn ('never reached');
```

```console
$ algc refusals/0002-block-comment-braces.a24
Uncaught: [line 1] Error: Unexpected character: }
exit: 70
```

### 4.2 Tokens

**[LEX-004]**  A token is an identifier, a keyword, a literal, or an operator
or item of punctuation. Whitespace and comments separate tokens and are
otherwise discarded.

    unit         Scan Tokens

##### conformance/0017-tokens-and-separation.a24

```algol24
// Whitespace and comments SEPARATE tokens and are otherwise discarded, so the
// same expression written densely and written spaciously is one token stream.
var Dense := 1+2*3;
var Loose :=   1    // a comment between two tokens
    +
    2  *  3 ;

WriteLn (Dense);
WriteLn (Loose);
WriteLn (Dense = Loose);
```

```console
$ algc conformance/0017-tokens-and-separation.a24
7
7
true
```

**[LEX-005]**  Where a shorter and a longer token both match, the longer is
taken. `<` followed by `>` is one `<>`; `<` followed by anything else is a `<`
on its own.

    unit         Scan Less Is Not Greedy

##### conformance/0012-operators.a24

```algol24
// LEX-012: the operators and punctuation.
WriteLn (5 + 3);
WriteLn (5 - 3);
WriteLn (5 * 3);
WriteLn (15 / 3);

// LEX-013: '=' compares, ':=' assigns, '<>' is inequality.  There is no '=='.
var A := 5;
WriteLn (A = 5);
WriteLn (A <> 5);

// LEX-005: the longer token wins.  '<=' is one token, and '<' followed by
// something that is not '>' or '=' is a '<' on its own.
WriteLn (3 <= 3);
WriteLn (3 <  4);
WriteLn (3 >= 3);
WriteLn (3 >  2);

// LEX-014: the word operators.
WriteLn (True and True);
WriteLn (True or False);
WriteLn (not False);
WriteLn (5 is Integer);
WriteLn ('a' in ['a', 'b']);
```

```console
$ algc conformance/0012-operators.a24
8
2
15
5
true
false
true
true
true
true
true
true
true
true
true
```

> `<<><=<` scans as `<`, `<>`, `<=`, `<` — four tokens.

**[LEX-006]**  There is no automatic semicolon insertion. A line ending is
whitespace and never stands in for a `;`.

##### refusals/0004-no-semicolon-insertion.a24

```algol24
WriteLn (1)
WriteLn (2)
```

```console
$ algc refusals/0004-no-semicolon-insertion.a24
Uncaught: Expect ';' after expression.
[ERROR] refusals/0004-no-semicolon-insertion.a24: Expect ';' after expression.
[ERROR] 1 | WriteLn (1)
[ERROR]   |           ^
exit: 70
```

### 4.3 Identifiers

**[LEX-007]**  An identifier is a **letter** followed by any number of letters,
digits and identifier marks. `letter`, `decimal_digit` and `identifier_mark`
are as defined in [SRC-005].

```
identifier = letter { letter | decimal_digit | identifier_mark } .
```

`Gate?`, `Send!`, `_under` and `a1b2` are identifiers. `Ready?Set` is one
identifier too: a mark does not end a word.

    unit         Scan Identifier
    unit         Scan Identifier With A Question Mark

##### conformance/0010-identifier-forms.a24

```algol24
// A letter, then letters, digits and identifier marks in any mixture.  Both
// marks are ordinary identifier characters, so these are four names.
var Gate?  := 1;
var Send!  := 2;
var _under := 4;
var a1b2   := 8;

// A mark does not end a word: Ready?Set is ONE identifier, not three tokens.
var Ready?Set := 16;

WriteLn (Gate? + Send! + _under + a1b2 + Ready?Set);
```

```console
$ algc conformance/0010-identifier-forms.a24
31
```

##### conformance/0120-identifier-marks.a24

```algol24
var Gate?     := 1;
var Send!     := 2;
var _under    := 4;
var a1b2      := 8;
var Ready?Set := 16;

WriteLn (Gate? + Send! + _under + a1b2 + Ready?Set);

// A mark does not end a word, and either may appear more than once.
var Both?!    := 32;
WriteLn (Both?!);
```

```console
$ algc conformance/0120-identifier-marks.a24
31
32
```

**[LEX-008]**  An identifier mark may not **begin** an identifier. `?` and `!`
alone are not identifiers, and neither are `?abc` and `!abc`: the mark is
refused as an unexpected character [SRC-002], because nothing else in the
language claims it.

##### refusals/0032-a-mark-may-not-begin-an-identifier.a24

```algol24
var ? := 7;
```

```console
$ algc refusals/0032-a-mark-may-not-begin-an-identifier.a24
Uncaught: [line 1] Error: Unexpected character: ?
exit: 70
```

> The rule exists so that `Gate?` can be one word without `?` also becoming a
> name. A trailing mark reads as punctuation on a word; a leading one reads as
> an operator the language does not have.

**[LEX-009]**  An identifier may not be spelled the same as a keyword in any
case, because the keyword is recognized first. `var begin := 7;` and
`var BEGIN := 7;` are both refused with `Expect variable name.`

    unit         Scan Keywords

##### refusals/0003-keyword-is-not-a-name.a24

```algol24
var begin := 7;
```

```console
$ algc refusals/0003-keyword-is-not-a-name.a24
Uncaught: Expect variable name.
[ERROR] refusals/0003-keyword-is-not-a-name.a24: Expect variable name.
[ERROR] 1 | var begin := 7;
[ERROR]   | ^^^
exit: 70
```

### 4.4 Keywords

**[LEX-010]**  The following 43 words are keywords and are matched
case-insensitively per [SRC-010]:

```
and     as       begin   break     case    class    const   constructor
continue         div     do        else    end      except  exit
external         false   for       function         goto    if
in      is       nil     not       object  of       operator
or      private  procedure         property         public  raise
super   then     this    true      try     type     uses
var     while
```

No other word is a keyword. Every word not in this list is an identifier and
may be declared as a name.

`print` used to be registered as a thirty-eighth, introducing a statement
[STM-022]. Neither was part of the language, and `var print := 7;` was refused
with `Expect variable name.`

    unit         Scan Keywords

##### conformance/0133-print-is-an-ordinary-name.a24

```algol24
var print := 7;
WriteLn (print);

print := print + 1;
WriteLn (print);

class Printer;
var print : Integer;
begin
end

var P := Printer ();
P.print := 3;
WriteLn (P.print);

function Emit (print : String);
begin
    Exit 'got ' + print;
end

WriteLn (Emit ('it'));
```

```console
$ algc conformance/0133-print-is-an-ordinary-name.a24
7
8
3
got it
```

**[LEX-011]**  `unit`, `test` and `on` are **not** keywords. They are ordinary
identifiers that the grammar recognizes by position — `unit` opening a file,
`test` before a block's quoted name, `on` introducing a handler — and each may
be used as a variable name.

    unit         Parse On Is Not A Keyword

##### conformance/0018-context-sensitive-words.a24

```algol24
// 'unit', 'test' and 'on' are not keywords.  The grammar recognizes them by
// position, and each may be used as an ordinary name.
var unit := 1;
var test := 2;
var on   := 4;

WriteLn (unit + test + on);
```

```console
$ algc conformance/0018-context-sensitive-words.a24
7
```

> `var test := 7;` is a valid declaration, and so are the `unit` and `on`
> forms. Verified in all three.

### 4.5 Operators and punctuation

**[LEX-012]**  The following are operators and punctuation:

```
(    )    [    ]    ,    .    ;    :
+    -    *    /    =    :=
<    <=   >    >=   <>
```

    unit         Scan Operators
    conformance  0012-operators.a24

**[LEX-013]**  `=` is equality and `:=` is assignment. Inequality is `<>`.
There is no `==`, no `!=` and no `!` operator: negation is `not`, and `!` is an
identifier mark [SRC-005] rather than punctuation.

    unit         Scan Operators
    conformance  0012-operators.a24

> Because `!` never begins a token [LEX-008], `A!=B` is unambiguous: it is the
> identifier `A!` compared with `B`. There is no `!=` for it to be mistaken for.

**[LEX-014]**  `and`, `or`, `not`, `in`, `is` and `as` are operators spelled as
keywords rather than punctuation, and are subject to [SRC-010].

    unit         Scan Keywords
    conformance  0012-operators.a24

`{` and `}` are not tokens of the language at all — not as comment
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

The base prefix and the hexadecimal digits are matched **without regard to
case**, as every other name in the language is [SRC-011]: `0XFF`, `0xff` and
`0xFF` are one literal.

    unit         Scan Number
    unit         Scan Integer Is Not A Double

##### conformance/0013-integer-literals.a24

```algol24
// LEX-015: a run of decimal digits.
WriteLn (42);

// LEX-017: leading zeros are permitted and carry no meaning -- 007 is seven,
// not an octal.
WriteLn (007);

// LEX-019: there is no negative literal.  A leading '-' is the unary operator,
// which is why '2-1' is a subtraction rather than two adjacent expressions.
WriteLn (-5);
WriteLn (2-1);

// A literal has no upper bound, because an Integer has none [LEX-018].  These
// are ordinary runs of digits, not values near a limit.
WriteLn (2147483647);
WriteLn (1234567890);

// A leading '-' is the operator here too, so this is unary minus over one
// positive literal and a subtraction of another.
WriteLn (-2147483647 - 1);
```

```console
$ algc conformance/0013-integer-literals.a24
42
7
-5
1
2147483647
1234567890
-2147483648
```

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
| `1_.5`, `1._5`, `1e_5` | refused: the neighbor is not a digit |
| `0x_FF` | refused: the prefix is not a digit either |

**There is no octal.** It is a PDP-11 artefact, and `0755` silently meaning
493 is a classic defect; C# omits it for the same reason. Three bases where two
are used is a name the reader must know for nothing.

**A comma separator is impossible rather than merely awkward.**
`F (1,000,000)` is already a call with three arguments and `[1,000,000]` a list
of three elements — both valid, with a different meaning. No lookahead resolves
it, because both readings are complete. `_` is the only separator available to a
language with comma-separated arguments and collection literals.

**`0x` and `0b` rather than Turbo Pascal's `$FF`.** `$` is unclaimed, and
`$FF` would sit consistently beside `#10`, which the language already has for a
code point. But Turbo Pascal has no binary form at all, so `$FF` beside `0b1010`
would mix two traditions in one sentence. The choice is for coherence with the
binary form, not for modernity.

**A separator does not survive into the value**, so `1_000` and `1000` are
the same literal and print alike.

##### conformance/0006-integer-bases-and-separators.a24

```algol24
WriteLn (0xFF);
WriteLn (0b1010);
WriteLn (1_000_000);

// The prefix and the hexadecimal digits fold [SRC-011], as every other name
// in the language does.
WriteLn (0xff = 0XFF);
WriteLn (0B1010 = 0b1010);

// A separator may stand between any two digits, in any base.
WriteLn (0xFF_FF);
WriteLn (0b1010_1010);
WriteLn (1_0_0);

WriteLn (1_000 = 1000);
WriteLn (0x10 = 16);
WriteLn (0b1010 is Integer);

// '0x' is a prefix only when a digit of that base follows it.  A variable
// named 'x' after a zero is still two things.
var x := 5;
WriteLn (0 + x);
```

```console
$ algc conformance/0006-integer-bases-and-separators.a24
255
10
1000000
true
true
65535
170
100
true
true
true
5
```

##### refusals/0151-a-separator-must-separate-digits.a24

```algol24
WriteLn (100_);
```

```console
$ algc refusals/0151-a-separator-must-separate-digits.a24
Uncaught: Expect ')' after arguments.
[ERROR] refusals/0151-a-separator-must-separate-digits.a24: Expect ')' after arguments.
[ERROR] 1 | WriteLn (100_);
[ERROR]   |          ^^^
exit: 70
```

**[LEX-017]**  Leading zeros are permitted and carry no meaning. `007` is the
integer 7, not an octal.

    conformance  0013-integer-literals.a24

**[LEX-018]**  An Integer is **unbounded**. Arithmetic never overflows: a result
too large for the machine's width grows to hold it.

**This is the whole of the type.** "An `Integer` is an integer" is a sentence
a reader needs nothing else to understand, where "an `Integer` is a signed
32-bit value, and an operation whose result falls outside that range raises"
asks them to carry a boundary. Removing the boundary removes a category of
error rather than diagnosing it.

**Cheaper than it sounds, and the reason is worth stating.** The wide path
begins past 2⁶³ and almost nothing reaches it — `algc` cannot, since its own
scanner accumulates digits through this very arithmetic. What an ordinary
program pays is one predicted branch per operation, which is exactly what the
range check it replaced already cost.

**It used to wrap silently**, so `2147483647 + 1` was `-2147483648`; then it
raised [was LEX-018 as first written]; now it grows. Each step removed a way for
a program to be surprised, and the last one removes the surprise itself.

**One implementation, not two.** The interpreter's `+` *is* the runtime's —
`Exit Left + Right` in `VisitBinary` compiles to `alg_add` — so the two cannot
disagree, and this landed in `bootstrap/algol.c` alone.

**Signed overflow in C is undefined behavior, not a wrap**, which is a
different problem and was already avoided: the arithmetic goes through
`__builtin_*_overflow`. What changed is only what happens on the overflow they
report — the same branch that raised now promotes.

**The switch that turned the check off is gone.**
`-DALG_NO_OVERFLOW_CHECK` skipped a range check and left the defined wrap that
preceded it: a build that did not conform but did compute something. The same
branch now decides whether to promote, so skipping it would not be a faster
conforming build — it would be wrong answers. A check that may be turned off and
a promotion that may not are one line of C and a different bargain.

**Crossing into a machine width is a separate question**, and one place
answers it. A subscript, a `Buffer` offset, a code point and an exit status all
need a number C can hold, so each asks for one and gets a diagnostic naming the
value rather than a truncation.

##### conformance/0041-integers-grow.a24

```algol24
WriteLn (2147483647 + 1);
WriteLn (9223372036854775807 + 1);
WriteLn (9223372036854775807 * 9223372036854775807);

// It DEMOTES.  A result that fits is an ordinary Integer again, so one value
// never has two representations and '=' , hashing and Map keys agree.
var Huge := 9223372036854775807 * 9223372036854775807;

WriteLn (Huge / 9223372036854775807 = 9223372036854775807);
WriteLn ((9223372036854775807 + 1) - 1 = 9223372036854775807);
WriteLn (Huge / Huge);
WriteLn (Huge / Huge is Integer);

// Factorials are the ordinary reason to want this.
function Fact (N);
begin
    var R := 1;
    for var I := 1; I <= N; I := I + 1 do R := R * I;
    Exit R;
end

WriteLn (Fact (25));
WriteLn (Fact (30) / Fact (29));

// There is still no negative literal [LEX-019], so a large negative value is
// the unary operator applied to a large positive one -- which now works.
WriteLn (-9223372036854775808);
WriteLn (0 - Huge < 0);

// Truncation toward zero, both signs [EXP-004], and a remainder that takes the
// sign of the dividend.
WriteLn (Huge / 1000000000000000000000);
WriteLn ((0 - Huge) / 1000000000000000000000);
WriteLn (Mod (Huge, 1000000000000000000000));
WriteLn (Mod (0 - Huge, 1000000000000000000000));

// It is an Integer, by every question the language can ask.
WriteLn (Huge is Integer);
WriteLn (Val (Str (Huge)) = Huge);
```

```console
$ algc conformance/0041-integers-grow.a24
2147483648
9223372036854775808
85070591730234615847396907784232501249
true
true
1
true
15511210043330985984000000
30
-9223372036854775808
true
85070591730234615
-85070591730234615
847396907784232501249
-847396907784232501249
true
true
```

##### conformance/0136-integer-range.a24

```algol24
WriteLn (2147483646 + 1);
WriteLn (-2147483647 - 1);
WriteLn (46340 * 46340);
WriteLn (2147483647 / 1);
WriteLn (-(-2147483647));

// This was once the ONLY way to write the most negative 32-bit Integer,
// because a literal could not exceed 2147483647 and there is no negative
// literal [LEX-019].  It is now an ordinary subtraction of two ordinary
// numbers, and '-2147483648' is writable directly.
WriteLn (-2147483647 - 1);
WriteLn (-2147483648);

// A Double is NOT unbounded, and that asymmetry is deliberate: it follows
// IEEE 754, so 1.0 / 0 is Infinity [EXP-006] rather than an error, and a mixed
// expression is Double arithmetic.  Integer division by zero is [EXP-006].
WriteLn (1.0 / 0 > 0);
WriteLn (2147483647 + 1.0);
```

```console
$ algc conformance/0136-integer-range.a24
2147483647
-2147483648
2147395600
2147483647
2147483647
-2147483648
-2147483648
true
2.147483648E9
```

**[LEX-019]**  There is no negative literal. A leading `-` is the unary
operator applied to a non-negative literal, which is why `2-1` is a
subtraction rather than two adjacent expressions.

    conformance  0013-integer-literals.a24

### 4.7 Double literals

**[LEX-020]**  A double literal requires at least one digit on **both** sides
of the point, or an exponent [LEX-022] in place of the point.

```
double_lit = decimal_lit "." decimal_lit [ exponent ] | decimal_lit exponent .
```

    unit         Scan Number Decimal

##### conformance/0014-double-literals.a24

```algol24
// A double literal needs at least one digit on BOTH sides of the point.
WriteLn (1.5);
WriteLn (1.0);
WriteLn (0.25);
```

```console
$ algc conformance/0014-double-literals.a24
1.5
1.0
0.25
```

**[LEX-021]**  `1.` is therefore not a double. It is the integer `1` followed
by the `.` operator, and a program containing it fails with `Expect property
name after '.'.` Likewise `.5` is not a literal at all.

    unit         Scan Integer Then Dot

##### refusals/0005-trailing-dot-is-not-a-double.a24

```algol24
WriteLn (1.);
```

```console
$ algc refusals/0005-trailing-dot-is-not-a-double.a24
Uncaught: Expect property name after '.'.
[ERROR] refusals/0005-trailing-dot-is-not-a-double.a24: Expect property name after '.'.
[ERROR] 1 | WriteLn (1.);
[ERROR]   |           ^
exit: 70
```

**[LEX-022]**  A literal may carry an exponent, and one that does is a Double
whether or not it has a point.

```
exponent = ( "e" | "E" ) [ "+" | "-" ] decimal_digit { [ "_" ] decimal_digit } .
```

`1e5` is `100000.0`, `1.5e-3` is `0.0015`, and `1E300` is a Double.

**The exponent decides the type**, which is why `1e5` is a Double rather than
an Integer of the same value. A form written to say "this is a magnitude" should
not answer with the type that cannot express most magnitudes.

**This closed a place where the language printed a form it could not read.**
`Str` renders a large Double in exponent notation — `1.0E300` — and that text
was not a literal. Nothing was unreachable, because `Val` parsed the exponent
form and `Val(Str(X))` round-tripped; but a value could not be written into a
program the way the program wrote it out.

**The sign belongs to the exponent, not to the literal.** [LEX-019] still
holds: there is no negative literal, and `-1e5` is the unary operator applied to
one. The `-` inside `1e-5` is part of the exponent and is not that operator.

##### conformance/0007-exponent-notation.a24

```algol24
WriteLn (1e5);
WriteLn (1e5 is Double);
WriteLn (1.5e-3);
WriteLn (2e+3);

// Either case, as every other name in the language folds [SRC-011].
WriteLn (1E5 = 1e5);

// The round trip through the source, which is the point of the rule.
var Big := 1.0E300;
WriteLn (Str (Big));
WriteLn (Val (Str (Big)) = Big);

// The sign belongs to the EXPONENT.  [LEX-019] still holds -- there is no
// negative literal -- so the '-' in front is the unary operator and the one
// inside is not.
WriteLn (-1e2);
WriteLn (1e-2);

// 'e' followed by anything but an exponent is still an identifier, so this
// is a number and a name, not a malformed literal.
var eight := 8;
WriteLn (1 + eight);
```

```console
$ algc conformance/0007-exponent-notation.a24
100000.0
true
0.0015
2000.0
true
1.0E300
true
-100.0
0.01
9
```

### 4.8 Character literals

**[LEX-023]**  A quoted literal denoting exactly one character is a Char rather
than a String. `'a'`, `'é'` and `''''` are all Chars; `''` is the empty String
and `'ab'` a String of two.

**The measurement is on the VALUE, not on the source span.** A doubled quote
`''''` is two characters of source and one character of value, and it is the
value that decides — because the doubling is *notation for a character*, and
notation must not change a type.

**This was the other way round, and was wrong.** Measuring the span made the
same character carry two types depending on how it was spelled:

```
''''  is Char  →  false            #39  is Char  →  true
''''  =  #39   →  false            a character not equal to itself
Ord ('''')     →  Ord failed: ''' has no ordinal.
```

**This was wrong twice over.** The implementation measured the span, and
measured it in *bytes* — so `''''` was a String and `'é'` a String of length 2.
One line decided both, which is why they were corrected together.

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

`char_lit` and `string_lit` are not distinguished by the grammar — both open
with a quote — and are not meant to be. [LEX-023] decides between them by
counting the characters the literal denotes.

    unit         Scan Char By Code Point
    unit         Scan Char Without Digits

##### conformance/0015-char-literals.a24

```algol24
// LEX-024: '#' followed by decimal digits is the character with that code
// point.
WriteLn (#65);
WriteLn (#65 is Char);
Write   ('a');
Write   (#10);

// LEX-026: a Char and a String are never equal, however alike they look.
// Both sides of the first comparison are Chars.  Copy yields a String of
// length one, which the Char 'a' is not.
WriteLn ('a' = 'a');
WriteLn (Copy ('abc', 0, 1) = 'a');
```

```console
$ algc conformance/0015-char-literals.a24
A
true
a
true
false
```

**[LEX-025]**  A Char is a Unicode code point: 0 … 10FFFF, excluding the
surrogate range D800 … DFFF, which encodes no character. A `#` literal outside
that range is refused when the program is read, with the shape every other
scan error has — `[line N] Error: …` — because that is where it is detected.

A Char is held as its **UTF-8 encoding** — a String of one character and
possibly several bytes — and `alg_char_value` is the single place that encodes
it, so the two processors agree by construction rather than by both being
restricted to what a byte can hold.

##### refusals/0038-char-out-of-range.a24

```algol24
WriteLn (#1114112);
```

```console
$ algc refusals/0038-char-out-of-range.a24
Uncaught: [line 1] Error: Char is limited to 0..10FFFF, excluding D800..DFFF: #1114112
exit: 70
```

**[LEX-026]**  A Char and a String are never equal, however alike they look.
`'a' = 'a'` is true because both sides are Chars; `Copy('abc', 0, 1) = 'a'` is
**false**, because `Copy` yields a String of length one and the Char `'a'` is
not it.

    conformance  0015-char-literals.a24

### 4.9 String literals

**[LEX-027]**  A string literal is enclosed in single quotes. A quote within it
is written twice.

```
string_lit = "'" { source_character_other_than_quote | "''" } "'" .
```

    unit         Scan String
    unit         Scan Doubled Quote

##### conformance/0016-string-literals.a24

```algol24
// LEX-027: single quotes, and a quote within is written twice.
WriteLn ('it''s');

// LEX-029: '' is the empty String -- zero characters, and there is no empty
// Char.
WriteLn (Length (''));
WriteLn ('' is String);

// LEX-028: no backslash escapes.  This is four characters and the one at
// index 1 is the backslash itself.
WriteLn (Length ('a\nb'));
WriteLn ('a\nb'[1]);

// LEX-030: a literal may span lines, and the line feed is part of the value.
WriteLn (Length ('one
two'));
```

```console
$ algc conformance/0016-string-literals.a24
it's
0
true
4
\
7
```

**[LEX-028]**  There are no backslash escapes. `'a\nb'` is four characters, and
its element at index 1 is the backslash itself. A line feed is written `#10` and
concatenated.

    conformance  0016-string-literals.a24

**[LEX-029]**  `''` is the empty String — zero characters, and there is no
empty Char. `''''` is the **Char** holding a quote: one character of value,
however many of source [LEX-023].

`''''` and `#39` are therefore the same value, and equal. They are two
spellings of one character.

The scanner measures the literal's **value**, not its source span, and that
one line decides two things: `'é'` is a Char rather than a String of two bytes,
and a doubled quote counts once.

**There is then no literal for a one-character String**, and that is not a
loss. `var S : String := 'c';` is already a type mismatch for every character
but the quote [LEX-023], so `''''` being writable was an accident of the
measurement rather than a way of writing anything. Once a Char widens to a
String at an assignment context [VAR-004], `var S : String := 'a';` is how one
is written, and it works for every character alike.

    unit         Scan Empty String
    unit         Scan An Escaped Quote Is A Char
    conformance  0016-string-literals.a24

##### conformance/0130-a-doubled-quote-is-a-char.a24

```algol24
WriteLn ('''' is Char);
WriteLn (#39 is Char);
WriteLn ('''' = #39);
WriteLn (Ord (''''));

// '' is the empty String, and there is no empty Char [LEX-029].
WriteLn ('' is String);
WriteLn (Length (''));
```

```console
$ algc conformance/0130-a-doubled-quote-is-a-char.a24
true
true
true
39
true
0
```

**[LEX-030]**  A string literal may span lines. The line feed is part of its
value and advances the line count, so `'one` ⏎ `two'` is seven characters.

    conformance  0016-string-literals.a24

**[LEX-031]**  A string that reaches the end of the file unclosed is an error
reading `[line N] Error: Unterminated string.`, where N is the line the string
**opened** on.

A quote closes the string before it. A file with several stray quotes
therefore reports the last *unpaired* one, which is the string that actually
runs to the end.

    unit         Scan Unterminated String

##### conformance/0110-unterminated-string-line.a24

```algol24
var A := 1;
var B := 2;

WriteLn ('oops);

var C := 3;
var D := 4;
var E := 5;
var F := 6;
```

```console
$ algc conformance/0110-unterminated-string-line.a24
Uncaught: [line 4] Error: Unterminated string.
exit: 70
```

**[LEX-032]**  `#0` is not a Char. A code point of 0 is refused exactly as an
out-of-range one is [LEX-025], when the program is read.

**Only the LITERAL is refused.** [LEX-025] puts a Char at 0 … 10FFFF and the
built-in `Char(0)` stays legal — which it must, because the scanner's own
end-of-input sentinel is `Char(0)`, and a scanner that cannot name its sentinel
cannot scan.

`Str(Char(0))` no longer truncates: a String carries its own length
[SRC-001], so `Length('a' + Str(Char(0)) + 'b')` is 3.

##### refusals/0037-nul-char-literal.a24

```algol24
WriteLn (#0 is Char);
```

```console
$ algc refusals/0037-nul-char-literal.a24
Uncaught: [line 1] Error: '#0' is not a Char.
exit: 70
```
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

    unit         Parse Var Statement
    unit         Parse Var Expect Semicolon

##### conformance/0019-declaration-forms.a24

```algol24
// VAR-001: a type and an initializer are each optional.
var A;
var B := 1;
var C : Integer;
var D : Integer := 2;

WriteLn (A);
WriteLn (B);
WriteLn (C);
WriteLn (D);

// VAR-008: a collection may carry an element type.
var L : List of Integer := [1, 2, 3];
WriteLn (L.Length);

// Only the List form is exercised here.  VAR-008 admits 'Map of', 'Set of'
// and 'Array of' on the same terms.
```

```console
$ algc conformance/0019-declaration-forms.a24
nil
1
nil
2
3
```

**[VAR-002]**  A variable declared without an initializer holds `nil`, whatever
its declared type. **There is no zero value**: an uninitialized `Integer` is
`nil`, not `0`.

##### conformance/0022-no-zero-value.a24

```algol24
// VAR-002: a variable declared without an initializer holds nil, whatever its
// declared type.  There is no zero value -- an uninitialized Integer is nil,
// not 0.
var N : Integer;
var S : String;
var B : Boolean;

WriteLn (N);
WriteLn (S);
WriteLn (B);
WriteLn (N = nil);

// VAR-005: nil satisfies every declared type, which is what makes the above
// consistent rather than a special case.
var Explicit : Integer := nil;
WriteLn (Explicit = nil);
```

```console
$ algc conformance/0022-no-zero-value.a24
nil
nil
nil
true
true
```

**[VAR-003]**  A declared type constrains the initializer and every later
assignment. A violation is the error `Type mismatch!`

##### refusals/0008-declared-type-constrains.a24

```algol24
WriteLn ('this line never runs');

var X : Integer := 1;
X := 'text';
```

```console
$ algc refusals/0008-declared-type-constrains.a24
Uncaught: Expected Integer, found String.
[ERROR] refusals/0008-declared-type-constrains.a24: Expected Integer, found String.
[ERROR] 4 | X := 'text';
[ERROR]   | ^
exit: 70
```

**[VAR-004]**  A value **widens** to reach a written type, and is converted at
the point it arrives. There are two widening pairs:

| From | To | Example |
| --- | --- | --- |
| Integer | Double | `var X : Double := 1;` gives `X` the Double `1.0` |
| Char | String | `var S : String := 'a';` gives `S` a String of length 1 |

The variable holds the wider type afterwards. A declaration never misdescribes
what it holds.

A plain assignment and a field reached this **last**, and `D := 1` used to
leave `D` holding an Integer — a declaration describing something the variable
did not hold.

##### conformance/0025-operators-widen.a24

```algol24
// Integer widens to Double.
WriteLn (1 + 1.5);

// Char widens to String, in either position.
WriteLn ('a' + 'bc');
WriteLn ('ab' + 'c');

// And two Chars concatenate to a String of two characters rather than staying
// Chars or summing their code points.
WriteLn ('a' + 'b');
WriteLn (Length ('a' + 'b'));
WriteLn (('a' + 'b') is String);
```

```console
$ algc conformance/0025-operators-widen.a24
2.5
abc
abc
ab
2
true
```

##### conformance/0140-widening-at-every-context.a24

```algol24
// A declaration and a const.
var A : Double := 1;
const C : Double := 2;
WriteLn (A);
WriteLn (C);

// A plain assignment, which is the context widening reached last.
var B : Double := 0.0;
B := 1;
WriteLn (B);

// A parameter and a declared return type.
function F (X : Double) : Double; begin Exit X; end
WriteLn (F (1));

// A field, through a constructor and through an initializer.
class K;
var Field : Double;
var Seeded : Double := 3;
begin
    constructor Init (); begin this.Field := 1; end
end

var Instance := K ();
WriteLn (Instance.Field);
WriteLn (Instance.Seeded);

// And from outside the class.
Instance.Field := 4;
WriteLn (Instance.Field);

// Char widens to String at the same six contexts.
var S : String := 'a';
S := 'b';
WriteLn (S + '!');
```

```console
$ algc conformance/0140-widening-at-every-context.a24
1.0
2.0
1.0
1.0
1.0
3.0
4.0
b!
```

**[VAR-017]**  Widening applies wherever a value meets a written type — the six
**assignment contexts**, and nowhere else:

```
var X : T := E ;          const X : T := E ;
X := E ;                  Obj.Field := E ;
Exit E ;   (against a declared return type)
F (E) ;    (against a declared parameter type)
```

**The interpreter does not know a variable's declared type at run time**, and
this is how the last two contexts are reached anyway. `Env` stores values, not
types, so a plain `X := 1` has nothing to consult — a declaration knows its own
type, and a parameter and a return type are on the function. The **TypeChecker
writes the declared type onto the assignment node**, having already computed it
to check the assignment, and the interpreter widens with it. A field is the same
arrangement on `SetExpr`.

A field written through `this` needs the receiver's type, and `this` is
**deliberately untyped** so that a class's own code escapes the private-member
check. The class name is taken for the widening lookup alone, after visibility
has had its untyped receiver — typing `this` outright breaks that rule, which
the checker's own tests catch.

**Comparison is not among them and does not widen.** `'a'` and
`Copy('abc', 0, 1)` remain unequal [LEX-026]. A widening converts *toward a
target type*, and an `=` supplies none — it would have to invent one, and
"convert when the sides differ" is the rule that makes `=` unpredictable.

    conformance  0140-widening-at-every-context.a24

**[VAR-018]**  Narrowing is refused in every one of those contexts.
`var X : Integer := 1.5;` is a mismatch: the value does not fit, and choosing
how to lose the fraction is not a decision a declaration should make silently.
`var C : Char := 'ab';` is refused for the same reason.

##### refusals/0014-no-implicit-narrowing.a24

```algol24
var X : Integer := 1.5;
```

```console
$ algc refusals/0014-no-implicit-narrowing.a24
Uncaught: Expected Integer, found Double.
[ERROR] refusals/0014-no-implicit-narrowing.a24: Expected Integer, found Double.
[ERROR] 1 | var X : Integer := 1.5;
[ERROR]   |     ^
exit: 70
```

**[VAR-005]**  `nil` satisfies every declared type, so `var X : Integer := nil;`
is accepted.

    conformance  0022-no-zero-value.a24

**[VAR-006]**  `Any` is the declared type meaning *not known*. A variable
declared `Any` accepts every value.

It does **not** flow the other way. A value whose type is `Any`, or whose type
could not be determined at all, does not satisfy a written type: neither
`var I : Integer := A;` nor a later `I := A;` is accepted where `A` is `Any`.
The conversion must be written, and `as` [VAL-007] is how to write it.

**A type is not a suggestion once it is written.** Where a program declares a
type, every value reaching that variable either has the type already or is
converted by an expression that says so and checks it. This is what lets a
declared type be relied upon — by a reader, and by the C back end, which can
only generate a machine representation for a variable whose type it may trust.

Writing no type remains entirely permissive. `var A := M.Get (1);` is
ordinary and unremarkable; the rule bites only where a type was written down.

**An assignment is now as strict as a declaration**, and getting there was an
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

**Five sites in the compiler genuinely could not be typed**, and each was
given the `as` this rule prescribes — a member of an untyped parameter, a
subscript of one. That is the rule working as intended rather than a concession
to it: the conversion is written where the checker cannot see the type.

**Scoping `Inferred` was not optional.** While one helper read it a stale
entry could only lose checking; once an ordinary variable's type comes from it, a
leftover `String` from another function's `C` makes a correct program fail to
check — the one kind of wrong answer that is not harmless. `Generics` was made
scoped for exactly this reason and the pattern was copied.

##### conformance/0020-any-accepts-every-value.a24

```algol24
// A variable declared Any accepts every value, and accepts a different kind of
// value later.
var X : Any := 1;
WriteLn (X);

X := 'text';
WriteLn (X);

X := [1, 2];
WriteLn (X.Length);

// Writing no type at all is permissive in the same way.  The rule in VAR-006
// bites only where a type WAS written down.
var Y := 1;
Y := 'text';
WriteLn (Y);

// The other direction -- Any into a written type -- is refused by [VAR-006],
// at a declaration and at an assignment alike.
```

```console
$ algc conformance/0020-any-accepts-every-value.a24
1
text
2
text
```

##### conformance/0141-inference-carries-a-type.a24

```algol24
// A variable declared WITHOUT a type carries its deduced type into later
// expressions, rather than reducing to no type at all.
var Text := 'abcdef';
var C := Copy (Text, 1, 1);
var Result : String := '';
Result := Result + C;
WriteLn (Result);

// A bare name inside a method may be a FIELD -- an implicit 'this.Field' --
// and a field's type is registered under 'Class::Field'.  Looking for it bare
// found nothing, which was the checker's largest blind spot.
class Reader;
var Source : String;
var At : Integer;
begin
    constructor Init (S : String); begin this.Source := S; this.At := 0; end

    function Next () : Char;
    var
        Ch : Char;
    begin
        Ch := Source[At];
        At := At + 1;
        Exit Ch;
    end
end

var R := Reader ('hi');
WriteLn (R.Next ());
WriteLn (R.Next ());

// A field declared on a PARENT is reached bare from a subclass's methods.
class Base;
var Tag : String := 'from the parent';
begin
    constructor Init (); begin end
end

class Derived (Base);
begin
    constructor Init (); begin end
    function Read () : String;
    var
        T : String;
    begin
        T := Tag;
        Exit T;
    end
end

WriteLn (Derived ().Read ());

// Writing no type stays permissive: an untyped variable accepts anything.
var Anything := Untyped ();
Anything := 5;
WriteLn (Anything);

function Untyped (); begin Exit 'x'; end
```

```console
$ algc conformance/0141-inference-carries-a-type.a24
b
h
i
from the parent
5
```

##### refusals/0048-assignment-escapes-the-type.a24

```algol24
function Untyped (); begin Exit 'xy'; end

var S : String;
S := Untyped ();
```

```console
$ algc refusals/0048-assignment-escapes-the-type.a24
Uncaught: Expected String, found an untyped expression.
[ERROR] refusals/0048-assignment-escapes-the-type.a24: Expected String, found an untyped expression.
[ERROR] 4 | S := Untyped ();
[ERROR]   | ^
exit: 70
```
    defect       DEF-35-inference-stops-at-a-later-declaration.a24

**[VAR-007]**  A name may not be declared twice in one scope. The second is
refused with `'X' is already defined.`

**Two subprograms of one name are not a duplicate** where their signatures
differ: they are overloads [FUN-013], selected between at the call. Two with the
*same* signature are a duplicate like any other name.

    unit         Resolve Duplicate Variable

##### refusals/0009-no-redeclaration.a24

```algol24
var X := 1;
var X := 2;
```

```console
$ algc refusals/0009-no-redeclaration.a24
Uncaught: 'X' is already defined.
exit: 70
```

**[VAR-008]**  A collection may carry an element type, written `of`:
`var L : List of Integer := [];`. Every collection type accepts one — `List`,
`Map`, `Set` and `Array`.

For a `Map` the element type is the **value** type, since that is what a
subscript and a `Get` yield [VAR-016]. A Map's keys are not constrained.

**Wherever a type may be written**, which is every context [TYP-002] names —
a variable, a constant, a field, a **parameter** and a **return type**. The last
two did not parse: `Items : List of Integer` was `Expect ')' after parameters.`
and a return type stopped at the collection's name. Annex A's grammar has
described both since it was written, and only the parser disagreed.

    conformance  0019-declaration-forms.a24

##### conformance/0121-element-type-on-every-collection.a24

```algol24
var L : List of Integer  := [1, 2];
var M : Map of String    := [1 : 'one'];
var S : Set of Integer   := Set ();
var A : Array of Integer := Array (2);

WriteLn (L.Length);
WriteLn (M.Length);
WriteLn (S.Length);
WriteLn (A.Length);

// For a Map the element type is the VALUE type, because that is what a
// subscript and a Get yield.  A Map's keys are not constrained.
var V : String := M[1];
WriteLn (V);

// And it still flows to a read on a List.
var First : Integer := L[0];
WriteLn (First);
```

```console
$ algc conformance/0121-element-type-on-every-collection.a24
2
1
0
2
one
1
```

##### conformance/0157-element-types-on-parameters.a24

```algol24
function Total (Items : List of Integer) : Integer;
begin
    var Sum := 0;

    for var I in Items do Sum := Sum + I;

    Exit Sum;
end

WriteLn (Total ([1, 2, 3]));

// A return type carries one too, and it flows to reads from the call.
function Names () : List of String;
begin
    Exit ['alpha', 'beta'];
end

WriteLn (Names ().Get (1));
WriteLn (Names ().Get (1).Length);

// Every collection type accepts one [VAR-008].  For a Map it is the VALUE
// type, since that is what Get yields.
function Look (M : Map of Integer) : Integer;
begin
    Exit M.Get ('k');
end

WriteLn (Look (['k' : 5]));

function Count (S : Set of String) : Integer;
begin
    Exit S.Length;
end

WriteLn (Count (Set (['a', 'b'])));

// It is a source of types for READS and no constraint on writes [VAR-016],
// exactly as it is on a var -- so a parameter's element type is what makes the
// loop variable below an Integer rather than nothing.
function Widths (Items : List of String) : Integer;
begin
    var Total := 0;

    for var S in Items do Total := Total + S.Length;

    Exit Total;
end

WriteLn (Widths (['ab', 'cde']));
```

```console
$ algc conformance/0157-element-types-on-parameters.a24
6
beta
4
5
2
5
```

**[VAR-016]**  An element type is a **source of types for reads and a
constraint on writes.** Given `var L : List of Integer`:

| Expression | |
| --- | --- |
| `L[0]` | Integer |
| `X` in `for var X in L` | Integer |
| `L.Add ('text')` | refused: `Expected Integer, found String.` |

**Every route in is covered**, and there are five: `Add`, `Push`, `Put`,
subscript assignment, and the collection **literal** at a declaration.

**A check covering some of them would be worse than none**, which is why the
list is exhaustive rather than convenient. A fence with a gate in it invites the
declared type to be trusted, and a type that is trusted in four places and not
the fifth is more dangerous than one trusted nowhere.

**`Put` constrains its SECOND argument.** A `Map of T` declares the type of
what is stored, which is what `M[K]` reads back; the key is not constrained.

**Checked where the receiver's type is known, and nowhere else** — the same
bargain [CLS-017] makes for a property and [DCL-015] for `private:`. The element
type is available only for a plain **name**: there is nowhere to have written
the element type of an arbitrary expression, so an insertion through one is
unchecked. It costs nothing at run time.

**A bare `List` is unconstrained**, as it always was. The element type does
the constraining, so declaring none declares no constraint — which is why this
rule is about the *annotation* rather than about collections.

**It checks and does not convert.** `D.Add (2)` into a `List of Double` is
accepted because an Integer widens to a Double [VAR-004], and the element
stored is the Integer `2`. Widening happens where a value reaches a *written
type*, and an element is not one.

##### conformance/0021-element-types-flow-to-reads.a24

```algol24
var L : List of Integer := [10, 20];

// A subscript has the element type, and a loop variable takes it too.  Both
// are visible here only as the absence of a complaint: were the element type
// not flowing, neither line would type-check against Integer.
var First : Integer := L[0];
WriteLn (First);

for var X in L do
begin
    var Doubled : Integer := X * 2;
    WriteLn (Doubled);
end

// Insertion IS checked: an element that does not fit the declared type is
// refused at every route in, and a read carries the element type back out.
// [VAR-016] states the whole rule.
L.Add (30);
WriteLn (L.Length);
WriteLn (L[2]);

// A BARE 'List' is still unconstrained.  The element type is what does the
// constraining, so declaring none declares no constraint -- which is why this
// rule reads as being about the annotation rather than about collections.
var Loose : List := [1];
Loose.Add ('anything');
WriteLn (Loose);
```

```console
$ algc conformance/0021-element-types-flow-to-reads.a24
10
20
40
3
30
[1, anything]
```

##### conformance/0173-element-types-on-insertion.a24

```algol24
var L : List  of Integer := [1, 2];
var M : Map   of Integer := [:];
var S : Stack of Integer := Stack ();

// Correct insertions, by every route.
L.Add (3);
L[0] := 9;
M.Put ('key', 7);
S.Push (4);

WriteLn (L);
WriteLn (M);
WriteLn (S.Length);

// It CHECKS and does not CONVERT.  An Integer widens to a Double [VAR-004]
// so the insertion is accepted, and what is stored is the Integer -- widening
// happens where a value reaches a written type, and an element is not one.
var D : List of Double := [1.0];
D.Add (2);
WriteLn (D);

// 'Put' constrains its SECOND argument.  A 'Map of T' declares the type of
// what is stored, which is what 'M[K]' reads back; the key is not constrained.
M.Put ('any key at all', 1);
WriteLn (M.Length);

// nil inhabits every type [VAR-005].
L.Add (Nil);
WriteLn (L);

// A bare 'List' is unconstrained: the element type does the constraining, so
// declaring none declares no constraint.
var Loose : List := [1];
Loose.Add ('anything');
WriteLn (Loose);

// So is a receiver with no declared type -- there is nowhere to have written an
// element type, which is the same limit reading one has.
var Inferred := [1];
Inferred.Add ('anything');
WriteLn (Inferred);
```

```console
$ algc conformance/0173-element-types-on-insertion.a24
[9, 2, 3]
[key:7]
1
[1.0, 2]
2
[9, 2, 3, nil]
[1, anything]
[1, anything]
```

##### refusals/0173-element-type-on-add.a24

```algol24
var L : List  of Integer := [1, 2];
var M : Map   of Integer := [:];
var S : Stack of Integer := Stack ();

WriteLn ('never reached');

L.Add ('text');
```

```console
$ algc refusals/0173-element-type-on-add.a24
Uncaught: Expected Integer, found String.
[ERROR] refusals/0173-element-type-on-add.a24: Expected Integer, found String.
[ERROR] 7 | L.Add ('text');
[ERROR]   |   ^^^
exit: 70
```

##### refusals/0174-element-type-on-subscript.a24

```algol24
var L : List  of Integer := [1, 2];
var M : Map   of Integer := [:];
var S : Stack of Integer := Stack ();

WriteLn ('never reached');

L[0] := 'text';
```

```console
$ algc refusals/0174-element-type-on-subscript.a24
Uncaught: Expected Integer, found String.
[ERROR] refusals/0174-element-type-on-subscript.a24: Expected Integer, found String.
[ERROR] 7 | L[0] := 'text';
[ERROR]   |  ^
exit: 70
```

##### refusals/0175-element-type-on-put.a24

```algol24
var L : List  of Integer := [1, 2];
var M : Map   of Integer := [:];
var S : Stack of Integer := Stack ();

WriteLn ('never reached');

M.Put ('k', 'text');
```

```console
$ algc refusals/0175-element-type-on-put.a24
Uncaught: Expected Integer, found String.
[ERROR] refusals/0175-element-type-on-put.a24: Expected Integer, found String.
[ERROR] 7 | M.Put ('k', 'text');
[ERROR]   |   ^^^
exit: 70
```

##### refusals/0176-element-type-on-push.a24

```algol24
var L : List  of Integer := [1, 2];
var M : Map   of Integer := [:];
var S : Stack of Integer := Stack ();

WriteLn ('never reached');

S.Push ('text');
```

```console
$ algc refusals/0176-element-type-on-push.a24
Uncaught: Expected Integer, found String.
[ERROR] refusals/0176-element-type-on-push.a24: Expected Integer, found String.
[ERROR] 7 | S.Push ('text');
[ERROR]   |   ^^^^
exit: 70
```

##### refusals/0177-element-type-on-literal.a24

```algol24
var L : List  of Integer := [1, 2];
var M : Map   of Integer := [:];
var S : Stack of Integer := Stack ();

WriteLn ('never reached');

var Bad : List of Integer := ['text'];
```

```console
$ algc refusals/0177-element-type-on-literal.a24
Uncaught: Expected Integer, found String.
[ERROR] refusals/0177-element-type-on-literal.a24: Expected Integer, found String.
[ERROR] 7 | var Bad : List of Integer := ['text'];
[ERROR]   |     ^^^
exit: 70
```

    conformance  0021-element-types-flow-to-reads.a24

### 5.2 Sections

**[VAR-009]**  In the header of a function, procedure, class or object, `var`
may open a **section**: a run of declarations, each ending in `;`, closed by the
next section marker or by `begin`.

```
VarSection = "var" { identifier { "," identifier } [ ":" Type ] [ ":=" Expression ] ";" } .
```

    unit         Parse A Function Local Var Section

##### conformance/0023-sections.a24

```algol24
function F ();
var
    A, B : Integer;          // VAR-010: several names share one declaration
    Tail : String := 'ok';   // 'ok', not 'o' -- a one-character literal is a
const                        //    Char and would not satisfy String [LEX-023]
    K := 10;                 // VAR-015: const opens a section on the same terms

begin
    A := 1;
    B := 2;

    Exit Str (A + B + K) + Tail;
end

WriteLn (F ());
```

```console
$ algc conformance/0023-sections.a24
13ok
```

**[VAR-010]**  Within a section several names may share one declaration:
`A, B : Integer;` declares both.

    unit         Parse A Comma Group Stays A Group
    unit         Parse A Single Name Is Not A Group
    conformance  0023-sections.a24

**[VAR-011]**  A section is a feature of a **header**, not of a program body. At
the top level `var` declares exactly one name, and a run of declarations
beneath it is read as ordinary statements — `var A : Integer;` followed by
`B : String;` is refused.

**Labels changed how it is refused, and the diagnostic got worse.** `B :`
is now read as a **label** [STM-010] on the statement `String;`, so the line
parses and fails at run time with `Undefined variable 'String'.` rather than at
parse time with `Expect ';' after expression.` The rule is unchanged and the
program is still refused; what is lost is that it used to be caught without
being run, so a mistaken section on a path never taken is now silent. This is
the price of a label needing no keyword, and it is the only place in the
language where the two forms collide.

##### refusals/0010-no-section-at-top-level.a24

```algol24
var A : Integer;
    B : String;
```

```console
$ algc refusals/0010-no-section-at-top-level.a24
Uncaught: Undefined variable 'String'.
exit: 70
```

### 5.3 Constants

**[VAR-012]**  A constant is introduced by `const` and **must** be given a
value. Omitting the initializer is refused with `A constant must be given a
value.`

```
ConstDecl = "const" identifier [ ":" Type ] ":=" Expression ";" .
```

    unit         Parse A Constant Must Be Given A Value

##### refusals/0011-const-must-be-given-a-value.a24

```algol24
const C : Integer;
```

```console
$ algc refusals/0011-const-must-be-given-a-value.a24
Uncaught: A constant must be given a value.
[ERROR] refusals/0011-const-must-be-given-a-value.a24: A constant must be given a value.
[ERROR] 1 | const C : Integer;
[ERROR]   |       ^
exit: 70
```

**[VAR-013]**  A constant may not be assigned to. The attempt is refused with
`Can't assign to constant 'C'.`

##### refusals/0012-const-is-not-assignable.a24

```algol24
const C := 1;
C := 2;
```

```console
$ algc refusals/0012-const-is-not-assignable.a24
Uncaught: Can't assign to constant 'C'.
exit: 70
```

**[VAR-014]**  A constant's initializer is an **ordinary expression evaluated
at run time**, not a constant expression. `const C := 1 + 2;` is legal, and so
is `const C := V;` where `V` is a variable — the constant takes whatever value
`V` held at that moment.

`const` therefore means *this binding may not be reassigned*, not *this value is
known before the program runs*.

##### conformance/0024-const-is-a-runtime-expression.a24

```algol24
// A constant's initializer is an ordinary expression evaluated when the
// declaration runs, not a constant expression.
const Computed := 1 + 2;
WriteLn (Computed);

// And it may read a variable, so a constant's value need not be known before
// the program runs.  'const' means the BINDING may not be reassigned -- not
// that the value is known in advance.
var V := 9;
const FromVariable := V;
WriteLn (FromVariable);

// Changing V afterwards does not change the constant: it took the value V held
// at that moment.
V := 100;
WriteLn (FromVariable);
```

```console
$ algc conformance/0024-const-is-a-runtime-expression.a24
3
9
9
```

**[VAR-015]**  `const` may open a section on the same terms as `var`, and the
two may appear together in one header.

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
| Foreign | `Pointer` — only in a build with foreign calls [INI-008] |
| Unknown | `Any` — a declaration only, never a runtime type |

**`Pointer` is in the table but not in the corpus's list**, because a program
cannot make one without calling C [TYP-017] and a conformance case must run in
the default build. `0026` therefore names every row but that one.

##### conformance/0026-the-runtime-types.a24

```algol24
class Dog; begin end
type Color = (Red, Green);

// TYP-001: every runtime type answers 'is' to its own name.
WriteLn (1        is Integer);
WriteLn (1.5      is Double);
WriteLn ('ab'     is String);
WriteLn ('a'      is Char);
WriteLn (True     is Boolean);
WriteLn (Dog ()   is Dog);
WriteLn (Red      is Color);
WriteLn (List ()  is List);
WriteLn (Set ()   is Set);
WriteLn (Stack () is Stack);
WriteLn (Array(2) is Array);
WriteLn (Map ()   is Map);
WriteLn (Buffer() is Buffer);
WriteLn (TextFile() is TextFile);

// 'Any' is a declaration, never a runtime type.
WriteLn (1 is Any);

// TYP-003: a one-character value is a Char, and stays one.  Widening moves a
// Char into a String at an assignment context [VAR-017]; 'is' is not one, and
// asks what the value IS rather than what it could become.
WriteLn ('s' is String);
WriteLn ('s' is Char);

// TYP-002: the one compound form is a collection with an element type.
var L : List of Integer := [1];
WriteLn (L.Length);
```

```console
$ algc conformance/0026-the-runtime-types.a24
true
true
true
true
true
true
true
true
true
true
true
true
true
true
false
false
true
1
```

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

**One feature instead of several special cases.** With [LEX-018] making an
Integer unbounded, a width is no longer a representation to match — only a range
to name. `Byte` is `0 .. 255` and says so.

**`Short` is 16 bits, and Turbo Pascal's was not.** TP's `ShortInt` was 8
bits and its `Integer` 16; the modern reading is the one a reader can state
without looking it up, which is the test this language applies.

**There is no unsigned family.** Unsigned types exist to buy one more bit
inside a fixed width and to say "not negative". An unbounded Integer removes the
first reason, and `0 ..` states the second directly rather than encoding it in a
name. It also avoids C#'s corner where `long + ulong` has no type to answer
with.

**Selection ignores the bounds** [FUN-013]. Two subprograms differing only in
a parameter's range claim the **same signature** and are a duplicate — which is
the argument that rule already makes about return types: a call could never tell
them apart. Consulting the bounds would send `Take (200)` and `Take (300)` to
different subprograms, and would let *adding* an overload steal calls from one
that was already there.

**`X is Byte` is nonetheless a range test**, and that is not a contradiction.
The principle is that a program may **ask** about a value; the language may not
silently **dispatch** on one. `is` is the question written where the programmer
wrote it.

**The check lives where widening does, and that is safe for a reason.**
Widening converts and refuses nothing, and making it refuse on a *type*
mismatch would break a shape real programs use: a String reaching a field
declared `Expr`. A *range* check cannot fire on
that shape: it applies only when the declared name is a subrange and the value
is already an Integer.

##### conformance/0153-subranges.a24

```algol24
var B : Byte := 200;

WriteLn (B);
WriteLn (B is Byte);

// It is an Integer, and stays one.  Nothing is ever 'a Byte' -- a subrange
// constrains a value where a type is written, and TYP-001 is unchanged.
WriteLn (B is Integer);
WriteLn (B + 1 is Integer);

// 'is' on a subrange is a RANGE TEST, which is the program asking
// explicitly.  What the language may not do is dispatch on a value silently.
WriteLn (0 is Byte);
WriteLn (255 is Byte);
WriteLn (256 is Byte);
WriteLn (-1 is Byte);
WriteLn (32767 is Short);
WriteLn (-32768 is Short);
WriteLn (65535 is Word);

// Only an Integer is ever within one.
WriteLn (1.5 is Byte);
WriteLn ('a' is Byte);

// The bounds are checked at the assignment contexts [VAR-017].
try
    var Bad : Byte := 300;
except
    on e : String do WriteLn (e);
end

var C : Byte := 1;
C := 250;
WriteLn (C);

try
    C := 999;
except
    on e : String do WriteLn (e);
end

procedure Pixel (R : Byte, G : Byte);
begin
    WriteLn (Str (R) + ',' + Str (G));
end

Pixel (10, 20);

try
    Pixel (10, 300);
except
    on e : String do WriteLn (e);
end
```

```console
$ algc conformance/0153-subranges.a24
200
true
true
true
true
true
false
false
true
true
true
false
false
300 is not in Byte.
250
999 is not in Byte.
10,20
300 is not in Byte.
```

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

**The bounds are literals, not expressions.** A subrange is hoisted like a
class and an enumeration, so its bounds must be known before anything runs — and
an expression would have to be *evaluated*, which needs the declaration to have
run already. The restriction can be relaxed later by admitting constants, and
nothing in the rule prevents it.

**The sign is read by the declaration**, because [LEX-019] still holds: there
is no negative literal, and `-273` is the unary operator applied to one. Where
an expression cannot be evaluated, the same rule is applied by hand.

**An empty subrange is refused where it is read.** `type Empty = 9 .. 0;` is
`A subrange must not be empty: 9 is above 0.` — it admits no value at all, so
every assignment through it would fail and the declaration is the only place
that can say why.

**`type` declares two different things**, and which is decided by the
character after the `=`: a `(` begins an enumeration [ENU-001], anything else a
subrange. Both bind a name that denotes a type and neither binds a value.

##### conformance/0154-declared-subranges.a24

```algol24
type Digit   = 0 .. 9;
type Celsius = -273 .. 1000;

var D : Digit := 7;

WriteLn (D);
WriteLn (D is Digit);

// It is an Integer, and stays one.  A subrange constrains a value where a
// type is written; nothing is ever 'a Digit' [TYP-001].
WriteLn (D is Integer);
WriteLn (D + 1 is Integer);

WriteLn (0 is Digit);
WriteLn (9 is Digit);
WriteLn (10 is Digit);
WriteLn (-1 is Digit);

// The sign is read by the DECLARATION, because there is no negative
// literal [LEX-019].
WriteLn (-273 is Celsius);
WriteLn (-274 is Celsius);
WriteLn (1000 is Celsius);

// The bounds are checked at the assignment contexts [VAR-017].
try
    var Bad : Digit := 10;
except
    on e : String do WriteLn (e);
end

procedure Show (N : Digit);
begin
    WriteLn ('digit ' + Str (N));
end

Show (3);

try
    Show (42);
except
    on e : String do WriteLn (e);
end

// A declared subrange and a predefined one are the same kind of thing.
var B : Byte := 200;
WriteLn (B is Byte);
WriteLn (B is Digit);
```

```console
$ algc conformance/0154-declared-subranges.a24
7
true
true
true
true
true
false
false
true
false
true
10 is not in Digit.
digit 3
42 is not in Digit.
true
false
```

**[TYP-014]**  `Real` is another spelling of `Double`. It is not a second type:
`X is Real` and `X is Double` answer alike, a parameter declared either accepts
the same arguments, and two subprograms differing only in which was written
claim the same signature [FUN-013].

**An alias, not a conversion.** C# settled this shape: `int` *is*
`System.Int32`, one type with two names and no box between them. Java's
`int`/`Integer` duality — two things with almost the same name behaving
differently — is the arrangement this avoids.

**The canonical spelling is `Double`**, and a diagnostic uses it: `X as Real`
on a String is `Cannot cast String to Double.` The alias telling a reader what it
is, is worth more than echoing what they wrote.

**Turbo Pascal's `Real` was a 6-byte software float** from before the 8087,
with no C type to map onto. A type whose only distinction is a 1985 storage
format is the opposite of self-explanatory, so the name survives and the
representation does not. Delphi reached the same conclusion.

**There is no `Single`.** A 32-bit float earns its place in a language whose
values are unboxed, by halving the storage of an array; Algol-24's values are
tagged and one size, so it would cost a reader "32-bit IEEE, less precision"
and buy nothing.

**Replaced where a written type becomes something to compare**, and nowhere
else, so no part of the implementation past the front end knows the alias
exists — the C runtime has no case for it at all. `is` is canonicalised at its
two use sites rather than at the parser, because it carries a token where the
others carry a string.

##### conformance/0152-real-is-double.a24

```algol24
var X : Real := 1.5;

WriteLn (X);
WriteLn (X is Real);
WriteLn (X is Double);

// One type, so widening reaches it exactly as it reaches the other
// spelling [VAR-004].
var Y : Real := 1;
WriteLn (Y);
WriteLn (Y is Double);

// A parameter declared either way accepts the same arguments.
function Twice (R : Real); begin Exit R * 2; end

WriteLn (Twice (3));
WriteLn (Twice (2.5));

var Z : Any := 1.5;
WriteLn (Z as Real);

// The CANONICAL spelling is what a diagnostic names, which is the alias
// telling the reader what it is.
var Bad : Any := 'text';
try
    WriteLn (Bad as Real);
except
    on e : String do WriteLn (e);
end

// It folds like every other name [SRC-011].
WriteLn (1.5 is real);
WriteLn (1.5 is REAL);
```

```console
$ algc conformance/0152-real-is-double.a24
1.5
true
true
1.0
true
6.0
5.0
1.5
Cannot cast String to Double.
true
true
```

**[TYP-002]**  A type is written as an identifier. The only compound form is a
collection type with an element type, written `of` — `List of Integer`,
`Map of Token` [VAR-008].

```
Type = identifier [ "of" identifier ] .
```

    conformance  0026-the-runtime-types.a24

**[TYP-003]**  `Char` and `String` are distinct types, and a one-character
value is a `Char`. `'s' is String` is **false**.

**Widening does not change this.** A Char widens to a String on its way into
a written type [VAR-004], but `is` asks what a value *is*, not what it could
become, and a type test is not one of the six assignment contexts [VAR-017]. A
Char that has widened is a String and answers so; the Char it came from is not.

    conformance  0026-the-runtime-types.a24

### 6.2 Any

**[TYP-004]**  `Any` is the declared type meaning *the type is not known*. A
variable declared `Any` accepts every value; a value of type `Any` does not
satisfy a written type without a cast [VAR-006]. No value ever reports `Any` as
its runtime type, so `X is Any` is false for every `X` [VAL-005].

    conformance  0020-any-accepts-every-value.a24

##### refusals/0013-any-does-not-satisfy-a-written-type.a24

```algol24
var A : Any := 1;
var I : Integer := A;
```

```console
$ algc refusals/0013-any-does-not-satisfy-a-written-type.a24
Uncaught: Expected Integer, found Any.
[ERROR] refusals/0013-any-does-not-satisfy-a-written-type.a24: Expected Integer, found Any.
[ERROR] 2 | var I : Integer := A;
[ERROR]   |     ^
exit: 70
```

> The asymmetry is the point of [VAR-006]: `Any` is where a type is not known,
> and a written type is a claim that it is. Moving from the first to the second
> is a conversion, and `as` is how one is written.

### 6.3 nil

**[TYP-005]**  `nil` is of no type at all. `nil is T` is **false** for every `T`,
including the type `nil` was declared as.

##### conformance/0027-nil-has-no-type.a24

```algol24
// TYP-005: nil is of no type at all -- not even the one it was declared as,
// and not Any.
var X : Integer := nil;
WriteLn (X is Integer);
WriteLn (nil is Any);
WriteLn (X = nil);

// TYP-006: yet nil satisfies every declared type for assignment.  A value that
// is not there has no type to check.
var S : String := nil;
var D : Dog    := nil;
var L : List   := nil;
WriteLn (S);
WriteLn (D);
WriteLn (L);

class Dog; begin end
```

```console
$ algc conformance/0027-nil-has-no-type.a24
false
false
true
nil
nil
nil
```

**[TYP-006]**  `nil` nonetheless satisfies every declared type for the purpose
of assignment — see [VAR-005]. A value that is not there has no type to check,
and is accepted everywhere.

    conformance  0027-nil-has-no-type.a24

**[TYP-013]**  A type name must denote a declared type. A name that denotes
nothing is refused when the program is read, rather than being read as a type no
value has.

The name used never to be resolved: `1 is Nonexistent` was `false`, silently,
so a misspelled type answered false and the branch it guarded never ran — while
an undefined *variable* in the same position has always been
`Undefined variable 'X'`.

**`Any` stays legal**, though `X is Any` is always false [VAL-005]. It names
something; it just never matches.

Checked **folded**, because `is` folds at run time — `SatisfiesType` lowers
both sides, so `1 is dog` finds `class Dog` and refusing it here would refuse a
program that runs.

Writing that case down found a second fault: `InheritsFrom` compared class
names **exactly** while `SatisfiesType` folded its direct match, so
`Puppy() is Dog` was true and `Puppy() is dog` was false — one operator
disagreeing with itself about case, and the C runtime folding both. Fixed with
this rule.

##### refusals/0040-unknown-type-name.a24

```algol24
WriteLn (1 is Nonexistent);
```

```console
$ algc refusals/0040-unknown-type-name.a24
Uncaught: Unknown type 'Nonexistent'.
[ERROR] refusals/0040-unknown-type-name.a24: Unknown type 'Nonexistent'.
[ERROR] 1 | WriteLn (1 is Nonexistent);
[ERROR]   |               ^^^^^^^^^^^
exit: 70
```

##### conformance/0135-type-names-that-denote.a24

```algol24
class Dog; begin end
class Puppy (Dog); begin end
type Colour = (Red, Green);
object Reg; begin end

WriteLn (Puppy () is Dog);
WriteLn (1 is Integer);
WriteLn (1.5 is Double);
WriteLn ('ab' is String);
WriteLn ('a' is Char);
WriteLn (True is Boolean);
WriteLn (1 is Any);

WriteLn ([1] is List);
WriteLn (Set () is Set);
WriteLn (Stack () is Stack);
WriteLn (Array (1) is Array);
WriteLn ([1 : 2] is Map);
WriteLn (Buffer () is Buffer);
WriteLn (TextFile () is TextFile);

WriteLn (Red is Colour);
WriteLn (Reg is Reg);

// Matched WITHOUT REGARD TO CASE, because 'is' folds at run time [SRC-011].
// The check has to fold too, or it would refuse a program that runs.
WriteLn (Puppy () is dog);
```

```console
$ algc conformance/0135-type-names-that-denote.a24
true
true
true
true
true
true
false
true
true
true
true
true
true
true
true
true
true
```

> This is not a gradual-typing case. Gradual typing concerns a *value* whose
> type is not known, which is ordinary; a type *name* is written by the
> programmer and must denote something.

### 6.4 Collection types

**[TYP-007]**  The five collection types are distinguished by their kind, and
each answers `is` to its own name only. A `List` is not a `Set`.

##### conformance/0028-collection-types-are-distinct.a24

```algol24
var L := List ();
WriteLn (L is List);
WriteLn (L is Set);
WriteLn (L is Stack);
WriteLn (L is Array);
WriteLn (L is Map);

var S := Set ();
WriteLn (S is Set);
WriteLn (S is List);
```

```console
$ algc conformance/0028-collection-types-are-distinct.a24
true
false
false
false
false
true
false
```

**[TYP-008]**  `Array` is fixed in size. Its elements begin as `nil`, it is
indexed from zero, and an index outside its bounds is the runtime error
`Index N out of range 0..M.` It does not grow on assignment.

##### conformance/0029-array-is-fixed.a24

```algol24
var A := Array (3);

// Elements begin as nil, and it is indexed from zero.
WriteLn (A[0]);
WriteLn (A.Length);

A[2] := 'x';
WriteLn (A[2]);

// It does not grow on assignment, and an index outside its bounds raises.
A[5] := 'y';
WriteLn ('never reached');
```

```console
$ algc conformance/0029-array-is-fixed.a24
Uncaught: Index 5 out of range 0..2.
nil
3
x
exit: 70
```

**[TYP-009]**  A collection is **not** a class instance. It has no `ClassName`,
and asking for one is the error `Undefined property 'ClassName'.`

##### conformance/0030-collections-have-no-classname.a24

```algol24
class Dog; begin end
WriteLn (Dog ().ClassName);

WriteLn (List ().ClassName);
```

```console
$ algc conformance/0030-collections-have-no-classname.a24
Uncaught: Undefined property 'ClassName'.
Dog
exit: 70
```

### 6.5 What a class type cannot do

These rules are normative in their own right, and together they say which
built-in behavior a program cannot reproduce for a type of its own.

**[TYP-010]**  A class instance is subscriptable when its class declares `Get`
taking one argument: `B[0]` calls `B.Get (0)`. Assignment needs `Put` taking
two: `B[0] := X` calls `B.Put (0, X)`. Without them, `B[0]` is the runtime error
`Subscript target should be an ordinal.`

**The fifth structural protocol**, beside `Contains`, `ToString` [CLS-009],
`Elements` [TYP-011] and `Compare` [VAL-014]. It needs no member name of its
own: `Get` and `Put` are what the built-in collections already answer to
[COL-003], so a collection written in Algol-24 reuses the names rather than
being given a second set.

**A `property` is not one of them**, though it is often listed beside them.
A protocol is *structural* — a class either happens to declare the member or it
does not — while a property is announced with a keyword [CLS-017]. The
difference matters when counting: there are five protocols and one declared
member kind, not six of anything.

**The two forms are two members of different arity**, which is the one
question subscripting adds that no other operator has — and the language already
tells arities apart everywhere else, so nothing has to pair a getter with a
setter syntactically. A class declaring only `Get` is readable and not
assignable, which needs no separate way of saying so.

##### conformance/0171-a-class-that-subscripts.a24

```algol24
class Row;
var
private:
    Cells : List;

begin
    constructor Init (); begin this.Cells := [10, 20, 30]; end

    function  Get (I : Integer) : Any;    begin Exit Cells[I]; end
    procedure Put (I : Integer, V : Any); begin Cells[I] := V; end

    property  Length : Integer;           begin Exit Cells.Length; end
end

var R := Row ();

WriteLn (R[0], ' ', R[1], ' ', R[2]);
WriteLn (R.Length);

R[1] := 99;
WriteLn (R[1]);

// THE TWO FORMS ARE TWO MEMBERS of different arity, so a class declaring
// only 'Get' is readable and not assignable -- which needs no separate way of
// saying so.
class ReadOnly;
var
private:
    Cells : List;

begin
    constructor Init ();              begin this.Cells := [1, 2]; end
    function Get (I : Integer) : Any; begin Exit Cells[I]; end
end

var O := ReadOnly ();
WriteLn (O[0]);

try
    O[0] := 5;
except
    on e : String do WriteLn (e);
end

// A protocol is a NAME and a shape: 'Get' of two arguments is not this one.
class WrongShape;
begin
    constructor Init (); begin end
    function Get (I : Integer, J : Integer) : Any; begin Exit 0; end
end

try
    WriteLn (WrongShape ()[0]);
except
    on e : String do WriteLn (e);
end

// And this is what the whole protocol run was for: a Stack written in
// Algol-24 that reads like the built-in it would replace -- subscripted,
// iterated, ordered, and answering Length without parentheses.
class Stack;
var
private:
    Items : List;

begin
    constructor Init ();                  begin this.Items := []; end
    procedure Push (V : Any);             begin Items.Add (V); end

    function  Get (I : Integer) : Any;    begin Exit Items[I]; end
    function  Elements () : List;         begin Exit Items; end
    property  Length  : Integer;          begin Exit Items.Length; end
    property  IsEmpty : Boolean;          begin Exit Items.Length = 0; end
end

var S := Stack ();
S.Push (10);
S.Push (20);
S.Push (30);

WriteLn (S.Length, ' ', S.IsEmpty, ' ', S[1]);

for var X in S do Write (Str (X) + ' ');
WriteLn ();
```

```console
$ algc conformance/0171-a-class-that-subscripts.a24
10 20 30
3
99
1
Subscript target should be an ordinal.
Subscript target should be an ordinal.
3 false 20
10 20 30 
```

##### conformance/0031-instance-is-not-subscriptable.a24

```algol24
class Box;
var Items : List;
begin
    constructor Init (); begin this.Items := [10, 20]; end
    function At (I); begin Exit this.Items[I]; end
end

var B := Box ();
WriteLn (B.At (0));

WriteLn (B[0]);
```

```console
$ algc conformance/0031-instance-is-not-subscriptable.a24
Uncaught: Subscript target should be an ordinal.
10
exit: 70
```

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

**The protocol is STRUCTURAL, not declared.** There is nothing to inherit
from and nothing to announce: a class either has the method or it does not. `Str`
works the same way through `ToString` [CLS-009], `in` through a `Contains`
taking one argument, ordering through `Compare` [VAL-014] and subscripting
through `Get` and `Put` [TYP-010] — five protocols, one convention.

**A protocol is a name AND a shape.** `Elements` taking an argument does not
implement this one, and such a class is simply not iterable. Neither processor
checked that: the interpreter asked for the first method of the name whatever
its shape, the runtime's `has_method` fell back to the same, and the two then
failed differently — `Index 0 out of range 0..-1.` against
`No matching signature for function.`, neither of them the message above.

**The result is walked, not re-asked.** `Elements` may return another
instance that also declares `Elements`, and the chain resolves — which is what
stops a `List` whose `Elements` returns a `List` from recursing forever.

**It is snapshotted like any other walk** [STM-009]. The method answers a
whole collection, so the loop has its elements before the first pass runs; a
lazy protocol would be a different feature and would take that guarantee away.

##### conformance/0032-instance-is-not-iterable.a24

```algol24
class Bag;
var Items : List;
begin
    constructor Init (); begin this.Items := [1, 2]; end
end

var B := Bag ();
WriteLn (B.Items.Length);

for var X in B do WriteLn (X);
```

```console
$ algc conformance/0032-instance-is-not-iterable.a24
Uncaught: Can only iterate a collection or a String.
2
exit: 70
```

##### conformance/0165-a-class-that-iterates.a24

```algol24
class Bag;
var Items : List;
begin
    constructor Init (); begin this.Items := [10, 20, 30]; end
    function Elements (); begin Exit Items; end
end

for var X in Bag () do Write (Str (X) + ' ');
WriteLn ();

// The result is WALKED, not re-asked, so Elements may hand back another
// instance that also declares Elements and the chain resolves.  That is what
// stops a List whose Elements returns a List from recursing forever.
class Inner;
begin
    constructor Init (); begin end
    function Elements (); begin Exit ['a', 'b']; end
end

class Outer;
begin
    constructor Init (); begin end
    function Elements (); begin Exit Inner (); end
end

for var Y in Outer () do Write (Str (Y) + ' ');
WriteLn ();

// A PROTOCOL IS A NAME AND A SHAPE.  'Elements' taking an argument does not
// implement this one, so the class is simply not iterable -- and says so with
// the ordinary message rather than with a complaint about signatures.
class WrongShape;
begin
    constructor Init (); begin end
    function Elements (N : Integer); begin Exit [1]; end
end

try
    for var Z in WrongShape () do WriteLn (Z);
except
    on e : String do WriteLn (e);
end

// The same rule on the other two protocols.  'Contains ()' does not implement
// membership, and answering it TRUE was a wrong answer rather than an error.
class BadContains;
begin
    constructor Init (); begin end
    function Contains (); begin Exit True; end
end

try
    WriteLn (1 in BadContains ());
except
    on e : String do WriteLn (e);
end

// And 'ToString (N)' does not implement stringification, so the default stands.
class BadToString;
begin
    constructor Init (); begin end
    function ToString (N : Integer); begin Exit 'never'; end
end

WriteLn (Str (BadToString ()));

// Snapshotted like any other walk [STM-009]: Elements answers a whole
// collection, so the loop has its elements before the first pass runs.
class Growing;
var Items : List;
begin
    constructor Init (); begin this.Items := [1, 2]; end
    function Elements (); begin Exit Items; end
end

var G := Growing ();
for var W in G do
begin
    Write (Str (W) + ' ');
    G.Items.Add (99);
end
WriteLn ();
```

```console
$ algc conformance/0165-a-class-that-iterates.a24
10 20 30 
a b 
Can only iterate a collection or a String.
Right operand of 'in' must be a collection or a String.
BadToString instance
1 2 
```

**[TYP-012]**  A class exposes a **field** without parentheses and a **method**
with them: a method named `Length` read as `B.Length` yields the function
itself, printing `<fn Length>`, where a collection's `Length` yields its count.

A class may also declare a **property**: a member read without parentheses,
whose read *is* the call [CLS-017].

**The three are distinguished by their declarations, not by the call site.**
A field is a name in a `var` section, a method is `function` or `procedure`, and
a property is `property`. Nothing at a use site says which — `B.Count` looks the
same whichever it is — which is why the runtime decides, and why the emitter is
told at the declaration rather than working it out at the call.

**A BUILT-IN member reads the same way.** `L.Sort` yields something callable
and prints `<fn Sort>`, because it is the same kind of thing as a bound method.
The spelling is the one the program wrote — a built-in member has no declaration
to take a canonical one from, where a method prints the name its declaration
used.

##### conformance/0033-no-computed-property.a24

```algol24
class Box;
var Items : List;
begin
    constructor Init (); begin this.Items := [1, 2, 3]; end
    function Length (); begin Exit this.Items.Length; end
end

var B := Box ();

// With parentheses, the method runs.
WriteLn (B.Length ());

// Without them, the method itself is the value.
WriteLn (B.Length);

// A collection's Length, by contrast, is a count and needs no parentheses --
// which is exactly the asymmetry a class cannot reproduce.
WriteLn (B.Items.Length);
```

```console
$ algc conformance/0033-no-computed-property.a24
3
<fn Length>
3
```

##### conformance/0149-a-built-in-member-as-a-value.a24

```algol24
var L := [3, 1, 2];

WriteLn (L.Sort);
WriteLn (L.SORT);
WriteLn (L.Add);

// The other two receivers whose members come from the runtime rather than
// from a class.
var B := Buffer (4);
WriteLn (B.Append);

var F := TextFile ();
WriteLn (F.WriteLn);

// And it is callable, which is the point of reading one.
var Sort := L.Sort;
Sort ();
WriteLn (L[0]);
```

```console
$ algc conformance/0149-a-built-in-member-as-a-value.a24
<fn Sort>
<fn SORT>
<fn Add>
<fn Append>
<fn WriteLn>
1
```

---

## 7. Properties of types and values

### 7.1 Assignability

**[VAL-001]**  A value is assignable to a declaration when its type is the
declared type, when the **declaration** is `Any`, when the value is `nil`, when
its class inherits from the declared class, or when it widens to the declared
type [VAR-004].

A value *of* type `Any` is not assignable to a written type; only the reverse
holds [VAR-006].

##### conformance/0034-assignability.a24

```algol24
class Animal; begin end
class Dog (Animal); begin end

// Same type.
var I : Integer := 1;
WriteLn (I);

// The DECLARATION is Any -- every value satisfies it.
var A : Any := Dog ();
WriteLn (A is Dog);

// nil satisfies every declared type.
var N : Dog := nil;
WriteLn (N = nil);

// A subclass stands where its parent is declared, upward only.
var P : Animal := Dog ();
WriteLn (P is Dog);
WriteLn (P is Animal);

// And a value that widens to the declared type [VAR-004].  The narrowing half
// of [VAL-002] is refused rather than truncated.
var W : Double := 1;
var T : String := 'a';
WriteLn (W);
WriteLn (T);
```

```console
$ algc conformance/0034-assignability.a24
1
true
true
true
true
1.0
a
```
    conformance  0140-widening-at-every-context.a24

**[VAL-002]**  Nothing else converts. The widenings are exactly the two of
[VAR-004] — Integer to Double and Char to String — and they apply only at the
assignment contexts of [VAR-017]. There is no narrowing, no conversion between a
number and a String, and no user-defined conversion.

    conformance  0034-assignability.a24
    refusal      0014-no-implicit-narrowing.a24

### 7.2 Type tests

**[VAL-003]**  `X is T` is true when the runtime type of `X` is `T`, or is a
class inheriting from `T`. Inheritance is followed upward only: a `Dog` is an
`Animal`, and an `Animal` is not a `Dog`.

##### conformance/0035-type-tests.a24

```algol24
class Animal; begin end
class Dog (Animal); begin end

// VAL-003: inheritance is followed UPWARD only.
WriteLn (Dog () is Dog);
WriteLn (Dog () is Animal);
WriteLn (Animal () is Dog);

// VAL-004: nil has no type to test -- not even the one it was declared as.
var N : Dog := nil;
WriteLn (N is Dog);
WriteLn (nil is Integer);

// VAL-005: Any is a declaration, never a runtime type -- but it is a legal
// name to write, unlike a name that denotes nothing [TYP-013].
WriteLn (1 is Any);
WriteLn (nil is Any);

// VAL-006: the type name folds case, as every name does [SRC-011].
WriteLn (1 is integer);
WriteLn (1 is INTEGER);
WriteLn (Dog () is dog);
```

```console
$ algc conformance/0035-type-tests.a24
true
true
false
false
false
false
false
true
true
true
```

**[VAL-004]**  `nil is T` is **false** for every `T`. A value that is not there
has no type to test.

    conformance  0035-type-tests.a24

**[VAL-005]**  `X is Any` is **false** for every `X`. `Any` is a declaration,
never a runtime type.

`Any` is nonetheless a legal type name in `is` [TYP-013]. It denotes
something; it just never matches.

    conformance  0035-type-tests.a24

**[VAL-006]**  The type name in `is` is matched case-insensitively, so
`1 is integer` is true. This is [SRC-011] applied to a type name and is not a
special case.

    conformance  0035-type-tests.a24

### 7.3 Casts

**[VAL-007]**  `X as T` is a **checked conversion**. It tells the checker that
the expression has type `T`, and verifies the claim when the program runs: if
`X` is not a `T`, the cast raises.

`nil` satisfies every type [VAR-005] and therefore passes every cast.

`as` is the one construct that moves a value from untyped into typed
[VAR-006], so it carries the whole weight of that boundary. A cast that could
not fail would make the boundary a formality, and every declared type downstream
of it a claim nothing had checked.

A cast that does not hold raises `Cannot cast String to Integer.`

The test is the one `is` uses [VAL-003] — the value's own type, or a class it
inherits from — and deliberately the same code, so `X as T` and `X is T` cannot
come to disagree about what `T` means.

##### conformance/0117-as-is-checked.a24

```algol24
var Good : Any := 1;
WriteLn (Good as Integer);
WriteLn ((Good as Integer) + 1);

// A class hierarchy: a cast to a base class succeeds, by the rule 'is' uses.
class Animal; begin end
class Dog (Animal); begin end
var D : Any := Dog ();
WriteLn (D as Animal is Dog);

// nil satisfies every type [VAR-005] and therefore passes every cast.
var Nothing : Any := nil;
WriteLn (Nothing as Integer);

// And a cast that does not hold raises.
var Bad : Any := 'text';
WriteLn (Bad as Integer);
```

```console
$ algc conformance/0117-as-is-checked.a24
Uncaught: Cannot cast String to Integer.
1
2
true
nil
exit: 70
```

### 7.4 Truthiness

**[VAL-008]**  A value is **falsey** if it is `nil`, `False`, the Integer `0`, or
an enumeration member whose ordinal is `0`. Every other value is **truthy**.

In particular these are all truthy: `0.0`, the empty String `''`, the empty
List `[]`, the empty Map `[:]`, and every `Char`.

Truthiness is **independent of a value's contents**. A collection is a thing,
and a thing is there; `if not S then` therefore does not test emptiness, and
`if S.Length = 0 then` is the only spelling that does.

    unit         Execute Logical Truthy
    unit         Evaluate Unary Bang Nil

##### conformance/0036-truthiness.a24

```algol24
type Flag = (Off, On);

procedure Show (Label, V);
begin
    if V then WriteLn (Label + ' truthy');
    else WriteLn (Label + ' falsey');
end

// Falsey: nil, False, the Integer 0, and an enum member of ordinal 0.
Show ('nil       ', nil);
Show ('False     ', False);
Show ('0         ', 0);
Show ('enum ord 0', Off);

// Everything else is truthy -- including every empty thing, because
// truthiness is independent of a value's contents.
Show ('True      ', True);
Show ('1         ', 1);
Show ('0.0       ', 0.0);
Show ('empty str ', '');
Show ('a Char    ', 'a');
Show ('empty list', []);
Show ('empty map ', [:]);
Show ('enum ord 1', On);

// So this is the only spelling that tests emptiness.
// Length(S), not S.Length: a String has no .Length property interpreted,
// though it has one compiled -- see C-9.
var S := '';
WriteLn (Length (S) = 0);
```

```console
$ algc conformance/0036-truthiness.a24
nil        falsey
False      falsey
0          falsey
enum ord 0 falsey
True       truthy
1          truthy
0.0        truthy
empty str  truthy
a Char     truthy
empty list truthy
empty map  truthy
enum ord 1 truthy
true
```

### 7.5 Equality

**[VAL-009]**  `=` and `<>` promote numerically. `1 = 1.0` is true, and so is
`0 = 0.0`.

    unit         Evaluate Binary Equal Equal

##### conformance/0037-equality.a24

```algol24
// VAL-009: '=' and '<>' promote numerically.
WriteLn (1 = 1.0);
WriteLn (0 = 0.0);
WriteLn (1 <> 1.0);

// VAL-010: a Char is never equal to a String.  Both sides of the first are
// Chars, which is why it is true; Copy yields a String of length one.
WriteLn ('a' = 'a');
WriteLn (Copy ('abc', 0, 1) = 'a');

// VAL-012: nil equals nil.
WriteLn (nil = nil);

// VAL-011: collections and instances compare by IDENTITY, not contents.
WriteLn ([1, 2] = [1, 2]);

var L := [1, 2];
var M := L;
WriteLn (L = M);

class Dog; begin end
WriteLn (Dog () = Dog ());
```

```console
$ algc conformance/0037-equality.a24
true
true
false
true
false
true
false
true
false
```

**[VAL-010]**  A `Char` is never equal to a `String` — see [LEX-026]. `'a'` and
`Copy('abc', 0, 1)` are not equal.

**Widening does not reach equality**, and the asymmetry with [VAL-009] is
deliberate. A numeric promotion has one obvious target — the wider of the two
types — and converting toward it loses nothing. `Char` against `String` has no
target at all: it is a change of representation rather than a widening of value,
and picking a direction would mean `=` converting its operands differently
depending on which side they arrived on.

The rule bites less often than it appears to. `'a' = 'a'` is already true,
because both sides are Chars; it is only reached when one side came from `Copy`,
`Str` or a subscript. The complaint worth acting on is how easily a
one-character String is produced by accident, not how `=` treats one.

    conformance  0037-equality.a24

**[VAL-011]**  Class instances, collections and enumeration members compare by
**identity**, not by contents. `[1, 2] = [1, 2]` is **false**: they are two
collections. Two references to one collection are equal.

**There is still no way for a class to say otherwise, and it is now a
choice rather than an absence.** A program may define `+`, `-`, `*`, `/` and
`div` [EXP-020]; `=` is deliberately not on that list. Equality is coupled to
membership by [VAL-013] — *if `X = Y` then a collection holding `Y` contains
`X`* — and an object key hashes by its address, so defining `=` without a hash
protocol to move with it would break a stated rule silently. That pairing is
what Java's `equals`/`hashCode` discipline exists for, and it is the whole of
what a program-defined `=` would have to settle first.

**Ordering is different** [VAL-014]. A class
declaring `Compare` orders with `<` and its three companions, because ordering
touches no hash and no membership — which is exactly why it was settled while
equality was not.

    conformance  0037-equality.a24

**[VAL-012]**  `nil = nil` is true.

    unit         Evaluate Binary Bang Equal Nil
    conformance  0037-equality.a24

### 7.6 Membership

**[VAL-013]**  `in`, `Contains` and Map key lookup use the equality of
[VAL-009]. Membership and equality are one relation: if `X = Y` then a
collection holding `Y` contains `X`. `1 in [1.0]` is **true**, and a Map holding
the key `1` contains the key `1.0`.

**The hash is what pays for it**, not the comparison. A Map and a Set bucket
by a hash, so an Integer and a Double of one value must reach the same slot or
`Contains` answers false for a key the Map holds. Every `int32` converts to a
`double` exactly, so both hash *as* a double and no range test can get it wrong.

**`-0.0`, `0.0` and `0` are one key.** They were three while the comparison
was a `memcmp`, and the runtime said so in a comment this rule made stale.

**NaN is the one departure, and this rule permits it.** The rule is an
*implication*: a pair that is not equal is unconstrained by it, and `NaN = NaN`
is false. All NaNs are one **key**, because a Map that cannot find a key it
holds is broken in a way no rule asks for.

One implementation, not two: `ObjCollection` delegates to the host's own
`Contains`, so the interpreter's membership *is* the runtime's and the two
cannot disagree.

##### conformance/0127-membership-follows-equality.a24

```algol24
WriteLn (1 = 1.0);

WriteLn (1 in [1.0]);
WriteLn (1.0 in [1]);

var Keys := [1 : 'one'];
WriteLn (Keys.Contains (1.0));

var S := Set ([1]);
WriteLn (S.Contains (1.0));

// The hash is the real work, not the comparison.  A Map keyed 1 and then
// Put under 1.0 holds ONE key, because both reach the same slot.
var M := [1 : 'one'];
M.Put (1.0, 'again');
WriteLn (M.Length);
WriteLn (M.Get (1));

// -0.0 and 0.0 and 0 are one key.  They were three while the comparison was
// a memcmp, and the runtime said so in a comment that this rule made stale.
var Z := Set ();
Z.Add (0.0);
Z.Add (-0.0);
Z.Add (0);
WriteLn (Z.Length);

// Collections still compare by IDENTITY -- two Lists of the same contents are
// not equal, so membership does not find one by the other.
WriteLn ([1] in [[1]]);
```

```console
$ algc conformance/0127-membership-follows-equality.a24
true
true
true
true
true
1
again
1
false
```

### 7.7 Ordering

**[VAL-014]**  `<`, `<=`, `>` and `>=` apply to numbers and to **text**. Text
is ordered **lexicographically by code point**, and a prefix sorts before what
extends it: `'ab' < 'abc'`. Anything else is `Operands must be numbers.`

**A `Char` and a `String` compare as text.** `'a' < 'ab'` is true, and the
one-character String `Str ('a')` orders identically to the Char `'a'` — the two
are still never *equal* [VAL-009], but they sit in one order.

**Code points, not bytes.** UTF-8 was designed so that byte order and
code-point order agree, so an implementation comparing bytes is right by
accident; this one is written in terms of code points so that it is right on
purpose, and so that it cannot disagree with `Ord`.

**Char ordering was by the FIRST BYTE and is now by the code point**, which
this rule never said either way. `'è'` and `'é'` are `C3 A8` and `C3 A9`, share
a lead byte, and compared **equal** — while `Ord` answered 232 and 233, so the
language disagreed with itself about which came first. Fixed with this rule.

A **class instance** orders when its class declares `Compare (Other) : Integer`,
answering negative, zero or positive. Without one, `A < B` on two instances is
`Operands must be numbers.`

**The fourth structural protocol**, beside `Contains`, `ToString` [CLS-009]
and `Elements` [TYP-011]; subscripting [TYP-010] is the fifth. A name and a
shape: `Compare` taking one argument. There is no declaration keyword and no
precedence question, because `<` already has a precedence [EXP-001].

**Ordering costs nothing that equality would.** It touches no hash and no
membership, so unlike [VAL-013]'s coupling of `=` with `in` there is no second
protocol that must move with it. That is why this is settled and equality is
not.

**`Sort` does NOT ask `Compare`** [COL-013], and the asymmetry is forced
rather than chosen. The interpreter delegates `Sort` to the host's, and the
values it passes are `ObjInstance` — the *compiler's* class, not the program's —
so the host would look for `Compare` there and never find it. Answering compiled
and refusing interpreted is the divergence the corpus exists to catch, so
neither does it. Sorting by `Compare` wants an interpreter inside
`ObjCollection` and is a piece of work of its own.

**`Sort` uses this ordering for TEXT** [COL-013], rather than a second one
that happens to agree. It compared with `strcmp`, which stops at an embedded
zero a String is entitled to hold and which orders bytes rather than
characters.

    unit         Evaluate Binary Greater Left Not Number

##### conformance/0166-text-is-ordered.a24

```algol24
// Numbers and Chars still order as they did.

WriteLn (1 < 2);
WriteLn (1.5 >= 1.5);
WriteLn ('a' < 'b');

// Strings now do.
WriteLn ('ab' < 'cd');
WriteLn ('cd' < 'ab');
WriteLn ('ab' <= 'ab');
WriteLn ('' < 'a');

// A prefix sorts before what extends it.
WriteLn ('ab' < 'abc');
WriteLn ('abc' > 'ab');

// A Char and a String compare as TEXT.  The two are still never equal
// [VAL-009], but they sit in one order.
WriteLn ('a' < 'ab');
WriteLn ('ab' > 'a');
WriteLn (Str ('a') < 'b');

// By code point, so case is not folded: 'Z' is 90 and 'a' is 97.
WriteLn ('Z' < 'a');

// CODE POINTS, NOT BYTES.  'è' and 'é' are C3 A8 and C3 A9 in UTF-8: they
// share a lead byte, so comparing bytes would call them EQUAL while Ord
// answers 232 and 233 -- the language disagreeing with itself about order.
WriteLn (Ord ('è'), ' ', Ord ('é'));
WriteLn ('è' < 'é');
WriteLn ('é' <= 'è');

// Sort uses this same ordering [COL-013], not a second one that agrees.
var Names := ['pear', 'Apple', 'banana', 'apple'];
Names.Sort ();
WriteLn (Names);

var Accents := ['é', 'e', 'è', 'z'];
Accents.Sort ();
WriteLn (Accents);

// Mixing text with numbers is still refused.
try
    WriteLn ('ab' < 1);
except
    on e : String do WriteLn (e);
end
```

```console
$ algc conformance/0166-text-is-ordered.a24
true
true
true
true
false
true
true
true
true
true
true
true
true
232 233
true
false
[Apple, apple, banana, pear]
[e, z, è, é]
Operands must be numbers.
```

##### conformance/0170-a-class-that-orders.a24

```algol24
class Money;
var Cents : Integer;
begin
    constructor Init (C : Integer); begin this.Cents := C; end

    function Compare (Other : Money) : Integer; begin Exit Cents - Other.Cents; end
    function ToString () : String;              begin Exit Str (Cents); end
end

var A := Money (100);
var B := Money (200);

WriteLn (A < B, ' ', A > B, ' ', A <= B, ' ', A >= B);
WriteLn (A < A, ' ', A <= A, ' ', A >= A);

// EQUALITY IS UNTOUCHED and stays identity [VAL-011].  Ordering needs no
// hash and no membership, which is exactly why it is settled where equality is
// not: '=' is coupled to 'in' by [VAL-013], and a second protocol would have to
// move with it.
WriteLn (Money (100) = Money (100));
WriteLn (A = A);
WriteLn (Money (100) in [A]);

// Sort does NOT ask Compare, and the asymmetry is forced rather than chosen:
// the interpreter delegates Sort to the host's, whose values are the compiler's
// own instances and not the program's.  Answering compiled while refusing
// interpreted is the divergence this corpus exists to catch.
var L := [Money (300), Money (100)];
try
    L.Sort ();
except
    on e : String do WriteLn (e);
end

// A class without Compare does not order.
class Plain;
begin
    constructor Init (); begin end
end

try WriteLn (Plain () < Plain ()); except on e : String do WriteLn (e); end

// A protocol is a name AND a shape: 'Compare' taking no argument is not it.
class WrongShape;
begin
    constructor Init (); begin end
    function Compare () : Integer; begin Exit 0; end
end

try WriteLn (WrongShape () < WrongShape ()); except on e : String do WriteLn (e); end

// Compare must answer a number.
class BadAnswer;
begin
    constructor Init (); begin end
    function Compare (Other : Any) : Any; begin Exit 'soon'; end
end

try WriteLn (BadAnswer () < BadAnswer ()); except on e : String do WriteLn (e); end
```

```console
$ algc conformance/0170-a-class-that-orders.a24
true false true false
false true true
false
true
false
Can only sort numbers against numbers, or text against text.
Operands must be numbers.
Operands must be numbers.
Compare must answer an Integer.
```

> Ordering text used to mean comparing it character by character, which is what
> `compiler/CEmitter.a24`'s `TextLess` did — a function the compiler wrote for
> itself because the language provided no operator. It is gone.

---

## 8. Declarations and scope

### 8.1 Blocks

**[DCL-001]**  A block is `begin` … `end` and introduces a scope. A name
declared inside it is not visible after it: reading one is `Undefined variable
'X'.`

##### conformance/0039-blocks-and-scope.a24

```algol24
var Outer := 1;

begin
    // DCL-002: a block sees every name of the scopes enclosing it.
    WriteLn (Outer);

    var Inner := 2;
    WriteLn (Inner);
end

// DCL-008: a loop variable belongs to the loop, in both forms.
for var I := 0; I < 2; I := I + 1 do WriteLn (I);
for var E in [7] do WriteLn (E);

// DCL-001: a name declared inside a block is not visible after it.  This is a
// RUNTIME error, which is why the lines above have already printed.
WriteLn (Inner);
```

```console
$ algc conformance/0039-blocks-and-scope.a24
Uncaught: Undefined variable 'Inner'.
1
2
0
1
7
exit: 70
```

**[DCL-002]**  A block sees every name of the scopes enclosing it.

    unit         Resolve One Hop
    unit         Resolve Two Hops
    conformance  0039-blocks-and-scope.a24

### 8.2 Shadowing

**[DCL-003]**  A declaration shadows an outer one of the same name for the rest
of its scope. The outer binding is untouched and reappears when the scope ends.

    unit         Resolve Same Level

##### conformance/0040-shadowing.a24

```algol24
procedure ShadowsAVar ();
var X : Integer := 1;
begin
    begin
        // DCL-003: the inner declaration shadows the outer for the rest of its
        // scope.  The outer binding is untouched.
        var X := 2;
        WriteLn (X);

        X := 3;
        WriteLn (X);
    end

    WriteLn (X);
end

procedure ShadowsAConst ();
const K := 10;
begin
    begin
        // DCL-004: a var may shadow a const.  The inner name is an ordinary
        // variable and may be assigned.
        var K := 20;
        K := 30;
        WriteLn (K);
    end

    // The outer constant is unaffected.
    WriteLn (K);
end

ShadowsAVar ();
ShadowsAConst ();
```

```console
$ algc conformance/0040-shadowing.a24
2
3
1
30
10
```

**[DCL-004]**  A `var` may shadow a `const`. The inner name is an ordinary
variable and may be assigned; the outer constant is unaffected.

    conformance  0040-shadowing.a24

### 8.3 Declaration and use

**[DCL-005]**  A local may not be read in its own initializer. `var X := X;`
inside a block is refused with `Can't read local variable in its own
initializer.`, even where an outer `X` exists.

    unit         Resolve Local Variable Is Own Initializer

##### refusals/0015-own-initializer.a24

```algol24
var X := 1;

begin
    var X := X;
    WriteLn (X);
end
```

```console
$ algc refusals/0015-own-initializer.a24
Uncaught: Can't read local variable in its own initializer.
exit: 70
```

**[DCL-006]**  A **function or class** declared at the top level of a file is
visible throughout that file, wherever it is written. A call may precede the
declaration, so a program may be organized from the top down.

**A class is declared in two phases**, which is what C gets from a header:
every top-level class name is bound to an empty class before anything runs, and
each is *filled in* — the same object, never replaced — when its declaration is
reached. A subclass written above its parent therefore ends up holding the
finished parent.

**Binding the name is not enough**, and it looks as though it were. With only
the name bound, `var D := Dog ();` above the declaration built from an *empty*
class: an object that answered `D is Dog` and had none of Dog's methods. A
silent wrong answer, and worse than the `Undefined variable` it replaced. The
class is built during the hoist, not merely named.

**A class inheriting from something that is not a top-level class *of this
file* is left where it stands**, and that is what keeps [CLS-014] reachable: at
hoist time a `var` has no value yet, so evaluating it would say `Undefined
variable` in place of `'X' is not a class.`

**A parent from a module is one of those**, which is where the limit of
hoisting shows: a module runs at its `uses` [INI-003], so a class inheriting
across a module boundary is built where its declaration stands and the import
has to come first. Written above the `uses`, it is `Undefined variable 'Shape'.`
— a fact about when the name is bound, not about inheritance.

Hoisting made an inheritance **cycle** reachable for the first time — a class
could not previously be declared above its parent at all — so [CLS-013]'s check
grew from a self-reference to a cycle.

##### conformance/0122-functions-are-hoisted.a24

```algol24
WriteLn (Greet ());
WriteLn (Total (2, 3));

function Greet ();          begin Exit 'called from above'; end
function Total (A, B);      begin Exit A + B; end

// A class written below is usable above it.
var D := Dog ();
WriteLn (D is Dog);
WriteLn (D.Speak ());

class Dog;
begin
    constructor Init (); begin end
    function Speak (); begin Exit 'woof'; end
end

// A class may INHERIT from one written below it, which is the case that
// makes hoisting more than binding a name: the parent is bound as an empty
// shell and FILLED IN where its declaration stands, so the child holds the
// finished class because it is the same object.
class Puppy (Hound);
begin
    constructor Init (); begin end
end

class Hound;
begin
    constructor Init (); begin end
    function Speak (); begin Exit 'bay'; end
end

WriteLn (Puppy () is Hound);
WriteLn (Puppy ().Speak ());

// A VARIABLE is not hoisted: its initializer runs in order, and a name read
// before that has no value to give, and is an error rather than nil.
var Ready := 'declared in order';
WriteLn (Ready);
```

```console
$ algc conformance/0122-functions-are-hoisted.a24
called from above
5
true
woof
true
bay
declared in order
```

##### conformance/0146-inherit-across-a-module.a24

```algol24
uses 'modules/Shape';

WriteLn ('root, after the import');

class Circle (Shape);
begin
    constructor Init (); begin end
end

WriteLn (Circle ().Name ());
WriteLn (Circle () is Shape);

// A class of this file may still be inherited from either side of its own
// declaration, which is what hoisting is for.
class Puppy (Hound);
begin
    constructor Init (); begin end
end

class Hound;
begin
    constructor Init (); begin end
    function Name (); begin Exit 'hound'; end
end

WriteLn (Puppy ().Name ());
```

```console
$ algc conformance/0146-inherit-across-a-module.a24
  Shape body
root, after the import
shape
true
hound
```

##### conformance/0147-inherit-before-the-import.a24

```algol24
WriteLn ('root, before the import');

class Circle (Shape);
begin
    constructor Init (); begin end
end

uses 'modules/Shape';

WriteLn (Circle ().Name ());
```

```console
$ algc conformance/0147-inherit-before-the-import.a24
Uncaught: Undefined variable 'Shape'.
root, before the import
exit: 70
```

##### refusals/0046-inherit-from-a-non-class.a24

```algol24
var X := 1;

class C (X);
begin
end
```

```console
$ algc refusals/0046-inherit-from-a-non-class.a24
Uncaught: 'X' is not a class.
exit: 70
```

**[DCL-016]**  A **variable or constant** is not visible before its declaration
has run. Its initializer is an expression evaluated in order [VAR-014], and a
name read before that has no value to give — so it is an error, not `nil`.

The split is deliberate. A function or class declaration is complete as soon
as it is read and has nothing to execute; a `var` has an initializer whose
effects belong at the point it is written. Hoisting the first is what lets a
file be read top-down; hoisting the second would silently substitute `nil` for a
value that does not exist yet.

##### conformance/0044-variables-are-not-hoisted.a24

```algol24
var Ready := 'declared';
WriteLn (Ready);

// A function IS visible above its declaration, and so is a class -- and a
// function called from up here reads the variables that exist WHEN IT RUNS,
// not the ones that existed where it was written.
WriteLn (Ahead ());
WriteLn (Thing ().ClassName);

function Ahead (); begin Exit Ready; end
class Thing; begin end

// Writing to a name does not bind it either: a variable is bound by its
// declaration, so this is the same error a read gets.
try
    Absent := 5;
except
    on e : String do WriteLn (e);
end

var Absent := 1;

// A variable is not visible before its declaration has run.  Its initializer
// is an expression evaluated in order, and a name read before that has no
// value to give -- so this is an error, not nil.
WriteLn (Later);

var Later := 7;
```

```console
$ algc conformance/0044-variables-are-not-hoisted.a24
Uncaught: Undefined variable 'Later'.
declared
declared
Thing
Undefined variable 'Absent'.
exit: 70
```

##### refusals/0033-a-variable-is-not-hoisted.a24

```algol24
WriteLn (Later);

var Later := 7;
```

```console
$ algc refusals/0033-a-variable-is-not-hoisted.a24
Uncaught: Undefined variable 'Later'.
exit: 70
```

**[DCL-007]**  A free name in a function body is resolved **when the body runs**,
not where it is written. Two functions may therefore call each other, provided
neither is called before both declarations have run.

##### conformance/0041-mutual-recursion.a24

```algol24
function IsEven (N);
begin
    if N = 0 then Exit True;
    Exit IsOdd (N - 1);
end

function IsOdd (N);
begin
    if N = 0 then Exit False;
    Exit IsEven (N - 1);
end

WriteLn (IsEven (4));
WriteLn (IsEven (7));
WriteLn (IsOdd (7));
```

```console
$ algc conformance/0041-mutual-recursion.a24
true
false
true
```

> This is why mutual recursion works even under the current implementation,
> where [DCL-006] does not: the *call* inside a body is resolved late, so only a
> call at the top level, above the declaration, meets the missing binding.

### 8.4 Loop variables

**[DCL-008]**  A variable declared in a `for` header belongs to the loop, in
both forms, and is not visible after it ends.

For the counted form this follows from [DCL-001] rather than being a rule of its
own: `for` **desugars into a block** holding the initializer and a `while`, so
the variable is scoped because it is inside a block.

    unit         Parse For Statement
    conformance  0039-blocks-and-scope.a24

### 8.5 this and super

**[DCL-009]**  `this` outside a class is refused with `Can't use 'this' outside a
class.`

    unit         This Is Never Caught

##### refusals/0016-this-outside-a-class.a24

```algol24

```

```console
$ algc refusals/0016-this-outside-a-class.a24
```

**[DCL-010]**  `super` outside a class is refused with `Can't use 'super'
outside a class.`, and inside a class having no superclass with `Can't use
'super' in a class with no superclass.`

##### refusals/0017-super-outside-a-class.a24

```algol24

```

```console
$ algc refusals/0017-super-outside-a-class.a24
```

##### refusals/0018-super-with-no-superclass.a24

```algol24
class Lonely;
begin
    procedure Attempt ();
    begin
        super.Something ();
    end
end

Lonely ().Attempt ();
```

```console
$ algc refusals/0018-super-with-no-superclass.a24
Uncaught: Can't use 'super' in a class with no superclass.
exit: 70
```

### 8.6 Visibility

**[DCL-011]**  `private:` and `public:` are section markers within a class or
object, each governing the members that follow it. A member declared under no
marker is public.

    unit         A Public Member Is Reachable From Outside
    unit         A Private Field Is Not Readable From Outside

##### conformance/0042-visibility.a24

```algol24
class Counter;
private:
var Count : Integer;
public:
var Name : String;

begin
    constructor Init (N);
    begin
        this.Count := 0;
        this.Name  := N;
    end

    // DCL-012: the body starts public however the header ended.  The header
    // above closed under 'public:', and this method is reachable regardless.
    procedure Bump (); begin this.Count := this.Count + 1; end

    function Value (); begin Exit this.Count; end

    // DCL-013: privacy belongs to the CLASS, not to the object -- a method may
    // reach the private members of another instance of its own class.
    function Total (Other : Counter);
    begin
        Exit this.Count + Other.Count;
    end
end

var A := Counter ('a');
var B := Counter ('b');

A.Bump ();
A.Bump ();
B.Bump ();

// DCL-011: a public member is reachable from outside.
WriteLn (A.Name);
WriteLn (A.Value ());

WriteLn (A.Total (B));
```

```console
$ algc conformance/0042-visibility.a24
a
2
3
```

##### refusals/0019-private-through-a-typed-receiver.a24

```algol24
class Counter;
private:
var Count : Integer;
public:
begin
    constructor Init (); begin this.Count := 0; end
end

var C : Counter := Counter ();
WriteLn (C.Count);
```

```console
$ algc refusals/0019-private-through-a-typed-receiver.a24
Uncaught: 'Count' is private to Counter.
exit: 70
```

**[DCL-012]**  The body starts public however the header ended. A `private:` in
the header does not carry across `begin`.

    unit         The Body Starts Public However The Header Ended
    conformance  0042-visibility.a24

**[DCL-013]**  Privacy belongs to the **class**, not to the object. A method may
reach the private members of another instance of its own class.

    unit         Another Instance Of The Same Class Reaches Its Privates
    conformance  0042-visibility.a24

**[DCL-014]**  A subclass does not reach what its parent hid. Reading a parent's
private member through a receiver declared as the parent is refused with
`'N' is private to P.`

    unit         A Subclass Does Not Reach What Its Parent Hid

##### refusals/0020-subclass-does-not-reach-what-a-parent-hid.a24

```algol24
class Parent;
private:
var Secret : Integer;
public:
begin
    constructor Init (); begin this.Secret := 1; end
end

class Child (Parent);
begin
    function Peek (P : Parent); begin Exit P.Secret; end
end

WriteLn (Child ().Peek (Parent ()));
```

```console
$ algc refusals/0020-subclass-does-not-reach-what-a-parent-hid.a24
Uncaught: 'Secret' is private to Parent.
exit: 70
```

**[DCL-015]**  **`private:` is advisory.** It is checked **statically, and
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

**The guarantee is therefore strongest exactly where it is least needed** —
in well-annotated code — and absent from the code most likely to be reaching
somewhere it should not. That is an honest description of a checker in a
gradually typed language, not an accident.

`as` becoming a checked conversion [VAL-007] does not close this. Member
access is not one of the assignment contexts [VAR-017], so nothing obliges a
receiver to be narrowed before it is read through.

    unit         A Private Member Is Caught Through A Declared Receiver

##### conformance/0043-visibility-is-advisory.a24

```algol24
class Counter;
private:
var Count : Integer;
public:
begin
    constructor Init (); begin this.Count := 5; end
end

// Through a receiver declared Any, the static check cannot see the type, and
// the private field is readable...
var C : Any := Counter ();
WriteLn (C.Count);

// ... and writable.
C.Count := 99;
WriteLn (C.Count);
```

```console
$ algc conformance/0043-visibility-is-advisory.a24
5
99
```

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

    unit         Parse Term Plus
    unit         Parse Factor Star

##### conformance/0045-precedence.a24

```algol24
WriteLn (1 + 2 * 3);           // * over +
WriteLn ((1 + 2) * 3);         // parentheses override
WriteLn (-2 * 3);              // unary over *
WriteLn (1 + 1 = 2);           // + over =
WriteLn (1 < 2 = True);        // < over =
WriteLn (not True and False);  // not over and
WriteLn (True or False and False);   // and over or
WriteLn (False and True or True);    // and over or, the other way

// EXP-002: one level is left-associative.  Right-associative, these would be
// 11 and 18.
WriteLn (10 - 2 - 3);
WriteLn (12 / 2 / 3);
```

```console
$ algc conformance/0045-precedence.a24
7
9
-6
true
true
false
true
true
5
2
```

> `1 + 2 * 3` is 7, `-2 * 3` is -6, `not True and False` is false,
> `True or False and False` is true, and `False = False and False` is false.
> Each distinguishes its pair. Verified.

**[EXP-002]**  Binary operators of one level are left-associative:
`10 - 2 - 3` is 5 and `12 / 2 / 3` is 2.

    conformance  0045-precedence.a24

**[EXP-003]**  `as` binds **tightly**, at the level of unary `-` and `not`. It
applies to the operand beside it and to nothing further: `A and B as C` is
`A and (B as C)`, and `A as Integer > 3` is `(A as Integer) > 3`.

The binding stopped being cosmetic when `as` became a checked conversion
[VAL-007]. Under the old reading `False and 5 as Integer` was
`(False and 5) as Integer` — a Boolean cast to Integer, which raises. It is now
`False and (5 as Integer)`, which is `False`.

##### conformance/0118-as-binds-tightly.a24

```algol24
var A : Any := 5;

// Under the old precedence this did not parse at all: the cast consumed the
// expression and the comparison had nothing to attach to.
WriteLn (A as Integer > 3);
WriteLn (A as Integer + 1);

// The line that distinguishes the two readings now that a cast is checked.
// 'and' yields its LEFT operand when that is falsey, so the old reading was
// '(False and 5) as Integer' -- a Boolean cast to Integer, which raises.  The
// new one casts 5, which is already an Integer, and the conjunction is False.
WriteLn (False and 5 as Integer);

// And the ordinary case: the cast applies to B, not to the conjunction.
WriteLn (True and A as Integer);
```

```console
$ algc conformance/0118-as-binds-tightly.a24
true
6
false
5
```

### 9.2 Arithmetic

**[EXP-004]**  Integer arithmetic yields an Integer, **including `/`**, which
divides and truncates toward zero: `7 / 2` is 3 and `-7 / 2` is -3.

    unit         Evaluate Binary Slash

##### conformance/0046-arithmetic.a24

```algol24
// EXP-004: Integer arithmetic yields an Integer, INCLUDING '/', which
// truncates toward zero rather than flooring.
WriteLn (7 / 2);
WriteLn (-7 / 2);
WriteLn (7 * 2);
WriteLn (7 - 2);

// EXP-005: a Double on either side promotes the operation and the result.
WriteLn (7.0 / 2);
WriteLn (7 / 2.0);
WriteLn (1 + 2.0);
WriteLn (2.0 * 3);
WriteLn ((1 + 2.0) is Double);
```

```console
$ algc conformance/0046-arithmetic.a24
3
-3
14
5
3.5
3.5
3.0
6.0
true
```

**[EXP-005]**  A Double on either side promotes the operation and the result:
`7.0 / 2` and `7 / 2.0` are both 3.5, and `1 + 2.0` is `3.0`.

    unit         Evaluate Binary Plus Mixed
    conformance  0046-arithmetic.a24

**[EXP-006]**  Integer division by zero is the runtime error `Division by
zero.` **Double division by zero is not an error**: it yields `Infinity`,
`-Infinity` or `NaN`, and the program continues.

Whether dividing by zero is a fault or a value therefore depends on which
type reached the operator, and [EXP-005] promotes an Integer whenever it meets a
Double — so an edit far from the division can move it from one category to the
other. This is specified rather than merely tolerated: each behavior is right
for its own type. IEEE 754 defines the Double case and there is no integer
infinity to return for the other.

##### conformance/0047-division-by-zero.a24

```algol24
WriteLn (1.0 / 0);
WriteLn (-1.0 / 0);
WriteLn (0.0 / 0);

// Integer division by zero is.  The asymmetry is specified, not tolerated.
WriteLn (1 / 0);
```

```console
$ algc conformance/0047-division-by-zero.a24
Uncaught: Division by zero.
Infinity
-Infinity
NaN
exit: 70
```

**[EXP-007]**  Integer arithmetic never overflows: a result too large for the
machine's width grows to hold it [LEX-018].

**A Double does not**, and the asymmetry is deliberate. A Double follows IEEE
754, so `1.0 / 0` is `Infinity` [EXP-006] rather than an error and precision is
lost silently past 2⁵³. An Integer is exact and unbounded; a Double is
approximate and bounded, and a program choosing between them is choosing
between those.

**A mixed expression is Double arithmetic** [EXP-005], so
`2147483647 + 1.0` is `2.147483648E9` — the Integer promotes to a Double and the
exactness goes with it.

    conformance  0041-integers-grow.a24
    conformance  0136-integer-range.a24

**[EXP-018]**  `A div B` is integer division, said deliberately. It truncates
toward zero as `/` does on two Integers, and **refuses** anything that is not an
Integer.

**It says which division was meant.** `/` is integer division on two Integers
and real division as soon as a Double reaches it [EXP-004], [EXP-005] — so
`X / Y` cannot be read where `X` is declared `Any`, and an edit far from the
division can change which operation it is. `div` always truncates.

**`/` is unchanged**, deliberately. Making it always real would be more
predictable, and is a migration through every division in the tree — `algc`'s
own included. `div` gives the programmer the option of saying plainly which was
meant, and breaks nothing.

**Refusing a Double rather than truncating it** is the bargain `Mod` already
makes. A programmer writing `div` has said the operands are Integers; if they
are not, that is a mistake worth reporting rather than a conversion worth
performing silently.

It binds as `*` and `/` do — a different operation, not a different
precedence, so `A + B div C` groups the way `A + B / C` does.

##### conformance/0155-integer-division.a24

```algol24
WriteLn (7 div 2);
WriteLn (-7 div 2);
WriteLn (7 div 2 is Integer);

// It binds as '*' and '/' do, so this groups as 'A + (B div C)'.
WriteLn (1 + 8 div 2);

// It grows with the Integer it divides [LEX-018].
WriteLn (9223372036854775807 * 2 div 2);

// A Double is REFUSED rather than truncated -- the bargain Mod makes.  '/'
// would quietly do real division instead, which is the ambiguity div exists to
// remove.
try
    WriteLn (7.0 div 2);
except
    on e : String do WriteLn (e);
end

try
    WriteLn (7 div 0);
except
    on e : String do WriteLn (e);
end

// '/' is unchanged, and still means both things.
WriteLn (7 / 2);
WriteLn (7.0 / 2);
```

```console
$ algc conformance/0155-integer-division.a24
3
-3
true
5
9223372036854775807
div expects Integers.
Division by zero.
3
3.5
```

**[EXP-008]**  `+` concatenates when **either** operand is text, converting the
other. `'ab' + 1` is `ab1`, `1 + 'ab'` is `1ab`, and `'a' + 'b'` — two Chars — is
the String `ab`.

A **`Char` mixed with a number** is refused: `'a' + 1` is `A Char and a number
cannot be added; use Succ or Str.` So is `'a' - 1`, with `use Pred.`

**A Char is an ordinal, so the mixed form reads two ways** — step the
character, or join it to the text `1` — and rather than pick one silently the
language makes the program say which: `Succ ('a')` [RT-020] for the step,
`Str ('a') + 1` for the join.

**It used to concatenate, and that quietly widened the Char.** `Str` is how a
Char becomes a String, which is why `Line ('{')` must be declared `Any`
[LEX-026] — yet `'a' + 1` and `Str ('a') + 1` both gave `a1`, so in this one
place the widening happened without being asked for and `Str` was decorative.
[VAR-004] specifies widening **to reach a written type**, at a declaration; `+`
in an expression was never that rule being applied.

**A String mixed with a number still concatenates.** A String is not an
ordinal, so `'ab' + 1` has only one reading and nothing to disambiguate.

    unit         Evaluate Binary Plus String
    conformance  0025-operators-widen.a24

##### conformance/0167-character-arithmetic.a24

```algol24
// The distance between two Chars, as an Integer.

WriteLn ('z' - 'a');
WriteLn ('a' - 'z');
WriteLn ('a' - 'a');

// Code points, so this is the same 232 and 233 that Ord answers.
WriteLn ('é' - 'è');

// Stepping, on a Char and on an Integer.
WriteLn (Succ ('a'), ' ', Pred ('b'));
WriteLn (Succ (5), ' ', Pred (5));
WriteLn (Succ ('è'));

// A CHAR MIXED WITH A NUMBER IS REFUSED.  A Char is an ordinal, so 'a' + 1
// reads two ways -- step the character, or join it to the text '1' -- and
// rather than pick one silently the language makes the program say which.
try WriteLn ('a' + 1); except on e : String do WriteLn (e); end
try WriteLn (1 + 'a'); except on e : String do WriteLn (e); end
try WriteLn ('a' - 1); except on e : String do WriteLn (e); end

// Str is how a Char widens, and now it means something: these two differ.
WriteLn (Str ('a') + 1);
WriteLn (Succ ('a'));

// A STRING mixed with a number still concatenates.  A String is not an
// ordinal, so it has only one reading and nothing to disambiguate.
WriteLn ('ab' + 1);
WriteLn (1 + 'ab');

// And two Chars still concatenate, which is what Turbo Pascal does.
WriteLn ('a' + 'b');

// Anything that is not an ordinal has no Succ.
try WriteLn (Succ (True));  except on e : String do WriteLn (e); end
try WriteLn (Succ ('ab'));  except on e : String do WriteLn (e); end
```

```console
$ algc conformance/0167-character-arithmetic.a24
25
-25
0
1
b a
6 4
é
A Char and a number cannot be added; use Succ or Str.
A Char and a number cannot be added; use Succ or Str.
A Char and a number cannot be subtracted; use Pred.
a1
b
ab1
1ab
ab
Succ failed: 'true' has no ordinal.
Succ failed: 'ab' has no ordinal.
```

**[EXP-019]**  `-` on **two Chars** answers the Integer distance between their
code points: `'z' - 'a'` is 25.

**The only arithmetic a Char takes**, and it is the one that cannot be read
two ways: subtracting two ordinals is a distance and nothing else. Stepping is
`Succ` and `Pred` [RT-020], joining is `Str` and `+` [EXP-008].

**Turbo Pascal has neither**, and this is a deliberate departure from it. TP
answers a distance with `Ord (X) - Ord (Y)`, which stays available and says the
same thing at greater length.

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

**A closed list, and it has to be.** A new operator would need a precedence
and an associativity, and [EXP-001] is a fixed table of seven levels with
nowhere to put one. These five already have a place in it. `operator =` is
refused with `An operator must be one of + - * / div.`

**The LEFT operand decides**, as a receiver does everywhere else in this
language: `Money * 3` is a Money and `3 * Money` is `Operands must be numbers.`
An operator is a member, and a member is reached through the value on its left.

**Unary and binary are told apart by ARITY**, as the two forms of subscript
are [TYP-010]. `operator - (Other)` is subtraction and `operator - ()` is
negation; the language tells arities apart everywhere, so neither form needs a
word of its own.

**This is the one place a keyword was chosen over a protocol**, after six
protocols in a row. `Compare` [VAL-014], `Get` and `Put` are not *translations*
of operators — `Compare` yields four of them, `Get` and `Put` are two halves of
one — while a `Plus` method would be a pure synonym for `+`, a name added
without a concept. Where the name says something the symbol does not, the
protocol wins; here it would not.

**`not` and `:=` are not on the list.** `not` tests truthiness, which
[VAL-008] defines for every value, so a type overloading it lies about a
language-wide property rather than defining its own behavior. `:=` is outside
the mechanism entirely: dispatch is on values [FUN-013], and the left of an
assignment is a location.

**`Mod` is a function and `div` is an operator** [RT-011], so a class may
define `div` and never `mod`. The asymmetry predates this rule.

##### conformance/0172-a-class-that-computes.a24

```algol24
class Money;
var Cents : Integer;
begin
    constructor Init (C : Integer); begin this.Cents := C; end

    operator + (Other : Money) : Money;   begin Exit Money (Cents + Other.Cents); end
    operator - (Other : Money) : Money;   begin Exit Money (Cents - Other.Cents); end
    operator * (N : Integer)   : Money;   begin Exit Money (Cents * N); end
    operator div (N : Integer) : Money;   begin Exit Money (Cents div N); end

    // UNARY, told apart from subtraction by ARITY -- as the two forms of
    // subscript are.  The language tells arities apart everywhere, so neither
    // form needs a word of its own.
    operator - ()              : Money;   begin Exit Money (-Cents); end

    function ToString () : String;        begin Exit Str (Cents); end
end

var A := Money (100);
var B := Money (250);

WriteLn (A + B);
WriteLn (B - A);
WriteLn (A * 3);
WriteLn (B div 5);
WriteLn (-A);

// It composes with the other protocols: an operator answering an instance is
// an instance like any other.
WriteLn ((A + B) - A);

// THE LEFT OPERAND DECIDES, as a receiver does everywhere else in this
// language.  An operator is a member, and a member is reached through the value
// on its left.
try
    WriteLn (3 * A);
except
    on e : String do WriteLn (e);
end

// A class defining no operator is unchanged.
class Plain;
begin
    constructor Init (); begin end
end

try
    WriteLn (Plain () + Plain ());
except
    on e : String do WriteLn (e);
end
```

```console
$ algc conformance/0172-a-class-that-computes.a24
350
150
300
50
-100
250
Operands must be numbers.
Operands must be two numbers, or two strings.
```

##### refusals/0172-an-operator-not-on-the-list.a24

```algol24
class Pair;
var Left, Right : Integer;

begin
    constructor Init (L : Integer, R : Integer); begin this.Left := L; this.Right := R; end

    operator = (Other : Pair) : Boolean; begin Exit Left = Other.Left; end
end
```

```console
$ algc refusals/0172-an-operator-not-on-the-list.a24
Uncaught: An operator must be one of + - * / div.
[ERROR] refusals/0172-an-operator-not-on-the-list.a24: An operator must be one of + - * / div.
[ERROR] 7 |     operator = (Other : Pair) : Boolean; begin Exit Left = Other.Left; end
[ERROR]   |              ^
exit: 70
```

### 9.4 Logical operators

**[EXP-009]**  `and` and `or` **short-circuit**. The right operand is evaluated
only when the left does not decide the result.

    unit         Execute Logical And
    unit         Execute Logical Or

##### conformance/0048-logical-operators.a24

```algol24
var Ran := 0;

function Boom ();
begin
    Ran := Ran + 1;
    Exit True;
end

// EXP-009: the right operand is evaluated only when the left does not decide.
Ran := 0;  var A := False and Boom ();  WriteLn (Ran);
Ran := 0;  var B := True  or  Boom ();  WriteLn (Ran);
Ran := 0;  var C := True  and Boom ();  WriteLn (Ran);
Ran := 0;  var D := False or  Boom ();  WriteLn (Ran);

// EXP-010: both test truthiness rather than requiring a Boolean, and yield an
// OPERAND rather than a Boolean.
WriteLn (0 or 'text');
WriteLn ('text' and 7);
WriteLn (nil or 'fallback');
```

```console
$ algc conformance/0048-logical-operators.a24
0
0
1
1
text
7
fallback
```

**[EXP-010]**  Both operators test truthiness [VAL-008] rather than requiring a
Boolean.

    unit         Execute Logical Truthy
    conformance  0048-logical-operators.a24

### 9.5 Calls

**[EXP-011]**  A call checks arity. A mismatch is `Expected N arguments but got
M.`

**Except where a count is not the callee's rule.** A subprogram whose last
parameter gathers trailing arguments [FUN-005] has a different count by design,
and reports `No matching signature for function.` instead — naming the count
would send the reader to look at the wrong thing, since what refused the call
was the element type. `Write` and `WriteLn` take any number of values [RT-001]
and so can never fail this way at all.

    unit         Call Wrong Number Of Arguments

##### conformance/0049-call-failures.a24

```algol24
function One (A); begin Exit A; end

WriteLn (One (1));

// Too FEW is a failure too, and the more dangerous one: the missing argument
// has to be diagnosed rather than read from wherever the call left off.
try
    WriteLn (One ());
except
    on e : String do WriteLn (e);
end

class Box;
begin
    constructor Init (A); begin end
    function Only (A); begin Exit A; end
end

try
    WriteLn (Box (1).Only (1, 2));
except
    on e : String do WriteLn (e);
end

try
    WriteLn (Box (1).Only ());
except
    on e : String do WriteLn (e);
end

// Construction reports the counts, like any other call with one signature.
try
    WriteLn (Box (1, 2));
except
    on e : String do WriteLn (e);
end

// And uncaught, which is how the failure ends a program.
WriteLn (One (1, 2));
```

```console
$ algc conformance/0049-call-failures.a24
Uncaught: Expected 1 arguments but got 2.
1
Expected 1 arguments but got 0.
No matching signature for function.
No matching signature for function.
Expected 1 arguments but got 2.
exit: 70
```

##### conformance/0145-a-builtin-with-the-wrong-arity.a24

```algol24
WriteLn (Length ('abc'));

try
    WriteLn (Length ('a', 'b'));
except
    on e : String do WriteLn (e);
end

try
    WriteLn (Ord ());
except
    on e : String do WriteLn (e);
end

// Two built-ins take nothing OR one value -- Set and Buffer [RT-001] -- so
// 'expected' is not always a single number.
//
// And Write and WriteLn take ANY number of values, so neither of these is a
// wrong call at all: no argument is the newline on its own, and several are
// run together with nothing between them.  This is the one place a built-in's
// count is never wrong.
WriteLn ();
WriteLn ('a', 'b');

// A name nothing declares is the other failure, for contrast.
try
    WriteLn (Nonexistent (1));
except
    on e : String do WriteLn (e);
end
```

```console
$ algc conformance/0145-a-builtin-with-the-wrong-arity.a24
3
Expected 1 arguments but got 2.
Expected 1 arguments but got 0.

ab
Undefined variable 'Nonexistent'.
```

**[EXP-012]**  Calling something that is neither a function nor a class is
`Can only call functions and classes.`

    unit         Call Non Function
    conformance  0049-call-failures.a24

**[EXP-013]**  Where a name is overloaded, selection is made on the **whole
signature** — the number of arguments and the type of each — and is made **at
run time**, from the arguments actually passed.

**Run-time selection is required, not an implementation choice.** The type
system is gradual, so an argument's declared type may be `Any` or absent while
its value has a definite type: `var A : Any := 1;` passed to a name overloaded on
Integer and String selects the Integer. No static rule could reach that, and an
implementation must not resolve overloads at compile time on declared types
alone.

An argument may **name the parameter it fills** — `Log (Level: 'warn')`. The
arguments are then put in declaration order, so the order at the call site is
free.

**The names select the signature**, which is why the feature exists. Run-time
selection above stays the rule, and stays right; what a programmer who *does*
know which overload they mean has lacked is a way to say so. A name identifies
one signature, where values only describe something several signatures might
accept.

**Positional arguments come first and named ones after.** A positional
argument following a named one is refused, as is a parameter supplied twice, and
a name no parameter has. This is also what spares [FUN-005] a rule of its own:
gathering takes trailing *positional* arguments, and positional arguments end
exactly where naming begins — so naming the absorbing parameter turns gathering
off without anything having to say so.

**`:` rather than `=>`, because the language already has this colon.**
`[k : v]` is a Map literal [COL-001]: a name on the left, a value on the right,
read by parsing an expression and then looking for a colon. A named argument
means the same thing and parses the same way. The ambiguity that usually rules
`:` out is absent — a colon in expression position normally meets a conditional
expression's `? :`, and this language has none, because `?` is an identifier
mark [LEX-008] and `Gate?` is one word.

**A built-in has no named parameters.** Its parameters are not declared in
this language at all — they exist only as a count [RT-001] — so there is no name
to write, and `WriteLn (V: 'abc')` is *A built-in has no named parameters.*

##### conformance/0160-named-arguments.a24

```algol24
procedure Log (Level : String, Message : String);
begin
    WriteLn (Level + ': ' + Message);
end

Log ('warn', 'disk');
Log (Level: 'warn', Message: 'disk');

// The order at the call site is free; the order that matters is the
// declaration's.
Log (Message: 'disk', Level: 'warn');

// Positional first, named after.
Log ('warn', Message: 'disk');

// A name folds like every other name [SRC-011].
Log (level: 'warn', MESSAGE: 'disk');

// Two subprograms of one name, told apart by the names alone.
procedure Note (Level : String, Message : String); begin WriteLn ('two'); end
procedure Note (Code : Integer);                   begin WriteLn ('one'); end

Note (Code: 7);
Note (Level: 'warn', Message: 'x');

// Constructing an instance is a call to the constructor, so its parameters are
// named the same way [CLS-002].
class Dog;
begin
    constructor Init (Name : String, Age : Integer);
    begin
        WriteLn (Name + ' is ' + Str (Age));
    end

    procedure Fetch (What : String, Times : Integer);
    begin
        WriteLn (What + ' x' + Str (Times));
    end
end

var D := Dog (Age: 3, Name: 'Rex');

// And a method, whose class is not known until the receiver is.
D.Fetch (Times: 2, What: 'ball');

// A subprogram held in a variable keeps its parameter names.
var F := Log;

F (Message: 'held', Level: 'warn');

// Naming the absorbing parameter turns absorption OFF, and needs no rule to
// do it [FUN-005]: an arrangement fills every slot exactly once, so the
// arranged call has precisely the declared arity and the exact pass takes it
// before absorption is ever reached.
procedure Take (Label : String, Items : List of Integer);
begin
    WriteLn (Label + ' ' + Str (Items.Length));
end

Take ('a', 1, 2, 3);
Take ('a', Items: [1, 2, 3]);
Take (Items: [1], Label: 'a');

// A name no parameter has.
try
    Log (Levl: 'warn', Message: 'x');
except
    on e : String do WriteLn (e);
end

// A parameter supplied twice.
try
    Log (Level: 'a', Level: 'b');
except
    on e : String do WriteLn (e);
end

// A BUILT-IN has no named parameters.  Its parameters are not declared in
// this language at all -- they exist only as a count -- so there is no name to
// write [RT-001].
try
    WriteLn (V: 'abc');
except
    on e : String do WriteLn (e);
end
```

```console
$ algc conformance/0160-named-arguments.a24
warn: disk
warn: disk
warn: disk
warn: disk
warn: disk
one
two
Rex is 3
ball x2
warn: held
a 3
a 3
a 1
No matching signature for function.
No matching signature for function.
A built-in has no named parameters.
```

##### refusals/0160-a-positional-argument-after-a-named-one.a24

```algol24
procedure Log (Level : String, Message : String);
begin
    WriteLn (Level + ': ' + Message);
end

Log (Level: 'warn', 'disk');
```

```console
$ algc refusals/0160-a-positional-argument-after-a-named-one.a24
Uncaught: A positional argument cannot follow a named one.
exit: 70
```

##### conformance/0050-overload-selection.a24

```algol24
class M;
begin
    function Take (I : Integer);          begin Exit 'integer';      end
    function Take (S : String);           begin Exit 'string';       end
    function Take (C : Char);             begin Exit 'char';         end
    function Take (A : Integer, B : Integer); begin Exit 'two integers'; end
end

var X := M ();

// EXP-013: selection is on the WHOLE signature -- count and each type.
WriteLn (X.Take (1));
WriteLn (X.Take ('ab'));
WriteLn (X.Take ('a'));
WriteLn (X.Take (1, 2));

// Selection is at RUN TIME, from the value actually passed.  A's declared
// type is Any; no static rule could reach the Integer overload from that.
var A : Any := 1;
WriteLn (X.Take (A));

var B : Any := 'ab';
WriteLn (X.Take (B));

// EXP-014: an exact match is preferred.  'a' is a Char and takes the Char
// overload rather than widening to the String one.
WriteLn (X.Take ('a'));
```

```console
$ algc conformance/0050-overload-selection.a24
integer
string
char
two integers
integer
string
char
```

**[EXP-014]**  An overload is chosen by preferring an **exact match** on every
argument; failing that, one reachable by widening [VAR-004], since a parameter
is an assignment context [VAR-017]. When neither fits, the call fails with
`No matching signature for function.`

So a `Char` argument selects a `Char` parameter where one is declared, and
widens to a `String` parameter where it is not.

**Selection makes three passes**, and the order is the rule: one admitting no
widening, then one admitting it, then one admitting **absorption** [FUN-005].
Adding widening to a single pass let *declaration order* decide instead —
`Take('a')` took a `String` overload declared above the `Char` one — which
`conformance/0050` caught at once.

**The third pass is why "a fixed-arity signature beats a variadic one" is
written nowhere.** It is the pass order: absorption never runs when either of
the first two found something, so `Log ('warn', [1, 2])` passes the list rather
than gathering it into a second one holding it.

Each pass runs over the **whole inheritance chain** before the next begins.
An exact match on a parent must beat a widened match on the child, or adding an
overload to a subclass would silently capture calls the parent was answering
exactly.

**Inheritance is not widening.** A `Dog` fits an `Animal` parameter in both
passes, because that is the argument being what the parameter asks for rather
than being converted into it.

    conformance  0050-overload-selection.a24

##### conformance/0137-parameters-match-on-signature.a24

```algol24
function G (N : Integer); begin Exit 'integer ' + Str (N); end
WriteLn (G (7));

// A parameter is an assignment context [VAR-017], so an argument WIDENS into
// it: an Integer where a Double is written, a Char where a String is.  The
// parameter holds the wider type, so this prints 1.0 rather than 1.
function D (X : Double); begin Exit X; end
WriteLn (D (1));

function S (T : String); begin Exit T + '!'; end
WriteLn (S ('a'));

// The same two widenings at a method, which is where they were already
// admitted at the declaration and refused at the call.
class N;
begin
    function Only (T : String); begin Exit 'string only'; end
end
WriteLn (N ().Only ('a'));

// An EXACT match is preferred over a widened one [EXP-014], whatever order
// the overloads are declared in.  Selection makes two passes for this: one
// admitting no widening, then one admitting it.
class M;
begin
    function Take (T : String); begin Exit 'string'; end
    function Take (C : Char);   begin Exit 'char';   end
end
WriteLn (M ().Take ('a'));
WriteLn (M ().Take ('ab'));

// Inheritance is not widening -- a subclass fits its parent's type in both
// passes, because that is the argument being what the parameter asks for.
class Animal; begin end
class Dog (Animal); begin end
function Feed (A : Animal); begin Exit 'fed'; end
WriteLn (Feed (Dog ()));
```

```console
$ algc conformance/0137-parameters-match-on-signature.a24
integer 7
1.0
a!
string only
char
string
fed
```

### 9.6 Subscripting

**[EXP-015]**  Subscripting a String yields the `Char` at that **character**
position, counted from zero [SRC-004]. An index outside the value is
`Index N out of range 0..M.`

##### conformance/0051-string-subscript.a24

```algol24
var S := 'abc';

WriteLn (S[0]);
WriteLn (S[2]);
WriteLn (S[0] is Char);

var T := 'café';

WriteLn (T[3]);
WriteLn (T[3] is Char);
WriteLn (Length (T));

// The bound is in characters too, so the last index is 3 and not 4.
try
    WriteLn (T[4]);
except
    on e : String do WriteLn (e);
end

WriteLn (S[9]);
```

```console
$ algc conformance/0051-string-subscript.a24
Uncaught: Index 9 out of range 0..2.
a
c
true
é
true
4
Index 4 out of range 0..3.
exit: 70
```

**[EXP-016]**  A class instance is subscripted through `Get` and `Put` — see
[TYP-010].

    conformance  0031-instance-is-not-subscriptable.a24
    conformance  0171-a-class-that-subscripts.a24

### 9.7 Assignment

**[EXP-017]**  Assignment is an **expression**, and its value is the value
assigned: `X := (Y := 1)` leaves both at 1.

    unit         Resolve Assignment

##### conformance/0052-assignment-is-an-expression.a24

```algol24
var X := 0;
var Y := 0;

X := (Y := 1);

WriteLn (X);
WriteLn (Y);

// So it may appear where a value is wanted.
var Z := 0;
WriteLn ((Z := 5) + 1);
WriteLn (Z);
```

```console
$ algc conformance/0052-assignment-is-an-expression.a24
1
1
6
5
```

---

## 10. Statements

### 10.1 Blocks and expression statements

**[STM-001]**  A block is `begin` … `end` and may be empty.

    unit         Execute Block Statement

##### conformance/0053-blocks-and-conditionals.a24

```algol24
// STM-001: a block may be empty.
begin
end

// STM-003: the condition is tested for TRUTHINESS, not required to be Boolean.
if 1 then WriteLn ('integer 1 is truthy');
if 0 then WriteLn ('not reached'); else WriteLn ('integer 0 is falsey');
if 'text' then WriteLn ('a String is truthy');
if nil then WriteLn ('not reached'); else WriteLn ('nil is falsey');

// STM-004: an else binds to the NEAREST unmatched if.  Were it bound to the
// outer one, nothing would print here.
if True then
    if False then WriteLn ('not reached');
    else WriteLn ('inner-else');
```

```console
$ algc conformance/0053-blocks-and-conditionals.a24
integer 1 is truthy
integer 0 is falsey
a String is truthy
nil is falsey
inner-else
```

**[STM-002]**  A declaration may **not** stand as the body of a branch or a
loop. `if C then var X := 1;` is refused; the declaration must be inside a block.

It used to be accepted, and the declared name **escaped into the enclosing
scope** — so whether the name existed was decided by a runtime condition, and a
loop body never entered behaved the same way.

A declaration stays legal as a `try` body, which is a statement rather than a
branch: `try var X := 1; …` has to parse.

##### refusals/0034-declaration-as-an-unbraced-body.a24

```algol24
if True then var X := 1;
```

```console
$ algc refusals/0034-declaration-as-an-unbraced-body.a24
Uncaught: A declaration cannot be a branch or loop body; use 'begin' ... 'end'.
[ERROR] refusals/0034-declaration-as-an-unbraced-body.a24: A declaration cannot be a branch or loop body; use 'begin' ... 'end'.
[ERROR] 1 | if True then var X := 1;
[ERROR]   |              ^^^
exit: 70
```

### 10.2 Conditionals

**[STM-003]**  `if Cond then S` with an optional `else S`. The condition is
tested for truthiness [VAL-008], not required to be a Boolean. A missing `then`
is `Expect 'then' after if condition.`

    unit         Execute If Statement
    unit         Execute Else Statement
    unit         Parse If Expect Then
    conformance  0053-blocks-and-conditionals.a24

**[STM-004]**  An `else` binds to the **nearest** unmatched `if`.

    conformance  0053-blocks-and-conditionals.a24

### 10.3 Loops

**[STM-005]**  `while Cond do S`. A missing `do` is `Expect 'do' after
condition.`

    unit         Execute While Loop
    unit         Parse While Expect Do

##### conformance/0054-loops.a24

```algol24
// STM-005: while.
var N := 0;
while N < 3 do
begin
    Write (N);
    N := N + 1;
end
WriteLn ('');

// STM-006: the counted form.
for var I := 0; I < 3; I := I + 1 do Write (I);
WriteLn ('');

// STM-007: for..in over a collection, a String, and a Map.
for var E in [7, 8] do Write (E);
WriteLn ('');

for var C in 'abc' do Write (C);
WriteLn ('');

// Over a Map it yields each KEY, not each value.
for var K in [1 : 'one', 2 : 'two'] do Write (K);
WriteLn ('');

// STM-010: break leaves the innermost enclosing loop.
for var I := 0; I < 10; I := I + 1 do
begin
    if I = 3 then break;
    Write (I);
end
WriteLn ('');

// The INNERMOST one -- the outer loop keeps going.
for var I := 0; I < 3; I := I + 1 do
begin
    for var J := 0; J < 10; J := J + 1 do
    begin
        if J = 1 then break;
        Write (J);
    end
    Write ('|');
end
WriteLn ('');
```

```console
$ algc conformance/0054-loops.a24
012
012
78
abc
12
012
0|0|0|
```

**[STM-006]**  The counted form is `for Init ; Cond ; Step do S`, and it
**desugars into a block** holding the initializer and a `while` — which is why
its variable is scoped [DCL-008].

**The Step is held by the `while`, not appended to the body**, and `continue`
is the reason [STM-010]: with the step written at the end of the body, beginning
the next iteration jumped over it and the loop never ended.

    unit         Execute For Loop
    unit         Parse For Statement
    conformance  0054-loops.a24

##### conformance/0142-two-counted-loops-share-a-name.a24

```algol24
for var I := 0; I < 2; I := I + 1 do Write (I);
WriteLn ('');

for var I := 0; I < 3; I := I + 1 do Write (I);
WriteLn ('');

// And the name is gone once the loop is over [DCL-008].
var I := 'not the loop variable';
WriteLn (I);
```

```console
$ algc conformance/0142-two-counted-loops-share-a-name.a24
01
012
not the loop variable
```

**[STM-007]**  `for var X in C do S` walks a collection or a String. Over a
String it yields each `Char`; over a `Map` it yields each **key**.

    conformance  0054-loops.a24

**[STM-008]**  Iterating anything else is `Can only iterate a collection or a
String.` — see [TYP-011], which is where a class says it is iterable.

    conformance  0032-instance-is-not-iterable.a24

**[STM-009]**  The collection is **snapshotted** when the loop begins.
Adding to it inside the loop does not lengthen the walk.

##### conformance/0055-loop-snapshot.a24

```algol24
var L := [1, 2, 3];

for var E in L do
begin
    Write (E);
    L.Add (E + 10);
end
WriteLn ('');

// The additions did happen -- the walk simply did not see them.
WriteLn (L.Length);
```

```console
$ algc conformance/0055-loop-snapshot.a24
123
6
```

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

**`Name:` needs no keyword**, because `:=` scans as a single token [LEX-005]
and so `X := 1` cannot be read as a label on `= 1`. It is the third place this
shape appears and it means the same thing each time — a name on the left, the
thing it names on the right — beside the Map literal [COL-001] and a named
argument [EXP-013].

**A labelled jump leaves every `try` opened inside the loop it names**, not
merely the innermost one, so more than one frame may have to be unwound at
once.

**A `for` still takes its step.** `continue` skips the rest of the body and
nothing else, so `for var I := 0; I < 5; I := I + 1 do` with a `continue` in it
runs `I := I + 1` on that pass exactly as on every other. This is what separates
`continue` from `break`, which skips the step as well, because leaving a loop
means leaving all of it.

**It is the reason a `for` is not merely a `while`.** A `for` desugars into a
while, and while the step was written at the end of the body a `continue` jumped
over it and the loop never ended — in both processors, since
`while (c) { body; step; }` skips the step in C for the same reason the
tree-walker does. The step is now held by the loop itself, so the interpreter
runs it after catching a `continue` and the C back end writes a real `for`.

    unit         Parse Break Inside A While
    unit         Parse Break Outside A Loop
    conformance  0054-loops.a24

##### conformance/0161-continue.a24

```algol24
for var I := 0; I < 5; I := I + 1 do
begin
    if I = 2 then continue;
    Write (Str (I));
end
WriteLn ();

// while: the programmer steps, so continue is their problem
var J := 0;
while J < 5 do
begin
    J := J + 1;
    if J = 3 then continue;
    Write (Str (J));
end
WriteLn ();

// for ... in
for var C in ['a', 'b', 'c'] do
begin
    if C = 'b' then continue;
    Write (Str (C));
end
WriteLn ();

// break still leaves
for var K := 0; K < 5; K := K + 1 do
begin
    if K = 2 then break;
    Write (Str (K));
end
WriteLn ();

// Leaving a 'try' by continuing must pop the runtime's frame, exactly as
// breaking does.  A frame left behind points at a C frame that has returned,
// and the next raise jumps into dead stack -- so the raise after this loop is
// the part of the case that matters.
for var N := 0; N < 6; N := N + 1 do
begin
    try
        if N = 2 then continue;
        if N = 4 then break;
        Write (Str (N));
    except
        on e : String do WriteLn ('caught ' + e);
    end
end
WriteLn ();

try
    raise 'the frame stack is still sound';
except
    on e : String do WriteLn (e);
end
```

```console
$ algc conformance/0161-continue.a24
0134
1245
ac
01
013
the frame stack is still sound
```

##### conformance/0162-labelled-break-and-continue.a24

```algol24
Outer:
for var I := 0; I < 3; I := I + 1 do
begin
    for var J := 0; J < 3; J := J + 1 do
    begin
        if J = 1 then continue Outer;
        if I = 2 then break Outer;
        Write (Str (I) + Str (J) + ' ');
    end

    // Never reached: continuing the outer loop skips the rest of ITS body.
    Write ('| ');
end
WriteLn ();

// Unlabelled still means the innermost loop.
for var I := 0; I < 2; I := I + 1 do
begin
    for var J := 0; J < 3; J := J + 1 do
    begin
        if J = 1 then break;
        Write (Str (I) + Str (J) + ' ');
    end
end
WriteLn ();

// A label on a 'for ... in', named without regard to case [SRC-011].
Rows:
for var R in ['a', 'b', 'c'] do
begin
    for var C in [1, 2] do
    begin
        if C = 2 then continue rows;
        Write (Str (R) + Str (C) + ' ');
    end
    Write ('never ');
end
WriteLn ();

// A labelled jump leaves every 'try' opened inside the loop it names, not
// merely the innermost one -- so the runtime's frame stack has to be unwound
// by more than one frame at a time.  The raise at the end is what proves it.
Deep:
for var I := 0; I < 3; I := I + 1 do
begin
    try
        for var J := 0; J < 3; J := J + 1 do
        begin
            try
                if I = 1 and J = 1 then break Deep;
                if J = 2 then continue Deep;
                Write (Str (I) + Str (J) + ' ');
            except
                on e : String do WriteLn ('inner ' + e);
            end
        end
    except
        on e : String do WriteLn ('outer ' + e);
    end
end
WriteLn ();

try
    raise 'the frame stack is still sound';
except
    on e : String do WriteLn (e);
end
```

```console
$ algc conformance/0162-labelled-break-and-continue.a24
00 10 
00 10 
a1 b1 c1 
00 01 10 
the frame stack is still sound
```

##### refusals/0021-break-outside-a-loop.a24

```algol24
WriteLn ('never runs');

break;
```

```console
$ algc refusals/0021-break-outside-a-loop.a24
Uncaught: Must be inside a loop to use 'break'.
[ERROR] refusals/0021-break-outside-a-loop.a24: Must be inside a loop to use 'break'.
[ERROR] 3 | break;
[ERROR]   | ^^^^^
exit: 70
```

##### refusals/0161-continue-outside-a-loop.a24

```algol24
WriteLn ('reached');

continue;
```

```console
$ algc refusals/0161-continue-outside-a-loop.a24
Uncaught: Must be inside a loop to use 'continue'.
[ERROR] refusals/0161-continue-outside-a-loop.a24: Must be inside a loop to use 'continue'.
[ERROR] 3 | continue;
[ERROR]   | ^^^^^^^^
exit: 70
```

##### refusals/0162-a-label-no-enclosing-loop-has.a24

```algol24
Outer:
for var I := 0; I < 3; I := I + 1 do
begin
    break Inner;
end
```

```console
$ algc refusals/0162-a-label-no-enclosing-loop-has.a24
Uncaught: No enclosing loop is labelled 'Inner'.
[ERROR] refusals/0162-a-label-no-enclosing-loop-has.a24: No enclosing loop is labelled 'Inner'.
[ERROR] 4 |     break Inner;
[ERROR]   |     ^^^^^
exit: 70
```

### 10.4 Case

**[STM-011]**  A `case` names a value, then arms, then `end`. An arm may list
several values separated by commas, and a final `else` is optional.

```
CaseStmt = "case" Expression "of" { Arm } [ "else" Statement ] "end" .
Arm      = Expression { "," Expression } ":" Statement .
```

##### conformance/0056-case.a24

```algol24
procedure Classify (V);
begin
    case V of
        1      : WriteLn ('one');
        2, 3   : WriteLn ('two or three');
    else
        WriteLn ('other');
    end
end

Classify (1);
Classify (2);
Classify (3);
Classify (9);

// STM-012: arms compare with '=' [VAL-009], which promotes -- so a Double
// matches an Integer arm of the same value.
Classify (1.0);

// STM-013: no arm and no else means nothing happens, and execution continues.
procedure NoElse (V);
begin
    case V of
        1 : WriteLn ('matched one');
    end
    WriteLn ('continued');
end

NoElse (1);
NoElse (2);
```

```console
$ algc conformance/0056-case.a24
one
two or three
two or three
other
one
matched one
continued
continued
```

**[STM-012]**  `case` **desugars into an if/else-if chain**. There is no case
statement downstream of the parser, and two consequences follow from that rather
than from any rule of their own:

- Arms compare with `=` [VAL-009], so a `Double` matches an `Integer` arm of the
  same value — `1.0` matches the arm `1`.
- There is no fall-through. At most one arm runs.

    conformance  0056-case.a24

**[STM-013]**  When no arm matches and there is no `else`, nothing happens and
execution continues after the `end`.

    conformance  0056-case.a24

### 10.5 Exit

**[STM-014]**  `Exit` returns from the enclosing function or procedure, with a
value in a function and bare in a procedure. Statements after it do not run.

##### conformance/0057-exit.a24

```algol24
// With a value in a function.
function Answer ();
begin
    Exit 7;
    WriteLn ('not reached');
end

WriteLn (Answer ());

// Bare in a procedure.
procedure Early (Stop);
begin
    WriteLn ('before');
    if Stop then Exit;
    WriteLn ('after');
end

Early (True);
Early (False);
```

```console
$ algc conformance/0057-exit.a24
7
before
before
after
```

**[STM-015]**  `Exit` at the top level is refused with `Can't return from
top-level code.`

    unit         Invalid Return

##### refusals/0022-exit-at-top-level.a24

```algol24

```

```console
$ algc refusals/0022-exit-at-top-level.a24
```

### 10.6 Exceptions

**[STM-016]**  `raise E` carries **any value** — a String, an Integer, a class
instance, anything.

    unit         Parse Raise

##### conformance/0058-exceptions.a24

```algol24
class Base; begin end
class Derived (Base); begin end

// STM-016: raise carries any value.
try raise 42;      except on e : Integer do WriteLn ('Integer: ' + Str (e)); end
try raise 'text';  except on e : String  do WriteLn ('String: ' + e);        end

// STM-017: a handler for a base class catches a derived value.
try raise Derived (); except on e : Base do WriteLn ('base caught derived'); end

// STM-018: the MOST DERIVED handler runs, however the handlers are ordered.
try
    raise Derived ();
except
    on e : Base    do WriteLn ('wrong: base');
    on e : Derived do WriteLn ('derived, base written first');
end

try
    raise Derived ();
except
    on e : Derived do WriteLn ('derived, derived written first');
    on e : Base    do WriteLn ('wrong: base');
end

// STM-019: a handler without 'on' is the catch-all.
try raise 1.5; except WriteLn ('catch-all'); end

// STM-020: a runtime error raised by the language is catchable AS A STRING,
// carrying the diagnostic as its value.
try
    WriteLn (1 / 0);
except
    on e : String do WriteLn ('caught: ' + e);
end
```

```console
$ algc conformance/0058-exceptions.a24
Integer: 42
String: text
base caught derived
derived, base written first
derived, derived written first
catch-all
caught: Division by zero.
```

**[STM-017]**  A handler is written `on e : T do S` and matches on the runtime
type name of the raised value. A handler for a base class catches a derived
value.

    unit         Parse Try With A Typed Handler
    conformance  0058-exceptions.a24

**[STM-018]**  The **most derived** matching handler runs, however the
handlers are ordered. Writing the base first does not shadow the derived one.

This is a deliberate departure from first-match, and [STM-023] is what makes
it total: two handlers for one type are refused, so "most derived" always names
exactly one handler and there is never a tie to break by position. The
commonest bug in a first-match language — a base handler written above a derived
one, quietly swallowing everything — cannot be written here.

    conformance  0058-exceptions.a24

**[STM-023]**  Two handlers for the same type on one `try` are refused with
`Duplicate handler for 'T'.`

##### refusals/0023-duplicate-handler.a24

```algol24
class Base; begin end

try
    raise Base ();
except
    on e : Base do WriteLn ('first');
    on e : Base do WriteLn ('second');
end
```

```console
$ algc refusals/0023-duplicate-handler.a24
Uncaught: Duplicate handler for 'Base'.
[ERROR] refusals/0023-duplicate-handler.a24: Duplicate handler for 'Base'.
[ERROR] 7 |     on e : Base do WriteLn ('second');
[ERROR]   |            ^^^^
exit: 70
```

**[STM-019]**  A handler written without `on` is the catch-all and matches any
raised value.

    unit         Parse Untyped Handler Is The Catch All
    unit         Parse Empty Except Is The Catch All
    conformance  0058-exceptions.a24

**[STM-020]**  A runtime error raised by the language is catchable **as a
String**, carrying the diagnostic as its value: dividing by zero inside a `try`
is caught by `on e : String` with `e` equal to `Division by zero.`

    conformance  0058-exceptions.a24

**[STM-021]**  A value raised and never caught ends the program, printing
`Uncaught: ` followed by the value, and exits with status **70**.

##### conformance/0059-uncaught-exits-70.a24

```algol24
WriteLn ('before');

raise 'boom';
```

```console
$ algc conformance/0059-uncaught-exits-70.a24
Uncaught: boom
before
exit: 70
```

### 10.7 print

**[STM-022]**  There is no print statement. `WriteLn` [RT-015] writes a value
and a newline, and it is an ordinary built-in rather than syntax.

The statement existed, and `print` was a keyword for it [LEX-010], so the
word could not be used as a name.

**It also bypassed the test runner's output suppression**, which `Write` and
`WriteLn` respect — so a compiled suite printed the sample program before its
first test while interpreted it printed nothing. That behavior went with the
statement, and nothing replaces it: output during a test run is suppressed for
every built-in alike.

    conformance  0133-print-is-an-ordinary-name.a24

##### refusals/0039-print-is-not-a-statement.a24

```algol24
print 123;
```

```console
$ algc refusals/0039-print-is-not-a-statement.a24
Uncaught: Expect ';' after expression.
[ERROR] refusals/0039-print-is-not-a-statement.a24: Expect ';' after expression.
[ERROR] 1 | print 123;
[ERROR]   | ^^^^^
exit: 70
```

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

**Direction is not the constraint; nesting is.** A backward jump costs
nothing that a forward one does not — the interpreter resumes a block at an
index, and an index may move either way, while C's `goto` has never cared. What
neither processor can do is jump **into** a nested block: the interpreter's jump
travels as an exception, which propagates outward and has no way inward, and C
would be skipping initializers. Pascal restricts it the same way and for the
same reason.

**It may not leave the subprogram.** C's cannot, and the interpreter's would
unwind past the call it should have stayed inside.

**The check is the Resolver's, not the parser's**, because a forward jump
names a label the parser has not reached yet. The Resolver has the whole block
in hand and so can answer for both directions at once — which is also where
`break` and `continue` differ: a loop they are inside has always been entered
already, so the parser can answer for those.

**A jump out of a `try` must leave its frame.** The runtime's frame stack is
explicit, and a frame left behind points at a C frame that has returned; the
next `raise` then longjmps into it. A `goto` out of two `try` blocks to a
top-level label popped nothing at first, and the compiled program ran a handler
the interpreter never reached — the two processors disagreeing about a program,
which is the one thing the C back end exists not to do.

##### conformance/0163-goto.a24

```algol24
// Forward, same block.
WriteLn ('a');
goto Skip;
WriteLn ('never');
Skip:
WriteLn ('b');

// Backward -- a loop written by hand.
var N := 0;
Again:
N := N + 1;
Write (Str (N));
if N < 4 then goto Again;
WriteLn ();

// Outward: out of a loop and out of an if, to a label in the enclosing block.
for var I := 0; I < 5; I := I + 1 do
begin
    if I = 2 then goto Done;
    Write (Str (I));
end
WriteLn ('never either');

Done:
WriteLn (' done');

// A jump out of a 'try' must LEAVE ITS FRAME.  The runtime's frame stack is
// explicit, and a frame left behind points at a C frame that has returned -- so
// the raise at the end is what proves the pops happened.  Without them a
// compiled program runs the inner handler and prints a line the interpreter
// never prints.
try
    try
        goto Out;
    except
        on e : String do WriteLn ('inner');
    end
except
    on e : String do WriteLn ('outer');
end

WriteLn ('never a third time');

Out:
WriteLn ('out');

try
    raise 'the frame stack is still sound';
except
    on e : String do WriteLn (e);
end

// A label is a name, so it folds [SRC-011].
goto FINISH;
WriteLn ('never a fourth time');
Finish:
WriteLn ('finish');
```

```console
$ algc conformance/0163-goto.a24
a
b
1234
01 done
out
the frame stack is still sound
finish
```

##### refusals/0163-goto-into-a-nested-block.a24

```algol24
goto Inside;

begin
    Inside:
    WriteLn ('unreachable');
end
```

```console
$ algc refusals/0163-goto-into-a-nested-block.a24
Uncaught: No label 'Inside' is in scope.
exit: 70
```

##### refusals/0164-goto-out-of-a-subprogram.a24

```algol24
Home:
WriteLn ('at home');

procedure Wander ();
begin
    goto Home;
end

Wander ();
```

```console
$ algc refusals/0164-goto-out-of-a-subprogram.a24
Uncaught: No label 'Home' is in scope.
exit: 70
```

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

    unit         Parse Function
    unit         Parse Function No Open Parenthesis

##### conformance/0060-subprogram-declarations.a24

```algol24
// FUN-001: parameters may be typed or untyped, and a return type is optional.
function Bare (A);                     begin Exit A;     end
function Typed (A : Integer);          begin Exit A;     end
function Returns (A) : Integer;        begin Exit A;     end
function Both (A : Integer) : Integer; begin Exit A;     end
function None ();                      begin Exit 0;     end
procedure Proc (A);                    begin WriteLn (A); end

WriteLn (Bare (1));
WriteLn (Typed (2));
WriteLn (Returns (3));
WriteLn (Both (4));
WriteLn (None ());
Proc (5);

// FUN-002: a subprogram that returns without a value yields nil -- whether it
// falls off the end or exits bare.
function NoExit (); begin end
WriteLn (NoExit ());

procedure BareExit (); begin Exit; end
WriteLn (BareExit ());
```

```console
$ algc conformance/0060-subprogram-declarations.a24
1
2
3
4
0
5
nil
nil
```

**[FUN-002]**  A subprogram that returns without a value yields `nil`.

    conformance  0060-subprogram-declarations.a24

**[FUN-003]**  A **procedure** may not `Exit` a value. `Exit E;` inside one is
refused; `Exit;` and falling off the end are the ways a procedure returns, and
its result is always `nil` [FUN-002].

A **function** may `Exit` a value or not, and yields `nil` when it does not.

A function declared **inside** a procedure may still exit a value: the
restriction belongs to the body being parsed, not to everything within it.

The restriction is what makes the word mean something. Without it `procedure`
is a comment, and a reader cannot tell from a declaration whether a call has a
result worth using — which the C back end must also decide, and which every
caller must otherwise guard.

##### conformance/0111-procedure-cannot-exit-a-value.a24

```algol24
procedure Early (Stop);
begin
    WriteLn ('before');
    if Stop then Exit;
    WriteLn ('after');
end

Early (True);
Early (False);

// A function declared INSIDE a procedure may still exit a value -- the
// restriction is saved and restored around a body, not merely set.
procedure Outer ();
begin
    function Inner (); begin Exit 7; end
    WriteLn (Inner ());
end

Outer ();
```

```console
$ algc conformance/0111-procedure-cannot-exit-a-value.a24
before
before
after
7
```

##### refusals/0031-procedure-cannot-exit-a-value.a24

```algol24
procedure P ();
begin
    Exit 7;
end

WriteLn (P ());
```

```console
$ algc refusals/0031-procedure-cannot-exit-a-value.a24
Uncaught: A procedure cannot exit a value.
[ERROR] refusals/0031-procedure-cannot-exit-a-value.a24: A procedure cannot exit a value.
[ERROR] 3 |     Exit 7;
[ERROR]   |     ^^^^
exit: 70
```

**[FUN-004]**  A declaration may not have more than 255 parameters:
`Can't have more than 255 parameters.`

    unit         Parse Function More Than 255 Parameters

##### refusals/0024-too-many-parameters.a24

```algol24
function Wide (P0, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, P20, P21, P22, P23, P24, P25, P26, P27, P28, P29, P30, P31, P32, P33, P34, P35, P36, P37, P38, P39, P40, P41, P42, P43, P44, P45, P46, P47, P48, P49, P50, P51, P52, P53, P54, P55, P56, P57, P58, P59, P60, P61, P62, P63, P64, P65, P66, P67, P68, P69, P70, P71, P72, P73, P74, P75, P76, P77, P78, P79, P80, P81, P82, P83, P84, P85, P86, P87, P88, P89, P90, P91, P92, P93, P94, P95, P96, P97, P98, P99, P100, P101, P102, P103, P104, P105, P106, P107, P108, P109, P110, P111, P112, P113, P114, P115, P116, P117, P118, P119, P120, P121, P122, P123, P124, P125, P126, P127, P128, P129, P130, P131, P132, P133, P134, P135, P136, P137, P138, P139, P140, P141, P142, P143, P144, P145, P146, P147, P148, P149, P150, P151, P152, P153, P154, P155, P156, P157, P158, P159, P160, P161, P162, P163, P164, P165, P166, P167, P168, P169, P170, P171, P172, P173, P174, P175, P176, P177, P178, P179, P180, P181, P182, P183, P184, P185, P186, P187, P188, P189, P190, P191, P192, P193, P194, P195, P196, P197, P198, P199, P200, P201, P202, P203, P204, P205, P206, P207, P208, P209, P210, P211, P212, P213, P214, P215, P216, P217, P218, P219, P220, P221, P222, P223, P224, P225, P226, P227, P228, P229, P230, P231, P232, P233, P234, P235, P236, P237, P238, P239, P240, P241, P242, P243, P244, P245, P246, P247, P248, P249, P250, P251, P252, P253, P254, P255);
begin
    Exit P0;
end
```

```console
$ algc refusals/0024-too-many-parameters.a24
Uncaught: Can't have more than 255 parameters.
exit: 70
```

### 11.2 Parameters and results

**[FUN-005]**  A call checks the number of arguments — see [EXP-011] — unless
the subprogram's **last parameter is a `List of T`**, which **gathers** the
trailing arguments into a list. `Log ('warn', 1, 2)` is `Log ('warn', [1, 2])`,
and `Log ('warn')` is `Log ('warn', [])`.

**An element type is what makes a parameter absorbing**, so a bare `List`
does not gather. There would be nothing to check the gathered arguments
against, and it leaves `List` as the spelling for a parameter that wants the
list itself and nothing else.

**The element type replaces the arity check and is stricter than it.**
`Log ('warn', 1, 2, 'red')` against `List of Integer` is still refused, because
the stray argument is not an Integer — and it is refused with *No matching
signature for function.* rather than a count, which would name the wrong thing.

**Gathering nothing yields the empty list.** That is structural and not a
default: absorbing none gives `[]` by the same rule that absorbing three gives
a list of three. It is what makes `WriteLn ()` an ordinary call [RT-001].

**No new syntax, and that is the design rather than an economy.** The
declaration already says `List of T` [VAR-008]; absorption is a *reading* of a
type that exists, not a marker added to it. It became possible only when
element types were admitted on parameters — before that a bare `List` carried
no element type.

    conformance  0049-call-failures.a24

##### conformance/0158-varargs-from-an-element-type.a24

```algol24
function Total (Label : String, Items : List of Integer) : Integer;
var
    Sum : Integer := 0;

begin
    for var I := 0; I < Items.Length; I := I + 1 do Sum := Sum + Items[I];

    Exit Sum;
end

WriteLn (Total ('a', 1, 2, 3));

// Gathering NOTHING yields the empty list. It is STRUCTURAL and not a
// default: absorbing none gives [] by the same rule that absorbing three gives
// a list of three.
WriteLn (Total ('a'));

// An exact match is preferred [EXP-014], so the list is passed rather than
// gathered into a second list holding it.
WriteLn (Total ('a', [1, 2, 3]));

// An ELEMENT TYPE is what makes a parameter absorbing, so a bare 'List' does
// not absorb -- there would be nothing to check the gathered arguments against,
// and it leaves 'List' as the spelling for a parameter that wants the list
// itself and nothing else.
procedure Bare (Items : List);
begin
    WriteLn (Items.Length);
end

Bare ([4, 5]);

try
    Bare (4, 5);
except
    on e : String do WriteLn (e);
end

// The element type REPLACES the arity check and is stricter than it: the
// stray argument is refused because it is not an Integer, not because there
// are too many.
try
    WriteLn (Total ('a', 1, 2, 'red'));
except
    on e : String do WriteLn (e);
end

// A fixed-arity signature beats an absorbing one. That is not a rule of its
// own -- it is the pass order [EXP-014], since absorption is the third pass and
// never runs when either of the first two found something.
procedure Pick (A : Integer, B : Integer);
begin
    WriteLn ('fixed');
end

procedure Pick (Ns : List of Integer);
begin
    WriteLn ('gathered ' + Str (Ns.Length));
end

Pick (1, 2);
Pick (1, 2, 3);
Pick ([9]);
Pick ();

// And a method absorbs on the same terms, selected up the whole class chain.
class Logger;
begin
    constructor Init (); begin end

    procedure Log (Level : String, Items : List of Integer);
    begin
        WriteLn (Level + ' ' + Str (Items.Length));
    end
end

var L := Logger ();

L.Log ('warn', 1, 2);
L.Log ('warn', [1, 2]);
L.Log ('warn');
```

```console
$ algc conformance/0158-varargs-from-an-element-type.a24
6
0
6
2
Expected 1 arguments but got 2.
No matching signature for function.
fixed
gathered 3
gathered 1
gathered 0
warn 2
warn 2
warn 0
```

**[FUN-006]**  A subprogram's declared parameter types are enforced on every
call, whether it is a top-level subprogram or a method. A parameter is an
assignment context [VAR-017], so an argument must have the declared type, widen
to it [VAR-004], or be `nil` [VAR-005].

**One rule, one path.** Signature comparison used to run only when the callee
had an *owner* — that is, only for a method — so a top-level subprogram fell
through to an arity check and its annotation was a contract in one place and
decoration in the other. `Fits` is asked of every declared subprogram now.

A **native** is still matched on arity alone, and correctly: its parameters
are not declared in this language, so it has a signature only in the sense of a
count.

    conformance  0137-parameters-match-on-signature.a24

##### refusals/0042-top-level-parameter-type.a24

```algol24
function G (N : Integer); begin Exit N; end

WriteLn (G ('a string'));
```

```console
$ algc refusals/0042-top-level-parameter-type.a24
Uncaught: No matching signature for function.
exit: 70
```

**[FUN-007]**  A **method's** parameter types **are** enforced, because a method
goes through overload selection [EXP-013]. Passing a String where `Integer` is
declared is `No matching signature for function.`

##### refusals/0025-method-parameter-type-is-enforced.a24

```algol24
class M;
begin
    function Take (N : Integer); begin Exit N; end
end

WriteLn (M ().Take ('a string'));
```

```console
$ algc refusals/0025-method-parameter-type-is-enforced.a24
Uncaught: No matching signature for function.
exit: 70
```

**[FUN-008]**  A declared **return** type **is** enforced. `Exit` of a value
that does not fit is `Type mismatch!`

##### refusals/0026-return-type-is-enforced.a24

```algol24
function F () : Integer;
begin
    Exit 'a string';
end

WriteLn (F ());
```

```console
$ algc refusals/0026-return-type-is-enforced.a24
Uncaught: Expected Integer, found String.
[ERROR] refusals/0026-return-type-is-enforced.a24: Expected Integer, found String.
[ERROR] 3 |     Exit 'a string';
[ERROR]   |     ^^^^
exit: 70
```

### 11.3 Closures

**[FUN-009]**  A nested subprogram captures the enclosing variables **by
reference**, and the capture outlives the call that created it. A function
returning a nested one hands back something that keeps reading and writing the
same variable.

##### conformance/0061-closures.a24

```algol24
function MakeCounter ();
var Count : Integer := 0;
begin
    function Next ();
    begin
        // FUN-009: the enclosing variable is captured BY REFERENCE, and the
        // capture outlives the call that created it.
        Count := Count + 1;
        Exit Count;
    end

    Exit Next;
end

var A := MakeCounter ();
WriteLn (A ());
WriteLn (A ());
WriteLn (A ());

// FUN-010: each call to the enclosing subprogram creates a FRESH set of
// captured variables.  Two counters do not share a count.
var B := MakeCounter ();
WriteLn (B ());
WriteLn (A ());
```

```console
$ algc conformance/0061-closures.a24
1
2
3
1
4
```

**[FUN-010]**  Each call to the enclosing subprogram creates a **fresh** set of
captured variables. Two counters made the same way do not share a count.

    conformance  0061-closures.a24

### 11.4 Subprograms as values

**[FUN-011]**  A subprogram's name used without a call is a value. It may be
assigned to a variable, passed as an argument, stored in a collection, and
called from wherever it comes to rest.

    unit         Interpret Local Function

##### conformance/0062-subprograms-as-values.a24

```algol24
function Double (N); begin Exit N * 2; end
function Triple (N); begin Exit N * 3; end

// Assigned to a variable and called from there.
var F := Double;
WriteLn (F (5));

// Passed as an argument.
function Apply (G, N); begin Exit G (N); end
WriteLn (Apply (Triple, 5));

// Stored in a collection and called from where it came to rest.
var Ops := [Double, Triple];
WriteLn (Ops[0] (7));
WriteLn (Ops[1] (7));

var ByName := ['double' : Double];
WriteLn (ByName.Get ('double') (9));
```

```console
$ algc conformance/0062-subprograms-as-values.a24
10
15
14
21
18
```

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

**Two declarations claiming the SAME signature are still a duplicate**, and
the *parameter* types alone decide it. A return type does not distinguish an
overload — selection happens from the arguments, so two subprograms differing
only in what they return could never be told apart at a call. Neither do the
parameter names: `Take (A : Integer)` and `Take (B : Integer)` are one
signature, not two.

**That is not contradicted by named arguments** [EXP-013], and the
distinction is worth keeping straight. Names cannot make two identical
signatures into an overload set; what they do is let a *call* say which of
several genuinely different signatures it means, which is a question about the
call site rather than about the declarations.

The environment binds one name to one value, which is what made the
restriction look structural. The value can be a **set** of subprograms, and the
call selects from it exactly as a method call selects from a class's methods —
the mechanism was already here.

Nothing in this specification ever restricted overloading to methods.
[EXP-013] and [EXP-014] describe selection without qualification; the
restriction lived in two of this document's own notes and in a comment in
`compiler/Resolver.a24`, none of which was a rule.

##### conformance/0138-top-level-overloading.a24

```algol24
function Take (I : Integer);              begin Exit 'integer'; end
function Take (S : String);               begin Exit 'string';  end
function Take (C : Char);                 begin Exit 'char';    end
function Take (A : Integer, B : Integer); begin Exit 'two';     end

WriteLn (Take (1));
WriteLn (Take ('ab'));
WriteLn (Take ('a'));
WriteLn (Take (1, 2));

// Selection is at RUN TIME, from the value actually passed.  A's declared
// type is Any; no static rule could reach the Integer overload from that.
var A : Any := 1;
WriteLn (Take (A));

var B : Any := 'ab';
WriteLn (Take (B));

// An exact match is preferred over a widened one [EXP-014], so the Char
// argument takes the Char overload rather than the String one.
WriteLn (Take ('a'));
```

```console
$ algc conformance/0138-top-level-overloading.a24
integer
string
char
two
integer
string
char
```

##### refusals/0043-same-signature-twice.a24

```algol24
function F (N : Integer); begin Exit 1; end
function F (M : Integer); begin Exit 2; end
```

```console
$ algc refusals/0043-same-signature-twice.a24
Uncaught: 'F' is already defined.
exit: 70
```

**[FUN-012]**  Subprograms may be declared inside subprograms, to any depth.

##### conformance/0063-nesting.a24

```algol24
function Outer ();
begin
    function Middle ();
    begin
        function Inner ();
        begin
            Exit 3;
        end

        Exit Inner () + 20;
    end

    Exit Middle () + 100;
end

WriteLn (Outer ());
```

```console
$ algc conformance/0063-nesting.a24
123
```

##### conformance/0148-a-function-inside-a-method.a24

```algol24
class Box;
var
    N : Integer := 5;

begin
    function Twice ();
    begin
        function Helper ();
        begin
            Exit N * 2;
        end

        Exit Helper ();
    end

    function Bump (By : Integer);
    begin
        function Add (X);
        begin
            this.N := this.N + X;
            Exit this.N;
        end

        Exit Add (By);
    end
end

var B := Box ();

WriteLn (B.Twice ());
WriteLn (B.Bump (3));
WriteLn (B.N);
WriteLn (B.Twice ());
```

```console
$ algc conformance/0148-a-function-inside-a-method.a24
10
8
8
16
```

**[FUN-014]**  A subprogram may name a **C function** instead of having a body.
It is written `external` and a symbol, optionally saying which library the
symbol is in:

```
function TextLength (S : String) : Integer;       external 'strlen';
function Power (X : Double, Y : Double) : Double; external 'pow' in 'libm';
procedure Release (P : Pointer);                  external 'free';
```

Without a library the symbol is looked for in the **running program**, which
covers libc and anything already linked. The declared types say how the
arguments are marshalled: an Integer or a Boolean passes as a machine word, a
Double as a double, a String as a NUL-terminated C string, and a `Pointer` as
itself [TYP-013].

**THE LANGUAGE DEFINES THE CALL AND NOT THE CALLEE**, and this is the first
place that sentence has been needed. What a foreign function does, whether the
symbol exists, and whether the declared types match the C ones are all outside
this specification and cannot be checked by it. A declaration that misdescribes
a C signature is undefined behavior in the ordinary C sense — the conformance
corpus tests that a call is *made*, never what it reaches.

**Both processors go through one implementation.** The tree-walker cannot
call C, but it runs inside a C program, so the marshalling is in the runtime and
the interpreter reaches it through a built-in while a compiled program calls it
directly. Neither can drift from the other because there is nothing to drift.

**A foreign call is available only in a build that has one** [INI-008]. The
default build has no libffi and no `dlopen`, and reports `Foreign calls are not
available in this build: 'X' cannot be reached.` The **bootstrap** therefore
still needs a C compiler and nothing else, which is what that constraint has
always been about.

**`in` rather than a keyword of its own.** The word is already reserved
[LEX-010] and reads correctly — the symbol is *in* the library — so the feature
costs one new keyword instead of two.

**At most eight arguments.** More is `A foreign call takes at most eight
arguments.` The limit is the marshalling buffers' and is not a language
principle; it is stated so that a program meets a message rather than a crash.

##### conformance/0174-a-foreign-call.a24

```algol24
function TextLength (S : String) : Integer;       external 'strlen';
function Power (X : Double, Y : Double) : Double; external 'pow' in 'libm';
function Allocate (Size : Integer) : Pointer;     external 'malloc';
procedure Release (P : Pointer);                  external 'free';

// A declaration is legal whether or not the build can honor it, and so is
// reading one as a value [FUN-011].
var F := TextLength;
WriteLn (F <> Nil);

// The call is where the configuration is felt [INI-008].
try
    WriteLn (TextLength ('hello'));
except
    on e : String do WriteLn (e);
end

try
    WriteLn (Power (2.0, 10.0));
except
    on e : String do WriteLn (e);
end

// 'Pointer' is a type whether or not a Pointer can be obtained.  It denotes
// a declared type [TYP-013], so it may be written on a declaration and tested
// with 'is' -- and nothing that is not a foreign handle is one.
var P : Pointer;
WriteLn (P = Nil);
WriteLn (1 is Pointer);
WriteLn ('text' is Pointer);

try
    Release (Allocate (64));
except
    on e : String do WriteLn (e);
end

// A Buffer answers Address, and THAT needs no foreign call to observe: a
// program builds a region of memory here, and only handing it to C requires a
// build that can [INI-008].
var B := Buffer ();
B.Append ('....');

WriteLn (B.Address is Pointer);
WriteLn (B.Address = B.Address);
WriteLn (B.Address);
WriteLn (B.Text);
```

```console
$ algc conformance/0174-a-foreign-call.a24
true
Foreign calls are not available in this build: 'strlen' cannot be reached.
Foreign calls are not available in this build: 'pow' cannot be reached.
true
false
false
Foreign calls are not available in this build: 'malloc' cannot be reached.
true
true
<pointer>
....
```

**[TYP-017]**  A `Pointer` is an **opaque foreign handle**. It comes from a
foreign call and goes back to one, and the language does nothing else with it:
it has no arithmetic, no ordering, and no conversion to a number.

Two Pointers are equal when they address the same thing. A `Pointer` renders as
`<pointer>`, or `<pointer nil>` for a null one.

A `Buffer` answers **`Address`**, the address of its bytes, so a program can
build a C struct and hand it to a foreign function:

```
var B := Buffer ();
B.Append ('....');

CopyBytes (B.Address, 'ABCD', 4);      // memcpy writes into the Buffer
WriteLn (B.Text);                      // ABCD
```

**A property rather than an implicit conversion at the call.** Passing a
`Buffer` where a `Pointer` is declared would take its address silently; this
language makes a program say when it means something else, which is the same
reason `Str` is how a `Char` widens [LEX-026].

**THE ADDRESS DOES NOT OUTLIVE THE BYTES.** `Resize` may move them and
`Free` ends them, so an address taken before either is stale afterwards. That is
the ordinary C hazard, arrived at honestly rather than hidden — and it is the
reason the address is taken at the point of use rather than stored.

**It renders WITHOUT its address, deliberately.** Printing the address would
make a program's output depend on where the allocator happened to put
something — non-determinism of exactly the kind the fixed-point check exists to
catch — and the value means nothing to the program holding it anyway.

**A type of its own rather than an Integer**, so that it cannot be
arithmetic'd or compared as a number. An Integer would carry the address
faithfully — an Integer is unbounded [LEX-018] — and that is the objection, not
a limitation.

    conformance  0174-a-foreign-call.a24

---

## 12. Classes and objects

### 12.1 Declaration

**[CLS-001]**  A class is declared with an optional superclass, an optional
header of sections, and a body.

```
ClassDecl = "class" identifier [ "(" identifier ")" ] ";"
            [ Sections ] "begin" { Member } "end" .
```

    unit         Parse Class Declaration
    unit         Parse Class No Begin

##### conformance/0064-class-declaration-and-fields.a24

```algol24
class Base;
private:
var Hidden : Integer := 1;
public:
var Shown  : String  := 'shown';
var Items  : List    := [];
var Bare;

begin
    constructor Init (); begin end
    function Peek (); begin Exit this.Hidden; end
end

var A := Base ();
var B := Base ();

// CLS-002: fields come from the header, methods from the body, and visibility
// markers apply to both.
WriteLn (A.Shown);
WriteLn (A.Peek ());

// CLS-006: a field with no initializer begins as nil.
WriteLn (A.Bare);

// CLS-005: a field's initializer is evaluated ONCE PER INSTANCE.  Two
// instances hold two different Lists -- were the initializer shared, both
// would report 1.
A.Items.Add (1);
WriteLn (Str (A.Items.Length) + ' ' + Str (B.Items.Length));

// CLS-001: the superclass clause is optional, and so is the header.
class Minimal;
begin
    constructor Init (); begin end
end
WriteLn (Minimal () is Minimal);
```

```console
$ algc conformance/0064-class-declaration-and-fields.a24
shown
1
nil
1 0
true
```

**[CLS-002]**  Fields are declared in `var` sections of the header [VAR-009];
methods in the body. Visibility markers apply to both [DCL-011].

    conformance  0064-class-declaration-and-fields.a24

### 12.2 Construction

**[CLS-003]**  An instance is made by **calling the class**: `Point(3, 4)`.

##### conformance/0065-construction.a24

```algol24
class Point;
var X, Y : Integer;
begin
    constructor Init (X, Y);
    begin
        this.X := X;
        this.Y := Y;
    end
end

// CLS-003: an instance is made by CALLING THE CLASS.
var P := Point (3, 4);
WriteLn (Str (P.X) + ',' + Str (P.Y));

// CLS-004: a class with no constructor takes no arguments.
class Bare;
begin
    function Hello (); begin Exit 'hello'; end
end
WriteLn (Bare ().Hello ());

// And construction checks the constructor's arity.
WriteLn (Bare (1, 2));
```

```console
$ algc conformance/0065-construction.a24
Uncaught: Expected 0 arguments but got 2.
3,4
hello
exit: 70
```

**[CLS-004]**  A constructor is a member named `constructor Init`. Construction
checks its arity, and a class with no constructor takes no arguments —
`C(1, 2)` on such a class is `Expected 0 arguments but got 2.`

    conformance  0065-construction.a24

**[CLS-005]**  A field's initializer is evaluated **once per instance**, at
construction. Two instances of a class whose field is `List := []` hold two
different Lists.

    conformance  0064-class-declaration-and-fields.a24

**[CLS-006]**  A field with no initializer begins as `nil` [VAR-002].

    conformance  0064-class-declaration-and-fields.a24

### 12.3 Members

**[CLS-007]**  A field is read without parentheses and a method is called with
them. A `property` is read without them too, and its read is the call
[CLS-017].

    unit         Call Setters And Getters

##### conformance/0066-members.a24

```algol24
class Thing;
var Field : String := 'field';
begin
    constructor Init (); begin end
    function Method (); begin Exit 'method'; end
end

var T := Thing ();

// CLS-007: a field is read without parentheses, a method called with them.
WriteLn (T.Field);
WriteLn (T.Method ());

// CLS-008: every instance answers ClassName.
WriteLn (T.ClassName);

// And it answers AHEAD of its fields: the name belongs to the language, so a
// field of that name cannot take it.
class Shadow;
var ClassName : String := 'field value';
begin
    constructor Init (); begin end
end
WriteLn (Shadow ().ClassName);

// CLS-009: with no ToString, an instance renders as its class name and
// ' instance'.
WriteLn (Str (Thing ()));

// With one, the class decides.
class Pretty;
begin
    constructor Init (); begin end
    function ToString (); begin Exit 'I am pretty'; end
end
WriteLn (Str (Pretty ()));
WriteLn (Pretty ());
```

```console
$ algc conformance/0066-members.a24
field
method
Thing
Shadow
Thing instance
I am pretty
I am pretty
```

**[CLS-008]**  Every instance answers `ClassName`, and does so **ahead of its
fields**: the name belongs to the language, so a field of that name cannot take
it.

    conformance  0066-members.a24

**[CLS-009]**  A class declaring `ToString()` — **taking no arguments** —
decides how its instances render through `Str` [RT-006] and wherever a value is
written [RT-015]. With none, an instance renders as its class name followed by
` instance` — `C instance`.

**The arity is part of the protocol**, as it is for `Elements` [TYP-011]. A
`ToString` taking an argument does not implement this one and the default
rendering stands, rather than the call being attempted and failing.

    conformance  0066-members.a24
    conformance  0165-a-class-that-iterates.a24

**[CLS-010]**  Reading or calling a member the class does not have is
`Undefined property 'X'.`

    unit         Call Undefined Getter

##### conformance/0067-undefined-property.a24

```algol24
class Thing;
begin
    constructor Init (); begin end
end

WriteLn (Thing ().Nope);
```

```console
$ algc conformance/0067-undefined-property.a24
Uncaught: Undefined property 'Nope'.
exit: 70
```

### 12.4 Inheritance

**[CLS-011]**  `class D (B)` makes `D` inherit `B`'s fields and methods. A
method of the same name overrides the inherited one.

##### conformance/0068-inheritance.a24

```algol24
class A;
begin
    constructor Init (); begin end
    function Who ();     begin Exit 'A'; end
    function Shared ();  begin Exit 'from A'; end
end

class B (A);
begin
    // CLS-011: a method of the same name overrides the inherited one.
    function Who ();       begin Exit 'B'; end
    function CallSuper (); begin Exit super.Who (); end
end

class C (B);
begin
    function Who (); begin Exit 'C'; end
end

// CLS-011: inherited methods are reachable, and overrides win.
WriteLn (B ().Shared ());
WriteLn (A ().Who ());
WriteLn (B ().Who ());
WriteLn (C ().Who ());

// CLS-012: super binds to the class that DECLARED the calling method, not to
// the runtime class.  CallSuper is declared in B, so super is A -- and it is
// still A when the receiver is a C.
WriteLn (B ().CallSuper ());
WriteLn (C ().CallSuper ());
```

```console
$ algc conformance/0068-inheritance.a24
from A
A
B
C
A
A
```

**[CLS-012]**  `super.M()` calls the version above the class that declared the
calling method, not above the runtime class.

It binds to the class that **declared** the method, not to the runtime class
of `this`. A method in `B` calling `super.Who()` reaches `A`'s version even when
the receiver is a `C` below `B`.

**`super.M` read without calling it binds the parent's method to this
receiver**, exactly as `B.M` binds the receiver's own [CLS-011], and the search
starts in the same place. It is the only way a program can hold the
implementation an override replaced.

    conformance  0068-inheritance.a24

##### conformance/0150-super-as-a-value.a24

```algol24
class Animal;
begin
    constructor Init (); begin end
    function Speak (); begin Exit 'animal'; end
    function Name  (); begin Exit 'Animal'; end
end

class Dog (Animal);
begin
    constructor Init (); begin end
    function Speak (); begin Exit 'woof'; end

    function Both ();
    begin
        var Parent := super.Speak;

        Exit Parent () + ' and ' + Speak ();
    end

    function Held ();
    begin
        var M := super.Name;

        Exit M;
    end
end

var D := Dog ();

WriteLn (D.Both ());

// It survives being returned, so the binding is on the value and not on the
// method that made it.
WriteLn (D.Held () ());

// And it prints as a bound method does [TYP-012].
WriteLn (D.Held ());
```

```console
$ algc conformance/0150-super-as-a-value.a24
animal and woof
Animal
<fn Name>
```

**[CLS-013]**  A class may not inherit from itself: `A class can't inherit from
itself.`

    unit         Inherit From Self

##### refusals/0027-inherit-from-self.a24

```algol24

```

```console
$ algc refusals/0027-inherit-from-self.a24
```

**[CLS-014]**  A superclass must be a class, and is checked **where it is
declared** rather than where an instance is later built. Naming something that
is not a class is `'X' is not a class.`, beside the existing
`A class can't inherit from itself.` [CLS-013].

Naming a name that denotes nothing is `Undefined variable 'X'.`

The check fires at the declaration, so a program that never constructs the
class is still refused. It used to ask the superclass for `.ClassName` first,
which raised `Only instances have properties.` before the comparison meant to
reject it could run — a sentence naming neither the class, nor the superclass,
nor inheritance.

**A cycle counts as inheriting from itself.** `class A (B); class B (A);` ran
silently until classes were hoisted [DCL-006], leaving a superclass chain with
no end for method lookup to walk. It is refused with the same sentence the
direct case gives, because it is the same fault reached the long way round.

    unit         Inherit Not A Class

##### conformance/0112-inherit-from-a-non-class.a24

```algol24
var X := 1;

class C (X);
begin
end
```

```console
$ algc conformance/0112-inherit-from-a-non-class.a24
Uncaught: 'X' is not a class.
exit: 70
```

##### refusals/0047-inheritance-cycle.a24

```algol24
class A (B);
begin
end

class B (A);
begin
end
```

```console
$ algc refusals/0047-inheritance-cycle.a24
Uncaught: A class can't inherit from itself.
exit: 70
```

### 12.5 Objects

**[CLS-015]**  `object N;` declares a class having exactly one instance, reached
by the name itself. The instance is built on first use, so an object may refer
to another declared later in the file.

    unit         An Object Takes Visibility Sections

##### conformance/0069-objects.a24

```algol24
object Config;
var Name : String := 'config';
begin
    function Ask (); begin Exit Later.Value (); end
end

// The instance is built on FIRST USE, so an object may refer to another
// declared below it.
object Later;
begin
    function Value (); begin Exit 'from Later'; end
end

WriteLn (Config.Name);
WriteLn (Config.Ask ());

// Exactly one instance: two references are the same object.
var A := Config;
var B := Config;
WriteLn (A = B);
```

```console
$ algc conformance/0069-objects.a24
config
from Later
true
```

**[CLS-016]**  An object is not callable. `Config()` is `Can only call functions
and classes.`

##### conformance/0070-object-is-not-callable.a24

```algol24
object Config;
begin
    function Value (); begin Exit 1; end
end

WriteLn (Config.Value ());

WriteLn (Config ());
```

```console
$ algc conformance/0070-object-is-not-callable.a24
Uncaught: Can only call functions and classes.
1
exit: 70
```

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

**It exists to give a read-only view of internal state**, which nothing else
in the language could express. A field is public — readable **and writable** — or
private, meaning invisible [DCL-011]; there is no third state, so a `Stack`
written in Algol-24 could not protect its own count while showing it, and was
strictly worse than the built-in it imitates, whose `Length` cannot be assigned.

**Nothing is checked at run time**, and that is deliberate. Assignment is
refused by the checker where the receiver's type is known and reported nowhere
when it is not — exactly as `private:` is silent there [DCL-015]. Enforcing
visibility at run time would put a check on every property *access*, which is not
worth buying a boundary the rest of the language does not have.

**A parameter list would have nowhere to arrive from**, which is why the
declaration has none. Leaving the parentheses off is what says the member is
read rather than called.

##### conformance/0168-a-read-only-property.a24

```algol24
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

var S := Stack ();
WriteLn (S.Count, ' ', S.IsEmpty);

S.Push (10);
S.Push (20);
WriteLn (S.Count, ' ', S.IsEmpty);

// A property reduces to its declared type, so this is an Integer context.
var N : Integer := S.Count;
WriteLn (N + 1);

// An inherited property is still a property.
class Deque (Stack);
begin
    constructor Init (); begin super.Init (); end
end

var D : Deque := Deque ();
WriteLn (D.Count);
D.Push (1);
WriteLn (D.Count);

// A method still reads as the method it is [TYP-012] -- only a property is
// called by being read.
class Plain;
begin
    constructor Init (); begin end
    function Size (); begin Exit 7; end
end

WriteLn (Plain ().Size);
WriteLn (Plain ().Size ());

// Through an UNTYPED receiver the checker has no class to ask, so the
// assignment is not refused there -- it reaches the instance, which is closed
// [CLS-018] and answers for itself.
try
    var A : Any := Stack ();
    A.Count := 99;
except
    on e : String do WriteLn (e);
end
```

```console
$ algc conformance/0168-a-read-only-property.a24
0 true
2 false
3
0
1
<fn Size>
7
Undefined property 'Count'.
```

##### refusals/0168-assigning-to-a-property.a24

```algol24
class Stack;
var
private:
    Items : List;

begin
    constructor Init ();       begin this.Items := []; end
    property Count : Integer;  begin Exit Items.Length; end
end

var S : Stack := Stack ();

WriteLn (S.Count);

S.Count := 99;
```

```console
$ algc refusals/0168-assigning-to-a-property.a24
Uncaught: 'Count' is a property of Stack and cannot be assigned.
exit: 70
```

**[CLS-018]**  An instance is **closed**: assignment reaches only a field the
class declared. `B.Undeclared := 1` is `Undefined property 'Undeclared'.`

##### conformance/0169-an-instance-is-closed.a24

```algol24
class Box;
var Items : List;
begin
    constructor Init (); begin this.Items := []; end
end

var B : Any := Box ();

// A declared field is assignable.
B.Items := [1, 2];
WriteLn (B.Items.Length);

// One the class does not declare is not.
try
    B.Undeclared := 1;
except
    on e : String do WriteLn (e);
end

// And assigning over a METHOD is refused on the same terms -- a method is not a
// field either.
class WithMethod;
begin
    constructor Init (); begin end
    function Size (); begin Exit 7; end
end

try
    var W : Any := WithMethod ();
    W.Size := 1;
except
    on e : String do WriteLn (e);
end
```

```console
$ algc conformance/0169-an-instance-is-closed.a24
2
Undefined property 'Undeclared'.
Undefined property 'Size'.
```

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

##### conformance/0071-enumerations.a24

```algol24
type Colour = (RED, GREEN, BLUE);
type Fruit  = (APPLE, PEAR);

// ENU-002: each member binds as a BARE NAME and is also reachable qualified.
// Both spellings denote the same interned object.
WriteLn (RED);
WriteLn (Colour.RED);
WriteLn (RED = Colour.RED);

// ENU-007: a member renders as its bare name.
WriteLn (Str (BLUE));

// ENU-006: 'is' is true for the member's own type and false for every other.
WriteLn (RED is Colour);
WriteLn (RED is Fruit);
WriteLn (APPLE is Fruit);

// ENU-005: members compare by IDENTITY.  A member is never equal to a member
// of another enumeration, whatever they are called, and not to its own name as
// text.
WriteLn (RED = GREEN);
WriteLn (RED = APPLE);
WriteLn (RED = 'RED');

// ENU-001: the members are named in order, and the declaration is the only
// place that order appears.
var Seen := '';
for var C in [RED, GREEN, BLUE] do Seen := Seen + Str (C) + ' ';
WriteLn (Seen);
```

```console
$ algc conformance/0071-enumerations.a24
RED
RED
true
BLUE
true
false
true
false
false
false
RED GREEN BLUE 
```

**[ENU-002]**  Each member is bound as a **bare name** in the enclosing scope and
is also reachable qualified as `Type.Member`. Both spellings denote the **same
interned object**, so `RED = Color.RED` is true.

    unit         Both Spellings Of An Enum Member Type As The Enum
    conformance  0071-enumerations.a24

**[ENU-003]**  Two enumerations **may** share a member name. Declaring
`type First = (A, B);` and `type Second = (A, C);` in one scope is accepted, and
neither declaration is affected by the other.

The declaration used to be refused with `'A' is already defined.`, so adding
a member to one enumeration could break an unrelated one elsewhere in the
program — and `First.A`, which is unambiguous, never got a chance to help.

    conformance  0123-enumerations-may-share-member-names.a24

**[ENU-011]**  A **bare** member name bound by more than one enumeration in
scope is ambiguous, and using it is refused with
`'A' is ambiguous: First or Second.` The qualified form [ENU-002] resolves it:
`First.A` and `Second.A` are two different members.

A bare name bound by only one enumeration in scope is unambiguous and needs no
qualifier, which is the ordinary case and the reason members bind bare at all.

**The refusal belongs to the use, not to the declaration.** Two enumerations
that never meet an ambiguous use coexist without complaint, and a program is
told about a name only where it actually cannot be resolved.

The ambiguous name is **removed** from the scope's bindings rather than left
in it holding one of the two, so a bare read cannot quietly find one. The
qualified form is unaffected: it reaches the member through the enumeration
rather than through that binding.

##### conformance/0123-enumerations-may-share-member-names.a24

```algol24
type First  = (A, B);
type Second = (A, C);

// Qualified: unambiguous, and they are different members of different types.
WriteLn (First.A);
WriteLn (Second.A);
WriteLn (First.A = Second.A);

// Bare, and bound by only one enumeration each.  A shared name does not make
// its neighbors ambiguous [ENU-003].
WriteLn (B);
WriteLn (C);

// Bare 'A' is the error, and it is the LAST thing that happens: everything
// above ran.  A name is refused where it cannot be resolved, not where it was
// declared.
WriteLn (A);
```

```console
$ algc conformance/0123-enumerations-may-share-member-names.a24
Uncaught: 'A' is ambiguous: First or Second.
A
A
false
B
C
exit: 70
```

**[ENU-004]**  Naming a member the type does not have is `Undefined enum member
'X'.`

##### conformance/0072-unknown-enum-member.a24

```algol24
type Colour = (RED, GREEN);

WriteLn (Colour.RED);

WriteLn (Colour.Nope);
```

```console
$ algc conformance/0072-unknown-enum-member.a24
Uncaught: Undefined enum member 'Nope'.
RED
exit: 70
```

### 13.2 Values

**[ENU-005]**  Members compare by **identity** [VAL-011]. A member of one
enumeration is never equal to a member of another, whatever they are called.

    unit         An Enum Member Does Not Satisfy Another Enum
    conformance  0071-enumerations.a24

**[ENU-006]**  `M is T` is true for the member's own type and false for every
other.

    unit         An Enum Type Name Types As Itself
    conformance  0071-enumerations.a24

**[ENU-007]**  A member renders as its bare name: `Str(RED)` is `RED`.

    conformance  0071-enumerations.a24

**[ENU-008]**  Members are **not ordered**. `RED < GREEN` is `Operands must be
numbers.`

A program that needs an order compares ordinals [ENU-010]. The operators are
left alone deliberately: `<` on two members would have to mean position, and
position is exactly the property [ENU-009] shows to be a trap when it acts
implicitly.

##### conformance/0073-enum-members-are-not-ordered.a24

```algol24
type Colour = (RED, GREEN, BLUE);

WriteLn (RED = RED);
WriteLn (RED <> GREEN);

WriteLn (RED < GREEN);
```

```console
$ algc conformance/0073-enum-members-are-not-ordered.a24
Uncaught: Operands must be numbers.
true
true
exit: 70
```

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

**The discipline it asks for: put the absent, off or zero member first.** The
position is part of the declaration's meaning, so reordering members changes the
truth of every condition written over them — in the same way, and for the same
reason, that reordering a `case`'s arms changes which one runs. The position is
readable [ENU-010], so nothing here is hidden.

This compiler's own enumerations already follow the convention: `FUN_NONE`
and `CLASS_NONE` are the first members of `FunctionType` and `ClassType`.

##### conformance/0074-enum-truthiness.a24

```algol24
type Colour = (RED, GREEN, BLUE);

// The first member is falsey; every later member is truthy.
if RED   then WriteLn ('RED truthy');   else WriteLn ('RED falsey');
if GREEN then WriteLn ('GREEN truthy'); else WriteLn ('GREEN falsey');
if BLUE  then WriteLn ('BLUE truthy');  else WriteLn ('BLUE falsey');

// Which is the point of the rule: a program may declare its own two-valued
// types and use them directly in a condition, with no comparison and no
// conversion.
type Flag   = (Off, On);
type Answer = (No, Yes);

procedure Report (Label, V);
begin
    if V then WriteLn (Label + ' is on');
    else WriteLn (Label + ' is off');
end

Report ('Off   ', Off);
Report ('On    ', On);
Report ('No    ', No);
Report ('Yes   ', Yes);

// The discipline: the position is part of the declaration's meaning.  These
// two enumerations differ only in the order of their members, and every
// condition written over them differs with it.
type Forward  = (Zero, One);
type Backward = (One2, Zero2);

Report ('Zero  ', Zero);
Report ('Zero2 ', Zero2);
```

```console
$ algc conformance/0074-enum-truthiness.a24
RED falsey
GREEN truthy
BLUE truthy
Off    is off
On     is on
No     is off
Yes    is on
Zero   is off
Zero2  is on
```

**[ENU-010]**  A member answers `Ordinal`, its **zero-based position** in the
declaration. `RED.Ordinal` is 0 and `BLUE.Ordinal` is 2. It answers no other
property.

The ordinal is what a program needs to order members [ENU-008], to index an
array by one, or to write one out and read it back. It also governs truthiness
[ENU-009], and a program could once discover that only by testing a member for
truth.

##### conformance/0113-enum-ordinal.a24

```algol24
type Colour = (RED, GREEN, BLUE);

WriteLn (RED.Ordinal);
WriteLn (GREEN.Ordinal);
WriteLn (BLUE.Ordinal);
WriteLn (RED.Ordinal is Integer);

// The position GOVERNS behavior: truthiness reads it, so the first member
// of every enumeration is falsey [ENU-009].  A program could once discover
// that only by testing a member for truth.
if RED then WriteLn ('RED truthy'); else WriteLn ('RED falsey');
WriteLn (RED.Ordinal = 0);

// It is also what a program needs to put members in an order, which they do
// not have themselves [ENU-008].
WriteLn (RED.Ordinal < BLUE.Ordinal);
```

```console
$ algc conformance/0113-enum-ordinal.a24
0
1
2
true
RED falsey
true
true
```

---

## 14. Collections

**This chapter describes the collections as built-ins, which is what they
are.** A second set written in Algol-24 may one day stand **beside** them
rather than replace them, in which case this chapter keeps describing the
natives and the library's behavior is documented with the library.

**`Array` is what a library implementation would be built on**, and it stays:
nothing in the language can express a fixed-size, constant-time store of
arbitrary values. The literal forms `[…]` and `[:]` also stay, and they are why
`List` and `Map` keep their names in the core whatever a library calls its
own.

**The rules below are therefore expected to leave this specification**, and
their conformance cases with them. That is not a failure of either: a rule that
stops describing the *language* because its subject became a *library* has been
retired, not falsified, and the cases that pinned it become the unit tests of
the unit that replaces it. They are worth writing now precisely because they are
the behavioral target that unit has to meet.

One rule in this chapter is **not** provisional in that way. [COL-007]
specifies insertion order for every collection, including `Set` and `Map`, and
any replacement must reproduce it — it was specified rather than left to the
representation because both processors must agree, and a unit is a third
implementation with the same obligation.

### 14.1 Construction

**[COL-001]**  A bracketed list of values is a `List`, and `[]` is an empty one.
A bracketed list of `key : value` pairs is a `Map`, and `[:]` is an empty one.

##### conformance/0075-collection-construction.a24

```algol24
// COL-001: a bracketed list of values is a List; of key : value pairs, a Map.
var L := [1, 2, 3];
var M := [1 : 'one', 2 : 'two'];
WriteLn (L is List);
WriteLn (M is Map);
WriteLn (L.Length);
WriteLn (M.Length);

// And the empty forms are distinguished by the colon.
WriteLn ([] is List);
WriteLn ([:] is Map);
WriteLn ([].Length);
WriteLn ([:].Length);

// COL-002: the constructors.
WriteLn (List () is List);
WriteLn (Set () is Set);
WriteLn (Stack () is Stack);
WriteLn (Map () is Map);
WriteLn (Array (3) is Array);
WriteLn (Array (3).Length);

// Set(L) builds a Set from a collection, keeping each value once.
WriteLn (Set ([1, 1, 2]).Length);
```

```console
$ algc conformance/0075-collection-construction.a24
true
true
3
2
true
true
0
0
true
true
true
true
true
3
2
```

##### conformance/0143-a-large-computed-literal.a24

```algol24
var N := 7;
var Big := [N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N];

WriteLn (Big.Length);
WriteLn (Big[0] + Big[149]);
```

```console
$ algc conformance/0143-a-large-computed-literal.a24
150
14
```

**[COL-002]**  `List()`, `Set()`, `Stack()` and `Map()` construct empty
collections, `Set(L)` builds a Set from a collection, and `Array(N)` an Array of
`N` elements.

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

This table is checked against the interpreter by `spec/spec.sh`, which asks
`spec/members.a24` which members each kind actually answers for. A matrix
transcribed into a specification and checked by nobody is the most rot-prone
thing this document can hold.

##### conformance/0076-collection-members.a24

```algol24
var L := [3, 1, 2];
WriteLn (Str (L.Length) + ' ' + Str (L.IsEmpty) + ' ' + Str (L.Contains (1)));
WriteLn (L.Get (0));
L.Add (9);      WriteLn (L.Length);
L.Insert (0, 0); WriteLn (L.Get (0));
WriteLn (L.IndexOf (9));
L.RemoveAt (0); WriteLn (L.Get (0));

var S := Set ();
S.Add (1); S.Add (2);
WriteLn (Str (S.Length) + ' ' + Str (S.Contains (1)));
WriteLn (S.ToList () is List);
S.Remove (1);   WriteLn (S.Length);

var K := Stack ();
K.Push (1); K.Push (2);
WriteLn (Str (K.Peek ()) + ' ' + Str (K.Pop ()) + ' ' + Str (K.Length));

var A := Array (3);
A.Set (0, 'x'); WriteLn (A.Get (0));
A.Fill ('y');   WriteLn (Str (A.Get (0)) + Str (A.Get (2)));

var M := Map ();
M.Put (1, 'one');
WriteLn (Str (M.Get (1)) + ' ' + Str (M.Contains (1)));
WriteLn (Str (M.Keys ().Length) + ' ' + Str (M.Values ().Length));
M.Remove (1);   WriteLn (M.Length);

// COL-004: a List has no Remove.  Removing a value means saying WHICH one,
// because a List may hold the same value more than once.
var Dup := [7, 8, 7];
Dup.RemoveAt (Dup.IndexOf (7));
WriteLn (Str (Dup.Length) + ' ' + Str (Dup.Get (0)) + Str (Dup.Get (1)));
```

```console
$ algc conformance/0076-collection-members.a24
3 false true
3
4
0
4
3
2 true
true
1
2 2 1
x
yy
one true
1 1
0
2 87
```

**[COL-004]**  A `List` has **no `Remove`**. Removing a value from a List
means finding it with `IndexOf` and passing that to `RemoveAt`, while a `Set` and
a `Map` remove by value and by key directly.

The asymmetry has a reason, and it is not an oversight. A List may hold the
same value more than once, so "remove this value" has no single meaning — the
first, the last, or all of them — while a Set holds each value once and a Map
each key once, so for those it has exactly one. Making a program write `IndexOf`
and `RemoveAt` is making it say which it meant.

    conformance  0076-collection-members.a24

**[COL-005]**  A member a kind does not have is `Undefined property 'X'.`

A member the kind *does* have is a value before it is a call, as a method of
an instance is [CLS-011]: `L.Sort` reads as something callable. That is also the
only way to ask whether a kind has a member without arranging arguments for it,
which is how `spec/members.a24` — the source [COL-003]'s matrix is checked
against — probes for one.

##### conformance/0077-undefined-collection-member.a24

```algol24
var K := Stack ();
K.Push (1);
WriteLn (K.Peek ());

WriteLn (K.Get (0));
```

```console
$ algc conformance/0077-undefined-collection-member.a24
Uncaught: Undefined property 'Get'.
1
exit: 70
```

##### conformance/0144-a-collection-member-without-the-call.a24

```algol24
var L := [3, 1, 2];

var Sort := L.Sort;
Sort ();
WriteLn (L[0]);

var Add := L.Add;
Add (9);
WriteLn (L.Length);

// A member the kind does not have is refused on this path too [COL-005].
try
    var Nope := L.Push;
except
    on e : String do WriteLn (e);
end
```

```console
$ algc conformance/0144-a-collection-member-without-the-call.a24
1
4
Undefined property 'Push'.
```

**[COL-006]**  A collection member's name is matched **case-insensitively**,
as every name in the language is [SRC-011]. `L.Add(2)` and `L.add(2)` are the
same member.

The comparison literals in `ObjCollection`, `ObjFile` and `ObjBuffer` are
written **folded**, and the incoming member is folded to meet them. The
diagnostic still quotes the member as the program wrote it: `L.Zap` is
`Undefined property 'Zap'.`, not `'zap'`.

    conformance  0126-identifiers-are-case-insensitive.a24

### 14.3 Order

**[COL-007]**  Every collection iterates in **insertion order**, including
`Set` and `Map`. This is specified rather than left to the representation,
because both processors must produce the same output.

##### conformance/0078-collection-order.a24

```algol24
// COL-007: every collection iterates in INSERTION order, including Set and
// Map.  Inserted 3, 1, 2 -- so 3, 1, 2 comes back, not 1, 2, 3.
var L := [3, 1, 2];
var S := Set ([3, 1, 2]);
var M := [3 : 'c', 1 : 'a', 2 : 'b'];

procedure Walk (Label, C);
begin
    Write (Label);
    for var E in C do Write (Str (E) + ' ');
    WriteLn ('');
end

Walk ('List : ', L);
Walk ('Set  : ', S);
Walk ('Map  : ', M);

// COL-008: re-assigning an existing key keeps its ORIGINAL position.
M.Put (3, 'changed');
Walk ('Map  : ', M);
WriteLn (M.Get (3));

// A key not present goes to the end.
M.Put (9, 'new');
Walk ('Map  : ', M);

// COL-009: Keys() and Values() answer in that same order, element for element.
Walk ('Keys : ', M.Keys ());
Walk ('Vals : ', M.Values ());
```

```console
$ algc conformance/0078-collection-order.a24
List : 3 1 2 
Set  : 3 1 2 
Map  : 3 1 2 
Map  : 3 1 2 
changed
Map  : 3 1 2 9 
Keys : 3 1 2 9 
Vals : changed a b new 
```

**[COL-008]**  Re-assigning an existing Map key keeps the key's **original
position**. `Put` on a key already present replaces the value and does not move
it to the end.

    conformance  0078-collection-order.a24

**[COL-009]**  `Keys()` and `Values()` answer in that same order, so the two
correspond element for element.

    conformance  0078-collection-order.a24

### 14.4 Behavior

**[COL-010]**  A `Set` holds each value once. Adding a value it already has
leaves its length unchanged.

##### conformance/0079-collection-behavior.a24

```algol24
// COL-010: a Set holds each value once.
var S := Set ([1, 1, 2]);
WriteLn (S.Length);
S.Add (2);
WriteLn (S.Length);
S.Add (3);
WriteLn (S.Length);

// COL-011: Remove answers DIFFERENT KINDS OF THING by kind.
// A Map returns the value removed, and nil when the key was absent.
var M := [1 : 'one'];
WriteLn (M.Remove (1));
WriteLn (M.Remove (99));

// A Set returns whether there was anything to remove.
var T := Set ([1]);
WriteLn (T.Remove (1));
WriteLn (T.Remove (99));
```

```console
$ algc conformance/0079-collection-behavior.a24
2
2
3
one
nil
true
false
```

**[COL-011]**  `Remove` answers **different kinds of thing** by kind. A `Map`
returns the value removed, and `nil` when the key was absent. A `Set` returns
whether there was anything to remove.

Each answer is the useful one for its kind — a Map's removed value is worth
having, and a Set has nothing to hand back but whether it did anything — but the
two cannot be used interchangeably, and nothing in the call says which is coming.

    conformance  0079-collection-behavior.a24

**[COL-012]**  Membership — `Contains`, `in`, and Map key lookup — uses the
equality of [VAL-009], so a collection holding `1.0` contains `1`. See
[VAL-013].

A collection still compares by **identity**, and that is unchanged: two Lists
of the same contents are not equal, so `[1] in [[1]]` is false. Promotion is
between the numeric types, not a structural comparison.

    conformance  0127-membership-follows-equality.a24

**[COL-013]**  `Sort` orders in place and is **stable**. It orders numbers
against numbers and text against text; mixing them is `Can only sort numbers
against numbers, or text against text.`

**Text is ordered by [VAL-014]**, the same ordering `<` gives, rather than by
a second one that happens to agree. Comparing bytes would stop at an embedded
zero a String is entitled to hold, and matches only because UTF-8 is designed so
byte order follows code-point order.

##### conformance/0080-sort.a24

```algol24
// Sort orders in place -- the List itself is changed, and nothing is returned
// that has to be caught.
var N := [3, 1, 2];
N.Sort ();
for var E in N do Write (Str (E) + ' ');
WriteLn ('');

// It orders text against text as well as numbers against numbers.
var T := ['pear', 'apple', 'fig'];
T.Sort ();
for var E in T do Write (E + ' ');
WriteLn ('');

// An Array sorts too.
var A := Array (3);
A.Set (0, 3); A.Set (1, 1); A.Set (2, 2);
A.Sort ();
WriteLn (Str (A.Get (0)) + Str (A.Get (1)) + Str (A.Get (2)));

// Mixing them is refused.
var Mixed := [1, 'text'];
Mixed.Sort ();
```

```console
$ algc conformance/0080-sort.a24
Uncaught: Can only sort numbers against numbers, or text against text.
1 2 3 
apple fig pear 
123
exit: 70
```
    conformance  0166-text-is-ordered.a24

**[COL-014]**  Subscripting reads by position for a `List` and an `Array` and by
key for a `Map`. A `Set` has no positions and is refused with `Subscript target
should be an ordinal.`

##### conformance/0081-subscripting-by-kind.a24

```algol24
// By POSITION for a List and an Array.
var L := [10, 20, 30];
WriteLn (L[1]);

var A := Array (2);
A[0] := 'x';
WriteLn (A[0]);

// By KEY for a Map -- the subscript is the key, not a position.
var M := [7 : 'seven'];
WriteLn (M[7]);

// A String is subscriptable and not assignable, and says so -- a different
// complaint from the one a target without a subscript path gets.
try
    var T := 'abc';
    T[0] := 'x';
except
    on e : String do WriteLn (e);
end

// A Set has no positions.
var S := Set ([1, 2]);
WriteLn (S[0]);
```

```console
$ algc conformance/0081-subscripting-by-kind.a24
Uncaught: Subscript target should be an ordinal.
20
x
seven
Strings are immutable.
exit: 70
```

**[COL-015]**  An `Array` is fixed in size and does not grow on assignment — see
[TYP-008].

    conformance  0029-array-is-fixed.a24

---

## 15. Modules

### 15.1 Importing

**[MOD-001]**  `uses` imports another file. A bare identifier names the file of
that name with `.a24` appended; a quoted string is a path.

```
UsesStmt = "uses" ( identifier | string_lit ) ";" .
```

##### conformance/0082-module-import.a24

```algol24
// MOD-001: a quoted string is a path, resolved beside this file first.
uses 'modules/Alpha';

// MOD-005: a module exports its top-level declarations...
WriteLn (OnlyAlpha ());

// MOD-010: ...and an exported name may be qualified by its unit.  The
// qualifier is resolved statically as a unit, not evaluated as a value.
WriteLn (Alpha.OnlyAlpha ());
WriteLn (Alpha.Shared ());

// MOD-006: 'private' at the top level of a module hides a single declaration.
// Alpha's Hidden is not reachable here -- see 0084 for the diagnostic.
WriteLn (OnlyAlpha () = Alpha.OnlyAlpha ());
```

```console
$ algc conformance/0082-module-import.a24
only in Alpha
only in Alpha
from Alpha
true
```

**[MOD-002]**  A module name is the one place [SRC-011] does **not** reach.
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

    conformance  0082-module-import.a24

**[MOD-003]**  A module is loaded and executed **once**, keyed by its resolved
path, however many files import it. A second import of the same file sees the
names without re-running the body.

##### conformance/0083-module-runs-once.a24

```algol24
uses 'modules/Counted';
uses 'modules/AlsoUsesCounted';

WriteLn (CountedName ());
WriteLn (Reach ());
```

```console
$ algc conformance/0083-module-runs-once.a24
Counted body ran
from Counted
from Counted
```

**[MOD-004]**  A file may open with `unit N;`. If present, `N` must match the
file's own name: `Unit 'Wrong' must match its file name 'Mismatch'.`

##### refusals/0029-unit-name-must-match-the-file.a24

```algol24
uses 'conformance/modules/Mismatch';

WriteLn (W ());
```

```console
$ algc refusals/0029-unit-name-must-match-the-file.a24
Uncaught: Unit 'Wrong' must match its file name 'Mismatch'.
[ERROR] refusals/0029-unit-name-must-match-the-file.a24: Unit 'Wrong' must match its file name 'Mismatch'.
[ERROR] 4 | unit Wrong;
[ERROR]   |      ^^^^^
exit: 70
```

### 15.2 Exports

**[MOD-005]**  A module exports its top-level declarations, except those marked
`private`.

    conformance  0082-module-import.a24

**[MOD-006]**  At the top level of a module, `private` precedes a **single
declaration** and hides it. It is not a section marker there, unlike inside a
class [DCL-011].

    unit         Module Private Is Not A Section Marker
    conformance  0082-module-import.a24

**[MOD-007]**  A private name is invisible to an importer both bare and
qualified. Qualified, it is `Undefined name 'Hidden' in unit 'Mid'.`

##### conformance/0084-module-private.a24

```algol24
uses 'modules/Alpha';

WriteLn (Alpha.OnlyAlpha ());

WriteLn (Alpha.Hidden ());
```

```console
$ algc conformance/0084-module-private.a24
Uncaught: Undefined name 'Hidden' in unit 'Alpha'.
only in Alpha
exit: 70
```

**[MOD-008]**  Two imported modules **may** export one name. Importing both is
accepted, and neither module is affected by the other.

The import used to be refused with `'Clash' is already defined; mark it
private in one of the modules.` — advice to edit a module because of what some
other module, possibly written by someone else, happens to export.

    conformance  0124-modules-may-share-exported-names.a24

**[MOD-013]**  A **bare** name exported by more than one imported module is
ambiguous, and using it is refused with
`'Shared' is ambiguous: Alpha or Beta.` The qualifier [MOD-010] resolves it:
`Alpha.Shared()` and `Beta.Shared()` are two different functions.

A bare name exported by only one imported module is unambiguous and needs no
qualifier, which is the ordinary case.

**The refusal belongs to the use, not to the import.** Two modules that
export a common name and are never used ambiguously coexist without complaint,
and a program is told about a name only where it actually cannot be resolved.

This is [ENU-011] applied to units, and for the same reason: a name that
cannot be resolved is a property of the *use*, not of the declaration. It also
removes the need for the advice the old diagnostic gave — a module should not
have to be edited because of what some other module, possibly written by someone
else, happens to export.

Detected where the name is **resolved through the imports**, which is the
only place the ambiguity is real. Importing one module twice is not a clash with
itself: the same environment appearing twice in the import list is still one
module.

##### conformance/0124-modules-may-share-exported-names.a24

```algol24
uses 'modules/Alpha';
uses 'modules/Beta';

WriteLn (Alpha.Shared ());
WriteLn (Beta.Shared ());

// Bare, and exported by only one module each [MOD-008].
WriteLn (OnlyAlpha ());
WriteLn (OnlyBeta ());

// Bare 'Shared' is the error, and it is the LAST thing that happens.
WriteLn (Shared ());
```

```console
$ algc conformance/0124-modules-may-share-exported-names.a24
Uncaught: 'Shared' is ambiguous: Alpha or Beta.
from Alpha
from Beta
only in Alpha
only in Beta
exit: 70
```

### 15.3 Visibility

**[MOD-009]**  `uses` is **not transitive**. If `A` imports `B` and `B`
imports `C`, then `A` does not see `C`'s names — `B` may use them, and `A` may
not. The diagnostic names the unit that would export it:

```
Undefined variable 'DeepName'. Unit 'Deep' exports it; this file has no 'uses' for it.
```

##### conformance/0085-uses-is-not-transitive.a24

```algol24
uses 'modules/Mid';

WriteLn (MidName ());
WriteLn (MidReachesDeep ());

// The diagnostic names the unit that would export it.
WriteLn (DeepName ());
```

```console
$ algc conformance/0085-uses-is-not-transitive.a24
Uncaught: Undefined variable 'DeepName'. Unit 'Deep' exports it; this file has no 'uses' for it.
from Mid
from Deep
exit: 70
```

**[MOD-010]**  An exported name may be qualified by its unit — `Mid.MidName()` —
and the qualifier is resolved statically as a unit rather than evaluated as a
value.

    conformance  0082-module-import.a24

**[MOD-011]**  `System` is the unit of the built-in functions. No file imports
it and every file may qualify against it: `System.Copy('abcdef', 0, 3)`.

##### conformance/0086-system-unit.a24

```algol24
WriteLn (System.Copy ('abcdef', 0, 3));
WriteLn (System.Length ('abc'));

// THE QUALIFIER NAMES WHAT IS STILL BUILT IN, AND ONLY THAT.  Max, Mod,
// Succ, Pred and Ord were all reachable here and are library functions now, so
// System.Max and System.Ord do not resolve.  Copy and Length remain, which is
// why the qualifier is shown with those two.

// The bare spellings are the same functions.
WriteLn (System.Copy ('abcdef', 0, 3) = Copy ('abcdef', 0, 3));
```

```console
$ algc conformance/0086-system-unit.a24
abc
3
true
```

### 15.4 Cycles

**[MOD-012]**  A cycle **between modules** works. `A` uses `B` and `B` uses
`A`, and both are loaded, both bodies run, and the functions of each are
callable — because a module is loaded once by resolved path [MOD-003], so the
second import finds the entry already made rather than descending again.

Cycles of three and more behave the same way.

##### conformance/0087-cycles-between-modules-work.a24

```algol24
uses 'modules/CycA';

WriteLn (AName ());
WriteLn (CycA.AName ());
```

```console
$ algc conformance/0087-cycles-between-modules-work.a24
from CycA
from CycA
```

**[MOD-014]**  A cycle **through the root file** — a module importing the file
that is being run — works as [MOD-012] does. The root is a module in its own
right: a `uses` naming it resolves to the file already loaded, and to the
environment already running.

The root's environment is registered **before its own body runs**, which is
exactly the position an ordinary module is in when a cycle reaches it. An
import-only node carries no statements, so the importer needs the environment to
exist by the time it links to it; a name is looked up when it is *used*, by which
time everything has loaded.

The root's own environment is the **globals**, not a copy, so the importer
sees the same bindings. It exports every name it declares.

The root used to be the one file never entered in the loader's map, so a
module importing it back parsed it a **second** time and the two copies did not
share their names — the root's body printed and then its own imported name was
undefined. Compiled, the duplicate refused with `Two modules named 'X' is not
supported by the C back end yet.`, which was the only known case of a valid
program having no compiled form.

##### conformance/0125-a-cycle-through-the-root.a24

```algol24
uses 'modules/BackRef';

WriteLn ('root body ran');

WriteLn (ModName ());
```

```console
$ algc conformance/0125-a-cycle-through-the-root.a24
root body ran
from the module
```

---

## 16. Built-in functions

### 16.1 The set

**[RT-001]**  Thirty names are built in. Twenty-seven are always
available:

```
Length  Copy  Pos   Str        Ord   Char  Val
ToUpper ToLower
Succ    Pred  Foreign
Mod     clock
List    Set   Stack Array      Map   Buffer
TextFile      FileExists
ParamCount    ParamStr
Write   WriteLn    Halt
```

The list is checked against the names the interpreter registers by
`spec/spec.sh`; Annex B is the index.

A built-in is called like any other subprogram, so a call to one checks its
argument count [EXP-011] and reports it the same way — the name existing is what
separates that failure from a reference to something undeclared.

**`Write` and `WriteLn` take any number of values**, rendered as `Str`
renders them [RT-019] and run together with nothing between them — so
`WriteLn ('ABC', 123)` writes `ABC123`, and `WriteLn (1, 2)` writes `12` rather
than `3`. `WriteLn ()` is the newline on its own, which is the same rule and not
a second form: rendering no values gives the empty string.

    conformance  0145-a-builtin-with-the-wrong-arity.a24

##### conformance/0159-write-takes-any-number-of-values.a24

```algol24
WriteLn ();
WriteLn ('ABC');
WriteLn ('ABC', 123);

// Every kind of value renders as Str renders it, so the one-value form and the
// many cannot disagree.
WriteLn ('a', 'b', 'c', 1, 2.5, True, Nil);

// Text concatenation and not addition: this writes '12', not '3'.
WriteLn (1, 2);

Write ('no');
Write ('newline', ' here');
WriteLn ();
```

```console
$ algc conformance/0159-write-takes-any-number-of-values.a24

ABC
ABC123
abc12.5truenil
12
nonewline here
```

##### conformance/0088-builtins.a24

```algol24
WriteLn (Length ('abc'));
WriteLn (Copy ('abcdef', 0, 3));
WriteLn (Pos ('abcdef', 'cd'));
WriteLn (Str (42));
WriteLn (Ord ('A'));
WriteLn (Char (65));
WriteLn (Val ('1.5'));
WriteLn (Mod (7, 3));
WriteLn (clock () is Double);

WriteLn (List () is List);
WriteLn (Set () is Set);
WriteLn (Stack () is Stack);
WriteLn (Array (1) is Array);
WriteLn (Map () is Map);
WriteLn (Buffer () is Buffer);
WriteLn (TextFile () is TextFile);
WriteLn (FileExists ('no-such-file-anywhere') = False);
WriteLn (ParamCount ());
WriteLn (Length (ParamStr (0)) > 0);
Write ('written');
WriteLn ('');

// Halt is shown under [RT-018] rather than here: calling it would end this
// program before the rest of the list was reached, and there is no way to ask
// whether it answers without calling it.
```

```console
$ algc conformance/0088-builtins.a24
3
abc
2
42
65
A
1.5
1
true
true
true
true
true
true
true
true
true
0
true
written
```

**[RT-002]**  The remaining three — `AssertTrue`, `AssertEqual` and `Fail` — are
registered **only while `--test` is running** [see 19]. Calling one outside a
test run is `Undefined variable 'AssertTrue'.`

##### refusals/0030-assert-outside-a-test-run.a24

```algol24
AssertTrue (True);
```

```console
$ algc refusals/0030-assert-outside-a-test-run.a24
Uncaught: Undefined variable 'AssertTrue'.
exit: 70
```

### 16.2 Text

**[RT-003]**  `Length(V)` measures **text**, in characters [SRC-004]. It takes
a String or a Char. Given a collection it is refused — `Length expects text; use
.Length for a collection.` — because a collection's count is a property
[COL-003] and the two are different questions.

It used to stringify whatever it was given, so `Length([10, 20, 30])` was
**12** — the length of the rendering — where `L.Length` is 3. The failure mode
was the bad one: a *plausible number* rather than an error, and the two are
never equal, since a List of *n* one-digit numbers renders as `3n` characters.

A program that means the rendering writes `Length(Str(L))`, which is what it
was getting by accident.

##### conformance/0115-length-refuses-a-collection.a24

```algol24
WriteLn (Length ('abc'));
WriteLn (Length ('a'));
WriteLn ([10, 20, 30].Length);

WriteLn (Length ([10, 20, 30]));
```

```console
$ algc conformance/0115-length-refuses-a-collection.a24
Uncaught: Length expects text; use .Length for a collection.
3
1
3
exit: 70
```

**[RT-017]**  A `String` answers `Length` as a **property**, its count of
characters: `'abc'.Length` is 3. This is the same count `Length('abc')` gives,
and the same spelling every collection uses [COL-003]. It is the **only** member
a `String` has — there are no string methods, and `IsEmpty` is a collection's
[COL-003], not text's. A `Char` has no members at all, because a one-character
literal is a `Char` and not a short `String` [TYP-003].

##### conformance/0114-string-length-property.a24

```algol24
var S := 'abc';

WriteLn (S.Length);
WriteLn (Length (S));
WriteLn (S.Length = Length (S));
WriteLn (''.Length);

// A String was already iterable and subscriptable; not answering for its own
// length was the odd one out.
WriteLn (S[0]);
for var C in S do Write (C);
WriteLn ('');

// A collection answers the same way.
WriteLn ([1, 2, 3].Length);
```

```console
$ algc conformance/0114-string-length-property.a24
3
3
true
0
a
abc
3
```

##### conformance/0180-a-strings-only-member.a24

```algol24
// Length is the ONE member a String has. It is a property, and there is no
// second one: a String is not an object with an interface, and asking it for
// one says so.

var S := 'hello';

WriteLn (S.Length);

try WriteLn (S.IsEmpty);    except on E : String do WriteLn (E); end
try WriteLn (S.ToUpper ()); except on E : String do WriteLn (E); end

// A one-character literal is a Char, and a Char is not a short String: it has
// no properties at all, so it answers the other message.
try WriteLn ('x'.Length);   except on E : String do WriteLn (E); end

// A number answers ToString the same way, and nothing else.
WriteLn ((5).ToString ());
try WriteLn ((5).Length);   except on E : String do WriteLn (E); end

// Only a collection answers both [COL-003].
WriteLn ([1, 2].Length, ' ', [1, 2].IsEmpty);
try WriteLn (Nil.IsEmpty);  except on E : String do WriteLn (E); end
```

```console
$ algc conformance/0180-a-strings-only-member.a24
5
Undefined property 'IsEmpty'.
Undefined property 'ToUpper'.
Only instances have properties.
5
Undefined property 'Length'.
2 false
Only instances have properties.
```

**[RT-004]**  `Copy(Text, Begin, Length)` takes a substring, counting from zero.
The length is clamped to what remains, so `Copy('abcdef', 3, 99)` is `def`. A
start outside the text is `Copy failed: Start -2 out of range 0..6.`

##### conformance/0089-text-builtins.a24

```algol24
// RT-004: Copy counts from zero, and the length is CLAMPED to what remains.

WriteLn (Copy ('abcdef', 0, 3));
WriteLn (Copy ('abcdef', 3, 3));
WriteLn (Copy ('abcdef', 3, 99));
WriteLn (Copy ('abcdef', 6, 1));

// RT-005: Pos is zero-based, and -1 when absent.
WriteLn (Pos ('abcdef', 'a'));
WriteLn (Pos ('abcdef', 'cd'));
WriteLn (Pos ('abcdef', 'z'));

// RT-007: Ord answers a code point as an Integer.
WriteLn (Ord ('A'));
WriteLn (Ord ('A') is Integer);
WriteLn (Ord (' '));
```

```console
$ algc conformance/0089-text-builtins.a24
abc
def
def

0
2
-1
65
true
32
```

**[RT-005]**  `Pos(Text, Part)` answers the zero-based index of `Part` within
`Text`, or **-1** when it is absent.

    conformance  0089-text-builtins.a24

**`Pos(Text, Part, Start)` searches from `Start` instead of from the
beginning**, and answers an index into **the whole text** rather than an offset
from `Start`. That is what lets the answer be handed straight back as the next
search's start, which is the scanning loop the third argument exists for:

```algol24
var At := Pos (S, ',');
while At >= 0 do
begin
    ...
    At := Pos (S, ',', At + 1);
end
```

`Start` counts **characters**, as every index in the language does, and is
**checked rather than clamped** — outside `0 … Length(Text)` it is
`Pos failed: Start 7 out of range 0..6.`, the message `Copy` gives for the same
mistake [RT-004]. Clamping would answer -1, which is the one answer that must
keep meaning *absent*; a start the caller computed wrongly would then be
indistinguishable from a part that is not there.

**This is not an overload in the sense [FUN-013] means.** One built-in answers
to the name and accepts two arguments or three, the way `Set` and `Buffer`
accept none or one [RT-001] — so no call to `Pos` selects among signatures at
run time, and none raises the `[WARN]` an overloaded name would [ERR-010].

**Both `Pos` and `Copy` render what they are given**, as `Length` does
[RT-003]: `Pos(42, '2')` is 1 and `Copy(42, 0, 1)` is `4`. Text is what any
value has, and a built-in that measures text takes any value.

##### conformance/0182-pos-from-a-start.a24

```algol24
var S := 'a,b,,c';

// The answer is an index into the WHOLE text, not an offset from Start, so it
// can be handed straight back as the next search's start.
WriteLn (Pos (S, ','));
WriteLn (Pos (S, ',', 0));
WriteLn (Pos (S, ',', 2));
WriteLn (Pos (S, ',', 4));

// Which is what makes the scanning loop the obvious one to write.
var At := Pos (S, ',');
while At >= 0 do
begin
    Write (At, ' ');
    At := Pos (S, ',', At + 1);
end
WriteLn ('');

// Absent from Start onwards is absent, on the same terms as the two-argument
// form [RT-005].
WriteLn (Pos (S, ',', 6));
WriteLn (Pos (S, 'z', 0));

// Start counts CHARACTERS, not bytes, as every index in the language does.
WriteLn (Pos ('café au lait', 'a', 4));

// A start outside the text is refused rather than answered -1, the way Copy
// refuses one [RT-004] -- it is a mistake in the caller's arithmetic, and -1
// would hide it among the ordinary absent answers.
try WriteLn (Pos (S, ',', 7));  except on E : String do WriteLn (E); end
try WriteLn (Pos (S, ',', -1)); except on E : String do WriteLn (E); end

// Two or three, and nothing else.
try WriteLn (Pos (S));          except on E : String do WriteLn (E); end
try WriteLn (Pos (S, ',', 0, 0)); except on E : String do WriteLn (E); end

// Pos renders what it is given, as Length does [RT-003] and as Copy does
// beside it: text is what any value has.
WriteLn (Pos (42, '2'));
WriteLn (Copy (42, 0, 1));
```

```console
$ algc conformance/0182-pos-from-a-start.a24
1
1
3
4
1 3 4 
-1
-1
5
Pos failed: Start 7 out of range 0..6.
Pos failed: Start -1 out of range 0..6.
Expected 2 or 3 arguments but got 1.
Expected 2 or 3 arguments but got 4.
1
4
```

**[RT-025]**  `ToUpper(T)` and `ToLower(T)` fold the case of text. They answer
**whichever of `Char` and `String` they were given** — case is not a reason to
widen, and `Str` is how widening is asked for [TYP-003] — and they take nothing
else, so `ToUpper(42)` is `ToUpper expects text.` rather than `42`.

**The fold is ASCII, `A`–`Z` against `a`–`z`, and stops there.** `ToUpper('café')`
is `CAFé`. This is the same reach every other case comparison in the language
has: identifiers fold case-insensitively [SRC-011] over the same range, and
Annex G.3 lowercases an identifier over the same range before escaping it. A
built-in that folded further would be the one thing in the language that
disagreed with the rest of it about what case means.

Text outside the range is **unchanged, not damaged**. Folding runs over bytes,
and every byte of a multi-byte character is `80` or above, which no fold
reaches — so a character the fold does not know is copied through whole.

##### conformance/0181-folding-case.a24

```algol24
WriteLn (ToUpper ('hello'));
WriteLn (ToLower ('WORLD'));
WriteLn (ToUpper ('Mixed Case 42!'));

// The fold is ASCII and stops there. Every byte of a multi-byte character is
// outside the range that folds, so the character survives rather than being
// mangled a byte at a time -- it simply does not change.
WriteLn (ToUpper ('café'));
WriteLn (Length (ToUpper ('café')));

// A Char folds to a Char, because case is not a reason to widen [TYP-003].
WriteLn (ToUpper ('a') is Char);
WriteLn (ToUpper ('a') = 'A');
WriteLn (ToUpper ('a') = Str ('A'));

// A String of one character stays a String, on the same rule.
WriteLn (ToUpper (Str ('a')) is String);

// Neither takes anything but text -- unlike Length, which measures whatever
// Str renders [RT-003].
try WriteLn (ToUpper (42));   except on E : String do WriteLn (E); end
try WriteLn (ToLower ([1]));  except on E : String do WriteLn (E); end

// The empty string folds to itself.
WriteLn ('[' + ToUpper ('') + ']');
```

```console
$ algc conformance/0181-folding-case.a24
HELLO
world
MIXED CASE 42!
CAFé
4
true
true
false
true
ToUpper expects text.
ToLower expects text.
[]
```

**[RT-006]**  `Str(V)` renders any value: an Integer bare, a Double always with
a point (`1.0`), a Boolean lowercase (`true`), `nil` as `nil`, a List as
`[10, 20, 30]`, a Map as `[1:2]`, an instance by its `ToString` [CLS-009], and
the two resources as `Buffer(4)` [RT-023] and `TextFile('name')` [RT-024].

**Any value means any value, and a `TextFile` was the one that was not.**
It had no case at all and answered `A value of object kind 14 has no text
form.` — a message naming an internal tag, to a program that has no way to know
what a kind 14 is. The Buffer beside it had always rendered, which is what made
it a defect in the implementation rather than a limit worth writing down.

##### conformance/0090-str.a24

```algol24
WriteLn (Str (42));
WriteLn (Str (1.0));
WriteLn (Str (1.5));
WriteLn (Str (True));
WriteLn (Str (False));
WriteLn (Str (nil));
WriteLn (Str ('text'));
WriteLn (Str ('c'));
WriteLn (Str ([10, 20, 30]));
WriteLn (Str ([1 : 2]));
WriteLn (Str ([]));

class Plain; begin constructor Init (); begin end end
WriteLn (Str (Plain ()));

class Pretty;
begin
    constructor Init (); begin end
    function ToString (); begin Exit 'rendered by ToString'; end
end
WriteLn (Str (Pretty ()));

type Colour = (RED, GREEN);
WriteLn (Str (RED));
```

```console
$ algc conformance/0090-str.a24
42
1.0
1.5
true
false
nil
text
c
[10, 20, 30]
[1:2]
[]
Plain instance
rendered by ToString
RED
```

##### conformance/0177-a-buffers-lifetime.a24

```algol24
procedure Show (What : String, Value : Any);
begin
    WriteLn (What + ' = ' + Str (Value));
end

// Construction.  Buffer(N) is N zero bytes, which is not empty.
var E := Buffer ();
Show ('Buffer () Length', E.Length);
Show ('Buffer () IsEmpty', E.IsEmpty);

var N := Buffer (4);
Show ('Buffer (4) Length', N.Length);
Show ('Buffer (4) IsEmpty', N.IsEmpty);
Show ('Buffer (4) first and last', Str (N[0]) + ', ' + Str (N[3]));

try var Bad := Buffer (-1); except on X : String do WriteLn ('  Buffer (-1): ' + X); end

// Resize truncates, or extends with zero bytes.
var R := Buffer ();
R.Append ('AB');
R.Resize (4);
Show ('grown to 4', Str (R[0]) + ', ' + Str (R[1]) + ', ' + Str (R[2]) + ', ' + Str (R[3]));
R.Resize (1);
Show ('cut to 1', R.Text);
try R.Resize (-1); except on X : String do WriteLn ('  Resize (-1): ' + X); end

// Str is the size, never the contents and never the capacity.
var S := Buffer ();
S.Append ('a longer run of bytes');
Show ('Str of a Buffer', S);

// Free, and what a freed Buffer answers.
S.Free ();
Show ('Str once freed', S);

try WriteLn (S.Length);     except on X : String do WriteLn ('  Length: ' + X); end
try WriteLn (S.Text);       except on X : String do WriteLn ('  Text: ' + X); end
try S.Append ('x');         except on X : String do WriteLn ('  Append: ' + X); end
try S.Resize (2);           except on X : String do WriteLn ('  Resize: ' + X); end
try WriteLn (S[0]);         except on X : String do WriteLn ('  subscript: ' + X); end

// Free is the exception: a second one is a no-op, so a handler may release on
// the way out without knowing how far the program got.
S.Free ();
WriteLn ('a second Free is a no-op');
```

```console
$ algc conformance/0177-a-buffers-lifetime.a24
Buffer () Length = 0
Buffer () IsEmpty = true
Buffer (4) Length = 4
Buffer (4) IsEmpty = false
Buffer (4) first and last = 0, 0
  Buffer (-1): A Buffer's size cannot be negative.
grown to 4 = 65, 66, 0, 0
cut to 1 = A
  Resize (-1): A Buffer's size cannot be negative.
Str of a Buffer = Buffer(21)
Str once freed = Buffer(freed)
  Length: That Buffer has been freed.
  Text: That Buffer has been freed.
  Append: That Buffer has been freed.
  Resize: That Buffer has been freed.
  subscript: That Buffer has been freed.
a second Free is a no-op
```

##### conformance/0178-a-text-files-state.a24

```algol24
// Nothing works before an Assign, except Close.
var F := TextFile ();

try F.Reset ();          except on X : String do WriteLn (X); end
try F.Rewrite ();        except on X : String do WriteLn (X); end
try F.Append ();         except on X : String do WriteLn (X); end
try F.Erase ();          except on X : String do WriteLn (X); end
try F.Rename ('t-b.txt'); except on X : String do WriteLn (X); end

// ... and nothing reads or writes before an open.
try WriteLn (F.Eof);     except on X : String do WriteLn (X); end
try WriteLn (F.ReadLn ()); except on X : String do WriteLn (X); end
try F.Write ('x');       except on X : String do WriteLn (X); end
try F.WriteLn ('x');     except on X : String do WriteLn (X); end
try F.Flush ();          except on X : String do WriteLn (X); end

F.Close ();
WriteLn ('Close before an open is not an error');

// A name must be a String.
try F.Assign (1); except on X : String do WriteLn (X); end

// Rewrite opens for writing.  A direction is exclusive: reading members fail.
F.Assign ('t-state.txt');
WriteLn ('assigned: ' + Str (F));

F.Rewrite ();
F.WriteLn ('one');
F.Write ('two');
F.Flush ();

WriteLn ('Eof while writing = ' + Str (F.Eof));
try WriteLn (F.ReadLn ()); except on X : String do WriteLn (X); end

// The refusals run the other way too: everything that opens, names, deletes or
// renames the file wants it closed first.
try F.Assign ('t-other.txt'); except on X : String do WriteLn (X); end
try F.Reset ();               except on X : String do WriteLn (X); end
try F.Rewrite ();             except on X : String do WriteLn (X); end
try F.Append ();              except on X : String do WriteLn (X); end
try F.Erase ();               except on X : String do WriteLn (X); end
try F.Rename ('t-other.txt'); except on X : String do WriteLn (X); end

F.Close ();

// Reset opens for reading, and now the writing members are the ones that fail.
F.Reset ();
try F.Write ('x'); except on X : String do WriteLn (X); end

WriteLn ('read: ' + F.ReadLn ());
WriteLn ('read: ' + F.ReadLn ());
WriteLn ('Eof after the last line = ' + Str (F.Eof));
try WriteLn (F.ReadLn ()); except on X : String do WriteLn (X); end
F.Close ();

// Rename moves the file and renames the handle with it.
F.Rename ('t-renamed.txt');
WriteLn ('t-state.txt exists = '   + Str (FileExists ('t-state.txt')));
WriteLn ('t-renamed.txt exists = ' + Str (FileExists ('t-renamed.txt')));
WriteLn ('the handle now = ' + Str (F));

F.Erase ();
WriteLn ('after Erase = ' + Str (FileExists ('t-renamed.txt')));
```

```console
$ algc conformance/0178-a-text-files-state.a24
Reset failed: no file has been assigned.
Rewrite failed: no file has been assigned.
Append failed: no file has been assigned.
Erase failed: no file has been assigned.
Rename failed: no file has been assigned.
Eof failed: the file is not open for reading.
ReadLn failed: the file is not open for reading.
Write failed: the file is not open for writing.
WriteLn failed: the file is not open for writing.
Flush failed: the file is not open for writing.
Close before an open is not an error
A file name must be a String.
assigned: TextFile('t-state.txt')
Eof while writing = true
ReadLn failed: the file is not open for reading.
Assign failed: the file is already open.
Reset failed: the file is already open.
Rewrite failed: the file is already open.
Append failed: the file is already open.
Erase failed: the file is already open.
Rename failed: the file is already open.
Write failed: the file is not open for writing.
read: one
read: two
Eof after the last line = true
ReadLn failed: at end of file.
t-state.txt exists = false
t-renamed.txt exists = true
the handle now = TextFile('t-renamed.txt')
after Erase = false
```

**[RT-007]**  `Ord(C)` answers the code point of a single character, as an
**Integer**. Anything longer is `Ord failed: 'ab' has no ordinal.`

    conformance  0089-text-builtins.a24

**[RT-008]**  `Char(N)` answers the character with code point `N`, over the
range of [LEX-025] — 0 … 10FFFF, excluding the surrogates. `Ord` and `Char` are
inverse across it.

`Char(0)` is legal here, and only the **literal** `#0` is refused
[LEX-032] — the scanner's own end-of-input sentinel is `Char(0)`.

**And everything that carries a character has to carry it, including the way
out.** `Write (Char (0))` raised interpreted and printed the byte compiled,
because the interpreter joined `Write`'s values through a `Buffer` and a Buffer
refuses to hand back `Text` when it holds a zero byte [RT-022]. A String carries
its own length and holds one perfectly well; it was the Buffer in the middle
that could not.

    conformance  0128-text-is-characters.a24

##### conformance/0179-a-zero-byte-survives-write.a24

```algol24
var Z := Char (0);

// It has an ordinal, and it is one character long.
WriteLn ('Ord      = ' + Str (Ord (Z)));
WriteLn ('Length   = ' + Str (Length (Str (Z))));

// A String holds it, because a String carries its own length rather than
// stopping at a terminator.
var Sandwiched := 'a' + Str (Z) + 'b';
WriteLn ('in a String = ' + Str (Length (Sandwiched)));
WriteLn ('  first  = ' + Str (Ord (Sandwiched[0])));
WriteLn ('  middle = ' + Str (Ord (Sandwiched[1])));
WriteLn ('  last   = ' + Str (Ord (Sandwiched[2])));

// AND IT SURVIVES Write [RT-015], which is the half that is easy to lose.
// Joining Write's values through a Buffer would not do: a Buffer refuses to
// hand back Text when it holds a zero byte [RT-022], so the byte has to travel
// as a String, which carries its own length.
Write (Sandwiched);
WriteLn ('');

// The many-value form of Write goes the same way, since it is the same join.
Write ('x', Z, 'y');
WriteLn ('');

// A Buffer still refuses, and should: that rule is about the Buffer, not about
// the character.
var B := Buffer ();
B.Append (Z);
WriteLn ('a Buffer holds it: ' + Str (B.Length));
try WriteLn (B.Text); except on E : String do WriteLn ('  but ' + E); end
```

```console
$ algc conformance/0179-a-zero-byte-survives-write.a24
Ord      = 0
Length   = 1
in a String = 3
  first  = 97
  middle = 0
  last   = 98
a^@b
x^@y
a Buffer holds it: 1
  but A Buffer holding a zero byte has no Text.
```
    refusal      0038-char-out-of-range.a24

### 16.3 Numeric

**[RT-009]**  `Val(S)` parses a number from text, answering an **Integer** where
the text has no point and a **Double** where it has one — reading the same
characters the literal rules do [LEX-015], [LEX-020]. Failure is `Val failed:
'abc' is not a number.`

Text that is neither — `'1e5'`, which no literal rule spells [LEX-022] — is
a Double, since only an integer literal yields an Integer.

**NOT YET IMPLEMENTED**, and `spec/DEFECTS.md` records it. `Val` delegates
to C's `strtod`, whose
idea of a number is not this language's, so five forms disagree with the rule
above: `'0x1F'` answers a Double where a hex literal is an Integer [LEX-016],
`'1_000'` is refused where a separator is permitted, and `' 42'`, `'.5'`, `'5.'`
and `'+7'` are all accepted where no literal spells them.

**AND `Val` IS THE SCANNER'S OWN NUMBER PARSER**, which is why the fix is not
where it looks. `Scanner.a24` reads every numeric literal with
`AddToken (TOKEN_NUMBER, Val (Digits))`, so whatever `Val` does *is* what a
literal means — the rule and the scanner cannot drift apart, because they are
one function. It also makes "compare `Val ('0x1F')` with the literal `0x1F`" a
**circular** test, which is the trap this rule sets for anyone fixing it.

**Rewriting it in Algol-24 was tried and withdrawn.** The literal forms came
out right, but the exponent did not: repeated multiplication and even
exponentiation by squaring drift, so `1.0E300` read back as
`1.0000000000000002E300`. A correctly-rounded decimal-to-binary conversion is a
hard numerical problem that `strtod` already solves, and getting the *acceptance*
right is not worth losing the *precision*.

**`Val` therefore has no static type**, and a checker cannot give it one: the
answer depends on the *content* of the text, not on its type. A typed
declaration needs a cast — `var D : Double := Val (S) as Double;` — which is
checked [VAL-007] and fails loudly when the text held the other kind. Declaring
`Val` to be Double, as this implementation once did, is a lie in both
directions: it refused `var I : Integer := Val ('42');`, which works.

##### conformance/0119-val.a24

```algol24
WriteLn (Val ('42'));
WriteLn (Val ('42') is Integer);
WriteLn (Val ('-7'));
WriteLn (Val ('1.5'));
WriteLn (Val ('1.5') is Double);
```

```console
$ algc conformance/0119-val.a24
42
true
-7
1.5
true
```
    defect       DEF-34-val-follows-strtod.a24

**[RT-010]**  ***Removed.*** `Max(A, B)` was a built-in
answering the greater of two numbers. It is not in the language and is not in a
library either: **nothing called it**, and Turbo Pascal never had it.

**Removing it deleted a special case rather than moving one.** `Max`
promoted, so its type came from its arguments rather than from a table, and
`TypeChecker.Reduce` carried a branch for exactly that. `Val` is now the only
built-in with no static return type.

**A removal needs a case as much as an addition does**, or nothing would
notice `Max` quietly coming back.

##### refusals/0178-max-was-removed.a24

```algol24
WriteLn (Max (1, 2));
```

```console
$ algc refusals/0178-max-was-removed.a24
Uncaught: Undefined variable 'Max'.
exit: 70
```

**[RT-011]**  `Mod(A, B)` answers the remainder, whose sign follows the
dividend: `Mod(-7, 3)` is `-1`. A zero divisor is `Mod failed: Division by
zero.`

##### conformance/0091-numeric-builtins.a24

```algol24
// RT-011: Mod's sign follows the DIVIDEND.

WriteLn (Mod (7, 3));
WriteLn (Mod (-7, 3));
WriteLn (Mod (7, -3));
WriteLn (Mod (6, 3));

// RT-012: clock() is a Double.
WriteLn (clock () is Double);
WriteLn (clock () > 0.0);
```

```console
$ algc conformance/0091-numeric-builtins.a24
1
-1
1
0
true
true
```

**[RT-012]**  `clock()` answers the seconds since the epoch as a **Double**, at
millisecond resolution.

    conformance  0091-numeric-builtins.a24

### 16.4 Environment

**[RT-013]**  `ParamStr(0)` is the program's own name and `ParamCount()` does
not count it, so a program run with no arguments reports zero.

**A RESOLVED path, not the bare word a shell passes.** A program found on
`PATH` is handed `algc` and nothing else, which is a name with nowhere to start
from — so the runtime asks the operating system where the executable really is
and answers that. It is still the program's own name; it is just the whole of
it. Without this, anything wanting a file shipped *beside* the binary cannot
find one, which is exactly what `--compile` needs when it copies the runtime
into the emitted directory.

##### conformance/0092-environment-builtins.a24

```algol24
// RT-013: ParamStr(0) is the program's own name, and ParamCount does not count
// it -- so a program run with no arguments reports zero.
WriteLn (ParamCount ());
WriteLn (Length (ParamStr (0)) > 0);

// RT-014: FileExists.
WriteLn (FileExists ('conformance/0092-environment-builtins.a24'));
WriteLn (FileExists ('no-such-file-anywhere.a24'));
```

```console
$ algc conformance/0092-environment-builtins.a24
0
true
true
false
```

**[RT-014]**  `FileExists(Name)` answers whether the named file exists.

    conformance  0092-environment-builtins.a24

**[RT-015]**  `Write` and `WriteLn` write their stringified values to standard
output, `WriteLn` following them with `#10` — always that byte, never the host's
line separator, so one program writes the same bytes everywhere.

They take **any number of values** [RT-001], run together with nothing between
them, so `WriteLn ('ABC', 123)` writes `ABC123` and `WriteLn ()` is the newline
on its own.

##### conformance/0093-write-and-writeln.a24

```algol24
Write ('a');
Write ('b');
WriteLn ('c');

WriteLn (42);
WriteLn (1.5);
WriteLn (True);
WriteLn (nil);
WriteLn ([1, 2]);

// An empty WriteLn is just the newline.
WriteLn ('');
WriteLn ('after the blank line');
```

```console
$ algc conformance/0093-write-and-writeln.a24
abc
42
1.5
true
nil
[1, 2]

after the blank line
```
    conformance  0159-write-takes-any-number-of-values.a24
    conformance  0179-a-zero-byte-survives-write.a24

**[RT-016]**  `ReadLn` on a `TextFile` splits on the same rule as the scanner
[SRC-006], [SRC-007]: a line ends at `#10`, which is **not** returned; a `#13`
immediately before it comes off with it; and any other `#13` is ordinary text
returned as part of the line.

A file whose only line endings are `#13` is therefore read as a single line
containing those bytes.

##### conformance/0008-readln-line-rule.a24

```algol24
procedure Write3 (Name : String, Body : String);
var
    F : TextFile;
begin
    F := TextFile();
    F.Assign (Name);
    F.Rewrite();
    F.Write (Body);
    F.Close();
end

procedure Show (Name : String);
var
    F : TextFile;
    N : Integer := 0;
begin
    F := TextFile();
    F.Assign (Name);
    F.Reset();
    while not F.Eof do
    begin
        var L := F.ReadLn();
        N := N + 1;
        WriteLn ('  line ' + Str(N) + ' length ' + Str(Length(L)));
    end
    F.Close();
    F.Assign (Name);
    F.Erase();
end

Write3 ('t-lf.txt',   'alpha' + #10 + 'beta' + #10);
Write3 ('t-crlf.txt', 'alpha' + #13 + #10 + 'beta' + #13 + #10);
Write3 ('t-cr.txt',   'alpha' + #13 + 'beta' + #13);

WriteLn ('LF:');   Show ('t-lf.txt');
WriteLn ('CRLF:'); Show ('t-crlf.txt');
WriteLn ('CR:');   Show ('t-cr.txt');
```

```console
$ algc conformance/0008-readln-line-rule.a24
LF:
  line 1 length 5
  line 2 length 4
CRLF:
  line 1 length 5
  line 2 length 4
CR:
  line 1 length 10
```

**[RT-019]**  A number answers `ToString`, which is `Str` by another spelling.
`5.ToString ()` is `'5'`.

**C#'s arrangement, not Java's.** `5.ToString ()` works because an Integer is
a type with members, not because a box wraps a primitive. There is no second
kind of thing that compares differently under `=`, and nothing to unbox.
Java's `int`/`Integer` duality — two things with almost the same name behaving
differently — is what this avoids, and is the same objection [TYP-014] makes to
a `Real` that converts.

**One rendering, so the two spellings cannot disagree.** `ToString` answers
exactly what `Str` does, including for a Double's shortest round-trip form and
for an Integer past the machine's width.

**It reads without being called**, like every other member [COL-005]:
`var T := 7.ToString;` binds something callable and prints `<fn ToString>`
[TYP-012].

##### conformance/0156-number-members.a24

```algol24
WriteLn (5.ToString ());
WriteLn (5.ToString () is String);
WriteLn (1.5.ToString ());
WriteLn ((0 - 42).ToString ());

// ONE rendering, so the two spellings cannot disagree -- including past the
// machine's width [LEX-018].
WriteLn ((9223372036854775807 * 2).ToString ());
WriteLn ((9223372036854775807 * 2).ToString () = Str (9223372036854775807 * 2));
WriteLn (1.5.ToString () = Str (1.5));

// It folds like every other member name [SRC-011].
WriteLn (5.tostring ());

// And it reads WITHOUT being called, like every other member [COL-005].
var T := 7.ToString;
WriteLn (T ());
WriteLn (T);

// A member a number does not have is refused, by either spelling.
try
    WriteLn (5.Nope ());
except
    on e : String do WriteLn (e);
end

try
    WriteLn (5.Nope);
except
    on e : String do WriteLn (e);
end
```

```console
$ algc conformance/0156-number-members.a24
5
true
1.5
-42
18446744073709551614
true
true
5
7
<fn ToString>
Undefined property 'Nope'.
Undefined property 'Nope'.
```

**[RT-020]**  `Succ(X)` and `Pred(X)` step an ordinal. A `Char` moves one code
point, an `Integer` moves one. `Succ ('a')` is `'b'` and `Pred (5)` is `4`.

Anything else is `Succ failed: 'X' has no ordinal.`, and a Char at the end of
the code-point range is `Succ failed: 'X' has no ordinal beyond it.`

**An enum member is not stepped, and the gap is honest rather than chosen.**
Stepping one is the most Pascal use of `Succ` there is, but a member carries its
type's *name* and its ordinal rather than a pointer to the type, so there is no
way from a member to the list it belongs to. That link is a change of its own.

**An Integer has no end to check** because it is unbounded [LEX-018]; a Char
does, stopping at U+10FFFF.

    conformance  0167-character-arithmetic.a24

**[RT-018]**  `Halt(N)` ends the program at once with status `N`. Nothing after
it runs, and no enclosing `except` sees it — it is not an exception.

**It is the only way a program can choose its own exit status.** Without it a
program that wants to exit non-zero has to `raise`, which prints `Uncaught: ` and
the raised value [ERR-008] — output the program did not ask for and cannot
suppress. `algc`'s own `--test` driver did exactly that, so a failing run printed
`Uncaught: Tests failed.` after the report, while the *compiled* form of the same
suite returned the status from `main` and printed nothing. That was the last line
on which the two processors disagreed.

**Buffered output is flushed first.** `stdout` is block-buffered when it is
not a terminal, so ending the process without flushing discards whatever the
program has written — a report that halted would print nothing at all when
piped.

The status is what the program passes. The host takes it modulo 256, as every
process exit status is; that is the operating system's rule, not this language's.

##### conformance/0134-halt.a24

```algol24
WriteLn ('before');

// Buffered output is flushed first.  stdout is block-buffered when it is not
// a terminal, so the line above would be lost without that -- and the output
// here is piped, so the fault would show rather than hide.
Halt (3);

WriteLn ('after');
```

```console
$ algc conformance/0134-halt.a24
before
exit: 3
```

### 16.5 Resources

**[RT-021]**  `Buffer` and `TextFile` build the two **resources** [TYP-001]:
values holding something the program must release rather than abandon. Neither
is a collection — neither answers `Contains`, and only a `Buffer` answers
`Length`. Their members are:

| | Buffer | TextFile |
| --- | :-: | :-: |
| `Length` `IsEmpty` `Text` `Address` | ● | |
| `PutInt` `GetInt` `Resize` `Free` | ● | |
| `Append` | ● | ● |
| `Eof` `Assign` `Reset` `Rewrite` | | ● |
| `ReadLn` `Write` `WriteLn` `Flush` | | ● |
| `Close` `Erase` `Rename` | | ● |

`Length`, `IsEmpty`, `Text`, `Address` and `Eof` are **properties**, written
without parentheses; the rest are methods. A member a resource does not have is
`Undefined property 'X'.`, as it is for a collection [COL-005].

This table is checked against the interpreter by `spec/spec.sh`, exactly as
[COL-003]'s is and for the same reason: a matrix transcribed into a
specification and checked by nobody is the most rot-prone thing this document
can hold.

**`Append` is the one name both answer to, and it means different things** —
a Buffer's takes a value and adds its bytes, a file's takes nothing and opens
for writing at the end. Only the receiver says which, which is why both
processors try the file's members and the Buffer's *before* the collections'.

**A resource is not an instance either**, so neither answers `ClassName`
[CLS-008] — the same answer a collection gives [TYP-009]. Both do render
[RT-006]: a Buffer as its size and a file as its name, spelled out in [RT-023]
and [RT-024].

##### conformance/0175-resource-members.a24

```algol24
procedure Has (Kind : String, Name : String, Present : Boolean);
begin
    if Present then WriteLn (Kind + '.' + Name);
    else            WriteLn (Kind + '.' + Name + ' -- no');
end

var B := Buffer ();
var F := TextFile ();

// A Buffer's four properties and five methods.
Has ('Buffer', 'Length',  B.Length  = 0);
Has ('Buffer', 'IsEmpty', B.IsEmpty);
Has ('Buffer', 'Text',    B.Text = '');
Has ('Buffer', 'Address', B.Address is Pointer);
Has ('Buffer', 'Append',  Str (B.Append) = '<fn Append>');
Has ('Buffer', 'PutInt',  Str (B.PutInt) = '<fn PutInt>');
Has ('Buffer', 'GetInt',  Str (B.GetInt) = '<fn GetInt>');
Has ('Buffer', 'Resize',  Str (B.Resize) = '<fn Resize>');
Has ('Buffer', 'Free',    Str (B.Free)   = '<fn Free>');

// A TextFile's one property and eleven methods.  Eof needs the file open, so
// it is asked for after a Rewrite rather than here.
Has ('TextFile', 'Assign',  Str (F.Assign)  = '<fn Assign>');
Has ('TextFile', 'Reset',   Str (F.Reset)   = '<fn Reset>');
Has ('TextFile', 'Rewrite', Str (F.Rewrite) = '<fn Rewrite>');
Has ('TextFile', 'Append',  Str (F.Append)  = '<fn Append>');
Has ('TextFile', 'ReadLn',  Str (F.ReadLn)  = '<fn ReadLn>');
Has ('TextFile', 'Write',   Str (F.Write)   = '<fn Write>');
Has ('TextFile', 'WriteLn', Str (F.WriteLn) = '<fn WriteLn>');
Has ('TextFile', 'Flush',   Str (F.Flush)   = '<fn Flush>');
Has ('TextFile', 'Close',   Str (F.Close)   = '<fn Close>');
Has ('TextFile', 'Erase',   Str (F.Erase)   = '<fn Erase>');
Has ('TextFile', 'Rename',  Str (F.Rename)  = '<fn Rename>');

F.Assign ('t-members.txt');
F.Rewrite ();
Has ('TextFile', 'Eof', F.Eof);
F.Close ();
F.Erase ();

// Neither is a collection, and neither is an instance.
procedure Absent (What : String);
begin
    WriteLn ('  ' + What);
end

try WriteLn (B.Contains);  except on E : String do Absent ('Buffer.Contains: '   + E); end
try WriteLn (F.Length);    except on E : String do Absent ('TextFile.Length: '   + E); end
try WriteLn (B.ClassName); except on E : String do Absent ('Buffer.ClassName: '  + E); end
try WriteLn (F.Eof);       except on E : String do Absent ('TextFile.Eof shut: ' + E); end

// Append is the one name both answer to, and only the receiver says which is
// meant: a Buffer's takes a value, a file's takes nothing.
var C := Buffer ();
C.Append ('bytes');
WriteLn ('Buffer.Append (X) -> ' + C.Text);

var G := TextFile ();
G.Assign ('t-append.txt');
G.Rewrite (); G.WriteLn ('first'); G.Close ();
G.Append ();  G.WriteLn ('second'); G.Close ();
G.Reset ();
WriteLn ('TextFile.Append () -> ' + G.ReadLn () + ', ' + G.ReadLn ());
G.Close ();
G.Erase ();
```

```console
$ algc conformance/0175-resource-members.a24
Buffer.Length
Buffer.IsEmpty
Buffer.Text
Buffer.Address
Buffer.Append
Buffer.PutInt
Buffer.GetInt
Buffer.Resize
Buffer.Free
TextFile.Assign
TextFile.Reset
TextFile.Rewrite
TextFile.Append
TextFile.ReadLn
TextFile.Write
TextFile.WriteLn
TextFile.Flush
TextFile.Close
TextFile.Erase
TextFile.Rename
TextFile.Eof
  Buffer.Contains: Undefined property 'Contains'.
  TextFile.Length: Undefined property 'Length'.
  Buffer.ClassName: Undefined property 'ClassName'.
  TextFile.Eof shut: Eof failed: the file is not open for reading.
Buffer.Append (X) -> bytes
TextFile.Append () -> first, second
```

**[RT-022]**  A `Buffer` holds **bytes**, and `Length` counts them rather than
characters: appending `'é'` makes it 2.

| | |
| --- | --- |
| `B[I]` | the byte at `I`, an Integer 0 … 255 |
| `B[I] := N` | writes one; outside that range, `A byte must be in 0..255.` |
| `Append (X)` | appends the bytes of `Str(X)` [RT-006] |
| `PutInt (At, N)` `GetInt (At)` | a signed four-byte little-endian Integer |
| `Text` | the bytes as a String |

An offset outside the buffer is `Offset I out of range 0..N.`, where `N` is the
**last offset a value of that width may start at** — `Length - 1` for a byte and
`Length - 4` for an Integer. An empty Buffer therefore says `0..-1`, and a
four-byte one asked for an Integer at 1 says `0..0`.

`Text` on a Buffer holding a zero byte is `A Buffer holding a zero byte has no
Text.`

**The message names the width by naming the last legal offset**, rather than
by stating it. `0..0` on a four-byte buffer says everything `0..3, minus three
for the width` would, in the terms the program already has.

**`Append` measures with the value's own length, never with a terminator.**
A String carries its length [G.2], which is what lets `Append (Char (0))` put a
zero byte in — and a Buffer that can *hold* one, through `Buffer (N)` and
`B[I] := 0`, but could not be handed one was the asymmetry. `strlen` was how it
got there.

**`Text` is the way to ask for the contents, and it is explicit.** A Buffer
is bytes, which may not be text at all; `Str` gives its size [RT-023].

##### conformance/0176-a-buffers-bytes.a24

```algol24
procedure Show (What : String, Value : Any);
begin
    WriteLn (What + ' = ' + Str (Value));
end

// Length is bytes.  'é' is one character and two bytes.
var B := Buffer ();
B.Append ('é');
Show ('Length of one e-acute', B.Length);
Show ('  its bytes', Str (B[0]) + ', ' + Str (B[1]));

// Append takes the text form of any value [RT-006].
var A := Buffer ();
A.Append ('n=');
A.Append (1);
A.Append (2.5);
A.Append (True);
A.Append ([1, 2]);
Show ('Append renders', A.Text);

// ... and measures with the value's own length, so a zero byte goes in.
var Z := Buffer ();
Z.Append (Char (0));
Show ('Append Char(0) Length', Z.Length);
Show ('  the byte', Z[0]);

// A zero byte has no text form, though.
try WriteLn (Z.Text); except on E : String do WriteLn ('  Text: ' + E); end

// The two forms of subscript.
var S := Buffer ();
S.Append ('AB');
Show ('S[0]', S[0]);
S[0] := 67;
Show ('after S[0] := 67', S.Text);

try S[0] := 256; except on E : String do WriteLn ('  256: ' + E); end
try S[0] := -1;  except on E : String do WriteLn ('  -1: '  + E); end

// An Integer is four bytes, signed and little-endian.
var I := Buffer ();
I.Append ('....');
I.PutInt (0, 1);
Show ('PutInt 1 bytes', Str (I[0]) + ', ' + Str (I[1]) + ', ' + Str (I[2]) + ', ' + Str (I[3]));
I.PutInt (0, -1);
Show ('PutInt -1 round trip', I.GetInt (0));

// The offset message names the last offset a value of that width may start at:
// Length - 1 for a byte, Length - 4 for an Integer.
var E4 := Buffer ();
try WriteLn (E4[0]);      except on E : String do WriteLn ('  empty, a byte: ' + E); end
try WriteLn (I.GetInt (1)); except on E : String do WriteLn ('  four bytes, an Integer at 1: ' + E); end
try WriteLn (I[9]);       except on E : String do WriteLn ('  four bytes, a byte at 9: ' + E); end
```

```console
$ algc conformance/0176-a-buffers-bytes.a24
Length of one e-acute = 2
  its bytes = 195, 169
Append renders = n=12.5true[1, 2]
Append Char(0) Length = 1
  the byte = 0
  Text: A Buffer holding a zero byte has no Text.
S[0] = 65
after S[0] := 67 = CB
  256: A byte must be in 0..255.
  -1: A byte must be in 0..255.
PutInt 1 bytes = 1, 0, 0, 0
PutInt -1 round trip = -1
  empty, a byte: Offset 0 out of range 0..-1.
  four bytes, an Integer at 1: Offset 1 out of range 0..0.
  four bytes, a byte at 9: Offset 9 out of range 0..3.
```

**[RT-023]**  A `Buffer` has an **explicit lifetime**. `Buffer ()` is empty and
`Buffer (N)` is `N` zero bytes; a negative size is `A Buffer's size cannot be
negative.` `Resize (N)` sets the length, truncating or extending with zero
bytes, and `Free ()` releases the bytes.

Every member of a freed Buffer is `That Buffer has been freed.` — except `Free`
itself, which is a no-op the second time.

`Str` of a Buffer is `Buffer(N)`, or `Buffer(freed)`.

**`Free` is the one member a freed Buffer still accepts**, which is the
bargain `Close` makes for a file [RT-024]: a handler can release on the way out
without knowing how far the program got.

**Its size, never its contents and never its capacity.** Capacity is a
function of allocation history, so printing it would make output depend on how a
buffer happened to grow — the non-determinism the fixed-point check exists to
catch. Contents are left out for a plainer reason: a compiler's Buffer holds
700 KB of bytes that may not be text.

**An address does not outlive the bytes** [TYP-017]. `Resize` may move them
and `Free` ends them.

    conformance  0177-a-buffers-lifetime.a24

**[RT-024]**  A `TextFile` is opened in one of three ways, and every member says
what it needed when it does not have it:

| | |
| --- | --- |
| `Assign (Name)` | names the file; a name must be a String |
| `Reset` | opens it for reading |
| `Rewrite` | opens it for writing, emptying it first |
| `Append` | opens it for writing at the end |
| `Close` `Erase` `Rename (Name)` | closes, deletes, renames |

`Eof` and `ReadLn` need it open for reading and `Write`, `WriteLn` and `Flush`
open for writing; otherwise the member fails with `X failed: the file is not
open for reading.` or `… for writing.` Every member but `Close` needs a name,
and without one fails with `X failed: no file has been assigned.` `ReadLn` past
the last line is `ReadLn failed: at end of file.`

The refusals run the other way too: **`Assign`, `Reset`, `Rewrite`, `Append`,
`Erase` and `Rename` all require the file to be closed**, and on an open one
fail with `X failed: the file is already open.` `Close` and the reading and
writing members are the only ones an open file accepts.

`Rename` renames the file **and the handle**: the name it was given is the name
the handle then has. `Str` of a `TextFile` is `TextFile('name')`, or
`TextFile()` before an `Assign`.

**`Eof` is TRUE on a file open for writing**, as it is in Turbo Pascal: the
position on an output file is always the end. It is a *position* query rather
than a report of a failed read, which is why a file open for reading keeps one
line of lookahead — `Eof` must answer *at* the end, which a line reader cannot
know without having looked.

**Every failure names the member that failed**, in one shape: the member, a
colon, and what it needed. That is what makes the messages worth quoting here —
there is one sentence pattern rather than eleven.

**`Close` on a file that is not open is not an error**, for the reason
`Free`'s second call is not [RT-023].

What `ReadLn` treats as a line is [RT-016], which is the scanner's rule
[SRC-006] rather than a second one.

    conformance  0178-a-text-files-state.a24

---

## 17. Program initialization and execution

### 17.1 A program

**[INI-001]**  A program is one file. Its top-level statements are executed in
the order they are written, and there is no distinguished entry point — no
`main`, and no statement that begins execution.

##### conformance/0094-program-order.a24

```algol24
WriteLn ('1');

var X := 2;
WriteLn (X);

begin
    WriteLn ('3, from a block in place');
end

// A counted for is a block too [STM-006], so this is deferred compiled for
// the same reason -- and it is the case that matters, because a bare block at
// the top level is rare and a counted loop is ordinary code.
for var I := 1; I <= 2; I := I + 1 do WriteLn ('3.' + Str (I) + ', from a loop in place');

procedure P (); begin WriteLn ('5, when called'); end

WriteLn ('4');
P ();
WriteLn ('6');
```

```console
$ algc conformance/0094-program-order.a24
1
2
3, from a block in place
3.1, from a loop in place
3.2, from a loop in place
4
5, when called
6
```

**[INI-002]**  A **variable or constant** takes effect when its statement is
reached, so a name is undefined above its declaration [DCL-016]. A **function or
class** is visible throughout the file wherever it is written [DCL-006].

A **variable** is still bound when its statement runs, and only a function or
a class is hoisted — `refusals/0033` pins the difference.

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

##### conformance/0095-module-init-order.a24

```algol24
// INI-003: a uses loads and runs its module AT THE POINT IT APPEARS, so root
// statements between two uses clauses run between the two module bodies.
WriteLn ('1 root');

uses 'modules/Alpha2';

WriteLn ('2 root');

uses 'modules/Gamma';

WriteLn ('3 root');

// INI-004: a module's imports are initialized before it, so its own body may
// use anything it imported -- and Alpha2 is not run a second time [MOD-003].
uses 'modules/UsesAlpha2';

WriteLn (Reach ());
```

```console
$ algc conformance/0095-module-init-order.a24
1 root
  Alpha body
2 root
  Gamma body
3 root
  UsesAlpha2 body, after its import
alpha
```

**[INI-004]**  A module is initialized once [MOD-003], and its imports are
initialized before it, so a module's own body may use anything it imported.

    conformance  0095-module-init-order.a24

**This follows from [INI-003] rather than needing its own mechanism**: a
module's `uses` clauses stand at the top of its body, so its initializer runs
them before its own statements.

### 17.3 Termination

**[INI-005]**  A program that reaches the end of its statements exits with
status **0**, and **only** such a program does. A run that never began — because
the file could not be read — is a failure and exits non-zero [INI-006].

**No case in `conformance/` covers the second half, and none can.** Every
case is run by handing `algc` a file that exists, so a run that never began is
not reachable from inside the corpus. It is checked by hand:

```
$ bootstrap/algc /no/such/file.a24 ; echo $?
algc: cannot open /no/such/file.a24
70
```

It used to print that line and exit **0**, so the driver reported a failure and
reported success at the same time.

    conformance  0094-program-order.a24

**[INI-006]**  Every failure the language reports exits with status **70** —
an uncaught `raise` [STM-021], and equally a scan, parse, resolution or type
error, which are reported before any statement runs.

##### conformance/0096-exit-status.a24

```algol24
WriteLn ('this program raises');

raise 'boom';
```

```console
$ algc conformance/0096-exit-status.a24
Uncaught: boom
this program raises
exit: 70
```

> **One status for every kind of failure** is deliberate rather than
> unconsidered. A caller wanting to tell a compile error from a runtime one
> reads the diagnostic; the alternative — a second status for failures found
> before execution — buys a little for tooling and costs every existing caller a
> change. What was *not* deliberate was a failure exiting **0**, and that is fixed.

### 17.4 Arguments

**[INI-007]**  A program reads its command line through `ParamCount` and
`ParamStr` [RT-013]. `ParamStr(0)` is the program's own name, and arguments
follow from index 1.

    conformance  0092-environment-builtins.a24

**[INI-008]**  A foreign call [FUN-014] is available only in a build that has
one. Two configurations exist:

| build | `external` |
| --- | --- |
| default | refused at the call: `Foreign calls are not available in this build: 'X' cannot be reached.` |
| with libffi | the call is made |

**The corpus runs the default build**, and this is what decides what it can
test: that an `external` declaration parses, checks and reaches the runtime in
both processors, and that the refusal reads the same either way. What a foreign
call *does* is outside the corpus, because it is outside this specification
[FUN-014].

**Both processors still agree within a build**, which is what the standing
rule asks. The configuration is a property of the runtime the two share, not a
difference between them.

**The default is the one without**, so that the bootstrap needs a C compiler
and nothing else — a claim about how `algc` is obtained from nothing, not about
what a program may link against.

    conformance  0174-a-foreign-call.a24

---

## 18. Errors

### 18.1 Phases

**[ERR-001]**  A program passes through five phases: **scan**, **parse**,
**resolve**, **check**, **run**. The first four complete over the whole program
— its imports included — before any statement is executed.

    conformance  0097-error-phases.a24

**[ERR-002]**  An error in any of the first four phases means **no statement
runs at all**. A program cannot produce output and then fail to compile.

##### conformance/0097-error-phases.a24

```algol24
WriteLn ('this line is never reached');
WriteLn ('nor this one');

var X : Integer := 'text';
```

```console
$ algc conformance/0097-error-phases.a24
Uncaught: Expected Integer, found String.
[ERROR] conformance/0097-error-phases.a24: Expected Integer, found String.
[ERROR] 4 | var X : Integer := 'text';
[ERROR]   |     ^
exit: 70
```

    refusal      0008-declared-type-constrains.a24

**[ERR-003]**  A runtime error occurs during execution. Statements before it
have run and their output stands.

##### conformance/0098-runtime-errors-follow-output.a24

```algol24
WriteLn ('this line runs');
WriteLn ('and so does this one');

var L := [1, 2];
WriteLn (L[9]);

WriteLn ('never reached');
```

```console
$ algc conformance/0098-runtime-errors-follow-output.a24
Uncaught: Index 9 out of range 0..1.
this line runs
and so does this one
exit: 70
```

### 18.2 Diagnostics

Diagnostics are part of the observable surface [1.2]; their wording and shape
are specified.

**[ERR-004]**  A **scan** error reads `[line N] Error: <message>` and carries no
source excerpt. Like every error in the first four phases it prevents execution
[ERR-002].

**That is the whole of the requirement.** This rule previously went on to say
the error is "recorded rather than raised: the scanner sets a flag and keeps the
message, and a driver must ask" — which describes how *this* implementation
happens to work, not what an implementation must do. A specification that
mandates a mechanism forbids a better one; what matters is that the error is
reported in the shape above and that no statement runs. The mechanism, and the
hazard that comes with it, are recorded in Annex G, G.1.

    unit         Scan Unrecognized Character Is Recorded

##### conformance/0099-scan-error-shape.a24

```algol24
WriteLn ('never reached');

@
```

```console
$ algc conformance/0099-scan-error-shape.a24
Uncaught: [line 3] Error: Unexpected character: @
exit: 70
```

**[ERR-005]**  A **parse** or **resolution** error prints the message and a
three-line excerpt naming the file, the line, and the offending token:

```
Uncaught: Expect variable name.
[ERROR] e.a24: Expect variable name.
[ERROR] 2 | var := 1;
[ERROR]   | ^^^
```

##### conformance/0100-parse-error-shape.a24

```algol24
var := 1;
```

```console
$ algc conformance/0100-parse-error-shape.a24
Uncaught: Expect variable name.
[ERROR] conformance/0100-parse-error-shape.a24: Expect variable name.
[ERROR] 1 | var := 1;
[ERROR]   | ^^^
exit: 70
```

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

**The caret names the declaration or the assignment, not the offending
value.** A literal carries no token, so there is nothing inside the initializer
to point at without giving every expression one — and the message already names
both types, which is what the caret would otherwise have to convey.

**This compounds with [ERR-002]:** a type error stops the program before any
statement runs, so there is no output to orient by either. The message is the
only information available, which is why it has to carry some.

##### conformance/0108-type-error-shape.a24

```algol24
var Count : Integer := 'text';
```

```console
$ algc conformance/0108-type-error-shape.a24
Uncaught: Expected Integer, found String.
[ERROR] conformance/0108-type-error-shape.a24: Expected Integer, found String.
[ERROR] 1 | var Count : Integer := 'text';
[ERROR]   |     ^^^^^
exit: 70
```

##### conformance/0109-type-error-untyped.a24

```algol24
function G (); begin Exit 1; end

var Y : Integer := G ();
```

```console
$ algc conformance/0109-type-error-untyped.a24
Uncaught: Expected Integer, found an untyped expression.
[ERROR] conformance/0109-type-error-untyped.a24: Expected Integer, found an untyped expression.
[ERROR] 3 | var Y : Integer := G ();
[ERROR]   |     ^
exit: 70
```

### 18.3 Catching

**[ERR-007]**  Only **runtime** errors are catchable, and they are caught as a
String carrying the diagnostic [STM-020].

##### conformance/0101-catching.a24

```algol24
// ERR-007: only RUNTIME errors are catchable, as a String carrying the
// diagnostic.
try
    WriteLn (1 / 0);
except
    on e : String do WriteLn ('caught: ' + e);
end

try
    var L := [1];
    WriteLn (L[9]);
except
    on e : String do WriteLn ('caught: ' + e);
end

// ERR-008: a try around a compile-phase error catches nothing, because those
// phases complete before the try is reached.  The nearest thing this file can
// show is that the handler is entered only for runtime faults -- a mistyped
// declaration inside the try would stop the whole program, which [STM-017]
// states and a refusal of its own shows.
WriteLn ('reached the end');
```

```console
$ algc conformance/0101-catching.a24
caught: Division by zero.
caught: Index 9 out of range 0..0.
reached the end
```

**[ERR-008]**  A `try` around a scan, parse, resolution or type error catches
nothing, because those phases complete before the `try` is reached. Wrapping a
mistyped declaration in a handler does not suppress it.

    conformance  0101-catching.a24

### 18.4 Status

**[ERR-009]**  Every failure exits with status **70**, whichever phase reported
it [INI-006].

A failure that never reaches a phase at all — a file that cannot be read — is
still a failure and must not exit 0 [INI-005].

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

**The wording is checked against what is printed**, by `spec/spec.sh` running
`spec/warning.a24` — the treatment the keyword table, Annex B and [COL-003]'s
matrix already get, and for the same reason. A message quoted in a specification
and checked by nobody is the most rot-prone thing this document can hold.

**It is not raised where a named argument decides the call** [EXP-013].
Naming the parameters identifies one signature, so nothing is left to select at
run time — the warning and its remedy arrived together, and a warning whose
remedy did not exist would point at nothing.

**A warning is not a refusal, and the boundary matters.** Refusal is for what
the C back end cannot express; a construct that is legal and merely costly gets
a warning instead, which is what keeps `<X> is not supported by the C back end
yet.` meaning only one thing.

**It is not part of a program's output**, and the corpus drops it from both
sides. The front end is shared, so the same warning appears when an interpreted
program *runs* and when a compiled one is *emitted* — different moments, so
comparing them would report a divergence where the two processors agree
completely. Dropped rather than suppressed: it is meant to be seen by whoever is
compiling, and only the comparison must not see it.

**It is silent on this compiler.** No top-level name in `compiler/*.a24` is
overloaded, so `algc` compiling itself raises none at all — which is the
evidence that it is a scalpel rather than noise.

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

`test` is not a keyword [LEX-011]; it is recognized here by the quoted name that
follows it, so a variable may still be called `test`.

**Either quoted form**, because the name is *text* and a one-character name is
an ordinary thing to write. `'X'` is a Char rather than a String [LEX-023], and
that distinction belongs to values rather than to a declaration naming itself.

##### conformance/0102-test-declaration.a24

```algol24
test 'This block does not run';
begin
    WriteLn ('a test body ran, which it must not have');
end

// 'test' is not a keyword [LEX-011] -- it is recognized here by the quoted
// name that follows it, so a variable may still be called 'test'.
var test := 7;
WriteLn (test);

WriteLn ('the program ran');
```

```console
$ algc conformance/0102-test-declaration.a24
7
the program ran
```

##### conformance/0116-one-character-test-name.a24

```algol24
test 'X';
begin
    AssertTrue (True);
end

test 'A longer name';
begin
    AssertTrue (True);
end
```

```console
$ algc --test conformance/0116-one-character-test-name.a24
[INFO] Running 2 tests...
[INFO] < conformance/0116-one-character-test-name.a24 >
[INFO] Test: A longer name .......................................... [ PASS ]
[INFO] Test: X ...................................................... [ PASS ]
[INFO] 
[INFO] All 2 tests passed.
```

**[TST-002]**  A test block is a declaration and does not run when the program
runs.

    conformance  0102-test-declaration.a24

### 19.2 Running

**[TST-003]**  A test run executes the test blocks **instead of** the program.
The top-level statements do not run — only the declarations they would have
created.

##### conformance/0103-a-test-run.a24

```algol24
WriteLn ('a top-level statement, which must not run');

function Helper (); begin Exit 7; end

test 'A declaration is still available';
begin
    AssertEqual (7, Helper ());
end

test 'Output from a test body is swallowed';
begin
    WriteLn ('this must not appear in the report');
    AssertTrue (True);
end

// TST-011: every test passed, so the summary says so and the run exits 0.
```

```console
$ algc --test conformance/0103-a-test-run.a24
[INFO] Running 2 tests...
[INFO] < conformance/0103-a-test-run.a24 >
[INFO] Test: A declaration is still available ....................... [ PASS ]
[INFO] Test: Output from a test body is swallowed ................... [ PASS ]
[INFO] 
[INFO] All 2 tests passed.
```

**[TST-004]**  Tests are collected from the root file and from every module it
reaches, each file contributing once however many ways it is reached.

##### conformance/0104-test-collection-and-order.a24

```algol24
uses 'modules/Tested';

test 'Zebra is reported last';
begin
    AssertTrue (True);
end

test 'Alpha is reported first';
begin
    AssertTrue (True);
end

test 'Middle is reported between them';
begin
    AssertTrue (True);
end
```

```console
$ algc --test conformance/0104-test-collection-and-order.a24
[INFO] Running 4 tests...
[INFO] < conformance/modules/Tested.a24 >
[INFO] Test: A test in an imported module ........................... [ PASS ]
[INFO] 
[INFO] < conformance/0104-test-collection-and-order.a24 >
[INFO] Test: Alpha is reported first ................................ [ PASS ]
[INFO] Test: Middle is reported between them ........................ [ PASS ]
[INFO] Test: Zebra is reported last ................................. [ PASS ]
[INFO] 
[INFO] All 4 tests passed.
```

**[TST-005]**  Tests are reported **sorted by name within a file**, and files in
the order their first test was met — which for `uses` is load order. Source
order within a file is not preserved.

    conformance  0104-test-collection-and-order.a24

**[TST-006]**  A program's own `Write` and `WriteLn` output is **swallowed**
during a test run, so it cannot interleave with the report.

    conformance  0103-a-test-run.a24

**[TST-007]**  A value raised inside a test body and not caught makes that test
**fail**; it does not end the run, and later tests still execute.

##### conformance/0105-report-format.a24

```algol24
test 'A raise is a failure, not an abort';
begin
    raise 'thrown';
end

test 'B still runs after the failure above';
begin
    AssertTrue (True);
end

test 'C fails on an assertion';
begin
    AssertEqual (5, 4);
end

test 'D still runs after that one too';
begin
    AssertTrue (True);
end
```

```console
$ algc --test conformance/0105-report-format.a24
[INFO] Running 4 tests...
[INFO] < conformance/0105-report-format.a24 >
[INFO] Test: A raise is a failure, not an abort ..................... [ FAIL ]
[ERROR] conformance/0105-report-format.a24: thrown
[INFO] Test: B still runs after the failure above ................... [ PASS ]
[INFO] Test: C fails on an assertion ................................ [ FAIL ]
[ERROR] conformance/0105-report-format.a24: Assertion failed.  Expected '5' but got '4'.
[INFO] Test: D still runs after that one too ........................ [ PASS ]
[INFO] 
[INFO] 2 of 4 tests failed.
exit: 70
```

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

    conformance  0105-report-format.a24

**[TST-009]**  The dot leader is `55 - Length(name)` dots, clamped to a minimum
of one, so a name longer than the banner still produces a well-formed line.

##### conformance/0106-dot-leader.a24

```algol24
test 'Xy';
begin
    AssertTrue (True);
end

test 'A name of exactly forty characters here!';
begin
    AssertTrue (True);
end

test 'A name of exactly fifty-four characters, padded out ok';
begin
    AssertTrue (True);
end

test 'A name far longer than the banner allows, which must still produce a well-formed line';
begin
    AssertTrue (True);
end
```

```console
$ algc --test conformance/0106-dot-leader.a24
[INFO] Running 4 tests...
[INFO] < conformance/0106-dot-leader.a24 >
[INFO] Test: A name far longer than the banner allows, which must still produce a well-formed line . [ PASS ]
[INFO] Test: A name of exactly fifty-four characters, padded out ok . [ PASS ]
[INFO] Test: A name of exactly forty characters here! ............... [ PASS ]
[INFO] Test: Xy ..................................................... [ PASS ]
[INFO] 
[INFO] All 4 tests passed.
```

**[TST-010]**  The report is colored, and the colors are part of it: the
`[INFO]` tag white and blue, `[ERROR]` white and red, the file name cyan, `PASS`
green, `FAIL` red, and the summary green when all passed and red otherwise.

The escapes are emitted **unconditionally**, whether or not the output is a
terminal — the language has no way to ask — so anything reading a report strips
or transliterates them.

    conformance  0105-report-format.a24

**[TST-011]**  The summary is `All N tests passed.` or `N of M tests failed.`,
and the run exits **0** when every test passed and **70** when any failed.

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

**The third form is not an alternative wording but a different case**, and it
is the reason the second is not enough: a `Char` and a `String` both render as
`3` and are never equal [LEX-026], so a message quoting only the rendered values
would read `Expected '3' but got '3'.` Naming the types is what makes that
legible. Both processors already do this, and it was missing from this table.

Every form used to begin `Assertion 'left = right' failed.` — including
`AssertTrue`, which makes no comparison and has no left or right. The stem read
like a template nobody filled in.

**The two processors disagreed here**, and nothing caught it: the C runtime
said only `Assertion failed.` for `AssertTrue`, with no value at all. A report
comparison drops the `[ERROR]` lines an assertion failure prints, so the one
message a programmer reads most often was outside everything that checks the two
against each other.

##### conformance/0132-assertion-messages.a24

```algol24
test 'AssertTrue names the value that was false';
begin
    AssertTrue (False);
end

test 'AssertEqual names both values';
begin
    AssertEqual (5, 4);
end

// The types are named only when the renderings MATCH, which is the case that
// otherwise reads as nonsense: a Char and a String both render as 'a' and are
// never equal, so the message would read 'Expected ''a'' but got ''a''.'
test 'AssertEqual names the types when the renderings match';
begin
    AssertEqual ('a', Copy ('abc', 0, 1));
end

test 'Fail carries its message';
begin
    Fail ('deliberate');
end
```

```console
$ algc --test conformance/0132-assertion-messages.a24
[INFO] Running 4 tests...
[INFO] < conformance/0132-assertion-messages.a24 >
[INFO] Test: AssertEqual names both values .......................... [ FAIL ]
[ERROR] conformance/0132-assertion-messages.a24: Assertion failed.  Expected '5' but got '4'.
[INFO] Test: AssertEqual names the types when the renderings match .. [ FAIL ]
[ERROR] conformance/0132-assertion-messages.a24: Assertion failed.  Expected Char 'a' but got String 'a'.
[INFO] Test: AssertTrue names the value that was false .............. [ FAIL ]
[ERROR] conformance/0132-assertion-messages.a24: Assertion failed.  Expected true but got 'false'.
[INFO] Test: Fail carries its message ............................... [ FAIL ]
[ERROR] conformance/0132-assertion-messages.a24: Failed.  deliberate
[INFO] 
[INFO] 4 of 4 tests failed.
exit: 70
```

**[TST-013]**  `AssertEqual` compares with `=` [VAL-009], so it promotes
numerically and holds a `Char` unequal to a `String` [LEX-026].

##### conformance/0107-assert-equal-comparison.a24

```algol24
test 'AssertEqual promotes numerically';
begin
    AssertEqual (1, 1.0);
    AssertEqual (0, 0.0);
end

test 'AssertEqual holds a Char unequal to a String';
begin
    // Both render as 'a', and they are not equal -- which is why the failure
    // message names the types [TST-012].
    AssertTrue (not ('a' = Copy ('abc', 0, 1)));
end
```

```console
$ algc --test conformance/0107-assert-equal-comparison.a24
[INFO] Running 2 tests...
[INFO] < conformance/0107-assert-equal-comparison.a24 >
[INFO] Test: AssertEqual holds a Char unequal to a String ........... [ PASS ]
[INFO] Test: AssertEqual promotes numerically ....................... [ PASS ]
[INFO] 
[INFO] All 2 tests passed.
```

### 19.5 Compiled runs

**[TST-014]**  The report is **the same from any implementation**, line for
line and color for color. It is the surface on which two implementations are
compared, so a difference in it is a difference in conformance and not a matter
of presentation.

**Both processors meet this**, line for line and color for color, over the
whole suite — which is the strongest available check that the two implementations
agree, since a test report is built from almost everything the language has.

This rule previously stated only that the compiled report differs, which said
nothing about what an implementation must **do**. The requirement is agreement,
and it is now met.

    conformance  0105-report-format.a24

---

## Annex A — grammar summary *(non-normative)*

Every production stated in the chapters, collected. This annex adds nothing:
each line appears in the chapter that specifies it, and `spec/spec.sh` checks
that none has been added here or lost from here.

**The grammar is partial, deliberately.** Where a construct's shape was
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

`Sections`, `Block`, `Member` and `Statement` are referenced above and not
themselves defined. Completing the grammar is worth doing; inventing those four
productions from memory is not.

---

## Annex B — index of built-in functions *(non-normative)*

The thirty built-in names, with the rule specifying each. `spec/spec.sh`
checks this list against the names the interpreter actually registers.

| Name | Rule | Summary |
| --- | --- | --- |
| `AssertEqual` | [TST-012] | Fails unless two values are equal; test runs only |
| `AssertTrue` | [TST-012] | Fails unless a value is truthy; test runs only |
| `Fail` | [TST-012] | Fails outright with a message; test runs only |
| `Halt` | [RT-018] | Ends the program with a chosen exit status |
| `Array` | [COL-002] | An Array of N elements, each `nil` |
| `Buffer` | [RT-023] | Growable bytes with an explicit lifetime |
| `List` | [COL-002] | An empty List |
| `Map` | [COL-002] | An empty Map |
| `Set` | [COL-002] | An empty Set, or a Set of a collection's values |
| `Stack` | [COL-002] | An empty Stack |
| `Ord` | [RT-007] | The code point of one character, as an Integer |
| `Succ` | [RT-020] | The next ordinal — a Char or an Integer |
| `Pred` | [RT-020] | The previous ordinal, on the same terms |
| `Mod` | [RT-011] | The remainder, its sign following the dividend |
| `Char` | [RT-008] | The character with a code point, 0 … 10FFFF, surrogates excluded |
| `Copy` | [RT-004] | A substring, from a zero-based start, length clamped |
| `Length` | [RT-003] | The length of the argument's **text**, not a count |
| `Foreign` | [FUN-014] | The FFI's own plumbing. `external` is the spelling a program uses; this is what it becomes, and it exists because the tree-walker can reach C no other way |
| `Pos` | [RT-005] | A zero-based index, or -1 when absent; from a start index when given one |
| `ToUpper` | [RT-025] | Text folded up, ASCII only; a Char stays a Char |
| `ToLower` | [RT-025] | Text folded down, on the same terms |
| `Str` | [RT-006] | Any value rendered as text |
| `Val` | [RT-009] | A number parsed from text — an **Integer** without a point, a Double with one |
| `clock` | [RT-012] | Seconds since the epoch, as a Double |
| `FileExists` | [RT-014] | Whether a named file exists |
| `TextFile` | [RT-024] | A text file handle |
| `ParamCount` | [RT-013] | The argument count, not counting the program |
| `ParamStr` | [RT-013] | An argument by index; 0 is the program |
| `Write` | [RT-015] | Writes a value |
| `WriteLn` | [RT-015] | Writes a value and `#10` |

`clock` is the only built-in spelled in lower case, and the only one whose
name is not a noun or an imperative. Nothing depends on this; it is noted
because a reader will wonder.

---
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
- **`HadError` and `LastError` are module-level, not per instance.** Two
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

**This is an allocation-volume problem, not a reclamation one.** A collector
would not help: the bytes are allocated whether or not they are later freed, and
the copying is what makes it quadratic. `Buffer` avoids it by appending in
place, which is why the compiler's own hot paths use one.

**The fix this section proposed does not work, and it is instructive.** It
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

**What makes it unsafe is that a String is a NUL-terminated `char *`.** Any
other value holding that pointer would see the extension, because its length is
read from the bytes:

```
var A := 'ab' + 'cd';     A is the most recent allocation
var B := A;               B aliases it
var C := A + 'ef';        extending in place would change B
```

**An explicit length makes it safe**, and for a reason worth stating exactly:
`B` holds `{p, 4}` and reads only `[0, 4)`, which the append never touches — it
writes at `p + 4` and yields `{p, 6}`. The alias is correct because it carries
its own length rather than looking for a terminator. This is why the two changes
had to land in that order, and they did.

**Capacity is not enough on its own: the test must be IDENTITY.** The left
operand has to *be* the string the reserved block currently holds — pointer
**and** length together. Checking only that the capacity fits lets two appends
from one base both succeed, and the second overwrites the first:

```
var A := 'x';   var B := A + 'y';   var C := A + 'z';
```

leaves `B` reading `xz`. This was found by the compiler's own test suite
printing corrupted ANSI escapes, because `Console` builds its tags by
concatenating shared constants — so a shared operand was appended to twice.

**The consumers cost less than this section feared.** It expected every
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

**The last row is what admits all of Unicode.** `🙂` is U+1F642 and emits as
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

A prefix names a *kind*, so a name that reaches C twice reaches it through
two constructors rather than one string built by hand: `d_` goes through
`Mangle` exactly as `v_` does, or a variable spelled `Gate?` would have a legal
symbol and an illegal flag.

Symbols not derived from a name at all — a hoisted literal, a method's
parameter-type table, a test body, a `try` frame — are numbered rather than
mangled, and need none of this.

**This scheme is injective, and the one it replaced was not.** That one wrote
`?` as `_q` and passed letters through untouched, so `Ready?` and `Ready_q`
emitted one symbol between them and `cc` refused the result. Here they are
`readyQ` and `readyVq`.

**The same argument answers the escape's own collision.** An identifier
spelled `U01F642` and the character `🙂` would both want that symbol; lowercasing
separates them into `u01f642` and `U01F642`.

The two decisions depend on each other. Lowercasing is only lossless because
identifiers are case-insensitive, and the uppercase escape space only exists
because of the lowercasing. Neither works alone.

**`_` is escaped to `V` rather than passed through**, which is what leaves it
free as a separator. A caller joining parts — a method's owner and name, an
enum's type and member, a private name and its unit — escapes each part and puts
a raw `_` between them. Escaping the *joined* string instead would put the
separator back into the alphabet the escape uses: `Name__Unit` would give
`nameVVunit`, which an identifier spelled `NameVVUnit` also gives.

---

---
