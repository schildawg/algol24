#!/usr/bin/env python3
"""Rasterise just the codepoints the demo needs into a Unifont-style .hex file.

This stands in for shipping GNU Unifont: the format is the same, so the
Algol-24 side is written against the real thing.

  XXXX:HH x16   a narrow glyph, 8 x 16
  XXXX:HHHH x16 a wide glyph,  16 x 16

Width is carried by the length of the row data, exactly as Unifont does it.
"""
import sys, unicodedata
from PIL import Image, ImageDraw, ImageFont

FONT = "/System/Library/Fonts/Supplemental/Arial Unicode.ttf"

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

def render(ch, font, cell_w):
    img = Image.new("L", (cell_w, 16), 0)
    d = ImageDraw.Draw(img)
    # Nudge each glyph into the cell using its own bounding box.
    try:
        box = font.getbbox(ch)
    except Exception:
        box = (0, 0, 0, 0)
    w = box[2] - box[0]

    # A proportional face has letters wider than the cell -- 'M' and 'W' lose a
    # stem if they are simply clipped.  Draw those into a wider image and
    # condense it, which is the compromise a hand-drawn cell font does not need.
    if w > cell_w:
        wide_img = Image.new("L", (w + 2, 16), 0)
        ImageDraw.Draw(wide_img).text((-box[0], 13), ch, font=font, fill=255, anchor="ls")
        return wide_img.resize((cell_w, 16), Image.LANCZOS)

    d.text((-box[0] + max(0, (cell_w - w) // 2), 13), ch, font=font, fill=255, anchor="ls")
    return img

def main():
    font = ImageFont.truetype(FONT, 13)
    seen, out = set(), []

    for ch in sorted(set(TEXT)):
        cp = ord(ch)
        if cp in seen or cp < 0x20:
            continue
        seen.add(cp)

        wide = is_wide(ch)
        cell_w = 16 if wide else 8
        img = render(ch, font, cell_w)

        rows = []
        px = img.load()
        for y in range(16):
            bits = 0
            for x in range(cell_w):
                if px[x, y] > 110:
                    bits |= 1 << (cell_w - 1 - x)
            rows.append(("%04X" if wide else "%02X") % bits)

        out.append("%04X:%s" % (cp, "".join(rows)))

    with open(sys.argv[1], "w") as f:
        f.write("\n".join(out) + "\n")

    print("%d glyphs" % len(out))

main()
