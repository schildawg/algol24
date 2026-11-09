#!/bin/sh
#
# GENERATES vm/dispatch.c -- the machine's dispatch loop, in hand-written C
# over the SAME Algol-24 handlers.
#
#   ./vm/dispatch.sh          # regenerate, and say what changed
#   ./vm/dispatch.sh --check  # fail if the file is not what this would write
#
# ⚠️ GENERATED, not written.  The switch has one arm per opcode and the arms
# come from vm/Vm.a24's own BuildHandlers table, so adding an opcode means
# regenerating rather than remembering.  --check is what holds it in step, and
# vm/build.sh runs it.
#
# ⚠️ WHAT THIS BUYS, and it is the only change in the machine that helps it
# more than it helps the compiled back end.  Per bytecode the Algol-24 loop
# does a subscript into the handler Array and then alg_call, which walks six
# is_obj tag checks -- class, bound method, overload set, builtin-bound,
# extension -- before it reaches a plain closure.  A C loop calls
# f_doconstant(NULL, NULL, 0) directly and touches v_ip.integer as a struct
# field rather than through alg_declared/alg_widen/alg_add.
#
# ⚠️ WHAT IT COSTS is the calling convention.  Giving C a stable name to call
# FREEZES `Value **cells, Value *args, int32_t count`, which is private to the
# emitter today and has changed before.  A change to it now breaks this file,
# which is why this script exists rather than a hand-maintained copy: the
# breakage is a regeneration away.
#
# ⚠️ sh AND awk ONLY, like every other generator here (docs.sh, conform.sh,
# spec/spec.sh, vm/reference.sh).  It read vm/OpCode.a24 with python3 once and
# the Windows job has none, so ./vm/build.sh died there with
# `python3: command not found` -- on the one platform where the checked-in
# vm/dispatch.c would otherwise have gone unchecked.  A C compiler is the only
# dependency this repository takes, and a generator is no place to add one.
#
# ⚠️ AND IT COSTS -Wl,-export_dynamic.  The loop reaches the handlers through
# a no-library `external`, which resolves with dlsym(RTLD_DEFAULT, ...) -- and
# that finds nothing unless the binary's own symbols are in its dynamic table.
# vm/build.sh passes the flag; algc does not need it and does not get it.
set -eu

ROOT=$(cd "$(dirname "$0")/.." && pwd)
cd "$ROOT"

OUT=vm/dispatch.c
CHECK=0
[ "${1:-}" = "--check" ] && CHECK=1

WORK=$(mktemp -d "${TMPDIR:-/tmp}/algol24-dispatch.XXXXXX")
trap 'rm -rf "$WORK"' EXIT


# The hand-written fast arms, one file each, spliced into the arm for that
# opcode.  @SP@, @SLOTS@ and @HANDLER@ are filled with the mangled symbols.
#
# The Algol-24 handler stays the DEFINITION and still answers everything the
# fast path declines -- there is no second implementation of an operator here,
# only a shortcut past the plumbing for the case the fast path recognises.
# That is what keeps this out of the "two implementations to hold in
# agreement" trade a wholesale handler rewrite would make.
#
# What a fast arm saves is the STACK rather than the arithmetic: Slots is an
# Array, so Push and Pop each go through alg_subscript_get/set, which try Map,
# Buffer, Set, sequence and text in turn before they can index.
mkdir -p "$WORK/fast"

cat > "$WORK/fast/OP_ADD" <<'ARMEOF'
                /* Two numbers held inline cannot be a VmInstance, so DoAdd's
                   operator-overload check cannot apply [EXP-020] -- and
                   alg_add still does the adding, so unbounded overflow and
                   the type rules stay in exactly one place. */
                int64_t sp = @SP@.integer;
                Value  *s  = alg_array_slots(@SLOTS@);

                if (s != NULL && sp >= 2
                        && alg_plain_number(s[sp - 2])
                        && alg_plain_number(s[sp - 1])) {
                    s[sp - 2] = alg_add(s[sp - 2], s[sp - 1]);

                    @SP@.integer = sp - 1;
                    break;
                }

                @HANDLER@(NULL, NULL, 0);
                break;
ARMEOF

awk -v fast="$WORK/fast" > "$WORK/dispatch.c" '
# Annex G.3, as far as an opcode or handler name needs it: every letter and
# digit lowercases and "_" becomes "V".  Nothing here carries a character
# needing the U-plus-six-hex form, and a name that did would be a bug in the
# caller rather than something to escape quietly.
function mangle(prefix, name,    i, c, out) {
    out = ""

    for (i = 1; i <= length(name); i++) {
        c = substr(name, i, 1)

        if (c == "_")                out = out "V"
        else if (c ~ /[A-Za-z0-9]/)  out = out tolower(c)
        else {
            printf("dispatch.sh: %s cannot be a C symbol\n", name) > "/dev/stderr"
            exit 1
        }
    }

    return prefix out
}

