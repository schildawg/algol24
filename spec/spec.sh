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
    /^[ \t]+(interpreter|compiler|unit|conformance|refusal|defect)[ \t]/ {
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
    [ "$key" = "unit" ] || continue
    CITED_TESTS=$((CITED_TESTS + 1))

    if [ -s "$WORK/testnames" ] && ! grep -qxF "$value" "$WORK/testnames"; then
        problem "$rule cites a unit test the suite does not run: '$value'"
        MISSING_TEST=$((MISSING_TEST + 1))
    fi
done < "$WORK/cites"

[ "$MISSING_TEST" -eq 0 ] && [ -s "$WORK/testnames" ] \
    && echo "  $CITED_TESTS unit citation(s) name tests the suite runs"

# ------------------------------------------------------------- conformance --
#
# ⚠️ A conformance citation names a program in conformance/, which is a
# different kind of evidence from a unit test and must not be checked against
# the same list.  A unit test proves the rule transcribes the interpreter; only
# a conformance program can be run against another implementation at all.

MISSING_CONF=0
TBD=0

# ⚠️ A rule is covered three ways, not one.  A valid program in conformance/, an
# invalid one in refusals/, or -- where the specification has decided something
# the implementation does not yet do -- a reproduction in defects/.  Counting
# only the first would report a rule as uncovered when it is precisely tracked.
while IFS="$(printf '\t')" read -r rule key value; do
    case "$key" in
        conformance) _dir=conformance ;;
        refusal)     _dir=refusals ;;
        defect)      _dir=defects ;;
        *) continue ;;
    esac

    if [ "$key" != conformance ]; then
        if [ ! -f "$_dir/$value" ]; then
            problem "$rule cites a $key case that does not exist: $value"
            MISSING_CONF=$((MISSING_CONF + 1))
        fi
        continue
    fi

    if [ "$value" = "TBD" ]; then
        # ⚠️ The reserved -000 illustration is excluded here for the same
        # reason it is excluded from the rule count: counting its TBD made the
        # conformance tally exceed the number of rules and report a negative
        # coverage.
        case "$rule" in *-000) ;; *) TBD=$((TBD + 1)) ;; esac
        continue
    fi

    if [ ! -f "conformance/$value" ]; then
        problem "$rule cites a conformance program that does not exist: $value"
        MISSING_CONF=$((MISSING_CONF + 1))
    fi
done < "$WORK/cites"

for k in unit conformance refusal defect; do
    awk -F'\t' -v k="$k" '$2==k{print $1}' "$WORK/cites" | sort -u > "$WORK/has_$k"
done
cat "$WORK/has_conformance" "$WORK/has_refusal" "$WORK/has_defect" 2>/dev/null \
  | sort -u > "$WORK/has_any"

[ "$MISSING_CONF" -eq 0 ] && echo "  $TBD rule(s) await a conformance program (TBD)"

# ⚠️ Every rule must carry BOTH keys.  A rule with neither is not "not yet
# covered" -- it is unaccounted for, and the difference is the whole point of
# writing TBD down rather than leaving the line out.
sort -u "$WORK/ids" > "$WORK/allids"
# ⚠️ Every rule must be accounted for by ONE of the three, and 'conformance TBD'
# counts: an admitted gap is accounted for, an absent line is not. The point is
# that no rule can be silently unclaimed.
comm -23 "$WORK/allids" "$WORK/has_any" > "$WORK/no_conf"
if [ -s "$WORK/no_conf" ]; then
    while read -r r; do
        problem "$r is unaccounted for — needs a conformance, refusal or defect line"
    done < "$WORK/no_conf"
fi

# ⚠️ The two markers a rule uses to admit it is ahead of the implementation each
# owe the reader somewhere to go, and a marker with nowhere to go is worse than
# none -- it announces a gap and then strands whoever followed it.
#
#   NOT YET IMPLEMENTED  wrong outright   -> must CITE a defect in its trailer
#   PARTLY IMPLEMENTED   wrong in part    -> must NAME a defect in its text
#   PLANNED              not wrong at all -> must name Annex H
#
# PARTLY IMPLEMENTED is the looser of the first two on purpose: the half that
# works is pinned by a conformance program, so that is what the trailer holds,
# and the failing half is named in prose.
#
# Getting these backwards is the specific mistake worth catching: writing PLANNED
# over a defect quietly excuses it, and writing NOT YET IMPLEMENTED over planned
# work invents a defect that does not exist.

