# third_party

Vendored code that this project did not write.

| File | Origin | Licence |
|---|---|---|
| `stb_image.h` | [nothings/stb](https://github.com/nothings/stb) v2.30 | public domain / MIT |

## Why this directory exists rather than `bootstrap/`

`bootstrap/` holds two things and only two: the compiler's own emitted C, and
the hand-written runtime `algol.[ch]`. The fixed point compares that directory
against a freshly emitted generation with

```sh
diff -r -x 'algol.[ch]' -x build.sh bootstrap/ <generation>
```

⚠️ **Anything else placed in `bootstrap/` breaks `./test.sh fixedpoint`**, because
a file the emitter did not produce reads as a difference. Adding `stb_image.h`
there would have meant widening that exclusion list, and the exclusion list is
the fixed point — every name added to it is a file the check no longer covers.
Vendored code lives here so the seed directory stays exactly what it claims to
be.

Nothing here is copied into an emitted directory. The eleven sites that copy
`algol.c` and `algol.h` alongside emitted output are untouched, and reaching
this header is the build's job:

```sh
CFLAGS="-std=c11 -O2 -DALG_SDL -Ithird_party $(sdl2-config --cflags --libs)"
```

## Why stb_image rather than SDL_image

SDL2 proper decodes BMP and nothing else. The usual answer is `SDL_image`,
which is a second link-time dependency dragging `libpng` and `zlib` behind it.
`stb_image.h` is one header with no link dependency at all, so the SDL build
needs exactly one library rather than four.

It is compiled only under `ALG_SDL`, and only into `algol.c`, which is the sole
translation unit that defines `STB_IMAGE_IMPLEMENTATION`. A default build never
includes it — `cc` never opens this file, and the directory can be deleted
without affecting anything `./build.sh` or `./test.sh` does.

`STBI_ONLY_PNG` is set, so the decoder compiled in is the PNG one alone.
