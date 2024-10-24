#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 file1 file2"
    exit 1
fi

file1=$1
file2=$2

if [ "$file1" = "$file2" ]; then
    echo "Both are same files. Enter two distinct files."
	exit 1
fi


if [ ! -f "$file1" ]; then
    echo "$file1 does not exist."
    exit 1
fi

if [ ! -f "$file2" ]; then
    echo "$file2 does not exist."
    exit 1
fi

cmp -s "$file1" "$file2"

if [ $? -eq 0 ]; then
    echo "The contents of $file1 and $file2 are the same. Deleting $file2."
    rm "$file2"
else
    echo "The contents of $file1 and $file2 are different."
fi


