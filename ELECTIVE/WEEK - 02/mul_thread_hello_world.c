#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
    #pragma omp parallel num_threads(10)
    {
        printf("hello World!\n");
    }

    return 0;
}