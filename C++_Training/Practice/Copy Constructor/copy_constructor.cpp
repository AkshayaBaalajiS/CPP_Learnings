#include<iostream>
using namespace std ;

class A
{
	int private_variable ;
	public :
		int public_variable ;
		A() : private_variable(5) , public_variable(private_variable)
		{
			cout<<"@ Default Constructor ..\n";
		}
		
		A(int a )
		{
			cout<<"@ Single Parameterized Constructor ..\n";
		}
		
		void display ();
		int get_value();
		
		A( A & ) ;
		
		
		~A()
		{
			cout<<"@ Destructor ..\n";
		}
};
A:: A(A& ref ) : private_variable(6) , public_variable(private_variable) 
{
	cout<<"@ Copy Constructor \n";
	ref.private_variable = this->private_variable ;
	ref.public_variable = this->public_variable ;
}

int A::get_value()
{
	return this->private_variable;
}
void A::display()
{
	cout<<"The private variable value : " << get_value()<<"\n";
	cout<<"The public variable value : "  << public_variable <<"\n";  
}
int main()
{
	cout<<"Hello \n";
	A object ;  // default constructor 
	A object_1(object);  // copy constructor 
	
	cout<<"--------------------------------------\n";
	object.display();
	cout<<"--------------------------------------\n";
	object_1.display();
	
}