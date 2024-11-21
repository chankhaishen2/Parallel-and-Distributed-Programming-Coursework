#include <stdio.h>
#include <omp.h>
#include <time.h>

int main() {
	int VECTOR_SIZE = 2000;
	int vector1[VECTOR_SIZE], vector2[VECTOR_SIZE], vectorSum[VECTOR_SIZE];
	
	for (int i = 0; i < VECTOR_SIZE; i++) {
		vector1[i] = (i+1)*100;
	}
	
	for (int i = 0; i < VECTOR_SIZE; i++) {
		vector2[i] = i+3;
	}
	
	clock_t start = clock();
	#pragma omp parallel for schedule(static) num_threads(4)
	for (int i = 0; i < VECTOR_SIZE; i++) {
		vectorSum[i] = vector1[i] + vector2[i];
	}
	clock_t end = clock();
	printf("Time: %ld clocks\n", end-start);
	
	return 0;
}

