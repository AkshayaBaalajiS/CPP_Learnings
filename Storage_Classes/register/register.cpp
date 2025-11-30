#include <iostream>
using namespace std;

class classA
{
	public :
		classA()
		{
			cout<<"@ classA class constructor\n ";
		}

		~classA()
		{
			cout<<"@ classA class destructor\n ";
		}
		
};

int main()
{
	register int someVar =23;
	register classA * ptr ;
	register classA * ptr1 = new classA();
	// the above line is valid the ptr will be onn register and the obj will be on the heap
	cout<<"Address of refister var ptr1 = " << &ptr1 <<endl;
}