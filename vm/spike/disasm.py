# How many bytecodes CPython needs for one iteration of loop.py's body.
#
# The steady-state loop runs from JUMP_BACKWARD's target to the JUMP_BACKWARD
# itself, so the count is read off the jump rather than eyeballed: eleven on
# CPython 3.12, against three instructions for the same work in vmtable.a24.
import dis
import sys


def loop():
    i, x = 30000000, 0
    while i != 0:
        x = 1
        i = i - 1


instructions = list(dis.get_instructions(loop))

back = next(i for i in instructions if i.opname == 'JUMP_BACKWARD')
body = [i for i in instructions if back.argval <= i.offset <= back.offset]

for instruction in instructions:
    marker = '>' if instruction in body else ' '
    print('%s %-4s %-22s %s' % (marker, instruction.offset, instruction.opname,
                                instruction.argrepr))

print()
print('%d bytecodes per iteration (CPython %s)'
      % (len(body), '.'.join(str(n) for n in sys.version_info[:2])))
