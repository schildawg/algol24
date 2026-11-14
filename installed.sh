#!/bin/sh
#
# The INSTALLED LAYOUT, which no other harness reaches.
#
# Every other gate runs from the repository root with a program's modules beside
# it, so none of them asks the question a package manager asks: can a program in
# some other directory reach a unit that was installed somewhere else?  Two
# portability defects hid in that gap and neither was reachable from any of the
# 265 corpus cases:
#
#   - FolderOf cut a path at '/' alone, so a Windows binary -- whose own path
#     arrives with backslashes -- found no install prefix at all.
#
#   - FileExists OPENS the path, and fopen on a DIRECTORY succeeds on macOS and
#     Linux and fails on Windows, so a tested lib directory was found on two
#     platforms and not the third.
#
# ⚠️ IT WOULD HAVE CAUGHT NEITHER OF THOSE ON A UNIX, and that was checked
# rather than assumed: with the directory test put back, this script still
# passes 9 of 9 on macOS -- because fopen on a directory SUCCEEDS here, which
# is precisely why the defect reached Windows undetected.  So:
#
#   - run on Windows, where fopen on a directory fails, it has teeth for the
#     second defect, and the windows workflow runs it for that reason;
#
#   - the first defect is guarded platform-independently by a Parser unit test
#     that hands FolderOf a literal backslash, since no Unix path has one.
#
# What it does guard everywhere is the layout itself: that an installed unit is
# reachable by name at all, from both places a processor looks, under all three
# processors, and that a nearer unit still wins.  None of which any other gate
# asks.
#
# ⚠️ It builds a PREFIX rather than installing anything.  The processors answer
# from their own binary's path [MOD-002], so a copy of the binary in a scratch
# directory is a complete install as far as they are concerned -- and the test
# never touches the machine it runs on.
set -eu

ROOT=$(cd "$(dirname "$0")" && pwd)

[ -x "$ROOT/bootstrap/algc" ] || { echo "installed.sh: no bootstrap/algc -- run ./bootstrap/build.sh" >&2; exit 2; }

WORK=$(mktemp -d "${TMPDIR:-/tmp}/algol24-installed.XXXXXX")
trap 'rm -rf "$WORK"' EXIT

PASS=0
FAIL=0

check () {
    _what=$1; _want=$2; _got=$3

    if [ "$_got" = "$_want" ]; then
        PASS=$((PASS + 1))
    else
        FAIL=$((FAIL + 1))
        echo "  FAIL  $_what"
        echo "        wanted: $_want"
        echo "        got:    $_got"
    fi
}

# The unit an install provides, which the program will reach by its bare name.
unit_into () {
    mkdir -p "$1"
    cat > "$1/Greeting.a24" <<'UNIT'
/// A unit that exists only where it was installed.
unit Greeting;

/// Answers where it was found from, to prove which copy answered.
function Where () : String;
begin
    Exit 'installed';
end
UNIT
}

