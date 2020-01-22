// Figurine.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Figurine.h"


using namespace std;
namespace sdds
{
	Figurine::Figurine() {
		setEmpty();
	}
	Figurine::Figurine(const char* name, const char* pose, double price) {
		if ((name == nullptr || name[0] == '\0') || (pose == nullptr || pose[0] == '\0'))
			setEmpty();

		else if (strlen(name) > MAX_NAME_LEN)
		{
			strncpy(f_name, name, MAX_NAME_LEN);
			f_name[MAX_NAME_LEN] = '\0';
			f_pose = new char[strlen(pose) + 1];
			strcpy(f_pose, pose);
			f_price = price;
		}

		else if (price <= 0)
		{
			f_pose = new char[strlen(pose) + 1];
			strcpy(f_pose, pose);
			strncpy(f_name, name, MAX_NAME_LEN);
			f_name[MAX_NAME_LEN] = '\0';
			f_price = DEFAULT_PRICE;
		}
		else {

			f_pose = new char[strlen(pose) + 1];
			strcpy(f_pose, pose);
			strcpy(f_name, name);
			f_price = price;

		}
	}
	Figurine::Figurine(const Figurine& inputFigurine) {

		if (inputFigurine.isEmpty())
			setEmpty();
		else
		{
			f_price = inputFigurine.f_price;
			f_pose = new char[strlen(inputFigurine.f_pose) + 1];
			strcpy(f_pose, inputFigurine.f_pose);
			strcpy(f_name, inputFigurine.f_name);
		}

	}
	Figurine::~Figurine() {
		//if (isEmpty())
		//	cout << "An unknown flower has departed..." << endl;


		delete[] f_pose;
	}
	bool Figurine::isEmpty() const {
		return (f_price <= 0 || f_pose == nullptr || f_name[0] == '\0');
	}
	void Figurine::setEmpty() {
		f_name[0] = '\0';
		f_pose = nullptr;
		f_price = 0;
	}

	void Figurine::setName(const char* figurineName) {
		strcpy(f_name, figurineName);
	}

	void Figurine::setPose(const char* figurinePose) {

		f_pose = new char[strlen(figurinePose) + 1];
		strcpy(f_pose, figurinePose);
	}
	void Figurine::setPrice(double figurinePrice) {
		f_price = (figurinePrice <= 0) ? DEFAULT_PRICE : figurinePrice;
	}
	ostream& Figurine::display() const {
		if (isEmpty())
			cout << "This Figurine has not yet been sculpted" << endl;
		else
		{
			cout << "Figurine Details" << endl;
			cout << "Name: " << f_name << endl;
			cout << "Pose: " << f_pose << endl;
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Price: " << f_price << endl;

		}
		return cout;

	}

	Figurine::operator bool() const {
		return (f_name == nullptr || f_name[0] == '\0');
	}
}
