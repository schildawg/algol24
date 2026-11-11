# Algol-24 — releases

Cumulative, newest first. Each entry says what changed and why, at the level
someone deciding whether to upgrade needs — not at the level of a commit log.

For how the *language* arrived, see `spec/HISTORY.md`. For why a particular
thing looks the way it does, see the proposal in `finished/`. For what the
language **is**, `spec/ALGOL-24.md` is the authority and every rule in it is
claimed by a case.

⚠️ **No counts are quoted here.** Every harness prints its own totals, and a
number in prose is a claim nothing checks — this file has watched three of them
go stale.

---

## v0.2.7 — a line of text could come back two characters short

A correctness release, and the only thing in it is a defect v0.2.6 introduced.
**Upgrade if you are on v0.2.6.**

### What was wrong

v0.2.6 made text collectable, which means a block of memory holding one string
can later hold another. One thing in the runtime had quietly depended on that
never happening: a small cache remembering how many **characters** a string has,
keyed on **where its bytes are**. While text came from an allocator that never
freed, that key was safe — a given address held one string for the life of the
process. With a heap that recycles, a different string of the same **byte**
length can arrive at the same address and be answered with the old one's
character count.

**What a program saw** was a string silently a few characters short — a wrong
answer rather than an error, and deterministic rather than random.

⚠️ **IT TAKES A MULTI-BYTE CHARACTER TO SHOW AT ALL.** In text that is entirely
ASCII the character count *is* the byte count, so a stale answer is the same
answer and nothing goes wrong. It needs a string whose two counts differ — one
containing an emoji, an accent, a CJK character or a typographic dash — to have
occupied the block first. That is why it survived a release: every gate here
passed, and the program that found it renders half a megabyte of mixed text.

**Where it bit:** `algol24.com` D-3. Building the site under the tree-walking
interpreter produced one line out of 27,875 that differed from what the other
two processors produced:

```diff
- <p>Sets the color a viewport's pen draws in.</p>
+ <p>Sets the color a viewport's pen draws i</p>
```

41 bytes of plain ASCII, landing on the block of a 41-byte line that contained
one em dash — 39 characters — and answered 39.

### Who was affected

| | |
| --- | --- |
| text that is entirely ASCII | **not affected**, in any processor |
| a program that never calls `Collect` and runs briefly | **not affected** — nothing is recycled |
| mixed-script text, with collection on | **affected**, rarely and silently |

All three processors share the runtime, so all three could produce it; it was
found in the interpreter because that is what the site compared.

### Two new ways to see memory go wrong

- **`ALG_TEXT_CHECK=1`** recomputes every cached text length where the cache
  answers it, and fails naming both answers. This is what found the defect
  after reading the code three times did not, and it is to a stale length what
  `ALG_POISON=1` is to a released object.
- **`collector.sh` runs every case a third way** under it.

### Upgrading

Nothing to change: a program that ran under v0.2.6 runs here and computes the
same answers, with one fewer way to be wrong.

⚠️ **Both halves of the runtime move together.** `algol.c` and `algol.h` are
hand-written and copied verbatim by `--compile`, and the body uses what the
header declares. Anything assembling a build from both a compiler's output and
a checkout must take the pair from the same release.

---

## v0.2.6 — text is collectable, so a long-running program stops growing

A memory release. **The language gained nothing and lost nothing**: every rule,
every diagnostic and every answer is what v0.2.5 gave, which the whole corpus
under three processors is what says. What changed is that a program can now run
for a long time without its memory climbing.

The driving measurement is a game that would not stay up. `shroom-slots` ran
the Dew Drop Inn until the operating system killed it — 10.1 GB on a 15.6 GB
device, with no error and nothing in the crash buffer, because nothing had gone
wrong in the program. Its arena grew about **229 KB a frame**. It is **flat**
now, at 29 MB over a thousand frames.

### Why a String used to be permanent

Text came from the arena, which never frees. A `Value` carried a raw pointer
into it with no owning object, so the collector had nothing to sweep — every
`Str`, every `+`, every `Copy` and every case fold was held for the life of the
process. A program that built one string a frame grew without bound, and no
amount of calling `Collect` changed it.

