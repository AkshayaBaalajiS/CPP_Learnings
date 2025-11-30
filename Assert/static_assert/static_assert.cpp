#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class A 
{	
	static_assert(sizeof(T)>4); // if false error on compile time 
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
	// A<char> obj;
	A<double> obj;
}