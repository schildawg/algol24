# Proposal: a Char equals a one-character String

**From:** the three projects written in Algol-24 — `algol24-library`,
`shroom-slots`, and the website — and from the compiler's own development
**Status:** proposal, for the language project to accept, refuse or reshape
**Concerns:** one rule, [VAL-010]. No change to types, to the literal rules, to
widening, or to `is`

---

## Summary

Make `=` and `<>` treat a `Char` and a one-character `String` as equal, the way
they already treat an `Integer` and a `Double`:

```algol24
WriteLn ('a' = Str ('a'));        // false today, true under this proposal
WriteLn (1 = 1.0);                // already true [VAL-009]
```

Nothing else changes. `'a' is String` stays **false**, a one-character literal
stays a `Char` [LEX-023], and no existing program needs editing.

This asks the language project to overturn a decision it made deliberately and
wrote down. [VAL-010] states the asymmetry is intentional and gives its
reasons; this document answers them with measurements rather than preference.

---

## The language already contradicts itself here

This is the finding that prompted the proposal, and it is not a matter of
taste. With `C` the Char `'a'` and `S` the String `Str ('a')`:

| written | answers |
| --- | --- |
| `C <= S` | **true** |
| `S <= C` | **true** |
| `C < S` | false |
| `S < C` | false |
| `C = S` | **false** |
| `C <> S` | **true** |

Neither value is less than the other, each is less-than-or-equal to the other,
and the two are not equal. `a ≤ b ∧ b ≤ a ⟹ a = b` holds for every other pair
of values in the language and fails for this one.

Both halves are specified on purpose. [VAL-014] says a Char and a String
"compare as text" and that `Str ('a')` "orders identically to the Char `'a'` —
the two are still never *equal* [VAL-009], but they sit in one order."
[VAL-010] says they are never equal. Each rule is defensible alone; together
they describe an ordering that no value can satisfy.

**Ordering has already picked the direction [VAL-010] says cannot be picked.**
That is the crux. [VAL-010] argues that `Char` against `String` "has no target
at all" and that choosing one "would mean `=` converting its operands
differently depending on which side they arrived on." But `<` already compares
them, in one order, side-independently — and [VAR-004] already gives the
conversion a direction, since a Char widens to a String at every one of the six
assignment contexts [VAR-017] and never the reverse. The target exists, the
language uses it twice, and `=` is the one place it is withheld.

---

## Why three projects are asking

### The trap is reached by writing a type annotation

[VAL-010] says the rule "bites less often than it appears to… it is only
reached when one side came from `Copy`, `Str` or a subscript." Measured, there
is a fourth source, and it is the language's own widening:

```algol24
var F : String := 'x';        // the Char widens into the declared type
WriteLn (F = 'x');            // false
```

Four tokens, no `Copy`, no `Str`, no subscript. The annotation is what breaks
it: without `: String` the comparison is Char against Char and answers true.
That inverts the usual bargain of a gradually typed language, where writing a
type down is supposed to buy diagnostics rather than change an answer — and it
is the same shape as the `BoundValue` finding in `PROPOSAL-VM.md`, where
annotating a variable made the emitted code slower.

A field, a parameter and a return type do this too, because all six assignment
contexts widen alike.

### What the workaround costs, counted

Across the four codebases there are **2,409** one-character literals and **77**
places that wrap one in `Str (…)` for no reason but to make a comparison work:

| | one-char literals | `Str ('x')` workarounds |
| --- | --- | --- |
| `algol24.com` (432 files) | 1,090 | 12 |
| `algol24/compiler` | 640 | 14 |
| `algol24-library` | 434 | 45 |
| `shroom-slots` | 245 | 6 |

The workaround is most concentrated in **tests**, where a value's type is least
visible:

```algol24
AssertEqual (Str ('A'), EnvName ('A=b=c'));        // algol24-library/dos.a24
AssertEqual (Str ('0'), Str (RandomInteger (1)));  // algol24-library/random.a24
```

and in the compiler's own back ends, where an operator arrives as a String:

