#!/bin/bash

# Two numbers are entered through the keyboard. Write a program
# to find the value of one number raised to the power of
# another.

read -p "Enter two nums: " n1 n2

# echo "$n1^$n2 = $((${n1} ** ${n2}))"

echo "$n1 ^ $n2" | bc
