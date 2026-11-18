#!/bin/sh
# vm/image.sh -- runs the corpus from a bytecode image and compares it with the
# same corpus compiled.
#
#     ./bootstrap/build.sh && vm/image.sh
#
# The question is narrower than vm/conform.sh's and the oracle is different:
# not "does the machine answer what the specification records" but "does a
# program loaded from a file answer what the same program compiled answers".
# So the expectation is the machine's OWN output from source, case by case,
# and a fixture is never read.
#
# ⚠️ THAT IS THE ONLY ORACLE THAT ANSWERS THIS, which is worth saying because
# comparing against the fixtures looks equivalent and is not.  A case the
# emitter refuses by name has no recorded output to compare, and a case whose
# fixture records a build without foreign calls has one that describes neither
# run -- both of which vm/conform.sh has to work around.  Against the machine
# itself, a refusal compares to the same refusal and the workarounds are not
# needed at all.
#
# Three outcomes, and only the last is a failure:
#
#   identical         the image answers exactly what the compile answers
#   refused before    the program never compiled -- a refusals/ case, or an
#   emitting          opcode the emitter lacks -- so there is no image to load,
#                     and what is compared is that --emit refuses it the same
#                     way a run does
#   not applicable    the case asks to be run some way the machine has not got
#   DIVERGED          the image answered something else
#
# ⚠️ AN IMAGE IS A SEPARATE FILE AND THE PROGRAM CAN SEE THAT, which bounds
# what this can check.  ParamStr (0) is the image's path where a compiled run
# answers the source's [RT-013], so a case printing its own name would diverge
# over a path.  Two cases reach for it and both ask only whether it is
# non-empty, which is why nothing here has to render it away -- a case that
# printed it would need the same treatment render() gives a [WARN].
#
# Written in sh and awk like every other harness here.
set -eu

CC="${CC:-cc}"
CFLAGS="${CFLAGS:--std=c11 -O2}"
ALGC="${ALGC:-bootstrap/algc}"
WORK="${WORK:-$(mktemp -d)}"

[ -x "$ALGC" ] || { echo "no $ALGC -- run ./bootstrap/build.sh first" >&2; exit 1; }

ESC=$(printf '\033')
BEL=$(printf '\007')

# conform.sh's own rendering, kept identical on purpose: a rule applied to one
# of these harnesses has to be applied to the others, and three copies that
# agree are easier to keep in step than one that is reached three ways.
render() {
    sed -e "s/${ESC}\[[0-9;]*m//g" \
      | { grep -av '^\[WARN\]' || true; } \
      | { grep -av '^       at ' || true; } \
      | tr '\000' "$BEL" | sed "s/${BEL}/^@/g"
}

# ⚠️ BUILT HERE RATHER THAN TAKEN FROM vm/algvm, because a stale machine passes
# this check perfectly: it would write an image and read it back with the same
# wrong opcodes.  The same reason defects.sh builds its own.
ALGC="$ALGC" CC="$CC" CFLAGS="$CFLAGS" ./vm/build.sh "$WORK/algvm" > "$WORK/build.log" 2>&1 \
    || { cat "$WORK/build.log"; exit 1; }

PASS=0; EARLY=0; DIVERGED=0; SKIPPED=0
: > "$WORK/diverged"

for src in conformance/*.a24 refusals/*.a24; do
    [ -f "$src" ] || continue

    # The same question vm/conform.sh asks of a case: is it meant to be run the
    # ordinary way, or under --test?  Anything else the machine has no mode for.
    wants=""
    [ -f "${src%.a24}.args" ] && wants=$(cat "${src%.a24}.args")
    [ -n "$wants" ] || wants=$(sed -n 's|^// run: ||p' "$src" | head -1)

    if [ -n "$wants" ] && [ "$wants" != "--test" ]; then
        SKIPPED=$((SKIPPED + 1))
        continue
    fi

    mode=""
    [ "$wants" = "--test" ] && mode="--test"

    # What the compile answers, which is this harness's whole expectation.
    status=0
    # shellcheck disable=SC2086
    "$WORK/algvm" $mode "$src" > "$WORK/raw" 2>&1 || status=$?
    { render < "$WORK/raw"; echo "exit: $status"; } > "$WORK/compiled"

    rm -f "$WORK/case.a24b"

    emitted=0
    # shellcheck disable=SC2086
    "$WORK/algvm" --emit $mode "$src" --out="$WORK/case.a24b" > "$WORK/raw" 2>&1 || emitted=$?

    if [ "$emitted" -ne 0 ]; then
        # No image, because the program never got as far as one.  What is left
        # to check is that --emit refuses it exactly as a run refuses it: a
        # front end that answered differently depending on where the back end's
        # output was going would be the defect this catches.
        { render < "$WORK/raw"; echo "exit: $emitted"; } > "$WORK/refusal"

        if cmp -s "$WORK/refusal" "$WORK/compiled"; then
            EARLY=$((EARLY + 1))
        else
            DIVERGED=$((DIVERGED + 1))
            basename "$src" .a24 >> "$WORK/diverged"
        fi

        continue
    fi

    loaded=0
    # shellcheck disable=SC2086
    "$WORK/algvm" $mode "$WORK/case.a24b" > "$WORK/raw" 2>&1 || loaded=$?
    { render < "$WORK/raw"; echo "exit: $loaded"; } > "$WORK/image"

    if cmp -s "$WORK/image" "$WORK/compiled"; then
        PASS=$((PASS + 1))
    else
        DIVERGED=$((DIVERGED + 1))
        basename "$src" .a24 >> "$WORK/diverged"
    fi
done

echo "identical to the compile : $PASS"
echo "refused before emitting  : $EARLY"
echo "not applicable           : $SKIPPED"
echo "DIVERGED                 : $DIVERGED"

# ⚠️ AN EMPTY CORPUS IS A FAILURE AND NOT A PASS, because '0 diverged' is only
# as good as the set that was walked.  conformance/ and refusals/ are GENERATED
# by conform.sh and git-ignored, so a checkout that has not run it has nothing
# here to compare -- and this script would have reported three zeroes and an
# OK.  CLAUDE.md already carries the rule from the time vm/conform.sh walked
# one corpus and said so about two.
if [ $((PASS + EARLY + SKIPPED + DIVERGED)) -eq 0 ]; then
    echo
    echo "no cases: conformance/ and refusals/ are generated -- run ./conform.sh" >&2
    exit 1
fi

if [ "$DIVERGED" -gt 0 ]; then
    echo
    echo "diverging cases:"
    sed 's/^/  /' "$WORK/diverged"
    exit 1
fi

echo
echo "OK: every program the machine can compile, it answers the same way from"
echo "    a file as from its source."
