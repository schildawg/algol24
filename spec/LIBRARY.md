# The Algol-24 Library Specification

> **Status: opened at Gen-8, and mostly empty on purpose.** The language is
> feature-complete; what remains is a library, and this is where it is decided
> and written down.
>
> ⚠️ **This document exists so that `ALGOL-24.md` does not have to grow.** The
> language specification describes **the language** — every rule of it claimed
> by a case in `conformance/`, `refusals/` or `defects/`. A library
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

Not to be re-walked. These are the built-ins of Annex B and the members of the
two resources; each names the rule that specifies it. Annex B is the index and
`spec/spec.sh` counts it, which is why no number is written here.

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
| `Abs` | **A24** | Untyped, so the result type follows the argument — see below. Unit: `math` |
| `Sqr` | | |
| `Sqrt` | | |
| `Exp` | | |
| `Ln` | | |
| `Sin` | | |
| `Cos` | | |
| `ArcTan` | **FFI** | `external 'atan'` — the declaration is the implementation |
| `Pi` | | |
| `Int` | | |
| `Frac` | | |
| `Round` | | |
| `Trunc` | | |
| `Odd` | | |
| `Random`, `Randomize` | | |

*Both live in a `math` unit — see Q6 for the boundary that raises.*

**`Abs (X)`** — the result takes the argument's type, and that falls out rather
than being arranged: `0 - X` is an Integer when `X` is one and a Double as soon
as a Double reaches it [EXP-004].

```
function Abs (X);
begin
    if X <= 0 then Exit 0 - X;
    Exit X;
end
```

⚠️ **`<=`, not `<`, and the difference is negative zero.** `-0.0 < 0` is false,
so `<` hands `-0.0` straight back; `<=` runs it through `0 - X` and yields
`0.0`. Turbo Pascal clears the sign bit and agrees.

⚠️ **Better than the C it replaces.** `abs(INT_MIN)` is undefined behavior in C
because the negation overflows. An Integer here is unbounded [LEX-018], so the
trap does not exist — `Abs` of −2¹²⁷ answers 2¹²⁷.

⚠️ **It must be written UNTYPED, and that costs the caller something.** A value
of type `Any` is not assignable to a written type [VAL-001], so `var N : Integer
:= Abs (-5);` is refused while `Take (Abs (-5))`, `Abs (-5) + 1` and
`var N := Abs (-5);` are all fine — a declared variable is the one context that
rejects it. Two typed overloads are not a way out, for the reason recorded as an
open question below.

`Abs ('text')` and `Abs (nil)` answer `Operands must be numbers.`, from the
subtraction rather than from a check of its own.

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
| `Addr` | **✗ Not needed** | No Algol-24 variable has an address to take — see below |
| `Ptr`, `Seg`, `Ofs` | | |
| `Mark`, `Release` | | |
| `MemAvail`, `MaxAvail` | | |

**`Addr (X)`** — not merely unwanted but incoherent here. A value is tagged and
arena-allocated, `concat` may move a String's bytes to append in place [G.2],
and a `var` is a slot in an environment rather than a location. There is nothing
whose address would stay true long enough to be worth having.

The one honest case — *memory the program owns and means to hand to C* — is
already served by `Buffer.Address` [TYP-017], which is a property of something
that really is a block of bytes.

### Can `Pointer` stay hidden?

**It already is, everywhere but one place.** A program can take a handle from C,
hold it, store it in a `List` and a `Map`, compare it by identity and hand it
back — without the word `Pointer` appearing:

```
var A := Allocate (32);          // untyped; the type is never written
var Handles := [A, B];
Named['first'] := A;
WriteLn (Named['first'] = A);    // true -- identity survives a Map
CopyBytes (Named['first'], 'hi', 3);
```

The one place it must be written is an `external` declaration — and ⚠️ **there
it is containment, not exposure.** The same C function declared two ways:

```
function AllocOpaque (N : Integer) : Pointer; external 'malloc';   // <pointer>
function AllocNumber (N : Integer) : Integer; external 'malloc';   // 4381188096
```

Declared `Integer`, the address comes back as a **number** — printable,
comparable, and arithmetic-able, which is everything [TYP-017] exists to
prevent. Writing `Pointer` is what keeps it opaque. Removing the type from the
language would not hide pointers; it would expose them.

⚠️ **So "hidden" is a matter of library structure, not of language machinery.**
The bindings units are plumbing and name the type; `graph`, `crt` and the rest
hand out objects of their own, and a program that uses them never meets a
`Pointer`. Visibility on a type name would be machinery to enforce what the
arrangement of units already gives.

