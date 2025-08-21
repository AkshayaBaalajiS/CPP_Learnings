//C++ program to demonstate property : If an exception is
// thrown and not caught anywhere, the program terminates
// abnormally in exception handling.
#include<iostream>
using namespace std ;
int main()
{
	try
	{
		cout<<"Inside the try .....\n";
		throw('a');
	}
	catch(int a )
	{
		cout<<"This wont be catched ...\n";
	}
}
