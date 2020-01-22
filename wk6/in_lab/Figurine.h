// Figurine.h

#ifndef SDDS_FIGURINE_H__
#define SDDS_FIGURINE_H__
namespace sdds
{
	const int MAX_NAME_LEN = 20;
	const double DEFAULT_PRICE = 25.25;

	class Figurine
	{
		char f_name[MAX_NAME_LEN + 1];
		char* f_pose;
		double f_price;
		bool f_copy;
	public:
		Figurine();
		Figurine(const Figurine& inputFigurine);
		Figurine(const char* m_name, const char* m_pose, double m_pricea);
		~Figurine();
		bool isEmpty()const;
		void setEmpty();
		void setName(const char*);
		void setPose(const char*);
		void setPrice(double);
		std::ostream& display() const;
		operator bool() const;
		Figurine& operator=(const Figurine&);
		bool isCopy() const;
	};
	bool operator==(const Figurine&, const Figurine&);

}
#endif