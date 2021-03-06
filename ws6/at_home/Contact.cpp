/*
Name: Anh Minh Hieu Nguyen
Student ID: 151432168
Email: amhnguyen@myseneca.ca
*/

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
Contact::Contact(const char* na, const long long* no, int n) {
	if (na != nullptr) {
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
Contact::Contact(const Contact& src) {
	number = nullptr;
	*this = src;
	/* strncpy(name, src.name, 19);
	numb = src.numb;
	if (src.number != nullptr) {
		number = new long long[numb];
		for (int i = 0; i < numb; i++)
			number[i] = src.number[i];
	}
	else {
		number = nullptr;
	}*/
}
Contact& Contact::operator=(const Contact& cpyass) {
	if (this != &cpyass) {
		strncpy(name, cpyass.name, 19);
		numb = cpyass.numb;
		delete[] number;
		if (cpyass.number != nullptr) {
			number = new long long[numb];
			for (int i = 0; i < numb;i++)
				number[i] = cpyass.number[i];
		}
		else {
			number = nullptr;
		}
	}
	return *this;
	
}
Contact& Contact::operator+=(long long phone) {
	long long* phonecpy = nullptr;
	int noOfPhone = numb +1;
	phonecpy = new long long[noOfPhone];
	for (int i = 0; i < numb; i++)
		phonecpy[i] = number[i];
	phonecpy[noOfPhone - 1] = phone;
	numb++;
	number = new long long[numb];
	for (int i = 0; i < numb; i++){
		 number[i] = phonecpy[i];
	}
	return *this;
}
bool Contact::isEmpty() const {
	if (name[0] == '\0' || name == nullptr)
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
				long long test = number[i] % 10000000000;
				int array[10];
				for (int j = 9; j >= 0; j--) {
					array[j] = test % 10;
					test /= 10;
				}
				cout << array[0] << array[1] << array[2] << " "
					<< array[3] << array[4] << array[5] << "-"
					<< array[6] << array[7] << array[8] << array[9] << endl;

			}
		}
	}
}


