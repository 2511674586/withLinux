/**
 * @file selective_sort.cc
 * @brief implements selective sorting
 */
#include <iostream>
#include <vector>
#include "vectorutil"

/**
 * @brief implement selective sort, ascending.
 * @param [std::vector<int>] buf the vector to be sorted.
 * @param [int] verbose set to 1 to toggle verbose mode, 0 to disable.
 *   its default is 1 if omitted.
 * @return void
 */
void
selective_sort (std::vector<int> &buf, int verbose = 1)
{
	// selective sort requires looping for buf.size() - 1 times
	for (unsigned int i = 0; i < buf.size() - 1; i++) {
		// search for min value from i-th to the end
		int min = buf[i];
		unsigned int min_cur = i;
		if (verbose) std::cout << "iter " << i << std::endl;
		for (unsigned int j = i; j < buf.size(); j++) {
			if (buf[j] < min) {
				// update min value and cursor
				min = buf[j];
				min_cur = j;
			} else {
				continue;
			}
		}
		// swap the min value with i-th item
		if (verbose) std::cout << "min cursor at: "
		   	<< min_cur << " value: " << min << std::endl;
		int tmp = buf[i];
		buf[i] = buf[min_cur];
		buf[min_cur] = tmp;
		if (verbose) vector_dump (buf);
	}
	return;
}

/** 
 * @brief test selective sort
 */
int
main (void)
{
	std::vector<int> buf;
	{ // input sequence and dump
		int i;
		while (std::cin >> i) buf.push_back(i);
		vector_dump(buf);
	}
	selective_sort (buf);
	vector_dump(buf);

	return 0;
}
