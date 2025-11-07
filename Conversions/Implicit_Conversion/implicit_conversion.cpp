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

int main()
{
	cout<<"This is the program to understand the implicit conversion in cpp\n";

	A * ptr = new A();

	int a =123;
	char c = 'a';
	double d = 123.2342342;

	// 1 . when we are assigning a value of diff type to diff type implicit conversion done by the compiler 
	ptr->iVar = d;
	cout<<"ivar = " << ptr->iVar <<endl;
	// 2 . when we are do operation of diff type and assigning to diff type implicit conversion done by the compiler 
	ptr->iVar = a  + ptr->cVar; 
	cout<<"ivar = " << ptr->iVar <<endl;
	// 3 . when we are passing a var but the parameter is expecting a diff var type implicit conversion done by the compiler 
	function(ptr->dVar);

	// Implicit Conversion mean compiler changes the type of var by itself 
	B obj;

	ptr = &obj; // this is also a implicit conversion as we are not converting it manually 
}