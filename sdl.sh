#!/usr/bin/env bash
#
# Runs an Algol-24 program in an SDL-enabled build -- interpreted, then
# compiled -- and requires the two to agree.
#
# ⚠️ NOT part of test.sh, and it must not be added to it.  Everything test.sh
# runs must pass for someone who has only a C compiler, which is the promise
# the -DALG_SDL guard exists to keep.  This is the opt-in harness for the one
# capability that guard hides, in the same relationship collide.sh and depth.sh
# have to the pinned suites: run by hand, when the thing it covers changed.
#
# ⚠️ It exists because the invocation is a trap, not because it is long.  Three
# separate mistakes are baked out of it:
#
#   * -I must be ABSOLUTE.  compile.sh and test.sh cd into the output directory
#     before calling cc, so a relative -Ithird_party resolves against the wrong
#     place and fails with 'stb_image.h file not found' -- pointing at the one
#     file the reader just added, which reads as the vendoring having failed.
#
#   * compile.sh has NO --test flag and does not reject one.  It emits the
#     program instead of its tests, and a file that is all test blocks then
#     runs, prints nothing, and exits 0.  A green run that tested nothing.
#
#   * SDL_VIDEODRIVER=dummy is the difference between a harness that works on a
#     build machine and one that only works on a desktop.
#
# Usage:
#   ./sdl.sh examples/Windowed.a24            # run it, both ways
#   ./sdl.sh --test examples/WindowedTest.a24 # run its test blocks, both ways
#   ./sdl.sh --show examples/Windowed.a24     # on a real display, not headless
#
set -uo pipefail

ROOT=$(cd "$(dirname "$0")" && pwd)
CC=${CC:-cc}

if ! command -v sdl2-config >/dev/null 2>&1; then
    echo "sdl2-config not found -- install SDL2 (brew install sdl2)." >&2
    exit 1
fi

# ⚠️ $PWD-independent.  Every path here is built from ROOT for the reason in the
# header: the compile step runs from inside the output directory.
SDL_CFLAGS="-DALG_SDL -I$ROOT/third_party $(sdl2-config --cflags)"
SDL_LIBS="$(sdl2-config --libs)"
BASE=${CFLAGS:--std=c11 -O2}

WANT_TESTS=0
HEADLESS=1

while [ $# -gt 0 ]; do
    case "$1" in
        --test) WANT_TESTS=1; shift ;;
        --show) HEADLESS=0; shift ;;
        --) shift; break ;;
        -*) echo "unknown option: $1" >&2; exit 2 ;;
        *) break ;;
    esac
done

if [ $# -lt 1 ]; then
    echo "usage: ./sdl.sh [--test] [--show] <program.a24>" >&2
    exit 2
fi

SOURCE=$1

if [ ! -f "$SOURCE" ]; then
    echo "no such file: $SOURCE" >&2
    exit 1
fi

WORK=$(mktemp -d); trap 'rm -rf "$WORK"' EXIT

[ "$HEADLESS" -eq 1 ] && export SDL_VIDEODRIVER=dummy

# -- an SDL-enabled compiler, from the checked-in seed ----------------------
#
# From bootstrap/ rather than ./algc, because ./algc is whatever the last plain
# build produced and that one has no SDL in it.  The seed is C, so this needs
# nothing but cc.
echo "  building an SDL-enabled algc from the seed"

( cd "$ROOT/bootstrap" && $CC $BASE $SDL_CFLAGS $SDL_LIBS -o "$WORK/algc" ./*.c ) \
    || { echo "FAIL  the seed would not build with SDL"; exit 1; }

# ⚠️ Guarded expansion, not "${MODE[@]}".  macOS ships bash 3.2, where an EMPTY
# array counts as unbound under 'set -u' -- so the no-arguments case, which is
# the common one, died with 'MODE[@]: unbound variable' while --test worked.
MODE=()
[ "$WANT_TESTS" -eq 1 ] && MODE=(--test)

# -- interpreted -----------------------------------------------------------
echo "  interpreting"
interpreted=$( cd "$ROOT" && "$WORK/algc" ${MODE[@]+"${MODE[@]}"} "$SOURCE" 2>&1 ); istat=$?

# -- compiled --------------------------------------------------------------
echo "  compiling"
OUT="$WORK/out"; mkdir -p "$OUT"
cp "$ROOT/bootstrap/algol.c" "$ROOT/bootstrap/algol.h" "$OUT/"

if ! ( cd "$ROOT" && "$WORK/algc" --compile ${MODE[@]+"${MODE[@]}"} "--out=$OUT" "$SOURCE" ) >"$WORK/emit.log" 2>&1; then
    echo "FAIL  could not emit C"; cat "$WORK/emit.log"; exit 1
fi

if ! ( cd "$OUT" && $CC $BASE $SDL_CFLAGS $SDL_LIBS -o run ./*.c ) 2>"$WORK/cc.log"; then
    echo "FAIL  cc rejected the emitted C"; head -20 "$WORK/cc.log"; exit 1
fi

echo "  running"
# ⚠️ From ROOT, so a relative path like 'examples/bar.png' in the program means
# the same thing under both processors.  Run from $OUT and only the compiled
# half fails to find its images.
compiled=$( cd "$ROOT" && "$OUT/run" 2>&1 ); cstat=$?

# -- compare ---------------------------------------------------------------
#
# ⚠️ The same normalisation test.sh uses: colour stripped and [ERROR] lines
# dropped, because an assertion failure prints a source caret when interpreted
# and compiled code carries no line information to print one from.
strip() { LC_ALL=C sed -E $'s/\033\\[[0-9;]*m//g' | LC_ALL=C grep -v '^\[ERROR\]'; }

a=$(printf '%s\n' "$interpreted" | strip)
b=$(printf '%s\n' "$compiled"    | strip)

echo
printf '%s\n' "$interpreted"

if [ "$a" != "$b" ]; then
    echo
    echo "FAIL  the two processors disagree"
    diff <(printf '%s\n' "$a") <(printf '%s\n' "$b") | head -20
    exit 1
fi

if [ "$istat" -ne "$cstat" ]; then
    echo
    echo "FAIL  exit codes differ: interpreted $istat, compiled $cstat"
    exit 1
fi

echo
echo "ok    both processors agree (exit $istat)"
exit "$istat"
