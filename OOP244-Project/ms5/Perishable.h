#ifndef SICT_PERISHABLE_H_
#define SICT_PERISHABLE_H_
#include<iostream>
#include<fstream>
#include"Date.h"
#include"NonPerishable.h"
namespace sict {
	class Perishable : public NonPerishable {
		Date expiryD;
	public:
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;

	};
	Product* CreatePerishable();
}

#endif // !SICT_PERISHABLE_H_

