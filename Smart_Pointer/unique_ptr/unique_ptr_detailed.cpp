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


void function()
{

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
	unique_ptr<A> uniPtr31 ;
	uniPtr31 = createUniPtr(); // this also can be done 
	//  ----------------------------
	// 2 move semantics ++++++++++++++++++++
	// unique_ptr<A> uniptr4 = std::move(new A()); // this will be a error move of a 

	unique_ptr<A> uniPtr4 = std::move(uniPtr3);
	// cout<<"A = " << uniPtr3->a ; // this cant be done cause we have transfered the owner ship 
	// ++++++++++++++++++++

	// 3. release ownership 

	A * ptr_3 = uniPtr1.release();
	// cout<<"A = " << uniPtr1->a ; // after release unique ptr looses its raw pointer 

	// 4. reset 
	uniPtr4.reset();
	// cout<<"A = " << uniPtr4->a ; // after reset we cant derefer the smart pointer 
	uniPtr4.reset(new A());
	cout<<"A = " << uniPtr4->a ; // reset with arg will delete the current raw pointer and assigned the arg to raw pointer  	

}
