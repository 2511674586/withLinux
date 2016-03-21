/**
 * @file gcd_wolf2.cc
 * @brief application of gcd.cc, looks for safe caves for the
 * rabbit, who's being chased by a wolf. version 2
 */
#include <iostream>
#include <vector>
#include "vectorutil"

int debug = 1;
using namespace std;

template <typename DType> DType
gcd (DType a, DType b) // a > b
{
	// find greatest common divisor
	int big = (a>b) ? a : b;
	int small = (a>b) ? b : a;
	if (big % small == 0)
		return small;
	else
		return gcd<DType> (small, big % small);
}

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
		if (gcd(caves, mod) == 1) {
			cout << "no safe place" << endl;
			return 0;
		} else {
			cout << "exists safe palce, dangerous caves:" << endl;
			for (int j = 0; j < caves; j+=mod) {
				cout << j << " ";
			}
		}
	}	
}
