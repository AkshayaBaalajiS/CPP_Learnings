#include <iostream>
using namespace std;

class A
{
	int * ptr ;
	public:
		A()
		{
			cout<<"@ A class constructor\n";
			ptr = new int [5]; // resource allocated 
		}

		~A()
		{
			cout<<"@ A class destructor \n";
			delete[] ptr; // resource deleted 
		}
};

int main()
{
	A obj;
}