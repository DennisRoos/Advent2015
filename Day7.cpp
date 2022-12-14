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

vector<string> instructions;


struct entry {
	string name;
	unsigned int value;
	entry(string n, unsigned int v) : name(n), value(v) {}
};

vector<entry> e;

enum operation {TEMP, LSHIFT, RSHIFT, AND, OR, NOT, ASSIGN};

struct finder {
	string name;
	string o1;
	string o2;
	operation op;
	int num;
	finder(string n, string s1, string s2, operation o, int nu): name(n),o1(s1),o2(s2),op(o), num(nu){}
};

vector<finder> finders;


int find(string n) {
	for (int i = 0; i < e.size(); i++) {
		if (n.compare(e[i].name) == 0) {
			return e[i].value;
		}
	}
	int j = -1;
	unsigned int v = 999999999;
	for (int i = 0; i < finders.size(); i++) {
		if (n.compare(finders[i].name) == 0) {
			j = i;
		}
	}
	if (finders[j].op == LSHIFT) {
		unsigned int x = find(finders[j].o1);
		v = (x<<finders[j].num) % 65536;
		entry ent = entry(n, v);
		e.push_back(ent);
	}
	else if (finders[j].op == RSHIFT) {
		unsigned int x = find(finders[j].o1);
		v = (x >> finders[j].num) % 65536;
		entry ent = entry(n, v);
		e.push_back(ent);
	}
	else if (finders[j].op == NOT) {
		unsigned int x = find(finders[j].o1);
		v = (~x) % 65536;
		entry ent = entry(n, v);
		e.push_back(ent);
	}
	else if (finders[j].op == AND) {
		unsigned int x = find(finders[j].o1);
		unsigned int y = find(finders[j].o2);
		v = (x & y) % 65536;
		entry ent = entry(n, v);
		e.push_back(ent);
	}
	else if (finders[j].op == OR) {
		unsigned int x = find(finders[j].o1);
		unsigned int y = find(finders[j].o2);
		v = (x | y) % 65536;
		entry ent = entry(n, v);
		e.push_back(ent);
	}
	else if (finders[j].op == ASSIGN) {
		v = find(finders[j].o1);
		entry ent = entry(n, v);
		e.push_back(ent);
	}
	return v;
}




int main(int argc, char * argv[]) {

	regex re1("([\\d]+) -> ([a-z]+)");
	regex re2("([a-z]+) LSHIFT ([\\d]+) -> ([a-z]+)");
	regex re3("([a-z]+) RSHIFT ([\\d]+) -> ([a-z]+)");
	regex re4("NOT ([a-z]+) -> ([a-z]+)");
	regex re5("(.+) AND ([a-z]+) -> ([a-z]+)");
	regex re6("([a-z]+) OR ([a-z]+) -> ([a-z]+)");
	regex re7("([a-z]+) -> ([a-z]+)");
	string s;
	smatch match;
	ifstream f("data.txt");

	while (getline(f, s)) {
		if (regex_search(s, match, re2) == true) {
			operation op = LSHIFT;
			string s2 = match.str(1);
			int x = stoi(match.str(2));
			string t = match.str(3);
			finder fi = finder(t, s2, "", op,x);
			finders.push_back(fi);
		}
		else if (regex_search(s, match, re3) == true) {
			operation op = RSHIFT;
			string s2 = match.str(1);
			int x = stoi(match.str(2));
			string t = match.str(3);
			finder fi = finder(t, s2, "", op, x);
			finders.push_back(fi);
		}
		else if (regex_search(s, match, re1) == true) {
			int x1 = stoi(match.str(1));
			string target = match.str(2);
			entry ent = entry(target, x1);
			e.push_back(ent);
		}
		else if (regex_search(s, match, re4) == true) {
			operation op = NOT;
			string s1 = match.str(1);
			string t = match.str(2);
			finder fi = finder(t, s1, "", op, 0);
			finders.push_back(fi);
		}
		else if (regex_search(s, match, re5) == true) {
			operation op = AND;
			string s1 = match.str(1);
			string s2 = match.str(2);
			string t = match.str(3);
			finder fi = finder(t, s1, s2, op, 0);
			finders.push_back(fi);
		}
		else if (regex_search(s, match, re6) == true) {
			operation op = OR;
			string s1 = match.str(1);
			string s2 = match.str(2);
			string t = match.str(3);
			finder fi = finder(t, s1, s2, op, 0);
			finders.push_back(fi);
		}
		else if (regex_search(s, match, re7) == true) {
			operation op = ASSIGN;
			string s1 = match.str(1);
			string t = match.str(2);
			finder fi = finder(t, s1, "", op, 0);
			finders.push_back(fi);
		}
	}
	unsigned int temp = 1;
	entry en = entry("1",temp);
	e.push_back(en);

	cout << "Done with reading in stuff\n";
	
	//delete these lines to get part 1
	for (int i = 0; i < e.size(); i++) {
		if (e[i].name.compare("b") == 0) {
			e[i].value = 16076;
		}
	}

	cout << "The charge on wire a is " << find("a") << endl;

	return 0;
}