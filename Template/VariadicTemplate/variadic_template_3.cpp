#include <iostream>
using namespace std;

// empty function for making it call empty function at last 
void function()
{
}

template <typename A, typename... T>
void function(A arg1, T... arg2)
{
	cout<<"Arg1 = " << arg1 <<endl;
	function(arg2...);
}


int main()
{
	cout<<"Variadic template \n";
	function(123,123,12,31,23,1,23,12,21,"Asdf",234.234,'a');
}