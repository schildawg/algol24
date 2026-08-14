# vm — the bytecode VM

Empty on purpose. This is where project 3 goes: a bytecode virtual machine
**written in Algol-24 and compiled to native**, modelled on *Crafting
Interpreters* Part II.

## Why it is not here yet

The compiler in `compiler/` is a tree-walker, and a tree-walker pays most of its
cost in call overhead. Compiled to C it is already fast enough that nothing in
this repository is waiting on it — which is exactly why the VM is deferred. It
will be a better project once there are real programs to make faster, and a
profile to point at.

## What it will be able to assume

- A self-hosting compiler, so the VM can be written in the language it runs.
- A verified fixed point, so a change to the compiler is provably not a change
  to what it emits.
- `Obj*` naming shared by all three layers — `ObjClass`, `ObjInstance`,
  `ObjSeq` — chosen so the runtime, the compiler and the VM say the same word
  for the same thing.

## The known first question

Dispatch. 93% of calls in compiled output go through `alg_invoke`, a lookup by
method **name** at run time, and that is the cost a VM is actually for. It is
name-based because in a gradually typed language the emitter frequently does not
know a receiver's type — so the VM's answer has to survive that, not assume it
away.
