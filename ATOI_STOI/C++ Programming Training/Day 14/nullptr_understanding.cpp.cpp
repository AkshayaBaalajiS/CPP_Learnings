#include<iostream>
using namespace std ;

namespace Group1
{
	void add_find(int * ptr )
	{
		cout<<"ptr hold : " << ptr   << " address is   " << &ptr  << " value it hold :   " << *ptr  <<"\n";
	}
	/*
	//Commenting this out to understand the NULL as argument 
	void add_find(char  * ptr )
	{
		cout<<"ptr hold : " << ptr   << " address is   " << &ptr <<"\n";
	}*/
	void add_find(int ptr )
	{
		cout<<"ptr hold : " << ptr   << " address is   " << &ptr <<"\n";
	}
	
	void main()
	{
		cout<<"Group1::main     : " << "\n";
		int i=10;
		char arr[] = "AB";
		
		cout<<"-------------------\n";
		add_find(&i);
//		cout<<"-------------------\n";
//		add_find(arr);
		cout<<"-------------------\n";
		add_find(i);
		cout<<"-------------------\n";
//		add_find(NULL);  // this will create error so we use the nullptr 
		add_find(nullptr);
//	if a pointer is nullptr it cant be dereferenced 
	
	}
	
}
int main()
{
	Group1::main();
	
}