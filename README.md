# Algol-24

A Pascal-flavoured, gradually typed language whose compiler is written in
itself. It interprets a program or emits C for it — and it does both to its own
source: the test suite runs the compiler under the interpreter, and the build
compiles it to C and checks that the result reproduces itself byte for byte.

`bootstrap/` holds the compiler's own C output, checked in, so **a C compiler is
the only prerequisite**. There is no bootstrap chicken-and-egg to solve and
nothing to install.

```sh
./build.sh            # -> ./algc
./test.sh             # all seven suites
```

## A taste of it

```pascal
type
    Suit = (Clubs, Diamonds, Hearts, Spades);

class Card;
var
    Rank : Integer;
    Of?  : Suit;

begin
    constructor Init (Rank : Integer, Of? : Suit);
    begin
        this.Rank := Rank;
        this.Of?  := Of?;
    end

    function Describe () : String;
    begin
        if Rank < 1 or Rank > 13 then raise 'No such rank: ' + Str (Rank);

        Exit Str (Rank) + ' of ' + Str (Of?);
    end
end

var Hand := [Card (7, Hearts), Card (13, Spades)];

test 'A hand describes itself';
begin
    AssertEqual (2, Hand.Length);
    AssertEqual ('7 of Hearts', Hand[0].Describe ());
end

begin
    for var Each in Hand do
        WriteLn (Each.Describe ());

    try
        WriteLn (Card (99, Clubs).Describe ());
    except
        on E : String do WriteLn ('caught: ' + E);
    end
end
```

```
7 of Hearts
13 of Spades
caught: No such rank: 99
```

Things that program is quietly demonstrating:

- **Gradual typing.** `Hand` has no annotation and needs none; `Rank : Integer`
  is checked wherever the checker can see a type to check it against.
- **Tests are a language construct**, not a library. `test` blocks live beside
  the code they cover and run with `--test`. The compiler's own 220 tests are
  written this way.
- **`?` is a letter**, and so is `!`. `Of?` and `Commit!` are ordinary
  identifiers, as is any name in Unicode letters.
- **Pascal's operators**, not C's: `=` compares, `:=` assigns, `<>` is
  inequality. Semicolons *terminate*, including the one before `end`. `Exit`
  returns and carries the value; there is no `return`.
- **`Length` and `IsEmpty` are properties** on a collection, written without
  parentheses. `Length (S)` is the function form, and works on a string.
- Exceptions carry a value, and a handler selects on its type. `raise 42` caught
  by `on E : Integer` works exactly as the string form above does.

Two things regularly catch people out. A one-character literal is a `Char` and
never a `String`, so `'z'` and `'zz'` are different types and never compare
equal. And truth is not C's: `nil`, `False`, the **Integer** `0` and an enum
member of ordinal 0 are falsey, while `0.0`, `''` and every `Char` are truthy.

## Using it

```sh
./algc Prog.a24                   # interpret
./algc --test Prog.a24            # run its test blocks
./algc --compile Prog.a24         # emit C into ./out
./algc                            # no arguments: runs the built-in sample

./compile.sh Prog.a24             # emit, build, -> build/Prog
./compile.sh Prog.a24 --run a b   # ...and run it with arguments
```

`CC` (default `cc`) and `CFLAGS` (default `-std=c11 -O2`) are honoured by every
script, and each resolves its own root, so they run from any working directory.

`--out` defaults to `out` and **the directory must already exist** — the
language cannot create one, so every caller `mkdir -p`s first.

## How the build works

```
bootstrap/*.c  --cc-->  stage 1  --compiles compiler/*.a24-->  stage 2  ->  ./algc
                                                                  |
                                          diff -r against bootstrap/
```

Stage 2's emitted C is compared against the checked-in seed. A difference means
the seed is stale: `./build.sh` says so and carries on, and `./test.sh
fixedpoint` treats it as a hard failure. So a compiler change is

```sh
./build.sh && ./test.sh && ./build.sh --reseed
```

committing `compiler/` and `bootstrap/` together.

`bootstrap/algol.c` and `algol.h` are the hand-written C runtime rather than
generated output, and are edited in place — they are copied verbatim into every
emitted directory, so a runtime change takes effect with no reseed.

## Testing

**Nothing here is compared against hand-written expected output.** `ALGOL-24.md`
is the specification and the interpreter is the reference implementation, so
correctness is differential: a program runs both ways and the two must agree.

