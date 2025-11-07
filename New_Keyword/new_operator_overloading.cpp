#include <iostream>
using namespace std;

void* operator new(size_t size)
{
	cout<<"New overloaded \n";
	void * ptr  =  malloc(size);
	return ptr;
}

class A 
{
	public :
		A()
		{
			cout<<"Default constructor \n";
		}
		int a =34;
};
int main()
{
	cout<<"New operator overloading \n";

	A * ptr  = new A();
	/*
	Internally :  A * ptr = new A();  :  it does this 
	is not just a call to operator new. It is two steps combined into one:
	
	Call memory allocation function:
	void* raw_memory = operator new(sizeof(A));
	Call the constructor using placement new:

	A* obj = new (raw_memory) A(); 
	*/

	cout<<"a =  " << ptr->a<<endl	;


}