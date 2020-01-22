// Calculator.h
// WS09 in-lab
#ifndef _CALCULATOR_H__
#define _CALCULATOR_H__
#include<iostream>
#include<string>
using namespace std;
namespace sdds {
	template<class T, int N>
	class Calculator
	{
	public:
		Calculator() {
			for (int i = 0; i < N; i++)
			{
				results[i] = { 0 };
			}			
		}
		void add(const T* arr1, const T* arr2) {
			for (int i = 0; i < N; i++)
			{
				results[i] = arr1[i] + arr2[i];
			}
		}
		void subtract(const T* arr1, const T* arr2) {
			for (int i = 0; i < N; i++)
			{
				results[i] = arr1[i] - arr2[i];
			}
		}
		void multiply(const T* arr1, const T* arr2) {
			for (int i = 0; i < N; i++)
			{
				results[i] = arr1[i] * arr2[i];
			}
		}
		void divide(const T* arr1, const T* arr2) {
			for (int i = 0; i < N; i++)
			{
				results[i] = arr1[i] / arr2[i];
			}
		}
		Calculator& operator+=(const T* arr1) {
			for (int i = 0; i < N; i++)
			{
				results[i] = arr1[i] + results[i];
			}
			return *this;
		}
		Calculator& operator-=(const T* arr1) {
			for (int i = 0; i < N; i++)
			{
				results[i] = results[i] - arr1[i];
			}
			return *this;
		}
		Calculator& operator*=(const T* arr1) {
			for (int i = 0; i < N; i++)
			{
				results[i] = arr1[i] * results[i];
			}
			return *this;
		}
		Calculator& operator/=(const T* arr1) {
			for (int i = 0; i < N; i++)
			{
				results[i] = results[i] / arr1[i];
			}
			return *this;
		}
		std::ostream& display(std::ostream& os) const {
			int count = 0;
			for (int i = 0; i < N; i++)
			{
				os << results[i];
				count++;
				if (count < N)
				{
					os << ",";
				}
			}
			
			
			os << std::endl;
			return os;
		}
	private:
		T results[N];
	};
}
#endif // !_CALCULATOR_H__