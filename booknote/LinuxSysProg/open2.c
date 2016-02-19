#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

	while (len != 0 && (ret == read (fd, buf, len )) != 0)
	{
		if (ret == -1)
		{
			if (errno == EINTR)
				continue;
			perror ("read");
			break;
		}
		len -= ret;
		buf += ret;
	}