awk '/^\*\*\[[A-Z]+-[0-9]+\]\*\*/ {
         if (id != "") { print id "\t" nyi "\t" partly "\t" planned "\t" names }
         match($0, /\[[A-Z]+-[0-9]+\]/)
         id = substr($0, RSTART + 1, RLENGTH - 2)
         nyi = 0; partly = 0; planned = 0; names = 0
     }
     /NOT YET IMPLEMENTED/         { nyi = 1 }
     /PARTLY IMPLEMENTED/          { partly = 1 }
     /PLANNED — a later generation/ { planned = 1 }
     /DEF-[0-9]/                   { names = 1 }
     END { if (id != "") print id "\t" nyi "\t" partly "\t" planned "\t" names }' \
    "$SPEC" > "$WORK/markers"

awk -F'\t' '$2 == 1 {print $1}'             "$WORK/markers" | sort -u > "$WORK/nyi"
awk -F'\t' '$3 == 1 && $5 == 0 {print $1}'  "$WORK/markers" | sort -u > "$WORK/partly_bare"
awk -F'\t' '$3 == 1 {print $1}'             "$WORK/markers" | sort -u > "$WORK/partly"
awk -F'\t' '$4 == 1 {print $1}'             "$WORK/markers" | sort -u > "$WORK/planned"

NYI_UNTRACKED=$(comm -23 "$WORK/nyi" "$WORK/has_defect" | tr '\n' ' ')
[ -n "$NYI_UNTRACKED" ] \
    && problem "marked NOT YET IMPLEMENTED but citing no defect: $NYI_UNTRACKED"

PARTLY_BARE=$(tr '\n' ' ' < "$WORK/partly_bare")
[ -n "$PARTLY_BARE" ] \
    && problem "marked PARTLY IMPLEMENTED but naming no defect: $PARTLY_BARE"

BOTH=$(comm -12 "$WORK/nyi" "$WORK/planned" | tr '\n' ' ')
[ -n "$BOTH" ] \
    && problem "marked both NOT YET IMPLEMENTED and PLANNED, which cannot both be true: $BOTH"

if [ -s "$WORK/planned" ] && ! grep -q '^## Annex H' "$SPEC"; then
    problem "rule(s) marked PLANNED but the specification has no Annex H"
fi

[ -z "$NYI_UNTRACKED" ] && [ -z "$BOTH" ] && [ -z "$PARTLY_BARE" ] && {
    echo "  $(wc -l < "$WORK/nyi" | tr -d ' ') rule(s) ahead of the implementation, each citing a defect"
    echo "  $(wc -l < "$WORK/partly" | tr -d ' ') rule(s) partly implemented, each naming one"
    echo "  $(wc -l < "$WORK/planned" | tr -d ' ') rule(s) planned for a later generation"
}

# ------------------------------------------------------------------ tables --
#
# ⚠️ A list transcribed into prose is the most rot-prone thing a specification
# can hold, and this repository has already lost one: the VS Code grammar's
# keyword list was a hand copy that nothing checked.  Any enumeration the
# specification states must be derived from the source and compared, not
# trusted.  This is the first of that family; operators and built-ins will want
# the same treatment.

echo
echo "Tables"

sed -n '/var  Keywords := \[/,/TOKEN_WHILE\];/p' compiler/Scanner.a24 \
  | grep -oE "'[a-z]+':" | tr -d "':" | sort -u > "$WORK/kw_source"

# ⚠️ [LEX-010] carries TWO fenced blocks: the keywords of the language, and --
# under the NOT YET IMPLEMENTED note -- the ones the scanner registers in error.
# The scanner must match their UNION, or the specification has lost track of a
# word in one direction or the other. Checking only the first block would report
# every specified removal as a discrepancy, which is exactly the noise that gets
# a checker switched off.

awk '/\*\*\[LEX-010\]\*\*/{f=1; next}
     f && /^\*\*\[LEX-011\]\*\*/{exit}
     f && /^```$/ { c++; next }
     f && c % 2 == 1 { print }' "$SPEC" \
  | tr -s ' \n' '\n' | grep -vE '^$' | sort -u > "$WORK/kw_spec"

awk '/\*\*\[LEX-010\]\*\*/{f=1; next}
     f && /^```$/ { c++; if (c == 2) exit; next }
     f && c == 1  { print }' "$SPEC" \
  | tr -s ' \n' '\n' | grep -vE '^$' | sort -u > "$WORK/kw_norm"

if [ ! -s "$WORK/kw_source" ] || [ ! -s "$WORK/kw_spec" ]; then
    problem "the keyword table could not be read from one side or the other"
