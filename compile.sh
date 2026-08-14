#!/usr/bin/env bash
#
# Compiles an Algol-24 program to a native binary.
#
#   ./compile.sh Program.a24          # -> build/Program
#   ./compile.sh Program.a24 --run    # ...and run it
#   ./compile.sh Program.a24 --run a b # ...with arguments
#
# Builds the compiler first if it is not there, so this works on a fresh clone
# with nothing but a C compiler installed.
#
# The C is emitted into an output directory alongside the runtime it links
# against, so that directory stands alone afterwards: 'cc *.c -o name'.
#
# ⚠️ One C file per SOURCE file, plus a header each.  A module compiles to its
# own translation unit, which is what lets 'private' be C's own 'static'.
#
# Environment:
#   OUT=dir      where to emit and build   (default: build)
#   CC=...       the C compiler            (default: cc)
#   CFLAGS=...   passed to it              (default: -std=c11 -O2)

set -uo pipefail

if [ $# -lt 1 ]; then
    echo "Usage: ./compile.sh <program.a24> [--run] [args...]"
    exit 64
fi

program=$1
shift

run=false
if [ "${1-}" = "--run" ]; then
    run=true
    shift
fi

ROOT="$(cd "$(dirname "$0")" && pwd)"
OUT="${OUT:-build}"
CC="${CC:-cc}"
CFLAGS="${CFLAGS:--std=c11 -O2}"

if [ ! -f "$program" ]; then
    echo "No such program: $program"
    exit 66
fi

if [ ! -x "$ROOT/algc" ]; then
    echo "No compiler yet -- building one."
    "$ROOT/build.sh" || exit 70
    echo
fi

name=$(basename "$program" .a24)

# ⚠️ The compiler will not create this: the language has no way to make a
# directory, so every caller makes it first.
mkdir -p "$OUT"
cp "$ROOT/bootstrap/algol.c" "$ROOT/bootstrap/algol.h" "$OUT"/

# Emitted names are sanitized -- a file name reaches the C as an identifier, so
# '18-frames.a24' becomes '18_frames.c'.  Clear out any earlier emission so a
# renamed module cannot leave a stale file behind for '*.c' to pick up.
find "$OUT" -maxdepth 1 -name '*.c' ! -name 'algol.c' -delete
find "$OUT" -maxdepth 1 -name '*.h' ! -name 'algol.h' -delete

"$ROOT/algc" --compile "--out=$OUT" "$program" || exit 70

# shellcheck disable=SC2086,SC2046
( cd "$OUT" && $CC $CFLAGS -o "$name" ./*.c ) || exit 70

echo "Built $OUT/$name"

if [ "$run" = true ]; then
    echo
    exec "$OUT/$name" "$@"
fi
