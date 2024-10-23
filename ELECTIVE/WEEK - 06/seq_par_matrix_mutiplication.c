#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100

void seq(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void par(int A[N][N], int B[N][N], int C[N][N]) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }

    double start_time = omp_get_wtime();
    seq(A, B, C);
    double end_time = omp_get_wtime();
    printf("Sequential Matrix Multiplication Time: %f seconds\n", end_time - start_time);

    start_time = omp_get_wtime();
    par(A, B, C);
    end_time = omp_get_wtime();
    printf("Parallel Matrix Multiplication Time: %f seconds\n", end_time - start_time);

    return 0;
}

