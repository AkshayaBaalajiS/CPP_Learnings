#include <iostream>
using namespace std;

int globalNum=12;

int function(int number)
{
	if(number==0)
	{
		return -1; // error code to handle the error 
	}
	return globalNum/=number;
}

int main()
{
	cout<<"This is the program to understand the error code in cpp\n";

	int number = 0;
	if(function(number) != 1 )
	{
		cout<<"Output of the function = " << function(number) <<endl;
	}
	else
	{
		cout<<"Number = 0 " <<endl;
 	}
}