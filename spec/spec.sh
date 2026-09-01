#!/bin/sh
#
# spec.sh -- checks that ALGOL-24.md's rules cite things that exist.
#
#   ./spec/spec.sh              # all checks
#   ./spec/spec.sh --coverage   # also list rules citing no test
#   ./spec/spec.sh --gaps       # which chapters still await a case, and which rules
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
GAPS_REPORT=0

while [ $# -gt 0 ]; do
    case "$1" in
        --coverage) COVERAGE=1 ;;
        --gaps)     GAPS_REPORT=1 ;;
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
grep -oE '^\*\*\[[A-Z]+-[0-9]+\]' "$SPEC" | sed 's/^\*\*\[//; s/\]$//' \
  | sort -u > "$WORK/ids_sorted"

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
    /^[ \t]+(interpreter|compiler|library|unit|conformance|refusal|defect)[ \t]/ {
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
        interpreter|compiler|library) ;;
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

# ⚠️ The reserved -000 illustration is excluded here as it is from the rule
# count, or 'accounted for' reports 261 of 260 -- a total larger than the thing
# it is a total of, which is the shape of a number nobody checks.
for k in unit conformance refusal defect library; do
    awk -F'\t' -v k="$k" '$2==k{print $1}' "$WORK/cites" \
      | grep -v -- '-000$' | sort -u > "$WORK/has_$k"
done
cat "$WORK/has_conformance" "$WORK/has_refusal" "$WORK/has_defect" \
    "$WORK/has_library" 2>/dev/null \
  | sort -u > "$WORK/has_any"

[ "$MISSING_CONF" -eq 0 ] && echo "  $TBD rule(s) await a conformance program (TBD)"

# ⚠️ A TOMBSTONE is a rule whose subject has left the language -- moved into a
# unit written in Algol-24.  It keeps its number so that what cites it still
# resolves, and cites the unit instead of a conformance program: library code is
# pinned by unit tests, never by the corpus, so demanding a case would be asking
# for the one kind of evidence it must not have.
MOVED=$(awk -F"\t" '$2=="library"{print $1}' "$WORK/cites" | sort -u | wc -l | tr -d " ")
echo "  $MOVED rule(s) moved to a library unit, each citing it"

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

# ⚠️ Annex entries must be numbered in the order they appear.  This is checked
# because it has been got wrong four times: Annex E was stranded between two
# chapters, F and G were inserted ahead of it, and H-3 and C-6 each landed above
# entries that should precede them.  An out-of-order annex reads as though an
# entry is missing, and the mistake is invisible in a diff of an inserted block.

awk '/^## Annex ([A-Z]) /{ annex = $3 }
     /^\*\*[A-Z]-[0-9]+ /{
         match($0, /[A-Z]-[0-9]+/)
         tag = substr($0, RSTART, RLENGTH)
         split(tag, part, "-")
         if (part[1] != last_letter) { last_letter = part[1]; last_n = 0 }
         if (part[2] + 0 <= last_n) print tag " follows " part[1] "-" last_n
         last_n = part[2] + 0
     }' "$SPEC" > "$WORK/annex_order"

if [ -s "$WORK/annex_order" ]; then
    while read -r line; do
        problem "annex entries are out of order: $line"
    done < "$WORK/annex_order"
else
    echo "  annex entries are numbered in order"
fi

# ⚠️ Both directions.  Every case the specification cites must exist -- checked
# above -- and every case that exists must be cited by some rule.  Without the
# second, a case can sit in the corpus running green while no rule points at it,
# so a reader following a rule never finds its reproduction and nobody notices
# the citation was never written.  Six files were in that state when this check
# was added.

find conformance refusals defects -maxdepth 1 -name '*.a24' 2>/dev/null \
  | sed 's|.*/||' | sort -u > "$WORK/cases_on_disk"

awk -F'\t' '$2=="conformance"||$2=="refusal"||$2=="defect" {print $3}' "$WORK/cites" \
  | grep -v '^TBD$' | sort -u > "$WORK/cases_cited"

