#include <iostream>
using namespace std;

class Base
{
	public :
		Base()
		{
			cout<<"Constructor of Base class \n";
		}
		virtual void print()
		{
			cout<<"@virtual void print() of Base class \n";
		}
		

		virtual void print1()
		{
			cout<<"@virtual void print1() of Base class \n";
		}

		virtual void print2()
		{
			cout<<"@virtual void print2() of Base class \n";
		}

		virtual void print3()
		{
			cout<<"@virtual void print3() of Base class \n";
		}

		virtual ~Base()
		{
			cout<<"Destructor of Base class \n";
		}
		
};

class Derived : public Base
{
	public :
		Derived()
		{
			cout<<"@ Derived class constructor \n";
		}
		

		void print() override
		{
			cout<<"@void print() override of Derived class \n";
		}
		

		void print1() override
		{
			cout<<"@void print1() override of Derived class \n";
		}

		void print2() override
		{
			cout<<"@void print2() override of Derived class \n";
		}

		void print3() override
		{
			cout<<"@void print3() override of Derived class \n";
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
		delete ptr;	
	}
	cout<<"---------------------------------\n";
	{
		Base * ptr =  new Base();
		ptr->print(); 
		delete ptr;
	}
	cout<<"---------------------------------\n";
	{
		Derived * ptr =  static_cast<Derived *>(new Base());
		ptr->print(); 
		delete ptr;
	}
	cout<<"---------------------------------\n";
	{
		Base * ptr =  new Derived(); // if derived has the override of the virtual fucntion of base only the derived function will be called 
		ptr->print(); 
		delete ptr;
	}
}