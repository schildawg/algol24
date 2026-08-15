# Algol-24

A small Pascal-flavoured language with optional types, compiled to C.

The compiler is **written in Algol-24 and compiles itself**. What is checked in
here is its own output, so the only thing you need to build it is a C compiler.

```sh
cd bootstrap && ./build.sh     # -> bootstrap/algc, needs nothing but cc
```

or from the top, which builds the compiler from source in two stages:

```sh
./build.sh                     # -> ./algc
./compile.sh hello.a24 --run   # compile a program and run it
./test.sh                      # everything
```

---

## The language in one page

```pascal
begin
    WriteLn('Hello, world.');
end
```

A program is declarations followed by a `begin ... end` block. Semicolons
**terminate** statements rather than separating them, so the one before `end` is
required.

### Variables

```pascal
var Name := 'Ada';              // inferred
var Count : Integer := 0;       // declared
const Limit := 100;             // cannot be reassigned

var                             // a section, several at once
    Width, Height : Integer := 10;
```

Types are optional and checked when written. `Integer`, `Double`, `String`,
`Char`, `Boolean`, `Any`, plus any class, enum, or collection name. An
un-annotated name is `Any`, which is compatible with everything in both
directions — writing no type is never itself an error.

⚠️ A one-character literal is a `Char`, not a `String`, and the two are never
equal. `Copy(S, 0, 1)` gives a `String`; `S[0]` gives a `Char`.

### Control flow

```pascal
if X > 0 then WriteLn('positive');
else WriteLn('zero or less');

while X > 0 do X := X - 1;

for var I := 0; I < 10; I := I + 1 do
    WriteLn(I);

for var Item in [1, 2, 3] do
    WriteLn(Item);
```

The `for` is C-shaped, not Pascal's `to`/`downto`. `for ... in` walks any
collection, a `String`'s characters, or anything with an `Elements()` method.

⚠️ Truthiness is not C's: `nil`, `False`, the **Integer** `0`, and an enum member
whose ordinal is `0` are falsey. `0.0`, `''` and any `Char` are truthy.

### Functions

```pascal
function Add (A : Integer, B : Integer) : Integer;
begin
    Exit A + B;
end

procedure Announce (Text : String);
begin
    WriteLn(Text);
end
```

Parameters are comma-separated and individually typed. `Exit` returns — there is
no `return`. Functions are values, nest, and close over what they see:

```pascal
function Counter() : Any;
var
    Count := 0;

begin
    function Bump() : Integer;
    begin
        Count := Count + 1;

        Exit Count;
    end

    Exit Bump;
end
```

### Collections

```pascal
var Numbers := [1, 2, 3];             // List
var Ages    := ['Ada':36, 'Bob':41];  // Map
var Seen    := Set();
var Grid    := Array(10);
var Work    := Stack();

Numbers.Add(4);
WriteLn(Numbers[0]);
WriteLn(Numbers.Length);
WriteLn(2 in Numbers);
```

`[...]` is a list, `[k:v]` a map, `[:]` an empty one. `in` is membership.
`Length` and `IsEmpty` are **properties**, not calls.

### Classes

```pascal
class Animal;
var
    Name : String;

private:
    Secret : Integer := 0;

public:
begin
    constructor Init (Name : String);
    begin
        this.Name := Name;
    end

    function Speak() : String;
    begin
        Exit '...';
    end

    function ToString() : String;
    begin
        Exit Name + ' says ' + Speak();
    end
end

class Dog (Animal);
begin
    function Speak() : String;
    begin
        Exit 'Woof';
    end
end

begin
    var D := Dog('Rex');          // no 'new'
    WriteLn(D);                   // Rex says Woof
end
```

Fields go in a `var` section with optional initializers; `private:` and
`public:` sections control visibility, enforced statically. Methods overload on
their whole signature. `ToString()` decides how an instance prints, anywhere it
appears — including inside a collection.

### Objects and enums

```pascal
object Registry;
var
    Count : Integer := 0;

begin
    procedure Note();
    begin
        Count := Count + 1;
    end
end

type Colour = (Red, Green, Blue);

begin
    Registry.Note();

    var C := Red;                 // bare
    if C = Colour.Red then        // or qualified -- the same value
        WriteLn(Ord(C));          // 0
end
```

An `object` is a singleton reached by name, built on first use.

### Exceptions

```pascal
try
    raise 'went wrong';
except
    on E : String do WriteLn('caught ' + E);
    on E : Animal do WriteLn('an animal');
end
```

Anything can be raised. Handlers respect the class hierarchy and the **most
derived** one wins, whatever order they are written in.

