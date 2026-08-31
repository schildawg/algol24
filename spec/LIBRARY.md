# The Algol-24 Library Specification

> **Status: opened at Gen-8, and mostly empty on purpose.** The language is
> feature-complete; what remains is a library, and this is where it is decided
> and written down.
>
> ⚠️ **This document exists so that `ALGOL-24.md` does not have to grow.** The
> language specification describes **the language** — 280 rules, every one
> claimed by a case in `conformance/`, `refusals/` or `defects/`. A library
> written *in* Algol-24 is not the language, and putting it there would blur the
> one boundary the corpus depends on. Nothing here is a rule, nothing here is
> numbered `XXX-000`, and `spec/spec.sh` does not read this file.
>
> ⚠️ **The bootstrap should be finished with.** From here on the library is
> ordinary Algol-24 compiled by an `algc` that already exists, so a change to a
> unit is a change to a unit. Reseeding is for bugs in the compiler now, not for
> building on top of it.

---

## 1. What goes in which document

| | `ALGOL-24.md` | `LIBRARY.md` |
| --- | --- | --- |
| Describes | the language | what is written in it |
| Numbered rules | yes, `XXX-000` | no |
| Pinned by | `conformance/`, `refusals/`, `defects/` | inline `test` blocks |
| Checked by | `spec/spec.sh`, `./conform.sh` | `./test.sh` |
| Changing it | changes the language | adds or changes a unit |

⚠️ **A library entry never becomes a rule, and a rule never moves here.** The
one thing that can happen at the boundary is a library unit needing something
the language does not have — and that is an Annex H entry in the other
document, decided there, not a library question.

---

## 2. How each entry is classified

Turbo Pascal is the reference being walked, routine by routine. Each gets one
of four verdicts — and there is a fifth row below them that is not a verdict but
a fact, and that shortens the walk considerably.

| Verdict | Means | Test for it |
| --- | --- | --- |
| **✗ Not needed** | Algol-24 does not want it. | It serves a machine, a memory model or a habit this language does not have. |
| **A24** | Can be written entirely in Algol-24. | It needs nothing but the language and what is already in it. |
| **FFI** | Is the foreign declaration, essentially. | The whole of it is one C function; wrapping it would add a name and no concept. |
| **A24 + FFI** | Written in Algol-24, over a foreign call. | The logic is ours; only the primitive underneath is C's. |
| *Already* | The language provides it — §3. | It is a built-in or a member, and a rule specifies it. |

⚠️ **The verdicts are about what *should* be, not what is easiest.** Since
[FUN-014] landed, almost everything *can* be FFI — `strlen` is right there. The
question each entry answers is which shape the resulting Algol-24 reads best in,
because that is how this language decides things.

⚠️ **"Not needed" is a real answer and should be used.** Turbo Pascal's library
answers to a 16-bit machine with manual memory, typed files and a text console.
This language has an unbounded Integer, an arena, and no `IOResult`. Porting a
routine because it exists is how a library becomes a museum.

---

## 3. What the language already provides

Not to be re-walked. These are the twenty-nine built-ins of Annex B and the
members of the two resources; each names the rule that specifies it.

| Turbo Pascal | Algol-24 | Rule |
| --- | --- | --- |
| `Chr` | `Char` | [RT-008] |
| `Ord` | `Ord` | [RT-007] |
| `Length` | `Length` | [RT-003] |
| `Copy` | `Copy` — zero-based | [RT-004] |
| `Pos` | `Pos` — zero-based, `-1` when absent | [RT-005] |
| `Str` | `Str` — a function, not a procedure | [RT-006] |
| `Val` | `Val` — a function, and no error code | [RT-009] |
| `Concat` | `+` | [EXP-008] |
| `Succ`, `Pred` | `Succ`, `Pred` | [RT-020] |
| `Halt` | `Halt` | [RT-018] |
| `Exit` | `Exit` — a statement, not a routine | [STM-014] |
| `ParamCount`, `ParamStr` | the same | [RT-013] |
| `Write`, `WriteLn` | the same, variadic | [RT-015] |
| `Assign`, `Reset`, `Rewrite`, `Append` | members of a `TextFile` | [RT-024] |
| `Close`, `Flush`, `Erase`, `Rename` | the same | [RT-024] |
| `Eof` | a property of a `TextFile` | [RT-024] |
| `ReadLn` | a member, and a line is the scanner's line | [RT-016] |
| `New`, `Dispose`, `GetMem`, `FreeMem` | `Buffer`, and `Free` | [RT-023] |

