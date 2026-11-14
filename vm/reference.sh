#!/bin/sh
#
# reference.sh -- checks that REFERENCE.md describes the opcodes that exist.
#
#     ./vm/reference.sh              # all checks
#     ./vm/reference.sh --missing    # also name every opcode still unwritten
#
# vm/OpCode.a24 is the AUTHORITY and this script never argues with it.  Every
# encoding in REFERENCE.md is written by hand, so each is a claim about a number
# and an operand layout the machine already knows -- and 78 hand-written
# encodings with nothing checking them would drift inside two increments.  This
# is spec/spec.sh's bargain applied to the machine: nothing here judges whether
# a description is GOOD, only that the bytes it shows are the bytes the opcode
# has.
#
# ⚠️ A count in prose was the first thing this caught, and it had already got
# into three files: OP_LONG's rationale said nineteen opcodes carry a constant
# index where twenty-four do.  Nothing checks a number written in a sentence,
# which is why this script prints the ones it derives rather than asserting
# figures a reader must trust.
#
# Three outcomes, as vm/conform.sh has three, and only the third is a failure:
#
# The report is a TOTAL and a breakdown of it, and the three parts are asserted
# to sum to the total:
#
#   opcodes declared   how many OpCode.a24 declares, the OP_COUNT sentinel
#                      excluded
#   entries agreeing   the entry's number, operands and byte count all match
#   variable-width     the entry says OpShape cannot describe its shape, and is
#                      believed -- so its shape is not compared.  DISJOINT from
#                      the line above rather than a subset of it
#   no entry yet       work to do
#   WRONG            the entry disagrees with the machine
#
# The STACK section is compared against OpStack in vm/OpCode.a24, which is in
# turn held to a RUN by vm/Vm.a24's own tests -- so an entry's stack effect is
# two steps from something that executes rather than being prose.  Two of its
# three numbers are measured for 67 of the 78 opcodes, the other eleven being
# named in vm/Vm.a24 with the reason each cannot be run alone: `pushes - pops`
# is what a run reveals and `needs`
# is what running one value shallower reveals.
#
# ⚠️ The SPLIT between pops and pushes is description and not measurement, and
# no test can make it otherwise: popping a value and pushing two copies of it
# moves the stack exactly as reading it and pushing one does.  That was checked
# with distinct sentinels rather than assumed, and it is why the vocabulary
# carries `needs` at all -- the two-term version passed a declaration of
# `1 2` for OP_DUP, whose truth is `0 1`.

set -eu

cd "$(dirname "$0")/.."

OPCODES="vm/OpCode.a24"
REF="vm/REFERENCE.md"
SPEC="spec/ALGOL-24.md"

MISSING=0
[ "${1:-}" = "--missing" ] && MISSING=1

# The one mode that WRITES.  It stops after rewriting, because a file that has
# just been rewritten has nothing left to tell you that the diff does not.
REWRITE=0
[ "${1:-}" = "--examples" ] && REWRITE=1

for f in "$OPCODES" "$REF" "$SPEC"; do
    [ -f "$f" ] || { echo "no $f" >&2; exit 1; }
done

WORK=$(mktemp -d)
trap 'rm -rf "$WORK"' EXIT

FAILED=0

note() { echo "  $1"; }
fail() { echo "  WRONG: $1"; FAILED=1; }

# ------------------------------------------------------------- the authority --

# `const OP_X := N;` -- every opcode and its number.  OP_COUNT is a SENTINEL
# and not an opcode, so it bounds the walk rather than joining it.
sed -n 's/^const \(OP_[A-Z0-9_]*\) := \([0-9]*\);.*/\1 \2/p' "$OPCODES" > "$WORK/numbers"

OP_COUNT=$(awk '$1 == "OP_COUNT" { print $2 }' "$WORK/numbers")
grep -v '^OP_COUNT ' "$WORK/numbers" > "$WORK/ops"

TOTAL=$(wc -l < "$WORK/ops" | tr -d ' ')

[ "$TOTAL" = "$OP_COUNT" ] || fail "OP_COUNT is $OP_COUNT but $TOTAL opcodes are declared"

