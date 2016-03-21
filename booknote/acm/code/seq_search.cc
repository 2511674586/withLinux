/**
 * @file seq_search.cc
 * @brief implement sequencial searching
 */
#include <iostream>
#include <vector>
#include "vectorutil"

/**
 * @brief implement sequential search
 * @param [std::vector<int> &] buf, search in this vector
 * @param [int] key, search key
 * @param [int] verbose
 * @return [int] the first index that the key emerges, -1 on nothing found.
 */
int
seq_search (std::vector<int> & buf, int key, int verbose = 1)
{
	int ret = -1;
	for (unsigned int i = 0; i < buf.size(); i++) {
		if (verbose) std::cout << "check " << i << std::endl;
		if (buf[i] == key) {
			ret = i;
			break;
		}
	}
	return ret;
}

/**
 * @brief test sequential search
 */
int
main (int argc, char ** argv)
{
	std::vector<int> buf;
	{ // input and dump
		int i;
		while (std::cin >> i) buf.push_back(i);
		vector_dump(buf);
	}
	{ // interactively trigger seq search
		int key = 91;
		int index = -1;
		std::cout << "Key: " << key << std::endl;
		index = seq_search(buf, key);
		std::cout << "Index: " << index << std::endl;
	}
	return 0;
}
