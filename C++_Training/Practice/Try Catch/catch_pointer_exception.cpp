#include<iostream>
#include<stdexcept>
using namespace std;
void function(int *ptr , int a)
{
	if(ptr == NULL )
	{
		throw(ptr);
	}
	else
	{
		cout<<"ptr = " <<  ptr << "\n";
		cout<<"arg1 = " << a <<"\n";
	}
}

int main()
{
	try
	{
		function(NULL,10);
	}
	catch(int * ptr)
	{
		cout<<"The error is in int * \n"; 
	}
} 
