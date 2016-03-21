/**
 * @file bicomb.cc
 * @brief show all binary combinations
 */
#include <iostream>
#include <vector>
#include "vectorutil"

/**
 * @brief Core function of binary combination
 * @param len is the length of combination
 * @param bcms is the memory stack usded for recursion
 * @return void
 */
void
_binary_combs (unsigned int len, std::vector<int> * bcms)
{
	if (len == bcms->size()) { // reached recursion boundary
		vector_dump (*bcms);
	} else { // enter into next bit
		for (int i = 0; i < 2; i++) {
			bcms->push_back (i);
			_binary_combs (len, bcms);
			(void) bcms->pop_back();
		}
	}
}

/**
 * @brief wrapper for core function of binary combination
 * @param len is the length of combination vector
 */
void
binary_combs (unsigned int len)
{
	std::vector<int> bicombs;
	_binary_combs (len, &bicombs);
	return;
}

/**
 * @brief test the binary combination implementation
 */
int
main (void)
{
	binary_combs (3);
	return 0;
}
