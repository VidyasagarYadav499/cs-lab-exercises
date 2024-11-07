//#include <mpi.h>
//#include <stdio.h>
//
//int main(int argc, char** argv) {
//    MPI_Init(&argc, &argv);
//
//    int rank;
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    int message;
//
//    if (rank == 0) {
//        message = 100;
//        MPI_Send(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
//        printf("Process 0 sent -> %d to Process 1\n", message);
//
//        MPI_Recv(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//        printf("Process 0 received modified message -> %d from Process 1\n", message);
//
//    }
//    else if (rank == 1) {
//        MPI_Recv(&message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//        printf("Process 1 received -> %d\n from Process 0", message);
//
//        message += 10;
//        MPI_Send(&message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
//    }
//
//    MPI_Finalize();
//    return 0;
//}
