#!/usr/bin/env bash
#
# Name-collision mutation harness.
#
#   ./collide.sh                          # 24 mutants, both compilers
#   ./collide.sh --only object-root-private   # just that one -- a failure prints this
#   ./collide.sh --keep                   # leave the generated tree behind to read
#
# ⚠️ This is a different KIND of check from every other gate here, and the
# difference is the point.  ctest, gate and cgate take programs that are expected
# to work and compare implementations; refuse.sh takes programs a compiler is
# expected to decline.  None of them varies a program along an axis the language
# allows and asserts an invariant -- so a program that is legal, runs correctly
# interpreted, and emits C that cc or ld then rejects was invisible to all of
# them.  Four findings were exactly that shape (C17, C19, C20, C21), and each
# was found by hand.
#
# The axis is NAMES, because per-file emission makes a name the only way one
# file's C can conflict with another's.  From one seed with no bug in it, this
# builds 24 mutants -- six declaration kinds x {root, module} x {public,
# private} -- each shadowing a name its own import exports.
#
# ⚠️ THE ORACLE IS THE NEGATIVE ONE.  Stated as "the interpreter runs it, so the
# compiler must build it" this reports failures that are section 9 doing its job:
# a named refusal is a documented narrowing and is legal.  What is never legal is
# emitting C and then having cc or ld reject it:
#
#     interpreter refuses  ->  the compiler must refuse too, not emit
#     interpreter runs     ->  the compiler must EITHER refuse by name
#                              OR emit C that builds and matches the interpreter
#
# ⚠️ AND A SECOND CLAUSE: THE PARTITION IS A RULE, NOT A LIST.  Over-refusal is
# permitted by the oracle above -- refusing a legal program is "safe" -- so it
# needs a second opinion to be caught, and for a while the only one here was the
# other compiler.  It does not have to be: the 24 outcomes are ONE rule.
#
#     refused  <=>  host == module && visibility == public
#
# That is section 9's `Two modules exporting 'X'` row and nothing else.  A
# root-hosted collision builds because the root's symbols are static; a private
# one builds because a private has no cross-file reader.  So a pinned expectation
# is a second opinion, and a single compiler can hold it.
#
# ⚠️ The rule checks the SENTENCE too, not just the bucket.  Asserting only
# "module-and-public is refused" goes stale in silence if section 9 ever gains a
# second collision-shaped refusal: a mutant refused for the NEW reason would
# still be in the right bucket and the assertion would pass for the wrong reason.
# Requiring the words as well means a new refusal either moves a mutant (clause
# one fails) or changes what it says (clause two fails).  Keep both in step with
# section 9.
#
# ⚠️ BOTH COMPILERS WHEN BOTH ARE PRESENT, AND THE BUCKETS ARE COMPARED.  That
# is a third check, not the only one: it catches a divergence the partition rule
# cannot, where the two compilers disagree and BOTH are self-consistent.  The
# published repo has one compiler and runs the first two clauses; that is the
# half which found five of this axis's six detections, and the partition rule
# catches the sixth.
#
# ⚠️ A mutant that fails here is not a fixture.  This is the SEARCH; the corpus
# is the pinned record.  Promote a failing mutant into ctest/ or refuse/ by hand
# once it has failed, so the harness stays adversarial and the regression stays
# nailed down.  Checking in all 24 would grow the corpus with cases that never
# fail and that nobody reads.

set -uo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
JAR="$ROOT/target/jpascal.jar"
WORK="${TMPDIR:-/tmp}/collide.$$"

# ⚠️ Layout-derived, not hardcoded to this repo's -- the mistake depth.sh
# shipped with and the reviewer found by running it where it was published.
[ -z "${ALGC:-}" ] && { [ -x "$ROOT/algc.exe" ] && ALGC="$ROOT/algc.exe" || ALGC="$ROOT/algc"; }
if [ -z "${RUNTIME:-}" ]; then
    if   [ -f "$ROOT/src/main/resources/runtime/algol.h" ]; then RUNTIME="$ROOT/src/main/resources/runtime"
    elif [ -f "$ROOT/bootstrap/algol.h" ];                  then RUNTIME="$ROOT/bootstrap"
    fi
fi

KEEP=0
ONLY=""
while [ $# -gt 0 ]; do
    case "$1" in
        --keep) KEEP=1; shift ;;
        --only) ONLY="${2:-}"; shift 2 ;;
        *)      echo "Usage: $0 [--only KIND-HOST-VISIBILITY] [--keep]"; exit 64 ;;
    esac
