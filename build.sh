#!/usr/bin/env bash
#
# Builds algc, the Algol-24 compiler.
#
#   ./build.sh            # -> ./algc
#   ./build.sh --clean    # ...from scratch
#
# Two stages, because the compiler is written in the language it compiles:
#
#   1. bootstrap/  is C, and builds with cc alone -> a working compiler
#   2. that compiler compiles compiler/*.a24       -> ./algc
#
# Stage 2 is the one you want: it is built from the sources in this repository,
# so an edit to compiler/ shows up in it.  Stage 1 exists only to make stage 2
# possible.
#
# ⚠️ The C in bootstrap/ is GENERATED, and it is a copy of what stage 2 emits.
# So the build can check itself: if the C stage 2 produces differs from the C
# stage 1 was built from, the seed is stale.  That is reported, not fatal --
# right after editing compiler/ it is exactly what you expect to see, and the
# fix is ./build.sh --reseed.  ./test.sh treats it as an error.
#
# Environment:
#   CC=...       the C compiler            (default: cc)
#   CFLAGS=...   passed to it              (default: -std=c11 -O2)

set -uo pipefail

CC="${CC:-cc}"
CFLAGS="${CFLAGS:--std=c11 -O2}"
ROOT="$(cd "$(dirname "$0")" && pwd)"
WORK="$ROOT/.build"

reseed=false
case "${1-}" in
    --clean)  rm -rf "$WORK" "$ROOT/algc" ;;
    --reseed) reseed=true ;;
    "")       ;;
    *)        echo "Usage: ./build.sh [--clean|--reseed]"; exit 64 ;;
esac

mkdir -p "$WORK/stage1" "$WORK/stage2"

# ---------------------------------------------------------------- stage 1 --
echo "  stage 1: building the seed with $CC"
# shellcheck disable=SC2086
( cd "$ROOT/bootstrap" && $CC $CFLAGS -o "$WORK/stage1/algc" ./*.c ) \
    || { echo "FAIL  the seed does not build"; exit 70; }

# ---------------------------------------------------------------- stage 2 --
echo "  stage 2: that compiler compiles compiler/"
rm -f "$WORK/stage2"/*.c "$WORK/stage2"/*.h
cp "$ROOT/bootstrap/algol.c" "$ROOT/bootstrap/algol.h" "$WORK/stage2"/

"$WORK/stage1/algc" --compile "--out=$WORK/stage2" "$ROOT/compiler/Main.a24" \
    || { echo "FAIL  the seed could not compile compiler/"; exit 70; }

# shellcheck disable=SC2086
( cd "$WORK/stage2" && $CC $CFLAGS -o "$ROOT/algc" ./*.c ) \
    || { echo "FAIL  stage 2 does not build"; exit 70; }

# ------------------------------------------------------------- the check --
# Stage 2's C against the seed it came from.  Equal means the checked-in C is
# current; different means compiler/ has moved on since it was generated.
#
# ⚠️ algol.[ch] is the runtime, copied in rather than emitted, and build.sh is
# hand-written -- neither is generated, so neither appears in stage 2's output
# and both would read as a difference forever.  test.sh excludes the same two.
if diff -r -x 'algol.[ch]' -x build.sh "$ROOT/bootstrap" "$WORK/stage2" >/dev/null 2>&1; then
    echo "  seed:    current -- compiler/ emits exactly the checked-in C"
else
    if [ "$reseed" = true ]; then
        cp "$WORK/stage2"/*.c "$WORK/stage2"/*.h "$ROOT/bootstrap"/
        rm -f "$ROOT/bootstrap/algol.c.bak"
        echo "  seed:    REGENERATED from compiler/ -- commit bootstrap/ with your change"
    else
        echo "  seed:    stale -- compiler/ has changed since bootstrap/ was generated"
        echo "           (expected after editing compiler/; run ./build.sh --reseed)"
    fi
fi

echo "Built $ROOT/algc"
