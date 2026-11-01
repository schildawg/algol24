#!/bin/sh
#
# collector.sh -- runs the collector corpus, plainly and under poisoning.
#
#   ./collector.sh            # every case, both ways -- both must pass
#   ./collector.sh --record   # write .out from what happens
#   ./collector.sh --limit N  # seconds a single run may take (default 120)
#
# ⚠️ THE COMPILED BACK END ONLY, and that is not an omission.  `Collect` is a
# REQUEST [RT-029]: the interpreter answers 0 because its live values sit in C
# locals all through a recursive evaluator, where no collector can see them, so
# declining is the conformant answer and there is nothing here to compare it
# against.  The corpus under ./conform.sh is where the two processors are held
# to each other; this asks a question only one of them answers.
#
# ⚠️ EVERY CASE RUNS TWICE, because the bugs this guards against divide exactly
# along that line:
#
#   plainly          a released body is handed back out.  This is where a
#                    collector that frees something live corrupts quietly --
#                    the program fails somewhere else entirely, or not at all.
#   ALG_POISON=1     a released body is retagged and never reused, and the
#                    first use of one faults where it is used, naming the kind
#                    and the site.
#
# Three bugs in the hunt that produced these cases had the same signature --
# "poisoning works, reuse does not" -- so a case that passes one way and fails
# the other is the most informative result this script can give, and it reports
# which way round it was.
#
# ⚠️ A FAILURE MAY BE A HANG rather than wrong output, which is why each run is
# bounded.  0004 guards a released TextFile that stayed linked in `all_files`
# with its `next` overwritten; the symptom was `close_open_files` walking in a
# circle at exit, spinning at full CPU, still going after twenty-six minutes.
# Comparing output alone would wait for it forever.

set -u

LIMIT=120
RECORD=0

while [ $# -gt 0 ]; do
    case $1 in
        --record) RECORD=1 ;;
        --limit)  shift; LIMIT=$1 ;;
        *) echo "collector.sh: unknown option '$1'" >&2; exit 2 ;;
    esac
    shift
done

ALGC=bootstrap/algc

if [ ! -x "$ALGC" ]; then
    echo "collector.sh: $ALGC is not built -- run ./bootstrap/build.sh" >&2
    exit 2
fi

WORK=$(mktemp -d "${TMPDIR:-/tmp}/algol24-collector.XXXXXX")
trap 'rm -rf "$WORK"' EXIT INT TERM

PASS=0
FAIL=0
RECORDED=0

# Runs a command with a wall-clock bound, because `timeout` is not portable to
# the platform this is developed on.  Answers the command's status, or 137 when
# the watchdog took it.
run_bounded () {
    _out=$1; shift

    "$@" > "$_out" 2>&1 &
    _pid=$!

    ( sleep "$LIMIT"; kill -9 "$_pid" 2>/dev/null ) &
    _dog=$!

    wait "$_pid" 2>/dev/null
    _status=$?

    kill -9 "$_dog" 2>/dev/null
    wait "$_dog" 2>/dev/null

    return $_status
}

# Compiles one case and runs it both ways.
check () {
    _src=$1
    _want=${_src%.a24}.out
    _name=$(basename "$_src" .a24)

    _dir=$WORK/$_name
    mkdir -p "$_dir"

    if ! "$ALGC" --compile --out="$_dir" "$_src" > "$WORK/emit" 2>&1; then
        echo "  FAIL  $_name -- did not compile"
        sed 's/^/           /' "$WORK/emit"
        FAIL=$((FAIL + 1))
        return
    fi

    if ! cc -std=c11 -O2 -o "$_dir/prog" "$_dir"/*.c > "$WORK/cc" 2>&1; then
        echo "  FAIL  $_name -- the emitted C did not build"
        sed 's/^/           /' "$WORK/cc"
        FAIL=$((FAIL + 1))
        return
    fi

    # Plainly first: a released body is handed back out here.
    run_bounded "$WORK/plain" "$_dir/prog"
    _plain=$?

    # And poisoned: a released body is withheld and its first use faults.
    ALG_POISON=1 run_bounded "$WORK/poisoned" "$_dir/prog"
    _poisoned=$?

    if [ "$RECORD" -eq 1 ]; then
        if [ "$_plain" -eq 0 ]; then
            cp "$WORK/plain" "$_want"
            echo "  wrote $(basename "$_want")"
            RECORDED=$((RECORDED + 1))
        else
            echo "  SKIP  $_name -- exit $_plain, so there is nothing to record"
        fi
        return
    fi

    if [ ! -f "$_want" ]; then
        echo "  FAIL  $_name -- no $(basename "$_want"); run ./collector.sh --record"
        FAIL=$((FAIL + 1))
        return
    fi

    _why=''

    [ "$_plain"    -eq 137 ] && _why="hung for more than ${LIMIT}s, plainly"
    [ "$_poisoned" -eq 137 ] && _why="hung for more than ${LIMIT}s, poisoned"

    if [ -z "$_why" ] && [ "$_plain" -ne 0 ]; then
        _why="exit $_plain, plainly"
    fi

    if [ -z "$_why" ] && [ "$_poisoned" -ne 0 ]; then
        _why="exit $_poisoned, poisoned"
    fi

    if [ -z "$_why" ] && ! cmp -s "$WORK/plain" "$_want"; then
        _why='wrong output, plainly'
    fi

    if [ -z "$_why" ] && ! cmp -s "$WORK/poisoned" "$_want"; then
        _why='wrong output, poisoned'
    fi

    if [ -n "$_why" ]; then
        echo "  FAIL  $_name -- $_why"

        case $_why in
            *poisoned)
                sed 's/^/           /' "$WORK/poisoned" | head -12
                ;;
            *)
                diff "$_want" "$WORK/plain" 2>/dev/null | sed 's/^/           /' | head -12
                ;;
        esac

        FAIL=$((FAIL + 1))
        return
    fi

    echo "  PASS  $_name"
    PASS=$((PASS + 1))
}

found=$(find collector -maxdepth 1 -name '*.a24' 2>/dev/null | sort)

if [ -z "$found" ]; then
    echo "collector.sh: no cases in collector/" >&2
    exit 2
fi

echo "collector"

for src in $found; do
    check "$src"
done

echo

if [ "$RECORD" -eq 1 ]; then
    echo "$RECORDED expectation(s) written."
    exit 0
fi

echo "the collector: $PASS passed, $FAIL failed."

if [ "$FAIL" -gt 0 ]; then
    echo
    echo "A collector failure is a wrong answer about memory the program still"
    echo "holds, or a hang.  Neither is a gap to be accepted: read whether it"
    echo "failed plainly or poisoned first, because that says whether marking"
    echo "or reuse is at fault."
    exit 1
fi

echo
echo "OK: every case keeps what it holds and releases what it does not,"
echo "    whether a released body is reused or withheld."
