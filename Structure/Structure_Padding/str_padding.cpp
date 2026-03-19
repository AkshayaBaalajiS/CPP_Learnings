#include <iostream>
using namespace std;

struct A 
{
	char a;
	char c;
	int b;
};

int main()
{
	cout<<"This is the code to understand the Structure Padding \n";
	cout<<"sizeof(A) = " << sizeof(A)<<endl;
}