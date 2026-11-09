# Proposal: concurrency by isolated processes, and the one built-in it needs

**Status:** proposed, not decided. Written 2026-11-09, out of a question asked
after v0.2.5: the language has no concurrency story at all, and the
specification reserves nothing for one.

Two things, and the second is a paragraph:

- **`Spawn`**, a built-in that starts a program and answers an object carrying
  its streams and its status — `TextFile`'s shape, for a process.
- **A rule saying what the concurrency model is**: execution is
  single-threaded, values are never shared between concurrent executions, and
  concurrency is by isolated processes.

Everything a program would actually call — run these in parallel, wait for
them all, keep a pool of workers — is then a **library unit**, and belongs in
`algol24-library` rather than here. That division is the whole of what this
proposes.

---

## The demand, measured

**The Dew Drop Inn spends 27.6 seconds before its first frame, and 1.74 of
them compiling.**

Measured on 2026-11-09 against `algvm` at v0.2.5:

| | |
| --- | --- |
| `algvm inn.a24 --frames 1`, wall | **27.64 s** |
| of that, inside the frame loop | 0.035 s |
| `algc --compile inn.a24`, the whole front end | **1.74 s** |
| so: the program's own start-up work | **~26 s** |

That 26 seconds is `shroom-slots` loading art and computing props — guest code,
running one unit after another, on one core. It is embarrassingly parallel:
each sheet is read from a different file and nothing shares state with
anything. A machine with eight cores spends 26 seconds using one of them.

**It is not the compiler's problem and it is not the machine's.** Caching
bytecode would save the 1.74 s and leave the 26 — which is the measurement
that killed that idea when it was raised, and the same measurement that makes
this one worth having.

A second, weaker demand sits beside it: the Inn runs at **26.8 ms a frame, 37
fps**, logic-bound rather than SDL-bound, with the other cores idle. That one
is weaker because a per-frame task would pay a copy at the boundary, and
nothing has measured whether the copy is cheaper than the work.

---

## What exists already, and what is actually missing

**`dos.a24` already runs programs.** `Exec (Path, Args) : Integer` spawns
without a shell, passes an argument vector rather than a command line, and —
the relevant words — *"The call waits for the program to finish."* It does not
capture the child's output; the child inherits the parent's streams.

**`file.a24` already knows how to read a pipe.** It handles a stream that
cannot be re-opened or seeked, and records that `stat` answers the bytes
currently buffered for one. What it has no way to do is *make* one.

**The runtime has none of the machinery.** Checked rather than assumed: zero
occurrences of `pipe(`, `O_NONBLOCK` or `poll(` in `bootstrap/algol.c`.

⚠️ **CAPABILITY IS NOT THE GAP, and this is the part that decides the
proposal.** A library could do all of it through the FFI today: `fork`,
`posix_spawn`, `pipe`, `dup2` and `waitpid` are libc, and
`CreateProcess`/`CreatePipe`/`WaitForSingleObject` are kernel32. Nothing here
needs the language's permission.

What a library cannot do gracefully is carry **three operating systems' process
APIs**. The runtime already absorbs exactly this kind of asymmetry, once, for
exactly this reason — `algol.c`'s own comment above its dynamic-loading shim:

> Windows does the same three things under different names, so they are given
> the POSIX ones and the rest of this file does not have to know.

A process is the same shape of problem as a shared library, and the same
sentence should cover it.

---

## Why it is a library and not a language feature

Three reasons, each sufficient.

**The three-processor rule.** Anything that suspends and resumes execution is
easy on `algvm` — a coroutine is a saved `IP` and a stack slice, which is how
Lua does it — and very hard in the other two. The tree walker's live state sits
in C locals of a recursive evaluator, which is the same reason its collector
was long thought impossible; compiled Algol-24 runs on the C stack. A feature
one processor has is not a feature of this language.

**Shared memory would tax every program.** The runtime keeps about twenty
pieces of process-wide mutable state — the arena, the object registry, the
per-unit root tables, `all_buffers`, `all_files`, `seq_spares`, the subrange
table, the interned built-ins, the `setjmp` frame stack, and the shadow stack.
Threads would need every one of them thread-local, including **`alg_root_top`,
which generated code reads and writes inline** precisely because a call per
block boundary was too expensive. The shadow stack itself measured +5.8% on
the VM's `Fib (27)`; a thread-local on that path is a cost every
single-threaded program would pay so that some programs could have threads.

**Isolation keeps the collector simple.** A per-process heap means a task
collects alone, with no stop-the-world coordination and no cross-thread root
sets. Precise roots keep falling out of module-level variables being C statics,
which is the property the whole collector rests on.

And the aesthetic argument, which is not a tiebreaker here but points the same
way: for a language whose stated principle is that code should read beautifully,
`lock` is an admission that the language let you make a mistake. Under
isolation, a data race cannot be written down.

---

## How the other languages answer the same question

