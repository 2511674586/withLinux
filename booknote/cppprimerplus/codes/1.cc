#include <iostream>

using namespace std; // lazy approach, all names available, but may introduce issue.


// It is recommended :
// using std::cout; // make cout available
// using std::cin;
// using std::endl;

int main (void)
{
	double x;
	cout << "hello, type a numner:" << endl;
	cin >> x;
	cout << "the number is " << x << endl;
	return 0;
}