### 4.5 Crt

| Routine | Verdict | Notes |
| --- | --- | --- |
| `AssignCrt` | **A24** | In **both** units, and it is what makes them one vocabulary — see below |
| `ClrScr`, `ClrEol` | | |
| `GotoXY`, `WhereX`, `WhereY` | | |
| `TextColor`, `TextBackground` | | |
| `KeyPressed`, `ReadKey` | | |
| `Delay`, `Sound`, `NoSound` | | |
| `Window` | | |

**`AssignCrt (F)`** — in Turbo Pascal this bound a `Text` variable to the screen
so that `Write (F, …)` went to the console instead of to a file. Here it is the
routine that makes `crt` and `graph` **one vocabulary without one
implementation**, which is the thing the two-unit design otherwise has to
promise on trust.

⚠️ **Each unit hands back a different thing, and the call site cannot tell.**
`crt` returns a real `TextFile`, because on Unix the console *is* a file;
`graph` returns a class of its own that writes into the cell grid. Both answer
to `Write`, `WriteLn` and `Close`, and dispatch does the rest:

```
procedure Emit (Sink);          // does not know or care which it got
begin
    Sink.WriteLn ('the same call, whatever is behind it');
    Sink.Close ();
end
```

That is the same structural style the language already uses for `ToString`,
`Elements` and `Contains` [TYP-011] — a thing either answers to the member or it
does not. The shared vocabulary stops being a documented promise that two units
export matching names and becomes a property of the values they return.

⚠️ **`crt`'s half is one line, because the console is a file.**
`F.Assign ('/dev/tty'); F.Rewrite ();` and `F.WriteLn` reaches the terminal —
no FFI, no escape codes, nothing added to the language. Fall back to
`/dev/stdout` where there is no controlling terminal, which is how it behaves
under a pipe or a test harness.

⚠️ **`graph`'s half CANNOT be a `TextFile`, and that is a language limit.** An
`ObjFile` holds a `FILE *` from `fopen`; nothing in [RT-024] lets a program bind
one to anything but a path. So the two sinks are duck-compatible but not the
same type, and `X is TextFile` tells them apart. That is acceptable — it is only
a problem for a program that asks, and none should.

⚠️ **MIXING THE TWO SINKS REORDERS THE OUTPUT.** A `TextFile` on `/dev/stdout`
and the ordinary `WriteLn` are two `FILE *` streams onto one descriptor, each
with its own buffer. In the run above, a line written by `WriteLn` came out
*after* a line written later through the file. Whichever a program picks, it
should pick one.

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

⚠️ **Every routine in this unit is A24 + FFI by construction**, so the verdict
column carries almost no information here: `graph` needs SDL to have a window at
all, and everything drawn into the framebuffer is Algol-24. What matters in this
section is the **notes** — the signature, the convention, and what changes from
Borland's BGI.

Grouped rather than alphabetical, because the grouping is the analysis. Sixty
routines, and the verdict is **A24 + FFI** for all but the one marked
otherwise — `graph` needs SDL for a window and everything above that is
Algol-24.

| Group | Routines | Notes |
| --- | --- | --- |
| **Opening** | `InitGraph`, `CloseGraph` | Size, title, and the cell size the grid derives from |
| **Pages** | `SetActivePage`, `SetVisualPage` | Become one `Flip`; offscreen surfaces are a separate feature — O2 |
| **Bounds** | `GetMaxX`, `GetMaxY`, `GetMaxColor` | Keep; `GetMaxX` is width **− 1** — see O3 |
| | `GetAspectRatio` | **✗ Not needed** — square pixels — see O3 |
| **Drawing state** | `SetColor`, `GetColor`, `SetBkColor`, `GetBkColor` | State is chosen — Q5 answered |
| | `SetLineStyle`, `GetLineSettings` | |
| | `SetFillStyle`, `SetFillPattern`, `GetFillPattern`, `GetFillSettings` | An 8 × 8 bit pattern |
| | `SetWriteMode` | XOR and COPY; XOR is what rubber-banding needs |
| **Position** | `MoveTo`, `MoveRel`, `GetX`, `GetY` | The current point `LineTo` draws from |
| **Primitives** | `Line`, `LineTo`, `LineRel`, `Rectangle`, `Bar`, `Bar3D` | |
| | `Circle`, `Ellipse`, `FillEllipse`, `Arc`, `PieSlice`, `Sector` | Angles as `Arc`'s |
| | `DrawPoly`, `FillPoly` | Take a `List` of points, not a pointer and a count |
| | `PutPixel`, `GetPixel`, `FloodFill` | `GetPixel` is free: the framebuffer is ours |
| | `GetArcCoords` | Where the last arc started and ended |
| **Images** | `GetImage`, `PutImage`, `ImageSize` | A `Buffer` is exactly the right shape |
| **Viewport** | `SetViewPort`, `GetViewSettings`, `ClearViewPort` | Clipping plus an origin |
| **Text** | `ClrScr`, `ClrEol`, `DelLine`, `InsLine` | Console vocabulary, on the cell grid |
| | `GotoXY`, `WhereX`, `WhereY`, `Window` | |
| | `TextColor`, `TextBackground` | |
| | `LowVideo`, `HiVideo` | Keep, but see O5 |
| **Text metrics** | `TextWidth`, `TextHeight` | Keep — CJK is two cells, so these are needed |
| | `SetTextJustify`, `GetTextSettings` | Cell-based here |
| | `SetTextOrientation` | Replaces `SetTextStyle`; vertical text — see O4 |
| **Off-grid text** | `Write`, `WriteLn` with `X:` and `Y:` | A named-parameter overload — see O6 |
| **Input** | `KeyPressed`, `ReadKey` | From SDL events here, from raw mode in `crt` |
| **Sink** | `AssignCrt` | **A24**. Also in `crt` — see §4.5 |

