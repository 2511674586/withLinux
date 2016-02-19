#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = NULL;

	fd = open ("/tmp/hello", O_RDWR);
	if (fd == -1)
		fputs("err\n", stderr);
	printf ("%d", fd);

	return 0;
}
