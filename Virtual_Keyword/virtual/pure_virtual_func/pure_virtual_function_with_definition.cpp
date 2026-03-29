#include <iostream>
using namespace std;

class A 
{
	public :
		virtual void virtualFunction() 
		{
			cout<<"virtual void virtualFunction() \n";	
		} 

		virtual void pureVirtualFunction() = 0 ; 
};
void A::pureVirtualFunction()
{
	cout<<"void A::pureVirtualFunction()\n";
}
class B:public A
{
	public :
		void pureVirtualFunction() override 
		{
			 A::pureVirtualFunction();
			cout<<"void B::pureVirtualFunction()\n";
		}
};	


int main()
{
	cout<<"This is the program to understand the pure virtual function in cpp\n";
	A * ptr  = new B();
	ptr->virtualFunction();
	ptr->pureVirtualFunction();
	
}