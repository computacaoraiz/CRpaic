#!/bin/bash

# Set version and date for CRpaic library files.

# Verifica se os argumentos foram fornecidos
if [ $# -ne 1 ]; then
    echo "Usage: $0 <version file>"
    exit 1
fi

# Important variables:
VERSION=$(cat VERSION.TXT)
DATE=$(date +"%Y-%m-%d %H:%M %z")

# Files to be modified:
FILES="CRpaic_tests.h CRpaic_tests.c tests.c"

# Execute:
for i in $FILES; do
    sed -i "s/^ \* Version : .*/ \* Version : $VERSION/" "$i"
    sed -i "s/^ \* Date    : .*/ \* Date    : $DATE/" "$i"
    echo "Version and Date on $i altered."
done