```algol24
if Op = Str ('-') then Into.Emit (OP_NEGATE);      // compiler/VmEmitter.a24
```

Every one of those `Str (…)` calls is a reader being told that two things which
look identical are not.

### It has produced a wrong diagnosis of an unrelated feature

`spec/HISTORY.md` D-14 concluded that circular imports fail with
`Type mismatch!` They do not. The entry records what actually happened:

> The `Type mismatch!` came from the probe's own fixtures, which returned `'A'`
> and `'B'` from functions declared `: String`. A one-character literal is a
> Char [LEX-023], so those functions failed whether or not any cycle existed —
> the recording was evidence of DEF-10 and was read as evidence about modules.

An entire specification entry was written about the wrong feature. That is the
cost worth weighing: not the keystrokes, but that the symptom points away from
the cause.

### And it does not stop at `=`

Because [VAL-013] couples membership to equality, the inconsistency reaches
every collection. The numeric pair unifies and the text pair does not:

| | `Integer` / `Double` | `Char` / `String` |
| --- | --- | --- |
| `=` | true | **false** |
| `in` | true | **false** |
| Map key lookup | finds it | **misses** |
| a Set holding both | 1 member | **2 members** |
| `IndexOf` | finds it | **misses** |

The Map row is a silent wrong answer rather than a diagnostic: a Map keyed by
`'n'` is not found by `Str ('n')`, and writing both leaves two entries that
print identically.

---

## The proposal

Amend [VAL-010] so that `=` and `<>` compare a `Char` against a `String` **as
text**, which is the phrasing [VAL-014] already uses for ordering. A Char
equals a String exactly when the String is one character long and holds that
character.

The direction is the one [VAR-004] already uses: the Char is read as the
one-character String it widens to. It is side-independent — the Char converts
whichever operand it is — so the objection in [VAL-010] about operands being
"converted differently depending on which side they arrived on" does not arise.

[VAL-013] then carries it into `in`, `Contains`, Map keys, Set membership and
`IndexOf` with no further rule, exactly as it already carries [VAL-009]'s
numeric promotion.

---

## What does not change

- **[LEX-023] stands.** A quoted literal of exactly one character is still a
  `Char`. None of the 2,409 literals changes meaning.
- **[TYP-003] stands.** `Char` and `String` remain distinct types and `is`
  still tells them apart: `'s' is String` is **false**. The question "what is
  this value?" keeps its honest answer; only "are these two the same?" changes.
- **[VAR-004] stands**, unamended. Widening already goes Char → String and this
  proposal borrows that direction rather than adding one.
- **[VAL-014] stands**, and becomes consistent rather than merely compatible:
  the two values that already sit in one order now also compare equal.
- **No existing program needs editing.** Every comparison that is true today
  stays true; some that are false today become true. The 77 `Str (…)`
  workarounds keep working and may be removed at leisure.
- **Nothing about `#NN`, `Ord`, `Char ()`, `Length`, or how a Char is stored.**

---

## Risks

**It makes a previously-false comparison true, which is a behaviour change.**
A program relying on `'a' <> Str ('a')` would break. We searched all four
codebases and found no such reliance — but absence of evidence over 2,409 sites
is weaker than a proof, and a fifth project might differ. Worth a `[WARN]`
during one release rather than a silent flip, if the project wants belt and
braces.

**Equality and hashing must move together.** A Map and a Set must agree with
`=`, which means a Char and its one-character String have to hash alike in both
processors and in `bootstrap/algol.c`. The numeric pair already does this, so
the mechanism exists; it is still two implementations that must not drift.

**[TST-008]'s type-naming report loses a case.** `AssertEqual` renders
`Expected Char 's' but got String 's'` precisely because the two compare
unequal while printing alike. Under this proposal that comparison passes, so
the message becomes unreachable for equal values. It is still wanted for
genuinely different values that render alike, so the form stays — but
`spec/HISTORY.md` D-18 should record that its original motivating case is gone.

