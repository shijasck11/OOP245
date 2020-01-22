// Ore.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Ore.h"

using namespace std;
using namespace sdds;

namespace sdds
{
	Ore::Ore() {
		setEmpty();
	}
	void Ore::setEmpty() {
		f_weight = 0;
		f_purity = 0;
		f_classification[0] = '\0';
	}

	Ore::Ore(double weight, int purity, const char* classification) {
		if (weight < 1)
		{
			f_weight = DEFAULT_WEIGHT;
		}
		else {
			f_weight = weight;
		}
		if (purity < 1 || purity > 100)
		{
			f_purity = DEFAULT_PURITY;
		}
		else {
			f_purity = purity;
		}
		if (strlen(classification) > CLASS_LEN)
		{
			strncpy(f_classification, classification, CLASS_LEN);
		}
		else
		{
			strcpy(f_classification, classification);
		}

	}
	bool Ore::refine() {
		bool ret = false;
		if (f_purity > 100)
		{
			cout << "Can no longer be refined" << endl;
			ret = true;
			f_purity = 100;
		}
		else
		{
			f_weight -= 20;
			f_purity += 10;
			ret = false;
		}
		return ret;
	}

	ostream& Ore::display(ostream& os) const {
		if (f_weight == 0 || f_purity == 0 || f_classification[0] == '\0')
		{
			os << "This ore is imaginary" << endl;
		}
		else
		{
			os.setf(ios::fixed);
			os.precision(2);
			os << "Weight: " << f_weight << endl;
			os << "Purity: " << f_purity << endl;
			os << "Classification: " << f_classification << endl;
		}
		return os;
	}

	istream& Ore::input(istream& is) {
		double weight;
		int purity;
		char classification[CLASS_LEN + 1];
		cout << "Enter a value for this ore's weight: ";
		is >> weight;
		cout << "Enter a value for this ore's purity: ";
		is >> purity;
		is.ignore(9999, '\n');
		cout << "Enter a classification for the ore (MAX 30 chars): ";
		is.getline(classification, CLASS_LEN);

		/*getline(is, classification);*/
		if (weight < 1)
		{
			f_weight = DEFAULT_WEIGHT;
		}
		else {
			f_weight = weight;
		}
		if (purity < 1 || purity > 100)
		{
			f_purity = DEFAULT_PURITY;
		}
		else {
			f_purity = purity;
		}
		if (strlen(classification) > CLASS_LEN)
		{
			strncpy(f_classification, classification, CLASS_LEN);
		}
		else
		{
			strcpy(f_classification, classification);
		}
		return is;
	}

	ostream& operator<<(ostream& os, const Ore& ore) {
		os << "Ore" << endl;
		ore.display(os);
		return os;
	}

	istream& operator>>(istream& is, Ore& ore) {
		ore.input(is);
		return is;
	}
}

