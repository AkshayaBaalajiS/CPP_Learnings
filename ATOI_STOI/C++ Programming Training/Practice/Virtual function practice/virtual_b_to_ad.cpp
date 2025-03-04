#include<iostream>
using namespace std ;

class A 
{
	public :
		A()
		{
			cout<<"@ A class constructor \n";
		}
		virtual void display()
		{
			cout<<"A::display \n";
		}
		~A()
		{
			cout<<"@ A class destructor \n";
		}		
};
class B : public A 
{
	public :
		B()
		{
			cout<<"@ B class constructor \n";
		}
		void display()
		{
			cout<<"B::display \n";
		}
		~B()
		{
			cout<<"@ B class destructor \n";
		}		
};
int main()
{
	
	B b_object ;
	
	//basics 
	cout<<"------------------------\n";
	A a_object = b_object ;
	a_object.display() ;
	cout<<"--------------------------\n";
	A * ptr = &b_object ;
	ptr->display();
	cout<<"--------------------------\n";
	//to access the base class function 
	ptr->A::display(); // this can be done 
	cout<<"--------------------------\n";
	A & ref = b_object ;
	ref.display();
	cout<<"--------------------------\n";
	//to access that class fucntion instead of the next class 
	ref.A::display();
	cout<<"--------------------------\n";
	
	//advanced :
	A *a_ptr = new B() ;
	a_ptr->display();  // this will call the class b fucntion due to virtual 
	cout<<"--------------------------\n";	
	A *aa_ptr = new A();   // aa_ptr is a pointer of type A where the nameless object of type A() created and mem allocated in heap space 
//	A *aa_ptr = new B();
	*aa_ptr = b_object; // the value is only changes not the address so it will see only in the class A 
	aa_ptr->display(); 
	cout<<"--------------------------\n";	
	aa_ptr = &b_object; // the value is only changes not the address so it will see only in the class A 
	aa_ptr->display(); 
	cout<<"--------------------------\n";	
	
	
	
}
