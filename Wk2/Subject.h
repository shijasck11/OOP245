#ifndef NAMESPACE_SUBJECT_H__
#define NAMESPACE_SUBJECT_H__
namespace sdds {
	struct Subject
	{
		int* m_noOfSections;
		int* m_noOfStdsInSecs;
		char* m_subjectName;
	};
	
	void read(Subject& Sub);
	void freeMem(Subject& Subject);
	int report(const Subject& Sub);


}
#endif
