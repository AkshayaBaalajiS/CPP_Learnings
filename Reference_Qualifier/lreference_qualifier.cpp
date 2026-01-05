#include <iostream>
using namespace std;

class A 
{
	public :
		void function1() & 
		{
			cout<<"void function1() & \n";
		}

		void function2() &&
		{
			cout<<"void function2() && \n";
		}

		
};

int main()
{
	cout<<"This is the program for the lvaue reference qualifier \n";

	A obj;
	obj.function1(); // this can be done 
	// obj.function2(); // this cant be done 
	/*
	void function2() && 
hduser@hduser-virtual-machine:~/Desktop/CPP_Learnings/Reference_Qualifier$ g++ lreference_qualifier.cpp
lreference_qualifier.cpp: In function ‘int main()’:
lreference_qualifier.cpp:26:22: error: passing ‘A’ as ‘this’ argument discards qualifiers [-fpermissive]
   26 |         obj.function2(); // this cant be done
      |         ~~~~~~~~~~~~~^~
lreference_qualifier.cpp:12:22: note:   in call to ‘void A::function2() &&’
   12 |                 void function2() &&
      |                      ^~~~~~~~~
hduser@hduser-virtual-machine:~/Desktop/CPP_Learnings/Reference_Qualifier$ 

	

	This means:

You are calling a function that expects this to be an rvalue (A&&)

But you are giving it an lvalue object (obj)

That mismatch is NOT allowed → compilation error.	

	*/
	std::move(obj).function2(); // this can be done 
	(A()).function2();
	/*
(*(new A())).function2();
CRITICAL RULE 🔥
Dereferencing a pointer always produces an lvalue
	*/
}
