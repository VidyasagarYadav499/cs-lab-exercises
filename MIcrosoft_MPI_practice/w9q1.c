//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//#define TOL 1e-3
//#define ITER 15
//
//void parallel_gauss_seidel(double* A, double* b, double* x, int n, int rows_per_proc, int rank, int size) {
//    int i, j, iteration;
//    double* local_A = malloc(rows_per_proc * n * sizeof(double));
//    double* local_b = malloc(rows_per_proc * sizeof(double));
//    double* local_x = malloc(rows_per_proc * sizeof(double));
//    double* x_global = malloc(n * sizeof(double));
//    int converged = 0;
//
//    MPI_Scatter(A, rows_per_proc * n, MPI_DOUBLE, local_A, rows_per_proc * n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
//    MPI_Scatter(b, rows_per_proc, MPI_DOUBLE, local_b, rows_per_proc, MPI_DOUBLE, 0, MPI_COMM_WORLD);
//
//    // Initialize local x with the global guess
//    for (i = 0; i < rows_per_proc; i++) {
//        local_x[i] = x[rank * rows_per_proc + i];
//    }
//
//    // iteration loop
//    for (iteration = 0; iteration < ITER && !converged; iteration++) {
//        converged = 1;
//
//        // Update each row assigned to the current process
//        for (i = 0; i < rows_per_proc; i++) {
//            int global_i = rank * rows_per_proc + i;
//            double sum = 0.0;
//
//            // Calculate the sum for the current row, excluding the diagonal element
//            for (j = 0; j < n; j++) {
//                if (j != global_i) {
//                    sum += local_A[i * n + j] * x[j];
//                }
//            }
//
//            // Update the solution for the current row
//            double new_x = (local_b[i] - sum) / local_A[i * n + global_i];
//            if (fabs(new_x - local_x[i]) > TOL) {
//                converged = 0;
//            }
//            local_x[i] = new_x;
//        }
//
//        MPI_Allgather(local_x, rows_per_proc, MPI_DOUBLE, x, rows_per_proc, MPI_DOUBLE, MPI_COMM_WORLD);
//
//        int global_converged;
//        MPI_Allreduce(&converged, &global_converged, 1, MPI_INT, MPI_LAND, MPI_COMM_WORLD);
//        if (global_converged) {
//            break;
//        }
//    }
//
//    free(local_A);
//    free(local_b);
//    free(local_x);
//    free(x_global);
//}
//
//int main(int argc, char* argv[]) {
//    int rank, size, n = 3;
//    double A[] = { 2, -1, 0, -1, 2, -1, 0, -1, 2 };
//    double b[] = { 7, 1, 1 };
//    double x[] = { 0, 0, 0 };
//
//    MPI_Init(&argc, &argv);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//    if (n % size != 0) {
//        if (rank == 0) {
//            printf("Matrix size must be divisible by the number of processes.\n");
//        }
//        MPI_Finalize();
//        return -1;
//    }
//
//    int rows_per_proc = n / size;
//
//    parallel_gauss_seidel(A, b, x, n, rows_per_proc, rank, size);
//
//    if (rank == 0) {
//        printf("Solution vector x:\n");
//        for (int i = 0; i < n; i++) {
//            printf("%f ", x[i]);
//        }
//        printf("\n");
//    }
//
//    MPI_Finalize();
//    return 0;
//}
