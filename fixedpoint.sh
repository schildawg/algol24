#!/bin/sh
#
# fixedpoint.sh -- proves the Algol-24 compiler is a fixed point under its own
# output, and that the checked-in seed matches the sources it was emitted from.
#
#   ./fixedpoint.sh              # both checks
#   ./fixedpoint.sh --keep       # leave the generations behind to inspect
#   CC=clang ./fixedpoint.sh
#
# Needs a C compiler and nothing else.  It builds its own compiler from the
# seed, so it does not care whether bootstrap/algc exists or how old it is.
#
# ⚠️ TWO checks, and they answer different questions.
#
#   SEED IN SYNC -- is bootstrap/*.c what the compiler emits from compiler/*.a24
#   today?  Fails when someone edits an .a24 and forgets to reseed.
#
#   FIXED POINT -- does the compiler still emit the same C once it is compiled
#   by itself?  Fails when a change to the emitter changes how the compiler's
#   own source comes out, and it is the only thing that can tell you so.
#
# ⚠️ ONE RESEED IS NOT ALWAYS ENOUGH, which is the whole reason this iterates.
# Generation 1 holds the new emitter's SOURCE written by the OLD emitter's
# rules -- a compiler that behaves the new way, spelled the old way.  Only at
# generation 2 do the rules and the text agree.  A change that alters how the
# compiler emits its own code therefore needs two generations to settle, and
# nothing but this comparison reveals that.
#
# ⚠️ What this does NOT prove.  It exercises the compiler on exactly ONE
# program -- itself -- so any construct the compiler does not use in its own
# source is untested here; that is what the test suite is for.  And a
# self-reproducing defect passes by construction.  A fixed point is
# consistency, not correctness.

set -eu

cd "$(dirname "$0")"

SOURCE="compiler/Main.a24"
MAX_GENERATIONS=5
KEEP=0

while [ $# -gt 0 ]; do
    case "$1" in
        --keep)     KEEP=1 ;;
        --source=*) SOURCE="${1#--source=}" ;;
        --max=*)    MAX_GENERATIONS="${1#--max=}" ;;
        -h|--help)
            sed -n '2,/^set -eu/p' "$0" | sed 's/^#\{1,2\} \{0,1\}//; s/^#$//; /^set -eu$/d'
            exit 0 ;;
        *)
            echo "fixedpoint.sh: unknown argument '$1'" >&2
            exit 2 ;;
    esac
    shift
done

CC="${CC:-cc}"
CFLAGS="${CFLAGS:--std=c11 -O2}"

# ⚠️ The runtime is HAND-WRITTEN and never emitted.  It has to be copied in to
# build each generation, and must not take part in any comparison -- it is the
# one pair of files in bootstrap/ that the compiler does not produce.
RUNTIME="algol.c algol.h"

WORK=$(mktemp -d "${TMPDIR:-/tmp}/algol24-fixedpoint.XXXXXX")

cleanup() {
    if [ "$KEEP" -eq 1 ]; then
        echo
        echo "Generations left in $WORK"
    else
        rm -rf "$WORK"
    fi
}
trap cleanup EXIT

fail() {
    echo
    echo "FAIL: $1"
    exit 1
}

# Every generated file in a directory, by name, in sorted order.
names_in() {
    ( cd "$1" && ls ) | grep -E '\.(c|h)$' | grep -vx -e algol.c -e algol.h || true
}

# Whether two directories hold the same generated files with the same bytes.
# Prints what differs; returns 1 when anything does.
same_tree() {
    _a=$1
    _b=$2
    _differs=0

    names_in "$_a" > "$WORK/.names_a"
    names_in "$_b" > "$WORK/.names_b"

    if ! cmp -s "$WORK/.names_a" "$WORK/.names_b"; then
        echo "  the two sets of files are not the same:"
        diff "$WORK/.names_a" "$WORK/.names_b" | sed 's/^/    /' || true
        _differs=1
    fi

    # ⚠️ The list is capped.  When something run-to-run leaks into the emitted
    # text every file differs at once, and forty identical lines say no more
    # than eight do.
    _shown=0
    _count=0

    while read -r _name; do
        [ -f "$_b/$_name" ] || continue
        if ! cmp -s "$_a/$_name" "$_b/$_name"; then
            _differs=1
            _count=$((_count + 1))
            if [ "$_shown" -lt 8 ]; then
                echo "  differs: $_name"
                _shown=$((_shown + 1))
            fi
        fi
    done < "$WORK/.names_a"

    if [ "$_count" -gt "$_shown" ]; then
        echo "  ... and $((_count - _shown)) more ($_count of $(wc -l < "$WORK/.names_a" | tr -d ' ') files)"
    fi

    return $_differs
}

