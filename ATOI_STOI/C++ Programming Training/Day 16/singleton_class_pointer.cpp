#include <iostream>
using namespace std ;

class Task1 
{
	static Task1 * ptr ;
//	public :
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
	
	public :
			static Task1 * getter ()
			{
				if(ptr)
				{
					
				}
				else
				{
					ptr = new Task1();
				}
				return ptr ;
			}
};//concrete class
Task1 *Task1::ptr = nullptr ;


int main()
{
	cout<<"Hi ..............\n";
//	cant be done the below stmt because ther constructor is private 
//	Task1 object ;
//	Task1 object_1 ;
	Task1 * ptr = Task1::getter();
//	Task * ptr_1 = some address 
	cout<<"The address of the pointer is " << &ptr << " the value it holds   : "  << ptr << "\n";  
	cout <<"................\n";
	Task1 & ref =  *ptr ;
	cout <<"The reference holds " << &ref <<"\n";
	cout <<"................\n";
		
	
	Task1 * ptr_1 = Task1::getter();
	cout<<"The address of the pointer is " << &ptr_1 << " the value it holds   : "  << ptr_1 << "\n";  
	cout <<"................\n";
	
}
