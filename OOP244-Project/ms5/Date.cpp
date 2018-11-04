// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"
#include <iostream>
using namespace std;

namespace sict {

	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const { 
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
	Date::Date() {
		year = 0;
		month = 0;
		day = 0;
		errorState = NO_ERROR;
	}
	//check the passed data, if it is not true, set the object to the safe empty state
	Date::Date(int y, int m, int d) {
		if (!(y >= min_year && y <= max_year)) {
			errorState = YEAR_ERROR;
			*this = Date();
		}
		else if (!(m >= 1 && m <= 12)) {
			errorState = MON_ERROR;
			*this = Date();
		}
		else if (!((d >= 1) && (d <= mdays(m, y)))) {
			errorState = DAY_ERROR;
			*this = Date();
		}
		else{
			errorState = NO_ERROR;
			year = y;
			month = m;
			day = d;
		}
	}
	int Date::value() const {//calculate the valid date
		return year * 372 + month * 31 + day;
	}
	bool Date::operator==(const Date& rhs) const {
		return (value() == rhs.value());
	}
	bool Date::operator!=(const Date& rhs) const {
		return (value() != rhs.value());
	}
	bool Date::operator<(const Date& rhs) const {
		return (value() < rhs.value());
	}
	bool Date::operator>(const Date& rhs) const {
		return (value() > rhs.value());
	}
	bool Date::operator<=(const Date& rhs) const {
		return (value() <= rhs.value());
	}
	bool Date::operator>=(const Date& rhs) const {
		return (value() >= rhs.value());
	}
	int Date::errCode() const { //return the error state
		return errorState;
	}
	bool Date::bad() const {
		return errorState != NO_ERROR;
	}
	std::istream& Date::read(std::istream& istr)  {
		istr >> year;
		istr.ignore(1, '/');//ignore 1 "/" character
		istr >> month;
		istr.ignore(1, '/');
		istr >> day;
		if (!(istr.fail())) {//if it fail, set the error state
			if (!(year >= min_year && year <= max_year)) {
				errorState = YEAR_ERROR;
				year = 0;
				month = 0;
				day = 0;
			}
			else if (!(month >= 1 && month <= 12)) {
				errorState = MON_ERROR;
				year = 0;
				month = 0;
				day = 0;
			}
			else if (!((day >= 1) && (day <= mdays(month, year)))) {
				errorState = DAY_ERROR;
				year = 0;
				month = 0;
				day = 0;
			}
			else
				errorState = NO_ERROR;
		}
		else
			errorState = CIN_FAILED;
		return istr;

	}
	std::ostream& Date::write(std::ostream& ostr) const {//display the date in the right format yyyy/mm/dd
		if (day < 10 && month < 10)
			ostr << year << "/0" << month << "/0" << day ;
		else if (day < 10)
			ostr << year << "/" << month << "/0" << day ;
		else if (month < 10)
			ostr << year << "/0" << month << "/" << day ;
		else
			ostr << year << "/" << month << "/" << day;
		return ostr;
	}
	std::ostream& operator<<(std::ostream& os,const Date& D) {
		return D.write(os);
	}
	std::istream& operator>>(std::istream& is, Date& D) {
		return D.read(is);
	}
}
