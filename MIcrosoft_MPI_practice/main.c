#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    const int root = 0;
    const int n = 2;
    int* data = NULL;
    int local_data;

    if (rank == root) {
        data = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            data[i] = i + 1;
        }
    }

    MPI_Scatter(data, 1, MPI_INT, &local_data, 1, MPI_INT, root, MPI_COMM_WORLD);

    local_data *= 2;

    MPI_Gather(&local_data, 1, MPI_INT, data, 1, MPI_INT, root, MPI_COMM_WORLD);

    if (rank == root) {
        printf("Gathered data at root: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
        free(data);
    }

    MPI_Finalize();
    return 0;
}
