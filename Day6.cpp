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

int A[1000][1000];




int main(int argc, char * argv[]) {

	regex re1("turn on ([\\d]+),([\\d]+) through ([\\d]+),([\\d]+)");
	regex re2("turn off ([\\d]+),([\\d]+) through ([\\d]+),([\\d]+)");
	regex re3("toggle ([\\d]+),([\\d]+) through ([\\d]+),([\\d]+)");
	string s;
	smatch match;
	ifstream f("data.txt");
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			A[i][j] = false;
		}
	}

	while (getline(f, s)) {
		if (regex_search(s, match, re1) == true) {
			int x1 = stoi(match.str(1));
			int y1 = stoi(match.str(2));
			int x2 = stoi(match.str(3));
			int y2 = stoi(match.str(4));
			for (int x = x1; x <= x2; x++) {
				for (int y = y1; y <= y2; y++) {
					A[x][y]++;
				}
			}
		}
		else if (regex_search(s, match, re2) == true) {
			int x1 = stoi(match.str(1));
			int y1 = stoi(match.str(2));
			int x2 = stoi(match.str(3));
			int y2 = stoi(match.str(4));
			for (int x = x1; x <= x2; x++) {
				for (int y = y1; y <= y2; y++) {
					A[x][y]--;
					if (A[x][y] < 0) {
						A[x][y] = 0;
					}
				}
			}
		}
		else if (regex_search(s, match, re3) == true) {
			int x1 = stoi(match.str(1));
			int y1 = stoi(match.str(2));
			int x2 = stoi(match.str(3));
			int y2 = stoi(match.str(4));
			for (int x = x1; x <= x2; x++) {
				for (int y = y1; y <= y2; y++) {
					A[x][y] += 2;
				}
			}
		}
	}

	int total = 0;

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			total += A[i][j];
		}
	}

	cout << total << " lamps are turned on.\n";
	return 0;
}