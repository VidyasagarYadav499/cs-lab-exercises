#!/bin/bash

t_emp=10
rate=12.00
t_pay=0

for ((i=1; i<=t_emp; i++)); do
    read -p "Total hours worked by employee $i: " wk_hrs

    if [ $wk_hrs -gt 40 ]; then
        ovt_hrs=$(( wk_hrs - 40 ))
        ovt_pay=$(echo "$ovt_hrs * $rate" | bc)
        t_pay=$(echo "$t_pay + $ovt_pay" | bc)
    fi
done

echo "Total overtime pay: $t_pay"

