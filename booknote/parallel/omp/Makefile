CC=gcc
CFLAGS=-fopenmp -g -Wall
main:
	@parallel 'printf " CC %s\n" {} ; $(CC) $(CFLAGS) {} -o {.}.elf' ::: *.c
clean:
	-$(RM) *.elf
