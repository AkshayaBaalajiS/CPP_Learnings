#include <iostream>
using namespace std;

class A 
{
	public :
		A()
		{
			cout<<"@ A class constructor \n";
		}
		void printFunction()
		{
			cout<<"@ A clss printFunction\n";
		}

		~A()
		{	
			cout<<"@ A class destructor \n";
		}
};

int main()
{
	cout<<"This is the program to understand the abstraction of a function in cpp\n";
	A obj ;
	obj.printFunction();	
	/*
		They don't know what's inside it — could be 1 line, could be 100 lines. They only know what it does, not how.
	*/
}