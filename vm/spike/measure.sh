#!/bin/sh
# Reproduces every number in PROPOSAL-VM.md's measurement tables.
#
# Run from the repository root, with bootstrap/algc already built:
#
#     ./bootstrap/build.sh && vm/spike/measure.sh
#
# Needs a C compiler for every row, and python3 for the two CPython rows, for
# generating the annotation variants, and for cdispatch.py. Each figure is the
# median of five runs, and every row is sized to take at least a second -- an
# earlier draft had rows finishing in six milliseconds, which measured the
# scheduler.
#
# WORK=/some/dir keeps the generated sources and binaries for inspection.
set -e

CC="${CC:-cc}"
CFLAGS="${CFLAGS:--std=c11 -O2}"
ALGC="${ALGC:-bootstrap/algc}"
WORK="${WORK:-$(mktemp -d)}"

[ -x "$ALGC" ] || { echo "no $ALGC -- run ./bootstrap/build.sh first" >&2; exit 1; }

median () { sort -n | awk '{ a[NR] = $1 } END { print a[int((NR + 1) / 2)] }'; }

# Five runs of a spike binary, reporting the median of the rate it prints.
rate () {
    i=0
    while [ "$i" -lt 5 ]; do
        "$1" | sed -n '2p' | awk '{ print $1 }'
        i=$((i + 1))
    done | median
}

# --- the Algol-24 variants ------------------------------------------------
#
# "untyped" removes every written type from a declaration, which is what
# eliding alg_widen where it is provably the identity would amount to.
# "nocast" additionally removes `as Integer` from the dispatch loop, which is
# what resolving a cast at emit time would amount to.
python3 - "$WORK" <<'PYEOF'
import pathlib, re, sys

work = pathlib.Path(sys.argv[1])

def untype(source):
    source = re.sub(r'(\bvar\s+\w+)\s*:\s*\w+\s*:=', r'\1 :=', source)
    return re.sub(r'^(\s+)(\w+)\s*:\s*(Integer|Double|Boolean|String|Buffer);\s*$',
                  r'\1\2;', source, flags=re.M)

aot = pathlib.Path('vm/spike/direct.a24').read_text()
vm  = pathlib.Path('vm/spike/vmtable.a24').read_text()

aot = aot.replace('ITERATIONS := 1000000', 'ITERATIONS := 300000000')
vm  = vm.replace('ITERATIONS := 1000000',  'ITERATIONS := 30000000')

(work / 'aot-typed.a24').write_text(aot)
(work / 'aot-untyped.a24').write_text(untype(aot))
(work / 'vm-typed.a24').write_text(vm)
(work / 'vm-untyped.a24').write_text(untype(vm))
(work / 'vm-nocast.a24').write_text(untype(vm).replace(' as Integer;', ';'))

# the two `case`-dispatch spikes, for the arm-position penalty
for name in ('vm', 'vm60'):
    source = pathlib.Path('vm/spike/%s.a24' % name).read_text()
    (work / ('case-%s.a24' % name)).write_text(
        source.replace('ITERATIONS := 1000000', 'ITERATIONS := 10000000'))
PYEOF

printf '%-34s %10s %10s\n' 'variant' '-O2' '-O2 -flto'
printf '%-34s %10s %10s\n' '---' '---' '---'

for variant in aot-typed aot-untyped vm-typed vm-untyped vm-nocast case-vm case-vm60; do
    mkdir -p "$WORK/$variant.d"
    "$ALGC" --compile --out="$WORK/$variant.d" "$WORK/$variant.a24"

    $CC $CFLAGS        -o "$WORK/$variant.o2"  "$WORK/$variant.d"/*.c
    plain=$(rate "$WORK/$variant.o2")

    if $CC $CFLAGS -flto -o "$WORK/$variant.lto" "$WORK/$variant.d"/*.c 2>/dev/null; then
        linked=$(rate "$WORK/$variant.lto")
    else
        linked='n/a'
    fi

    printf '%-34s %10s %10s\n' "$variant" "$plain" "$linked"

    # The same handlers under a hand-written C dispatch loop. Only the three
    # vmtable rows have a loop to replace.
    case $variant in
    vm-*)
        c="$variant-cdispatch"
        cp -R "$WORK/$variant.d" "$WORK/$c.d"
        python3 vm/spike/cdispatch.py "$WORK/$c.d" --dispatch

        $CC $CFLAGS        -o "$WORK/$c.o2"  "$WORK/$c.d"/*.c
        plain=$(rate "$WORK/$c.o2")

        if $CC $CFLAGS -flto -o "$WORK/$c.lto" "$WORK/$c.d"/*.c 2>/dev/null; then
            linked=$(rate "$WORK/$c.lto")
        else
            linked='n/a'
        fi

        printf '%-34s %10s %10s\n' "$c" "$plain" "$linked"
        ;;
    esac
done

# --- the C dispatch is equivalent, not merely faster ----------------------
#
# A thousand iterations of each form, reporting the VM's final state, because
# the rate the spikes print is derived from ITERATIONS rather than counted.
echo
sed 's/ITERATIONS := 30000000/ITERATIONS := 1000/' "$WORK/vm-typed.a24" \
    > "$WORK/verify.a24"

for form in emitted cdispatch; do
    d="$WORK/verify-$form.d"
    mkdir -p "$d"
    "$ALGC" --compile --out="$d" "$WORK/verify.a24"

    if [ "$form" = cdispatch ]; then
        python3 vm/spike/cdispatch.py "$d" --dispatch --probe
    else
        python3 vm/spike/cdispatch.py "$d" --probe
    fi

    $CC $CFLAGS -o "$WORK/verify-$form" "$d"/*.c
    printf '%-34s %s\n' "final state, $form dispatch" \
        "$("$WORK/verify-$form" 2>&1 >/dev/null)"
done

# --- the outside reference points -----------------------------------------
echo
for reference in cdirect cvm; do
    $CC $CFLAGS -o "$WORK/$reference" "vm/spike/$reference.c"
    printf '%-34s %10s\n' "$reference (C)" "$(rate "$WORK/$reference")"
done
printf '%-34s %10s\n' 'loop.py (CPython)' \
    "$(i=0; while [ $i -lt 5 ]; do python3 vm/spike/loop.py | sed -n '2p' | awk '{ print $1 }'; i=$((i + 1)); done | median)"

echo
python3 vm/spike/disasm.py | tail -1
