#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program to understand the pointer in cpp \n";
	int number =43;

	int * ptr = &number; 
	int * ptr_1  = ptr ;

	cout<<"Number = " << number <<"  Address =   " << &number <<endl; 
	cout<<"Pointer = " << *ptr << " Address   = " << ptr  <<endl;
	cout<<"Pointer_1= " << *ptr_1 << " Address   = " << ptr_1  <<endl;

	// Reference 

	int & ref = number ; // this work like int * const // value can be changed addresss cant be changed and the value change affect the original  

	cout<<"Reference = " << ref  << " NUmber = " << number <<endl; 

	cout<<"Changing reference value \n";

	ref = 23;

	cout<<"--------------------------------------------------\n";
	cout<<"Number = " << number <<"  Address =   " << &number <<endl; 
	cout<<"Pointer = " << *ptr << " Address   = " << ptr  <<endl;
	cout<<"Pointer_1= " << *ptr_1 << " Address   = " << ptr_1  <<endl;
	cout<<"Reference = " << ref  << " NUmber = " << number <<endl;
	cout<<"--------------------------------------------------\n";

	cout<<"Assigning the pointer to a const int * \n";

	const int * cPtr_1 = const_cast<const int *>(ptr);
	cout<<"Const POinter = " << cPtr_1 << " " << " NUmber = " << number << "  Pointer = " << *ptr <<endl;

	number =98;
	cout<<"Changing the value of the number and checking it affect the const pointer \n";
	cout<<"--------------------------------------------------\n";
	cout<<"Number = " << number <<"  Address =   " << &number <<endl; 
	cout<<"Pointer = " << *ptr << " Address   = " << ptr  <<endl;
	cout<<"Pointer_1= " << *ptr_1 << " Address   = " << ptr_1  <<endl;
	cout<<"Reference = " << ref  << " NUmber = " << number <<endl;
	cout<<"Const POinter = " << cPtr_1 << " " << " NUmber = " << number << "  Pointer = " << *ptr <<endl;
	cout<<"--------------------------------------------------\n";


	cout<<"Changing the value of the number and checking it affect the const pointer \n";
	// *cPtr_1 = 34; // this cant be done cause "assignment of read-only location ‘* cPtr_1’ "
	cout<<"--------------------------------------------------\n";
	cout<<"Number = " << number <<"  Address =   " << &number <<endl; 
	cout<<"Pointer = " << *ptr << " Address   = " << ptr  <<endl;
	cout<<"Pointer_1= " << *ptr_1 << " Address   = " << ptr_1  <<endl;
	cout<<"Reference = " << ref  << " NUmber = " << number <<endl;
	cout<<"Const POinter = " << cPtr_1 << " " << " NUmber = " << number << "  Pointer = " << *ptr <<endl;
	cout<<"--------------------------------------------------\n";

	
}