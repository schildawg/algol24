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
#   described        the entry agrees with OpCode.a24
#   variable-width   the entry says OpShape cannot describe it, and is believed
#   not yet written  no entry, which is work to do
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

# ---------------------------------------------------------------- coverage --

: > "$WORK/unwritten"
while read -r name number; do
    grep -qx "$name" "$WORK/entries" || echo "$name" >> "$WORK/unwritten"
done < "$WORK/ops"

UNWRITTEN=$(wc -l < "$WORK/unwritten" | tr -d ' ')

echo
echo "described       : $DESCRIBED"
echo "variable-width  : $VARIABLE"
echo "not yet written : $UNWRITTEN"

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
