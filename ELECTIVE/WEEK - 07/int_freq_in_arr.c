#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define SIZE 1000000
#define NUM_THREADS 8

int main() {
    srand(time(NULL));

    long int *arr = (long int *)malloc(SIZE * sizeof(long int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    int freq_arr[100] = {0};

    double start = omp_get_wtime();

    // Sequential
    for (int i = 0; i < SIZE; i++) {
        freq_arr[arr[i]]++;
    }
    double end = omp_get_wtime();
    double seq_time = end - start;
    printf("Sequential Time: %f seconds\n", seq_time);

    for (int i = 0; i < 100; i++) {
        freq_arr[i] = 0;
    }

    start = omp_get_wtime();

    // Parallel
    #pragma omp parallel for num_threads(NUM_THREADS) shared(freq_arr)
    for (int i = 0; i < SIZE; i++) {
        #pragma omp atomic
        freq_arr[arr[i]]++;
    }
    end = omp_get_wtime();
    double par_time = end - start;
    double speedup = seq_time / par_time;
    double efficiency = speedup / NUM_THREADS;
    printf("Parallel Time with %d threads: %f seconds\n", NUM_THREADS, par_time);
    printf("Speedup: %f, Efficiency: %f\n", speedup, efficiency);

    free(arr);
    return 0;
}
