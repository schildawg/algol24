#!/bin/sh
#
# test.sh -- runs the Algol-24 unit tests through the compiled compiler.
#
#   ./test.sh                        # every test the compiler can reach
#   ./test.sh compiler/Scanner.a24   # that file, and everything it imports
#   ./test.sh -q                     # the summary only, unless something fails
#
# Builds bootstrap/algc first if it is not there.  The tests are the 'test'
# blocks written beside the code they cover, and algc runs them instead of the
# program: the main block is never executed.
#
# ⚠️ THERE IS NO PER-TEST OR PER-FILE FILTER.  Naming a file runs every test
# block that file can REACH, its imports' included -- so asking for Parser.a24
# runs Scanner's and Token's too, and the count will be larger than the file's
# own.  compiler/Main.a24 imports everything, which is what makes it the
# complete suite rather than one more file.  The narrowest thing that can be
# run is a leaf module.
#
# ⚠️ A file that fails to PARSE reports nothing at all: the run ends on stderr
# with no report to summarise, and a count of zero tests is not the same as a
# clean run.  Both streams are shown for that reason.

set -eu

cd "$(dirname "$0")"

SUITE="compiler/Main.a24"
QUIET=0

while [ $# -gt 0 ]; do
    case "$1" in
        -q|--quiet) QUIET=1 ;;
        -h|--help)
            sed -n '2,/^set -eu/p' "$0" | sed 's/^#\{1,2\} \{0,1\}//; s/^#$//; /^set -eu$/d'
            exit 0 ;;
        -*)
            echo "test.sh: unknown option '$1'" >&2
            exit 2 ;;
        *)
            SUITE="$1" ;;
    esac
    shift
done

[ -f "$SUITE" ] || { echo "test.sh: no such file: $SUITE" >&2; exit 2; }

ALGC="bootstrap/algc"

if [ ! -x "$ALGC" ]; then
    echo "No compiler at $ALGC -- building it first."
    ./bootstrap/build.sh
    echo
fi

WORK=$(mktemp -d "${TMPDIR:-/tmp}/algol24-test.XXXXXX")
trap 'rm -rf "$WORK"' EXIT

REPORT="$WORK/report"
ERRORS="$WORK/errors"

# ⚠️ The two streams are captured SEPARATELY rather than merged.  The report
# goes to stdout and is buffered; a raise goes to stderr and is not, so merging
# them puts 'Uncaught: Tests failed.' above the report that explains it.
STATUS=0
"$ALGC" --test "$SUITE" > "$REPORT" 2> "$ERRORS" || STATUS=$?

if [ "$QUIET" -eq 0 ] || [ "$STATUS" -ne 0 ]; then
    cat "$REPORT"
fi

# Always shown when there is anything: on a parse failure this is the only
# account of what went wrong.
if [ -s "$ERRORS" ]; then
    [ "$QUIET" -eq 1 ] && [ "$STATUS" -eq 0 ] || echo
    cat "$ERRORS" >&2
fi

# The last [INFO] line of a completed run is its verdict -- 'All N tests
# passed.' or 'N of M tests failed.'
#
# ⚠️ Stripped before matching, never before printing.  The report is coloured
# unconditionally -- the interpreter has no way to ask whether it is talking to
# a terminal, so it always says so and readers strip -- which means a report
# line does not begin with '[' at all, and an anchored pattern matches nothing.
# The copy shown to the user keeps its escapes; only the copy being searched
# loses them.
#
# ⚠️ The escape is built with printf rather than written '\033' in the pattern.
# GNU sed reads that as an escape and BSD sed reads it as the four characters,
# so the substitution quietly does nothing on macOS -- the anchored grep below
# then matches no line and a run with failures reports as 'no tests ran'.
ESC=$(printf '\033')
SUMMARY=$(sed "s/${ESC}\\[[0-9;]*m//g" "$REPORT" \
          | grep -E '^\[INFO\] (All [0-9]+ tests passed|[0-9]+ of [0-9]+ tests failed)' \
          | tail -1 | sed 's/^\[INFO\] //' || true)

echo
if [ "$STATUS" -eq 0 ]; then
    echo "PASS  $SUITE -- ${SUMMARY:-no tests ran}"
    exit 0
fi

if [ -n "$SUMMARY" ]; then
    echo "FAIL  $SUITE -- $SUMMARY"
else
    # No report at all: the file did not get as far as running its tests.
    echo "FAIL  $SUITE -- no tests ran; see the error above (exit $STATUS)"
fi

exit 1
