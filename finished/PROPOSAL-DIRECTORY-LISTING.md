# Proposal: a directory listing in the core

> **FINISHED — accepted, built, and shipped in v0.4.0.**
> `Entries (Path) : List` is [RT-026]'s fifth directory built-in, and
> `conformance/0224-a-directory-lists-itself.a24` is the case. The five open
> questions in *The shape* below are all answered, four of them as the body
> guessed:
>
> - **`.` and `..` are left out.** The body called this "not quite `readdir`"
>   and worried at [RT-026]'s own principle; the deciding argument turned out
>   to be that the library's `Directory` already omits them, so matching it is
>   what lets this replace the three foreign calls without changing an answer.
> - **The order is the filesystem's**, stated in the rule, which is why the
>   case sorts every listing before printing it.
> - **A failure raises in the directory family's voice** —
>   `Entries failed: cannot open 'x'.` — because `Entries` is one of them. A
>   missing path, a path naming a file, and a directory that cannot be read
>   are one answer and not three.
> - **[MOD-002]'s concession is NOT withdrawn**, as the body's last section
>   recommended. The rule now says the folded lookup is a *decision* rather
>   than a limit, and names the measurement still missing: nobody has reported
>   a `uses` that resolves on one platform and fails on another.
> - **Whether the library's three externals come out** is still the library's
>   call and its own release.
>
> ⚠️ **ONE THING THE BODY DID NOT PREDICT, and it is the whole of what went
> wrong: the tree walker's collections are `ObjCollection` and never the
> host's.** Handing back the host List that `alg_entries` answers gave a value
> that *rendered* as a List and was one to nothing else — `E.Length` reported
> `Only instances have properties.` and `E is List` was false, while
> `Str (E)` printed `[alpha.txt, …]` perfectly. No previous directory built-in
> could meet it: the other four answer `nil` or a String. The compiled back
> end and the machine both use host collections directly and were right from
> the first build, so this was the interpreter alone.
>
> ⚠️ **It cost TWO GENERATIONS of the seed, for the reason a new operator
> does.** The interpreter's arm *calls* `Entries`, so the checked-in seed has
> to know the name before it can emit a call to it: generation 1 emits
> `alg_error("Undefined variable 'Entries'.")` into `Interpreter.c` and
> generation 2 is the first that works. `fixedpoint.sh` iterates for exactly
> this, and the intermediate generation is a compiler that compiles correctly
> and cannot *interpret* the new built-in.
>
> ⚠️ **AND THE CALLER THE ARGUMENT RESTS ON IS STILL NOT WRITTEN.** The case
> for the core is that the module loader cannot reach a library unit, and the
> loader does not call `Entries` — folding the `uses` lookup [MOD-018] is the
> work that would, and it is deliberately not taken. So this is the first of
> [RT-001]'s names with no caller inside the compiler or the machine, which
> `PROPOSAL-CONCURRENCY.md` records as the one exception to its bar.

**Status:** accepted and built, shipped in v0.4.0. Written 2026-11-07, out of
`finished/PLAN-0.2.4.md` item 6.

[RT-026] gives the core four directory built-ins — `MkDir`, `RmDir`, `ChDir`,
`GetDir` — and no way to **list** one. This proposes a fifth.

It is written because two separate pieces of work wanted it independently and
neither could have it: `algol24-library` needed it badly enough to write a
foreign shim, and the compiler's own module loader needs it to make [MOD-002]
platform-independent and cannot reach the library's.

---

## The demand, measured

**`algol24-library` already implemented it, in C, through the FFI.**
`file.a24` carries `class Directory` — Turbo Pascal's `FindFirst` and
`FindNext` as an object rather than a `SearchRec` the caller holds and hands
back — and `Entries (Path) : List` as sugar over it. Its own doc comment names
the gap outright:

> The core can make, remove and change directories [RT-026] and cannot list
> one, which is the gap this fills.

Three of `file.a24`'s twenty-two `external` declarations exist only for this:

```
external 'alg_libdir_open'  in 'libfileffi.so';
external 'alg_libdir_next'  in 'libfileffi.so';
external 'alg_libdir_close' in 'libfileffi.so';
```

behind which `fileffi.c` wraps `opendir`, `readdir` and `closedir` over a fixed
table of handles. **The C is written and tested**, which is the part of this
proposal that is not speculative.

**The compiler cannot use any of that**, for three reasons that each hold
alone:

- The module loader is `compiler/Parser.a24`, which is **in the seed**. It may
  import the compiler's own units and nothing else, because the only way into
  the language is a checked-in copy of its own output.
- `algc` is built **without `--ffi`** by default [INI-008], so a foreign call
  there answers `Foreign calls are not available in this build`.
- The library is a separate repository, and the compiler depending on it would
  invert the relationship between the language and a program written in it.

