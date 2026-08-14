#!/usr/bin/env bash
#
# Every check in the repository.
#
#   ./test.sh              # all of it
#   ./test.sh unit         # the compiler's own test blocks
#   ./test.sh conformance  # the language suites, interpreted
#   ./test.sh compiled     # the same suites compiled -- reports must match
#   ./test.sh programs     # differential: interpreted output vs compiled output
#   ./test.sh fixedpoint   # the compiler reproduces itself, byte for byte
#   ./test.sh leaks        # compiled programs exit without leaking (macOS)
#
# ⚠️ Nothing here is checked against expected output written down by hand.  The
# tree-walking interpreter DEFINES the language, so correctness is differential:
# a program is run both ways and the two must agree.  That is why 'compiled' and
# 'programs' compare against the interpreter rather than against a fixture, and
# why a bug that affects both halves equally would not be caught here -- the
# fixed point and the conformance suites are what cover that.

set -uo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
ALGC="$ROOT/algc"
WORK="${TMPDIR:-/tmp}/algol24-test.$$"
CC="${CC:-cc}"
CFLAGS="${CFLAGS:--std=c11 -O2}"

mkdir -p "$WORK"
trap 'rm -rf "$WORK"' EXIT

if [ ! -x "$ALGC" ]; then
    echo "No compiler yet -- building one."
    "$ROOT/build.sh" >/dev/null || exit 70
    echo
fi

SUITES=(Collections Objects Enumerations Declarations Exceptions Modules Files Core)

# Colour removed; the report proper starts at 'Running'.  ⚠️ [ERROR] lines are
# dropped: an assertion failure prints a source caret interpreted, and compiled
# code has no line information.  What is compared is which tests passed.
report() { sed -E $'s/\033\\[[0-9;]*m//g' | sed -n '/Running/,$p' | grep -v '^\[ERROR\]'; }
plain()  { sed -E $'s/\033\\[[0-9;]*m//g' | grep -vE '^\[(INFO|DEBUG|ERROR)\]'; }

failed=0
declare -a summary

section() { echo; echo "-- $1 ${*:2}"; }
record()  { summary+=("$1"); [ "${2:-0}" -eq 0 ] || failed=$((failed + 1)); }

# --------------------------------------------------------------- unit --
run_unit() {
    section "unit" "the compiler's own test blocks"
    local out bad=0
    out=$("$ALGC" --test "$ROOT/compiler/Main.a24" 2>&1) || bad=1

    echo "$out" | sed -E $'s/\033\\[[0-9;]*m//g' | grep -E 'tests passed|tests failed' | tail -1
    [ "$bad" -eq 0 ] || echo "$out" | sed -E $'s/\033\\[[0-9;]*m//g' | grep -E 'FAIL' | head -5
    record "unit" "$bad"
}

# -------------------------------------------------------- conformance --
run_conformance() {
    section "conformance" "the language suites, interpreted"
    local bad=0
    for suite in "${SUITES[@]}"; do
        local out
        if out=$("$ALGC" --test "$ROOT/tests/conformance/$suite.a24" 2>&1); then
            printf "ok    %-14s %s\n" "$suite" \
                "$(echo "$out" | sed -E $'s/\033\\[[0-9;]*m//g' | grep -oE 'All [0-9]+ tests passed')"
        else
            echo "FAIL  $suite"
            echo "$out" | sed -E $'s/\033\\[[0-9;]*m//g' | grep -E 'FAIL|tests failed' | head -4
            bad=1
        fi
    done
    record "conformance" "$bad"
}

