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
vector<int> b;
long long minimum[31];
int s;
int total;
int part;
int bestminimum;

void counter(int i, int rem, int used) {
	if (i >= s) {
		return;
	}
	if (rem - v[i] == 0) {
		b[i] = 1;
		long long quantum = 1;
		for (int k = 0; k < b.size(); k++) {
			if (b[k] == 1) {
				quantum = quantum * v[k];
			}
		}
		if (bestminimum > used) {
			bestminimum = used;
		}
		if (minimum[used] > quantum) {
			minimum[used] = quantum;
		}

		b[i] = -1;
		return;
	}
	if (used > bestminimum) {
		return;
	}
	counter(i + 1, rem, used);
	if (rem - v[i] > 0) {
		b[i] = 1;
		counter(i + 1, rem - v[i], used + 1);
		b[i] = -1;
	}
	return;
}

int main(int argc, char * argv[])
{
	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		int n;

		for (int i = 0; i < 30; i++) {
			minimum[i] = 9999999999999;
		}
		total = 0;
		while (infile >> n) {
			b.push_back(-1);
			v.push_back(n);
			total += n;
		}
		part = total / 4;//change to 3 for part 1
		s = v.size();
		bestminimum = 999;
		counter(0, part, 1);

		int i = 0;
		while (minimum[i] == 9999999999999) {
			i++;
		}

		cout << "The best quantum entanglement is with " << i << " presents, and it is " << minimum[i] << endl;
	}
	else {
		cout << "can't find file?\n";
	}
	return 0;
}