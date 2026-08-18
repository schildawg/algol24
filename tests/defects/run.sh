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
# ⚠️ BOTH PROCESSORS, and a reproduction counts as reproduced if EITHER refuses
# it.  Most files here fail both ways, so running only the interpreter looks
# sufficient -- until a defect lives in the compiled half alone.
# EnumMemberSymbol is one: interpreted it passes, and compiled it silently
# computes a different answer.  With one processor this harness would have
# reported that file as a defect already fixed, which is the exact opposite of
# what it does.
#
set -uo pipefail

ROOT=$(cd "$(dirname "$0")/../.." && pwd)
HERE=$ROOT/tests/defects
ALGC=${ALGC:-$ROOT/algc}
RUNTIME=${RUNTIME:-$ROOT/bootstrap}
CC=${CC:-cc}

if [ ! -x "$ALGC" ]; then
    echo "no compiler at $ALGC -- run ./build.sh first" >&2
    exit 1
fi
if [ ! -f "$RUNTIME/algol.h" ]; then
    echo "no C runtime under '$RUNTIME'" >&2
    exit 1
fi

WORK=$(mktemp -d); trap 'rm -rf "$WORK"' EXIT

# The first line worth reporting out of a --test run.
#
# ⚠️ Prefer the [ERROR] line over the 'Uncaught:' one, even though the
# 'Uncaught:' is printed FIRST.  A file whose tests ran ends with 'Uncaught:
# Tests failed.', which is the same sentence whatever went wrong; the [ERROR]
# beneath it is the one that names the defect.  Only a file rejected before any
# test ran has no [ERROR] at all -- and there the 'Uncaught:' is the whole
# answer.
#
# ⚠️ LC_ALL=C throughout, because a reproduction here may hold bytes that are not
# valid text.  The scanner echoes the offending BYTE when it refuses one, so a
# Unicode identifier makes this output ill-formed UTF-8, and a locale-aware sed
# answers 'illegal byte sequence' and drops the line -- the reason column came
# out empty, which reads as the harness being broken rather than the defect
# being reproduced.  The last substitution renders any such byte as '.' so the
# column stays printable.
reason() {
    local plain why
    plain=$(printf '%s\n' "$1" | LC_ALL=C sed 's/'$'\033''\[[0-9;]*m//g')

    why=$(printf '%s\n' "$plain" | LC_ALL=C grep -m1 '^\[ERROR\]' \
          | LC_ALL=C sed -e 's/^\[ERROR\] [^:]*: //' -e 's/^Failed\.  //')

    # ⚠️ A COMPILED failure has neither line, and that is by design rather than
    # an oversight: an assertion prints a source caret when interpreted, and
    # compiled code carries no line information to print one from.  So the third
    # fallback reads the '[ FAIL ]' row itself and reports which test failed --
    # without it the reason column is empty for exactly the reproductions that
    # only the compiled half can show.
    if [ -z "$why" ]; then
        why=$(printf '%s\n' "$plain" | LC_ALL=C grep -m1 '^Uncaught:' \
              | LC_ALL=C sed 's/^Uncaught: //')
        [ -n "$why" ] && why="$why (file rejected -- no test ran)"
    fi

    if [ -z "$why" ]; then
        why=$(printf '%s\n' "$plain" | LC_ALL=C grep -m1 '\[ FAIL \]' \
              | LC_ALL=C sed -e 's/^\[INFO\] Test: //' -e 's/ *\.* *\[ FAIL \].*//')
        [ -n "$why" ] && why="test '$why' failed (no line -- compiled code has none)"
    fi

    [ -z "$why" ] && why="failed with no reportable line"

    printf '%s' "$why" | LC_ALL=C sed 's/[^ -~]/./g'
}

fixed=0
failing=0

for source in "$HERE"/*.a24; do
    name=$(basename "$source" .a24)

    interpreted=$("$ALGC" --test "$source" 2>&1); istat=$?

    out="$WORK/$name"; rm -rf "$out"; mkdir -p "$out"
    cp "$RUNTIME/algol.c" "$RUNTIME/algol.h" "$out/"

    if ! "$ALGC" --compile --test "--out=$out" "$source" >"$out/emit.log" 2>&1; then
        compiled=$(cat "$out/emit.log"); cstat=70
    elif ! ( cd "$out" && $CC -std=c11 -O0 -o run ./*.c ) 2>"$out/cc.log"; then
        compiled="Uncaught: cc rejected the emitted C: $(LC_ALL=C grep -m1 'error:' "$out/cc.log" | LC_ALL=C sed 's|.*error: ||')"
        cstat=70
    else
        compiled=$("$out/run" 2>&1); cstat=$?
    fi

    if [ "$istat" -eq 0 ] && [ "$cstat" -eq 0 ]; then
        printf '%-26s PASSES -- defect appears fixed\n' "$name"
        fixed=$((fixed + 1))
    elif [ "$istat" -ne 0 ]; then
        printf '%-26s fails    %s\n' "$name" "$(reason "$interpreted")"
        failing=$((failing + 1))
    else
        printf '%-26s fails    compiled only: %s\n' "$name" "$(reason "$compiled")"
        failing=$((failing + 1))
    fi
done

echo
echo "$failing still failing, $fixed now passing"

[ "$fixed" -eq 0 ]