| | model | what it costs them |
| --- | --- | --- |
| **Erlang** | isolated processes, message passing, copied values | a bespoke scheduler and runtime |
| **Go** | goroutines plus channels, shared memory underneath | a race detector ships with the toolchain |
| **Rust** | shared memory, races refused by the type system | an ownership system this language does not have |
| **Lua** | coroutines, one OS thread | concurrency without parallelism |
| **Python** | threads, a global lock | the lock, and twenty years of arguing about it |
| **Turbo Pascal** | nothing | — |

Erlang's answer is the one that fits, for the reason Erlang chose it: isolation
is what lets the runtime stay simple. This proposal takes the model and not the
scheduler — the operating system is the scheduler, and processes are the
isolation.

That is also the retro-modern line. Pascal had no concurrency at all; Algol-24
gets the **modern** answer rather than the 1990s one.

---

## The shape

```
var Job := Spawn ('/usr/local/bin/algvm', ['load.a24', 'reels.png']);

Job.Output.ReadLn ();        // the child's standard output, as a TextFile
Job.Input.WriteLn ('go');    // its standard input
Job.Done                     // has it finished, without blocking
Job.Wait ()                  // its exit status, blocking until there is one
```

`Spawn` answers an **object**, which is the shape [RT-001] already uses for
`TextFile`, `Buffer`, `Map` and `List` — a built-in that answers something with
members rather than a bare value. Nothing here is new syntax, and the
specification gains one built-in and one rule rather than a subsystem.

**The streams are `TextFile`s** so that `file.a24` reads them with what it
already has, including its handling of a stream that cannot be seeked.

### The alternative considered, and why it loses

**`Pipe ()` answering two `TextFile`s**, leaving the spawn to `dos.a24`. It is
a smaller built-in and it was the first shape proposed. It loses because a pipe
alone does not help: the child needs the write end *as its standard output*,
which is `dup2` inside the spawn path, so the platform branch the library was
trying to avoid is still there. `Spawn` absorbs the branch where the
dlopen shim already absorbs its own.

### The rule

A rule saying: execution of a program is single-threaded; no value is shared
between concurrent executions; concurrency is by isolated processes, which
communicate by bytes. `Spawn` itself belongs in **§16, Built-in functions**,
beside [RT-026]'s four directory built-ins; the model rule is a statement about
execution rather than about a built-in, so where it goes is a question for
whoever writes it. Short, and it earns its place three
ways — it says why there is no `lock`, it tells a library author that
isolation may be relied on rather than hoped for, and it stops the current
silence reading as an oversight.

### What the library would then build

In `algol24-library`, over `Spawn` and the existing `Exec`: start N jobs
without waiting, wait for all of them, keep a pool of workers alive so
start-up is paid once, and a `Tasks` unit that reads the way the rest of the
library does. None of it needs a reseed, and all of it can change without one
— which is the main reason for drawing the line here.

---

## What this deliberately does not propose

- **Threads, locks, atomics.** The thread-local tax above, plus data races
  become expressible.
- **`async` / `await`.** It colours every subprogram that touches it, and the
  suspension it needs is feasible on one processor of three.
- **Coroutines**, for the same suspension reason. They are a fine feature and a
  separate proposal, and they are not a concurrency story here.
- **`parallel begin … end`.** It reads well and buys nothing a library
  `WaitAll` does not, while putting a scheduler inside the language.
- **Channels as syntax.** Bytes over a stream are enough for the measured
  demand; a typed channel wants a copy protocol for arbitrary values, which is
  a larger question and should be asked by a program rather than invented here.

⚠️ **A RE-ENTRY CONVENTION IS THE ONE DEFERRED PIECE WITH A REAL CASE.**
A task taking a *subprogram* rather than a program — `Task (LoadSheet, Path)`
— cannot be done portably: `fork` gives the child the parent's address space on
a Unix and does not exist on Windows, where a child starts fresh. A documented
"re-enter at this named subprogram" flag honoured by `algvm` and by compiled
binaries would make it portable.

It is deferred because of a number in this document: a child that re-executes
the program **recompiles it**, and the Inn takes 27.6 s to start. That only
works behind a pool that pays start-up once, which is library work, so the
language should wait and see whether the pool makes the convention unnecessary.

---

## Why it is not in v0.2.5

v0.2.5 is performance and nothing else, and this is a capability. More to the
point, the policy is that the language changes only on measured demand from a
project using it — and while the 26 seconds is a real measurement, **nothing
has yet tried and failed** to get it back through the FFI. The library doing it
the awkward way first is what would prove the shape, exactly as
`algol24-library` proved the directory listing by writing `fileffi.c` before
`PROPOSAL-DIRECTORY-LISTING.md` asked for it in the core.

So the honest order is: `algol24-library` builds a `Tasks` unit over the FFI,
`shroom-slots` loads its art with it, and if the platform branches are as ugly
as this document predicts, that is the evidence for `Spawn` and the report that
carries it.
