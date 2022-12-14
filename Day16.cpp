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


	int children;
	int cats;
	int samoyeds;
	int pomeranians;
	int akitas;
	int vizslas;
	int goldfish;
	int trees;
	int cars;
	int perfumes;

bool match(string s, int n) {
	if (s.compare("children") == 0) {
		return (children == n);
	}
	if (s.compare("cats") == 0) {
		return (cats == n);
	}
	if (s.compare("samoyeds") == 0) {
		return (samoyeds == n);
	}
	if (s.compare("pomeranians") == 0) {
		return (pomeranians == n);
	}
	if (s.compare("akitas") == 0) {
		return (akitas == n);
	}
	if (s.compare("vizslas") == 0) {
		return (vizslas == n);
	}
	if (s.compare("goldfish") == 0) {
		return (goldfish == n);
	}
	if (s.compare("trees") == 0) {
		return (trees == n);
	}
	if (s.compare("cars") == 0) {
		return (cars == n);
	}
	if (s.compare("perfumes") == 0) {
		return (perfumes == n);
	}
}


bool match2(string s, int n) {
	if (s.compare("children") == 0) {
		return (children == n);
	}
	if (s.compare("cats") == 0) {
		return (cats < n);
	}
	if (s.compare("samoyeds") == 0) {
		return (samoyeds == n);
	}
	if (s.compare("pomeranians") == 0) {
		return (pomeranians > n);
	}
	if (s.compare("akitas") == 0) {
		return (akitas == n);
	}
	if (s.compare("vizslas") == 0) {
		return (vizslas == n);
	}
	if (s.compare("goldfish") == 0) {
		return (goldfish > n);
	}
	if (s.compare("trees") == 0) {
		return (trees < n);
	}
	if (s.compare("cars") == 0) {
		return (cars == n);
	}
	if (s.compare("perfumes") == 0) {
		return (perfumes == n);
	}
}

int main(int argc, char * argv[])
{
	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		string a1;
		string a2;
		string a3;
		int n1;
		int n2;
		int n3;

		int ind;

		children = 3;
		cats = 7;
		samoyeds = 2;
		pomeranians = 3;
		akitas = 0;
		vizslas = 0;
		goldfish = 5;
		trees = 3;
		cars = 2;
		perfumes = 1;

		string s;
		while (getline(infile, s)) {
			stringstream ss(s);
			ss >> a1;
			ss >> ind; 
			ss >> a1;
			ss >> n1;
			ss >> a2;
			ss >> n2;
			ss >> a3;
			ss >> n3;

			bool b1 = match(a1,n1);
			bool b2 = match(a2, n2);
			bool b3 = match(a3, n3);

			if (b1 && b2 && b3) {
				cout << "The correct Sue for part 1 is number " << ind << endl;
			}
			b1 = match2(a1, n1);
			b2 = match2(a2, n2);
			b3 = match2(a3, n3);

			if (b1 && b2 && b3) {
				cout << "The correct Sue for part 2 is number " << ind << endl;
			}
		}
	}
	return 0;
}