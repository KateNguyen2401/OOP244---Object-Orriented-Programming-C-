#include <iostream>
#include <string.h>
#include "Contact.h"
using namespace std;
using namespace sict;

Contact::Contact() {
	name[0] = '\0';
	numb = 0;
	number = nullptr;
}
Contact::Contact(const char na[], const long long* no, int n) {
	if (na == nullptr) {
		*this = Contact();
	}
	else{
		strncpy(name, na, 19);
	}
	if (n >0) {
		numb = n;
		number = new long long[numb];
		for (int i = 0; i < numb; i++)
			number[i] = no[i];
	}
	else {
		number = nullptr;
		numb = 0;
	}
}
Contact::~Contact() {
	delete[] number;
}
bool Contact::isEmpty() const {
	if ((name[0] == '\0' || name == nullptr || strcmp(name, "") ==0) && numb ==0)
		return true;
	else
		return false;
}
void Contact::display() const {
	if (isEmpty()) {
		cout << "Empty contact!" << endl;
	}
	else {
		cout << name << endl;
		for (int i = 0; i<numb; i++) {
			if (10000000000 <= number[i] && number[i] <= 999999999999) {
				cout << "(+" << number[i] / 10000000000 << ") ";
					/*<< number[i] % 10000000000 / 10000000 << " "
					<< number[i] % 10000000 / 10000 << "-"
					<< number[i] % 10000000 % 10000 << endl;*/
				long long test = number[i] % 10000000000;
				int array[10];
				for (int j = 9; j >= 0; j--) {
					array[j] = test % 10;
					test /= 10;
					//cout << array[j];
				}
				cout << array[0] << array[1] << array[2] << " " 
					<< array[3] << array[4] << array[5] << "-"
					<< array[6] << array[7] << array[8] << array[9] << endl;
				
			}
		}
	}
}


