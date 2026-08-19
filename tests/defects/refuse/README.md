# tests/defects/refuse

Programs that **must be refused**, and the sentence they must be refused with.

An ordinary reproduction in the parent directory is a `test` block that passes
once the defect is fixed. That shape cannot express a rule whose correct outcome
is *this program does not run* — a refusal produces no observable behaviour to
assert. Four issues have hit that wall: #4, #14, #15 and #18.

Each file here carries its expected refusal in its header, in the shape
`tests/mem/` already uses for its budgets:

```
/// REFUSE: Undefined variable 'NeverDeclared'.
```

The oracle has three parts, and the second is the one that earns the harness:

1. the **interpreter** refuses the program;
2. its sentence **matches** the header exactly, once `[ERROR] file:` and
   `Uncaught:` framing is stripped;
3. the **compiler** refuses it too, rather than emitting.

Clause 2 is not pedantry. Every file here is currently refused for *some*
reason — a feature that does not parse is refused as surely as a rule that is
enforced — so a harness checking only *that* it failed would report every one of
these as already correct. The sentence is what distinguishes a rule being
applied from a syntax error standing in for it.

Clause 3 is where the two processors have historically parted company. A static
error is decided in the shared front end, so both should refuse alike; where one
refuses and the other emits, that is the defect rather than a detail.

Run it with the rest: `./tests/defects/run.sh`.
