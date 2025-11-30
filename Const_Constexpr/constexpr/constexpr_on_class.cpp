#include <iostream>
using namespace std;

class A
{
	public :
		A()
		{
			cout<<"@ A class constructor\n";
		}

		~A()
		{
			cout<<"@ A class destructor\n";
		}

};	

class B
{
	int a ;
	float b;
	char c;
	double d;
	public :
		constexpr B() : a(12), b(23.23f), c('2'), d(234.23423423)
		{
			// there should not be cout 
			// cout<<"@ B class constructor\n";
			// cout is a runtime operation
		}

		constexpr ~B()
		{
			// there should not be cout
			// cout<<"@ B class destructor\n"; // ❌ compile-time I/O → forbidden
			// cout is a runtime operation
		}

};	

int main()
{
	cout<<"This is the program to understand the constexpr on the class constructor \n";
	// constexpr A obj; // the type ‘const A’ of ‘constexpr’ variable ‘obj’ is not literal
	constexpr B bobj;
}	