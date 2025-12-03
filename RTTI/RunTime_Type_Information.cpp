#include <iostream>
using namespace std;

class A 
{
	public :
		A()
		{
			cout<<"@ A class constructor \n";
		}
		// virtual void print()
		// {

		// }
		virtual ~A() // wither a virtula function or virtual on destructor 
		{
			cout<<"@ A class destructor \n";
		}
};

class B : public A
{
	public :
		B()
		{
			cout<<"@ B class constructor \n";
		}

		~B()
		{
			cout<<"@ B class destructor \n";
		}
};


int main()
{
	cout<<"This is the program to understand the RTTI in cpp\n";

	A * ptr = new A();
	A * aptr = new B(); // up-casting cause Derived is typecasted to Base

	B * bptr = new B(); 
	B * bbptr = dynamic_cast<B *>(ptr); // this is downcasting Base is typecsated to Derived 
	// error error: cannot ‘dynamic_cast’ ‘ptr’ (of type ‘class A*’) to type ‘class B*’ (source type is not polymorphic)
	// Because dynamic_cast requires at least one virtual function in the base class to create RTTI info.

	/* Why static cast worked here without error 
	B * bbptr = static_cast<B *>(ptr);
	Does NOT check actual object type

	Only checks at compile time that a conversion might be possible

	So compiler sees:

	ptr is A*

	A → B is a valid inheritance relation

	Thus, it allows the cast.

	But at runtime:

	⚠️ This is undefined behavior
	⚠️ You will get a corrupt object
	⚠️ Using bbptr will likely crash

	Static cast trusts you — dynamic cast verifies it.
	*/

	cout<<"Type of the dynamica cast ptr = " << typeid(bbptr).name()<<endl;
	cout<<"Type of the  bptr = " << typeid(bptr).name()<<endl;
	cout<<"Type of the  ptr = " << typeid(ptr).name()<<endl;

	// for polymorphic class type is deducted from 
	// the typeid is comming from vptr -> vtable -> type_info 

	cout<<"Type of the  new A" << typeid(new A()).name()<<endl;
	cout<<"Type of the  int = " << typeid(int).name()<<endl;

	const type_info & typeInforVar = typeid(bbptr) ;
	cout<<"typeInforVar = " << typeInforVar.name() <<endl;




}