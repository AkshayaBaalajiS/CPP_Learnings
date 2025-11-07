#include <iostream>
using namespace std;

int main()
{
	cout<<"Reference understanding \n";

	int value = 234;
	cout<<"Value = " << value << " Address of value  " << &value <<endl;

	int & ref  = value ;
	cout<<"Reference = " << ref << " Address of ref  = " << &ref <<endl; // the address of ref will be same as val;

	// because of that when we change the ref the value get changed 
	ref =34;

	cout<<"After changing value of ref \n" << "Ref = " << ref << " value = " << value <<endl; 

}