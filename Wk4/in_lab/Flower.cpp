#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Flower.h"
#include "utils.h"
#include <cstring>
using namespace std;

namespace sdds {
	Flower::Flower() {
		setEmpty();
	}
	Flower::Flower(const char* name, const char* color, double price) {
		bool validName = name != nullptr && name != "";
		bool validColor = color != nullptr && color != "";
		bool validPrice = price > 0;

		if (validName && validColor && validPrice) {
			//create memory for name and color
			f_name = new char[strlen(name)+1];
			strcpy(f_name, name);
			f_colour = new char[strlen(name)+1];
			strcpy(f_colour, name);
			f_price = price;
		}
		else {
			setEmpty();
		}
	}
	Flower::~Flower() {
		
		bool emptyFlower = isEmpty();
		if (emptyFlower) {
			cout << "An unknown flower has departed..." << endl;
		}
		else {
			cout << f_name << " " << f_colour << " has departed..." << endl;
		}
		delete[] f_name;
		delete[] f_colour;
	}


	const char* Flower::name() const {
		return f_name;
	}
	const char* Flower::colour() const {
		return f_colour;
	}
	double Flower::price()const {
		return f_price;
	}
	bool Flower::isEmpty()const{
		bool empty = false;
		if (f_name==nullptr) {
			empty = true;
		}
		return empty;
	}
	void Flower::setEmpty(){
		f_name = nullptr;
		f_colour = nullptr;
		f_price = 0;
	}
	void Flower::setName(const char* prompt){
		
		char temp[NAME_MAX_LEN+1];
		cout << prompt;
		read(temp, NAME_MAX_LEN, "A flower's name is limited to 25 characters... Try again: ");
		f_name = new char[strlen(temp) + 1];
		strcpy(f_name, temp);
	}
	void Flower::setColour(const char* prompt){
		char temp[COL_MAX_LEN + 1];
		cout << prompt;
		read(temp, COL_MAX_LEN, "A flower's colour is limited to 15 characters... Try again: ");
		f_name = new char[strlen(temp) + 1];
		strcpy(f_name, temp);
	}
	void Flower::setPrice(const char* prompt){
		cout << prompt;
		readprice(f_price, 0, "A flower's price is a non-negative number... Try again: ");
	}
	void Flower::setFlower(){
		setName("Enter the flower's name... : ");
		setColour("Enter the flowe's colour... : ");
		setPrice("Enter the flower's price... : ");
	}
	ostream& Flower::display() const{
		if (isEmpty()) {
			cout << "This is an empty flower..."<<endl;
		}
		else {
			cout << "Flower: " << f_colour << " " << f_name << "Price: " << f_price << endl; 
		}

		return cout;
	}
	

}