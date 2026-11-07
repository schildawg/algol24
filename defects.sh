#!/bin/sh
#
# THE DEFECT SWEEP, which is a harness only until it is green.
#
# Fifteen defects reported by two projects using the language -- shroom-slots
# (R-1..R-15) and algol24.com (D-1, D-2) -- each reduced to the smallest program
# that shows it, and each run under whichever processors disagree.  See
# finished/PLAN-0.2.4.md, where the same numbering carries the root cause for each.
#
# Plus what working through them has FOUND, which carries no R- or D- number
# because nobody reported it: BI-1, a built-in held as a value.  A sweep that
# only ever checked what was reported would have shipped it.
#
# Unlike every other gate here, this one is EXPECTED TO FAIL when written and
# its finish line is the release: a defect that stops reproducing is fixed, and
# the last line says how many are left.
#
# ⚠️ IT REPORTS WHAT IT SAW, not what a report claimed.  Three incoming claims
# did not survive being run -- R-2's second case is already fixed, R-11's
# "second half" is not a divergence, and R-13 is localised to one unit rather
# than to units being loaded -- so each check prints the observation and the
# script never takes a defect's status from the file that reported it.
#
# ⚠️ A defect that divides the processors is checked by COMPARING THEM, not
# against recorded text.  Seven of these are divergences, and the whole point of
# a divergence is that no single expected output exists: the check is that the
# three answers agree, which is also what keeps the check honest if the right
# answer is later decided differently than this script guesses.
set -eu

ROOT=$(cd "$(dirname "$0")" && pwd)
ALGC="$ROOT/bootstrap/algc"
ALGVM="$ROOT/vm/algvm"

[ -x "$ALGC" ]  || { echo "defects.sh: no bootstrap/algc -- run ./bootstrap/build.sh" >&2; exit 2; }
[ -x "$ALGVM" ] || { echo "defects.sh: no vm/algvm -- run ./vm/build.sh" >&2; exit 2; }

WORK=$(mktemp -d "${TMPDIR:-/tmp}/algol24-defects.XXXXXX")
trap 'rm -rf "$WORK"' EXIT

OPEN=0
FIXED=0

# Reports one defect.  $1 the tag, $2 one line saying what it is, $3 'open' or
# 'fixed', $4 what was seen.
report () {
    if [ "$3" = fixed ]; then
        FIXED=$((FIXED + 1))
        printf '  %-6s FIXED       %s\n' "$1" "$2"
    else
        OPEN=$((OPEN + 1))
        printf '  %-6s REPRODUCES  %s\n' "$1" "$2"
        printf '              %s\n' "$4"
    fi
}

