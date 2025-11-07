#include <iostream>
#include <bitset>
// #include <binary>

using namespace std;

int main()
{
	cout<<"This is the program to understand the binary literal in cpp \n";
	int number =  0b010001;
	double dnumber =  0b010001;
	int iNum = 123;
	cout<< hex << (iNum) << endl;
	cout<<"Number =  " << number<<endl;
	cout<< oct << iNum << endl;	


    // using bitset to print in binary
    cout << "num2 (binary) = " << bitset<8>(number) << endl;


    cout<< hex << (dnumber) << endl;
	cout<<"Number =  " << dnumber<<endl;
	cout<< oct << dnumber << endl;	


    // using bitset to print in binary
    cout << "num2 (binary) = " << bitset<8>(dnumber) << endl;
}