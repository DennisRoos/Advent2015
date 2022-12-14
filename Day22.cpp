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

int att;
int best;

void fight(int hp, int ehp, int mana, int manaspent, int shield, int poison, int recharge) {
	if (manaspent > best) {
		return;
	}

	//start of enemy turn
	if (recharge > 0) {
		mana += 101;
		recharge--;
	}
	if (poison > 0) {
		poison--;
		ehp -= 3;
	}
	if (ehp <= 0) {
		best = min(manaspent, best);
		return;
	}

	if (shield > 0) {//enemy attacks
		hp -= (att - 7);
		shield--;
	}
	else {
		hp -= att;
	}
	//start of our turn

	//Hard mode for Part 2
	hp--;

	if (hp <= 0) {
		return;//we died :(
	}


	if (recharge > 0) {
		mana += 101;
		recharge--;
	}
	if (poison > 0) {
		ehp -= 3;
		poison--;
	}
	if (ehp <= 0) {
		best = min(manaspent, best);
		return;
	}
	shield--;

	//now to choose one of the spells to cast
	if (mana >= 53) {//Magic Missile
		fight(hp, ehp - 4, mana - 53, manaspent + 53, shield, poison, recharge);
	}
	if (mana >= 73) {//Drain Life
		fight(hp + 2, ehp - 2, mana - 73, manaspent + 73, shield, poison, recharge);
	}
	if (mana >= 113) {//Shield
		fight(hp, ehp, mana - 113, manaspent + 113, 6, poison, recharge);
	}
	if (mana >= 173) {//Poison
		fight(hp, ehp, mana - 173, manaspent + 173, shield, 6, recharge);
	}
	if (mana >= 229) {//Recharge
		fight(hp, ehp, mana - 229, manaspent + 229, shield, poison, 5);
	}

}


int main(int argc, char * argv[]) {
	best = 1500;
	att = 9;
	fight(59, 51, 500, 0, 0, 0, 0);
	cout << "The least mana spent while winning was " << best << " mana.\n";
}