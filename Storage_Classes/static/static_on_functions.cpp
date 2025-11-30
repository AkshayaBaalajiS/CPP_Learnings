#include <iostream>
using namespace std;


class A
{	
	static int staIntVar;
	int intVar;
	public :
		A() : intVar(34) // , staIntVar(12) // this should not be done cause static access from non static 
		{
			cout<<"@ A class constructor \n";
		}
		static void function()
		{
			cout<<"@static void function()\n";
			// function1();
		}
		void function1()
		{
			staIntVar =12;
			cout<<"@void function1()\n";
			function();
		}
		~A()
		{
			cout<<"@ A class destructor \n";
		}		
};
int A::staIntVar = 0;   // definition + optional initialization
/*
 Static members exist at class scope, not object scope.
 so for accessing the static data member we need the initialization to be done  
 */

void function2()
{
	cout<<"void function2()\n";
}
/*
the below function cant be overloaded / overrided 
void function()
{
	cout<<"void function()\n";
}
*/
static void function()
{
	cout<<"@static void function()\n";
	function2();
}

int main()
{
	function(); // a static function can call non static function  

	A obj;
	cout<<"---------------------\n";
	obj.function();
	obj.function1(); // non static member function can call static member function 
	cout<<"---------------------\n";

	A::function(); // this  can be done 
	// A::function1(); // this  cant be done  cannot call member function ‘void A::function1()’ without object

	// staObj.
}