#include <iostream>
using namespace std;

class A 
{
	int * ptr;
	float * fptr;
	public :
		A() : ptr(new int[10]), fptr(new float[10])
		{
			cout<<"A class constructor \n";
		}

		~A()
		{
			cout<<"A class destructor \n";
			delete [] ptr;
			delete [] fptr;
		}
};

int main()
{
	cout<<"Free to work like the operator delete \n";\
	int poolsize = 10;
	void * memoryPool = (A *)malloc(sizeof(A) * poolsize);

	A * ptr =new(memoryPool) A();

	ptr->~A();
	free(memoryPool);
}