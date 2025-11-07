#include<iostream>
#include<typeinfo>
using namespace std ;


class A
{
	int private_variable=24;
	protected :
		void print_variable()
		{
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
};
class B 
{
	int private_variable=12;
	protected :
		void print_variable()
		{
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
};
template<class t1 >
class C 
{
	t1 object ;
	public :
//		The below without return type is not giving error it will give only warning 
//		call_prev_function()
//		{
//			object.print_variable();
//		}
		void call_prev_function()
		{
			object.print_variable();
		}
		
};

int main()
{
	cout<<"-------------------------------------------------------------\n";
	{
		C<A> object ;
	}
	cout<<"-------------------------------------------------------------\n";
	{
		C<B> object ;
	}
	cout<<"-------------------------------------------------------------\n";
}