Text now lives in a heap the collector marks and sweeps, like every other kind
of value. **A program that discards text gets the memory back.**

| | before | after |
| --- | --- | --- |
| two million discarded strings | 138.7 MB | **8.2 MB** |
| the Dew Drop Inn's arena, over a thousand frames | +229 KB a frame | **flat** |
| `algc --compile compiler/Main.a24` | 53.0 MB | **46.9 MB** |
| `algc --test compiler/Main.a24` | 298.5 MB | **258.3 MB** |

### Compiled programs collect on their own

Before this, compiled Algol-24 collected only where a program called `Collect`
itself. It now collects at the top of every loop body, which is the one shape
that allocates without bound — the tree walker has done the equivalent since
v0.2.4 and the machine since v0.2.0, so all three processors now manage their
memory whether a program asks or not.

`ALG_COLLECT_EVERY=0` turns it off, and `ALG_COLLECT_EVERY=N` sets the
interval; the default is a measurement rather than a fact, which is why it is
adjustable at all.

### What it costs

**The bytecode machine is about 13% slower and nothing else is measurably
slower at all.** `Fib (27)` on `algvm` goes from 0.70 s to 0.79; the same
program compiled is unchanged, and so is `algc --compile`.

The reason is where the cost falls. Making an intermediate value visible to the
collector costs something each time a program moves a heap reference about, and
that is exactly what the machine's instruction handlers do — once per
instruction. Compiled arithmetic pays a type test and nothing more, because an
Integer is never on the heap to begin with.

So the Dew Drop Inn under the machine gives back part of what v0.2.5 won, and
the compiled Inn is where it was: **42 fps against 43** under a software
renderer. If you are running the machine on something speed-critical and your
program does not build text, `ALG_COLLECT_EVERY=0` is the dial.

### Three smaller leaks, each its own shape

- **A case fold is cached.** `ToUpper` and `ToLower` copied on every call, so
  the cost was proportional to the number of *calls* rather than to the
  distinct strings. The machine folds a name for every member read, so a loop
  containing a single built-in call grew for ever.
- **A file owns its line buffer.** Reading a file line by line allocated one
  buffer per line and never got it back. It allocates once per file now.
- **A Buffer is reclaimed when abandoned.** `Free` is still how a program
  releases one early, and a Buffer is still the right way to accumulate text —
  the difference is that forgetting to free one is no longer permanent.

### Two new diagnostics for memory

- **`ALG_MEM_REPORT=1`** writes what the heap and the arena hold at exit:
  chunks, room, bytes used, bytes live, and how many times the collector ran.
  It earns its place — it is what found a single line costing 6.9 GB.
- **`ALG_POISON=1`** now covers text as well as objects. A released block is
  filled and withheld rather than handed back out, which separates *the
  collector freed something live* from *something reused a block too early*.
  That split was the whole diagnosis four times in this work.

### Upgrading

Nothing to change. A program that ran under v0.2.5 runs here and computes the
same answers; what differs is how much memory it uses while doing it. If you
have been working around text growth — reaching for `Buffer` where `+` would
have read better, or restarting a long-running process — those workarounds are
no longer load-bearing.

⚠️ **Both halves of the runtime move together.** `algol.c` and `algol.h` are
hand-written and copied verbatim by `--compile`, and the body uses what the
header declares. Anything assembling a build from both a compiler's output and
a checkout must take the pair from the same release; a mismatch is one line
now rather than twenty `cc` errors.

---

## v0.2.5 — the machine runs the Dew Drop Inn at 37 fps, where it ran at 20

A performance release. **The language gained nothing and lost nothing**: every
rule, every diagnostic and every answer is what v0.2.4 gave, which the whole
corpus under three processors is what says. What changed is how fast the
bytecode machine runs, and one thing it changed for the compiled back end too.

