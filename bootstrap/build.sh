#!/bin/sh
#
# Builds algc, the Algol-24 compiler, from the C checked in beside this script.
#
#   ./build.sh                 # -> ./algc
#   CC=clang CFLAGS=-O0 ./build.sh
#
# ⚠️ CFLAGS="-std=c11 -O2 -DALG_NO_OVERFLOW_CHECK" turns off integer range
# checking.  Such a build wraps on overflow instead of raising, and so does NOT
# conform -- [LEX-018] requires the raise.  The switch is there because the cost
# is per-operation; measured at about 2-4% on ./test.sh, which is why it is ON
# by default and off in no build these harnesses make.
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
#   cp DIR/*.c DIR/*.h bootstrap/     # never overwrites algol.c/algol.h
#   ./bootstrap/build.sh              # the new seed builds itself

set -eu

cd "$(dirname "$0")"

CC="${CC:-cc}"
CFLAGS="${CFLAGS:--std=c11 -O2}"

# shellcheck disable=SC2086
$CC $CFLAGS -o algc *.c

echo "Built $(pwd)/algc"
echo "Try:  ./algc --help  or  ./algc <program.a24>"
