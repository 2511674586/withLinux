/* init.c - cdluminate@163.com */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bsdbar.h"

#define star     "\x1b[1;32m * \x1b[0;m"
#define cinfo    "\x1b[36m"
#define cnormal  "\x1b[32m"
#define cwarn    "\x1b[31m"
#define cend     "\x1b[0;m\n"

#define INFO 1
#define NORMAL 2
#define WARN 3

void
sdump (int level, char * string)
{
    write (1, star, sizeof(star));
    switch (level) {
    case INFO:
        write (1, cinfo, sizeof(cinfo));
        break;
    case NORMAL:
        write (1, cnormal, sizeof(cnormal));
        break;
    case WARN:
        write (1, cwarn, sizeof(cwarn));
        break;
    default:
        ;
    }
    write (1, string, strlen(string));
    write (1, cend, sizeof(cend));
    return;
}

void
main (int argc, char **argv, char **env)
{
    long counter = 0;
    sdump (WARN, "Welcome to infinite init !");
    sleep (1);
    sdump (NORMAL, "Loop start ...");
    BSDbar_init ();
    while (1) {
        counter++;
        usleep (80);
        BSDbar_refresh ();
        if (counter > 10000 || counter < 0) {
            BSDbar_clear ();
            sdump (INFO, "passed 10000 cycle.");
            counter = 0;
        } 
    }
    BSDbar_clear ();
    return;
}
