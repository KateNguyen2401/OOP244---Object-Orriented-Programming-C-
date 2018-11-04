#include <iostream>
#include <cstring>
#include <string.h>
#include "Passenger.h"
using namespace std;
using namespace sict;

Passenger::Passenger() {
	nameP[0] = '\0';
	destination[0] = '\0';
	year = 0;
	month = 0;
	day = 0;
}
Passenger::Passenger(const char* n, const char* dest) {
	if (n == nullptr || strlen(n) == 0 || dest == nullptr || strlen(dest) == 0) {
		nameP[0] = '\0';
		destination[0] = '\0';
		year = 0;
		month = 0;
		day = 0;
	}
	else {
		strcpy(nameP, n);
		strcpy(destination, dest);
		year = 2017;
		month = 7;
		day = 1;
	};

}
bool Passenger::isEmpty() const {
	if (nameP[0] != '\0' && destination[0] != '\0')
		return false;
	else
		return true;
}
void Passenger::display() const {
	if (isEmpty())
		cout << "No passenger!" << endl;
	else {
		if (day <10 && month < 10)
			cout << nameP << " - " << destination << " on " << year << "/0" << month << "/0" << day << endl;
		else if (day >10 && month <10)
			cout << nameP << " - " << destination << " on " << year << "/0" << month << "/" << day << endl;
		else if (day <10 && month > 10)
			cout << nameP << " - " << destination << " on " << year << "/" << month << "/0" << day << endl;
		else
			cout << nameP << " - " << destination << " on " << year << "/" << month << "/" << day << endl;
	}
}
Passenger::Passenger(const char* na, const char* des, int y, int m, int d) {
	bool valid = na != nullptr && des != nullptr &&
		strlen(na) != 0 && strlen(des) != 0 &&
		(y == 2017 || y == 2018 || y == 2019 || y == 2020) &&
		(m >= 1 && m <= 12) &&
		(d >= 1 && d <= 31);
	if (valid) {
		strcpy(nameP, na);
		strcpy(destination, des);
		year = y;
		month = m;
		day = d;
	}
	else {
		nameP[0] = '\0';
		destination[0] = '\0';
		year = 0;
		month = 0;
		day = 0;

	}

}
const char* Passenger::name() const {
	if (nameP != '\0')
		return nameP;
	else
		return {};
}
bool Passenger::canTravelWith(const Passenger& p) const {
	if (strcmp(destination, p.destination) == 0)
		return true;
	else
		return false;
}