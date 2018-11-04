/*
Name: Anh Minh Hieu Nguyen
Student ID: 151432168
Email: amhnguyen@myseneca.ca
*/

#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_
namespace sict {
	class Contact {
		char name[20];
		int numb;
		long long* number;
	public:
		Contact();
		Contact(const char na[] , const long long* no, int n );
		~Contact();
		//void addPhoneNumber(long long );
		bool isEmpty() const;
		void display() const;

	};
}

#endif 
