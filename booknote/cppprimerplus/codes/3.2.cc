#include <iostream>

using namespace std;

int
main (void)
{
	int x {64};
	cout << "decimal " << x << endl;
	cout << hex; // manipulator for changing number base
	cout << "hexadecimal " << x << endl;
	cout << oct;
	cout << "octal " << x << endl;

	return 0;
}
