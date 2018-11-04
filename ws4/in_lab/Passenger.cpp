#include <iostream>
#include <cstring>
#include <string.h>
#include "Passenger.h"
using namespace std;
using namespace sict;

Passenger::Passenger() {
	name[0] = '\0';
	destination[0] = '\0';
}
Passenger::Passenger(const char* n, const char* dest) {
	if (n == nullptr || dest == nullptr ||strlen(n) == 0||strlen(n) ==0){
		name[0] = '\0';
		destination[0] = '\0';
	}else{
		strcpy(name, n);
	//if (dest == nullptr || strlen(dest) == 0)
		//destination[0] = '\0';
	
		strcpy(destination, dest);
	}
}
bool Passenger::isEmpty() const {
	if (name[0] != '\0' && destination[0] != '\0')
		return false;
	else
		return true;
}
void Passenger::display() const {
	if (isEmpty())
		cout << "No passenger!" << endl;
	else {
		cout << name << " - " << destination << endl;
	}
}
