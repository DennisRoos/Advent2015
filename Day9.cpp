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

int Dist[8][8];
bool G[8];

int shortestPath;
int longestPath;

void find(int cur, int d, int amount) {
	if (amount == 8) {
		if (d < shortestPath) {
			shortestPath = d;
			return;
		}
		if (d > longestPath) {
			longestPath = d;
			return;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (G[i] == false) {
			G[i] = true;
			find(i, d + Dist[cur][i], amount + 1);
			G[i] = false;
		}
	}
	return;
}

int main(int argc, char * argv[]) {

	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		shortestPath = 999999;
		longestPath = -1;
		int nice1 = 0;
		int nice2 = 0;
		string s;
		int n;
		for(int i = 0; i < 7; i++){
			for (int j = i + 1; j < 8; j++) {
				infile >> s;
				infile >> s;
				infile >> s;
				infile >> s;
				infile >> n;
				Dist[i][j] = n;
				Dist[j][i] = n;
				cout << i << "," << j << ": " << n << endl;
			}
		}

		for (int i = 0; i < 8; i++) {
			G[i] = false;
		}

		for (int i = 0; i < 8; i++) {
			G[i] = true;
			find(i, 0, 1);
			G[i] = false;
		}

		cout << "Shortest path is length " << shortestPath << endl;
		cout << "Longest path is length " << longestPath << endl;
	}
	return 0;
}