#include<iostream>
#include<fstream>
#include"Perishable.h"
using namespace std;
namespace sict {
	Perishable::Perishable() : NonPerishable('P'){
		expiryD = Date(); //set expiry date to safe empty state using sonstructor
	}
	std::fstream& Perishable::store(std::fstream& file, bool newLine ) const {
		NonPerishable::store(file, false) << "," << expiryD; //call the base class
		if (newLine)
			file << endl;
		return file;
	}
	std::fstream& Perishable::load(std::fstream& file) {
		NonPerishable::load(file);
		file.ignore(1,',');
		expiryD.read(file);
		return file;
	}
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		NonPerishable::write(os, linear);
		if (isClear()) {
			if (linear)
				os << expiry();
			else {
				os << endl << "Expiry date: " << expiry();
			}
		}
		return os;
	}
	std::istream& Perishable::read(std::istream& is) {
		Date temp;//create a temporary Date object
		NonPerishable::read(is);
		cout << "Expiry date (YYYY/MM/DD): ";
		temp.read(is);
		if (temp.bad()) {
			is.istream::setstate(std::ios::failbit);
			if (temp.Date::errCode() == CIN_FAILED)
				NonPerishable::message("Invalid Date Entry");
			else if (temp.errCode() == YEAR_ERROR)
				NonPerishable::message("Invalid Year in Date Entry");
			else if (temp.errCode() == MON_ERROR)
				NonPerishable::message("Invalid Month in Date Entry");
			else if (temp.errCode() == DAY_ERROR)
				NonPerishable::message("Invalid Day in Date Entry");
			
		}
		
		expiryD = temp;//copy assign the temporary object to the current object
		return is;
	}
	const Date& Perishable::expiry() const {
		return expiryD;
	}
	Product* CreatePerishable() {
		Product* p = nullptr;
		p = new Perishable();
		return p;
	}
}