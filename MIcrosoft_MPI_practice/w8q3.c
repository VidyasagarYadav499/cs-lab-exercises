//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//#define N 3
//
////void print_matrix(double matrix[N][N + 1]) {
////    for (int i = 0; i < N; i++) {
////        for (int j = 0; j <= N; j++) {
////            printf("%8.3f ", matrix[i][j]);
////        }
////        printf("\n");
////    }
////}
//
//
//void g_elim(double matrix[N][N + 1], int rank, int size) {
//    int i, j, k;
//    for (k = 0; k < N; k++) { // row loop
//        MPI_Bcast(matrix[k], N + 1, MPI_DOUBLE, k % size, MPI_COMM_WORLD); //one process broadcasts its rows
//
//        for (i = k + 1; i < N; i++) { // look at the rows below row k, ith row is the pivot row
//            if (i % size == rank) {  
//                double factor = matrix[i][k] / matrix[k][k];
//                for (j = k; j <= N; j++) { // jth col including the vector, har 
//                    matrix[i][j] -= factor * matrix[k][j];
//                }
//            }
//        }
//    }
//}
//
//void b_subs(double matrix[N][N + 1], double solution[N], int rank, int size) {
//
//    for (int i = N - 1; i >= 0; i--) {
//        if (rank == i % size) {  // Only the responsible process computes this part
//            solution[i] = matrix[i][N] / matrix[i][i];
//        }
//        MPI_Bcast(&solution[i], 1, MPI_DOUBLE, i % size, MPI_COMM_WORLD);
//
//        // Update the matrix
//        for (int j = 0; j < i; j++) {
//            if (rank == j % size) {
//                matrix[j][N] -= matrix[j][i] * solution[i];
//            }
//        }
//    }
//}
//
//int main(int argc, char** argv) {
//    int rank, size;
//    MPI_Init(&argc, &argv);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//    double matrix[N][N + 1] = { {3.0, 2.0, -1.0, 1.0}, {2.0, -2.0, 4.0, -2.0}, {-1.0, 0.5, -1.0, 0.0} };
//    double sol[N] = { 0.0 };
//
//    /* if (rank == 0) {
//         printf("Initial matrix:\n");
//         print_matrix(matrix);
//     }*/
//
//    g_elim(matrix, rank, size);
//    b_subs(matrix, sol, rank, size);
//
//    if (rank == 0) {
//        printf("\nSolution:\n");
//        for (int i = 0; i < N; i++) {
//            printf("x%d = %.3f\n", i, sol[i]);
//        }
//    }
//
//    MPI_Finalize();
//    return 0;
//}