**`Arc (X, Y, Radius, StartAngle, EndAngle)`** — a circular arc. Trig comes from
libm, the pixels are ours.

⚠️ **Double coordinates, not BGI's Integer.** BGI took integer pixels because it
was addressing a pixel grid directly. Doubles cost nothing here and are what
make an **antialiased** arc possible — a subpixel endpoint is the difference
between an arc that looks drawn and one that looks stair-stepped, which is the
same argument as coverage-versus-bits for glyphs.

⚠️ **Degrees, and BGI's convention: 0° at three o'clock, counterclockwise.**
Kept because it is what a Turbo Pascal programmer expects and because
`Arc (100, 100, 50, 0, 90)` reads better than the radian form. Note that
counterclockwise *on screen* means **subtracting** the sine, since screen Y
grows downward:

```
  0 deg -> x 150.0, y 100.0     three o'clock
 90 deg -> x 100.0, y  50.0     twelve o'clock -- y SMALLER than the centre
180 deg -> x  50.0, y 100.0     nine o'clock
270 deg -> x 100.0, y 150.0     six o'clock
```

Getting that sign wrong mirrors every arc in the library, and nothing but a
picture would catch it.

#### What the list decides

⚠️ **Q5 is answered: `graph` carries drawing state.** `SetColor`, `SetBkColor`,
`SetFillStyle`, `SetLineStyle`, `SetWriteMode`, `MoveTo` and `SetViewPort` are
all on the list with their `Get` counterparts, which is BGI's stateful model
entire. Chosen by choosing the routines rather than by argument — and it is the
consistent answer, because the console half genuinely has state already:
`TextColor` sets it and `Write` uses it. A stateless drawing half beside a
stateful text half would have been the asymmetry.

⚠️ **The list IS the merged vocabulary, which confirms the two-unit design.**
`ClrScr`, `ClrEol`, `DelLine`, `InsLine`, `GotoXY`, `WhereX`, `WhereY`,
`Window`, `TextColor`, `TextBackground`, `KeyPressed` and `ReadKey` are Turbo
Pascal's **Crt** unit, not its Graph unit. Asking for them here is the design:
one vocabulary, and `graph` owes the whole console contract.

⚠️ **`OutText` and `OutTextXY` are absent, and that is the point.** BGI's way of
drawing text was a string at a pixel coordinate. Leaving them off keeps the
promise that text is written the same way in both units — `GotoXY` and `Write`,
never a second spelling for a second unit.

#### Open questions this list raises

**O1 — ANSWERED: `InitGraph` and `CloseGraph` keep their names.** They carry
the window's size, its title, and the cell size the character grid derives from.
What they no longer carry is BGI's driver-and-mode pair, which existed to pick a
video card.

**O2 — the pages become `Flip`, but the need behind them is separate and
real.** The two calls collapse into one, because the framebuffer is already a
back buffer and `SDL_RenderPresent` already shows it.

⚠️ **Drawing offscreen is a different feature, and a better one.** BGI's pages
were a fixed number of same-sized video pages; what is actually wanted is an
arbitrary surface a program can draw into with the ordinary routines and then
blit. That is `GetImage` / `PutImage`'s memory with the drawing routines
pointed at it — a **render target** — and it subsumes double buffering rather
than being a variant of it. Left open: whether that is a distinct type or a
`SetTarget` beside `SetViewPort`.

