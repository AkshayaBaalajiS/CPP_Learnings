#include <iostream>
using namespace std;

class A
{
	public :
		A();
		virtual ~A();
		virtual void print();
		virtual void function()=0;
};

class B: public A
{
	public :
		B()
		{
			cout<<"@ B class constructor \n";
		}
		void print() override 
		{
			cout<<"@ B class void print() function \n";
		}
		void function() override 
		{
			cout<<"@ B class void print() function \n";
			A::function();
		}
		
		~B()
		{
			cout<<"@ B class destructor \n";
		}
};