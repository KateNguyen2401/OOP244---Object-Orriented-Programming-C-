#ifndef PASSENGER_H_
#define PASSENGER_H_
namespace sict {
	class Passenger {
		int year;
		int month;
		int day;
		char nameP[32];
		char destination[32];
	public:
		Passenger();
		Passenger(const char*, const char*);
		Passenger(const char*, const char*, int, int, int);
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
		bool isEmpty() const;
		void display() const;
	};
}

#endif
