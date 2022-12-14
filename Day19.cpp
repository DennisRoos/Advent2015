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

struct rule {
	char in;
	string out;
	rule(char i, string o): in(i), out(o){}
};

vector<rule> v;
vector<string> results;

int main(int argc, char * argv[])
{
	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		string c;//calibration molecule
		infile >> c;
		char p;
		string temp;
		string r;
		while (infile >> p) {
			infile >> temp;
			infile >> r;
			rule ru = rule(p, r);
			v.push_back(ru);
		}

		for (int i = 0; i < c.size(); i++) {
			char d = c[i];
			for (int j = 0; j < v.size(); j++) {
				if (d == v[j].in) {
					string s;
					s.assign(c);
					s.replace(i, 1, v[j].out);
					bool b = true;
					for (int k = 0; k < results.size(); k++) {
						if (s.compare(results[k]) == 0) {
							b = false;
							break;
						}
					}
					if (b) {
						results.push_back(s);
					}
				}
			}
		}

		cout << "There were " << results.size() << " resulting molecules" << endl;
	}
	else {
		cout << "can't find file?\n";
	}
	return 0;
}


/*
Al -> A
Ca -> D
Mg -> M
Si -> S
Ar -> R
Rn -> L
Th -> T
Ti -> I
*/