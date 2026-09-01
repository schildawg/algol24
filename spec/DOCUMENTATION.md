# Documentation comments

How `///` is written in Algol-24. The conventions are **Rust's**, adapted where
this language differs from that one, and they are conventions rather than rules:
[LEX-002] says `///` is not a distinct form — the scanner sees `//` followed by a
comment whose first character is `/` and treats it as any other comment. The
language does not know what a doc comment is. Tools and readers do.

## The one distinction everything follows from

A doc comment carries **contract**. Version control carries **provenance**.

Contract is what a caller must know and cannot read off the signature: what the
subprogram does, what it raises, what it mutates, what the caller must guarantee
first. Provenance is who wrote it, when, and in which revision — questions `git`
answers exactly, continuously, and without anyone maintaining a comment.

Every documentation system designed since version control became universal draws
this line, and the ones that predate it — Javadoc's `@author` and `@version` —
are the reason it needed drawing. An `@author` on a file five people have since
edited is not out of date; it is false.

## The summary line

The first line is a **complete sentence that stands alone**, because it is the
only line an index, a hover or a listing shows.

- Write it in the third person, starting with the verb or with the name:
  *"Folds a name to lower case."*, *"Gets a variable from the local scope."*
- End it with a full stop.
- **One sentence**, which may wrap — but no further than a second line. A
  summary needing three is doing too much.
- Then a blank `///`, then the body.

The unit of the rule is the **sentence**, not the line. Rust and Go both wrap a
summary when it needs it, and a hard one-line cap would only buy truncation:
Algol-24 sources wrap at 80 columns, and `/// ` spends four of them.

**It must say something the signature does not.** This tree carries the
counter-examples: `/// Environment!` above `class Environment;` and
`/// Prints an Abstract Syntax Tree!!!` above the printer. Both are the name
again, with punctuation for enthusiasm. A summary that restates the declaration
is worse than none, because it satisfies a reader's glance without informing it.

**One line is a complete doc comment** and 56 of this compiler's 576 blocks
are exactly that — almost all of them on fields, where they read well:
`/// The C file's stem -- the source file's, without '.a24'.` Brevity is not the
failure mode. Emptiness is.

## Sections

Rust's `#` headings, with the set adapted to what this language actually has.
A section is a `#` heading on its own `///` line, a blank `///`, then prose.

| Section | When |
| --- | --- |
| `# Raises` | The subprogram may `raise`. Name the condition and quote the message. |
| `# Safety` | The subprogram crosses the foreign function interface, or its correctness rests on something the language cannot check. |
| `# Examples` | Worth showing rather than describing. See below — an example cites a test. |
| `# Satisfies` | The rules of `spec/ALGOL-24.md` this declaration implements. |
| `# Since` | **Library only.** The release the name first appeared in. |

**`# Raises` replaces both of Rust's error sections.** Rust separates
`# Panics` from `# Errors` because it has two mechanisms — unwinding, and a
`Result` the caller must handle. Algol-24 has one: `raise`, caught by
`try` / `except`. Two headings where the language has one mechanism would be a
distinction the reader has to learn and the writer has to guess at.

**`# Raises` rather than `# Errors`, which is what this tree writes today.**
Seventeen blocks use `# Errors`; the keyword is `raise`, and naming the section
after the mechanism is the spelling that needs no explanation. They convert as
they are rewritten, which costs nothing, because the doc comments are being
written fresh.

**`# Safety` earns its place through the FFI and nowhere else.** Rust's
version guards `unsafe`. Algol-24's equivalent boundary is a foreign call: past
it the runtime cannot check a pointer, a lifetime or an arity, and a wrong
declaration is a crash rather than a diagnostic. A subprogram written wholly in
Algol-24 has nothing to put under this heading and should not have the heading.

### Order

Summary, body, `# Raises`, `# Safety`, `# Examples`, `# Satisfies`, `# Since`.

**Contract before illustration**, which is the one place these conventions
depart from Rust's usual ordering. An example is the longest part of a doc
comment and the least urgent; a reader checking whether a call can raise should
not scroll past a worked example to find out.

## Examples cite a test

An `# Examples` section names a test block rather than carrying a code fragment:

```
/// # Examples
///
/// See test 'Scan Comment Ends At Newline'.
```

