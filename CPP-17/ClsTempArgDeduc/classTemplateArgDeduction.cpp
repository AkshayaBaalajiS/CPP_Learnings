#include <iostream>
#include <array>
using namespace std;

template <typename T>
class A 
{
	public:
		T * cMem;
		A()
		{
			cout<<"@ A class destructor \n";
		}
		A(T * arg) : cMem(cMem)
		{
			cout<<"@ A class parameterized destructor \n";
		}
};

int main()
{
	cout<<"Class Template Argument Deduction in cpp \n";
	A<int *> *cptr = new A<int *>();  // for new we need this template type specified 
	int array[5] = {12,23,34};
	A obj(array);

	
}