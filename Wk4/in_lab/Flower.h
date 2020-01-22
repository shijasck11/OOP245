#include <iostream>
namespace sdds {
	class Flower
	{
		const int NAME_MAX_LEN = 25;
		const int COL_MAX_LEN = 15;

	public:
		Flower();
		~Flower();
		Flower(const char* name, const char* colour, double price);

		//rest
		const char* name()const;
		const char* colour()const;
		double price()const;
		bool isEmpty()const;
		void setEmpty();
		void setName(const char* prompt);
		void setColour(const char* prompt);
		void setPrice(const char* prompt);
		std::ostream& display() const;
		void setFlower();

		

	private:
		char* f_name;
		char* f_colour;
		double f_price;
		
	};

}