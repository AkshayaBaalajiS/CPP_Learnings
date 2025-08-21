#include<iostream>
using namespace std ;

class B ; // declaration of B class / forward declaration 

class A 
{
	
	public :
	int private_variable ;
	
		A()
		{
			cout<<"@ A Constructor : \n"; 	
		}
		A(int args=-1) : private_variable(args) 
		{
			cout<<"@ A Constructor : \n"; 	
		}
		
		void feature(B & obj ) ; //  it wont know the B so foward declaration of B done above and the definitions are done later to avoid errors 
		
		void feature_1();
		
		~A()
		{
			cout<<"@ A Destructor : \n"; 	
		}
			
};
class B
{
	
	public :
	int private_variable ;
	
		B()
		{
			cout<<"@ B Constructor : \n"; 	
		}
		B(int args=-1) : private_variable (args) 
		{
			cout<<"@ B Constructor : \n"; 	
		}
		
		void feature_3(A & obj );
		
		void feature_4();
		
		~B()
		{
			cout<<"@ B Destructor : \n"; 	
		}
};

void A::feature(B & ref )
{
	cout<< "ref.private_variable    : " <<ref.private_variable << "\n";
	
}
void A::feature_1()
{
	cout<< "void A::feature_1()    : " << "\n";
	
}
void B::feature_3(A & ref )
{
	cout<< "ref.private_variable    : " <<ref.private_variable << "\n";
	
}
void B::feature_4()
{
	cout<< "void B::feature_4()    : " <<"\n";
	
}


int main() 
{
	cout<<"Program Starts  \n";
	cout<<"-------------------------------------\n";
	A a_object(10);
	B b_object(10);
	
	cout<<"-------------------------------------\n";
	a_object.feature(b_object);
	b_object.feature_3(a_object);
	cout<<"-------------------------------------\n";
	
}

	