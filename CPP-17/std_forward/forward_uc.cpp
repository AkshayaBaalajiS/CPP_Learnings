#include <iostream>

using namespace std;
// ambiguious 
// void function(int a )
// {
// 	std::cout<<"void function(int a )\n";
// }

void function(int & a)
{
	std::cout<<"void function1(int & a)\n";
}

void function(int && a)
{
	std::cout<<"void function(int && a)\n";
}

template <typename T>
void forwardUC(T&& args)
{
	function(forward<T>(args));
}

int main()
{
	cout<<"This is the program to udnerstadn the std forward clearly in cpp \n";
	int number  =2134;

	forwardUC(number);// int & 

	forwardUC(std::move(number)); // int && 
	
}