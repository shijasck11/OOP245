#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Mark.h"

using namespace std;
namespace sdds
{
	void Mark::flushKeyboard()const {
		while (cin.get() != '\n');
	}

	void Mark::set(int displayMode) {
		m_displayMode = displayMode;
	}

	void Mark::set(double mark, int outOf) {
		m_mark = mark;
		m_outOf = outOf;
	}

	void Mark::setEmpty() {
		m_displayMode = DSP_UNDEFINED;
		m_mark = -1;
		m_outOf = 100;
		m_name[0] = 0;

	}

	bool Mark::isEmpty()const {
		if (m_mark == -1 || m_name[0] == -1)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	int Mark::percent()const {
		return (((m_mark / m_outOf) * 100) + 0.5);
	}

	double Mark::rawValue()const {
		return m_mark / m_outOf;
	}

	bool Mark::read(const char* prompt) {
		bool success = true;
		cout << prompt;
		cin >> m_mark;
		cin.ignore();
		cin >> m_outOf;
		if (cin.fail())
		{
			cin.clear();
			setEmpty();
			success = false;
		}
		flushKeyboard();
		return success;
	}

	ostream& Mark::display(int width)const {
		if (m_mark == -1 || m_name[0] == -1)
		{
			cout << "Empty Mark object!";
		}
		else
		{
			if (width == 30 || width == 60) {
				cout.width(width);
				cout.fill('.');
				cout.setf(ios::left);
			}

			cout << m_name;

			switch (m_displayMode)
			{
			case DSP_RAW:
				cout << setprecision(2) << fixed << rawValue();
				break;
			case DSP_PERCENT:
				cout << "%" << percent();
				break;
			case DSP_ASIS:
				cout << setprecision(1) << fixed << m_mark;
				cout << "/" << m_outOf;
				break;
			case DSP_UNDEFINED:
				cout << "Display mode not set!";
				break;
			case DSP_LETTER:
				if (GPA() > 4)
				{
					cout << "?";
				}
				else
				{
					prnLetter();
				}
				
				break;
			case DSP_GPA:
				cout << setprecision(1) << fixed << GPA();
				
				break;
			default:
				cout << "Invalid Mark Display setting!";
				break;
			}
		}
		return cout;
	}



	void Mark::prnLetter()const {
		if (!isEmpty())
		{
			if ((percent() >= 90) && (percent() <= 100))
			{
				cout << "A+";
			}
			else if ((percent() >= 80) && (percent() <= 89))
			{
				cout << "A";
			}
			else if ((percent() >= 75) && (percent() <= 79))
			{
				cout << "B+";
			}
			else if ((percent() >= 70) && (percent() <= 74))
			{
				cout << "B";
			}
			else if ((percent() >= 65) && (percent() <= 69))
			{
				cout << "C+";
			}
			else if ((percent() >= 60) && (percent() <= 64))
			{
				cout << "C";
			}
			else if ((percent() >= 55) && (percent() <= 59))
			{
				cout << "D+";
			}
			else if ((percent() >= 50) && (percent() <= 54))
			{
				cout << "D";
			}
			else if ((percent() >= 0) && (percent() <= 49))
			{
				cout << "F";
			}
		}
	}
	void Mark::set(const char* name) {
		int len = strlen(name);
		strncpy(m_name, name, MAX_NAME);
		if (len >= 50)
		{
			m_name[50] = '\0';
		}
		else
		{
			m_name[len] = '\0';
		}

	}

	void Mark::set(const char* name, double rawMark, int outof) {
		set(name);
		set(rawMark, outof);
	}

	bool Mark::readName(const char* prompt, int maxLen) {
		cout << prompt;
		cin >> m_name;
		int len = strlen(m_name);
		if (len > maxLen)
		{
			cin.clear();
			flushKeyboard();
			setEmpty();
			return false;
		}
		return true;
	}

	void Mark::changeOutOf(int value) {
		m_mark = m_mark * (double(value) / m_outOf);
		m_outOf = value;
		if (m_outOf < 1)
		{
			setEmpty();
		}
	}

	double Mark::GPA()const {
		return rawValue() * 4;
	}

	double Mark::letterBasedGPA()const {
		if ((percent() > 100)) return 4.5;
		if ((percent() >= 90) && (percent() <= 100))
		{
			return 4.0;
		}
		else if ((percent() >= 80) && (percent() <= 89))
		{
			return 4.0;
		}
		else if ((percent() >= 75) && (percent() <= 79))
		{
			return 3.5;
		}
		else if ((percent() >= 70) && (percent() <= 74))
		{
			return 3.0;
		}
		else if ((percent() >= 65) && (percent() <= 69))
		{
			return 2.5;
		}
		else if ((percent() >= 60) && (percent() <= 64))
		{
			return 2.0;
		}
		else if ((percent() >= 55) && (percent() <= 59))
		{
			return 1.5;
		}
		else if ((percent() >= 50) && (percent() <= 54))
		{
			return 1.0;
		}
		else
		{
			return 0.0;
		}
	}


}