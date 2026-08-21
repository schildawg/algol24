# Contributing

How work moves through this repository. `CLAUDE.md` says what a change must
satisfy — the six conditions of the Prime Directive — and this file says how a
change gets from an issue to `main` without two of them colliding.

## The strategy in one line

**Main-based, with one short-lived branch per issue, rebased and squash-merged.**
No `develop`, no `release/*`, no `hotfix/*`, and no long-lived branch per role.

## Why not Git Flow

Git Flow's apparatus exists to maintain several released versions in production
at once. This project has no releases yet, and the criterion for the first one is
a single event: the specification says what it should say and the code does what
it says. `release/*` and `hotfix/*` would have nothing to hold, and a permanent
`develop` would double the surface on which the problem below occurs.

## ⚠️ The constraint that decides everything: the reseed

Every change to `compiler/` ends in `./build.sh --reseed`, which commits
`compiler/` together with the regenerated `bootstrap/`. That generated C covers
every emitted symbol, so a small change to the compiler is a large change to the
seed. Measured on this repository's own history:

| Commit | `compiler/` | `bootstrap/` |
|---|---|---|
| `f709980` | 15 lines | 175 lines |
| `38498dc` | 57 lines | 226 lines |
| `02204d4` | 205 lines | 785 lines |

Five to ten times amplification. Two branches open on `compiler/` at the same
time produce a conflict in `bootstrap/` that cannot be resolved by hand — and the
danger is not that the resolution is hard. It is that a **wrong** resolution
still compiles, and the first thing to notice would be `test.sh fixedpoint`, if
anyone ran it.

Everything below follows from minimising the time two branches are open on
`compiler/` at once.

## Two lanes

**The serialized lane — anything touching `compiler/`.** One issue at a time.
Work that churns the whole seed lands alone, with nothing else open against the
compiler: that means `Mangle`, identifier case folding, and the symbol scheme.
Landing those early is cheaper than landing them late, because every other seed
diff built in the meantime has to be regenerated on top of them.

**The free lane — everything else.** `ALGOL-24.md`, `tests/defects/`, the shell
scripts at the root, the issue tracker. None of it reseeds, so it parallelises
with the serialized lane and with itself at no risk.

## The lifecycle of a change

```sh
git switch main && git pull
git switch -c fix/<issue>-<slug>      # 27-arity-segfault, say
#   ... edit compiler/ only.  Do NOT reseed while iterating.
./test.sh                             # condition 2
./build.sh                            # conditions 4 and 5
./test.sh                             # condition 5
./tests/defects/run.sh                # condition 1

git fetch && git rebase origin/main   # rebase LAST, while the seed is absent
./build.sh --reseed                   # the final commit on the branch
git push -u origin HEAD               # open the PR; the Tester reviews
```

**⚠️ Reseed last, never during.** Iterating with the seed committed means every
rebase drags a regenerated `bootstrap/` through a conflict. Iterating without it
means the rebase touches `compiler/` only, which merges like ordinary source. The
reseed then goes in as the final commit, and the window in which anyone can build
on a stale seed is minutes rather than days.

**⚠️ Rebase; never merge `main` into a branch.** A merge commit inside
`bootstrap/` is not resolvable.

**⚠️ If a rebase does conflict in `bootstrap/`, do not resolve it.** Neither
`--ours` nor `--theirs` is correct — both produce a seed matching no compiler.
Regenerate instead:

```sh
git checkout main -- bootstrap/
./build.sh --reseed
```

The seed is a build artifact. Treat a conflict in it as a signal to rebuild, not
as a merge to perform.

## Merging

**Squash.** Every commit on `main` is then a complete state that satisfies all
six conditions. That matters more here than in most repositories: a fixed-point
failure is exactly the kind of defect you bisect for, and a bisect that lands on
a half-reseeded commit tells you nothing.

**Require a review.** Prime Directive condition 3 is that the Tester approves the
work. Branch protection on `main` requiring one approving review is that
condition mechanised, rather than left to memory.

## Naming

`fix/<issue>-<slug>` for a defect, `spec/<slug>` for specification work,
`docs/<slug>` for prose. Delete the branch once it merges.

## ⚠️ No long-lived branch per role

A role is identified by the working tree it runs in, never by a branch. A
permanent `dev` or `test` or `spec` branch is Git Flow's `develop` under another
name: it drifts from `main`, accumulates exactly the seed conflicts described
above, and buys nothing that a per-issue branch does not.

## Review noise

`bootstrap/*.c` is generated. Marking it in `.gitattributes` keeps a review of a
15-line compiler change from opening as an 800-line diff:

```
bootstrap/*.c  linguist-generated=true  -diff
bootstrap/*.h  linguist-generated=true  -diff
```

⚠️ `bootstrap/algol.c` and `bootstrap/algol.h` are **not** generated — they are
the hand-written runtime, and a rule matching them would hide real changes. List
them back:

```
bootstrap/algol.c  linguist-generated=false  diff
bootstrap/algol.h  linguist-generated=false  diff
```
