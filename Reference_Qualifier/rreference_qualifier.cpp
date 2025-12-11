#include <iostream>
using namespace std;

class A 
{
	public :
		void function1() &&
		{
			cout<<"void function1() & \n";
		}

		void function2() &
		{
			cout<<"void function2() && \n";
		}

		
};

int main()
{
	cout<<"This is the program for the lvaue reference qualifier \n";

	A().function1(); // this can be done 
	A().function2(); // this cant be done cause the this expects to be of type lvalue of type A 
	
		
	A obj;
	obj.function1(); // this cant be done 
	// as this expects the this to be of type rvalue of type A 
	
}
