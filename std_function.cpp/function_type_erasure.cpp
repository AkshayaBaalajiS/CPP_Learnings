#include <iostream>
#include <functional>
using namespace std;

int function_1(int a , char b)
{
	cout<<"int function_1(int a , char b) \n";
}

int function_2(int a , char b)
{
	cout<<"int function_2(int a , char b) \n";
}

int function_3(int a , char b)
{
	cout<<"int function_3(int a , char b) \n";
}



int main()
{
	cout<<"This is the program to understand the type closure property of function\n";
	std::function<int(int , char)> some_function_1 = function_1;
	some_function_1(12,'a');
	some_function_1=function_2;
	some_function_1(12,'a');
	some_function_1=function_3;
	some_function_1(12,'a');
}