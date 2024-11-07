//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(int argc, char** argv) {
//    int rank, size;
//    int arr_size = 100; 
//    int* data_arr = NULL;   
//    int l_sum = 0, total_sum = 0;
//
//    MPI_Init(&argc, &argv);               
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  
//    MPI_Comm_size(MPI_COMM_WORLD, &size);  
//
//    int chunk_size = arr_size / size;
//
//    int* l_data_arr = (int*)malloc(chunk_size * sizeof(int));
//
//    if (rank == 0) {
//        data_arr = (int*)malloc(arr_size * sizeof(int));
//        for (int i = 0; i < arr_size; i++) {
//            data_arr[i] = i + 1;
//        }
//    }
//
//    MPI_Scatter(data_arr, chunk_size, MPI_INT, l_data_arr, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);
//
//    for (int i = 0; i < chunk_size; i++) {
//        l_sum += l_data_arr[i];
//    }
//
//    MPI_Reduce(&l_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
//
//    if (rank == 0) {
//        printf("Total sum: %d\n", total_sum);
//        free(data_arr);
//    }
//
//    free(l_data_arr);
//    MPI_Finalize();
//    return 0;
//}
