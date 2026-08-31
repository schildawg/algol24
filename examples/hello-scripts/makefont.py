#!/usr/bin/env python3
"""Rasterise the codepoints this demo needs into a cell font.

Two formats, and the difference between them is the whole point of the
comparison in the README.

  makefont.py font.hex                 GNU Unifont's format: one BIT per pixel,
                                       cells 8 x 16 and 16 x 16, width carried
                                       by the length of the row data.

  makefont.py --gray 32 font-aa.hex    one BYTE of coverage per pixel, at any
                                       cell height.  The first line says so.

The 1-bit form is what a 1980s character ROM held.  The grey form is what every
console on this machine actually draws, and it is why their text looks smooth
and a thresholded bitmap does not.
"""
import sys, unicodedata
from PIL import Image, ImageDraw, ImageFont

FONT  = "/System/Library/Fonts/Supplemental/Arial Unicode.ttf"
EMOJI = "/System/Library/Fonts/Apple Color Emoji.ttc"

# Colour glyphs.  Single codepoints only: a flag is two regional indicators and
# a family is five codepoints joined by ZWJ, and one cell holds one codepoint.
COLOURED = "🙂🌍🎉👋⭐🐈"

TEXT = (
    "".join(chr(c) for c in range(0x20, 0x7F)) +
    "Hello in five languages"
    "Merhaba Turkce Türkçe"
    "Geia sou Ellinika"
    "Γεια σου Ελληνικά"
    "你好 中文"
    "안녕하세요 한국어"
    "Hola Espanol Español ¡"
    "0123456789 ()%,.:-"
)

def is_wide(ch):
    return unicodedata.east_asian_width(ch) in ("W", "F")

def render(ch, font, cell_w, cell_h, baseline):
    img = Image.new("L", (cell_w, cell_h), 0)
    try:
        box = font.getbbox(ch)
    except Exception:
        box = (0, 0, 0, 0)
    w = box[2] - box[0]

    # A proportional face has letters wider than the cell -- 'M' and 'W' lose a
    # stem if they are simply clipped.  Draw those into a wider image and
    # condense it, which is the compromise a font drawn FOR the cell avoids.
    if w > cell_w:
        wide = Image.new("L", (w + 2, cell_h), 0)
        ImageDraw.Draw(wide).text((-box[0], baseline), ch, font=font, fill=255, anchor="ls")
        return wide.resize((cell_w, cell_h), Image.LANCZOS)

    ImageDraw.Draw(img).text((-box[0] + max(0, (cell_w - w) // 2), baseline),
                             ch, font=font, fill=255, anchor="ls")
    return img

def main():
    args = sys.argv[1:]
    grey = False
    cell_h = 16

    if args and args[0] == "--gray":
        grey, cell_h, args = True, int(args[1]), args[2:]

    # A cell wants the face a little smaller than its height, so ascenders and
    # descenders have somewhere to go.
    size     = int(cell_h * 0.80)
    baseline = int(cell_h * 0.78)
    font     = ImageFont.truetype(FONT, size)

    seen, out = set(), []
    if grey:
        out.append("# gray8 %d" % cell_h)

        # ⚠️ A COLOUR glyph, and the separator says so: ':' is coverage, '+' is
        # RRGGBBAA.  Emoji are not coverage over one ink colour -- they are
        # pictures -- so no amount of grey will do, and the format has to admit
        # a second kind rather than pretend.
        colour = ImageFont.truetype(EMOJI, 160)

        for ch in COLOURED:
            cp = ord(ch)
            seen.add(cp)

            img = Image.new("RGBA", (200, 200), (0, 0, 0, 0))
            ImageDraw.Draw(img).text((0, 0), ch, font=colour, embedded_color=True)

            box = img.getbbox() or (0, 0, 160, 160)
            px  = img.crop(box).resize((cell_h, cell_h), Image.LANCZOS).load()

            body = "".join("%02X%02X%02X%02X" % px[x, y]
                           for y in range(cell_h) for x in range(cell_h))
            out.append("%04X+%s" % (cp, body))

    for ch in sorted(set(TEXT)):
        cp = ord(ch)
        if cp in seen or cp < 0x20:
            continue
        seen.add(cp)

        cell_w = cell_h if is_wide(ch) else cell_h // 2
        px = render(ch, font, cell_w, cell_h, baseline).load()

        if grey:
            # One byte of coverage per pixel, row by row.
            body = "".join("%02X" % px[x, y]
                           for y in range(cell_h) for x in range(cell_w))
        else:
            rows = []
            for y in range(cell_h):
                bits = 0
                for x in range(cell_w):
                    if px[x, y] > 110:
                        bits |= 1 << (cell_w - 1 - x)
                rows.append(("%04X" if cell_w > 8 else "%02X") % bits)
            body = "".join(rows)

        out.append("%04X:%s" % (cp, body))

    with open(args[0], "w") as f:
        f.write("\n".join(out) + "\n")

    print("%d glyphs, %s%s" % (len(out) - (1 if grey else 0),
                               "grey %d" % cell_h if grey else "1-bit 16",
                               " + %d in colour" % len(COLOURED) if grey else ""))

main()
