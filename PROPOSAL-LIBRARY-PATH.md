# Proposal: A Library Path

> **HALF OF THIS SHIPPED, AND HALF IS STILL OPEN.** The document is as it was
> written; this header is the only thing added.
>
> ⚠️ **The MODULE path landed in v0.2.1.** `uses X;` looks beside the importing
> file, then the working directory, then **an installed library** — and nearer
> still wins, so installing a library can never change what an existing program
> means by a name. [MOD-002] carries it, and `./installed.sh` is the harness
> that exists because no other gate asked the question.
>
> ⚠️ **The FOREIGN LIBRARY path did not**, and is why this is still in the root
> rather than in `finished/`. A bare name in an `in` clause still goes straight
> to `dlopen` with the name as written, so the operating system's rules apply:
>
> ```c
> void *handle = dlopen(library, RTLD_LAZY);
> ```
>
> The measurement in the body still reproduces — the same program answers from
> inside the library's directory and fails from `/tmp`. What makes it survivable
> is a **workaround in packaging rather than a fix in the language**: the
> Homebrew formulae wrap the binary and set `DYLD_LIBRARY_PATH` or
> `LD_LIBRARY_PATH` for it. A program installed any other way is on its own,
> and `algol24-library` still writes `in 'libgraphffi.so'` and relies on the
> wrapper.
>
> **So the second half of this proposal is live, and the first half is the
> argument for it**: a module path that resolves the source and then fails at
> the first foreign call is the half-measure this document predicted.

**From:** the language project, which is unusual — the four before this came
from `algol24-library` as a user. This one comes from asking how the library
would be *installed*, and finding that it cannot be.
**Status:** proposal, for decision
**Concerns:** where two kinds of file are looked for — no change to the
language's syntax, types, or what a program means

---

## Summary

`uses graph;` cannot find an installed library, and a program that imports one
by path cannot load its C shims. Both are search problems and neither has a
search path.

Give each one, in the shape `RuntimeFolder` already uses for the runtime.

---

## What is missing, measured

### A module is looked for in exactly two places

`ResolveModule` in `compiler/Parser.a24`, entire:

```algol24
TheFile := ModuleName + '.a24';
Dir := DirectoryOf (FileName);

if Dir <> '' then
begin
    var Beside := Dir + '/' + TheFile;
    if FileExists (Beside) then Exit Beside;
end

if FileExists (TheFile) then Exit TheFile;
```

Beside the importing file, then the working directory. That is [MOD-002] and it
is all of it. **There is nowhere an installed library could be put that `uses`
would find.**

### And a bare shim name only loads from the working directory

The library declares its shims by leaf name — `external 'alg_trunc' in
'libmathffi.so'` — and `foreign_resolve` hands that string to `dlopen`
unchanged, so the operating system's rules apply. Measured, with the shims
present in the library's own directory and nowhere else:

```console
$ cd /tmp && algc shim.a24          # uses '<library>/math'; WriteLn (Trunc (3.9));
Uncaught: Cannot open foreign library 'libmathffi.so'.

$ cd <library> && algc shim.a24
3
```

Same program, same absolute `uses`, different working directory. So **a module
path alone would deliver nothing**: `uses` would resolve the source and the
first foreign call would fail.

### Which is most of the library

| | |
| --- | --- |
| Pure Algol-24 | `strings`, `testing` |
| Needs a C shim | the other **eight** |
| Additionally need SDL2 | `graph`, `sound` |

### And the precedent already exists

`RuntimeFolder` in `compiler/Main.a24` finds `algol.c` and `algol.h` in three
places — beside the binary, `bin/../share/algol24` for a package manager, and
`bootstrap/` relative to the working directory — and the comment says why: the
language has no way to be told its own install prefix. This proposal is that
idea applied twice more.

---

## The proposal

### Where `uses X;` looks

In order, stopping at the first hit:

1. **beside the importing file** — unchanged
2. **the working directory** — unchanged
3. **each directory in `ALGOL24_PATH`**, if it is set
4. **the install's library directory** — `<program>/../share/algol24/lib`,
   found the way `RuntimeFolder` finds the runtime

⚠️ **The first two come first, and that is the whole safety argument.** A
project that vendors its own `strings.a24` must not have it silently replaced by
an installed one, and today's two places keep meaning exactly what they mean.
Nothing that resolves now resolves differently; the new places are reached only
where the program was an error.

The quoted form is untouched: `uses 'modules/Alpha'` is a path and stays one.

### Where a bare library name looks

When the name in an `in` clause contains **no path separator**, try in order:

