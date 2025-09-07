#include <iostream>
using namespace std;

#ifndef SQUARE
double square_function(int a)
{
	return a*a;
}
#endif

int main()
{
	cout<<"This is the program to understand the ifndef in C++ \n";

	int number_1 = square_function(23);

	cout<<"Square of 23 = " << number_1 <<endl;
}