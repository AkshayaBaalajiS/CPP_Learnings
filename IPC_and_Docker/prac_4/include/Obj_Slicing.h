#include <iostream>
using namespace std;

class Base 
{
	public :
		Base()
		{
			cout<<"Base class constructor \n";
		}

		void print_something()
		{
			cout<<"This is the print stmt from the Base class print_function\n";
		}

		virtual void some_print()
		{
			cout<<"Some Print function definition from the Base class \n";
		}

		~Base()
		{
			cout<<"Base class destructor \n";
		}
};

class Derived : public Base 
{
	public :
		Derived()
		{
			cout<<"Derived class constructor \n";
		}

		void print_something()
		{
			cout<<"This is the print stmt from the Derived class print_function\n";
		}

		void some_print() override
		{
			cout<<"Some Print function definition from the Derived class \n";
		}

		~Derived()
		{
			cout<<"Derived class destructor \n";
		}
};