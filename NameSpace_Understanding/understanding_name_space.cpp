/*
#include <iostream>
#include "understanding_name_space.h"
using namespace std;

int main()
{
	cout<<"This is the program to undertsand how the namespace works in a manual way \n";
	int iVariable = 1234;
	float fVariable = 12.09f;
	cout<<"-------------------------------------------------\n";
	customNameSpace::printFunction(iVariable);
	customNameSpace::printFunction(fVariable);
	cout<<"-------------------------------------------------\n";
}
*/

#include <iostream>
#include "understanding_name_space.h"
using namespace std;
using namespace customNameSpace;
int main()
{
	cout<<"This is the program to undertsand how the namespace works in a manual way \n";
	int iVariable = 1234;
	float fVariable = 12.09f;
	cout<<"-------------------------------------------------\n";
	printFunction(iVariable); // when we are explicitly mentioning the namespace in the using namespace we wont have to give the namespace for that function before calling 
	printFunction(fVariable);
	cout<<"-------------------------------------------------\n";
}


	