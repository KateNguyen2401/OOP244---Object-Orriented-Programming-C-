#ifndef  SICT_SUPERHERO_H_
#define SICT_SUPERHERO_H
#include <iostream>
#include "Hero.h"
namespace sict {
	class SuperHero : public Hero {
		int bonus;
		int Sdefend;
	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif // ! SICT_SUPERHERO_H_


