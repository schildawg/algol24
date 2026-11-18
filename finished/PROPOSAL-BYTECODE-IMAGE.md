# Proposal: a compiled program as a file

> **FINISHED — built in v0.5.0.** `algvm --emit prog.a24 --out=prog.a24b`
> writes a program's bytecode and `algvm prog.a24b` loads it, deciding by the
> four bytes at the front of the file rather than by its name. The Dew Drop
> Inn starts in **14 ms where it compiled in about 3,400** — 240× on the front
> end, and 0.02 s against 3.4 s of process time.
>
> It answers open question 3 of `finished/PROPOSAL-VM.md`: **the image is not a
> committed artifact and is not a second seed.** It carries the release that
> wrote it and is refused by any other build, because an opcode's number is not
> interface.
>
> It also closes a gap in the language that had nothing to do with the machine:
> a `Buffer` could hold bytes and had no way to put them in a file or take them
> out. `Load`, `Save` and `GetText` are [RT-036] and [RT-022].
>
> **What remains open:** nothing checks that an image is newer than the source
> it came from, because the language cannot ask a file its age — so a stale
> image runs stale code until it is re-emitted. An image is also one file per
> root program rather than one per unit, so a program that shares most of its
> units with another shares none of the loading. And the image is read with a
> cursor into one Buffer, which means the whole file is in memory twice for as
> long as the decode takes.

## The measurement

`algvm --time --stop inn.a24`, `shroom-slots` at the commit this was written
against, on an Apple M-series laptop:

| phase | |
| --- | --- |
| scan | 76 ms |
| **parse** | **1,731 ms** |
| resolve | 67 ms |
| check | 104 ms |
| **emit** | **1,399 ms** |
| | **3,377 ms** |

Three runs of the whole compile read 3.35, 3.39 and 3.43 s, so about 3.4 is the
figure and a tenth of a second is the noise.

The same program on a Pixel Fold takes about **13 s**. None of it is the
dispatch loop: the machine has not executed an instruction when the last of
those phases ends. The game then runs at 31 fps, so the compile costs about a
hundred frames' worth of time before the first one is drawn.

That is the whole argument, and it is the one `finished/PROPOSAL-VM.md` already
made from the other side — *process exit is the only garbage collector the
front end has* — with the AST measured at fifty times the source.

## What it costs instead

| | |
| --- | --- |
| image for `inn.a24` | 553,826 bytes |
| writing it | 32 ms |
| **loading it** | **13–14 ms** |
| process time, image | **0.01–0.02 s** |
| process time, source | 3.4 s |

689 chunks and about 100,000 instructions. So the load is **240× inside the
compile** and the measured startup is **about 200×** better, which is further than
this needed to go: anything under a tenth of a second would have been enough,
and the format did not have to be clever to get there.

**It is not clever.** A byte stream with a cursor, no index, no alignment, no
compression, everything little-endian because that is what [RT-022] promises of
a `Buffer`'s own accessors. The numbers that decided it were measured before
any of it was written, in compiled Algol-24 on this machine:

| | per operation |
| --- | --- |
| `Dst[I] := Src[I]` between Buffers | 24 ns |
| `GetInt` | 28 ns |
| `Append` of a ten-byte String | 30 ns |
| `List.Add` | 30 ns |

At those rates half a megabyte of image is tens of milliseconds whatever the
encoding, so the encoding was chosen to be obvious rather than tight.

## What the language was missing

A `Buffer` is the language's record of bytes and has been since [RT-022]:
`PutInt`, `GetInt`, `PutWord`, `GetWord`, `PutDouble`, `GetDouble`, byte
subscripting, a documented byte order. What it could not do was reach a file.
`TextFile` reads and writes *lines of text* [RT-024], and `Buffer.Text` refuses
a buffer holding a zero byte — so there was no way to write a byte image at
all, and no way to read one.

So the first thing an image needed was three members, and they are the whole of
the language change:

| | |
| --- | --- |
| `Load (Name)` | the file's bytes become the Buffer's |
| `Save (Name)` | the Buffer's bytes become the file's |
| `GetText (At, Length)` | those bytes as a String |

**`GetText` is the inverse `Append` never had.** A record written into a Buffer
could be read back field by field for every type but text, which is the one a
file format is mostly made of.

