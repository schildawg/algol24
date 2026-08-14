#!/bin/sh
#
# Builds algc, the Algol-24 compiler, from the C checked in beside this script.
#
#   ./build.sh                 # -> ./algc
#   CC=clang CFLAGS=-O0 ./build.sh
#
# Needs a C compiler and nothing else -- no JDK, no Maven, no make.  That is the
# point of this directory: the compiler is written in Algol-24 and compiles
# itself, so the only way in is a copy of its own output.
#
# This C is generated.  Do not edit it -- edit algc/*.a24 in the repository and
# run ./seed.sh --update.

set -eu

cd "$(dirname "$0")"

CC="${CC:-cc}"
CFLAGS="${CFLAGS:--std=c11 -O2}"

# shellcheck disable=SC2086
$CC $CFLAGS -o algc *.c

echo "Built $(pwd)/algc"
echo "Try:  ./algc --help  or  ./algc <program.a24>"
