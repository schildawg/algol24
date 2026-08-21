# Working across the role worktrees

**This file is Schildawg's, and only Schildawg's.** It is notes for the person
holding all four checkouts at once, not a process the team follows and not a
rule anyone is held to. Nothing in it is normative — `ALGOL-24.md` is the
specification, `CLAUDE.md` is the instruction every role reads, and neither
depends on a word written here. If it stops being useful, delete it; nothing
breaks.

Owned by Tiller. Written against `eb6405c`, the commit at which the roles were
given separate trees.

## The layout

| Directory | Role | Branch it started on |
|---|---|---|
| `algol24/` | Schildawg, and Tiller alongside | `main` |
| `algol24-dev/` | the Developer | `dev` |
| `algol24-test/` | the Tester | `test` |
| `algol24-spec/` | Plumb | `spec` |

The role branches are starting points, not homes. A worktree switches branches
freely — the Developer will spend most of their time on `fix/...` branches, and
the Tester on whatever is under review.

The Client named in [`README.md`](README.md) is deliberately absent. That role
builds *on* Algol-24 from outside it, so it belongs in its own repository rather
than in a checkout of this one.

## The mental model

There is **one repository with four checkouts of it**, which is not the same
thing as four copies. Each worktree's `.git` is not a directory but a single
line pointing back here:

```
gitdir: /Users/jschilling/workspace-copilot/algol24/.git/worktrees/algol24-dev
```

So the four trees share one object store, one set of branches and tags, one
config, one remote, and one stash. What they do *not* share is the files on
disk, the staging area, and which commit each has checked out.

Almost every surprise below follows from that sentence. When something behaves
oddly, ask which of the two lists the thing in question is on.

## What is safe

Worth knowing, because the failure modes are easier to think about once the
non-failures are off the table.

- **Parallel work cannot corrupt the repository.** Commits made in a worktree
  are ordinary commits. This is what the feature is for.
- **Git blocks the two likeliest mistakes itself.** Checking out a branch a
  second tree already holds fails, and so does deleting a branch that is checked
  out somewhere. Those errors are the protection working.
- **Build artifacts never collide.** `.build/`, `algc` and `out/` are ignored
  and rooted per tree, so three roles can build at once without seeing each
  other's output.
- **Nothing done in a worktree reaches `main` here** until something is merged
  in this tree.

## What will actually bite

**Never `rm -rf` a worktree directory.** It removes the files and leaves the
administrative record in `.git/worktrees/`, so git goes on believing the branch
is checked out — and the error it gives later will not mention the directory
that was deleted. The right command is `git worktree remove ../algol24-dev`. For
a deletion already done by hand, `git worktree prune` clears the wreckage.

**Do not move or rename `algol24/`.** Each worktree records that absolute path,
so tidying the workspace folder breaks all three at once. `git worktree repair`
recovers it, but not moving it is easier.

**The stash is shared.** There is one stack for the whole repository, so a
`git stash` in one tree is visible in the others and a `git stash pop` in the
wrong one applies somebody else's changes to your files. With several trees
live, commit to a scratch branch instead of stashing.

**Do not force-push a branch that is under review.** If the Tester is sitting on
`origin/fix-x` in a detached HEAD and the Developer rebases and force-pushes,
that commit becomes an orphan and the review silently refers to code that no
longer exists. Push new commits during review; rebase after approval.

## The two that belong to this project

⚠️ **Never resolve a `bootstrap/` conflict by hand.** Reseeding rewrites all of
`bootstrap/` — generated C covering every emitted symbol — so two roles who
reseed on different branches conflict across thousands of lines of
machine-written code. Resolving those by hand produces a seed corresponding to
no compiler that ever existed, which is worse than a merge that fails, because
it builds.

The way through is to take either side to let the merge complete, then re-run
`./build.sh` and `./build.sh --reseed` against the merged `compiler/` source and
commit that. **The seed is output. Regenerate it; do not negotiate it.** This is
also the reason seed-churning work — anything touching `Mangle`, identifier case
folding, or the symbol scheme — wants to land early and alone.

⚠️ **Verification does not transfer between trees.** Conditions 4 through 6 of
[the Prime Directive](CLAUDE.md#the-prime-directive) are claims about one
specific tree's build. A Tester approving work has to run the ladder in
`algol24-test/` rather than read that it passed in `algol24-dev/`. That is most
of the reason the Tester has a tree at all.

## Permissions

`.claude/settings.json` is checked in and carries the allowlist every tree
needs — the build, the suites, the defect reproductions, and both generating
harnesses. `.claude/settings.local.json` is ignored, because it accumulates
whatever one machine happened to approve, absolute paths and dead session
identifiers included, and must not follow the shared file into the repository.

⚠️ `./build.sh --reseed` is **deliberately not** in the allowlist. Everything a
role runs to *check* their work is free of prompts; the one command that rewrites
the seed still asks first. Add it if the friction outweighs the caution, but add
it knowingly.

## Commands worth remembering

```sh
git worktree list                    # what exists, and what each tree has checked out
git worktree remove ../algol24-dev   # the correct way to delete one
git worktree prune                   # clean up after an rm -rf you regret
git worktree repair                  # after moving directories
```

When something is confusing, `git worktree list` is almost always the first
thing to look at. A stale or unexpected entry there explains most of the errors
that do not obviously mention worktrees at all.