**This is the whole of what Rust's doctests buy, without a second mechanism.**
Rust's examples are valuable because `cargo test` compiles and runs them, so an
example that stops being true turns red. Algol-24 already has `test 'Name';
begin … end` and a harness that runs it, and `spec/spec.sh` already checks that
99 unit citations name tests the suite actually runs. Copying a fragment into a
comment instead would create a second copy of the code with nothing to keep it
honest — the exact rot the corpus exists to prevent.

**The name is the contract, so it must resolve.** A cited test that has been
renamed is a dangling reference, and the check below is what catches it.

## Satisfying a rule

`spec/ALGOL-24.md` is the authority and the implementation is measured against
it. `# Satisfies` is the pointer back:

```
/// Folds a name to the form it is looked up under.
///
/// # Satisfies
///
/// [SRC-011]
```

Bracketed identifiers, comma-separated and **sorted**, wrapped at the margin.
Sorted so a reader can find one and a diff stays stable.

**On the lowest declaration it applies to, and nowhere above it.** A rule
implemented by one method is named on that method, not on its class and not on
its unit. A rolled-up list would be a second copy of a fact already written
down, maintained by hand, with nothing checking the two agree — and the whole
reason this tag exists is to make the mapping checkable rather than remembered.

Where the lowest declaration has no doc comment of its own — an enum *member*,
which lives inside a parenthesised list — the rule goes on the nearest
declaration that does. [LEX-013] cites `TOKEN_ASSIGN`, so it is named on the
`TokenType` enumeration.

**The specification's own citations are the authority on placement.** A rule
carrying `interpreter  compiler/Scanner.a24  ScanToken` says where its
implementation lives, so `ScanToken` names that rule. The two directions can
then be checked against each other, which is most of the value: today the
mapping exists only in the specification and nothing verifies the code agrees.

**A rule merely mentioned in prose is not satisfied by it.** `Token.a24`
explains subranges and cites [TYP-015] in a sentence, but the rule's
implementation is `Interpreter.InSubrange` and that is where the tag belongs. An
inline `[ID]` in prose is a reference; `# Satisfies` is a claim.

## No glyphs

A doc comment carries no `⚠️`, and no marker of any kind whose job is to say
"this part matters".

The habit it replaces is well established here — 119 of `CEmitter.a24`'s 167
blocks carried one — and the reason to drop it is what a warning sign actually
communicates. `⚠️` reads as *a hazard that needs acting on*, an item still
outstanding. What these paragraphs almost always hold is the opposite: settled
knowledge, a decision already made and already right. A unit with nine warning
signs on it looks like a unit with nine unresolved problems.

**Prose that needs a glyph to be noticed is prose that has buried its point.**
State the constraint in the paragraph's first sentence and it needs no
announcement:

```
/// Pads rather than appending.  The scanner calls this once per line in
/// increasing order, so an append would do -- but a gap would then shift
/// every later line by one and misreport them all.
```

**Anything genuinely actionable already has a section.** A hazard the caller
must handle is `# Raises`; one the language cannot check for them is `# Safety`.
If a note belongs behind a warning sign, it belongs under a heading instead —
where a reader looking for it can find it, rather than only a reader already
scrolling past.

This applies to `///` only. The `⚠️` paragraphs in `spec/ALGOL-24.md` and in
ordinary `//` comments are a separate question and are left alone.

## What never appears

- **An author.** `git log` and `git blame` answer it, exactly and forever.
- **A date.** Wrong from the next commit onward, and read by nobody.
- **A version**, except `# Since` in the library. A compiler unit is one program,
  not a published interface; there is no release for a private name to be
  "since".
- **A change log.** *"Changed to handle the empty case"* documents an edit, not
  the thing. The revision that made the change is where that belongs.
- **A ticket or issue identifier**, which points outside the tree and rots when
  the tracker moves.
- **A restatement of the signature.** Parameter names and types are in the
  declaration and are checked; prose repeating them is a second copy that drifts,
  and it drifts silently.

**This is why there is no `@param` or `@return` vocabulary.** Zero of this
tree's 576 doc blocks use one, and that is the right number. Go and Zig
demonstrate that a prose sentence naming the parameters that matter reads better
than a table restating all of them, and Algol-24's signatures carry types, so
the table would be the less reliable of the two.

## Length

There is no maximum, and a cap would be the wrong instrument: it would push out
the paragraphs explaining why a thing is the way it is, which are the most
valuable content these comments carry.

The discipline is the summary line, which is capped at one sentence and one
line. Below that, a declaration deserves what it deserves. For calibration, this
compiler's own blocks run to a median of 5 lines, 12 at the 90th percentile, and
26 at the longest.

