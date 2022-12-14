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

string lookandsee(string a) {
	string b;
	char c = a[0];
	int count = 1;
	for (int i = 1; i < a.size(); i++) {
		if (a[i] == c) {
			count++;
		}
		else {
			b.append(to_string(count));
			b.push_back(c);
			count = 1;
			c = a[i];
		}
	}
	b.append(to_string(count));
	b.push_back(c);
	return b;
}

int main(int argc, char * argv[]) {
	string a = "1321131112";
	for (int i = 0; i < 40; i++) {
		a = lookandsee(a);
	}
	cout << "The initial result is " << a.size() << endl;
	for (int i = 0; i < 10; i++) {
		a = lookandsee(a);
	}
	cout << "The final result is " << a.size() << endl;
	return 0;
}