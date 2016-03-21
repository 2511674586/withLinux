
#include <stdio.h>
#include <omp.h>

int
main (void)
{
	int nthreads, tid;
	#pragma omp parallel private(tid)
   	{
		tid = omp_get_thread_num();
		printf("Hello OpenMP from thread %d\n", tid);
		if (tid == 0) { // main thread
			nthreads = omp_get_num_threads();
			printf("nthreads = %d\n", nthreads);
		}
	}
	return 0;
}
