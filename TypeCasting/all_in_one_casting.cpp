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
		virtual void function() =0;
};

class C : public B
{
	public:
		C()
		{
			cout<<"@ C default constructor\n";
		}
		void function() override;
};

void C::function()
{
	cout<<"@ void C::function() \n";
}



void function(int a)
{
	cout<<"@ function parameter is : " << a << "\n";
}

int main()
{
	cout<<"This is the program to understand the implicit conversion in cpp\n";

	A * aPtr = new A();

	int a =123;
	char c = 'a';
	double d = 123.2342342;

	aPtr->iVar = static_cast<int>(d);
	cout<<"ivar = " << aPtr->iVar <<endl;

	// why static_cast works and reinterpret class wont work ? 
	// reinterpret_cast only work with pointers 
	// aPtr->iVar = reinterpret_cast<int>(d);
	cout<<"ivar = " << aPtr->iVar <<endl;

	// dynamic_cast wont work with value it work only with pointers or reference 
	// aPtr->iVar = dynamic_cast<int>(d);
	// cout<<"ivar = " << aPtr->iVar <<endl;


	B *obj;

	aPtr = static_cast<A *>(obj);

	aPtr = dynamic_cast<A *>(obj);

	B * bPtr;
	// bPtr = dynamic_cast<B*>(aPtr); // this cant be done cause it is not polymorphic (no virtual functions )
	bPtr = static_cast<B*>(aPtr); // static_cast is still doing the upcasting but it is supposed to do downcasting only 
	// here I will allow you to do this cast, but I will not check if it’s valid at runtime happens 
	// it will be a issue casuse the aptr does not point to B 

	A * aaPtr = static_cast<A*>(obj); // this is upcasting and now A points to B

	B * bbPtr = static_cast<B*>(aaPtr); // this is downcasting and it is done by static_cast and here the aaPtr is actually point to B so this is valid  


	C * cPtr;
	cPtr = dynamic_cast<C*>(bPtr); // this is working cause b class is having a virtul function so it is polymorphic 	


	// what is 
	// upcasting : converting from derived to base // aPtr = static_cast<A *>(obj);
	// downcasting : converting from base to derived // cPtr = dynamic_cast<C*>(bPtr);


	//reinterpret_cast
	double dd = 123.456;
	// int* iPtr = reinterpret_cast<int*>(&dd); this should not be done 

	// cout << *iPtr << endl;  // 🚨 Undefined behavior// value is not proper : shit value 

	// cout << *iPtr << endl;  // 🚨 Undefined behavior// value is not proper : shit value 

	// iPtr = static_cast<int*>(&dd); // error on conversion

	void * add = malloc(2024);
	cout<<"void *add = " << add <<endl;

	int * iiPtr = reinterpret_cast<int*>(add);
	cout<<"int * iiPtr = " << iiPtr <<endl;


}