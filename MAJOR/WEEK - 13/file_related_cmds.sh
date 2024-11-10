#!/bin/bash

mkdir dir
cd dir/
touch file.txt
echo "experimental file" > file.txt
cp file.txt file_cpy.txt
ls -l
cd ..
ls
