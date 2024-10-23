#include <stdio.h>
#include <omp.h>

int main() {
    const int N = 100; 
    int arr[N];
    int start_idx = 0;
    int last_idx;       
    
    for(int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }
    
    
    #pragma omp parallel firstprivate(start_idx)
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        int chunk_size = N / num_threads;
        
        start_idx = thread_id * chunk_size;
        
        #pragma omp for lastprivate(last_idx) nowait
        for(int i = 0; i < N; i++) {
            arr[i] = arr[i] * 2;
            last_idx = i; 
        }
        
        printf("Thread %d: processed indices %d to %d\n", 
               thread_id, start_idx, start_idx + chunk_size - 1);
    }
    
    printf("\nLast index processed (from lastprivate): %d\n", last_idx);
    
    printf("\nDoubled first 5 values: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Doubled last 5 values: ");
    for(int i = N-5; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
