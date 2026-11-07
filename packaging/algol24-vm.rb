# The Homebrew formula for the Algol-24 bytecode machine and its library --
# "the complete package": a runtime and something to write programs against.
#
# Kept here so it is versioned with the thing it packages, like algol24.rb; the
# tap that serves it is github.com/schildawg/homebrew-algol24, whose
# Formula/algol24-vm.rb is a copy of this file with a bottle block that
# 'brew pr-pull' writes.
#
# ⚠️ IT DOES NOT CONFLICT WITH algol24, and the two are meant to coexist.
# algol24 installs bin/algc, this installs bin/algvm, and a user who wants to
# compile as well as run installs both.
#
# ⚠️ sdl2 is a REAL dependency where libffi is not.  A --ffi build links the
# system libffi, which is why algol24.rb declares nothing; the library's
# 'graph' and 'sound' reach SDL2, and its build script asks sdl2-config for the
# flags -- so the dependency is the library's rather than the machine's.
class Algol24Vm < Formula
  desc "Bytecode machine for Algol-24, with the Algol-24 runtime library"
  homepage "https://github.com/schildawg/algol24"
  url "https://github.com/schildawg/algol24/archive/refs/tags/v0.2.4.tar.gz"
  sha256 "9d9dc66a8029470687a1206afd044f8f824c9ff6fa29db1404cc00ac63220145"
  license "MIT"
  head "https://github.com/schildawg/algol24.git", branch: "main"

  # ⚠️ sdl2-compat AND NOT sdl2, which is merely its alias -- `brew linkage
  # --test` reports a dylib reached through an alias as an INDIRECT dependency
  # and fails the formula for it.  Homebrew's sdl2 has become a compatibility
  # layer over SDL3, so the name that actually owns libSDL2 is this one.
  depends_on "sdl2-compat"

  # ⚠️ LINUX-ONLY, and the asymmetry is the operating system's: macOS ships the
  # foreign-call library in /usr/lib and Linux has to be told.  The machine
  # always needs it -- a foreign call is a feature of the language rather than
  # a build option [FUN-014], so vm/build.sh fails without one instead of
  # producing a binary that refuses foreign calls at run time.
  on_linux do
    depends_on "libffi"
  end

  # ⚠️ PINNED, and to a VERSION rather than a branch: the bundle is a pairing
  # of two releases, and `algol24-vm 0.2.2` carrying `algol24-library 0.1.0`
  # says which.  The library's number is its own and does not track this one --
  # it is a separate repository with its own release events and its own defect
  # record, where algc and algvm are two binaries from one tree and so share a
  # version.
  resource "library" do
    url "https://github.com/schildawg/algol24-library/archive/refs/tags/v0.1.0.tar.gz"
    sha256 "e0e5e2131548519a41b58b2caf9343cff89f720fb7af52e816b109965405eb5c"
  end

  def install
    # The machine is built BY algc, so the compiler comes first.  A plain build
    # is enough: algc is only asked to --compile here, and the machine gets its
    # own foreign-call support from vm/build.sh, which always links libffi
    # because a foreign call is a feature of the language rather than a build
    # option [FUN-014].
    system "./bootstrap/build.sh"
    system "./vm/build.sh"

    libexec.install "vm/algvm"

    # ⚠️ INTO libexec/lib, AND THE NAME MATTERS.  The compiler resolves a
    # 'uses' against an installed library by looking beside its own binary for
    # a 'lib' directory [MOD-002] -- so this one directory is what makes
    # 'uses graph;' work from any program, with no path written in it.
    resource("library").stage do
      # Builds lib*ffi.so, asking sdl2-config for the flags graph and sound
      # need.  The shims are named .so on every platform, macOS included,
      # because the units' own 'external ... in' clauses say so.
      system "./build.sh"

      (libexec/"lib").install Dir["*.a24"]
      (libexec/"lib").install Dir["*.hex"], "beep.wav"
      (libexec/"lib").install Dir["lib*ffi.so"]
      (libexec/"lib").install "REFERENCE.md"
    end

    # ⚠️ A WRAPPER, and all three of these are load-bearing.
    #
    # The loader path: a unit declares its shim as "external ... in
    # 'libgraphffi.so'", and dlopen is handed that name exactly as written --
    # so a relative one resolves against the working directory, and without
    # this the library works only when run from its own install directory.
    # The variable's NAME is the platform's: dyld reads one and ld.so another,
    # and setting the wrong one fails silently rather than loudly.
    #
    # ALGOL24_LIB: 'graph' reads its glyph files itself rather than through the
    # compiler, so an installed font has to be named rather than searched for.
    #
    # And the real binary is exec'd from libexec so that argv[0] stays there,
    # which is what lets the compiler find libexec/lib beside it.
    loader = OS.mac? ? "DYLD_LIBRARY_PATH" : "LD_LIBRARY_PATH"

    (bin/"algvm").write <<~SHELL
      #!/bin/sh
      #{loader}="#{libexec}/lib${#{loader}:+:$#{loader}}" \\
      ALGOL24_LIB="#{libexec}/lib" \\
      exec "#{libexec}/algvm" "$@"
    SHELL

    doc.install "README.md", "spec/ALGOL-24.md"
  end

  test do
    # ⚠️ HEADLESS, because a test runner has no display: `graph` opens a real
    # window otherwise and fails with `Graph could not start: The video driver
    # did not add any displays`.  The library's own test script sets the same
    # variable for the same reason; a user's install is untouched by it, since
    # this is the test's environment and not the wrapper's.
    ENV["SDL_VIDEODRIVER"] = "dummy"
    ENV["ALG_SOUND"] = "dummy"

    assert_match "algvm", shell_output("#{bin}/algvm --version")

    (testpath/"hello.a24").write "WriteLn ('hello, ' + Str (2 + 2));\n"
    assert_equal "hello, 4\n", shell_output("#{bin}/algvm hello.a24")

    # ⚠️ ErrorLn [RT-030] must not reach STANDARD OUTPUT, which is the whole of
    # what it is for: a diagnostic has to survive `prog > results.txt` without
    # corrupting what the program produced.  shell_output captures stdout only,
    # so stdout holding the FIRST line and nothing else is the assertion.
    (testpath/"streams.a24").write <<~ALGOL
      WriteLn ('to output');
      ErrorLn ('to the error stream');
    ALGOL
    assert_equal "to output\n", shell_output("#{bin}/algvm streams.a24")

    # ⚠️ THE POINT OF THE PACKAGE: a bare 'uses' of an installed unit, from a
    # directory holding none of the library's files.  This is what the install
    # exists to make work, and it failed in three separate ways before it did.
    (testpath/"lib.a24").write <<~ALGOL
      uses strings;

      WriteLn (ToUpper ('shouting'));
    ALGOL
    assert_equal "SHOUTING\n", shell_output("#{bin}/algvm lib.a24")

    # And a unit that needs both a C shim and a data file, which is the half
    # that needs the wrapper rather than the compiler's own search.
    (testpath/"font.a24").write <<~ALGOL
      uses graph;

      InitGraph (160, 100, 'test', False);
      OutTextXY (4, 4, 'drawn');
      CloseGraph ();
    ALGOL
    system bin/"algvm", "font.a24"
  end
end
