#include "header.h"

int main()
{
	cout<<"This is a program to understand the inline variable usage in header file in C++\n ";
	cout<<"varInHeaderWithInline = " << varInHeaderWithInline<<endl;
	cout<<"varInHeader = " << varInHeader<<endl;
	
	A objectA ;
	cout<< "Printing object A  = " <<  objectA <<endl;
	
	B objectB ;
	cout<< "Printing object B  = " <<  objectB <<endl;

	// try changing the values of the variable
	varInHeaderWithInline = 234;
	// varInHeader = 235;  // the value of constexpr cant be changed 
	cout<<"varInHeaderWithInline = " << varInHeaderWithInline<<endl;
	cout<<"varInHeader = " << varInHeader<<endl;
	/*
	constexpr
	constexpr variables are implicitly const → you cannot modify them at runtime.
	Usage: Can be used in array sizes, template parameters, switch cases, etc.

	inline 
	An inline variable is just like a normal global variable, except it is ODR-safe
	you can change value at runtime 
	It can be initialized with something that isn’t known until runtime.
	*/

	
}	