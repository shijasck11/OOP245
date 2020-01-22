#ifndef SDDS_PEN_H
#define SDDS_PEN_H
#include "WriteInstrument.h"

namespace sdds
{
#define INK_MAX 50

	class Pen : public WriteInstrument
	{
	private:
		char* style;
		int ink;
	public:
		Pen();
		Pen(const char*, int);
		~Pen();
		void write(const char*);
		void refill(int);
		bool filled() const;
		ostream& display(ostream& os) const;
	};
}

#endif