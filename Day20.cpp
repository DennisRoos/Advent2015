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
	bool b = true;
	static int A[3600000];
	for (int i = 1; i <= 3600000; i++) {
		int j = i;
		for (int k = 0; k < 50; k++) {
			if (j < 3600000) {
				A[j] += i;
				j += i;
			}
		}
	}
	int n = 0;
	while (A[n] < 3272728) {
		n++;
	}
	cout << "Answer is house " << n << endl;
	return 0;
}