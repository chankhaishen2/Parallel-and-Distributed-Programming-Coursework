#include <stdio.h>
#include <mpi.h>

int main (int argc, char **argv) {
	MPI_Init(&argc, &argv);
	
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int MESSAGE_LENGTH = 20;
	
	if (rank == 0) {
		printf("Master: Hello slaves give me your messages\n");
		
		MPI_Request requests[3];
		MPI_Status statuses[3];
		char message1[MESSAGE_LENGTH], message2[MESSAGE_LENGTH], message3[MESSAGE_LENGTH];
		
		MPI_Irecv(message1, MESSAGE_LENGTH, MPI_CHAR, 1, 99, MPI_COMM_WORLD, &requests[0]);
		MPI_Irecv(message2, MESSAGE_LENGTH, MPI_CHAR, 2, 99, MPI_COMM_WORLD, &requests[1]);
		MPI_Irecv(message3, MESSAGE_LENGTH, MPI_CHAR, 3, 99, MPI_COMM_WORLD, &requests[2]);
		
		MPI_Waitall(3, requests, statuses);
		
		printf("Message received from process 1: %s\n", message1);
		printf("Message received from process 2: %s\n", message2);
		printf("Message received from process 3: %s\n", message3);
	} 
	else if (rank == 1) {
		MPI_Request request;
		char message[] = "Hello, I am John";
		MPI_Isend(message, MESSAGE_LENGTH, MPI_CHAR, 0, 99, MPI_COMM_WORLD, &request);
	} 
	else if (rank == 2) {
		MPI_Request request;
		char message[] = "Hello, I am Mary";
		MPI_Isend(message, MESSAGE_LENGTH, MPI_CHAR, 0, 99, MPI_COMM_WORLD, &request);
	}
	else {
		MPI_Request request;
		char message[] = "Hello, I am Susan";
		MPI_Isend(message, MESSAGE_LENGTH, MPI_CHAR, 0, 99, MPI_COMM_WORLD, &request);
	}
	
	MPI_Finalize();
	
	return 0;
}

