#!/bin/sh
#
# Builds algc, the Algol-24 compiler, from the C checked in beside this script.
#
#   ./build.sh                 # -> ./algc
#   ./build.sh --ffi           # -> ./algc, able to call C [FUN-014]
#   CC=clang CFLAGS=-O0 ./build.sh
#
# ⚠️ There is no switch to turn integer range checking off, and there used to
# be: -DALG_NO_OVERFLOW_CHECK skipped a check and left a defined wrap.  An
# Integer is unbounded now [LEX-018], so the same branch decides whether to
# promote -- skipping it would not be a faster conforming build, it would be
# wrong answers.
#
# Needs a C compiler and nothing else -- no JDK, no Maven, no make.  That is the
# point of this directory: the compiler is written in Algol-24 and compiles
# itself, so the only way in is a copy of its own output.
#
# This C is generated, apart from algol.c and algol.h, which are the
# hand-written runtime.  Do not edit the rest -- edit compiler/*.a24 and reseed:
#
#   ./bootstrap/build.sh
#   bootstrap/algc --compile --out=DIR compiler/Main.a24
#   cp DIR/*.c DIR/*.h bootstrap/     # algol.c/algol.h are copies of themselves
#   ./bootstrap/build.sh              # the new seed builds itself

set -eu

cd "$(dirname "$0")"

CC="${CC:-cc}"
CFLAGS="${CFLAGS:--std=c11 -O2}"

# ⚠️ --ffi is OFF by default, and that is the whole point of it being a switch.
# A foreign call needs libffi and dlopen [FUN-014]; without them algc still
# builds from a C compiler and nothing else, and an external call reports
# 'Foreign calls are not available in this build' rather than failing to link.
# The default build is the one the conformance corpus runs.
FFI=""
FFI_LIBS=""

case "${1:-}" in
    --ffi) FFI="-DALG_FFI"; FFI_LIBS="-lffi" ;;
    "")    ;;
    *)     echo "usage: build.sh [--ffi]" >&2; exit 2 ;;
esac

# shellcheck disable=SC2086
$CC $CFLAGS $FFI -o algc *.c $FFI_LIBS

echo "Built $(pwd)/algc${FFI:+  (with foreign calls)}"
echo "Try:  ./algc --help  or  ./algc <program.a24>"
