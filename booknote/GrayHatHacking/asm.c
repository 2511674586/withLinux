#include <stdio.h>

unsigned long
get_sp (void)
{
	__asm__("mov %rsp, %rax");
}

int
main (void)
{
	printf ("Stack pointer (RSP) : 0x%x\n", get_sp());
}
