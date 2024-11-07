#!/bin/bash

# Write a program to find the factorial value of any number
# entered through the keyboard.

read -p "Enter a positive integer number: " num

fact=1

for ((i=2; i<=num; i++)); do
	fact=$((fact * i))
done

echo "Factorial of $num is $fact."
