#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int
main (void)
{
	string buffer;
	ofstream outfile;

	cout << "Opening file ..." << endl;
	outfile.open ("temp.temp");
	cout << "Input your message ..." << endl;
	//cin >> buffer; // will break at space.
	getline (cin, buffer);
	cout << "Input size (" << buffer.size() << ")" << endl;

	outfile << buffer;
	outfile.close ();

	return 0;
}
