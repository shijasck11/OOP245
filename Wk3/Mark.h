#include <iostream>
#ifndef NAMESPACE_MARK_H__
#define NAMESPACE_MARK_H__
namespace sdds
{
	const int DSP_RAW = 1;
	const int DSP_PERCENT = 2;
	const int DSP_ASIS = 3;
	const int DSP_UNDEFINED = -1;

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
		std::ostream & display() const;

	private:
		int m_displayMode;
		double m_mark;
		int m_outOf;
		void flushKeyboard()const;
	};
}
#endif