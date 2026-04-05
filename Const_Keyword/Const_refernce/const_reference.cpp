#include <iostream>

using namespace std;

int gnumber =234;

void funct(const int & ref)
{
	// ref =234; // this cant be done cause ref is read only reference 
	
}

int main()
{
	cout<<"This is the code to understand the const refernce in cpp \n";
	int number  =243;
	cout<<"number = " << number <<endl;

	funct(number);
	cout<<"After funct call \n";
	cout<<"number = " << number <<endl;

	// int & ref = 234; this cant be done 
	const int & ref = 324 ; // this can be done with help of const 
}
// const on refernce does not allow the variable to be changed 
// why const reference ?
	// the const reference avoid unnecessary copy of that variable 
	// when we are working with STL it is imp that the copy of the STL is heavy and mem issues 