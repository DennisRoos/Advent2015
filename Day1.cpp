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
		string s;
		bool b = true;
		int floor = 0;
		infile >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				floor++;
			}
			else {
				floor--;
				if (floor == -1 && b) {
					b = false;
					cout << "The first time we reach the basement is on move " << i + 1 << endl;
				}
			}
		}
		cout << "The final floor is " << floor << endl;
	}
	return 0;
}