
#include <stdio.h>
#include <omp.h>

int
main (void)
{
	int tid, i;
	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();
		printf("static scheduler ...\n");
		#pragma omp for schedule(static) // schedule(static|dynamic)
		for (i = 0; i < 12; i++) {
			printf("tid %d prints %d\n", tid, i);
		}
		printf("dynamic scheduler ...\n");
		#pragma omp barrier
		#pragma omp for schedule(dynamic) // schedule(static|dynamic)
		for (i = 0; i < 12; i++) {
			printf("tid %d prints %d\n", tid, i);
		}
	}
	return 0;
}
