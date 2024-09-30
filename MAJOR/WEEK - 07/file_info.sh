#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Provide file name while running the script"
    exit 1
fi

filename=$1

# file exists ?
if [ ! -e "$filename" ]; then
    echo "File '$filename' does not exist!"
    exit 1
fi

echo "File Info for: $filename"
ls -l "$filename"
