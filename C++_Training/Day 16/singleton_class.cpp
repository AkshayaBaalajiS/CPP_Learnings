#include <iostream>
using namespace std ;

class Task1 
{
	static Task1 obj ;
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
		static Task1 & getter ()
		{
			return obj;
		}
};//concrete class
Task1 Task1::obj;
//class Task2 
//{
//	public :
//		Task2()	
//		{
//			cout<<"@ Task2 constructor \n";
//		}
//		
//		void task_function()
//		{
//			cout<<"----Task is to open Calculator ----\n";
//		}
//		
//		
//		~Task2()	
//		{
//			cout<<"@ Task2 destructor \n";
//		}
//}; //concrete class

int main()
{
	cout<<"Hi ..............\n";
//	cant be done the below stmt because ther constructor is private 
//	Task1 object ;
//	Task1 object_1 ;
	Task1 & ptr = Task1::getter();
//	Task * ptr_1 = & 
	cout<<"The address of the object is " << &ptr << "\n";  
	cout <<"................\n";
	Task1 & ptr_1 = Task1::getter();
//	Task * ptr_1 = & 
	cout<<"The address of the object is " << &ptr_1 << "\n";  
	cout <<"................\n";
	
}
