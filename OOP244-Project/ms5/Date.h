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
#ifndef SICT_DATE_H
#define SICT_DATE_H
#include <iostream>
namespace sict {
#define min_year 2000
#define max_year 2030
	class Date {
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4
		int year;
		int month;
		int day;
		int comp;
		int errorState;
		int mdays(int, int)const;
	public:
		Date();
		Date(int, int, int);
		int value() const;
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		int errCode() const;
		bool bad() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};
	std::ostream& operator<<(std::ostream& os, const Date& D);
	std::istream& operator>>(std::istream& os, Date& D);
}
#endif
