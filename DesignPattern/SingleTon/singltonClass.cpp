#include <iostream>
#include <memory>
using namespace std;

class Base
{
	Base(): a(12)
	{
		cout<<"Base class constructor \n";
	}

	~Base()
	{
		cout<<"Base class destructor\n";
	}	
	public :
	int a ;
		static Base * baseInstance() //  usually named as getInstance
		{
			return (new Base());
		}
		friend ostream & operator<< (ostream& out, Base & ref)
		{
			out<<"Base Object  = " << ref.a << endl;
			return out; 
		}	
};

// class Derived : public Base // cant derive a class with private constructor 
class Derived 
{
	public :
		Derived()
		{
			cout<<"Derived class constructor\n";
		}
		
		~Derived()
		{
			cout<<"Derived class destructor\n";
		}

};

int main()
{
	cout<<"This is the program to practice the weakPtr in cpp\n";
	Base * ptr =  Base::baseInstance();
	cout<<"*ptr = " << *ptr;
}	