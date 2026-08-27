// Test Explorer support for Algol-24.
//
// Discovery is per test and running is per FILE, because the language has no
// per-test filter: 'algc --test X.a24' runs every test block X.a24 can reach
// and there is no way to ask for one.  So the run handler groups whatever was
// requested by file, runs each file once, and maps the report back onto the
// tree by name.  Asking for one test therefore fills in its whole file, which
// is honest -- those tests really did run -- rather than leaving siblings in
// whatever state a previous run left them.
//
// ⚠️ The oracle is the REPORT, not the exit status.  A file whose tests all
// pass exits 0 and one with a failure exits 70, but the status cannot say which
// test failed, and a file that fails to parse exits non-zero having run nothing
// at all.  Everything interesting is in the lines, which is why they are parsed
// rather than merely echoed.

const vscode = require('vscode');
const cp = require('child_process');
const fs = require('fs');
const os = require('os');
const path = require('path');

// ⚠️ BOTH reports are COLOURED, and identically -- the interpreter writes the
// codes Console.a24 defines and alg_test_run in algol.c spells the same bytes.
// Neither asks whether it is talking to a terminal, because the language has no
// way to ask, so the escapes are always present and every reader strips.  The
// PARSING here must: an unstripped '[ PASS ]' carries escapes around PASS and
// matches nothing.
//
// ⚠️ Stripping for the parse is not a reason to strip for the eye.  What is
// appended to the run goes to the Test Results panel, which is a terminal and
// renders the escapes, so the output keeps its colour and only the copy being
// matched against loses it.
const ANSI = /\x1B\[[0-9;]*m/g;

// The three lines that carry meaning.  Their wording is part of the observable
// surface both implementations must reproduce, so it is safe to match exactly.
const BANNER = /^\[INFO\] < (.+) >$/;
const RESULT = /^\[INFO\] Test: (.*?) \.+ \[ (PASS|FAIL) \]$/;
const FAILURE = /^\[ERROR\] (?:[^:]*: )?(.*)$/;

// ⚠️ 'test' is a context-sensitive identifier and not a keyword -- a variable
// may be called test -- so a block is only recognised where it opens a line and
// is followed by its quoted name.  Anchoring to the line start is also what
// keeps a commented-out '// test ...' out of the tree.
const TEST_BLOCK = /^[ \t]*test[ \t]*'((?:[^']|'')*)'/gim;

/** Turns a scanned test name back into the string the report will print. */
function unescapeName(raw) {
    return raw.replace(/''/g, "'");
}

/** The workspace folder holding the compiler, or undefined outside one. */
function rootOf(uri) {
    const folder = vscode.workspace.getWorkspaceFolder(uri);

    return folder ? folder.uri.fsPath : undefined;
}

