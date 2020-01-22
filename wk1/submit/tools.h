#ifndef NAMESPACE_TOOLS_H__
#define NAMESPACE_TOOLS_H__
namespace sdds {
	int menu(int noOfSamples);
	void goBack(int n);
	void line(int n, const char* label = nullptr);
	int getInt(int min, int max);
}
#endif