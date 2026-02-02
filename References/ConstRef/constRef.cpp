#include <iostream>
using namespace std;

int main()
{
	cout<<"Reference vs const reference \n";
	int number = 10;
	cout<<"Number = " <<number <<endl;
	int & ref = number;
	cout<<"ref = " <<ref <<endl;

	// int & ref2 =12; // this cant be done cause the ref need lvaue and we arew giving prvalue 
	const int & ref2 = 234; // this can be done cause the const with the refernce can accept the prvalue 

	cout<<"ref2 = " <<ref2 <<endl;
	// ref2 = number; // error read only obj
	// cout<<"ref2 = " <<ref2 <<endl;

}