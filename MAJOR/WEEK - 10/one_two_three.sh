#!/bin/bash

# A shell script can receive an argument ‘one’, ‘two’, or
# ‘three’. If the argument supplied is ‘one’ display it in bold,
# if it is ‘two’ display it in reverse order and if it is
# ‘three’ make it blink on the screen. If a wrong argument is
# supplied report it. (Hint: Use an elif statement)

# source ~/bash_scripting/text_formatting.sh

. ~/bash_scripting/text_formatting.sh

read -p "Enter 'one', 'two' or 'three': " str

if [ "$str" = "one" ]; then
	echo -e "${BOLD}one${CLEAR}"
elif [ "$str" = "two" ]; then
	echo "two" | rev
elif [ "$str" = "three" ]; then
	echo -e "\e[5mthree${CLEAR}"
else
	echo -e "\e[1;5;7;31m ERROR: ${CLEAR} Wrong argument -> '$str' provided!"
fi
