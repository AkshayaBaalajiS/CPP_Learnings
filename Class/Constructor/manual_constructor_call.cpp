#include <iostream>
using namespace std;

class A
{
	public :
		A(int a )
		{
			cout<<"@ A class constructor \n";
		}

		// void * operator new(size_t sizee )
		// {
		// 	cout<<"@ A class operator new overloading \n";
		// 	return (A *)malloc(sizee);
		// }

		// void operator delete(void  * ptr )
		// {
		// 	free(ptr);
		// }

		

		~A()
		{
			cout<<"@ A class destructor \n";
		}
};	

int main()
{
	cout<<"This is the code to understand the CPP operator new overloading \n";
	
	void * ptr1 = ::operator new(sizeof(A)); // operator new return raw pointer 
	A * ptr2 = (A *)ptr1;
	ptr2->A::A(); // cant call the constructor directly 

	delete(ptr1);


}