**A very long doc comment is evidence about the design, not the prose.** If a
subprogram needs forty lines to describe, the subprogram is doing too much; edit
the code rather than the comment.

## Where documentation goes

**Above the declaration**, with no blank line between.

**A unit is documented by a `///` block above its `unit` declaration.** The
optional `unit Name;` header [LEX-011] opens a file, and a doc comment binds to
it exactly as it binds to any other declaration:

```
/// The token vocabulary, and nothing else.
unit TokenType;
```

**The header must come before the `uses` clauses**, because it opens the file —
`unit` is recognized by position, so a header after an import is two identifiers
in a row and the file will not parse. Only comments may precede it.

**A file with no `unit` declaration has no unit documentation.** There is
nothing for the block to bind to, and a `///` at the top of such a file would
document whatever declaration happened to come first.

Rust and Zig both need a separate marker for file-level documentation — `//!` —
because `///` binds forward and a file has no declaration to bind to. Algol-24
needs no marker, because `unit` gives the file the declaration it was missing.
One rule then covers every doc comment in the language: **a `///` block
documents the declaration beneath it**, with no exceptions and no second form to
learn.

A unit header is also the only way to give a file a name the compiler checks:
`unit Wrong;` in `Greet.a24` is refused with `Unit 'Wrong' must match its file
name 'Greet'.`

**Exported names require a doc comment; private ones do not.** `private` at the
top level already marks a name unexported, so it already says which names have an
audience. This is Go's rule and it puts the effort where it is read.

**End the block on its last line of content.** This tree habitually closes a
doc comment with a bare `///` before the declaration. It separates nothing — the
declaration is its own terminator — and it is the one existing habit these
conventions ask to change.

## Checks

A convention stated in a document goes stale; a check that runs cannot. That
principle is why `spec.sh`, `conform.sh` and `fixedpoint.sh` exist, and
`/// Environment!` is what an unchecked convention produces.

1. Every **exported** top-level declaration has a doc comment.
2. The summary is one sentence, ends in a full stop, and is not the declared name
   re-spelled.
3. A test named by an `# Examples` section exists — the check `spec.sh` already
   performs for the specification's unit citations.
4. A section heading is one of the four. A misspelled `# Panics` should fail
   rather than render as prose.
5. A `///` that documents nothing — one that precedes a statement rather than a
   declaration — is an error.

**The fifth is Zig's rule and it is the one worth stealing outright.** Zig
makes a misplaced doc comment a compile error. Here it cannot be the language's
error, because [LEX-002] leaves `///` indistinguishable to the scanner — which is
exactly the case that rule's own note anticipates: *"tools may treat them
specially. The language does not."* So it is a check the tooling owes, and
declining to make it means `///` in the wrong place stays silently ordinary.

## A worked example

The declaration as this tree carries it today:

```
/// Gets a variable from the local scope, or looks in the enclosing environment.
///
/// # Errors
///
/// Returns a runtime error if reaches the top-level environment and does not find the variable.
///
function Get (Name : Token) : Any;
```

and as it now stands in `compiler/Environment.a24`:

```
/// Gets a variable, searching the local scope, then this file's imports,
/// then the enclosing environment.
///
/// An import is searched for its OWN bindings only, never through its
/// imports in turn, which is what makes 'uses' non-transitive.
///
/// The lookup is on the FOLDED name and the diagnostic echoes the lexeme,
/// because identifiers are matched without regard to case [SRC-011] while an
/// error must show the spelling the program used.
///
/// # Raises
///
/// 'Undefined variable ''X''.' when the search reaches the outermost scope
/// without finding the name, and '''X'' is ambiguous: A or B.' when two
/// imports both export it.
///
/// # Satisfies
///
/// [SRC-011]
function Get (Name : Token) : Any;
```

What changed, and why each: the summary names all three places searched, since
"or looks in the enclosing environment" omitted the one that surprises people;
`# Errors` became `# Raises`; the section says *when*, and quotes both messages a
caller can actually catch, rather than saying that an error occurs; the
non-transitivity note moved up from the field it was attached to, because it is a
fact about calling `Get` rather than about the field's storage, and it lost its
warning sign on the way; `# Satisfies` names the rule the specification locates
here; and the trailing `///` is gone.

**This block is copied from the tree, not composed for the page.** An example of
a convention that does not match the code it claims to describe is the same rot
the convention exists to prevent, so it is quoted verbatim and moves when the
declaration does.
