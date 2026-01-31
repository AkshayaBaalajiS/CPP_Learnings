#include <iostream>
using namespace std;

void sample() noexcept 
{
	throw 1;
}
void sample1()  
{
	throw 1;
}

int main()
{
	cout<<"noexcept program in cpp \n";
	try
	{
		sample();
		// sample1();
	}
	catch(int & a)
	{
		cout<<"Caught "<<a<<endl;
	}
}