# ----------------------------------------------------------- compiled --
run_compiled() {
    section "compiled" "the same suites compiled -- reports must match"
    local bad=0
    for suite in "${SUITES[@]}"; do
        local dir="$WORK/$suite" expected actual es as
        rm -rf "$dir" && mkdir -p "$dir"
        cp "$ROOT/bootstrap/algol.c" "$ROOT/bootstrap/algol.h" "$dir"/

        if ! "$ALGC" --compile --test "--out=$dir" "$ROOT/tests/conformance/$suite.a24" >"$dir/emit.log" 2>&1; then
            echo "FAIL  $suite -- could not emit C"; plain <"$dir/emit.log" | head -3; bad=1; continue
        fi
        # shellcheck disable=SC2086
        if ! ( cd "$dir" && $CC $CFLAGS -o "$suite" ./*.c ) 2>"$dir/cc.log"; then
            echo "FAIL  $suite -- C compiler rejected the output"; grep -i error "$dir/cc.log" | head -3; bad=1; continue
        fi

        expected=$("$ALGC" --test "$ROOT/tests/conformance/$suite.a24" 2>&1 | report); es=${PIPESTATUS[0]}
        actual=$( ( cd "$ROOT/tests/conformance" && "$dir/$suite" ) 2>&1 | report); as=${PIPESTATUS[0]}

        if [ "$expected" != "$actual" ]; then
            echo "FAIL  $suite -- report differs"
            diff <(echo "$expected") <(echo "$actual") | head -10; bad=1
        elif [ "$es" != "$as" ]; then
            echo "FAIL  $suite -- exit code: interpreted $es, compiled $as"; bad=1
        else
            printf "ok    %-14s %s\n" "$suite" "$(echo "$actual" | tail -1 | sed 's/^\[INFO\] //')"
        fi
    done
    record "compiled" "$bad"
}

# ----------------------------------------------------------- programs --
run_programs() {
    section "programs" "differential: interpreted output vs compiled output"
    local bad=0
    for program in "$ROOT"/tests/programs/*.a24; do
        local name dir expected actual es as
        name=$(basename "$program" .a24)
        dir="$WORK/p_$name"
        rm -rf "$dir" && mkdir -p "$dir"
        cp "$ROOT/bootstrap/algol.c" "$ROOT/bootstrap/algol.h" "$dir"/

        expected=$( ( cd "$(dirname "$program")" && "$ALGC" "$program" ) 2>/dev/null | plain); es=${PIPESTATUS[0]}

        if ! "$ALGC" --compile "--out=$dir" "$program" >"$dir/emit.log" 2>&1; then
            echo "FAIL  $name -- could not emit C"; plain <"$dir/emit.log" | head -3; bad=1; continue
        fi
        # shellcheck disable=SC2086
        if ! ( cd "$dir" && $CC $CFLAGS -o run ./*.c ) 2>"$dir/cc.log"; then
            echo "FAIL  $name -- C compiler rejected the output"; grep -i error "$dir/cc.log" | head -3; bad=1; continue
        fi

        actual=$( ( cd "$(dirname "$program")" && "$dir/run" ) 2>&1); as=$?

        if [ "$expected" != "$actual" ]; then
            echo "FAIL  $name -- output differs"
            diff <(echo "$expected") <(echo "$actual") | head -10; bad=1
        elif [ "$es" != "$as" ]; then
            echo "FAIL  $name -- exit code: interpreted $es, compiled $as"; bad=1
        else
            echo "ok    $name"
        fi
    done
    record "programs" "$bad"
}

# --------------------------------------------------------- fixedpoint --
run_fixedpoint() {
    section "fixedpoint" "the compiler reproduces itself, byte for byte"
    local bad=0

    # ⚠️ What this really tests is DETERMINISM.  Two compilers built from one
    # source must agree down to the character: no hash-order iteration, no
    # timestamps, no addresses reaching the emitted text.  A compiler can be
    # correct and still fail this, and no other check here would see it.
    mkdir -p "$WORK/g2" "$WORK/g3"
    for gen in g2 g3; do cp "$ROOT/bootstrap/algol.c" "$ROOT/bootstrap/algol.h" "$WORK/$gen"/; done

    "$ALGC" --compile "--out=$WORK/g2" "$ROOT/compiler/Main.a24" >/dev/null 2>&1
    if [ ! -s "$WORK/g2/Main.c" ]; then echo "FAIL  could not compile compiler/"; record "fixedpoint" 1; return; fi

    if ! diff -r -x 'algol.[ch]' -x build.sh "$ROOT/bootstrap" "$WORK/g2" >/dev/null; then
        echo "FAIL  the checked-in seed is stale -- run ./build.sh --reseed"
        diff -r -x 'algol.[ch]' -x build.sh "$ROOT/bootstrap" "$WORK/g2" | head -10
        record "fixedpoint" 1; return
    fi
    echo "ok    the seed matches what compiler/ emits"

    # shellcheck disable=SC2086
    ( cd "$WORK/g2" && $CC $CFLAGS -o algc ./*.c ) || { echo "FAIL  generation 2 does not build"; record "fixedpoint" 1; return; }
    "$WORK/g2/algc" --compile "--out=$WORK/g3" "$ROOT/compiler/Main.a24" >/dev/null 2>&1

    if ! diff -r -x 'algol.[ch]' -x algc "$WORK/g2" "$WORK/g3" >/dev/null; then
        echo "FAIL  generations 2 and 3 differ -- the emitter is not deterministic"
        diff -r -x 'algol.[ch]' -x algc "$WORK/g2" "$WORK/g3" | head -10; bad=1
    else
        echo "ok    generations 2 and 3 are identical"
    fi
    record "fixedpoint" "$bad"
}

# -------------------------------------------------------------- leaks --
run_leaks() {
    section "leaks" "compiled programs exit without leaking (macOS)"
    if ! command -v leaks >/dev/null 2>&1; then
        echo "skip  'leaks' not available on this platform"
        return
    fi

    # ⚠️ LeakSanitizer is unsupported on Darwin -- it aborts rather than
    # reporting -- so macOS's own 'leaks' is what does this.
    local bad=0
    for program in "$ROOT"/tests/leak/*.a24; do
        local name dir
        name=$(basename "$program" .a24)
        dir="$WORK/l_$name"
        rm -rf "$dir" && mkdir -p "$dir"
        cp "$ROOT/bootstrap/algol.c" "$ROOT/bootstrap/algol.h" "$dir"/

        "$ALGC" --compile "--out=$dir" "$program" >/dev/null 2>&1
        # shellcheck disable=SC2086
        ( cd "$dir" && $CC -std=c11 -O0 -g -o run ./*.c ) 2>/dev/null

        if MallocStackLogging=1 leaks -atExit -- "$dir/run" >"$dir/leaks.log" 2>&1; then
            echo "ok    $name -- $(grep -oE '[0-9]+ leaks for [0-9]+ total leaked bytes' "$dir/leaks.log" | tail -1)"
        else
            echo "FAIL  $name"; grep -E 'leaks for' "$dir/leaks.log" | tail -2; bad=1
        fi
    done
    record "leaks" "$bad"
}

case "${1-all}" in
    unit)        run_unit ;;
    conformance) run_conformance ;;
    compiled)    run_compiled ;;
    programs)    run_programs ;;
    fixedpoint)  run_fixedpoint ;;
    leaks)       run_leaks ;;
    all)         run_unit; run_conformance; run_compiled; run_programs; run_fixedpoint; run_leaks ;;
    *)           echo "Usage: ./test.sh [unit|conformance|compiled|programs|fixedpoint|leaks]"; exit 64 ;;
esac

echo
if [ "$failed" -eq 0 ]; then
    echo "All green: ${summary[*]}"
    exit 0
fi
echo "$failed of ${#summary[@]} sections failed."
exit 70
