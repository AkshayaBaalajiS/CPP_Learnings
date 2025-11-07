#include<iostream>
#include<typeinfo>
using namespace std ;


class A
{
	int private_variable=24;
	protected :
		void print_variable()
		{
			cout<<"@ A Class Member Function  : ..\n";
			cout<< "this->private_variable : " << this->private_variable << "\n";	
		}	
	public :
		A()
		{
			cout<<"@ A Constructor .. \n";
		}
		~A()
		{
			cout << "@ A Destructor ..\n";
		}
		void call_protected_function()
		{
			print_variable();
		}
};
class B 
{
	int private_variable=12;
	protected :
		void print_variable()
		{
			cout<<"@ A Class Member Function  : ..\n";
			cout<< "this->private_variable : " << this->private_variable << "\n";	
		}	
	public :
		B()
		{
			cout<<"@ B Constructor .. \n";
		}
		~B()
		{
			cout << "@ B Destructor ..\n";
		}
		void call_protected_function()
		{
			print_variable();
		}
};
template <class t1>
void template_function(t1 & ref)
{
	ref.call_protected_function();
}

int main()
{
	cout<<"-------------------------------------------------------------\n";
	{
		B object ;
		template_function(object);
	}
	cout<<"-------------------------------------------------------------\n";
	{
		A object ;
		template_function(object);
	}
	cout<<"-------------------------------------------------------------\n";
}
