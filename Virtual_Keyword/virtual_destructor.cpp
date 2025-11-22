#include <iostream>
using namespace std;
class Base 
{
	public :
		int data;
		void * ptr ;
		Base() : data(0), ptr(nullptr)
		{
			cout<<"@ base class Constructor \n";
		}
		virtual void function() = 0;
		virtual void function1()
		{
			cout<<"@ base class function 1\n";
		}
		// ~Base() // without virtual 
		virtual ~Base()
		{
			cout<<"@ Base class destructor \n";
		}
};

class Derived : public Base
{	
	public :
		Derived()
		{
			cout<<"@ Derived class Constructor \n";
		}
		void function1() override
		{
			cout<<"@ derived class function 1\n";
		}
		void function() override 
		{
			cout<<"@ derived class function\n";
		}

		/*
		Inside Derived::~Derived, compiler automatically inserts:

		Base::~Base();
		*/
		~Derived()
		{
			cout<<"@ Derived class destructor \n";
		}
};



int main()
{
	Base * ptr = new Derived();

	delete ptr; // Only Base class destructor called no derived class destructor called so use virtual on destuctor of base to call the derived and from derived base will be called again 
}
