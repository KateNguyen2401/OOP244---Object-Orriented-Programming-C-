// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the Account class
///////////////////////////////////////////////////
#include <iostream>
#include "Account.h"
using namespace std;
namespace sict {
	Account::Account(double b) {
		if (b > 0)
			bal = b;
		else
			bal = 0.0;
	}
	bool Account::credit(double amount) {
		if (amount > 0) {
			bal += amount;
			return true;
		}
		else {
			return false;
		}
	}
	bool Account::debit(double amount) {
		if (amount > 0) {
			bal -= amount;
			return true;
		}
		else
			return false;
	}
	double Account::balance() const {
		return bal;
	}
 }
