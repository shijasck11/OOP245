#include <iostream>
#ifndef NAMESPACE_MARKSREPORT_H__
#define NAMESPACE_MARKSREPORT_H__
namespace sdds
{
	class MarksReport
	{
	public:
		void initialize();
		int getMarks();
		void print();
		void terminate();

	private:
		char reportname;
	};

	
}
#endif