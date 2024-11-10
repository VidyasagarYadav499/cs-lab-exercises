#!/bin/bash

if [ $# -eq 0 ]; then
	echo "ERROR: provide file as argument."
	exit 1
fi

file=$1

grep -v "Unix" "$file" > without_unix_lines.txt
