#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	cout<<"This is the program to understand the auto in cpp\n";

	double d = 12.1212121;
	string s = "Hi String";
	
	char * ptr = "This is the char *";
	// this is the warning cause 
	// we are using the poinrt to modify the string through ptr for solving this use const  

	const char * cPtr = "This is the const char * |  string literal ";
}