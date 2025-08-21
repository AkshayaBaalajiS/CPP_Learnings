#include <iostream>
using namespace std;

void reference_function(int & ref)
{
	ref = 34;
}

int main()
{
	cout<<"Reference understanding in C++\n";

	int number =12;
	int const * arr = new int [5];

	cout<<"arr = " << arr <<endl;
	cout<<"*arr = " << *arr <<endl;

	cout<<"NUmber =  " << number <<endl;

	// reference_function(&number); // this cant be done // reference only take value as input 
	reference_function(number); // reference should take address as input 

	cout<<"NUmber After call  =  " << number <<endl;
}