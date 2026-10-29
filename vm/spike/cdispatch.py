# Rewrites a compiled vmtable variant so its dispatch loop is hand-written C
# over the SAME Algol-24 handlers, in place.
#
#     python3 vm/spike/cdispatch.py DIR [--dispatch] [--probe]
#
# --dispatch  replace the emitted `while Running` loop with the C form
# --probe     print the VM's final state to stderr when the loop ends
#
# The handlers, the opcode numbering and the VM's state are untouched: only
# the loop changes. --probe exists because the rate the spikes print is
# derived from ITERATIONS rather than counted, so a dispatch loop that exited
# early would report a FLATTERING figure. Comparing the final state of the two
# forms is what rules that out.
import pathlib
import sys

# vmtable.a24's own numbering: HALT 0, PUSHI 1, POP 2, DECJNZ 3.
LOOP = '''    unsigned char prog[16];
    for (int i = 0; i < 6; i++)
        prog[i] = (unsigned char)alg_subscript_get(v_code, alg_int(i)).integer;

    while (v_running.boolean) {
        int64_t op = prog[v_ip.integer];
        v_ip.integer = v_ip.integer + 1;
        switch (op) {
            case 0: f_dohalt(NULL, NULL, 0);   break;
            case 1: f_dopushi(NULL, NULL, 0);  break;
            case 2: f_dopop(NULL, NULL, 0);    break;
            case 3: f_dodecjnz(NULL, NULL, 0); break;
            default: alg_error("unknown opcode");
        }
    }
'''

PROBE = ('    fprintf(stderr, "ip=%lld sp=%lld stack0=%lld running=%d\\n",'
         ' (long long)v_ip.integer, (long long)v_sp.integer,'
         ' (long long)alg_subscript_get(v_stack, alg_int(0)).integer,'
         ' (int)v_running.boolean);\n')

emitted = pathlib.Path(sys.argv[1])
flags = sys.argv[2:]

unit = next(f for f in emitted.glob('*.c') if f.name != 'algol.c')
source = unit.read_text()

if '--dispatch' in flags:
    lines = source.split('\n')
    at = next(n for n, line in enumerate(lines)
              if 'while (alg_truthy((alg_declared(d_running' in line)

    # the emitted loop is eight lines: the test, a block brace, the opcode
    # fetch, its (void) cast, the IP advance, the handler call, and two braces
    if lines[at + 7].strip() != '}':
        raise SystemExit('unexpected dispatch loop shape: %r' % lines[at:at + 9])

    source = '\n'.join(lines[:at]) + '\n' + LOOP + '\n'.join(lines[at + 8:])

if '--probe' in flags:
    at = source.index('    v_elapsed = ')
    source = '#include <stdio.h>\n' + source[:at] + PROBE + source[at:]

unit.write_text(source)
