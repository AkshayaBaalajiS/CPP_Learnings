#include <iostream>
using namespace std;

int function(int a )
{
	return a;
}

int main()
{
	cout<<"Null vs Nullptr\n";
	function(NULL); // NULL typecasted to int 
	// function(nullptr); // nullptr cant be typecasted to int so error occur here  
	
}
/*
Learning Null will be typecasted to int and NullPtr will not be typecasted to int 
*/