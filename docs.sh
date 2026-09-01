#!/bin/sh
#
# docs.sh -- checks the documentation comments in compiler/*.a24 against the
# conventions in spec/DOCUMENTATION.md.
#
#   ./docs.sh            check every unit that has been through the doc pass
#   ./docs.sh -v         also list what is still to do
#
# A FILE WITH A 'unit' DECLARATION IS EXPECTED TO BE FULLY DOCUMENTED.  That is
# the whole scheduling mechanism: the doc pass adds 'unit X;' to a file as it
# documents it, so the header doubles as the mark that the file is finished and
# this script has something to enforce from the first file onward rather than
# only at the end.  A file with no header is reported as outstanding and not
# checked.
#
# The last check is that no file is outstanding, which is what makes the pass
# complete.
#
# Written in sh and awk like the other harnesses.  A C compiler is the only
# thing this repository needs to build itself, and a checker that reached for
# python would quietly make that untrue.

set -eu

VERBOSE=0
[ "${1:-}" = "-v" ] && VERBOSE=1

SRC="compiler"
problems=0
checked=0
outstanding=""

# Every test name the suite declares, so an '# Examples' citation can be
# resolved.  Test blocks open at column 0, which is what lets the awk below
# find them without parsing begin/end.
#
# Through a FILE rather than -v.  A test name is ordinary prose and awk reads a
# -v assignment for escapes, so a list of them joined by newlines is a syntax
# error before the program starts.
TESTS=$(mktemp)
RULES=$(mktemp)
trap 'rm -f "$TESTS" "$RULES"' EXIT INT TERM
grep -h "^test '" "$SRC"/*.a24 | sed "s/^test '//; s/';.*$//" | sort -u > "$TESTS"

# Every rule the specification declares, so a '# Satisfies' citation can be
# resolved.  A rule is introduced as **[XXX-000]** at the start of a line.
grep -oE '^\*\*\[[A-Z]+-[0-9]+\]\*\*' spec/ALGOL-24.md |
    sed 's/^\*\*\[//; s/\]\*\*$//' | sort -u > "$RULES"

for f in "$SRC"/*.a24; do
    if ! grep -q '^unit ' "$f"; then
        outstanding="$outstanding $(basename "$f")"
        continue
    fi
    checked=$((checked + 1))

    out=$(awk -v tests="$TESTS" -v rules="$RULES" '
    BEGIN {
        while ((getline line < tests) > 0) known[line] = 1
        close(tests)
        while ((getline line < rules) > 0) rule[line] = 1
        close(rules)
        ok["# Raises"] = 1; ok["# Safety"] = 1; ok["# Examples"] = 1
        ok["# Satisfies"] = 1; ok["# Since"] = 1
    }

    # A test block is top level and its end is at column 0, so skipping one
    # needs no block nesting: the doc pass leaves test blocks alone and their
    # bodies hold statements this script must not read as declarations.
    # A doc block sitting above a test belongs to the test, and test blocks are
    # out of scope for this pass, so its pending complaints are discarded rather
    # than reported.  Complaints are buffered until the declaration they belong
    # to is known, for exactly this reason.
    /^test[ \t]/ { skip = 1; pend = ""; doc = 0 }
    skip && /^end/ { skip = 0; doc = 0; next }
    skip { next }

    # A "var" section holds FIELDS after a class or object header and LOCALS
    # after a subprogram header.  They look identical -- "Name : Type;" -- so
    # which one it is depends on the header last seen.  Locals are not part of
    # any contract and are not documented.
    /^(class|object)[ \t]/           { owner = "class" }
    /^type[ \t]*$/ || /^type[ \t]/   { owner = "type" }
    /^[ \t]*(function|procedure|constructor|operator)[ \t]/ { owner = "sub" }
    /^[ \t]*var[ \t]*$/              { fields = (owner == "class") }
    /^[ \t]*begin[ \t]*$/            { fields = 0 }

    # Accumulate a run of /// lines.  first holds the summary, last the final
    # line, so a block ending in a bare /// can be reported.
    /^[ \t]*\/\/\// {
        line = $0
        sub(/^[ \t]*\/\/\/[ ]?/, "", line)
        # insat resets with the block.  Without that it leaks past the
        # declaration and an ordinary sentence citing a rule inline -- which is
        # a reference, not a claim -- is read as part of a # Satisfies list.
        if (doc == 0) { first = line; firstno = NR; sumdone = 0; sumlines = 0; insat = 0 }
        last = line
        doc++

        # The summary is the first SENTENCE, which may wrap onto a second line
        # but no further.  Counting lines instead would just force truncation:
        # sources wrap at 80 columns and "/// " spends four of them.
        if (!sumdone) {
            if (line == "") {
                pend = pend "  " FILENAME ":" firstno ": summary is not a sentence" "\n"
                sumdone = 1
            }
            else {
                sumlines++
                if (line ~ /[.?!]$/) sumdone = 1
                else if (sumlines >= 2) {
                    pend = pend "  " FILENAME ":" firstno ": summary runs past two lines" "\n"
                    sumdone = 1
                }
            }
        }

        if (line ~ /⚠️/)
            pend = pend "  " FILENAME ":" NR ": a warning sign in a doc comment" "\n"

        if (line ~ /^#/) {
            h = line
            sub(/[ \t]+$/, "", h)
            if (!(h in ok))
                pend = pend "  " FILENAME ":" NR ": unknown section " h "\n"
        }

        # Rule identifiers, wherever they appear in a # Satisfies list.  A
        # sorted list is checked too: it is what makes one findable and keeps a
        # diff stable.
        if (insat && line ~ /\[[A-Z]+-[0-9]+\]/) {
            n = split(line, part, /[],[ \t]+/)
            prev = ""
            for (i = 1; i <= n; i++) {
                id = part[i]
                gsub(/[][ \t,]/, "", id)
                if (id == "") continue
                if (!(id in rule))
                    pend = pend "  " FILENAME ":" NR ": # Satisfies names no such rule: " id "\n"
                if (prev != "" && id < prev)
                    pend = pend "  " FILENAME ":" NR ": # Satisfies is not sorted: " prev " before " id "\n"
                prev = id
            }
        }
        insat = (line == "# Satisfies") ? 1 : (line ~ /^#/ ? 0 : insat)

        if (line ~ /^See test /) {
            n = line
            sub(/^See test '"'"'/, "", n)
            sub(/'"'"'\..*$/, "", n)
            if (!(n in known))
                pend = pend "  " FILENAME ":" NR ": # Examples names no such test: " n "\n"
        }

        if (tolower(line) ~ /^(author|date|version|since)[ \t]*:/ && line !~ /^Since/)
            pend = pend "  " FILENAME ":" NR ": provenance belongs in version control" "\n"
        next
    }

    # A declaration the conventions require documentation on: anything at
    # column 0 that declares, a class member one indent in, and a field in a
    # var section -- "Name : Type;" indented, which is a declaration even
    # though it opens with no keyword.
    # "type X = ..." on one line declares; a bare "type" opens a section and
    # the names under it are the declarations, so the two are matched apart.
    /^(unit|function|procedure|class|object|const|var)[ \t]/ ||
    /^type[ \t]+[A-Za-z_]/ ||
    /^[ \t]+(function|procedure|constructor|operator)[ \t]/ ||
    (fields && /^[ \t]+[A-Za-z_][A-Za-z0-9_?!]*([ \t]*,[ \t]*[A-Za-z_][A-Za-z0-9_?!]*)*[ \t]*:[ \t]*[A-Za-z_]/) ||
    (owner == "type" && /^[ \t]+[A-Za-z_][A-Za-z0-9_?!]*[ \t]*=/) {
        kind = $1
        name = $2
        if ($0 !~ /^(unit|function|procedure|class|object|const|var)[ \t]/ &&
            $0 !~ /^type[ \t]+[A-Za-z_]/ &&
            $0 !~ /^[ \t]+(function|procedure|constructor|operator)[ \t]/) {
            kind = (owner == "type") ? "type" : "field"
            name = $1
        }
        sub(/[(;:=].*$/, "", name)

        printf "%s", pend
        pend = ""

        if (doc == 0) {
            print "  " FILENAME ":" NR ": undocumented -- " kind " " name
        }
        else {
            if (last == "")
                print "  " FILENAME ":" firstno ": block ends on a bare ///"
            if (tolower(first) == tolower(name) || tolower(first) == tolower(name) ".")
                print "  " FILENAME ":" firstno ": summary is the name again -- " first
        }
        doc = 0
        insat = 0
        next
    }

    # Any other line ends a doc block without consuming it.  A /// that
    # documents nothing is a doc comment in an invalid position.
    /^[ \t]*$/ { next }
    {
        # Buffered like the rest: a doc block may be separated from the test it
        # belongs to by an ordinary comment, and the complaint must still be
        # discarded when that test is reached.
        if (doc > 0)
            pend = pend "  " FILENAME ":" firstno ": /// documents nothing" "\n"
        doc = 0
    }
    ' "$f") || true

    if [ -n "$out" ]; then
        printf '%s\n' "$out"
        problems=$((problems + $(printf '%s\n' "$out" | wc -l)))
    fi
done

echo
echo "Documentation"
echo "  $checked unit(s) checked"

if [ -n "$outstanding" ]; then
    echo "  not yet through the doc pass:$outstanding"
    [ "$VERBOSE" -eq 1 ] || true
fi

if [ "$problems" -gt 0 ]; then
    echo
    echo "FAIL: $problems problem(s) against spec/DOCUMENTATION.md."
    exit 1
fi

if [ -n "$outstanding" ]; then
    echo
    echo "OK so far: every documented unit conforms; some units remain."
    exit 0
fi

echo "  every unit carries a 'unit' declaration and is documented"
echo
echo "OK: documentation conforms to spec/DOCUMENTATION.md."
