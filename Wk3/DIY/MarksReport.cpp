#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "MarksReport.h"
using namespace std;
namespace sdds
{
	
		void MarksReport::initialize() {
			n_mark = N_UNDEFINED;
			subname[0] = 0;
			gpa = 0;
		}

		int MarksReport::getMarks() {
			cout << "Enter the report Name: " << endl;
			cin >> reportname;
			cout << "Enter the number of marks: " << endl;;
			cin >> nom;
			int i;
			for ( i = 0; i < nom; i++)
			{
				cout <<i+1 << ": Subject Name: ";
				cin >> subname; 
				cout << endl<< "Mark (mark/outof): ";
				cin >> n_mark;
			}
			cout << endl << "Entry Completed!";
		}

		void MarksReport::print() {
			cout << reportname << endl;
			cout << "----------------------------------------------------------------------" << endl;
			cout << "Marks entered:" << endl;
			cout << subname << cout.width(60) << cout.fill('.') << endl;
			cout << subname << cout.width(60) << cout.fill('.') << endl;
			cout << subname << cout.width(60) << cout.fill('.') << endl;
			cout << "----------------------------------------------------------------------" << endl;
		}

	
}

