SRC=$(ls *.cc)
main:
	for X in "$(shell ls *.cc)"; do g++ -std=c++11 -o $$X.elf $$X ; done
clean:
	-$(RM) *.elf
