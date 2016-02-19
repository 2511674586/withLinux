#include <string.h>

void
foo (char *bar)
{
	char c[8];
	strcpy (c, bar); /* no check on border */
}

int
main ()
{
	char array[] = "ABCDABCDABCD\x18\xFF\x18\x00";
	foo (array);
	return 0;
}
