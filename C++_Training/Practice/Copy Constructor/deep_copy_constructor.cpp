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
		void set_value(int args , int args1 );
		
		A(int args , int args1) ; 
		A( A & ) ;
		
		
		~A()
		{
			cout<<"@ Destructor ..\n";
		}
};
A::A(int args , int args2 ) : private_variable(args) , public_variable(args2) {} 

A:: A(A& ref ) : private_variable(6) , public_variable(private_variable) 
{
	cout<<"@ Copy Constructor \n";
	int new_private_variable =ref.private_variable;
	int new_public_variable =ref.public_variable;
	
	set_value(new_private_variable ,new_public_variable); 
}

void A::set_value(int a , int b)
{
	this->private_variable = a;
	this->public_variable = b ;
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
	cout<<"OBJECT ....\n"; 
	object.display();
	cout<<"--------------------------------------\n";
	cout<<"OBJECT_1 ....\n";
	object_1.display();
	cout<<"--------------------------------------\n";
	cout<<"CHANGING THE OBJECT DATA MEMBER VALUE ....\n";
	//done by the double parameterized constructor 
	object.set_value(20,40);
	cout<<"--------------------------------------\n";
	cout<<"OBJECT ....\n"; 
	object.display();
	cout<<"--------------------------------------\n";
	cout<<"OBJECT_1 ....\n"; 
	object_1.display();
	cout<<"--------------------------------------\n";
	cout<<"CREATING ANOTHER OBJECT AND CALLING THE COPY CONSTRUCTOR OF OBJECT ........\n";
	A object_2(object);  // copy constructor 
	cout<<"OBJECT ....\n"; 
	object_2.display();
	cout<<"--------------------------------------\n";
	
	
	
	
}