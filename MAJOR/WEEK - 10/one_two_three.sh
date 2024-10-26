#!/bin/bash

# A shell script can receive an argument ‘one’, ‘two’, or
# ‘three’. If the argument supplied is ‘one’ display it in bold,
# if it is ‘two’ display it in reverse order and if it is
# ‘three’ make it blink on the screen. If a wrong argument is
# supplied report it. (Hint: Use an elif statement)

source ~/bash_scripting/text_formatting.sh

read -p "Enter 'one', 'two' or 'three': " str

if [ "$str" = "one" ]; then
	echo -e "${BOLD}one${CLEAR}"
elif [ "$str" = "two" ]; then
	echo "two" | rev
elif [ "$str" = "three" ]; then
	echo -e "\033[1;5;31mthree${CLEAR}"
else echo -e "${RED_BOLD}ERROR:${CLEAR} Wrong argument -> '$str' provided!"

fi
