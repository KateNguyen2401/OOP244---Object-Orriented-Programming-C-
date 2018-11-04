#define _CRT_SECURE_NO_WARNINGS
//#include <iomanip>
#include<iostream>
#include<fstream>
#include<string.h>
#include"NonPerishable.h"
using namespace std;
namespace sict {
	//replace and sore the name in dynamically allocated memory
	void NonPerishable::name(const char* nm) {
		if (nm != nullptr) { //check the sring that is passed in
			Pname = new char[strlen(nm) + 1];
			strcpy(Pname, nm);
		}
		else {
			Pname = nullptr;
		}
	}
	const char* NonPerishable::name() const {
		if (Pname != nullptr) //check whether or not name is in safe empty state
			return Pname;
		else
			return nullptr;
	}
	//calculate the final cost of the product 
	double NonPerishable::cost() const {
		if (taxable)
			return price + (price * tax_rate);
		else
			return price;
	}
	//set the error state
	void NonPerishable::message(const char* mess) {
		this->errorState.message(mess);
	}
	//check the error state
	bool NonPerishable::isClear() const {
		if (errorState.ErrorMessage::isClear())
			return true;
		else
			return false;
	}
	//set the object to the safe empty state
	NonPerishable::NonPerishable(const char t) {
		type = t;
		sku[0] = '\0';
		Pname = nullptr;
		unit[0] = '\0';
		qtyOnHand = 0;
		Pquantity = 0;
		price = 0.0;
	}
	//check the values if they are valid,if not send the object to the safe empty state
	NonPerishable::NonPerishable(const char* s, const char* n, const char* u, int on, bool tax, double p, int qN) {
		if (s != '\0' && n != '\0' && n != nullptr  && on >= 0 && p >= 0 && qN >= 0) {
			strcpy(sku, s);
			name(n);
			strcpy(unit, u);
			qtyOnHand = on;
			taxable = tax;
			price = p;
			Pquantity = qN;
		}
		else
			NonPerishable();
	}
	//copy constructor
	NonPerishable::NonPerishable(const NonPerishable& src) {
		Pname = nullptr;
		*this = src; // avoid duplicating with copy assignment
	}
	//copy assignment
	NonPerishable& NonPerishable::operator=(const NonPerishable& n) {
		if (this != &n) {
			strcpy(sku, n.sku);
			strcpy(unit, n.unit);
			qtyOnHand = n.qtyOnHand;
			taxable = n.taxable;
			price = n.price;
			Pquantity = n.Pquantity;
			/*delete[] Pname;
			Pname = nullptr;*/
			if (n.Pname != nullptr) {
				Pname = new char[strlen(n.Pname) + 1];
				strcpy(Pname, n.Pname);
			}
			else {
				Pname = nullptr;
			}
		}
		return *this;
	}
	//deallocating
	NonPerishable::~NonPerishable() {
		delete[] Pname;
	}
	//insert the data of the current record into the fstream object with comma seperated fields
	std::fstream& NonPerishable::store(std::fstream& file, bool newLine) const {
		file << type << "," << sku << "," << Pname
			<< "," << price << "," << taxable << "," << qtyOnHand << "," << unit << ","
			<< Pquantity;
		if (newLine) //if newLine is true, insert new line
			file << endl;
		return file;
	}
	//extract the field from the fstream object into the current object
	std::fstream& NonPerishable::load(std::fstream& file) {
		char f_name[max_name_length + 1]; // create the temporary char variable to store name the scan from the file
		NonPerishable t; // create temporary nonperishable product
		file.getline(t.sku, max_sku_length + 1, ',');
		file.getline(f_name, max_name_length + 1, ',');
		t.name(f_name);
		file >> t.price;
		file.ignore(1, ',');
		file >> t.taxable;
		file.ignore(1, ',');
		file >> t.qtyOnHand;
		file.ignore(1, ',');
		file.getline(t.unit, max_unit_length + 1, ',');
		file >> t.Pquantity;
		*this = t;//copy assign the temporary object the the current object
		return file;
	}
	//display the information of the product
	std::ostream& NonPerishable::write(std::ostream& os, bool linear) const {
		if (!(errorState.isClear())) { //check for error
			os << errorState.message();
		}
		else {
			if (linear) {
				os.width(max_sku_length);
				os << left << sku << "|";
				os.width(20);
				os << left << name() << "|";
				os.width(7);
				os.setf(std::ios::fixed);
				os.precision(2);
				os << right << cost() << "|";
				os.width(4);
				os << right << quantity() << "|";
				os.width(10);
				os << left << unit << "|";
				os.width(4);
				os << right << qtyNeeded() << "|";
			}
			else {
				os.setf(std::ios::fixed);
				os.precision(2);
				os << "Sku: " << sku << endl <<
					"Name: " << name() << endl <<
					"Price: " << price << endl;
				if (taxable)
					os << "Price after tax: " << cost() << endl;
				else
					os << "Price after tax: N/A" << endl;
				os << "Quantity On Hand: " << qtyOnHand << " " << unit << endl
					<< "Quantity Needed: " << qtyNeeded() ;
			}
		}
		return os;
	}
	//read the user's input
	std::istream& NonPerishable::read(std::istream& is) {
		char f_sku[max_sku_length + 1];  //create the temporary variable to store the user's input
		char f_name[max_name_length + 1];
		double f_price;
		char f_unit[max_unit_length + 1];
		char f_taxed = '\0';
		int f_quant = 0;
		int f_quantN = 0;
		cout << " Sku: ";
		is >> f_sku;
		is.ignore();
		cout << " Name: ";
		is >> f_name;
		is.ignore();
		cout << " Unit: ";
		is >> f_unit;
		is.ignore();
		cout << " Taxed? (y/n): ";

		is >> f_taxed;
		if (f_taxed != 'y' && f_taxed != 'Y' &&
			f_taxed != 'n' && f_taxed != 'N') {
			is.setstate(std::ios::failbit);
		}
		if (is.fail())
			errorState.message("Only (Y)es or (N)o are acceptable");
		else {
			cout << " Price: ";
			is >> f_price;
			is.ignore();
			if (is.istream::fail())
				errorState.message("Invalid Price Entry");
			else {
				cout << "Quantity On hand: ";
				is >> f_quant;
				is.ignore();
				if (is.fail())
					errorState.message("Invalid Quantity Entry");
				else {

					cout << "Quantity Needed: ";
					is >> f_quantN;
					if (is.fail())
						errorState.message("Invalid Quantity Needed Entry");
					else
						errorState.message("");
				}
			}
		}
		//if there is no error, assign it to the current object
		if (errorState.isClear()) {
			strcpy(sku, f_sku);
			name(f_name);
			strcpy(unit, f_unit);
			price = f_price;
			(f_taxed == 'y' || f_taxed == 'Y' || f_taxed == '1') ? taxable = true : taxable = false;
			Pquantity = f_quantN;
			qtyOnHand = f_quant;
		}

		return is;
	}