Where they disagree, the interpreter is usually the one that is right — but not
always, and the specification says which. `Length([1, 2])` is `6` interpreted
and `2` compiled, and it is the interpreter that has the bug.

```
$ ./test.sh
-- unit the compiler's own test blocks
-- conformance the language suites, interpreted
-- compiled the same suites compiled -- reports must match
-- programs differential: interpreted output vs compiled output
-- fixedpoint the compiler reproduces itself, byte for byte
-- leaks compiled programs exit without leaking (macOS)
-- memory compiled programs stay inside their memory budget
All green: unit conformance compiled programs fixedpoint leaks memory
```

That design has one blind spot worth stating plainly: **a bug that affects both
halves equally is invisible to a differential test.** The conformance suites and
the fixed point exist to cover it, and it is still where the interesting defects
come from — see `tests/defects/` below.

`fixedpoint` builds generation 2, has it emit generation 3, and requires the two
to be byte-identical. That is a *determinism* check: no hash-order iteration, no
timestamps, no addresses may reach the emitted text. Correct code can fail it and
nothing else here would notice.

`leaks` and `memory` are different instruments rather than one with two numbers.
`leaks` asks what was still reachable at exit; `memory` measures peak RSS against
a budget each program carries in its own header. A program that allocated 1.27 GB
it never needed once reported "0 leaks for 0 total leaked bytes" — that was a
real bug this repository shipped, and only the second instrument saw it.

### The two generating harnesses

`test.sh` runs pinned cases. `collide.sh` and `depth.sh` instead **write
programs**, varying one along an axis the language allows and asserting an
invariant. They are not in `test.sh` — together they add about half again to its
running time, and their value is periodic rather than per-commit.

```sh
./collide.sh                            # 24 mutants on the name-collision axis
./depth.sh                              # uses-chains of depth 1..8
./collide.sh --only object-root-private # one case; a failure prints this line
./depth.sh --keep                       # leave the generated tree behind to read
```

**`collide.sh`** builds 24 mutants from one clean seed — six declaration kinds ×
{root, module} × {public, private} — each shadowing a name its own import
exports. Names are the axis because per-file emission makes a name the only way
one file's C can conflict with another's.

Its oracle is the negative one. A *named* refusal is a documented narrowing and
is legal; what is never legal is emitting C that `cc` or `ld` then rejects. Over-
refusal would slip past that, so a second clause pins the whole partition as a
rule — a mutant is refused **if and only if** the host is a module and the name
is public — and checks the refusal *sentence*, not just the bucket, so a new
collision-shaped refusal cannot satisfy it for the wrong reason.

**`depth.sh`** generates `uses` chains one level at a time. Its first clause is
collide's oracle, and the ordinary build now exercises that too. Its reason to
exist is the second: `--test` must run **one test per module plus the root's**.

That count is the point. The obvious oracle — "the program still works" — would
have missed the finding this was built for, because the program *did* work: it
ran, printed the right answer, and interpreted and compiled agreed. What failed
was that two of its tests never ran, and no differential check can see that,
since both sides agree about the tests they know about. When the failure mode is
silent **omission**, only a count catches it, and a generator can hold one
because it wrote the tests and knows how many there are.

A mutant that fails is not a fixture. These are the *search*; `tests/` is the
pinned record. Promote a failure into a suite by hand once it has failed, so the
harness stays adversarial.

### The optional capability

Graphics is the one thing a conforming processor may decline to provide, and it
is compiled in only under `-DALG_SDL`. Everything `test.sh` runs must pass for
someone who has nothing but a C compiler, so nothing there needs SDL —
`tests/conformance/Window.a24` asserts the behaviour of a build *without* it.

`sdl.sh` is the opt-in harness for the rest, and runs a program both ways:

```sh
./sdl.sh --test examples/WindowedTest.a24   # headless, both processors, compared
./sdl.sh --show examples/Windowed.a24       # on a real display
```

It renders headless through `SDL_VIDEODRIVER=dummy`, which is what makes drawing
testable at all: a window that can be read back with `Pixel` answers questions,
and a machine with no screen can still ask them.

## Layout

