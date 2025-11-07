#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	cout<<"This is the program to understand the lambda in cpp\n";

	int a = 12;
	char c = 'a';
	double d =1231.12131;

	auto lambda = [](int & a){
		++a;
	};

	lambda(a);

	cout<<"A  = " << a <<endl;
}