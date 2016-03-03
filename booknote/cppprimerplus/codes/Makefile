SRC=$(ls *.cc)
CXX=g++
main: compile_all_parallel
compile_all_serial:
	@for X in $(shell ls *.cc); do \
		printf " CC %s\n" $$X; \
	   	$(CXX) -g -Wall -std=c++11 "$$X" -o "$$X.elf"; \
   	done
compile_all_parallel:
	# using GNU parallel, to compile sources in parallel
	parallel 'printf " CC %s\n" {} ; $(CXX) -g -Wall -std=c++11 {} -o {.}.elf' ::: *.cc
clean:
	-$(RM) *.elf
