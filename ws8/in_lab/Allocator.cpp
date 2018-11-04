// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file allocates an Account object in dynamic memory
///////////////////////////////////////////////////

#include <iostream>
#include <string.h>
#include "SavingsAccount.h" 
using namespace std;
namespace sict {

	// define interest rate
	//
#define INT_RATE 0.05

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* type, double b) {
		iAccount* acc = nullptr;
		if (type[0] == 'S') {
			acc = new SavingsAccount(b,INT_RATE);
			return acc;
		}
		else
			return nullptr;

	}







}
