/* printf_colour.c
   a sample showing how to print text in colour (in terminal).
   C.D.Luminate
   	at 30/06/2014
 */

#include <stdio.h>

int
main (void)
{
	/* int fprintf(FILE *stream, const char *format, ...); */
	fprintf (stdout, "\033[31m RED hello world.\033[m\n");

	/* chars after "\033[31m" will be printed in red,
	   while colour of chars after "\033[m" is restored.
	 */
	
	/* it is green */
	fprintf (stdout, "\033[32m what colour is it\033[m\n");
	
	/* tips : 
	   using vim, press Ctrl^V then ESC, will insert a char '\033',
	   which is displayed as '^[' and it is one char, rather than
	   '^' + '['
	 */

	/* 31 red
	   32 green
	   33 yellow
	   34 blue
	   35 purple
	   36 colour bettwen green and blue.
	   37 grey
	 */
	return 0;
}

/*
 * Reference:
 *
 * screen(1), where an amount of terminal control sequences are introduced.
 *
 */