**It narrows what the type system can express.** A program wanting "exactly one
character, not a String of one" can no longer get it from `=`. It can still get
it from `is`, which is the right tool for that question.

---

## Open questions for the language project

Genuine ones; the asking projects have no basis to decide them.

1. **Is [VAL-010]'s reasoning answered, or only disputed?** The rule says
   representation-change is not widening. This document replies that [VAR-004]
   already widens in that direction and [VAL-014] already orders across it. If
   the project still holds that `=` is different in kind from `<`, the proposal
   fails and the right outcome is to amend [VAL-014] instead — making `<`
   refuse a Char against a String, so the two rules agree by *tightening*
   rather than loosening. Either resolution ends the contradiction; this
   document argues for the loosening because it is the one no program has to
   change for.
2. **The empty String.** `Str ('') = ?` against a Char — no Char equals a
   zero-length String, which falls out, but it wants stating.
3. **A `[WARN]` first?** [ERR-010] already warns where `and` or `or` is handed
   an Integer, for the same reason: the reader writes the obvious thing and
   gets a plausible wrong answer. A release that warns on a Char-against-String
   comparison before changing it would surface any reliance we failed to find.
   `spec/spec.sh` checks the three existing warnings against
   `spec/warning.a24`, so a fourth is a known shape of change.
4. **Does the alternative framing serve better?** [VAL-010] proposes one: "the
   complaint worth acting on is how easily a one-character String is produced
   by accident." We considered it and think not — the producers are all
   *correct*. `Copy (S, 0, 1)` genuinely yields a String, `Str (X)` genuinely
   yields a String, and `var F : String := 'x'` genuinely widens. There is
   nothing there to repair; the friction is at the comparison, which is why
   this proposal is about the comparison.
5. **And the other alternative, which this does not ask for:** making a
   one-character literal a `String` and requiring `Char ('S')` or `#83`. It was
   the first idea considered and measurement argued against it — a subscript and
   `for … in` still yield Chars, so `Source[Start] = '0'` and `Peek () = 'x'`
   would become the new silent `false`. That is 56 comparisons across the four
   codebases and the central idiom of every scanner, including this compiler's.
   It moves the trap into the place where a one-character literal is currently
   right.

---

## What this proposal does not ask for

- Removing `Char`. It is the right type for a subscript and for `for … in`, and
  `Ord`/`Char ()` need it.
- Changing what a literal denotes [LEX-023].
- Changing `is` [TYP-003], or widening [VAR-004].
- Cross-type equality for anything else. `1 = '1'` stays false; a number and
  text are different things, where a Char and a one-character String are the
  same thing twice.
- Any change to ordering [VAL-014], which already behaves as this proposal
  wants `=` to.

---

## What the asking projects would do with it

- **`algol24-library`** would retire 45 `Str (…)` wrappers, most of them in
  test assertions where they obscure what is being asserted.
- **`shroom-slots`** would retire 6, and stop carrying `Str ('-')` for a
  one-character separator.
- **`algol24.com`** would retire 12 across its 432 files — the largest body of
  Algol-24 that exists, and the one where a one-character literal is most often
  a piece of markup compared against text.
- **The compiler** would retire 14, including `Op = Str ('-')` in two back ends,
  where an operator's lexeme arrives as a String and is compared against what
  reads like a character.
- **All four** would stop having to explain the rule to a reader of their own
  source, which is the cost that does not show up in a diff.

---

## Appendix: how the evidence was gathered

Everything measured here came from running `algc 0.1.6`, not from reading it.
The contradiction table is the output of a six-line program; the collection
table is two programs of five lines each, one per type pair; the "what produces
a Char" findings are a program printing `is Char` and `is String` for a
subscript, `Copy`, `for … in` and a declared `String`. The literal and
workaround counts are searches over all `.a24` files in the four repositories,
`algol24.com`'s 432 included. The
D-14 quotation is from `spec/HISTORY.md` in this repository.

The one claim not established by measurement is that no program relies on a
Char and a String being unequal. That is a search over four codebases finding
nothing, which is weaker, and it is listed under *Risks* as such.
