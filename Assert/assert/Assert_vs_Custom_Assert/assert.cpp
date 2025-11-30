#include <iostream>
#include <cassert>
using namespace std;

class A 
{
	public :
		int a ;
		char b;
		float c;
		double d;

		A() : a(1), b('1'), c(1.1f), d(1.111)
		{
			cout<<"@ A class constructor \n";
		}

		~A()
		{
			cout<<"@ A class destructor \n";
		}
};	

int main()
{
	cout<<"This s the code to understand the assert in code \n";
	A obj;
	assert(obj.a > 0);
	obj.a =-12;
	assert(obj.a > 0);	
}