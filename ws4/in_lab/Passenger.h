#ifndef PASSENGER_H_
#define PASSENGER_H_
namespace sict {
	class Passenger {
		char name[32];
		char destination[32];
	public:
		Passenger();
		Passenger(const char*,const char*);
		bool isEmpty() const;
		void display() const;
	};
}

#endif 

