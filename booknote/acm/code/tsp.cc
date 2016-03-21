/**
 * @file tsp.cc
 * @brief solves traveling salesman problem with brute force
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
_permutation (
	float W[6][6],
	int size,
	std::vector<int> buf,
	std::vector<int> * stack,
	std::vector<int> * solution,
	float * sum_min)
{
	if (stack->size() == buf.size()) {
		float sum = .0;
		// vector_dump(*stack); // don't dump permutation
		// check this perm
		for (unsigned int i = 0; i < stack->size(); i++)
			if ((int)i == stack->at(i)) return;
		// update solution if this is better
		for (unsigned int i = 1; i < stack->size(); i++) {
			sum += W[stack->at(i-1)][stack->at(i)];
		}
		sum += W[stack->back()][stack->front()];
		if (*sum_min == .0) { // the first permutation, just update solution
			*sum_min = sum;
			*solution = *stack;

			std::cout << "initial try: " << sum << " with";
			vector_dump (*stack);
		} else { // test current perm stack
			if (*sum_min > sum) {
				*sum_min = sum;
				*solution = *stack;

				std::cout << "found better result: " << sum << " with";
				vector_dump (*stack);
			}
		}
	} else {
		for (unsigned int i = 0; i < buf.size(); i++) {
			if (i_in_stack(i, *stack)) continue;
			else {
				stack->push_back(i);
				_permutation (W, size, buf, stack, solution, sum_min);
				(void) stack->pop_back();
			}
		}
	}
	return;
}


void
tsp (
	float W[6][6], // weight
	int size,
	std::vector<int> * solution,
	float * sum_min)
{
	std::vector<int> buf;
	std::vector<int> stack;
	for (int i = 0; i < size; i++) buf.push_back(1);
	_permutation (W, size, buf, &stack, solution, sum_min);
	return;
}

/**
 * @brief test the permutation implementation
 */
int
main (void)
{
	// weight matrix
	float W[6][6] =
	{
		{ 0,13,51,77,68,50},
		{13, 0,60,70,67,59},
		{51,60, 0,57,36, 2},
		{77,70,57, 0,20,55},
		{68,67,36,20, 0,34},
		{50,59, 2,55,34, 0}
	};

	std::vector<int> solution;
	float sum_min = 0.;

	tsp (W, 6, &solution, &sum_min);

	return 0;
}
