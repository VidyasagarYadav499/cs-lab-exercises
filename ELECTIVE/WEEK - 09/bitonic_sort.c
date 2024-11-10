#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 16

void swap(int *arr, int i, int j, int dir) {
    if (dir == (arr[i] > arr[j])) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void sequentialBitonicMerge(int *arr, int low, int cnt, int dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++) {
            swap(arr, i, i + k, dir);
        }
        sequentialBitonicMerge(arr, low, k, dir);
        sequentialBitonicMerge(arr, low + k, k, dir);
    }
}

void sequentialBitonicSort(int *arr, int low, int cnt, int dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        sequentialBitonicSort(arr, low, k, 1);  // Ascending
        sequentialBitonicSort(arr, low + k, k, 0);  // Descending
        sequentialBitonicMerge(arr, low, cnt, dir);
    }
}

void parallelBitonicMerge(int *arr, int low, int cnt, int dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++) {
            swap(arr, i, i + k, dir);
        }

        #pragma omp task shared(arr)
        parallelBitonicMerge(arr, low, k, dir);
        
        #pragma omp task shared(arr)
        parallelBitonicMerge(arr, low + k, k, dir);
        
        #pragma omp taskwait
    }
}

void parallelBitonicSort(int *arr, int low, int cnt, int dir) {
    if (cnt > 1) {
        int k = cnt / 2;

        #pragma omp task shared(arr)
        parallelBitonicSort(arr, low, k, 1);  // Ascending

        #pragma omp task shared(arr)
        parallelBitonicSort(arr, low + k, k, 0);  // Descending
        
        #pragma omp taskwait
        parallelBitonicMerge(arr, low, cnt, dir);
    }
}


int main() {
    int arr[N], arr_copy[N];
    srand(time(0));

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000;
        arr_copy[i] = arr[i];
    }

    double start_seq = omp_get_wtime();
    sequentialBitonicSort(arr_copy, 0, N, 1);
    double end_seq = omp_get_wtime();
    double time_seq = end_seq - start_seq;
    printf("Time taken by Sequential Bitonic Sort: %f seconds\n", time_seq);

    double start_par = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single
        parallelBitonicSort(arr, 0, N, 1);
    }
    double end_par = omp_get_wtime();
    double time_par = end_par - start_par;
    printf("Time taken by Parallel Bitonic Sort: %f seconds\n", time_par);

    double speedup = time_seq / time_par;
    printf("Speedup of Parallel over Sequential: %fx\n", speedup);
    
    printf("arr after sorting:\n");
    for(int i = 0; i < N; i++) {
    	printf("%d ", arr[i]);
	}

    return 0;
}

