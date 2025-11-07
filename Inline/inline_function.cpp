#include <iostream>
using namespace std;

#define SQUARE(a) (a*a)
inline double square(double a)
{
	return a*a;
}
int main()
{
	cout<<"Inline function in C++ \n";
	int number1 = 21;

	int result = square(number1);
	cout<<"Result = " << result <<endl;

	int result_1 = SQUARE(23);
	cout<<"Result 1  = " << result_1 <<endl;
}