#ifndef SICT_KINGDOM_H_
#define SICT_kINGDOM_H_
namespace sict {
	struct Kingdom {
		char m_name[33];
		int m_population;
	};
	void display(struct Kingdom p);
	void display(struct Kingdom k[], int n);
}
#endif
