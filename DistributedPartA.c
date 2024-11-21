#include <stdio.h>
#include <mpi.h>

int main (int argc, char **argv) {
	MPI_Init(&argc, &argv);
	
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	printf("Process %d: Hello World\n", rank);
	
	MPI_Finalize();
	
	return 0;
}

