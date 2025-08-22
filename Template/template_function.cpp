#include <iostream>
using namespace std;


template <typename T>
T function_to_do_something(T &ref )
{
	cout<<"T function_to_do_something(T &ref ) \n";
	return ref;
}

int main()
{
	cout<<"This is the program to understand the template in c++ \n";

	int a =123;

	float b =23.234;

	char c='a';

	double d = 34.23423;

	string s= "232423423422";

	cout<<"-------------------------------------------\n";
	function_to_do_something(a);
	cout<<"-------------------------------------------\n";
	cout<<"-------------------------------------------\n";
	function_to_do_something(b);
	cout<<"-------------------------------------------\n";
	cout<<"-------------------------------------------\n";
	function_to_do_something(c);
	cout<<"-------------------------------------------\n";
	cout<<"-------------------------------------------\n";
	function_to_do_something(d);
	cout<<"-------------------------------------------\n";
	cout<<"-------------------------------------------\n";
	function_to_do_something(s);
	cout<<"-------------------------------------------\n";


}