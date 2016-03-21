/**
 * @file str_match.cc
 * @brief string matching
 */
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief implement brute force string matching
 * @param [std::string] text, original text to be searched
 * @param [std::string] needle
 * @return [int] the first place that needle appears, -1 on error.
 */
int
str_match (std::string text, std::string needle)
{
	// loop time is text.size()-needle.size()+1
	for (unsigned int i = 0; i < text.size()-needle.size()+1; i++) {
		// from current char, match needle
		for (unsigned int j = 0; j < needle.size(); j++) {
			if (text[i+j] == needle[j]) { // match
				if (j == needle.size()-1) return i; // the last one still matchs
			}
		}
	}
	return -1;
}

/**
 * @brief test brute force string matching
 */
int
main (void)
{
	string text;
	string needle;
	cout << "Text: "; cin >> text;
	cout << "needle: "; cin >> needle;
	cout << endl;
	cout << "location " << str_match(text, needle) << endl;
	return 0;
}
