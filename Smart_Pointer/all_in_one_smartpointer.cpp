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
		cout<<"Move constructor\n";
		this->a = ref.a;
		this->b = ref.b;
		this->iPtr = ref.iPtr;
		this->cPtr = ref.cPtr;
		
	}
	A(A* && ref)
	{
		cout<<"Move constructor\n";
		this->a = ref->a;
		this->b = ref->b;
		this->iPtr = ref->iPtr;
		this->cPtr = ref->cPtr;
		
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

	// unique_ptr =========================
	// 1 Ways of Initialization  ----------------------------
	unique_ptr<A> uniPtr(new A());

	unique_ptr<A> uniPtr1 = make_unique<A>();

	// unique_ptr<A> uniPtr2(uniPtr); // use of a deleted function 
	uniPtr->function();
	uniPtr1->function();
	
	unique_ptr<A> uniPtr2;
	uniPtr2 = make_unique<A>();
	
	unique_ptr<A> uniPtr3 = createUniPtr();
	//  ----------------------------
	// 2 move semantics ++++++++++++++++++++


	// unique_ptr<A> uniptr4 = std::move(new A()); // this will be a error move of a 

	A * ptr = new A();

	A * ptr_1 = std::move(ptr);

	A * ptr_2 = new A(std::move(*ptr));
	A * ptr_4 = std::move((new A())); // this cant be done cause the move expects the r value reference 
	unique_ptr<A> uniPtr4 = std::move(uniPtr3);
	// cout<<"A = " << uniPtr3->a ; // this cant be done cause we have transfered the owner ship 
	// ++++++++++++++++++++

	// 3. release ownership 

	A * ptr_3 = uniPtr1.release(); // returns the raw pointer and the unique_ptr becomes NULL 
	uniPtr4.reset(new A()); 


	
}
