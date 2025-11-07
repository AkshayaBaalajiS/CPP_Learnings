#include <iostream>
#include <cstring>

using namespace std;


class A
{
	public :
		int iVar;
		char cVar;
		double dVar;
		char * cPtr;
		int * iPtr;

		A() : iVar(0), cVar('0'),dVar(0.00), cPtr(NULL), iPtr(NULL)
		{
			cout<<"@ A default constructor\n";
		}

		// the below is fused when the obj is assigned  = obj like this this will not overload the explicit conversion 
	
		explicit operator int ()
		{
			cout<<"@ operator int (int a)\n ";
			return static_cast<int>(dVar);
		}
		
};

class B : public A 
{
	public:
		B()
		{
			cout<<"@ B default constructor\n";
		}

};

void function(int a)
{
	cout<<"@ function parameter is : " << a << "\n";
}

// int operator int &(int a)
// {
// 	cout<<"@ operator int &(int a)\n ";
// 	return a;
// }

int main()
{
	cout<<"This is the program to understand the implicit conversion in cpp\n";

	A * ptr = new A();

	int a =123;
	char c = 'a';
	double d = 123.2342342;

	//old  1 . when we are assigning a value of diff type to diff type implicit conversion done by the compiler 
	//new we are assigning through the explicit casting 
	ptr->iVar = static_cast<int>(d);
	cout<<"ivar 1= " << ptr->iVar <<endl;

	ptr->dVar = 234.23423;
	ptr->iVar = static_cast<int>(*ptr);
	cout<<"ivar 2= " << ptr->iVar <<endl;

	//old  2 . when we are do operation of diff type and assigning to diff type implicit conversion done by the compiler 
	// new here we are converting and assigning so explicit conversion used  
	ptr->iVar = a  + static_cast<int>(ptr->cVar); 
	cout<<"ivar = " << ptr->iVar <<endl;
	// 3 . when we are passing a var but the parameter is expecting a diff var type implicit conversion done by the compiler 
	function(static_cast<int>(ptr->dVar));

	//old  Implicit Conversion mean compiler changes the type of var by itself 
	//new we are using the casting mecha so this is explicit conversion 
	B obj;

	ptr = static_cast<A *>(&obj); 


	// Explicit cast :  You tell the compiler to convert using a cast like static_cast
}