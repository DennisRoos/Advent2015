#include <iostream>
#include <fstream>
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <regex>
#include <cmath>
#include <list>

using namespace std;

vector<int> v;
int minimum[21];
int s;

int counter(int i, int rem, int used) {
	if (i >= s) {
		return 0;
	}
	if (rem - v[i] == 0) {
		minimum[used + 1]++;
		return 1 + counter(i + 1, rem, used);
	}
	int c1 = counter(i+1,rem, used);
	int c2 = 0;
	if (rem - v[i] > 0) {
		c2 = counter(i + 1, rem - v[i], used + 1);
	}
	return c1 + c2;
}

int main(int argc, char * argv[])
{
	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		int n;

		for (int i = 0; i < 20; i++) {
			minimum[i] = 0;
		}

		while (infile >> n) {
			v.push_back(n);
		}
		s = v.size();
		int total = counter(0, 150, 0);
		cout << "The total amount of combinations is " << total << endl;

		int i = 0;
		while (minimum[i] == 0) {
			i++;
		}

		cout << "The amount of ways for the minimum number " << i << " is " << minimum[i] << endl;
	}
	else {
		cout << "can't find file?\n";
	}
	return 0;
}