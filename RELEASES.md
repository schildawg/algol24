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

## v0.4.0 — a program can list a directory, and a library's shims are found where its units are

Two features, both asked for by a project using the language, and both of them
the second half of something that shipped incomplete.

```algol24
for var Name in Entries ('art') do          // names, in the filesystem's order
    if Pos (Name, '.png') >= 0 then WriteLn (Name);
```

```algol24
function Draw (X, Y : Integer);
    external 'graph_draw' in 'libgraphffi.so';   // searched, not just dlopen'd
```

### `Entries` — the fifth directory built-in

The language could make a directory, remove one and change into one, and could
not read one [RT-026]. `Entries (Path)` answers a List of the names in it.

| | |
| --- | --- |
| each element | a **name**, never a path — `alpha.txt`, not `art/alpha.txt` |
| `.` and `..` | not answered |
| the order | the **filesystem's**, which is neither sorted nor stable between runs |
| failure | `Entries failed: cannot open '<path>'.`, in the voice the other four use |

A missing path, a path naming a file and a directory that cannot be read are
one answer, because to a program they are one fact: there are no names here to
read.

**Why it is a built-in and not a library unit.** Every other name in [RT-001] is
used by the compiler or the machine itself, which is the bar, and the module
loader is what wants this one: folding a `uses` lookup means enumerating the
stems in a directory, and `compiler/Parser.a24` is in the seed, so it may import
the compiler's own units and nothing else. A library unit is out of its reach by
construction.

⚠️ **It is the first built-in admitted on a caller that is not written yet**,
and that is worth saying plainly: nothing in `compiler/*.a24` or `vm/*.a24`
calls `Entries` today. The bar it clears is "a library version of this would be
unreachable from the seed" rather than "the compiler calls it".
`finished/PROPOSAL-DIRECTORY-LISTING.md` is the record, and
`PROPOSAL-CONCURRENCY.md` states the bar as a rule and now carries the
exception.

⚠️ **THE LIBRARY HAS HAD AN `Entries` SINCE 0.1.6 AND KEEPS IT.** `file`'s
`Entries (Path) : List` is built over its own `Directory` class, and the
built-in's surface was matched to it deliberately — names only, no `.` or `..`,
the filesystem's order — so that the two cannot disagree about an answer. A
declaration forms one overload set with a built-in of the same name at the
counts it declares [FUN-005], so a program that `uses file` still reaches the
library's. Whether those three `external`s come out is the library's own call,
on its own release.

⚠️ **The folded `uses` lookup is now POSSIBLE and is still not done**, which
makes it a decision rather than a limit. Changing which file a program finds
changes what existing programs mean, and nobody has reported a `uses` that
resolves on one platform and fails on another — which is the measurement the
policy asks for. [MOD-018] says so in its own text.

### A bare library name is searched where its unit is

v0.2.1 gave a `uses` three places to look, so `uses graph;` reached a library a
package manager had installed. That was **half an answer for four releases**: a
unit that calls into C is most of what a library is, and a bare name in an
`external … in` clause went straight to the operating system — so the unit
resolved, and the first foreign call failed.

[FUN-017] searches a bare name the same way, and for the same reason: a
library's units and the shared objects they call into are one install.

| | |
| --- | --- |
| 1 | beside the running binary |
| 2 | `lib` beside it |
| 3 | `bin/../share/algol24/lib` |
| 4 | wherever the operating system itself looks |

The system is asked **last**, so a vendored copy wins and a system library is
still reachable. A name holding a separator is **that exact file and nothing is
searched**, so `in '/opt/homebrew/lib/libSDL2.dylib'` means what it always
meant — and its failure names no place, because none was tried.

**Where it fails, it says where it looked.** The commonest cause is a library
installed somewhere the processor does not look, and a message naming only the
library cannot tell that from one never installed at all.

⚠️ **The packaging workaround is gone, and that is the measure of it.** The
formula for `algol24-vm` wrapped the binary in a script that set
`DYLD_LIBRARY_PATH` or `LD_LIBRARY_PATH`, because the library's shims install
into `libexec/lib` and a bare name could not find them. That is the directory
the search looks in second. The wrapper sets no loader path at all now.

⚠️ **THERE IS NO `ALGOL24_PATH`, and the reason is the language rather than
taste.** The proposal offered one and it is refused: there is no `GetEnv`
built-in, so a variable the runtime honored for shared objects would be
unreachable from the module loader — one spelling meaning two different things
for the two kinds of file, which is worse than no spelling at all. Honoring it
for both means a new always-available built-in for a case `cd` answers.

### The gate for it is `./installed.sh`, because no corpus case can hold it