done

if [ ! -x "$ALGC" ]; then echo "Missing $ALGC -- run: ./build-algc.sh"; exit 1; fi

# ⚠️ JPascal is OPTIONAL, and its absence is a MODE rather than an error.  The
# published repo has one compiler, so the bucket diff cannot run there -- but the
# violation oracle and the partition rule below both work with one, and together
# they caught all six of this axis's findings.  Without this the sibling had no
# collision search at all.
BOTH=1
[ -f "$JAR" ] || BOTH=0

# ⚠️ The third prerequisite, and it used to be the only one unchecked -- the
# same hole depth.sh had.  A missing runtime becomes one 'cc' error per mutant,
# each reading like an emitter regression rather than a missing file.  THE
# HARNESS FAILING TO RUN AND A MUTANT FAILING ARE DIFFERENT EVENTS, and only the
# second is a finding.
if [ ! -f "$RUNTIME/algol.h" ]; then
    echo "Missing the C runtime: no algol.h under '$RUNTIME'."
    exit 1
fi

mkdir -p "$WORK"
[ "$KEEP" -eq 0 ] && trap 'rm -rf "$WORK"' EXIT

# One declaration of the given kind, named $2, whose value or tag is $3 -- so the
# two copies of a mutant are distinguishable in the output.
declaration() {
    case "$1" in
        var)      printf 'var %s := %s%s%s;\n' "$2" "'" "$3" "'" ;;
        const)    printf 'const %s := %s%s%s;\n' "$2" "'" "$3" "'" ;;
        function) printf 'function %s () : String;\nbegin\n    Exit %s%s%s;\nend\n' "$2" "'" "$3" "'" ;;
        class)    printf 'class %s;\nbegin\n    function Tag () : String;\n    begin\n        Exit %s%s%s;\n    end\nend\n' "$2" "'" "$3" "'" ;;
        object)   printf 'object %s;\nbegin\n    function Tag () : String;\n    begin\n        Exit %s%s%s;\n    end\nend\n' "$2" "'" "$3" "'" ;;
        enum)     printf 'type %s = (M%s, N%s);\n' "$2" "$3" "$3" ;;
    esac
}

# The refusal message with each driver's framing stripped, as refuse.sh does it.
sentence() {
    echo "$1" | grep -E '^(\[ERROR\]|Uncaught:)' | head -1 \
        | sed -E 's/^\[ERROR\] //; s/^Uncaught: //; s|^[^ ]*: ||; s/^ *//'
}

