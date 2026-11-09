# Proposal: Algol-24 is single-threaded, and concurrency is a library concern

**Status:** proposed, not decided. Written 2026-11-09, out of a question asked
after v0.2.5: the language has no concurrency story at all, and the
specification reserves nothing for one.

This proposes **a rule and no built-in**. The rule says what the model is;
everything a program would call is a library unit, and the library already has
what it needs to build it.

⚠️ **THE FIRST DRAFT PROPOSED A `Spawn` BUILT-IN AND WAS WRONG.** The argument
was that a library should not have to carry three operating systems' process
APIs. It already does — see below — so the argument was about a burden that had
been paid before the document was written. What is left is the rule, which is a
statement about the language rather than a capability, and the refusals, which
are language questions.

---

## The bar a built-in has to clear

Every one of [RT-001]'s built-ins is used by **the compiler or the machine
itself**, and that is what makes them built-ins rather than library units. The
reason is structural: `compiler/Parser.a24` is in the seed and may import the
compiler's own units and nothing else, because the only way into the language
is a checked-in copy of its own output — and `algc` is built without `--ffi` by
default [INI-008], so a foreign call there answers `Foreign calls are not
available in this build`.

Counted rather than assumed, over `compiler/*.a24` and `vm/*.a24`:

| built-in | uses |
| --- | --- |
| `ParamStr` | 36 |
| `FileExists` | 11 |
| `clock` | 9 |
| `TextFile` | 8 |
| `Collect` | 5 |
| `Foreign` | 4 |
| `MkDir`, `RmDir`, `ChDir`, `GetDir` | 2 each |

Even [RT-026]'s four directory built-ins, which look most like Turbo Pascal
compatibility imported wholesale, are reached by the compiler's own code. There
is no built-in in the list that exists only for programs.

**`Spawn` would be the first.** Neither the compiler nor the machine ever
starts a process — checked, and there is not one call site between them. So it
fails the bar, and the bar is the right one.

This is the same argument `PROPOSAL-DIRECTORY-LISTING.md` makes *for* a
built-in, which is why it is worth stating as a rule rather than re-deriving:
a directory listing belongs in the core because **the module loader needs it**
and cannot reach the library's. Process spawning has no such caller.

---

## The demand, measured, and why it is not an argument for the core

**The Dew Drop Inn spends 27.64 seconds before its first frame, and 1.74 of
them compiling.** Measured against `algvm` at v0.2.5:

| | |
| --- | --- |
| `algvm inn.a24 --frames 1`, wall | **27.64 s** |
| of that, inside the frame loop | 0.035 s |
| `algc --compile inn.a24`, the whole front end | **1.74 s** |
| so: the program's own start-up work | **~26 s** |

That 26 seconds is `shroom-slots` loading art and computing props serially, on
one core, with nothing shared between sheets. It is the measurement that also
killed bytecode caching — caching would have saved the 1.74 and left the 26.

It is a real demand, and it is a demand on **the library**. Nothing about it
reaches the compiler or the machine.

---

## The library already carries this

`algol24-library` ships **eight C shims** and **110 `external`
declarations**, and one of those shims is `dosffi.c` — 470 lines, already
spawning processes on both families:

```c
#ifdef _WIN32
    if (!CreateProcessA (path, line, NULL, NULL, FALSE, 0, NULL, NULL,
...
    int err = posix_spawn (&child, path, NULL, NULL, argv, ALG_ENVIRON);
    while (waitpid (child, &status, 0) < 0)
```

`dos.a24`'s `Exec (Path, Args) : Integer` is the Algol-24 face of it: no shell,
an argument vector rather than a command line, and — the only words that matter
here — *"The call waits for the program to finish."*

So the asymmetry a built-in was going to absorb is **already absorbed, in the
library, in the file where the rest of it lives**. What async needs is small
and sits beside code that does the hard part:

- `posix_spawn` without the `waitpid`, answering the child's id;
- `waitpid` with `WNOHANG`, for asking without blocking;
- a pipe: `posix_spawn_file_actions_adddup2` on POSIX, `CreatePipe` plus a
  `STARTUPINFO` on Windows.