| Path | |
|---|---|
| `compiler/` | the compiler, ~14k lines of Algol-24 in 22 modules |
| `bootstrap/` | the checked-in seed, plus the hand-written C runtime |
| `tests/` | conformance suites, differential programs, leak and memory probes |
| `tests/defects/` | reproductions of known defects — these fail on purpose |
| `collide.sh`, `depth.sh` | generating harnesses — they write programs rather than run fixtures |
| `sdl.sh` | opt-in harness for the one optional capability, run by hand |
| `examples/` | programs that need something `test.sh` does not require — currently a display |
| `third_party/` | vendored code this project did not write |
| `bench/`, `vm/` | benchmarks, and a placeholder for the bytecode VM |
| `ALGOL-24.md` | the language specification |
| `CLAUDE.md` | orientation for agents working in the repository |

The pipeline is one front end feeding two back ends:

```
Scanner -> Parser -> Resolver -> TypeChecker -> { Interpreter | CEmitter }
```

The shared prefix is deliberate. A program that fails to parse or check must
fail identically whichever back end is asked for, or the two stop describing one
language.

Two pieces of that are worth knowing before reading the source. Module loading
lives in the **Parser**, not in the driver, because the parser is what follows a
`uses` clause. And the emitter produces one `.c` and `.h` per *source file*,
which is what lets `private` become C's `static`.

## Known defects

`tests/defects/` holds reproductions written as tests that assert the *intended*
behavior, so every file in it fails today. It is deliberately outside
`test.sh`'s suites, and its `run.sh` inverts the usual convention — it exits
non-zero only when a reproduction **passes**, which is the signal the defect is
closed and the file should graduate into a real suite. The directory is meant to
shrink.

Five are open, tracked as
[issues](https://github.com/schildawg/algol24/issues) and indexed offline in
`tests/defects/README.md`. The oldest is
[#1](https://github.com/schildawg/algol24/issues/1): identifiers are
case-sensitive and are not meant to be, across twelve surfaces, with both
processors agreeing on eleven of them — which is precisely why the differential
suites never caught it.

`ALGOL-24.md` keeps no defects. It carries *Open decisions* instead: questions
the language has not yet answered, each with a recommendation and each blocking
the first release.

## The team

| Name | Role | |
|---|---|---|
| **Schildawg** | Project lead | owns the language; settles the [open decisions](ALGOL-24.md#open-decisions) |
| **Plumb** | Specification & conformance | maintains `ALGOL-24.md`, probes both processors for compliance, writes the tests in `tests/defects/` that decide it, and files the gaps as issues |
| **Tiller** | Product management | owns the order of the backlog — sequences the open issues, keeps the dependencies between them visible, and says what is pulled next |

More to be added as they join: a Developer pulling tickets, a Tester approving
the work before it merges, and a Client building on Algol-24.

Tiller does not decide *whether* an issue ships. The backlog is the first
release: Schildawg specified it feature by feature, Plumb wrote it up as issues
and conformance tests, and when it is empty Algol-24 is at v1. What is left to
decide is the order, and the order is not free — the issues gate one another,
and every change to `compiler/` ends in a reseed that rewrites the generated
`bootstrap/`, so two tracks worked at once collide there. Sequencing is
therefore a real cost, and it is the job.

The separation is deliberate. Specification, implementation and approval are
held by different people, so no one marks their own homework — see
[The Prime Directive](CLAUDE.md#the-prime-directive) for the six conditions a
fix has to meet, and `tests/defects/README.md` for who owns the tests that
measure the first of them.

## Status

Pre-1.0, and development is **spec-driven**. `ALGOL-24.md` is normative — it
states what the language *shall* do, not what the implementations currently do —
so a rule is in it because it is right, and where an implementation does not yet
match, the rule stands and names the issue tracking the gap.

**The first release is the point at which the specification says what it should
say and the implementations do what it says.** What stands between here and
there is nine open defects and four open decisions, all listed.

A defect counts as fixed only when all six of these hold — the project's
**Prime Directive**:

1. every test associated with the issue passes;
2. every existing suite still passes;
3. the Tester approves it, with no regressions introduced;
4. it runs on the current bootstrap;
5. it builds a new bootstrap and runs there too;
6. that new compiler emits a third generation byte-identical to the second.

The last three are the two-stage build and the fixed point, which `./build.sh`
and `./test.sh fixedpoint` perform. The emitted C is compared exactly: no
tolerance for timestamps, because a timestamp reaching emitted text is itself
what the fixed point exists to catch.

The compiler is self-hosting, at a verified fixed point, with the whole suite
green. The tree-walking interpreter is the reference implementation; the C back
end is what makes it fast. A bytecode VM written in Algol-24 is the intended
third project — see `vm/README.md` for why it is deferred and what it will get
to assume.

Licensed under Apache 2.0.
