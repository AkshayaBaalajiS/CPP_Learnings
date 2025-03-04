#include<iostream>
using namespace std;
void function(int *ptr , int a)
{
	if(ptr == NULL)
	{
		throw(ptr);
//		throw(ptr);	
	}
	else
	{
		throw(a);
//		cout<<"ptr = " <<  ptr << "\n";
//		cout<<"arg1 = " << a <<"\n";
	}
}

int main()
{
	int a=10;
	try
	{
		function(&a,10);
	}
	catch(...)
	{
		cout<<"Any type of error will be caught here ...\n";
		cout<<"The error is in int * \n"; 
		
	}
} 
