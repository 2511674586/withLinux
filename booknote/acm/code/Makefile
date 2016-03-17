SRC=$(ls *.cc)
CXX=g++
main: compile_all_parallel
compile_all_serial:
	@for X in $(shell ls *.cc); do \
		printf " CC %s\n" $$X; \
	   	$(CXX) -g -Wall -std=c++11 "$$X" -o "$$X.elf"; \
   	done
compile_all_parallel:
	# Compiling sources in parallel using GNU parallel
	@parallel 'printf " CC %s\n" {} ; $(CXX) -g -Wall -std=c++11 {} -o {.}.elf' ::: *.cc
	# Done
clean:
	-$(RM) *.elf