**Three and not four.** A `PutText` looks like the missing fourth and is not
needed: a Buffer grows by `Append`, which takes a String's bytes already, and a
fixed-width field is written by reserving that many ASCII characters and
overwriting them —

```algol24
var At := Out.Length;

Out.Append ('....');
Out.PutInt (At, N);
```

— which is the one idiom in `vm/Image.a24` worth learning before reading the
rest of it. The same trick measures a String's **byte** length, which is what a
reader has to be told and what `Length` does not answer: append it and take the
difference.

⚠️ **`Append (Char (N))` IS NOT A BYTE**, which is why reserving is necessary
rather than merely tidy. `Append` takes the *text* of a value [RT-022], so
`Char (200)` appends the two bytes of its UTF-8 and `Char (0)` appends one.
Every fixed-width field in the format is reserved and written through for that
reason.

### Why not the foreign function interface

`algvm` always has foreign calls [FUN-014], so `fopen`, `fread` and `fwrite`
were available with no language change at all, and `vm/dispatch.c` is the
precedent for C the machine reaches through a no-library `external`.

Rejected for two reasons. The machine's own loader would then depend on libc
symbols by name for its core function, where everything else it does is in the
language. And the gap would still be there: `shroom-slots` already ships C
shims to read PNGs because the language cannot read bytes, which is the second
project to have worked around this.

### Why not a TextFile binary mode

`BlockRead` and `BlockWrite` over an untyped file is Turbo Pascal's answer and
the lineage this language's file members otherwise follow. It is a wider
addition than the one taken: a record size on the open, a position, a partial
read, and four calls plus a file variable to do what two members do. A Buffer
holds all of a file or none of it, so the state those features need is state it
has not got.

## The format

Everything little-endian. A text field is a four-byte byte count followed by
the bytes; a value is a one-byte tag followed by its payload.

```
'A24B'              four bytes of magic
u32                 format version -- this encoding, not the release
text                the release that wrote it
text                the source it was emitted from
u8                  1 for a test image, 0 for a run image
chunk               the script
value               the test table
```

and a chunk is

```
u32                 how many bytes of code
bytes               the instructions
value               the constants      (a List)
value               the global names   (a List)
value               the global keys    (a List)
value               the line offsets   (a List)
value               the line numbers   (a List)
text                the file it was emitted from
```

The twelve tags are nil, false, true, a four-byte Integer, an Integer as
decimal text, a Double, a String, a Char, a List, a subprogram, a built-in,
and a back-reference.

**A subprogram's body is a chunk**, so the tree of chunks is the recursion of
the value encoder and needs no table of its own. Nothing else in the machine's
world has to be written down: a class is built at run time by `OP_CLASS`,
`OP_METHOD` and `OP_FIELD`, an enumeration by `OP_ENUM`, and a subrange by
`OP_SUBRANGE` — which `vm/Vm.a24` already notes is what keeps a chunk
self-describing.

⚠️ **AN INTEGER IS UNBOUNDED, so a fixed field cannot hold every one** of them
[LEX-018]. One past four bytes goes as its decimal digits and is rebuilt by
arithmetic, which is exact at every magnitude — where reading it back as a
number would not be, since `Val` answers a `Double` [RT-009].

⚠️ **THE BACK-REFERENCE IS WHAT KEEPS THE OBJECT GRAPH'S SHAPE** rather than
merely its contents. A built-in held as a value is **one** value per name —
`Length = Length` is true, and these compare by identity [VAL-011] — so a
fresh `VmBuiltin` per constant would answer false where the compiler's own
interning answers true. The writer keeps every subprogram and built-in it has
written in the order first seen and the reader keeps the same list, so an index
means the same object on both sides without the index being in the file.

⚠️ **A LIST CONSTANT IS WRITTEN OUT EVERY TIME IT IS MET, deliberately.** No
program can reach one: the emitter makes them for a named call's argument names
and for a subrange's bounds, and both are read by the machine alone. Interning
them would cost a scan per constant to preserve an identity nothing can
observe.

⚠️ **`Count` BYTES OF CODE AND NOT `Code.Length`.** A chunk's Buffer is longer
than its instructions — the slack is what `Write` appends into — so writing all
of it would put whatever the last doubling left between one chunk and the next.
There is a unit test on exactly that, because the round trip would otherwise
succeed and the file would be larger than the program.

