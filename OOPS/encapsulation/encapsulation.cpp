#include <iostream>
using namespace std;

class A 
{
	int idata;	
	public :
		A()
		{
			cout<<"@ A class constructor \n";
			idata = 123;
		}
		void printFunction()
		{
			cout<<"@void printFunction() \n";
			cout<< "idata  = " << idata <<endl;
		}
		~A()
		{
			cout<<"@ A class destructor \n";
		}

};

int main()
{
	cout<<"This is the program to understand the encapsulation in cpp \n";

	A obj;
	obj.printFunction();

}