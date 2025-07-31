#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program to understand the reference in C++\n";

	int a =10;

	int b=12;

	cout<<"The refernce value before change  ";
	int & ref =a;
	cout<<"A Val : "<<a <<"   B Val : "<<b << "  Ref : "<<ref <<endl;

	// the reference is the alias to a variable 
	// the reference cant be declared without the declaration 

	// the below line cause error 
	// int & ref_1;  // declared as reference but not initialized


	ref=b;

	cout<<"The refernce value after change  ";
	cout<<"A Val : "<<a <<"   B Val : "<<b << "  Ref : "<<ref <<endl;


	int storeResultOfReference = ref;// this cant be done cause the value of refernce cant be reassigned
	cout<<"The result is from the refernce is  : " << storeResultOfReference<<endl;
}