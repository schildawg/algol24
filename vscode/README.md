# Algol-24 for VS Code

Syntax colouring and a Test Explorer for `.a24` files: a TextMate grammar, a
language configuration, and a `TestController` that runs `test` blocks through
either processor. No language server and no diagnostics — the compiler already
reports those, and this does not duplicate them.

## Installing

The extension has no dependencies and nothing to compile, so a link into the
extensions directory is the whole of it:

```sh
ln -s "$PWD/vscode" ~/.vscode/extensions/algol24-0.1.0
```

Then restart VS Code. Open any `.a24` file and the status bar should read
**Algol-24**; if it reads Plain Text, the link is in the wrong place or the
window has not been reloaded.

To build a `.vsix` instead, `npx @vscode/vsce package` from this directory.

## What it colours

Derived from `compiler/Scanner.a24` and `compiler/TokenType.a24` rather than
from a Pascal grammar, because the two differ in ways that show:

- **Keywords are case-insensitive.** `begin`, `Begin` and `BEGIN` are one word,
  and every keyword pattern is written `(?i:…)` to match. The 38 keywords are
  exactly the ones in `Scanner.a24`'s `Keywords` table — checked both ways, so
  none is missing and none is invented.
- **`unit`, `test` and `on` are not keywords.** They are context-sensitive
  identifiers — a variable may be called `test` — so each is coloured only in
  the position that makes it structural: `unit` opening a file, `test` before a
  block's quoted name, `on` before a handler's `e : Type`. A variable named
  `test` stays a variable.
- **A one-character literal is a `Char`**, never a `String`, and is scoped as
  one. `''''` is the quote itself and counts as a Char; `''` is the empty
  String.
- **`#27` is a Char by code point**, which is how `Console.a24` writes `ESC`.
- **A `Double` needs a digit on both sides of the point.** `1.` is an Integer
  followed by a dot, and colours that way.
- **`?` and `!` are identifier characters.** `Gate?` is one word to
  double-click, one word to the grammar, and one word to the scanner.
- **`///` is distinguished from `//`.** The scanner does not tell them apart —
  both run to end of line — but the project's doc comments are `///` by
  convention, and `⚠️`, which marks a hard-won constraint, is picked out inside
  them.

## The Test Explorer

`extension.js` contributes a `TestController`, so `test` blocks appear in the
Testing view with a run button in the gutter beside each one. Two profiles:

- **Interpreted** (the default) — `bootstrap/algc --test <file>`, run from the
  repository root.
- **Compiled** — the same four steps `algc --help` describes, into a temporary
  directory: emit C, copy `algol.c` and `algol.h` in beside it, `cc`, run the
  binary from the file's own directory.

⚠️ The two working directories are not interchangeable: a suite that touches
files can tell the difference, so each half uses the one that matches how it
would be run by hand.

⚠️ The emitted directory is **not** self-contained, despite what `--help` says.
The emitter writes `#include "algol.h"` and never the runtime, so the copy step
is required rather than a convenience.

⚠️ **Discovery is per test; running is per file.** The language has no per-test
filter, so asking for one test runs every test its file can reach, and the
results for all of them are reported. That is not a shortcut — those tests
really did run — but it does mean a run of `compiler/Parser.a24` reports into
other files' items as well, because a module's tests come with its imports'.

⚠️ **A file in an import cycle with the root reports its own tests twice**, and
that is a defect rather than a quirk of this view. `Parser.a24` uses
`Interpreter`, which uses `Parser`, and the root file is never entered in the
parser's `Loaded` map — so the second `uses` loads it again and hoists its tests
a second time. Running `compiler/Parser.a24` gives 273 results for 190 distinct
tests: its own 83 counted twice. The whole suite is unaffected at 221, because
nothing imports `Main.a24`.

Failures carry the interpreter's own message: a failed assertion in the tree
reads `Subscript target should be an ordinal.` A **compiled** failure carries
no message, because `alg_test_run` in `algol.c` prints no `[ERROR]` line — the
FAIL stands alone, and that is a property of the runtime rather than a gap here.

A file the C back end refuses reports every one of its tests as *errored*,
carrying the refusal: `Two modules named 'Resolver' is not supported by the C
back end yet.` That is the honest answer — the tests did not run — and it is how
the remaining gaps stay visible.

⚠️ **The Test Explorer is a way to read a failure, not a gate.** It reports per
test and knows nothing about totals, so whatever this repository decides to gate
on lives outside it.

## What it does not do

- **No `begin`/`end` bracket matching.** VS Code's bracket pairs are character
  pairs, and these are words. Folding and indentation are configured for them,
  so they behave; they just do not highlight as a pair.
- **User-defined types colour only where they are declared or annotated.** The
  annotation rule reads `Name : Type`, and deliberately declines three shapes
  that look like it and are not: a map literal (`'and':TOKEN_AND`), a case arm
  (`#10 : begin`), and a call in a case arm (`#39 : ScanString()`). All three
  occur in `Scanner.a24`, which is what they were tested against.
- **No semantic colouring.** Nothing here knows that a name is a class, that a
  method is private, or that a `uses` resolves. `Length` is coloured as a
  built-in wherever it appears, including where a program has shadowed it.

## Keeping it honest

The keyword list, the built-in list and the literal forms are copies of what
the scanner does, and copies go stale. If a token is added to
`compiler/TokenType.a24` and registered in `Scanner.a24`'s `Keywords`, it
belongs in `syntaxes/algol24.tmLanguage.json` too — nothing checks this, and no
test covers this directory.
