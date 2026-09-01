# Algol-24

**Legacy meets the future. Strength meets beauty. Power wrapped in simplicity.**

Algol-24 is a retro-modern language: classic Pascal syntax over unbounded
integers, full Unicode, gradual types, closures and a foreign function
interface. Its compiler is written in Algol-24 and compiles itself.

```pascal
type Color = (Red, Green, Blue);

class Point;
var
    X : Integer;
    Y : Integer;

begin
    constructor Init (X : Integer, Y : Integer);
    begin
        this.X := X;
        this.Y := Y;
    end

    operator + (Other : Point) : Point;
    begin
        Exit Point (X + Other.X, Y + Other.Y);
    end

    function ToString () : String;
    begin
        Exit '(' + Str (X) + ', ' + Str (Y) + ')';
    end
end

var Sum := Point (1, 2) + Point (10, 20);
WriteLn (Sum);                                  // (11, 22)

for var C in [Red, Green, Blue] do
    WriteLn (Str (C) + ' is ' + Str (C.Ordinal));
```

There is **no JDK, no Maven, no make**. A C compiler is the only thing needed to
get from nothing to a working compiler, because the only way into the language
is a checked-in copy of its own output.

## Install

```sh
brew tap schildawg/algol24
brew install algol24
```

The formula and its CI live in `packaging/`; foreign calls are compiled in, and
on macOS the binary depends on nothing but the operating system.

Or from source — this takes about two seconds:

```sh
git clone https://github.com/schildawg/algol24
cd algol24
./bootstrap/build.sh              # -> bootstrap/algc
./bootstrap/build.sh --ffi        # ... able to call C, needs libffi
```

## Using it

```sh
algc program.a24                         # run it
algc --test program.a24                  # run its test blocks
algc --compile --out=build program.a24   # emit C
cc -std=c11 -O2 -o program build/*.c     # and build it
```

The emitted directory carries the runtime with it, so that last line is all
there is to it.

## Two back ends, one language

```
Scanner → Parser → Resolver → TypeChecker → ┬→ Interpreter  (tree-walking)
                                            └→ CEmitter     (C11)
```

A program that fails to parse or type-check fails identically whichever back end
is asked for. More than that: **every case in the corpus produces byte-identical
output through both**, which is the strongest check the project has that the two
describe one language.

## What it has

Classes, objects and enumerations. Closures and nested subprograms. Exceptions.
Modules, including circular ones. Five collections and two resources.

**Unbounded Integers** — arithmetic past the machine width grows rather than
wrapping. **Unicode throughout** — Unicode source, Unicode identifiers, and text
measured in characters rather than bytes, so `Length ('你好')` is 2.

Varargs and named arguments, with a `[WARN]` when a call will bind at run time.
`break`, `continue`, labels and `goto`. Operators a class may define — arithmetic,
comparison through `Compare`, subscripting through `Get` and `Put`. A foreign
function interface that reaches C, so a program can call SDL or libm directly.

`examples/hello-scripts/` draws a pie chart and the word *hello* in Turkish,
Greek, Chinese, Korean and Spanish — with color emoji — into an SDL2 window.
Everything in the picture is drawn by the Algol-24 program.

## How it is checked

Four harnesses, all of which must pass:

| | |
| --- | --- |
| `./test.sh` | 220 unit tests, inline in the source they cover |
| `./conform.sh` | 179 conformance programs and 55 refusals, under **both** processors |
| `./spec/spec.sh` | every rule in the specification cites something that exists |
| `./fixedpoint.sh` | the seed matches what the compiler emits, and emits itself unchanged |

`spec/ALGOL-24.md` is the specification — 280 rules, every one claimed by a case.
It is the authority, and the implementation is measured against it: where the two
disagree, `spec/DEFECTS.md` names the defect and carries a program that
reproduces it. `spec/HISTORY.md` holds how the language arrived.

## Status

**v0.1.0 — the feature-complete alpha release.** The language is done; what
comes next is a library, written in Algol-24 rather than in the runtime:
collections, and a unified text-and-graphics unit over SDL. That is the whole of
what *alpha* means here — nothing in the language is provisional.

## Licence

MIT.
