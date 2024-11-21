#include <stdio.h>
#include <omp.h>

int main() {	
	#pragma omp parallel num_threads(10)
	{
		printf("Thread %d: Hello World\n", omp_get_thread_num());
	}
	
	return 0;
}

