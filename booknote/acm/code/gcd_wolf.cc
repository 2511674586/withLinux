/**
 * @file gcd_wolf.cc
 * @brief application of gcd.cc, looks for safe caves for the
 * rabbit, who's being chased by a wolf.
 */
#include <iostream>
#include <vector>
#include "vectorutil"

int debug = 1;
using namespace std;

int
main (void)
{
	vector<int> cave;
	vector<int> dirty;
	int caves;
	int mod;
	{// input
		cout << "Caves :";
		cin >> caves;
		cout << "Mod :";
		cin >> mod;
		cout << caves << mod << endl;
	}
	// init
	for (int i = 0; i < caves; i++) {
		cave.push_back(i);
		dirty.push_back(0);
	}
	{// search, and dump
		int cur = 0;
		while (true) {
			if (debug) cout << cur << endl;
			// current cave
			if (0 == dirty.at(cur)) { // not accessed yet
				(void) cave.at(cur); // access cave
				dirty.at(cur) = 1; // set dirty bit
			} else { // accessed
				break; // quit loop
			}
			// next cave
			cur -= mod; // move to next cave
			if (cur < 0) cur += caves; // cursor correction
		}
		vector_dump (cave);
		vector_dump (dirty);
		if (vector_asum(dirty) == caves) {
			cout << "no safe place" << endl;
		} else {
			cout << "exists safe palce" << endl;
		}
	}	
	return 0;
}
