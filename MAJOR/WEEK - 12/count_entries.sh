#!/bin/bash
if [ $# -eq 0 ]; then
    echo "Please provide a directory path"
    exit 1
fi
dir=$1
if [ ! -d "$dir" ]; then
    echo "Error: $dir is not a valid directory"
    exit 1
fi
echo "Counting entries in each subdirectory of $dir..."
if [ -d "$dir" ]; then
    n=$(ls -1 "$dir" | wc -l)
    d=$(basename "$dir")
    echo "Directory: $d"
    echo "Number of entries: $n"
    echo " "
fi
for d in "$dir"/*/ ; do
    if [ -d "$d" ]; then
        n=$(ls -1 "$d" | wc -l)
        echo "Directory: $(basename "$d")"
        echo "Number of entries: $n"
        echo " "
    fi
done
