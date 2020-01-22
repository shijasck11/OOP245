#include <iostream>
#include <cstring>
#include "Subject.h"
#include "utils.h"
using namespace std;

namespace sdds {


	void read(char* m_subjectName) {
		cout << "Enter subject name: " ;
		read(m_subjectName, 70, "Name is too long, only 70 characters allowed!\nRedo Entry: ");

	}

	void read(int& m_noOfSections) {
		cout << "Enter number of sections: ";
		read(m_noOfSections, 1, 10, "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ");
	}

	void read(int nos[], int m_noOfStdsInSecs) {
		cout << "Enter the number of students in each one of the " << m_noOfStdsInSecs << " sections: ";
		cin >> m_noOfStdsInSecs;
		int i;
		for (i = 0; i < nos[m_noOfStdsInSecs]; i++) {
			read(m_noOfStdsInSecs, 5, 35, "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ");
		}
	}

	void read(Subject& Sub) {
		char readloc[71];
		read(readloc);
		Sub.m_subjectName = new char[strlen(readloc) + 1];
		strcpy(Sub.m_subjectName, readloc);


		Sub.m_noOfSections = new int;
		read(*Sub.m_noOfSections);


		Sub.m_noOfStdsInSecs = new int[*Sub.m_noOfSections];
		read(Sub.m_noOfStdsInSecs, *Sub.m_noOfSections);
	}

	int report(const Subject& Sub) {
		int total = 0;
		for (int i = 0; i < *Sub.m_noOfSections; i++) {
			cout << Sub.m_noOfStdsInSecs[i];
			total = total + Sub.m_noOfStdsInSecs[i];
			if (i < *Sub.m_noOfSections - 1) {
				cout << ", ";
			}
		}
		cout << "\n" << Sub.m_subjectName << ":" << total << endl;
		return total;
	}

	void freeMem(Subject& Sub) {
		delete Sub.m_noOfSections;                    // Deleting the Subject member number of sections dynamic memory
		delete[] Sub.m_noOfStdsInSecs;                  // Deleting the Subjects number of students in Sections dynamic memory
		delete[] Sub.m_subjectName;                     // Deleting the Subject member name's dynamic memory
	}

}
