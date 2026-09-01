#!/bin/sh
#
# record.sh -- runs the specification's probes and records what they do.
#
#   ./spec/probes/record.sh             # re-run and report anything that moved
#   ./spec/probes/record.sh --record    # (re)write the .actual files
#
# ⚠️ A PROBE IS NOT A CONFORMANCE TEST. A .actual file records what the
# implementation DOES. It asserts nothing about what the implementation SHOULD
# do, carries no authority, and a rule whose probe runs green is still
# `conformance TBD` in the specification.
#
# The distinction is the whole point. Deciding what the language ought to do is
# a deliberate act, taken once per rule, with Annex D in hand -- writing a
# conformance test the moment a behavior is discovered would canonize every
# defect on sight. LEX-018 is the standing example: these probes record that
# 2147483648 prints -2147483648, and Annex D recommends that it should raise
# instead. Both are true at once, and only one of them is a commitment.
#
# What this IS good for: a change detector. Anything that moves without being
# recorded gets reported, so the language cannot shift under a half-written
# specification unnoticed.

set -eu

cd "$(dirname "$0")/../.."

PROBES="spec/probes"
ALGC="bootstrap/algc"
RECORD=0

while [ $# -gt 0 ]; do
    case "$1" in
        --record) RECORD=1 ;;
        -h|--help)
            sed -n '2,/^set -eu/p' "$0" | sed 's/^#\{1,2\} \{0,1\}//; s/^#$//; /^set -eu$/d'
            exit 0 ;;
        *) echo "record.sh: unknown argument '$1'" >&2; exit 2 ;;
    esac
    shift
done

[ -x "$ALGC" ] || { echo "record.sh: no $ALGC -- run ./bootstrap/build.sh" >&2; exit 2; }

ESC=$(printf '\033')

# ⚠️ Color is TRANSLITERATED, not stripped.  Stripping is not injective -- a
# wrong color and a right one compare equal afterwards -- so it would make a
# color change invisible to the detector.  An escape with no mapping renders
# as [ESC:...] rather than passing through or vanishing.
render() {
    sed -e "s/${ESC}\\[0m/[RESET]/g"  -e "s/${ESC}\\[31m/[RED]/g" \
        -e "s/${ESC}\\[32m/[GREEN]/g" -e "s/${ESC}\\[33m/[YELLOW]/g" \
        -e "s/${ESC}\\[34m/[BLUE]/g"  -e "s/${ESC}\\[36m/[CYAN]/g" \
        -e "s/${ESC}\\[37m/[WHITE]/g" -e "s/${ESC}\\[\\([0-9;]*\\)m/[ESC:\\1]/g"
}

WORK=$(mktemp -d "${TMPDIR:-/tmp}/algol24-probes.XXXXXX")
trap 'rm -rf "$WORK"' EXIT

TOTAL=0; WROTE=0; MOVED=0; NEW=0; EMPTY=0

for probe in "$PROBES"/*.a24; do
    TOTAL=$((TOTAL + 1))
    name=$(basename "$probe" .a24)
    actual="$PROBES/$name.actual"

    # ⚠️ A probe may ask to be run differently.  '// run: --test' makes this a
    # test run, which chapter 19 needs: the report is the thing being recorded,
    # and an ordinary run would execute the program and skip the tests
    # entirely.  Without this the report could not be probed at all.
    args=$(sed -n 's|^// run: ||p' "$probe" | head -1)

    # ⚠️ A probe with no program is indistinguishable from a probe that ran and
    # printed nothing, and record.sh happily recorded three of them as 'exit: 0'
    # -- so nine rules in chapter 7 cited evidence that did not exist while the
    # detector reported green. A probe must contain at least one line that is
    # not blank and not a comment.
    if ! grep -qE '^[[:space:]]*[^/[:space:]]' "$probe"; then
        echo "  EMPTY    $name (header only -- no program to run)"
        EMPTY=$((EMPTY + 1))
        continue
    fi

    status=0
    # shellcheck disable=SC2086
    "$ALGC" $args "$probe" > "$WORK/out" 2>&1 || status=$?
    { render < "$WORK/out"; echo "exit: $status"; } > "$WORK/rendered"

    if [ "$RECORD" -eq 1 ]; then
        if [ ! -f "$actual" ] || ! cmp -s "$WORK/rendered" "$actual"; then
            cp "$WORK/rendered" "$actual"
            WROTE=$((WROTE + 1))
        fi
    elif [ ! -f "$actual" ]; then
        echo "  NEW      $name (never recorded)"
        NEW=$((NEW + 1))
    elif ! cmp -s "$WORK/rendered" "$actual"; then
        echo "  MOVED    $name"
        diff "$actual" "$WORK/rendered" | sed 's/^/             /'
        MOVED=$((MOVED + 1))
    fi
done

echo
if [ "$RECORD" -eq 1 ]; then
    echo "$TOTAL probe(s); $WROTE recording(s) written, $EMPTY empty."
    [ "$EMPTY" -eq 0 ] || exit 1
    exit 0
fi

echo "$TOTAL probe(s); $MOVED moved, $NEW never recorded, $EMPTY empty."
[ "$MOVED" -eq 0 ] && [ "$NEW" -eq 0 ] && [ "$EMPTY" -eq 0 ] \
    && { echo "OK: nothing has shifted."; exit 0; }
echo
echo "Nothing here says the new behavior is wrong -- only that it changed."
echo "Re-record with --record once you have decided it is intended."
exit 1
