#include <iostream>
using namespace std;

class Base 
{
	public:
		Base()
		{
			cout<<"@ Base class constructor\n";
		}

		virtual void function() = 0 ; 

		void function1()
		{
			cout<<"BASE: void function1()\n";
		}

		virtual ~Base()
		{
			cout<<"@ Base class destructor \n";
		}
};

class Derived : public Base
{
	public:
		Derived()
		{
			cout<<"@ Derived class constructor\n";
		}

		void function() 
		{
			cout<<"DERIVED : void function() \n";
		}

		~Derived()
		{
			cout<<"@ Derived class destructor \n";
		}
};

int main()
{
	cout<<"This is the code to understand the virtual function \n";
	// Base obj; // obj cant be created it is abstract class 

	Base * ptr =  new Derived();
	ptr->function();
	ptr->function1();

}