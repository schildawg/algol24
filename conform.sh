#!/bin/sh
#
# conform.sh -- runs the conformance corpus, the refusal corpus, and the
# defects, against both processors.
#
#   ./conform.sh                # everything
#   ./conform.sh --interpreted  # skip the compiled half
#   ./conform.sh --record       # write .out/.expected/.current from what happens
#
# THREE KINDS OF CASE, and the difference is the point:
#
#   conformance/  a valid program and the output it must produce.
#   refusals/     an invalid program and the diagnostic it must be refused with.
#   defects/      a program whose behaviour the specification says is WRONG,
#                 and a record of the wrong behaviour it currently produces.
#
# ⚠️ A defect passes while it still reproduces and FAILS WHEN IT STOPS. A fix is
# as much a change to be noticed as a regression, and the alternative -- a suite
# with permanently failing entries -- is a suite nobody reads. This repository
# has already been there once: the old VS Code notes said the tree was "red on
# purpose" and gated on the count rather than the colour.
#
# ⚠️ --record NEVER writes when the two processors disagree. There is no single
# "what happens" in that case, and recording either one would bury a divergence.
# It also refuses to run in CI.

set -eu

cd "$(dirname "$0")"

ALGC="bootstrap/algc"
RECORD=0
COMPILED=1

while [ $# -gt 0 ]; do
    case "$1" in
        --record)      RECORD=1 ;;
        --interpreted) COMPILED=0 ;;
        -h|--help)
            sed -n '2,/^set -eu/p' "$0" | sed 's/^#\{1,2\} \{0,1\}//; s/^#$//; /^set -eu$/d'
            exit 0 ;;
        *) echo "conform.sh: unknown argument '$1'" >&2; exit 2 ;;
    esac
    shift
done

[ -x "$ALGC" ] || { echo "conform.sh: no $ALGC -- run ./bootstrap/build.sh" >&2; exit 2; }
if [ "$RECORD" -eq 1 ] && [ -n "${CI:-}" ]; then
    echo "conform.sh: --record is not permitted in CI" >&2; exit 2
fi

WORK=$(mktemp -d "${TMPDIR:-/tmp}/algol24-conform.XXXXXX")
trap 'rm -rf "$WORK"' EXIT

# ⚠️ Every text tool here runs in the C locale, so it treats its input as BYTES.
# A program under test may print a partial UTF-8 sequence -- 'café'[3] does
# exactly that today, which is the whole point of DEF-01 -- and sed in a UTF-8
# locale refuses such input with "illegal byte sequence" rather than passing it
# through. A harness that cannot read the output of a failing case is no use.
LC_ALL=C
export LC_ALL

ESC=$(printf '\033')

# ⚠️ Colour is transliterated rather than stripped: stripping is not injective,
# so a wrong colour and a right one would compare equal.  See spec/PLAN.md §7.3.
render() {
    sed -e "s/${ESC}\\[0m/[RESET]/g"  -e "s/${ESC}\\[31m/[RED]/g" \
        -e "s/${ESC}\\[32m/[GREEN]/g" -e "s/${ESC}\\[33m/[YELLOW]/g" \
        -e "s/${ESC}\\[34m/[BLUE]/g"  -e "s/${ESC}\\[36m/[CYAN]/g" \
        -e "s/${ESC}\\[37m/[WHITE]/g" -e "s/${ESC}\\[\\([0-9;]*\\)m/[ESC:\\1]/g"
}

PASS=0; FAIL=0; RECORDED=0; SKIPPED=0

