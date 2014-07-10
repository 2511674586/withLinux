#include <stdio.h>
#include <stdlib.h>

int
Usage (void)
{
	fputs ("\
Usage of \%s <argv[0]> : hex edit.\n", stderr);
	return 0;
}

long get_password_hash (void);
int show_secret (void);

int
main (void)
{
	long hash;

	fputs ("Please give the password first:\n", stdout);
	hash = get_password_hash ();

	printf ("the password hash is %ld .\n", hash);

	/* the password is "password" */
	if (hash != 29798) {
		fputs ("Wrong password!\n", stderr);
		exit (-1);
	}

	fputs ("Correct PASSWORD !\n", stderr);
	show_secret ();
	
	return 0;
}

long
get_password_hash (void)
{
	char string[16] = {0};
	fgets (string, 16, stdin);
	
	int worker_hash = 0;
	int i;
	for (i=0; i<16; i++) {
        /* emulate the process of hash */
		worker_hash += (long)(string[i]) * (1<<i);
	}
	return worker_hash;
}

int
show_secret (void)
{
	fputs ("\
OK, In fact, the secret is :\n\
    this programe contains no any secrets.\n", stdout);
	return 0;
}