## Why it is refused by another build

An opcode's **number** is not interface. `vm/OpCode.a24` renumbers freely, and
CLAUDE.md's own advice for adding one is to append it above `OP_COUNT` and
renumber nothing *because* the number carries no promise. So the same bytes
mean different instructions in two builds, and an image is bytecode.

So the release that wrote an image is in its header and a mismatch is a
refusal:

```
This image was written by algvm 0.4.2 and this is algvm 0.5.0.  Re-emit it.
```

The format version is separate from it and answers a different question: the
release says whether the **bytecode** is this machine's, and the format version
says whether the **wrapper** is. A reader that could not tell them apart would
report an encoding it cannot read as a stale program.

⚠️ **THIS IS WHAT MAKES AN IMAGE A BUILD ARTIFACT RATHER THAN A SEED**, which
is the shape open question 3 offered as the alternative. A committed image
would be a second thing to keep in step with `compiler/*.a24`, with no
`fixedpoint.sh` to hold it there — and the only way to know it was stale would
be to compile the program and compare, which is the cost it exists to avoid.

## Two modes, two images

Under `--test` a unit's bare statements are not compiled and its test bodies
are [TST-003], so what is in the chunk differs and one file cannot serve both.
`--emit --test` writes a test image carrying the test table, and asking for the
wrong one is refused by name rather than run:

```
This image was emitted to run, not to test.  Re-emit it with --test.
This image was emitted to test.  Run it with --test.
```

That `--test` is worth the second artifact is R-19's lesson rather than a
guess: **nothing ran `algvm --test` until a crash in the machine's own emitter
was found downstream**, and a three-second wait per test run is part of why.
`lobby.a24`'s 151 tests run identically from a test image and 2.5 s faster.

⚠️ **THE IMAGE CARRIES THE SOURCE'S PATH, so that a failing test names it.**
A test report names its root file, and an image naming *itself* there would
make the two reports differ over a path rather than over a test. Caught by
reading the reports rather than by anything going red, because every test
passed.

## The gate

`./vm/image.sh` runs both corpora from an image and compares each one with the
**machine's own output from source**, case by case. Currently **222 identical
to the compile, 63 refused before emitting, 0 diverged**.

⚠️ **THE FIXTURES ARE THE WRONG ORACLE HERE, which is worth saying because
comparing against them looks equivalent.** The question is not whether the
machine agrees with the specification — `vm/conform.sh` asks that — but whether
a program loaded from a file answers what the same program compiled answers. A
case the emitter refuses by name has no recorded output to compare against, and
a case whose fixture records a build without foreign calls has one that
describes neither run. Against the machine itself both work out: a refusal
compares to the same refusal.

⚠️ **A CASE REFUSED BEFORE EMITTING IS STILL COMPARED.** The program never got
as far as an image, so what is checked is that `--emit` refuses it exactly as a
run refuses it — a front end that answered differently depending on where the
back end's output was going is the defect that catches.

⚠️ **IT BUILDS ITS OWN MACHINE** rather than using `vm/algvm`, because a stale
one passes this check perfectly: it would write an image and read it back with
the same wrong opcodes. `defects.sh` builds its own for the mirror of that
reason.

⚠️ **WHAT IT CANNOT CHECK is a program that prints its own name.**
`ParamStr (0)` is the image's path where a compiled run answers the source's
[RT-013]. Two corpus cases reach for it and both ask only whether it is
non-empty, so nothing had to be rendered away — but a case that printed it
would need the treatment `render()` gives a `[WARN]`.

## What was measured end to end

| | from source | from an image |
| --- | --- | --- |
| `inn.a24`, startup | 3.4 s | **0.02 s** |
| `verify.a24`, 59 lines | 8.47 s | 8.23 s, identical output |
| `lobby.a24 --test`, 151 tests | 14.95 s | 12.45 s, identical report |

`verify.a24` is the case that puts the saving in proportion: it spends eight
seconds computing, so keeping the compile is worth 3% of it. The Inn is the
program this was built for, and the game is the shape that cares — a player
waits for the compile every time where `verify` waits for it once in a batch.
