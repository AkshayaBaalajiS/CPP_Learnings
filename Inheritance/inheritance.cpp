#include <iostream>
using namespace std;

class A
{
	public:
		A()
		{
			cout<<"A class constructor \n";
		}

		~A()
		{
			cout<<"A class destructor \n";
		}
};

class B : public A 
{ 
	public:
		B()
		{
			cout<<"B class constructor \n";
		}

		~B()
		{
			cout<<"B class destructor \n";
		}
};



int main()
{
	cout<<" Single Inheritance code \n";
	
}