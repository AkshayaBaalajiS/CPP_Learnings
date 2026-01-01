// this code is std::function converted from functionPointer.cpp file  
#include <iostream>
#include <cstdlib>
#include <functional>
using namespace std;

struct Structure
{
	Structure()
	{
		cout<<"@Structure constructor \n";
	}
	~Structure()
	{
		cout<<"@Structure destructor \n";
	}
	int a;
	void * ptr ;
	char b;
};

void reset(Structure * ptr )
{
	ptr->a = 0;
	ptr->ptr = nullptr;
	ptr->b = '0';
	cout<<"@void reset(Structure * ptr )\n";
}

void reset(Structure ** ptr )
{
	(*ptr)->a = 0;
	(*ptr)->ptr = nullptr;
	(*ptr)->b = '0';
	cout<<"@void reset(Structure ** ptr )\n";
}

int * function1 (int a, void * b, char c, Structure* ptr)
{
	cout<<"@int * function (int a, void * b, char c, Structure* ptr)\n";
	ptr->a = a;
	ptr->ptr = b;
	ptr->b = c;
	
}


int main()
{
	cout<<"Function pointer in cpp \n";
	// int * (*functionPointer1)(int , float, Structure*) ; // this is the prrof that the function pointer with diff type can be there unless assignment done on that 
	std::function<int * (int , float, Structure*)> someFunc1;

	int * (*functionPointer)(int , void *, char, Structure*);
	std::function<int * (int , void *, char, Structure*)> someFunc;


	void * vptr = (void *)malloc(1024);
	Structure * ptr = new Structure();
	reset(ptr);
	// functionPointer(12,vptr,'C', ptr);  // here segmentation violation occur cause there is no assignment stmt to the function pointer 
	// functionPointer = function1;
	// functionPointer(12,vptr,'C', ptr);  // here segmentation violation occur cause there is no assignment stmt to the function pointer 
	
	// someFunc(12,vptr,'C', ptr); // without assignment to the function this line throw error
	someFunc = function1 ;
	someFunc(12,vptr,'C', ptr); 


	cout<<"ptr - > a = " << ptr->a <<endl;
	cout<<"ptr - > ptr = " << ptr->ptr <<endl;
	cout<<"ptr - > b = " << ptr->b <<endl;

	reset(&ptr);

	cout<<"ptr - > a = " << ptr->a <<endl;
	cout<<"ptr - > ptr = " << ptr->ptr <<endl;
	cout<<"ptr - > b = " << ptr->b <<endl;

	
}