⚠️ **Where a name survived but its shape changed, the shape is this language's.**
`Str` and `Val` are functions rather than procedures with `var` parameters;
strings are 0-based [EXP-015] so `Copy` and `Pos` count from zero; `Exit`
returns rather than leaving a block. A library entry must not reintroduce the
Pascal spelling beside the Algol-24 one.

---

## 4. The walk

Turbo Pascal's routines, by the unit they came from. Filled in as they are
decided.

### 4.1 System — arithmetic

| Routine | Verdict | Notes |
| --- | --- | --- |
| `Abs` | | |
| `Sqr` | | |
| `Sqrt` | | |
| `Exp` | | |
| `Ln` | | |
| `Sin` | | |
| `Cos` | | |
| `ArcTan` | | |
| `Pi` | | |
| `Int` | | |
| `Frac` | | |
| `Round` | | |
| `Trunc` | | |
| `Odd` | | |
| `Random`, `Randomize` | | |

### 4.2 System — ordinals and text

| Routine | Verdict | Notes |
| --- | --- | --- |
| `Inc`, `Dec` | | |
| `UpCase` | | |
| `Insert` | | |
| `Delete` | | |
| `FillChar` | | |
| `Move` | | |
| `SizeOf` | | |
| `Swap`, `Hi`, `Lo` | | |

### 4.3 System — files beyond text

| Routine | Verdict | Notes |
| --- | --- | --- |
| `Seek`, `FilePos`, `FileSize` | | |
| `Truncate` | | |
| `BlockRead`, `BlockWrite` | | |
| `Eoln`, `SeekEof`, `SeekEoln` | | |
| `IOResult` | | |
| `Read` (console) | | |

### 4.4 System — memory

| Routine | Verdict | Notes |
| --- | --- | --- |
| `Ptr`, `Addr`, `Seg`, `Ofs` | | |
| `Mark`, `Release` | | |
| `MemAvail`, `MaxAvail` | | |

### 4.5 Crt

| Routine | Verdict | Notes |
| --- | --- | --- |
| `ClrScr`, `ClrEol` | | |
| `GotoXY`, `WhereX`, `WhereY` | | |
| `TextColor`, `TextBackground` | | |
| `KeyPressed`, `ReadKey` | | |
| `Delay`, `Sound`, `NoSound` | | |
| `Window` | | |

### 4.6 Dos

| Routine | Verdict | Notes |
| --- | --- | --- |
| `GetDate`, `GetTime`, `SetDate`, `SetTime` | | |
| `GetEnv` | | |
| `Exec`, `DosExitCode` | | |
| `FindFirst`, `FindNext` | | |
| `DiskFree`, `DiskSize` | | |
| `FSplit`, `FExpand`, `FSearch` | | |

### 4.7 Graph

Deferred as a unit rather than routine by routine: the target is SDL, not
Borland's BGI, and the shape of the Algol-24 API is its own question. Recorded
here so the walk does not stall on sixty entries that all answer the same way.

### 4.8 Beyond Turbo Pascal

Things the walk will not produce, kept here so they are not lost:

| Unit | Notes |
| --- | --- |
| Collections | The library collections built on `Array` — Annex H, H-9. |

---

## 5. How a library unit is written

⚠️ **Unit tests, never conformance cases.** `conformance/` and `refusals/` pin
the language. A unit written *in* the language is tested by inline
`test '...'; begin … end` blocks in its own source, which `./test.sh` runs —
comprehensive ones, one target per thing the unit offers.

⚠️ **Documented here, not there.** An entry says what the unit offers and why it
is shaped that way. The `⚠️` convention carries over: a paragraph marked that
way is a hard-won constraint, and explains why the obvious alternative was
wrong.

⚠️ **Both processors, as ever.** A unit must behave identically interpreted and
compiled. Nothing about being a library relaxes that — it is the one bar the
whole project is built on.
