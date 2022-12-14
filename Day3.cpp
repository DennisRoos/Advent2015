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
		int x = 250;
		int y = 250;
		int rx = 250;
		int ry = 250;
		int A[500][500];
		for (int i = 0; i < 500; i++) {
			for (int j = 0; j < 500; j++) {
				A[i][j] = 0;
			}
		}
		A[250][250] = 1;
		string s;
		infile >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '>') {
				x++;
			}
			else if (s[i] == '<') {
				x--;
			}
			else if (s[i] == 'v') {
				y++;
			}
			else if (s[i] == '^') {
				y--;
			}
			A[x][y]++;
			i++;
			if (s[i] == '>') {
				rx++;
			}
			else if (s[i] == '<') {
				rx--;
			}
			else if (s[i] == 'v') {
				ry++;
			}
			else if (s[i] == '^') {
				ry--;
			}
			A[rx][ry]++;
		}

		int total = 0;
		for (int i = 0; i < 500; i++) {
			for (int j = 0; j < 500; j++) {
				if (A[i][j] > 0) {
					total++;
				}
			}
		}
		cout << total << " houses got presents" << endl;
	}
	return 0;
}