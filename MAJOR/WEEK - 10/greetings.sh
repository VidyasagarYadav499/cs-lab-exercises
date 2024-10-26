#!/bin/bash

# Write a shell script to display the message “Good Morning” /
# “Good Afternoon” / “Good Evening” depending upon the current
# time.

curr_time=$(date +"%H")

if [ $curr_time -lt 12 ]; then
    echo "Good Morning"
elif [ $curr_time -lt 18 ]; then
    echo "Good Afternoon"
else
    echo "Good Evening"
fi
