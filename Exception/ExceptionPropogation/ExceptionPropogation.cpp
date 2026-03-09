#include <iostream>
using namespace std;

void function1()
{
	throw(234);
	// throw std::runtime_error("fail");
}

int main()
{
	cout<<"Exception Propogation in cpp\n";
	try
	{
		function1();
	}
	// oder of the catch should be proper 
	catch(const int & e)
	{
		cout<<"Exception caught here :" <<e <<endl;
	}
	catch(const std::exception & e)
	{
		cout<<e.what() <<endl;
	}
	catch(...)
	{
		cout<<"Exception caught here " <<endl;
	}
	
}