# ⚠️ Every Annex F ENTRY must have a reproduction, which is a third direction and
# was missing.  The two checks above ask whether a cited file exists and whether
# an existing file is cited -- neither notices an entry in Annex F whose case has
# been deleted, because a fixed defect's entry stops citing anything at all.  Two
# entries were in that state when this check was added: DEF-19 and DEF-30, both
# describing faults that had been fixed, both reading as open.

grep -oE '^\*\*DEF-[0-9]+[a-z]*' "$SPEC" | sed 's/^\*\*//' | sort -u > "$WORK/annex_defects"

find defects -maxdepth 1 -name 'DEF-*.a24' 2>/dev/null \
  | sed 's|.*/||; s/^\(DEF-[0-9]*[a-z]*\)-.*/\1/' | sort -u > "$WORK/defect_cases"

# ⚠️ Annex C's divergences are checked in TWO places, and the split is the point.
# Here: a 'gap' citation names a case that exists, and every live entry has one.
# In conform.sh: that case still actually diverges -- which only a script that
# has just compiled every case can know.  A divergence needs no recorded file of
# its own, unlike a defect: the conformance expectation IS the correct answer
# and the compiled run is the fault.

grep -E '^    gap  ' "$SPEC" | awk '{print $2}' | sort -u > "$WORK/gap_cited"

MISSING_GAP=""
while read -r _case; do
    [ -n "$_case" ] || continue
    [ -f "conformance/$_case" ] || [ -f "refusals/$_case" ] \
        || MISSING_GAP="$MISSING_GAP $_case"
done < "$WORK/gap_cited"

if [ -n "$MISSING_GAP" ]; then
    problem "Annex C cites case(s) that do not exist:$MISSING_GAP"
fi

# Live entries -- those not marked Withdrawn -- and how many carry a citation.
# ⚠️ Reported rather than failed: the mapping from Annex C to the cases that
# demonstrate it is the work of Generation 2, and this counts it down.
ENTRIES=$(grep -cE '^\*\*C-[0-9]+ —' "$SPEC")
WITHDRAWN=$(grep -cE '^\*\*\*Withdrawn\.\*\*\*' "$SPEC")
LIVE=$((ENTRIES - WITHDRAWN))
CITEDC=$(wc -l < "$WORK/gap_cited" | tr -d ' ')

echo "  Annex C: $CITEDC gap citation(s) across $LIVE live divergence(s)"

STALE=$(comm -23 "$WORK/annex_defects" "$WORK/defect_cases" | tr '\n' ' ')
if [ -n "$STALE" ]; then
    problem "Annex F entr(ies) with no reproduction, so a fixed defect still reads as open: $STALE"
else
    echo "  every Annex F entry has a reproduction ($(wc -l < "$WORK/annex_defects" | tr -d ' ') defects)"
fi

# ⚠️ Annex H's pins were checked by nothing, and rotted exactly as predicted.
# A planned change is pinned by a case recording the CURRENT rule, so the case
# is meant to be rewritten in the generation that lands the change -- which is
# the moment the citation goes stale.  H-1 and H-2 landed in Generation 3 and
# went on citing the two refusals that were deleted with them, for a whole
# generation, in the annex whose own preamble describes that very sequence.
#
# ⚠️ A landed entry is skipped rather than dropped.  It has no live pin by
# definition, and its prose is worth keeping: it says what the language used to
# do, which the rule it changed no longer records anywhere.

awk '/^## Annex H/{inH=1} inH' "$SPEC" \
  | awk '/^\*\*H-[0-9]/{landed=0} /^\*\*\*Landed/{landed=1} !landed' \
  | grep -oE '(conformance|refusals)/[A-Za-z0-9.-]+\.a24' | sort -u > "$WORK/h_pins"

