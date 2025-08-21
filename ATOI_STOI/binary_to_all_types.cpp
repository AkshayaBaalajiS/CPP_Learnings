#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	cout<<"This is the program to convert the binary number to all types \n";
	int inputt ;
	cout<<"Enter the binary : ";
	cin>>inputt;

	string strr= to_string(inputt);
	int decimal = stoi(strr,nullptr,2);
	// the below will give wrong answer cause the data that is converted is binary we need to put the deimal there 
	cout<<"Octal is " << oct<<decimal<<endl;
	cout<<"hexa Decimal is " << hex<<decimal<<endl;



}