function w(line) { OUT[++N] = line }

# vm/OpCode.a24 -- the numbers.
FILENAME ~ /OpCode\.a24$/ && /^const +OP_[A-Z_]+ +:= +[0-9]+;/ {
    name = $2
    num  = $4
    sub(/;$/, "", num)

    NUMBER[name] = num
    HAS[name]    = 1

    next
}

# vm/Vm.a24 -- the handler table, read only between BuildHandlers and its end.
FILENAME ~ /Vm\.a24$/ {
    if ($0 ~ /^function +BuildHandlers +\(\)/) { inside = 1; next }
    if (!inside) next
    if ($0 ~ /^end[ \t]*$/)                    { inside = 0; next }

    if (match($0, /Table\[[^]]+\][ \t]*:=[ \t]*[A-Za-z0-9_]+;/) == 0) next

    s   = substr($0, RSTART, RLENGTH)
    kb  = index(s, "[") + 1
    key = substr(s, kb, index(s, "]") - kb)
    val = substr(s, index(s, ":=") + 2)

    sub(/^[ \t]+/, "", val)
    sub(/;.*$/, "", val)

    if (key == "Slot") { unknown = val; next }

    if (!(key in HAS)) {
        printf("dispatch.sh: %s is in BuildHandlers and not in OpCode.a24\n",
               key) > "/dev/stderr"
        exit 1
    }

    n = NUMBER[key]

    if (n in ARMOP) {
        printf("dispatch.sh: opcode %d is %s and %s\n", n, ARMOP[n], key) \
            > "/dev/stderr"
        exit 1
    }

    ARMOP[n]  = key
    ARMFN[n]  = val
    SEEN[val] = 1

    if (n > top) top = n
    arms++

    if (length(key) > width) width = length(key)

    next
}

