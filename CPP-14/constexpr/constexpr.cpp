#include <iostream>

using namespace std;


constexpr int function(int a=2, int b=6)
{
	return a*b;
	// return a+b; // for this 
	//error: static assertion failed: The condition not working fine
}

static_assert(function(4,3) == 12, "The condition not working fine ");

int function1(int a=2, int b=6)
{
	return a*b;
}


template <typename T>
T variable = T(123123.234233);


int main()
{
	cout<<"This is the cpp code to understand the constexpr in cpp \n";

	constexpr int a =1234;

	int aa =123;
	int b=234;
	constexpr int d =a+a; // this works fine 
	// constexpr int d =aa+a; // this wont work fine  cause the value of a and b get assigned in run time and the 
	// constexpr get value assigned at run time 
	constexpr int funret = function(123,34); // this is also possible as the function is constexpr 
	int funret1 = function(123,34); // this is also possible as it is running at compile time and the funtion get eval at compile time 
	int funret2 = function1(123,34); // this is also possible as it is running at run time 

	//‘aa’ is not usable in a constant expression
	// constexpr int funret2 = function(aa,b); //this create error as the aa and b are compile at runtime 
	int array[function(2,2)];
	int array1[function1(2,2)];

	cout<<"variable<int>" <<variable<int><<endl;
	cout<<"variable<char>" <<variable<char><<endl;
	cout<<"variable<double>" <<variable<double><<endl;
	
	
}

// $ g++ -E constexpr.cpp for preprocessed output 