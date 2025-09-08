#include <iostream>
using namespace std;

#define square_function(a) (a*a)

#ifndef square_function
double square_function(int a)
{
	cout<<"@double square_function(int a) \n";s

	return a*a;
}
#endif

int main()
{
	cout<<"This is the program to understand the ifndef in C++ \n";

	int number_1 = square_function(23);
	// here the macro is used not the function cause the macro is defined and the function is not used 

	cout<<"Square of 23 = " << number_1 <<endl;
}