function activate(context) {
    const controller = vscode.tests.createTestController('algol24', 'Algol-24');
    context.subscriptions.push(controller);

    // Every file item, by fsPath, so a report banner can be resolved back to
    // the tree.  ⚠️ The banner carries the file's NAME and not its path --
    // Console.TestFile trims it, so that a suite emitted from an absolute path
    // and interpreted from a relative one print the same line -- which means
    // the lookup here is by basename and has to cope with two files sharing
    // one, as compiler/Console.a24 and any other Console.a24 would.
    const files = new Map();

    async function discoverFile(uri) {
        const existing = files.get(uri.fsPath);
        if (existing) controller.items.delete(existing.id);

        let text;
        try {
            text = (await vscode.workspace.fs.readFile(uri)).toString();
        }
        catch {
            files.delete(uri.fsPath);
            return;
        }

        const names = [];
        for (const match of text.matchAll(TEST_BLOCK)) {
            const upto = text.slice(0, match.index).split('\n');
            names.push({ name: unescapeName(match[1]), line: upto.length - 1 });
        }

        if (names.length === 0) {
            files.delete(uri.fsPath);
            return;
        }

        const item = controller.createTestItem(uri.toString(), path.basename(uri.fsPath), uri);
        item.canResolveChildren = false;

        for (const { name, line } of names) {
            const test = controller.createTestItem(uri.toString() + '::' + name, name, uri);
            test.range = new vscode.Range(line, 0, line, 0);
            item.children.add(test);
        }

        controller.items.add(item);
        files.set(uri.fsPath, item);
    }

    async function discoverAll() {
        const found = await vscode.workspace.findFiles(
            '**/*.a24', '**/{node_modules,.build,build,out}/**');

        await Promise.all(found.map(discoverFile));
    }

    controller.resolveHandler = async item => {
        if (!item) await discoverAll();
    };

    const watcher = vscode.workspace.createFileSystemWatcher('**/*.a24');
    watcher.onDidCreate(discoverFile);
    watcher.onDidChange(discoverFile);
    watcher.onDidDelete(uri => {
        const item = files.get(uri.fsPath);
        if (item) controller.items.delete(item.id);
        files.delete(uri.fsPath);
    });
    context.subscriptions.push(watcher);

    /** Every file item that owns at least one of the requested tests. */
    function requestedFiles(request) {
        const wanted = new Map();

        const include = request.include ?? [...gather(controller.items)];
        for (const item of include) {
            const file = item.parent ?? item;
            if (request.exclude?.includes(item)) continue;

            const tests = wanted.get(file) ?? new Set();
            if (item.parent) tests.add(item);
            else for (const [, child] of item.children) tests.add(child);

            wanted.set(file, tests);
        }

        return wanted;
    }

    function* gather(collection) {
        for (const [, item] of collection) yield item;
    }

    /** One child process, resolving to everything it wrote and its status. */
    function run(command, args, cwd, token) {
        return new Promise(resolve => {
            const child = cp.spawn(command, args, { cwd });

            let text = '';
            child.stdout.on('data', chunk => { text += chunk; });
            child.stderr.on('data', chunk => { text += chunk; });

            token.onCancellationRequested(() => child.kill());

            child.on('error', error => resolve({ text: String(error.message), status: -1 }));
            child.on('close', status => resolve({ text, status }));
        });
    }

    /**
     * Runs one file and reports what its report said.
     *
     * Interpreted is one call.  Compiled is the four steps the compiler's own
     * '--help' describes: emit C into a temporary directory, copy the runtime
     * in beside it, build, run.  ⚠️ The emitted directory is NOT self-contained
     * despite what '--help' says -- the emitter writes '#include "algol.h"' and
     * never the runtime itself, so the copy is required.
     *
     * ⚠️ The working directory is not incidental.  A suite is interpreted from
     * the repository root and its COMPILED binary runs from the suite's own
     * directory, because a suite that touches files can tell the difference.
     *
     * ⚠️ A failing step returns ITS OWN output rather than continuing.  A back
     * end refusal -- 'A call to Copy is not supported by the C back end yet.'
     * -- arrives from the emit step, and is the only thing worth showing.
     */
    async function spawnRun(root, file, compiled, token) {
        const algc = path.join(root, 'bootstrap', 'algc');

        if (!compiled) return run(algc, ['--test', file], root, token);

        const out = fs.mkdtempSync(path.join(os.tmpdir(), 'algol24-vscode-'));

        try {
            const emitted = await run(
                algc, ['--compile', '--test', '--out=' + out, file], root, token);
            if (emitted.status !== 0) return emitted;

            for (const name of ['algol.c', 'algol.h'])
                fs.copyFileSync(path.join(root, 'bootstrap', name), path.join(out, name));

            const binary = path.join(out, 'suite');
            const sources = fs.readdirSync(out)
                .filter(name => name.endsWith('.c'))
                .map(name => path.join(out, name));

            const built = await run(
                process.env.CC || 'cc',
                ['-std=c11', '-O2', '-o', binary, ...sources], out, token);
            if (built.status !== 0) return built;

            return run(binary, [], path.dirname(file), token);
        }
        finally {
            fs.rmSync(out, { recursive: true, force: true });
        }
    }

    /**
     * Maps a report onto the tree.  Results are keyed by the banner's file name
     * and the test's own name, so a run of compiler/Main.a24 reports into
     * Scanner.a24 and Parser.a24 as readily as into itself -- which is the
     * point, since that is where most of the compiler's tests live.
     */
    function report(text, run, requested) {
        const lines = text.replace(ANSI, '').split('\n');
        const seen = new Set();

        let banner;
        for (let i = 0; i < lines.length; i++) {
            const line = lines[i].replace(/\r$/, '');

            const opened = BANNER.exec(line);
            if (opened) { banner = opened[1]; continue; }

            const result = RESULT.exec(line);
            if (!result) continue;

            const [, name, status] = result;
            const item = locate(banner, name);
            if (!item) continue;

            seen.add(item);

            if (status === 'PASS') { run.passed(item); continue; }

            // The message, when there is one, is the next [ERROR] line: the
            // interpreter prints it directly under the result.  A compiled run
            // prints none at all, which is why a missing one is not a defect
            // here and the FAIL stands on its own.
            const next = (lines[i + 1] ?? '').replace(/\r$/, '');
            const why = FAILURE.exec(next);

            run.failed(item, new vscode.TestMessage(why ? why[1] : 'Failed.'));
        }

        return seen;
    }

    function locate(banner, name) {
        if (!banner) return undefined;

        const candidates = [...files.values()].filter(
            item => path.basename(item.uri.fsPath) === path.basename(banner));

        for (const file of candidates) {
            const found = file.children.get(file.uri.toString() + '::' + name);
            if (found) return found;
        }

        return undefined;
    }

    function handler(compiled) {
        return async (request, token) => {
            const run = controller.createTestRun(request);
            const wanted = requestedFiles(request);

            for (const [file, tests] of wanted) {
                if (token.isCancellationRequested) break;

                const root = rootOf(file.uri);
                if (!root) {
                    for (const test of tests) run.errored(test, new vscode.TestMessage(
                        'This file is not inside an open workspace folder.'));
                    continue;
                }

                if (!fs.existsSync(path.join(root, 'bootstrap', 'algc'))) {
                    for (const test of tests) run.errored(test, new vscode.TestMessage(
                        'No compiler at ' + path.join(root, 'bootstrap', 'algc')
                        + ' -- run ./bootstrap/build.sh first.'));
                    continue;
                }

                for (const test of tests) run.started(test);

                const { text, status } = await spawnRun(root, file.uri.fsPath, compiled, token);

                // ⚠️ Appended WITH its escapes.  The Test Results panel is a
                // terminal and renders ANSI, so this is where the colour the
                // report carries survives to be seen -- green PASS, red FAIL,
                // and the red tag on the message under it.  Only the parse
                // below strips, and it strips a copy.
                //
                // ⚠️ CRLF, though.  Bare '\n' leaves the terminal's cursor in
                // the column it was in, so every line after the first starts
                // where the last one ended.
                run.appendOutput(text.replace(/\r?\n/g, '\r\n'));

                const seen = report(text, run, tests);

                // ⚠️ A test that ran and was not reported is an ERROR, not a
                // pass.  Every suite in tests/conformance that the C back end
                // refuses lands here -- 'A call to Copy is not supported by the
                // C back end yet' -- and so does any file that fails to parse:
                // the process exits non-zero having printed no result lines,
                // and the reason is the only thing worth showing.
                for (const test of tests) {
                    if (seen.has(test)) continue;

                    if (status === 0) run.skipped(test);
                    else run.errored(test, new vscode.TestMessage(
                        firstProblem(text) ?? 'Did not run; exit status ' + status + '.'));
                }
            }

            run.end();
        };
    }

    /** The first line that explains a run which produced no results. */
    function firstProblem(text) {
        for (const line of text.replace(ANSI, '').split('\n')) {
            const trimmed = line.replace(/\r$/, '');
            if (trimmed.startsWith('Uncaught:')) return trimmed;
            if (trimmed.startsWith('[ERROR]')) return trimmed.replace(/^\[ERROR\] /, '');
        }

        return undefined;
    }

    controller.createRunProfile(
        'Interpreted', vscode.TestRunProfileKind.Run, handler(false), true);

    // The same tests through the C back end.  Both processors must agree, and a
    // disagreement is the class of bug this project exists to catch, so it is
    // worth one click rather than a shell invocation.
    controller.createRunProfile(
        'Compiled', vscode.TestRunProfileKind.Run, handler(true), false);

    discoverAll();
}

function deactivate() {}

module.exports = { activate, deactivate };
