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

int regs[2];
int ic;
enum operation{hlf,tpl,inc,jmp,jie,jio};

struct instruction {
	operation op;
	int reg;
	int offset;
	instruction(operation o, int r, int of) :op(o), reg(r), offset(of) {}
};

vector<instruction> prog;

int main(int argc, char * argv[])
{
	ic = 0;
	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{

		string s;

		regs[0] = 1;//value of register a
		regs[1] = 0;

		while (infile >> s) {
			operation op;
			int reg = 0;
			int offset = 0;
			if (s.compare("hlf") == 0) {
				op = hlf;
				char c;
				infile >> c;
				reg = c - 'a';
			}
			else if (s.compare("tpl") == 0) {
				op = tpl;
				char c;
				infile >> c;
				reg = c - 'a';
			}
			else if (s.compare("inc") == 0) {
				op = inc;
				char c;
				infile >> c;
				reg = c - 'a';
			}
			else if (s.compare("jmp") == 0) {
				op = jmp;
				infile >> offset;
			}
			else if (s.compare("jio") == 0) {
				op = jio;
				char c;
				infile >> c;
				reg = c - 'a';
				infile >> offset;
			}
			else if (s.compare("jie") == 0) {
				op = jie;
				char c;
				infile >> c;
				reg = c - 'a';
				infile >> offset;
			}
			instruction ins = instruction(op, reg, offset);
			prog.push_back(ins);
		}

		int size = prog.size();
		while (ic < size && ic >= 0) {
			if (prog[ic].op == hlf) {
				regs[prog[ic].reg] = regs[prog[ic].reg] / 2;
			}
			else if (prog[ic].op == tpl) {
				regs[prog[ic].reg] = regs[prog[ic].reg] * 3;
			}
			else if (prog[ic].op == inc) {
				regs[prog[ic].reg]++;
			}
			else if (prog[ic].op == jmp) {
				ic += prog[ic].offset - 1;
			}
			else if (prog[ic].op == jie) {
				if (regs[prog[ic].reg] % 2 == 0) {
					ic += prog[ic].offset - 1;
				}
			}
			else if (prog[ic].op == jio) {
				if (regs[prog[ic].reg] == 1) {
					ic += prog[ic].offset - 1;
				}
			}
			ic++;
		}
		cout << "The result is " << regs[1] << endl;

	}
	else {
		cout << "can't find file?\n";
	}
	return 0;
}