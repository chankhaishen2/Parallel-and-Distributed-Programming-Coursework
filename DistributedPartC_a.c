#include <stdio.h>
#include <mpi.h>

int main (int argc, char **argv) {
	MPI_Init(&argc, &argv);
	
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int MESSAGE_LENGTH = 20;
	
	if (rank == 0) {
		printf("Master: Hello slaves receive my message\n");
		
		MPI_Request requests[3];
		char message[] = "Hello";
		
		MPI_Isend(message, MESSAGE_LENGTH, MPI_CHAR, 1, 100, MPI_COMM_WORLD, &requests[0]);
		MPI_Isend(message, MESSAGE_LENGTH, MPI_CHAR, 2, 100, MPI_COMM_WORLD, &requests[1]);
		MPI_Isend(message, MESSAGE_LENGTH, MPI_CHAR, 3, 100, MPI_COMM_WORLD, &requests[2]);
	} 
	else {
		MPI_Request request;
		MPI_Status status;
		char message[MESSAGE_LENGTH];
		
		MPI_Irecv(message, MESSAGE_LENGTH, MPI_CHAR, 0, 100, MPI_COMM_WORLD, &request);
		MPI_Wait(&request, &status);
		printf("Message received by process %d: %s\n", rank, message);
	}
	
	MPI_Finalize();
	
	return 0;
}

