#include <stdio.h>
#include <omp.h>

void fibo(int n) {
    long int a = 0, b = 1;
    int i;
    printf("%ld\n", a);

    if (n > 1){
        printf("%ld\n", b);
        #pragma omp parallel private(i)
        {
            #pragma omp for
            for (i = 2; i < n; i++) {
                long int next;
                #pragma omp critical
                {
                    next = a + b;
                    a = b;
                    b = next;
                    printf("%ld\n", next);
                }
            }
        }
    }
}

int main() {
    int n = 50; 
    fibo(n);
    return 0;
}

