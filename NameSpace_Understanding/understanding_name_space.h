#include<iostream>
using namespace std;

namespace customNameSpace
{
	template<typename T>
	void printFunction(T & ref)
	{
		cout<<"++++++"<<ref <<"++++++\n";
	}
}