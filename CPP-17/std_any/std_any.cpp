#include <iostream>
#include <any>
using namespace std;

int main()
{
	cout<<"This is the program to understand the any in C++ \n";
	any variable = 234;
	// cout<<"variable = " << variable <<endl;// variable with any type cant be printed directly 
	cout<<"variable int = " << any_cast<int>(variable) <<endl;
	// cout<<"type of variable = " << variable.type() <<endl; // this type cant be printed we can compare the typoe with the data type 
	variable = 234.234f;
	cout<<"variable float = " << any_cast<float>(variable) <<endl;
	cout<<"variable double = " << any_cast<double>(variable) <<endl;
}