# Runs one mutant under one compiler and echoes its bucket:
#   refused:…   a named refusal, or the front end declining -- legal either way,
#               carrying its sentence, because WHICH refusal matters below
#   built       emitted, built, and matched the interpreter
#   VIOLATION:… emitted something cc or ld rejected, or disagreed with interpreted
classify() {
    local dir="$1" run="$2" compile="$3" out expected emitted

    expected=$($run "$dir/Root.a24" 2>&1 | sed -E $'s/\033\\[[0-9;]*m//g')

    rm -rf "$dir/out"; mkdir -p "$dir/out"
    emitted=$($compile "$dir/out" "$dir/Root.a24" 2>&1 | sed -E $'s/\033\\[[0-9;]*m//g')

    # The interpreter refused it, so the compiler must too.
    if echo "$expected" | grep -qE '^(\[ERROR\]|Uncaught:)'; then
        if echo "$emitted" | grep -qE '^(\[ERROR\]|Uncaught:)'; then echo "refused:$(sentence "$emitted")"; return; fi

        echo "VIOLATION: interpreter refused, compiler emitted"; return
    fi

    if echo "$emitted" | grep -qE '^(\[ERROR\]|Uncaught:)'; then echo "refused:$(sentence "$emitted")"; return; fi

    cp "$RUNTIME/algol.c" "$RUNTIME/algol.h" "$dir/out/" 2>/dev/null

    if ! cc -std=c11 -O1 -o "$dir/binary" "$dir"/out/*.c 2>"$dir/cc.log"; then
        echo "VIOLATION: emitted, then $(grep -oE '(error|ld): .*' "$dir/cc.log" | head -1)"; return
    fi

    out=$("$dir/binary" 2>&1)
    if [ "$out" != "$expected" ]; then
        echo "VIOLATION: compiled '$out' vs interpreted '$expected'"; return
    fi
    echo "built"
}

jpascal_run()     { java -jar "$JAR" "$1" 2>&1 | sed -n '/RUNNING/,$p' | tail -n +2; }
jpascal_compile() { java -jar "$JAR" --compile "--out=$1" "$2"; }
algc_run()        { "$ALGC" "$1"; }
algc_compile()    { "$ALGC" --compile "--out=$1" "$2"; }

violations=0
divergences=0
built=0
refused=0

for kind in var const function class object enum; do
for host in root module; do
for visibility in public private; do
    name="${kind}-${host}-${visibility}"
    [ -n "$ONLY" ] && [ "$ONLY" != "$name" ] && continue

    dir="$WORK/$name"
    mkdir -p "$dir/lib"

    private=""
    [ "$visibility" = private ] && private="private "

    { echo "unit A;"; echo; declaration "$kind" Clash unit; } > "$dir/lib/A.a24"

    if [ "$host" = root ]; then
        {   echo "uses 'lib/A';"; echo
            printf '%s' "$private"; declaration "$kind" Clash mine; echo
            echo "begin"; echo "    WriteLn ('ok');"; echo "end"
        } > "$dir/Root.a24"
    else
        {   echo "unit B;"; echo; echo "uses A;"; echo
            printf '%s' "$private"; declaration "$kind" Clash mine
        } > "$dir/lib/B.a24"
        {   echo "uses 'lib/B';"; echo
            echo "begin"; echo "    WriteLn ('ok');"; echo "end"
        } > "$dir/Root.a24"
    fi

    j=""
    if [ "$BOTH" -eq 1 ]; then
        j=$(classify "$dir" jpascal_run jpascal_compile)
        rm -rf "$dir/out" "$dir/binary"
    fi
    a=$(classify "$dir" algc_run algc_compile)

    for side in "JPascal:$j" "algc:$a"; do
        case "${side#*:}" in
            VIOLATION*)
                echo "FAIL  $name -- ${side%%:*} ${side#*:}"
                echo "      reproduce: $0 --only $name --keep"
                violations=$((violations + 1)) ;;
        esac
    done

    # Clause two: the partition rule, which needs no second compiler.
    #
    # ⚠️ THE REFUSAL MUST BE THE COLLISION ONE.  A mutant refused for some other
    # reason is in the right bucket for the wrong cause, which is how this would
    # rot without anyone noticing.
    for side in "JPascal:$j" "algc:$a"; do
        who="${side%%:*}"; got="${side#*:}"
        [ "$who" = JPascal ] && [ "$BOTH" -eq 0 ] && continue
        [[ "$got" == VIOLATION* ]] && continue

        if [ "$host" = module ] && [ "$visibility" = public ]; then
            case "$got" in
                refused:Two\ modules\ exporting*) ;;
                refused:*) echo "FAIL  $name -- $who refused it, but for the wrong reason: ${got#refused:}"
                           echo "      reproduce: $0 --only $name --keep"
                           violations=$((violations + 1)) ;;
                *)         echo "FAIL  $name -- $who $got, but section 9 says two modules exporting one name is refused"
                           echo "      reproduce: $0 --only $name --keep"
                           violations=$((violations + 1)) ;;
            esac
        else
            case "$got" in
                refused:*) echo "FAIL  $name -- $who refused a legal program: ${got#refused:}"
                           echo "      reproduce: $0 --only $name --keep"
                           violations=$((violations + 1)) ;;
            esac
        fi
    done

    # Clause three: the two compilers against each other.  It catches what the
    # partition rule cannot -- a disagreement where both are self-consistent.
    if [ "$BOTH" -eq 1 ] && [ "$j" != "$a" ] && [[ "$j" != VIOLATION* ]] && [[ "$a" != VIOLATION* ]]; then
        echo "DIFF  $name -- JPascal $j, algc $a"
        echo "      reproduce: $0 --only $name --keep"
        divergences=$((divergences + 1))
    fi

    [ "$BOTH" -eq 1 ] && probe="$j" || probe="$a"
    [ "$probe" = built ]      && built=$((built + 1))
    [[ "$probe" == refused* ]] && refused=$((refused + 1))
done; done; done

echo
[ "$BOTH" -eq 1 ] && mode="both compilers" || mode="one compiler -- no bucket diff"
echo "collide: $built built and matched, $refused refused by name, \
$violations violations, $divergences bucket differences ($mode)"

[ "$KEEP" -eq 1 ] && echo "kept: $WORK"
[ "$violations" -eq 0 ] && [ "$divergences" -eq 0 ] && exit 0
exit 70
