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

int D[8][8];
int Dist[9][9];
int bestResult;

int main(int argc, char * argv[]) {

	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		bestResult = -1;
		string s;
		int n;
		for (int i = 0; i < 8; i++) {
			int k = 0;
			for (int j = 0; j < 7; j++) {
				if (j == i) {
					k++;
				}
				infile >> s;
				infile >> s;
				infile >> s;
				infile >> n;
				if (s.compare("gain") == 0) {
					D[i][k] = n;
				}
				else {
					D[i][k] = -n;
				}
				cout << i << ", " << k << ": " << D[i][k] << endl;
				k++;
				infile >> s;
				infile >> s;
				infile >> s;
				infile >> s;
				infile >> s;
				infile >> s;
				infile >> s;
			}
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++){
				Dist[i][j] = D[i][j] + D[j][i];
			}
		}

		for (int i = 0; i < 9; i++) {
			Dist[i][8] = 0;
			Dist[8][i] = 0;
		}

		string p = "012345678";
		while (p.compare("876543210") != 0) {
			int result = 0;
			//cout << p << endl;
			for (int i = 0; i < 8; i++) {
				int a = p[i] - '0';
				int b = p[i + 1] - '0';
				result += Dist[a][b];
			}
			int a = p[0] - '0';
			int b = p[8] - '0';
			result += Dist[a][b];
			if (result > bestResult) {
				bestResult = result;
			}
			next_permutation(p.begin(), p.end());
		}

		cout << "Best result is " << bestResult << endl;

	}
	return 0;
}