#include <stdio.h>

int
main (void)
{
	float n = 0.;
	for (long i = 0; i < 67108864; i++) {
		n += 1.;
		if (0 == i % 1000000) printf (" iter %ld, n = %lf\n", i, n);
	}
	// you may find that the resulting n is not 67108864,
	// the reason lies in IEEE 754, single precision.
	return 0;
}
