#include <iostream>
using namespace std;

class A
{
	public :
		int a;
		float b;
		char c;
		double d;
};

int main()
{
	cout<<"Memory pool implementation in cpp\n";

	int poolSize = 5;
	void * ptr = ::operator new (sizeof(A) * poolSize ); 

	A * aPtr1 = new(ptr) A();
	A * aPtr2 = new((char*)ptr + sizeof(A)) A();
	A * aPtr3 = new((char*)ptr + (sizeof(A)*2) ) A();

	aPtr1->~A();
	aPtr2->~A();
	aPtr3->~A();
	
	::operator delete(ptr);
	//delte on ptr should happen not on  aPtr's 	
	// ::operator delete(aPtr1);	
	// ::operator delete(aPtr2);	
	// ::operator delete(aPtr3);	
}