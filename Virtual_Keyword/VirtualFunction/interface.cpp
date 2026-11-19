#include <iostream>
using namespace std;

class Interface
{
	public :
		virtual void print() =0 ;

		virtual void printFunc() = 0 ;
		
		virtual void printFunc1() = 0 ;
		
		virtual void printFunc2() = 0 ;
		
		virtual void printFunc3() = 0 ;
		
		virtual ~Interface(){};
};

class Derived : public Interface
{
	public :
		Derived()
		{
			cout<<"@ Derived class constructor \n";
		}
		void print() override
		{
			cout<<"@void print() of Derived class overriden \n";
		}
		void printFunc()  override
		{
			cout<<"@void printFunc() of Derived class overriden \n";
		}
		
		void printFunc1()  override
		{
			cout<<"@void printFunc1() of Derived class overriden \n";
		}
		
		void printFunc2()  override
		{
			cout<<"@void printFunc2() of Derived class overriden \n";
		}
		
		void printFunc3()  override
		{
			cout<<"@void printFunc3() of Derived class overriden \n";
		}

		~Derived()
		{
			cout<<"@ Derived class destructor \n";
		}
		
};

int main()
{
	cout<<"This is the code to understand the virtual function in cpp\n";
	{
		Derived * ptr =  new Derived();
		ptr->print();  
		ptr->printFunc();
		ptr->printFunc1();
		ptr->printFunc2();
		ptr->printFunc3();
		delete ptr;	
	}
	cout<<"---------------------------------\n";
	{
		Interface * ptr =  new Derived();
		ptr->print();  
		ptr->printFunc();
		ptr->printFunc1();
		ptr->printFunc2();
		ptr->printFunc3();
		delete ptr;
	}
}