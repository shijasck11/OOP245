// Ore.h
#ifndef ORE_HEADER
#define ORE_HEADER
#include <iostream>
#include <cstring>

using namespace std;
namespace sdds {
	const double DEFAULT_WEIGHT = 300.50;
	const int DEFAULT_PURITY = 20;
	const int CLASS_LEN = 30;

	class Ore
	{
	public:
		Ore();
		Ore(double weight, int purity, const char* classification = "Unknown");
		void setEmpty();
		bool refine();
		ostream& display(ostream& os) const;
		istream& input(istream& is);
		

	private:
		double f_weight;
		int f_purity;
		char f_classification[CLASS_LEN+1];

	};
	ostream& operator<<(ostream& os, const Ore& ore);
	istream& operator>>(istream& is, Ore& ore);
}
#endif