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
		int total = 0;
		int num;
		while (infile >> num) {
			total += num;
		}
		cout << total << endl;
	}
	return 0;
}