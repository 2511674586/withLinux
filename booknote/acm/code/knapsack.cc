/**
 * @file knapsack.cc
 * @brief solves knapsack problem with brute force
 */
#include <iostream>
#include <vector>
#include "vectorutil"

/**
 * @brief Core function for KP implementation, recursive.
 */
void
kp_binary_combs (
	std::vector<int> weight,
	std::vector<int> value,
	int w_max,
   	std::vector<int> * bcms, // bcms is stack
	std::vector<int> * solution,
	int * solution_sum)
{
	unsigned int len = weight.size();
	if (len == bcms->size()) { // reached recursion boundary
		// vector_dump (*bcms); don't dump current combination
		int cur_weight = vector_dot(weight, *bcms);
		if (cur_weight < w_max) { // not exceed max weight
			int cur_value  = vector_dot(value, *bcms);
			if (cur_value > *solution_sum) { // better income
				*solution = *bcms;
				*solution_sum = cur_value;
			}
		}
	} else { // enter into next bit
		for (int i = 0; i < 2; i++) {
			bcms->push_back (i);
			kp_binary_combs (weight, value, w_max, bcms, solution, solution_sum);
			(void) bcms->pop_back();
		}
	}
}

/**
 * @brief KP problem wrapper
 */
void
knapsack_problem (
	std::vector<int> weight,
	std::vector<int> value,
	int w_max,
	std::vector<int> * solution,
	int * solution_sum)
{
	if (weight.size() != value.size()) {
		std::cout << "E: knapsack_problem: w and v size mismatch!\n";
		return;
	}
	std::vector<int> bicombs;
	kp_binary_combs (weight, value, w_max, &bicombs, solution, solution_sum);
	return;
}

/**
 * @brief test knapsack implementation, uses brute force 
 */
int
main (void)
{
	using std::cout;
	using std::endl;
	std::vector<int> weight {7,3,4,5};
	std::vector<int> value {42,12,40,25};
	int w_max = 10;
	std::vector<int> solution;
	int solution_sum = 0;
	knapsack_problem (weight, value, w_max, &solution, &solution_sum);
	cout << "dump solution";
	vector_dump (solution);
	cout << " with total value " << solution_sum << endl;
	return 0;
}