The driving measurement is `shroom-slots`' Dew Drop Inn, the program that
decides whether the machine is fast enough to play a game on. It went from
**48.7 ms a frame to 26.8** — 20 fps to 37 — so a 30 fps frame is 80% full
where it used to be 119% of one. `Fib (27)` went from 1.35 s to 0.69 s.

### The dispatch loop is written in C

`algvm` now dispatches through hand-written C over the **same Algol-24
handlers**, which remain the definition of every opcode. It is generated from
the machine's own handler table, so adding an opcode means regenerating rather
than remembering, and the build checks that the generated file is current.

Worth **1.51×**, which is the first thing here that corrects a projection: the
proposal that argued for this work estimated 1.7× from a four-opcode spike, and
said to treat that as a reason to try rather than a number to plan with. It was
right to.

`--algol-loop` runs without it. An optimization over handlers that remain the
definition needs a way to be turned off, and not having one is what made a
platform problem hard to diagnose.

### `is` and `as` stopped comparing strings

`alg_is` and `alg_cast` took the type as a **string the compiler wrote**, so
every type test paid a table scan and a case-insensitive comparison for
something fixed when the C was emitted — and in a profile of the Inn they were
the two heaviest functions in the whole program, above addition.

They are resolved at compile time now: a built-in type becomes an integer
compare, and a class becomes a walk comparing class identities rather than
names. This is the one item that reaches **every compiled Algol-24 program**
rather than only the machine, though its size depends entirely on how much a
program asks: the machine gains about 10%, `algc --test` about 4%, and
`algc --compile` nothing measurable.

Three guards decide when a name can be resolved, and each exists because
answering otherwise would be **wrong rather than slow**. A built-in type name
is not reserved — `class List` is legal, and `[1] is List` and `X is List` are
then both true. Two units may declare a class of one name, and the other two
processors match a class by name, so comparing identities there would answer
differently. And a singleton, an enumeration or a subrange sharing the name
keeps the string form.

### A field read is one lookup instead of two

Reading a field asked whether the instance had it and then asked for it; it now
asks once where the field holds anything but nil, which is the common case. The
member read also folds the written name once instead of three times.

### Smaller, and recorded rather than quoted

An `OP_ADD` fast path, worth about 2.6%, whose real finding was that the
**stack costs more than the arithmetic**: the machine's value stack is an Array,
so every push and pop went through the runtime's general subscript. The rest of
that work is written up in `finished/PROPOSAL-VM.md` as the live enhancement,
with the measured reason to expect more from the opcodes that do nothing but
move values.

### Windows

`algvm` on Windows gets the C dispatch loop with link-time optimization, like
every other platform. That was in doubt: the loop is reached by looking up a
symbol in the binary's own exports, and `-flto` and MinGW's
`--export-all-symbols` disagreed about the address — the symbol was found, the
pointer was not the function. Annotating the two names the loop offers is the
fix, and the build now probes for a working combination by **calling through
the pointer** rather than by checking that a flag was accepted.

### Nothing in the language changed, and that is checked rather than claimed

Both corpora pass under all three processors with no divergence, the compiler
is still a fixed point under its own output, every recorded defect still
reproduces, and `shroom-slots`' own verification run answers identically to the
interpreter. The upgrade is safe for any program that ran on v0.2.4; the only
visible difference is that it finishes sooner.

---

## v0.2.4 — sixteen defects, every one reported by a program that uses the language

The first release driven entirely from outside. Nothing here was found by
reading the compiler; every item came from `shroom-slots`, a game of about
twenty units, or from `algol24.com`, this language's own website — both written
in Algol-24 by people meeting the language as users of it. All sixteen reports
are closed, and `./defects.sh` is a new harness that holds them closed.

### Five reports were one bug

A bare name was resolved against **every declaration in the program** rather
than against the file it was written in. So a name declared in any unit could
quietly take over a name in another, and the C back end was the only processor
that got it wrong — which meant a program ran correctly interpreted and
misbehaved when built for release.

