/*
Name: Anh Minh Hieu Nguyen
ID: 151432168
Email: amhnguyen@myseneca.ca
*/
#ifndef CRA_ACCOUNT_H_
#define CRA_ACCOUNT_H_
namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	class CRA_Account {
		char fName[max_name_length];
		char gName[max_name_length];
		int SIN;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}
#endif
