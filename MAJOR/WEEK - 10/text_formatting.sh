# ANSI escape codes for terminal text formatting.
# Reference: https://en.wikipedia.org/wiki/ANSI_escape_code#SGR_(Select_Graphic_Rendition)_parameters

### Text formatting ###

# Reset the text formatting to default settings.
CLEAR="\e[0m"  		    # Can also be written like this: CLEAR="\033[0m"

# Text settings for various styles.
BOLD="\e[1m"                # Makes text bold.
UNDERLINE="\e[4m"           # Underlines the text.
FAINT="\e[2m"               # Makes the text faint or dim.
ITALIC="\e[3m"              # Makes the text italic (may not be supported in all terminals).
BLINK="\e[5m"               # Makes the text blink (not supported in all terminals).
REVERSE="\e[7m"             # Reverses the foreground and background colors.
HIDDEN="\e[8m"              # Hides the text.
STRIKETHROUGH="\e[9m"       # Strikes through the text (may not be supported in all terminals).
BOLD_UNDERLINE="\e[1;4m"    # Creates bold and underlined text.
BOLD_FAINT="\e[1;2m"        # Creates bold and faint text.

# Text color settings.
RED="\e[31m"                # Sets the text color to red.
GREEN="\e[32m"              # Sets the text color to green.
YELLOW="\e[33m"             # Sets the text color to yellow.
BLUE="\e[34m"               # Sets the text color to blue.
MAGENTA="\e[35m"            # Sets the text color to magenta.
CYAN="\e[36m"               # Sets the text color to cyan.
WHITE="\e[37m"              # Sets the text color to white.
BRIGHT_RED="\e[91m"         # Bright red text.
BRIGHT_GREEN="\e[92m"       # Bright green text.
BRIGHT_YELLOW="\e[93m"      # Bright yellow text.
BRIGHT_BLUE="\e[94m"        # Bright blue text.
BRIGHT_MAGENTA="\e[95m"     # Bright magenta text.
BRIGHT_CYAN="\e[96m"        # Bright cyan text.
BRIGHT_WHITE="\e[97m"       # Bright white text.

# Bold text colors for emphasis.
RED_BOLD="\e[1;31m"         # Bold red text.
GREEN_BOLD="\e[1;32m"       # Bold green text.
YELLOW_BOLD="\e[1;33m"      # Bold yellow text.
BLUE_BOLD="\e[1;34m"        # Bold blue text.
MAGENTA_BOLD="\e[1;35m"     # Bold magenta text.
CYAN_BOLD="\e[1;36m"        # Bold cyan text.
WHITE_BOLD="\e[1;37m"       # Bold white text.

# Background color settings.
RED_BG="\e[41m"             # Sets the background color to red.
GREEN_BG="\e[42m"           # Sets the background color to green.
YELLOW_BG="\e[43m"          # Sets the background color to yellow.
BLUE_BG="\e[44m"            # Sets the background color to blue.
MAGENTA_BG="\e[45m"         # Sets the background color to magenta.
CYAN_BG="\e[46m"            # Sets the background color to cyan.
WHITE_BG="\e[47m"           # Sets the background color to white.
BRIGHT_RED_BG="\e[101m"     # Bright red background.
BRIGHT_GREEN_BG="\e[102m"   # Bright green background.
BRIGHT_YELLOW_BG="\e[103m"  # Bright yellow background.
BRIGHT_BLUE_BG="\e[104m"    # Bright blue background.
BRIGHT_MAGENTA_BG="\e[105m" # Bright magenta background.
BRIGHT_CYAN_BG="\e[106m"    # Bright cyan background.
BRIGHT_WHITE_BG="\e[107m"   # Bright white background.

