#!/bin/bash
echo -e "Files before:\n"
ls
echo -e "Creating 'file.txt'\n"
touch file.txt
echo -e "Files after:\n"
ls
echo -e "\nDeleting 'file.txt':\n"
rm file.txt
ls
