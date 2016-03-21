
#include <stdio.h>
#include <omp.h>

int
main (void)
{
	int count = 0;
	int i = 0;
	#pragma omp parallel shared(count)
	{
		#pragma omp for
		for (i = 0; i < 10000; i++) {
			/* if you don't use atomic operation here, the result will
			 * be not 10000 */
			#pragma omp atomic update
			count += 1;
		}
		if (0 == omp_get_thread_num()) printf("count = %d\n", count);
	}
	return 0;
}
