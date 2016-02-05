SRC=$(ls *.cc)
main:
	for X in $(shell ls *.cc); \
	   	do g++ -Wall -std=c++11 "$$X" -o "$$X.elf"; \
   	done
clean:
	-$(RM) *.elf
