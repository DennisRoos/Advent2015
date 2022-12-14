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

struct reindeer {
	int speed;
	int time;
	int rest;
	bool running;
	int count;
	int distance;
	int score;
	reindeer(int s, int t, int r) : speed(s), time(t), rest(r), running(true), count(t), distance(0), score(0) {};
};

vector<reindeer> v;
int best;
int finalTime;

int main(int argc, char * argv[]) {

	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		string s;
		finalTime = 2503;
		int sp;
		int t;
		int r;
		while (infile >> s) {
			infile >> s;
			infile >> s;
			infile >> sp;
			infile >> s;
			infile >> s;
			infile >> t;

			infile >> s;
			infile >> s;
			infile >> s;
			infile >> s;
			infile >> s;
			infile >> s;

			infile >> r;

			infile >> s;
			reindeer rein = reindeer(sp, t, r);
			v.push_back(rein);
		}

		for (int i = 0; i < v.size(); i++) {
			int dist = 0;
			int time = 0;
			bool b = true;
			while (b) {
				if (time + v[i].time > finalTime) {
					b = false;
					if (time < finalTime) {
						dist += (finalTime - time) * v[i].speed;
					}
				}
				else {
					dist += v[i].time * v[i].speed;
					time += v[i].time + v[i].rest;
				}
			}
			if (dist > best) {
				best = dist;
			}
		}
		cout << "Best distance is " << best << endl;

		//Part 2

		for (int i = 0; i < 2503; i++) {
			int dist = 0;
			for (int j = 0; j < v.size(); j++) {
				v[j].count--;
				if (v[j].running) {
					v[j].distance += v[j].speed;
					if (v[j].count == 0) {
						v[j].running = false;
						v[j].count = v[j].rest;
					}
				}
				else {
					if (v[j].count == 0) {
						v[j].running = true;
						v[j].count = v[j].time;
					}
				}
				if (v[j].distance > dist) {
					dist = v[j].distance;
				}
			}
			for (int j = 0; j < v.size(); j++) {
				if (v[j].distance == dist) {
					v[j].score++;
				}
			}
		}
		int highestScore = 0;

		for (int j = 0; j < v.size(); j++) {
			if (v[j].score > highestScore) {
				highestScore = v[j].score;
			}
		}

		cout << "The highest score was " << highestScore << endl;

	}
	return 0;
}