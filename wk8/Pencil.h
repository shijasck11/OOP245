// Pencil.h
#ifndef SDDS_PENCIL_H
#define SDDS_PENCIL_H
#include "WriteInstrument.h"

namespace sdds
{
#define HB_MAX 2
#define GRAPHITE_MAX 100

	class Pencil : public WriteInstrument
	{
	protected:
		char HB_scale[HB_MAX + 1];
		int graphite;
	public:
		Pencil();
		Pencil(const char* , int);
		void write(const char* );
		void refill(int);
		bool filled() const;
		ostream& display(ostream& os) const;
	};
}
#endif