# Runs one case interpreted, and compiled unless it opts out, and leaves the
# rendered result in $WORK/interpreted and $WORK/compiled.
run_case() {
    _src=$1
    _status=0
    "$ALGC" "$_src" > "$WORK/raw" 2>&1 || _status=$?
    { render < "$WORK/raw"; echo "exit: $_status"; } > "$WORK/interpreted"

    COMPILED_RAN=0
    [ "$COMPILED" -eq 1 ] || return 0
    grep -q '^// compiled: no' "$_src" && return 0

    rm -rf "$WORK/out"; mkdir -p "$WORK/out"
    if ! "$ALGC" --compile --out="$WORK/out" "$_src" > "$WORK/emit" 2>&1; then
        { render < "$WORK/emit"; echo "exit: 70"; } > "$WORK/compiled"
        COMPILED_RAN=1
        return 0
    fi
    cp bootstrap/algol.c bootstrap/algol.h "$WORK/out/"
    if ! ${CC:-cc} -std=c11 -O2 -o "$WORK/out/prog" "$WORK/out"/*.c 2>"$WORK/ccerr"; then
        { echo "(did not build)"; sed 's/^/cc: /' "$WORK/ccerr"; } > "$WORK/compiled"
        COMPILED_RAN=1
        return 0
    fi
    _status=0
    "$WORK/out/prog" > "$WORK/raw" 2>&1 || _status=$?
    { render < "$WORK/raw"; echo "exit: $_status"; } > "$WORK/compiled"
    COMPILED_RAN=1
}

# Compares the run against its expectation file, reporting by kind.
check() {
    _src=$1; _want=$2; _kind=$3; _name=$(basename "$_src" .a24)

    run_case "$_src"

    if [ "$RECORD" -eq 1 ]; then
        if [ "$COMPILED_RAN" -eq 1 ] && ! cmp -s "$WORK/interpreted" "$WORK/compiled"; then
            echo "  SKIP     $_name — processors disagree, refusing to record"
            SKIPPED=$((SKIPPED + 1)); return 0
        fi
        if [ ! -f "$_want" ] || ! cmp -s "$WORK/interpreted" "$_want"; then
            cp "$WORK/interpreted" "$_want"; RECORDED=$((RECORDED + 1))
        fi
        return 0
    fi

    if [ ! -f "$_want" ]; then
        echo "  MISSING  $_name — no expectation recorded"
        FAIL=$((FAIL + 1)); return 0
    fi

    _ok=1
    if ! cmp -s "$WORK/interpreted" "$_want"; then _ok=0; fi

    if [ "$_kind" = defect ]; then
        # ⚠️ Inverted: matching the record means the defect still reproduces,
        # which is the expected state.  Not matching means it changed.
        if [ "$_ok" -eq 1 ]; then
            PASS=$((PASS + 1))
        else
            echo "  CHANGED  $_name — the defect no longer reproduces as recorded"
            diff "$_want" "$WORK/interpreted" | sed 's/^/             /'
            echo "             If this is a fix, promote it to conformance/ and remove the entry from Annex F."
            FAIL=$((FAIL + 1))
        fi
        return 0
    fi

    if [ "$_ok" -eq 0 ]; then
        echo "  FAIL     $_name"
        diff "$_want" "$WORK/interpreted" | sed 's/^/             /'
        FAIL=$((FAIL + 1)); return 0
    fi

    if [ "$COMPILED_RAN" -eq 1 ] && ! cmp -s "$WORK/interpreted" "$WORK/compiled"; then
        echo "  DIVERGES $_name — compiled differs from interpreted"
        diff "$WORK/interpreted" "$WORK/compiled" | sed 's/^/             /'
        FAIL=$((FAIL + 1)); return 0
    fi

    PASS=$((PASS + 1))
}

for dir_kind in "conformance:out:conformance" "refusals:expected:refusal" "defects:current:defect"; do
    dir=${dir_kind%%:*}; rest=${dir_kind#*:}; ext=${rest%%:*}; kind=${rest#*:}
    [ -d "$dir" ] || continue
    found=$(find "$dir" -maxdepth 1 -name '*.a24' | sort)
    [ -n "$found" ] || continue
    echo "$dir"
    for src in $found; do
        check "$src" "${src%.a24}.$ext" "$kind"
    done
    echo
done

if [ "$RECORD" -eq 1 ]; then
    echo "$RECORDED expectation(s) written, $SKIPPED skipped."
    exit 0
fi

echo "$PASS passed, $FAIL failed."
[ "$FAIL" -eq 0 ] || exit 1
echo "OK: the implementation conforms where the specification says it should,"
echo "    and every recorded defect still reproduces."
