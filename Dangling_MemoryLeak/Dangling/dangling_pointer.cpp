#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program to understand the Dangling pointer in cpp \n";

	int * ptr = new int;
	*ptr = 234;
	cout<<"*ptr = " << *ptr <<endl;
	int * pptr = ptr ;
	cout<<"----- before deletion ------ \n";
	cout<<"ptr = " << ptr <<endl;
	cout<<"*ptr = " << *ptr <<endl;
	cout<<"pptr = " << pptr <<endl;
	cout<<"*pptr = " << *pptr <<endl;
	cout<<"----- ------- ------ \n";

	delete ptr;
	// correct prac is after deletion we have to null the pointer deleted 
	ptr = nullptr;

	cout<<"----- After deletion ------ \n";
	cout<<"ptr = " << ptr <<endl;
	cout<<"*ptr = " << *ptr <<endl;
	cout<<"pptr = " << pptr <<endl;
	cout<<"*pptr = " << *pptr <<endl; // become dangling 
	cout<<"----- ------- ------ \n";




}