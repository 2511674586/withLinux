/* bsdbar.h

   part of Bytefreq
   cdluminate@163.com
*/
#ifndef BSDBAR_H
#define BSDBAR_H

#include <unistd.h>
#include <stdio.h>

/* INTERFACE */
void BSDbar_init (void);
void BSDbar_clear (void);
void BSDbar_refresh (void);
/* END INTERFACE */

static struct _bsdbar {
	char bar;
	struct _bsdbar * next;
} bar1, bar2, bar3;

static struct _bsdbar * _bar_cursor;

void
BSDbar_init (void)
{
    /* write a padding for the bar */
	write (2, "    ", 5);
	/* build a chain cycle */
	bar1.bar = '-';
	bar2.bar = '\\';
	bar3.bar = '/';
	bar1.next = &bar2;
	bar2.next = &bar3;
	bar3.next = &bar1;
	/* point the cursor to bar1 */
	_bar_cursor = &bar1;

	return;
}

/* this function is for internal use */
void
_BSDbar_refresh (char _bar)
{
	/* refresh BSD-style progress bar */
    /* whole buffer of the bar */
	static char bb[4] = {
        ' ', ' ', ' ', ' '
    };
	write (2, "\b\b\b\b", 5); /* clear the previous bar */
	snprintf (bb, 4, " %c  ", _bar); /* prepare buffer */
	fflush (NULL); /* sync stdio buffer to user-defined buffer */
	write (2, bb, 4); /* print the buffer to stderr */
	return;
}

void
BSDbar_refresh (void)
{
    /* note that 'int num' is the proportion to display */
    _BSDbar_refresh (_bar_cursor -> bar);
	_bar_cursor = _bar_cursor -> next;
    return;
}

void
BSDbar_clear (void)
{
    /* clear the padding/bar and newline*/
	write (2, "\b\b\b\b\n", 6);
	return;
}

#endif /* BSDBAR_H */