# OpShape's body only, so a mention of an opcode anywhere else cannot be read
# as a shape.  An opcode absent from it has no operands, which is the function's
# own fallthrough.
awk '/^function OpShape/ { inside = 1; next }
     inside && /^end$/    { inside = 0 }
     inside' "$OPCODES" \
  | sed -n "s/.*if Op = \(OP_[A-Z0-9_]*\)[[:space:]]*then Exit '\([a-z]*\)';.*/\1 \2/p" \
  > "$WORK/shapes"

# OpStack's body the same way: `pops pushes needs` per opcode.  This is the
# section REFERENCE.md's readers care most about and the one that was pure
# prose until there was something to hold it to.
awk '/^function OpStack/ { inside = 1; next }
     inside && /^end$/    { inside = 0 }
     inside' "$OPCODES" \
  | sed -n "s/.*if Op = \(OP_[A-Z0-9_]*\)[[:space:]]*then Exit '\([^']*\)';.*/\1 \2/p" \
  > "$WORK/effects"

# ----------------------------------------------------------------- the file --

# One entry per `## OP_X — Title`, split into a file apiece so each can be read
# on its own.  The heading's name is the entry's identity.
awk -v work="$WORK" '
    /^## OP_[A-Z0-9_]+/ {
        name = $2
        print name >> (work "/entries")
        out = work "/entry." name
        printf "" > out
        next
    }
    out { print >> out }
' "$REF"

[ -f "$WORK/entries" ] || { echo "no entries in $REF" >&2; exit 1; }

echo "REFERENCE.md — $(wc -l < "$WORK/entries" | tr -d ' ') entries, $OP_COUNT opcodes"
echo

# ------------------------------------------------------------- named at all --

echo "Entries"

sort "$WORK/entries" | uniq -d > "$WORK/dupes"
while read -r name; do
    [ -n "$name" ] && fail "$name has more than one entry"
done < "$WORK/dupes"

while read -r name; do
    grep -q "^$name " "$WORK/ops" \
        || fail "$name has an entry but is no opcode -- a mnemonic typo, or a rename OpCode.a24 took and this file did not"
done < "$WORK/entries"

# --------------------------------------------------------------- encodings --

DESCRIBED=0
VARIABLE=0

while read -r name; do
    entry="$WORK/entry.$name"
    [ -f "$entry" ] || continue
    grep -q "^$name " "$WORK/ops" || continue

    want_number=$(awk -v n="$name" '$1 == n { print $2 }' "$WORK/ops")
    want_shape=$(awk -v n="$name" '$1 == n { print $2 }' "$WORK/shapes")

    # Every entry must carry the sections a reader cannot do without, matched as
    # the HEADERS they are and not as words that appear somewhere.  A loose
    # substring match passed an entry whose `**Stack**` header had been mangled
    # into prose, because the mangled line still contained the word.  Encoding
    # is not in this list: the bracketed row below is what proves it is there,
    # and says something more useful when it is not.
    for section in Stack Operation; do
        grep -q "^\*\*$section\*\*" "$entry" \
            || fail "$name has no $section section"
    done

    # The STACK line, against OpStack.  Everything after the three numbers is
    # free prose; the three themselves are the claim.
    want_effect=$(awk -v n="$name" '$1 == n { print $2, $3, $4 }' "$WORK/effects")
    said=$(sed -n 's/^\*\*Stack\*\* — pops \([^,]*\), pushes \([^,]*\), needs \([^. ]*\).*/\1 \2 \3/p' "$entry" | head -1)

    if [ -z "$said" ]; then
        fail "$name states no stack effect in the form 'pops P, pushes Q, needs R'"
    elif [ -z "$want_effect" ]; then
        fail "$name has no OpStack entry to be held to"
    elif [ "$said" != "$want_effect" ]; then
        fail "$name does '$want_effect' to the stack but its entry says '$said'"
    fi

    # The first bracketed row inside the fence is the machine-readable one.
    row=$(sed -n '/^```/,/^```/p' "$entry" | grep -m1 '\[ *[0-9]' || true)

    if [ -z "$row" ]; then
        fail "$name has no bracketed encoding row"
        continue
    fi

    # Number, operand letters and byte count all come from THAT ONE ROW, so
    # nothing in the prose below can be mistaken for part of the encoding.  An
    # earlier version read the letters from the whole row with `tr -cd`, which
    # took the b and the s out of the words `5 bytes` and reported every
    # multi-operand opcode as wrong.
    got_number=$(echo "$row" | sed -n 's/.*\[ *\([0-9][0-9]*\) *\].*/\1/p')

    [ "$got_number" = "$want_number" ] \
        || fail "$name is numbered $want_number but its entry shows $got_number"

    got_shape=$(echo "$row" \
        | grep -o '\[ *[ibls] *\]' \
        | tr -d '[] ' \
        | tr -d '\n')

    if sed -n '/^```/,/^```/p' "$entry" | grep -q 'variable-width'; then
        VARIABLE=$((VARIABLE + 1))
        echo "$name" >> "$WORK/variable"

        [ "$want_shape" = "" ] \
            || fail "$name says variable-width but OpShape describes it as '$want_shape'"

        continue
    fi

    if [ "$got_shape" != "$want_shape" ]; then
        fail "$name has shape '$want_shape' but its entry shows '$got_shape'"
        continue
    fi

    # The stated byte count, against the one the shape implies.  An index and a
    # local slot are one byte each until OP_LONG widens them; a short is always
    # two; the opcode itself is the first.
    want_bytes=$(echo "$want_shape" | awk '
        { n = 1
          for (i = 1; i <= length($0); i++) {
              c = substr($0, i, 1)
              n += (c == "s") ? 2 : 1
          }
          print n }')

    got_bytes=$(echo "$row" | sed -n 's/.*[^0-9]\([0-9][0-9]*\) bytes*.*/\1/p')

    if [ -z "$got_bytes" ]; then
        fail "$name states no byte count"
    elif [ "$got_bytes" != "$want_bytes" ]; then
        fail "$name is $want_bytes bytes but its entry says $got_bytes"
    else
        DESCRIBED=$((DESCRIBED + 1))
    fi
done < "$WORK/entries"

# ------------------------------------------------------------- cross-links --

echo
echo "Cross-references"

# A `See also` naming an opcode that does not exist is a dead end no reader can
# tell from a real one.
grep -ho 'OP_[A-Z0-9_]*' "$REF" | sort -u > "$WORK/mentioned"

# A name deliberately cited AS one that does not exist -- OP_WIDE, which this
# machine pointedly is not -- is declared in a comment beside the sentence that
# needs it, so the exemption is local to its reason and visible in the source
# rather than being a list somewhere else that outlives its use.
sed -n 's/.*<!-- reference.sh: not-an-opcode \(OP_[A-Z0-9_]*\) -->.*/\1/p' "$REF" \
    | sort -u > "$WORK/exempt"

while read -r name; do
    grep -q "^$name " "$WORK/numbers" && continue
    grep -qx "$name" "$WORK/exempt" && continue

    fail "$REF mentions $name, which is no opcode"
done < "$WORK/mentioned"

EXEMPT=$(wc -l < "$WORK/exempt" | tr -d ' ')
[ "$EXEMPT" -eq 0 ] || note "$EXEMPT named as deliberately not an opcode: $(tr '\n' ' ' < "$WORK/exempt")"

note "$(wc -l < "$WORK/mentioned" | tr -d ' ') distinct opcodes mentioned, all real"

# ----------------------------------------------------------- rule citations --

echo
echo "Citations"

# spec.sh checks the citations INSIDE the specification; it cannot see these.
# A rule renumbered out from under this file would otherwise go quietly wrong.
grep -ho '\[[A-Z][A-Z][A-Z]-[0-9][0-9][0-9]\]' "$REF" | tr -d '[]' | sort -u > "$WORK/cited"

CITED=0
while read -r rule; do
    [ -n "$rule" ] || continue
    CITED=$((CITED + 1))

    grep -q "\*\*\[$rule\]\*\*" "$SPEC" \
        || fail "$REF cites [$rule], which $SPEC does not define"
done < "$WORK/cited"

note "$CITED rules cited, all defined"

# ----------------------------------------------------------------- examples --
#
# ⚠️ AN EXAMPLE IS THE MACHINE'S OWN OUTPUT AND IS RUN TO PROVE IT.  Each entry
# carries one program and the window of `algvm --list` where its opcode appears;
# this writes that program out, lists it, and requires the window to come back
# CONTIGUOUSLY and in order.  Eighty hand-copied disassemblies would drift the
# first time the emitter changed, and nothing would say so -- this is the
# bargain conform.sh strikes for the corpus, applied to a reference: the example
# and the thing it describes are one text.
#
# ⚠️ IT USES THE CHECKED-IN vm/algvm, which is exactly what a stale build leaves
# behind.  defects.sh caught that once, where neither corpus did.  Build the
# machine before trusting a green run here.
#
# Four entries name themselves as NOT RUN, because the only program that
# reaches them declares three hundred globals and no entry can carry its
# source.  Their windows are real output; nothing re-runs them.

echo
echo "Examples"

ALGVM=vm/algvm
[ -x "$ALGVM" ] || ALGVM=""

SHOWN=0
RAN=0
NOT_RUN=0

: > "$WORK/notrun"

# The Example section's two fences -- the program, and the listing window --
# pulled out by the FENCE and not by line number, so prose between them stays
# free.  The first is tagged `algol24` and the second is bare, which is the
# only thing telling them apart.
example_of () {
    awk -v src="$2" -v lst="$3" '
        BEGIN { printf "" > src; printf "" > lst }
        /^\*\*Example\*\*/ { inside = 1; next }
        inside && /^\*\*/  { inside = 0 }
        !inside { next }
        /^```/ {
            if (open) { open = 0; next }
            open = 1
            kind = ($0 == "```algol24") ? "src" : "lst"
            next
        }
        open && kind == "src" { print > src }
        open && kind == "lst" { print > lst }
    ' "$1"
}

# ⚠️ --examples REWRITES RATHER THAN CHECKS, which is what makes the check
# above affordable.  A change to what the emitter emits moves offsets in most
# of these windows at once, and hand-editing seventy-six disassemblies is the
# kind of chore that ends with the check being deleted.  This is vm/dispatch.sh's
# split -- generate, or --check -- with the default the other way round, because
# the usual question here is whether the file still agrees.
#
# It keeps each window's SHAPE: the same chunk, the same number of lines before
# and after the instruction.  The instruction is found by its own text first and
# by its mnemonic second, so a window stays pointed at what its author chose
# even when every offset around it has moved.  The result is a diff to read, not
# a thing to trust blindly.
if [ "$REWRITE" -eq 1 ]; then
    [ -n "$ALGVM" ] || { echo "no vm/algvm to list with -- ./vm/build.sh builds one" >&2; exit 2; }

    CHANGED=0

    while read -r name; do
        entry="$WORK/entry.$name"
        [ -f "$entry" ] || continue
        grep -q '^\*\*Example\*\*' "$entry" || continue
        grep -q "reference.sh: example-not-run $name" "$entry" && continue

        example_of "$entry" "$WORK/prog.a24" "$WORK/want.lst"

        [ -s "$WORK/prog.a24" ] || continue
        [ -s "$WORK/want.lst" ] || continue

        "$ALGVM" --list "$WORK/prog.a24" > "$WORK/got.lst" 2>/dev/null || true

        awk -v OP="$name" -v want="$WORK/want.lst" '
            BEGIN {
                while ((getline l < want) > 0) w[++n] = l

                head = "== <script> =="
                if (w[1] ~ /^== /) { head = w[1]; for (i = 2; i <= n; i++) w[i - 1] = w[i]; n-- }

                for (i = 1; i <= n; i++) {
                    split(w[i], f, " ")
                    if (f[2] == OP) { at = i; text = w[i]; sub(/^[0-9]+  /, "", text); break }
                }

                before = at - 1
                after  = n - at
            }

            /^== / { chunk = $0; next }
            /^$/   { next }

            {
                line[++m] = $0
                where[m]  = chunk

                said = $0
                sub(/^[0-9]+  /, "", said)

                # FOUR candidates, best first.  The instruction by its own text
                # survives every offset around it moving, which is the usual
                # case after an emitter change; the mnemonic alone survives its
                # operands changing too.  Both are preferred inside the chunk
                # the window named -- and then tried anywhere, because a chunk
                # RENAMED by an edit to the program above it would otherwise
                # leave the window unrepairable by anything but hand.
                #
                # (No apostrophes in here: this awk is single-quoted, and one
                # closed the string and made the shell parse the rest.)
                if (said == text) {
                    if (chunk == head && pick1 == 0) pick1 = m
                    if (pick3 == 0)                  pick3 = m
                }

                if ($2 == OP) {
                    if (chunk == head && pick2 == 0) pick2 = m
                    if (pick4 == 0)                  pick4 = m
                }
            }

            END {
                at = pick1 ? pick1 : pick2 ? pick2 : pick3 ? pick3 : pick4
                if (!at) exit 1

                # The window stays inside the chunk it landed in: a line from
                # the one above or below says nothing true about either.
                lo = at - before; if (lo < 1) lo = 1
                hi = at + after;  if (hi > m) hi = m

                while (where[lo] != where[at]) lo++
                while (where[hi] != where[at]) hi--

                if (where[at] != "== <script> ==") print where[at]
                for (i = lo; i <= hi; i++) print line[i]
            }
        ' "$WORK/got.lst" > "$WORK/new.$name" || { fail "$name: $ALGVM lists no $name for its own example"; continue; }

        cmp -s "$WORK/new.$name" "$WORK/want.lst" || CHANGED=$((CHANGED + 1))
    done < "$WORK/entries"

    awk -v work="$WORK" '
        /^## OP_[A-Z0-9_]+/ { name = $2; inside = 0; done = 0 }
        /^\*\*Example\*\*/  { inside = 1 }
        inside && /^\*\*(Satisfies|Raises|See also)\*\*/ { inside = 0 }

        inside && !done && /^```$/ && !open {
            file = work "/new." name

            # ⚠️ NOT CLOSED BETWEEN THE FIRST READ AND THE REST.  Closing
            # rewinds the file, so the loop below read line one a second time
            # and every window came back with its first line twice.
            if ((getline probe < file) > 0) {
                print
                print probe
                while ((getline probe < file) > 0) print probe
                close(file)
                skipping = 1
                done = 1
                next
            }
            close(file)
        }

        skipping && /^```$/ { skipping = 0; print; next }
        skipping            { next }

        /^```algol24/ { open = 1 }
        /^```$/ && open { open = 0 }

        { print }
    ' "$REF" > "$WORK/REF.new"

    mv "$WORK/REF.new" "$REF"

    echo "  rewrote every window from $ALGVM; $CHANGED differed from what was there"
    echo
    echo "Read the diff: a window is a CHOICE of what to show, and this keeps the"
    echo "old one's shape without knowing what it was for."

    # ⚠️ A REWRITE THAT COULD NOT FIND AN INSTRUCTION STILL FAILS.  Leaving the
    # old window in place is the right answer, since nothing here can guess
    # what was meant -- but exiting 0 on it would report a repair that did not
    # happen.
    exit "$FAILED"
fi

while read -r name; do
    entry="$WORK/entry.$name"
    [ -f "$entry" ] || continue
    grep -q "^$name " "$WORK/ops" || continue

    grep -q '^\*\*Example\*\*' "$entry" \
        || { fail "$name has no Example section"; continue; }

    example_of "$entry" "$WORK/prog.a24" "$WORK/want.lst"

    [ -s "$WORK/want.lst" ] \
        || { fail "$name's Example shows no listing"; continue; }

    # An example of the wrong instruction is the one mistake a contiguity
    # check cannot catch: a window copied from a neighbour still matches the
    # machine perfectly.  The mnemonic is matched with its leading gap and a
    # boundary after it, because OP_GET_GLOBAL is a prefix of
    # OP_GET_GLOBAL_LONG.
    grep -qE "  $name( |\$)" "$WORK/want.lst" \
        || fail "$name's Example does not show $name"

    SHOWN=$((SHOWN + 1))

    if grep -q "reference.sh: example-not-run $name" "$entry"; then
        NOT_RUN=$((NOT_RUN + 1))
        echo "$name" >> "$WORK/notrun"
        continue
    fi

    [ -s "$WORK/prog.a24" ] \
        || { fail "$name's Example has no program to run"; continue; }

    [ -n "$ALGVM" ] || continue

    "$ALGVM" --list "$WORK/prog.a24" > "$WORK/got.lst" 2>/dev/null || true

    # A leading `== name ==` is an ASSERTION ABOUT WHICH CHUNK and not a line
    # the window is adjacent to: an example inside a subprogram names the chunk
    # it is in and then shows a window from the middle of it.  So the header is
    # located first and the search is confined to that chunk, where the rest
    # must be contiguous and in order.
    if awk -v want="$WORK/want.lst" '
            BEGIN {
                while ((getline l < want) > 0) w[++n] = l

                if (w[1] ~ /^== /) { head = w[1]; for (i = 2; i <= n; i++) w[i - 1] = w[i]; n-- }
            }

            /^== / { chunk = $0 }
            { out[++m] = $0; where[m] = chunk }

            END {
                for (i = 1; i + n - 1 <= m; i++) {
                    if (head != "" && where[i] != head) continue

                    ok = 1
                    for (j = 1; j <= n; j++)
                        if (out[i + j - 1] != w[j]) { ok = 0; break }
                    if (ok) exit 0
                }
                exit 1
            }' "$WORK/got.lst"
    then
        RAN=$((RAN + 1))
    else
        fail "$name's Example is not what the machine prints today -- ./vm/reference.sh --examples rewrites every window from live output"
    fi
done < "$WORK/entries"

note "$SHOWN entries carry one, $RAN run and compared against the machine"

[ "$NOT_RUN" -eq 0 ] \
    || note "$NOT_RUN not run, by their own admission: $(tr '\n' ' ' < "$WORK/notrun")"

[ -n "$ALGVM" ] \
    || note "no vm/algvm, so NOTHING was run -- ./vm/build.sh builds one"

# ---------------------------------------------------------------- coverage --

: > "$WORK/unwritten"
while read -r name number; do
    grep -qx "$name" "$WORK/entries" || echo "$name" >> "$WORK/unwritten"
done < "$WORK/ops"

UNWRITTEN=$(wc -l < "$WORK/unwritten" | tr -d ' ')

# ⚠️ THE TOTAL IS PRINTED FIRST, and it is printed because it was MISREAD.
# This block used to open with 'described' and 'variable-width' as two lines
# that happen to sum to the total -- so taking the first for the whole was the
# obvious mistake, and it nearly put the wrong figure on the website.  A
# variable-width opcode is described too; it is merely exempt from the shape
# comparison.  So the total is its own line, and the two below it are a
# breakdown of it rather than alternatives to it.
TOTAL=$(wc -l < "$WORK/ops" | tr -d ' ')

echo
echo "opcodes declared by OpCode.a24 : $TOTAL"
echo "  entries agreeing with it     : $DESCRIBED"
echo "  variable-width, shape not compared : $VARIABLE"
echo "  no entry yet                 : $UNWRITTEN"

# ⚠️ The three MUST sum to the total, and checking it is the point.  They are
# disjoint -- the variable-width branch continues before DESCRIBED is counted --
# so a reader cannot tell by looking whether they are parts of a whole or
# alternatives, and the old report's first two lines were taken for the whole.
# Now the arithmetic is asserted, so the breakdown cannot quietly stop
# accounting for every opcode.
PARTS=$((DESCRIBED + VARIABLE + UNWRITTEN))

if [ "$PARTS" -ne "$TOTAL" ]; then
    fail "the breakdown sums to $PARTS and OpCode.a24 declares $TOTAL"
fi

if [ "$VARIABLE" -gt 0 ]; then
    echo
    echo "exempt from the shape check, by their own admission:"
    sed 's/^/  /' "$WORK/variable"
fi

if [ "$UNWRITTEN" -gt 0 ] && [ "$MISSING" -eq 1 ]; then
    echo
    echo "no entry yet:"
    sed 's/^/  /' "$WORK/unwritten"
fi

echo
if [ "$FAILED" -ne 0 ]; then
    echo "FAIL: REFERENCE.md disagrees with vm/OpCode.a24."
    exit 1
fi

if [ "$UNWRITTEN" -gt 0 ]; then
    # Work to do rather than a failure, as a refusal is in vm/conform.sh -- so
    # adding an opcode does not break the build before its entry is written.
    # The gate that DOES fail on one is vm/Vm.a24's own test suite: an opcode
    # with no OpStack entry fails four tests there, which is the right place
    # for it, since the machine cannot run the opcode either.
    #
    # ⚠️ Every entry existed once.  Going from none unwritten to any is a file
    # falling behind the machine, which is worth looking at even though it is
    # not red.
    noun="opcodes"
    [ "$UNWRITTEN" -eq 1 ] && noun="opcode"

    echo "OK so far: every entry agrees with the machine, and $UNWRITTEN $noun"
    echo "    $([ "$UNWRITTEN" -eq 1 ] && echo 'is' || echo 'are') still unwritten.  Run with --missing to name $([ "$UNWRITTEN" -eq 1 ] && echo it || echo them)."
    exit 0
fi

echo "OK: every opcode is described, and every entry agrees with the machine."
