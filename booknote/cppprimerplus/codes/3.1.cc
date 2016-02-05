#include <iostream>
#include <climits>

using std::cout;
using std::endl;

#define TAB '\t'

int main (void)
{
	cout << "Short size     (" << sizeof(short)  << ")" << TAB
		<< "Short max      (" << SHRT_MAX  << ")" << TAB
		<< "Short min      (" << SHRT_MIN  << ")" << endl;

	cout << "Int size       (" << sizeof(int) << ")" << TAB
		<< "Int max        (" << INT_MAX   << ")" << TAB
		<< "Int min        (" << INT_MIN   << ")" << endl;

	cout << "Long size      (" << sizeof(long) << ")" << TAB
		<< "Long max       (" << LONG_MAX  << ")" << TAB
		<< "Long min       (" << LONG_MIN  << ")" << endl;

	cout << "Long long size (" << sizeof(long long) << ")" << TAB
		<< "Long long max  (" << LLONG_MAX << ")" << TAB
		<< "Long long min  (" << LLONG_MIN << ")" << endl;

	cout << "float size     (" << sizeof(float) << ")" << TAB << endl;
	cout << "double size    (" << sizeof(double) << ")" << TAB << endl;
	cout << "long double size (" << sizeof(long double) << ")" << TAB << endl;

	return 0;
}
