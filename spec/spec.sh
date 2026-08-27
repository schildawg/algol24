#!/bin/sh
#
# spec.sh -- checks that ALGOL-24.md's rules cite things that exist.
#
#   ./spec/spec.sh              # all checks
#   ./spec/spec.sh --coverage   # also list rules citing no test
#
# A specification is the largest unchecked copy a repository can own, and this
# one names files, symbols and tests that live elsewhere and move. Nothing here
# judges whether a rule is TRUE -- only that its evidence is real. A rule
# citing a test that has been renamed is a lie the prose cannot detect.
#
# ⚠️ Rule identifiers are permanent. This checks they are unique and
# well-formed; it deliberately does NOT check they are contiguous, because a
# retired rule leaves a gap on purpose and renumbering to close it is the exact
# rot the scheme exists to prevent.

set -eu

cd "$(dirname "$0")/.."

SPEC="spec/ALGOL-24.md"
COVERAGE=0

while [ $# -gt 0 ]; do
    case "$1" in
        --coverage) COVERAGE=1 ;;
        -h|--help)
            sed -n '2,/^set -eu/p' "$0" | sed 's/^#\{1,2\} \{0,1\}//; s/^#$//; /^set -eu$/d'
            exit 0 ;;
        *) echo "spec.sh: unknown argument '$1'" >&2; exit 2 ;;
    esac
    shift
done

[ -f "$SPEC" ] || { echo "spec.sh: no $SPEC" >&2; exit 2; }

WORK=$(mktemp -d "${TMPDIR:-/tmp}/algol24-spec.XXXXXX")
trap 'rm -rf "$WORK"' EXIT

FAILED=0
problem() { echo "  $1"; FAILED=1; }

# ---------------------------------------------------------------- the rules --
#
# A rule opens with **[NNN-000]** at the start of a line.  Its trailer is the
# indented block that follows: a key, then a file and an optional symbol, or a
# test name.

# ⚠️ Number 000 is RESERVED in every namespace for the format illustration in
# §1.3 and is never a real rule.  Its citations are still checked -- the example
# has to keep working -- but counting it would overstate the specification by
# one and leave a permanent hole in the coverage report.
grep -nE '^\*\*\[[A-Z]+-[0-9]+\]\*\*' "$SPEC" \
  | sed -E 's/^([0-9]+):\*\*\[([A-Z]+-[0-9]+)\]\*\*.*/\1 \2/' \
  | grep -v -- '-000$' > "$WORK/rules"

RULE_COUNT=$(wc -l < "$WORK/rules" | tr -d ' ')

echo "ALGOL-24.md — $RULE_COUNT rules"
echo

# --------------------------------------------------------- identifier shape --

echo "Identifiers"

awk '{print $2}' "$WORK/rules" > "$WORK/ids"

# ⚠️ Malformed IDs are caught by the grep above never matching them, which
# would silently DROP the rule rather than report it.  So count the loose
# bracketed forms too and complain about the difference.
LOOSE=$(grep -E '^\*\*\[[^]]*\]\*\*' "$SPEC" | grep -vc -- '-000\]' || true)
if [ "$LOOSE" -ne "$RULE_COUNT" ]; then
    problem "$((LOOSE - RULE_COUNT)) rule heading(s) have a malformed identifier"
fi

DUPES=$(sort "$WORK/ids" | uniq -d)
if [ -n "$DUPES" ]; then
    for d in $DUPES; do problem "duplicate identifier: $d"; done
else
    echo "  unique, well-formed"
fi

# ------------------------------------------------------------- the trailers --
#
# Collected by walking the file: a rule heading opens a rule, and the indented
# key/value lines beneath it belong to it until a non-indented, non-blank line.

awk '
    /^\*\*\[[A-Z]+-[0-9]+\]\*\*/ {
        match($0, /\[[A-Z]+-[0-9]+\]/)
        rule = substr($0, RSTART + 1, RLENGTH - 2)
        next
    }
    /^[ \t]+(interpreter|compiler|tests)[ \t]/ {
        if (rule == "") next
        line = $0
        sub(/^[ \t]+/, "", line)
        key = $1
        sub(/^[a-z]+[ \t]+/, "", line)
        print rule "\t" key "\t" line
        next
    }
    # ⚠️ Closed by a HEADING, not by any unindented line.  A rule statement
    # wraps, and its continuation starts at column zero -- closing on that
    # dropped the trailer of every rule whose text ran past one line, which was
    # all but one of them.  The failure was silent: the citations simply were
    # not checked.
    /^#/ { rule = "" }
