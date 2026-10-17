#!/bin/sh
# Build the exe (matching or not), report anything that moved, write it into a copy
# of your disc image, and optionally boot it.
#
#   ./play.sh            build + make build/disc/ApeEscape.cue
#   ./play.sh run        ... then open it in RetroArch (Beetle PSX)
#   ./play.sh test       ... then boot it headlessly and compare screenshots with the original disc
#
# Path of your original "Ape Escape (USA).bin": set APE_DISC, or put it in the file disc.path.
cd "$(dirname "$0")"

DISC=${APE_DISC:-$(head -n1 disc.path 2>/dev/null | tr -d '\r')}
if [ ! -f "$DISC" ]; then
    echo "Original disc image not found. Put the path of 'Ape Escape (USA).bin' in disc.path or APE_DISC." >&2
    exit 1
fi
PY=$(command -v py >/dev/null 2>&1 && echo py || echo python3)
CUE_ORIG="${DISC%.bin}.cue"

# build without the checksum gate, then report whether it still matches
./make.sh build/SCUS_944.23 >/dev/null || exit 1
if sha1sum --quiet -c scus_944.23.sha1 >/dev/null 2>&1; then
    echo "exe matches the original"
else
    echo "exe is MODIFIED (no longer matches the original)"
    MSYS_NO_PATHCONV=1 docker run --rm -v "$(pwd -W 2>/dev/null || pwd):/work" apes-escaped-build \
        python3 tools/check_shift.py | tail -15
fi

$PY tools/patch_disc.py "$DISC" build/disc/ApeEscape.bin || exit 1

case "$1" in
run)
    RA=${RETROARCH:-$APPDATA/RetroArch/retroarch.exe}
    "$RA" -L "$(dirname "$RA")/cores/mednafen_psx_libretro.dll" "$(pwd -W 2>/dev/null || pwd)/build/disc/ApeEscape.cue" &
    ;;
test)
    $PY tools/boot_test.py build/disc/ApeEscape.cue --compare "$CUE_ORIG" ${FRAMES:+--frames $FRAMES}
    ;;
esac
