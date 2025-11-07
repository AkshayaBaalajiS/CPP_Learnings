#include <iostream>
using namespace std;

struct A 
{
	int a;
	char c;
	float b;
	double d;
};

int main()
{
	cout<<"This is the program to understand the aggregate member function in cpp \n";

	A obj = {12};
	cout<<obj.a<<endl;

	obj = {12, 'a'};
	cout<<obj.c<<endl;

	obj = {12, 'a', 456.234f};
	cout<<obj.b<<endl;
	
	obj = {12, 'a', 234.234f, 3454.324534};
	cout<<obj.d<<endl;

}