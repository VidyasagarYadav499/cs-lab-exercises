#include <stdio.h>
#include <omp.h>

int main() {
    int n = 10;
    long long fact= 1;
    int i;
    #pragma omp parallel for reduction(*:fact) private(i)
    for (i = 2; i <= n; i++){
        fact = fact * i;
    }

    printf("Factorial: %lld\n",fact);
    return 0;
}

