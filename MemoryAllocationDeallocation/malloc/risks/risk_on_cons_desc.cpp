#include <iostream>
#include <thread>
using namespace std;

class Sample
{
	public:
	int number;
	int * ptr ;
	float * fptr ;
		Sample(int number= 12) : number(number), ptr(new int[10]), fptr(new float[10])
		{
			cout<<"@ Sample class constructor \n";
		}

		~Sample()
		{
			cout<<"@ Sample class destructor \n";
			delete [] ptr;
			delete [] fptr;
		}
};

int main()
{
	cout<<"This is the code to understand the risk of using the malloc and free in cpp \n";

	Sample * ptr = (Sample*)malloc(sizeof(Sample));
	cout<<"Size of class = " << sizeof(Sample)<<endl;
	cout<<"--Malloc result--------------------------------\n";
	cout<<"ptr->number = " << ptr->number <<endl;
	cout<<"------------------------------------\n";

	Sample * ptr1 = new Sample();
	cout<<"--New result--------------------------------\n";
	cout<<"ptr1->number = " << ptr1->number <<endl; // 12 is the output cause the cons called 
	cout<<"------------------------------------\n";

	delete(ptr1); // sample CLass destructor called 
	free(ptr);
}

/*
malloc does not call the constructor so the members wont be initialized 

free does not call the destructor so the mem is not freed 
*/ 