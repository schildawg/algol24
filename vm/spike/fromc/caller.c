/* A hand-written C program that calls Algol-24 subprograms directly.
   This is the mechanism PROPOSAL-VM.md item 0b needs for a C dispatch loop,
   and it needs nothing from the language: Hot.h is generated, declares the
   unit's public subprograms with external linkage, and is included here.

   Link Hot.c and algol.c and NOT the generated Main.c -- that file has a main
   of its own, and this one is the program.  run.sh does it. */
#include <stdio.h>

/* ⚠️ The case matters.  An emitted file keeps its SOURCE's spelling -- Hot.h,
   not hot.h -- while the symbols inside it are lowercased by Annex G.3.  On a
   case-insensitive filesystem the wrong spelling compiles anyway and then
   fails on Linux. */
#include "Hot.h"

int main(void) {
    /* Every unit has one of these, and nothing in it is initialized until it
       runs.  A generated main calls them in dependency order; a hand-written
       one has to do the same. */
    init_Hot();

    Value argument = alg_int(21);
    printf("Twice(21)        = %lld\n",
           (long long)f_twice(NULL, &argument, 1).integer);

    argument = alg_int(100);
    printf("SumTo(100)       = %lld\n",
           (long long)f_sumto(NULL, &argument, 1).integer);

    /* The closure value works too, and goes through the same dispatch the
       interpreter uses -- slower, but it takes the subprogram as a VALUE,
       which is what a handler table holds. */
    printf("fn_twice(100)    = %lld\n",
           (long long)alg_call(fn_twice, &argument, 1).integer);

    return 0;
}