' "$SPEC" > "$WORK/cites"

echo
echo "Citations"

# ------------------------------------------------------- files and symbols --

MISSING_FILE=0
MISSING_SYM=0

while IFS="$(printf '\t')" read -r rule key value; do
    case "$key" in
        interpreter|compiler) ;;
        *) continue ;;
    esac

    file=$(echo "$value" | awk '{print $1}')
    symbol=$(echo "$value" | cut -s -d' ' -f2- | sed 's/^ *//')

    if [ ! -f "$file" ]; then
        problem "$rule cites a file that does not exist: $file"
        MISSING_FILE=$((MISSING_FILE + 1))
        continue
    fi

    # ⚠️ A fixed string, not a pattern: a symbol containing regex punctuation
    # would otherwise match by accident or fail to match at all.
    if [ -n "$symbol" ] && ! grep -qF "$symbol" "$file"; then
        problem "$rule cites '$symbol', which is not in $file"
        MISSING_SYM=$((MISSING_SYM + 1))
    fi
done < "$WORK/cites"

CITED_FILES=$(awk -F'\t' '$2=="interpreter"||$2=="compiler"' "$WORK/cites" | wc -l | tr -d ' ')
[ "$MISSING_FILE" -eq 0 ] && [ "$MISSING_SYM" -eq 0 ] \
    && echo "  $CITED_FILES file citation(s) resolve"

# ------------------------------------------------------------------- tests --
#
# ⚠️ The names come from the RUNNER, not from grepping for 'test' in the
# sources.  A test block that exists but is unreachable from the suite would
# pass a grep and never run, which is the case worth catching.

if [ -x bootstrap/algc ]; then
    # ⚠️ The dot leader is trimmed with an anchored, non-greedy step.  A single
    # sed with '\(.*\) *\.* \[' looks right and is not: '.*' is greedy, so the
    # captured name swallows the leader and every citation fails to match a
    # name that is really there.
    bootstrap/algc --test compiler/Main.a24 2>/dev/null \
      | sed 's/'"$(printf '\033')"'\[[0-9;]*m//g' \
      | awk '/^\[INFO\] Test: /{
                n = $0
                sub(/^\[INFO\] Test: /, "", n)
                sub(/ \.+ \[.*$/, "", n)
                print n
            }' \
      | sort -u > "$WORK/testnames"
else
    : > "$WORK/testnames"
    problem "no bootstrap/algc, so test citations cannot be checked -- run ./bootstrap/build.sh"
fi

MISSING_TEST=0
CITED_TESTS=0

while IFS="$(printf '\t')" read -r rule key value; do
    [ "$key" = "tests" ] || continue
    CITED_TESTS=$((CITED_TESTS + 1))

    if [ -s "$WORK/testnames" ] && ! grep -qxF "$value" "$WORK/testnames"; then
        problem "$rule cites a test that the suite does not run: '$value'"
        MISSING_TEST=$((MISSING_TEST + 1))
    fi
done < "$WORK/cites"

[ "$MISSING_TEST" -eq 0 ] && [ -s "$WORK/testnames" ] \
    && echo "  $CITED_TESTS test citation(s) name tests the suite runs"

# ---------------------------------------------------------------- coverage --

if [ "$COVERAGE" -eq 1 ]; then
    echo
    echo "Coverage"

    awk -F'\t' '$2=="tests"{print $1}' "$WORK/cites" | sort -u > "$WORK/proven"
    sort -u "$WORK/ids" > "$WORK/allids"
    comm -23 "$WORK/allids" "$WORK/proven" > "$WORK/unproven"

    echo "  $(wc -l < "$WORK/proven" | tr -d ' ') of $RULE_COUNT rules cite a test"
    if [ -s "$WORK/unproven" ]; then
        echo "  unproven:"
        sed 's/^/    /' "$WORK/unproven"
    fi
fi

echo
if [ "$FAILED" -ne 0 ]; then
    echo "FAIL: the specification cites things that do not exist."
    exit 1
fi

echo "OK: every citation resolves."
