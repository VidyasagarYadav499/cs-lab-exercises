//#include <mpi.h>
//#include <stdio.h>
//
//int main(int argc , char *argv[]) {
//	// initialize the MPI environment
//	MPI_Init(&argc, &argc);
//	int rank, size;
//	//how many processes in the communicator?
//	MPI_Comm_size(MPI_COMM_WORLD,&size);
//	//rank or the id of the calling process
//	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
//
//	printf("Hello World! from process (ID) %d of total %d processes!", rank, size);
//
//	MPI_Finalize();
//
//	return 0;
//}