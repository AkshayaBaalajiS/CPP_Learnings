#include<iostream>
using namespace std ;

class A
{
	public :
		A()
		{
			cout<<"@ A constructor \n";
		}
		virtual void function() = 0;
		
		~A()
		{
			cout<<"@ A Destructor \n";
		}
			
};
int main()
{
	cout<<"Hello \n" ;
	A object ; // this will craete error because object creation for the abstract class 
	/*
	 cannot declare variable 'object' to be of abstract type 'A' because the following virtual functions are pure within 'A':
	*/ 
}
