#include <iostream>
#include <memory>
using namespace std;


class Sample
{
	public:
		Sample()
		{
			cout<<"@ Sample class cons\n";
		}
		~Sample()
		{
			cout<<"@ Sample class desc\n";
		}	
};

class A
{	

	unique_ptr<Sample> uniqPtr;
	public :
		A()
		{
			cout<<"@ A class cons\n";
		}	
};

int main()
{
	cout<<"@ Rule of 0 program\n";
	A obj;
	// A obj1 = obj; // use of deleted funcion
	A obj2;
	// obj2 = obj; //use of deleted function 

	A * ptr = new A();
	delete ptr;
}
