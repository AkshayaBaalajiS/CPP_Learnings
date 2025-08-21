#include<iostream>
using namespace std ;

int main()
{
	cout<<"Hi.................\n";
	try
	{
		cout<<"Inside the try block..........\n";
		throw(10);
		cout<<"After through nothing will be executed...\n";
	}
	catch(int a )
	{
		cout<<"Inside the catch block "<<" returned : " <<a << "\n" ;
	}
}
