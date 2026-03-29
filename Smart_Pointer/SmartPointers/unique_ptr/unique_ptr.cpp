#include <iostream>
#include <memory>
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
		A(int size, int * ptr) : size(size), ptr(ptr)
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

		A(A&& ref) : size(ref.size), ptr(ref.ptr)
		{
			cout<<"A class move constructor\n";
			ref.ptr = nullptr;
			ref.size = 0;
		}
		A & operator= (A&& ref)
		{
			cout<<"A class move constructor\n";
			if(this!=&ref)
			{
				delete [] ptr; // free old resource 

				ptr = ref.ptr;
				size = ref.size;
				ref.ptr = nullptr;
				ref.size = 0;
			}
			return *this;
		}

		~A()
		{
			cout<<"A class destructor \n";
			delete [] ptr;
		}
};

void function(A * ptr )
{
	cout<<"@void function(A * ptr )\n";
}

int main()
{
	cout<<"This is the program to understand the unique_ptr in cpp\n";

	// uniqur pointer hold the ownership of the resource

	// ways of initialization 
	unique_ptr<A> up(new A());
	unique_ptr<A> up0 = make_unique<A>();

	// move the resource hold 
	unique_ptr<A> up1 = std::move(up);

	// .get 
	function(up1.get());

}