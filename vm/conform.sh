#!/bin/sh
# vm/conform.sh -- runs the conformance AND refusal corpora on the bytecode
# machine.
#
#     ./bootstrap/build.sh && vm/conform.sh
#
# The third column PROPOSAL-VM.md item 5 asks for.  Output is rendered exactly
# as conform.sh renders it -- ANSI stripped, [WARN] lines dropped from both
# sides, the exit status appended -- so a case comparing equal here is
# comparing equal by the same rule the other two processors are held to.
#
# Three outcomes, and only the third is a failure:
#
#   identical         the machine agrees with the recorded expectation
#   refused by name   an opcode does not exist yet, and the emitter said so
#   not applicable    the case asks to be run some other way, and the machine
#                     has no such mode.  '--test' USED to be the common one and
#                     no longer is: the machine runs test blocks now.
#   DIVERGED          the machine ran it and got something else
#
# A refusal is work still to do.  A divergence is a bug, and the reason the
# emitter refuses by name rather than emitting nothing: a silent gap would
# show up here as a divergence in a case that looks unrelated.
#
# ⚠️ BOTH CORPORA, and for a while it was only the first.  A refusals/ case is
# a program that must FAIL with a particular diagnostic, which is exactly what
# a back end gets wrong quietly -- and walking only conformance/ hid
# refusals/0042 for the whole life of the machine: a lone subprogram's declared
# parameter type was never checked, so `G ('a string')` where G takes an
# Integer ran and printed the string.  It stayed hidden because the emitter's
# refuse-by-name policy answered most refusal cases with a refusal, so the hole
# only began to matter once the machine started emitting run-time diagnostics
# instead.
set -eu

CC="${CC:-cc}"
CFLAGS="${CFLAGS:--std=c11 -O2}"
ALGC="${ALGC:-bootstrap/algc}"
WORK="${WORK:-$(mktemp -d)}"

[ -x "$ALGC" ] || { echo "no $ALGC -- run ./bootstrap/build.sh first" >&2; exit 1; }

ESC=$(printf '\033')
BEL=$(printf '\007')

# conform.sh's own rendering, kept identical on purpose.
render() {
    sed -e "s/${ESC}\[[0-9;]*m//g" \
      | { grep -av '^\[WARN\]' || true; } \
      | tr '\000' "$BEL" | sed "s/${BEL}/^@/g"
}

mkdir -p "$WORK/out"
"$ALGC" --compile --out="$WORK/out" vm/run.a24 > "$WORK/emit.log" 2>&1 \
    || { cat "$WORK/emit.log"; exit 1; }

# shellcheck disable=SC2086
$CC $CFLAGS -o "$WORK/algvm" "$WORK/out"/*.c

PASS=0; REFUSED=0; DIVERGED=0; SKIPPED=0
: > "$WORK/diverged"

for src in conformance/*.a24 refusals/*.a24; do
    [ -f "$src" ] || continue

    # conformance/ records what a program PRINTS and refusals/ what it is
    # refused with, under different extensions; the comparison is the same.
    expected="${src%.a24}.out"
    [ -f "$expected" ] || expected="${src%.a24}.expected"
    [ -f "$expected" ] || continue

    # A case may ask to be run differently -- a .args file or a '// run:'
    # line -- and conform.sh honours that.  '--test' is the common one, and
    # the machine has no test runner, so such a case is not applicable rather
    # than diverging: its recorded output is of a run this cannot perform.
    wants=""
    [ -f "${src%.a24}.args" ] && wants=$(cat "${src%.a24}.args")
    [ -n "$wants" ] || wants=$(sed -n 's|^// run: ||p' "$src" | head -1)

    # '--test' is one the machine CAN now be asked, so it is run rather than
    # skipped: the seven cases that ask for it are the ones that pin the report
    # itself -- collection order, the dot leader, the assertion messages -- and
    # skipping them left the format unchecked on this processor.
    if [ -n "$wants" ] && [ "$wants" != "--test" ]; then
        SKIPPED=$((SKIPPED + 1))
        continue
    fi

    status=0
    if [ "$wants" = "--test" ]; then
        "$WORK/algvm" --test "$src" > "$WORK/raw" 2>&1 || status=$?
    else
        "$WORK/algvm" "$src" > "$WORK/raw" 2>&1 || status=$?
    fi
    { render < "$WORK/raw"; echo "exit: $status"; } > "$WORK/got"

    if grep -q 'is not supported by the bytecode back end yet' "$WORK/raw"; then
        REFUSED=$((REFUSED + 1))
        continue
    fi

    if cmp -s "$WORK/got" "$expected"; then
        PASS=$((PASS + 1))
    else
        DIVERGED=$((DIVERGED + 1))
        basename "$src" .a24 >> "$WORK/diverged"
    fi
done

echo "identical to expected : $PASS"
echo "refused by name       : $REFUSED"
echo "not applicable        : $SKIPPED"
echo "DIVERGED              : $DIVERGED"

if [ "$DIVERGED" -gt 0 ]; then
    echo
    echo "diverging cases:"
    sed 's/^/  /' "$WORK/diverged"
    exit 1
fi

echo
echo "OK: every case the machine runs, it runs as the corpus records it."
