#include <iostream>
using namespace std;

class A
{
	public :
		A()
		{
			cout<<"@ A class constructor \n";
		}

		~A()
		{
			cout<<"@ A class destructor \n";
		}	
};

int main()
{
	A obj;
	/*
	This object uses constructor/destructor, but:

	It acquires no resource (file, memory, lock, socket, etc.)

	It releases nothing
	*/
}