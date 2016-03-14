#!/bin/sh

root=${0%/*}
[ "$root" ] && cd "$root"

src="4d_pse2_impl/4d_pse2_v1.3.inc.c"
dest="4d_pse2_impl/4d_pse2_prototypes.h"

[ -e $src ] || { echo "ERROR: missing $src"; exit 1; }

gcc -DL4D_PSE2_PUTCHAR=putc -DL4D_PSE2_GETCHAR=getc -DL4D_PSE2_PREFIX=replace_me_ -DL4D_PSE2_BUILD_PROTOTYPES=1 \
    -std=c99 -E "$src" | \
    grep '_t replace_me_.*(' - | \
    sed -e 's/{.*$/;/' -e 's/^/extern /' -e 's/replace_me_\([a-zA-Z0-9_-]*\)/__(\1)/g' \
    > "$dest"
