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

struct weapon {
	int cost;
	int damage;
	weapon(int c, int d): cost(c), damage(d){}
};

struct armor {
	int cost;
	int defense;
	armor(int c, int d) : cost(c), defense(d) {}
};

struct ring {
	int cost;
	int damage;
	int defense;
	ring(int c, int d, int e) : cost(c), damage(d), defense(e) {}
};

vector<weapon> w;
vector<armor> a;
vector<ring> r;

int hp;
int dam;
int arm;

int best;

bool fight(int att, int def) {
	int enemydam = max(dam - def, 1);
	int mydam = max(att - arm, 1);
	int enemyhp = 100;
	int myhp = 100;
	while (true) {
		enemyhp -= mydam;
		if (enemyhp <= 0) {
			return true;
		}
		myhp -= enemydam;
		if (myhp <= 0) {
			return false;
		}
	}
}

int main(int argc, char * argv[]) {
	w.push_back(weapon(8, 4));
	w.push_back(weapon(10, 5));
	w.push_back(weapon(25, 6));
	w.push_back(weapon(40, 7));
	w.push_back(weapon(74, 8));

	a.push_back(armor(0, 0));
	a.push_back(armor(13, 1));
	a.push_back(armor(31, 2));
	a.push_back(armor(53, 3));
	a.push_back(armor(75, 4));
	a.push_back(armor(102, 5));

	r.push_back(ring(0, 0, 0));
	r.push_back(ring(0, 0, 0));
	r.push_back(ring(25, 1, 0));
	r.push_back(ring(50, 2, 0));
	r.push_back(ring(100, 3, 0));
	r.push_back(ring(20, 0, 1));
	r.push_back(ring(40, 0, 2));
	r.push_back(ring(80, 0, 3));

	hp = 100;
	dam = 8;
	arm = 2;
	best = 999999;
	int worst = 0;
	for (int sword = 4; sword >= 0; sword--) {
		for (int shield = 5; shield >= 0; shield--) {
			for (int ring1 = 7; ring1 > 0; ring1--) {
				for (int ring2 = ring1 - 1; ring2 >= 0; ring2--) {
					int cost = w[sword].cost + a[shield].cost + r[ring1].cost + r[ring2].cost;
					int att = w[sword].damage + r[ring1].damage + r[ring2].damage;
					int def = a[shield].defense + r[ring1].defense + r[ring2].defense;
					if (fight(att, def) == true) {
						best = min(best, cost);
					}
					else {
						worst = max(worst, cost);
					}
				}
			}
		}
	}
	cout << "The cheapest winning strat costs " << best << endl;
	cout << "The most expensive losing strat costs " << worst << endl;


}