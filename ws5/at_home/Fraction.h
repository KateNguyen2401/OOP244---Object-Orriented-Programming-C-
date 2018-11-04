#ifndef _FRACTION_H_
#define _FRACTION_H_
namespace sict {
	class Fraction {
		int numer;
		int denomi;
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction& operator+=(const Fraction& rhs) ;
	};
}
#endif 

