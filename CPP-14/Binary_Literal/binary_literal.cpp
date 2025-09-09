#include <iostream>
using namespace std;

int main()
{
	cout<<"This is a program to demonstrate binary literal in C++ \n";

	int binary_val = 0b1010;
	cout<< " 0b1010 stored in int is = " << binary_val <<endl;

	int binary_val1 = 0B00001111;
	cout<< " 0B00001111 stored in int is = " << binary_val1 <<endl;

	int binary_val2 = 0B000011110;
	cout<< " 0B000011110 stored in int is = " << binary_val2 <<endl;
/* The below creates error "invalid digit "3" in binary constant"
	int binary_val3 = 0B00001111023;
	cout<< " 0B00001111023 stored in int is = " << binary_val3 <<endl;
*/
}