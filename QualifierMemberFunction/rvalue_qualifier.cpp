#include <iostream>
using namespace std;

class A
{
	public :
		A()
		{
			cout<<"@ A class constructor \n";
		}

		virtual void type() & 
		{
			cout<<"virtual void type()\n";
		}	

		virtual void type1() &&
		{
			cout<<"virtual void type1()\n";
		}	

		~A()
		{
			cout<<"@ A class destructor \n";
		}
};


int main()
{
	cout<<"R Value specifier \n";
	A obj;
	obj.type();
	// obj.type1(); // this cant be done cause this will not be a arg in the rvalue specifier function 
}