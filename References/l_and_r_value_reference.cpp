#include <iostream>
using namespace std;

void function(int & ref ) // int & ref similar to int * const ref so it needs a address of a variable  
{
	cout<<"void function(int & ref ) is called \n";
	cout<<"Value = " << ref<<endl;
}

void function(int && ref )
{
	cout<<"void function(int && ref ) is called \n";
	cout<<"Value = " << ref<<endl;	
}

int main()
{
	int number = 23;

	function(number); // this will call the int & ref // number has a name and address 
	function(234); // this will call the int && ref // 234 has no name and it has no address 

	// l-value to r-value 

	function(std::move(number));

	// using rvalue to compute l value 

	int && rval = 34; // rval is an rvalue reference, but because it's named, it becomes an lvalue when used

	int someResult;
	someResult = number + rval ; // here rval is a r-value reference but it has a name so it works like a l-value reference 
	cout<<"Computed result  = " << someResult <<endl; 
}