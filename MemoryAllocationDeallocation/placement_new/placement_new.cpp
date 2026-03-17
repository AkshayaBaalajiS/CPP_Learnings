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
	// ptr2->A::A(); // cant call the constructor directly 
	// so placement new helps here 

    A * ptr3 = new(ptr1) A(10);


    // the below delete cause double delete issue 
	// delete(ptr1);

    // so use the below steps 
    ptr3->~A(); // destructor called 
    ::operator delete(ptr1); // delete memory 

    // the below can be used  
    // delete(ptr3);
    // internally calls 
        // 1. destructor 
        // 2. A::operator delete() // for freeing resource 

}