So the capability exists in the language and is unreachable from the one place
that would make a language rule platform-independent. That asymmetry is the
argument.

---

## What it would settle

**[MOD-002] is the rule, and it currently concedes the platform.** A module
name is the one place [SRC-011] does not reach: the filesystem decides how it
is matched, case-insensitively on macOS and Windows and sensitively on Linux.
So `uses scanner;` finds `Scanner.a24` on two platforms out of three.

⚠️ **Measured rather than assumed**, because the obvious guess is wrong:
macOS is the case-**insensitive** one. Writing `unit.a24` beside `Unit.a24` on
this machine's APFS overwrote it — one file, the first spelling kept. **Linux
is the outlier.** (APFS can be formatted case-sensitive, so even one platform
is not uniform, which strengthens the case rather than weakening it.)

With a listing, the loader could fold the lookup: read the candidate directory,
compare each entry's stem folded, and answer the match. `uses alpha;` would
then find `Alpha.a24` **everywhere**, and [MOD-002]'s concession could be
withdrawn rather than restated.

**What it would NOT change** is the meaning of a found program. v0.2.4 already
folds everything the language owns — the unit registry, the duplicate check,
the file a back end names after a unit — and refuses two units whose names
differ only in case on every platform alike [MOD-018]. This proposal is about
*findability* only, which is the half that is still the platform's.

---

## How the other languages answer the same question

Four strategies, splitting on whether the language itself folds:

| | strategy | who |
| --- | --- | --- |
| 1 | don't fold; require an exact match | Java, Haskell, Rust |
| 2 | verify the case you were given, so the strict answer is uniform | Python, PEP 235 |
| 3 | encode case out of the storage key | Go — `Sirupsen` is cached as `!sirupsen` |
| 4 | fold everywhere, and do the searching yourself | Free Pascal |

Strategy 1 is unavailable: case-insensitivity is not a detail of this language
but one of its commitments [SRC-011]. Strategy 2 would make the language refuse
what the filesystem was willing to give, which is uniform but is uniformly
*stricter* than the rule says. Strategy 3 applies to a package cache a tool
owns and not to a path a programmer wrote.

**Strategy 4 is the one this language is already shaped for**, and it is the
nearest relative's answer: Free Pascal is case-insensitive, treats unit names
in `uses` case-insensitively, and does the searching itself rather than letting
the filesystem decide. Turbo Pascal never faced the question — DOS folded.

Strategy 4 is exactly what a listing makes possible, and nothing else does.

---

## The shape

One built-in, answering a List of the names in a directory:

```
Entries (Path) : List
```

Not an iterator. The library's `Directory` is right to be one — `ReadAll`'s
lesson is that the incremental form is the primitive — but a built-in cannot be
a class, and the loader wants all the names at once anyway. A program wanting
the incremental form keeps using the library's, which would then be sugar over
this instead of over three foreign calls.

Open questions, which is why this is a proposal and not a plan:

- **`.` and `..`**: the library's `Directory` omits them, on the ground that
  every caller would filter them and the ones that forgot would recurse
  forever. A built-in should probably do the same, but that makes it not quite
  `readdir`, and [RT-026]'s own principle is that each built-in *does exactly
  what its name says and nothing on the way*.
- **Order**: the filesystem's, which is neither sorted nor stable between runs.
  Saying so is honest; sorting would be a decision the name does not imply.
- **Failure**: `Entries` on a missing path, a file, or an unreadable directory.
  The library raises `Entries: cannot open '<Path>'.`; the core's directory
  built-ins answer `nil` as `Write` does, except `GetDir` which reports. Which
  convention this follows is a real choice.
- **Whether to withdraw [MOD-002]'s concession at the same time.** The listing
  makes a folded lookup *possible*; actually folding it changes which programs
  find which files on Linux, and that is a second decision with its own
  compatibility question.
- **Whether the library's three externals come out.** They should eventually,
  but that is the library's call and its own release.

---

## Why it is not in v0.2.4

v0.2.4 is a defect sweep. This is a feature, and it would be the second time
that sweep turned into one — the first being the warnings in item 4, which at
least answered defects that were reported.

[MOD-018] fixes what was actually broken: a program that meant three different
things on one platform now means one thing on all three. What remains is that
`uses alpha;` may not *find* `Alpha.a24` on Linux, which [MOD-002] has always
stated and which no project has yet reported as a cost.

**That last sentence is the thing to watch.** The policy here is that the
language changes on measured demand from a project using it, and the
measurement goes in the proposal. The demand for *listing* is measured and
recorded above. The demand for a *folded lookup* is not: nobody has reported a
`uses` that failed on Linux and worked here. Until someone does, this proposal
should probably land as the built-in alone, leaving [MOD-002] as it stands.
