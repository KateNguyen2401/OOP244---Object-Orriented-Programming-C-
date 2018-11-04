#include <iostream>
#include "Kingdom.h"
using namespace std;
//using namespace sict;
void sict::display(struct Kingdom d) {
	cout << d.m_name << ", population " << d.m_population << endl;
	return;
}
void sict::display(struct Kingdom k[], int n) {
	int i,sum=0;
	cout << "------------------------------" << endl;
	cout << "Kingdoms of SICT" << endl;
	cout << "------------------------------" << endl;
	for (i = 0; i < n; i++) {
		cout << i+1 << ". " << k[i].m_name << ", population " << k[i].m_population << endl;
		sum += k[i].m_population;
	}
	cout << "------------------------------" << endl;
	cout << "Total population of SICT: " << sum << endl;
	cout << "------------------------------" << endl;
	return;
}
