#include <stdio.h>
#include <omp.h>

void seq_workload() {
    double sum = 0.0;
    for (long i = 0; i < 100000000; i++) {
        sum += i * 0.0001;
    }
    printf("Sequential work result: %f\n", sum);
}

void par_workload() {
    double sum = 0.0;
    #pragma omp parallel for reduction(+:sum)
    for (long i = 0; i < 300000000; i++) {
        sum += i * 0.0001;
    }
    printf("Parallel work result: %f\n", sum);
}

int main() {
    double start_time = omp_get_wtime();

    double seq_start = omp_get_wtime();
    seq_workload();
    double seq_end = omp_get_wtime();
    printf("Sequential Work Time: %f seconds\n", seq_end - seq_start);

    double par_start = omp_get_wtime();
    par_workload();
    double par_end = omp_get_wtime();
    printf("Parallel Work Time: %f seconds\n", par_end - par_start);

    double end_time = omp_get_wtime();
    printf("Total Work Time: %f seconds\n", end_time - start_time);

    int num_threads = omp_get_max_threads();
    double f = 0.70;
    double speedup = 1.0 / (0.30 + (f / num_threads));
    printf("Speedup (Amdahl's Law) with %d threads: %f\n", num_threads, speedup);

    return 0;
}

