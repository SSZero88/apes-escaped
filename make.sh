#!/bin/sh
# Run make inside the build container: ./make.sh [targets...]
cd "$(dirname "$0")"
MSYS_NO_PATHCONV=1 exec docker run --rm -v "$(pwd -W 2>/dev/null || pwd):/work" apes-escaped-build make "$@"
