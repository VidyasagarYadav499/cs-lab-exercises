#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100000000 // Define the size of the array

int main() {
    long int* arr = (long int *)malloc(SIZE * sizeof(long int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }

    // Initialize number of threads
    int num_threads = 16;
    omp_set_num_threads(num_threads);
    
    // Each thread starts with a specific value and captures the last initialized value
    #pragma omp parallel firstprivate(num_threads) lastprivate(arr)
    {
        long int tid = omp_get_thread_num();
        long int start_value = tid * (SIZE / num_threads) + 1;
        long int end_value = (tid + 1) * (SIZE / num_threads);

        // Initialize array elements in chunks by each thread
        for (long int i = start_value; i <= end_value; i++) {
            arr[i - 1] = i; // Fill the array
        }

        // Capture the last initialized value by each thread
        long int last_value = end_value;
        #pragma omp critical
        {
            arr[SIZE - 1] = last_value; // Update the last element with the last value
        }
    } // Implicit barrier is avoided with the nowait clause

    // Print the last initialized value
    printf("Last initialized value: %ld\n", arr[SIZE - 1]);

    free(arr);
    return 0;
}

