#include <iostream>
#include <cstring>

using namespace std;

int
main (void) 
{
	char charr[20];
	string str;

	cout << "Input line for char charr[20]: " << endl;
	cin.getline (charr, 20);
	cout << "Input line for string str: " << endl;
	getline (cin, str);

	cout << "size of charr: " << strlen(charr) << " " << charr << endl;
	cout << "size of str: " << str.size() << " " << str << endl;
	return 0;
}
