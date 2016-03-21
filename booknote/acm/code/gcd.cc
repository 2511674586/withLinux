/**
 * @file gcd.cc
 * @brief calculate the great common divisor of two numbers, recursively.
 */
#include <iostream>
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
	cout << gcd (153, 123) << endl;
	cout << gcd (123, 153) << endl;
	return 0;
}
