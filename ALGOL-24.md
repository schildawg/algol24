# Algol-24 — Language Reference

The language implemented by this repository. Pascal-flavored in its keywords and block structure, but the semantics are closer to a dynamically-typed scripting language with optional type annotations. Anything below marked ⚠️ is a place where the implementation does not behave the way the syntax suggests it should; those are collected with root causes in [Rough Edges](#rough-edges).

Running a program:

```bash
java -jar target/jpascal.jar Program.a24          # run it
java -jar target/jpascal.jar --test Program.a24   # run its test blocks
```

A program's imports resolve beside it, so it can be run from anywhere — see [Modules](#modules--uses).

---

## The language in one page

Algol-24 is a **dynamically typed, garbage-collected, object-oriented scripting language** wearing Pascal's keywords. It is executed by a tree-walking interpreter on the JVM — there is no compilation step, no manual memory, and no pointers.

Types are **optional and gradual**. An unannotated declaration is `Any` and unchecked; an annotated one is verified before the program runs. `Any` means "not known" and is compatible with everything, so adding annotations can only ever add checking — never break working code.

```pascal
type Suit = (Hearts, Spades);

const LIMIT := 3;

class Card;
var
   Rank : Integer;
   Kind : Suit;

begin
   constructor Init(Rank, Kind);
   begin
      this.Rank := Rank;
      this.Kind := Kind;
   end

   function Describe() : String;
   begin
      Exit Str(Rank) + ' of ' + Str(Kind);
   end
end

object Deck;                       // a singleton, reached by name
var
   Cards : List := [];

begin
   procedure Put(Each);
   begin
      Cards.Add(Each);
   end
end

function Described(Cards : List) : List;
var
   Result := [];

begin
   for var Each in Cards do
      Result.Add(Each.Describe());

   Exit Result;
end

begin
   for var Rank := 1; Rank <= LIMIT; Rank := Rank + 1 do
      Deck.Put(Card(Rank, Spades));

   for var Line in Described(Deck.Cards) do
      WriteLn(Line);

   const Faces := Set([11, 12, 13]);
   WriteLn('11 is a face card: ' + Str(11 in Faces));

   try
      raise 'a String';
   except
      on E : String do WriteLn('caught ' + E);
   end
end
```

### Coming from Pascal

The keywords are familiar; much of the grammar is not.

| | Pascal | Algol-24 |
|---|---|---|
| Statement `;` | separator — none before `end` or `else` | **terminator** — one after every statement |
| Counted loop | `for I := 1 to 10 do` | `for I := 1; I <= 10; I := I + 1 do` |
| Return | assign to the function name | `Exit Value;` |
| Parameters | `(A, B: Integer; C: String)` | `(A : Integer, B : Integer)` — commas, each typed |
| Instantiation | `New(P)` / constructors | `Card(1, Spades)` — no `new` |
| Inheritance | `class(Parent)` in a type | `class Dog(Animal);` |
| `[1, 2]` | a **set** | a **list** — sets are `Set([1, 2])` |
| `{ ... }` | a comment | not supported; comments are `//` |
| Strings | 1-based indexing | **0-based** |

### Coming from Java or Kotlin

Much closer than the Pascal costume suggests. Semicolons terminate, `for` is C-style, `final` is spelled `const`, and `object` is Kotlin's singleton declaration. The differences that will catch you:

- `=` is equality and `:=` is assignment. There is no `==`.
- `and` / `or` / `not` bind **looser** than comparison, so `A = B and C = D` needs no parentheses.
- `/` is integer division when both operands are integers — `7 / 2` is `3`.
- Exceptions carry any value, not just a class: `raise 'a message';` is normal.
- Blocks are `begin ... end`, and a branch body is a single statement unless you open one.
- Declarations are statements, so `var` and `const` are legal anywhere — inside a `try`, an `if` branch, a loop body.

### What it has

Classes with single inheritance and `super`; `object` singletons; enums with bare *and* qualified members; first-class and nested functions with closures; `List`, `Map`, `Set`, `Array`, `Stack` with literals for the first two; `for ... in` over any of them; exceptions with type-matched handlers that respect the class hierarchy; a module system; `private:` and `public:` sections in a class; and a test runner built into the language.

### What it does not

No `finally` ([deliberately](#rough-edges)), no generics beyond `List of T`, no interfaces or traits, no operator overloading, no threads, no `continue`, no module namespacing, and no `protected`.

---

## 1. Lexical structure

### Comments

```pascal
// line comment, runs to end of line
/// doc comment — lexically identical to //, no special handling
```

There is no block comment. Pascal's `{ ... }` and `(* ... *)` are **not** supported — `{` is an unexpected character, and `(*` scans as `(` followed by `*`.

"End of line" means `#10`. `#13` is whitespace, alongside space and tab, and does not end a comment or advance the line count — so a CRLF file behaves exactly as an LF one. The same rule governs reading a file with [`TextFile`](#files).

### Identifiers

Letters, digits, `_`, and `?`, not starting with a digit. `?` is legal in any position, so `IsEmpty?` is one identifier.

⚠️ Compiled, `?` becomes `_q` in the C symbol — `Ready?` is `v_Ready_q` — and that mapping is **not injective**: a scope declaring both `Ready?` and `Ready_q` emits one symbol twice, which the C compiler rejects as a duplicate declaration. It cannot produce wrong code, only a confusing message, and interpreted the same program is fine. Making it injective would mean escaping the escape (`_` → `__`), renaming every symbol in every emitted file.

Identifiers are **case-sensitive**, but **keywords are case-insensitive** (`begin`, `Begin`, and `BEGIN` all scan as `BEGIN`). Property and method lookup on built-in collections is case-insensitive; lookup on user-defined classes is case-sensitive.

### Literals

| Form | Token | Notes |
|---|---|---|
| `42` | `INTEGER` | 32-bit signed, and it **wraps** on overflow rather than trapping or widening |
| `3.14` | `NUMBER` | IEEE 754 double. Requires a digit on both sides — `1.` and `.5` do not scan as reals. ⚠️ No exponent form: `1.0e20` does not scan |
| `'hello'` | `STRING` | Single quotes only |
| `'x'` | `CHAR` | A one-character literal is a **Char**, not a String — see below |
| `''` | `STRING` | Empty string (length 0, so not a Char) |
| `'it''s'` | `STRING` | Doubled quote escapes a quote |
| `#13` | `CHAR` | Character by decimal code point |
| `True`, `False` | — | Booleans |
| `nil` | — | Null |

There are no escape sequences other than `''`. Build control characters with `#10`, `#13`, etc.

#### How a Double prints

The text of a Double is **specified by the language**, not inherited from whatever the implementation is written in — every implementation has to produce the same characters, because that is how they are checked against each other.

- The **shortest digit string that parses back to the same double**. So `0.1` prints as `0.1`, and `0.1 + 0.2` prints as `0.30000000000000004` rather than hiding the difference.
- **Positional** when `10⁻³ ≤ |v| < 10⁷`, **scientific** outside it: `0.001`, `1000000.0`, but `1.0E-4` and `1.23456789123E8`.
- **Always a digit after the point**, so an integral Double reads as `100.0`. `Integer` and `Double` are different types and the output says which one it is.
- `NaN`, `Infinity`, `-Infinity`, and `-0.0` keep their signs and spellings.

This is the same format Python, JavaScript, Rust, Go and Java 19+ arrived at. Note it is *not* Java 17's `Double.toString`, which emits a digit more than necessary on roughly 0.3% of doubles — matching that would have meant reproducing a known-incorrect algorithm whose output changes on a JDK upgrade.

The same value prints identically however it reaches the output — `WriteLn(X)`, `Str(X)`, and `'' + X` all agree. (They did not always: concatenation used to strip the trailing `.0`, so `'' + 2.0` gave `2` while `WriteLn(2.0)` gave `2.0`.)

**Char behaves as a one-character String.** A literal's type still depends on its length, and `Char` is a distinct type from `String` — but that distinction is invisible for the operations that matter. `+` concatenates any mix of Char and String to a String, and builtins declaring a `String` parameter accept a Char, so `Length('a')` and `Copy('a', 0, 1)` work. Subscripting a String yields a Char, which likewise concatenates freely:

```pascal
var S := 'abc';
WriteLn(S[0] + S[1]);   // ab
WriteLn('a' + 'b');     // ab
```

### Operators

| Category | Operators |
|---|---|
| Assignment | `:=` |
| Equality | `=` (equal), `<>` (not equal) |
| Relational | `<`, `<=`, `>`, `>=` |
| Arithmetic | `+`, `-`, `*`, `/` |
| Logical | `and`, `or`, `not` |
| Membership | `in` |
| Type cast | `as` |
| Access | `.`, `[ ]`, `( )` |

`=` is equality; there is no `==`. There is no `mod` or `div` operator — use the `Mod(a, b)` builtin. No `+=`/`-=`, no `++`, and no bitwise operators. `is` tests a value's runtime type — see *Type tests*.

**Numeric promotion.** Mixing `Integer` and `Double` promotes to `Double`, for arithmetic, comparison, and equality alike:

```pascal
WriteLn(1 + 2.5);    // 3.5
WriteLn(1 < 2.5);    // true
WriteLn(1 = 1.0);    // true
```

⚠️ The one exception is `/`, which stays **integer division when both operands are Integer**: `7 / 2` is `3`, while `7.0 / 2` is `3.5`. There is no separate `div`, so force a Double operand when you want a real quotient.

`Char` participates in comparison (`'a' < 'b'`) but not in arithmetic — `'b' - 'a'` is an error, not a code-point subtraction. Use `Ord`, which now genuinely gives the code point: `Ord('b') - Ord('a')` is 1.

⚠️ **`+` on text allocates a fresh string and copies both operands**, so building one up a piece at a time is **quadratic in memory**. Strings are immutable and the runtime frees no individual object, so every intermediate stays live:

```pascal
var S := '';
for var I := 0; I < N; I := I + 1 do
    S := S + 'x';           // retains all N intermediates: ~N²/2 bytes
```

| N | peak memory |
|---|---|
| 5,000 | 13 MB |
| 10,000 | 49 MB |
| 20,000 | 193 MB |
| 40,000 | 770 MB |

Four times the memory for twice the work. This is a property of *both* back ends, but it bites hardest compiled, where nothing is reclaimed at all — under the interpreter the JVM collects the intermediates, so the cost is time rather than a ceiling.

**[`Buffer`](#buffer) is the linear alternative**, and it is why the type exists. It appends in place and grows by doubling, so n appends cost under 2n bytes rather than n²/2:

```pascal
var B := Buffer();
for var I := 0; I < N; I := I + 1 do
    B.Append('x');
var S := B.Text;            // one copy, at the end
```

⚠️ This makes a linear path **available**, not automatic. `S := S + 'x'` in a loop is still quadratic, and there is no `Join` and no n-ary `Concat` — the cost is the loop rather than the expression, so neither would have helped. Making the naive idiom linear needs an explicit length in the string representation, which is a change to every site that makes or reads a string and waits for a reason to reopen it.

**Truthiness.** Four things are false; everything else is true.

| Falsey | Truthy |
|---|---|
| `nil` | every other value |
| `False` | `True` |
| the Integer `0` | any other Integer, **and `0.0`** |
| an enum member whose **ordinal is 0** | any later member |

Two of those catch people out. **`0.0` is truthy while `0` is falsey** — the rule tests Integer and does not look at Double. And **the first member of every enum is falsey**, since the rule reads the member's ordinal, so `if Colour then` is false for the first colour declared and true for the rest. An empty `String`, an empty collection, and any `Char` are all truthy.

This governs `if`, `while`, `not`, and what `and`/`or` short-circuit on.

**`and` and `or` yield an operand, not a boolean**, and short-circuit — so `or` reads as a default and `and` as a guard:

```pascal
WriteLn(nil or 'fallback');    // fallback
WriteLn('kept' or 'unused');   // kept
WriteLn(nil and 'unused');     // nil
WriteLn('left' and 'right');   // right
```

The left operand is evaluated **exactly once**, so an operand with a side effect is safe on either side.

**Membership.** `X in C` tests a `Set`, `List`, `Stack`, `Array`, a `Map`'s keys, a `String`'s substrings, or an enum type's members. It binds with the relational operators, as in Pascal:

```pascal
const Vowels := Set(['a', 'e', 'i', 'o', 'u']);

if C in Vowels then ...
WriteLn('ell' in 'hello');   // true
```

⚠️ Matching is exactly what the collection's own `Contains` does, so it compares by boxed value: `1 in Set([1.0])` is false even though `1 = 1.0` is true.

⚠️ **A one-character literal is a `Char`, and a `Char` is never equal to a `String`.** `'3' = Str(3)` is false. The trap is that both print as `3`, so a failed comparison used to read `Expected '3' but got '3'.` — `AssertEqual` now names the types when the printed forms match, so it reads `Expected Char '3' but got String '3'.` Pascal avoided this by letting a literal adapt to context and promoting `char` to `string` in a comparison; Algol-24 commits the literal at scan time and does not promote.

### Keywords

```
and  as  begin  break  case  class  const  constructor  do  else  end  except
exit  false  finally  for  function  if  in  nil  not  object  of  or  print
private  procedure  public  raise  super  then  this  true  try  type  uses  var
while
```

⚠️ `finally` is scanned as a keyword but **no parser rule implements it** — it reports `'finally' is not supported yet.`

Two words are **context-sensitive** and are matched as identifiers rather than reserved words, so they remain usable as variable names:

- `test` — only when followed by a string literal at the top level (test declaration)
- `on` — only inside an `except` block (exception handler)

---

## 2. Program structure

A source file is a sequence of top-level declarations plus an optional main block:

```pascal
uses Token;              // module imports
type Color = (Red, Green, Blue);

function Double(N : Integer) : Integer;
begin
  Exit N * 2;
end

begin                    // main block — runs top to bottom
  WriteLn(Double(21));
end
```

`begin ... end` at the top level is just a block statement, not a distinguished "main". You can have several; they all run in order.

### Modules — `uses`

```pascal
uses Scanner;      // loads ./Scanner.a24
uses 'Scanner';    // same thing
```

The name resolves to `<name>.a24`, looked for **beside the importing file first**, then in the process working directory. So a directory of related modules can import each other by bare name, and a set of files can be moved together.

**A file sees what it imports, and nothing else.** `uses` is not transitive: if `A` uses `B`, `B`'s exports are visible in `A` alone, and a file that wants them says so itself. Every file declares its own dependencies, including the one the program starts from.

Loading and visibility are separate. A file is **loaded once**, keyed by resolved path, however many files import it — so a diamond runs the shared module a single time and every importer links to that same copy. A second `uses` of an already-loaded file is therefore not a no-op: it loads nothing and grants sight of it.

That separation is what lets the dependency graph have **cycles**, which real ones do — a class names its instances and an instance names its class. Two modules may `uses` each other; a name is looked up when it is used, by which time everything has loaded.

A module that cannot be found reports where it looked:

```
[ERROR] lib/Bad.a24: Could not find module 'Absent': no Absent.a24 in 'lib' or the working directory.
```

`uses` is only recognized at the top level of a file.

#### `private`

Each imported file runs in **an environment of its own**. Everything it declares is handed to the importer except the names marked `private`, which stay reachable only from inside the module that declares them:

```pascal
// Scanner.a24
private var Current := 0;

private function Peek(): Char;      // Scanner.a24 only
begin
    Exit Source[Current];
end

class Scanner;                      // visible to anything that 'uses Scanner'
begin
    ...
end
```

```pascal
// Test.a24
uses Scanner;

var S := Scanner('...');   // fine — exported
var C := Peek();           // Undefined variable 'Peek'.
```

`private` goes in front of a **top-level** declaration — `var`, `const`, `function`, `procedure`, `class`, `object`, or `type`. On a nested one it is an error, since module visibility means nothing inside a block. A private `type` withholds its members too, because enum members bind as bare names as well as qualified ones.

Two modules may each declare a private `Peek` without colliding — that is the point of the feature. Two modules that **export** the same name still collide, which is now a real conflict rather than an accident of file layout:

```
[ERROR] Main.a24: 'Thing' is already defined; mark it private in one of the modules.
```

A module keeps its own environment for the life of the run, and an import is a **link** to it rather than a copy. So a module variable is a single binding wherever it is reached from: a function inside the module and code in three files that import it all read and write the same one.

⚠️ Both privacy and visibility are enforced **at run time**, by the environment chain — reaching a private name, or one from a module this file never imported, reports `Undefined variable` at the point of use. The type checker does not know about module boundaries, so it will not flag either earlier, and the C back end flattens every module into one file and so cannot see them at all. A program that violates visibility is caught interpreted and not compiled; that gap closes when the check moves into the Resolver.

### Units and qualified names

**Every file is a unit, and a unit is named by its file.** `Scanner.a24` is the unit `Scanner`, and a name it exports can be written `Scanner.ScanTokens()` as well as bare. Nothing declares this and nothing needs to: the name is the file's stem, so `uses 'lib/ModA';` gives the unit `ModA`.

**`System` is the unit the built-ins live in.** It is in scope in every file, is imported by nobody, and is the only way back to a name the program has [shadowed](#7-built-ins):

```pascal
function Max (A, B) : String;    // takes the name over for the whole file
begin
    Exit 'mine';
end

begin
    WriteLn (Max (1, 2));           // mine
    WriteLn (System.Max (1, 2));    // 2
end
```

A qualified name is an ordinary expression: call it, pass it, or read a unit's `var` through it.

#### Which one is it?

`A.B` is three tokens whether `A` is a value or a unit, so the question is decided by scope, in the same nearest-binding-first order every other name follows:

1. a **local** or a parameter;
2. a top-level name that **can answer a dot** — an `object`, an enum type, or a file-scope `var`/`const`;
3. a **unit**.

Steps 1 and 2 are what the language already did, so nothing that worked before changes meaning; a unit only ever claims a slot that used to be an error.

**This is why a unit and its own primary class do not collide.** A bare class name has no member access at all — `Thing.Get()` is `Only instances have properties.` — so `class Scanner` inside `Scanner.a24` leaves the dotted form free:

```pascal
Scanner            // the class
Scanner.Scanner    // the same class, through its unit
Scanner.Advance    // a free function in the unit
```

That is the ordinary shape rather than a curiosity: eighteen of the twenty-two units the compiler is written in are a file whose primary class shares its name.

#### `unit Name;`

A file may open with a header naming itself:

```pascal
unit Shapes;    // must be the first thing in Shapes.a24
```

It declares nothing, and qualification works without it. What it buys is a **check**: a file renamed without its header, or a header copied between files, is reported rather than quietly changing which unit a qualified name reaches.

```
[ERROR] Shapes.a24: Unit 'Shape' must match its file name 'Shapes'.
```

`unit` is context-sensitive, like `test` — it is not a keyword and does not stop anything else being called `unit`.

#### What it does not do, and where it bites

- **`private` is respected.** Qualification reaches a unit's *exports*, so it is not a way around visibility. A private or absent name raises `Undefined name 'Peek' in unit 'ModuleHelper'.`, which is catchable like any runtime error, and the compiled program raises the same thing.
- **Qualification is as non-transitive as `uses`.** A file may qualify only the units it imported itself, never the units *those* imported.
- **A unit's `var` can be written through it** — `Vals.Answer := 9` — and reaches the same single binding a bare assignment would. `System` is refused: `Can't assign to 'Max' in unit 'System'.`
- ⚠️ **An `object` or enum type named after its own unit wins, and takes qualification of that unit with it.** `Console.a24` declaring `object Console` means `Console.Write` is the singleton's method — which is what it always was — and nothing in that unit can be qualified. Two of the compiler's own units are shaped this way. The hazard is adding such a declaration *later*: qualified calls that worked then quietly become member lookups on the object, and only fail if it has no member of that name.
- ⚠️ **That check is program-wide, not per file.** An `object Console` anywhere stops *every* file qualifying a unit called `Console`. The over-approximation is deliberate and one-directional: it can only decline to qualify, never change what a name already meant.
- **A unit whose stem is not an identifier cannot be qualified**, and needs no rule to say so — `18-frames.X` is not something you can write.
- ⚠️ **Two files with the same stem in one program** — `algc/Scanner.a24` and `ctest/Lox/Scanner.a24` — resolve their bare names correctly, but the qualified name reaches whichever was imported last. Nothing in the corpus does this.
- ⚠️ **`System.X` as a value is refused by the C back end** — `var F := System.Max;` compiles interpreted and is `'System.Max' as a value` compiled. A built-in is a C function with no closure to stand for it. Qualified *calls* are fine, and so is a user unit's function taken as a value.
- ⚠️ **A built-in the C back end has not implemented is refused at compile time through `System`**, where the bare name is a run-time `Undefined variable`. That is the same asymmetry every unimplemented built-in already has.

---

## 3. Declarations

### Variables

Two different syntaxes exist, and they are **not** interchangeable:

**Statement form** — one variable, legal anywhere a statement is, including single-statement bodies like an `if` branch or a `try` block:

```pascal
var X := 1;
var Y : Integer := 2;
var Z : Integer;
var L : List of Token;     // `of` is only honored when the type is `List`
```

**Section form** — inside a `var` section of a function or class header, allowing comma groups and no repeated `var`:

```pascal
var
  Source : String;
  Current, Start, Line : Integer;
```

A comma group **evaluates its initializer once** and gives every name the result, as `a = b = f()` does in Python or JavaScript. `var A, B, C := Bump();` calls `Bump()` once.

⚠️ One evaluation means one value, so `var A, B := List();` gives both names **the same list**, not two. Declare them separately when you want independent objects.

⚠️ Comma groups exist only in a var section — a function, class, or object header. The statement form `var X := 1;` takes a single name.

Untyped declarations get the type name `Any`, which disables checking for that symbol.

### Constants

`const` declares a binding that cannot be reassigned:

```pascal
const MAX := 100;
const Limit : Integer := 50;

MAX := 5;              // Can't assign to constant 'MAX'.
```

A value is required, since there is no later opportunity to supply one. The initializer is any expression, evaluated once where the declaration runs — not restricted to literals, and not folded at compile time.

**Only the binding is fixed, not the value** — the same rule as `final` in Java or `const` in JavaScript. A constant collection can still be modified, and a field or element of one can be assigned:

```pascal
const Items := List();
Items.Add('ABC');      // fine
Items := List();       // error

const Values := [1, 2, 3];
Values[0] := 99;       // fine
```

Reassignment is rejected before the program runs, so it is caught even in a branch that never executes. A `var` in an inner scope may shadow a `const` and is assignable normally.

`const` also has a **section form** in a function header, alongside `var`, in either order and with comma groups:

```pascal
function Area() : Integer;
const
  WIDTH  := 10;
  HEIGHT := 4;

var
  Total : Integer := 0;

begin
  Total := WIDTH * HEIGHT;
  Exit Total;
end
```

⚠️ A `const` section is **not** allowed in a class or object header — it reports `'const' is not supported in a class header.` A constant *field* is a different question from a constant binding (per instance or per class, and enforced against `this.X := ...` rather than rebinding), so it is rejected rather than quietly treated as a `var`.

### Enumerations

```pascal
type Color = (Red, Green, Blue);
```

Legal at the top level, in a class `type` section, or in a function `type` section.

Members are bound **bare**, as in Pascal, and the type name is also bound as a value so the same member can be reached **qualified**:

```pascal
var C := Red;           // bare
var D := Color.Red;     // qualified — the same value
WriteLn(C = D);         // true
```

Both forms yield one shared value, so they compare equal and are interchangeable as `case` labels or in a typed declaration. The type is also iterable, in declaration order:

```pascal
for var Each in Color do
  WriteLn(Str(Each));   // Red, Green, Blue
```

⚠️ Because members are bare, two enums still **cannot share a member name** — the second declaration reports `'Red' is already defined.` Qualifying does not rescue it: `Color.Red` and `Paint.Red` would be unambiguous, but bare `Red` would not be.

### Functions and procedures

```pascal
function Add(A : Integer, B : Integer) : Integer;
begin
  Exit A + B;
end

procedure Log(Msg);        // untyped parameter → Any
begin
  WriteLn(Msg);
end
```

Notes:

- Parameters are separated by **commas**, not semicolons as in real Pascal, and each carries its own type: `(A : Integer, B : Integer)`.
- A `procedure` may not declare a return type, and `Exit <value>` inside one is an error. `Exit;` alone is fine.
- `Exit` is the return statement (there is no `return`, and no implicit "assign to the function name" as in Pascal).
- Between the signature and `begin` you may open `var` and `type` sections.
- Functions may be nested; inner functions are hoisted into the enclosing body.
- Empty parens are required at the call site: `Foo()`, not `Foo`.

### Classes

```pascal
class Animal;
var
  Name : String;
  Age  : Integer;
begin
  constructor Init(Name);
  begin
    this.Name := Name;
  end

  function Speak() : String;
  begin
    Exit Name + ' makes a sound';
  end
end

class Dog(Animal);          // inheritance via parentheses
begin
  function Fetch();
  begin
    Exit Name + ' fetches';  // inherited fields are in scope unqualified
  end
end
```

- Superclass goes in parentheses after the name — there is no `= class(...)`.
- Field declarations sit between the `;` and the `begin`, in a `var` section. A field may carry an initializer, which is evaluated per instance; one declared without a value starts as `nil` rather than not existing. Declared fields are applied **before** the constructor, so `Init` overrides a default rather than being overwritten by it, and inherited fields are applied before the subclass's own.
- The constructor is named `Init` and is invoked by calling the class: `Dog('Rex')`. A bare `Exit;` inside it returns the instance; **`Exit <value>` is refused** — `Can't return a value from an initializer.` — since a constructor call evaluates to the new instance and nothing else. ⚠️ JPascal accepted it until recently: the check compared against Lox's lowercase `"init"` case-sensitively, so it never matched a constructor and never fired.
- Instantiation uses **no `new`**: `var D := Dog('Rex');`.
- Fields are reachable unqualified inside methods; `this.X := X` disambiguates a shadowing parameter.
- `super.Method()` calls the parent implementation.
- Methods are declared with `function`, `procedure`, or `constructor`; the parser accepts any of the three interchangeably.

#### Visibility — `private:` and `public:`

Fields and methods are public unless a section says otherwise. Visibility is written as a **section marker**, as in Object Pascal, rather than a modifier on each declaration:

```pascal
class Counter;
public:
  var Name  : String := 'anonymous';
private:
  var Count : Integer := 0;
begin
  procedure Bump();
  begin
    Advance();                     // its own privates, bare or through 'this'
  end

private:
  procedure Advance();
  begin
    Count := Count + 1;
  end

public:
  function Report() : String;
  begin
    Exit(Name + '=' + Str(Count));
  end
end
```

- A marker takes effect where it appears and runs to the next marker **within the block it is in**. The header and the body are separate blocks: the body starts public again regardless of how the header ended.
- Markers are legal both between sections and inside a `var` section, so `private:` may stand before the first `var` or between two fields of one.
- A private member belongs to the class that **declared** it. Its own methods reach it, and so does another instance of the same class — `Other.Count` inside a `Counter` method is fine, as in Java. A subclass does not: what a parent hid stays hidden. There is no `protected`.
- `object` declarations take sections on the same terms.
- The `:` is what separates this from the module-level `private`, which prefixes a single top-level declaration and has nothing to do with classes.

⚠️ **Visibility is checked statically, so it is enforced wherever the receiver has a type.** A declared variable, a declared parameter, and `var C := Counter()` are all typed, and reaching a private member through any of them is an error. A receiver that reduces to `Any` is not, and the access goes through — the same bargain gradual typing makes everywhere else. `this` is deliberately such a receiver, which is what keeps a class's own code free of the rule. Nothing is checked at run time: an instance carries no record of which of its fields were private.

### Protocols

A class takes part in the language's built-in operations by **having a method**, not by declaring conformance — there are no interfaces to declare against, so the protocols are structural, as in Python rather than Java.

| Method | Makes the class work with |
|---|---|
| `Elements()` | `for X in C do` — returns what to iterate |
| `ToString()` | `Str(X)`, `Write`, `WriteLn`, and printing inside a collection |
| `Contains(X)` | `X in C` |

```pascal
class Range;
var
  Low : Integer;
  High : Integer;

begin
  function Elements() : List;
  begin
    var Out := [];
    for var I := Low; I <= High; I := I + 1 do Out.Add(I);
    Exit Out;
  end

  function ToString() : String; begin Exit Str(Low) + '..' + Str(High); end
  function Contains(N) : Boolean; begin Exit N >= Low and N <= High; end
end
```

**`Elements()` is asked once and its result is walked** — it is never asked again of the result. That is what lets a collection's `Elements()` return a collection without recursing forever.

Iteration keeps **snapshot semantics**: the loop walks what `Elements()` returned, so mutating the original inside the loop does not change what the loop sees.

A class with none of these keeps the defaults: it prints as `Thing instance`, and iterating or testing membership on it is an error.

### Singletons — `object`

`object` declares exactly one instance, in the same shape as a `class`. The name *is* the instance — there is no constructor call and no `new`:

```pascal
object Goblin(Monster);
var
  Hp    : Integer := 10;
  Power : Integer := 3;

begin
  function Describe() : String;
  begin
    Exit 'goblin hp=' + Str(Hp);
  end
end

begin
  WriteLn(Goblin.Describe());   // goblin hp=10
  Goblin.Hp := 8;               // mutation sticks; there is only one
end
```

This is Kotlin's `object` declaration. Everything a `class` supports works: an optional superclass in parentheses, inherited methods, `super.M()`, `this`, and `var`/`type` sections.

**Creation is deferred to first use**, so an object may refer to another declared later in the file.

Every `object` **declares an `Id` field** holding its own name, contributed by the declaration itself — so it is present whether or not the object has a superclass, and whether or not a superclass declares it.

**Your declaration wins.** The name is only contributed when the object has not claimed `Id` itself, and a declaration counts even with no value — having named the field, the program owns it:

```pascal
object Renamed;
var
  Id : String := 'something else';   // Renamed.Id is 'something else'
begin end

object Blank;
var
  Id : String;                       // Blank.Id is nil, not 'Blank'
begin end
```

`Id` initializes with the other fields, before `Init` runs, so an `Init` that assigns it wins over both.

An object is an ordinary value, so grouping a set of them needs no special mechanism:

```pascal
var Catalog := ['Goblin':Goblin, 'Orc':Orc];

WriteLn(Catalog['Orc'].Hp);

for var Name in Catalog do
  WriteLn(Name);
```

⚠️ An `object` cannot take constructor parameters, since nothing ever calls its constructor.

---

## 4. Statements

**`;` is a terminator, not a separator.** Every statement ends in one, including the last before an `end`. This is the C/Java rule rather than the Pascal one, and it is applied uniformly — if you are coming from Java the placement will already be familiar; if you are coming from Pascal, it is the main thing to unlearn.

### Blocks

```pascal
begin
  Stmt1;
  Stmt2;
end
```

`end` is **not** followed by a semicolon and there is no `end.` terminator for the program.

⚠️ **A `var` as the body of a branch or loop written without `begin ... end` is refused by the C back end** — `if Flag then var Y := 5;`, and the `while`, `for ... in` and `case`-arm forms of it. Interpreted, what such a binding means differs per construct: `if` and `case` leak it to the enclosing scope, `while` redefines it on the second pass and fails with `'Y' is already defined`, and a `for ... in` body scopes it per iteration so nothing after the loop can read it. The emitter brace-wraps every body and can reproduce none of the three, so it says so by name rather than emitting C that means something else. Open a `begin ... end` and all four work.

### Conditionals

```pascal
if X > 0 then
  WriteLn('positive');
else if X < 0 then
  WriteLn('negative');
else
  WriteLn('zero');
```

Note the semicolon **before** `else`: it terminates the then-branch, which is a complete statement. Exactly as in Java — `if (c) f(); else g();` — and the opposite of standard Pascal, where `;` separates statements and so cannot precede `else`.

When the branch is a block, no semicolon appears, again matching Java's `} else {`:

```pascal
if X > 0 then
begin
  WriteLn('positive');
end
else
begin
  WriteLn('non-positive');
end
```

Each branch is a single statement; use `begin ... end` for more.

### Loops

```pascal
while I < 10 do
begin
  I := I + 1;
end

for var I := 0; I < 10; I := I + 1 do
  WriteLn(I);
```

```pascal
for var Each in [10, 20, 30] do
  WriteLn(Each);
```

The counted `for` is **C-style** (`init; condition; increment do`), not Pascal's `for I := 1 to 10 do` — there is no `to`/`downto` and no `repeat..until`.

`for var X in C do` iterates a collection directly. It works on `List`, `Set`, `Array`, `Stack`, `Map`, `String`, and an enum type; a **Map yields its keys**, a String its characters, and an enum its members in declaration order. The loop variable is scoped to the loop and is a fresh binding on each pass. Anything else raises `Can only iterate a collection or a String.`

Test blocks report **sorted by name within a file, and files in the order their tests were first met** — which for `uses` is load order, so a multi-file report reads in dependency order. Like everything else observable, it is specified rather than inherited: it used to depend on Java's hashing.

**Every collection iterates in insertion order**, `Map` and `Set` included, and this is a guarantee of the language rather than a property of the implementation. Re-assigning an existing key keeps its original position; only a genuinely new key appends. This is specified rather than left to the host because a second implementation has to reproduce it — an order inherited from whatever a runtime's hashing happens to do is unreproducible, and would silently diverge between the interpreter, the compiler, and the VM.

`break` exits the innermost loop of either kind and is rejected at parse time outside one. There is no `continue`.

### Case

```pascal
case X of
  1:    WriteLn('one');
  2, 3: WriteLn('two or three');   // comma-separated alternatives
else
  WriteLn('other');
end
```

Desugars into an if/else-if chain, so branches are tested in order and there is no fallthrough and no jump table.

Each branch takes **one** statement, as in standard Pascal and as in an `if` or `while` body here — wrap two or more in `begin ... end`. A declaration counts as a statement, so `1: var Y := 0;` needs no block:

```pascal
case X of
  1: begin
       WriteLn('a');
       WriteLn('b');
     end
  2: var Y := 0;
end
```

Labels are arbitrary expressions, not just constants, and there are no ranges (`1..5`). ⚠️ That generality is also why a branch cannot simply run on to a second statement: with `;` terminating rather than separating, the parser reaching `WriteLn('b')` cannot tell a further statement from the next branch's label, since `WriteLn('b'):` would itself be a legal label. Hence the error names the missing `:` rather than the extra statement.

### Exceptions

```pascal
try
  Risky();
except
  on E : String do WriteLn('string error: ' + E);
  on E do WriteLn('anything else');
end
```

Handlers are matched on the **runtime type name** of the raised value — the class name for a class instance, otherwise the Algol-24 type name: `String`, `Char`, `Integer`, `Double`, `Boolean`, `List`, `Map`, `Set`, `Array`, `Stack`, or an enum member's own type. The same names `is` answers with. Internal runtime errors carry their message as the value, so they match as `String`.

```pascal
raise 'something went wrong';
raise MyError('detail');
```

There are three ways to catch everything, and one way to catch nothing:

| Form | Behavior |
|---|---|
| `on E do ...` | Untyped handler, catches any value and binds it |
| statements after the `on` handlers | Catch-all block, no binding |
| `except ... end` with no `on` handlers at all | The whole block is the catch-all |
| `except end` (empty, no handlers) | Catches and deliberately ignores |

**When typed handlers are present and none matches, the exception propagates** to the enclosing `try` or out of the function, exactly as you would expect. Add an untyped `on E do` or trailing statements if you want it stopped there.

**Handlers respect the class hierarchy.** `on E : Animal do` catches a raised `Dog`, and the most derived handler wins regardless of the order they are written in — matching starts at the value's own class and walks up its superclasses:

```pascal
try
  raise Dog();
except
  on E : Animal do WriteLn('not this one');
  on E : Dog do WriteLn('this one, even though it is second');
end
```

Non-class values (`String`, `Integer`, …) match on their type name exactly; there is no hierarchy to walk.

⚠️ `finally` does not exist.

Declaring the same handler twice is a **parse error** rather than a silent overwrite — whether that is two handlers for one type, two untyped `on` handlers, or an untyped `on` alongside a trailing catch-all block:

```pascal
except
  on E : String do WriteLn('first');
  on E : String do WriteLn('second');   // Duplicate handler for 'String'.
end
```

### Other statements

```pascal
Exit;              // return from procedure
Exit Value;        // return a value from function
print Expr;        // writes directly to stdout, bypassing Screen
raise Expr;
break;
```

`print` is a debugging leftover — prefer `WriteLn`, which routes through the `Screen` singleton and can be buffered.

---

## 5. Expressions

Precedence, loosest to tightest:

| Level | Operators | Associativity |
|---|---|---|
| 1 | `as` (applied to the whole expression) | — |
| 2 | `:=` | right |
| 3 | `or` | left |
| 4 | `and` | left |
| 5 | `=`, `<>` | left |
| 6 | `<`, `<=`, `>`, `>=` | left |
| 7 | `+`, `-` | left |
| 8 | `*`, `/` | left |
| 9 | `not`, unary `-` | right |
| 10 | `()` call, `[]` subscript, `.` access | left |

Because `and`/`or` sit **below** the comparison operators, `A = B or C = D` parses as `(A = B) or (C = D)` — no parentheses needed. This is a deliberate improvement over standard Pascal, where `and`/`or` bind tighter and force parens.

### Assignment is an expression

`X := 1` is an expression, so `A := B := 0` works. Three assignment targets are supported: a bare variable, a property (`obj.field`), and a subscript (`A[0] := x`).

### List and map literals

Square brackets build both, and **the colon decides which**:

```pascal
var L := [10, 20, 30];        // List
var M := ['a':1, 'b':2];      // Map
var E := [];                  // empty List
var F := [:];                 // empty Map
```

A `:` after the first element makes it a map; otherwise it is a list. Elements are arbitrary expressions, and literals nest: `[[1, 2], [3, 4]]` and `[['a':1], ['b':2]]` both work.

`List()` and `Map()` remain available and are equivalent to `[]` and `[:]`.

A **set** has no literal of its own — the colon is already spent distinguishing the two forms above — so it is built from a list, which also collapses duplicates:

```pascal
var S := Set([1, 2, 3]);
var Unique := Set(SomeList);   // dedupes
```

⚠️ Maps and sets are hash-backed, so iteration order is unspecified.

### Type casts

```pascal
var D := A as Dog;
```

`as` is purely a **compile-time** annotation: it overrides the static type the checker infers and emits no runtime check. Casting to a wrong type fails later at the point of use, not at the cast.

### Type tests

```pascal
if A is Dog then WriteLn('woof');
```

`is` is the **runtime** counterpart to `as`: it answers whether a value's type is the named one, or inherits from it.

```pascal
var D := Dog();

D is Dog          // true
D is Animal       // true — the chain is walked
D is Cat          // false — a sibling is not a parent

1 is Integer      // true
1 is Double       // false — no numeric promotion here
'a' is Char       // true
'a' is String     // false — a one-character literal is a Char
[1, 2] is List    // true
Red is Colour     // true — an enum member answers with its type

nil is Animal     // false
```

Four things to know:

- **The right side is a type name, not an expression.** There is nothing to evaluate there, so `is` cannot test against a type held in a variable. The name is matched case-insensitively, as type names are everywhere else.
- **`nil` is of no type at all**, rather than an error or a match. A test may be written against a value that might not be there.
- **It binds with the relational operators**, tighter than `and` — so `A is Dog and B is Cat` parses as two tests joined.
- **Every value answers with something**, including the collections: `List`, `Map`, `Set`, `Array`, `Stack`, `TextFile`, and an enum member with its own type.

### Subscripting

Reads work on `String` (yielding a Char), `List`, `Map`, `Array`, and `Stack`.

Writes work on `List`, `Map`, and `Array`:

```pascal
A[0] := 'zero';        // Array
L[1] := 'second';      // List — index must already exist
M['key'] := 'value';   // Map — inserts if absent
```

Assigning through a `String` subscript raises "Strings are immutable.". An out-of-range `List` or `Array` index raises at runtime. Like other assignments this is an expression, so it evaluates to the assigned value.

---

## 6. Types

Annotations are optional; anything unannotated is `Any` and unchecked. Type names in use: `Integer`, `Double`, `Boolean`, `String`, `Char`, `Any`, every declared class/enum name, the built-in collections, and `TextFile` and [`Buffer`](#buffer) — which are not collections but are named and tested for the same way.

Checking happens in a pass after parsing and before execution (`TypeChecker`). It verifies variable initializers, `Exit` types, assignments, and binary operands, and it accepts a subclass wherever a parent is expected.

It is deliberately **gradual**, not sound. `Any` means "not known" and is compatible with everything in both directions — an expression the checker cannot type is never itself an error. Annotating more is therefore always safe: it can only add checking, never break a working program.

What the checker does know:

- **Builtins** carry the return type from their Java signature, so `Exit Random(1, 6)` satisfies `: Integer`.
- **Methods**, including inherited ones and `super.M()` calls, resolve by walking up the class hierarchy. This applies inside `object` declarations as well as `class` bodies.
- **Subclasses** satisfy a parent annotation, for both `Exit` and variable initializers.
- **List and map literals** reduce to `List` and `Map`, so `var L : List := [1, 2];` checks.

What it does not: subscript results (`L[0]` is `Any` unless the variable was declared `List of T`), map values, and anything reached through a `Get` on an untyped value.

Generic element types are recognized in exactly one position, `List of T`, and are recorded for checking but not enforced at runtime.

---

## 7. Built-ins

Every public static method of `nativefunction/NativeFunctions.java` is registered as a global under its exact Java name, so this list is the source of truth. Same-named methods become overloads, selected by argument count.

**A built-in is an ordinary binding in the outermost scope, so anything you declare shadows it.** `class Buffer`, `function Max`, a top-level `var Str`, a local `var Set` — each takes the name over for as far as its own scope reaches, and the built-in is simply not found first. Nothing is reserved: these are names, not keywords, and the only names Algol-24 keeps for itself are the [keywords](#keywords).

**A local is scoped to its block**, so a name released at `end` goes back to meaning whatever it meant outside — a field, a method, or a built-in. Two sibling blocks may each bind it without either outliving its own.

⚠️ **A file-scope shadow reaches exactly one file, plus whoever imports it.** A top-level `function Length` takes the name over in its own file and in nothing else — a module that file imports goes on calling the built-in, because a module sees its own declarations, its own imports' exports, and the built-ins, and never the declarations of a file that merely imported *it*. Shadowing follows `uses`, in other words, like every other name.

Shadowing is scoped like any other binding, which is worth stating because the two halves are easy to conflate:

```pascal
function Wrap();
begin
    function Set (V);            // shadows Set() inside Wrap
    begin
        Exit 'nested ' + V;
    end
    Exit Set ('x');              // 'nested x'
end

begin
    var S := Set (['a', 'b']);   // out here the built-in is found again
end
```

To reach a built-in you have shadowed, qualify it: `System.WriteLn(x)` is the built-in however thoroughly the bare name has been taken over. `System` is the unit the built-ins live in — see [Units and qualified names](#units-and-qualified-names).

⚠️ **A collection literal never goes through the constructor**, so `[1, 2]` and `[:]` build a real `List` and `Map` whatever names are in scope. Only the constructor *call* — `List()`, `Map()` — is shadowable.

**I/O** — `WriteLn(x)`, `Write(x)`, `ReadLn(prompt)`, `ClearScreen()`, `Screen()`

**Files** — `TextFile()`, `FileExists(name)`, `ParamCount()`, `ParamStr(i)` — see [Files](#files)

**Strings** — `Length(s)`, `Copy(s, begin, len)`, `Pos(haystack, needle)`, `Str(x)`, `Char(n)`

**Ordinals** — `Ord(x)` is the ordinal value, as in Turbo Pascal: a `Char` gives its code point (the inverse of `Char(n)`), a `Boolean` gives 0 or 1, an enum member gives its position within its own type, and an `Integer` gives itself. Anything else raises `Ord failed: '…' has no ordinal.` — a `Double` is not an ordinal type, and neither is a `String`.

**Parsing** — `Val(text)` reads a number out of text and returns a `Double`, so `Val('2.5')` is `2.5` and `Val(nil)` is `-1.0`. Text that is not a number raises `Val failed: '…' is not a number.`

**Math** — `Max(a, b)`, `Mod(a, b)`, `Random(min, max)`, `Randomize()`, `clock()`

**Misc** — `Pause(ms)`, `Debug(label, x)`

**Constructors** — `Array(size)`, `List()`, `Map()`, `Set()`, `Set(list)`, `Stack()`, `Buffer()`, `Buffer(size)`

Collection methods (case-insensitive):

| Type | Members |
|---|---|
| `Array` | `Get(i)`, `Set(i, v)`, `Fill(v)`, `Contains(v)`, `IndexOf(v)`, `Sort()`, `Length`, `IsEmpty` |
| `List` | `Get(i)`, `Add(v)`, `Insert(i, v)`, `RemoveAt(i)`, `Contains(v)`, `IndexOf(v)`, `Sort()`, `Clear()`, `Length`, `IsEmpty` |
| `Map` | `Get(k)`, `Put(k, v)`, `Remove(k)`, `Contains(k)`, `Keys()`, `Values()`, `Clear()`, `Length`, `IsEmpty` |
| `Set` | `Add(v)`, `Remove(v)`, `Contains(v)`, `ToList()`, `Clear()`, `Length`, `IsEmpty` |
| `Stack` | `Push(v)`, `Pop()`, `Peek()`, `Contains(v)`, `Clear()`, `Length`, `IsEmpty` |

**`Length` and `IsEmpty` are properties; everything else is a method.** The rule is that a zero-argument query reads better without parentheses — write `L.Length` and `L.IsEmpty`, but `L.Clear()`. Every collection is iterable with `for var X in C do`.

A few members are worth spelling out:

- **`RemoveAt(i)` on a `List` takes an index**, and is named for it. `Remove(k)` on a `Map` takes a key, so a `List.Remove` accepting either would be ambiguous about which it meant. It returns the element removed.
- **`Insert(i, v)` accepts `Length` as the index**, which appends — so a loop can fill a list without a special case for the end.
- **`IndexOf(v)` returns `-1`** when there is no match, rather than raising, so a miss can be tested for.
- **`Pop()` and `Peek()` on an empty `Stack` raise** `Pop from an empty Stack.` and `Peek at an empty Stack.`, which are catchable as any other runtime error is. Test `IsEmpty` first if a miss is expected.
- **`Keys()`, `Values()` and `ToList()` return a `List`** in insertion order — the same order `for ... in` walks. ⚠️ They are **methods**, so the parentheses are required: `M.Keys` without them is not a shorthand and fails, differently in each back end.
- **A `Map` is hashed**, so `Get`, `Put` and `Contains` do not get slower as it fills. Insertion order is kept separately from lookup and is what everything reads, so this is invisible except in the time it takes. ⚠️ `Remove(k)` is the exception and is **O(n)**: it shifts the entries above the removed one so the remaining order is unchanged.
- **`Sort()` orders numbers numerically and text lexicographically**, with a `Char` treated as a one-character `String`. Integers and Doubles order against each other. Anything else raises `Can only sort numbers against numbers, or text against text.` — it used to inherit the JVM's natural ordering and die with a raw Java `ClassCastException` on a mixed list.

**Printing a collection uses the shape of its literal**, so a `List` renders as `[1, 2, 3]` and a `Map` as `[a:1, b:2]`, with elements rendered as they would be individually. This is specified rather than inherited: a `Map` used to print as `{a=1}`, which was Java's `HashMap.toString` showing through — braces and `=` are not Algol-24 syntax, and no other implementation would have produced them.

⚠️ String indices are **0-based**, unlike real Pascal's 1-based strings: `Copy('abcdef', 0, 3)` is `'abc'`, and `Pos('abcdef', 'cd')` is `2`. `Pos` returns `-1` when not found, not `0`.

### Buffer

Growable bytes with an explicit lifetime. It is the answer to the [concatenation cliff](#operators) and the memory primitive a bytecode VM needs, which are the same machinery seen from two directions.

```pascal
var B := Buffer();               // empty
B.Append('static Value ');
B.Append(Symbol);
WriteLn(B.Length);
Exit B.Text;

var Chunk := Buffer(1024);       // 1024 zero bytes, addressable at once
Chunk[0] := 72;
Chunk.PutInt(4, Offset);
Chunk.Resize(2048);
Chunk.Free();
```

| Member | Meaning |
|---|---|
| `Append(x)` | Appends `x`'s text, as `Write` would render it. Amortized O(1). |
| `PutInt(at, n)`, `GetInt(at)` | A 32-bit Integer, four bytes, **little-endian**. |
| `Resize(n)` | Grows zero-filled, or truncates. |
| `Free()` | Releases it. See below. |
| `Text` | **A property.** The bytes as a `String`, copied. |
| `Length`, `IsEmpty` | **Properties**, as on every collection. |

`Buffer(n)` is n bytes of zero the way `Array(n)` is n nils — `Length` is the addressable size from the moment it is made, not a capacity that appending has to fill first. `B[i]` reads and writes one byte as an **Integer 0..255**, not a `Char`: a `Buffer` is raw memory, and `Text` is the only member that produces a `String`.

Four things are worth knowing before using one:

- ⚠️ **`Free()` poisons.** It does not merely release the memory: the buffer is marked dead, and *any* later access raises `That Buffer has been freed.` Freeing twice is harmless, like closing a file twice. The rule is stricter than C's on purpose — the same programs run interpreted, where there is nothing to deallocate, and a `Free` that only released memory would read fine one way and be undefined the other.
- ⚠️ **A zero byte has no `Text`.** `Buffer(4).Text` raises `A Buffer holding a zero byte has no Text.` rather than returning a truncated or NUL-bearing string, because a compiled `String` ends at its first NUL and an interpreted one does not. `Resize` down to the bytes actually written, or build the text with `Append` alone.
- **`Text` copies.** Handing back the internal bytes would alias mutable memory as an immutable `String`, and the next `Append` would change a string already handed out. The copy is O(n) once, not O(n) per append.
- **Capacity is invisible.** `Length` is the size; a `Buffer` prints as `Buffer(27)` — never its contents, which may not be text and may be very large, and never its capacity, which depends on allocation history.

A `Buffer` is not iterable and has no literal.

### Files

Turbo Pascal's text-file API, with the handle as the receiver.

```pascal
var F := TextFile();
F.Assign('Program.a24');
F.Reset();
while not F.Eof do
   WriteLn(F.ReadLn());
F.Close();

var Out := TextFile();
Out.Assign('out.c');
Out.Rewrite();
Out.WriteLn('#include "algol.h"');
Out.Close();
```

| Member | Meaning |
|---|---|
| `Assign(name)` | Binds a file name. The file must not be open. |
| `Reset()` | Opens the assigned file for reading. |
| `Rewrite()` | Creates it, or truncates it, for writing. |
| `Append()` | Opens it for writing at the end. |
| `ReadLn()` | The next line, without its terminator. |
| `Write(x)`, `WriteLn(x)` | Writes; `WriteLn` ends the line. |
| `Flush()` | Pushes buffered output to disk. |
| `Close()` | Closes it. Harmless if it is not open. |
| `Erase()` | Deletes the assigned file. It must be closed. |
| `Rename(name)` | Renames it, and re-assigns the handle to the new name. |
| `Eof` | **A property.** At end of file — always true while writing. |

Turbo Pascal spells these as free procedures over a `var F: Text` parameter — `Assign(F, Name)`, `ReadLn(F, S)`. Algol-24 has neither var parameters nor a `Text` type, so the handle became the receiver. The names and their meanings are unchanged.

Three departures worth knowing:

- **Failures raise; there is no `IOResult`.** Turbo Pascal's `{$I-}`/`IOResult` pair exists because it had no exceptions. Algol-24 does, so a failure raises a `String` that `try/except` catches. `Reset` on a missing file raises `Reset failed: cannot open 'name'.`
- **No `Eoln`, `Read` or `SeekEof`.** `ReadLn` is the unit of reading, so a position *within* a line has nothing to mean. A file is a sequence of lines.

**A line ends at `#10`.** A `#13` immediately before it is the other half of a CRLF pair and comes off with it; any other `#13` is ordinary text. `WriteLn` writes `#10` and never the host's separator, so the same program writes the same bytes on every platform.

That is one rule for the whole language, not just for files: the scanner treats `#13` as whitespace alongside space and tab, and only `#10` advances the line count. A reader that also broke lines at a lone `#13` — which is what Java's `BufferedReader.readLine` does — would have disagreed with the scanner about a single character, which is the sort of thing that stays hidden until it is expensive.
- **`FileExists` is not Turbo Pascal's**, which had you attempt the open and check `IOResult`. It is SysUtils' name, and asking beats probing by exception.

`ParamStr(0)` is the program and `ParamStr(1)` upward are its arguments, as in Turbo Pascal; `ParamCount()` counts the arguments, not the program. Anything after the script on the command line belongs to the program:

```bash
java -jar target/jpascal.jar Program.a24 alpha beta   # ParamCount() = 2
```

⚠️ Interpreted, `ParamStr(0)` is the **script's path**; compiled it is the executable's. They are different strings for the same idea, and neither back end can produce the other's. `ParamStr` past the end is `''` rather than an error, so walking `1..ParamCount()` is always safe.

---

## 8. Tests

```pascal
test 'Scan a comment';
begin
  var Uut := Scanner('// comment');
  AssertEqual(1, Uut.Tokens.Length);
end
```

A test block desugars into a function whose name is the string literal. Assertions available: `AssertEqual(expected, actual)`, `AssertTrue(x)`.

Run them with `--test`, which reports PASS/FAIL grouped by source file and exits 70 if anything fails. ⚠️ In normal (non-`--test`) runs the assertion builtins are never registered, so calling `AssertEqual` outside test mode is an undefined-variable error.

---

## 9. What the C back end refuses

The interpreter defines the language, so anywhere the compiler is **narrower** than the interpreter is part of the observable surface and belongs here. There are eighteen such places. Each one **names the construct, writes no output, and stops** — it never emits C that means something other than what the program said, because output comparison is the only thing verifying the back end and silence would defeat it.

The message is always `<construct> is not supported by the C back end yet.`

⚠️ **The two compilers report it differently.** JPascal prints `[ERROR] …` and exits **65**; `algc` raises, so the line reads `Uncaught: …` and it exits **70**. The text between is identical, and is what this table gives. Neither can produce the other's exit code — the language has no `Halt`.

| Refused | When you hit it |
|---|---|
| `A function nested more than one level deep` | Reachable. A function inside a function inside a function. |
| `A function declared inside a method` | Reachable. Any nested function in a class body. |
| `Reading 'X' from a nested function` | Reachable. A bare name in a nested body that is neither a local nor a file-scope global — usually a typo, and the refusal exists so it reads as this rather than as a `cc` error about the emitter's own output. |
| `A 'var' as an unbraced branch or loop body` | Reachable. See the ⚠️ in [Statements](#4-statements): open a `begin ... end` and it works. |
| `A call to 'X'` | Reachable. Calling a name that is neither a builtin nor a declared function. Without it an unimplemented builtin emitted `f_X(...)` and failed at `cc` with a message about incompatible types. `X` may be qualified — `A call to 'System.Nope'` — where the interpreter would have raised at run time instead. |
| `'super' as a value` | Reachable. `var F := super.M;` — needs a bound method. `super.M()` compiles fine; it is a different node. |
| `'System.X' as a value` | Reachable. `var F := System.Max;` — a built-in is a C function with no closure to stand for it. `System.Max(1, 2)` compiles fine, and a *user* unit's function taken as a value does too. See [Units](#units-and-qualified-names). |
| `Two modules named 'X'` | Two source files with the same stem reaching one program. A file is a translation unit, so the stems have to be distinct. |
| `Two modules exporting 'X'` | Reachable. Two imported modules exporting one name. Both interpreters refuse it at the `uses` as `'X' is already defined; mark it private in one of the modules.`; without this row the compilers emitted it and the failure landed on the **linker**. Mark one `private`, or rename. |
| `A capture of 'X'` | A guard. The closure machinery lists the cells in scope where the declaration stands; this fires if one is named that does not exist. |
| `An identifier containing 'c'` | A guard on the identifier mangler. Only `?` is legal in an Algol-24 name and illegal in C, and that is mapped to `_q`; this is the one place that would have to learn about a second such character. |
| `A literal of type X` | A guard. A literal whose Java/Algol-24 class the emitter has no writer for. |
| `Unary 'op'`, `Binary 'op'` | Guards. Every operator in the language is emitted; these catch one being added to the front end and not here. |
| `A class field` | A guard. A field *declaration* reaching the expression path instead of the class-emission path. |
| `'super' outside a class` | Unreachable — the Resolver rejects it first, with `Can't use 'super' outside a class.` |
| `A nested 'uses'` | Unreachable — the Parser rejects it first. `uses` is only legal at the top of a file. |
| `An assignment to 'Unit.X'` | Reachable. `Unit.X := V` where X is not a file-scope `var` of that unit — a function or a class, which is not a place to write. Assigning to a unit's `var` compiles; `System.X := V` is refused here and is `Can't assign to 'X' in unit 'System'.` interpreted. |

⚠️ **"Guard" means no program is known to reach it, not that it cannot happen.** They are the cheap half of the bargain: the alternative to a named refusal is emitted C that compiles and disagrees with the interpreter, which is the one failure this project cannot detect.

The development repository's `./refuse.sh` runs a program per reachable refusal under both compilers and requires the wording to match and no output to be written. `refuse/front/` does the same for the **Resolver's** refusals — programs that are wrong in the language itself, refused whether or not anyone is compiling. It exists because nothing else could see a refusal: `cgate` compares emitted C, and a refused program emits none; `ctest` and `gate` compare a program's output, and a refused program has none. That gap is why `algc` said `'super'` where JPascal said `'super' as a value` for as long as both had existed.

Two things that are **not** in this table, because they are not refusals:

- **Module visibility is not checked when compiling.** The back end flattens every module into one program, so a file that reaches a name it never imported fails interpreted and compiles fine. See [Program structure](#2-program-structure).
- **`ParamStr(0)`** is the script interpreted and the executable compiled. Neither back end can produce the other's string.

---

## Rough Edges

Ordered roughly by how much friction they cause.

### 1. `finally` is unimplemented

```pascal
try
  Work();
finally             // Error: 'finally' is not supported yet.
  Cleanup();
end
```

Deliberately unimplemented rather than merely missing — the construct exists to release resources deterministically, and the language has none to release (no file handles, locks, or manual memory, and the host is garbage collected). `statement()` reports it by name so it fails honestly instead of as a confusing `Expect expression.`

**If it is ever added**, it needs a parser rule (`tryStatement` currently *requires* `except`, so `try/finally` alone does not fit the existing shape), a `Stmt.Try` field, and a Java `finally` in `visitTryStmt` that runs on all four exit paths: normal fall-through, a raised error, `Exit` (thrown as `Return`), and `break` (thrown as `BreakException`).

### 2. Top-level functions cannot be overloaded

```pascal
function F(A) : Integer;    begin Exit 1; end
function F(A, B) : Integer; begin Exit 2; end
```
```
[ERROR] t.a24: 'F' is already defined.
```

**Cause.** `Interpreter.visitFunctionStmt` rejects any name already present in the
environment, throwing before it reaches `Environment.define` — whose exemption for
a `PascalFunction` replacing a `PascalFunction` exists precisely to permit
overloads, and is therefore unreachable from this path. The dispatch machinery is
all present: `PascalFunction.overloads`, `match(types)`, and the walk in
`visitCallExpr` that tries the enclosing environments. Methods on a class do
overload, since `visitClassStmt` builds its own method table and appends to
`overloads` rather than going through the environment.

**Fix.** Append to the existing `PascalFunction`'s `overloads` when the name is
already bound to one, instead of throwing — the same thing `visitClassStmt` already
does for methods.

### 3. Smaller inconsistencies

- ~~**`Ord` parses rather than taking a character code.**~~ **Fixed.** It was Turbo Pascal's `Val` under the wrong name, and the two are now separate: `Ord` gives an ordinal and `Val` parses. ⚠️ The old note said "nothing in the corpus uses it, so it is a free change" — that was wrong twice over. Both scanners used it, and the change was forced rather than free: a compiler written in Algol-24 needs a character's code point to emit `alg_char_value(65)`, and the name for that operation was taken by its opposite. Four of the seven `cgate` programs were blocked on it.
- **`=` and collection membership disagree about numbers.** `1 = 1.0` is true — the operator promotes an Integer to a Double before comparing — but `1 in [1.0]` is false, and a `Map` with the key `1` does not find `1.0`. Membership and key lookup compare strictly, requiring the same type. The C runtime reproduces this deliberately, because the interpreter defines the language, but the two ought to agree with each other. Fixing it means picking a side: either membership promotes (which needs numeric keys normalised, since a hash lookup cannot promote), or `=` stops promoting (which is a much bigger change). Both back ends have always agreed here; `Collections.a24` now pins it.

  ⚠️ **They disagree about `NaN` and `-0.0` too, and that half is Fixed.** Membership compares a Double by its **bits**, so `NaN` is equal to itself and `-0.0` is a different key from `0.0` — while the `=` operator keeps IEEE's answers, `NaN = NaN` false and `-0.0 = 0.0` true. The C runtime used to compare with `==` in both places, which meant a `NaN` could be put into a `Map` and then never found again, a `Set` held two of them, and `-0.0` overwrote `0.0`. The interpreter never did any of that — `PascalMap` is a `LinkedHashMap` and `Double.equals` is a bit comparison — so this **closed a divergence between the back ends** rather than choosing a new rule, and it is what makes a Double hashable at all.
- **Enum members are global**, so two enums cannot share a member name. Qualified access exists but the bare binding is what collides. Marking the `type` `private` scopes both the name and its members to one module, which narrows this to a per-file problem rather than a program-wide one.
- **Modules have no qualified access.** `uses` scopes a file's declarations and honours `private`, but a module name is not bound to anything, so there is no `Scanner.ScanTokens` to disambiguate with when two modules want to export the same name. The remedy today is to mark one of them `private`. Deliberate for now — the obstacle is that the module name is already taken by what the module exports.
- **A private member is enforced only where the receiver has a type.** The rule is a static one, so a receiver that reduces to `Any` reaches whatever it likes. That is consistent with the rest of the type system, and it does mean visibility is a discipline the checker helps with rather than a guarantee the runtime makes. There is also no `protected`: a subclass cannot reach what its parent hid, and nothing lets it.
- **The type checker does not know about module boundaries.** A reference to another module's private name types cleanly and fails at run time as `Undefined variable`. Correct, but later than it could be.
