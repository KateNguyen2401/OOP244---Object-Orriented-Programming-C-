// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////
#include<iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double b, double t, double m) : Account(b) {
		if (t > 0)
			trans = t;
		else
			trans = 0.0;
		if (m > 0)
			month = m;
		else
			month = 0.0;
	}


	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double amount) {
		if (Account::credit(amount)) {
			Account::debit(trans);
			return true;
		}
		else
			return false;
	}



	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double amount) {
		if (Account::debit(amount)) {
			Account::debit(trans);
			return true;
		}
		else 
			return false;
	}


	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd() {
		debit(month);
	}


	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& os) const{
		os << "Account type: Chequing" << std::endl;
		os << "Balance: $" << balance() << std::endl;
		os << "Per Transaction Fee: " << trans << std::endl;
		os << "Monthly Fee: " << month << std::endl;
		os.setf(std::ios::fixed);
		os.precision(2);
	}



}