### Modules and units

```pascal
uses Scanner;         // loads ./Scanner.a24
private var Current;  // stays inside this file
```

A file sees what it imports and nothing else — `uses` is not transitive, and
every file declares its own dependencies. A module is loaded once however many
files import it. The dependency graph may contain cycles, which real ones do.

In the compiled output each source file becomes its own C file and header, and
`private` becomes C's `static`.

**Every file is also a unit, named by its file**, so an exported name can be
written either way:

```pascal
Scanner.ScanTokens()   // the same function the bare name reaches
```

A file may open with `unit Scanner;` to say so. It declares nothing and
qualification works without it — what it buys is a check that the name and the
file still agree.

**`System` is the unit the built-ins live in.** It is in scope everywhere and is
what makes built-in names shadowable without being lost:

```pascal
function Max (A, B) : String;   // takes the name over for this file
begin
    Exit 'mine';
end

begin
    WriteLn (Max (1, 2));          // mine
    WriteLn (System.Max (1, 2));   // 2
end
```

Which one a dot means is ordinary scoping — a local, then an `object` or enum
type of that name, then the unit. A bare class name has never had member access,
so `class Scanner` inside `Scanner.a24` costs nothing: `Scanner` is the class and
`Scanner.Scanner` is that class through its unit. Qualification reaches a unit's
*exports*, so it is not a way around `private`.

### Tests

Tests are part of the language:

```pascal
test 'Copy Takes A Length';
begin
    AssertEqual('ell', Copy('hello', 1, 3));
end
```

```sh
./algc --test Program.a24     # exits 70 on failure
```

[ALGOL-24.md](ALGOL-24.md) is the full reference, including the built-in
functions, the collection method table, and the deliberate rough edges.

---

## Usage

```sh
./algc Program.a24                    # run
./algc --test Program.a24             # run its test blocks
./algc --compile --out=DIR Program.a24  # emit C (DIR must exist)
./algc --help
```

The emitted directory stands alone — `cc *.c -o name` — and links nothing but
libc.

## Layout

| Where | What |
|---|---|
| `bootstrap/` | the compiler as generated C, plus `build.sh`. **Do not edit.** |
| `compiler/` | the compiler in Algol-24 — scanner, parser, resolver, type checker, interpreter, C emitter |
| `vm/` | placeholder for the bytecode VM |
| `tests/` | conformance suites, differential programs, leak canaries |
| `bench/` | `Fib.a24` |

## How it is built

Two stages, because the compiler is written in the language it compiles:

1. `bootstrap/` is C and builds with `cc` alone, giving a working compiler;
2. that compiler compiles `compiler/*.a24` into `./algc`.

⚠️ `build.sh` then compares stage 2's output against `bootstrap/`. They should be
identical — the checked-in C *is* what the compiler emits. A difference means
the seed is stale, which is what you expect right after editing `compiler/`;
`./build.sh --reseed` regenerates it, and the change belongs in the same commit.

## How it is tested

Nothing here is checked against expected output written by hand. The
tree-walking interpreter **defines** the language, so correctness is
differential: a program is run both ways and the two must agree.

```sh
./test.sh unit         # the compiler's own 221 test blocks
./test.sh conformance  # 8 language suites, interpreted
./test.sh compiled     # the same suites compiled -- reports must match
./test.sh programs     # interpreted output vs compiled output, per program
./test.sh fixedpoint   # the compiler reproduces itself, byte for byte
./test.sh leaks        # compiled programs exit without leaking (macOS)
./test.sh memory       # ...and stay inside a peak-memory budget (macOS)
```

⚠️ `leaks` and `memory` are not one check with two numbers. `leaks` asks whether
memory was still *reachable* at exit — and the arena frees every chunk it took,
so a program that allocated 1.27 GB it never needed still reported *0 leaks for
0 total leaked bytes*. That is a real bug this repository shipped: rebuilding a
`Map`'s hash index into a fresh table on every `Remove` made draining one
quadratic in memory, and the leak canaries passed on the broken build. Nothing
was leaked; far too much was allocated. Each `tests/mem/` program carries its own
budget in a `/// MAXRSS:` header.

The fixed point is the interesting one. It compiles `compiler/` with the seed,
compiles it again with the result, and requires the two emissions to be
**byte-identical**. That is a determinism check as much as a correctness one: no
hash-order iteration, no timestamps, no addresses may reach the emitted text. A
compiler can be correct and still fail it, and no other check would notice.

## Licence

See [LICENSE](LICENSE).
