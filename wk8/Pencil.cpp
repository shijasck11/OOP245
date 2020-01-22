#include "Pencil.h"
namespace sdds
{
	Pencil::Pencil() {
		*HB_scale = 0;
		graphite = 0;
	}

	Pencil::Pencil(const char* HB, int grp) {
		if (HB == nullptr || strcmp(HB, "") == 0) {
			*HB_scale = 0;
			graphite = 0;
		}
		else {
			strncpy(HB_scale, HB, HB_MAX + 1);
		}
		if (grp < 1 || grp > 100) {
			graphite = GRAPHITE_MAX;
		}
		else {
			graphite = grp;
		}
	}

	void Pencil::write(const char* HB) {
		if (graphite > 0) {
			int space = 0;
			int used = 0;
			int len = strlen(HB);
			cout << "Writing out the following: " << HB << " with a Pencil!" << endl;
			for (int i = 0; i < len; i++) {
				if (HB[i] == ' ') {
					space++;
				}
			}
			used = space * 5;
			graphite -= used;
			if (graphite < 0) {
				graphite = 0;
			}
		}
		else {
			cout << "We can't write without graphite!" << endl;
		}
	}

	void Pencil::refill(int grp) {
		graphite += grp;
		if (graphite > GRAPHITE_MAX) {
			graphite = GRAPHITE_MAX;
		}
		cout << "Refilling the pencil with graphite" << endl;
	}

	bool Pencil::filled() const {
		return graphite > 0;
	}

	ostream& Pencil::display(ostream& os) const {
		if (*HB_scale != 0) {
			os << "Pencil Details" << endl;
			os << "HB Value: " << HB_scale << endl;
			os << "Graphite Remaining: " << graphite << endl;
		}
		else {
			os << "This is an empty Pencil" << endl;
		}
		return os;
	}
}