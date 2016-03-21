/**
 * @file assign.cc
 * @brief solve task assigning problem
 */
#include <vector>
#include <iostream>
#include "vectorutil"

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


void
_assign_problem (
	int cost [4][4],
   	std::vector<int> * stack,
	std::vector<int> * solution,
	int * solution_sum)
{
	if (stack->size() == 4) {
		//vector_dump(*stack);
		int cur_sum = 0;
		for (unsigned int i = 0; i < 4; i++) {
			cur_sum += cost[i][stack->at(i)];
		}
		if (*solution_sum == 0)
			*solution_sum = cur_sum;
		else if (*solution_sum > cur_sum) {
			*solution_sum = cur_sum;
			*solution = *stack;
		}
	} else {
		for (unsigned int i = 0; i < 4; i++) {
			if (i_in_stack(i, *stack)) continue;
			else {
				stack->push_back(i);
				_assign_problem (cost, stack, solution, solution_sum);
				(void) stack->pop_back();
			}
		}
	}
	return;
}

int
assign_problem (
	int cost [4][4],
	std::vector<int> * solution,
	int * solution_sum)
{
	std::vector<int> stack;
	_assign_problem (cost, &stack, solution, solution_sum);
	return 0;
}

int
main (void)
{
	using std::cout;
	using std::endl;
	int cost[4][4] = {
		{9,2,7,8},
		{6,4,3,7},
		{5,8,1,8},
		{7,6,9,4}
	};
	std::vector<int> solution;
	int solution_sum = 0;
	assign_problem (cost, &solution, &solution_sum);
	cout << "dump solution";
	vector_dump (solution);
	cout << " with total cost " << solution_sum << endl;

	return 0;
}
