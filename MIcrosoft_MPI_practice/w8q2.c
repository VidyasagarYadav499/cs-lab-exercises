//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char** argv) {
//    int rank, size;
//    int n = 1000;
//    int* data = NULL;
//    int l_count;
//    double l_sum = 0.0, g_sum = 0.0;
//    int g_count = 0;
//
//    MPI_Init(&argc, &argv);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//    l_count = n / size;
//    int* l_data = (int*)malloc(l_count * sizeof(int));
//
//    if (rank == 0) {
//        data = (int*)malloc(n * sizeof(int));
//        for (int i = 0; i < n; i++) {
//            data[i] = i + 1;
//        }
//    }
//
//    MPI_Scatter(data, l_count, MPI_INT, l_data, l_count, MPI_INT, 0, MPI_COMM_WORLD);
//
//    for (int i = 0; i < l_count; i++) {
//        l_sum += l_data[i];
//    }
//
//    MPI_Reduce(&l_sum, &g_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
//    MPI_Reduce(&l_count, &g_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
//
//    if (rank == 0) {
//        double g_avg = g_sum / g_count;
//        printf("Global average is: %f\n", g_avg);
//        free(data);
//    }
//
//    free(l_data);
//    MPI_Finalize();
//    return 0;
//}
