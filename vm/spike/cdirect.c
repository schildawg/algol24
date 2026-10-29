/* The same loop as direct.a24, written directly in C, as the ceiling.
   The barriers are load-bearing: without them the optimiser deletes the
   loop outright and the program reports an infinite rate. */
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define ITERATIONS 3000000000
#define BARRIER(v) __asm__ __volatile__("" : "+r"(v))

int main(void) {
    int64_t i = ITERATIONS, x = 0;
    struct timespec t0, t1;

    clock_gettime(CLOCK_MONOTONIC, &t0);
    while (i != 0) {
        x = 1;      BARRIER(x);
        i = i - 1;  BARRIER(i);
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);

    double el = (t1.tv_sec - t0.tv_sec) + (t1.tv_nsec - t0.tv_nsec) / 1e9;

    printf("direct C: %.0f operations in %.3f s\n", ITERATIONS * 3.0, el);
    printf("          %.2f M op/s\n", (ITERATIONS * 3.0) / el / 1e6);
    return 0;
}
