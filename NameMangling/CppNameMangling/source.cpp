#include <iostream>
using namespace std;

void function1(int a, float b )
{
	cout<<"@int function1(int a, float b )\n";
}

int function1(int a, float b, char c, double d)
{
	cout<<"@int function1(int a, float b, char c, double d)\n";
	return 0;
}
int main()
{
	cout<<"This is the code to understand the namemangling in cpp\n";

}