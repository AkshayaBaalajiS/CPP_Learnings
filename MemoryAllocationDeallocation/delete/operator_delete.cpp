#include <iostream>
using namespace std;

class A
{
	public :
		A(int a )
		{
			cout<<"@ A class constructor \n";
		}

		void * operator new(size_t sizee )
		{
			cout<<"@ A class operator new overloading \n";
			return (A *)malloc(sizee);
		}

		void operator delete(void  * ptr )
		{
			free(ptr);
		}

		

		~A()
		{
			cout<<"@ A class destructor \n";
		}
};	

int main()
{
	cout<<"This is the code to understand the CPP operator new overloading \n";
	// A obj(12);

	// A * ptr = new A; // overload operator new 

	A * ptr1 = new A(12);

	delete(ptr1);


}