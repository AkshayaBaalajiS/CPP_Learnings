#include <iostream>
using namespace std;

namespace n1
{
	void function1()
	{
		cout<<"@ n1::function1 \n";
	}

	namespace n2
	{
		void function1()
		{
			cout<<"@ n1::n2::function1 \n";
		}	
	};
};

using namespace n1;
// this cant be done cause the compiler dont know which function to call cause both have same declaration and same arg
// using namespace n2;

int main()
{
	cout<<"This is the program for understanding the nested namespace \n";

	n1::function1();
	n1::n2::function1();

	function1();

}