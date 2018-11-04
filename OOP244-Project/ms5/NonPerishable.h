#ifndef SICT_NONPERISHABLE_H_
#define SICT_NONPERISHABLE_H_
#include<iostream>
#include<fstream>
#include "Product.h"
#include "ErrorMessage.h"
namespace sict {
#define max_sku_length 7
#define max_unit_length 10
#define max_name_length 75
#define tax_rate 0.13
	class NonPerishable : public Product {
		char type;
		char sku[max_sku_length + 1];
		char* Pname;
		char unit[max_unit_length + 1];
		int qtyOnHand;
		int Pquantity;
		double price;
		bool taxable;
		ErrorMessage errorState;
	protected:
		void name(const char*);
		const char* name() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
	public:
		NonPerishable(const char = 'N');
		NonPerishable(const char*, const char*, const char*, int = 0, bool = true, double = 0.0, int = 0);
		NonPerishable(const NonPerishable&);
		NonPerishable& operator=(const NonPerishable&);
		~NonPerishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear = true) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		int operator+=(int);
		bool operator>(const Product&) const;

	};
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
	Product* CreateProduct();

}
#endif // !SICT_NONPERISHABLE_H_