Every conformance run is a build without libffi [INI-008], where no library is
opened at all — so the corpus cannot reach this, and the harness that builds a
prefix is the only thing that can ask. It now installs a unit whose work is
done in C, with its shim beside it, and runs a program from a directory holding
neither. Both of its new checks were seen red before being trusted: with the
search removed, `uses Probe;` resolves and the first foreign call fails, which
is exactly the half-measure this release closes.

It builds its own foreign-call compiler rather than using the checked-in one,
and skips with a note where libffi or a shared library cannot be built — the
bootstrap needs a C compiler and nothing else, and a gate demanding libffi
would make that untrue.

### Upgrading

Nothing to change. Two things are worth knowing:

- **A bare library name now resolves nearer than it used to.** If a shared
  object of the same name sits both beside your binary and in a system
  directory, the nearer one answers where the system's used to. Write the path
  in the `in` clause to pin a particular file; a name with a separator in it is
  not searched.
- **A program declaring its own `Entries`** forms an overload set with the
  built-in [FUN-005] rather than being refused, and answers at the counts it
  declares.

⚠️ **Both halves of the runtime move together.** `algol.c` and `algol.h` are
hand-written and copied verbatim by `--compile`, and the body uses what the
header declares — `Entries` is new in both. Anything assembling a build from
both a compiler's output and a checkout must take the pair from one release.

**The bundle moves too.** `algol24-vm` carries `algol24-library` 0.2.0, which
adds `reflect` — the library's half of the reflection built-ins v0.3.1 shipped,
as two extension functions that describe a value and compare two by content.
The library's number is its own and does not track this one.

---

## v0.3.2 — three defects the library found by using the language

All three were reported by `algol24-library` against 0.3.1, and all three are
cases where a processor disagreed with the other two or with the
specification. Nothing in the language changed.

### `New` did not check its argument count

[RT-034] says `New` and `SetMember` "answer exactly what the written form
answers", and the **tree walker** did not: it checked a constructor's argument
*types* and not its count.

| `New (Needs, …)` where `constructor Init (Arg : Integer)` | before | now |
| --- | --- | --- |
| `[]` — too few | `Index 0 out of range 0..-1.` | `Expected 1 arguments but got 0.` |
| `[1, 2]` — too many | **answered an instance** | `Expected 1 arguments but got 2.` |

⚠️ **The second was the worse one.** Too many arguments was not refused at
all: the extra was discarded and a plausible instance came back, which is the
shape of fault that reports success. A deserializer calling `New (T, [])` to
make a blank instance is exactly the shape that meets the first.

**The check now lives where construction happens** rather than at the call
site, which is why `New` had missed it — a written construction goes through
the call path and `New` does not. Fixing it there uncovered a second
disagreement about an **overloaded** constructor: `Pair (1, 2, 3)` where two
constructors each take one argument reported `Expected 1 arguments but got 3.`
in two processors, naming one candidate's arity as though it were the only one,
where the count is in fact ambiguous and the class is what to name [EXP-014].
All three now answer alike for every constructor shape and both spellings.

### A variadic built-in refused its qualified spelling when compiled

[RT-001] says `Write` and `WriteLn` "take any number of values" and [MOD-011]
says the qualified spelling always reaches the built-in — "which is what makes
taking a name over safe: nothing is put out of reach." The C back end put
exactly that out of reach past one argument:

```
System.WriteLn ('a', 'b')     ->  A call to 'System.WriteLn' is not supported
                                  by the C back end yet.
```

**It landed on one kind of program in particular.** A unit that declares its
own `Write` and `WriteLn` makes the qualified spelling the only console route a
program using it has — so such a program could report a single value and no
more, and could not be compiled at all.

Measuring the whole surface rather than the reported cell found the same
omission in a second place: `Write ()` and `ErrorLn ()` with **no** arguments
were refused in either spelling, the table carrying a no-argument form for
`WriteLn` alone. All three built-ins now take every count through both
spellings, which is 24 cells all answering alike.

### A warning went to standard output, where it mixed with the program's output

A `[WARN]` is **non-blocking**: the program compiles and runs. Writing the
warning to standard output therefore interleaved a diagnostic with what the
program produced, which broke anything comparing that output byte for byte —
and after extension functions, a name that some class gains a member of in a
later version could start narrating into the output of a program that had done
nothing wrong.

**Warnings go to the error stream now** [ERR-010], with standard output
flushed first so a warning never appears ahead of output already written.

⚠️ **An `[ERROR]` excerpt still goes to standard output, and that is the
distinction.** A parse or type error means **no statement runs** [ERR-002], so
there is no program output for it to mix with. A warning is the opposite case
by construction, and the stream is what tells them apart.

### And a fourth, found by fixing the first three

Adding the missing constructor cases to the corpus turned up one the library
had not reached: a **subclass declaring its own constructor also offered its
parent's implicit one** on the bytecode machine.

