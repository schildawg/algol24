# The Algol-24 Programming Language Specification

## Introduction

This is the reference manual for the Algol-24 programming language.

Algol-24 is a Pascal-flavoured, gradually typed language. Type annotations are
optional; where they are written they are checked before the program runs. A
program is a sequence of declarations and statements. Two processors are
intended to conform — a tree-walking interpreter and a compiler that emits C —
and a conforming program means the same thing under both.

### This document is normative

**It states what the language shall do, not what any implementation currently
does.** A rule is here because it is right, not because it is implemented. Where
an implementation does not yet match, the rule still stands as written and
carries a pointer to the issue tracking the gap; the implementation is what
moves.

Development is driven from this document. The first release of Algol-24 is the
point at which the specification says what it should say **and** the
implementations do what it says.

Three consequences a reader should know:

- Some rules here are not yet true of any processor. Every one of them names the
  issue that says so — see [Known defects](#known-defects). A rule with no such
  pointer is one both processors are expected to honour today.
- [Open decisions](#open-decisions) is **empty**. Every question the language
  had left unanswered has been settled and stated above, so nothing here is
  waiting on a decision. What a rule may still be waiting on is an
  implementation, which is the first point.
- [Future directions](#future-directions) lists capabilities the language is
  intended to gain and does not have. These do **not** block the first release,
  and nothing in that section may be relied upon by a program.

One capability is **optional** rather than universal: a conforming processor may
decline to provide [Graphics](#graphics). Declining changes what a program can
do, never what it means — the rule is given under
[Optional capabilities](#optional-capabilities), and it is the pattern any later
optional capability is expected to follow.

Every statement of current behavior in this document was checked by executing a
program under both processors. Nothing was taken from source comments or from
earlier prose, both of which were found to be wrong in specific places while this
was written.

## Notation

The syntax is specified using Extended Backus-Naur Form (EBNF):

```
Production  = production_name "=" [ Expression ] "." .
Expression  = Term { "|" Term } .
Term        = Factor { Factor } .
Factor      = production_name | token [ "…" token ] | Group | Option | Repetition .
Group       = "(" Expression ")" .
Option      = "[" Expression "]" .
Repetition  = "{" Expression "}" .
```

Lowercase production names identify lexical tokens; non-terminals are
CamelCase. Tokens are enclosed in double quotes.

Keywords are matched case-insensitively and are written here in lower case.
`"begin"` therefore also matches `Begin` and `BEGIN`.

## Source code representation

Source text is UTF-8 encoded Unicode, and a Unicode code point may appear
anywhere a character may: in an identifier (see
[Identifiers](#identifiers)), in a string or character literal, and in a
comment. The language's own syntax — its keywords, operators and delimiters —
uses only characters in the range 0 through 127.

Text is measured in **code points**, never in bytes or in encoded units. UTF-8
is how source is encoded and says nothing about what a program observes.

No processor accepts a byte above 127 in an identifier today; see
[Known defects](#known-defects). Literals and comments already accept them.

A line ends at the character `#10`. The characters `#9`, `#13` and space are
whitespace and separate tokens; they are otherwise ignored. `#13` is not
treated as a line terminator: it does not increment the line count.

### Characters

```
newline        = /* the character #10 */ .
whitespace     = /* #9 | #13 | " " */ .
unicode_letter = /* a Unicode code point in category Lu, Ll, Lt, Lm or Lo */ .
letter         = unicode_letter | "_" | "?" | "!" .
decimal_digit  = "0" … "9" .
```

`_`, `?` and `!` are letters and may appear anywhere in an identifier, including
as its first character. A decimal digit may not begin one.

## Lexical elements

### Comments

A comment begins with `//` and stops at the end of the line. There is no
general block comment form and no nesting. A comment acts as whitespace.

A comment beginning `///` is lexically an ordinary comment. By convention it
documents the declaration that follows, but it carries no meaning to the
language: comments are discarded by the scanner and cannot be recovered by a
program.

### Semicolons

A semicolon **terminates** a statement or declaration rather than separating
one from the next. The semicolon before `end` is therefore required:

```pascal
begin
    WriteLn('a');
    WriteLn('b');       // this semicolon is not optional
end
```

The semicolon before `else` is likewise required, because it terminates the
`then` branch (see [If statements](#if-statements)).

### Identifiers

```
identifier = letter { letter | decimal_digit } .
```

Identifiers name program entities. Identifiers are **case-insensitive**: `Count`
and `count` are one name, as are `BEGIN` and `begin`. An identifier that differs
from a keyword only in case is therefore not available as a name.

An identifier begins with a letter and continues with letters and decimal
digits. `unicode_letter` covers the Unicode letter categories, so `Café`,
`Δelta` and `半径` are identifiers; `_`, `?` and `!` are letters too, so
`Snake_Case`, `Ready?` and `Commit!` are each a single identifier and the
trailing punctuation is part of the name rather than an operator. Nothing else
in the language spells `?` or `!`, so no ambiguity arises.

A decimal digit may not begin an identifier, which is what keeps `1x` from
scanning as a name. Digits are the ASCII digits `0` through `9`; a Unicode digit
is not a digit here, and — not being a letter either — cannot appear in an
identifier at all.

`?` and `!` carry no meaning. They are ordinary characters, conventionally used
to end a predicate and a mutator respectively, and a processor must not attach
significance to either.

Two consequences of admitting Unicode. Identifiers are otherwise compared by
their code points, so two names that render identically but differ in
normalization are different names; a processor performs no normalization. And
the case fold covers the whole Unicode letter range rather than ASCII alone, so
it applies to `Straße` and `İstanbul` as it does to `Count`. The fold is
locale-independent: `I` never folds to `ı`.

**Three parts of this are not implemented.** Identifiers are case-*sensitive*
today, and `!` and Unicode letters are refused by the scanner. See
[Known defects](#known-defects), issues #1 and #2.

### Keywords

The following identifiers are reserved and may not be used as names:

```
and         as          begin       break       case        class
const       constructor continue    do          else        end
except      exit        false       for         function    goto
if          in          is          nil         not         object
of          or          print       private     procedure   public
raise       super       then        this        true        try
type        uses        var         while
```

`unit`, `test` and `on` are **not** keywords. They are ordinary identifiers
recognised by position: a program may declare a variable named `test`. They are
described where they are used.

There is no `finally` keyword; the language has no such construct.

### Operators and delimiters

```
+    -    *    /
=    <>   <    <=   >    >=
:=   :    ;    ,    .
(    )    [    ]    #
```

`=` is equality and `:=` is assignment. `<>` is inequality. There is no `==`,
`!` or `!=` token. `#` introduces a character literal. `//` introduces a
comment; a single `/` is division.

Any other character is a lexical error.

### Integer literals

```
int_lit      = dec_lit | hex_lit | oct_lit | bin_lit .
dec_lit      = decimal_digit { [ "_" ] decimal_digit } .
hex_lit      = "0" ( "x" | "X" ) hex_digit    { [ "_" ] hex_digit } .
oct_lit      = "0" ( "o" | "O" ) octal_digit  { [ "_" ] octal_digit } .
bin_lit      = "0" ( "b" | "B" ) binary_digit { [ "_" ] binary_digit } .

hex_digit    = "0" … "9" | "A" … "F" | "a" … "f" .
octal_digit  = "0" … "7" .
binary_digit = "0" | "1" .
```

An integer may be written in base 10, 16, 8 or 2: `65535`, `0xFFFF`, `0o1234`,
`0b1111`. The prefix letter and the hexadecimal digits are case-insensitive, so
`0XFF` and `0xff` are the same literal.

A leading zero does **not** make a literal octal. `0123` is one hundred and
twenty-three, and octal is written `0o123` or not at all.

An underscore may separate digits: `1_000_000`, `0xFFF_FFF`, `0b1010_1010`. The
grammar above states the whole rule — **an underscore must have a digit
immediately on both sides**. So `_1`, `1_`, `1__0` and `0x_FF` are all
malformed, and an underscore never appears next to the prefix, the point or the
exponent marker. Underscores have no meaning; they are removed before the value
is read.

Every form denotes a **value**, not a bit pattern. `0xFFFFFFFF` is 4294967295,
so by the rule below it is a `Long`; it is not `-1`.

An integer literal takes the **narrowest of `Integer` and `Long` that holds its
value**. `1` is an `Integer`; `10000000000` is a `Long`. A literal too large for
`Long` is a static error, not a wrap — a constant is the one place a processor
always has enough information to refuse.

`Byte` and `Short` have no literal form. A literal reaches them by widening
where the context asks for one, or by an explicit conversion.

There is no sign in the literal itself; `-1` is the unary operator `-` applied
to `1`. There is no base prefix and no digit separator.

> **Defective.** `10000000000` is silently truncated to `1410065408` by both
> processors — [issue #8](https://github.com/schildawg/algol24/issues/8).

### Floating-point literals

```
float_lit = dec_lit "." dec_lit [ exponent ]
          | dec_lit exponent .
exponent  = ( "e" | "E" ) [ "+" | "-" ] dec_lit .
```

A floating-point literal has type `Double`. There is no literal form for
`Single`; a literal reaches it by an explicit conversion.

A literal is a `Double` when it has a fractional part, an exponent, or both:
`1.5`, `1.1e-9`, `1e9`. A fractional part is recognised only when a digit
follows the `.`, so `1.` is the integer `1` followed by the `.` operator.

The exponent marker is `e` or `E`, its sign is optional, and its digits are
decimal whatever the mantissa looks like. There is no exponent on a hexadecimal,
octal or binary literal; those are integer forms only.

Underscores may separate digits here too, under the same rule — between two
digits and nowhere else. `1_000.000_1` and `1e1_0` are well formed; `1_.0`,
`1._0` and `1e_9` are not.

> **Not implemented.** None of the bases, the exponent or the separators are
> accepted — [issue #10](https://github.com/schildawg/algol24/issues/10). Each
> currently scans as a number followed by an identifier.

**There is no exponent notation.** `1.0e6` is not a floating-point literal: it
scans as the literal `1.0` followed by the identifier `e6`.

### Character literals

```
char_lit = "#" decimal_digit { decimal_digit }
         | "'" /* exactly one source character other than "'" */ "'" .
```

A character literal has type `Char`. It takes two forms:

- `#N` denotes the character with code point N. N must be a Unicode scalar
  value — 0 through 1114111, excluding the surrogate range 55296 through 57343.
  A value outside that is a run-time error.
- A quoted literal whose text between the quotes is **exactly one code point**
  is a `Char`, not a `String`. `'a'`, `'é'` and `'😀'` are each a `Char`.

The second rule is measured on the source text, not on the resulting value.
`''''` is a quoted literal containing an escaped quote: two source characters
between the quotes, so it is a `String` of length 1, not a `Char`.

### String literals

```
string_lit = "'" { source_char_other_than_quote | "''" } "'" .
```

A string literal has type `String`. Literals are single-quoted. The only
escape is a doubled quote, which denotes one quote character: `'it''s'` is the
four-character string `it's`. There are **no backslash escapes**; a backslash
is an ordinary character.

A literal whose source text between the quotes is exactly one code point is a
`Char` (see above). The empty literal `''` is a `String` of length 0.

A string literal may span lines; an embedded newline is part of the value.

## Types

A type determines a set of values and the operations that apply to them.

```
Type     = TypeName [ "of" TypeArgs ] .
TypeArgs = Type | "(" Type { "," Type } ")" .
TypeName = identifier .
```

A type is a name, optionally followed by `of` and the types it is made of. After
`of` comes either a single type or a parenthesised list of them; a single type
may be parenthesised or not, so `List of Integer` and `List of (Integer)` are
the same.

The parenthesised form is what keeps a two-argument type readable where a comma
already means something else — a parameter list:

```pascal
procedure Merge (Into : Map of (String, Integer), From : Map of (String, Integer));
```

Only the collection types take arguments, and each takes a fixed number: one for
`List`, `Array`, `Set` and `Stack`, two for `Map` — its key type and then its
value type. Supplying the wrong number is a static error.

A type argument is itself a type, so they nest:
`Map of (String, List of Integer)`.

An annotated type may be written wherever a type may: a variable or field
declaration, a parameter, and a function's result type.

### Predeclared types

```
Boolean
Byte  Short  Integer  Long
Single  Double
Char  String
Any
```

- **`Boolean`** has values `True` and `False`.
- **`Byte`** is an unsigned 8-bit integer, 0 through 255.
- **`Short`** is a signed 16-bit two's-complement integer.
- **`Integer`** is a signed 32-bit two's-complement integer. Note that this is
  32 bits and not Turbo Pascal's 16.
- **`Long`** is a signed 64-bit two's-complement integer.
- **`Single`** is an IEEE 754 binary32 floating-point number.
- **`Double`** is an IEEE 754 binary64 floating-point number.
- **`Char`** is a single Unicode scalar value: a code point in 0 through
  1114111, excluding the surrogate range 55296 through 57343. `'a'`, `'é'` and
  `'😀'` are each one `Char`.
- **`String`** is a sequence of `Char`, indexed from 0. Its length, its indices
  and every operation on it are counted in **code points**. How a processor
  stores a `String` is its own affair and is not observable; in particular a
  program cannot see the UTF-8 encoding of its own source.
- **`Any`** is the type of a value whose type is not stated.

There is no `Real`. Turbo Pascal's `Real` is a 48-bit software format that
existed because the 8087 was an optional chip, and Delphi later redefined it as
an alias for `Double`; naming it here would mean one of two different things
depending on which Pascal the reader knows. `Single` and `Double` are also
Turbo Pascal's names, and both are unambiguous.

There is no unsigned type other than `Byte`, which exists to hold raw data
rather than to count. `Char` is a Unicode scalar and no longer byte-sized, so
`Byte` occupies the place Turbo Pascal's `Char` held.

> **Not implemented.** Only `Boolean`, `Integer`, `Double`, `Char`, `String` and
> `Any` exist — [issue #9](https://github.com/schildawg/algol24/issues/9). And
> `String` is a sequence of bytes rather than code points —
> [issue #6](https://github.com/schildawg/algol24/issues/6). A program using
> neither the new types nor a character above 127 cannot tell, which is why the
> compiler compiles itself under the current behavior.

### Numeric conversion

The numeric types form one ladder:

```
Byte  →  Short  →  Integer  →  Long  →  Single  →  Double
```

A value **widens** implicitly to any type to its right, and never leftwards.
A binary arithmetic or comparison operator promotes both operands to the
further of their two positions and produces a result of that type.

`Long → Single` is on the ladder for uniformity, and it is the one step that can
lose precision: a 64-bit integer beyond 2^24 may not be representable. It is
still a widening, because it cannot fail — only round.

**`Byte` and `Short` are storage types.** Arithmetic on them yields `Integer`,
so `B + B` is an `Integer` and neither type ever appears as the result of an
operator. This is what keeps the operator rules to a ladder rather than a table
of every pair.

Narrowing is never implicit. Each numeric type is also a **conversion
function** taking any number, following `Char(N)`, which the language already
has:

```pascal
var Small : Byte    := Byte (200);      // 200
var Cut   : Integer := Integer (1.9);   // 1, truncated toward zero
var Bad   : Byte    := Byte (300);      // run-time error
```

A conversion that would lose *range* is a run-time error, in the same shape as
`Char is limited to a Unicode scalar value.` A conversion from a floating-point
type to an integer type truncates toward zero, since discarding the fraction is
what the conversion is for; it is an error only when the truncated value does
not fit. `Round(X)` converts to the nearest integer instead, halves away from
zero.

### Overflow

Integer arithmetic wraps at the width of its result type and is not an error:
`2147483647 + 1` is `-2147483648`. Floating-point division by zero yields an
infinity; integer division by zero is a run-time error.

Because `Byte` and `Short` are storage types, no operator produces a value that
wraps at 8 or 16 bits — the wrap can only happen at an explicit conversion,
where it is an error rather than a wrap.

`Char` and `String` are **distinct types**, but a `Char` widens to a `String`
(see [Widening](#widening)), so they compare as text and are equal when they
hold the same code points:

```pascal
Copy('ab', 0, 1) = 'a'      // True
'hello'[0] = 'h'            // True
'A' = Str('A')              // True
```

The types stay distinct where the distinction is observable — `'a' is Char` and
`Str('a') is String` are both `True`, and a declared `Char` will not accept a
`String` — but no operation silently reports two pieces of identical text as
different.

> **Not implemented.** Both processors report `'A' = Str('A')` as `False` —
> [issue #7](https://github.com/schildawg/algol24/issues/7).

`Integer` and `Double` are distinct types, but they compare and combine
numerically: `1 = 1.0` is `True`, and mixing them in arithmetic produces a
`Double`.

### The nil value

`nil` is a value belonging to no type. It may be assigned to a variable of any
declared type, and it is the value of a variable that has been declared without
an initializer and of a function that returns without a value.

`nil is T` is `False` for every `T`.

### Collection types

```
List  Map  Set  Stack  Array  Buffer
```

Each is produced by a built-in constructor of the same name, and `List` and
`Map` also have literal forms. Their operations are given in
[Collections](#collections).

Every collection iterates in **insertion order**. Re-assigning a key already
present in a `Map` keeps that key's original position.

### File type

`TextFile` is the type of a text file handle, produced by the built-in
`TextFile()`. Its operations are given in [Files](#files).

### Graphics types

`Window` is the type of a window, produced by the built-in
`Window(Title, Width, Height)`. `Image` is the type of a decoded picture,
produced by `Load` on a window. Their operations are given in
[Graphics](#graphics).

Both names are predeclared in every conforming processor, including one that
cannot open a window. A processor that omits the graphics capability still
answers `Window` and `Image` to `is`, and still renders the two types as
`'Window'` and `'Image'`. See [Optional capabilities](#optional-capabilities).

### Class, object and enumeration types

A `class`, `object` or `type` declaration introduces a named type. These are
described under [Declarations](#declarations-and-scope).

### Function values

A function or procedure name denotes a value. Function values may be assigned
to variables, passed as arguments, stored in collections, and called:

```pascal
function Twice (X); begin Exit X * 2; end
begin
    var F := Twice;
    var L := [Twice];
    WriteLn(F(21));         // 42
    WriteLn(L[0](3));       // 6
end
```

There is no syntax for an anonymous function; a function value is always
obtained from a declared function.

## Type compatibility

The checker runs before the program does. A program that fails to check does
not run, and its diagnostic is not catchable by `try` (see
[Static errors](#static-errors)).

### Widening

Some types convert to others without being asked. A value of type `Actual`
**widens** to `Expected` when:

| From | To | |
|---|---|---|
| `Char` | `String` | a single code point becomes a `String` of length 1 |
| `Integer` | `Double` | exactly, for every `Integer` |

Widening never runs backwards. A `String` does not narrow to a `Char` even when
it holds one code point, and a `Double` does not narrow to an `Integer` even
when it is whole; both require an explicit operation.

A widening conversion loses nothing and cannot fail, which is what distinguishes
it from a cast. `Length` of a widened `Char` is 1, and a widened `Integer`
compares equal to the `Integer` it came from.

### The two modes

Annotations are optional, and both ways of writing a program are first class.

- **Static.** Types are written, and every one of them is enforced before the
  program runs. The compiler's own source is written this way and is meant to be
  the worked example of it.
- **Dynamic.** Types are omitted, and there is nothing to enforce.

The rules below are shaped by that pair. Nothing obliges a program to write a
type; everything a program does write is a promise a processor keeps. Types are
a compile-time statement and nothing else — there is no run-time type system
underneath, and an annotation produces no check while the program runs.

### `Any` and the absence of a type

**`Any` and *untyped* are one type, not two.** A declaration written without an
annotation, a parameter written without one, and a declaration annotated `Any`
all describe a value of type `Any`. `Any` means *the type is not known here*,
and the language does not distinguish “nobody wrote it” from “nobody could
work it out”.

`Any` is **contagious**. An expression is `Any` when what it is computed from is
`Any`: a call whose result type is not known, an operator with an `Any` operand,
a field read from a receiver of unknown type. There is no point at which a value
stops being `Any` by being used.

How much of a program is `Any` is therefore decided by how well a processor
infers. Where a type is determined, a processor is expected to determine it;
`Any` is what is left.

> **Not implemented.** Inference stops well short of what the program
> determines, so `Any` appears in many places where the type is deducible —
> [issue #28](https://github.com/schildawg/algol24/issues/28).

### Assignability

A type `Actual` is *assignable* to a declared type `Expected` when any of the
following holds:

- `Expected` is `Any`;
- `Actual` is the type of `nil`;
- the two are the same type;
- `Actual` **widens** to `Expected`;
- `Actual` is a class that inherits, directly or transitively, from `Expected`.

**The relation is asymmetric, and that is the whole of its content.** Every type
is assignable to `Any`. `Any` is assignable to nothing but `Any`.

```pascal
function F (X);                     // X is Any
var
    A : Any    := X;                // legal: every type goes into Any
    B : String := X;                // ILLEGAL: Any does not come back out
```

`Any` promises nothing, so nothing can disappoint it and every value may enter
it. Letting it flow back out would mean `B : String` said nothing about `B`, and
a program that wrote its annotations would be checked no better than one that
did not — which would leave the static mode with nothing to offer.

**One relation, everywhere.** Assignability governs every place a value meets a
declared type: a declaration's initializer, an assignment, an argument bound to
a parameter, a value returned against a declared result type, and a field
against its declaration. All five are checked alike. A processor rejects a
program only when no run-time value could make it succeed.

**Splitting the statement is not a way around it.** Where a declaration is
refused, the assignment that would have the same effect is refused too:

```pascal
var B : String := X;                // ILLEGAL
```

```pascal
var B : String := '';
B := X;                             // ILLEGAL, for the same reason
```

A rule that caught only the first would not protect `B`. It would only penalise
writing the program in one statement instead of two.

> **Not implemented.** `Any` is accepted in both directions, and of the five
> paths only a declaration is strict at all —
> [issue #32](https://github.com/schildawg/algol24/issues/32). That issue also
> records why the rule must land *after*
> [issue #28](https://github.com/schildawg/algol24/issues/28): applied to the
> compiler as it stands today, it would refuse 285 sites.

### Inference

A declaration with no type annotation **infers** its type from its initializer.
Where the initializer's static type is known, that becomes the variable's type;
where it is not, the variable is `Any`.

```pascal
var I := 1;                         // Integer
var S := 'text';                    // String
var L := [1, 2, 3];                 // List
var X := F ();                      // F's declared result type, or Any
```

**An inferred type describes a variable; it does not restrict it.** It is what a
*read* of the variable yields, and it is never a constraint on what may be
written to it — no assignment to an unannotated variable is refused. Where an
assignment would contradict the inferred type, the variable is `Any` throughout
its scope instead.

```pascal
var X := 1;                         // Integer
var B : String := X;                // ILLEGAL: Integer is not assignable to String
```

```pascal
var X := 1;
X := 'text';                        // legal — and X is Any throughout, not Integer
var C : Any    := X;                // legal
var B : String := X;                // ILLEGAL: Any does not flow into String
```

Note that `var B : String := X;` is refused in both, for different reasons. That
is what makes the rule safe: an annotated declaration is protected from an
unannotated variable however that variable is later used.

**This is what keeps the two modes from colliding.** A program that writes
annotations gets them enforced, because inference is what gives the checker a
type to enforce them against — the better the inference, the more of the program
is actually checked. A program that writes none never meets a type rule at all:
it declares nothing typed, so there is nothing for an initializer to fail and
nothing for an assignment to contradict.

The alternatives were each worse in one direction. Had an inferred type also
constrained assignment, `var X := nil;` followed by `X := 5;` would be a static
error in a program containing not one annotation, which is not what an optional
type system should do. Had an unannotated declaration stayed `Any` for good,
inference would have nothing to bite on and an annotation would be checkable only
against a literal.

> **Not implemented.** An unannotated declaration is treated as untyped rather
> than inferred, and inference gives up in many places where the type is
> determined — [issue #28](https://github.com/schildawg/algol24/issues/28).

Narrowing is never implicit, in a declaration or anywhere else. Widening is:

```pascal
var I : Integer := 1.0;             // illegal: Double does not narrow
var D : Double  := 1;               // legal: Integer widens
var S : String  := 'A';             // legal: Char widens
var C : Char    := Str('A');        // illegal: String does not narrow
```

> **Not implemented.** Both processors reject all four —
> [issue #7](https://github.com/schildawg/algol24/issues/7).

## Declarations and scope

```
Program     = { Declaration | Statement | MainBlock } .
MainBlock   = "begin" { Statement } "end" .
Declaration = VarDecl | ConstDecl | FunctionDecl | ProcedureDecl
            | ClassDecl | ObjectDecl | EnumDecl | UsesDecl | UnitDecl
            | TestDecl .
```

A program is a sequence of declarations and statements at file scope. A
`begin … end` block is permitted but is not required: a file consisting of a
single statement is a program.

A file may contain any number of such blocks, and each is executed where it
stands — see [Program execution](#program-execution).

Declarations at file scope are visible throughout the file, including to
functions declared earlier in it.

### Variable declarations

```
VarDecl    = "var" identifier [ ":" Type [ "of" Type ] ] [ ":=" Expression ] ";" .
VarSection = "var" { VarSpec } .
VarSpec    = IdentifierList [ ":" Type [ "of" Type ] ] [ ":=" Expression ] ";" .
IdentifierList = identifier { "," identifier } .
ConstDecl  = "const" identifier [ ":" Type ] [ ":=" Expression ] ";" .
```

A variable declared without an initializer has the value `nil`.

`const` declares a binding that may not be reassigned. An attempt to assign to
it is a static error, reported as `Can't assign to constant 'N'.`

**An element-type annotation** — `List of Integer`, `Map of (String, Integer)` —
tells the checker what a collection holds. It does two things.

Reading from the collection yields the annotated type, so `L[0]` on a
`List of Integer` is an `Integer` and `M.Get(K)` on a `Map of (String, Integer)`
is an `Integer`, rather than `Any`.

Writing to it is **checked**: a value whose static type is known and is not
[assignable](#assignability) to the element type is a static error. A value
whose static type is unknown or `Any` is accepted, as it is everywhere else in
the language.

```pascal
var L : List of Integer := [];

L.Add (1);                          // fine
L.Add (Str ('x'));                  // static error: String is not an Integer

var Whatever := Str ('x');
L.Add (Whatever);                   // accepted: static type unknown
```

**The check is static only.** Nothing is verified when the program runs, and a
collection carries no element type at run time — so the last line above stores a
`String` in a `List of Integer` and no processor objects. The annotation is a
claim the checker helps you keep, not a guarantee a reader may rely on.

That is also why an element type is **not part of a signature** for
[overload resolution](#overload-resolution). `F(List of Integer)` and
`F(List of String)` are one signature, and declaring both is a duplicate. Were
they distinct, a call whose argument types are not known statically could not be
resolved at all, since nothing at run time can tell the two lists apart — and
the rule that a compile-time resolution must agree with a run-time one would
become impossible to keep.

> **Not implemented.** Only `List of T`, only on a variable declaration, and the
> write is not checked —
> [issue #14](https://github.com/schildawg/algol24/issues/14).

#### Variable sections and groups

A **var section** is the `var` form that introduces several declarations under
one keyword. It appears in a function's declaration part (between the
signature and its `begin`) and in a class or object header. Within a section,
a single declaration may name several variables at once — a **var group**:

```pascal
function Sect () : String;
var
    W, H : Integer := 5;            // a group: both are 5
    S : String := 'zz';
begin
    Exit Str(W) + Str(H) + S;
end
```

Every name in a group takes the one declared type, and the one initializer is
evaluated **once** into a shared temporary rather than re-evaluated per name.

**A var group may not appear at file scope.** At file scope each declaration
requires its own `var` keyword and may name only one variable:

```pascal
var W, H : Integer := 5;            // ILLEGAL at file scope
var W := 1;                         // legal
var H := 2;                         // legal
```

### Function and procedure declarations

```
FunctionDecl  = "function" identifier Signature [ ":" Type ] ";"
                [ VarSection ] Block .
ProcedureDecl = "procedure" identifier Signature ";"
                [ VarSection ] Block .
Signature     = "(" [ ParameterList ] ")" .
ParameterList = Parameter { "," Parameter } .
Parameter     = identifier [ ":" Type ] ( "..." | [ ":=" Expression ] ) .
Block         = "begin" { Statement | Declaration } "end" .
```

Parameters are comma-separated and are typed individually; a parameter without
an annotation has no declared type. A `function` may declare a result type; a
`procedure` may not. Both may be called for their value, and a `procedure`
yields `nil`.

A parameter may declare a **default**, written with `:=` as every other
initializer in the language is. A parameter with a default may be omitted at a
call.

```pascal
function Slice (Text : String, Start : Integer := 0, Count : Integer := 1) : String;
```

`:=` rather than `=` because `=` is equality here. Delphi spells a default with
`=`, but Delphi also spells a constant that way; this language writes
`const D := '…'` and `var X : Integer := 1`, so `:=` is what a binding looks
like and `=` is what a question looks like.

A default expression is evaluated **each time the call omits it**, in the scope
of the declaration rather than the caller's. Evaluating it once when the
function is declared would give every call the same object, which is a trap
worth designing out rather than documenting.

Calling with too few arguments for the parameters that have no default, or with
more than there are parameters to take them, is an error:
`Expected 1 arguments but got 0.`

#### Variadic parameters

A parameter's type may be followed by `...`, making it **variadic**: it collects
every remaining positional argument.

```pascal
function Log (Level : Integer, Parts : String...) : Nil;
```

- Inside the function the parameter is a `List of T` — `List of String` above —
  so `Parts.Length`, `Parts[0]` and `for var P in Parts` all work. Supplying no
  arguments gives a list of length zero, never `nil`.
- Only the **last** parameter may be variadic.
- A variadic parameter may not carry a `:=` default; the empty list is its
  default.
- A variadic parameter **may not be named** at a call. This needs no rule of its
  own: named arguments must follow all positional ones, and the variadic takes
  the trailing positional arguments, so a call cannot both fill it positionally
  and name an earlier parameter.
- A type is not required. `Parts...` alone collects into a `List of Any`.
- `...` follows a complete type, qualified or not, so `Shapes.Circle...` is
  variadic. One token of lookahead separates the two uses of `.`: a dot
  continuing a qualified name is followed by an identifier, and a dot beginning
  `...` is not.

#### Spread arguments

An argument may be followed by `...`, which **spreads** a collection: its
elements are passed as separate arguments.

```pascal
function Log (Parts : String...) : Nil;
begin
    Report (Prefix, Parts...);      // Parts' elements, as arguments
    Report (Prefix, Parts);         // one argument, which is a List
end
```

Spreading is explicit and is the only way a collection becomes several
arguments. A `List` passed without `...` is one argument that happens to be a
list — the meaning of a call never depends on the static type of what is passed
to it.

The operand must be a collection. A spread argument may be positional only, not
named, and it may spread into ordinary parameters as readily as into a variadic
one. Where the collection's length is not known before the program runs, so is
the call's arity, and the call is resolved when it is made — see
[Resolving at compile time](#resolving-at-compile-time).

> **Not implemented.** Neither `...` is accepted —
> [issue #16](https://github.com/schildawg/algol24/issues/16).

#### Named arguments

An argument may name the parameter it is for, with `=>`:

```pascal
WriteLn (Slice (Text => S, Count => 3));
```

**Positional and named arguments may be mixed, positional first.** Positional
arguments bind to the parameters in declaration order; after the first named
argument, every remaining argument must be named. Named arguments may appear in
any order among themselves, and any parameter supplied neither way takes its
default.

```pascal
function Slice (Text : String, Start : Integer := 0, Count : Integer := 1) : String;

Slice (S, 1, 3)                     // all positional
Slice (S, Count => 3, Start => 1)   // mixed; the named pair in either order
Slice (Text => S, Count => 2)       // all named; Start takes its default
Slice (Count => 2, Text => S)       // the same call
```

Two ways to get it wrong, both errors:

```pascal
Slice (Text => S, 1)                // positional after a named argument
Slice (S, Text => S2)               // Text is already bound positionally
```

This is Python's rule for the forms this language has. Algol-24 has no variadic
parameters, and no marker making a parameter positional-only or keyword-only, so
every parameter may be supplied either way.

`=>` rather than `=` because `f(Index = 1)` is already a legal call today — it
passes the *comparison* `Index = 1` — so `=` cannot mean association without
changing what an existing program means.

**A parameter name is part of the public interface.** Once a function is called
by name anywhere, renaming its parameter breaks that caller as surely as
changing its type would. This is a cost the feature carries rather than a
detail: a name that was private bookkeeping becomes a promise the moment the
feature exists.

> **Not implemented.** Neither defaults nor named arguments are accepted —
> [issue #15](https://github.com/schildawg/algol24/issues/15).

`Exit` returns from the current function, optionally with a value; see
[Exit statements](#exit-statements). Reaching the end of a function without
executing `Exit` yields `nil`.

Functions may be declared inside a function body and close over the enclosing
variables. Each evaluation of the enclosing function creates fresh bindings:

```pascal
function Counter () : Any;
var
    Count := 0;
begin
    function Bump () : Integer;
    begin
        Count := Count + 1;
        Exit Count;
    end
    Exit Bump;
end
// two calls to Counter() yield independent counters
```

**Functions may be overloaded.** Two functions of one name may be declared at
file scope when their signatures differ; declaring two with the *same* signature
is a static error, `'F' is already defined.` The rule is the same one that
governs methods — see [Overload resolution](#overload-resolution).

> **Not implemented.** A second top-level function of one name is refused
> whatever its signature — [issue #11](https://github.com/schildawg/algol24/issues/11).

### Class declarations

```
ClassDecl   = "class" identifier [ "(" identifier ")" ] ";"
              { FieldSection } "begin" { Member } "end" .
FieldSection = VarSection | "private" ":" { VarSpec } | "public" ":" { VarSpec } .
Member      = ConstructorDecl | FunctionDecl | ProcedureDecl .
ConstructorDecl = "constructor" identifier Signature ";" Block .
```

A class declares fields in a `var` section before its `begin`, and members
between `begin` and `end`. The optional parenthesised name after the class
name is the superclass.

```pascal
class Animal;
var
    Name : String;
private:
    Secret : Integer := 7;
public:
begin
    constructor Init (Name : String);
    begin
        this.Name := Name;
    end

    function Speak () : String; begin Exit '...'; end
    function ToString () : String; begin Exit Name + ' says ' + Speak(); end
end
```

- A field declared with an initializer is initialized **once per instance**,
  when the instance is created and before the constructor runs. Inherited
  fields are initialized before the subclass's own.
- A field without an initializer starts as `nil`. Reading a declared field
  before the constructor assigns it yields `nil` rather than an error.
- `this` refers to the receiver.
- An instance is created by calling the class name. There is no `new`.
  Arguments are passed to the constructor: `Dog('Rex')`.

#### Constructors

A member declared `constructor` is a constructor. **The keyword decides, and the
name does not.** `constructor Make` is a constructor; `function Init` is an
ordinary method with no special treatment.

A constructor may not declare a result type, and `Exit` within one may not carry
a value: `Can't return a value from an initializer.` An instance is what
construction produces, and a constructor that returned something else would have
nowhere to put it.

Constructors are members, so they are inherited and they overload like any other
member — see [Overload resolution](#overload-resolution).

```pascal
class Circle;
var
    Radius : Double := 0.0;

begin
    constructor Init (Radius : Double);
    begin
        this.Radius := Radius;
    end

    constructor FromDiameter (Across : Double);
    begin
        this.Radius := Across / 2.0;
    end
end
```

**Calling the class name** selects among **all** of its constructors by
signature: `Circle(5.0)` finds the one taking a `Double`. Where that is
ambiguous — two constructors a call fits equally — it is an error, and the
constructor must be named:

```pascal
var A := Circle (5.0);                  // the Init above
var B := Circle.FromDiameter (10.0);    // named explicitly
```

A class declaring no constructor is still callable: `Empty()` yields an instance
with its fields initialized and nothing else run.

#### What a constructor may do

**Every field initializer has already run** — the whole instance's, inherited
and declared alike, before any constructor body begins. Initialization is not
interleaved with construction, so a constructor never observes a field that its
own class initialized as `nil` unless it was declared without an initializer.

**The superclass constructor is not called automatically.** A subclass that
wants it says so:

```pascal
class Derived (Base);
begin
    constructor Init ();
    begin
        super.Init ();          // not implicit; omit it and Base's body never runs
        ...
    end
end
```

`super.Init(...)` may appear anywhere in the body, or not at all. Note what
this does *not* affect: `Base`'s field initializers ran regardless, because
initialization precedes every constructor body.

**A call on `this` reaches the most-derived override**, and that override sees
fully initialized fields. This is where the language differs usefully from its
neighbours:

| | base constructor | `this.M()` in a base constructor reaches | the override sees |
|---|---|---|---|
| C++ | implicit, first | the **base**'s `M` | — |
| Java | implicit, first | the **derived** `M` | *uninitialized* derived fields |
| Algol-24 | explicit, anywhere | the **derived** `M` | initialized fields |

Java's arrangement is a well-known trap. It does not arise here, because field
initialization is not staged per class: it all happens before any body runs.

**Other rules.**

- Reading a field before the constructor assigns it yields `nil`, never an
  error. A field declared without an initializer is `nil` throughout.
- A bare `Exit` returns from a constructor early. `Exit` with a value is a
  static error.
- `raise` propagates out of a constructor and out of the construction
  expression. The partly built instance is discarded, never bound.
- A constructor may be invoked on an existing instance — `X.Init(5)` — which
  runs it again over that instance's current state. It yields `nil`, a
  constructor having no result.

> **Not implemented.** `X.Init(5)` yields the **instance** interpreted and `nil`
> compiled — [issue #21](https://github.com/schildawg/algol24/issues/21).

> **Not implemented.** The keyword is decorative and the **name** `Init` decides
> everything — [issue #20](https://github.com/schildawg/algol24/issues/20). So
> `function Init` is a constructor today and `constructor Make` is not, which is
> the reverse of this rule. Naming a constructor at a call is not supported
> either, and constructor overloading works compiled and not interpreted.

#### Visibility

`private:` and `public:` introduce sections within the field list. A name
covered by `private:` is accessible only within its own class. Access from
outside is a **static** error — `'Secret' is private to Animal.` — and is
therefore not catchable.

#### Inheritance and `super`

A subclass inherits its parent's fields and members. A member declared in the
subclass overrides one of the same signature in the parent. `super.M(...)`
calls the parent's version, beginning the search above the class that declares
the calling member.

#### Method overloading

Methods overload under the same rule as functions; see
[Overload resolution](#overload-resolution).

A failed match in a subclass falls through to the superclass, so declaring
`Take(String)` in a subclass does not hide an inherited `Take(Integer)`.

### Overload resolution

Functions and methods overload on their **whole signature** — arity and declared
parameter types together — so two of one name may differ only in the type of a
single parameter. Two declarations with the same signature are a static error.

```pascal
function Take (N : Integer) : String; begin Exit 'int'; end
function Take (S : String)  : String; begin Exit 'str'; end
```

A call selects the candidate of matching arity whose parameters best fit the
arguments, considering each argument in turn and preferring, in this order:

1. an **exact** type match;
2. a match by [widening](#widening) — a `Char` argument to a `String` parameter,
   an `Integer` to a `Double`;
3. a parameter declared `Any`, which accepts anything;
4. a [variadic](#variadic-parameters) parameter collecting the argument.

A fixed-arity candidate therefore always beats a variadic one, so `F(S : String)`
and `F(S : String...)` are not ambiguous on `F('x')`. That is the two-phase
resolution other languages describe separately, written here as one more rung so
the ladder stays single.

A candidate that fits at a better rank on some argument and a worse rank on
another is **ambiguous** with its rival, and an ambiguous call is an error.
Declaration order never decides anything: reordering two declarations cannot
change which one a call selects.

If no candidate matches, the call is an error — `No matching signature for
function.` A parameter's declared type is a requirement, not a hint.

> **Not implemented, in two ways.** Resolution is first-declared-wins rather
> than most-specific ([issue #12](https://github.com/schildawg/algol24/issues/12)),
> and a call matching no candidate is refused by the interpreter but runs anyway
> when compiled ([issue #13](https://github.com/schildawg/algol24/issues/13)).

#### Names and defaults in resolution

A **named argument narrows the candidates before types are considered.** Only
candidates having a parameter of that name, in a position the call has not
already filled, remain. Names are syntax, so this narrowing is always available
— to a compiler and to an interpreter alike, and whether or not any argument's
type is known.

```pascal
function Adjust (Index : Integer) : String;      begin Exit 'by index'; end
function Adjust (Percentage : Single) : String;  begin Exit 'by percent'; end

Adjust (1)                  // 'by index' — Integer is exact, Single is a widening
Adjust (Index => 1)         // 'by index' — and says so
Adjust (Percentage => 1)    // 'by percent' — unreachable positionally
```

Note which line earns the feature. The first two agree, because exact already
beats widening; naming the parameter documents the choice but does not change
it. The third is the one positional calling cannot express at all — with an
`Integer` argument, `Adjust(Percentage => 1)` is the only way to reach the
`Single` overload.

**Parameter names are not part of a signature.** Two functions differing only in
the names of their parameters have the same signature and are a duplicate
declaration. Were they distinct, every positional call would be ambiguous
between them, and a feature meant to remove doubt would create it.

**Defaults are applied after narrowing, not before.** A candidate matches an
arity if the arguments supplied cover every parameter without a default. Where
more than one candidate still matches once defaults are filled in, the call is
ambiguous and is an error — the same rule as any other tie.

#### Resolving at compile time

A processor **may** resolve a call when it can determine the argument types
statically, and emit a direct call rather than a search. This is an
optimization, and it is permitted only because it is required to be invisible:
the candidate chosen statically must be the one the rule above would choose from
the run-time types. Where a static type is unknown, or is `Any`, the call is
resolved when it is made.

That requirement reaches parameter names and variadic-ness as well. A call on a receiver whose
class is not known statically is resolved when it is made, so **the run time
must carry parameter names** exactly as it carries parameter types, or a named
call would resolve one way through the compiler and another way through the
dispatcher.

The same requirement constrains the run-time representation of types. Every type
that may appear in a signature must be distinguishable at run time,
or the two paths can disagree: with `F(Byte)` and `F(Integer)` declared and a
`Byte` argument, a static resolver picks `F(Byte)` while a run time that stores
a `Byte` as a plain integer picks `F(Integer)`. Same call, two functions, and
no diagnostic from either.

#### `ToString` and `ClassName`

If a class declares `ToString()`, that member determines how an instance is
rendered by `Str`, by `Write` and `WriteLn`, and when the instance appears
inside a collection being rendered. Without it, an instance renders as
`<ClassName> instance`.

Every instance answers the property `ClassName` with the name of its class,
ahead of any field of that name.

### Object declarations

```
ObjectDecl = "object" identifier [ "(" identifier ")" ] ";"
             { FieldSection } "begin" { Member } "end" .
```

An `object` declaration is a class with exactly one instance, reached by the
declaration's name. The instance is created on first use, so an object may
refer to another object declared later in the file.

```pascal
object Registry;
var
    Count : Integer := 0;
begin
    procedure Note (); begin Count := Count + 1; end
end

begin
    Registry.Note();
    WriteLn(Registry.Count);        // 1
end
```

### Enumeration declarations

```
EnumDecl = "type" identifier "=" "(" identifier { "," identifier } ")" ";" .
```

```pascal
type Colour = (Red, Green, Blue);
```

An enumeration declares a named type and its members. Members are bound as
bare names and may also be written qualified by the type name; the two denote
the same value, and equality is identity:

```pascal
Red = Colour.Red                    // true
```

`Ord(M)` is the member's zero-based position. `Str(M)` is the member's name.
The **first member of an enumeration is false** under the truth rule; see
[Truth](#truth).

`type` declares enumerations only. There is no general type-alias form.

### Test declarations

```
TestDecl = "test" string_lit ";" Block .
```

A test declaration names a block of statements that is run only when the
processor is asked to run tests. See [Test blocks](#test-blocks).

`test` is recognised as an identifier followed by a string literal, so it
remains available as an ordinary name elsewhere.

### Units and modules

```
UnitDecl = "unit" identifier ";" .
UsesDecl = "uses" ( identifier | string_lit ) ";" .
```

Every source file is a **unit**, named by its file. A file may open with
`unit N;` to state its own name; the declaration binds nothing, and
qualification works without it.

`uses` names a file to load. The argument is either a bare identifier, which
names `<identifier>.a24`, or a quoted string giving a path, which may include
directories: `uses 'lib/Shapes';`.

A module is loaded once however many files name it. The dependency graph may
contain cycles.

**`uses` is not transitive.** A file sees the names it imports directly and
not what those imports themselves import. Each file must declare its own
dependencies:

```pascal
// M.a24 says 'uses B' and B exports Pub.
uses 'M';
begin
    WriteLn(Via());     // fine: Via is exported by M
    WriteLn(Pub());     // error: Pub belongs to B, which this file does not use
end
```

> **Defective.** The two processors treat this error very differently. The
> interpreter names the exporting unit and says the importing file has no `uses`
> for it; the compiled form emits C that the C compiler rejects. This is the
> module-system case of [issue #4](https://github.com/schildawg/algol24/issues/4).

A name marked `private` is not exported and is invisible to importers:

```pascal
private var Hidden := 'x';
private function Priv () : String; begin Exit 'p'; end
```

#### Qualification

`U.N` reaches the export `N` of unit `U`. Qualification reaches a unit's
**exports only**, so it is not a way around `private`. It reaches a type as
readily as a value: `Shapes.Circle` names a class in an annotation, in an `is`
test and in a `new` expression alike.

#### Exporting one name from two units

**Two units may export the same name.** Importing both is not an error, and
neither is using either name — provided each use says which is meant.

```pascal
uses 'Round';                       // exports Circle
uses 'Flat';                        // exports Circle

var A : Round.Circle := Round.Circle ();
var B : Flat.Circle  := Flat.Circle ();
```

A **bare** use of a name exported by more than one imported unit is an error,
reported where it is used rather than where the units are imported. Importing
two units that happen to share a name costs nothing until a program actually
writes the ambiguous name.

A file's own declaration shadows every import, so a file declaring `Circle`
means its own, and reaches the others only by qualifying.

This is what qualification is for. A module system whose names must be globally
unique has not separated anything; the point of a unit is that it owns its
names, and the point of `U.N` is to say whose you mean.

> **Not implemented.** Two units exporting one name is refused outright:
> `'Circle' is already defined; mark it private in one of the modules.` from the
> interpreter, and `Two modules exporting 'Circle' is not supported by the C
> back end yet.` from the compiler —
> [issue #18](https://github.com/schildawg/algol24/issues/18). The advice in the
> first message tells a programmer to avoid the collision rather than resolve
> it, which is the workaround this rule removes.

Which entity a name before the dot denotes follows ordinary scoping: a local
binding, then an `object` or enumeration type of that name, then a unit. A
bare class name cannot answer a dot, which is what allows a file whose unit
name and principal class name coincide to be qualified unambiguously.

#### The `System` unit

`System` is the unit of the built-in functions. It is in scope in every file
and is imported by no one. Because a program may shadow a built-in name,
`System` is the way back to the original:

```pascal
function Max (A, B) : String; begin Exit 'mine'; end
begin
    WriteLn(Max(1, 2));             // mine
    WriteLn(System.Max(1, 2));      // 2
end
```

## Expressions

### Operands

```
Operand    = Literal | identifier | "this" | "(" Expression ")"
           | ListLit | MapLit | SuperCall .
Literal    = int_lit | float_lit | string_lit | char_lit
           | "true" | "false" | "nil" .
ListLit    = "[" [ Expression { "," Expression } ] "]" .
MapLit     = "[" ( ":" | KeyValue { "," KeyValue } ) "]" .
KeyValue   = Expression ":" Expression .
SuperCall  = "super" "." identifier .
```

`[]` is an empty `List`; `[:]` is an empty `Map`. A list literal's elements
need not share a type.

### Primary expressions

```
PrimaryExpr = Operand
            | PrimaryExpr Selector
            | PrimaryExpr Index
            | PrimaryExpr Arguments .
Selector    = "." identifier .
Index       = "[" Expression "]" .
Arguments   = "(" [ Argument { "," Argument } ] ")" .
Argument    = identifier "=>" Expression | Expression [ "..." ] .
```

**Selectors** read a field, a property, or a member of the value on the left.
An unknown name is a run-time error, `Undefined property 'N'.`

**Index** reads by position from a `String`, `List`, `Array` or `Stack`, and by
key from a `Map`. String and sequence indices are 0-based and are bounds
checked: `Index 9 out of range 0..4.` Indexing a `String` yields a `Char`, and
the index counts **code points**, so `'héllo'[1]` is `'é'` and never a fragment
of one. A
`Set` is indexed by position too: every collection iterates in
[insertion order](#collection-types), so its elements have positions even though
its members are not addressed by one.

### Operators

```
Expression = AsExpr .
AsExpr     = OrExpr [ "as" identifier ] .
OrExpr     = AndExpr { "or" AndExpr } .
AndExpr    = EqualExpr { "and" EqualExpr } .
EqualExpr  = RelExpr { ( "=" | "<>" ) RelExpr } .
RelExpr    = AddExpr { ( "<" | "<=" | ">" | ">=" | "is" | "in" ) AddExpr } .
AddExpr    = MulExpr { ( "+" | "-" ) MulExpr } .
MulExpr    = UnaryExpr { ( "*" | "/" ) UnaryExpr } .
UnaryExpr  = PrimaryExpr | ( "not" | "-" ) UnaryExpr .
```

Precedence, from loosest to tightest:

| Level | Operators |
|---|---|
| 1 | `as` |
| 2 | `or` |
| 3 | `and` |
| 4 | `=` `<>` |
| 5 | `<` `<=` `>` `>=` `is` `in` |
| 6 | `+` `-` |
| 7 | `*` `/` |
| 8 | `not` `-` (unary) |

Binary operators of the same level associate left to right. `not` and unary
`-` associate right to left.

`is` and `in` sit with the relational operators, which is what allows
`A is Dog and B is Cat` to parse as intended.

**`as` binds loosest of all.** `A + B as T` casts the whole sum. An expression
carries at most one cast.

### Arithmetic operators

`+`, `-`, `*` and `/` require two numbers, except that `+` also concatenates
when either operand is text — a `String` or a `Char`. Any other combination is a
run-time error: `Operands must be two numbers, or two strings.`

- `Integer` with `Integer` yields an `Integer`. This includes `/`, which is
  integer division; it **truncates toward zero**, so `-7 / 2` is `-3`.
- A `Double` on either side promotes the result to `Double`.
- Integer division by zero is a run-time error, `Division by zero.`
  Floating-point division by zero yields an infinity.
- Integer overflow wraps at 32 bits and is not an error.

Concatenation renders a non-string operand as `Str` would:
`'n=' + 1` is `n=1`, and `1 + '2'` is `12`. Two `Char`s concatenate to a
`String`: `'a' + 'b'` is `ab`.

Unary `-` requires a number: `Operand must be a number.`

`Mod(A, B)` is the remainder and is **not** an operator; it is a built-in
requiring two `Integer`s. Its result takes the sign of the dividend:
`Mod(-7, 2)` is `-1`.

### Comparison operators

`=` and `<>` compare any two values and **never fail**. Where one operand
[widens](#widening) to the other's type, both are widened to that common type
and compared as values of it; where neither does, values of different types are
unequal.

- `Integer` and `Double` compare numerically: `1 = 1.0` is `True`.
- `Char` and `String` compare as text: `'A' = Str('A')` is `True`, and
  `'a' = #97` is `True`.
- Two values with no common type are unequal rather than an error:
  `1 = Str('1')` is `False`, and so is `nil = 0`.
- `nil = nil` is `True`.
- Enumeration members compare by identity.

Equality never raising is what lets a collection hold values of mixed type.
`Contains`, `Map` keys and `case` labels all use this relation, so a `Map` keyed
by `'A'` is found by `Str('A')` and vice versa.

`<`, `<=`, `>` and `>=` order **numbers** and **text**, and mixing the two is a
run-time error, `Operands must be numbers.`

- Numbers order numerically, widening `Integer` to `Double` where they meet.
- Text orders by code point, comparing position by position; where one is a
  prefix of the other the shorter is the lesser. `Char` widens to `String`
  first, so `'a' < Str('ab')` is `True` and `Str('abc') < Str('abd')` is `True`.

The order is by code point and nothing else. It is not a collation: it is not
locale-sensitive, does not case-fold, and does not normalize. Two processors
must agree on it, and only a mechanical rule can guarantee that.

> **Not implemented.** `Str('abc') < Str('abd')` is a run-time error under both
> processors — [issue #7](https://github.com/schildawg/algol24/issues/7).

### Logical operators

`and` and `or` take the truth of their operands (see [Truth](#truth)) and
**yield one of the operands rather than a `Boolean`**. Evaluation is
short-circuit: `or` does not evaluate its right operand when the left is true,
and `and` does not when the left is false.

`not` yields a `Boolean`.

### Membership

`X in C` reports whether `C` contains `X`. It is defined for the collection
types and for `String`, and reports membership by value. For a `Map` it tests
**keys**, not values. For a `String` it tests whether the left operand occurs
in the text, so `'b' in 'abc'` is `True`.

### Type tests and casts

`X is T` reports whether `X`'s run-time type is `T` or inherits from it. It
yields a `Boolean`. `nil is T` is `False` for every `T`.

`X as T` tells the checker to treat `X` as a `T`. It has no run-time effect
and performs no check: it exists to state what the programmer knows and the
checker deduced otherwise.

### Truth

Every value has a truth used by `if`, `while`, `and`, `or` and `not`.

**False** are exactly:

- `nil`
- `False`
- the **`Integer`** `0`
- an enumeration member whose ordinal is `0`

**Everything else is true**, including `0.0`, the empty string `''`, and every
`Char`.

The rule for `Integer` `0` does not extend to `Double`: `not 0` is `True` while
`not 0.0` is `False`. The rule for ordinal-zero enumeration members means the
first member declared in a `type` is false, which is why a value of an
enumeration type must be compared rather than tested.

## Statements

```
Statement = [ Label ] UnlabelledStmt .
Label     = identifier ":" .

UnlabelledStmt
          = Block | VarDecl | ConstDecl | ExpressionStmt | AssignStmt
          | IfStmt | WhileStmt | ForStmt | ForInStmt | CaseStmt
          | BreakStmt | ContinueStmt | GotoStmt
          | ExitStmt | RaiseStmt | TryStmt | PrintStmt .
Block     = "begin" { Statement | Declaration } "end" .
```

A block introduces a new scope. A declaration inside a block is visible from
its declaration to the end of the block, and shadows any outer binding of the
same name for that region. An inner declaration may shadow an outer `const`
and is itself assignable.

Note that a block is `begin … end`, and that `end` is not followed by a
semicolon.

### Expression statements

```
ExpressionStmt = Expression ";" .
```

### Assignment statements

```
AssignStmt = Target ":=" Expression ";" .
Target     = identifier | PrimaryExpr Selector | PrimaryExpr Index .
```

The three assignable forms are a variable, a property or field, and a
subscript:

```pascal
X := 1;
Obj.Field := 5;
L[0] := 9;
M['k'] := 1;
```

Assigning to a `const` is a static error. Assignment is checked by
[assignability](#assignability) alone, which is more permissive than the rule
for a declaration with an initializer.

Assigning to a `Map` key that is not present adds it.

### If statements

```
IfStmt = "if" Expression "then" Statement [ ";" ] "else" Statement .
```

The condition is evaluated for its [truth](#truth); it need not be a `Boolean`.

The `then` branch is a statement and is terminated by its own semicolon, so a
semicolon precedes `else`:

```pascal
if X > 0 then WriteLn('positive');
else WriteLn('zero or less');
```

`else if` chains as expected, the `else` branch being another `if` statement.

### While statements

```
WhileStmt = "while" Expression "do" Statement .
```

The condition is evaluated for its truth before each iteration.

### For statements

```
ForStmt = "for" VarDeclNoSemi ";" Expression ";" Expression "do" Statement .
```

The counted `for` has three clauses: an initializer that declares the loop
variable, a condition evaluated for its truth before each iteration, and a step
evaluated after each iteration.

```pascal
for var I := 0; I < 10; I := I + 1 do
    WriteLn(I);
```

There is no `to`/`downto` form. The step is an ordinary expression, so it
determines the direction.

**The loop variable is scoped to the loop.** It is not visible after the loop
ends.

### For-in statements

```
ForInStmt = "for" "var" identifier "in" Expression "do" Statement .
```

`for … in` walks:

- a `List`, `Set`, `Stack` or `Array`, yielding elements in insertion order;
- a `Map`, yielding its **keys**;
- a `String`, yielding its characters as `Char`s.

The collection is snapshotted before the loop begins, so mutating it inside the
body does not change what the loop walks.

### Case statements

```
CaseStmt   = "case" Expression "of" { CaseClause } [ "else" Statement ] "end" .
CaseClause = Expression { "," Expression } ":" Statement ";" .
```

A clause may list several labels. The first clause whose label equals the
subject value is run, and **control does not fall through** to the next.
If no clause matches and there is no `else`, the statement does nothing.

Labels are compared with `=`, so a case may switch on an `Integer`, a `Char`, a
`String` or an enumeration member. There is no range label.

```pascal
case N of
    1:    Exit 'one';
    2, 3: Exit 'few';
else
    Exit 'many';
end
```

### Labels

Any statement may be preceded by a label, which names it for `break`,
`continue` and `goto`. There is one label namespace and no `label` declaration
section.

```pascal
Outer: for var I := 0; I < 3; I := I + 1 do
begin
    for var J := 0; J < 3; J := J + 1 do
    begin
        if Grid[I][J] = Wanted then break Outer;
    end
end
```

A label is in scope from the statement it names to the end of the block
containing that statement. Two labels of the same name may not be in scope at
once. `Ident :` cannot be mistaken for the start of an assignment, since `:=` is
a single token.

### Break, continue and goto

```
BreakStmt    = "break" [ identifier ] ";" .
ContinueStmt = "continue" [ identifier ] ";" .
GotoStmt     = "goto" identifier ";" .
```

`break` leaves a loop; `continue` begins its next iteration. Without a label
each acts on the innermost enclosing loop; with one, on the loop the label
names, which must enclose the statement.

`goto` transfers control to the labelled statement, which is then executed from
its beginning. On a loop that means the loop restarts, initializer and all —
which is what distinguishes `goto L` from `continue L`.

#### Where a goto may go

**A `goto` may name a label in its own block or in an enclosing block, within
the same function.** It may not jump into a nested block, and may not leave the
function it is in.

The reason is not fashion, and it is worth stating because it also explains why
labelled `break` and `continue` are unaffected. Every jump has to pop the
exception frames lying between where it is and where it goes: `break` already
pops back to the depth its loop began at, and the emitter keeps a `LoopTryDepth`
for precisely that, because a `break` out of a `try` that skipped the pop left
the runtime's frame stack pointing at a C frame that had returned.

A jump **outward** has a depth to restore, because the frames between here and
there exist and can be counted. A jump **inward** does not: the frames that
block would have opened were never opened, so there is no arithmetic to do. The
constraint is what the frame stack can express, not a matter of taste.

Labelled `break` and `continue` name an enclosing loop by construction, so they
are always in the permitted direction.

> **Not implemented.** There is no `continue`, no label and no `goto` —
> [issue #19](https://github.com/schildawg/algol24/issues/19). The compiler's own
> source works around the absence of `continue` in three places.

### Exit statements

```
ExitStmt = "exit" [ Expression ] ";" .
```

`Exit` returns from the current function or procedure. With an expression, that
is the result; without one, the result is `nil`. There is no `return` keyword.

`Exit` may appear only inside a function or procedure body. At file scope,
including inside a file-scope `begin … end` block, it is a static error:
`Can't return from top-level code.` A program therefore has no statement that
ends it early; it ends by running out of statements or by raising.

### Raise statements

```
RaiseStmt = "raise" Expression ";" .
```

See [Exceptions](#exceptions).

### Try statements

```
TryStmt = "try" { Statement } "except" ( { Handler } | { Statement } ) "end" .
Handler = "on" identifier ":" identifier "do" Statement ";" .
```

See [Exceptions](#exceptions).

### Print statements

```
PrintStmt = "print" Expression ";" .
```

`print` writes the value followed by a newline. `WriteLn` is the built-in with
the same effect; `print` is a statement rather than a call.

## Errors

The language distinguishes errors detected before the program runs from those
raised while it runs. The distinction is observable, because only the second
kind can be caught.

### Static errors

A static error prevents the program from running at all. It is reported and
the program is rejected; `try` cannot intercept it, because no statement has
executed.

The following are static errors:

- a type mismatch in a declaration or assignment (`Type mismatch!`);
- assigning to a `const` (`Can't assign to constant 'K'.`);
- accessing a private member from outside its class
  (`'Secret' is private to Animal.`);
- declaring two top-level functions of the same name
  (`'F' is already defined.`);
- `Exit` outside a function or procedure
  (`Can't return from top-level code.`);
- any lexical or syntactic error.

Every static error reports the file, the line and a caret under the offending
text.

> **Not implemented.** `Type mismatch!` alone reports no position and names
> neither of the two types —
> [issue #37](https://github.com/schildawg/algol24/issues/37).

### Run-time errors

A run-time error is raised as a `String` and may be caught by a handler for
`String`. Observed messages include:

```
Undefined variable 'N'.
Undefined property 'N'.
Undefined method 'N'.
Division by zero.
Operands must be two numbers, or two strings.
Operands must be numbers.
Operand must be a number.
Index 9 out of range 0..4.
Expected 1 arguments but got 0.
Char is limited to a Unicode scalar value.
That Buffer has been freed.
```

An uncaught error terminates the program with status 70, and is reported as

```
Uncaught: <message>
```

whatever raised it — a built-in, a processor's own runtime, or the program's own
`raise`.

**The prefix describes what happened to the error, not what the error is.** It
is added by the top level, on finding no handler left to unwind to, and never by
whatever constructed the message. A *caught* value therefore never carries the
word `Uncaught`, and a handler that inspects the string sees exactly what was
raised.

> **Not implemented.** Compiled code prints a built-in's message bare, without
> the prefix — [issue #40](https://github.com/schildawg/algol24/issues/40).
> A value raised by the program itself is already correct under both.

## Exceptions

```
RaiseStmt = "raise" Expression ";" .
TryStmt   = "try" { Statement } "except" ( { Handler } | { Statement } ) "end" .
Handler   = "on" identifier ":" identifier "do" Statement ";" .
```

Any value may be raised. `raise` unwinds until a matching handler is found; if
none is, the program terminates with status 70.

A handler names a type. It matches when the raised value's run-time type is
that type or inherits from it. The type names that match built-in values are
`String`, `Integer`, `Double`, `Char`, `Boolean`, and the collection type names;
an instance matches its class name and any ancestor's.

**The most derived handler wins, whatever order the handlers are written in:**

```pascal
try raise Derived();
except
    on E : Base    do WriteLn('base');
    on E : Derived do WriteLn('derived');    // this one runs
end
```

An `except` section with no `on` clauses is a catch-all:

```pascal
try raise 'x'; except WriteLn('caught'); end
```

`Any` is **not** a handler type and matches nothing:

```pascal
try raise 1; except on E : Any do WriteLn('never'); end   // propagates
```

`on` is recognised by position and is not a keyword.

There is no `finally`. The nearest equivalent is a catch-all handler.

Note that a one-character quoted literal is a `Char`, so `raise 's'` is caught
by `on E : Char` and not by `on E : String`.

## Test blocks

```
TestDecl = "test" string_lit ";" Block .
```

Tests are part of the language rather than a library. A test declaration is
ignored during a normal run and is executed when the processor is asked to run
the file's tests.

```pascal
test 'Copy Takes A Length';
begin
    AssertEqual('ell', Copy('hello', 1, 3));
end
```

Three built-ins are available to a test: `AssertTrue(V)`, `AssertEqual(E, A)`
and `Fail(M)`. A failing assertion reports the expectation and the actual
value and marks the test failed; the run continues with the next test.

A run reports how many tests passed and failed. If any test fails the program
terminates with status 70.

**Tests run in alphabetical order by name**, not in declaration order. A test
must therefore not depend on another having run first.

A test block can only reach the names its own file can reach. A file's tests
therefore see what that file declares and what it `uses`, and nothing else.

## Collections

Six collection types are built in. `List` and `Map` have literal forms; all six
have a constructor of the same name.

```pascal
var L := [3, 1, 2];             // List
var M := ['a':1, 'b':2];        // Map
var E := [:];                   // empty Map
var S := Set();
var K := Stack();
var A := Array(3);              // three elements, each nil
var B := Buffer();              // or Buffer(N) for N zero bytes
```

Every collection has the properties `Length` and `IsEmpty`, written **without
parentheses**, and the method `Contains(V)`.

`Array(N)` is created with `N` elements, each `nil`.

### Method sets

A collection kind is defined by an **invariant** — a property that holds of
every value of that kind, however the program uses it. From that follows the
whole of the rule:

**A method is refused on a kind only where no meaning would preserve both that
kind's invariant and what the call asked for.** Nothing else is refused: where
such a meaning exists, the method is accepted and given it.

The second clause matters as much as the first. A call that *could* break an
invariant is not thereby refused — it is refused only when honouring it would
mean either breaking the invariant or quietly doing something other than what was
asked. Most of the awkward cases have an obvious honest meaning, and take it.

| Kind | Invariant | What it refuses |
|---|---|---|
| `Array` | its length never changes | anything that adds or removes an element: `Add`, `Insert`, `Remove`, `RemoveAt`, `Clear`, `Push`, `Pop` |
| `Set` | no two elements are equal | `Set(I, V)`, where `V` is already an element at some other index |
| `String` | it cannot be modified in place | every mutating method, with `Strings are immutable.` |
| `List` | none | nothing |
| `Stack` | none — LIFO is a discipline, not a structure | nothing |

A `Map` is keyed rather than positional and stands apart from the five: it has
`Get`, `Put`, `Remove`, `Keys`, `Values`, `Clear` and `Contains`, and the
sequence methods do not apply to it.

Two consequences are worth stating, because both are easy to expect the other
way round.

**A harmless synonym is legal.** `K.Add(V)` on a `Stack` means `K.Push(V)`, and
`L.Push(V)` on a `List` means `L.Add(V)`. A `Stack` is last-in-first-out by
discipline rather than by structure, and a `List` has no invariant at all, so
neither has anything to protect. Refusing the second spelling would cost a
reader something and protect nothing.

**A `Set` may be subscripted.** Every collection
[iterates in insertion order](#collection-types), so a `Set` does have positions,
and `S[0]` answers its first element. Reading a position cannot create a
duplicate, so uniqueness is not at risk.

#### Positions on a `Set`

Because a `Set` has positions, the operations that name one can be sent to it,
and uniqueness decides what they mean when the value is already an element.

| Call on a `Set` already containing `V` | Meaning |
|---|---|
| `S.Add(V)`, `S.Push(V)` | nothing happens; `V` keeps the position it has |
| `S.Insert(I, V)` | `V` **moves** to position `I` |
| `S.Set(I, V)` | refused: `Cannot hold two equal elements.` |
| `S.Fill(V)` | every element becomes `V`, so the set collapses to `V` alone |

**An operation that does not name a position does not move anything.** `Add` is
defined that way already, and so is re-assigning a key that a `Map` already
holds — [both keep the original position](#collection-types). `Push` is legal on
a `Set` only because it is a synonym of `Add`, so it inherits that and nothing
else; a `Push` that repositioned would not be a synonym.

**An operation that does name a position honours it.** `Insert(I, V)` asks for
two things — that `V` be an element, and that it be at `I` — and moving it grants
both without endangering uniqueness. This is also the only way a program can
reorder a `Set`, which is worth having.

**`Set(I, V)` is the one that cannot be honoured.** It does not insert, it
*replaces* what is at `I`. Where `V` is already an element at some other index,
the only way to keep uniqueness is to drop that other copy — so a call that
replaces one element would silently shorten the collection. Refusing is the
honest answer, and it is a refusal of that *call* and not of the method: where
`V` is not already an element, `S.Set(I, V)` is an ordinary replacement and
succeeds.

The methods themselves:

| Method | Effect |
|---|---|
| `Add(V)` | appends `V`; on a `Set`, only if no equal element is present |
| `Get(K)` | the element at position `K`, or a `Map`'s value for key `K` |
| `Put(K,V)` | sets a `Map`'s value for key `K` |
| `Set(I,V)` | replaces the element at position `I` |
| `Fill(V)` | replaces every element with `V` |
| `Insert(I,V)` | inserts `V` at position `I`, moving later elements up |
| `RemoveAt(I)` | removes the element at position `I` |
| `Remove(K)` | removes by value, or by key on a `Map` |
| `IndexOf(V)` | the position of the first element equal to `V`, or -1 |
| `Sort()` | orders the elements in place |
| `Clear()` | removes every element |
| `Keys()` | a `Map`'s keys, in insertion order |
| `Values()` | a `Map`'s values, in insertion order |
| `ToList()` | the elements as a `List` |
| `Push(V)` | appends `V` |
| `Pop()` | removes and answers the last element |
| `Peek()` | answers the last element without removing it |
| `Contains(V)` | whether any element is equal to `V` |

`Remove` answers differently by kind: on a `Map` it returns the value removed,
or `nil` if the key was absent; on a `Set` it returns whether there was
anything to remove.

`Keys()`, `Values()` and `ToList()` return a `List`.

> **Not implemented.** No processor applies this rule yet, and the two fail in
> opposite directions. The interpreter enforces a per-kind method table, so the
> harmless synonyms and `S[0]` on a `Set` are refused —
> [issue #41](https://github.com/schildawg/algol24/issues/41). Compiled
> code enforces nothing, so an `Array` can change length and a `Set` can hold
> duplicates — [issue #33](https://github.com/schildawg/algol24/issues/33).

### A `String` is a collection of `Char`

A `String` is a collection like any other, and it answers the collection
members. `S.Length` and `S.IsEmpty` are the properties every collection has;
`S.Contains(C)`, `S.IndexOf(C)`, `S.Get(I)` and `S.ToList()` are the methods
that read without modifying.

```pascal
var S : String := 'hello';

WriteLn (Str (S.Length));           // 5
WriteLn (Str (S.IsEmpty));          // false
WriteLn (Str (S.Contains ('e')));   // true
```

Its invariant is immutability, so every mutating method is refused with
`Strings are immutable.` — the same sentence that already answers an assignment
to a position:

```pascal
S[0] := 'z';                        // Uncaught: Strings are immutable.
S.Add ('z');                        // Uncaught: Strings are immutable.
```

Two notes for a reader.

**`Length (S)` is unaffected** and remains the [function
spelling](#text). This rule says what `.` reaches on a `String`; it does not
restrict what a function may be applied to. `S.Contains (C)` and `C in S` are
likewise two spellings of one thing.

**The unit is the `Char`.** `S.Length`, `Length (S)` and `for C in S` all count
code points, exactly as [`String`](#predeclared-types) is defined to. Any
processor that measures one of them in bytes must measure all three that way or
none.

> **Not implemented.** Neither processor applies this rule —
> [issue #42](https://github.com/schildawg/algol24/issues/42). The interpreter
> rejects the whole dotted form on a `String` with `Only instances have
> properties.`, so `S.Length` and `S.Anything` fail alike. Compiled code answers
> `Length` and `IsEmpty`, refuses the other read-only members as though a
> `String` were not a collection, and refuses the mutating ones with the same
> sentence rather than with `Strings are immutable.`

### Rendering

A collection renders with `[` and `]`, its elements separated by `, `. A `Map`
renders each pair as `key:value`. An empty `Map` renders as `[]`, not `[:]`.
Elements render as `Str` would render them, so an instance with a `ToString`
member uses it.

```pascal
Str([1, 'two', 3.0, nil, True])     // [1, two, 3.0, nil, true]
Str(['a':1, 'b':2])                 // [a:1, b:2]
```

### Buffers

A `Buffer` is growable bytes with an explicit lifetime. `Buffer(N)` creates N
zero bytes; `Buffer()` creates none. `Append(V)` adds text or a character,
`Length` reports the size, and `Text` yields the contents as a `String`.

`Free()` releases the buffer. Using a buffer after `Free()` is a run-time
error, `That Buffer has been freed.`

## Files

`TextFile()` creates a file handle. Its operations follow Turbo Pascal's names,
with the handle as the receiver:

| Operation | Effect |
|---|---|
| `Assign(Name)` | associates the handle with a path |
| `Reset()` | opens for reading |
| `Rewrite()` | creates or truncates, and opens for writing |
| `Append()` | opens for writing at the end |
| `ReadLn()` | reads one line, without its terminator |
| `Write(V)` | writes a value |
| `WriteLn(V)` | writes a value and a newline |
| `Flush()` | flushes buffered output |
| `Close()` | closes the handle |
| `Erase()` | deletes the file |
| `Rename(New)` | renames the file |
| `Eof` | **property**: whether the end has been reached |

A line ends at `#10`, which is not returned. A `#13` immediately before it is
removed with it; any other `#13` is ordinary text. `WriteLn` always writes
`#10` rather than a host-specific separator, so a program writes the same bytes
everywhere.

Failures raise rather than setting a status, and the messages are part of the
observable surface: a failure inside a `try` is catchable as a `String`.

`FileExists(Name)` reports whether a path exists.

## Graphics

`Window(Title, Width, Height)` creates a window and returns a handle to it.
`Width` and `Height` are in pixels and shall be positive; the title is a
`String`. Operations take the handle as the receiver, as a file's do:

| Operation | Effect |
|---|---|
| `Load(Path)` | decodes a picture and returns an `Image` |
| `Clear()` | fills the drawing surface with opaque black |
| `Draw(Image, X, Y)` | places the image with its **top-left corner** at `X, Y` |
| `Present()` | shows what has been drawn |
| `Poll()` | drains pending events; returns `False` once the window should close |
| `Delay(Ms)` | pauses for a number of milliseconds |
| `Pixel(X, Y)` | reads back one pixel of the drawing surface, as `0xRRGGBB` |
| `Close()` | closes the window |
| `Width`, `Height` | **properties**: the size the window was asked for |
| `Open?` | **property**: whether the window is still open |

An `Image` answers the properties `Width` and `Height`, which are the decoded
picture's own dimensions in pixels, and has no operations of its own.

The coordinate origin is the top-left corner of the window, with `X` increasing
rightwards and `Y` downwards. `Draw` does no scaling, clipping to the window
aside, and no layout: an image is placed where it is told.

`Load` shall accept PNG. Other formats are not specified.

**An `Image` belongs to the `Window` that loaded it.** Passing one to a
different window's `Draw` shall raise rather than draw. A program that opens two
windows loads its pictures twice.

`Close()` on an already-closed window succeeds and does nothing, as `Close` on a
file does. Every other operation on a closed window shall raise. A window left
open when the program ends is closed by the processor.

Failures raise rather than setting a status, and the messages are part of the
observable surface: a failure inside a `try` is catchable as a `String`.

### Optional capabilities

**Graphics is the first capability a conforming processor may decline to
provide**, and the rule that makes that safe is that declining changes the
*capability* and never the *language*.

In a processor without graphics:

- `Window` and `Image` remain declared, and remain in scope everywhere;
- a program that uses them parses, resolves, type-checks and compiles exactly as
  it does elsewhere, and the compiled artefact links;
- `Window(...)` raises when **evaluated**, with the sentence
  `Window requires a build with SDL support (-DALG_SDL).`
- that raise is an ordinary run-time error: catchable as a `String`, so a
  program may ask for a window and continue without one.

What a processor shall **not** do is refuse the program, omit the declaration,
or fail to link. Any of those would make the presence of graphics a difference
of dialect rather than of build, and the same source would stop meaning the same
thing.

> The sentence above names a build flag, and so names one implementation. That
> is deliberate rather than an oversight: the message exists to be read by the
> person who has to pass the flag. A processor built on something other than SDL
> shall raise its own equivalent sentence naming its own switch.

### What `Pixel` does and does not promise

`Pixel` exists so that drawing can be tested — without it, a window produces
nothing any suite can compare, and every operation above is unobservable.

Two limits are part of the specification rather than accidents:

- **`Pixel` shall be read before `Present`, not after.** `Present` releases the
  drawing surface to the display, and its contents afterwards are not specified.
- **The value is not portable across processors.** Compositing belongs to the
  host's renderer, and a renderer that blends through a linear colourspace
  returns channels a few steps from the source. A program may compare two pixels
  to each other; it may not assume what either one is. Opaque black, which
  `Clear` writes directly with nothing to blend against, is the one exception.

## Built-in functions

The following are declared in the unit `System` and are in scope everywhere.
Any of them may be shadowed by a program's own declaration, in which case
`System.N` still reaches the built-in.

### Text

| Function | Result |
|---|---|
| `Length(S)` | the number of code points in a `String` |
| `Copy(S, Start, Count)` | the substring of `Count` code points from `Start` |
| `Pos(S, Part)` | the 0-based code-point index of `Part` in `S`, or `-1` |
| `Str(V)` | the rendering of any value as a `String` |

Indices are 0-based. `Copy` clamps its end but not its start: a `Start` outside
`0 .. Length(S)` is a run-time error, while a `Count` running past the end is
truncated.

> **Defective.** `Length` applied to a collection differs between the processors
> — [issue #5](https://github.com/schildawg/algol24/issues/5). Use the `Length`
> **property** on a collection, which agrees.

### Numbers

| Function | Result |
|---|---|
| `Ord(V)` | the code point of a `Char`, or an enumeration member's position |
| `Char(N)` | the character with code point N, which must be a Unicode scalar value |
| `Byte(N)` `Short(N)` `Integer(N)` `Long(N)` | conversion to that integer type; a run-time error if the value does not fit |
| `Single(N)` `Double(N)` | conversion to that floating-point type |
| `Round(X)` | the nearest integer to a number, halves away from zero |
| `Val(S)` | the numeric value of a `String`, always a `Double` |
| `Max(A, B)` | the greater of two `Integer`s |
| `Mod(A, B)` | the remainder of two `Integer`s, signed as the dividend |
| `clock()` | seconds since the epoch, at millisecond resolution |

`Ord` requires a single character or an enumeration member; `Ord('12')` is a
run-time error. `Val` always yields a `Double`, so `Val('12')` is `12.0`.
`Max` and `Mod` are defined only on `Integer`s.

### Output

| Function | Effect |
|---|---|
| `Write(V)` | writes a value |
| `WriteLn(V)` | writes a value and a newline |

### Constructors

`List()`, `Map()`, `Set()`, `Stack()`, `Array(N)`, `Buffer([N])`, `TextFile()`,
`Window(Title, Width, Height)`.

`Window` is an [optional capability](#optional-capabilities) and is declared
even where it cannot be provided.

### Files and command line

`FileExists(Name)`, `ParamCount()`, `ParamStr(I)`.

**`ParamStr(0)` names the program**, and `ParamCount()` does not count it, so
`ParamStr(1)` is the first argument the program was actually given. That is
Turbo Pascal's convention.

What *names the program* means depends on what is running it:

| | `ParamStr(0)` |
|---|---|
| interpreted | the path of the source file being run |
| compiled | the path of the running executable |

The argument vector a program sees is its own and not its host's. An interpreter
is invoked as `algc Prog.a24 alpha beta`, and a program run that way sees a
`ParamCount()` of 2 with `alpha` at index 1 — the interpreter and the source
file are both already behind it. Answering the interpreter's own path at index 0
would break that at exactly one position, letting a program see its arguments
correctly while seeing *itself* as something else.

**The two answers are not byte-identical, by design.** One is a source path and
one is a binary path, and no arrangement makes them the same string. A program
that prints `ParamStr(0)` therefore produces different output under the two
processors legitimately, and cannot be compared across them — the same class of
thing as [a pixel's value](#what-pixel-does-and-does-not-promise).

> **Unspecified.** Whether the path is absolute or normalised, and what
> `ParamStr(0)` answers where no source file was named — an interpreter invoked
> with no arguments at all, or under a test run.

### Assertions

`AssertTrue(V)`, `AssertEqual(Expected, Actual)`, `Fail(Message)`. See
[Test blocks](#test-blocks).

## Program execution

A program is executed by running its file-scope declarations and statements.

**In source order.** A `begin … end` block written at file scope is an ordinary
compound statement, executed where it stands. It is not a main block held back
until the declarations around it have run, and a file may contain any number of
them.

```pascal
WriteLn ('A');
begin WriteLn ('B'); end
WriteLn ('C');
begin WriteLn ('D'); end
WriteLn ('E');
```

prints `A B C D E`.

The same rule covers a **module**, with no addition: a `begin … end` block in a
module runs at that module's own initialisation, in source order among that
module's file-scope statements. A program's imports are fully initialised, in
dependency order, before any file-scope statement of the importing file runs.

A program with one `begin … end` block written last — the conventional shape,
and the one every program in this repository has — cannot tell the difference.

> **Not implemented.** Compiled code collects the contents of every
> `begin … end` block and runs them after all other file-scope statements, so
> the program above prints `A C E B D` —
> [issue #39](https://github.com/schildawg/algol24/issues/39).

Execution terminates when the last statement completes, or when a raised value
reaches the top uncaught. There is no early-exit statement at file scope.

The exit status is 0 on normal completion and 70 when a value is raised and not
caught, including a failed assertion under a test run.

---

# Open decisions

**None. Every question this section held has been settled**, and each answer has
moved into the body of the document above.

An open decision was a question the language had not answered: a rule admitting
more than one coherent reading, where more than one answer was defensible, so
this document declined to state one. Seven were recorded here. Six were settled
by a ruling; the seventh — `Type mismatch!` carrying no source position — was
reclassified as a defect, because no reading of the language made a diagnostic
without a position the intended behaviour. Each ruling's reasoning is kept in
[the issue that records it](https://github.com/schildawg/algol24/issues?q=label%3Adecision).

That is the distinction from [Known defects](#known-defects), which is not empty
and will not be for some time. A defect needs no decision — the language
determines the answer and a processor gets it wrong. An open decision could not
be fixed, only settled.

**What this means for the release.** The first release is the point at which
this document says what it should say and the implementations do what it says.
With nothing left open, the first half is no longer waiting on a decision: what
stands between here and 1.0 is work rather than questions. A rule stated above
with no issue pointer beside it is one both processors are expected to honour
today; every other rule names the issue that is closing the gap.

---

# Areas not covered

The following were not probed and are not specified here. They are neither
decisions nor defects: nothing in the language depends on them today, and a
program that relies on one is relying on a particular processor.

- concurrency: no construct in the language creates or synchronises threads;
- the precise rounding and shortest-round-trip rules for rendering a `Double`,
  beyond the observation that large magnitudes render in `E` notation
  (`1.0E8`, `1.2345678901234568E20`);
- the search path for `uses` beyond the observation that a module is looked for
  relative to the importing file and then the working directory;
- the ordering guarantees of `Sort()` for mixed-type elements;
- the interaction of `Buffer.Free()` with buffers still referenced elsewhere.

---

# Future directions

The entries below are intended work that this document does not yet specify.

**They do not block the first release**, and that is what separates them from
[Open decisions](#open-decisions). An open decision is a question the language
must answer before it can be said to mean anything definite; a future direction
is a capability the language does not have yet and will be no less coherent
without. Nothing here should be read as a promise about when.

## A foreign function interface

**Every native capability the language gains today costs an edit to the
compiler.** [Graphics](#graphics) is the worked example, and its shape is the
argument: adding one window type touched the runtime, the interpreter's table of
native functions, a wrapper module, the emitter's constructor table, and the
root module's `uses` clause — and then required the bootstrap to be reseeded
**twice**, because the compiler's own source cannot call a built-in that the
checked-in seed does not yet know how to emit.

That is an acceptable price once. It is the wrong price per capability, and the
capabilities are foreseeable: sound, sockets, a clock with more resolution than
`clock`, a process launcher, a database client. Under the present arrangement
each is a compiler release, each enlarges the surface every processor must
implement to conform, and each makes the specification longer without making the
language more expressive.

**The intended answer is a foreign function interface**, so that a capability
becomes a library that a program imports rather than a built-in the compiler
carries. The graphics surface should become the first consumer of it, and should
stop being privileged, once it exists.

Four constraints follow from the rest of this document and any design has to
meet all of them:

1. **One implementation, reached by both processors.** The interpreter and the
   compiled program must call the same foreign code. This is already how
   `TextFile` and `Window` work, and it is why a differential test of either
   cannot distinguish the two halves — the arrangement is a feature, but it puts
   the burden of correctness on tests that reach the foreign side directly.
2. **A declaration the front end can see.** Overload resolution, the declaration
   rule and the type checker all operate before either back end runs, so a
   foreign function must present a signature statically, not merely a symbol to
   be found at run time.
3. **Absence must remain a run-time refusal.** The rule in
   [Optional capabilities](#optional-capabilities) generalises: a program that
   names a foreign function the host cannot provide must still parse, check and
   link, and must fail only when it evaluates the call. A missing library that
   turns into a static error turns a build difference into a dialect.
4. **The default build must stay dependency-free.** A C compiler is the only
   thing required to build a processor from the checked-in seed, and an FFI must
   not change that for a program that uses no foreign function.

> **Open question.** Whether the interface binds C symbols directly — names,
> signatures and a link flag — or goes through a narrow host-provided capability
> registry that a processor implements for itself. The first is more expressive
> and ties the language to C's calling convention; the second keeps the
> specification implementable by a processor that is not built on C, which the
> intended bytecode VM will not be.

# Known defects

The following are **not** open decisions. In each the language determines an
answer and a processor gets it wrong, so they are tracked as issues and
reproduced in
[`tests/defects/`](https://github.com/schildawg/algol24/tree/main/tests/defects)
rather than described here — a specification that doubles as a bug list goes
stale the first time a fix lands without an edit.

They are listed because each makes some rule stated above unreliable today, and
a reader is entitled to know which.

| Issue | The rule it makes unreliable |
|---|---|
| [#1](https://github.com/schildawg/algol24/issues/1) | Identifiers are case-sensitive, where the language intends them not to be. Affects every surface that names a declared entity. |
| [#2](https://github.com/schildawg/algol24/issues/2) | `!` and Unicode letters are refused, though [Identifiers](#identifiers) admits them. Carries the mangling scheme a fix needs. |
| [#3](https://github.com/schildawg/algol24/issues/3) | Two enum members can emit one C symbol, so an unqualified member can evaluate to the wrong one. Silent: nothing refuses it. |
| [#4](https://github.com/schildawg/algol24/issues/4) | An unresolved name — undeclared, out of scope, or reached past a non-transitive `uses` — is a catchable error interpreted and invalid C compiled. |
| [#5](https://github.com/schildawg/algol24/issues/5) | The `Length` built-in measures a collection's rendering rather than counting it, so `Length([1, 2])` is `6` interpreted. Use the property. |
| [#6](https://github.com/schildawg/algol24/issues/6) | A `String` is a sequence of **bytes**, not code points. `Length('héllo')` is `6`, `'héllo'[1]` is half of `é`, and `Char` is capped at `127` while indexing yields values above it. |
| [#7](https://github.com/schildawg/algol24/issues/7) | No widening is implemented. `'A' = Str('A')` is `False`, `var D : Double := 1` is rejected, and text has no order. Also: a one-code-point `test` name does not parse. |
| [#8](https://github.com/schildawg/algol24/issues/8) | An integer literal too large for `Integer` is silently truncated: `10000000000` reads as `1410065408`. |
| [#9](https://github.com/schildawg/algol24/issues/9) | `Byte`, `Short`, `Long` and `Single` do not exist, and neither do the numeric conversion functions or `Round`. |
| [#10](https://github.com/schildawg/algol24/issues/10) | No hexadecimal, octal or binary literals, no exponent, and no `_` digit separator. Each scans as a number followed by an identifier. |
| [#11](https://github.com/schildawg/algol24/issues/11) | A top-level function cannot be overloaded, though a method can. |
| [#12](https://github.com/schildawg/algol24/issues/12) | Overload resolution is first-declared-wins; reordering two declarations changes which one a call runs. |
| [#13](https://github.com/schildawg/algol24/issues/13) | A call matching no signature is refused interpreted and runs anyway compiled. |
| [#14](https://github.com/schildawg/algol24/issues/14) | Only `List` takes an element type, only on a variable declaration, and a wrongly typed write is never refused. |
| [#15](https://github.com/schildawg/algol24/issues/15) | Parameters have no defaults, and an argument cannot name its parameter with `=>`. |
| [#16](https://github.com/schildawg/algol24/issues/16) | No variadic parameters and no spread argument; `...` is not a token. |
| [#17](https://github.com/schildawg/algol24/issues/17) | A type name cannot be qualified by its unit, though a value can. |
| [#18](https://github.com/schildawg/algol24/issues/18) | Two units cannot export the same name; the collision is refused rather than resolved by qualification. |
| [#19](https://github.com/schildawg/algol24/issues/19) | No `continue`, no statement labels, no labelled `break`, and no `goto`. |
| [#20](https://github.com/schildawg/algol24/issues/20) | The `constructor` keyword is decorative; the name `Init` decides. Constructors do not overload interpreted, and cannot be named at a call. |
| [#21](https://github.com/schildawg/algol24/issues/21) | A constructor invoked on an existing instance yields the instance interpreted and `nil` compiled. |
| [#22](https://github.com/schildawg/algol24/issues/22) | A wrong-arity call is not checked when compiled. `Expected 3 arguments but got 1.` is a [run-time error](#run-time-errors) that compiled code does not raise: the call returns an answer and the program exits 0. |
| [#27](https://github.com/schildawg/algol24/issues/27) | A wrong-arity call to a *collection* method segfaults compiled code rather than raising. |
| [#28](https://github.com/schildawg/algol24/issues/28) | Inference stops short of what the program determines, so [`Any`](#any-and-the-absence-of-a-type) appears in 285 places in the compiler's own source where the type is deducible. Every annotation downstream of one silently stops being checked. |
| [#29](https://github.com/schildawg/algol24/issues/29) | Subscripting a value that has no positions raises a different sentence in each processor. |
| [#32](https://github.com/schildawg/algol24/issues/32) | [Assignability](#assignability) is symmetric — an `Any` is accepted where a type is declared — and of the five paths only a declaration is checked strictly at all. |
| [#33](https://github.com/schildawg/algol24/issues/33) | Compiled code enforces no [invariant](#method-sets): an `Array` can change length and a `Set` can hold duplicates, after which `Remove` answers `true` and `Contains` stays true. |
| [#37](https://github.com/schildawg/algol24/issues/37) | `Type mismatch!` is the one [static error](#static-errors) that reports no file, line or caret, and it names neither of the two types. |
| [#39](https://github.com/schildawg/algol24/issues/39) | Compiled code defers every `begin … end` block to the end of the program, so [file-scope execution](#program-execution) is not in source order. |
| [#40](https://github.com/schildawg/algol24/issues/40) | An uncaught *built-in* error prints without the `Uncaught: ` prefix when compiled, though [Errors](#errors) states one form for both. |
| [#41](https://github.com/schildawg/algol24/issues/41) | The interpreter enforces a per-kind method table rather than [each kind's invariant](#method-sets), so `Stack.Add`, `List.Pop` and `S[0]` on a `Set` are refused. |
| [#42](https://github.com/schildawg/algol24/issues/42) | A [`String` does not answer the collection members](#a-string-is-a-collection-of-char). The interpreter refuses the whole dotted form; compiled code answers two of them and refuses the rest with the wrong sentence. |

`tests/defects/README.md` is the offline index, for a copy of the repository
with no network.
