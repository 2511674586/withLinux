/**
 * @file permutation.cc
 * @brief show all possible permutations of a given vector
 */
#include <vector>
#include <iostream>
#include "vectorutil"

/// debug flag, 0 to disable.
int debug = 0;

/**
 * @brief test if number i is in the vector named "stack"
 * @param i is the query key
 * @param stack is the vector to look up
 * @return true if found.
 */
bool
i_in_stack (int i, std::vector<int> stack)
{
	for (unsigned int j = 0; j < stack.size(); j++) {
		if (stack[j] == i) return true;
	}
	return false;
}

/**
 * @brief Core permutation function, this is a recursive implementation
 * @param buf, the number sequence to be permuted
 * @param stack, memory stack storing chosen path
 * @return void
 */
void
_permutation (std::vector<int> buf, std::vector<int> * stack)
{
	if (debug) {
		std::cout << "dump _permutation" << std::endl << "buf";
		vector_dump(buf);
		std::cout << "stack ";
		vector_dump(*stack);
	}
	if (stack->size() == buf.size()) {
		vector_dump(*stack);
		for (unsigned int i = 0; i < stack->size(); i++) {
			std::cout << " " << buf[stack->at(i)] << " ";
		}
		std::cout << std::endl;
	} else {
		for (unsigned int i = 0; i < buf.size(); i++) {
			if (i_in_stack(i, *stack)) continue;
			else {
				stack->push_back(i);
				_permutation (buf, stack);
				(void) stack->pop_back();
			}
		}
	}
	return;
}

/**
 * @brief wrapper of the core permutation function
 * @param buf, the sequence of numbers that to be permuted
 * @return 0
 */
int
permutation (std::vector<int> buf)
{
	std::vector<int> stack;
	_permutation (buf, &stack);
	return 0;
}

/**
 * @brief test the permutation implementation
 */
int
main (void)
{
	std::vector<int> buf;
	buf.push_back(2);
	buf.push_back(5);
	buf.push_back(8);
	buf.push_back(4);

	permutation(buf);
	return 0;
}
