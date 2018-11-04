#ifndef SICT_HERO_H_
#define SICT_HERO_H_
#include <iostream>
using namespace std;
namespace sict {
	class Hero {
		char name[41];
		int health;
		int strength;
	public:
		Hero();
		Hero(const char*, int, int);
		bool isClear() const;
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		const char* heroName() const;
		const int heroHlth() const;
		int heroStr() const;
	};
	ostream& operator<<(ostream& os, const Hero& hero);
	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif // !SICT_HERO_H_


