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

cp vm/dispatch.c "$WORK/out/dispatch.c"

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

void alg_probe_target(void) { }

int main(void) { return self_lookup("alg_probe_target") != NULL ? 0 : 1; }
PROBEEOF

EXPORTS=""
_exports_found=0

for _flag in "-Wl,--export-all-symbols" "-Wl,-export_dynamic" \
             "-Wl,--export-dynamic" "-rdynamic" ""; do
    for _dl in "" "-ldl"; do
        # shellcheck disable=SC2086
        # $LTO too, because the target is unreferenced -- nothing calls
        # alg_vm_dispatch statically -- and link-time optimization is exactly
        # what might drop it.  A probe that does not mirror the real link can
        # answer for a build nobody makes.
        if $CC $CFLAGS $LTO $_flag -o "$WORK/exports" "$WORK/exports.c" $_dl \
               2>/dev/null && "$WORK/exports"; then
            EXPORTS="$_flag"
            _exports_found=1
            break
        fi
    done

    [ "$_exports_found" -eq 1 ] && break
done

if [ "$_exports_found" -eq 0 ]; then
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
echo "  own symbols reachable with: ${EXPORTS:-no flag needed}"
