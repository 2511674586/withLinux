#include <stdio.h>
#include <stdlib.h>

#define  db(msg) \
	fputs("Debug : ", stderr);\
	fputs(msg, stderr);\
	fputc('\n', stderr)

int getpassword (void); /* read password from keyboard.
			   correct --> return 0
			   	or exit -1 */
int showsecret (void);

int
main (void)
{
	db ("passwd :");
	getpassword ();
	
	db ("correct");
	showsecret ();

	return 0;
}

int
getpassword (void)
{
	char c;
	if ( (c=fgetc (stdin)) != 'p' ) {
		db ("incorrect");
		exit (-1);
	}
	return 0;
}

int
showsecret (void)
{
	fputs ("\
The message is\n",
   	       stdout);
	return 0;
}

