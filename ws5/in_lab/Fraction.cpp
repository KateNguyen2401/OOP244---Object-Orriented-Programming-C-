/*Name: Anh Minh Hieu Nguyen
  ID: 151432168
  Email: amhnguyen@myseneca.ca
*/


#include <iostream>
#include "Fraction.h"
using namespace std;
using namespace sict;
Fraction::Fraction() {
	numer = -1;
	denomi = -1;
}
Fraction::Fraction(int num, int deno) {
	if (num > -1 && deno > 0) {
		numer = num;
		denomi = deno;
		this->reduce();
	}
	else {
		numer = -1;
		denomi = -1;
	}
}
int Fraction::max() const {
	if (numer > denomi)
		return numer;
	else
		return denomi;
}
int Fraction::min() const {
	if (numer < denomi)
		return numer;
	else
		return denomi;
}
int Fraction::gcd() const {
	int mn = min();  // min of numerator and denominator
	int mx = max();  // max of numerator and denominator
	int g_c_d = 1;
	bool found = false;

	for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
		if (mx % x == 0 && mn % x == 0) {
			found = true;
			g_c_d = x;
		}
	}
	return g_c_d;
}
void Fraction::reduce(){
	int a = gcd();
	numer = numer / a;
	denomi = denomi / a;
}
bool Fraction::isEmpty() const {
	if (numer == -1 || denomi == -1)
		return true;
	else
		return false;
}
void Fraction::display() const{
	if (isEmpty()) {
		cout << "no fraction stored" ;
	}
	else {
		if (denomi == 1)
			cout << numer;
		else
			cout << numer << "/" << denomi ;
	}
}
Fraction Fraction::operator+(const Fraction& rhs) const {
	if (isEmpty() || rhs.isEmpty() ) {
		Fraction result(-1, -1);
		return result;
	}
	else {
		Fraction result((numer * rhs.denomi + rhs.numer * denomi), (denomi * rhs.denomi));
		result.reduce();
		return result;

	}
}
