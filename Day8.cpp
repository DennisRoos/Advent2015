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
		int total1 = 0;
		int total2 = 0;
		while (infile >> s) {
			int lit = s.size();
			int encoded = 0;
			for (int i = 0; i < lit; i++) {
				if (s[i] == '\\') {
					if (s[i + 1] == 'x') {
						encoded++;
						i += 3;
					}
					else {
						encoded++;
						i++;
					}
				}
				else {
					encoded++;
				}
			}
			encoded -= 2;
			total1 += lit - encoded;

			int code = 2;
			for (int i = 0; i < lit; i++) {
				if (s[i] == '"' || s[i] == '\\') {
					code += 1;
				}
				code += 1;
			}
			total2 += code - lit;
		}
		cout << "The difference for part 1 is " << total1 << endl;
		cout << "The difference for part 2 is " << total2 << endl;
	}
	return 0;
}