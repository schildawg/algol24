#!/bin/sh
#
# Builds algvm, the bytecode machine, from vm/run.a24.
#
#   ./vm/build.sh                      # -> vm/algvm
#   ./vm/build.sh /tmp/algvm           # ... somewhere else
#   CC=clang CFLAGS=-O0 ./vm/build.sh
#   LTO=0 ./vm/build.sh                # ... without link-time optimization
#
# ⚠️ FOREIGN CALLS ARE NOT A SWITCH HERE, and that is the difference from
# bootstrap/build.sh.  A foreign call is a feature of the language [FUN-014],
# so the machine always has one: there is no `--ffi`, and a build that cannot
# find libffi fails rather than quietly producing a binary that answers
# 'Foreign calls are not available in this build'.
#
# algc has the switch for a reason that does not apply here.  The compiler must
# build from a C compiler and nothing else, because the only way into the
# language is a checked-in copy of its own output -- so its default build
# carries no dependency it could be blocked on.  The machine is a SECOND binary,
# built by someone who already has algc, and is in no bootstrap path at all.
#
# The header is not always at the top of the include path: macOS ships libffi
# in the SDK with ffi.h one directory down, which is why algol.c writes
# `#include <ffi/ffi.h>` on Apple.  FFI_CFLAGS and FFI_LIBS override both
# halves for a toolchain that puts them somewhere else again.

set -eu

cd "$(dirname "$0")/.."

CC="${CC:-cc}"
CFLAGS="${CFLAGS:--std=c11 -O2}"
ALGC="${ALGC:-bootstrap/algc}"
OUT="${1:-vm/algvm}"

FFI_CFLAGS="${FFI_CFLAGS:--DALG_FFI}"
FFI_LIBS="${FFI_LIBS:--lffi}"

[ -x "$ALGC" ] || { echo "no $ALGC -- run ./bootstrap/build.sh first" >&2; exit 1; }

WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT

# Link-time optimization, probed rather than assumed because -flto needs a
# linker plugin some toolchains do not have.  The probe LINKS as well as
# compiles, since that is where it actually fails.
_want_lto="${LTO:-1}"
LTO=""
if [ "$_want_lto" != 0 ]; then
    printf 'int main(void){return 0;}\n' > "$WORK/probe.c"

    # shellcheck disable=SC2086
    if $CC $CFLAGS -flto -o "$WORK/probe" "$WORK/probe.c" 2>/dev/null; then
        LTO="-flto"
    fi
fi

# Compiled from the repository root, so that `uses 'compiler/Parser'` resolves:
# the machine imports the compiler's front end rather than being imported into
# it, which is what keeps compiler/ untouched and the VM out of the seed.
mkdir -p "$WORK/out"
"$ALGC" --compile --out="$WORK/out" vm/run.a24

# ⚠️ THE DISPATCH LOOP IS GENERATED, and stale is worse than absent: an opcode
# added to vm/Vm.a24's table without regenerating would reach DoUnknown in the
# C loop and the right handler in the Algol-24 one, which is a divergence
# between two builds of one machine.  Checked here rather than trusted.
./vm/dispatch.sh --check

# ⚠️ WHETHER TO LINK IT, which is not a question anywhere the loop works.
#
# The C loop SEGFAULTS on Windows: `algvm hello.a24` exits 139 where the same
# binary's `--stop` and `--algol-loop` both answer, and `algc` answers, so
# compiling and the handlers are fine and the loop alone is not.  Root cause
# unknown, and not reproducible on a Unix.
#
# NOT DEFAULTED OFF ANYWHERE, because leaving it out would be a bypass rather
# than a fix.  vm/Vm.a24 asks `alg_vm_dispatch_present` inside a try and falls
# back when the symbol is absent, so CDISPATCH=0 produces a correct, roughly
# 1.5x slower machine -- which is the escape hatch for someone bisecting the
# crash, not the shipped answer.
#
#   CDISPATCH=0   leave the C loop out and run the Algol-24 one
_want_c="${CDISPATCH:-1}"

if [ "$_want_c" != 0 ]; then
    cp vm/dispatch.c "$WORK/out/dispatch.c"
fi

# The flag that puts the binary's OWN symbols where it can look them up, for
# the one thing that needs it: the C loop is reached through a no-library
# `external`, which resolves with dlsym(RTLD_DEFAULT, ...) -- and that finds
# nothing unless the symbols are reachable.  bootstrap/build.sh needs none of
# this and gets none of it, which is what keeps the seed as it was.
#
# ⚠️ PROBED, AND THE PROBE RUNS, because the spelling differs per platform and
# accepting a flag is not the same as the lookup working.  -export_dynamic is
# Apple's, --export-dynamic is GNU/ELF's, and PE exports nothing from an
# executable without --export-all-symbols.  It was hard-coded to Apple's, so
# the Windows job linked happily and then could not find its own dispatch loop
# -- `algvm hello.a24` failed where `algvm --version` and the machine's own
# tests under algc both passed, because neither runs the C loop.
# ⚠️ THE PROBE CALLS THROUGH THE POINTER, and it is TWO translation units.
#
# The first version asked only whether the lookup answered non-NULL, with the
# target in the same file as main.  Both were wrong, and together they passed
# --export-all-symbols on Windows while the real binary jumped to a bad
# address: GetProcAddress answered a pointer that was not the function, so the
# check "did we find it" said yes and the call segfaulted inside libffi.
#
# So the target lives in its own file, compiled and linked exactly as
# vm/dispatch.c is -- $LTO included, since nothing references it and that is
# what might move or drop it -- and the probe CALLS it.  A wrong address fails
# the probe by crashing it, which is the only way to tell a found symbol from
# a usable one.
cat > "$WORK/exports_target.c" <<'PROBEEOF'
/* Referenced by nothing and annotated exactly as vm/dispatch.c's two names
   are, so the probe answers for the combination the machine actually uses. */
