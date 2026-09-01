# Packaging

`algol24.rb` is the Homebrew formula, kept here so it is versioned with the
thing it packages. The **tap** that serves it is a separate repository —
`github.com/schildawg/homebrew-algol24` — because that is the layout Homebrew
requires: a repo named `homebrew-<tap>`, with formulae in `Formula/`.

```sh
brew tap schildawg/algol24
brew install algol24
```

## Why a tap rather than homebrew-core

`homebrew-core` gates on **notability**, judged by the maintainers with a rough
heuristic around 75 stars, 30 forks and 30 watchers. A tap has no gate: you own
it, you release when you like, and the install experience is the same but for
one `brew tap`.

## Bottles — the executable, not the source

A **bottle** is a pre-built binary package: a tarball of the installed files,
built once by CI and downloaded by everyone else. With one, `brew install`
unpacks a binary in seconds; without one, every user compiles from source.

Bottles are per macOS version and per architecture, so `arm64_sequoia` and
`arm64_sonoma` are two builds. The formula gains a `bottle do` block of SHAs
that CI writes for you.

⚠️ **Algol-24 bottles unusually well.** A `--ffi` build links against
`/usr/lib/libffi.dylib` — the *system* libffi — and nothing else:

```
/usr/lib/libffi.dylib
/usr/lib/libSystem.B.dylib
```

So the bottle has no dependencies beyond the operating system, and the formula
needs no `depends_on` on macOS. A Linux formula would need `depends_on "libffi"`.

⚠️ **And it barely needs one.** A source build takes about 2.4 seconds, so a
bottle saves a user almost nothing. It is worth having because you asked for the
executable rather than the source, not because compiling is slow.

## Releasing

1. Tag and push: `git tag -a vX.Y.Z && git push origin vX.Y.Z`
2. Take the tarball's checksum:
   `curl -sL https://github.com/schildawg/algol24/archive/refs/tags/vX.Y.Z.tar.gz | shasum -a 256`
3. Copy `algol24.rb` into the tap's `Formula/`, with the new `url` and `sha256`.
4. Update `VERSION` in `compiler/Main.a24` **before** tagging — it is what
   `algc --version` reports, and nothing checks that it matches the tag.
5. Open a pull request against the tap. `tests.yml` builds and tests it;
   `publish.yml` uploads the bottle and commits the `bottle do` block.

⚠️ **`VERSION` and the tag can drift, and nothing catches it.** The one thing in
this repository that is checked by nobody. Worth a line in `spec/spec.sh` when
releases become routine.

## The two workflows

Both go in the **tap** repository, not here. They are the standard Homebrew
ones; `brew test-bot` does the work.

`.github/workflows/tests.yml` — build and test every formula a pull request
touches, on each platform you intend to bottle for.

`.github/workflows/publish.yml` — on merge, upload the bottles to a GitHub
release of the tap and write the `bottle do` block back into the formula.

Copies of both are in this directory as `tests.yml` and `publish.yml`.