Its worst shape: a program-level variable named after an imported enumeration's
member read as **the member**, so every assignment to it was discarded in
silence and the name was permanently truthy. In the game that meant paying out
every win and charging for no spin, with the balance climbing and nothing
warning. Its most confusing shape put an error *inside a unit the program never
edited*, naming the wrong file as the one needing an import.

Two new rules say what the answer is. **[MOD-016]**: a file's own top-level
declaration is resolved before its imports. **[MOD-017]**: a top-level
subprogram *visible in a file* is resolved before a member of a class declared
there — and one that is **not** visible does not enter the question at all. The
second was measured in both directions before it was written, because the
behaviour is sharp: the same class body means different things depending on what
its own unit imports.

### A runtime error now says where it happened

In the **interpreter** and the **bytecode machine**: file and line, on a second
line below the message.

⚠️ **Compiled Algol-24 deliberately does not carry source information at run
time**, and will not. Carrying it means the emitted C storing a position before
every statement — a cost every program pays forever so that a failing one can be
read. A program that wants that runs under the machine, which can **disassemble
itself**: `--list` walks every chunk, `--trace N` keeps a ring of the last N
instructions with the stack pointer, frame base and call depth, and
`--watch TEXT` dumps the instant a message is raised, caught or not. That is the
division of labour the machine exists for, and **[ERR-003]** now states it.

Each processor finds the location its own way, which is the point: the walker
publishes it as it runs, and the machine **recovers it from its own instruction
pointer** where a fault is caught — so the machine pays nothing at all until
something fails.

### `ErrorLn`, and why the language needed it

**[RT-030]** adds one built-in: `ErrorLn` writes a line to the **error stream**,
taking any number of values and joining them exactly as `WriteLn` does.

The language previously had **no way to reach that stream**. A program that
detected something wrong had to write to its own output, so a diagnostic could
not survive `prog > results.txt` without corrupting what the program produced —
it had to choose between being seen and being separable. Fixing the runtime
error above was impossible without it.

It flushes standard output first, which fixes a second thing: **a program's own
output now comes before the error that stopped it.** It always had,
chronologically; standard output is buffered the moment it is redirected, so in
every pipe and every log a program appeared to fail before it had printed
anything. A program's last output before dying is the most useful thing it has.

⚠️ **That reordered every located diagnostic too, and the old order was the
artefact.** A parse error's excerpt was always written before its message and
only *appeared* second because it sat in a buffer. **[ERR-005]** now shows
excerpt-then-message, which is what every other compiler prints.

### A diagnostic names the file its token came from

It used to name the **root** file over whichever file had last written that line
number — so a fault inside an imported unit was reported against the program,
over a line the program need not even have. One case pinned a three-line
program being blamed for line 12.

### The tree-walking interpreter collects garbage

It had declined to, for a reason that had stopped being true: its live values
were said to sit in C locals where no collector could see them, which the
precise shadow stack overtook. **2.8× less memory for about 9% more time** on
the heaviest interpreted run available.

⚠️ **The compiled back end has had a precise collector since v0.2.0** and never
leaked. That is easy to misremember as a machine feature and is not.

### Two warnings where the compiler knew and waited

A call whose argument count matches **no declaration** of the name, and a name
that **cannot be reached** from where it is written. Both used to be discovered
when the line ran — which in one case meant a shipped program that could not
start at all, and in another an abort on a device with no console, where the
language's good message went to a stream nobody was reading.

Both are **warnings and not refusals**, because both programs are legal: a free
name on a path that never runs is never resolved. The cost is made visible
rather than forbidden.

### Smaller fixes, each with a sharp edge

- **A built-in's name folds** like any other identifier, so `Clock` is `clock`.
  It did not in the C back end, where eleven of eleven non-canonical spellings
  became latent aborts. It bit unevenly, which is why it lasted: `clock` is the
  only built-in spelt lower-case, so writing the natural `Clock` was enough —
  and the library had exactly that, waiting for a caller.
- **A built-in can be held as a value** in compiled code, which it could not at
  all. `var F := Length` is interned, so `Length = Length` is true across units.
