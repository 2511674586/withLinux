/**
 * @file insert.cc
 * @brief implement insert sorting
 */

#include <iostream>
#include <vector>
#include "vectorutil.hpp"
#include <cassert>

int debug = 1;

void
insert_sort (std::vector<int> & v)
{
	using namespace std;
	assert(v.size() >= 2);
	for (unsigned int i = 1; i < v.size(); i++) { // handle this number
		if (debug) cout << "iter " << i << endl;
		// select insert location
		unsigned int j = 0;
		while ((j < i) && (v.at(i) > v.at(j))) j++;
		if (debug) cout << "  cursor > " << j << endl;
		// now j is the target location, move i to j
		int tmp = v.at(i);
		v.erase(v.begin()+i);
		v.insert(v.begin()+j, tmp);
		if (debug) vector_dump(v);
	}
	return;
}

int
main (void)
{
	std::vector<int> buf;
	{ // input and dump
		int i;
		while (std::cin >> i) buf.push_back(i);
		vector_dump(buf);
	}
	insert_sort(buf);
	vector_dump(buf);

	return 0;
}
