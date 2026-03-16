#include <iostream>
#include <memory>
using namespace std;

class A 
{	
	int* up;
	int size;
	public :
		A(int size=0) :  size(size)
		{
			cout<<"@ A class constructor\n";
			up=new int[size];
		}

		void func()
		{
			throw std::runtime_error("error on call\n");
		}

		~A()
		{
			cout<<"@ A class destructor\n";
			delete[] up;
		}
};

int main()
{
	cout<<"This is the code to understand the CPP mem leak\n";
	try
	{
		A obj;
		obj.func();
	}
	catch(exception & e)
	{
		cout<<"[EXCEPTION] = " <<e.what();
	}
}