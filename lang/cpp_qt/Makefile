CXX=g++
CXXFLAG=-g -Wall
INCLUDE=-I/usr/include/qt4/
LIBRARY=-lQtCore -lQtGui

COMPILE=$(CXX) $(CXXFLAG) $(INCLUDE) $(LIBRARY)

.PHONY: main info hello clean
main: info hello
info:
	@echo run "apt install libqt4-dev qt4-doc qt4-doc-html" on Debian jessie

hello:
	$(COMPILE) hello.cc -o hello.elf
clean:
	-$(RM) *.elf
