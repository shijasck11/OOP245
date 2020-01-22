#include <iostream>
#ifndef NAMESPACE_MARK_H__
#define NAMESPACE_MARK_H__
namespace sdds
{
	const int DSP_RAW = 1;
	const int DSP_PERCENT = 2;
	const int DSP_ASIS = 3;
	const int DSP_UNDEFINED = -1;
	const int DSP_GPA = 4;
	const int DSP_LETTER = 5;
	const int MAX_NAME = 50;

	class Mark
	{
	public:
		void set(int displayMode);
		void set(double mark, int outOf = 1);
		void setEmpty();
		bool isEmpty()const;
		int percent()const;
		double rawValue()const;
		bool read(const char* prompt);
		std::ostream& display(int width = 55)const;
		void set(const char* name);
		void set(const char* name, double rawMark, int outof = 1);
		bool readName(const char* prompt, int maxLen = 50);
		void changeOutOf(int value);
		double GPA()const;
		double letterBasedGPA()const;



	private:
		int m_displayMode;
		double m_mark;
		int m_outOf;
		void flushKeyboard()const;
		char m_name[MAX_NAME+1];
		void prnLetter()const;
	};
}
#endif