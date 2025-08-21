#include <iostream>
using namespace std ;


class Task1 
{
	private :
		Task1()	
		{
			cout<<"@ Task1 constructor \n";
		}
	public :
		static Task1* named_constructor()
		{
			return new Task1(); // this creates the instance of class 
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

int main()
{
	cout<<"Hi ..............\n";
	
	cout <<"------------------\n";
		
//	Task1::named_constructor()  ;
	
	Task1 * tptr = Task1::named_constructor();	 // this cant be donw without creating object 
	cout <<"------------------\n";
		
	
}