1. **beside the running program** — so an emitted program can ship its shims
   next to it, which is what `--compile`'s output directory already does for the
   runtime
2. **each directory in `ALGOL24_PATH`**
3. **the install's library directory**
4. **the operating system's own resolution**, unchanged

⚠️ **Step 4 must stay, and must stay last.** `shroom-slots` writes
`external … in '/opt/homebrew/lib/libSDL2.dylib'` today, and a program should be
able to name a system library — `libSDL2.so` — and have the loader find it. Our
directories first means a vendored copy wins over a system one, which matches
the order above; the OS last means naming a system library still works.

A name **with** a separator is passed straight through, as now. That is how a
program says "this exact file and no searching".

### `ALGOL24_PATH`

A list of directories, searched left to right. Separated by `:`, except on
Windows where it is `;`.

⚠️ **The separator differs by platform because it has to.** A Windows path
contains a colon — `C:\lib` — so a colon-separated list is unparseable there.
Every PATH-like variable on Windows uses a semicolon for exactly this reason,
and a single spelling would be wrong on one platform or the other.

### What the diagnostic has to say

Today's failure names the places it looked:

```
Could not find module 'graph': no graph.a24 in '/project' or the working directory.
```

With four places that message has to list four, or a failure becomes
unexplainable — the commonest cause will be an `ALGOL24_PATH` that is set and
wrong. The same applies to `Cannot open foreign library 'X'.`, which currently
names the library and not one place it was sought.

---

## What this does not change

- **No program that works today changes meaning.** Both new searches are
  reached only after the existing places miss, which today means after an
  error.
- **No syntax.** `uses` and `external … in` are spelled as they are.
- **Not a package manager.** No versions, no dependency resolution, no
  fetching, no manifest. A directory of `.a24` files and shared objects is the
  whole model.
- **Nothing about what a unit may contain**, or about `private`, or about the
  non-transitivity of `uses` [MOD-015].

---

## Risks

**Shadowing becomes possible in a way it is not today.** A stale local copy of
a unit will quietly win over a correct installed one, because local comes
first. That is the right default — the alternative is an installed library
overriding the file sitting next to your program — but it is a new way for "it
works on my machine" to be true. The diagnostic cannot help here, because
nothing failed.

**An installed library is a thing that can go stale.** Today the library is
always the copy you are looking at. Afterwards it may be one somebody installed
months ago, and `algc` has no way to report which file it loaded. A flag that
prints where each `uses` resolved would answer that, and is not proposed here
because it is separable.

**The shim search runs per foreign library.** Four `stat` calls before the
loader is asked, cached per (symbol, library) pair as `foreign_symbol` already
caches. Not measurable against a foreign call.

**`ALGOL24_PATH` is a new way to break a build invisibly**, in the way
`PYTHONPATH` and `CLASSPATH` are. Searched after the local places rather than
before, which is the mitigation, and the diagnostic naming it is the rest.

---

## Open questions

1. **Is `ALGOL24_PATH` wanted at all?** The install directory alone covers the
   packaged case, and the local places cover development. The variable is for
   the person with a library checkout who does not want to install it — which
   today is answered by `cd`. Dropping it removes a failure mode and a platform
   difference.
2. **Should the install directory be `share/algol24/lib` or `lib/algol24`?**
   The first sits beside the runtime that `RuntimeFolder` already finds, which
   argues for it. The second is where a Unix packager would expect a loadable
   object, which argues against putting `.so` files under `share`.
3. **Should `--compile` copy a used unit's shims into the output directory**,
   as it already copies `algol.c` and `algol.h`? It would make an emitted
   program self-contained in the same sense, and it is the only way step 1 of
   the shim search is useful without the user doing it by hand.
4. **Does the module search belong in the Parser or in a driver?**
   `ResolveModule` is in the Parser, which has no business knowing an install
   prefix; `RuntimeFolder` is in `Main`. The path probably arrives as a field
   the way `FileName` does.
5. **Is a `--where` flag worth it** — printing what each `uses` resolved to?
   It is the answer to the staleness risk and it is also scope.

---

## What this is for

So that `brew install algol24-library` can mean something: the units and their
shims land in one directory, and `uses graph;` finds them from any project.
Without it, every program that uses the library needs the library *in its own
directory* — which is why `shroom-slots` carries its own copies and its own
hardcoded `/opt/homebrew/lib/libSDL2.dylib`.

⚠️ **It is a prerequisite rather than a feature.** Nothing becomes expressible
that was not expressible before; what changes is that a library can be
installed rather than copied. Whether the library then ships bundled with the
compiler or as a second package is a distribution decision this does not make —
and it is a decision that cannot be made at all until a search path exists.
