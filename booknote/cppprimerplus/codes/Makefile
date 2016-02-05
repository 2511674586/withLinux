SRC=$(ls *.cc)
CXX=g++
main:
	@for X in $(shell ls *.cc); do \
		echo "Compiling " $$X " -> " $$X.elf; \
	   	$(CXX) -Wall -std=c++11 "$$X" -o "$$X.elf"; \
   	done
clean:
	-$(RM) *.elf
