#include <iostream>
using namespace std;

class A 
{
	public :
		A() =  default;

		// error: call of overloaded ‘A()’ is ambiguous
		// A(int a =23) //error: call of overloaded ‘A()’ is ambiguous
		// {
		// 	cout<<"Act as default / paramerized cons \n";
		// }

		// error: ‘A::A(int, int)’ cannot be defaulted
		// A(int a, int b ) = default;

		A& operator=(A&) = default;

};

int main()
{
	cout<<"This is the program to understand the default usage in cpp \n";
	A obj; 	
}