#!/bin/sh
#
# collector.sh -- runs the collector corpus, plainly and under poisoning.
#
#   ./collector.sh            # every case, both ways -- both must pass
#   ./collector.sh --record   # write .out from what happens
#   ./collector.sh --limit N  # seconds a single run may take (default 120)
#
# ⚠️ THE COMPILED BACK END ONLY, which was the RULE when the interpreter
# declined and is now merely where these cases happen to run.  All three
# processors collect, so there would be something to compare -- worth
# revisiting if a case here ever needs to be about more than the compiled
# path.  The corpus under ./conform.sh is where the processors are held to
# each other.
#
# ⚠️ EVERY CASE RUNS THREE WAYS, because the bugs this guards against divide
# exactly along those lines:
#
#   plainly          a released body is handed back out.  This is where a
#                    collector that frees something live corrupts quietly --
#                    the program fails somewhere else entirely, or not at all.
#   ALG_POISON=1     a released body is retagged and never reused, and the
#                    first use of one faults where it is used, naming the kind
#                    and the site.
#   ALG_TEXT_CHECK=1 every cached text length is recomputed where the cache
#                    answers it, so a recycled block that kept an earlier
#                    string's answer faults rather than returning a plausible
#                    number.
#
# Three bugs in the hunt that produced these cases had the same signature --
# "poisoning works, reuse does not" -- so a case that passes one way and fails
# the other is the most informative result this script can give, and it reports
# which way round it was.
#
# ⚠️ THE THIRD WAY IS A DIAGNOSTIC AS MUCH AS A GATE, and that is worth being
# honest about: nothing in this repository's harnesses trips it today, because
# the coincidence it catches -- a block recycled at the same address with its
# cache entry still live -- is one a small program does not reach.  D-3 was
# found by a program in another project rendering half a megabyte of text, and
# three probes written to reproduce it guessed wrong first.  0007 is the
# REGRESSION gate; this is what makes the NEXT one of its class cost one run
# instead of an afternoon.
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

    # And checked: every cached text length is recomputed where the cache
    # answers, so a recycled block that kept an earlier string's answer faults
    # instead of returning a plausible number.
    ALG_TEXT_CHECK=1 run_bounded "$WORK/checked" "$_dir/prog"
    _checked=$?

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
    [ "$_checked"  -eq 137 ] && _why="hung for more than ${LIMIT}s, text-checked"

    if [ -z "$_why" ] && [ "$_plain" -ne 0 ]; then
        _why="exit $_plain, plainly"
    fi

    if [ -z "$_why" ] && [ "$_poisoned" -ne 0 ]; then
        _why="exit $_poisoned, poisoned"
    fi

    if [ -z "$_why" ] && [ "$_checked" -ne 0 ]; then
        _why="exit $_checked, text-checked"
    fi

    if [ -z "$_why" ] && ! cmp -s "$WORK/plain" "$_want"; then
        _why='wrong output, plainly'
    fi

    if [ -z "$_why" ] && ! cmp -s "$WORK/poisoned" "$_want"; then
        _why='wrong output, poisoned'
    fi

    if [ -z "$_why" ] && ! cmp -s "$WORK/checked" "$_want"; then
        _why='wrong output, text-checked'
    fi

    if [ -n "$_why" ]; then
        echo "  FAIL  $_name -- $_why"

        case $_why in
            *text-checked)
                sed 's/^/           /' "$WORK/checked" | head -12
                ;;
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

# ── The scale check ───────────────────────────────────────────────────────
#
# ⚠️ A TEXT LEAK IS INVISIBLE TO OUTPUT, so comparing what a program prints
# cannot catch one.  `flat-text.a24` takes a round count instead and is run at
# two scales ten times apart: the memory the runtime reports must be the SAME,
# which is the property a leak breaks and an allocator's own choices do not.
#
# The small scale is 20,000 rather than 2,000 because the heap has to reach
# steady state first -- 2,000 rounds peaks BELOW the figure it settles on, so
# comparing against it would read a leak as the heap merely warming up.
check_flat () {
    _src=collector/flat-text.a24
    _dir=$WORK/flat

    mkdir -p "$_dir"

    if ! "$ALGC" --compile --out="$_dir" "$_src" > "$WORK/emit" 2>&1; then
        echo "  FAIL  flat-text -- did not compile"
        sed 's/^/           /' "$WORK/emit"
        FAIL=$((FAIL + 1))
        return
    fi

    if ! cc -std=c11 -O2 -o "$_dir/prog" "$_dir"/*.c > "$WORK/cc" 2>&1; then
        echo "  FAIL  flat-text -- the emitted C did not build"
        sed 's/^/           /' "$WORK/cc"
        FAIL=$((FAIL + 1))
        return
    fi

    for _scale in 20000 200000; do
        ALG_MEM_REPORT=1 run_bounded "$WORK/flat-$_scale" "$_dir/prog" "$_scale"

        if [ $? -ne 0 ]; then
            echo "  FAIL  flat-text -- $_scale rounds did not run"
            sed 's/^/           /' "$WORK/flat-$_scale" | head -8
            FAIL=$((FAIL + 1))
            return
        fi
    done

    _small=$(awk '/\[mem\] text:/ { for (i = 1; i < NF; i++) if ($(i + 1) == "MB" && $(i + 2) == "room") print $i }
                  /\[mem\] arena:/ { print $3 }' "$WORK/flat-20000" | tr '\n' ' ')
    _large=$(awk '/\[mem\] text:/ { for (i = 1; i < NF; i++) if ($(i + 1) == "MB" && $(i + 2) == "room") print $i }
                  /\[mem\] arena:/ { print $3 }' "$WORK/flat-200000" | tr '\n' ' ')

    if [ -z "$_small" ] || [ "$_small" != "$_large" ]; then
        echo "  FAIL  flat-text -- ten times the work cost more memory"
        echo "           20,000 rounds: text room and arena, in MB: $_small"
        echo "          200,000 rounds: text room and arena, in MB: $_large"
        FAIL=$((FAIL + 1))
        return
    fi

    echo "  PASS  flat-text -- text room and arena unchanged at ${_large}MB, 10x the work"
    PASS=$((PASS + 1))
}

found=$(find collector -maxdepth 1 -name '[0-9]*.a24' 2>/dev/null | sort)

if [ -z "$found" ]; then
    echo "collector.sh: no cases in collector/" >&2
    exit 2
fi

echo "collector"

for src in $found; do
    check "$src"
done

if [ "$RECORD" -eq 0 ]; then check_flat; fi

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
echo "    whether a released body is reused or withheld -- and every cached"
echo "    text length agrees with the bytes it was cached for."
