#include <iostream>
#include "CRA_Account.h"
using namespace std;
using namespace sict;
CRA_Account::CRA_Account() {
	SIN = 0;
	NoOfYear = 0;
}
void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
	int test[9];
	int i,check,sum = 0;
	int x = sin;
	for (i = 8; i >= 0; i--) {
		test[i] = x % 10;
		x /= 10;
	}
	for (i = 1 ; i < 8; i += 2) {
		if (2 * int(test[i]) >= 10)
			sum += 2 * int(test[i]) - 9;
		else
			sum += 2 * int(test[i]);
	}
	for (i = 0; i < 9; i += 2) {
		sum += int(test[i]);
	}
	check = sum % 10;
	if (min_sin <= sin && sin <= max_sin && familyName[0] != '\0' && givenName[0] != '\0' && check ==0 ) {
		for (int i = 0; i< max_name_length; i++) {
			fName[i] = familyName[i];
			gName[i] = givenName[i];
		}
		SIN = sin;
	}
	else {
		SIN = 0;
	}
}
bool CRA_Account::isEmpty() const {
	if (SIN == 0)
		return true;
	else
		return false;
}
void CRA_Account::display() const {
	int i;
	if (SIN != 0) {
		cout << "Family Name: " << fName << endl;
		cout << "Given Name : " << gName << endl;
		cout << "CRA Account: " << SIN << endl;
		for (i = 0; i < NoOfYear; i++) {
			if (OwOrRe[i] > 2) {
				cout << "Year (" << taxYear[i] << ") balance owing: " << OwOrRe[i] << endl;
			}
			else if (OwOrRe[i] < -2) {
				float a = OwOrRe[i] * (-1.00);
				cout.precision(2);
				cout << fixed << "Year (" << taxYear[i] << ") refund due: " << a << endl;
			}
			else {
				cout << "Year (" << taxYear[i] << ") No balance owing or refund due!" << endl;
			}
		}
	}
	else {
		cout << "Account object is empty!" << endl;
	}
}
void CRA_Account::set(int year, double balance) {
	if (SIN != 0 && NoOfYear < max_yrs) {
		taxYear[NoOfYear] = year;
		OwOrRe[NoOfYear] = balance;
		NoOfYear++;
	}
}
