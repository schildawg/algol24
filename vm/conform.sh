#!/bin/sh
# vm/conform.sh -- runs the conformance corpus on the bytecode machine.
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
#   DIVERGED          the machine ran it and got something else
#
# A refusal is work still to do.  A divergence is a bug, and the reason the
# emitter refuses by name rather than emitting nothing: a silent gap would
# show up here as a divergence in a case that looks unrelated.
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

PASS=0; REFUSED=0; DIVERGED=0
: > "$WORK/diverged"

for src in conformance/*.a24; do
    expected="${src%.a24}.out"
    [ -f "$expected" ] || continue

    status=0
    "$WORK/algvm" "$src" > "$WORK/raw" 2>&1 || status=$?
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
echo "DIVERGED              : $DIVERGED"

if [ "$DIVERGED" -gt 0 ]; then
    echo
    echo "diverging cases:"
    sed 's/^/  /' "$WORK/diverged"
    exit 1
fi

echo
echo "OK: every case the machine runs, it runs as the corpus records it."