#if defined(_WIN32)
#define ALG_VM_EXPORTED __declspec(dllexport)
#else
#define ALG_VM_EXPORTED __attribute__((used, visibility("default")))
#endif

ALG_VM_EXPORTED int alg_probe_target(void) { return 24; }
PROBEEOF

cat > "$WORK/exports.c" <<'PROBEEOF'
#include <stddef.h>

#if defined(_WIN32)
#include <windows.h>
static void *self_lookup(const char *name) {
    return (void *)GetProcAddress(GetModuleHandleA(NULL), name);
}
#else
#include <dlfcn.h>
static void *self_lookup(const char *name) { return dlsym(RTLD_DEFAULT, name); }
#endif

#include <stdio.h>

int main(void) {
    int (*found)(void) = (int (*)(void))self_lookup("alg_probe_target");

    if (found == NULL) return 1;

    /* Crashes here rather than answering, if the address is not the function. */
    if (found() != 24) return 1;

    /* PRINTED, and the caller compares it.  A combination that links and then
       produces an executable which runs but does nothing has to fail too:
       -export_dynamic on MinGW does exactly that, and an exit status alone
       called it a success. */
    printf("usable\n");
    return 0;
}
PROBEEOF

EXPORTS=""
_exports_found=0

# ⚠️ LTO IS PART OF THE COMBINATION, not a separate choice.
#
# On MinGW --export-all-symbols is the flag that works and -flto breaks it:
# the symbol is found and its address is not the function, so the call lands
# in the middle of nowhere.  And the flag that linked instead, -export_dynamic,
# produced an executable that ran and printed nothing at all -- both loops, not
# just the C one.
#
# So the search is over (link-time optimization, flag) pairs, LTO first
# because it is worth about 24% to this loop, and the probe's OUTPUT decides.
# Preferring LTO and then picking any flag that merely links is what shipped a
# broken Windows binary twice.
_try_exports () {
    for _flag in "-Wl,--export-all-symbols" "-Wl,-export_dynamic" \
                 "-Wl,--export-dynamic" "-rdynamic" ""; do
        for _dl in "" "-ldl"; do
            # shellcheck disable=SC2086
            if [ "$($CC $CFLAGS $1 $_flag -o "$WORK/exports" \
                        "$WORK/exports.c" "$WORK/exports_target.c" $_dl \
                        2>/dev/null && "$WORK/exports" 2>/dev/null)" = "usable" ]; then
                EXPORTS="$_flag"
                return 0
            fi
        done
    done

    return 1
}

if [ "$_want_c" != 0 ]; then
    if _try_exports "$LTO"; then
        _exports_found=1
    elif [ -n "$LTO" ] && _try_exports ""; then
        # The machine keeps its C loop and gives up link-time optimization,
        # which is the better half of that trade: the loop is 1.5x and LTO is
        # about 24% of what is left.
        _exports_found=1
        LTO=""
    fi
else
    _exports_found=1
fi

if [ "$_exports_found" -eq 0 ] && [ "$_want_c" != 0 ]; then
    echo "This toolchain cannot make a binary find its own symbols, which the" >&2
    echo "machine's C dispatch loop is reached through.  Tried:" >&2
    echo "  --export-all-symbols, -export_dynamic, --export-dynamic, -rdynamic" >&2
    echo "and no flag made dlsym(RTLD_DEFAULT, ...) answer." >&2
    exit 1
fi

# shellcheck disable=SC2086
if ! $CC $CFLAGS $LTO $FFI_CFLAGS $EXPORTS -o "$OUT" "$WORK/out"/*.c $FFI_LIBS 2>"$WORK/cc.log"; then
    cat "$WORK/cc.log" >&2
    echo >&2
    echo "algvm needs libffi: a foreign call is part of the language [FUN-014]," >&2
    echo "so the machine is not built without one.  Install libffi, or set" >&2
    echo "FFI_CFLAGS and FFI_LIBS if your toolchain keeps it somewhere else." >&2
    exit 1
fi

echo "Built $OUT  (with foreign calls)${LTO:+  (link-time optimized)}"

if [ "$_want_c" != 0 ]; then
    echo "  dispatch: the C loop, own symbols reachable with ${EXPORTS:-no flag needed}"
else
    echo "  dispatch: the Algol-24 loop -- the C one is left out on this platform"
fi
