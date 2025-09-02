#include <iostream>
using namespace std;

class Abstract 
{
	public :
		Abstract()
		{
			cout<<"Default constructor class of Abstract class  \n";
		}

		virtual void function_1()
		{
			cout<<" @ virtual void function_1() from Abstract class \n";
		}
		
		virtual void function_2() = 0 ;
	
		virtual void function_3() final 
		{
			cout<<" @ virtual void function_3() final from Abstract class \n";
		}

		void function_5()
		{
			cout<<"  @void function_5() from Abstrcat class \n";
		}

		virtual void function_4() = 0;

		~Abstract()
		{
			cout<<" @ Destructor of  Abstract class \n";
		}
};

class Derived : public  Abstract
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

		void function_2() override
		{
			cout<<" @ void function_2() override from Derived class \n";
		}

		/*
		this cant be done cause we have used final there so the override or redefinition cant be done 
		void function_3 () override
		{
			cout<<" @ virtual void function_1() from Abstract class \n";
		}
		*/
		void function_4() override
		{
			cout<<" @ void function_4() override from Derived class \n";
		}
		
		void function_5()
		{
			cout<<"  @void function_5() from Derived class \n";
		}
};

int main()
{
	cout<<"This is the program to demonstrate Abstract class in C++\n";

	// Abstract * ptr = new Abstract(); // A class with one or more pure virtual function is a abstract class and pointer or obj cant be created on it (A pointer can be created on abstract class assigned with derived class instance )
	Abstract * absPtr = new Derived();
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

}