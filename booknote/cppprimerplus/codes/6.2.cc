#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int
main (void)
{
	string buffer;
	ifstream infile;
	cout << "Reading temp.temp ..." << endl;
	infile.open ("temp.temp");
	if (!infile.is_open()) {
		cout << "Error openning file" << endl;
		exit (EXIT_FAILURE);
	}
	while (infile.good()) {
		infile >> buffer;
		cout << buffer;
	}
	if (infile.eof())
		cout << "I: End due to EOF" << endl;
	else if (infile.fail())
		cout << "E: Fail reading file" << endl;
	else
		cout << "W: abort" << endl;
	infile.close();
	return 0;
}
