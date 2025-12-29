#include <iostream>
#include <cstdlib>
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

int * function (int a, void * b, char c, Structure* ptr)
{
	cout<<"@int * function (int a, void * b, char c, Structure* ptr)\n";
	ptr->a = a;
	ptr->ptr = b;
	ptr->b = c;
	
}


int main()
{
	cout<<"Function pointer in cpp \n";
	int * (*functionPointer1)(int , float, Structure*) ; // this is the prrof that the function pointer with diff type can be there unless assignment done on that 

	int * (*functionPointer)(int , void *, char, Structure*);

	void * vptr = (void *)malloc(1024);
	Structure * ptr = new Structure();
	reset(ptr);
	// functionPointer(12,vptr,'C', ptr);  // here segmentation violation occur cause there is no assignment stmt to the function pointer 
	functionPointer = function;
	functionPointer(12,vptr,'C', ptr);  // here segmentation violation occur cause there is no assignment stmt to the function pointer 

	cout<<"ptr - > a = " << ptr->a <<endl;
	cout<<"ptr - > ptr = " << ptr->ptr <<endl;
	cout<<"ptr - > b = " << ptr->b <<endl;

	reset(&ptr);

	cout<<"ptr - > a = " << ptr->a <<endl;
	cout<<"ptr - > ptr = " << ptr->ptr <<endl;
	cout<<"ptr - > b = " << ptr->b <<endl;

	
}