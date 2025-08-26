#include <iostream>
#include <functional>
using namespace std;


int some_function(int a, string b, char c)
{
	cout<<"int some_function(int a, string b, char c)\n";
	if(b.find(c))
	{
		return 1;
	}
	return 0;
}

int main()
{
	cout<<"This is the program to understand the std::function in c++ \n";
	// std::function<int(int,string,char)> function_1 ; without assigning to respective function this wont work and will cause bad_function_Call abort 
	std::function<int(int,string,char)> function_1 =some_function;
	cout<<"Return is : " << 	function_1(1,"asdfg",'a') <<endl;

}