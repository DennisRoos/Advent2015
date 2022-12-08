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
		int a;
		int b;
		int c;
		int total = 0;
		int totalribbon = 0;
		while (infile >> a) {
			infile >> b;
			infile >> c;
			if (a > c) {
				int t = a;
				a = c;
				c = t;
			}
			if (b > c) {
				int t = b;
				b = c;
				c = t;
			}
			int package = 2 * (a*b + b*c + a*c) + a*b;
			total += package;
			int ribbon = 2 * (a + b) + a*b*c;
			totalribbon += ribbon;
		}

		cout << "The total required amount of wrapping paper is " << total << " square feet." << endl;
		cout << "The total required amount of ribbon is " << totalribbon << "  feet." << endl;
		
	}
	return 0;
}