#include <iostream>
#include <functional>
using namespace std;

void * function1 (int a, int * p)
{
	static int * ptr = new int ; // mem assigned 
	*ptr = a + *p ;
	return (void *)ptr;
}

int * function2 (int a, int * p)
{
	static int * ptr = new int; // memory assigned 
	*ptr = a + *p ;
	return ptr;
}

int main()
{
	cout<<"This is the program to understand the function pointer vs std_function in cpp\n";

	void * (*functionPtr1) (int, int*);
	int * (*functionPtr) (int, int*);

	functionPtr = function2;
	functionPtr1 = function1;

	int number =12;
	// int *result = (12, &number);// for this comma operator is done so 12 is evaluated and move to next towards right 
	int *result = functionPtr(12, &number);
	cout<<"*result " << *result <<endl; 

	void * vresult = functionPtr1(56, &number);
	int * ptrr = static_cast<int *>(vresult);
	cout<<"*ptrr " << *ptrr<<endl;

	std::function<int *(int, int *)> function_Function = function2;
	int * result1 = function_Function(67,&number);
	cout<<"*result1 = " << *result1 << endl;	
}	