```algol24
class Base;  var Tag : String;  begin end           // declares no constructor

class Thing (Base);
var Worth : Integer;
begin
    constructor Init (W : Integer); begin Worth := W; end
end

Thing ()        // refused by two processors; the machine CONSTRUCTED one
```

"A class with no constructor takes no arguments" is a property of a class
*without* one, not a signature a subclass inherits [CLS-004]. The machine gave
`Base` a synthesized no-argument constructor — which is right — and then let
selection walk the chain and find it from `Thing`, answering an instance with
its field unset where the other two refuse. Construction selects among a
class's **own** constructors now; the emitter already makes that set complete,
giving a subclass that declares none a forwarder per inherited signature.

### Upgrading

Nothing to change in a program. Two things to check if you read our
diagnostics with a script:

- **A warning now arrives on the error stream.** Anything grepping stdout for
  `[WARN]` must capture stderr instead — this repository's own `spec/spec.sh`
  needed exactly that change, and now also checks that no warning reaches
  stdout.
- **A wrong constructor count reports differently in two cases** that were
  wrong before: `New` with the wrong count now reports it at all, and an
  overloaded constructor with an ambiguous count names the class rather than
  one candidate's arity.

⚠️ **Both halves of the runtime move together.** `algol.c` and `algol.h` are
hand-written and copied verbatim by `--compile`, and the body uses what the
header declares. Anything assembling a build from both a compiler's output and
a checkout must take the pair from the same release.

---

## v0.3.1 — a program can read its own shapes

**Reflection.** A program can ask what a class declares, construct one by a
type it was handed, read and write a field by a computed name, call a method by
one, and ask whether a value satisfies a type — all without a single new piece
of syntax. Every one of them is a built-in or a member of a value the language
already had.

```algol24
var Shape := Fields (Thing);            // name -> declared type
for var F in Shape do
    WriteLn (F, ' = ', Str (Member (T, F)));

var Made := New (TypeOf (T), [7]);      // construct by a type held as a value
SetMember (Made, 'Worth', 11);          // write a field by name
WriteLn (Str (Invoke (Made, 'Scaled', [3])));
WriteLn (Str (TypeOf (5).Accepts (5))); // the dynamic form of `is`
```

### What is new

| | |
| --- | --- |
| `Fields (X)` | a Map from each field's name to its declared type, parent-first [RT-031] |
| `TypeOf (X)` | X's type **as a value**; a class answers itself [RT-032] |
| `T.Name` `T.Parent` `T.Fields` `T.Methods` `T.Properties` | what a class says about itself [RT-032] |
| `Member (X, Name)` `Invoke (X, Name, Args)` | a member read, a method called, by a computed name [RT-033] |
| `New (T, Args)` `SetMember (X, Name, Value)` | construction, and a field written, by a computed name [RT-034] |
| `T.Accepts (X)` | whether a value satisfies a type held as a value [RT-035] |

A type value is **interned**, so `TypeOf (1)` and `TypeOf (2)` are the same
value and compare by identity as a class does. A type is not constructible:
`TypeOf (42) ()` says so rather than answering an `Integer instance`.

### What it is not

**No metaclasses, no attribute hooks, nothing creates or alters a class at run
time.** The data is distilled when the program is built, not held as a live
syntax tree — an AST kept alive for the life of a program is thousands of nodes
retained for a few dozen bytes of metadata. There are no frames, no stacks and
no source: this is not Python's `inspect`.

⚠️ **A computed name REACHES A PRIVATE MEMBER, and that is a trapdoor rather
than an oversight.** `private` is settled before the program runs and nothing
records it at run time [DCL-011], so reflection can do what written code may
not. It is stated in the specification so that it is met on purpose; the guard
that remains is `uses`, since the reading sugar a program actually writes is an
extension [MOD-015].

### A diagnostic that named nothing now names what failed

`No matching signature for function.` named no subprogram, no class and no
member — of no use at all to the generic code this release exists to enable. It
is now `No matching signature for <what was called>.`: a subprogram or a class
by its own name, a method as `Class.Member`.

**And where the name is unambiguous the counts are reported instead.** One
candidate of fixed arity called with the wrong number of arguments has the
count as its whole fault, so `Expected N arguments but got M.` says more. That
removes an asymmetry the language had carried from the beginning: a **method**
answered a selection failure for a wrong count where a **subprogram** and a
**constructor** reported the counts, so one fault read two ways depending on
what you had called.

```
Box (1).Only (1, 2)     No matching signature for function.   ->  Expected 1 arguments but got 2.
Two (1, 2)              No matching signature for function.   ->  No matching signature for Two.
Box (1, 2)              Expected 1 arguments but got 2.       ->  unchanged
```

**This is the one thing in the release that changes what an existing program
prints**, and only in its diagnostics. A program that compares the text of a
caught selection failure will see the new sentence; nothing else moves. A
search across the five projects using this language found no test or source
that compares it.

