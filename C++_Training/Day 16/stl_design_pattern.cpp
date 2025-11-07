#include <iostream>
using namespace std ;

class parent_interface_class 
{
	public :
		parent_interface_class()	
		{
			cout<<"@ Task2 constructor \n";
		}	
		virtual void task_function() = 0 ;
		~parent_interface_class()	
		{
			cout<<"@ Task2 destructor \n";
		}
};//interface 


class Task1 : public parent_interface_class
{
	public :
		Task1()	
		{
			cout<<"@ Task1 constructor \n";
		}
		
		void task_function()
		{
			cout<<"----Task is to Draw ----\n";
		}
		
		
		~Task1()	
		{
			cout<<"@ Task1 destructor \n";
		}
};//concrete class

class Task2 :  public parent_interface_class 
{
	public :
		Task2()	
		{
			cout<<"@ Task2 constructor \n";
		}
		
		void task_function()
		{
			cout<<"----Task is to open Calculator ----\n";
		}
		
		
		~Task2()	
		{
			cout<<"@ Task2 destructor \n";
		}
}; //concrete class

int main()
{
	cout<<"Hi ..............\n";
	
	cout <<"------------------\n";
	
	/*parent_interface_class * ptr = new parent_interface_class() 
	The above statement cant be done because the parent_interface_class() with new call the constructor 
	and that cant be done 
	*/	
	
	parent_interface_class * t2_ptr  = new Task2();
	t2_ptr->task_function();
	cout <<"------------------\n";
	
	parent_interface_class * t1_ptr = new Task1();
	t1_ptr->task_function();
	cout <<"------------------\n";
	
	parent_interface_class * t3_ptr ; 
	t3_ptr = new Task2();
	t3_ptr->task_function();
	cout <<"------------------\n";
	t3_ptr = new Task1();
	t3_ptr->task_function();
	cout <<"------------------\n";
	/*
	here we are facing a prob for creating a object for specific type instead we can try 
	designing the class to create the object accordingly 
	
	*/
	
	
	
	
	
}
