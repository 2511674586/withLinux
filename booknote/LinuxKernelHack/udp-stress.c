/* this is a dropped program from linux kernel hacks, 机械工业出版社
 * send flood of udp packet.
 */

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DADDR "192.168.0.112"
#define PORT 5000

int
main (int argc, char **argv)
{
	int sock = 0;
	struct sockaddr_in dest;
	char tmpbuf[] = {"stress"};

	sock = socket (PF_INET, SOCK_DGRAM, 0);
	if (!sock) {
		perror ("socket");
		return 1;
	}

	dest.sin_family = AF_INET;
	dest.sin_port = htons (PORT);
	dest.sin_addr.s_addr = inet_addr (DADDR);

	if (connect (sock, (struct sockaddr *)&dest, sizeof (dest)) == -1) {
		perror ("connect");
		return 1;
	}

	while (1)
		sendto (sock, tmpbuf, strlen (tmpbuf) +1, 0,
				(struct sockaddr *)&dest, sizeof (dest));
	
	close (sock);
	return 0;
}
