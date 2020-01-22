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
		*f_name = 0;
		f_pose = nullptr;
		f_price = 0.0;
		f_copy = false;
	}
	Figurine::Figurine(const char* m_name, const char* m_pose, double m_price) {
		if ((m_name == nullptr) || (m_pose == nullptr))
			setEmpty();

		else
		{
			if (strlen(m_name) > MAX_NAME_LEN)
			{
				strncpy(f_name, m_name, MAX_NAME_LEN - 1);
			}
			else
			{
				strcpy(f_name, m_name);
			}
			f_pose = new char[strlen(m_pose) + 1];
			strcpy(f_pose, m_pose);
			if (m_price < 1)
			{
				f_price = DEFAULT_PRICE;
			}
			else
			{
				f_price = m_price;
			}
			f_copy = false;
		}
	}
	Figurine::Figurine(const Figurine& fig) {

		strcpy(f_name, fig.f_name);
		f_price = fig.f_price;
		f_copy = true;
		if (fig.f_pose == nullptr)
		{
			f_pose = nullptr;
		}
		else
		{
			f_pose = new char[strlen(fig.f_pose) + 1];
			strcpy(f_pose, fig.f_pose);
		}

	}
	Figurine::~Figurine() {
		delete[] f_pose;
	}
	bool Figurine::isEmpty() const {
		return (f_price <= 0 || f_pose == nullptr || f_name[0] == '\0' || f_copy == false);
	}
	void Figurine::setEmpty() {
		*f_name = 0;
		f_pose = nullptr;
		f_price = 0.0;
	}

	void Figurine::setName(const char* m_name) {
		if (strlen(m_name) > MAX_NAME_LEN)
		{
			strncpy(f_name, m_name, MAX_NAME_LEN);
		}
		else
		{
			strcpy(f_name, m_name);
		}
	}

	void Figurine::setPose(const char* m_pose) {

		delete[] f_pose;
		f_pose = nullptr;
		f_pose = new char[strlen(m_pose) + 1];
		strcpy(f_pose, m_pose);
	}
	void Figurine::setPrice(double m_price) {
		if (m_price < 1)
		{
			f_price = DEFAULT_PRICE;
		}
		else
		{
			f_price = m_price;
		}
	}
	ostream & Figurine::display() const {
		if (*f_name == 0 && f_pose == nullptr && f_price == 0.0){
			if (f_copy){
				cout << "This Figurine has not yet been sculpted" << endl << "This is a replica of emptiness" << endl;
			}
			else
			{
				cout << "This Figurine has not yet been sculpted" << endl;
			}
		}
		else
		{
			cout << "Figurine Details" << endl << "Name: " << f_name << endl << "Pose: " << f_pose << endl << "Price: ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << f_price << endl;
			if (f_copy)
			{
				cout << "This is a replica" << endl;
			}
		}
		return cout;
	}

	Figurine& Figurine::operator=(const Figurine& fig) {
		if (this != &fig)
		{
			strcpy(f_name, fig.f_name);
			f_price = fig.f_price;
			f_copy = true;
			if (fig.f_pose == nullptr)
			{
				f_pose = nullptr;
			}
			else
			{
				delete[] f_pose;
				f_pose = nullptr;
				f_pose = new char[strlen(fig.f_pose) + 1];
				strcpy(f_pose, fig.f_pose);
			}
		}
		return *this;
	}

	bool Figurine::isCopy() const
	{
		return f_copy;
	}

	const char* Figurine::name() const
	{
		return f_name;
	}

	const char* Figurine::pose() const
	{
		return f_pose;
	}

	double Figurine::price() const
	{
		return f_price;
	}

	Figurine::operator bool() const {
		 bool result;
    if (*f_name == 0)
    {
      result = true;
    }
    else
    {
      result = false;
    }
    return result;
	}

	bool operator==(const Figurine& f1, const Figurine& f2)
	{
		return strcmp(f1.name(), f2.name()) == 0 && strcmp(f1.pose(), f2.pose()) == 0 && f1.price() == f2.price() && !f1.isCopy() && !f2.isCopy();
	}
}
