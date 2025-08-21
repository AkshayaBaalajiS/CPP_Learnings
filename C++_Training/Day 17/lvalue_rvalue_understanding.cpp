#include<iostream>
using namespace std ;

void function(int & ref )
{
	cout<<"void function(int & ref  )    : " << "\n";
	
}

void function(int && ref  )
{
	cout<<"void function(int && ref  )    : " << "\n";
}

int main()
{
	int a =10;
	function(a);
	cout<<"...............\n";
	function(10);
	cout<<"...............\n";
	function(a + 123);
	cout<<"...............\n";
	function(std::move(a)) ; //move semantics 
}
