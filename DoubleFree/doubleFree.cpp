#include <iostream>
using namespace std;

class Sample
{
	public:
		int * ptr ;
		int **pptr;
		Sample() : ptr(nullptr), pptr(nullptr)
		{
			cout<<"Sample class constructor\n";
		}
		Sample(int * p, int **p1) : ptr(p), pptr(p1)
		{
			cout<<"Sample class constructor\n";
		}
		~Sample()
		{
			delete [] ptr;
			delete [] pptr;
			cout<<"Sample class destructor\n";
		}
};

int main()
{
	cout<<"This is the code to understand the doubleFree / double Deletion in cpp \n";
	{
		Sample obj;
	}

	{
		Sample obj(new int[10], new int*[10]);
	}
	{
		Sample obj(new int[10], new int*[10]);
		Sample obj1(obj); // copy cons double deletiojn here 
	}
}