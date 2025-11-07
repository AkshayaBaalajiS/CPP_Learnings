#include<iostream>
#include <sstream>

using namespace std;

int main()
{
	cout<<"This is the program to convert the binary to decimal, octal and hexadecimal \n ";
	string binary;
	cout<<"Enter the binary number : ";
	cin>>binary;

	int decimal = stoi(binary , nullptr , 2 );
	cout<<"The Decimal of " << binary << " this binary is : " << decimal <<endl ;

	ostringstream oss ;
	oss<<oct<<decimal;

	string octal = oss.str();
	cout<<"The Octal of " << binary << " this binary is : " << octal <<endl ;
	int octal_number = stoi(octal);
	cout<<"The Octal of " << binary << " this binary is : " << octal_number <<endl ;
	


	oss.str("");
	oss.clear();

	oss<<hex<<decimal;

	string hexa = oss.str();
	cout<<"The Hexa Decimal of " << binary << " this binary is : " << hexa <<endl ;
	int hexa_num = stoi(hexa,nullptr,16);
	cout<<"The Hexa Decimal of " << binary << " this binary is : " << hexa_num <<endl ;
	


}