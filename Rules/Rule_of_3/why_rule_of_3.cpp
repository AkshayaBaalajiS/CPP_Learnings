#include <iostream>
using namespace std;

class A
{
	int size;
	int * ptr ;
	public:
		A(int size) : size(size) , ptr(new int[size])
		{

		}
};

int main()
{
	A ptr(10);
	A ptr1(ptr); // here the shallow copy happens 
} 
/*
// At scope end:
// b destructor: delete[] heap block A  ✓
// a destructor: delete[] heap block A  ✗ DOUBLE FREE → undefined behavior / crash
The symptom is a heap corruption crash or silent memory corruption. This is the canonical use case for Rule of 3. You must know this cold.
*/