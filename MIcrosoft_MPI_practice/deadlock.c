//#include <mpi.h>
//#include <stdio.h>
//int main(int argc, char** argv) {
//	int rank, size;
//	MPI_Init(&argc, &argv);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	int send_data = rank; // Each process sends its rank
//	int recv_data;
//	if (size != 2) {
//		printf("This program requires exactly 2 processes.\n");
//		MPI_Abort(MPI_COMM_WORLD, 1);
//	}
//	/*Deadlock*/
//	if (rank == 0) {
//		// Process 0 sends a message to Process 1 and waits to receive from Process 1
//		MPI_Send(&send_data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
//		MPI_Recv(&recv_data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//	}
//	else if (rank == 1) {
//		// Process 1 sends a message to Process 0 and waits to receive from Process 0
//		MPI_Send(&send_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
//		MPI_Recv(&recv_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//	}
//	printf("Process %d received %d\n", rank, recv_data);
//	MPI_Finalize();
//	return 0;
//}