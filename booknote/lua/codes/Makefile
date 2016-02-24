CC=gcc

main: mylua mylib

mylua:
	$(CC) -Wall mylua.c -o mylua -llua5.1
mylib:
	$(CC) -shared mylib.c -llua5.1 -fPIC -o mylib.so
	lua5.1 -e 'require "mylib"; a = mylib.hello()'
clean:
	$(RM) mylua mylib.so
