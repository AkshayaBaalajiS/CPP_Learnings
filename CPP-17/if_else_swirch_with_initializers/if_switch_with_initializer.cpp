#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the code to understand the if switch with initializer \n";

	int a= 234;

	if(int b = a%2 )
	{
		cout<<"ODD \n";
	}
	else
	{
		cout<<"Even \n";
	}

	int aa=1;

	switch(int x =aa)
	{
		case 1:
			cout<<"case 1\n";
			break;
		case 2:
			cout<<"case 2\n";
			break;
		default :
			break;
	}
}