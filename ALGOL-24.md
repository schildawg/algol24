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

Two consequences a reader should know:

- Some rules here are not yet true of any processor. Every one of them names the
  issue that says so — see [Known defects](#known-defects). A rule with no such
  pointer is one both processors are expected to honour today.
- [Open decisions](#open-decisions) lists questions the language has not yet
  answered. Each is a decision to be made rather than a permanent gap, and each
  blocks the first release. A program whose meaning depends on one is not
  portable, and will not become portable by itself.

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
const       constructor do          else        end         except
exit        false       for         function    if          in
is          nil         not         object      of          or
print       private     procedure   public      raise       super
then        this        true        try         type        uses
var         while
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
int_lit = decimal_digit { decimal_digit } .
```

An integer literal has type `Integer`. There is no sign in the literal itself;
`-1` is the unary operator `-` applied to `1`. There is no base prefix and no
digit separator.

### Floating-point literals

```
float_lit = decimal_digit { decimal_digit } "." decimal_digit { decimal_digit } .
```

A floating-point literal has type `Double`. A fractional part is what makes a
literal a `Double`, and it is recognised only when a digit follows the `.`;
`1.` is the integer `1` followed by the `.` operator.

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
Type     = TypeName .
TypeName = identifier .
```

There is no type syntax beyond a name: a type is always written as a single
identifier. The one exception is the element-type annotation on a variable
declaration, `List of T`, described under
[Variable declarations](#variable-declarations).

### Predeclared types

```
Boolean  Integer  Double  Char  String  Any
```

- **`Boolean`** has values `True` and `False`.
- **`Integer`** is a signed 32-bit two's-complement integer. Overflow wraps:
  `2147483647 + 1` is `-2147483648`. Overflow is not an error.
- **`Double`** is a double-precision binary floating-point number. Division by
  zero yields an infinity rather than an error.
- **`Char`** is a single Unicode scalar value: a code point in 0 through
  1114111, excluding the surrogate range 55296 through 57343. `'a'`, `'é'` and
  `'😀'` are each one `Char`.
- **`String`** is a sequence of `Char`, indexed from 0. Its length, its indices
  and every operation on it are counted in **code points**. How a processor
  stores a `String` is its own affair and is not observable; in particular a
  program cannot see the UTF-8 encoding of its own source.

**Neither processor implements this.** Both treat a `String` as bytes; see
[issue #6](https://github.com/schildawg/algol24/issues/6). A program restricted
to characters 0 through 127 cannot tell the difference, which is why the
compiler compiles itself under the current behavior.
- **`Any`** is the type of a value whose type is not stated.

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

### Assignability

A type `Actual` is *assignable* to a declared type `Expected` when any of the
following holds:

- either type is unknown or is `Any`;
- `Actual` is the type of `nil`;
- the two are the same type;
- `Actual` **widens** to `Expected`;
- `Actual` is a class that inherits, directly or transitively, from `Expected`.

The static type of an expression is *unknown* when the checker cannot deduce
it — for example when it reads a variable or parameter that was declared
without a type annotation.

**One relation, everywhere.** Assignability governs every place a value meets a
declared type: a declaration's initializer, an assignment, an argument bound to
a parameter, a value returned against a declared result type, and a field
against its declaration. A processor rejects a program only when no run-time
value could make it succeed.

### The declaration rule

Assignability alone governs **assignment** to an existing variable. A
**declaration with an explicit type** is checked by a stricter rule: the
initializer's static type must be known, must not be `Any`, and must be
assignable to the declared type.

The practical effect is an asymmetry that a program must be written around:

```pascal
function F (X);                     // X has no declared type
var
    B : String := X;                // ILLEGAL: X's static type is unknown
begin
    var C : String := 'aa';
    C := X;                         // legal: assignment, not declaration
    Exit C;
end
```

The rule applies whatever the declared type is, including `Any`:

```pascal
var X := 1;
begin
    var B : Any := X;               // ILLEGAL, although Any accepts everything
    var C : Any := 1;               // legal: the literal's type is known
end
```

This is recorded as [an open decision](#the-declaration-rule-versus-assignability):
the two rules are not obviously meant to differ, and the declaration rule
contradicts the general treatment of `Any` elsewhere in the language. Note that
the same asymmetry already exists between a declaration and a **parameter**: a
`Char` argument is accepted for a `String` parameter, while the equivalent
declaration is rejected.

### Inference

A declaration without a type annotation takes no declared type. Its static
type is unknown when it is later read, even where an initializer would appear
to determine it — which is what makes the second example above illegal.

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

> **Open decision.** A program containing both top-level statements and a
> `begin … end` block, or more than one such block, executes its parts in a
> different order under the two processors. See
> [Order of top-level execution](#order-of-top-level-execution). A program with
> at most one `begin … end` block, placed last, is unaffected.

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

**`List of T`** annotates a variable's element type. It is used for checking
only: it makes an element read from the variable reduce to `T`, and it does not
restrict what may be stored in the collection at run time.

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
Parameter     = identifier [ ":" Type ] .
Block         = "begin" { Statement | Declaration } "end" .
```

Parameters are comma-separated and are typed individually; a parameter without
an annotation has no declared type. A `function` may declare a result type; a
`procedure` may not. Both may be called for their value, and a `procedure`
yields `nil`.

There are no default arguments and no variadic parameters. Calling with the
wrong number of arguments is a run-time error, catchable as a `String`:
`Expected 1 arguments but got 0.`

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

**Top-level functions may not be overloaded.** Declaring two functions of the
same name at file scope is a static error, `'F' is already defined.`, whatever
their signatures. Methods may be overloaded; see
[Method overloading](#method-overloading).

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
- The constructor is named `Init` by convention in all observed code; a
  constructor is selected for a call by its signature like any other member.

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

Members overload on their **whole signature**, not on arity alone: a class may
declare two members of one name each taking one argument that differ only in
the declared parameter type. Selection happens when the call is made, using
the run-time types of the arguments.

```pascal
function Take (N : Integer) : String; begin Exit 'int'; end
function Take (S : String)  : String; begin Exit 'str'; end
```

A failed match in a subclass falls through to the superclass, so declaring
`Take(String)` in a subclass does not hide an inherited `Take(Integer)`.

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
**exports only**, so it is not a way around `private`.

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
Arguments   = "(" [ Expression { "," Expression } ] ")" .
```

**Selectors** read a field, a property, or a member of the value on the left.
An unknown name is a run-time error, `Undefined property 'N'.`

**Index** reads by position from a `String`, `List`, `Array` or `Stack`, and by
key from a `Map`. String and sequence indices are 0-based and are bounds
checked: `Index 9 out of range 0..4.` Indexing a `String` yields a `Char`, and
the index counts **code points**, so `'héllo'[1]` is `'é'` and never a fragment
of one. A
`Set` has no positions and cannot be indexed
([an open decision](#collection-method-sets)).

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
Statement = Block | VarDecl | ConstDecl | ExpressionStmt | AssignStmt
          | IfStmt | WhileStmt | ForStmt | ForInStmt | CaseStmt
          | BreakStmt | ExitStmt | RaiseStmt | TryStmt | PrintStmt .
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

### Break statements

```
BreakStmt = "break" ";" .
```

`break` leaves the innermost enclosing loop. There is no label and no
`continue`.

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

> **Unspecified.** The diagnostic for a type mismatch carries no source
> position, which makes it hard to locate in a large file. Other static errors
> report a line and a caret.

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

An uncaught error terminates the program with status 70.

> **Unspecified.** An uncaught *built-in* run-time error is printed as
> `Uncaught: <message>` by the interpreter and as bare `<message>` by compiled
> code. An uncaught *raised value* is printed as `Uncaught: <value>` by both.

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

The method available on each kind:

| Method | List | Array | Map | Set | Stack |
|---|:--:|:--:|:--:|:--:|:--:|
| `Add(V)` | ● | | | ● | |
| `Get(K)` | ● | ● | ● | | |
| `Put(K,V)` | | | ● | | |
| `Set(I,V)` | | ● | | | |
| `Fill(V)` | | ● | | | |
| `Insert(I,V)` | ● | | | | |
| `RemoveAt(I)` | ● | | | | |
| `Remove(K)` | | | ● | ● | |
| `IndexOf(V)` | ● | ● | | | |
| `Sort()` | ● | | | | |
| `Clear()` | ● | | ● | ● | ● |
| `Keys()` | | | ● | | |
| `Values()` | | | ● | | |
| `ToList()` | | | | ● | |
| `Push(V)` | | | | | ● |
| `Pop()` | | | | | ● |
| `Peek()` | | | | | ● |
| `Contains(V)` | ● | ● | ● | ● | ● |

`Remove` answers differently by kind: on a `Map` it returns the value removed,
or `nil` if the key was absent; on a `Set` it returns whether there was
anything to remove.

`Keys()`, `Values()` and `ToList()` return a `List`.

> **Open decision.** This table is the set the interpreter enforces. Compiled
> code shares one representation across `List`, `Array`, `Set` and `Stack` and
> accepts most sequence methods on any of them — `L.Remove(2)`, `A.Insert(0,9)`,
> `K.Sort()` and many others succeed compiled and are rejected interpreted. See
> [Collection method sets](#collection-method-sets). A program should use only
> the table above.

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

`List()`, `Map()`, `Set()`, `Stack()`, `Array(N)`, `Buffer([N])`, `TextFile()`.

### Files and command line

`FileExists(Name)`, `ParamCount()`, `ParamStr(I)`.

`ParamStr(0)` is the program itself and `ParamCount()` does not count it.

> **Unspecified.** What `ParamStr(0)` contains differs between the
> processors: the interpreter reports the source file name, and compiled code
> reports the path of the executable.

### Assertions

`AssertTrue(V)`, `AssertEqual(Expected, Actual)`, `Fail(Message)`. See
[Test blocks](#test-blocks).

## Program execution

A program is executed by running its file-scope declarations and statements.

Execution terminates when the last statement completes, or when a raised value
reaches the top uncaught. There is no early-exit statement at file scope.

The exit status is 0 on normal completion and 70 when a value is raised and not
caught, including a failed assertion under a test run.

---

# Open decisions

The entries below are questions the language has not yet answered. In each, the
two processors are observed to disagree or a rule admits more than one coherent
reading, and more than one answer is defensible — so this document does not yet
state one.

**These are decisions to be made, not gaps to be documented.** Each resolves by
choosing what the language means; the choice then moves into the body of this
document, the implementations are made to match, and the entry disappears. Every
entry here blocks the first release.

That is what separates them from [Known defects](#known-defects). A defect needs
no decision — the language already determines the answer and a processor gets it
wrong. An open decision cannot be fixed, only settled.

Each was reproduced under both processors. Where one reading seems better, this
document says which and why, without treating that as the answer.

## Order of top-level execution

A program may contain both statements at file scope and one or more
`begin … end` blocks. The two processors run them in different orders.

```pascal
WriteLn('A');
begin WriteLn('B'); end
WriteLn('C');
begin WriteLn('D'); end
WriteLn('E');
```

The interpreter prints `A B C D E` — source order. Compiled, the program prints
`A C E B D`: the contents of every `begin … end` block are collected and run
after all other file-scope statements.

A program with at most one `begin … end` block, written last, is unaffected,
and that is the conventional form.

**The choice.** Either `begin … end` is a *main block* deferred until the
declarations and initialisers around it have run, or it is an ordinary
compound statement executed in place. Both readings are consistent with the
conventional form; the language does not say which is meant.

**Recommendation.** Source order — a `begin … end` block is an ordinary
compound statement. It is what the interpreter already does, it is what the
text looks like it means, and a deferred block is hard to explain once a
program has two of them. The compiled path would change.

## The declaration rule versus assignability

A declaration with an explicit type requires its initializer's static type to
be *known and not `Any`*, while an assignment to the same variable requires
only [assignability](#assignability), under which unknown and `Any` are
accepted from either side.

```pascal
function F (X);                     // X is untyped
var
    B : String := X;                // rejected
begin
    var C : String := 'aa';
    C := X;                         // accepted
end
```

The rule holds even when the declared type is `Any`, so `var B : Any := X;` is
rejected although no assignment to `B` could fail.

**The choice.** Either the strictness is deliberate — a written type
annotation is a demand that the initializer's type be *proved*, not merely
*permitted* — or the declaration path is meant to use the same assignability
relation as everything else and does not. Nothing else in the language treats
`Any` as a failure, which favours the second reading; but the check is explicit
and hard to arrive at by accident, which favours the first.

**Recommendation.** The second — one assignability relation everywhere. Gradual
typing exists so that an unannotated value can flow into an annotated one, and
the current rule rejects `var B : Any := X`, where no assignment to `B` could
ever fail. A rule that rejects a declaration whose every subsequent use would be
accepted is hard to justify to the person who wrote it.

## Collection method sets

The interpreter enforces a per-kind method table. Compiled code shares one
representation across `List`, `Array`, `Set` and `Stack`, and accepts most
sequence methods on any of them.

```pascal
begin
    var L := [1, 2, 3];
    WriteLn(Str(L.Remove(2)));      // compiled: true, and L becomes [1, 3]
                                    // interpreted: Undefined property 'Remove'.
end
```

Calls accepted compiled and rejected interpreted include `Remove`, `ToList`,
`Push`, `Pop`, `Peek`, `Fill` and `Set` on a `List`; `Remove`, `RemoveAt`,
`Insert`, `Clear`, `ToList`, `Push`, `Pop` and `Peek` on an `Array`; `Insert`,
`IndexOf`, `Sort`, `Push` and `Fill` on a `Set`; and `Add`, `Remove`, `Insert`,
`IndexOf`, `Sort`, `ToList` and `Fill` on a `Stack`.

Subscripting divides the same way. A `Set` has no positions, and `S[0]` is a
run-time error interpreted — `Subscript target should be an ordinal.` —
while compiled it returns an element.

**The choice.** Either the kinds are genuinely distinct types with distinct
operations, and the shared compiled representation is an implementation detail
that leaks; or they are one sequence type with conventional restrictions, and
the interpreter's table is the enforcement. The `Remove` case argues for the
first: it is specified to answer *different things* on a `Map` and a `Set`,
which is a type distinction rather than a restriction.

**Recommendation.** Distinct kinds, with the table above as the rule. `Remove`
settles it — one name cannot mean two things on one type — and the compiled
path's permissiveness is a shared representation showing through rather than a
decision anyone made.

## Properties on a string

The two processors disagree about whether a string answers `Length` and
`IsEmpty` as properties.

```pascal
var S : String := 'hello';

WriteLn (Str (Length (S)));     (* 5 under both *)
WriteLn (Str (S.Length));       (* interpreted: raises; compiled: 5 *)
WriteLn (Str (S.IsEmpty));      (* interpreted: raises; compiled: false *)
```

The interpreter raises `Only instances have properties.`; compiled code answers.
The function form `Length (S)` agrees under both and is the portable spelling.

**The choice.** Neither answer is absurd. Against the property form: a string is not a
collection, `Length (S)` already exists and is the documented spelling for it,
and admitting it adds a second way to spell one thing. For it: `Length` and
`IsEmpty` are properties on all five collections, a string is indexable and
sliceable like one, and a reader who has learned `L.Length` has no way to
predict that `S.Length` is different in kind.

**Recommendation.** Allow them. The language already treats a string as a
sequence — `S[0]`, `Copy`, `Pos`, `in` — and the cost of the restriction falls
on every reader who has to remember it, while the cost of lifting it falls once
on the interpreter. `Length (S)` keeps working either way.

Note that the failure is not a *property* error but `Only instances have
properties.` — the interpreter rejects the whole dotted form on a string rather
than rejecting these two names on it, so the same message answers `S.Anything`.

## Uncaught error reporting

An uncaught error raised by a *built-in* prints as `Uncaught: <message>` under
the interpreter and as a bare `<message>` compiled. An uncaught value raised by
a program's own `raise` prints as `Uncaught: <value>` under both. Exit status
is 70 in every case.

## `ParamStr(0)`

The interpreter reports the source file name; compiled code reports the path of
the running executable. `ParamCount()` agrees, counting neither.

## Static diagnostics without position

`Type mismatch!` carries no file, line or caret, unlike the other static
diagnostics. In a file of any size the failing declaration must be found by
bisection. This is a quality-of-diagnostic gap rather than a semantic
ambiguity, but it is the one most likely to be met.

## Areas not covered

The following were not probed and are not specified here:

- concurrency: no construct in the language creates or synchronises threads;
- the precise rounding and shortest-round-trip rules for rendering a `Double`,
  beyond the observation that large magnitudes render in `E` notation
  (`1.0E8`, `1.2345678901234568E20`);
- the search path for `uses` beyond the observation that a module is looked for
  relative to the importing file and then the working directory;
- the ordering guarantees of `Sort()` for mixed-type elements;
- the interaction of `Buffer.Free()` with buffers still referenced elsewhere.

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

`tests/defects/README.md` is the offline index, for a copy of the repository
with no network.
