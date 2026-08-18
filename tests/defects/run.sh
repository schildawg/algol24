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
        # a file rejected before any test ran has no [ERROR] at all -- and there
        # the 'Uncaught:' is the whole answer.
        #
        # ⚠️ LC_ALL=C throughout, because a reproduction here may hold bytes that
        # are not valid text.  The scanner echoes the offending BYTE when it
        # refuses one, so a Unicode identifier makes this output ill-formed
        # UTF-8, and a locale-aware sed answers 'illegal byte sequence' and
        # drops the line -- the reason column came out empty, which reads as the
        # harness being broken rather than the defect being reproduced.  The
        # final substitution renders any such byte as '.' so the column stays
        # printable.
        plain=$(printf '%s\n' "$output" | LC_ALL=C sed 's/'$'\033''\[[0-9;]*m//g')

        why=$(printf '%s\n' "$plain" | LC_ALL=C grep -m1 '^\[ERROR\]' \
              | LC_ALL=C sed -e 's/^\[ERROR\] [^:]*: //' -e 's/^Failed\.  //')

        if [ -z "$why" ]; then
            why=$(printf '%s\n' "$plain" | LC_ALL=C grep -m1 '^Uncaught:' \
                  | LC_ALL=C sed 's/^Uncaught: //')
            why="$why (file rejected -- no test ran)"
        fi

        why=$(printf '%s' "$why" | LC_ALL=C sed 's/[^ -~]/./g')

        printf '%-26s fails    %s\n' "$name" "$why"
        failing=$((failing + 1))
    fi
done

echo
echo "$failing still failing, $fixed now passing"

[ "$fixed" -eq 0 ]
