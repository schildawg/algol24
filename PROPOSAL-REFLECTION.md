# Proposal: a class, readable at run time

**Status:** the LANGUAGE's half is built and shipped in v0.3.1, with v0.3.2 fixing
three defects the library found in it. The library's half has been **started**:
`algol24-library` 0.2.0 ships a `reflect` unit — `Describe` and `Compare`, two
extensions over `Fields`, `TypeOf` and `Member` that work on any value — and
`testing` has not adopted it, so the asserting half of what this proposed is
still unwritten and this stays in the root. Written 2026-11-12.

**From:** `algol24-library`'s own `PROPOSAL-REFLECTION.md`, which asked for a
read-only field list — and from the author, who has a project in view that
needs considerably more than that.

**Concerns:** what a class can be asked about itself. Fields, methods, types as
values, and calling a method by a name held in a variable.

---

## Summary

A class is **already a value** in this language, and that is the thing to build
on rather than around:

```algol24
var T := Dog;
WriteLn (T = Dog);        // true -- compared by identity
WriteLn (T () is Dog);    // true -- and callable
WriteLn (T.ClassName);    // Uncaught: Only instances have properties.
```

It can be held, compared and called, and it can answer **nothing about
itself**. This proposes that it can.

| | |
| --- | --- |
| `Fields (X)` | the fields a value's class declares, with their declared types |
| a class's methods | names, arities, parameter types, and which are properties |
| a type as a value | what `TypeOf` answers, and what a class name already is |
| calling by name | invoking a method whose name is in a variable |

---

## The demand, and which half of it is measured

⚠️ **TWO HALVES, AND ONLY ONE IS MEASURED. Saying so is the point**, because
this project's policy is that the language changes on measured demand with the
measurement in the proposal — and dressing anticipation as measurement would
spend that policy's credibility to save a sentence.

**Measured.** `algol24-library` wrote the originating proposal out of three
things in its own source, none hypothetical: an instance has no useful
diagnostic (`Str (P)` is `Prop instance`), deep equality is hand-written per
class, and the concurrency report's copy protocol has no way to serialize an
arbitrary value. Each has a workaround; what the three share is that the
workaround is **per class and goes stale silently when a field is added**.

**Anticipatory.** The full surface here — types as values, method listing,
calling by name — is not drawn from a program that exists. It is drawn from one
the author intends to write and has judged will need it. That is a weaker
warrant than the library's three, and it is the reason this document exists
rather than a plan: it is asking for a decision, not recording one.

⚠️ **IT REVERSES THE ORIGINAL PROPOSAL'S OWN BOUNDARY, in two places.** The
library wrote that setting by computed name, invoking methods by name and
building classes at run time are *"where a statically-checked language stops
being checkable"*, and excluded them deliberately. Two of those three are
proposed here. The reversal is not an oversight and the argument is that the
premise does not hold for this language:

- Overload selection is **already at run time** [EXP-013], because the type
  system is gradual and an argument's declared type may be `Any`.
- `alg_invoke` **already dispatches by name** at run time, and is how every
  method call in the compiled back end works.

So a call by a computed name reaches the same machinery a written one does. It
is not a hole cut in a static guarantee; it is a name the program supplies
later. What this proposal still does **not** ask for is building or altering a
class at run time, which is where the library's sentence does hold.

---

## What the three processors already hold

The grounding for every cost claim below. Read before estimating anything.

| | fields | field types | methods | method types |
| --- | --- | --- | --- | --- |
| tree walker | AST nodes, in declaration order | **already there** | a Map of AST | **already there** |
| C back end | `const char **fields` | missing | `MethodEntry` | **already there** |
| machine | `Fields : List` of folded keys | missing | `Methods : Map` | — |

⚠️ **THE RUNTIME KNOWS MORE ABOUT METHODS THAN ABOUT FIELDS, which is the
opposite of the natural guess** and it reverses the cost of the two halves.
`MethodEntry` already carries a name, an arity, the parameter types **and** an
`is_property` flag; `alg_class_method` has taken `const char **types` all
along. A field is `alg_class_field (klass, name)` and nothing else.

