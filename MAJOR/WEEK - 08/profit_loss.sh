#!/bin/bash

read -p "Enter the cost price: " cp
read -p "Enter the selling price: " sp

if [ $sp -gt $cp ]; then
    pr=$((sp - cp))
    echo "The seller made a profit of $pr."
elif [ $sp -lt $cp ]; then
    ls=$((cp - sp))
    echo "The seller incurred a loss of $ls."
else
    echo "No profit, no loss."
fi