# ⚠️ TWO LAYOUTS, because the processors look in two places and only one of
# them was ever exercised by hand.  `lib` beside the binary is what the
# Homebrew formula makes; `bin/../share/algol24/lib` is the layout a package
# manager makes, and nothing had tried it at all.
for LAYOUT in beside share; do
    P="$WORK/$LAYOUT"
    mkdir -p "$P/bin"

    cp "$ROOT/bootstrap/algc" "$P/bin/"
    [ -x "$ROOT/vm/algvm" ] && cp "$ROOT/vm/algvm" "$P/bin/"

    case $LAYOUT in
        beside)
            unit_into "$P/bin/lib"
            # The runtime goes beside the binary too, which is where
            # RuntimeFolder looks first -- and RuntimeFolder had the same
            # separator defect, so --compile exercises it.
            cp "$ROOT/bootstrap/algol.c" "$ROOT/bootstrap/algol.h" "$P/bin/"
            ;;
        share)
            unit_into "$P/share/algol24/lib"
            mkdir -p "$P/share/algol24"
            cp "$ROOT/bootstrap/algol.c" "$ROOT/bootstrap/algol.h" "$P/share/algol24/"
            ;;
    esac

    # A directory with none of the library's files in it, which is the whole
    # point: the module is reached by its name and not by its path.
    mkdir -p "$P/work"
    printf "uses Greeting;\n\nWriteLn (Where ());\n" > "$P/work/prog.a24"

    cd "$P/work"

    check "$LAYOUT: interpreted" "installed" "$("$P/bin/algc" prog.a24 2>&1 | tail -1)"

    if [ -x "$P/bin/algvm" ]; then
        check "$LAYOUT: the machine" "installed" "$("$P/bin/algvm" prog.a24 2>&1 | tail -1)"
    fi

    # The COMPILED back end resolves modules at parse time like the others, and
    # emitting also asks RuntimeFolder for the runtime to copy in -- so this one
    # case covers both questions the binary's own path answers.
    mkdir -p "$P/work/out"

    if "$P/bin/algc" --compile --out="$P/work/out" prog.a24 >/dev/null 2>&1 &&
       "${CC:-cc}" -std=c11 -O2 -o "$P/work/prog" "$P/work/out"/*.c >/dev/null 2>&1; then
        check "$LAYOUT: compiled" "installed" "$("$P/work/prog" 2>&1 | tail -1)"
    else
        FAIL=$((FAIL + 1))
        echo "  FAIL  $LAYOUT: compiled -- did not emit or did not build"
    fi

    cd "$ROOT"
done

# ⚠️ NEARER WINS, and it is the half that keeps an install from changing what a
# program already means.  A unit beside the program must beat an installed one
# of the same name.
P="$WORK/beside"
cat > "$P/work/Greeting.a24" <<'UNIT'
/// A unit beside the program, which must win.
unit Greeting;

/// Answers where it was found from.
function Where () : String;
begin
    Exit 'beside the program';
end
UNIT

cd "$P/work"
check "nearer wins: interpreted" "beside the program" "$("$P/bin/algc" prog.a24 2>&1 | tail -1)"

if [ -x "$P/bin/algvm" ]; then
    check "nearer wins: the machine" "beside the program" "$("$P/bin/algvm" prog.a24 2>&1 | tail -1)"
fi

cd "$ROOT"

# And a module in NEITHER place names every place it looked, which is the
# diagnostic that found the second defect: an empty candidate list silently
# dropped a clause, so the message said which question had gone unanswered.
cd "$P/work"
printf "uses Nowhere;\n" > miss.a24
MISS=$("$P/bin/algc" miss.a24 2>&1 | head -1)
cd "$ROOT"

case $MISS in
    *"no Nowhere.a24 in"*"lib'"*) PASS=$((PASS + 1)) ;;
    *) FAIL=$((FAIL + 1))
       echo "  FAIL  a missing module names the installed folder"
       echo "        got: $MISS" ;;
esac

# ---------------------------------------------------------- a unit's shim --
#
# ⚠️ A UNIT THAT CALLS INTO C NEEDS ITS SHARED OBJECT FOUND TOO [FUN-017], and
# this is the only harness that can ask.  A module path that resolves the
# source and then fails at the first foreign call is the half-measure
# finished/PROPOSAL-LIBRARY-PATH.md predicted, and every other gate assumes it away by
# running from the repository root with everything beside it.  Measured before
# the search existed: a bare `dlopen` from the program's own directory does not
# find a library installed in the prefix, on any of the three platforms.
#
# ⚠️ IT BUILDS ITS OWN --ffi algc AND NEVER USES bootstrap/algc, because one of
# those fails 0174, 0210 and 0225 under the main corpus -- the trap vm/conform.sh
# avoids the same way.
#
# ⚠️ SKIPPED RATHER THAN FAILED where libffi or a shared library cannot be
# built here.  The bootstrap needs a C compiler and nothing else, so a gate
# that demanded libffi would make that untrue -- and this script runs in the
# windows workflow, where neither the link flags nor the suffix are the Unix
# ones.
case $(uname -s 2>/dev/null || echo unknown) in
    Darwin) SHIM=libprobeffi.dylib; GONE_SHIM=libnowhereffi.dylib
            SHIM_FLAGS="-dynamiclib" ;;
    Linux)  SHIM=libprobeffi.so;    GONE_SHIM=libnowhereffi.so
            SHIM_FLAGS="-shared -fPIC" ;;
    *)      SHIM=libprobeffi.dll;   GONE_SHIM=libnowhereffi.dll
            SHIM_FLAGS="-shared" ;;
esac

P="$WORK/shim"
mkdir -p "$P/bin" "$P/share/algol24/lib" "$P/work"

cat > "$WORK/probe.c" <<'C'
/* The whole of the C a unit needs, so that what is under test is where the
   shared object was found and nothing else. */
int alg_probe_twice(int n) { return n * 2; }
C

if "${CC:-cc}" -std=c11 -O2 -DALG_FFI -o "$P/bin/algc" "$ROOT"/bootstrap/*.c -lffi \
        > "$WORK/shim.log" 2>&1 &&
   "${CC:-cc}" $SHIM_FLAGS -o "$P/share/algol24/lib/$SHIM" "$WORK/probe.c" \
        >> "$WORK/shim.log" 2>&1; then

    cat > "$P/share/algol24/lib/Probe.a24" <<UNIT
/// A unit whose work is done in C, installed with its shim beside it.
unit Probe;

/// Doubles a number, in C.
function Twice (N : Integer) : Integer;
    external 'alg_probe_twice' in '$SHIM';
UNIT

    printf "uses Probe;\n\nWriteLn (Twice (21));\n" > "$P/work/prog.a24"

    # The library name holds no separator, so it is SEARCHED: the unit is
    # found by its name and the shim beside it, from a directory holding
    # neither.
    cd "$P/work"
    check "a shim is found where its unit is" "42" \
          "$("$P/bin/algc" prog.a24 2>&1 | tail -1)"

    # And a shim that is nowhere names the places it looked, which is the
    # whole of that diagnostic's job: the commonest cause is a library
    # installed somewhere the processor does not look, and a message naming
    # only the library cannot tell that from one never installed.
    printf "function Gone (N : Integer) : Integer;\n    external 'alg_probe_twice' in '%s';\n\nWriteLn (Gone (1));\n" \
        "$GONE_SHIM" > "$P/work/miss.a24"

    GONE=$("$P/bin/algc" miss.a24 2>&1 | head -1)
    cd "$ROOT"

    case $GONE in
        *"Cannot open foreign library '$GONE_SHIM'"*"the system looks."*)
            PASS=$((PASS + 1)) ;;
        *) FAIL=$((FAIL + 1))
           echo "  FAIL  a missing shim names the places it looked"
           echo "        got: $GONE" ;;
    esac
else
    cd "$ROOT"
    echo "  note: no --ffi algc or no shared library here, so [FUN-017] goes unasked"
fi

echo
echo "the installed layout:  $PASS passed, $FAIL failed."

[ "$FAIL" -eq 0 ] || exit 1

echo
echo "OK: a program reaches an installed unit by name, from a directory holding"
echo "    none of its files, and a nearer unit of that name still wins."
