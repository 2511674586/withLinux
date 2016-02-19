/* this is a sample of buffer overflow
 * it is dropped from <<信息安全技术实用教程 电子工业出版社>>
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void
foo (int a, int b, int c)
{
	char buffer[8]; // char buffer[9];
	int *ret;
	ret = (int*)(buffer + 16); // ret = (int*)(buffer + 17);
	(*ret) += 7;
}

int
main (void)
{
	int x;
	x = 99999;
	foo (1, 2, 3);
	x = 1;
	printf("%d\n", x);

	return 0;
}

