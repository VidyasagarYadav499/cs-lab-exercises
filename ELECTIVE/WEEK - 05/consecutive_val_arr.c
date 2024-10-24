7#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100000000 

int main() {
    long int* arr = (long int *)malloc(SIZE * sizeof(long int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }
    
    int num_threads = 16;
    omp_set_num_threads(num_threads);
    
    #pragma omp parallel firstprivate(num_threads) lastprivate(arr)
    {
        long int tid = omp_get_thread_num();
        long int start_value = tid * (SIZE / num_threads) + 1;
        long int end_value = (tid + 1) * (SIZE / num_threads);

        for (long int i = start_value; i <= end_value; i++) {
            arr[i - 1] = i; 
        }

        long int last_value = end_value;
        #pragma omp critical
        {
            arr[SIZE - 1] = last_value;
        }
    } 
    
    printf("Last initialized value: %ld\n", arr[SIZE - 1]);

    free(arr);
    return 0;
}

