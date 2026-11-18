# The Homebrew formula for Algol-24.
#
# Lives here so it is versioned with the thing it packages; the tap that serves
# it is a separate repository, github.com/schildawg/homebrew-algol24, whose
# Formula/algol24.rb is a copy of this file with the url and sha256 for the
# release being published.
#
# ⚠️ THE DEPENDENCY IS LINUX-ONLY, and the asymmetry is the operating system's.
# A --ffi build links the foreign-call library; macOS ships one in /usr/lib, so
# a mac bottle needs nothing beyond the OS, and Linux has to be told.  That is
# the only thing the two platforms do not share here.
#
# ⚠️ Naming that library in the ordinary way inside a COMMENT fails
# 'brew style': the audit reads it as a dependency someone commented out.  It
# is named for real below, where it belongs.
#
# ⚠️ IT CARRIES THE RUNTIME LIBRARY, exactly as algol24-vm.rb does, and that is
# a FIX rather than a convenience.  A user who installed the compiler alone got
# a language with nothing to write programs against: `uses graph;` resolved
# nowhere, and `shroom-slots` reported it as not being able to use the library
# with the compiler.  The two formulae pin the SAME library release on purpose,
# so that a machine with both installed has one library and not two that
# disagree.
class Algol24 < Formula
  desc "Retro-modern, gradually typed, self-hosting language, with its library"
  homepage "https://github.com/schildawg/algol24"
  url "https://github.com/schildawg/algol24/archive/refs/tags/v0.5.0.tar.gz"
  sha256 "4ebff74b24f893cf9124a5c8d39678eb6d0984566567cf4d280072228704874b"
  license "MIT"
  head "https://github.com/schildawg/algol24.git", branch: "main"

  # ⚠️ sdl2-compat AND NOT sdl2, which is merely its alias -- `brew linkage
  # --test` reports a dylib reached through an alias as an INDIRECT dependency
  # and fails the formula for it.  Homebrew's sdl2 has become a compatibility
  # layer over SDL3, so the name that actually owns libSDL2 is this one.
  #
  # The dependency is the LIBRARY's and not the compiler's: 'graph' and 'sound'
  # reach SDL2 and the library's build script asks sdl2-config for the flags.
  depends_on "sdl2-compat"

  on_linux do
    depends_on "libffi"
  end

  # ⚠️ PINNED to the same release algol24-vm.rb pins, and to a VERSION rather
  # than a branch: the bundle is a pairing of two releases, and `algol24 0.5.0`
  # carrying `algol24-library 0.3.1` says which.  The library's number is its
  # own and does not track this one -- it is a separate repository with its own
  # release events and its own defect record, where algc and algvm are two
  # binaries from one tree and so share a version.
  resource "library" do
    url "https://github.com/schildawg/algol24-library/archive/refs/tags/v0.3.1.tar.gz"
    sha256 "1f3c9c523222418ed1cc29e78647d8557f28fa804c0d536b059ae91d835d9727"
  end

  def install
    # Foreign calls are part of the language, so the packaged build has them.
    # The bootstrap stays buildable with a C compiler and nothing else -- that
    # is what ./bootstrap/build.sh with no argument is for.
    system "./bootstrap/build.sh", "--ffi"

    # ⚠️ INTO libexec, WITH THE RUNTIME BESIDE IT.  'algc --compile' copies
    # algol.c and algol.h into the directory it emits, so that the result
    # compiles on its own -- and it finds them beside the executable.
    libexec.install "bootstrap/algc"
    libexec.install "bootstrap/algol.c", "bootstrap/algol.h"

    # ⚠️ INTO libexec/lib, AND THE NAME MATTERS.  The compiler resolves a
    # 'uses' against an installed library by looking beside its own binary for
    # a 'lib' directory [MOD-002] -- so this one directory is what makes
    # 'uses graph;' work from any program, with no path written in it.
    #
    # ⚠️ AND THE SHIMS GO IN THE SAME DIRECTORY FOR THE SAME REASON [FUN-017].
    # A library's units and the shared objects they call into are one install,
    # and a bare name in an 'external ... in' clause is searched there too.
    # This needs the --ffi build above: without one every unit of the library
    # that reaches C resolves and then fails at its first call.
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

    # ⚠️ A wrapper rather than a symlink, and ALGOL24_LIB is why it is now
    # load-bearing: 'graph' reads its glyph files itself rather than through
    # the compiler, so an installed font has to be named rather than searched
    # for.  The real binary is exec'd from libexec so that argv[0] stays
    # there, which is what lets the compiler find libexec/lib beside it.
    (bin/"algc").write <<~SHELL
      #!/bin/sh
      ALGOL24_LIB="#{libexec}/lib" \\
      exec "#{libexec}/algc" "$@"
    SHELL

    doc.install "README.md", "spec/ALGOL-24.md", "spec/LIBRARY.md"
    pkgshare.install "examples"
  end

  test do
    # ⚠️ HEADLESS, because a test runner has no display: `graph` opens a real
    # window otherwise and fails with `Graph could not start: The video driver
    # did not add any displays`.  This is the test's environment and not the
    # wrapper's, so a user's install is untouched by it.
    ENV["SDL_VIDEODRIVER"] = "dummy"
    ENV["ALG_SOUND"] = "dummy"

    assert_match "algc", shell_output("#{bin}/algc --version")

    (testpath/"hello.a24").write "WriteLn ('hello, ' + Str (2 + 2));\n"
    assert_equal "hello, 4\n", shell_output("#{bin}/algc hello.a24")

    # ⚠️ ErrorLn [RT-030] must not reach STANDARD OUTPUT, which is the whole of
    # what it is for: a diagnostic has to survive `prog > results.txt` without
    # corrupting what the program produced.  shell_output captures stdout only,
    # so stdout holding the FIRST line and nothing else is the assertion.
    (testpath/"streams.a24").write <<~ALGOL
      WriteLn ('to output');
      ErrorLn ('to the error stream');
    ALGOL
    assert_equal "to output\n", shell_output("#{bin}/algc streams.a24")

    # The emitted directory must build on its own, which is the whole point of
    # shipping the runtime beside the binary.
    #
    # ⚠️ --out names a directory that must ALREADY EXIST.  algc does not create
    # it and exits 70 when it cannot write, so the mkpath is part of the test
    # rather than tidiness.
    (testpath/"build").mkpath
    system bin/"algc", "--compile", "--out=#{testpath}/build", "hello.a24"
    system ENV.cc, "-std=c11", "-O2", "-o", "#{testpath}/hello",
           *Dir["#{testpath}/build/*.c"]
    assert_equal "hello, 4\n", shell_output("#{testpath}/hello")

    # ⚠️ THE REASON THE LIBRARY IS HERE: a bare 'uses' of an installed unit,
    # from a directory holding none of the library's files.  Without it the
    # compiler installs a language with nothing to write programs against,
    # which is what was reported.
    (testpath/"lib.a24").write <<~ALGOL
      uses strings;

      WriteLn (ToUpper ('shouting'));
    ALGOL
    assert_equal "SHOUTING\n", shell_output("#{bin}/algc lib.a24")

    # And a unit that needs both a C shim and a data file, which is the half
    # that needs the wrapper and the --ffi build rather than the compiler's
    # own search.
    (testpath/"font.a24").write <<~ALGOL
      uses graph;

      InitGraph (160, 100, 'test', False);
      OutTextXY (4, 4, 'drawn');
      CloseGraph ();
    ALGOL
    system bin/"algc", "font.a24"
  end
end
