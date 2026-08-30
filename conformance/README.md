# The corpora

Three directories, one question, and a distinction that decides everything
else. `conformance/`, `refusals/` and `defects/` are run by `../conform.sh`.

```sh
./conform.sh                # everything -- both processors must pass
./conform.sh --interpreted  # skip the compiled half
./conform.sh --lenient      # report compiler gaps without failing
./conform.sh --record       # write expectations from what happens
```

## Which directory a case belongs in

⚠️ **One question decides it: is the interpreter right?** What the compiler does
never enters into the classification.

| The interpreter | The case goes in | It records |
| --- | --- | --- |
| refuses the program | `refusals/` | `NAME.expected` |
| runs it and is right | `conformance/` | `NAME.out` |
| runs it and is **wrong** | `defects/` | `NAME.current` |

This follows the generation plan rather than tidiness. The goal of the next
generation is an interpreter that matches the specification; the goal of the one
after is a compiler that matches the interpreter. Classifying by the compiler's
state would mix two generations of work into one suite.

**A divergence is an outcome, not a category.** Every case in `conformance/`
runs under both processors. One the interpreter gets right and the compiler does
not fails its compiled half, and *that failure is the record of the divergence* —
which is why there is no `divergences/` directory and why Annex C entries are
reproduced by ordinary conformance cases.

⚠️ There was once a `// compiled: no` marker for silencing a known divergence.
It recorded nothing and noticed nothing: three Annex C entries had no
reproduction anywhere while it stood, and C-14 — *compiled code does not check
arity at all* — was found within minutes of removing it, in a case that had been
silenced since the day it was written. The marker is gone and will not come
back.

## Two verdicts, because they answer different questions

- **the language** — the interpreted half, which must be green.
- **the compiler** — the compiled half, which must be green too. A case the
  interpreter gets right and the compiled program gets wrong is a **gap**, and a
  gap is a **failure**.

⚠️ **Both are the gate, as of Generation 3.** Through Generations 1 and 2 a gap
was reported without failing the run, because the compiler was deliberately
allowed to trail while the interpreter was brought to the specification. That
relaxation ended the moment the count reached zero. `--lenient` still shows work
in progress; it is not a way to finish anything.

A third question is asked elsewhere and is the one that must not break: does the
compiler still build and reproduce itself? That is `../fixedpoint.sh` and
`../test.sh`. A compiler that cannot compile cannot produce the generation that
closes these gaps.

## Why a defect passes while the code is wrong

A case in `defects/` is a **reverse conformance test**. It records the wrong
behaviour and passes while that behaviour persists; it turns **red when the
defect stops reproducing**, because a fix is as much a change to be noticed as a
regression.

The alternative — a suite with permanently failing entries — is a suite nobody
reads. This repository has already been there once: the old notes said the tree
was "red on purpose" and gated on the count rather than the colour.

⚠️ A defect is a statement about the **interpreter** and is never compiled.
Whether the compiler happens to share the fault says nothing about whether the
interpreter still has it.

## How a case leaves

Two reasons, and they must not look alike in a diff.

**Withdrawn** — the case pinned the wrong behaviour. `refusals/0028` pinned two
enumerations being unable to share a member name; the decision went the other
way, so the case was deleted and a defect took its place. A correction: the case
was wrong from the moment it was written.

**Retired** — the rule stopped describing the *language*. The collections are
moving out of the core into a unit written in Algol-24 (Annex H, H-9), and when
they do, most of chapter 14's rules leave the specification and their cases
become **unit tests of that unit**. Nothing was wrong; the subject changed from
a language feature to a library.

## ⚠️ Writing a case that proves something

This is the failure that recurred most often while the corpus was built, and it
recurred in four different disguises. **The tell is always the same: the
recording is what a *correct* implementation would produce.**

| | What happened |
| --- | --- |
| A probe of CRLF handling | git normalized the line endings, so it passed with no `#13` left in it to be whitespace |
| Three chapter 7 probes | header comment, no program — recorded `exit: 0` and reported green, while nine rules cited them as evidence |
| The first DEF-16 | recorded `5` for a cast covering a conjunction — which is what the *fixed* behaviour prints too |
| The first DEF-28 | recorded `exit: 0` for a driver bug no program can exhibit — exactly what a correct implementation gives |

