#include<iostream>
using namespace std;
void function(int *ptr , int a)
{
	if(ptr == NULL )
	{
		try
		{
//			int b =12/0;
			int b=10;
			cout<<"b= " << b <<"\n";
			throw(12);
		}
		catch(int a)
		{
			cout<<"catch with elipses inside the function ..."<<a<<"\n";
			throw(12);
		}
//		throw(ptr);	
	}
	else
	{
		cout<<"ptr = " <<  ptr << "\n";
		cout<<"arg1 = " << a <<"\n";
	}
}

int main()
{
	int a=10;
	try
	{
		function(NULL,10);
	}
	catch(int b)
	{
		cout<<"Any type of error will be caught here ...\n";
		cout<<"The error is in int * "<<b<<"\n"; 
		
	}
} 
