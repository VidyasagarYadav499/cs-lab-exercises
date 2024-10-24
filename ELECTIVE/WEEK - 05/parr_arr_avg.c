#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SIZE 100000000

int main() {
    double start = omp_get_wtime();
    
    long int* arr = (long int *)malloc(SIZE * sizeof(long int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    omp_set_num_threads(2);
    
    #pragma omp parallel for
    for (long int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    long long sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (long int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    double average = (double)sum / SIZE;

    double end = omp_get_wtime();
    double time_taken = end - start;

    printf("Time taken: %.5f secs\n", time_taken);
    printf("Average: %.5f\n", average);

    free(arr);

    return 0;
}

