s#include <iostream>
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

int capacity[4];
int durability[4];
int flavor[4];
int texture[4];
int calories[4];

int best = 0;
int best2 = 0;

int main(int argc, char * argv[])
{
	capacity[0] = 2;
	capacity[1] = 0;
	capacity[2] = 0;
	capacity[3] = 0;
	durability[0] = 0;
	durability[1] = 5;
	durability[2] = 0;
	durability[3] = -1;
	flavor[0] = -2;
	flavor[1] = -3;
	flavor[2] = 5;
	flavor[3] = 0;
	texture[0] = 0;
	texture[1] = 0;
	texture[2] = -1;
	texture[3] = 5;
	calories[0] = 3;
	calories[1] = 3;
	calories[2] = 8;
	calories[3] = 8;

	for (int a = 0; a <= 100; a++) {
		for (int b = a; b <= 100; b++) {
			for (int c = b; c <= 100; c++) {
				int sprinkles = a;
				int butter = b - a;
				int choco = c - b;
				int candy = 100 - c;

				int cap = max(sprinkles*capacity[0] + butter*capacity[1] + choco*capacity[2] + candy*capacity[3],0);
				int dur = max(sprinkles*durability[0] + butter*durability[1] + choco*durability[2] + candy*durability[3], 0);
				int flav = max(sprinkles*flavor[0] + butter*flavor[1] + choco*flavor[2] + candy*flavor[3], 0);
				int tex = max(sprinkles*texture[0] + butter*texture[1] + choco*texture[2] + candy*texture[3], 0);
				int cal = max(sprinkles*calories[0] + butter*calories[1] + choco*calories[2] + candy*calories[3], 0);

				int score = cap * dur * flav * tex;
				if (score > best) {
					best = score;
				}
				if (cal == 500 && score > best2) {
					best2 = score;
				}

			}
		}
	}
	cout << "The best score for part 1 was " << best << endl;
	cout << "The best score for part 2 was " << best2 << endl;
	return 0;
}