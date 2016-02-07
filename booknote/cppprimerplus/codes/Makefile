SRC=$(ls *.cc)
CXX=g++
main:
	@for X in $(shell ls *.cc); do \
		echo " CC " $$X " -> " $$X.elf; \
	   	$(CXX) -g -Wall -std=c++11 "$$X" -o "$$X.elf"; \
   	done
clean:
	-$(RM) *.elf
