#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4  // Size of the matrix (N x N)
#define EPSILON 1e-10

void print_matrix(double matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%8.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double matrix[N][N + 1];  // Augmented matrix (includes constants on the right side)
    int rows_per_process = N / size;
    int start_row = rank * rows_per_process;
    int end_row = start_row + rows_per_process;

    if (rank == 0) {
        // Initialize the augmented matrix with some values
        double temp_matrix[N][N + 1] = {
            {2.0, -1.0, 1.0, 2.0, 1.0},
            {4.0, 2.0, -3.0, 5.0, 2.0},
            {-2.0, 1.0, 2.0, -1.0, -1.0},
            {3.0, 2.0, 1.0, -3.0, 3.0}
        };

        for (int i = 0; i < N; i++)
            for (int j = 0; j <= N; j++)
                matrix[i][j] = temp_matrix[i][j];

        printf("Initial matrix:\n");
        print_matrix(matrix);
    }

    MPI_Bcast(matrix, N * (N + 1), MPI_DOUBLE, 0, MPI_COMM_WORLD);

    for (int k = 0; k < N; k++) {
        if (rank == 0) {
            if (fabs(matrix[k][k]) < EPSILON) {
                printf("Matrix is singular or nearly singular!\n");
                MPI_Abort(MPI_COMM_WORLD, 1);
            }
        }

        MPI_Bcast(&matrix[k][0], N + 1, MPI_DOUBLE, k / rows_per_process, MPI_COMM_WORLD);

        for (int i = start_row; i < end_row; i++) {
            if (i > k) {
                double factor = matrix[i][k] / matrix[k][k];
                for (int j = k; j <= N; j++) {
                    matrix[i][j] -= factor * matrix[k][j];
                }
            }
        }

        for (int i = start_row; i < end_row; i++) {
            MPI_Bcast(&matrix[i][0], N + 1, MPI_DOUBLE, rank, MPI_COMM_WORLD);
        }
    }

    if (rank == 0) {
        double solution[N];
        for (int i = N - 1; i >= 0; i--) {
            solution[i] = matrix[i][N] / matrix[i][i];
            for (int j = i - 1; j >= 0; j--) {
                matrix[j][N] -= matrix[j][i] * solution[i];
            }
        }

        printf("\nSolution:\n");
        for (int i = 0; i < N; i++) {
            printf("x%d = %8.4f\n", i + 1, solution[i]);
        }
    }

    MPI_Finalize();
    return 0;
}
