#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the code to understand the dangling ptr in cpp\n";
	int * ptr = new int[10]; // ptr is assigned with int of 10 ele 
	delete ptr; // mem got freed 

	// below line is undefined behaviour 
	cout<<"*ptr = " << *ptr <<endl; // using the pointer after a delete or memory free is dangling pointer that dangling ptr is not pointing to anywhere 
	// so we need to do nullptr once after delete 
	ptr = nullptr;
}