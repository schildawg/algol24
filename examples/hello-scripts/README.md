# Hello, in five scripts

A pie chart and the word *hello* in Turkish, Greek, Chinese, Korean and Spanish,
in one SDL2 window.

Everything in the picture is drawn by `hello.a24`: the arc test that decides
which slice a pixel belongs to, the glyph blitter, the hex font loader, the
layout. The program owns a `Buffer` of `W × H × 4` bytes, writes every pixel
into it, and hands `Pixels.Address` to `SDL_UpdateTexture` once a frame. C does
three things only — SDL2 opens the window and takes the texture, and `atan2` and
`sqrt` come from libm. There is no SDL_ttf, no FreeType, and no rasterizer.

**Text and graphics are the same surface.** There is no text mode and no
graphics mode: the Korean label and the pie occupy the same pixels, and text
goes wherever it is put rather than onto a grid.

## Running it

You need SDL2 and libffi. On macOS: `brew install sdl2`; libffi comes with the
system.

```sh
./bootstrap/build.sh --ffi                 # algc, able to call C
cd examples/hello-scripts
../../bootstrap/algc hello.a24             # interpreted -- correct, but slow
                                           # (font-aa.hex by default)
```

⚠️ **Interpreted, the first frame takes about 40 seconds**, because every pixel
is a tree-walk — a 1040 × 520 canvas is 540,800 of them, and the pie asks
`atan2` about each one inside the circle. It is worth watching once: it is the
clearest demonstration in the tree of what the C back end is *for*. Compiled,
the same frame takes about 3 ms.

```sh
mkdir -p build
../../bootstrap/algc --compile --out=build hello.a24
cp ../../bootstrap/algol.c ../../bootstrap/algol.h build/
cc -std=c11 -O2 -DALG_FFI -o build/hello build/*.c -lffi
./build/hello
```

Esc or closing the window quits. It also writes `hello.bmp` beside itself, so
the picture outlives the run.

⚠️ **The SDL path is spelled out in the source**, sixteen times, because `in`
takes a string *literal* — the path cannot come from a `const`, and a program
cannot try one name and fall back to another. If your SDL2 is elsewhere, one
substitution fixes it:

```sh
sed -i '' "s|/opt/homebrew/lib/libSDL2.dylib|/usr/lib/libSDL2.so|g" hello.a24
```

## Two fonts, and why one looks like 1985

The program takes the font file as its first argument, so the same frame can be
drawn twice:

```sh
./build/hello font.hex    old.bmp     # 1-bit cells, 8 x 16, doubled to fit
./build/hello font-aa.hex new.bmp     # grey coverage, 16 x 32, drawn at 1:1
```

Two changes separate them, and only the first is interesting:

1. **One byte of coverage per pixel instead of one bit.** A stem that falls
   between two pixels marks both, each at the weight it actually covers,
   instead of being thresholded into one of them. `Mix` and `Wash` in
   `hello.a24` are the whole of it — eleven lines.
2. **A 32-pixel font, not a 16-pixel font magnified twice.** Integer-scaling a
   small bitmap doubles every error in it. This is most of what people mean
   when they say something "looks like the eighties".

⚠️ **Grey costs data, and the cost is why Unifont is 1-bit.** These 124 glyphs
are 5 KB at one bit and 140 KB at one byte. The whole Basic Multilingual Plane
would be about 1.4 MB at one bit and **tens of megabytes** in grey at this size —
and a bitmap font is one file *per size*. Arbitrary sizes want a rasterizer,
which means FreeType through the FFI, which is currently blocked: reading
`face->glyph->bitmap.buffer` means reading a pointer out of a C struct, and a
`Buffer` has no way to hand one back.

## The font format

`font.hex` is in **GNU Unifont's format** and could be replaced by the real
thing without touching `hello.a24`:

```
0041:00001824426666667E6666660000    a narrow glyph, 8 x 16
4F60:09001B001B0013FC3648344857FC…   a wide glyph,  16 x 16
```

A codepoint, then sixteen rows. Two hex digits to a row is a narrow glyph eight
pixels wide; four digits is a wide one at sixteen. **The width is carried by the
length of the row data**, which is how Unifont supplies the East Asian width
table without a second table — 你好 and 한국어 take double cells with nothing
asked and nothing looked up.

⚠️ **`font.hex` is generated, like `compiler/Unicode.a24` is.** `makefont.py`
rasterises just the codepoints this demo needs out of a system font; it stands
in for shipping Unifont itself, which covers the whole Basic Multilingual Plane
in about 1.4 MB. Do not hand-edit a row — regenerate:

```sh
python3 makefont.py font.hex             # 1-bit, Unifont's format
python3 makefont.py --gray 32 font-aa.hex
```

Both need Pillow.

⚠️ **A proportional face does not fit an eight-pixel cell.** `M` and `W` lose a
stem, so `makefont.py` condenses anything too wide. That is the argument for
Unifont rather than a rasterizer: its glyphs are drawn *to* the cell instead of
being squeezed into it.

## What it does not do

One codepoint per cell. Combining marks get a cell of their own rather than
joining the letter before them, there is no shaping for Arabic or Devanagari,
and no bidi. That is what every terminal does too, and it is the line this
demo draws deliberately rather than the line it failed to reach.
