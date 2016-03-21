/**
 * @file factorial.cc
 * @brief calculate factorial recursively.
 */
#include <iostream>
using namespace std;

long
factorial (long n)
{
	return (n==0) ? 1 : n*factorial(n-1) ;
}

int
main (void)
{
	cout << factorial(13) << endl;
	return 0;
}
