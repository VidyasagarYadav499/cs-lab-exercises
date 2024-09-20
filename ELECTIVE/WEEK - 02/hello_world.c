#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
    #pragma omp parallel
    {
        printf("hello World!\n");
    }

    return 0;
}