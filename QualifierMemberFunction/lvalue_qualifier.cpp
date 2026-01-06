#include <iostream>
using namespace std;

class A
{
	public :
		A()
		{
			cout<<"@ A class constructor \n";
		}

		void function() & // this is lvalue qualifier 
		{
			cout<<"void function() & \n";
		}

		void function1() 
		{
			cout<<"void function1() \n";
		}

		~A()
		{
			cout<<"@ A class destructor \n";
		}
};

int main()
{
	cout<<"@ Lvalue specifier \n";
	A obj;
	obj.function();
	// A::function(); // this cant be called cause the function1 will be having the this as arg 
	// A::function1(); // this cant be called cause the function1 will be having the this as arg 
}