#include <iostream>
using namespace std;

class A 
{
	public:
		A()
		{
			cout<<"@ A class constructor\n";
		}
		explicit A(int a)
		{
			cout<<"@ A class constructor\n";
		}
};


class B 
{
	public:
		B()
		{
			cout<<"@ B class constructor\n";
		}
		 B(int a)
		{
			cout<<"@ B class constructor\n";
		}
};


int main()
{
	cout<<"Explicit conversion \n";
	// A obj = 10;// error implicit conversion not possible 
	/*
	 conversion from ‘int’ to non-scalar type ‘A’
	*/
	B obj1 = 10; // this can be done cause the explicit is not mentioned 

	A obj = A(10);
	// this is the explicit converted version of the line 21 

}	

/*

Implicit Conversion mean :
	COmpiler convert insteead of we coonvert ;

*/