#include <iostream>
using namespace std;

void * function1 (int a, int * p)
{
	static int * ptr = new int ; // mem assigned 
	*ptr = a + *p ;
	return (void *)ptr;
}

void ** function3 (int a, int * p)
{
	static int * ptr = new int ; // mem assigned 
	*ptr = a + *p ;
	return (void **)ptr;
}

int * function2 (int a, int * p)
{
	static int * ptr = new int; // memory assigned 
	*ptr = a + *p ;
	return ptr;
}

void simpleFunction()
{
	cout<<"@void simpleFunction()\n";
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

	void ** (*functionPtr2) (int, int*) ;
	functionPtr2 = function3;
	void ** vresult1 = functionPtr2(34, &number);
	void * vresult2 = static_cast<void *>(vresult1);
	int * ptrr1 = static_cast<int *>(vresult2);
	cout<<"*ptrr1 " << *ptrr1<<endl;
	

	// for simple 
	void (*simFunc) () = simpleFunction;
	simFunc();

}	