	bool NonPerishable::operator==(const char* s) const {//compare sku string
		if (strcmp(sku, s) == 0)
			return true;
		else
			return false;
	}
	double NonPerishable::total_cost() const { // calculate the total cost
		return this->cost() * qtyOnHand;
	}
	void NonPerishable::quantity(int q) { //set the quantity on hand
		qtyOnHand = q;
	}
	bool NonPerishable::isEmpty() const { // check whether or not the object is empty
		if (sku[0] != '\0' || Pname != nullptr || qtyOnHand != 0 || Pquantity != 0 || price != 0.0)
			return false;
		else
			return true;
	}
	int NonPerishable::qtyNeeded() const {
		return Pquantity;
	}
	int NonPerishable::quantity() const {
		return qtyOnHand;
	}
	bool NonPerishable::operator>(const char* s) const {
		if (strcmp(sku, s) > 0)
			return false;
		else
			return true;
	}
	int NonPerishable::operator+=(int n) {//increase the quantity on hand
		if (n > 0) {
			qtyOnHand += n;
		}
		return qtyOnHand;
	}
	bool NonPerishable::operator>(const Product& nm) const {
		if (strcmp(nm.name(), Pname) > 0)
			return true;
		else
			return false;
	}
	std::ostream& operator<<(std::ostream& os, const Product& p) {//helper function insert the record into ostream
		p.write(os, true);
		return os;
	}
	std::istream& operator>>(std::istream& is, Product& p) {//helper function extracts the record into ostream
		p.read(is);
		return is;
	}
	double operator+=(double& m, const Product& p) {
		m += p.total_cost();
		return m;
	}
	Product* CreateProduct() { //create a new product object
		Product* p = nullptr;
		p = new NonPerishable();
		return p;
	}
}
