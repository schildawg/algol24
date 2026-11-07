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
| `PLAN-0.1.6.md` | v0.1.6 — four items | nothing |
| `PLAN-0.2.4.md` | v0.2.4 — sixteen defects, all closed | nothing |

Still live, in the root:

| | |
| --- | --- |
| `PROPOSAL-CHAR-EQUALITY.md` | **refused so far.** [VAL-010] still states the asymmetry is deliberate and answers the proposal's measurements. It stays because the argument is good and the decision could be revisited. |
| `PROPOSAL-DIRECTORY-LISTING.md` | **open.** A listing in the core, which `algol24-library` already needed badly enough to write an FFI shim for. |
| `PROPOSAL-LIBRARY-PATH.md` | **half shipped, half open.** The module search path landed in v0.2.1 [MOD-002]; the foreign library search did not, and is worked around in packaging by a wrapper that sets the loader path. |
