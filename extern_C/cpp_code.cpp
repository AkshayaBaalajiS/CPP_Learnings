#include <iostream>
#include "cpp_header.h"

using namespace std;

void printStyleCpp()
{
	cout<<"   printStyleCpp\n";
}

void cpp_style_print()
{
	cout<<" cpp_style_print\n";
	printStyleCpp();
}

void stringFunc(string s)
{
	cout<<"String Function called \n";
	cout<<" s = "  << s  << endl;
}

void wrapperForStringFunc(char * sttt)
{
	stringFunc(sttt);
}

// int main()
// {
// 	cout<<"A simple code where main will be commented after checking cpp execution \n";

// }