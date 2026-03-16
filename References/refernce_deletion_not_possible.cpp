#include <iostream>
using namespace std;

void function(int & ref )
{
	cout<<"@void function(int & ref )\n";
	cout<<"&ref = " << &ref <<endl;
	delete &ref; // deleting the reference cause the undefined behaviour 
}

int main()
{
	cout<<"This is the code to understand the reference deletion in cpp\n";

	int number = 12;
	cout<<"&number = " << &number <<endl;
	function(number);
}