# Compiles a program and runs it, answering its output.  Answers the cc errors
# instead when the emitted C does not build, since that IS the symptom for four
# of these.
compiled () {
    dir=$1; prog=$2
    rm -rf "$dir/out"; mkdir -p "$dir/out"
    if ! "$ALGC" --compile --out="$dir/out" "$prog" > "$dir/emit.log" 2>&1; then
        sed -n '1p' "$dir/emit.log"; return 0
    fi
    if ! cc -std=c11 -O0 -o "$dir/run" "$dir/out"/*.c > "$dir/cc.log" 2>&1; then
        grep -m1 'error:' "$dir/cc.log" | sed 's/.*error: //'; return 0
    fi
    "$dir/run" 2>&1 || true
}

echo
echo "The defect sweep -- fifteen reports, reduced, plus what they led to"
echo

# ---------------------------------------------------------------- group 1
# R-6, R-7, R-9, R-11: CEmitter resolves a bare name against a program-wide
# table, so an imported declaration beats the file's own and a unit's own
# member is reported missing.  All four are the compiled back end alone.
echo "1. CEmitter resolves a bare name against a program-wide table"

D=$WORK/r6; mkdir -p "$D"
printf 'unit phases;\ntype Phase = (Idle, Spinning, Done);\n' > "$D/phases.a24"
cat > "$D/r6.a24" <<'EOF'
uses phases;
var Spinning := false;
Spinning := true;
WriteLn (Spinning);
EOF
I=$("$ALGC" "$D/r6.a24" 2>&1 || true)
V=$("$ALGVM" "$D/r6.a24" 2>&1 || true)
C=$(compiled "$D" "$D/r6.a24")
if [ "$I" = "$V" ] && [ "$I" = "$C" ]; then
    report R-6 "a program var named after an imported enum member" fixed ''
else
    report R-6 "a program var named after an imported enum member" open \
        "interpreted '$I', machine '$V', compiled '$C' -- the assignment is discarded in silence"
fi

D=$WORK/r7; mkdir -p "$D"
printf "unit purse;\nfunction Money (N : Integer) : String;\nbegin\n    Exit Str (N);\nend\n" > "$D/purse.a24"
printf 'uses purse;\nvar Money := 5;\nWriteLn (Money);\n' > "$D/r7.a24"
I=$("$ALGC" "$D/r7.a24" 2>&1 || true)
V=$("$ALGVM" "$D/r7.a24" 2>&1 || true)
C=$(compiled "$D" "$D/r7.a24")
if [ "$I" = "$V" ] && [ "$I" = "$C" ]; then
    report R-7 "a program var named after an imported function" fixed ''
else
    report R-7 "a program var named after an imported function" open \
        "interpreted '$I', machine '$V', compiled '$C'"
fi

D=$WORK/r9; mkdir -p "$D"
cat > "$D/boxlib.a24" <<'EOF'
unit boxlib;
class Box;
var
    W : Integer;
begin
    constructor Init (W : Integer);
    begin
        this.W := W;
    end
    function Size () : Integer;
    begin
        Exit this.W * 2;
    end
    function Report () : Integer;
    begin
        Exit Size ();
    end
end
EOF
printf 'unit namer;\nfunction Size (N : Integer) : Integer;\nbegin\n    Exit N;\nend\n' > "$D/namer.a24"
printf 'uses boxlib;\nuses namer;\nvar B := Box (10);\nWriteLn (B.Report ());\n' > "$D/r9.a24"
I=$("$ALGC" "$D/r9.a24" 2>&1 || true)
V=$("$ALGVM" "$D/r9.a24" 2>&1 || true)
C=$(compiled "$D" "$D/r9.a24")
if [ "$I" = "$V" ] && [ "$I" = "$C" ]; then
    report R-9 "a unit's own method, broken by a name in another unit" fixed ''
else
    report R-9 "a unit's own method, broken by a name in another unit" open \
        "interpreted '$I', machine '$V', compiled '$C' -- the stub lands in boxlib.c, which nothing edited"
fi

D=$WORK/r11; mkdir -p "$D"
printf "unit shelf;\nprocedure Depth (Word : String, N : Integer);\nbegin\n    WriteLn (Word + Str (N));\nend\n" > "$D/shelf.a24"
cat > "$D/mid.a24" <<'EOF'
unit mid;
uses shelf;
const Depth := 260;
function Run (Ticks : Integer) : Integer;
begin
    var Grow := 1000;
    if Ticks < Depth then Grow := Ticks * 1000 div Depth;
    Exit Grow;
end
EOF
printf "uses shelf;\nuses mid;\nWriteLn (Run (100));\n" > "$D/r11.a24"
I=$("$ALGC" "$D/r11.a24" 2>&1 || true)
V=$("$ALGVM" "$D/r11.a24" 2>&1 || true)
C=$(compiled "$D" "$D/r11.a24")
if [ "$I" = "$V" ] && [ "$I" = "$C" ]; then
    report R-11 "a unit's own const named after an imported subprogram" fixed ''
else
    report R-11 "a unit's own const named after an imported subprogram" open \
        "interpreted '$I', machine '$V', compiled '$C'"
fi

# ⚠️ The strongest check of the four, and it is not any of their outputs: a
# program-wide grep of the emitted C for the error stub.  shroom-slots added
# exactly this after R-9 cost it an afternoon and found three latent aborts on
# the first run.
STUBS=0
for d in "$WORK"/r6 "$WORK"/r7 "$WORK"/r9 "$WORK"/r11; do
    [ -d "$d/out" ] || continue
    N=$(grep -ho 'alg_error("Undefined[^"]*"' "$d"/out/*.c 2>/dev/null | wc -l | tr -d ' ')
    STUBS=$((STUBS + N))
done
printf '         %s error stub(s) in the emitted C across the four\n' "$STUBS"
echo

# ---------------------------------------------------------------- group 2
echo "2. A built-in beats a field of 'this'"
D=$WORK/r1; mkdir -p "$D"
cat > "$D/r1.a24" <<'EOF'
class Thing;
var
    Pos    : Integer;
    Cursor : Integer;
begin
    constructor Init ();
    begin
        this.Pos    := 42;
        this.Cursor := 42;
    end
    function BareField () : Integer;   begin Exit Pos;    end
    function ControlCase () : Integer; begin Exit Cursor; end
end

var T := Thing ();
WriteLn (Str (T.BareField ()) + ' ' + Str (T.ControlCase ()));
EOF
I=$("$ALGC" "$D/r1.a24" 2>&1 || true)
V=$("$ALGVM" "$D/r1.a24" 2>&1 || true)
C=$(compiled "$D" "$D/r1.a24")
if [ "$I" = "$V" ] && [ "$I" = "$C" ]; then
    report R-1 "a class field named after a built-in, read bare inside the class" fixed ''
else
    report R-1 "a class field named after a built-in, read bare inside the class" open \
        "interpreted '$I', machine '$V', compiled '$C' -- the interpreter is the odd one out"
fi
echo

# ---------------------------------------------------------------- group 3
echo "3. One SourceCode holds every file"
D=$WORK/r3; mkdir -p "$D"
printf 'unit badunit;\nfunction Twice (N : Integer) : Integer;\nbegin\n    Exit N * 2\nend\n' > "$D/badunit.a24"
printf 'uses badunit;\nWriteLn (Twice (5));\n' > "$D/r3.a24"
OUT=$("$ALGC" "$D/r3.a24" 2>&1 || true)
# The fault is on line 4 of badunit.a24.  A correct report names that file.
if printf '%s' "$OUT" | grep -q 'badunit.a24'; then
    report R-3 "a syntax error names one file and quotes another" fixed ''
else
    # Strip the colour codes and the work directory, so the line says which
    # file was named and which file's text was quoted and nothing else.
    QUOTED=$(printf '%s' "$OUT" | sed 's/\x1b\[[0-9;]*m//g' \
                                | grep -m1 '^\[ERROR\] *[0-9]* |' \
                                | sed 's/^\[ERROR\] *//')
    report R-3 "a syntax error names one file and quotes another" open \
        "the fault is badunit.a24:4; the report names r3.a24 and quotes '$QUOTED'"
fi
echo

# ---------------------------------------------------------------- group 4
echo "4. The compiler knows and waits"
D=$WORK/r8; mkdir -p "$D"
printf 'unit helperu;\nfunction Helper () : Integer;\nbegin\n    Exit 7;\nend\n' > "$D/helperu.a24"
printf "WriteLn ('before');\nWriteLn (Helper ());\n" > "$D/r8.a24"
# ⚠️ The criterion is a WARNING, not a refusal, and that is the decided shape
# rather than a compromise.  A free name on a path that never runs is never
# resolved [DCL-007], so the program is legal and refusing it would forbid what
# the language permits -- see finished/PLAN-0.2.4.md item 4.  What was wrong was only
# that nothing said so while compiling.
rm -rf "$D/out"; mkdir -p "$D/out"
"$ALGC" --compile --out="$D/out" "$D/r8.a24" > "$D/emit.log" 2>&1 || true
if grep -q 'WARN.*Undefined variable' "$D/emit.log"; then
    report R-8 "a name nothing declares compiles without a word" fixed ''
else
    report R-8 "a name nothing declares compiles without a word" open \
        "--compile said nothing and carried the error into the emitted C"
fi

D=$WORK/r10; mkdir -p "$D"
cat > "$D/r10.a24" <<'EOF'
function Three (A : Integer, B : Integer, C : Integer) : Integer;
begin
    Exit A + B + C;
end

WriteLn (Three (1, 2));
EOF
rm -rf "$D/out"; mkdir -p "$D/out"
"$ALGC" --compile --out="$D/out" "$D/r10.a24" > "$D/emit.log" 2>&1 || true
if grep -q 'WARN.*no declaration of it takes' "$D/emit.log"; then
    report R-10 "a call matching no declared arity compiles and links" fixed ''
else
    report R-10 "a call matching no declared arity compiles and links" open \
        "one visible declaration taking 3, called with 2, and --compile said nothing"
fi

# ⚠️ The guard on R-10's fix, and it matters more than the fix: selection is at
# RUN time [EXP-013], so these four calls must keep compiling.  A check narrow
# enough to be sound cannot see any of them.
cat > "$WORK/r10-sound.a24" <<'EOF'
function Total (Tag : String, Values : List of Integer) : Integer;
begin
    var Sum := 0;
    for var V in Values do Sum := Sum + V;
    Exit Sum;
end

function Pick (A : Integer) : Integer;          begin Exit A;     end
function Pick (A : Integer, B : Integer) : Integer; begin Exit A + B; end

var F := Pick;
WriteLn (Total ('a', 1, 2, 3));
WriteLn (Pick (1));
WriteLn (Pick (1, 2));
WriteLn (F (9));
WriteLn (Length ('abc'));
EOF
rm -rf "$WORK/r10s"; mkdir -p "$WORK/r10s"
"$ALGC" --compile --out="$WORK/r10s" "$WORK/r10-sound.a24" > "$WORK/r10s.log" 2>&1 || true
if grep -q 'WARN' "$WORK/r10s.log"; then
    printf '         !! a gathering, overloaded, held or built-in call WARNED -- too wide\n'
    grep 'WARN' "$WORK/r10s.log" | sed 's/^/            /'
else
    printf '         the unrefusable call shapes compile, and none of them warns\n'
fi
echo

# ---------------------------------------------------------------- group 5
echo "5. A diagnostic that carries no location"
printf 'begin WriteLn (1); end; WriteLn (2);\n' > "$WORK/r2.a24"
OUT=$("$ALGC" "$WORK/r2.a24" 2>&1 || true)
if printf '%s' "$OUT" | grep -q 'ERROR'; then
    report R-2 "'Expect expression!' carries no file, line or caret" fixed ''
else
    report R-2 "'Expect expression!' carries no file, line or caret" open \
        "the whole report is: $(printf '%s' "$OUT" | tr '\n' ' ')"
fi

printf 'WriteLn (1);\n' > "$WORK/r4.a24"
OUT=$("$ALGC" --compile --out="$WORK/nodir" "$WORK/r4.a24" 2>&1 || true)
if printf '%s' "$OUT" | grep -qi 'director'; then
    report R-4 "a missing --out directory is reported as an unopenable file" fixed ''
else
    report R-4 "a missing --out directory is reported as an unopenable file" open \
        "$(printf '%s' "$OUT" | tr '\n' ' ')"
fi
echo

# ---------------------------------------------------------------- group 6
echo "6. A unit name is compared case-sensitively"
D=$WORK/d1; mkdir -p "$D/a" "$D/b"
printf "unit Alpha;\nfunction FromUpper () : String;\nbegin\n    Exit 'upper';\nend\n" > "$D/a/Alpha.a24"
printf "unit alpha;\nfunction FromLower () : String;\nbegin\n    Exit 'lower';\nend\n" > "$D/b/alpha.a24"
cat > "$D/d1.a24" <<'EOF'
uses 'a/Alpha';
uses 'b/alpha';
WriteLn (FromUpper ());
WriteLn (FromLower ());
EOF
# ⚠️ The FIRST LINE of each, not the whole output.  All three must say the same
# thing, and what they say is the 'Uncaught:' sentence -- the [ERROR] excerpt
# below it is the same text again, and the compiled half is captured from the
# EMIT rather than from a run, which renders it differently.  Comparing whole
# outputs reported a divergence where the three agree completely.
said () { printf '%s' "$1" | sed 's/\x1b\[[0-9;]*m//g' | sed -n '1p'; }

I=$(cd "$D" && "$ALGC" d1.a24 2>&1 || true)
V=$(cd "$D" && "$ALGVM" d1.a24 2>&1 || true)
C=$(cd "$D" && compiled "$D" d1.a24)
if [ "$(said "$I")" = "$(said "$V")" ] && [ "$(said "$I")" = "$(said "$C")" ]; then
    report D-1 "two units whose names differ only in case" fixed ''
else
    report D-1 "two units whose names differ only in case" open \
        "interpreted '$(said "$I")', machine '$(said "$V")', compiled '$(said "$C")'"
fi
echo

# ---------------------------------------------------------------- group 7
echo "7. The runtime pair carries no version"
if grep -q 'ALG_RUNTIME_VERSION' "$ROOT/bootstrap/algol.h" 2>/dev/null \
   && grep -q '_Static_assert.*ALG_RUNTIME_VERSION' "$ROOT/bootstrap/algol.c" 2>/dev/null; then
    report R-15 "algol.c and algol.h are a pair with nothing checking the halves match" fixed ''
else
    report R-15 "algol.c and algol.h are a pair with nothing checking the halves match" open \
        "neither half records a release, so a mismatched pair reads as a corrupt runtime"
fi
echo

# ---------------------------------------------------------------- group 8
echo "8. vm/REFERENCE.md states a total its own body contradicts"
DECLARED=$(grep -c '^const OP_' "$ROOT/vm/OpCode.a24")
REAL=$((DECLARED - 1))
ENTRIES=$(grep -c '^## OP_' "$ROOT/vm/REFERENCE.md")

# ⚠️ FIXED means the file states NO count, not that it states the right one.
# A number in prose is a claim nothing checks, and the right fix was to delete
# the figure and let ./vm/reference.sh print it -- this repository's own OP_LONG
# rationale carried a stale nineteen-for-twenty-four in three files at once.
# So this looks for any surviving '**N opcodes**' at all.
STALE=$(grep -oE '\*\*[0-9]+ opcodes\*\*' "$ROOT/vm/REFERENCE.md" | head -1)

if [ -z "$STALE" ] && [ "$REAL" -eq "$ENTRIES" ]; then
    report D-2 "the reference's stated opcode total" fixed ''
elif [ -n "$STALE" ]; then
    report D-2 "the reference's stated opcode total" open \
        "OpCode.a24 has $REAL instructions and the reference carries $ENTRIES entries, under a heading saying $STALE"
else
    report D-2 "the reference's stated opcode total" open \
        "no count is stated, but OpCode.a24 has $REAL instructions and the reference carries $ENTRIES entries"
fi
echo

# ---------------------------------------------------------------- the two that are not repairs
echo "9. R-5 -- a runtime error carries no location"
cat > "$WORK/r5.a24" <<'EOF'
procedure Deep (X);   begin WriteLn (X - 1); end
procedure Middle (X); begin Deep (X);        end
WriteLn ('before');
Middle ('text');
EOF
OUT=$("$ALGC" "$WORK/r5.a24" 2>&1 || true)
if printf '%s' "$OUT" | grep -q 'r5.a24'; then
    report R-5 "a runtime error names no file, line or call stack" fixed ''
else
    ORDER=$(printf '%s' "$OUT" | head -1)
    report R-5 "a runtime error names no file, line or call stack" open \
        "the whole report is '$ORDER', and the program's own output arrives after it"
fi
echo

echo "10. R-13 -- the interpreter's memory"
# The report's own shape -- a long interpreted run -- needs shroom-slots, so
# what is checked here is the CAUSE: the interpreter declined to collect.
cat > "$WORK/r13.a24" <<'EOF'
for var I := 0; I < 20000; I := I + 1 do
begin
    var Junk := [I, I + 1, I + 2];
end
WriteLn (Collect () > 0);
EOF
I=$("$ALGC" "$WORK/r13.a24" 2>&1 || true)
if [ "$I" = "true" ]; then
    report R-13 "the interpreter declines to collect" fixed ''
else
    report R-13 "the interpreter declines to collect" open \
        "Collect () released nothing interpreted: '$I'.  The compiled back end has had a precise collector since v0.2.0; this processor refused one."
fi
echo
echo "11. A built-in held as a value"
# Found by probing item 2's edges rather than reported, so it carries no R- or
# D- number: FUN-011 makes a subprogram's name without parentheses a value and
# RT-001's built-ins are names like any other.  Both other processors do it.
cat > "$WORK/b11.a24" <<'EOF'
var F := Length;
WriteLn (F ('abc'));
WriteLn (Str (Length = Length));
EOF
I=$("$ALGC" "$WORK/b11.a24" 2>&1 || true)
V=$("$ALGVM" "$WORK/b11.a24" 2>&1 || true)
D=$WORK/b11; mkdir -p "$D"
C=$(compiled "$D" "$WORK/b11.a24")
if [ "$I" = "$V" ] && [ "$I" = "$C" ]; then
    report BI-1 "a built-in held as a value" fixed ''
else
    report BI-1 "a built-in held as a value" open \
        "interpreted '$(printf '%s' "$I" | tr '\n' '/')', machine '$(printf '%s' "$V" | tr '\n' '/')', compiled '$(printf '%s' "$C" | tr '\n' '/')'"
fi

# ⚠️ Interning is the half a naive fix would miss: these compare by IDENTITY
# [VAL-011], so one value per name is required and a fresh one per read answers
# false.  The second line of the program above is what asks.
echo


echo "----------------------------------------------------------------"
printf '%s reproducing, %s fixed, of %s checked\n' "$OPEN" "$FIXED" "$((OPEN + FIXED))"
echo
if [ "$OPEN" -gt 0 ]; then
    echo "Not green yet.  finished/PLAN-0.2.4.md carries the root cause for each."
    exit 1
fi
echo "Green: every reported defect is fixed."
