#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the code to understand the reference vs pointer in cpp \n";
	int number = 234;
	int number1 = 123;
	cout<<"-------- reference ---------------- \n";

	int & ref = number ; 
	cout<<"ref = " << ref <<endl;
	cout<<"number = " << number <<endl;
	ref = 768;
	cout<<"\nAfter ref assigned to " << ref <<endl;
	cout<<"ref = " << ref <<endl;
	cout<<"number = " << number <<endl;

	// assigning of ref to another var 
	ref = number1;

	cout<<"\nAfter ref assigned to variabl2" << ref <<endl; // only the variable value is copied still the ref is pointing to the number  
	cout<<"ref = " << ref <<endl;
	cout<<"number = " << number <<endl;
	cout<<"number1 = " << number1 <<endl;

	cout<<"\nAddress printing " <<endl;
	cout<<"&ref = " << &ref <<endl;
	cout<<"&number = " << &number <<endl; // still the ref is pointing to number
	cout<<"&number1 = " << &number1 <<endl;
	cout<<"---------------------------------- \n";

	cout<<"-------- pointer ---------------- \n";
	int * ptr =  &number;
	cout<<"ptr = " << ptr <<endl;
	cout<<"number = " << number <<endl;
	*ptr = 768;
	cout<<"\nAfter ptr assigned to " << ptr <<endl;
	cout<<"*ptr = " << *ptr <<endl;
	cout<<"number = " << number <<endl;


	cout<<"\nAddress printing " <<endl;
	cout<< "ptr = " << ptr <<endl;
	cout<<"&number = " << &number <<endl; // still the ptr is pointing to number
	cout<<"&number1 = " << &number1 <<endl;
	
	// assigning of ptr to another var // changing the address 
	ptr = &number1;

	cout<<"\nAfter ptr assigned to variabl2 " << ptr <<endl; // only the variable value is copied still the ptr is pointing to the number  
	cout<<"*ptr = " << *ptr <<endl;
	cout<<"number = " << number <<endl;
	cout<<"number1 = " << number1 <<endl;

	cout<<"\nAddress printing " <<endl;
	cout<<"ptr = " << ptr <<endl;
	cout<<"&number = " << &number <<endl; // still the ptr is pointing to number
	cout<<"&number1 = " << &number1 <<endl;
	cout<<"---------------------------------- \n";

	cout<<"-------- reference from pointer ----------- \n";	
	// try to crease refernce frmo pointer 
	int & ref13 = *ptr ;
	cout<<"ref13 = " << ref13 <<endl;
	cout<<"---------------------------------- \n";
	
	
}