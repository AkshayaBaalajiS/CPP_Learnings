#include <iostream>
using namespace std;

static int number = 23;

int & function1()
{
	return number;
}

int main()
{
	cout<<"This is the code to understand the auto and decltype in cpp \n";
	int & rvalue = function1(); 

	auto var = function1(); // int 
	decltype(auto) declVar = function1(); // int & 
	cout<<"Global Number  = " << number <<endl;
	cout<<" var  = " << var <<endl;
	cout<<" declVar  = " << declVar <<endl;
	cout<<"------------------------\n";
	
	// after changing the var 
	cout<<"------------------------\n";
	var =456;
	cout<<"Global Number  = " << number <<endl;
	cout<<" var  = " << var <<endl;
	cout<<" declVar  = " << declVar <<endl;
	cout<<"------------------------\n";

	
	// after changing the declVar  
	cout<<"------------------------\n";
	declVar =784;
	cout<<"Global Number  = " << number <<endl;
	cout<<" var  = " << var <<endl;
	cout<<" declVar  = " << declVar <<endl;
	cout<<"------------------------\n";



	// on const 
	const int a =124;
	auto autoA = a;
	decltype(auto) declA = a;
	autoA =234; // here the const is not preserved 
	// declA = 24356; // error assignment of read only var
	
}