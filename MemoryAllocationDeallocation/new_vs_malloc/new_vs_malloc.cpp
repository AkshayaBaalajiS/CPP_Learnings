#include <iostream>
using namespace std;

class A
{
	public:
		A()
		{
			cout<<"A class constructor \n";
		}

		~A()
		{
			cout<<"A class destructor \n";
		}
};

int main()
{
	cout<<"This the program to understand the CPP new and malloc \n";
	
	A * ptr =  new A();
	// the new allocates memory with operator new which will aloocate memory and new handles the contructor call 
	// new returns the obj of type passed as Arg 
	// if new cant allocate memory it returns bad_alloc

	// delete should be called for the new 
	delete(ptr);

	// operator new working 
	void * operNew = operator new(sizeof(A));
	// new with operator new allocated mem
	A * ptr1 = new(operNew) A();

	// call the des 
	ptr1->~A();
	operator delete(ptr1);

	A * mallocPtr = (A*)malloc(sizeof(A));
	// malloc allocates memory there is no way to call the constructor 
	// malloc return the pointer of type void * manual conversion is needed to req type 
	// mem deallocation should be ddone by free for malloc 
	// malloc return NULL is no memory 
	free(mallocPtr);


}