### Also fixed

Three divergences between the three processors, none of them reachable by any
case in the corpus — which is why they had survived:

- **A raise inside a nested run left the bytecode machine's saved state
  unrestored.** Reachable through `Invoke` from the day it was written: the
  program gave every right answer and then died at its *last statement* with
  `Index -1 out of range`, naming neither the raise nor the nested run.
- **`Only an instance has fields.`** was the machine's wording where the other
  two processors say `Only instances have fields.` — latent for the machine's
  whole life, because nothing in the corpus wrote to a non-instance.
- **A by-name invoke with a wrong argument type** said `Undefined property` in
  the tree walker for a method that was plainly declared, where the other two
  reported a selection failure.

And a gate for the class of bug that produced two of them: `spec/spec.sh` now
holds the machine's built-in arity table, and its variadic exemption, against
the names the interpreter actually registers. A built-in added without an arity
there answered a quietly different sentence on one processor and nothing refused
it.

### Upgrading

Nothing to change unless you compare the text of a caught selection failure.
The new built-in names — `Fields`, `TypeOf`, `Member`, `Invoke`, `New`,
`SetMember` — are now built in, and a declaration of one of those names forms
an overload set with it [FUN-005] rather than being refused, so an existing
program that declares a `New` of its own keeps working at the counts it
declares.

⚠️ **Both halves of the runtime move together.** `algol.c` and `algol.h` are
hand-written and copied verbatim by `--compile`, and the body uses what the
header declares. Anything assembling a build from both a compiler's output and
a checkout must take the pair from the same release.

---

## v0.3.0 — a Char equals a one-character String

**The first release that changes what an existing program means.** Everything
before this either added a capability or fixed something that was wrong; this
one makes a comparison that was false become true. The minor version moves for
that reason and no other.

```algol24
WriteLn ('a' = Copy ('abc', 0, 1));     // false before, TRUE now
```

### What changed, exactly

A `Char` and a `String` holding the same text are now **equal** [VAL-010], and
membership follows [VAL-013] — a Map keyed `Str('a')` is reached by `'a'` and
the other way about. Equality here fails only when the text differs: `'ab'` and
`'a'` are different characters, not different types.

**Nothing else moved.** The types are still distinct, a one-character literal
is still a Char, `'a' is String` is still false, a Char still widens to a
String and never the reverse, and `as String` still refuses a Char. Nothing
converts: neither operand becomes the other's type.

### Why

⚠️ **The language already contradicted itself.** With `C` the Char `'a'` and
`S` the String `Str('a')`, every processor answered `C <= S` **true**,
`S <= C` **true**, `C < S` false, `S < C` false — and `C = S` **false**.
Everywhere else in the language `a <= b` and `b <= a` imply `a = b`. Ordering
had been settled as text while equality refused it, and together they described
an ordering no value can satisfy. One of the two had to give.

⚠️ **And it was producing defects in real programs** — two of them, in two
different projects, both silent, both fixed by this with **no edit to either
program**:

- An image viewer filtered by a mode that could never filter: a cast made one
  side a String while the literal stayed a Char, so the test was always true
  and every entry passed.
- A game never read back its saved window position: the keys came from parsed
  JSON and so were Strings, while `'x'` and `'y'` are one character each and so
  were Chars. ⚠️ **`'zoom'` is why nobody noticed** — the same function reads
  three keys and the four-character one worked, so the window remembered its
  zoom and forgot where it was. A rule that breaks the short keys and not the
  long ones in one function is not a rule a programmer can hold in their head.

The clearest sign was how the old rule was reached: writing a **type
annotation**. `var F : String := 'x';` then `F = 'x'` answered false, where
without the annotation both sides are Chars and it answered true. Adding a
declared type silently changed a comparison's answer.

### Does this break your program?

Almost certainly not, and that was established three ways rather than assumed:

| | |
| --- | --- |
| a search across four codebases | nothing |
| a **type-checker sweep** over 389 files in six codebases | three sites — one was a defect, two were this project's own probes |
| the one shape that would actually break | present in none of the seven codebases |

The shape to check, if you want to check: a collection deliberately holding
**both** a Char and a one-character String as distinct keys. Those are now one
key. Everything else — including the 77 places across these codebases that
wrapped a literal in `Str(…)` to make a comparison work — keeps answering what
it answered, because `Str('x') = 'x'` compares a String to a String either way.

### Upgrading

Nothing to change. Those `Str(…)` wrappers are no longer needed and can go
whenever it suits; they are not wrong, only redundant.

⚠️ **Both halves of the runtime move together.** `algol.c` and `algol.h` are
hand-written and copied verbatim by `--compile`, and the body uses what the
header declares. Anything assembling a build from both a compiler's output and
a checkout must take the pair from the same release.

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
