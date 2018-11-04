#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Hero.h"
using namespace std;
namespace sict {
	Hero::Hero() {
		name[0] = '\0';
		strength = -1;
		health = -1;
	}
	Hero::Hero(const char* nm, int hlth, int str) {
		if (nm != nullptr && hlth > 0 && str > 0) {
			strcpy(name, nm);
			health = hlth;
			strength = str;
		}
		else
			Hero();
	}
	bool Hero::isClear() const{
		if (name[0] == '\0' && strength < 0 && health < 0)
			return true;
		else
			return false;
	}
	void Hero::operator-=(int attack) {
		if (attack > 0) {
			health -= attack;
			if (health < 0)
				health = 0;
		}       
	}
	bool Hero::isAlive() const {
		if (health > 0)
			return true;
		else
			return false;
	}
	int Hero::attackStrength() const {
		if (strength < 0)
			return 0;
		else
			return strength;
	}
	const char* Hero::heroName() const {
		return name;
	}
	const int Hero::heroHlth() const {
		return health;
	}
	int Hero::heroStr() const {
		return strength;
	}
	ostream& operator<<(ostream& os, const Hero& hero) {
		if (hero.isClear()) {
			os << "No hero";
			return os;
		}
		else {
			os << hero.heroName();
			return os;
		}
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		int max_rounds = 0;
		int hlth1 = first.heroHlth();
		int hlth2 = second.heroHlth();
		int str1 = first.heroStr();
		int str2 = second.heroStr();
		cout << "Ancient Battle! " << first.heroName() << " vs " << second.heroName() << " : Winner is ";
		while ( hlth1 > 0 && hlth2 > 0) {
			hlth1 -= str2;
			hlth2 -= str1;
			max_rounds++;
		}
		if (hlth1 < 0 || hlth1 == 0) {
			cout << second.heroName() << " in " << max_rounds << " rounds." << endl;
			return second;
		}
		else {
			cout << first.heroName() << " in " << max_rounds << " rounds." << endl;
			return first;
		}
		
	}
}