So **listing methods is nearly free**, and **field types are the new work** —
in the two compiled processors only, since the tree walker holds `VarStmt` and
`VarStmt` carries `TypeName`.

⚠️ **`private` IS COMPILE-TIME ONLY, and that decides a question the original
proposal called its hardest.** `grep private bootstrap/algol.c` answers
nothing: the runtime cannot tell a private field from a public one, because
`private` is `CEmitter.VisibleFields` and, in the emitted C, `static`. So
*including* private fields costs nothing and *hiding* them would mean a new bit
in the field table of all three processors. Decided: they appear.

⚠️ **The original proposal cites [MOD-006] for that question and the rule is
[DCL-011].** [MOD-006] is `private` on a module's top-level declaration;
visibility sections inside a class are [DCL-011]. A citation is a pointer to
check.

---

## What is proposed

### A field list

```
Fields (X) : List
```

A built-in rather than a member of every instance, for a reason the shape of
the language settles: a member would put the name on every instance, and
[EXP-022] makes a member win at a call — so a class declaring its own `Fields`
would be shadowed by the runtime's, silently.

⚠️ **THE SUGAR IS THE LIBRARY'S, AS AN EXTENSION, and that is the better
spelling.** An extension function has exactly the right precedence and the
language says so out loud. Measured under all three processors:

```
[WARN] 'Described' is a member of Own, so the extension of that name is
       not reached.
the class's own        <- a class's own member wins [EXP-022]
the extension          <- and the extension answers where there is none
```

A receiver written `Any` is legal and reaches an instance, an Integer and a
String alike, and both spellings — `P.Described ()` and `Described (P)` — are
one call [FUN-016]. So the core ships the primitive and the library ships the
reading, which is this project's usual division and keeps the name out of every
program: an extension's visibility is the file's own `uses` [MOD-015].

**Decided, each with its reason:**

| | | |
| --- | --- | --- |
| private fields | **in** | the runtime cannot tell; hiding them is new machinery |
| properties | **out** | a serializer must not write one — there is nothing to write back into. `is_property` already distinguishes them, so this is free |
| inherited fields | **in**, parent-first | [CLS-011] gives a subclass the parent's fields and `ObjClass.total_fields` already counts the whole chain; parent-first matches how initializers are seeded [CLS-005] |
| order | declaration order | the useful answer for a serializer, because it makes a written record reproducible. The tree walker already keeps it — *"Declared field names, in the order written"* |

### Methods

Names, arities, parameter types and the property flag — all of which
`MethodEntry` already carries. ⚠️ **A NAME IS NOT ONE METHOD**: two methods of
a name are an overload set [FUN-013], so the answer is a list of entries rather
than a list of names.

### A type as a value

A class name already is one. What it lacks is a surface to ask, and `TypeOf`
to reach the types that are not classes — an Integer, a String, a List — since
today **only instances can be asked**:

| | |
| --- | --- |
| `instance.ClassName` | `Prop` |
| `(42).ClassName` | `Undefined property 'ClassName'.` |
| `[1, 2].ClassName` | `Undefined property 'ClassName'.` |

### Calling by name

`alg_invoke` is the existing machinery and needs no new path. What needs
deciding is the spelling and what happens when the name is not a member.

### Construction and writing, which the library asked about

A generic **serializer** needs the field list. A generic **deserializer** needs
to make an instance and fill it, and ⚠️ **CONSTRUCTION ALONE DOES NOT CLOSE
THAT GAP**: unless a class has a constructor taking every field, a deserializer
must also write a field by name. Both halves already exist in the runtime and
neither is reachable from the language — `alg_new` and `alg_set_property`.

⚠️ **A BY-NAME WRITE HONOURS THE DECLARED TYPE, which this proposal is what
makes possible.** A written field assignment is an assignment context and
widens [VAL-001]; a by-name write must do the same or it becomes the one way to
put an Integer where a class promised a String. The field table now carries the
declared type, so the check has something to check against — reflection makes
its own write path safe rather than cutting a hole beside it.

