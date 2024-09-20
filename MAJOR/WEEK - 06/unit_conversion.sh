#!/bin/bash

read -p "Enter distance(in km): " dist

mtr=$((dist*1000))
ft=$(echo "scale=2; $dist * 3280.84" | bc)
inch=$(echo "scale=2; $dist * 39370.079" | bc)
cm=$((dist*100000))

echo "meter: "$mtr
echo "feet: "$ft
echo "inch: "$inch
echo "centimeter: "$cm
