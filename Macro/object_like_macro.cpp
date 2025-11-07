#include <iostream>
using namespace std;

template <typename T>
void function(T & ref)
{
	cout<<"@ void function(T & ref) \n";
	cout<<"ref = " << ref <<endl;
}

void variadic_function()
{
	cout<<"@ void variadic_function()\n";	
}

template <typename T, typename... TT>
void variadic_function(T  ref, TT...  reff)
{
	cout<<"@ void variadic_function(T  ref, TT...  reff) \n";
	cout<<"ref = " << ref <<endl;
	variadic_function(reff...);
}



#define PI 3.14159265359
int main()
{
	cout<<"This is the program to understand the object like macro in C++ \n";
	int pi_value  = PI ;
	cout<<"The  pi_value is " << pi_value <<endl;

	double pi_value_1  = PI ;
	cout<<"The  pi_value is " << pi_value_1 <<endl;
	
	int number =23;
	function(number);

	variadic_function(12,324,34.3443,456.34f,'s', "String");

}