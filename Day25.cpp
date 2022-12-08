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
	int row = 3010;
	int column = 3019;
	
	int start = row + column - 1;
	int index = start * (start - 1) / 2;
	index += column;//index of the requested code in the sequence

	cout << "The index is " << index << endl;

	long long code = 20151125;
	for (int i = 1; i < index; i++) {
		code = (code * 252533) % 33554393;
	}
	cout << "The requested code is " << code << endl;
}