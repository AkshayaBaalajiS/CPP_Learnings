#include <iostream>
using namespace std;

int globalNum=12;

int function(int number)
{
	if(number==0)
	{
		throw("Number = 0 so division cant be done "); 
	}
	return globalNum/=number;
}

int main()
{
	cout<<"This is the program to understand the error code in cpp\n";

	int number = 0;
	try
	{
		function(number); 
	}
	catch(const char * ptr)
	{
		cout<<"Error caught : " << ptr <<endl;
	}
	catch(std::exception & e)
	{
		cout<<"[main] error = " << e.what() <<endl;
 	}
 	catch(...)
 	{
 		cout<<"Error raised so throw called in code \n";
 	}
}