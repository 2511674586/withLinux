/**
 * @file coin1.cc
 * @brief a row of coins @f[ (c_1, c_2, ..., c_n), c_i \in Z^+ @f]
 *  select some coins, and your selections cannot touch each other.
 *  maximize the total value of your selected coins, tell the selection.
 */

#include <iostream>
#include <vector>
#include "vectorutil.hpp"

/**
 * @brief maximum coin selection, in iteration
 */
int
maxcoinsel_iter (std::vector<int> coins)
{
	std::vector<int> res; // result by step
	res.push_back(0); // res[0] == 0
	res.push_back(coins[1]); // res[1] == C_1
	for (unsigned int i = 2; i < coins.size(); i++) {
		int s1 = coins[i] + res[i-2];
		int s2 = res[i-1];
		res.push_back( (s1>s2)?(s1):(s2) );
	}
	vector_dump(res);
	return res.back();
}

/**
 * @brief maximum coin selection, in recursion
 */
int
maxcoinsel_recur (std::vector<int> co, unsigned int remain, std::vector<int> & sel)
{
	if (remain == 0) { // boundary 1
		return 0;
	} else if (remain == 1) { // boundary 2
		return co[1];
	} else { // not yet
		int s1 = co[remain] + maxcoinsel_recur(co, remain-2, sel);
		int s2 = co[remain-1];
		if (s1>s2) { // set selection bit
			sel[remain] = 1;
			sel[remain-1] = 0;
		} else {
			sel[remain] = 0;
			sel[remain-1] = 1;
		}
		return (s1>s2)?s1:s2;
	}
}

/**
 * @brief tester for coin1
 */
int
main (void)
{
	using namespace std;

	// prepare coins
	std::vector<int> coins;
	coins.push_back(0);  // null coin, C_0
	coins.push_back(5);
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(10);
	coins.push_back(6);
	coins.push_back(2);
	std::vector<int> sel;
	for (int i = 0; i < 7; i++)
		sel.push_back(0);

	cout << maxcoinsel_iter(coins) << endl;
	cout << maxcoinsel_recur(coins, 6, sel) << endl;
	vector_dump(sel);

	return 0;
}