**O3 — the `(?)` on the bounds routines.** `GetMaxX` and `GetMaxY` are needed:
a program that draws must know how much room it has. But BGI's return is the
maximum valid *coordinate*, one less than the width, which is a reliable
off-by-one. Recommend keeping the routines and considering `ScreenWidth` /
`ScreenHeight` beside them. **`GetAspectRatio` is the clearest museum piece on
the list** — it existed because CGA and EGA pixels were not square and `Circle`
had to correct for it. Pixels are square now, so it would answer 1:1 forever.

**O4 — `SetTextStyle` becomes `SetTextOrientation`**, keeping the part that was
wanted — BGI's `Direction` argument, for vertical text — and dropping the font
and size multiplier, which have nothing to select here.

⚠️ **"Vertical" is two different features, and BGI conflated them.** Its
`VertDir` **rotated the glyphs** ninety degrees, which is what a chart's Y-axis
label needs. CJK vertical writing instead keeps every glyph **upright and stacks
them down a column**. A bitmap cell font can do both cheaply — stacking is
advancing Y instead of X, and rotating is transposing the cell — so the question
is which one the name means, not which one is affordable.

`TextWidth` and `TextHeight` are the opposite case and should **stay**: a cell
is one column for Latin and two for CJK, so `TextWidth ('你好')` genuinely
differs from `TextWidth ('ab')` and nothing else can tell a program that.

**O6 — off-grid text as a named-parameter overload. It works, and it binds
better than the positional form.** The proposal is `WriteLn (S)` on the grid and
`WriteLn (S, X: 137, Y: 42)` at a pixel — one verb, and the call site says which
it means.

⚠️ **The names are not decoration: they resolve the overload at COMPILE time.**
Given a variadic `Show (Values : List of Any)` beside a placed
`Show (S, X, Y)`, the bare call warns and the named call does not:

```
Show ('A', X: 1, Y: 2);      // silent  -- bound statically
Show ('B', 1, 2);            // [WARN] 'Show' selects among 2 overloads at run time
```

That is exactly what named arguments and [ERR-010]'s warning were added for, and
it makes the named form the *preferred* spelling rather than merely a readable
one.

⚠️ **A user-defined `WriteLn` takes only the argument counts it declares**
[RT-027]. Declaring `WriteLn (S, X, Y)` leaves `WriteLn ('x')` and `WriteLn ()`
reaching the **built-in**, which writes to standard output — so a graphics
program that declares only the placed form has a `WriteLn` that goes to the
window at three arguments and to the terminal at one, which is the worst of both
and would be found at run time rather than at the declaration.

So `graph` must still supply the whole set, and now for a sharper reason than
before: not because a declaration replaces the built-in, but because it does
**not**, and every count left undeclared silently keeps the old destination. A
variadic `WriteLn (Values : List of Any)` reproduces [RT-015] with a
`List of Any` parameter [FUN-005] and takes every count from zero upward, which
is the one declaration that leaves nothing behind.

Two things left open by it:

- **What does "Ln" mean off the grid?** There is no line to end. Either it
  advances Y by the line height — which keeps the name honest and makes
  successive placed calls stack — or off-grid writing is `Write` only.
- **Two cursors, or one?** If `WriteLn (S, X:, Y:)` leaves a pixel position
  behind, where does a following bare `WriteLn (S)` go — on from there, or back
  to the cell cursor? One of them has to be the answer, and neither is obvious.

**O5 — `LowVideo` / `HiVideo` are a 16-color idea in a 24-bit unit.** They dim
and brighten the current text color, which mattered when there were eight
colors and an intensity bit. Harmless to keep as a shade of the current
color; worth asking whether anyone would reach for them beside `TextColor`.

### 4.8 Beyond Turbo Pascal

Things the walk will not produce, kept here so they are not lost:

| Unit | Notes |
| --- | --- |
| Collections | The library collections built on `Array` — Annex H, H-9. |

---

## 4.9 Open questions raised by the walk

Recorded as they arise and settled at the end, from the whole survey rather than
from the routine that happened to surface them.

**Q1 — Where does a type-preserving function live?** `Abs` is untyped because it
must be, and [VAL-001] then keeps its result out of a declared variable. The
same will be true of `Sqr`, `Max`, `Min`, `Odd` and anything else whose result
follows its argument, so this is a question about the shape of the whole
library, not about `Abs`.

**Q2 — The checker takes the LAST declared overload's return type, whatever the
argument is.** This makes two typed overloads useless as a way round Q1, and it
is a defect rather than a limitation: the answer is *wrong*, not unknown.

