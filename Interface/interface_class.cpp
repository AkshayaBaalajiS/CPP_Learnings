#include <iostream>
using namespace std;

class Interface 
{
	public :
		virtual void function_1() = 0 ;
		virtual void function_2() = 0 ;
		virtual void function_3() = 0 ;
		virtual void function_4() = 0 ;
		virtual void function_5() = 0 ;
		virtual ~Interface() {}
};

class Derived : public  Interface
{
	public :
		Derived()
		{
			cout<<"Default constructor of Derived class \n";
		}

		void function_1() override
		{
			cout<<" @ void function_1() override from Derived class \n";
		}

		void function_2()
		{
			cout<<" @ void function_2() from Derived class \n";
		}

		
		void function_3 () override
		{
			cout<<" @ virtual void function_3() from Derived class \n";
		}
		
		void function_4() override
		{
			cout<<" @ void function_4() override from Derived class \n";
		}
		
		void function_5() override
		{
			cout<<"  @void function_5() from Derived class \n";
		}
		~Derived ()
		{
			cout<<" @ derived class destructor \n";
		}
};

int main()
{
	cout<<"This is the program to demonstrate Interface class in C++\n";

	// Interface * ptr = new Interface(); // A class with one or more pure virtual function is a Interface class and pointer or obj cant be created on it (A pointer can be created on Interface class assigned with derived class instance )
	Interface * absPtr = new Derived();
	Derived * derPtr = new Derived();


	cout<<"______________________________________________\n";
	absPtr->function_1();
	derPtr->function_1();
	cout<<"______________________________________________\n";
	

	cout<<"______________________________________________\n";
	absPtr->function_2();
	derPtr->function_2();
	cout<<"______________________________________________\n";
	

	cout<<"______________________________________________\n";
	absPtr->function_3();
	derPtr->function_3();
	cout<<"______________________________________________\n";
	

	cout<<"______________________________________________\n";
	absPtr->function_4();
	derPtr->function_4();
	cout<<"______________________________________________\n";
	

	cout<<"______________________________________________\n";
	absPtr->function_5();
	derPtr->function_5();
	cout<<"______________________________________________\n";

	delete absPtr; // this will call the Interface destructor and as it is virtual it call the derived class destructor
}