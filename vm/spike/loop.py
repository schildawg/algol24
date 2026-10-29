# The same loop as direct.a24, in CPython, as an outside reference point.
# Three operations an iteration: a store, a subtraction and a comparison.
# CPython needs eleven bytecodes to do them -- see disasm.py.
import time

ITERATIONS = 30000000

i, x = ITERATIONS, 0
start = time.perf_counter()
while i != 0:
    x = 1
    i = i - 1
elapsed = time.perf_counter() - start

print("python:   %d operations in %.3f s" % (ITERATIONS * 3, elapsed))
print("          %.2f M op/s" % (ITERATIONS * 3 / elapsed / 1e6))