### Private members: visible, callable, and that is a decision

⚠️ **`private` IS A COMPILE-TIME CONVENTION AND NOT A RUN-TIME BOUNDARY**, and
after this proposal it is plainly so. `S.Secret ()` is refused before the
program runs, and `grep private bootstrap/algol.c` answers nothing — so a
by-name call reaches a private method, a by-name read reaches a private field,
and neither costs anything because the runtime never knew. Refusing them would
mean a new bit in the method table of all three processors.

So **reflection can do what written code cannot**: read private state, call a
private method, write a field the class exposes no setter for. That is a
trapdoor, it is deliberate, and it is written here so that nobody meets it by
surprise. The guard that remains is `uses`: the sugar is an extension, so a
file that does not import it has none of this [MOD-015].

### A by-name call does not reach a property

A property computes on read, so reading and calling are two operations and
`MethodEntry.is_property` already tells them apart at no cost. A by-name READ
reaches a property; a by-name CALL does not. A generic writer must not be able
to "call" something there is nothing to write back through.

### What a wrong arity answers

⚠️ **A METHOD'S WRONG ARITY NAMES NEITHER THE MEMBER NOR THE COUNTS, where a
subprogram's and a constructor's name both.** Measured:

```
method:      No matching signature for function.
subprogram:  Expected 2 arguments but got 1.
constructor: Expected 0 arguments but got 1.
```

A by-name call goes through the method path, so for generic code that sentence
is the entire debugging experience — and it does not say which call failed.
[0049] pins the split deliberately, because an overloaded name has no single
*expected N*. That reason does not reach the case above, which has exactly one
candidate.

**Proposed:** name the member and its class always, and the counts where there
is one candidate. This changes `conformance/0049`, which compares all five
reports, so it is a change to argue there rather than slip in.

### `is` and `as` are NOT extended

⚠️ **A TYPE HELD IN A VARIABLE DOES NOT GO INTO `is`, and the price of doing
so is already measured.** v0.2.5 resolved `is`/`as` against a **written** name
at emit time — `ResolvedKind` for the built-in types, `ResolvedClass` for a
class handle — worth **11% on `Fib (27)`** and **10% on the Dew Drop Inn**.
Accepting a runtime value there would need a second path beside that or give
the optimization back. The dynamic question gets a spelling of its own instead,
and `is` keeps meaning what it means.

---

## How the open questions were answered

1. **Declared type.** [RT-031] reports what the program wrote, `''` where
   nothing was, so a field's entry never reports the checker's working state.
2. **A type value is an interned synthetic class** [RT-032], carrying the
   type's name and marked so that constructing one is refused rather than
   answering an `Integer instance`.
3. **`T.Accepts (X)`** [RT-035], a member of the class surface rather than a
   built-in — which is what the surface being a member *list* makes possible.
   It answers through whatever already answers `is` in each processor, so the
   written form keeps its emit-time resolution and the two cannot drift.
4. **The same diagnostic the written form gives**, which turned out to be two
   diagnostics rather than one: a name no class in the chain declares is
   `Undefined property`, and a name that *is* declared and fits nothing is a
   selection failure. The interpreter answered the first for both and was the
   odd one out of the three.

   And the selection failure itself **named nothing at all**, which was the
   library's actual complaint. It is now
   `No matching signature for <what was called>.` — a subprogram or a class by
   its own name, a method as `Class.Member` — and **where the name is
   unambiguous the counts are reported instead**, which removes the asymmetry
   [0049] used to pin: a method answered a selection failure for a wrong count
   where a subprogram and a constructor reported the counts, so one fault read
   two ways.

   ⚠️ **A built-in sharing the name makes the count ambiguous**, however few
   declarations there are. One `Length (A, B)` beside the built-in answers both
   1 and 2 arguments [RT-027], so reporting `Expected 2 arguments but got 3.`
   would name a count as the only one accepted while `Length ('abc')` plainly
   works. `ObjOverloads.Fallback` being non-nil is what withholds the counts.

   ⚠️ **A CONSTRUCTOR names the class alone.** `Init` is not a name a call site
   writes — a construction is `C (...)` — so `C.Init` would name something the
   program never said. The compiled back end answered `Holder.Init` from one of
   the several routes into a constructor's selection while the other two
   answered `Holder`, which is why the rule lives in the reporter rather than
   at the call sites.

   ⚠️ **The machine must count a class's OWN constructors, not the chain's.**
   The emitter gives a class with none a synthesized arity-0 `Init`, and a
   subclass declaring none a forwarder *per inherited signature* — so the chain
   holds the same signatures twice and `AlsoBare (Bare)` looked like two
   candidates. A method wants the chain; a constructor does not.
