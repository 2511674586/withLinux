/**
 * @file delete_number.cc
 * @brief delete N number characters within a number, and the resulting number
 * becomes the mininum among all possibilities.
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int
main (void)
{
	vector<int> buf;
	int i = 0; // buffer
	int n = 0; // number of string
	int s = 0; // how many to delete

	{ // input
		cout << "Input number: ";
		while ((i = getchar()) != EOF) {
			if (i == '\r') break;
			if (i == '\n') break;
			buf.push_back(i-'0');
			n++;
		}
		cout << "how many to delete? ";
		cin >> s;
	}
	{ // dump
		cout << "string: ";
		for (unsigned int j = 0; j < buf.size(); j++) {
			cout << buf[j];
		}
		cout << " ";
		cout << "length " << n << " ";
		cout << "delete " << s << " ";
		cout << endl;
	}
	{ // delete
		for (int t = 0; t < s; t++) { // the t time of deletion
			for (unsigned int cur = 0; cur < buf.size(); cur++) { // move cursor
				int next = buf[cur+1];
				if (buf[cur] > next) {
					cout << "delete " << buf[cur] << " at " << cur+1 << endl;
					buf.erase(buf.begin() + cur);
					break;
				}
				if (cur == buf.size()-1) {
					cout << "delete " << buf[buf.size()] << " at " << cur+1 << endl;
					(void) buf.pop_back();
				}
			}
		}
		while (buf[0] == 0)
			buf.erase(buf.begin());
	}
	{ // dump
		cout << "result string: ";
		for (unsigned int j = 0; j < buf.size(); j++) {
			cout << buf[j];
		}
		cout << endl;
	}

	return 0;
}