END {
    if (arms == 0) {
        print "dispatch.sh: BuildHandlers has no opcode arms" > "/dev/stderr"
        exit 1
    }

    if (unknown == "") {
        print "dispatch.sh: BuildHandlers has no default handler" > "/dev/stderr"
        exit 1
    }

    SEEN[unknown] = 1

    # The prototypes are sorted, so a regeneration after adding an opcode
    # moves one line rather than reordering the block.  Insertion sort: there
    # are eighty of them and asort is not in every awk.
    hn = 0
    for (h in SEEN) HLIST[++hn] = h

    for (i = 2; i <= hn; i++) {
        pick = HLIST[i]

        for (j = i - 1; j >= 1 && HLIST[j] > pick; j--) HLIST[j + 1] = HLIST[j]

        HLIST[j + 1] = pick
    }

    w("/* GENERATED by ./vm/dispatch.sh -- do not edit.  Regenerate instead. */")
    w("")
    w("#include \"algol.h\"")
    w("")
    w("/* The machine'\''s state, which lives in vm/Vm.a24 as module-level variables")
    w("   and reaches C as ordinary globals.  Touched as struct fields rather than")
    w("   through the runtime, which is most of what this loop exists to do.")
    w("")
    w("   IP, Tick, COLLECT_EVERY and TRACE_ROOM are Integers and stay VAL_INT for")
    w("   a whole run, so writing .integer keeps the tag it already has.  Live is a")
    w("   Boolean. */")

    gn = split("IP Live Tick COLLECT_EVERY TRACE_ROOM CodeBytes Slots SP", G, " ")
    for (i = 1; i <= gn; i++) w("extern Value " mangle("v_", G[i]) ";")

    w("")
    w("/* The handlers, unchanged and still in Algol-24.  This is the convention")
    w("   the emitter gives a top-level subprogram, and calling them directly is")
    w("   what freezes it -- see vm/dispatch.sh. */")

    for (i = 1; i <= hn; i++)
        w("Value " mangle("f_", HLIST[i]) "(Value **cells, Value *args, int32_t count);")

    w("Value f_traced(Value **cells, Value *args, int32_t count);")
    w("")
    w("/* Reached from vm/Vm.a24 as a no-library `external`, once per run rather")
    w("   than once per instruction, so the foreign call costs nothing measurable.")
    w("")
    w("   ⚠️ THE BYTES ARE RE-READ EVERY INSTRUCTION, and must be: entering or")
    w("   leaving a frame assigns CodeBytes := Running.Code, so a pointer taken")
    w("   once would read the CALLER'\''s bytecode for the whole of a call.  The")
    w("   Algol-24 loop re-reads it too, by going through CodeBytes[IP] each time.")
    w("")
    w("   RETURNS when Live goes false.  A host error does NOT return: alg_error")
    w("   longjmps past this frame to the try in RunLoop, which is safe because")
    w("   this function holds nothing that needs unwinding and alg_raise truncates")
    w("   the shadow stack itself. */")
    w("void alg_vm_dispatch(void) {")
    w("    while (" mangle("v_", "Live") ".boolean) {")
    w("        const unsigned char *code = alg_buffer_bytes(" mangle("v_", "CodeBytes") ");")
    w("")
    w("        if (code == NULL) { " mangle("f_", unknown) "(NULL, NULL, 0); continue; }")
    w("")
    w("        int64_t op = code[" mangle("v_", "IP") ".integer];")
    w("")
    w("        " mangle("v_", "IP") ".integer += 1;")
    w("")
    w("        /* One test per instruction, as the Algol-24 loop pays: measured at")
    w("           about 2.5% there and kept rather than dropped, because a trace")
    w("           nobody can turn on is a trace nobody has. */")
    w("        if (" mangle("v_", "TRACE_ROOM") ".integer > 0) {")
    w("            Value at[2];")
    w("")
    w("            at[0] = alg_int(" mangle("v_", "IP") ".integer - 1);")
    w("            at[1] = alg_int(op);")
    w("")
    w("            f_traced(NULL, at, 2);")
    w("        }")
    w("")
    w("        switch (op) {")

    for (n = 0; n <= top; n++) {
        if (!(n in ARMOP)) continue

        op = ARMOP[n]
        arm = fast "/" op
        lines = 0

        while ((getline line < arm) > 0) {
            ARM[++lines] = line
        }
        close(arm)

        if (lines > 0) {
            w(sprintf("            case %3d: { /* %s -- fast path, see the fast arms in dispatch.sh */", n, op))

            for (i = 1; i <= lines; i++) {
                line = ARM[i]
                gsub(/@SP@/,      mangle("v_", "SP"),   line)
                gsub(/@SLOTS@/,   mangle("v_", "Slots"), line)
                gsub(/@HANDLER@/, mangle("f_", ARMFN[n]), line)
                w(line)
            }

            w("            }")
            w("")

            continue
        }

        label = "/* " op " */"
        pad   = width + 6 - length(label)
        while (pad-- > 0) label = label " "

        w(sprintf("            case %3d: %s %s(NULL, NULL, 0); break;",
                  n, label, mangle("f_", ARMFN[n])))
    }

    w("")
    w("            /* Every byte that is not an instruction, named by the same")
    w("               handler the Algol-24 table gives it -- so a bad byte reports")
    w("               an opcode rather than a subscript. */")
    w("            default: " mangle("f_", unknown) "(NULL, NULL, 0); break;")
    w("        }")
    w("")
    w("        /* THE SAFE POINT, in the same place the Algol-24 loop has it: an")
    w("           instruction has finished, so every live guest value is on Slots")
    w("           or in a module-level variable [RT-029]. */")
    w("        " mangle("v_", "Tick") ".integer += 1;")
    w("")
    w("        if (" mangle("v_", "COLLECT_EVERY") ".integer > 0 && " mangle("v_", "Tick") ".integer >= " mangle("v_", "COLLECT_EVERY") ".integer) {")
    w("            " mangle("v_", "Tick") ".integer = 0;")
    w("")
    w("            alg_collect();")
    w("        }")
    w("    }")
    w("}")

    for (i = 1; i <= N; i++) print OUT[i]

    printf("dispatch.sh: %d opcode arm(s), %d handler(s), default %s\n",
           arms, hn, unknown) > "/dev/stderr"
}
' vm/OpCode.a24 vm/Vm.a24

if [ "$CHECK" -eq 1 ]; then
    if cmp -s "$WORK/dispatch.c" "$OUT"; then
        echo "OK: $OUT is what vm/dispatch.sh writes."
    else
        echo "FAIL: $OUT is stale.  Run ./vm/dispatch.sh" >&2
        diff "$OUT" "$WORK/dispatch.c" | head -20 >&2
        exit 1
    fi
    exit 0
fi

if cmp -s "$WORK/dispatch.c" "$OUT" 2>/dev/null; then
    echo "unchanged: $OUT"
else
    cp "$WORK/dispatch.c" "$OUT"
    echo "wrote $OUT"
fi
