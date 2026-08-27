# Probes

The programs that were run to verify the specification's rules, and a recording
of what each one did.

⚠️ **A probe is not a conformance test.** A `.actual` file records what the
implementation **does**. It asserts nothing about what the implementation
**should** do, carries no authority, and a rule whose probe runs green is still
`conformance TBD` in `ALGOL-24.md`.

The distinction is deliberate, not pedantic. Deciding what the language ought
to do is an act taken once per rule, with Annex D in hand; writing a
conformance test the moment a behaviour is discovered would canonize every
defect on sight. `LEX-018` is the standing example — these probes record that
`2147483648` prints `-2147483648`, and Annex D recommends it should raise
instead. Both are true at once. Only one of them is a commitment.

## What they are for

**Evidence.** Every normative rule in the specification claims to have been
verified by running the interpreter. These are the runs. A reader who doubts a
rule can see the program and its output.

**A change detector.** `./spec/probes/record.sh` re-runs every probe and reports
anything that moved. It has no opinion about whether the new behaviour is
better — only that it is different, and that nobody recorded the decision. That
keeps the language from shifting under a half-written specification unnoticed.

**Raw material for the conformance corpus.** When the conformance pass happens,
each probe is a candidate, and the question asked of it is one question: *is
this what we want to conform to?* Where the answer is yes, the recording is
already the expected output. Where it is no, the rule earns an Annex D entry
and the conformance case asserts the behaviour we want instead — failing until
the implementation catches up.

## Using them

```sh
./spec/probes/record.sh            # re-run; report anything that moved
./spec/probes/record.sh --record   # accept the current behaviour as recorded
```

A moved probe exits non-zero. Re-record only once you have decided the change
was intended.

## Conventions

Each probe names the rules it exercises in a header comment:

```
// spec: LEX-023, LEX-029
```

A `.actual` holds the program's combined output followed by `exit: N`.

⚠️ Colour is **transliterated**, not stripped — `\033[31m` is recorded as
`[RED]`. Stripping is not injective, so a wrong colour and a right one would
compare equal afterwards and a colour change would be invisible to the
detector. An escape with no mapping records as `[ESC:…]` rather than passing
through or vanishing.

The recordings are therefore precise about things a stripped capture would
lose. `LEX-021` preserves the `[ERROR]` line whose `]` falls outside the white
run — a quirk `compiler/Console.a24` documents deliberately.
