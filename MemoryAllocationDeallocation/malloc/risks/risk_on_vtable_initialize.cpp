#include <iostream>
#include <thread>
using namespace std;

class Base 
{
	public :
		Base()
		{
			cout<<"@ Base class constructor\n";
		}	

		virtual void print() = 0 ;
		virtual void printFunction() = 0 ;
		
		virtual ~Base()
		{
			cout<<"@ Base class destructor \n";
		}
};

class Derived : public Base
{
	public :
		Derived()
		{
			cout<<"@ Derived class constructor\n";
		}	

		void print() override 
		{
			cout<<"Derived class print function overidden \n";
		}

		void printFunction() override
		{
			cout<<"Derived class printFunction function override\n";
		}

		~Derived()
		{
			cout<<"@ Derived class destructor \n";
		}
};

int main()
{

	cout<<"This is the code to understand the risk of using the malloc and free in cpp \n";


	cout<<"---NEW---------------------------\n";
	Base * basePtr1 = new Derived();
	// new initialize the vtable so no issues on calling the virtual function 
	basePtr1->print();
	basePtr1->printFunction();
	cout<<"------------------------------------\n";

	cout<<"---MALLOC----------------------\n";
	Base * basePtr = (Derived*)malloc(sizeof(Derived));
	// due to vatble not get initialized we get the seg violation 
	basePtr->print();
	basePtr->printFunction();
	cout<<"------------------------------------\n";

	delete(basePtr1); // sample CLass destructor called 
	free(basePtr); // resource freed but there is 1 possibility for memory leak  
}

/*
malloc does not initialize the vtable and the virtual destructor  

new initialize the vtable 
*/ 