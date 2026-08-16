#!/usr/bin/env bash
#
# `uses`-depth mutation harness.
#
#   ./depth.sh                    # chains of depth 1..8, with JPascal
#   ALGC=./algc.exe ./depth.sh    # ...with algc instead
#   ./depth.sh --keep             # leave the generated tree behind to read
#
# ⚠️ The second generating gate, after collide.sh, and it exists because the
# corpus was all LEAVES.  Nothing in ctest/lib/ imported anything, and the two
# large multi-module programs -- algc and the Lox interpreter -- are STARS, where
# the root imports every other file directly.  So the two programs compiled on
# every single build were the one shape immune to a chain bug.  C13 and C15 were
# both found by hand for exactly that reason.
#
# ⚠️ THE INVARIANT IS A COUNT, AND THAT IS THE WHOLE POINT.  The obvious oracle
# for depth is "the program still works", which every gate already asserts for
# its own fixtures -- and it would have missed C15 completely, because that
# program DID work: it ran, printed the right answer, and the compiled and
# interpreted outputs agreed.  What failed was that two of its tests never ran,
# and no differential check can see that, because both sides agree about the
# tests they know about.  A generator can, because it wrote them and knows how
# many there are.
#
# When the failure mode is silent OMISSION, only a count catches it.
#
# Three clauses, none needing a hand-written expected value:
#
#   1  refuse-or-build-and-match      the oracle collide.sh uses
#   2  '--test' runs one test per module plus the root's       (a COUNT)
#   3  the answer at depth d equals the answer at depth 1      (metamorphic)
#
# ⚠️ Clause 3 has caught nothing yet and is kept deliberately.  It is the one
# that would catch a WRONG BUT PLAUSIBLE answer -- an initialisation order that
# gives a different value at depth 5 than at depth 2 -- which is exactly what the
# tentative-definition merge produced one axis over, and exactly what "it builds"
# cannot see.
#
# ⚠️ Unlike collide.sh this TRAVELS: it needs one compiler and cc, nothing else.
# That is not luck.  Clauses 2 and 3 are self-referential -- a count the
# generator knows, and a program compared with itself -- so neither needs a
# second implementation to disagree with.

set -uo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
ALGC="${ALGC:-}"
RUNTIME="${RUNTIME:-$ROOT/src/main/resources/runtime}"
MAX="${MAX:-8}"
WORK="${TMPDIR:-/tmp}/depth.$$"

KEEP=0
[ "${1:-}" = "--keep" ] && KEEP=1

# Default to JPascal, which needs the jar; ALGC= overrides with any compiler
# taking the same flags.
if [ -z "$ALGC" ]; then
    if [ ! -f "$ROOT/target/jpascal.jar" ]; then
        echo "Missing target/jpascal.jar -- run: mvn package -DskipTests"; exit 1
    fi
    run()     { java -jar "$ROOT/target/jpascal.jar" "$@"; }
else
    if [ ! -x "$ALGC" ]; then echo "Missing $ALGC"; exit 1; fi
    run()     { "$ALGC" "$@"; }
fi

plain() { sed -E $'s/\033\\[[0-9;]*m//g'; }

mkdir -p "$WORK"
[ "$KEEP" -eq 0 ] && trap 'rm -rf "$WORK"' EXIT

baseline=""
ok=0
failed=0

for depth in $(seq 1 "$MAX"); do
    dir="$WORK/d$depth"
    mkdir -p "$dir/lib"

    # A chain L1 -> L2 -> ... -> Ld.  Each module takes its value from the one
    # below and carries a test, so the count in clause 2 is known by construction.
    for level in $(seq 1 "$depth"); do
        below=$((level + 1))
        {
            echo "unit L$level;"
            [ "$level" -lt "$depth" ] && echo "uses L$below;"
            echo
            if [ "$level" -lt "$depth" ]; then
                echo "var Held$level := Value$below ();"
            else
                echo "var Held$level := 'end';"
            fi
            echo
            echo "function Value$level () : String;"
            echo "begin"
            echo "    Exit Held$level;"
            echo "end"
            echo
            echo "test 'level $level';"
            echo "begin"
            echo "    AssertEqual ('end', Value$level ());"
            echo "end"
        } > "$dir/lib/L$level.a24"
    done

    {   echo "uses 'lib/L1';"; echo
        echo "begin"; echo "    WriteLn (Value1 ());"; echo "end"; echo
        echo "test 'root';"
        echo "begin"; echo "    AssertEqual ('end', Value1 ());"; echo "end"
    } > "$dir/Root.a24"

    interpreted=$(run "$dir/Root.a24" 2>&1 | plain | tail -1)

    rm -rf "$dir/out"; mkdir -p "$dir/out"
    emitted=$(run --compile "--out=$dir/out" "$dir/Root.a24" 2>&1 | plain)

    # Clause 1a: a chain is legal, so refusing one is a failure -- unlike
    # collide.sh, where a named refusal is a documented narrowing.
    if echo "$emitted" | grep -qE '^(\[ERROR\]|Uncaught:)'; then
        echo "FAIL  depth $depth -- the compiler refused a legal program: $(echo "$emitted" | head -1)"
        failed=$((failed + 1)); continue
    fi

    cp "$RUNTIME/algol.c" "$RUNTIME/algol.h" "$dir/out/" 2>/dev/null

    if ! cc -std=c11 -O1 -o "$dir/binary" "$dir"/out/*.c 2>"$dir/cc.log"; then
        echo "FAIL  depth $depth -- emitted C does not build: $(grep -oE '(error|ld): .*' "$dir/cc.log" | head -1)"
        failed=$((failed + 1)); continue
    fi

    # Clause 1b: compiled must match interpreted.
    compiled=$("$dir/binary" 2>&1)
    if [ "$compiled" != "$interpreted" ]; then
        echo "FAIL  depth $depth -- compiled '$compiled' vs interpreted '$interpreted'"
        failed=$((failed + 1)); continue
    fi

    # Clause 3: depth is not part of the program's meaning.
    [ -z "$baseline" ] && baseline="$interpreted"
    if [ "$interpreted" != "$baseline" ]; then
        echo "FAIL  depth $depth -- '$interpreted', but depth 1 gave '$baseline'"
        failed=$((failed + 1)); continue
    fi

    # Clause 2: the count. One test per module, plus the root's.
    expected=$((depth + 1))
    for mode in interpreted compiled; do
        if [ "$mode" = interpreted ]; then
            report=$(run --test "$dir/Root.a24" 2>&1 | plain)
        else
            rm -rf "$dir/tout"; mkdir -p "$dir/tout"
            run --compile --test "--out=$dir/tout" "$dir/Root.a24" >/dev/null 2>&1
            cp "$RUNTIME/algol.c" "$RUNTIME/algol.h" "$dir/tout/" 2>/dev/null
            cc -std=c11 -O1 -o "$dir/tbinary" "$dir"/tout/*.c 2>/dev/null || { report=""; }
            report=$("$dir/tbinary" 2>&1 | plain)
        fi

        ran=$(echo "$report" | grep -cE '\[ PASS \]')
        if [ "$ran" != "$expected" ]; then
            echo "FAIL  depth $depth -- $mode --test ran $ran of $expected tests"
            failed=$((failed + 1)); continue 2
        fi
    done

    ok=$((ok + 1))
done

echo
echo "depth: $ok chains ok, $failed failed"

[ "$KEEP" -eq 1 ] && echo "kept: $WORK"
[ "$failed" -eq 0 ] && exit 0
exit 70
