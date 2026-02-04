#include <iostream>
using namespace std;

struct A
{
	int a{};
	int b{};
	int c{};
	A(int a=12, int b =1234, int c=24354) : a(a), b(b), c(c)
	{

	}
	void print() const 
	{
		cout<<"----"<<a << "  " << b << "  " << c << "----\n";
	}
};

int main()
{
	cout<<"Const program mainly const on diff places \n";

	const A * ptr = new A();
	ptr->print();
	// assignment of read only obj
	// ptr->a = 23; // error the value cant be changed  
	A * ptr1 = new A(67,78,89);
	ptr1->print();
	ptr = ptr1 ;// address can be chqngerd 
	ptr->print(); // value changed 


	A * const var = new A();
	var->a =234324;
	
	var->print(); // value changed 

}