# Compiles a directory of C into a compiler binary.
build_from() {
    _dir=$1
    _out=$2

    for _file in $RUNTIME; do
        cp "bootstrap/$_file" "$_dir/$_file"
    done

    # shellcheck disable=SC2086
    $CC $CFLAGS -o "$_out" "$_dir"/*.c
}

# Emits a fresh generation of C from the Algol-24 sources.
emit_with() {
    _binary=$1
    _out=$2

    mkdir -p "$_out"
    "$_binary" --compile --out="$_out" "$SOURCE"
}

[ -f "$SOURCE" ] || fail "no such source file: $SOURCE"

echo "Algol-24 fixed-point check"
echo "  source:  $SOURCE"
echo "  seed:    bootstrap/"
echo "  cc:      $CC $CFLAGS"
echo

# ---------------------------------------------------------------- stage one --
#
# Built from the checked-in seed, so this is whatever compiler the repository
# currently ships -- not necessarily one that agrees with compiler/*.a24.

echo "Building stage 1 from the checked-in seed..."
mkdir -p "$WORK/seed"
cp bootstrap/*.c bootstrap/*.h "$WORK/seed/"
build_from "$WORK/seed" "$WORK/algc1"

echo "Emitting generation 1..."
# ⚠️ Emitted into a directory of its own and left pristine.  Building a
# generation puts the runtime beside it, and a generation that has been built
# can no longer be compared against one that has not.
emit_with "$WORK/algc1" "$WORK/gen1"

# ------------------------------------------------------------ seed in sync? --

echo
echo "Check 1 of 2: is the checked-in seed what the compiler emits today?"

mkdir -p "$WORK/seed-generated"
for f in bootstrap/*.c bootstrap/*.h; do
    case "$(basename "$f")" in
        algol.c|algol.h) continue ;;
    esac
    cp "$f" "$WORK/seed-generated/"
done

SEED_IN_SYNC=1
if same_tree "$WORK/seed-generated" "$WORK/gen1"; then
    echo "  seed is in sync with $SOURCE"
else
    SEED_IN_SYNC=0
    echo "  seed is STALE -- bootstrap/ is not what the sources emit"
fi

# ------------------------------------------------------------- fixed point? --

echo
echo "Check 2 of 2: does the compiler emit the same C once compiled by itself?"

GENERATION=1
CONVERGED=0

while [ "$GENERATION" -lt "$MAX_GENERATIONS" ]; do
    NEXT=$((GENERATION + 1))

    # ⚠️ Built from the PREVIOUS generation's C, which is what makes this a
    # bootstrap rather than a repetition: the compiler doing the emitting is
    # itself the product of the emitting under test.
    cp -R "$WORK/gen$GENERATION" "$WORK/build$GENERATION"
    build_from "$WORK/build$GENERATION" "$WORK/algc$NEXT"

    echo "  emitting generation $NEXT (compiler built from generation $GENERATION)..."
    emit_with "$WORK/algc$NEXT" "$WORK/gen$NEXT"

    if same_tree "$WORK/gen$GENERATION" "$WORK/gen$NEXT"; then
        echo "  generation $NEXT is identical to generation $GENERATION"
        CONVERGED=$NEXT
        break
    fi

    echo "  generation $NEXT differs from generation $GENERATION -- not settled yet"
    GENERATION=$NEXT
done

echo
if [ "$CONVERGED" -eq 0 ]; then
    fail "no fixed point after $MAX_GENERATIONS generations.
      The compiler's output never stopped changing, which is not the ordinary
      shape of an unseeded change -- that settles by generation 2.  Suspect
      something in the emitted text that depends on run-to-run state: a map
      iterated in hash order, a pointer or an address printed, a buffer's
      capacity, a timestamp."
fi

if [ "$CONVERGED" -gt 2 ]; then
    echo "Note: it took $CONVERGED generations to settle rather than the usual 2."
    echo
fi

if [ "$SEED_IN_SYNC" -eq 0 ]; then
    fail "the fixed point holds, but the checked-in seed is stale.
      Generation $CONVERGED is the C this repository should ship.  Reseed with it,
      keeping the hand-written runtime:

        ./fixedpoint.sh --keep
        cp WORK/gen$CONVERGED/*.c WORK/gen$CONVERGED/*.h bootstrap/
        ./bootstrap/build.sh

      then run this again -- both checks must pass before committing."
fi

echo "OK: the seed is in sync and the compiler is a fixed point under its own output."
