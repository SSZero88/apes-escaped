#!/bin/sh
# Draft C for a function with m2c: tools/m2c.sh func_80012345 [extra m2c args]
f=$1; shift
s=$(find asm/nonmatchings -name "$f.s" | head -1)
[ -z "$s" ] && { echo "no asm for $f" >&2; exit 1; }
# strip splat's nonmatching macro line, m2c doesn't know it
sed '/^nonmatching /d' "$s" > /tmp/m2c_in.s
ctx=/tmp/ctx.c
mips-linux-gnu-cpp -Iinclude -P -undef -D M2CTX -D_LANGUAGE_C include/common.h > $ctx 2>/dev/null
python3 -m m2c.main --target mipsel-gcc-c --context $ctx "$@" /tmp/m2c_in.s