MISSING_PIN=""
while read -r _case; do
    [ -n "$_case" ] || continue
    [ -f "$_case" ] || MISSING_PIN="$MISSING_PIN $_case"
done < "$WORK/h_pins"

if [ -n "$MISSING_PIN" ]; then
    problem "Annex H pins case(s) that do not exist:$MISSING_PIN"
else
    echo "  every live Annex H pin exists ($(wc -l < "$WORK/h_pins" | tr -d ' ') pins)"
fi

UNCITED=$(comm -23 "$WORK/cases_on_disk" "$WORK/cases_cited" | tr '\n' ' ')
if [ -n "$UNCITED" ]; then
    problem "case file(s) no rule cites: $UNCITED"
else
    echo "  every case file is cited ($(wc -l < "$WORK/cases_on_disk" | tr -d ' ') files)"
fi

# ⚠️ A cross-reference like [VAR-017] must name a rule that exists.  Nothing
# checked this until the specification was finished and about to be read
# carefully, and a dangling reference is the most frustrating thing a reader can
# meet: it looks deliberate, and following it costs a search that ends nowhere.
#
# ⚠️ Defect and annex identifiers -- DEF-12, C-4, D-15, H-9 -- are deliberately
# NOT bracketed, so that the brackets mean one thing.  One had slipped through.

grep -oE '\[[A-Z]+-[0-9]+\]' "$SPEC" | tr -d '[]' | sort -u > "$WORK/xrefs"

DANGLING=$(comm -23 "$WORK/xrefs" "$WORK/ids_sorted" | tr '\n' ' ')
if [ -n "$DANGLING" ]; then
    problem "cross-reference(s) to a rule that does not exist: $DANGLING"
else
    echo "  $(wc -l < "$WORK/xrefs" | tr -d ' ') distinct rule cross-reference(s) resolve"
fi

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

# ⚠️ The editor's grammar is a SECOND transcription of the keyword list, and
# nothing else guards it.  CLAUDE.md warns to mirror a new keyword by hand into
# vscode/syntaxes/, which is exactly the kind of instruction that gets followed
# until it is not -- 'div' had to be remembered on the day it was added.
#
# ⚠️ PRESENCE, not correctness.  A keyword mirrored into the wrong rule would
# still colour wrongly and pass here.  Matching TextMate's structure would mean
# parsing several patterns that each legitimately list a different subset, and a
# brittle check that cries wolf is worse than a narrow one that does not: this
# catches the failure that actually happens, which is a keyword never mirrored
# at all.

GRAMMAR="vscode/syntaxes/algol24.tmLanguage.json"

if [ ! -f "$GRAMMAR" ]; then
    problem "the editor grammar is missing: $GRAMMAR"
elif [ ! -s "$WORK/kw_source" ]; then
    problem "the keyword list could not be read from Scanner.a24"
else
    GRAMMAR_MISSING=""
    while read -r word; do
        grep -qE "[^A-Za-z0-9_]${word}[^A-Za-z0-9_]" "$GRAMMAR" \
            || GRAMMAR_MISSING="$GRAMMAR_MISSING $word"
    done < "$WORK/kw_source"

    if [ -n "$GRAMMAR_MISSING" ]; then
        problem "the editor grammar never mentions keyword(s):$GRAMMAR_MISSING"
    else
        echo "  every keyword appears in the editor grammar ($(wc -l < "$WORK/kw_source" | tr -d ' ') checked for presence)"
    fi
fi

# ⚠️ [COL-003]'s member matrix is five kinds by twenty names, transcribed by
# hand, and it is the single most rot-prone thing in the document.  [RT-021]'s
# is the same shape for the two resources.  spec/members.a24 asks the
# interpreter which members each kind actually answers for, and both tables are
# compared against the answer -- the same treatment the keyword table and Annex
# B get, for the same reason.
#
# ⚠️ ONE SOURCE, TWO TABLES, and the kinds in each table's own header row are
# what separate them.  Checking a table against every pair the probe prints
# would make each table look as though it omitted the other's, so the source is
# narrowed to the kinds the table actually claims to cover.

