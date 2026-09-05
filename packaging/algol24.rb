# The Homebrew formula for Algol-24.
#
# Lives here so it is versioned with the thing it packages; the tap that serves
# it is a separate repository, github.com/schildawg/homebrew-algol24, whose
# Formula/algol24.rb is a copy of this file with the url and sha256 for the
# release being published.
#
# ⚠️ NO dependency block, and that is not an oversight.  A --ffi build links
# against /usr/lib/libffi.dylib -- the system one, shipped with macOS -- so the
# bottle needs nothing beyond the operating system.  A Linux formula would have
# to declare libffi instead, which is one reason this tap bottles for macOS
# alone.
#
# ⚠️ Naming that library in the ordinary way, even inside a comment, fails
# 'brew style': the audit reads it as a dependency someone commented out, and
# an explanation of why a formula has none looks exactly like one.
class Algol24 < Formula
  desc "Retro-modern, gradually typed, self-hosting language"
  homepage "https://github.com/schildawg/algol24"
  url "https://github.com/schildawg/algol24/archive/refs/tags/v0.1.4.tar.gz"
  sha256 "7808f22ff6dffc1728bb111f9b9604b57954e553f7b4de70313c91e456e5e2ce"
  license "MIT"
  head "https://github.com/schildawg/algol24.git", branch: "main"

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

    # ⚠️ A wrapper rather than a symlink.  The runtime resolves argv[0] to a
    # real path, so a symlink would work too -- this is belt and braces, and
    # costs one line.
    (bin/"algc").write <<~SHELL
      #!/bin/sh
      exec "#{libexec}/algc" "$@"
    SHELL

    doc.install "README.md", "spec/ALGOL-24.md", "spec/LIBRARY.md"
    pkgshare.install "examples"
  end

  test do
    assert_match "algc", shell_output("#{bin}/algc --version")

    (testpath/"hello.a24").write "WriteLn ('hello, ' + Str (2 + 2));\n"
    assert_equal "hello, 4\n", shell_output("#{bin}/algc hello.a24")

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
  end
end
