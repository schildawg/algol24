#!/bin/sh
#
# conform.sh -- runs the conformance corpus, the refusal corpus, and the
# defects.
#
#   ./conform.sh                # everything
#   ./conform.sh --interpreted  # skip the compiled half entirely
#   ./conform.sh --strict       # also fail on compiler gaps
#   ./conform.sh --record       # write .out/.expected/.current from what happens
#
# ⚠️ THE INTERPRETER DEFINES THE CORPUS. Every case here asks one question --
# "is the interpreter right?" -- and the compiler's state never enters into how
# a case is classified:
#
#   interpreter right  -> conformance/ or refusals/, EVEN IF the compiler is
#                         wrong. The compiled half then fails, and that failure
#                         IS the record of the divergence.
#   interpreter wrong  -> defects/, EVEN IF the compiler is right.
#
# This is deliberate and follows the generation plan: the goal of the next
# generation is an interpreter that matches the specification, and the goal of
# the one after is a compiler that matches the interpreter. Classifying by the
# compiler's state would mix the two.
#
# ⚠️ TWO VERDICTS, NOT ONE, because they answer different questions:
#
#   the language   the interpreted half must be green. This is the gate.
#   the compiler   compiled failures are counted and listed as GAPS. They are
#                  EXPECTED while the compiler trails the specification, and do
#                  not fail the run unless --strict is given.
#
# A third question is not asked here at all: whether the compiler still builds
# and reproduces itself. That is ./fixedpoint.sh and ./test.sh, and it is the
# one thing that must not break -- a compiler that cannot compile cannot
# produce the generation that fixes it.
#
# ⚠️ A defect is a statement about the INTERPRETER, so defects are compared
# interpreted-only. Whether the compiler happens to share the fault says
# nothing about whether the interpreter still has it.
#
# ⚠️ A defect passes while it still reproduces and FAILS WHEN IT STOPS. A fix is
# as much a change to be noticed as a regression, and the alternative -- a suite
# with permanently failing entries -- is a suite nobody reads. This repository
# has already been there once: the old VS Code notes said the tree was "red on
# purpose" and gated on the count rather than the colour.

set -eu

cd "$(dirname "$0")"

ALGC="bootstrap/algc"
SPEC="spec/ALGOL-24.md"
RECORD=0
COMPILED=1
STRICT=0

while [ $# -gt 0 ]; do
    case "$1" in
        --record)      RECORD=1 ;;
        --interpreted) COMPILED=0 ;;
        --strict)      STRICT=1 ;;
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

PASS=0; FAIL=0; GAPS=0; RECORDED=0
: > "$WORK/gaplist"

