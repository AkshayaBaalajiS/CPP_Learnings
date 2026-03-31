#include <iostream>
using namespace std;

class A
{
	public :
	int size;
	int * ptr;
		A() : size(10), ptr(new int[size])
		{
			cout<<"A class constructor \n";
		}

		A(const A & ref) : size(ref.size), ptr(new int[size])
		{
			cout<<"@ A class copy constructor \n";
			for(int i=0;i<10;i++)
			{
				ptr[i] = ref.ptr[i];
			}
		}

		A & operator = (const A& ref)
		{
			// delte is mandatory 
			delete [] ptr;
			size = ref.size;
			ptr = new int[size];
			cout<<"A class copy assignment operator \n";
			if(this!=&ref)
			{
				for(int i=0;i<10;i++)
				{
					ptr[i] = ref.ptr[i];
				}
			}
			return *this;
		}

		~A()
		{
			cout<<"A class destructor \n";
			delete [] ptr;
		}
};

int main()
{
	cout<<"Code to demonstrate RUle of 3 in cpp\n";
	// if we are dealing with resource we need to have a class with the Rule of 5 or Rule of 3 where the Rule of 3 is old but this code is a ex of Rule of 3 
	 // Rule of 3 should have a copy cons , copy assignment oeprator and a destuctor 

	A obj;
	obj.ptr[0] = 123;
	cout<<"A obj prt [0]  = " << obj.ptr[0] <<endl;
	A * ptr = new A(obj); // copy cons 
	*ptr = obj; // copy assignment operator 
	cout<<"A obj prt [0]  = " << obj.ptr[0] <<endl;
	obj.ptr[0] = 234;

	cout<<"--------------------------------\n";
	cout<<"A obj prt [0]  = " << obj.ptr[0] <<endl;
	cout<<"ptr ptr [0]  = " << ptr->ptr[0] <<endl;
	cout<<"--------------------------------\n";
	
	delete ptr;
}