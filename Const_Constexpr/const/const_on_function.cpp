#include <iostream>
using namespace std;


class A
{
	public :
		int ivar;
		float fvar;
		char cvar;
		double dvar;
		mutable string str;

		A()
		{
			cout<<"@ A class constructor \n";
		}	
		//const-qualified member function
		//The function cannot modify the internal state of the object because this becomes a pointer-to-const.
		void function1() const  // A const* this
		{
			cout<<"@ void function1() const \n";
			str= "234";
			// function12();
			function123();
			// ivar=234; //assignment of member ‘A::ivar’ in read-only object0
		}
		// the below function is not overriding the function casue the signature is diff 
		// the below function is overloading the function by removing const 
		void function1() // A * this
		{
			cout<<"@void function1() \n";
		}
		void function12() // A * this
		{
			cout<<"@void function12() \n";
		}
		void function123() const // A * this
		{
			cout<<"@void function123() const  \n";
		}
		/*
		mutable void function11() //function ‘function11’ cannot be declared ‘mutable’
		{
			cout<<"@void function1() \n";
		}
		*/
		~A()
		{
			cout<<"@ A class destructor \n";
		}
};
/*
const cant be applied on funciton outside oof class cause 
these fucntion dont have this pointer in it 
void function(int a, int b) const 
{
	int as = a+b;
}
*/



int main()
{
	cout<<"This is the program to undertsnad the const applied on function \n";
	A obj;
	obj.function1(); // calls non const function 
	obj.function123(); // this can also be done 

	const A obj2;
	obj2.function1(); // calls const function

	A const obj3;  // is same as const A obj2;
	obj3.function123(); 
	// obj2.function12(); // this cant be done cause the obj is const and the function is non const 
	//passing ‘const A’ as ‘this’ argument discards qualifiers
	// cannot convert const A* → A*, so compiler forbids it
}