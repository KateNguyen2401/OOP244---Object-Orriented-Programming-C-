// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the SavingsAccount class
///////////////////////////////////////////////////
#include <iostream>
#include "SavingsAccount.h"
using namespace std;
namespace sict {
	SavingsAccount::SavingsAccount(double b, double r) : Account(b){
		if (r > 0)
			rate = r;
		else
			rate = 0.0;
	}
	void SavingsAccount::monthEnd() {
		double month = balance() * rate;
		credit(month);

	}
	void SavingsAccount::display(std::ostream& os) const{
		os << "Account type: Savings" << std::endl;
		os.setf(std::ios::fixed);
		os.precision(2);
		os << "Balance: $" << balance() << std::endl;
		os << "Interest Rate (%): " << rate *100 << std::endl;
	}
}