else
    KW_MISSING=$(comm -23 "$WORK/kw_source" "$WORK/kw_spec" | tr '\n' ' ')
    KW_EXTRA=$(comm -13 "$WORK/kw_source" "$WORK/kw_spec" | tr '\n' ' ')

    [ -n "$KW_MISSING" ] && problem "LEX-010 omits keyword(s) the scanner has: $KW_MISSING"
    [ -n "$KW_EXTRA" ]   && problem "LEX-010 lists word(s) the scanner does not: $KW_EXTRA"
    [ -z "$KW_MISSING" ] && [ -z "$KW_EXTRA" ] \
        && echo "  LEX-010 keywords match Scanner.a24 ($(wc -l < "$WORK/kw_norm" | tr -d ' ') in the language, $(( $(wc -l < "$WORK/kw_spec" | tr -d ' ') - $(wc -l < "$WORK/kw_norm" | tr -d ' ') )) registered in error)"
fi

# ⚠️ Annex A repeats every production the chapters state.  A repetition that
# nothing checks is the same bet this repository has already lost twice, so
# both directions are compared: a production stated in a chapter and missing
# from the annex, and one in the annex that no chapter defines.

awk '/^## 3\. Source code/{on=1} /^## Annex/{on=0}
     on && /^```$/ {f = !f; next}
     on && f && /^[A-Za-z_][A-Za-z_0-9]*[ \t]*=/ {
         sub(/[ \t]*=.*/, ""); print
     }' "$SPEC" | sort -u > "$WORK/prod_chapters"

awk '/^## Annex A/{on=1} /^## Annex B/{on=0}
     on && /^```$/ {f = !f; next}
     on && f && /^[A-Za-z_][A-Za-z_0-9]*[ \t]*=/ {
         sub(/[ \t]*=.*/, ""); print
     }' "$SPEC" | sort -u > "$WORK/prod_annex"

PROD_MISSING=$(comm -23 "$WORK/prod_chapters" "$WORK/prod_annex" | tr '\n' ' ')
PROD_EXTRA=$(comm -13 "$WORK/prod_chapters" "$WORK/prod_annex" | tr '\n' ' ')
[ -n "$PROD_MISSING" ] && problem "Annex A omits production(s) a chapter states: $PROD_MISSING"
[ -n "$PROD_EXTRA" ]   && problem "Annex A states production(s) no chapter defines: $PROD_EXTRA"
[ -z "$PROD_MISSING" ] && [ -z "$PROD_EXTRA" ] \
    && echo "  Annex A matches the chapters ($(wc -l < "$WORK/prod_chapters" | tr -d ' ') productions)"

# ⚠️ Annex B is derived from the names the interpreter registers, not from the
# chapter that describes them, so a built-in added to the language without a
# specification entry is caught here rather than going unnoticed.

grep -oE "Builtins\.Define \('[A-Za-z]+'" compiler/Interpreter.a24 \
  | sed "s/.*'\(.*\)'/\1/" | sort -u > "$WORK/bi_source"

awk '/^## Annex B/{on=1} /^## Annex C/{on=0}
     on && /^\| `/ { gsub(/^\| `|`.*$/, ""); print }' "$SPEC" | sort -u > "$WORK/bi_annex"

BI_MISSING=$(comm -23 "$WORK/bi_source" "$WORK/bi_annex" | tr '\n' ' ')
BI_EXTRA=$(comm -13 "$WORK/bi_source" "$WORK/bi_annex" | tr '\n' ' ')
[ -n "$BI_MISSING" ] && problem "Annex B omits built-in(s) the interpreter registers: $BI_MISSING"
[ -n "$BI_EXTRA" ]   && problem "Annex B lists name(s) the interpreter does not register: $BI_EXTRA"
[ -z "$BI_MISSING" ] && [ -z "$BI_EXTRA" ] \
    && echo "  Annex B matches Interpreter.a24 ($(wc -l < "$WORK/bi_source" | tr -d ' ') built-ins)"

# ---------------------------------------------------------------- coverage --

if [ "$COVERAGE" -eq 1 ]; then
    echo
    echo "Coverage"

    comm -23 "$WORK/allids" "$WORK/has_unit" > "$WORK/no_unit"

    echo "  pinned by a unit test:   $(wc -l < "$WORK/has_unit" | tr -d ' ') of $RULE_COUNT"
    echo "  covered by conformance:  $(( $(wc -l < "$WORK/allids" | tr -d ' ') - TBD )) of $RULE_COUNT"
    echo "  tracked by a defect:     $(wc -l < "$WORK/has_defect" | tr -d ' ') of $RULE_COUNT"
    echo "  covered by a refusal:    $(wc -l < "$WORK/has_refusal" | tr -d ' ') of $RULE_COUNT"

    if [ -s "$WORK/no_unit" ]; then
        echo "  no unit test pins these:"
        sed 's/^/    /' "$WORK/no_unit"
    fi
fi

echo
if [ "$FAILED" -ne 0 ]; then
    echo "FAIL: the specification cites things that do not exist."
    exit 1
fi

echo "OK: every citation resolves."
