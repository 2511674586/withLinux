/**
 * @file bubble_sort.cc
 * @brief implement bubble sorting
 */
#include <iostream>
#include <vector>
#include "vectorutil"

/**
 * @brief implement bubble sort, ascending.
 * @param [std::vector<int> &] buf is the vector to be sorted.
 * @param [int] verbose set 1 to toggle verbose output
 * @return void
 */
void
bubble_sort (std::vector<int> & buf, int verbose = 1)
{
	// bubble sort requires buf.size() - 2 times of loop
	for (unsigned int i = 0; i < buf.size()-2; i++) {
		// push the max numbers to the last one (size()-1-i), gradually
		for (unsigned int j = 0; j < buf.size()-2-i; j++) {
			if (buf[j] > buf[j+1]) {
				// swap
				int tmp = buf[j];
				buf[j] = buf[j+1];
				buf[j+1] = tmp;
			} else {
				continue; // scan the next pair
			}
		}
	}
	return;
}

/**
 * @brief test bubble sort funciton
 */
int
main (void)
{
	std::vector<int> buf;
	{ // input and dump
		int i;
		while (std::cin >> i) buf.push_back(i);
		vector_dump(buf);
	}
	bubble_sort(buf);
	vector_dump(buf);
	return 0;
}
