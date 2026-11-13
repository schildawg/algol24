# Finished proposals and plans

A proposal lands here when **what it proposed has been built**. It is kept
rather than deleted because the measurements in it are the reason the thing
looks the way it does, and because a proposal is the only place that records
what was considered and rejected.

⚠️ **Landing here does not mean every question in the document is answered.**
Several carry open questions that were future work when the proposal was
accepted and still are. Each file's header says what it decided, when that
landed, and what remains — read the header before assuming the body is
history.

A proposal that was **refused**, or that is still **open**, stays in the
repository root. Those are live documents; these are not.

| | decided | what remains |
| --- | --- | --- |
| `PROPOSAL-GC.md` | v0.2.0 — a precise collector under every processor | four questions about arena sizing and region lifetimes |
| `PROPOSAL-VM.md` | v0.2.0 — `algvm`, a third processor | the bytecode artifact, a `case` jump table, and whether 25 fps suits the Inn |
| `PROPOSAL-RUNTIME-LOCATION.md` | v0.2.4 — a runtime error names its file and line | the call stack, deliberately deferred |
| `PROPOSAL-CHAR-EQUALITY.md` | v0.3.0 — a Char equals a one-character String | nothing; the `as` observation was never a request |
| `PROPOSAL-COLLECTABLE-TEXT.md` | v0.3.0 — every String and Char is swept | the value representation, which this deliberately did not change |
| `PROPOSAL-DIRECTORY-LISTING.md` | v0.4.0 — `Entries`, [RT-026]'s fifth directory built-in | whether the library's three `external`s come out, which is its own call |
| `PROPOSAL-LIBRARY-PATH.md` | v0.2.1 for the module path, v0.4.0 for the shims [FUN-017] | whether `--compile` copies a used unit's shims, and a `--where` flag |
| `PLAN-0.1.6.md` | v0.1.6 — four items | nothing |
| `PLAN-0.2.4.md` | v0.2.4 — sixteen defects, all closed | nothing |

Still live, in the root:

| | |
| --- | --- |
| `PROPOSAL-CONCURRENCY.md` | **open.** |
| `PROPOSAL-REFLECTION.md` | **open in part.** The language's half shipped in v0.3.1; the library has a `reflect` unit in its 0.2.0 and `testing` has not adopted it. |
