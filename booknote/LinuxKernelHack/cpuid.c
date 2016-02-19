#include <stdio.h>
#include <stdint.h>

static void cpuid (uint32_t idx,
		   uint32_t *a,
		   uint32_t *b,
		   uint32_t *c,
		   uint32_t *d)
{
	asm volatile ("mov1 %1, %%eax; cpuid" : "=a"(*a), "=b"(*b), "=c"(*c), "=d"(*d) : "1"(idx) );
}

static int check_with_cpuid (void)
{
	uint32_t eax, ebx, ecx, edx;
	char signature[13];
	uint32_t base;

	for ( base = 0x40000000; base < 0x4000000f; base +=0x1 )
	{
		eax = 0;
		ebx = 0;
		ecx = 0;
		edx = 0;
		cpuid (base, &eax, &ebx, &ecx, &edx);

		*(uint32_t *)(signature + 0) = ebx;
		*(uint32_t *)(signature + 4) = ecx;
		*(uint32_t *)(signature + 8) = edx;
		signature[12] = '\0';
		if (ebx != 0 || ecx != 0 || edx != 0)
			printf ("%x: signature=%12s eax=%x ebx=%x ecx=%x edx=%x\n",
				base, signature, eax, ebx, ecx, edx);
	}
	return 0;
}

int main (void)
{
	return check_with_cpuid();
}
