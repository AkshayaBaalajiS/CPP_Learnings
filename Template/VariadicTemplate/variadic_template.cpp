#include <iostream>
using namespace std;

// the below empty function is to stop recursion 
// once all variadic arg are done it will call empty function and this stops recurssion 
void variadic_function()
{

}

// variadic function template 
template <typename T, typename ... Typess>
void variadic_function(T arg1, Typess ... arg_2)
{
	// we cant print the arg2 directly cause we have to print it with ... else error: parameter packs not expanded with ... 
	// and while printing we should call the variadic function by passing the arg2 of first as first arg to the function so that it can print 
	// cout<<"Arg 1 =  " << arg1 << endl << "  Arg2  = " << arg_2... <<endl ; 
	// cout<<"Arg 1 =  " << arg1 << endl << "  Arg2  = " << variadic_function(arg_2...) <<endl ; 

	// correct way to print parameter packs is : 
	// recursion 
	// fold expressions 

	// 1 recursion is below 
	// cout<<"Arg 1 =  " << arg1 << endl << "  Arg2  = " << variadic_function(arg_2...) <<endl ;  // this wont work cause compiler cant convert void to const char *
	cout<<"Arg 1 =  " << arg1 << endl; 
	variadic_function(arg_2...) ;  // this wont work cause compiler cant convert void to const char *


}

int main()
{
	cout<<"This is a prgram for Variadic template in c++\n";
				
	variadic_function(12,23,324,3.34, 34.3434f , 'a' , "assdfs");

}
/*
How it works : 
Exactly! Let’s clarify this carefully.

Suppose your call is:

variadic_function(12, 23, 324, 3.34, 34.3434f, 'a', "assdfs");

First recursive call
T = int           // arg1 = 12
Typess = {int, int, double, float, char, const char*}  // arg_2... = {23, 324, 3.34, 34.3434f, 'a', "assdfs"}


Inside function:

cout << "Arg 1 = " << arg1 << endl;  // prints 12
variadic_function(arg_2...);         // expands to: variadic_function(23, 324, 3.34, 34.3434f, 'a', "assdfs")


✅ So yes, it now calls itself with 6 arguments, which becomes the new arg1 + arg_2... in the next instantiation.

Second recursive call
T = int           // arg1 = 23
Typess = {int, double, float, char, const char*}  // arg_2... = {324, 3.34, 34.3434f, 'a', "assdfs"}


Prints 23

Calls: variadic_function(324, 3.34, 34.3434f, 'a', "assdfs")

Third recursive call
T = int           // arg1 = 324
Typess = {double, float, char, const char*}  // arg_2... = {3.34, 34.3434f, 'a', "assdfs"}


Prints 324

Calls: variadic_function(3.34, 34.3434f, 'a', "assdfs")

This continues until eventually:

variadic_function()  // no arguments


This matches the base case void variadic_function()

Recursion stops.

*/