```
function F (X : Integer) : Integer; begin Exit X; end
function F (X : String)  : String;  begin Exit X; end

var N : Integer := F (5);      // Expected Integer, found String.
```

Swap the two declarations and the same line compiles and prints `5`. The
`[WARN]` is right that selection happens at run time [ERR-010]; what should
follow is a static type of `Any`, which [VAL-001] would then refuse
consistently and a cast could resolve. Instead the checker commits to one
overload it has not chosen.

⚠️ **This one belongs to the language, not the library**, and wants a defect
entry in `spec/DEFECTS.md` with a reproduction — the survey found it, it does not wait on
the survey.

**Q7 — a library function cannot ask whether a value is an enum member.**
*(Raised while `Ord` was briefly a library function; it is a built-in again, so
this now bears on H-9 rather than on `Ord`.)*
`Ord` accepts one, because a member carries `Ordinal` [ENU-010]. Nothing else in
the language answers that property — an Integer, a `Char`, `nil`, an instance
and a `List` were all checked and every one raises — so the test is sound. But
there is no `is Enum`, so the only way to run it is to read the property and
catch the failure:

```
try Exit X.Ordinal; except end
```

Using an exception as a type test is not what this language reads like
anywhere else. The fix belongs to the language — either `is Enum`, or admitting
`Ordinal` as a structural protocol beside `Contains`, `ToString`, `Elements`,
`Compare` and `Get`/`Put` — and it is the first thing the library has wanted
that the core does not offer.

**Q6 — ANSWERED, and the answer was to remove rather than move.** `Max` and
`Mod` were the evidence that the core's numeric set was arbitrary — `Min` and
`Abs` did not exist beside them. Asking *where they were used* settled it:
`Max` had **no call sites at all** (every mention in the compiler was a
comment), and Turbo Pascal never had either as a function. `Max` was removed in
Generation 9 [RT-010].

**`Mod` is gone too, and neither did it move here.** Turbo Pascal has `mod` as
an OPERATOR, `a mod b`, beside `a div b` — so the capability was always
Pascal's and only the spelling as a function was not. It became the `mod`
operator [EXP-021] and the built-in was removed [RT-011], which is a language
change and not a library one; `math` never sees it. The emitter's hex mangling,
the one call site, now reads `Left mod 16`.

The seam this question found therefore closed from the language's side. `math`
is left holding `Abs`, `Min` and the rest — the things Turbo Pascal really did
spell as functions — and nothing that is an operator anywhere else.

**Q6 (original) — the core's numeric set is arbitrary, and `math` makes that visible.**
`Max` [RT-010] and `Mod` [RT-011] are built-ins; `Min` and `Abs` do not exist at
all:

```
WriteLn (Max (3, 7));    →  7
WriteLn (Mod (7, 3));    →  1
WriteLn (Min (3, 7));    →  Undefined variable 'Min'.
WriteLn (Abs (-3));      →  Undefined variable 'Abs'.
```

Putting `Abs` in `math` therefore leaves a program taking `Abs` from a unit and
`Max` from nowhere — two spellings of the same kind of thing, decided by an
accident of which built-ins were needed while the compiler was being written.

The tidy end state is that `Max` and `Mod` follow `Abs` into `math` and leave
the core, which is the same direction Annex E and H-9 already travel. ⚠️ **But
that is a language change, not a library one** — it removes built-ins, changes
Annex B and breaks every program that uses them unqualified, so it belongs to a
generation rather than to this survey. Recorded here because `math` is where the
seam shows.

*(Both left the core in the end, and neither arrived here: `Max` was removed
outright and `Mod` became an operator. See the answer above.)*

**Q5 — ANSWERED: `graph` carries drawing state**, settled by the Graph list
asking for `SetColor`, `SetBkColor`, `SetFillStyle`, `SetLineStyle`,
`SetWriteMode`, `MoveTo` and `SetViewPort` with their `Get` counterparts. See
§4.7. The five questions the same list opened are recorded there as O1–O5,
beside the routines they concern.

**Q3 — `Buffer.PutPointer` yes; `GetPointer` undecided.** Building a C array of
pointers needs only the write half, and a written pointer can only be one that
already existed. `GetPointer` reads a pointer *out* of memory the program can
also write byte by byte, so it lets a program conjure an address — the first
thing that would break "every `Pointer` came from C". It is what opens FreeType
and Core Text; `Addr`'s verdict above argues for containment, so the two pull
against each other and the answer should come from the whole survey.

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
