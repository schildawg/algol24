/* A bytecode VM over the same three opcodes, written directly in C.
   The dispatch floor: what the loop in vmtable.a24 would cost if its
   interpreter loop were C rather than Algol-24 compiled to C. */
#include <stdio.h>
#include <stdint.h>
#include <time.h>

enum { OP_HALT, OP_PUSHI, OP_POP, OP_DECJNZ };

#define ITERATIONS 600000000

int main(void) {
    unsigned char code[8];
    int64_t operand[8], stack[64];
    int n = 0;

    code[n] = OP_PUSHI;  operand[n] = 1; n++;
    code[n] = OP_POP;    operand[n] = 0; n++;
    code[n] = OP_DECJNZ; operand[n] = 0; n++;
    code[n] = OP_HALT;   operand[n] = 0; n++;

    int64_t sp = 0, ip = 0, counter = ITERATIONS;
    struct timespec t0, t1;

    clock_gettime(CLOCK_MONOTONIC, &t0);
    for (;;) {
        switch (code[ip++]) {
            case OP_PUSHI:  stack[sp++] = operand[ip - 1]; break;
            case OP_POP:    sp--;                          break;
            case OP_DECJNZ: if (--counter != 0) ip = 0;    break;
            case OP_HALT:   goto done;
        }
    }
done:
    clock_gettime(CLOCK_MONOTONIC, &t1);

    double el = (t1.tv_sec - t0.tv_sec) + (t1.tv_nsec - t0.tv_nsec) / 1e9;

    printf("C VM:     %.0f instructions in %.3f s\n", ITERATIONS * 3.0, el);
    printf("          %.2f M instr/s\n", (ITERATIONS * 3.0) / el / 1e6);
    return 0;
}
