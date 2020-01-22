// Metal.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Metal.h"
#include "Ore.h"
#include<string.h>
#include<stdio.h>
using namespace std;

namespace sdds
{
	Metal::Metal() {
		emptyState();
	}

	Metal::Metal(double weight, int purity, const char* classification, const char* name, double mohs) : Ore(weight, purity, classification) {
	
		if (name == nullptr || name[0] == '\0')
		{
			emptyState();
		}
		else
		{
			f_name = new char[NAME_LEN];
			if (strlen(name)>NAME_LEN)
			{
				strncpy(f_name, name, NAME_LEN+1);
			}
			else
			{
				strcpy(f_name, name);
			}
			if (mohs > 0)
			{
				f_mohs = mohs;
			}
			else
			{
				f_mohs = DEFAULT_MOHS;
			}
			//delete[] f_name;
		}
		
	}
	
	void Metal::refine() {
		if (!(Ore::refine()))
		{
			f_mohs += 1;
		}
	}

	void Metal::emptyState() {
		f_name = nullptr;
		f_mohs = 0;
	}
	ostream& Metal::display(ostream& os) const {
		if (f_name == nullptr ||  f_mohs == 0)
		{
			os << "This metal is imaginary" << endl;
		}
		else
		{
			os << "Name: " << f_name << endl;
			Ore::display(os);
			os << "Mohs: " << f_mohs << endl;
		}
		return os;
	}
	

	istream& Metal::input(istream& is) {
		char tempName[NAME_LEN+1];
		double tempmohs;
		cout << "Enter a value for this metal's name: ";
		is.getline(tempName, NAME_LEN);
		/*if (f_name)
		{
			delete[] f_name;
		}*/
		f_name = new char[NAME_LEN];
		strncpy(f_name, tempName, NAME_LEN);
		cout << "Enter a value for this metal's mohs: ";
	/*	is.clear();
		is.ignore(1000,'\n');*/
		is >> tempmohs;
		if (tempmohs < 1)
		{
			tempmohs = DEFAULT_MOHS;
		}
		else
		{
			f_mohs = tempmohs;
		}
		Ore::input(is);
		return is;
	}

	ostream& operator<<(ostream& os, const Metal& met) {
		cout << "Metal" << endl; // Maybe os instead
		met.display(os);
		return os;
	}

	istream& operator>>(istream& is, Metal& met) {
		met.input(is);
		return is;
	}
}