**Before recording a case, ask what it would print if the implementation were
already right.** If that is what you are about to record, the case proves
nothing. DEF-28 could not be written at all, and Annex F says so and gives a
shell command instead; that is a better answer than a green file.

⚠️ **A probe proves that a program did something, not *why*.** [MOD-012] said
"circular imports do not work" for months on the strength of a probe whose
fixtures returned `'A'` from a function declared `: String`. A one-character
literal is a Char, so those fixtures failed whether or not a cycle existed. The
recording was accurate; the inference drawn from it was not. Cycles between
modules work fine.

## ⚠️ Defect or a later generation?

Not every gap between the language and the implementation is a defect. Ask
whether the language **lacks** the facility or **has it inconsistently**.

- **Annex H, a later generation** — nothing in the language knows about the
  thing. Alternate bases (H-1) are absent everywhere; there is no rule for them
  to disagree with. The corpus pins the *current* rule, and that case turns red
  when the generation lands, which is correct.
- **Annex F, a defect** — the rule exists and is applied elsewhere, and one path
  does not follow it. `1 + 1.5` is `2.5` and `'a' + 'bc'` is `abc`, so widening
  is settled behaviour; only the paths carrying a *written* type refused it,
  which made a declared type mean something narrower than the operators do.

⚠️ A useful second check: does the change only make more programs legal, or does
it change what an existing program *means*? The second kind needs more care
whichever annex it lands in.

## Fixtures

A case may import a module. Fixtures live in `modules/` beside the case and are
imported as `uses 'modules/Alpha';` — resolved beside the importing file. They
are **not** cases: `conform.sh` only looks one level deep, which is why they are
in a subdirectory.

## ⚠️ Line endings are held byte-exact

`../.gitattributes` marks these directories `-text`. `conformance/0006` has real
CRLF endings because it exists to show that CRLF and LF report identical line
numbers; normalized to LF it would still pass, for entirely the wrong reason.
Every `.out`, `.expected` and `.current` is a byte-for-byte record of what an
implementation printed, and a rewritten byte is a false record.


## Divergences — Annex C, and why they need no corpus

A **defect** was a fault in the interpreter, and it needed a case of its own:
nothing else recorded the wrong behaviour, so `defects/X.current` held it, the
case passed while the fault persisted, and it turned red when the fault stopped.
`defects/` is empty as of Gen 1.

A **divergence** is a fault in the *compiler*, and it needs no case at all. The
reproduction already exists: a conformance case whose interpreted run is the
correct answer and whose compiled run is not. `conform.sh` computes that
difference on every run and calls it a **gap**.

| | Defect | Divergence |
| --- | --- | --- |
| Wrong implementation | the interpreter | the compiler |
| Truth is | the specification | the case's own `.out` |
| Faulty behaviour recorded in | `.current` | nothing — recomputed each run |
| Passes while | the fault persists | the fault persists |
| Turns red when | it is fixed | it is fixed |

⚠️ **So do not write a `divergences/` directory.** A second copy of a case that
already exists would have to be kept in step with the first, and the first is
the one the language is defined by.

**An Annex C entry cites the gap that demonstrates it**, in the same block shape
a rule uses:

```
**C-16 — Inheriting from a non-class emits invalid C.**

    gap  0046-inherit-from-a-non-class.a24
```

Two harnesses check it, and the split matters:

- `spec/spec.sh` — the cited case **exists**, and counts how many live entries
  carry a citation. Static, so it is cheap and runs anywhere.
- `conform.sh` — the cited case **still diverges**. Only this script can know
  that, having just compiled every case. A citation naming a case that no longer
  differs is a **failure**: the divergence has been fixed and the entry now reads
  as open, which is how C-1, C-3, C-4 and C-22 came to be wrong.

⚠️ A gap that **no** entry cites fails on its own account, ahead of the gap
count, so the message names the real problem: a divergence nothing has written
up is worse than one that has been, whatever the totals say. Under `--lenient`
it is the backlog it used to be.

## Colour is transliterated, not stripped

`\033[31m` becomes `[RED]`. Stripping is not injective — a wrong colour and a
right one would compare equal — and the test report's colours are part of the
specified surface [TST-010].
