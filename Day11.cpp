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

string increment(string a) {
	int i = a.size() - 1;
	while (a[i] == 'z') {
		a[i] = 'a';
		i--;
	}
	a[i]++;
	if (a[i] == 'i' || a[i] == 'o' || a[i] == 'l') {
		a[i]++;
	}
	return a;
}

int main(int argc, char * argv[]) {
	string a = "vzbxkghb";
	int b = 0;
	while (b < 2) {
		a = increment(a);
		//cout << a << endl;
		bool straight = false;
		int couple = 0;
		for (int i = 0; i < a.size() - 2; i++) {
			if (a[i] == a[i + 1] - 1 && a[i] == a[i + 2] - 2) {
				straight = true;
			}
		}
		if (straight) {
			for (int i = 0; i < a.size() - 1; i++) {
				if (a[i] == a[i + 1]) {
					couple++;
					i++;
				}
			}
			if (couple >= 2) {
				cout << "The new password is " << a << endl;
				b++;
			}
		}
	}
}