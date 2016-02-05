#include <iostream>
#include <climits>

using std::cout;
using std::endl;

#define TAB '\t'

int main (void)
{
	cout << "Short size     (" << sizeof(short)  << ")" << TAB
		<< "Short max      (" << SHRT_MAX  << ")" << endl;

	cout << "Int size       (" << sizeof(int) << ")" << TAB
		<< "Int max        (" << INT_MAX   << ")" << endl;

	cout << "Long size      (" << sizeof(long) << ")" << TAB
		<< "Long max       (" << LONG_MAX  << ")" << endl;

	cout << "Long long size (" << sizeof(long long) << ")" << TAB
		<< "Long long max  (" << LLONG_MAX << ")" << endl;

	cout << "float size     (" << sizeof(float) << ")" << TAB << endl;
	cout << "double size    (" << sizeof(double) << ")" << TAB << endl;
	cout << "long double size (" << sizeof(long double) << ")" << TAB << endl;

	return 0;
}
