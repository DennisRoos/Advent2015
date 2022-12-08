// Day18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <regex>
#include <cmath>
#include <iterator>         // std::(istream_iterator, back_inserter)
#include <sstream>          // std::(istringstream)
#include <list>

using namespace std;

int A[102][102];
int B[102][102];


int main(int argc, char * argv[])
{
	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		string s;

		for (int a = 0; a < 102; a++) {
			for (int b = 0; b < 102; b++) {
				A[a][b] = 0;
			}
		}
		int k = 1;
		while (getline(infile, s)) {
			for (int j = 1; j <= 100; j++) {
				if (s[j - 1] == '#') {
					A[k][j] = 1;
				}
			}
			k++;
		}
		for (int steps = 0; steps < 100; steps++) {
			for (int i = 1; i <= 100; i++) {
				for (int j = 1; j <= 100; j++) {

					int count = A[i - 1][j - 1] + A[i - 1][j] + A[i - 1][j + 1] + A[i][j - 1] + A[i][j + 1] + A[i + 1][j - 1] + A[i + 1][j] + A[i + 1][j + 1];
					if (A[i][j] == 0) {
						if (count == 3) {
							B[i][j] = 1;
						}
						else {
							B[i][j] = 0;
						}
					}
					else {
						if (count == 2 || count == 3) {
							B[i][j] = 1;
						}
						else {
							B[i][j] = 0;
						}

					}
				}
			}

			for (int i = 1; i <= 100; i++) {
				for (int j = 1; j <= 100; j++) {
					A[i][j] = B[i][j];
				}
			}
			A[1][1] = 1;
			A[1][100] = 1;
			A[100][1] = 1;
			A[100][100] = 1;
		}
		int count = 0;

		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				count += A[i][j];
			}
		}
		cout << "Total lights on is " << count << endl;
	}
	else {
		cout << "can't find file?\n";
	}
	return 0;
}

