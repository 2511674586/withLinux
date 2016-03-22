CC=gcc
CFLAGS=-fopenmp -g -Wall -std=c99
main:
	@parallel 'printf " CC %s\n" {} ; $(CC) $(CFLAGS) {} -o {.}.elf' ::: *.c
clean:
	-$(RM) *.elf
