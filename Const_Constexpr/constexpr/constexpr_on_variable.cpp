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

int main()
{
	cout<<"This is the program to understand the constexpr in CPP\n";
	constexpr int a =123;
	// constexpr A * ptr = new A(); // cant be assigned with new cause the new get memory at runtime 
	/*
	constexpr requires compile-time evaluation

	A constexpr variable must be fully evaluatable at compile time

	new A() // allocates memory at runtime, not compile time.
	*/
	constexpr int b = a+23;

	int c =234;
	// constexpr int d = b+ c; // the value of ‘c’ is not usable in a constant expression
}