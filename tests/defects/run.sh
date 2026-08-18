#!/usr/bin/env bash
#
# Runs every reproduction in this directory and reports which ones still fail.
#
# ⚠️ This script does not fail when a test fails -- that is the normal state
# here, and an exit code that tracked it would be red on every run and tell
# nobody anything.  It exits non-zero only when a reproduction PASSES, because
# that is the event worth acting on: the defect is fixed and the file should
# move to a real suite.  That inversion is why this directory is not in
# test.sh's SUITES array and must not be added to it.
#
set -uo pipefail

ROOT=$(cd "$(dirname "$0")/../.." && pwd)
HERE=$ROOT/tests/defects
ALGC=${ALGC:-$ROOT/algc}

if [ ! -x "$ALGC" ]; then
    echo "no compiler at $ALGC -- run ./build.sh first" >&2
    exit 1
fi

fixed=0
failing=0

for source in "$HERE"/*.a24; do
    name=$(basename "$source" .a24)
    output=$("$ALGC" --test "$source" 2>&1)
    status=$?

    if [ "$status" -eq 0 ]; then
        printf '%-26s PASSES -- defect appears fixed\n' "$name"
        fixed=$((fixed + 1))
    else
        # ⚠️ Prefer the [ERROR] line over the 'Uncaught:' one, even though the
        # 'Uncaught:' is printed FIRST.  A file whose tests ran ends with
        # 'Uncaught: Tests failed.', which is the same sentence whatever went
        # wrong; the [ERROR] beneath it is the one that names the defect.  Only
        # a file abandoned during checking, before any test ran, has no [ERROR]
        # at all -- and there the 'Uncaught:' is the whole answer.
        plain=$(printf '%s\n' "$output" | sed 's/\x1b\[[0-9;]*m//g')

        why=$(printf '%s\n' "$plain" | grep -m1 '^\[ERROR\]' \
              | sed -e 's/^\[ERROR\] [^:]*: //' -e 's/^Failed\.  //')

        if [ -z "$why" ]; then
            why=$(printf '%s\n' "$plain" | grep -m1 '^Uncaught:' \
                  | sed 's/^Uncaught: //')
            why="$why (abandoned during checking -- no test ran)"
        fi

        printf '%-26s fails    %s\n' "$name" "$why"
        failing=$((failing + 1))
    fi
done

echo
echo "$failing still failing, $fixed now passing"

[ "$fixed" -eq 0 ]
