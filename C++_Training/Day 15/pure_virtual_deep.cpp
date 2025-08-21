#include<iostream>
using namespace std ;

class A 
{
	public :
		A()
		{
			cout<<"@ A Constructor \n";
		}
			
		void allocate_memory()
		{
			cout<<"Class A Memory Allocated ....\n";
		}
		void function()
		{
			cout <<"This is a virtual function \n";
		}
		
		void deallocate_memory()
		{
			cout<<"Class A Memory Deallocated ....\n";
		}
		
		~A()
		{
			cout<<"@ A Destructor  \n";
		}
	
}; // this is a concreate class 
class B : public A  // try the derived as abstract class 
{
	public :
		B()
		{
			cout<<"@ B constructor \n";
		}
		virtual void function() = 0;
		
		~B()
		{
			cout<<"@ B Destructor \n";
		}
};

template <typename Type1 >
void render_function(Type1 & ref )
{
	cout<<"-------------------------\n";
	ref.allocate_memory();
	cout<<"-------------------------\n";
	ref.deallocate_memory();
	cout<<"-------------------------\n"; 
}

int main()
{
	cout<<"Hello \n" ;	
	cout <<"++++++++++++++++++++++++\n";
//	b b_object ; // this object cant be created because the B class is an abstract class 
	
	A a_object ; 
//	render_function(a_object);  
	cout <<"++++++++++++++++++++++++\n";
//	B b_object ; // this object cant be created because the B class is an abstract class but it is derived from the base class 
//	b_object.function();
		
}
