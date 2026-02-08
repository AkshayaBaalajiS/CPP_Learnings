#include <iostream>
using namespace std;

class Sample
{
	public :
		Sample()
		{
			cout<<"@Sample class constructor \n";
		}
		void print()
		{
			cout<<"@ Sample class print function \n";
		}
		~Sample()
		{
			cout<<"@Sample class destructor \n";
		}
};

int main()
{
	cout<<"Program to design the Dangling pointer \n";
	Sample * ptr = new Sample();

	Sample ** pptr = new Sample*[10];
	pptr[0] = ptr;
	pptr[0]->print();
	delete ptr; // pptr[0] becomes a dangling pointer after delete ptr;.
	pptr[0]->print(); // // ❌ UNDEFINED BEHAVIOR

	// solution is after delete 
	ptr =  nullptr;
	ptr[0] = nullptr ; 
	// we have to set it to nullptr once after deletion 
}