5. **A packed constant**, as `OP_INVOKE_NAMED` already packs two names.
6. Still open, and it is what the library work after this release will decide.

## What writing by name turned up

Three defects, none of them in the new feature, found by giving an old fault a
second way in:

- **A raise inside a nested run left the machine's saved state unrestored.**
  `CallNested` set `StopDepth` and restored it only on the way out, so a
  selection failure or a property guard skipped the restore entirely. The
  program then gave every right answer and died at its **last statement** with
  `Index -1 out of range` — `FrameOf[-1]`, because the floor test
  `FrameDepth = StopDepth` compared 0 against the stale 1. Pre-existing for
  `Invoke`'s whole life; `New` reached it the same way.
- **`on E : Any` matches nothing**, which is how the first fix for that failed
  silently. `Any` is the absence of a written type rather than a type a value
  can be tested against, so `X is Any` is false for everything and the arm
  never selects. `on E : String` is complete inside the machine: a host error
  is a String, and a guest raise nothing took arrives as `raise Str (Value)`.
  Both drivers still carry such an arm after an `on e : String` one; it is
  unreachable and harmless, since an uncaught non-String raise is already
  reported identically by all three processors.
- **`Only an instance has fields.`** was the machine's wording where the other
  two say `Only instances have fields.` — a 2-to-1 divergence no corpus case
  reached, latent for the machine's whole life because nothing wrote to a
  non-instance.

---

## Open questions

1. **Declared type or inferred type?** `VarStmt` carries both — `TypeName` is
   what was written, `''` where nothing was, and the TypeChecker fills a second
   field with what the initializer reduced to. A gradually typed language has
   many fields with no written type, so reporting only the declared one answers
   `''` often. Reporting the inferred one reports the checker's working state,
   which DEF-35 shows is incomplete above a declaration. **Leaning: the
   declared type**, because it is what the program promised and the other is an
   implementation's current opinion.
2. **What is a type value, exactly?** A class handle for a class; what for an
   Integer? A new object per built-in type, interned so identity compares, is
   the obvious answer and it is new machinery.
3. **The spelling of the dynamic type test.** `T.Accepts (X)` keeps `is`
   resolved at emit time and reads well. It is a second way to ask one thing.
4. **What a call by name does when the name is not a member.** The same
   `Undefined property` the written form gives, or an answer a caller can test?
5. **`OP_FIELD` carries one constant index**, and CLAUDE.md's invariant is **at
   most one widenable operand per opcode**. A type alongside the name wants
   either a packed constant — as `OP_INVOKE_NAMED` already packs two names —
   or a second non-widening operand.
6. **Does a serializer need the ENUM and SUBRANGE tables too?** Both are
   declared types a field can have, and neither is a class.

---

## What this does not ask for

- **Creating or altering a class at run time**, metaclasses, attribute hooks.
  The library's sentence holds here and this proposal keeps it.
- **Frames, stacks or source** — Python's `inspect`.
- **AST retention.** The data is distilled at build time, which the original
  proposal argued for and this one keeps: an AST held alive for the life of a
  program is thousands of nodes kept for a few dozen bytes of metadata, and
  the shadow stack's +5.8% is the nearest measured comparison for what a
  per-program cost looks like.