check_matrix() {
    RULE=$1; STOP=$2

    awk -v rule="\\\\*\\\\*\\\\[$RULE\\\\]\\\\*\\\\*" -v stop="^\\\\*\\\\*\\\\[$STOP\\\\]\\\\*\\\\*" '
         $0 ~ rule {f=1}
         f && $0 ~ stop {exit}
         f && /^\| /{print}' "$SPEC" > "$WORK/mem_table"

    awk -F'|' 'NR==1 {
                   for (i = 3; i <= NF - 1; i++) { gsub(/ /, "", $i); kind[i] = $i }
                   for (i = 3; i <= NF - 1; i++) print "KIND " kind[i] > "/dev/stderr"
                   next
               }
               NR == 2 { next }
               {
                   n = split($2, names, " ")
                   for (i = 3; i <= NF - 1; i++) {
                       cell = $i; gsub(/ /, "", cell)
                       if (cell == "●")
                           for (j = 1; j <= n; j++) {
                               nm = names[j]; gsub(/`/, "", nm)
                               if (nm != "") print kind[i] " " nm
                           }
                   }
               }' "$WORK/mem_table" 2> "$WORK/mem_kinds" | sort -u > "$WORK/mem_spec"

    # Only the kinds this table names.  A pair for any other kind belongs to the
    # other table and is not this one's to account for.
    sed 's/^KIND //' "$WORK/mem_kinds" | sort -u > "$WORK/mem_kinds_only"
    awk 'NR == FNR { want[$1] = 1; next } want[$1]' \
        "$WORK/mem_kinds_only" "$WORK/mem_all" | sort -u > "$WORK/mem_source"

    if [ ! -s "$WORK/mem_source" ] || [ ! -s "$WORK/mem_spec" ]; then
        problem "the $RULE member matrix could not be read from one side or the other"
        return
    fi

    MEM_MISSING=$(comm -23 "$WORK/mem_source" "$WORK/mem_spec" | tr '\n' ',' | sed 's/,$//')
    MEM_EXTRA=$(comm -13 "$WORK/mem_source" "$WORK/mem_spec" | tr '\n' ',' | sed 's/,$//')
    [ -n "$MEM_MISSING" ] && problem "$RULE omits member(s) the interpreter answers for: $MEM_MISSING"
    [ -n "$MEM_EXTRA" ]   && problem "$RULE claims member(s) the interpreter does not answer for: $MEM_EXTRA"
    [ -z "$MEM_MISSING" ] && [ -z "$MEM_EXTRA" ] \
        && echo "  $RULE matches the interpreter ($(wc -l < "$WORK/mem_source" | tr -d ' ') kind/member pairs)"
}

if [ -x bootstrap/algc ]; then
    bootstrap/algc spec/members.a24 2>/dev/null | sort -u > "$WORK/mem_all"

    check_matrix COL-003 COL-004
    check_matrix RT-021  RT-022
fi

# ⚠️ [ERR-010]'s warning is quoted in the document, and a message quoted and
# checked by nobody is exactly what the three checks above exist to prevent.
# spec/warning.a24 provokes it and the line is compared with the one the rule
# shows -- file, line number and wording together.
#
# ⚠️ The corpus CANNOT do this.  conform.sh drops [WARN] from both sides by
# design, because the front end is shared and the two processors raise the
# warning at different moments; so a conformance case can exercise the warning
# but can never see it.  This check is the only thing holding the wording.

if [ -x bootstrap/algc ]; then
    bootstrap/algc spec/warning.a24 2>/dev/null \
      | sed "s/$(printf '\033')\\[[0-9;]*m//g" \
      | grep '^\[WARN\]' > "$WORK/warn_actual" || true

    awk '/\*\*\[ERR-010\]\*\*/{f=1}
         f && /^\[WARN\] /{print; exit}' "$SPEC" > "$WORK/warn_spec"

    if [ ! -s "$WORK/warn_actual" ]; then
        problem "ERR-010 quotes a warning that spec/warning.a24 does not raise"
    elif [ ! -s "$WORK/warn_spec" ]; then
        problem "ERR-010 states no warning line to check"
    elif ! cmp -s "$WORK/warn_actual" "$WORK/warn_spec"; then
        problem "ERR-010's warning differs from the one raised:
      stated: $(cat "$WORK/warn_spec")
      raised: $(cat "$WORK/warn_actual")"
    else
        echo "  ERR-010 matches the warning algc raises"
    fi
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

    # ⚠️ Each of these counts the rules citing that KIND, and they overlap: a
    # rule may cite a conformance program for the half that works and a defect
    # for the half that does not, so they do not sum to the total.
    #
    # ⚠️ 'covered by conformance' was once computed as (total - TBD), which
    # measures how many rules are ACCOUNTED FOR rather than how many cite a
    # conformance program. While TBD was non-zero the number looked plausible;
    # when TBD reached zero it read '260 of 260' and claimed full conformance
    # coverage for a document where 64 rules cite only a refusal or a defect.
    echo "  pinned by a unit test:   $(wc -l < "$WORK/has_unit" | tr -d ' ') of $RULE_COUNT"
    echo "  cite a conformance program: $(( $(wc -l < "$WORK/has_conformance" | tr -d ' ') - TBD )) of $RULE_COUNT"
    echo "  cite a refusal:          $(wc -l < "$WORK/has_refusal" | tr -d ' ') of $RULE_COUNT"
    echo "  cite a defect:           $(wc -l < "$WORK/has_defect" | tr -d ' ') of $RULE_COUNT"
    echo "  accounted for:           $(wc -l < "$WORK/has_any" | tr -d ' ') of $RULE_COUNT (the gate; overlaps above)"

    if [ -s "$WORK/no_unit" ]; then
        echo "  no unit test pins these:"
        sed 's/^/    /' "$WORK/no_unit"
    fi
fi

# ⚠️ Which chapters still have rules with no case of their own.  'conformance
# TBD' is an honest admission rather than an error, so it does not fail the run
# -- but a per-chapter count is what says how much of the conformance pass is
# left, and a bare total does not.
#
# Every rule ends with exactly one of three, decided by ONE question -- is the
# interpreter right?  It refuses: a case in refusals/.  It is right: a case in
# conformance/.  It is wrong: a case in defects/.  What the compiler does never
# enters into it; see Annex C.

if [ "$GAPS_REPORT" -eq 1 ]; then
    echo
    echo "Rules still awaiting a case, by chapter"
    awk '/^## /{ chap = $0; sub(/^## /, "", chap) }
         /^\*\*\[[A-Z]+-[0-9]+\]\*\*/ {
             match($0, /\[[A-Z]+-[0-9]+\]/)
             id = substr($0, RSTART + 1, RLENGTH - 2)
             if (id ~ /-000$/) next
             cur = id; total[chap]++; order[++n] = chap
         }
         /^[ \t]+conformance[ \t]+TBD[ \t]*$/ {
             if (cur != "") { tbd[chap]++; ids[chap] = ids[chap] " " cur }
         }
         END {
             for (i = 1; i <= n; i++) {
                 c = order[i]
                 if (seen[c]) continue
                 seen[c] = 1
                 if (tbd[c] > 0)
                     printf "  %3d of %3d  %s\n     %s\n", tbd[c], total[c], c, ids[c]
             }
             for (i = 1; i <= n; i++) { c = order[i]; if (!done[c]) { done[c]=1; g += tbd[c]; r += total[c] } }
             printf "  %d of %d rules await a case.\n", g, r
         }' "$SPEC"
fi

echo
if [ "$FAILED" -ne 0 ]; then
    echo "FAIL: the specification cites things that do not exist."
    exit 1
fi

echo "OK: every citation resolves."