# Bold background colors.
RED_BG_BOLD="\e[1;41m"      # Bold red background.
GREEN_BG_BOLD="\e[1;42m"    # Bold green background.
YELLOW_BG_BOLD="\e[1;43m"   # Bold yellow background.
BLUE_BG_BOLD="\e[1;44m"     # Bold blue background.
MAGENTA_BG_BOLD="\e[1;45m"  # Bold magenta background.
CYAN_BG_BOLD="\e[1;46m"     # Bold cyan background.
WHITE_BG_BOLD="\e[1;47m"    # Bold white background.

### End of Text formatting ###

### Usage Examples ###

# Use the defined variables to format terminal output.
# Example 1: Displaying a message in bold green text.
# echo -e "${GREEN_BOLD}This is a bold green message.${CLEAR}"

# Example 2: Displaying a warning in yellow text with a red background.
# echo -e "${YELLOW}Warning: An error has occurred!${RED_BG}${CLEAR}"

# Example 3: Displaying a success message in bold green with a blue background.
# echo -e "${GREEN_BOLD}Success!${BLUE_BG}${CLEAR}"

# Example 4: Displaying underlined text.
# echo -e "${UNDERLINE}This text is underlined.${CLEAR}"

# Example 5: Displaying hidden text (might not be visible).
# echo -e "${HIDDEN}This text is hidden and not visible.${CLEAR}"

# Example 6: Combining effects to create bold and underlined text.
# echo -e "${BOLD_UNDERLINE}This text is bold and underlined.${CLEAR}"

# Example 7: Strikethrough effect.
# echo -e "${STRIKETHROUGH}This text has a strikethrough.${CLEAR}"

### End of Usage Examples ###

# Note: The `-e` option in `echo` enables interpretation of escape sequences.

### Additional Information ###

# 1. **Terminal Support**:
# Not all terminals support all ANSI codes. Most modern terminal emulators, such as xterm, gnome-terminal, and Windows Terminal, do support these codes. However, the display of certain effects, like blinking, can vary.

# 2. **Combining Effects**:
# You can combine styles by using semicolons. For example:
BOLD_UNDERLINE="\e[1;4m"   # Creates bold and underlined text.

# 3. **Custom Color Support**:
# Some terminals support 256-color mode, allowing for more customization with colors. You can specify these colors with codes ranging from `0` to `255` in the format `\e[38;5;{color_code}m` for foreground and `\e[48;5;{color_code}m` for background. 
# Example of 256 color:
# echo -e "\e[38;5;82mThis is a custom green from the 256 color palette.${CLEAR}"

# 4. **Best Practices**: 
# Always reset the formatting after displaying styled text by including the `CLEAR` variable to avoid affecting subsequent text. For example:
# echo -e "${GREEN}This will be green${CLEAR} and this will be normal."

# 5. **Cross-Platform Compatibility**: 
# If your script is intended to run on different operating systems, keep in mind that some may require different handling of ANSI codes. For instance, Windows traditionally did not support these codes in the Command Prompt but has improved support in PowerShell and Windows Terminal.

# 6. **Color Customization**: 
# You can create your own functions or variables to encapsulate color choices for ease of use, such as:
# set_color() {
#  echo -e "\e[$1m"
# }

# Example usage: set_color "32" to set text color to green.

# 7. **Performance Considerations**:
# If you are executing many formatted outputs in a script, consider minimizing the number of escape sequences for performance. Batch your outputs when possible to reduce the overhead.

# 8. **Compatibility Check**:
# To check if your terminal supports ANSI codes, you can run a simple command:
# if [[ $TERM == "xterm"* || $TERM == "screen"* || $TERM == "linux" ]]; then
#  echo -e "${GREEN}Your terminal supports ANSI escape codes!${CLEAR}"
# else
#  echo -e "${RED}Your terminal may not support ANSI escape codes.${CLEAR}"
# fi

# 9. **Testing Script**: 
# Create a simple testing script to visualize how each effect looks:
# for color in {30..37} {90..97}; do
#   echo -e "\e[${color}mColor ${color}\e[0m"
# done

### End of additional information ###
