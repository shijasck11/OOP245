// Pen.cpp
#include "Pen.h"

namespace sdds
{
	Pen::Pen() {
		style = nullptr;
		ink = 0;
	}

	Pen::Pen(const char* f_style, int f_ink) {
		if (f_style == nullptr || strcmp(f_style, "") == 0) {
			style = nullptr;
			ink = 0;
		}
		else {
			int length = strlen(f_style);
			style = new char[length + 1];
			strncpy(style, f_style, length + 1);
		}
		if (f_ink < 1 || 1 > 50) {
			ink = INK_MAX;
		}
		else {
			ink = f_ink;
		}
	}

	Pen::~Pen() {
		delete[] style;
	}

	void Pen::write(const char* f_style) {
		if (ink > 0) {
			int i;
			int nospace = 0;
			int inkused = 0;
			int length = strlen(f_style);
			cout << "Writing out the following: " << f_style << " with a Pen!" << endl;
			for (i = 0; i < length; i++) {
				if (f_style[i] != ' ') {
					nospace++;
				}
			}
			inkused = nospace * 2;
			ink -= inkused;
			if (ink < 0) {
				ink = 0;
			}
		}
		else {
			cout << "We can't write without ink!" << endl;
		}
	}

	void Pen::refill(int f_ink) {
		ink += f_ink;
		if (ink > INK_MAX) {
			ink = INK_MAX;
		}
		cout << "Refilling the pen with ink" << endl;
	}

	bool Pen::filled() const {
		return ink > 0;
	}

	ostream& Pen::display(ostream& os) const {
		if (style == nullptr || strcmp(style, "") == 0) {
			os << "This is an empty Pen" << endl;
		}
		else {
			os << "Pen Details" << endl;
			os << "Style: " << style << endl;
			os << "Ink Remaining: " << ink << endl;
		}
		return os;
	}
}