- **Two units whose names differ only in case** are refused on every platform
  alike. Unrefused the program meant three different things at once.
  ⚠️ macOS and Windows fold filenames and **Linux does not**, which is the
  opposite of the natural guess.
- **A field of `this` beats a built-in** of the same name, read bare inside a
  method; a **visible global** beats the field. Two processors disagreed in
  opposite directions.
- **`algol.c` and `algol.h` refuse to build as a mismatched pair.** Assembling
  one of each used to give twenty errors reading as a corrupt runtime; it now
  gives one naming the real fault.
- **A missing `--out` directory** says so, rather than naming a file nobody
  asked about.
- **`Expect expression!`** carries its file, line and caret, which it alone did
  not — and it is the error a semicolon after `end` produces.

---

## v0.2.3 — four fixes an installed program could meet and a developer could not

Found by packaging the language for three platforms rather than by reading it.
A `uses` resolves against an installed library on Windows as well: a path is cut
at either separator, and nothing asks whether a directory exists, because
`FileExists` opens the path and opening a directory succeeds on two platforms of
three. A nested subprogram's C symbol carries what it is nested in, so two of
one name in different parents no longer emit one function; and a nested
`external` binds a local rather than a global handle.

`./installed.sh` is the harness for the question every other one assumed away.

## v0.2.2 — the machine reports its version, from the one place that holds it

`algvm` answers `--version` and `--help` as `algc` does, and both read one
constant, because a version in two places is two answers to one question.

## v0.2.1 — a `uses` reaches an installed library

The one thing a library needs in order to *be* one: a `uses` finds a unit in an
installed library, not only one beside the program or in the working directory.
**Nearer still wins**, so installing a library can never change what an existing
program means by a name. Found by trying to write the formula that installs it.

## v0.2.0 — a third processor, a collector under all three, and five rules corrected

`algvm` is a bytecode machine that runs the same language the interpreter and
the compiled back end do, and it **hosts `algc` compiling itself** to
byte-identical C. Under all three there is now a **precise** garbage collector —
no stack scanning, because a module-level variable is a C static and an
Algol-24 local is registered where it is declared.

The language itself gained nothing and had **five rules corrected**, every one
found by building a third processor rather than by reading: a constructor goes
through selection, a chain's field initializers are seeded before any
constructor body, `super` is not exempt from the undefined-member rule, and NaN
is not ordered — including by `<=` and `>=`, which a negated `>` had been
answering backwards.

⚠️ That last one is the lesson of the release. `clox` emits `>=` as `<` plus
`not` and saves two opcodes by it; every ordered comparison with NaN is false,
so negating one answers **true**. The corpus could not catch it and a library
assertion could: `AssertNear` guards itself with exactly the shape the negation
inverts, so a NaN difference *passed* a test written to catch it.

## v0.1.6 — the language is stable rather than closed

Three things the library asked for, each with its own proposal and its own
measurements: **bitwise operators** over Integers that are two's complement
extended infinitely to the left, so no width is named anywhere; a **precision
for `Str`**, correctly rounded from the value rather than by text surgery; and
**wider `Buffer` accessors**.

This release replaced the sentence saying the language was *done*, which had
been rewritten at every release that disproved it. The policy since: **the
language is stable, not closed** — it changes only on measured demand from a
project using it, and the measurement goes in the proposal.

## v0.1.5 — the language was opened once

**Extension functions.** A top-level subprogram marked `extension` may also be
called with method syntax on its first parameter, so `S.Trim ()` and `Trim (S)`
are one call. Asked for by `algol24-library` as a user of the language, which is
the shape every later opening has taken.

⚠️ An extension is **permission, not a new kind of declaration**. A member of
the name always wins at a call, visibility is the file's own `uses` list and
nothing wider, and `extension` is a context-sensitive identifier rather than a
keyword.

## v0.1.0 — the language, complete

Nineteen chapters of specification, every rule claimed by a case, and a compiler
written in Algol-24 that compiles itself. A C compiler is the only dependency,
because the only way into the language is a checked-in copy of its own output.
