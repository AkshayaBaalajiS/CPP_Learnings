#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

struct A 
{
	int a;
	float b;
	int * iPtr;
	char * cPtr;
	A() : a(0),b(0.00001f), iPtr(nullptr), cPtr(nullptr)
	{
		cout<<"@ A Constructor\n";
	}
	~A()
	{
		cout<<"@ A Destructor\n";
	}
	A(A && ref)
	{
		cout<<"Move constructor A(A && ref) \n";
		this->a = ref.a;
		this->b = ref.b;
		this->iPtr = ref.iPtr;
		this->cPtr = ref.cPtr;
		
	}
	A(A* && ref)
	{
		cout<<"Move constructor A(A* && ref) \n";
		this->a = ref->a;
		this->b = ref->b;
		this->iPtr = ref->iPtr;
		this->cPtr = ref->cPtr;
		
	}

	void operator = (A* && ref )
	{
		cout<<"move assignement operator void operator = (A *&&)\n";
	}


	void function()
	{
		cout<<"@ function \n";
	}

	void function1()
	{
		cout<<"@ function1 \n";
	}
	

};

unique_ptr<A> createUniPtr()
{
	return make_unique<A>();
}

int main()
{
	cout<<"This is the program to understand the smart pointer in cpp\n";

	A * ptr = new A();

	A * ptr_1 = std::move(ptr); // return A* && and assign to ptr 

	A obj = std::move(ptr); //Move constructor A(A* && ref)

	A obj1 ;
	obj1 = std::move(ptr); // move assignement operator void operator = (A *&&)
	

	A * ptr_2 = new A(std::move(ptr)); // Move constructor A(A* && ref) 


	A * ptr_3 = new A(std::move(*ptr)); // Move constructor A(A && ref)

	A * ptr_4 = std::move(new A()); // A * = A *&& // how this is working 
	/*
	Concept	Description
	A*	A pointer variable — holds an address of an object.
	A*&&	A reference (alias) to a pointer variable — refers to another pointer.
	Assignment from A*&& → A*	Copies the pointer value (the address) from the aliased pointer variable into a new pointer variable.
	*/

	A obj3 = std::move(*(new A())); // Move constructor A(A && ref)
	
}

