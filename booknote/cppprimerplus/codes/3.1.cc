#include <iostream>
#include <climits>
#include <cfloat>

using std::cout;
using std::endl;

#define TAB '\t'
#define NEWLINE do {std::cout<<std::endl;} while(0)

int main (void)
{
	cout << "Short size     (" << sizeof(short)  << ")" << TAB
		<< "Short max      (" << SHRT_MAX  << ")" << TAB
		<< "Short min      (" << SHRT_MIN  << ")" << endl;
	NEWLINE;

	cout << "Int size       (" << sizeof(int) << ")" << TAB
		<< "Int max        (" << INT_MAX   << ")" << TAB
		<< "Int min        (" << INT_MIN   << ")" << endl;
	NEWLINE;

	cout << "Long size      (" << sizeof(long) << ")" << TAB
		<< "Long max       (" << LONG_MAX  << ")" << TAB
		<< "Long min       (" << LONG_MIN  << ")" << endl;
	NEWLINE;

	cout << "Long long size (" << sizeof(long long) << ")" << TAB
		<< "Long long max  (" << LLONG_MAX << ")" << TAB
		<< "Long long min  (" << LLONG_MIN << ")" << endl;
	NEWLINE;

	cout << "float size     (" << sizeof(float) << ")" << endl
		<< "min num of significant digits (" << FLT_DIG << ")" << endl
		<< "min exponent value (" << FLT_MIN_10_EXP << endl
		<< "max exponent value (" << FLT_MAX_10_EXP << endl
		<< "min (" << FLT_MIN << endl
		<< "max (" << FLT_MAX << endl;
	NEWLINE;

	cout << "double size    (" << sizeof(double) << ")" << endl
		<< "min num of significant digits (" << DBL_DIG << ")" << endl
		<< "min exponent value (" << DBL_MIN_10_EXP << endl
		<< "max exponent value (" << DBL_MAX_10_EXP << endl
		<< "min (" << DBL_MIN << endl
		<< "max (" << DBL_MAX << endl;
	NEWLINE;

	cout << "long double size (" << sizeof(long double) << ")" << endl
		<< "min num of significant digits (" << LDBL_DIG << ")" << endl
		<< "min exponent value (" << LDBL_MIN_10_EXP << endl
		<< "max exponent value (" << LDBL_MAX_10_EXP << endl
		<< "min (" << LDBL_MIN << endl
		<< "max (" << LDBL_MAX << endl;
	NEWLINE;

	return 0;
}
