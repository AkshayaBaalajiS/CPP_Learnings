#include <iostream>
using namespace std;

int function1(int & ref)
{
	cout<<"@function1(int & ref)  : ";
	return 0;
}


int function1(int && ref)
{
	cout<<"@function1(int && ref)  : ";
	return 1;
}


int main()
{
	cout<<"This the code to udnerstand the auto variable on const passed it will not take the const \n";
	const int someVar = 324;
	const int * cptr = &someVar;
	cout<<"Type os someVar = " << typeid(someVar).name()<<endl;
	auto autVar = someVar; // auto does not hold the const 
	autVar = 34;	
	cout<<"Type os autVar = " << typeid(autVar).name()<<endl;

	decltype(auto) declAut = someVar; // holds the const also 
	// declAut = 234; // error assignment of readOnly operation 
	
	cout<<"---------------------------------\n";
	int number = 23;
	auto autNum = number;
	cout<<"Resullt = " << function1(autNum) <<endl; // lvalue function will be called 
	auto rvalueNum= std::move(number);
	cout<<"Resullt = " << function1(rvalueNum) <<endl; // lvalue function will be called 
	cout<<"---------------------------------\n";

	cout<<"---------------------------------\n";
	decltype(auto) drvalueNum0= number;
	cout<<"Resullt = " << function1(drvalueNum0) <<endl; // lvalue function will be called 
	
	decltype(auto) drvalueNum= std::move(number);
	cout<<"Resullt = " << function1(drvalueNum) <<endl; // lvalue function will be called 
	cout<<"---------------------------------\n";

	int && rNum = std::move(number);
	cout<<"Resullt = " << function1(rNum) <<endl; // lvalue function will be called 

	
}

/*
Named variables are always lvalues.
	Even if their type is int&&.
	This is the key to everything in your program.
*/