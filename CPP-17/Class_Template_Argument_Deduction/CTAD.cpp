#include <iostream>
using namespace std;

template <typename T>
class Sample
{
	public :
		T * ptr  ; 
		T value ;

		Sample(T arg) : value(arg)
		{
			cout<<"@ Sample class constructor \n";
		}

		Sample(T* arg) : ptr(arg)
		{
			cout<<"@ Sample class constructor \n";
		}

		~Sample()
		{
			cout<<"@ Sample class destructor \n";
		}
};

int main()
{
	cout<<"This is the program to understand the CTAD in C++ 17 \n";
	
	// template type deduced from the constructor argument 
	// Sample * classPtr = new Sample(12);
	// auto * classPtr = new Sample(12); // use auto to solve the issue when new is used in CTAD 
	Sample<int> * classPtr = new Sample<int>(12);
	/*
Class template argument deduction is performed only when a variable is being declared with a class template as its type.
	*/
	classPtr->ptr = new int[5];
	cout<<"Non pointer variable value = " << classPtr->value <<endl;
	cout<<"Pointer variable value = " << classPtr->ptr <<endl;

	Sample classObj{12.243f};
	cout<<"Non pointer variable value = " << classObj.value <<endl;
	cout<<"Pointer variable value = " << classObj.ptr <<endl;
	
	int array[6]={1,2,3,4,5,6};
	Sample classObj_1{array};
	cout<<"Non pointer variable value = " << classObj_1.value <<endl;
	cout<<"Pointer variable value = " << classObj_1.ptr <<endl;
	
}