# Runs one case interpreted, and compiled unless the caller says not to.
# Leaves the rendered results in $WORK/interpreted and $WORK/compiled.
run_case() {
    _src=$1
    _want_compiled=$2

    # ⚠️ A case may ask to be run differently. '// run: --test' makes this a
    # test run, which chapter 19 needs: the report is the thing being pinned,
    # and an ordinary run would execute the program and skip the tests
    # entirely. Same directive spec/probes/record.sh uses.
    _args=$(sed -n 's|^// run: ||p' "$_src" | head -1)

    _status=0
    # shellcheck disable=SC2086
    "$ALGC" $_args "$_src" > "$WORK/raw" 2>&1 || _status=$?
    { render < "$WORK/raw"; echo "exit: $_status"; } > "$WORK/interpreted"

    COMPILED_RAN=0
    [ "$COMPILED" -eq 1 ] && [ "$_want_compiled" -eq 1 ] || return 0

    rm -rf "$WORK/out"; mkdir -p "$WORK/out"
    _emit=0
    # ⚠️ '--compile --test' emits the tests plus a runner, so a case asking for
    # a test run is compiled as one. Compiling it as an ordinary program would
    # compare a test report against a program that ran nothing.
    # shellcheck disable=SC2086
    "$ALGC" --compile $_args --out="$WORK/out" "$_src" > "$WORK/emit" 2>&1 || _emit=$?
    if [ "$_emit" -ne 0 ]; then
        # ⚠️ Rendered exactly as the interpreted run is, with no marker of its
        # own.  The front end is shared [1.1], so a program refused when it is
        # run is refused identically when it is compiled -- and the whole
        # refusal corpus compares equal here, as it should.  An added
        # "(refused to emit)" line made all twenty-three of them look like
        # divergences.
        { render < "$WORK/emit"; echo "exit: $_emit"; } > "$WORK/compiled"
        COMPILED_RAN=1
        return 0
    fi
    cp bootstrap/algol.c bootstrap/algol.h "$WORK/out/"
    if ! ${CC:-cc} -std=c11 -O2 -o "$WORK/out/prog" "$WORK/out"/*.c 2>"$WORK/ccerr"; then
        { echo "(the emitted C did not build)"; sed 's/^/cc: /' "$WORK/ccerr" | head -4; } \
            > "$WORK/compiled"
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

    # ⚠️ A defect is a statement about the interpreter, so it is never compiled.
    _do_compiled=1
    [ "$_kind" = defect ] && _do_compiled=0

    run_case "$_src" "$_do_compiled"

    if [ "$RECORD" -eq 1 ]; then
        # ⚠️ The recording is ALWAYS the interpreted run.  It used to be skipped
        # when the two processors disagreed, which was how several divergences
        # were first noticed -- but a disagreement is now reported as a gap on
        # every ordinary run, so the discovery is continuous rather than
        # happening only at record time.
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
    cmp -s "$WORK/interpreted" "$_want" || _ok=0

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

    PASS=$((PASS + 1))

    # The language is satisfied.  Now ask the separate question about the
    # compiler, and record the answer as a gap rather than a failure.
    if [ "$COMPILED_RAN" -eq 1 ] && ! cmp -s "$WORK/interpreted" "$WORK/compiled"; then
        GAPS=$((GAPS + 1))
        {
            echo "  $_name"
            diff "$WORK/interpreted" "$WORK/compiled" \
              | sed 's/^/      /' | head -8
        } >> "$WORK/gaplist"

        # ⚠️ The names alone, for the Annex C cross-check below.  A gap IS the
        # divergence's reproduction: the interpreted expectation is the correct
        # answer and the compiled run is the fault, so unlike a defect it needs
        # no recorded file of its own.
        echo "$_name.a24" >> "$WORK/gapnames"
    fi
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
    echo "$RECORDED expectation(s) written."
    exit 0
fi

echo "the language:  $PASS passed, $FAIL failed."

if [ "$COMPILED" -eq 1 ]; then
    echo "the compiler:  $GAPS gap(s) — cases the interpreter gets right and the compiled back end does not."
    if [ "$GAPS" -gt 0 ]; then
        echo
        echo "Compiler gaps (Annex C). Expected while the compiler trails the"
        echo "specification; each is a case for the generation after this one."
        cat "$WORK/gaplist"
    fi
fi

# ---------------------------------------------------------------- Annex C --
#
# ⚠️ Every divergence Annex C records must still HAPPEN, and every divergence
# that happens must be recorded.  Both directions, for the reason the Annex F
# check in spec.sh exists: an entry describing a fault that has been fixed goes
# on reading as open, and C-1, C-3, C-4 and C-22 all reached that state.
#
# ⚠️ Checked HERE rather than in spec.sh because only this script knows which
# cases actually differ -- it has just compiled every one of them.  spec.sh
# checks that a cited case EXISTS; this checks that it still diverges.
touch "$WORK/gapnames"
sort -u "$WORK/gapnames" > "$WORK/gaps_live"

grep -E '^    gap  ' "$SPEC" 2>/dev/null | awk '{print $2}' | sort -u > "$WORK/gaps_cited"

STALE=$(comm -23 "$WORK/gaps_cited" "$WORK/gaps_live" | tr '\n' ' ')
UNCITED=$(comm -13 "$WORK/gaps_cited" "$WORK/gaps_live" | tr '\n' ' ')

CITED_N=$(wc -l < "$WORK/gaps_cited" | tr -d ' ')

echo
echo "Annex C:       $CITED_N of $GAPS gap(s) are cited by a divergence entry."

if [ -n "$STALE" ]; then
    echo "FAIL: Annex C cites case(s) that no longer diverge, so a fixed"
    echo "      divergence still reads as open: $STALE"
    echo "      Withdraw the entry, as C-1, C-3, C-4 and C-22 were."
    exit 1
fi

# ⚠️ An UNCITED gap is the backlog, not an error -- the mapping from Annex C to
# the cases that demonstrate it has still to be written.  Under --strict it is
# an error, and --strict passing with no gaps at all is what ends Generation 2.
if [ -n "$UNCITED" ] && [ "$STRICT" -eq 1 ]; then
    echo "FAIL: --strict, and $(echo "$UNCITED" | wc -w | tr -d ' ') gap(s) no entry cites."
    exit 1
fi

echo
[ "$FAIL" -eq 0 ] || { echo "FAIL: the interpreter does not match the specification."; exit 1; }

if [ "$STRICT" -eq 1 ] && [ "$GAPS" -gt 0 ]; then
    echo "FAIL: --strict, and the compiler has $GAPS gap(s)."
    exit 1
fi

echo "OK: the interpreter conforms where the specification says it should,"
echo "    and every recorded defect still reproduces."
[ "$GAPS" -eq 0 ] || echo "    $GAPS compiler gap(s) remain, which is expected and not a failure."
