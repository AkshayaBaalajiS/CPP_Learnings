#include <iostream>
using namespace std;

int main()
{
	cout<<"Exceptions in C++\n";
	int a =23;
	int b=0;
	try
	{
		int c = a/b;
	}
	catch(exception &e )
	{
		cout<<"Exception : " << e.what() <<endl;
	}
}