#include <stdio.h>
#include <stdlib.h>

int main() {
    double value = 0.0;
    
    for (int i = 1; i <= 1000000; i++) {
        if (i % 2 != 0) {
            value += 1.0 / (2 * i - 1);
        } else {
            value -= 1.0 / (2 * i - 1);
        }
    }
    
    printf("%0.15f", 4 * value);
    return 0;
}

