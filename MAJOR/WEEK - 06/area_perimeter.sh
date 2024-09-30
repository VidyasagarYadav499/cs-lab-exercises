#!/bin/bash
read -p "Enter the lenght: " l
read -p "Enter the breadth: " b
read -p "Enter the radius: " r
area=$((l*b))
perimeter=$((l+l+b+b))
ar=$(echo "scale=2; 3.141 * $r * $r" | bc)
cir=$(echo "scale=2; 2 * 3.141 * $r" | bc)
echo "area of rectangle: "$area
echo "perimeter of rectangle: "$perimeter
echo "area of circle: "$ar
echo "circumference of circle: "$cir