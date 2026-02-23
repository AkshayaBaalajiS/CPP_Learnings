#include <iostream>

using namespace std;

class A 
{
	public:
		A()
		{
			cout<<"A class constructor \n";
		}
		// if a function with noexcept throw 
		// void function() noexcept 
		// {
		// 	throw(12);
		// }

		void function()  
		{
			throw(12);
		}
		
		// ~A() noexcept
		// {
		// 	cout<<"A class destructor \n";
		// 	// throw (1);
		// }

		~A()  
		{
			cout<<"A class destructor \n";
			// throw (1);
		}
};

int main()
{
	cout<<"This is the program to understand the noexcept in cpp \n";

	A obj;
	try
	{
		obj.function();
	}
	catch(...)
	{
		cout<<"Catch caught \n";
	}
}