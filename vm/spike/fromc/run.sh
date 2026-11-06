#!/bin/sh
# Builds and runs the C-calls-Algol-24 spike, and checks what it prints.
#
#     vm/spike/fromc/run.sh        # from the repository root
#
# Demonstrates that a hand-written C file can call a unit's subprograms with
# no change to the language -- the mechanism PROPOSAL-VM.md item 0b rests on.
set -eu

CC="${CC:-cc}"
CFLAGS="${CFLAGS:--std=c11 -O2}"
ALGC="${ALGC:-bootstrap/algc}"
HERE="$(cd "$(dirname "$0")" && pwd)"
WORK="${WORK:-$(mktemp -d)}"

[ -x "$ALGC" ] || { echo "no $ALGC -- run ./bootstrap/build.sh first" >&2; exit 1; }

# absolute, because the emit below runs from another directory
ALGC="$(cd "$(dirname "$ALGC")" && pwd)/$(basename "$ALGC")"

mkdir -p "$WORK/out"

# --compile resolves 'uses' beside the importing file, so emit from there
( cd "$HERE" && "$ALGC" --compile --out="$WORK/out" Main.a24 )

cp "$HERE/caller.c" "$WORK/out/"

# Main.c is deliberately left out: caller.c is the program's main
# shellcheck disable=SC2086
$CC $CFLAGS -o "$WORK/caller" \
    "$WORK/out/caller.c" "$WORK/out/Hot.c" "$WORK/out/algol.c"

echo "--- called from C ---"
"$WORK/caller"

echo "--- the same unit run the ordinary way ---"
"$ALGC" "$HERE/Main.a24"