`file.a24` can already read the result: it handles a stream that cannot be
re-opened or seeked, and records that `stat` answers the bytes currently
buffered for a pipe.

---

## What the rule would say

That execution of a program is **single-threaded**; that no value is shared
between concurrent executions; and that concurrency is by **isolated
processes**, which communicate in bytes.

It earns its place for three reasons, none of which is a capability:

- **It makes the absence a decision.** The specification currently reserves
  nothing, so the silence reads as an oversight. Every other settled question
  in this language has a rule — [MOD-018] for case folding, [CLS-019] for how a
  bare name resolves in a method — and this one does not.
- **A library may rely on isolation rather than hope for it.** A `Tasks` unit
  is only safe to write if the language promises that a child shares no value
  with its parent. Today that is true by accident of implementation.
- **It says why there is no `lock`.** A reader who comes from Java or Go will
  look for one, and the honest answer is a sentence rather than an omission.

Where it goes is a question for whoever writes it: `Spawn` would have belonged
in §16 beside [RT-026], but a statement about execution is not a statement
about a built-in.

---

## What is refused, and these are language questions

Unlike the above, each of these would have to be in the language, and each is
refused for a measured reason rather than for taste.

**Threads, locks and atomics.** The runtime keeps about twenty pieces of
process-wide mutable state — the arena, the object registry, the per-unit root
tables, `all_buffers`, `all_files`, `seq_spares`, the subrange table, the
interned built-ins, the `setjmp` frame stack and the shadow stack. Threads
would need every one of them thread-local, including **`alg_root_top`, which
generated code reads and writes inline** precisely because a call per block
boundary was too expensive. The shadow stack alone measured **+5.8%** on the
VM's `Fib (27)`; a thread-local on that path is a cost every single-threaded
program would pay so that some programs could have threads. And data races
become expressible, in a language whose stated principle is that code should
read beautifully.

**`async` / `await`, and coroutines.** Both need execution to suspend and
resume. That is easy on `algvm` — a coroutine is a saved `IP` and a stack
slice, which is how Lua does it — and very hard in the other two processors:
the tree walker's live state sits in C locals of a recursive evaluator, which
is the same reason its collector was long thought impossible, and compiled
Algol-24 runs on the C stack. **A feature one processor of three has is not a
feature of this language.** Coroutines are a fine thing and deserve their own
proposal; they are not a concurrency story here.

**`parallel begin … end`, and typed channels.** The first reads well and buys
nothing a library `WaitAll` does not, while putting a scheduler inside the
language. The second wants a copy protocol for arbitrary values, which is a
larger question than the measured demand asks — the Inn's art is bytes.

⚠️ **A RE-ENTRY CONVENTION IS THE ONE THING A LIBRARY GENUINELY CANNOT DO.**
A task taking a *subprogram* rather than a program — `Task (LoadSheet, Path)` —
needs the child to run this program's own code. `fork` gives that free on a
Unix and does not exist on Windows, where a child starts fresh. A documented
"re-enter at this named subprogram" flag honoured by `algvm` and by compiled
binaries would make it portable.

It is deferred by a number in this document: a child that re-executes the
program **recompiles** it, and the Inn takes 27.6 s to start. That only works
behind a pool of workers that pays start-up once — which is library work. So
the language should wait and see whether the pool makes the convention
unnecessary, rather than add a flag on the strength of a surface nobody has
written yet.

---

## Why it is not in v0.2.5, and what would change the answer

The rule could land at any time; it is a paragraph and it describes what is
already true.

What would reopen the built-in question is a measurement the library cannot
answer: a `Tasks` unit built over `dosffi.c`, used by `shroom-slots` to load
its art, that is *still* unable to do the job — because process start-up
dominates, or because a pool cannot be written portably, or because the
subprogram-granularity surface turns out to be the only usable one. That
report, with its numbers, is what the core should respond to.

That is the order the directory listing followed, and it is the order the
policy asks for: the language changes on measured demand from a project using
it, and the measurement goes in the proposal.
