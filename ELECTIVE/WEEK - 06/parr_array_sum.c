#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h> 

#define SIZE 100000000

int main() {
	clock_t start = clock();

    long int* arr = (long int *)malloc(SIZE * sizeof(long int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }
    
    
    omp_set_num_threads(16);
    
    #pragma omp parallel for
    for (long int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }
    
    long long sum = 0; 
    #pragma omp parallel for reduction(+:sum)
    for (long int i = 0; i < SIZE; i++) {
            sum += arr[i];
    }

    clock_t end = clock();
    
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken: %.5f secs\n", time_taken);
    printf("Sum: %lld\n", sum); 

    free(arr);
    
    return 0;
}

