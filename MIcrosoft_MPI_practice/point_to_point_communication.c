//#include <mpi.h>
//#include <stdio.h>
//
//int main(int argc, char **argv) {
//
//	MPI_Init(&argc, &argv);
//
//	int rank, size;
//	int message;
//	MPI_Status status;
//	
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	if (rank == 1) {
//		message = 42;
//		MPI_Send(&message, 1 , MPI_INT, 0, 100, MPI_COMM_WORLD);
//		printf("Message %d, sent from process %d\n", message, rank);
//	}
//
//	if (rank == 0) {
//		MPI_Recv(&message, 1, MPI_INT, 1, 100, MPI_COMM_WORLD, &status);
//		printf("Message %d, recieved from process %d\n", message, rank);
//	}
//
//	MPI_Finalize();
//
//	return 0;
//}