#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "SuperHero.h"
using namespace std;
namespace sict {
	SuperHero::SuperHero() {
		bonus = -1;
		Sdefend = -1;
	}
	SuperHero::SuperHero(const char* nm, int hlth, int str, int bn, int df) : Hero(nm, hlth, str) {
		if (bn > 0 && df > 0) {
			bonus = bn;
			Sdefend = df;
		}
		else {
			SuperHero();
		}
	}
	int SuperHero::attackStrength() const {
		return (heroStr() + bonus);
	}
	int SuperHero::defend() const {
		if (isClear() && bonus < 0 && Sdefend < 0)
			return 0;
		else
			return Sdefend;
	}
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		int max_rounds = 0;
		int hlth1 = first.heroHlth();
		int hlth2 = second.heroHlth();
		int str1 = first.attackStrength();
		int str2 = second.attackStrength();
		int df1 = first.defend();
		int df2 = second.defend();
		cout << "Super Fight! " << first.heroName() << " vs " << second.heroName() << " : Winner is ";
		while (hlth1 > 0 && hlth2 > 0) {
			hlth1 = hlth1 - (str2 - df1);
			hlth2 = hlth2 - (str1 - df2);
			max_rounds++;
		}
		if (hlth1 < 0) {
			cout << second.heroName() << " in " << max_rounds << " rounds." << endl;
			return second;
		}
		else {
			cout << first.heroName() << " in " << max_rounds << " rounds." << endl;
			return first;
		}
	}
}
