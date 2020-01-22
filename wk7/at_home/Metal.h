// Metal.h
#ifndef SDDS_METAL_HEADER
#define SDDS_METAL_HEADER
#include <iostream>
#include "Ore.h"
#include <cstring>

using namespace std;
namespace sdds
{
	const double DEFAULT_MOHS = 2.5;
	const int NAME_LEN = 10;

	class Metal : public Ore
	{
	public:
		Metal();
		Metal(double, int, const char*, const char*, double);
		//~Metal();
		void emptyState();
		void refine();
		ostream& display(ostream& os) const;
		istream& input(istream& is);

	private:
		char* f_name;
		double f_mohs;
	};

	ostream& operator<<(ostream& os, const Metal& met);
	istream& operator>>(istream& is, Metal& met);
}

#endif // !SDDS_METAL_H
