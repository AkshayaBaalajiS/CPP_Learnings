#include <iostream>
using namespace std;

int * func()
{
	int x =10;
	return &x;
}

static int * func1()
{
	int x =10;
	return &x;
}

int * func2()
{
	static int x =10;
	return &x;
}

int main()
{
	cout<<"This is the program to understand the dangling pointer in cpp \n";
	int * ptr = func2();
	cout<<"*ptr = " << *ptr <<endl;
}