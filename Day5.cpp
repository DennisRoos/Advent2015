#include <iostream>
#include <fstream>
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <regex>

#include <cmath>

using namespace std;

int main(int argc, char * argv[]) {

	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		int nice1 = 0;
		int nice2 = 0;
		string s;
		while (infile >> s) {
			int vowels = 0;
			bool twice = false;
			bool banned = false;
			bool duplicate = false;
			bool pair = false;
			for (int i = 0; i < s.size() - 1; i++) {
				if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u' || s[i] == 'o') {
					vowels++;
				}
				if (s[i] == s[i + 1]){
					twice = true;
				}
				if ((s[i] == 'a' && s[i + 1] == 'b') || (s[i] == 'c' && s[i + 1] == 'd') || (s[i] == 'p' && s[i + 1] == 'q') || (s[i] == 'x' && s[i + 1] == 'y')) {
					banned = true;
				}
				for (int j = i + 2; j < s.size() - 1; j++) {
					if (s[i] == s[j] && s[i + 1] == s[j + 1]) {
						duplicate = true;
					}
				}

			}
			for (int i = 0; i < s.size() - 2; i++) {
				if (s[i] == s[i + 2]) {
					pair = true;
				}

			}
			if (s[s.size() - 1] == 'a' || s[s.size() - 1] == 'e' || s[s.size() - 1] == 'i' || s[s.size() - 1] == 'u' || s[s.size() - 1] == 'o') {
				vowels++;
			}
			if (vowels >= 3 && twice == true && banned == false) {
				nice1++;
			}
			if (duplicate && pair) {
				nice2++;
			}
		}

		cout << "There were " << nice1 << " nice strings under the first definition." << endl;
		cout << "There were " << nice2 << " nice strings under the second definition." << endl;
	}
	return 0;
}